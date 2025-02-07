/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'ozysdriverandreceiver/Solver Configuration'.
 */

#include "ne_ds.h"
#include "ozysdriverandreceiver_d22bbe4d_49_ds_sys_struct.h"
#include "ozysdriverandreceiver_d22bbe4d_49_ds_acon.h"
#include "ozysdriverandreceiver_d22bbe4d_49_ds.h"
#include "ozysdriverandreceiver_d22bbe4d_49_ds_externals.h"
#include "ozysdriverandreceiver_d22bbe4d_49_ds_external_struct.h"
#include "ssc_ml_fun.h"

int32_T ozysdriverandreceiver_d22bbe4d_49_ds_acon(const NeDynamicSystem *sys,
  const NeDynamicSystemInput *t57, NeDsMethodOutput *out)
{
  real_T t10[6];
  real_T t18[6];
  real_T t19[6];
  real_T t2[6];
  real_T t8[6];
  real_T t11[5];
  real_T t12[5];
  real_T t15[5];
  real_T t6[5];
  real_T t9[5];
  real_T t1[4];
  real_T t16[4];
  size_t t27;
  (void)t57;
  t1[0UL] = -0.0;
  t1[1UL] = 1.0E-6;
  t1[2UL] = -0.013888888888888888;
  t1[3UL] = 0.013888888888888888;
  t2[0UL] = -0.0;
  t2[1UL] = -1.5384615384615385E-6;
  t2[2UL] = -4.395604395604396E-6;
  t2[3UL] = -1.0000000000015385;
  t2[4UL] = -1.0000000000043956;
  t2[5UL] = 1.5384615384615385E-6;
  t6[0UL] = -0.013888888888888888;
  t6[1UL] = 0.027777777777777776;
  t6[2UL] = -0.027777777777777776;
  t6[3UL] = 0.013888888888888888;
  t6[4UL] = 0.013888888888888888;
  t8[0UL] = 1.5384615384615385E-6;
  t8[1UL] = 2.8571428571428573E-6;
  t8[2UL] = 1.0000000000015385;
  t8[3UL] = 1.000000000002857;
  t8[4UL] = 0.00015008912655971478;
  t8[5UL] = -3.0303030303030305E-6;
  t9[0UL] = 1.0;
  t9[1UL] = 1.0E-6;
  t9[2UL] = -0.013888888888888888;
  t9[3UL] = 0.013889888888888887;
  t9[4UL] = -1.0E-6;
  t10[0UL] = 3.0303030303030305E-6;
  t10[1UL] = -3.0303030303030305E-6;
  t10[2UL] = -1.0;
  t10[3UL] = 3.0303030303030305E-12;
  t10[4UL] = -3.0303030303030305E-12;
  t10[5UL] = 1.0000030303030303;
  t11[0UL] = -0.00015162758809817632;
  t11[1UL] = 0.00015008912655971478;
  t11[2UL] = -1.0000000001516276;
  t11[3UL] = 1.5008912655971478E-10;
  t11[4UL] = -3.0303030303030305E-6;
  t12[0UL] = 0.013888888888888888;
  t12[1UL] = 1.0;
  t12[2UL] = 1.0E-6;
  t12[3UL] = -0.013888888888888888;
  t12[4UL] = 0.013888888888888888;
  t15[0UL] = -0.013889888888888887;
  t15[1UL] = 0.013888888888888888;
  t15[2UL] = 2.0E-6;
  t15[3UL] = -0.027777777777777776;
  t15[4UL] = 0.027777777777777776;
  t16[0UL] = 0.00014705882352941175;
  t16[1UL] = -0.00014705882352941175;
  t16[2UL] = 1.4705882352941175E-10;
  t16[3UL] = -1.4705882352941175E-10;
  t18[0UL] = -1.0;
  t18[1UL] = -1.5384615384615385E-12;
  t18[2UL] = -1.0000000000043956;
  t18[3UL] = -1.0000000000015384E-6;
  t18[4UL] = -2.0000000000043956E-6;
  t18[5UL] = 1.0000000000015385;
  t19[0UL] = 0.013888888888888888;
  t19[1UL] = -0.027777777777777776;
  t19[2UL] = 0.055555555555555552;
  t19[3UL] = -0.013888888888888888;
  t19[4UL] = -0.013888888888888888;
  t19[5UL] = -0.027777777777777776;
  out->mACON.mX[0UL] = -1.0;
  out->mACON.mX[1UL] = -1.0;
  for (t27 = 0UL; t27 < 4UL; t27++) {
    out->mACON.mX[t27 + 2UL] = t1[t27];
  }

  for (t27 = 0UL; t27 < 6UL; t27++) {
    out->mACON.mX[t27 + 6UL] = t2[t27];
  }

  out->mACON.mX[12UL] = -0.0;
  out->mACON.mX[13UL] = -1.0;
  out->mACON.mX[14UL] = -0.0;
  out->mACON.mX[15UL] = -1.0;
  out->mACON.mX[16UL] = -0.0;
  out->mACON.mX[17UL] = -1.0;
  for (t27 = 0UL; t27 < 5UL; t27++) {
    out->mACON.mX[t27 + 18UL] = t6[t27];
  }

  out->mACON.mX[23UL] = -1.0;
  out->mACON.mX[24UL] = -3.0303030303030305E-6;
  out->mACON.mX[25UL] = 1.0000030303030303;
  for (t27 = 0UL; t27 < 6UL; t27++) {
    out->mACON.mX[t27 + 26UL] = t8[t27];
  }

  for (t27 = 0UL; t27 < 5UL; t27++) {
    out->mACON.mX[t27 + 32UL] = t9[t27];
  }

  for (t27 = 0UL; t27 < 6UL; t27++) {
    out->mACON.mX[t27 + 37UL] = t10[t27];
  }

  for (t27 = 0UL; t27 < 5UL; t27++) {
    out->mACON.mX[t27 + 43UL] = t11[t27];
  }

  for (t27 = 0UL; t27 < 5UL; t27++) {
    out->mACON.mX[t27 + 48UL] = t12[t27];
  }

  out->mACON.mX[53UL] = -2.0E-6;
  out->mACON.mX[54UL] = -1.0E-6;
  out->mACON.mX[55UL] = 1.0E-6;
  out->mACON.mX[56UL] = 1.0E-6;
  out->mACON.mX[57UL] = -2.0E-6;
  out->mACON.mX[58UL] = 0.0;
  for (t27 = 0UL; t27 < 5UL; t27++) {
    out->mACON.mX[t27 + 59UL] = t15[t27];
  }

  for (t27 = 0UL; t27 < 4UL; t27++) {
    out->mACON.mX[t27 + 64UL] = t16[t27];
  }

  out->mACON.mX[68UL] = -0.00014705882352941175;
  out->mACON.mX[69UL] = -1.0;
  out->mACON.mX[70UL] = -0.0;
  for (t27 = 0UL; t27 < 6UL; t27++) {
    out->mACON.mX[t27 + 71UL] = t18[t27];
  }

  for (t27 = 0UL; t27 < 6UL; t27++) {
    out->mACON.mX[t27 + 77UL] = t19[t27];
  }

  (void)sys;
  (void)out;
  return 0;
}
