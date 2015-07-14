/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2007
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

/*******************************************************************************
 * Filename:
 * ---------
 *   ratcm_csce_struct.h
 *
 * Project:
 * --------
 *   MONZA
 *
 * Description:
 * ------------
 *
 *
 * Author:
 * -------
 * -------
 *
 * ==========================================================================
 * $Log:$
 *
 * 01 17 2014 vend_yuhhwang.yu
 * [MOLY00026316] ???libnvram_daemon_callback  ????IMEI LID ??
 * .
 *
 * 12 19 2012 rachel.liu
 * [MOLY00007503] [for LGE] WCDMA Dynamic Band Setting
 * .
 *
 * 11 15 2012 yunqi.wang
 * [MOLY00006217] 卡槽1插白卡-不连接终测仪开机-过一段时间-连接中测仪器-无法注册网络
 * plmn-search on specified uarfcn
 * 
 * 10 05 2012 mw.hsu
 * [MOLY00004236] [interface][service][kal]remove stack_ltlcom.h
 * .
 * 
 * 09 04 2012 ye.yuan
 * [MOLY00003052] [FDD2TDD][vodafone][QC-497]-3G VAP - DUT does not receives LAU&RAU reject cause#15 after 12h of the first LAU&RAU reject casue#15
 * csce part.
 *
 * 07 05 2012 c-hua.yang
 * [MOLY00000280] Decide and update "Home Country MCC" by MM
 * .
 *
 * 01 06 2012 chi-chung.lin
 * removed!
 * .
 *
 * 11 10 2011 c-hua.yang
 * removed!
 * .
 *
 * 05 24 2011 mw.hsu
 * removed!
 * .
 *
 * 12 17 2010 mw.hsu
 * removed!
 * .
 *
 * 12 14 2010 dennis.weng
 * removed!
 * .
 *
 * 10 20 2010 cosine.jheng
 * removed!
 * [RATCM][RHR]Check in ratcm file in uas\interface
 *
 * 10 08 2010 mw.hsu
 * removed!
 * .
 *
 * 08 09 2010 dennis.weng
 * removed!
 * .
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * Modified for ANY PLMN found H/R-PLMN cell, then perform Given PLMN Search while directly camped on.
 *
 * removed!
 * removed!
 * Handle REGN_STATUS_UPDATE_REQ from RATCM.
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * Add copyright header.
 ****************************************************************************/

#ifndef _RATCM_CSCE_STRUCT_H
#define _RATCM_CSCE_STRUCT_H

/* MAUI_02828210, redundant header removal */
//#include "ratcm_uas_enums.h"
//#include "ratcm_uas_struct.h"
//#include "ratcm_csce_enums.h"
#include "l3_inc_local.h"
#include "kal_public_api.h"
#include "kal_general_types.h"
#include "l3_inc_enums.h"
#include "mcd_l3_inc_struct.h"
#include "ps_public_enum.h"
#include "ps_public_struct.h"

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

/**************************************************************
 * RATCM_CSCE_INIT_REQ
 *
 * Sent from RATCM to CSCE to initialise UAS 
 * 1.IMEI number.
 * 2.preferred_GSM_band is the working band info from NVRAM.
 * 3.working_UMTS_FDD_band is the working band info transferred from 
 * Upper layer also with byte 0 indicates the band info of band I - VIII.
 * where second byte indicates the band info of band IX - X.
 * (LSB of byte 1 is used for band IX and X)
 ***************************************************************/   
typedef struct
{
    LOCAL_PARA_HDR

    kal_uint8  requested_gsm_band;
    kal_uint8  imeisv_value_digit0;
#ifdef __HSPA_PREFERENCE_SETTING__
    hspa_preference_enum hspa_preference; /* MAUI_02361221: hspa on-off preference */
#endif
    kal_uint8  requested_umts_bands[4];
    kal_uint8  imeisv_value_digit_byte[8];
}ratcm_csce_init_req_struct;

typedef struct
{
    LOCAL_PARA_HDR

    kal_uint8  imeisv_value_digit0;
    kal_uint8  imeisv_value_digit_byte[8];
}ratcm_csce_set_imei_req_struct;

