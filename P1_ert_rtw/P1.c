/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: P1.c
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

#include "P1.h"
#include "rtwtypes.h"
#include <math.h>
#include "P1_types.h"
#include "P1_private.h"
#include "P1_dt.h"

/* Named constants for Chart: '<Root>/AOO,VOO,AAI,VVI StateFlows' */
#define IN_Atrial_Pacing_by_DISCHARGING (2U)
#define IN_CHARGING_C22_AND_DISCHARGING (3U)
#define IN_CHARGING_C22_AND_DISCHARGI_b (6U)
#define IN_CHARGING_C22_AND_DISCHARGI_f (4U)
#define IN_CHARGING_C22_AND_DISCHARGI_o (5U)
#define P1_IN_Atrial_Pacing1           (1U)
#define P1_IN_Ventricle_Pacing         (7U)
#define P1_IN_Ventricle_Pacing1        (8U)
#define P1_IN_start                    (9U)

/* Block signals (default storage) */
B_P1_T P1_B;

/* Block states (default storage) */
DW_P1_T P1_DW;

/* Real-time model */
static RT_MODEL_P1_T P1_M_;
RT_MODEL_P1_T *const P1_M = &P1_M_;

/* Forward declaration for local functions */
static void enter_atomic_CHARGING_C22_AND_j(void);
static void enter_atomic_CHARGING_C22_AND_D(void);

/* Function for Chart: '<Root>/AOO,VOO,AAI,VVI StateFlows' */
static void enter_atomic_CHARGING_C22_AND_j(void)
{
  P1_B.PACE_CHARGE_CONTROL = true;
  P1_B.PACING_REF_PWM = P1_B.Constant1;
  P1_B.PACE_GROUND_CONTROL = true;
  P1_B.VENTRICLE_PACE_CONTROL = false;
  P1_B.Z_ATRIAL_CONTROL = false;
  P1_B.Z_VENTRICLE_CONTROL = false;
  P1_B.ATRIAL_PACE_CONTROL = false;
  P1_B.ATRIAL_GROUND_CONTROL = false;
  P1_B.VENTRICLE_GROUND_CONTROL = true;
}

/* Function for Chart: '<Root>/AOO,VOO,AAI,VVI StateFlows' */
static void enter_atomic_CHARGING_C22_AND_D(void)
{
  P1_B.PACE_CHARGE_CONTROL = true;
  P1_B.PACING_REF_PWM = P1_B.Constant1;
  P1_B.PACE_GROUND_CONTROL = true;
  P1_B.VENTRICLE_PACE_CONTROL = false;
  P1_B.Z_ATRIAL_CONTROL = false;
  P1_B.Z_VENTRICLE_CONTROL = false;
  P1_B.ATRIAL_PACE_CONTROL = false;
  P1_B.ATRIAL_GROUND_CONTROL = true;
  P1_B.VENTRICLE_GROUND_CONTROL = false;
}

