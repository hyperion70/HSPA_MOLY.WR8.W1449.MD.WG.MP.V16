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
 *    usbacm_adap.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file implements usb adaption layer for UART API
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
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
 *============================================================================
 ****************************************************************************/
 
 #ifdef __USB_COM_PORT_ENABLE__
 
#include "intrCtrl.h"
//#include "kal_release.h"
//#include "stack_common.h"
#include "kal_public_defs.h" //MSBB change #include "stack_msgs.h"
#include "kal_public_api.h" //#include "stack_ltlcom.h" //MSBB change #include "app_ltlcom.h"
//#include "app_buff_alloc.h"
#include "drv_comm.h"
//#include "gpt_sw.h"
#include "dcl.h"
//#include "uart_sw.h"
#include "cache_sw.h"
//#include "mmu.h"
#include "drvsignals.h"

#include "usb_comm.h"
#include "usb_mode.h"

//#include "usb_drv.h"
#include "usb_trc.h"
#include "usb_adap.h"
#include "usb.h"
#include "usbacm_drv.h"
#include "usbacm_ft.h"
#include "usbacm_adap.h"
#include "usb_custom.h"
#include "usb_custom_def.h"

#include "usb_debug_tool.h"
//#include "otg.h"
#include "usb_mode.h"

#include "drv_features.h"
//#include "kal_non_specific_general_types.h"
#include "kal_trace.h"
#include "kal_public_defs.h" //MSBB change #include "stack_config.h"
#include "kal_public_api.h" //#include "stack_ltlcom.h"
#include "bmd.h"
//#include "mmu_arm11.h"
#include "mmu.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "nvram_data_items.h"
#include "nvram_interface.h"

#include "drv_msgid.h"

/* Exception flag */
extern kal_uint8 INT_Exception_Enter;
#if defined(__USB_BOOTUP_TRACE__)
extern kal_bool is_init_log_enable;
extern kal_bool is_init_stage;
#endif

/* static functions*/
static kal_bool USB2UART_open(UART_PORT port, module_type ownerid);
static void USB2UART_close(UART_PORT port, module_type ownerid);
static void USB2UART_ClrRxBuffer(UART_PORT port, module_type ownerid);
static kal_uint16 USB2UART_GetRxAvail(UART_PORT port);
static kal_uint16 USB2UART_GetBufAvail(BUFFER_INFO *buf_info);
static kal_uint16 USB2UART_GetBytes(UART_PORT port, kal_uint8 *buffaddr, kal_uint16 length,kal_uint8 *status, module_type ownerid);
static void USB2UART_ClrTxBuffer(UART_PORT port, module_type ownerid);
static kal_uint16 USB2UART_GetTxRoomLeft(UART_PORT port);
static kal_uint16 USB2UART_PutBytes(UART_PORT port, kal_uint8 *buffaddr, kal_uint16 length, module_type ownerid);
//static kal_uint16 USB2UART_SendData(UART_PORT port, kal_uint8 *buffaddr, kal_uint16 length,kal_uint8 mode,kal_uint8 escape_char , module_type ownerid);
static kal_uint16 USB2UART_GetTxISRRoomLeft(UART_PORT port);
//static kal_uint16 USB2UART_PutISRBytes(UART_PORT port, kal_uint8 *buffaddr, kal_uint16 length, module_type ownerid);
//static kal_uint16 USB2UART_SendISRData(UART_PORT port, kal_uint8 *buffaddr, kal_uint16 length,kal_uint8 mode,kal_uint8 escape_char, module_type ownerid);
//static kal_uint16 USB2UART_Send_ISRData(UART_PORT port, kal_uint8 *buffaddr, kal_uint16 length,kal_uint8 mode, kal_uint8 escape_char, module_type ownerid);
static kal_uint16 USB2UART_Send_ISRData(UART_PORT port, kal_uint8 *buffaddr, kal_uint16 length, module_type ownerid);
static void USB2UART_setowner(UART_PORT port, module_type ownerid);
static module_type USB2UART_GetOwnerID(UART_PORT port);
static void USB2UART_ConfigEscape(UART_PORT port, kal_uint8 EscChar, kal_uint16 ESCGuardtime, module_type ownerid);
static void USB2UART_SetDCBConfig(UART_PORT port, UARTDCBStruct *UART_Config, module_type ownerid);
//static void USB2UART_Purge(UART_PORT port, UART_BUFFER_T dir, module_type ownerid);
//static void USB2UART_SetFlowCtrl(UART_PORT port, kal_bool XON, module_type ownerid);
static void USB2UART_CtrlDCD(UART_PORT port, IO_LEVEL_T SDCD, module_type ownerid);
//static void USB2UART_CtrlBreak(UART_PORT port, IO_LEVEL_T SBREAK, module_type ownerid);
//static void USB2UART_SetBaudRate(UART_PORT port, UART_baudrate baudrate, module_type ownerid);
//static void USB2UART_SetAutoBaud_Div(UART_PORT port, module_type ownerid);
static void USB2UART_Register_TX_Callback(UART_PORT port, module_type ownerid, UART_TX_FUNC func);
static void USB2UART_Register_RX_Callback(UART_PORT port, module_type ownerid, UART_RX_FUNC func);
static kal_uint8 USB2UART_GetUARTByte(UART_PORT port);
//static void USB2UART_PutUARTByte(UART_PORT port, kal_uint8 data);
static void USB2UART_Put_Exp_Data(UART_PORT port, kal_uint8 *Buffaddr, kal_uint16 Length);
static void USB2UART_ReadDCBConfig(UART_PORT port, UARTDCBStruct *DCB);
//static void USB2UART_CtrlRI (UART_PORT port, IO_LEVEL_T SRI, module_type ownerid);
//static void USB2UART_CtrlDTR (UART_PORT port, IO_LEVEL_T SDTR, module_type ownerid);
static void USB2UART_ReadHWStatus(UART_PORT port, IO_LEVEL_T *SDSR, IO_LEVEL_T *SCTS);



#if defined(__USB_TETHERING__)||defined(__MBIM_SUPPORT__)||defined(__ECM_SUPPORT__)
static kal_uint16 USB_CTRLPutBytes(UART_PORT port, kal_uint8 *buffaddr, kal_uint16 length, module_type ownerid);
static kal_uint16 USB_CTRLGetFrame(UART_PORT port, kal_uint8 **buffaddr, module_type ownerid, USB_Requ_type type);
static void USB_RNDIS_HaltBus(UART_PORT port,module_type ownerid);
#endif



#ifdef  __USB_HIGH_SPEED_COM_PORT_ENABLE__
static kal_bool USB_EnableHighSpeedPort(UART_PORT port, kal_bool enable, module_type ownerid,USB_Transfer_type transfer_type);
static kal_uint16 USB_HighSpeed_PutBytes(UART_PORT port, kal_uint8 *buffaddr, kal_uint16 length, module_type ownerid,kal_bool send_ready_to_write);
static void USB_Register_HighSpeed_TX_Callback(UART_PORT port, module_type ownerid, usb_dma_callback func);
static kal_bool USB_QueryHSTxDataLeft(UART_PORT usb_port);
static void USB_High_Speed_En_Check (kal_uint32 usb_port);
static void USB_HighSpeedPushBuff(UART_PORT port, module_type ownerid);
static kal_uint16 USB_Send_Data(UART_PORT port, kal_uint8 *buffaddr, kal_uint16 length, module_type ownerid);//,USB_Transfer_type transfer_type);
static kal_uint16 USB_Receive_Data(UART_PORT port, kal_uint8 **buffaddr, module_type ownerid, kal_uint16 length,kal_uint8 *status,USB_Requ_type type);//,USB_Transfer_type transfer_type);
static kal_uint16 USB_Send_ISR_Data(UART_PORT port, kal_uint8 *buffaddr, kal_uint16 length, module_type ownerid,kal_uint8 mode, kal_uint8 escape_char);//,USB_Transfer_type transfer_type);
#endif

#ifdef  DRV_USB_HW_TX_DIRECT_PATH_SUPPORT
static kal_bool USB_Enable_TX_Direct_Path(UART_PORT port, kal_bool enable, module_type ownerid);
#endif

#ifdef __ECM_SUPPORT__
static kal_bool USB2UART_ECM_Notification(UART_PORT port,module_type ownerid,USB_ECM_type type,void *buffer);	
#endif

extern void USB2UART_Tx_DMA_Callback(UART_PORT port);
extern void USB2UART_Send_Intr_Pending(kal_uint32 usb_port);
extern kal_uint16 USB2UART_GetBuffRoomLeft(BUFFER_INFO *buf_info);
//extern void nvram_get_ps(kal_uint8 *port, kal_uint32 *baudrate);
extern kal_uint32 USB_EP_Bulk_HW_TxPktRdy_Addr(void);
extern void USB_EP_Bulk_HW_Set_TxPktRdy(kal_uint32 ep_num);
extern kal_uint32 USB_EP_Bulk_HW_FIFO_Addr(kal_uint32 ep_num);

#ifdef  __USB_HIGH_SPEED_COM_PORT_ENABLE__
extern usb_dma_callback usb_hs_tx_reg_cb;
#if defined(__USB_MULTIPLE_COMPORT_SUPPORT__)
  extern usb_dma_callback usb2_hs_tx_reg_cb;
#endif
#if defined (__USB_MODEM_CARD_SUPPORT__)
  extern usb_dma_callback usb3_hs_tx_reg_cb;
  extern usb_dma_callback usb4_hs_tx_reg_cb;
  extern usb_dma_callback usb5_hs_tx_reg_cb;
#endif
#endif

#if defined(DRV_USB_DMA_QUEUE_SUPPORT)
usb_dma_callback  USB_COM_DMAQ_Callback(UART_PORT port);
extern TGPD USB_DMAQ_PPP_TX_GPD[2];
extern TGPD USB_DMAQ_PPP_RX_GPD[2];

#if defined(__MBIM_SUPPORT__)||defined(__ECM_SUPPORT__)
#ifdef __MTK_TARGET__
__attribute__ ((section ("NONCACHEDZI"), aligned(4))) 
#endif /* __MTK_TARGET__ */
TGPD *USB_DMAQ_TX_GPD_HEADER;

#ifdef __MTK_TARGET__
__attribute__ ((section ("NONCACHEDZI"), aligned(4))) 
#endif /* __MTK_TARGET__ */
TGPD *USB_DMAQ_TX_GPD_QUEUED;

#ifdef __MTK_TARGET__
__attribute__ ((section ("NONCACHEDZI"), aligned(4))) 
#endif /* __MTK_TARGET__ */
TGPD *USB_DMAQ_RX_GPD_HEADER;

#ifdef __MTK_TARGET__
__attribute__ ((section ("NONCACHEDZI"), aligned(4))) 
#endif /* __MTK_TARGET__ */
TGPD USB_DMAQ_RX_GPD_NULL;

#ifdef __MTK_TARGET__
__attribute__ ((section ("NONCACHEDZI"), aligned(4))) 
#endif /* __MTK_TARGET__ */
TGPD USB_DMAQ_TX_GPD_NULL;
#endif

#endif


#if defined(__USB_LIMIT__)
static void USB_DMA_Free(UART_PORT port, module_type ownerid);
static void USB_DMA_Limit(UART_PORT port, module_type ownerid, kal_uint32 dma_limit_num);
#endif


void USB2UART_init(void);


static DCL_STATUS USB2UartDriver(DCL_DEV dev,DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data);
const Seriport_HANDLER_T  USB2Uart_Drv_Handler = {DCL_UART_USB_TYPE, USB2UartDriver};

