#include <stdio.h>
#include <ctime>
#include "AP_Simulink/AP_Simulink.h"
#include "controller.h"
#include <GCS_MAVLink/GCS.h>
#include <AP_AHRS/AP_AHRS.h>
#include <AP_Airspeed/AP_Airspeed.h>
#include <SRV_Channel/SRV_Channel.h>
#include <RC_Channel/RC_Channel.h>
#include <AP_Filesystem/AP_Filesystem.h>
#include <AP_GPS/AP_GPS.h>
#include <../ArduPlane/mode.h>

// Convert range [-pi/2, pi/2] to [-4500, 4500]
#define RAD2SERVO(input) constrain_float(degrees(input) * 50, -4500, 4500)

extern const AP_HAL::HAL &hal;
AP_AHRS *ahrs = AP_AHRS::get_singleton();
AP_Airspeed *airspeed = AP_Airspeed::get_singleton();
AP_GPS *gps = AP_GPS::get_singleton();

RC_Channel *ch;

controller control;
controller::ExtU_controller_T input = {};
controller::ExtY_controller_T output = {};

AP_Simulink::AP_Simulink() {}

void AP_Simulink::init() {
    ch = RC_Channels::get_singleton()->find_channel_for_option(RC_Channel::AUX_FUNC::SCRIPTING_1);
    if (ch == nullptr) {
        GCS_SEND_TEXT(MAV_SEVERITY_INFO, "AP_Simulink: No Scripting1 channel found.");
        return;
    }
    GCS_SEND_TEXT(MAV_SEVERITY_INFO, "AP_Simulink: Library initialized.");
}

void AP_Simulink::loop() {
    if (pre_run()) {
        run();
    }
    logging();
}

bool enabled_rc = false;
bool enabled_nav = false;
bool running = false;
bool AP_Simulink::pre_run() {
    // Check if the Scripting1 RC switch is on
    bool rc_ok = true;
    if ((ch == nullptr) || (ch->get_aux_switch_pos() != RC_Channel::AuxSwitchPos::HIGH)) {
        rc_ok = false;
    }
    (enabled_rc != rc_ok && rc_ok)
        ? GCS_SEND_TEXT(MAV_SEVERITY_INFO, "AP_Simulink: Enabled RC Switch.")
        : GCS_SEND_TEXT(MAV_SEVERITY_INFO, "AP_Simulink: Disabled RC Switch.");
    enabled_rc = rc_ok;

    // Check if navigation conditions are met
    bool nav_ok = true;
    // Only run on auto or stabilize modes
    if (control_mode != Mode::Number::AUTO || control_mode != Mode::Number::STABILIZE) { nav_ok = false; }
    // during regular waypoints
    if (command_nav != MAV_CMD_NAV_WAYPOINT) { nav_ok = false; }
    ((enabled_nav != nav_ok) && nav_ok)
        ? GCS_SEND_TEXT(MAV_SEVERITY_INFO, "AP_Simulink: Entered navigation conditions.")
        : GCS_SEND_TEXT(MAV_SEVERITY_INFO, "AP_Simulink: Exited navigation conditions.");
    enabled_nav = nav_ok;

    // Run if both checks are true
    bool ok = rc_ok && nav_ok;
    if (ok != running) {
        if (ok) {
            GCS_SEND_TEXT(MAV_SEVERITY_INFO, "AP_Simulink: Enabled custom controller.");
            initialize();
        } else {
            GCS_SEND_TEXT(MAV_SEVERITY_INFO, "AP_Simulink: Disabled custom controller.");
            terminate();
            reset_pid();
        }
    }
    running = ok;
    return ok;
}

// ** Custom controller methods **

void AP_Simulink::initialize() {
    control.initialize();
}

void AP_Simulink::run() {
    // ** Set up inputs **
    // mode
    input.control_mode = control_mode;
    input.command_nav = command_nav;
    // sensors
    input.roll = ahrs->roll;
    input.pitch = ahrs->pitch;
    input.yaw = ahrs->yaw;
    input.altitude = altitude;
    input.airspeed = 0.1f;
    ahrs->airspeed_estimate(input.airspeed);
    // navigation
    input.yaw_nav = yaw_nav;
    input.yaw_error = yaw_error;
    input.altitude_nav = altitude_nav;
    // high level controllers
    input.roll_L1 = roll_L1;
    input.pitch_TECS = pitch_TECS;
    input.throttle_TECS = throttle_TECS;

    control.setExternalInputs(&input);

    // ** Run the model **
    control.step();

    // ** Process outputs **
    output = control.getExternalOutputs();
    SRV_Channels::set_output_scaled(SRV_Channel::k_aileron, RAD2SERVO(output.aileron));
    SRV_Channels::set_output_scaled(SRV_Channel::k_elevator, RAD2SERVO(output.elevator));
    SRV_Channels::set_output_scaled(SRV_Channel::k_rudder, RAD2SERVO(output.rudder));
    SRV_Channels::set_output_scaled(SRV_Channel::k_throttle, RAD2SERVO(output.aileron));
}

void AP_Simulink::terminate() {
    control.terminate();
}

bool recording = false;
int file = -1;
char write_buf[1500];
void AP_Simulink::logging() {
    // Check if we should log and open/close file on condition changes
    bool log_ok = true;
    if (control_mode != Mode::Number::AUTO && control_mode != Mode::Number::STABILIZE) { log_ok = false; }
    if (recording != log_ok) {
        if (log_ok) {
            // Create log file on logging toggled on
            uint32_t utc_s = gps->time_epoch_usec() * 1E-6;
            time_t now = static_cast<time_t>(utc_s);
            strftime(write_buf, sizeof(write_buf), "%d %m %y - %H %M %S.txt", gmtime(&now));
            file = AP::FS().open(write_buf, O_WRONLY | O_CREAT | O_TRUNC);
            if (file != 1) {
                printf("\nCreated log file %s", write_buf);
            } else {
                printf("\nFailed to create log file");
            }
        } else {
            // Close log file on logging toggled off
            if (file != -1) {
                AP::FS().close(file);
                printf("\nClosed log file");
            }
        }
    }
    recording = log_ok;
    if (!recording) { return; }
    if (file == -1) { return; }

    snprintf(write_buf, sizeof(write_buf), "\nHOLLAAAA");
    ssize_t len = strnlen(write_buf, sizeof(write_buf));
    AP::FS().write(file, write_buf, len);
}