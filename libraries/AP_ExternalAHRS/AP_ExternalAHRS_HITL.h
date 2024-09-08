#pragma once

#include "AP_ExternalAHRS_backend.h"

#ifndef HAL_EXTERNAL_AHRS_HITL_ENABLED
#define HAL_EXTERNAL_AHRS_HITL_ENABLED HAL_EXTERNAL_AHRS_ENABLED
#endif

#if HAL_EXTERNAL_AHRS_HITL_ENABLED
#include "AP_ExternalAHRS_backend.h"
#include <AP_GPS/AP_GPS.h>
#include <AP_HAL/AP_HAL.h>

class AP_ExternalAHRS_HITL : public AP_ExternalAHRS_backend {
public:
    AP_ExternalAHRS_HITL(AP_ExternalAHRS *frontend, AP_ExternalAHRS::state_t &state);
    int8_t get_port(void) const override;
    bool pre_arm_check(char *failure_msg, uint8_t failure_msg_len) const override;
    const char *get_name() const override { return "HITL"; };

    bool healthy(void) const override;
    bool initialised(void) const override;
    void get_filter_status(nav_filter_status &status) const override;
    void send_status_report(class GCS_MAVLINK &link) const override;
    void update() override;

private:
    struct {
        char preamble[4] = { 'H', 'I', 'T', 'L' };
        int type;
    } header;

    struct {
        AP_ExternalAHRS::baro_data_message_t baro{
            .instance = 0,
            .pressure_pa = 101325,
            .temperature = 25
        };
        AP_ExternalAHRS::mag_data_message_t mag{
            .field = Vector3f(400, 0, 0)
        };
        AP_ExternalAHRS::gps_data_message_t gps{
            .fix_type = GPS_FIX_TYPE_NO_FIX
        };
        AP_ExternalAHRS::ins_data_message_t ins{
            .accel = Vector3f(0, 0, -1000)
        };
        AP_ExternalAHRS::airspeed_data_message_t aspd{};
        float q1, q2, q3, q4;
    } ahrs_msg;


    struct {
        uint8_t state;
        uint32_t ahrs_count;
    } state_msg;

    struct {
        float roll_cyclic;
        float pitch_cyclic;
        float collective;
        float tail;
        float throttle;
    } heli_msg;

    struct {
        float roll;
        float pitch;
        float yaw;
        float throttle;
    } plane_msg;

    char ping_msg[21] = "PINGHITLPINGHITLPING";

    AP_HAL::UARTDriver *uart;

    uint8_t buffer[200];
    long unsigned int pos = 0;

    uint32_t baudrate;
    int8_t port_num;
    bool port_open = false;

    uint32_t on_ahrs_time = 0;

    // keep track of how many ahrs packet have been received
    uint32_t ahrs_count_time = 0;
    uint32_t ahrs_count = 0;
    uint32_t ahrs_count_send = 0;

    // time without updates before the ekf ahrs becomes unhealthy
    const uint32_t unhealthy_ahrs_ms = 100;

    // ping timer
    uint32_t last_ping_time = 0;
    const uint32_t ping_interval = 1000;

    void thread();

    void read(uint32_t t);
    void on_ahrs(uint32_t t);
    void on_reset();
    void push_sensors();
    void push_ekf();
    void send_rc();
    void send_ping();
};

#endif
