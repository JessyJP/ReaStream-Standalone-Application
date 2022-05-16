/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: readReaStreameFrame.c
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 13-Nov-2021 13:55:06
 */

/* Include Files */
#include "readReaStreameFrame.h"
#include "MainProcess_data.h"
#include "MainProcess_emxutil.h"
#include "MainProcess_types.h"
#include "rt_nonfinite.h"
#include "tic.h"
#include "toc.h"
#include "DAHostLib_rtw.h"
#include "HostLib_Audio.h"
#include <math.h>
#include <stddef.h>
#include <string.h>

/* Function Definitions */
/*
 * function [audioFrame,STATE_FLAG_] = readReaStreameFrame(obj)
 *
 * Arguments    : const char obj_ReaStreamIDtag_data[]
 *                const int obj_ReaStreamIDtag_size[2]
 *                const char obj_frameStart[4]
 *                double *audioFrame_udpPayLoadBytes
 *                char audioFrame_streamName_data[]
 *                int audioFrame_streamName_size[2]
 *                double *audioFrame_numChannels
 *                double *audioFrame_SampleRate
 *                double *audioFrame_audioByteLength
 *                double *audioFrame_bufferSize
 *                double *audioFrame_timeLength_ms
 *                emxArray_real32_T *audioFrame_audioFrameBuff
 *                double *STATE_FLAG_
 * Return Type  : void
 */
