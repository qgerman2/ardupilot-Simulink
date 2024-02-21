#include "AP_Simulink.h"
#include "Plane.h"

void AP_Simulink_Plane::pre_run() {
    // Navigation variables
    control_mode = plane.control_mode->mode_number();
    nav_command = plane.mission.get_current_nav_cmd().id;
    hgt_dem = plane.TECS_controller._hgt_dem;
    bearing_error = plane.L1_controller._bearing_error;
    nav_bearing = plane.L1_controller._nav_bearing;

    // High level controller variables
    nav_roll_cd = plane.nav_roll_cd;
    nav_pitch_cd = plane.nav_pitch_cd;
    throttle = plane.TECS_controller.get_throttle_demand();
    run();
}

void AP_Simulink_Plane::reset_pid() {
    plane.last_stabilize_ms = 0;
}