/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'ozysdriverandreceiver/Solver Configuration'.
 */

#include "ne_ds.h"
#include "ozysdriverandreceiver_d22bbe4d_49_ds_sys_struct.h"
#include "ozysdriverandreceiver_d22bbe4d_49_ds_f.h"
#include "ozysdriverandreceiver_d22bbe4d_49_ds.h"
#include "ozysdriverandreceiver_d22bbe4d_49_ds_externals.h"
#include "ozysdriverandreceiver_d22bbe4d_49_ds_external_struct.h"
#include "ssc_ml_fun.h"

int32_T ozysdriverandreceiver_d22bbe4d_49_ds_f(const NeDynamicSystem *sys, const
  NeDynamicSystemInput *t17, NeDsMethodOutput *out)
{
  real_T t11[1];
  real_T t12[1];
  real_T t16[1];
  real_T SG_Variable_Resistor2_v;
  real_T t0;
  real_T t2;
  real_T t3;
  real_T t4;
  real_T t6;
  real_T zc_int3;
  int32_T t13[2];
  out->mF.mX[18UL] = 1.5;
  t6 = -t17->mX.mX[17UL] + t17->mX.mX[18UL];
  SG_Variable_Resistor2_v = -t17->mX.mX[19UL] + t17->mX.mX[17UL];
  if (t17->mM.mX[0UL] != 0) {
    t0 = 0.0;
  } else {
    t11[0] = 0.0;
    t12[0] = 1.0;
    t13[0UL] = t17->mQ.mX[0UL];
    t13[1UL] = t17->mQ.mX[1UL];
    compute_gaussian_value(&t16[0UL], &t11[0UL], &t12[0UL], &t13[0UL]);
    t0 = t16[0UL];
  }

  if (t17->mM.mX[0UL] != 0) {
    zc_int3 = 0.0;
  } else {
    t11[0] = 0.0;
    t12[0] = 1.0;
    t13[0UL] = t17->mQ.mX[2UL];
    t13[1UL] = t17->mQ.mX[3UL];
    compute_gaussian_value(&t16[0UL], &t11[0UL], &t12[0UL], &t13[0UL]);
    zc_int3 = t16[0UL];
  }

  if (t17->mM.mX[6UL] != 0) {
    t3 = 2.5E+9;
  } else {
    t3 = t17->mM.mX[7UL] != 0 ? -2.5E+9 : ((t17->mX.mX[9UL] - t17->mX.mX[12UL]) *
      -44562.5 - t17->mX.mX[0UL]) * 1.5079644737231007E+8;
  }

  if (t17->mM.mX[10UL] != 0) {
    t4 = 2.5E+9;
  } else {
    t4 = t17->mM.mX[11UL] != 0 ? -2.5E+9 : ((t17->mX.mX[12UL] - t17->mX.mX[9UL])
      * -44562.5 - t17->mX.mX[1UL]) * 1.5079644737231007E+8;
  }

  if (t17->mM.mX[1UL] != 0) {
    t2 = -0.0;
  } else {
    t2 = t17->mM.mX[5UL] != 0 ? -0.0 : -t3;
  }

  if (t17->mM.mX[8UL] != 0) {
    t3 = -0.0;
  } else {
    t3 = t17->mM.mX[9UL] != 0 ? -0.0 : -t4;
  }

  if (t17->mM.mX[12UL] != 0) {
    out->mF.mX[12UL] = t6 - t17->mU.mX[0UL] * ((t17->mX.mX[17UL] *
      0.016666666666666666 + t17->mX.mX[20UL]) - 0.052999999999999992);
  } else {
    out->mF.mX[12UL] = t6;
  }

  if (t17->mM.mX[2UL] != 0) {
    out->mF.mX[13UL] = -t17->mX.mX[18UL] - t17->mU.mX[3UL] * ((((t17->mX.mX[17UL]
      * 0.016666666666666666 + t17->mX.mX[18UL] * 0.00014705882352941175) +
      t17->mX.mX[12UL] * -0.00014705882352941175) + t17->mX.mX[20UL]) -
      0.052999999999999992);
  } else {
    out->mF.mX[13UL] = -t17->mX.mX[18UL];
  }

  if (t17->mM.mX[3UL] != 0) {
    out->mF.mX[14UL] = SG_Variable_Resistor2_v - t17->mU.mX[1UL] * t17->mX.mX
      [20UL];
  } else {
    out->mF.mX[14UL] = SG_Variable_Resistor2_v;
  }

  if (t17->mM.mX[4UL] != 0) {
    out->mF.mX[15UL] = t17->mX.mX[19UL] - t17->mU.mX[2UL] * ((t17->mX.mX[19UL] *
      -0.00014705882352941175 + t17->mX.mX[9UL] * 0.00014705882352941175) +
      t17->mX.mX[20UL]);
  } else {
    out->mF.mX[15UL] = t17->mX.mX[19UL];
  }

  out->mF.mX[0UL] = -0.0;
  out->mF.mX[1UL] = -0.0;
  out->mF.mX[2UL] = -0.0;
  out->mF.mX[3UL] = -(t2 / 6.7198666860285674E+12);
  out->mF.mX[4UL] = -(t3 / 6.7198666860285674E+12);
  out->mF.mX[5UL] = -0.0;
  out->mF.mX[6UL] = -0.0;
  out->mF.mX[7UL] = -0.0;
  out->mF.mX[8UL] = -(t0 * 0.15811388300841897);
  out->mF.mX[9UL] = -(zc_int3 * 0.15811388300841897);
  out->mF.mX[10UL] = 0.0;
  out->mF.mX[11UL] = 0.0;
  out->mF.mX[16UL] = 0.0;
  out->mF.mX[17UL] = 0.0;
  out->mF.mX[19UL] = -0.0;
  out->mF.mX[20UL] = -0.0;
  out->mF.mX[21UL] = -1.5;
  out->mF.mX[22UL] = -1.5;
  out->mF.mX[23UL] = -0.0;
  (void)sys;
  (void)out;
  return 0;
}