DCL_STATUS USB2UartDriver(DCL_DEV dev,DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data)
{
	DCL_STATUS return_flag = KAL_FALSE;
	DCL_STATUS return_status = STATUS_OK;
	
	switch (cmd)
	{
		case SIO_CMD_INIT:
			USB2UART_init();
			break;
		
		case SIO_CMD_OPEN:
			{
				UART_CTRL_OPEN_T* prCtrlOpen;
				prCtrlOpen = &(data->rUARTCtrlOPEN);
				return_flag = USB2UART_open(dev, (module_type)prCtrlOpen->u4OwenrId);
				if(return_flag == KAL_FALSE)
					return_status = STATUS_FAIL;
			}
			break;
		
		case SIO_CMD_CLOSE:
			{
				UART_CTRL_CLOSE_T* prCtrlClose;
				prCtrlClose = &(data->rUARTCtrlCLOSE);
				USB2UART_close(dev, (module_type)prCtrlClose->u4OwenrId);
			}
			break;
		
		case SIO_CMD_GET_BYTES:
			{
				UART_CTRL_GET_BYTES_T* prCtrlGetBytes;
				prCtrlGetBytes = &(data->rUARTCtrlGETBYTES);
				prCtrlGetBytes->u2RetSize=USB2UART_GetBytes(dev, prCtrlGetBytes->puBuffaddr, prCtrlGetBytes->u2Length, prCtrlGetBytes->pustatus, (module_type)prCtrlGetBytes->u4OwenrId);
			}
			break;
		
		case SIO_CMD_PUT_BYTES:
			{
				UART_CTRL_PUT_BYTES_T* prCtrlPutBytes;
				prCtrlPutBytes = &(data->rUARTCtrlPUTBYTES);
				prCtrlPutBytes->u2RetSize=	USB2UART_PutBytes(dev, prCtrlPutBytes->puBuffaddr, prCtrlPutBytes->u2Length, (module_type)prCtrlPutBytes->u4OwenrId);
			}
			break;
		
		case SIO_CMD_GET_RX_AVAIL:
			{
				UART_CTRL_RX_AVAIL_T* prCtrlRXAvail;
				prCtrlRXAvail = &(data->rUARTCtrlRXAVAIL);
				prCtrlRXAvail->u2RetSize = USB2UART_GetRxAvail(dev);
			}
		break;
		
		case SIO_CMD_GET_TX_AVAIL:
			{
				UART_CTRL_TX_AVAIL_T* prCtrlTXAvail;
				prCtrlTXAvail = &(data->rUARTCtrlTXAVAIL);
				prCtrlTXAvail->u2RetSize = USB2UART_GetTxRoomLeft(dev);
			}
			break;
		
		case SIO_CMD_PUT_ISR_BYTES:
			{
				UART_CTRL_PUT_BYTES_T* prCtrlPutBytes;
				prCtrlPutBytes = &(data->rUARTCtrlPUTBYTES);
//				prCtrlPutBytes->u2RetSize = USB2UART_Send_ISRData(dev,prCtrlPutBytes->puBuffaddr,prCtrlPutBytes->u2Length,
//									0,0, (module_type)prCtrlPutBytes->u4OwenrId);
				prCtrlPutBytes->u2RetSize = USB2UART_Send_ISRData(dev,prCtrlPutBytes->puBuffaddr,prCtrlPutBytes->u2Length,
								(module_type)prCtrlPutBytes->u4OwenrId);
			}
			break;

		case SIO_CMD_GET_ISR_TX_AVAIL:
			{
				UART_CTRL_TX_AVAIL_T* prCtrlTXAail;
				prCtrlTXAail = &(data->rUARTCtrlTXAVAIL);
				prCtrlTXAail->u2RetSize = USB2UART_GetTxISRRoomLeft(dev);	
			}
			break;
		
//		case SIO_CMD_PURGE:
//			{
//				UART_CTRL_PURGE_T* prCtrlPurge;
//				prCtrlPurge = &(data->rUARTCtrlPURGE);
//				USB2UART_Purge(dev,prCtrlPurge->dir, (module_type)prCtrlPurge->u4OwenrId);
//			}
//			break;
		
		case SIO_CMD_SET_OWNER:
			{
				 UART_CTRL_OWNER_T* prCtrlOwner;
				 prCtrlOwner = &(data->rUARTCtrlOWNER);
				 USB2UART_setowner(dev, (module_type)prCtrlOwner->u4OwenrId);					 
			}
			break;
		
//		case SIO_CMD_SET_FLOW_CTRL:
//			{
//				UART_CTRL_FLOW_CTRL_T* prCtrlFlowCtrl;
//				prCtrlFlowCtrl = &(data->rUARTCtrlFLOWCTRL);
//				USB2UART_SetFlowCtrl(dev, (kal_bool)prCtrlFlowCtrl->bXON, (module_type)prCtrlFlowCtrl->u4OwenrId);
//			}
//			break;
		
		case SIO_CMD_CONFIG_ESCAPE:
			{
				UART_CTRL_CONFIG_ESP_T* prCtrlConfigEsp;
				prCtrlConfigEsp = &(data->rUARTCtrlCONFIGESP);
				USB2UART_ConfigEscape(dev,prCtrlConfigEsp->uEscChar,prCtrlConfigEsp->u2ESCGuardtime, (module_type)prCtrlConfigEsp->u4OwenrId);					
			}
			break;
		
		case SIO_CMD_GET_ESCAPE_INFO:
			{
				UART_CTRL_CONFIG_ESP_T* prCtrlConfigEsp;
				prCtrlConfigEsp = &(data->rUARTCtrlCONFIGESP);
				prCtrlConfigEsp->u2ESCGuardtime = USB2UARTPort[dev].ESCDet.GuardTime;
				prCtrlConfigEsp->uEscChar = USB2UARTPort[dev].ESCDet.EscChar;					
			}
			break;

		case SIO_CMD_SET_DCB_CONFIG:
			{
				UARTDCBStruct *prDCB;
				UART_CTRL_DCB_T* prCtrlDCB;
				prCtrlDCB = &(data->rUARTCtrlDCB);
				prDCB = (UARTDCBStruct*)(&(prCtrlDCB->rUARTConfig));
				USB2UART_SetDCBConfig(dev, prDCB, (module_type)prCtrlDCB->u4OwenrId);
			}
			break;
		
		case SIO_CMD_CTRL_DCD:
			{
				 UART_CTRL_DCD_T* prCtrlDCD;
				 prCtrlDCD = &(data->rUARTCtrlDCD);
				 USB2UART_CtrlDCD(dev,prCtrlDCD->rIOLevelDCD, (module_type)prCtrlDCD->u4OwenrId);
			}
			break;
		
//		case SIO_CMD_CTRL_BREAK:
//			{
//				UART_CTRL_BREAK_T* prCtrlBreak;
//				prCtrlBreak = &(data->rUARTCtrlBREAK);
//				USB2UART_CtrlBreak(dev,prCtrlBreak->rIOLevelBRK, (module_type)prCtrlBreak->u4OwenrId);
//			}
//			break;
		
		case SIO_CMD_CLR_RX_BUF:
			{
				UART_CTRL_CLR_BUFFER_T* prCtrlClrBuffer;
				prCtrlClrBuffer = &(data->rUARTCtrlCLRBUFFER);
				USB2UART_ClrRxBuffer(dev, (module_type)prCtrlClrBuffer->u4OwenrId);
			}
			break;
		
		case SIO_CMD_CLR_TX_BUF:
			{
				UART_CTRL_CLR_BUFFER_T* prCtrlClrBuffer;
				prCtrlClrBuffer = &(data->rUARTCtrlCLRBUFFER);
				USB2UART_ClrTxBuffer(dev, (module_type)prCtrlClrBuffer->u4OwenrId);
			}
			break;
		
//		case SIO_CMD_SET_BAUDRATE:
//			{
//				UART_CTRL_BAUDRATE_T* prCtrlBaudrate;
//				prCtrlBaudrate = &(data->rUARTCtrlBAUDRATE);
//				USB2UART_SetBaudRate(dev,prCtrlBaudrate->baudrate, (module_type)prCtrlBaudrate->u4OwenrId);
//			}
//			break;

//		case SIO_CMD_SEND_ISR_DATA:
//			{
//				UART_CTRL_SEND_DATA_T* prCtrlSendData;
//				prCtrlSendData = &(data->rUARTCtrlSENDDATA);
//				prCtrlSendData->u2RetSize = USB2UART_Send_ISRData(dev,prCtrlSendData->puBuffaddr,prCtrlSendData->u2Length,
//									prCtrlSendData->umode,prCtrlSendData->uescape_char, (module_type)prCtrlSendData->u4OwenrId);
//			}	
//			break;
		
		case SIO_CMD_SEND_DATA:
			{
				UART_CTRL_SEND_DATA_T* prCtrlSendData;
				prCtrlSendData = &(data->rUARTCtrlSENDDATA);
				prCtrlSendData->u2RetSize = USB2UART_PutBytes(dev,prCtrlSendData->puBuffaddr,prCtrlSendData->u2Length,
									(module_type)prCtrlSendData->u4OwenrId);
			}
			break;
		
		case SIO_CMD_GET_OWNER_ID:
			{
				 UART_CTRL_OWNER_T* prCtrlOwner;
				 prCtrlOwner = &(data->rUARTCtrlOWNER);		 
				 prCtrlOwner->u4OwenrId = USB2UART_GetOwnerID(dev);
			}
			break;
		
//		case SIO_CMD_SET_AUTOBAUD_DIV:
//			{
//				 UART_CTRL_AUTO_BAUDDIV_T* prCtrlAutoBaudDiv;
//				 prCtrlAutoBaudDiv = &(data->rUARTCtrlAUTOBAUDDIV);
//				 USB2UART_SetAutoBaud_Div(dev, (module_type)prCtrlAutoBaudDiv->u4OwenrId);
//			}
//			break;
		
		case SIO_CMD_REG_TX_CB:
			{
				UART_CTRL_REG_TX_CB_T* prCtrlTxCB;
				prCtrlTxCB = &(data->rUARTCtrlREGTXCB);
				USB2UART_Register_TX_Callback(dev, (module_type)prCtrlTxCB->u4OwenrId, (UART_TX_FUNC)prCtrlTxCB->func); 
			}
			break;
		
		case SIO_CMD_REG_RX_CB:
			{
				 UART_CTRL_REG_RX_CB_T * prCtrlRxCb;
				 prCtrlRxCb = &(data->rUARTCtrlREGRXCB);
				 USB2UART_Register_RX_Callback(dev, (module_type)prCtrlRxCb->u4OwenrId, (UART_RX_FUNC)prCtrlRxCb->func); 
			}
			break;


		case SIO_CMD_GET_UART_BYTE:
			{
				 UART_CTRL_GET_UART_BYTE_T* prCtrlGetUartByte;
				 prCtrlGetUartByte = &(data->rUARTCtrlGETUARTBYTE);
				 prCtrlGetUartByte->uByte = USB2UART_GetUARTByte(dev); 
			}
			break;
		
		case SIO_CMD_PUT_UART_BYTE:
			{
				UART_CTRL_PUT_UART_BYTE_T* prCtrlPutUartByte;
				prCtrlPutUartByte = &(data->rUARTCtrlPUTUARTBYTE);
				USB2UART_Put_Exp_Data(dev, &(prCtrlPutUartByte->uData), 1);
			}
			break;
		
		case USB_CMD_BOOT_PUTBYTES:
		case SIO_CMD_PUT_UART_BYTES:
			{			
				 UART_CTRL_PUT_UART_BYTES_T* prCtrlPutUartBytes;
				 prCtrlPutUartBytes = &(data->rUARTCtrlPUTUARTBYTES);
				 USB2UART_Put_Exp_Data(dev,prCtrlPutUartBytes->puBuffaddr,prCtrlPutUartBytes->u2Length); 
			}
			break;
		
		case SIO_CMD_READ_DCB_CONFIG:
			{
				UARTDCBStruct *prDCB;
				UART_CTRL_DCB_T* prCtrlDCB;
				prCtrlDCB = &(data->rUARTCtrlDCB);
				prDCB = (UARTDCBStruct*)(&(prCtrlDCB->rUARTConfig));
				USB2UART_ReadDCBConfig(dev,prDCB); 
			}
			break;
		
//		case SIO_CMD_CTRL_RI:
//			{
//				 UART_CTRL_RI_T* prCtrlRI;
//				 prCtrlRI= &(data->rUARTCtrlRI);
//				 USB2UART_CtrlRI(dev,prCtrlRI->rIOLevelSRI, (module_type)prCtrlRI->u4OwenrId); 
//			}
//			break;
		
//		case SIO_CMD_CTRL_DTR:
//			{
//				UART_CTRL_DTR_T* prCtrlDTR;
//				prCtrlDTR = &(data->rUARTCtrlDTR);
//				USB2UART_CtrlDTR(dev,prCtrlDTR->rIOLevelDTR, (module_type)prCtrlDTR->u4OwenrId); 
//			}
//			break;
		
		case SIO_CMD_READ_HW_STATUS:
			{
				IO_LEVEL_T* pSDSR;
				IO_LEVEL_T* pSCTS;
				UART_CTRL_RHS_T* prCtrlRHS;
				prCtrlRHS = &(data->rUARTCtrlRHS);
				pSDSR = (IO_LEVEL_T*)(&(prCtrlRHS->rIOLevelDSR));
				pSCTS = (IO_LEVEL_T*)(&(prCtrlRHS->rIOLevelCTS));
				USB2UART_ReadHWStatus(dev,pSDSR,pSCTS);  
			}
			break;
			
//		case UART_CMD_GET_FLOW_CONTROL:
//		case UART_CMD_SLEEP_TX_ENABLE:
//			{
//				/* legancy bypass command which is handled by uart handler
//				 * In HAL, USB need to handle it but do nothing.
//				 */
//			}
//			break;
			
		case USB_CMD_IS_CDCACM:
			{
				USB_DRV_CTRL_COM_TYPE_QUERY_T* ptrBool;
				ptrBool = &(data->rComport_Ctrl_Func);		
				ptrBool->is_cdcacm = (DCL_BOOL)KAL_TRUE;
#if defined(__USB_COMPORT_SUPPORT_TC01_DRIVER__)
				//only port1 is CDCACM in MTK and LGE driver
				if (dev != uart_port_usb)
				{
					ptrBool->is_cdcacm = (DCL_BOOL)KAL_FALSE;
				}
#elif defined(__USB_MODEM_CARD_SUPPORT__)
				if ((dev != uart_port_usb)&&(dev != uart_port_usb2))
				{
					ptrBool->is_cdcacm = (DCL_BOOL)KAL_FALSE;
				}
#endif
			}
			break;
			
		case USB_CMD_FT_PORT:
			{
				USB_DRV_CTRL_COM_FT_PORT* ptr_CDCACM_fun8;
				ptr_CDCACM_fun8 = &(data->rComport_Ctrl_Fun8);
				ptr_CDCACM_fun8->u1ftPort = USB_Acm_FT_Port();
			}
			break;
		case USB_CMD_ACM_RING_BUFF_THRESHOLD_EN:
			{
				USB_DRV_CTRL_COM_RB_THRESHOLD_EN* ptr_CDCACM_fun7;
				ptr_CDCACM_fun7 = &(data->rComport_Ctrl_Fun7);
				USB_Acm_Ring_Buffer_Threshold_Enable(dev, (kal_bool)ptr_CDCACM_fun7->fgbset, (module_type)ptr_CDCACM_fun7->u4OwenrId); 				
			}
			break;
		case USB_CMD_USB2UART_TX_DMA_CBK:
			{
				USB2UART_Tx_DMA_Callback(dev);					
			}
			break;	
			case USB_CMD_IS_CDCACM_ACTIVE:
			{
				USB_DRV_CTRL_COM_TYPE_QUERY_T* ptrBool;
				USB_DEVICE_TYPE 	device_type;
				ptrBool = &(data->rComport_Ctrl_Func);		
				device_type = USB_Get_Device_Type();
				if((device_type == USB_CDC_ACM) ||
					(device_type == USB_COMPOSITE_VIDEO_COM) ||
					(device_type == USB_COMPOSITE_MULTI_COM) ||
					(device_type == USB_COMPOSITE_DEVICES))
				{
					 ptrBool->is_cdcacm = (DCL_BOOL)KAL_TRUE;
				}
				else
				{
					 ptrBool->is_cdcacm = (DCL_BOOL)KAL_FALSE; 			
				}
			}
			break;	

#ifdef  __USB_HIGH_SPEED_COM_PORT_ENABLE__

		case USB_CMD_HIGH_SPEED_IF_ENABLE:
			{
				USB_DRV_CTRL_COM_HIGH_SPEED_IF* ptr_CDCACM_fun2;
				ptr_CDCACM_fun2 = &(data->rComport_Ctrl_Fun2);
				ptr_CDCACM_fun2->u2Retresult =(DCL_BOOL)(USB_EnableHighSpeedPort(dev, (kal_bool)ptr_CDCACM_fun2->enable, (module_type)ptr_CDCACM_fun2->u4OwenrId,(USB_Transfer_type)ptr_CDCACM_fun2->ptransfer_type));
			}
			break;

		case USB_CMD_REG_TX_CB:
			{
				UART_CTRL_REG_TX_CB_T* prCtrlTxCB;
				prCtrlTxCB = &(data->rUARTCtrlREGTXCB);
				USB_Register_HighSpeed_TX_Callback(dev, (module_type)prCtrlTxCB->u4OwenrId, (usb_dma_callback)prCtrlTxCB->func); 
			}
			break;
			
		case USB_CMD_TX_DATA_STATUS:
			{
				USB_DRV_CTRL_COM_RESPONSE* presonse;
				presonse =  &(data->rComport_Ctrl_Fun5);
				presonse->u2Retresult = (DCL_BOOL)USB_QueryHSTxDataLeft(dev);
			}

		case USB_CMD_SEND_DATA:
			{
				USB_DRV_CTRL_COM_SEND_DATA* ptr_CDCACM_fun3;
				ptr_CDCACM_fun3 = &(data->rComport_Ctrl_Fun3);
				ptr_CDCACM_fun3->u2RetSize = (DCL_UINT16)(USB_Send_Data(dev, ptr_CDCACM_fun3->puBuffaddr,ptr_CDCACM_fun3->u2Length, (module_type)ptr_CDCACM_fun3->u4OwenrId));//,(USB_Transfer_type)ptr_CDCACM_fun3->ptransfer_type));
			}
			break;	
			
		case USB_CMD_GET_DATA:
			{
				USB_DRV_CTRL_COM_GET_DATA* ptr_CDCACM_fun4;
				ptr_CDCACM_fun4 = &(data->rComport_Ctrl_Fun4);
				ptr_CDCACM_fun4->u2RetSize = (DCL_UINT16)(USB_Receive_Data(dev, ptr_CDCACM_fun4->puBuffaddr, (module_type)ptr_CDCACM_fun4->u4OwenrId, ptr_CDCACM_fun4->u2Length,ptr_CDCACM_fun4->pustatus,(USB_Requ_type)ptr_CDCACM_fun4->ptype));//,(USB_Transfer_type)ptr_CDCACM_fun4->ptransfer_type));
			}
			break;
		case USB_CMD_PUSH_DATA:
			{
				USB_DRV_CTRL_COM_PUSH_DATA* ptr_CDCACM_fun11;
				ptr_CDCACM_fun11 = &(data->rComport_Ctrl_Fun11);
				USB_HighSpeedPushBuff(dev, (module_type)ptr_CDCACM_fun11->u4OwenrId);
			}
			break;

		case USB_CMD_SEND_ISR_DATA:
			{
				USB_DRV_CTRL_COM_SEND_ISR_DATA* ptr_CDCACM_fun6;
				ptr_CDCACM_fun6 = &(data->rComport_Ctrl_Fun6);
				ptr_CDCACM_fun6->u2RetSize = (DCL_UINT16)(USB_Send_ISR_Data(dev, ptr_CDCACM_fun6->puBuffaddr,ptr_CDCACM_fun6->u2Length, (module_type)ptr_CDCACM_fun6->u4OwenrId,ptr_CDCACM_fun6->umode, ptr_CDCACM_fun6->uescape_char));//,(USB_Transfer_type)ptr_CDCACM_fun6->ptransfer_type));
			}
			break;	

#if defined(__USB_TETHERING__)||defined(__MBIM_SUPPORT__)||defined(__ECM_SUPPORT__)
		case USB_CMD_CTRL_SEND_DATA:
			{
				USB_DRV_CTRL_COM_SEND_DATA* ptr_CDCACM_fun3;
				ptr_CDCACM_fun3 = &(data->rComport_Ctrl_Fun3);
				ptr_CDCACM_fun3->u2RetSize = (DCL_UINT16)(USB_CTRLPutBytes(dev, ptr_CDCACM_fun3->puBuffaddr,ptr_CDCACM_fun3->u2Length, (module_type)ptr_CDCACM_fun3->u4OwenrId));
			}
			break;

		case USB_CMD_CTRL_GET_DATA:
			{
				USB_DRV_CTRL_COM_GET_DATA* ptr_CDCACM_fun4;
				ptr_CDCACM_fun4 = &(data->rComport_Ctrl_Fun4);
				ptr_CDCACM_fun4->u2RetSize = (DCL_UINT16)(USB_CTRLGetFrame(dev, ptr_CDCACM_fun4->puBuffaddr, (module_type)ptr_CDCACM_fun4->u4OwenrId,(USB_Requ_type)ptr_CDCACM_fun4->ptype));
			}
			break;
			
#if defined(__MBIM_SUPPORT__)
		case USB_CMD_CTRL_FLUSH_DATA:
			{
				kal_uint32 savedMask;
				
				savedMask = SaveAndSetIRQMask();
				g_UsbACM[USB_PORT[dev]].ctrl_data_done = KAL_TRUE;
				USB_Clear_Tx_EP_FIFO(g_UsbACM[USB_PORT[dev]].intrpipe->byEP, USB_ENDPT_INTR, KAL_FALSE);
				
				if(g_UsbACM[USB_PORT[dev]].send_ctrl_Txilm == KAL_TRUE)
				{
					g_UsbACM[USB_PORT[dev]].send_ctrl_Txilm = KAL_FALSE;
					RestoreIRQMask(savedMask);
					USB2UART_Sendilm(uart_port_usb, MSG_ID_CTRL_UART_READY_TO_WRITE_IND);
					savedMask = SaveAndSetIRQMask();
				}
				RestoreIRQMask(savedMask);
				
				usb_drv_trace0(USB2UARTPort[USB_PORT[dev]].ownerid, (kal_uint32)USBACM_FLC_HIGHSPEED_FLUSH);
			}
			break;
#endif

		case USB_CMD_HALT:
			{
				UART_CTRL_OWNER_T* prCtrlOwner;
				prCtrlOwner = &(data->rUARTCtrlOWNER);
				USB_RNDIS_HaltBus(dev, (module_type)prCtrlOwner->u4OwenrId);					
			}
			break;
#endif /*__USB_TETHERING__ || __MBIM_SUPPORT__ || __ECM_SUPPORT__*/

#if defined(__MBIM_SUPPORT__)||defined(__ECM_SUPPORT__)
		case USB_CMD_RX_RECV_DATA:
			{
				TGPD *p_GPD = NULL;
				UART_GIO_RX_RECV_DATA_T* ptr_rUARTGIORXRecvData;
				ptr_rUARTGIORXRecvData = &(data->rUARTGIORXRecvData);
				ptr_rUARTGIORXRecvData->pOut_GPD = NULL;

				USB_Mask_USB_CORE((USB_MASK_OWNER)USB_PORT[dev]);
				if (USB_DMAQ_RX_GPD_HEADER != NULL)	//may UPS just flush GPD
				{
					if(((USB_DMAQ_RX_GPD_HEADER->flag & RXGPD_FLAGS_HWO) == 0)&&(USB_DMAQ_RX_GPD_HEADER != (&USB_DMAQ_RX_GPD_NULL)))
					{
						//set buffer header to caller.
						ptr_rUARTGIORXRecvData->pOut_GPD = (DCL_UINT8 *)USB_DMAQ_RX_GPD_HEADER;
						
						//search tails.
						p_GPD = USB_DMAQ_RX_GPD_HEADER;
						USB_DMAQ_RX_GPD_HEADER = USB_DMAQ_RX_GPD_HEADER->pNext;
						p_GPD->pNext = NULL;
					}
					else
					{
						g_UsbACM[USB_PORT[dev]].send_Rxilm = KAL_TRUE;
						usb_drv_trace2(USB2UARTPort[USB_PORT[dev]].ownerid, (kal_uint32)USB_DMAQ_RXGPD_INFO, (kal_uint32)USB_DMAQ_RX_GPD_HEADER, (kal_uint32)USB_DMAQ_RX_GPD_HEADER->pNext);
					}
				}
				if(USB_Get_UnMask_Irq() == KAL_TRUE)
					USB_UnMask_USB_CORE((USB_MASK_OWNER)USB_PORT[dev]);
			}
			break;
			
		case USB_CMD_TX_RECYCLE_GPD:
			{
				TGPD *p_GPD = NULL;
				UART_GIO_TX_RECYCLE_GPD_T* ptr_rUARTGIOTXRecycleGPD;
				ptr_rUARTGIOTXRecycleGPD = &(data->rUARTGIOTXRecycleGPD);
				ptr_rUARTGIOTXRecycleGPD->pOut_GPD = NULL;

				if (USB_DMAQ_TX_GPD_HEADER != NULL)	//may UPS just flush GPD
				{
					if(((USB_DMAQ_TX_GPD_HEADER->flag & TXGPD_FLAGS_HWO) == 0)&&(USB_DMAQ_TX_GPD_HEADER != (&USB_DMAQ_TX_GPD_NULL)))
					{
						//set buffer header to caller.
						ptr_rUARTGIOTXRecycleGPD->pOut_GPD = (DCL_UINT8 *)USB_DMAQ_TX_GPD_HEADER;
	
						//search tails.
						p_GPD = USB_DMAQ_TX_GPD_HEADER;
						USB_DMAQ_TX_GPD_HEADER = NULL;
						while(((p_GPD->pNext) != (&USB_DMAQ_TX_GPD_NULL)))
						{
							if (p_GPD == NULL)
								ASSERT(0);
							p_GPD = p_GPD->pNext;
						}
						p_GPD->pNext = NULL;
						
					}
					else
					{
						usb_drv_trace2(USB2UARTPort[USB_PORT[dev]].ownerid, (kal_uint32)USB_DMAQ_TXGPD_INFO, (kal_uint32)USB_DMAQ_TX_GPD_HEADER, (kal_uint32)USB_DMAQ_TX_GPD_HEADER->pNext);
					}
				}
				
				if (USB_DMAQ_TX_GPD_QUEUED != NULL)
				{
					USB_DMAQ_TX_GPD_HEADER = USB_DMAQ_TX_GPD_QUEUED;
					USB_DMAQ_TX_GPD_QUEUED = NULL;
					if (USB_DMAQ_TX_GPD_HEADER != (&USB_DMAQ_TX_GPD_NULL))
					{
						drv_trace2(TRACE_FUNC, (kal_uint32)USB_DMAQ_TXGPD_SETUP, (kal_uint32)p_GPD, (kal_uint32)USB_DMAQ_TX_GPD_HEADER);                                                                    
						USB_DMAQ_Setup(g_UsbACM[USB_PORT[dev]].txpipe->byEP, USB_EP_TX_DIR, KAL_TRUE, (kal_uint32)USB_DMAQ_TX_GPD_HEADER, (usb_dmaq_CB)USB2UART_TX_DMAQ_Callback, (usb_dmaq_CB)USB2UART_TX_DMAQ_Empty_Callback,(void *)&USB2UARTPort[USB_PORT[dev]].port_no);
					}
				}
				
			} 
			break;
        
		case USB_CMD_TX_FLUSH_GPD:
			{
				TGPD *p_GPD = NULL;
				UART_GIO_TX_FLUSH_GPD_T* ptr_rUARTGIOTXFlushGPD;
				ptr_rUARTGIOTXFlushGPD = &(data->rUARTGIOTXFlushGPD);
				
				drv_trace0(TRACE_FUNC, (kal_uint32)USB_DMAQ_TXGPD_FLUSH);
				USB_DMAQ_Stop(g_UsbACM[USB_PORT[dev]].txpipe->byEP, USB_EP_TX_DIR);

				if (USB_DMAQ_TX_GPD_HEADER == NULL || USB_DMAQ_TX_GPD_HEADER == (&USB_DMAQ_TX_GPD_NULL))
				{
					USB_DMAQ_TX_GPD_HEADER = NULL;
					USB_DMAQ_TX_GPD_QUEUED = NULL;
				}
				else
				{
					p_GPD = (TGPD *)USB_DMAQ_TX_GPD_HEADER;;
					do{
						if (p_GPD->pNext == (&USB_DMAQ_TX_GPD_NULL))
							p_GPD->pNext = NULL;
						p_GPD = p_GPD->pNext;
					}while(p_GPD != NULL);
				}
				ptr_rUARTGIOTXFlushGPD->pOut_GPD = (DCL_UINT8 *)USB_DMAQ_TX_GPD_HEADER;
				USB_DMAQ_TX_GPD_HEADER = NULL;
				USB_DMAQ_TX_GPD_QUEUED = NULL;

			}
			break;
		case USB_CMD_RX_FLUSH_GPD:
			{
				TGPD *p_GPD = NULL;
				UART_GIO_RX_FLUSH_GPD_T* ptr_rUARTGIORXFlushGPD;
				
				drv_trace0(TRACE_FUNC, (kal_uint32)USB_DMAQ_RXGPD_FLUSH);
				ptr_rUARTGIORXFlushGPD = &(data->rUARTGIORXFlushGPD);
				USB_DMAQ_Stop(g_UsbACM[USB_PORT[dev]].rxpipe->byEP, USB_EP_RX_DIR);
				
				if (USB_DMAQ_RX_GPD_HEADER == NULL || USB_DMAQ_RX_GPD_HEADER == (&USB_DMAQ_RX_GPD_NULL))
				{
					USB_DMAQ_RX_GPD_HEADER = NULL;
				}
				else
				{
					p_GPD = (TGPD *)USB_DMAQ_RX_GPD_HEADER;;
					do{
						if (p_GPD->pNext == (&USB_DMAQ_RX_GPD_NULL))
							p_GPD->pNext = NULL;
						p_GPD = p_GPD->pNext;
					}while(p_GPD != NULL);
				}

				ptr_rUARTGIORXFlushGPD->pOut_GPD = (DCL_UINT8 *)USB_DMAQ_RX_GPD_HEADER;
				USB_DMAQ_RX_GPD_HEADER = NULL;
			}
			break;
		case USB_ECM_CMD_CDC_TYPE:
			{
				USB_DRV_CTRL_CDC_CLASS* ptr_info;
				ptr_info = &(data->rEcm_Ctrl_Fun2);
				ptr_info->ptype = (DCL_UINT8)(USB2UARTPort[USB_PORT[dev]].class_type);
			}
			break;
#endif /*__MBIM_SUPPORT__*/
#endif /*__USB_HIGH_SPEED_COM_PORT_ENABLE__*/

#if defined(__ECM_SUPPORT__)
		case USB_ECM_CMD_ENCM_NOTIFY:
			{
				USB_DRV_CTRL_ECM_NOTIFY* ptr_info;
				ptr_info = &(data->rEcm_Ctrl_Fun1);
				ptr_info->u2Retresult = (DCL_BOOL)USB2UART_ECM_Notification(dev,(module_type)ptr_info->u4OwenrId,(USB_ECM_type)ptr_info->ptype,ptr_info->puBuffaddr);
			}
			break;
#endif /*__ECM_SUPPORT__*/

#ifdef DRV_USB_HW_TX_DIRECT_PATH_SUPPORT
		case USB_CMD_GET_MPS:
			{
				USB_DRV_CTRL_COM_INFO* ptr_info;
				ptr_info = &(data->rComport_Ctrl_Fun10);

				/*check enumeration done! if NOT, return 0*/
				if (USB_Get_Device_State() == DEVSTATE_CONFIG)
					ptr_info->u4info = USB_Bulk_Max_Packet_Size();
				else
					ptr_info->u4info = 0;
			}
			break;
			
		case USB_CMD_GET_TX_EP_NUMBER:
			{
				/*check enumeration done! if NOT, return 0*/
				USB_DRV_CTRL_COM_INFO* ptr_info;
				ptr_info = &(data->rComport_Ctrl_Fun10);
				ptr_info->u4info = g_UsbACM[USB_PORT[dev]].txpipe->byEP;  //EP is in ZI region, so default value is 0
			}
			break;
			
		case USB_CMD_GET_RX_EP_NUMBER:
			{
				/*check enumeration done! if NOT, return 0*/
				USB_DRV_CTRL_COM_INFO* ptr_info;
				ptr_info = &(data->rComport_Ctrl_Fun10);
				ptr_info->u4info = g_UsbACM[USB_PORT[dev]].rxpipe->byEP; //EP is in ZI region, so default value is 0
			}
			break;
			
		case USB_CMD_GET_HW_TXPKTRDY_ADDR:
			{
				USB_DRV_CTRL_COM_INFO* ptr_info;
				ptr_info = &(data->rComport_Ctrl_Fun10);
				ptr_info->u4info = USB_EP_Bulk_HW_TxPktRdy_Addr();
			}
			break;
			
		case USB_CMD_SET_HW_TXPKTRDY:
			{
				USB_EP_Bulk_HW_Set_TxPktRdy(g_UsbACM[USB_PORT[dev]].txpipe->byEP);
			}
			break;
			
		case USB_CMD_GET_HW_FIFO_ADDR:
			{
				USB_DRV_CTRL_COM_INFO* ptr_info;
				ptr_info = &(data->rComport_Ctrl_Fun10);
				ptr_info->u4info = USB_EP_Bulk_HW_FIFO_Addr(g_UsbACM[USB_PORT[dev]].rxpipe->byEP);
			}
			break;
			
		case USB_CMD_HW_TX_DIRECT_PATH_ENABLE:
			{
				USB_DRV_CTRL_COM_DIRECT_PATH_IF* ptr_CDCACM_fun2;
				ptr_CDCACM_fun2 = &(data->rComport_Ctrl_Fun2);
				ptr_CDCACM_fun2->u2Retresult = (DCL_BOOL)USB_Enable_TX_Direct_Path(dev, (kal_bool)ptr_CDCACM_fun2->enable, (module_type)ptr_CDCACM_fun2->u4OwenrId);
			}
			break;
#endif /*DRV_USB_HW_TX_DIRECT_PATH_SUPPORT*/

		default:
//			ASSERT(0);
			return_status = STATUS_INVALID_CMD;
			break;
	}
	return return_status;
}



static kal_bool USB2UART_Check_Config(kal_uint32 usb_port)
{
	if((g_UsbACM[usb_port].txpipe == NULL)||(USB2UARTPort[usb_port].initialized == KAL_FALSE)|| (USB_Get_Device_State() != DEVSTATE_CONFIG))
		return KAL_FALSE;
	else
		return KAL_TRUE;
}




/************************************************************
	Communication with UART owner and initialize functions
*************************************************************/

