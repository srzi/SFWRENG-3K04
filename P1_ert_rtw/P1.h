/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: P1.h
 *
 * Code generated for Simulink model 'P1'.
 *
 * Model version                  : 1.24
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Mon Oct 17 16:40:28 2022
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
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "dt_info.h"
#include "ext_work.h"
#include "MW_digitalIO.h"
#include "MW_AnalogIn.h"
#include "MW_PWM.h"
#endif                                 /* P1_COMMON_INCLUDES_ */

#include "P1_types.h"
#include <stddef.h>
#include <float.h>
#include <string.h>

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWExtModeInfo
#define rtmGetRTWExtModeInfo(rtm)      ((rtm)->extModeInfo)
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                (&(rtm)->Timing.taskTime0)
#endif

/* Block signals (default storage) */
typedef struct {
  real_T Constant1;                    /* '<Root>/Constant1' */
  real_T Constant;                     /* '<Root>/Constant' */
  real_T Constant4;                    /* '<Root>/Constant4' */
  real_T Divide;                       /* '<S3>/Divide' */
  real_T Constant3;                    /* '<Root>/Constant3' */
  real_T Constant5;                    /* '<Root>/Constant5' */
  real_T Constant6;                    /* '<Root>/Constant6' */
  real_T Divide_d;                     /* '<S4>/Divide' */
  real_T AnalogInput;                  /* '<Root>/Analog Input' */
  real_T PACING_REF_PWM;               /* '<Root>/AOO,VOO,AAI,VVI StateFlows' */
  boolean_T VENTRICLE_CMP_DETECT;      /* '<Root>/VENTRICLE_CMP_DETECT' */
  boolean_T ATRIAL_CMP_DETECT;         /* '<Root>/ATRIAL_CMP_DETECT' */
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
  freedomk64f_DigitalRead_P1_T obj;    /* '<Root>/VENTRICLE_CMP_DETECT' */
  freedomk64f_DigitalRead_P1_T obj_l;  /* '<Root>/ATRIAL_CMP_DETECT' */
  freedomk64f_AnalogInput_P1_T obj_k;  /* '<Root>/Analog Input' */
  freedomk64f_DigitalWrite_P1_T obj_g; /* '<S2>/Z_VENTRICLE_CONTROL' */
  freedomk64f_DigitalWrite_P1_T obj_h; /* '<S2>/Z_ATRIAL_CONTROL' */
  freedomk64f_DigitalWrite_P1_T obj_b; /* '<S2>/VENTRICLE_PACE_CONTROL' */
  freedomk64f_DigitalWrite_P1_T obj_m; /* '<S2>/VENTRICLE_GROUND_CONTROL' */
  freedomk64f_DigitalWrite_P1_T obj_lh;/* '<S2>/PACE_GROUND_CONTROL' */
  freedomk64f_DigitalWrite_P1_T obj_o; /* '<S2>/PACE_CHARGE_CONTROL' */
  freedomk64f_DigitalWrite_P1_T obj_h0;/* '<S2>/ATRIAL_PACE_CONTROL' */
  freedomk64f_DigitalWrite_P1_T obj_oh;/* '<S2>/ATRIAL_GROUND_CONTROL' */
  freedomk64f_DigitalWrite_P1_T obj_e; /* '<Root>/Digital Write' */
  freedomk64f_PWMOutput_P1_T obj_f;    /* '<Root>/PWM Output' */
  freedomk64f_PWMOutput_P1_T obj_c;    /* '<S2>/PACING_REF_PWM' */
  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<Root>/Scope' */

  struct {
    void *LoggedData;
  } Scope1_PWORK;                      /* '<Root>/Scope1' */

  uint32_T is_c1_P1;                   /* '<Root>/AOO,VOO,AAI,VVI StateFlows' */
  uint32_T temporalCounter_i1;         /* '<Root>/AOO,VOO,AAI,VVI StateFlows' */
  uint8_T is_active_c1_P1;             /* '<Root>/AOO,VOO,AAI,VVI StateFlows' */
} DW_P1_T;

/* Parameters (default storage) */
struct P_P1_T_ {
  real_T ATRIAL_CMP_DETECT_SampleTime; /* Expression: SampleTime
                                        * Referenced by: '<Root>/ATRIAL_CMP_DETECT'
                                        */
  real_T AnalogInput_SampleTime;       /* Expression: SampleTime
                                        * Referenced by: '<Root>/Analog Input'
                                        */
  real_T VENTRICLE_CMP_DETECT_SampleTime;/* Expression: SampleTime
                                          * Referenced by: '<Root>/VENTRICLE_CMP_DETECT'
                                          */
  real_T Constant1_Value;              /* Expression: 60
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T Constant_Value;               /* Expression: 3
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T Constant4_Value;              /* Expression: 1000
                                        * Referenced by: '<Root>/Constant4'
                                        */
  real_T Constant6_Value;              /* Expression: 60000
                                        * Referenced by: '<S3>/Constant6'
                                        */
  real_T LowerRateLimit_Value;         /* Expression: 60
                                        * Referenced by: '<S3>/LowerRateLimit'
                                        */
  real_T Constant3_Value;              /* Expression: 3
                                        * Referenced by: '<Root>/Constant3'
                                        */
  real_T Constant5_Value;              /* Expression: 1
                                        * Referenced by: '<Root>/Constant5'
                                        */
  real_T Constant6_Value_c;            /* Expression: 200
                                        * Referenced by: '<Root>/Constant6'
                                        */
  real_T Constant6_Value_e;            /* Expression: 60000
                                        * Referenced by: '<S4>/Constant6'
                                        */
  real_T UpperRateLimit_Value;         /* Expression: 60
                                        * Referenced by: '<S4>/UpperRateLimit'
                                        */
  real_T Constant8_Value;              /* Expression: 1
                                        * Referenced by: '<Root>/Constant8'
                                        */
  real_T Constant9_Value;              /* Expression: 60
                                        * Referenced by: '<Root>/Constant9'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_P1_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint8_T clockTick0;
    time_T stepSize0;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
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
 * Block '<Root>/Constant2' : Unused code path elimination
 * Block '<Root>/Constant7' : Unused code path elimination
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
 * '<S2>'   : 'P1/Output Pins'
 * '<S3>'   : 'P1/Subsystem'
 * '<S4>'   : 'P1/Subsystem1'
 */
#endif                                 /* RTW_HEADER_P1_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
