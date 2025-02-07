/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'ozysdriverandreceiver/Solver Configuration'.
 */

#include "ne_ds.h"
#include "ozysdriverandreceiver_d22bbe4d_49_ds_sys_struct.h"
#include "ozysdriverandreceiver_d22bbe4d_49_ds_log.h"
#include "ozysdriverandreceiver_d22bbe4d_49_ds.h"
#include "ozysdriverandreceiver_d22bbe4d_49_ds_externals.h"
#include "ozysdriverandreceiver_d22bbe4d_49_ds_external_struct.h"
#include "ssc_ml_fun.h"

int32_T ozysdriverandreceiver_d22bbe4d_49_ds_log(const NeDynamicSystem *sys,
  const NeDynamicSystemInput *t21, NeDsMethodOutput *out)
{
  real_T t2[1];
  real_T t6[1];
  real_T t9[1];
  real_T Resistor2_i;
  real_T Resistor2_power_dissipated;
  real_T Resistor3_n_v;
  real_T Resistor_i;
  real_T Resistor_power_dissipated;
  real_T SG_Variable_Resistor2_v;
  real_T SG_Variable_Resistor3_i;
  real_T SG_Variable_Resistor_v;
  real_T Subsystem1_Psuedo_AD8132_C1a_n_v;
  real_T Subsystem1_Psuedo_AD8132_C1b_i;
  real_T Subsystem1_Psuedo_AD8132_C2_i;
  real_T Subsystem1_Psuedo_AD8132_R1a_i;
  real_T Subsystem1_Psuedo_AD8132_R1b_i;
  real_T Subsystem1_Psuedo_AD8132_R2_i;
  real_T Subsystem1_Psuedo_AD8132_diff_op_amp_eqn_i_out_p;
  real_T Subsystem1_RF1_Resistor_i;
  real_T Subsystem1_RG1_i;
  real_T Subsystem1_RG_Resistor_i;
  real_T Subsystem2_Capacitor2_n_v;
  real_T Subsystem2_Resistor1_Resistor_i;
  real_T Subsystem2_Resistor2_Resistor_i;
  real_T Subsystem2_Resistor3_Resistor_i;
  real_T Subsystem2_Resistor4_Resistor_i;
  real_T Voltage_Sensor1_V;
  real_T Voltage_Sensor3_V;
  real_T Voltage_Sensor_V;
  real_T piece9;
  real_T t0;
  real_T t13;
  real_T zc_int3;
  int32_T t7[2];
  out->mLOG.mX[5UL] = -t21->mX.mX[8UL] + t21->mX.mX[10UL];
  out->mLOG.mX[11UL] = -t21->mX.mX[11UL] + t21->mX.mX[13UL];
  Resistor_i = t21->mX.mX[10UL] * 1.0E-6 + t21->mX.mX[14UL] * -1.0E-6;
  Resistor_power_dissipated = Resistor_i * Resistor_i * 1.0E+6;
  Resistor2_i = t21->mX.mX[15UL] * -1.0E-6 + t21->mX.mX[16UL] * 1.0E-6;
  Resistor2_power_dissipated = Resistor2_i * Resistor2_i * 1.0E+6;
  Resistor3_n_v = t21->mX.mX[2UL] + t21->mX.mX[16UL];
  out->mLOG.mX[33UL] = -t21->mX.mX[17UL];
  t13 = t21->mX.mX[17UL] * 0.016666666666666666 - 0.054999999999999993;
  out->mLOG.mX[38UL] = t13 * t13 * 60.0;
  SG_Variable_Resistor_v = -t21->mX.mX[17UL] + t21->mX.mX[18UL];
  out->mLOG.mX[50UL] = ((t21->mX.mX[17UL] * 0.016666666666666666 + t21->mX.mX
    [20UL]) - 0.052999999999999992) * SG_Variable_Resistor_v;
  out->mLOG.mX[55UL] = ((((t21->mX.mX[17UL] * 0.016666666666666666 + t21->mX.mX
    [18UL] * 0.00014705882352941175) + t21->mX.mX[12UL] *
    -0.00014705882352941175) + t21->mX.mX[20UL]) - 0.052999999999999992) *
    -t21->mX.mX[18UL];
  SG_Variable_Resistor2_v = -t21->mX.mX[19UL] + t21->mX.mX[17UL];
  out->mLOG.mX[61UL] = t21->mX.mX[20UL] * SG_Variable_Resistor2_v;
  SG_Variable_Resistor3_i = (t21->mX.mX[19UL] * -0.00014705882352941175 +
    t21->mX.mX[9UL] * 0.00014705882352941175) + t21->mX.mX[20UL];
  out->mLOG.mX[66UL] = SG_Variable_Resistor3_i * t21->mX.mX[19UL];
  Subsystem1_Psuedo_AD8132_C1a_n_v = (-t21->mX.mX[3UL] + t21->mX.mX[22UL] *
    -1.0E-6) + t21->mX.mX[9UL];
  out->mLOG.mX[77UL] = t21->mX.mX[22UL] * t21->mX.mX[22UL] * 1.0E-9;
  out->mLOG.mX[75UL] = t21->mX.mX[22UL] * 1.0E-6 + t21->mX.mX[3UL];
  Subsystem1_Psuedo_AD8132_C1b_i = ((((t21->mX.mX[3UL] * 1.5384615384615385E-6 +
    t21->mX.mX[11UL] * -3.0303030303030305E-6) + t21->mX.mX[18UL] *
    -0.00014705882352941175) + t21->mX.mX[22UL] * 1.5384615384615385E-12) +
    t21->mX.mX[9UL] * -1.5384615384615385E-6) + t21->mX.mX[12UL] *
    0.00015162758809817632;
  out->mLOG.mX[83UL] = Subsystem1_Psuedo_AD8132_C1b_i *
    Subsystem1_Psuedo_AD8132_C1b_i * 1.0E-9;
  out->mLOG.mX[81UL] = ((-t21->mX.mX[3UL] + t21->mX.mX[22UL] * -1.0E-6) -
                        t21->mX.mX[12UL]) + t21->mX.mX[9UL];
  Subsystem1_Psuedo_AD8132_C2_i = ((((t21->mX.mX[3UL] * 4.395604395604396E-6 +
    t21->mX.mX[11UL] * 3.0303030303030305E-6) + t21->mX.mX[18UL] *
    0.00014705882352941175) + t21->mX.mX[22UL] * 1.0000000000043956) +
    t21->mX.mX[9UL] * -2.8571428571428573E-6) + t21->mX.mX[12UL] *
    -0.00015008912655971478;
  out->mLOG.mX[88UL] = Subsystem1_Psuedo_AD8132_C2_i *
    Subsystem1_Psuedo_AD8132_C2_i * 1.0E-9;
  Subsystem1_Psuedo_AD8132_R1a_i = t21->mX.mX[3UL] * 1.5384615384615385E-6 +
    t21->mX.mX[22UL] * 1.5384615384615385E-12;
  out->mLOG.mX[93UL] = Subsystem1_Psuedo_AD8132_R1a_i *
    Subsystem1_Psuedo_AD8132_R1a_i * 650000.0;
  Subsystem1_Psuedo_AD8132_R1b_i = ((t21->mX.mX[3UL] * -1.5384615384615385E-6 +
    t21->mX.mX[22UL] * -1.5384615384615385E-12) + t21->mX.mX[9UL] *
    1.5384615384615385E-6) + t21->mX.mX[12UL] * -1.5384615384615385E-6;
  out->mLOG.mX[98UL] = Subsystem1_Psuedo_AD8132_R1b_i *
    Subsystem1_Psuedo_AD8132_R1b_i * 650000.0;
  Subsystem1_Psuedo_AD8132_R2_i = (t21->mX.mX[3UL] * -2.8571428571428573E-6 +
    t21->mX.mX[22UL] * -2.857142857142857E-12) + t21->mX.mX[9UL] *
    2.8571428571428573E-6;
  out->mLOG.mX[102UL] = Subsystem1_Psuedo_AD8132_R2_i *
    Subsystem1_Psuedo_AD8132_R2_i * 350000.0;
  out->mLOG.mX[103UL] = -(((-t21->mX.mX[1UL] + t21->mX.mX[11UL]) - 1.5) +
    ((-t21->mX.mX[0UL] + t21->mX.mX[8UL]) - 1.5));
  Subsystem1_Psuedo_AD8132_diff_op_amp_eqn_i_out_p = t21->mX.mX[11UL] *
    -3.0303030303030305E-6 + t21->mX.mX[12UL] * 3.0303030303030305E-6;
  out->mLOG.mX[122UL] = Subsystem1_Psuedo_AD8132_diff_op_amp_eqn_i_out_p *
    Subsystem1_Psuedo_AD8132_diff_op_amp_eqn_i_out_p * 330000.0;
  Subsystem1_RF1_Resistor_i = t21->mX.mX[8UL] * -3.0303030303030305E-6 +
    t21->mX.mX[9UL] * 3.0303030303030305E-6;
  out->mLOG.mX[129UL] = Subsystem1_RF1_Resistor_i * Subsystem1_RF1_Resistor_i *
    330000.0;
  Subsystem1_RG_Resistor_i = t21->mX.mX[18UL] * 0.00014705882352941175 +
    t21->mX.mX[12UL] * -0.00014705882352941175;
  out->mLOG.mX[136UL] = Subsystem1_RG_Resistor_i * Subsystem1_RG_Resistor_i *
    6800.0;
  Subsystem1_RG1_i = t21->mX.mX[19UL] * 0.00014705882352941175 + t21->mX.mX[9UL]
    * -0.00014705882352941175;
  out->mLOG.mX[141UL] = Subsystem1_RG1_i * Subsystem1_RG1_i * 6800.0;
  out->mLOG.mX[145UL] = ((t21->mX.mX[7UL] * 0.013888888888888888 + t21->mX.mX
    [15UL] * -1.0E-6) + t21->mX.mX[16UL] * 0.013889888888888887) + t21->mX.mX
    [23UL] * -0.013888888888888888;
  out->mLOG.mX[148UL] = t21->mX.mX[2UL];
  out->mLOG.mX[151UL] = ((t21->mX.mX[7UL] * -0.027777777777777776 + t21->mX.mX
    [13UL] * -0.013888888888888888) + t21->mX.mX[16UL] * -0.013888888888888888)
    + t21->mX.mX[23UL] * 0.027777777777777776;
  Subsystem2_Capacitor2_n_v = -t21->mX.mX[7UL] + t21->mX.mX[23UL];
  out->mLOG.mX[154UL] = t21->mX.mX[7UL];
  Subsystem2_Resistor1_Resistor_i = t21->mX.mX[10UL] * 0.013888888888888888 +
    t21->mX.mX[23UL] * -0.013888888888888888;
  out->mLOG.mX[167UL] = Subsystem2_Resistor1_Resistor_i *
    Subsystem2_Resistor1_Resistor_i * 72.0;
  Subsystem2_Resistor2_Resistor_i = (t21->mX.mX[2UL] * -0.013888888888888888 +
    t21->mX.mX[16UL] * -0.013888888888888888) + t21->mX.mX[23UL] *
    0.013888888888888888;
  out->mLOG.mX[174UL] = Subsystem2_Resistor2_Resistor_i *
    Subsystem2_Resistor2_Resistor_i * 72.0;
  Subsystem2_Resistor3_Resistor_i = (t21->mX.mX[7UL] * 0.013888888888888888 +
    t21->mX.mX[13UL] * 0.013888888888888888) + t21->mX.mX[23UL] *
    -0.013888888888888888;
  out->mLOG.mX[181UL] = Subsystem2_Resistor3_Resistor_i *
    Subsystem2_Resistor3_Resistor_i * 72.0;
  Subsystem2_Resistor4_Resistor_i = (t21->mX.mX[7UL] * -0.013888888888888888 +
    t21->mX.mX[16UL] * -0.013888888888888888) + t21->mX.mX[23UL] *
    0.013888888888888888;
  out->mLOG.mX[188UL] = Subsystem2_Resistor4_Resistor_i *
    Subsystem2_Resistor4_Resistor_i * 72.0;
  Voltage_Sensor_V = Resistor3_n_v - t21->mX.mX[16UL];
  Voltage_Sensor1_V = t21->mX.mX[18UL] - t21->mX.mX[19UL];
  Voltage_Sensor3_V = t21->mX.mX[10UL] - t21->mX.mX[13UL];
  out->mLOG.mX[210UL] = t21->mX.mX[14UL];
  if (t21->mM.mX[0UL] != 0) {
    t0 = 0.0;
  } else {
    t2[0] = 0.0;
    t6[0] = 1.0;
    t7[0UL] = t21->mQ.mX[0UL];
    t7[1UL] = t21->mQ.mX[1UL];
    compute_gaussian_value(&t9[0UL], &t2[0UL], &t6[0UL], &t7[0UL]);
    t0 = t9[0UL];
  }

  out->mLOG.mX[3UL] = t0;
  if (t21->mM.mX[0UL] != 0) {
    zc_int3 = 0.0;
  } else {
    t2[0] = 0.0;
    t6[0] = 1.0;
    t7[0UL] = t21->mQ.mX[2UL];
    t7[1UL] = t21->mQ.mX[3UL];
    compute_gaussian_value(&t9[0UL], &t2[0UL], &t6[0UL], &t7[0UL]);
    zc_int3 = t9[0UL];
  }

  out->mLOG.mX[9UL] = zc_int3;
  piece9 = t21->mX.mX[17UL] * 0.016666666666666666;
  out->mLOG.mX[0UL] = -1.5 + ((-t21->mX.mX[0UL] + t21->mX.mX[8UL] *
    1.0000030303030303) + t21->mX.mX[9UL] * -3.0303030303030305E-6);
  out->mLOG.mX[1UL] = t21->mX.mX[8UL];
  out->mLOG.mX[2UL] = t21->mX.mX[10UL];
  out->mLOG.mX[4UL] = t0;
  out->mLOG.mX[6UL] = -1.5 + ((-t21->mX.mX[1UL] + t21->mX.mX[11UL] *
    1.0000030303030303) + t21->mX.mX[12UL] * -3.0303030303030305E-6);
  out->mLOG.mX[7UL] = t21->mX.mX[11UL];
  out->mLOG.mX[8UL] = t21->mX.mX[13UL];
  out->mLOG.mX[10UL] = zc_int3;
  out->mLOG.mX[12UL] = Resistor_i;
  out->mLOG.mX[13UL] = t21->mX.mX[14UL];
  out->mLOG.mX[14UL] = t21->mX.mX[10UL];
  out->mLOG.mX[15UL] = Resistor_i * 1.0E+6;
  out->mLOG.mX[16UL] = Resistor_power_dissipated;
  out->mLOG.mX[17UL] = Resistor_i;
  out->mLOG.mX[18UL] = t21->mX.mX[13UL];
  out->mLOG.mX[19UL] = t21->mX.mX[14UL];
  out->mLOG.mX[20UL] = Resistor_i * 1.0E+6;
  out->mLOG.mX[21UL] = Resistor_power_dissipated;
  out->mLOG.mX[22UL] = Resistor2_i;
  out->mLOG.mX[23UL] = t21->mX.mX[15UL];
  out->mLOG.mX[24UL] = t21->mX.mX[16UL];
  out->mLOG.mX[25UL] = Resistor2_i * 1.0E+6;
  out->mLOG.mX[26UL] = Resistor2_power_dissipated;
  out->mLOG.mX[27UL] = Resistor2_i;
  out->mLOG.mX[28UL] = Resistor3_n_v;
  out->mLOG.mX[29UL] = t21->mX.mX[15UL];
  out->mLOG.mX[30UL] = Resistor2_i * 1.0E+6;
  out->mLOG.mX[31UL] = Resistor2_power_dissipated;
  out->mLOG.mX[32UL] = t21->mX.mX[17UL];
  out->mLOG.mX[34UL] = -0.054999999999999993 + piece9;
  out->mLOG.mX[35UL] = 0.054999999999999993 - piece9;
  out->mLOG.mX[36UL] = t21->mX.mX[17UL];
  out->mLOG.mX[37UL] = t13 * -60.0;
  out->mLOG.mX[39UL] = t21->mU.mX[0UL];
  out->mLOG.mX[40UL] = t21->mU.mX[1UL];
  out->mLOG.mX[41UL] = t21->mU.mX[2UL];
  out->mLOG.mX[42UL] = t21->mU.mX[3UL];
  out->mLOG.mX[43UL] = t21->mX.mX[18UL];
  out->mLOG.mX[44UL] = t21->mX.mX[19UL];
  out->mLOG.mX[45UL] = t21->mU.mX[0UL];
  out->mLOG.mX[46UL] = -0.052999999999999992 + (t21->mX.mX[17UL] *
    0.016666666666666666 + t21->mX.mX[20UL]);
  out->mLOG.mX[47UL] = t21->mX.mX[17UL];
  out->mLOG.mX[48UL] = t21->mX.mX[18UL];
  out->mLOG.mX[49UL] = SG_Variable_Resistor_v;
  out->mLOG.mX[51UL] = t21->mU.mX[3UL];
  out->mLOG.mX[52UL] = -0.052999999999999992 + (((t21->mX.mX[17UL] *
    0.016666666666666666 + t21->mX.mX[18UL] * 0.00014705882352941175) +
    t21->mX.mX[12UL] * -0.00014705882352941175) + t21->mX.mX[20UL]);
  out->mLOG.mX[53UL] = t21->mX.mX[18UL];
  out->mLOG.mX[54UL] = -t21->mX.mX[18UL];
  out->mLOG.mX[56UL] = t21->mU.mX[1UL];
  out->mLOG.mX[57UL] = t21->mX.mX[20UL];
  out->mLOG.mX[58UL] = t21->mX.mX[19UL];
  out->mLOG.mX[59UL] = t21->mX.mX[17UL];
  out->mLOG.mX[60UL] = SG_Variable_Resistor2_v;
  out->mLOG.mX[62UL] = t21->mU.mX[2UL];
  out->mLOG.mX[63UL] = SG_Variable_Resistor3_i;
  out->mLOG.mX[64UL] = t21->mX.mX[19UL];
  out->mLOG.mX[65UL] = t21->mX.mX[19UL];
  out->mLOG.mX[67UL] = -6.5217391304347834E-5 - t21->mX.mX[21UL];
  out->mLOG.mX[68UL] = t21->mX.mX[8UL];
  out->mLOG.mX[69UL] = t21->mX.mX[11UL];
  out->mLOG.mX[70UL] = t21->mX.mX[19UL];
  out->mLOG.mX[71UL] = t21->mX.mX[18UL];
  out->mLOG.mX[72UL] = t21->mX.mX[22UL];
  out->mLOG.mX[73UL] = Subsystem1_Psuedo_AD8132_C1a_n_v;
  out->mLOG.mX[74UL] = t21->mX.mX[9UL];
  out->mLOG.mX[76UL] = t21->mX.mX[3UL];
  out->mLOG.mX[78UL] = Subsystem1_Psuedo_AD8132_C1b_i;
  out->mLOG.mX[79UL] = t21->mX.mX[12UL];
  out->mLOG.mX[80UL] = Subsystem1_Psuedo_AD8132_C1a_n_v;
  out->mLOG.mX[82UL] = t21->mX.mX[4UL];
  out->mLOG.mX[84UL] = Subsystem1_Psuedo_AD8132_C2_i;
  out->mLOG.mX[85UL] = Subsystem1_Psuedo_AD8132_C1a_n_v;
  out->mLOG.mX[86UL] = Subsystem1_Psuedo_AD8132_C1a_n_v;
  out->mLOG.mX[87UL] = t21->mX.mX[5UL];
  out->mLOG.mX[89UL] = Subsystem1_Psuedo_AD8132_R1a_i;
  out->mLOG.mX[90UL] = Subsystem1_Psuedo_AD8132_C1a_n_v;
  out->mLOG.mX[91UL] = t21->mX.mX[9UL];
  out->mLOG.mX[92UL] = Subsystem1_Psuedo_AD8132_R1a_i * 650000.0;
  out->mLOG.mX[94UL] = Subsystem1_Psuedo_AD8132_R1b_i;
  out->mLOG.mX[95UL] = t21->mX.mX[12UL];
  out->mLOG.mX[96UL] = Subsystem1_Psuedo_AD8132_C1a_n_v;
  out->mLOG.mX[97UL] = Subsystem1_Psuedo_AD8132_R1b_i * 650000.0;
  out->mLOG.mX[99UL] = Subsystem1_Psuedo_AD8132_R2_i;
  out->mLOG.mX[100UL] = Subsystem1_Psuedo_AD8132_C1a_n_v;
  out->mLOG.mX[101UL] = Subsystem1_Psuedo_AD8132_R2_i * 350000.0;
  out->mLOG.mX[104UL] = -1.5 + (-t21->mX.mX[1UL] + t21->mX.mX[11UL]);
  out->mLOG.mX[105UL] = -1.5 + (-t21->mX.mX[0UL] + t21->mX.mX[8UL]);
  out->mLOG.mX[106UL] = t21->mX.mX[9UL];
  out->mLOG.mX[107UL] = t21->mX.mX[11UL];
  out->mLOG.mX[108UL] = t21->mX.mX[8UL];
  out->mLOG.mX[109UL] = t21->mX.mX[12UL];
  out->mLOG.mX[110UL] = t21->mX.mX[1UL];
  out->mLOG.mX[111UL] = t21->mX.mX[0UL];
  out->mLOG.mX[112UL] = t21->mX.mX[9UL];
  out->mLOG.mX[113UL] = t21->mX.mX[11UL];
  out->mLOG.mX[114UL] = t21->mX.mX[8UL];
  out->mLOG.mX[115UL] = t21->mX.mX[12UL];
  out->mLOG.mX[116UL] = t21->mX.mX[11UL];
  out->mLOG.mX[117UL] = t21->mX.mX[12UL];
  out->mLOG.mX[118UL] = Subsystem1_Psuedo_AD8132_diff_op_amp_eqn_i_out_p;
  out->mLOG.mX[119UL] = t21->mX.mX[11UL];
  out->mLOG.mX[120UL] = t21->mX.mX[12UL];
  out->mLOG.mX[121UL] = Subsystem1_Psuedo_AD8132_diff_op_amp_eqn_i_out_p *
    330000.0;
  out->mLOG.mX[123UL] = t21->mX.mX[8UL];
  out->mLOG.mX[124UL] = t21->mX.mX[9UL];
  out->mLOG.mX[125UL] = Subsystem1_RF1_Resistor_i;
  out->mLOG.mX[126UL] = t21->mX.mX[8UL];
  out->mLOG.mX[127UL] = t21->mX.mX[9UL];
  out->mLOG.mX[128UL] = Subsystem1_RF1_Resistor_i * 330000.0;
  out->mLOG.mX[130UL] = t21->mX.mX[12UL];
  out->mLOG.mX[131UL] = t21->mX.mX[18UL];
  out->mLOG.mX[132UL] = Subsystem1_RG_Resistor_i;
  out->mLOG.mX[133UL] = t21->mX.mX[12UL];
  out->mLOG.mX[134UL] = t21->mX.mX[18UL];
  out->mLOG.mX[135UL] = Subsystem1_RG_Resistor_i * 6800.0;
  out->mLOG.mX[137UL] = Subsystem1_RG1_i;
  out->mLOG.mX[138UL] = t21->mX.mX[9UL];
  out->mLOG.mX[139UL] = t21->mX.mX[19UL];
  out->mLOG.mX[140UL] = Subsystem1_RG1_i * 6800.0;
  out->mLOG.mX[142UL] = t21->mX.mX[21UL];
  out->mLOG.mX[143UL] = t21->mX.mX[6UL];
  out->mLOG.mX[144UL] = 0.0;
  out->mLOG.mX[146UL] = t21->mX.mX[16UL];
  out->mLOG.mX[147UL] = Resistor3_n_v;
  out->mLOG.mX[149UL] = t21->mX.mX[2UL];
  out->mLOG.mX[150UL] = 0.0;
  out->mLOG.mX[152UL] = Subsystem2_Capacitor2_n_v;
  out->mLOG.mX[153UL] = t21->mX.mX[23UL];
  out->mLOG.mX[155UL] = t21->mX.mX[7UL];
  out->mLOG.mX[156UL] = 0.0;
  out->mLOG.mX[157UL] = t21->mX.mX[10UL];
  out->mLOG.mX[158UL] = t21->mX.mX[13UL];
  out->mLOG.mX[159UL] = Resistor3_n_v;
  out->mLOG.mX[160UL] = t21->mX.mX[16UL];
  out->mLOG.mX[161UL] = t21->mX.mX[23UL];
  out->mLOG.mX[162UL] = t21->mX.mX[10UL];
  out->mLOG.mX[163UL] = Subsystem2_Resistor1_Resistor_i;
  out->mLOG.mX[164UL] = t21->mX.mX[23UL];
  out->mLOG.mX[165UL] = t21->mX.mX[10UL];
  out->mLOG.mX[166UL] = Subsystem2_Resistor1_Resistor_i * 72.0;
  out->mLOG.mX[168UL] = Resistor3_n_v;
  out->mLOG.mX[169UL] = t21->mX.mX[23UL];
  out->mLOG.mX[170UL] = Subsystem2_Resistor2_Resistor_i;
  out->mLOG.mX[171UL] = Resistor3_n_v;
  out->mLOG.mX[172UL] = t21->mX.mX[23UL];
  out->mLOG.mX[173UL] = Subsystem2_Resistor2_Resistor_i * 72.0;
  out->mLOG.mX[175UL] = Subsystem2_Capacitor2_n_v;
  out->mLOG.mX[176UL] = t21->mX.mX[13UL];
  out->mLOG.mX[177UL] = Subsystem2_Resistor3_Resistor_i;
  out->mLOG.mX[178UL] = Subsystem2_Capacitor2_n_v;
  out->mLOG.mX[179UL] = t21->mX.mX[13UL];
  out->mLOG.mX[180UL] = Subsystem2_Resistor3_Resistor_i * 72.0;
  out->mLOG.mX[182UL] = t21->mX.mX[16UL];
  out->mLOG.mX[183UL] = Subsystem2_Capacitor2_n_v;
  out->mLOG.mX[184UL] = Subsystem2_Resistor4_Resistor_i;
  out->mLOG.mX[185UL] = t21->mX.mX[16UL];
  out->mLOG.mX[186UL] = Subsystem2_Capacitor2_n_v;
  out->mLOG.mX[187UL] = Subsystem2_Resistor4_Resistor_i * 72.0;
  out->mLOG.mX[189UL] = Voltage_Sensor_V;
  out->mLOG.mX[190UL] = t21->mX.mX[16UL];
  out->mLOG.mX[191UL] = Resistor3_n_v;
  out->mLOG.mX[192UL] = Voltage_Sensor1_V;
  out->mLOG.mX[193UL] = t21->mX.mX[19UL];
  out->mLOG.mX[194UL] = t21->mX.mX[18UL];
  out->mLOG.mX[195UL] = Voltage_Sensor1_V;
  out->mLOG.mX[196UL] = t21->mX.mX[10UL];
  out->mLOG.mX[197UL] = t21->mX.mX[10UL];
  out->mLOG.mX[198UL] = t21->mX.mX[10UL];
  out->mLOG.mX[199UL] = Voltage_Sensor3_V;
  out->mLOG.mX[200UL] = t21->mX.mX[13UL];
  out->mLOG.mX[201UL] = t21->mX.mX[10UL];
  out->mLOG.mX[202UL] = Voltage_Sensor3_V;
  out->mLOG.mX[203UL] = t21->mX.mX[13UL];
  out->mLOG.mX[204UL] = t21->mX.mX[13UL];
  out->mLOG.mX[205UL] = t21->mX.mX[13UL];
  out->mLOG.mX[206UL] = Voltage_Sensor3_V;
  out->mLOG.mX[207UL] = t21->mX.mX[13UL];
  out->mLOG.mX[208UL] = t21->mX.mX[10UL];
  out->mLOG.mX[209UL] = Voltage_Sensor3_V;
  out->mLOG.mX[211UL] = t21->mX.mX[14UL];
  out->mLOG.mX[212UL] = t21->mX.mX[15UL];
  out->mLOG.mX[213UL] = t21->mX.mX[15UL];
  out->mLOG.mX[214UL] = t21->mX.mX[15UL];
  out->mLOG.mX[215UL] = Voltage_Sensor_V;
  (void)sys;
  (void)out;
  return 0;
}
