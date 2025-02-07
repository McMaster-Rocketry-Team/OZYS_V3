/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'ozysdriverandreceiver/Solver Configuration'.
 */

#include "ne_ds.h"
#include "ozysdriverandreceiver_d22bbe4d_49_ds_sys_struct.h"
#include "ozysdriverandreceiver_d22bbe4d_49_ds_mode.h"
#include "ozysdriverandreceiver_d22bbe4d_49_ds.h"
#include "ozysdriverandreceiver_d22bbe4d_49_ds_externals.h"
#include "ozysdriverandreceiver_d22bbe4d_49_ds_external_struct.h"
#include "ssc_ml_fun.h"

int32_T ozysdriverandreceiver_d22bbe4d_49_ds_mode(const NeDynamicSystem *sys,
  const NeDynamicSystemInput *t5, NeDsMethodOutput *out)
{
  real_T intrm_sf_mf_2;
  real_T intrm_sf_mf_3;
  real_T intrm_sf_mf_4;
  real_T intrm_sf_mf_5;
  boolean_T t0;
  boolean_T t1;
  boolean_T t2;
  boolean_T t3;
  intrm_sf_mf_2 = ((t5->mX.mX[9UL] - t5->mX.mX[12UL]) * -44562.5 - t5->mX.mX[0UL])
    * 1.5079644737231007E+8;
  intrm_sf_mf_3 = ((t5->mX.mX[12UL] - t5->mX.mX[9UL]) * -44562.5 - t5->mX.mX[1UL])
    * 1.5079644737231007E+8;
  if (intrm_sf_mf_2 > 2.5E+9) {
    intrm_sf_mf_4 = 2.5E+9;
  } else {
    intrm_sf_mf_4 = intrm_sf_mf_2 < -2.5E+9 ? -2.5E+9 : intrm_sf_mf_2;
  }

  if (intrm_sf_mf_3 > 2.5E+9) {
    intrm_sf_mf_5 = 2.5E+9;
  } else {
    intrm_sf_mf_5 = intrm_sf_mf_3 < -2.5E+9 ? -2.5E+9 : intrm_sf_mf_3;
  }

  if (1.5 + t5->mX.mX[0UL] > 5.0) {
    t0 = (intrm_sf_mf_4 > 0.0);
  } else {
    t0 = false;
  }

  if (1.5 + t5->mX.mX[0UL] < -5.0) {
    t1 = (intrm_sf_mf_4 < 0.0);
  } else {
    t1 = false;
  }

  if (1.5 + t5->mX.mX[1UL] > 5.0) {
    t2 = (intrm_sf_mf_5 > 0.0);
  } else {
    t2 = false;
  }

  if (1.5 + t5->mX.mX[1UL] < -5.0) {
    t3 = (intrm_sf_mf_5 < 0.0);
  } else {
    t3 = false;
  }

  out->mMODE.mX[0UL] = (int32_T)(t5->mT.mX[0UL] < 0.0);
  out->mMODE.mX[1UL] = (int32_T)t0;
  out->mMODE.mX[2UL] = (int32_T)(t5->mU.mX[3UL] > 0.0);
  out->mMODE.mX[3UL] = (int32_T)(t5->mU.mX[1UL] > 0.0);
  out->mMODE.mX[4UL] = (int32_T)(t5->mU.mX[2UL] > 0.0);
  out->mMODE.mX[5UL] = (int32_T)t1;
  out->mMODE.mX[6UL] = (int32_T)(intrm_sf_mf_2 > 2.5E+9);
  out->mMODE.mX[7UL] = (int32_T)(intrm_sf_mf_2 < -2.5E+9);
  out->mMODE.mX[8UL] = (int32_T)t2;
  out->mMODE.mX[9UL] = (int32_T)t3;
  out->mMODE.mX[10UL] = (int32_T)(intrm_sf_mf_3 > 2.5E+9);
  out->mMODE.mX[11UL] = (int32_T)(intrm_sf_mf_3 < -2.5E+9);
  out->mMODE.mX[12UL] = (int32_T)(t5->mU.mX[0UL] > 0.0);
  (void)sys;
  (void)out;
  return 0;
}
