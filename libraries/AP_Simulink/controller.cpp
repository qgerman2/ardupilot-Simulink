//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: controller.cpp
//
// Code generated for Simulink model 'controller'.
//
// Model version                  : 1.24
// Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
// C/C++ source code generated on : Tue Feb 20 21:22:37 2024
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex-M
// Code generation objective: Safety precaution
// Validation result: Not run
//
#include "controller.h"

// user code (top of source file)

#pragma GCC diagnostic ignored "-Wfloat-equal"

// Model step function
void controller::step()
{
  // Sum: '<Root>/Add' incorporates:
  //   Inport: '<Root>/Roll_objetivo'
  //   Inport: '<Root>/Roll_sensor'

  controller_Y.Aleron = controller_U.Roll_objetivo - controller_U.Roll_sensor;

  // Outport: '<Root>/Timon' incorporates:
  //   Gain: '<Root>/Gain2'

  controller_Y.Timon = 0.5F * controller_Y.Aleron;

  // Outport: '<Root>/Elevador' incorporates:
  //   Gain: '<Root>/Gain1'
  //   Inport: '<Root>/Pitch_objetivo'
  //   Inport: '<Root>/Pitch_sensor'
  //   Sum: '<Root>/Add1'

  controller_Y.Elevador = (controller_U.Pitch_objetivo -
    controller_U.Pitch_sensor) * 2.0F;

  // Outport: '<Root>/Acelerador' incorporates:
  //   Inport: '<Root>/Throttle_objetivo'

  controller_Y.Acelerador = controller_U.Throttle_objetivo;
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
