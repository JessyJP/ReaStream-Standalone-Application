/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * MainProcess.c
 *
 * Code generation for function 'MainProcess'
 *
 */

/* Include files */
#include "MainProcess.h"
#include "MainProcess_data.h"
#include "MainProcess_emxutil.h"
#include "MainProcess_internal_types.h"
#include "MainProcess_types.h"
#include "SystemCore.h"
#include "audioDeviceWriter.h"
#include "handle.h"
#include "nullAssignment.h"
#include "readReaStreameFrame.h"
#include "rt_nonfinite.h"
#include "DAHostLib_rtw.h"
#include "HostLib_Audio.h"
#include "mwmathutil.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = {
    9,             /* lineNo */
    "MainProcess", /* fcnName */
    "C:\\Users\\JessyJP\\Dropbox\\Projects Workfiles & Software\\ReaStream "
    "Standalone Receiver\\MainProcess.m" /* pathName */
};

static emlrtRSInfo b_emlrtRSI = {
    82,            /* lineNo */
    "MainProcess", /* fcnName */
    "C:\\Users\\JessyJP\\Dropbox\\Projects Workfiles & Software\\ReaStream "
    "Standalone Receiver\\MainProcess.m" /* pathName */
};

static emlrtRSInfo c_emlrtRSI = {
    79,            /* lineNo */
    "MainProcess", /* fcnName */
    "C:\\Users\\JessyJP\\Dropbox\\Projects Workfiles & Software\\ReaStream "
    "Standalone Receiver\\MainProcess.m" /* pathName */
};

static emlrtRSInfo d_emlrtRSI = {
    74,            /* lineNo */
    "MainProcess", /* fcnName */
    "C:\\Users\\JessyJP\\Dropbox\\Projects Workfiles & Software\\ReaStream "
    "Standalone Receiver\\MainProcess.m" /* pathName */
};

static emlrtRSInfo e_emlrtRSI = {
    66,            /* lineNo */
    "MainProcess", /* fcnName */
    "C:\\Users\\JessyJP\\Dropbox\\Projects Workfiles & Software\\ReaStream "
    "Standalone Receiver\\MainProcess.m" /* pathName */
};

static emlrtRSInfo f_emlrtRSI = {
    51,            /* lineNo */
    "MainProcess", /* fcnName */
    "C:\\Users\\JessyJP\\Dropbox\\Projects Workfiles & Software\\ReaStream "
    "Standalone Receiver\\MainProcess.m" /* pathName */
};

static emlrtRSInfo g_emlrtRSI = {
    44,            /* lineNo */
    "MainProcess", /* fcnName */
    "C:\\Users\\JessyJP\\Dropbox\\Projects Workfiles & Software\\ReaStream "
    "Standalone Receiver\\MainProcess.m" /* pathName */
};

static emlrtRSInfo h_emlrtRSI = {
    41,            /* lineNo */
    "MainProcess", /* fcnName */
    "C:\\Users\\JessyJP\\Dropbox\\Projects Workfiles & Software\\ReaStream "
    "Standalone Receiver\\MainProcess.m" /* pathName */
};

static emlrtRSInfo i_emlrtRSI = {
    39,            /* lineNo */
    "MainProcess", /* fcnName */
    "C:\\Users\\JessyJP\\Dropbox\\Projects Workfiles & Software\\ReaStream "
    "Standalone Receiver\\MainProcess.m" /* pathName */
};

static emlrtRSInfo j_emlrtRSI = {
    35,            /* lineNo */
    "MainProcess", /* fcnName */
    "C:\\Users\\JessyJP\\Dropbox\\Projects Workfiles & Software\\ReaStream "
    "Standalone Receiver\\MainProcess.m" /* pathName */
};

static emlrtRSInfo k_emlrtRSI = {
    111,                    /* lineNo */
    "setDefaultProperties", /* fcnName */
    "C:\\Users\\JessyJP\\Dropbox\\Projects Workfiles & Software\\ReaStream "
    "Standalone Receiver\\MainProcess.m" /* pathName */
};

static emlrtRSInfo gc_emlrtRSI = {
    71,                   /* lineNo */
    "decodePlaybackLoop", /* fcnName */
    "C:\\Users\\JessyJP\\Dropbox\\Projects Workfiles & Software\\ReaStream "
    "Standalone Receiver\\decodePlaybackLoop.m" /* pathName */
};

static emlrtRSInfo hc_emlrtRSI = {
    70,                   /* lineNo */
    "decodePlaybackLoop", /* fcnName */
    "C:\\Users\\JessyJP\\Dropbox\\Projects Workfiles & Software\\ReaStream "
    "Standalone Receiver\\decodePlaybackLoop.m" /* pathName */
};

static emlrtRSInfo ic_emlrtRSI = {
    67,                   /* lineNo */
    "decodePlaybackLoop", /* fcnName */
    "C:\\Users\\JessyJP\\Dropbox\\Projects Workfiles & Software\\ReaStream "
    "Standalone Receiver\\decodePlaybackLoop.m" /* pathName */
};

static emlrtRSInfo jc_emlrtRSI = {
    59,                   /* lineNo */
    "decodePlaybackLoop", /* fcnName */
    "C:\\Users\\JessyJP\\Dropbox\\Projects Workfiles & Software\\ReaStream "
    "Standalone Receiver\\decodePlaybackLoop.m" /* pathName */
};

