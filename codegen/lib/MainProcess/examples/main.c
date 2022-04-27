/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: main.c
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 13-Nov-2021 13:55:06
 */

/*************************************************************************/
/* This automatically generated example C main file shows how to call    */
/* entry-point functions that MATLAB Coder generated. You must customize */
/* this file for your application. Do not modify this file directly.     */
/* Instead, make a copy of this file, modify it, and integrate it into   */
/* your development environment.                                         */
/*                                                                       */
/* This file initializes entry-point function arguments to a default     */
/* size and value before calling the entry-point functions. It does      */
/* not store or use any values returned from the entry-point functions.  */
/* If necessary, it does pre-allocate memory for returned values.        */
/* You can use this file as a starting point for a main function that    */
/* you can deploy in your application.                                   */
/*                                                                       */
/* After you copy the file, and before you deploy it, you must make the  */
/* following changes:                                                    */
/* * For variable-size function arguments, change the example sizes to   */
/* the sizes that your application requires.                             */
/* * Change the example values of function arguments to the values that  */
/* your application requires.                                            */
/* * If the entry-point functions return values, store these values or   */
/* otherwise use them as required by your application.                   */
/*                                                                       */
/*************************************************************************/

/* Include Files */
#include "main.h"
#include "MainProcess.h"
#include "MainProcess_terminate.h"
#include "rt_nonfinite.h"
#include "DAHostLib_rtw.h"
#include "HostLib_Audio.h"
#include <string.h>

/* Function Declarations */
static void argInit_1x11_char_T(char result[11]);

static void argInit_1x7_char_T(char result[7]);

static void argInit_1xd13_char_T(char result_data[], int result_size[2]);

static boolean_T argInit_boolean_T(void);

static char argInit_char_T(void);

static double argInit_real_T(void);

static void main_MainProcess(void);

/* Function Definitions */
/*
 * Arguments    : char result[11]
 * Return Type  : void
 */
static void argInit_1x11_char_T(char result[11])
{
  int idx1;
  /* Loop over the array to initialize each element. */
  for (idx1 = 0; idx1 < 11; idx1++) {
    /* Set the value of the array element.
Change this value to the value that the application requires. */
    result[idx1] = argInit_char_T();
  }
}

/*
 * Arguments    : char result[7]
 * Return Type  : void
 */
static void argInit_1x7_char_T(char result[7])
{
  int idx1;
  /* Loop over the array to initialize each element. */
  for (idx1 = 0; idx1 < 7; idx1++) {
    /* Set the value of the array element.
Change this value to the value that the application requires. */
    result[idx1] = argInit_char_T();
  }
}

/*
 * Arguments    : char result_data[]
 *                int result_size[2]
 * Return Type  : void
 */
static void argInit_1xd13_char_T(char result_data[], int result_size[2])
{
  int idx1;
  /* Set the size of the array.
Change this size to the value that the application requires. */
  result_size[0] = 1;
  result_size[1] = 2;
  /* Loop over the array to initialize each element. */
  for (idx1 = 0; idx1 < 2; idx1++) {
    /* Set the value of the array element.
Change this value to the value that the application requires. */
    result_data[idx1] = argInit_char_T();
  }
}

/*
 * Arguments    : void
 * Return Type  : boolean_T
 */
static boolean_T argInit_boolean_T(void)
{
  return false;
}

/*
 * Arguments    : void
 * Return Type  : char
 */
static char argInit_char_T(void)
{
  return '?';
}

/*
 * Arguments    : void
 * Return Type  : double
 */
static double argInit_real_T(void)
{
  return 0.0;
}

/*
 * Arguments    : void
 * Return Type  : void
 */
static void main_MainProcess(void)
{
  int ReaStreamIDtag_size[2];
  char ReaStreamIDtag_data[13];
  char cv[11];
  char cv1[7];
  /* Initialize function 'MainProcess' input arguments. */
  /* Initialize function input argument 'ReaStreamIDtag'. */
  argInit_1xd13_char_T(ReaStreamIDtag_data, ReaStreamIDtag_size);
  /* Initialize function input argument 'driverSelection'. */
  /* Initialize function input argument 'deviceSelection'. */
  /* Call the entry-point 'MainProcess'. */
  argInit_1x11_char_T(cv);
  argInit_1x7_char_T(cv1);
  MainProcess(ReaStreamIDtag_data, ReaStreamIDtag_size, cv, cv1,
              argInit_real_T(), argInit_boolean_T());
}

/*
 * Arguments    : int argc
 *                char **argv
 * Return Type  : int
 */
int main(int argc, char **argv)
{
  (void)argc;
  (void)argv;
  /* The initialize function is being called automatically from your entry-point
   * function. So, a call to initialize is not included here. */
  /* Invoke the entry-point functions.
You can call entry-point functions multiple times. */
  main_MainProcess();
  /* Terminate the application.
You do not need to do this more than one time. */
  MainProcess_terminate();
  return 0;
}

/*
 * File trailer for main.c
 *
 * [EOF]
 */
