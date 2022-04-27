/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * nullAssignment.c
 *
 * Code generation for function 'nullAssignment'
 *
 */

/* Include files */
#include "nullAssignment.h"
#include "MainProcess_emxutil.h"
#include "MainProcess_types.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "DAHostLib_rtw.h"
#include "HostLib_Audio.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo ob_emlrtRSI = {
    21,                               /* lineNo */
    "eml_int_forloop_overflow_check", /* fcnName */
    "D:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\eml\\eml_int_forloop_"
    "overflow_check.m" /* pathName */
};

static emlrtRSInfo uc_emlrtRSI = {
    22,               /* lineNo */
    "nullAssignment", /* fcnName */
    "D:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\nullAssignment.m" /* pathName */
};

static emlrtRSInfo vc_emlrtRSI = {
    26,               /* lineNo */
    "nullAssignment", /* fcnName */
    "D:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\nullAssignment.m" /* pathName */
};

static emlrtRSInfo wc_emlrtRSI = {
    274,           /* lineNo */
    "delete_rows", /* fcnName */
    "D:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\nullAssignment.m" /* pathName */
};

static emlrtRSInfo xc_emlrtRSI = {
    283,           /* lineNo */
    "delete_rows", /* fcnName */
    "D:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\nullAssignment.m" /* pathName */
};

static emlrtRSInfo yc_emlrtRSI = {
    285,           /* lineNo */
    "delete_rows", /* fcnName */
    "D:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\nullAssignment.m" /* pathName */
};

static emlrtRSInfo ad_emlrtRSI = {
    288,           /* lineNo */
    "delete_rows", /* fcnName */
    "D:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\nullAssignment.m" /* pathName */
};

static emlrtRSInfo bd_emlrtRSI = {
    290,           /* lineNo */
    "delete_rows", /* fcnName */
    "D:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\nullAssignment.m" /* pathName */
};

static emlrtRSInfo cd_emlrtRSI = {
    259,             /* lineNo */
    "make_bitarray", /* fcnName */
    "D:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\nullAssignment.m" /* pathName */
};

static emlrtRSInfo dd_emlrtRSI = {
    132,        /* lineNo */
    "num_true", /* fcnName */
    "D:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\nullAssignment.m" /* pathName */
};

static emlrtRTEInfo o_emlrtRTEI = {
    81,                /* lineNo */
    27,                /* colNo */
    "validate_inputs", /* fName */
    "D:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\nullAssignment.m" /* pName */
};

static emlrtRTEInfo p_emlrtRTEI = {
    297,           /* lineNo */
    1,             /* colNo */
    "delete_rows", /* fName */
    "D:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\nullAssignment.m" /* pName */
};

static emlrtRTEInfo bb_emlrtRTEI = {
    283,              /* lineNo */
    9,                /* colNo */
    "nullAssignment", /* fName */
    "D:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\nullAssignment.m" /* pName */
};

static emlrtRTEInfo cb_emlrtRTEI = {
    26,               /* lineNo */
    13,               /* colNo */
    "nullAssignment", /* fName */
    "D:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\nullAssignment.m" /* pName */
};

static emlrtRTEInfo db_emlrtRTEI = {
    281,              /* lineNo */
    9,                /* colNo */
    "nullAssignment", /* fName */
    "D:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\nullAssignment.m" /* pName */
};

