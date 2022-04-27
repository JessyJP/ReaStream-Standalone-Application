/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_MainProcess_api.h
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 13-Nov-2021 13:55:06
 */

#ifndef _CODER_MAINPROCESS_API_H
#define _CODER_MAINPROCESS_API_H

/* Include Files */
#include "emlrt.h"
#include "tmwtypes.h"
#include <string.h>

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void MEXGlobalSyncInFunction(const emlrtStack *sp);

void MEXGlobalSyncOutFunction(boolean_T skipDirtyCheck);

void MainProcess(char_T ReaStreamIDtag_data[], int32_T ReaStreamIDtag_size[2],
                 char_T driverSelection[11], char_T deviceSelection[7],
                 real_T pbSampSize, boolean_T VariableBufferON);

void MainProcess_api(const mxArray *const prhs[5]);

void MainProcess_atexit(void);

void MainProcess_initialize(void);

void MainProcess_terminate(void);

void MainProcess_xil_shutdown(void);

void MainProcess_xil_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for _coder_MainProcess_api.h
 *
 * [EOF]
 */
