//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: controller.cpp
//
// Code generated for Simulink model 'controller'.
//
// Model version                  : 1.1
// Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
// C/C++ source code generated on : Tue Feb 20 00:59:20 2024
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex-M
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "controller.h"

// Model step function
void controller::step()
{
  // Outport: '<Root>/salida' incorporates:
  //   Gain: '<Root>/Gain'
  //   Inport: '<Root>/entrada'

  controller_Y.salida = 2.0F * controller_U.entrada;
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
