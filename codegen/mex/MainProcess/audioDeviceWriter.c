/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * audioDeviceWriter.c
 *
 * Code generation for function 'audioDeviceWriter'
 *
 */

/* Include files */
#include "audioDeviceWriter.h"
#include "MainProcess_internal_types.h"
#include "rt_nonfinite.h"
#include "DAHostLib_rtw.h"
#include "HostLib_Audio.h"
#include <string.h>

/* Function Definitions */
audioDeviceWriter *c_audioDeviceWriter_audioDevice(audioDeviceWriter *obj)
{
  audioDeviceWriter *b_obj;
  b_obj = obj;
  b_obj->isInitialized = 0;
  /* System object Constructor function: audiointerface.audioDeviceWriter */
  b_obj->pInterface.S0_isInitialized = 0;
  b_obj->matlabCodegenIsDeleted = false;
  return b_obj;
}

/* End of code generation (audioDeviceWriter.c) */
