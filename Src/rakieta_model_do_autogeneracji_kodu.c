/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: rakieta_model_do_autogeneracji_kodu.c
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

#include "rakieta_model_do_autogeneracji_kodu.h"
#define NumBitsPerChar                 8U

/* Block signals and states (default storage) */
DW rtDW;

/* External inputs (root inport signals with default storage) */
ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
ExtY rtY;

/* Real-time model */
RT_MODEL rtM_;
RT_MODEL *const rtM = &rtM_;
static void ograniczenie_katapochylenia(real_T rtu_u, real_T *rty_y);
static void EvaluateRuleConsequents(const real_T rtu_antecedentOutputs[9], const
  real_T rtu_samplePoints[100], real_T rty_aggregatedOutputs[100],
  DW_EvaluateRuleConsequents *localDW);

/* Forward declaration for local functions */
static void trimf(const real_T x[100], const real_T params[3], real_T y[100]);
static void createMamdaniOutputMFCache(const real_T outputSamplePoints[100],
  real_T outputMFCache[700]);
static int32_T abs_c(int32_T x);
static real_T evaluateAndMethod(const real_T x[2]);
static real_T evaluateOrMethod(const real_T x[2]);

/* Forward declaration for local functions */
static real_T trapmf(real_T x, const real_T params[4]);
static real_T trimf_b(real_T x, const real_T params[3]);
extern real_T rtInf;
extern real_T rtMinusInf;
extern real_T rtNaN;
extern real32_T rtInfF;
extern real32_T rtMinusInfF;
extern real32_T rtNaNF;
extern void rt_InitInfAndNaN(size_t realSize);
extern boolean_T rtIsInf(real_T value);
extern boolean_T rtIsInfF(real32_T value);
extern boolean_T rtIsNaN(real_T value);
extern boolean_T rtIsNaNF(real32_T value);
typedef struct {
  struct {
    uint32_T wordH;
    uint32_T wordL;
  } words;
} BigEndianIEEEDouble;

typedef struct {
  struct {
    uint32_T wordL;
    uint32_T wordH;
  } words;
} LittleEndianIEEEDouble;

typedef struct {
  union {
    real32_T wordLreal;
    uint32_T wordLuint;
  } wordL;
} IEEESingle;

real_T rtInf;
real_T rtMinusInf;
real_T rtNaN;
real32_T rtInfF;
real32_T rtMinusInfF;
real32_T rtNaNF;
extern real_T rtGetInf(void);
extern real32_T rtGetInfF(void);
extern real_T rtGetMinusInf(void);
extern real32_T rtGetMinusInfF(void);
extern real_T rtGetNaN(void);
extern real32_T rtGetNaNF(void);

/*
 * Initialize the rtInf, rtMinusInf, and rtNaN needed by the
 * generated code. NaN is initialized as non-signaling. Assumes IEEE.
 */
void rt_InitInfAndNaN(size_t realSize)
{
  (void) (realSize);
  rtNaN = rtGetNaN();
  rtNaNF = rtGetNaNF();
  rtInf = rtGetInf();
  rtInfF = rtGetInfF();
  rtMinusInf = rtGetMinusInf();
  rtMinusInfF = rtGetMinusInfF();
}

/* Test if value is infinite */
boolean_T rtIsInf(real_T value)
{
  return (boolean_T)((value==rtInf || value==rtMinusInf) ? 1U : 0U);
}

/* Test if single-precision value is infinite */
boolean_T rtIsInfF(real32_T value)
{
  return (boolean_T)(((value)==rtInfF || (value)==rtMinusInfF) ? 1U : 0U);
}

/* Test if value is not a number */
boolean_T rtIsNaN(real_T value)
{
  boolean_T result = (boolean_T) 0;
  size_t bitsPerReal = sizeof(real_T) * (NumBitsPerChar);
  if (bitsPerReal == 32U) {
    result = rtIsNaNF((real32_T)value);
  } else {
    union {
      LittleEndianIEEEDouble bitVal;
      real_T fltVal;
    } tmpVal;

    tmpVal.fltVal = value;
    result = (boolean_T)((tmpVal.bitVal.words.wordH & 0x7FF00000) == 0x7FF00000 &&
                         ( (tmpVal.bitVal.words.wordH & 0x000FFFFF) != 0 ||
                          (tmpVal.bitVal.words.wordL != 0) ));
  }

  return result;
}

