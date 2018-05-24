/*
 * MpcController.h
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

#ifndef RTW_HEADER_MpcController_h_
#define RTW_HEADER_MpcController_h_
#include <cmath>
#include <string.h>
#include <stddef.h>
#ifndef MpcController_COMMON_INCLUDES_
# define MpcController_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* MpcController_COMMON_INCLUDES_ */

#include "MpcController_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T Delay_DSTATE[2];              /* '<S1>/Delay' */
  real_T last_mv_DSTATE[2];            /* '<S4>/last_mv' */
  real_T KalmanSys_DSTATE[10];         /* '<S2>/KalmanSys' */
  boolean_T Memory_PreviousInput[60];  /* '<S4>/Memory' */
} DW_MpcController_T;

/* Constant parameters (auto storage) */
typedef struct {
  /* Expression: A_kal-L_kal*Cm_kal
   * Referenced by: '<S2>/KalmanSys'
   */
  real_T KalmanSys_rtw_collapsed_sub_exp[100];
} ConstP_MpcController_T;

/* External inputs (root inport signals with auto storage) */
typedef struct {
  real_T ref[4];                       /* '<Root>/ref' */
  real_T umin[2];                      /* '<Root>/umin' */
  real_T umax[2];                      /* '<Root>/umax' */
  real_T ymin[4];                      /* '<Root>/ymin' */
  real_T ymax[4];                      /* '<Root>/ymax' */
  real_T ymeas[4];                     /* '<Root>/ymeas' */
} ExtU_MpcController_T;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  real_T mv[2];                        /* '<Root>/mv' */
  real_T x_est[8];                     /* '<Root>/x_est' */
  real_T dist[2];                      /* '<Root>/dist' */
} ExtY_MpcController_T;

