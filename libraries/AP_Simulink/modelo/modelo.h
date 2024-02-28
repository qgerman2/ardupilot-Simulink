//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: modelo.h
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
#ifndef RTW_HEADER_modelo_h_
#define RTW_HEADER_modelo_h_
#include <stdbool.h>
#include <stdint.h>

// Class declaration for model modelo
class modelo final
{
  // public data and function members
 public:
  // Block signals and states (default storage) for system '<Root>'
  struct DW_T {
    float Integrator_DSTATE;           // '<S34>/Integrator'
    float Filter_DSTATE;               // '<S29>/Filter'
    float Integrator_DSTATE_p;         // '<S82>/Integrator'
    float Filter_DSTATE_k;             // '<S77>/Filter'
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
    float airspeed_nav;                // '<Root>/airspeed_nav'
    float aileron_rc;                  // '<Root>/aileron_rc'
    float elevator_rc;                 // '<Root>/elevator_rc'
    float rudder_rc;                   // '<Root>/rudder_rc'
    float throttle_rc;                 // '<Root>/throttle_rc'
    bool enable_rc;                    // '<Root>/enable_rc'
    float roll_L1;                     // '<Root>/roll_L1'
    float pitch_TECS;                  // '<Root>/pitch_TECS'
    float throttle_TECS;               // '<Root>/throttle_TECS'
  };

  // External outputs (root outports fed by signals with default storage)
  struct ExtY_T {
    bool enable_p;                     // '<Root>/enable_p'
    float aileron;                     // '<Root>/aileron'
    float elevator;                    // '<Root>/elevator'
    float rudder;                      // '<Root>/rudder'
    float throttle;                    // '<Root>/throttle'
    float roll_obj;                    // '<Root>/roll_obj'
    float pitch_obj;                   // '<Root>/pitch_obj'
    float debug;                       // '<Root>/debug'
  };

  // Copy Constructor
  modelo(modelo const&) = delete;

  // Assignment Operator
  modelo& operator= (modelo const&) & = delete;

  // Move Constructor
  modelo(modelo &&) = delete;

  // Move Assignment Operator
  modelo& operator= (modelo &&) = delete;

  // Block states
  DW_T DW;

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
  const DW_T &getDWork() const
  {
    return DW;
  }

  // Block states set method
  void setDWork(const DW_T *pDW_T)
  {
    DW = *pDW_T;
  }

  // model initialize function
  static void initialize();

  // model step function
  void step();

  // model terminate function
  static void terminate();

  // Constructor
  modelo();

  // private data and function members
 private:
  // External inputs
  ExtU_T U;

