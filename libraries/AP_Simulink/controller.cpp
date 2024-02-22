//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: controller.cpp
//
// Code generated for Simulink model 'controller'.
//
// Model version                  : 1.38
// Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
// C/C++ source code generated on : Thu Feb 22 01:07:14 2024
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex-M
// Code generation objective: Safety precaution
// Validation result: Not run
//
#include "controller.h"
#include "rtwtypes.h"

// user code (top of source file)

#pragma GCC diagnostic ignored "-Wfloat-equal"

// Model step function
void controller::step()
{
  real32_T rtb_Add;
  real32_T rtb_Add1;
  real32_T rtb_FilterCoefficient;
  real32_T rtb_FilterCoefficient_i;
  real32_T rtb_FilterCoefficient_j;

  // Saturate: '<S3>/Saturation' incorporates:
  //   Inport: '<Root>/yaw_error'

  if (controller_U.yaw_error > 0.52359879F) {
    rtb_Add = 0.52359879F;
  } else if (controller_U.yaw_error < -0.52359879F) {
    rtb_Add = -0.52359879F;
  } else {
    rtb_Add = controller_U.yaw_error;
  }

  // Sum: '<S3>/Add' incorporates:
  //   Inport: '<Root>/roll'
  //   Saturate: '<S3>/Saturation'

  rtb_Add -= controller_U.roll;

  // Gain: '<S137>/Filter Coefficient' incorporates:
  //   DiscreteIntegrator: '<S129>/Filter'
  //   Gain: '<S128>/Derivative Gain'
  //   Sum: '<S129>/SumD'

  rtb_FilterCoefficient = (0.0F * rtb_Add - controller_DW.Filter_DSTATE) *
    100.0F;

  // DiscreteIntegrator: '<S31>/Filter' incorporates:
  //   DiscreteIntegrator: '<S134>/Integrator'
  //   Sum: '<S143>/Sum'

  controller_Y.aileron = (rtb_Add + controller_DW.Integrator_DSTATE) +
    rtb_FilterCoefficient;

  // Saturate: '<S141>/Saturation'
  if (controller_Y.aileron > 1.57079637F) {
    // DiscreteIntegrator: '<S31>/Filter'
    controller_Y.aileron = 1.57079637F;
  } else if (controller_Y.aileron < -1.57079637F) {
    // DiscreteIntegrator: '<S31>/Filter'
    controller_Y.aileron = -1.57079637F;
  }

  // End of Saturate: '<S141>/Saturation'

  // Outport: '<Root>/rudder' incorporates:
  //   Gain: '<Root>/Gain'

  controller_Y.rudder = 0.5F * controller_Y.aileron;

  // Gain: '<S39>/Filter Coefficient' incorporates:
  //   Constant: '<S1>/Constant'
  //   DiscreteIntegrator: '<S31>/Filter'
  //   Gain: '<S30>/Derivative Gain'
  //   Inport: '<Root>/airspeed'
  //   Sum: '<S1>/Add'
  //   Sum: '<S31>/SumD'

  rtb_FilterCoefficient_i = ((80.0F - controller_U.airspeed) * 0.0F -
    controller_DW.Filter_DSTATE_p) * 100.0F;

  // Sum: '<S45>/Sum' incorporates:
  //   Constant: '<S1>/Constant'
  //   DiscreteIntegrator: '<S36>/Integrator'
  //   Inport: '<Root>/airspeed'
  //   Sum: '<S1>/Add'

  controller_Y.throttle = ((80.0F - controller_U.airspeed) +
    controller_DW.Integrator_DSTATE_i) + rtb_FilterCoefficient_i;

  // Saturate: '<S43>/Saturation'
  if (controller_Y.throttle > 100.0F) {
    // Sum: '<S45>/Sum' incorporates:
    //   Outport: '<Root>/throttle'

    controller_Y.throttle = 100.0F;
  } else if (controller_Y.throttle < 0.0F) {
    // Sum: '<S45>/Sum' incorporates:
    //   Outport: '<Root>/throttle'

    controller_Y.throttle = 0.0F;
  }

  // End of Saturate: '<S43>/Saturation'

  // Gain: '<S2>/Gain' incorporates:
  //   Inport: '<Root>/altitude'
  //   Inport: '<Root>/altitude_nav'
  //   Sum: '<S2>/Add'

  rtb_Add1 = (controller_U.altitude_nav - controller_U.altitude) * 3.0F;

  // Saturate: '<S2>/Saturation'
  if (rtb_Add1 > 0.52359879F) {
    rtb_Add1 = 0.52359879F;
  } else if (rtb_Add1 < -0.52359879F) {
    rtb_Add1 = -0.52359879F;
  }

  // Sum: '<S2>/Add1' incorporates:
  //   Inport: '<Root>/pitch'
  //   Saturate: '<S2>/Saturation'

  rtb_Add1 -= controller_U.pitch;

  // Gain: '<S88>/Filter Coefficient' incorporates:
  //   DiscreteIntegrator: '<S80>/Filter'
  //   Gain: '<S79>/Derivative Gain'
  //   Sum: '<S80>/SumD'

  rtb_FilterCoefficient_j = (0.0F * rtb_Add1 - controller_DW.Filter_DSTATE_o) *
    100.0F;

  // Sum: '<S94>/Sum' incorporates:
  //   DiscreteIntegrator: '<S85>/Integrator'

  controller_Y.elevator = (rtb_Add1 + controller_DW.Integrator_DSTATE_e) +
    rtb_FilterCoefficient_j;

  // Saturate: '<S92>/Saturation'
  if (controller_Y.elevator > 1.57079637F) {
    // Sum: '<S94>/Sum' incorporates:
    //   Outport: '<Root>/elevator'

    controller_Y.elevator = 1.57079637F;
  } else if (controller_Y.elevator < -1.57079637F) {
    // Sum: '<S94>/Sum' incorporates:
    //   Outport: '<Root>/elevator'

    controller_Y.elevator = -1.57079637F;
  }

  // End of Saturate: '<S92>/Saturation'

  // Update for DiscreteIntegrator: '<S129>/Filter'
  controller_DW.Filter_DSTATE += 0.0025F * rtb_FilterCoefficient;

  // Update for DiscreteIntegrator: '<S134>/Integrator'
  controller_DW.Integrator_DSTATE += 0.0025F * rtb_Add;

  // Update for DiscreteIntegrator: '<S31>/Filter'
  controller_DW.Filter_DSTATE_p += 0.0025F * rtb_FilterCoefficient_i;

  // Update for DiscreteIntegrator: '<S36>/Integrator' incorporates:
  //   Constant: '<S1>/Constant'
  //   Inport: '<Root>/airspeed'
  //   Sum: '<S1>/Add'

  controller_DW.Integrator_DSTATE_i += (80.0F - controller_U.airspeed) * 0.0025F;

  // Update for DiscreteIntegrator: '<S80>/Filter'
  controller_DW.Filter_DSTATE_o += 0.0025F * rtb_FilterCoefficient_j;

  // Update for DiscreteIntegrator: '<S85>/Integrator'
  controller_DW.Integrator_DSTATE_e += 0.0025F * rtb_Add1;
}

// Model initialize function
void controller::initialize()
{
  // (no initialization code required)
}

// Model terminate function
void controller::terminate()
{
  // (no terminate code required)
}

// Constructor
controller::controller() :
  controller_U(),
  controller_Y(),
  controller_DW(),
  controller_M()
{
  // Currently there is no constructor body generated.
}

// Destructor
// Currently there is no destructor body generated.
controller::~controller() = default;

// Real-Time Model get method
controller::RT_MODEL_controller_T * controller::getRTM()
{
  return (&controller_M);
}

//
// File trailer for generated code.
//
// [EOF]
//