/* Send ilm to UART owner */
void USB2UART_Sendilm(UART_PORT port, msg_type msgid)
{
#ifndef __MEUT__
	kal_uint32 usb_port = USB_PORT[port];
//	ilm_struct *USB2UART_ilm = NULL;
	void *port_ptr = NULL;
//	module_type src_mod;
	UART_PORT real_port = port;
	module_type 				temp_ownerid;

	/* In assert mode, we cannot send message.
	 * Thus, we just retun.
	 */
	 if (USB_Exception_Check() == KAL_FALSE) //if(INT_Exception_Enter != 0 || (is_init_log_enable == KAL_TRUE && is_init_stage == KAL_TRUE))
		return;

#if defined(__USB_TETHERING__)||defined(__MBIM_SUPPORT__)||defined(__ECM_SUPPORT__)
	if(msgid == MSG_ID_RNDIS_USB_CONFIG_CNF) // at this time, owner ID is MOD_DRV_HISR 
	{	// flow : 1.  UPS: config  2. USB: config_Cnf   3. UPS: open port  		
		rndis_usb_config_cnf_struct  *tmp;  
		
		/* Notify UPS USB is config */
		tmp = (rndis_usb_config_cnf_struct*)construct_local_para(sizeof(rndis_usb_config_cnf_struct), TD_CTRL);
		tmp->confirm = KAL_FALSE;
		port_ptr = tmp;

#if defined(__USB_TETHERING__)
		USB_Send_Msg_Ext_Queue(MOD_UPS_HIGH, msgid, port_ptr);
#elif defined(__MBIM_SUPPORT__)||defined(__ECM_SUPPORT__)		
		USB_Send_Msg_Ext_Queue(MOD_MBIM, msgid, port_ptr);
#endif
		
//		DRV_BuildPrimitive(USB2UART_ilm, src_mod,MOD_UPS, msgid, port_ptr);
//		msg_send_ext_queue(USB2UART_ilm);
		
		return;
	}
	#if defined(__MBIM_SUPPORT__)
	else if(msgid == MSG_ID_MBIM_USB_RESET_IND)
	{
		USB_Send_Msg_Ext_Queue(MOD_UPS_HIGH, MSG_ID_MBIM_USB_RESET_IND, NULL);
		return;
	}
	#endif
#endif



	if(USB2UARTPort[usb_port].ownerid == MOD_DRV_HISR)
		return;


#if defined(__USB_MULTIPLE_COMPORT_SUPPORT__)
	// because EM setting as COM2 + other function  -->for user using :  switch to COM1 + other function
	// need to switch back for upper layer 
	// normal mapping :  USB_PORT[uart_port_usb] = 0;   USB_PORT[uart_port_usb2] = 1
	if (USB_PORT[uart_port_usb] == USB_PORT[uart_port_usb2])
		real_port = uart_port_usb2;
#endif


	temp_ownerid = USB2UARTPort[usb_port].ownerid;

	switch(msgid)
	{
	case MSG_ID_UART_READY_TO_READ_IND:
		{
			uart_ready_to_read_ind_struct *tmp;
			tmp = (uart_ready_to_read_ind_struct *)construct_local_para(sizeof(uart_ready_to_read_ind_struct),TD_UL);
			tmp->port = real_port;
			port_ptr = tmp;
#if defined(__USB_TETHERING__)||defined(__MBIM_SUPPORT__)||defined(__ECM_SUPPORT__)
			if (temp_ownerid == MOD_UPS_HIGH)
			{
				#if defined(__USB_TETHERING__)
				temp_ownerid = MOD_UPS;
				#else
				temp_ownerid = MOD_MBIM;
				#endif
			}
#endif			
		}
		break;

	case MSG_ID_UART_READY_TO_WRITE_IND:
		{
			uart_ready_to_write_ind_struct *tmp;
			tmp = (uart_ready_to_write_ind_struct *)construct_local_para(sizeof(uart_ready_to_write_ind_struct),TD_UL);
			tmp->port = real_port;
			port_ptr = tmp;
#if defined(__USB_TETHERING__)||defined(__MBIM_SUPPORT__)||defined(__ECM_SUPPORT__)
			if (temp_ownerid == MOD_UPS_HIGH)
				#if defined(__USB_TETHERING__)
				temp_ownerid = MOD_UPS;
				#else
				temp_ownerid = MOD_MBIM;
				#endif
#endif					
		}
		break;

	case MSG_ID_UART_ESCAPE_DETECTED_IND:
		{
			uart_escape_detected_ind_struct *tmp;
			tmp = (uart_escape_detected_ind_struct *)construct_local_para(sizeof(uart_escape_detected_ind_struct),TD_UL);
			tmp->port = real_port;
			port_ptr = tmp;
		}
		break;

	case MSG_ID_UART_PLUGOUT_IND:
		{
			/* Notify UART owner plug out */
			uart_plugout_ind_struct *tmp;

			tmp = (uart_plugout_ind_struct*)construct_local_para(sizeof(uart_plugout_ind_struct), TD_CTRL);
			tmp->port = real_port;
			port_ptr = tmp;
		}
		break;
		
	case MSG_ID_UART_DSR_CHANGE_IND:
		{
			/* Notify UART owner plug out */
			uart_dsr_change_ind_struct *tmp;
			tmp = (uart_dsr_change_ind_struct*)construct_local_para(sizeof(uart_dsr_change_ind_struct), TD_UL);
			tmp->port = real_port;
			port_ptr = tmp;			
		}
		break;
#if defined(__USB_TETHERING__)||defined(__MBIM_SUPPORT__)||defined(__ECM_SUPPORT__)
	case MSG_ID_CTRL_UART_READY_TO_READ_IND:
		{
			uart_ready_to_read_ind_struct *tmp;
			tmp = (uart_ready_to_read_ind_struct *)construct_local_para(sizeof(uart_ready_to_read_ind_struct),TD_UL);
			tmp->port = real_port;
			port_ptr = tmp;
		}
		break;

	case MSG_ID_CTRL_UART_READY_TO_WRITE_IND:
		{
			uart_ready_to_write_ind_struct *tmp;
			tmp = (uart_ready_to_write_ind_struct *)construct_local_para(sizeof(uart_ready_to_write_ind_struct),TD_UL);
			tmp->port = real_port;
			port_ptr = tmp;
		}
		break;
#endif

	default:
		EXT_ASSERT(0, (kal_uint32)msgid, 0, 0);
		break;
	}

	USB_Send_Msg_Ext_Queue(temp_ownerid, msgid, port_ptr);

//	DRV_BuildPrimitive(USB2UART_ilm, src_mod,USB2UARTPort[usb_port].ownerid, msgid, port_ptr);
//	msg_send_ext_queue(USB2UART_ilm);
#endif
}


void USB2UART_Switch_Mapping(UART_PORT port,kal_uint8 new_port,kal_bool open)
{
	module_type ownerid = USB2UARTPort[USB_PORT[port]].ownerid;

	USB_Dbg_Trace(USB_ACM_USB2UART_Switch_port,(kal_uint32)port, new_port);
	
	if(ownerid != MOD_DRV_HISR) // old port has already be-opened
	{	
		if(open == KAL_TRUE)
		{			
			USB_PORT[port] = new_port;
			USB2UART_open(port,ownerid); // open switch port
		}
		else
		{
			USB2UART_close(port,ownerid); // close switch port			
			USB_PORT[port] = new_port;
		}
	}
	else
	{
		USB_PORT[port] = new_port;
	}
}



/* Initialize USB2UART setting, called when driver initialize, no matter user select as UART or not */
void USB2UART_init(void)
{
	kal_uint32 usb_port;


	/* Setup N81,(UART_WLS_8 | UART_NONE_PARITY | UART_1_STOP) = 0x03 */
	/* BaudRate and autoflowcontrol */
	UARTDCBStruct  UART_DefaultConfig =
	{
		UART_BAUD_115200,    /* baud; */
		len_8,               /* dataBits; */
		sb_1,                /*stopBits; */
		pa_none,             /* parity; */
		fc_none,             /*no flow control*/
		0x11,                /* xonChar; */
		0x13,                /* xoffChar; */
		KAL_FALSE
	};

//	if(uart_port_usb2 != (uart_port_usb+1))
//		ASSERT(0);

	if (g_USB_Dcl_Handle == 0)
		g_USB_Dcl_Handle = DclUSB_DRV_Open(DCL_USB, FLAGS_NONE);
		
#ifndef __MEUT__
	g_UsbACM_Comm.acm_param = USB_GetCustomFunc()->get_acm_param_func();
	/* Initialize USB port value */
	USB_PORT[uart_port_usb] = 0;

	//UART_Register(uart_port_usb, USB_TYPE, (UartDriver_strcut*)&USB2UartDriver);
	USB2UARTPort[0].port_no = uart_port_usb;

#if defined(__USB_MULTIPLE_COMPORT_SUPPORT__)
	/* Initialize USB port value */
	USB_PORT[uart_port_usb2] = 1;

	//UART_Register(uart_port_usb2, USB_TYPE, (UartDriver_strcut*)&USB2UartDriver);
	USB2UARTPort[1].port_no = uart_port_usb2;

	/* Initialize USB port value */
#if defined (__USB_MODEM_CARD_SUPPORT__)
	USB_PORT[uart_port_usb3] = 2;

	//UART_Register(uart_port_usb3, USB_TYPE, (UartDriver_strcut*)&USB2UartDriver);
	USB2UARTPort[2].port_no = uart_port_usb3;

	USB_PORT[uart_port_usb4] = 3;

	//UART_Register(uart_port_usb3, USB_TYPE, (UartDriver_strcut*)&USB2UartDriver);
	USB2UARTPort[3].port_no = uart_port_usb4;
	USB_PORT[uart_port_usb5] = 4;

	//UART_Register(uart_port_usb3, USB_TYPE, (UartDriver_strcut*)&USB2UartDriver);
	USB2UARTPort[4].port_no = uart_port_usb5;
#endif //(__USB_MODEM_CARD_SUPPORT__)
#endif
#endif

	for(usb_port = 0; usb_port < MAX_USB_PORT_NUM;usb_port++)
	{
		/* Set UART setting to USB2UARTPort.DCB and g_UsbACM.line_coding */
		USB2UARTPort[usb_port].UART_id = MOD_DRV_HISR;

		kal_mem_cpy(&USB2UARTPort[usb_port].DCB, &UART_DefaultConfig, sizeof(UARTDCBStruct));

		if((kal_uint32)USB2UARTPort[usb_port].ownerid == 0)
		{
			USB2UARTPort[usb_port].ownerid = MOD_DRV_HISR;
			UART2USB_DCB2LineCoding(&USB2UARTPort[usb_port].DCB, &g_UsbACM[usb_port].line_coding);
		}

		g_UsbACM[usb_port].send_Txilm = KAL_FALSE;
		g_UsbACM[usb_port].send_Rxilm = KAL_TRUE;

//		usb_drv_trace1(USB2UARTPort[usb_port].ownerid, (kal_uint32)USBACM_INIT_READY_TO_READ_FLAG, usb_port);

		g_UsbACM[usb_port].config_send_Txilm = KAL_FALSE;
		USB2UARTPort[usb_port].tx_cb = USB2UART_Dafault_Tx_Callback;
		USB2UARTPort[usb_port].rx_cb = USB2UART_Dafault_Rx_Callback;
//		USB2UARTPort[usb_port].port_no = (UART_PORT)(uart_port_usb+usb_port);
	}

#ifdef  __USB_HIGH_SPEED_COM_PORT_ENABLE__
	//Register HS CB
	usb_hs_tx_reg_cb = USB2UART_Tx_DMA1_Callback;
	#if defined(__USB_MULTIPLE_COMPORT_SUPPORT__)
	  usb2_hs_tx_reg_cb = USB2UART_Tx_DMA2_Callback;
	  #if defined (__USB_MODEM_CARD_SUPPORT__)
	  usb3_hs_tx_reg_cb = USB2UART_Tx_DMA3_Callback;
	  usb4_hs_tx_reg_cb = USB2UART_Tx_DMA4_Callback;
	  usb5_hs_tx_reg_cb = USB2UART_Tx_DMA5_Callback;
	  #endif  //#if defined (__USB_MODEM_CARD_SUPPORT__)
	#endif  //#if defined(__USB_MULTIPLE_COMPORT_SUPPORT__)
#endif
}






/* Clear Tx Ring buffer */
void USB2UART_Clear_Tx_Buffer(UART_PORT port)
{
	kal_uint32 usb_port = USB_PORT[port];

	USB2UART_ClrTxBuffer(port, USB2UARTPort[usb_port].ownerid);
	USB_Dbg_Trace(USB_ACM_USB2UART_Clear_Tx_Buffer, (kal_uint32)port, 0);
}


/* Clear TX isr buffer */
void USB2UART_Clear_Tx_ISR_Buffer(UART_PORT port)
{
	kal_uint32 usb_port = USB_PORT[port];
	kal_uint32 savedMask;

	usb_drv_trace1(USB2UARTPort[usb_port].ownerid, (kal_uint32)USBACM_CLEAR_TX_ISR_BUF, usb_port);
	USB_Dbg_Trace(USB_ACM_USB2UART_Clear_Tx_ISR_Buffer, (kal_uint32)port, 0);

	savedMask = SaveAndSetIRQMask();
	USB2UARTPort[usb_port].Tx_Buffer_ISR.Write = 0;
	USB2UARTPort[usb_port].Tx_Buffer_ISR.Read = 0;
	USB_Stop_DMA_Channel(g_UsbACM[usb_port].txpipe->byEP, USB_EP_TX_DIR);
	g_UsbACM[usb_port].setup_dma = KAL_FALSE;
	if(g_UsbACM[usb_port].put_start == KAL_TRUE)
	{
	   g_UsbACM[usb_port].dmaf_setmember |= 0x10;
	}
	RestoreIRQMask(savedMask);
}


/* Clear RX buffer */
void USB2UART_Clear_Rx_Buffer(UART_PORT port)
{
	kal_uint32 usb_port = USB_PORT[port];

	USB2UART_ClrRxBuffer(port, USB2UARTPort[usb_port].ownerid);
	USB_Dbg_Trace(USB_ACM_USB2UART_Clear_Rx_ISR_Buffer, (kal_uint32)port, 0);
}


/************************************************************
	UART driver  functions
*************************************************************/

/* Open USB2UART port */
static kal_bool USB2UART_open(UART_PORT port, module_type ownerid)
{
	kal_uint32 usb_port = USB_PORT[port];
	kal_uint32 length_tx =0 ,length_rx = 0;

	if((USB_Get_Device_Type() == USB_CDC_ACM)&&(port != uart_port_usb))
	{
		ASSERT(0);
	}

	if((USB_IS_LOGGING_PORT[port] == KAL_TRUE)||((g_UsbACM_Comm.acm_owner == USB_ACM_OWNER_FT)&&(USBDL_Mode_Type()== USBDL_MODE_NONE)))//(USBDL_Is_USB_Download_Mode() == KAL_FALSE)&&(USBDL_Is_USB_Fast_Meta_Mode()== KAL_FALSE)))
	{
		ASSERT(0);
	}

	/* It cannot be opened if uart owner did not close it before */
	if(USB2UARTPort[usb_port].ownerid != MOD_DRV_HISR)
		return KAL_FALSE;

	if((USB_INT_USBBoot() == KAL_TRUE)&&(ownerid != MOD_TST_READER))// only boot trace feature can open com port in boot mode
		return KAL_FALSE;

	if(ownerid == MOD_TST_READER)
	{
		if(USB2UARTPort[usb_port].RingBuffers.txISR_buffer == NULL)	
			USB2UARTPort[usb_port].RingBuffers.txISR_buffer = (kal_uint8 *)USB_Get_Memory(USB_TXISR_RING_BUFFER_SIZE);//(kal_uint8 *)g_UsbACM_Comm.acm_param->txisr_ringbuff_3;
		Buf_init(&(USB2UARTPort[usb_port].Tx_Buffer_ISR), (kal_uint8 *)(USB2UARTPort[usb_port].RingBuffers.txISR_buffer),USB_TXISR_RING_BUFFER_SIZE);
	}

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
#if defined(__USB_MULTIPLE_COMPORT_SUPPORT__)	
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
#if defined (__USB_MODEM_CARD_SUPPORT__)	
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
#endif  //	__USB_MODEM_CARD_SUPPORT__
#endif
#else
	if (usb_port == 0)
	{
		length_tx = USB_TX_RING_BUFFER_1_SIZE;
		length_rx = USB_RX_RING_BUFFER_1_SIZE;		

	}
#if defined(__USB_MULTIPLE_COMPORT_SUPPORT__)	
	else if (usb_port == 1)
	{
		length_tx = USB_TX_RING_BUFFER_2_SIZE;
		length_rx = USB_RX_RING_BUFFER_2_SIZE;		
	}
#if defined (__USB_MODEM_CARD_SUPPORT__)
	else if (usb_port == 2)
	{
		length_tx = USB_TX_RING_BUFFER_3_SIZE;
		length_rx = USB_RX_RING_BUFFER_3_SIZE;	
	}
	else if (usb_port == 3)
	{
		length_tx = USB_TX_RING_BUFFER_4_SIZE;
		length_rx = USB_RX_RING_BUFFER_4_SIZE;	
	}
	else if (usb_port == 4)
	{
		length_tx = USB_TX_RING_BUFFER_5_SIZE;
		length_rx = USB_RX_RING_BUFFER_5_SIZE;	
	}
#endif  //	__USB_MODEM_CARD_SUPPORT__	
#endif
	else
		ASSERT(0);
		
if(USB2UARTPort[usb_port].RingBuffers.rx_buffer == NULL)		
	USB2UARTPort[usb_port].RingBuffers.rx_buffer = (kal_uint8 *)USB_Get_Memory(length_rx);//(kal_uint8 *)g_UsbACM_Comm.acm_param->rx_ringbuff_2;
Buf_init(&(USB2UARTPort[usb_port].Rx_Buffer), (kal_uint8 *)(USB2UARTPort[usb_port].RingBuffers.rx_buffer),length_rx);

if(USB2UARTPort[usb_port].RingBuffers.tx_buffer == NULL)				
	USB2UARTPort[usb_port].RingBuffers.tx_buffer = (kal_uint8 *)USB_Get_Memory(length_tx);//(kal_uint8 *)g_UsbACM_Comm.acm_param->tx_ringbuff_2;
Buf_init(&(USB2UARTPort[usb_port].Tx_Buffer), (kal_uint8 *)(USB2UARTPort[usb_port].RingBuffers.tx_buffer),length_tx);

#endif
	USB2UARTPort[usb_port].initialized = KAL_TRUE;
	USB2UARTPort[usb_port].ownerid = ownerid;

	g_UsbACM[usb_port].send_Txilm = KAL_FALSE;
	g_UsbACM[usb_port].send_Rxilm = KAL_TRUE;

	usb_drv_trace1(USB2UARTPort[usb_port].ownerid, (kal_uint32)USBACM_OPEN, usb_port);
//	usb_drv_trace2(USB2UARTPort[usb_port].ownerid, (kal_uint32)USBACM_OPEN_READY_TO_READ_FLAG, (kal_uint32)ownerid, usb_port);


	g_UsbACM[usb_port].transfer_type = CDC_NORMAL;

	g_UsbACM[usb_port].config_send_Txilm = KAL_FALSE;
	g_UsbACM[usb_port].threshold_enable = KAL_FALSE;


	if(g_UsbACM[usb_port].ring_buffer_timer_counting == KAL_TRUE)
	{
		USB_GPTI_StopItem(g_UsbACM[usb_port].ring_buffer_handle);
//		DclSGPT_Control((DCL_HANDLE)(g_UsbACM[usb_port].ring_buffer_handle), SGPT_CMD_STOP, 0);
		g_UsbACM[usb_port].ring_buffer_timer_counting = KAL_FALSE;
	}

	if((g_UsbACM[usb_port].txpipe != NULL)&&(USB_Get_Device_State() == DEVSTATE_CONFIG))
	{
		/* Only RX EP needs to be enabled since TX EP will use DMA polling */
		USB_TxEPEn(g_UsbACM[usb_port].txpipe->byEP, USB_ENDPT_BULK, USB_EP_USE_ONLY_DMA, KAL_FALSE, KAL_FALSE);
		USB_RxEPEn(g_UsbACM[usb_port].rxpipe->byEP, USB_ENDPT_BULK, USB_EP_USE_NO_DMA, KAL_FALSE, KAL_FALSE);
		/* Open intr */
//		USB_Set_UnMask_Irq(KAL_TRUE);
		USB_UnMask_COM_Intr(port);

/*
		if(port == uart_port_usb)
			USB_UnMask_Irq(USB_MASK_OWNER_COM_1);
#if defined(__USB_MULTIPLE_COMPORT_SUPPORT__)
		else if(port == uart_port_usb2)
			USB_UnMask_Irq(USB_MASK_OWNER_COM_2);
		else if(port == uart_port_usb3)
			USB_UnMask_Irq(USB_MASK_OWNER_COM_3);
#endif
*/
		USB_Dbg_Trace(USB_ACM_USB2UART_EP_ENABLE, (kal_uint32)port, 0);
	}

	return KAL_TRUE;
}


/* Close USB2UART port */
static void USB2UART_close(UART_PORT port, module_type ownerid)
{
	kal_uint32 usb_port = USB_PORT[port];
//	kal_bool	result;

	usb_drv_trace2(ownerid, (kal_uint32)USBACM_CLOSE, (kal_uint32)ownerid, usb_port);

	USB_Check_Owner(ownerid,USB2UARTPort[usb_port].ownerid);

	g_UsbACM[usb_port].send_Txilm = KAL_FALSE;
	g_UsbACM[usb_port].config_send_Txilm = KAL_FALSE;
	USB2UARTPort[usb_port].initialized = KAL_FALSE;
	USB2UARTPort[usb_port].ownerid = MOD_DRV_HISR;
	g_UsbACM[usb_port].threshold_enable = KAL_FALSE;

	if((g_UsbACM[usb_port].txpipe != NULL)&&(USB_Get_Device_State() == DEVSTATE_CONFIG))
	{
		/* After assert or fatal error, TST will put many 0x00 to ring buffer, then UART_close and UART_open */
	        /* disable endpoint interrupt */

		USB_Stop_DMA_Channel(g_UsbACM[usb_port].txpipe->byEP, USB_EP_TX_DIR);

		USB_TxEPDis(g_UsbACM[usb_port].txpipe->byEP, USB_EP_USE_ONLY_DMA);
		USB_RxEPDis(g_UsbACM[usb_port].rxpipe->byEP, USB_EP_USE_NO_DMA);
		USB_Dbg_Trace(USB_ACM_USB2UART_EP_DISABLE, (kal_uint32)port, 0);
	}

	if(g_UsbACM[usb_port].ring_buffer_timer_counting == KAL_TRUE)
	{
		USB_GPTI_StopItem(g_UsbACM[usb_port].ring_buffer_handle);
//		DclSGPT_Control((DCL_HANDLE)(g_UsbACM[usb_port].ring_buffer_handle), SGPT_CMD_STOP, 0);
		g_UsbACM[usb_port].ring_buffer_timer_counting = KAL_FALSE;
	}

	g_UsbACM[usb_port].transfer_type = CDC_NORMAL;

	USB2UART_ConfigEscape(port, 0xFF, 0, MOD_DRV_HISR);
}


/* Clear RX buffer */
static void USB2UART_ClrRxBuffer(UART_PORT port, module_type ownerid)
{
	kal_uint32 usb_port = USB_PORT[port];
#if 0
/* under construction !*/
#endif

	USB_Check_Owner(ownerid,USB2UARTPort[usb_port].ownerid);

	usb_drv_trace1(ownerid, (kal_uint32)USBACM_CLEAR_RX_BUF, usb_port);
	USB_Dbg_Trace(USB_ACM_USB2UART_ClrRxBuffer, (kal_uint32)port, 0);
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if 0 	
/* under construction !*/
#else
/* under construction !*/
#endif
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
#else
	USB_Mask_USB_CORE((USB_MASK_OWNER) usb_port); //IRQMask(IRQ_USB_CODE);
	/* Clear ring buffer */
	USB2UARTPort[usb_port].Rx_Buffer.Write = 0;
	USB2UARTPort[usb_port].Rx_Buffer.Read = 0;
	g_UsbACM[usb_port].send_Rxilm = KAL_TRUE;

	/* Clear hardware FIFO if current status is CDC ACM */
    if(USB2UART_Check_Config(usb_port) == KAL_TRUE)
	{	
		/* Clear RX FIFO */
		USB_Acm_Rx_ClrFifo(port);
		/* Clear interrupt mask variable */
		/* Open intr */
//		USB_Set_UnMask_Irq(KAL_TRUE);
		USB_UnMask_COM_Intr(port);
	}
	if(USB_Get_UnMask_Irq() == KAL_TRUE)
		USB_UnMask_USB_CORE((USB_MASK_OWNER) usb_port); //IRQUnmask(IRQ_USB_CODE);

#endif
	usb_drv_trace2(ownerid, (kal_uint32)USBACM_CLEAR_RX_BUF_READY_TO_READ_FLAG, (kal_uint32)ownerid, usb_port);
}


/* Get available bytes in RX buffer */
static kal_uint16 USB2UART_GetRxAvail(UART_PORT port)
{
	kal_uint32 usb_port = USB_PORT[port];
	kal_uint16 real_count;
	kal_uint32 savedMask;


	savedMask = SaveAndSetIRQMask();
	Buf_GetBytesAvail(&(USB2UARTPort[usb_port].Rx_Buffer), real_count);
	RestoreIRQMask(savedMask);
	return real_count;
}

/* Get available bytes in RX buffer */
static kal_uint16 USB2UART_GetBufAvail(BUFFER_INFO *buf_info)
{
//	kal_uint32 usb_port = USB_PORT[port];
	kal_uint16 real_count;
	
	Buf_GetBytesAvail(buf_info, real_count);	
	
	return real_count;
}

/* Get bytes from RX buffer, parameter status shows escape and break status
     return value is the actually get bytes */
