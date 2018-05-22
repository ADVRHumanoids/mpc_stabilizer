//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: xgeqrf.cpp
//
// MATLAB Coder version            : 3.4
// C/C++ source code generated on  : 22-May-2018 17:53:16
//

// Include Files
#include "rt_nonfinite.h"
#include "mpcmoveCodeGeneration.h"
#include "xgeqrf.h"
#include "xger.h"
#include "xgemv.h"
#include "xnrm2.h"

// Function Declarations
static double rt_hypotd_snf(double u0, double u1);

// Function Definitions

//
// Arguments    : double u0
//                double u1
// Return Type  : double
//
static double rt_hypotd_snf(double u0, double u1)
{
  double y;
  double a;
  double b;
  a = std::abs(u0);
  b = std::abs(u1);
  if (a < b) {
    a /= b;
    y = b * std::sqrt(a * a + 1.0);
  } else if (a > b) {
    b /= a;
    y = a * std::sqrt(b * b + 1.0);
  } else if (rtIsNaN(b)) {
    y = b;
  } else {
    y = a * 1.4142135623730951;
  }

  return y;
}

//
// Arguments    : double A[121]
//                double tau[11]
// Return Type  : void
//
void xgeqrf(double A[121], double tau[11])
{
  double work[11];
  int i;
  int i_i;
  double atmp;
  double d7;
  double xnorm;
  int knt;
  int i_ip1;
  int b_i;
  int lastv;
  int lastc;
  boolean_T exitg2;
  int exitg1;
  memset(&work[0], 0, 11U * sizeof(double));
  for (i = 0; i < 11; i++) {
    i_i = i + i * 11;
    if (i + 1 < 11) {
      atmp = A[i_i];
      d7 = 0.0;
      xnorm = xnrm2(10 - i, A, i_i + 2);
      if (xnorm != 0.0) {
        xnorm = rt_hypotd_snf(A[i_i], xnorm);
        if (A[i_i] >= 0.0) {
          xnorm = -xnorm;
        }

        if (std::abs(xnorm) < 1.0020841800044864E-292) {
          knt = 0;
          b_i = (i_i - i) + 11;
          do {
            knt++;
            for (lastc = i_i + 1; lastc + 1 <= b_i; lastc++) {
              A[lastc] *= 9.9792015476736E+291;
            }

            xnorm *= 9.9792015476736E+291;
            atmp *= 9.9792015476736E+291;
          } while (!(std::abs(xnorm) >= 1.0020841800044864E-292));

          xnorm = rt_hypotd_snf(atmp, xnrm2(10 - i, A, i_i + 2));
          if (atmp >= 0.0) {
            xnorm = -xnorm;
          }

          d7 = (xnorm - atmp) / xnorm;
          atmp = 1.0 / (atmp - xnorm);
          b_i = (i_i - i) + 11;
          for (lastc = i_i + 1; lastc + 1 <= b_i; lastc++) {
            A[lastc] *= atmp;
          }

          for (lastc = 1; lastc <= knt; lastc++) {
            xnorm *= 1.0020841800044864E-292;
          }

          atmp = xnorm;
        } else {
          d7 = (xnorm - A[i_i]) / xnorm;
          atmp = 1.0 / (A[i_i] - xnorm);
          b_i = (i_i - i) + 11;
          for (lastc = i_i + 1; lastc + 1 <= b_i; lastc++) {
            A[lastc] *= atmp;
          }

          atmp = xnorm;
        }
      }

      tau[i] = d7;
      A[i_i] = atmp;
      atmp = A[i_i];
      A[i_i] = 1.0;
      i_ip1 = (i + (i + 1) * 11) + 1;
      if (tau[i] != 0.0) {
        lastv = 11 - i;
        b_i = (i_i - i) + 10;
        while ((lastv > 0) && (A[b_i] == 0.0)) {
          lastv--;
          b_i--;
        }

        lastc = 10 - i;
        exitg2 = false;
        while ((!exitg2) && (lastc > 0)) {
          knt = i_ip1 + (lastc - 1) * 11;
          b_i = knt;
          do {
            exitg1 = 0;
            if (b_i <= (knt + lastv) - 1) {
              if (A[b_i - 1] != 0.0) {
                exitg1 = 1;
              } else {
                b_i++;
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
        xgemv(lastv, lastc, A, i_ip1, A, i_i + 1, work);
        xger(lastv, lastc, -tau[i], i_i + 1, work, A, i_ip1);
      }

      A[i_i] = atmp;
    } else {
      tau[10] = 0.0;
    }
  }
}

//
// File trailer for xgeqrf.cpp
//
// [EOF]
//
