#include "AP_Simulink.h"
#include "Plane.h"

void AP_Simulink_Plane::test() {
    printf("\n%6.2f", plane.TECS_controller._hgt_dem);
}