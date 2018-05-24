/*
 * MpcController_data.cpp
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

/* Constant parameters (auto storage) */
const ConstP_MpcController_T MpcController_ConstP = {
  /* Expression: A_kal-L_kal*Cm_kal
   * Referenced by: '<S2>/KalmanSys'
   */
  { 0.0020375275030257282, 0.0, 0.0020552803059333117, 0.0,
    0.0010347047243040603, 0.0, 0.046876225798940532, 0.0, 0.046876225798940532,
    0.0, 0.0, 0.0020375275030238026, 0.0, 0.002055280305934297, 0.0,
    0.0010347047243062187, 0.0, 0.046876225798936161, 0.0, 0.046876225798936161,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, -3.5453365746317579E-6, 0.0, -5.2944419411543329E-6,
    0.0, -3.342967938867471E-6, 0.0, -0.0044763909168130016, 0.0,
    -0.0044763909168130016, 0.0, 0.0, -3.5453365742792448E-6, 0.0,
    -5.2944419408142508E-6, 0.0, -3.3429679387063526E-6, 0.0,
    -0.0044763909168130944, 0.0, -0.0044763909168130944, 3.8604776034879137E-5,
    0.0, 5.7650590025902734E-5, 0.0, 3.6401206445445794E-5, 0.0,
    0.04874292331640824, 0.0, 0.04874292331640824, 0.0, 0.0,
    3.8604776031040662E-5, 0.0, 5.7650590022199621E-5, 0.0,
    3.6401206443691392E-5, 0.0, 0.048742923316409247, 0.0, 0.048742923316409247,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0 }
};