/* Parameters (auto storage) */
struct P_MpcController_T_ {
  real_T A_kal[100];                   /* Variable: A_kal
                                        * Referenced by: '<S2>/KalmanSys'
                                        */
  real_T KalmanSys_B[60];              /* Expression: [Bu_kal L_kal]
                                        * Referenced by: '<S2>/KalmanSys'
                                        */
  real_T KalmanSys_C[100];             /* Expression: eye(10) - M_kal*Cm_kal
                                        * Referenced by: '<S2>/KalmanSys'
                                        */
  real_T KalmanSys_D[60];              /* Expression: [zeros(10,2) M_kal]
                                        * Referenced by: '<S2>/KalmanSys'
                                        */
  real_T KalmanSys_InitialCondition;   /* Expression: 0
                                        * Referenced by: '<S2>/KalmanSys'
                                        */
  real_T Delay_InitialCondition;       /* Expression: 0.0
                                        * Referenced by: '<S1>/Delay'
                                        */
  real_T E_zero_Value[2];              /* Expression: zeros(1,2)
                                        * Referenced by: '<S3>/E_zero'
                                        */
  real_T F_zero_Value[4];              /* Expression: zeros(1,4)
                                        * Referenced by: '<S3>/F_zero'
                                        */
  real_T G_zero_Value;                 /* Expression: zeros(1,1)
                                        * Referenced by: '<S3>/G_zero'
                                        */
  real_T extmv_zero_Value[2];          /* Expression: zeros(2,1)
                                        * Referenced by: '<S3>/ext.mv_zero'
                                        */
  real_T extmv_scale_Gain[2];          /* Expression: RMVscale
                                        * Referenced by: '<S4>/ext.mv_scale'
                                        */
  real_T mvtarget_zero_Value[2];       /* Expression: zeros(2,1)
                                        * Referenced by: '<S3>/mv.target_zero'
                                        */
  real_T extmv_scale1_Gain[2];         /* Expression: RMVscale
                                        * Referenced by: '<S4>/ext.mv_scale1'
                                        */
  real_T last_mv_InitialCondition[2];  /* Expression: lastu+uoff
                                        * Referenced by: '<S4>/last_mv'
                                        */
  real_T ym_zero_Value[4];             /* Expression: zeros(nym,1)
                                        * Referenced by: '<S4>/ym_zero'
                                        */
  real_T md_zero_Value;                /* Expression: zeros(1,1)
                                        * Referenced by: '<S3>/md_zero'
                                        */
  real_T umin_scale_Gain[2];           /* Expression: RMVscale
                                        * Referenced by: '<S4>/umin_scale'
                                        */
  real_T umax_scale_Gain[2];           /* Expression: RMVscale
                                        * Referenced by: '<S4>/umax_scale'
                                        */
  real_T ymin_scale_Gain[4];           /* Expression: RYscale
                                        * Referenced by: '<S4>/ymin_scale'
                                        */
  real_T ymax_scale_Gain[4];           /* Expression: RYscale
                                        * Referenced by: '<S4>/ymax_scale'
                                        */
  real_T umin_scale4_Gain[2];          /* Expression: MVscale(:,ones(1,max(nCC,1)))'
                                        * Referenced by: '<S4>/umin_scale4'
                                        */
  real_T ymin_scale1_Gain[4];          /* Expression: Yscale(:,ones(1,max(nCC,1)))'
                                        * Referenced by: '<S4>/ymin_scale1'
                                        */
  real_T S_zero_Value;                 /* Expression: zeros(1,1)
                                        * Referenced by: '<S3>/S_zero'
                                        */
  real_T ymin_scale2_Gain;             /* Expression: MDscale(:,ones(1,max(nCC,1)))'
                                        * Referenced by: '<S4>/ymin_scale2'
                                        */
  real_T switch_zero_Value;            /* Expression: zeros(1,1)
                                        * Referenced by: '<S3>/switch_zero'
                                        */
  real_T ywt_zero_Value[4];            /* Expression: zeros(4,1)
                                        * Referenced by: '<S3>/y.wt_zero'
                                        */
  real_T uwt_zero_Value[2];            /* Expression: zeros(2,1)
                                        * Referenced by: '<S3>/u.wt_zero'
                                        */
  real_T duwt_zero_Value[2];           /* Expression: zeros(2,1)
                                        * Referenced by: '<S3>/du.wt_zero'
                                        */
  real_T ecrwt_zero_Value;             /* Expression: zeros(1,1)
                                        * Referenced by: '<S3>/ecr.wt_zero'
                                        */
  real_T umin_scale1_Gain[2];          /* Expression: MVscale
                                        * Referenced by: '<S4>/umin_scale1'
                                        */
  uint32_T Delay_DelayLength;          /* Computed Parameter: Delay_DelayLength
                                        * Referenced by: '<S1>/Delay'
                                        */
  boolean_T Memory_InitialCondition[60];/* Expression: iA
                                         * Referenced by: '<S4>/Memory'
                                         */
};

/* Real-time Model Data Structure */
struct tag_RTM_MpcController_T {
  const char_T *errorStatus;
};

/* Constant parameters (auto storage) */
extern const ConstP_MpcController_T MpcController_ConstP;

/* Class declaration for model MpcController */
class MpcControllerModelClass {
  /* public data and function members */
 public:
  /* External inputs */
  ExtU_MpcController_T MpcController_U;

  /* External outputs */
  ExtY_MpcController_T MpcController_Y;

  /* model initialize function */
  void initialize();

  /* model step function */
  void step();

  /* model terminate function */
  void terminate();

  /* Constructor */
  MpcControllerModelClass();

  /* Destructor */
  ~MpcControllerModelClass();

  /* Real-Time Model get method */
  RT_MODEL_MpcController_T * getRTM();

  /* private data and function members */
 private:
  /* Tunable parameters */
  P_MpcController_T MpcController_P;

  /* Block states */
  DW_MpcController_T MpcController_DW;

  /* Real-Time Model */
  RT_MODEL_MpcController_T MpcController_M;

