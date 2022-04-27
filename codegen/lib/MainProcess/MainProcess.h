/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: MainProcess.h
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 13-Nov-2021 13:55:06
 */

#ifndef MAINPROCESS_H
#define MAINPROCESS_H

/* Include Files */
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
extern void MainProcess(const char ReaStreamIDtag_data[],
                        const int ReaStreamIDtag_size[2],
                        const char driverSelection[11],
                        const char deviceSelection[7], double pbSampSize,
                        boolean_T VariableBufferON);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for MainProcess.h
 *
 * [EOF]
 */
