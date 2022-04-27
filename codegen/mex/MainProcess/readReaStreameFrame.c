/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * readReaStreameFrame.c
 *
 * Code generation for function 'readReaStreameFrame'
 *
 */

/* Include files */
#include "readReaStreameFrame.h"
#include "MainProcess_data.h"
#include "MainProcess_emxutil.h"
#include "MainProcess_types.h"
#include "rt_nonfinite.h"
#include "strcmp.h"
#include "strtrim.h"
#include "tic.h"
#include "toc.h"
#include "DAHostLib_rtw.h"
#include "HostLib_Audio.h"
#include "emlrt.h"
#include "mwmathutil.h"
#include <stddef.h>
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo p_emlrtRSI = {
    12,                    /* lineNo */
    "readReaStreameFrame", /* fcnName */
    "C:\\Users\\JessyJP\\Dropbox\\Projects Workfiles & Software\\ReaStream "
    "Android Reciever\\readReaStreameFrame.m" /* pathName */
};

static emlrtRSInfo q_emlrtRSI = {
    14,                    /* lineNo */
    "readReaStreameFrame", /* fcnName */
    "C:\\Users\\JessyJP\\Dropbox\\Projects Workfiles & Software\\ReaStream "
    "Android Reciever\\readReaStreameFrame.m" /* pathName */
};

static emlrtRSInfo r_emlrtRSI = {
    25,                    /* lineNo */
    "readReaStreameFrame", /* fcnName */
    "C:\\Users\\JessyJP\\Dropbox\\Projects Workfiles & Software\\ReaStream "
    "Android Reciever\\readReaStreameFrame.m" /* pathName */
};

static emlrtRSInfo s_emlrtRSI = {
    27,                    /* lineNo */
    "readReaStreameFrame", /* fcnName */
    "C:\\Users\\JessyJP\\Dropbox\\Projects Workfiles & Software\\ReaStream "
    "Android Reciever\\readReaStreameFrame.m" /* pathName */
};

static emlrtRSInfo t_emlrtRSI = {
    35,                    /* lineNo */
    "readReaStreameFrame", /* fcnName */
    "C:\\Users\\JessyJP\\Dropbox\\Projects Workfiles & Software\\ReaStream "
    "Android Reciever\\readReaStreameFrame.m" /* pathName */
};

static emlrtRSInfo u_emlrtRSI = {
    38,                    /* lineNo */
    "readReaStreameFrame", /* fcnName */
    "C:\\Users\\JessyJP\\Dropbox\\Projects Workfiles & Software\\ReaStream "
    "Android Reciever\\readReaStreameFrame.m" /* pathName */
};

static emlrtRSInfo v_emlrtRSI = {
    41,                    /* lineNo */
    "readReaStreameFrame", /* fcnName */
    "C:\\Users\\JessyJP\\Dropbox\\Projects Workfiles & Software\\ReaStream "
    "Android Reciever\\readReaStreameFrame.m" /* pathName */
};

static emlrtRSInfo w_emlrtRSI = {
    45,                    /* lineNo */
    "readReaStreameFrame", /* fcnName */
    "C:\\Users\\JessyJP\\Dropbox\\Projects Workfiles & Software\\ReaStream "
    "Android Reciever\\readReaStreameFrame.m" /* pathName */
};

static emlrtRSInfo x_emlrtRSI = {
    52,                    /* lineNo */
    "readReaStreameFrame", /* fcnName */
    "C:\\Users\\JessyJP\\Dropbox\\Projects Workfiles & Software\\ReaStream "
    "Android Reciever\\readReaStreameFrame.m" /* pathName */
};

static emlrtRSInfo y_emlrtRSI = {
    53,                    /* lineNo */
    "readReaStreameFrame", /* fcnName */
    "C:\\Users\\JessyJP\\Dropbox\\Projects Workfiles & Software\\ReaStream "
    "Android Reciever\\readReaStreameFrame.m" /* pathName */
};

static emlrtRSInfo eb_emlrtRSI = {
    54,              /* lineNo */
    "readUDPbuffer", /* fcnName */
    "C:\\Users\\JessyJP\\Dropbox\\Projects Workfiles & Software\\ReaStream "
    "Android Reciever\\readUDPbuffer.m" /* pathName */
};

