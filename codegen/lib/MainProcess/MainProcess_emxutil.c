/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: MainProcess_emxutil.c
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 13-Nov-2021 13:55:06
 */

/* Include Files */
#include "MainProcess_emxutil.h"
#include "MainProcess_types.h"
#include "rt_nonfinite.h"
#include "DAHostLib_rtw.h"
#include "HostLib_Audio.h"
#include <stdlib.h>
#include <string.h>

/* Function Definitions */
/*
 * Arguments    : emxArray_boolean_T *emxArray
 *                int oldNumel
 * Return Type  : void
 */
void emxEnsureCapacity_boolean_T(emxArray_boolean_T *emxArray, int oldNumel)
{
  int b_i;
  int newNumel;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }
  newNumel = 1;
  for (b_i = 0; b_i < emxArray->numDimensions; b_i++) {
    newNumel *= emxArray->size[b_i];
  }
  if (newNumel > emxArray->allocatedSize) {
    b_i = emxArray->allocatedSize;
    if (b_i < 16) {
      b_i = 16;
    }
    while (b_i < newNumel) {
      if (b_i > 1073741823) {
        b_i = MAX_int32_T;
      } else {
        b_i *= 2;
      }
    }
    newData = calloc((unsigned int)b_i, sizeof(boolean_T));
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, sizeof(boolean_T) * oldNumel);
      if (emxArray->canFreeData) {
        free(emxArray->data);
      }
    }
    emxArray->data = (boolean_T *)newData;
    emxArray->allocatedSize = b_i;
    emxArray->canFreeData = true;
  }
}

/*
 * Arguments    : emxArray_int32_T *emxArray
 *                int oldNumel
 * Return Type  : void
 */
void emxEnsureCapacity_int32_T(emxArray_int32_T *emxArray, int oldNumel)
{
  int b_i;
  int newNumel;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }
  newNumel = 1;
  for (b_i = 0; b_i < emxArray->numDimensions; b_i++) {
    newNumel *= emxArray->size[b_i];
  }
  if (newNumel > emxArray->allocatedSize) {
    b_i = emxArray->allocatedSize;
    if (b_i < 16) {
      b_i = 16;
    }
    while (b_i < newNumel) {
      if (b_i > 1073741823) {
        b_i = MAX_int32_T;
      } else {
        b_i *= 2;
      }
    }
    newData = calloc((unsigned int)b_i, sizeof(int));
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, sizeof(int) * oldNumel);
      if (emxArray->canFreeData) {
        free(emxArray->data);
      }
    }
    emxArray->data = (int *)newData;
    emxArray->allocatedSize = b_i;
    emxArray->canFreeData = true;
  }
}

/*
 * Arguments    : emxArray_real32_T *emxArray
 *                int oldNumel
 * Return Type  : void
 */
void emxEnsureCapacity_real32_T(emxArray_real32_T *emxArray, int oldNumel)
{
  int b_i;
  int newNumel;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }
  newNumel = 1;
  for (b_i = 0; b_i < emxArray->numDimensions; b_i++) {
    newNumel *= emxArray->size[b_i];
  }
  if (newNumel > emxArray->allocatedSize) {
    b_i = emxArray->allocatedSize;
    if (b_i < 16) {
      b_i = 16;
    }
    while (b_i < newNumel) {
      if (b_i > 1073741823) {
        b_i = MAX_int32_T;
      } else {
        b_i *= 2;
      }
    }
    newData = calloc((unsigned int)b_i, sizeof(float));
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, sizeof(float) * oldNumel);
      if (emxArray->canFreeData) {
        free(emxArray->data);
      }
    }
    emxArray->data = (float *)newData;
    emxArray->allocatedSize = b_i;
    emxArray->canFreeData = true;
  }
}

/*
 * Arguments    : emxArray_uint16_T *emxArray
 *                int oldNumel
 * Return Type  : void
 */
void emxEnsureCapacity_uint16_T(emxArray_uint16_T *emxArray, int oldNumel)
{
  int b_i;
  int newNumel;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }
  newNumel = 1;
  for (b_i = 0; b_i < emxArray->numDimensions; b_i++) {
    newNumel *= emxArray->size[b_i];
  }
  if (newNumel > emxArray->allocatedSize) {
    b_i = emxArray->allocatedSize;
    if (b_i < 16) {
      b_i = 16;
    }
    while (b_i < newNumel) {
      if (b_i > 1073741823) {
        b_i = MAX_int32_T;
      } else {
        b_i *= 2;
      }
    }
    newData = calloc((unsigned int)b_i, sizeof(unsigned short));
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, sizeof(unsigned short) * oldNumel);
      if (emxArray->canFreeData) {
        free(emxArray->data);
      }
    }
    emxArray->data = (unsigned short *)newData;
    emxArray->allocatedSize = b_i;
    emxArray->canFreeData = true;
  }
}

