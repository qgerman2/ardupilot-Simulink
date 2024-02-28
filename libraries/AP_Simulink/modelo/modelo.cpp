//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: modelo.cpp
//
// Code generated for Simulink model 'modelo'.
//
// Model version                  : 1.9
// Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
// C/C++ source code generated on : Wed Feb 28 03:09:11 2024
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex-M
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "modelo.h"

// Model step function
void modelo::step()
{
  float rtb_Add{ 0.0F };

  float rtb_Add1{ 0.0F };

  float rtb_SumD{ 0.0F };

  float rtb_SumD_a{ 0.0F };

  // Sum: '<Root>/Add' incorporates:
  //   Inport: '<Root>/aileron_rc'
  //   Inport: '<Root>/roll'

  rtb_Add = U.aileron_rc - U.roll;

  // Sum: '<S29>/SumD' incorporates:
  //   DiscreteIntegrator: '<S29>/Filter'

  rtb_SumD = rtb_Add - DW.Filter_DSTATE;

  // Outport: '<Root>/aileron' incorporates:
  //   DiscreteIntegrator: '<S34>/Integrator'
  //   Sum: '<S43>/Sum'

  Y.aileron = (rtb_Add + DW.Integrator_DSTATE) + rtb_SumD;

  // Sum: '<Root>/Add1' incorporates:
  //   Inport: '<Root>/elevator_rc'
  //   Inport: '<Root>/pitch'

  rtb_Add1 = U.elevator_rc - U.pitch;

  // Sum: '<S77>/SumD' incorporates:
  //   DiscreteIntegrator: '<S77>/Filter'

  rtb_SumD_a = rtb_Add1 - DW.Filter_DSTATE_k;

  // Outport: '<Root>/elevator' incorporates:
  //   DiscreteIntegrator: '<S82>/Integrator'
  //   Sum: '<S91>/Sum'

  Y.elevator = (rtb_Add1 + DW.Integrator_DSTATE_p) + rtb_SumD_a;

  // Outport: '<Root>/enable_p' incorporates:
  //   Inport: '<Root>/enable_rc'

  Y.enable_p = U.enable_rc;

  // Outport: '<Root>/throttle' incorporates:
  //   Inport: '<Root>/throttle_rc'

  Y.throttle = U.throttle_rc;

  // Update for DiscreteIntegrator: '<S34>/Integrator'
  DW.Integrator_DSTATE += 0.02F * rtb_Add;
  if (DW.Integrator_DSTATE > 1.0F) {
    DW.Integrator_DSTATE = 1.0F;
  } else if (DW.Integrator_DSTATE < -1.0F) {
    DW.Integrator_DSTATE = -1.0F;
  }

  // End of Update for DiscreteIntegrator: '<S34>/Integrator'

  // Update for DiscreteIntegrator: '<S29>/Filter'
  DW.Filter_DSTATE += 0.02F * rtb_SumD;

  // Update for DiscreteIntegrator: '<S82>/Integrator'
  DW.Integrator_DSTATE_p += 0.02F * rtb_Add1;
  if (DW.Integrator_DSTATE_p > 1.0F) {
    DW.Integrator_DSTATE_p = 1.0F;
  } else if (DW.Integrator_DSTATE_p < -1.0F) {
    DW.Integrator_DSTATE_p = -1.0F;
  }

  // End of Update for DiscreteIntegrator: '<S82>/Integrator'

  // Update for DiscreteIntegrator: '<S77>/Filter'
  DW.Filter_DSTATE_k += 0.02F * rtb_SumD_a;
}

// Model initialize function
void modelo::initialize()
{
  // (no initialization code required)
}

// Model terminate function
void modelo::terminate()
{
  // (no terminate code required)
}

// Constructor
modelo::modelo():
  DW(),
  U(),
  Y()
{
  // Currently there is no constructor body generated.
}

//
// File trailer for generated code.
//
// [EOF]
//