/* Test if single-precision value is not a number */
boolean_T rtIsNaNF(real32_T value)
{
  IEEESingle tmp;
  tmp.wordL.wordLreal = value;
  return (boolean_T)( (tmp.wordL.wordLuint & 0x7F800000) == 0x7F800000 &&
                     (tmp.wordL.wordLuint & 0x007FFFFF) != 0 );
}

/*
 * Initialize rtInf needed by the generated code.
 * Inf is initialized as non-signaling. Assumes IEEE.
 */
real_T rtGetInf(void)
{
  size_t bitsPerReal = sizeof(real_T) * (NumBitsPerChar);
  real_T inf = 0.0;
  if (bitsPerReal == 32U) {
    inf = rtGetInfF();
  } else {
    union {
      LittleEndianIEEEDouble bitVal;
      real_T fltVal;
    } tmpVal;

    tmpVal.bitVal.words.wordH = 0x7FF00000U;
    tmpVal.bitVal.words.wordL = 0x00000000U;
    inf = tmpVal.fltVal;
  }

  return inf;
}

/*
 * Initialize rtInfF needed by the generated code.
 * Inf is initialized as non-signaling. Assumes IEEE.
 */
real32_T rtGetInfF(void)
{
  IEEESingle infF;
  infF.wordL.wordLuint = 0x7F800000U;
  return infF.wordL.wordLreal;
}

/*
 * Initialize rtMinusInf needed by the generated code.
 * Inf is initialized as non-signaling. Assumes IEEE.
 */
real_T rtGetMinusInf(void)
{
  size_t bitsPerReal = sizeof(real_T) * (NumBitsPerChar);
  real_T minf = 0.0;
  if (bitsPerReal == 32U) {
    minf = rtGetMinusInfF();
  } else {
    union {
      LittleEndianIEEEDouble bitVal;
      real_T fltVal;
    } tmpVal;

    tmpVal.bitVal.words.wordH = 0xFFF00000U;
    tmpVal.bitVal.words.wordL = 0x00000000U;
    minf = tmpVal.fltVal;
  }

  return minf;
}

/*
 * Initialize rtMinusInfF needed by the generated code.
 * Inf is initialized as non-signaling. Assumes IEEE.
 */
real32_T rtGetMinusInfF(void)
{
  IEEESingle minfF;
  minfF.wordL.wordLuint = 0xFF800000U;
  return minfF.wordL.wordLreal;
}

/*
 * Initialize rtNaN needed by the generated code.
 * NaN is initialized as non-signaling. Assumes IEEE.
 */
real_T rtGetNaN(void)
{
  size_t bitsPerReal = sizeof(real_T) * (NumBitsPerChar);
  real_T nan = 0.0;
  if (bitsPerReal == 32U) {
    nan = rtGetNaNF();
  } else {
    union {
      LittleEndianIEEEDouble bitVal;
      real_T fltVal;
    } tmpVal;

    tmpVal.bitVal.words.wordH = 0xFFF80000U;
    tmpVal.bitVal.words.wordL = 0x00000000U;
    nan = tmpVal.fltVal;
  }

  return nan;
}

/*
 * Initialize rtNaNF needed by the generated code.
 * NaN is initialized as non-signaling. Assumes IEEE.
 */
real32_T rtGetNaNF(void)
{
  IEEESingle nanF = { { 0 } };

  nanF.wordL.wordLuint = 0xFFC00000U;
  return nanF.wordL.wordLreal;
}

/*
 * Output and update for atomic system:
 *    '<Root>/ograniczenie_kata pochylenia'
 *    '<Root>/ograniczenie_kata przechylenia'
 */
static void ograniczenie_katapochylenia(real_T rtu_u, real_T *rty_y)
{
  *rty_y = rtu_u;
  if ((!(rtu_u >= -90.0)) || (!(rtu_u <= 90.0))) {
    if (rtu_u < -90.0) {
      *rty_y = -90.0;
    } else {
      if (rtu_u > 90.0) {
        *rty_y = 90.0;
      }
    }
  }
}

