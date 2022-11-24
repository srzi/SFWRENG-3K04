/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Group30_SFWR_Assignment1_SIMULINK.c
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

#include "Group30_SFWR_Assignment1_SIMULINK.h"
#include "Group30_SFWR_Assignment1_SIMULINK_types.h"
#include "rtwtypes.h"
#include <string.h>
#include <math.h>
#include "rt_nonfinite.h"
#include "rt_roundd_snf.h"
#include <stddef.h>
#include "Transmit_DCM.h"
#include "Transmit_DCM_private.h"

/* Named constants for Chart: '<Root>/AOO,VOO,AAI,VVI StateFlows' */
#define Gro_IN_PACE_Discharge_Ventricle ((uint8_T)6U)
#define Group30_SFWR_A_IN_Default_State ((uint8_T)4U)
#define Group30_SFWR_As_IN_SENSE_Atrial ((uint8_T)3U)
#define Group30_SFWR_IN_SENSE_Ventricle ((uint8_T)7U)
#define Group30_S_IN_PACE_Charge_Atrial ((uint8_T)1U)
#define Group3_IN_PACE_Charge_Ventricle ((uint8_T)5U)
#define Group3_IN_PACE_Discharge_Atrial ((uint8_T)2U)

/* Named constants for Chart: '<S4>/Serial Receive from the DCM' */
#define Group30_SFWR_As_IN_Default_Case ((uint8_T)1U)
#define Group30_SFWR_Assignm_IN_STANDBY ((uint8_T)3U)
#define Group30_SFWR_IN_Echo_Parameters ((uint8_T)2U)
#define Group30_SFWR__IN_Set_Parameters ((uint8_T)4U)

/* Block signals (default storage) */
B_Group30_SFWR_Assignment1_SI_T Group30_SFWR_Assignment1_SIMU_B;

/* Block states (default storage) */
DW_Group30_SFWR_Assignment1_S_T Group30_SFWR_Assignment1_SIM_DW;

/* Real-time model */
static RT_MODEL_Group30_SFWR_Assignm_T Group30_SFWR_Assignment1_SIM_M_;
RT_MODEL_Group30_SFWR_Assignm_T *const Group30_SFWR_Assignment1_SIM_M =
  &Group30_SFWR_Assignment1_SIM_M_;

/* Forward declaration for local functions */
static void Group30_SFWR_SystemCore_setup_b(freedomk64f_SCIRead_Group30_S_T *obj);
static void rate_monotonic_scheduler(void);

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to remember which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void Group30_SFWR_Assignment1_SIMULINK_SetEventsForThisBaseStep(boolean_T
  *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(Group30_SFWR_Assignment1_SIM_M, 1));
}

/*
 *         This function updates active task flag for each subrate
 *         and rate transition flags for tasks that exchange data.
 *         The function assumes rate-monotonic multitasking scheduler.
 *         The function must be called at model base rate so that
 *         the generated code self-manages all its subrates and rate
 *         transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (Group30_SFWR_Assignment1_SIM_M->Timing.TaskCounters.TID[1])++;
  if ((Group30_SFWR_Assignment1_SIM_M->Timing.TaskCounters.TID[1]) > 99) {/* Sample time: [0.1s, 0.0s] */
    Group30_SFWR_Assignment1_SIM_M->Timing.TaskCounters.TID[1] = 0;
  }
}

static void Group30_SFWR_SystemCore_setup_b(freedomk64f_SCIRead_Group30_S_T *obj)
{
  MW_SCI_Parity_Type ParityValue;
  obj->isSetupComplete = false;
  obj->isInitialized = 1;
  Group30_SFWR_Assignment1_SIMU_B.TxPinLoc = MW_UNDEFINED_VALUE;
  Group30_SFWR_Assignment1_SIMU_B.SCIModuleLoc = 0;
  obj->MW_SCIHANDLE = MW_SCI_Open(&Group30_SFWR_Assignment1_SIMU_B.SCIModuleLoc,
    false, 10U, Group30_SFWR_Assignment1_SIMU_B.TxPinLoc);
  MW_SCI_SetBaudrate(obj->MW_SCIHANDLE, 115200U);
  Group30_SFWR_Assignment1_SIMU_B.StopBitsValue = MW_SCI_STOPBITS_1;
  ParityValue = MW_SCI_PARITY_NONE;
  MW_SCI_SetFrameFormat(obj->MW_SCIHANDLE, 8, ParityValue,
                        Group30_SFWR_Assignment1_SIMU_B.StopBitsValue);
  obj->isSetupComplete = true;
}

/* Model step function for TID0 */
void Group30_SFWR_Assignment1_SIMULINK_step0(void) /* Sample time: [0.001s, 0.0s] */
{
  {                                    /* Sample time: [0.001s, 0.0s] */
    rate_monotonic_scheduler();
  }
}

