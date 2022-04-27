/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * SystemCore.c
 *
 * Code generation for function 'SystemCore'
 *
 */

/* Include files */
#include "SystemCore.h"
#include "MainProcess_data.h"
#include "MainProcess_emxutil.h"
#include "MainProcess_internal_types.h"
#include "MainProcess_types.h"
#include "rt_nonfinite.h"
#include "setup.h"
#include "DAHostLib_rtw.h"
#include "HostLib_Audio.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo l_emlrtRSI =
    {
        1,                            /* lineNo */
        "audioDeviceWriter/stepImpl", /* fcnName */
        "D:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\dsp\\dsp\\compiled\\audioDeviceWriter."
        "p" /* pathName */
};

static emlrtRSInfo qc_emlrtRSI = {
    1,                 /* lineNo */
    "SystemCore/step", /* fcnName */
    "D:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\shared\\system\\coder\\+matlab\\+system\\+"
    "coder\\SystemCore.p" /* pathName */
};

static emlrtRSInfo rc_emlrtRSI = {
    1,                          /* lineNo */
    "SystemCore/setupAndReset", /* fcnName */
    "D:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\shared\\system\\coder\\+matlab\\+system\\+"
    "coder\\SystemCore.p" /* pathName */
};

static emlrtRSInfo sc_emlrtRSI = {
    1,                  /* lineNo */
    "SystemCore/setup", /* fcnName */
    "D:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\shared\\system\\coder\\+matlab\\+system\\+"
    "coder\\SystemCore.p" /* pathName */
};

static emlrtRSInfo tc_emlrtRSI =
    {
        1,                             /* lineNo */
        "audioDeviceWriter/setupImpl", /* fcnName */
        "D:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\dsp\\dsp\\compiled\\audioDeviceWriter."
        "p" /* pathName */
};

static emlrtRTEInfo i_emlrtRTEI = {
    1,                    /* lineNo */
    1,                    /* colNo */
    "SystemCore/release", /* fName */
    "D:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\shared\\system\\coder\\+matlab\\+system\\+"
    "coder\\SystemCore.p" /* pName */
};

static emlrtRTEInfo j_emlrtRTEI = {
    49,     /* lineNo */
    20,     /* colNo */
    "step", /* fName */
    "D:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\scomp\\step.m" /* pName
                                                                           */
};

static emlrtRTEInfo k_emlrtRTEI = {
    15,      /* lineNo */
    1,       /* colNo */
    "reset", /* fName */
    "D:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\scomp\\reset.m" /* pName
                                                                            */
};

static emlrtRTEInfo m_emlrtRTEI = {
    1,                 /* lineNo */
    1,                 /* colNo */
    "SystemCore/step", /* fName */
    "D:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\shared\\system\\coder\\+matlab\\+system\\+"
    "coder\\SystemCore.p" /* pName */
};

static emlrtRTEInfo n_emlrtRTEI = {
    1,                  /* lineNo */
    1,                  /* colNo */
    "SystemCore/setup", /* fName */
    "D:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\shared\\system\\coder\\+matlab\\+system\\+"
    "coder\\SystemCore.p" /* pName */
};

static emlrtRTEInfo ab_emlrtRTEI = {
    49,     /* lineNo */
    53,     /* colNo */
    "step", /* fName */
    "D:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\scomp\\step.m" /* pName
                                                                           */
};

