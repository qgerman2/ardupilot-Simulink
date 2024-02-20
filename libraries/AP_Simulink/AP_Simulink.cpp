#include <stdio.h>
#include "AP_Simulink/AP_Simulink.h"
#include "controller.h"
#include <GCS_MAVLink/GCS.h>
#include <AP_AHRS/AP_AHRS.h>

extern const AP_HAL::HAL &hal;
AP_AHRS *ahrs = AP_AHRS::get_singleton();
controller control;

controller::ExtU_controller_T input = {
    1.0f
};

controller::ExtY_controller_T output = {};

AP_Simulink::AP_Simulink() {}

void AP_Simulink::init() {
    printf("Simulink library init!!!");
    control.initialize();
    control.setExternalInputs(&input);
}

void AP_Simulink::run(controller ctrl) {
    control.step();
    output = control.getExternalOutputs();
    printf("\n%f", output.salida);
    input.entrada = output.salida;
    if (input.entrada > 10000.f) {
        input.entrada = 1.0f;
    }
    control.setExternalInputs(&input);
}