static emlrtRSInfo jb_emlrtRSI = {
    56,                     /* lineNo */
    "rsFrameHeader2Struct", /* fcnName */
    "C:\\Users\\JessyJP\\Dropbox\\Projects Workfiles & Software\\ReaStream "
    "Android Reciever\\rsFrameHeader2Struct.m" /* pathName */
};

static emlrtRSInfo kb_emlrtRSI = {
    61,                     /* lineNo */
    "rsFrameHeader2Struct", /* fcnName */
    "C:\\Users\\JessyJP\\Dropbox\\Projects Workfiles & Software\\ReaStream "
    "Android Reciever\\rsFrameHeader2Struct.m" /* pathName */
};

static emlrtRSInfo dc_emlrtRSI = {
    56,              /* lineNo */
    "readUDPbuffer", /* fcnName */
    "C:\\Users\\JessyJP\\Dropbox\\Projects Workfiles & Software\\ReaStream "
    "Android Reciever\\readUDPbuffer.m" /* pathName */
};

static emlrtRSInfo ec_emlrtRSI = {
    29,                  /* lineNo */
    "reshapeSizeChecks", /* fcnName */
    "D:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\reshapeSizeChecks.m" /* pathName */
};

static emlrtRTEInfo b_emlrtRTEI = {
    116,               /* lineNo */
    9,                 /* colNo */
    "computeDimsData", /* fName */
    "D:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\reshapeSizeChecks.m" /* pName */
};

static emlrtRTEInfo c_emlrtRTEI =
    {
        62,         /* lineNo */
        25,         /* colNo */
        "typecast", /* fName */
        "D:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\datatypes\\typecast."
        "m" /* pName */
};

static emlrtRTEInfo d_emlrtRTEI = {
    59,                  /* lineNo */
    23,                  /* colNo */
    "reshapeSizeChecks", /* fName */
    "D:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\reshapeSizeChecks.m" /* pName */
};

static emlrtRTEInfo e_emlrtRTEI = {
    52,                  /* lineNo */
    13,                  /* colNo */
    "reshapeSizeChecks", /* fName */
    "D:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\reshapeSizeChecks.m" /* pName */
};

static emlrtBCInfo c_emlrtBCI = {
    1,               /* iFirst */
    14756238,        /* iLast */
    54,              /* lineNo */
    49,              /* colNo */
    "output_",       /* aName */
    "readUDPbuffer", /* fName */
    "C:\\Users\\JessyJP\\Dropbox\\Projects Workfiles & Software\\ReaStream "
    "Android Reciever\\readUDPbuffer.m", /* pName */
    0                                    /* checkKind */
};

static emlrtDCInfo b_emlrtDCI = {
    54,              /* lineNo */
    49,              /* colNo */
    "readUDPbuffer", /* fName */
    "C:\\Users\\JessyJP\\Dropbox\\Projects Workfiles & Software\\ReaStream "
    "Android Reciever\\readUDPbuffer.m", /* pName */
    1                                    /* checkKind */
};

static emlrtBCInfo d_emlrtBCI = {
    1,               /* iFirst */
    14756238,        /* iLast */
    56,              /* lineNo */
    49,              /* colNo */
    "output_",       /* aName */
    "readUDPbuffer", /* fName */
    "C:\\Users\\JessyJP\\Dropbox\\Projects Workfiles & Software\\ReaStream "
    "Android Reciever\\readUDPbuffer.m", /* pName */
    0                                    /* checkKind */
};

static emlrtDCInfo c_emlrtDCI = {
    56,              /* lineNo */
    49,              /* colNo */
    "readUDPbuffer", /* fName */
    "C:\\Users\\JessyJP\\Dropbox\\Projects Workfiles & Software\\ReaStream "
    "Android Reciever\\readUDPbuffer.m", /* pName */
    1                                    /* checkKind */
};

static emlrtBCInfo e_emlrtBCI = {
    1,                      /* iFirst */
    43,                     /* iLast */
    61,                     /* lineNo */
    43,                     /* colNo */
    "F",                    /* aName */
    "rsFrameHeader2Struct", /* fName */
    "C:\\Users\\JessyJP\\Dropbox\\Projects Workfiles & Software\\ReaStream "
    "Android Reciever\\rsFrameHeader2Struct.m", /* pName */
    0                                           /* checkKind */
};

