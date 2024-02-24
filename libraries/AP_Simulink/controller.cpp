//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: controller.cpp
//
// Code generated for Simulink model 'controller'.
//
// Model version                  : 1.126
// Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
// C/C++ source code generated on : Sat Feb 24 03:52:12 2024
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
  float rtb_Add;
  float rtb_Add1;
  float rtb_FilterCoefficient;
  float rtb_FilterCoefficient_d;
  float rtb_FilterCoefficient_o;
  float rtb_Integrator_l;

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

  controller_Y.enable_p = (controller_U.enable_rc && (((controller_U.command_nav
    == 16.0F) && (controller_U.control_mode == 10.0F)) ||
    (controller_U.control_mode == 2.0F)));

  // Outputs for Enabled SubSystem: '<S2>/AUTO controller' incorporates:
  //   EnablePort: '<S4>/Enable'

  // RelationalOperator: '<S2>/Relational Operator' incorporates:
  //   Constant: '<S2>/AUTO'
  //   Inport: '<Root>/control_mode'

  if (controller_U.control_mode == 10.0F) {
    // Merge: '<S2>/Merge2' incorporates:
    //   Constant: '<S8>/Constant'
    //   SignalConversion generated from: '<S4>/airspeed_obj'

    controller_DW.Merge2 = 65.0F;

    // Gain: '<S6>/Gain' incorporates:
    //   Inport: '<Root>/altitude'
    //   Inport: '<Root>/altitude_nav'
    //   Sum: '<S6>/Add'

    controller_DW.Merge1 = (controller_U.altitude_nav - controller_U.altitude) *
      0.025F;

    // Saturate: '<S6>/Saturation'
    if (controller_DW.Merge1 > 0.52359879F) {
      // Gain: '<S6>/Gain' incorporates:
      //   Merge: '<S2>/Merge1'

      controller_DW.Merge1 = 0.52359879F;
    } else if (controller_DW.Merge1 < -0.52359879F) {
      // Gain: '<S6>/Gain' incorporates:
      //   Merge: '<S2>/Merge1'

      controller_DW.Merge1 = -0.52359879F;
    }

    // End of Saturate: '<S6>/Saturation'

    // Saturate: '<S7>/Saturation' incorporates:
    //   Inport: '<Root>/yaw_error'

    if (controller_U.yaw_error > 0.52359879F) {
      // Merge: '<S2>/Merge'
      controller_DW.Merge = 0.52359879F;
    } else if (controller_U.yaw_error < -0.52359879F) {
      // Merge: '<S2>/Merge'
      controller_DW.Merge = -0.52359879F;
    } else {
      // Merge: '<S2>/Merge'
      controller_DW.Merge = controller_U.yaw_error;
    }

    // End of Saturate: '<S7>/Saturation'
  }

  // End of RelationalOperator: '<S2>/Relational Operator'
  // End of Outputs for SubSystem: '<S2>/AUTO controller'

  // Outputs for Enabled SubSystem: '<S2>/STABILIZE controller' incorporates:
  //   EnablePort: '<S5>/Enable'

  // RelationalOperator: '<S2>/Relational Operator1' incorporates:
  //   Constant: '<S2>/STABILIZE'
  //   Inport: '<Root>/control_mode'

  if (controller_U.control_mode == 2.0F) {
    // Merge: '<S2>/Merge' incorporates:
    //   Gain: '<S5>/Gain'
    //   Inport: '<Root>/aileron_rc'

    controller_DW.Merge = 0.5F * controller_U.aileron_rc;

    // Gain: '<S6>/Gain' incorporates:
    //   Gain: '<S5>/Gain1'
    //   Inport: '<Root>/elevator_rc'
    //   Merge: '<S2>/Merge1'

    controller_DW.Merge1 = 0.5F * controller_U.elevator_rc;

    // Merge: '<S2>/Merge2' incorporates:
    //   Gain: '<S5>/Gain2'
    //   Inport: '<Root>/throttle_rc'

    controller_DW.Merge2 = controller_U.throttle_rc;
  }

  // End of RelationalOperator: '<S2>/Relational Operator1'
  // End of Outputs for SubSystem: '<S2>/STABILIZE controller'

  // Sum: '<S10>/Add' incorporates:
  //   Inport: '<Root>/roll'

  rtb_Integrator_l = controller_DW.Merge - controller_U.roll;

  // Gain: '<S96>/Filter Coefficient' incorporates:
  //   DiscreteIntegrator: '<S88>/Filter'
  //   Gain: '<S87>/Derivative Gain'
  //   Sum: '<S88>/SumD'

  rtb_FilterCoefficient = (0.0F * rtb_Integrator_l - controller_DW.Filter_DSTATE)
    * 100.0F;

  // Outport: '<Root>/aileron' incorporates:
  //   DiscreteIntegrator: '<S93>/Integrator'
  //   Sum: '<S102>/Sum'

  controller_Y.aileron = (rtb_Integrator_l + controller_DW.Integrator_DSTATE) +
    rtb_FilterCoefficient;

  // Sum: '<S9>/Add1' incorporates:
  //   Inport: '<Root>/pitch'

  rtb_Add1 = controller_DW.Merge1 - controller_U.pitch;

  // Gain: '<S47>/Filter Coefficient' incorporates:
  //   DiscreteIntegrator: '<S39>/Filter'
  //   Sum: '<S39>/SumD'

  rtb_FilterCoefficient_d = (rtb_Add1 - controller_DW.Filter_DSTATE_e) * 100.0F;

  // Outport: '<Root>/elevator' incorporates:
  //   DiscreteIntegrator: '<S44>/Integrator'
  //   Sum: '<S53>/Sum'

  controller_Y.elevator = (rtb_Add1 + controller_DW.Integrator_DSTATE_f) +
    rtb_FilterCoefficient_d;

  // Sum: '<S11>/Add' incorporates:
  //   Inport: '<Root>/airspeed'

  rtb_Add = controller_DW.Merge2 - controller_U.airspeed;

  // Gain: '<S145>/Filter Coefficient' incorporates:
  //   DiscreteIntegrator: '<S137>/Filter'
  //   Sum: '<S137>/SumD'

  rtb_FilterCoefficient_o = (rtb_Add - controller_DW.Filter_DSTATE_d) * 100.0F;

  // Outport: '<Root>/throttle' incorporates:
  //   DiscreteIntegrator: '<S142>/Integrator'
  //   Sum: '<S151>/Sum'

  controller_Y.throttle = (rtb_Add + controller_DW.Integrator_DSTATE_a) +
    rtb_FilterCoefficient_o;

  // Outport: '<Root>/airspeed_obj'
  controller_Y.airspeed_obj = controller_DW.Merge2;

  // Outport: '<Root>/pitch_obj'
  controller_Y.pitch_obj = controller_DW.Merge1;

  // Outport: '<Root>/roll_obj'
  controller_Y.roll_obj = controller_DW.Merge;

  // Update for DiscreteIntegrator: '<S93>/Integrator' incorporates:
  //   Gain: '<S90>/Integral Gain'

  controller_DW.Integrator_DSTATE += 0.0F * rtb_Integrator_l * 0.01F;

  // Update for DiscreteIntegrator: '<S88>/Filter'
  controller_DW.Filter_DSTATE += 0.01F * rtb_FilterCoefficient;

  // Update for DiscreteIntegrator: '<S44>/Integrator'
  controller_DW.Integrator_DSTATE_f += 0.01F * rtb_Add1;

  // Update for DiscreteIntegrator: '<S39>/Filter'
  controller_DW.Filter_DSTATE_e += 0.01F * rtb_FilterCoefficient_d;

  // Update for DiscreteIntegrator: '<S142>/Integrator'
  controller_DW.Integrator_DSTATE_a += 0.01F * rtb_Add;

  // Update for DiscreteIntegrator: '<S137>/Filter'
  controller_DW.Filter_DSTATE_d += 0.01F * rtb_FilterCoefficient_o;
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
