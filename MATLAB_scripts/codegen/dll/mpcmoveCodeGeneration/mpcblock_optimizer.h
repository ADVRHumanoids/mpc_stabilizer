//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: mpcblock_optimizer.h
//
// MATLAB Coder version            : 3.4
// C/C++ source code generated on  : 22-May-2018 17:53:16
//
#ifndef MPCBLOCK_OPTIMIZER_H
#define MPCBLOCK_OPTIMIZER_H

// Include Files
#include <cmath>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "mpcmoveCodeGeneration_types.h"

// Function Declarations
extern void mpcblock_optimizer(const double rseq[120], const double vseq[31],
  const double x[10], const double old_u[2], const boolean_T iA[60], const
  double Hinv[121], const double Kx[100], const double Ku1[20], const double
  Kut[600], const double Kr[1200], const double Kv[310], const double Mlim[60],
  const double Mx[600], const double Mu1[120], const double Mv[1860], const
  double utarget[60], const double uoff[2], const double H[121], const double
  Linv[121], const double Ac[660], const double Wy[4], const double Jm[600],
  const double Su1[240], const double Sx[1200], const double Hv[3720], const
  double I1[120], double u[2], double *cost, double useq[60], double *status,
  boolean_T iAout[60], double *slack);

#endif

//
// File trailer for mpcblock_optimizer.h
//
// [EOF]
//
