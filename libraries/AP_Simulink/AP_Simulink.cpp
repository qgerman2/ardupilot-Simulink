#include <stdio.h>
#include "AP_Simulink/AP_Simulink.h"
#include "controller.h"
#include <GCS_MAVLink/GCS.h>
#include <AP_AHRS/AP_AHRS.h>
#include <SRV_Channel/SRV_Channel.h>
#include <RC_Channel/RC_Channel.h>

extern const AP_HAL::HAL &hal;
AP_AHRS *ahrs = AP_AHRS::get_singleton();

RC_Channel *ch;

controller control;
controller::ExtU_controller_T input = {};
controller::ExtY_controller_T output = {};

AP_Simulink::AP_Simulink() {}

bool enabled_rc = false;
bool running = false;

void AP_Simulink::init() {
    control.initialize();
    ch = RC_Channels::get_singleton()->find_channel_for_option(RC_Channel::AUX_FUNC::SCRIPTING_1);
    if (ch == nullptr) {
        GCS_SEND_TEXT(MAV_SEVERITY_INFO, "AP_Simulink: No Scripting1 channel found.");
        return;
    }
    GCS_SEND_TEXT(MAV_SEVERITY_INFO, "AP_Simulink: Library initialized.");
}

bool AP_Simulink::check_rc() {
    bool rc_ok = true;
    if ((ch == nullptr) || (ch->get_aux_switch_pos() != RC_Channel::AuxSwitchPos::HIGH)) {
        rc_ok = false;
    }
    if (enabled_rc != rc_ok) {
        if (rc_ok) {
            GCS_SEND_TEXT(MAV_SEVERITY_INFO, "AP_Simulink: Enabled RC Switch.");
        } else {
            GCS_SEND_TEXT(MAV_SEVERITY_INFO, "AP_Simulink: Disabled RC Switch.");
            running = false;
        }
    }
    enabled_rc = rc_ok;
    return rc_ok;
}

bool AP_Simulink::check_nav(nav_inputs nav) {
    bool nav_ok = true;
    // Only run on auto mode
    if (nav.mode != 10) { nav_ok = false; }
    // during regular waypoints
    if (nav.cmd != MAV_CMD_NAV_WAYPOINT) { nav_ok = false; }
    if (running != nav_ok) {
        if (running) {
            GCS_SEND_TEXT(MAV_SEVERITY_INFO, "AP_Simulink: Enabled custom controller");
        } else {
            GCS_SEND_TEXT(MAV_SEVERITY_INFO, "AP_Simulink: Disabled custom controller");
        }
    }
    running = nav_ok;
    return true;
}

void AP_Simulink::run(nav_inputs nav) {
    if (!check_rc()) { return; }
    if (!check_nav(nav)) { return; }

    // Notify user
    input.Roll_sensor = ahrs->roll;
    input.Pitch_sensor = ahrs->pitch;

    input.Roll_objetivo = nav.roll;
    input.Pitch_objetivo = nav.pitch;
    input.Throttle_objetivo = nav.throttle; // -100 a 100

    control.setExternalInputs(&input);

    control.step();

    output = control.getExternalOutputs();
    output.Aleron = constrain_float(degrees(output.Aleron) * 50, -4500, 4500);
    output.Elevador = constrain_float(degrees(output.Elevador) * 50, -4500, 4500);

    SRV_Channels::set_output_scaled(SRV_Channel::k_aileron, output.Aleron);
    SRV_Channels::set_output_scaled(SRV_Channel::k_elevator, output.Elevador);
    SRV_Channels::set_output_scaled(SRV_Channel::k_throttle, output.Acelerador);
}