/* Function Definitions */
void SystemCore_release(audioDeviceWriter *obj)
{
  char_T *sErr;
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

void SystemCore_step(const emlrtStack *sp, audioDeviceWriter *obj,
                     const emxArray_real32_T *varargin_1)
{
  cell_wrap_3 varSizes;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  emxArray_real32_T *U0;
  int32_T b_i;
  int32_T k;
  int16_T inSize[8];
  char_T *sErr;
  boolean_T exitg1;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  emxInit_real32_T(sp, &U0, 2, &ab_emlrtRTEI, true);
  if (obj->isInitialized == 2) {
    emlrtErrorWithMessageIdR2018a(
        sp, &i_emlrtRTEI, "MATLAB:system:methodCalledWhenReleasedCodegen",
        "MATLAB:system:methodCalledWhenReleasedCodegen", 3, 4, 4, "step");
  }
  if (obj->isInitialized != 1) {
    st.site = &o_emlrtRSI;
    b_st.site = &o_emlrtRSI;
    obj->isSetupComplete = false;
    if (obj->isInitialized != 0) {
      emlrtErrorWithMessageIdR2018a(
          &b_st, &i_emlrtRTEI,
          "MATLAB:system:methodCalledWhenLockedReleasedCodegen",
          "MATLAB:system:methodCalledWhenLockedReleasedCodegen", 3, 4, 5,
          "setup");
    }
    obj->isInitialized = 1;
    c_st.site = &o_emlrtRSI;
    varSizes.f1[0] = (uint32_T)varargin_1->size[0];
    varSizes.f1[1] = (uint32_T)varargin_1->size[1];
    for (b_i = 0; b_i < 6; b_i++) {
      varSizes.f1[b_i + 2] = 1U;
    }
    obj->inputVarSize[0] = varSizes;
    c_st.site = &o_emlrtRSI;
    d_st.site = &l_emlrtRSI;
    setup(&d_st, &obj->pInterface);
    obj->isSetupComplete = true;
    obj->TunablePropsChanged = false;
    b_st.site = &o_emlrtRSI;
    c_st.site = &l_emlrtRSI;
    if (obj->pInterface.S0_isInitialized == 2) {
      emlrtErrorWithMessageIdR2018a(
          &c_st, &k_emlrtRTEI,
          "MATLAB:system:runtimeMethodCalledWhenReleasedCodegen",
          "MATLAB:system:runtimeMethodCalledWhenReleasedCodegen", 0);
    }
    if (obj->pInterface.S0_isInitialized == 1) {
      /* System object Initialization function: audiointerface.audioDeviceWriter
       */
      obj->pInterface.W1_numChans = 255U;
    }
  }
  st.site = &o_emlrtRSI;
  if (obj->TunablePropsChanged) {
    obj->TunablePropsChanged = false;
  }
  st.site = &o_emlrtRSI;
  inSize[0] = (int16_T)varargin_1->size[0];
  inSize[1] = (int16_T)varargin_1->size[1];
  for (b_i = 0; b_i < 6; b_i++) {
    inSize[b_i + 2] = 1;
  }
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 8)) {
    if (obj->inputVarSize[0].f1[k] != (uint32_T)inSize[k]) {
      for (b_i = 0; b_i < 8; b_i++) {
        obj->inputVarSize[0].f1[b_i] = (uint32_T)inSize[b_i];
      }
      exitg1 = true;
    } else {
      k++;
    }
  }
  st.site = &o_emlrtRSI;
  b_st.site = &l_emlrtRSI;
  if (obj->pInterface.S0_isInitialized != 1) {
    if (obj->pInterface.S0_isInitialized == 2) {
      emlrtErrorWithMessageIdR2018a(
          &b_st, &j_emlrtRTEI,
          "MATLAB:system:runtimeMethodCalledWhenReleasedCodegen",
          "MATLAB:system:runtimeMethodCalledWhenReleasedCodegen", 0);
    }
    obj->pInterface.S0_isInitialized = 1;
    c_st.site = NULL;
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
    c_st.site = NULL;
    /* System object Initialization function: audiointerface.audioDeviceWriter
     */
    obj->pInterface.W1_numChans = 255U;
  }
  c_st.site = NULL;
  b_i = U0->size[0] * U0->size[1];
  U0->size[0] = varargin_1->size[0];
  U0->size[1] = varargin_1->size[1];
  emxEnsureCapacity_real32_T(&c_st, U0, b_i, &ab_emlrtRTEI);
  k = varargin_1->size[0] * varargin_1->size[1];
  for (b_i = 0; b_i < k; b_i++) {
    U0->data[b_i] = varargin_1->data[b_i];
  }
  /* System object Outputs function: audiointerface.audioDeviceWriter */
  if (U0->size[0] != 0) {
    if ((uint32_T)U0->size[1] != obj->pInterface.W1_numChans) {
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
      obj->pInterface.W1_numChans = (uint32_T)U0->size[1];
    }
    sErr = GetErrorBuffer(&obj->pInterface.W0_AudioDeviceLib[0U]);
    LibUpdate_Audio(&obj->pInterface.W0_AudioDeviceLib[0U], &U0->data[0U], 1,
                    U0->size[0], &obj->pInterface.O0_Y0);
    if (*sErr != 0) {
      PrintError(sErr);
    }
  }
  emxFree_real32_T(&U0);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

