//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: passthrough.h
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
#ifndef RTW_HEADER_passthrough_h_
#define RTW_HEADER_passthrough_h_
#include <stdbool.h>
#include <stdint.h>

// Class declaration for model passthrough
class passthrough final
{
  // public data and function members
 public:
  // Block signals and states (default storage) for system '<Root>'
  struct DW_T {
    float DiscreteTimeIntegrator_DSTATE;// '<Root>/Discrete-Time Integrator'
  };

  // External inputs (root inport signals with default storage)
  struct ExtU_T {
    float control_mode;                // '<Root>/control_mode'
    float command_nav;                 // '<Root>/command_nav'
    float roll;                        // '<Root>/roll'
    float pitch;                       // '<Root>/pitch'
    float yaw;                         // '<Root>/yaw'
    float altitude;                    // '<Root>/altitude'
    float airspeed;                    // '<Root>/airspeed'
    float yaw_nav;                     // '<Root>/yaw_nav'
    float yaw_error;                   // '<Root>/yaw_error'
    float altitude_nav;                // '<Root>/altitude_nav'
    float aileron_rc;                  // '<Root>/aileron_rc'
    float elevator_rc;                 // '<Root>/elevator_rc'
    float rudder_rc;                   // '<Root>/rudder_rc'
    float throttle_rc;                 // '<Root>/throttle_rc'
    bool enable_rc;                    // '<Root>/enable_rc'
    float roll_L1;                     // '<Root>/roll_L1'
    float pitch_TECS;                  // '<Root>/pitch_TECS'
    float airspeed_TECS;               // '<Root>/airspeed_TECS'
  };

  // External outputs (root outports fed by signals with default storage)
  struct ExtY_T {
    bool enable_p;                     // '<Root>/enable'
    float aileron;                     // '<Root>/aileron'
    float elevator;                    // '<Root>/elevator'
    float rudder;                      // '<Root>/rudder'
    float throttle;                    // '<Root>/throttle'
    float roll_obj;                    // '<Root>/roll_obj'
    float pitch_obj;                   // '<Root>/pitch_obj'
    float airspeed_obj;                // '<Root>/airspeed_obj'
    float debug;                       // '<Root>/debug'
  };

  // Copy Constructor
  passthrough(passthrough const&) = delete;

  // Assignment Operator
  passthrough& operator= (passthrough const&) & = delete;

  // Move Constructor
  passthrough(passthrough &&) = delete;

  // Move Assignment Operator
  passthrough& operator= (passthrough &&) = delete;

  // Root inports set method
  void setExternalInputs(const ExtU_T *pExtU_T)
  {
    U = *pExtU_T;
  }

  // Root outports get method
  const ExtY_T &getExternalOutputs() const
  {
    return Y;
  }

  // Block states get method
  const DW_T &getDWork() const;

  // Block states set method
  void setDWork(const DW_T *pDW_T);

  // model initialize function
  static void initialize();

  // model step function
  void step();

  // model terminate function
  static void terminate();

  // Constructor
  passthrough();

  // private data and function members
 private:
  // External inputs
  ExtU_T U;

  // External outputs
  ExtY_T Y;

  // Block states
  DW_T DW;
};

//-
//  The generated code includes comments that allow you to trace directly
//  back to the appropriate location in the model.  The basic format
//  is <system>/block_name, where system is the system number (uniquely
//  assigned by Simulink) and block_name is the name of the block.
//
//  Use the MATLAB hilite_system command to trace the generated code back
//  to the model.  For example,
//
//  hilite_system('<S3>')    - opens system 3
//  hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'passthrough'

#endif                                 // RTW_HEADER_passthrough_h_

//
// File trailer for generated code.
//
// [EOF]
//
