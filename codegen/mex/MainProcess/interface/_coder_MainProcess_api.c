/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_MainProcess_api.c
 *
 * Code generation for function '_coder_MainProcess_api'
 *
 */

/* Include files */
#include "_coder_MainProcess_api.h"
#include "MainProcess.h"
#include "MainProcess_data.h"
#include "rt_nonfinite.h"
#include "DAHostLib_rtw.h"
#include "HostLib_Audio.h"
#include <string.h>

/* Function Declarations */
static boolean_T b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                    const emlrtMsgIdentifier *parentId);

static const mxArray *b_emlrt_marshallOut(const uint8_T u[14756238]);

static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *b_output_,
                               const char_T *identifier, uint8_T y[14756238]);

static const mxArray *c_emlrt_marshallOut(const real_T u);

static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               uint8_T y[14756238]);

static real_T e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *b_i,
                                 const char_T *identifier);

static boolean_T emlrt_marshallIn(const emlrtStack *sp,
                                  const mxArray *b_STATE_IN_LOOP_FLAG_,
                                  const char_T *identifier);

static const mxArray *emlrt_marshallOut(const boolean_T u);

static real_T f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                 const emlrtMsgIdentifier *parentId);

static void g_emlrt_marshallIn(const emlrtStack *sp,
                               const mxArray *ReaStreamIDtag,
                               const char_T *identifier, char_T y_data[],
                               int32_T y_size[2]);

static void h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               char_T y_data[], int32_T y_size[2]);

static void i_emlrt_marshallIn(const emlrtStack *sp,
                               const mxArray *driverSelection,
                               const char_T *identifier, char_T y[11]);

static void j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               char_T y[11]);

static void k_emlrt_marshallIn(const emlrtStack *sp,
                               const mxArray *deviceSelection,
                               const char_T *identifier, char_T y[7]);

static void l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId, char_T y[7]);

static boolean_T m_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                    const emlrtMsgIdentifier *msgId);

static void n_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               uint8_T ret[14756238]);

static real_T o_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                 const emlrtMsgIdentifier *msgId);

static void p_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               char_T ret_data[], int32_T ret_size[2]);

static void q_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId, char_T ret[11]);

static void r_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId, char_T ret[7]);

/* Function Definitions */
static boolean_T b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                    const emlrtMsgIdentifier *parentId)
{
  boolean_T y;
  y = m_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static const mxArray *b_emlrt_marshallOut(const uint8_T u[14756238])
{
  static const int32_T iv[2] = {1, 14756238};
  const mxArray *m;
  const mxArray *y;
  int32_T b_i;
  uint8_T *pData;
  y = NULL;
  m = emlrtCreateNumericArray(2, (const void *)&iv[0], mxUINT8_CLASS, mxREAL);
  pData = (uint8_T *)emlrtMxGetData(m);
  for (b_i = 0; b_i < 14756238; b_i++) {
    pData[b_i] = u[b_i];
  }
  emlrtAssign(&y, m);
  return y;
}

static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *b_output_,
                               const char_T *identifier, uint8_T y[14756238])
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  d_emlrt_marshallIn(sp, emlrtAlias(b_output_), &thisId, y);
  emlrtDestroyArray(&b_output_);
}

static const mxArray *c_emlrt_marshallOut(const real_T u)
{
  const mxArray *m;
  const mxArray *y;
  y = NULL;
  m = emlrtCreateDoubleScalar(u);
  emlrtAssign(&y, m);
  return y;
}

static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               uint8_T y[14756238])
{
  n_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static real_T e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *b_i,
                                 const char_T *identifier)
{
  emlrtMsgIdentifier thisId;
  real_T y;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = f_emlrt_marshallIn(sp, emlrtAlias(b_i), &thisId);
  emlrtDestroyArray(&b_i);
  return y;
}

static boolean_T emlrt_marshallIn(const emlrtStack *sp,
                                  const mxArray *b_STATE_IN_LOOP_FLAG_,
                                  const char_T *identifier)
{
  emlrtMsgIdentifier thisId;
  boolean_T y;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = b_emlrt_marshallIn(sp, emlrtAlias(b_STATE_IN_LOOP_FLAG_), &thisId);
  emlrtDestroyArray(&b_STATE_IN_LOOP_FLAG_);
  return y;
}

