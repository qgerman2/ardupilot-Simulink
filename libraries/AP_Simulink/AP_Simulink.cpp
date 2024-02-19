#include <stdio.h>
#include "AP_Simulink/AP_Simulink.h"
#include <GCS_MAVLink/GCS.h>
#include <AP_AHRS/AP_AHRS.h>

extern const AP_HAL::HAL &hal;
AP_AHRS *ahrs = AP_AHRS::get_singleton();

AP_Simulink::AP_Simulink() {}

void AP_Simulink::init() {
    printf("Simulink library init!!!");
}

void AP_Simulink::run(controller ctrl) {
    printf("\n%6d %6d %6d %6d %4.2f ", ctrl.pitch, ahrs->pitch_sensor, ctrl.roll, ahrs->roll_sensor, ctrl.throttle);
}