void b_SystemCore_step(const emlrtStack *sp, audioDeviceWriter *obj,
                       const emxArray_real32_T *varargin_1)
{
  cell_wrap_3 varSizes;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  emxArray_real32_T *U0;
  int32_T b_i;
  int32_T k;
  uint32_T inSize[8];
  char_T *sErr;
  boolean_T exitg1;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  emxInit_real32_T(sp, &U0, 2, &ab_emlrtRTEI, true);
  if (obj->isInitialized == 2) {
    emlrtErrorWithMessageIdR2018a(
        sp, &m_emlrtRTEI, "MATLAB:system:methodCalledWhenReleasedCodegen",
        "MATLAB:system:methodCalledWhenReleasedCodegen", 3, 4, 4, "step");
  }
  if (obj->isInitialized != 1) {
    st.site = &qc_emlrtRSI;
    b_st.site = &rc_emlrtRSI;
    obj->isSetupComplete = false;
    if (obj->isInitialized != 0) {
      emlrtErrorWithMessageIdR2018a(
          &b_st, &n_emlrtRTEI,
          "MATLAB:system:methodCalledWhenLockedReleasedCodegen",
          "MATLAB:system:methodCalledWhenLockedReleasedCodegen", 3, 4, 5,
          "setup");
    }
    obj->isInitialized = 1;
    c_st.site = &sc_emlrtRSI;
    varSizes.f1[0] = (uint32_T)varargin_1->size[0];
    varSizes.f1[1] = (uint32_T)varargin_1->size[1];
    for (b_i = 0; b_i < 6; b_i++) {
      varSizes.f1[b_i + 2] = 1U;
    }
    obj->inputVarSize[0] = varSizes;
    c_st.site = &sc_emlrtRSI;
    d_st.site = &tc_emlrtRSI;
    setup(&d_st, &obj->pInterface);
    obj->isSetupComplete = true;
    obj->TunablePropsChanged = false;
    b_st.site = &rc_emlrtRSI;
    c_st.site = &l_emlrtRSI;
    if (obj->pInterface.S0_isInitialized == 2) {
      emlrtErrorWithMessageIdR2018a(
          &c_st, &k_emlrtRTEI,
          "MATLAB:system:runtimeMethodCalledWhenReleasedCodegen",
          "MATLAB:system:runtimeMethodCalledWhenReleasedCodegen", 0);
    }
    if (obj->pInterface.S0_isInitialized == 1) {
      /* System object Initialization function: audiointerface.audioDeviceWriter
       */
      obj->pInterface.W1_numChans = 255U;
    }
  }
  st.site = &qc_emlrtRSI;
  if (obj->TunablePropsChanged) {
    obj->TunablePropsChanged = false;
  }
  st.site = &qc_emlrtRSI;
  inSize[0] = (uint32_T)varargin_1->size[0];
  inSize[1] = (uint32_T)varargin_1->size[1];
  for (b_i = 0; b_i < 6; b_i++) {
    inSize[b_i + 2] = 1U;
  }
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 8)) {
    if (obj->inputVarSize[0].f1[k] != inSize[k]) {
      for (b_i = 0; b_i < 8; b_i++) {
        obj->inputVarSize[0].f1[b_i] = inSize[b_i];
      }
      exitg1 = true;
    } else {
      k++;
    }
  }
  st.site = &qc_emlrtRSI;
  b_st.site = &l_emlrtRSI;
  if (obj->pInterface.S0_isInitialized != 1) {
    if (obj->pInterface.S0_isInitialized == 2) {
      emlrtErrorWithMessageIdR2018a(
          &b_st, &j_emlrtRTEI,
          "MATLAB:system:runtimeMethodCalledWhenReleasedCodegen",
          "MATLAB:system:runtimeMethodCalledWhenReleasedCodegen", 0);
    }
    obj->pInterface.S0_isInitialized = 1;
    c_st.site = NULL;
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
    c_st.site = NULL;
    /* System object Initialization function: audiointerface.audioDeviceWriter
     */
    obj->pInterface.W1_numChans = 255U;
  }
  c_st.site = NULL;
  b_i = U0->size[0] * U0->size[1];
  U0->size[0] = varargin_1->size[0];
  U0->size[1] = varargin_1->size[1];
  emxEnsureCapacity_real32_T(&c_st, U0, b_i, &ab_emlrtRTEI);
  k = varargin_1->size[0] * varargin_1->size[1];
  for (b_i = 0; b_i < k; b_i++) {
    U0->data[b_i] = varargin_1->data[b_i];
  }
  /* System object Outputs function: audiointerface.audioDeviceWriter */
  if (U0->size[0] != 0) {
    if ((uint32_T)U0->size[1] != obj->pInterface.W1_numChans) {
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
      obj->pInterface.W1_numChans = (uint32_T)U0->size[1];
    }
    sErr = GetErrorBuffer(&obj->pInterface.W0_AudioDeviceLib[0U]);
    LibUpdate_Audio(&obj->pInterface.W0_AudioDeviceLib[0U], &U0->data[0U], 1,
                    U0->size[0], &obj->pInterface.O0_Y0);
    if (*sErr != 0) {
      PrintError(sErr);
    }
  }
  emxFree_real32_T(&U0);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

/* End of code generation (SystemCore.c) */
