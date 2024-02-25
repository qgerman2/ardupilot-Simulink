//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: my_controller.cpp
//
// Code generated for Simulink model 'my_controller'.
//
// Model version                  : 1.158
// Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
// C/C++ source code generated on : Sun Feb 25 14:59:07 2024
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
  float rtb_Add1;
  float rtb_Add_p;
  float rtb_SumD;
  float rtb_SumD_i;
  float rtb_SumD_k;

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

    DW.Merge = 0.333333343F * U.aileron_rc;

    // Gain: '<S6>/Gain' incorporates:
    //   Gain: '<S5>/Gain1'
    //   Inport: '<Root>/elevator_rc'
    //   Merge: '<S2>/Merge1'

    DW.Merge1 = 0.166666672F * U.elevator_rc;

    // Merge: '<S2>/Merge2' incorporates:
    //   Gain: '<S5>/Gain2'
    //   Inport: '<Root>/throttle_rc'

    DW.Merge2 = U.throttle_rc;
  }

  // End of RelationalOperator: '<S2>/Relational Operator1'
  // End of Outputs for SubSystem: '<S2>/STABILIZE controller'

  // Sum: '<S10>/Add' incorporates:
  //   Inport: '<Root>/roll'

  rtb_Add = DW.Merge - U.roll;

  // Sum: '<S88>/SumD' incorporates:
  //   DiscreteIntegrator: '<S88>/Filter'

  rtb_SumD = rtb_Add - DW.Filter_DSTATE;

  // Outport: '<Root>/aileron' incorporates:
  //   DiscreteIntegrator: '<S93>/Integrator'
  //   Gain: '<S98>/Proportional Gain'
  //   Sum: '<S102>/Sum'

  Y.aileron = (2.0F * rtb_Add + DW.Integrator_DSTATE) + rtb_SumD;

  // Sum: '<S9>/Add1' incorporates:
  //   Inport: '<Root>/pitch'

  rtb_Add1 = DW.Merge1 - U.pitch;

  // Sum: '<S39>/SumD' incorporates:
  //   DiscreteIntegrator: '<S39>/Filter'

  rtb_SumD_i = rtb_Add1 - DW.Filter_DSTATE_e;

  // Outport: '<Root>/elevator' incorporates:
  //   DiscreteIntegrator: '<S44>/Integrator'
  //   Gain: '<S49>/Proportional Gain'
  //   Sum: '<S53>/Sum'

  Y.elevator = (2.0F * rtb_Add1 + DW.Integrator_DSTATE_f) + rtb_SumD_i;

  // Sum: '<S11>/Add' incorporates:
  //   Inport: '<Root>/airspeed'

  rtb_Add_p = DW.Merge2 - U.airspeed;

  // Sum: '<S137>/SumD' incorporates:
  //   DiscreteIntegrator: '<S137>/Filter'

  rtb_SumD_k = rtb_Add_p - DW.Filter_DSTATE_d;

  // Outport: '<Root>/throttle' incorporates:
  //   DiscreteIntegrator: '<S142>/Integrator'
  //   Gain: '<S147>/Proportional Gain'
  //   Sum: '<S151>/Sum'

  Y.throttle = (2.0F * rtb_Add_p + DW.Integrator_DSTATE_a) + rtb_SumD_k;

  // Outport: '<Root>/airspeed_obj'
  Y.airspeed_obj = DW.Merge2;

  // Outport: '<Root>/pitch_obj'
  Y.pitch_obj = DW.Merge1;

  // Outport: '<Root>/roll_obj'
  Y.roll_obj = DW.Merge;

  // Outport: '<Root>/rudder' incorporates:
  //   Inport: '<Root>/rudder_rc'

  Y.rudder = U.rudder_rc;

  // Update for DiscreteIntegrator: '<S93>/Integrator'
  DW.Integrator_DSTATE += 0.01F * rtb_Add;
  if (DW.Integrator_DSTATE > 1.0F) {
    DW.Integrator_DSTATE = 1.0F;
  } else if (DW.Integrator_DSTATE < -1.0F) {
    DW.Integrator_DSTATE = -1.0F;
  }

  // End of Update for DiscreteIntegrator: '<S93>/Integrator'

  // Update for DiscreteIntegrator: '<S88>/Filter'
  DW.Filter_DSTATE += 0.01F * rtb_SumD;

  // Update for DiscreteIntegrator: '<S44>/Integrator'
  DW.Integrator_DSTATE_f += 0.01F * rtb_Add1;
  if (DW.Integrator_DSTATE_f > 1.0F) {
    DW.Integrator_DSTATE_f = 1.0F;
  } else if (DW.Integrator_DSTATE_f < -1.0F) {
    DW.Integrator_DSTATE_f = -1.0F;
  }

  // End of Update for DiscreteIntegrator: '<S44>/Integrator'

  // Update for DiscreteIntegrator: '<S39>/Filter'
  DW.Filter_DSTATE_e += 0.01F * rtb_SumD_i;

  // Update for DiscreteIntegrator: '<S142>/Integrator'
  DW.Integrator_DSTATE_a += 0.01F * rtb_Add_p;
  if (DW.Integrator_DSTATE_a > 1.0F) {
    DW.Integrator_DSTATE_a = 1.0F;
  } else if (DW.Integrator_DSTATE_a < -1.0F) {
    DW.Integrator_DSTATE_a = -1.0F;
  }

  // End of Update for DiscreteIntegrator: '<S142>/Integrator'

  // Update for DiscreteIntegrator: '<S137>/Filter'
  DW.Filter_DSTATE_d += 0.01F * rtb_SumD_k;
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
const my_controller::DW_T &my_controller::getDWork() const
{
  return DW;
}

// Block states set method
void my_controller::setDWork(const my_controller::DW_T *pDW_T)
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
