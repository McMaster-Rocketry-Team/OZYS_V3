/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'ozysdriverandreceiver/Solver Configuration'.
 */

#include "ne_ds.h"
#include "ozysdriverandreceiver_d22bbe4d_49_ds_sys_struct.h"
#include "ozysdriverandreceiver_d22bbe4d_49_ds_dxf.h"
#include "ozysdriverandreceiver_d22bbe4d_49_ds.h"
#include "ozysdriverandreceiver_d22bbe4d_49_ds_externals.h"
#include "ozysdriverandreceiver_d22bbe4d_49_ds_external_struct.h"
#include "ssc_ml_fun.h"

int32_T ozysdriverandreceiver_d22bbe4d_49_ds_dxf(const NeDynamicSystem *sys,
  const NeDynamicSystemInput *t33, NeDsMethodOutput *out)
{
  real_T t21[4];
  real_T intermediate_der111;
  real_T intermediate_der112;
  real_T intermediate_der125;
  real_T t1;
  real_T t3;
  real_T t6;
  real_T t7;
  size_t t27;
  if (t33->mM.mX[6UL] != 0) {
    t1 = 0.0;
  } else {
    t1 = t33->mM.mX[7UL] != 0 ? 0.0 : -1.5079644737231007E+8;
  }

  if (t33->mM.mX[6UL] != 0) {
    t6 = 0.0;
  } else {
    t6 = t33->mM.mX[7UL] != 0 ? 0.0 : 6.7198666860285674E+12;
  }

  if (t33->mM.mX[6UL] != 0) {
    t3 = 0.0;
  } else {
    t3 = t33->mM.mX[7UL] != 0 ? 0.0 : -6.7198666860285674E+12;
  }

  if (t33->mM.mX[10UL] != 0) {
    intermediate_der125 = 0.0;
  } else {
    intermediate_der125 = t33->mM.mX[11UL] != 0 ? 0.0 : -1.5079644737231007E+8;
  }

  if (t33->mM.mX[10UL] != 0) {
    t7 = 0.0;
  } else {
    t7 = t33->mM.mX[11UL] != 0 ? 0.0 : -6.7198666860285674E+12;
  }

  if (t33->mM.mX[10UL] != 0) {
    intermediate_der112 = 0.0;
  } else {
    intermediate_der112 = t33->mM.mX[11UL] != 0 ? 0.0 : 6.7198666860285674E+12;
  }

  if (t33->mM.mX[1UL] != 0) {
    intermediate_der111 = 0.0;
  } else {
    intermediate_der111 = t33->mM.mX[5UL] != 0 ? 0.0 : -t1;
  }

  if (t33->mM.mX[8UL] != 0) {
    t1 = 0.0;
  } else {
    t1 = t33->mM.mX[9UL] != 0 ? 0.0 : -intermediate_der125;
  }

  if (t33->mM.mX[1UL] != 0) {
    intermediate_der125 = 0.0;
  } else {
    intermediate_der125 = t33->mM.mX[5UL] != 0 ? 0.0 : -t3;
  }

  if (t33->mM.mX[8UL] != 0) {
    t3 = 0.0;
  } else {
    t3 = t33->mM.mX[9UL] != 0 ? 0.0 : -intermediate_der112;
  }

  if (t33->mM.mX[4UL] != 0) {
    out->mDXF.mX[4UL] = -(t33->mU.mX[2UL] * 0.00014705882352941175);
  } else {
    out->mDXF.mX[4UL] = 0.0;
  }

  if (t33->mM.mX[1UL] != 0) {
    intermediate_der112 = 0.0;
  } else {
    intermediate_der112 = t33->mM.mX[5UL] != 0 ? 0.0 : -t6;
  }

  if (t33->mM.mX[8UL] != 0) {
    t6 = 0.0;
  } else {
    t6 = t33->mM.mX[9UL] != 0 ? 0.0 : -t7;
  }

  if (t33->mM.mX[2UL] != 0) {
    out->mDXF.mX[7UL] = -(t33->mU.mX[3UL] * -0.00014705882352941175);
  } else {
    out->mDXF.mX[7UL] = 0.0;
  }

  if (t33->mM.mX[12UL] != 0) {
    out->mDXF.mX[8UL] = -1.0 - t33->mU.mX[0UL] * 0.016666666666666666;
  } else {
    out->mDXF.mX[8UL] = -1.0;
  }

  if (t33->mM.mX[2UL] != 0) {
    out->mDXF.mX[9UL] = -(t33->mU.mX[3UL] * 0.016666666666666666);
  } else {
    out->mDXF.mX[9UL] = 0.0;
  }

  if (t33->mM.mX[2UL] != 0) {
    out->mDXF.mX[12UL] = -1.0 - t33->mU.mX[3UL] * 0.00014705882352941175;
  } else {
    out->mDXF.mX[12UL] = -1.0;
  }

  if (t33->mM.mX[4UL] != 0) {
    out->mDXF.mX[14UL] = 1.0 - t33->mU.mX[2UL] * -0.00014705882352941175;
  } else {
    out->mDXF.mX[14UL] = 1.0;
  }

  if (t33->mM.mX[12UL] != 0) {
    t21[0UL] = -t33->mU.mX[0UL];
  } else {
    t21[0UL] = 0.0;
  }

  if (t33->mM.mX[2UL] != 0) {
    t21[1UL] = -t33->mU.mX[3UL];
  } else {
    t21[1UL] = 0.0;
  }

  if (t33->mM.mX[4UL] != 0) {
    t21[3UL] = -t33->mU.mX[2UL];
  } else {
    t21[3UL] = 0.0;
  }

  out->mDXF.mX[2UL] = -(intermediate_der125 / 6.7198666860285674E+12);
  out->mDXF.mX[3UL] = -(t3 / 6.7198666860285674E+12);
  out->mDXF.mX[5UL] = -(intermediate_der112 / 6.7198666860285674E+12);
  out->mDXF.mX[6UL] = -(t6 / 6.7198666860285674E+12);
  t21[2UL] = t33->mM.mX[3UL] != 0 ? -t33->mU.mX[1UL] : 0.0;
  out->mDXF.mX[0UL] = -(intermediate_der111 / 6.7198666860285674E+12);
  out->mDXF.mX[1UL] = -(t1 / 6.7198666860285674E+12);
  out->mDXF.mX[10UL] = 1.0;
  out->mDXF.mX[11UL] = 1.0;
  out->mDXF.mX[13UL] = -1.0;
  for (t27 = 0UL; t27 < 4UL; t27++) {
    out->mDXF.mX[t27 + 15UL] = t21[t27];
  }

  (void)sys;
  (void)out;
  return 0;
}
