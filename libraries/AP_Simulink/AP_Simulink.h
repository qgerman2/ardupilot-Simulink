#pragma once
#include <AP_HAL/AP_HAL.h>
#include <AP_Math/AP_Math.h>
#include <AP_Logger/AP_Logger.h>

#define LOG_SIMULINK_1 248
struct PACKED log_Simulink_1 {
    LOG_PACKET_HEADER;
    uint64_t time_us;
    float control_mode;                // '<Root>/control_mode'
    float command_nav;                 // '<Root>/command_nav'
    float roll;                        // '<Root>/roll'
    float pitch;                       // '<Root>/pitch'
    float yaw;                         // '<Root>/yaw'
    float altitude;                    // '<Root>/altitude'
    float airspeed;                    // '<Root>/airspeed'
};
#define LOG_SIMULINK_STRUCTURE_1 \
    { LOG_SIMULINK_1, sizeof(log_Simulink_1), \
      "SLK1", "Qfffffff", \
      "TimeUS," \
      "control_mode," \
      "command_nav," \
      "roll," \
      "pitch," \
      "yaw," \
      "altitude," \
      "airspeed" \
      , "s-------", "F-------", true}

#define LOG_SIMULINK_2 249
struct PACKED log_Simulink_2 {
    LOG_PACKET_HEADER;
    uint64_t time_us;
    float yaw_nav;                     // '<Root>/yaw_nav'
    float yaw_error;                   // '<Root>/yaw_error'
    float altitude_nav;                // '<Root>/altitude_nav'
};
#define LOG_SIMULINK_STRUCTURE_2 \
    { LOG_SIMULINK_2, sizeof(log_Simulink_2), \
      "SLK2", "Qfff", \
      "TimeUS," \
      "yaw_nav," \
      "yaw_error," \
      "altitude_nav" \
      , "s---", "F---", true}

#define LOG_SIMULINK_3 250
struct PACKED log_Simulink_3 {
    LOG_PACKET_HEADER;
    uint64_t time_us;
    float aileron_rc;                  // '<Root>/aileron_rc'
    float elevator_rc;                 // '<Root>/elevator_rc'
    float rudder_rc;                   // '<Root>/rudder_rc'
    float throttle_rc;                 // '<Root>/throttle_rc'
    bool enable_rc;                    // '<Root>/enable_rc'
};
#define LOG_SIMULINK_STRUCTURE_3 \
    { LOG_SIMULINK_3, sizeof(log_Simulink_3), \
      "SLK3", "QffffB", \
      "TimeUS," \
      "aileron_rc," \
      "elevator_rc," \
      "rudder_rc," \
      "throttle_rc," \
      "enable_rc" \
      , "s-----", "F-----", true}

#define LOG_SIMULINK_4 251
struct PACKED log_Simulink_4 {
    LOG_PACKET_HEADER;
    uint64_t time_us;
    float roll_L1;                     // '<Root>/roll_L1'
    float pitch_TECS;                  // '<Root>/pitch_TECS'
    float airspeed_TECS;               // '<Root>/airspeed_TECS'
};
#define LOG_SIMULINK_STRUCTURE_4 \
    { LOG_SIMULINK_4, sizeof(log_Simulink_4), \
      "SLK4", "Qfff", \
      "TimeUS," \
      "roll_L1," \
      "pitch_TECS," \
      "airspeed_TECS" \
      , "s---", "F---", true}

#define LOG_SIMULINK_5 252
struct PACKED log_Simulink_5 {
    LOG_PACKET_HEADER;
    uint64_t time_us;
    bool enable_p;                     // '<Root>/enable'
    float aileron;                     // '<Root>/aileron'
    float elevator;                    // '<Root>/elevator'
    float rudder;                      // '<Root>/rudder'
    float throttle;                    // '<Root>/throttle'
};
#define LOG_SIMULINK_STRUCTURE_5 \
    { LOG_SIMULINK_5, sizeof(log_Simulink_5), \
      "SLK5", "QBffff", \
      "TimeUS," \
      "enable," \
      "aileron," \
      "elevator," \
      "rudder," \
      "throttle" \
      , "s-----", "F-----", true}

#define LOG_SIMULINK_6 253
struct PACKED log_Simulink_6 {
    LOG_PACKET_HEADER;
    uint64_t time_us;
    float airspeed_obj;                // '<Root>/airspeed_obj'
    float pitch_obj;                   // '<Root>/pitch_obj'
    float roll_obj;                    // '<Root>/roll_obj'
};
#define LOG_SIMULINK_STRUCTURE_6 \
    { LOG_SIMULINK_6, sizeof(log_Simulink_6), \
      "SLK6", "Qfff", \
      "TimeUS," \
      "airspeed_obj," \
      "pitch_obj," \
      "roll_obj" \
      , "s---", "F---", true}

class AP_Simulink {
public:
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
    float airspeed_TECS;

    AP_Simulink() {};
    void init();

    // Called everytime the main navigation (update mode) and PID (stabilize) controllers are done
    // but before the servo outputs are pushed to the HAL
    // Runs on all modes except manual
    void loop();

    // ** Custom controller **
    bool running = false;
    void step();

    void logging();

    virtual void reset_pid() {};
};