  // External outputs
  ExtY_T Y;
};

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S28>/Derivative Gain' : Eliminated nontunable gain of 1
//  Block '<S31>/Integral Gain' : Eliminated nontunable gain of 1
//  Block '<S37>/Filter Coefficient' : Eliminated nontunable gain of 1
//  Block '<S39>/Proportional Gain' : Eliminated nontunable gain of 1
//  Block '<S76>/Derivative Gain' : Eliminated nontunable gain of 1
//  Block '<S79>/Integral Gain' : Eliminated nontunable gain of 1
//  Block '<S85>/Filter Coefficient' : Eliminated nontunable gain of 1
//  Block '<S87>/Proportional Gain' : Eliminated nontunable gain of 1


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
//  '<Root>' : 'modelo'
//  '<S1>'   : 'modelo/Discrete PID Controller'
//  '<S2>'   : 'modelo/Discrete PID Controller1'
//  '<S3>'   : 'modelo/Discrete PID Controller/Anti-windup'
//  '<S4>'   : 'modelo/Discrete PID Controller/D Gain'
//  '<S5>'   : 'modelo/Discrete PID Controller/Filter'
//  '<S6>'   : 'modelo/Discrete PID Controller/Filter ICs'
//  '<S7>'   : 'modelo/Discrete PID Controller/I Gain'
//  '<S8>'   : 'modelo/Discrete PID Controller/Ideal P Gain'
//  '<S9>'   : 'modelo/Discrete PID Controller/Ideal P Gain Fdbk'
//  '<S10>'  : 'modelo/Discrete PID Controller/Integrator'
//  '<S11>'  : 'modelo/Discrete PID Controller/Integrator ICs'
//  '<S12>'  : 'modelo/Discrete PID Controller/N Copy'
//  '<S13>'  : 'modelo/Discrete PID Controller/N Gain'
//  '<S14>'  : 'modelo/Discrete PID Controller/P Copy'
//  '<S15>'  : 'modelo/Discrete PID Controller/Parallel P Gain'
//  '<S16>'  : 'modelo/Discrete PID Controller/Reset Signal'
//  '<S17>'  : 'modelo/Discrete PID Controller/Saturation'
//  '<S18>'  : 'modelo/Discrete PID Controller/Saturation Fdbk'
//  '<S19>'  : 'modelo/Discrete PID Controller/Sum'
//  '<S20>'  : 'modelo/Discrete PID Controller/Sum Fdbk'
//  '<S21>'  : 'modelo/Discrete PID Controller/Tracking Mode'
//  '<S22>'  : 'modelo/Discrete PID Controller/Tracking Mode Sum'
//  '<S23>'  : 'modelo/Discrete PID Controller/Tsamp - Integral'
//  '<S24>'  : 'modelo/Discrete PID Controller/Tsamp - Ngain'
//  '<S25>'  : 'modelo/Discrete PID Controller/postSat Signal'
//  '<S26>'  : 'modelo/Discrete PID Controller/preSat Signal'
//  '<S27>'  : 'modelo/Discrete PID Controller/Anti-windup/Passthrough'
//  '<S28>'  : 'modelo/Discrete PID Controller/D Gain/Internal Parameters'
//  '<S29>'  : 'modelo/Discrete PID Controller/Filter/Disc. Forward Euler Filter'
//  '<S30>'  : 'modelo/Discrete PID Controller/Filter ICs/Internal IC - Filter'
//  '<S31>'  : 'modelo/Discrete PID Controller/I Gain/Internal Parameters'
//  '<S32>'  : 'modelo/Discrete PID Controller/Ideal P Gain/Passthrough'
//  '<S33>'  : 'modelo/Discrete PID Controller/Ideal P Gain Fdbk/Disabled'
//  '<S34>'  : 'modelo/Discrete PID Controller/Integrator/Discrete'
//  '<S35>'  : 'modelo/Discrete PID Controller/Integrator ICs/Internal IC'
//  '<S36>'  : 'modelo/Discrete PID Controller/N Copy/Disabled'
//  '<S37>'  : 'modelo/Discrete PID Controller/N Gain/Internal Parameters'
//  '<S38>'  : 'modelo/Discrete PID Controller/P Copy/Disabled'
//  '<S39>'  : 'modelo/Discrete PID Controller/Parallel P Gain/Internal Parameters'
//  '<S40>'  : 'modelo/Discrete PID Controller/Reset Signal/Disabled'
//  '<S41>'  : 'modelo/Discrete PID Controller/Saturation/Passthrough'
//  '<S42>'  : 'modelo/Discrete PID Controller/Saturation Fdbk/Disabled'
//  '<S43>'  : 'modelo/Discrete PID Controller/Sum/Sum_PID'
//  '<S44>'  : 'modelo/Discrete PID Controller/Sum Fdbk/Disabled'
//  '<S45>'  : 'modelo/Discrete PID Controller/Tracking Mode/Disabled'
//  '<S46>'  : 'modelo/Discrete PID Controller/Tracking Mode Sum/Passthrough'
//  '<S47>'  : 'modelo/Discrete PID Controller/Tsamp - Integral/TsSignalSpecification'
//  '<S48>'  : 'modelo/Discrete PID Controller/Tsamp - Ngain/Passthrough'
//  '<S49>'  : 'modelo/Discrete PID Controller/postSat Signal/Forward_Path'
//  '<S50>'  : 'modelo/Discrete PID Controller/preSat Signal/Forward_Path'
//  '<S51>'  : 'modelo/Discrete PID Controller1/Anti-windup'
//  '<S52>'  : 'modelo/Discrete PID Controller1/D Gain'
//  '<S53>'  : 'modelo/Discrete PID Controller1/Filter'
//  '<S54>'  : 'modelo/Discrete PID Controller1/Filter ICs'
//  '<S55>'  : 'modelo/Discrete PID Controller1/I Gain'
//  '<S56>'  : 'modelo/Discrete PID Controller1/Ideal P Gain'
//  '<S57>'  : 'modelo/Discrete PID Controller1/Ideal P Gain Fdbk'
//  '<S58>'  : 'modelo/Discrete PID Controller1/Integrator'
//  '<S59>'  : 'modelo/Discrete PID Controller1/Integrator ICs'
//  '<S60>'  : 'modelo/Discrete PID Controller1/N Copy'
//  '<S61>'  : 'modelo/Discrete PID Controller1/N Gain'
//  '<S62>'  : 'modelo/Discrete PID Controller1/P Copy'
//  '<S63>'  : 'modelo/Discrete PID Controller1/Parallel P Gain'
//  '<S64>'  : 'modelo/Discrete PID Controller1/Reset Signal'
//  '<S65>'  : 'modelo/Discrete PID Controller1/Saturation'
//  '<S66>'  : 'modelo/Discrete PID Controller1/Saturation Fdbk'
//  '<S67>'  : 'modelo/Discrete PID Controller1/Sum'
//  '<S68>'  : 'modelo/Discrete PID Controller1/Sum Fdbk'
//  '<S69>'  : 'modelo/Discrete PID Controller1/Tracking Mode'
//  '<S70>'  : 'modelo/Discrete PID Controller1/Tracking Mode Sum'
//  '<S71>'  : 'modelo/Discrete PID Controller1/Tsamp - Integral'
//  '<S72>'  : 'modelo/Discrete PID Controller1/Tsamp - Ngain'
//  '<S73>'  : 'modelo/Discrete PID Controller1/postSat Signal'
//  '<S74>'  : 'modelo/Discrete PID Controller1/preSat Signal'
//  '<S75>'  : 'modelo/Discrete PID Controller1/Anti-windup/Passthrough'
//  '<S76>'  : 'modelo/Discrete PID Controller1/D Gain/Internal Parameters'
//  '<S77>'  : 'modelo/Discrete PID Controller1/Filter/Disc. Forward Euler Filter'
//  '<S78>'  : 'modelo/Discrete PID Controller1/Filter ICs/Internal IC - Filter'
//  '<S79>'  : 'modelo/Discrete PID Controller1/I Gain/Internal Parameters'
//  '<S80>'  : 'modelo/Discrete PID Controller1/Ideal P Gain/Passthrough'
//  '<S81>'  : 'modelo/Discrete PID Controller1/Ideal P Gain Fdbk/Disabled'
//  '<S82>'  : 'modelo/Discrete PID Controller1/Integrator/Discrete'
//  '<S83>'  : 'modelo/Discrete PID Controller1/Integrator ICs/Internal IC'
//  '<S84>'  : 'modelo/Discrete PID Controller1/N Copy/Disabled'
//  '<S85>'  : 'modelo/Discrete PID Controller1/N Gain/Internal Parameters'
//  '<S86>'  : 'modelo/Discrete PID Controller1/P Copy/Disabled'
//  '<S87>'  : 'modelo/Discrete PID Controller1/Parallel P Gain/Internal Parameters'
//  '<S88>'  : 'modelo/Discrete PID Controller1/Reset Signal/Disabled'
//  '<S89>'  : 'modelo/Discrete PID Controller1/Saturation/Passthrough'
//  '<S90>'  : 'modelo/Discrete PID Controller1/Saturation Fdbk/Disabled'
//  '<S91>'  : 'modelo/Discrete PID Controller1/Sum/Sum_PID'
//  '<S92>'  : 'modelo/Discrete PID Controller1/Sum Fdbk/Disabled'
//  '<S93>'  : 'modelo/Discrete PID Controller1/Tracking Mode/Disabled'
//  '<S94>'  : 'modelo/Discrete PID Controller1/Tracking Mode Sum/Passthrough'
//  '<S95>'  : 'modelo/Discrete PID Controller1/Tsamp - Integral/TsSignalSpecification'
//  '<S96>'  : 'modelo/Discrete PID Controller1/Tsamp - Ngain/Passthrough'
//  '<S97>'  : 'modelo/Discrete PID Controller1/postSat Signal/Forward_Path'
//  '<S98>'  : 'modelo/Discrete PID Controller1/preSat Signal/Forward_Path'

#endif                                 // RTW_HEADER_modelo_h_

//
// File trailer for generated code.
//
// [EOF]
//