static emlrtRSInfo kc_emlrtRSI = {
    39,                   /* lineNo */
    "decodePlaybackLoop", /* fcnName */
    "C:\\Users\\JessyJP\\Dropbox\\Projects Workfiles & Software\\ReaStream "
    "Standalone Receiver\\decodePlaybackLoop.m" /* pathName */
};

static emlrtRSInfo lc_emlrtRSI = {
    23,                   /* lineNo */
    "decodePlaybackLoop", /* fcnName */
    "C:\\Users\\JessyJP\\Dropbox\\Projects Workfiles & Software\\ReaStream "
    "Standalone Receiver\\decodePlaybackLoop.m" /* pathName */
};

static emlrtRSInfo mc_emlrtRSI = {
    16,                   /* lineNo */
    "decodePlaybackLoop", /* fcnName */
    "C:\\Users\\JessyJP\\Dropbox\\Projects Workfiles & Software\\ReaStream "
    "Standalone Receiver\\decodePlaybackLoop.m" /* pathName */
};

static emlrtRSInfo nc_emlrtRSI = {
    24,    /* lineNo */
    "cat", /* fcnName */
    "D:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\cat.m" /* pathName
                                                                          */
};

static emlrtRSInfo oc_emlrtRSI = {
    96,         /* lineNo */
    "cat_impl", /* fcnName */
    "D:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\cat.m" /* pathName
                                                                          */
};

static emlrtRSInfo pc_emlrtRSI = {
    1,                           /* lineNo */
    "SystemCore/parenReference", /* fcnName */
    "D:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\shared\\system\\coder\\+matlab\\+system\\+"
    "coder\\SystemCore.p" /* pathName */
};

static emlrtMCInfo emlrtMCI = {
    31,            /* lineNo */
    5,             /* colNo */
    "MainProcess", /* fName */
    "C:\\Users\\JessyJP\\Dropbox\\Projects Workfiles & Software\\ReaStream "
    "Standalone Receiver\\MainProcess.m" /* pName */
};

static emlrtMCInfo b_emlrtMCI = {
    42,            /* lineNo */
    9,             /* colNo */
    "MainProcess", /* fName */
    "C:\\Users\\JessyJP\\Dropbox\\Projects Workfiles & Software\\ReaStream "
    "Standalone Receiver\\MainProcess.m" /* pName */
};

static emlrtMCInfo c_emlrtMCI = {
    64,            /* lineNo */
    9,             /* colNo */
    "MainProcess", /* fName */
    "C:\\Users\\JessyJP\\Dropbox\\Projects Workfiles & Software\\ReaStream "
    "Standalone Receiver\\MainProcess.m" /* pName */
};

static emlrtMCInfo d_emlrtMCI = {
    69,            /* lineNo */
    9,             /* colNo */
    "MainProcess", /* fName */
    "C:\\Users\\JessyJP\\Dropbox\\Projects Workfiles & Software\\ReaStream "
    "Standalone Receiver\\MainProcess.m" /* pName */
};

static emlrtMCInfo e_emlrtMCI = {
    78,            /* lineNo */
    9,             /* colNo */
    "MainProcess", /* fName */
    "C:\\Users\\JessyJP\\Dropbox\\Projects Workfiles & Software\\ReaStream "
    "Standalone Receiver\\MainProcess.m" /* pName */
};

static emlrtMCInfo f_emlrtMCI = {
    135,            /* lineNo */
    5,              /* colNo */
    "connectReceiverUDP", /* fName */
    "C:\\Users\\JessyJP\\Dropbox\\Projects Workfiles & Software\\ReaStream "
    "Standalone Receiver\\MainProcess.m" /* pName */
};

static emlrtMCInfo g_emlrtMCI = {
    143,             /* lineNo */
    5,               /* colNo */
    "disconnectReceiverUDP", /* fName */
    "C:\\Users\\JessyJP\\Dropbox\\Projects Workfiles & Software\\ReaStream "
    "Standalone Receiver\\MainProcess.m" /* pName */
};

static emlrtMCInfo h_emlrtMCI = {
    196,                /* lineNo */
    9,                  /* colNo */
    "SetupAudioDevice", /* fName */
    "C:\\Users\\JessyJP\\Dropbox\\Projects Workfiles & Software\\ReaStream "
    "Standalone Receiver\\MainProcess.m" /* pName */
};

static emlrtMCInfo i_emlrtMCI = {
    5,                /* lineNo */
    2,                /* colNo */
    "flushUDPbuffer", /* fName */
    "C:\\Users\\JessyJP\\Dropbox\\Projects Workfiles & Software\\ReaStream "
    "Standalone Receiver\\flushUDPbuffer.m" /* pName */
};

static emlrtBCInfo emlrtBCI = {
    -1,                   /* iFirst */
    -1,                   /* iLast */
    70,                   /* lineNo */
    51,                   /* colNo */
    "playbackBuffer",     /* aName */
    "decodePlaybackLoop", /* fName */
    "C:\\Users\\JessyJP\\Dropbox\\Projects Workfiles & Software\\ReaStream "
    "Standalone Receiver\\decodePlaybackLoop.m", /* pName */
    0                                         /* checkKind */
};

