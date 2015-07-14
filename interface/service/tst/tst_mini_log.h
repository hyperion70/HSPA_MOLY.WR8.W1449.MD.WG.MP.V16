/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
*
*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE. 
*
*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 * tst_mini_log.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file implements mini log related functions.  
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __TST_MINI_LOG_H__
#define __TST_MINI_LOG_H__
 
#include "kal_public_api.h" //MSBB change #include "kal_release.h"

/* !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
!!!                                                                                                                                                                                                          !!!
!!!  Mini_Log_Step 1. Add your static info type in MINI_LOG_STATIC_INFO_TYPE_T                                                                                        !!!
!!!  [Notice] The number and order of items in tst_mini_log_static_info_struct should be synchronized with MINI_LOG_STATIC_INFO_TYPE_T      !!!
!!!                                                                                                                                                                                                          !!!
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/

#ifdef __MINI_LOG_SUPPORT__
//definitions
typedef enum
{
  MINI_LOG_INFO_MODULE_MM,
  MINI_LOG_INFO_MODULE_MPAL,
  MINI_LOG_INFO_MODULE_ACS,
  MINI_LOG_INFO_MODULE_RRM,
  MINI_LOG_INFO_MODULE_RCS,
  MINI_LOG_INFO_MODULE_CSRR,
  MINI_LOG_INFO_MODULE_LAPDM,  
  MINI_LOG_INFO_MODULE_RR,  
  MINI_LOG_INFO_MODULE_L4C,
#ifdef __UMTS_FDD_MODE__
  MINI_LOG_INFO_MODULE_SIBE,
  MINI_LOG_INFO_MODULE_USIME,
  MINI_LOG_INFO_MODULE_CSE,
  MINI_LOG_INFO_MODULE_CSCE,
  MINI_LOG_INFO_MODULE_MEME,
  MINI_LOG_INFO_MODULE_DBME,
#ifdef __UAGPS_CP_SUPPORT__
  MINI_LOG_INFO_MODULE_UAGPS_CP,
#endif /* __UAGPS_CP_SUPPORT__ */
#ifdef __UAGPS_UP_SUPPORT__
  MINI_LOG_INFO_MODULE_UAGPS_UP,
#endif /* __UAGPS_CP_SUPPORT__ */
#endif /* __UMTS_FDD_MODE__ */
#if (defined(__UMTS_FDD_MODE__) || defined(__STORED_CELL_SELECTION_INFO__))
  MINI_LOG_INFO_MODULE_SCSI,
#endif
#ifdef __GEMINI__ 
    MINI_LOG_INFO_MODULE_RSVA,
#endif
#ifdef __UMTS_FDD_MODE__
  MINI_LOG_INFO_MODULE_SLCE,
#endif /* __UMTS_FDD_MODE__ */
  MINI_LOG_INFO_MODULE_SIM,
#ifdef __PS_SERVICE__ 
  MINI_LOG_INFO_MODULE_RLC,
  MINI_LOG_INFO_MODULE_REASM,
  MINI_LOG_INFO_MODULE_MAC,
#endif
#ifdef __MTK_TARGET__
#ifdef MTK_SLEEP_ENABLE
	MINI_LOG_INFO_MODULE_SM,
#ifdef __UMTS_RAT__
	MINI_LOG_INFO_MODULE_USM,
#endif
#endif
#ifdef __CENTRALIZED_SLEEP_MANAGER__
	MINI_LOG_INFO_MODULE_OSTD,
#endif
#endif
#ifdef __UMTS_FDD_MODE__
  MINI_LOG_INFO_MODULE_RRCE,
#endif /*__UMTS_FDD_MODE__*/
#if defined(__UMTS_FDD_MODE__)
  MINI_LOG_INFO_MODULE_URLC_RX, 
  MINI_LOG_INFO_MODULE_URLC_TX, 
#if defined(__RLC_HSDPA_COPRO__) || defined(__L2_HSUPA_COPRO__)
  MINI_LOG_INFO_MODULE_SEQ,
  MINI_LOG_INFO_MODULE_URLC_RX_DRV,
  #if defined(__L2_HSUPA_COPRO__)
  MINI_LOG_INFO_MODULE_URLC_TX_DRV,
  #endif
