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
 * L3_INC_STRUCT.H
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file describes the common enums of L3.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
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
 *============================================================================
 ****************************************************************************/

/********************************************************************************
*  Copyright Statement:
*  --------------------
*
*  This product has been developed using a protocol stack
*  developed by Sasken Communication Technologies Limited.
*
********************************************************************************/

#ifndef _L3_INC_LOCAL_H
#define _L3_INC_LOCAL_H

#include "kal_general_types.h"
//#include "kal_non_specific_general_types.h"
#include "l3_inc_enums.h"
#include "mcd_l3_inc_struct.h"
#include "ps_public_struct.h"

/*****************************************************************************
 * Constant Definitions
 *****************************************************************************/
#define RAC_MAX_NUM_LISTED_PLMNS 32

/*****************************************************************************
 * Type Definitions
 *****************************************************************************/

#if (defined(__IPV4V6__) || defined (__IPV6__))
#define PACKET_FILTER_CONTENT_LEN   53  /* Poying: 29+(32-8) */
#else  /* (defined(__IPV4V6__) || defined (__IPV6__)) */
#define PACKET_FILTER_CONTENT_LEN   29
#endif /* (defined(__IPV4V6__) || defined (__IPV6__)) */

typedef struct {
    kal_uint8 pfi;
    kal_uint8 epi;
    kal_uint8 contents_len; /* in bytes*/
    kal_uint8 contents[PACKET_FILTER_CONTENT_LEN];
} packet_filter_struct;

typedef struct {
    kal_uint8 tft_op_code;
    kal_uint8 spare;
    kal_uint8 num_packet_filters;
    packet_filter_struct packet_list[8];
} tft_struct;

typedef struct {
    kal_uint16      req_n201u; //erica 20070112
} pdp_auxinfo_struct;


typedef struct {
    kal_uint8 length; /* LENGTH*/
    kal_uint8 digit0; /* DIGIT 0*/
    kal_uint8 odd_or_even; /* ODD OR EVEN*/
    kal_uint8 identity_type; /* IDENTITY TYPE*/
    kal_uint8 digit_byte[7];
} imsi_struct;

typedef struct {
    kal_uint16 bcch_list[8];
} bcchs_struct;


typedef struct {
    kal_uint8 length;
    kal_uint8 digit0;
    kal_uint8 odd_or_even;
    kal_uint8 identity_type;
    kal_uint8 digit_byte[7];
} imei_struct;

typedef struct {
    plmn_id_struct plmn_id;
    kal_uint8 la_code[2];
    kal_uint8 ra_code;  /* RA CODE*/
    kal_uint32 cell_id; /* CELL ID*/
#ifdef __CSG_SUPPORT__
    kal_bool is_csg_cell;
    csg_info_struct csg_info;    
#endif
} cell_info_struct;

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
#ifdef __CSG_SUPPORT__
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
#endif
/*MAUI_02729678:In LU abnormal case, it need to remember cell inforamtion and current rat.
  And in some related function, one input parameter type is cell_info_struct.
  So it is not flexible to handle if we store abnormal cell information and rat 
  in a variable which is cell_info_rat_struct type.
  So, add this new type.
*/
typedef struct {
    cell_info_struct cell_info;
    rat_enum rat;  /* rat_enum */
} cell_info_and_rat_struct;


typedef struct {
    kal_uint8          plmn_count;
    plmn_id_rat_struct plmn_id_rat[RAC_MAX_NUM_LISTED_PLMNS];
    kal_uint8          la_code[RAC_MAX_NUM_LISTED_PLMNS][2];
    mm_plmn_list_status_enum    status[RAC_MAX_NUM_LISTED_PLMNS];	
} rac_plmn_list_struct;

typedef enum
{
    MS_NULL_STATE = 0,
    MS_READY_STATE,
    MS_STANDBY_STATE,
    MS_FORCED_TO_STANDBY_STATE
}gmm_ms_state_enum;

/* UAS/GAS <-> RATCM begin */
typedef struct {
    plmn_id_struct   plmn_id;
    kal_uint8        la_code[2];
    kal_int8         power_level;
    kal_bool         may_suitable_cell_exist;   
                     //TRUE(1) for suitable cell may exist;
                     //FALSE(0) for no suitable cell exist.
} available_plmn_struct;

typedef struct {
    kal_uint8        plmn_count;
    kal_uint8        high_quality_plmn_count;
    available_plmn_struct available_plmn[MAX_NUM_PLMN_PER_RAT];
} as_plmn_list_struct;

typedef struct {
    plmn_id_rat_struct plmn_id_rat;
    kal_uint8 csg_count;
    csg_info_struct *csg_info_list;
} available_plmn_csg_struct;

typedef struct {
    kal_uint8 plmn_count;
    available_plmn_csg_struct available_plmn_csg[MAX_NUM_PLMN_PER_RAT];
} as_csg_list_struct;

typedef struct
{
    kal_uint8 plmn_count;
    available_plmn_csg_struct available_plmn_csg[MAX_NUM_PLMN_PER_RAT];
    //available_plmn_csg_struct available_plmn_csg[MAX_NUM_PLMN_PER_RAT*2];
} rac_csg_list_struct;

/* UAS/GAS <-> RATCM end */

typedef struct {
    domain_id_enum pag_resp_rest_ind;
    domain_id_enum loc_reg_rest_ind;   
    kal_uint16 loc_reg_ppacr;
} ppacr_info_struct ;

#endif 


