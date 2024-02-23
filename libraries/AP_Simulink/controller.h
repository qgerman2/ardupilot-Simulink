//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: controller.h
//
// Code generated for Simulink model 'controller'.
//
// Model version                  : 1.49
// Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
// C/C++ source code generated on : Fri Feb 23 15:40:00 2024
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
    float Filter_DSTATE;               // '<S129>/Filter'
    float Integrator_DSTATE;           // '<S134>/Integrator'
    float Integrator_DSTATE_i;         // '<S36>/Integrator'
    float Filter_DSTATE_p;             // '<S31>/Filter'
    float Integrator_DSTATE_e;         // '<S85>/Integrator'
    float Filter_DSTATE_o;             // '<S80>/Filter'
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
    float roll_L1;                     // '<Root>/roll_L1'
    float pitch_TECS;                  // '<Root>/pitch_TECS'
    float throttle_TECS;               // '<Root>/throttle_TECS'
    float aileron_rc;                  // '<Root>/aileron_rc'
    float elevator_rc;                 // '<Root>/elevator_rc'
    float rudder_rc;                   // '<Root>/rudder_rc'
    float throttle_rc;                 // '<Root>/throttle_rc'
  };

  // External outputs (root outports fed by signals with default storage)
  struct ExtY_controller_T {
    float aileron;                     // '<Root>/aileron'
    float elevator;                    // '<Root>/elevator'
    float rudder;                      // '<Root>/rudder'
    float throttle;                    // '<Root>/throttle'
    float debug[4];                    // '<Root>/debug'
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
//  Block '<S139>/Proportional Gain' : Eliminated nontunable gain of 1


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
//  '<S1>'   : 'controller/airspeed PID'
//  '<S2>'   : 'controller/altitude PID'
//  '<S3>'   : 'controller/bearing PID'
//  '<S4>'   : 'controller/airspeed PID/PID Controller'
//  '<S5>'   : 'controller/airspeed PID/PID Controller/Anti-windup'
//  '<S6>'   : 'controller/airspeed PID/PID Controller/D Gain'
//  '<S7>'   : 'controller/airspeed PID/PID Controller/Filter'
//  '<S8>'   : 'controller/airspeed PID/PID Controller/Filter ICs'
//  '<S9>'   : 'controller/airspeed PID/PID Controller/I Gain'
//  '<S10>'  : 'controller/airspeed PID/PID Controller/Ideal P Gain'
//  '<S11>'  : 'controller/airspeed PID/PID Controller/Ideal P Gain Fdbk'
//  '<S12>'  : 'controller/airspeed PID/PID Controller/Integrator'
//  '<S13>'  : 'controller/airspeed PID/PID Controller/Integrator ICs'
//  '<S14>'  : 'controller/airspeed PID/PID Controller/N Copy'
//  '<S15>'  : 'controller/airspeed PID/PID Controller/N Gain'
//  '<S16>'  : 'controller/airspeed PID/PID Controller/P Copy'
//  '<S17>'  : 'controller/airspeed PID/PID Controller/Parallel P Gain'
//  '<S18>'  : 'controller/airspeed PID/PID Controller/Reset Signal'
//  '<S19>'  : 'controller/airspeed PID/PID Controller/Saturation'
//  '<S20>'  : 'controller/airspeed PID/PID Controller/Saturation Fdbk'
//  '<S21>'  : 'controller/airspeed PID/PID Controller/Sum'
//  '<S22>'  : 'controller/airspeed PID/PID Controller/Sum Fdbk'
//  '<S23>'  : 'controller/airspeed PID/PID Controller/Tracking Mode'
//  '<S24>'  : 'controller/airspeed PID/PID Controller/Tracking Mode Sum'
//  '<S25>'  : 'controller/airspeed PID/PID Controller/Tsamp - Integral'
//  '<S26>'  : 'controller/airspeed PID/PID Controller/Tsamp - Ngain'
//  '<S27>'  : 'controller/airspeed PID/PID Controller/postSat Signal'
//  '<S28>'  : 'controller/airspeed PID/PID Controller/preSat Signal'
//  '<S29>'  : 'controller/airspeed PID/PID Controller/Anti-windup/Passthrough'
//  '<S30>'  : 'controller/airspeed PID/PID Controller/D Gain/Internal Parameters'
//  '<S31>'  : 'controller/airspeed PID/PID Controller/Filter/Disc. Forward Euler Filter'
//  '<S32>'  : 'controller/airspeed PID/PID Controller/Filter ICs/Internal IC - Filter'
//  '<S33>'  : 'controller/airspeed PID/PID Controller/I Gain/Internal Parameters'
//  '<S34>'  : 'controller/airspeed PID/PID Controller/Ideal P Gain/Passthrough'
//  '<S35>'  : 'controller/airspeed PID/PID Controller/Ideal P Gain Fdbk/Disabled'
//  '<S36>'  : 'controller/airspeed PID/PID Controller/Integrator/Discrete'
//  '<S37>'  : 'controller/airspeed PID/PID Controller/Integrator ICs/Internal IC'
//  '<S38>'  : 'controller/airspeed PID/PID Controller/N Copy/Disabled'
//  '<S39>'  : 'controller/airspeed PID/PID Controller/N Gain/Internal Parameters'
//  '<S40>'  : 'controller/airspeed PID/PID Controller/P Copy/Disabled'
//  '<S41>'  : 'controller/airspeed PID/PID Controller/Parallel P Gain/Internal Parameters'
//  '<S42>'  : 'controller/airspeed PID/PID Controller/Reset Signal/Disabled'
//  '<S43>'  : 'controller/airspeed PID/PID Controller/Saturation/Enabled'
//  '<S44>'  : 'controller/airspeed PID/PID Controller/Saturation Fdbk/Disabled'
//  '<S45>'  : 'controller/airspeed PID/PID Controller/Sum/Sum_PID'
//  '<S46>'  : 'controller/airspeed PID/PID Controller/Sum Fdbk/Disabled'
//  '<S47>'  : 'controller/airspeed PID/PID Controller/Tracking Mode/Disabled'
//  '<S48>'  : 'controller/airspeed PID/PID Controller/Tracking Mode Sum/Passthrough'
//  '<S49>'  : 'controller/airspeed PID/PID Controller/Tsamp - Integral/TsSignalSpecification'
//  '<S50>'  : 'controller/airspeed PID/PID Controller/Tsamp - Ngain/Passthrough'
//  '<S51>'  : 'controller/airspeed PID/PID Controller/postSat Signal/Forward_Path'
//  '<S52>'  : 'controller/airspeed PID/PID Controller/preSat Signal/Forward_Path'
//  '<S53>'  : 'controller/altitude PID/PID Controller'
//  '<S54>'  : 'controller/altitude PID/PID Controller/Anti-windup'
//  '<S55>'  : 'controller/altitude PID/PID Controller/D Gain'
//  '<S56>'  : 'controller/altitude PID/PID Controller/Filter'
//  '<S57>'  : 'controller/altitude PID/PID Controller/Filter ICs'
//  '<S58>'  : 'controller/altitude PID/PID Controller/I Gain'
//  '<S59>'  : 'controller/altitude PID/PID Controller/Ideal P Gain'
//  '<S60>'  : 'controller/altitude PID/PID Controller/Ideal P Gain Fdbk'
//  '<S61>'  : 'controller/altitude PID/PID Controller/Integrator'
//  '<S62>'  : 'controller/altitude PID/PID Controller/Integrator ICs'
//  '<S63>'  : 'controller/altitude PID/PID Controller/N Copy'
//  '<S64>'  : 'controller/altitude PID/PID Controller/N Gain'
//  '<S65>'  : 'controller/altitude PID/PID Controller/P Copy'
//  '<S66>'  : 'controller/altitude PID/PID Controller/Parallel P Gain'
//  '<S67>'  : 'controller/altitude PID/PID Controller/Reset Signal'
//  '<S68>'  : 'controller/altitude PID/PID Controller/Saturation'
//  '<S69>'  : 'controller/altitude PID/PID Controller/Saturation Fdbk'
//  '<S70>'  : 'controller/altitude PID/PID Controller/Sum'
//  '<S71>'  : 'controller/altitude PID/PID Controller/Sum Fdbk'
//  '<S72>'  : 'controller/altitude PID/PID Controller/Tracking Mode'
//  '<S73>'  : 'controller/altitude PID/PID Controller/Tracking Mode Sum'
//  '<S74>'  : 'controller/altitude PID/PID Controller/Tsamp - Integral'
//  '<S75>'  : 'controller/altitude PID/PID Controller/Tsamp - Ngain'
//  '<S76>'  : 'controller/altitude PID/PID Controller/postSat Signal'
//  '<S77>'  : 'controller/altitude PID/PID Controller/preSat Signal'
//  '<S78>'  : 'controller/altitude PID/PID Controller/Anti-windup/Passthrough'
//  '<S79>'  : 'controller/altitude PID/PID Controller/D Gain/Internal Parameters'
//  '<S80>'  : 'controller/altitude PID/PID Controller/Filter/Disc. Forward Euler Filter'
//  '<S81>'  : 'controller/altitude PID/PID Controller/Filter ICs/Internal IC - Filter'
//  '<S82>'  : 'controller/altitude PID/PID Controller/I Gain/Internal Parameters'
//  '<S83>'  : 'controller/altitude PID/PID Controller/Ideal P Gain/Passthrough'
//  '<S84>'  : 'controller/altitude PID/PID Controller/Ideal P Gain Fdbk/Disabled'
//  '<S85>'  : 'controller/altitude PID/PID Controller/Integrator/Discrete'
//  '<S86>'  : 'controller/altitude PID/PID Controller/Integrator ICs/Internal IC'
//  '<S87>'  : 'controller/altitude PID/PID Controller/N Copy/Disabled'
//  '<S88>'  : 'controller/altitude PID/PID Controller/N Gain/Internal Parameters'
//  '<S89>'  : 'controller/altitude PID/PID Controller/P Copy/Disabled'
//  '<S90>'  : 'controller/altitude PID/PID Controller/Parallel P Gain/Internal Parameters'
//  '<S91>'  : 'controller/altitude PID/PID Controller/Reset Signal/Disabled'
//  '<S92>'  : 'controller/altitude PID/PID Controller/Saturation/Enabled'
//  '<S93>'  : 'controller/altitude PID/PID Controller/Saturation Fdbk/Disabled'
//  '<S94>'  : 'controller/altitude PID/PID Controller/Sum/Sum_PID'
//  '<S95>'  : 'controller/altitude PID/PID Controller/Sum Fdbk/Disabled'
//  '<S96>'  : 'controller/altitude PID/PID Controller/Tracking Mode/Disabled'
//  '<S97>'  : 'controller/altitude PID/PID Controller/Tracking Mode Sum/Passthrough'
//  '<S98>'  : 'controller/altitude PID/PID Controller/Tsamp - Integral/TsSignalSpecification'
//  '<S99>'  : 'controller/altitude PID/PID Controller/Tsamp - Ngain/Passthrough'
//  '<S100>' : 'controller/altitude PID/PID Controller/postSat Signal/Forward_Path'
//  '<S101>' : 'controller/altitude PID/PID Controller/preSat Signal/Forward_Path'
//  '<S102>' : 'controller/bearing PID/PID Controller'
//  '<S103>' : 'controller/bearing PID/PID Controller/Anti-windup'
//  '<S104>' : 'controller/bearing PID/PID Controller/D Gain'
//  '<S105>' : 'controller/bearing PID/PID Controller/Filter'
//  '<S106>' : 'controller/bearing PID/PID Controller/Filter ICs'
//  '<S107>' : 'controller/bearing PID/PID Controller/I Gain'
//  '<S108>' : 'controller/bearing PID/PID Controller/Ideal P Gain'
//  '<S109>' : 'controller/bearing PID/PID Controller/Ideal P Gain Fdbk'
//  '<S110>' : 'controller/bearing PID/PID Controller/Integrator'
//  '<S111>' : 'controller/bearing PID/PID Controller/Integrator ICs'
//  '<S112>' : 'controller/bearing PID/PID Controller/N Copy'
//  '<S113>' : 'controller/bearing PID/PID Controller/N Gain'
//  '<S114>' : 'controller/bearing PID/PID Controller/P Copy'
//  '<S115>' : 'controller/bearing PID/PID Controller/Parallel P Gain'
//  '<S116>' : 'controller/bearing PID/PID Controller/Reset Signal'
//  '<S117>' : 'controller/bearing PID/PID Controller/Saturation'
//  '<S118>' : 'controller/bearing PID/PID Controller/Saturation Fdbk'
//  '<S119>' : 'controller/bearing PID/PID Controller/Sum'
//  '<S120>' : 'controller/bearing PID/PID Controller/Sum Fdbk'
//  '<S121>' : 'controller/bearing PID/PID Controller/Tracking Mode'
//  '<S122>' : 'controller/bearing PID/PID Controller/Tracking Mode Sum'
//  '<S123>' : 'controller/bearing PID/PID Controller/Tsamp - Integral'
//  '<S124>' : 'controller/bearing PID/PID Controller/Tsamp - Ngain'
//  '<S125>' : 'controller/bearing PID/PID Controller/postSat Signal'
//  '<S126>' : 'controller/bearing PID/PID Controller/preSat Signal'
//  '<S127>' : 'controller/bearing PID/PID Controller/Anti-windup/Passthrough'
//  '<S128>' : 'controller/bearing PID/PID Controller/D Gain/Internal Parameters'
//  '<S129>' : 'controller/bearing PID/PID Controller/Filter/Disc. Forward Euler Filter'
//  '<S130>' : 'controller/bearing PID/PID Controller/Filter ICs/Internal IC - Filter'
//  '<S131>' : 'controller/bearing PID/PID Controller/I Gain/Internal Parameters'
//  '<S132>' : 'controller/bearing PID/PID Controller/Ideal P Gain/Passthrough'
//  '<S133>' : 'controller/bearing PID/PID Controller/Ideal P Gain Fdbk/Disabled'
//  '<S134>' : 'controller/bearing PID/PID Controller/Integrator/Discrete'
//  '<S135>' : 'controller/bearing PID/PID Controller/Integrator ICs/Internal IC'
//  '<S136>' : 'controller/bearing PID/PID Controller/N Copy/Disabled'
//  '<S137>' : 'controller/bearing PID/PID Controller/N Gain/Internal Parameters'
//  '<S138>' : 'controller/bearing PID/PID Controller/P Copy/Disabled'
//  '<S139>' : 'controller/bearing PID/PID Controller/Parallel P Gain/Internal Parameters'
//  '<S140>' : 'controller/bearing PID/PID Controller/Reset Signal/Disabled'
//  '<S141>' : 'controller/bearing PID/PID Controller/Saturation/Enabled'
//  '<S142>' : 'controller/bearing PID/PID Controller/Saturation Fdbk/Disabled'
//  '<S143>' : 'controller/bearing PID/PID Controller/Sum/Sum_PID'
//  '<S144>' : 'controller/bearing PID/PID Controller/Sum Fdbk/Disabled'
//  '<S145>' : 'controller/bearing PID/PID Controller/Tracking Mode/Disabled'
//  '<S146>' : 'controller/bearing PID/PID Controller/Tracking Mode Sum/Passthrough'
//  '<S147>' : 'controller/bearing PID/PID Controller/Tsamp - Integral/TsSignalSpecification'
//  '<S148>' : 'controller/bearing PID/PID Controller/Tsamp - Ngain/Passthrough'
//  '<S149>' : 'controller/bearing PID/PID Controller/postSat Signal/Forward_Path'
//  '<S150>' : 'controller/bearing PID/PID Controller/preSat Signal/Forward_Path'

#endif                                 // RTW_HEADER_controller_h_

//
// File trailer for generated code.
//
// [EOF]
//