static kal_uint16 USB2UART_GetBytes(UART_PORT port, kal_uint8 *buffaddr, kal_uint16 length,
					kal_uint8 *status, module_type ownerid)
{
	kal_uint32 usb_port = USB_PORT[port];
	kal_uint16 real_count;
	kal_uint16 RoomLeft;
	kal_uint32 savedMask;
	kal_int32 remain;
	BUFFER_INFO *rx_buf_info = &(USB2UARTPort[usb_port].Rx_Buffer);


	USB_Check_Owner(ownerid,USB2UARTPort[usb_port].ownerid);


#ifdef  __USB_HIGH_SPEED_COM_PORT_ENABLE__
	if(g_UsbACM[usb_port].b_is_high_speed_enable == KAL_TRUE)
		ASSERT(0);
#endif

	/* Return directly if not match conditions */
	if(USB2UART_Check_Config(usb_port) == KAL_FALSE)
		return 0;

	/* Determine real data count */
	/* Note that the area to determine send_Rxilm must also contain in critical section.
	   Otherwise if USB HISR activated before send_Rxilm setting as true,
	   this message will be lost */
	savedMask = SaveAndSetIRQMask();
#if 0 
/* under construction !*/
#else
    real_count = USB2UART_GetBufAvail(rx_buf_info);
#endif
	if(real_count >= length)
	{
		real_count = length;
	}
	else
	{
		g_UsbACM[usb_port].send_Rxilm = KAL_TRUE;  /*After this time get byte, buffer will be empty */
	}

	RestoreIRQMask(savedMask);

	if(g_UsbACM[usb_port].send_Rxilm == KAL_TRUE)
		usb_drv_trace2(ownerid, (kal_uint32)USBACM_GET_BYTES_BUF_EMPTY, (kal_uint32)ownerid, usb_port);

	if(real_count != 0)
	{
		remain = (BRead(rx_buf_info) + real_count) - BLength(rx_buf_info);

		if(remain < 0)
		{
			/* dest, src, len */
			kal_mem_cpy(buffaddr, BuffRead(rx_buf_info), real_count);
			BRead(rx_buf_info) += real_count;
		}
		else
		{
			kal_mem_cpy(buffaddr, BuffRead(rx_buf_info), real_count-remain);
			kal_mem_cpy((kal_uint8 *)(buffaddr+real_count-remain), BStartAddr(rx_buf_info), remain);
			BRead(rx_buf_info) = remain;
		}
	}

	/* Update status */
	if (status != NULL)
	{
		*status = 0;

		if(USB2UARTPort[usb_port].EscFound)
		{
			*status |= UART_STAT_EscDet;
			USB2UARTPort[usb_port].EscFound = KAL_FALSE;
		}

		if(USB2UARTPort[usb_port].breakDet)
		{
			*status |= UART_STAT_Break;
			USB2UARTPort[usb_port].breakDet = KAL_FALSE;
		}
	}

	USB_Mask_USB_CORE((USB_MASK_OWNER) usb_port); //IRQMask(IRQ_USB_CODE);
#if 0	
/* under construction !*/
#else
		RoomLeft = USB2UART_GetBuffRoomLeft(rx_buf_info);
#endif

#ifdef __USB_HS_ENABLE__
	/* Only unmask IRQ if ring buffer room left >= MAX BULK PKT SIZE */
	if(((USB_Is_High_Speed() == KAL_TRUE)&&(RoomLeft >= USB_EP_BULK_MAXP_HS))
			||((USB_Is_High_Speed() == KAL_FALSE)&&(RoomLeft >= USB_EP_BULK_MAXP_FS)))
#else
	if(RoomLeft >= USB_EP_BULK_MAXP)
#endif
	{
//		USB_Set_UnMask_Irq(KAL_TRUE);
		USB_UnMask_COM_Intr(port);

/*
		if(port == uart_port_usb)
			USB_UnMask_Irq(USB_MASK_OWNER_COM_1);
	#if defined(__USB_MULTIPLE_COMPORT_SUPPORT__)
		else if(port == uart_port_usb2)
			USB_UnMask_Irq(USB_MASK_OWNER_COM_2);
		else if(port == uart_port_usb3)
			USB_UnMask_Irq(USB_MASK_OWNER_COM_3);
	#endif
*/
	}
		if(USB_Get_UnMask_Irq() == KAL_TRUE)
		USB_UnMask_USB_CORE((USB_MASK_OWNER) usb_port); //IRQUnmask(IRQ_USB_CODE);

	usb_drv_trace2(ownerid, (kal_uint32)USBACM_GET_BYTES, real_count, usb_port);

	return real_count;
}


/* Clear TX buffer */
static void USB2UART_ClrTxBuffer(UART_PORT port, module_type ownerid)
{
	kal_uint32 usb_port = USB_PORT[port];
	kal_uint32 savedMask;


	USB_Check_Owner(ownerid,USB2UARTPort[usb_port].ownerid);


	usb_drv_trace1(ownerid, (kal_uint32)USBACM_CLEAR_TX_BUF, usb_port);
	USB_Dbg_Trace(USB_ACM_USB2UART_ClrTxBuffer, (kal_uint32)port, 0);

	/* Stop DMA channel if current status is CDC ACM */
#if 0	
/* under construction !*/
#else
    if(USB2UART_Check_Config(usb_port) == KAL_TRUE)
#endif
	{
		USB_Stop_DMA_Channel(g_UsbACM[usb_port].txpipe->byEP, USB_EP_TX_DIR);
		g_UsbACM[usb_port].setup_dma = KAL_FALSE;
		if(g_UsbACM[usb_port].put_start == KAL_TRUE)
		{
		   g_UsbACM[usb_port].dmaf_setmember |= 0x20;
		}		
	}

	savedMask = SaveAndSetIRQMask();
	USB2UARTPort[usb_port].Tx_Buffer.Write = 0;
	USB2UARTPort[usb_port].Tx_Buffer.Read = 0;

#ifdef __USB_TETHERING__
	if (g_UsbACM[usb_port].halt_flag == KAL_TRUE)
	{
		// after halt, resume should not send Ready_to _write 
	}	
	else
#endif
	{
		g_UsbACM[usb_port].send_Txilm = KAL_TRUE;	
	}

	RestoreIRQMask(savedMask);

	usb_drv_trace2(ownerid, (kal_uint32)USBACM_CLEAR_TX_BUF_READY_TO_READ_FLAG, (kal_uint32)ownerid, usb_port);
}


/*Get the left bytes for buffer */
kal_uint16 USB2UART_GetBuffRoomLeft(BUFFER_INFO *buf_info)
{
	kal_uint16 real_count;
	Buf_GetRoomLeft(buf_info, real_count);
	return real_count;
}
/*Get the left bytes for TX buffer */
static kal_uint16 USB2UART_GetTxRoomLeft(UART_PORT port)
{
	kal_uint32 usb_port = USB_PORT[port];
	kal_uint16 real_count;
	kal_uint32  savedMask;


	savedMask = SaveAndSetIRQMask();
	real_count = USB2UART_GetBuffRoomLeft(&(USB2UARTPort[usb_port].Tx_Buffer));
	RestoreIRQMask(savedMask);
	return real_count;
}


/* Put bytes to tx buffer, return value is the actually put out bytes */
static kal_uint16 USB2UART_PutBytes(UART_PORT port, kal_uint8 *buffaddr, kal_uint16 length, module_type ownerid)
{
	kal_uint32 usb_port = USB_PORT[port];
	kal_uint16  real_count;
	kal_uint32  savedMask;
//	kal_uint8  ep_num = 0;
	kal_bool  setup_dma = KAL_FALSE;
	kal_int32 	remain;
	BUFFER_INFO 	*tx_info = &(USB2UARTPort[usb_port].Tx_Buffer);
#if defined(__DUAL_TALK_MODEM_SUPPORT__)	
	kal_bool  remote_wake = KAL_FALSE;
#endif

	USB_Check_Owner(ownerid,USB2UARTPort[usb_port].ownerid);


#ifdef  __USB_HIGH_SPEED_COM_PORT_ENABLE__
	if(g_UsbACM[usb_port].b_is_high_speed_enable == KAL_TRUE)
		ASSERT(0);
#endif

	USB_Dbg_Trace(USB_ACM_USB2UART_PutBytes, (kal_uint32)port, length);

	/* Return directly if not match condition */
	if(USB2UART_Check_Config(usb_port) == KAL_FALSE)
	{
		if((USB2UARTPort[usb_port].initialized == KAL_TRUE)&&(USB_Get_Device_State() != DEVSTATE_CONFIG))
		{
			g_UsbACM[usb_port].config_send_Txilm = KAL_TRUE;  /* for PC set config later then can issue the first message */
		}

		usb_drv_trace0(ownerid, (kal_uint32)USBACM_PUT_BYTES_FAIL);
		return 0;
	}

	/* The same issue as USB2UART_GetBytes()
	   The area to determine send_Txilm must also contain in critical section.
	   Otherwise if DMA callback activated before send_Txilm setting as true,
	   this message will be lost */
	savedMask = SaveAndSetIRQMask();
#if 0 
/* under construction !*/
#else
	real_count = USB2UART_GetBuffRoomLeft(tx_info);
#endif
	if((real_count == 0)&&(g_UsbACM[usb_port].dma_txcb_just_done == KAL_TRUE))
		ASSERT(0);

	g_UsbACM[usb_port].dma_txcb_just_done = KAL_FALSE;

	/* determine real sent data count */
	if (real_count > length)
	{
		real_count = length;
	}
	else
	{
		if((ownerid == MOD_MED) || (ownerid == MOD_L1SP))  // for audio
		{
			if(real_count != length)
			{
			  real_count = 0;
			}					  			
		}
		g_UsbACM[usb_port].send_Txilm = KAL_TRUE;  /*After this time put bytes, buffer will be full */
		g_UsbACM[usb_port].config_send_Txilm = KAL_TRUE; /* if be reseted, then it can issue the message waited for*/
	}
	RestoreIRQMask(savedMask);


	if(g_UsbACM[usb_port].send_Txilm == KAL_TRUE)
	{
		if((USB2UARTPort[usb_port].Tx_Buffer.Write != 0) &&(USB2UARTPort[usb_port].Tx_Buffer.Read != 0 ))
		{    // ClrTxBuffer (TXBuffer empty) will set  g_UsbACM.send_Txilm = T
			usb_drv_trace2(ownerid, (kal_uint32)USBACM_PUT_BYTES_BUF_FULL, (kal_uint32)ownerid, usb_port);
		}
	}

	if(real_count != 0)
	{
		remain = (BWrite(tx_info) + real_count) - BLength(tx_info);

		if(remain < 0)
		{
			/* dest, src, len */
			kal_mem_cpy(BuffWrite(tx_info), buffaddr, real_count);
			BWrite(tx_info) += real_count;
		}
		else
		{
			kal_mem_cpy(BuffWrite(tx_info), buffaddr, real_count-remain);
			kal_mem_cpy(BStartAddr(tx_info), (kal_uint8 *)(buffaddr+real_count-remain), remain);
			BWrite(tx_info) = remain;
		}
	}

	savedMask = SaveAndSetIRQMask();
	/* In case USB is plugged out just before this critical section */
	if(g_UsbACM[usb_port].txpipe != NULL)
	{
//		if(USB_DMA_Get_Run_Status(g_UsbACM[usb_port].txpipe->byEP, USB_EP_TX_DIR) == KAL_FALSE)
//		if USB2UART_PutISR just be called right here,DMA running flag hasn't set, that will cause DMA_Setup twice.So,we cannot remove setup_dma flag.

		if(g_UsbACM[usb_port].setup_dma == KAL_FALSE)
		{
			g_UsbACM[usb_port].setup_dma = KAL_TRUE;
			setup_dma = KAL_TRUE;
			g_UsbACM[usb_port].put_start = KAL_TRUE;
			g_UsbACM[usb_port].dmaf_setmember = 0;
//			ep_num = g_UsbACM[usb_port].txpipe->byEP;
		}
	}
	RestoreIRQMask(savedMask);

	usb_drv_trace2(ownerid, (kal_uint32)USBACM_PUT_BYTES, real_count, usb_port);

	if(setup_dma == KAL_TRUE)
	{
		USB_Dbg_Trace(USB_ACM_DMA_SETUP_1, (kal_uint32)port, 0);
		USB2UART_DMATransmit(port, KAL_FALSE);
	}
	g_UsbACM[usb_port].put_start = KAL_FALSE;
	g_UsbACM[usb_port].dmaf_setmember = 0;
#if defined(__DUAL_TALK_MODEM_SUPPORT__)	
		if((USB_Get_Device_State() == DEVSTATE_CONFIG) && (USB_Is_Suspend_Power_Status() == KAL_TRUE)
			&& ((g_UsbACM[usb_port].line_state & CONTROL_LINE_SIGNAL_DTR) == CONTROL_LINE_SIGNAL_DTR))
		{
		  savedMask = SaveAndSetIRQMask();
		  if(gUsbDevice.isRemoteWking == KAL_FALSE)
		  {
			remote_wake = KAL_TRUE;
			gUsbDevice.isRemoteWking = KAL_TRUE;		
		  }
		  RestoreIRQMask(savedMask);			  
		  if(remote_wake == KAL_TRUE)
		  {
			usb_drv_trace1(ownerid, (kal_uint32)USB_REMOTE_WAKEUP,1);	
   	        savedMask = SaveAndSetIRQMask();    
			USB_Lock_SleepMode();		
            RestoreIRQMask(savedMask); 			
			USB_Remote_Wake_UP_Start();
		  } 
	
		}	
#endif

	return real_count;
}



/* Get the left bytes for TX buffer */
static kal_uint16 USB2UART_GetTxISRRoomLeft(UART_PORT port)
{
	kal_uint32 usb_port = USB_PORT[port];
	kal_uint16 real_count;
	kal_uint32  savedMask;


	savedMask = SaveAndSetIRQMask();
#if 0 
/* under construction !*/
#else
	real_count = USB2UART_GetBuffRoomLeft(&(USB2UARTPort[usb_port].Tx_Buffer_ISR));
#endif	
	RestoreIRQMask(savedMask);
	return real_count;
}



/* Set owner for UART port */
static void USB2UART_setowner(UART_PORT port, module_type ownerid)
{
	kal_uint32 usb_port = USB_PORT[port];

	if(((USB_IS_LOGGING_PORT[port] == KAL_TRUE))||((g_UsbACM_Comm.acm_owner == USB_ACM_OWNER_FT)&&(USBDL_Mode_Type()== USBDL_MODE_NONE)))//(USBDL_Is_USB_Download_Mode() == KAL_FALSE)&&(USBDL_Is_USB_Fast_Meta_Mode()== KAL_FALSE)))
	{
		ASSERT(0);
	}

/*
#ifdef DRV_USB_PPP_BW_LIMIT  // MT6236 BW limitation :while using Dial up, USB should use INC4 transfer.
	if((ownerid == MOD_PPP)&&(custom_ifLPSDRAM() == KAL_FALSE))
	{
		USB_Set_DMA_Burst_Mode(DMA_MODE_INC4);
	}
	else
	{
		USB_Set_DMA_Burst_Mode(DMA_MODE_INC16);
	}
#endif
*/

	usb_drv_trace2(ownerid, (kal_uint32)USBACM_SET_OWNER, (kal_uint32)ownerid, usb_port);

	USB2UARTPort[usb_port].ownerid = ownerid;
}


/* Get current UART owner id */
static module_type USB2UART_GetOwnerID(UART_PORT port)
{
	kal_uint32 usb_port = USB_PORT[port];

	return USB2UARTPort[usb_port].ownerid;
}


/* Config escape character and guard time */
static void USB2UART_ConfigEscape(UART_PORT port, kal_uint8 EscChar, kal_uint16 ESCGuardtime, module_type ownerid)
{
	kal_uint32 usb_port = USB_PORT[port];
//	SGPT_CTRL_START_T start;


	USB_Check_Owner(ownerid,USB2UARTPort[usb_port].ownerid);


	USB2UARTPort[usb_port].ESCDet.EscChar = EscChar;
	USB2UARTPort[usb_port].ESCDet.GuardTime = ESCGuardtime;

	if(USB2UARTPort[usb_port].ESCDet.GuardTime != 0)
	{
		USB2UARTPort[usb_port].Rec_state = UART_RecNormal;

//		if((USB2UARTPort[usb_port].handle == 0)||(USB2UARTPort[usb_port].handle == 0x7F))
//		{
			//GPTI_GetHandle(&USB2UARTPort[usb_port].handle);
		USB_GPTI_GetHandle(&(USB2UARTPort[usb_port].handle));//DclSGPT_Open(DCL_GPT_CB, 0);
//		}

		USB_GPTI_StartItem(USB2UARTPort[usb_port].handle, (USB2UARTPort[usb_port].ESCDet.GuardTime/10), USB2UART_Timeout, &USB2UARTPort[usb_port]);
//		start.u2Tick = (USB2UARTPort[usb_port].ESCDet.GuardTime/10);
//		start.pfCallback = USB2UART_Timeout;
//		start.vPara = &USB2UARTPort[usb_port];
//		DclSGPT_Control((DCL_HANDLE)(USB2UARTPort[usb_port].handle), SGPT_CMD_START, (DCL_CTRL_DATA_T*)&start);
	}
}


static void USB2UART_SetDCBConfig(UART_PORT port, UARTDCBStruct *UART_Config, module_type ownerid)
{
	kal_uint32 usb_port = USB_PORT[port];

	USB_Check_Owner(ownerid,USB2UARTPort[usb_port].ownerid);
	kal_mem_cpy(&USB2UARTPort[usb_port].DCB, UART_Config, sizeof(UARTDCBStruct));
}

static void USB2UART_CtrlDCD(UART_PORT port, IO_LEVEL_T SDCD, module_type ownerid)
{
	kal_uint32 usb_port = USB_PORT[port];
	kal_uint32 savedMask;
	kal_bool  b_set_intr;
//	kal_uint8  ep_num = 0;
//	kal_uint32 max_intr_pkt_size;
#if defined(__DUAL_TALK_MODEM_SUPPORT__)	
	kal_bool  remote_wake = KAL_FALSE;
#endif	


//	USB_Dbg_Trace(USB_ACM_SEND_INTERRUPT, (kal_uint32)g_UsbACM[usb_port].intr_state, 0);

	USB_Check_Owner(ownerid,USB2UARTPort[usb_port].ownerid);

	usb_drv_trace1(ownerid, (kal_uint32)USBACM_CTRL_DCD, usb_port);

	USB_Dbg_Trace(USB_ACM_USB2UART_CtrlDCD, (kal_uint32)port, (kal_uint32)g_UsbACM[usb_port].intr_state);

	savedMask = SaveAndSetIRQMask();
	if((g_UsbACM[usb_port].intr_state == ACM_INTR_IDLE)&&(USB_Get_Device_State() == DEVSTATE_CONFIG))
	{
		b_set_intr = KAL_TRUE;
		g_UsbACM[usb_port].is_intr_pending_pkt = KAL_FALSE;
//		ep_num = g_UsbACM[usb_port].intrpipe->byEP;
	}
	else
	{
		b_set_intr = KAL_FALSE;
		g_UsbACM[usb_port].is_intr_pending_pkt = KAL_TRUE;
	}

	if(SDCD == (IO_LEVEL_T)io_high)
		g_UsbACM[usb_port].intr_pkt.Data = SERIAL_STATE_BRXCARRIER;
	else if (SDCD == (IO_LEVEL_T)io_low)
		g_UsbACM[usb_port].intr_pkt.Data = 0x00;
	else
		ASSERT(0);

	RestoreIRQMask(savedMask);

	if(b_set_intr == KAL_TRUE)
	{
		usb_drv_trace2(ownerid, (kal_uint32)USBACM_INTR, g_UsbACM[usb_port].intr_pkt.Data, usb_port);

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
	  #else
     	 USB2UART_Send_Intr_Pending(usb_port);
	  #endif
	}
#if defined(__DUAL_TALK_MODEM_SUPPORT__)	
    if((USB_Get_Device_State() == DEVSTATE_CONFIG) && (USB_Is_Suspend_Power_Status() == KAL_TRUE)
			&& ((g_UsbACM[usb_port].line_state & CONTROL_LINE_SIGNAL_DTR) == CONTROL_LINE_SIGNAL_DTR))		
    {
	  savedMask = SaveAndSetIRQMask();
	  if(gUsbDevice.isRemoteWking == KAL_FALSE)
	  {
	    remote_wake = KAL_TRUE;
        gUsbDevice.isRemoteWking = KAL_TRUE;		
	  }
      RestoreIRQMask(savedMask);    		  
	  if(remote_wake == KAL_TRUE)
	  {
		usb_drv_trace1(ownerid, (kal_uint32)USB_REMOTE_WAKEUP,1);	  
   	    savedMask = SaveAndSetIRQMask();    
		USB_Lock_SleepMode();		
        RestoreIRQMask(savedMask); 		
	    USB_Remote_Wake_UP_Start();
	  } 

    }	
#endif	
}

#ifdef __ECM_SUPPORT__
static kal_bool USB2UART_ECM_Notification(UART_PORT port,module_type ownerid,USB_ECM_type type,void *buffer)		
{
		kal_uint32 usb_port = USB_PORT[port];
		kal_uint32 max_intr_pkt_size;
		kal_uint32 intr_packet_size = 0;
		kal_bool		bEPEmpty;
		kal_uint32 	count = 0;		
		kal_uint8  ep_num = g_UsbACM[usb_port].intrpipe->byEP;	
		max_intr_pkt_size = USB_Intr_Max_Packet_Size();		
		
		USB_Check_Owner(ownerid,USB2UARTPort[usb_port].ownerid);
	
		usb_drv_trace1(ownerid, (kal_uint32)USB_ECM_CTRL_NOTIFY, usb_port);
	
		USB_Dbg_Trace(USB_ACM_USB2UART_CtrlDCD, (kal_uint32)port, (kal_uint32)g_UsbACM[usb_port].intr_state);
	
		if(type == CDC_NETWORK_CONNECTION)
		{
			g_UsbACM[usb_port].notify_pkt.bNotificationCode = ECM_NETWORK_CONNECTION;
			g_UsbACM[usb_port].notify_pkt.wValue = *(kal_uint16 *)buffer;
			g_UsbACM[usb_port].notify_pkt.wLength = 0;
			intr_packet_size = 8;		
		}
		else if (type == CDC_RESPONSE_AVAILABLE)
		{
			g_UsbACM[usb_port].notify_pkt.bNotificationCode = ECM_RESPONSE_AVAILABLE;
			g_UsbACM[usb_port].notify_pkt.wValue = 0;
			g_UsbACM[usb_port].notify_pkt.wLength = 0;
			intr_packet_size = 8;			
		}
		else if (type == CDC_CONNECTION_SPEED_CHANGE)
		{
			g_UsbACM[usb_port].notify_pkt.bNotificationCode = ECM_CONNECYION_SPEED_CHANGE;
			g_UsbACM[usb_port].notify_pkt.wValue = 0;
			g_UsbACM[usb_port].notify_pkt.wLength = 8;
			g_UsbACM[usb_port].notify_pkt.Data[0] = 0x00;	
			g_UsbACM[usb_port].notify_pkt.Data[1] = 0x00;
			g_UsbACM[usb_port].notify_pkt.Data[2] = 0x64;
			g_UsbACM[usb_port].notify_pkt.Data[3] = 0x19;			
			g_UsbACM[usb_port].notify_pkt.Data[4] = 0x00;	
			g_UsbACM[usb_port].notify_pkt.Data[5] = 0x00;
			g_UsbACM[usb_port].notify_pkt.Data[6] = 0x64;
			g_UsbACM[usb_port].notify_pkt.Data[7] = 0x19;													
			intr_packet_size = 16;				
		}
		else	
		{	
			ASSERT(0);
		}
		
		if(USB_Is_EP_Tx_Empty(ep_num, USB_ENDPT_BULK) == KAL_FALSE)
		{
			return KAL_FALSE;
		}
		
		
			usb_drv_trace2(ownerid, (kal_uint32)USBACM_INTR, g_UsbACM[usb_port].intr_pkt.Data, usb_port);	
			
			if(max_intr_pkt_size > intr_packet_size)
			{
				g_UsbACM[usb_port].intr_state = ACM_INTR_SEND_LAST_PKT;
			
				/* Send only one short packet */
				USB_Dbg_Trace(USB_ACM_SEND_INTERRUPT2, (kal_uint32)g_UsbACM[usb_port].intr_state, 0);
				USB_EPFIFOWrite(ep_num, intr_packet_size, (kal_uint8 *)&g_UsbACM[usb_port].notify_pkt);  
		}
		else
		{
			ASSERT(0);
		}
		
		USB_EP_Tx_Ready(ep_num, USB_ENDPT_INTR); 

		bEPEmpty = USB_Is_EP_Tx_Empty(ep_num, USB_ENDPT_BULK);

		while((bEPEmpty == KAL_FALSE)&&(count != 10)&&(USB_Get_Device_State() == DEVSTATE_CONFIG))
		{
			count++;
			kal_sleep_task(1);
			bEPEmpty = USB_Is_EP_Tx_Empty(ep_num, USB_ENDPT_BULK);
		}
		
		return KAL_TRUE;
			
 }
#endif

static void USB2UART_Register_TX_Callback(UART_PORT port, module_type ownerid, UART_TX_FUNC func)
{
	kal_uint32 usb_port = USB_PORT[port];

	USB_Check_Owner(ownerid,USB2UARTPort[usb_port].ownerid);

	USB2UARTPort[usb_port].tx_cb = func;
}


static void USB2UART_Register_RX_Callback(UART_PORT port, module_type ownerid, UART_RX_FUNC func)
{
	kal_uint32 usb_port = USB_PORT[port];

	USB_Check_Owner(ownerid,USB2UARTPort[usb_port].ownerid);

	USB2UARTPort[usb_port].rx_cb = func;
}

