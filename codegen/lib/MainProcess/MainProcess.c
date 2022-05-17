/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: MainProcess.c
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 13-Nov-2021 13:55:06
 */

/* Include Files */
#include "MainProcess.h"
#include "MainProcess_data.h"
#include "MainProcess_emxutil.h"
#include "MainProcess_initialize.h"
#include "MainProcess_internal_types.h"
#include "MainProcess_types.h"
#include "SystemCore.h"
#include "readReaStreameFrame.h"
#include "rt_nonfinite.h"
#include "DAHostLib_rtw.h"
#include "HostLib_Audio.h"
#include <math.h>
#include <string.h>

/* Function Definitions */
/*
 * function MainProcess()
 *  Main Process Script
 *
 * Arguments    : const char ReaStreamIDtag_data[]
 *                const int ReaStreamIDtag_size[2]
 *                const char driverSelection[11]
 *                const char deviceSelection[7]
 *                double pbSampSize
 *                boolean_T VariableBufferON
 * Return Type  : void
 */
void MainProcess(const char ReaStreamIDtag_data[],
                 const int ReaStreamIDtag_size[2],
                 const char driverSelection[11], const char deviceSelection[7],
                 double pbSampSize, boolean_T VariableBufferON)
{
  static const char obj_frameStart[4] = {'M', 'R', 'S', 'R'};
  audioDeviceWriter lobj_0;
  c_audiointerface_audioDeviceWri *obj;
  emxArray_boolean_T *b;
  emxArray_int32_T *idx;
  emxArray_real32_T *U0;
  emxArray_real32_T *b_playbackBuffer;
  emxArray_real32_T *playbackBuffer;
  emxArray_real32_T *testFrame_audioFrameBuff;
  double STATE_FLAG_NEEDED;
  double b_expl_temp;
  double c_expl_temp;
  double d_expl_temp;
  double e_expl_temp;
  double expl_temp;
  double testFrame_SampleRate;
  unsigned int inSize[8];
  int expl_temp_size[2];
  int b_i;
  int exitg1;
  int exitg2;
  int input_sizes_idx_0;
  int j;
  int k;
  int ncolx;
  int nrows;
  int sizes_idx_0;
  char expl_temp_data[32];
  char *sErr;
  boolean_T empty_non_axis_sizes;
  boolean_T exitg3;
  (void)driverSelection;
  (void)deviceSelection;
  if (!isInitialized_MainProcess) {
    MainProcess_initialize();
  }
  emxInit_real32_T(&testFrame_audioFrameBuff, 2);
  emxInit_real32_T(&U0, 2);
  obj = &lobj_0.pInterface;
  obj->S0_isInitialized = 0;
  lobj_0.matlabCodegenIsDeleted = true;
  /*     %% Settings and Properties */
  /*  Main loop interupt */
  /*  Global interupt flag */
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
  lobj_0.isInitialized = 0;
  /* System object Constructor function: audiointerface.audioDeviceWriter */
  lobj_0.pInterface.S0_isInitialized = 0;
  lobj_0.matlabCodegenIsDeleted = false;
  /*  Operation Flags ENUMERATION */
  /*  Main Processing state */
  /*  Interupt flag to exit the main loop */
  /*  Flag to skip frame */
  /*  Flag to indicate no no transmission */
  /*  Debug and interface */
  /*      disp(obj); */
  /*     %% Setup UPD connection    */
  /*  function [obj] = connectReceiverUDP(obj) */
  /*  Setup UPD connection */
  /*     %% Setup the audio device with default settings */
  /*  Check and listen for Frames */
  readReaStreameFrame(ReaStreamIDtag_data, ReaStreamIDtag_size, obj_frameStart,
                      &expl_temp, expl_temp_data, expl_temp_size, &b_expl_temp,
                      &testFrame_SampleRate, &c_expl_temp, &d_expl_temp,
                      &e_expl_temp, testFrame_audioFrameBuff,
                      &STATE_FLAG_NEEDED);
  emxInit_real32_T(&playbackBuffer, 2);
  emxInit_int32_T(&idx, 2);
  emxInit_boolean_T(&b, 2);
  emxInit_real32_T(&b_playbackBuffer, 2);
  do {
    exitg1 = 0;
    if (STATE_FLAG_NEEDED != 1.0) {
      readReaStreameFrame(ReaStreamIDtag_data, ReaStreamIDtag_size,
                          obj_frameStart, &expl_temp, expl_temp_data,
                          expl_temp_size, &b_expl_temp, &testFrame_SampleRate,
                          &c_expl_temp, &d_expl_temp, &e_expl_temp,
                          testFrame_audioFrameBuff, &STATE_FLAG_NEEDED);
      if (!STATE_IN_LOOP_FLAG_) {
        /*  Clear the UDP object */
        exitg1 = 1;
      }
    } else {
      /*  Setup Audio Device Based on the header */
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
      /*          disp(Settings.deviceWriter);        */
      /*  Check if audio device is available */
      /*     %% Run Decode and Playback Loop */
      /*  profile on */
      /*  function  [obj] = decodePlaybackLoop(obj) */
      /*  Unpack ReaStream Frame and Play Audio */
      /*  Control Flags */
      /*  Global interupt flag */
      FLUSH_UDP_BUFFER_FLAG_ = false;
      STATE_FLAG_NEEDED = 1.0;
      /*  Playback Settings */
      playbackBuffer->size[0] = 0;
      playbackBuffer->size[1] = 0;
      /*  Clear the UDP buffer before starting to decode */
      /*  Frame count */
      /*  Loop */
      do {
        exitg2 = 0;
        if (STATE_IN_LOOP_FLAG_ && (!(STATE_FLAG_NEEDED == 0.0))) {
          /*  External and Internal interupt flags */
          /*  Read reastream frame */
          readReaStreameFrame(
              ReaStreamIDtag_data, ReaStreamIDtag_size, obj_frameStart,
              &expl_temp, expl_temp_data, expl_temp_size, &b_expl_temp,
              &testFrame_SampleRate, &c_expl_temp, &d_expl_temp, &e_expl_temp,
              testFrame_audioFrameBuff, &STATE_FLAG_NEEDED);
          /*  This will force update the UI but not unless there is normal */
          /*  transmission frames */
          /*  Control logic Check flags */
          if ((!(STATE_FLAG_NEEDED == 2.0)) && (!(STATE_FLAG_NEEDED == -1.0))) {
            FLUSH_UDP_BUFFER_FLAG_ = false;
            /*  External interupt switch! */
            if (!STATE_IN_LOOP_FLAG_) {
              exitg2 = 1;
            } else {
              /*   IGNORE+++START */
              /*   IGNORE+++END */
              /*  Sent to Device with variable size bufffer */
              if (VariableBufferON) {
                SystemCore_step(&lobj_0, testFrame_audioFrameBuff);
              } else {
                /*  Reset the buffer size if the channel number changes */
                if (playbackBuffer->size[1] !=
                    testFrame_audioFrameBuff->size[1]) {
                  playbackBuffer->size[0] = 0;
                  playbackBuffer->size[1] = 0;
                }
                /*  Add to buffer */
                if ((playbackBuffer->size[0] != 0) &&
                    (playbackBuffer->size[1] != 0)) {
                  nrows = playbackBuffer->size[1];
                } else if ((testFrame_audioFrameBuff->size[0] != 0) &&
                           (testFrame_audioFrameBuff->size[1] != 0)) {
                  nrows = testFrame_audioFrameBuff->size[1];
                } else {
                  nrows = playbackBuffer->size[1];
                  if (testFrame_audioFrameBuff->size[1] >
                      playbackBuffer->size[1]) {
                    nrows = testFrame_audioFrameBuff->size[1];
                  }
                }
                empty_non_axis_sizes = (nrows == 0);
                if (empty_non_axis_sizes || ((playbackBuffer->size[0] != 0) &&
                                             (playbackBuffer->size[1] != 0))) {
                  input_sizes_idx_0 = playbackBuffer->size[0];
                } else {
                  input_sizes_idx_0 = 0;
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
                b_playbackBuffer->size[1] = nrows;
                emxEnsureCapacity_real32_T(b_playbackBuffer, b_i);
                for (b_i = 0; b_i < nrows; b_i++) {
                  for (ncolx = 0; ncolx < input_sizes_idx_0; ncolx++) {
                    b_playbackBuffer
                        ->data[ncolx + b_playbackBuffer->size[0] * b_i] =
                        playbackBuffer->data[ncolx + input_sizes_idx_0 * b_i];
                  }
                }
                for (b_i = 0; b_i < nrows; b_i++) {
                  for (ncolx = 0; ncolx < sizes_idx_0; ncolx++) {
                    b_playbackBuffer->data[(ncolx + input_sizes_idx_0) +
                                           b_playbackBuffer->size[0] * b_i] =
                        testFrame_audioFrameBuff
                            ->data[ncolx + sizes_idx_0 * b_i];
                  }
                }
                b_i = playbackBuffer->size[0] * playbackBuffer->size[1];
                playbackBuffer->size[0] = b_playbackBuffer->size[0];
                playbackBuffer->size[1] = b_playbackBuffer->size[1];
                emxEnsureCapacity_real32_T(playbackBuffer, b_i);
                input_sizes_idx_0 =
                    b_playbackBuffer->size[0] * b_playbackBuffer->size[1];
                for (b_i = 0; b_i < input_sizes_idx_0; b_i++) {
                  playbackBuffer->data[b_i] = b_playbackBuffer->data[b_i];
                }
                /*  Sent to Device with fixed size bufffer */
                if (playbackBuffer->size[0] >= pbSampSize) {
                  if (1.0 > pbSampSize) {
                    input_sizes_idx_0 = 0;
                  } else {
                    input_sizes_idx_0 = (int)pbSampSize;
                  }
                  if (lobj_0.isInitialized != 1) {
                    lobj_0.isSetupComplete = false;
                    lobj_0.isInitialized = 1;
                    lobj_0.inputVarSize[0].f1[0] =
                        (unsigned int)input_sizes_idx_0;
                    lobj_0.inputVarSize[0].f1[1] =
                        (unsigned int)playbackBuffer->size[1];
                    for (b_i = 0; b_i < 6; b_i++) {
                      lobj_0.inputVarSize[0].f1[b_i + 2] = 1U;
                    }
                    if (lobj_0.pInterface.S0_isInitialized != 1) {
                      lobj_0.pInterface.S0_isInitialized = 1;
                      /* System object Start function:
                       * audiointerface.audioDeviceWriter */
                      sErr = GetErrorBuffer(
                          &lobj_0.pInterface.W0_AudioDeviceLib[0U]);
                      CreateHostLibrary(
                          "hostlibaudio.dll",
                          &lobj_0.pInterface.W0_AudioDeviceLib[0U]);
                      if (*sErr == 0) {
                        LibCreate_Audio(
                            &lobj_0.pInterface.W0_AudioDeviceLib[0U], 0,
                            "Default", 1, 1, 255, 48000.0, 3, 4096, 40960, -1,
                            1, NULL);
                      }
                      if (*sErr != 0) {
                        DestroyHostLibrary(
                            &lobj_0.pInterface.W0_AudioDeviceLib[0U]);
                        if (*sErr != 0) {
                          PrintError(sErr);
                        }
                      }
                    }
                    lobj_0.isSetupComplete = true;
                    lobj_0.TunablePropsChanged = false;
                    if (lobj_0.pInterface.S0_isInitialized == 1) {
                      /* System object Initialization function:
                       * audiointerface.audioDeviceWriter */
                      lobj_0.pInterface.W1_numChans = 255U;
                    }
                  }
                  if (lobj_0.TunablePropsChanged) {
                    lobj_0.TunablePropsChanged = false;
                  }
                  inSize[0] = (unsigned int)input_sizes_idx_0;
                  inSize[1] = (unsigned int)playbackBuffer->size[1];
                  for (b_i = 0; b_i < 6; b_i++) {
                    inSize[b_i + 2] = 1U;
                  }
                  k = 0;
                  exitg3 = false;
                  while ((!exitg3) && (k < 8)) {
                    if (lobj_0.inputVarSize[0].f1[k] != inSize[k]) {
                      for (b_i = 0; b_i < 8; b_i++) {
                        lobj_0.inputVarSize[0].f1[b_i] = inSize[b_i];
                      }
                      exitg3 = true;
                    } else {
                      k++;
                    }
                  }
                  if (lobj_0.pInterface.S0_isInitialized != 1) {
                    lobj_0.pInterface.S0_isInitialized = 1;
                    /* System object Start function:
                     * audiointerface.audioDeviceWriter */
                    sErr = GetErrorBuffer(
                        &lobj_0.pInterface.W0_AudioDeviceLib[0U]);
                    CreateHostLibrary("hostlibaudio.dll",
                                      &lobj_0.pInterface.W0_AudioDeviceLib[0U]);
                    if (*sErr == 0) {
                      LibCreate_Audio(&lobj_0.pInterface.W0_AudioDeviceLib[0U],
                                      0, "Default", 1, 1, 255, 48000.0, 3, 4096,
                                      40960, -1, 1, NULL);
                    }
                    if (*sErr != 0) {
                      DestroyHostLibrary(
                          &lobj_0.pInterface.W0_AudioDeviceLib[0U]);
                      if (*sErr != 0) {
                        PrintError(sErr);
                      }
                    }
                    /* System object Initialization function:
                     * audiointerface.audioDeviceWriter */
                    lobj_0.pInterface.W1_numChans = 255U;
                  }
                  nrows = playbackBuffer->size[1];
                  b_i = U0->size[0] * U0->size[1];
                  U0->size[0] = input_sizes_idx_0;
                  U0->size[1] = playbackBuffer->size[1];
                  emxEnsureCapacity_real32_T(U0, b_i);
                  for (b_i = 0; b_i < nrows; b_i++) {
                    for (ncolx = 0; ncolx < input_sizes_idx_0; ncolx++) {
                      U0->data[ncolx + U0->size[0] * b_i] =
                          playbackBuffer
                              ->data[ncolx + playbackBuffer->size[0] * b_i];
                    }
                  }
                  /* System object Outputs function:
                   * audiointerface.audioDeviceWriter */
                  if (U0->size[0] != 0) {
                    if ((unsigned int)U0->size[1] !=
                        lobj_0.pInterface.W1_numChans) {
                      sErr = GetErrorBuffer(
                          &lobj_0.pInterface.W0_AudioDeviceLib[0U]);
                      LibTerminate(&lobj_0.pInterface.W0_AudioDeviceLib[0U]);
                      if (*sErr != 0) {
                        PrintError(sErr);
                      }
                      LibDestroy_Audio(&lobj_0.pInterface.W0_AudioDeviceLib[0U],
                                       1, 1);
                      DestroyHostLibrary(
                          &lobj_0.pInterface.W0_AudioDeviceLib[0U]);
                      sErr = GetErrorBuffer(
                          &lobj_0.pInterface.W0_AudioDeviceLib[0U]);
                      CreateHostLibrary(
                          "hostlibaudio.dll",
                          &lobj_0.pInterface.W0_AudioDeviceLib[0U]);
                      if (*sErr == 0) {
                        LibCreate_Audio(
                            &lobj_0.pInterface.W0_AudioDeviceLib[0U], 0,
                            "Default", 1, 1, U0->size[1], 48000.0, 3, 4096,
                            40960, -1, 1, NULL);
                      }
                      if (*sErr != 0) {
                        DestroyHostLibrary(
                            &lobj_0.pInterface.W0_AudioDeviceLib[0U]);
                        if (*sErr != 0) {
                          PrintError(sErr);
                        }
                      }
                      lobj_0.pInterface.W1_numChans = (unsigned int)U0->size[1];
                    }
                    sErr = GetErrorBuffer(
                        &lobj_0.pInterface.W0_AudioDeviceLib[0U]);
                    LibUpdate_Audio(&lobj_0.pInterface.W0_AudioDeviceLib[0U],
                                    &U0->data[0U], 1, U0->size[0],
                                    &lobj_0.pInterface.O0_Y0);
                    if (*sErr != 0) {
                      PrintError(sErr);
                    }
                  }
                  b_i = idx->size[0] * idx->size[1];
                  idx->size[0] = 1;
                  input_sizes_idx_0 = (int)floor(pbSampSize - 1.0);
                  idx->size[1] = input_sizes_idx_0 + 1;
                  emxEnsureCapacity_int32_T(idx, b_i);
                  for (b_i = 0; b_i <= input_sizes_idx_0; b_i++) {
                    idx->data[b_i] = b_i + 1;
                  }
                  sizes_idx_0 = playbackBuffer->size[0];
                  ncolx = playbackBuffer->size[1] - 1;
                  if (idx->size[1] == 1) {
                    nrows = playbackBuffer->size[0] - 1;
                    for (j = 0; j <= ncolx; j++) {
                      b_i = idx->data[0];
                      for (input_sizes_idx_0 = b_i; input_sizes_idx_0 <= nrows;
                           input_sizes_idx_0++) {
                        playbackBuffer->data[(input_sizes_idx_0 +
                                              playbackBuffer->size[0] * j) -
                                             1] =
                            playbackBuffer->data[input_sizes_idx_0 +
                                                 playbackBuffer->size[0] * j];
                      }
                    }
                  } else {
                    b_i = b->size[0] * b->size[1];
                    b->size[0] = 1;
                    b->size[1] = playbackBuffer->size[0];
                    emxEnsureCapacity_boolean_T(b, b_i);
                    input_sizes_idx_0 = playbackBuffer->size[0];
                    for (b_i = 0; b_i < input_sizes_idx_0; b_i++) {
                      b->data[b_i] = false;
                    }
                    b_i = idx->size[1];
                    for (k = 0; k < b_i; k++) {
                      b->data[idx->data[k] - 1] = true;
                    }
                    nrows = 0;
                    b_i = b->size[1];
                    for (k = 0; k < b_i; k++) {
                      nrows += b->data[k];
                    }
                    nrows = playbackBuffer->size[0] - nrows;
                    input_sizes_idx_0 = 0;
                    for (k = 0; k < sizes_idx_0; k++) {
                      if ((k + 1 > b->size[1]) || (!b->data[k])) {
                        for (j = 0; j <= ncolx; j++) {
                          playbackBuffer->data[input_sizes_idx_0 +
                                               playbackBuffer->size[0] * j] =
                              playbackBuffer
                                  ->data[k + playbackBuffer->size[0] * j];
                        }
                        input_sizes_idx_0++;
                      }
                    }
                  }
                  if (1 > nrows) {
                    input_sizes_idx_0 = 0;
                  } else {
                    input_sizes_idx_0 = nrows;
                  }
                  nrows = playbackBuffer->size[1] - 1;
                  for (b_i = 0; b_i <= nrows; b_i++) {
                    for (ncolx = 0; ncolx < input_sizes_idx_0; ncolx++) {
                      playbackBuffer->data[ncolx + input_sizes_idx_0 * b_i] =
                          playbackBuffer
                              ->data[ncolx + playbackBuffer->size[0] * b_i];
                    }
                  }
                  b_i = playbackBuffer->size[0] * playbackBuffer->size[1];
                  playbackBuffer->size[0] = input_sizes_idx_0;
                  playbackBuffer->size[1] = nrows + 1;
                  emxEnsureCapacity_real32_T(playbackBuffer, b_i);
                }
              }
              /*  Debug %  IGNORE+++START */
              /*   IGNORE+++END */
              /*  Increment frame only when the whole routine is complete */
            }
          }
        } else {
          exitg2 = 1;
        }
      } while (exitg2 == 0);
      /*  profile off */
      /*  profile viewer */
      /*     %% Release UDP & audio device and hide debug settings */
      /*  Clear the UDP connection */
      /*  Clear the UDP object */
      /*  Release the audio device */
      SystemCore_release(&lobj_0);
      exitg1 = 1;
    }
  } while (exitg1 == 0);
  emxFree_real32_T(&b_playbackBuffer);
  emxFree_boolean_T(&b);
  emxFree_int32_T(&idx);
  emxFree_real32_T(&playbackBuffer);
  emxFree_real32_T(&testFrame_audioFrameBuff);
  if (!lobj_0.matlabCodegenIsDeleted) {
    lobj_0.matlabCodegenIsDeleted = true;
    SystemCore_release(&lobj_0);
  }
  obj = &lobj_0.pInterface;
  /* System object Destructor function: audiointerface.audioDeviceWriter */
  if (obj->S0_isInitialized == 1) {
    obj->S0_isInitialized = 2;
    /* System object Terminate function: audiointerface.audioDeviceWriter */
    sErr = GetErrorBuffer(&obj->W0_AudioDeviceLib[0U]);
    LibTerminate(&obj->W0_AudioDeviceLib[0U]);
    if (*sErr != 0) {
      PrintError(sErr);
    }
    LibDestroy_Audio(&obj->W0_AudioDeviceLib[0U], 1, 1);
    DestroyHostLibrary(&obj->W0_AudioDeviceLib[0U]);
  }
  emxFree_real32_T(&U0);
}

/*
 * File trailer for MainProcess.c
 *
 * [EOF]
 */
