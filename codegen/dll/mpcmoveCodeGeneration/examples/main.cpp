//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: main.cpp
//
// MATLAB Coder version            : 3.4
// C/C++ source code generated on  : 22-May-2018 17:53:16
//

//***********************************************************************
// This automatically generated example C main file shows how to call
// entry-point functions that MATLAB Coder generated. You must customize
// this file for your application. Do not modify this file directly.
// Instead, make a copy of this file, modify it, and integrate it into
// your development environment.
//
// This file initializes entry-point function arguments to a default
// size and value before calling the entry-point functions. It does
// not store or use any values returned from the entry-point functions.
// If necessary, it does pre-allocate memory for returned values.
// You can use this file as a starting point for a main function that
// you can deploy in your application.
//
// After you copy the file, and before you deploy it, you must make the
// following changes:
// * For variable-size function arguments, change the example sizes to
// the sizes that your application requires.
// * Change the example values of function arguments to the values that
// your application requires.
// * If the entry-point functions return values, store these values or
// otherwise use them as required by your application.
//
//***********************************************************************
// Include Files
#include "rt_nonfinite.h"
#include "mpcmoveCodeGeneration.h"
#include "main.h"
#include "mpcmoveCodeGeneration_terminate.h"
#include "mpcmoveCodeGeneration_initialize.h"

// Function Declarations
static void argInit_10x10_real_T(double result[100]);
static void argInit_1x4_real_T(double result[4]);
static void argInit_2x1_real_T(double result[2]);
static void argInit_4x1_real_T(double result[4]);
static void argInit_60x1_boolean_T(boolean_T result[60]);
static void argInit_8x1_real_T(double result[8]);
static boolean_T argInit_boolean_T();
static double argInit_real_T();
static void argInit_struct1_T(struct1_T *result);
static struct2_T argInit_struct2_T();
static struct3_T argInit_struct3_T();
static void main_mpcmoveCodeGeneration();

// Function Definitions

//
// Arguments    : double result[100]
// Return Type  : void
//
static void argInit_10x10_real_T(double result[100])
{
  int idx0;
  int idx1;

  // Loop over the array to initialize each element.
  for (idx0 = 0; idx0 < 10; idx0++) {
    for (idx1 = 0; idx1 < 10; idx1++) {
      // Set the value of the array element.
      // Change this value to the value that the application requires.
      result[idx0 + 10 * idx1] = argInit_real_T();
    }
  }
}

//
// Arguments    : double result[4]
// Return Type  : void
//
static void argInit_1x4_real_T(double result[4])
{
  int idx1;

  // Loop over the array to initialize each element.
  for (idx1 = 0; idx1 < 4; idx1++) {
    // Set the value of the array element.
    // Change this value to the value that the application requires.
    result[idx1] = argInit_real_T();
  }
}

//
// Arguments    : double result[2]
// Return Type  : void
//
static void argInit_2x1_real_T(double result[2])
{
  int idx0;

  // Loop over the array to initialize each element.
  for (idx0 = 0; idx0 < 2; idx0++) {
    // Set the value of the array element.
    // Change this value to the value that the application requires.
    result[idx0] = argInit_real_T();
  }
}

//
// Arguments    : double result[4]
// Return Type  : void
//
static void argInit_4x1_real_T(double result[4])
{
  int idx0;

  // Loop over the array to initialize each element.
  for (idx0 = 0; idx0 < 4; idx0++) {
    // Set the value of the array element.
    // Change this value to the value that the application requires.
    result[idx0] = argInit_real_T();
  }
}

//
// Arguments    : boolean_T result[60]
// Return Type  : void
//
static void argInit_60x1_boolean_T(boolean_T result[60])
{
  int idx0;

  // Loop over the array to initialize each element.
  for (idx0 = 0; idx0 < 60; idx0++) {
    // Set the value of the array element.
    // Change this value to the value that the application requires.
    result[idx0] = argInit_boolean_T();
  }
}

//
// Arguments    : double result[8]
// Return Type  : void
//
static void argInit_8x1_real_T(double result[8])
{
  int idx0;

  // Loop over the array to initialize each element.
  for (idx0 = 0; idx0 < 8; idx0++) {
    // Set the value of the array element.
    // Change this value to the value that the application requires.
    result[idx0] = argInit_real_T();
  }
}

//
// Arguments    : void
// Return Type  : boolean_T
//
static boolean_T argInit_boolean_T()
{
  return false;
}

//
// Arguments    : void
// Return Type  : double
//
static double argInit_real_T()
{
  return 0.0;
}

//
// Arguments    : struct1_T *result
// Return Type  : void
//
static void argInit_struct1_T(struct1_T *result)
{
  // Set the value of each structure field.
  // Change this value to the value that the application requires.
  argInit_8x1_real_T(result->Plant);
  argInit_2x1_real_T(result->Disturbance);
  argInit_2x1_real_T(result->LastMove);
  argInit_10x10_real_T(result->Covariance);
  argInit_60x1_boolean_T(result->iA);
}

//
// Arguments    : void
// Return Type  : struct2_T
//
static struct2_T argInit_struct2_T()
{
  struct2_T result;

  // Set the value of each structure field.
  // Change this value to the value that the application requires.
  result.signals = argInit_struct3_T();
  return result;
}

//
// Arguments    : void
// Return Type  : struct3_T
//
static struct3_T argInit_struct3_T()
{
  struct3_T result;

  // Set the value of each structure field.
  // Change this value to the value that the application requires.
  argInit_4x1_real_T(result.ym);
  argInit_1x4_real_T(result.ref);
  return result;
}

//
// Arguments    : void
// Return Type  : void
//
static void main_mpcmoveCodeGeneration()
{
  struct1_T mpcmovestate;
  struct2_T r0;
  double u[2];
  struct7_T Info;

  // Initialize function 'mpcmoveCodeGeneration' input arguments.
  // Initialize function input argument 'mpcmovestate'.
  // Initialize function input argument 'mpcmovedata'.
  // Call the entry-point 'mpcmoveCodeGeneration'.
  argInit_struct1_T(&mpcmovestate);
  r0 = argInit_struct2_T();
  mpcmoveCodeGeneration(&mpcmovestate, &r0, u, &Info);
}

//
// Arguments    : int argc
//                const char * const argv[]
// Return Type  : int
//
int main(int, const char * const [])
{
  // Initialize the application.
  // You do not need to do this more than one time.
  mpcmoveCodeGeneration_initialize();

  // Invoke the entry-point functions.
  // You can call entry-point functions multiple times.
  main_mpcmoveCodeGeneration();

  // Terminate the application.
  // You do not need to do this more than one time.
  mpcmoveCodeGeneration_terminate();
  return 0;
}

//
// File trailer for main.cpp
//
// [EOF]
//
