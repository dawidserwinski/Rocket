/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: rakieta_model_do_autogeneracji_kodu.h
 *
 * Code generated for Simulink model 'rakieta_model_do_autogeneracji_kodu'.
 *
 * Model version                  : 1.20
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Sat Sep 10 14:30:00 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_rakieta_model_do_autogeneracji_kodu_h_
#define RTW_HEADER_rakieta_model_do_autogeneracji_kodu_h_
#include "rtwtypes.h"
#include <stddef.h>
#include <math.h>
#include <string.h>
#include <stddef.h>
#ifndef rakieta_model_do_autogeneracji_kodu_COMMON_INCLUDES_
# define rakieta_model_do_autogeneracji_kodu_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* rakieta_model_do_autogeneracji_kodu_COMMON_INCLUDES_ */

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Forward declaration for rtModel */
typedef struct tag_RTM RT_MODEL;

#ifndef DEFINED_TYPEDEF_FOR_struct_ZYAZzDLQhdIHp0QjDdTYKF_
#define DEFINED_TYPEDEF_FOR_struct_ZYAZzDLQhdIHp0QjDdTYKF_

typedef struct {
  uint8_T SimulinkDiagnostic;
  uint8_T Model[35];
  uint8_T Block[44];
  uint8_T OutOfRangeInputValue;
  uint8_T NoRuleFired;
  uint8_T EmptyOutputFuzzySet;
} struct_ZYAZzDLQhdIHp0QjDdTYKF;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_nDiNttezQ8pHMZv76leKsH_
#define DEFINED_TYPEDEF_FOR_struct_nDiNttezQ8pHMZv76leKsH_

typedef struct {
  uint8_T type[6];
  int32_T origTypeLength;
  real_T params[4];
  int32_T origParamLength;
} struct_nDiNttezQ8pHMZv76leKsH;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_6VzYiVW2hAWQCI9jAYOVeF_
#define DEFINED_TYPEDEF_FOR_struct_6VzYiVW2hAWQCI9jAYOVeF_

typedef struct {
  struct_nDiNttezQ8pHMZv76leKsH mf[3];
  int32_T origNumMF;
} struct_6VzYiVW2hAWQCI9jAYOVeF;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_RCP1oovUDF2zF6C9vcJmtG_
#define DEFINED_TYPEDEF_FOR_struct_RCP1oovUDF2zF6C9vcJmtG_

typedef struct {
  uint8_T type[5];
  int32_T origTypeLength;
  real_T params[3];
  int32_T origParamLength;
} struct_RCP1oovUDF2zF6C9vcJmtG;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_xaJpTrGDqNmvd5vaYMDkGD_
#define DEFINED_TYPEDEF_FOR_struct_xaJpTrGDqNmvd5vaYMDkGD_

typedef struct {
  struct_RCP1oovUDF2zF6C9vcJmtG mf[7];
  int32_T origNumMF;
} struct_xaJpTrGDqNmvd5vaYMDkGD;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_4J6WXgW8L0lD3CnE2ROeNB_
#define DEFINED_TYPEDEF_FOR_struct_4J6WXgW8L0lD3CnE2ROeNB_

typedef struct {
  uint8_T type[7];
  uint8_T andMethod[3];
  uint8_T orMethod[3];
  uint8_T defuzzMethod[8];
  uint8_T impMethod[3];
  uint8_T aggMethod[3];
  real_T inputRange[4];
  real_T outputRange[2];
  struct_6VzYiVW2hAWQCI9jAYOVeF inputMF[2];
  struct_xaJpTrGDqNmvd5vaYMDkGD outputMF;
  real_T antecedent[18];
  real_T consequent[9];
  real_T connection[9];
  real_T weight[9];
  int32_T numSamples;
  int32_T numInputs;
  int32_T numOutputs;
  int32_T numRules;
  int32_T numInputMFs[2];
  int32_T numCumInputMFs[2];
  int32_T numOutputMFs;
  int32_T numCumOutputMFs;
  real_T outputSamplePoints[100];
  int32_T orrSize[2];
  int32_T aggSize[2];
} struct_4J6WXgW8L0lD3CnE2ROeNB;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_ZzcqxGmmGnVzXNp2UR5XbG_
#define DEFINED_TYPEDEF_FOR_struct_ZzcqxGmmGnVzXNp2UR5XbG_

