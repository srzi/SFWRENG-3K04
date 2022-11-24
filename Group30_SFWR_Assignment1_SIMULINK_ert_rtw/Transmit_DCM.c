/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Transmit_DCM.c
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

#include "Group30_SFWR_Assignment1_SIMULINK_types.h"
#include "Transmit_DCM_private.h"
#include "Group30_SFWR_Assignment1_SIMULINK.h"
#include "Transmit_DCM.h"
#include <string.h>
#include "rtwtypes.h"
#include <stddef.h>

/* Forward declaration for local functions */
static void Group30_SFWR_A_SystemCore_setup(freedomk64f_SCIWrite_Group30__T *obj);
static void Group30_SFWR_A_SystemCore_setup(freedomk64f_SCIWrite_Group30__T *obj)
{
  MW_SCI_Parity_Type ParityValue;
  MW_SCI_StopBits_Type StopBitsValue;
  uint32_T RxPinLoc;
  uint32_T SCIModuleLoc;
  obj->isSetupComplete = false;
  obj->isInitialized = 1;
  RxPinLoc = MW_UNDEFINED_VALUE;
  SCIModuleLoc = 0;
  obj->MW_SCIHANDLE = MW_SCI_Open(&SCIModuleLoc, false, RxPinLoc, 10U);
  MW_SCI_SetBaudrate(obj->MW_SCIHANDLE, 115200U);
  StopBitsValue = MW_SCI_STOPBITS_1;
  ParityValue = MW_SCI_PARITY_NONE;
  MW_SCI_SetFrameFormat(obj->MW_SCIHANDLE, 8, ParityValue, StopBitsValue);
  obj->isSetupComplete = true;
}

/* System initialize for Simulink Function: '<S4>/Serial Transmit to the DCM' */
void Transmit_DCM_Init(void)
{
  /* Start for MATLABSystem: '<S12>/Serial Transmit' */
  Group30_SFWR_Assignment1_SIM_DW.obj_ml.isInitialized = 0;
  Group30_SFWR_Assignment1_SIM_DW.obj_ml.matlabCodegenIsDeleted = false;
  Group30_SFWR_A_SystemCore_setup(&Group30_SFWR_Assignment1_SIM_DW.obj_ml);
}