static emlrtBCInfo f_emlrtBCI = {
    1,                      /* iFirst */
    43,                     /* iLast */
    56,                     /* lineNo */
    39,                     /* colNo */
    "F",                    /* aName */
    "rsFrameHeader2Struct", /* fName */
    "C:\\Users\\JessyJP\\Dropbox\\Projects Workfiles & Software\\ReaStream "
    "Android Reciever\\rsFrameHeader2Struct.m", /* pName */
    0                                           /* checkKind */
};

static emlrtRTEInfo w_emlrtRTEI =
    {
        28,      /* lineNo */
        9,       /* colNo */
        "colon", /* fName */
        "D:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\ops\\colon.m" /* pName
                                                                          */
};

static emlrtRTEInfo x_emlrtRTEI = {
    53,                    /* lineNo */
    5,                     /* colNo */
    "readReaStreameFrame", /* fName */
    "C:\\Users\\JessyJP\\Dropbox\\Projects Workfiles & Software\\ReaStream "
    "Android Reciever\\readReaStreameFrame.m" /* pName */
};

static emlrtRTEInfo y_emlrtRTEI = {
    56,              /* lineNo */
    51,              /* colNo */
    "readUDPbuffer", /* fName */
    "C:\\Users\\JessyJP\\Dropbox\\Projects Workfiles & Software\\ReaStream "
    "Android Reciever\\readUDPbuffer.m" /* pName */
};

