/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: P1.c
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

#include "P1.h"
#include "rtwtypes.h"
#include <math.h>
#include "P1_types.h"

/* Named constants for Chart: '<Root>/AOO,VOO,AAI,VVI StateFlows' */
#define P1_IN_PACE_Charge_Atrial       ((uint8_T)1U)
#define P1_IN_PACE_Charge_Ventricle    ((uint8_T)2U)
#define P1_IN_PACE_Discharge_Atrial    ((uint8_T)3U)
#define P1_IN_PACE_Discharge_Ventricle ((uint8_T)4U)
#define P1_IN_SENSE_Atrial             ((uint8_T)5U)
#define P1_IN_SENSE_Ventricle          ((uint8_T)6U)
#define P1_IN_init_state               ((uint8_T)7U)

/* Block signals (default storage) */
B_P1_T P1_B;

/* Block states (default storage) */
DW_P1_T P1_DW;

/* Real-time model */
static RT_MODEL_P1_T P1_M_;
RT_MODEL_P1_T *const P1_M = &P1_M_;

/* Model step function */
void P1_step(void)
{
  real_T tmp;
  boolean_T rtb_ATRIAL_CMP_DETECT_0;
  boolean_T rtb_VENTRICLE_CMP_DETECT_0;

  /* MATLABSystem: '<S2>/ATRIAL_CMP_DETECT' */
  if (P1_DW.obj_l.SampleTime != P1_P.ATRIAL_CMP_DETECT_SampleTime) {
    P1_DW.obj_l.SampleTime = P1_P.ATRIAL_CMP_DETECT_SampleTime;
  }

  rtb_ATRIAL_CMP_DETECT_0 = MW_digitalIO_read(P1_DW.obj_l.MW_DIGITALIO_HANDLE);

  /* MATLABSystem: '<S2>/VENTRICLE_CMP_DETECT' */
  if (P1_DW.obj.SampleTime != P1_P.VENTRICLE_CMP_DETECT_SampleTime) {
    P1_DW.obj.SampleTime = P1_P.VENTRICLE_CMP_DETECT_SampleTime;
  }

  rtb_VENTRICLE_CMP_DETECT_0 = MW_digitalIO_read(P1_DW.obj.MW_DIGITALIO_HANDLE);

  /* Chart: '<Root>/AOO,VOO,AAI,VVI StateFlows' incorporates:
   *  Constant: '<Root>/PACE_WIDTH'
   *  Constant: '<Root>/PERIOD'
   *  Constant: '<Root>/P_ARP'
   *  Constant: '<Root>/P_VRP'
   *  Constant: '<Root>/Pace_Type'
   *  Constant: '<Root>/Sensing_Control'
   *  Constant: '<Root>/duty_cycle'
   *  Constant: '<S4>/Constant6'
   *  Constant: '<S4>/LowerRateLimit'
   *  MATLABSystem: '<S2>/ATRIAL_CMP_DETECT'
   *  MATLABSystem: '<S2>/VENTRICLE_CMP_DETECT'
   *  Product: '<S4>/Divide'
   */
  if (P1_DW.temporalCounter_i1 < MAX_uint32_T) {
    P1_DW.temporalCounter_i1++;
  }

  if (P1_DW.is_active_c1_P1 == 0U) {
    P1_DW.is_active_c1_P1 = 1U;
    P1_DW.is_c1_P1 = P1_IN_init_state;
    P1_B.PACING_REF_PWM = P1_P.duty_cycle_Value;
    P1_B.Z_ATRIAL_CONTROL = false;
    P1_B.Z_VENTRICLE_CONTROL = false;
    P1_B.PACE_GROUND_CONTROL = true;
  } else {
    switch (P1_DW.is_c1_P1) {
     case P1_IN_PACE_Charge_Atrial:
      P1_B.PACE_CHARGE_CONTROL = true;
      P1_B.VENTRICLE_PACE_CONTROL = false;
      P1_B.VENTRICLE_GROUND_CONTROL = false;
      P1_B.ATRIAL_PACE_CONTROL = false;
      P1_B.ATRIAL_GROUND_CONTROL = true;
      if ((P1_DW.temporalCounter_i1 >= (uint32_T)ceil(P1_P.P_ARP_Value)) &&
          (P1_P.Sensing_Control_Value == 1.0)) {
        P1_DW.is_c1_P1 = P1_IN_SENSE_Atrial;
        P1_DW.temporalCounter_i1 = 0U;
      } else if ((P1_DW.temporalCounter_i1 >= (uint32_T)ceil(P1_P.PERIOD_Value -
        P1_P.PACE_WIDTH_Value)) && (P1_P.Sensing_Control_Value == 0.0)) {
        P1_DW.is_c1_P1 = P1_IN_PACE_Discharge_Atrial;
        P1_DW.temporalCounter_i1 = 0U;
        P1_B.PACE_CHARGE_CONTROL = false;
        P1_B.ATRIAL_PACE_CONTROL = true;
        P1_B.ATRIAL_GROUND_CONTROL = false;
      }
      break;

     case P1_IN_PACE_Charge_Ventricle:
      P1_B.PACE_CHARGE_CONTROL = true;
      P1_B.VENTRICLE_PACE_CONTROL = false;
      P1_B.VENTRICLE_GROUND_CONTROL = true;
      P1_B.ATRIAL_PACE_CONTROL = false;
      P1_B.ATRIAL_GROUND_CONTROL = false;
      if ((P1_DW.temporalCounter_i1 >= (uint32_T)ceil(P1_P.P_VRP_Value)) &&
          (P1_P.Sensing_Control_Value == 1.0)) {
        P1_DW.is_c1_P1 = P1_IN_SENSE_Ventricle;
        P1_DW.temporalCounter_i1 = 0U;
      } else if ((P1_DW.temporalCounter_i1 >= (uint32_T)ceil(P1_P.PERIOD_Value -
        P1_P.PACE_WIDTH_Value)) && (P1_P.Sensing_Control_Value == 0.0)) {
        P1_DW.is_c1_P1 = P1_IN_PACE_Discharge_Ventricle;
        P1_DW.temporalCounter_i1 = 0U;
        P1_B.PACE_CHARGE_CONTROL = false;
        P1_B.VENTRICLE_PACE_CONTROL = true;
        P1_B.VENTRICLE_GROUND_CONTROL = false;
      }
      break;

     case P1_IN_PACE_Discharge_Atrial:
      P1_B.PACE_CHARGE_CONTROL = false;
      P1_B.ATRIAL_PACE_CONTROL = true;
      P1_B.ATRIAL_GROUND_CONTROL = false;
      if (P1_DW.temporalCounter_i1 >= (uint32_T)ceil(P1_P.PACE_WIDTH_Value)) {
        P1_DW.is_c1_P1 = P1_IN_PACE_Charge_Atrial;
        P1_DW.temporalCounter_i1 = 0U;
        P1_B.PACE_CHARGE_CONTROL = true;
        P1_B.VENTRICLE_PACE_CONTROL = false;
        P1_B.VENTRICLE_GROUND_CONTROL = false;
        P1_B.ATRIAL_PACE_CONTROL = false;
        P1_B.ATRIAL_GROUND_CONTROL = true;
      }
      break;

     case P1_IN_PACE_Discharge_Ventricle:
      P1_B.PACE_CHARGE_CONTROL = false;
      P1_B.VENTRICLE_PACE_CONTROL = true;
      P1_B.VENTRICLE_GROUND_CONTROL = false;
      if (P1_DW.temporalCounter_i1 >= (uint32_T)ceil(P1_P.PACE_WIDTH_Value)) {
        P1_DW.is_c1_P1 = P1_IN_PACE_Charge_Ventricle;
        P1_DW.temporalCounter_i1 = 0U;
        P1_B.PACE_CHARGE_CONTROL = true;
        P1_B.VENTRICLE_PACE_CONTROL = false;
        P1_B.VENTRICLE_GROUND_CONTROL = true;
        P1_B.ATRIAL_PACE_CONTROL = false;
        P1_B.ATRIAL_GROUND_CONTROL = false;
      }
      break;

     case P1_IN_SENSE_Atrial:
      if ((P1_DW.temporalCounter_i1 >= (uint32_T)ceil(P1_P.Constant6_Value /
            P1_P.LowerRateLimit_Value - P1_P.P_ARP_Value)) &&
          (!rtb_ATRIAL_CMP_DETECT_0)) {
        P1_DW.is_c1_P1 = P1_IN_PACE_Discharge_Atrial;
        P1_DW.temporalCounter_i1 = 0U;
        P1_B.PACE_CHARGE_CONTROL = false;
        P1_B.ATRIAL_PACE_CONTROL = true;
        P1_B.ATRIAL_GROUND_CONTROL = false;
      } else if (rtb_ATRIAL_CMP_DETECT_0) {
        P1_DW.is_c1_P1 = P1_IN_SENSE_Atrial;
        P1_DW.temporalCounter_i1 = 0U;
      }
      break;

     case P1_IN_SENSE_Ventricle:
      if ((P1_DW.temporalCounter_i1 >= (uint32_T)ceil(P1_P.Constant6_Value /
            P1_P.LowerRateLimit_Value - P1_P.P_VRP_Value)) &&
          (!rtb_VENTRICLE_CMP_DETECT_0)) {
        P1_DW.is_c1_P1 = P1_IN_PACE_Discharge_Ventricle;
        P1_DW.temporalCounter_i1 = 0U;
        P1_B.PACE_CHARGE_CONTROL = false;
        P1_B.VENTRICLE_PACE_CONTROL = true;
        P1_B.VENTRICLE_GROUND_CONTROL = false;
      } else if (rtb_VENTRICLE_CMP_DETECT_0) {
        P1_DW.is_c1_P1 = P1_IN_SENSE_Ventricle;
        P1_DW.temporalCounter_i1 = 0U;
      }
      break;

     default:
      /* case IN_init_state: */
      P1_B.Z_ATRIAL_CONTROL = false;
      P1_B.Z_VENTRICLE_CONTROL = false;
      P1_B.PACE_GROUND_CONTROL = true;
      if (P1_P.Pace_Type_Value == 1.0) {
        P1_DW.is_c1_P1 = P1_IN_PACE_Charge_Atrial;
        P1_DW.temporalCounter_i1 = 0U;
        P1_B.PACE_CHARGE_CONTROL = true;
        P1_B.VENTRICLE_PACE_CONTROL = false;
        P1_B.VENTRICLE_GROUND_CONTROL = false;
        P1_B.ATRIAL_PACE_CONTROL = false;
        P1_B.ATRIAL_GROUND_CONTROL = true;
      } else if (P1_P.Pace_Type_Value == 0.0) {
        P1_DW.is_c1_P1 = P1_IN_PACE_Charge_Ventricle;
        P1_DW.temporalCounter_i1 = 0U;
        P1_B.PACE_CHARGE_CONTROL = true;
        P1_B.VENTRICLE_PACE_CONTROL = false;
        P1_B.VENTRICLE_GROUND_CONTROL = true;
        P1_B.ATRIAL_PACE_CONTROL = false;
        P1_B.ATRIAL_GROUND_CONTROL = false;
      }
      break;
    }
  }

  /* End of Chart: '<Root>/AOO,VOO,AAI,VVI StateFlows' */

  /* MATLABSystem: '<S3>/PACE_CHARGE_CONTROL' */
  MW_digitalIO_write(P1_DW.obj_o.MW_DIGITALIO_HANDLE, P1_B.PACE_CHARGE_CONTROL);

  /* MATLABSystem: '<S3>/Z_ATRIAL_CONTROL' */
  MW_digitalIO_write(P1_DW.obj_h.MW_DIGITALIO_HANDLE, P1_B.Z_ATRIAL_CONTROL);

  /* MATLABSystem: '<S3>/Z_VENTRICLE_CONTROL' */
  MW_digitalIO_write(P1_DW.obj_g.MW_DIGITALIO_HANDLE, P1_B.Z_VENTRICLE_CONTROL);

  /* MATLABSystem: '<S3>/ATRIAL_PACE_CONTROL' */
  MW_digitalIO_write(P1_DW.obj_h0.MW_DIGITALIO_HANDLE, P1_B.ATRIAL_PACE_CONTROL);

  /* MATLABSystem: '<S3>/VENTRICLE_PACE_CONTROL' */
  MW_digitalIO_write(P1_DW.obj_b.MW_DIGITALIO_HANDLE,
                     P1_B.VENTRICLE_PACE_CONTROL);

  /* MATLABSystem: '<S3>/PACE_GROUND_CONTROL' */
  MW_digitalIO_write(P1_DW.obj_lh.MW_DIGITALIO_HANDLE, P1_B.PACE_GROUND_CONTROL);

  /* MATLABSystem: '<S3>/ATRIAL_GROUND_CONTROL' */
  MW_digitalIO_write(P1_DW.obj_oh.MW_DIGITALIO_HANDLE,
                     P1_B.ATRIAL_GROUND_CONTROL);

  /* MATLABSystem: '<S3>/VENTRICLE_GROUND_CONTROL' */
  MW_digitalIO_write(P1_DW.obj_m.MW_DIGITALIO_HANDLE,
                     P1_B.VENTRICLE_GROUND_CONTROL);

  /* MATLABSystem: '<S3>/PACING_REF_PWM' */
  MW_PWM_SetDutyCycle(P1_DW.obj_c.MW_PWM_HANDLE, P1_B.PACING_REF_PWM);

  /* MATLABSystem: '<S2>/ATRIAL_CMP_RED_PWM' incorporates:
   *  Constant: '<S2>/Constant9'
   */
  MW_PWM_SetDutyCycle(P1_DW.obj_f.MW_PWM_HANDLE, P1_P.Constant9_Value);

  /* MATLABSystem: '<S2>/Analog Input' */
  if (P1_DW.obj_n.SampleTime != P1_P.AnalogInput_SampleTime) {
    P1_DW.obj_n.SampleTime = P1_P.AnalogInput_SampleTime;
  }

  MW_AnalogIn_Start(P1_DW.obj_n.MW_ANALOGIN_HANDLE);
  MW_AnalogInSingle_ReadResult(P1_DW.obj_n.MW_ANALOGIN_HANDLE, &tmp, 7);

  /* End of MATLABSystem: '<S2>/Analog Input' */

  /* MATLABSystem: '<S2>/VENTRICLE_CMP_REF_PWM' incorporates:
   *  Constant: '<S2>/Constant2'
   */
  MW_PWM_SetDutyCycle(P1_DW.obj_a.MW_PWM_HANDLE, P1_P.Constant2_Value);

  /* MATLABSystem: '<S2>/FRONTEND_CTRL' incorporates:
   *  Constant: '<S2>/Constant8'
   */
  MW_digitalIO_write(P1_DW.obj_e.MW_DIGITALIO_HANDLE, P1_P.Constant8_Value !=
                     0.0);
}