/***********************/
/* RATCM_CSCE_INIT_CNF */
/***********************/
// No local parameter for this primitive


/******************************/
/* RATCM_CSCE_PLMN_SEARCH_REQ */
/******************************/
/* Scenario 1: PLMN Selection, automatic mode, normal case
   PLMNSearchType == SINGLE_PLMN

   At power-on, the non-access stratum (NAS) selects the PLMN with
   highest priority, possibly the last PLMN stored prior to previous
   power off. The access stratum (AS) is requested to find a cell
   belonging to that PLMN.

   When searching for the requested PLMN and in order to speed up the
   search, AS may use a list of cell information stored prior to
   previous power-off. When a cell belonging to the requested PLMN is
   found, that cell is selected and NAS is notified that the PLMN was
   found (ref: [25.304;10.4]).

   Initiates search for cell with given PLMN Identity, (or one of its equivalent),
   or any PLMN.On receipt of a new PLMN identity list, the previously stored equivalent
   PLMN list is discarded.The search type also allows a search for a given PLMN to be made
   excluding or allowing cells from Forbidden LAs.  Forbidden LAs are not taken into
   account for a PLMN search of type "any". If forbidden LAs are allowed then AS can
   camp on a cell regardless whether it is in a forbidden Location Area or not and this
   will continue until either a new UGC-CELL-SELECTION_CONTROL _REQ or a new
   GC-PLMN-SEARCH-REQ is issued.
 */
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8              trx_id;
    kal_uint8              plmn_count;
    kal_bool               is_manual_sel;
    kal_bool               is_ir_cell_resel_allowed;
    /* Viola 20090302
     * This flag is used to indicate if current PLMN Search is triggered by RSSI Sniffer
     * UL1 detects a cell and sent signal_appear_ind. 
     * NAS starts PLMN Search with (trigger_by_signal_appear = KAL_TRUE) since some cells appear.  
     */
    kal_bool               trigger_by_signal_appear;
#ifdef __UMTS_R7__
    kal_bool               is_higher_plmn_search;
#endif

#ifdef __CSG_SUPPORT__
    kal_bool               is_manual_csg_sel;
    kal_uint32             csg_id;
#endif

    kal_uint16			   factory_mode_arfcn;
    
    plmn_search_type_enum  plmn_search_type;
    plmn_id_struct         plmn_id[MAX_NUM_SEARCH_PLMN]; 
} ratcm_csce_plmn_search_req_struct;

/******************************/
/* RATCM_CSCE_PLMN_SEARCH_CNF */
/******************************/
/* Note: the GC PLMN Search Confirm should only be used when the
   requested PLMN Id is found.  The failure case use a the list
   primitive. */
typedef struct
{
    LOCAL_PARA_HDR
    kal_bool                  is_plmn_list_valid;
    kal_uint8                 trx_id;
    plmn_search_result_enum   result;

#ifdef __R6_NETWORK_SHARING__        
    as_cell_type_enum         multi_selected_cell_type[MAX_NUM_MULTI_PLMN];
#endif    
    as_cell_type_enum         selected_cell_type; //20081027: Quick PLMN Recovery ANY PLMN on H/R-PLMN cell

#ifdef __R6_NETWORK_SHARING__    
    kal_uint8                 multi_plmn_count;
    /* Range: 1 to MAX_NUM_MULTI_PLMN, only valid if result == PLMN_FOUND */
    plmn_id_struct            multi_selected_plmn[MAX_NUM_MULTI_PLMN];
#endif    
    plmn_id_struct            selected_plmn;    /* only valid if result == PLMN_FOUND *//* Reserved for before R6*/
    as_plmn_list_struct       plmn_list;
} ratcm_csce_plmn_search_cnf_struct;

/*********************************************/
/* RATCM_CSCE_START_TIMER_OUT_OF_SERVICE_IND */
/*********************************************/
// No local parameter for this primitive


/****************************/
/* RATCM_CSCE_PLMN_LOSS_IND */
/****************************/
/* This primitive is used when the selected PLMN is LOST */
typedef struct
{
    LOCAL_PARA_HDR
    as_plmn_list_struct plmn_list;
} ratcm_csce_plmn_loss_ind_struct;

