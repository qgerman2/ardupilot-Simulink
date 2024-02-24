#include "AP_Simulink.h"
#include "Plane.h"

// These files in the ArduPlane folder are needed because
// 'Plane.h' can't be accessed on an external library
// So they are passed to the external library through 'pre_run'

void AP_Simulink_Plane::pre_loop() {
    // RC
    aileron_rc = plane.channel_roll->get_control_in();
    elevator_rc = plane.channel_pitch->get_control_in();
    rudder_rc = plane.channel_rudder->get_control_in();
    throttle_rc = plane.channel_throttle->get_control_in();

    // Sensor
    altitude = plane.tecs_hgt_afe();

    // Navigation variables
    control_mode = plane.control_mode->mode_number();
    command_nav = plane.mission.get_current_nav_cmd().id;
    altitude_nav = plane.TECS_controller._hgt_dem;
    yaw_error = plane.L1_controller._bearing_error;
    yaw_nav = plane.L1_controller._nav_bearing;

    // High level controller variables
    roll_L1 = radians(plane.nav_roll_cd * 0.01f);
    pitch_TECS = radians(plane.nav_pitch_cd * 0.01f);
    airspeed_TECS = plane.TECS_controller._TAS_dem;
    loop();
}

void AP_Simulink_Plane::reset_pid() {
    plane.last_stabilize_ms = 0;
}