/* Model initialize function */
void P1_initialize(void)
{
  {
    MW_AnalogIn_TriggerSource_Type trigger_val;
    freedomk64f_AnalogInput_P1_T *obj_2;
    freedomk64f_DigitalRead_P1_T *obj;
    freedomk64f_DigitalWrite_P1_T *obj_0;
    freedomk64f_PWMOutput_P1_T *obj_1;

    /* Start for MATLABSystem: '<S2>/ATRIAL_CMP_DETECT' */
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

    /* Start for MATLABSystem: '<S2>/VENTRICLE_CMP_DETECT' */
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

    /* Start for MATLABSystem: '<S3>/PACE_CHARGE_CONTROL' */
    P1_DW.obj_o.matlabCodegenIsDeleted = true;
    P1_DW.obj_o.isInitialized = 0;
    P1_DW.obj_o.matlabCodegenIsDeleted = false;
    obj_0 = &P1_DW.obj_o;
    P1_DW.obj_o.isSetupComplete = false;
    P1_DW.obj_o.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(2U, 1);
    P1_DW.obj_o.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/Z_ATRIAL_CONTROL' */
    P1_DW.obj_h.matlabCodegenIsDeleted = true;
    P1_DW.obj_h.isInitialized = 0;
    P1_DW.obj_h.matlabCodegenIsDeleted = false;
    obj_0 = &P1_DW.obj_h;
    P1_DW.obj_h.isSetupComplete = false;
    P1_DW.obj_h.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(4U, 1);
    P1_DW.obj_h.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/Z_VENTRICLE_CONTROL' */
    P1_DW.obj_g.matlabCodegenIsDeleted = true;
    P1_DW.obj_g.isInitialized = 0;
    P1_DW.obj_g.matlabCodegenIsDeleted = false;
    obj_0 = &P1_DW.obj_g;
    P1_DW.obj_g.isSetupComplete = false;
    P1_DW.obj_g.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(7U, 1);
    P1_DW.obj_g.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/ATRIAL_PACE_CONTROL' */
    P1_DW.obj_h0.matlabCodegenIsDeleted = true;
    P1_DW.obj_h0.isInitialized = 0;
    P1_DW.obj_h0.matlabCodegenIsDeleted = false;
    obj_0 = &P1_DW.obj_h0;
    P1_DW.obj_h0.isSetupComplete = false;
    P1_DW.obj_h0.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(8U, 1);
    P1_DW.obj_h0.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/VENTRICLE_PACE_CONTROL' */
    P1_DW.obj_b.matlabCodegenIsDeleted = true;
    P1_DW.obj_b.isInitialized = 0;
    P1_DW.obj_b.matlabCodegenIsDeleted = false;
    obj_0 = &P1_DW.obj_b;
    P1_DW.obj_b.isSetupComplete = false;
    P1_DW.obj_b.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(9U, 1);
    P1_DW.obj_b.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/PACE_GROUND_CONTROL' */
    P1_DW.obj_lh.matlabCodegenIsDeleted = true;
    P1_DW.obj_lh.isInitialized = 0;
    P1_DW.obj_lh.matlabCodegenIsDeleted = false;
    obj_0 = &P1_DW.obj_lh;
    P1_DW.obj_lh.isSetupComplete = false;
    P1_DW.obj_lh.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(10U, 1);
    P1_DW.obj_lh.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/ATRIAL_GROUND_CONTROL' */
    P1_DW.obj_oh.matlabCodegenIsDeleted = true;
    P1_DW.obj_oh.isInitialized = 0;
    P1_DW.obj_oh.matlabCodegenIsDeleted = false;
    obj_0 = &P1_DW.obj_oh;
    P1_DW.obj_oh.isSetupComplete = false;
    P1_DW.obj_oh.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(11U, 1);
    P1_DW.obj_oh.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/VENTRICLE_GROUND_CONTROL' */
    P1_DW.obj_m.matlabCodegenIsDeleted = true;
    P1_DW.obj_m.isInitialized = 0;
    P1_DW.obj_m.matlabCodegenIsDeleted = false;
    obj_0 = &P1_DW.obj_m;
    P1_DW.obj_m.isSetupComplete = false;
    P1_DW.obj_m.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(12U, 1);
    P1_DW.obj_m.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/PACING_REF_PWM' */
    P1_DW.obj_c.matlabCodegenIsDeleted = true;
    P1_DW.obj_c.isInitialized = 0;
    P1_DW.obj_c.matlabCodegenIsDeleted = false;
    obj_1 = &P1_DW.obj_c;
    P1_DW.obj_c.isSetupComplete = false;
    P1_DW.obj_c.isInitialized = 1;
    obj_1->MW_PWM_HANDLE = MW_PWM_Open(5U, 2000.0, 60.0);
    MW_PWM_Start(P1_DW.obj_c.MW_PWM_HANDLE);
    P1_DW.obj_c.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/ATRIAL_CMP_RED_PWM' */
    P1_DW.obj_f.matlabCodegenIsDeleted = true;
    P1_DW.obj_f.isInitialized = 0;
    P1_DW.obj_f.matlabCodegenIsDeleted = false;
    obj_1 = &P1_DW.obj_f;
    P1_DW.obj_f.isSetupComplete = false;
    P1_DW.obj_f.isInitialized = 1;
    obj_1->MW_PWM_HANDLE = MW_PWM_Open(6U, 2000.0, 51.0);
    MW_PWM_Start(P1_DW.obj_f.MW_PWM_HANDLE);
    P1_DW.obj_f.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/Analog Input' */
    P1_DW.obj_n.matlabCodegenIsDeleted = true;
    P1_DW.obj_n.isInitialized = 0;
    P1_DW.obj_n.SampleTime = -1.0;
    P1_DW.obj_n.matlabCodegenIsDeleted = false;
    P1_DW.obj_n.SampleTime = P1_P.AnalogInput_SampleTime;
    obj_2 = &P1_DW.obj_n;
    P1_DW.obj_n.isSetupComplete = false;
    P1_DW.obj_n.isInitialized = 1;
    obj_2->MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(16U);
    trigger_val = MW_ANALOGIN_SOFTWARE_TRIGGER;
    MW_AnalogIn_SetTriggerSource(P1_DW.obj_n.MW_ANALOGIN_HANDLE, trigger_val, 0U);
    P1_DW.obj_n.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/VENTRICLE_CMP_REF_PWM' */
    P1_DW.obj_a.matlabCodegenIsDeleted = true;
    P1_DW.obj_a.isInitialized = 0;
    P1_DW.obj_a.matlabCodegenIsDeleted = false;
    obj_1 = &P1_DW.obj_a;
    P1_DW.obj_a.isSetupComplete = false;
    P1_DW.obj_a.isInitialized = 1;
    obj_1->MW_PWM_HANDLE = MW_PWM_Open(3U, 2000.0, 60.0);
    MW_PWM_Start(P1_DW.obj_a.MW_PWM_HANDLE);
    P1_DW.obj_a.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/FRONTEND_CTRL' */
    P1_DW.obj_e.matlabCodegenIsDeleted = true;
    P1_DW.obj_e.isInitialized = 0;
    P1_DW.obj_e.matlabCodegenIsDeleted = false;
    obj_0 = &P1_DW.obj_e;
    P1_DW.obj_e.isSetupComplete = false;
    P1_DW.obj_e.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(13U, 1);
    P1_DW.obj_e.isSetupComplete = true;
  }
}

