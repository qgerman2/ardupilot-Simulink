//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: passthrough.cpp
//
// Code generated for Simulink model 'passthrough'.
//
// Model version                  : 1.146
// Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
// C/C++ source code generated on : Sun Feb 25 00:33:22 2024
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex-M
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "passthrough.h"

// user code (top of source file)

#pragma GCC diagnostic ignored "-Wfloat-equal"

// Computed Parameter: DiscreteTimeIntegrator_gainval
//  Referenced by: '<Root>/Discrete-Time Integrator'

#define rtCP_DiscreteTimeIntegrator_gai (0.01F)

// Pooled Parameter (Expression: 0)
//  Referenced by:
//    '<Root>/Constant1'
//    '<Root>/Discrete-Time Integrator'

#define rtCP_pooled1                   (0.0F)

// Model step function
void passthrough::step()
{
  // Outport: '<Root>/debug' incorporates:
  //   DiscreteIntegrator: '<Root>/Discrete-Time Integrator'

  Y.debug = DW.DiscreteTimeIntegrator_DSTATE;

  // Outport: '<Root>/enable' incorporates:
  //   Inport: '<Root>/enable_rc'

  Y.enable_p = U.enable_rc;

  // Outport: '<Root>/aileron' incorporates:
  //   Inport: '<Root>/aileron_rc'

  Y.aileron = U.aileron_rc;

  // Outport: '<Root>/elevator' incorporates:
  //   Inport: '<Root>/elevator_rc'

  Y.elevator = U.elevator_rc;

  // Outport: '<Root>/rudder' incorporates:
  //   Inport: '<Root>/rudder_rc'

  Y.rudder = U.rudder_rc;

  // Outport: '<Root>/throttle' incorporates:
  //   Inport: '<Root>/throttle_rc'

  Y.throttle = U.throttle_rc;

  // Update for DiscreteIntegrator: '<Root>/Discrete-Time Integrator' incorporates:
  //   Constant: '<Root>/Constant1'

  DW.DiscreteTimeIntegrator_DSTATE += rtCP_DiscreteTimeIntegrator_gai *
    rtCP_pooled1;
}

// Model initialize function
void passthrough::initialize()
{
  // (no initialization code required)
}

// Model terminate function
void passthrough::terminate()
{
  // (no terminate code required)
}

// Block states get method
const passthrough::DW_T &passthrough::getDWork() const
{
  return DW;
}

// Block states set method
void passthrough::setDWork(const passthrough::DW_T *pDW_T)
{
  DW = *pDW_T;
}

// Constructor
passthrough::passthrough():
  U(),
  Y(),
  DW()
{
  // Currently there is no constructor body generated.
}

//
// File trailer for generated code.
//
// [EOF]
//
