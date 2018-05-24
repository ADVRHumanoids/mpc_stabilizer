/*
 * MpcController.cpp
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "MpcController".
 *
 * Model version              : 1.5
 * Simulink Coder version : 8.13 (R2017b) 24-Jul-2017
 * C++ source code generated on : Thu May 24 12:54:04 2018
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objective: Execution efficiency
 * Validation result: Not run
 */

#include "MpcController.h"
#include "MpcController_private.h"

/* Named constants for MATLAB Function: '<S4>/optimizer' */
#define MpcController_ny               (4.0)

/* Function for MATLAB Function: '<S4>/optimizer' */
real_T MpcControllerModelClass::MpcController_mod(real_T x)
{
  real_T r;
  if ((!rtIsInf(x)) && (!rtIsNaN(x))) {
    if (x == 0.0) {
      r = 0.0;
    } else {
      r = std::fmod(x, MpcController_ny);
      if (r == 0.0) {
        r = 0.0;
      } else {
        if (x < 0.0) {
          r += MpcController_ny;
        }
      }
    }
  } else {
    r = (rtNaN);
  }

  return r;
}

/* Function for MATLAB Function: '<S4>/optimizer' */
void MpcControllerModelClass::MpcController_Unconstrained(const real_T b_Hinv
  [121], const real_T f[11], real_T x[11], int16_T n)
{
  int16_T i;
  real_T tmp;
  int32_T i_0;
  for (i = 1; i <= n; i++) {
    tmp = 0.0;
    for (i_0 = 0; i_0 < 11; i_0++) {
      tmp += -b_Hinv[(11 * i_0 + i) - 1] * f[i_0];
    }

    x[i - 1] = tmp;
  }
}

/* Function for MATLAB Function: '<S4>/optimizer' */
real_T MpcControllerModelClass::MpcController_norm(const real_T x[11])
{
  real_T y;
  real_T scale;
  real_T absxk;
  real_T t;
  int32_T k;
  y = 0.0;
  scale = 3.3121686421112381E-170;
  for (k = 0; k < 11; k++) {
    absxk = std::abs(x[k]);
    if (absxk > scale) {
      t = scale / absxk;
      y = y * t * t + 1.0;
      scale = absxk;
    } else {
      t = absxk / scale;
      y += t * t;
    }
  }

  return scale * std::sqrt(y);
}

/* Function for MATLAB Function: '<S4>/optimizer' */
void MpcControllerModelClass::MpcController_abs(const real_T x[11], real_T y[11])
{
  int32_T k;
  for (k = 0; k < 11; k++) {
    y[k] = std::abs(x[k]);
  }
}

/* Function for MATLAB Function: '<S4>/optimizer' */
void MpcControllerModelClass::MpcController_abs_e(const real_T x[60], real_T y
  [60])
{
  int32_T k;
  for (k = 0; k < 60; k++) {
    y[k] = std::abs(x[k]);
  }
}

/* Function for MATLAB Function: '<S4>/optimizer' */
real_T MpcControllerModelClass::MpcController_xnrm2(int32_T n, const real_T x
  [121], int32_T ix0)
{
  real_T y;
  real_T scale;
  int32_T kend;
  real_T absxk;
  real_T t;
  int32_T k;
  y = 0.0;
  if (!(n < 1)) {
    if (n == 1) {
      y = std::abs(x[ix0 - 1]);
    } else {
      scale = 3.3121686421112381E-170;
      kend = (ix0 + n) - 1;
      for (k = ix0; k <= kend; k++) {
        absxk = std::abs(x[k - 1]);
        if (absxk > scale) {
          t = scale / absxk;
          y = y * t * t + 1.0;
          scale = absxk;
        } else {
          t = absxk / scale;
          y += t * t;
        }
      }

      y = scale * std::sqrt(y);
    }
  }

  return y;
}

real_T rt_hypotd_snf(real_T u0, real_T u1)
{
  real_T y;
  real_T a;
  a = std::abs(u0);
  y = std::abs(u1);
  if (a < y) {
    a /= y;
    y *= std::sqrt(a * a + 1.0);
  } else if (a > y) {
    y /= a;
    y = std::sqrt(y * y + 1.0) * a;
  } else {
    if (!rtIsNaN(y)) {
      y = a * 1.4142135623730951;
    }
  }

  return y;
}

/* Function for MATLAB Function: '<S4>/optimizer' */
void MpcControllerModelClass::MpcController_xgemv(int32_T m, int32_T n, const
  real_T b_A[121], int32_T ia0, const real_T x[121], int32_T ix0, real_T y[11])
{
  int32_T ix;
  real_T c;
  int32_T iy;
  int32_T b;
  int32_T iac;
  int32_T d;
  int32_T ia;
  if (!((m == 0) || (n == 0))) {
    for (iy = 1; iy <= n; iy++) {
      y[iy - 1] = 0.0;
    }

    iy = 0;
    b = (n - 1) * 11 + ia0;
    for (iac = ia0; iac <= b; iac += 11) {
      ix = ix0;
      c = 0.0;
      d = (iac + m) - 1;
      for (ia = iac; ia <= d; ia++) {
        c += b_A[ia - 1] * x[ix - 1];
        ix++;
      }

      y[iy] += c;
      iy++;
    }
  }
}

/* Function for MATLAB Function: '<S4>/optimizer' */
void MpcControllerModelClass::MpcController_xger(int32_T m, int32_T n, real_T
  alpha1, int32_T ix0, const real_T y[11], real_T b_A[121], int32_T ia0)
{
  int32_T jA;
  int32_T jy;
  real_T temp;
  int32_T ix;
  int32_T j;
  int32_T b;
  int32_T ijA;
  if (!(alpha1 == 0.0)) {
    jA = ia0 - 1;
    jy = 0;
    for (j = 1; j <= n; j++) {
      if (y[jy] != 0.0) {
        temp = y[jy] * alpha1;
        ix = ix0;
        b = m + jA;
        for (ijA = jA; ijA + 1 <= b; ijA++) {
          b_A[ijA] += b_A[ix - 1] * temp;
          ix++;
        }
      }

      jy++;
      jA += 11;
    }
  }
}

