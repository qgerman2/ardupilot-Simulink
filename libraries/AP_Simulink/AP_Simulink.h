#pragma once
#include <AP_HAL/AP_HAL.h>
#include <AP_Math/AP_Math.h>

class AP_Simulink {

public:
    // Values produced by the navigation controller
    // These can't be directly accessed by the librarry
    // because including Plane.h fails compilation
    struct nav_inputs {
        uint8_t mode;
        uint16_t cmd;
        // Plane::nav_roll_cd
        ftype roll;
        // Plane::nav_pitch_cd
        ftype pitch;
        // Plane::commanded_throttle
        ftype throttle;
    };
    AP_Simulink();
    void init();
    // Check for rc trigger
    bool check_rc();
    // Check if we are in auto mode and on a waypoint
    bool check_nav(nav_inputs nav);
    // Called everytime the main navigation (update mode) and PID (stabilize) controllers are done
    // but before the servo outputs are pushed to the HAL
    // Runs on all modes except manual
    void run(nav_inputs nav);
};