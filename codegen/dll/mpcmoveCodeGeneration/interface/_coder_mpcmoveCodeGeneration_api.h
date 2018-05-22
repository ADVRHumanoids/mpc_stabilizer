/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_mpcmoveCodeGeneration_api.h
 *
 * MATLAB Coder version            : 3.4
 * C/C++ source code generated on  : 22-May-2018 17:53:16
 */

#ifndef _CODER_MPCMOVECODEGENERATION_API_H
#define _CODER_MPCMOVECODEGENERATION_API_H

/* Include Files */
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include <stddef.h>
#include <stdlib.h>
#include "_coder_mpcmoveCodeGeneration_api.h"

/* Type Definitions */
#ifndef struct_emxArray_char_T_1x10
#define struct_emxArray_char_T_1x10

struct emxArray_char_T_1x10
{
  char_T data[10];
  int32_T size[2];
};

#endif                                 /*struct_emxArray_char_T_1x10*/

#ifndef typedef_emxArray_char_T_1x10
#define typedef_emxArray_char_T_1x10

typedef struct emxArray_char_T_1x10 emxArray_char_T_1x10;

#endif                                 /*typedef_emxArray_char_T_1x10*/

#ifndef typedef_struct1_T
#define typedef_struct1_T

typedef struct {
  real_T Plant[8];
  real_T Disturbance[2];
  real_T LastMove[2];
  real_T Covariance[100];
  boolean_T iA[60];
} struct1_T;

#endif                                 /*typedef_struct1_T*/

#ifndef typedef_struct3_T
#define typedef_struct3_T

typedef struct {
  real_T ym[4];
  real_T ref[4];
} struct3_T;

#endif                                 /*typedef_struct3_T*/

#ifndef typedef_struct2_T
#define typedef_struct2_T

typedef struct {
  struct3_T signals;
} struct2_T;

#endif                                 /*typedef_struct2_T*/

#ifndef struct_sXu6I6hzBcQJXIXyhYqaLSH
#define struct_sXu6I6hzBcQJXIXyhYqaLSH

struct sXu6I6hzBcQJXIXyhYqaLSH
{
  real_T Uopt[62];
  real_T Yopt[124];
  real_T Xopt[310];
  real_T Topt[31];
  real_T Slack;
  real_T Iterations;
  emxArray_char_T_1x10 QPCode;
  real_T Cost;
};

#endif                                 /*struct_sXu6I6hzBcQJXIXyhYqaLSH*/

#ifndef typedef_struct7_T
#define typedef_struct7_T

typedef struct sXu6I6hzBcQJXIXyhYqaLSH struct7_T;

#endif                                 /*typedef_struct7_T*/

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

/* Function Declarations */
extern void mpcmoveCodeGeneration(struct1_T *mpcmovestate, struct2_T mpcmovedata,
  real_T u[2], struct7_T *Info);
extern void mpcmoveCodeGeneration_api(const mxArray * const prhs[3], const
  mxArray *plhs[3]);
extern void mpcmoveCodeGeneration_atexit(void);
extern void mpcmoveCodeGeneration_initialize(void);
extern void mpcmoveCodeGeneration_terminate(void);
extern void mpcmoveCodeGeneration_xil_terminate(void);

#endif

/*
 * File trailer for _coder_mpcmoveCodeGeneration_api.h
 *
 * [EOF]
 */
