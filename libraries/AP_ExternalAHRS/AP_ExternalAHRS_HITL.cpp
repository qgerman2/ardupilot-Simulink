#define ALLOW_DOUBLE_MATH_FUNCTIONS

#include "AP_ExternalAHRS_HITL.h"

#if HAL_EXTERNAL_AHRS_HITL_ENABLED
#include <AP_Vehicle/AP_Vehicle.h>
#include <AP_AHRS/AP_AHRS.h>
#include <AP_Arming/AP_Arming.h>
#include <SRV_Channel/SRV_Channel.h>
#include <AP_Baro/AP_Baro.h>
#include <AP_Compass/AP_Compass.h>
#include <AP_GPS/AP_GPS.h>
#include <AP_InertialSensor/AP_InertialSensor.h>
#include <GCS_MAVLink/GCS.h>
#include <AP_BoardConfig/AP_BoardConfig.h>

extern const AP_HAL::HAL &hal;

AP_ExternalAHRS_HITL::AP_ExternalAHRS_HITL(AP_ExternalAHRS *_frontend,
    AP_ExternalAHRS::state_t &_state) : AP_ExternalAHRS_backend(_frontend, _state) {

    // external ekf initial state
    state.have_location = false;
    state.have_origin = false;
    state.have_quaternion = false;
    state.have_velocity = false;

    // start serial communications
    auto &sm = AP::serialmanager();
    uart = sm.find_serial(AP_SerialManager::SerialProtocol_AHRS, 0);
    if (!uart) {
        GCS_SEND_TEXT(MAV_SEVERITY_ERROR, "HITL: No serial port defined as type ExternalAHRS");
        return;
    }

    // thread
    if (!hal.scheduler->thread_create(FUNCTOR_BIND_MEMBER(&AP_ExternalAHRS_HITL::thread, void), "AHRS", 2048, AP_HAL::Scheduler::PRIORITY_SPI, 0)) {
        AP_BoardConfig::allocation_error("HITL: Failed to allocate HITL driver thread");
    }
    GCS_SEND_TEXT(MAV_SEVERITY_INFO, "HITL: Initialized");
}

int8_t AP_ExternalAHRS_HITL::get_port(void) const {
    auto &sm = AP::serialmanager();
    return sm.find_portnum(AP_SerialManager::SerialProtocol_AHRS, 0);
};

bool AP_ExternalAHRS_HITL::pre_arm_check(char *failure_msg, uint8_t failure_msg_len) const {
    return true;
}

void AP_ExternalAHRS_HITL::thread(void) {
    auto &sm = AP::serialmanager();
    uart->begin(sm.find_baudrate(AP_SerialManager::SerialProtocol_AHRS, 0));

    while (true) {
        uint32_t now = AP_HAL::millis();
        // find efi
#if AP_EFI_SCRIPTING_ENABLED
        if (efi == nullptr) {
            efi = AP::EFI()->get_backend(0);
            if (efi != nullptr) {
                GCS_SEND_TEXT(MAV_SEVERITY_INFO, "HITL: EFI Enabled");
            }
        }
#endif
        // keep track of how many state packets have been received
        // every second (1000 ms)
        // these are shown in the xplane plugin and it should match the fps
        if (now - ahrs_count_time > 1000) {
            state_msg.ahrs_count = ahrs_count;
            ahrs_count = 0;
            ahrs_count_time = now;
        }
        // read and process data from xplane plugin
        uint32_t last_ahrs_time = on_ahrs_time;
        read(now);
        if (!healthy()) {
            // not connected, spam sensor data to avoid ardupilot complaining
            // and send pings
            push_sensors();
            if (now - last_ping_time > ping_interval) {
                send_ping();
                last_ping_time = now;
            }
        } else {
            // connected, on new telemetry from xplane
            // respond with servo outputs
            if (on_ahrs_time > last_ahrs_time) {
                push_sensors();
                push_ekf();
#if AP_EFI_SCRIPTING_ENABLED
                push_efi();
#endif
                send_rc();
            }
        }
        hal.scheduler->delay(1);
    }
}