/* Model step function for TID1 */
void Group30_SFWR_Assignment1_SIMULINK_step1(void) /* Sample time: [0.1s, 0.0s] */
{
  real_T tmp_0;
  int32_T tmp;
  uint32_T qY;
  uint32_T qY_0;
  uint16_T rtb_DataTypeConversion3;
  uint8_T status;
  boolean_T rtb_ATRIAL_CMP_DETECT_0;
  boolean_T rtb_VENTRICLE_CMP_DETECT_0;

  /* MATLABSystem: '<S4>/Serial Receive' */
  if (Group30_SFWR_Assignment1_SIM_DW.obj_j.SampleTime !=
      Group30_SFWR_Assignment1_SIMU_P.SerialReceive_SampleTime) {
    Group30_SFWR_Assignment1_SIM_DW.obj_j.SampleTime =
      Group30_SFWR_Assignment1_SIMU_P.SerialReceive_SampleTime;
  }

  status = MW_SCI_Receive(Group30_SFWR_Assignment1_SIM_DW.obj_j.MW_SCIHANDLE,
    &Group30_SFWR_Assignment1_SIMU_B.RxDataLocChar[0], 16U);
  memcpy((void *)&Group30_SFWR_Assignment1_SIMU_B.RxData[0], (void *)
         &Group30_SFWR_Assignment1_SIMU_B.RxDataLocChar[0], (uint32_T)((size_t)
          16 * sizeof(uint8_T)));

  /* Chart: '<S4>/Serial Receive from the DCM' incorporates:
   *  MATLABSystem: '<S4>/Serial Receive'
   */
  if (Group30_SFWR_Assignment1_SIM_DW.is_active_c2_Group30_SFWR_Assig == 0U) {
    Group30_SFWR_Assignment1_SIM_DW.is_active_c2_Group30_SFWR_Assig = 1U;
    Group30_SFWR_Assignment1_SIM_DW.is_c2_Group30_SFWR_Assignment1_ =
      Group30_SFWR_As_IN_Default_Case;
    Group30_SFWR_Assignment1_SIMU_B.Pace_Mode = 1U;
    Group30_SFWR_Assignment1_SIMU_B.Sensing_Control = 0U;
    Group30_SFWR_Assignment1_SIMU_B.Atrial_Amplitude = 35U;
    Group30_SFWR_Assignment1_SIMU_B.Ventricle_Amplitude = 35U;
    Group30_SFWR_Assignment1_SIMU_B.Atrial_PaceWidth = 1U;
    Group30_SFWR_Assignment1_SIMU_B.Ventricle_PaceWidth = 1U;
    Group30_SFWR_Assignment1_SIMU_B.Atrial_Refractory_Period_f = 250U;
    Group30_SFWR_Assignment1_SIMU_B.Ventricle_Refractory_Period_k = 320U;
    Group30_SFWR_Assignment1_SIMU_B.Lower_Rate_Limit = 60U;
    Group30_SFWR_Assignment1_SIMU_B.Upper_Rate_Limit = 120U;
    Group30_SFWR_Assignment1_SIMU_B.Atrial_Sensitivity = 10U;
    Group30_SFWR_Assignment1_SIMU_B.Ventricle_Sensitivity = 25U;
  } else {
    switch (Group30_SFWR_Assignment1_SIM_DW.is_c2_Group30_SFWR_Assignment1_) {
     case Group30_SFWR_As_IN_Default_Case:
      Group30_SFWR_Assignment1_SIM_DW.is_c2_Group30_SFWR_Assignment1_ =
        Group30_SFWR_Assignm_IN_STANDBY;
      break;

     case Group30_SFWR_IN_Echo_Parameters:
      Group30_SFWR_Assignment1_SIM_DW.is_c2_Group30_SFWR_Assignment1_ =
        Group30_SFWR_Assignm_IN_STANDBY;
      break;

     case Group30_SFWR_Assignm_IN_STANDBY:
      if (status == 0) {
        if (Group30_SFWR_Assignment1_SIMU_B.RxData[0] == 22) {
          switch (Group30_SFWR_Assignment1_SIMU_B.RxData[1]) {
           case 85:
            Group30_SFWR_Assignment1_SIM_DW.is_c2_Group30_SFWR_Assignment1_ =
              Group30_SFWR__IN_Set_Parameters;
            Group30_SFWR_Assignment1_SIMU_B.Pace_Mode =
              Group30_SFWR_Assignment1_SIMU_B.RxData[2];
            Group30_SFWR_Assignment1_SIMU_B.Sensing_Control =
              Group30_SFWR_Assignment1_SIMU_B.RxData[3];
            Group30_SFWR_Assignment1_SIMU_B.Atrial_Amplitude =
              Group30_SFWR_Assignment1_SIMU_B.RxData[4];
            Group30_SFWR_Assignment1_SIMU_B.Ventricle_Amplitude =
              Group30_SFWR_Assignment1_SIMU_B.RxData[5];
            Group30_SFWR_Assignment1_SIMU_B.Atrial_PaceWidth =
              Group30_SFWR_Assignment1_SIMU_B.RxData[6];
            Group30_SFWR_Assignment1_SIMU_B.Ventricle_PaceWidth =
              Group30_SFWR_Assignment1_SIMU_B.RxData[7];
            memcpy((void *)
                   &Group30_SFWR_Assignment1_SIMU_B.Atrial_Refractory_Period_f,
                   (void *)&Group30_SFWR_Assignment1_SIMU_B.RxData[8], (uint32_T)
                   ((size_t)1 * sizeof(uint16_T)));
            memcpy((void *)
                   &Group30_SFWR_Assignment1_SIMU_B.Ventricle_Refractory_Period_k,
                   (void *)&Group30_SFWR_Assignment1_SIMU_B.RxData[10],
                   (uint32_T)((size_t)1 * sizeof(uint16_T)));
            Group30_SFWR_Assignment1_SIMU_B.Lower_Rate_Limit =
              Group30_SFWR_Assignment1_SIMU_B.RxData[12];
            Group30_SFWR_Assignment1_SIMU_B.Upper_Rate_Limit =
              Group30_SFWR_Assignment1_SIMU_B.RxData[13];
            Group30_SFWR_Assignment1_SIMU_B.Atrial_Sensitivity =
              Group30_SFWR_Assignment1_SIMU_B.RxData[14];
            Group30_SFWR_Assignment1_SIMU_B.Ventricle_Sensitivity =
              Group30_SFWR_Assignment1_SIMU_B.RxData[15];
            break;

           case 34:
            Group30_SFWR_Assignment1_SIM_DW.is_c2_Group30_SFWR_Assignment1_ =
              Group30_SFWR_IN_Echo_Parameters;
            Transmit_DCM();
            break;

           default:
            Group30_SFWR_Assignment1_SIM_DW.is_c2_Group30_SFWR_Assignment1_ =
              Group30_SFWR_Assignm_IN_STANDBY;
            break;
          }
        } else {
          Group30_SFWR_Assignment1_SIM_DW.is_c2_Group30_SFWR_Assignment1_ =
            Group30_SFWR_Assignm_IN_STANDBY;
        }
      }
      break;

     default:
      /* case IN_Set_Parameters: */
      Group30_SFWR_Assignment1_SIM_DW.is_c2_Group30_SFWR_Assignment1_ =
        Group30_SFWR_Assignm_IN_STANDBY;
      break;
    }
  }

  /* End of Chart: '<S4>/Serial Receive from the DCM' */

  /* MATLABSystem: '<S6>/ATRIAL_CMP_DETECT' */
  if (Group30_SFWR_Assignment1_SIM_DW.obj_d.SampleTime !=
      Group30_SFWR_Assignment1_SIMU_P.ATRIAL_CMP_DETECT_SampleTime) {
    Group30_SFWR_Assignment1_SIM_DW.obj_d.SampleTime =
      Group30_SFWR_Assignment1_SIMU_P.ATRIAL_CMP_DETECT_SampleTime;
  }

  rtb_ATRIAL_CMP_DETECT_0 = MW_digitalIO_read
    (Group30_SFWR_Assignment1_SIM_DW.obj_d.MW_DIGITALIO_HANDLE);

  /* MATLABSystem: '<S6>/VENTRICLE_CMP_DETECT' */
  if (Group30_SFWR_Assignment1_SIM_DW.obj.SampleTime !=
      Group30_SFWR_Assignment1_SIMU_P.VENTRICLE_CMP_DETECT_SampleTime) {
    Group30_SFWR_Assignment1_SIM_DW.obj.SampleTime =
      Group30_SFWR_Assignment1_SIMU_P.VENTRICLE_CMP_DETECT_SampleTime;
  }

  rtb_VENTRICLE_CMP_DETECT_0 = MW_digitalIO_read
    (Group30_SFWR_Assignment1_SIM_DW.obj.MW_DIGITALIO_HANDLE);

  /* DataTypeConversion: '<S5>/Data Type Conversion3' incorporates:
   *  Constant: '<S5>/Constant6'
   *  Product: '<S5>/Divide'
   */
  tmp_0 = floor(Group30_SFWR_Assignment1_SIMU_P.Constant6_Value / (real_T)
                Group30_SFWR_Assignment1_SIMU_B.Lower_Rate_Limit);
  if (rtIsNaN(tmp_0) || rtIsInf(tmp_0)) {
    tmp_0 = 0.0;
  } else {
    tmp_0 = fmod(tmp_0, 65536.0);
  }

  rtb_DataTypeConversion3 = (uint16_T)(tmp_0 < 0.0 ? (int32_T)(uint16_T)
    -(int16_T)(uint16_T)-tmp_0 : (int32_T)(uint16_T)tmp_0);

  /* End of DataTypeConversion: '<S5>/Data Type Conversion3' */

  /* Chart: '<Root>/AOO,VOO,AAI,VVI StateFlows' incorporates:
   *  DataTypeConversion: '<S2>/Data Type Conversion1'
   *  DataTypeConversion: '<S2>/Data Type Conversion3'
   *  MATLABSystem: '<S6>/ATRIAL_CMP_DETECT'
   *  MATLABSystem: '<S6>/VENTRICLE_CMP_DETECT'
   */
  if (Group30_SFWR_Assignment1_SIM_DW.temporalCounter_i1 < MAX_uint32_T) {
    Group30_SFWR_Assignment1_SIM_DW.temporalCounter_i1++;
  }

  if (Group30_SFWR_Assignment1_SIM_DW.is_active_c1_Group30_SFWR_Assig == 0U) {
    Group30_SFWR_Assignment1_SIM_DW.is_active_c1_Group30_SFWR_Assig = 1U;
    Group30_SFWR_Assignment1_SIM_DW.is_c1_Group30_SFWR_Assignment1_ =
      Group30_SFWR_A_IN_Default_State;
    Group30_SFWR_Assignment1_SIMU_B.FRONTEND_CTRL = false;
    Group30_SFWR_Assignment1_SIMU_B.PACE_GROUND_CONTROL = false;
    Group30_SFWR_Assignment1_SIMU_B.Z_ATRIAL_CONTROL = false;
    Group30_SFWR_Assignment1_SIMU_B.Z_VENTRICLE_CONTROL = false;
    Group30_SFWR_Assignment1_SIMU_B.PACE_CHARGE_CONTROL = false;
    Group30_SFWR_Assignment1_SIMU_B.VENTRICLE_PACE_CONTROL = false;
    Group30_SFWR_Assignment1_SIMU_B.VENTRICLE_GROUND_CONTROL = false;
    Group30_SFWR_Assignment1_SIMU_B.ATRIAL_PACE_CONTROL = false;
    Group30_SFWR_Assignment1_SIMU_B.ATRIAL_GROUND_CONTROL = false;
  } else {
    switch (Group30_SFWR_Assignment1_SIM_DW.is_c1_Group30_SFWR_Assignment1_) {
     case Group30_S_IN_PACE_Charge_Atrial:
      Group30_SFWR_Assignment1_SIMU_B.PACE_CHARGE_CONTROL = true;
      Group30_SFWR_Assignment1_SIMU_B.VENTRICLE_PACE_CONTROL = false;
      Group30_SFWR_Assignment1_SIMU_B.VENTRICLE_GROUND_CONTROL = false;
      Group30_SFWR_Assignment1_SIMU_B.ATRIAL_PACE_CONTROL = false;
      Group30_SFWR_Assignment1_SIMU_B.ATRIAL_GROUND_CONTROL = true;
      Group30_SFWR_Assignment1_SIMU_B.PACE_GROUND_CONTROL = true;
      if (((uint32_T)((int32_T)
                      Group30_SFWR_Assignment1_SIM_DW.temporalCounter_i1 * 100) >=
           Group30_SFWR_Assignment1_SIMU_B.Atrial_Refractory_Period_f) &&
          (Group30_SFWR_Assignment1_SIMU_B.Sensing_Control == 1)) {
        Group30_SFWR_Assignment1_SIMU_B.FRONTEND_CTRL = true;
        Group30_SFWR_Assignment1_SIM_DW.is_c1_Group30_SFWR_Assignment1_ =
          Group30_SFWR_As_IN_SENSE_Atrial;
        Group30_SFWR_Assignment1_SIM_DW.temporalCounter_i1 = 0U;
      } else {
        qY = (uint32_T)rtb_DataTypeConversion3 - /*MW:OvSatOk*/
          Group30_SFWR_Assignment1_SIMU_B.Atrial_PaceWidth;
        if (qY > rtb_DataTypeConversion3) {
          qY = 0U;
        }

        if (((uint32_T)((int32_T)
                        Group30_SFWR_Assignment1_SIM_DW.temporalCounter_i1 * 100)
             >= qY) && (Group30_SFWR_Assignment1_SIMU_B.Sensing_Control == 0)) {
          Group30_SFWR_Assignment1_SIM_DW.is_c1_Group30_SFWR_Assignment1_ =
            Group3_IN_PACE_Discharge_Atrial;
          Group30_SFWR_Assignment1_SIM_DW.temporalCounter_i1 = 0U;
          Group30_SFWR_Assignment1_SIMU_B.PACE_CHARGE_CONTROL = false;
          Group30_SFWR_Assignment1_SIMU_B.ATRIAL_PACE_CONTROL = true;
          Group30_SFWR_Assignment1_SIMU_B.ATRIAL_GROUND_CONTROL = false;
          Group30_SFWR_Assignment1_SIMU_B.FRONTEND_CTRL = false;
        }
      }
      break;

     case Group3_IN_PACE_Discharge_Atrial:
      Group30_SFWR_Assignment1_SIMU_B.PACE_CHARGE_CONTROL = false;
      Group30_SFWR_Assignment1_SIMU_B.ATRIAL_PACE_CONTROL = true;
      Group30_SFWR_Assignment1_SIMU_B.ATRIAL_GROUND_CONTROL = false;
      if ((uint32_T)((int32_T)Group30_SFWR_Assignment1_SIM_DW.temporalCounter_i1
                     * 100) >= Group30_SFWR_Assignment1_SIMU_B.Atrial_PaceWidth)
      {
        Group30_SFWR_Assignment1_SIM_DW.is_c1_Group30_SFWR_Assignment1_ =
          Group30_S_IN_PACE_Charge_Atrial;
        Group30_SFWR_Assignment1_SIM_DW.temporalCounter_i1 = 0U;
        tmp = (int32_T)(10U * Group30_SFWR_Assignment1_SIMU_B.Atrial_Amplitude);
        if ((uint32_T)tmp > 255U) {
          tmp = 255;
        }

        Group30_SFWR_Assignment1_SIMU_B.PACING_REF_PWM = (uint8_T)rt_roundd_snf
          ((real_T)tmp / 5.0);
        Group30_SFWR_Assignment1_SIMU_B.PACE_CHARGE_CONTROL = true;
        Group30_SFWR_Assignment1_SIMU_B.VENTRICLE_PACE_CONTROL = false;
        Group30_SFWR_Assignment1_SIMU_B.VENTRICLE_GROUND_CONTROL = false;
        Group30_SFWR_Assignment1_SIMU_B.ATRIAL_PACE_CONTROL = false;
        Group30_SFWR_Assignment1_SIMU_B.ATRIAL_GROUND_CONTROL = true;
        Group30_SFWR_Assignment1_SIMU_B.FRONTEND_CTRL = false;
        Group30_SFWR_Assignment1_SIMU_B.PACE_GROUND_CONTROL = true;
      }
      break;

     case Group30_SFWR_As_IN_SENSE_Atrial:
      qY = (uint32_T)rtb_DataTypeConversion3 - /*MW:OvSatOk*/
        Group30_SFWR_Assignment1_SIMU_B.Atrial_Refractory_Period_f;
      if (qY > rtb_DataTypeConversion3) {
        qY = 0U;
      }

      qY_0 = qY - /*MW:OvSatOk*/
        Group30_SFWR_Assignment1_SIMU_B.Atrial_PaceWidth;
      if (qY_0 > qY) {
        qY_0 = 0U;
      }

      if (((uint32_T)((int32_T)
                      Group30_SFWR_Assignment1_SIM_DW.temporalCounter_i1 * 100) >=
           qY_0) && (!rtb_ATRIAL_CMP_DETECT_0)) {
        Group30_SFWR_Assignment1_SIM_DW.is_c1_Group30_SFWR_Assignment1_ =
          Group3_IN_PACE_Discharge_Atrial;
        Group30_SFWR_Assignment1_SIM_DW.temporalCounter_i1 = 0U;
        Group30_SFWR_Assignment1_SIMU_B.PACE_CHARGE_CONTROL = false;
        Group30_SFWR_Assignment1_SIMU_B.ATRIAL_PACE_CONTROL = true;
        Group30_SFWR_Assignment1_SIMU_B.ATRIAL_GROUND_CONTROL = false;
        Group30_SFWR_Assignment1_SIMU_B.FRONTEND_CTRL = false;
      } else if (rtb_ATRIAL_CMP_DETECT_0) {
        Group30_SFWR_Assignment1_SIM_DW.is_c1_Group30_SFWR_Assignment1_ =
          Group30_S_IN_PACE_Charge_Atrial;
        Group30_SFWR_Assignment1_SIM_DW.temporalCounter_i1 = 0U;
        tmp = (int32_T)(10U * Group30_SFWR_Assignment1_SIMU_B.Atrial_Amplitude);
        if ((uint32_T)tmp > 255U) {
          tmp = 255;
        }

        Group30_SFWR_Assignment1_SIMU_B.PACING_REF_PWM = (uint8_T)rt_roundd_snf
          ((real_T)tmp / 5.0);
        Group30_SFWR_Assignment1_SIMU_B.PACE_CHARGE_CONTROL = true;
        Group30_SFWR_Assignment1_SIMU_B.VENTRICLE_PACE_CONTROL = false;
        Group30_SFWR_Assignment1_SIMU_B.VENTRICLE_GROUND_CONTROL = false;
        Group30_SFWR_Assignment1_SIMU_B.ATRIAL_PACE_CONTROL = false;
        Group30_SFWR_Assignment1_SIMU_B.ATRIAL_GROUND_CONTROL = true;
        Group30_SFWR_Assignment1_SIMU_B.FRONTEND_CTRL = false;
        Group30_SFWR_Assignment1_SIMU_B.PACE_GROUND_CONTROL = true;
      }
      break;

     case Group30_SFWR_A_IN_Default_State:
      Group30_SFWR_Assignment1_SIMU_B.PACE_GROUND_CONTROL = false;
      Group30_SFWR_Assignment1_SIMU_B.Z_ATRIAL_CONTROL = false;
      Group30_SFWR_Assignment1_SIMU_B.Z_VENTRICLE_CONTROL = false;
      Group30_SFWR_Assignment1_SIMU_B.PACE_CHARGE_CONTROL = false;
      Group30_SFWR_Assignment1_SIMU_B.VENTRICLE_PACE_CONTROL = false;
      Group30_SFWR_Assignment1_SIMU_B.VENTRICLE_GROUND_CONTROL = false;
      Group30_SFWR_Assignment1_SIMU_B.ATRIAL_PACE_CONTROL = false;
      Group30_SFWR_Assignment1_SIMU_B.ATRIAL_GROUND_CONTROL = false;
      switch (Group30_SFWR_Assignment1_SIMU_B.Pace_Mode) {
       case 1:
        Group30_SFWR_Assignment1_SIM_DW.is_c1_Group30_SFWR_Assignment1_ =
          Group30_S_IN_PACE_Charge_Atrial;
        Group30_SFWR_Assignment1_SIM_DW.temporalCounter_i1 = 0U;
        tmp = (int32_T)(10U * Group30_SFWR_Assignment1_SIMU_B.Atrial_Amplitude);
        if ((uint32_T)tmp > 255U) {
          tmp = 255;
        }

        Group30_SFWR_Assignment1_SIMU_B.PACING_REF_PWM = (uint8_T)rt_roundd_snf
          ((real_T)tmp / 5.0);
        Group30_SFWR_Assignment1_SIMU_B.PACE_CHARGE_CONTROL = true;
        Group30_SFWR_Assignment1_SIMU_B.ATRIAL_GROUND_CONTROL = true;
        Group30_SFWR_Assignment1_SIMU_B.FRONTEND_CTRL = false;
        Group30_SFWR_Assignment1_SIMU_B.PACE_GROUND_CONTROL = true;
        break;

       case 0:
        Group30_SFWR_Assignment1_SIM_DW.is_c1_Group30_SFWR_Assignment1_ =
          Group3_IN_PACE_Charge_Ventricle;
        Group30_SFWR_Assignment1_SIM_DW.temporalCounter_i1 = 0U;
        tmp = (int32_T)(10U *
                        Group30_SFWR_Assignment1_SIMU_B.Ventricle_Amplitude);
        if ((uint32_T)tmp > 255U) {
          tmp = 255;
        }

        Group30_SFWR_Assignment1_SIMU_B.PACING_REF_PWM = (uint8_T)rt_roundd_snf
          ((real_T)tmp / 5.0);
        Group30_SFWR_Assignment1_SIMU_B.PACE_CHARGE_CONTROL = true;
        Group30_SFWR_Assignment1_SIMU_B.VENTRICLE_GROUND_CONTROL = true;
        Group30_SFWR_Assignment1_SIMU_B.FRONTEND_CTRL = false;
        Group30_SFWR_Assignment1_SIMU_B.PACE_GROUND_CONTROL = true;
        break;
      }
      break;

     case Group3_IN_PACE_Charge_Ventricle:
      Group30_SFWR_Assignment1_SIMU_B.PACE_CHARGE_CONTROL = true;
      Group30_SFWR_Assignment1_SIMU_B.VENTRICLE_PACE_CONTROL = false;
      Group30_SFWR_Assignment1_SIMU_B.VENTRICLE_GROUND_CONTROL = true;
      Group30_SFWR_Assignment1_SIMU_B.ATRIAL_PACE_CONTROL = false;
      Group30_SFWR_Assignment1_SIMU_B.ATRIAL_GROUND_CONTROL = false;
      Group30_SFWR_Assignment1_SIMU_B.PACE_GROUND_CONTROL = true;
      if (((uint32_T)((int32_T)
                      Group30_SFWR_Assignment1_SIM_DW.temporalCounter_i1 * 100) >=
           Group30_SFWR_Assignment1_SIMU_B.Ventricle_Refractory_Period_k) &&
          (Group30_SFWR_Assignment1_SIMU_B.Sensing_Control == 1)) {
        Group30_SFWR_Assignment1_SIMU_B.FRONTEND_CTRL = true;
        Group30_SFWR_Assignment1_SIM_DW.is_c1_Group30_SFWR_Assignment1_ =
          Group30_SFWR_IN_SENSE_Ventricle;
        Group30_SFWR_Assignment1_SIM_DW.temporalCounter_i1 = 0U;
      } else {
        qY = (uint32_T)rtb_DataTypeConversion3 - /*MW:OvSatOk*/
          Group30_SFWR_Assignment1_SIMU_B.Ventricle_PaceWidth;
        if (qY > rtb_DataTypeConversion3) {
          qY = 0U;
        }

        if (((uint32_T)((int32_T)
                        Group30_SFWR_Assignment1_SIM_DW.temporalCounter_i1 * 100)
             >= qY) && (Group30_SFWR_Assignment1_SIMU_B.Sensing_Control == 0)) {
          Group30_SFWR_Assignment1_SIM_DW.is_c1_Group30_SFWR_Assignment1_ =
            Gro_IN_PACE_Discharge_Ventricle;
          Group30_SFWR_Assignment1_SIM_DW.temporalCounter_i1 = 0U;
          Group30_SFWR_Assignment1_SIMU_B.PACE_CHARGE_CONTROL = false;
          Group30_SFWR_Assignment1_SIMU_B.VENTRICLE_PACE_CONTROL = true;
          Group30_SFWR_Assignment1_SIMU_B.VENTRICLE_GROUND_CONTROL = false;
          Group30_SFWR_Assignment1_SIMU_B.FRONTEND_CTRL = false;
        }
      }
      break;

     case Gro_IN_PACE_Discharge_Ventricle:
      Group30_SFWR_Assignment1_SIMU_B.PACE_CHARGE_CONTROL = false;
      Group30_SFWR_Assignment1_SIMU_B.VENTRICLE_PACE_CONTROL = true;
      Group30_SFWR_Assignment1_SIMU_B.VENTRICLE_GROUND_CONTROL = false;
      if ((uint32_T)((int32_T)Group30_SFWR_Assignment1_SIM_DW.temporalCounter_i1
                     * 100) >=
          Group30_SFWR_Assignment1_SIMU_B.Ventricle_PaceWidth) {
        Group30_SFWR_Assignment1_SIM_DW.is_c1_Group30_SFWR_Assignment1_ =
          Group3_IN_PACE_Charge_Ventricle;
        Group30_SFWR_Assignment1_SIM_DW.temporalCounter_i1 = 0U;
        tmp = (int32_T)(10U *
                        Group30_SFWR_Assignment1_SIMU_B.Ventricle_Amplitude);
        if ((uint32_T)tmp > 255U) {
          tmp = 255;
        }

        Group30_SFWR_Assignment1_SIMU_B.PACING_REF_PWM = (uint8_T)rt_roundd_snf
          ((real_T)tmp / 5.0);
        Group30_SFWR_Assignment1_SIMU_B.PACE_CHARGE_CONTROL = true;
        Group30_SFWR_Assignment1_SIMU_B.VENTRICLE_PACE_CONTROL = false;
        Group30_SFWR_Assignment1_SIMU_B.VENTRICLE_GROUND_CONTROL = true;
        Group30_SFWR_Assignment1_SIMU_B.ATRIAL_PACE_CONTROL = false;
        Group30_SFWR_Assignment1_SIMU_B.ATRIAL_GROUND_CONTROL = false;
        Group30_SFWR_Assignment1_SIMU_B.FRONTEND_CTRL = false;
        Group30_SFWR_Assignment1_SIMU_B.PACE_GROUND_CONTROL = true;
      }
      break;

     default:
      /* case IN_SENSE_Ventricle: */
      qY = (uint32_T)rtb_DataTypeConversion3 - /*MW:OvSatOk*/
        Group30_SFWR_Assignment1_SIMU_B.Ventricle_Refractory_Period_k;
      if (qY > rtb_DataTypeConversion3) {
        qY = 0U;
      }

      if (((uint32_T)((int32_T)
                      Group30_SFWR_Assignment1_SIM_DW.temporalCounter_i1 * 100) >=
           qY) && (!rtb_VENTRICLE_CMP_DETECT_0)) {
        Group30_SFWR_Assignment1_SIM_DW.is_c1_Group30_SFWR_Assignment1_ =
          Gro_IN_PACE_Discharge_Ventricle;
        Group30_SFWR_Assignment1_SIM_DW.temporalCounter_i1 = 0U;
        Group30_SFWR_Assignment1_SIMU_B.PACE_CHARGE_CONTROL = false;
        Group30_SFWR_Assignment1_SIMU_B.VENTRICLE_PACE_CONTROL = true;
        Group30_SFWR_Assignment1_SIMU_B.VENTRICLE_GROUND_CONTROL = false;
        Group30_SFWR_Assignment1_SIMU_B.FRONTEND_CTRL = false;
      } else if (rtb_VENTRICLE_CMP_DETECT_0) {
        Group30_SFWR_Assignment1_SIM_DW.is_c1_Group30_SFWR_Assignment1_ =
          Group3_IN_PACE_Charge_Ventricle;
        Group30_SFWR_Assignment1_SIM_DW.temporalCounter_i1 = 0U;
        tmp = (int32_T)(10U *
                        Group30_SFWR_Assignment1_SIMU_B.Ventricle_Amplitude);
        if ((uint32_T)tmp > 255U) {
          tmp = 255;
        }

        Group30_SFWR_Assignment1_SIMU_B.PACING_REF_PWM = (uint8_T)rt_roundd_snf
          ((real_T)tmp / 5.0);
        Group30_SFWR_Assignment1_SIMU_B.PACE_CHARGE_CONTROL = true;
        Group30_SFWR_Assignment1_SIMU_B.VENTRICLE_PACE_CONTROL = false;
        Group30_SFWR_Assignment1_SIMU_B.VENTRICLE_GROUND_CONTROL = true;
        Group30_SFWR_Assignment1_SIMU_B.ATRIAL_PACE_CONTROL = false;
        Group30_SFWR_Assignment1_SIMU_B.ATRIAL_GROUND_CONTROL = false;
        Group30_SFWR_Assignment1_SIMU_B.FRONTEND_CTRL = false;
        Group30_SFWR_Assignment1_SIMU_B.PACE_GROUND_CONTROL = true;
      }
      break;
    }
  }

  /* End of Chart: '<Root>/AOO,VOO,AAI,VVI StateFlows' */

  /* MATLABSystem: '<S9>/PACE_CHARGE_CONTROL' */
  MW_digitalIO_write(Group30_SFWR_Assignment1_SIM_DW.obj_jy.MW_DIGITALIO_HANDLE,
                     Group30_SFWR_Assignment1_SIMU_B.PACE_CHARGE_CONTROL);

  /* MATLABSystem: '<S9>/Z_ATRIAL_CONTROL' */
  MW_digitalIO_write(Group30_SFWR_Assignment1_SIM_DW.obj_lf.MW_DIGITALIO_HANDLE,
                     Group30_SFWR_Assignment1_SIMU_B.Z_ATRIAL_CONTROL);

  /* MATLABSystem: '<S9>/Z_VENTRICLE_CONTROL' */
  MW_digitalIO_write(Group30_SFWR_Assignment1_SIM_DW.obj_n.MW_DIGITALIO_HANDLE,
                     Group30_SFWR_Assignment1_SIMU_B.Z_VENTRICLE_CONTROL);

  /* MATLABSystem: '<S9>/ATRIAL_PACE_CONTROL' */
  MW_digitalIO_write(Group30_SFWR_Assignment1_SIM_DW.obj_e.MW_DIGITALIO_HANDLE,
                     Group30_SFWR_Assignment1_SIMU_B.ATRIAL_PACE_CONTROL);

  /* MATLABSystem: '<S9>/VENTRICLE_PACE_CONTROL' */
  MW_digitalIO_write(Group30_SFWR_Assignment1_SIM_DW.obj_j1.MW_DIGITALIO_HANDLE,
                     Group30_SFWR_Assignment1_SIMU_B.VENTRICLE_PACE_CONTROL);

  /* MATLABSystem: '<S9>/PACE_GROUND_CONTROL' */
  MW_digitalIO_write(Group30_SFWR_Assignment1_SIM_DW.obj_f.MW_DIGITALIO_HANDLE,
                     Group30_SFWR_Assignment1_SIMU_B.PACE_GROUND_CONTROL);

  /* MATLABSystem: '<S9>/ATRIAL_GROUND_CONTROL' */
  MW_digitalIO_write(Group30_SFWR_Assignment1_SIM_DW.obj_pz.MW_DIGITALIO_HANDLE,
                     Group30_SFWR_Assignment1_SIMU_B.ATRIAL_GROUND_CONTROL);

  /* MATLABSystem: '<S9>/VENTRICLE_GROUND_CONTROL' */
  MW_digitalIO_write(Group30_SFWR_Assignment1_SIM_DW.obj_m.MW_DIGITALIO_HANDLE,
                     Group30_SFWR_Assignment1_SIMU_B.VENTRICLE_GROUND_CONTROL);

  /* MATLABSystem: '<S9>/PACING_REF_PWM' */
  MW_PWM_SetDutyCycle(Group30_SFWR_Assignment1_SIM_DW.obj_k.MW_PWM_HANDLE,
                      (real_T)Group30_SFWR_Assignment1_SIMU_B.PACING_REF_PWM);

  /* MATLABSystem: '<S9>/FRONTEND_CTRL' */
  MW_digitalIO_write(Group30_SFWR_Assignment1_SIM_DW.obj_p.MW_DIGITALIO_HANDLE,
                     Group30_SFWR_Assignment1_SIMU_B.FRONTEND_CTRL);

  /* MATLABSystem: '<S6>/ATRIAL_CMP_RED_PWM' incorporates:
   *  Constant: '<S6>/Constant'
   *  Constant: '<S6>/Constant2'
   *  Gain: '<S6>/Multiply'
   *  Product: '<S6>/Divide'
   *  Product: '<S6>/Divide3'
   */
  MW_PWM_SetDutyCycle(Group30_SFWR_Assignment1_SIM_DW.obj_l.MW_PWM_HANDLE,
                      Group30_SFWR_Assignment1_SIMU_P.Multiply_Gain * ((real_T)
    Group30_SFWR_Assignment1_SIMU_B.Atrial_Sensitivity /
    Group30_SFWR_Assignment1_SIMU_P.Constant_Value /
    Group30_SFWR_Assignment1_SIMU_P.Constant2_Value));

  /* MATLABSystem: '<S6>/VENTRICLE_CMP_REF_PWM' incorporates:
   *  Constant: '<S6>/Constant1'
   *  Constant: '<S6>/Constant3'
   *  Gain: '<S6>/Multiply1'
   *  Product: '<S6>/Divide1'
   *  Product: '<S6>/Divide2'
   */
  MW_PWM_SetDutyCycle(Group30_SFWR_Assignment1_SIM_DW.obj_a.MW_PWM_HANDLE,
                      Group30_SFWR_Assignment1_SIMU_P.Multiply1_Gain * ((real_T)
    Group30_SFWR_Assignment1_SIMU_B.Ventricle_Sensitivity /
    Group30_SFWR_Assignment1_SIMU_P.Constant1_Value /
    Group30_SFWR_Assignment1_SIMU_P.Constant3_Value));
}

