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
 *   tcm_ratdm_struct.h
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
 * -------
 * $Log$
 *
 * 12 06 2012 andrew.wu
 * [MOLY00007098] LOCAL_PARA_HDR/PEER_BUF_HDR modification
 * LOCAL_PARA_HDR/PEER_BUF_HDR modification
 * 
 * 08 07 2012 andrew.wu
 * [MOLY00001588] [MT6575_ADAPT][LTE-BTR-1-7302] Bad audio qualilty in 12.2Kbps Uplink
 * [uas]URLC TM queue switchable modification
 *
 * 05 04 2012 carlson.lin
 * removed!
 * <saved by Perforce>
 *
 * 04 24 2012 wcpuser_integrator
 * removed!
 * .
 *
 * 04 02 2012 carlson.lin
 * removed!
 * <saved by Perforce>
 *
 * 01 30 2012 poying.chuang
 * removed!
 * .
 *
 * 01 11 2012 carlson.lin
 * removed!
 * <saved by Perforce>
 *
 * 01 11 2012 carlson.lin
 * removed!
 * <saved by Perforce>
 *
 * 12 24 2010 max.yin
 * removed!
 * .
 *
 * 12 22 2010 max.yin
 * removed!
 * .
 *
 * 12 14 2010 max.yin
 * removed!
 * .
 *
 * 10 18 2010 max.yin
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
 * 
 *
 ******************************************************************************/

#ifndef TCM_RATDM_STRUCT_H
#define TCM_RATDM_STRUCT_H

#include "kal_general_types.h"
#include "ps_public_enum.h"
//#include "ps_ratdm_struct.h"
#include "kal_public_defs.h" //MSBB change #include "stack_config.h"
#include "dcl.h"
#ifdef __UMTS_RAT__
#include "uas_common_enums.h"
#endif // ~ #ifdef __UMTS_RAT__

#if !defined(__MTK_TARGET__) && defined(__RATDM_UT__)
typedef struct {
    LOCAL_PARA_HDR  
    kal_uint8 nsapi;
    kal_uint8 pool_id;
} tcm_ratdm_data_req_struct;

typedef struct {
    LOCAL_PARA_HDR  
    kal_uint8 nsapi;
    kal_uint8 pool_id;
} tcm_ratdm_data_ind_struct;
#endif // ~ #if !defined(__MTK_TARGET__) && defined(__RATDM_UT__)

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 nsapi;
    kal_uint16 npdu_num;
    kal_uint8 ti;
} ratdm_process_tx_queue_ind_struct;

#ifdef __UMTS_RAT__
typedef struct {
    LOCAL_PARA_HDR
    
    // below elements are the same as SHAQ_csr_data_req_struct
    kal_uint16   pdu_len;
    kal_uint8    ref_count_2;
    kal_uint8    pb_resvered;
    kal_uint16   free_header_space;
    kal_uint16   free_tail_space;

    void *next_shaqElmt; 

    kal_uint16      bitLength;    
    kal_uint16      frame_index;
                
    ExtendedRbId    RBId;
    kal_bool       queued_enabled;
    kal_uint16      dummy;
} ratdm_shaq_print_cs_q_element_struct;
#endif // ~ #ifdef __UMTS_RAT__

typedef struct {
    LOCAL_PARA_HDR  
    kal_uint8 context_id;
    kal_uint8 nsapi;
    module_type module_id;
    kal_bool dummy_result; // dummy in config req
} tcm_ratdm_config_req_struct; // HSPA Optimization, remove TCM from data path

typedef struct {
    LOCAL_PARA_HDR  
    kal_uint8 context_id;
    kal_uint8 nsapi;
    module_type module_id;
    kal_bool result;
} tcm_ratdm_config_cnf_struct; // HSPA Optimization, remove TCM from data path

typedef struct {
    LOCAL_PARA_HDR  
    kal_uint8 context_id;
    kal_uint8 nsapi;
    module_type module_id;
} tcm_ratdm_deconfig_req_struct; // HSPA Optimization, remove TCM from data path

typedef struct {
    LOCAL_PARA_HDR  
    kal_bool result;
    kal_uint8 context_id;
    kal_uint8 nsapi;
    module_type module_id;
    kal_uint64	rx_data_octets;
    kal_uint64	rx_data_pkt_num;
    kal_uint64	tx_data_octets;
    kal_uint64	tx_data_pkt_num;
} tcm_ratdm_deconfig_cnf_struct; // HSPA Optimization, remove TCM from data path

typedef struct {
    LOCAL_PARA_HDR  
    //UART_PORT uart_port_number;        
    kal_uint8 src_id;
    kal_uint8 context_id;
    pdp_addr_type_enum pdp_type;
    kal_uint8 channel_id;
    module_type module_id;
} tcm_ratdm_enter_data_mode_req_struct; // HSPA Optimization, remove TCM from data path

typedef struct {
    LOCAL_PARA_HDR 
    UART_PORT uart_port_number;        
    kal_uint8 src_id;
    kal_uint8 context_id;
    module_type module_id;
    kal_uint8 result;
    kal_uint16 error_cause;
} tcm_ratdm_enter_data_mode_cnf_struct; // HSPA Optimization, remove TCM from data path

typedef struct {
    LOCAL_PARA_HDR  
    kal_uint16 query_serial_number; // for number between 0~255, it is used by L4C, for numbers > 255, it is used by TCM it self
} tcm_ratdm_query_ps_statistics_req_struct; // HSPA Optimization, remove TCM from data path

typedef struct {
    LOCAL_PARA_HDR  
    kal_uint16 query_serial_number; // for number between 0~255, it is used by L4C, for numbers > 255, it is used by TCM it self
    kal_uint8 no_of_nsapis;
    kal_uint8 reserved_1[1]; // to 8 bytes alignment
    kal_uint8 nsapi_list[11];
    kal_uint8 reserved_2[5]; // to 8 bytes alignment
    kal_uint8 context_id_list[11];
    kal_uint8 reserved_3[5]; // to 8 bytes alignment
    kal_uint64 rx_data_octets[11];
    kal_uint64 rx_data_pkt_num[11];
    kal_uint64 tx_data_octets[11];
    kal_uint64 tx_data_pkt_num[11];
} tcm_ratdm_query_ps_statistics_cnf_struct; // HSPA Optimization, remove TCM from data path

typedef struct {
    LOCAL_PARA_HDR  
    kal_uint16 reset_serial_num; // for number between 0~255, it is used by L4C, for numbers > 255, it is used by TCM it self
    kal_uint8 no_of_nsapis;
    kal_uint8 nsapi_list[11];
} tcm_ratdm_reset_ps_statistics_req_struct;

typedef struct {
    LOCAL_PARA_HDR   
    kal_uint16 reset_serial_num; // for number between 0~255, it is used by L4C, for numbers > 255, it is used by TCM it self
} tcm_ratdm_reset_ps_statistics_cnf_struct;

#ifdef __HSDPA_SUPPORT__
typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 no_of_nsapis;
    kal_uint8 nsapi_list[11];
    data_speed_activate_enum capability[11];
} tcm_ratdm_ps_bearer_capability_ind_struct;
#endif

//typedef ps_data_req_struct tcm_ratdm_data_req_struct;
//typedef ps_data_ind_struct tcm_ratdm_data_ind_struct;

#endif /* TCM_RATDM_STRUCT_H */