/*********************************/
/* RATCM_CSCE_RRC_DEACTIVATE_REQ */
/*********************************/
/*
REQ: Signals that UMTS RRC must become inactive.
Note: This primitive may be received in idle mode,
subsequently to a NAS request for a PLMN search on another RAT
*/
// No local parameter for this primitive

/*********************************/
/* RATCM_CSCE_RRC_DEACTIVATE_CNF */
/*********************************/
// No local parameter for this primitive

/****************************/
/* RATCM_CSCE_PLMN_LIST_REQ */
/****************************/
/* This service provides the list of currently available PLMN. */
typedef struct
{
    LOCAL_PARA_HDR
    kal_bool is_manual_list;  
} ratcm_csce_plmn_list_req_struct;


/*********************************/
/* RATCM_CSCE_PLMN_LIST_STOP_REQ */
/*********************************/
/**
 * The NAS may stop the search for PLMN on the rest
 *  of the carriers.
 */
// No local parameter for this primitive



/***********************************/
/* RATCM_CSCE_ADD_FORBIDDEN_LA_REQ */
/***********************************/
/* Scenario: NAS Controlled Cell Selection

   NAS may influence the cell selection and reselection by sending
   control information to AS. This information can include, for
   example, lists of forbidden registration areas and a list of NAS
   defined service areas in priority order. The control information is
   used by AS in cell selection and reselection:

   - Cells belonging to a forbidden registration area will only be
   selected if no better cell is found. At this point, the services
   provided the UE might be limited.

   - Cells belonging to a NAS defined service area with higher
   priority than current service area will be considered better than
   the cell currently camped on. Depending on radio access mode, the
   most suitable cell in idle mode may not be the most suitable cell
   in connected mode. */
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8              la_code[2];
    forbidden_la_type_enum forbidden_la_type;
    plmn_id_struct         plmn_id;
} ratcm_csce_add_forbidden_la_req_struct;

/***********************************/
/* RATCM_CSCE_DEL_FORBIDDEN_LA_REQ */
/***********************************/
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8              la_code[2];
    plmn_id_struct         plmn_id;
    kal_bool               delete_all;
} ratcm_csce_del_forbidden_la_req_struct;

/**************************************/
/* RATCM_CSCE_EQ_PLMN_LIST_UPDATE_REQ */
/**************************************/
/*
This primitive is sent by NAS whenever it obtains the equivalent PLMN list.
The PLMN Identity list contains the PLMN Id of the current PLMN.A new list
overrides the previously stored "equivalent PLMN" list. This primitive may
be received at any time, while the UMTS RAT is either active or inactive.

To delete the PLMN ID List, NAS will send a list containing 1 PLMN ID, i.e.
currently active one.
The first element in the array of eq_plmn_id is rplmn.
*/
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8        eq_plmn_count;/* Range: 1 to MAX_NUM_EQ_PLMN. */
    plmn_id_struct   eq_plmn_id[MAX_NUM_EQ_PLMN];
}ratcm_csce_eq_plmn_list_update_req_struct;

/*******************************/
/* RATCM_CSCE_SET_RAT_MODE_REQ */
/*******************************/
typedef struct
{
    LOCAL_PARA_HDR
    rat_enum   rat;
}ratcm_csce_set_rat_mode_req_struct;

/*
Yongjiao 20100612 MAUI_20542230
Add  RATCM_CSCE_SET_RAT_MODE_CNF to resolve 2G_3G_L1 conflict
*/
/*******************************/
/* RATCM_CSCE_SET_RAT_MODE_CNF */
/*******************************/
typedef struct
{
    LOCAL_PARA_HDR
}ratcm_csce_set_rat_mode_cnf_struct;

/***********************/
/* RATCM_CSCE_RFON_REQ */
/***********************/
// No local parameter for this primitive

/***********************/
/* RATCM_CSCE_RFON_CNF */
/***********************/
// No local parameter for this primitive

/************************/
/* RATCM_CSCE_RFOFF_REQ */
/************************/
// No local parameter for this primitive