static emlrtDCInfo emlrtDCI = {
    70,                   /* lineNo */
    51,                   /* colNo */
    "decodePlaybackLoop", /* fName */
    "C:\\Users\\JessyJP\\Dropbox\\Projects Workfiles & Software\\ReaStream "
    "Standalone Receiver\\decodePlaybackLoop.m", /* pName */
    1                                         /* checkKind */
};

static emlrtBCInfo b_emlrtBCI = {
    -1,                   /* iFirst */
    -1,                   /* iLast */
    70,                   /* lineNo */
    49,                   /* colNo */
    "playbackBuffer",     /* aName */
    "decodePlaybackLoop", /* fName */
    "C:\\Users\\JessyJP\\Dropbox\\Projects Workfiles & Software\\ReaStream "
    "Standalone Receiver\\decodePlaybackLoop.m", /* pName */
    0                                         /* checkKind */
};

static emlrtRTEInfo emlrtRTEI = {
    271,                   /* lineNo */
    27,                    /* colNo */
    "check_non_axis_size", /* fName */
    "D:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\cat.m" /* pName
                                                                          */
};

static emlrtRTEInfo q_emlrtRTEI = {
    291,   /* lineNo */
    14,    /* colNo */
    "cat", /* fName */
    "D:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\cat.m" /* pName
                                                                          */
};

static emlrtRTEInfo r_emlrtRTEI = {
    67,                   /* lineNo */
    13,                   /* colNo */
    "decodePlaybackLoop", /* fName */
    "C:\\Users\\JessyJP\\Dropbox\\Projects Workfiles & Software\\ReaStream "
    "Standalone Receiver\\decodePlaybackLoop.m" /* pName */
};

static emlrtRTEInfo s_emlrtRTEI = {
    70,                   /* lineNo */
    34,                   /* colNo */
    "decodePlaybackLoop", /* fName */
    "C:\\Users\\JessyJP\\Dropbox\\Projects Workfiles & Software\\ReaStream "
    "Standalone Receiver\\decodePlaybackLoop.m" /* pName */
};

static emlrtRTEInfo t_emlrtRTEI = {
    71,                   /* lineNo */
    32,                   /* colNo */
    "decodePlaybackLoop", /* fName */
    "C:\\Users\\JessyJP\\Dropbox\\Projects Workfiles & Software\\ReaStream "
    "Standalone Receiver\\decodePlaybackLoop.m" /* pName */
};

static emlrtRTEInfo u_emlrtRTEI = {
    39,            /* lineNo */
    6,             /* colNo */
    "MainProcess", /* fName */
    "C:\\Users\\JessyJP\\Dropbox\\Projects Workfiles & Software\\ReaStream "
    "Standalone Receiver\\MainProcess.m" /* pName */
};

static emlrtRTEInfo v_emlrtRTEI = {
    13,                   /* lineNo */
    5,                    /* colNo */
    "decodePlaybackLoop", /* fName */
    "C:\\Users\\JessyJP\\Dropbox\\Projects Workfiles & Software\\ReaStream "
    "Standalone Receiver\\decodePlaybackLoop.m" /* pName */
};

static emlrtRSInfo fd_emlrtRSI = {
    143,             /* lineNo */
    "disconnectReceiverUDP", /* fcnName */
    "C:\\Users\\JessyJP\\Dropbox\\Projects Workfiles & Software\\ReaStream "
    "Standalone Receiver\\MainProcess.m" /* pathName */
};

static emlrtRSInfo gd_emlrtRSI = {
    78,            /* lineNo */
    "MainProcess", /* fcnName */
    "C:\\Users\\JessyJP\\Dropbox\\Projects Workfiles & Software\\ReaStream "
    "Standalone Receiver\\MainProcess.m" /* pathName */
};

static emlrtRSInfo hd_emlrtRSI = {
    69,            /* lineNo */
    "MainProcess", /* fcnName */
    "C:\\Users\\JessyJP\\Dropbox\\Projects Workfiles & Software\\ReaStream "
    "Standalone Receiver\\MainProcess.m" /* pathName */
};

static emlrtRSInfo id_emlrtRSI = {
    5,                /* lineNo */
    "flushUDPbuffer", /* fcnName */
    "C:\\Users\\JessyJP\\Dropbox\\Projects Workfiles & Software\\ReaStream "
    "Standalone Receiver\\flushUDPbuffer.m" /* pathName */
};

static emlrtRSInfo jd_emlrtRSI = {
    64,            /* lineNo */
    "MainProcess", /* fcnName */
    "C:\\Users\\JessyJP\\Dropbox\\Projects Workfiles & Software\\ReaStream "
    "Standalone Receiver\\MainProcess.m" /* pathName */
};

static emlrtRSInfo kd_emlrtRSI = {
    196,                /* lineNo */
    "SetupAudioDevice", /* fcnName */
    "C:\\Users\\JessyJP\\Dropbox\\Projects Workfiles & Software\\ReaStream "
    "Standalone Receiver\\MainProcess.m" /* pathName */
};

static emlrtRSInfo ld_emlrtRSI = {
    135,            /* lineNo */
    "connectReceiverUDP", /* fcnName */
    "C:\\Users\\JessyJP\\Dropbox\\Projects Workfiles & Software\\ReaStream "
    "Standalone Receiver\\MainProcess.m" /* pathName */
};