static const mxArray *emlrt_marshallOut(const boolean_T u)
{
  const mxArray *m;
  const mxArray *y;
  y = NULL;
  m = emlrtCreateLogicalScalar(u);
  emlrtAssign(&y, m);
  return y;
}

static real_T f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                 const emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = o_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static void g_emlrt_marshallIn(const emlrtStack *sp,
                               const mxArray *ReaStreamIDtag,
                               const char_T *identifier, char_T y_data[],
                               int32_T y_size[2])
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  h_emlrt_marshallIn(sp, emlrtAlias(ReaStreamIDtag), &thisId, y_data, y_size);
  emlrtDestroyArray(&ReaStreamIDtag);
}

static void h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               char_T y_data[], int32_T y_size[2])
{
  p_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y_data, y_size);
  emlrtDestroyArray(&u);
}

static void i_emlrt_marshallIn(const emlrtStack *sp,
                               const mxArray *driverSelection,
                               const char_T *identifier, char_T y[11])
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  j_emlrt_marshallIn(sp, emlrtAlias(driverSelection), &thisId, y);
  emlrtDestroyArray(&driverSelection);
}

static void j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId, char_T y[11])
{
  q_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void k_emlrt_marshallIn(const emlrtStack *sp,
                               const mxArray *deviceSelection,
                               const char_T *identifier, char_T y[7])
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  l_emlrt_marshallIn(sp, emlrtAlias(deviceSelection), &thisId, y);
  emlrtDestroyArray(&deviceSelection);
}

static void l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId, char_T y[7])
{
  r_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static boolean_T m_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                    const emlrtMsgIdentifier *msgId)
{
  static const int32_T dims = 0;
  boolean_T ret;
  emlrtCheckBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"logical",
                          false, 0U, (void *)&dims);
  ret = *emlrtMxGetLogicals(src);
  emlrtDestroyArray(&src);
  return ret;
}

static void n_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               uint8_T ret[14756238])
{
  static const int32_T dims[2] = {1, 14756238};
  int32_T b_i;
  uint8_T(*r)[14756238];
  emlrtCheckBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"uint8",
                          false, 2U, (void *)&dims[0]);
  r = (uint8_T(*)[14756238])emlrtMxGetData(src);
  for (b_i = 0; b_i < 14756238; b_i++) {
    ret[b_i] = (*r)[b_i];
  }
  emlrtDestroyArray(&src);
}

static real_T o_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                 const emlrtMsgIdentifier *msgId)
{
  static const int32_T dims = 0;
  real_T ret;
  emlrtCheckBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"double",
                          false, 0U, (void *)&dims);
  ret = *(real_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static void p_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               char_T ret_data[], int32_T ret_size[2])
{
  static const int32_T dims[2] = {1, 13};
  int32_T iv[2];
  const boolean_T bv[2] = {false, true};
  emlrtCheckVsBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"char",
                            false, 2U, (void *)&dims[0], &bv[0], &iv[0]);
  ret_size[0] = iv[0];
  ret_size[1] = iv[1];
  emlrtImportArrayR2015b((emlrtCTX)sp, src, &ret_data[0], 1, false);
  emlrtDestroyArray(&src);
}

static void q_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId, char_T ret[11])
{
  static const int32_T dims[2] = {1, 11};
  emlrtCheckBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"char",
                          false, 2U, (void *)&dims[0]);
  emlrtImportCharArrayR2015b((emlrtCTX)sp, src, &ret[0], 11);
  emlrtDestroyArray(&src);
}

static void r_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId, char_T ret[7])
{
  static const int32_T dims[2] = {1, 7};
  emlrtCheckBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"char",
                          false, 2U, (void *)&dims[0]);
  emlrtImportCharArrayR2015b((emlrtCTX)sp, src, &ret[0], 7);
  emlrtDestroyArray(&src);
}