#if defined(__USB_MODEM_CARD_SUPPORT__)	
static void USB_ReConn_In_Exception(UART_PORT port)
{
	drvusb_usbcfg_req_struct usbcfg;
	static kal_uint32 usb_assert_Enter = 0;
	kal_uint32 prev_time;

	//if(usb_assert_Enter == 0)
	if((usb_assert_Enter == 0) && (USBDL_Mode_Type()== USBDL_MODE_NONE))	
	{
		usb_assert_Enter = 1;
		USB_Release_Type(KAL_TRUE, KAL_TRUE);	
		USB_Composite_Device_Table_Reset();
		
#if defined(__MBIM_SUPPORT__)||defined(__ECM_SUPPORT__)
		if(g_UsbMode.usb_comport_driver == USB_COMPORT_WIN)
		{
		USB_Composite_Device_Table_Register(USB_COMP_MBIM);
			usbcfg.product_code = g_UsbACM_Comm.acm_param->desc_mbim_4vcom_product;
			usbcfg.device_code = USB_COMPOSITE_DEVICE_CODE;
			usbcfg.subclass_code = USB_COMPOSITE_SUBCLASS_CODE;
			usbcfg.protocol_code = USB_COMPOSITE_PROTOCOL_CODE;			
			
		}
		else
		{
			USB_Composite_Device_Table_Register(USB_COMP_ECM);
			usbcfg.product_code = g_UsbACM_Comm.acm_param->desc_ecm_4vcom_product;		
			usbcfg.device_code = USB_MAC_COMPOSITE_DEVICE_CODE;
			usbcfg.subclass_code = USB_MAC_COMPOSITE_SUBCLASS_CODE;
			usbcfg.protocol_code = USB_MAC_COMPOSITE_PROTOCOL_CODE;			
		}
		
		USB_Composite_Device_Table_Register(USB_COMP_SI_CDC_ACM2);
		USB_Composite_Device_Table_Register(USB_COMP_REDUCED_CDC_ACM3);
		USB_Composite_Device_Table_Register(USB_COMP_REDUCED_CDC_ACM4); 
		USB_Composite_Device_Table_Register(USB_COMP_REDUCED_CDC_ACM5);

		usbcfg.mode = USB_COMPOSITE_DEVICES; 
		usbcfg.parameter = (kal_uint32 *) &usbcfg;
				
#else
		//5VCOM
		USB_Composite_Device_Table_Register(USB_COMP_SI_CDC_ACM);
		USB_Composite_Device_Table_Register(USB_COMP_SI_CDC_ACM2);
		USB_Composite_Device_Table_Register(USB_COMP_REDUCED_CDC_ACM3);
		USB_Composite_Device_Table_Register(USB_COMP_REDUCED_CDC_ACM4);
		USB_Composite_Device_Table_Register(USB_COMP_REDUCED_CDC_ACM5);
		usbcfg.mode = USB_COMPOSITE_DEVICES; 
		usbcfg.parameter = (kal_uint32 *) &usbcfg;
		usbcfg.device_code = USB_COMPOSITE_NO_IAD_DEVICE_CODE;
		usbcfg.subclass_code = USB_COMPOSITE_NO_IAD_SUBCLASS_CODE;
		usbcfg.protocol_code = USB_COMPOSITE_NO_IAD_PROTOCOL_CODE;
		usbcfg.product_code = g_UsbACM_Comm.acm_param->desc_5vcom_product;	
#endif		
		USB_Config_Type(USB_COMPOSITE_DEVICES, KAL_TRUE, (kal_uint32 *) &usbcfg);		

		while(USB_Get_Device_State() != DEVSTATE_CONFIG)
		{
			USB2UART_Polling_Recv_Data(port);
		}	
		prev_time = drv_get_current_time();
		
		while(drv_get_duration_ms(prev_time) < 1500)
		{
			USB2UART_Polling_Recv_Data(port);
		}			
	}
}
#endif

/* This function is only used for retrive exception log*/
static kal_uint8 USB2UART_GetUARTByte(UART_PORT port)
{
	kal_uint32 usb_port = USB_PORT[port];
	kal_uint32 real_count = 0;
//	kal_uint32 RoomLeft = 0;
	kal_uint8 data;
#if !defined(__USB_MODEM_CARD_SUPPORT__)	
	volatile kal_uint32 delay;
#endif
	BUFFER_INFO *rx_buf_info = &(USB2UARTPort[usb_port].Rx_Buffer);


	/* This function can only be called after exception*/
	USB_Acm_Exception_Check();

//	USB_Dbg_Trace(USB_ACM_USB2UART_GetUARTByte, (kal_uint32)port, 0);

#if defined(__USB_MODEM_CARD_SUPPORT__)	
	USB_ReConn_In_Exception(port); /* when modem card assert, we will reconnect except mass storage */
#else
	if(!((g_UsbACM[usb_port].txpipe != NULL)&&(USB_Get_Device_State() == DEVSTATE_CONFIG)))
	{
		/* This function should only be called when assertion,
		 *if not CDC_ACM type, re-enumeration to CDC ACM*/
		USB_Release_Type(KAL_TRUE, KAL_TRUE);
		
		for (delay = 0; delay < 255; delay++);

#if defined(__USB_MULTIPLE_COMPORT_SUPPORT__)
		if(g_UsbMode.usb_comport_boot >= USB_BOOT_TWO_PORT)
		{
			USB_Config_Type(USB_COMPOSITE_MULTI_COM, KAL_TRUE, NULL);
		}
		else
#endif
		{
			USB_Config_Type(USB_CDC_ACM, KAL_TRUE, NULL);
		}

		while(USB_Get_Device_State() != DEVSTATE_CONFIG)
		{
			USB2UART_Polling_Recv_Data(port);
		}
	}
#endif

#if 0 
/* under construction !*/
#else
    real_count = USB2UART_GetBufAvail(rx_buf_info);
#endif
	while(real_count == 0)
	{
		/* Polling to receive data */
		USB2UART_Polling_Recv_Data(port);
        #if 0 
/* under construction !*/
        #else
            real_count = USB2UART_GetBufAvail(rx_buf_info);
        #endif		
	}

	Buf_Pop(&(USB2UARTPort[usb_port].Rx_Buffer), data);   /* one byte at a time */

	/* ASSERT will close I bit, so there is no need to do the following code */
	/* Set unmask flag if room left is larger than USB_EP_BULK_MAXP */
//	Buf_GetRoomLeft(&(USB2UARTPort[usb_port].Rx_Buffer), RoomLeft);

	/* Only unmask IRQ if ring buffer romm left >= MAX BULK PKt SIZE */
/*
#ifdef __USB_HS_ENABLE__
	if(USB_Is_High_Speed() == KAL_TRUE)
	{
		if(RoomLeft >= USB_EP_BULK_MAXP_HS)
		{
			USB_Set_UnMask_Irq(KAL_TRUE);
		}
	}
	else
	{
		if(RoomLeft >= USB_EP_BULK_MAXP_FS)
		{
			USB_Set_UnMask_Irq(KAL_TRUE);
		}
	}
#else
	if(RoomLeft >= USB_EP_BULK_MAXP)
	{
		USB_Set_UnMask_Irq(KAL_TRUE);
	}
#endif
*/
	return data;
}



/* This function is only used for retrive exception log*/
static void USB2UART_Put_Exp_Data(UART_PORT port, kal_uint8 *Buffaddr, kal_uint16 Length)
{
	kal_uint32 usb_port = USB_PORT[port];
	kal_uint32 index;
	kal_uint16 data_length = 0;
	kal_uint16 offset = 0;


	/* This function can only be called after exception*/
	USB_Acm_Exception_Check();

//	USB_Dbg_Trace(USB_ACM_USB2UART_PutUARTBytes, (kal_uint32)port, 0);

		/* This function should only be called when assertion, if not CDC_ACM type, return it directly*/
	if(USB2UART_Check_Config(usb_port) == KAL_FALSE)
		return;

	#if defined(__USB_MODEM_CARD_SUPPORT__)	
		USB_ReConn_In_Exception(port); /* when modem card assert, we will reconnect except mass storage */
	#endif
	
	/* Flush previous data first*/
	USB2UART_Polling_Flush_Transmit_Data(port);

	/* If data length is larger than TX ring buffer, seperate to send as seceral times*/
	do
	{
		if((Length - offset) > USB2UARTPort[usb_port].Tx_Buffer.Length)
		{
			data_length = USB2UARTPort[usb_port].Tx_Buffer.Length;
		}
		else
		{
			data_length = Length - offset;
		}

		/* put data to tx queue*/
		/* push data from caller buffer to ring buffer */
		for (index = 0; index < data_length; index++)
		{
			Buf_Push(&(USB2UARTPort[usb_port].Tx_Buffer), *(Buffaddr+offset+index));
		}

		offset += data_length;

		/* Flush the tx queue */
		USB2UART_Polling_Flush_Transmit_Data(port);
	}while(offset < Length);
}


static void USB2UART_ReadDCBConfig(UART_PORT port, UARTDCBStruct *DCB)
{
	kal_uint32 usb_port = USB_PORT[port];

	kal_mem_cpy(DCB, &USB2UARTPort[usb_port].DCB, sizeof(UARTDCBStruct));
}


static void USB2UART_ReadHWStatus(UART_PORT port, IO_LEVEL_T *SDSR, IO_LEVEL_T *SCTS)
{
	kal_uint32 usb_port = USB_PORT[port];

	*SDSR = (IO_LEVEL_T)g_UsbACM[usb_port].line_state & 0x1;
	*SCTS = (IO_LEVEL_T)(g_UsbACM[usb_port].line_state >> 1) & 0x1;
}


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
#if 0 	
/* under construction !*/
#else
/* under construction !*/
#endif		
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
#if 0	
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if 0 			
/* under construction !*/
#else
/* under construction !*/
#endif					
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
#else
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
/* under construction !*/
#else
/* under construction !*/
#endif
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
#else
static kal_uint16 USB2UART_Send_ISRData(UART_PORT port, kal_uint8 *buffaddr, kal_uint16 length,module_type ownerid)
{
	kal_uint32 usb_port = USB_PORT[port];
	kal_uint16	real_count;
//	kal_uint16	index;
//	kal_uint8  data;
	kal_uint32  savedMask;
//	kal_uint8  ep_num = 0;
//	kal_uint16 roomleft;
	kal_bool  setup_dma = KAL_FALSE;
	kal_int32 	remain;
	BUFFER_INFO 	*tx_isr_info = &(USB2UARTPort[usb_port].Tx_Buffer_ISR);


	USB_Check_Owner(ownerid,USB2UARTPort[usb_port].ownerid);

	if(USB2UART_Check_Config(usb_port) == KAL_FALSE)
		return 0;

//	if((USB_Get_Device_Type()!= USB_CDC_ACM)&&(USB_Get_Device_Type()!= USB_COMPOSITE_MULTI_COM)
//	      &&(USB_Get_Device_Type()!= USB_COMPOSITE_RNDIS_COM)&&(USB_Get_Device_Type()!= USB_COMPOSITE_VIDEO_COM))
	if((USB_Get_Device_Type()!= USB_CDC_ACM)&&(USB_Check_Composite_With_COM(USB_Get_Device_Type())!= KAL_TRUE))
		return 0; 
		
	savedMask = SaveAndSetIRQMask();
#if 0 	
/* under construction !*/
#else
	real_count = USB2UART_GetBuffRoomLeft(tx_isr_info);
#endif		
	RestoreIRQMask(savedMask);

	/* determine real sent data count */
	if (real_count > length)
		real_count = length;

	/* Put bytes to ISR tx buffer, return value is the actually put out bytes */
		USB_Dbg_Trace(USB_ACM_USB2UART_PutISRBytes, (kal_uint32)port, length);
	if(real_count != 0)
	{
		remain = (BWrite(tx_isr_info) + real_count) - BLength(tx_isr_info);

		if(remain < 0)
		{
			/* dest, src, len */
			kal_mem_cpy(BuffWrite(tx_isr_info), buffaddr, real_count);
			BWrite(tx_isr_info) += real_count;
		}
		else
		{
			kal_mem_cpy(BuffWrite(tx_isr_info), buffaddr, real_count-remain);
			kal_mem_cpy(BStartAddr(tx_isr_info), (kal_uint8 *)(buffaddr+real_count-remain), remain);
			BWrite(tx_isr_info) = remain;
		}
	}

	savedMask = SaveAndSetIRQMask();
	/* in case usb is plugged out just before this critical section */
	if(g_UsbACM[usb_port].txpipe != NULL)
	{
//		if(USB_DMA_Get_Run_Status(g_UsbACM.txpipe->byEP,USB_EP_TX_DIR) == KAL_FALSE)
		if(g_UsbACM[usb_port].setup_dma == KAL_FALSE)
		{
			g_UsbACM[usb_port].setup_dma = KAL_TRUE;
			setup_dma = KAL_TRUE;
//			ep_num = g_UsbACM[usb_port].txpipe->byEP;
		}
	}
	RestoreIRQMask(savedMask);


	if(setup_dma == KAL_TRUE)
	{
		USB_Dbg_Trace(USB_ACM_DMA_SETUP_2, (kal_uint32)port, 0);
		USB2UART_DMATransmit(port, KAL_FALSE);
	}

	return real_count;

}

#endif

#ifdef  __USB_HIGH_SPEED_COM_PORT_ENABLE__
static void USB_High_Speed_En_Check (kal_uint32 usb_port)
{

	if( g_UsbACM[usb_port].b_is_high_speed_enable == KAL_FALSE )
		ASSERT(0);
}
#endif


#if defined(__USB_TETHERING__)||defined(__MBIM_SUPPORT__)||defined(__ECM_SUPPORT__)

static void USB_RNDIS_Response(kal_uint32 usb_port)
{
	kal_uint32 savedMask;
	kal_bool  b_set_intr;
	kal_uint8  ep_num = 0;
//	kal_uint32 max_intr_pkt_size;

	USB_Dbg_Trace(USB_ACM_USB2UART_RNDIS_Intr, 0, (kal_uint32)g_UsbACM[usb_port].intr_state);

	savedMask = SaveAndSetIRQMask();
	if((g_UsbACM[usb_port].intr_state == ACM_INTR_IDLE)&&(USB_Get_Device_State() == DEVSTATE_CONFIG))
	{
		b_set_intr = KAL_TRUE;
		g_UsbACM[usb_port].is_intr_pending_pkt = KAL_FALSE;
		ep_num = g_UsbACM[usb_port].intrpipe->byEP;
	}
	else
	{
		b_set_intr = KAL_FALSE;
		g_UsbACM[usb_port].is_intr_pending_pkt = KAL_TRUE;
	}
	RestoreIRQMask(savedMask);


	if(b_set_intr == KAL_TRUE)
	{
//		max_intr_pkt_size = USB_EP_INTR_MAXP;

		g_UsbACM[usb_port].intr_state = ACM_INTR_SEND_LAST_PKT;

		/* Send only one short packet */
		USB_Dbg_Trace(USB_ACM_USB2UART_RNDIS_Intr, 1,(kal_uint32)g_UsbACM[usb_port].intr_state);
		
		usb_drv_trace2(USB2UARTPort[usb_port].ownerid, (kal_uint32)USBACM_INTR, 8, usb_port);

		USB_EPFIFOWrite(ep_num, 8, (kal_uint8 *)&g_UsbACM[usb_port].intr_pkt);

		USB_EP_Tx_Ready(ep_num, USB_ENDPT_BULK);
	}

}



static kal_uint16 USB_CTRLPutBytes(UART_PORT port, kal_uint8 *buffaddr, kal_uint16 length, module_type ownerid)
{
	kal_uint32 usb_port = USB_PORT[port];
	kal_uint16 return_length = length;
	kal_uint32 delay_count = 0;
	kal_uint32 savedMask;
	kal_bool send_ilm = KAL_FALSE;


	USB_Check_Owner(ownerid,USB2UARTPort[usb_port].ownerid);
	
	USB_High_Speed_En_Check(usb_port);	
	
	if(length == 0)
		ASSERT(0);	
	
// if Device cannot response PC Send_encpasulated commend  --> send 0x00 instead of STALL
	if (length == 1)   
		USB_Dbg_Trace(USB_ACM_USB2UART_RNDIS_Error, 0,usb_port);


	USB_Dbg_Trace(USB_ACM_EP0_PUTBYTES, (kal_uint32)port, length);
	usb_drv_trace2(ownerid, (kal_uint32)USBACM_FLC_HIGHSPEED_PUTBYTES, length, usb_port);
	
	
	if ((USB_Is_Suspend_Power_Status() == KAL_TRUE)&&(gUsbDevice.remoteWk == KAL_TRUE))
	{
		DclUSB_DRV_Control(g_USB_Dcl_Handle, USB_DRV_CMD_REMOTE_WAKEUP, NULL);
	}


// Control pipe : 1. use interrupt pipe send notice signal
// 		            2. EP0 handler TX

	/* In case USB is plugged out just before this critical section */
	while((delay_count != 100)&&(USB_Get_Endpoint0_State() != USB_EP0_IDLE))
	{
		delay_count++;
		kal_sleep_task(1);
	}
	
// EP0 handler doesn't come back to idle state (EP0 transfering)
// Last EP0 data has not sent out
	savedMask = SaveAndSetIRQMask();
	if((USB_Get_Endpoint0_State() != USB_EP0_IDLE)||(g_UsbACM[usb_port].ctrl_data_done != KAL_TRUE))  
	{
		if(g_UsbACM[usb_port].ctrl_data_done == KAL_TRUE)
		{
			/* EP0 sent large data, thus it stays in USB_EP0_TX state after sent the first packet.
			 * In this case, EP0 class_specific_hdlr won't sent message.
			 */
			send_ilm = KAL_TRUE;
		}
		USB_Dbg_Trace(USB_ACM_USB2UART_RNDIS_Busy, 0, (kal_uint32)USB_Get_Endpoint0_State());
		g_UsbACM[usb_port].send_ctrl_Txilm = KAL_TRUE;  // previous data hasn't sent out
		return_length = 0;
	}
	RestoreIRQMask(savedMask);	
	
	if (send_ilm == KAL_TRUE)
	{
		USB2UART_Sendilm(uart_port_usb, MSG_ID_CTRL_UART_READY_TO_WRITE_IND);
	}
	
	if (return_length > 0)
	{
		g_UsbACM[usb_port].tx_flc_count = length ;
		g_UsbACM[usb_port].tx_flc_data_addr = buffaddr;
		g_UsbACM[usb_port].ctrl_data_done = KAL_FALSE;
		USB_RNDIS_Response(usb_port);	// use Interrupt pipe notice Host there is data to transfer 
	}
	else
	{
		usb_drv_trace0(ownerid, (kal_uint32)USBACM_FLC_HIGHSPEED_PUTBYTES_BUSY);
	}
	
	return return_length;
	
}



static kal_uint16 USB_CTRLGetFrame(UART_PORT port, kal_uint8 **buffaddr, module_type ownerid, USB_Requ_type type)
{
	kal_uint32 usb_port = USB_PORT[port];
	kal_uint16 real_count;
//	kal_bool buf_empty = KAL_FALSE;
	kal_uint32 savedMask;

// Debug
	kal_uint8 temp[4];
	kal_uint8 index;

	USB_Check_Owner(ownerid,USB2UARTPort[usb_port].ownerid);

	USB_High_Speed_En_Check(usb_port);	
	
	if ((type == CDC_ONLY_PUSH)||(type == CDC_GET_DATA))
	{
		if (*buffaddr == NULL)
			ASSERT(0);

		if( g_UsbACM[usb_port].rx_flc_buf_count > RNDIS_RX_FLC_BUFFER_NUM)
			ASSERT(0);
					
		if (g_UsbACM[usb_port].rx_flc_buf_addr[g_UsbACM[usb_port].rx_flc_empty_buff_index] != NULL)
			ASSERT(0);

		usb_drv_trace1(ownerid, (kal_uint32)USBACM_RX_FLC_PUSH, g_UsbACM[usb_port].rx_flc_empty_buff_index);

		savedMask = SaveAndSetIRQMask();

		g_UsbACM[usb_port].rx_flc_buf_addr[g_UsbACM[usb_port].rx_flc_empty_buff_index]= *buffaddr;

		g_UsbACM[usb_port].rx_flc_buf_count++;

		g_UsbACM[usb_port].rx_flc_empty_buff_index ++;
		
		if (g_UsbACM[usb_port].rx_flc_empty_buff_index == (RNDIS_RX_FLC_BUFFER_NUM+1))  // 0~ N-1
			g_UsbACM[usb_port].rx_flc_empty_buff_index = 0;	

		RestoreIRQMask(savedMask);

	}

	

	if (type == CDC_ONLY_PUSH)
	{
// because PC has already send data ,  FIFO read when UPS put data.
		if((g_UsbACM[usb_port].rx_flc_temp_length != 0) &&(g_UsbACM[usb_port].rx_flc_temp == KAL_TRUE))
		{
				kal_mem_cpy(g_UsbACM[usb_port].rx_flc_buf_addr[g_UsbACM[usb_port].rx_flc_buf_w_index], g_UsbACM[usb_port].rx_flc_temp_buf_addr, g_UsbACM[usb_port].rx_flc_temp_length);

// check frame header
				for (index=0; index<2; index++)
				{					
					temp[0] = *(g_UsbACM[usb_port].rx_flc_buf_addr[g_UsbACM[usb_port].rx_flc_buf_w_index]+(index*4));
					temp[1] = *(g_UsbACM[usb_port].rx_flc_buf_addr[g_UsbACM[usb_port].rx_flc_buf_w_index]+(index*4)+0x01);
					temp[2] = *(g_UsbACM[usb_port].rx_flc_buf_addr[g_UsbACM[usb_port].rx_flc_buf_w_index]+(index*4)+0x02);
					temp[3] = *(g_UsbACM[usb_port].rx_flc_buf_addr[g_UsbACM[usb_port].rx_flc_buf_w_index]+(index*4)+0x03);
															
					usb_drv_trace4(ownerid, (kal_uint32)USBACM_RX_FLC_DATA_HEADER,temp[0],temp[1],temp[2],temp[3]);
				}

				g_UsbACM[usb_port].rx_flc_buf_data_len[g_UsbACM[usb_port].rx_flc_buf_w_index] = g_UsbACM[usb_port].rx_flc_temp_length;	
				g_UsbACM[usb_port].rx_flc_temp_length = 0;
				g_UsbACM[usb_port].rx_flc_temp = KAL_FALSE;

				g_UsbACM[usb_port].rx_flc_buf_w_index++;  // update write pointer  --> first command

				if(g_UsbACM[usb_port].rx_flc_buf_w_index == (RNDIS_RX_FLC_BUFFER_NUM+1))
					g_UsbACM[usb_port].rx_flc_buf_w_index = 0;
		
				if(g_UsbACM[usb_port].send_ctrl_Rxilm == KAL_TRUE)
				{
					g_UsbACM[usb_port].send_ctrl_Rxilm = KAL_FALSE;		
					USB2UART_Sendilm(uart_port_usb, MSG_ID_CTRL_UART_READY_TO_READ_IND);
				}
				
		}

		return 0;
		
	}
	else if (type == CDC_POP_BUFF)
	{
		if (g_UsbACM[usb_port].rx_flc_buf_r_index != g_UsbACM[usb_port].rx_flc_empty_buff_index)
		{
			usb_drv_trace1(ownerid, (kal_uint32)USBACM_RX_FLC_POP, g_UsbACM[usb_port].rx_flc_buf_r_index);
		
			*buffaddr = g_UsbACM[usb_port].rx_flc_buf_addr[g_UsbACM[usb_port].rx_flc_buf_r_index];
			 g_UsbACM[usb_port].rx_flc_buf_addr[g_UsbACM[usb_port].rx_flc_buf_r_index] = NULL;

			g_UsbACM[usb_port].rx_flc_buf_r_index ++;
			g_UsbACM[usb_port].rx_flc_buf_count --;

			if (g_UsbACM[usb_port].rx_flc_buf_r_index == (RNDIS_RX_FLC_BUFFER_NUM+1))
				g_UsbACM[usb_port].rx_flc_buf_r_index = 0;
		}
		else
			*buffaddr = NULL;
			
		return 0;
	}
	else 
	{
		
//		IRQMask(IRQ_USB_CODE);
	
		/* Move read clear pointer */
//		if(g_UsbACM[usb_port].b_flc_rc_index_move == KAL_TRUE)
//		{
//			g_UsbACM[usb_port].b_flc_rc_index_move = KAL_FALSE;
	
//			if(g_UsbACM[usb_port].rx_flc_buf_data_len[g_UsbACM[usb_port].rx_flc_buf_rc_index] != 0)
//				ASSERT(0);

//			g_UsbACM[usb_port].rx_flc_buf_rc_index++;
	
//			if(g_UsbACM[usb_port].rx_flc_buf_rc_index == (RNDIS_RX_FLC_BUFFER_NUM+1))
//				g_UsbACM[usb_port].rx_flc_buf_rc_index = 0;
	
//			USB_Dbg_Trace(USB_ACM_EP0_MOVE_RC_INDEX, g_UsbACM[usb_port].rx_flc_buf_rc_index, 0);
//			drv_trace4(TRACE_GROUP_1, (kal_uint32)USBACM_FLC_MOVE_RC_INDEX, g_UsbACM[usb_port].rx_flc_buf_w_index, g_UsbACM[usb_port].rx_flc_buf_count, g_UsbACM[usb_port].rx_flc_buf_rc_index, g_UsbACM[usb_port].rx_flc_buf_r_index);
	
			/* UnmaskIRQ */
//			if(port == uart_port_usb)
//				USB_UnMask_Irq(USB_MASK_OWNER_COM_1);
//		}
	
	
		/* Move read pointer */
		/* Determine real data count */
		if(g_UsbACM[usb_port].rx_flc_buf_data_len[g_UsbACM[usb_port].rx_flc_buf_r_index] != 0)
		{

			if(g_UsbACM[usb_port].rx_flc_buf_count == 0)
				ASSERT(0);
			
			savedMask = SaveAndSetIRQMask();
			
			g_UsbACM[usb_port].rx_flc_buf_count--;
		
//			g_UsbACM[usb_port].b_flc_rc_index_move = KAL_TRUE;
			*buffaddr = g_UsbACM[usb_port].rx_flc_buf_addr[g_UsbACM[usb_port].rx_flc_buf_r_index];
			real_count = g_UsbACM[usb_port].rx_flc_buf_data_len[g_UsbACM[usb_port].rx_flc_buf_r_index];

			RestoreIRQMask(savedMask);

			for (index=0; index<2; index++)
			{					
				temp[0] = *(g_UsbACM[usb_port].rx_flc_buf_addr[g_UsbACM[usb_port].rx_flc_buf_r_index]+(index*4));
				temp[1] = *(g_UsbACM[usb_port].rx_flc_buf_addr[g_UsbACM[usb_port].rx_flc_buf_r_index]+(index*4)+0x01);
				temp[2] = *(g_UsbACM[usb_port].rx_flc_buf_addr[g_UsbACM[usb_port].rx_flc_buf_r_index]+(index*4)+0x02);
				temp[3] = *(g_UsbACM[usb_port].rx_flc_buf_addr[g_UsbACM[usb_port].rx_flc_buf_r_index]+(index*4)+0x03);
														
				usb_drv_trace4(ownerid, (kal_uint32)USBACM_RX_FLC_DATA_HEADER,temp[0],temp[1],temp[2],temp[3]);
			}
			

			savedMask = SaveAndSetIRQMask();
						
			g_UsbACM[usb_port].rx_flc_buf_data_len[g_UsbACM[usb_port].rx_flc_buf_r_index] = 0;
			g_UsbACM[usb_port].rx_flc_buf_addr[g_UsbACM[usb_port].rx_flc_buf_r_index] = NULL;
	
			g_UsbACM[usb_port].rx_flc_buf_r_index++;
	
			if(g_UsbACM[usb_port].rx_flc_buf_r_index == (RNDIS_RX_FLC_BUFFER_NUM+1))
				g_UsbACM[usb_port].rx_flc_buf_r_index = 0;

			RestoreIRQMask(savedMask);
				
			/* Move write pointer index only when current buffer receive 512*N, and write index does not move to next buffer, but PPP already receives this buffer */
			/* Check if it needs to move write index */
			if(g_UsbACM[usb_port].rx_flc_buf_addr[g_UsbACM[usb_port].rx_flc_buf_w_index]== NULL)
			{
//				buf_empty = KAL_TRUE;
				usb_drv_trace1(ownerid, (kal_uint32)USBACM_RX_FLC_NO_BUFFER, g_UsbACM[usb_port].rx_flc_buf_count);				
				USB_Dbg_Trace(USB_ACM_EP0_RX_IS_EMPTY, g_UsbACM[usb_port].rx_flc_buf_count, 0);
			}
			else
			{
				USB_Dbg_Trace(USB_ACM_EP0_RX_BUF_COUNT, g_UsbACM[usb_port].rx_flc_buf_count, 0);
			}
		
			USB_Dbg_Trace(USB_ACM_EP0_MOVE_R_INDEX, g_UsbACM[usb_port].rx_flc_buf_r_index, g_UsbACM[usb_port].rx_flc_buf_count);
			usb_drv_trace4(ownerid, (kal_uint32)USBACM_FLC_MOVE_R_INDEX, g_UsbACM[usb_port].rx_flc_buf_w_index, g_UsbACM[usb_port].rx_flc_buf_count, g_UsbACM[usb_port].rx_flc_empty_buff_index,g_UsbACM[usb_port].rx_flc_buf_r_index);
		}
		else
		{
			/* Note that the area to determine send_Rxilm must also contain in critical section.
			   Otherwise if USB HISR activated before send_Rxilm setting as true,this message will be lost */
	
			g_UsbACM[usb_port].send_ctrl_Rxilm = KAL_TRUE;
			usb_drv_trace2(ownerid, (kal_uint32)USBACM_FLC_HIGHSPEED_GETBYTES_NO_DATA, (kal_uint32)ownerid, usb_port);
			real_count = 0;
		}
	
		USB_Dbg_Trace(USB_ACM_EP0_GETBYTES, (kal_uint32)port, real_count);
		usb_drv_trace2(ownerid, (kal_uint32)USBACM_FLC_HIGHSPEED_GETBYTES, real_count, usb_port);
	
		if( g_UsbACM[usb_port].rx_flc_buf_count > RNDIS_RX_FLC_BUFFER_NUM)
			ASSERT(0);
						
//		if(USB_Get_UnMask_Irq() == KAL_TRUE)
//			IRQUnmask(IRQ_USB_CODE);
	
		return real_count;
	}
}




