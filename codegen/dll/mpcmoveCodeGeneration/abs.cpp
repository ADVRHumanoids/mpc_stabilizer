//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: abs.cpp
//
// MATLAB Coder version            : 3.4
// C/C++ source code generated on  : 22-May-2018 17:53:16
//

// Include Files
#include "rt_nonfinite.h"
#include "mpcmoveCodeGeneration.h"
#include "abs.h"

// Function Definitions

//
// Arguments    : const double x[11]
//                double y[11]
// Return Type  : void
//
void b_abs(const double x[11], double y[11])
{
  int k;
  for (k = 0; k < 11; k++) {
    y[k] = std::abs(x[k]);
  }
}

//
// Arguments    : const double x[60]
//                double y[60]
// Return Type  : void
//
void c_abs(const double x[60], double y[60])
{
  int k;
  for (k = 0; k < 60; k++) {
    y[k] = std::abs(x[k]);
  }
}

//
// File trailer for abs.cpp
//
// [EOF]
//