/* Model step function */
void P1_step(void)
{
  /* Constant: '<Root>/Constant1' */
  P1_B.Constant1 = P1_P.Constant1_Value;

  /* Constant: '<Root>/Constant' */
  P1_B.Constant = P1_P.Constant_Value;

  /* Constant: '<Root>/Constant4' */
  P1_B.Constant4 = P1_P.Constant4_Value;

  /* MATLABSystem: '<Root>/ATRIAL_CMP_DETECT' */
  if (P1_DW.obj_l.SampleTime != P1_P.ATRIAL_CMP_DETECT_SampleTime) {
    P1_DW.obj_l.SampleTime = P1_P.ATRIAL_CMP_DETECT_SampleTime;
  }

  /* MATLABSystem: '<Root>/ATRIAL_CMP_DETECT' */
  P1_B.ATRIAL_CMP_DETECT = MW_digitalIO_read(P1_DW.obj_l.MW_DIGITALIO_HANDLE);

  /* MATLABSystem: '<Root>/VENTRICLE_CMP_DETECT' */
  if (P1_DW.obj.SampleTime != P1_P.VENTRICLE_CMP_DETECT_SampleTime) {
    P1_DW.obj.SampleTime = P1_P.VENTRICLE_CMP_DETECT_SampleTime;
  }

  /* MATLABSystem: '<Root>/VENTRICLE_CMP_DETECT' */
  P1_B.VENTRICLE_CMP_DETECT = MW_digitalIO_read(P1_DW.obj.MW_DIGITALIO_HANDLE);

  /* Product: '<S3>/Divide' incorporates:
   *  Constant: '<S3>/Constant6'
   *  Constant: '<S3>/LowerRateLimit'
   */
  P1_B.Divide = P1_P.Constant6_Value / P1_P.LowerRateLimit_Value;

  /* Constant: '<Root>/Constant3' */
  P1_B.Constant3 = P1_P.Constant3_Value;

  /* Constant: '<Root>/Constant5' */
  P1_B.Constant5 = P1_P.Constant5_Value;

  /* Constant: '<Root>/Constant6' */
  P1_B.Constant6 = P1_P.Constant6_Value_c;

  /* Product: '<S4>/Divide' incorporates:
   *  Constant: '<S4>/Constant6'
   *  Constant: '<S4>/UpperRateLimit'
   */
  P1_B.Divide_d = P1_P.Constant6_Value_e / P1_P.UpperRateLimit_Value;

  /* Chart: '<Root>/AOO,VOO,AAI,VVI StateFlows' */
  if (P1_DW.temporalCounter_i1 < MAX_uint32_T) {
    P1_DW.temporalCounter_i1++;
  }

  if (P1_DW.is_active_c1_P1 == 0U) {
    P1_DW.is_active_c1_P1 = 1U;
    P1_DW.is_c1_P1 = P1_IN_start;
  } else {
    switch (P1_DW.is_c1_P1) {
     case P1_IN_Atrial_Pacing1:
      P1_DW.is_c1_P1 = IN_CHARGING_C22_AND_DISCHARGI_o;
      P1_DW.temporalCounter_i1 = 0U;
      enter_atomic_CHARGING_C22_AND_D();
      break;

     case IN_Atrial_Pacing_by_DISCHARGING:
      P1_B.PACE_CHARGE_CONTROL = false;
      P1_B.PACE_GROUND_CONTROL = true;
      P1_B.ATRIAL_GROUND_CONTROL = false;
      P1_B.Z_ATRIAL_CONTROL = false;
      P1_B.Z_VENTRICLE_CONTROL = false;
      P1_B.VENTRICLE_GROUND_CONTROL = false;
      if (P1_DW.temporalCounter_i1 >= (uint32_T)ceil(P1_B.Constant5 / 1.0E+6 -
           1.0E-5)) {
        P1_DW.is_c1_P1 = IN_CHARGING_C22_AND_DISCHARGING;
        P1_DW.temporalCounter_i1 = 0U;
        enter_atomic_CHARGING_C22_AND_D();
      }
      break;

     case IN_CHARGING_C22_AND_DISCHARGING:
      P1_B.PACE_CHARGE_CONTROL = true;
      P1_B.PACE_GROUND_CONTROL = true;
      P1_B.Z_ATRIAL_CONTROL = false;
      P1_B.Z_VENTRICLE_CONTROL = false;
      P1_B.ATRIAL_GROUND_CONTROL = true;
      P1_B.VENTRICLE_GROUND_CONTROL = false;
      if (P1_DW.temporalCounter_i1 >= (uint32_T)ceil((P1_B.Constant4 -
            P1_B.Constant5) / 1.0E+6 - 1.0E-5)) {
        P1_DW.is_c1_P1 = IN_Atrial_Pacing_by_DISCHARGING;
        P1_DW.temporalCounter_i1 = 0U;
        P1_B.PACE_CHARGE_CONTROL = false;
        P1_B.ATRIAL_PACE_CONTROL = true;
        P1_B.ATRIAL_GROUND_CONTROL = false;
        P1_B.VENTRICLE_PACE_CONTROL = false;
      }
      break;

     case IN_CHARGING_C22_AND_DISCHARGI_f:
      P1_B.PACE_CHARGE_CONTROL = true;
      P1_B.PACE_GROUND_CONTROL = true;
      P1_B.Z_ATRIAL_CONTROL = false;
      P1_B.Z_VENTRICLE_CONTROL = false;
      P1_B.ATRIAL_GROUND_CONTROL = false;
      P1_B.VENTRICLE_GROUND_CONTROL = true;
      if (P1_DW.temporalCounter_i1 >= (uint32_T)ceil((P1_B.Constant4 -
            P1_B.Constant5) / 1.0E+6 - 1.0E-5)) {
        P1_DW.is_c1_P1 = P1_IN_Ventricle_Pacing;
        P1_DW.temporalCounter_i1 = 0U;
        P1_B.PACE_CHARGE_CONTROL = false;
        P1_B.ATRIAL_PACE_CONTROL = false;
        P1_B.VENTRICLE_GROUND_CONTROL = false;
        P1_B.VENTRICLE_PACE_CONTROL = true;
      }
      break;

     case IN_CHARGING_C22_AND_DISCHARGI_o:
      P1_B.PACE_CHARGE_CONTROL = true;
      P1_B.PACE_GROUND_CONTROL = true;
      P1_B.Z_ATRIAL_CONTROL = false;
      P1_B.Z_VENTRICLE_CONTROL = false;
      P1_B.ATRIAL_GROUND_CONTROL = true;
      P1_B.VENTRICLE_GROUND_CONTROL = false;
      if (P1_DW.temporalCounter_i1 >= (uint32_T)ceil(P1_B.Constant6 / 1.0E+6 -
           1.0E-5)) {
        if (P1_DW.temporalCounter_i1 >= (uint32_T)ceil((P1_B.Divide -
              P1_B.Constant6) / 1.0E+6 - 1.0E-5)) {
          P1_DW.is_c1_P1 = P1_IN_Atrial_Pacing1;
          P1_B.PACE_CHARGE_CONTROL = false;
          P1_B.ATRIAL_PACE_CONTROL = true;
          P1_B.ATRIAL_GROUND_CONTROL = false;
          P1_B.VENTRICLE_PACE_CONTROL = false;
        } else if (P1_B.ATRIAL_CMP_DETECT) {
          P1_DW.is_c1_P1 = IN_CHARGING_C22_AND_DISCHARGI_o;
          P1_DW.temporalCounter_i1 = 0U;
          enter_atomic_CHARGING_C22_AND_D();
        }
      }
      break;

     case IN_CHARGING_C22_AND_DISCHARGI_b:
      P1_B.PACE_CHARGE_CONTROL = true;
      P1_B.PACE_GROUND_CONTROL = true;
      P1_B.Z_ATRIAL_CONTROL = false;
      P1_B.Z_VENTRICLE_CONTROL = false;
      P1_B.ATRIAL_GROUND_CONTROL = false;
      P1_B.VENTRICLE_GROUND_CONTROL = true;
      if (P1_DW.temporalCounter_i1 >= (uint32_T)ceil(P1_B.Constant6 / 1.0E+6 -
           1.0E-5)) {
        if (P1_DW.temporalCounter_i1 >= (uint32_T)ceil((P1_B.Divide -
              P1_B.Constant6) / 1.0E+6 - 1.0E-5)) {
          P1_DW.is_c1_P1 = P1_IN_Ventricle_Pacing1;
          P1_B.PACE_CHARGE_CONTROL = false;
          P1_B.ATRIAL_PACE_CONTROL = false;
          P1_B.VENTRICLE_GROUND_CONTROL = false;
          P1_B.VENTRICLE_PACE_CONTROL = true;
        } else if (P1_B.VENTRICLE_CMP_DETECT) {
          P1_DW.is_c1_P1 = IN_CHARGING_C22_AND_DISCHARGI_b;
          P1_DW.temporalCounter_i1 = 0U;
          enter_atomic_CHARGING_C22_AND_j();
        }
      }
      break;

     case P1_IN_Ventricle_Pacing:
      P1_B.PACE_CHARGE_CONTROL = false;
      P1_B.PACE_GROUND_CONTROL = true;
      P1_B.ATRIAL_GROUND_CONTROL = false;
      P1_B.Z_ATRIAL_CONTROL = false;
      P1_B.Z_VENTRICLE_CONTROL = false;
      P1_B.VENTRICLE_GROUND_CONTROL = false;
      if (P1_DW.temporalCounter_i1 >= (uint32_T)ceil(P1_B.Constant5 / 1.0E+6 -
           1.0E-5)) {
        P1_DW.is_c1_P1 = IN_CHARGING_C22_AND_DISCHARGI_f;
        P1_DW.temporalCounter_i1 = 0U;
        enter_atomic_CHARGING_C22_AND_j();
      }
      break;

     case P1_IN_Ventricle_Pacing1:
      P1_DW.is_c1_P1 = IN_CHARGING_C22_AND_DISCHARGI_b;
      P1_DW.temporalCounter_i1 = 0U;
      enter_atomic_CHARGING_C22_AND_j();
      break;

     default:
      /* case IN_start: */
      if (P1_B.Constant == 1.0) {
        P1_DW.is_c1_P1 = IN_CHARGING_C22_AND_DISCHARGING;
        P1_DW.temporalCounter_i1 = 0U;
        enter_atomic_CHARGING_C22_AND_D();
      } else if (P1_B.Constant == 2.0) {
        P1_DW.is_c1_P1 = IN_CHARGING_C22_AND_DISCHARGI_f;
        P1_DW.temporalCounter_i1 = 0U;
        enter_atomic_CHARGING_C22_AND_j();
      } else if (P1_B.Constant == 3.0) {
        P1_DW.is_c1_P1 = IN_CHARGING_C22_AND_DISCHARGI_o;
        P1_DW.temporalCounter_i1 = 0U;
        enter_atomic_CHARGING_C22_AND_D();
      } else if (P1_B.Constant == 4.0) {
        P1_DW.is_c1_P1 = IN_CHARGING_C22_AND_DISCHARGI_b;
        P1_DW.temporalCounter_i1 = 0U;
        enter_atomic_CHARGING_C22_AND_j();
      }
      break;
    }
  }

  /* End of Chart: '<Root>/AOO,VOO,AAI,VVI StateFlows' */

  /* MATLABSystem: '<S2>/PACE_CHARGE_CONTROL' */
  MW_digitalIO_write(P1_DW.obj_o.MW_DIGITALIO_HANDLE, P1_B.PACE_CHARGE_CONTROL);

  /* MATLABSystem: '<S2>/Z_ATRIAL_CONTROL' */
  MW_digitalIO_write(P1_DW.obj_h.MW_DIGITALIO_HANDLE, P1_B.Z_ATRIAL_CONTROL);

  /* MATLABSystem: '<S2>/Z_VENTRICLE_CONTROL' */
  MW_digitalIO_write(P1_DW.obj_g.MW_DIGITALIO_HANDLE, P1_B.Z_VENTRICLE_CONTROL);

  /* MATLABSystem: '<S2>/ATRIAL_PACE_CONTROL' */
  MW_digitalIO_write(P1_DW.obj_h0.MW_DIGITALIO_HANDLE, P1_B.ATRIAL_PACE_CONTROL);

  /* MATLABSystem: '<S2>/VENTRICLE_PACE_CONTROL' */
  MW_digitalIO_write(P1_DW.obj_b.MW_DIGITALIO_HANDLE,
                     P1_B.VENTRICLE_PACE_CONTROL);

  /* MATLABSystem: '<S2>/PACE_GROUND_CONTROL' */
  MW_digitalIO_write(P1_DW.obj_lh.MW_DIGITALIO_HANDLE, P1_B.PACE_GROUND_CONTROL);

  /* MATLABSystem: '<S2>/ATRIAL_GROUND_CONTROL' */
  MW_digitalIO_write(P1_DW.obj_oh.MW_DIGITALIO_HANDLE,
                     P1_B.ATRIAL_GROUND_CONTROL);

  /* MATLABSystem: '<S2>/VENTRICLE_GROUND_CONTROL' */
  MW_digitalIO_write(P1_DW.obj_m.MW_DIGITALIO_HANDLE,
                     P1_B.VENTRICLE_GROUND_CONTROL);

  /* MATLABSystem: '<S2>/PACING_REF_PWM' */
  MW_PWM_SetDutyCycle(P1_DW.obj_c.MW_PWM_HANDLE, P1_B.PACING_REF_PWM);

  /* MATLABSystem: '<Root>/Analog Input' */
  if (P1_DW.obj_k.SampleTime != P1_P.AnalogInput_SampleTime) {
    P1_DW.obj_k.SampleTime = P1_P.AnalogInput_SampleTime;
  }

  MW_AnalogIn_Start(P1_DW.obj_k.MW_ANALOGIN_HANDLE);

  /* MATLABSystem: '<Root>/Analog Input' */
  MW_AnalogInSingle_ReadResult(P1_DW.obj_k.MW_ANALOGIN_HANDLE, &P1_B.AnalogInput,
    7);

  /* MATLABSystem: '<Root>/Digital Write' incorporates:
   *  Constant: '<Root>/Constant8'
   */
  MW_digitalIO_write(P1_DW.obj_e.MW_DIGITALIO_HANDLE, P1_P.Constant8_Value !=
                     0.0);

  /* MATLABSystem: '<Root>/PWM Output' incorporates:
   *  Constant: '<Root>/Constant9'
   */
  MW_PWM_SetDutyCycle(P1_DW.obj_f.MW_PWM_HANDLE, P1_P.Constant9_Value);

  /* External mode */
  rtExtModeUploadCheckTrigger(1);

  {                                    /* Sample time: [1000.0s, 0.0s] */
    rtExtModeUpload(0, (real_T)P1_M->Timing.taskTime0);
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [1000.0s, 0.0s] */
    if ((rtmGetTFinal(P1_M)!=-1) &&
        !((rtmGetTFinal(P1_M)-P1_M->Timing.taskTime0) > P1_M->Timing.taskTime0 *
          (DBL_EPSILON))) {
      rtmSetErrorStatus(P1_M, "Simulation finished");
    }

    if (rtmGetStopRequested(P1_M)) {
      rtmSetErrorStatus(P1_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  P1_M->Timing.taskTime0 =
    ((time_T)(++P1_M->Timing.clockTick0)) * P1_M->Timing.stepSize0;
}

/* Model initialize function */
void P1_initialize(void)
{
  /* Registration code */
  rtmSetTFinal(P1_M, 0.0);
  P1_M->Timing.stepSize0 = 1000.0;

  /* External mode info */
  P1_M->Sizes.checksums[0] = (2639625311U);
  P1_M->Sizes.checksums[1] = (3463251421U);
  P1_M->Sizes.checksums[2] = (3210315652U);
  P1_M->Sizes.checksums[3] = (335434527U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[16];
    P1_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    systemRan[7] = &rtAlwaysEnabled;
    systemRan[8] = &rtAlwaysEnabled;
    systemRan[9] = &rtAlwaysEnabled;
    systemRan[10] = &rtAlwaysEnabled;
    systemRan[11] = &rtAlwaysEnabled;
    systemRan[12] = &rtAlwaysEnabled;
    systemRan[13] = &rtAlwaysEnabled;
    systemRan[14] = &rtAlwaysEnabled;
    systemRan[15] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(P1_M->extModeInfo, &P1_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(P1_M->extModeInfo, P1_M->Sizes.checksums);
    rteiSetTPtr(P1_M->extModeInfo, rtmGetTPtr(P1_M));
  }

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    P1_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 22;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  {
    MW_AnalogIn_TriggerSource_Type trigger_val;
    freedomk64f_AnalogInput_P1_T *obj_2;
    freedomk64f_DigitalRead_P1_T *obj;
    freedomk64f_DigitalWrite_P1_T *obj_0;
    freedomk64f_PWMOutput_P1_T *obj_1;

    /* Start for Constant: '<Root>/Constant1' */
    P1_B.Constant1 = P1_P.Constant1_Value;

    /* Start for Constant: '<Root>/Constant' */
    P1_B.Constant = P1_P.Constant_Value;

    /* Start for Constant: '<Root>/Constant4' */
    P1_B.Constant4 = P1_P.Constant4_Value;

    /* Start for Constant: '<Root>/Constant3' */
    P1_B.Constant3 = P1_P.Constant3_Value;

    /* Start for Constant: '<Root>/Constant5' */
    P1_B.Constant5 = P1_P.Constant5_Value;

    /* Start for Constant: '<Root>/Constant6' */
    P1_B.Constant6 = P1_P.Constant6_Value_c;

    /* Start for MATLABSystem: '<Root>/ATRIAL_CMP_DETECT' */
    P1_DW.obj_l.matlabCodegenIsDeleted = true;
    P1_DW.obj_l.isInitialized = 0;
    P1_DW.obj_l.SampleTime = -1.0;
    P1_DW.obj_l.matlabCodegenIsDeleted = false;
    P1_DW.obj_l.SampleTime = P1_P.ATRIAL_CMP_DETECT_SampleTime;
    obj = &P1_DW.obj_l;
    P1_DW.obj_l.isSetupComplete = false;
    P1_DW.obj_l.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(0U, 0);
    P1_DW.obj_l.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/VENTRICLE_CMP_DETECT' */
    P1_DW.obj.matlabCodegenIsDeleted = true;
    P1_DW.obj.isInitialized = 0;
    P1_DW.obj.SampleTime = -1.0;
    P1_DW.obj.matlabCodegenIsDeleted = false;
    P1_DW.obj.SampleTime = P1_P.VENTRICLE_CMP_DETECT_SampleTime;
    obj = &P1_DW.obj;
    P1_DW.obj.isSetupComplete = false;
    P1_DW.obj.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(1U, 0);
    P1_DW.obj.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/PACE_CHARGE_CONTROL' */
    P1_DW.obj_o.matlabCodegenIsDeleted = true;
    P1_DW.obj_o.isInitialized = 0;
    P1_DW.obj_o.matlabCodegenIsDeleted = false;
    obj_0 = &P1_DW.obj_o;
    P1_DW.obj_o.isSetupComplete = false;
    P1_DW.obj_o.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(2U, 1);
    P1_DW.obj_o.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/Z_ATRIAL_CONTROL' */
    P1_DW.obj_h.matlabCodegenIsDeleted = true;
    P1_DW.obj_h.isInitialized = 0;
    P1_DW.obj_h.matlabCodegenIsDeleted = false;
    obj_0 = &P1_DW.obj_h;
    P1_DW.obj_h.isSetupComplete = false;
    P1_DW.obj_h.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(4U, 1);
    P1_DW.obj_h.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/Z_VENTRICLE_CONTROL' */
    P1_DW.obj_g.matlabCodegenIsDeleted = true;
    P1_DW.obj_g.isInitialized = 0;
    P1_DW.obj_g.matlabCodegenIsDeleted = false;
    obj_0 = &P1_DW.obj_g;
    P1_DW.obj_g.isSetupComplete = false;
    P1_DW.obj_g.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(7U, 1);
    P1_DW.obj_g.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/ATRIAL_PACE_CONTROL' */
    P1_DW.obj_h0.matlabCodegenIsDeleted = true;
    P1_DW.obj_h0.isInitialized = 0;
    P1_DW.obj_h0.matlabCodegenIsDeleted = false;
    obj_0 = &P1_DW.obj_h0;
    P1_DW.obj_h0.isSetupComplete = false;
    P1_DW.obj_h0.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(8U, 1);
    P1_DW.obj_h0.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/VENTRICLE_PACE_CONTROL' */
    P1_DW.obj_b.matlabCodegenIsDeleted = true;
    P1_DW.obj_b.isInitialized = 0;
    P1_DW.obj_b.matlabCodegenIsDeleted = false;
    obj_0 = &P1_DW.obj_b;
    P1_DW.obj_b.isSetupComplete = false;
    P1_DW.obj_b.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(9U, 1);
    P1_DW.obj_b.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/PACE_GROUND_CONTROL' */
    P1_DW.obj_lh.matlabCodegenIsDeleted = true;
    P1_DW.obj_lh.isInitialized = 0;
    P1_DW.obj_lh.matlabCodegenIsDeleted = false;
    obj_0 = &P1_DW.obj_lh;
    P1_DW.obj_lh.isSetupComplete = false;
    P1_DW.obj_lh.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(10U, 1);
    P1_DW.obj_lh.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/ATRIAL_GROUND_CONTROL' */
    P1_DW.obj_oh.matlabCodegenIsDeleted = true;
    P1_DW.obj_oh.isInitialized = 0;
    P1_DW.obj_oh.matlabCodegenIsDeleted = false;
    obj_0 = &P1_DW.obj_oh;
    P1_DW.obj_oh.isSetupComplete = false;
    P1_DW.obj_oh.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(11U, 1);
    P1_DW.obj_oh.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/VENTRICLE_GROUND_CONTROL' */
    P1_DW.obj_m.matlabCodegenIsDeleted = true;
    P1_DW.obj_m.isInitialized = 0;
    P1_DW.obj_m.matlabCodegenIsDeleted = false;
    obj_0 = &P1_DW.obj_m;
    P1_DW.obj_m.isSetupComplete = false;
    P1_DW.obj_m.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(12U, 1);
    P1_DW.obj_m.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/PACING_REF_PWM' */
    P1_DW.obj_c.matlabCodegenIsDeleted = true;
    P1_DW.obj_c.isInitialized = 0;
    P1_DW.obj_c.matlabCodegenIsDeleted = false;
    obj_1 = &P1_DW.obj_c;
    P1_DW.obj_c.isSetupComplete = false;
    P1_DW.obj_c.isInitialized = 1;
    obj_1->MW_PWM_HANDLE = MW_PWM_Open(5U, 2000.0, 60.0);
    MW_PWM_Start(P1_DW.obj_c.MW_PWM_HANDLE);
    P1_DW.obj_c.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Analog Input' */
    P1_DW.obj_k.matlabCodegenIsDeleted = true;
    P1_DW.obj_k.isInitialized = 0;
    P1_DW.obj_k.SampleTime = -1.0;
    P1_DW.obj_k.matlabCodegenIsDeleted = false;
    P1_DW.obj_k.SampleTime = P1_P.AnalogInput_SampleTime;
    obj_2 = &P1_DW.obj_k;
    P1_DW.obj_k.isSetupComplete = false;
    P1_DW.obj_k.isInitialized = 1;
    obj_2->MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(19U);
    trigger_val = MW_ANALOGIN_SOFTWARE_TRIGGER;
    MW_AnalogIn_SetTriggerSource(P1_DW.obj_k.MW_ANALOGIN_HANDLE, trigger_val, 0U);
    P1_DW.obj_k.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Write' */
    P1_DW.obj_e.matlabCodegenIsDeleted = true;
    P1_DW.obj_e.isInitialized = 0;
    P1_DW.obj_e.matlabCodegenIsDeleted = false;
    obj_0 = &P1_DW.obj_e;
    P1_DW.obj_e.isSetupComplete = false;
    P1_DW.obj_e.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(13U, 1);
    P1_DW.obj_e.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/PWM Output' */
    P1_DW.obj_f.matlabCodegenIsDeleted = true;
    P1_DW.obj_f.isInitialized = 0;
    P1_DW.obj_f.matlabCodegenIsDeleted = false;
    obj_1 = &P1_DW.obj_f;
    P1_DW.obj_f.isSetupComplete = false;
    P1_DW.obj_f.isInitialized = 1;
    obj_1->MW_PWM_HANDLE = MW_PWM_Open(6U, 2000.0, 60.0);
    MW_PWM_Start(P1_DW.obj_f.MW_PWM_HANDLE);
    P1_DW.obj_f.isSetupComplete = true;
  }
}

/* Model terminate function */
void P1_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/ATRIAL_CMP_DETECT' */
  if (!P1_DW.obj_l.matlabCodegenIsDeleted) {
    P1_DW.obj_l.matlabCodegenIsDeleted = true;
    if ((P1_DW.obj_l.isInitialized == 1) && P1_DW.obj_l.isSetupComplete) {
      MW_digitalIO_close(P1_DW.obj_l.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/ATRIAL_CMP_DETECT' */

  /* Terminate for MATLABSystem: '<Root>/VENTRICLE_CMP_DETECT' */
  if (!P1_DW.obj.matlabCodegenIsDeleted) {
    P1_DW.obj.matlabCodegenIsDeleted = true;
    if ((P1_DW.obj.isInitialized == 1) && P1_DW.obj.isSetupComplete) {
      MW_digitalIO_close(P1_DW.obj.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/VENTRICLE_CMP_DETECT' */

  /* Terminate for MATLABSystem: '<S2>/PACE_CHARGE_CONTROL' */
  if (!P1_DW.obj_o.matlabCodegenIsDeleted) {
    P1_DW.obj_o.matlabCodegenIsDeleted = true;
    if ((P1_DW.obj_o.isInitialized == 1) && P1_DW.obj_o.isSetupComplete) {
      MW_digitalIO_close(P1_DW.obj_o.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/PACE_CHARGE_CONTROL' */

  /* Terminate for MATLABSystem: '<S2>/Z_ATRIAL_CONTROL' */
  if (!P1_DW.obj_h.matlabCodegenIsDeleted) {
    P1_DW.obj_h.matlabCodegenIsDeleted = true;
    if ((P1_DW.obj_h.isInitialized == 1) && P1_DW.obj_h.isSetupComplete) {
      MW_digitalIO_close(P1_DW.obj_h.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/Z_ATRIAL_CONTROL' */

  /* Terminate for MATLABSystem: '<S2>/Z_VENTRICLE_CONTROL' */
  if (!P1_DW.obj_g.matlabCodegenIsDeleted) {
    P1_DW.obj_g.matlabCodegenIsDeleted = true;
    if ((P1_DW.obj_g.isInitialized == 1) && P1_DW.obj_g.isSetupComplete) {
      MW_digitalIO_close(P1_DW.obj_g.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/Z_VENTRICLE_CONTROL' */

  /* Terminate for MATLABSystem: '<S2>/ATRIAL_PACE_CONTROL' */
  if (!P1_DW.obj_h0.matlabCodegenIsDeleted) {
    P1_DW.obj_h0.matlabCodegenIsDeleted = true;
    if ((P1_DW.obj_h0.isInitialized == 1) && P1_DW.obj_h0.isSetupComplete) {
      MW_digitalIO_close(P1_DW.obj_h0.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/ATRIAL_PACE_CONTROL' */

  /* Terminate for MATLABSystem: '<S2>/VENTRICLE_PACE_CONTROL' */
  if (!P1_DW.obj_b.matlabCodegenIsDeleted) {
    P1_DW.obj_b.matlabCodegenIsDeleted = true;
    if ((P1_DW.obj_b.isInitialized == 1) && P1_DW.obj_b.isSetupComplete) {
      MW_digitalIO_close(P1_DW.obj_b.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/VENTRICLE_PACE_CONTROL' */

  /* Terminate for MATLABSystem: '<S2>/PACE_GROUND_CONTROL' */
  if (!P1_DW.obj_lh.matlabCodegenIsDeleted) {
    P1_DW.obj_lh.matlabCodegenIsDeleted = true;
    if ((P1_DW.obj_lh.isInitialized == 1) && P1_DW.obj_lh.isSetupComplete) {
      MW_digitalIO_close(P1_DW.obj_lh.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/PACE_GROUND_CONTROL' */

  /* Terminate for MATLABSystem: '<S2>/ATRIAL_GROUND_CONTROL' */
  if (!P1_DW.obj_oh.matlabCodegenIsDeleted) {
    P1_DW.obj_oh.matlabCodegenIsDeleted = true;
    if ((P1_DW.obj_oh.isInitialized == 1) && P1_DW.obj_oh.isSetupComplete) {
      MW_digitalIO_close(P1_DW.obj_oh.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/ATRIAL_GROUND_CONTROL' */

  /* Terminate for MATLABSystem: '<S2>/VENTRICLE_GROUND_CONTROL' */
  if (!P1_DW.obj_m.matlabCodegenIsDeleted) {
    P1_DW.obj_m.matlabCodegenIsDeleted = true;
    if ((P1_DW.obj_m.isInitialized == 1) && P1_DW.obj_m.isSetupComplete) {
      MW_digitalIO_close(P1_DW.obj_m.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/VENTRICLE_GROUND_CONTROL' */

  /* Terminate for MATLABSystem: '<S2>/PACING_REF_PWM' */
  if (!P1_DW.obj_c.matlabCodegenIsDeleted) {
    P1_DW.obj_c.matlabCodegenIsDeleted = true;
    if ((P1_DW.obj_c.isInitialized == 1) && P1_DW.obj_c.isSetupComplete) {
      MW_PWM_Stop(P1_DW.obj_c.MW_PWM_HANDLE);
      MW_PWM_Close(P1_DW.obj_c.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/PACING_REF_PWM' */

  /* Terminate for MATLABSystem: '<Root>/Analog Input' */
  if (!P1_DW.obj_k.matlabCodegenIsDeleted) {
    P1_DW.obj_k.matlabCodegenIsDeleted = true;
    if ((P1_DW.obj_k.isInitialized == 1) && P1_DW.obj_k.isSetupComplete) {
      MW_AnalogIn_Stop(P1_DW.obj_k.MW_ANALOGIN_HANDLE);
      MW_AnalogIn_Close(P1_DW.obj_k.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Analog Input' */

  /* Terminate for MATLABSystem: '<Root>/Digital Write' */
  if (!P1_DW.obj_e.matlabCodegenIsDeleted) {
    P1_DW.obj_e.matlabCodegenIsDeleted = true;
    if ((P1_DW.obj_e.isInitialized == 1) && P1_DW.obj_e.isSetupComplete) {
      MW_digitalIO_close(P1_DW.obj_e.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Write' */

  /* Terminate for MATLABSystem: '<Root>/PWM Output' */
  if (!P1_DW.obj_f.matlabCodegenIsDeleted) {
    P1_DW.obj_f.matlabCodegenIsDeleted = true;
    if ((P1_DW.obj_f.isInitialized == 1) && P1_DW.obj_f.isSetupComplete) {
      MW_PWM_Stop(P1_DW.obj_f.MW_PWM_HANDLE);
      MW_PWM_Close(P1_DW.obj_f.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/PWM Output' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