/* Function for MATLAB Function: '<S4>/Evaluate Rule Consequents' */
static void trimf(const real_T x[100], const real_T params[3], real_T y[100])
{
  real_T a;
  real_T b;
  real_T c;
  int32_T i;
  a = params[0];
  b = params[1];
  c = params[2];
  for (i = 0; i < 100; i++) {
    y[i] = 0.0;
    if ((a != b) && (a < x[i]) && (x[i] < b)) {
      y[i] = 1.0 / (b - a) * (x[i] - a);
    }

    if ((b != c) && (b < x[i]) && (x[i] < c)) {
      y[i] = 1.0 / (c - b) * (c - x[i]);
    }

    if (x[i] == b) {
      y[i] = 1.0;
    }
  }
}

/* Function for MATLAB Function: '<S4>/Evaluate Rule Consequents' */
static void createMamdaniOutputMFCache(const real_T outputSamplePoints[100],
  real_T outputMFCache[700])
{
  static const real_T b[3] = { -30.0, -30.0, -20.0 };

  static const real_T c[3] = { 20.0, 30.0, 30.0 };

  real_T tmp[100];
  real_T tmp_0[100];
  real_T tmp_1[100];
  real_T tmp_2[100];
  real_T tmp_3[100];
  real_T tmp_4[3];
  real_T tmp_5[100];
  real_T tmp_6[100];
  int32_T i;
  trimf(outputSamplePoints, b, tmp_6);
  tmp_4[0] = -30.0;
  tmp_4[1] = -20.0;
  tmp_4[2] = -10.0;
  trimf(outputSamplePoints, tmp_4, tmp_5);
  tmp_4[0] = -20.0;
  tmp_4[1] = -10.0;
  tmp_4[2] = 0.0;
  trimf(outputSamplePoints, tmp_4, tmp_3);
  tmp_4[0] = -10.0;
  tmp_4[1] = 0.0;
  tmp_4[2] = 10.0;
  trimf(outputSamplePoints, tmp_4, tmp_2);
  tmp_4[0] = 0.0;
  tmp_4[1] = 10.0;
  tmp_4[2] = 20.0;
  trimf(outputSamplePoints, tmp_4, tmp_1);
  tmp_4[0] = 10.0;
  tmp_4[1] = 20.0;
  tmp_4[2] = 30.0;
  trimf(outputSamplePoints, tmp_4, tmp_0);
  trimf(outputSamplePoints, c, tmp);
  for (i = 0; i < 100; i++) {
    outputMFCache[7 * i] = tmp_6[i];
    outputMFCache[1 + 7 * i] = tmp_5[i];
    outputMFCache[2 + 7 * i] = tmp_3[i];
    outputMFCache[3 + 7 * i] = tmp_2[i];
    outputMFCache[4 + 7 * i] = tmp_1[i];
    outputMFCache[5 + 7 * i] = tmp_0[i];
    outputMFCache[6 + 7 * i] = tmp[i];
  }
}

/* Function for MATLAB Function: '<S4>/Evaluate Rule Consequents' */
static int32_T abs_c(int32_T x)
{
  int32_T y;
  if (x < 0) {
    if (x <= MIN_int32_T) {
      y = MAX_int32_T;
    } else {
      y = -x;
    }
  } else {
    y = x;
  }

  return y;
}

/* Function for MATLAB Function: '<S4>/Evaluate Rule Consequents' */
static real_T evaluateAndMethod(const real_T x[2])
{
  real_T y;
  if (x[0] > x[1]) {
    y = x[1];
  } else if (rtIsNaN(x[0])) {
    if (!rtIsNaN(x[1])) {
      y = x[1];
    } else {
      y = x[0];
    }
  } else {
    y = x[0];
  }

  return y;
}

/* Function for MATLAB Function: '<S4>/Evaluate Rule Consequents' */
static real_T evaluateOrMethod(const real_T x[2])
{
  real_T y;
  if (x[0] < x[1]) {
    y = x[1];
  } else if (rtIsNaN(x[0])) {
    if (!rtIsNaN(x[1])) {
      y = x[1];
    } else {
      y = x[0];
    }
  } else {
    y = x[0];
  }

  return y;
}

/*
 * Output and update for atomic system:
 *    '<S4>/Evaluate Rule Consequents'
 *    '<S5>/Evaluate Rule Consequents'
 */
