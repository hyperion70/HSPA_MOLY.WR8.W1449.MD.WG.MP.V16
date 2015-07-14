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
 * tst_hal_internal_wrapper_defs.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file implements HAL wrapper layer for interface transition
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
 *
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __TST_HAL_INTERNAL_WRAPPER_DEFS_H__
#define __TST_HAL_INTERNAL_WRAPPER_DEFS_H__

#include "kal_public_api.h"
#include "dcl.h"

//defs
typedef enum
{
  TST_PS_Port_Item,
  TST_L1_Port_Item,
  TST_RX_Port_Item,
  TST_Postman_Port_Item,
  TST_DSP_Port_Item,
  TST_Max_Port_Item
}
TST_UartPort_handle_mapping_t;

//UART wrapper interface


//UART_GetTxISRRoomLeft
#define HAL_UART_GET_TXISR_ROOMLEFT(room_left, port) \
        do{\
          UART_CTRL_RX_AVAIL_T data;\
          DclSerialPort_Control(uart_handle,SIO_CMD_GET_ISR_TX_AVAIL, (DCL_CTRL_DATA_T*)&data);\
          room_left = data.u2RetSize;\
        while(0)      

//RTC wrapper layer

//function declarations
void tst_hal_uart_handler_init(DCL_DEV port);
kal_uint16 tst_hal_UART_SendISRData(DCL_DEV port, kal_uint8 *Buffaddr, kal_uint16 Length,kal_uint8 mode, kal_uint8 escape_char, module_type ownerid);
kal_uint16 tst_hal_UART_PutISRBytes(DCL_DEV port, kal_uint8 *Buffaddr, kal_uint16 Length, module_type ownerid);
kal_uint16 tst_hal_UART_PutBytes(DCL_DEV port, kal_uint8 *Buffaddr, kal_uint16 Length, module_type ownerid);
void tst_hal_UART_Boot_PutUARTBytes(DCL_DEV port, kal_uint8 *Buffaddr, kal_uint16 Length);
kal_bool tst_hal_UART_Open(DCL_DEV port, module_type ownerid);
void tst_hal_UART_Close(DCL_DEV port, module_type ownerid);
void tst_hal_UART_SetDCBConfig(DCL_DEV port, UART_CONFIG_T *UART_Config, module_type ownerid);
void tst_hal_UART_VFIFO_TX_DMA_Enable(DCL_DEV port, kal_bool enable);
void tst_hal_PutUARTBytes(DCL_DEV port, kal_uint8 *data, kal_uint16 len);
void tst_hal_PutUARTByte(DCL_DEV port, kal_uint8 data);
void tst_hal_UART_SleepOnTx_Enable(DCL_DEV port, UART_SLEEP_ON_TX_T flag);
void tst_hal_UART_SetBaudRate(DCL_DEV port, UART_BAUDRATE_T baudrate, module_type ownerid);
void tst_hal_UART_AssertWaitPrevDataSentOut(DCL_DEV port);
module_type tst_hal_UART_GetOwnerID(DCL_DEV port);
void tst_hal_UART_Purge(DCL_DEV port, UART_BUFFER_T dir, module_type ownerid);
kal_uint8 tst_hal_GetUARTByte(DCL_DEV port);
kal_uint8 tst_hal_GetUARTByte_WithTimeOut(DCL_DEV port, kal_uint8* ch, kal_uint32 timeout_val);
kal_uint16 tst_hal_UART_GetBytes(DCL_DEV port, kal_uint8 *Buffaddr, kal_uint16 Length, kal_uint8 *status, module_type ownerid);
void tst_hal_UART_Register_RX_cb(DCL_DEV port, module_type ownerid, DCL_UART_RX_FUNC func);
void tst_hal_UART_Register_TX_cb(DCL_DEV port, module_type ownerid, DCL_UART_TX_FUNC func);
void tst_hal_PW_Set_Switch2Idle_Flag(void);
void tst_hal_WDT_Enable_Debug_Mode(kal_bool en,PFN_DCL_CALLBACK callback);
void tst_hal_DRV_ABN_RESET(void);
kal_uint16 tst_hal_UART_SendData(DCL_DEV port, kal_uint8 *Buffaddr, kal_uint16 Length,kal_uint8 mode,kal_uint8 escape_char, module_type ownerid );
void tst_hal_UART_SwitchPort(DCL_DEV *APP_port, DCL_DEV new_uart_port);
kal_bool tst_hal_USBDL_Is_USB_Download_Mode(void);
kal_bool tst_hal_USB_Meta_Mode(DCL_CTRL_CMD dcl_cmd);
kal_bool tst_hal_USBDL_Is_USB_Fast_Meta_Mode(void);
kal_uint16 tst_sendISRLog(DCL_DEV port, UART_FLOW_CTRL_MODE_T fc, kal_uint8 *Buffaddr, kal_uint16 Length);
void tst_sendISRLog_exception(DCL_DEV port, UART_FLOW_CTRL_MODE_T fc, kal_uint8 *Buffaddr, kal_uint16 Length);
kal_uint16 tst_sendLog(DCL_DEV port, UART_FLOW_CTRL_MODE_T fc, kal_uint8 *Buffaddr, kal_uint16 Length);
void tst_hal_UART_Register_DMA_TX_Callback(DCL_DEV port, module_type ownerid, DCL_UART_TX_FUNC func);
kal_uint32 tst_hal_UART_GetTxISR_RoomLeft(DCL_DEV port);
kal_uint16 tst_hal_UART_DMA_PutBytes(DCL_DEV port, kal_uint8 *buffaddr, kal_uint16 length, module_type ownerid);
kal_uint16 tst_hal_UART_DMA_PutISRBytes(DCL_DEV port, kal_uint8 *buffaddr, kal_uint16 length, module_type ownerid);
kal_uint16 tst_hal_UART_DMA_GetBytes(DCL_DEV port, kal_uint8 **buffaddr, kal_uint8 *status, module_type ownerid);
kal_bool tst_hal_UART_DMAIF_Enable(DCL_DEV port, kal_bool enable);
void tst_hal_USB_Acm_Ring_Buffer_Threshold_Enable(DCL_DEV port, kal_bool bset, module_type ownerid);
void tst_hal_USB2UART_Tx_DMA_Callback(DCL_DEV port);
kal_uint8 tst_hal_USB_Acm_FT_Port(void);

kal_uint16 tst_hal_USB_HS_GetBytes(DCL_DEV port, kal_uint8 **buffaddr, kal_uint8 *status, module_type ownerid);
kal_uint16 tst_hal_USB_HS_PutBytes(DCL_DEV port, kal_uint8 *buffaddr, kal_uint16 length, module_type ownerid);
kal_bool tst_hal_USB_HS_DMAIF_Enable(DCL_DEV port, kal_bool enable);
kal_bool tst_hal_USB_HSTX_DMAIF_Enable(DCL_DEV port, kal_bool enable); // arvin
void tst_hal_USB_HS_Register_DMA_TX_Callback(DCL_DEV port, module_type ownerid, DCL_UART_TX_FUNC func);

kal_uint32 tst_hal_USB_DirectPath_GetMPS(void);
kal_uint32 tst_hal_USB_DirectPath_GetTX_EPNum(DCL_DEV port);
kal_uint32 tst_hal_USB_DirectPath_GetRX_EPNum(DCL_DEV port);
kal_bool tst_hal_USB_DirectPath_Enable(DCL_DEV port, kal_bool enabled);
kal_uint32 tst_hal_USB_DirectPath_GetTXAddr(DCL_DEV port);
kal_uint32 tst_hal_USB_DirectPath_GetHWFIFOAddr(DCL_DEV port);
kal_uint32 tst_hal_USB_DirectPath_SetTxPktRdy(DCL_DEV port);

kal_bool tst_hal_UART_QueryDMA_SINGULAR_DataLeft(DCL_DEV port);

#endif  //__TST_HAL_INTERNAL_WRAPPER_DEFS_H__