typedef struct {
  uint8_T SimulinkDiagnostic;
  uint8_T Model[35];
  uint8_T Block[46];
  uint8_T OutOfRangeInputValue;
  uint8_T NoRuleFired;
  uint8_T EmptyOutputFuzzySet;
} struct_ZzcqxGmmGnVzXNp2UR5XbG;

#endif

/* Custom Type definition for MATLAB Function: '<S4>/Evaluate Rule Consequents' */
#ifndef struct_tag_s5auVAtj0sXVTykAgnl5VDF
#define struct_tag_s5auVAtj0sXVTykAgnl5VDF

struct tag_s5auVAtj0sXVTykAgnl5VDF
{
  uint8_T type[6];
  int32_T origTypeLength;
  real_T params[4];
  int32_T origParamLength;
};

#endif                                 /*struct_tag_s5auVAtj0sXVTykAgnl5VDF*/

#ifndef typedef_s5auVAtj0sXVTykAgnl5VDF
#define typedef_s5auVAtj0sXVTykAgnl5VDF

typedef struct tag_s5auVAtj0sXVTykAgnl5VDF s5auVAtj0sXVTykAgnl5VDF;

#endif                                 /*typedef_s5auVAtj0sXVTykAgnl5VDF*/

#ifndef struct_tag_svsFxM4ngCdn87vGXXvLrxC
#define struct_tag_svsFxM4ngCdn87vGXXvLrxC

struct tag_svsFxM4ngCdn87vGXXvLrxC
{
  s5auVAtj0sXVTykAgnl5VDF mf[3];
  int32_T origNumMF;
};

#endif                                 /*struct_tag_svsFxM4ngCdn87vGXXvLrxC*/

#ifndef typedef_svsFxM4ngCdn87vGXXvLrxC
#define typedef_svsFxM4ngCdn87vGXXvLrxC

typedef struct tag_svsFxM4ngCdn87vGXXvLrxC svsFxM4ngCdn87vGXXvLrxC;

#endif                                 /*typedef_svsFxM4ngCdn87vGXXvLrxC*/

#ifndef struct_tag_sDfM9XCdU9DLkphJPFDd11C
#define struct_tag_sDfM9XCdU9DLkphJPFDd11C

struct tag_sDfM9XCdU9DLkphJPFDd11C
{
  uint8_T type[5];
  int32_T origTypeLength;
  real_T params[3];
  int32_T origParamLength;
};

#endif                                 /*struct_tag_sDfM9XCdU9DLkphJPFDd11C*/

#ifndef typedef_sDfM9XCdU9DLkphJPFDd11C
#define typedef_sDfM9XCdU9DLkphJPFDd11C

typedef struct tag_sDfM9XCdU9DLkphJPFDd11C sDfM9XCdU9DLkphJPFDd11C;

#endif                                 /*typedef_sDfM9XCdU9DLkphJPFDd11C*/

#ifndef struct_tag_sTohsHfcc6R2teRT5o0XNVG
#define struct_tag_sTohsHfcc6R2teRT5o0XNVG

struct tag_sTohsHfcc6R2teRT5o0XNVG
{
  sDfM9XCdU9DLkphJPFDd11C mf[7];
  int32_T origNumMF;
};

#endif                                 /*struct_tag_sTohsHfcc6R2teRT5o0XNVG*/

#ifndef typedef_sTohsHfcc6R2teRT5o0XNVG
#define typedef_sTohsHfcc6R2teRT5o0XNVG

typedef struct tag_sTohsHfcc6R2teRT5o0XNVG sTohsHfcc6R2teRT5o0XNVG;

#endif                                 /*typedef_sTohsHfcc6R2teRT5o0XNVG*/

#ifndef struct_tag_sCqzMDLvceTB4YAHI1mHjFF
#define struct_tag_sCqzMDLvceTB4YAHI1mHjFF