void AP_ExternalAHRS_HITL::read(uint32_t t) {
    uint32_t nbytes = uart->available();
    struct _header header;
    struct _footer footer;
    while (nbytes-- > 0) {
        // read a single byte into the buffer
        if (!uart->read(&buffer[pos], 1)) {
            continue;
        }
        // check if the first bytes of the message match the preamble
        if (pos < sizeof(header.preamble)) {
            if (buffer[pos] != header.preamble[pos]) {
                pos = 0;
                continue;
            }
        }
        // if we get to this point it means the first bytes have matched the
        // header so far
        pos++;
        if (pos == sizeof(header)) {
            memcpy(&header, buffer, sizeof(header));
            if (header.type == 1) {
                on_reset();
                pos = 0;
            }
        } else if (pos == sizeof(ahrs_msg) + sizeof(header) + sizeof(footer)) {
            pos = 0;
            memcpy(&header, buffer, sizeof(header));
            memcpy(&footer, &buffer[sizeof(header) + sizeof(ahrs_msg)], sizeof(footer));
            if (header.type != 0) { continue; }
            if (footer.len != sizeof(header) + sizeof(ahrs_msg)) { continue; }
            if (strncmp(footer.postamble, "END", 3) != 0) { continue; };
            memcpy(&ahrs_msg, &buffer[sizeof(header)], sizeof(ahrs_msg));
            on_ahrs(t);
        }
    }
}

float random_float();
float random_float() {
    return ((((unsigned)random()) % 2000000) - 1.0e6) / 1.0e6;
}

void AP_ExternalAHRS_HITL::on_ahrs(uint32_t t) {
    // baro readings are considered unhealthy if its the same everytime
    // this can happen if the plane is parked or in calibration
    ahrs_msg.baro.pressure_pa += random_float();
    ahrs_msg.baro.temperature += random_float();
    // scale compass reading magnitude to match gps location
    float intensity;
    float declination;
    float inclination;
    if (AP_Declination::get_mag_field_ef(
        ahrs_msg.gps.latitude * 1e-7f,
        ahrs_msg.gps.longitude * 1e-7f,
        intensity, declination, inclination)) {
        ahrs_msg.mag.field *= (intensity * 1000);
    }
    on_ahrs_time = t;
    ahrs_msg.efi.last_updated_ms = t;
    ahrs_count++;
}

void AP_ExternalAHRS_HITL::push_sensors() {
    AP::ins().handle_external(ahrs_msg.ins);
    AP::compass().handle_external(ahrs_msg.mag);
    AP::baro().handle_external(ahrs_msg.baro);
    AP::gps().handle_external(ahrs_msg.gps);
    AP::airspeed()->handle_external(ahrs_msg.aspd);
}

void AP_ExternalAHRS_HITL::push_ekf() {
    WITH_SEMAPHORE(state.sem);
    state.accel = ahrs_msg.ins.accel;
    state.gyro = ahrs_msg.ins.gyro;
    state.location = { ahrs_msg.gps.latitude, ahrs_msg.gps.longitude, ahrs_msg.gps.msl_altitude, Location::AltFrame::ABSOLUTE };
    state.have_location = true;
    state.velocity = { ahrs_msg.gps.ned_vel_north, ahrs_msg.gps.ned_vel_east, ahrs_msg.gps.ned_vel_down };
    state.have_velocity = true;
    state.quat = { ahrs_msg.q1, ahrs_msg.q2, ahrs_msg.q3, ahrs_msg.q4 };
    state.have_quaternion = true;
    if (!state.have_origin) {
        state.origin = state.location;
        state.have_origin = true;
    }
}

#if AP_EFI_SCRIPTING_ENABLED
void AP_ExternalAHRS_HITL::push_efi() {
    if (efi != nullptr) {
        efi->handle_scripting(ahrs_msg.efi);
    }
}
#endif

// restart ahrs

void AP_ExternalAHRS_HITL::on_reset() {
    GCS_SEND_TEXT(MAV_SEVERITY_WARNING, "HITL: Reboot");
    AP::vehicle()->reboot(false);
}

// rc

