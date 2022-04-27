/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * SystemCore.h
 *
 * Code generation for function 'SystemCore'
 *
 */

#pragma once

/* Include files */
#include "MainProcess_internal_types.h"
#include "MainProcess_types.h"
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
void SystemCore_release(audioDeviceWriter *obj);

void SystemCore_step(const emlrtStack *sp, audioDeviceWriter *obj,
                     const emxArray_real32_T *varargin_1);

void b_SystemCore_step(const emlrtStack *sp, audioDeviceWriter *obj,
                       const emxArray_real32_T *varargin_1);

/* End of code generation (SystemCore.h) */