/* Output and update for Simulink Function: '<S4>/Serial Transmit to the DCM' */
void Transmit_DCM(void)
{
  uint8_T TxDataLocChar[14];
  uint8_T rtb_TmpSignalConversionAtSerial[14];
  uint8_T status;

  /* SignalConversion generated from: '<S12>/ARP' */
  Group30_SFWR_Assignment1_SIMU_B.Atrial_Refractory_Period =
    Group30_SFWR_Assignment1_SIMU_B.Atrial_Refractory_Period_f;

  /* SignalConversion generated from: '<S12>/VRP' */
  Group30_SFWR_Assignment1_SIMU_B.Ventricle_Refractory_Period =
    Group30_SFWR_Assignment1_SIMU_B.Ventricle_Refractory_Period_k;

  /* S-Function (any2byte): '<S12>/Byte Pack4' */

  /* Pack: <S12>/Byte Pack4 */
  (void) memcpy(&Group30_SFWR_Assignment1_SIMU_B.BytePack4[0],
                &Group30_SFWR_Assignment1_SIMU_B.Atrial_Refractory_Period,
                2);

  /* S-Function (any2byte): '<S12>/Byte Pack5' */

  /* Pack: <S12>/Byte Pack5 */
  (void) memcpy(&Group30_SFWR_Assignment1_SIMU_B.BytePack5[0],
                &Group30_SFWR_Assignment1_SIMU_B.Ventricle_Refractory_Period,
                2);

  /* SignalConversion generated from: '<S12>/Serial Transmit' incorporates:
   *  SignalConversion generated from: '<S12>/Atrial_Amplitude'
   *  SignalConversion generated from: '<S12>/Atrial_PaceWidth'
   *  SignalConversion generated from: '<S12>/Atrial_Sensitivity'
   *  SignalConversion generated from: '<S12>/LowerRateLimit(BPM)'
   *  SignalConversion generated from: '<S12>/Pace Mode'
   *  SignalConversion generated from: '<S12>/Sensing_Control'
   *  SignalConversion generated from: '<S12>/UpperRateLimit(BPM)'
   *  SignalConversion generated from: '<S12>/Ventricle_Amplitude'
   *  SignalConversion generated from: '<S12>/Ventricle_PaceWidth'
   *  SignalConversion generated from: '<S12>/Ventricle_Sensitivity'
   */
  rtb_TmpSignalConversionAtSerial[0] = Group30_SFWR_Assignment1_SIMU_B.Pace_Mode;
  rtb_TmpSignalConversionAtSerial[1] =
    Group30_SFWR_Assignment1_SIMU_B.Sensing_Control;
  rtb_TmpSignalConversionAtSerial[2] =
    Group30_SFWR_Assignment1_SIMU_B.Atrial_Amplitude;
  rtb_TmpSignalConversionAtSerial[3] =
    Group30_SFWR_Assignment1_SIMU_B.Ventricle_Amplitude;
  rtb_TmpSignalConversionAtSerial[4] =
    Group30_SFWR_Assignment1_SIMU_B.Atrial_PaceWidth;
  rtb_TmpSignalConversionAtSerial[5] =
    Group30_SFWR_Assignment1_SIMU_B.Ventricle_PaceWidth;
  rtb_TmpSignalConversionAtSerial[6] =
    Group30_SFWR_Assignment1_SIMU_B.BytePack4[0];
  rtb_TmpSignalConversionAtSerial[8] =
    Group30_SFWR_Assignment1_SIMU_B.BytePack5[0];
  rtb_TmpSignalConversionAtSerial[7] =
    Group30_SFWR_Assignment1_SIMU_B.BytePack4[1];
  rtb_TmpSignalConversionAtSerial[9] =
    Group30_SFWR_Assignment1_SIMU_B.BytePack5[1];
  rtb_TmpSignalConversionAtSerial[10] =
    Group30_SFWR_Assignment1_SIMU_B.Lower_Rate_Limit;
  rtb_TmpSignalConversionAtSerial[11] =
    Group30_SFWR_Assignment1_SIMU_B.Upper_Rate_Limit;
  rtb_TmpSignalConversionAtSerial[12] =
    Group30_SFWR_Assignment1_SIMU_B.Atrial_Sensitivity;
  rtb_TmpSignalConversionAtSerial[13] =
    Group30_SFWR_Assignment1_SIMU_B.Ventricle_Sensitivity;

  /* MATLABSystem: '<S12>/Serial Transmit' */
  status = 1U;
  while (status != 0) {
    memcpy((void *)&TxDataLocChar[0], (void *)&rtb_TmpSignalConversionAtSerial[0],
           (uint32_T)((size_t)14 * sizeof(uint8_T)));
    status = MW_SCI_Transmit(Group30_SFWR_Assignment1_SIM_DW.obj_ml.MW_SCIHANDLE,
      &TxDataLocChar[0], 14U);
  }

  /* End of MATLABSystem: '<S12>/Serial Transmit' */
}

/* Termination for Simulink Function: '<S4>/Serial Transmit to the DCM' */
void Transmit_DCM_Term(void)
{
  /* Terminate for MATLABSystem: '<S12>/Serial Transmit' */
  if (!Group30_SFWR_Assignment1_SIM_DW.obj_ml.matlabCodegenIsDeleted) {
    Group30_SFWR_Assignment1_SIM_DW.obj_ml.matlabCodegenIsDeleted = true;
    if ((Group30_SFWR_Assignment1_SIM_DW.obj_ml.isInitialized == 1) &&
        Group30_SFWR_Assignment1_SIM_DW.obj_ml.isSetupComplete) {
      MW_SCI_Close(Group30_SFWR_Assignment1_SIM_DW.obj_ml.MW_SCIHANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S12>/Serial Transmit' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