void MEXGlobalSyncInFunction(const emlrtStack *sp)
{
  const mxArray *tmp;
  /* Marshall in global variables */
  tmp = emlrtGetGlobalVariable((const char_T *)"STATE_IN_LOOP_FLAG_");
  if (tmp != NULL) {
    STATE_IN_LOOP_FLAG_ = emlrt_marshallIn(sp, tmp, "STATE_IN_LOOP_FLAG_");
    STATE_IN_LOOP_FLAG__dirty = 0U;
  }
  tmp = emlrtGetGlobalVariable((const char_T *)"output_");
  if (tmp != NULL) {
    c_emlrt_marshallIn(sp, tmp, "output_", output_);
    output__dirty = 0U;
  }
  tmp = emlrtGetGlobalVariable((const char_T *)"i");
  if (tmp != NULL) {
    i = e_emlrt_marshallIn(sp, tmp, "i");
    i_dirty = 0U;
  }
  tmp = emlrtGetGlobalVariable((const char_T *)"FLUSH_UDP_BUFFER_FLAG_");
  if (tmp != NULL) {
    FLUSH_UDP_BUFFER_FLAG_ =
        emlrt_marshallIn(sp, tmp, "FLUSH_UDP_BUFFER_FLAG_");
    FLUSH_UDP_BUFFER_FLAG__dirty = 0U;
  }
}

void MEXGlobalSyncOutFunction(boolean_T skipDirtyCheck)
{
  /* Marshall out global variables */
  if (skipDirtyCheck || (STATE_IN_LOOP_FLAG__dirty != 0U)) {
    emlrtPutGlobalVariable((const char_T *)"STATE_IN_LOOP_FLAG_",
                           emlrt_marshallOut(STATE_IN_LOOP_FLAG_));
  }
  if (skipDirtyCheck || (output__dirty != 0U)) {
    emlrtPutGlobalVariable((const char_T *)"output_",
                           b_emlrt_marshallOut(output_));
  }
  if (skipDirtyCheck || (i_dirty != 0U)) {
    emlrtPutGlobalVariable((const char_T *)"i", c_emlrt_marshallOut(i));
  }
  if (skipDirtyCheck || (FLUSH_UDP_BUFFER_FLAG__dirty != 0U)) {
    emlrtPutGlobalVariable((const char_T *)"FLUSH_UDP_BUFFER_FLAG_",
                           emlrt_marshallOut(FLUSH_UDP_BUFFER_FLAG_));
  }
}

void MainProcess_api(const mxArray *const prhs[5])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  real_T pbSampSize;
  int32_T ReaStreamIDtag_size[2];
  char_T ReaStreamIDtag_data[13];
  char_T driverSelection[11];
  char_T deviceSelection[7];
  boolean_T VariableBufferON;
  st.tls = emlrtRootTLSGlobal;
  /* Marshall function inputs */
  g_emlrt_marshallIn(&st, emlrtAliasP(prhs[0]), "ReaStreamIDtag",
                     ReaStreamIDtag_data, ReaStreamIDtag_size);
  i_emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "driverSelection",
                     driverSelection);
  k_emlrt_marshallIn(&st, emlrtAliasP(prhs[2]), "deviceSelection",
                     deviceSelection);
  pbSampSize = e_emlrt_marshallIn(&st, emlrtAliasP(prhs[3]), "pbSampSize");
  VariableBufferON =
      emlrt_marshallIn(&st, emlrtAliasP(prhs[4]), "VariableBufferON");
  /* Marshall in global variables */
  MEXGlobalSyncInFunction(&st);
  /* Invoke the target function */
  MainProcess(&st, ReaStreamIDtag_data, ReaStreamIDtag_size, driverSelection,
              deviceSelection, pbSampSize, VariableBufferON);
  /* Marshall out global variables */
  MEXGlobalSyncOutFunction(true);
}

void emlrt_synchGlobalsFromML(const emlrtStack *sp)
{
  MEXGlobalSyncInFunction(sp);
  STATE_IN_LOOP_FLAG__dirty = 0U;
  output__dirty = 0U;
  i_dirty = 0U;
  FLUSH_UDP_BUFFER_FLAG__dirty = 0U;
}

void emlrt_synchGlobalsToML(const emlrtStack *sp)
{
  (void)sp;
  MEXGlobalSyncOutFunction(false);
}

/* End of code generation (_coder_MainProcess_api.c) */
