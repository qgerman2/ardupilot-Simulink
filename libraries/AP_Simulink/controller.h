//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: controller.h
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
#ifndef RTW_HEADER_controller_h_
#define RTW_HEADER_controller_h_
#include "rtwtypes.h"
#include "controller_types.h"

// Macros for accessing real-time model data structure
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

// Class declaration for model controller
class controller final
{
  // public data and function members
 public:
  // External inputs (root inport signals with default storage)
  struct ExtU_controller_T {
    real32_T entrada;                  // '<Root>/entrada'
  };

  // External outputs (root outports fed by signals with default storage)
  struct ExtY_controller_T {
    real32_T salida;                   // '<Root>/salida'
  };

  // Real-time Model Data Structure
  struct RT_MODEL_controller_T {
    const char_T * volatile errorStatus;
  };

  // Copy Constructor
  controller(controller const&) = delete;

  // Assignment Operator
  controller& operator= (controller const&) & = delete;

  // Move Constructor
  controller(controller &&) = delete;

  // Move Assignment Operator
  controller& operator= (controller &&) = delete;

  // Real-Time Model get method
  controller::RT_MODEL_controller_T * getRTM();

  // Root inports set method
  void setExternalInputs(const ExtU_controller_T *pExtU_controller_T)
  {
    controller_U = *pExtU_controller_T;
  }

  // Root outports get method
  const ExtY_controller_T &getExternalOutputs() const
  {
    return controller_Y;
  }

  // model initialize function
  static void initialize();

  // model step function
  void step();

  // model terminate function
  static void terminate();

  // Constructor
  controller();

  // Destructor
  ~controller();

  // private data and function members
 private:
  // External inputs
  ExtU_controller_T controller_U;

  // External outputs
  ExtY_controller_T controller_Y;

  // Real-Time Model
  RT_MODEL_controller_T controller_M;
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
//  '<Root>' : 'controller'

#endif                                 // RTW_HEADER_controller_h_

//
// File trailer for generated code.
//
// [EOF]
//