static void USB_RNDIS_HaltBus(UART_PORT port,module_type ownerid)
{
	kal_uint32 usb_port = USB_PORT[port];


	USB_Check_Owner(ownerid,USB2UARTPort[usb_port].ownerid);


	USB_High_Speed_En_Check(usb_port);	
	

// stop DMA transfer
	USB_Stop_DMA_Channel(g_UsbACM[usb_port].txpipe->byEP, USB_EP_TX_DIR);
//	USB_Stop_DMA_Channel(g_UsbACM[usb_port].rxpipe->byEP, USB_EP_RX_DIR);

	g_UsbACM[usb_port].setup_dma = KAL_FALSE;
//	g_UsbACM[usb_port].dma_rx_running = KAL_FALSE;
//	g_UsbACM[usb_port].send_Txilm = KAL_FALSE;
//	g_UsbACM[usb_port].send_Rxilm = KAL_FALSE;
//	g_UsbACM[usb_port].send_ctrl_Txilm = KAL_FALSE;  // Ctrl pipe --> TX message
//	g_UsbACM[usb_port].send_ctrl_Rxilm = KAL_FALSE;  // ctrl pipe --> RX message
	g_UsbACM[usb_port].halt_flag = KAL_TRUE;

// clear FIFO
	USB_Clear_Tx_EP_FIFO(g_UsbACM[usb_port].txpipe->byEP,USB_ENDPT_BULK,KAL_FALSE);
	USB_Clear_Rx_EP_FIFO(g_UsbACM[usb_port].rxpipe->byEP,USB_ENDPT_BULK,KAL_FALSE);
}



#endif   // USB Tethering API





/* Add dependency with USB_HS_ENABLE */
#ifdef  __USB_HIGH_SPEED_COM_PORT_ENABLE__

static kal_bool USB_EnableHighSpeedPort(UART_PORT port, kal_bool enable, module_type ownerid,USB_Transfer_type transfer_type)
{
	kal_uint32 usb_port = USB_PORT[port];
	kal_uint16 buf_avail_count;
	kal_uint16 temp_count;
	kal_uint32 savedMask;
	kal_uint32 count = 0;
	BUFFER_INFO *rx_buf_info = &(USB2UARTPort[usb_port].Rx_Buffer);
	BUFFER_INFO *tx_buf_info = &(USB2UARTPort[usb_port].Tx_Buffer);
	kal_int32 remain;


	if(transfer_type == CDC_HIGH_SPEED)
	{

			/* Only when USB is high speed mode, it supports high speed interface */
			if(enable == KAL_TRUE)
			{
				if(USB_Is_High_Speed() == KAL_TRUE)
				{
					/* PPP enables high speed mode */
					/* Check TX ring buffer and DMA, sleep untill DMA stop, no need to do memory copy,
								no need to check buffer status since PPP will not enable threshold */

					savedMask = SaveAndSetIRQMask();
					#if 0
/* under construction !*/
					#else
					    buf_avail_count = USB2UART_GetBufAvail(tx_buf_info);
					#endif
					RestoreIRQMask(savedMask);

					if(buf_avail_count != 0)
					{
						while((g_UsbACM[usb_port].setup_dma == KAL_TRUE)&&(count != USBACM_HIGH_SPEED_LOOP)&&
							(USB_Get_Device_State() == DEVSTATE_CONFIG))
						{
							count++;
							kal_sleep_task(1);
						}
					}

					savedMask = SaveAndSetIRQMask();
					#if 0 
/* under construction !*/
					#else
					    buf_avail_count = USB2UART_GetBufAvail(tx_buf_info);
					#endif					
					RestoreIRQMask(savedMask);

					// To prevent cable out
					if(USB_Get_Device_State() == DEVSTATE_CONFIG)
					{
						if((g_UsbACM[usb_port].setup_dma == KAL_TRUE)||(buf_avail_count != 0)||(count == USBACM_HIGH_SPEED_LOOP))
						{
							USB_Exception_Check();
//							if(INT_Exception_Enter == 0)
//							{
//								EXT_ASSERT(0, g_UsbACM[usb_port].setup_dma, buf_avail_count, count);
//							}
						}
					}

					/* Check RX ring buffer, do memory copy */
					/* Do not want there are many packets still sent from host */
					USB_Mask_USB_CORE((USB_MASK_OWNER) usb_port); //IRQMask(IRQ_USB_CODE);

					/* Initialize the new Rx buffers */
					for(count = 0; count < USB_ACM_RX_BUFFER_NUM; count++)
					{
						g_UsbACM[usb_port].rx_buf_data_len[count] =  0;

						if (g_UsbACM_Comm.rx_buf_addr[count] == NULL)
							g_UsbACM_Comm.rx_buf_addr[count] =  (kal_uint8 *)USB_Get_Memory(USB_ACM_RX_BUFFER_SIZE);						
							
						g_UsbACM[usb_port].rx_buf_addr[count] =  g_UsbACM_Comm.rx_buf_addr[count];						
					}

					g_UsbACM[usb_port].rx_buf_r_index = 0;
					g_UsbACM[usb_port].rx_buf_rc_index = 0;
					g_UsbACM[usb_port].rx_buf_w_index = 0;
					g_UsbACM[usb_port].rx_buf_count = 0;
					g_UsbACM[usb_port].b_data_left = KAL_FALSE;
					g_UsbACM[usb_port].b_rc_index_move = KAL_FALSE;


		//			savedMask = SaveAndSetIRQMask();
					#if 0 
/* under construction !*/
					#else
					    buf_avail_count = USB2UART_GetBufAvail(rx_buf_info);
					#endif			
		//			RestoreIRQMask(savedMask);

					while(buf_avail_count != 0)
					{
						if(buf_avail_count > USB_ACM_RX_BUFFER_SIZE)
						{
							temp_count = USB_ACM_RX_BUFFER_SIZE;
						}
						else
						{
							temp_count = buf_avail_count;
						}

						remain = (BRead(rx_buf_info) + temp_count) - BLength(rx_buf_info);

						/* Copy RX ring buffer data to new buffer */
						if(remain < 0)
						{
							/* dest, src, len */
							kal_mem_cpy(g_UsbACM[usb_port].rx_buf_addr[g_UsbACM[usb_port].rx_buf_w_index], BuffRead(rx_buf_info), temp_count);
							BRead(rx_buf_info) += temp_count;
						}
						else
						{
							kal_mem_cpy(g_UsbACM[usb_port].rx_buf_addr[g_UsbACM[usb_port].rx_buf_w_index], BuffRead(rx_buf_info), temp_count-remain);
							kal_mem_cpy(g_UsbACM[usb_port].rx_buf_addr[g_UsbACM[usb_port].rx_buf_w_index]+(temp_count-remain), BStartAddr(rx_buf_info), remain);
							BRead(rx_buf_info) = remain;
						}

						g_UsbACM[usb_port].rx_buf_data_len[g_UsbACM[usb_port].rx_buf_w_index] = temp_count;
						buf_avail_count -= temp_count;
						g_UsbACM[usb_port].rx_buf_w_index++;

						/* Data is too mush and RX ring is not enough to store it */
						if(g_UsbACM[usb_port].rx_buf_w_index == USB_ACM_RX_BUFFER_NUM)
							ASSERT(0);
					}

					g_UsbACM[usb_port].rx_buf_count = g_UsbACM[usb_port].rx_buf_w_index;

					if(g_UsbACM[usb_port].b_is_high_speed_enable == KAL_TRUE)
					{
						USB_Acm_Exception_Check();
//						if(INT_Exception_Enter == 0)
//						{
//							ASSERT(0);
//						}
					}

					g_UsbACM[usb_port].b_is_high_speed_enable = KAL_TRUE;
					g_UsbACM[usb_port].transfer_type = CDC_HIGH_SPEED;
					g_UsbACM[usb_port].b_rc_get_count = 0;
#ifdef DRV_USB_DMA_QUEUE_SUPPORT		
					USB_DMAQ_PPP_TX_GPD[0].chksum = 0;//PDU_calcCksum((kal_uint8 *)(USB_DMAQ_GPD+index), 16)-1;
					USB_DMAQ_PPP_TX_GPD[0].DataBufferLen = 0;
					USB_DMAQ_PPP_TX_GPD[0].pNext = &(USB_DMAQ_PPP_TX_GPD[1]);
					USB_DMAQ_PPP_TX_GPD[0].pBuf = 0;
					USB_DMAQ_PPP_TX_GPD[0].bufLen =  0;
					USB_DMAQ_PPP_TX_GPD[0].ExtLength = 0;
					USB_DMAQ_PPP_TX_GPD[0].ZTepFlag = g_UsbACM[usb_port].txpipe->byEP;
					USB_DMAQ_PPP_TX_GPD[0].flag = 0;					
					USB_DMAQ_PPP_TX_GPD[1].chksum = 0;//PDU_calcCksum((kal_uint8 *)(USB_DMAQ_GPD+index), 16)-1;
					USB_DMAQ_PPP_TX_GPD[1].DataBufferLen = 0;
					USB_DMAQ_PPP_TX_GPD[1].pNext = &(USB_DMAQ_PPP_TX_GPD[0]);
					USB_DMAQ_PPP_TX_GPD[1].pBuf = 0;
					USB_DMAQ_PPP_TX_GPD[1].bufLen = 0;
					USB_DMAQ_PPP_TX_GPD[1].ExtLength = 0;
					USB_DMAQ_PPP_TX_GPD[1].ZTepFlag = g_UsbACM[usb_port].txpipe->byEP;
					USB_DMAQ_PPP_TX_GPD[1].flag = 0;	


					USB_DMAQ_PPP_RX_GPD[0].chksum = 0;//PDU_calcCksum((kal_uint8 *)(USB_DMAQ_GPD+index), 16)-1;
					USB_DMAQ_PPP_RX_GPD[0].DataBufferLen = USB_ACM_RX_BUFFER_SIZE;
					USB_DMAQ_PPP_RX_GPD[0].pNext = &(USB_DMAQ_PPP_RX_GPD[1]);
					USB_DMAQ_PPP_RX_GPD[0].ExtLength = 0;
					USB_DMAQ_PPP_RX_GPD[0].ZTepFlag = g_UsbACM[usb_port].rxpipe->byEP;
					USB_DMAQ_PPP_RX_GPD[1].chksum = 0;//PDU_calcCksum((kal_uint8 *)(USB_DMAQ_GPD+index), 16)-1;
					USB_DMAQ_PPP_RX_GPD[1].DataBufferLen = USB_ACM_RX_BUFFER_SIZE;
					USB_DMAQ_PPP_RX_GPD[1].pNext = &(USB_DMAQ_PPP_RX_GPD[0]);
					USB_DMAQ_PPP_RX_GPD[1].ExtLength = 0;
					USB_DMAQ_PPP_RX_GPD[1].ZTepFlag = g_UsbACM[usb_port].rxpipe->byEP;
					USB_DMAQ_PPP_RX_GPD[1].flag = 0;
					
					USB_DMAQ_PPP_RX_GPD[0].pBuf = (kal_uint8*)&g_UsbACM[usb_port].rx_buf_addr[g_UsbACM[usb_port].rx_buf_w_index][0];
					USB_DMAQ_PPP_RX_GPD[0].bufLen =  0;						
					USB_DMAQ_PPP_RX_GPD[0].flag = RXGPD_FLAGS_HWO; //1:HW is Owner, SW should not to access data buffer; HW will clear it to 0.
					g_UsbACM[usb_port].ppp_rdmaq_idx = 0;
					g_UsbACM[usb_port].ppp_tdmaq_idx = 0;
					g_UsbACM[usb_port].ppp_txdmaq_first = KAL_TRUE;

					USB_RxEPDis(g_UsbACM[usb_port].rxpipe->byEP, USB_EP_USE_NO_DMA);
					USB_RxEP_DMAQ_En(g_UsbACM[usb_port].rxpipe->byEP,KAL_TRUE);
					USB_TxEP_DMAQ_En(g_UsbACM[usb_port].txpipe->byEP,KAL_TRUE);					
					USB_DMAQ_Setup(g_UsbACM[usb_port].rxpipe->byEP, USB_EP_RX_DIR, 
					  KAL_TRUE, (kal_uint32) &USB_DMAQ_PPP_RX_GPD[g_UsbACM[usb_port].ppp_rdmaq_idx],
					  (usb_dmaq_CB)USB2UART_PPPRX_DMAQ_Callback, (usb_dmaq_CB)NULL,(void *)&USB2UARTPort[usb_port].port_no);
#endif

					USB_Dbg_Trace(USB_ACM_HIGH_SPEED_IF_ENABLE, (kal_uint32)port, g_UsbACM[usb_port].rx_buf_w_index);
					usb_drv_trace1(ownerid, (kal_uint32)USBACM_ENABLE_HIGH_SPEED_IF, g_UsbACM[usb_port].rx_buf_w_index);

					if(USB_Get_UnMask_Irq() == KAL_TRUE)
						USB_UnMask_USB_CORE((USB_MASK_OWNER) usb_port); //IRQUnmask(IRQ_USB_CODE);


					return KAL_TRUE;
				}
				else
				{
					/* USB is in full speed */
					return KAL_FALSE;
				}
			}
			else
			{
				/* PPP disables high speed mode */

				/* For TX, should sleep PPP until DMA stop running */
				if(g_UsbACM[usb_port].setup_dma == KAL_TRUE)
				{
					count = 0;

					while((g_UsbACM[usb_port].setup_dma == KAL_TRUE)&&(count != USBACM_HIGH_SPEED_LOOP)&&
						(USB_Get_Device_State() == DEVSTATE_CONFIG))
					{
						count++;
						kal_sleep_task(1);
					}

					savedMask = SaveAndSetIRQMask();
					if((USB_Is_Suspend_Power_Status() == KAL_TRUE)&&(g_UsbACM[usb_port].txpipe != NULL))
					{
						USB_Stop_DMA_Channel(g_UsbACM[usb_port].txpipe->byEP, USB_EP_TX_DIR);
						g_UsbACM[usb_port].setup_dma = KAL_FALSE;
					}
					RestoreIRQMask(savedMask);
					if(count == USBACM_HIGH_SPEED_LOOP)
					{
						usb_drv_trace1(ownerid, (kal_uint32)USBACM_DISABLE_HIGH_SPEED_IF_TIMEOUT, USBACM_HIGH_SPEED_LOOP);
						USB_Debug_Information(g_UsbACM[usb_port].txpipe->byEP, USB_EP_TX_DIR, KAL_FALSE);
						//ASSERT(0);
					}
				}

				/* For RX, it should not copy the left data to RX ring buffer */
				/* This is because when PPP to L4C, (the data mode to cmd mode), L4C always clear RX ring buffer to prevent from L4C see data as cmd */

				/* Do not want there are many packets still are sent from host */

				
				USB_High_Speed_En_Check(usb_port);	

				g_UsbACM[usb_port].b_is_high_speed_enable = KAL_FALSE;
	#ifdef DRV_USB_DMA_QUEUE_SUPPORT					
				USB_DMAQ_Stop(g_UsbACM[usb_port].rxpipe->byEP,USB_EP_RX_DIR);
				USB_RxEP_DMAQ_En(g_UsbACM[usb_port].rxpipe->byEP,KAL_FALSE);	
				USB_DMAQ_Stop(g_UsbACM[usb_port].txpipe->byEP,USB_EP_TX_DIR);
				USB_TxEP_DMAQ_En(g_UsbACM[usb_port].txpipe->byEP,KAL_FALSE);	
				USB_RxEPEn(g_UsbACM[usb_port].rxpipe->byEP, USB_ENDPT_BULK, USB_EP_USE_NO_DMA, KAL_FALSE, KAL_FALSE);
				USB_TxEPEn(g_UsbACM[usb_port].txpipe->byEP, USB_ENDPT_BULK, USB_EP_USE_ONLY_DMA, KAL_FALSE, KAL_FALSE);				
	#endif
				g_UsbACM[usb_port].transfer_type = CDC_NORMAL;

				USB_Dbg_Trace(USB_ACM_HIGH_SPEED_IF_DISABLE, (kal_uint32)port, BRead(rx_buf_info));
				usb_drv_trace1(ownerid, (kal_uint32)USBACM_DISABLE_HIGH_SPEED_IF, BRead(rx_buf_info));

		//		if(USB_Get_UnMask_Irq() == KAL_TRUE)
		//			IRQUnmask(IRQ_USB_CODE);

				return KAL_TRUE;
			}
		}

#ifdef __USB_TETHERING__

		else if(transfer_type == CDC_HIGH_SPEED_FRAME)
		{
		
			/* Initialize the new Rx buffers */
			for(count = 0; count < (RNDIS_RX_BUFFER_NUM+1); count++)
			{
				g_UsbACM[usb_port].isd_rx_buf_data_len[count] = 0;
				g_UsbACM[usb_port].rx_buf_addr[count] = 0;
			}
					
			for(count = 0; count < (RNDIS_RX_FLC_BUFFER_NUM+1); count++)
			{
				g_UsbACM[usb_port].rx_flc_buf_data_len[count] = 0;
				g_UsbACM[usb_port].rx_flc_buf_addr[count] = 0;
			}	
			
#ifdef __USB_SW_DMA_DIV__
			if (g_UsbACM[usb_port].tx_temp_buf_addr == NULL)
				g_UsbACM[usb_port].tx_temp_buf_addr = (kal_uint8 *)USB_Get_Memory(RNDIS_MAX_FRAME);
#endif			
			g_UsbACM[usb_port].rx_buf_r_index = 0;
			g_UsbACM[usb_port].rx_buf_rc_index = 0;
			g_UsbACM[usb_port].rx_buf_w_index = 0;
			g_UsbACM[usb_port].rx_buf_count = 0;
			g_UsbACM[usb_port].b_data_left = KAL_FALSE;
			g_UsbACM[usb_port].b_rc_index_move = KAL_FALSE;
			g_UsbACM[usb_port].halt_flag = KAL_FALSE;
			g_UsbACM[usb_port].rx_full_buff_index = 0;	// receive Data 
			g_UsbACM[usb_port].rx_empty_buff_index = 0; // empty buffer
			g_UsbACM[usb_port].rx_flc_full_buff_index = 0;	// receive Data 
			g_UsbACM[usb_port].rx_flc_empty_buff_index = 0; // empty buffer 
			g_UsbACM[usb_port].rx_flc_buf_r_index = 0;	/* read pointer */
			g_UsbACM[usb_port].rx_flc_buf_w_index = 0;	/* write pointer: data write (bulk out handler) */
			g_UsbACM[usb_port].rx_flc_buf_count = 0;  /* the buffer count with data */
			g_UsbACM[usb_port].rx_full_data = KAL_FALSE;
			g_UsbACM[usb_port].ctrl_data_done = KAL_TRUE; // these is no EP0 data need to be sent
			
			if(g_UsbACM[usb_port].rx_flc_temp_buf_addr == NULL)
				g_UsbACM[usb_port].rx_flc_temp_buf_addr = (kal_uint8 *)USB_Get_Memory(USB_ISD_EP0_BUFFER_LENGTH);
			
			if(enable == KAL_TRUE)
			{
		//		g_UsbACM[usb_port].rx_flc_temp_length = 0; // initial length --> because USB may receive data before UPS call this API
		//		g_UsbACM[usb_port].rx_flc_temp = KAL_FALSE; // only when PC enumeration faster then UPS push
				g_UsbACM[usb_port].b_is_high_speed_enable = KAL_TRUE;
				g_UsbACM[usb_port].transfer_type = CDC_HIGH_SPEED_FRAME;				
				USB_Dbg_Trace(USB_ACM_HIGH_SPEED_IF_ENABLE, (kal_uint32)port, g_UsbACM[usb_port].rx_buf_w_index);
				usb_drv_trace1(ownerid, (kal_uint32)USB_ISD_ENABLE_HIGH_SPEED_IF, g_UsbACM[usb_port].rx_buf_w_index);
			}
			else
			{
				g_UsbACM[usb_port].b_is_high_speed_enable = KAL_FALSE;
				g_UsbACM[usb_port].transfer_type = CDC_NORMAL;

				USB_Dbg_Trace(USB_ACM_HIGH_SPEED_IF_DISABLE, (kal_uint32)port, BRead(rx_buf_info));
				usb_drv_trace1(ownerid, (kal_uint32)USB_ISD_DISABLE_HIGH_SPEED_IF, BRead(rx_buf_info));
				
		//		USB_Release_Acm_Status();

				g_UsbACM[usb_port].rx_flc_temp_length = 0; // initial length --> because USB may receive data before UPS call this API
				g_UsbACM[usb_port].rx_flc_temp = KAL_FALSE; // only when PC enumeration faster then UPS push			

			}
			return KAL_TRUE;			
		}	
#endif
#if defined(__MBIM_SUPPORT__)||defined(__ECM_SUPPORT__)
		else if(transfer_type == CDC_HIGH_SPEED_FRAME_DMAQ)
		{
			/* Initialize the new Rx buffers */
			for(count = 0; count < (RNDIS_RX_BUFFER_NUM+1); count++)
			{
				g_UsbACM[usb_port].isd_rx_buf_data_len[count] = 0;
				g_UsbACM[usb_port].rx_buf_addr[count] = 0;
			}
					
			for(count = 0; count < (RNDIS_RX_FLC_BUFFER_NUM+1); count++)
			{
				g_UsbACM[usb_port].rx_flc_buf_data_len[count] = 0;
				g_UsbACM[usb_port].rx_flc_buf_addr[count] = 0;
			}	
			
			g_UsbACM[usb_port].rx_buf_r_index = 0;
			g_UsbACM[usb_port].rx_buf_rc_index = 0;
			g_UsbACM[usb_port].rx_buf_w_index = 0;
			g_UsbACM[usb_port].rx_buf_count = 0;
			g_UsbACM[usb_port].b_data_left = KAL_FALSE;
			g_UsbACM[usb_port].b_rc_index_move = KAL_FALSE;
			g_UsbACM[usb_port].halt_flag = KAL_FALSE;
			g_UsbACM[usb_port].rx_full_buff_index = 0;	// receive Data 
			g_UsbACM[usb_port].rx_empty_buff_index = 0; // empty buffer
			g_UsbACM[usb_port].rx_flc_full_buff_index = 0;	// receive Data 
			g_UsbACM[usb_port].rx_flc_empty_buff_index = 0; // empty buffer 
			g_UsbACM[usb_port].rx_flc_buf_r_index = 0;	/* read pointer */
			g_UsbACM[usb_port].rx_flc_buf_w_index = 0;	/* write pointer: data write (bulk out handler) */
			g_UsbACM[usb_port].rx_flc_buf_count = 0;  /* the buffer count with data */
			g_UsbACM[usb_port].rx_full_data = KAL_FALSE;
			g_UsbACM[usb_port].ctrl_data_done = KAL_TRUE; // these is no EP0 data need to be sent
			
			USB_RxEPDis(g_UsbACM[usb_port].rxpipe->byEP, USB_EP_USE_NO_DMA);
			USB_RxEP_DMAQ_En(g_UsbACM[usb_port].rxpipe->byEP,KAL_TRUE);
			USB_TxEP_DMAQ_En(g_UsbACM[usb_port].txpipe->byEP,KAL_TRUE);
			
			USB_DMAQ_RX_GPD_NULL.flag = 0;
			USB_DMAQ_TX_GPD_NULL.flag = 0;
			USB_DMAQ_RX_GPD_NULL.pNext = 0;
			USB_DMAQ_TX_GPD_NULL.pNext = 0;
			
			if(g_UsbACM[usb_port].rx_flc_temp_buf_addr == NULL)
				g_UsbACM[usb_port].rx_flc_temp_buf_addr = (kal_uint8 *)USB_Get_Memory(USB_ISD_EP0_BUFFER_LENGTH);
			
			if(enable == KAL_TRUE)
			{
				g_UsbACM[usb_port].b_is_high_speed_enable = KAL_TRUE;
				g_UsbACM[usb_port].transfer_type = transfer_type;				
				USB_Dbg_Trace(USB_ACM_HIGH_SPEED_IF_ENABLE, (kal_uint32)port, g_UsbACM[usb_port].rx_buf_w_index);
				usb_drv_trace1(ownerid, (kal_uint32)USB_ISD_ENABLE_HIGH_SPEED_IF, g_UsbACM[usb_port].rx_buf_w_index);
			}
			else
			{
				g_UsbACM[usb_port].b_is_high_speed_enable = KAL_FALSE;
				g_UsbACM[usb_port].transfer_type = CDC_NORMAL;

				USB_Dbg_Trace(USB_ACM_HIGH_SPEED_IF_DISABLE, (kal_uint32)port, BRead(rx_buf_info));
				usb_drv_trace1(ownerid, (kal_uint32)USB_ISD_DISABLE_HIGH_SPEED_IF, BRead(rx_buf_info));

				g_UsbACM[usb_port].rx_flc_temp_length = 0; // initial length --> because USB may receive data before UPS call this API
				g_UsbACM[usb_port].rx_flc_temp = KAL_FALSE; // only when PC enumeration faster then UPS push			

			}
			return KAL_TRUE;	
		}
#endif //#if defined(__MBIM_SUPPORT__)
			ASSERT(0);

return KAL_FALSE;

	
}

