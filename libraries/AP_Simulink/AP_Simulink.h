#pragma once
#include <AP_HAL/AP_HAL.h>

class AP_Simulink {

public:
    // Values produced by the navigation controller
    // These can't be directly accessed by the librarry
    // because including Plane.h fails compilation
    struct controller {
        // Plane::nav_roll_cd
        int32_t roll;
        // Plane::nav_pitch_cd
        int32_t pitch;
        // Plane::commanded_throttle
        float throttle;
    };
    AP_Simulink();
    void init();
    // Called everytime the main navigation (update mode) and PID (stabilize) controllers are done
    // but before the servo outputs are pushed to the HAL
    void run(controller ctrl);
};