#pragma once
#include <AP_HAL/AP_HAL.h>
#include <AP_Math/AP_Math.h>

class AP_Simulink {

public:
    AP_Simulink();
    void init();
    // Check for rc trigger
    void check_rc();
    // Check if we are in auto mode and on a waypoint
    void check_nav();
    // Called everytime the main navigation (update mode) and PID (stabilize) controllers are done
    // but before the servo outputs are pushed to the HAL
    // Runs on all modes except manual
    void run(void *veh);
};