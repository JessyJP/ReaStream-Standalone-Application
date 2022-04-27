/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * MainProcess.h
 *
 * Code generation for function 'MainProcess'
 *
 */

#pragma once

/* Include files */
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
void MainProcess(const emlrtStack *sp, const char_T ReaStreamIDtag_data[],
                 const int32_T ReaStreamIDtag_size[2],
                 const char_T driverSelection[11],
                 const char_T deviceSelection[7], real_T pbSampSize,
                 boolean_T VariableBufferON);

/* End of code generation (MainProcess.h) */
