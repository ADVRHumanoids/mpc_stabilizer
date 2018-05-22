//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: qpkwik.cpp
//
// MATLAB Coder version            : 3.4
// C/C++ source code generated on  : 22-May-2018 17:53:16
//

// Include Files
#include "rt_nonfinite.h"
#include "mpcmoveCodeGeneration.h"
#include "qpkwik.h"
#include "qr.h"
#include "abs.h"
#include "norm.h"

// Function Declarations
static void DropConstraint(short kDrop, short iA[60], short *nA, short iC[60]);
static double KWIKfactor(const double Ac[660], const short iC[60], short nA,
  const double Linv[121], double RLinv[121], double D[121], double H[121]);
static void Unconstrained(const double Hinv[121], const double f[11], double x
  [11]);

// Function Definitions

//
// Arguments    : short kDrop
//                short iA[60]
//                short *nA
//                short iC[60]
// Return Type  : void
//
static void DropConstraint(short kDrop, short iA[60], short *nA, short iC[60])
{
  int i8;
  short i9;
  short i;
  iA[iC[kDrop - 1] - 1] = 0;
  if (kDrop < *nA) {
    i8 = *nA - 1;
    if (i8 < -32768) {
      i8 = -32768;
    }

    i9 = (short)i8;
    for (i = kDrop; i <= i9; i++) {
      iC[i - 1] = iC[i];
    }
  }

  iC[*nA - 1] = 0;
  i8 = *nA - 1;
  if (i8 < -32768) {
    i8 = -32768;
  }

  *nA = (short)i8;
}

//
// Arguments    : const double Ac[660]
//                const short iC[60]
//                short nA
//                const double Linv[121]
//                double RLinv[121]
//                double D[121]
//                double H[121]
// Return Type  : double
//
static double KWIKfactor(const double Ac[660], const short iC[60], short nA,
  const double Linv[121], double RLinv[121], double D[121], double H[121])
{
  double Status;
  short i;
  double QQ[121];
  double RR[121];
  int i3;
  int exitg1;
  int i4;
  short j;
  double d6;
  short k;
  double TL[121];
  Status = 1.0;
  memset(&RLinv[0], 0, 121U * sizeof(double));
  for (i = 1; i <= nA; i++) {
    memset(&RLinv[i * 11 + -11], 0, 11U * sizeof(double));
    for (i3 = 0; i3 < 11; i3++) {
      RLinv[i3 + 11 * (i - 1)] = 0.0;
      for (i4 = 0; i4 < 11; i4++) {
        RLinv[i3 + 11 * (i - 1)] += Linv[i3 + 11 * i4] * Ac[(iC[i - 1] + 60 * i4)
          - 1];
      }
    }
  }

  qr(RLinv, QQ, RR);
  i = 1;
  do {
    exitg1 = 0;
    if (i <= nA) {
      if (std::abs(RR[(i + 11 * (i - 1)) - 1]) < 1.0E-12) {
        Status = -2.0;
        exitg1 = 1;
      } else {
        i++;
      }
    } else {
      for (i = 0; i < 11; i++) {
        for (j = 0; j < 11; j++) {
          d6 = 0.0;
          for (i3 = 0; i3 < 11; i3++) {
            d6 += Linv[i3 + 11 * i] * QQ[i3 + 11 * j];
          }

          TL[i + 11 * j] = d6;
        }
      }

      memset(&RLinv[0], 0, 121U * sizeof(double));
      for (j = nA; j > 0; j--) {
        RLinv[(j + 11 * (j - 1)) - 1] = 1.0;
        for (k = j; k <= nA; k++) {
          RLinv[(j + 11 * (k - 1)) - 1] /= RR[(j + 11 * (j - 1)) - 1];
        }

        if (j > 1) {
          for (i = 1; i < j; i++) {
            for (k = j; k <= nA; k++) {
              RLinv[(i + 11 * (k - 1)) - 1] -= RR[(i + 11 * (j - 1)) - 1] *
                RLinv[(j + 11 * (k - 1)) - 1];
            }
          }
        }
      }

      for (i = 0; i < 11; i++) {
        for (j = (short)(i + 1); j < 12; j++) {
          H[i + 11 * (j - 1)] = 0.0;
          for (k = (short)(nA + 1); k < 12; k++) {
            H[i + 11 * (j - 1)] -= TL[i + 11 * (k - 1)] * TL[(j + 11 * (k - 1))
              - 1];
          }

          H[(j + 11 * i) - 1] = H[i + 11 * (j - 1)];
        }
      }

      for (j = 1; j <= nA; j++) {
        for (i = 0; i < 11; i++) {
          D[i + 11 * (j - 1)] = 0.0;
          for (k = j; k <= nA; k++) {
            D[i + 11 * (j - 1)] += TL[i + 11 * (k - 1)] * RLinv[(j + 11 * (k - 1))
              - 1];
          }
        }
      }

      exitg1 = 1;
    }
  } while (exitg1 == 0);

  return Status;
}