#endif
#endif
#ifdef __IS_BYTECOPY_SUPPORT__
  MINI_LOG_INFO_MODULE_BYTECOPY,
#endif /*__IS_BYTECOPY_SUPPORT__*/
#if defined(__UMTS_FDD_MODE__)
  MINI_LOG_INFO_MODULE_UMAC_RX,
  MINI_LOG_INFO_MODULE_UMAC_TX,
#endif
  MINI_LOG_INFO_MODULE_END
}
MINI_LOG_STATIC_INFO_TYPE_T;

#if defined(GEN_FOR_PC)

#include "sim_public_struct.h"

#if defined(__UMTS_FDD_MODE__)
#include "crlc_fsm.h"
#if defined(__RLC_HSDPA_COPRO__) || defined(__L2_HSUPA_COPRO__)
#include "rlc_drv_common.h"
#include "seq_fsm.h"
#ifdef __UL2_HSPA_PLUS_RX_COPRO__
#include "bytecopy_internal.h"
#endif /*__UL2_HSPA_PLUS_RX_COPRO__*/
#endif
#endif

#include "acs_utils.h"
#include "rrm_utils.h"
#include "rr_context.h"
#include "mm_mini_log.h"
#include "rcs_context.h"
#include "lapdm_context.h"
#include "rmc_context.h"
#include "mpal_context.h"
#ifdef __UMTS_FDD_MODE__
#include "sibe_context.h"
#include "usime_context.h"
#include "cse_context.h"
#include "csce_context.h"
#include "meme_context.h"
#include "dbme.h"
#ifdef __UAGPS_CP_SUPPORT__
#include "uagps_cp_context.h"
#endif /* __UAGPS_CP_SUPPORT__ */
#ifdef __UAGPS_UP_SUPPORT__
#include "uagps_up_context.h"
#endif /* __UAGPS_UP_SUPPORT__ */
#endif /* __UMTS_FDD_MODE__ */
#if (defined(__UMTS_FDD_MODE__) || defined(__STORED_CELL_SELECTION_INFO__))
#include "scsi_context.h"
#endif
#ifdef __GEMINI__
#include "rsva_create.h"
#endif
#ifdef __UMTS_FDD_MODE__
#include "slce_context.h"
#endif /* __UMTS_FDD_MODE__ */
#ifdef __MTK_TARGET__
#ifdef MTK_SLEEP_ENABLE
#include "l1sm.h"
#ifdef __UMTS_RAT__
#include "ul1sm.h"
#endif
#endif
#ifdef __CENTRALIZED_SLEEP_MANAGER__
#include "ostd_private.h"
#endif
#endif
#ifdef __UMTS_FDD_MODE__
#include "rrce_context.h"
#endif /* __UMTS_FDD_MODE__ */
#include "rmmi_context.h"

#ifdef __PS_SERVICE__
#include "mac_context.h"
#include "rlc_context.h"
#include "reasm_context.h"
#endif

#ifdef __UMTS_FDD_MODE__
#include "umac_context.h"
#endif

/* !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
!!!                                                                                                                                                                                                          !!!
!!!  Mini_Log_Step 2. Add your structure in tst_mini_log_static_info_struct, remember to add a dummy word for 4-bytes alignment.                  !!!
!!!  [Notice] The number and order of items in tst_mini_log_static_info_struct should be synchronized with MINI_LOG_STATIC_INFO_TYPE_T      !!!
!!!                                                                                                                                                                                                          !!!
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/

typedef struct
{
  mini_log_module_mm_struct mm_static_info;
  mpal_mini_log_struct          mpal_static_info;
  acs_mini_log_struct           acs_static_info;
  rrm_mini_dump_struct          rrm_static_info;
  rcs_mini_dump_struct          rcs_static_info;
  csrr_mini_dump_struct         csrr_static_info;  
  lapdm_mini_dump_struct        lapdm_static_info;  
  rr_mini_dump_struct           rr_static_info;  
  l4c_minilog_struct l4c_static_info;
#ifdef __UMTS_FDD_MODE__
  sibe_mini_dump_struct sibe_static_info;
  usime_mini_dump_struct usime_static_info;
  CSE_MiniDump  cse_static_info;
  csce_mini_dump_struct csce_static_info;
  meme_mini_dump_struct meme_static_info;
  dbme_mini_dump_struct dbme_static_info;
#ifdef __UAGPS_CP_SUPPORT__
  uagps_cp_mini_dump_struct uagps_cp_static_info;
#endif /* __UAGPS_CP_SUPPORT__ */
#ifdef __UAGPS_UP_SUPPORT__
  uagps_up_mini_dump_struct uagps_up_static_info;
