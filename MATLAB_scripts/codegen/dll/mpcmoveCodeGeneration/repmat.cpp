//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: repmat.cpp
//
// MATLAB Coder version            : 3.4
// C/C++ source code generated on  : 22-May-2018 17:53:16
//

// Include Files
#include "rt_nonfinite.h"
#include "mpcmoveCodeGeneration.h"
#include "repmat.h"

// Function Definitions

//
// Arguments    : double b[124]
// Return Type  : void
//
void b_repmat(double b[124])
{
  int jtilecol;
  int ibtile;
  int k;
  for (jtilecol = 0; jtilecol < 31; jtilecol++) {
    ibtile = jtilecol << 2;
    for (k = 0; k < 4; k++) {
      b[ibtile + k] = 0.0;
    }
  }
}

//
// Arguments    : double b[310]
// Return Type  : void
//
void c_repmat(double b[310])
{
  int jtilecol;
  int ibtile;
  for (jtilecol = 0; jtilecol < 31; jtilecol++) {
    ibtile = jtilecol * 10;
    memset(&b[ibtile], 0, 10U * sizeof(double));
  }
}

//
// Arguments    : double b[124]
// Return Type  : void
//
void d_repmat(double b[124])
{
  int jtilecol;
  int ibtile;
  int k;
  for (jtilecol = 0; jtilecol < 31; jtilecol++) {
    ibtile = jtilecol << 2;
    for (k = 0; k < 4; k++) {
      b[ibtile + k] = 1.0;
    }
  }
}

//
// Arguments    : double b[60]
// Return Type  : void
//
void e_repmat(double b[60])
{
  int jtilecol;
  int ibtile;
  int k;
  for (jtilecol = 0; jtilecol < 30; jtilecol++) {
    ibtile = jtilecol << 1;
    for (k = 0; k < 2; k++) {
      b[ibtile + k] = 1.0;
    }
  }
}

//
// Arguments    : double b[60]
// Return Type  : void
//
void repmat(double b[60])
{
  int jtilecol;
  int ibtile;
  int k;
  for (jtilecol = 0; jtilecol < 30; jtilecol++) {
    ibtile = jtilecol << 1;
    for (k = 0; k < 2; k++) {
      b[ibtile + k] = 0.0;
    }
  }
}

//
// File trailer for repmat.cpp
//
// [EOF]
//
