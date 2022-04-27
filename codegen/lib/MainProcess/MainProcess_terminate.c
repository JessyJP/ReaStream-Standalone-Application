/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: MainProcess_terminate.c
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 13-Nov-2021 13:55:06
 */

/* Include Files */
#include "MainProcess_terminate.h"
#include "MainProcess_data.h"
#include "rt_nonfinite.h"
#include "DAHostLib_rtw.h"
#include "HostLib_Audio.h"
#include <string.h>

/* Function Definitions */
/*
 * Arguments    : void
 * Return Type  : void
 */
void MainProcess_terminate(void)
{
  /* (no terminate code required) */
  isInitialized_MainProcess = false;
}

/*
 * File trailer for MainProcess_terminate.c
 *
 * [EOF]
 */
