/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: MainProcess_internal_types.h
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 13-Nov-2021 13:55:06
 */

#ifndef MAINPROCESS_INTERNAL_TYPES_H
#define MAINPROCESS_INTERNAL_TYPES_H

/* Include Files */
#include "MainProcess_types.h"
#include "rtwtypes.h"

/* Type Definitions */
#ifndef typedef_c_audiointerface_audioDeviceWri
#define typedef_c_audiointerface_audioDeviceWri
typedef struct {
  int S0_isInitialized;
  unsigned char W0_AudioDeviceLib[1096];
  unsigned int W1_numChans;
  unsigned int O0_Y0;
} c_audiointerface_audioDeviceWri;
#endif /* typedef_c_audiointerface_audioDeviceWri */

#ifndef typedef_cell_wrap_3
#define typedef_cell_wrap_3
typedef struct {
  unsigned int f1[8];
} cell_wrap_3;
#endif /* typedef_cell_wrap_3 */

#ifndef typedef_audioDeviceWriter
#define typedef_audioDeviceWriter
typedef struct {
  boolean_T matlabCodegenIsDeleted;
  int isInitialized;
  boolean_T isSetupComplete;
  boolean_T TunablePropsChanged;
  cell_wrap_3 inputVarSize[1];
  c_audiointerface_audioDeviceWri pInterface;
} audioDeviceWriter;
#endif /* typedef_audioDeviceWriter */

#endif
/*
 * File trailer for MainProcess_internal_types.h
 *
 * [EOF]
 */
