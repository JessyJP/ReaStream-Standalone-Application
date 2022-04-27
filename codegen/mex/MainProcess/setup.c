/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * setup.c
 *
 * Code generation for function 'setup'
 *
 */

/* Include files */
#include "setup.h"
#include "MainProcess_internal_types.h"
#include "rt_nonfinite.h"
#include "DAHostLib_rtw.h"
#include "HostLib_Audio.h"
#include <string.h>

/* Variable Definitions */
static emlrtRTEInfo l_emlrtRTEI = {
    43,      /* lineNo */
    1,       /* colNo */
    "setup", /* fName */
    "D:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\scomp\\setup.m" /* pName
                                                                            */
};

/* Function Definitions */
void setup(const emlrtStack *sp, c_audiointerface_audioDeviceWri *obj)
{
  char_T *sErr;
  if (obj->S0_isInitialized != 1) {
    if (obj->S0_isInitialized == 2) {
      emlrtErrorWithMessageIdR2018a(
          sp, &l_emlrtRTEI,
          "MATLAB:system:setupCalledWhenLockedReleasedCodegen",
          "MATLAB:system:setupCalledWhenLockedReleasedCodegen", 0);
    }
    obj->S0_isInitialized = 1;
    /* System object Start function: audiointerface.audioDeviceWriter */
    sErr = GetErrorBuffer(&obj->W0_AudioDeviceLib[0U]);
    CreateHostLibrary("hostlibaudio.dll", &obj->W0_AudioDeviceLib[0U]);
    if (*sErr == 0) {
      LibCreate_Audio(&obj->W0_AudioDeviceLib[0U], 0, "Default", 1, 1, 255,
                      48000.0, 3, 4096, 40960, -1, 1, NULL);
    }
    if (*sErr != 0) {
      DestroyHostLibrary(&obj->W0_AudioDeviceLib[0U]);
      if (*sErr != 0) {
        PrintError(sErr);
      }
    }
  } else {
    emlrtErrorWithMessageIdR2018a(
        sp, &l_emlrtRTEI, "MATLAB:system:setupCalledWhenLockedCodegen",
        "MATLAB:system:setupCalledWhenLockedCodegen", 0);
  }
}

/* End of code generation (setup.c) */