static void USB_Register_HighSpeed_TX_Callback(UART_PORT port, module_type ownerid, usb_dma_callback func)
{
//	kal_uint32 usb_port = USB_PORT[port];

  if (port == uart_port_usb)
    usb_hs_tx_reg_cb = func;    
  #if defined(__USB_MULTIPLE_COMPORT_SUPPORT__)
  else if (port == uart_port_usb2)
  {
    usb2_hs_tx_reg_cb = func;    
  }
  #if defined (__USB_MODEM_CARD_SUPPORT__)
  else if (port == uart_port_usb3)
  {
    usb3_hs_tx_reg_cb = func;
  }
  else if (port == uart_port_usb4)
  {
    usb4_hs_tx_reg_cb = func;
  }
  else if (port == uart_port_usb5)
  {
    usb5_hs_tx_reg_cb = func;
  }
  #endif  //#if defined (__USB_MODEM_CARD_SUPPORT__)
#endif  //#if defined(__USB_MULTIPLE_COMPORT_SUPPORT__)
}

static kal_bool USB_QueryHSTxDataLeft(UART_PORT usb_port)
{
  if (g_UsbACM[usb_port].tx_count > 0)
    return KAL_TRUE;
  else
    return KAL_FALSE;  
}


PRAGMA_BEGIN_COMPILER_OPTIMIZE_TIME
/* Put bytes to TX buffer, return value is the actually put out bytes number */
static kal_uint16 USB_HighSpeed_PutBytes(UART_PORT port, kal_uint8 *buffaddr, kal_uint16 length, module_type ownerid,kal_bool send_ready_to_write)
{
	kal_uint32 usb_port = USB_PORT[port];
	kal_uint8* non_cache_addr = buffaddr;
	kal_uint32 savedMask;
	kal_uint8 ep_num = 0;
	#ifndef DRV_USB_DMA_QUEUE_SUPPORT
	usb_dma_callback dma_callback;
	#endif
	kal_bool  setup_dma = KAL_FALSE;

	if (ownerid != MOD_UPS)
	USB_Check_Owner(ownerid,USB2UARTPort[usb_port].ownerid);
	
	
	if (length == 0)
		ASSERT(0);


	USB_High_Speed_En_Check(usb_port);	


	// RNDIS will add padding (framek = transfer) --> not 64B *N
	if ((g_UsbACM[usb_port].transfer_type == CDC_HIGH_SPEED_FRAME)&&(length%64 == 0))
			ASSERT(0);
	

	USB_Dbg_Trace(USB_ACM_HIGHSPEED_PUTBYTES, (kal_uint32)port, length);

	usb_drv_trace2(ownerid, (kal_uint32)USBACM_HIGHSPEED_PUTBYTES, length, usb_port);


	/* Return directly if not match condition, may be due to cable out just before PPP call this API */
	if((USB2UART_Check_Config(usb_port) == KAL_FALSE)||(g_UsbACM[usb_port].halt_flag == KAL_TRUE))
    {
	    usb_drv_trace0(ownerid, (kal_uint32)USBACM_HIGHSPEED_PUTBYTES_FAIL);
		return 0;
	}

	savedMask = SaveAndSetIRQMask();

	/* In case USB is plugged out just before this critical section */
	if(g_UsbACM[usb_port].txpipe != NULL)
	{
#ifdef DRV_USB_DMA_QUEUE_SUPPORT
		if(g_UsbACM[usb_port].setup_dma == KAL_FALSE)
		{
			setup_dma = KAL_TRUE;
		}
#else
		setup_dma = (USB_DMA_Get_Run_Status(g_UsbACM[usb_port].txpipe->byEP, USB_EP_TX_DIR) == KAL_FALSE);
#endif
			
		/* Can use DMA flag since only PPP will trigger DMA. (USB driver only see one buffer) */
//		if(USB_DMA_Get_Run_Status(g_UsbACM[usb_port].txpipe->byEP, USB_EP_TX_DIR) == KAL_FALSE)
		if(setup_dma)
		{
			/* DMA is not running */
			ep_num = g_UsbACM[usb_port].txpipe->byEP;
			g_UsbACM[usb_port].setup_dma = KAL_TRUE;			
		}
		else
		{
			if(send_ready_to_write == KAL_TRUE)
			{
			/* DMA is running, in DMA callback should send the "ready to write" */
			g_UsbACM[usb_port].send_Txilm = KAL_TRUE;
			}
		}
	}

	RestoreIRQMask(savedMask);

	if(ep_num != 0)
	{
		USB_Dbg_Trace(USB_ACM_HIGHSPEED_PUTBYTES_SETUP_DMA, (kal_uint32)port, length);

	    usb_drv_trace2(ownerid, (kal_uint32)USBACM_HIGHSPEED_PUTBYTES_SETUP_DMA, length, usb_port);

#ifndef DRV_USB_DMA_QUEUE_SUPPORT
		if(port == uart_port_usb)
		{
			dma_callback = usb_hs_tx_reg_cb;
		}
#if defined(__USB_MULTIPLE_COMPORT_SUPPORT__)
		else if(port == uart_port_usb2)
		{
			dma_callback = usb2_hs_tx_reg_cb;
		}
#if defined (__USB_MODEM_CARD_SUPPORT__)
		else if(port == uart_port_usb3)
		{
			dma_callback = usb3_hs_tx_reg_cb;
		}
		else if(port == uart_port_usb4)
		{
			dma_callback = usb4_hs_tx_reg_cb;
		}
		else if(port == uart_port_usb5)
		{
			dma_callback = usb5_hs_tx_reg_cb;
		}
#endif  /*__USB_MODEM_CARD_SUPPORT__*/
#endif
		else
		{
			dma_callback = NULL;
			ASSERT(0);
		}
#endif

#ifdef __DYNAMIC_SWITCH_CACHEABILITY__
		if((kal_bool)INT_QueryIsNonCachedRAM(non_cache_addr, length) == KAL_FALSE)
		{
	#if defined(__MTK_TARGET__)
			dynamic_switch_cacheable_region((void*)&non_cache_addr, length, PAGE_NO_CACHE);
	#endif
		}
		else
		{
//			ASSERT(0);
		}
#endif

//		g_UsbACM[usb_port].setup_dma = KAL_TRUE;

		// Only support high speed
		if((length%USB_EP_BULK_MAXP_HS) == 0)
		{
			g_UsbACM[usb_port].tx_count = length - 1;
			g_UsbACM[usb_port].b_data_left = KAL_TRUE;
			g_UsbACM[usb_port].data_addr = (kal_uint32)non_cache_addr + length - 1;
		}
		else
		{
			g_UsbACM[usb_port].tx_count = length;
		}


#ifdef __USB_TETHERING__
		if (g_UsbACM[usb_port].transfer_type == CDC_HIGH_SPEED_FRAME)
		{
		g_UsbACM[usb_port].tx_count = length;
		}
#endif


#ifdef __USB_SW_DMA_DIV__
		if ((kal_uint32)non_cache_addr & 0x03)
		{	
			kal_mem_cpy(g_UsbACM[usb_port].tx_temp_buf_addr,non_cache_addr,g_UsbACM[usb_port].tx_count);
			USB_DMA_Setup(ep_num, USB_EP_TX_DIR, USB_ENDPT_BULK, (kal_uint32)g_UsbACM[usb_port].tx_temp_buf_addr, g_UsbACM[usb_port].tx_count, dma_callback, KAL_FALSE, KAL_TRUE, USB_DMA1_TYPE);
		}
		else
		{
		USB_DMA_Setup(ep_num, USB_EP_TX_DIR, USB_ENDPT_BULK, (kal_uint32)non_cache_addr, g_UsbACM[usb_port].tx_count, dma_callback, KAL_FALSE, KAL_TRUE, USB_DMA1_TYPE);
		}
#else
	#ifdef DRV_USB_DMA_QUEUE_SUPPORT
	  	USB_DMAQ_PPP_TX_GPD[g_UsbACM[usb_port].ppp_tdmaq_idx].pBuf = non_cache_addr;
	  	USB_DMAQ_PPP_TX_GPD[g_UsbACM[usb_port].ppp_tdmaq_idx].bufLen = g_UsbACM[usb_port].tx_count;		
		USB_DMAQ_PPP_TX_GPD[g_UsbACM[usb_port].ppp_tdmaq_idx].flag = TXGPD_FLAGS_HWO; //1:HW is Owner, SW should not to access data buffer; HW will clear it to 0.		
		USB_DMAQ_Setup(g_UsbACM[usb_port].txpipe->byEP, USB_EP_TX_DIR, 
		  g_UsbACM[usb_port].ppp_txdmaq_first, (kal_uint32) &USB_DMAQ_PPP_TX_GPD[g_UsbACM[usb_port].ppp_tdmaq_idx],
		  (usb_dmaq_CB)USB2UART_PPPTX_DMAQ_Callback, (usb_dmaq_CB)NULL,(void *)&USB2UARTPort[usb_port].port_no);
		g_UsbACM[usb_port].ppp_txdmaq_first = KAL_FALSE;
//		g_UsbACM[usb_port].ppp_tdmaq_idx++;
//		if(g_UsbACM[usb_port].ppp_tdmaq_idx == 2)
//			g_UsbACM[usb_port].ppp_tdmaq_idx = 0;		
	#else
		USB_DMA_Setup(ep_num, USB_EP_TX_DIR, USB_ENDPT_BULK, (kal_uint32)non_cache_addr, g_UsbACM[usb_port].tx_count, dma_callback, KAL_FALSE, KAL_TRUE, USB_DMA1_TYPE);
#endif
#endif

		return length;
		// Still let PPP feel all data is out
	}
	else
	{
		usb_drv_trace0(ownerid, (kal_uint32)USBACM_HIGHSPEED_PUTBYTES_DMA_IS_RUNNING);
		return 0;
	}

}
PRAGMA_END_COMPILER_OPTIMIZE_TIME

PRAGMA_BEGIN_COMPILER_OPTIMIZE_TIME
static void USB_HighSpeedPushBuff(UART_PORT port, module_type ownerid)
{
	kal_uint32 usb_port = USB_PORT[port];
	//kal_uint32 savedMask;	


	/* Return directly if not match conditions */
	if(USB2UART_Check_Config(usb_port) == KAL_FALSE)
		return;

	USB_Mask_USB_CORE((USB_MASK_OWNER) usb_port);//IRQMask(IRQ_USB_CODE);	
	/* Move read clear pointer */
	if(g_UsbACM[usb_port].b_rc_index_move == KAL_TRUE)
	{
		g_UsbACM[usb_port].b_rc_get_count -= 1;	
		if(g_UsbACM[usb_port].b_rc_get_count == 0)
		{
		g_UsbACM[usb_port].b_rc_index_move = KAL_FALSE;
		}

		if(g_UsbACM[usb_port].rx_buf_data_len[g_UsbACM[usb_port].rx_buf_rc_index] != 0)
			ASSERT(0);
	/* UnmaskIRQ */
	/* UnmaskIRQ */
		#ifdef DRV_USB_DMA_QUEUE_SUPPORT
		if(g_UsbACM[usb_port].rx_buf_w_index == g_UsbACM[usb_port].rx_buf_rc_index)
		{
			kal_uint32 curr_idx = g_UsbACM[usb_port].ppp_rdmaq_idx;
			USB_DMAQ_PPP_RX_GPD[curr_idx].pBuf = (kal_uint8*)&g_UsbACM[usb_port].rx_buf_addr[g_UsbACM[usb_port].rx_buf_w_index][0];
			USB_DMAQ_PPP_RX_GPD[curr_idx].bufLen =  0;	
			USB_DMAQ_PPP_RX_GPD[curr_idx].flag = RXGPD_FLAGS_HWO; //1:HW is Owner, SW should not to access data buffer; HW will clear it to 0.					
			USB_DMAQ_Setup(g_UsbACM[usb_port].rxpipe->byEP, USB_EP_RX_DIR, 
				  KAL_FALSE, (kal_uint32) &USB_DMAQ_PPP_RX_GPD[curr_idx],
				  (usb_dmaq_CB)USB2UART_PPPRX_DMAQ_Callback, (usb_dmaq_CB)NULL,(void *)&USB2UARTPort[usb_port].port_no);
		}		
		#endif

		g_UsbACM[usb_port].rx_buf_rc_index++;

		if(g_UsbACM[usb_port].rx_buf_rc_index == USB_ACM_RX_BUFFER_NUM)
			g_UsbACM[usb_port].rx_buf_rc_index = 0;

//		USB_Dbg_Trace(USB_ACM_HIGHSPEED_MOVE_RC_INDEX, g_UsbACM[usb_port].rx_buf_rc_index, 0);
		drv_trace4(TRACE_GROUP_1, (kal_uint32)USBACM_MOVE_RC_INDEX, g_UsbACM[usb_port].rx_buf_w_index, g_UsbACM[usb_port].rx_buf_count, g_UsbACM[usb_port].rx_buf_rc_index, g_UsbACM[usb_port].rx_buf_r_index);

		/* UnmaskIRQ */
		#ifndef DRV_USB_DMA_QUEUE_SUPPORT
		USB_UnMask_COM_Intr(port);
		#endif
	}	
	USB_UnMask_USB_CORE((USB_MASK_OWNER) usb_port); //IRQUnmask(IRQ_USB_CODE);

}
PRAGMA_END_COMPILER_OPTIMIZE_TIME

PRAGMA_BEGIN_COMPILER_OPTIMIZE_TIME
/* Get bytes from RX buffer, parameter status shows escape and break status
     return value is the actually get bytes */
static kal_uint16 USB_HighSpeedGetBytes(UART_PORT port, kal_uint8 **buffaddr, kal_uint8 *status, module_type ownerid)
{
	kal_uint32 usb_port = USB_PORT[port];
	kal_uint16 real_count;
	kal_bool buf_empty = KAL_FALSE;
	//kal_uint32 savedMask;	

	USB_Check_Owner(ownerid,USB2UARTPort[usb_port].ownerid);
	
	/* Return directly if not match conditions */
	if(USB2UART_Check_Config(usb_port) == KAL_FALSE)
		return 0;

	/* Update status */
	if(status != NULL)
	{
		*status = 0;

		if(USB2UARTPort[usb_port].EscFound)
		{
			*status |= UART_STAT_EscDet;
			USB2UARTPort[usb_port].EscFound = KAL_FALSE;
		}

		if(USB2UARTPort[usb_port].breakDet)
		{
			*status |= UART_STAT_Break;
			USB2UARTPort[usb_port].breakDet = KAL_FALSE;
		}
	}
	
	
	//Mass Storage and CDCACM race condition
	//IRQ_USBDMA trigger MS to unmask IRQ_USB_CODE
	//USB_Mask_Irq(USB_MASK_OWNER_ALL); 
	
	USB_Mask_USB_CORE((USB_MASK_OWNER) usb_port);//IRQMask(IRQ_USB_CODE);

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
		#ifdef DRV_USB_DMA_QUEUE_SUPPORT
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
		#ifndef DRV_USB_DMA_QUEUE_SUPPORT
/* under construction !*/
		#endif
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

	/* Move read pointer */
	/* Determine real data count */
	if(g_UsbACM[usb_port].rx_buf_data_len[g_UsbACM[usb_port].rx_buf_r_index] != 0)
	{
		g_UsbACM[usb_port].b_rc_get_count += 1;
		g_UsbACM[usb_port].b_rc_index_move = KAL_TRUE;
		*buffaddr = g_UsbACM[usb_port].rx_buf_addr[g_UsbACM[usb_port].rx_buf_r_index];
		real_count = g_UsbACM[usb_port].rx_buf_data_len[g_UsbACM[usb_port].rx_buf_r_index];
		g_UsbACM[usb_port].rx_buf_data_len[g_UsbACM[usb_port].rx_buf_r_index] = 0;

		/* Move write pointer index only when current buffer receive 512*N, and write index does not move to next buffer, but PPP already receives this buffer */
		/* Check if it needs to move write index */
		if((g_UsbACM[usb_port].rx_buf_r_index == g_UsbACM[usb_port].rx_buf_w_index)&&(g_UsbACM[usb_port].rx_buf_count == 0))
		{
			buf_empty = KAL_TRUE;
			//USB_Dbg_Trace(USB_ACM_HIGHSPEED_RX_IS_EMPTY, g_UsbACM[usb_port].rx_buf_count, 0);
		}
		else
		{
			if(g_UsbACM[usb_port].rx_buf_count == 0)
				ASSERT(0);

			g_UsbACM[usb_port].rx_buf_count--;
			//USB_Dbg_Trace(USB_ACM_HIGHSPEED_RX_BUF_COUNT, g_UsbACM[usb_port].rx_buf_count, 0);
		}

		g_UsbACM[usb_port].rx_buf_r_index++;

		if(g_UsbACM[usb_port].rx_buf_r_index == USB_ACM_RX_BUFFER_NUM)
			g_UsbACM[usb_port].rx_buf_r_index = 0;

		/* Update write pointer */
		if(buf_empty == KAL_TRUE)
			g_UsbACM[usb_port].rx_buf_w_index = g_UsbACM[usb_port].rx_buf_r_index;

		//USB_Dbg_Trace(USB_ACM_HIGHSPEED_MOVE_R_INDEX, g_UsbACM[usb_port].rx_buf_r_index, g_UsbACM[usb_port].rx_buf_count);
		usb_drv_trace4(ownerid, (kal_uint32)USBACM_MOVE_R_INDEX, g_UsbACM[usb_port].rx_buf_w_index, g_UsbACM[usb_port].rx_buf_count, g_UsbACM[usb_port].rx_buf_rc_index, g_UsbACM[usb_port].rx_buf_r_index);
	}
	else
	{
		/* Note that the area to determine send_Rxilm must also contain in critical section.
		   Otherwise if USB HISR activated before send_Rxilm setting as true,
		   this message will be lost */
		g_UsbACM[usb_port].send_Rxilm = KAL_TRUE;
		usb_drv_trace2(ownerid, (kal_uint32)USBACM_HIGHSPEED_GETBYTES_NO_DATA, (kal_uint32)ownerid, usb_port);
		real_count = 0;
	}

//	USB_Dbg_Trace(USB_ACM_HIGHSPEED_GETBYTES, (kal_uint32)port, real_count);
	usb_drv_trace2(ownerid, (kal_uint32)USBACM_HIGHSPEED_GETBYTES, real_count, usb_port);


//	savedMask = SaveAndSetIRQMask();
	
//	USB_UnMask_Irq(USB_MASK_OWNER_ALL);
//	if(USB_Get_UnMask_Irq() == KAL_TRUE)
		USB_UnMask_USB_CORE((USB_MASK_OWNER) usb_port); //IRQUnmask(IRQ_USB_CODE);

		
//	RestoreIRQMask(savedMask);



	return real_count;
}
PRAGMA_END_COMPILER_OPTIMIZE_TIME

