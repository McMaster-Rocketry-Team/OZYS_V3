/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'ozysdriverandreceiver/Solver Configuration'.
 */
/* ozysdriverandreceiver_d22bbe4d_49_ds.c - body for module ozysdriverandreceiver_d22bbe4d_49_ds */

#include "ne_ds.h"
#include "ozysdriverandreceiver_d22bbe4d_49_ds_dxicrm_p.h"
#include "ozysdriverandreceiver_d22bbe4d_49_ds_dxf_p.h"
#include "ozysdriverandreceiver_d22bbe4d_49_ds_tdxf_p.h"
#include "ozysdriverandreceiver_d22bbe4d_49_ds_tdxy_p.h"
#include "ozysdriverandreceiver_d22bbe4d_49_ds_dxy_p.h"
#include "ozysdriverandreceiver_d22bbe4d_49_ds_obs_exp.h"
#include "ozysdriverandreceiver_d22bbe4d_49_ds_dxf.h"
#include "ozysdriverandreceiver_d22bbe4d_49_ds_zc.h"
#include "ozysdriverandreceiver_d22bbe4d_49_ds_vmf.h"
#include "ozysdriverandreceiver_d22bbe4d_49_ds_obs_act.h"
#include "ozysdriverandreceiver_d22bbe4d_49_ds_nldv.h"
#include "ozysdriverandreceiver_d22bbe4d_49_ds_lv.h"
#include "ozysdriverandreceiver_d22bbe4d_49_ds_dnf_v_x.h"
#include "ozysdriverandreceiver_d22bbe4d_49_ds_assert.h"
#include "ozysdriverandreceiver_d22bbe4d_49_ds_dnf_p.h"
#include "ozysdriverandreceiver_d22bbe4d_49_ds_imin.h"
#include "ozysdriverandreceiver_d22bbe4d_49_ds_log.h"
#include "ozysdriverandreceiver_d22bbe4d_49_ds_slv.h"
#include "ozysdriverandreceiver_d22bbe4d_49_ds_obs_all.h"
#include "ozysdriverandreceiver_d22bbe4d_49_ds_dxdelt_p.h"
#include "ozysdriverandreceiver_d22bbe4d_49_ds_obs_il.h"
#include "ozysdriverandreceiver_d22bbe4d_49_ds_mcon_p.h"
#include "ozysdriverandreceiver_d22bbe4d_49_ds_f.h"
#include "ozysdriverandreceiver_d22bbe4d_49_ds_acon_p.h"
#include "ozysdriverandreceiver_d22bbe4d_49_ds_acon.h"
#include "ozysdriverandreceiver_d22bbe4d_49_ds_mnl_p.h"
#include "ozysdriverandreceiver_d22bbe4d_49_ds_imax.h"
#include "ozysdriverandreceiver_d22bbe4d_49_ds_mode.h"
#include "ozysdriverandreceiver_d22bbe4d_49_ds.h"
#include "ssc_ml_fun.h"
#include "ozysdriverandreceiver_d22bbe4d_49_ds_external_struct.h"
#include "ozysdriverandreceiver_d22bbe4d_49_ds_externals.h"
#include "ozysdriverandreceiver_d22bbe4d_49_ds_sys_struct.h"

static int32_T ds_mcon(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
  NeDsMethodOutput *out);
