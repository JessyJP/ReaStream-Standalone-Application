/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * readReaStreameFrame.h
 *
 * Code generation for function 'readReaStreameFrame'
 *
 */

#pragma once

/* Include files */
#include "MainProcess_types.h"
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
void readReaStreameFrame(
    const emlrtStack *sp, const char_T obj_ReaStreamIDtag_data[],
    const int32_T obj_ReaStreamIDtag_size[2], const char_T obj_frameStart[4],
    real_T *audioFrame_udpPayLoadBytes, char_T audioFrame_streamName_data[],
    int32_T audioFrame_streamName_size[2], real_T *audioFrame_numChannels,
    real_T *audioFrame_SampleRate, real_T *audioFrame_audioByteLength,
    real_T *audioFrame_bufferSize, real_T *audioFrame_timeLength_ms,
    emxArray_real32_T *audioFrame_audioFrameBuff, real_T *STATE_FLAG_);

/* End of code generation (readReaStreameFrame.h) */
