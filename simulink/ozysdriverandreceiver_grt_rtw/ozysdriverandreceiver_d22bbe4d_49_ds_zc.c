/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'ozysdriverandreceiver/Solver Configuration'.
 */

#include "ne_ds.h"
#include "ozysdriverandreceiver_d22bbe4d_49_ds_sys_struct.h"
#include "ozysdriverandreceiver_d22bbe4d_49_ds_zc.h"
#include "ozysdriverandreceiver_d22bbe4d_49_ds.h"
#include "ozysdriverandreceiver_d22bbe4d_49_ds_externals.h"
#include "ozysdriverandreceiver_d22bbe4d_49_ds_external_struct.h"
#include "ssc_ml_fun.h"

int32_T ozysdriverandreceiver_d22bbe4d_49_ds_zc(const NeDynamicSystem *sys,
  const NeDynamicSystemInput *t9, NeDsMethodOutput *out)
{
  real_T intrm_sf_mf_3;
  real_T intrm_sf_mf_4;
  real_T intrm_sf_mf_5;
  real_T t2;
  boolean_T t4;
  boolean_T t5;
  boolean_T t6;
  boolean_T t7;
  t2 = ((t9->mX.mX[9UL] - t9->mX.mX[12UL]) * -44562.5 - t9->mX.mX[0UL]) *
    1.5079644737231007E+8;
  intrm_sf_mf_3 = ((t9->mX.mX[12UL] - t9->mX.mX[9UL]) * -44562.5 - t9->mX.mX[1UL])
    * 1.5079644737231007E+8;
  if (t2 > 2.5E+9) {
    intrm_sf_mf_4 = 2.5E+9;
  } else {
    intrm_sf_mf_4 = t2 < -2.5E+9 ? -2.5E+9 : t2;
  }

  if (intrm_sf_mf_3 > 2.5E+9) {
    intrm_sf_mf_5 = 2.5E+9;
  } else {
    intrm_sf_mf_5 = intrm_sf_mf_3 < -2.5E+9 ? -2.5E+9 : intrm_sf_mf_3;
  }

  if ((t9->mM.mX[1UL] == 0) && (t9->mM.mX[5UL] == 0)) {
    out->mZC.mX[5UL] = t2 - 2.5E+9;
  } else {
    out->mZC.mX[5UL] = 0.0;
  }

  if ((t9->mM.mX[1UL] == 0) && (t9->mM.mX[5UL] == 0) && (t9->mM.mX[6UL] == 0)) {
    out->mZC.mX[6UL] = -2.5E+9 - t2;
  } else {
    out->mZC.mX[6UL] = 0.0;
  }

  if ((t9->mM.mX[8UL] == 0) && (t9->mM.mX[9UL] == 0)) {
    out->mZC.mX[7UL] = intrm_sf_mf_3 - 2.5E+9;
  } else {
    out->mZC.mX[7UL] = 0.0;
  }

  if ((t9->mM.mX[8UL] == 0) && (t9->mM.mX[9UL] == 0) && (t9->mM.mX[10UL] == 0))
  {
    out->mZC.mX[8UL] = -2.5E+9 - intrm_sf_mf_3;
  } else {
    out->mZC.mX[8UL] = 0.0;
  }

  if (1.5 + t9->mX.mX[0UL] > 5.0) {
    t4 = (intrm_sf_mf_4 > 0.0);
  } else {
    t4 = false;
  }

  if (t9->mM.mX[1UL] == 0) {
    if (1.5 + t9->mX.mX[0UL] < -5.0) {
      t5 = (intrm_sf_mf_4 < 0.0);
    } else {
      t5 = false;
    }
  } else {
    t5 = false;
  }

  if (1.5 + t9->mX.mX[1UL] > 5.0) {
    t6 = (intrm_sf_mf_5 > 0.0);
  } else {
    t6 = false;
  }

  if (t9->mM.mX[8UL] == 0) {
    if (1.5 + t9->mX.mX[1UL] < -5.0) {
      t7 = (intrm_sf_mf_5 < 0.0);
    } else {
      t7 = false;
    }
  } else {
    t7 = false;
  }

  out->mZC.mX[0UL] = -t9->mT.mX[0UL];
  out->mZC.mX[1UL] = t9->mU.mX[0UL];
  out->mZC.mX[2UL] = t9->mU.mX[3UL];
  out->mZC.mX[3UL] = t9->mU.mX[1UL];
  out->mZC.mX[4UL] = t9->mU.mX[2UL];
  out->mZC.mX[9UL] = (real_T)t4;
  out->mZC.mX[10UL] = (real_T)t5;
  out->mZC.mX[11UL] = (real_T)t6;
  out->mZC.mX[12UL] = (real_T)t7;
  (void)sys;
  (void)out;
  return 0;
}
