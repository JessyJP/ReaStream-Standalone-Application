/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: readReaStreameFrame.h
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 13-Nov-2021 13:55:06
 */

#ifndef READREASTREAMEFRAME_H
#define READREASTREAMEFRAME_H

/* Include Files */
#include "MainProcess_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void readReaStreameFrame(
    const char obj_ReaStreamIDtag_data[], const int obj_ReaStreamIDtag_size[2],
    const char obj_frameStart[4], double *audioFrame_udpPayLoadBytes,
    char audioFrame_streamName_data[], int audioFrame_streamName_size[2],
    double *audioFrame_numChannels, double *audioFrame_SampleRate,
    double *audioFrame_audioByteLength, double *audioFrame_bufferSize,
    double *audioFrame_timeLength_ms, emxArray_real32_T *audioFrame_audioFrameBuff,
    double *STATE_FLAG_);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for readReaStreameFrame.h
 *
 * [EOF]
 */
