/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Group30_SFWR_Assignment1_SIMULINK_types.h
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

#ifndef RTW_HEADER_Group30_SFWR_Assignment1_SIMULINK_types_h_
#define RTW_HEADER_Group30_SFWR_Assignment1_SIMULINK_types_h_
#include "rtwtypes.h"
#include "MW_SVD.h"

/* Model Code Variants */
#ifndef DEFINED_TYPEDEF_FOR_slTestResult_
#define DEFINED_TYPEDEF_FOR_slTestResult_

typedef enum {
  slTestResult_Untested = -1,          /* Default value */
  slTestResult_Pass,
  slTestResult_Fail
} slTestResult;

#endif

/* Custom Type definition for MATLABSystem: '<S12>/Serial Transmit' */
#include "MW_SVD.h"
#ifndef struct_tag_0QIIqIWUIOhUbf1p9QN9pB
#define struct_tag_0QIIqIWUIOhUbf1p9QN9pB

struct tag_0QIIqIWUIOhUbf1p9QN9pB
{
  int32_T __dummy;
};

#endif                                 /* struct_tag_0QIIqIWUIOhUbf1p9QN9pB */

#ifndef typedef_b_freedomk64f_Hardware_Group3_T
#define typedef_b_freedomk64f_Hardware_Group3_T

typedef struct tag_0QIIqIWUIOhUbf1p9QN9pB b_freedomk64f_Hardware_Group3_T;

#endif                             /* typedef_b_freedomk64f_Hardware_Group3_T */

#ifndef struct_tag_GV9UedAE1zOVNNbkXknChB
#define struct_tag_GV9UedAE1zOVNNbkXknChB

struct tag_GV9UedAE1zOVNNbkXknChB
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  b_freedomk64f_Hardware_Group3_T Hw;
  MW_Handle_Type MW_SCIHANDLE;
};

#endif                                 /* struct_tag_GV9UedAE1zOVNNbkXknChB */

#ifndef typedef_freedomk64f_SCIWrite_Group30__T
#define typedef_freedomk64f_SCIWrite_Group30__T

typedef struct tag_GV9UedAE1zOVNNbkXknChB freedomk64f_SCIWrite_Group30__T;

#endif                             /* typedef_freedomk64f_SCIWrite_Group30__T */

#ifndef struct_tag_q6HQSF2nXq6EjCNj0vbuLD
#define struct_tag_q6HQSF2nXq6EjCNj0vbuLD

struct tag_q6HQSF2nXq6EjCNj0vbuLD
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  b_freedomk64f_Hardware_Group3_T Hw;
  MW_Handle_Type MW_DIGITALIO_HANDLE;
  real_T SampleTime;
};

#endif                                 /* struct_tag_q6HQSF2nXq6EjCNj0vbuLD */

#ifndef typedef_freedomk64f_DigitalRead_Group_T
#define typedef_freedomk64f_DigitalRead_Group_T

typedef struct tag_q6HQSF2nXq6EjCNj0vbuLD freedomk64f_DigitalRead_Group_T;

#endif                             /* typedef_freedomk64f_DigitalRead_Group_T */

#ifndef struct_tag_RYgVoAXTz61tXGMaBAGv7F
#define struct_tag_RYgVoAXTz61tXGMaBAGv7F

struct tag_RYgVoAXTz61tXGMaBAGv7F
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  b_freedomk64f_Hardware_Group3_T Hw;
  MW_Handle_Type MW_PWM_HANDLE;
};

#endif                                 /* struct_tag_RYgVoAXTz61tXGMaBAGv7F */

#ifndef typedef_freedomk64f_PWMOutput_Group30_T
#define typedef_freedomk64f_PWMOutput_Group30_T

typedef struct tag_RYgVoAXTz61tXGMaBAGv7F freedomk64f_PWMOutput_Group30_T;

#endif                             /* typedef_freedomk64f_PWMOutput_Group30_T */

#ifndef struct_tag_EkIWEs70Gs0LyfeXELZ2TC
#define struct_tag_EkIWEs70Gs0LyfeXELZ2TC

struct tag_EkIWEs70Gs0LyfeXELZ2TC
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  b_freedomk64f_Hardware_Group3_T Hw;
  MW_Handle_Type MW_DIGITALIO_HANDLE;
};

#endif                                 /* struct_tag_EkIWEs70Gs0LyfeXELZ2TC */

#ifndef typedef_freedomk64f_DigitalWrite_Grou_T
#define typedef_freedomk64f_DigitalWrite_Grou_T

typedef struct tag_EkIWEs70Gs0LyfeXELZ2TC freedomk64f_DigitalWrite_Grou_T;

#endif                             /* typedef_freedomk64f_DigitalWrite_Grou_T */

#ifndef struct_tag_214cR1nKZWaoqoq0FTtOUH
#define struct_tag_214cR1nKZWaoqoq0FTtOUH

struct tag_214cR1nKZWaoqoq0FTtOUH
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  b_freedomk64f_Hardware_Group3_T Hw;
  MW_Handle_Type MW_SCIHANDLE;
  real_T SampleTime;
};

#endif                                 /* struct_tag_214cR1nKZWaoqoq0FTtOUH */

#ifndef typedef_freedomk64f_SCIRead_Group30_S_T
#define typedef_freedomk64f_SCIRead_Group30_S_T

typedef struct tag_214cR1nKZWaoqoq0FTtOUH freedomk64f_SCIRead_Group30_S_T;

#endif                             /* typedef_freedomk64f_SCIRead_Group30_S_T */

/* Parameters (default storage) */
typedef struct P_Group30_SFWR_Assignment1_SI_T_ P_Group30_SFWR_Assignment1_SI_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_Group30_SFWR_Assignme_T RT_MODEL_Group30_SFWR_Assignm_T;

#endif               /* RTW_HEADER_Group30_SFWR_Assignment1_SIMULINK_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
