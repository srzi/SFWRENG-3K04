/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Group30_SFWR_Assignment1_SIMULINK.h
 *
 * Code generated for Simulink model 'Group30_SFWR_Assignment1_SIMULINK'.
 *
 * Model version                  : 1.100
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Thu Nov 24 17:43:38 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Group30_SFWR_Assignment1_SIMULINK_h_
#define RTW_HEADER_Group30_SFWR_Assignment1_SIMULINK_h_
#ifndef Group30_SFWR_Assignment1_SIMULINK_COMMON_INCLUDES_
#define Group30_SFWR_Assignment1_SIMULINK_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "MW_digitalIO.h"
#include "MW_PWM.h"
#include "MW_SCI.h"
#endif                  /* Group30_SFWR_Assignment1_SIMULINK_COMMON_INCLUDES_ */

#include "Group30_SFWR_Assignment1_SIMULINK_types.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"
#include <stddef.h>
#include "Transmit_DCM.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmStepTask
#define rtmStepTask(rtm, idx)          ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
#endif

#ifndef rtmTaskCounter
#define rtmTaskCounter(rtm, idx)       ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

#define Group30_SFWR_Assignment1_SIMULINK_M (Group30_SFWR_Assignment1_SIM_M)

/* Block signals (default storage) */
typedef struct {
  uint8_T RxData[16];
  uint8_T RxDataLocChar[16];
  uint32_T TxPinLoc;
  uint32_T SCIModuleLoc;
  MW_SCI_StopBits_Type StopBitsValue;
  uint16_T Atrial_Refractory_Period;
  uint16_T Ventricle_Refractory_Period;
  uint16_T Atrial_Refractory_Period_f; /* '<S4>/Serial Receive from the DCM' */
  uint16_T Ventricle_Refractory_Period_k;/* '<S4>/Serial Receive from the DCM' */
  uint8_T BytePack4[2];                /* '<S12>/Byte Pack4' */
  uint8_T BytePack5[2];                /* '<S12>/Byte Pack5' */
  uint8_T Atrial_Amplitude;            /* '<S4>/Serial Receive from the DCM' */
  uint8_T Atrial_PaceWidth;            /* '<S4>/Serial Receive from the DCM' */
  uint8_T Atrial_Sensitivity;          /* '<S4>/Serial Receive from the DCM' */
  uint8_T Lower_Rate_Limit;            /* '<S4>/Serial Receive from the DCM' */
  uint8_T Pace_Mode;                   /* '<S4>/Serial Receive from the DCM' */
  uint8_T Sensing_Control;             /* '<S4>/Serial Receive from the DCM' */
  uint8_T Upper_Rate_Limit;            /* '<S4>/Serial Receive from the DCM' */
  uint8_T Ventricle_Amplitude;         /* '<S4>/Serial Receive from the DCM' */
  uint8_T Ventricle_PaceWidth;         /* '<S4>/Serial Receive from the DCM' */
  uint8_T Ventricle_Sensitivity;       /* '<S4>/Serial Receive from the DCM' */
  uint8_T PACING_REF_PWM;              /* '<Root>/AOO,VOO,AAI,VVI StateFlows' */
  boolean_T PACE_CHARGE_CONTROL;       /* '<Root>/AOO,VOO,AAI,VVI StateFlows' */
  boolean_T Z_ATRIAL_CONTROL;          /* '<Root>/AOO,VOO,AAI,VVI StateFlows' */
  boolean_T Z_VENTRICLE_CONTROL;       /* '<Root>/AOO,VOO,AAI,VVI StateFlows' */
  boolean_T ATRIAL_PACE_CONTROL;       /* '<Root>/AOO,VOO,AAI,VVI StateFlows' */
  boolean_T VENTRICLE_PACE_CONTROL;    /* '<Root>/AOO,VOO,AAI,VVI StateFlows' */
  boolean_T PACE_GROUND_CONTROL;       /* '<Root>/AOO,VOO,AAI,VVI StateFlows' */
  boolean_T ATRIAL_GROUND_CONTROL;     /* '<Root>/AOO,VOO,AAI,VVI StateFlows' */
  boolean_T VENTRICLE_GROUND_CONTROL;  /* '<Root>/AOO,VOO,AAI,VVI StateFlows' */
  boolean_T FRONTEND_CTRL;             /* '<Root>/AOO,VOO,AAI,VVI StateFlows' */
} B_Group30_SFWR_Assignment1_SI_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  freedomk64f_DigitalRead_Group_T obj; /* '<S6>/VENTRICLE_CMP_DETECT' */
  freedomk64f_DigitalRead_Group_T obj_d;/* '<S6>/ATRIAL_CMP_DETECT' */
  freedomk64f_SCIRead_Group30_S_T obj_j;/* '<S4>/Serial Receive' */
  freedomk64f_PWMOutput_Group30_T obj_k;/* '<S9>/PACING_REF_PWM' */
  freedomk64f_PWMOutput_Group30_T obj_a;/* '<S6>/VENTRICLE_CMP_REF_PWM' */
  freedomk64f_PWMOutput_Group30_T obj_l;/* '<S6>/ATRIAL_CMP_RED_PWM' */
  freedomk64f_DigitalWrite_Grou_T obj_n;/* '<S9>/Z_VENTRICLE_CONTROL' */
  freedomk64f_DigitalWrite_Grou_T obj_lf;/* '<S9>/Z_ATRIAL_CONTROL' */
  freedomk64f_DigitalWrite_Grou_T obj_j1;/* '<S9>/VENTRICLE_PACE_CONTROL' */
  freedomk64f_DigitalWrite_Grou_T obj_m;/* '<S9>/VENTRICLE_GROUND_CONTROL' */
  freedomk64f_DigitalWrite_Grou_T obj_f;/* '<S9>/PACE_GROUND_CONTROL' */
  freedomk64f_DigitalWrite_Grou_T obj_jy;/* '<S9>/PACE_CHARGE_CONTROL' */
  freedomk64f_DigitalWrite_Grou_T obj_p;/* '<S9>/FRONTEND_CTRL' */
  freedomk64f_DigitalWrite_Grou_T obj_e;/* '<S9>/ATRIAL_PACE_CONTROL' */
  freedomk64f_DigitalWrite_Grou_T obj_pz;/* '<S9>/ATRIAL_GROUND_CONTROL' */
  freedomk64f_SCIWrite_Group30__T obj_ml;/* '<S12>/Serial Transmit' */
  uint32_T temporalCounter_i1;         /* '<Root>/AOO,VOO,AAI,VVI StateFlows' */
  uint8_T is_active_c2_Group30_SFWR_Assig;/* '<S4>/Serial Receive from the DCM' */
  uint8_T is_c2_Group30_SFWR_Assignment1_;/* '<S4>/Serial Receive from the DCM' */
  uint8_T is_active_c1_Group30_SFWR_Assig;/* '<Root>/AOO,VOO,AAI,VVI StateFlows' */
  uint8_T is_c1_Group30_SFWR_Assignment1_;/* '<Root>/AOO,VOO,AAI,VVI StateFlows' */
} DW_Group30_SFWR_Assignment1_S_T;

