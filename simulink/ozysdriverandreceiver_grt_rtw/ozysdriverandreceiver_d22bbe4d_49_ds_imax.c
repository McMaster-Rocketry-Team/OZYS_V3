/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'ozysdriverandreceiver/Solver Configuration'.
 */

#include "ne_ds.h"
#include "ozysdriverandreceiver_d22bbe4d_49_ds_sys_struct.h"
#include "ozysdriverandreceiver_d22bbe4d_49_ds_imax.h"
#include "ozysdriverandreceiver_d22bbe4d_49_ds.h"
#include "ozysdriverandreceiver_d22bbe4d_49_ds_externals.h"
#include "ozysdriverandreceiver_d22bbe4d_49_ds_external_struct.h"
#include "ssc_ml_fun.h"

int32_T ozysdriverandreceiver_d22bbe4d_49_ds_imax(const NeDynamicSystem *sys,
  const NeDynamicSystemInput *t1, NeDsMethodOutput *out)
{
  (void)t1;
  out->mIMAX.mX[0] = pmf_get_inf();
  out->mIMAX.mX[1] = pmf_get_inf();
  out->mIMAX.mX[2] = pmf_get_inf();
  out->mIMAX.mX[3] = pmf_get_inf();
  out->mIMAX.mX[4] = pmf_get_inf();
  out->mIMAX.mX[5] = pmf_get_inf();
  out->mIMAX.mX[6] = pmf_get_inf();
  out->mIMAX.mX[7] = pmf_get_inf();
  out->mIMAX.mX[8] = pmf_get_inf();
  out->mIMAX.mX[9] = pmf_get_inf();
  out->mIMAX.mX[10] = pmf_get_inf();
  out->mIMAX.mX[11] = pmf_get_inf();
  out->mIMAX.mX[12] = pmf_get_inf();
  out->mIMAX.mX[13] = pmf_get_inf();
  out->mIMAX.mX[14] = pmf_get_inf();
  out->mIMAX.mX[15] = pmf_get_inf();
  out->mIMAX.mX[16] = pmf_get_inf();
  out->mIMAX.mX[17] = pmf_get_inf();
  out->mIMAX.mX[18] = pmf_get_inf();
  out->mIMAX.mX[19] = pmf_get_inf();
  out->mIMAX.mX[20] = pmf_get_inf();
  out->mIMAX.mX[21] = pmf_get_inf();
  out->mIMAX.mX[22] = pmf_get_inf();
  out->mIMAX.mX[23] = pmf_get_inf();
  (void)sys;
  (void)out;
  return 0;
}
