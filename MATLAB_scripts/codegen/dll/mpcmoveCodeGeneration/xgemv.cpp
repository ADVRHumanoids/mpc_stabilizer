//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: xgemv.cpp
//
// MATLAB Coder version            : 3.4
// C/C++ source code generated on  : 22-May-2018 17:53:16
//

// Include Files
#include "rt_nonfinite.h"
#include "mpcmoveCodeGeneration.h"
#include "xgemv.h"

// Function Definitions

//
// Arguments    : int m
//                int n
//                const double A[121]
//                int ia0
//                const double x[121]
//                int ix0
//                double y[11]
// Return Type  : void
//
void xgemv(int m, int n, const double A[121], int ia0, const double x[121], int
           ix0, double y[11])
{
  int iy;
  int i5;
  int iac;
  int ix;
  double c;
  int i6;
  int ia;
  if (n != 0) {
    for (iy = 1; iy <= n; iy++) {
      y[iy - 1] = 0.0;
    }

    iy = 0;
    i5 = ia0 + 11 * (n - 1);
    for (iac = ia0; iac <= i5; iac += 11) {
      ix = ix0;
      c = 0.0;
      i6 = (iac + m) - 1;
      for (ia = iac; ia <= i6; ia++) {
        c += A[ia - 1] * x[ix - 1];
        ix++;
      }

      y[iy] += c;
      iy++;
    }
  }
}

//
// File trailer for xgemv.cpp
//
// [EOF]
//