/*
 * Arguments    : emxArray_boolean_T **pEmxArray
 * Return Type  : void
 */
void emxFree_boolean_T(emxArray_boolean_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_boolean_T *)NULL) {
    if (((*pEmxArray)->data != (boolean_T *)NULL) &&
        (*pEmxArray)->canFreeData) {
      free((*pEmxArray)->data);
    }
    free((*pEmxArray)->size);
    free(*pEmxArray);
    *pEmxArray = (emxArray_boolean_T *)NULL;
  }
}

/*
 * Arguments    : emxArray_int32_T **pEmxArray
 * Return Type  : void
 */
void emxFree_int32_T(emxArray_int32_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_int32_T *)NULL) {
    if (((*pEmxArray)->data != (int *)NULL) && (*pEmxArray)->canFreeData) {
      free((*pEmxArray)->data);
    }
    free((*pEmxArray)->size);
    free(*pEmxArray);
    *pEmxArray = (emxArray_int32_T *)NULL;
  }
}

/*
 * Arguments    : emxArray_real32_T **pEmxArray
 * Return Type  : void
 */
void emxFree_real32_T(emxArray_real32_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_real32_T *)NULL) {
    if (((*pEmxArray)->data != (float *)NULL) && (*pEmxArray)->canFreeData) {
      free((*pEmxArray)->data);
    }
    free((*pEmxArray)->size);
    free(*pEmxArray);
    *pEmxArray = (emxArray_real32_T *)NULL;
  }
}

/*
 * Arguments    : emxArray_uint16_T **pEmxArray
 * Return Type  : void
 */
void emxFree_uint16_T(emxArray_uint16_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_uint16_T *)NULL) {
    if (((*pEmxArray)->data != (unsigned short *)NULL) &&
        (*pEmxArray)->canFreeData) {
      free((*pEmxArray)->data);
    }
    free((*pEmxArray)->size);
    free(*pEmxArray);
    *pEmxArray = (emxArray_uint16_T *)NULL;
  }
}

/*
 * Arguments    : emxArray_boolean_T **pEmxArray
 *                int numDimensions
 * Return Type  : void
 */
void emxInit_boolean_T(emxArray_boolean_T **pEmxArray, int numDimensions)
{
  emxArray_boolean_T *emxArray;
  int b_i;
  *pEmxArray = (emxArray_boolean_T *)malloc(sizeof(emxArray_boolean_T));
  emxArray = *pEmxArray;
  emxArray->data = (boolean_T *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int *)malloc(sizeof(int) * numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (b_i = 0; b_i < numDimensions; b_i++) {
    emxArray->size[b_i] = 0;
  }
}

/*
 * Arguments    : emxArray_int32_T **pEmxArray
 *                int numDimensions
 * Return Type  : void
 */
void emxInit_int32_T(emxArray_int32_T **pEmxArray, int numDimensions)
{
  emxArray_int32_T *emxArray;
  int b_i;
  *pEmxArray = (emxArray_int32_T *)malloc(sizeof(emxArray_int32_T));
  emxArray = *pEmxArray;
  emxArray->data = (int *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int *)malloc(sizeof(int) * numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (b_i = 0; b_i < numDimensions; b_i++) {
    emxArray->size[b_i] = 0;
  }
}

/*
 * Arguments    : emxArray_real32_T **pEmxArray
 *                int numDimensions
 * Return Type  : void
 */
void emxInit_real32_T(emxArray_real32_T **pEmxArray, int numDimensions)
{
  emxArray_real32_T *emxArray;
  int b_i;
  *pEmxArray = (emxArray_real32_T *)malloc(sizeof(emxArray_real32_T));
  emxArray = *pEmxArray;
  emxArray->data = (float *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int *)malloc(sizeof(int) * numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (b_i = 0; b_i < numDimensions; b_i++) {
    emxArray->size[b_i] = 0;
  }
}

/*
 * Arguments    : emxArray_uint16_T **pEmxArray
 *                int numDimensions
 * Return Type  : void
 */
void emxInit_uint16_T(emxArray_uint16_T **pEmxArray, int numDimensions)
{
  emxArray_uint16_T *emxArray;
  int b_i;
  *pEmxArray = (emxArray_uint16_T *)malloc(sizeof(emxArray_uint16_T));
  emxArray = *pEmxArray;
  emxArray->data = (unsigned short *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int *)malloc(sizeof(int) * numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (b_i = 0; b_i < numDimensions; b_i++) {
    emxArray->size[b_i] = 0;
  }
}

/*
 * File trailer for MainProcess_emxutil.c
 *
 * [EOF]
 */
