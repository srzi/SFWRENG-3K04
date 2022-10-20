/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: P1.h
 *
 * Code generated for Simulink model 'P1'.
 *
 * Model version                  : 1.30
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Wed Oct 19 17:23:27 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_P1_h_
#define RTW_HEADER_P1_h_
#ifndef P1_COMMON_INCLUDES_
#define P1_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "MW_digitalIO.h"
#include "MW_PWM.h"
#include "MW_AnalogIn.h"
#endif                                 /* P1_COMMON_INCLUDES_ */

#include "P1_types.h"
#include <stddef.h>

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block signals (default storage) */
typedef struct {
  real_T PACING_REF_PWM;               /* '<Root>/AOO,VOO,AAI,VVI StateFlows' */
  boolean_T PACE_CHARGE_CONTROL;       /* '<Root>/AOO,VOO,AAI,VVI StateFlows' */
  boolean_T Z_ATRIAL_CONTROL;          /* '<Root>/AOO,VOO,AAI,VVI StateFlows' */
  boolean_T Z_VENTRICLE_CONTROL;       /* '<Root>/AOO,VOO,AAI,VVI StateFlows' */
  boolean_T ATRIAL_PACE_CONTROL;       /* '<Root>/AOO,VOO,AAI,VVI StateFlows' */
  boolean_T VENTRICLE_PACE_CONTROL;    /* '<Root>/AOO,VOO,AAI,VVI StateFlows' */
  boolean_T PACE_GROUND_CONTROL;       /* '<Root>/AOO,VOO,AAI,VVI StateFlows' */
  boolean_T ATRIAL_GROUND_CONTROL;     /* '<Root>/AOO,VOO,AAI,VVI StateFlows' */
  boolean_T VENTRICLE_GROUND_CONTROL;  /* '<Root>/AOO,VOO,AAI,VVI StateFlows' */
} B_P1_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  freedomk64f_DigitalRead_P1_T obj;    /* '<S2>/VENTRICLE_CMP_DETECT' */
  freedomk64f_DigitalRead_P1_T obj_l;  /* '<S2>/ATRIAL_CMP_DETECT' */
  freedomk64f_AnalogInput_P1_T obj_n;  /* '<S2>/Analog Input' */
  freedomk64f_PWMOutput_P1_T obj_c;    /* '<S3>/PACING_REF_PWM' */
  freedomk64f_PWMOutput_P1_T obj_a;    /* '<S2>/VENTRICLE_CMP_REF_PWM' */
  freedomk64f_PWMOutput_P1_T obj_f;    /* '<S2>/ATRIAL_CMP_RED_PWM' */
  freedomk64f_DigitalWrite_P1_T obj_g; /* '<S3>/Z_VENTRICLE_CONTROL' */
  freedomk64f_DigitalWrite_P1_T obj_h; /* '<S3>/Z_ATRIAL_CONTROL' */
  freedomk64f_DigitalWrite_P1_T obj_b; /* '<S3>/VENTRICLE_PACE_CONTROL' */
  freedomk64f_DigitalWrite_P1_T obj_m; /* '<S3>/VENTRICLE_GROUND_CONTROL' */
  freedomk64f_DigitalWrite_P1_T obj_lh;/* '<S3>/PACE_GROUND_CONTROL' */
  freedomk64f_DigitalWrite_P1_T obj_o; /* '<S3>/PACE_CHARGE_CONTROL' */
  freedomk64f_DigitalWrite_P1_T obj_h0;/* '<S3>/ATRIAL_PACE_CONTROL' */
  freedomk64f_DigitalWrite_P1_T obj_oh;/* '<S3>/ATRIAL_GROUND_CONTROL' */
  freedomk64f_DigitalWrite_P1_T obj_e; /* '<S2>/FRONTEND_CTRL' */
  uint32_T temporalCounter_i1;         /* '<Root>/AOO,VOO,AAI,VVI StateFlows' */
  uint8_T is_active_c1_P1;             /* '<Root>/AOO,VOO,AAI,VVI StateFlows' */
  uint8_T is_c1_P1;                    /* '<Root>/AOO,VOO,AAI,VVI StateFlows' */
} DW_P1_T;

/* Parameters (default storage) */
struct P_P1_T_ {
  real_T ATRIAL_CMP_DETECT_SampleTime; /* Expression: SampleTime
                                        * Referenced by: '<S2>/ATRIAL_CMP_DETECT'
                                        */
  real_T AnalogInput_SampleTime;       /* Expression: SampleTime
                                        * Referenced by: '<S2>/Analog Input'
                                        */
  real_T VENTRICLE_CMP_DETECT_SampleTime;/* Expression: SampleTime
                                          * Referenced by: '<S2>/VENTRICLE_CMP_DETECT'
                                          */
  real_T duty_cycle_Value;             /* Expression: 60
                                        * Referenced by: '<Root>/duty_cycle'
                                        */
  real_T Pace_Type_Value;              /* Expression: 0
                                        * Referenced by: '<Root>/Pace_Type'
                                        */
  real_T PERIOD_Value;                 /* Expression: 1000
                                        * Referenced by: '<Root>/PERIOD'
                                        */
  real_T Constant6_Value;              /* Expression: 60000
                                        * Referenced by: '<S4>/Constant6'
                                        */
  real_T LowerRateLimit_Value;         /* Expression: 60
                                        * Referenced by: '<S4>/LowerRateLimit'
                                        */
  real_T PACE_WIDTH_Value;             /* Expression: 1
                                        * Referenced by: '<Root>/PACE_WIDTH'
                                        */
  real_T P_VRP_Value;                  /* Expression: 320
                                        * Referenced by: '<Root>/P_VRP'
                                        */
  real_T P_ARP_Value;                  /* Expression: 250
                                        * Referenced by: '<Root>/P_ARP'
                                        */
  real_T Sensing_Control_Value;        /* Expression: 1
                                        * Referenced by: '<Root>/Sensing_Control'
                                        */
  real_T Constant9_Value;              /* Expression: 50
                                        * Referenced by: '<S2>/Constant9'
                                        */
  real_T Constant2_Value;              /* Expression: 40
                                        * Referenced by: '<S2>/Constant2'
                                        */
  real_T Constant8_Value;              /* Expression: 1
                                        * Referenced by: '<S2>/Constant8'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_P1_T {
  const char_T * volatile errorStatus;
};

/* Block parameters (default storage) */
extern P_P1_T P1_P;

/* Block signals (default storage) */
extern B_P1_T P1_B;

/* Block states (default storage) */
extern DW_P1_T P1_DW;

/* Model entry point functions */
extern void P1_initialize(void);
extern void P1_step(void);
extern void P1_terminate(void);

/* Real-time Model object */
extern RT_MODEL_P1_T *const P1_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S2>/Scope' : Unused code path elimination
 * Block '<S2>/Scope1' : Unused code path elimination
 * Block '<S5>/Constant6' : Unused code path elimination
 * Block '<S5>/Divide' : Unused code path elimination
 * Block '<S5>/UpperRateLimit' : Unused code path elimination
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'P1'
 * '<S1>'   : 'P1/AOO,VOO,AAI,VVI StateFlows'
 * '<S2>'   : 'P1/Digital Writes'
 * '<S3>'   : 'P1/Output Pins'
 * '<S4>'   : 'P1/Subsystem'
 * '<S5>'   : 'P1/Subsystem1'
 */
#endif                                 /* RTW_HEADER_P1_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
