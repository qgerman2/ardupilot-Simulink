#pragma once
#include <AP_HAL/AP_HAL.h>
#include <AP_Math/AP_Math.h>

class AP_Simulink {
public:
    // Check ArduPlane/AP_Simulink.cpp for details on these variables
    // Sensors
    float altitude;

    // Navigation
    uint8_t control_mode;
    uint16_t command_nav;
    float altitude_nav;
    float yaw_error;
    float yaw_nav;

    // High level controller
    float roll_L1;
    float pitch_TECS;
    float throttle_TECS;

    AP_Simulink();
    void init();

    // Called everytime the main navigation (update mode) and PID (stabilize) controllers are done
    // but before the servo outputs are pushed to the HAL
    // Runs on all modes except manual
    void loop();

    // ** Custom controller **
    bool pre_run();
    void run();
    void initialize();
    void terminate();

    // Writes the state to a file
    void logging();


    virtual void reset_pid() {};
};