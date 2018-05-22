//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: mpcblock_optimizer.cpp
//
// MATLAB Coder version            : 3.4
// C/C++ source code generated on  : 22-May-2018 17:53:16
//

// Include Files
#include "rt_nonfinite.h"
#include "mpcmoveCodeGeneration.h"
#include "mpcblock_optimizer.h"
#include "qpkwik.h"

// Function Definitions

//
// Arguments    : const double rseq[120]
//                const double vseq[31]
//                const double x[10]
//                const double old_u[2]
//                const boolean_T iA[60]
//                const double Hinv[121]
//                const double Kx[100]
//                const double Ku1[20]
//                const double Kut[600]
//                const double Kr[1200]
//                const double Kv[310]
//                const double Mlim[60]
//                const double Mx[600]
//                const double Mu1[120]
//                const double Mv[1860]
//                const double utarget[60]
//                const double uoff[2]
//                const double H[121]
//                const double Linv[121]
//                const double Ac[660]
//                const double Wy[4]
//                const double Jm[600]
//                const double Su1[240]
//                const double Sx[1200]
//                const double Hv[3720]
//                const double I1[120]
//                double u[2]
//                double *cost
//                double useq[60]
//                double *status
//                boolean_T iAout[60]
//                double *slack
// Return Type  : void
//
void mpcblock_optimizer(const double rseq[120], const double vseq[31], const
  double x[10], const double old_u[2], const boolean_T iA[60], const double
  Hinv[121], const double Kx[100], const double Ku1[20], const double Kut[600],
  const double Kr[1200], const double Kv[310], const double Mlim[60], const
  double Mx[600], const double Mu1[120], const double Mv[1860], const double
  utarget[60], const double uoff[2], const double H[121], const double Linv[121],
  const double Ac[660], const double Wy[4], const double Jm[600], const double
  Su1[240], const double Sx[1200], const double Hv[3720], const double I1[120],
  double u[2], double *cost, double useq[60], double *status, boolean_T iAout[60],
  double *slack)
{
  double f[11];
  int kidx;
  double d0;
  int i2;
  double b_Mlim[60];
  short iAnew[60];
  double aux[11];
  double aux3[60];
  double d1;
  double d2;
  double d3;
  double d4;
  double b_Sx[120];
  signed char I[4];
  int i1;
  double b_Su1[120];
  int b_j1;
  int j2;
  double aux2[120];
  double b_old_u[2];
  double K[600];
  signed char b_K[3600];
  static const signed char A[900] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0,
    0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1,
    1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 1 };

  double c_K[60];
  *cost = 0.0;
  memset(&f[0], 0, 11U * sizeof(double));
  for (kidx = 0; kidx < 10; kidx++) {
    d0 = 0.0;
    for (i2 = 0; i2 < 10; i2++) {
      d0 += Kx[i2 + 10 * kidx] * x[i2];
    }

    d1 = 0.0;
    for (i2 = 0; i2 < 120; i2++) {
      d1 += Kr[i2 + 120 * kidx] * rseq[i2];
    }

    d2 = 0.0;
    for (i2 = 0; i2 < 2; i2++) {
      d2 += Ku1[i2 + (kidx << 1)] * old_u[i2];
    }

    d3 = 0.0;
    for (i2 = 0; i2 < 31; i2++) {
      d3 += Kv[i2 + 31 * kidx] * vseq[i2];
    }

    d4 = 0.0;
    for (i2 = 0; i2 < 60; i2++) {
      d4 += Kut[i2 + 60 * kidx] * utarget[i2];
    }

    f[kidx] = (((d0 + d1) + d2) + d3) + d4;
  }

  for (kidx = 0; kidx < 60; kidx++) {
    iAnew[kidx] = iA[kidx];
    d0 = 0.0;
    for (i2 = 0; i2 < 10; i2++) {
      d0 += Mx[kidx + 60 * i2] * x[i2];
    }

    aux3[kidx] = 0.0;
    for (i2 = 0; i2 < 2; i2++) {
      aux3[kidx] += Mu1[kidx + 60 * i2] * old_u[i2];
    }

    d1 = 0.0;
    for (i2 = 0; i2 < 31; i2++) {
      d1 += Mv[kidx + 60 * i2] * vseq[i2];
    }

    b_Mlim[kidx] = -(((Mlim[kidx] + d0) + aux3[kidx]) + d1);
  }

  qpkwik(Linv, Hinv, f, Ac, b_Mlim, iAnew, aux, aux3, status);
  for (kidx = 0; kidx < 60; kidx++) {
    iAout[kidx] = (iAnew[kidx] != 0);
  }

  if ((*status < 0.0) || (*status == 0.0)) {
    memset(&aux[0], 0, 11U * sizeof(double));
  }

  *slack = aux[10];
  for (kidx = 0; kidx < 2; kidx++) {
    u[kidx] = old_u[kidx] + aux[kidx];
  }

  if (*status > 0.0) {
    for (i2 = 0; i2 < 120; i2++) {
      b_Sx[i2] = 0.0;
      for (kidx = 0; kidx < 10; kidx++) {
        b_Sx[i2] += Sx[i2 + 120 * kidx] * x[kidx];
      }

      b_Su1[i2] = 0.0;
      for (kidx = 0; kidx < 2; kidx++) {
        b_Su1[i2] += Su1[i2 + 120 * kidx] * old_u[kidx];
      }

      d0 = 0.0;
      for (kidx = 0; kidx < 31; kidx++) {
        d0 += Hv[i2 + 120 * kidx] * vseq[kidx];
      }

      aux2[i2] = ((b_Sx[i2] + b_Su1[i2]) + d0) - rseq[i2];
    }

    for (i2 = 0; i2 < 60; i2++) {
      d0 = 0.0;
      for (kidx = 0; kidx < 2; kidx++) {
        d0 += I1[i2 + 60 * kidx] * old_u[kidx];
      }

      aux3[i2] = d0 - utarget[i2];
    }

    kidx = -1;
    for (i1 = 0; i1 < 30; i1++) {
      for (i2 = 0; i2 < 4; i2++) {
        kidx++;
        b_Sx[kidx] = Wy[i2];
      }
    }

    d0 = 0.0;
    for (i2 = 0; i2 < 60; i2++) {
      d0 += aux3[i2] * (0.0 * aux3[i2]);
    }

    d1 = 0.0;
    for (i2 = 0; i2 < 120; i2++) {
      d1 += aux2[i2] * (b_Sx[i2] * aux2[i2]);
    }

    d2 = 0.0;
    for (i2 = 0; i2 < 11; i2++) {
      d3 = 0.0;
      for (kidx = 0; kidx < 11; kidx++) {
        d3 += H[i2 + 11 * kidx] * aux[kidx];
      }

      d2 += aux[i2] * (d3 + 2.0 * f[i2]);
    }

    *cost = (d0 + d1) + d2;
  }

  for (i2 = 0; i2 < 4; i2++) {
    I[i2] = 0;
  }

  for (kidx = 0; kidx < 2; kidx++) {
    I[kidx + (kidx << 1)] = 1;
  }

  kidx = -1;
  for (b_j1 = 0; b_j1 < 30; b_j1++) {
    for (j2 = 0; j2 < 2; j2++) {
      for (i1 = 0; i1 < 30; i1++) {
        for (i2 = 0; i2 < 2; i2++) {
          kidx++;
          b_K[kidx] = (signed char)(A[i1 + 30 * b_j1] * I[i2 + (j2 << 1)]);
        }
      }
    }
  }

  for (i2 = 0; i2 < 60; i2++) {
    for (kidx = 0; kidx < 10; kidx++) {
      K[i2 + 60 * kidx] = 0.0;
      for (i1 = 0; i1 < 60; i1++) {
        K[i2 + 60 * kidx] += (double)b_K[i2 + 60 * i1] * Jm[i1 + 60 * kidx];
      }
    }
  }

  for (i2 = 0; i2 < 2; i2++) {
    b_old_u[i2] = old_u[i2] + uoff[i2];
  }

  for (i2 = 0; i2 < 60; i2++) {
    aux3[i2] = 0.0;
    for (kidx = 0; kidx < 10; kidx++) {
      aux3[i2] += K[i2 + 60 * kidx] * aux[kidx];
    }

    b_Mlim[i2] = 0.0;
    for (kidx = 0; kidx < 2; kidx++) {
      b_Mlim[i2] += I1[i2 + 60 * kidx] * b_old_u[kidx];
    }

    c_K[i2] = aux3[i2] + b_Mlim[i2];
  }

  for (i2 = 0; i2 < 2; i2++) {
    for (kidx = 0; kidx < 30; kidx++) {
      useq[kidx + 30 * i2] = c_K[i2 + (kidx << 1)];
    }
  }
}

//
// File trailer for mpcblock_optimizer.cpp
//
// [EOF]
//
