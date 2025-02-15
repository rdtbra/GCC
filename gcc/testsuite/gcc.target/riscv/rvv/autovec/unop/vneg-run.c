/* { dg-do run { target { riscv_vector } } } */
/* { dg-additional-options "-std=c99 -fno-vect-cost-model --param=riscv-autovec-preference=fixed-vlmax" } */

#include "vneg-template.h"

#include <assert.h>

#define SZ 255

#define RUN(TYPE)				\
  TYPE a##TYPE[SZ];				\
  for (int i = 0; i < SZ; i++)			\
  {                             		\
    a##TYPE[i] = i - 127;             		\
  }                             		\
  vneg_##TYPE (a##TYPE, a##TYPE, SZ);	\
  for (int i = 0; i < SZ; i++)			\
    assert (a##TYPE[i] == -(i - 127));

#define RUN_ALL()	                        \
 RUN(int8_t)	                                \
 RUN(int16_t)	                                \
 RUN(int32_t)	                                \
 RUN(int64_t)

int main ()
{
  RUN_ALL()
}
