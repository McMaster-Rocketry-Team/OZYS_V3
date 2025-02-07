/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'ozysdriverandreceiver/Solver Configuration'.
 */

#include "ne_ds.h"
#include "ozysdriverandreceiver_d22bbe4d_49_ds_sys_struct.h"
#include "ozysdriverandreceiver_d22bbe4d_49_ds_vmf.h"
#include "ozysdriverandreceiver_d22bbe4d_49_ds.h"
#include "ozysdriverandreceiver_d22bbe4d_49_ds_externals.h"
#include "ozysdriverandreceiver_d22bbe4d_49_ds_external_struct.h"
#include "ssc_ml_fun.h"

int32_T ozysdriverandreceiver_d22bbe4d_49_ds_vmf(const NeDynamicSystem *sys,
  const NeDynamicSystemInput *t1, NeDsMethodOutput *out)
{
  static boolean_T _cg_const_1[24] = { false, false, false, true, true, false,
    false, false, true, true, false, false, true, true, true, true, false, false,
    false, false, false, false, false, false };

  (void)t1;
  out->mVMF.mX[0] = _cg_const_1[0];
  out->mVMF.mX[1] = _cg_const_1[1];
  out->mVMF.mX[2] = _cg_const_1[2];
  out->mVMF.mX[3] = _cg_const_1[3];
  out->mVMF.mX[4] = _cg_const_1[4];
  out->mVMF.mX[5] = _cg_const_1[5];
  out->mVMF.mX[6] = _cg_const_1[6];
  out->mVMF.mX[7] = _cg_const_1[7];
  out->mVMF.mX[8] = _cg_const_1[8];
  out->mVMF.mX[9] = _cg_const_1[9];
  out->mVMF.mX[10] = _cg_const_1[10];
  out->mVMF.mX[11] = _cg_const_1[11];
  out->mVMF.mX[12] = _cg_const_1[12];
  out->mVMF.mX[13] = _cg_const_1[13];
  out->mVMF.mX[14] = _cg_const_1[14];
  out->mVMF.mX[15] = _cg_const_1[15];
  out->mVMF.mX[16] = _cg_const_1[16];
  out->mVMF.mX[17] = _cg_const_1[17];
  out->mVMF.mX[18] = _cg_const_1[18];
  out->mVMF.mX[19] = _cg_const_1[19];
  out->mVMF.mX[20] = _cg_const_1[20];
  out->mVMF.mX[21] = _cg_const_1[21];
  out->mVMF.mX[22] = _cg_const_1[22];
  out->mVMF.mX[23] = _cg_const_1[23];
  (void)sys;
  (void)out;
  return 0;
}
