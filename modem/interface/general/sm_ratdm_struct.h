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
 *   sm_ratdm_struct.h
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
 ******************************************************************************/

#ifndef SM_RATDM_STRUCT_H
#define SM_RATDM_STRUCT_H

#include "kal_general_types.h"
#include "mcd_l3_inc_gprs_struct.h"
#include "l3_inc_local.h"
#include "kal_public_defs.h"

typedef struct {
    LOCAL_PARA_HDR  
    kal_uint8 nsapi;
    kal_uint8 pool_id;
    kal_uint8 context_id;  // originally in tcm_ratdm_config_req_struct
    module_type module_id;  // originally in tcm_ratdm_config_req_struct
} sm_ratdm_rab_activate_req_struct;

typedef struct {
    LOCAL_PARA_HDR   
    kal_uint8 nsapi;
} sm_ratdm_rab_activate_cnf_struct;

typedef struct {
    LOCAL_PARA_HDR  
    kal_uint8 no_of_nsapis;
    kal_uint8 nsapi_list[11];
} sm_ratdm_rab_activate_ind_struct;

typedef struct {
    LOCAL_PARA_HDR  
    kal_uint8 nsapi;
    kal_uint8 is_successful;
} sm_ratdm_rab_activate_rsp_struct;

typedef struct {
    LOCAL_PARA_HDR 
    kal_uint8 nsapi;
    kal_uint8 llc_sapi;
    qos_struct qos_negotiated;
    kal_uint8 radio_priority;
    kal_uint8 pfi;
    kal_uint8 data_comp_algo;
    kal_uint8 header_comp_algo;
    kal_uint8 pdp_addr_type;
    pdp_auxinfo_struct      aux_info; //erica 20070112
} sm_ratdm_activate_req_struct;

typedef struct {
    LOCAL_PARA_HDR   
    kal_uint8 nsapi;
} sm_ratdm_activate_cnf_struct;

typedef struct {
    LOCAL_PARA_HDR  
    kal_uint8 no_of_nsapis;
    kal_uint8 nsapi_list[11];
    kal_uint8 cause;
    kal_bool xid_neg_indicator[11];
} sm_ratdm_deactivate_req_struct;

typedef struct {
    LOCAL_PARA_HDR  
    kal_uint8 no_of_nsapis;
    kal_uint8 nsapi_list[11];
#ifdef __DIALUP_GPRS_COUNTER_SUPPORT__
    kal_uint64 tx_data_amount[11]; // new field for gprs call history
    kal_uint64 rx_data_amount[11]; // new field for gprs call history
#endif	
} sm_ratdm_deactivate_cnf_struct;

typedef struct {
    LOCAL_PARA_HDR  
    kal_uint8 no_of_nsapis;
    kal_uint8 nsapi_list[11];
} sm_ratdm_rab_deactivate_ind_struct;

typedef struct {
    LOCAL_PARA_HDR 
    kal_uint8 nsapi;    
    kal_uint8 radio_priority;
    kal_uint8 llc_sapi;
    qos_struct qos_negotiated;
    kal_uint8 pfi;
} sm_ratdm_modify_req_struct;

typedef struct {
    LOCAL_PARA_HDR 
    kal_uint8 nsapi;
} sm_ratdm_modify_cnf_struct;

typedef struct {
    LOCAL_PARA_HDR  
    kal_uint8 nsapi;
    kal_uint8 cause;
} sm_ratdm_status_ind_struct;

#endif /* SM_RATDM_STRUCT_H */