static void EvaluateRuleConsequents(const real_T rtu_antecedentOutputs[9], const
  real_T rtu_samplePoints[100], real_T rty_aggregatedOutputs[100],
  DW_EvaluateRuleConsequents *localDW)
{
  int32_T ruleID;
  int32_T sampleID;
  static const int8_T b[9] = { 7, 4, 1, 6, 4, 2, 5, 4, 3 };

  real_T outputMFCache[2];
  real_T rty_aggregatedOutputs_0[2];
  int32_T q0;
  int32_T q0_0;
  memset(&rty_aggregatedOutputs[0], 0, 100U * sizeof(real_T));
  createMamdaniOutputMFCache(rtu_samplePoints, localDW->outputMFCache);
  q0 = abs_c(0);
  for (ruleID = 0; ruleID < 9; ruleID++) {
    if ((q0 < 0) && (b[ruleID] < MIN_int32_T - q0)) {
      q0_0 = MIN_int32_T;
    } else if ((q0 > 0) && (b[ruleID] > MAX_int32_T - q0)) {
      q0_0 = MAX_int32_T;
    } else {
      q0_0 = q0 + b[ruleID];
    }

    for (sampleID = 0; sampleID < 100; sampleID++) {
      outputMFCache[0] = localDW->outputMFCache[(7 * sampleID + q0_0) - 1];
      outputMFCache[1] = rtu_antecedentOutputs[ruleID];
      rty_aggregatedOutputs_0[0] = rty_aggregatedOutputs[sampleID];
      rty_aggregatedOutputs_0[1] = evaluateAndMethod(outputMFCache);
      rty_aggregatedOutputs[sampleID] = evaluateOrMethod(rty_aggregatedOutputs_0);
    }
  }
}

/* Function for MATLAB Function: '<S4>/Evaluate Rule Antecedents' */
static real_T trapmf(real_T x, const real_T params[4])
{
  real_T b_y1;
  real_T y2;
  b_y1 = 0.0;
  y2 = 0.0;
  if (x >= params[1]) {
    b_y1 = 1.0;
  }

  if (x < params[0]) {
    b_y1 = 0.0;
  }

  if ((params[0] <= x) && (x < params[1]) && (params[0] != params[1])) {
    b_y1 = 1.0 / (params[1] - params[0]) * (x - params[0]);
  }

  if (x <= params[2]) {
    y2 = 1.0;
  }

  if (x > params[3]) {
    y2 = 0.0;
  }

  if ((params[2] < x) && (x <= params[3]) && (params[2] != params[3])) {
    y2 = 1.0 / (params[3] - params[2]) * (params[3] - x);
  }

  return fmin(b_y1, y2);
}

/* Function for MATLAB Function: '<S4>/Evaluate Rule Antecedents' */
static real_T trimf_b(real_T x, const real_T params[3])
{
  real_T y;
  y = 0.0;
  if ((params[0] != params[1]) && (params[0] < x) && (x < params[1])) {
    y = 1.0 / (params[1] - params[0]) * (x - params[0]);
  }

  if ((params[1] != params[2]) && (params[1] < x) && (x < params[2])) {
    y = 1.0 / (params[2] - params[1]) * (params[2] - x);
  }

  if (x == params[1]) {
    y = 1.0;
  }

  return y;
}