static int32_T ds_mpar_p(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_mpar(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
  NeDsMethodOutput *out);
static int32_T ds_mnl(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
                      NeDsMethodOutput *out);
static int32_T ds_vmm(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
                      NeDsMethodOutput *out);
static int32_T ds_dxm_p(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_dxm(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
                      NeDsMethodOutput *out);
static int32_T ds_ddm_p(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_ddm(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
                      NeDsMethodOutput *out);
static int32_T ds_dum_p(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_dum(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
                      NeDsMethodOutput *out);
static int32_T ds_dtm_p(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_dtm(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
                      NeDsMethodOutput *out);
static int32_T ds_dpm_p(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_dpm(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
                      NeDsMethodOutput *out);
static int32_T ds_apar_p(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_apar(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
  NeDsMethodOutput *out);
static int32_T ds_bcon_p(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_bcon(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
  NeDsMethodOutput *out);
static int32_T ds_bpar_p(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_bpar(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
  NeDsMethodOutput *out);
static int32_T ds_ccon_p(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_ccon(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
  NeDsMethodOutput *out);
static int32_T ds_cpar_p(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_cpar(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
  NeDsMethodOutput *out);
static int32_T ds_vpf(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
                      NeDsMethodOutput *out);
static int32_T ds_vsf(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
                      NeDsMethodOutput *out);
static int32_T ds_slf(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
                      NeDsMethodOutput *out);
static int32_T ds_slf0(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
  NeDsMethodOutput *out);
static int32_T ds_duf_p(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_duf(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
                      NeDsMethodOutput *out);
static int32_T ds_dtf_p(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_dtf(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
                      NeDsMethodOutput *out);
static int32_T ds_ddf_p(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_ddf(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
                      NeDsMethodOutput *out);
static int32_T ds_dpdxf_p(const NeDynamicSystem *ds, const NeDynamicSystemInput *
  in, NeDsMethodOutput *out);
static int32_T ds_dpdxf(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_dwf_p(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_dwf(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
                      NeDsMethodOutput *out);
static int32_T ds_tduf_p(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_dnf(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
                      NeDsMethodOutput *out);
static int32_T ds_cer(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
                      NeDsMethodOutput *out);
static int32_T ds_dxcer(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_dxcer_p(const NeDynamicSystem *ds, const NeDynamicSystemInput *
  in, NeDsMethodOutput *out);
static int32_T ds_ddcer(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_ddcer_p(const NeDynamicSystem *ds, const NeDynamicSystemInput *
  in, NeDsMethodOutput *out);
static int32_T ds_ic(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
                     NeDsMethodOutput *out);
static int32_T ds_icr(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
                      NeDsMethodOutput *out);
static int32_T ds_icr_im(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_icr_id(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_icr_il(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_dxicr(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_dxicr_p(const NeDynamicSystem *ds, const NeDynamicSystemInput *
  in, NeDsMethodOutput *out);
static int32_T ds_ddicr(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_ddicr_p(const NeDynamicSystem *ds, const NeDynamicSystemInput *
  in, NeDsMethodOutput *out);
static int32_T ds_tduicr_p(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_icrm_p(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_icrm(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
  NeDsMethodOutput *out);
static int32_T ds_dxicrm(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_ddicrm_p(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_ddicrm(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_freqs(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_solverhits(const NeDynamicSystem *ds, const
  NeDynamicSystemInput *in, NeDsMethodOutput *out);
static int32_T ds_mduy_p(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_mdxy_p(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_tduy_p(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_y(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
                    NeDsMethodOutput *out);
static int32_T ds_dxy(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
                      NeDsMethodOutput *out);
static int32_T ds_duy_p(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_duy(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
                      NeDsMethodOutput *out);
static int32_T ds_dty_p(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_dty(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
                      NeDsMethodOutput *out);
static int32_T ds_cache_r(const NeDynamicSystem *ds, const NeDynamicSystemInput *
  in, NeDsMethodOutput *out);
static int32_T ds_cache_i(const NeDynamicSystem *ds, const NeDynamicSystemInput *
  in, NeDsMethodOutput *out);
static int32_T ds_update_r(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_update_i(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_update2_r(const NeDynamicSystem *ds, const
  NeDynamicSystemInput *in, NeDsMethodOutput *out);
static int32_T ds_update2_i(const NeDynamicSystem *ds, const
  NeDynamicSystemInput *in, NeDsMethodOutput *out);
static int32_T ds_lock_r(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_lock_i(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_lock2_r(const NeDynamicSystem *ds, const NeDynamicSystemInput *
  in, NeDsMethodOutput *out);
static int32_T ds_lock2_i(const NeDynamicSystem *ds, const NeDynamicSystemInput *
  in, NeDsMethodOutput *out);
static int32_T ds_sfo(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
                      NeDsMethodOutput *out);
static int32_T ds_sfp(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
                      NeDsMethodOutput *out);
static int32_T ds_init_r(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_init_i(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_passert(const NeDynamicSystem *ds, const NeDynamicSystemInput *
  in, NeDsMethodOutput *out);
static int32_T ds_iassert(const NeDynamicSystem *ds, const NeDynamicSystemInput *
  in, NeDsMethodOutput *out);
static int32_T ds_del_t(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_del_v(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_del_v0(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_del_tmax(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_dxdelt(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_dudelt_p(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_dudelt(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_dtdelt_p(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_dtdelt(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_dp_l(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
  NeDsMethodOutput *out);
static int32_T ds_dp_i(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
  NeDsMethodOutput *out);
static int32_T ds_dp_j(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
  NeDsMethodOutput *out);
static int32_T ds_dp_r(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
  NeDsMethodOutput *out);
static int32_T ds_qx(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
                     NeDsMethodOutput *out);
static int32_T ds_qu(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
                     NeDsMethodOutput *out);
static int32_T ds_qt(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
                     NeDsMethodOutput *out);
static int32_T ds_q1(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
                     NeDsMethodOutput *out);
static int32_T ds_qx_p(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
  NeDsMethodOutput *out);
static int32_T ds_qu_p(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
  NeDsMethodOutput *out);
static int32_T ds_qt_p(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
  NeDsMethodOutput *out);
static int32_T ds_q1_p(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
  NeDsMethodOutput *out);
static int32_T ds_var_tol(const NeDynamicSystem *ds, const NeDynamicSystemInput *
  in, NeDsMethodOutput *out);
static int32_T ds_eq_tol(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_sclv(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
  NeDsMethodOutput *out);
static int32_T ds_dimin(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_dimax(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static NeDsMethodOutput *ds_output_mcon_p(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_mcon(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_mpar_p(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_mpar(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_mnl_p(const NeDynamicSystem *ds, PmAllocator *
  allocator);
static NeDsMethodOutput *ds_output_mnl(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_vmm(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_dxm_p(const NeDynamicSystem *ds, PmAllocator *
  allocator);
static NeDsMethodOutput *ds_output_dxm(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_ddm_p(const NeDynamicSystem *ds, PmAllocator *
  allocator);
static NeDsMethodOutput *ds_output_ddm(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_dum_p(const NeDynamicSystem *ds, PmAllocator *
  allocator);
static NeDsMethodOutput *ds_output_dum(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_dtm_p(const NeDynamicSystem *ds, PmAllocator *
  allocator);
static NeDsMethodOutput *ds_output_dtm(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_dpm_p(const NeDynamicSystem *ds, PmAllocator *
  allocator);
static NeDsMethodOutput *ds_output_dpm(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_acon_p(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_acon(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_apar_p(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_apar(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_bcon_p(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_bcon(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_bpar_p(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_bpar(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_ccon_p(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_ccon(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_cpar_p(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_cpar(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_f(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_vmf(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_vpf(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_vsf(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_slf(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_slf0(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_dxf_p(const NeDynamicSystem *ds, PmAllocator *
  allocator);
static NeDsMethodOutput *ds_output_dxf(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_duf_p(const NeDynamicSystem *ds, PmAllocator *
  allocator);
static NeDsMethodOutput *ds_output_duf(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_dtf_p(const NeDynamicSystem *ds, PmAllocator *
  allocator);
static NeDsMethodOutput *ds_output_dtf(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_ddf_p(const NeDynamicSystem *ds, PmAllocator *
  allocator);
static NeDsMethodOutput *ds_output_ddf(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_dpdxf_p(const NeDynamicSystem *ds,
  PmAllocator *allocator);
static NeDsMethodOutput *ds_output_dpdxf(const NeDynamicSystem *ds, PmAllocator *
  allocator);
static NeDsMethodOutput *ds_output_dwf_p(const NeDynamicSystem *ds, PmAllocator *
  allocator);
static NeDsMethodOutput *ds_output_dwf(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_tduf_p(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_tdxf_p(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_dnf_p(const NeDynamicSystem *ds, PmAllocator *
  allocator);
static NeDsMethodOutput *ds_output_dnf(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_dnf_v_x(const NeDynamicSystem *ds,
  PmAllocator *allocator);
static NeDsMethodOutput *ds_output_cer(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_dxcer(const NeDynamicSystem *ds, PmAllocator *
  allocator);
static NeDsMethodOutput *ds_output_dxcer_p(const NeDynamicSystem *ds,
  PmAllocator *allocator);
static NeDsMethodOutput *ds_output_ddcer(const NeDynamicSystem *ds, PmAllocator *
  allocator);
static NeDsMethodOutput *ds_output_ddcer_p(const NeDynamicSystem *ds,
  PmAllocator *allocator);
static NeDsMethodOutput *ds_output_ic(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_icr(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_icr_im(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_icr_id(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_icr_il(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_dxicr(const NeDynamicSystem *ds, PmAllocator *
  allocator);
static NeDsMethodOutput *ds_output_dxicr_p(const NeDynamicSystem *ds,
  PmAllocator *allocator);
static NeDsMethodOutput *ds_output_ddicr(const NeDynamicSystem *ds, PmAllocator *
  allocator);
static NeDsMethodOutput *ds_output_ddicr_p(const NeDynamicSystem *ds,
  PmAllocator *allocator);
static NeDsMethodOutput *ds_output_tduicr_p(const NeDynamicSystem *ds,
  PmAllocator *allocator);
static NeDsMethodOutput *ds_output_icrm_p(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_icrm(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_dxicrm_p(const NeDynamicSystem *ds,
  PmAllocator *allocator);
static NeDsMethodOutput *ds_output_dxicrm(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_ddicrm_p(const NeDynamicSystem *ds,
  PmAllocator *allocator);
static NeDsMethodOutput *ds_output_ddicrm(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_freqs(const NeDynamicSystem *ds, PmAllocator *
  allocator);
static NeDsMethodOutput *ds_output_solverhits(const NeDynamicSystem *ds,
  PmAllocator *allocator);
static NeDsMethodOutput *ds_output_mduy_p(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_mdxy_p(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_tduy_p(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_tdxy_p(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_y(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_dxy_p(const NeDynamicSystem *ds, PmAllocator *
  allocator);
static NeDsMethodOutput *ds_output_dxy(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_duy_p(const NeDynamicSystem *ds, PmAllocator *
  allocator);
static NeDsMethodOutput *ds_output_duy(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_dty_p(const NeDynamicSystem *ds, PmAllocator *
  allocator);
static NeDsMethodOutput *ds_output_dty(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_mode(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_zc(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_cache_r(const NeDynamicSystem *ds,
  PmAllocator *allocator);
static NeDsMethodOutput *ds_output_cache_i(const NeDynamicSystem *ds,
  PmAllocator *allocator);
static NeDsMethodOutput *ds_output_update_r(const NeDynamicSystem *ds,
  PmAllocator *allocator);
static NeDsMethodOutput *ds_output_update_i(const NeDynamicSystem *ds,
  PmAllocator *allocator);
static NeDsMethodOutput *ds_output_update2_r(const NeDynamicSystem *ds,
  PmAllocator *allocator);
static NeDsMethodOutput *ds_output_update2_i(const NeDynamicSystem *ds,
  PmAllocator *allocator);
static NeDsMethodOutput *ds_output_lock_r(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_lock_i(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_lock2_r(const NeDynamicSystem *ds,
  PmAllocator *allocator);
static NeDsMethodOutput *ds_output_lock2_i(const NeDynamicSystem *ds,
  PmAllocator *allocator);
static NeDsMethodOutput *ds_output_sfo(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_sfp(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_init_r(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_init_i(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_log(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_assert(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_passert(const NeDynamicSystem *ds,
  PmAllocator *allocator);
static NeDsMethodOutput *ds_output_iassert(const NeDynamicSystem *ds,
  PmAllocator *allocator);
static NeDsMethodOutput *ds_output_del_t(const NeDynamicSystem *ds, PmAllocator *
  allocator);
static NeDsMethodOutput *ds_output_del_v(const NeDynamicSystem *ds, PmAllocator *
  allocator);
static NeDsMethodOutput *ds_output_del_v0(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_del_tmax(const NeDynamicSystem *ds,
  PmAllocator *allocator);
static NeDsMethodOutput *ds_output_dxdelt_p(const NeDynamicSystem *ds,
  PmAllocator *allocator);
static NeDsMethodOutput *ds_output_dxdelt(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_dudelt_p(const NeDynamicSystem *ds,
  PmAllocator *allocator);
static NeDsMethodOutput *ds_output_dudelt(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_dtdelt_p(const NeDynamicSystem *ds,
  PmAllocator *allocator);
static NeDsMethodOutput *ds_output_dtdelt(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_obs_exp(const NeDynamicSystem *ds,
  PmAllocator *allocator);
static NeDsMethodOutput *ds_output_obs_act(const NeDynamicSystem *ds,
  PmAllocator *allocator);
static NeDsMethodOutput *ds_output_obs_all(const NeDynamicSystem *ds,
  PmAllocator *allocator);
static NeDsMethodOutput *ds_output_obs_il(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_dp_l(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_dp_i(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_dp_j(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_dp_r(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_qx(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_qu(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_qt(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_q1(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_qx_p(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_qu_p(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_qt_p(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_q1_p(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_var_tol(const NeDynamicSystem *ds,
  PmAllocator *allocator);
static NeDsMethodOutput *ds_output_eq_tol(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_lv(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_slv(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_nldv(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_sclv(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_imin(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_imax(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_dimin(const NeDynamicSystem *ds, PmAllocator *
  allocator);
static NeDsMethodOutput *ds_output_dimax(const NeDynamicSystem *ds, PmAllocator *
  allocator);
static void release_reference(NeDynamicSystem *ds);
static void get_reference(NeDynamicSystem *ds);
static NeDynamicSystem *diagnostics(NeDynamicSystem *ds, boolean_T);
static void expand(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
                   PmRealVector *out, boolean_T kp);
static void rtpmap(const NeDynamicSystem * ds, const PmIntVector* inl, const
                   PmIntVector* ini, const PmIntVector* inj, const PmRealVector*
                   inr, PmIntVector* outl, PmIntVector* outi, PmIntVector* outj,
                   PmRealVector* outr);
static NeEquationData s_equation_data[24] = { { "", 0U, 8,
    NE_EQUATION_DOMAIN_TIME, "ozysdriverandreceiver/Subsystem1/Psuedo-AD8132",
    1U, 0U, TRUE, 1.0, "1", }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "ozysdriverandreceiver/Subsystem1/Psuedo-AD8132", 1U, 1U, TRUE, 1.0, "1", },
  { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "ozysdriverandreceiver/Subsystem1/Psuedo-AD8132", 1U, 2U, TRUE, 1.0, "1", },
  { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "ozysdriverandreceiver/Subsystem1/Psuedo-AD8132", 8U, 3U, TRUE, 1.0, "1", },
  { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "ozysdriverandreceiver/Subsystem1/Psuedo-AD8132", 8U, 11U, TRUE, 1.0, "1", },
  { "", 0U, 8, NE_EQUATION_DOMAIN_TIME, "ozysdriverandreceiver/Subsystem1/0.1uF",
    1U, 19U, TRUE, 1.0, "1", }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "ozysdriverandreceiver/Subsystem2/Capacitor1", 1U, 20U, TRUE, 1.0, "1", }, {
    "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "ozysdriverandreceiver/Subsystem2/Capacitor2", 1U, 21U, TRUE, 1.0, "1", }, {
    "", 0U, 8, NE_EQUATION_DOMAIN_TIME, "ozysdriverandreceiver/Noise1", 1U, 22U,
    FALSE, 1.0, "1", }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "ozysdriverandreceiver/Noise2", 1U, 23U, FALSE, 1.0, "1", }, { "", 0U, 8,
    NE_EQUATION_DOMAIN_TIME, "ozysdriverandreceiver/Resistor1", 1U, 24U, TRUE,
    1.0, "1", }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "ozysdriverandreceiver/Resistor3", 1U, 25U, TRUE, 1.0, "1", }, { "", 0U, 8,
    NE_EQUATION_DOMAIN_TIME, "ozysdriverandreceiver/SG/Variable Resistor", 3U,
    26U, FALSE, 1.0, "1", }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "ozysdriverandreceiver/SG/Variable Resistor1", 3U, 29U, FALSE, 1.0, "1", },
    { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "ozysdriverandreceiver/SG/Variable Resistor2", 3U, 32U, FALSE, 1.0, "1", },
    { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "ozysdriverandreceiver/SG/Variable Resistor3", 3U, 35U, FALSE, 1.0, "1", },
    { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "ozysdriverandreceiver/Subsystem1/Psuedo-AD8132", 1U, 38U, TRUE, 1.0, "1", },
  { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "ozysdriverandreceiver/Subsystem1/Psuedo-AD8132", 1U, 39U, TRUE, 1.0, "1", },
  { "", 0U, 8, NE_EQUATION_DOMAIN_TIME, "ozysdriverandreceiver/Subsystem1/0.1uF",
    1U, 40U, TRUE, 1.0, "1", }, { "", 0U, 1, NE_EQUATION_DOMAIN_TIME,
    "ozysdriverandreceiver/Subsystem1", 3U, 41U, TRUE, 1.0, "1", }, { "", 0U, 1,
    NE_EQUATION_DOMAIN_TIME, "ozysdriverandreceiver/Subsystem2", 3U, 44U, TRUE,
    1.0, "1", }, { "", 0U, 1, NE_EQUATION_DOMAIN_TIME, "", 3U, 47U, TRUE, 1.0,
    "1", }, { "", 0U, 1, NE_EQUATION_DOMAIN_TIME, "", 3U, 50U, TRUE, 1.0, "1", },
  { "", 0U, 1, NE_EQUATION_DOMAIN_TIME, "", 3U, 53U, TRUE, 1.0, "1", } };

static NeCERData *s_cer_data = NULL;
static NeICRData *s_icr_data = NULL;
static NeVariableData s_variable_data[24] = { {
    "Subsystem1.Psuedo_AD8132.diff_op_amp_eqn.v_p", 0U, 0,
    "ozysdriverandreceiver/Subsystem1/Psuedo-AD8132", 1.0, "1", 0.0, TRUE, FALSE,
    { 1, "1x1" }, NE_INIT_MODE_MANDATORY, "Internal variable v_p", }, {
    "Subsystem1.Psuedo_AD8132.diff_op_amp_eqn.v_n", 0U, 0,
    "ozysdriverandreceiver/Subsystem1/Psuedo-AD8132", 1.0, "1", 0.0, TRUE, FALSE,
    { 1, "1x1" }, NE_INIT_MODE_MANDATORY, "Internal variable v_n", }, {
    "Subsystem2.Capacitor1.vc", 0U, 0,
    "ozysdriverandreceiver/Subsystem2/Capacitor1", 1.0, "1", 0.0, TRUE, FALSE, {
      1, "1x1" }, NE_INIT_MODE_MANDATORY, "Capacitor voltage", }, {
    "Subsystem1.Psuedo_AD8132.C1a.vc", 0U, 0,
    "ozysdriverandreceiver/Subsystem1/Psuedo-AD8132", 1.0, "1", 0.0, TRUE, FALSE,
    { 1, "1x1" }, NE_INIT_MODE_MANDATORY, "Capacitor voltage", }, {
    "Subsystem1.Psuedo_AD8132.C1b.vc", 0U, 0,
    "ozysdriverandreceiver/Subsystem1/Psuedo-AD8132", 1.0, "1", 0.0, TRUE, FALSE,
    { 1, "1x1" }, NE_INIT_MODE_MANDATORY, "Capacitor voltage", }, {
    "Subsystem1.Psuedo_AD8132.C2.vc", 0U, 0,
    "ozysdriverandreceiver/Subsystem1/Psuedo-AD8132", 1.0, "1", 0.0, TRUE, FALSE,
    { 1, "1x1" }, NE_INIT_MODE_MANDATORY, "Capacitor voltage", }, {
    "Subsystem1.x0_1uF.vc", 0U, 0, "ozysdriverandreceiver/Subsystem1/0.1uF", 1.0,
    "1", 0.0, TRUE, FALSE, { 1, "1x1" }, NE_INIT_MODE_MANDATORY,
    "Capacitor voltage", }, { "Subsystem2.Capacitor2.vc", 0U, 0,
    "ozysdriverandreceiver/Subsystem2/Capacitor2", 1.0, "1", 0.0, TRUE, FALSE, {
      1, "1x1" }, NE_INIT_MODE_MANDATORY, "Capacitor voltage", }, { "Noise1.n.v",
    0U, 1, "ozysdriverandreceiver/Noise1", 1.0, "1", 0.0, FALSE, FALSE, { 1,
      "1x1" }, NE_INIT_MODE_NONE, "Voltage", }, {
    "Subsystem1.Psuedo_AD8132.C1a.p.v", 0U, 1,
    "ozysdriverandreceiver/Subsystem1/Psuedo-AD8132", 1.0, "1", 0.0, FALSE,
    FALSE, { 1, "1x1" }, NE_INIT_MODE_NONE, "Voltage", }, { "Noise1.p.v", 0U, 1,
    "ozysdriverandreceiver/Noise1", 1.0, "1", 0.0, FALSE, FALSE, { 1, "1x1" },
    NE_INIT_MODE_NONE, "Voltage", }, { "Noise2.n.v", 0U, 1,
    "ozysdriverandreceiver/Noise2", 1.0, "1", 0.0, FALSE, FALSE, { 1, "1x1" },
    NE_INIT_MODE_NONE, "Voltage", }, { "Subsystem1.Psuedo_AD8132.C1b.n.v", 0U, 1,
    "ozysdriverandreceiver/Subsystem1/Psuedo-AD8132", 1.0, "1", 0.0, FALSE,
    FALSE, { 1, "1x1" }, NE_INIT_MODE_NONE, "Voltage", }, { "Noise2.p.v", 0U, 1,
    "ozysdriverandreceiver/Noise2", 1.0, "1", 0.0, FALSE, FALSE, { 1, "1x1" },
    NE_INIT_MODE_NONE, "Voltage", }, { "Resistor.n.v", 0U, 1,
    "ozysdriverandreceiver/Resistor", 1.0, "1", 0.0, FALSE, FALSE, { 1, "1x1" },
    NE_INIT_MODE_NONE, "Voltage", }, { "Resistor2.n.v", 0U, 1,
    "ozysdriverandreceiver/Resistor2", 1.0, "1", 0.0, FALSE, FALSE, { 1, "1x1" },
    NE_INIT_MODE_NONE, "Voltage", }, { "Resistor2.p.v", 0U, 1,
    "ozysdriverandreceiver/Resistor2", 1.0, "1", 0.0, FALSE, FALSE, { 1, "1x1" },
    NE_INIT_MODE_NONE, "Voltage", }, { "SG.Current_Source.n.v", 0U, 1,
    "ozysdriverandreceiver/SG/Current Source", 1.0, "1", 0.0, FALSE, FALSE, { 1,
      "1x1" }, NE_INIT_MODE_NONE, "Voltage", }, { "SG.V_SGOut0.v", 0U, 1,
    "ozysdriverandreceiver/SG", 1.0, "1", 0.0, FALSE, FALSE, { 1, "1x1" },
    NE_INIT_MODE_NONE, "Voltage", }, { "SG.V_SGOut1.v", 0U, 1,
    "ozysdriverandreceiver/SG", 1.0, "1", 0.0, FALSE, FALSE, { 1, "1x1" },
    NE_INIT_MODE_NONE, "Voltage", }, { "SG.Variable_Resistor2.i", 0U, 0,
    "ozysdriverandreceiver/SG/Variable Resistor2", 1.0, "1", 0.0, FALSE, FALSE,
      { 1, "1x1" }, NE_INIT_MODE_NONE, "Current", }, { "Subsystem1.x0_1uF.i", 0U,
    0, "ozysdriverandreceiver/Subsystem1/0.1uF", 1.0, "1", 0.0, FALSE, FALSE, {
      1, "1x1" }, NE_INIT_MODE_NONE, "Current", }, {
    "Subsystem1.Psuedo_AD8132.C1a.i", 0U, 0,
    "ozysdriverandreceiver/Subsystem1/Psuedo-AD8132", 1.0, "1", 0.0, FALSE,
    FALSE, { 1, "1x1" }, NE_INIT_MODE_NONE, "Current", }, {
    "Subsystem2.Capacitor2.p.v", 0U, 1,
    "ozysdriverandreceiver/Subsystem2/Capacitor2", 1.0, "1", 0.0, FALSE, FALSE,
      { 1, "1x1" }, NE_INIT_MODE_NONE, "Voltage", } };

static NeVariableData *s_discrete_data = NULL;
static NeObservableData s_observable_data[304] = { { "Electrical_Reference1.V.v",
    "ozysdriverandreceiver/Electrical Reference1", { 1, "1x1" }, "V", 1.0, "V",
    NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, {
    "Electrical_Reference2.V.v", "ozysdriverandreceiver/Electrical Reference2",
      { 1, "1x1" }, "V", 1.0, "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE,
    TRUE, FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, {
    "Electrical_Reference3.V.v", "ozysdriverandreceiver/Electrical Reference3",
      { 1, "1x1" }, "V", 1.0, "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE,
    TRUE, FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, {
    "Electrical_Reference4.V.v", "ozysdriverandreceiver/Electrical Reference4",
      { 1, "1x1" }, "V", 1.0, "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE,
    TRUE, FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, { "Noise1.i",
    "ozysdriverandreceiver/Noise1", { 1, "1x1" }, "A", 1.0, "A",
    NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Current (positive in)", }, {
    "Noise1.n.v", "ozysdriverandreceiver/Noise1", { 1, "1x1" }, "V", 1.0, "V",
    NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, { "Noise1.p.v",
    "ozysdriverandreceiver/Noise1", { 1, "1x1" }, "V", 1.0, "V",
    NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, { "Noise1.random_source.Y",
    "ozysdriverandreceiver/Noise1", { 1, "1x1" }, "1", 1.0, "1",
    NE_NOMINAL_SOURCE_DERIVED, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Y", }, { "Noise1.random_source.c.y",
    "ozysdriverandreceiver/Noise1", { 1, "1x1" }, "1", 1.0, "1",
    NE_NOMINAL_SOURCE_DERIVED, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "y", }, { "Noise1.v",
    "ozysdriverandreceiver/Noise1", { 1, "1x1" }, "V", 1.0, "V",
    NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, { "Noise2.i",
    "ozysdriverandreceiver/Noise2", { 1, "1x1" }, "A", 1.0, "A",
    NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Current (positive in)", }, {
    "Noise2.n.v", "ozysdriverandreceiver/Noise2", { 1, "1x1" }, "V", 1.0, "V",
    NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, { "Noise2.p.v",
    "ozysdriverandreceiver/Noise2", { 1, "1x1" }, "V", 1.0, "V",
    NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, { "Noise2.random_source.Y",
    "ozysdriverandreceiver/Noise2", { 1, "1x1" }, "1", 1.0, "1",
    NE_NOMINAL_SOURCE_DERIVED, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Y", }, { "Noise2.random_source.c.y",
    "ozysdriverandreceiver/Noise2", { 1, "1x1" }, "1", 1.0, "1",
    NE_NOMINAL_SOURCE_DERIVED, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "y", }, { "Noise2.v",
    "ozysdriverandreceiver/Noise2", { 1, "1x1" }, "V", 1.0, "V",
    NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, { "Resistor.i",
    "ozysdriverandreceiver/Resistor", { 1, "1x1" }, "A", 1.0, "A",
    NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Current", }, { "Resistor.n.v",
    "ozysdriverandreceiver/Resistor", { 1, "1x1" }, "V", 1.0, "V",
    NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, { "Resistor.p.v",
    "ozysdriverandreceiver/Resistor", { 1, "1x1" }, "V", 1.0, "V",
    NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, { "Resistor.v",
    "ozysdriverandreceiver/Resistor", { 1, "1x1" }, "V", 1.0, "V",
    NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, {
    "Resistor.power_dissipated", "ozysdriverandreceiver/Resistor", { 1, "1x1" },
    "A^2*Ohm", 1.0, "A^2*Ohm", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE,
    FALSE, NE_FREQTIME_TYPE_TIME, TRUE, FALSE, "Dissipated power", }, {
    "Resistor1.i", "ozysdriverandreceiver/Resistor1", { 1, "1x1" }, "A", 1.0,
    "A", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Current", }, { "Resistor1.n.v",
    "ozysdriverandreceiver/Resistor1", { 1, "1x1" }, "V", 1.0, "V",
    NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, { "Resistor1.p.v",
    "ozysdriverandreceiver/Resistor1", { 1, "1x1" }, "V", 1.0, "V",
    NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, { "Resistor1.v",
    "ozysdriverandreceiver/Resistor1", { 1, "1x1" }, "V", 1.0, "V",
    NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, {
    "Resistor1.power_dissipated", "ozysdriverandreceiver/Resistor1", { 1, "1x1"
    }, "A^2*Ohm", 1.0, "A^2*Ohm", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE,
    FALSE, FALSE, NE_FREQTIME_TYPE_TIME, TRUE, FALSE, "Dissipated power", }, {
    "Resistor2.i", "ozysdriverandreceiver/Resistor2", { 1, "1x1" }, "A", 1.0,
    "A", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Current", }, { "Resistor2.n.v",
    "ozysdriverandreceiver/Resistor2", { 1, "1x1" }, "V", 1.0, "V",
    NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, { "Resistor2.p.v",
    "ozysdriverandreceiver/Resistor2", { 1, "1x1" }, "V", 1.0, "V",
    NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, { "Resistor2.v",
    "ozysdriverandreceiver/Resistor2", { 1, "1x1" }, "V", 1.0, "V",
    NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, {
    "Resistor2.power_dissipated", "ozysdriverandreceiver/Resistor2", { 1, "1x1"
    }, "A^2*Ohm", 1.0, "A^2*Ohm", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE,
    FALSE, FALSE, NE_FREQTIME_TYPE_TIME, TRUE, FALSE, "Dissipated power", }, {
    "Resistor3.i", "ozysdriverandreceiver/Resistor3", { 1, "1x1" }, "A", 1.0,
    "A", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Current", }, { "Resistor3.n.v",
    "ozysdriverandreceiver/Resistor3", { 1, "1x1" }, "V", 1.0, "V",
    NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, { "Resistor3.p.v",
    "ozysdriverandreceiver/Resistor3", { 1, "1x1" }, "V", 1.0, "V",
    NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, { "Resistor3.v",
    "ozysdriverandreceiver/Resistor3", { 1, "1x1" }, "V", 1.0, "V",
    NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, {
    "Resistor3.power_dissipated", "ozysdriverandreceiver/Resistor3", { 1, "1x1"
    }, "A^2*Ohm", 1.0, "A^2*Ohm", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE,
    FALSE, FALSE, NE_FREQTIME_TYPE_TIME, TRUE, FALSE, "Dissipated power", }, {
    "SG.Current_Source.i", "ozysdriverandreceiver/SG/Current Source", { 1, "1x1"
    }, "A", 1.0, "A", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Current (positive in)", }, {
    "SG.Current_Source.n.v", "ozysdriverandreceiver/SG/Current Source", { 1,
      "1x1" }, "V", 1.0, "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE,
    FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, {
    "SG.Current_Source.p.v", "ozysdriverandreceiver/SG/Current Source", { 1,
      "1x1" }, "V", 1.0, "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, TRUE,
    FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, {
    "SG.Current_Source.v", "ozysdriverandreceiver/SG/Current Source", { 1, "1x1"
    }, "V", 1.0, "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, { "SG.DC_Voltage_Source.i",
    "ozysdriverandreceiver/SG/DC Voltage Source", { 1, "1x1" }, "A", 1.0, "A",
    NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Current", }, {
    "SG.DC_Voltage_Source.n.v", "ozysdriverandreceiver/SG/DC Voltage Source", {
      1, "1x1" }, "V", 1.0, "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE,
    TRUE, FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, {
    "SG.DC_Voltage_Source.p.v", "ozysdriverandreceiver/SG/DC Voltage Source", {
      1, "1x1" }, "V", 1.0, "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE,
    TRUE, FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, {
    "SG.Electrical_Reference1.V.v",
    "ozysdriverandreceiver/SG/Electrical Reference1", { 1, "1x1" }, "V", 1.0,
    "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, {
    "SG.Electrical_Reference2.V.v",
    "ozysdriverandreceiver/SG/Electrical Reference2", { 1, "1x1" }, "V", 1.0,
    "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, {
    "SG.Electrical_Reference3.V.v",
    "ozysdriverandreceiver/SG/Electrical Reference3", { 1, "1x1" }, "V", 1.0,
    "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, { "SG.Pull_Up.i",
    "ozysdriverandreceiver/SG/Pull Up", { 1, "1x1" }, "A", 1.0, "A",
    NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Current", }, { "SG.Pull_Up.n.v",
    "ozysdriverandreceiver/SG/Pull Up", { 1, "1x1" }, "V", 1.0, "V",
    NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, { "SG.Pull_Up.p.v",
    "ozysdriverandreceiver/SG/Pull Up", { 1, "1x1" }, "V", 1.0, "V",
    NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, { "SG.Pull_Up.v",
    "ozysdriverandreceiver/SG/Pull Up", { 1, "1x1" }, "V", 1.0, "V",
    NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, {
    "SG.Pull_Up.power_dissipated", "ozysdriverandreceiver/SG/Pull Up", { 1,
      "1x1" }, "A^2*Ohm", 1.0, "A^2*Ohm", NE_NOMINAL_SOURCE_NONE,
    NE_INIT_MODE_NONE, FALSE, FALSE, NE_FREQTIME_TYPE_TIME, TRUE, FALSE,
    "Dissipated power", }, { "SG.Simulink_PS_Converter1_output0",
    "ozysdriverandreceiver/SG/Simulink-PS\nConverter1", { 1, "1x1" }, "1", 1.0,
    "1", NE_NOMINAL_SOURCE_FIXED, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Simulink_PS_Converter1_output0", }, {
    "SG.Simulink_PS_Converter2_output0",
    "ozysdriverandreceiver/SG/Simulink-PS\nConverter2", { 1, "1x1" }, "1", 1.0,
    "1", NE_NOMINAL_SOURCE_FIXED, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Simulink_PS_Converter2_output0", }, {
    "SG.Simulink_PS_Converter3_output0",
    "ozysdriverandreceiver/SG/Simulink-PS\nConverter3", { 1, "1x1" }, "1", 1.0,
    "1", NE_NOMINAL_SOURCE_FIXED, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Simulink_PS_Converter3_output0", }, {
    "SG.Simulink_PS_Converter_output0",
    "ozysdriverandreceiver/SG/Simulink-PS\nConverter", { 1, "1x1" }, "1", 1.0,
    "1", NE_NOMINAL_SOURCE_FIXED, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Simulink_PS_Converter_output0", }, {
    "SG.V_SGOut0.v", "ozysdriverandreceiver/SG", { 1, "1x1" }, "V", 1.0, "V",
    NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Voltage", }, { "SG.V_SGOut1.v",
    "ozysdriverandreceiver/SG", { 1, "1x1" }, "V", 1.0, "V",
    NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Voltage", }, {
    "SG.Variable_Resistor.H.T", "ozysdriverandreceiver/SG/Variable Resistor", {
      1, "1x1" }, "K", 1.0, "K", NE_NOMINAL_SOURCE_DERIVED, NE_INIT_MODE_NONE,
    TRUE, FALSE, NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Temperature", }, {
    "SG.Variable_Resistor.R", "ozysdriverandreceiver/SG/Variable Resistor", { 1,
      "1x1" }, "Ohm", 1.0, "kg*m^2/(C^2*s)", NE_NOMINAL_SOURCE_DERIVED,
    NE_INIT_MODE_NONE, FALSE, FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "R", },
    { "SG.Variable_Resistor.T", "ozysdriverandreceiver/SG/Variable Resistor", {
      1, "1x1" }, "K", 1.0, "K", NE_NOMINAL_SOURCE_DERIVED, NE_INIT_MODE_NONE,
    TRUE, FALSE, NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Temperature", }, {
    "SG.Variable_Resistor.i", "ozysdriverandreceiver/SG/Variable Resistor", { 1,
      "1x1" }, "A", 1.0, "A", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE,
    FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Current", }, {
    "SG.Variable_Resistor.n.v", "ozysdriverandreceiver/SG/Variable Resistor", {
      1, "1x1" }, "V", 1.0, "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE,
    FALSE, FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, {
    "SG.Variable_Resistor.p.v", "ozysdriverandreceiver/SG/Variable Resistor", {
      1, "1x1" }, "V", 1.0, "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE,
    FALSE, FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, {
    "SG.Variable_Resistor.v", "ozysdriverandreceiver/SG/Variable Resistor", { 1,
      "1x1" }, "V", 1.0, "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE,
    FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, {
    "SG.Variable_Resistor.power_dissipated",
    "ozysdriverandreceiver/SG/Variable Resistor", { 1, "1x1" }, "A*V", 1.0,
    "A*V", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, FALSE, "Dissipated power", }, {
    "SG.Variable_Resistor1.H.T", "ozysdriverandreceiver/SG/Variable Resistor1",
      { 1, "1x1" }, "K", 1.0, "K", NE_NOMINAL_SOURCE_DERIVED, NE_INIT_MODE_NONE,
    TRUE, FALSE, NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Temperature", }, {
    "SG.Variable_Resistor1.R", "ozysdriverandreceiver/SG/Variable Resistor1", {
      1, "1x1" }, "Ohm", 1.0, "kg*m^2/(C^2*s)", NE_NOMINAL_SOURCE_DERIVED,
    NE_INIT_MODE_NONE, FALSE, FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "R", },
    { "SG.Variable_Resistor1.T", "ozysdriverandreceiver/SG/Variable Resistor1",
      { 1, "1x1" }, "K", 1.0, "K", NE_NOMINAL_SOURCE_DERIVED, NE_INIT_MODE_NONE,
    TRUE, FALSE, NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Temperature", }, {
    "SG.Variable_Resistor1.i", "ozysdriverandreceiver/SG/Variable Resistor1", {
      1, "1x1" }, "A", 1.0, "A", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE,
    FALSE, FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Current", }, {
    "SG.Variable_Resistor1.n.v", "ozysdriverandreceiver/SG/Variable Resistor1",
      { 1, "1x1" }, "V", 1.0, "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE,
    FALSE, FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, {
    "SG.Variable_Resistor1.p.v", "ozysdriverandreceiver/SG/Variable Resistor1",
      { 1, "1x1" }, "V", 1.0, "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE,
    TRUE, FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, {
    "SG.Variable_Resistor1.v", "ozysdriverandreceiver/SG/Variable Resistor1", {
      1, "1x1" }, "V", 1.0, "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE,
    FALSE, FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, {
    "SG.Variable_Resistor1.power_dissipated",
    "ozysdriverandreceiver/SG/Variable Resistor1", { 1, "1x1" }, "A*V", 1.0,
    "A*V", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, FALSE, "Dissipated power", }, {
    "SG.Variable_Resistor2.H.T", "ozysdriverandreceiver/SG/Variable Resistor2",
      { 1, "1x1" }, "K", 1.0, "K", NE_NOMINAL_SOURCE_DERIVED, NE_INIT_MODE_NONE,
    TRUE, FALSE, NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Temperature", }, {
    "SG.Variable_Resistor2.R", "ozysdriverandreceiver/SG/Variable Resistor2", {
      1, "1x1" }, "Ohm", 1.0, "kg*m^2/(C^2*s)", NE_NOMINAL_SOURCE_DERIVED,
    NE_INIT_MODE_NONE, FALSE, FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "R", },
    { "SG.Variable_Resistor2.T", "ozysdriverandreceiver/SG/Variable Resistor2",
      { 1, "1x1" }, "K", 1.0, "K", NE_NOMINAL_SOURCE_DERIVED, NE_INIT_MODE_NONE,
    TRUE, FALSE, NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Temperature", }, {
    "SG.Variable_Resistor2.i", "ozysdriverandreceiver/SG/Variable Resistor2", {
      1, "1x1" }, "A", 1.0, "A", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE,
    FALSE, FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Current", }, {
    "SG.Variable_Resistor2.n.v", "ozysdriverandreceiver/SG/Variable Resistor2",
      { 1, "1x1" }, "V", 1.0, "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE,
    FALSE, FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, {
    "SG.Variable_Resistor2.p.v", "ozysdriverandreceiver/SG/Variable Resistor2",
      { 1, "1x1" }, "V", 1.0, "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE,
    FALSE, FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, {
    "SG.Variable_Resistor2.v", "ozysdriverandreceiver/SG/Variable Resistor2", {
      1, "1x1" }, "V", 1.0, "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE,
    FALSE, FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, {
    "SG.Variable_Resistor2.power_dissipated",
    "ozysdriverandreceiver/SG/Variable Resistor2", { 1, "1x1" }, "A*V", 1.0,
    "A*V", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, FALSE, "Dissipated power", }, {
    "SG.Variable_Resistor3.H.T", "ozysdriverandreceiver/SG/Variable Resistor3",
      { 1, "1x1" }, "K", 1.0, "K", NE_NOMINAL_SOURCE_DERIVED, NE_INIT_MODE_NONE,
    TRUE, FALSE, NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Temperature", }, {
    "SG.Variable_Resistor3.R", "ozysdriverandreceiver/SG/Variable Resistor3", {
      1, "1x1" }, "Ohm", 1.0, "kg*m^2/(C^2*s)", NE_NOMINAL_SOURCE_DERIVED,
    NE_INIT_MODE_NONE, FALSE, FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "R", },
    { "SG.Variable_Resistor3.T", "ozysdriverandreceiver/SG/Variable Resistor3",
      { 1, "1x1" }, "K", 1.0, "K", NE_NOMINAL_SOURCE_DERIVED, NE_INIT_MODE_NONE,
    TRUE, FALSE, NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Temperature", }, {
    "SG.Variable_Resistor3.i", "ozysdriverandreceiver/SG/Variable Resistor3", {
      1, "1x1" }, "A", 1.0, "A", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE,
    FALSE, FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Current", }, {
    "SG.Variable_Resistor3.n.v", "ozysdriverandreceiver/SG/Variable Resistor3",
      { 1, "1x1" }, "V", 1.0, "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE,
    TRUE, FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, {
    "SG.Variable_Resistor3.p.v", "ozysdriverandreceiver/SG/Variable Resistor3",
      { 1, "1x1" }, "V", 1.0, "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE,
    FALSE, FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, {
    "SG.Variable_Resistor3.v", "ozysdriverandreceiver/SG/Variable Resistor3", {
      1, "1x1" }, "V", 1.0, "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE,
    FALSE, FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, {
    "SG.Variable_Resistor3.power_dissipated",
    "ozysdriverandreceiver/SG/Variable Resistor3", { 1, "1x1" }, "A*V", 1.0,
    "A*V", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, FALSE, "Dissipated power", }, {
    "Subsystem1.DC_Voltage_Source.i",
    "ozysdriverandreceiver/Subsystem1/DC Voltage Source", { 1, "1x1" }, "A", 1.0,
    "A", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Current", }, {
    "Subsystem1.DC_Voltage_Source.n.v",
    "ozysdriverandreceiver/Subsystem1/DC Voltage Source", { 1, "1x1" }, "V", 1.0,
    "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, {
    "Subsystem1.DC_Voltage_Source.p.v",
    "ozysdriverandreceiver/Subsystem1/DC Voltage Source", { 1, "1x1" }, "V", 1.0,
    "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, { "Subsystem1.Diff0.v",
    "ozysdriverandreceiver/Subsystem1", { 1, "1x1" }, "V", 1.0, "V",
    NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Voltage", }, { "Subsystem1.Diff1.v",
    "ozysdriverandreceiver/Subsystem1", { 1, "1x1" }, "V", 1.0, "V",
    NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Voltage", }, {
    "Subsystem1.DriverVin0.v", "ozysdriverandreceiver/Subsystem1", { 1, "1x1" },
    "V", 1.0, "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Voltage", }, {
    "Subsystem1.DriverVin1.v", "ozysdriverandreceiver/Subsystem1", { 1, "1x1" },
    "V", 1.0, "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Voltage", }, {
    "Subsystem1.Electrical_Reference.V.v",
    "ozysdriverandreceiver/Subsystem1/Electrical Reference", { 1, "1x1" }, "V",
    1.0, "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, {
    "Subsystem1.Electrical_Reference1.V.v",
    "ozysdriverandreceiver/Subsystem1/Electrical Reference1", { 1, "1x1" }, "V",
    1.0, "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, {
    "Subsystem1.Psuedo_AD8132.C1a.i",
    "ozysdriverandreceiver/Subsystem1/Psuedo-AD8132", { 1, "1x1" }, "A", 1.0,
    "A", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Current", }, {
    "Subsystem1.Psuedo_AD8132.C1a.n.v",
    "ozysdriverandreceiver/Subsystem1/Psuedo-AD8132", { 1, "1x1" }, "V", 1.0,
    "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, {
    "Subsystem1.Psuedo_AD8132.C1a.p.v",
    "ozysdriverandreceiver/Subsystem1/Psuedo-AD8132", { 1, "1x1" }, "V", 1.0,
    "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, {
    "Subsystem1.Psuedo_AD8132.C1a.v",
    "ozysdriverandreceiver/Subsystem1/Psuedo-AD8132", { 1, "1x1" }, "V", 1.0,
    "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, {
    "Subsystem1.Psuedo_AD8132.C1a.vc",
    "ozysdriverandreceiver/Subsystem1/Psuedo-AD8132", { 1, "1x1" }, "V", 1.0,
    "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_MANDATORY, FALSE, TRUE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Capacitor voltage", }, {
    "Subsystem1.Psuedo_AD8132.C1a.power_dissipated",
    "ozysdriverandreceiver/Subsystem1/Psuedo-AD8132", { 1, "1x1" }, "kW", 1.0,
    "kW", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, FALSE, "Dissipated power", }, {
    "Subsystem1.Psuedo_AD8132.C1b.i",
    "ozysdriverandreceiver/Subsystem1/Psuedo-AD8132", { 1, "1x1" }, "A", 1.0,
    "A", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Current", }, {
    "Subsystem1.Psuedo_AD8132.C1b.n.v",
    "ozysdriverandreceiver/Subsystem1/Psuedo-AD8132", { 1, "1x1" }, "V", 1.0,
    "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, {
    "Subsystem1.Psuedo_AD8132.C1b.p.v",
    "ozysdriverandreceiver/Subsystem1/Psuedo-AD8132", { 1, "1x1" }, "V", 1.0,
    "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, {
    "Subsystem1.Psuedo_AD8132.C1b.v",
    "ozysdriverandreceiver/Subsystem1/Psuedo-AD8132", { 1, "1x1" }, "V", 1.0,
    "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, {
    "Subsystem1.Psuedo_AD8132.C1b.vc",
    "ozysdriverandreceiver/Subsystem1/Psuedo-AD8132", { 1, "1x1" }, "V", 1.0,
    "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_MANDATORY, FALSE, TRUE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Capacitor voltage", }, {
    "Subsystem1.Psuedo_AD8132.C1b.power_dissipated",
    "ozysdriverandreceiver/Subsystem1/Psuedo-AD8132", { 1, "1x1" }, "kW", 1.0,
    "kW", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, FALSE, "Dissipated power", }, {
    "Subsystem1.Psuedo_AD8132.C2.i",
    "ozysdriverandreceiver/Subsystem1/Psuedo-AD8132", { 1, "1x1" }, "A", 1.0,
    "A", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Current", }, {
    "Subsystem1.Psuedo_AD8132.C2.n.v",
    "ozysdriverandreceiver/Subsystem1/Psuedo-AD8132", { 1, "1x1" }, "V", 1.0,
    "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, {
    "Subsystem1.Psuedo_AD8132.C2.p.v",
    "ozysdriverandreceiver/Subsystem1/Psuedo-AD8132", { 1, "1x1" }, "V", 1.0,
    "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, {
    "Subsystem1.Psuedo_AD8132.C2.v",
    "ozysdriverandreceiver/Subsystem1/Psuedo-AD8132", { 1, "1x1" }, "V", 1.0,
    "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, {
    "Subsystem1.Psuedo_AD8132.C2.vc",
    "ozysdriverandreceiver/Subsystem1/Psuedo-AD8132", { 1, "1x1" }, "V", 1.0,
    "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_MANDATORY, FALSE, TRUE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Capacitor voltage", }, {
    "Subsystem1.Psuedo_AD8132.C2.power_dissipated",
    "ozysdriverandreceiver/Subsystem1/Psuedo-AD8132", { 1, "1x1" }, "kW", 1.0,
    "kW", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, FALSE, "Dissipated power", }, {
    "Subsystem1.Psuedo_AD8132.R1a.i",
    "ozysdriverandreceiver/Subsystem1/Psuedo-AD8132", { 1, "1x1" }, "A", 1.0,
    "A", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Current", }, {
    "Subsystem1.Psuedo_AD8132.R1a.n.v",
    "ozysdriverandreceiver/Subsystem1/Psuedo-AD8132", { 1, "1x1" }, "V", 1.0,
    "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, {
    "Subsystem1.Psuedo_AD8132.R1a.p.v",
    "ozysdriverandreceiver/Subsystem1/Psuedo-AD8132", { 1, "1x1" }, "V", 1.0,
    "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, {
    "Subsystem1.Psuedo_AD8132.R1a.v",
    "ozysdriverandreceiver/Subsystem1/Psuedo-AD8132", { 1, "1x1" }, "V", 1.0,
    "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, {
    "Subsystem1.Psuedo_AD8132.R1a.power_dissipated",
    "ozysdriverandreceiver/Subsystem1/Psuedo-AD8132", { 1, "1x1" }, "A^2*Ohm",
    1.0, "A^2*Ohm", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, FALSE, "Dissipated power", }, {
    "Subsystem1.Psuedo_AD8132.R1b.i",
    "ozysdriverandreceiver/Subsystem1/Psuedo-AD8132", { 1, "1x1" }, "A", 1.0,
    "A", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Current", }, {
    "Subsystem1.Psuedo_AD8132.R1b.n.v",
    "ozysdriverandreceiver/Subsystem1/Psuedo-AD8132", { 1, "1x1" }, "V", 1.0,
    "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, {
    "Subsystem1.Psuedo_AD8132.R1b.p.v",
    "ozysdriverandreceiver/Subsystem1/Psuedo-AD8132", { 1, "1x1" }, "V", 1.0,
    "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, {
    "Subsystem1.Psuedo_AD8132.R1b.v",
    "ozysdriverandreceiver/Subsystem1/Psuedo-AD8132", { 1, "1x1" }, "V", 1.0,
    "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, {
    "Subsystem1.Psuedo_AD8132.R1b.power_dissipated",
    "ozysdriverandreceiver/Subsystem1/Psuedo-AD8132", { 1, "1x1" }, "A^2*Ohm",
    1.0, "A^2*Ohm", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, FALSE, "Dissipated power", }, {
    "Subsystem1.Psuedo_AD8132.R2.i",
    "ozysdriverandreceiver/Subsystem1/Psuedo-AD8132", { 1, "1x1" }, "A", 1.0,
    "A", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Current", }, {
    "Subsystem1.Psuedo_AD8132.R2.n.v",
    "ozysdriverandreceiver/Subsystem1/Psuedo-AD8132", { 1, "1x1" }, "V", 1.0,
    "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, {
    "Subsystem1.Psuedo_AD8132.R2.p.v",
    "ozysdriverandreceiver/Subsystem1/Psuedo-AD8132", { 1, "1x1" }, "V", 1.0,
    "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, {
    "Subsystem1.Psuedo_AD8132.R2.v",
    "ozysdriverandreceiver/Subsystem1/Psuedo-AD8132", { 1, "1x1" }, "V", 1.0,
    "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, {
    "Subsystem1.Psuedo_AD8132.R2.power_dissipated",
    "ozysdriverandreceiver/Subsystem1/Psuedo-AD8132", { 1, "1x1" }, "A^2*Ohm",
    1.0, "A^2*Ohm", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, FALSE, "Dissipated power", }, {
    "Subsystem1.Psuedo_AD8132.R3a.i",
    "ozysdriverandreceiver/Subsystem1/Psuedo-AD8132", { 1, "1x1" }, "A", 1.0,
    "A", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Current", }, {
    "Subsystem1.Psuedo_AD8132.R3a.n.v",
    "ozysdriverandreceiver/Subsystem1/Psuedo-AD8132", { 1, "1x1" }, "V", 1.0,
    "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, {
    "Subsystem1.Psuedo_AD8132.R3a.p.v",
    "ozysdriverandreceiver/Subsystem1/Psuedo-AD8132", { 1, "1x1" }, "V", 1.0,
    "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, {
    "Subsystem1.Psuedo_AD8132.R3a.v",
    "ozysdriverandreceiver/Subsystem1/Psuedo-AD8132", { 1, "1x1" }, "V", 1.0,
    "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, {
    "Subsystem1.Psuedo_AD8132.R3a.power_dissipated",
    "ozysdriverandreceiver/Subsystem1/Psuedo-AD8132", { 1, "1x1" }, "A^2*Ohm",
    1.0, "A^2*Ohm", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, FALSE, "Dissipated power", }, {
    "Subsystem1.Psuedo_AD8132.R3b.i",
    "ozysdriverandreceiver/Subsystem1/Psuedo-AD8132", { 1, "1x1" }, "A", 1.0,
    "A", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Current", }, {
    "Subsystem1.Psuedo_AD8132.R3b.n.v",
    "ozysdriverandreceiver/Subsystem1/Psuedo-AD8132", { 1, "1x1" }, "V", 1.0,
    "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, {
    "Subsystem1.Psuedo_AD8132.R3b.p.v",
    "ozysdriverandreceiver/Subsystem1/Psuedo-AD8132", { 1, "1x1" }, "V", 1.0,
    "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, {
    "Subsystem1.Psuedo_AD8132.R3b.v",
    "ozysdriverandreceiver/Subsystem1/Psuedo-AD8132", { 1, "1x1" }, "V", 1.0,
    "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, {
    "Subsystem1.Psuedo_AD8132.R3b.power_dissipated",
    "ozysdriverandreceiver/Subsystem1/Psuedo-AD8132", { 1, "1x1" }, "A^2*Ohm",
    1.0, "A^2*Ohm", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, FALSE, "Dissipated power", }, {
    "Subsystem1.Psuedo_AD8132.cm.v",
    "ozysdriverandreceiver/Subsystem1/Psuedo-AD8132", { 1, "1x1" }, "V", 1.0,
    "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, {
    "Subsystem1.Psuedo_AD8132.diff_op_amp_eqn.cm.v",
    "ozysdriverandreceiver/Subsystem1/Psuedo-AD8132", { 1, "1x1" }, "V", 1.0,
    "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, {
    "Subsystem1.Psuedo_AD8132.diff_op_amp_eqn.i_cm",
    "ozysdriverandreceiver/Subsystem1/Psuedo-AD8132", { 1, "1x1" }, "A", 1.0,
    "A", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Common mode current", }, {
    "Subsystem1.Psuedo_AD8132.diff_op_amp_eqn.i_n",
    "ozysdriverandreceiver/Subsystem1/Psuedo-AD8132", { 1, "1x1" }, "A", 1.0,
    "A", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Current (n -> *)", }, {
    "Subsystem1.Psuedo_AD8132.diff_op_amp_eqn.i_out_n",
    "ozysdriverandreceiver/Subsystem1/Psuedo-AD8132", { 1, "1x1" }, "A", 1.0,
    "A", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Current (out_n -> *)", }, {
    "Subsystem1.Psuedo_AD8132.diff_op_amp_eqn.i_out_p",
    "ozysdriverandreceiver/Subsystem1/Psuedo-AD8132", { 1, "1x1" }, "A", 1.0,
    "A", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Current (out_p -> *)", }, {
    "Subsystem1.Psuedo_AD8132.diff_op_amp_eqn.i_p",
    "ozysdriverandreceiver/Subsystem1/Psuedo-AD8132", { 1, "1x1" }, "A", 1.0,
    "A", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Current (p -> *)", }, {
    "Subsystem1.Psuedo_AD8132.diff_op_amp_eqn.n.v",
    "ozysdriverandreceiver/Subsystem1/Psuedo-AD8132", { 1, "1x1" }, "V", 1.0,
    "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, {
    "Subsystem1.Psuedo_AD8132.diff_op_amp_eqn.out_n.v",
    "ozysdriverandreceiver/Subsystem1/Psuedo-AD8132", { 1, "1x1" }, "V", 1.0,
    "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, {
    "Subsystem1.Psuedo_AD8132.diff_op_amp_eqn.out_p.v",
    "ozysdriverandreceiver/Subsystem1/Psuedo-AD8132", { 1, "1x1" }, "V", 1.0,
    "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, {
    "Subsystem1.Psuedo_AD8132.diff_op_amp_eqn.p.v",
    "ozysdriverandreceiver/Subsystem1/Psuedo-AD8132", { 1, "1x1" }, "V", 1.0,
    "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, {
    "Subsystem1.Psuedo_AD8132.diff_op_amp_eqn.v_n",
    "ozysdriverandreceiver/Subsystem1/Psuedo-AD8132", { 1, "1x1" }, "V", 1.0,
    "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_MANDATORY, FALSE, TRUE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Internal variable v_n", }, {
    "Subsystem1.Psuedo_AD8132.diff_op_amp_eqn.v_p",
    "ozysdriverandreceiver/Subsystem1/Psuedo-AD8132", { 1, "1x1" }, "V", 1.0,
    "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_MANDATORY, FALSE, TRUE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Internal variable v_p", }, {
    "Subsystem1.Psuedo_AD8132.n.v",
    "ozysdriverandreceiver/Subsystem1/Psuedo-AD8132", { 1, "1x1" }, "V", 1.0,
    "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, {
    "Subsystem1.Psuedo_AD8132.negative_rail.i",
    "ozysdriverandreceiver/Subsystem1/Psuedo-AD8132", { 1, "1x1" }, "A", 1.0,
    "A", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Current", }, {
    "Subsystem1.Psuedo_AD8132.negative_rail.n.v",
    "ozysdriverandreceiver/Subsystem1/Psuedo-AD8132", { 1, "1x1" }, "V", 1.0,
    "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, {
    "Subsystem1.Psuedo_AD8132.out_n.v",
    "ozysdriverandreceiver/Subsystem1/Psuedo-AD8132", { 1, "1x1" }, "V", 1.0,
    "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, {
    "Subsystem1.Psuedo_AD8132.out_p.v",
    "ozysdriverandreceiver/Subsystem1/Psuedo-AD8132", { 1, "1x1" }, "V", 1.0,
    "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, {
    "Subsystem1.Psuedo_AD8132.p.v",
    "ozysdriverandreceiver/Subsystem1/Psuedo-AD8132", { 1, "1x1" }, "V", 1.0,
    "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, {
    "Subsystem1.Psuedo_AD8132.positive_rail.i",
    "ozysdriverandreceiver/Subsystem1/Psuedo-AD8132", { 1, "1x1" }, "A", 1.0,
    "A", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Current", }, {
    "Subsystem1.Psuedo_AD8132.positive_rail.p.v",
    "ozysdriverandreceiver/Subsystem1/Psuedo-AD8132", { 1, "1x1" }, "V", 1.0,
    "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, {
    "Subsystem1.Psuedo_AD8132.reference.V.v",
    "ozysdriverandreceiver/Subsystem1/Psuedo-AD8132", { 1, "1x1" }, "V", 1.0,
    "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, {
    "Subsystem1.Psuedo_AD8132.vcvs.i1",
    "ozysdriverandreceiver/Subsystem1/Psuedo-AD8132", { 1, "1x1" }, "A", 1.0,
    "A", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Input current", }, {
    "Subsystem1.Psuedo_AD8132.vcvs.i2",
    "ozysdriverandreceiver/Subsystem1/Psuedo-AD8132", { 1, "1x1" }, "A", 1.0,
    "A", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Output current", }, {
    "Subsystem1.Psuedo_AD8132.vcvs.n1.v",
    "ozysdriverandreceiver/Subsystem1/Psuedo-AD8132", { 1, "1x1" }, "V", 1.0,
    "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, {
    "Subsystem1.Psuedo_AD8132.vcvs.n2.v",
    "ozysdriverandreceiver/Subsystem1/Psuedo-AD8132", { 1, "1x1" }, "V", 1.0,
    "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, {
    "Subsystem1.Psuedo_AD8132.vcvs.p1.v",
    "ozysdriverandreceiver/Subsystem1/Psuedo-AD8132", { 1, "1x1" }, "V", 1.0,
    "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, {
    "Subsystem1.Psuedo_AD8132.vcvs.p2.v",
    "ozysdriverandreceiver/Subsystem1/Psuedo-AD8132", { 1, "1x1" }, "V", 1.0,
    "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, {
    "Subsystem1.Psuedo_AD8132.vcvs.v1",
    "ozysdriverandreceiver/Subsystem1/Psuedo-AD8132", { 1, "1x1" }, "V", 1.0,
    "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Input voltage", }, {
    "Subsystem1.Psuedo_AD8132.vcvs.v2",
    "ozysdriverandreceiver/Subsystem1/Psuedo-AD8132", { 1, "1x1" }, "V", 1.0,
    "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Output voltage", }, {
    "Subsystem1.RF.faultExtTrigger", "ozysdriverandreceiver/Subsystem1/RF", { 1,
      "1x1" }, "1", 1.0, "1", NE_NOMINAL_SOURCE_DERIVED, NE_INIT_MODE_NONE, TRUE,
    FALSE, NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "External fault trigger", }, {
    "Subsystem1.RF.faulted", "ozysdriverandreceiver/Subsystem1/RF", { 1, "1x1" },
    "1", 1.0, "1", NE_NOMINAL_SOURCE_DERIVED, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Fault flag", }, { "Subsystem1.RF.n.v",
    "ozysdriverandreceiver/Subsystem1/RF", { 1, "1x1" }, "V", 1.0, "V",
    NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, { "Subsystem1.RF.p.v",
    "ozysdriverandreceiver/Subsystem1/RF", { 1, "1x1" }, "V", 1.0, "V",
    NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, {
    "Subsystem1.RF.Resistor.i", "ozysdriverandreceiver/Subsystem1/RF", { 1,
      "1x1" }, "A", 1.0, "A", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE,
    FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Current", }, {
    "Subsystem1.RF.Resistor.n.v", "ozysdriverandreceiver/Subsystem1/RF", { 1,
      "1x1" }, "V", 1.0, "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE,
    FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, {
    "Subsystem1.RF.Resistor.p.v", "ozysdriverandreceiver/Subsystem1/RF", { 1,
      "1x1" }, "V", 1.0, "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE,
    FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, {
    "Subsystem1.RF.Resistor.v", "ozysdriverandreceiver/Subsystem1/RF", { 1,
      "1x1" }, "V", 1.0, "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE,
    FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, {
    "Subsystem1.RF.Resistor.power_dissipated",
    "ozysdriverandreceiver/Subsystem1/RF", { 1, "1x1" }, "A^2*Ohm", 1.0,
    "A^2*Ohm", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, FALSE, "Dissipated power", }, {
    "Subsystem1.RF1.faultExtTrigger", "ozysdriverandreceiver/Subsystem1/RF1", {
      1, "1x1" }, "1", 1.0, "1", NE_NOMINAL_SOURCE_DERIVED, NE_INIT_MODE_NONE,
    TRUE, FALSE, NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "External fault trigger", },
  { "Subsystem1.RF1.faulted", "ozysdriverandreceiver/Subsystem1/RF1", { 1, "1x1"
    }, "1", 1.0, "1", NE_NOMINAL_SOURCE_DERIVED, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Fault flag", }, { "Subsystem1.RF1.n.v",
    "ozysdriverandreceiver/Subsystem1/RF1", { 1, "1x1" }, "V", 1.0, "V",
    NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, { "Subsystem1.RF1.p.v",
    "ozysdriverandreceiver/Subsystem1/RF1", { 1, "1x1" }, "V", 1.0, "V",
    NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, {
    "Subsystem1.RF1.Resistor.i", "ozysdriverandreceiver/Subsystem1/RF1", { 1,
      "1x1" }, "A", 1.0, "A", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE,
    FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Current", }, {
    "Subsystem1.RF1.Resistor.n.v", "ozysdriverandreceiver/Subsystem1/RF1", { 1,
      "1x1" }, "V", 1.0, "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE,
    FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, {
    "Subsystem1.RF1.Resistor.p.v", "ozysdriverandreceiver/Subsystem1/RF1", { 1,
      "1x1" }, "V", 1.0, "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE,
    FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, {
    "Subsystem1.RF1.Resistor.v", "ozysdriverandreceiver/Subsystem1/RF1", { 1,
      "1x1" }, "V", 1.0, "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE,
    FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, {
    "Subsystem1.RF1.Resistor.power_dissipated",
    "ozysdriverandreceiver/Subsystem1/RF1", { 1, "1x1" }, "A^2*Ohm", 1.0,
    "A^2*Ohm", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, FALSE, "Dissipated power", }, {
    "Subsystem1.RG.faultExtTrigger", "ozysdriverandreceiver/Subsystem1/RG", { 1,
      "1x1" }, "1", 1.0, "1", NE_NOMINAL_SOURCE_DERIVED, NE_INIT_MODE_NONE, TRUE,
    FALSE, NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "External fault trigger", }, {
    "Subsystem1.RG.faulted", "ozysdriverandreceiver/Subsystem1/RG", { 1, "1x1" },
    "1", 1.0, "1", NE_NOMINAL_SOURCE_DERIVED, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Fault flag", }, { "Subsystem1.RG.n.v",
    "ozysdriverandreceiver/Subsystem1/RG", { 1, "1x1" }, "V", 1.0, "V",
    NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, { "Subsystem1.RG.p.v",
    "ozysdriverandreceiver/Subsystem1/RG", { 1, "1x1" }, "V", 1.0, "V",
    NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, {
    "Subsystem1.RG.Resistor.i", "ozysdriverandreceiver/Subsystem1/RG", { 1,
      "1x1" }, "A", 1.0, "A", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE,
    FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Current", }, {
    "Subsystem1.RG.Resistor.n.v", "ozysdriverandreceiver/Subsystem1/RG", { 1,
      "1x1" }, "V", 1.0, "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE,
    FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, {
    "Subsystem1.RG.Resistor.p.v", "ozysdriverandreceiver/Subsystem1/RG", { 1,
      "1x1" }, "V", 1.0, "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE,
    FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, {
    "Subsystem1.RG.Resistor.v", "ozysdriverandreceiver/Subsystem1/RG", { 1,
      "1x1" }, "V", 1.0, "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE,
    FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, {
    "Subsystem1.RG.Resistor.power_dissipated",
    "ozysdriverandreceiver/Subsystem1/RG", { 1, "1x1" }, "A^2*Ohm", 1.0,
    "A^2*Ohm", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, FALSE, "Dissipated power", }, {
    "Subsystem1.RG1.i", "ozysdriverandreceiver/Subsystem1/RG1", { 1, "1x1" },
    "A", 1.0, "A", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Current", }, { "Subsystem1.RG1.n.v",
    "ozysdriverandreceiver/Subsystem1/RG1", { 1, "1x1" }, "V", 1.0, "V",
    NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, { "Subsystem1.RG1.p.v",
    "ozysdriverandreceiver/Subsystem1/RG1", { 1, "1x1" }, "V", 1.0, "V",
    NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, { "Subsystem1.RG1.v",
    "ozysdriverandreceiver/Subsystem1/RG1", { 1, "1x1" }, "V", 1.0, "V",
    NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, {
    "Subsystem1.RG1.power_dissipated", "ozysdriverandreceiver/Subsystem1/RG1", {
      1, "1x1" }, "A^2*Ohm", 1.0, "A^2*Ohm", NE_NOMINAL_SOURCE_NONE,
    NE_INIT_MODE_NONE, FALSE, FALSE, NE_FREQTIME_TYPE_TIME, TRUE, FALSE,
    "Dissipated power", }, { "Subsystem1.x0_1uF.H.T",
    "ozysdriverandreceiver/Subsystem1/0.1uF", { 1, "1x1" }, "K", 1.0, "K",
    NE_NOMINAL_SOURCE_DERIVED, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Temperature", }, {
    "Subsystem1.x0_1uF.T", "ozysdriverandreceiver/Subsystem1/0.1uF", { 1, "1x1"
    }, "K", 1.0, "K", NE_NOMINAL_SOURCE_DERIVED, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Temperature", }, {
    "Subsystem1.x0_1uF.faultExtTrigger",
    "ozysdriverandreceiver/Subsystem1/0.1uF", { 1, "1x1" }, "1", 1.0, "1",
    NE_NOMINAL_SOURCE_DERIVED, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "External fault trigger", }, {
    "Subsystem1.x0_1uF.faulted", "ozysdriverandreceiver/Subsystem1/0.1uF", { 1,
      "1x1" }, "1", 1.0, "1", NE_NOMINAL_SOURCE_DERIVED, NE_INIT_MODE_NONE, TRUE,
    FALSE, NE_FREQTIME_TYPE_TIME, FALSE, TRUE,
    "Faulted/not-faulted flag for behavioral trigger", }, {
    "Subsystem1.x0_1uF.i", "ozysdriverandreceiver/Subsystem1/0.1uF", { 1, "1x1"
    }, "A", 1.0, "A", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Current", }, { "Subsystem1.x0_1uF.n.v",
    "ozysdriverandreceiver/Subsystem1/0.1uF", { 1, "1x1" }, "V", 1.0, "V",
    NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, { "Subsystem1.x0_1uF.p.v",
    "ozysdriverandreceiver/Subsystem1/0.1uF", { 1, "1x1" }, "V", 1.0, "V",
    NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, { "Subsystem1.x0_1uF.v",
    "ozysdriverandreceiver/Subsystem1/0.1uF", { 1, "1x1" }, "V", 1.0, "V",
    NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, { "Subsystem1.x0_1uF.vc",
    "ozysdriverandreceiver/Subsystem1/0.1uF", { 1, "1x1" }, "V", 1.0, "V",
    NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_MANDATORY, FALSE, TRUE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Capacitor voltage", }, {
    "Subsystem1.x0_1uF.power_dissipated",
    "ozysdriverandreceiver/Subsystem1/0.1uF", { 1, "1x1" }, "W", 1.0, "kW",
    NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "power_dissipated", }, {
    "Subsystem2.Capacitor1.H.T", "ozysdriverandreceiver/Subsystem2/Capacitor1",
      { 1, "1x1" }, "K", 1.0, "K", NE_NOMINAL_SOURCE_DERIVED, NE_INIT_MODE_NONE,
    TRUE, FALSE, NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Temperature", }, {
    "Subsystem2.Capacitor1.T", "ozysdriverandreceiver/Subsystem2/Capacitor1", {
      1, "1x1" }, "K", 1.0, "K", NE_NOMINAL_SOURCE_DERIVED, NE_INIT_MODE_NONE,
    TRUE, FALSE, NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Temperature", }, {
    "Subsystem2.Capacitor1.faultExtTrigger",
    "ozysdriverandreceiver/Subsystem2/Capacitor1", { 1, "1x1" }, "1", 1.0, "1",
    NE_NOMINAL_SOURCE_DERIVED, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "External fault trigger", }, {
    "Subsystem2.Capacitor1.faulted",
    "ozysdriverandreceiver/Subsystem2/Capacitor1", { 1, "1x1" }, "1", 1.0, "1",
    NE_NOMINAL_SOURCE_DERIVED, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE,
    "Faulted/not-faulted flag for behavioral trigger", }, {
    "Subsystem2.Capacitor1.i", "ozysdriverandreceiver/Subsystem2/Capacitor1", {
      1, "1x1" }, "A", 1.0, "A", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE,
    FALSE, FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Current", }, {
    "Subsystem2.Capacitor1.n.v", "ozysdriverandreceiver/Subsystem2/Capacitor1",
      { 1, "1x1" }, "V", 1.0, "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE,
    FALSE, FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, {
    "Subsystem2.Capacitor1.p.v", "ozysdriverandreceiver/Subsystem2/Capacitor1",
      { 1, "1x1" }, "V", 1.0, "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE,
    FALSE, FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, {
    "Subsystem2.Capacitor1.v", "ozysdriverandreceiver/Subsystem2/Capacitor1", {
      1, "1x1" }, "V", 1.0, "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE,
    FALSE, FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, {
    "Subsystem2.Capacitor1.vc", "ozysdriverandreceiver/Subsystem2/Capacitor1", {
      1, "1x1" }, "V", 1.0, "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_MANDATORY,
    FALSE, TRUE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Capacitor voltage", }, {
    "Subsystem2.Capacitor1.power_dissipated",
    "ozysdriverandreceiver/Subsystem2/Capacitor1", { 1, "1x1" }, "W", 1.0, "kW",
    NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "power_dissipated", }, {
    "Subsystem2.Capacitor2.H.T", "ozysdriverandreceiver/Subsystem2/Capacitor2",
      { 1, "1x1" }, "K", 1.0, "K", NE_NOMINAL_SOURCE_DERIVED, NE_INIT_MODE_NONE,
    TRUE, FALSE, NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Temperature", }, {
    "Subsystem2.Capacitor2.T", "ozysdriverandreceiver/Subsystem2/Capacitor2", {
      1, "1x1" }, "K", 1.0, "K", NE_NOMINAL_SOURCE_DERIVED, NE_INIT_MODE_NONE,
    TRUE, FALSE, NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Temperature", }, {
    "Subsystem2.Capacitor2.faultExtTrigger",
    "ozysdriverandreceiver/Subsystem2/Capacitor2", { 1, "1x1" }, "1", 1.0, "1",
    NE_NOMINAL_SOURCE_DERIVED, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "External fault trigger", }, {
    "Subsystem2.Capacitor2.faulted",
    "ozysdriverandreceiver/Subsystem2/Capacitor2", { 1, "1x1" }, "1", 1.0, "1",
    NE_NOMINAL_SOURCE_DERIVED, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE,
    "Faulted/not-faulted flag for behavioral trigger", }, {
    "Subsystem2.Capacitor2.i", "ozysdriverandreceiver/Subsystem2/Capacitor2", {
      1, "1x1" }, "A", 1.0, "A", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE,
    FALSE, FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Current", }, {
    "Subsystem2.Capacitor2.n.v", "ozysdriverandreceiver/Subsystem2/Capacitor2",
      { 1, "1x1" }, "V", 1.0, "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE,
    FALSE, FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, {
    "Subsystem2.Capacitor2.p.v", "ozysdriverandreceiver/Subsystem2/Capacitor2",
      { 1, "1x1" }, "V", 1.0, "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE,
    FALSE, FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, {
    "Subsystem2.Capacitor2.v", "ozysdriverandreceiver/Subsystem2/Capacitor2", {
      1, "1x1" }, "V", 1.0, "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE,
    FALSE, FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, {
    "Subsystem2.Capacitor2.vc", "ozysdriverandreceiver/Subsystem2/Capacitor2", {
      1, "1x1" }, "V", 1.0, "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_MANDATORY,
    FALSE, TRUE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Capacitor voltage", }, {
    "Subsystem2.Capacitor2.power_dissipated",
    "ozysdriverandreceiver/Subsystem2/Capacitor2", { 1, "1x1" }, "W", 1.0, "kW",
    NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "power_dissipated", }, {
    "Subsystem2.Diff0.v", "ozysdriverandreceiver/Subsystem2", { 1, "1x1" }, "V",
    1.0, "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Voltage", }, { "Subsystem2.Diff1.v",
    "ozysdriverandreceiver/Subsystem2", { 1, "1x1" }, "V", 1.0, "V",
    NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Voltage", }, { "Subsystem2.Filtered0.v",
    "ozysdriverandreceiver/Subsystem2", { 1, "1x1" }, "V", 1.0, "V",
    NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Voltage", }, { "Subsystem2.Filtered1.v",
    "ozysdriverandreceiver/Subsystem2", { 1, "1x1" }, "V", 1.0, "V",
    NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Voltage", }, {
    "Subsystem2.Resistor1.faultExtTrigger",
    "ozysdriverandreceiver/Subsystem2/Resistor1", { 1, "1x1" }, "1", 1.0, "1",
    NE_NOMINAL_SOURCE_DERIVED, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "External fault trigger", }, {
    "Subsystem2.Resistor1.faulted", "ozysdriverandreceiver/Subsystem2/Resistor1",
    { 1, "1x1" }, "1", 1.0, "1", NE_NOMINAL_SOURCE_DERIVED, NE_INIT_MODE_NONE,
    TRUE, FALSE, NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Fault flag", }, {
    "Subsystem2.Resistor1.n.v", "ozysdriverandreceiver/Subsystem2/Resistor1", {
      1, "1x1" }, "V", 1.0, "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE,
    FALSE, FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, {
    "Subsystem2.Resistor1.p.v", "ozysdriverandreceiver/Subsystem2/Resistor1", {
      1, "1x1" }, "V", 1.0, "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE,
    FALSE, FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, {
    "Subsystem2.Resistor1.Resistor.i",
    "ozysdriverandreceiver/Subsystem2/Resistor1", { 1, "1x1" }, "A", 1.0, "A",
    NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Current", }, {
    "Subsystem2.Resistor1.Resistor.n.v",
    "ozysdriverandreceiver/Subsystem2/Resistor1", { 1, "1x1" }, "V", 1.0, "V",
    NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, {
    "Subsystem2.Resistor1.Resistor.p.v",
    "ozysdriverandreceiver/Subsystem2/Resistor1", { 1, "1x1" }, "V", 1.0, "V",
    NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, {
    "Subsystem2.Resistor1.Resistor.v",
    "ozysdriverandreceiver/Subsystem2/Resistor1", { 1, "1x1" }, "V", 1.0, "V",
    NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, {
    "Subsystem2.Resistor1.Resistor.power_dissipated",
    "ozysdriverandreceiver/Subsystem2/Resistor1", { 1, "1x1" }, "A^2*Ohm", 1.0,
    "A^2*Ohm", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, FALSE, "Dissipated power", }, {
    "Subsystem2.Resistor2.faultExtTrigger",
    "ozysdriverandreceiver/Subsystem2/Resistor2", { 1, "1x1" }, "1", 1.0, "1",
    NE_NOMINAL_SOURCE_DERIVED, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "External fault trigger", }, {
    "Subsystem2.Resistor2.faulted", "ozysdriverandreceiver/Subsystem2/Resistor2",
    { 1, "1x1" }, "1", 1.0, "1", NE_NOMINAL_SOURCE_DERIVED, NE_INIT_MODE_NONE,
    TRUE, FALSE, NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Fault flag", }, {
    "Subsystem2.Resistor2.n.v", "ozysdriverandreceiver/Subsystem2/Resistor2", {
      1, "1x1" }, "V", 1.0, "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE,
    FALSE, FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, {
    "Subsystem2.Resistor2.p.v", "ozysdriverandreceiver/Subsystem2/Resistor2", {
      1, "1x1" }, "V", 1.0, "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE,
    FALSE, FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, {
    "Subsystem2.Resistor2.Resistor.i",
    "ozysdriverandreceiver/Subsystem2/Resistor2", { 1, "1x1" }, "A", 1.0, "A",
    NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Current", }, {
    "Subsystem2.Resistor2.Resistor.n.v",
    "ozysdriverandreceiver/Subsystem2/Resistor2", { 1, "1x1" }, "V", 1.0, "V",
    NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, {
    "Subsystem2.Resistor2.Resistor.p.v",
    "ozysdriverandreceiver/Subsystem2/Resistor2", { 1, "1x1" }, "V", 1.0, "V",
    NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, {
    "Subsystem2.Resistor2.Resistor.v",
    "ozysdriverandreceiver/Subsystem2/Resistor2", { 1, "1x1" }, "V", 1.0, "V",
    NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, {
    "Subsystem2.Resistor2.Resistor.power_dissipated",
    "ozysdriverandreceiver/Subsystem2/Resistor2", { 1, "1x1" }, "A^2*Ohm", 1.0,
    "A^2*Ohm", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, FALSE, "Dissipated power", }, {
    "Subsystem2.Resistor3.faultExtTrigger",
    "ozysdriverandreceiver/Subsystem2/Resistor3", { 1, "1x1" }, "1", 1.0, "1",
    NE_NOMINAL_SOURCE_DERIVED, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "External fault trigger", }, {
    "Subsystem2.Resistor3.faulted", "ozysdriverandreceiver/Subsystem2/Resistor3",
    { 1, "1x1" }, "1", 1.0, "1", NE_NOMINAL_SOURCE_DERIVED, NE_INIT_MODE_NONE,
    TRUE, FALSE, NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Fault flag", }, {
    "Subsystem2.Resistor3.n.v", "ozysdriverandreceiver/Subsystem2/Resistor3", {
      1, "1x1" }, "V", 1.0, "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE,
    FALSE, FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, {
    "Subsystem2.Resistor3.p.v", "ozysdriverandreceiver/Subsystem2/Resistor3", {
      1, "1x1" }, "V", 1.0, "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE,
    FALSE, FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, {
    "Subsystem2.Resistor3.Resistor.i",
    "ozysdriverandreceiver/Subsystem2/Resistor3", { 1, "1x1" }, "A", 1.0, "A",
    NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Current", }, {
    "Subsystem2.Resistor3.Resistor.n.v",
    "ozysdriverandreceiver/Subsystem2/Resistor3", { 1, "1x1" }, "V", 1.0, "V",
    NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, {
    "Subsystem2.Resistor3.Resistor.p.v",
    "ozysdriverandreceiver/Subsystem2/Resistor3", { 1, "1x1" }, "V", 1.0, "V",
    NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, {
    "Subsystem2.Resistor3.Resistor.v",
    "ozysdriverandreceiver/Subsystem2/Resistor3", { 1, "1x1" }, "V", 1.0, "V",
    NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, {
    "Subsystem2.Resistor3.Resistor.power_dissipated",
    "ozysdriverandreceiver/Subsystem2/Resistor3", { 1, "1x1" }, "A^2*Ohm", 1.0,
    "A^2*Ohm", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, FALSE, "Dissipated power", }, {
    "Subsystem2.Resistor4.faultExtTrigger",
    "ozysdriverandreceiver/Subsystem2/Resistor4", { 1, "1x1" }, "1", 1.0, "1",
    NE_NOMINAL_SOURCE_DERIVED, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "External fault trigger", }, {
    "Subsystem2.Resistor4.faulted", "ozysdriverandreceiver/Subsystem2/Resistor4",
    { 1, "1x1" }, "1", 1.0, "1", NE_NOMINAL_SOURCE_DERIVED, NE_INIT_MODE_NONE,
    TRUE, FALSE, NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Fault flag", }, {
    "Subsystem2.Resistor4.n.v", "ozysdriverandreceiver/Subsystem2/Resistor4", {
      1, "1x1" }, "V", 1.0, "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE,
    FALSE, FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, {
    "Subsystem2.Resistor4.p.v", "ozysdriverandreceiver/Subsystem2/Resistor4", {
      1, "1x1" }, "V", 1.0, "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE,
    FALSE, FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, {
    "Subsystem2.Resistor4.Resistor.i",
    "ozysdriverandreceiver/Subsystem2/Resistor4", { 1, "1x1" }, "A", 1.0, "A",
    NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Current", }, {
    "Subsystem2.Resistor4.Resistor.n.v",
    "ozysdriverandreceiver/Subsystem2/Resistor4", { 1, "1x1" }, "V", 1.0, "V",
    NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, {
    "Subsystem2.Resistor4.Resistor.p.v",
    "ozysdriverandreceiver/Subsystem2/Resistor4", { 1, "1x1" }, "V", 1.0, "V",
    NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, {
    "Subsystem2.Resistor4.Resistor.v",
    "ozysdriverandreceiver/Subsystem2/Resistor4", { 1, "1x1" }, "V", 1.0, "V",
    NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, {
    "Subsystem2.Resistor4.Resistor.power_dissipated",
    "ozysdriverandreceiver/Subsystem2/Resistor4", { 1, "1x1" }, "A^2*Ohm", 1.0,
    "A^2*Ohm", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, FALSE, "Dissipated power", }, {
    "Voltage_Sensor.V", "ozysdriverandreceiver/Voltage Sensor", { 1, "1x1" },
    "V", 1.0, "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "V", }, { "Voltage_Sensor.n.v",
    "ozysdriverandreceiver/Voltage Sensor", { 1, "1x1" }, "V", 1.0, "V",
    NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, { "Voltage_Sensor.p.v",
    "ozysdriverandreceiver/Voltage Sensor", { 1, "1x1" }, "V", 1.0, "V",
    NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, { "Voltage_Sensor1.V",
    "ozysdriverandreceiver/Voltage Sensor1", { 1, "1x1" }, "V", 1.0, "V",
    NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "V", }, { "Voltage_Sensor1.n.v",
    "ozysdriverandreceiver/Voltage Sensor1", { 1, "1x1" }, "V", 1.0, "V",
    NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, { "Voltage_Sensor1.p.v",
    "ozysdriverandreceiver/Voltage Sensor1", { 1, "1x1" }, "V", 1.0, "V",
    NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, { "Voltage_Sensor1_V0",
    "ozysdriverandreceiver/PS-Simulink\nConverter2", { 1, "1x1" }, "V", 1.0, "V",
    NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Voltage_Sensor1_V0", }, {
    "Voltage_Sensor2.V", "ozysdriverandreceiver/Voltage Sensor2", { 1, "1x1" },
    "V", 1.0, "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "V", }, { "Voltage_Sensor2.n.v",
    "ozysdriverandreceiver/Voltage Sensor2", { 1, "1x1" }, "V", 1.0, "V",
    NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, { "Voltage_Sensor2.p.v",
    "ozysdriverandreceiver/Voltage Sensor2", { 1, "1x1" }, "V", 1.0, "V",
    NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, { "Voltage_Sensor2_V0",
    "ozysdriverandreceiver/PS-Simulink\nConverter3", { 1, "1x1" }, "V", 1.0, "V",
    NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Voltage_Sensor2_V0", }, {
    "Voltage_Sensor3.V", "ozysdriverandreceiver/Voltage Sensor3", { 1, "1x1" },
    "V", 1.0, "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "V", }, { "Voltage_Sensor3.n.v",
    "ozysdriverandreceiver/Voltage Sensor3", { 1, "1x1" }, "V", 1.0, "V",
    NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, { "Voltage_Sensor3.p.v",
    "ozysdriverandreceiver/Voltage Sensor3", { 1, "1x1" }, "V", 1.0, "V",
    NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, { "Voltage_Sensor3_V0",
    "ozysdriverandreceiver/PS-Simulink\nConverter1", { 1, "1x1" }, "V", 1.0, "V",
    NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Voltage_Sensor3_V0", }, {
    "Voltage_Sensor4.V", "ozysdriverandreceiver/Voltage Sensor4", { 1, "1x1" },
    "V", 1.0, "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "V", }, { "Voltage_Sensor4.n.v",
    "ozysdriverandreceiver/Voltage Sensor4", { 1, "1x1" }, "V", 1.0, "V",
    NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, { "Voltage_Sensor4.p.v",
    "ozysdriverandreceiver/Voltage Sensor4", { 1, "1x1" }, "V", 1.0, "V",
    NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, { "Voltage_Sensor4_V0",
    "ozysdriverandreceiver/PS-Simulink\nConverter4", { 1, "1x1" }, "V", 1.0, "V",
    NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Voltage_Sensor4_V0", }, {
    "Voltage_Sensor5.V", "ozysdriverandreceiver/Voltage Sensor5", { 1, "1x1" },
    "V", 1.0, "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "V", }, { "Voltage_Sensor5.n.v",
    "ozysdriverandreceiver/Voltage Sensor5", { 1, "1x1" }, "V", 1.0, "V",
    NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, { "Voltage_Sensor5.p.v",
    "ozysdriverandreceiver/Voltage Sensor5", { 1, "1x1" }, "V", 1.0, "V",
    NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, { "Voltage_Sensor5_V0",
    "ozysdriverandreceiver/PS-Simulink\nConverter5", { 1, "1x1" }, "V", 1.0, "V",
    NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Voltage_Sensor5_V0", }, {
    "Voltage_Sensor6.V", "ozysdriverandreceiver/Voltage Sensor6", { 1, "1x1" },
    "V", 1.0, "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "V", }, { "Voltage_Sensor6.n.v",
    "ozysdriverandreceiver/Voltage Sensor6", { 1, "1x1" }, "V", 1.0, "V",
    NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, { "Voltage_Sensor6.p.v",
    "ozysdriverandreceiver/Voltage Sensor6", { 1, "1x1" }, "V", 1.0, "V",
    NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, { "Voltage_Sensor7.V",
    "ozysdriverandreceiver/Voltage Sensor7", { 1, "1x1" }, "V", 1.0, "V",
    NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "V", }, { "Voltage_Sensor7.n.v",
    "ozysdriverandreceiver/Voltage Sensor7", { 1, "1x1" }, "V", 1.0, "V",
    NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, TRUE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, { "Voltage_Sensor7.p.v",
    "ozysdriverandreceiver/Voltage Sensor7", { 1, "1x1" }, "V", 1.0, "V",
    NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Voltage", }, { "Voltage_Sensor7_V0",
    "ozysdriverandreceiver/PS-Simulink\nConverter6", { 1, "1x1" }, "V", 1.0, "V",
    NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Voltage_Sensor7_V0", }, {
    "Voltage_Sensor_V0", "ozysdriverandreceiver/PS-Simulink\nConverter", { 1,
      "1x1" }, "V", 1.0, "V", NE_NOMINAL_SOURCE_MODEL, NE_INIT_MODE_NONE, FALSE,
    FALSE, NE_FREQTIME_TYPE_TIME, FALSE, TRUE, "Voltage_Sensor_V0", } };

static NeModeData s_major_mode_data[4] = { { "Noise1.random_source.c.update0",
    0U, "ozysdriverandreceiver/Noise1", 0, { 2, "1x2" },
    "Secondary variable representing an update statement or an initial event found in one of the blocks, including Noise1.random_source.c.",
  }, { "Noise1.random_source.c.update0", 1U, "ozysdriverandreceiver/Noise1", 0,
      { 2, "1x2" },
    "Secondary variable representing an update statement or an initial event found in one of the blocks, including Noise1.random_source.c.",
  }, { "Noise2.random_source.c.update1", 0U, "ozysdriverandreceiver/Noise2", 0,
      { 2, "1x2" },
    "Secondary variable representing an update statement or an initial event found in one of the blocks, including Noise2.random_source.c.",
  }, { "Noise2.random_source.c.update1", 1U, "ozysdriverandreceiver/Noise2", 0,
      { 2, "1x2" },
    "Secondary variable representing an update statement or an initial event found in one of the blocks, including Noise2.random_source.c.",
  } };

static NeZCData s_zc_data[13] = { { "ozysdriverandreceiver/Noise2", 2U, 0U,
    "Noise2.random_source.c", "simscape_internal.rand_gaussian",
    NE_ZC_TYPE_FALSE, }, { "ozysdriverandreceiver/SG/Variable Resistor", 1U, 2U,
    "SG.Variable_Resistor", "foundation.electrical.elements.variable_resistor",
    NE_ZC_TYPE_FALSE, }, { "ozysdriverandreceiver/SG/Variable Resistor1", 1U, 3U,
    "SG.Variable_Resistor1", "foundation.electrical.elements.variable_resistor",
    NE_ZC_TYPE_FALSE, }, { "ozysdriverandreceiver/SG/Variable Resistor2", 1U, 4U,
    "SG.Variable_Resistor2", "foundation.electrical.elements.variable_resistor",
    NE_ZC_TYPE_FALSE, }, { "ozysdriverandreceiver/SG/Variable Resistor3", 1U, 5U,
    "SG.Variable_Resistor3", "foundation.electrical.elements.variable_resistor",
    NE_ZC_TYPE_FALSE, }, { "ozysdriverandreceiver/Subsystem1/Psuedo-AD8132", 1U,
    6U, "Subsystem1.Psuedo_AD8132.diff_op_amp_eqn",
    "ee.ic.differential_opamp_eqn", NE_ZC_TYPE_FALSE, }, {
    "ozysdriverandreceiver/Subsystem1/Psuedo-AD8132", 1U, 7U,
    "Subsystem1.Psuedo_AD8132.diff_op_amp_eqn", "ee.ic.differential_opamp_eqn",
    NE_ZC_TYPE_FALSE, }, { "ozysdriverandreceiver/Subsystem1/Psuedo-AD8132", 1U,
    8U, "Subsystem1.Psuedo_AD8132.diff_op_amp_eqn",
    "ee.ic.differential_opamp_eqn", NE_ZC_TYPE_FALSE, }, {
    "ozysdriverandreceiver/Subsystem1/Psuedo-AD8132", 1U, 9U,
    "Subsystem1.Psuedo_AD8132.diff_op_amp_eqn", "ee.ic.differential_opamp_eqn",
    NE_ZC_TYPE_FALSE, }, { "ozysdriverandreceiver/Subsystem1/Psuedo-AD8132", 1U,
    10U, "Subsystem1.Psuedo_AD8132.diff_op_amp_eqn",
    "ee.ic.differential_opamp_eqn", NE_ZC_TYPE_FALSE, }, {
    "ozysdriverandreceiver/Subsystem1/Psuedo-AD8132", 1U, 11U,
    "Subsystem1.Psuedo_AD8132.diff_op_amp_eqn", "ee.ic.differential_opamp_eqn",
    NE_ZC_TYPE_FALSE, }, { "ozysdriverandreceiver/Subsystem1/Psuedo-AD8132", 1U,
    12U, "Subsystem1.Psuedo_AD8132.diff_op_amp_eqn",
    "ee.ic.differential_opamp_eqn", NE_ZC_TYPE_FALSE, }, {
    "ozysdriverandreceiver/Subsystem1/Psuedo-AD8132", 1U, 13U,
    "Subsystem1.Psuedo_AD8132.diff_op_amp_eqn", "ee.ic.differential_opamp_eqn",
    NE_ZC_TYPE_FALSE, } };

static NeRange s_range[14] = { { "simscape_internal.rand_gaussian", 1U, 1U, 1U,
    1U, NE_RANGE_TYPE_PROTECTED, }, { "simscape_internal.rand_gaussian", 1U, 1U,
    1U, 1U, NE_RANGE_TYPE_PROTECTED, }, {
    "foundation.electrical.elements.variable_resistor", 58U, 8U, 58U, 16U,
    NE_RANGE_TYPE_NORMAL, }, {
    "foundation.electrical.elements.variable_resistor", 58U, 8U, 58U, 16U,
    NE_RANGE_TYPE_NORMAL, }, {
    "foundation.electrical.elements.variable_resistor", 58U, 8U, 58U, 16U,
    NE_RANGE_TYPE_NORMAL, }, {
    "foundation.electrical.elements.variable_resistor", 58U, 8U, 58U, 16U,
    NE_RANGE_TYPE_NORMAL, }, { "ee.ic.differential_opamp_eqn", 1U, 1U, 1U, 1U,
    NE_RANGE_TYPE_PROTECTED, }, { "ee.ic.differential_opamp_eqn", 1U, 1U, 1U, 1U,
    NE_RANGE_TYPE_PROTECTED, }, { "ee.ic.differential_opamp_eqn", 1U, 1U, 1U, 1U,
    NE_RANGE_TYPE_PROTECTED, }, { "ee.ic.differential_opamp_eqn", 1U, 1U, 1U, 1U,
    NE_RANGE_TYPE_PROTECTED, }, { "ee.ic.differential_opamp_eqn", 1U, 1U, 1U, 1U,
    NE_RANGE_TYPE_PROTECTED, }, { "ee.ic.differential_opamp_eqn", 1U, 1U, 1U, 1U,
    NE_RANGE_TYPE_PROTECTED, }, { "ee.ic.differential_opamp_eqn", 1U, 1U, 1U, 1U,
    NE_RANGE_TYPE_PROTECTED, }, { "ee.ic.differential_opamp_eqn", 1U, 1U, 1U, 1U,
    NE_RANGE_TYPE_PROTECTED, } };

static NeAssertData s_assert_data[56] = { { "ozysdriverandreceiver/Resistor", 1U,
    0U, "Resistor.power_dissipated", "foundation.electrical.elements.resistor",
    FALSE,
    "In power, the exponent must be positive when the base is equal to zero.",
    "physmod:common:mf:expr:analyze:RequireExponentPositive", }, {
    "ozysdriverandreceiver/Resistor", 1U, 1U, "Resistor.power_dissipated",
    "foundation.electrical.elements.resistor", FALSE,
    "In power, the base must be nonnegative when the exponent is not an integer.",
    "physmod:common:mf:expr:analyze:RequireBaseNonnegative", }, {
    "ozysdriverandreceiver/Resistor1", 1U, 2U, "Resistor1.power_dissipated",
    "foundation.electrical.elements.resistor", FALSE,
    "In power, the exponent must be positive when the base is equal to zero.",
    "physmod:common:mf:expr:analyze:RequireExponentPositive", }, {
    "ozysdriverandreceiver/Resistor1", 1U, 3U, "Resistor1.power_dissipated",
    "foundation.electrical.elements.resistor", FALSE,
    "In power, the base must be nonnegative when the exponent is not an integer.",
    "physmod:common:mf:expr:analyze:RequireBaseNonnegative", }, {
    "ozysdriverandreceiver/Resistor2", 1U, 4U, "Resistor2.power_dissipated",
    "foundation.electrical.elements.resistor", FALSE,
    "In power, the exponent must be positive when the base is equal to zero.",
    "physmod:common:mf:expr:analyze:RequireExponentPositive", }, {
    "ozysdriverandreceiver/Resistor2", 1U, 5U, "Resistor2.power_dissipated",
    "foundation.electrical.elements.resistor", FALSE,
    "In power, the base must be nonnegative when the exponent is not an integer.",
    "physmod:common:mf:expr:analyze:RequireBaseNonnegative", }, {
    "ozysdriverandreceiver/Resistor3", 1U, 6U, "Resistor3.power_dissipated",
    "foundation.electrical.elements.resistor", FALSE,
    "In power, the exponent must be positive when the base is equal to zero.",
    "physmod:common:mf:expr:analyze:RequireExponentPositive", }, {
    "ozysdriverandreceiver/Resistor3", 1U, 7U, "Resistor3.power_dissipated",
    "foundation.electrical.elements.resistor", FALSE,
    "In power, the base must be nonnegative when the exponent is not an integer.",
    "physmod:common:mf:expr:analyze:RequireBaseNonnegative", }, {
    "ozysdriverandreceiver/SG/Pull Up", 1U, 8U, "SG.Pull_Up.power_dissipated",
    "foundation.electrical.elements.resistor", FALSE,
    "In power, the exponent must be positive when the base is equal to zero.",
    "physmod:common:mf:expr:analyze:RequireExponentPositive", }, {
    "ozysdriverandreceiver/SG/Pull Up", 1U, 9U, "SG.Pull_Up.power_dissipated",
    "foundation.electrical.elements.resistor", FALSE,
    "In power, the base must be nonnegative when the exponent is not an integer.",
    "physmod:common:mf:expr:analyze:RequireBaseNonnegative", }, {
    "ozysdriverandreceiver/Subsystem1/Psuedo-AD8132", 1U, 10U,
    "Subsystem1.Psuedo_AD8132.C1a.power_dissipated",
    "foundation.electrical.elements.capacitor", FALSE,
    "In power, the exponent must be positive when the base is equal to zero.",
    "physmod:common:mf:expr:analyze:RequireExponentPositive", }, {
    "ozysdriverandreceiver/Subsystem1/Psuedo-AD8132", 1U, 11U,
    "Subsystem1.Psuedo_AD8132.C1a.power_dissipated",
    "foundation.electrical.elements.capacitor", FALSE,
    "In power, the base must be nonnegative when the exponent is not an integer.",
    "physmod:common:mf:expr:analyze:RequireBaseNonnegative", }, {
    "ozysdriverandreceiver/Subsystem1/Psuedo-AD8132", 1U, 12U,
    "Subsystem1.Psuedo_AD8132.C1a.power_dissipated",
    "foundation.electrical.elements.capacitor", FALSE,
    "In power, the exponent must be positive when the base is equal to zero.",
    "physmod:common:mf:expr:analyze:RequireExponentPositive", }, {
    "ozysdriverandreceiver/Subsystem1/Psuedo-AD8132", 1U, 13U,
    "Subsystem1.Psuedo_AD8132.C1a.power_dissipated",
    "foundation.electrical.elements.capacitor", FALSE,
    "In power, the base must be nonnegative when the exponent is not an integer.",
    "physmod:common:mf:expr:analyze:RequireBaseNonnegative", }, {
    "ozysdriverandreceiver/Subsystem1/Psuedo-AD8132", 1U, 14U,
    "Subsystem1.Psuedo_AD8132.C1b.power_dissipated",
    "foundation.electrical.elements.capacitor", FALSE,
    "In power, the exponent must be positive when the base is equal to zero.",
    "physmod:common:mf:expr:analyze:RequireExponentPositive", }, {
    "ozysdriverandreceiver/Subsystem1/Psuedo-AD8132", 1U, 15U,
    "Subsystem1.Psuedo_AD8132.C1b.power_dissipated",
    "foundation.electrical.elements.capacitor", FALSE,
    "In power, the base must be nonnegative when the exponent is not an integer.",
    "physmod:common:mf:expr:analyze:RequireBaseNonnegative", }, {
    "ozysdriverandreceiver/Subsystem1/Psuedo-AD8132", 1U, 16U,
    "Subsystem1.Psuedo_AD8132.C1b.power_dissipated",
    "foundation.electrical.elements.capacitor", FALSE,
    "In power, the exponent must be positive when the base is equal to zero.",
    "physmod:common:mf:expr:analyze:RequireExponentPositive", }, {
    "ozysdriverandreceiver/Subsystem1/Psuedo-AD8132", 1U, 17U,
    "Subsystem1.Psuedo_AD8132.C1b.power_dissipated",
    "foundation.electrical.elements.capacitor", FALSE,
    "In power, the base must be nonnegative when the exponent is not an integer.",
    "physmod:common:mf:expr:analyze:RequireBaseNonnegative", }, {
    "ozysdriverandreceiver/Subsystem1/Psuedo-AD8132", 1U, 18U,
    "Subsystem1.Psuedo_AD8132.C2.power_dissipated",
    "foundation.electrical.elements.capacitor", FALSE,
    "In power, the exponent must be positive when the base is equal to zero.",
    "physmod:common:mf:expr:analyze:RequireExponentPositive", }, {
    "ozysdriverandreceiver/Subsystem1/Psuedo-AD8132", 1U, 19U,
    "Subsystem1.Psuedo_AD8132.C2.power_dissipated",
    "foundation.electrical.elements.capacitor", FALSE,
    "In power, the base must be nonnegative when the exponent is not an integer.",
    "physmod:common:mf:expr:analyze:RequireBaseNonnegative", }, {
    "ozysdriverandreceiver/Subsystem1/Psuedo-AD8132", 1U, 20U,
    "Subsystem1.Psuedo_AD8132.C2.power_dissipated",
    "foundation.electrical.elements.capacitor", FALSE,
    "In power, the exponent must be positive when the base is equal to zero.",
    "physmod:common:mf:expr:analyze:RequireExponentPositive", }, {
    "ozysdriverandreceiver/Subsystem1/Psuedo-AD8132", 1U, 21U,
    "Subsystem1.Psuedo_AD8132.C2.power_dissipated",
    "foundation.electrical.elements.capacitor", FALSE,
    "In power, the base must be nonnegative when the exponent is not an integer.",
    "physmod:common:mf:expr:analyze:RequireBaseNonnegative", }, {
    "ozysdriverandreceiver/Subsystem1/Psuedo-AD8132", 1U, 22U,
    "Subsystem1.Psuedo_AD8132.R1a.power_dissipated",
    "foundation.electrical.elements.resistor", FALSE,
    "In power, the exponent must be positive when the base is equal to zero.",
    "physmod:common:mf:expr:analyze:RequireExponentPositive", }, {
    "ozysdriverandreceiver/Subsystem1/Psuedo-AD8132", 1U, 23U,
    "Subsystem1.Psuedo_AD8132.R1a.power_dissipated",
    "foundation.electrical.elements.resistor", FALSE,
    "In power, the base must be nonnegative when the exponent is not an integer.",
    "physmod:common:mf:expr:analyze:RequireBaseNonnegative", }, {
    "ozysdriverandreceiver/Subsystem1/Psuedo-AD8132", 1U, 24U,
    "Subsystem1.Psuedo_AD8132.R1b.power_dissipated",
    "foundation.electrical.elements.resistor", FALSE,
    "In power, the exponent must be positive when the base is equal to zero.",
    "physmod:common:mf:expr:analyze:RequireExponentPositive", }, {
    "ozysdriverandreceiver/Subsystem1/Psuedo-AD8132", 1U, 25U,
    "Subsystem1.Psuedo_AD8132.R1b.power_dissipated",
    "foundation.electrical.elements.resistor", FALSE,
    "In power, the base must be nonnegative when the exponent is not an integer.",
    "physmod:common:mf:expr:analyze:RequireBaseNonnegative", }, {
    "ozysdriverandreceiver/Subsystem1/Psuedo-AD8132", 1U, 26U,
    "Subsystem1.Psuedo_AD8132.R2.power_dissipated",
    "foundation.electrical.elements.resistor", FALSE,
    "In power, the exponent must be positive when the base is equal to zero.",
    "physmod:common:mf:expr:analyze:RequireExponentPositive", }, {
    "ozysdriverandreceiver/Subsystem1/Psuedo-AD8132", 1U, 27U,
    "Subsystem1.Psuedo_AD8132.R2.power_dissipated",
    "foundation.electrical.elements.resistor", FALSE,
    "In power, the base must be nonnegative when the exponent is not an integer.",
    "physmod:common:mf:expr:analyze:RequireBaseNonnegative", }, {
    "ozysdriverandreceiver/Subsystem1/RF", 1U, 28U,
    "Subsystem1.RF.Resistor.power_dissipated",
    "foundation.electrical.elements.resistor", FALSE,
    "In power, the exponent must be positive when the base is equal to zero.",
    "physmod:common:mf:expr:analyze:RequireExponentPositive", }, {
    "ozysdriverandreceiver/Subsystem1/RF", 1U, 29U,
    "Subsystem1.RF.Resistor.power_dissipated",
    "foundation.electrical.elements.resistor", FALSE,
    "In power, the base must be nonnegative when the exponent is not an integer.",
    "physmod:common:mf:expr:analyze:RequireBaseNonnegative", }, {
    "ozysdriverandreceiver/Subsystem1/RF1", 1U, 30U,
    "Subsystem1.RF1.Resistor.power_dissipated",
    "foundation.electrical.elements.resistor", FALSE,
    "In power, the exponent must be positive when the base is equal to zero.",
    "physmod:common:mf:expr:analyze:RequireExponentPositive", }, {
    "ozysdriverandreceiver/Subsystem1/RF1", 1U, 31U,
    "Subsystem1.RF1.Resistor.power_dissipated",
    "foundation.electrical.elements.resistor", FALSE,
    "In power, the base must be nonnegative when the exponent is not an integer.",
    "physmod:common:mf:expr:analyze:RequireBaseNonnegative", }, {
    "ozysdriverandreceiver/Subsystem1/RG", 1U, 32U,
    "Subsystem1.RG.Resistor.power_dissipated",
    "foundation.electrical.elements.resistor", FALSE,
    "In power, the exponent must be positive when the base is equal to zero.",
    "physmod:common:mf:expr:analyze:RequireExponentPositive", }, {
    "ozysdriverandreceiver/Subsystem1/RG", 1U, 33U,
    "Subsystem1.RG.Resistor.power_dissipated",
    "foundation.electrical.elements.resistor", FALSE,
    "In power, the base must be nonnegative when the exponent is not an integer.",
    "physmod:common:mf:expr:analyze:RequireBaseNonnegative", }, {
    "ozysdriverandreceiver/Subsystem1/RG1", 1U, 34U,
    "Subsystem1.RG1.power_dissipated", "foundation.electrical.elements.resistor",
    FALSE,
    "In power, the exponent must be positive when the base is equal to zero.",
    "physmod:common:mf:expr:analyze:RequireExponentPositive", }, {
    "ozysdriverandreceiver/Subsystem1/RG1", 1U, 35U,
    "Subsystem1.RG1.power_dissipated", "foundation.electrical.elements.resistor",
    FALSE,
    "In power, the base must be nonnegative when the exponent is not an integer.",
    "physmod:common:mf:expr:analyze:RequireBaseNonnegative", }, {
    "ozysdriverandreceiver/Subsystem1/0.1uF", 1U, 36U, "Subsystem1.x0_1uF",
    "ee.passive.capacitor", FALSE,
    "In power, the exponent must be positive when the base is equal to zero.",
    "physmod:common:mf:expr:analyze:RequireExponentPositive", }, {
    "ozysdriverandreceiver/Subsystem1/0.1uF", 1U, 37U, "Subsystem1.x0_1uF",
    "ee.passive.capacitor", FALSE,
    "In power, the base must be nonnegative when the exponent is not an integer.",
    "physmod:common:mf:expr:analyze:RequireBaseNonnegative", }, {
    "ozysdriverandreceiver/Subsystem1/0.1uF", 1U, 38U, "Subsystem1.x0_1uF",
    "ee.passive.capacitor", FALSE,
    "In power, the exponent must be positive when the base is equal to zero.",
    "physmod:common:mf:expr:analyze:RequireExponentPositive", }, {
    "ozysdriverandreceiver/Subsystem1/0.1uF", 1U, 39U, "Subsystem1.x0_1uF",
    "ee.passive.capacitor", FALSE,
    "In power, the base must be nonnegative when the exponent is not an integer.",
    "physmod:common:mf:expr:analyze:RequireBaseNonnegative", }, {
    "ozysdriverandreceiver/Subsystem2/Capacitor1", 1U, 40U,
    "Subsystem2.Capacitor1", "ee.passive.capacitor", FALSE,
    "In power, the exponent must be positive when the base is equal to zero.",
    "physmod:common:mf:expr:analyze:RequireExponentPositive", }, {
    "ozysdriverandreceiver/Subsystem2/Capacitor1", 1U, 41U,
    "Subsystem2.Capacitor1", "ee.passive.capacitor", FALSE,
    "In power, the base must be nonnegative when the exponent is not an integer.",
    "physmod:common:mf:expr:analyze:RequireBaseNonnegative", }, {
    "ozysdriverandreceiver/Subsystem2/Capacitor1", 1U, 42U,
    "Subsystem2.Capacitor1", "ee.passive.capacitor", FALSE,
    "In power, the exponent must be positive when the base is equal to zero.",
    "physmod:common:mf:expr:analyze:RequireExponentPositive", }, {
    "ozysdriverandreceiver/Subsystem2/Capacitor1", 1U, 43U,
    "Subsystem2.Capacitor1", "ee.passive.capacitor", FALSE,
    "In power, the base must be nonnegative when the exponent is not an integer.",
    "physmod:common:mf:expr:analyze:RequireBaseNonnegative", }, {
    "ozysdriverandreceiver/Subsystem2/Capacitor2", 1U, 44U,
    "Subsystem2.Capacitor2", "ee.passive.capacitor", FALSE,
    "In power, the exponent must be positive when the base is equal to zero.",
    "physmod:common:mf:expr:analyze:RequireExponentPositive", }, {
    "ozysdriverandreceiver/Subsystem2/Capacitor2", 1U, 45U,
    "Subsystem2.Capacitor2", "ee.passive.capacitor", FALSE,
    "In power, the base must be nonnegative when the exponent is not an integer.",
    "physmod:common:mf:expr:analyze:RequireBaseNonnegative", }, {
    "ozysdriverandreceiver/Subsystem2/Capacitor2", 1U, 46U,
    "Subsystem2.Capacitor2", "ee.passive.capacitor", FALSE,
    "In power, the exponent must be positive when the base is equal to zero.",
    "physmod:common:mf:expr:analyze:RequireExponentPositive", }, {
    "ozysdriverandreceiver/Subsystem2/Capacitor2", 1U, 47U,
    "Subsystem2.Capacitor2", "ee.passive.capacitor", FALSE,
    "In power, the base must be nonnegative when the exponent is not an integer.",
    "physmod:common:mf:expr:analyze:RequireBaseNonnegative", }, {
    "ozysdriverandreceiver/Subsystem2/Resistor1", 1U, 48U,
    "Subsystem2.Resistor1.Resistor.power_dissipated",
    "foundation.electrical.elements.resistor", FALSE,
    "In power, the exponent must be positive when the base is equal to zero.",
    "physmod:common:mf:expr:analyze:RequireExponentPositive", }, {
    "ozysdriverandreceiver/Subsystem2/Resistor1", 1U, 49U,
    "Subsystem2.Resistor1.Resistor.power_dissipated",
    "foundation.electrical.elements.resistor", FALSE,
    "In power, the base must be nonnegative when the exponent is not an integer.",
    "physmod:common:mf:expr:analyze:RequireBaseNonnegative", }, {
    "ozysdriverandreceiver/Subsystem2/Resistor2", 1U, 50U,
    "Subsystem2.Resistor2.Resistor.power_dissipated",
    "foundation.electrical.elements.resistor", FALSE,
    "In power, the exponent must be positive when the base is equal to zero.",
    "physmod:common:mf:expr:analyze:RequireExponentPositive", }, {
    "ozysdriverandreceiver/Subsystem2/Resistor2", 1U, 51U,
    "Subsystem2.Resistor2.Resistor.power_dissipated",
    "foundation.electrical.elements.resistor", FALSE,
    "In power, the base must be nonnegative when the exponent is not an integer.",
    "physmod:common:mf:expr:analyze:RequireBaseNonnegative", }, {
    "ozysdriverandreceiver/Subsystem2/Resistor3", 1U, 52U,
    "Subsystem2.Resistor3.Resistor.power_dissipated",
    "foundation.electrical.elements.resistor", FALSE,
    "In power, the exponent must be positive when the base is equal to zero.",
    "physmod:common:mf:expr:analyze:RequireExponentPositive", }, {
    "ozysdriverandreceiver/Subsystem2/Resistor3", 1U, 53U,
    "Subsystem2.Resistor3.Resistor.power_dissipated",
    "foundation.electrical.elements.resistor", FALSE,
    "In power, the base must be nonnegative when the exponent is not an integer.",
    "physmod:common:mf:expr:analyze:RequireBaseNonnegative", }, {
    "ozysdriverandreceiver/Subsystem2/Resistor4", 1U, 54U,
    "Subsystem2.Resistor4.Resistor.power_dissipated",
    "foundation.electrical.elements.resistor", FALSE,
    "In power, the exponent must be positive when the base is equal to zero.",
    "physmod:common:mf:expr:analyze:RequireExponentPositive", }, {
    "ozysdriverandreceiver/Subsystem2/Resistor4", 1U, 55U,
    "Subsystem2.Resistor4.Resistor.power_dissipated",
    "foundation.electrical.elements.resistor", FALSE,
    "In power, the base must be nonnegative when the exponent is not an integer.",
    "physmod:common:mf:expr:analyze:RequireBaseNonnegative", } };

static NeRange s_assert_range[56] = { {
    "foundation.electrical.elements.resistor", 20U, 29U, 20U, 30U,
    NE_RANGE_TYPE_NORMAL, }, { "foundation.electrical.elements.resistor", 20U,
    27U, 20U, 28U, NE_RANGE_TYPE_NORMAL, }, {
    "foundation.electrical.elements.resistor", 20U, 29U, 20U, 30U,
    NE_RANGE_TYPE_NORMAL, }, { "foundation.electrical.elements.resistor", 20U,
    27U, 20U, 28U, NE_RANGE_TYPE_NORMAL, }, {
    "foundation.electrical.elements.resistor", 20U, 29U, 20U, 30U,
    NE_RANGE_TYPE_NORMAL, }, { "foundation.electrical.elements.resistor", 20U,
    27U, 20U, 28U, NE_RANGE_TYPE_NORMAL, }, {
    "foundation.electrical.elements.resistor", 20U, 29U, 20U, 30U,
    NE_RANGE_TYPE_NORMAL, }, { "foundation.electrical.elements.resistor", 20U,
    27U, 20U, 28U, NE_RANGE_TYPE_NORMAL, }, {
    "foundation.electrical.elements.resistor", 20U, 29U, 20U, 30U,
    NE_RANGE_TYPE_NORMAL, }, { "foundation.electrical.elements.resistor", 20U,
    27U, 20U, 28U, NE_RANGE_TYPE_NORMAL, }, {
    "foundation.electrical.elements.capacitor", 26U, 29U, 26U, 30U,
    NE_RANGE_TYPE_NORMAL, }, { "foundation.electrical.elements.capacitor", 26U,
    27U, 26U, 28U, NE_RANGE_TYPE_NORMAL, }, {
    "foundation.electrical.elements.capacitor", 26U, 36U, 26U, 37U,
    NE_RANGE_TYPE_NORMAL, }, { "foundation.electrical.elements.capacitor", 26U,
    33U, 26U, 35U, NE_RANGE_TYPE_NORMAL, }, {
    "foundation.electrical.elements.capacitor", 26U, 29U, 26U, 30U,
    NE_RANGE_TYPE_NORMAL, }, { "foundation.electrical.elements.capacitor", 26U,
    27U, 26U, 28U, NE_RANGE_TYPE_NORMAL, }, {
    "foundation.electrical.elements.capacitor", 26U, 36U, 26U, 37U,
    NE_RANGE_TYPE_NORMAL, }, { "foundation.electrical.elements.capacitor", 26U,
    33U, 26U, 35U, NE_RANGE_TYPE_NORMAL, }, {
    "foundation.electrical.elements.capacitor", 26U, 29U, 26U, 30U,
    NE_RANGE_TYPE_NORMAL, }, { "foundation.electrical.elements.capacitor", 26U,
    27U, 26U, 28U, NE_RANGE_TYPE_NORMAL, }, {
    "foundation.electrical.elements.capacitor", 26U, 36U, 26U, 37U,
    NE_RANGE_TYPE_NORMAL, }, { "foundation.electrical.elements.capacitor", 26U,
    33U, 26U, 35U, NE_RANGE_TYPE_NORMAL, }, {
    "foundation.electrical.elements.resistor", 20U, 29U, 20U, 30U,
    NE_RANGE_TYPE_NORMAL, }, { "foundation.electrical.elements.resistor", 20U,
    27U, 20U, 28U, NE_RANGE_TYPE_NORMAL, }, {
    "foundation.electrical.elements.resistor", 20U, 29U, 20U, 30U,
    NE_RANGE_TYPE_NORMAL, }, { "foundation.electrical.elements.resistor", 20U,
    27U, 20U, 28U, NE_RANGE_TYPE_NORMAL, }, {
    "foundation.electrical.elements.resistor", 20U, 29U, 20U, 30U,
    NE_RANGE_TYPE_NORMAL, }, { "foundation.electrical.elements.resistor", 20U,
    27U, 20U, 28U, NE_RANGE_TYPE_NORMAL, }, {
    "foundation.electrical.elements.resistor", 20U, 29U, 20U, 30U,
    NE_RANGE_TYPE_NORMAL, }, { "foundation.electrical.elements.resistor", 20U,
    27U, 20U, 28U, NE_RANGE_TYPE_NORMAL, }, {
    "foundation.electrical.elements.resistor", 20U, 29U, 20U, 30U,
    NE_RANGE_TYPE_NORMAL, }, { "foundation.electrical.elements.resistor", 20U,
    27U, 20U, 28U, NE_RANGE_TYPE_NORMAL, }, {
    "foundation.electrical.elements.resistor", 20U, 29U, 20U, 30U,
    NE_RANGE_TYPE_NORMAL, }, { "foundation.electrical.elements.resistor", 20U,
    27U, 20U, 28U, NE_RANGE_TYPE_NORMAL, }, {
    "foundation.electrical.elements.resistor", 20U, 29U, 20U, 30U,
    NE_RANGE_TYPE_NORMAL, }, { "foundation.electrical.elements.resistor", 20U,
    27U, 20U, 28U, NE_RANGE_TYPE_NORMAL, }, { "ee.passive.capacitor", 1U, 1U, 1U,
    1U, NE_RANGE_TYPE_PROTECTED, }, { "ee.passive.capacitor", 1U, 1U, 1U, 1U,
    NE_RANGE_TYPE_PROTECTED, }, { "ee.passive.capacitor", 1U, 1U, 1U, 1U,
    NE_RANGE_TYPE_PROTECTED, }, { "ee.passive.capacitor", 1U, 1U, 1U, 1U,
    NE_RANGE_TYPE_PROTECTED, }, { "ee.passive.capacitor", 1U, 1U, 1U, 1U,
    NE_RANGE_TYPE_PROTECTED, }, { "ee.passive.capacitor", 1U, 1U, 1U, 1U,
    NE_RANGE_TYPE_PROTECTED, }, { "ee.passive.capacitor", 1U, 1U, 1U, 1U,
    NE_RANGE_TYPE_PROTECTED, }, { "ee.passive.capacitor", 1U, 1U, 1U, 1U,
    NE_RANGE_TYPE_PROTECTED, }, { "ee.passive.capacitor", 1U, 1U, 1U, 1U,
    NE_RANGE_TYPE_PROTECTED, }, { "ee.passive.capacitor", 1U, 1U, 1U, 1U,
    NE_RANGE_TYPE_PROTECTED, }, { "ee.passive.capacitor", 1U, 1U, 1U, 1U,
    NE_RANGE_TYPE_PROTECTED, }, { "ee.passive.capacitor", 1U, 1U, 1U, 1U,
    NE_RANGE_TYPE_PROTECTED, }, { "foundation.electrical.elements.resistor", 20U,
    29U, 20U, 30U, NE_RANGE_TYPE_NORMAL, }, {
    "foundation.electrical.elements.resistor", 20U, 27U, 20U, 28U,
    NE_RANGE_TYPE_NORMAL, }, { "foundation.electrical.elements.resistor", 20U,
    29U, 20U, 30U, NE_RANGE_TYPE_NORMAL, }, {
    "foundation.electrical.elements.resistor", 20U, 27U, 20U, 28U,
    NE_RANGE_TYPE_NORMAL, }, { "foundation.electrical.elements.resistor", 20U,
    29U, 20U, 30U, NE_RANGE_TYPE_NORMAL, }, {
    "foundation.electrical.elements.resistor", 20U, 27U, 20U, 28U,
    NE_RANGE_TYPE_NORMAL, }, { "foundation.electrical.elements.resistor", 20U,
    29U, 20U, 30U, NE_RANGE_TYPE_NORMAL, }, {
    "foundation.electrical.elements.resistor", 20U, 27U, 20U, 28U,
    NE_RANGE_TYPE_NORMAL, } };

static NeAssertData *s_param_assert_data = NULL;
static NeRange *s_param_assert_range = NULL;
static NeAssertData *s_initial_assert_data = NULL;
static NeRange *s_initial_assert_range = NULL;
static NeRange s_equation_range[56] = { {
    "foundation.electrical.elements.capacitor", 36U, 5U, 36U, 25U,
    NE_RANGE_TYPE_NORMAL, }, { "foundation.electrical.elements.capacitor", 36U,
    5U, 36U, 25U, NE_RANGE_TYPE_NORMAL, }, {
    "foundation.electrical.elements.capacitor", 36U, 5U, 36U, 25U,
    NE_RANGE_TYPE_NORMAL, }, { "ee.ic.differential_opamp_eqn", 1U, 1U, 1U, 1U,
    NE_RANGE_TYPE_PROTECTED, }, { "ee.ic.differential_opamp_eqn", 1U, 1U, 1U, 1U,
    NE_RANGE_TYPE_PROTECTED, }, { "ee.ic.differential_opamp_eqn", 1U, 1U, 1U, 1U,
    NE_RANGE_TYPE_PROTECTED, }, { "ee.ic.differential_opamp_eqn", 1U, 1U, 1U, 1U,
    NE_RANGE_TYPE_PROTECTED, }, { "ee.ic.differential_opamp_eqn", 1U, 1U, 1U, 1U,
    NE_RANGE_TYPE_PROTECTED, }, { "ee.ic.differential_opamp_eqn", 1U, 1U, 1U, 1U,
    NE_RANGE_TYPE_PROTECTED, }, { "ee.ic.differential_opamp_eqn", 1U, 1U, 1U, 1U,
    NE_RANGE_TYPE_PROTECTED, }, { "ee.ic.differential_opamp_eqn", 1U, 1U, 1U, 1U,
    NE_RANGE_TYPE_PROTECTED, }, { "ee.ic.differential_opamp_eqn", 1U, 1U, 1U, 1U,
    NE_RANGE_TYPE_PROTECTED, }, { "ee.ic.differential_opamp_eqn", 1U, 1U, 1U, 1U,
    NE_RANGE_TYPE_PROTECTED, }, { "ee.ic.differential_opamp_eqn", 1U, 1U, 1U, 1U,
    NE_RANGE_TYPE_PROTECTED, }, { "ee.ic.differential_opamp_eqn", 1U, 1U, 1U, 1U,
    NE_RANGE_TYPE_PROTECTED, }, { "ee.ic.differential_opamp_eqn", 1U, 1U, 1U, 1U,
    NE_RANGE_TYPE_PROTECTED, }, { "ee.ic.differential_opamp_eqn", 1U, 1U, 1U, 1U,
    NE_RANGE_TYPE_PROTECTED, }, { "ee.ic.differential_opamp_eqn", 1U, 1U, 1U, 1U,
    NE_RANGE_TYPE_PROTECTED, }, { "ee.ic.differential_opamp_eqn", 1U, 1U, 1U, 1U,
    NE_RANGE_TYPE_PROTECTED, }, { "ee.passive.capacitor", 1U, 1U, 1U, 1U,
    NE_RANGE_TYPE_PROTECTED, }, { "ee.passive.capacitor", 1U, 1U, 1U, 1U,
    NE_RANGE_TYPE_PROTECTED, }, { "ee.passive.capacitor", 1U, 1U, 1U, 1U,
    NE_RANGE_TYPE_PROTECTED, }, { "ee.sources.voltage_source", 1U, 1U, 1U, 1U,
    NE_RANGE_TYPE_PROTECTED, }, { "ee.sources.voltage_source", 1U, 1U, 1U, 1U,
    NE_RANGE_TYPE_PROTECTED, }, { "foundation.electrical.branch", 23U, 5U, 23U,
    19U, NE_RANGE_TYPE_NORMAL, }, { "foundation.electrical.branch", 23U, 5U, 23U,
    19U, NE_RANGE_TYPE_NORMAL, }, {
    "foundation.electrical.elements.variable_resistor", 58U, 8U, 58U, 16U,
    NE_RANGE_TYPE_NORMAL, }, {
    "foundation.electrical.elements.variable_resistor", 59U, 9U, 59U, 17U,
    NE_RANGE_TYPE_NORMAL, }, {
    "foundation.electrical.elements.variable_resistor", 61U, 9U, 61U, 20U,
    NE_RANGE_TYPE_NORMAL, }, {
    "foundation.electrical.elements.variable_resistor", 58U, 8U, 58U, 16U,
    NE_RANGE_TYPE_NORMAL, }, {
    "foundation.electrical.elements.variable_resistor", 59U, 9U, 59U, 17U,
    NE_RANGE_TYPE_NORMAL, }, {
    "foundation.electrical.elements.variable_resistor", 61U, 9U, 61U, 20U,
    NE_RANGE_TYPE_NORMAL, }, {
    "foundation.electrical.elements.variable_resistor", 58U, 8U, 58U, 16U,
    NE_RANGE_TYPE_NORMAL, }, {
    "foundation.electrical.elements.variable_resistor", 59U, 9U, 59U, 17U,
    NE_RANGE_TYPE_NORMAL, }, {
    "foundation.electrical.elements.variable_resistor", 61U, 9U, 61U, 20U,
    NE_RANGE_TYPE_NORMAL, }, {
    "foundation.electrical.elements.variable_resistor", 58U, 8U, 58U, 16U,
    NE_RANGE_TYPE_NORMAL, }, {
    "foundation.electrical.elements.variable_resistor", 59U, 9U, 59U, 17U,
    NE_RANGE_TYPE_NORMAL, }, {
    "foundation.electrical.elements.variable_resistor", 61U, 9U, 61U, 20U,
    NE_RANGE_TYPE_NORMAL, }, { "foundation.electrical.elements.capacitor", 35U,
    5U, 35U, 18U, NE_RANGE_TYPE_NORMAL, }, {
    "foundation.electrical.elements.capacitor", 35U, 5U, 35U, 18U,
    NE_RANGE_TYPE_NORMAL, }, { "ee.passive.capacitor", 1U, 1U, 1U, 1U,
    NE_RANGE_TYPE_PROTECTED, }, { "", 1U, 1U, 1U, 1U, NE_RANGE_TYPE_PROTECTED, },
  { "ee.ic.differential_opamp_eqn", 1U, 1U, 1U, 1U, NE_RANGE_TYPE_PROTECTED, },
    { "foundation.electrical.branch", 19U, 5U, 19U, 6U, NE_RANGE_TYPE_NORMAL, },
  { "", 1U, 1U, 1U, 1U, NE_RANGE_TYPE_PROTECTED, }, { "ee.passive.capacitor", 1U,
    1U, 1U, 1U, NE_RANGE_TYPE_PROTECTED, }, { "foundation.electrical.branch",
    19U, 5U, 19U, 6U, NE_RANGE_TYPE_NORMAL, }, { "", 1U, 1U, 1U, 1U,
    NE_RANGE_TYPE_PROTECTED, }, { "ee.sources.voltage_source", 1U, 1U, 1U, 1U,
    NE_RANGE_TYPE_PROTECTED, }, { "foundation.electrical.branch", 19U, 5U, 19U,
    6U, NE_RANGE_TYPE_NORMAL, }, { "", 1U, 1U, 1U, 1U, NE_RANGE_TYPE_PROTECTED,
  }, { "ee.sources.voltage_source", 1U, 1U, 1U, 1U, NE_RANGE_TYPE_PROTECTED, },
    { "foundation.electrical.branch", 19U, 5U, 19U, 6U, NE_RANGE_TYPE_NORMAL, },
  { "", 1U, 1U, 1U, 1U, NE_RANGE_TYPE_PROTECTED, }, { "ee.passive.capacitor", 1U,
    1U, 1U, 1U, NE_RANGE_TYPE_PROTECTED, }, { "foundation.electrical.branch",
    19U, 5U, 19U, 6U, NE_RANGE_TYPE_NORMAL, } };

static NeRange *s_cer_range = NULL;
static NeRange *s_icr_range = NULL;
static NeParameterData *s_logical_parameter_data = NULL;
static NeParameterData *s_integer_parameter_data = NULL;
static NeParameterData *s_index_parameter_data = NULL;
static NeParameterData *s_real_parameter_data = NULL;
static NeDsMethodOutput *ds_output_mcon_p(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mMCON_P.mNumCol = 24;
  out->mMCON_P.mNumRow = 24;
  out->mMCON_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    25);
  out->mMCON_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    6);
  return out;
}

static NeDsMethodOutput *ds_output_mcon(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mMCON.mN = 6;
  out->mMCON.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 6);
  return out;
}

static NeDsMethodOutput *ds_output_mpar_p(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mMPAR_P.mNumCol = 24;
  out->mMPAR_P.mNumRow = 24;
  out->mMPAR_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    25);
  out->mMPAR_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_mpar(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mMPAR.mN = 0;
  out->mMPAR.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_mnl_p(const NeDynamicSystem *ds, PmAllocator *
  allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mMNL_P.mNumCol = 24;
  out->mMNL_P.mNumRow = 24;
  out->mMNL_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    25);
  out->mMNL_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    2);
  return out;
}

static NeDsMethodOutput *ds_output_mnl(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mMNL.mN = 2;
  out->mMNL.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 2);
  return out;
}

static NeDsMethodOutput *ds_output_vmm(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mVMM.mN = 8;
  out->mVMM.mX = (boolean_T *) allocator->mCallocFcn(allocator, sizeof(boolean_T),
    8);
  return out;
}

static NeDsMethodOutput *ds_output_dxm_p(const NeDynamicSystem *ds, PmAllocator *
  allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDXM_P.mNumCol = 24;
  out->mDXM_P.mNumRow = 8;
  out->mDXM_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    25);
  out->mDXM_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_dxm(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDXM.mN = 0;
  out->mDXM.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_ddm_p(const NeDynamicSystem *ds, PmAllocator *
  allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDDM_P.mNumCol = 0;
  out->mDDM_P.mNumRow = 8;
  out->mDDM_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    1);
  out->mDDM_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_ddm(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDDM.mN = 0;
  out->mDDM.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_dum_p(const NeDynamicSystem *ds, PmAllocator *
  allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDUM_P.mNumCol = 4;
  out->mDUM_P.mNumRow = 8;
  out->mDUM_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    5);
  out->mDUM_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_dum(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDUM.mN = 0;
  out->mDUM.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_dtm_p(const NeDynamicSystem *ds, PmAllocator *
  allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDTM_P.mNumCol = 1;
  out->mDTM_P.mNumRow = 8;
  out->mDTM_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    2);
  out->mDTM_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_dtm(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDTM.mN = 0;
  out->mDTM.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_dpm_p(const NeDynamicSystem *ds, PmAllocator *
  allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDPM_P.mNumCol = 0;
  out->mDPM_P.mNumRow = 8;
  out->mDPM_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    1);
  out->mDPM_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_dpm(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDPM.mN = 0;
  out->mDPM.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_acon_p(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mACON_P.mNumCol = 24;
  out->mACON_P.mNumRow = 24;
  out->mACON_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    25);
  out->mACON_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    83);
  return out;
}

static NeDsMethodOutput *ds_output_acon(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mACON.mN = 83;
  out->mACON.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 83);
  return out;
}

static NeDsMethodOutput *ds_output_apar_p(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mAPAR_P.mNumCol = 24;
  out->mAPAR_P.mNumRow = 24;
  out->mAPAR_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    25);
  out->mAPAR_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_apar(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mAPAR.mN = 0;
  out->mAPAR.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_bcon_p(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mBCON_P.mNumCol = 4;
  out->mBCON_P.mNumRow = 24;
  out->mBCON_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    5);
  out->mBCON_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_bcon(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mBCON.mN = 0;
  out->mBCON.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_bpar_p(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mBPAR_P.mNumCol = 4;
  out->mBPAR_P.mNumRow = 24;
  out->mBPAR_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    5);
  out->mBPAR_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_bpar(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mBPAR.mN = 0;
  out->mBPAR.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_ccon_p(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mCCON_P.mNumCol = 1;
  out->mCCON_P.mNumRow = 24;
  out->mCCON_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    2);
  out->mCCON_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_ccon(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mCCON.mN = 0;
  out->mCCON.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_cpar_p(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mCPAR_P.mNumCol = 1;
  out->mCPAR_P.mNumRow = 24;
  out->mCPAR_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    2);
  out->mCPAR_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_cpar(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mCPAR.mN = 0;
  out->mCPAR.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_f(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mF.mN = 24;
  out->mF.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 24);
  return out;
}

static NeDsMethodOutput *ds_output_vmf(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mVMF.mN = 24;
  out->mVMF.mX = (boolean_T *) allocator->mCallocFcn(allocator, sizeof(boolean_T),
    24);
  return out;
}

static NeDsMethodOutput *ds_output_vpf(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mVPF.mN = 24;
  out->mVPF.mX = (boolean_T *) allocator->mCallocFcn(allocator, sizeof(boolean_T),
    24);
  return out;
}

static NeDsMethodOutput *ds_output_vsf(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mVSF.mN = 24;
  out->mVSF.mX = (boolean_T *) allocator->mCallocFcn(allocator, sizeof(boolean_T),
    24);
  return out;
}

static NeDsMethodOutput *ds_output_slf(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mSLF.mN = 24;
  out->mSLF.mX = (boolean_T *) allocator->mCallocFcn(allocator, sizeof(boolean_T),
    24);
  return out;
}

static NeDsMethodOutput *ds_output_slf0(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mSLF0.mN = 24;
  out->mSLF0.mX = (boolean_T *) allocator->mCallocFcn(allocator, sizeof
    (boolean_T), 24);
  return out;
}

static NeDsMethodOutput *ds_output_dxf_p(const NeDynamicSystem *ds, PmAllocator *
  allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDXF_P.mNumCol = 24;
  out->mDXF_P.mNumRow = 24;
  out->mDXF_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    25);
  out->mDXF_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    19);
  return out;
}

static NeDsMethodOutput *ds_output_dxf(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDXF.mN = 19;
  out->mDXF.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 19);
  return out;
}

static NeDsMethodOutput *ds_output_duf_p(const NeDynamicSystem *ds, PmAllocator *
  allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDUF_P.mNumCol = 4;
  out->mDUF_P.mNumRow = 24;
  out->mDUF_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    5);
  out->mDUF_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    4);
  return out;
}

static NeDsMethodOutput *ds_output_duf(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDUF.mN = 4;
  out->mDUF.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 4);
  return out;
}

static NeDsMethodOutput *ds_output_dtf_p(const NeDynamicSystem *ds, PmAllocator *
  allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDTF_P.mNumCol = 1;
  out->mDTF_P.mNumRow = 24;
  out->mDTF_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    2);
  out->mDTF_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    2);
  return out;
}

static NeDsMethodOutput *ds_output_dtf(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDTF.mN = 2;
  out->mDTF.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 2);
  return out;
}

static NeDsMethodOutput *ds_output_ddf_p(const NeDynamicSystem *ds, PmAllocator *
  allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDDF_P.mNumCol = 0;
  out->mDDF_P.mNumRow = 24;
  out->mDDF_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    1);
  out->mDDF_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_ddf(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDDF.mN = 0;
  out->mDDF.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_dpdxf_p(const NeDynamicSystem *ds,
  PmAllocator *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDPDXF_P.mNumCol = 0;
  out->mDPDXF_P.mNumRow = 19;
  out->mDPDXF_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof
    (int32_T), 1);
  out->mDPDXF_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof
    (int32_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_dpdxf(const NeDynamicSystem *ds, PmAllocator *
  allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDPDXF.mN = 0;
  out->mDPDXF.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_dwf_p(const NeDynamicSystem *ds, PmAllocator *
  allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDWF_P.mNumCol = 0;
  out->mDWF_P.mNumRow = 24;
  out->mDWF_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    1);
  out->mDWF_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_dwf(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDWF.mN = 0;
  out->mDWF.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_tduf_p(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mTDUF_P.mNumCol = 4;
  out->mTDUF_P.mNumRow = 24;
  out->mTDUF_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    5);
  out->mTDUF_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    4);
  return out;
}

static NeDsMethodOutput *ds_output_tdxf_p(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mTDXF_P.mNumCol = 24;
  out->mTDXF_P.mNumRow = 24;
  out->mTDXF_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    25);
  out->mTDXF_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    102);
  return out;
}

static NeDsMethodOutput *ds_output_dnf_p(const NeDynamicSystem *ds, PmAllocator *
  allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDNF_P.mNumCol = 31;
  out->mDNF_P.mNumRow = 24;
  out->mDNF_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    32);
  out->mDNF_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    4);
  return out;
}

static NeDsMethodOutput *ds_output_dnf(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDNF.mN = 4;
  out->mDNF.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 4);
  return out;
}

static NeDsMethodOutput *ds_output_dnf_v_x(const NeDynamicSystem *ds,
  PmAllocator *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDNF_V_X.mN = 24;
  out->mDNF_V_X.mX = (boolean_T *) allocator->mCallocFcn(allocator, sizeof
    (boolean_T), 24);
  return out;
}

static NeDsMethodOutput *ds_output_cer(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mCER.mN = 0;
  out->mCER.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_dxcer(const NeDynamicSystem *ds, PmAllocator *
  allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDXCER.mN = 0;
  out->mDXCER.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_dxcer_p(const NeDynamicSystem *ds,
  PmAllocator *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDXCER_P.mNumCol = 24;
  out->mDXCER_P.mNumRow = 0;
  out->mDXCER_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof
    (int32_T), 25);
  out->mDXCER_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof
    (int32_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_ddcer(const NeDynamicSystem *ds, PmAllocator *
  allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDDCER.mN = 0;
  out->mDDCER.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_ddcer_p(const NeDynamicSystem *ds,
  PmAllocator *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDDCER_P.mNumCol = 0;
  out->mDDCER_P.mNumRow = 0;
  out->mDDCER_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof
    (int32_T), 1);
  out->mDDCER_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof
    (int32_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_ic(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mIC.mN = 24;
  out->mIC.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 24);
  return out;
}

static NeDsMethodOutput *ds_output_icr(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mICR.mN = 0;
  out->mICR.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_icr_im(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mICR_IM.mN = 0;
  out->mICR_IM.mX = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_icr_id(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mICR_ID.mN = 0;
  out->mICR_ID.mX = (boolean_T *) allocator->mCallocFcn(allocator, sizeof
    (boolean_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_icr_il(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mICR_IL.mN = 0;
  out->mICR_IL.mX = (boolean_T *) allocator->mCallocFcn(allocator, sizeof
    (boolean_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_dxicr(const NeDynamicSystem *ds, PmAllocator *
  allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDXICR.mN = 0;
  out->mDXICR.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_dxicr_p(const NeDynamicSystem *ds,
  PmAllocator *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDXICR_P.mNumCol = 24;
  out->mDXICR_P.mNumRow = 0;
  out->mDXICR_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof
    (int32_T), 25);
  out->mDXICR_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof
    (int32_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_ddicr(const NeDynamicSystem *ds, PmAllocator *
  allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDDICR.mN = 0;
  out->mDDICR.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_ddicr_p(const NeDynamicSystem *ds,
  PmAllocator *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDDICR_P.mNumCol = 0;
  out->mDDICR_P.mNumRow = 0;
  out->mDDICR_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof
    (int32_T), 1);
  out->mDDICR_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof
    (int32_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_tduicr_p(const NeDynamicSystem *ds,
  PmAllocator *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mTDUICR_P.mNumCol = 4;
  out->mTDUICR_P.mNumRow = 0;
  out->mTDUICR_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof
    (int32_T), 5);
  out->mTDUICR_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof
    (int32_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_icrm_p(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mICRM_P.mNumCol = 24;
  out->mICRM_P.mNumRow = 0;
  out->mICRM_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    25);
  out->mICRM_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_icrm(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mICRM.mN = 0;
  out->mICRM.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_dxicrm_p(const NeDynamicSystem *ds,
  PmAllocator *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDXICRM_P.mNumCol = 24;
  out->mDXICRM_P.mNumRow = 0;
  out->mDXICRM_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof
    (int32_T), 25);
  out->mDXICRM_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof
    (int32_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_dxicrm(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDXICRM.mN = 0;
  out->mDXICRM.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_ddicrm_p(const NeDynamicSystem *ds,
  PmAllocator *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDDICRM_P.mNumCol = 0;
  out->mDDICRM_P.mNumRow = 0;
  out->mDDICRM_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof
    (int32_T), 1);
  out->mDDICRM_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof
    (int32_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_ddicrm(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDDICRM.mN = 0;
  out->mDDICRM.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_freqs(const NeDynamicSystem *ds, PmAllocator *
  allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mFREQS.mN = 1;
  out->mFREQS.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 1);
  return out;
}

static NeDsMethodOutput *ds_output_solverhits(const NeDynamicSystem *ds,
  PmAllocator *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mSOLVERHITS.mN = 0;
  out->mSOLVERHITS.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof
    (real_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_mduy_p(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mMDUY_P.mNumCol = 4;
  out->mMDUY_P.mNumRow = 7;
  out->mMDUY_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    5);
  out->mMDUY_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_mdxy_p(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mMDXY_P.mNumCol = 24;
  out->mMDXY_P.mNumRow = 7;
  out->mMDXY_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    25);
  out->mMDXY_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_tduy_p(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mTDUY_P.mNumCol = 4;
  out->mTDUY_P.mNumRow = 7;
  out->mTDUY_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    5);
  out->mTDUY_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_tdxy_p(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mTDXY_P.mNumCol = 24;
  out->mTDXY_P.mNumRow = 7;
  out->mTDXY_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    25);
  out->mTDXY_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    11);
  return out;
}

static NeDsMethodOutput *ds_output_y(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mY.mN = 7;
  out->mY.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 7);
  return out;
}

static NeDsMethodOutput *ds_output_dxy_p(const NeDynamicSystem *ds, PmAllocator *
  allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDXY_P.mNumCol = 24;
  out->mDXY_P.mNumRow = 7;
  out->mDXY_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    25);
  out->mDXY_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    11);
  return out;
}

static NeDsMethodOutput *ds_output_dxy(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDXY.mN = 11;
  out->mDXY.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 11);
  return out;
}

static NeDsMethodOutput *ds_output_duy_p(const NeDynamicSystem *ds, PmAllocator *
  allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDUY_P.mNumCol = 4;
  out->mDUY_P.mNumRow = 7;
  out->mDUY_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    5);
  out->mDUY_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_duy(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDUY.mN = 0;
  out->mDUY.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_dty_p(const NeDynamicSystem *ds, PmAllocator *
  allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDTY_P.mNumCol = 1;
  out->mDTY_P.mNumRow = 7;
  out->mDTY_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    2);
  out->mDTY_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_dty(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDTY.mN = 0;
  out->mDTY.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_mode(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mMODE.mN = 13;
  out->mMODE.mX = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    13);
  return out;
}

static NeDsMethodOutput *ds_output_zc(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mZC.mN = 13;
  out->mZC.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 13);
  return out;
}

static NeDsMethodOutput *ds_output_cache_r(const NeDynamicSystem *ds,
  PmAllocator *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mCACHE_R.mN = 0;
  out->mCACHE_R.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_cache_i(const NeDynamicSystem *ds,
  PmAllocator *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mCACHE_I.mN = 0;
  out->mCACHE_I.mX = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_update_r(const NeDynamicSystem *ds,
  PmAllocator *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mUPDATE_R.mN = 0;
  out->mUPDATE_R.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_update_i(const NeDynamicSystem *ds,
  PmAllocator *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mUPDATE_I.mN = 4;
  out->mUPDATE_I.mX = (int32_T *) allocator->mCallocFcn(allocator, sizeof
    (int32_T), 4);
  return out;
}

static NeDsMethodOutput *ds_output_update2_r(const NeDynamicSystem *ds,
  PmAllocator *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mUPDATE2_R.mN = 0;
  out->mUPDATE2_R.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_update2_i(const NeDynamicSystem *ds,
  PmAllocator *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mUPDATE2_I.mN = 4;
  out->mUPDATE2_I.mX = (int32_T *) allocator->mCallocFcn(allocator, sizeof
    (int32_T), 4);
  return out;
}

static NeDsMethodOutput *ds_output_lock_r(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mLOCK_R.mN = 0;
  out->mLOCK_R.mX = (boolean_T *) allocator->mCallocFcn(allocator, sizeof
    (boolean_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_lock_i(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mLOCK_I.mN = 4;
  out->mLOCK_I.mX = (boolean_T *) allocator->mCallocFcn(allocator, sizeof
    (boolean_T), 4);
  return out;
}

static NeDsMethodOutput *ds_output_lock2_r(const NeDynamicSystem *ds,
  PmAllocator *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mLOCK2_R.mN = 0;
  out->mLOCK2_R.mX = (boolean_T *) allocator->mCallocFcn(allocator, sizeof
    (boolean_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_lock2_i(const NeDynamicSystem *ds,
  PmAllocator *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mLOCK2_I.mN = 4;
  out->mLOCK2_I.mX = (boolean_T *) allocator->mCallocFcn(allocator, sizeof
    (boolean_T), 4);
  return out;
}

static NeDsMethodOutput *ds_output_sfo(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mSFO.mN = 2;
  out->mSFO.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 2);
  return out;
}

static NeDsMethodOutput *ds_output_sfp(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mSFP.mN = 2;
  out->mSFP.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 2);
  return out;
}

static NeDsMethodOutput *ds_output_init_r(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mINIT_R.mN = 0;
  out->mINIT_R.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_init_i(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mINIT_I.mN = 4;
  out->mINIT_I.mX = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    4);
  return out;
}

static NeDsMethodOutput *ds_output_log(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mLOG.mN = 216;
  out->mLOG.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 216);
  return out;
}

static NeDsMethodOutput *ds_output_assert(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mASSERT.mN = 56;
  out->mASSERT.mX = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    56);
  return out;
}

static NeDsMethodOutput *ds_output_passert(const NeDynamicSystem *ds,
  PmAllocator *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mPASSERT.mN = 0;
  out->mPASSERT.mX = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_iassert(const NeDynamicSystem *ds,
  PmAllocator *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mIASSERT.mN = 0;
  out->mIASSERT.mX = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_del_t(const NeDynamicSystem *ds, PmAllocator *
  allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDEL_T.mN = 0;
  out->mDEL_T.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_del_v(const NeDynamicSystem *ds, PmAllocator *
  allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDEL_V.mN = 0;
  out->mDEL_V.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_del_v0(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDEL_V0.mN = 0;
  out->mDEL_V0.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_del_tmax(const NeDynamicSystem *ds,
  PmAllocator *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDEL_TMAX.mN = 0;
  out->mDEL_TMAX.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_dxdelt_p(const NeDynamicSystem *ds,
  PmAllocator *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDXDELT_P.mNumCol = 24;
  out->mDXDELT_P.mNumRow = 0;
  out->mDXDELT_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof
    (int32_T), 25);
  out->mDXDELT_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof
    (int32_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_dxdelt(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDXDELT.mN = 0;
  out->mDXDELT.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_dudelt_p(const NeDynamicSystem *ds,
  PmAllocator *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDUDELT_P.mNumCol = 4;
  out->mDUDELT_P.mNumRow = 0;
  out->mDUDELT_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof
    (int32_T), 5);
  out->mDUDELT_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof
    (int32_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_dudelt(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDUDELT.mN = 0;
  out->mDUDELT.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_dtdelt_p(const NeDynamicSystem *ds,
  PmAllocator *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDTDELT_P.mNumCol = 1;
  out->mDTDELT_P.mNumRow = 0;
  out->mDTDELT_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof
    (int32_T), 2);
  out->mDTDELT_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof
    (int32_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_dtdelt(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDTDELT.mN = 0;
  out->mDTDELT.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_obs_exp(const NeDynamicSystem *ds,
  PmAllocator *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mOBS_EXP.mN = 279;
  out->mOBS_EXP.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T),
    279);
  return out;
}

static NeDsMethodOutput *ds_output_obs_act(const NeDynamicSystem *ds,
  PmAllocator *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mOBS_ACT.mN = 279;
  out->mOBS_ACT.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T),
    279);
  return out;
}

static NeDsMethodOutput *ds_output_obs_all(const NeDynamicSystem *ds,
  PmAllocator *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mOBS_ALL.mN = 279;
  out->mOBS_ALL.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T),
    279);
  return out;
}

static NeDsMethodOutput *ds_output_obs_il(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mOBS_IL.mN = 279;
  out->mOBS_IL.mX = (boolean_T *) allocator->mCallocFcn(allocator, sizeof
    (boolean_T), 279);
  return out;
}

static NeDsMethodOutput *ds_output_dp_l(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDP_L.mN = 0;
  out->mDP_L.mX = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_dp_i(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDP_I.mN = 0;
  out->mDP_I.mX = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_dp_j(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDP_J.mN = 0;
  out->mDP_J.mX = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_dp_r(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDP_R.mN = 0;
  out->mDP_R.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_qx(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mQX.mN = 0;
  out->mQX.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_qu(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mQU.mN = 0;
  out->mQU.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_qt(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mQT.mN = 0;
  out->mQT.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_q1(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mQ1.mN = 0;
  out->mQ1.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_qx_p(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mQX_P.mNumCol = 24;
  out->mQX_P.mNumRow = 24;
  out->mQX_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    25);
  out->mQX_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_qu_p(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mQU_P.mNumCol = 4;
  out->mQU_P.mNumRow = 24;
  out->mQU_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    5);
  out->mQU_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_qt_p(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mQT_P.mNumCol = 1;
  out->mQT_P.mNumRow = 24;
  out->mQT_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    2);
  out->mQT_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_q1_p(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mQ1_P.mNumCol = 1;
  out->mQ1_P.mNumRow = 24;
  out->mQ1_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    2);
  out->mQ1_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_var_tol(const NeDynamicSystem *ds,
  PmAllocator *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mVAR_TOL.mN = 24;
  out->mVAR_TOL.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T),
    24);
  return out;
}

static NeDsMethodOutput *ds_output_eq_tol(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mEQ_TOL.mN = 24;
  out->mEQ_TOL.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T),
    24);
  return out;
}

static NeDsMethodOutput *ds_output_lv(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mLV.mN = 24;
  out->mLV.mX = (boolean_T *) allocator->mCallocFcn(allocator, sizeof(boolean_T),
    24);
  return out;
}

static NeDsMethodOutput *ds_output_slv(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mSLV.mN = 24;
  out->mSLV.mX = (boolean_T *) allocator->mCallocFcn(allocator, sizeof(boolean_T),
    24);
  return out;
}

static NeDsMethodOutput *ds_output_nldv(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mNLDV.mN = 24;
  out->mNLDV.mX = (boolean_T *) allocator->mCallocFcn(allocator, sizeof
    (boolean_T), 24);
  return out;
}

static NeDsMethodOutput *ds_output_sclv(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mSCLV.mN = 24;
  out->mSCLV.mX = (boolean_T *) allocator->mCallocFcn(allocator, sizeof
    (boolean_T), 24);
  return out;
}

static NeDsMethodOutput *ds_output_imin(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mIMIN.mN = 24;
  out->mIMIN.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 24);
  return out;
}

static NeDsMethodOutput *ds_output_imax(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mIMAX.mN = 24;
  out->mIMAX.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 24);
  return out;
}

static NeDsMethodOutput *ds_output_dimin(const NeDynamicSystem *ds, PmAllocator *
  allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDIMIN.mN = 0;
  out->mDIMIN.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_dimax(const NeDynamicSystem *ds, PmAllocator *
  allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDIMAX.mN = 0;
  out->mDIMAX.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 0);
  return out;
}

static void release_reference(NeDynamicSystem *ds)
{
  _NeDynamicSystem *_ds;
  _ds = (_NeDynamicSystem *)ds;
  if (--_ds->mRefCnt == 0) {
    _ds->mAlloc.mFreeFcn(&_ds->mAlloc, _ds);
  }
}

static void get_reference(NeDynamicSystem *ds)
{
  _NeDynamicSystem *_ds;
  _ds = (_NeDynamicSystem *)ds;
  ++_ds->mRefCnt;
}

static NeDynamicSystem *diagnostics(NeDynamicSystem *ds, boolean_T kp)
{
  _NeDynamicSystem *_ds = (_NeDynamicSystem *)ds;
  (void) kp;
  ne_ds_get_reference(&_ds->mBase);
  return &_ds->mBase;
}

static void expand(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
                   PmRealVector *out, boolean_T kp)
{
  (void)ds;
  (void)kp;
  memcpy(out->mX, in->mX.mX, sizeof(real_T)*out->mN);
}

static void rtpmap(const NeDynamicSystem * ds, const PmIntVector* inl, const
                   PmIntVector* ini, const PmIntVector* inj, const PmRealVector*
                   inr, PmIntVector* outl, PmIntVector* outi, PmIntVector* outj,
                   PmRealVector* outr)
{
  (void)ds;
  memcpy(outl->mX, inl->mX, sizeof(int32_T)*inl->mN);
  memcpy(outi->mX, ini->mX, sizeof(int32_T)*ini->mN);
  memcpy(outj->mX, inj->mX, sizeof(int32_T)*inj->mN);
  memcpy(outr->mX, inr->mX, sizeof(real_T)*inr->mN);
}

NeDynamicSystem *ozysdriverandreceiver_d22bbe4d_49_dae_ds(PmAllocator *allocator)
{
  NeDynamicSystem *ds;
  _NeDynamicSystem *_ds;
  static SscIoInfo input_info[4];
  static SscIoInfo output_info[7];

  /* allocate dynamic system data and extended data */
  _ds = (_NeDynamicSystem *)allocator->mCallocFcn( allocator, sizeof
    (_NeDynamicSystem), 1);
  _ds->mAlloc = *allocator;
  _ds->mRefCnt = 1;
  ds = &_ds->mBase;

  /* setup sizes */
  ds->mNumVariables = 24;
  ds->mNumDiscreteRealVariables = 0;
  ds->mNumDifferentialVariables = 8;
  ds->mNumEquations = 24;
  ds->mNumCEResiduals = 0;
  ds->mNumICResiduals = 0;
  ds->mNumFreqs = 1;
  ds->mNumSolverHits = 0;
  ds->mNumModes = 13;
  ds->mNumMajorModes = 4;
  ds->mNumRealCache = 0;
  ds->mNumIntCache = 0;
  ds->mNumObservables = 304;
  ds->mNumObservableElements = 279;
  ds->mNumZcs = 13;
  ds->mNumAsserts = 56;
  ds->mNumAssertRanges = 56;
  ds->mNumParamAsserts = 0;
  ds->mNumParamAssertRanges = 0;
  ds->mNumInitialAsserts = 0;
  ds->mNumInitialAssertRanges = 0;
  ds->mNumRanges = 14;
  ds->mNumEquationRanges = 56;
  ds->mNumCERRanges = 0;
  ds->mNumICRRanges = 0;
  ds->mNumFundamentalSamples = 2;
  ds->mNumDelays = 0;
  ds->mNumLogicalParameters = 0;
  ds->mNumIntegerParameters = 0;
  ds->mNumIndexParameters = 0;
  ds->mNumRealParameters = 0;
  ds->mNumLogicalDerivedParameters = 0;
  ds->mNumIntegerDerivedParameters = 0;
  ds->mNumIndexDerivedParameters = 0;
  ds->mNumRealDerivedParameters = 0;
  ds->mIsOutputLinear = TRUE;
  ds->mIsOutputSwitchedLinear = TRUE;
  ds->mIsScalable = FALSE;

  /* setup ios */
  ds->mNumIo[SSC_INPUT_IO_TYPE] = 4;
  input_info[0].identifier = "SG.Simulink_PS_Converter1_output0";
  input_info[0].size.numElements = 1;
  input_info[0].size.encodedDimensions = "1x1";
  input_info[0].name = "SG.Simulink_PS_Converter1_output0";
  input_info[0].unit = "1";
  input_info[1].identifier = "SG.Simulink_PS_Converter2_output0";
  input_info[1].size.numElements = 1;
  input_info[1].size.encodedDimensions = "1x1";
  input_info[1].name = "SG.Simulink_PS_Converter2_output0";
  input_info[1].unit = "1";
  input_info[2].identifier = "SG.Simulink_PS_Converter3_output0";
  input_info[2].size.numElements = 1;
  input_info[2].size.encodedDimensions = "1x1";
  input_info[2].name = "SG.Simulink_PS_Converter3_output0";
  input_info[2].unit = "1";
  input_info[3].identifier = "SG.Simulink_PS_Converter_output0";
  input_info[3].size.numElements = 1;
  input_info[3].size.encodedDimensions = "1x1";
  input_info[3].name = "SG.Simulink_PS_Converter_output0";
  input_info[3].unit = "1";
  ds->mIo[SSC_INPUT_IO_TYPE] = input_info;
  ds->mNumIo[SSC_OUTPUT_IO_TYPE] = 7;
  output_info[0].identifier = "Voltage_Sensor1_V0";
  output_info[0].size.numElements = 1;
  output_info[0].size.encodedDimensions = "1x1";
  output_info[0].name = "Voltage_Sensor1_V0";
  output_info[0].unit = "V";
  output_info[1].identifier = "Voltage_Sensor2_V0";
  output_info[1].size.numElements = 1;
  output_info[1].size.encodedDimensions = "1x1";
  output_info[1].name = "Voltage_Sensor2_V0";
  output_info[1].unit = "V";
  output_info[2].identifier = "Voltage_Sensor3_V0";
  output_info[2].size.numElements = 1;
  output_info[2].size.encodedDimensions = "1x1";
  output_info[2].name = "Voltage_Sensor3_V0";
  output_info[2].unit = "V";
  output_info[3].identifier = "Voltage_Sensor4_V0";
  output_info[3].size.numElements = 1;
  output_info[3].size.encodedDimensions = "1x1";
  output_info[3].name = "Voltage_Sensor4_V0";
  output_info[3].unit = "V";
  output_info[4].identifier = "Voltage_Sensor5_V0";
  output_info[4].size.numElements = 1;
  output_info[4].size.encodedDimensions = "1x1";
  output_info[4].name = "Voltage_Sensor5_V0";
  output_info[4].unit = "V";
  output_info[5].identifier = "Voltage_Sensor7_V0";
  output_info[5].size.numElements = 1;
  output_info[5].size.encodedDimensions = "1x1";
  output_info[5].name = "Voltage_Sensor7_V0";
  output_info[5].unit = "V";
  output_info[6].identifier = "Voltage_Sensor_V0";
  output_info[6].size.numElements = 1;
  output_info[6].size.encodedDimensions = "1x1";
  output_info[6].name = "Voltage_Sensor_V0";
  output_info[6].unit = "V";
  ds->mIo[SSC_OUTPUT_IO_TYPE] = output_info;

  /* setup administration methods */
  ds->mReleaseReference = release_reference;
  ds->mGetReference = get_reference;
  ds->mDiagnosticsDsFcn = diagnostics;
  ds->mExpandFcn = expand;
  ds->mRtpMapFcn = rtpmap;
  ds->mMethods[NE_DS_METHOD_MCON_P] =
    ozysdriverandreceiver_d22bbe4d_49_ds_mcon_p;
  ds->mMakeOutput[NE_DS_METHOD_MCON_P] = ds_output_mcon_p;
  ds->mMethods[NE_DS_METHOD_MCON] = ds_mcon;
  ds->mMakeOutput[NE_DS_METHOD_MCON] = ds_output_mcon;
  ds->mMethods[NE_DS_METHOD_MPAR_P] = ds_mpar_p;
  ds->mMakeOutput[NE_DS_METHOD_MPAR_P] = ds_output_mpar_p;
  ds->mMethods[NE_DS_METHOD_MPAR] = ds_mpar;
  ds->mMakeOutput[NE_DS_METHOD_MPAR] = ds_output_mpar;
  ds->mMethods[NE_DS_METHOD_MNL_P] = ozysdriverandreceiver_d22bbe4d_49_ds_mnl_p;
  ds->mMakeOutput[NE_DS_METHOD_MNL_P] = ds_output_mnl_p;
  ds->mMethods[NE_DS_METHOD_MNL] = ds_mnl;
  ds->mMakeOutput[NE_DS_METHOD_MNL] = ds_output_mnl;
  ds->mMethods[NE_DS_METHOD_VMM] = ds_vmm;
  ds->mMakeOutput[NE_DS_METHOD_VMM] = ds_output_vmm;
  ds->mMethods[NE_DS_METHOD_DXM_P] = ds_dxm_p;
  ds->mMakeOutput[NE_DS_METHOD_DXM_P] = ds_output_dxm_p;
  ds->mMethods[NE_DS_METHOD_DXM] = ds_dxm;
  ds->mMakeOutput[NE_DS_METHOD_DXM] = ds_output_dxm;
  ds->mMethods[NE_DS_METHOD_DDM_P] = ds_ddm_p;
  ds->mMakeOutput[NE_DS_METHOD_DDM_P] = ds_output_ddm_p;
  ds->mMethods[NE_DS_METHOD_DDM] = ds_ddm;
  ds->mMakeOutput[NE_DS_METHOD_DDM] = ds_output_ddm;
  ds->mMethods[NE_DS_METHOD_DUM_P] = ds_dum_p;
  ds->mMakeOutput[NE_DS_METHOD_DUM_P] = ds_output_dum_p;
  ds->mMethods[NE_DS_METHOD_DUM] = ds_dum;
  ds->mMakeOutput[NE_DS_METHOD_DUM] = ds_output_dum;
  ds->mMethods[NE_DS_METHOD_DTM_P] = ds_dtm_p;
  ds->mMakeOutput[NE_DS_METHOD_DTM_P] = ds_output_dtm_p;
  ds->mMethods[NE_DS_METHOD_DTM] = ds_dtm;
  ds->mMakeOutput[NE_DS_METHOD_DTM] = ds_output_dtm;
  ds->mMethods[NE_DS_METHOD_DPM_P] = ds_dpm_p;
  ds->mMakeOutput[NE_DS_METHOD_DPM_P] = ds_output_dpm_p;
  ds->mMethods[NE_DS_METHOD_DPM] = ds_dpm;
  ds->mMakeOutput[NE_DS_METHOD_DPM] = ds_output_dpm;
  ds->mMethods[NE_DS_METHOD_ACON_P] =
    ozysdriverandreceiver_d22bbe4d_49_ds_acon_p;
  ds->mMakeOutput[NE_DS_METHOD_ACON_P] = ds_output_acon_p;
  ds->mMethods[NE_DS_METHOD_ACON] = ozysdriverandreceiver_d22bbe4d_49_ds_acon;
  ds->mMakeOutput[NE_DS_METHOD_ACON] = ds_output_acon;
  ds->mMethods[NE_DS_METHOD_APAR_P] = ds_apar_p;
  ds->mMakeOutput[NE_DS_METHOD_APAR_P] = ds_output_apar_p;
  ds->mMethods[NE_DS_METHOD_APAR] = ds_apar;
  ds->mMakeOutput[NE_DS_METHOD_APAR] = ds_output_apar;
  ds->mMethods[NE_DS_METHOD_BCON_P] = ds_bcon_p;
  ds->mMakeOutput[NE_DS_METHOD_BCON_P] = ds_output_bcon_p;
  ds->mMethods[NE_DS_METHOD_BCON] = ds_bcon;
  ds->mMakeOutput[NE_DS_METHOD_BCON] = ds_output_bcon;
  ds->mMethods[NE_DS_METHOD_BPAR_P] = ds_bpar_p;
  ds->mMakeOutput[NE_DS_METHOD_BPAR_P] = ds_output_bpar_p;
  ds->mMethods[NE_DS_METHOD_BPAR] = ds_bpar;
  ds->mMakeOutput[NE_DS_METHOD_BPAR] = ds_output_bpar;
  ds->mMethods[NE_DS_METHOD_CCON_P] = ds_ccon_p;
  ds->mMakeOutput[NE_DS_METHOD_CCON_P] = ds_output_ccon_p;
  ds->mMethods[NE_DS_METHOD_CCON] = ds_ccon;
  ds->mMakeOutput[NE_DS_METHOD_CCON] = ds_output_ccon;
  ds->mMethods[NE_DS_METHOD_CPAR_P] = ds_cpar_p;
  ds->mMakeOutput[NE_DS_METHOD_CPAR_P] = ds_output_cpar_p;
  ds->mMethods[NE_DS_METHOD_CPAR] = ds_cpar;
  ds->mMakeOutput[NE_DS_METHOD_CPAR] = ds_output_cpar;
  ds->mMethods[NE_DS_METHOD_F] = ozysdriverandreceiver_d22bbe4d_49_ds_f;
  ds->mMakeOutput[NE_DS_METHOD_F] = ds_output_f;
  ds->mMethods[NE_DS_METHOD_VMF] = ozysdriverandreceiver_d22bbe4d_49_ds_vmf;
  ds->mMakeOutput[NE_DS_METHOD_VMF] = ds_output_vmf;
  ds->mMethods[NE_DS_METHOD_VPF] = ds_vpf;
  ds->mMakeOutput[NE_DS_METHOD_VPF] = ds_output_vpf;
  ds->mMethods[NE_DS_METHOD_VSF] = ds_vsf;
  ds->mMakeOutput[NE_DS_METHOD_VSF] = ds_output_vsf;
  ds->mMethods[NE_DS_METHOD_SLF] = ds_slf;
  ds->mMakeOutput[NE_DS_METHOD_SLF] = ds_output_slf;
  ds->mMethods[NE_DS_METHOD_SLF0] = ds_slf0;
  ds->mMakeOutput[NE_DS_METHOD_SLF0] = ds_output_slf0;
  ds->mMethods[NE_DS_METHOD_DXF_P] = ozysdriverandreceiver_d22bbe4d_49_ds_dxf_p;
  ds->mMakeOutput[NE_DS_METHOD_DXF_P] = ds_output_dxf_p;
  ds->mMethods[NE_DS_METHOD_DXF] = ozysdriverandreceiver_d22bbe4d_49_ds_dxf;
  ds->mMakeOutput[NE_DS_METHOD_DXF] = ds_output_dxf;
  ds->mMethods[NE_DS_METHOD_DUF_P] = ds_duf_p;
  ds->mMakeOutput[NE_DS_METHOD_DUF_P] = ds_output_duf_p;
  ds->mMethods[NE_DS_METHOD_DUF] = ds_duf;
  ds->mMakeOutput[NE_DS_METHOD_DUF] = ds_output_duf;
  ds->mMethods[NE_DS_METHOD_DTF_P] = ds_dtf_p;
  ds->mMakeOutput[NE_DS_METHOD_DTF_P] = ds_output_dtf_p;
  ds->mMethods[NE_DS_METHOD_DTF] = ds_dtf;
  ds->mMakeOutput[NE_DS_METHOD_DTF] = ds_output_dtf;
  ds->mMethods[NE_DS_METHOD_DDF_P] = ds_ddf_p;
  ds->mMakeOutput[NE_DS_METHOD_DDF_P] = ds_output_ddf_p;
  ds->mMethods[NE_DS_METHOD_DDF] = ds_ddf;
  ds->mMakeOutput[NE_DS_METHOD_DDF] = ds_output_ddf;
  ds->mMethods[NE_DS_METHOD_DPDXF_P] = ds_dpdxf_p;
  ds->mMakeOutput[NE_DS_METHOD_DPDXF_P] = ds_output_dpdxf_p;
  ds->mMethods[NE_DS_METHOD_DPDXF] = ds_dpdxf;
  ds->mMakeOutput[NE_DS_METHOD_DPDXF] = ds_output_dpdxf;
  ds->mMethods[NE_DS_METHOD_DWF_P] = ds_dwf_p;
  ds->mMakeOutput[NE_DS_METHOD_DWF_P] = ds_output_dwf_p;
  ds->mMethods[NE_DS_METHOD_DWF] = ds_dwf;
  ds->mMakeOutput[NE_DS_METHOD_DWF] = ds_output_dwf;
  ds->mMethods[NE_DS_METHOD_TDUF_P] = ds_tduf_p;
  ds->mMakeOutput[NE_DS_METHOD_TDUF_P] = ds_output_tduf_p;
  ds->mMethods[NE_DS_METHOD_TDXF_P] =
    ozysdriverandreceiver_d22bbe4d_49_ds_tdxf_p;
  ds->mMakeOutput[NE_DS_METHOD_TDXF_P] = ds_output_tdxf_p;
  ds->mMethods[NE_DS_METHOD_DNF_P] = ozysdriverandreceiver_d22bbe4d_49_ds_dnf_p;
  ds->mMakeOutput[NE_DS_METHOD_DNF_P] = ds_output_dnf_p;
  ds->mMethods[NE_DS_METHOD_DNF] = ds_dnf;
  ds->mMakeOutput[NE_DS_METHOD_DNF] = ds_output_dnf;
  ds->mMethods[NE_DS_METHOD_DNF_V_X] =
    ozysdriverandreceiver_d22bbe4d_49_ds_dnf_v_x;
  ds->mMakeOutput[NE_DS_METHOD_DNF_V_X] = ds_output_dnf_v_x;
  ds->mMethods[NE_DS_METHOD_CER] = ds_cer;
  ds->mMakeOutput[NE_DS_METHOD_CER] = ds_output_cer;
  ds->mMethods[NE_DS_METHOD_DXCER] = ds_dxcer;
  ds->mMakeOutput[NE_DS_METHOD_DXCER] = ds_output_dxcer;
  ds->mMethods[NE_DS_METHOD_DXCER_P] = ds_dxcer_p;
  ds->mMakeOutput[NE_DS_METHOD_DXCER_P] = ds_output_dxcer_p;
  ds->mMethods[NE_DS_METHOD_DDCER] = ds_ddcer;
  ds->mMakeOutput[NE_DS_METHOD_DDCER] = ds_output_ddcer;
  ds->mMethods[NE_DS_METHOD_DDCER_P] = ds_ddcer_p;
  ds->mMakeOutput[NE_DS_METHOD_DDCER_P] = ds_output_ddcer_p;
  ds->mMethods[NE_DS_METHOD_IC] = ds_ic;
  ds->mMakeOutput[NE_DS_METHOD_IC] = ds_output_ic;
  ds->mMethods[NE_DS_METHOD_ICR] = ds_icr;
  ds->mMakeOutput[NE_DS_METHOD_ICR] = ds_output_icr;
  ds->mMethods[NE_DS_METHOD_ICR_IM] = ds_icr_im;
  ds->mMakeOutput[NE_DS_METHOD_ICR_IM] = ds_output_icr_im;
  ds->mMethods[NE_DS_METHOD_ICR_ID] = ds_icr_id;
  ds->mMakeOutput[NE_DS_METHOD_ICR_ID] = ds_output_icr_id;
  ds->mMethods[NE_DS_METHOD_ICR_IL] = ds_icr_il;
  ds->mMakeOutput[NE_DS_METHOD_ICR_IL] = ds_output_icr_il;
  ds->mMethods[NE_DS_METHOD_DXICR] = ds_dxicr;
  ds->mMakeOutput[NE_DS_METHOD_DXICR] = ds_output_dxicr;
  ds->mMethods[NE_DS_METHOD_DXICR_P] = ds_dxicr_p;
  ds->mMakeOutput[NE_DS_METHOD_DXICR_P] = ds_output_dxicr_p;
  ds->mMethods[NE_DS_METHOD_DDICR] = ds_ddicr;
  ds->mMakeOutput[NE_DS_METHOD_DDICR] = ds_output_ddicr;
  ds->mMethods[NE_DS_METHOD_DDICR_P] = ds_ddicr_p;
  ds->mMakeOutput[NE_DS_METHOD_DDICR_P] = ds_output_ddicr_p;
  ds->mMethods[NE_DS_METHOD_TDUICR_P] = ds_tduicr_p;
  ds->mMakeOutput[NE_DS_METHOD_TDUICR_P] = ds_output_tduicr_p;
  ds->mMethods[NE_DS_METHOD_ICRM_P] = ds_icrm_p;
  ds->mMakeOutput[NE_DS_METHOD_ICRM_P] = ds_output_icrm_p;
  ds->mMethods[NE_DS_METHOD_ICRM] = ds_icrm;
  ds->mMakeOutput[NE_DS_METHOD_ICRM] = ds_output_icrm;
  ds->mMethods[NE_DS_METHOD_DXICRM_P] =
    ozysdriverandreceiver_d22bbe4d_49_ds_dxicrm_p;
  ds->mMakeOutput[NE_DS_METHOD_DXICRM_P] = ds_output_dxicrm_p;
  ds->mMethods[NE_DS_METHOD_DXICRM] = ds_dxicrm;
  ds->mMakeOutput[NE_DS_METHOD_DXICRM] = ds_output_dxicrm;
  ds->mMethods[NE_DS_METHOD_DDICRM_P] = ds_ddicrm_p;
  ds->mMakeOutput[NE_DS_METHOD_DDICRM_P] = ds_output_ddicrm_p;
  ds->mMethods[NE_DS_METHOD_DDICRM] = ds_ddicrm;
  ds->mMakeOutput[NE_DS_METHOD_DDICRM] = ds_output_ddicrm;
  ds->mMethods[NE_DS_METHOD_FREQS] = ds_freqs;
  ds->mMakeOutput[NE_DS_METHOD_FREQS] = ds_output_freqs;
  ds->mMethods[NE_DS_METHOD_SOLVERHITS] = ds_solverhits;
  ds->mMakeOutput[NE_DS_METHOD_SOLVERHITS] = ds_output_solverhits;
  ds->mMethods[NE_DS_METHOD_MDUY_P] = ds_mduy_p;
  ds->mMakeOutput[NE_DS_METHOD_MDUY_P] = ds_output_mduy_p;
  ds->mMethods[NE_DS_METHOD_MDXY_P] = ds_mdxy_p;
  ds->mMakeOutput[NE_DS_METHOD_MDXY_P] = ds_output_mdxy_p;
  ds->mMethods[NE_DS_METHOD_TDUY_P] = ds_tduy_p;
  ds->mMakeOutput[NE_DS_METHOD_TDUY_P] = ds_output_tduy_p;
  ds->mMethods[NE_DS_METHOD_TDXY_P] =
    ozysdriverandreceiver_d22bbe4d_49_ds_tdxy_p;
  ds->mMakeOutput[NE_DS_METHOD_TDXY_P] = ds_output_tdxy_p;
  ds->mMethods[NE_DS_METHOD_Y] = ds_y;
  ds->mMakeOutput[NE_DS_METHOD_Y] = ds_output_y;
  ds->mMethods[NE_DS_METHOD_DXY_P] = ozysdriverandreceiver_d22bbe4d_49_ds_dxy_p;
  ds->mMakeOutput[NE_DS_METHOD_DXY_P] = ds_output_dxy_p;
  ds->mMethods[NE_DS_METHOD_DXY] = ds_dxy;
  ds->mMakeOutput[NE_DS_METHOD_DXY] = ds_output_dxy;
  ds->mMethods[NE_DS_METHOD_DUY_P] = ds_duy_p;
  ds->mMakeOutput[NE_DS_METHOD_DUY_P] = ds_output_duy_p;
  ds->mMethods[NE_DS_METHOD_DUY] = ds_duy;
  ds->mMakeOutput[NE_DS_METHOD_DUY] = ds_output_duy;
  ds->mMethods[NE_DS_METHOD_DTY_P] = ds_dty_p;
  ds->mMakeOutput[NE_DS_METHOD_DTY_P] = ds_output_dty_p;
  ds->mMethods[NE_DS_METHOD_DTY] = ds_dty;
  ds->mMakeOutput[NE_DS_METHOD_DTY] = ds_output_dty;
  ds->mMethods[NE_DS_METHOD_MODE] = ozysdriverandreceiver_d22bbe4d_49_ds_mode;
  ds->mMakeOutput[NE_DS_METHOD_MODE] = ds_output_mode;
  ds->mMethods[NE_DS_METHOD_ZC] = ozysdriverandreceiver_d22bbe4d_49_ds_zc;
  ds->mMakeOutput[NE_DS_METHOD_ZC] = ds_output_zc;
  ds->mMethods[NE_DS_METHOD_CACHE_R] = ds_cache_r;
  ds->mMakeOutput[NE_DS_METHOD_CACHE_R] = ds_output_cache_r;
  ds->mMethods[NE_DS_METHOD_CACHE_I] = ds_cache_i;
  ds->mMakeOutput[NE_DS_METHOD_CACHE_I] = ds_output_cache_i;
  ds->mMethods[NE_DS_METHOD_UPDATE_R] = ds_update_r;
  ds->mMakeOutput[NE_DS_METHOD_UPDATE_R] = ds_output_update_r;
  ds->mMethods[NE_DS_METHOD_UPDATE_I] = ds_update_i;
  ds->mMakeOutput[NE_DS_METHOD_UPDATE_I] = ds_output_update_i;
  ds->mMethods[NE_DS_METHOD_UPDATE2_R] = ds_update2_r;
  ds->mMakeOutput[NE_DS_METHOD_UPDATE2_R] = ds_output_update2_r;
  ds->mMethods[NE_DS_METHOD_UPDATE2_I] = ds_update2_i;
  ds->mMakeOutput[NE_DS_METHOD_UPDATE2_I] = ds_output_update2_i;
  ds->mMethods[NE_DS_METHOD_LOCK_R] = ds_lock_r;
  ds->mMakeOutput[NE_DS_METHOD_LOCK_R] = ds_output_lock_r;
  ds->mMethods[NE_DS_METHOD_LOCK_I] = ds_lock_i;
  ds->mMakeOutput[NE_DS_METHOD_LOCK_I] = ds_output_lock_i;
  ds->mMethods[NE_DS_METHOD_LOCK2_R] = ds_lock2_r;
  ds->mMakeOutput[NE_DS_METHOD_LOCK2_R] = ds_output_lock2_r;
  ds->mMethods[NE_DS_METHOD_LOCK2_I] = ds_lock2_i;
  ds->mMakeOutput[NE_DS_METHOD_LOCK2_I] = ds_output_lock2_i;
  ds->mMethods[NE_DS_METHOD_SFO] = ds_sfo;
  ds->mMakeOutput[NE_DS_METHOD_SFO] = ds_output_sfo;
  ds->mMethods[NE_DS_METHOD_SFP] = ds_sfp;
  ds->mMakeOutput[NE_DS_METHOD_SFP] = ds_output_sfp;
  ds->mMethods[NE_DS_METHOD_INIT_R] = ds_init_r;
  ds->mMakeOutput[NE_DS_METHOD_INIT_R] = ds_output_init_r;
  ds->mMethods[NE_DS_METHOD_INIT_I] = ds_init_i;
  ds->mMakeOutput[NE_DS_METHOD_INIT_I] = ds_output_init_i;
  ds->mMethods[NE_DS_METHOD_LOG] = ozysdriverandreceiver_d22bbe4d_49_ds_log;
  ds->mMakeOutput[NE_DS_METHOD_LOG] = ds_output_log;
  ds->mMethods[NE_DS_METHOD_ASSERT] =
    ozysdriverandreceiver_d22bbe4d_49_ds_assert;
  ds->mMakeOutput[NE_DS_METHOD_ASSERT] = ds_output_assert;
  ds->mMethods[NE_DS_METHOD_PASSERT] = ds_passert;
  ds->mMakeOutput[NE_DS_METHOD_PASSERT] = ds_output_passert;
  ds->mMethods[NE_DS_METHOD_IASSERT] = ds_iassert;
  ds->mMakeOutput[NE_DS_METHOD_IASSERT] = ds_output_iassert;
  ds->mMethods[NE_DS_METHOD_DEL_T] = ds_del_t;
  ds->mMakeOutput[NE_DS_METHOD_DEL_T] = ds_output_del_t;
  ds->mMethods[NE_DS_METHOD_DEL_V] = ds_del_v;
  ds->mMakeOutput[NE_DS_METHOD_DEL_V] = ds_output_del_v;
  ds->mMethods[NE_DS_METHOD_DEL_V0] = ds_del_v0;
  ds->mMakeOutput[NE_DS_METHOD_DEL_V0] = ds_output_del_v0;
  ds->mMethods[NE_DS_METHOD_DEL_TMAX] = ds_del_tmax;
  ds->mMakeOutput[NE_DS_METHOD_DEL_TMAX] = ds_output_del_tmax;
  ds->mMethods[NE_DS_METHOD_DXDELT_P] =
    ozysdriverandreceiver_d22bbe4d_49_ds_dxdelt_p;
  ds->mMakeOutput[NE_DS_METHOD_DXDELT_P] = ds_output_dxdelt_p;
  ds->mMethods[NE_DS_METHOD_DXDELT] = ds_dxdelt;
  ds->mMakeOutput[NE_DS_METHOD_DXDELT] = ds_output_dxdelt;
  ds->mMethods[NE_DS_METHOD_DUDELT_P] = ds_dudelt_p;
  ds->mMakeOutput[NE_DS_METHOD_DUDELT_P] = ds_output_dudelt_p;
  ds->mMethods[NE_DS_METHOD_DUDELT] = ds_dudelt;
  ds->mMakeOutput[NE_DS_METHOD_DUDELT] = ds_output_dudelt;
  ds->mMethods[NE_DS_METHOD_DTDELT_P] = ds_dtdelt_p;
  ds->mMakeOutput[NE_DS_METHOD_DTDELT_P] = ds_output_dtdelt_p;
  ds->mMethods[NE_DS_METHOD_DTDELT] = ds_dtdelt;
  ds->mMakeOutput[NE_DS_METHOD_DTDELT] = ds_output_dtdelt;
  ds->mMethods[NE_DS_METHOD_OBS_EXP] =
    ozysdriverandreceiver_d22bbe4d_49_ds_obs_exp;
  ds->mMakeOutput[NE_DS_METHOD_OBS_EXP] = ds_output_obs_exp;
  ds->mMethods[NE_DS_METHOD_OBS_ACT] =
    ozysdriverandreceiver_d22bbe4d_49_ds_obs_act;
  ds->mMakeOutput[NE_DS_METHOD_OBS_ACT] = ds_output_obs_act;
  ds->mMethods[NE_DS_METHOD_OBS_ALL] =
    ozysdriverandreceiver_d22bbe4d_49_ds_obs_all;
  ds->mMakeOutput[NE_DS_METHOD_OBS_ALL] = ds_output_obs_all;
  ds->mMethods[NE_DS_METHOD_OBS_IL] =
    ozysdriverandreceiver_d22bbe4d_49_ds_obs_il;
  ds->mMakeOutput[NE_DS_METHOD_OBS_IL] = ds_output_obs_il;
  ds->mMethods[NE_DS_METHOD_DP_L] = ds_dp_l;
  ds->mMakeOutput[NE_DS_METHOD_DP_L] = ds_output_dp_l;
  ds->mMethods[NE_DS_METHOD_DP_I] = ds_dp_i;
  ds->mMakeOutput[NE_DS_METHOD_DP_I] = ds_output_dp_i;
  ds->mMethods[NE_DS_METHOD_DP_J] = ds_dp_j;
  ds->mMakeOutput[NE_DS_METHOD_DP_J] = ds_output_dp_j;
  ds->mMethods[NE_DS_METHOD_DP_R] = ds_dp_r;
  ds->mMakeOutput[NE_DS_METHOD_DP_R] = ds_output_dp_r;
  ds->mMethods[NE_DS_METHOD_QX] = ds_qx;
  ds->mMakeOutput[NE_DS_METHOD_QX] = ds_output_qx;
  ds->mMethods[NE_DS_METHOD_QU] = ds_qu;
  ds->mMakeOutput[NE_DS_METHOD_QU] = ds_output_qu;
  ds->mMethods[NE_DS_METHOD_QT] = ds_qt;
  ds->mMakeOutput[NE_DS_METHOD_QT] = ds_output_qt;
  ds->mMethods[NE_DS_METHOD_Q1] = ds_q1;
  ds->mMakeOutput[NE_DS_METHOD_Q1] = ds_output_q1;
  ds->mMethods[NE_DS_METHOD_QX_P] = ds_qx_p;
  ds->mMakeOutput[NE_DS_METHOD_QX_P] = ds_output_qx_p;
  ds->mMethods[NE_DS_METHOD_QU_P] = ds_qu_p;
  ds->mMakeOutput[NE_DS_METHOD_QU_P] = ds_output_qu_p;
  ds->mMethods[NE_DS_METHOD_QT_P] = ds_qt_p;
  ds->mMakeOutput[NE_DS_METHOD_QT_P] = ds_output_qt_p;
  ds->mMethods[NE_DS_METHOD_Q1_P] = ds_q1_p;
  ds->mMakeOutput[NE_DS_METHOD_Q1_P] = ds_output_q1_p;
  ds->mMethods[NE_DS_METHOD_VAR_TOL] = ds_var_tol;
  ds->mMakeOutput[NE_DS_METHOD_VAR_TOL] = ds_output_var_tol;
  ds->mMethods[NE_DS_METHOD_EQ_TOL] = ds_eq_tol;
  ds->mMakeOutput[NE_DS_METHOD_EQ_TOL] = ds_output_eq_tol;
  ds->mMethods[NE_DS_METHOD_LV] = ozysdriverandreceiver_d22bbe4d_49_ds_lv;
  ds->mMakeOutput[NE_DS_METHOD_LV] = ds_output_lv;
  ds->mMethods[NE_DS_METHOD_SLV] = ozysdriverandreceiver_d22bbe4d_49_ds_slv;
  ds->mMakeOutput[NE_DS_METHOD_SLV] = ds_output_slv;
  ds->mMethods[NE_DS_METHOD_NLDV] = ozysdriverandreceiver_d22bbe4d_49_ds_nldv;
  ds->mMakeOutput[NE_DS_METHOD_NLDV] = ds_output_nldv;
  ds->mMethods[NE_DS_METHOD_SCLV] = ds_sclv;
  ds->mMakeOutput[NE_DS_METHOD_SCLV] = ds_output_sclv;
  ds->mMethods[NE_DS_METHOD_IMIN] = ozysdriverandreceiver_d22bbe4d_49_ds_imin;
  ds->mMakeOutput[NE_DS_METHOD_IMIN] = ds_output_imin;
  ds->mMethods[NE_DS_METHOD_IMAX] = ozysdriverandreceiver_d22bbe4d_49_ds_imax;
  ds->mMakeOutput[NE_DS_METHOD_IMAX] = ds_output_imax;
  ds->mMethods[NE_DS_METHOD_DIMIN] = ds_dimin;
  ds->mMakeOutput[NE_DS_METHOD_DIMIN] = ds_output_dimin;
  ds->mMethods[NE_DS_METHOD_DIMAX] = ds_dimax;
  ds->mMakeOutput[NE_DS_METHOD_DIMAX] = ds_output_dimax;

  /* equation data */
  ds->mEquationData = s_equation_data;

  /* cer data */
  ds->mCERData = s_cer_data;

  /* icr data */
  ds->mICRData = s_icr_data;

  /* continuous variable data */
  ds->mVariableData = s_variable_data;

  /* discrete variable data */
  ds->mDiscreteData = s_discrete_data;

  /* observable data */
  ds->mObservableData = s_observable_data;

  /* major mode data */
  ds->mMajorModeData = s_major_mode_data;

  /* zc data */
  ds->mZCData = s_zc_data;

  /* ranges */
  ds->mRanges = s_range;

  /* assert data */
  ds->mAssertData = s_assert_data;

  /* assert ranges */
  ds->mAssertRanges = s_assert_range;

  /* param assert data */
  ds->mParamAssertData = s_param_assert_data;

  /* param assert ranges */
  ds->mParamAssertRanges = s_param_assert_range;

  /* initial assert data */
  ds->mInitialAssertData = s_initial_assert_data;

  /* initial assert ranges */
  ds->mInitialAssertRanges = s_initial_assert_range;

  /* equation ranges */
  ds->mEquationRanges = s_equation_range;

  /* cer ranges */
  ds->mCERRanges = s_cer_range;

  /* icr ranges */
  ds->mICRRanges = s_icr_range;

  /* parameters */
  ds->mLogicalParameters = s_logical_parameter_data;
  ds->mIntegerParameters = s_integer_parameter_data;
  ds->mIndexParameters = s_index_parameter_data;
  ds->mRealParameters = s_real_parameter_data;

  /* constant tables */
  ds->mNumLargeArray = 0;
  return (NeDynamicSystem *)_ds;
}

static int32_T ds_passert (const NeDynamicSystem *sys, const
  NeDynamicSystemInput *t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)out;
  (void)sys;
  (void)out;
  return 0;
}

static int32_T ds_iassert (const NeDynamicSystem *sys, const
  NeDynamicSystemInput *t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)out;
  (void)sys;
  (void)out;
  return 0;
}

static int32_T ds_cer (const NeDynamicSystem *sys, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)out;
  (void)sys;
  (void)out;
  return 0;
}

static int32_T ds_dxcer (const NeDynamicSystem *sys, const NeDynamicSystemInput *
  t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)out;
  (void)sys;
  (void)out;
  return 0;
}

static int32_T ds_dxcer_p (const NeDynamicSystem *sys, const
  NeDynamicSystemInput *t1, NeDsMethodOutput *out)
{
  (void)t1;
  out->mDXCER_P.mNumCol = 24UL;
  out->mDXCER_P.mNumRow = 0UL;
  out->mDXCER_P.mJc[0] = 0;
  out->mDXCER_P.mJc[1] = 0;
  out->mDXCER_P.mJc[2] = 0;
  out->mDXCER_P.mJc[3] = 0;
  out->mDXCER_P.mJc[4] = 0;
  out->mDXCER_P.mJc[5] = 0;
  out->mDXCER_P.mJc[6] = 0;
  out->mDXCER_P.mJc[7] = 0;
  out->mDXCER_P.mJc[8] = 0;
  out->mDXCER_P.mJc[9] = 0;
  out->mDXCER_P.mJc[10] = 0;
  out->mDXCER_P.mJc[11] = 0;
  out->mDXCER_P.mJc[12] = 0;
  out->mDXCER_P.mJc[13] = 0;
  out->mDXCER_P.mJc[14] = 0;
  out->mDXCER_P.mJc[15] = 0;
  out->mDXCER_P.mJc[16] = 0;
  out->mDXCER_P.mJc[17] = 0;
  out->mDXCER_P.mJc[18] = 0;
  out->mDXCER_P.mJc[19] = 0;
  out->mDXCER_P.mJc[20] = 0;
  out->mDXCER_P.mJc[21] = 0;
  out->mDXCER_P.mJc[22] = 0;
  out->mDXCER_P.mJc[23] = 0;
  out->mDXCER_P.mJc[24] = 0;
  (void)sys;
  (void)out;
  return 0;
}

static int32_T ds_ddcer (const NeDynamicSystem *sys, const NeDynamicSystemInput *
  t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)out;
  (void)sys;
  (void)out;
  return 0;
}

static int32_T ds_ddcer_p (const NeDynamicSystem *sys, const
  NeDynamicSystemInput *t1, NeDsMethodOutput *out)
{
  (void)t1;
  out->mDDCER_P.mNumCol = 0UL;
  out->mDDCER_P.mNumRow = 0UL;
  out->mDDCER_P.mJc[0] = 0;
  (void)sys;
  (void)out;
  return 0;
}

static int32_T ds_del_v (const NeDynamicSystem *sys, const NeDynamicSystemInput *
  t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)out;
  (void)sys;
  (void)out;
  return 0;
}

static int32_T ds_del_v0 (const NeDynamicSystem *sys, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)out;
  (void)sys;
  (void)out;
  return 0;
}

static int32_T ds_del_tmax (const NeDynamicSystem *sys, const
  NeDynamicSystemInput *t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)out;
  (void)sys;
  (void)out;
  return 0;
}

static int32_T ds_del_t (const NeDynamicSystem *sys, const NeDynamicSystemInput *
  t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)out;
  (void)sys;
  (void)out;
  return 0;
}

static int32_T ds_dxdelt (const NeDynamicSystem *sys, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)out;
  (void)sys;
  (void)out;
  return 0;
}

static int32_T ds_dudelt (const NeDynamicSystem *sys, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)out;
  (void)sys;
  (void)out;
  return 0;
}

static int32_T ds_dudelt_p (const NeDynamicSystem *sys, const
  NeDynamicSystemInput *t1, NeDsMethodOutput *out)
{
  (void)t1;
  out->mDUDELT_P.mNumCol = 4UL;
  out->mDUDELT_P.mNumRow = 0UL;
  out->mDUDELT_P.mJc[0] = 0;
  out->mDUDELT_P.mJc[1] = 0;
  out->mDUDELT_P.mJc[2] = 0;
  out->mDUDELT_P.mJc[3] = 0;
  out->mDUDELT_P.mJc[4] = 0;
  (void)sys;
  (void)out;
  return 0;
}

static int32_T ds_dtdelt (const NeDynamicSystem *sys, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)out;
  (void)sys;
  (void)out;
  return 0;
}

static int32_T ds_dtdelt_p (const NeDynamicSystem *sys, const
  NeDynamicSystemInput *t1, NeDsMethodOutput *out)
{
  (void)t1;
  out->mDTDELT_P.mNumCol = 1UL;
  out->mDTDELT_P.mNumRow = 0UL;
  out->mDTDELT_P.mJc[0] = 0;
  out->mDTDELT_P.mJc[1] = 0;
  (void)sys;
  (void)out;
  return 0;
}

static int32_T ds_cache_r (const NeDynamicSystem *sys, const
  NeDynamicSystemInput *t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)out;
  (void)sys;
  (void)out;
  return 0;
}

static int32_T ds_init_r (const NeDynamicSystem *sys, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)out;
  (void)sys;
  (void)out;
  return 0;
}

static int32_T ds_update_r (const NeDynamicSystem *sys, const
  NeDynamicSystemInput *t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)out;
  (void)sys;
  (void)out;
  return 0;
}

static int32_T ds_lock_r (const NeDynamicSystem *sys, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)out;
  (void)sys;
  (void)out;
  return 0;
}

static int32_T ds_cache_i (const NeDynamicSystem *sys, const
  NeDynamicSystemInput *t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)out;
  (void)sys;
  (void)out;
  return 0;
}

static int32_T ds_init_i (const NeDynamicSystem *sys, const NeDynamicSystemInput
  *t5, NeDsMethodOutput *out)
{
  size_t _in1ivar;
  int32_T t1[2];
  int32_T t2[2];
  (void)t5;
  _in1ivar = 3415357569UL;
  init_gaussian_seed(&t1[0UL], &_in1ivar);
  _in1ivar = 802611725UL;
  init_gaussian_seed(&t2[0UL], &_in1ivar);
  out->mINIT_I.mX[0UL] = t1[0UL];
  out->mINIT_I.mX[1UL] = t1[1UL];
  out->mINIT_I.mX[2UL] = t2[0UL];
  out->mINIT_I.mX[3UL] = t2[1UL];
  (void)sys;
  (void)out;
  return 0;
}

static int32_T ds_update_i (const NeDynamicSystem *sys, const
  NeDynamicSystemInput *t5, NeDsMethodOutput *out)
{
  int32_T t0[2];
  int32_T t2[2];
  int32_T t3[2];
  if (t5->mE.mX[0UL] != 0) {
    t2[0UL] = t5->mQ.mX[0UL];
    t2[1UL] = t5->mQ.mX[1UL];
    update_gaussian_seed(&t0[0UL], &t2[0UL]);
  } else {
    t0[0UL] = t5->mQ.mX[0UL];
    t0[1UL] = t5->mQ.mX[1UL];
  }

  if (t5->mE.mX[1UL] != 0) {
    t3[0UL] = t5->mQ.mX[2UL];
    t3[1UL] = t5->mQ.mX[3UL];
    update_gaussian_seed(&t2[0UL], &t3[0UL]);
  } else {
    t2[0UL] = t5->mQ.mX[2UL];
    t2[1UL] = t5->mQ.mX[3UL];
  }

  out->mUPDATE_I.mX[0UL] = t0[0UL];
  out->mUPDATE_I.mX[1UL] = t0[1UL];
  out->mUPDATE_I.mX[2UL] = t2[0UL];
  out->mUPDATE_I.mX[3UL] = t2[1UL];
  (void)sys;
  (void)out;
  return 0;
}

static int32_T ds_lock_i (const NeDynamicSystem *sys, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *out)
{
  boolean_T indicator0;
  boolean_T indicator1;
  indicator0 = (t1->mE.mX[0UL] != 0);
  indicator1 = (t1->mE.mX[1UL] != 0);
  out->mLOCK_I.mX[0UL] = indicator0;
  out->mLOCK_I.mX[1UL] = indicator0;
  out->mLOCK_I.mX[2UL] = indicator1;
  out->mLOCK_I.mX[3UL] = indicator1;
  (void)sys;
  (void)out;
  return 0;
}

static int32_T ds_update2_r (const NeDynamicSystem *sys, const
  NeDynamicSystemInput *t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)out;
  (void)sys;
  (void)out;
  return 0;
}

static int32_T ds_lock2_r (const NeDynamicSystem *sys, const
  NeDynamicSystemInput *t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)out;
  (void)sys;
  (void)out;
  return 0;
}

static int32_T ds_update2_i (const NeDynamicSystem *sys, const
  NeDynamicSystemInput *t1, NeDsMethodOutput *out)
{
  out->mUPDATE2_I.mX[0UL] = t1->mQ.mX[0UL];
  out->mUPDATE2_I.mX[1UL] = t1->mQ.mX[1UL];
  out->mUPDATE2_I.mX[2UL] = t1->mQ.mX[2UL];
  out->mUPDATE2_I.mX[3UL] = t1->mQ.mX[3UL];
  (void)sys;
  (void)out;
  return 0;
}

static int32_T ds_lock2_i (const NeDynamicSystem *sys, const
  NeDynamicSystemInput *t1, NeDsMethodOutput *out)
{
  (void)t1;
  out->mLOCK2_I.mX[0UL] = false;
  out->mLOCK2_I.mX[1UL] = false;
  out->mLOCK2_I.mX[2UL] = false;
  out->mLOCK2_I.mX[3UL] = false;
  (void)sys;
  (void)out;
  return 0;
}

static int32_T ds_sfp (const NeDynamicSystem *sys, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *out)
{
  (void)t1;
  out->mSFP.mX[0] = 1.0E-5;
  out->mSFP.mX[1] = 1.0E-5;
  (void)sys;
  (void)out;
  return 0;
}

static int32_T ds_sfo (const NeDynamicSystem *sys, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *out)
{
  (void)t1;
  out->mSFO.mX[0] = 1.0E-5;
  out->mSFO.mX[1] = 1.0E-5;
  (void)sys;
  (void)out;
  return 0;
}

static int32_T ds_duf (const NeDynamicSystem *sys, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *out)
{
  out->mDUF.mX[0UL] = t1->mM.mX[12UL] != 0 ? -((t1->mX.mX[17UL] *
    0.016666666666666666 + t1->mX.mX[20UL]) - 0.052999999999999992) : 0.0;
  out->mDUF.mX[1UL] = t1->mM.mX[3UL] != 0 ? -t1->mX.mX[20UL] : 0.0;
  out->mDUF.mX[2UL] = t1->mM.mX[4UL] != 0 ? -((t1->mX.mX[19UL] *
    -0.00014705882352941175 + t1->mX.mX[9UL] * 0.00014705882352941175) +
    t1->mX.mX[20UL]) : 0.0;
  out->mDUF.mX[3UL] = t1->mM.mX[2UL] != 0 ? -((((t1->mX.mX[17UL] *
    0.016666666666666666 + t1->mX.mX[18UL] * 0.00014705882352941175) + t1->
    mX.mX[12UL] * -0.00014705882352941175) + t1->mX.mX[20UL]) -
    0.052999999999999992) : 0.0;
  (void)sys;
  (void)out;
  return 0;
}

static int32_T ds_duf_p (const NeDynamicSystem *sys, const NeDynamicSystemInput *
  t1, NeDsMethodOutput *out)
{
  static int32_T _cg_const_2[4] = { 12, 14, 15, 13 };

  (void)t1;
  out->mDUF_P.mNumCol = 4UL;
  out->mDUF_P.mNumRow = 24UL;
  out->mDUF_P.mJc[0] = 0;
  out->mDUF_P.mJc[1] = 1;
  out->mDUF_P.mJc[2] = 2;
  out->mDUF_P.mJc[3] = 3;
  out->mDUF_P.mJc[4] = 4;
  out->mDUF_P.mIr[0] = _cg_const_2[0];
  out->mDUF_P.mIr[1] = _cg_const_2[1];
  out->mDUF_P.mIr[2] = _cg_const_2[2];
  out->mDUF_P.mIr[3] = _cg_const_2[3];
  (void)sys;
  (void)out;
  return 0;
}

static int32_T ds_dtf (const NeDynamicSystem *sys, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *out)
{
  (void)t1;
  out->mDTF.mX[0UL] = -0.0;
  out->mDTF.mX[1UL] = -0.0;
  (void)sys;
  (void)out;
  return 0;
}

static int32_T ds_dtf_p (const NeDynamicSystem *sys, const NeDynamicSystemInput *
  t1, NeDsMethodOutput *out)
{
  (void)t1;
  out->mDTF_P.mNumCol = 1UL;
  out->mDTF_P.mNumRow = 24UL;
  out->mDTF_P.mJc[0] = 0;
  out->mDTF_P.mJc[1] = 2;
  out->mDTF_P.mIr[0] = 8;
  out->mDTF_P.mIr[1] = 9;
  (void)sys;
  (void)out;
  return 0;
}

static int32_T ds_ddf (const NeDynamicSystem *sys, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)out;
  (void)sys;
  (void)out;
  return 0;
}

static int32_T ds_ddf_p (const NeDynamicSystem *sys, const NeDynamicSystemInput *
  t1, NeDsMethodOutput *out)
{
  (void)t1;
  out->mDDF_P.mNumCol = 0UL;
  out->mDDF_P.mNumRow = 24UL;
  out->mDDF_P.mJc[0] = 0;
  (void)sys;
  (void)out;
  return 0;
}

static int32_T ds_apar (const NeDynamicSystem *sys, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)out;
  (void)sys;
  (void)out;
  return 0;
}

static int32_T ds_apar_p (const NeDynamicSystem *sys, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *out)
{
  (void)t1;
  out->mAPAR_P.mNumCol = 24UL;
  out->mAPAR_P.mNumRow = 24UL;
  out->mAPAR_P.mJc[0] = 0;
  out->mAPAR_P.mJc[1] = 0;
  out->mAPAR_P.mJc[2] = 0;
  out->mAPAR_P.mJc[3] = 0;
  out->mAPAR_P.mJc[4] = 0;
  out->mAPAR_P.mJc[5] = 0;
  out->mAPAR_P.mJc[6] = 0;
  out->mAPAR_P.mJc[7] = 0;
  out->mAPAR_P.mJc[8] = 0;
  out->mAPAR_P.mJc[9] = 0;
  out->mAPAR_P.mJc[10] = 0;
  out->mAPAR_P.mJc[11] = 0;
  out->mAPAR_P.mJc[12] = 0;
  out->mAPAR_P.mJc[13] = 0;
  out->mAPAR_P.mJc[14] = 0;
  out->mAPAR_P.mJc[15] = 0;
  out->mAPAR_P.mJc[16] = 0;
  out->mAPAR_P.mJc[17] = 0;
  out->mAPAR_P.mJc[18] = 0;
  out->mAPAR_P.mJc[19] = 0;
  out->mAPAR_P.mJc[20] = 0;
  out->mAPAR_P.mJc[21] = 0;
  out->mAPAR_P.mJc[22] = 0;
  out->mAPAR_P.mJc[23] = 0;
  out->mAPAR_P.mJc[24] = 0;
  (void)sys;
  (void)out;
  return 0;
}

static int32_T ds_bcon (const NeDynamicSystem *sys, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)out;
  (void)sys;
  (void)out;
  return 0;
}

static int32_T ds_bcon_p (const NeDynamicSystem *sys, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *out)
{
  (void)t1;
  out->mBCON_P.mNumCol = 4UL;
  out->mBCON_P.mNumRow = 24UL;
  out->mBCON_P.mJc[0] = 0;
  out->mBCON_P.mJc[1] = 0;
  out->mBCON_P.mJc[2] = 0;
  out->mBCON_P.mJc[3] = 0;
  out->mBCON_P.mJc[4] = 0;
  (void)sys;
  (void)out;
  return 0;
}

static int32_T ds_bpar (const NeDynamicSystem *sys, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)out;
  (void)sys;
  (void)out;
  return 0;
}

static int32_T ds_bpar_p (const NeDynamicSystem *sys, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *out)
{
  (void)t1;
  out->mBPAR_P.mNumCol = 4UL;
  out->mBPAR_P.mNumRow = 24UL;
  out->mBPAR_P.mJc[0] = 0;
  out->mBPAR_P.mJc[1] = 0;
  out->mBPAR_P.mJc[2] = 0;
  out->mBPAR_P.mJc[3] = 0;
  out->mBPAR_P.mJc[4] = 0;
  (void)sys;
  (void)out;
  return 0;
}

static int32_T ds_ccon (const NeDynamicSystem *sys, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)out;
  (void)sys;
  (void)out;
  return 0;
}

static int32_T ds_ccon_p (const NeDynamicSystem *sys, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *out)
{
  (void)t1;
  out->mCCON_P.mNumCol = 1UL;
  out->mCCON_P.mNumRow = 24UL;
  out->mCCON_P.mJc[0] = 0;
  out->mCCON_P.mJc[1] = 0;
  (void)sys;
  (void)out;
  return 0;
}

static int32_T ds_cpar (const NeDynamicSystem *sys, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)out;
  (void)sys;
  (void)out;
  return 0;
}

static int32_T ds_cpar_p (const NeDynamicSystem *sys, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *out)
{
  (void)t1;
  out->mCPAR_P.mNumCol = 1UL;
  out->mCPAR_P.mNumRow = 24UL;
  out->mCPAR_P.mJc[0] = 0;
  out->mCPAR_P.mJc[1] = 0;
  (void)sys;
  (void)out;
  return 0;
}

static int32_T ds_tduf_p (const NeDynamicSystem *sys, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *out)
{
  static int32_T _cg_const_2[4] = { 12, 14, 15, 13 };

  (void)t1;
  out->mTDUF_P.mNumCol = 4UL;
  out->mTDUF_P.mNumRow = 24UL;
  out->mTDUF_P.mJc[0] = 0;
  out->mTDUF_P.mJc[1] = 1;
  out->mTDUF_P.mJc[2] = 2;
  out->mTDUF_P.mJc[3] = 3;
  out->mTDUF_P.mJc[4] = 4;
  out->mTDUF_P.mIr[0] = _cg_const_2[0];
  out->mTDUF_P.mIr[1] = _cg_const_2[1];
  out->mTDUF_P.mIr[2] = _cg_const_2[2];
  out->mTDUF_P.mIr[3] = _cg_const_2[3];
  (void)sys;
  (void)out;
  return 0;
}

static int32_T ds_dwf (const NeDynamicSystem *sys, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)out;
  (void)sys;
  (void)out;
  return 0;
}

static int32_T ds_dwf_p (const NeDynamicSystem *sys, const NeDynamicSystemInput *
  t1, NeDsMethodOutput *out)
{
  (void)t1;
  out->mDWF_P.mNumCol = 0UL;
  out->mDWF_P.mNumRow = 24UL;
  out->mDWF_P.mJc[0] = 0;
  (void)sys;
  (void)out;
  return 0;
}

static int32_T ds_dpdxf (const NeDynamicSystem *sys, const NeDynamicSystemInput *
  t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)out;
  (void)sys;
  (void)out;
  return 0;
}

static int32_T ds_dpdxf_p (const NeDynamicSystem *sys, const
  NeDynamicSystemInput *t1, NeDsMethodOutput *out)
{
  (void)t1;
  out->mDPDXF_P.mNumCol = 0UL;
  out->mDPDXF_P.mNumRow = 19UL;
  out->mDPDXF_P.mJc[0] = 0;
  (void)sys;
  (void)out;
  return 0;
}

static int32_T ds_slf (const NeDynamicSystem *sys, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *out)
{
  (void)t1;
  out->mSLF.mX[0] = false;
  out->mSLF.mX[1] = false;
  out->mSLF.mX[2] = false;
  out->mSLF.mX[3] = false;
  out->mSLF.mX[4] = false;
  out->mSLF.mX[5] = false;
  out->mSLF.mX[6] = false;
  out->mSLF.mX[7] = false;
  out->mSLF.mX[8] = false;
  out->mSLF.mX[9] = false;
  out->mSLF.mX[10] = false;
  out->mSLF.mX[11] = false;
  out->mSLF.mX[12] = false;
  out->mSLF.mX[13] = false;
  out->mSLF.mX[14] = false;
  out->mSLF.mX[15] = false;
  out->mSLF.mX[16] = false;
  out->mSLF.mX[17] = false;
  out->mSLF.mX[18] = false;
  out->mSLF.mX[19] = false;
  out->mSLF.mX[20] = false;
  out->mSLF.mX[21] = false;
  out->mSLF.mX[22] = false;
  out->mSLF.mX[23] = false;
  (void)sys;
  (void)out;
  return 0;
}

static int32_T ds_dnf (const NeDynamicSystem *sys, const NeDynamicSystemInput
  *t4, NeDsMethodOutput *out)
{
  (void)t4;
  out->mDNF.mX[0UL] = -0.15811388300841897;
  out->mDNF.mX[1UL] = -1.0;
  out->mDNF.mX[2UL] = -1.0;
  out->mDNF.mX[3UL] = -0.15811388300841897;
  (void)sys;
  (void)out;
  return 0;
}

static int32_T ds_slf0 (const NeDynamicSystem *sys, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *out)
{
  (void)t1;
  out->mSLF0.mX[0] = false;
  out->mSLF0.mX[1] = false;
  out->mSLF0.mX[2] = false;
  out->mSLF0.mX[3] = false;
  out->mSLF0.mX[4] = false;
  out->mSLF0.mX[5] = false;
  out->mSLF0.mX[6] = false;
  out->mSLF0.mX[7] = false;
  out->mSLF0.mX[8] = false;
  out->mSLF0.mX[9] = false;
  out->mSLF0.mX[10] = false;
  out->mSLF0.mX[11] = false;
  out->mSLF0.mX[12] = false;
  out->mSLF0.mX[13] = false;
  out->mSLF0.mX[14] = false;
  out->mSLF0.mX[15] = false;
  out->mSLF0.mX[16] = false;
  out->mSLF0.mX[17] = false;
  out->mSLF0.mX[18] = false;
  out->mSLF0.mX[19] = false;
  out->mSLF0.mX[20] = false;
  out->mSLF0.mX[21] = false;
  out->mSLF0.mX[22] = false;
  out->mSLF0.mX[23] = false;
  (void)sys;
  (void)out;
  return 0;
}

static int32_T ds_vpf (const NeDynamicSystem *sys, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *out)
{
  (void)t1;
  out->mVPF.mX[0] = false;
  out->mVPF.mX[1] = false;
  out->mVPF.mX[2] = false;
  out->mVPF.mX[3] = false;
  out->mVPF.mX[4] = false;
  out->mVPF.mX[5] = false;
  out->mVPF.mX[6] = false;
  out->mVPF.mX[7] = false;
  out->mVPF.mX[8] = false;
  out->mVPF.mX[9] = false;
  out->mVPF.mX[10] = false;
  out->mVPF.mX[11] = false;
  out->mVPF.mX[12] = false;
  out->mVPF.mX[13] = false;
  out->mVPF.mX[14] = false;
  out->mVPF.mX[15] = false;
  out->mVPF.mX[16] = false;
  out->mVPF.mX[17] = false;
  out->mVPF.mX[18] = false;
  out->mVPF.mX[19] = false;
  out->mVPF.mX[20] = false;
  out->mVPF.mX[21] = false;
  out->mVPF.mX[22] = false;
  out->mVPF.mX[23] = false;
  (void)sys;
  (void)out;
  return 0;
}

static int32_T ds_vsf (const NeDynamicSystem *sys, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *out)
{
  (void)t1;
  out->mVSF.mX[0] = false;
  out->mVSF.mX[1] = false;
  out->mVSF.mX[2] = false;
  out->mVSF.mX[3] = false;
  out->mVSF.mX[4] = false;
  out->mVSF.mX[5] = false;
  out->mVSF.mX[6] = false;
  out->mVSF.mX[7] = false;
  out->mVSF.mX[8] = false;
  out->mVSF.mX[9] = false;
  out->mVSF.mX[10] = false;
  out->mVSF.mX[11] = false;
  out->mVSF.mX[12] = false;
  out->mVSF.mX[13] = false;
  out->mVSF.mX[14] = false;
  out->mVSF.mX[15] = false;
  out->mVSF.mX[16] = false;
  out->mVSF.mX[17] = false;
  out->mVSF.mX[18] = false;
  out->mVSF.mX[19] = false;
  out->mVSF.mX[20] = false;
  out->mVSF.mX[21] = false;
  out->mVSF.mX[22] = false;
  out->mVSF.mX[23] = false;
  (void)sys;
  (void)out;
  return 0;
}

static int32_T ds_freqs (const NeDynamicSystem *sys, const NeDynamicSystemInput *
  t1, NeDsMethodOutput *out)
{
  (void)t1;
  out->mFREQS.mX[0] = 376.99111843077515;
  (void)sys;
  (void)out;
  return 0;
}

static int32_T ds_ic (const NeDynamicSystem *sys, const NeDynamicSystemInput *t1,
                      NeDsMethodOutput *out)
{
  (void)t1;
  out->mIC.mX[0] = 0.0;
  out->mIC.mX[1] = 0.0;
  out->mIC.mX[2] = 0.0;
  out->mIC.mX[3] = 0.0;
  out->mIC.mX[4] = 0.0;
  out->mIC.mX[5] = 0.0;
  out->mIC.mX[6] = 0.0;
  out->mIC.mX[7] = 0.0;
  out->mIC.mX[8] = 0.0;
  out->mIC.mX[9] = 0.0;
  out->mIC.mX[10] = 0.0;
  out->mIC.mX[11] = 0.0;
  out->mIC.mX[12] = 0.0;
  out->mIC.mX[13] = 0.0;
  out->mIC.mX[14] = 0.0;
  out->mIC.mX[15] = 0.0;
  out->mIC.mX[16] = 0.0;
  out->mIC.mX[17] = 0.0;
  out->mIC.mX[18] = 0.0;
  out->mIC.mX[19] = 0.0;
  out->mIC.mX[20] = 0.0;
  out->mIC.mX[21] = 0.0;
  out->mIC.mX[22] = 0.0;
  out->mIC.mX[23] = 0.0;
  (void)sys;
  (void)out;
  return 0;
}

static int32_T ds_icr (const NeDynamicSystem *sys, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)out;
  (void)sys;
  (void)out;
  return 0;
}

static int32_T ds_icr_im (const NeDynamicSystem *sys, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)out;
  (void)sys;
  (void)out;
  return 0;
}

static int32_T ds_icr_id (const NeDynamicSystem *sys, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)out;
  (void)sys;
  (void)out;
  return 0;
}

static int32_T ds_icr_il (const NeDynamicSystem *sys, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)out;
  (void)sys;
  (void)out;
  return 0;
}

static int32_T ds_dxicr (const NeDynamicSystem *sys, const NeDynamicSystemInput *
  t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)out;
  (void)sys;
  (void)out;
  return 0;
}

static int32_T ds_dxicr_p (const NeDynamicSystem *sys, const
  NeDynamicSystemInput *t1, NeDsMethodOutput *out)
{
  (void)t1;
  out->mDXICR_P.mNumCol = 24UL;
  out->mDXICR_P.mNumRow = 0UL;
  out->mDXICR_P.mJc[0] = 0;
  out->mDXICR_P.mJc[1] = 0;
  out->mDXICR_P.mJc[2] = 0;
  out->mDXICR_P.mJc[3] = 0;
  out->mDXICR_P.mJc[4] = 0;
  out->mDXICR_P.mJc[5] = 0;
  out->mDXICR_P.mJc[6] = 0;
  out->mDXICR_P.mJc[7] = 0;
  out->mDXICR_P.mJc[8] = 0;
  out->mDXICR_P.mJc[9] = 0;
  out->mDXICR_P.mJc[10] = 0;
  out->mDXICR_P.mJc[11] = 0;
  out->mDXICR_P.mJc[12] = 0;
  out->mDXICR_P.mJc[13] = 0;
  out->mDXICR_P.mJc[14] = 0;
  out->mDXICR_P.mJc[15] = 0;
  out->mDXICR_P.mJc[16] = 0;
  out->mDXICR_P.mJc[17] = 0;
  out->mDXICR_P.mJc[18] = 0;
  out->mDXICR_P.mJc[19] = 0;
  out->mDXICR_P.mJc[20] = 0;
  out->mDXICR_P.mJc[21] = 0;
  out->mDXICR_P.mJc[22] = 0;
  out->mDXICR_P.mJc[23] = 0;
  out->mDXICR_P.mJc[24] = 0;
  (void)sys;
  (void)out;
  return 0;
}

static int32_T ds_ddicr (const NeDynamicSystem *sys, const NeDynamicSystemInput *
  t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)out;
  (void)sys;
  (void)out;
  return 0;
}

static int32_T ds_ddicr_p (const NeDynamicSystem *sys, const
  NeDynamicSystemInput *t1, NeDsMethodOutput *out)
{
  (void)t1;
  out->mDDICR_P.mNumCol = 0UL;
  out->mDDICR_P.mNumRow = 0UL;
  out->mDDICR_P.mJc[0] = 0;
  (void)sys;
  (void)out;
  return 0;
}

static int32_T ds_tduicr_p (const NeDynamicSystem *sys, const
  NeDynamicSystemInput *t1, NeDsMethodOutput *out)
{
  (void)t1;
  out->mTDUICR_P.mNumCol = 4UL;
  out->mTDUICR_P.mNumRow = 0UL;
  out->mTDUICR_P.mJc[0] = 0;
  out->mTDUICR_P.mJc[1] = 0;
  out->mTDUICR_P.mJc[2] = 0;
  out->mTDUICR_P.mJc[3] = 0;
  out->mTDUICR_P.mJc[4] = 0;
  (void)sys;
  (void)out;
  return 0;
}

static int32_T ds_icrm (const NeDynamicSystem *sys, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)out;
  (void)sys;
  (void)out;
  return 0;
}

static int32_T ds_icrm_p (const NeDynamicSystem *sys, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *out)
{
  (void)t1;
  out->mICRM_P.mNumCol = 24UL;
  out->mICRM_P.mNumRow = 0UL;
  out->mICRM_P.mJc[0] = 0;
  out->mICRM_P.mJc[1] = 0;
  out->mICRM_P.mJc[2] = 0;
  out->mICRM_P.mJc[3] = 0;
  out->mICRM_P.mJc[4] = 0;
  out->mICRM_P.mJc[5] = 0;
  out->mICRM_P.mJc[6] = 0;
  out->mICRM_P.mJc[7] = 0;
  out->mICRM_P.mJc[8] = 0;
  out->mICRM_P.mJc[9] = 0;
  out->mICRM_P.mJc[10] = 0;
  out->mICRM_P.mJc[11] = 0;
  out->mICRM_P.mJc[12] = 0;
  out->mICRM_P.mJc[13] = 0;
  out->mICRM_P.mJc[14] = 0;
  out->mICRM_P.mJc[15] = 0;
  out->mICRM_P.mJc[16] = 0;
  out->mICRM_P.mJc[17] = 0;
  out->mICRM_P.mJc[18] = 0;
  out->mICRM_P.mJc[19] = 0;
  out->mICRM_P.mJc[20] = 0;
  out->mICRM_P.mJc[21] = 0;
  out->mICRM_P.mJc[22] = 0;
  out->mICRM_P.mJc[23] = 0;
  out->mICRM_P.mJc[24] = 0;
  (void)sys;
  (void)out;
  return 0;
}

static int32_T ds_dxicrm (const NeDynamicSystem *sys, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)out;
  (void)sys;
  (void)out;
  return 0;
}

static int32_T ds_ddicrm (const NeDynamicSystem *sys, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)out;
  (void)sys;
  (void)out;
  return 0;
}

static int32_T ds_ddicrm_p (const NeDynamicSystem *sys, const
  NeDynamicSystemInput *t1, NeDsMethodOutput *out)
{
  (void)t1;
  out->mDDICRM_P.mNumCol = 0UL;
  out->mDDICRM_P.mNumRow = 0UL;
  out->mDDICRM_P.mJc[0] = 0;
  (void)sys;
  (void)out;
  return 0;
}

static int32_T ds_dimin (const NeDynamicSystem *sys, const NeDynamicSystemInput *
  t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)out;
  (void)sys;
  (void)out;
  return 0;
}

static int32_T ds_dimax (const NeDynamicSystem *sys, const NeDynamicSystemInput *
  t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)out;
  (void)sys;
  (void)out;
  return 0;
}

static int32_T ds_mcon (const NeDynamicSystem *sys, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *out)
{
  static real_T _cg_const_1[6] = { -2.0E-8, -3.6E-12, -3.6E-12,
    -6.3692307692307666E-12, -1.0E-7, -2.0E-8 };

  (void)t1;
  out->mMCON.mX[0] = _cg_const_1[0];
  out->mMCON.mX[1] = _cg_const_1[1];
  out->mMCON.mX[2] = _cg_const_1[2];
  out->mMCON.mX[3] = _cg_const_1[3];
  out->mMCON.mX[4] = _cg_const_1[4];
  out->mMCON.mX[5] = _cg_const_1[5];
  (void)sys;
  (void)out;
  return 0;
}

static int32_T ds_mpar (const NeDynamicSystem *sys, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)out;
  (void)sys;
  (void)out;
  return 0;
}

static int32_T ds_mpar_p (const NeDynamicSystem *sys, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *out)
{
  (void)t1;
  out->mMPAR_P.mNumCol = 24UL;
  out->mMPAR_P.mNumRow = 24UL;
  out->mMPAR_P.mJc[0] = 0;
  out->mMPAR_P.mJc[1] = 0;
  out->mMPAR_P.mJc[2] = 0;
  out->mMPAR_P.mJc[3] = 0;
  out->mMPAR_P.mJc[4] = 0;
  out->mMPAR_P.mJc[5] = 0;
  out->mMPAR_P.mJc[6] = 0;
  out->mMPAR_P.mJc[7] = 0;
  out->mMPAR_P.mJc[8] = 0;
  out->mMPAR_P.mJc[9] = 0;
  out->mMPAR_P.mJc[10] = 0;
  out->mMPAR_P.mJc[11] = 0;
  out->mMPAR_P.mJc[12] = 0;
  out->mMPAR_P.mJc[13] = 0;
  out->mMPAR_P.mJc[14] = 0;
  out->mMPAR_P.mJc[15] = 0;
  out->mMPAR_P.mJc[16] = 0;
  out->mMPAR_P.mJc[17] = 0;
  out->mMPAR_P.mJc[18] = 0;
  out->mMPAR_P.mJc[19] = 0;
  out->mMPAR_P.mJc[20] = 0;
  out->mMPAR_P.mJc[21] = 0;
  out->mMPAR_P.mJc[22] = 0;
  out->mMPAR_P.mJc[23] = 0;
  out->mMPAR_P.mJc[24] = 0;
  (void)sys;
  (void)out;
  return 0;
}

static int32_T ds_mnl (const NeDynamicSystem *sys, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *out)
{
  (void)t1;
  out->mMNL.mX[0] = 1.488124760092523E-13;
  out->mMNL.mX[1] = 1.488124760092523E-13;
  (void)sys;
  (void)out;
  return 0;
}

static int32_T ds_dxm (const NeDynamicSystem *sys, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)out;
  (void)sys;
  (void)out;
  return 0;
}

static int32_T ds_dxm_p (const NeDynamicSystem *sys, const NeDynamicSystemInput *
  t1, NeDsMethodOutput *out)
{
  (void)t1;
  out->mDXM_P.mNumCol = 24UL;
  out->mDXM_P.mNumRow = 8UL;
  out->mDXM_P.mJc[0] = 0;
  out->mDXM_P.mJc[1] = 0;
  out->mDXM_P.mJc[2] = 0;
  out->mDXM_P.mJc[3] = 0;
  out->mDXM_P.mJc[4] = 0;
  out->mDXM_P.mJc[5] = 0;
  out->mDXM_P.mJc[6] = 0;
  out->mDXM_P.mJc[7] = 0;
  out->mDXM_P.mJc[8] = 0;
  out->mDXM_P.mJc[9] = 0;
  out->mDXM_P.mJc[10] = 0;
  out->mDXM_P.mJc[11] = 0;
  out->mDXM_P.mJc[12] = 0;
  out->mDXM_P.mJc[13] = 0;
  out->mDXM_P.mJc[14] = 0;
  out->mDXM_P.mJc[15] = 0;
  out->mDXM_P.mJc[16] = 0;
  out->mDXM_P.mJc[17] = 0;
  out->mDXM_P.mJc[18] = 0;
  out->mDXM_P.mJc[19] = 0;
  out->mDXM_P.mJc[20] = 0;
  out->mDXM_P.mJc[21] = 0;
  out->mDXM_P.mJc[22] = 0;
  out->mDXM_P.mJc[23] = 0;
  out->mDXM_P.mJc[24] = 0;
  (void)sys;
  (void)out;
  return 0;
}

static int32_T ds_ddm (const NeDynamicSystem *sys, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)out;
  (void)sys;
  (void)out;
  return 0;
}

static int32_T ds_ddm_p (const NeDynamicSystem *sys, const NeDynamicSystemInput *
  t1, NeDsMethodOutput *out)
{
  (void)t1;
  out->mDDM_P.mNumCol = 0UL;
  out->mDDM_P.mNumRow = 8UL;
  out->mDDM_P.mJc[0] = 0;
  (void)sys;
  (void)out;
  return 0;
}

static int32_T ds_dum (const NeDynamicSystem *sys, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)out;
  (void)sys;
  (void)out;
  return 0;
}

static int32_T ds_dum_p (const NeDynamicSystem *sys, const NeDynamicSystemInput *
  t1, NeDsMethodOutput *out)
{
  (void)t1;
  out->mDUM_P.mNumCol = 4UL;
  out->mDUM_P.mNumRow = 8UL;
  out->mDUM_P.mJc[0] = 0;
  out->mDUM_P.mJc[1] = 0;
  out->mDUM_P.mJc[2] = 0;
  out->mDUM_P.mJc[3] = 0;
  out->mDUM_P.mJc[4] = 0;
  (void)sys;
  (void)out;
  return 0;
}

static int32_T ds_dtm (const NeDynamicSystem *sys, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)out;
  (void)sys;
  (void)out;
  return 0;
}

static int32_T ds_dtm_p (const NeDynamicSystem *sys, const NeDynamicSystemInput *
  t1, NeDsMethodOutput *out)
{
  (void)t1;
  out->mDTM_P.mNumCol = 1UL;
  out->mDTM_P.mNumRow = 8UL;
  out->mDTM_P.mJc[0] = 0;
  out->mDTM_P.mJc[1] = 0;
  (void)sys;
  (void)out;
  return 0;
}

static int32_T ds_dpm (const NeDynamicSystem *sys, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)out;
  (void)sys;
  (void)out;
  return 0;
}

static int32_T ds_dpm_p (const NeDynamicSystem *sys, const NeDynamicSystemInput *
  t1, NeDsMethodOutput *out)
{
  (void)t1;
  out->mDPM_P.mNumCol = 0UL;
  out->mDPM_P.mNumRow = 8UL;
  out->mDPM_P.mJc[0] = 0;
  (void)sys;
  (void)out;
  return 0;
}

static int32_T ds_vmm (const NeDynamicSystem *sys, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *out)
{
  (void)t1;
  out->mVMM.mX[0] = false;
  out->mVMM.mX[1] = false;
  out->mVMM.mX[2] = false;
  out->mVMM.mX[3] = false;
  out->mVMM.mX[4] = false;
  out->mVMM.mX[5] = false;
  out->mVMM.mX[6] = false;
  out->mVMM.mX[7] = false;
  (void)sys;
  (void)out;
  return 0;
}

static int32_T ds_dp_l (const NeDynamicSystem *sys, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)out;
  (void)sys;
  (void)out;
  return 0;
}

static int32_T ds_dp_i (const NeDynamicSystem *sys, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)out;
  (void)sys;
  (void)out;
  return 0;
}

static int32_T ds_dp_j (const NeDynamicSystem *sys, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)out;
  (void)sys;
  (void)out;
  return 0;
}

static int32_T ds_dp_r (const NeDynamicSystem *sys, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)out;
  (void)sys;
  (void)out;
  return 0;
}

static int32_T ds_qx (const NeDynamicSystem *sys, const NeDynamicSystemInput *t1,
                      NeDsMethodOutput *out)
{
  (void)t1;
  (void)out;
  (void)sys;
  (void)out;
  return 0;
}

static int32_T ds_qu (const NeDynamicSystem *sys, const NeDynamicSystemInput *t1,
                      NeDsMethodOutput *out)
{
  (void)t1;
  (void)out;
  (void)sys;
  (void)out;
  return 0;
}

static int32_T ds_qt (const NeDynamicSystem *sys, const NeDynamicSystemInput *t1,
                      NeDsMethodOutput *out)
{
  (void)t1;
  (void)out;
  (void)sys;
  (void)out;
  return 0;
}

static int32_T ds_q1 (const NeDynamicSystem *sys, const NeDynamicSystemInput *t1,
                      NeDsMethodOutput *out)
{
  (void)t1;
  (void)out;
  (void)sys;
  (void)out;
  return 0;
}

static int32_T ds_qx_p (const NeDynamicSystem *sys, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *out)
{
  (void)t1;
  out->mQX_P.mNumCol = 24UL;
  out->mQX_P.mNumRow = 24UL;
  out->mQX_P.mJc[0] = 0;
  out->mQX_P.mJc[1] = 0;
  out->mQX_P.mJc[2] = 0;
  out->mQX_P.mJc[3] = 0;
  out->mQX_P.mJc[4] = 0;
  out->mQX_P.mJc[5] = 0;
  out->mQX_P.mJc[6] = 0;
  out->mQX_P.mJc[7] = 0;
  out->mQX_P.mJc[8] = 0;
  out->mQX_P.mJc[9] = 0;
  out->mQX_P.mJc[10] = 0;
  out->mQX_P.mJc[11] = 0;
  out->mQX_P.mJc[12] = 0;
  out->mQX_P.mJc[13] = 0;
  out->mQX_P.mJc[14] = 0;
  out->mQX_P.mJc[15] = 0;
  out->mQX_P.mJc[16] = 0;
  out->mQX_P.mJc[17] = 0;
  out->mQX_P.mJc[18] = 0;
  out->mQX_P.mJc[19] = 0;
  out->mQX_P.mJc[20] = 0;
  out->mQX_P.mJc[21] = 0;
  out->mQX_P.mJc[22] = 0;
  out->mQX_P.mJc[23] = 0;
  out->mQX_P.mJc[24] = 0;
  (void)sys;
  (void)out;
  return 0;
}

static int32_T ds_qu_p (const NeDynamicSystem *sys, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *out)
{
  (void)t1;
  out->mQU_P.mNumCol = 4UL;
  out->mQU_P.mNumRow = 24UL;
  out->mQU_P.mJc[0] = 0;
  out->mQU_P.mJc[1] = 0;
  out->mQU_P.mJc[2] = 0;
  out->mQU_P.mJc[3] = 0;
  out->mQU_P.mJc[4] = 0;
  (void)sys;
  (void)out;
  return 0;
}

static int32_T ds_qt_p (const NeDynamicSystem *sys, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *out)
{
  (void)t1;
  out->mQT_P.mNumCol = 1UL;
  out->mQT_P.mNumRow = 24UL;
  out->mQT_P.mJc[0] = 0;
  out->mQT_P.mJc[1] = 0;
  (void)sys;
  (void)out;
  return 0;
}

static int32_T ds_q1_p (const NeDynamicSystem *sys, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *out)
{
  (void)t1;
  out->mQ1_P.mNumCol = 1UL;
  out->mQ1_P.mNumRow = 24UL;
  out->mQ1_P.mJc[0] = 0;
  out->mQ1_P.mJc[1] = 0;
  (void)sys;
  (void)out;
  return 0;
}

static int32_T ds_solverhits (const NeDynamicSystem *sys, const
  NeDynamicSystemInput *t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)out;
  (void)sys;
  (void)out;
  return 0;
}

static int32_T ds_var_tol (const NeDynamicSystem *sys, const
  NeDynamicSystemInput *t1, NeDsMethodOutput *out)
{
  (void)t1;
  out->mVAR_TOL.mX[0] = 1.0E-9;
  out->mVAR_TOL.mX[1] = 1.0E-9;
  out->mVAR_TOL.mX[2] = 1.0E-9;
  out->mVAR_TOL.mX[3] = 1.0E-9;
  out->mVAR_TOL.mX[4] = 1.0E-9;
  out->mVAR_TOL.mX[5] = 1.0E-9;
  out->mVAR_TOL.mX[6] = 1.0E-9;
  out->mVAR_TOL.mX[7] = 1.0E-9;
  out->mVAR_TOL.mX[8] = 1.0E-9;
  out->mVAR_TOL.mX[9] = 1.0E-9;
  out->mVAR_TOL.mX[10] = 1.0E-9;
  out->mVAR_TOL.mX[11] = 1.0E-9;
  out->mVAR_TOL.mX[12] = 1.0E-9;
  out->mVAR_TOL.mX[13] = 1.0E-9;
  out->mVAR_TOL.mX[14] = 1.0E-9;
  out->mVAR_TOL.mX[15] = 1.0E-9;
  out->mVAR_TOL.mX[16] = 1.0E-9;
  out->mVAR_TOL.mX[17] = 1.0E-9;
  out->mVAR_TOL.mX[18] = 1.0E-9;
  out->mVAR_TOL.mX[19] = 1.0E-9;
  out->mVAR_TOL.mX[20] = 1.0E-9;
  out->mVAR_TOL.mX[21] = 1.0E-9;
  out->mVAR_TOL.mX[22] = 1.0E-9;
  out->mVAR_TOL.mX[23] = 1.0E-9;
  (void)sys;
  (void)out;
  return 0;
}

static int32_T ds_eq_tol (const NeDynamicSystem *sys, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *out)
{
  (void)t1;
  out->mEQ_TOL.mX[0] = 1.0E-9;
  out->mEQ_TOL.mX[1] = 1.0E-9;
  out->mEQ_TOL.mX[2] = 1.0E-9;
  out->mEQ_TOL.mX[3] = 1.0E-9;
  out->mEQ_TOL.mX[4] = 1.0E-9;
  out->mEQ_TOL.mX[5] = 1.0E-9;
  out->mEQ_TOL.mX[6] = 1.0E-9;
  out->mEQ_TOL.mX[7] = 1.0E-9;
  out->mEQ_TOL.mX[8] = 1.0E-9;
  out->mEQ_TOL.mX[9] = 1.0E-9;
  out->mEQ_TOL.mX[10] = 1.0E-9;
  out->mEQ_TOL.mX[11] = 1.0E-9;
  out->mEQ_TOL.mX[12] = 1.0E-9;
  out->mEQ_TOL.mX[13] = 1.0E-9;
  out->mEQ_TOL.mX[14] = 1.0E-9;
  out->mEQ_TOL.mX[15] = 1.0E-9;
  out->mEQ_TOL.mX[16] = 1.0E-9;
  out->mEQ_TOL.mX[17] = 1.0E-9;
  out->mEQ_TOL.mX[18] = 1.0E-9;
  out->mEQ_TOL.mX[19] = 1.0E-9;
  out->mEQ_TOL.mX[20] = 1.0E-9;
  out->mEQ_TOL.mX[21] = 1.0E-9;
  out->mEQ_TOL.mX[22] = 1.0E-9;
  out->mEQ_TOL.mX[23] = 1.0E-9;
  (void)sys;
  (void)out;
  return 0;
}

static int32_T ds_sclv (const NeDynamicSystem *sys, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *out)
{
  (void)t1;
  out->mSCLV.mX[0] = false;
  out->mSCLV.mX[1] = false;
  out->mSCLV.mX[2] = false;
  out->mSCLV.mX[3] = false;
  out->mSCLV.mX[4] = false;
  out->mSCLV.mX[5] = false;
  out->mSCLV.mX[6] = false;
  out->mSCLV.mX[7] = false;
  out->mSCLV.mX[8] = false;
  out->mSCLV.mX[9] = false;
  out->mSCLV.mX[10] = false;
  out->mSCLV.mX[11] = false;
  out->mSCLV.mX[12] = false;
  out->mSCLV.mX[13] = false;
  out->mSCLV.mX[14] = false;
  out->mSCLV.mX[15] = false;
  out->mSCLV.mX[16] = false;
  out->mSCLV.mX[17] = false;
  out->mSCLV.mX[18] = false;
  out->mSCLV.mX[19] = false;
  out->mSCLV.mX[20] = false;
  out->mSCLV.mX[21] = false;
  out->mSCLV.mX[22] = false;
  out->mSCLV.mX[23] = false;
  (void)sys;
  (void)out;
  return 0;
}

static int32_T ds_y (const NeDynamicSystem *sys, const NeDynamicSystemInput *t7,
                     NeDsMethodOutput *out)
{
  real_T Voltage_Sensor3_V;
  out->mY.mX[6UL] = (t7->mX.mX[2UL] + t7->mX.mX[16UL]) - t7->mX.mX[16UL];
  out->mY.mX[0UL] = t7->mX.mX[18UL] - t7->mX.mX[19UL];
  out->mY.mX[1UL] = t7->mX.mX[10UL];
  Voltage_Sensor3_V = t7->mX.mX[10UL] - t7->mX.mX[13UL];
  out->mY.mX[3UL] = t7->mX.mX[13UL];
  out->mY.mX[5UL] = t7->mX.mX[15UL];
  out->mY.mX[2UL] = Voltage_Sensor3_V;
  out->mY.mX[4UL] = Voltage_Sensor3_V;
  (void)sys;
  (void)out;
  return 0;
}

static int32_T ds_dxy (const NeDynamicSystem *sys, const NeDynamicSystemInput
  *t13, NeDsMethodOutput *out)
{
  (void)t13;
  out->mDXY.mX[8UL] = 0.0;
  out->mDXY.mX[0UL] = 1.0;
  out->mDXY.mX[1UL] = 1.0;
  out->mDXY.mX[2UL] = 1.0;
  out->mDXY.mX[3UL] = 1.0;
  out->mDXY.mX[4UL] = -1.0;
  out->mDXY.mX[5UL] = 1.0;
  out->mDXY.mX[6UL] = -1.0;
  out->mDXY.mX[7UL] = 1.0;
  out->mDXY.mX[9UL] = 1.0;
  out->mDXY.mX[10UL] = -1.0;
  (void)sys;
  (void)out;
  return 0;
}

static int32_T ds_duy (const NeDynamicSystem *sys, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)out;
  (void)sys;
  (void)out;
  return 0;
}

static int32_T ds_duy_p (const NeDynamicSystem *sys, const NeDynamicSystemInput *
  t1, NeDsMethodOutput *out)
{
  (void)t1;
  out->mDUY_P.mNumCol = 4UL;
  out->mDUY_P.mNumRow = 7UL;
  out->mDUY_P.mJc[0] = 0;
  out->mDUY_P.mJc[1] = 0;
  out->mDUY_P.mJc[2] = 0;
  out->mDUY_P.mJc[3] = 0;
  out->mDUY_P.mJc[4] = 0;
  (void)sys;
  (void)out;
  return 0;
}

static int32_T ds_mduy_p (const NeDynamicSystem *sys, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *out)
{
  (void)t1;
  out->mMDUY_P.mNumCol = 4UL;
  out->mMDUY_P.mNumRow = 7UL;
  out->mMDUY_P.mJc[0] = 0;
  out->mMDUY_P.mJc[1] = 0;
  out->mMDUY_P.mJc[2] = 0;
  out->mMDUY_P.mJc[3] = 0;
  out->mMDUY_P.mJc[4] = 0;
  (void)sys;
  (void)out;
  return 0;
}

static int32_T ds_mdxy_p (const NeDynamicSystem *sys, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *out)
{
  (void)t1;
  out->mMDXY_P.mNumCol = 24UL;
  out->mMDXY_P.mNumRow = 7UL;
  out->mMDXY_P.mJc[0] = 0;
  out->mMDXY_P.mJc[1] = 0;
  out->mMDXY_P.mJc[2] = 0;
  out->mMDXY_P.mJc[3] = 0;
  out->mMDXY_P.mJc[4] = 0;
  out->mMDXY_P.mJc[5] = 0;
  out->mMDXY_P.mJc[6] = 0;
  out->mMDXY_P.mJc[7] = 0;
  out->mMDXY_P.mJc[8] = 0;
  out->mMDXY_P.mJc[9] = 0;
  out->mMDXY_P.mJc[10] = 0;
  out->mMDXY_P.mJc[11] = 0;
  out->mMDXY_P.mJc[12] = 0;
  out->mMDXY_P.mJc[13] = 0;
  out->mMDXY_P.mJc[14] = 0;
  out->mMDXY_P.mJc[15] = 0;
  out->mMDXY_P.mJc[16] = 0;
  out->mMDXY_P.mJc[17] = 0;
  out->mMDXY_P.mJc[18] = 0;
  out->mMDXY_P.mJc[19] = 0;
  out->mMDXY_P.mJc[20] = 0;
  out->mMDXY_P.mJc[21] = 0;
  out->mMDXY_P.mJc[22] = 0;
  out->mMDXY_P.mJc[23] = 0;
  out->mMDXY_P.mJc[24] = 0;
  (void)sys;
  (void)out;
  return 0;
}

static int32_T ds_tduy_p (const NeDynamicSystem *sys, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *out)
{
  (void)t1;
  out->mTDUY_P.mNumCol = 4UL;
  out->mTDUY_P.mNumRow = 7UL;
  out->mTDUY_P.mJc[0] = 0;
  out->mTDUY_P.mJc[1] = 0;
  out->mTDUY_P.mJc[2] = 0;
  out->mTDUY_P.mJc[3] = 0;
  out->mTDUY_P.mJc[4] = 0;
  (void)sys;
  (void)out;
  return 0;
}

static int32_T ds_dty (const NeDynamicSystem *sys, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *out)
{
  (void)t1;
  (void)out;
  (void)sys;
  (void)out;
  return 0;
}

static int32_T ds_dty_p (const NeDynamicSystem *sys, const NeDynamicSystemInput *
  t1, NeDsMethodOutput *out)
{
  (void)t1;
  out->mDTY_P.mNumCol = 1UL;
  out->mDTY_P.mNumRow = 7UL;
  out->mDTY_P.mJc[0] = 0;
  out->mDTY_P.mJc[1] = 0;
  (void)sys;
  (void)out;
  return 0;
}