/* Function Definitions */
void readReaStreameFrame(
    const emlrtStack *sp, const char_T obj_ReaStreamIDtag_data[],
    const int32_T obj_ReaStreamIDtag_size[2], const char_T obj_frameStart[4],
    real_T *audioFrame_udpPayLoadBytes, char_T audioFrame_streamName_data[],
    int32_T audioFrame_streamName_size[2], real_T *audioFrame_numChannels,
    real_T *audioFrame_SampleRate, real_T *audioFrame_audioByteLength,
    real_T *audioFrame_bufferSize, real_T *audioFrame_timeLenght,
    emxArray_real32_T *audioFrame_audioFrameBuff, real_T *STATE_FLAG_)
{
  static const char_T b_b[4] = {'M', 'R', 'S', 'R'};
  emlrtStack b_st;
  emlrtStack st;
  emlrtTimespec expl_temp;
  emxArray_uint16_T *y;
  real_T S_bufferSize;
  real_T b;
  real_T byteSize;
  int32_T tmp_size[2];
  int32_T S_numChannels_tmp_tmp;
  int32_T b_STATE_FLAG_;
  int32_T b_i;
  int32_T calclen;
  int32_T exitg1;
  int32_T exitg2;
  int32_T ny;
  int32_T ret;
  real32_T y_data[16383];
  uint32_T b_y;
  uint32_T c_y;
  int16_T x_size_idx_1;
  uint16_T d_y;
  char_T b_tmp_data[13];
  char_T ID[4];
  int8_T tmp_data[32];
  uint8_T b_x_data[65535];
  uint8_T frameHeader[43];
  uint8_T x[43];
  uint8_T streamName[32];
  uint8_T tag_data[4];
  uint8_T x_data[4];
  uint8_T b_x[2];
  uint8_T u;
  boolean_T b_bool;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  /*  function [audioFrame,STATE_FLAG_] = readReaStreameFrame(obj) */
  /*  Default output */
  /*      audioFrame = [];% Get Empty frame   */
  /*  Default output state */
  b_STATE_FLAG_ = 1;
  /*  Locate 'MRSR' */
  st.site = &p_emlrtRSI;
  expl_temp = tic(&st);
  emxInit_uint16_T(sp, &y, 2, &y_emlrtRTEI, true);
  do {
    exitg1 = 0;
    st.site = &q_emlrtRSI;
    /*  function [output] = readUDPbuffer(obj,byteSize,type) */
    /*  Global Declaration FOR RECORD AND PLAYBACK */
    /*     %% The actual code needed */
    /*     %% For testing */
    /*  FOR TESTING for recording data */
    /*  For reading back data  */
    if (i + 4.0 > 2.9512476E+6) {
      i = 0.0;
      i_dirty |= 1U;
      STATE_IN_LOOP_FLAG_ = false;
      STATE_IN_LOOP_FLAG__dirty |= 1U;
    }
    b_st.site = &eb_emlrtRSI;
    b = i + 1.0;
    if (i + 1.0 != (int32_T)muDoubleScalarFloor(i + 1.0)) {
      emlrtIntegerCheckR2012b(b, &b_emlrtDCI, &b_st);
    }
    if (((int32_T)(i + 1.0) < 1) || ((int32_T)(i + 1.0) > 14756238)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)b, 1, 14756238, &c_emlrtBCI,
                                    &b_st);
    }
    x_data[0] = output_[(int32_T)(i + 1.0) - 1];
    b = i + 2.0;
    if (i + 2.0 != (int32_T)muDoubleScalarFloor(i + 2.0)) {
      emlrtIntegerCheckR2012b(b, &b_emlrtDCI, &b_st);
    }
    if (((int32_T)(i + 2.0) < 1) || ((int32_T)(i + 2.0) > 14756238)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)b, 1, 14756238, &c_emlrtBCI,
                                    &b_st);
    }
    x_data[1] = output_[(int32_T)(i + 2.0) - 1];
    b = i + 3.0;
    if (i + 3.0 != (int32_T)muDoubleScalarFloor(i + 3.0)) {
      emlrtIntegerCheckR2012b(b, &b_emlrtDCI, &b_st);
    }
    if (((int32_T)(i + 3.0) < 1) || ((int32_T)(i + 3.0) > 14756238)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)b, 1, 14756238, &c_emlrtBCI,
                                    &b_st);
    }
    x_data[2] = output_[(int32_T)(i + 3.0) - 1];
    b = i + 4.0;
    if (i + 4.0 != (int32_T)muDoubleScalarFloor(i + 4.0)) {
      emlrtIntegerCheckR2012b(b, &b_emlrtDCI, &b_st);
    }
    if (((int32_T)(i + 4.0) < 1) || ((int32_T)(i + 4.0) > 14756238)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)b, 1, 14756238, &c_emlrtBCI,
                                    &b_st);
    }
    x_data[3] = output_[(int32_T)(i + 4.0) - 1];
    memcpy((void *)&tag_data[0], (void *)&x_data[0],
           (uint32_T)((size_t)4 * sizeof(uint8_T)));
    i += 4.0;
    i_dirty |= 1U;
    /*  Add the numder of bytes read */
    /*  If a frame is located */
    ID[0] = (int8_T)tag_data[0];
    ID[1] = (int8_T)tag_data[1];
    ID[2] = (int8_T)tag_data[2];
    ID[3] = (int8_T)tag_data[3];
    b_bool = false;
    ret = 0;
    do {
      exitg2 = 0;
      if (ret < 4) {
        if (obj_frameStart[ret] != ID[ret]) {
          exitg2 = 1;
        } else {
          ret++;
        }
      } else {
        b_bool = true;
        exitg2 = 1;
      }
    } while (exitg2 == 0);
    if (b_bool) {
      /*  Read header */
      /*  remove 4 bytes frameID bytes becuase it was located earlier */
      st.site = &t_emlrtRSI;
      /*  function [output] = readUDPbuffer(obj,byteSize,type) */
      /*  Global Declaration FOR RECORD AND PLAYBACK */
      /*     %% The actual code needed */
      /*     %% For testing */
      /*  FOR TESTING for recording data */
      /*  For reading back data  */
      if (i + 43.0 > 2.9512476E+6) {
        i = 0.0;
        i_dirty |= 1U;
        STATE_IN_LOOP_FLAG_ = false;
        STATE_IN_LOOP_FLAG__dirty |= 1U;
      }
      b_st.site = &eb_emlrtRSI;
      for (ny = 0; ny < 43; ny++) {
        b = i + ((real_T)ny + 1.0);
        if (b != (int32_T)muDoubleScalarFloor(b)) {
          emlrtIntegerCheckR2012b(b, &b_emlrtDCI, &b_st);
        }
        if (((int32_T)b < 1) || ((int32_T)b > 14756238)) {
          emlrtDynamicBoundsCheckR2012b((int32_T)b, 1, 14756238, &c_emlrtBCI,
                                        &b_st);
        }
        x[ny] = output_[(int32_T)b - 1];
      }
      memcpy((void *)&frameHeader[0], (void *)&x[0],
             (uint32_T)((size_t)43 * sizeof(uint8_T)));
      i += 43.0;
      i_dirty |= 1U;
      /*  Make Sure the "frameHeader" not stored as double */
      /*  Add the numder of bytes read */
      st.site = &u_emlrtRSI;
      /*  function [S,i] = rsFrameHeader2Struct(F) */
      /*  Unpack ReaStream Frame Header to a Structure */
      /*  The input is expected as uint8 byte stream */
      /*  */
      /*      typedef struct ReaStream */
      /*      { */
      /*      char ID[4]; // 'MRSR' tag for every packet like an ID (4 bytes) */
      /*      unsigned int packetSize; // size of the entire UDP packet (4
       * bytes) */
      /*      char name[32]; // Name of the stream (ie: default on the plugin)
       * (32 bytes) */
      /*      unsigned int nbChan; // the number of channels the plugin sends (1
       * byte) */
      /*      unsigned int freq; // the rate Frequency of the data (44100,
       * 48000, ...) (4 bytes) */
      /*      unsigned datasSize; // size of the following bytes to read. (2
       * bytes) */
      /*      float *datas; // start of the audio datas (variable get from
       * "datasSize") */
      /*      } ReaStream; */
      /*  Frame Output template */
      /*  ID (4 bytes) */
      ID[0] = (int8_T)frameHeader[0];
      ID[1] = (int8_T)frameHeader[1];
      ID[2] = (int8_T)frameHeader[2];
      ID[3] = (int8_T)frameHeader[3];
      ret = memcmp(&ID[0], &b_b[0], 4);
      if (ret == 0) {
        b_i = 4;
      } else {
        b_i = 0;
      }
      /*  DataSize (4 bytes) */
      memcpy((void *)&b_y, (void *)&frameHeader[b_i],
             (uint32_T)((size_t)1 * sizeof(uint32_T)));
      /*  Stream Name (32 bytes) */
      ret = 0;
      ny = 0;
      for (calclen = 0; calclen < 32; calclen++) {
        u = frameHeader[(calclen + b_i) + 4];
        streamName[calclen] = u;
        if (u > 0) {
          ret++;
          tmp_data[ny] = (int8_T)(calclen + 1);
          ny++;
        }
      }
      audioFrame_streamName_size[0] = 1;
      audioFrame_streamName_size[1] = (int8_T)ret;
      ret = (int8_T)ret;
      for (ny = 0; ny < ret; ny++) {
        audioFrame_streamName_data[ny] = (int8_T)streamName[tmp_data[ny] - 1];
      }
      /*  Number of channels (1 bytes) */
      /*      S.numChannels = double( F(i+1:i+1) ); */
      S_numChannels_tmp_tmp = frameHeader[b_i + 36];
      /*  DataSize (4 bytes) */
      b_st.site = &jb_emlrtRSI;
      x_data[0] = frameHeader[b_i + 37];
      x_data[1] = frameHeader[b_i + 38];
      if (b_i + 40 > 43) {
        emlrtDynamicBoundsCheckR2012b(44, 1, 43, &f_emlrtBCI, &b_st);
      }
      x_data[2] = frameHeader[b_i + 39];
      if (b_i + 41 > 43) {
        emlrtDynamicBoundsCheckR2012b(b_i + 41, 1, 43, &f_emlrtBCI, &b_st);
      }
      x_data[3] = frameHeader[b_i + 40];
      memcpy((void *)&c_y, (void *)&x_data[0],
             (uint32_T)((size_t)1 * sizeof(uint32_T)));
      /*  dec2hex( F(i+1:i+4)) */
      /*  ID (2 bytes) */
      b_st.site = &kb_emlrtRSI;
      if (b_i + 42 > 43) {
        emlrtDynamicBoundsCheckR2012b(b_i + 42, 1, 43, &e_emlrtBCI, &b_st);
      }
      b_x[0] = frameHeader[b_i + 41];
      if (b_i + 43 > 43) {
        emlrtDynamicBoundsCheckR2012b(b_i + 43, 1, 43, &e_emlrtBCI, &b_st);
      }
      b_x[1] = frameHeader[42];
      memcpy((void *)&d_y, (void *)&b_x[0],
             (uint32_T)((size_t)1 * sizeof(uint16_T)));
      /*  Compute buffer */
      S_bufferSize = (real_T)d_y / ((real_T)S_numChannels_tmp_tmp * 4.0);
      /*  Audio Buffer to be read */
      b_i = d_y;
      *audioFrame_timeLenght = 1000.0 * S_bufferSize / (real_T)c_y;
      audioFrame_audioFrameBuff->size[0] = 0;
      audioFrame_audioFrameBuff->size[1] = 0;
      /*  Convert the byte stream to a structure */
      /*  If the tag does not match discard the audio buffer */
      st.site = &v_emlrtRSI;
      strtrim(&st, obj_ReaStreamIDtag_data, obj_ReaStreamIDtag_size, b_tmp_data,
              tmp_size);
      st.site = &v_emlrtRSI;
      if (!b_strcmp(&st, audioFrame_streamName_data, audioFrame_streamName_size,
                    b_tmp_data, tmp_size)) {
        /*          clc;disp(Frame); */
        /*          disp('REJECT FRAME!');% DEBUG++++++++++++++ */
        /*  Discard this packet payload */
        st.site = &w_emlrtRSI;
        byteSize = (real_T)d_y / 4.0;
        /*  function [output] = readUDPbuffer(obj,byteSize,type) */
        /*  Global Declaration FOR RECORD AND PLAYBACK */
        /*     %% The actual code needed */
        /*     %% For testing */
        /*  FOR TESTING for recording data */
        /*  For reading back data  */
        if (i + byteSize > 2.9512476E+6) {
          i = 0.0;
          i_dirty |= 1U;
          STATE_IN_LOOP_FLAG_ = false;
          STATE_IN_LOOP_FLAG__dirty |= 1U;
        }
        b = byteSize * 4.0;
        if (b < 1.0) {
          y->size[0] = 1;
          y->size[1] = 0;
        } else {
          ny = y->size[0] * y->size[1];
          y->size[0] = 1;
          ret = (int32_T)muDoubleScalarFloor(b - 1.0);
          y->size[1] = ret + 1;
          emxEnsureCapacity_uint16_T(&st, y, ny, &w_emlrtRTEI);
          for (ny = 0; ny <= ret; ny++) {
            y->data[ny] = (uint16_T)(ny + 1);
          }
        }
        b_st.site = &dc_emlrtRSI;
        ret = y->size[1];
        for (ny = 0; ny < ret; ny++) {
          b = i + (real_T)y->data[ny];
          if (b != (int32_T)muDoubleScalarFloor(b)) {
            emlrtIntegerCheckR2012b(b, &c_emlrtDCI, &b_st);
          }
          if (((int32_T)b < 1) || ((int32_T)b > 14756238)) {
            emlrtDynamicBoundsCheckR2012b((int32_T)b, 1, 14756238, &d_emlrtBCI,
                                          &b_st);
          }
          b_x_data[ny] = output_[(int32_T)b - 1];
        }
        if (y->size[1] == 0) {
          ny = 0;
        } else {
          ny = y->size[1] >> 2;
          if (ny << 2 != y->size[1]) {
            emlrtErrorWithMessageIdR2018a(
                &b_st, &c_emlrtRTEI, "MATLAB:typecastc:notEnoughInputElements",
                "MATLAB:typecastc:notEnoughInputElements", 12, 12, 4, 4, 5,
                "uint8", 13, 8U, 4, 6, "single", 12, 32);
          }
        }
        memcpy((void *)&y_data[0], (void *)&b_x_data[0],
               (uint32_T)((size_t)ny * sizeof(real32_T)));
        i += byteSize;
        i_dirty |= 1U;
        /*  Add the numder of bytes read */
        b_STATE_FLAG_ = 2;
      } else {
        /*  Read Audio */
        st.site = &x_emlrtRSI;
        byteSize = (real_T)d_y / 4.0;
        /*  function [output] = readUDPbuffer(obj,byteSize,type) */
        /*  Global Declaration FOR RECORD AND PLAYBACK */
        /*     %% The actual code needed */
        /*     %% For testing */
        /*  FOR TESTING for recording data */
        /*  For reading back data  */
        if (i + byteSize > 2.9512476E+6) {
          i = 0.0;
          i_dirty |= 1U;
          STATE_IN_LOOP_FLAG_ = false;
          STATE_IN_LOOP_FLAG__dirty |= 1U;
        }
        b = byteSize * 4.0;
        if (b < 1.0) {
          y->size[0] = 1;
          y->size[1] = 0;
        } else {
          ny = y->size[0] * y->size[1];
          y->size[0] = 1;
          ret = (int32_T)muDoubleScalarFloor(b - 1.0);
          y->size[1] = ret + 1;
          emxEnsureCapacity_uint16_T(&st, y, ny, &w_emlrtRTEI);
          for (ny = 0; ny <= ret; ny++) {
            y->data[ny] = (uint16_T)(ny + 1);
          }
        }
        b_st.site = &dc_emlrtRSI;
        ret = y->size[1];
        for (ny = 0; ny < ret; ny++) {
          b = i + (real_T)y->data[ny];
          if (b != (int32_T)muDoubleScalarFloor(b)) {
            emlrtIntegerCheckR2012b(b, &c_emlrtDCI, &b_st);
          }
          if (((int32_T)b < 1) || ((int32_T)b > 14756238)) {
            emlrtDynamicBoundsCheckR2012b((int32_T)b, 1, 14756238, &d_emlrtBCI,
                                          &b_st);
          }
          b_x_data[ny] = output_[(int32_T)b - 1];
        }
        if (y->size[1] == 0) {
          ny = 0;
        } else {
          ny = y->size[1] >> 2;
          if (ny << 2 != y->size[1]) {
            emlrtErrorWithMessageIdR2018a(
                &b_st, &c_emlrtRTEI, "MATLAB:typecastc:notEnoughInputElements",
                "MATLAB:typecastc:notEnoughInputElements", 12, 12, 4, 4, 5,
                "uint8", 13, 8U, 4, 6, "single", 12, 32);
          }
        }
        memcpy((void *)&y_data[0], (void *)&b_x_data[0],
               (uint32_T)((size_t)ny * sizeof(real32_T)));
        i += byteSize;
        i_dirty |= 1U;
        st.site = &y_emlrtRSI;
        x_size_idx_1 = (int16_T)ny;
        b_st.site = &ec_emlrtRSI;
        if (S_numChannels_tmp_tmp > 0) {
          calclen = ny / S_numChannels_tmp_tmp;
          if (calclen > ny) {
            emlrtErrorWithMessageIdR2018a(&b_st, &b_emlrtRTEI,
                                          "Coder:builtins:AssertionFailed",
                                          "Coder:builtins:AssertionFailed", 0);
          }
        } else {
          calclen = 0;
        }
        ret = 1;
        if (ny > 1) {
          ret = ny;
        }
        ret = muIntScalarMax_sint32(x_size_idx_1, ret);
        if (calclen > ret) {
          emlrtErrorWithMessageIdR2018a(
              &st, &e_emlrtRTEI, "Coder:toolbox:reshape_emptyReshapeLimit",
              "Coder:toolbox:reshape_emptyReshapeLimit", 0);
        }
        if (S_numChannels_tmp_tmp > ret) {
          emlrtErrorWithMessageIdR2018a(
              &st, &e_emlrtRTEI, "Coder:toolbox:reshape_emptyReshapeLimit",
              "Coder:toolbox:reshape_emptyReshapeLimit", 0);
        }
        ret = calclen * S_numChannels_tmp_tmp;
        if (ret != ny) {
          emlrtErrorWithMessageIdR2018a(
              &st, &d_emlrtRTEI, "Coder:MATLAB:getReshapeDims_notSameNumel",
              "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
        }
        ny = audioFrame_audioFrameBuff->size[0] *
             audioFrame_audioFrameBuff->size[1];
        audioFrame_audioFrameBuff->size[0] = calclen;
        audioFrame_audioFrameBuff->size[1] = S_numChannels_tmp_tmp;
        emxEnsureCapacity_real32_T(sp, audioFrame_audioFrameBuff, ny,
                                   &x_emlrtRTEI);
        for (ny = 0; ny < ret; ny++) {
          audioFrame_audioFrameBuff->data[ny] = y_data[ny];
        }
        /*  Add the numder of bytes read */
        /*      disp(totalBytesRead); */
      }
      exitg1 = 1;
    } else {
      /*          disp('UDP TIMEOUT!');% DEBUG++++++++++++++ */
      /*  There is a limit to the number of attemtps in order to return */
      /*  control to the main loop and check for interupts before checking */
      /*  the buffer again */
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b((emlrtCTX)sp);
      }
      st.site = &r_emlrtRSI;
      if (toc(&st, expl_temp.tv_sec, expl_temp.tv_nsec) > 1.0) {
        b_STATE_FLAG_ = -1;
        st.site = &s_emlrtRSI;
        /*  function [S,i] = rsFrameHeader2Struct(F) */
        /*  Unpack ReaStream Frame Header to a Structure */
        /*  The input is expected as uint8 byte stream */
        /*  */
        /*      typedef struct ReaStream */
        /*      { */
        /*      char ID[4]; // 'MRSR' tag for every packet like an ID (4 bytes)
         */
        /*      unsigned int packetSize; // size of the entire UDP packet (4
         * bytes) */
        /*      char name[32]; // Name of the stream (ie: default on the plugin)
         * (32 bytes) */
        /*      unsigned int nbChan; // the number of channels the plugin sends
         * (1 byte) */
        /*      unsigned int freq; // the rate Frequency of the data (44100,
         * 48000, ...) (4 bytes) */
        /*      unsigned datasSize; // size of the following bytes to read. (2
         * bytes) */
        /*      float *datas; // start of the audio datas (variable get from
         * "datasSize") */
        /*      } ReaStream; */
        /*  Frame Output template */
        /*  ID (4 bytes) */
        /*  DataSize (4 bytes) */
        x_data[0] = 0U;
        x_data[1] = 0U;
        x_data[2] = 0U;
        x_data[3] = 0U;
        memcpy((void *)&b_y, (void *)&x_data[0],
               (uint32_T)((size_t)1 * sizeof(uint32_T)));
        /*  Stream Name (32 bytes) */
        /*  Number of channels (1 bytes) */
        /*      S.numChannels = double( F(i+1:i+1) ); */
        /*  DataSize (4 bytes) */
        memcpy((void *)&c_y, (void *)&x_data[0],
               (uint32_T)((size_t)1 * sizeof(uint32_T)));
        /*  dec2hex( F(i+1:i+4)) */
        /*  ID (2 bytes) */
        b_x[0] = 0U;
        b_x[1] = 0U;
        memcpy((void *)&d_y, (void *)&b_x[0],
               (uint32_T)((size_t)1 * sizeof(uint16_T)));
        /*  Compute buffer */
        if (d_y > 0.0) {
          S_bufferSize = rtInf;
        } else if (d_y < 0.0) {
          S_bufferSize = rtMinusInf;
        } else {
          S_bufferSize = rtNaN;
        }
        /*  Audio Buffer to be read */
        audioFrame_streamName_size[0] = 1;
        audioFrame_streamName_size[1] = 0;
        S_numChannels_tmp_tmp = 0;
        b_i = d_y;
        *audioFrame_timeLenght = 1000.0 * S_bufferSize / (real_T)c_y;
        audioFrame_audioFrameBuff->size[0] = 0;
        audioFrame_audioFrameBuff->size[1] = 0;
        /*  Get Empty frame    */
        exitg1 = 1;
      }
    }
  } while (exitg1 == 0);
  emxFree_uint16_T(&y);
  *audioFrame_udpPayLoadBytes = b_y;
  *audioFrame_numChannels = S_numChannels_tmp_tmp;
  *audioFrame_SampleRate = c_y;
  *audioFrame_audioByteLength = b_i;
  *audioFrame_bufferSize = S_bufferSize;
  *STATE_FLAG_ = b_STATE_FLAG_;
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

/* End of code generation (readReaStreameFrame.c) */