/************************/
/* RATCM_CSCE_RFOFF_REQ */
/************************/
// No local parameter for this primitive

/**************************/
/* REGN_STATUS_UPDATE_REQ */
/**************************/
/**
 * Gibran 20080320: MONZA00006851
 * NAS will directly send REGN_STATUS_UPDATE_REQ to CSCE
 * since RRCE will save REGN_STATUS_UPDATE_REQ 
 * when it is configuring lower layer. 
 */
typedef struct
{
    LOCAL_PARA_HDR
    plmn_search_status_enum   plmn_search_status;
    plmn_search_type_enum     plmn_search_type;

    /* Viola 20090302
     * Add proc_status to inform CSCE current NAS procedure.
     * CSCE mainly cares 5 procedures,
     * ATTACH_PROCEDURE_SUCCESS, RAU_PROCEDURE_SUCCESS, LU_PROCEDURE_SUCCESS, MS_IN_LIMITED_SERVICE, MS_IN_NO_SERVICE         
     */
    regn_proc_status_enum     proc_status;

#ifdef __REL8__
    kal_uint8  r_eq_plmn_count;
    plmn_id_struct r_eq_plmn_id[MAX_NUM_EQ_PLMN];
#endif
}ratcm_csce_regn_status_update_req_struct;


/**************************/
/* RATCM_UAS_SIGNAL_APPEAR_IND */
/* This message is used by CSCE to inform NAS that some cells appear in No Service status. */
/**************************/
typedef struct
{
    LOCAL_PARA_HDR

} ratcm_uas_signal_appear_ind_struct;

/**************************************/
/* RATCM_CSCE_EHPLMN_INFO_UPDATE_REQ */
/* This message is used by RATCM to forward EHPLMN list to CSCE */
/**************************************/
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 plmn_id_count;
    plmn_id_struct plmn_id[MAX_NUM_HPLMN];
    kal_uint8 home_country_mcc[3];
}ratcm_csce_hplmn_info_update_req_struct;

#ifdef __CSG_SUPPORT__
/**************************************/
/* RATCM_CSCE_UPDATE_ALLOWED_CSG_LIST_REQ */
/* This message is used by RATCM to add/delete Allowed CSG to CSCE */
/**************************************/
typedef struct {
    LOCAL_PARA_HDR
    csg_update_type_enum csg_update_type;
    plmn_id_struct plmn_id;
    kal_uint32 csg_id;
} ratcm_csce_update_allowed_csg_list_req_struct;

/**************************************/
/* RATCM_CSCE_CSG_LIST_REQ */
/* This message is used by RATCM to request CSCE to do manual CSG list */
/**************************************/
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 plmn_count;
    plmn_id_struct plmn_id[MAX_NUM_EQ_PLMN];
} ratcm_csce_csg_list_req_struct;

/*********************************/
/* RATCM_CSCE_CSG_LIST_STOP_REQ */
/*********************************/
// No local parameter for this primitive
#endif /* __CSG_SUPPORT__ */

#ifdef __GEMINI__
/**************************/
/* RATCM_CSCE_SIM_STATUS_UPDATE_REQ */
/* This message is used by NAS to inform CSCE current SIM Status */
/**************************/
typedef struct
{
    LOCAL_PARA_HDR
    sim_config_status_enum sim_config_status;
    sim_insert_status_enum sim_insert_status;
} ratcm_csce_sim_status_update_req_struct;

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

#endif

#ifdef __DYNAMIC_BAND_SEL__
/**************************/
/* RATCM_CSCE_SET_PREFERRED_BAND_REQ */
/* This message is used by NAS to inform CSCE that GSM or UMTS FDD band changed */
/**************************/
typedef struct {
    LOCAL_PARA_HDR
    kal_bool is_gsm_band_present;  /* 2G band change */
    kal_bool is_umts_band_present; /* 3G band change */
    kal_uint8 gsm_band;
    kal_uint8 umts_fdd_band[SIZE_OF_UMTS_BAND];
}ratcm_csce_set_preferred_band_req_struct;
#endif

#endif /* RATCM_CSCE_STRUCT_H */
