#pragma once

#include <AP_Simulink/AP_Simulink.h>

class AP_Simulink_Plane : public AP_Simulink {
public:
    // Gathers values from Plane and sends them to the library.
    void pre_loop();
    void reset_pid() override;
};