/* Model terminate function */
void P1_terminate(void)
{
  /* Terminate for MATLABSystem: '<S2>/ATRIAL_CMP_DETECT' */
  if (!P1_DW.obj_l.matlabCodegenIsDeleted) {
    P1_DW.obj_l.matlabCodegenIsDeleted = true;
    if ((P1_DW.obj_l.isInitialized == 1) && P1_DW.obj_l.isSetupComplete) {
      MW_digitalIO_close(P1_DW.obj_l.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/ATRIAL_CMP_DETECT' */

  /* Terminate for MATLABSystem: '<S2>/VENTRICLE_CMP_DETECT' */
  if (!P1_DW.obj.matlabCodegenIsDeleted) {
    P1_DW.obj.matlabCodegenIsDeleted = true;
    if ((P1_DW.obj.isInitialized == 1) && P1_DW.obj.isSetupComplete) {
      MW_digitalIO_close(P1_DW.obj.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/VENTRICLE_CMP_DETECT' */

  /* Terminate for MATLABSystem: '<S3>/PACE_CHARGE_CONTROL' */
  if (!P1_DW.obj_o.matlabCodegenIsDeleted) {
    P1_DW.obj_o.matlabCodegenIsDeleted = true;
    if ((P1_DW.obj_o.isInitialized == 1) && P1_DW.obj_o.isSetupComplete) {
      MW_digitalIO_close(P1_DW.obj_o.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S3>/PACE_CHARGE_CONTROL' */

  /* Terminate for MATLABSystem: '<S3>/Z_ATRIAL_CONTROL' */
  if (!P1_DW.obj_h.matlabCodegenIsDeleted) {
    P1_DW.obj_h.matlabCodegenIsDeleted = true;
    if ((P1_DW.obj_h.isInitialized == 1) && P1_DW.obj_h.isSetupComplete) {
      MW_digitalIO_close(P1_DW.obj_h.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S3>/Z_ATRIAL_CONTROL' */

  /* Terminate for MATLABSystem: '<S3>/Z_VENTRICLE_CONTROL' */
  if (!P1_DW.obj_g.matlabCodegenIsDeleted) {
    P1_DW.obj_g.matlabCodegenIsDeleted = true;
    if ((P1_DW.obj_g.isInitialized == 1) && P1_DW.obj_g.isSetupComplete) {
      MW_digitalIO_close(P1_DW.obj_g.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S3>/Z_VENTRICLE_CONTROL' */

  /* Terminate for MATLABSystem: '<S3>/ATRIAL_PACE_CONTROL' */
  if (!P1_DW.obj_h0.matlabCodegenIsDeleted) {
    P1_DW.obj_h0.matlabCodegenIsDeleted = true;
    if ((P1_DW.obj_h0.isInitialized == 1) && P1_DW.obj_h0.isSetupComplete) {
      MW_digitalIO_close(P1_DW.obj_h0.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S3>/ATRIAL_PACE_CONTROL' */

  /* Terminate for MATLABSystem: '<S3>/VENTRICLE_PACE_CONTROL' */
  if (!P1_DW.obj_b.matlabCodegenIsDeleted) {
    P1_DW.obj_b.matlabCodegenIsDeleted = true;
    if ((P1_DW.obj_b.isInitialized == 1) && P1_DW.obj_b.isSetupComplete) {
      MW_digitalIO_close(P1_DW.obj_b.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S3>/VENTRICLE_PACE_CONTROL' */

  /* Terminate for MATLABSystem: '<S3>/PACE_GROUND_CONTROL' */
  if (!P1_DW.obj_lh.matlabCodegenIsDeleted) {
    P1_DW.obj_lh.matlabCodegenIsDeleted = true;
    if ((P1_DW.obj_lh.isInitialized == 1) && P1_DW.obj_lh.isSetupComplete) {
      MW_digitalIO_close(P1_DW.obj_lh.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S3>/PACE_GROUND_CONTROL' */

  /* Terminate for MATLABSystem: '<S3>/ATRIAL_GROUND_CONTROL' */
  if (!P1_DW.obj_oh.matlabCodegenIsDeleted) {
    P1_DW.obj_oh.matlabCodegenIsDeleted = true;
    if ((P1_DW.obj_oh.isInitialized == 1) && P1_DW.obj_oh.isSetupComplete) {
      MW_digitalIO_close(P1_DW.obj_oh.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S3>/ATRIAL_GROUND_CONTROL' */

  /* Terminate for MATLABSystem: '<S3>/VENTRICLE_GROUND_CONTROL' */
  if (!P1_DW.obj_m.matlabCodegenIsDeleted) {
    P1_DW.obj_m.matlabCodegenIsDeleted = true;
    if ((P1_DW.obj_m.isInitialized == 1) && P1_DW.obj_m.isSetupComplete) {
      MW_digitalIO_close(P1_DW.obj_m.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S3>/VENTRICLE_GROUND_CONTROL' */

  /* Terminate for MATLABSystem: '<S3>/PACING_REF_PWM' */
  if (!P1_DW.obj_c.matlabCodegenIsDeleted) {
    P1_DW.obj_c.matlabCodegenIsDeleted = true;
    if ((P1_DW.obj_c.isInitialized == 1) && P1_DW.obj_c.isSetupComplete) {
      MW_PWM_Stop(P1_DW.obj_c.MW_PWM_HANDLE);
      MW_PWM_Close(P1_DW.obj_c.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S3>/PACING_REF_PWM' */

  /* Terminate for MATLABSystem: '<S2>/ATRIAL_CMP_RED_PWM' */
  if (!P1_DW.obj_f.matlabCodegenIsDeleted) {
    P1_DW.obj_f.matlabCodegenIsDeleted = true;
    if ((P1_DW.obj_f.isInitialized == 1) && P1_DW.obj_f.isSetupComplete) {
      MW_PWM_Stop(P1_DW.obj_f.MW_PWM_HANDLE);
      MW_PWM_Close(P1_DW.obj_f.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/ATRIAL_CMP_RED_PWM' */

  /* Terminate for MATLABSystem: '<S2>/Analog Input' */
  if (!P1_DW.obj_n.matlabCodegenIsDeleted) {
    P1_DW.obj_n.matlabCodegenIsDeleted = true;
    if ((P1_DW.obj_n.isInitialized == 1) && P1_DW.obj_n.isSetupComplete) {
      MW_AnalogIn_Stop(P1_DW.obj_n.MW_ANALOGIN_HANDLE);
      MW_AnalogIn_Close(P1_DW.obj_n.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/Analog Input' */

  /* Terminate for MATLABSystem: '<S2>/VENTRICLE_CMP_REF_PWM' */
  if (!P1_DW.obj_a.matlabCodegenIsDeleted) {
    P1_DW.obj_a.matlabCodegenIsDeleted = true;
    if ((P1_DW.obj_a.isInitialized == 1) && P1_DW.obj_a.isSetupComplete) {
      MW_PWM_Stop(P1_DW.obj_a.MW_PWM_HANDLE);
      MW_PWM_Close(P1_DW.obj_a.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/VENTRICLE_CMP_REF_PWM' */

  /* Terminate for MATLABSystem: '<S2>/FRONTEND_CTRL' */
  if (!P1_DW.obj_e.matlabCodegenIsDeleted) {
    P1_DW.obj_e.matlabCodegenIsDeleted = true;
    if ((P1_DW.obj_e.isInitialized == 1) && P1_DW.obj_e.isSetupComplete) {
      MW_digitalIO_close(P1_DW.obj_e.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/FRONTEND_CTRL' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