/* Function for MATLAB Function: '<S4>/optimizer' */
void MpcControllerModelClass::MpcController_xgeqrf(real_T b_A[121], real_T tau
  [11])
{
  real_T work[11];
  int32_T i_i;
  real_T b;
  real_T b_atmp;
  int32_T i;
  real_T xnorm;
  int32_T knt;
  int32_T lastv;
  int32_T lastc;
  int32_T coltop;
  int32_T ia;
  int32_T exitg1;
  boolean_T exitg2;
  memset(&work[0], 0, 11U * sizeof(real_T));
  for (i = 0; i < 11; i++) {
    i_i = i * 11 + i;
    if (i + 1 < 11) {
      b_atmp = b_A[i_i];
      b = 0.0;
      xnorm = MpcController_xnrm2(10 - i, b_A, i_i + 2);
      if (xnorm != 0.0) {
        xnorm = rt_hypotd_snf(b_A[i_i], xnorm);
        if (b_A[i_i] >= 0.0) {
          xnorm = -xnorm;
        }

        if (std::abs(xnorm) < 1.0020841800044864E-292) {
          knt = 0;
          lastv = (i_i - i) + 11;
          do {
            knt++;
            for (lastc = i_i + 1; lastc + 1 <= lastv; lastc++) {
              b_A[lastc] *= 9.9792015476736E+291;
            }

            xnorm *= 9.9792015476736E+291;
            b_atmp *= 9.9792015476736E+291;
          } while (!(std::abs(xnorm) >= 1.0020841800044864E-292));

          xnorm = rt_hypotd_snf(b_atmp, MpcController_xnrm2(10 - i, b_A, i_i + 2));
          if (b_atmp >= 0.0) {
            xnorm = -xnorm;
          }

          b = (xnorm - b_atmp) / xnorm;
          b_atmp = 1.0 / (b_atmp - xnorm);
          lastv = (i_i - i) + 11;
          for (lastc = i_i + 1; lastc + 1 <= lastv; lastc++) {
            b_A[lastc] *= b_atmp;
          }

          for (lastv = 1; lastv <= knt; lastv++) {
            xnorm *= 1.0020841800044864E-292;
          }

          b_atmp = xnorm;
        } else {
          b = (xnorm - b_A[i_i]) / xnorm;
          b_atmp = 1.0 / (b_A[i_i] - xnorm);
          knt = (i_i - i) + 11;
          for (lastv = i_i + 1; lastv + 1 <= knt; lastv++) {
            b_A[lastv] *= b_atmp;
          }

          b_atmp = xnorm;
        }
      }

      tau[i] = b;
      b_A[i_i] = b_atmp;
      b_atmp = b_A[i_i];
      b_A[i_i] = 1.0;
      knt = ((i + 1) * 11 + i) + 1;
      if (tau[i] != 0.0) {
        lastv = 11 - i;
        lastc = (i_i - i) + 10;
        while ((lastv > 0) && (b_A[lastc] == 0.0)) {
          lastv--;
          lastc--;
        }

        lastc = 10 - i;
        exitg2 = false;
        while ((!exitg2) && (lastc > 0)) {
          coltop = (lastc - 1) * 11 + knt;
          ia = coltop;
          do {
            exitg1 = 0;
            if (ia <= (coltop + lastv) - 1) {
              if (b_A[ia - 1] != 0.0) {
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
        MpcController_xgemv(lastv, lastc, b_A, knt, b_A, i_i + 1, work);
        MpcController_xger(lastv, lastc, -tau[i], i_i + 1, work, b_A, knt);
      }

      b_A[i_i] = b_atmp;
    } else {
      tau[10] = 0.0;
    }
  }
}

/* Function for MATLAB Function: '<S4>/optimizer' */
void MpcControllerModelClass::MpcController_qr(const real_T b_A[121], real_T Q
  [121], real_T R[121])
{
  real_T c_A[121];
  real_T tau[11];
  int32_T d_i;
  int32_T itau;
  real_T work[11];
  int32_T iaii;
  int32_T lastv;
  int32_T lastc;
  int32_T coltop;
  int32_T ia;
  int32_T exitg1;
  boolean_T exitg2;
  memcpy(&c_A[0], &b_A[0], 121U * sizeof(real_T));
  MpcController_xgeqrf(c_A, tau);
  for (itau = 0; itau < 11; itau++) {
    for (d_i = 0; d_i + 1 <= itau + 1; d_i++) {
      R[d_i + 11 * itau] = c_A[11 * itau + d_i];
    }

    for (d_i = itau + 1; d_i + 1 < 12; d_i++) {
      R[d_i + 11 * itau] = 0.0;
    }

    work[itau] = 0.0;
  }

  itau = 10;
  for (d_i = 10; d_i >= 0; d_i--) {
    iaii = (d_i * 11 + d_i) + 1;
    if (d_i + 1 < 11) {
      c_A[iaii - 1] = 1.0;
      if (tau[itau] != 0.0) {
        lastv = 11 - d_i;
        lastc = (iaii - d_i) + 9;
        while ((lastv > 0) && (c_A[lastc] == 0.0)) {
          lastv--;
          lastc--;
        }

        lastc = 10 - d_i;
        exitg2 = false;
        while ((!exitg2) && (lastc > 0)) {
          coltop = ((lastc - 1) * 11 + iaii) + 10;
          ia = coltop;
          do {
            exitg1 = 0;
            if (ia + 1 <= coltop + lastv) {
              if (c_A[ia] != 0.0) {
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
        MpcController_xgemv(lastv, lastc, c_A, iaii + 11, c_A, iaii, work);
        MpcController_xger(lastv, lastc, -tau[itau], iaii, work, c_A, iaii + 11);
      }

      lastv = (iaii - d_i) + 10;
      for (lastc = iaii; lastc + 1 <= lastv; lastc++) {
        c_A[lastc] *= -tau[itau];
      }
    }

    c_A[iaii - 1] = 1.0 - tau[itau];
    for (lastv = 1; lastv <= d_i; lastv++) {
      c_A[(iaii - lastv) - 1] = 0.0;
    }

    itau--;
  }

  for (itau = 0; itau < 11; itau++) {
    memcpy(&Q[itau * 11], &c_A[itau * 11], 11U * sizeof(real_T));
  }
}

/* Function for MATLAB Function: '<S4>/optimizer' */
real_T MpcControllerModelClass::MpcController_KWIKfactor(const real_T b_Ac[660],
  const int16_T iC[60], int16_T nA, const real_T b_Linv[121], real_T RLinv[121],
  real_T D[121], real_T b_H[121], int16_T n)
{
  real_T Status;
  real_T TL[121];
  real_T QQ[121];
  real_T RR[121];
  int16_T i;
  int16_T f_i;
  int16_T d_k;
  real_T tmp;
  int32_T i_0;
  int32_T i_1;
  int32_T tmp_0;
  int32_T i_2;
  int32_T exitg1;
  Status = 1.0;
  memset(&RLinv[0], 0, 121U * sizeof(real_T));
  for (i = 1; i <= nA; i++) {
    for (i_1 = 0; i_1 < 11; i_1++) {
      RLinv[i_1 + 11 * (i - 1)] = 0.0;
    }

    i_2 = i - 1;
    for (i_1 = 0; i_1 < 11; i_1++) {
      tmp_0 = i_1 + 11 * i_2;
      RLinv[tmp_0] = 0.0;
      for (i_0 = 0; i_0 < 11; i_0++) {
        RLinv[tmp_0] = b_Ac[(iC[i - 1] + 60 * i_0) - 1] * b_Linv[11 * i_0 + i_1]
          + RLinv[11 * i_2 + i_1];
      }
    }
  }

  MpcController_qr(RLinv, QQ, RR);
  i = 1;
  do {
    exitg1 = 0;
    if (i <= nA) {
      if (std::abs(RR[((i - 1) * 11 + i) - 1]) < 1.0E-12) {
        Status = -2.0;
        exitg1 = 1;
      } else {
        i++;
      }
    } else {
      for (i = 1; i <= n; i++) {
        for (f_i = 1; f_i <= n; f_i++) {
          tmp = 0.0;
          for (i_1 = 0; i_1 < 11; i_1++) {
            tmp += b_Linv[(i - 1) * 11 + i_1] * QQ[(f_i - 1) * 11 + i_1];
          }

          TL[(i + 11 * (f_i - 1)) - 1] = tmp;
        }
      }

      memset(&RLinv[0], 0, 121U * sizeof(real_T));
      i = nA;
      while (i > 0) {
        i_1 = i - 1;
        RLinv[(i + 11 * i_1) - 1] = 1.0;
        for (f_i = i; f_i <= nA; f_i++) {
          tmp_0 = f_i - 1;
          RLinv[(i + 11 * tmp_0) - 1] /= RR[((i - 1) * 11 + i) - 1];
        }

        if (i > 1) {
          for (f_i = 1; f_i <= i_1; f_i++) {
            for (d_k = i; d_k <= nA; d_k++) {
              tmp_0 = d_k - 1;
              i_0 = tmp_0 * 11;
              RLinv[(f_i + 11 * tmp_0) - 1] = RLinv[(i_0 + f_i) - 1] - RR[(i_1 *
                11 + f_i) - 1] * RLinv[(i_0 + i) - 1];
            }
          }
        }

        i = (int16_T)i_1;
      }

      for (i = 1; i <= n; i++) {
        for (f_i = i; f_i <= n; f_i++) {
          i_1 = f_i - 1;
          tmp_0 = (i + 11 * i_1) - 1;
          b_H[tmp_0] = 0.0;
          for (d_k = (int16_T)(nA + 1); d_k <= n; d_k++) {
            i_0 = (d_k - 1) * 11;
            b_H[tmp_0] = b_H[((f_i - 1) * 11 + i) - 1] - TL[(i_0 + i) - 1] * TL
              [(i_0 + f_i) - 1];
          }

          b_H[(f_i + 11 * (i - 1)) - 1] = b_H[(i_1 * 11 + i) - 1];
        }
      }

      for (i = 1; i <= nA; i++) {
        for (f_i = 1; f_i <= n; f_i++) {
          i_1 = i - 1;
          tmp_0 = (f_i + 11 * i_1) - 1;
          D[tmp_0] = 0.0;
          for (d_k = i; d_k <= nA; d_k++) {
            i_0 = (d_k - 1) * 11;
            D[tmp_0] = TL[(i_0 + f_i) - 1] * RLinv[(i_0 + i) - 1] + D[(i_1 * 11
              + f_i) - 1];
          }
        }
      }

      exitg1 = 1;
    }
  } while (exitg1 == 0);

  return Status;
}

/* Function for MATLAB Function: '<S4>/optimizer' */
void MpcControllerModelClass::MpcController_DropConstraint(int16_T kDrop,
  int16_T iA[60], int16_T *nA, int16_T iC[60])
{
  int16_T i;
  int32_T tmp;
  iA[iC[kDrop - 1] - 1] = 0;
  if (kDrop < *nA) {
    tmp = *nA - 1;
    if (tmp < -32768) {
      tmp = -32768;
    }

    for (i = kDrop; i <= (int16_T)tmp; i++) {
      iC[i - 1] = iC[i];
    }
  }

  iC[*nA - 1] = 0;
  tmp = *nA - 1;
  if (tmp < -32768) {
    tmp = -32768;
  }

  *nA = (int16_T)tmp;
}

/* Function for MATLAB Function: '<S4>/optimizer' */
void MpcControllerModelClass::MpcController_qpkwik(const real_T b_Linv[121],
  const real_T b_Hinv[121], const real_T f[11], const real_T b_Ac[660], const
  real_T b[60], int16_T iA[60], int16_T b_maxiter, real_T FeasTol, real_T x[11],
  real_T lambda[60], real_T *status)
{
  real_T r[11];
  real_T rMin;
  real_T RLinv[121];
  real_T D[121];
  real_T b_H[121];
  real_T U[121];
  real_T cTol[60];
  boolean_T cTolComputed;
  int16_T iC[60];
  int16_T nA;
  real_T Opt[22];
  real_T Rhs[22];
  boolean_T DualFeasible;
  boolean_T ColdReset;
  int16_T kDrop;
  real_T Xnorm0;
  real_T cMin;
  int16_T kNext;
  real_T cVal;
  real_T AcRow[11];
  real_T t;
  int16_T iSave;
  uint16_T q;
  uint16_T b_x;
  real_T varargin_1[60];
  int32_T i;
  real_T b_Ac_0[11];
  int32_T tmp;
  int32_T kDrop_tmp;
  int32_T U_tmp;
  int32_T exitg1;
  int32_T exitg2;
  int32_T exitg3;
  boolean_T exitg4;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  *status = 1.0;
  memset(&lambda[0], 0, 60U * sizeof(real_T));
  memset(&x[0], 0, 11U * sizeof(real_T));
  memset(&r[0], 0, 11U * sizeof(real_T));
  rMin = 0.0;
  cTolComputed = false;
  for (i = 0; i < 60; i++) {
    cTol[i] = 1.0;
    iC[i] = 0;
  }

  nA = 0;
  for (kNext = 0; kNext < 60; kNext++) {
    if (iA[kNext] == 1) {
      i = nA + 1;
      if (i > 32767) {
        i = 32767;
      }

      nA = (int16_T)i;
      iC[(int16_T)i - 1] = (int16_T)(kNext + 1);
    }
  }

  guard1 = false;
  if (nA > 0) {
    memset(&Opt[0], 0, 22U * sizeof(real_T));
    for (i = 0; i < 11; i++) {
      Rhs[i] = f[i];
      Rhs[i + 11] = 0.0;
    }

    DualFeasible = false;
    i = 3 * nA;
    if (i > 32767) {
      i = 32767;
    }

    if ((int16_T)i > 50) {
      kNext = (int16_T)i;
    } else {
      kNext = 50;
    }

    q = (uint16_T)(kNext / 10U);
    b_x = (uint16_T)((uint32_T)kNext - q * 10);
    if ((b_x > 0) && (b_x >= 5)) {
      q++;
    }

    ColdReset = false;
    do {
      exitg3 = 0;
      if ((!DualFeasible) && (nA > 0) && ((int32_T)*status <= b_maxiter)) {
        Xnorm0 = MpcController_KWIKfactor(b_Ac, iC, nA, b_Linv, RLinv, D, b_H,
          11);
        if (Xnorm0 < 0.0) {
          if (ColdReset) {
            *status = -2.0;
            exitg3 = 2;
          } else {
            nA = 0;
            memset(&iA[0], 0, 60U * sizeof(int16_T));
            memset(&iC[0], 0, 60U * sizeof(int16_T));
            ColdReset = true;
          }
        } else {
          for (kNext = 1; kNext <= nA; kNext++) {
            i = 11 + kNext;
            if (i > 32767) {
              i = 32767;
            }

            kDrop_tmp = kNext - 1;
            Rhs[i - 1] = b[iC[kDrop_tmp] - 1];
            for (kDrop = kNext; kDrop <= nA; kDrop++) {
              i = (kDrop + 11 * kDrop_tmp) - 1;
              U[i] = 0.0;
              for (iSave = 1; iSave <= nA; iSave++) {
                U_tmp = (iSave - 1) * 11;
                U[i] = RLinv[(U_tmp + kDrop) - 1] * RLinv[(U_tmp + kNext) - 1] +
                  U[((kNext - 1) * 11 + kDrop) - 1];
              }

              U[(kNext + 11 * (kDrop - 1)) - 1] = U[(kDrop_tmp * 11 + kDrop) - 1];
            }
          }

          for (kNext = 0; kNext < 11; kNext++) {
            kDrop_tmp = kNext + 1;
            cVal = 0.0;
            for (i = 0; i < 11; i++) {
              cVal += b_H[(11 * i + kDrop_tmp) - 1] * Rhs[i];
            }

            Opt[kNext] = cVal;
            for (kDrop = 1; kDrop <= nA; kDrop++) {
              i = 11 + kDrop;
              if (i > 32767) {
                i = 32767;
              }

              Opt[kNext] += D[(kDrop - 1) * 11 + kNext] * Rhs[i - 1];
            }
          }

          for (kNext = 1; kNext <= nA; kNext++) {
            cVal = 0.0;
            for (i = 0; i < 11; i++) {
              cVal += D[(kNext - 1) * 11 + i] * Rhs[i];
            }

            i = 11 + kNext;
            kDrop_tmp = i;
            if (i > 32767) {
              kDrop_tmp = 32767;
            }

            Opt[kDrop_tmp - 1] = cVal;
            for (kDrop = 1; kDrop <= nA; kDrop++) {
              kDrop_tmp = i;
              if (i > 32767) {
                kDrop_tmp = 32767;
              }

              U_tmp = i;
              if (i > 32767) {
                U_tmp = 32767;
              }

              tmp = 11 + kDrop;
              if (tmp > 32767) {
                tmp = 32767;
              }

              Opt[kDrop_tmp - 1] = U[((kDrop - 1) * 11 + kNext) - 1] * Rhs[tmp -
                1] + Opt[U_tmp - 1];
            }
          }

          Xnorm0 = -1.0E-12;
          kDrop = 0;
          for (kNext = 1; kNext <= nA; kNext++) {
            i = 11 + kNext;
            kDrop_tmp = i;
            if (i > 32767) {
              kDrop_tmp = 32767;
            }

            lambda[iC[kNext - 1] - 1] = Opt[kDrop_tmp - 1];
            kDrop_tmp = i;
            if (i > 32767) {
              kDrop_tmp = 32767;
            }

            if ((Opt[kDrop_tmp - 1] < Xnorm0) && (kNext <= nA)) {
              kDrop = kNext;
              if (i > 32767) {
                i = 32767;
              }

              Xnorm0 = Opt[i - 1];
            }
          }

          if (kDrop <= 0) {
            DualFeasible = true;
            memcpy(&x[0], &Opt[0], 11U * sizeof(real_T));
          } else {
            (*status)++;
            if ((int32_T)*status > q) {
              nA = 0;
              memset(&iA[0], 0, 60U * sizeof(int16_T));
              memset(&iC[0], 0, 60U * sizeof(int16_T));
              ColdReset = true;
            } else {
              lambda[iC[kDrop - 1] - 1] = 0.0;
              MpcController_DropConstraint(kDrop, iA, &nA, iC);
            }
          }
        }
      } else {
        if (nA <= 0) {
          memset(&lambda[0], 0, 60U * sizeof(real_T));
          MpcController_Unconstrained(b_Hinv, f, x, 11);
        }

        exitg3 = 1;
      }
    } while (exitg3 == 0);

    if (exitg3 == 1) {
      guard1 = true;
    }
  } else {
    MpcController_Unconstrained(b_Hinv, f, x, 11);
    guard1 = true;
  }

  if (guard1) {
    Xnorm0 = MpcController_norm(x);
    do {
      exitg2 = 0;
      if ((int32_T)*status <= b_maxiter) {
        cMin = -FeasTol;
        kNext = 0;
        for (kDrop = 0; kDrop < 60; kDrop++) {
          if (!cTolComputed) {
            kDrop_tmp = kDrop + 1;
            for (i = 0; i < 11; i++) {
              b_Ac_0[i] = b_Ac[(60 * i + kDrop_tmp) - 1] * x[i];
            }

            MpcController_abs(b_Ac_0, AcRow);
            i = 1;
            cVal = AcRow[0];
            if (rtIsNaN(AcRow[0])) {
              kDrop_tmp = 2;
              exitg4 = false;
              while ((!exitg4) && (kDrop_tmp < 12)) {
                i = kDrop_tmp;
                if (!rtIsNaN(AcRow[kDrop_tmp - 1])) {
                  cVal = AcRow[kDrop_tmp - 1];
                  exitg4 = true;
                } else {
                  kDrop_tmp++;
                }
              }
            }

            if (i < 11) {
              while (i + 1 < 12) {
                if (AcRow[i] > cVal) {
                  cVal = AcRow[i];
                }

                i++;
              }
            }

            if (!((cTol[kDrop] > cVal) || rtIsNaN(cVal))) {
              cTol[kDrop] = cVal;
            }
          }

          if (iA[kDrop] == 0) {
            kDrop_tmp = kDrop + 1;
            cVal = 0.0;
            for (i = 0; i < 11; i++) {
              cVal += b_Ac[(60 * i + kDrop_tmp) - 1] * x[i];
            }

            cVal = (cVal - b[kDrop]) / cTol[kDrop];
            if (cVal < cMin) {
              cMin = cVal;
              kNext = (int16_T)(kDrop + 1);
            }
          }
        }

        cTolComputed = true;
        if (kNext <= 0) {
          exitg2 = 1;
        } else {
          do {
            exitg1 = 0;
            if ((kNext > 0) && ((int32_T)*status <= b_maxiter)) {
              guard2 = false;
              if (nA == 0) {
                for (i = 0; i < 11; i++) {
                  AcRow[i] = 0.0;
                  for (kDrop_tmp = 0; kDrop_tmp < 11; kDrop_tmp++) {
                    AcRow[i] += b_Ac[(60 * kDrop_tmp + kNext) - 1] * b_Hinv[11 *
                      kDrop_tmp + i];
                  }
                }

                guard2 = true;
              } else {
                cMin = MpcController_KWIKfactor(b_Ac, iC, nA, b_Linv, RLinv, D,
                  b_H, 11);
                if (cMin <= 0.0) {
                  *status = -2.0;
                  exitg1 = 1;
                } else {
                  for (i = 0; i < 11; i++) {
                    for (kDrop_tmp = 0; kDrop_tmp < 11; kDrop_tmp++) {
                      U[kDrop_tmp + 11 * i] = -b_H[11 * i + kDrop_tmp];
                    }
                  }

                  for (i = 0; i < 11; i++) {
                    AcRow[i] = 0.0;
                    for (kDrop_tmp = 0; kDrop_tmp < 11; kDrop_tmp++) {
                      AcRow[i] += b_Ac[(60 * kDrop_tmp + kNext) - 1] * U[11 *
                        kDrop_tmp + i];
                    }
                  }

                  for (kDrop = 1; kDrop <= nA; kDrop++) {
                    cVal = 0.0;
                    for (i = 0; i < 11; i++) {
                      cVal += b_Ac[(60 * i + kNext) - 1] * D[(kDrop - 1) * 11 +
                        i];
                    }

                    r[kDrop - 1] = cVal;
                  }

                  guard2 = true;
                }
              }

              if (guard2) {
                kDrop = 0;
                cMin = 0.0;
                DualFeasible = true;
                ColdReset = true;
                if (nA > 0) {
                  iSave = 1;
                  exitg4 = false;
                  while ((!exitg4) && (iSave <= nA)) {
                    if (r[iSave - 1] >= 1.0E-12) {
                      ColdReset = false;
                      exitg4 = true;
                    } else {
                      iSave++;
                    }
                  }
                }

                if (!((nA == 0) || ColdReset)) {
                  for (iSave = 1; iSave <= nA; iSave++) {
                    i = iSave - 1;
                    if (r[i] > 1.0E-12) {
                      cVal = lambda[iC[i] - 1] / r[iSave - 1];
                      if ((kDrop == 0) || (cVal < rMin)) {
                        rMin = cVal;
                        kDrop = iSave;
                      }
                    }
                  }

                  if (kDrop > 0) {
                    cMin = rMin;
                    DualFeasible = false;
                  }
                }

                cVal = 0.0;
                for (i = 0; i < 11; i++) {
                  cVal += b_Ac[(60 * i + kNext) - 1] * AcRow[i];
                }

                if (cVal <= 0.0) {
                  cVal = 0.0;
                  ColdReset = true;
                } else {
                  t = 0.0;
                  for (i = 0; i < 11; i++) {
                    t += b_Ac[(60 * i + kNext) - 1] * x[i];
                  }

                  cVal = (b[kNext - 1] - t) / cVal;
                  ColdReset = false;
                }

                if (DualFeasible && ColdReset) {
                  *status = -1.0;
                  exitg1 = 1;
                } else {
                  if (ColdReset) {
                    t = cMin;
                  } else if (DualFeasible) {
                    t = cVal;
                  } else if ((cMin < cVal) || rtIsNaN(cVal)) {
                    t = cMin;
                  } else {
                    t = cVal;
                  }

                  for (iSave = 1; iSave <= nA; iSave++) {
                    i = iSave - 1;
                    kDrop_tmp = iC[i] - 1;
                    lambda[kDrop_tmp] -= r[i] * t;
                    if ((iC[iSave - 1] <= 60) && (lambda[iC[iSave - 1] - 1] <
                         0.0)) {
                      lambda[kDrop_tmp] = 0.0;
                    }
                  }

                  lambda[kNext - 1] += t;
                  if (t == cMin) {
                    MpcController_DropConstraint(kDrop, iA, &nA, iC);
                  }

                  if (!ColdReset) {
                    for (i = 0; i < 11; i++) {
                      x[i] += t * AcRow[i];
                    }

                    if (t == cVal) {
                      if (nA == 11) {
                        *status = -1.0;
                        exitg1 = 1;
                      } else {
                        i = nA + 1;
                        if (i > 32767) {
                          i = 32767;
                        }

                        nA = (int16_T)i;
                        iC[(int16_T)i - 1] = kNext;
                        kDrop = (int16_T)i;
                        exitg4 = false;
                        while ((!exitg4) && (kDrop > 1)) {
                          i = kDrop - 1;
                          kDrop_tmp = kDrop - 2;
                          if (iC[i] > iC[kDrop_tmp]) {
                            exitg4 = true;
                          } else {
                            iSave = iC[kDrop - 1];
                            iC[i] = iC[kDrop - 2];
                            iC[kDrop_tmp] = iSave;
                            kDrop = (int16_T)i;
                          }
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
              cMin = MpcController_norm(x);
              if (std::abs(cMin - Xnorm0) > 0.001) {
                Xnorm0 = cMin;
                MpcController_abs_e(b, varargin_1);
                for (i = 0; i < 60; i++) {
                  if (varargin_1[i] > 1.0) {
                    cTol[i] = varargin_1[i];
                  } else {
                    cTol[i] = 1.0;
                  }
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

/* Model step function */
void MpcControllerModelClass::step()
{
  real_T rseq[120];
  int32_T j;
  real_T Bc[60];
  real_T ymax_incr[4];
  real_T ymin_incr[4];
  real_T DelBound;
  real_T ii;
  real_T f[11];
  int32_T ix;
  real_T zopt[11];
  real_T unusedU0[60];
  int16_T iAnew[60];
  static const real_T b_Ac[660] = { 0.0045710034013605443, 0.0090170068027210885,
    0.013213010204081634, 0.01703401360544218, 0.020355017006802725,
    0.023051020408163269, 0.024997023809523813, 0.026068027210884356,
    0.0261390306122449, 0.025085034013605446, 0.022781037414965989,
    0.019102040816326535, 0.013923044217687079, 0.0071190476190476229,
    -0.001434948979591834, -0.01186394557823129, -0.024292942176870745,
    -0.0388469387755102, -0.055650935374149661, -0.074829931972789115,
    -0.096508928571428579, -0.12081292517006804, -0.1478669217687075,
    -0.17779591836734696, -0.21072491496598642, -0.24677891156462589,
    -0.28608290816326537, -0.32876190476190481, -0.37494090136054425,
    -0.42474489795918374, -0.0045710034013605443, -0.0090170068027210885,
    -0.013213010204081634, -0.01703401360544218, -0.020355017006802725,
    -0.023051020408163269, -0.024997023809523813, -0.026068027210884356,
    -0.0261390306122449, -0.025085034013605446, -0.022781037414965989,
    -0.019102040816326535, -0.013923044217687079, -0.0071190476190476229,
    0.001434948979591834, 0.01186394557823129, 0.024292942176870745,
    0.0388469387755102, 0.055650935374149661, 0.074829931972789115,
    0.096508928571428579, 0.12081292517006804, 0.1478669217687075,
    0.17779591836734696, 0.21072491496598642, 0.24677891156462589,
    0.28608290816326537, 0.32876190476190481, 0.37494090136054425,
    0.42474489795918374, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -0.0, 0.0045710034013605443,
    0.0090170068027210885, 0.013213010204081634, 0.01703401360544218,
    0.020355017006802725, 0.023051020408163269, 0.024997023809523813,
    0.026068027210884356, 0.0261390306122449, 0.025085034013605446,
    0.022781037414965989, 0.019102040816326535, 0.013923044217687079,
    0.0071190476190476229, -0.001434948979591834, -0.01186394557823129,
    -0.024292942176870745, -0.0388469387755102, -0.055650935374149661,
    -0.074829931972789115, -0.096508928571428579, -0.12081292517006804,
    -0.1478669217687075, -0.17779591836734696, -0.21072491496598642,
    -0.24677891156462589, -0.28608290816326537, -0.32876190476190481,
    -0.37494090136054425, 0.0, -0.0045710034013605443, -0.0090170068027210885,
    -0.013213010204081634, -0.01703401360544218, -0.020355017006802725,
    -0.023051020408163269, -0.024997023809523813, -0.026068027210884356,
    -0.0261390306122449, -0.025085034013605446, -0.022781037414965989,
    -0.019102040816326535, -0.013923044217687079, -0.0071190476190476229,
    0.001434948979591834, 0.01186394557823129, 0.024292942176870745,
    0.0388469387755102, 0.055650935374149661, 0.074829931972789115,
    0.096508928571428579, 0.12081292517006804, 0.1478669217687075,
    0.17779591836734696, 0.21072491496598642, 0.24677891156462589,
    0.28608290816326537, 0.32876190476190481, 0.37494090136054425, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, -0.0, -0.0, 0.0045710034013605443, 0.0090170068027210885,
    0.013213010204081634, 0.01703401360544218, 0.020355017006802725,
    0.023051020408163269, 0.024997023809523813, 0.026068027210884356,
    0.0261390306122449, 0.025085034013605446, 0.022781037414965989,
    0.019102040816326535, 0.013923044217687079, 0.0071190476190476229,
    -0.001434948979591834, -0.01186394557823129, -0.024292942176870745,
    -0.0388469387755102, -0.055650935374149661, -0.074829931972789115,
    -0.096508928571428579, -0.12081292517006804, -0.1478669217687075,
    -0.17779591836734696, -0.21072491496598642, -0.24677891156462589,
    -0.28608290816326537, -0.32876190476190481, 0.0, 0.0, -0.0045710034013605443,
    -0.0090170068027210885, -0.013213010204081634, -0.01703401360544218,
    -0.020355017006802725, -0.023051020408163269, -0.024997023809523813,
    -0.026068027210884356, -0.0261390306122449, -0.025085034013605446,
    -0.022781037414965989, -0.019102040816326535, -0.013923044217687079,
    -0.0071190476190476229, 0.001434948979591834, 0.01186394557823129,
    0.024292942176870745, 0.0388469387755102, 0.055650935374149661,
    0.074829931972789115, 0.096508928571428579, 0.12081292517006804,
    0.1478669217687075, 0.17779591836734696, 0.21072491496598642,
    0.24677891156462589, 0.28608290816326537, 0.32876190476190481, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, -0.0, -0.0, -0.0, 0.0045710034013605443, 0.0090170068027210885,
    0.013213010204081634, 0.01703401360544218, 0.020355017006802725,
    0.023051020408163269, 0.024997023809523813, 0.026068027210884356,
    0.0261390306122449, 0.025085034013605446, 0.022781037414965989,
    0.019102040816326535, 0.013923044217687079, 0.0071190476190476229,
    -0.001434948979591834, -0.01186394557823129, -0.024292942176870745,
    -0.0388469387755102, -0.055650935374149661, -0.074829931972789115,
    -0.096508928571428579, -0.12081292517006804, -0.1478669217687075,
    -0.17779591836734696, -0.21072491496598642, -0.24677891156462589,
    -0.28608290816326537, 0.0, 0.0, 0.0, -0.0045710034013605443,
    -0.0090170068027210885, -0.013213010204081634, -0.01703401360544218,
    -0.020355017006802725, -0.023051020408163269, -0.024997023809523813,
    -0.026068027210884356, -0.0261390306122449, -0.025085034013605446,
    -0.022781037414965989, -0.019102040816326535, -0.013923044217687079,
    -0.0071190476190476229, 0.001434948979591834, 0.01186394557823129,
    0.024292942176870745, 0.0388469387755102, 0.055650935374149661,
    0.074829931972789115, 0.096508928571428579, 0.12081292517006804,
    0.1478669217687075, 0.17779591836734696, 0.21072491496598642,
    0.24677891156462589, 0.28608290816326537, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -0.0, -0.0,
    -0.0, -0.0, 0.0045710034013605443, 0.0090170068027210885,
    0.013213010204081634, 0.01703401360544218, 0.020355017006802725,
    0.023051020408163269, 0.024997023809523813, 0.026068027210884356,
    0.0261390306122449, 0.025085034013605446, 0.022781037414965989,
    0.019102040816326535, 0.013923044217687079, 0.0071190476190476229,
    -0.001434948979591834, -0.01186394557823129, -0.024292942176870745,
    -0.0388469387755102, -0.055650935374149661, -0.074829931972789115,
    -0.096508928571428579, -0.12081292517006804, -0.1478669217687075,
    -0.17779591836734696, -0.21072491496598642, -0.24677891156462589, 0.0, 0.0,
    0.0, 0.0, -0.0045710034013605443, -0.0090170068027210885,
    -0.013213010204081634, -0.01703401360544218, -0.020355017006802725,
    -0.023051020408163269, -0.024997023809523813, -0.026068027210884356,
    -0.0261390306122449, -0.025085034013605446, -0.022781037414965989,
    -0.019102040816326535, -0.013923044217687079, -0.0071190476190476229,
    0.001434948979591834, 0.01186394557823129, 0.024292942176870745,
    0.0388469387755102, 0.055650935374149661, 0.074829931972789115,
    0.096508928571428579, 0.12081292517006804, 0.1478669217687075,
    0.17779591836734696, 0.21072491496598642, 0.24677891156462589, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0 };

  static const real_T b_Hinv[121] = { 20.179555551595492, 0.0,
    -24.515725198398165, 0.0, -8.2236650684419068, 0.0, 2.81343214203823, 0.0,
    10.237138546238059, 0.0, 0.0, 0.0, 20.179555551595339, 0.0,
    -24.515725198398332, 0.0, -8.2236650684412265, 0.0, 2.8134321420381623, 0.0,
    10.237138546237752, 0.0, -24.515725198398165, 0.0, 46.49048445631513, 0.0,
    -14.070059446214465, 0.0, -7.3374142448304918, 0.0, -1.2695521427518237, 0.0,
    0.0, 0.0, -24.515725198398332, 0.0, 46.49048445631518, 0.0,
    -14.070059446214316, 0.0, -7.337414244830029, 0.0, -1.2695521427523386, 0.0,
    -8.2236650684419068, 0.0, -14.070059446214465, 0.0, 49.818475112509311, 0.0,
    -15.75935592789803, 0.0, -12.646775941852768, 0.0, 0.0, 0.0,
    -8.2236650684412265, 0.0, -14.070059446214316, 0.0, 49.818475112507862, 0.0,
    -15.759355927899135, 0.0, -12.646775941850946, 0.0, 2.81343214203823, 0.0,
    -7.3374142448304918, 0.0, -15.75935592789803, 0.0, 44.8881385452638, 0.0,
    -24.71137317927678, 0.0, 0.0, 0.0, 2.8134321420381623, 0.0,
    -7.337414244830029, 0.0, -15.759355927899135, 0.0, 44.888138545265022, 0.0,
    -24.71137317927732, 0.0, 10.237138546238059, 0.0, -1.2695521427518237, 0.0,
    -12.646775941852768, 0.0, -24.71137317927678, 0.0, 30.036903111112537, 0.0,
    0.0, 0.0, 10.237138546237752, 0.0, -1.2695521427523386, 0.0,
    -12.646775941850946, 0.0, -24.71137317927732, 0.0, 30.03690311111205, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 9.9999999999999974E-6 };

  static const real_T b_Linv[121] = { 0.1449512816895035, 0.0,
    -2.7610349821442335, 0.0, 1.9763278236864419, 0.0, 2.2672341063851187, 0.0,
    1.8678887400149777, 0.0, 0.0, 0.0, 0.1449512816895035, 0.0,
    -2.7610349821442335, 0.0, 1.9763278236864419, 0.0, 2.2672341063851187, 0.0,
    1.8678887400149369, 0.0, 0.0, 0.0, 3.2012927167070657, 0.0,
    -5.7730188723665794, 0.0, -1.6913908722642317, 0.0, -0.23164501892762346,
    0.0, 0.0, 0.0, 0.0, 0.0, 3.2012927167070657, 0.0, -5.7730188723665794, 0.0,
    -1.6913908722642317, 0.0, -0.2316450189277193, 0.0, 0.0, 0.0, 0.0, 0.0,
    4.076642751455851, 0.0, -5.27964433836411, 0.0, -2.307555990629822, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 4.076642751455851, 0.0, -5.27964433836411, 0.0,
    -2.307555990629508, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 4.9556110767480455,
    0.0, -4.5088864923920937, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    4.9556110767480455, 0.0, -4.5088864923922287, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 5.4805933174349413, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 5.4805933174348969, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.003162277660168379 };

  static const real_T b_Mx[600] = { -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0,
    -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0,
    -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, -0.05, -0.1, -0.15000000000000002, -0.2, -0.25, -0.3, -0.35,
    -0.39999999999999997, -0.44999999999999996, -0.49999999999999994,
    -0.54999999999999993, -0.6, -0.65, -0.70000000000000007,
    -0.75000000000000011, -0.80000000000000016, -0.8500000000000002,
    -0.90000000000000024, -0.95000000000000029, -1.0000000000000002,
    -1.0500000000000003, -1.1000000000000003, -1.1500000000000004,
    -1.2000000000000004, -1.2500000000000004, -1.3000000000000005,
    -1.3500000000000005, -1.4000000000000006, -1.4500000000000006,
    -1.5000000000000007, 0.05, 0.1, 0.15000000000000002, 0.2, 0.25, 0.3, 0.35,
    0.39999999999999997, 0.44999999999999996, 0.49999999999999994,
    0.54999999999999993, 0.6, 0.65, 0.70000000000000007, 0.75000000000000011,
    0.80000000000000016, 0.8500000000000002, 0.90000000000000024,
    0.95000000000000029, 1.0000000000000002, 1.0500000000000003,
    1.1000000000000003, 1.1500000000000004, 1.2000000000000004,
    1.2500000000000004, 1.3000000000000005, 1.3500000000000005,
    1.4000000000000006, 1.4500000000000006, 1.5000000000000007, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.090586734693877555, 0.086836734693877551, 0.080586734693877546,
    0.071836734693877552, 0.060586734693877549, 0.046836734693877544,
    0.030586734693877543, 0.011836734693877544, -0.0094132653061224578,
    -0.033163265306122458, -0.059413265306122454, -0.088163265306122451,
    -0.11941326530612245, -0.15316326530612245, -0.18941326530612246,
    -0.22816326530612246, -0.26941326530612247, -0.31316326530612248,
    -0.3594132653061225, -0.40816326530612251, -0.45941326530612253,
    -0.51316326530612255, -0.56941326530612257, -0.62816326530612265,
    -0.68941326530612268, -0.75316326530612265, -0.81941326530612268,
    -0.88816326530612266, -0.9594132653061227, -1.0331632653061227,
    -0.090586734693877555, -0.086836734693877551, -0.080586734693877546,
    -0.071836734693877552, -0.060586734693877549, -0.046836734693877544,
    -0.030586734693877543, -0.011836734693877544, 0.0094132653061224578,
    0.033163265306122458, 0.059413265306122454, 0.088163265306122451,
    0.11941326530612245, 0.15316326530612245, 0.18941326530612246,
    0.22816326530612246, 0.26941326530612247, 0.31316326530612248,
    0.3594132653061225, 0.40816326530612251, 0.45941326530612253,
    0.51316326530612255, 0.56941326530612257, 0.62816326530612265,
    0.68941326530612268, 0.75316326530612265, 0.81941326530612268,
    0.88816326530612266, 0.9594132653061227, 1.0331632653061227, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -1.0, -1.0, -1.0,
    -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0,
    -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0,
    -1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

  static const real_T b_Mu1[120] = { 0.0045710034013605443,
    0.0090170068027210885, 0.013213010204081634, 0.01703401360544218,
    0.020355017006802725, 0.023051020408163269, 0.024997023809523813,
    0.026068027210884356, 0.0261390306122449, 0.025085034013605446,
    0.022781037414965989, 0.019102040816326535, 0.013923044217687079,
    0.0071190476190476229, -0.001434948979591834, -0.01186394557823129,
    -0.024292942176870745, -0.0388469387755102, -0.055650935374149661,
    -0.074829931972789115, -0.096508928571428579, -0.12081292517006804,
    -0.1478669217687075, -0.17779591836734696, -0.21072491496598642,
    -0.24677891156462589, -0.28608290816326537, -0.32876190476190481,
    -0.37494090136054425, -0.42474489795918374, -0.0045710034013605443,
    -0.0090170068027210885, -0.013213010204081634, -0.01703401360544218,
    -0.020355017006802725, -0.023051020408163269, -0.024997023809523813,
    -0.026068027210884356, -0.0261390306122449, -0.025085034013605446,
    -0.022781037414965989, -0.019102040816326535, -0.013923044217687079,
    -0.0071190476190476229, 0.001434948979591834, 0.01186394557823129,
    0.024292942176870745, 0.0388469387755102, 0.055650935374149661,
    0.074829931972789115, 0.096508928571428579, 0.12081292517006804,
    0.1478669217687075, 0.17779591836734696, 0.21072491496598642,
    0.24677891156462589, 0.28608290816326537, 0.32876190476190481,
    0.37494090136054425, 0.42474489795918374, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

  static const real_T b_Kx[100] = { 158.83093121862345, 0.0, 222.7441357066391,
    0.0, 136.11244904403773, 0.0, 0.0, 0.0, 158.83093121862345, 0.0, 0.0,
    158.83093121862345, 0.0, 222.7441357066391, 0.0, 136.11244904403773, 0.0,
    0.0, 0.0, 158.83093121862345, 130.35948164009028, 0.0, 186.55493542084383,
    0.0, 115.86159064847386, 0.0, 0.0, 0.0, 130.35948164009028, 0.0, 0.0,
    130.35948164009028, 0.0, 186.55493542084383, 0.0, 115.86159064847386, 0.0,
    0.0, 0.0, 130.35948164009028, 105.22648764932467, 0.0, 154.11676881716164,
    0.0, 97.469409841351734, 0.0, 0.0, 0.0, 105.22648764932467, 0.0, 0.0,
    105.22648764932467, 0.0, 154.11676881716164, 0.0, 97.469409841351734, 0.0,
    0.0, 0.0, 105.22648764932467, 83.188958676650373, 0.0, 125.21992329198272,
    0.0, 80.8580544149186, 0.0, 0.0, 0.0, 83.188958676650373, 0.0, 0.0,
    83.188958676650373, 0.0, 125.21992329198272, 0.0, 80.8580544149186, 0.0, 0.0,
    0.0, 83.188958676650373, 64.012283137552387, 0.0, 99.655524140213373, 0.0,
    65.948178550316811, 0.0, 0.0, 0.0, 64.012283137552387, 0.0, 0.0,
    64.012283137552387, 0.0, 99.655524140213373, 0.0, 65.948178550316811, 0.0,
    0.0, 0.0, 64.012283137552387 };

  static const real_T b_Kr[1200] = { 0.30640295737618622, -0.0, -0.0, -0.0,
    0.60442692959112243, -0.0, -0.0, -0.0, 0.88569293148355877, -0.0, -0.0, -0.0,
    1.1418219778922452, -0.0, -0.0, -0.0, 1.3644350836559314, -0.0, -0.0, -0.0,
    1.5451532636133676, -0.0, -0.0, -0.0, 1.6755975326033039, -0.0, -0.0, -0.0,
    1.74738890546449, -0.0, -0.0, -0.0, 1.7521483970356764, -0.0, -0.0, -0.0,
    1.6814970221556125, -0.0, -0.0, -0.0, 1.5270557956630486, -0.0, -0.0, -0.0,
    1.2804457323967351, -0.0, -0.0, -0.0, 0.93328784719542124, -0.0, -0.0, -0.0,
    0.47720315489785742, -0.0, -0.0, -0.0, -0.096187329657206444, -0.0, -0.0,
    -0.0, -0.7952625916310202, -0.0, -0.0, -0.0, -1.628401616184834, -0.0, -0.0,
    -0.0, -2.603983388479898, -0.0, -0.0, -0.0, -3.730386893677462, -0.0, -0.0,
    -0.0, -5.0159911169387756, -0.0, -0.0, -0.0, -6.46917504342509, -0.0, -0.0,
    -0.0, -8.0983176582976544, -0.0, -0.0, -0.0, -9.9117979467177175, -0.0, -0.0,
    -0.0, -11.917994893846531, -0.0, -0.0, -0.0, -14.125287484845346, -0.0, -0.0,
    -0.0, -16.542054704875412, -0.0, -0.0, -0.0, -19.176675539097978, -0.0, -0.0,
    -0.0, -22.037528972674288, -0.0, -0.0, -0.0, -25.132993990765602, -0.0, -0.0,
    -0.0, -28.471449578533168, -0.0, -0.0, -0.0, -0.0, 0.30640295737618622, -0.0,
    -0.0, -0.0, 0.60442692959112243, -0.0, -0.0, -0.0, 0.88569293148355877, -0.0,
    -0.0, -0.0, 1.1418219778922452, -0.0, -0.0, -0.0, 1.3644350836559314, -0.0,
    -0.0, -0.0, 1.5451532636133676, -0.0, -0.0, -0.0, 1.6755975326033039, -0.0,
    -0.0, -0.0, 1.74738890546449, -0.0, -0.0, -0.0, 1.7521483970356764, -0.0,
    -0.0, -0.0, 1.6814970221556125, -0.0, -0.0, -0.0, 1.5270557956630486, -0.0,
    -0.0, -0.0, 1.2804457323967351, -0.0, -0.0, -0.0, 0.93328784719542124, -0.0,
    -0.0, -0.0, 0.47720315489785742, -0.0, -0.0, -0.0, -0.096187329657206444,
    -0.0, -0.0, -0.0, -0.7952625916310202, -0.0, -0.0, -0.0, -1.628401616184834,
    -0.0, -0.0, -0.0, -2.603983388479898, -0.0, -0.0, -0.0, -3.730386893677462,
    -0.0, -0.0, -0.0, -5.0159911169387756, -0.0, -0.0, -0.0, -6.46917504342509,
    -0.0, -0.0, -0.0, -8.0983176582976544, -0.0, -0.0, -0.0, -9.9117979467177175,
    -0.0, -0.0, -0.0, -11.917994893846531, -0.0, -0.0, -0.0, -14.125287484845346,
    -0.0, -0.0, -0.0, -16.542054704875412, -0.0, -0.0, -0.0, -19.176675539097978,
    -0.0, -0.0, -0.0, -22.037528972674288, -0.0, -0.0, -0.0, -25.132993990765602,
    -0.0, -0.0, -0.0, -28.471449578533168, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    0.30640295737618622, -0.0, -0.0, -0.0, 0.60442692959112243, -0.0, -0.0, -0.0,
    0.88569293148355877, -0.0, -0.0, -0.0, 1.1418219778922452, -0.0, -0.0, -0.0,
    1.3644350836559314, -0.0, -0.0, -0.0, 1.5451532636133676, -0.0, -0.0, -0.0,
    1.6755975326033039, -0.0, -0.0, -0.0, 1.74738890546449, -0.0, -0.0, -0.0,
    1.7521483970356764, -0.0, -0.0, -0.0, 1.6814970221556125, -0.0, -0.0, -0.0,
    1.5270557956630486, -0.0, -0.0, -0.0, 1.2804457323967351, -0.0, -0.0, -0.0,
    0.93328784719542124, -0.0, -0.0, -0.0, 0.47720315489785742, -0.0, -0.0, -0.0,
    -0.096187329657206444, -0.0, -0.0, -0.0, -0.7952625916310202, -0.0, -0.0,
    -0.0, -1.628401616184834, -0.0, -0.0, -0.0, -2.603983388479898, -0.0, -0.0,
    -0.0, -3.730386893677462, -0.0, -0.0, -0.0, -5.0159911169387756, -0.0, -0.0,
    -0.0, -6.46917504342509, -0.0, -0.0, -0.0, -8.0983176582976544, -0.0, -0.0,
    -0.0, -9.9117979467177175, -0.0, -0.0, -0.0, -11.917994893846531, -0.0, -0.0,
    -0.0, -14.125287484845346, -0.0, -0.0, -0.0, -16.542054704875412, -0.0, -0.0,
    -0.0, -19.176675539097978, -0.0, -0.0, -0.0, -22.037528972674288, -0.0, -0.0,
    -0.0, -25.132993990765602, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    0.30640295737618622, -0.0, -0.0, -0.0, 0.60442692959112243, -0.0, -0.0, -0.0,
    0.88569293148355877, -0.0, -0.0, -0.0, 1.1418219778922452, -0.0, -0.0, -0.0,
    1.3644350836559314, -0.0, -0.0, -0.0, 1.5451532636133676, -0.0, -0.0, -0.0,
    1.6755975326033039, -0.0, -0.0, -0.0, 1.74738890546449, -0.0, -0.0, -0.0,
    1.7521483970356764, -0.0, -0.0, -0.0, 1.6814970221556125, -0.0, -0.0, -0.0,
    1.5270557956630486, -0.0, -0.0, -0.0, 1.2804457323967351, -0.0, -0.0, -0.0,
    0.93328784719542124, -0.0, -0.0, -0.0, 0.47720315489785742, -0.0, -0.0, -0.0,
    -0.096187329657206444, -0.0, -0.0, -0.0, -0.7952625916310202, -0.0, -0.0,
    -0.0, -1.628401616184834, -0.0, -0.0, -0.0, -2.603983388479898, -0.0, -0.0,
    -0.0, -3.730386893677462, -0.0, -0.0, -0.0, -5.0159911169387756, -0.0, -0.0,
    -0.0, -6.46917504342509, -0.0, -0.0, -0.0, -8.0983176582976544, -0.0, -0.0,
    -0.0, -9.9117979467177175, -0.0, -0.0, -0.0, -11.917994893846531, -0.0, -0.0,
    -0.0, -14.125287484845346, -0.0, -0.0, -0.0, -16.542054704875412, -0.0, -0.0,
    -0.0, -19.176675539097978, -0.0, -0.0, -0.0, -22.037528972674288, -0.0, -0.0,
    -0.0, -25.132993990765602, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, 0.30640295737618622, -0.0, -0.0, -0.0, 0.60442692959112243, -0.0,
    -0.0, -0.0, 0.88569293148355877, -0.0, -0.0, -0.0, 1.1418219778922452, -0.0,
    -0.0, -0.0, 1.3644350836559314, -0.0, -0.0, -0.0, 1.5451532636133676, -0.0,
    -0.0, -0.0, 1.6755975326033039, -0.0, -0.0, -0.0, 1.74738890546449, -0.0,
    -0.0, -0.0, 1.7521483970356764, -0.0, -0.0, -0.0, 1.6814970221556125, -0.0,
    -0.0, -0.0, 1.5270557956630486, -0.0, -0.0, -0.0, 1.2804457323967351, -0.0,
    -0.0, -0.0, 0.93328784719542124, -0.0, -0.0, -0.0, 0.47720315489785742, -0.0,
    -0.0, -0.0, -0.096187329657206444, -0.0, -0.0, -0.0, -0.7952625916310202,
    -0.0, -0.0, -0.0, -1.628401616184834, -0.0, -0.0, -0.0, -2.603983388479898,
    -0.0, -0.0, -0.0, -3.730386893677462, -0.0, -0.0, -0.0, -5.0159911169387756,
    -0.0, -0.0, -0.0, -6.46917504342509, -0.0, -0.0, -0.0, -8.0983176582976544,
    -0.0, -0.0, -0.0, -9.9117979467177175, -0.0, -0.0, -0.0, -11.917994893846531,
    -0.0, -0.0, -0.0, -14.125287484845346, -0.0, -0.0, -0.0, -16.542054704875412,
    -0.0, -0.0, -0.0, -19.176675539097978, -0.0, -0.0, -0.0, -22.037528972674288,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    0.30640295737618622, -0.0, -0.0, -0.0, 0.60442692959112243, -0.0, -0.0, -0.0,
    0.88569293148355877, -0.0, -0.0, -0.0, 1.1418219778922452, -0.0, -0.0, -0.0,
    1.3644350836559314, -0.0, -0.0, -0.0, 1.5451532636133676, -0.0, -0.0, -0.0,
    1.6755975326033039, -0.0, -0.0, -0.0, 1.74738890546449, -0.0, -0.0, -0.0,
    1.7521483970356764, -0.0, -0.0, -0.0, 1.6814970221556125, -0.0, -0.0, -0.0,
    1.5270557956630486, -0.0, -0.0, -0.0, 1.2804457323967351, -0.0, -0.0, -0.0,
    0.93328784719542124, -0.0, -0.0, -0.0, 0.47720315489785742, -0.0, -0.0, -0.0,
    -0.096187329657206444, -0.0, -0.0, -0.0, -0.7952625916310202, -0.0, -0.0,
    -0.0, -1.628401616184834, -0.0, -0.0, -0.0, -2.603983388479898, -0.0, -0.0,
    -0.0, -3.730386893677462, -0.0, -0.0, -0.0, -5.0159911169387756, -0.0, -0.0,
    -0.0, -6.46917504342509, -0.0, -0.0, -0.0, -8.0983176582976544, -0.0, -0.0,
    -0.0, -9.9117979467177175, -0.0, -0.0, -0.0, -11.917994893846531, -0.0, -0.0,
    -0.0, -14.125287484845346, -0.0, -0.0, -0.0, -16.542054704875412, -0.0, -0.0,
    -0.0, -19.176675539097978, -0.0, -0.0, -0.0, -22.037528972674288, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    0.30640295737618622, -0.0, -0.0, -0.0, 0.60442692959112243, -0.0, -0.0, -0.0,
    0.88569293148355877, -0.0, -0.0, -0.0, 1.1418219778922452, -0.0, -0.0, -0.0,
    1.3644350836559314, -0.0, -0.0, -0.0, 1.5451532636133676, -0.0, -0.0, -0.0,
    1.6755975326033039, -0.0, -0.0, -0.0, 1.74738890546449, -0.0, -0.0, -0.0,
    1.7521483970356764, -0.0, -0.0, -0.0, 1.6814970221556125, -0.0, -0.0, -0.0,
    1.5270557956630486, -0.0, -0.0, -0.0, 1.2804457323967351, -0.0, -0.0, -0.0,
    0.93328784719542124, -0.0, -0.0, -0.0, 0.47720315489785742, -0.0, -0.0, -0.0,
    -0.096187329657206444, -0.0, -0.0, -0.0, -0.7952625916310202, -0.0, -0.0,
    -0.0, -1.628401616184834, -0.0, -0.0, -0.0, -2.603983388479898, -0.0, -0.0,
    -0.0, -3.730386893677462, -0.0, -0.0, -0.0, -5.0159911169387756, -0.0, -0.0,
    -0.0, -6.46917504342509, -0.0, -0.0, -0.0, -8.0983176582976544, -0.0, -0.0,
    -0.0, -9.9117979467177175, -0.0, -0.0, -0.0, -11.917994893846531, -0.0, -0.0,
    -0.0, -14.125287484845346, -0.0, -0.0, -0.0, -16.542054704875412, -0.0, -0.0,
    -0.0, -19.176675539097978, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, 0.30640295737618622, -0.0,
    -0.0, -0.0, 0.60442692959112243, -0.0, -0.0, -0.0, 0.88569293148355877, -0.0,
    -0.0, -0.0, 1.1418219778922452, -0.0, -0.0, -0.0, 1.3644350836559314, -0.0,
    -0.0, -0.0, 1.5451532636133676, -0.0, -0.0, -0.0, 1.6755975326033039, -0.0,
    -0.0, -0.0, 1.74738890546449, -0.0, -0.0, -0.0, 1.7521483970356764, -0.0,
    -0.0, -0.0, 1.6814970221556125, -0.0, -0.0, -0.0, 1.5270557956630486, -0.0,
    -0.0, -0.0, 1.2804457323967351, -0.0, -0.0, -0.0, 0.93328784719542124, -0.0,
    -0.0, -0.0, 0.47720315489785742, -0.0, -0.0, -0.0, -0.096187329657206444,
    -0.0, -0.0, -0.0, -0.7952625916310202, -0.0, -0.0, -0.0, -1.628401616184834,
    -0.0, -0.0, -0.0, -2.603983388479898, -0.0, -0.0, -0.0, -3.730386893677462,
    -0.0, -0.0, -0.0, -5.0159911169387756, -0.0, -0.0, -0.0, -6.46917504342509,
    -0.0, -0.0, -0.0, -8.0983176582976544, -0.0, -0.0, -0.0, -9.9117979467177175,
    -0.0, -0.0, -0.0, -11.917994893846531, -0.0, -0.0, -0.0, -14.125287484845346,
    -0.0, -0.0, -0.0, -16.542054704875412, -0.0, -0.0, -0.0, -19.176675539097978,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, 0.30640295737618622, -0.0, -0.0, -0.0,
    0.60442692959112243, -0.0, -0.0, -0.0, 0.88569293148355877, -0.0, -0.0, -0.0,
    1.1418219778922452, -0.0, -0.0, -0.0, 1.3644350836559314, -0.0, -0.0, -0.0,
    1.5451532636133676, -0.0, -0.0, -0.0, 1.6755975326033039, -0.0, -0.0, -0.0,
    1.74738890546449, -0.0, -0.0, -0.0, 1.7521483970356764, -0.0, -0.0, -0.0,
    1.6814970221556125, -0.0, -0.0, -0.0, 1.5270557956630486, -0.0, -0.0, -0.0,
    1.2804457323967351, -0.0, -0.0, -0.0, 0.93328784719542124, -0.0, -0.0, -0.0,
    0.47720315489785742, -0.0, -0.0, -0.0, -0.096187329657206444, -0.0, -0.0,
    -0.0, -0.7952625916310202, -0.0, -0.0, -0.0, -1.628401616184834, -0.0, -0.0,
    -0.0, -2.603983388479898, -0.0, -0.0, -0.0, -3.730386893677462, -0.0, -0.0,
    -0.0, -5.0159911169387756, -0.0, -0.0, -0.0, -6.46917504342509, -0.0, -0.0,
    -0.0, -8.0983176582976544, -0.0, -0.0, -0.0, -9.9117979467177175, -0.0, -0.0,
    -0.0, -11.917994893846531, -0.0, -0.0, -0.0, -14.125287484845346, -0.0, -0.0,
    -0.0, -16.542054704875412, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    0.30640295737618622, -0.0, -0.0, -0.0, 0.60442692959112243, -0.0, -0.0, -0.0,
    0.88569293148355877, -0.0, -0.0, -0.0, 1.1418219778922452, -0.0, -0.0, -0.0,
    1.3644350836559314, -0.0, -0.0, -0.0, 1.5451532636133676, -0.0, -0.0, -0.0,
    1.6755975326033039, -0.0, -0.0, -0.0, 1.74738890546449, -0.0, -0.0, -0.0,
    1.7521483970356764, -0.0, -0.0, -0.0, 1.6814970221556125, -0.0, -0.0, -0.0,
    1.5270557956630486, -0.0, -0.0, -0.0, 1.2804457323967351, -0.0, -0.0, -0.0,
    0.93328784719542124, -0.0, -0.0, -0.0, 0.47720315489785742, -0.0, -0.0, -0.0,
    -0.096187329657206444, -0.0, -0.0, -0.0, -0.7952625916310202, -0.0, -0.0,
    -0.0, -1.628401616184834, -0.0, -0.0, -0.0, -2.603983388479898, -0.0, -0.0,
    -0.0, -3.730386893677462, -0.0, -0.0, -0.0, -5.0159911169387756, -0.0, -0.0,
    -0.0, -6.46917504342509, -0.0, -0.0, -0.0, -8.0983176582976544, -0.0, -0.0,
    -0.0, -9.9117979467177175, -0.0, -0.0, -0.0, -11.917994893846531, -0.0, -0.0,
    -0.0, -14.125287484845346, -0.0, -0.0, -0.0, -16.542054704875412, -0.0, -0.0
  };

  static const real_T b_Ku1[20] = { 47.579484365902751, 0.0, 0.0,
    47.579484365902751, 41.048983105600435, 0.0, 0.0, 41.048983105600435,
    35.056888887122753, 0.0, 0.0, 35.056888887122753, 29.584671812288374, 0.0,
    0.0, 29.584671812288374, 24.613649828810438, 0.0, 0.0, 24.613649828810438 };

  real_T rtb_KalmanSys[10];
  real_T rtb_ymin_scale[4];
  real_T rtb_ymax_scale[4];
  real_T rtb_xk1[10];
  real_T TmpSignalConversionAtKalmanSysI[6];
  real_T rtb_umin_scale1;
  real_T rtb_umin_scale1_idx_0;
  real_T rtb_umin_scale1_idx_1;

  /* Outputs for Atomic SubSystem: '<Root>/MpcController' */
  /* Outputs for Atomic SubSystem: '<S1>/KalmanFilter' */
  /* SignalConversion: '<S2>/TmpSignal ConversionAtKalmanSysInport1' incorporates:
   *  Delay: '<S1>/Delay'
   *  Inport: '<Root>/ymeas'
   */
  TmpSignalConversionAtKalmanSysI[0] = MpcController_DW.Delay_DSTATE[0];
  TmpSignalConversionAtKalmanSysI[1] = MpcController_DW.Delay_DSTATE[1];
  TmpSignalConversionAtKalmanSysI[2] = MpcController_U.ymeas[0];
  TmpSignalConversionAtKalmanSysI[3] = MpcController_U.ymeas[1];
  TmpSignalConversionAtKalmanSysI[4] = MpcController_U.ymeas[2];
  TmpSignalConversionAtKalmanSysI[5] = MpcController_U.ymeas[3];
  for (ix = 0; ix < 10; ix++) {
    /* DiscreteStateSpace: '<S2>/KalmanSys' */
    rtb_KalmanSys[ix] = 0.0;
    for (j = 0; j < 10; j++) {
      rtb_KalmanSys[ix] += MpcController_P.KalmanSys_C[10 * j + ix] *
        MpcController_DW.KalmanSys_DSTATE[j];
    }

    for (j = 0; j < 6; j++) {
      rtb_KalmanSys[ix] += MpcController_P.KalmanSys_D[10 * j + ix] *
        TmpSignalConversionAtKalmanSysI[j];
    }

    /* End of DiscreteStateSpace: '<S2>/KalmanSys' */

    /* Update for DiscreteStateSpace: '<S2>/KalmanSys' */
    rtb_xk1[ix] = 0.0;
    for (j = 0; j < 10; j++) {
      rtb_xk1[ix] += (MpcController_P.A_kal[10 * j + ix] -
                      MpcController_ConstP.KalmanSys_rtw_collapsed_sub_exp[10 *
                      j + ix]) * MpcController_DW.KalmanSys_DSTATE[j];
    }

    for (j = 0; j < 6; j++) {
      rtb_xk1[ix] += MpcController_P.KalmanSys_B[10 * j + ix] *
        TmpSignalConversionAtKalmanSysI[j];
    }
  }

  /* Update for DiscreteStateSpace: '<S2>/KalmanSys' */
  memcpy(&MpcController_DW.KalmanSys_DSTATE[0], &rtb_xk1[0], 10U * sizeof(real_T));

  /* End of Outputs for SubSystem: '<S1>/KalmanFilter' */

  /* Gain: '<S4>/ymin_scale' incorporates:
   *  Inport: '<Root>/ymin'
   */
  rtb_ymin_scale[0] = MpcController_P.ymin_scale_Gain[0] * MpcController_U.ymin
    [0];

  /* Gain: '<S4>/ymax_scale' incorporates:
   *  Inport: '<Root>/ymax'
   */
  rtb_ymax_scale[0] = MpcController_P.ymax_scale_Gain[0] * MpcController_U.ymax
    [0];

  /* Gain: '<S4>/ymin_scale' incorporates:
   *  Inport: '<Root>/ymin'
   */
  rtb_ymin_scale[1] = MpcController_P.ymin_scale_Gain[1] * MpcController_U.ymin
    [1];

  /* Gain: '<S4>/ymax_scale' incorporates:
   *  Inport: '<Root>/ymax'
   */
  rtb_ymax_scale[1] = MpcController_P.ymax_scale_Gain[1] * MpcController_U.ymax
    [1];

  /* Gain: '<S4>/ymin_scale' incorporates:
   *  Inport: '<Root>/ymin'
   */
  rtb_ymin_scale[2] = MpcController_P.ymin_scale_Gain[2] * MpcController_U.ymin
    [2];

  /* Gain: '<S4>/ymax_scale' incorporates:
   *  Inport: '<Root>/ymax'
   */
  rtb_ymax_scale[2] = MpcController_P.ymax_scale_Gain[2] * MpcController_U.ymax
    [2];

  /* Gain: '<S4>/ymin_scale' incorporates:
   *  Inport: '<Root>/ymin'
   */
  rtb_ymin_scale[3] = MpcController_P.ymin_scale_Gain[3] * MpcController_U.ymin
    [3];

  /* Gain: '<S4>/ymax_scale' incorporates:
   *  Inport: '<Root>/ymax'
   */
  rtb_ymax_scale[3] = MpcController_P.ymax_scale_Gain[3] * MpcController_U.ymax
    [3];

  /* MATLAB Function: '<S4>/optimizer' incorporates:
   *  Inport: '<Root>/ref'
   *  Memory: '<S4>/Memory'
   *  UnitDelay: '<S4>/last_mv'
   */
  memset(&rseq[0], 0, 120U * sizeof(real_T));
  for (ix = 0; ix < 30; ix++) {
    j = ix * (int32_T)MpcController_ny;
    rseq[j] = MpcController_U.ref[0];
    rseq[1 + j] = MpcController_U.ref[1];
    rseq[2 + j] = MpcController_U.ref[2];
    rseq[3 + j] = MpcController_U.ref[3];
  }

  rtb_umin_scale1_idx_0 = MpcController_DW.last_mv_DSTATE[0];
  rtb_umin_scale1_idx_1 = MpcController_DW.last_mv_DSTATE[1];
  memcpy(&rtb_xk1[0], &rtb_KalmanSys[0], 10U * sizeof(real_T));
  ymax_incr[0] = (rtNaN);
  ymin_incr[0] = (rtNaN);
  ymax_incr[1] = (rtNaN);
  ymin_incr[1] = (rtNaN);
  ymax_incr[2] = (rtNaN);
  ymin_incr[2] = (rtNaN);
  ymax_incr[3] = (rtNaN);
  ymin_incr[3] = (rtNaN);
  for (j = 0; j < 60; j++) {
    rtb_umin_scale1 = 0.0;
    for (ix = 0; ix < 10; ix++) {
      rtb_umin_scale1 += b_Mx[60 * ix + j] * rtb_xk1[ix];
    }

    ix = (j << 2) + 1;
    if (ix <= 120) {
      ii = MpcController_mod((real_T)ix - 1.0) + 1.0;
      if (rtIsNaN(ymax_incr[(int32_T)ii - 1])) {
        DelBound = -rtb_ymax_scale[(int32_T)ii - 1] - -1.5;
      } else {
        DelBound = ymax_incr[(int32_T)ii - 1];
      }

      ymax_incr[(int32_T)ii - 1] = DelBound;
    } else {
      ii = MpcController_mod(((real_T)ix - 120.0) - 1.0) + 1.0;
      if (rtIsNaN(ymin_incr[(int32_T)ii - 1])) {
        DelBound = rtb_ymin_scale[(int32_T)ii - 1] - -1.5;
      } else {
        DelBound = ymin_incr[(int32_T)ii - 1];
      }

      ymin_incr[(int32_T)ii - 1] = DelBound;
    }

    Bc[j] = -((1.5 + rtb_umin_scale1) + (b_Mu1[j + 60] * rtb_umin_scale1_idx_1 +
               b_Mu1[j] * rtb_umin_scale1_idx_0)) + DelBound;
  }

  memset(&f[0], 0, 11U * sizeof(real_T));
  for (j = 0; j < 10; j++) {
    rtb_umin_scale1 = 0.0;
    for (ix = 0; ix < 10; ix++) {
      rtb_umin_scale1 += b_Kx[10 * j + ix] * rtb_xk1[ix];
    }

    ii = 0.0;
    for (ix = 0; ix < 120; ix++) {
      ii += b_Kr[120 * j + ix] * rseq[ix];
    }

    f[j] = (b_Ku1[(j << 1) + 1] * rtb_umin_scale1_idx_1 + b_Ku1[j << 1] *
            rtb_umin_scale1_idx_0) + (rtb_umin_scale1 + ii);
  }

  for (ix = 0; ix < 60; ix++) {
    iAnew[ix] = MpcController_DW.Memory_PreviousInput[ix];
  }

  MpcController_qpkwik(b_Linv, b_Hinv, f, b_Ac, Bc, iAnew, 284, 1.0E-6, zopt,
                       unusedU0, &ii);
  if ((ii < 0.0) || (ii == 0.0)) {
    memset(&zopt[0], 0, 11U * sizeof(real_T));
  }

  rtb_umin_scale1_idx_1 = MpcController_DW.last_mv_DSTATE[0] + zopt[0];

  /* Gain: '<S4>/umin_scale1' */
  rtb_umin_scale1 = MpcController_P.umin_scale1_Gain[0] * rtb_umin_scale1_idx_1;

  /* Update for Delay: '<S1>/Delay' */
  MpcController_DW.Delay_DSTATE[0] = rtb_umin_scale1;

  /* Gain: '<S4>/umin_scale1' */
  rtb_umin_scale1_idx_0 = rtb_umin_scale1;

  /* MATLAB Function: '<S4>/optimizer' incorporates:
   *  UnitDelay: '<S4>/last_mv'
   */
  ii = rtb_umin_scale1_idx_1;
  rtb_umin_scale1_idx_1 = MpcController_DW.last_mv_DSTATE[1] + zopt[1];

  /* Gain: '<S4>/umin_scale1' */
  rtb_umin_scale1 = MpcController_P.umin_scale1_Gain[1] * rtb_umin_scale1_idx_1;

  /* Update for Delay: '<S1>/Delay' */
  MpcController_DW.Delay_DSTATE[1] = rtb_umin_scale1;

  /* Update for Memory: '<S4>/Memory' incorporates:
   *  MATLAB Function: '<S4>/optimizer'
   */
  for (ix = 0; ix < 60; ix++) {
    MpcController_DW.Memory_PreviousInput[ix] = (iAnew[ix] != 0);
  }

  /* End of Update for Memory: '<S4>/Memory' */

  /* Update for UnitDelay: '<S4>/last_mv' */
  MpcController_DW.last_mv_DSTATE[0] = ii;

  /* End of Outputs for SubSystem: '<Root>/MpcController' */

  /* Outport: '<Root>/mv' */
  MpcController_Y.mv[0] = rtb_umin_scale1_idx_0;

  /* Outputs for Atomic SubSystem: '<Root>/MpcController' */
  /* Update for UnitDelay: '<S4>/last_mv' */
  MpcController_DW.last_mv_DSTATE[1] = rtb_umin_scale1_idx_1;

  /* End of Outputs for SubSystem: '<Root>/MpcController' */

  /* Outport: '<Root>/mv' */
  MpcController_Y.mv[1] = rtb_umin_scale1;

  /* Outport: '<Root>/x_est' */
  memcpy(&MpcController_Y.x_est[0], &rtb_KalmanSys[0], sizeof(real_T) << 3U);

  /* Outport: '<Root>/dist' */
  MpcController_Y.dist[0] = rtb_KalmanSys[8];
  MpcController_Y.dist[1] = rtb_KalmanSys[9];
}

/* Model initialize function */
void MpcControllerModelClass::initialize()
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize error status */
  rtmSetErrorStatus(getRTM(), (NULL));

  /* states (dwork) */
  (void) memset((void *)&MpcController_DW, 0,
                sizeof(DW_MpcController_T));

  /* external inputs */
  (void)memset((void *)&MpcController_U, 0, sizeof(ExtU_MpcController_T));

  /* external outputs */
  (void) memset((void *)&MpcController_Y, 0,
                sizeof(ExtY_MpcController_T));

  {
    int32_T i;

    /* SystemInitialize for Atomic SubSystem: '<Root>/MpcController' */
    /* InitializeConditions for Delay: '<S1>/Delay' */
    MpcController_DW.Delay_DSTATE[0] = MpcController_P.Delay_InitialCondition;
    MpcController_DW.Delay_DSTATE[1] = MpcController_P.Delay_InitialCondition;

    /* InitializeConditions for Memory: '<S4>/Memory' */
    for (i = 0; i < 60; i++) {
      MpcController_DW.Memory_PreviousInput[i] =
        MpcController_P.Memory_InitialCondition[i];
    }

    /* End of InitializeConditions for Memory: '<S4>/Memory' */

    /* InitializeConditions for UnitDelay: '<S4>/last_mv' */
    MpcController_DW.last_mv_DSTATE[0] =
      MpcController_P.last_mv_InitialCondition[0];
    MpcController_DW.last_mv_DSTATE[1] =
      MpcController_P.last_mv_InitialCondition[1];

    /* SystemInitialize for Atomic SubSystem: '<S1>/KalmanFilter' */
    /* InitializeConditions for DiscreteStateSpace: '<S2>/KalmanSys' */
    for (i = 0; i < 10; i++) {
      MpcController_DW.KalmanSys_DSTATE[i] =
        MpcController_P.KalmanSys_InitialCondition;
    }

    /* End of InitializeConditions for DiscreteStateSpace: '<S2>/KalmanSys' */
    /* End of SystemInitialize for SubSystem: '<S1>/KalmanFilter' */
    /* End of SystemInitialize for SubSystem: '<Root>/MpcController' */
  }
}

/* Model terminate function */
void MpcControllerModelClass::terminate()
{
  /* (no terminate code required) */
}

/* Constructor */
MpcControllerModelClass::MpcControllerModelClass()
{
  static const P_MpcController_T MpcController_P_temp = {
    { 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.001, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.001, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 5.0E-7, 0.0,
      0.001, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 5.0E-7, 0.0, 0.001, 0.0,
      1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 1.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 1.0
    },

    { 1.6666666666666663E-10, 0.0, 5.0E-7, 0.0, 0.001, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 1.6666666666666666E-10, 0.0, 5.0E-7, 0.0, 0.001, 0.0, 0.0, 0.0, 0.0,
      3.8604776034879137E-5, 0.0, 5.7650590025902734E-5, 0.0,
      3.6401206445445794E-5, 0.0, 0.04874292331640824, 0.0, 0.04874292331640824,
      0.0, 0.0, 3.8604776031040662E-5, 0.0, 5.7650590022199621E-5, 0.0,
      3.6401206443691392E-5, 0.0, 0.048742923316409247, 0.0,
      0.048742923316409247, 0.0019989227269908492, 0.0, 0.0019976297159074088,
      0.0, 0.00099830351785861458, 0.0, -0.0018666975174677065, 0.0,
      -0.0018666975174677065, 0.0, 0.0, 0.0019989227269927622, 0.0,
      0.0019976297159120973, 0.0, 0.00099830351786252725, 0.0,
      -0.0018666975174730831, 0.0, -0.0018666975174730831 },

    { 0.99796452725992779, 0.0, -0.0020542456012090072, 0.0,
      -0.0010347047243040603, 0.0, -0.046876225798940525, 0.0,
      -0.046876225798940525, 0.0, 0.0, 0.99796452725992979, 0.0,
      -0.0020542456012099912, 0.0, -0.0010347047243062187, 0.0,
      -0.046876225798936161, 0.0, -0.046876225798936161, 0.0, 0.0, 1.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      3.5400438041745719E-6, 0.0, 5.2910989732154653E-6, 0.0, 1.0000033429679389,
      0.0, 0.0044763909168130007, 0.0, 0.0044763909168130016, 0.0, 0.0,
      3.5400438038223997E-6, 0.0, 5.2910989728755451E-6, 0.0, 1.0000033429679387,
      0.0, 0.0044763909168130936, 0.0, 0.0044763909168130944,
      -3.8547143645456446E-5, 0.0, -5.761418881945729E-5, 0.0,
      -3.640120644544578E-5, 0.0, 0.95125707668359172, 0.0,
      -0.048742923316408233, 0.0, 0.0, -3.8547143641621684E-5, 0.0,
      -5.7614188815755932E-5, 0.0, -3.6401206443691385E-5, 0.0,
      0.95125707668359072, 0.0, -0.048742923316409247, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0
    },

    { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 3.8547143645456446E-5, 0.0, 5.761418881945729E-5,
      0.0, 3.640120644544578E-5, 0.0, 0.048742923316408227, 0.0,
      0.048742923316408233, 0.0, 0.0, 3.8547143641621684E-5, 0.0,
      5.7614188815755932E-5, 0.0, 3.6401206443691385E-5, 0.0,
      0.04874292331640924, 0.0, 0.048742923316409247, 0.0019969255964267007, 0.0,
      0.00199663141238955, 0.0, 0.00099830351785861458, 0.0,
      -0.0018666975174676981, 0.0, -0.0018666975174677063, 0.0, 0.0,
      0.0019969255964286088, 0.0, 0.0019966314123942351, 0.0,
      0.00099830351786252725, 0.0, -0.0018666975174730818, 0.0,
      -0.0018666975174730835 },
    0.0,
    0.0,

    { 0.0, 0.0 },

    { 0.0, 0.0, 0.0, 0.0 },
    0.0,

    { 0.0, 0.0 },

    { 1.0, 1.0 },

    { 0.0, 0.0 },

    { 1.0, 1.0 },

    { 0.0, 0.0 },

    { 0.0, 0.0, 0.0, 0.0 },
    0.0,

    { 1.0, 1.0 },

    { 1.0, 1.0 },

    { 1.0, 1.0, 1.0, 1.0 },

    { 1.0, 1.0, 1.0, 1.0 },

    { 1.0, 1.0 },

    { 1.0, 1.0, 1.0, 1.0 },
    0.0,
    1.0,
    0.0,

    { 0.0, 0.0, 0.0, 0.0 },

    { 0.0, 0.0 },

    { 0.0, 0.0 },
    0.0,

    { 1.0, 1.0 },
    1U,

    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
  };                                   /* Modifiable parameters */

  /* Initialize tunable parameters */
  MpcController_P = MpcController_P_temp;
}

/* Destructor */
MpcControllerModelClass::~MpcControllerModelClass()
{
  /* Currently there is no destructor body generated.*/
}

/* Real-Time Model get method */
RT_MODEL_MpcController_T * MpcControllerModelClass::getRTM()
{
  return (&MpcController_M);
}
