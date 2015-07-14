/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2010
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
 *    dcl_pfc.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   Header file of DCL (Driver Common Layer) for PFC.
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

#ifdef DCL_DEFINITION_STRUCT
#ifndef __DCL_PFC_H_STRUCT__
#define __DCL_PFC_H_STRUCT__

/*******************************************************************************
 * DCL_OPTIONS for PFC
 *******************************************************************************/
#define PFC_OPTIONS

/*******************************************************************************
 * DCL_CONFIGURE_T for PFC
 *******************************************************************************/
#define PFC_CONFIGS

/*******************************************************************************
 * DCL_EVENT for PFC
 *******************************************************************************/
#define PFC_EVENTS

/*******************************************************************************
 * DCL_CTRL_CMD for PFC
 *******************************************************************************/
#ifdef __BUILD_DOM__
/* The PFC Command Values in DCL_CTRL_CMD_T Enum of dcl.h */
typedef enum {
    PFC_CMD_RESET, /* To Reset PFC */
    PFC_CMD_ENCODE, /* To Encode PPP Framer */
    PFC_CMD_DECODE, /* To Decode PPP Framer */

} DCL_CTRL_CMD_T;
#else /* __BUILD_DOM__ */
#define PFC_CMDS \
    PFC_CMD_RESET, \
    PFC_CMD_ENCODE, \
    PFC_CMD_DECODE,
#endif /* __BUILD_DOM__ */    

/*******************************************************************************
 * DCL_CTRL_DATA_T: Define the Control data structure for each module's command
 *******************************************************************************/
 
/* For PFC_CMD_RESET command. */
typedef struct 
{
    DCL_UINT32 ContextID; /* Input : Context ID of PPP */ 
} PFC_CTRL_RESET_T;

/* Enum for PFC Buffer Type. */
typedef enum 
{
    PFC_NULL_BUF, /* Null Buffer */
    PFC_CTRL_BUF, /* Control Buffer */
    PFC_FLC_BUF, /* FLC Buffer */
    PFC_TEMP_DECODE_DST_BUFF, /* __PPP_DROP_PACKETS_WHEN_2G_PS_SUSPEND__ */    
    PFC_INVALID_TYPE = 0x0fffffff /* Forces to be a 32-bit */    
} pfc_buff_type_enum;

/* Data Structure of AHDLC State. */
typedef struct 
{
    DCL_UINT32 raccm; /* raccm */
    DCL_UINT32 xaccm; /* xaccm */

    DCL_UINT16 rfcs; /* rfcs */
    DCL_UINT16 xfcs; /* xfcs */

    DCL_UINT16 mru; /* Maximum Receive Unit */
    DCL_UINT16 mtu; /* Maximum Transmission Unit */

    DCL_BOOLEAN  is_acfc_tx; /* Whether is ACFC Tx */
    DCL_BOOLEAN  is_pfc_tx; /* Whether is PFC TX */
    DCL_BOOLEAN  is_acfc_rx; /* Whether is ACFC RX */
    DCL_BOOLEAN  is_pfc_rx; /* Whether is PFC RX */
   
    DCL_UINT8  rflags; /* rflags */
    DCL_UINT8  xflags; /* xflags */
    DCL_UINT8  context_id; /* Context ID */
    DCL_UINT16 __align_00; /* Align 00 */
} pfc_ahdlc_state_struct;

