/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: MainProcess_data.c
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 13-Nov-2021 13:55:06
 */

/* Include Files */
#include "MainProcess_data.h"
#include "rt_nonfinite.h"
#include "DAHostLib_rtw.h"
#include "HostLib_Audio.h"
#include <string.h>

/* Variable Definitions */
boolean_T STATE_IN_LOOP_FLAG_;

double freq;

boolean_T freq_not_empty;

unsigned char output_[14756238];

double i;

boolean_T FLUSH_UDP_BUFFER_FLAG_;

boolean_T isInitialized_MainProcess = false;

/*
 * File trailer for MainProcess_data.c
 *
 * [EOF]
 */