void readReaStreameFrame(
    const char obj_ReaStreamIDtag_data[], const int obj_ReaStreamIDtag_size[2],
    const char obj_frameStart[4], double *audioFrame_udpPayLoadBytes,
    char audioFrame_streamName_data[], int audioFrame_streamName_size[2],
    double *audioFrame_numChannels, double *audioFrame_SampleRate,
    double *audioFrame_audioByteLength, double *audioFrame_bufferSize,
    double *audioFrame_timeLength_ms, emxArray_real32_T *audioFrame_audioFrameBuff,
    double *STATE_FLAG_)
{
  static const char cv[128] = {
      '\x00',  '\x01', '\x02', '\x03', '\x04', '\x05', '\x06', '\x07', '\x08',
      '	', '\x0a', '\x0b', '\x0c', '\x0d', '\x0e', '\x0f', '\x10', '\x11',
      '\x12',  '\x13', '\x14', '\x15', '\x16', '\x17', '\x18', '\x19', '\x1a',
      '\x1b',  '\x1c', '\x1d', '\x1e', '\x1f', ' ',    '!',    '\"',   '#',
      '$',     '%',    '&',    '\'',   '(',    ')',    '*',    '+',    ',',
      '-',     '.',    '/',    '0',    '1',    '2',    '3',    '4',    '5',
      '6',     '7',    '8',    '9',    ':',    ';',    '<',    '=',    '>',
      '?',     '@',    'a',    'b',    'c',    'd',    'e',    'f',    'g',
      'h',     'i',    'j',    'k',    'l',    'm',    'n',    'o',    'p',
      'q',     'r',    's',    't',    'u',    'v',    'w',    'x',    'y',
      'z',     '[',    '\\',   ']',    '^',    '_',    '`',    'a',    'b',
      'c',     'd',    'e',    'f',    'g',    'h',    'i',    'j',    'k',
      'l',     'm',    'n',    'o',    'p',    'q',    'r',    's',    't',
      'u',     'v',    'w',    'x',    'y',    'z',    '{',    '|',    '}',
      '~',     '\x7f'};
  static const char b[4] = {'M', 'R', 'S', 'R'};
  static const boolean_T bv[128] = {
      false, false, false, false, false, false, false, false, false, true,
      true,  true,  true,  true,  false, false, false, false, false, false,
      false, false, false, false, false, false, false, false, true,  true,
      true,  true,  true,  false, false, false, false, false, false, false,
      false, false, false, false, false, false, false, false, false, false,
      false, false, false, false, false, false, false, false, false, false,
      false, false, false, false, false, false, false, false, false, false,
      false, false, false, false, false, false, false, false, false, false,
      false, false, false, false, false, false, false, false, false, false,
      false, false, false, false, false, false, false, false, false, false,
      false, false, false, false, false, false, false, false, false, false,
      false, false, false, false, false, false, false, false, false, false,
      false, false, false, false, false, false, false, false};
  emxArray_uint16_T *y;
  double S_bufferSize;
  double timer_tv_nsec;
  double timer_tv_sec;
  float y_data[16383];
  int b_STATE_FLAG_;
  int b_audioFrame_audioByteLength;
  int b_audioFrame_numChannels;
  int b_i;
  int b_j1;
  unsigned int b_y;
  unsigned int c_y;
  int exitg1;
  int exitg2;
  int j2;
  int ret;
  int trueCount;
  unsigned short d_y;
  unsigned char b_x_data[65535];
  unsigned char frameHeader[43];
  unsigned char x[43];
  unsigned char streamName[32];
  signed char tmp_data[32];
  unsigned char varargin_1_data[32];
  char ID[4];
  unsigned char tag_data[4];
  unsigned char x_data[4];
  unsigned char b_x[2];
  unsigned char u;
  boolean_T b_b;
  boolean_T b_bool;
  /*  Default output */
  /*      audioFrame = [];% Get Empty frame   */
  /*  Default output state */
  b_STATE_FLAG_ = 1;
  /*  Locate 'MRSR' */
  tic(&timer_tv_sec, &timer_tv_nsec);
  emxInit_uint16_T(&y, 2);
  do {
    exitg1 = 0;
    /*  function [output] = readUDPbuffer(obj,byteSize,type) */
    /*  Global Declaration FOR RECORD AND PLAYBACK */
    /*     %% The actual code needed */
    /*     %% For testing */
    /*  FOR TESTING for recording data */
    /*  For reading back data  */
    if (i + 4.0 > 2.9512476E+6) {
      i = 0.0;
      STATE_IN_LOOP_FLAG_ = false;
    }
    x_data[0] = output_[(int)(i + 1.0) - 1];
    x_data[1] = output_[(int)(i + 2.0) - 1];
    x_data[2] = output_[(int)(i + 3.0) - 1];
    x_data[3] = output_[(int)(i + 4.0) - 1];
    memcpy((void *)&tag_data[0], (void *)&x_data[0],
           (unsigned int)((size_t)4 * sizeof(unsigned char)));
    i += 4.0;
    /*  Add the numder of bytes read */
    /*  If a frame is located */
    ID[0] = (signed char)tag_data[0];
    ID[1] = (signed char)tag_data[1];
    ID[2] = (signed char)tag_data[2];
    ID[3] = (signed char)tag_data[3];
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
      /*  function [output] = readUDPbuffer(obj,byteSize,type) */
      /*  Global Declaration FOR RECORD AND PLAYBACK */
      /*     %% The actual code needed */
      /*     %% For testing */
      /*  FOR TESTING for recording data */
      /*  For reading back data  */
      if (i + 43.0 > 2.9512476E+6) {
        i = 0.0;
        STATE_IN_LOOP_FLAG_ = false;
      }
      for (b_j1 = 0; b_j1 < 43; b_j1++) {
        x[b_j1] = output_[(int)(i + ((double)b_j1 + 1.0)) - 1];
      }
      memcpy((void *)&frameHeader[0], (void *)&x[0],
             (unsigned int)((size_t)43 * sizeof(unsigned char)));
      i += 43.0;
      /*  Make Sure the "frameHeader" not stored as double */
      /*  Add the numder of bytes read */
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
      ID[0] = (signed char)frameHeader[0];
      ID[1] = (signed char)frameHeader[1];
      ID[2] = (signed char)frameHeader[2];
      ID[3] = (signed char)frameHeader[3];
      ret = memcmp(&ID[0], &b[0], 4);
      if (ret == 0) {
        b_i = 40;
      } else {
        b_i = 36;
      }
      /*  DataSize (4 bytes) */
      memcpy((void *)&b_y, (void *)&frameHeader[b_i + -36],
             (unsigned int)((size_t)1 * sizeof(unsigned int)));
      /*  Stream Name (32 bytes) */
      trueCount = 0;
      ret = 0;
      for (b_j1 = 0; b_j1 < 32; b_j1++) {
        u = frameHeader[(b_j1 + b_i) - 32];
        streamName[b_j1] = u;
        if (u > 0) {
          trueCount++;
          tmp_data[ret] = (signed char)(b_j1 + 1);
          ret++;
        }
      }
      for (b_j1 = 0; b_j1 < trueCount; b_j1++) {
        varargin_1_data[b_j1] = streamName[tmp_data[b_j1] - 1];
      }
      ret = (signed char)trueCount;
      /*  Number of channels (1 bytes) */
      /*      S.numChannels = double( F(i+1:i+1) ); */
      /*  DataSize (4 bytes) */
      x_data[0] = frameHeader[b_i + 1];
      x_data[1] = frameHeader[b_i + 2];
      x_data[2] = frameHeader[b_i + 3];
      x_data[3] = frameHeader[b_i + 4];
      memcpy((void *)&c_y, (void *)&x_data[0],
             (unsigned int)((size_t)1 * sizeof(unsigned int)));
      /*  dec2hex( F(i+1:i+4)) */
      /*  ID (2 bytes) */
      b_x[0] = frameHeader[b_i + 5];
      b_x[1] = frameHeader[b_i + 6];
      memcpy((void *)&d_y, (void *)&b_x[0],
             (unsigned int)((size_t)1 * sizeof(unsigned short)));
      /*  Compute buffer */
      S_bufferSize = (double)d_y / ((double)frameHeader[b_i] * 4.0);
      /*  Audio Buffer to be read */
      audioFrame_streamName_size[0] = 1;
      audioFrame_streamName_size[1] = (signed char)trueCount;
      for (b_j1 = 0; b_j1 < ret; b_j1++) {
        audioFrame_streamName_data[b_j1] = (signed char)varargin_1_data[b_j1];
      }
      b_audioFrame_numChannels = frameHeader[b_i];
      b_audioFrame_audioByteLength = d_y;
      *audioFrame_timeLength_ms = 1000.0 * S_bufferSize / (double)c_y;
      audioFrame_audioFrameBuff->size[0] = 0;
      audioFrame_audioFrameBuff->size[1] = 0;
      /*  Convert the byte stream to a structure */
      /*  If the tag does not match discard the audio buffer */
      b_j1 = 0;
      while ((b_j1 + 1 <= obj_ReaStreamIDtag_size[1]) &&
             bv[(unsigned char)obj_ReaStreamIDtag_data[b_j1] & 127] &&
             (!(obj_ReaStreamIDtag_data[b_j1] == '\x00'))) {
        b_j1++;
      }
      j2 = obj_ReaStreamIDtag_size[1] - 1;
      while ((j2 + 1 > 0) &&
             bv[(unsigned char)obj_ReaStreamIDtag_data[j2] & 127] &&
             (!(obj_ReaStreamIDtag_data[j2] == '\x00'))) {
        j2--;
      }
      if (b_j1 + 1 > j2 + 1) {
        b_j1 = 0;
        j2 = -1;
      }
      b_bool = false;
      b_b = ((signed char)trueCount == 0);
      if (b_b && ((j2 - b_j1) + 1 == 0)) {
        b_bool = true;
      } else if ((j2 - b_j1) + 1 == (signed char)trueCount) {
        ret = 0;
        do {
          exitg2 = 0;
          if (ret <= j2 - b_j1) {
            if (cv[(unsigned char)audioFrame_streamName_data[ret] & 127] !=
                cv[(unsigned char)obj_ReaStreamIDtag_data[b_j1 + ret] & 127]) {
              exitg2 = 1;
            } else {
              ret++;
            }
          } else {
            b_bool = true;
            exitg2 = 1;
          }
        } while (exitg2 == 0);
      }
      if (!b_bool) {
        /*          clc;disp(Frame); */
        /*          disp('REJECT FRAME!');% DEBUG++++++++++++++ */
        /*  Discard this packet payload */
        timer_tv_sec = (double)d_y / 4.0;
        /*  function [output] = readUDPbuffer(obj,byteSize,type) */
        /*  Global Declaration FOR RECORD AND PLAYBACK */
        /*     %% The actual code needed */
        /*     %% For testing */
        /*  FOR TESTING for recording data */
        /*  For reading back data  */
        if (i + timer_tv_sec > 2.9512476E+6) {
          i = 0.0;
          STATE_IN_LOOP_FLAG_ = false;
        }
        timer_tv_nsec = timer_tv_sec * 4.0;
        if (timer_tv_nsec < 1.0) {
          y->size[0] = 1;
          y->size[1] = 0;
        } else {
          b_j1 = y->size[0] * y->size[1];
          y->size[0] = 1;
          ret = (int)floor(timer_tv_nsec - 1.0);
          y->size[1] = ret + 1;
          emxEnsureCapacity_uint16_T(y, b_j1);
          for (b_j1 = 0; b_j1 <= ret; b_j1++) {
            y->data[b_j1] = (unsigned short)(b_j1 + 1);
          }
        }
        ret = y->size[1];
        for (b_j1 = 0; b_j1 < ret; b_j1++) {
          b_x_data[b_j1] = output_[(int)(i + (double)y->data[b_j1]) - 1];
        }
        if (y->size[1] == 0) {
          ret = 0;
        } else {
          ret = y->size[1] >> 2;
        }
        memcpy((void *)&y_data[0], (void *)&b_x_data[0],
               (unsigned int)((size_t)ret * sizeof(float)));
        i += timer_tv_sec;
        /*  Add the numder of bytes read */
        b_STATE_FLAG_ = 2;
      } else {
        /*  Read Audio */
        timer_tv_sec = (double)d_y / 4.0;
        /*  function [output] = readUDPbuffer(obj,byteSize,type) */
        /*  Global Declaration FOR RECORD AND PLAYBACK */
        /*     %% The actual code needed */
        /*     %% For testing */
        /*  FOR TESTING for recording data */
        /*  For reading back data  */
        if (i + timer_tv_sec > 2.9512476E+6) {
          i = 0.0;
          STATE_IN_LOOP_FLAG_ = false;
        }
        timer_tv_nsec = timer_tv_sec * 4.0;
        if (timer_tv_nsec < 1.0) {
          y->size[0] = 1;
          y->size[1] = 0;
        } else {
          b_j1 = y->size[0] * y->size[1];
          y->size[0] = 1;
          ret = (int)floor(timer_tv_nsec - 1.0);
          y->size[1] = ret + 1;
          emxEnsureCapacity_uint16_T(y, b_j1);
          for (b_j1 = 0; b_j1 <= ret; b_j1++) {
            y->data[b_j1] = (unsigned short)(b_j1 + 1);
          }
        }
        ret = y->size[1];
        for (b_j1 = 0; b_j1 < ret; b_j1++) {
          b_x_data[b_j1] = output_[(int)(i + (double)y->data[b_j1]) - 1];
        }
        if (y->size[1] == 0) {
          ret = 0;
        } else {
          ret = y->size[1] >> 2;
        }
        memcpy((void *)&y_data[0], (void *)&b_x_data[0],
               (unsigned int)((size_t)ret * sizeof(float)));
        i += timer_tv_sec;
        if (frameHeader[b_i] > 0) {
          b_j1 = frameHeader[b_i];
          if (b_j1 == 0) {
            ret = MAX_int32_T;
          } else {
            ret /= b_j1;
          }
        } else {
          ret = 0;
        }
        b_j1 = audioFrame_audioFrameBuff->size[0] *
               audioFrame_audioFrameBuff->size[1];
        audioFrame_audioFrameBuff->size[0] = ret;
        audioFrame_audioFrameBuff->size[1] = frameHeader[b_i];
        emxEnsureCapacity_real32_T(audioFrame_audioFrameBuff, b_j1);
        ret *= frameHeader[b_i];
        for (b_j1 = 0; b_j1 < ret; b_j1++) {
          audioFrame_audioFrameBuff->data[b_j1] = y_data[b_j1];
        }
        /*  Add the numder of bytes read */
        /*      disp(totalBytesRead); */
      }
      exitg1 = 1;

      /*          disp('UDP TIMEOUT!');% DEBUG++++++++++++++ */
      /*  There is a limit to the number of attemtps in order to return */
      /*  control to the main loop and check for interupts before checking */
      /*  the buffer again */
    } else if (toc(timer_tv_sec, timer_tv_nsec) > 1.0) {
      b_STATE_FLAG_ = -1;
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
      /*  DataSize (4 bytes) */
      x_data[0] = 0U;
      x_data[1] = 0U;
      x_data[2] = 0U;
      x_data[3] = 0U;
      memcpy((void *)&b_y, (void *)&x_data[0],
             (unsigned int)((size_t)1 * sizeof(unsigned int)));
      /*  Stream Name (32 bytes) */
      /*  Number of channels (1 bytes) */
      /*      S.numChannels = double( F(i+1:i+1) ); */
      /*  DataSize (4 bytes) */
      memcpy((void *)&c_y, (void *)&x_data[0],
             (unsigned int)((size_t)1 * sizeof(unsigned int)));
      /*  dec2hex( F(i+1:i+4)) */
      /*  ID (2 bytes) */
      b_x[0] = 0U;
      b_x[1] = 0U;
      memcpy((void *)&d_y, (void *)&b_x[0],
             (unsigned int)((size_t)1 * sizeof(unsigned short)));
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
      b_audioFrame_numChannels = 0;
      b_audioFrame_audioByteLength = d_y;
      *audioFrame_timeLength_ms = 1000.0 * S_bufferSize / (double)c_y;
      audioFrame_audioFrameBuff->size[0] = 0;
      audioFrame_audioFrameBuff->size[1] = 0;
      /*  Get Empty frame    */
      exitg1 = 1;
    }
  } while (exitg1 == 0);
  emxFree_uint16_T(&y);
  *audioFrame_udpPayLoadBytes = b_y;
  *audioFrame_numChannels = b_audioFrame_numChannels;
  *audioFrame_SampleRate = c_y;
  *audioFrame_audioByteLength = b_audioFrame_audioByteLength;
  *audioFrame_bufferSize = S_bufferSize;
  *STATE_FLAG_ = b_STATE_FLAG_;
}

/*
 * File trailer for readReaStreameFrame.c
 *
 * [EOF]
 */
