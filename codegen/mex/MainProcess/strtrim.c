/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * strtrim.c
 *
 * Code generation for function 'strtrim'
 *
 */

/* Include files */
#include "strtrim.h"
#include "MainProcess_data.h"
#include "rt_nonfinite.h"
#include "DAHostLib_rtw.h"
#include "HostLib_Audio.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo
    fb_emlrtRSI =
        {
            15,          /* lineNo */
            "isstrprop", /* fcnName */
            "D:\\Program "
            "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\strfun\\isstrpro"
            "p.m" /* pathName */
};

static emlrtRSInfo
    gb_emlrtRSI =
        {
            23,                         /* lineNo */
            "apply_property_predicate", /* fcnName */
            "D:\\Program "
            "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\strfun\\isstrpro"
            "p.m" /* pathName */
};

static emlrtRSInfo pb_emlrtRSI = {
    23,        /* lineNo */
    "strtrim", /* fcnName */
    "D:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\strfun\\strtrim.m" /* pathName
                                                                           */
};

static emlrtRSInfo qb_emlrtRSI = {
    24,        /* lineNo */
    "strtrim", /* fcnName */
    "D:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\strfun\\strtrim.m" /* pathName
                                                                           */
};

static emlrtRSInfo rb_emlrtRSI = {
    32,         /* lineNo */
    "firstcol", /* fcnName */
    "D:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\strfun\\strtrim.m" /* pathName
                                                                           */
};

static emlrtRSInfo sb_emlrtRSI = {
    51,          /* lineNo */
    "allwspace", /* fcnName */
    "D:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\strfun\\strtrim.m" /* pathName
                                                                           */
};

static emlrtRSInfo tb_emlrtRSI = {
    41,        /* lineNo */
    "lastcol", /* fcnName */
    "D:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\strfun\\strtrim.m" /* pathName
                                                                           */
};

/* Function Definitions */
void strtrim(const emlrtStack *sp, const char_T x_data[],
             const int32_T x_size[2], char_T y_data[], int32_T y_size[2])
{
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
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack st;
  int32_T b_i;
  int32_T b_j1;
  int32_T j2;
  char_T x;
  boolean_T exitg1;
  boolean_T p;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &pb_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  b_j1 = 0;
  exitg1 = false;
  while ((!exitg1) && (b_j1 + 1 <= x_size[1])) {
    b_st.site = &rb_emlrtRSI;
    c_st.site = &sb_emlrtRSI;
    x = x_data[b_j1];
    d_st.site = &fb_emlrtRSI;
    e_st.site = &gb_emlrtRSI;
    if ((uint8_T)x > 127) {
      emlrtErrorWithMessageIdR2018a(
          &e_st, &h_emlrtRTEI, "Coder:toolbox:unsupportedString",
          "Coder:toolbox:unsupportedString", 2, 12, 127);
    }
    if ((!bv[(uint8_T)x & 127]) || (x_data[b_j1] == '\x00')) {
      p = false;
    } else {
      p = true;
    }
    if (p) {
      b_j1++;
    } else {
      exitg1 = true;
    }
  }
  st.site = &qb_emlrtRSI;
  j2 = x_size[1] - 1;
  exitg1 = false;
  while ((!exitg1) && (j2 + 1 > 0)) {
    b_st.site = &tb_emlrtRSI;
    c_st.site = &sb_emlrtRSI;
    x = x_data[j2];
    d_st.site = &fb_emlrtRSI;
    e_st.site = &gb_emlrtRSI;
    if ((uint8_T)x > 127) {
      emlrtErrorWithMessageIdR2018a(
          &e_st, &h_emlrtRTEI, "Coder:toolbox:unsupportedString",
          "Coder:toolbox:unsupportedString", 2, 12, 127);
    }
    if ((!bv[(uint8_T)x & 127]) || (x_data[j2] == '\x00')) {
      p = false;
    } else {
      p = true;
    }
    if (p) {
      j2--;
    } else {
      exitg1 = true;
    }
  }
  if (b_j1 + 1 > j2 + 1) {
    b_j1 = 0;
    j2 = -1;
  }
  y_size[0] = 1;
  j2 -= b_j1;
  y_size[1] = j2 + 1;
  for (b_i = 0; b_i <= j2; b_i++) {
    y_data[b_i] = x_data[b_j1 + b_i];
  }
}

/* End of code generation (strtrim.c) */