static kal_uint16 USB_HighSpeedGetFrame(UART_PORT port, kal_uint8 **buffaddr, module_type ownerid, USB_Requ_type type)
{
	kal_uint32 usb_port = USB_PORT[port];	
	kal_uint16 real_count;
//	kal_bool buf_empty = KAL_FALSE;
	kal_uint32 savedMask;	
	kal_uint32 max_bulk_pkt_size;
	
/*	
#ifdef __USB_HS_ENABLE__
		if((USB_Is_High_Speed() == KAL_TRUE)||(USB_Is_FIFO_Not_Empty() == KAL_TRUE))  // if OUT+Suspend+OUT, still gets 512B data from FIFO.
			max_bulk_pkt_size = USB_EP_BULK_MAXP_HS;
		else
			max_bulk_pkt_size = USB_EP_BULK_MAXP_FS;
#else
		max_bulk_pkt_size = USB_EP_BULK_MAXP;
#endif
*/
	if (ownerid !=MOD_UPS)
		USB_Check_Owner(ownerid,USB2UARTPort[usb_port].ownerid);
	max_bulk_pkt_size = USB_Bulk_Max_Packet_Size();


	if ((type == CDC_ONLY_PUSH)||(type == CDC_GET_DATA))  // push buffer 
	{

		if (*buffaddr == NULL)
			ASSERT(0);

//		if (g_UsbACM[usb_port].rx_empty_buff_index == g_UsbACM[usb_port].rx_buf_w_index)
//			ASSERT(0);

		if( g_UsbACM[usb_port].rx_buf_count > RNDIS_RX_BUFFER_NUM)
			ASSERT(0);

		if (g_UsbACM[usb_port].rx_buf_addr[g_UsbACM[usb_port].rx_empty_buff_index] != NULL)
			ASSERT(0);
		
		usb_drv_trace1(ownerid, (kal_uint32)USBACM_RX_PUSH, g_UsbACM[usb_port].rx_empty_buff_index);		

		savedMask = SaveAndSetIRQMask();

		g_UsbACM[usb_port].rx_buf_addr[g_UsbACM[usb_port].rx_empty_buff_index]= *buffaddr;
		
		g_UsbACM[usb_port].rx_empty_buff_index ++;
		
		g_UsbACM[usb_port].rx_buf_count++;
				
		if(g_UsbACM[usb_port].rx_empty_buff_index == (RNDIS_RX_BUFFER_NUM+1)) // 0 ~  8
			g_UsbACM[usb_port].rx_empty_buff_index = 0;		
		
		
				
		/* Return directly if not match conditions */
		if(USB2UART_Check_Config(usb_port) == KAL_FALSE)
                {
		         RestoreIRQMask(savedMask);		
		usb_drv_trace4(ownerid, (kal_uint32)USBACM_RX_INDEX, g_UsbACM[usb_port].rx_buf_w_index, g_UsbACM[usb_port].rx_buf_count, g_UsbACM[usb_port].rx_buf_rc_index, g_UsbACM[usb_port].rx_buf_r_index);
			return 0;
                }

				
		if (g_UsbACM[usb_port].rx_full_data == KAL_TRUE)  //  there is some buffer for further data receive 
		{		
				g_UsbACM[usb_port].rx_full_data = KAL_FALSE;				
				USB_EP_Rx_Ready(g_UsbACM[usb_port].rxpipe->byEP, USB_ENDPT_BULK); /* Clear RxPktRdy */
				
				
				USB_UnMask_COM_Intr(port);
/*				
				if(port == uart_port_usb)
					USB_UnMask_Irq(USB_MASK_OWNER_COM_1);
#if defined(__USB_MULTIPLE_COMPORT_SUPPORT__)
				else if(port == uart_port_usb2)
					USB_UnMask_Irq(USB_MASK_OWNER_COM_2);
				else if(port == uart_port_usb3)
					USB_UnMask_Irq(USB_MASK_OWNER_COM_3);
#endif
*/
		}
                RestoreIRQMask(savedMask);				
		usb_drv_trace4(ownerid, (kal_uint32)USBACM_RX_INDEX, g_UsbACM[usb_port].rx_buf_w_index, g_UsbACM[usb_port].rx_buf_count, g_UsbACM[usb_port].rx_buf_rc_index, g_UsbACM[usb_port].rx_buf_r_index);
	}


	if (type == CDC_ONLY_PUSH)
	{		
		return 0;
	}
	else if (type == CDC_POP_BUFF)
	{

//		drv_trace1(TRACE_GROUP_1, (kal_uint32)USBACM_RX_POP, g_UsbACM[usb_port].rx_buf_r_index);
		
		if (g_UsbACM[usb_port].rx_buf_r_index != g_UsbACM[usb_port].rx_empty_buff_index)
		{
			usb_drv_trace1(ownerid, (kal_uint32)USBACM_RX_POP, g_UsbACM[usb_port].rx_buf_r_index);
		
			*buffaddr = g_UsbACM[usb_port].rx_buf_addr[g_UsbACM[usb_port].rx_buf_r_index];		
			g_UsbACM[usb_port].rx_buf_addr[g_UsbACM[usb_port].rx_buf_r_index] = NULL;	
			
			g_UsbACM[usb_port].rx_buf_r_index ++;			
			g_UsbACM[usb_port].rx_buf_count --;

			if(g_UsbACM[usb_port].rx_buf_r_index == (RNDIS_RX_BUFFER_NUM+1))
				g_UsbACM[usb_port].rx_buf_r_index = 0; 	
			
		}
		else
			*buffaddr = NULL;
			
		return 0;

	}
	else 
	{
		/* Return directly if not match conditions */
		if(USB2UART_Check_Config(usb_port) == KAL_FALSE)
			return 0;
		
		//Mass Storage and CDCACM race condition
		//IRQ_USBDMA trigger MS to unmask IRQ_USB_CODE
		USB_Mask_Irq(USB_MASK_OWNER_ALL); 
		USB_Mask_USB_CORE((USB_MASK_OWNER) usb_port);//IRQMask(IRQ_USB_CODE);
	
		/* Move read clear pointer */
		if(g_UsbACM[usb_port].b_rc_index_move == KAL_TRUE)
		{
			g_UsbACM[usb_port].b_rc_index_move = KAL_FALSE;
	
			if(g_UsbACM[usb_port].isd_rx_buf_data_len[g_UsbACM[usb_port].rx_buf_rc_index] != 0)
				ASSERT(0); // for IT

			g_UsbACM[usb_port].rx_buf_rc_index++;
	
			if(g_UsbACM[usb_port].rx_buf_rc_index == (RNDIS_RX_BUFFER_NUM+1))
				g_UsbACM[usb_port].rx_buf_rc_index = 0;
	
			USB_Dbg_Trace(USB_ACM_HIGHSPEED_MOVE_RC_INDEX, g_UsbACM[usb_port].rx_buf_rc_index, 0);
			usb_drv_trace4(ownerid, (kal_uint32)USBACM_MOVE_RC_INDEX, g_UsbACM[usb_port].rx_buf_w_index, g_UsbACM[usb_port].rx_buf_count, g_UsbACM[usb_port].rx_buf_rc_index, g_UsbACM[usb_port].rx_buf_r_index);
	
			/* UnmaskIRQ */
			
			USB_UnMask_COM_Intr(port);
/*			
			if(port == uart_port_usb)
				USB_UnMask_Irq(USB_MASK_OWNER_COM_1);
#if defined(__USB_MULTIPLE_COMPORT_SUPPORT__)
			else if(port == uart_port_usb2)
				USB_UnMask_Irq(USB_MASK_OWNER_COM_2);
			else if(port == uart_port_usb3)
				USB_UnMask_Irq(USB_MASK_OWNER_COM_3);
#endif
*/
		}
	
	
		/* Move read pointer */
		/* Determine real data count */
		if((g_UsbACM[usb_port].isd_rx_buf_data_len[g_UsbACM[usb_port].rx_buf_r_index] != 0)&&((g_UsbACM[usb_port].isd_rx_buf_data_len[g_UsbACM[usb_port].rx_buf_r_index] % max_bulk_pkt_size) != 0))
		{
		
			savedMask = SaveAndSetIRQMask();

		
			if(g_UsbACM[usb_port].rx_buf_count == 0)
				ASSERT(0);
			
			g_UsbACM[usb_port].rx_buf_count--;

		
			g_UsbACM[usb_port].b_rc_index_move = KAL_TRUE;
			*buffaddr = g_UsbACM[usb_port].rx_buf_addr[g_UsbACM[usb_port].rx_buf_r_index];
			real_count = g_UsbACM[usb_port].isd_rx_buf_data_len[g_UsbACM[usb_port].rx_buf_r_index];
			g_UsbACM[usb_port].isd_rx_buf_data_len[g_UsbACM[usb_port].rx_buf_r_index] = 0;
			g_UsbACM[usb_port].rx_buf_addr[g_UsbACM[usb_port].rx_buf_r_index] = NULL;
	
			/* Move write pointer index only when current buffer receive 512*N, and write index does not move to next buffer, but PPP already receives this buffer */
			/* Check if it needs to move write index */
	
			g_UsbACM[usb_port].rx_buf_r_index++;
	
			if(g_UsbACM[usb_port].rx_buf_r_index == (RNDIS_RX_BUFFER_NUM+1))
				g_UsbACM[usb_port].rx_buf_r_index = 0;

			
//			if((g_UsbACM[usb_port].rx_empty_buff_index == g_UsbACM[usb_port].rx_buf_w_index)&&(g_UsbACM[usb_port].rx_buf_count == 0))
			if(g_UsbACM[usb_port].rx_buf_addr[g_UsbACM[usb_port].rx_buf_w_index]== NULL)
			{
				USB_Dbg_Trace(USB_ACM_HIGHSPEED_RX_IS_EMPTY, g_UsbACM[usb_port].rx_buf_count, 0);
			}
			else
			{
				USB_Dbg_Trace(USB_ACM_HIGHSPEED_RX_BUF_COUNT, g_UsbACM[usb_port].rx_buf_count, 0);
			}
	
			/* Update write pointer */
//			if(buf_empty == KAL_TRUE)
//				g_UsbACM[usb_port].rx_buf_w_index = g_UsbACM[usb_port].rx_buf_r_index;
	

			RestoreIRQMask(savedMask);

	
			USB_Dbg_Trace(USB_ACM_HIGHSPEED_MOVE_R_INDEX, g_UsbACM[usb_port].rx_buf_r_index, g_UsbACM[usb_port].rx_buf_count);
			usb_drv_trace4(ownerid, (kal_uint32)USBACM_MOVE_R_INDEX, g_UsbACM[usb_port].rx_buf_w_index, g_UsbACM[usb_port].rx_buf_count, g_UsbACM[usb_port].rx_buf_rc_index, g_UsbACM[usb_port].rx_buf_r_index);
		}
		else
		{
			/* Note that the area to determine send_Rxilm must also contain in critical section.
			   Otherwise if USB HISR activated before send_Rxilm setting as true,this message will be lost */
	
			g_UsbACM[usb_port].send_Rxilm = KAL_TRUE;
			usb_drv_trace2(ownerid, (kal_uint32)USBACM_HIGHSPEED_GETBYTES_NO_DATA, (kal_uint32)ownerid, usb_port);
			real_count = 0;
		}
	
		if(g_UsbACM[usb_port].rx_buf_count > RNDIS_RX_BUFFER_NUM)
			ASSERT(0);

	
		USB_Dbg_Trace(USB_ACM_HIGHSPEED_GET_FRAME, (kal_uint32)port, real_count);
		usb_drv_trace2(ownerid, (kal_uint32)USBACM_HIGHSPEED_GETBYTES, real_count, usb_port);
	
		savedMask = SaveAndSetIRQMask();
		USB_UnMask_Irq(USB_MASK_OWNER_ALL);
		if(USB_Get_UnMask_Irq() == KAL_TRUE)
			USB_UnMask_USB_CORE((USB_MASK_OWNER) usb_port); //IRQUnmask(IRQ_USB_CODE);

		RestoreIRQMask(savedMask);
	
		
		if (g_UsbACM[usb_port].rx_full_data == KAL_TRUE)  // because Get byte, there is some buffer for further data receive 
		{		
			if (g_UsbACM[usb_port].rx_empty_buff_index != g_UsbACM[usb_port].rx_buf_w_index)
			{
				g_UsbACM[usb_port].rx_full_data = KAL_FALSE;				
				USB_EP_Rx_Ready(g_UsbACM[usb_port].rxpipe->byEP, USB_ENDPT_BULK); /* Clear RxPktRdy */
			}		
		}
	
		return real_count;
	}

}
	






static kal_uint16 USB_Receive_Data(UART_PORT port, kal_uint8 **buffaddr, module_type ownerid, kal_uint16 length,kal_uint8 *status,USB_Requ_type type)//,USB_Transfer_type transfer_type)
{
	kal_uint32 usb_port = USB_PORT[port];
#if defined(__MBIM_SUPPORT__)||defined(__ECM_SUPPORT__)
	TGPD *p_GPD = NULL;
#endif
	
	if (g_UsbACM[usb_port].transfer_type == CDC_NORMAL)
	{
		return USB2UART_GetBytes(port, *buffaddr, length,status, ownerid);
	}	
#ifdef  __USB_HIGH_SPEED_COM_PORT_ENABLE__	
	else
	{
		
		if (g_UsbACM[usb_port].transfer_type == CDC_HIGH_SPEED)
		{
			return USB_HighSpeedGetBytes(port, buffaddr, status, ownerid);
		}
		else if(g_UsbACM[usb_port].transfer_type == CDC_HIGH_SPEED_FRAME)
		{
			return USB_HighSpeedGetFrame(port, buffaddr, ownerid, type);
		}
#if defined(__MBIM_SUPPORT__)||defined(__ECM_SUPPORT__)
		else if(g_UsbACM[usb_port].transfer_type == CDC_HIGH_SPEED_FRAME_DMAQ)
		{
			if (buffaddr == NULL)
				ASSERT(0);

			USB_Mask_USB_CORE((USB_MASK_OWNER) usb_port);
			
			if (USB_DMAQ_RX_GPD_HEADER == NULL || USB_DMAQ_RX_GPD_HEADER == (&USB_DMAQ_RX_GPD_NULL))
			{
				USB_DMAQ_RX_GPD_HEADER = (TGPD *)buffaddr;
				p_GPD = (TGPD *)buffaddr;;
				do{
					p_GPD->ZTepFlag = (g_UsbACM[usb_port].rxpipe->byEP); //EP
					if (p_GPD->pNext == NULL)
						p_GPD->pNext = &USB_DMAQ_RX_GPD_NULL;
					p_GPD = p_GPD->pNext;
				}while(p_GPD != (&USB_DMAQ_RX_GPD_NULL));
				
				drv_trace2(TRACE_FUNC, (kal_uint32)USB_DMAQ_RXGPD_SETUP, (kal_uint32)buffaddr, (kal_uint32)USB_DMAQ_RX_GPD_HEADER);
				USB_DMAQ_Setup(g_UsbACM[usb_port].rxpipe->byEP, USB_EP_RX_DIR, KAL_TRUE, (kal_uint32) buffaddr, (usb_dmaq_CB)USB2UART_RX_DMAQ_Callback, (usb_dmaq_CB)USB2UART_RX_DMAQ_Empty_Callback,(void *)&USB2UARTPort[usb_port].port_no);
			}
			else
			{
				p_GPD = (TGPD *)buffaddr;
				do{
					p_GPD->ZTepFlag = (g_UsbACM[usb_port].rxpipe->byEP); //EP
					if (p_GPD->pNext == NULL)
						p_GPD->pNext = &USB_DMAQ_RX_GPD_NULL;
					p_GPD = p_GPD->pNext;
				}while(p_GPD != (&USB_DMAQ_RX_GPD_NULL));
				
				drv_trace2(TRACE_FUNC, (kal_uint32)USB_DMAQ_RXGPD_INSERT,	(kal_uint32)USB_DMAQ_RX_GPD_HEADER, (kal_uint32)buffaddr);
				USB_DMAQ_Insert(g_UsbACM[usb_port].rxpipe->byEP, USB_EP_RX_DIR, (kal_uint32)USB_DMAQ_RX_GPD_HEADER, (kal_uint32) buffaddr);
			}
			
			if(USB_Get_UnMask_Irq() == KAL_TRUE)
				USB_UnMask_USB_CORE((USB_MASK_OWNER) usb_port); //IRQUnmask(IRQ_USB_CODE);
				
			return 0;
		}
#endif
	}
	return 0;
#else
	return 0;
#endif
}

	
static kal_uint16 USB_Send_Data(UART_PORT port, kal_uint8 *buffaddr, kal_uint16 length, module_type ownerid)//,USB_Transfer_type transfer_type)
{
	kal_uint32 usb_port = USB_PORT[port];
#if defined(__MBIM_SUPPORT__)||defined(__ECM_SUPPORT__)
	TGPD *p_GPD = NULL;
#endif

	if(g_UsbACM[usb_port].transfer_type == CDC_NORMAL)
	{
		return USB2UART_PutBytes(port, buffaddr, length, ownerid);
	}
#ifdef  __USB_HIGH_SPEED_COM_PORT_ENABLE__
	else if ((g_UsbACM[usb_port].transfer_type == CDC_HIGH_SPEED)||(g_UsbACM[usb_port].transfer_type == CDC_HIGH_SPEED_FRAME))
	{
		return USB_HighSpeed_PutBytes(port, buffaddr, length,ownerid,KAL_TRUE);
	}
#if defined(__MBIM_SUPPORT__)||defined(__ECM_SUPPORT__)
	else if (g_UsbACM[usb_port].transfer_type == CDC_HIGH_SPEED_FRAME_DMAQ)
	{
		if (buffaddr == NULL)
				ASSERT(0);
				
		if ((USB_Is_Suspend_Power_Status() == KAL_TRUE)&&(gUsbDevice.remoteWk == KAL_TRUE))
		{
			DclUSB_DRV_Control(g_USB_Dcl_Handle, USB_DRV_CMD_REMOTE_WAKEUP, NULL);
		}

		if (USB_DMAQ_TX_GPD_HEADER == NULL || USB_DMAQ_TX_GPD_HEADER == (&USB_DMAQ_TX_GPD_NULL))
		{
			USB_DMAQ_TX_GPD_HEADER = (TGPD *)buffaddr;
			p_GPD = (TGPD *)buffaddr;;
			do{
				if (p_GPD->pNext == NULL)
					p_GPD->pNext = &USB_DMAQ_TX_GPD_NULL;
				p_GPD = p_GPD->pNext;
			}while(p_GPD != (&USB_DMAQ_TX_GPD_NULL));
			
			drv_trace2(TRACE_FUNC, (kal_uint32)USB_DMAQ_TXGPD_SETUP, (kal_uint32)buffaddr, (kal_uint32)USB_DMAQ_TX_GPD_HEADER);
			
			USB_DMAQ_TX_GPD_QUEUED = NULL;
			USB_DMAQ_Setup(g_UsbACM[usb_port].txpipe->byEP, USB_EP_TX_DIR, KAL_TRUE, (kal_uint32) buffaddr, (usb_dmaq_CB)USB2UART_TX_DMAQ_Callback, (usb_dmaq_CB)USB2UART_TX_DMAQ_Empty_Callback,(void *)&USB2UARTPort[usb_port].port_no);
		}
		else
		{
			
			//IRQMask(IRQ_USB_CODE);
			if (USB_DMAQ_TX_GPD_HEADER == NULL || USB_DMAQ_TX_GPD_HEADER == (&USB_DMAQ_TX_GPD_NULL))
				ASSERT(0);
				
			//insert null packet at tail
			p_GPD = (TGPD *)buffaddr;
			do{
				if (p_GPD->pNext == NULL)
					p_GPD->pNext = &USB_DMAQ_TX_GPD_NULL;
				p_GPD = p_GPD->pNext;
			}while(p_GPD != (&USB_DMAQ_TX_GPD_NULL));
			
			//insert queue
			if (USB_DMAQ_TX_GPD_QUEUED == NULL)
			{
				USB_DMAQ_TX_GPD_QUEUED = (TGPD *)buffaddr;
			}
			else
			{
				p_GPD = (TGPD *)USB_DMAQ_TX_GPD_QUEUED;
				
				do{
					if (p_GPD->pNext == (&USB_DMAQ_TX_GPD_NULL))
						p_GPD->pNext = (TGPD *)buffaddr;
					p_GPD = p_GPD->pNext;
				}while(p_GPD != ((TGPD *)buffaddr));
			}
			//if(USB_Get_UnMask_Irq() == KAL_TRUE)
			//	IRQUnmask(IRQ_USB_CODE);
			
			drv_trace2(TRACE_FUNC, (kal_uint32)USB_DMAQ_TXGPD_INSERT,	(kal_uint32)USB_DMAQ_TX_GPD_HEADER, (kal_uint32)buffaddr);
		}
		return 0;
	}
#endif
	return 0;
#else
	return 0;
#endif	
	
}

static kal_uint16 USB_Send_ISR_Data(UART_PORT port, kal_uint8 *buffaddr, kal_uint16 length, module_type ownerid,kal_uint8 mode, kal_uint8 escape_char)//,USB_Transfer_type transfer_type)
{
	kal_uint32 usb_port = USB_PORT[port];

	if(g_UsbACM[usb_port].transfer_type == CDC_NORMAL)
	{
//		return USB2UART_Send_ISRData(port, buffaddr, length,mode, escape_char, ownerid);
		return USB2UART_Send_ISRData(port, buffaddr, length, ownerid);
	}
#ifdef  __USB_HIGH_SPEED_COM_PORT_ENABLE__

	else if(g_UsbACM[usb_port].transfer_type == CDC_HIGH_SPEED)
	{
		return USB_HighSpeed_PutBytes(port, buffaddr, length,ownerid,KAL_FALSE);
	}
#endif	
	else
		return 0;
}

#endif   /* __USB_HIGH_SPEED_COM_PORT_ENABLE__ */


#if defined(__USB_LIMIT__)

static void USB_DMA_Limit(UART_PORT port, module_type ownerid,kal_uint32 dma_limit_num)
{
	kal_uint32 usb_port = USB_PORT[port];

	USB_Check_Owner(ownerid,USB2UARTPort[usb_port].ownerid);
	usb_drv_trace4(ownerid, (kal_uint32)USBACM_SET_DMA_LIMITER, ownerid, dma_limit_num, usb_port, 0);
	USB2UART_Set_DMA_Limiter(dma_limit_num);
}


static void USB_DMA_Free(UART_PORT port, module_type ownerid)
{
	kal_uint32 usb_port = USB_PORT[port];

	USB_Check_Owner(ownerid,USB2UARTPort[usb_port].ownerid);	
	usb_drv_trace2(ownerid, (kal_uint32)USBACM_CLEAR_DMA_LIMITER, ownerid, usb_port);
	USB2UART_Clear_DMA_Limiter();
}

#endif

#ifdef  DRV_USB_HW_TX_DIRECT_PATH_SUPPORT
extern void USB_EP_Bulk_HW_TxPktRdy_Enable(kal_uint32 ep_num, kal_bool enable);
static kal_bool USB_Enable_TX_Direct_Path(UART_PORT port, kal_bool enable, module_type ownerid)
{
	kal_uint32 usb_port = USB_PORT[port];
	kal_uint32 count = 0;
	DCL_STATUS return_status = STATUS_OK;
	kal_uint16  buf_status;
	//kal_uint32  savedMask;
	BUFFER_INFO 	*tx_info = &(USB2UARTPort[usb_port].Tx_Buffer);
	
	USB_Check_Owner(ownerid,USB2UARTPort[usb_port].ownerid);
	
	
	if (enable == KAL_TRUE)
	{
		if(g_UsbACM[usb_port].b_is_tx_direct_path_enable == KAL_TRUE)
			ASSERT(0);
		
		if (USB_Get_Device_State() == DEVSTATE_CONFIG)
		{
			/*check enumeration done! if NOT, ASSER*/
			while((g_UsbACM[usb_port].setup_dma == KAL_TRUE)&&(count != USBACM_DIRECT_PATH_LOOP))
			{
				count++;
				kal_sleep_task(1);
			}			
			
			if (count == USBACM_DIRECT_PATH_LOOP)
			{
				return_status = STATUS_FAIL;
				ASSERT(0);
			}
			else
			{
				/*if working buffer still has data, flush it??????*/
				Buf_IsEmpty(tx_info, buf_status);
				if (buf_status != Buff_isEmpty)
				{
				
					ASSERT(0);
				
				
					//savedMask = SaveAndSetIRQMask();
					//if(g_UsbACM[usb_port].txpipe != NULL)
					//{
					//	if(g_UsbACM[usb_port].setup_dma == KAL_FALSE)
					//	{
					//		g_UsbACM[usb_port].setup_dma = KAL_TRUE;
					//		setup_dma = KAL_TRUE;
					//	}
					//	else
					//	{
					//		ASSERT(0);
					//	}
					//}
					//RestoreIRQMask(savedMask);
					//
					////usb_drv_trace2(ownerid, (kal_uint32)USBACM_PUT_BYTES, real_count, usb_port);
			                //
					//if(setup_dma == KAL_TRUE)
					//{
					//	USB_Dbg_Trace(USB_ACM_DMA_SETUP_1, (kal_uint32)port, 0);
					//	USB2UART_DMATransmit(port, KAL_TRUE);
					//}
				}
			}
			g_UsbACM[usb_port].b_is_tx_direct_path_enable = KAL_TRUE;
			
			USB_EP_Bulk_HW_TxPktRdy_Enable(g_UsbACM[usb_port].txpipe->byEP, enable);
			
		}
		else
		{
			return_status = STATUS_FAIL;
		}
	}
	else
	{
		if(g_UsbACM[usb_port].b_is_tx_direct_path_enable == KAL_FALSE)
			ASSERT(0);
			
		g_UsbACM[usb_port].b_is_tx_direct_path_enable = KAL_FALSE;
		USB_EP_Bulk_HW_TxPktRdy_Enable(g_UsbACM[usb_port].txpipe->byEP, enable);
	}
	
	return (kal_bool)return_status;
}
#endif /*#ifdef  DRV_USB_HW_TX_DIRECT_PATH_SUPPORT*/

#endif /*__USB_COM_PORT_ENABLE__*/


