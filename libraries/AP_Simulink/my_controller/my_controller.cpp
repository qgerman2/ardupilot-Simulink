//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: my_controller.cpp
//
// Code generated for Simulink model 'my_controller'.
//
// Model version                  : 1.138
// Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
// C/C++ source code generated on : Sun Feb 25 00:21:32 2024
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex-M
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "my_controller.h"

// user code (top of source file)

#pragma GCC diagnostic ignored "-Wfloat-equal"

// Model step function
void my_controller::step()
{
  float rtb_Add;
  float rtb_FilterCoefficient;
  float rtb_FilterCoefficient_d;
  float rtb_FilterCoefficient_o;
  float rtb_Integrator;
  float rtb_Integrator_e;

  // Outport: '<Root>/enable' incorporates:
  //   Constant: '<S1>/AUTO'
  //   Constant: '<S1>/NAV_WAYPOINT'
  //   Constant: '<S1>/STABILIZE'
  //   Inport: '<Root>/command_nav'
  //   Inport: '<Root>/control_mode'
  //   Inport: '<Root>/enable_rc'
  //   Logic: '<S1>/AND1'
  //   Logic: '<S1>/AND2'
  //   Logic: '<S1>/OR'
  //   RelationalOperator: '<S1>/Equal'
  //   RelationalOperator: '<S1>/Equal1'
  //   RelationalOperator: '<S1>/Equal2'

  Y.enable_p = (U.enable_rc && (((U.command_nav == 16.0F) && (U.control_mode ==
    10.0F)) || (U.control_mode == 2.0F)));

  // Outputs for Enabled SubSystem: '<S2>/AUTO controller' incorporates:
  //   EnablePort: '<S4>/Enable'

  // RelationalOperator: '<S2>/Relational Operator' incorporates:
  //   Constant: '<S2>/AUTO'
  //   Inport: '<Root>/control_mode'

  if (U.control_mode == 10.0F) {
    // Gain: '<S7>/Gain' incorporates:
    //   Inport: '<Root>/yaw_error'

    DW.Merge = 0.5F * U.yaw_error;

    // Saturate: '<S7>/Saturation'
    if (DW.Merge > 0.785398185F) {
      // Gain: '<S7>/Gain' incorporates:
      //   Merge: '<S2>/Merge'

      DW.Merge = 0.785398185F;
    } else if (DW.Merge < -0.785398185F) {
      // Gain: '<S7>/Gain' incorporates:
      //   Merge: '<S2>/Merge'

      DW.Merge = -0.785398185F;
    }

    // End of Saturate: '<S7>/Saturation'

    // Merge: '<S2>/Merge2' incorporates:
    //   Constant: '<S8>/Constant'
    //   SignalConversion generated from: '<S4>/airspeed_obj'

    DW.Merge2 = 40.0F;

    // Gain: '<S6>/Gain' incorporates:
    //   Inport: '<Root>/altitude'
    //   Inport: '<Root>/altitude_nav'
    //   Sum: '<S6>/Add'

    DW.Merge1 = (U.altitude_nav - U.altitude) * 0.025F;

    // Saturate: '<S6>/Saturation'
    if (DW.Merge1 > 0.52359879F) {
      // Gain: '<S6>/Gain' incorporates:
      //   Merge: '<S2>/Merge1'

      DW.Merge1 = 0.52359879F;
    } else if (DW.Merge1 < -0.52359879F) {
      // Gain: '<S6>/Gain' incorporates:
      //   Merge: '<S2>/Merge1'

      DW.Merge1 = -0.52359879F;
    }

    // End of Saturate: '<S6>/Saturation'
  }

  // End of RelationalOperator: '<S2>/Relational Operator'
  // End of Outputs for SubSystem: '<S2>/AUTO controller'

  // Outputs for Enabled SubSystem: '<S2>/STABILIZE controller' incorporates:
  //   EnablePort: '<S5>/Enable'

  // RelationalOperator: '<S2>/Relational Operator1' incorporates:
  //   Constant: '<S2>/STABILIZE'
  //   Inport: '<Root>/control_mode'

  if (U.control_mode == 2.0F) {
    // Gain: '<S7>/Gain' incorporates:
    //   Gain: '<S5>/Gain'
    //   Inport: '<Root>/aileron_rc'
    //   Merge: '<S2>/Merge'

    DW.Merge = 0.5F * U.aileron_rc;

    // Gain: '<S6>/Gain' incorporates:
    //   Gain: '<S5>/Gain1'
    //   Inport: '<Root>/elevator_rc'
    //   Merge: '<S2>/Merge1'

    DW.Merge1 = 0.5F * U.elevator_rc;

    // Merge: '<S2>/Merge2' incorporates:
    //   Gain: '<S5>/Gain2'
    //   Inport: '<Root>/throttle_rc'

    DW.Merge2 = U.throttle_rc;
  }

  // End of RelationalOperator: '<S2>/Relational Operator1'
  // End of Outputs for SubSystem: '<S2>/STABILIZE controller'

  // Sum: '<S10>/Add' incorporates:
  //   Inport: '<Root>/roll'

  rtb_Integrator = DW.Merge - U.roll;

  // Gain: '<S96>/Filter Coefficient' incorporates:
  //   DiscreteIntegrator: '<S88>/Filter'
  //   Gain: '<S87>/Derivative Gain'
  //   Sum: '<S88>/SumD'

  rtb_FilterCoefficient = (0.5F * rtb_Integrator - DW.Filter_DSTATE) * 100.0F;

  // Outport: '<Root>/aileron' incorporates:
  //   DiscreteIntegrator: '<S93>/Integrator'
  //   Sum: '<S102>/Sum'

  Y.aileron = (rtb_Integrator + DW.Integrator_DSTATE) + rtb_FilterCoefficient;

  // Sum: '<S9>/Add1' incorporates:
  //   Inport: '<Root>/pitch'

  rtb_Integrator_e = DW.Merge1 - U.pitch;

  // Gain: '<S47>/Filter Coefficient' incorporates:
  //   DiscreteIntegrator: '<S39>/Filter'
  //   Gain: '<S38>/Derivative Gain'
  //   Sum: '<S39>/SumD'

  rtb_FilterCoefficient_d = (0.1F * rtb_Integrator_e - DW.Filter_DSTATE_e) *
    100.0F;

  // Outport: '<Root>/elevator' incorporates:
  //   DiscreteIntegrator: '<S44>/Integrator'
  //   Sum: '<S53>/Sum'

  Y.elevator = (rtb_Integrator_e + DW.Integrator_DSTATE_f) +
    rtb_FilterCoefficient_d;

  // Sum: '<S11>/Add' incorporates:
  //   Inport: '<Root>/airspeed'

  rtb_Add = DW.Merge2 - U.airspeed;

  // Gain: '<S145>/Filter Coefficient' incorporates:
  //   DiscreteIntegrator: '<S137>/Filter'
  //   Sum: '<S137>/SumD'

  rtb_FilterCoefficient_o = (rtb_Add - DW.Filter_DSTATE_d) * 100.0F;

  // Outport: '<Root>/throttle' incorporates:
  //   DiscreteIntegrator: '<S142>/Integrator'
  //   Gain: '<S147>/Proportional Gain'
  //   Sum: '<S151>/Sum'

  Y.throttle = (5.0F * rtb_Add + DW.Integrator_DSTATE_a) +
    rtb_FilterCoefficient_o;

  // Outport: '<Root>/airspeed_obj'
  Y.airspeed_obj = DW.Merge2;

  // Outport: '<Root>/pitch_obj'
  Y.pitch_obj = DW.Merge1;

  // Outport: '<Root>/roll_obj'
  Y.roll_obj = DW.Merge;

  // Update for DiscreteIntegrator: '<S93>/Integrator' incorporates:
  //   Gain: '<S90>/Integral Gain'

  DW.Integrator_DSTATE += 0.0F * rtb_Integrator * 0.01F;

  // Update for DiscreteIntegrator: '<S88>/Filter'
  DW.Filter_DSTATE += 0.01F * rtb_FilterCoefficient;

  // Update for DiscreteIntegrator: '<S44>/Integrator' incorporates:
  //   Gain: '<S41>/Integral Gain'

  DW.Integrator_DSTATE_f += 0.1F * rtb_Integrator_e * 0.01F;

  // Update for DiscreteIntegrator: '<S39>/Filter'
  DW.Filter_DSTATE_e += 0.01F * rtb_FilterCoefficient_d;

  // Update for DiscreteIntegrator: '<S142>/Integrator'
  DW.Integrator_DSTATE_a += 0.01F * rtb_Add;

  // Update for DiscreteIntegrator: '<S137>/Filter'
  DW.Filter_DSTATE_d += 0.01F * rtb_FilterCoefficient_o;
}

// Model initialize function
void my_controller::initialize()
{
  // (no initialization code required)
}

// Model terminate function
void my_controller::terminate()
{
  // (no terminate code required)
}

// Block states get method
const DW_T &my_controller::getDWork() const
{
  return DW;
}

// Block states set method
void my_controller::setDWork(const DW_T *pDW_T)
{
  DW = *pDW_T;
}

// Constructor
my_controller::my_controller():
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