/* Enum for PPPE Error Cause. */
typedef enum
{
    PFC_PPPE_NONE, /* None */
    PFC_PPPE_LCP_FAIL, /* LCP FAIL */
    PFC_PPPE_AUTH_FAIL, /* Authentication Fail */
    PFC_PPPE_IPCP_FAIL, /* Internet Protocol Control Protocol Fail */
    PFC_PPPE_ESC_DETECT, /* Escape Detected */
    PFC_PPPE_PLUGOUT_DETECT, /* Plug Out Detected */
    PFC_PPPE_PPP_GPRS_DIALUP_ALREADY_ACTIVATED, /* PPP GPRS Dial-up Already Activated */
    PFC_PPPE_PPP_NOT_ACTIVATED_BY_EXT_MODEM_YET, /* PPP Not Activated by External Modem Yet */ 
    PFC_PPPE_PPP_ALREADY_ACTIVATED_BY_EXT_MODEM, /* PPP Already Activated by External Modem */
    PFC_PPPE_PPP_NOT_ACTIVATED_BY_WAP_OVER_CSD_YET, /* PPP Not Activated by WAP Over CSD Yet */ 
    PFC_PPPE_PPP_ALREADY_ACTIVATED_BY_WAP_OVER_CSD, /* PPP Already Activated by WAP Over CSD */ 
    PFC_PPPE_PPP_WRONG_CSD_MOD_ID, /* Wrong CSD Module ID */
    PFC_PPPE_PPP_DETECT_AT_CMD_DURING_DIALUP, /* AT Command Detected During Dial-up */
    PFC_PPPE_PPP_DETECT_ESCAPE_DURING_DIALUP, /* Escape Detected During Dial-up */
    PFC_PPPE_PPP_IN_GEMINI_DIALUP_ACTIVATED_BY_ANOTHER_L4C, /* Dial-up Actived By Another L4C in Gemini */
    PFC_PPPE_PPP_DIALUP_ABORTED_BY_L4C_AT_CGACT_0, /* Dial-up Aborted By L4C At CGACT 0 */
    PFC_PPPE_PPP_DIALUP_WITH_UNSUPPORTED_PDP_TYPE, /* Dial-up With Unsupported PDP Type */
    PFC_PPPE_PPP_PDP_CONTEXT_INCORRECT, /* PDP Context Incorrect */
    PFC_PPPE_PPP_ERROR_CAUSE_ENUM_SIZE /* Error Cause Enum Size */
} pfc_error_cause_enum;

/* Data Structure of PFC Buffer Header */
typedef struct 
{    
    DCL_BOOLEAN ip_pkt_four_byte_align_required; /* IP Packet 4 Byte Align Required */
    DCL_BOOLEAN ip_pkt_four_byte_align_already_done; /* IP Packet 4 Byte Align Already Done */
    DCL_UINT16 protocol; /* Protocol Type */
    
    DCL_UINT16 size; /* Size */
    DCL_UINT16 used; /* Used Size */
    
    DCL_UINT8 *data_ptr; /* Data Pointer */
    DCL_UINT8 *cur_ptr; /* Current Porinter */
    DCL_UINT8 *end_ptr; /* End Pointer */

    pfc_buff_type_enum pkt_type; /* Packet Type */
    
} pfc_buff_head_struct;

/* For PFC_CMD_ENCODE command. */
typedef struct
{
    pfc_buff_head_struct * dest; /* Input : Destination */
    pfc_buff_head_struct * src; /* Input : Source */
    pfc_ahdlc_state_struct * state; /* Input : AHDLC State */
    DCL_BOOLEAN fgEncodeResult; /* Output : Encode Result */
}PFC_CTRL_ENCODE_T;

/* For PFC_CMD_DECODE command. */
typedef struct
{
    pfc_buff_head_struct * dest; /* Input : Destination */
    pfc_buff_head_struct * src; /* Input : Source */
    pfc_ahdlc_state_struct * state; /* Input : AHDLC State */
    pfc_error_cause_enum * rcv_AT_CMD_OR_ESCAPE; /* Input : Receive AT Commadn Or Escape */
    DCL_BOOLEAN fgDecodeResult; /* Output : Encode Result */   
}PFC_CTRL_DECODE_T;

#ifdef __BUILD_DOM__
/* The PFC Command Parameter Data Structure for Each Command in DCL_CTRL_DATA_T Enum of dcl.h */
typedef struct
{
    PFC_CTRL_RESET_T rPfcCtrlReset; /* Data Structure for PFC_CMD_RESET */
    PFC_CTRL_ENCODE_T rPfcCtrlEncode; /* Data Structure for PFC_CMD_ENCODE */
    PFC_CTRL_DECODE_T rPfcCtrlDecode; /* Data Structure for PFC_CMD_DECODE */
}DCL_CTRL_DATA_T;
#else /* __BUILD_DOM__ */
#define PFC_CTRLS \
   PFC_CTRL_RESET_T rPfcCtrlReset; \
   PFC_CTRL_ENCODE_T rPfcCtrlEncode; \
   PFC_CTRL_DECODE_T rPfcCtrlDecode;
#endif /* __BUILD_DOM__ */

#endif // #ifndef __DCL_PFC_H_STRUCT__
#endif // #ifdef DCL_DEFINITION_STRUCT   


#ifdef DCL_DEFINITION_PROTOTYPE
#ifndef __DCL_PFC_H_PROTOTYPE__
#define __DCL_PFC_H_PROTOTYPE__


