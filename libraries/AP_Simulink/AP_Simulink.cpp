#include "AP_Simulink/AP_Simulink.h"
#include <GCS_MAVLink/GCS.h>
#include <AP_AHRS/AP_AHRS.h>
#include <AP_Airspeed/AP_Airspeed.h>
#include <SRV_Channel/SRV_Channel.h>
#include <RC_Channel/RC_Channel.h>
#include <AP_Logger/AP_Logger.h>
#include <AP_DAL/AP_DAL.h>
#include <../ArduPlane/mode.h>

#define SIMULINK_MODEL passthrough

#include QUOTE(SIMULINK_MODEL/SIMULINK_MODEL.cpp)

// Convert range [-pi/2, pi/2] to [-4500, 4500]
#define RAD2SERVO(input) constrain_float(degrees(input) * 50, -4500, 4500)
#define SERVO2RAD(input) constrain_float(radians(input / 50), -M_PI/2, M_PI/2)

extern const AP_HAL::HAL &hal;
AP_AHRS *ahrs = AP_AHRS::get_singleton();
AP_Airspeed *airspeed = AP_Airspeed::get_singleton();
AP_GPS *gps = AP_GPS::get_singleton();
RC_Channels *rc_ch = RC_Channels::get_singleton();
RC_Channel *ch;
SIMULINK_MODEL control;
SIMULINK_MODEL::ExtU_T input = {};
SIMULINK_MODEL::ExtY_T output = {};
SIMULINK_MODEL::DW_T state = {};

void AP_Simulink::init() {
    ch = rc_ch->find_channel_for_option(RC_Channel::AUX_FUNC::SCRIPTING_1);
    if (ch == nullptr) {
        GCS_SEND_TEXT(MAV_SEVERITY_INFO, "AP_Simulink: No Scripting1 channel found.");
        return;
    }
    GCS_SEND_TEXT(MAV_SEVERITY_INFO, "AP_Simulink: Initialized '" QUOTE(SIMULINK_MODEL) "' model.");
}

void AP_Simulink::loop() {
    step();
    logging();
}

bool was_running = false;
void AP_Simulink::step() {
    if (!was_running) {
        // Reset simulation state while not running
        // Clears integrators
        state = {};
        control.setDWork(&state);
        control.initialize();
    }

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
    // rc
    input.aileron_rc = SERVO2RAD(aileron_rc);
    input.elevator_rc = SERVO2RAD(elevator_rc);
    input.rudder_rc = SERVO2RAD(rudder_rc);
    input.throttle_rc = throttle_rc;
    input.enable_rc = ((ch != nullptr) && (ch->get_aux_switch_pos() == RC_Channel::AuxSwitchPos::HIGH));
    // high level controllers
    input.roll_L1 = roll_L1;
    input.pitch_TECS = pitch_TECS;
    input.airspeed_TECS = airspeed_TECS;

    control.setExternalInputs(&input);

    // ** Run the model **
    control.step();

    // ** Process outputs **
    output = control.getExternalOutputs();

    if (output.enable_p) {
        SRV_Channels::set_output_scaled(SRV_Channel::k_aileron, RAD2SERVO(output.aileron));
        SRV_Channels::set_output_scaled(SRV_Channel::k_elevator, RAD2SERVO(output.elevator));
        SRV_Channels::set_output_scaled(SRV_Channel::k_rudder, RAD2SERVO(output.rudder));
        SRV_Channels::set_output_scaled(SRV_Channel::k_throttle, output.throttle);
    }

    // ** Report **

    if (output.enable_p != was_running) {
        if (was_running) {
            // Switched from custom controller to ardupilot's
            GCS_SEND_TEXT(MAV_SEVERITY_INFO, "AP_Simulink: Disabled custom controller.");
            reset_pid();
            control.terminate();
        } else {
            GCS_SEND_TEXT(MAV_SEVERITY_INFO, "AP_Simulink: Enabled custom controller.");
        }
    }
    was_running = output.enable_p;
}


// ** Logging **
void AP_Simulink::logging() {
#if CONFIG_HAL_BOARD == HAL_BOARD_SITL
    if (!output.enable_p) { return; }
    uint64_t time_us = AP::dal().micros64();

    struct log_Simulink_1 pkt1 {
        LOG_PACKET_HEADER_INIT(LOG_SIMULINK_1),
            time_us: time_us,
            control_mode : input.control_mode,
            command_nav : input.command_nav,
            roll : input.roll,
            pitch : input.pitch,
            yaw : input.yaw,
            altitude : input.altitude,
            airspeed : input.airspeed,
    };
    AP::logger().WriteBlock(&pkt1, sizeof(pkt1));

    struct log_Simulink_2 pkt2 {
        LOG_PACKET_HEADER_INIT(LOG_SIMULINK_2),
            time_us: time_us,
            yaw_nav : input.yaw_nav,
            yaw_error : input.yaw_error,
            altitude_nav : input.altitude_nav,
    };
    AP::logger().WriteBlock(&pkt2, sizeof(pkt2));

    struct log_Simulink_3 pkt3 {
        LOG_PACKET_HEADER_INIT(LOG_SIMULINK_3),
            time_us: time_us,
            aileron_rc : input.aileron_rc,
            elevator_rc : input.elevator_rc,
            rudder_rc : input.rudder_rc,
            throttle_rc : input.throttle_rc,
            enable_rc : input.enable_rc,
    };
    AP::logger().WriteBlock(&pkt3, sizeof(pkt3));

    struct log_Simulink_4 pkt4 {
        LOG_PACKET_HEADER_INIT(LOG_SIMULINK_4),
            time_us: time_us,
            roll_L1 : input.roll_L1,
            pitch_TECS : input.pitch_TECS,
            airspeed_TECS : input.airspeed_TECS,
    };
    AP::logger().WriteBlock(&pkt4, sizeof(pkt4));

    struct log_Simulink_5 pkt5 {
        LOG_PACKET_HEADER_INIT(LOG_SIMULINK_5),
            time_us: time_us,
            enable_p : output.enable_p,
            aileron : output.aileron,
            elevator : output.elevator,
            rudder : output.rudder,
            throttle : output.throttle,
    };
    AP::logger().WriteBlock(&pkt5, sizeof(pkt5));

    struct log_Simulink_6 pkt6 {
        LOG_PACKET_HEADER_INIT(LOG_SIMULINK_6),
            time_us: time_us,
            airspeed_obj : output.airspeed_obj,
            pitch_obj : output.pitch_obj,
            roll_obj : output.roll_obj
    };
    AP::logger().WriteBlock(&pkt6, sizeof(pkt6));
#endif
}
