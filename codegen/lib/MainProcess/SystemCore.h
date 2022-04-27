/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: SystemCore.h
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 13-Nov-2021 13:55:06
 */

#ifndef SYSTEMCORE_H
#define SYSTEMCORE_H

/* Include Files */
#include "MainProcess_internal_types.h"
#include "MainProcess_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void SystemCore_release(audioDeviceWriter *obj);

void SystemCore_step(audioDeviceWriter *obj,
                     const emxArray_real32_T *varargin_1);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for SystemCore.h
 *
 * [EOF]
 */