/* Function Definitions */
void nullAssignment(const emlrtStack *sp, emxArray_real32_T *x,
                    const emxArray_int32_T *idx)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  emxArray_boolean_T *b;
  int32_T b_i;
  int32_T j;
  int32_T k;
  int32_T ncolx;
  int32_T nrows;
  int32_T nrowx;
  boolean_T exitg1;
  boolean_T overflow;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  st.site = &uc_emlrtRSI;
  overflow = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k <= idx->size[1] - 1)) {
    if (idx->data[k] > x->size[0]) {
      overflow = false;
      exitg1 = true;
    } else {
      k++;
    }
  }
  if (!overflow) {
    emlrtErrorWithMessageIdR2018a(&st, &o_emlrtRTEI,
                                  "MATLAB:subsdeldimmismatch",
                                  "MATLAB:subsdeldimmismatch", 0);
  }
  st.site = &vc_emlrtRSI;
  nrowx = x->size[0];
  ncolx = x->size[1] - 1;
  if (idx->size[1] == 1) {
    nrows = x->size[0] - 1;
    b_st.site = &wc_emlrtRSI;
    for (j = 0; j <= ncolx; j++) {
      k = idx->data[0];
      for (b_i = k; b_i <= nrows; b_i++) {
        x->data[(b_i + x->size[0] * j) - 1] = x->data[b_i + x->size[0] * j];
      }
    }
  } else {
    emxInit_boolean_T(&st, &b, 2, &db_emlrtRTEI, true);
    b_st.site = &xc_emlrtRSI;
    k = b->size[0] * b->size[1];
    b->size[0] = 1;
    b->size[1] = x->size[0];
    emxEnsureCapacity_boolean_T(&b_st, b, k, &bb_emlrtRTEI);
    b_i = x->size[0];
    for (k = 0; k < b_i; k++) {
      b->data[k] = false;
    }
    b_i = idx->size[1];
    c_st.site = &cd_emlrtRSI;
    if (1 > idx->size[1]) {
      overflow = false;
    } else {
      overflow = (idx->size[1] > 2147483646);
    }
    if (overflow) {
      d_st.site = &ob_emlrtRSI;
      check_forloop_overflow_error(&d_st);
    }
    for (k = 0; k < b_i; k++) {
      b->data[idx->data[k] - 1] = true;
    }
    b_st.site = &yc_emlrtRSI;
    nrows = 0;
    b_i = b->size[1];
    c_st.site = &dd_emlrtRSI;
    if (1 > b->size[1]) {
      overflow = false;
    } else {
      overflow = (b->size[1] > 2147483646);
    }
    if (overflow) {
      d_st.site = &ob_emlrtRSI;
      check_forloop_overflow_error(&d_st);
    }
    for (k = 0; k < b_i; k++) {
      nrows += b->data[k];
    }
    nrows = x->size[0] - nrows;
    b_i = 0;
    b_st.site = &ad_emlrtRSI;
    if (1 > x->size[0]) {
      overflow = false;
    } else {
      overflow = (x->size[0] > 2147483646);
    }
    if (overflow) {
      c_st.site = &ob_emlrtRSI;
      check_forloop_overflow_error(&c_st);
    }
    for (k = 0; k < nrowx; k++) {
      if ((k + 1 > b->size[1]) || (!b->data[k])) {
        b_st.site = &bd_emlrtRSI;
        for (j = 0; j <= ncolx; j++) {
          x->data[b_i + x->size[0] * j] = x->data[k + x->size[0] * j];
        }
        b_i++;
      }
    }
    emxFree_boolean_T(&b);
  }
  if (nrows > nrowx) {
    emlrtErrorWithMessageIdR2018a(&st, &p_emlrtRTEI,
                                  "Coder:builtins:AssertionFailed",
                                  "Coder:builtins:AssertionFailed", 0);
  }
  if (1 > nrows) {
    nrows = 0;
  }
  b_i = x->size[1] - 1;
  for (k = 0; k <= b_i; k++) {
    for (nrowx = 0; nrowx < nrows; nrowx++) {
      x->data[nrowx + nrows * k] = x->data[nrowx + x->size[0] * k];
    }
  }
  k = x->size[0] * x->size[1];
  x->size[0] = nrows;
  x->size[1] = b_i + 1;
  emxEnsureCapacity_real32_T(&st, x, k, &cb_emlrtRTEI);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

/* End of code generation (nullAssignment.c) */
