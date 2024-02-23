//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: controller.cpp
//
// Code generated for Simulink model 'controller'.
//
// Model version                  : 1.49
// Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
// C/C++ source code generated on : Fri Feb 23 15:40:00 2024
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex-M
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "controller.h"

// user code (top of source file)

#pragma GCC diagnostic ignored "-Wfloat-equal"

// Model step function
void controller::step()
{
  float rtb_Add1;
  float rtb_FilterCoefficient;
  float rtb_FilterCoefficient_i;
  float rtb_FilterCoefficient_j;
  float rtb_Filter_d;
  float rtb_Integrator_l;

  // Saturate: '<S3>/Saturation' incorporates:
  //   Inport: '<Root>/yaw_error'

  if (controller_U.yaw_error > 0.52359879F) {
    rtb_Filter_d = 0.52359879F;
  } else if (controller_U.yaw_error < -0.52359879F) {
    rtb_Filter_d = -0.52359879F;
  } else {
    rtb_Filter_d = controller_U.yaw_error;
  }

  // End of Saturate: '<S3>/Saturation'

  // Sum: '<S3>/Add' incorporates:
  //   Inport: '<Root>/roll'

  rtb_Integrator_l = rtb_Filter_d - controller_U.roll;

  // Gain: '<S137>/Filter Coefficient' incorporates:
  //   DiscreteIntegrator: '<S129>/Filter'
  //   Gain: '<S128>/Derivative Gain'
  //   Sum: '<S129>/SumD'

  rtb_FilterCoefficient = (0.0F * rtb_Integrator_l - controller_DW.Filter_DSTATE)
    * 100.0F;

  // Sum: '<S143>/Sum' incorporates:
  //   DiscreteIntegrator: '<S134>/Integrator'

  rtb_Add1 = (rtb_Integrator_l + controller_DW.Integrator_DSTATE) +
    rtb_FilterCoefficient;

  // Saturate: '<S141>/Saturation'
  if (rtb_Add1 > 1.57079637F) {
    rtb_Add1 = 1.57079637F;
  } else if (rtb_Add1 < -1.57079637F) {
    rtb_Add1 = -1.57079637F;
  }

  // End of Saturate: '<S141>/Saturation'

  // Outport: '<Root>/aileron'
  controller_Y.aileron = rtb_Add1;

  // Outport: '<Root>/rudder' incorporates:
  //   Gain: '<Root>/Gain'

  controller_Y.rudder = 0.5F * rtb_Add1;

  // Gain: '<S2>/Gain' incorporates:
  //   Inport: '<Root>/altitude'
  //   Inport: '<Root>/altitude_nav'
  //   Sum: '<S2>/Add'

  rtb_Add1 = (controller_U.altitude_nav - controller_U.altitude) * 3.0F;

  // Outport: '<Root>/debug' incorporates:
  //   Constant: '<S1>/Constant'
  //   Inport: '<Root>/airspeed'
  //   Sum: '<S1>/Add'

  controller_Y.debug[0] = rtb_Filter_d;
  controller_Y.debug[1] = rtb_Integrator_l;
  controller_Y.debug[2] = rtb_Add1;
  controller_Y.debug[3] = 50.0F - controller_U.airspeed;

  // Gain: '<S30>/Derivative Gain' incorporates:
  //   Constant: '<S1>/Constant'
  //   Gain: '<S33>/Integral Gain'
  //   Inport: '<Root>/airspeed'
  //   Sum: '<S1>/Add'

  rtb_Filter_d = (50.0F - controller_U.airspeed) * 0.0F;

  // Gain: '<S39>/Filter Coefficient' incorporates:
  //   DiscreteIntegrator: '<S31>/Filter'
  //   Gain: '<S30>/Derivative Gain'
  //   Sum: '<S31>/SumD'

  rtb_FilterCoefficient_i = (rtb_Filter_d - controller_DW.Filter_DSTATE_p) *
    100.0F;

  // Sum: '<S45>/Sum' incorporates:
  //   Constant: '<S1>/Constant'
  //   DiscreteIntegrator: '<S36>/Integrator'
  //   Gain: '<S41>/Proportional Gain'
  //   Inport: '<Root>/airspeed'
  //   Sum: '<S1>/Add'

  controller_Y.throttle = ((50.0F - controller_U.airspeed) * 0.1F +
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
  //   Gain: '<S90>/Proportional Gain'

  controller_Y.elevator = (0.1F * rtb_Add1 + controller_DW.Integrator_DSTATE_e)
    + rtb_FilterCoefficient_j;

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
  controller_DW.Filter_DSTATE += 0.01F * rtb_FilterCoefficient;

  // Update for DiscreteIntegrator: '<S134>/Integrator' incorporates:
  //   Gain: '<S131>/Integral Gain'

  controller_DW.Integrator_DSTATE += 0.0F * rtb_Integrator_l * 0.01F;

  // Update for DiscreteIntegrator: '<S36>/Integrator'
  controller_DW.Integrator_DSTATE_i += rtb_Filter_d * 0.01F;

  // Update for DiscreteIntegrator: '<S31>/Filter'
  controller_DW.Filter_DSTATE_p += 0.01F * rtb_FilterCoefficient_i;

  // Update for DiscreteIntegrator: '<S85>/Integrator' incorporates:
  //   Gain: '<S82>/Integral Gain'

  controller_DW.Integrator_DSTATE_e += 0.0F * rtb_Add1 * 0.01F;

  // Update for DiscreteIntegrator: '<S80>/Filter'
  controller_DW.Filter_DSTATE_o += 0.01F * rtb_FilterCoefficient_j;
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

// Block states get method
const controller::DW_controller_T &controller::getDWork() const
{
  return controller_DW;
}

// Block states set method
void controller::setDWork(const controller::DW_controller_T *pDW_controller_T)
{
  controller_DW = *pDW_controller_T;
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

// Real-Time Model set method
void controller::setRTM(const RT_MODEL_controller_T *pcontroller_M)
{
  controller_M = *pcontroller_M;
}

//
// File trailer for generated code.
//
// [EOF]
//