  /* private member function(s) for subsystem '<Root>'*/
  real_T MpcController_mod(real_T x);
  void MpcController_Unconstrained(const real_T b_Hinv[121], const real_T f[11],
    real_T x[11], int16_T n);
  real_T MpcController_norm(const real_T x[11]);
  void MpcController_abs(const real_T x[11], real_T y[11]);
  void MpcController_abs_e(const real_T x[60], real_T y[60]);
  real_T MpcController_xnrm2(int32_T n, const real_T x[121], int32_T ix0);
  void MpcController_xgemv(int32_T m, int32_T n, const real_T b_A[121], int32_T
    ia0, const real_T x[121], int32_T ix0, real_T y[11]);
  void MpcController_xger(int32_T m, int32_T n, real_T alpha1, int32_T ix0,
    const real_T y[11], real_T b_A[121], int32_T ia0);
  void MpcController_xgeqrf(real_T b_A[121], real_T tau[11]);
  void MpcController_qr(const real_T b_A[121], real_T Q[121], real_T R[121]);
  real_T MpcController_KWIKfactor(const real_T b_Ac[660], const int16_T iC[60],
    int16_T nA, const real_T b_Linv[121], real_T RLinv[121], real_T D[121],
    real_T b_H[121], int16_T n);
  void MpcController_DropConstraint(int16_T kDrop, int16_T iA[60], int16_T *nA,
    int16_T iC[60]);
  void MpcController_qpkwik(const real_T b_Linv[121], const real_T b_Hinv[121],
    const real_T f[11], const real_T b_Ac[660], const real_T b[60], int16_T iA
    [60], int16_T b_maxiter, real_T FeasTol, real_T x[11], real_T lambda[60],
    real_T *status);
};

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Note that this particular code originates from a subsystem build,
 * and has its own system numbers different from the parent model.
 * Refer to the system hierarchy for this subsystem below, and use the
 * MATLAB hilite_system command to trace the generated code back
 * to the parent model.  For example,
 *
 * hilite_system('kalman/MpcController')    - opens subsystem kalman/MpcController
 * hilite_system('kalman/MpcController/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'kalman'
 * '<S1>'   : 'kalman/MpcController'
 * '<S2>'   : 'kalman/MpcController/KalmanFilter'
 * '<S3>'   : 'kalman/MpcController/MPC Controller1'
 * '<S4>'   : 'kalman/MpcController/MPC Controller1/MPC'
 * '<S5>'   : 'kalman/MpcController/MPC Controller1/MPC/MPC Matrix Signal Check'
 * '<S6>'   : 'kalman/MpcController/MPC Controller1/MPC/MPC Matrix Signal Check1'
 * '<S7>'   : 'kalman/MpcController/MPC Controller1/MPC/MPC Matrix Signal Check2'
 * '<S8>'   : 'kalman/MpcController/MPC Controller1/MPC/MPC Preview Signal Check'
 * '<S9>'   : 'kalman/MpcController/MPC Controller1/MPC/MPC Preview Signal Check1'
 * '<S10>'  : 'kalman/MpcController/MPC Controller1/MPC/MPC Scalar Signal Check'
 * '<S11>'  : 'kalman/MpcController/MPC Controller1/MPC/MPC Scalar Signal Check1'
 * '<S12>'  : 'kalman/MpcController/MPC Controller1/MPC/MPC Vector Signal Check'
 * '<S13>'  : 'kalman/MpcController/MPC Controller1/MPC/MPC Vector Signal Check1'
 * '<S14>'  : 'kalman/MpcController/MPC Controller1/MPC/MPC Vector Signal Check11'
 * '<S15>'  : 'kalman/MpcController/MPC Controller1/MPC/MPC Vector Signal Check2'
 * '<S16>'  : 'kalman/MpcController/MPC Controller1/MPC/MPC Vector Signal Check3'
 * '<S17>'  : 'kalman/MpcController/MPC Controller1/MPC/MPC Vector Signal Check4'
 * '<S18>'  : 'kalman/MpcController/MPC Controller1/MPC/MPC Vector Signal Check5'
 * '<S19>'  : 'kalman/MpcController/MPC Controller1/MPC/MPC Vector Signal Check6'
 * '<S20>'  : 'kalman/MpcController/MPC Controller1/MPC/MPC Vector Signal Check7'
 * '<S21>'  : 'kalman/MpcController/MPC Controller1/MPC/MPC Vector Signal Check8'
 * '<S22>'  : 'kalman/MpcController/MPC Controller1/MPC/MPC Vector Signal Check9'
 * '<S23>'  : 'kalman/MpcController/MPC Controller1/MPC/optimizer'
 */
#endif                                 /* RTW_HEADER_MpcController_h_ */
