#pragma once
#include <AP_HAL/AP_HAL.h>
#include <AP_Math/AP_Math.h>

class AP_Simulink {
public:
#if CONFIG_HAL_BOARD == HAL_BOARD_SITL
    char log_header[346] =
        "time         , "
        "active       , "
        "control_mode , "
        "commmand_nav , "
        "roll         , "
        "pitch        , "
        "yaw          , "
        "altitude     , "
        "airspeed     , "
        "yaw_nav      , "
        "yaw_error    , "
        "altitude_nav , "
        "roll_L1      , "
        "pitch_TECS   , "
        "throttle_TECS, "
        "aileron_rc   , "
        "elevator_rc  , "
        "rudder_rc    , "
        "throttle_rc  , "
        "aileron      , "
        "elevator     , "
        "rudder       , "
        "throttle     , ";
#endif

    // Check ArduPlane/AP_Simulink.cpp for details on these variables
    // rc input
    float aileron_rc;
    float elevator_rc;
    float rudder_rc;
    float throttle_rc;

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