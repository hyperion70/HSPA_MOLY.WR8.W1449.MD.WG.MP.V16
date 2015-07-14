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

/*******************************************************************************
 * Filename:
 * ---------
 *	mm2mmi_struct.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for structure definition between MM and MMI.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 * 				HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------
 * removed!
 *
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
 *==============================================================================
 *******************************************************************************/

/********************************************************************************
*  Copyright Statement:
*  --------------------
*
*  This product has been developed using a protocol stack
*  developed by Sasken Communication Technologies Limited.
*
********************************************************************************/


/*******************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2002
*
*******************************************************************************
 *  FILENAME : mm2mmi_struct.h
 *  SYNOPSIS : Functions for encoding/decoding.
 *
 *                      R E V I S I O N    H I S T O R Y
 *
 */
#ifndef _MM2MMI_STRUCT_H
#define _MM2MMI_STRUCT_H

#include "kal_general_types.h"
#include "ps_public_enum.h"
#include "l3_inc_enums.h"
#include "mcd_mm_common_gen_struct.h"
#include "mcd_l3_inc_struct.h"
#include "l3_inc_local.h"
#include "mm_mmi_enums.h"
#include "kal_public_defs.h"

typedef struct {
    LOCAL_PARA_HDR
    domain_id_enum attach_type;
    mm_cause_enum cause; /* failure cause*/
    kal_uint8 att_id; /* Johnny: 3G RAC, for attach_req and detach_req using */	
    mm_cause_enum abnormal_lu_cause; /* MAUI_01650679 */
    kal_bool is_on_hplmn;
    cell_info_and_rat_struct cell_info; /* registered cell info*/
} gmmreg_attach_cnf_struct;

typedef struct {
    LOCAL_PARA_HDR
    domain_id_enum detach_type;
    mm_cause_enum cause;
    kal_bool issearching; /* is searching on going*/
    kal_bool is_reged; /* Johnny: 3G RAC */
    kal_uint8 att_id; /* Johnny: 3G RAC, for attach_req and detach_req using */
    kal_bool is_on_hplmn;
    cell_info_and_rat_struct cell_info; /* current cell info*/
} gmmreg_detach_ind_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_bool full_nw_nameP;
    kal_uint8 full_nw_name_len;
    kal_uint8 full_nw_name[24];
    kal_bool short_nw_nameP;
    kal_uint8 short_nw_name_len;
    kal_uint8 short_nw_name[24];
    kal_bool nw_time_zoneP;
    kal_uint8 nw_time_zone;
    kal_bool nw_time_zone_timeP;
    nw_time_zone_time_struct nw_time_zone_time;
    kal_bool lsa_idP;
    kal_uint8 lsa_id_len;
    kal_uint8 lsa_id[3];
    kal_bool nw_day_light_saving_timeP;
    kal_uint8 nw_day_light_saving_time;
    /* MAUI_01664028, mtk02118: added for MMI to exactly know which PLMN the NITZ comes from  */
    plmn_id_struct plmn_id;
} gmmreg_nw_info_struct; /* This struct shall be the same with l4crac_nw_info_ind_struct. */

typedef struct {
    LOCAL_PARA_HDR
    data_speed_support_enum cell_data_speed_support; /* mtk02475: for edge and hspa status */    
    kal_bool is_on_hplmn;
    cell_info_and_rat_struct cell_info;
    kal_bool is_ra_code_valid;
    kal_bool is_from_cgi_ind;
} gmmreg_cell_info_update_ind_struct;

/* For GPRS MMI. */
typedef struct {
    LOCAL_PARA_HDR
    gmmreg_ps_service_info_enum current_status; /* gmmreg_ps_service_info_enum */
} gmmreg_ps_service_info_ind_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 is_gsm_conn_exist;
    gmmreg_cipher_ind_enum gsm_cipher_cond; 
    gmmreg_cipher_ind_enum gprs_cipher_cond; 
} gmmreg_cipher_ind_struct; /* must same as l4crac_cipher_ind_struct */

typedef struct {
    LOCAL_PARA_HDR
    kal_bool is_dedicated_mode;
} gmmreg_dedicated_mode_ind_struct; /* must same as l4crac_hz_dedicated_mode_ind_struct */

typedef struct {
    LOCAL_PARA_HDR
    proc_status_enum status;          /* proc_status_enum */
    mm_cause_enum cause;           /* mm_cause_enum */
    kal_bool is_on_hplmn;
    cell_info_and_rat_struct cell_info;
} gmmreg_plmn_search_cnf_struct;

typedef struct {
    LOCAL_PARA_HDR
    proc_status_enum status;         /* proc_status_enum */
    mm_cause_enum  cause;          /* mm_cause_enum */
    kal_uint8 num_of_hplmn;
    rac_plmn_list_struct plmn_list;
} gmmreg_plmn_list_cnf_struct;

typedef gmmreg_plmn_list_cnf_struct gmmreg_plmn_list_ind_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 susp_id;
} gmmreg_suspend_status_ind_struct;

#ifdef __CSG_SUPPORT__
typedef struct {
    LOCAL_PARA_HDR
    proc_status_enum status;
    mm_cause_enum cause;
    rac_csg_list_struct csg_list;
} gmmreg_csg_list_cnf_struct;
#endif

typedef struct {
    LOCAL_PARA_HDR
    proc_status_enum status;         /* proc_status_enum */
    mm_cause_enum cause;          /* mm_cause_enum */
} gmmreg_set_rat_mode_cnf_struct;

typedef gmmreg_nw_info_struct gmmreg_nw_info_ind_struct;

#ifdef __GEMINI__
typedef struct {
    LOCAL_PARA_HDR
    rr_suspend_mode_reason_enum rr_service_status;
}gmmreg_rr_service_status_ind_struct; //20080217
#endif

//__REL5__
typedef struct l3_addr_bcd_struct
{
	kal_uint8 addr_length;
	kal_uint8 addr_bcd[41];
} l3_addr_bcd_struct;

typedef struct {
	kal_uint8          category;
	l3_addr_bcd_struct	tel_number;
} ecc_number_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 no_ecc; //number of ECC list
    ecc_number_struct ecc_list[16]; //ECC list
} gmmreg_nw_ecc_ind_struct;
//~ __REL5__

typedef struct {
    LOCAL_PARA_HDR
    end_session_result_enum result;
}gmmreg_end_ps_data_session_cnf_struct;

typedef struct {
    LOCAL_PARA_HDR
    susp_resu_result_enum result;
}gmmreg_susp_resu_update_cnf_struct;

#if defined (__MMDC__) && defined (__MMDC_TYPE1_DUAL_LOAD__)
typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;         //20120215 mtk80370: please DO NOT change the order of element in this struct
    //module_type peer_module;  /*20120229 mtk80370: No needed */
    mm_proc_enum mm_peer_procedure;
    mm_cause_enum mm_peer_reject_cause;
    plmn_id_struct mm_peer_plmn_id;
}gmmreg_peer_reject_ind_struct;

typedef struct {
	kal_uint8 ref_count;
	kal_uint16 msg_len;
	ind_type_enum ind_type;
	as_cell_type_enum cell_type;
}gmmreg_to_peer_info_ind_struct;
#endif /* __MMDC_LR_REJECT__ */

#endif 

