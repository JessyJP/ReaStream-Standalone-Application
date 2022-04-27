/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * MainProcess_internal_types.h
 *
 * Code generation for function 'MainProcess'
 *
 */

#pragma once

/* Include files */
#include "MainProcess_types.h"
#include "rtwtypes.h"
#include "emlrt.h"

/* Type Definitions */
#ifndef typedef_c_audiointerface_audioDeviceWri
#define typedef_c_audiointerface_audioDeviceWri
typedef struct {
  int32_T S0_isInitialized;
  uint8_T W0_AudioDeviceLib[1096];
  uint32_T W1_numChans;
  uint32_T O0_Y0;
} c_audiointerface_audioDeviceWri;
#endif /* typedef_c_audiointerface_audioDeviceWri */

#ifndef typedef_cell_wrap_3
#define typedef_cell_wrap_3
typedef struct {
  uint32_T f1[8];
} cell_wrap_3;
#endif /* typedef_cell_wrap_3 */

#ifndef typedef_audioDeviceWriter
#define typedef_audioDeviceWriter
typedef struct {
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  boolean_T TunablePropsChanged;
  cell_wrap_3 inputVarSize[1];
  c_audiointerface_audioDeviceWri pInterface;
} audioDeviceWriter;
#endif /* typedef_audioDeviceWriter */

#ifndef typedef_rtDesignRangeCheckInfo
#define typedef_rtDesignRangeCheckInfo
typedef struct {
  int32_T lineNo;
  int32_T colNo;
  const char_T *fName;
  const char_T *pName;
} rtDesignRangeCheckInfo;
#endif /* typedef_rtDesignRangeCheckInfo */

/* End of code generation (MainProcess_internal_types.h) */
