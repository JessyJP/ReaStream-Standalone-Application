/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: SystemCore.c
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 13-Nov-2021 13:55:06
 */

/* Include Files */
#include "SystemCore.h"
#include "MainProcess_emxutil.h"
#include "MainProcess_internal_types.h"
#include "MainProcess_types.h"
#include "rt_nonfinite.h"
#include "DAHostLib_rtw.h"
#include "HostLib_Audio.h"
#include <string.h>

/* Function Definitions */
/*
 * Arguments    : audioDeviceWriter *obj
 * Return Type  : void
 */
void SystemCore_release(audioDeviceWriter *obj)
{
  char *sErr;
  if (obj->isInitialized == 1) {
    obj->isInitialized = 2;
    if (obj->isSetupComplete && (obj->pInterface.S0_isInitialized == 1)) {
      /* System object Destructor function: audiointerface.audioDeviceWriter */
      obj->pInterface.S0_isInitialized = 2;
      /* System object Terminate function: audiointerface.audioDeviceWriter */
      sErr = GetErrorBuffer(&obj->pInterface.W0_AudioDeviceLib[0U]);
      LibTerminate(&obj->pInterface.W0_AudioDeviceLib[0U]);
      if (*sErr != 0) {
        PrintError(sErr);
      }
      LibDestroy_Audio(&obj->pInterface.W0_AudioDeviceLib[0U], 1, 1);
      DestroyHostLibrary(&obj->pInterface.W0_AudioDeviceLib[0U]);
    }
  }
}

/*
 * Arguments    : audioDeviceWriter *obj
 *                const emxArray_real32_T *varargin_1
 * Return Type  : void
 */
void SystemCore_step(audioDeviceWriter *obj,
                     const emxArray_real32_T *varargin_1)
{
  cell_wrap_3 varSizes;
  emxArray_real32_T *U0;
  int b_i;
  int k;
  short inSize[8];
  char *sErr;
  boolean_T exitg1;
  emxInit_real32_T(&U0, 2);
  if (obj->isInitialized != 1) {
    obj->isSetupComplete = false;
    obj->isInitialized = 1;
    varSizes.f1[0] = (unsigned int)varargin_1->size[0];
    varSizes.f1[1] = (unsigned int)varargin_1->size[1];
    for (b_i = 0; b_i < 6; b_i++) {
      varSizes.f1[b_i + 2] = 1U;
    }
    obj->inputVarSize[0] = varSizes;
    if (obj->pInterface.S0_isInitialized != 1) {
      obj->pInterface.S0_isInitialized = 1;
      /* System object Start function: audiointerface.audioDeviceWriter */
      sErr = GetErrorBuffer(&obj->pInterface.W0_AudioDeviceLib[0U]);
      CreateHostLibrary("hostlibaudio.dll",
                        &obj->pInterface.W0_AudioDeviceLib[0U]);
      if (*sErr == 0) {
        LibCreate_Audio(&obj->pInterface.W0_AudioDeviceLib[0U], 0, "Default", 1,
                        1, 255, 48000.0, 3, 4096, 40960, -1, 1, NULL);
      }
      if (*sErr != 0) {
        DestroyHostLibrary(&obj->pInterface.W0_AudioDeviceLib[0U]);
        if (*sErr != 0) {
          PrintError(sErr);
        }
      }
    }
    obj->isSetupComplete = true;
    obj->TunablePropsChanged = false;
    if (obj->pInterface.S0_isInitialized == 1) {
      /* System object Initialization function: audiointerface.audioDeviceWriter
       */
      obj->pInterface.W1_numChans = 255U;
    }
  }
  if (obj->TunablePropsChanged) {
    obj->TunablePropsChanged = false;
  }
  inSize[0] = (short)varargin_1->size[0];
  inSize[1] = (short)varargin_1->size[1];
  for (b_i = 0; b_i < 6; b_i++) {
    inSize[b_i + 2] = 1;
  }
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 8)) {
    if (obj->inputVarSize[0].f1[k] != (unsigned int)inSize[k]) {
      for (b_i = 0; b_i < 8; b_i++) {
        obj->inputVarSize[0].f1[b_i] = (unsigned int)inSize[b_i];
      }
      exitg1 = true;
    } else {
      k++;
    }
  }
  if (obj->pInterface.S0_isInitialized != 1) {
    obj->pInterface.S0_isInitialized = 1;
    /* System object Start function: audiointerface.audioDeviceWriter */
    sErr = GetErrorBuffer(&obj->pInterface.W0_AudioDeviceLib[0U]);
    CreateHostLibrary("hostlibaudio.dll",
                      &obj->pInterface.W0_AudioDeviceLib[0U]);
    if (*sErr == 0) {
      LibCreate_Audio(&obj->pInterface.W0_AudioDeviceLib[0U], 0, "Default", 1,
                      1, 255, 48000.0, 3, 4096, 40960, -1, 1, NULL);
    }
    if (*sErr != 0) {
      DestroyHostLibrary(&obj->pInterface.W0_AudioDeviceLib[0U]);
      if (*sErr != 0) {
        PrintError(sErr);
      }
    }
    /* System object Initialization function: audiointerface.audioDeviceWriter
     */
    obj->pInterface.W1_numChans = 255U;
  }
  b_i = U0->size[0] * U0->size[1];
  U0->size[0] = varargin_1->size[0];
  U0->size[1] = varargin_1->size[1];
  emxEnsureCapacity_real32_T(U0, b_i);
  k = varargin_1->size[0] * varargin_1->size[1];
  for (b_i = 0; b_i < k; b_i++) {
    U0->data[b_i] = varargin_1->data[b_i];
  }
  /* System object Outputs function: audiointerface.audioDeviceWriter */
  if (U0->size[0] != 0) {
    if ((unsigned int)U0->size[1] != obj->pInterface.W1_numChans) {
      sErr = GetErrorBuffer(&obj->pInterface.W0_AudioDeviceLib[0U]);
      LibTerminate(&obj->pInterface.W0_AudioDeviceLib[0U]);
      if (*sErr != 0) {
        PrintError(sErr);
      }
      LibDestroy_Audio(&obj->pInterface.W0_AudioDeviceLib[0U], 1, 1);
      DestroyHostLibrary(&obj->pInterface.W0_AudioDeviceLib[0U]);
      sErr = GetErrorBuffer(&obj->pInterface.W0_AudioDeviceLib[0U]);
      CreateHostLibrary("hostlibaudio.dll",
                        &obj->pInterface.W0_AudioDeviceLib[0U]);
      if (*sErr == 0) {
        LibCreate_Audio(&obj->pInterface.W0_AudioDeviceLib[0U], 0, "Default", 1,
                        1, U0->size[1], 48000.0, 3, 4096, 40960, -1, 1, NULL);
      }
      if (*sErr != 0) {
        DestroyHostLibrary(&obj->pInterface.W0_AudioDeviceLib[0U]);
        if (*sErr != 0) {
          PrintError(sErr);
        }
      }
      obj->pInterface.W1_numChans = (unsigned int)U0->size[1];
    }
    sErr = GetErrorBuffer(&obj->pInterface.W0_AudioDeviceLib[0U]);
    LibUpdate_Audio(&obj->pInterface.W0_AudioDeviceLib[0U], &U0->data[0U], 1,
                    U0->size[0], &obj->pInterface.O0_Y0);
    if (*sErr != 0) {
      PrintError(sErr);
    }
  }
  emxFree_real32_T(&U0);
}

/*
 * File trailer for SystemCore.c
 *
 * [EOF]
 */