/* Use this function only if you need to maintain compatibility with an existing static main program. */
void Group30_SFWR_Assignment1_SIMULINK_step(int_T tid)
{
  switch (tid) {
   case 0 :
    Group30_SFWR_Assignment1_SIMULINK_step0();
    break;

   case 1 :
    Group30_SFWR_Assignment1_SIMULINK_step1();
    break;

   default :
    /* do nothing */
    break;
  }
}

/* Model initialize function */
void Group30_SFWR_Assignment1_SIMULINK_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  {
    freedomk64f_DigitalRead_Group_T *obj;
    freedomk64f_DigitalWrite_Grou_T *obj_0;
    freedomk64f_PWMOutput_Group30_T *obj_1;

    /* SystemInitialize for S-Function (sfun_private_function_caller) generated from: '<S4>/Serial Transmit to the DCM' incorporates:
     *  SubSystem: '<S4>/Serial Transmit to the DCM'
     */
    Transmit_DCM_Init();

    /* End of SystemInitialize for S-Function (sfun_private_function_caller) generated from: '<S4>/Serial Transmit to the DCM' */

    /* Start for MATLABSystem: '<S4>/Serial Receive' */
    Group30_SFWR_Assignment1_SIM_DW.obj_j.isInitialized = 0;
    Group30_SFWR_Assignment1_SIM_DW.obj_j.matlabCodegenIsDeleted = false;
    Group30_SFWR_Assignment1_SIM_DW.obj_j.SampleTime =
      Group30_SFWR_Assignment1_SIMU_P.SerialReceive_SampleTime;
    Group30_SFWR_SystemCore_setup_b(&Group30_SFWR_Assignment1_SIM_DW.obj_j);

    /* Start for MATLABSystem: '<S6>/ATRIAL_CMP_DETECT' */
    Group30_SFWR_Assignment1_SIM_DW.obj_d.matlabCodegenIsDeleted = true;
    Group30_SFWR_Assignment1_SIM_DW.obj_d.isInitialized = 0;
    Group30_SFWR_Assignment1_SIM_DW.obj_d.SampleTime = -1.0;
    Group30_SFWR_Assignment1_SIM_DW.obj_d.matlabCodegenIsDeleted = false;
    Group30_SFWR_Assignment1_SIM_DW.obj_d.SampleTime =
      Group30_SFWR_Assignment1_SIMU_P.ATRIAL_CMP_DETECT_SampleTime;
    obj = &Group30_SFWR_Assignment1_SIM_DW.obj_d;
    Group30_SFWR_Assignment1_SIM_DW.obj_d.isSetupComplete = false;
    Group30_SFWR_Assignment1_SIM_DW.obj_d.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(0U, 0);
    Group30_SFWR_Assignment1_SIM_DW.obj_d.isSetupComplete = true;

    /* Start for MATLABSystem: '<S6>/VENTRICLE_CMP_DETECT' */
    Group30_SFWR_Assignment1_SIM_DW.obj.matlabCodegenIsDeleted = true;
    Group30_SFWR_Assignment1_SIM_DW.obj.isInitialized = 0;
    Group30_SFWR_Assignment1_SIM_DW.obj.SampleTime = -1.0;
    Group30_SFWR_Assignment1_SIM_DW.obj.matlabCodegenIsDeleted = false;
    Group30_SFWR_Assignment1_SIM_DW.obj.SampleTime =
      Group30_SFWR_Assignment1_SIMU_P.VENTRICLE_CMP_DETECT_SampleTime;
    obj = &Group30_SFWR_Assignment1_SIM_DW.obj;
    Group30_SFWR_Assignment1_SIM_DW.obj.isSetupComplete = false;
    Group30_SFWR_Assignment1_SIM_DW.obj.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(1U, 0);
    Group30_SFWR_Assignment1_SIM_DW.obj.isSetupComplete = true;

    /* Start for MATLABSystem: '<S9>/PACE_CHARGE_CONTROL' */
    Group30_SFWR_Assignment1_SIM_DW.obj_jy.matlabCodegenIsDeleted = true;
    Group30_SFWR_Assignment1_SIM_DW.obj_jy.isInitialized = 0;
    Group30_SFWR_Assignment1_SIM_DW.obj_jy.matlabCodegenIsDeleted = false;
    obj_0 = &Group30_SFWR_Assignment1_SIM_DW.obj_jy;
    Group30_SFWR_Assignment1_SIM_DW.obj_jy.isSetupComplete = false;
    Group30_SFWR_Assignment1_SIM_DW.obj_jy.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(2U, 1);
    Group30_SFWR_Assignment1_SIM_DW.obj_jy.isSetupComplete = true;

    /* Start for MATLABSystem: '<S9>/Z_ATRIAL_CONTROL' */
    Group30_SFWR_Assignment1_SIM_DW.obj_lf.matlabCodegenIsDeleted = true;
    Group30_SFWR_Assignment1_SIM_DW.obj_lf.isInitialized = 0;
    Group30_SFWR_Assignment1_SIM_DW.obj_lf.matlabCodegenIsDeleted = false;
    obj_0 = &Group30_SFWR_Assignment1_SIM_DW.obj_lf;
    Group30_SFWR_Assignment1_SIM_DW.obj_lf.isSetupComplete = false;
    Group30_SFWR_Assignment1_SIM_DW.obj_lf.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(4U, 1);
    Group30_SFWR_Assignment1_SIM_DW.obj_lf.isSetupComplete = true;

    /* Start for MATLABSystem: '<S9>/Z_VENTRICLE_CONTROL' */
    Group30_SFWR_Assignment1_SIM_DW.obj_n.matlabCodegenIsDeleted = true;
    Group30_SFWR_Assignment1_SIM_DW.obj_n.isInitialized = 0;
    Group30_SFWR_Assignment1_SIM_DW.obj_n.matlabCodegenIsDeleted = false;
    obj_0 = &Group30_SFWR_Assignment1_SIM_DW.obj_n;
    Group30_SFWR_Assignment1_SIM_DW.obj_n.isSetupComplete = false;
    Group30_SFWR_Assignment1_SIM_DW.obj_n.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(7U, 1);
    Group30_SFWR_Assignment1_SIM_DW.obj_n.isSetupComplete = true;

    /* Start for MATLABSystem: '<S9>/ATRIAL_PACE_CONTROL' */
    Group30_SFWR_Assignment1_SIM_DW.obj_e.matlabCodegenIsDeleted = true;
    Group30_SFWR_Assignment1_SIM_DW.obj_e.isInitialized = 0;
    Group30_SFWR_Assignment1_SIM_DW.obj_e.matlabCodegenIsDeleted = false;
    obj_0 = &Group30_SFWR_Assignment1_SIM_DW.obj_e;
    Group30_SFWR_Assignment1_SIM_DW.obj_e.isSetupComplete = false;
    Group30_SFWR_Assignment1_SIM_DW.obj_e.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(8U, 1);
    Group30_SFWR_Assignment1_SIM_DW.obj_e.isSetupComplete = true;

    /* Start for MATLABSystem: '<S9>/VENTRICLE_PACE_CONTROL' */
    Group30_SFWR_Assignment1_SIM_DW.obj_j1.matlabCodegenIsDeleted = true;
    Group30_SFWR_Assignment1_SIM_DW.obj_j1.isInitialized = 0;
    Group30_SFWR_Assignment1_SIM_DW.obj_j1.matlabCodegenIsDeleted = false;
    obj_0 = &Group30_SFWR_Assignment1_SIM_DW.obj_j1;
    Group30_SFWR_Assignment1_SIM_DW.obj_j1.isSetupComplete = false;
    Group30_SFWR_Assignment1_SIM_DW.obj_j1.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(9U, 1);
    Group30_SFWR_Assignment1_SIM_DW.obj_j1.isSetupComplete = true;

    /* Start for MATLABSystem: '<S9>/PACE_GROUND_CONTROL' */
    Group30_SFWR_Assignment1_SIM_DW.obj_f.matlabCodegenIsDeleted = true;
    Group30_SFWR_Assignment1_SIM_DW.obj_f.isInitialized = 0;
    Group30_SFWR_Assignment1_SIM_DW.obj_f.matlabCodegenIsDeleted = false;
    obj_0 = &Group30_SFWR_Assignment1_SIM_DW.obj_f;
    Group30_SFWR_Assignment1_SIM_DW.obj_f.isSetupComplete = false;
    Group30_SFWR_Assignment1_SIM_DW.obj_f.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(10U, 1);
    Group30_SFWR_Assignment1_SIM_DW.obj_f.isSetupComplete = true;

    /* Start for MATLABSystem: '<S9>/ATRIAL_GROUND_CONTROL' */
    Group30_SFWR_Assignment1_SIM_DW.obj_pz.matlabCodegenIsDeleted = true;
    Group30_SFWR_Assignment1_SIM_DW.obj_pz.isInitialized = 0;
    Group30_SFWR_Assignment1_SIM_DW.obj_pz.matlabCodegenIsDeleted = false;
    obj_0 = &Group30_SFWR_Assignment1_SIM_DW.obj_pz;
    Group30_SFWR_Assignment1_SIM_DW.obj_pz.isSetupComplete = false;
    Group30_SFWR_Assignment1_SIM_DW.obj_pz.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(11U, 1);
    Group30_SFWR_Assignment1_SIM_DW.obj_pz.isSetupComplete = true;

    /* Start for MATLABSystem: '<S9>/VENTRICLE_GROUND_CONTROL' */
    Group30_SFWR_Assignment1_SIM_DW.obj_m.matlabCodegenIsDeleted = true;
    Group30_SFWR_Assignment1_SIM_DW.obj_m.isInitialized = 0;
    Group30_SFWR_Assignment1_SIM_DW.obj_m.matlabCodegenIsDeleted = false;
    obj_0 = &Group30_SFWR_Assignment1_SIM_DW.obj_m;
    Group30_SFWR_Assignment1_SIM_DW.obj_m.isSetupComplete = false;
    Group30_SFWR_Assignment1_SIM_DW.obj_m.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(12U, 1);
    Group30_SFWR_Assignment1_SIM_DW.obj_m.isSetupComplete = true;

    /* Start for MATLABSystem: '<S9>/PACING_REF_PWM' */
    Group30_SFWR_Assignment1_SIM_DW.obj_k.matlabCodegenIsDeleted = true;
    Group30_SFWR_Assignment1_SIM_DW.obj_k.isInitialized = 0;
    Group30_SFWR_Assignment1_SIM_DW.obj_k.matlabCodegenIsDeleted = false;
    obj_1 = &Group30_SFWR_Assignment1_SIM_DW.obj_k;
    Group30_SFWR_Assignment1_SIM_DW.obj_k.isSetupComplete = false;
    Group30_SFWR_Assignment1_SIM_DW.obj_k.isInitialized = 1;
    obj_1->MW_PWM_HANDLE = MW_PWM_Open(5U, 2000.0, 40.0);
    MW_PWM_Start(Group30_SFWR_Assignment1_SIM_DW.obj_k.MW_PWM_HANDLE);
    Group30_SFWR_Assignment1_SIM_DW.obj_k.isSetupComplete = true;

    /* Start for MATLABSystem: '<S9>/FRONTEND_CTRL' */
    Group30_SFWR_Assignment1_SIM_DW.obj_p.matlabCodegenIsDeleted = true;
    Group30_SFWR_Assignment1_SIM_DW.obj_p.isInitialized = 0;
    Group30_SFWR_Assignment1_SIM_DW.obj_p.matlabCodegenIsDeleted = false;
    obj_0 = &Group30_SFWR_Assignment1_SIM_DW.obj_p;
    Group30_SFWR_Assignment1_SIM_DW.obj_p.isSetupComplete = false;
    Group30_SFWR_Assignment1_SIM_DW.obj_p.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(13U, 1);
    Group30_SFWR_Assignment1_SIM_DW.obj_p.isSetupComplete = true;

    /* Start for MATLABSystem: '<S6>/ATRIAL_CMP_RED_PWM' */
    Group30_SFWR_Assignment1_SIM_DW.obj_l.matlabCodegenIsDeleted = true;
    Group30_SFWR_Assignment1_SIM_DW.obj_l.isInitialized = 0;
    Group30_SFWR_Assignment1_SIM_DW.obj_l.matlabCodegenIsDeleted = false;
    obj_1 = &Group30_SFWR_Assignment1_SIM_DW.obj_l;
    Group30_SFWR_Assignment1_SIM_DW.obj_l.isSetupComplete = false;
    Group30_SFWR_Assignment1_SIM_DW.obj_l.isInitialized = 1;
    obj_1->MW_PWM_HANDLE = MW_PWM_Open(6U, 2000.0, 51.0);
    MW_PWM_Start(Group30_SFWR_Assignment1_SIM_DW.obj_l.MW_PWM_HANDLE);
    Group30_SFWR_Assignment1_SIM_DW.obj_l.isSetupComplete = true;

    /* Start for MATLABSystem: '<S6>/VENTRICLE_CMP_REF_PWM' */
    Group30_SFWR_Assignment1_SIM_DW.obj_a.matlabCodegenIsDeleted = true;
    Group30_SFWR_Assignment1_SIM_DW.obj_a.isInitialized = 0;
    Group30_SFWR_Assignment1_SIM_DW.obj_a.matlabCodegenIsDeleted = false;
    obj_1 = &Group30_SFWR_Assignment1_SIM_DW.obj_a;
    Group30_SFWR_Assignment1_SIM_DW.obj_a.isSetupComplete = false;
    Group30_SFWR_Assignment1_SIM_DW.obj_a.isInitialized = 1;
    obj_1->MW_PWM_HANDLE = MW_PWM_Open(3U, 2000.0, 60.0);
    MW_PWM_Start(Group30_SFWR_Assignment1_SIM_DW.obj_a.MW_PWM_HANDLE);
    Group30_SFWR_Assignment1_SIM_DW.obj_a.isSetupComplete = true;
  }
}

