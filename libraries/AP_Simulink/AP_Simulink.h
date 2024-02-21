#pragma once
#include <AP_HAL/AP_HAL.h>
#include <AP_Math/AP_Math.h>

class AP_Simulink {
public:
    // Check ArduPlane/AP_Simulink.cpp for details on these variables
    // Navigation
    uint8_t control_mode;
    uint16_t nav_command;
    float hgt_dem;
    float bearing_error;
    float nav_bearing;

    // High level controller
    int32_t nav_roll_cd;
    int32_t nav_pitch_cd;
    float throttle;

    bool enabled_rc = false;
    bool enabled_nav = false;
    bool running = false;

    AP_Simulink();
    void init();
    // Check for rc trigger
    void check_rc();
    // Check if we are in auto mode and on a waypoint
    void check_nav();
    // Called everytime the main navigation (update mode) and PID (stabilize) controllers are done
    // but before the servo outputs are pushed to the HAL
    // Runs on all modes except manual
    void run();
    virtual void reset_pid() {};
};