/* Parameters (default storage) */
struct P_Group30_SFWR_Assignment1_SI_T_ {
  real_T ATRIAL_CMP_DETECT_SampleTime; /* Expression: SampleTime
                                        * Referenced by: '<S6>/ATRIAL_CMP_DETECT'
                                        */
  real_T VENTRICLE_CMP_DETECT_SampleTime;/* Expression: SampleTime
                                          * Referenced by: '<S6>/VENTRICLE_CMP_DETECT'
                                          */
  real_T SerialReceive_SampleTime;     /* Expression: 0.1
                                        * Referenced by: '<S4>/Serial Receive'
                                        */
  real_T Constant6_Value;              /* Expression: 60000
                                        * Referenced by: '<S5>/Constant6'
                                        */
  real_T Constant6_Value_i;            /* Expression: 60000
                                        * Referenced by: '<S7>/Constant6'
                                        */
  real_T Constant_Value;               /* Expression: 10
                                        * Referenced by: '<S6>/Constant'
                                        */
  real_T Constant2_Value;              /* Expression: 5
                                        * Referenced by: '<S6>/Constant2'
                                        */
  real_T Multiply_Gain;                /* Expression: 100
                                        * Referenced by: '<S6>/Multiply'
                                        */
  real_T Constant1_Value;              /* Expression: 10
                                        * Referenced by: '<S6>/Constant1'
                                        */
  real_T Constant3_Value;              /* Expression: 5
                                        * Referenced by: '<S6>/Constant3'
                                        */
  real_T Multiply1_Gain;               /* Expression: 100
                                        * Referenced by: '<S6>/Multiply1'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_Group30_SFWR_Assignme_T {
  const char_T * volatile errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    struct {
      uint8_T TID[2];
    } TaskCounters;
  } Timing;
};

/* Block parameters (default storage) */
extern P_Group30_SFWR_Assignment1_SI_T Group30_SFWR_Assignment1_SIMU_P;

/* Block signals (default storage) */
extern B_Group30_SFWR_Assignment1_SI_T Group30_SFWR_Assignment1_SIMU_B;

/* Block states (default storage) */
extern DW_Group30_SFWR_Assignment1_S_T Group30_SFWR_Assignment1_SIM_DW;

/* External function called from main */
extern void Group30_SFWR_Assignment1_SIMULINK_SetEventsForThisBaseStep(boolean_T
  *eventFlags);

/* Model entry point functions */
extern void Group30_SFWR_Assignment1_SIMULINK_SetEventsForThisBaseStep(boolean_T
  *eventFlags);
extern void Group30_SFWR_Assignment1_SIMULINK_initialize(void);
extern void Group30_SFWR_Assignment1_SIMULINK_step0(void);
extern void Group30_SFWR_Assignment1_SIMULINK_step1(void);
extern void Group30_SFWR_Assignment1_SIMULINK_step(int_T tid);
extern void Group30_SFWR_Assignment1_SIMULINK_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Group30_SFWR_Assignm_T *const Group30_SFWR_Assignment1_SIM_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S6>/Cast To Boolean' : Eliminate redundant data type conversion
 * Block '<S6>/Cast To Boolean1' : Eliminate redundant data type conversion
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
 * '<Root>' : 'Group30_SFWR_Assignment1_SIMULINK'
 * '<S1>'   : 'Group30_SFWR_Assignment1_SIMULINK/AOO,VOO,AAI,VVI StateFlows'
 * '<S2>'   : 'Group30_SFWR_Assignment1_SIMULINK/Input Parameters1'
 * '<S3>'   : 'Group30_SFWR_Assignment1_SIMULINK/Output Pins and Requirements Table'
 * '<S4>'   : 'Group30_SFWR_Assignment1_SIMULINK/Serial Communication to//from DCM'
 * '<S5>'   : 'Group30_SFWR_Assignment1_SIMULINK/Input Parameters1/Lower Rate Interval'
 * '<S6>'   : 'Group30_SFWR_Assignment1_SIMULINK/Input Parameters1/Natural Heart Detection'
 * '<S7>'   : 'Group30_SFWR_Assignment1_SIMULINK/Input Parameters1/Upper Rate Interval'
 * '<S8>'   : 'Group30_SFWR_Assignment1_SIMULINK/Output Pins and Requirements Table/Requirements Table'
 * '<S9>'   : 'Group30_SFWR_Assignment1_SIMULINK/Output Pins and Requirements Table/Subsystem'
 * '<S10>'  : 'Group30_SFWR_Assignment1_SIMULINK/Output Pins and Requirements Table/Requirements Table/Requirements Table1'
 * '<S11>'  : 'Group30_SFWR_Assignment1_SIMULINK/Serial Communication to//from DCM/Serial Receive from the DCM'
 * '<S12>'  : 'Group30_SFWR_Assignment1_SIMULINK/Serial Communication to//from DCM/Serial Transmit to the DCM'
 */
#endif                     /* RTW_HEADER_Group30_SFWR_Assignment1_SIMULINK_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