/*************************************************************************
* FUNCTION
*  DclPFC_Initialize
*
* DESCRIPTION
*  This function is to initialize PFC module
*
* PARAMETERS
*  None
*
* RETURNS
*  Return the status of DclPFC_Initialize
*
* RETURN VALUES
*  STATUS_OK: Initialize Finished
*
*************************************************************************/
//extern DCL_STATUS DclPFC_Initialize(void);
/*************************************************************************
* FUNCTION
*  DclPFC_Open
*
* DESCRIPTION
*  This function is to open the PFC module and return a handle
*
* PARAMETERS
*  dev: [IN] Only valid for DCL_PFC
*  flags: [IN] No sepcial flags is needed. Please use FLAGS_NONE
*
* RETURNS
*  Return DCL_HANDLE of PFC
*
* RETURN VALUES
*  DCL_HANDLE_INVALID : Open failed
*  Other value : A valid handle
*
*************************************************************************/
extern DCL_HANDLE DclPFC_Open(DCL_DEV dev, DCL_FLAGS flags);
/*************************************************************************
* FUNCTION
*  DclPFC_ReadData
*
* DESCRIPTION
*  This function is not supported for the PFC module now.
*
* PARAMETERS
*	N/A
*
* RETURNS
*	STATUS_UNSUPPORTED
*
*************************************************************************/
extern DCL_STATUS DclPFC_ReadData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN *buf_len, DCL_OPTIONS options);
/*************************************************************************
* FUNCTION
*  DclPFC_WriteData
*
* DESCRIPTION
*  This function is not supported for the PFC module now.
*
* PARAMETERS
*	N/A
*
* RETURNS
*	STATUS_UNSUPPORTED
*
*************************************************************************/
extern DCL_STATUS DclPFC_WriteData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN *buf_len, DCL_OPTIONS options);
/*************************************************************************
* FUNCTION
*  DclPFC_Configure
*
* DESCRIPTION
*  This function is not supported for the PFC module now.
*
* PARAMETERS
*	N/A
*
* RETURNS
*	STATUS_UNSUPPORTED
*
*************************************************************************/
extern DCL_STATUS DclPFC_Configure(DCL_HANDLE handle, DCL_CONFIGURE_T *configure);
/*************************************************************************
* FUNCTION
*  DclPFC_RegisterCallback
*
* DESCRIPTION
*  This function is to set callback function for the PFC module.
*
* PARAMETERS
*  handle: the returned handle value of DclPFC_Open
*  event: Supported events:
*  callback: the callback function for registered events
*
* RETURNS
*  STATUS_OK: Successfully register the callback function.
*  STATUS_INVALID_DCL_HANDLE: It's a invalid handle.
*  STATUS_NOT_OPENED: The module has not been opened.
*  STATUS_INVALID_EVENT: The event parameter is invalid.
*
*************************************************************************/
extern DCL_STATUS DclPFC_RegisterCallback(DCL_HANDLE handle, DCL_EVENT event, PFN_DCL_CALLBACK callback);
/*************************************************************************
* FUNCTION
*  DclPFC_Control
*
* DESCRIPTION
*  This function is to send command to control the PFC module.
*
* PARAMETERS
*  handle: [IN] The handle value returned from DclPFC_Open
*  cmd: [IN] A control command for PFC module
*          1. PFC_CMD_RESET: to reset PFC Module
*          2. PFC_CMD_ENCODE: to Encode
*          3. PFC_CMD_DECODE: to Decode
*
*  data: [IN] The data of the control command
*          1. PFC_CMD_RESET: pointer to a PFC_CTRL_RESET_T structure
*          2. PFC_CMD_ENCODE: pointer to a PFC_CTRL_ENCODE_T structure
*          3. PFC_CMD_DECODE: pointer to a PFC_CTRL_DECODE_T structure
*
* RETURNS
*  Return the status of DclPFC_Control
*
* RETURN VALUES
*  STATUS_OK: Command is executed successfully.
*  STATUS_FAIL: Command is failed.
*  STATUS_INVALID_CMD: It's a invalid command.
*
*************************************************************************/
extern DCL_STATUS DclPFC_Control(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data);
/*************************************************************************
* FUNCTION
*  DclPFC_Close
*
* DESCRIPTION
*  This function is to close the PFC module.
*
* PARAMETERS
*  handle: [IN] The returned handle value of DclPFC_Open
*
* RETURNS
*  Return the status of DclPFC_Close
*
* RETURN VALUES
*  STATUS_OK
*
*************************************************************************/
extern DCL_STATUS DclPFC_Close(DCL_HANDLE handle);

// MoDIS parser skip end

#endif // #ifndef __DCL_PFC_H_PROTOTYPE__
#endif // #ifdef DCL_DEFINITION_PROTOTYPE