/* Model step function */
void rakieta_model_do_autogeneracji_kodu_step(void)
{
  real_T inputMFCache[6];
  int32_T ruleID;
  static const int8_T b[18] = { 1, 1, 1, 2, 2, 2, 3, 3, 3, 1, 2, 3, 1, 2, 3, 1,
    2, 3 };

  static const real_T c[4] = { 0.0, 10.0, 100.0, 100.0 };

  static const real_T d[4] = { -90.0, -90.0, -10.0, 0.0 };

  static const real_T e[4] = { 40.0, 80.0, 100.0, 100.0 };

  static const real_T f[3] = { 15.0, 40.0, 80.0 };

  static const real_T g[4] = { 0.0, 0.0, 15.0, 40.0 };

  static const int8_T b_0[18] = { 1, 1, 1, 2, 2, 2, 3, 3, 3, 1, 2, 3, 1, 2, 3, 1,
    2, 3 };

  static const real_T c_0[4] = { 0.0, 10.0, 100.0, 100.0 };

  static const real_T d_0[4] = { -90.0, -90.0, -10.0, 0.0 };

  static const real_T e_0[4] = { 40.0, 80.0, 100.0, 100.0 };

  static const real_T f_0[3] = { 15.0, 40.0, 80.0 };

  static const real_T g_0[4] = { 0.0, 0.0, 15.0, 40.0 };

  real_T rtb_defuzzifiedOutputs;
  real_T rtb_y;
  real_T rtb_antecedentOutputs[9];
  real_T rtb_y_h;
  real_T rtb_aggregatedOutputs[100];
  real_T tmp[3];
  real_T rtb_TmpSignalConversionAtSFun_0;
  real_T rtb_antecedentOutputs_n;

  /* MATLAB Function: '<Root>/ograniczenie_predkosci' incorporates:
   *  Inport: '<Root>/v'
   */
  if (rtU.v < 0.0) {
    rtb_y = -rtU.v;
  } else {
    rtb_y = rtU.v;
  }

  /* End of MATLAB Function: '<Root>/ograniczenie_predkosci' */

  /* MATLAB Function: '<Root>/ograniczenie_kata przechylenia' incorporates:
   *  Inport: '<Root>/przechylenie'
   */
  ograniczenie_katapochylenia(rtU.przechylenie, &rtb_y_h);

  /* Outputs for Atomic SubSystem: '<Root>/reg_przech' */
  /* MATLAB Function: '<S5>/Evaluate Rule Antecedents' incorporates:
   *  SignalConversion: '<S10>/TmpSignal ConversionAt SFunction Inport1'
   */
  rtb_defuzzifiedOutputs = 0.0;
  inputMFCache[0] = trapmf(rtb_y, g);
  inputMFCache[1] = trimf_b(rtb_y, f);
  inputMFCache[2] = trapmf(rtb_y, e);
  inputMFCache[3] = trapmf(rtb_y_h, d);
  tmp[0] = -10.0;
  tmp[1] = 0.0;
  tmp[2] = 10.0;
  inputMFCache[4] = trimf_b(rtb_y_h, tmp);
  inputMFCache[5] = trapmf(rtb_y_h, c);
  for (ruleID = 0; ruleID < 9; ruleID++) {
    rtb_antecedentOutputs_n = 1.0;
    rtb_TmpSignalConversionAtSFun_0 = inputMFCache[b[ruleID] - 1];
    if (1.0 > rtb_TmpSignalConversionAtSFun_0) {
      rtb_antecedentOutputs_n = rtb_TmpSignalConversionAtSFun_0;
    }

    rtb_TmpSignalConversionAtSFun_0 = inputMFCache[b[ruleID + 9] + 2];
    if (rtb_antecedentOutputs_n > rtb_TmpSignalConversionAtSFun_0) {
      rtb_antecedentOutputs_n = rtb_TmpSignalConversionAtSFun_0;
    }

    rtb_defuzzifiedOutputs += rtb_antecedentOutputs_n;
    rtb_antecedentOutputs[ruleID] = rtb_antecedentOutputs_n;
  }

  /* MATLAB Function: '<S5>/Evaluate Rule Consequents' incorporates:
   *  Constant: '<S5>/Output Sample Points'
   */
  EvaluateRuleConsequents(rtb_antecedentOutputs, rtConstP.pooled2,
    rtb_aggregatedOutputs, &rtDW.sf_EvaluateRuleConsequents_i);

  /* MATLAB Function: '<S5>/Defuzzify Outputs' incorporates:
   *  Constant: '<S5>/Output Sample Points'
   *  MATLAB Function: '<S5>/Evaluate Rule Antecedents'
   */
  if (rtb_defuzzifiedOutputs == 0.0) {
    rtb_defuzzifiedOutputs = 0.0;
  } else {
    rtb_defuzzifiedOutputs = 0.0;
    rtb_y_h = rtb_aggregatedOutputs[0];
    for (ruleID = 0; ruleID < 99; ruleID++) {
      rtb_y_h += rtb_aggregatedOutputs[ruleID + 1];
    }

    if (!(rtb_y_h == 0.0)) {
      for (ruleID = 0; ruleID < 100; ruleID++) {
        rtb_defuzzifiedOutputs += rtConstP.pooled2[ruleID] *
          rtb_aggregatedOutputs[ruleID];
      }

      rtb_defuzzifiedOutputs *= 1.0 / rtb_y_h;
    }
  }

  /* End of MATLAB Function: '<S5>/Defuzzify Outputs' */
  /* End of Outputs for SubSystem: '<Root>/reg_przech' */

  /* Outport: '<Root>/kanal_przech' incorporates:
   *  Gain: '<Root>/Gain'
   */
  rtY.kanal_przech = -3.3 * rtb_defuzzifiedOutputs;

  /* MATLAB Function: '<Root>/ograniczenie_kata pochylenia' incorporates:
   *  Inport: '<Root>/pochylenie'
   */
  ograniczenie_katapochylenia(rtU.pochylenie, &rtb_y_h);

  /* Outputs for Atomic SubSystem: '<Root>/reg_poch' */
  /* MATLAB Function: '<S4>/Evaluate Rule Antecedents' incorporates:
   *  SignalConversion: '<S7>/TmpSignal ConversionAt SFunction Inport1'
   */
  rtb_defuzzifiedOutputs = 0.0;
  inputMFCache[0] = trapmf(rtb_y, g_0);
  inputMFCache[1] = trimf_b(rtb_y, f_0);
  inputMFCache[2] = trapmf(rtb_y, e_0);
  inputMFCache[3] = trapmf(rtb_y_h, d_0);
  tmp[0] = -10.0;
  tmp[1] = 0.0;
  tmp[2] = 10.0;
  inputMFCache[4] = trimf_b(rtb_y_h, tmp);
  inputMFCache[5] = trapmf(rtb_y_h, c_0);
  for (ruleID = 0; ruleID < 9; ruleID++) {
    rtb_antecedentOutputs_n = 1.0;
    rtb_TmpSignalConversionAtSFun_0 = inputMFCache[b_0[ruleID] - 1];
    if (1.0 > rtb_TmpSignalConversionAtSFun_0) {
      rtb_antecedentOutputs_n = rtb_TmpSignalConversionAtSFun_0;
    }

    rtb_TmpSignalConversionAtSFun_0 = inputMFCache[b_0[ruleID + 9] + 2];
    if (rtb_antecedentOutputs_n > rtb_TmpSignalConversionAtSFun_0) {
      rtb_antecedentOutputs_n = rtb_TmpSignalConversionAtSFun_0;
    }

    rtb_defuzzifiedOutputs += rtb_antecedentOutputs_n;
    rtb_antecedentOutputs[ruleID] = rtb_antecedentOutputs_n;
  }

  /* MATLAB Function: '<S4>/Evaluate Rule Consequents' incorporates:
   *  Constant: '<S4>/Output Sample Points'
   */
  EvaluateRuleConsequents(rtb_antecedentOutputs, rtConstP.pooled2,
    rtb_aggregatedOutputs, &rtDW.sf_EvaluateRuleConsequents);

  /* MATLAB Function: '<S4>/Defuzzify Outputs' incorporates:
   *  Constant: '<S4>/Output Sample Points'
   *  MATLAB Function: '<S4>/Evaluate Rule Antecedents'
   */
  if (rtb_defuzzifiedOutputs == 0.0) {
    rtb_y = 0.0;
  } else {
    rtb_y = 0.0;
    rtb_y_h = rtb_aggregatedOutputs[0];
    for (ruleID = 0; ruleID < 99; ruleID++) {
      rtb_y_h += rtb_aggregatedOutputs[ruleID + 1];
    }

    if (!(rtb_y_h == 0.0)) {
      for (ruleID = 0; ruleID < 100; ruleID++) {
        rtb_y += rtConstP.pooled2[ruleID] * rtb_aggregatedOutputs[ruleID];
      }

      rtb_y *= 1.0 / rtb_y_h;
    }
  }

  /* End of MATLAB Function: '<S4>/Defuzzify Outputs' */
  /* End of Outputs for SubSystem: '<Root>/reg_poch' */

  /* Outport: '<Root>/kanal_poch' incorporates:
   *  Gain: '<Root>/Gain1'
   */
  rtY.kanal_poch = -3.3 * rtb_y;
}

/* Model initialize function */
void rakieta_model_do_autogeneracji_kodu_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize error status */
  rtmSetErrorStatus(rtM, (NULL));

  /* external inputs */
  (void)memset(&rtU, 0, sizeof(ExtU));

  /* external outputs */
  (void) memset((void *)&rtY, 0,
                sizeof(ExtY));
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
