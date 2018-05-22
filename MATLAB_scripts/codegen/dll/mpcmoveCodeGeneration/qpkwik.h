//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: qpkwik.h
//
// MATLAB Coder version            : 3.4
// C/C++ source code generated on  : 22-May-2018 17:53:16
//
#ifndef QPKWIK_H
#define QPKWIK_H

// Include Files
#include <cmath>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "mpcmoveCodeGeneration_types.h"

// Function Declarations
extern void qpkwik(const double Linv[121], const double Hinv[121], const double
                   f[11], const double Ac[660], const double b[60], short iA[60],
                   double x[11], double lambda[60], double *status);

#endif

//
// File trailer for qpkwik.h
//
// [EOF]
//