void AP_ExternalAHRS_HITL::send_rc() {
    struct _header header;
    header.type = 1;
    ///bool safety_on = hal.util->safety_switch_state() != AP_HAL::Util::SAFETY_DISARMED;
    // disabled check due to inconsistent behaviour
    bool safety_on = false;
    bool armed = AP::arming().is_armed();
    if (safety_on) {
        state_msg.state = 0;
    } else {
        state_msg.state = armed ? 2 : 1;
    }
    state_msg.starter = 0;
    SRV_Channels::get_output_pwm(SRV_Channel::k_starter, state_msg.starter);
    uart->write(reinterpret_cast<uint8_t *>(&header), sizeof(header));
    uart->write(reinterpret_cast<uint8_t *>(&state_msg), sizeof(state_msg));
    struct _footer footer;
    footer.len = sizeof(header) + sizeof(state_msg);
    uart->write(reinterpret_cast<uint8_t *>(&footer), sizeof(footer));
#if APM_BUILD_TYPE(APM_BUILD_ArduPlane)
    header.type = 2;
    SRV_Channels::get_output_pwm(SRV_Channel::k_aileron, plane_msg.roll);
    SRV_Channels::get_output_pwm(SRV_Channel::k_elevator, plane_msg.pitch);
    SRV_Channels::get_output_pwm(SRV_Channel::k_throttle, plane_msg.throttle);
    SRV_Channels::get_output_pwm(SRV_Channel::k_rudder, plane_msg.yaw);
    uart->write(reinterpret_cast<uint8_t *>(&header), sizeof(header));
    uart->write(reinterpret_cast<uint8_t *>(&plane_msg), sizeof(plane_msg));
    footer.len = sizeof(header) + sizeof(plane_msg);
    uart->write(reinterpret_cast<uint8_t *>(&footer), sizeof(footer));
#endif
#if APM_BUILD_TYPE(APM_BUILD_Heli)
    header.type = 3;
    SRV_Channels::get_output_pwm(SRV_Channel::k_motor1, heli_msg.roll_cyclic);
    SRV_Channels::get_output_pwm(SRV_Channel::k_motor2, heli_msg.pitch_cyclic);
    SRV_Channels::get_output_pwm(SRV_Channel::k_motor3, heli_msg.collective);
    SRV_Channels::get_output_pwm(SRV_Channel::k_motor4, heli_msg.tail);
    SRV_Channels::get_output_pwm(SRV_Channel::k_heli_rsc, heli_msg.throttle);
    uart->write(reinterpret_cast<uint8_t *>(&header), sizeof(header));
    uart->write(reinterpret_cast<uint8_t *>(&heli_msg), sizeof(heli_msg));
    footer.len = sizeof(header) + sizeof(heli_msg);
    uart->write(reinterpret_cast<uint8_t *>(&footer), sizeof(footer));
#endif
}

void AP_ExternalAHRS_HITL::send_ping() {
    struct _header header;
    header.type = 0;
    uart->write(reinterpret_cast<uint8_t *>(&header), sizeof(header));
    uart->write(reinterpret_cast<uint8_t *>(&ping_msg[0]), sizeof(ping_msg));
    struct _footer footer;
    footer.len = sizeof(header) + sizeof(ping_msg);
    uart->write(reinterpret_cast<uint8_t *>(&footer), sizeof(footer));
}

// external EKF
// not really an EKF, just grab attitude quaternion directly from X-Plane

bool AP_ExternalAHRS_HITL::healthy(void) const {
    return (AP_HAL::millis() - on_ahrs_time < unhealthy_ahrs_ms);
}

bool AP_ExternalAHRS_HITL::initialised(void) const {
    return (on_ahrs_time > 0);
}

void AP_ExternalAHRS_HITL::get_filter_status(nav_filter_status &status) const {
    memset(&status, 0, sizeof(status));
    status.flags.initalized = initialised();
    if (healthy()) {
        status.flags.attitude = 1;
        status.flags.vert_vel = 1;
        status.flags.vert_pos = 1;
        status.flags.horiz_vel = 1;
        status.flags.horiz_pos_rel = 1;
        status.flags.horiz_pos_abs = 1;
        status.flags.pred_horiz_pos_rel = 1;
        status.flags.pred_horiz_pos_abs = 1;
        status.flags.using_gps = 1;
    }
}

void AP_ExternalAHRS_HITL::send_status_report(GCS_MAVLINK &link) const {
    uint16_t flags = 0;
    nav_filter_status filterStatus;
    get_filter_status(filterStatus);
    if (filterStatus.flags.attitude) {
        flags |= EKF_ATTITUDE;
    }
    if (filterStatus.flags.horiz_vel) {
        flags |= EKF_VELOCITY_HORIZ;
    }
    if (filterStatus.flags.vert_vel) {
        flags |= EKF_VELOCITY_VERT;
    }
    if (filterStatus.flags.horiz_pos_rel) {
        flags |= EKF_POS_HORIZ_REL;
    }
    if (filterStatus.flags.horiz_pos_abs) {
        flags |= EKF_POS_HORIZ_ABS;
    }
    if (filterStatus.flags.vert_pos) {
        flags |= EKF_POS_VERT_ABS;
    }
    if (filterStatus.flags.terrain_alt) {
        flags |= EKF_POS_VERT_AGL;
    }
    if (filterStatus.flags.const_pos_mode) {
        flags |= EKF_CONST_POS_MODE;
    }
    if (filterStatus.flags.pred_horiz_pos_rel) {
        flags |= EKF_PRED_POS_HORIZ_REL;
    }
    if (filterStatus.flags.pred_horiz_pos_abs) {
        flags |= EKF_PRED_POS_HORIZ_ABS;
    }
    if (!filterStatus.flags.initalized) {
        flags |= EKF_UNINITIALIZED;
    }
    mavlink_msg_ekf_status_report_send(link.get_chan(), flags, 0, 0, 0, 0, 0, 0);
    return;
}

void AP_ExternalAHRS_HITL::update() {
    return;
}

#endif