struct tag_sCqzMDLvceTB4YAHI1mHjFF
{
  uint8_T type[7];
  uint8_T andMethod[3];
  uint8_T orMethod[3];
  uint8_T defuzzMethod[8];
  uint8_T impMethod[3];
  uint8_T aggMethod[3];
  real_T inputRange[4];
  real_T outputRange[2];
  svsFxM4ngCdn87vGXXvLrxC inputMF[2];
  sTohsHfcc6R2teRT5o0XNVG outputMF;
  real_T antecedent[18];
  real_T consequent[9];
  real_T connection[9];
  real_T weight[9];
  int32_T numSamples;
  int32_T numInputs;
  int32_T numOutputs;
  int32_T numRules;
  int32_T numInputMFs[2];
  int32_T numCumInputMFs[2];
  int32_T numOutputMFs;
  int32_T numCumOutputMFs;
  real_T outputSamplePoints[100];
  int32_T orrSize[2];
  int32_T aggSize[2];
};

#endif                                 /*struct_tag_sCqzMDLvceTB4YAHI1mHjFF*/

#ifndef typedef_sCqzMDLvceTB4YAHI1mHjFF
#define typedef_sCqzMDLvceTB4YAHI1mHjFF

typedef struct tag_sCqzMDLvceTB4YAHI1mHjFF sCqzMDLvceTB4YAHI1mHjFF;

#endif                                 /*typedef_sCqzMDLvceTB4YAHI1mHjFF*/

#ifndef struct_tag_sXsSeVB4E0ntMvFGNG3D1eC
#define struct_tag_sXsSeVB4E0ntMvFGNG3D1eC

struct tag_sXsSeVB4E0ntMvFGNG3D1eC
{
  uint8_T type[5];
  real_T params[3];
};

#endif                                 /*struct_tag_sXsSeVB4E0ntMvFGNG3D1eC*/

#ifndef typedef_sXsSeVB4E0ntMvFGNG3D1eC
#define typedef_sXsSeVB4E0ntMvFGNG3D1eC

typedef struct tag_sXsSeVB4E0ntMvFGNG3D1eC sXsSeVB4E0ntMvFGNG3D1eC;

#endif                                 /*typedef_sXsSeVB4E0ntMvFGNG3D1eC*/

/* Custom Type definition for MATLAB Function: '<S4>/Evaluate Rule Antecedents' */
#ifndef struct_tag_s28r02x6cXWXMPN55JOTJ2C
#define struct_tag_s28r02x6cXWXMPN55JOTJ2C

struct tag_s28r02x6cXWXMPN55JOTJ2C
{
  uint8_T SimulinkDiagnostic;
  uint8_T Model[35];
  uint8_T Block[44];
  uint8_T OutOfRangeInputValue;
  uint8_T NoRuleFired;
  uint8_T EmptyOutputFuzzySet;
};

#endif                                 /*struct_tag_s28r02x6cXWXMPN55JOTJ2C*/

#ifndef typedef_s28r02x6cXWXMPN55JOTJ2C
#define typedef_s28r02x6cXWXMPN55JOTJ2C

typedef struct tag_s28r02x6cXWXMPN55JOTJ2C s28r02x6cXWXMPN55JOTJ2C;

#endif                                 /*typedef_s28r02x6cXWXMPN55JOTJ2C*/

/* Custom Type definition for MATLAB Function: '<S5>/Evaluate Rule Antecedents' */
#ifndef struct_tag_sculW9uT2riFhoDCGUFgphB
#define struct_tag_sculW9uT2riFhoDCGUFgphB

struct tag_sculW9uT2riFhoDCGUFgphB
{
  uint8_T type[6];
  real_T params[4];
};

#endif                                 /*struct_tag_sculW9uT2riFhoDCGUFgphB*/

#ifndef typedef_sculW9uT2riFhoDCGUFgphB
#define typedef_sculW9uT2riFhoDCGUFgphB

typedef struct tag_sculW9uT2riFhoDCGUFgphB sculW9uT2riFhoDCGUFgphB;

#endif                                 /*typedef_sculW9uT2riFhoDCGUFgphB*/

#ifndef struct_tag_sclvsB4lMKuxCdVQBUB1e4D
#define struct_tag_sclvsB4lMKuxCdVQBUB1e4D

