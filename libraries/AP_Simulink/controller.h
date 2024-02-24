//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: controller.h
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
#ifndef RTW_HEADER_controller_h_
#define RTW_HEADER_controller_h_
#include <stdbool.h>
#include <stdint.h>
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
  // Block signals and states (default storage) for system '<Root>'
  struct DW_controller_T {
    float Merge;                       // '<S2>/Merge'
    float Merge1;                      // '<S2>/Merge1'
    float Merge2;                      // '<S2>/Merge2'
    float Integrator_DSTATE;           // '<S93>/Integrator'
    float Filter_DSTATE;               // '<S88>/Filter'
    float Integrator_DSTATE_f;         // '<S44>/Integrator'
    float Filter_DSTATE_e;             // '<S39>/Filter'
    float Integrator_DSTATE_a;         // '<S142>/Integrator'
    float Filter_DSTATE_d;             // '<S137>/Filter'
  };

  // External inputs (root inport signals with default storage)
  struct ExtU_controller_T {
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
  struct ExtY_controller_T {
    bool enable_p;                     // '<Root>/enable'
    float aileron;                     // '<Root>/aileron'
    float elevator;                    // '<Root>/elevator'
    float rudder;                      // '<Root>/rudder'
    float throttle;                    // '<Root>/throttle'
    float airspeed_obj;                // '<Root>/airspeed_obj'
    float pitch_obj;                   // '<Root>/pitch_obj'
    float roll_obj;                    // '<Root>/roll_obj'
  };

  // Real-time Model Data Structure
  struct RT_MODEL_controller_T {
    const char * volatile errorStatus;
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

  // Real-Time Model set method
  void setRTM(const RT_MODEL_controller_T *pcontroller_M);

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

  // Block states get method
  const DW_controller_T &getDWork() const;

  // Block states set method
  void setDWork(const DW_controller_T *pDW_controller_T);

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

  // Block states
  DW_controller_T controller_DW;

  // Real-Time Model
  RT_MODEL_controller_T controller_M;
};

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S7>/Gain' : Eliminated nontunable gain of 1
//  Block '<S38>/Derivative Gain' : Eliminated nontunable gain of 1
//  Block '<S41>/Integral Gain' : Eliminated nontunable gain of 1
//  Block '<S49>/Proportional Gain' : Eliminated nontunable gain of 1
//  Block '<S98>/Proportional Gain' : Eliminated nontunable gain of 1
//  Block '<S136>/Derivative Gain' : Eliminated nontunable gain of 1
//  Block '<S139>/Integral Gain' : Eliminated nontunable gain of 1
//  Block '<S147>/Proportional Gain' : Eliminated nontunable gain of 1


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
//  '<S1>'   : 'controller/Custom controller toggle'
//  '<S2>'   : 'controller/High level controller'
//  '<S3>'   : 'controller/Low level controller'
//  '<S4>'   : 'controller/High level controller/AUTO controller'
//  '<S5>'   : 'controller/High level controller/STABILIZE controller'
//  '<S6>'   : 'controller/High level controller/AUTO controller/Altitude controller'
//  '<S7>'   : 'controller/High level controller/AUTO controller/Bearing controller'
//  '<S8>'   : 'controller/High level controller/AUTO controller/Speed controller'
//  '<S9>'   : 'controller/Low level controller/Pitch controller'
//  '<S10>'  : 'controller/Low level controller/Roll controller'
//  '<S11>'  : 'controller/Low level controller/Throttle controller'
//  '<S12>'  : 'controller/Low level controller/Pitch controller/Discrete PID Controller1'
//  '<S13>'  : 'controller/Low level controller/Pitch controller/Discrete PID Controller1/Anti-windup'
//  '<S14>'  : 'controller/Low level controller/Pitch controller/Discrete PID Controller1/D Gain'
//  '<S15>'  : 'controller/Low level controller/Pitch controller/Discrete PID Controller1/Filter'
//  '<S16>'  : 'controller/Low level controller/Pitch controller/Discrete PID Controller1/Filter ICs'
//  '<S17>'  : 'controller/Low level controller/Pitch controller/Discrete PID Controller1/I Gain'
//  '<S18>'  : 'controller/Low level controller/Pitch controller/Discrete PID Controller1/Ideal P Gain'
//  '<S19>'  : 'controller/Low level controller/Pitch controller/Discrete PID Controller1/Ideal P Gain Fdbk'
//  '<S20>'  : 'controller/Low level controller/Pitch controller/Discrete PID Controller1/Integrator'
//  '<S21>'  : 'controller/Low level controller/Pitch controller/Discrete PID Controller1/Integrator ICs'
//  '<S22>'  : 'controller/Low level controller/Pitch controller/Discrete PID Controller1/N Copy'
//  '<S23>'  : 'controller/Low level controller/Pitch controller/Discrete PID Controller1/N Gain'
//  '<S24>'  : 'controller/Low level controller/Pitch controller/Discrete PID Controller1/P Copy'
//  '<S25>'  : 'controller/Low level controller/Pitch controller/Discrete PID Controller1/Parallel P Gain'
//  '<S26>'  : 'controller/Low level controller/Pitch controller/Discrete PID Controller1/Reset Signal'
//  '<S27>'  : 'controller/Low level controller/Pitch controller/Discrete PID Controller1/Saturation'
//  '<S28>'  : 'controller/Low level controller/Pitch controller/Discrete PID Controller1/Saturation Fdbk'
//  '<S29>'  : 'controller/Low level controller/Pitch controller/Discrete PID Controller1/Sum'
//  '<S30>'  : 'controller/Low level controller/Pitch controller/Discrete PID Controller1/Sum Fdbk'
//  '<S31>'  : 'controller/Low level controller/Pitch controller/Discrete PID Controller1/Tracking Mode'
//  '<S32>'  : 'controller/Low level controller/Pitch controller/Discrete PID Controller1/Tracking Mode Sum'
//  '<S33>'  : 'controller/Low level controller/Pitch controller/Discrete PID Controller1/Tsamp - Integral'
//  '<S34>'  : 'controller/Low level controller/Pitch controller/Discrete PID Controller1/Tsamp - Ngain'
//  '<S35>'  : 'controller/Low level controller/Pitch controller/Discrete PID Controller1/postSat Signal'
//  '<S36>'  : 'controller/Low level controller/Pitch controller/Discrete PID Controller1/preSat Signal'
//  '<S37>'  : 'controller/Low level controller/Pitch controller/Discrete PID Controller1/Anti-windup/Passthrough'
//  '<S38>'  : 'controller/Low level controller/Pitch controller/Discrete PID Controller1/D Gain/Internal Parameters'
//  '<S39>'  : 'controller/Low level controller/Pitch controller/Discrete PID Controller1/Filter/Disc. Forward Euler Filter'
//  '<S40>'  : 'controller/Low level controller/Pitch controller/Discrete PID Controller1/Filter ICs/Internal IC - Filter'
//  '<S41>'  : 'controller/Low level controller/Pitch controller/Discrete PID Controller1/I Gain/Internal Parameters'
//  '<S42>'  : 'controller/Low level controller/Pitch controller/Discrete PID Controller1/Ideal P Gain/Passthrough'
//  '<S43>'  : 'controller/Low level controller/Pitch controller/Discrete PID Controller1/Ideal P Gain Fdbk/Disabled'
//  '<S44>'  : 'controller/Low level controller/Pitch controller/Discrete PID Controller1/Integrator/Discrete'
//  '<S45>'  : 'controller/Low level controller/Pitch controller/Discrete PID Controller1/Integrator ICs/Internal IC'
//  '<S46>'  : 'controller/Low level controller/Pitch controller/Discrete PID Controller1/N Copy/Disabled'
//  '<S47>'  : 'controller/Low level controller/Pitch controller/Discrete PID Controller1/N Gain/Internal Parameters'
//  '<S48>'  : 'controller/Low level controller/Pitch controller/Discrete PID Controller1/P Copy/Disabled'
//  '<S49>'  : 'controller/Low level controller/Pitch controller/Discrete PID Controller1/Parallel P Gain/Internal Parameters'
//  '<S50>'  : 'controller/Low level controller/Pitch controller/Discrete PID Controller1/Reset Signal/Disabled'
//  '<S51>'  : 'controller/Low level controller/Pitch controller/Discrete PID Controller1/Saturation/Passthrough'
//  '<S52>'  : 'controller/Low level controller/Pitch controller/Discrete PID Controller1/Saturation Fdbk/Disabled'
//  '<S53>'  : 'controller/Low level controller/Pitch controller/Discrete PID Controller1/Sum/Sum_PID'
//  '<S54>'  : 'controller/Low level controller/Pitch controller/Discrete PID Controller1/Sum Fdbk/Disabled'
//  '<S55>'  : 'controller/Low level controller/Pitch controller/Discrete PID Controller1/Tracking Mode/Disabled'
//  '<S56>'  : 'controller/Low level controller/Pitch controller/Discrete PID Controller1/Tracking Mode Sum/Passthrough'
//  '<S57>'  : 'controller/Low level controller/Pitch controller/Discrete PID Controller1/Tsamp - Integral/TsSignalSpecification'
//  '<S58>'  : 'controller/Low level controller/Pitch controller/Discrete PID Controller1/Tsamp - Ngain/Passthrough'
//  '<S59>'  : 'controller/Low level controller/Pitch controller/Discrete PID Controller1/postSat Signal/Forward_Path'
//  '<S60>'  : 'controller/Low level controller/Pitch controller/Discrete PID Controller1/preSat Signal/Forward_Path'
//  '<S61>'  : 'controller/Low level controller/Roll controller/Discrete PID Controller'
//  '<S62>'  : 'controller/Low level controller/Roll controller/Discrete PID Controller/Anti-windup'
//  '<S63>'  : 'controller/Low level controller/Roll controller/Discrete PID Controller/D Gain'
//  '<S64>'  : 'controller/Low level controller/Roll controller/Discrete PID Controller/Filter'
//  '<S65>'  : 'controller/Low level controller/Roll controller/Discrete PID Controller/Filter ICs'
//  '<S66>'  : 'controller/Low level controller/Roll controller/Discrete PID Controller/I Gain'
//  '<S67>'  : 'controller/Low level controller/Roll controller/Discrete PID Controller/Ideal P Gain'
//  '<S68>'  : 'controller/Low level controller/Roll controller/Discrete PID Controller/Ideal P Gain Fdbk'
//  '<S69>'  : 'controller/Low level controller/Roll controller/Discrete PID Controller/Integrator'
//  '<S70>'  : 'controller/Low level controller/Roll controller/Discrete PID Controller/Integrator ICs'
//  '<S71>'  : 'controller/Low level controller/Roll controller/Discrete PID Controller/N Copy'
//  '<S72>'  : 'controller/Low level controller/Roll controller/Discrete PID Controller/N Gain'
//  '<S73>'  : 'controller/Low level controller/Roll controller/Discrete PID Controller/P Copy'
//  '<S74>'  : 'controller/Low level controller/Roll controller/Discrete PID Controller/Parallel P Gain'
//  '<S75>'  : 'controller/Low level controller/Roll controller/Discrete PID Controller/Reset Signal'
//  '<S76>'  : 'controller/Low level controller/Roll controller/Discrete PID Controller/Saturation'
//  '<S77>'  : 'controller/Low level controller/Roll controller/Discrete PID Controller/Saturation Fdbk'
//  '<S78>'  : 'controller/Low level controller/Roll controller/Discrete PID Controller/Sum'
//  '<S79>'  : 'controller/Low level controller/Roll controller/Discrete PID Controller/Sum Fdbk'
//  '<S80>'  : 'controller/Low level controller/Roll controller/Discrete PID Controller/Tracking Mode'
//  '<S81>'  : 'controller/Low level controller/Roll controller/Discrete PID Controller/Tracking Mode Sum'
//  '<S82>'  : 'controller/Low level controller/Roll controller/Discrete PID Controller/Tsamp - Integral'
//  '<S83>'  : 'controller/Low level controller/Roll controller/Discrete PID Controller/Tsamp - Ngain'
//  '<S84>'  : 'controller/Low level controller/Roll controller/Discrete PID Controller/postSat Signal'
//  '<S85>'  : 'controller/Low level controller/Roll controller/Discrete PID Controller/preSat Signal'
//  '<S86>'  : 'controller/Low level controller/Roll controller/Discrete PID Controller/Anti-windup/Passthrough'
//  '<S87>'  : 'controller/Low level controller/Roll controller/Discrete PID Controller/D Gain/Internal Parameters'
//  '<S88>'  : 'controller/Low level controller/Roll controller/Discrete PID Controller/Filter/Disc. Forward Euler Filter'
//  '<S89>'  : 'controller/Low level controller/Roll controller/Discrete PID Controller/Filter ICs/Internal IC - Filter'
//  '<S90>'  : 'controller/Low level controller/Roll controller/Discrete PID Controller/I Gain/Internal Parameters'
//  '<S91>'  : 'controller/Low level controller/Roll controller/Discrete PID Controller/Ideal P Gain/Passthrough'
//  '<S92>'  : 'controller/Low level controller/Roll controller/Discrete PID Controller/Ideal P Gain Fdbk/Disabled'
//  '<S93>'  : 'controller/Low level controller/Roll controller/Discrete PID Controller/Integrator/Discrete'
//  '<S94>'  : 'controller/Low level controller/Roll controller/Discrete PID Controller/Integrator ICs/Internal IC'
//  '<S95>'  : 'controller/Low level controller/Roll controller/Discrete PID Controller/N Copy/Disabled'
//  '<S96>'  : 'controller/Low level controller/Roll controller/Discrete PID Controller/N Gain/Internal Parameters'
//  '<S97>'  : 'controller/Low level controller/Roll controller/Discrete PID Controller/P Copy/Disabled'
//  '<S98>'  : 'controller/Low level controller/Roll controller/Discrete PID Controller/Parallel P Gain/Internal Parameters'
//  '<S99>'  : 'controller/Low level controller/Roll controller/Discrete PID Controller/Reset Signal/Disabled'
//  '<S100>' : 'controller/Low level controller/Roll controller/Discrete PID Controller/Saturation/Passthrough'
//  '<S101>' : 'controller/Low level controller/Roll controller/Discrete PID Controller/Saturation Fdbk/Disabled'
//  '<S102>' : 'controller/Low level controller/Roll controller/Discrete PID Controller/Sum/Sum_PID'
//  '<S103>' : 'controller/Low level controller/Roll controller/Discrete PID Controller/Sum Fdbk/Disabled'
//  '<S104>' : 'controller/Low level controller/Roll controller/Discrete PID Controller/Tracking Mode/Disabled'
//  '<S105>' : 'controller/Low level controller/Roll controller/Discrete PID Controller/Tracking Mode Sum/Passthrough'
//  '<S106>' : 'controller/Low level controller/Roll controller/Discrete PID Controller/Tsamp - Integral/TsSignalSpecification'
//  '<S107>' : 'controller/Low level controller/Roll controller/Discrete PID Controller/Tsamp - Ngain/Passthrough'
//  '<S108>' : 'controller/Low level controller/Roll controller/Discrete PID Controller/postSat Signal/Forward_Path'
//  '<S109>' : 'controller/Low level controller/Roll controller/Discrete PID Controller/preSat Signal/Forward_Path'
//  '<S110>' : 'controller/Low level controller/Throttle controller/PID Controller'
//  '<S111>' : 'controller/Low level controller/Throttle controller/PID Controller/Anti-windup'
//  '<S112>' : 'controller/Low level controller/Throttle controller/PID Controller/D Gain'
//  '<S113>' : 'controller/Low level controller/Throttle controller/PID Controller/Filter'
//  '<S114>' : 'controller/Low level controller/Throttle controller/PID Controller/Filter ICs'
//  '<S115>' : 'controller/Low level controller/Throttle controller/PID Controller/I Gain'
//  '<S116>' : 'controller/Low level controller/Throttle controller/PID Controller/Ideal P Gain'
//  '<S117>' : 'controller/Low level controller/Throttle controller/PID Controller/Ideal P Gain Fdbk'
//  '<S118>' : 'controller/Low level controller/Throttle controller/PID Controller/Integrator'
//  '<S119>' : 'controller/Low level controller/Throttle controller/PID Controller/Integrator ICs'
//  '<S120>' : 'controller/Low level controller/Throttle controller/PID Controller/N Copy'
//  '<S121>' : 'controller/Low level controller/Throttle controller/PID Controller/N Gain'
//  '<S122>' : 'controller/Low level controller/Throttle controller/PID Controller/P Copy'
//  '<S123>' : 'controller/Low level controller/Throttle controller/PID Controller/Parallel P Gain'
//  '<S124>' : 'controller/Low level controller/Throttle controller/PID Controller/Reset Signal'
//  '<S125>' : 'controller/Low level controller/Throttle controller/PID Controller/Saturation'
//  '<S126>' : 'controller/Low level controller/Throttle controller/PID Controller/Saturation Fdbk'
//  '<S127>' : 'controller/Low level controller/Throttle controller/PID Controller/Sum'
//  '<S128>' : 'controller/Low level controller/Throttle controller/PID Controller/Sum Fdbk'
//  '<S129>' : 'controller/Low level controller/Throttle controller/PID Controller/Tracking Mode'
//  '<S130>' : 'controller/Low level controller/Throttle controller/PID Controller/Tracking Mode Sum'
//  '<S131>' : 'controller/Low level controller/Throttle controller/PID Controller/Tsamp - Integral'
//  '<S132>' : 'controller/Low level controller/Throttle controller/PID Controller/Tsamp - Ngain'
//  '<S133>' : 'controller/Low level controller/Throttle controller/PID Controller/postSat Signal'
//  '<S134>' : 'controller/Low level controller/Throttle controller/PID Controller/preSat Signal'
//  '<S135>' : 'controller/Low level controller/Throttle controller/PID Controller/Anti-windup/Passthrough'
//  '<S136>' : 'controller/Low level controller/Throttle controller/PID Controller/D Gain/Internal Parameters'
//  '<S137>' : 'controller/Low level controller/Throttle controller/PID Controller/Filter/Disc. Forward Euler Filter'
//  '<S138>' : 'controller/Low level controller/Throttle controller/PID Controller/Filter ICs/Internal IC - Filter'
//  '<S139>' : 'controller/Low level controller/Throttle controller/PID Controller/I Gain/Internal Parameters'
//  '<S140>' : 'controller/Low level controller/Throttle controller/PID Controller/Ideal P Gain/Passthrough'
//  '<S141>' : 'controller/Low level controller/Throttle controller/PID Controller/Ideal P Gain Fdbk/Disabled'
//  '<S142>' : 'controller/Low level controller/Throttle controller/PID Controller/Integrator/Discrete'
//  '<S143>' : 'controller/Low level controller/Throttle controller/PID Controller/Integrator ICs/Internal IC'
//  '<S144>' : 'controller/Low level controller/Throttle controller/PID Controller/N Copy/Disabled'
//  '<S145>' : 'controller/Low level controller/Throttle controller/PID Controller/N Gain/Internal Parameters'
//  '<S146>' : 'controller/Low level controller/Throttle controller/PID Controller/P Copy/Disabled'
//  '<S147>' : 'controller/Low level controller/Throttle controller/PID Controller/Parallel P Gain/Internal Parameters'
//  '<S148>' : 'controller/Low level controller/Throttle controller/PID Controller/Reset Signal/Disabled'
//  '<S149>' : 'controller/Low level controller/Throttle controller/PID Controller/Saturation/Passthrough'
//  '<S150>' : 'controller/Low level controller/Throttle controller/PID Controller/Saturation Fdbk/Disabled'
//  '<S151>' : 'controller/Low level controller/Throttle controller/PID Controller/Sum/Sum_PID'
//  '<S152>' : 'controller/Low level controller/Throttle controller/PID Controller/Sum Fdbk/Disabled'
//  '<S153>' : 'controller/Low level controller/Throttle controller/PID Controller/Tracking Mode/Disabled'
//  '<S154>' : 'controller/Low level controller/Throttle controller/PID Controller/Tracking Mode Sum/Passthrough'
//  '<S155>' : 'controller/Low level controller/Throttle controller/PID Controller/Tsamp - Integral/TsSignalSpecification'
//  '<S156>' : 'controller/Low level controller/Throttle controller/PID Controller/Tsamp - Ngain/Passthrough'
//  '<S157>' : 'controller/Low level controller/Throttle controller/PID Controller/postSat Signal/Forward_Path'
//  '<S158>' : 'controller/Low level controller/Throttle controller/PID Controller/preSat Signal/Forward_Path'

#endif                                 // RTW_HEADER_controller_h_

//
// File trailer for generated code.
//
// [EOF]
//