#endif /* __UAGPS_CP_SUPPORT__ */
#endif /* __UMTS_FDD_MODE__ */
#if (defined(__UMTS_FDD_MODE__) || defined(__STORED_CELL_SELECTION_INFO__))
  SCSI_MiniDump  scsi_static_info;
#endif
#ifdef __GEMINI__
  rsva_mini_dump_struct        rsva_static_info;
#endif
#ifdef __UMTS_FDD_MODE__
  mini_log_module_slce_struct slce_static_info;
#endif /* __UMTS_FDD_MODE__ */
  mini_log_module_sim_struct	sim_static_info;
#ifdef __PS_SERVICE__
  gprs_rlc_mini_log_struct gprs_rlc_static_info;
  gprs_reasm_mini_log_struct gprs_reasm_static_info;
    gprs_mac_mini_log_struct       gprs_mac_static_info;
#endif
#ifdef __MTK_TARGET__
#ifdef MTK_SLEEP_ENABLE
	mini_log_module_sm_struct sm_static_info;
#ifdef __UMTS_RAT__
  mini_log_module_usm_struct usm_static_info;
#endif
#endif
#ifdef __CENTRALIZED_SLEEP_MANAGER__
  mini_log_module_ostd_struct ostd_static_info;
#endif
#endif
#ifdef __UMTS_FDD_MODE__
  rrce_mini_dump_struct	        rrce_static_info;
#endif /* __UMTS_FDD_MODE__ */
#if defined(__UMTS_FDD_MODE__)
  urlc_mini_log_rx_struct urlc_rx_static_info;
  urlc_mini_log_tx_struct urlc_tx_static_info;  
#if defined(__RLC_HSDPA_COPRO__) || defined(__L2_HSUPA_COPRO__)
  urlc_mini_log_seq_struct      urlc_seq_static_info;
  urlc_mini_log_rx_drv_struct   urlc_rx_drv_static_info;
  #if defined(__L2_HSUPA_COPRO__)
  urlc_mini_log_tx_drv_struct urlc_tx_drv_static_info;
  #endif
#ifdef __UL2_HSPA_PLUS_RX_COPRO__
  bc_mini_log_struct bc_static_info;
#endif /*__UL2_HSPA_PLUS_RX_COPRO__*/
  
#endif
#endif  
#if defined(__UMTS_FDD_MODE__)
  mini_log_module_umac_rx_struct	umac_rx_static_info;
  mini_log_module_umac_tx_struct	umac_tx_static_info;
#endif
}
tst_mini_log_static_info_struct;
#endif


/* !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
!!!                                                                                                                                                                                                          !!!
!!!  Mini_Log_Step 3. Register your callback function by tst_mini_log_callback_register                                                                                    !!!
!!!                                                                                                                                                                                                          !!!
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/


/*
* dst_buf: copy the desired data to dst_buf
* bytes: the number of bytes to copy
* return value: the number of bytes that this function really stores. Normally, it should match "bytes" parameter
*/
typedef kal_uint32 (*Mini_log_store_saving_bytes)(char *dst_buf, kal_uint32 bytes);

kal_bool tst_mini_log_callback_register(MINI_LOG_STATIC_INFO_TYPE_T info_type, Mini_log_store_saving_bytes fnCmd, kal_uint32 bytes_to_save);

#endif //#ifdef __MINI_LOG_SUPPORT__

#endif //__TST_MINI_LOG_H__