//
// Arguments    : const double Hinv[121]
//                const double f[11]
//                double x[11]
// Return Type  : void
//
static void Unconstrained(const double Hinv[121], const double f[11], double x
  [11])
{
  short i;
  double d8;
  int i10;
  for (i = 0; i < 11; i++) {
    d8 = 0.0;
    for (i10 = 0; i10 < 11; i10++) {
      d8 += -Hinv[i + 11 * i10] * f[i10];
    }

    x[i] = d8;
  }
}

//
// Arguments    : const double Linv[121]
//                const double Hinv[121]
//                const double f[11]
//                const double Ac[660]
//                const double b[60]
//                short iA[60]
//                double x[11]
//                double lambda[60]
//                double *status
// Return Type  : void
//
void qpkwik(const double Linv[121], const double Hinv[121], const double f[11],
            const double Ac[660], const double b[60], short iA[60], double x[11],
            double lambda[60], double *status)
{
  double r[11];
  double rMin;
  boolean_T cTolComputed;
  int i;
  short nA;
  double cTol[60];
  short b_i;
  short iC[60];
  boolean_T guard1 = false;
  double Opt[22];
  boolean_T DualFeasible;
  double Rhs[22];
  double Xnorm0;
  short iSave;
  int exitg2;
  unsigned short q;
  double cMin;
  unsigned short b_x;
  short kNext;
  boolean_T ColdReset;
  int exitg3;
  int exitg1;
  double d5;
  double z[11];
  double dv21[11];
  double cVal;
  double RLinv[121];
  double D[121];
  double H[121];
  boolean_T guard2 = false;
  double varargin_1[60];
  int ix;
  boolean_T exitg4;
  short kDrop;
  double U[121];
  double t1;
  *status = 1.0;
  memset(&lambda[0], 0, 60U * sizeof(double));
  memset(&x[0], 0, 11U * sizeof(double));
  memset(&r[0], 0, 11U * sizeof(double));
  rMin = 0.0;
  cTolComputed = false;
  for (i = 0; i < 60; i++) {
    cTol[i] = 1.0;
    iC[i] = 0;
  }

  nA = 0;
  for (b_i = 0; b_i < 60; b_i++) {
    if (iA[b_i] == 1) {
      nA++;
      iC[nA - 1] = (short)(b_i + 1);
    }
  }

  guard1 = false;
  if (nA > 0) {
    memset(&Opt[0], 0, 22U * sizeof(double));
    for (i = 0; i < 11; i++) {
      Rhs[i] = f[i];
      Rhs[i + 11] = 0.0;
    }

    DualFeasible = false;
    iSave = (short)(3 * nA);
    if (iSave > 50) {
    } else {
      iSave = 50;
    }

    q = (unsigned short)((unsigned short)iSave / 10U);
    b_x = (unsigned short)((unsigned int)(unsigned short)iSave - (unsigned short)
      (q * 10));
    if ((b_x > 0) && (b_x >= 5)) {
      q++;
    }

    ColdReset = false;
    do {
      exitg3 = 0;
      if ((!DualFeasible) && (nA > 0) && (*status <= 284.0)) {
        cVal = KWIKfactor(Ac, iC, nA, Linv, RLinv, D, H);
        if (cVal < 0.0) {
          if (ColdReset) {
            *status = -2.0;
            exitg3 = 2;
          } else {
            nA = 0;
            memset(&iA[0], 0, 60U * sizeof(short));
            memset(&iC[0], 0, 60U * sizeof(short));
            ColdReset = true;
          }
        } else {
          for (iSave = 1; iSave <= nA; iSave++) {
            i = 11 + iSave;
            if (i > 32767) {
              i = 32767;
            }

            Rhs[i - 1] = b[iC[iSave - 1] - 1];
            for (b_i = iSave; b_i <= nA; b_i++) {
              U[(b_i + 11 * (iSave - 1)) - 1] = 0.0;
              for (kDrop = 1; kDrop <= nA; kDrop++) {
                U[(b_i + 11 * (iSave - 1)) - 1] += RLinv[(b_i + 11 * (kDrop - 1))
                  - 1] * RLinv[(iSave + 11 * (kDrop - 1)) - 1];
              }

              U[(iSave + 11 * (b_i - 1)) - 1] = U[(b_i + 11 * (iSave - 1)) - 1];
            }
          }

          for (b_i = 0; b_i < 11; b_i++) {
            d5 = 0.0;
            for (i = 0; i < 11; i++) {
              d5 += H[b_i + 11 * i] * Rhs[i];
            }

            Opt[b_i] = d5;
            for (kDrop = 1; kDrop <= nA; kDrop++) {
              Opt[b_i] += D[b_i + 11 * (kDrop - 1)] * Rhs[10 + kDrop];
            }
          }

          for (b_i = 1; b_i <= nA; b_i++) {
            d5 = 0.0;
            for (i = 0; i < 11; i++) {
              d5 += D[i + 11 * (b_i - 1)] * Rhs[i];
            }

            Opt[b_i + 10] = d5;
            for (kDrop = 1; kDrop <= nA; kDrop++) {
              Opt[b_i + 10] += U[(b_i + 11 * (kDrop - 1)) - 1] * Rhs[10 + kDrop];
            }
          }

          cVal = -1.0E-12;
          kDrop = 0;
          for (b_i = 1; b_i <= nA; b_i++) {
            lambda[iC[b_i - 1] - 1] = Opt[b_i + 10];
            if ((Opt[b_i + 10] < cVal) && (b_i <= nA)) {
              kDrop = b_i;
              cVal = Opt[b_i + 10];
            }
          }

          if (kDrop <= 0) {
            DualFeasible = true;
            memcpy(&x[0], &Opt[0], 11U * sizeof(double));
          } else {
            (*status)++;
            if ((int)*status > q) {
              nA = 0;
              memset(&iA[0], 0, 60U * sizeof(short));
              memset(&iC[0], 0, 60U * sizeof(short));
              ColdReset = true;
            } else {
              lambda[iC[kDrop - 1] - 1] = 0.0;
              DropConstraint(kDrop, iA, &nA, iC);
            }
          }
        }
      } else {
        if (nA <= 0) {
          memset(&lambda[0], 0, 60U * sizeof(double));
          Unconstrained(Hinv, f, x);
        }

        exitg3 = 1;
      }
    } while (exitg3 == 0);

    if (exitg3 == 1) {
      guard1 = true;
    }
  } else {
    Unconstrained(Hinv, f, x);
    guard1 = true;
  }

  if (guard1) {
    Xnorm0 = norm(x);
    do {
      exitg2 = 0;
      if (*status <= 284.0) {
        cMin = -1.0E-6;
        kNext = 0;
        for (b_i = 0; b_i < 60; b_i++) {
          if (!cTolComputed) {
            for (i = 0; i < 11; i++) {
              z[i] = Ac[b_i + 60 * i] * x[i];
            }

            b_abs(z, dv21);
            memcpy(&z[0], &dv21[0], 11U * sizeof(double));
            i = 1;
            cVal = z[0];
            if (rtIsNaN(z[0])) {
              ix = 2;
              exitg4 = false;
              while ((!exitg4) && (ix < 12)) {
                i = ix;
                if (!rtIsNaN(z[ix - 1])) {
                  cVal = z[ix - 1];
                  exitg4 = true;
                } else {
                  ix++;
                }
              }
            }

            if (i < 11) {
              while (i + 1 < 12) {
                if (z[i] > cVal) {
                  cVal = z[i];
                }

                i++;
              }
            }

            if ((cTol[b_i] > cVal) || rtIsNaN(cVal)) {
            } else {
              cTol[b_i] = cVal;
            }
          }

          if (iA[b_i] == 0) {
            d5 = 0.0;
            for (i = 0; i < 11; i++) {
              d5 += Ac[b_i + 60 * i] * x[i];
            }

            cVal = (d5 - b[b_i]) / cTol[b_i];
            if (cVal < cMin) {
              cMin = cVal;
              kNext = (short)(b_i + 1);
            }
          }
        }

        cTolComputed = true;
        if (kNext <= 0) {
          exitg2 = 1;
        } else {
          do {
            exitg1 = 0;
            if ((kNext > 0) && (*status <= 284.0)) {
              guard2 = false;
              if (nA == 0) {
                for (i = 0; i < 11; i++) {
                  z[i] = 0.0;
                  for (ix = 0; ix < 11; ix++) {
                    z[i] += Hinv[i + 11 * ix] * Ac[(kNext + 60 * ix) - 1];
                  }
                }

                guard2 = true;
              } else {
                cVal = KWIKfactor(Ac, iC, nA, Linv, RLinv, D, H);
                if (cVal <= 0.0) {
                  *status = -2.0;
                  exitg1 = 1;
                } else {
                  for (i = 0; i < 11; i++) {
                    for (ix = 0; ix < 11; ix++) {
                      U[ix + 11 * i] = -H[ix + 11 * i];
                    }
                  }

                  for (i = 0; i < 11; i++) {
                    z[i] = 0.0;
                    for (ix = 0; ix < 11; ix++) {
                      z[i] += U[i + 11 * ix] * Ac[(kNext + 60 * ix) - 1];
                    }
                  }

                  for (b_i = 1; b_i <= nA; b_i++) {
                    d5 = 0.0;
                    for (i = 0; i < 11; i++) {
                      d5 += Ac[(kNext + 60 * i) - 1] * D[i + 11 * (b_i - 1)];
                    }

                    r[b_i - 1] = d5;
                  }

                  guard2 = true;
                }
              }

              if (guard2) {
                kDrop = 0;
                t1 = 0.0;
                ColdReset = true;
                DualFeasible = true;
                if (nA > 0) {
                  iSave = 1;
                  exitg4 = false;
                  while ((!exitg4) && (iSave <= nA)) {
                    if (r[iSave - 1] >= 1.0E-12) {
                      DualFeasible = false;
                      exitg4 = true;
                    } else {
                      iSave++;
                    }
                  }
                }

                if ((nA == 0) || DualFeasible) {
                  DualFeasible = true;
                } else {
                  DualFeasible = false;
                }

                if (!DualFeasible) {
                  for (b_i = 1; b_i <= nA; b_i++) {
                    if (r[b_i - 1] > 1.0E-12) {
                      cVal = lambda[iC[b_i - 1] - 1] / r[b_i - 1];
                      if ((kDrop == 0) || (cVal < rMin)) {
                        rMin = cVal;
                        kDrop = b_i;
                      }
                    }
                  }

                  if (kDrop > 0) {
                    t1 = rMin;
                    ColdReset = false;
                  }
                }

                d5 = 0.0;
                for (i = 0; i < 11; i++) {
                  d5 += z[i] * Ac[(kNext + 60 * i) - 1];
                }

                if (d5 <= 0.0) {
                  cMin = 0.0;
                  DualFeasible = true;
                } else {
                  cVal = 0.0;
                  for (i = 0; i < 11; i++) {
                    cVal += Ac[(kNext + 60 * i) - 1] * x[i];
                  }

                  cMin = (b[kNext - 1] - cVal) / d5;
                  DualFeasible = false;
                }

                if (ColdReset && DualFeasible) {
                  *status = -1.0;
                  exitg1 = 1;
                } else {
                  if ((t1 < cMin) || rtIsNaN(cMin)) {
                    cVal = t1;
                  } else {
                    cVal = cMin;
                  }

                  if (DualFeasible) {
                    cVal = t1;
                  } else {
                    if (ColdReset) {
                      cVal = cMin;
                    }
                  }

                  for (b_i = 1; b_i <= nA; b_i++) {
                    lambda[iC[b_i - 1] - 1] -= cVal * r[b_i - 1];
                    if (lambda[iC[b_i - 1] - 1] < 0.0) {
                      lambda[iC[b_i - 1] - 1] = 0.0;
                    }
                  }

                  lambda[kNext - 1] += cVal;
                  if (cVal == t1) {
                    DropConstraint(kDrop, iA, &nA, iC);
                  }

                  if (!DualFeasible) {
                    for (i = 0; i < 11; i++) {
                      x[i] += cVal * z[i];
                    }

                    if (cVal == cMin) {
                      if (nA == 11) {
                        *status = -1.0;
                        exitg1 = 1;
                      } else {
                        i = nA + 1;
                        if (i > 32767) {
                          i = 32767;
                        }

                        nA = (short)i;
                        iC[nA - 1] = kNext;
                        b_i = nA;
                        while ((b_i > 1) && (!(iC[b_i - 1] > iC[b_i - 2]))) {
                          iSave = iC[b_i - 1];
                          iC[b_i - 1] = iC[b_i - 2];
                          iC[b_i - 2] = iSave;
                          b_i--;
                        }

                        iA[kNext - 1] = 1;
                        kNext = 0;
                        (*status)++;
                      }
                    } else {
                      (*status)++;
                    }
                  } else {
                    (*status)++;
                  }
                }
              }
            } else {
              cVal = norm(x);
              if (std::abs(cVal - Xnorm0) > 0.001) {
                Xnorm0 = cVal;
                c_abs(b, varargin_1);
                for (i = 0; i < 60; i++) {
                  cVal = varargin_1[i];
                  if (!(cVal > 1.0)) {
                    cVal = 1.0;
                  }

                  cTol[i] = cVal;
                }

                cTolComputed = false;
              }

              exitg1 = 2;
            }
          } while (exitg1 == 0);

          if (exitg1 == 1) {
            exitg2 = 1;
          }
        }
      } else {
        *status = 0.0;
        exitg2 = 1;
      }
    } while (exitg2 == 0);
  }
}

//
// File trailer for qpkwik.cpp
//
// [EOF]
//
