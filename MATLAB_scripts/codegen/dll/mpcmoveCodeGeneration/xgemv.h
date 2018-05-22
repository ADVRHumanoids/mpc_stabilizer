//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: xgemv.h
//
// MATLAB Coder version            : 3.4
// C/C++ source code generated on  : 22-May-2018 17:53:16
//
#ifndef XGEMV_H
#define XGEMV_H

// Include Files
#include <cmath>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "mpcmoveCodeGeneration_types.h"

// Function Declarations
extern void xgemv(int m, int n, const double A[121], int ia0, const double x[121],
                  int ix0, double y[11]);

#endif

//
// File trailer for xgemv.h
//
// [EOF]
//
