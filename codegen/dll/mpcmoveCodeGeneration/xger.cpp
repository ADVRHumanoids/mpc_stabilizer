//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: xger.cpp
//
// MATLAB Coder version            : 3.4
// C/C++ source code generated on  : 22-May-2018 17:53:16
//

// Include Files
#include "rt_nonfinite.h"
#include "mpcmoveCodeGeneration.h"
#include "xger.h"

// Function Definitions

//
// Arguments    : int m
//                int n
//                double alpha1
//                int ix0
//                const double y[11]
//                double A[121]
//                int ia0
// Return Type  : void
//
void xger(int m, int n, double alpha1, int ix0, const double y[11], double A[121],
          int ia0)
{
  int jA;
  int jy;
  int j;
  double temp;
  int ix;
  int i7;
  int ijA;
  if (!(alpha1 == 0.0)) {
    jA = ia0 - 1;
    jy = 0;
    for (j = 1; j <= n; j++) {
      if (y[jy] != 0.0) {
        temp = y[jy] * alpha1;
        ix = ix0;
        i7 = m + jA;
        for (ijA = jA; ijA + 1 <= i7; ijA++) {
          A[ijA] += A[ix - 1] * temp;
          ix++;
        }
      }

      jy++;
      jA += 11;
    }
  }
}

//
// File trailer for xger.cpp
//
// [EOF]
//
