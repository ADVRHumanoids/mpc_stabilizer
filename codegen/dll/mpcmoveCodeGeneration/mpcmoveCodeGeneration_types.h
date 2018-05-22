//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: mpcmoveCodeGeneration_types.h
//
// MATLAB Coder version            : 3.4
// C/C++ source code generated on  : 22-May-2018 17:53:16
//
#ifndef MPCMOVECODEGENERATION_TYPES_H
#define MPCMOVECODEGENERATION_TYPES_H

// Include Files
#include "rtwtypes.h"

// Type Definitions
#ifndef struct_emxArray_char_T_1x10
#define struct_emxArray_char_T_1x10

struct emxArray_char_T_1x10
{
  char data[10];
  int size[2];
};

#endif                                 //struct_emxArray_char_T_1x10

typedef struct {
  double Plant[8];
  double Disturbance[2];
  double LastMove[2];
  double Covariance[100];
  boolean_T iA[60];
} struct1_T;

typedef struct {
  double ym[4];
  double ref[4];
} struct3_T;

typedef struct {
  struct3_T signals;
} struct2_T;

#ifndef struct_sXu6I6hzBcQJXIXyhYqaLSH
#define struct_sXu6I6hzBcQJXIXyhYqaLSH

struct sXu6I6hzBcQJXIXyhYqaLSH
{
  double Uopt[62];
  double Yopt[124];
  double Xopt[310];
  double Topt[31];
  double Slack;
  double Iterations;
  emxArray_char_T_1x10 QPCode;
  double Cost;
};

#endif                                 //struct_sXu6I6hzBcQJXIXyhYqaLSH

typedef sXu6I6hzBcQJXIXyhYqaLSH struct7_T;

#endif

//
// File trailer for mpcmoveCodeGeneration_types.h
//
// [EOF]
//
