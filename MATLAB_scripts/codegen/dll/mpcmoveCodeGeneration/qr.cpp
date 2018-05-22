//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: qr.cpp
//
// MATLAB Coder version            : 3.4
// C/C++ source code generated on  : 22-May-2018 17:53:16
//

// Include Files
#include "rt_nonfinite.h"
#include "mpcmoveCodeGeneration.h"
#include "qr.h"
#include "xger.h"
#include "xgemv.h"
#include "xgeqrf.h"

// Function Definitions

//
// Arguments    : const double A[121]
//                double Q[121]
//                double R[121]
// Return Type  : void
//
void qr(const double A[121], double Q[121], double R[121])
{
  double b_A[121];
  double tau[11];
  int itau;
  int lastc;
  int i;
  int iaii;
  int lastv;
  double work[11];
  boolean_T exitg2;
  int coltop;
  int ia;
  int exitg1;
  memcpy(&b_A[0], &A[0], 121U * sizeof(double));
  xgeqrf(b_A, tau);
  itau = 10;
  for (lastc = 0; lastc < 11; lastc++) {
    for (i = 0; i + 1 <= lastc + 1; i++) {
      R[i + 11 * lastc] = b_A[i + 11 * lastc];
    }

    for (i = lastc + 1; i + 1 < 12; i++) {
      R[i + 11 * lastc] = 0.0;
    }

    work[lastc] = 0.0;
  }

  for (i = 10; i >= 0; i--) {
    iaii = (i + i * 11) + 1;
    if (i + 1 < 11) {
      b_A[iaii - 1] = 1.0;
      if (tau[itau] != 0.0) {
        lastv = 11 - i;
        lastc = (iaii - i) + 9;
        while ((lastv > 0) && (b_A[lastc] == 0.0)) {
          lastv--;
          lastc--;
        }

        lastc = 10 - i;
        exitg2 = false;
        while ((!exitg2) && (lastc > 0)) {
          coltop = iaii + (lastc - 1) * 11;
          ia = coltop;
          do {
            exitg1 = 0;
            if (ia + 11 <= (coltop + lastv) + 10) {
              if (b_A[ia + 10] != 0.0) {
                exitg1 = 1;
              } else {
                ia++;
              }
            } else {
              lastc--;
              exitg1 = 2;
            }
          } while (exitg1 == 0);

          if (exitg1 == 1) {
            exitg2 = true;
          }
        }
      } else {
        lastv = 0;
        lastc = 0;
      }

      if (lastv > 0) {
        xgemv(lastv, lastc, b_A, iaii + 11, b_A, iaii, work);
        xger(lastv, lastc, -tau[itau], iaii, work, b_A, iaii + 11);
      }

      lastc = (iaii - i) + 10;
      for (coltop = iaii; coltop + 1 <= lastc; coltop++) {
        b_A[coltop] *= -tau[itau];
      }
    }

    b_A[iaii - 1] = 1.0 - tau[itau];
    for (lastc = 1; lastc <= i; lastc++) {
      b_A[(iaii - lastc) - 1] = 0.0;
    }

    itau--;
  }

  for (lastc = 0; lastc < 11; lastc++) {
    memcpy(&Q[lastc * 11], &b_A[lastc * 11], 11U * sizeof(double));
  }
}

//
// File trailer for qr.cpp
//
// [EOF]
//
