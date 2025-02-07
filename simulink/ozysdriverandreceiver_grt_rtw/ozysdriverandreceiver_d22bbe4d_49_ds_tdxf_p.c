/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'ozysdriverandreceiver/Solver Configuration'.
 */

#include "ne_ds.h"
#include "ozysdriverandreceiver_d22bbe4d_49_ds_sys_struct.h"
#include "ozysdriverandreceiver_d22bbe4d_49_ds_tdxf_p.h"
#include "ozysdriverandreceiver_d22bbe4d_49_ds.h"
#include "ozysdriverandreceiver_d22bbe4d_49_ds_externals.h"
#include "ozysdriverandreceiver_d22bbe4d_49_ds_external_struct.h"
#include "ssc_ml_fun.h"

int32_T ozysdriverandreceiver_d22bbe4d_49_ds_tdxf_p(const NeDynamicSystem *sys,
  const NeDynamicSystemInput *t1, NeDsMethodOutput *out)
{
  static int32_T _cg_const_2[102] = { 3, 21, 4, 22, 6, 11, 20, 23, 0, 1, 2, 16,
    17, 19, 1, 16, 2, 17, 5, 18, 6, 7, 20, 22, 23, 8, 19, 21, 1, 2, 3, 4, 15, 16,
    17, 19, 21, 8, 10, 20, 21, 22, 1, 2, 9, 16, 17, 22, 1, 2, 3, 4, 13, 16, 17,
    22, 7, 9, 10, 20, 22, 10, 21, 22, 6, 11, 23, 6, 7, 11, 20, 23, 12, 13, 14, 1,
    2, 12, 13, 16, 17, 14, 15, 19, 12, 13, 14, 15, 5, 18, 0, 1, 2, 16, 17, 19, 6,
    7, 20, 21, 22, 23 };

  static int32_T _cg_const_1[25] = { 0, 2, 4, 8, 14, 16, 18, 20, 25, 28, 37, 42,
    48, 56, 61, 64, 67, 72, 75, 81, 84, 88, 90, 96, 102 };

  int32_T i1;
  (void)t1;
  out->mTDXF_P.mNumCol = 24UL;
  out->mTDXF_P.mNumRow = 24UL;
  out->mTDXF_P.mJc[0] = _cg_const_1[0];
  out->mTDXF_P.mJc[1] = _cg_const_1[1];
  out->mTDXF_P.mJc[2] = _cg_const_1[2];
  out->mTDXF_P.mJc[3] = _cg_const_1[3];
  out->mTDXF_P.mJc[4] = _cg_const_1[4];
  out->mTDXF_P.mJc[5] = _cg_const_1[5];
  out->mTDXF_P.mJc[6] = _cg_const_1[6];
  out->mTDXF_P.mJc[7] = _cg_const_1[7];
  out->mTDXF_P.mJc[8] = _cg_const_1[8];
  out->mTDXF_P.mJc[9] = _cg_const_1[9];
  out->mTDXF_P.mJc[10] = _cg_const_1[10];
  out->mTDXF_P.mJc[11] = _cg_const_1[11];
  out->mTDXF_P.mJc[12] = _cg_const_1[12];
  out->mTDXF_P.mJc[13] = _cg_const_1[13];
  out->mTDXF_P.mJc[14] = _cg_const_1[14];
  out->mTDXF_P.mJc[15] = _cg_const_1[15];
  out->mTDXF_P.mJc[16] = _cg_const_1[16];
  out->mTDXF_P.mJc[17] = _cg_const_1[17];
  out->mTDXF_P.mJc[18] = _cg_const_1[18];
  out->mTDXF_P.mJc[19] = _cg_const_1[19];
  out->mTDXF_P.mJc[20] = _cg_const_1[20];
  out->mTDXF_P.mJc[21] = _cg_const_1[21];
  out->mTDXF_P.mJc[22] = _cg_const_1[22];
  out->mTDXF_P.mJc[23] = _cg_const_1[23];
  out->mTDXF_P.mJc[24] = _cg_const_1[24];
  for (i1 = 0; i1 < 102; i1++) {
    out->mTDXF_P.mIr[i1] = _cg_const_2[i1];
  }

  (void)sys;
  (void)out;
  return 0;
}
