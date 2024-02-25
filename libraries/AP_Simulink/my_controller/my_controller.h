//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: my_controller.h
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
#ifndef RTW_HEADER_my_controller_h_
#define RTW_HEADER_my_controller_h_
#include <stdbool.h>
#include <stdint.h>

// Class declaration for model my_controller
class my_controller final
{
  // public data and function members
 public:
  // Block signals and states (default storage) for system '<Root>'
  struct DW_T {
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
    float airspeed_obj;                // '<Root>/airspeed_obj'
    float pitch_obj;                   // '<Root>/pitch_obj'
    float roll_obj;                    // '<Root>/roll_obj'
    float debug;                       // '<Root>/debug'
  };

  // Copy Constructor
  my_controller(my_controller const&) = delete;

  // Assignment Operator
  my_controller& operator= (my_controller const&) & = delete;

  // Move Constructor
  my_controller(my_controller &&) = delete;

  // Move Assignment Operator
  my_controller& operator= (my_controller &&) = delete;

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
  my_controller();

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
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S38>/Derivative Gain' : Eliminated nontunable gain of 1
//  Block '<S41>/Integral Gain' : Eliminated nontunable gain of 1
//  Block '<S47>/Filter Coefficient' : Eliminated nontunable gain of 1
//  Block '<S87>/Derivative Gain' : Eliminated nontunable gain of 1
//  Block '<S90>/Integral Gain' : Eliminated nontunable gain of 1
//  Block '<S96>/Filter Coefficient' : Eliminated nontunable gain of 1
//  Block '<S136>/Derivative Gain' : Eliminated nontunable gain of 1
//  Block '<S139>/Integral Gain' : Eliminated nontunable gain of 1
//  Block '<S145>/Filter Coefficient' : Eliminated nontunable gain of 1


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
//  '<Root>' : 'my_controller'
//  '<S1>'   : 'my_controller/Custom controller toggle'
//  '<S2>'   : 'my_controller/High level controller'
//  '<S3>'   : 'my_controller/Low level controller'
//  '<S4>'   : 'my_controller/High level controller/AUTO controller'
//  '<S5>'   : 'my_controller/High level controller/STABILIZE controller'
//  '<S6>'   : 'my_controller/High level controller/AUTO controller/Altitude controller'
//  '<S7>'   : 'my_controller/High level controller/AUTO controller/Bearing controller'
//  '<S8>'   : 'my_controller/High level controller/AUTO controller/Speed controller'
//  '<S9>'   : 'my_controller/Low level controller/Pitch controller'
//  '<S10>'  : 'my_controller/Low level controller/Roll controller'
//  '<S11>'  : 'my_controller/Low level controller/Throttle controller'
//  '<S12>'  : 'my_controller/Low level controller/Pitch controller/Discrete PID Controller1'
//  '<S13>'  : 'my_controller/Low level controller/Pitch controller/Discrete PID Controller1/Anti-windup'
//  '<S14>'  : 'my_controller/Low level controller/Pitch controller/Discrete PID Controller1/D Gain'
//  '<S15>'  : 'my_controller/Low level controller/Pitch controller/Discrete PID Controller1/Filter'
//  '<S16>'  : 'my_controller/Low level controller/Pitch controller/Discrete PID Controller1/Filter ICs'
//  '<S17>'  : 'my_controller/Low level controller/Pitch controller/Discrete PID Controller1/I Gain'
//  '<S18>'  : 'my_controller/Low level controller/Pitch controller/Discrete PID Controller1/Ideal P Gain'
//  '<S19>'  : 'my_controller/Low level controller/Pitch controller/Discrete PID Controller1/Ideal P Gain Fdbk'
//  '<S20>'  : 'my_controller/Low level controller/Pitch controller/Discrete PID Controller1/Integrator'
//  '<S21>'  : 'my_controller/Low level controller/Pitch controller/Discrete PID Controller1/Integrator ICs'
//  '<S22>'  : 'my_controller/Low level controller/Pitch controller/Discrete PID Controller1/N Copy'
//  '<S23>'  : 'my_controller/Low level controller/Pitch controller/Discrete PID Controller1/N Gain'
//  '<S24>'  : 'my_controller/Low level controller/Pitch controller/Discrete PID Controller1/P Copy'
//  '<S25>'  : 'my_controller/Low level controller/Pitch controller/Discrete PID Controller1/Parallel P Gain'
//  '<S26>'  : 'my_controller/Low level controller/Pitch controller/Discrete PID Controller1/Reset Signal'
//  '<S27>'  : 'my_controller/Low level controller/Pitch controller/Discrete PID Controller1/Saturation'
//  '<S28>'  : 'my_controller/Low level controller/Pitch controller/Discrete PID Controller1/Saturation Fdbk'
//  '<S29>'  : 'my_controller/Low level controller/Pitch controller/Discrete PID Controller1/Sum'
//  '<S30>'  : 'my_controller/Low level controller/Pitch controller/Discrete PID Controller1/Sum Fdbk'
//  '<S31>'  : 'my_controller/Low level controller/Pitch controller/Discrete PID Controller1/Tracking Mode'
//  '<S32>'  : 'my_controller/Low level controller/Pitch controller/Discrete PID Controller1/Tracking Mode Sum'
//  '<S33>'  : 'my_controller/Low level controller/Pitch controller/Discrete PID Controller1/Tsamp - Integral'
//  '<S34>'  : 'my_controller/Low level controller/Pitch controller/Discrete PID Controller1/Tsamp - Ngain'
//  '<S35>'  : 'my_controller/Low level controller/Pitch controller/Discrete PID Controller1/postSat Signal'
//  '<S36>'  : 'my_controller/Low level controller/Pitch controller/Discrete PID Controller1/preSat Signal'
//  '<S37>'  : 'my_controller/Low level controller/Pitch controller/Discrete PID Controller1/Anti-windup/Passthrough'
//  '<S38>'  : 'my_controller/Low level controller/Pitch controller/Discrete PID Controller1/D Gain/Internal Parameters'
//  '<S39>'  : 'my_controller/Low level controller/Pitch controller/Discrete PID Controller1/Filter/Disc. Forward Euler Filter'
//  '<S40>'  : 'my_controller/Low level controller/Pitch controller/Discrete PID Controller1/Filter ICs/Internal IC - Filter'
//  '<S41>'  : 'my_controller/Low level controller/Pitch controller/Discrete PID Controller1/I Gain/Internal Parameters'
//  '<S42>'  : 'my_controller/Low level controller/Pitch controller/Discrete PID Controller1/Ideal P Gain/Passthrough'
//  '<S43>'  : 'my_controller/Low level controller/Pitch controller/Discrete PID Controller1/Ideal P Gain Fdbk/Disabled'
//  '<S44>'  : 'my_controller/Low level controller/Pitch controller/Discrete PID Controller1/Integrator/Discrete'
//  '<S45>'  : 'my_controller/Low level controller/Pitch controller/Discrete PID Controller1/Integrator ICs/Internal IC'
//  '<S46>'  : 'my_controller/Low level controller/Pitch controller/Discrete PID Controller1/N Copy/Disabled'
//  '<S47>'  : 'my_controller/Low level controller/Pitch controller/Discrete PID Controller1/N Gain/Internal Parameters'
//  '<S48>'  : 'my_controller/Low level controller/Pitch controller/Discrete PID Controller1/P Copy/Disabled'
//  '<S49>'  : 'my_controller/Low level controller/Pitch controller/Discrete PID Controller1/Parallel P Gain/Internal Parameters'
//  '<S50>'  : 'my_controller/Low level controller/Pitch controller/Discrete PID Controller1/Reset Signal/Disabled'
//  '<S51>'  : 'my_controller/Low level controller/Pitch controller/Discrete PID Controller1/Saturation/Passthrough'
//  '<S52>'  : 'my_controller/Low level controller/Pitch controller/Discrete PID Controller1/Saturation Fdbk/Disabled'
//  '<S53>'  : 'my_controller/Low level controller/Pitch controller/Discrete PID Controller1/Sum/Sum_PID'
//  '<S54>'  : 'my_controller/Low level controller/Pitch controller/Discrete PID Controller1/Sum Fdbk/Disabled'
//  '<S55>'  : 'my_controller/Low level controller/Pitch controller/Discrete PID Controller1/Tracking Mode/Disabled'
//  '<S56>'  : 'my_controller/Low level controller/Pitch controller/Discrete PID Controller1/Tracking Mode Sum/Passthrough'
//  '<S57>'  : 'my_controller/Low level controller/Pitch controller/Discrete PID Controller1/Tsamp - Integral/TsSignalSpecification'
//  '<S58>'  : 'my_controller/Low level controller/Pitch controller/Discrete PID Controller1/Tsamp - Ngain/Passthrough'
//  '<S59>'  : 'my_controller/Low level controller/Pitch controller/Discrete PID Controller1/postSat Signal/Forward_Path'
//  '<S60>'  : 'my_controller/Low level controller/Pitch controller/Discrete PID Controller1/preSat Signal/Forward_Path'
//  '<S61>'  : 'my_controller/Low level controller/Roll controller/Discrete PID Controller'
//  '<S62>'  : 'my_controller/Low level controller/Roll controller/Discrete PID Controller/Anti-windup'
//  '<S63>'  : 'my_controller/Low level controller/Roll controller/Discrete PID Controller/D Gain'
//  '<S64>'  : 'my_controller/Low level controller/Roll controller/Discrete PID Controller/Filter'
//  '<S65>'  : 'my_controller/Low level controller/Roll controller/Discrete PID Controller/Filter ICs'
//  '<S66>'  : 'my_controller/Low level controller/Roll controller/Discrete PID Controller/I Gain'
//  '<S67>'  : 'my_controller/Low level controller/Roll controller/Discrete PID Controller/Ideal P Gain'
//  '<S68>'  : 'my_controller/Low level controller/Roll controller/Discrete PID Controller/Ideal P Gain Fdbk'
//  '<S69>'  : 'my_controller/Low level controller/Roll controller/Discrete PID Controller/Integrator'
//  '<S70>'  : 'my_controller/Low level controller/Roll controller/Discrete PID Controller/Integrator ICs'
//  '<S71>'  : 'my_controller/Low level controller/Roll controller/Discrete PID Controller/N Copy'
//  '<S72>'  : 'my_controller/Low level controller/Roll controller/Discrete PID Controller/N Gain'
//  '<S73>'  : 'my_controller/Low level controller/Roll controller/Discrete PID Controller/P Copy'
//  '<S74>'  : 'my_controller/Low level controller/Roll controller/Discrete PID Controller/Parallel P Gain'
//  '<S75>'  : 'my_controller/Low level controller/Roll controller/Discrete PID Controller/Reset Signal'
//  '<S76>'  : 'my_controller/Low level controller/Roll controller/Discrete PID Controller/Saturation'
//  '<S77>'  : 'my_controller/Low level controller/Roll controller/Discrete PID Controller/Saturation Fdbk'
//  '<S78>'  : 'my_controller/Low level controller/Roll controller/Discrete PID Controller/Sum'
//  '<S79>'  : 'my_controller/Low level controller/Roll controller/Discrete PID Controller/Sum Fdbk'
//  '<S80>'  : 'my_controller/Low level controller/Roll controller/Discrete PID Controller/Tracking Mode'
//  '<S81>'  : 'my_controller/Low level controller/Roll controller/Discrete PID Controller/Tracking Mode Sum'
//  '<S82>'  : 'my_controller/Low level controller/Roll controller/Discrete PID Controller/Tsamp - Integral'
//  '<S83>'  : 'my_controller/Low level controller/Roll controller/Discrete PID Controller/Tsamp - Ngain'
//  '<S84>'  : 'my_controller/Low level controller/Roll controller/Discrete PID Controller/postSat Signal'
//  '<S85>'  : 'my_controller/Low level controller/Roll controller/Discrete PID Controller/preSat Signal'
//  '<S86>'  : 'my_controller/Low level controller/Roll controller/Discrete PID Controller/Anti-windup/Passthrough'
//  '<S87>'  : 'my_controller/Low level controller/Roll controller/Discrete PID Controller/D Gain/Internal Parameters'
//  '<S88>'  : 'my_controller/Low level controller/Roll controller/Discrete PID Controller/Filter/Disc. Forward Euler Filter'
//  '<S89>'  : 'my_controller/Low level controller/Roll controller/Discrete PID Controller/Filter ICs/Internal IC - Filter'
//  '<S90>'  : 'my_controller/Low level controller/Roll controller/Discrete PID Controller/I Gain/Internal Parameters'
//  '<S91>'  : 'my_controller/Low level controller/Roll controller/Discrete PID Controller/Ideal P Gain/Passthrough'
//  '<S92>'  : 'my_controller/Low level controller/Roll controller/Discrete PID Controller/Ideal P Gain Fdbk/Disabled'
//  '<S93>'  : 'my_controller/Low level controller/Roll controller/Discrete PID Controller/Integrator/Discrete'
//  '<S94>'  : 'my_controller/Low level controller/Roll controller/Discrete PID Controller/Integrator ICs/Internal IC'
//  '<S95>'  : 'my_controller/Low level controller/Roll controller/Discrete PID Controller/N Copy/Disabled'
//  '<S96>'  : 'my_controller/Low level controller/Roll controller/Discrete PID Controller/N Gain/Internal Parameters'
//  '<S97>'  : 'my_controller/Low level controller/Roll controller/Discrete PID Controller/P Copy/Disabled'
//  '<S98>'  : 'my_controller/Low level controller/Roll controller/Discrete PID Controller/Parallel P Gain/Internal Parameters'
//  '<S99>'  : 'my_controller/Low level controller/Roll controller/Discrete PID Controller/Reset Signal/Disabled'
//  '<S100>' : 'my_controller/Low level controller/Roll controller/Discrete PID Controller/Saturation/Passthrough'
//  '<S101>' : 'my_controller/Low level controller/Roll controller/Discrete PID Controller/Saturation Fdbk/Disabled'
//  '<S102>' : 'my_controller/Low level controller/Roll controller/Discrete PID Controller/Sum/Sum_PID'
//  '<S103>' : 'my_controller/Low level controller/Roll controller/Discrete PID Controller/Sum Fdbk/Disabled'
//  '<S104>' : 'my_controller/Low level controller/Roll controller/Discrete PID Controller/Tracking Mode/Disabled'
//  '<S105>' : 'my_controller/Low level controller/Roll controller/Discrete PID Controller/Tracking Mode Sum/Passthrough'
//  '<S106>' : 'my_controller/Low level controller/Roll controller/Discrete PID Controller/Tsamp - Integral/TsSignalSpecification'
//  '<S107>' : 'my_controller/Low level controller/Roll controller/Discrete PID Controller/Tsamp - Ngain/Passthrough'
//  '<S108>' : 'my_controller/Low level controller/Roll controller/Discrete PID Controller/postSat Signal/Forward_Path'
//  '<S109>' : 'my_controller/Low level controller/Roll controller/Discrete PID Controller/preSat Signal/Forward_Path'
//  '<S110>' : 'my_controller/Low level controller/Throttle controller/PID Controller'
//  '<S111>' : 'my_controller/Low level controller/Throttle controller/PID Controller/Anti-windup'
//  '<S112>' : 'my_controller/Low level controller/Throttle controller/PID Controller/D Gain'
//  '<S113>' : 'my_controller/Low level controller/Throttle controller/PID Controller/Filter'
//  '<S114>' : 'my_controller/Low level controller/Throttle controller/PID Controller/Filter ICs'
//  '<S115>' : 'my_controller/Low level controller/Throttle controller/PID Controller/I Gain'
//  '<S116>' : 'my_controller/Low level controller/Throttle controller/PID Controller/Ideal P Gain'
//  '<S117>' : 'my_controller/Low level controller/Throttle controller/PID Controller/Ideal P Gain Fdbk'
//  '<S118>' : 'my_controller/Low level controller/Throttle controller/PID Controller/Integrator'
//  '<S119>' : 'my_controller/Low level controller/Throttle controller/PID Controller/Integrator ICs'
//  '<S120>' : 'my_controller/Low level controller/Throttle controller/PID Controller/N Copy'
//  '<S121>' : 'my_controller/Low level controller/Throttle controller/PID Controller/N Gain'
//  '<S122>' : 'my_controller/Low level controller/Throttle controller/PID Controller/P Copy'
//  '<S123>' : 'my_controller/Low level controller/Throttle controller/PID Controller/Parallel P Gain'
//  '<S124>' : 'my_controller/Low level controller/Throttle controller/PID Controller/Reset Signal'
//  '<S125>' : 'my_controller/Low level controller/Throttle controller/PID Controller/Saturation'
//  '<S126>' : 'my_controller/Low level controller/Throttle controller/PID Controller/Saturation Fdbk'
//  '<S127>' : 'my_controller/Low level controller/Throttle controller/PID Controller/Sum'
//  '<S128>' : 'my_controller/Low level controller/Throttle controller/PID Controller/Sum Fdbk'
//  '<S129>' : 'my_controller/Low level controller/Throttle controller/PID Controller/Tracking Mode'
//  '<S130>' : 'my_controller/Low level controller/Throttle controller/PID Controller/Tracking Mode Sum'
//  '<S131>' : 'my_controller/Low level controller/Throttle controller/PID Controller/Tsamp - Integral'
//  '<S132>' : 'my_controller/Low level controller/Throttle controller/PID Controller/Tsamp - Ngain'
//  '<S133>' : 'my_controller/Low level controller/Throttle controller/PID Controller/postSat Signal'
//  '<S134>' : 'my_controller/Low level controller/Throttle controller/PID Controller/preSat Signal'
//  '<S135>' : 'my_controller/Low level controller/Throttle controller/PID Controller/Anti-windup/Passthrough'
//  '<S136>' : 'my_controller/Low level controller/Throttle controller/PID Controller/D Gain/Internal Parameters'
//  '<S137>' : 'my_controller/Low level controller/Throttle controller/PID Controller/Filter/Disc. Forward Euler Filter'
//  '<S138>' : 'my_controller/Low level controller/Throttle controller/PID Controller/Filter ICs/Internal IC - Filter'
//  '<S139>' : 'my_controller/Low level controller/Throttle controller/PID Controller/I Gain/Internal Parameters'
//  '<S140>' : 'my_controller/Low level controller/Throttle controller/PID Controller/Ideal P Gain/Passthrough'
//  '<S141>' : 'my_controller/Low level controller/Throttle controller/PID Controller/Ideal P Gain Fdbk/Disabled'
//  '<S142>' : 'my_controller/Low level controller/Throttle controller/PID Controller/Integrator/Discrete'
//  '<S143>' : 'my_controller/Low level controller/Throttle controller/PID Controller/Integrator ICs/Internal IC'
//  '<S144>' : 'my_controller/Low level controller/Throttle controller/PID Controller/N Copy/Disabled'
//  '<S145>' : 'my_controller/Low level controller/Throttle controller/PID Controller/N Gain/Internal Parameters'
//  '<S146>' : 'my_controller/Low level controller/Throttle controller/PID Controller/P Copy/Disabled'
//  '<S147>' : 'my_controller/Low level controller/Throttle controller/PID Controller/Parallel P Gain/Internal Parameters'
//  '<S148>' : 'my_controller/Low level controller/Throttle controller/PID Controller/Reset Signal/Disabled'
//  '<S149>' : 'my_controller/Low level controller/Throttle controller/PID Controller/Saturation/Passthrough'
//  '<S150>' : 'my_controller/Low level controller/Throttle controller/PID Controller/Saturation Fdbk/Disabled'
//  '<S151>' : 'my_controller/Low level controller/Throttle controller/PID Controller/Sum/Sum_PID'
//  '<S152>' : 'my_controller/Low level controller/Throttle controller/PID Controller/Sum Fdbk/Disabled'
//  '<S153>' : 'my_controller/Low level controller/Throttle controller/PID Controller/Tracking Mode/Disabled'
//  '<S154>' : 'my_controller/Low level controller/Throttle controller/PID Controller/Tracking Mode Sum/Passthrough'
//  '<S155>' : 'my_controller/Low level controller/Throttle controller/PID Controller/Tsamp - Integral/TsSignalSpecification'
//  '<S156>' : 'my_controller/Low level controller/Throttle controller/PID Controller/Tsamp - Ngain/Passthrough'
//  '<S157>' : 'my_controller/Low level controller/Throttle controller/PID Controller/postSat Signal/Forward_Path'
//  '<S158>' : 'my_controller/Low level controller/Throttle controller/PID Controller/preSat Signal/Forward_Path'

#endif                                 // RTW_HEADER_my_controller_h_

//
// File trailer for generated code.
//
// [EOF]
//