static emlrtRSInfo md_emlrtRSI = {
    31,            /* lineNo */
    "MainProcess", /* fcnName */
    "C:\\Users\\JessyJP\\Dropbox\\Projects Workfiles & Software\\ReaStream "
    "Standalone Receiver\\MainProcess.m" /* pathName */
};

static emlrtRSInfo nd_emlrtRSI = {
    42,            /* lineNo */
    "MainProcess", /* fcnName */
    "C:\\Users\\JessyJP\\Dropbox\\Projects Workfiles & Software\\ReaStream "
    "Standalone Receiver\\MainProcess.m" /* pathName */
};

/* Function Declarations */
static void disp(const emlrtStack *sp, const mxArray *b, emlrtMCInfo *location);

static void drawnow(const emlrtStack *sp, emlrtMCInfo *location);

/* Function Definitions */
static void disp(const emlrtStack *sp, const mxArray *b, emlrtMCInfo *location)
{
  const mxArray *pArray;
  pArray = b;
  emlrtCallMATLABR2012b((emlrtCTX)sp, 0, NULL, 1, &pArray,
                        (const char_T *)"disp", true, location);
}

static void drawnow(const emlrtStack *sp, emlrtMCInfo *location)
{
  emlrtCallMATLABR2012b((emlrtCTX)sp, 0, NULL, 0, NULL,
                        (const char_T *)"drawnow", true, location);
}

