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
 *  Copyright Statement:
 *  --------------------
 *  This software is protected by Copyright and the information contained
 *  herein is confidential. The software may not be copied and the information
 *  contained herein may not be used or disclosed except with the written
 *  permission of MediaTek Inc. (C) 2001
 *
 *******************************************************************************/

 /*******************************************************************************
 * Filename:
 * ---------
 *   em_sap.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Engineer mode related message identity definition
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
#include "module_msg_range.h"

#ifndef EM_MSGID_H
#define EM_MSGID_H
 
MODULE_MSG_BEGIN( MSG_ID_EM_CODE_BEGIN )
 	/* Engineer mode message begin */
 	/* Send to PS */ 	
	MSG_ID_L4CPS_EM_UPDATE_REQ = MSG_ID_EM_CODE_BEGIN,
	
	/*Byron: 2006/02/15: Suspend or resume the cell reselection*/
	MSG_ID_L4CPS_EM_CELL_RESEL_SUSPEND_REQ,  /* Suspend cell reselection */
	MSG_ID_L4CPS_EM_CELL_RESEL_SUSPEND_CNF,  /* Suspend cell reselection */

	MSG_ID_L4CPS_EM_CELL_RESEL_RESUME_REQ,    /* Resume cell reselection */
	MSG_ID_L4CPS_EM_CELL_RESEL_RESUME_CNF,    /* Resume cell reselection */
	
       /*Byron: 2006/08/06: Add for cell lock functionality from MMI EM*/
	MSG_ID_L4CPS_EM_SET_CELL_LOCK_REQ,
       MSG_ID_L4CPS_EM_SET_CELL_LOCK_CNF,
       
	MSG_ID_L4CPS_EM_GET_CELL_LOCK_REQ,
       MSG_ID_L4CPS_EM_GET_CELL_LOCK_CNF,

	/*Byron: 2007/03/14: Add for Pure Command request*/
	MSG_ID_L4CPS_EM_FEATURE_COMMAND_REQ,
	MSG_ID_L4CPS_EM_FEATURE_COMMAND_CNF,

/* brwang, 20070727, [EM Cell ID Lock function] { */    

   /* Send to PS */ 	
   MSG_ID_L4CPS_EM_SET_CELL_ID_LOCK_REQ,
   /* Received from PS */ 	
   MSG_ID_L4CPS_EM_SET_CELL_ID_LOCK_CNF,

/* brwang, 20070727, [EM Cell ID Lock function]  } */    

	/* Received from TST */
	MSG_ID_TSTL4C_EM_UPDATE_REQ,

	/*mtk00924: 061106 add for network event notify*/
	MSG_ID_L4CPS_EM_NW_EVENT_NOTIFY_REQ,
	MSG_ID_L4CPS_EM_NW_EVENT_NOTIFY_CNF,
	MSG_ID_L4CPS_EM_NW_EVENT_NOTIFY_IND,		
	
	/* Received from PS */ 	
        MSG_ID_L4CPS_EM_UPDATE_CNF,
	MSG_ID_L4CPS_EM_STATUS_IND,
      #if ((defined(__SM_UT__)) && (!defined(__MTK_TARGET__)))		
      MSG_ID_L4CPS_CHECK_SM_EM_STATUS_CONTENT, // used for check parameter correctness in SM UT
      #endif // ~ #if ((defined(__SM_UT__)) && (!defined(__MTK_TARGET__)))	
      #if ((!defined(__MTK_TARGET__)) && defined(__TCM_UT__))
      MSG_ID_L4CPS_CHECK_TCM_MMI_EM_INFO, // used for check parameter correctness in TCM UT
      #endif // ~ ((!defined(__MTK_TARGET__)) && defined(__TCM_UT__))
	
    /* VT Engineer Mode */
    MSG_ID_L4C_VT_EM_GET_CONFIG_REQ,
    MSG_ID_L4C_VT_EM_GET_CONFIG_CNF,
    MSG_ID_L4C_VT_EM_SET_CONFIG_REQ,

    /* EM request: GSM RF test */
    MSG_ID_L4CL1_EM_RF_TEST_GSM_STOP_REQ,
    MSG_ID_L4CL1_EM_RF_TEST_GSM_TX_TEST_REQ,
    MSG_ID_L4CL1_EM_RF_TEST_GSM_RX_TEST_REQ,
    MSG_ID_L4CL1_EM_RF_TEST_GSM_POWER_SCAN_REQ,
    MSG_ID_L4CL1_EM_RF_TEST_GSM_POWER_SCAN_CNF,

    MSG_ID_L1_GSM_MAX_TX_PWR_RED_REQ,
    MSG_ID_UL1_UMTS_MAX_TX_PWR_RED_REQ,

    MSG_ID_L4CL1_GET_RF_TEMPERATURE_REQ,
    MSG_ID_L4CL1_GET_RF_TEMPERATURE_CNF,
    
    MSG_ID_L4CUL1_GET_RF_TEMPERATURE_REQ,
    MSG_ID_L4CUL1_GET_RF_TEMPERATURE_CNF,

    MSG_ID_EM_CODE_END = MSG_ID_L4CUL1_GET_RF_TEMPERATURE_CNF,
	/* Engineer mode message end */
MODULE_MSG_END( MSG_ID_EM_CODE_TAIL )

#endif  //EM_MSGID_H
