/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'ozysdriverandreceiver/Solver Configuration'.
 */

#include "ne_ds.h"
#include "ozysdriverandreceiver_d22bbe4d_49_ds_sys_struct.h"
#include "ozysdriverandreceiver_d22bbe4d_49_ds_tdxy_p.h"
#include "ozysdriverandreceiver_d22bbe4d_49_ds.h"
#include "ozysdriverandreceiver_d22bbe4d_49_ds_externals.h"
#include "ozysdriverandreceiver_d22bbe4d_49_ds_external_struct.h"
#include "ssc_ml_fun.h"

int32_T ozysdriverandreceiver_d22bbe4d_49_ds_tdxy_p(const NeDynamicSystem *sys,
  const NeDynamicSystemInput *t1, NeDsMethodOutput *out)
{
  static int32_T _cg_const_1[25] = { 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 4, 4, 4, 7,
    7, 8, 9, 9, 10, 11, 11, 11, 11, 11 };

  static int32_T _cg_const_2[11] = { 6, 1, 2, 4, 2, 3, 4, 5, 6, 0, 0 };

  (void)t1;
  out->mTDXY_P.mNumCol = 24UL;
  out->mTDXY_P.mNumRow = 7UL;
  out->mTDXY_P.mJc[0] = _cg_const_1[0];
  out->mTDXY_P.mJc[1] = _cg_const_1[1];
  out->mTDXY_P.mJc[2] = _cg_const_1[2];
  out->mTDXY_P.mJc[3] = _cg_const_1[3];
  out->mTDXY_P.mJc[4] = _cg_const_1[4];
  out->mTDXY_P.mJc[5] = _cg_const_1[5];
  out->mTDXY_P.mJc[6] = _cg_const_1[6];
  out->mTDXY_P.mJc[7] = _cg_const_1[7];
  out->mTDXY_P.mJc[8] = _cg_const_1[8];
  out->mTDXY_P.mJc[9] = _cg_const_1[9];
  out->mTDXY_P.mJc[10] = _cg_const_1[10];
  out->mTDXY_P.mJc[11] = _cg_const_1[11];
  out->mTDXY_P.mJc[12] = _cg_const_1[12];
  out->mTDXY_P.mJc[13] = _cg_const_1[13];
  out->mTDXY_P.mJc[14] = _cg_const_1[14];
  out->mTDXY_P.mJc[15] = _cg_const_1[15];
  out->mTDXY_P.mJc[16] = _cg_const_1[16];
  out->mTDXY_P.mJc[17] = _cg_const_1[17];
  out->mTDXY_P.mJc[18] = _cg_const_1[18];
  out->mTDXY_P.mJc[19] = _cg_const_1[19];
  out->mTDXY_P.mJc[20] = _cg_const_1[20];
  out->mTDXY_P.mJc[21] = _cg_const_1[21];
  out->mTDXY_P.mJc[22] = _cg_const_1[22];
  out->mTDXY_P.mJc[23] = _cg_const_1[23];
  out->mTDXY_P.mJc[24] = _cg_const_1[24];
  out->mTDXY_P.mIr[0] = _cg_const_2[0];
  out->mTDXY_P.mIr[1] = _cg_const_2[1];
  out->mTDXY_P.mIr[2] = _cg_const_2[2];
  out->mTDXY_P.mIr[3] = _cg_const_2[3];
  out->mTDXY_P.mIr[4] = _cg_const_2[4];
  out->mTDXY_P.mIr[5] = _cg_const_2[5];
  out->mTDXY_P.mIr[6] = _cg_const_2[6];
  out->mTDXY_P.mIr[7] = _cg_const_2[7];
  out->mTDXY_P.mIr[8] = _cg_const_2[8];
  out->mTDXY_P.mIr[9] = _cg_const_2[9];
  out->mTDXY_P.mIr[10] = _cg_const_2[10];
  (void)sys;
  (void)out;
  return 0;
}