/* Model terminate function */
void Group30_SFWR_Assignment1_SIMULINK_terminate(void)
{
  /* Terminate for MATLABSystem: '<S4>/Serial Receive' */
  if (!Group30_SFWR_Assignment1_SIM_DW.obj_j.matlabCodegenIsDeleted) {
    Group30_SFWR_Assignment1_SIM_DW.obj_j.matlabCodegenIsDeleted = true;
    if ((Group30_SFWR_Assignment1_SIM_DW.obj_j.isInitialized == 1) &&
        Group30_SFWR_Assignment1_SIM_DW.obj_j.isSetupComplete) {
      MW_SCI_Close(Group30_SFWR_Assignment1_SIM_DW.obj_j.MW_SCIHANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/Serial Receive' */

  /* Terminate for S-Function (sfun_private_function_caller) generated from: '<S4>/Serial Transmit to the DCM' incorporates:
   *  SubSystem: '<S4>/Serial Transmit to the DCM'
   */
  Transmit_DCM_Term();

  /* End of Terminate for S-Function (sfun_private_function_caller) generated from: '<S4>/Serial Transmit to the DCM' */

  /* Terminate for MATLABSystem: '<S6>/ATRIAL_CMP_DETECT' */
  if (!Group30_SFWR_Assignment1_SIM_DW.obj_d.matlabCodegenIsDeleted) {
    Group30_SFWR_Assignment1_SIM_DW.obj_d.matlabCodegenIsDeleted = true;
    if ((Group30_SFWR_Assignment1_SIM_DW.obj_d.isInitialized == 1) &&
        Group30_SFWR_Assignment1_SIM_DW.obj_d.isSetupComplete) {
      MW_digitalIO_close
        (Group30_SFWR_Assignment1_SIM_DW.obj_d.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S6>/ATRIAL_CMP_DETECT' */

  /* Terminate for MATLABSystem: '<S6>/VENTRICLE_CMP_DETECT' */
  if (!Group30_SFWR_Assignment1_SIM_DW.obj.matlabCodegenIsDeleted) {
    Group30_SFWR_Assignment1_SIM_DW.obj.matlabCodegenIsDeleted = true;
    if ((Group30_SFWR_Assignment1_SIM_DW.obj.isInitialized == 1) &&
        Group30_SFWR_Assignment1_SIM_DW.obj.isSetupComplete) {
      MW_digitalIO_close(Group30_SFWR_Assignment1_SIM_DW.obj.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S6>/VENTRICLE_CMP_DETECT' */

  /* Terminate for MATLABSystem: '<S9>/PACE_CHARGE_CONTROL' */
  if (!Group30_SFWR_Assignment1_SIM_DW.obj_jy.matlabCodegenIsDeleted) {
    Group30_SFWR_Assignment1_SIM_DW.obj_jy.matlabCodegenIsDeleted = true;
    if ((Group30_SFWR_Assignment1_SIM_DW.obj_jy.isInitialized == 1) &&
        Group30_SFWR_Assignment1_SIM_DW.obj_jy.isSetupComplete) {
      MW_digitalIO_close
        (Group30_SFWR_Assignment1_SIM_DW.obj_jy.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S9>/PACE_CHARGE_CONTROL' */

  /* Terminate for MATLABSystem: '<S9>/Z_ATRIAL_CONTROL' */
  if (!Group30_SFWR_Assignment1_SIM_DW.obj_lf.matlabCodegenIsDeleted) {
    Group30_SFWR_Assignment1_SIM_DW.obj_lf.matlabCodegenIsDeleted = true;
    if ((Group30_SFWR_Assignment1_SIM_DW.obj_lf.isInitialized == 1) &&
        Group30_SFWR_Assignment1_SIM_DW.obj_lf.isSetupComplete) {
      MW_digitalIO_close
        (Group30_SFWR_Assignment1_SIM_DW.obj_lf.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S9>/Z_ATRIAL_CONTROL' */

  /* Terminate for MATLABSystem: '<S9>/Z_VENTRICLE_CONTROL' */
  if (!Group30_SFWR_Assignment1_SIM_DW.obj_n.matlabCodegenIsDeleted) {
    Group30_SFWR_Assignment1_SIM_DW.obj_n.matlabCodegenIsDeleted = true;
    if ((Group30_SFWR_Assignment1_SIM_DW.obj_n.isInitialized == 1) &&
        Group30_SFWR_Assignment1_SIM_DW.obj_n.isSetupComplete) {
      MW_digitalIO_close
        (Group30_SFWR_Assignment1_SIM_DW.obj_n.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S9>/Z_VENTRICLE_CONTROL' */

  /* Terminate for MATLABSystem: '<S9>/ATRIAL_PACE_CONTROL' */
  if (!Group30_SFWR_Assignment1_SIM_DW.obj_e.matlabCodegenIsDeleted) {
    Group30_SFWR_Assignment1_SIM_DW.obj_e.matlabCodegenIsDeleted = true;
    if ((Group30_SFWR_Assignment1_SIM_DW.obj_e.isInitialized == 1) &&
        Group30_SFWR_Assignment1_SIM_DW.obj_e.isSetupComplete) {
      MW_digitalIO_close
        (Group30_SFWR_Assignment1_SIM_DW.obj_e.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S9>/ATRIAL_PACE_CONTROL' */

  /* Terminate for MATLABSystem: '<S9>/VENTRICLE_PACE_CONTROL' */
  if (!Group30_SFWR_Assignment1_SIM_DW.obj_j1.matlabCodegenIsDeleted) {
    Group30_SFWR_Assignment1_SIM_DW.obj_j1.matlabCodegenIsDeleted = true;
    if ((Group30_SFWR_Assignment1_SIM_DW.obj_j1.isInitialized == 1) &&
        Group30_SFWR_Assignment1_SIM_DW.obj_j1.isSetupComplete) {
      MW_digitalIO_close
        (Group30_SFWR_Assignment1_SIM_DW.obj_j1.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S9>/VENTRICLE_PACE_CONTROL' */

  /* Terminate for MATLABSystem: '<S9>/PACE_GROUND_CONTROL' */
  if (!Group30_SFWR_Assignment1_SIM_DW.obj_f.matlabCodegenIsDeleted) {
    Group30_SFWR_Assignment1_SIM_DW.obj_f.matlabCodegenIsDeleted = true;
    if ((Group30_SFWR_Assignment1_SIM_DW.obj_f.isInitialized == 1) &&
        Group30_SFWR_Assignment1_SIM_DW.obj_f.isSetupComplete) {
      MW_digitalIO_close
        (Group30_SFWR_Assignment1_SIM_DW.obj_f.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S9>/PACE_GROUND_CONTROL' */

  /* Terminate for MATLABSystem: '<S9>/ATRIAL_GROUND_CONTROL' */
  if (!Group30_SFWR_Assignment1_SIM_DW.obj_pz.matlabCodegenIsDeleted) {
    Group30_SFWR_Assignment1_SIM_DW.obj_pz.matlabCodegenIsDeleted = true;
    if ((Group30_SFWR_Assignment1_SIM_DW.obj_pz.isInitialized == 1) &&
        Group30_SFWR_Assignment1_SIM_DW.obj_pz.isSetupComplete) {
      MW_digitalIO_close
        (Group30_SFWR_Assignment1_SIM_DW.obj_pz.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S9>/ATRIAL_GROUND_CONTROL' */

  /* Terminate for MATLABSystem: '<S9>/VENTRICLE_GROUND_CONTROL' */
  if (!Group30_SFWR_Assignment1_SIM_DW.obj_m.matlabCodegenIsDeleted) {
    Group30_SFWR_Assignment1_SIM_DW.obj_m.matlabCodegenIsDeleted = true;
    if ((Group30_SFWR_Assignment1_SIM_DW.obj_m.isInitialized == 1) &&
        Group30_SFWR_Assignment1_SIM_DW.obj_m.isSetupComplete) {
      MW_digitalIO_close
        (Group30_SFWR_Assignment1_SIM_DW.obj_m.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S9>/VENTRICLE_GROUND_CONTROL' */

  /* Terminate for MATLABSystem: '<S9>/PACING_REF_PWM' */
  if (!Group30_SFWR_Assignment1_SIM_DW.obj_k.matlabCodegenIsDeleted) {
    Group30_SFWR_Assignment1_SIM_DW.obj_k.matlabCodegenIsDeleted = true;
    if ((Group30_SFWR_Assignment1_SIM_DW.obj_k.isInitialized == 1) &&
        Group30_SFWR_Assignment1_SIM_DW.obj_k.isSetupComplete) {
      MW_PWM_Stop(Group30_SFWR_Assignment1_SIM_DW.obj_k.MW_PWM_HANDLE);
      MW_PWM_Close(Group30_SFWR_Assignment1_SIM_DW.obj_k.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S9>/PACING_REF_PWM' */

  /* Terminate for MATLABSystem: '<S9>/FRONTEND_CTRL' */
  if (!Group30_SFWR_Assignment1_SIM_DW.obj_p.matlabCodegenIsDeleted) {
    Group30_SFWR_Assignment1_SIM_DW.obj_p.matlabCodegenIsDeleted = true;
    if ((Group30_SFWR_Assignment1_SIM_DW.obj_p.isInitialized == 1) &&
        Group30_SFWR_Assignment1_SIM_DW.obj_p.isSetupComplete) {
      MW_digitalIO_close
        (Group30_SFWR_Assignment1_SIM_DW.obj_p.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S9>/FRONTEND_CTRL' */

  /* Terminate for MATLABSystem: '<S6>/ATRIAL_CMP_RED_PWM' */
  if (!Group30_SFWR_Assignment1_SIM_DW.obj_l.matlabCodegenIsDeleted) {
    Group30_SFWR_Assignment1_SIM_DW.obj_l.matlabCodegenIsDeleted = true;
    if ((Group30_SFWR_Assignment1_SIM_DW.obj_l.isInitialized == 1) &&
        Group30_SFWR_Assignment1_SIM_DW.obj_l.isSetupComplete) {
      MW_PWM_Stop(Group30_SFWR_Assignment1_SIM_DW.obj_l.MW_PWM_HANDLE);
      MW_PWM_Close(Group30_SFWR_Assignment1_SIM_DW.obj_l.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S6>/ATRIAL_CMP_RED_PWM' */

  /* Terminate for MATLABSystem: '<S6>/VENTRICLE_CMP_REF_PWM' */
  if (!Group30_SFWR_Assignment1_SIM_DW.obj_a.matlabCodegenIsDeleted) {
    Group30_SFWR_Assignment1_SIM_DW.obj_a.matlabCodegenIsDeleted = true;
    if ((Group30_SFWR_Assignment1_SIM_DW.obj_a.isInitialized == 1) &&
        Group30_SFWR_Assignment1_SIM_DW.obj_a.isSetupComplete) {
      MW_PWM_Stop(Group30_SFWR_Assignment1_SIM_DW.obj_a.MW_PWM_HANDLE);
      MW_PWM_Close(Group30_SFWR_Assignment1_SIM_DW.obj_a.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S6>/VENTRICLE_CMP_REF_PWM' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