void MainProcess(const emlrtStack *sp, const char_T ReaStreamIDtag_data[],
                 const int32_T ReaStreamIDtag_size[2],
                 const char_T driverSelection[11],
                 const char_T deviceSelection[7], real_T pbSampSize,
                 boolean_T VariableBufferON)
{
  static const int32_T iv[2] = {1, 25};
  static const int32_T iv1[2] = {1, 40};
  static const int32_T iv2[2] = {1, 30};
  static const int32_T iv3[2] = {1, 33};
  static const int32_T iv4[2] = {1, 41};
  static const int32_T iv5[2] = {1, 19};
  static const int32_T iv6[2] = {1, 49};
  static const int32_T iv7[2] = {1, 19};
  static const int32_T iv8[2] = {1, 30};
  static const int32_T iv9[2] = {1, 36};
  static const char_T g_u[49] = {
      ' ', '-', '-', '-', ' ', 'S', 't', 'o', 'p', ' ', 'L', 'i', 's',
      't', 'e', 'n', 'i', 'n', 'g', ' ', 'f', 'o', 'r', ' ', 'A', 'u',
      'd', 'i', 'o', ' ', 't', 'r', 'a', 'n', 's', 'm', 'i', 's', 's',
      'i', 'o', 'n', 's', '!', ' ', '-', '-', '-', ' '};
  static const char_T e_u[41] = {
      ' ', '+', '+', '+', ' ', 'L', 'i', 's', 't', 'e', 'n', ' ', 'f', 'o',
      'r', ' ', 'A', 'u', 'd', 'i', 'o', ' ', 't', 'r', 'a', 'n', 's', 'm',
      'i', 's', 's', 'i', 'o', 'n', 's', '!', ' ', '+', '+', '+', ' '};
  static const char_T b_u[40] = {
      ' ', '+', '+', '+', ' ', 'U', 'D', 'P', ' ', 'p', 'o', 'r', 't', ' ',
      'o', 'p', 'e', 'n', 'e', 'd', ' ', 'a', 'n', 'd', ' ', 'l', 'i', 's',
      't', 'e', 'n', 'i', 'n', 'g', '!', ' ', '+', '+', '+', ' '};
  static const char_T h_u[36] = {' ', '-', '-', '-', ' ', 'A', 'u', 'd', 'i',
                                 'o', ' ', 'd', 'e', 'v', 'i', 'c', 'e', ' ',
                                 'd', 'i', 's', 'c', 'o', 'n', 'n', 'e', 'c',
                                 't', 'e', 'd', '!', ' ', '-', '-', '-', ' '};
  static const char_T d_u[33] = {' ', '+', '+', '+', ' ', 'A', 'u', 'd', 'i',
                                 'o', ' ', 'd', 'e', 'v', 'i', 'c', 'e', ' ',
                                 'c', 'o', 'n', 'n', 'e', 'c', 't', 'e', 'd',
                                 '!', ' ', '+', '+', '+', ' '};
  static const char_T c_u[30] = {' ', '-', '-', '-', ' ', 'S', 't', 'o',
                                 'p', ' ', 'l', 'i', 's', 't', 'e', 'n',
                                 'i', 'n', 'g', ' ', 'p', 'o', 'r', 't',
                                 '!', ' ', '-', '-', '-', ' '};
  static const char_T u[25] = {' ', '+', '+', '+', ' ', 'S', 'e', 't', 't',
                               'i', 'n', 'g', 's', ' ', 'R', 'e', 'a', 'd',
                               'y', '!', ' ', '+', '+', '+', ' '};
  static const char_T f_u[19] = {'U', 'D', 'P', ' ', 'b', 'u', 'f',
                                 'f', 'e', 'r', ' ', 'f', 'l', 'u',
                                 's', 'h', 'e', 'd', '!'};
  static const char_T obj_frameStart[4] = {'M', 'R', 'S', 'R'};
  audioDeviceWriter lobj_0;
  audioDeviceWriter *obj_deviceWriter;
  c_audiointerface_audioDeviceWri *obj;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  emxArray_int32_T *r;
  emxArray_real32_T *b_playbackBuffer;
  emxArray_real32_T *playbackBuffer;
  emxArray_real32_T *testFrame_audioFrameBuff;
  const mxArray *b_y;
  const mxArray *c_y;
  const mxArray *d_y;
  const mxArray *e_y;
  const mxArray *f_y;
  const mxArray *g_y;
  const mxArray *h_y;
  const mxArray *i_y;
  const mxArray *j_y;
  const mxArray *m;
  const mxArray *y;
  real_T STATE_FLAG_NEEDED;
  real_T b_expl_temp;
  real_T c_expl_temp;
  real_T d_expl_temp;
  real_T e_expl_temp;
  real_T expl_temp;
  real_T testFrame_SampleRate;
  int32_T expl_temp_size[2];
  int32_T b_i;
  int32_T exitg1;
  int32_T i1;
  int32_T input_sizes_idx_0;
  int32_T result;
  int32_T sizes_idx_0;
  char_T expl_temp_data[32];
  char_T *sErr;
  boolean_T empty_non_axis_sizes;
  boolean_T exitg2;
  boolean_T guard1 = false;
  (void)driverSelection;
  (void)deviceSelection;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  emxInit_real32_T(sp, &testFrame_audioFrameBuff, 2, &u_emlrtRTEI, true);
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  st.site = NULL;
  obj = &lobj_0.pInterface;
  obj->S0_isInitialized = 0;
  emlrtPushHeapReferenceStackR2021a((emlrtCTX)sp, true, &lobj_0,
                                    (void *)&handle_matlabCodegenDestructor,
                                    NULL, NULL, NULL);
  lobj_0.matlabCodegenIsDeleted = true;
  /*  function MainProcess() */
  /*  Main Process Script */
  /*     %% Settings and Properties */
  /*  Main loop interupt */
  /*  Global interupt flag */
  st.site = &emlrtRSI;
  /*  Settings and Properties               */
  /*  Connection Properties */
  /*  Default */
  /*  Default */
  /*  UDP handle */
  /*  Reastream ID tag */
  /*  Default */
  /*  Audio settings */
  /*  Default */
  /*  Default */
  /*  Default */
  /*  Buffer size */
  /*  Default */
  /*  Default */
  /*  Device Writer Handle */
  b_st.site = &k_emlrtRSI;
  obj_deviceWriter = c_audioDeviceWriter_audioDevice(&lobj_0);
  /*  Operation Flags ENUMERATION */
  /*  Main Processing state */
  /*  Interupt flag to exit the main loop */
  /*  Flag to skip frame */
  /*  Flag to indicate no no transmission */
  /*  Debug and interface */
  y = NULL;
  m = emlrtCreateCharArray(2, &iv[0]);
  emlrtInitCharArrayR2013a((emlrtCTX)sp, 25, m, &u[0]);
  emlrtAssign(&y, m);
  st.site = &md_emlrtRSI;
  disp(&st, y, &emlrtMCI);
  /*      disp(obj); */
  /*     %% Setup UPD connection    */
  st.site = &j_emlrtRSI;
  /*  function [obj] = connectReceiverUDP(obj) */
  /*  Setup UPD connection */
  b_y = NULL;
  m = emlrtCreateCharArray(2, &iv1[0]);
  emlrtInitCharArrayR2013a(&st, 40, m, &b_u[0]);
  emlrtAssign(&b_y, m);
  b_st.site = &ld_emlrtRSI;
  disp(&b_st, b_y, &f_emlrtMCI);
  /*     %% Setup the audio device with default settings */
  /*  Check and listen for Frames */
  st.site = &i_emlrtRSI;
  readReaStreameFrame(&st, ReaStreamIDtag_data, ReaStreamIDtag_size,
                      obj_frameStart, &expl_temp, expl_temp_data,
                      expl_temp_size, &b_expl_temp, &testFrame_SampleRate,
                      &c_expl_temp, &d_expl_temp, &e_expl_temp,
                      testFrame_audioFrameBuff, &STATE_FLAG_NEEDED);
  emxInit_real32_T(sp, &playbackBuffer, 2, &v_emlrtRTEI, true);
  emxInit_real32_T(sp, &b_playbackBuffer, 2, &q_emlrtRTEI, true);
  emxInit_int32_T(sp, &r, 2, &t_emlrtRTEI, true);
  do {
    exitg1 = 0;
    if (STATE_FLAG_NEEDED != 1.0) {
      st.site = &h_emlrtRSI;
      readReaStreameFrame(&st, ReaStreamIDtag_data, ReaStreamIDtag_size,
                          obj_frameStart, &expl_temp, expl_temp_data,
                          expl_temp_size, &b_expl_temp, &testFrame_SampleRate,
                          &c_expl_temp, &d_expl_temp, &e_expl_temp,
                          testFrame_audioFrameBuff, &STATE_FLAG_NEEDED);
      st.site = &nd_emlrtRSI;
      drawnow(&st, &b_emlrtMCI);
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b((emlrtCTX)sp);
      }
      if (!STATE_IN_LOOP_FLAG_) {
        st.site = &g_emlrtRSI;
        /*  Clear the UDP object */
        c_y = NULL;
        m = emlrtCreateCharArray(2, &iv2[0]);
        emlrtInitCharArrayR2013a(&st, 30, m, &c_u[0]);
        emlrtAssign(&c_y, m);
        b_st.site = &fd_emlrtRSI;
        disp(&b_st, c_y, &g_emlrtMCI);
        exitg1 = 1;
      }
    } else {
      /*  Setup Audio Device Based on the header */
      st.site = &f_emlrtRSI;
      /*  function [obj] = SetupAudioDevice(obj) */
      /*      % Setup Audio Device Based on the header */
      /*      if not(obj.AUDIO_DEVICE_READY_FLAG) */
      /*   */
      /*      % Setup Audio device */
      /*      obj.deviceWriter = audioDeviceWriter(... */
      /*          'Driver',obj.driverSelection,... */
      /*          'Device',obj.deviceSelection,... */
      /*          'SampleRate',obj.SampleRate,... */
      /*          'BitDepth',obj.bitDepthStrings{obj.ByteDepth},... */
      /*          'BufferSize',obj.pbSampSize,... */
      /*          'SupportVariableSizeInput',obj.VariableBufferON); */
      /*   */
      /*          % Display */
      /*          disp(' +++ Audio device connected! +++ '); */
      /*          disp(obj.deviceWriter); */
      /*   */
      /*          % Done */
      /*          obj.AUDIO_DEVICE_READY_FLAG = true; */
      /*      end */
      /*  end */
      /* obj.driverSelection */
      /* deviceSelection.deviceSelection */
      /* obj.SampleRate */
      /* obj.bitDepthStrings{obj.ByteDepth} */
      /*  Setup Audio Device Based on the header */
      /*  Setup Audio device */
      /*          obj.deviceWriter.Driver = 'DirectSound'; */
      /*          obj.deviceWriter.Device = deviceSelection_; */
      /*          obj.deviceWriter.SampleRate = SampleRate_; */
      /*          obj.deviceWriter.BitDepth =
       * bitDepthStrings_;%Settings.ByteDepth */
      /*          obj.deviceWriter.BufferSize = pbSampSize_; */
      /*          obj.deviceWriter.SupportVariableSizeInput =
       * SupportVariableSizeInput_; */
      /*          Settings.deviceWriter = deviceWriter; */
      /*  Done */
      /*  Display */
      d_y = NULL;
      m = emlrtCreateCharArray(2, &iv3[0]);
      emlrtInitCharArrayR2013a(&st, 33, m, &d_u[0]);
      emlrtAssign(&d_y, m);
      b_st.site = &kd_emlrtRSI;
      disp(&b_st, d_y, &h_emlrtMCI);
      /*          disp(Settings.deviceWriter);        */
      /*  Check if audio device is available */
      /*     %% Run Decode and Playback Loop */
      e_y = NULL;
      m = emlrtCreateCharArray(2, &iv4[0]);
      emlrtInitCharArrayR2013a((emlrtCTX)sp, 41, m, &e_u[0]);
      emlrtAssign(&e_y, m);
      st.site = &jd_emlrtRSI;
      disp(&st, e_y, &c_emlrtMCI);
      /*  profile on */
      st.site = &e_emlrtRSI;
      /*  function  [obj] = decodePlaybackLoop(obj) */
      /*  Unpack ReaStream Frame and Play Audio */
      /*  Control Flags */
      /*  Global interupt flag */
      FLUSH_UDP_BUFFER_FLAG_ = false;
      FLUSH_UDP_BUFFER_FLAG__dirty |= 1U;
      STATE_FLAG_NEEDED = 1.0;
      /*  Playback Settings */
      playbackBuffer->size[0] = 0;
      playbackBuffer->size[1] = 0;
      /*  Clear the UDP buffer before starting to decode */
      b_st.site = &mc_emlrtRSI;
      f_y = NULL;
      m = emlrtCreateCharArray(2, &iv5[0]);
      emlrtInitCharArrayR2013a(&b_st, 19, m, &f_u[0]);
      emlrtAssign(&f_y, m);
      c_st.site = &id_emlrtRSI;
      disp(&c_st, f_y, &i_emlrtMCI);
      /*  Frame count */
      /*  Loop */
      exitg2 = false;
      while ((!exitg2) &&
             (STATE_IN_LOOP_FLAG_ && (!(STATE_FLAG_NEEDED == 0.0)))) {
        /*  External and Internal interupt flags */
        /*  Read reastream frame */
        b_st.site = &lc_emlrtRSI;
        readReaStreameFrame(&b_st, ReaStreamIDtag_data, ReaStreamIDtag_size,
                            obj_frameStart, &expl_temp, expl_temp_data,
                            expl_temp_size, &b_expl_temp, &testFrame_SampleRate,
                            &c_expl_temp, &d_expl_temp, &e_expl_temp,
                            testFrame_audioFrameBuff, &STATE_FLAG_NEEDED);
        /*  This will force update the UI but not unless there is normal */
        /*  transmission frames */
        /*  Control logic Check flags */
        guard1 = false;
        if ((STATE_FLAG_NEEDED == 2.0) || (STATE_FLAG_NEEDED == -1.0)) {
          guard1 = true;
        } else {
          if (FLUSH_UDP_BUFFER_FLAG_) {
            b_st.site = &kc_emlrtRSI;
            h_y = NULL;
            m = emlrtCreateCharArray(2, &iv7[0]);
            emlrtInitCharArrayR2013a(&b_st, 19, m, &f_u[0]);
            emlrtAssign(&h_y, m);
            c_st.site = &id_emlrtRSI;
            disp(&c_st, h_y, &i_emlrtMCI);
            FLUSH_UDP_BUFFER_FLAG_ = false;
            FLUSH_UDP_BUFFER_FLAG__dirty |= 1U;
          }
          /*  External interupt switch! */
          if (!STATE_IN_LOOP_FLAG_) {
            exitg2 = true;
          } else {
            /*   IGNORE+++START */
            /*   IGNORE+++END */
            /*  Sent to Device with variable size bufffer */
            if (VariableBufferON) {
              b_st.site = &jc_emlrtRSI;
              c_st.site = &o_emlrtRSI;
              SystemCore_step(&c_st, obj_deviceWriter,
                              testFrame_audioFrameBuff);
            } else {
              /*  Reset the buffer size if the channel number changes */
              if (playbackBuffer->size[1] !=
                  testFrame_audioFrameBuff->size[1]) {
                playbackBuffer->size[0] = 0;
                playbackBuffer->size[1] = 0;
              }
              /*  Add to buffer */
              b_st.site = &ic_emlrtRSI;
              c_st.site = &nc_emlrtRSI;
              if ((playbackBuffer->size[0] != 0) &&
                  (playbackBuffer->size[1] != 0)) {
                result = playbackBuffer->size[1];
              } else if ((testFrame_audioFrameBuff->size[0] != 0) &&
                         (testFrame_audioFrameBuff->size[1] != 0)) {
                result = testFrame_audioFrameBuff->size[1];
              } else {
                if (playbackBuffer->size[1] > 0) {
                  result = playbackBuffer->size[1];
                } else {
                  result = 0;
                }
                if (testFrame_audioFrameBuff->size[1] > result) {
                  result = testFrame_audioFrameBuff->size[1];
                }
              }
              d_st.site = &oc_emlrtRSI;
              if ((playbackBuffer->size[1] != result) &&
                  ((playbackBuffer->size[0] != 0) &&
                   (playbackBuffer->size[1] != 0))) {
                emlrtErrorWithMessageIdR2018a(
                    &d_st, &emlrtRTEI,
                    "MATLAB:catenate:matrixDimensionMismatch",
                    "MATLAB:catenate:matrixDimensionMismatch", 0);
              }
              if ((testFrame_audioFrameBuff->size[1] != result) &&
                  ((testFrame_audioFrameBuff->size[0] != 0) &&
                   (testFrame_audioFrameBuff->size[1] != 0))) {
                emlrtErrorWithMessageIdR2018a(
                    &d_st, &emlrtRTEI,
                    "MATLAB:catenate:matrixDimensionMismatch",
                    "MATLAB:catenate:matrixDimensionMismatch", 0);
              }
              if (result == 0) {
                empty_non_axis_sizes = true;
                input_sizes_idx_0 = playbackBuffer->size[0];
              } else {
                empty_non_axis_sizes = false;
                if ((playbackBuffer->size[0] != 0) &&
                    (playbackBuffer->size[1] != 0)) {
                  input_sizes_idx_0 = playbackBuffer->size[0];
                } else {
                  input_sizes_idx_0 = 0;
                }
              }
              if (empty_non_axis_sizes ||
                  ((testFrame_audioFrameBuff->size[0] != 0) &&
                   (testFrame_audioFrameBuff->size[1] != 0))) {
                sizes_idx_0 = testFrame_audioFrameBuff->size[0];
              } else {
                sizes_idx_0 = 0;
              }
              b_i = b_playbackBuffer->size[0] * b_playbackBuffer->size[1];
              b_playbackBuffer->size[0] = input_sizes_idx_0 + sizes_idx_0;
              b_playbackBuffer->size[1] = result;
              emxEnsureCapacity_real32_T(&c_st, b_playbackBuffer, b_i,
                                         &q_emlrtRTEI);
              for (b_i = 0; b_i < result; b_i++) {
                for (i1 = 0; i1 < input_sizes_idx_0; i1++) {
                  b_playbackBuffer->data[i1 + b_playbackBuffer->size[0] * b_i] =
                      playbackBuffer->data[i1 + input_sizes_idx_0 * b_i];
                }
              }
              for (b_i = 0; b_i < result; b_i++) {
                for (i1 = 0; i1 < sizes_idx_0; i1++) {
                  b_playbackBuffer->data[(i1 + input_sizes_idx_0) +
                                         b_playbackBuffer->size[0] * b_i] =
                      testFrame_audioFrameBuff->data[i1 + sizes_idx_0 * b_i];
                }
              }
              b_i = playbackBuffer->size[0] * playbackBuffer->size[1];
              playbackBuffer->size[0] = b_playbackBuffer->size[0];
              playbackBuffer->size[1] = b_playbackBuffer->size[1];
              emxEnsureCapacity_real32_T(&c_st, playbackBuffer, b_i,
                                         &r_emlrtRTEI);
              result = b_playbackBuffer->size[0] * b_playbackBuffer->size[1];
              for (b_i = 0; b_i < result; b_i++) {
                playbackBuffer->data[b_i] = b_playbackBuffer->data[b_i];
              }
              /*  Sent to Device with fixed size bufffer */
              if (playbackBuffer->size[0] >= pbSampSize) {
                if (1.0 > pbSampSize) {
                  result = 0;
                } else {
                  if (1 > playbackBuffer->size[0]) {
                    emlrtDynamicBoundsCheckR2012b(1, 1, playbackBuffer->size[0],
                                                  &b_emlrtBCI, &st);
                  }
                  if (pbSampSize != muDoubleScalarFloor(pbSampSize)) {
                    emlrtIntegerCheckR2012b(pbSampSize, &emlrtDCI, &st);
                  }
                  if ((int32_T)pbSampSize > playbackBuffer->size[0]) {
                    emlrtDynamicBoundsCheckR2012b((int32_T)pbSampSize, 1,
                                                  playbackBuffer->size[0],
                                                  &emlrtBCI, &st);
                  }
                  result = (int32_T)pbSampSize;
                }
                b_st.site = &hc_emlrtRSI;
                input_sizes_idx_0 = playbackBuffer->size[1];
                b_i = b_playbackBuffer->size[0] * b_playbackBuffer->size[1];
                b_playbackBuffer->size[0] = result;
                b_playbackBuffer->size[1] = playbackBuffer->size[1];
                emxEnsureCapacity_real32_T(&b_st, b_playbackBuffer, b_i,
                                           &s_emlrtRTEI);
                for (b_i = 0; b_i < input_sizes_idx_0; b_i++) {
                  for (i1 = 0; i1 < result; i1++) {
                    b_playbackBuffer
                        ->data[i1 + b_playbackBuffer->size[0] * b_i] =
                        playbackBuffer
                            ->data[i1 + playbackBuffer->size[0] * b_i];
                  }
                }
                c_st.site = &pc_emlrtRSI;
                b_SystemCore_step(&c_st, obj_deviceWriter, b_playbackBuffer);
                b_i = r->size[0] * r->size[1];
                r->size[0] = 1;
                result = (int32_T)muDoubleScalarFloor(pbSampSize - 1.0);
                r->size[1] = result + 1;
                emxEnsureCapacity_int32_T(&st, r, b_i, &t_emlrtRTEI);
                for (b_i = 0; b_i <= result; b_i++) {
                  r->data[b_i] = b_i + 1;
                }
                b_st.site = &gc_emlrtRSI;
                nullAssignment(&b_st, playbackBuffer, r);
              }
            }
            /*  Debug %  IGNORE+++START */
            /*   IGNORE+++END */
            /*  Increment frame only when the whole routine is complete */
            guard1 = true;
          }
        }
        if (guard1 && (*emlrtBreakCheckR2012bFlagVar != 0)) {
          emlrtBreakCheckR2012b(&st);
        }
      }
      /*  profile off */
      /*  profile viewer */
      g_y = NULL;
      m = emlrtCreateCharArray(2, &iv6[0]);
      emlrtInitCharArrayR2013a((emlrtCTX)sp, 49, m, &g_u[0]);
      emlrtAssign(&g_y, m);
      st.site = &hd_emlrtRSI;
      disp(&st, g_y, &d_emlrtMCI);
      /*     %% Release UDP & audio device and hide debug settings */
      /*  Clear the UDP connection */
      st.site = &d_emlrtRSI;
      /*  Clear the UDP object */
      i_y = NULL;
      m = emlrtCreateCharArray(2, &iv8[0]);
      emlrtInitCharArrayR2013a(&st, 30, m, &c_u[0]);
      emlrtAssign(&i_y, m);
      b_st.site = &fd_emlrtRSI;
      disp(&b_st, i_y, &g_emlrtMCI);
      /*  Release the audio device */
      j_y = NULL;
      m = emlrtCreateCharArray(2, &iv9[0]);
      emlrtInitCharArrayR2013a((emlrtCTX)sp, 36, m, &h_u[0]);
      emlrtAssign(&j_y, m);
      st.site = &gd_emlrtRSI;
      disp(&st, j_y, &e_emlrtMCI);
      st.site = &c_emlrtRSI;
      SystemCore_release(obj_deviceWriter);
      exitg1 = 1;
    }
  } while (exitg1 == 0);
  emxFree_int32_T(&r);
  emxFree_real32_T(&b_playbackBuffer);
  emxFree_real32_T(&playbackBuffer);
  emxFree_real32_T(&testFrame_audioFrameBuff);
  st.site = &b_emlrtRSI;
  handle_matlabCodegenDestructor(&st, &lobj_0);
  st.site = &b_emlrtRSI;
  obj = &lobj_0.pInterface;
  /* System object Destructor function: audiointerface.audioDeviceWriter */
  if (obj->S0_isInitialized == 1) {
    obj->S0_isInitialized = 2;
    b_st.site = NULL;
    /* System object Terminate function: audiointerface.audioDeviceWriter */
    sErr = GetErrorBuffer(&obj->W0_AudioDeviceLib[0U]);
    LibTerminate(&obj->W0_AudioDeviceLib[0U]);
    if (*sErr != 0) {
      PrintError(sErr);
    }
    LibDestroy_Audio(&obj->W0_AudioDeviceLib[0U], 1, 1);
    DestroyHostLibrary(&obj->W0_AudioDeviceLib[0U]);
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

/* End of code generation (MainProcess.c) */
