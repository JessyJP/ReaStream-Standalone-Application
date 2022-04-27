/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_MainProcess_mex.c
 *
 * Code generation for function '_coder_MainProcess_mex'
 *
 */

/* Include files */
#include "_coder_MainProcess_mex.h"
#include "MainProcess_data.h"
#include "MainProcess_initialize.h"
#include "MainProcess_terminate.h"
#include "_coder_MainProcess_api.h"
#include "rt_nonfinite.h"
#include "DAHostLib_rtw.h"
#include "HostLib_Audio.h"
#include <string.h>

/* Function Definitions */
void MainProcess_mexFunction(int32_T nlhs, int32_T nrhs, const mxArray *prhs[5])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  st.tls = emlrtRootTLSGlobal;
  /* Check for proper number of arguments. */
  if (nrhs != 5) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 5, 4,
                        11, "MainProcess");
  }
  if (nlhs > 0) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 11,
                        "MainProcess");
  }
  /* Call the function. */
  MainProcess_api(prhs);
}

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs,
                 const mxArray *prhs[])
{
  (void)plhs;
  mexAtExit(&MainProcess_atexit);
  /* Module initialization. */
  MainProcess_initialize();
  /* Dispatch the entry-point. */
  MainProcess_mexFunction(nlhs, nrhs, prhs);
  /* Module termination. */
  MainProcess_terminate();
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLSR2021a(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1,
                           NULL);
  return emlrtRootTLSGlobal;
}

/* End of code generation (_coder_MainProcess_mex.c) */
