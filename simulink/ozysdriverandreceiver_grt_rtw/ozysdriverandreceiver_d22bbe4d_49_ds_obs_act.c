/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'ozysdriverandreceiver/Solver Configuration'.
 */

#include "ne_ds.h"
#include "ozysdriverandreceiver_d22bbe4d_49_ds_sys_struct.h"
#include "ozysdriverandreceiver_d22bbe4d_49_ds_obs_act.h"
#include "ozysdriverandreceiver_d22bbe4d_49_ds.h"
#include "ozysdriverandreceiver_d22bbe4d_49_ds_externals.h"
#include "ozysdriverandreceiver_d22bbe4d_49_ds_external_struct.h"
#include "ssc_ml_fun.h"

int32_T ozysdriverandreceiver_d22bbe4d_49_ds_obs_act(const NeDynamicSystem *sys,
  const NeDynamicSystemInput *t21, NeDsMethodOutput *out)
{
  real_T t2[1];
  real_T t6[1];
  real_T t9[1];
  real_T Resistor2_i;
  real_T Resistor3_n_v;
  real_T Resistor_i;
  real_T Subsystem1_Psuedo_AD8132_C1a_n_v;
  real_T Subsystem1_Psuedo_AD8132_R1a_i;
  real_T Subsystem1_Psuedo_AD8132_R1b_i;
  real_T Subsystem1_Psuedo_AD8132_R2_i;
  real_T Subsystem1_Psuedo_AD8132_diff_op_amp_eqn_i_out_p;
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
  real_T t14;
  real_T zc_int3;
  int32_T t7[2];
  out->mOBS_ACT.mX[9UL] = -t21->mX.mX[8UL] + t21->mX.mX[10UL];
  out->mOBS_ACT.mX[15UL] = -t21->mX.mX[11UL] + t21->mX.mX[13UL];
  Resistor_i = t21->mX.mX[10UL] * 1.0E-6 + t21->mX.mX[14UL] * -1.0E-6;
  Resistor2_i = t21->mX.mX[15UL] * -1.0E-6 + t21->mX.mX[16UL] * 1.0E-6;
  Resistor3_n_v = t21->mX.mX[2UL] + t21->mX.mX[16UL];
  out->mOBS_ACT.mX[35UL] = -t21->mX.mX[17UL];
  out->mOBS_ACT.mX[58UL] = -t21->mX.mX[17UL] + t21->mX.mX[18UL];
  out->mOBS_ACT.mX[65UL] = -t21->mX.mX[18UL];
  out->mOBS_ACT.mX[72UL] = -t21->mX.mX[19UL] + t21->mX.mX[17UL];
  out->mOBS_ACT.mX[76UL] = (t21->mX.mX[19UL] * -0.00014705882352941175 +
    t21->mX.mX[9UL] * 0.00014705882352941175) + t21->mX.mX[20UL];
  out->mOBS_ACT.mX[79UL] = t21->mX.mX[19UL];
  Subsystem1_Psuedo_AD8132_C1a_n_v = (-t21->mX.mX[3UL] + t21->mX.mX[22UL] *
    -1.0E-6) + t21->mX.mX[9UL];
  out->mOBS_ACT.mX[92UL] = t21->mX.mX[22UL] * 1.0E-6 + t21->mX.mX[3UL];
  out->mOBS_ACT.mX[94UL] = ((((t21->mX.mX[3UL] * 1.5384615384615385E-6 +
    t21->mX.mX[11UL] * -3.0303030303030305E-6) + t21->mX.mX[18UL] *
    -0.00014705882352941175) + t21->mX.mX[22UL] * 1.5384615384615385E-12) +
    t21->mX.mX[9UL] * -1.5384615384615385E-6) + t21->mX.mX[12UL] *
    0.00015162758809817632;
  out->mOBS_ACT.mX[97UL] = ((-t21->mX.mX[3UL] + t21->mX.mX[22UL] * -1.0E-6) -
    t21->mX.mX[12UL]) + t21->mX.mX[9UL];
  out->mOBS_ACT.mX[99UL] = ((((t21->mX.mX[3UL] * 4.395604395604396E-6 +
    t21->mX.mX[11UL] * 3.0303030303030305E-6) + t21->mX.mX[18UL] *
    0.00014705882352941175) + t21->mX.mX[22UL] * 1.0000000000043956) +
    t21->mX.mX[9UL] * -2.8571428571428573E-6) + t21->mX.mX[12UL] *
    -0.00015008912655971478;
  Subsystem1_Psuedo_AD8132_R1a_i = t21->mX.mX[3UL] * 1.5384615384615385E-6 +
    t21->mX.mX[22UL] * 1.5384615384615385E-12;
  Subsystem1_Psuedo_AD8132_R1b_i = ((t21->mX.mX[3UL] * -1.5384615384615385E-6 +
    t21->mX.mX[22UL] * -1.5384615384615385E-12) + t21->mX.mX[9UL] *
    1.5384615384615385E-6) + t21->mX.mX[12UL] * -1.5384615384615385E-6;
  Subsystem1_Psuedo_AD8132_R2_i = (t21->mX.mX[3UL] * -2.8571428571428573E-6 +
    t21->mX.mX[22UL] * -2.857142857142857E-12) + t21->mX.mX[9UL] *
    2.8571428571428573E-6;
  out->mOBS_ACT.mX[126UL] = -(((-t21->mX.mX[1UL] + t21->mX.mX[11UL]) - 1.5) + ((
    -t21->mX.mX[0UL] + t21->mX.mX[8UL]) - 1.5));
  Subsystem1_Psuedo_AD8132_diff_op_amp_eqn_i_out_p = t21->mX.mX[11UL] *
    -3.0303030303030305E-6 + t21->mX.mX[12UL] * 3.0303030303030305E-6;
  t14 = t21->mX.mX[8UL] * -3.0303030303030305E-6 + t21->mX.mX[9UL] *
    3.0303030303030305E-6;
  Subsystem1_RG_Resistor_i = t21->mX.mX[18UL] * 0.00014705882352941175 +
    t21->mX.mX[12UL] * -0.00014705882352941175;
  Subsystem1_RG1_i = t21->mX.mX[19UL] * 0.00014705882352941175 + t21->mX.mX[9UL]
    * -0.00014705882352941175;
  out->mOBS_ACT.mX[196UL] = ((t21->mX.mX[7UL] * 0.013888888888888888 +
    t21->mX.mX[15UL] * -1.0E-6) + t21->mX.mX[16UL] * 0.013889888888888887) +
    t21->mX.mX[23UL] * -0.013888888888888888;
  out->mOBS_ACT.mX[199UL] = t21->mX.mX[2UL];
  out->mOBS_ACT.mX[206UL] = ((t21->mX.mX[7UL] * -0.027777777777777776 +
    t21->mX.mX[13UL] * -0.013888888888888888) + t21->mX.mX[16UL] *
    -0.013888888888888888) + t21->mX.mX[23UL] * 0.027777777777777776;
  Subsystem2_Capacitor2_n_v = -t21->mX.mX[7UL] + t21->mX.mX[23UL];
  out->mOBS_ACT.mX[209UL] = t21->mX.mX[7UL];
  Subsystem2_Resistor1_Resistor_i = t21->mX.mX[10UL] * 0.013888888888888888 +
    t21->mX.mX[23UL] * -0.013888888888888888;
  Subsystem2_Resistor2_Resistor_i = (t21->mX.mX[2UL] * -0.013888888888888888 +
    t21->mX.mX[16UL] * -0.013888888888888888) + t21->mX.mX[23UL] *
    0.013888888888888888;
  Subsystem2_Resistor3_Resistor_i = (t21->mX.mX[7UL] * 0.013888888888888888 +
    t21->mX.mX[13UL] * 0.013888888888888888) + t21->mX.mX[23UL] *
    -0.013888888888888888;
  Subsystem2_Resistor4_Resistor_i = (t21->mX.mX[7UL] * -0.013888888888888888 +
    t21->mX.mX[16UL] * -0.013888888888888888) + t21->mX.mX[23UL] *
    0.013888888888888888;
  Voltage_Sensor_V = Resistor3_n_v - t21->mX.mX[16UL];
  Voltage_Sensor1_V = t21->mX.mX[18UL] - t21->mX.mX[19UL];
  Voltage_Sensor3_V = t21->mX.mX[10UL] - t21->mX.mX[13UL];
  out->mOBS_ACT.mX[271UL] = t21->mX.mX[14UL];
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

  out->mOBS_ACT.mX[7UL] = t0;
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

  out->mOBS_ACT.mX[13UL] = zc_int3;
  piece9 = t21->mX.mX[17UL] * 0.016666666666666666;
  out->mOBS_ACT.mX[0UL] = 0.0;
  out->mOBS_ACT.mX[1UL] = 0.0;
  out->mOBS_ACT.mX[2UL] = 0.0;
  out->mOBS_ACT.mX[3UL] = 0.0;
  out->mOBS_ACT.mX[4UL] = -1.5 + ((-t21->mX.mX[0UL] + t21->mX.mX[8UL] *
    1.0000030303030303) + t21->mX.mX[9UL] * -3.0303030303030305E-6);
  out->mOBS_ACT.mX[5UL] = t21->mX.mX[8UL];
  out->mOBS_ACT.mX[6UL] = t21->mX.mX[10UL];
  out->mOBS_ACT.mX[8UL] = t0;
  out->mOBS_ACT.mX[10UL] = -1.5 + ((-t21->mX.mX[1UL] + t21->mX.mX[11UL] *
    1.0000030303030303) + t21->mX.mX[12UL] * -3.0303030303030305E-6);
  out->mOBS_ACT.mX[11UL] = t21->mX.mX[11UL];
  out->mOBS_ACT.mX[12UL] = t21->mX.mX[13UL];
  out->mOBS_ACT.mX[14UL] = zc_int3;
  out->mOBS_ACT.mX[16UL] = Resistor_i;
  out->mOBS_ACT.mX[17UL] = t21->mX.mX[14UL];
  out->mOBS_ACT.mX[18UL] = t21->mX.mX[10UL];
  out->mOBS_ACT.mX[19UL] = Resistor_i * 1.0E+6;
  out->mOBS_ACT.mX[20UL] = Resistor_i;
  out->mOBS_ACT.mX[21UL] = t21->mX.mX[13UL];
  out->mOBS_ACT.mX[22UL] = t21->mX.mX[14UL];
  out->mOBS_ACT.mX[23UL] = Resistor_i * 1.0E+6;
  out->mOBS_ACT.mX[24UL] = Resistor2_i;
  out->mOBS_ACT.mX[25UL] = t21->mX.mX[15UL];
  out->mOBS_ACT.mX[26UL] = t21->mX.mX[16UL];
  out->mOBS_ACT.mX[27UL] = Resistor2_i * 1.0E+6;
  out->mOBS_ACT.mX[28UL] = Resistor2_i;
  out->mOBS_ACT.mX[29UL] = Resistor3_n_v;
  out->mOBS_ACT.mX[30UL] = t21->mX.mX[15UL];
  out->mOBS_ACT.mX[31UL] = Resistor2_i * 1.0E+6;
  out->mOBS_ACT.mX[32UL] = -0.002;
  out->mOBS_ACT.mX[33UL] = t21->mX.mX[17UL];
  out->mOBS_ACT.mX[34UL] = 0.0;
  out->mOBS_ACT.mX[36UL] = -0.054999999999999993 + piece9;
  out->mOBS_ACT.mX[37UL] = 0.0;
  out->mOBS_ACT.mX[38UL] = 3.3;
  out->mOBS_ACT.mX[39UL] = 0.0;
  out->mOBS_ACT.mX[40UL] = 0.0;
  out->mOBS_ACT.mX[41UL] = 0.0;
  out->mOBS_ACT.mX[42UL] = 0.054999999999999993 - piece9;
  out->mOBS_ACT.mX[43UL] = t21->mX.mX[17UL];
  out->mOBS_ACT.mX[44UL] = 3.3;
  out->mOBS_ACT.mX[45UL] = (t21->mX.mX[17UL] * 0.016666666666666666 -
    0.054999999999999993) * -60.0;
  out->mOBS_ACT.mX[46UL] = t21->mU.mX[0UL];
  out->mOBS_ACT.mX[47UL] = t21->mU.mX[1UL];
  out->mOBS_ACT.mX[48UL] = t21->mU.mX[2UL];
  out->mOBS_ACT.mX[49UL] = t21->mU.mX[3UL];
  out->mOBS_ACT.mX[50UL] = t21->mX.mX[18UL];
  out->mOBS_ACT.mX[51UL] = t21->mX.mX[19UL];
  out->mOBS_ACT.mX[52UL] = 0.0;
  out->mOBS_ACT.mX[53UL] = t21->mU.mX[0UL];
  out->mOBS_ACT.mX[54UL] = 0.0;
  out->mOBS_ACT.mX[55UL] = -0.052999999999999992 + (t21->mX.mX[17UL] *
    0.016666666666666666 + t21->mX.mX[20UL]);
  out->mOBS_ACT.mX[56UL] = t21->mX.mX[17UL];
  out->mOBS_ACT.mX[57UL] = t21->mX.mX[18UL];
  out->mOBS_ACT.mX[59UL] = 0.0;
  out->mOBS_ACT.mX[60UL] = t21->mU.mX[3UL];
  out->mOBS_ACT.mX[61UL] = 0.0;
  out->mOBS_ACT.mX[62UL] = -0.052999999999999992 + (((t21->mX.mX[17UL] *
    0.016666666666666666 + t21->mX.mX[18UL] * 0.00014705882352941175) +
    t21->mX.mX[12UL] * -0.00014705882352941175) + t21->mX.mX[20UL]);
  out->mOBS_ACT.mX[63UL] = t21->mX.mX[18UL];
  out->mOBS_ACT.mX[64UL] = 0.0;
  out->mOBS_ACT.mX[66UL] = 0.0;
  out->mOBS_ACT.mX[67UL] = t21->mU.mX[1UL];
  out->mOBS_ACT.mX[68UL] = 0.0;
  out->mOBS_ACT.mX[69UL] = t21->mX.mX[20UL];
  out->mOBS_ACT.mX[70UL] = t21->mX.mX[19UL];
  out->mOBS_ACT.mX[71UL] = t21->mX.mX[17UL];
  out->mOBS_ACT.mX[73UL] = 0.0;
  out->mOBS_ACT.mX[74UL] = t21->mU.mX[2UL];
  out->mOBS_ACT.mX[75UL] = 0.0;
  out->mOBS_ACT.mX[77UL] = 0.0;
  out->mOBS_ACT.mX[78UL] = t21->mX.mX[19UL];
  out->mOBS_ACT.mX[80UL] = -6.5217391304347834E-5 - t21->mX.mX[21UL];
  out->mOBS_ACT.mX[81UL] = 0.0;
  out->mOBS_ACT.mX[82UL] = 1.5;
  out->mOBS_ACT.mX[83UL] = t21->mX.mX[8UL];
  out->mOBS_ACT.mX[84UL] = t21->mX.mX[11UL];
  out->mOBS_ACT.mX[85UL] = t21->mX.mX[19UL];
  out->mOBS_ACT.mX[86UL] = t21->mX.mX[18UL];
  out->mOBS_ACT.mX[87UL] = 0.0;
  out->mOBS_ACT.mX[88UL] = 0.0;
  out->mOBS_ACT.mX[89UL] = t21->mX.mX[22UL];
  out->mOBS_ACT.mX[90UL] = Subsystem1_Psuedo_AD8132_C1a_n_v;
  out->mOBS_ACT.mX[91UL] = t21->mX.mX[9UL];
  out->mOBS_ACT.mX[93UL] = t21->mX.mX[3UL];
  out->mOBS_ACT.mX[95UL] = t21->mX.mX[12UL];
  out->mOBS_ACT.mX[96UL] = Subsystem1_Psuedo_AD8132_C1a_n_v;
  out->mOBS_ACT.mX[98UL] = t21->mX.mX[4UL];
  out->mOBS_ACT.mX[100UL] = 0.0;
  out->mOBS_ACT.mX[101UL] = Subsystem1_Psuedo_AD8132_C1a_n_v;
  out->mOBS_ACT.mX[102UL] = Subsystem1_Psuedo_AD8132_C1a_n_v;
  out->mOBS_ACT.mX[103UL] = t21->mX.mX[5UL];
  out->mOBS_ACT.mX[104UL] = Subsystem1_Psuedo_AD8132_R1a_i;
  out->mOBS_ACT.mX[105UL] = Subsystem1_Psuedo_AD8132_C1a_n_v;
  out->mOBS_ACT.mX[106UL] = t21->mX.mX[9UL];
  out->mOBS_ACT.mX[107UL] = Subsystem1_Psuedo_AD8132_R1a_i * 650000.0;
  out->mOBS_ACT.mX[108UL] = Subsystem1_Psuedo_AD8132_R1b_i;
  out->mOBS_ACT.mX[109UL] = t21->mX.mX[12UL];
  out->mOBS_ACT.mX[110UL] = Subsystem1_Psuedo_AD8132_C1a_n_v;
  out->mOBS_ACT.mX[111UL] = Subsystem1_Psuedo_AD8132_R1b_i * 650000.0;
  out->mOBS_ACT.mX[112UL] = Subsystem1_Psuedo_AD8132_R2_i;
  out->mOBS_ACT.mX[113UL] = 0.0;
  out->mOBS_ACT.mX[114UL] = Subsystem1_Psuedo_AD8132_C1a_n_v;
  out->mOBS_ACT.mX[115UL] = Subsystem1_Psuedo_AD8132_R2_i * 350000.0;
  out->mOBS_ACT.mX[116UL] = 7.6086956521739124E-5;
  out->mOBS_ACT.mX[117UL] = 1.5;
  out->mOBS_ACT.mX[118UL] = 5.0;
  out->mOBS_ACT.mX[119UL] = 3.4999999999999996;
  out->mOBS_ACT.mX[120UL] = 0.00014130434782608697;
  out->mOBS_ACT.mX[121UL] = -5.0;
  out->mOBS_ACT.mX[122UL] = 1.5;
  out->mOBS_ACT.mX[123UL] = 6.5000000000000009;
  out->mOBS_ACT.mX[124UL] = 1.5;
  out->mOBS_ACT.mX[125UL] = 1.5;
  out->mOBS_ACT.mX[127UL] = 0.0;
  out->mOBS_ACT.mX[128UL] = -1.5 + (-t21->mX.mX[1UL] + t21->mX.mX[11UL]);
  out->mOBS_ACT.mX[129UL] = -1.5 + (-t21->mX.mX[0UL] + t21->mX.mX[8UL]);
  out->mOBS_ACT.mX[130UL] = 0.0;
  out->mOBS_ACT.mX[131UL] = t21->mX.mX[9UL];
  out->mOBS_ACT.mX[132UL] = t21->mX.mX[11UL];
  out->mOBS_ACT.mX[133UL] = t21->mX.mX[8UL];
  out->mOBS_ACT.mX[134UL] = t21->mX.mX[12UL];
  out->mOBS_ACT.mX[135UL] = t21->mX.mX[1UL];
  out->mOBS_ACT.mX[136UL] = t21->mX.mX[0UL];
  out->mOBS_ACT.mX[137UL] = t21->mX.mX[9UL];
  out->mOBS_ACT.mX[138UL] = 0.00014130434782608697;
  out->mOBS_ACT.mX[139UL] = -5.0;
  out->mOBS_ACT.mX[140UL] = t21->mX.mX[11UL];
  out->mOBS_ACT.mX[141UL] = t21->mX.mX[8UL];
  out->mOBS_ACT.mX[142UL] = t21->mX.mX[12UL];
  out->mOBS_ACT.mX[143UL] = -7.6086956521739124E-5;
  out->mOBS_ACT.mX[144UL] = 5.0;
  out->mOBS_ACT.mX[145UL] = 0.0;
  out->mOBS_ACT.mX[146UL] = 0.0;
  out->mOBS_ACT.mX[147UL] = 0.0;
  out->mOBS_ACT.mX[148UL] = 0.0;
  out->mOBS_ACT.mX[149UL] = 0.0;
  out->mOBS_ACT.mX[150UL] = 1.5;
  out->mOBS_ACT.mX[151UL] = 1.5;
  out->mOBS_ACT.mX[152UL] = 1.5;
  out->mOBS_ACT.mX[153UL] = 1.5;
  out->mOBS_ACT.mX[154UL] = 0.0;
  out->mOBS_ACT.mX[155UL] = 0.0;
  out->mOBS_ACT.mX[156UL] = t21->mX.mX[11UL];
  out->mOBS_ACT.mX[157UL] = t21->mX.mX[12UL];
  out->mOBS_ACT.mX[158UL] = Subsystem1_Psuedo_AD8132_diff_op_amp_eqn_i_out_p;
  out->mOBS_ACT.mX[159UL] = t21->mX.mX[11UL];
  out->mOBS_ACT.mX[160UL] = t21->mX.mX[12UL];
  out->mOBS_ACT.mX[161UL] = Subsystem1_Psuedo_AD8132_diff_op_amp_eqn_i_out_p *
    330000.0;
  out->mOBS_ACT.mX[162UL] = 0.0;
  out->mOBS_ACT.mX[163UL] = 0.0;
  out->mOBS_ACT.mX[164UL] = t21->mX.mX[8UL];
  out->mOBS_ACT.mX[165UL] = t21->mX.mX[9UL];
  out->mOBS_ACT.mX[166UL] = t14;
  out->mOBS_ACT.mX[167UL] = t21->mX.mX[8UL];
  out->mOBS_ACT.mX[168UL] = t21->mX.mX[9UL];
  out->mOBS_ACT.mX[169UL] = t14 * 330000.0;
  out->mOBS_ACT.mX[170UL] = 0.0;
  out->mOBS_ACT.mX[171UL] = 0.0;
  out->mOBS_ACT.mX[172UL] = t21->mX.mX[12UL];
  out->mOBS_ACT.mX[173UL] = t21->mX.mX[18UL];
  out->mOBS_ACT.mX[174UL] = Subsystem1_RG_Resistor_i;
  out->mOBS_ACT.mX[175UL] = t21->mX.mX[12UL];
  out->mOBS_ACT.mX[176UL] = t21->mX.mX[18UL];
  out->mOBS_ACT.mX[177UL] = Subsystem1_RG_Resistor_i * 6800.0;
  out->mOBS_ACT.mX[178UL] = Subsystem1_RG1_i;
  out->mOBS_ACT.mX[179UL] = t21->mX.mX[9UL];
  out->mOBS_ACT.mX[180UL] = t21->mX.mX[19UL];
  out->mOBS_ACT.mX[181UL] = Subsystem1_RG1_i * 6800.0;
  out->mOBS_ACT.mX[182UL] = 0.0;
  out->mOBS_ACT.mX[183UL] = 0.0;
  out->mOBS_ACT.mX[184UL] = 0.0;
  out->mOBS_ACT.mX[185UL] = 0.0;
  out->mOBS_ACT.mX[186UL] = t21->mX.mX[21UL];
  out->mOBS_ACT.mX[187UL] = 0.0;
  out->mOBS_ACT.mX[188UL] = 1.5;
  out->mOBS_ACT.mX[189UL] = 1.5;
  out->mOBS_ACT.mX[190UL] = t21->mX.mX[6UL];
  out->mOBS_ACT.mX[191UL] = 0.0;
  out->mOBS_ACT.mX[192UL] = 0.0;
  out->mOBS_ACT.mX[193UL] = 0.0;
  out->mOBS_ACT.mX[194UL] = 0.0;
  out->mOBS_ACT.mX[195UL] = 0.0;
  out->mOBS_ACT.mX[197UL] = t21->mX.mX[16UL];
  out->mOBS_ACT.mX[198UL] = Resistor3_n_v;
  out->mOBS_ACT.mX[200UL] = t21->mX.mX[2UL];
  out->mOBS_ACT.mX[201UL] = 0.0;
  out->mOBS_ACT.mX[202UL] = 0.0;
  out->mOBS_ACT.mX[203UL] = 0.0;
  out->mOBS_ACT.mX[204UL] = 0.0;
  out->mOBS_ACT.mX[205UL] = 0.0;
  out->mOBS_ACT.mX[207UL] = Subsystem2_Capacitor2_n_v;
  out->mOBS_ACT.mX[208UL] = t21->mX.mX[23UL];
  out->mOBS_ACT.mX[210UL] = t21->mX.mX[7UL];
  out->mOBS_ACT.mX[211UL] = 0.0;
  out->mOBS_ACT.mX[212UL] = t21->mX.mX[10UL];
  out->mOBS_ACT.mX[213UL] = t21->mX.mX[13UL];
  out->mOBS_ACT.mX[214UL] = Resistor3_n_v;
  out->mOBS_ACT.mX[215UL] = t21->mX.mX[16UL];
  out->mOBS_ACT.mX[216UL] = 0.0;
  out->mOBS_ACT.mX[217UL] = 0.0;
  out->mOBS_ACT.mX[218UL] = t21->mX.mX[23UL];
  out->mOBS_ACT.mX[219UL] = t21->mX.mX[10UL];
  out->mOBS_ACT.mX[220UL] = Subsystem2_Resistor1_Resistor_i;
  out->mOBS_ACT.mX[221UL] = t21->mX.mX[23UL];
  out->mOBS_ACT.mX[222UL] = t21->mX.mX[10UL];
  out->mOBS_ACT.mX[223UL] = Subsystem2_Resistor1_Resistor_i * 72.0;
  out->mOBS_ACT.mX[224UL] = 0.0;
  out->mOBS_ACT.mX[225UL] = 0.0;
  out->mOBS_ACT.mX[226UL] = Resistor3_n_v;
  out->mOBS_ACT.mX[227UL] = t21->mX.mX[23UL];
  out->mOBS_ACT.mX[228UL] = Subsystem2_Resistor2_Resistor_i;
  out->mOBS_ACT.mX[229UL] = Resistor3_n_v;
  out->mOBS_ACT.mX[230UL] = t21->mX.mX[23UL];
  out->mOBS_ACT.mX[231UL] = Subsystem2_Resistor2_Resistor_i * 72.0;
  out->mOBS_ACT.mX[232UL] = 0.0;
  out->mOBS_ACT.mX[233UL] = 0.0;
  out->mOBS_ACT.mX[234UL] = Subsystem2_Capacitor2_n_v;
  out->mOBS_ACT.mX[235UL] = t21->mX.mX[13UL];
  out->mOBS_ACT.mX[236UL] = Subsystem2_Resistor3_Resistor_i;
  out->mOBS_ACT.mX[237UL] = Subsystem2_Capacitor2_n_v;
  out->mOBS_ACT.mX[238UL] = t21->mX.mX[13UL];
  out->mOBS_ACT.mX[239UL] = Subsystem2_Resistor3_Resistor_i * 72.0;
  out->mOBS_ACT.mX[240UL] = 0.0;
  out->mOBS_ACT.mX[241UL] = 0.0;
  out->mOBS_ACT.mX[242UL] = t21->mX.mX[16UL];
  out->mOBS_ACT.mX[243UL] = Subsystem2_Capacitor2_n_v;
  out->mOBS_ACT.mX[244UL] = Subsystem2_Resistor4_Resistor_i;
  out->mOBS_ACT.mX[245UL] = t21->mX.mX[16UL];
  out->mOBS_ACT.mX[246UL] = Subsystem2_Capacitor2_n_v;
  out->mOBS_ACT.mX[247UL] = Subsystem2_Resistor4_Resistor_i * 72.0;
  out->mOBS_ACT.mX[248UL] = Voltage_Sensor_V;
  out->mOBS_ACT.mX[249UL] = t21->mX.mX[16UL];
  out->mOBS_ACT.mX[250UL] = Resistor3_n_v;
  out->mOBS_ACT.mX[251UL] = Voltage_Sensor1_V;
  out->mOBS_ACT.mX[252UL] = t21->mX.mX[19UL];
  out->mOBS_ACT.mX[253UL] = t21->mX.mX[18UL];
  out->mOBS_ACT.mX[254UL] = Voltage_Sensor1_V;
  out->mOBS_ACT.mX[255UL] = t21->mX.mX[10UL];
  out->mOBS_ACT.mX[256UL] = 0.0;
  out->mOBS_ACT.mX[257UL] = t21->mX.mX[10UL];
  out->mOBS_ACT.mX[258UL] = t21->mX.mX[10UL];
  out->mOBS_ACT.mX[259UL] = Voltage_Sensor3_V;
  out->mOBS_ACT.mX[260UL] = t21->mX.mX[13UL];
  out->mOBS_ACT.mX[261UL] = t21->mX.mX[10UL];
  out->mOBS_ACT.mX[262UL] = Voltage_Sensor3_V;
  out->mOBS_ACT.mX[263UL] = t21->mX.mX[13UL];
  out->mOBS_ACT.mX[264UL] = 0.0;
  out->mOBS_ACT.mX[265UL] = t21->mX.mX[13UL];
  out->mOBS_ACT.mX[266UL] = t21->mX.mX[13UL];
  out->mOBS_ACT.mX[267UL] = Voltage_Sensor3_V;
  out->mOBS_ACT.mX[268UL] = t21->mX.mX[13UL];
  out->mOBS_ACT.mX[269UL] = t21->mX.mX[10UL];
  out->mOBS_ACT.mX[270UL] = Voltage_Sensor3_V;
  out->mOBS_ACT.mX[272UL] = 0.0;
  out->mOBS_ACT.mX[273UL] = t21->mX.mX[14UL];
  out->mOBS_ACT.mX[274UL] = t21->mX.mX[15UL];
  out->mOBS_ACT.mX[275UL] = 0.0;
  out->mOBS_ACT.mX[276UL] = t21->mX.mX[15UL];
  out->mOBS_ACT.mX[277UL] = t21->mX.mX[15UL];
  out->mOBS_ACT.mX[278UL] = Voltage_Sensor_V;
  (void)sys;
  (void)out;
  return 0;
}