struct tag_sclvsB4lMKuxCdVQBUB1e4D
{
  uint8_T SimulinkDiagnostic;
  uint8_T Model[35];
  uint8_T Block[46];
  uint8_T OutOfRangeInputValue;
  uint8_T NoRuleFired;
  uint8_T EmptyOutputFuzzySet;
};

#endif                                 /*struct_tag_sclvsB4lMKuxCdVQBUB1e4D*/

#ifndef typedef_sclvsB4lMKuxCdVQBUB1e4D
#define typedef_sclvsB4lMKuxCdVQBUB1e4D

typedef struct tag_sclvsB4lMKuxCdVQBUB1e4D sclvsB4lMKuxCdVQBUB1e4D;

#endif                                 /*typedef_sclvsB4lMKuxCdVQBUB1e4D*/

/* Block signals and states (default storage) for system '<S4>/Evaluate Rule Consequents' */
typedef struct {
  real_T outputMFCache[700];
} DW_EvaluateRuleConsequents;

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  DW_EvaluateRuleConsequents sf_EvaluateRuleConsequents_i;/* '<S5>/Evaluate Rule Consequents' */
  DW_EvaluateRuleConsequents sf_EvaluateRuleConsequents;/* '<S4>/Evaluate Rule Consequents' */
} DW;

/* Constant parameters (default storage) */
typedef struct {
  /* Pooled Parameter (Expression: fis.outputSamplePoints)
   * Referenced by:
   *   '<S4>/Output Sample Points'
   *   '<S5>/Output Sample Points'
   */
  real_T pooled2[100];
} ConstP;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T v;                            /* '<Root>/v' */
  real_T przechylenie;                 /* '<Root>/przechylenie' */
  real_T pochylenie;                   /* '<Root>/pochylenie' */
} ExtU;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T kanal_przech;                 /* '<Root>/kanal_przech' */
  real_T kanal_poch;                   /* '<Root>/kanal_poch' */
} ExtY;

/* Real-time Model Data Structure */
struct tag_RTM {
  const char_T * volatile errorStatus;
};

/* Block signals and states (default storage) */
extern DW rtDW;

/* External inputs (root inport signals with default storage) */
extern ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY rtY;

/* Constant parameters (default storage) */
extern const ConstP rtConstP;

/* Model entry point functions */
extern void rakieta_model_do_autogeneracji_kodu_initialize(void);
extern void rakieta_model_do_autogeneracji_kodu_step(void);

/* Real-time Model object */
extern RT_MODEL *const rtM;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S4>/InputConversion' : Eliminate redundant data type conversion
 * Block '<S5>/InputConversion' : Eliminate redundant data type conversion
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
 * '<Root>' : 'rakieta_model_do_autogeneracji_kodu'
 * '<S1>'   : 'rakieta_model_do_autogeneracji_kodu/ograniczenie_kata pochylenia'
 * '<S2>'   : 'rakieta_model_do_autogeneracji_kodu/ograniczenie_kata przechylenia'
 * '<S3>'   : 'rakieta_model_do_autogeneracji_kodu/ograniczenie_predkosci'
 * '<S4>'   : 'rakieta_model_do_autogeneracji_kodu/reg_poch'
 * '<S5>'   : 'rakieta_model_do_autogeneracji_kodu/reg_przech'
 * '<S6>'   : 'rakieta_model_do_autogeneracji_kodu/reg_poch/Defuzzify Outputs'
 * '<S7>'   : 'rakieta_model_do_autogeneracji_kodu/reg_poch/Evaluate Rule Antecedents'
 * '<S8>'   : 'rakieta_model_do_autogeneracji_kodu/reg_poch/Evaluate Rule Consequents'
 * '<S9>'   : 'rakieta_model_do_autogeneracji_kodu/reg_przech/Defuzzify Outputs'
 * '<S10>'  : 'rakieta_model_do_autogeneracji_kodu/reg_przech/Evaluate Rule Antecedents'
 * '<S11>'  : 'rakieta_model_do_autogeneracji_kodu/reg_przech/Evaluate Rule Consequents'
 */
#endif                                 /* RTW_HEADER_rakieta_model_do_autogeneracji_kodu_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
