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
 *    usbacm_drv.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file implements usb CDC ACM class driver
 *
 * Author:
 * -------
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifdef __USB_COM_PORT_ENABLE__

#include "intrCtrl.h"
//#include "stack_common.h"
#include "kal_public_defs.h" //MSBB change #include "stack_msgs.h"
#include "drv_comm.h"
//#include "gpt_sw.h"
#include "dcl.h"
//#include "app_ltlcom.h"       /* Task message communiction */
#include "syscomp_config.h"
#include "usb_comm.h"
//#include "usb_task.h"
//#include "usb_drv.h"
#include "usb_adap.h"
#include "usb.h"
#include "usb_resource.h"
#include "usbacm_drv.h"
#include "usbacm_adap.h"
#include "usb_custom.h"
#include "usb_custom_def.h"

#include "usb_debug_tool.h"
#include "usb_trc.h"
#include "usb_mode.h"

#include "uart_sw.h"
//#include "kal_non_specific_general_types.h"
//#include "kal_release.h"
#include "bmd.h"
#include "kal_public_defs.h" //MSBB change #include "stack_config.h"
#include "kal_trace.h"
#include "kal_general_types.h"
#include "kal_public_api.h"

#ifdef __USB_STRESS_TEST__
#include "usbacm_echo.h"
extern void USB_ECHO_TEST(void);
#endif

#include "drv_msgid.h"
#include "ps_public_ups_def.h"


#if defined(__MBIM_SUPPORT__)||defined(__ECM_SUPPORT__)
extern TGPD USB_DMAQ_RX_GPD_NULL;
extern TGPD *USB_DMAQ_RX_GPD_HEADER;
extern TGPD USB_DMAQ_TX_GPD_NULL;
extern TGPD *USB_DMAQ_TX_GPD_HEADER;
#endif

#if defined(__MBIM_SUPPORT__)
extern void mbim_sio_getNtbParameters(kal_uint16 **ntb_ptr, kal_uint8 *len);
extern void mbim_sio_getNetAddress(kal_uint8 **addr_ptr, kal_uint8 *len);
extern void mbim_sio_setNtbInputSize(kal_uint32 size);
extern void mbim_sio_getNtbInputSize(kal_uint32 *size);
#endif

#if defined__ECM_SUPPORT__
extern void ecm_sio_getNetAddress(kal_uint16 **addr_ptr);
extern void ecm_sio_setEthernetPowerManagementPatternFilter(kal_uint32 index, kal_uint32 length, kal_uint8 *data);
extern kal_uint16 ecm_sio_getEthernetPowerManagementPatternFilter(kal_uint32 index);
extern kal_uint32 ecm_sio_getEthernetStatistic(kal_uint32 index);
extern void ecm_sio_setEthernetPacketFilter(kal_uint16 filter);
#endif

/* Global variables */
UsbUARTStruct USB2UARTPort[MAX_USB_PORT_NUM];
UsbAcm_Struct g_UsbACM[MAX_USB_PORT_NUM];
UsbAcm_Common_Struct g_UsbACM_Comm;
kal_uint8 USB_PORT[uart_max_port];

#ifdef  __USB_HIGH_SPEED_COM_PORT_ENABLE__
  usb_dma_callback usb_hs_tx_reg_cb;
	#if defined(__USB_MULTIPLE_COMPORT_SUPPORT__)
	usb_dma_callback usb2_hs_tx_reg_cb;
	#endif
  #if defined (__USB_MODEM_CARD_SUPPORT__)
  usb_dma_callback usb3_hs_tx_reg_cb;
  usb_dma_callback usb4_hs_tx_reg_cb;
  usb_dma_callback usb5_hs_tx_reg_cb;
  #endif
#endif  //#ifdef  __USB_HIGH_SPEED_COM_PORT_ENABLE__


#if defined(DRV_USB_DMA_QUEUE_SUPPORT)

#ifdef __MTK_TARGET__
__attribute__ ((section ("NONCACHEDZI"), aligned(4))) 
#endif /* __MTK_TARGET__ */
TGPD USB_DMAQ_PPP_TX_GPD[2];

#ifdef __MTK_TARGET__
__attribute__ ((section ("NONCACHEDZI"), aligned(4))) 
#endif /* __MTK_TARGET__ */
TGPD USB_DMAQ_PPP_RX_GPD[2];

#endif

/* Exception flag */
extern kal_uint8 INT_Exception_Enter;
#if defined(__USB_BOOTUP_TRACE__)
extern kal_bool is_init_log_enable;
extern kal_bool is_init_stage;
#endif

/* extern functions */
extern kal_uint16 USB2UART_GetBuffRoomLeft(BUFFER_INFO *buf_info);

/* for DMA tx buffer and tx_isr buffer to differentiate */
static USBTRX_MEM_TYPE USB2Uart_MemType[MAX_USB_PORT_NUM];
static kal_uint32 USB2Uart_WriteLength[MAX_USB_PORT_NUM];

/* Static functions */
static void USB2UART_LineCoding2DCB(UsbAcm_Line_Coding *pline_coding, UARTDCBStruct *pDCB);
static kal_uint32 USB2UART_Check_Transmit_Data(UART_PORT port, kal_uint32* addr, kal_bool b_check);
static void USB2UART_Update_Transmit_Data(UART_PORT port);
void USB2UART_Tx_DMA_Callback(UART_PORT port);
static kal_uint8 USB_Acm_Get_DataIf_Num(UART_PORT port);
static void USB_Acm_CommIf_Create(UART_PORT port, void *ifname);
static void USB_Acm_CommIf_Reset(UART_PORT port);
static void USB_Acm_CommIf_Enable(UART_PORT port);
static void USB_Acm_CommIf_Speed_Reset(UART_PORT port, kal_bool b_other_speed);
static void USB_Acm_DataIf_Create(UART_PORT port, void *ifname);
static void USB_Acm_DataIf_Reset(UART_PORT port);
static void USB_Acm_DataIf_Enable(UART_PORT port);
static void USB_Acm_DataIf_Speed_Reset(UART_PORT port, kal_bool b_other_speed);
static void USB_Acm_Break_Timeout(void *parameter);
static void USB_Acm_Ring_Buffer_Timeout(void *parameter);
#if 0 //disable DMAlog
/* under construction !*/
#endif
static void USB_Acm_Ep0_SetLineCoding(UART_PORT port, void *data);
static void USB_Acm1_Ep0_SetLineCoding(void *data);
static void USB_Acm_Ep0_Command(UART_PORT port, Usb_Ep0_Status* pep0state, Usb_Command* pcmd);
static void USB_Acm1_Ep0_Command(Usb_Ep0_Status* pep0state, Usb_Command* pcmd);
static void USB_Acm_BulkOut_Hdr(UART_PORT port);
static void USB_Acm1_BulkOut_Hdr(void);
static void USB_Acm_BulkIn_Reset(UART_PORT port);
static void USB_Acm1_BulkIn_Reset(void);
static void USB_Acm_BulkOut_Reset(UART_PORT port);
static void USB_Acm1_BulkOut_Reset(void);
static void USB_Acm_IntrIn_Hdlr(UART_PORT port);
static void USB_Acm1_IntrIn_Hdlr(void);
static void USB_Acm_IntrIn_Reset(UART_PORT port);
static void USB_Acm1_IntrIn_Reset(void);
#if defined(__USB_MULTIPLE_COMPORT_SUPPORT__)
static void USB_Acm2_Ep0_SetLineCoding(void *data);
static void USB_Acm2_Ep0_Command(Usb_Ep0_Status* pep0state, Usb_Command* pcmd);
static void USB_Acm2_BulkOut_Hdr(void);
static void USB_Acm2_BulkIn_Reset(void);
static void USB_Acm2_BulkOut_Reset(void);
static void USB_Acm2_IntrIn_Hdlr(void);
static void USB_Acm2_IntrIn_Reset(void);

#if defined (__USB_MODEM_CARD_SUPPORT__)
static void USB_Acm3_Ep0_SetLineCoding(void *data);
static void USB_Acm3_Ep0_Command(Usb_Ep0_Status* pep0state, Usb_Command* pcmd);
static void USB_Acm3_BulkOut_Hdr(void);
static void USB_Acm3_BulkIn_Reset(void);
static void USB_Acm3_BulkOut_Reset(void);
static void USB_Acm3_IntrIn_Hdlr(void);
static void USB_Acm3_IntrIn_Reset(void);

static void USB_Acm4_Ep0_SetLineCoding(void *data);
static void USB_Acm4_Ep0_Command(Usb_Ep0_Status* pep0state, Usb_Command* pcmd);
static void USB_Acm4_BulkOut_Hdr(void);
static void USB_Acm4_BulkIn_Reset(void);
static void USB_Acm4_BulkOut_Reset(void);
static void USB_Acm4_IntrIn_Hdlr(void);
static void USB_Acm4_IntrIn_Reset(void);

static void USB_Acm5_Ep0_SetLineCoding(void *data);
static void USB_Acm5_Ep0_Command(Usb_Ep0_Status* pep0state, Usb_Command* pcmd);
static void USB_Acm5_BulkOut_Hdr(void);
static void USB_Acm5_BulkIn_Reset(void);
static void USB_Acm5_BulkOut_Reset(void);
static void USB_Acm5_IntrIn_Hdlr(void);
static void USB_Acm5_IntrIn_Reset(void);
#endif

#if defined(__USB_TETHERING__)
static void USB_ISD_Ep0_SendEncapsulated(void *data);
static void USB_ISD_Ep0_Command(Usb_Ep0_Status* pep0state, Usb_Command* pcmd);
static void USB_ISD_IntrIn_Hdlr(void);
static void USB_ISD_IntrIn_Reset(void);
static void USB_ISD_BulkOut_Hdr(void);
static void USB_ISD_BulkIn_Reset(void);
static void USB_ISD_BulkOut_Reset(void);
#endif


#endif
static void USB_Acm_FT_BulkOut_Hdr(void);

static const kal_uint8 cdcacm_com_if_dscr[]=
{
	USB_IFDSC_LENGTH,	//bLength;
	USB_INTERFACE,	//bDescriptorType;
	0x00,	//bInterfaceNumber;
	0x00,	//bAlternateSetting;
	USB_CDC_ACM_COMM_EP_NUMBER,	//bNumEndpoints;
	USB_ACM_COMM_INTERFACE_CLASS_CODE,	//bInterfaceClass;
	USB_ACM_COMM_INTERFACE_SUBCLASS_CODE,	//bInterfaceSubClass;
	USB_ACM_COMM_INTERFACE_PROTOCOL_CODE,	//bInterfaceProtocol;
	0x00,	//iInterface;

	0x05,	//HFbFunctionLength;		/*Header Functional Descriptor*/
	0x24,	//HFbDescriptorType;
	0x00,	//HFbDescriptorSubtype;
	0x10,	//bcdCDC;
	0x01,	//bcdCDC;

	0x04,	//ACMFbFunctionLength;	/*Abstract Control Management Functional Descriptor*/
	0x24,	//ACMFbDescriptorType;
	0x02,	//ACMFbDescriptorSubtype;
	0x0f,	//ACMFbmCapabilities;

	0x05,	//UFbFunctionLength;		/*Union Functional Descriptor*/
	0x24,	//UFbDescriptorType;
	0x06,	//UFbDescriptorSubtype;
	0x00,	//bMasterInterface;
	0x00,	//bSlaveInterface0;

	0x05,	//CMFbFunctionLength;	/*Call Management Descriptor*/
	0x24,	//CMFbDescriptorType;
	0x01,	//CMFbDescriptorSubtype;
	0x03,	//CMFbmCapabilities;
	0x00	//bDataInterface;
};

const kal_uint8 cdcacm_intr_dscr[]=
{
	USB_EPDSC_LENGTH,	//bLength;
	USB_ENDPOINT,	//bDescriptorType;
	0x00,	//bEndpointAddress;
	USB_EP_INTR,	//bmAttributes;
	USB_EP_INTR_MAXP&0xff,	//wMaxPacketSize[2];	
	0x00,	//wMaxPacketSize[2];	
	0x03	//bInterval;
};



const kal_uint8 cdcacm_data_if_dscr[]=
{
	USB_IFDSC_LENGTH,	//bLength;
	USB_INTERFACE,	//bDescriptorType;
	0,	//bInterfaceNumber;
	0,	//bAlternateSetting;
	USB_CDC_ACM_DATA_EP_NUMBER,	//bNumEndpoints;
	USB_ACM_DATA_INTERFACE_CLASS_CODE,	//bInterfaceClass;
	USB_ACM_DATA_INTERFACE_SUBCLASS_CODE,	//bInterfaceSubClass;
	USB_ACM_DATA_INTERFACE_PROTOCOL_CODE,	//bInterfaceProtocol;
	0	//iInterface;
};


const kal_uint8 cdcacm_ep_in_dscr[]=
{
	USB_EPDSC_LENGTH,	//bLength;
	USB_ENDPOINT,	//bDescriptorType;
	0x00,	//bEndpointAddress;
	USB_EP_BULK,	//bmAttributes;
	0x40,	//wMaxPacketSize[2];	
	0x00,	//wMaxPacketSize[2];	
	0x00	//bInterval;
};

const kal_uint8 cdcacm_ep_out_dscr[]=
{
	USB_EPDSC_LENGTH,	//bLength;
	USB_ENDPOINT,	//bDescriptorType;
	0x00,	//bEndpointAddress;
	USB_EP_BULK,	//bmAttributes;
	0x40,	//wMaxPacketSize[2];	
	0x00,	//wMaxPacketSize[2];	
	0x00	//bInterval;
};

#if (defined(__USB_COMPORT_SUPPORT_TC01_DRIVER__)&&defined(__USB_MULTIPLE_COMPORT_SUPPORT__))
const kal_uint8 cdcacm_TC01_data_if_dscr[]=
{
	USB_IFDSC_LENGTH,	//bLength;
	USB_INTERFACE,	//bDescriptorType;
	0,	//bInterfaceNumber;
	0,	//bAlternateSetting;
	USB_CDC_ACM_DATA_EP_NUMBER,	//bNumEndpoints;
	0xFF,	//bInterfaceClass;
	0xFF,	//bInterfaceSubClass;
	0xFF,	//bInterfaceProtocol;
	0	//iInterface;
};

#endif


void USB_UnMask_COM_Intr(UART_PORT port)
{
#if (defined(DRV_USB_IP_V1)||defined(DRV_USB_IP_V1_PLUS))
	if(port == uart_port_usb)
		USB_UnMask_Irq(USB_MASK_OWNER_COM_1);
#if defined(__USB_MULTIPLE_COMPORT_SUPPORT__)
	else if(port == uart_port_usb2)
		USB_UnMask_Irq(USB_MASK_OWNER_COM_2);	
#if defined (__USB_MODEM_CARD_SUPPORT__)
	else if(port == uart_port_usb3)
		USB_UnMask_Irq(USB_MASK_OWNER_COM_3);
	else if(port == uart_port_usb4)
		USB_UnMask_Irq(USB_MASK_OWNER_COM_4);
	else if(port == uart_port_usb5)
		USB_UnMask_Irq(USB_MASK_OWNER_COM_5);
#endif	
#endif
#else
	kal_uint32 usb_port = USB_PORT[port];
    if(g_UsbACM[usb_port].rxpipe != NULL)
    {
    USB_RxEPEn(g_UsbACM[usb_port].rxpipe->byEP, USB_ENDPT_BULK, USB_EP_USE_NO_DMA, KAL_FALSE, KAL_TRUE);   
    }
#endif
}


void USB_Mask_COM_Intr(UART_PORT port)
{
#if (defined(DRV_USB_IP_V1)||defined(DRV_USB_IP_V1_PLUS))
	if(port == uart_port_usb)
		USB_Mask_Irq(USB_MASK_OWNER_COM_1);
#if defined(__USB_MULTIPLE_COMPORT_SUPPORT__)
	else if(port == uart_port_usb2)
		USB_Mask_Irq(USB_MASK_OWNER_COM_2);
#if defined (__USB_MODEM_CARD_SUPPORT__)
	else if(port == uart_port_usb3)
		USB_Mask_Irq(USB_MASK_OWNER_COM_3);
	else if(port == uart_port_usb4)
		USB_Mask_Irq(USB_MASK_OWNER_COM_4);
	else if(port == uart_port_usb5)
		USB_Mask_Irq(USB_MASK_OWNER_COM_5);
#endif	
   #endif
#else
  kal_uint32 usb_port = USB_PORT[port];
  if(g_UsbACM[usb_port].rxpipe != NULL)
  {
  USB_RxEPDis(g_UsbACM[usb_port].rxpipe->byEP, USB_EP_USE_NO_DMA);							   
  }
#endif
}

static usb_dma_callback  USB_COM_DMA_Callback(UART_PORT port) 
{
	if(port == uart_port_usb)
		return  USB2UART_Tx_DMA1_Callback;
#if defined(__USB_MULTIPLE_COMPORT_SUPPORT__)
	else if(port == uart_port_usb2)
		return  USB2UART_Tx_DMA2_Callback;
#if defined (__USB_MODEM_CARD_SUPPORT__)
	else if(port == uart_port_usb3)
		return USB2UART_Tx_DMA3_Callback;
	else if(port == uart_port_usb4)
		return USB2UART_Tx_DMA4_Callback;
	else if(port == uart_port_usb5)
		return USB2UART_Tx_DMA5_Callback;
#endif
#endif
	return NULL;

}

/*************************************************************
  translate ACM and UART setting functions
**************************************************************/

/* Translate ACM line coding to UART DCB */
static void USB2UART_LineCoding2DCB(UsbAcm_Line_Coding *pline_coding, UARTDCBStruct *pDCB)
{
	pDCB->baud = (UART_baudrate)(pline_coding->dwDTERate);
	pDCB->stopBits = (UART_stopBits)(pline_coding->bCharFormat+1);
	pDCB->parity = (UART_parity)(pline_coding->bParityType);
	pDCB->dataBits = (UART_bitsPerCharacter)(pline_coding->bDataBits);
}


/* Translate UART DCB to ACM line coding */
void UART2USB_DCB2LineCoding(UARTDCBStruct *pDCB, UsbAcm_Line_Coding *pline_coding)
{
	pline_coding->dwDTERate = (kal_uint32)(pDCB->baud);
	pline_coding->bCharFormat = (kal_uint8)(pDCB->stopBits)-1;
	pline_coding->bParityType = (kal_uint8)(pDCB->parity);
	pline_coding->bDataBits = (kal_uint8)(pDCB->dataBits);
}

/************************************************************
	GPT timeout handle escape character detect
*************************************************************/

/* GPT timer handler for Escape character detect */
void USB2UART_Timeout(void *parameter)
{
	UsbUARTStruct *UARTData = (UsbUARTStruct *)parameter;
	
	USB_GPTI_StopItem(UARTData->handle);
//	DclSGPT_Control((DCL_HANDLE)(UARTData->handle), SGPT_CMD_STOP, 0);

	USB_Dbg_Trace(USB_ACM_TIMEOUT, 0 , (kal_uint32)UARTData->Rec_state);

	UARTData->EscCount = 0;

	switch(UARTData->Rec_state)
	{
	case UART_Get3EscChar:
		/* Escape detect */
		UARTData->EscFound = KAL_TRUE;
		UARTData->Rec_state = UART_RecNormal;
		USB2UART_Sendilm(UARTData->port_no, MSG_ID_UART_ESCAPE_DETECTED_IND);
		break;
	case UART_RecNormal:
		/* first timeout, start to check escape character */
		UARTData->Rec_state = UART_StartCheckESC;
		break;
	case UART_StartCheckESC:
		UARTData->Rec_state = UART_RecNormal;
		break;
	default:
		ASSERT(0);
		break;
	}
}

void USB2UART_Send_Intr_Pending(kal_uint32 usb_port)
{
	kal_uint32 max_intr_pkt_size;
	kal_uint8  ep_num = g_UsbACM[usb_port].intrpipe->byEP;	
	max_intr_pkt_size = USB_Intr_Max_Packet_Size();

	
	if(max_intr_pkt_size > sizeof(UsbAcm_Intr_Pkt))
	{
		g_UsbACM[usb_port].intr_state = ACM_INTR_SEND_LAST_PKT;
	
		/* Send only one short packet */
		USB_Dbg_Trace(USB_ACM_SEND_INTERRUPT2, (kal_uint32)g_UsbACM[usb_port].intr_state, 0);
		USB_EPFIFOWrite(ep_num, sizeof(UsbAcm_Intr_Pkt), (kal_uint8 *)&g_UsbACM[usb_port].intr_pkt);
	}
	else
	{
		g_UsbACM[usb_port].intr_state = ACM_INTR_SEND_ONE_PKT;
	
		/* Send one max packet */
		USB_Dbg_Trace(USB_ACM_SEND_INTERRUPT1, (kal_uint32)g_UsbACM[usb_port].intr_state, 0);
		USB_EPFIFOWrite(ep_num, max_intr_pkt_size, (kal_uint8 *)&g_UsbACM[usb_port].intr_pkt);
	}
	
	USB_EP_Tx_Ready(ep_num, USB_ENDPT_INTR);

}

// while using USB catcher log, cannot use TST send USB log (TST stack)
void usb_drv_trace4(module_type ownerid, kal_uint32 msg_index,const char *arg_type, kal_uint32 data1, kal_uint32 data2,kal_uint32 data3, kal_uint32 data4)
{
#if defined(__USB_BOOTUP_TRACE__)
	if ((ownerid != MOD_TST_READER)&&(INT_Exception_Enter == 0 && is_init_log_enable != KAL_TRUE))
#else
	if ((ownerid != MOD_TST_READER)&&(INT_Exception_Enter == 0))
#endif
		drv_trace4(TRACE_FUNC, msg_index, arg_type, data1, data2, data3, data4);
}

void usb_drv_trace2(module_type ownerid, kal_uint32 msg_index,const char *arg_type, kal_uint32 data1, kal_uint32 data2)
{
#if defined(__USB_BOOTUP_TRACE__)
	if ((ownerid != MOD_TST_READER)&&(INT_Exception_Enter == 0 && is_init_log_enable != KAL_TRUE))
#else
	if ((ownerid != MOD_TST_READER)&&(INT_Exception_Enter == 0))
#endif
		drv_trace2(TRACE_FUNC, msg_index, arg_type, data1, data2);
}

void usb_drv_trace1(module_type ownerid, kal_uint32 msg_index,const char *arg_type, kal_uint32 data1)
{
#if defined(__USB_BOOTUP_TRACE__)
	if ((ownerid != MOD_TST_READER)&&(INT_Exception_Enter == 0 && is_init_log_enable != KAL_TRUE))
#else
	if ((ownerid != MOD_TST_READER)&&(INT_Exception_Enter == 0))
#endif
		drv_trace1(TRACE_FUNC, msg_index, arg_type, data1);
}

void usb_drv_trace0(module_type ownerid, kal_uint32 msg_index,const char *arg_type)
{
#if defined(__USB_BOOTUP_TRACE__)
	if ((ownerid != MOD_TST_READER)&&(INT_Exception_Enter == 0 && is_init_log_enable != KAL_TRUE))
#else
	if ((ownerid != MOD_TST_READER)&&(INT_Exception_Enter == 0))
#endif
		drv_trace0(TRACE_FUNC, msg_index, arg_type);
}


void USB_Check_Owner(module_type ownerid,module_type current_ownerid)
{
	if (ownerid != current_ownerid)		
		EXT_ASSERT(0, (kal_uint32)ownerid, (kal_uint32)current_ownerid, 0);		
}


void USB_Acm_Exception_Check(void)
{
	if (USB_Exception_Check() == KAL_TRUE)
		ASSERT(0);
}

/************************************************************
	Default UART callback function. Send ilm to UART owner
*************************************************************/

void USB2UART_Dafault_Tx_Callback(UART_PORT port)
{
	kal_uint32 usb_port = USB_PORT[port];

	if(g_UsbACM[usb_port].send_Txilm == KAL_TRUE)
	{
		USB_Dbg_Trace(USB_ACM_SEND_READY_TO_WRITE, (kal_uint32)port, 0);

		/* Send message to UART owner */
		USB2UART_Sendilm(port, MSG_ID_UART_READY_TO_WRITE_IND);
		g_UsbACM[usb_port].send_Txilm = KAL_FALSE;
		g_UsbACM[usb_port].config_send_Txilm = KAL_FALSE;
	}
}


void USB2UART_Dafault_Rx_Callback(UART_PORT port)
{
	kal_uint32 usb_port = USB_PORT[port];

	if(g_UsbACM[usb_port].send_Rxilm == KAL_TRUE)
	{
		USB_Dbg_Trace(USB_ACM_SEND_READY_TO_READ, (kal_uint32)port, 0);

		/* Send ready to read message to UART onwer if needed */
		USB2UART_Sendilm(port, MSG_ID_UART_READY_TO_READ_IND);
		g_UsbACM[usb_port].send_Rxilm = KAL_FALSE;
	}
}

/************************************************************
	Bulk EP IN handle functions (DMA setup and callback functions)
*************************************************************/

/*
    Determine transmit data
    If return value is large than 0, the caller should send the data in parameter.
     This function and "USB2UART_Update_Transmit_Data" function must be pair.
*/
static kal_uint32 USB2UART_Check_Transmit_Data(UART_PORT port, kal_uint32* addr, kal_bool b_check)
{
	kal_uint32 usb_port = USB_PORT[port];
	kal_uint32 length = 0;
	kal_uint32 savedMask;
//	SGPT_CTRL_START_T start;


	if((g_UsbACM[usb_port].ring_buffer_timer_counting == KAL_TRUE) && (kal_if_lisr() == KAL_FALSE))
	{
		USB_GPTI_StopItem(g_UsbACM[usb_port].ring_buffer_handle);
//		DclSGPT_Control((DCL_HANDLE)(g_UsbACM[usb_port].ring_buffer_handle), SGPT_CMD_STOP, 0);
		g_UsbACM[usb_port].ring_buffer_timer_counting = KAL_FALSE;
	}

	/* First, check if TX ISR buffer has "enough" data to send out */
	/* The data in the ISR TX buffer must be sent out all at one time. Otherwise, the catcher cannot decode the log correctly */
	savedMask = SaveAndSetIRQMask();

	if(USB2UARTPort[usb_port].Tx_Buffer_ISR.Write != USB2UARTPort[usb_port].Tx_Buffer_ISR.Read)
	{
		/* used for callback function to know sent source */
		USB2Uart_MemType[usb_port] = USBTRX_MEM_ISR;
		*addr = (kal_uint32)USB2UARTPort[usb_port].Tx_Buffer_ISR.CharBuffer + USB2UARTPort[usb_port].Tx_Buffer_ISR.Read;

		if(USB2UARTPort[usb_port].Tx_Buffer_ISR.Write >= USB2UARTPort[usb_port].Tx_Buffer_ISR.Read)
		{
			length = USB2UARTPort[usb_port].Tx_Buffer_ISR.Write - USB2UARTPort[usb_port].Tx_Buffer_ISR.Read;

			if(b_check == KAL_TRUE)
			{
				if(length <= (USB2UARTPort[usb_port].Tx_Buffer_ISR.Length/2))
				{
					length = 0;
					g_UsbACM[usb_port].ring_buffer_timer_counting = KAL_TRUE;
				}
			}
		}
		else
		{
			/* ISR TX buffer must have data to send out */
			length = USB2UARTPort[usb_port].Tx_Buffer_ISR.Length - USB2UARTPort[usb_port].Tx_Buffer_ISR.Read;
		}
	}

	/* Check if TX buffer has enough data to send out */
	if((USB2UARTPort[usb_port].Tx_Buffer.Write != USB2UARTPort[usb_port].Tx_Buffer.Read) && (length == 0))
	{
		g_UsbACM[usb_port].ring_buffer_timer_counting = KAL_FALSE;
		/* used for callback function to know sent source */
		USB2Uart_MemType[usb_port] = USBTRX_MEM_TASK;
		*addr = (kal_uint32)USB2UARTPort[usb_port].Tx_Buffer.CharBuffer + USB2UARTPort[usb_port].Tx_Buffer.Read;

		if(USB2UARTPort[usb_port].Tx_Buffer.Write >= USB2UARTPort[usb_port].Tx_Buffer.Read)
		{
			length = USB2UARTPort[usb_port].Tx_Buffer.Write - USB2UARTPort[usb_port].Tx_Buffer.Read;
#ifndef __L1_STANDALONE__
			if(b_check == KAL_TRUE)
			{
				if(length <= (USB2UARTPort[usb_port].Tx_Buffer.Length/2))
				{
					length = 0;
					g_UsbACM[usb_port].ring_buffer_timer_counting = KAL_TRUE;
				}
			}
#endif
		}
		else
		{
			length = USB2UARTPort[usb_port].Tx_Buffer.Length - USB2UARTPort[usb_port].Tx_Buffer.Read;
		}
	}
	RestoreIRQMask(savedMask);

	if((g_UsbACM[usb_port].ring_buffer_timer_counting == KAL_TRUE) && (kal_if_lisr() == KAL_FALSE))
	{
		USB2Uart_MemType[usb_port] = USBTRX_MEM_UNKOWN;
		USB_GPTI_StartItem(g_UsbACM[usb_port].ring_buffer_handle, USBACM_RING_BUFFER_TIMEOUT, USB_Acm_Ring_Buffer_Timeout, &USB2UARTPort[usb_port]);
//		start.u2Tick = USBACM_RING_BUFFER_TIMEOUT;
//		start.pfCallback = USB_Acm_Ring_Buffer_Timeout;
//		start.vPara = &USB2UARTPort[usb_port];
//		DclSGPT_Control((DCL_HANDLE)(g_UsbACM[usb_port].ring_buffer_handle ), SGPT_CMD_START, (DCL_CTRL_DATA_T*)&start);
	}

	/* If the packet size is multiple of 64, make the last one to be less than 64.
		Otherwise the last packet may not be seen on WinXP */
	if(((length&0x3f) == 0) && (length != 0))
		USB2Uart_WriteLength[usb_port] = length - 2;
	else
		USB2Uart_WriteLength[usb_port] = length;

	return USB2Uart_WriteLength[usb_port];
}

/*
    Update the buffer information after transmit done
    Note that "USB2Uart_WriteLength" will be reset to 0.
    This function and "USB2UART_Check_Transmit_Data" function must be pair.
*/

static void USB2UART_Update_Transmit_Data(UART_PORT port)
{
	kal_uint32 usb_port = USB_PORT[port];


	/* Update buffer information */
	if(USB2Uart_MemType[usb_port] == USBTRX_MEM_ISR)
	{
		USB2UARTPort[usb_port].Tx_Buffer_ISR.Read += USB2Uart_WriteLength[usb_port];
		#if 0  
/* under construction !*/
		#else		
		if(!(USB2UARTPort[usb_port].Tx_Buffer_ISR.Read <= USB2UARTPort[usb_port].Tx_Buffer_ISR.Length))
			ASSERT(0);
		#endif
		if(USB2UARTPort[usb_port].Tx_Buffer_ISR.Read == USB2UARTPort[usb_port].Tx_Buffer_ISR.Length)
			USB2UARTPort[usb_port].Tx_Buffer_ISR.Read = 0;
	}
	else if(USB2Uart_MemType[usb_port] == USBTRX_MEM_TASK)
	{
		USB2UARTPort[usb_port].Tx_Buffer.Read += USB2Uart_WriteLength[usb_port];
		#if 0  
/* under construction !*/
		#else
		if(!(USB2UARTPort[usb_port].Tx_Buffer.Read <= USB2UARTPort[usb_port].Tx_Buffer.Length))
			ASSERT(0);
		#endif		        

		if(USB2UARTPort[usb_port].Tx_Buffer.Read == USB2UARTPort[usb_port].Tx_Buffer.Length)
			USB2UARTPort[usb_port].Tx_Buffer.Read = 0;
	}
	else
	{
		EXT_ASSERT(0, (kal_uint32)USB2Uart_MemType[usb_port], 0, 0);
	}

	/* Reset to 0*/
	USB2Uart_WriteLength[usb_port] = 0;
}

/*
    Flush all data in TX ring buffer, use polling method
    Note that this is special for sending exception log since interrupt is disabled when exception occurs
    It must not be used in normal time
*/
void USB2UART_Polling_Flush_Transmit_Data(UART_PORT port)
{
	kal_uint32 usb_port = USB_PORT[port];
	kal_uint32 addr;
	kal_uint32 length=0;

	USB_Exception_Check();
//	if(INT_Exception_Enter == 0)
//		ASSERT(0);

	/* Avoid sending ilm to UART owner */
	g_UsbACM[usb_port].send_Txilm = KAL_FALSE;
	g_UsbACM[usb_port].send_Rxilm = KAL_FALSE;

	/* Wait for the running DMA done */
	USB_Polling_Transmit_Done(g_UsbACM[usb_port].txpipe->byEP, USB_ENDPT_BULK);

	if(USB2Uart_MemType[usb_port] != USBTRX_MEM_UNKOWN) /* make sure that SW buffer have data */
		USB2UART_Update_Transmit_Data(port);

	/* Flush the data in TX buffer */
	length = USB2UART_Check_Transmit_Data(port, &addr, KAL_FALSE);

	while(length)
	{
		/* used for callback function to know sent bytes */
		USB_Polling_Transmit_Data(g_UsbACM[usb_port].txpipe->byEP, USB_EP_TX_DIR, USB_ENDPT_BULK, addr, length, NULL, KAL_FALSE, KAL_TRUE, USB_DMA1_TYPE);
		USB2UART_Update_Transmit_Data(port);
		length = USB2UART_Check_Transmit_Data(port, &addr, KAL_FALSE);
		if(USB_Get_Device_State() != DEVSTATE_CONFIG)
		{
			length = 0;
			break;
		}

	}
}


void USB2UART_Set_DMA_Limiter(kal_uint32 dma_limit_num)
{
	USB_Set_DMA_Limiter(dma_limit_num);
}


void USB2UART_Clear_DMA_Limiter(void)
{
	USB_Set_DMA_Limiter(0);
}


/* Determine what buffer has data to send and call DMA setup function */
void USB2UART_DMATransmit(UART_PORT port, kal_bool b_force_isr_buffer)
{
	kal_uint32 usb_port = USB_PORT[port];
	kal_uint32 addr;
	kal_uint32 length = 0;
#ifdef __USB_SW_DMA_DIV__
	kal_uint32 short_pkt_length = 0;
#endif
	kal_uint8 ep_num = 0;
	kal_uint32 savedMask;
	kal_bool usb_dma_setup = KAL_FALSE;
	usb_dma_callback dma_callback;
//	USB_DRV_CTRL_GET_IP_VERSION_T dcl_data;


	if(b_force_isr_buffer == KAL_TRUE)
	{
		length = USB2UART_Check_Transmit_Data(port, &addr, KAL_FALSE);
	}
	else
	{
		length = USB2UART_Check_Transmit_Data(port, &addr, g_UsbACM[usb_port].threshold_enable);
	}

	if(length != 0)
	{
		usb_drv_trace2(USB2UARTPort[usb_port].ownerid, (kal_uint32)USBACM_DMA_Setup, length, usb_port);

		USB_Dbg_Trace(USB_ACM_DMA_SETUP, length, (kal_uint32)USB2Uart_MemType[usb_port]);

		savedMask = SaveAndSetIRQMask();
		/* In case USB is plugged out just before this critical section */
		if(g_UsbACM[usb_port].txpipe != NULL)
		{
			ep_num = g_UsbACM[usb_port].txpipe->byEP;
			usb_dma_setup = KAL_TRUE;
		}

		RestoreIRQMask(savedMask);

		if(usb_dma_setup == KAL_TRUE)
		{

//		dma_callback = USB_DMA_C[0];//USB_dma_callnack[uart_port_usb];

			dma_callback = USB_COM_DMA_Callback(port);

/*
		
			if(port == uart_port_usb)
				dma_callback = USB2UART_Tx_DMA1_Callback;
	#if defined(__USB_MULTIPLE_COMPORT_SUPPORT__)
			else if(port == uart_port_usb2)
				dma_callback = USB2UART_Tx_DMA2_Callback;
	#if defined (__USB_MODEM_CARD_SUPPORT__)
			else if(port == uart_port_usb3)
				dma_callback = USB2UART_Tx_DMA3_Callback;
	#endif
	#endif
			else
			{
				dma_callback = NULL;
				ASSERT(0);
			}
*/			

#ifdef __USB_SW_DMA_DIV__

			/* Get IP version */
//			DclUSB_DRV_Control(g_USB_Dcl_Handle, USB_DRV_CMD_GET_IP_VERSION, (DCL_CTRL_DATA_T  *)&dcl_data);

//			if(USB_IP_Version() == DCL_USB_IP_V3)
//			{
				/* Check one short packet length first here, only need to care about when length > 12 */
				if((length > 12)&&(addr&0x03))
				{
					short_pkt_length = 4-(addr&0x03);

					/* Send one short packet here */
					if(USB_Is_EP_Tx_Empty(ep_num, USB_ENDPT_BULK) == KAL_TRUE)
					{
						/* FIFO is empty */
						USB_EPFIFOWrite(ep_num, short_pkt_length, (kal_uint8*)addr);
						USB_EP_Tx_Ready(ep_num, USB_ENDPT_BULK);
						addr += short_pkt_length;
						length -= short_pkt_length;
						USB_Dbg_Trace(USB_ACM_SEND_SHORT_PKT, short_pkt_length, length);
					}
					else
					{
						/* FIFO is not empty, Trigger DMA for short packet only, and make sure next time will be 4 bytes alignment */
						length = short_pkt_length;
						USB2Uart_WriteLength[usb_port] = short_pkt_length;
						USB_Dbg_Trace(USB_ACM_DMA_SEND_SHORT_PKT, short_pkt_length, (kal_uint32)USB2Uart_MemType[usb_port]);
					}
				}
//			}
#endif
			/* Use short packet to instead of "max_packet + ZLP" */
	#ifdef __USB_HS_ENABLE__
			if(((USB_Is_High_Speed() == KAL_TRUE)&&(length % USB_EP_BULK_MAXP_HS == 0))||
				((USB_Is_High_Speed() == KAL_FALSE)&&(length % USB_EP_BULK_MAXP_FS == 0)))
	#else
			if(length % USB_EP_BULK_MAXP == 0)
	#endif
			{
				length -= 2;
				USB2Uart_WriteLength[usb_port] -= 2;
			}

			USB_DMA_Setup(ep_num, USB_EP_TX_DIR, USB_ENDPT_BULK, addr, length, dma_callback, KAL_FALSE, KAL_TRUE, USB_DMA1_TYPE);
		}
		/* else part must because of cable out, so we do not need to care */
	}
	else
	{
		g_UsbACM[usb_port].setup_dma = KAL_FALSE;
		if(g_UsbACM[usb_port].put_start == KAL_TRUE)
		{
		   g_UsbACM[usb_port].dmaf_setmember |= 0x02;
		}		
		//usb_drv_trace1(USB2UARTPort[usb_port].ownerid, (kal_uint32)USBACM_DMA_Setup0, usb_port);
	}
}


/* DMA callback function for TX sent out data */
void USB2UART_Tx_DMA_Callback(UART_PORT port)
{
	kal_uint32 usb_port = USB_PORT[port];
	kal_uint32 savedMask;
	kal_bool setup_dma = KAL_FALSE;
	kal_bool b_force_isr_buffer = KAL_FALSE;
#ifdef  __USB_HIGH_SPEED_COM_PORT_ENABLE__
	usb_dma_callback dma_callback;
#endif

	/*It can only be clear by USB2UART_PutBytes*/
	if (USB2Uart_MemType[usb_port] == USBTRX_MEM_TASK)
		g_UsbACM[usb_port].dma_txcb_just_done = KAL_TRUE;

	if(USB2UARTPort[usb_port].ownerid != MOD_TST_READER)
	{
#ifdef  __USB_HIGH_SPEED_COM_PORT_ENABLE__
		if(g_UsbACM[usb_port].b_is_high_speed_enable == KAL_TRUE)
		{
			usb_drv_trace2(USB2UARTPort[usb_port].ownerid, (kal_uint32)USBACM_DMA_CALLBACK, g_UsbACM[usb_port].tx_count, usb_port);
		}
		else
#endif
		{
			usb_drv_trace2(USB2UARTPort[usb_port].ownerid, (kal_uint32)USBACM_DMA_CALLBACK, USB2Uart_WriteLength[usb_port], usb_port);
		}

		USB_Debug_Information(g_UsbACM[usb_port].txpipe->byEP, USB_EP_TX_DIR, KAL_FALSE);
	}

#ifdef  __USB_HIGH_SPEED_COM_PORT_ENABLE__
	if((g_UsbACM[usb_port].b_data_left == KAL_TRUE)&&(g_UsbACM[usb_port].b_is_high_speed_enable == KAL_TRUE))
	{
		/* It's OK since high spped if enable/disable are all wait until DMA stop */
		g_UsbACM[usb_port].b_data_left = KAL_FALSE;

		/* In case USB is plugged out just before this critical section */
		if(g_UsbACM[usb_port].txpipe != NULL)
		{

			dma_callback = USB_COM_DMA_Callback(port);

/*
			if(port == uart_port_usb)
			{
				dma_callback = USB2UART_Tx_DMA1_Callback;
			}
	#if defined(__USB_MULTIPLE_COMPORT_SUPPORT__)
			else if(port == uart_port_usb2)
			{
				dma_callback = USB2UART_Tx_DMA2_Callback;
			}
	#if defined (__USB_MODEM_CARD_SUPPORT__)
			else if(port == uart_port_usb3)
			{
				dma_callback = USB2UART_Tx_DMA3_Callback;
			}
	#endif
	#endif
			else
			{
				dma_callback = NULL;
				ASSERT(0);
			}

*/
			g_UsbACM[usb_port].tx_count = 1;
			USB_DMA_Setup(g_UsbACM[usb_port].txpipe->byEP, USB_EP_TX_DIR, USB_ENDPT_BULK, g_UsbACM[usb_port].data_addr, 1, dma_callback, KAL_FALSE, KAL_TRUE, USB_DMA1_TYPE);
		}

		return;
	}

		if(g_UsbACM[usb_port].b_is_high_speed_enable == KAL_TRUE)
		{
			/* USB2Uart_MemType and USB2Uart_WriteLength are updated, so clear dma running state here*/
			g_UsbACM[usb_port].setup_dma = KAL_FALSE;		
		}
#endif

	/* TX complete callback */
	USB2UARTPort[usb_port].tx_cb(port);

#ifdef  __USB_HIGH_SPEED_COM_PORT_ENABLE__
	if(g_UsbACM[usb_port].b_is_high_speed_enable == KAL_FALSE)
#endif
	{
		/* Update read pointer for previously sent out buffer 
		    As for race condition, so we update transmit data first.
		    The putISRbyte may be called by LISR or HISR*/
		savedMask = SaveAndSetIRQMask();
		USB2UART_Update_Transmit_Data(port);
		RestoreIRQMask(savedMask);

		/* USB2Uart_MemType and USB2Uart_WriteLength are updated, so clear dma running state here*/
		g_UsbACM[usb_port].setup_dma = KAL_FALSE;
		if(g_UsbACM[usb_port].put_start == KAL_TRUE)
		{
		   g_UsbACM[usb_port].dmaf_setmember |= 0x01;
		}

		if(USB2UARTPort[usb_port].Tx_Buffer_ISR.Read == USB2UARTPort[usb_port].Tx_Buffer_ISR.Write)
		{
			/* No more data to send */
			if(USB2UARTPort[usb_port].Tx_Buffer.Read == USB2UARTPort[usb_port].Tx_Buffer.Write)
				return;
		}
		/* must send ISR buffer again */
		else if(USB2Uart_MemType[usb_port] == USBTRX_MEM_ISR)
		{
			b_force_isr_buffer = KAL_TRUE;
		}

		/* send data again in TX buffer or TXISR buffer */
		savedMask = SaveAndSetIRQMask();
		/* In case USB is plugged out just before this critical section */
		if(g_UsbACM[usb_port].txpipe != NULL)
		{
	//		if(USB_DMA_Get_Run_Status(g_UsbACM.txpipe->byEP,USB_EP_TX_DIR) == KAL_FALSE)
			if(g_UsbACM[usb_port].setup_dma == KAL_FALSE)
			{
				g_UsbACM[usb_port].setup_dma = KAL_TRUE;
				setup_dma = KAL_TRUE;
			}
		}
		RestoreIRQMask(savedMask);

		if(setup_dma == KAL_TRUE)
		{
			USB_Dbg_Trace(USB_ACM_DMA_CALLBACK, (kal_uint32)port, 0);
	//		USB_Dbg_Trace(USB_ACM_DMA_CALLBACK, b_force_isr_buffer, (kal_uint32)USB2Uart_MemType);

			USB2UART_DMATransmit(port, b_force_isr_buffer);
			/* There are already some logs in USB2UART_DMATransmit() */

/*
			if(USB2UARTPort[usb_port].ownerid != MOD_TST_READER)
			{
				drv_trace1(TRACE_FUNC, (kal_uint32)USBACM_DMA_Setup2, usb_port);
			}
*/
		}
	}
}



void USB2UART_Tx_DMA1_Callback(void)
{
	USB2UART_Tx_DMA_Callback(uart_port_usb);
}

#ifdef  __USB_HIGH_SPEED_COM_PORT_ENABLE__
#ifdef DRV_USB_DMA_QUEUE_SUPPORT

PRAGMA_BEGIN_COMPILER_OPTIMIZE_TIME
/* DMA callback function for TX sent out data */
void USB2UART_PPPRX_DMAQ_Callback(void *pridata)
{
	UART_PORT port = (UART_PORT) (*((UART_PORT *)pridata));
	kal_uint32 usb_port = USB_PORT[port];

	kal_uint32 real_count = 0;		
	kal_uint32 sp_Count,index;
	//kal_uint32 max_bulk_pkt_size;	
	kal_uint8  *data;
	static kal_bool esc_timer_is_run = KAL_TRUE;
	
	/* Stop escape GPT timer */
	if((esc_timer_is_run == KAL_TRUE)&&(USB2UARTPort[usb_port].ESCDet.GuardTime != 0))
	{
		USB_GPTI_StopItem(USB2UARTPort[usb_port].handle);
				esc_timer_is_run = KAL_FALSE;
	}

	if((USB_DMAQ_PPP_RX_GPD[g_UsbACM[usb_port].ppp_rdmaq_idx].flag & RXGPD_FLAGS_HWO) == 0)
	{
	  	real_count =  USB_DMAQ_PPP_RX_GPD[g_UsbACM[usb_port].ppp_rdmaq_idx].bufLen;
	}	
	g_UsbACM[usb_port].ppp_rdmaq_idx++;
	if(g_UsbACM[usb_port].ppp_rdmaq_idx == 2)
		g_UsbACM[usb_port].ppp_rdmaq_idx = 0;
	
	usb_drv_trace2(USB2UARTPort[usb_port].ownerid, (kal_uint32)USBACM_PC_SENT, real_count, port);
	
	if(real_count > USB_ACM_RX_BUFFER_SIZE) 				
		EXT_ASSERT(0,real_count, 0,0);	

	if(USB2UARTPort[usb_port].ownerid != MOD_DRV_HISR)
	{
		if(real_count != 0)	
	{
		/* RX complete callback */
		USB2UARTPort[usb_port].rx_cb(port);
		
	//max_bulk_pkt_size = USB_Bulk_Max_Packet_Size();		
	sp_Count = real_count & (USB_EP_BULK_MAXP_HS-1);
	if(sp_Count > 4)
	{				
		USB2UARTPort[usb_port].Rec_state = UART_RecNormal;
		USB2UARTPort[usb_port].EscCount = 0;
	}
	else
	{
		kal_uint32 offset;
		offset = real_count & ~(USB_EP_BULK_MAXP_HS-1);
		data = (kal_uint8 *)&g_UsbACM[usb_port].rx_buf_addr[g_UsbACM[usb_port].rx_buf_w_index][offset];
		/* Check escape character */
		if(USB2UARTPort[usb_port].ESCDet.GuardTime != 0)
		{
			/* Need to check escape charater */
			for(index = 0; index < sp_Count; index++)
			{
				/* detect escape sequence  */
				if(USB2UARTPort[usb_port].Rec_state != UART_RecNormal)
				{
					if (data[index] == USB2UARTPort[usb_port].ESCDet.EscChar)
					{
						USB_Dbg_Trace(USB_ACM_ESCAPE_CHAR, (kal_uint32)USB2UARTPort[usb_port].EscCount, 0);
						USB2UARTPort[usb_port].EscCount++;
						if(USB2UARTPort[usb_port].EscCount == 3)
						{
							USB2UARTPort[usb_port].Rec_state = UART_Get3EscChar;
						}
						else if(USB2UARTPort[usb_port].EscCount > 3)
						{
							USB2UARTPort[usb_port].Rec_state = UART_RecNormal;
							USB2UARTPort[usb_port].EscCount = 0;
						}
					}
					else
					{
						USB2UARTPort[usb_port].Rec_state = UART_RecNormal;
						USB2UARTPort[usb_port].EscCount = 0;
					}
				}
			}
		}
	}

	g_UsbACM[usb_port].rx_buf_data_len[g_UsbACM[usb_port].rx_buf_w_index] = real_count;
	/* This log cannot be executed when assertion because the system stack will overflow */
	g_UsbACM[usb_port].rx_buf_w_index++;
	if(g_UsbACM[usb_port].rx_buf_w_index == USB_ACM_RX_BUFFER_NUM)
		g_UsbACM[usb_port].rx_buf_w_index = 0;

	g_UsbACM[usb_port].rx_buf_count++;

//	USB_Dbg_Trace(USB_ACM_HIGHSPEED_MOVE_W_INDEX, g_UsbACM[usb_port].rx_buf_w_index, g_UsbACM[usb_port].rx_buf_count);
	usb_drv_trace4(USB2UARTPort[usb_port].ownerid, (kal_uint32)USBACM_MOVE_W_INDEX, g_UsbACM[usb_port].rx_buf_w_index, g_UsbACM[usb_port].rx_buf_count, g_UsbACM[usb_port].rx_buf_rc_index, g_UsbACM[usb_port].rx_buf_r_index);
	
	if(g_UsbACM[usb_port].rx_buf_count > USB_ACM_RX_BUFFER_NUM)
		ASSERT(0);	
		}


	/* Decide if we need to disable USB_IRQ */
	if(g_UsbACM[usb_port].rx_buf_w_index != g_UsbACM[usb_port].rx_buf_rc_index)
	{
		kal_uint32 curr_idx = g_UsbACM[usb_port].ppp_rdmaq_idx;
		USB_DMAQ_PPP_RX_GPD[curr_idx].pBuf = (kal_uint8*)&g_UsbACM[usb_port].rx_buf_addr[g_UsbACM[usb_port].rx_buf_w_index][0];
		USB_DMAQ_PPP_RX_GPD[curr_idx].bufLen =  0;			
		USB_DMAQ_PPP_RX_GPD[curr_idx].flag = RXGPD_FLAGS_HWO; //1:HW is Owner, SW should not to access data buffer; HW will clear it to 0.										
		USB_DMAQ_Setup(g_UsbACM[usb_port].rxpipe->byEP, USB_EP_RX_DIR, 
		  KAL_FALSE, (kal_uint32) &USB_DMAQ_PPP_RX_GPD[curr_idx],
		  (usb_dmaq_CB)USB2UART_PPPRX_DMAQ_Callback, (usb_dmaq_CB)NULL,(void *)&USB2UARTPort[usb_port].port_no);	

	}	
	}
	else
	{
		ASSERT(0);
	}
	/* Check the next packet's data length */
	real_count = USB_EP_Rx_Pkt_Len(g_UsbACM[usb_port].rxpipe->byEP);

	if(real_count == 0)
	{
		/* 0 may be due to no packet or NULL packet */
		/* re-start escape GPT timer */
		if(USB2UARTPort[usb_port].ESCDet.GuardTime != 0)
		{
			USB_GPTI_StartItem(USB2UARTPort[usb_port].handle, (USB2UARTPort[usb_port].ESCDet.GuardTime/10), USB2UART_Timeout, &USB2UARTPort[usb_port]);
//			start.u2Tick = (USB2UARTPort[usb_port].ESCDet.GuardTime/10);
//			start.pfCallback = USB2UART_Timeout;
//			start.vPara = &USB2UARTPort[usb_port];
//			DclSGPT_Control((DCL_HANDLE)(USB2UARTPort[usb_port].handle), SGPT_CMD_START, (DCL_CTRL_DATA_T*)&start);

			esc_timer_is_run = KAL_TRUE;
		}
	}	
}
PRAGMA_END_COMPILER_OPTIMIZE_TIME
/* DMA callback function for TX sent out data */

PRAGMA_BEGIN_COMPILER_OPTIMIZE_TIME
void USB2UART_PPPTX_DMAQ_Callback(void *pridata)
{
	UART_PORT port = (UART_PORT) (*((UART_PORT *)pridata));
	kal_uint32 usb_port = USB_PORT[port];

	
	if(USB2UARTPort[usb_port].ownerid != MOD_TST_READER)
	{
		usb_drv_trace2(USB2UARTPort[usb_port].ownerid, (kal_uint32)USBACM_DMA_CALLBACK, g_UsbACM[usb_port].tx_count, usb_port);
	}

	g_UsbACM[usb_port].ppp_tdmaq_idx++;
	if(g_UsbACM[usb_port].ppp_tdmaq_idx == 2)
		g_UsbACM[usb_port].ppp_tdmaq_idx = 0;		

	if((g_UsbACM[usb_port].b_data_left == KAL_TRUE)&&(g_UsbACM[usb_port].b_is_high_speed_enable == KAL_TRUE))
	{
		/* It's OK since high spped if enable/disable are all wait until DMA stop */
		g_UsbACM[usb_port].b_data_left = KAL_FALSE;

		/* In case USB is plugged out just before this critical section */
		if(g_UsbACM[usb_port].txpipe != NULL)
{
			g_UsbACM[usb_port].tx_count = 1;
		  	USB_DMAQ_PPP_TX_GPD[g_UsbACM[usb_port].ppp_tdmaq_idx].pBuf = (kal_uint8*)g_UsbACM[usb_port].data_addr;
		  	USB_DMAQ_PPP_TX_GPD[g_UsbACM[usb_port].ppp_tdmaq_idx].bufLen =  1;	
			USB_DMAQ_PPP_TX_GPD[g_UsbACM[usb_port].ppp_tdmaq_idx].flag = TXGPD_FLAGS_HWO; //1:HW is Owner, SW should not to access data buffer; HW will clear it to 0.								
			USB_DMAQ_Setup(g_UsbACM[usb_port].txpipe->byEP, USB_EP_TX_DIR, 
			  KAL_FALSE, (kal_uint32) &USB_DMAQ_PPP_TX_GPD[g_UsbACM[usb_port].ppp_tdmaq_idx],
			  (usb_dmaq_CB)USB2UART_PPPTX_DMAQ_Callback, (usb_dmaq_CB)NULL,(void *)&USB2UARTPort[usb_port].port_no);	
//			g_UsbACM[usb_port].ppp_tdmaq_idx++;
//			if(g_UsbACM[usb_port].ppp_tdmaq_idx == 2)
//				g_UsbACM[usb_port].ppp_tdmaq_idx = 0;

		}

		return;
}		

		/* TX complete callback */
	USB2UARTPort[usb_port].tx_cb(port);
	g_UsbACM[usb_port].setup_dma = KAL_FALSE;				
}
PRAGMA_END_COMPILER_OPTIMIZE_TIME

#if defined(__MBIM_SUPPORT__)||defined(__ECM_SUPPORT__)

void USB2UART_TX_DMAQ_Callback(void* pridata)
{
	//UART_PORT port = USB2UARTPort[usb_port].port_no;
	////if(g_UsbACM[usb_port].send_Txilm == KAL_TRUE)
	//{
	//	g_UsbACM[usb_port].send_Txilm = KAL_FALSE;
	//	USB2UART_Sendilm(port, MSG_ID_UART_READY_TO_WRITE_IND);
	//}
}

void USB2UART_RX_DMAQ_Callback(void *pridata)
{
//	UART_PORT port = USB2UARTPort[usb_port].port_no;
	UART_PORT port = (UART_PORT) (*((UART_PORT *)pridata));	
	kal_uint32 usb_port = USB_PORT[port];	
	drv_trace4(TRACE_FUNC, (kal_uint32)USB_DMAQ_RXGPD_EMPTY, port,0x00,port,0);

	if(g_UsbACM[usb_port].send_Rxilm == KAL_TRUE)
	{
		g_UsbACM[usb_port].send_Rxilm = KAL_FALSE;
		USB2UART_Sendilm(port, MSG_ID_UART_READY_TO_READ_IND);
	}
}

void USB2UART_RX_DMAQ_Empty_Callback(void *pridata)
{
	UART_PORT port = (UART_PORT) (*((UART_PORT *)pridata));
	kal_uint32 usb_port = USB_PORT[port];

	TGPD *p_GPD = NULL;
	
	drv_trace4(TRACE_FUNC, (kal_uint32)USB_DMAQ_RXGPD_EMPTY, (kal_uint32)USB_DMAQ_RX_GPD_HEADER,usb_port,port,0);
	
	if (USB_DMAQ_RX_GPD_HEADER != NULL)
	{
		p_GPD = USB_DMAQ_RX_GPD_HEADER;
		while((p_GPD != (&USB_DMAQ_RX_GPD_NULL)))
		{
			if (p_GPD == NULL)
				ASSERT(0);
				
			if ((p_GPD->flag&0x01) >0)
			{
				drv_trace2(TRACE_FUNC, (kal_uint32)USB_DMAQ_RXGPD_SETUP, (kal_uint32)p_GPD, (kal_uint32)USB_DMAQ_RX_GPD_HEADER);
				USB_DMAQ_Setup(g_UsbACM[usb_port].rxpipe->byEP, USB_EP_RX_DIR, KAL_TRUE, (kal_uint32)p_GPD, (usb_dmaq_CB)USB2UART_RX_DMAQ_Callback, (usb_dmaq_CB)USB2UART_RX_DMAQ_Empty_Callback,(void *)&USB2UARTPort[usb_port].port_no);
				break;
			}
			else
			{
				p_GPD = p_GPD->pNext;
			}
		}
	}
}

void USB2UART_TX_DMAQ_Empty_Callback(void* pridata)
{
	UART_PORT port = (UART_PORT) (*((UART_PORT *)pridata));
	
	drv_trace4(TRACE_FUNC, (kal_uint32)USB_DMAQ_TXGPD_EMPTY, (kal_uint32)USB_DMAQ_TX_GPD_HEADER,port,0,0);
	USB2UART_Sendilm(port, MSG_ID_UART_READY_TO_WRITE_IND);
}
#endif

#endif
#endif //	__USB_HIGH_SPEED_COM_PORT_ENABLE__
/************************************************************
	Bulk EP OUT handle functions (clear RX FIFO data, read them out and drop)
*************************************************************/
void USB_Acm_Rx_ClrFifo(UART_PORT port)
{
	kal_uint32 usb_port = USB_PORT[port];
	kal_uint32 nCount,index;
	kal_uint8         data[USB_EP_BULK_MAXP_HS];


	/* Check if data received */
	/* Check if data received, valid for double FIFO IP */

	for (index = 0; index<2; index++)
	{
		nCount = USB_EP_Rx_Pkt_Len(g_UsbACM[usb_port].rxpipe->byEP);

		if(nCount != 0)
		{
			/* Get the data from fifo */
			USB_EPFIFORead(g_UsbACM[usb_port].rxpipe->byEP, nCount, data, KAL_FALSE);

			/* Clear RxPktRdy */
			USB_EP_Rx_Ready(g_UsbACM[usb_port].rxpipe->byEP, USB_ENDPT_BULK);
			
			/*Clear RX interrupt*/
			USB_Clr_RX_EP_ISR(g_UsbACM[usb_port].rxpipe->byEP);
		}
	}
}


/************************************************************
	Interface initialization functions
*************************************************************/
static kal_uint8 USB_Acm_Get_DataIf_Num(UART_PORT port)
{
	kal_uint32 usb_port = USB_PORT[port];
	kal_uint8 if_id;


	if(g_UsbACM[usb_port].data_interface_id == 0xFF)
	{
		/* Get resource number and register to gUsbDevice */
		g_UsbACM[usb_port].data_if_info = USB_Get_Interface_Number(&if_id);
		g_UsbACM[usb_port].data_interface_id = if_id;
	}

	return g_UsbACM[usb_port].data_interface_id;
}


/* Communication interface create function, prepare descriptor */
static void USB_Acm_CommIf_Create(UART_PORT port, void *ifname)
{
	kal_uint32 usb_port = USB_PORT[port];
	kal_uint8 ep_id;
	kal_uint8 if_id;

	/* Get resource number and register to gUsbDevice */
	g_UsbACM[usb_port].comm_if_info = USB_Get_Interface_Number(&if_id);
	g_UsbACM[usb_port].comm_ep_intr_info = USB_Get_Intr_Ep(&ep_id);

	/* Record interface name and interface descriptor length */
	g_UsbACM[usb_port].comm_if_info->interface_name_ptr = (kal_char *)ifname;
	g_UsbACM[usb_port].comm_if_info->ifdscr_size = USB_CDC_IF_LENGTH;
	g_UsbACM[usb_port].comm_ep_intr_info->epdscr_size = USB_EPDSC_LENGTH;

	/* Related endpoint info and class specific command handler */
	g_UsbACM[usb_port].comm_if_info->ep_info[0] = g_UsbACM[usb_port].comm_ep_intr_info;

	if(port == uart_port_usb)
		g_UsbACM[usb_port].comm_if_info->if_class_specific_hdlr = USB_Acm1_Ep0_Command;
#if defined(__USB_MULTIPLE_COMPORT_SUPPORT__)
	else if(port == uart_port_usb2)
		g_UsbACM[usb_port].comm_if_info->if_class_specific_hdlr = USB_Acm2_Ep0_Command;
#if defined (__USB_MODEM_CARD_SUPPORT__)
	else if(port == uart_port_usb3)
		g_UsbACM[usb_port].comm_if_info->if_class_specific_hdlr = USB_Acm3_Ep0_Command;
	else if(port == uart_port_usb4)
		g_UsbACM[usb_port].comm_if_info->if_class_specific_hdlr = USB_Acm4_Ep0_Command;
	else if(port == uart_port_usb5)
		g_UsbACM[usb_port].comm_if_info->if_class_specific_hdlr = USB_Acm5_Ep0_Command;
#endif
#endif


	kal_mem_cpy(&(g_UsbACM[usb_port].comm_if_info->ifdscr.stdif), cdcacm_com_if_dscr, USB_CDC_IF_LENGTH);
	kal_mem_cpy(&(g_UsbACM[usb_port].comm_ep_intr_info->epdesc.stdep), cdcacm_intr_dscr, USB_EPDSC_LENGTH);



	/* Standard interface descriptor */
	((Usb_Cdc_If_Dscr*)g_UsbACM[usb_port].comm_if_info->ifdscr.classif)->bInterfaceNumber = if_id;


#ifdef __USB_MODEM_CARD_SUPPORT__	
//	if(g_UsbMode.usb_comport_driver == USB_COMPORT_WIN_SINGLE_INTERFACE)
	{
		((Usb_Cdc_If_Dscr*)g_UsbACM[usb_port].comm_if_info->ifdscr.classif)->bInterfaceClass = 0xFF;
	}
#endif


	if(port == uart_port_usb)
	{
		((Usb_Cdc_If_Dscr*)g_UsbACM[usb_port].comm_if_info->ifdscr.classif)->iInterface =USB_Get_String_Number((void *)g_UsbACM_Comm.acm_param->comm_interface_string);

		/* Endpoint handler */
		USB_Register_Drv_Info(USB_DRV_HDLR_EP_TX, ep_id, USB_Acm1_IntrIn_Hdlr);
		g_UsbACM[usb_port].comm_ep_intr_info->ep_reset = USB_Acm1_IntrIn_Reset;
	}
#if defined(__USB_MULTIPLE_COMPORT_SUPPORT__)
	else if(port == uart_port_usb2)
	{
		((Usb_Cdc_If_Dscr*)g_UsbACM[usb_port].comm_if_info->ifdscr.classif)->iInterface =USB_Get_String_Number((void *)g_UsbACM_Comm.acm_param->comm_interface_string_2);

		/* Endpoint handler */
		USB_Register_Drv_Info(USB_DRV_HDLR_EP_TX, ep_id, USB_Acm2_IntrIn_Hdlr);
		g_UsbACM[usb_port].comm_ep_intr_info->ep_reset = USB_Acm2_IntrIn_Reset;
	}
	
#if defined (__USB_MODEM_CARD_SUPPORT__)
	else if(port == uart_port_usb3)
	{	
//		((Usb_Cdc_If_Dscr*)g_UsbACM[usb_port].comm_if_info->ifdscr.classif)->iInterface = USB_Get_String_Number((void *)g_UsbACM_Comm.acm_param->comm_interface_string_3);
		/* Endpoint handler */
		USB_Register_Drv_Info(USB_DRV_HDLR_EP_TX, ep_id, USB_Acm3_IntrIn_Hdlr);
		g_UsbACM[usb_port].comm_ep_intr_info->ep_reset = USB_Acm3_IntrIn_Reset;
	}
	else if(port == uart_port_usb4)
	{	
		//((Usb_Cdc_If_Dscr*)g_UsbACM[usb_port].comm_if_info->ifdscr.classif)->iInterface = USB_Get_String_Number((void *)g_UsbACM_Comm.acm_param->comm_interface_string_4);
		/* Endpoint handler */
		USB_Register_Drv_Info(USB_DRV_HDLR_EP_TX, ep_id, USB_Acm4_IntrIn_Hdlr);
		g_UsbACM[usb_port].comm_ep_intr_info->ep_reset = USB_Acm4_IntrIn_Reset;
	}
	else if(port == uart_port_usb5)
	{	
		//((Usb_Cdc_If_Dscr*)g_UsbACM[usb_port].comm_if_info->ifdscr.classif)->iInterface = USB_Get_String_Number((void *)g_UsbACM_Comm.acm_param->comm_interface_string_5);
		/* Endpoint handler */
		USB_Register_Drv_Info(USB_DRV_HDLR_EP_TX, ep_id, USB_Acm5_IntrIn_Hdlr);
		g_UsbACM[usb_port].comm_ep_intr_info->ep_reset = USB_Acm5_IntrIn_Reset;
	}
#endif

#endif


#ifndef  __USB_COMPOSITE_REMOVE_IAD__
#if defined(__USB_COMPOSITE_DEVICE_SUPPORT__)
#ifndef __USB_MODEM_CARD_SUPPORT__

	if((USB_Check_Composite_With_COM(USB_Get_Device_Type()) == KAL_TRUE) && ((g_UsbMode.usb_comport_driver == USB_COMPORT_WIN)||(g_UsbMode.usb_comport_driver == USB_COMPORT_LINUX)))
	{
		/* Construct IAD descriptor */
		g_UsbACM[usb_port].iad_desc = USB_Get_IAD_Number();
		g_UsbACM[usb_port].iad_desc->bLength = USB_IAD_LENGTH;
		g_UsbACM[usb_port].iad_desc->bDescriptorType = USB_INTERFACE_ASSOCIATION;
		g_UsbACM[usb_port].iad_desc->bInterfaceCount = USB_CDC_ACM_IF_NUMBER;

		if(if_id < USB_Acm_Get_DataIf_Num(port))
		{
			/* Means first interface is communication interface */
			g_UsbACM[usb_port].iad_desc->bFirstInterface = if_id;
			g_UsbACM[usb_port].iad_desc->bFunctionClass = USB_ACM_COMM_INTERFACE_CLASS_CODE;
			g_UsbACM[usb_port].iad_desc->bFunctionSubClass = USB_ACM_COMM_INTERFACE_SUBCLASS_CODE;
			g_UsbACM[usb_port].iad_desc->bFunctionProtocol = USB_ACM_COMM_INTERFACE_PROTOCOL_CODE;
			g_UsbACM[usb_port].iad_desc->iFunction = ((Usb_Cdc_If_Dscr*)g_UsbACM[usb_port].comm_if_info->ifdscr.classif)->iInterface;
		}
		else
		{
			g_UsbACM[usb_port].iad_desc->bFirstInterface = g_UsbACM[usb_port].data_interface_id;
			g_UsbACM[usb_port].iad_desc->bFunctionClass = USB_ACM_DATA_INTERFACE_CLASS_CODE;
			g_UsbACM[usb_port].iad_desc->bFunctionSubClass = USB_ACM_DATA_INTERFACE_SUBCLASS_CODE;
			g_UsbACM[usb_port].iad_desc->bFunctionProtocol = USB_ACM_DATA_INTERFACE_PROTOCOL_CODE;
			g_UsbACM[usb_port].iad_desc->iFunction = g_UsbACM[usb_port].data_if_info->ifdscr.stdif.iInterface;
		}

		if(g_UsbACM[usb_port].iad_desc->iFunction == 0x00)
			ASSERT(0);
	}
#endif
#endif
#endif


	/* Union Functional Descriptor */
	((Usb_Cdc_If_Dscr*)g_UsbACM[usb_port].comm_if_info->ifdscr.classif)->bMasterInterface = if_id;
	((Usb_Cdc_If_Dscr*)g_UsbACM[usb_port].comm_if_info->ifdscr.classif)->bSlaveInterface0 = USB_Acm_Get_DataIf_Num(port);//g_UsbACM.data_interface_id;
	/* Call Management Descriptor */
	((Usb_Cdc_If_Dscr*)g_UsbACM[usb_port].comm_if_info->ifdscr.classif)->bDataInterface = USB_Acm_Get_DataIf_Num(port);//g_UsbACM.data_interface_id;

	/* Endpoint descriptor */
	g_UsbACM[usb_port].comm_ep_intr_info->epdesc.stdep.bEndpointAddress = (USB_EP_DIR_IN|ep_id);	/*InPipe*/
	g_UsbACM[usb_port].comm_ep_intr_info->epdesc.stdep.bInterval = 3;
#ifdef __USB_MODEM_CARD_SUPPORT__	
	if (g_UsbMode.usb_comport_driver == USB_COMPORT_LINUX)
		g_UsbACM[usb_port].comm_ep_intr_info->epdesc.stdep.bInterval = 1;
#endif
	g_UsbACM[usb_port].comm_ep_intr_info->ep_status.epin_status.byEP = ep_id;
	g_UsbACM[usb_port].comm_ep_intr_info->ep_status.epin_status.nBytesLeft = USB_EP_NODATA;

	g_UsbACM[usb_port].intr_pkt.bmRequestType = USB_CMD_CLASSIFIN;
	g_UsbACM[usb_port].intr_pkt.bRequest = USB_ACM_NOTIF_SERIAL_STATE;
	g_UsbACM[usb_port].intr_pkt.wValue = 0;
	g_UsbACM[usb_port].intr_pkt.wIndex = if_id;
	g_UsbACM[usb_port].intr_pkt.wLength = 2;
}




/* Communication interface reset function, should enable EP, but we do not use this interrupt EP so not enable it */
static void USB_Acm_CommIf_Reset(UART_PORT port)
{
	kal_uint32 usb_port = USB_PORT[port];


	g_UsbACM[usb_port].intrpipe = &g_UsbACM[usb_port].comm_ep_intr_info->ep_status.epin_status;
}




static void USB_Acm_CommIf_Enable(UART_PORT port)
{
	kal_uint32 usb_port = USB_PORT[port];


//#ifdef __USB_DOWNLOAD__
	if (USBDL_Mode_Type()== USBDL_MODE_USB_DOWNLOAD)//(USBDL_Is_USB_Download_Mode() == KAL_TRUE)
	{
		/* Non-DMA */
		USB_TxEPEn(g_UsbACM[usb_port].intrpipe->byEP, USB_ENDPT_INTR, USB_EP_USE_NO_DMA, KAL_FALSE, KAL_TRUE);
	}
	else
	{
		/* Non-DMA */
		USB_TxEPEn(g_UsbACM[usb_port].intrpipe->byEP, USB_ENDPT_INTR, USB_EP_USE_NO_DMA, KAL_TRUE, KAL_FALSE);
	}
//#else
//	/* Non-DMA */
//	USB_TxEPEn(g_UsbACM[usb_port].intrpipe->byEP, USB_ENDPT_INTR, USB_EP_USE_NO_DMA, KAL_TRUE, KAL_FALSE);
//#endif
}



/* Communication interface speed reset function, enable EP's speed-specific descriptor */
static void USB_Acm_CommIf_Speed_Reset(UART_PORT port, kal_bool b_other_speed)
{
#ifdef __USB_HS_ENABLE__
	kal_uint32 usb_port = USB_PORT[port];

	g_UsbACM[usb_port].comm_ep_intr_info->epdesc.stdep.wMaxPacketSize[0] = USB_EP_INTR_MAXP_FS&0xff;
	g_UsbACM[usb_port].comm_ep_intr_info->epdesc.stdep.wMaxPacketSize[1] = 0x00;
#endif
}




/* Data interface create function, prepare descriptor */
static void USB_Acm_DataIf_Create(UART_PORT port, void *ifname)
{
	kal_uint32 usb_port = USB_PORT[port];
	kal_uint8 ep_tx_id;
	kal_uint8 ep_rx_id;
	kal_uint8 if_id;


	/* Get resource number and register to gUsbDevice */
	if(g_UsbACM[usb_port].data_interface_id == 0xFF)  //check has already register or not
	{
		g_UsbACM[usb_port].data_if_info = USB_Get_Interface_Number(&if_id);
		g_UsbACM[usb_port].data_interface_id = if_id;
	}

	g_UsbACM[usb_port].data_ep_in_info = USB_Get_Bulk_Tx_Ep(&ep_tx_id);
	g_UsbACM[usb_port].data_ep_out_info = USB_Get_Bulk_Rx_Ep(&ep_rx_id);

	/* Record interface name and interface descriptor length */
	g_UsbACM[usb_port].data_if_info->interface_name_ptr = (kal_char *)ifname;
	g_UsbACM[usb_port].data_if_info->ifdscr_size = USB_IFDSC_LENGTH;
	g_UsbACM[usb_port].data_ep_in_info->epdscr_size = USB_EPDSC_LENGTH;
	g_UsbACM[usb_port].data_ep_out_info->epdscr_size = USB_EPDSC_LENGTH;

	/* Related endpoint info and class specific command handler*/
	g_UsbACM[usb_port].data_if_info->ep_info[0] = g_UsbACM[usb_port].data_ep_in_info;
	g_UsbACM[usb_port].data_if_info->ep_info[1] = g_UsbACM[usb_port].data_ep_out_info;
	if(port == uart_port_usb)
		g_UsbACM[usb_port].data_if_info->if_class_specific_hdlr = USB_Acm1_Ep0_Command; //align with Bootrom comm_if
	else
		g_UsbACM[usb_port].data_if_info->if_class_specific_hdlr = NULL;


	kal_mem_cpy(&(g_UsbACM[usb_port].data_if_info->ifdscr.stdif), cdcacm_data_if_dscr, USB_IFDSC_LENGTH);
	kal_mem_cpy(&(g_UsbACM[usb_port].data_ep_in_info->epdesc.stdep), cdcacm_ep_in_dscr, USB_EPDSC_LENGTH);
	kal_mem_cpy(&(g_UsbACM[usb_port].data_ep_out_info->epdesc.stdep), cdcacm_ep_out_dscr, USB_EPDSC_LENGTH);


	/* Standard interface descriptor */
	g_UsbACM[usb_port].data_if_info->ifdscr.stdif.bInterfaceNumber = g_UsbACM[usb_port].data_interface_id;

#ifdef __USB_MODEM_CARD_SUPPORT__	
//	if(g_UsbMode.usb_comport_driver == USB_COMPORT_WIN_SINGLE_INTERFACE)
	{
		g_UsbACM[usb_port].data_if_info->ifdscr.stdif.bInterfaceClass = 0xFF;
	}
#endif


	if(port == uart_port_usb)
	{
		g_UsbACM[usb_port].data_if_info->ifdscr.stdif.iInterface = USB_Get_String_Number((void *)g_UsbACM_Comm.acm_param->data_interface_string);
		g_UsbACM[usb_port].data_ep_in_info->ep_reset = USB_Acm1_BulkIn_Reset;
		g_UsbACM[usb_port].data_ep_out_info->ep_reset = USB_Acm1_BulkOut_Reset;
	}
#if defined(__USB_MULTIPLE_COMPORT_SUPPORT__)
	else if (port == uart_port_usb2)
	{
		g_UsbACM[usb_port].data_if_info->ifdscr.stdif.iInterface = USB_Get_String_Number((void *)g_UsbACM_Comm.acm_param->data_interface_string_2);
		g_UsbACM[usb_port].data_ep_in_info->ep_reset = USB_Acm2_BulkIn_Reset;
		g_UsbACM[usb_port].data_ep_out_info->ep_reset = USB_Acm2_BulkOut_Reset;
	}
#if defined (__USB_MODEM_CARD_SUPPORT__)
	else if (port == uart_port_usb3)
	{
		g_UsbACM[usb_port].data_if_info->ifdscr.stdif.iInterface = USB_Get_String_Number((void *)g_UsbACM_Comm.acm_param->data_interface_string_3);
		g_UsbACM[usb_port].data_ep_in_info->ep_reset = USB_Acm3_BulkIn_Reset;
		g_UsbACM[usb_port].data_ep_out_info->ep_reset = USB_Acm3_BulkOut_Reset;
	}
	else if (port == uart_port_usb4)
	{
		g_UsbACM[usb_port].data_if_info->ifdscr.stdif.iInterface = USB_Get_String_Number((void *)g_UsbACM_Comm.acm_param->data_interface_string_3);
		g_UsbACM[usb_port].data_ep_in_info->ep_reset = USB_Acm4_BulkIn_Reset;
		g_UsbACM[usb_port].data_ep_out_info->ep_reset = USB_Acm4_BulkOut_Reset;
	}
	else if (port == uart_port_usb5)
	{
		g_UsbACM[usb_port].data_if_info->ifdscr.stdif.iInterface = USB_Get_String_Number((void *)g_UsbACM_Comm.acm_param->data_interface_string_3);
		g_UsbACM[usb_port].data_ep_in_info->ep_reset = USB_Acm5_BulkIn_Reset;
		g_UsbACM[usb_port].data_ep_out_info->ep_reset = USB_Acm5_BulkOut_Reset;
	}
#endif
#endif

	/* TX Endpoint handler */
	USB_Register_Drv_Info(USB_DRV_HDLR_EP_TX, ep_tx_id, NULL);


	/* RX Endpoint handler */
	if(USB_IS_LOGGING_PORT[port] == KAL_TRUE)
	{
#ifdef __USB_LOGGING__
		USB_Register_Drv_Info(USB_DRV_HDLR_EP_RX, ep_rx_id, NULL);
#else
		ASSERT(0);
#endif
	}
	else if(g_UsbACM_Comm.acm_owner == USB_ACM_OWNER_FT)
	{
		if (USBDL_Mode_Type()!= USBDL_MODE_NONE)//((USBDL_Is_USB_Download_Mode() == KAL_TRUE) || (USBDL_Is_USB_Fast_Meta_Mode()== KAL_TRUE))
			USB_Register_Drv_Info(USB_DRV_HDLR_EP_RX, ep_rx_id, USB_Acm1_BulkOut_Hdr);
		else
			USB_Register_Drv_Info(USB_DRV_HDLR_EP_RX, ep_rx_id, USB_Acm_FT_BulkOut_Hdr);
	}
	else
	{
#ifdef __USB_STRESS_TEST__
		USB_Register_Drv_Info(USB_DRV_HDLR_EP_RX, ep_rx_id, NULL);
#else

		if(port == uart_port_usb)
		{
			USB_Register_Drv_Info(USB_DRV_HDLR_EP_RX, ep_rx_id, USB_Acm1_BulkOut_Hdr);
		}
#if defined(__USB_MULTIPLE_COMPORT_SUPPORT__)
		else if (port == uart_port_usb2)
		{
			USB_Register_Drv_Info(USB_DRV_HDLR_EP_RX, ep_rx_id, USB_Acm2_BulkOut_Hdr);
		}
#if defined (__USB_MODEM_CARD_SUPPORT__)
		else if (port == uart_port_usb3)
		{
			USB_Register_Drv_Info(USB_DRV_HDLR_EP_RX, ep_rx_id, USB_Acm3_BulkOut_Hdr);
		}
		else if (port == uart_port_usb4)
		{
			USB_Register_Drv_Info(USB_DRV_HDLR_EP_RX, ep_rx_id, USB_Acm4_BulkOut_Hdr);
		}
		else if (port == uart_port_usb5)
		{
			USB_Register_Drv_Info(USB_DRV_HDLR_EP_RX, ep_rx_id, USB_Acm5_BulkOut_Hdr);
		}
#endif
#endif
#endif
	}


	/* Endpoint descriptor */
	g_UsbACM[usb_port].data_ep_in_info->epdesc.stdep.bEndpointAddress = (USB_EP_DIR_IN|ep_tx_id);   /*InPipe*/

	g_UsbACM[usb_port].data_ep_in_info->ep_status.epin_status.byEP = ep_tx_id;
	g_UsbACM[usb_port].data_ep_in_info->ep_status.epin_status.nBytesLeft = USB_EP_NODATA;

	g_UsbACM[usb_port].data_ep_out_info->epdesc.stdep.bEndpointAddress = (USB_EP_DIR_OUT|ep_rx_id);   /*OutPipe*/

	g_UsbACM[usb_port].data_ep_out_info->ep_status.epout_status.byEP = ep_rx_id;

	USB_Get_DMA_Channel(ep_tx_id, 0, USB_EP_TX_DIR, KAL_FALSE);
#if defined(IC_MODULE_TEST) && !defined(__SLT_MD_CATCHER_LOG_VIA_USB__)
    USB_Get_DMA_Channel(0, ep_rx_id, USB_EP_RX_DIR, KAL_FALSE);
#endif
#ifdef __USB_STRESS_TEST__
#ifdef __USB_HS_ENABLE__ //use two DMA channel
	USB_Get_DMA_Channel(0, ep_out_id, USB_EP_RX_DIR, KAL_FALSE);
#endif
#endif

}




/* Data interface reset function, enable EP */
static void USB_Acm_DataIf_Reset(UART_PORT port)
{
	kal_uint32 usb_port = USB_PORT[port];
//	SGPT_CTRL_START_T start;

	g_UsbACM[usb_port].txpipe = &g_UsbACM[usb_port].data_ep_in_info->ep_status.epin_status;
	g_UsbACM[usb_port].rxpipe = &g_UsbACM[usb_port].data_ep_out_info->ep_status.epout_status;

	if((g_UsbACM[usb_port].send_UARTilm == KAL_TRUE)&&(USB2UARTPort[usb_port].ownerid != MOD_DRV_HISR))
	{
		g_UsbACM[usb_port].send_UARTilm = KAL_FALSE;
		USB2UART_Sendilm(port, MSG_ID_UART_PLUGOUT_IND);
	}

//#ifdef  __MTK_INTERNAL__
#if 0 //disable DMAlog
#ifdef __GEMINI__
/* under construction !*/
#else
/* under construction !*/
#endif /* __GEMINI__ */
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

//	if((USB2UARTPort[usb_port].handle == 0)||(USB2UARTPort[usb_port].handle == 0x7F))
//	{
		USB_GPTI_GetHandle(&(USB2UARTPort[usb_port].handle));//DclSGPT_Open(DCL_GPT_CB, 0);
//	}
	
//	if((g_UsbACM[usb_port].ring_buffer_handle == 0)||(g_UsbACM[usb_port].ring_buffer_handle == 0x7F))
//	{
		 USB_GPTI_GetHandle(&(g_UsbACM[usb_port].ring_buffer_handle));//DclSGPT_Open(DCL_GPT_CB, 0);
//	}
	
//	if((g_UsbACM[usb_port].handle == 0)||(g_UsbACM[usb_port].handle == 0x7F))
//	{
		 USB_GPTI_GetHandle(&(g_UsbACM[usb_port].handle));//DclSGPT_Open(DCL_GPT_CB, 0);
//	}
}




static void USB_Acm_DataIf_Enable(UART_PORT port)
{
	kal_uint32 usb_port = USB_PORT[port];


//#ifdef __USB_DOWNLOAD__
	if(USBDL_Mode_Type()== USBDL_MODE_USB_DOWNLOAD)//(USBDL_Is_USB_Download_Mode()== KAL_TRUE)
	{
		/* DMA */
		USB_TxEPEn(g_UsbACM[usb_port].txpipe->byEP, USB_ENDPT_BULK, USB_EP_USE_ONLY_DMA, KAL_FALSE, KAL_TRUE);
		/* Non-DMA */
		USB_RxEPEn(g_UsbACM[usb_port].rxpipe->byEP, USB_ENDPT_BULK, USB_EP_USE_NO_DMA, KAL_FALSE, KAL_TRUE);
	}
	else
	{
		/* DMA */
		USB_TxEPEn(g_UsbACM[usb_port].txpipe->byEP, USB_ENDPT_BULK, USB_EP_USE_ONLY_DMA, KAL_TRUE, KAL_FALSE);
		/*Non-DMA*/
		#if defined(IC_MODULE_TEST) && !defined(__SLT_MD_CATCHER_LOG_VIA_USB__)
	  	USB_RxEPEn(g_UsbACM[usb_port].rxpipe->byEP, USB_ENDPT_BULK, USB_EP_USE_ONLY_DMA, KAL_TRUE, KAL_FALSE);
		#else
		USB_RxEPEn(g_UsbACM[usb_port].rxpipe->byEP, USB_ENDPT_BULK, USB_EP_USE_NO_DMA, KAL_TRUE, KAL_FALSE);
		#endif
	}
//#else
//	/* DMA */
//	USB_TxEPEn(g_UsbACM[usb_port].txpipe->byEP, USB_ENDPT_BULK, USB_EP_USE_ONLY_DMA, KAL_TRUE, KAL_FALSE);
//	/* Non-DMA */
//	USB_RxEPEn(g_UsbACM[usb_port].rxpipe->byEP, USB_ENDPT_BULK, USB_EP_USE_NO_DMA, KAL_TRUE, KAL_FALSE);
//#endif
}




/* data interface speed reset function, enable EP's speed-specific descriptor */
static void USB_Acm_DataIf_Speed_Reset(UART_PORT port, kal_bool b_other_speed)
{
#ifdef __USB_HS_ENABLE__
	kal_uint32 usb_port = USB_PORT[port];
	kal_uint32	temp_max_size;

	temp_max_size = USB_Speed_Reset_Packet_Size(b_other_speed);	
	
	g_UsbACM[usb_port].data_ep_in_info->epdesc.stdep.wMaxPacketSize[0] = temp_max_size&0xff;
	g_UsbACM[usb_port].data_ep_in_info->epdesc.stdep.wMaxPacketSize[1] = (temp_max_size>>8)&0xff;
	
	g_UsbACM[usb_port].data_ep_out_info->epdesc.stdep.wMaxPacketSize[0] = temp_max_size&0xff;
	g_UsbACM[usb_port].data_ep_out_info->epdesc.stdep.wMaxPacketSize[1] = (temp_max_size>>8)&0xff;

#endif
}



#if (defined(__USB_COMPORT_SUPPORT_TC01_DRIVER__)&&defined(__USB_MULTIPLE_COMPORT_SUPPORT__))

void USB_Acm_VendorIf_Create(void *ifname)
{
	kal_uint8 ep_tx_id;
	kal_uint8 ep_rx_id;
	kal_uint8 if_id;


	/* Get resource number and register to gUsbDevice */
	g_UsbACM[1].data_if_info = USB_Get_Interface_Number(&if_id);
//	g_UsbACM[1].data_interface_id = if_id;
	g_UsbACM[1].data_ep_in_info = USB_Get_Bulk_Tx_Ep(&ep_tx_id);
	g_UsbACM[1].data_ep_out_info = USB_Get_Bulk_Rx_Ep(&ep_rx_id);

	/* Record interface name and interface descriptor length */
	g_UsbACM[1].data_if_info->interface_name_ptr = (kal_char *)ifname;
	g_UsbACM[1].data_if_info->ifdscr_size = USB_IFDSC_LENGTH;
	g_UsbACM[1].data_ep_in_info->epdscr_size = USB_EPDSC_LENGTH;
	g_UsbACM[1].data_ep_out_info->epdscr_size = USB_EPDSC_LENGTH;

	/* Related endpoint info and class specific command handler*/
	g_UsbACM[1].data_if_info->ep_info[0] = g_UsbACM[1].data_ep_in_info;
	g_UsbACM[1].data_if_info->ep_info[1] = g_UsbACM[1].data_ep_out_info;
	g_UsbACM[1].data_if_info->if_class_specific_hdlr = NULL;

	kal_mem_cpy(&(g_UsbACM[1].data_if_info->ifdscr.stdif), cdcacm_TC01_data_if_dscr, USB_IFDSC_LENGTH);
	kal_mem_cpy(&(g_UsbACM[1].data_ep_in_info->epdesc.stdep), cdcacm_ep_in_dscr, USB_EPDSC_LENGTH);
	kal_mem_cpy(&(g_UsbACM[1].data_ep_out_info->epdesc.stdep), cdcacm_ep_out_dscr, USB_EPDSC_LENGTH);

	/* Standard interface descriptor */
	g_UsbACM[1].data_if_info->ifdscr.stdif.bInterfaceNumber = if_id;
	g_UsbACM[1].data_if_info->ifdscr.stdif.iInterface = USB_Get_String_Number((void *)g_UsbACM_Comm.acm_param->data_interface_string_2);

//	g_UsbACM[1].data_if_info->ifdscr.stdif.bLength = USB_IFDSC_LENGTH;
//	g_UsbACM[1].data_if_info->ifdscr.stdif.bDescriptorType = USB_INTERFACE;
//	g_UsbACM[1].data_if_info->ifdscr.stdif.bAlternateSetting = 0;
//	g_UsbACM[1].data_if_info->ifdscr.stdif.bNumEndpoints = USB_CDC_ACM_DATA_EP_NUMBER;
//	g_UsbACM[1].data_if_info->ifdscr.stdif.bInterfaceClass = 0xFF;
//	g_UsbACM[1].data_if_info->ifdscr.stdif.bInterfaceSubClass = 0xFF;
//	g_UsbACM[1].data_if_info->ifdscr.stdif.bInterfaceProtocol = 0xFF;

	/* Endpoint handler */
	USB_Register_Drv_Info(USB_DRV_HDLR_EP_TX, ep_tx_id, NULL);
	g_UsbACM[1].data_ep_in_info->ep_reset = USB_Acm2_BulkIn_Reset;

	USB_Register_Drv_Info(USB_DRV_HDLR_EP_RX, ep_rx_id, USB_Acm2_BulkOut_Hdr);
	g_UsbACM[1].data_ep_out_info->ep_reset = USB_Acm2_BulkOut_Reset;

	/* Endpoint descriptor */
	g_UsbACM[1].data_ep_in_info->epdesc.stdep.bEndpointAddress = (USB_EP_DIR_IN|ep_tx_id);   /*InPipe*/
	g_UsbACM[1].data_ep_in_info->ep_status.epin_status.byEP = ep_tx_id;
	g_UsbACM[1].data_ep_in_info->ep_status.epin_status.nBytesLeft = USB_EP_NODATA;

//	g_UsbACM[1].data_ep_in_info->epdesc.stdep.bLength = USB_EPDSC_LENGTH;
//	g_UsbACM[1].data_ep_in_info->epdesc.stdep.bDescriptorType = USB_ENDPOINT;
//	g_UsbACM[1].data_ep_in_info->epdesc.stdep.bmAttributes = USB_EP_BULK;
//#ifndef __USB_HS_ENABLE__
//	g_UsbACM[1].data_ep_in_info->epdesc.stdep.wMaxPacketSize[0] = USB_EP_BULK_MAXP&0xff;
//	g_UsbACM[1].data_ep_in_info->epdesc.stdep.wMaxPacketSize[1] = (USB_EP_BULK_MAXP>>8)&0xff;
//	g_UsbACM[1].data_ep_in_info->epdesc.stdep.wMaxPacketSize[1] = 0x00;
//#endif
//	g_UsbACM[1].data_ep_in_info->epdesc.stdep.bInterval = 0;
//	g_UsbACM[1].data_ep_out_info->epdesc.stdep.bLength = USB_EPDSC_LENGTH;
//	g_UsbACM[1].data_ep_out_info->epdesc.stdep.bDescriptorType = USB_ENDPOINT;

	g_UsbACM[1].data_ep_out_info->epdesc.stdep.bEndpointAddress = (USB_EP_DIR_OUT|ep_rx_id);   /*OutPipe*/
	g_UsbACM[1].data_ep_out_info->ep_status.epout_status.byEP = ep_rx_id;

//	g_UsbACM[1].data_ep_out_info->epdesc.stdep.bmAttributes = USB_EP_BULK;
//#ifndef __USB_HS_ENABLE__
//	g_UsbACM[1].data_ep_out_info->epdesc.stdep.wMaxPacketSize[0] = USB_EP_BULK_MAXP&0xff;
//	g_UsbACM[1].data_ep_out_info->epdesc.stdep.wMaxPacketSize[1] = (USB_EP_BULK_MAXP>>8)&0xff;
//	g_UsbACM[1].data_ep_out_info->epdesc.stdep.wMaxPacketSize[1] = 0x00;
//#endif
//	g_UsbACM[1].data_ep_out_info->epdesc.stdep.bInterval = 0;

	USB_Get_DMA_Channel(ep_tx_id, 0, USB_EP_TX_DIR, KAL_FALSE);
}


/* Data interface reset function, enable EP */
void USB_Acm_VendorIf_Reset(void)
{
	g_UsbACM[1].txpipe = &g_UsbACM[1].data_ep_in_info->ep_status.epin_status;
	g_UsbACM[1].rxpipe = &g_UsbACM[1].data_ep_out_info->ep_status.epout_status;
}


void USB_Acm_VendorIf_Enable(void)
{
//#ifdef __USB_DOWNLOAD__
	if (USBDL_Mode_Type()== USBDL_MODE_USB_DOWNLOAD)//(USBDL_Is_USB_Download_Mode() == KAL_TRUE)
	{
		/* DMA */
		USB_TxEPEn(g_UsbACM[1].txpipe->byEP, USB_ENDPT_BULK, USB_EP_USE_ONLY_DMA, KAL_FALSE, KAL_TRUE);
		/* Non-DMA */
		USB_RxEPEn(g_UsbACM[1].rxpipe->byEP, USB_ENDPT_BULK, USB_EP_USE_NO_DMA, KAL_FALSE, KAL_TRUE);
	}
	else
	{
		/* DMA */
		USB_TxEPEn(g_UsbACM[1].txpipe->byEP, USB_ENDPT_BULK, USB_EP_USE_ONLY_DMA, KAL_TRUE, KAL_FALSE);
		/*Non-DMA*/
		USB_RxEPEn(g_UsbACM[1].rxpipe->byEP, USB_ENDPT_BULK, USB_EP_USE_NO_DMA, KAL_TRUE, KAL_FALSE);
	}
//#else
//	/* DMA */
//	USB_TxEPEn(g_UsbACM[1].txpipe->byEP, USB_ENDPT_BULK, USB_EP_USE_ONLY_DMA, KAL_TRUE, KAL_FALSE);
//	/* Non-DMA */
//	USB_RxEPEn(g_UsbACM[1].rxpipe->byEP, USB_ENDPT_BULK, USB_EP_USE_NO_DMA, KAL_TRUE, KAL_FALSE);
//#endif
}


/* data interface speed reset function, enable EP's speed-specific descriptor */
void USB_Acm_VendorIf_Speed_Reset(kal_bool b_other_speed)
{
#ifdef __USB_HS_ENABLE__
	kal_uint32	temp_max_size;

	temp_max_size = USB_Speed_Reset_Packet_Size(b_other_speed);	

	g_UsbACM[1].data_ep_in_info->epdesc.stdep.wMaxPacketSize[0] = temp_max_size&0xff;
	g_UsbACM[1].data_ep_in_info->epdesc.stdep.wMaxPacketSize[1] = (temp_max_size>>8)&0xff;
	g_UsbACM[1].data_ep_out_info->epdesc.stdep.wMaxPacketSize[0] = temp_max_size&0xff;
	g_UsbACM[1].data_ep_out_info->epdesc.stdep.wMaxPacketSize[1] = (temp_max_size>>8)&0xff;
	
#endif
}

#endif  /* defined(__USB_COMPORT_SUPPORT_TC01_DRIVER__)&&defined(__USB_MULTIPLE_COMPORT_SUPPORT__) */

/************************************************************
	global variable g_UsbACM initialize and release functions
*************************************************************/
static void USB_Acm_Default_Setting(kal_uint32 usb_port)
{
	g_UsbACM[usb_port].txpipe = NULL;
	g_UsbACM[usb_port].rxpipe = NULL;
	g_UsbACM[usb_port].intrpipe = NULL;
	g_UsbACM[usb_port].data_interface_id = 0xFF;
	g_UsbACM[usb_port].break_detect = KAL_FALSE;
	g_UsbACM[usb_port].break_number = 0;
	g_UsbACM[usb_port].send_Txilm = KAL_FALSE;
	g_UsbACM[usb_port].send_Rxilm = KAL_TRUE;
	g_UsbACM[usb_port].send_UARTilm = KAL_FALSE;
	g_UsbACM[usb_port].ring_buffer_timer_counting = KAL_FALSE;
	g_UsbACM[usb_port].intr_state = ACM_INTR_IDLE;
	g_UsbACM[usb_port].setup_dma = KAL_FALSE;
	g_UsbACM[usb_port].line_state = 0;
	if(g_UsbACM[usb_port].put_start == KAL_TRUE)
	{
	   g_UsbACM[usb_port].dmaf_setmember |= 0x04;
	}	
	g_UsbACM[usb_port].dma_txcb_just_done = KAL_FALSE;
}

/* Initialize global variable g_UsbACM */
void USB_Init_Acm_Status(void)
{
	kal_uint32 usb_port;
#ifdef  __USB_HIGH_SPEED_COM_PORT_ENABLE__
	kal_uint32 count = 0;
#endif
	for(usb_port = 0; usb_port < MAX_USB_PORT_NUM; usb_port++)
	{

		USB_Acm_Default_Setting(usb_port);
/*		
		g_UsbACM[usb_port].txpipe = NULL;
		g_UsbACM[usb_port].rxpipe = NULL;
		g_UsbACM[usb_port].intrpipe = NULL;
		g_UsbACM[usb_port].data_interface_id = 0xFF;
		g_UsbACM[usb_port].break_detect = KAL_FALSE;
		g_UsbACM[usb_port].break_number = 0;
		g_UsbACM[usb_port].send_Txilm = KAL_FALSE;
		g_UsbACM[usb_port].send_Rxilm = KAL_TRUE;
		g_UsbACM[usb_port].send_UARTilm = KAL_FALSE;
		g_UsbACM[usb_port].ring_buffer_timer_counting = KAL_FALSE;
		g_UsbACM[usb_port].intr_state = ACM_INTR_IDLE;
		g_UsbACM[usb_port].setup_dma = KAL_FALSE;
		g_UsbACM[usb_port].dma_txcb_just_done = KAL_FALSE;
*/		
#ifdef  __USB_HIGH_SPEED_COM_PORT_ENABLE__
		/* Initialize the new Rx buffers */
		for(count = 0; count < USB_ACM_RX_BUFFER_NUM; count++)
			g_UsbACM[usb_port].rx_buf_data_len[count] =  0;
		
		g_UsbACM[usb_port].rx_buf_r_index = 0;
		g_UsbACM[usb_port].rx_buf_rc_index = 0;
		g_UsbACM[usb_port].rx_buf_w_index = 0;
		g_UsbACM[usb_port].rx_buf_count = 0;
		g_UsbACM[usb_port].b_data_left = KAL_FALSE;
		g_UsbACM[usb_port].b_rc_index_move = KAL_FALSE;
		/* If PPP does not call disable high speed IF yet, it maybe be ASSERT since state does not match between USB and PPP */
		if(USB2UARTPort[usb_port].ownerid != MOD_PPP)
		{	
#ifdef __USB_TETHERING__	
			if (USB2UARTPort[usb_port].ownerid != MOD_UPS_HIGH)
#endif				
			g_UsbACM[usb_port].b_is_high_speed_enable = KAL_FALSE;
		}
#endif
	}
	
}


/* Release global variable g_UsbACM */
void USB_Release_Acm_Status(void)
{
	kal_uint32 usb_port;
#ifdef  __USB_HIGH_SPEED_COM_PORT_ENABLE__		
	kal_uint8 index;
#endif	
//	DCL_HANDLE handle;


	for(usb_port = 0; usb_port < MAX_USB_PORT_NUM; usb_port++)
	{
		if(g_UsbACM[usb_port].txpipe != NULL)
			USB_Free_DMA_Channel(g_UsbACM[usb_port].txpipe->byEP, 0, USB_EP_TX_DIR, KAL_FALSE);

		USB_Acm_Default_Setting(usb_port);

		USB2UARTPort[usb_port].RingBuffers.txISR_buffer = NULL;
		USB2UARTPort[usb_port].RingBuffers.tx_buffer = NULL; 
		USB2UARTPort[usb_port].RingBuffers.rx_buffer = NULL;

#ifdef  __USB_HIGH_SPEED_COM_PORT_ENABLE__		
		/* Initialize the new Rx buffers */
		for(index = 0; index < USB_ACM_RX_BUFFER_NUM; index++)
		{
//			g_UsbACM_Comm.rx_buf_addr[index] = NULL;				
//			g_UsbACM[usb_port].rx_buf_addr[index] = NULL;// cannot release buffer pointer, because UPS need to pop buffer
		}
#endif		
// work around for TST (TST should close port when cable out & open port when cable in)		
//		Buf_init(&(USB2UARTPort[usb_port].Tx_Buffer_ISR), (kal_uint8 *)(USB2UARTPort[usb_port].RingBuffers.txISR_buffer),0);
//		Buf_init(&(USB2UARTPort[usb_port].Tx_Buffer), (kal_uint8 *)(USB2UARTPort[usb_port].RingBuffers.tx_buffer),0);
//		Buf_init(&(USB2UARTPort[usb_port].Rx_Buffer), (kal_uint8 *)(USB2UARTPort[usb_port].RingBuffers.rx_buffer),0);
		
/*		
		g_UsbACM[usb_port].txpipe = NULL;
		g_UsbACM[usb_port].rxpipe = NULL;
		g_UsbACM[usb_port].intrpipe = NULL;
		g_UsbACM[usb_port].data_interface_id = 0xFF;
		g_UsbACM[usb_port].break_detect = KAL_FALSE;
		g_UsbACM[usb_port].break_number = 0;
		g_UsbACM[usb_port].send_Txilm = KAL_FALSE;
		g_UsbACM[usb_port].send_Rxilm = KAL_TRUE;
		g_UsbACM[usb_port].send_UARTilm = KAL_FALSE;
		g_UsbACM[usb_port].ring_buffer_timer_counting = KAL_FALSE;
		g_UsbACM[usb_port].intr_state = ACM_INTR_IDLE;
		g_UsbACM[usb_port].setup_dma = KAL_FALSE;
		g_UsbACM[usb_port].dma_txcb_just_done = KAL_FALSE;
*/		

		g_UsbACM[usb_port].config_send_Txilm = KAL_FALSE;

#ifdef  __USB_HIGH_SPEED_COM_PORT_ENABLE__
#ifdef __USB_SW_DMA_DIV__
		g_UsbACM[usb_port].tx_temp_buf_addr = NULL;
#endif
		g_UsbACM[usb_port].rx_flc_temp_buf_addr = NULL;
#endif

#if defined(__USB_BOOTUP_TRACE__)
		if (!(is_init_log_enable == KAL_TRUE && is_init_stage == KAL_TRUE))
#endif
		{
			//		if((USB2UARTPort[usb_port].handle != 0)&&(USB2UARTPort[usb_port].handle != 0x7F))
			//		{
						USB_GPTI_ReleaseHandle(&(USB2UARTPort[usb_port].handle));  /* for escape character use!!*/
						//GPTI_ReleaseHandle(&USB2UARTPort[usb_port].handle);  /* for escape character use!!*/
			//			handle = (DCL_HANDLE)USB2UARTPort[usb_port].handle;
			//			USB2UARTPort[usb_port].handle = DclSGPT_Close(&handle);
			//		}
			
			//		if((g_UsbACM[usb_port].ring_buffer_handle != 0)&&(g_UsbACM[usb_port].ring_buffer_handle != 0x7F))
			//		{
						USB_GPTI_ReleaseHandle(&(g_UsbACM[usb_port].ring_buffer_handle));  /* for ring buffer time out use!!*/
						//GPTI_ReleaseHandle(&g_UsbACM[usb_port].ring_buffer_handle);  /* for ring buffer time out use!!*/
			//			handle = (DCL_HANDLE)g_UsbACM[usb_port].ring_buffer_handle;
			//			g_UsbACM[usb_port].ring_buffer_handle = DclSGPT_Close(&handle);
			//		}
			
			//		if((g_UsbACM[usb_port].handle != 0)&&(g_UsbACM[usb_port].handle != 0x7F))
			//		{
						USB_GPTI_ReleaseHandle(&(g_UsbACM[usb_port].handle));	/*for break use!!*/
						//GPTI_ReleaseHandle(&g_UsbACM[usb_port].handle);   /*for break use!!*/
			//			handle = (DCL_HANDLE)g_UsbACM[usb_port].handle;
			//			g_UsbACM[usb_port].handle = DclSGPT_Close(&handle);
			//		}
			//#ifdef  __MTK_INTERNAL__
			#if 0 //disable DMAlog
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
			#endif
		}
	}
}



/***********************************************************
   	GPT timer handle break signal
************************************************************/

/* GPT timer handler for break signal */
static void USB_Acm_Break_Timeout(void *parameter)
{
	UsbUARTStruct *UARTData = (UsbUARTStruct *)parameter;
	kal_uint32 usb_port = USB_PORT[(kal_uint32)(UARTData->port_no)];


	if((g_UsbACM[usb_port].handle != 0)&&(g_UsbACM[usb_port].handle != 0x7F))
	{
		USB_GPTI_StopItem(g_UsbACM[usb_port].handle);
//		DclSGPT_Control((DCL_HANDLE)(g_UsbACM[usb_port].handle), SGPT_CMD_STOP, 0);
	}

	g_UsbACM[usb_port].break_detect = KAL_FALSE;
	g_UsbACM[usb_port].break_number++;
	USB2UARTPort[usb_port].breakDet = KAL_TRUE;
}


/***********************************************************
   	DMA  timer handle break signal
************************************************************/
//#ifdef  __MTK_INTERNAL__
#if 0 //disable DMAlog
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
#endif /* __MTK_INTERNAL__ */

/************************************************************
	Ring buffer threshold and time out mechanism APIs
************************************************************/
/* GPT timer handler for ring buffer time out  */
static void USB_Acm_Ring_Buffer_Timeout(void *parameter)
{
	UsbUARTStruct *UARTData = (UsbUARTStruct *)parameter;
	kal_uint32 usb_port = USB_PORT[(kal_uint32)(UARTData->port_no)];
	kal_uint32 addr;
	kal_uint32 length = 0;
#ifdef __USB_SW_DMA_DIV__
	kal_uint32 short_pkt_length;
#endif
	kal_uint32 savedMask;
	kal_uint8 ep_num = 0;
	kal_bool setup_dma = KAL_FALSE;
	usb_dma_callback  dma_callback;
//	USB_DRV_CTRL_GET_IP_VERSION_T dcl_data;


	if(INT_Exception_Enter != 0)
		ASSERT(0);

	/* DRV_HISR does not need to close I-bit */
	savedMask = SaveAndSetIRQMask();
	/* In case USB is plugged out just before this critical section */
	if((g_UsbACM[usb_port].txpipe != NULL)&&(USB_Get_Device_State() == DEVSTATE_CONFIG))
//	if(g_UsbACM[usb_port].txpipe != NULL)
	{
		if(g_UsbACM[usb_port].setup_dma == KAL_FALSE)
		{
			g_UsbACM[usb_port].setup_dma = KAL_TRUE;
			setup_dma = KAL_TRUE;
			ep_num = g_UsbACM[usb_port].txpipe->byEP;
		}
	}
	RestoreIRQMask(savedMask);

	if(setup_dma == KAL_TRUE)
	{
//		savedMask = SaveAndSetIRQMask();
		length = USB2UART_Check_Transmit_Data(UARTData->port_no, &addr, KAL_FALSE);
//		RestoreIRQMask(savedMask);

		if(length != 0)
		{
			USB_Dbg_Trace(USB_ACM_DMA_SETUP_4, length, (kal_uint32)USB2Uart_MemType[usb_port]);

			dma_callback = USB_COM_DMA_Callback(UARTData->port_no);

/*
			if(UARTData->port_no == uart_port_usb)
				dma_callback = USB2UART_Tx_DMA1_Callback;
	#if defined(__USB_MULTIPLE_COMPORT_SUPPORT__)
			else if(UARTData->port_no == uart_port_usb2)
				dma_callback = USB2UART_Tx_DMA2_Callback;
	#if defined (__USB_MODEM_CARD_SUPPORT__)
			else if(UARTData->port_no == uart_port_usb3)
				dma_callback = USB2UART_Tx_DMA3_Callback;
	#endif
	#endif
			else
			{
				dma_callback = NULL;
				ASSERT(0);
			}

*/

#ifdef __USB_SW_DMA_DIV__
			/* Get IP version */
//			DclUSB_DRV_Control(g_USB_Dcl_Handle, USB_DRV_CMD_GET_IP_VERSION, (DCL_CTRL_DATA_T  *)&dcl_data);

//			if(USB_IP_Version() == DCL_USB_IP_V3)
//			{
				/* Check one short packet length first here, only need to care about when length > 12 */
				if((length > 12)&&(addr&0x03))
				{
					short_pkt_length = 4-(addr&0x03);

					/* Send one short packet here */
					if(USB_Is_EP_Tx_Empty(ep_num, USB_ENDPT_BULK) == KAL_TRUE)
					{
						/* FIFO is empty */
						USB_EPFIFOWrite(ep_num, short_pkt_length, (kal_uint8*)addr);
						USB_EP_Tx_Ready(ep_num, USB_ENDPT_BULK);
						addr += short_pkt_length;
						length -= short_pkt_length;
						USB_Dbg_Trace(USB_ACM_SEND_SHORT_PKT, short_pkt_length, length);
					}
					else
					{
						/* FIFO is not empty, Trigger DMA for short packet only, and make sure next time will be 4 bytes alignment */
						length = short_pkt_length;
						USB2Uart_WriteLength[usb_port] = short_pkt_length;
						USB_Dbg_Trace(USB_ACM_DMA_SEND_SHORT_PKT, short_pkt_length, (kal_uint32)USB2Uart_MemType[usb_port]);
					}
				}
//			}
#endif
			USB_DMA_Setup(ep_num, USB_EP_TX_DIR, USB_ENDPT_BULK, addr, length, dma_callback, KAL_FALSE, KAL_TRUE, USB_DMA1_TYPE);
		}
		else
		{
			g_UsbACM[usb_port].setup_dma = KAL_FALSE;
			if(g_UsbACM[usb_port].put_start == KAL_TRUE)
			{
			   g_UsbACM[usb_port].dmaf_setmember |= 0x08;
			}			
		}
	}
}


void USB_Acm_Ring_Buffer_Threshold_Enable(UART_PORT port, kal_bool bset, module_type ownerid)
{
	kal_uint32 usb_port = USB_PORT[port];
//	DCL_HANDLE usb_dcl_handle;
//	DCL_BOOL dcl_data;
//	kal_bool b_is_dl_mode;


	USB_Check_Owner(ownerid,USB2UARTPort[usb_port].ownerid);

//#ifdef __USB_DOWNLOAD__
//	usb_dcl_handle = DclUSB_DRV_Open(DCL_USB, FLAGS_NONE);

//	DclUSB_DRV_Control(usb_dcl_handle, USB_DRV_CMD_USBDL_IS_USB_DL_MODE, (DCL_CTRL_DATA_T  *)&dcl_data);
//	b_is_dl_mode = (kal_bool)dcl_data;

//	if(USBDL_Is_USB_Download_Mode() == KAL_FALSE)
	if(USBDL_Mode_Type()== USBDL_MODE_NONE)//((USBDL_Is_USB_Download_Mode() == KAL_FALSE) && (USBDL_Is_USB_Fast_Meta_Mode()== KAL_FALSE))
//#endif
	{
		g_UsbACM[usb_port].threshold_enable = bset;

		if(bset == KAL_TRUE)
		{
			usb_drv_trace1(USB2UARTPort[usb_port].ownerid, (kal_uint32)USBACM_THRESHOLD_ON, usb_port);

			/* To reduce GPT handler number, only be enabled will get the GPT timer handler */
//			if((g_UsbACM[usb_port].ring_buffer_handle == 0)||(g_UsbACM[usb_port].ring_buffer_handle == 0x7F))
//			{
				//GPTI_GetHandle(&g_UsbACM[usb_port].ring_buffer_handle);   /* for ring buffer time out use!!*/
				 USB_GPTI_GetHandle(&(g_UsbACM[usb_port].ring_buffer_handle));//DclSGPT_Open(DCL_GPT_CB, 0);
//			}
		}
		else
		{
			usb_drv_trace1(USB2UARTPort[usb_port].ownerid, (kal_uint32)USBACM_THRESHOLD_OFF, usb_port);
		}
	}

//	DclUSB_DRV_Close(usb_dcl_handle);
}


/************************************************************
	EP0 handle functions
************************************************************/

/* Set USB request line coding to UART DCB structure */
static void USB_Acm_Ep0_SetLineCoding(UART_PORT port, void *data)
{
	kal_uint32 usb_port = USB_PORT[port];
	kal_uint32 nCount;
	kal_bool stall = KAL_FALSE;


	/* Read setting and set to UART structure */
	nCount = USB_EP0_Pkt_Len();
	USB_Dbg_Trace(USB_ACM_RX_PKT, nCount, 0xFF);

	if(nCount == 7)
	{
		USB_EPFIFORead(0, nCount, &g_UsbACM[usb_port].line_coding, KAL_FALSE);
   		USB2UART_LineCoding2DCB(&g_UsbACM[usb_port].line_coding, &USB2UARTPort[usb_port].DCB);
	}
	else
	{
		stall = KAL_TRUE;
	}

	USB_Set_Endpoint0_State(USB_EP0_RX_STATUS);
	USB_Update_EP0_State(USB_EP0_DRV_STATE_READ_END, stall, KAL_TRUE);
}


	

/* Parse class specific request */
static void USB_Acm_Ep0_Command(UART_PORT port, Usb_Ep0_Status* pep0state, Usb_Command* pcmd)
{
	kal_uint32 usb_port = USB_PORT[port];
	kal_bool  bError = KAL_FALSE;
//	SGPT_CTRL_START_T start;


	usb_drv_trace2(USB2UARTPort[usb_port].ownerid, (kal_uint32)USBACM_EP0_COMMAND,(kal_uint32)pcmd->bRequest, usb_port);

	switch (pcmd->bRequest)
	{
	case USB_ACM_SET_LINE_CODING:
		/* register handler to handle the get data*/
		if(port == uart_port_usb)
			USB_Register_EP0_RxHdlr(USB_Acm1_Ep0_SetLineCoding);
#if defined(__USB_MULTIPLE_COMPORT_SUPPORT__)
		else if(port == uart_port_usb2)
			USB_Register_EP0_RxHdlr(USB_Acm2_Ep0_SetLineCoding);
#if defined (__USB_MODEM_CARD_SUPPORT__)
		else if(port == uart_port_usb3)
			USB_Register_EP0_RxHdlr(USB_Acm3_Ep0_SetLineCoding);
		else if(port == uart_port_usb4)
			USB_Register_EP0_RxHdlr(USB_Acm4_Ep0_SetLineCoding);
		else if(port == uart_port_usb5)
			USB_Register_EP0_RxHdlr(USB_Acm5_Ep0_SetLineCoding);
#endif
#endif
		USB_Set_Endpoint0_State(USB_EP0_RX);
		break;
	case USB_ACM_GET_LINE_CODING:
		/* tell host the current setting */
		USB_Generate_EP0Data(pep0state, pcmd, &g_UsbACM[usb_port].line_coding, 7);
		break;
	case USB_ACM_SET_CONTROL_LINE_STATE:
		g_UsbACM[usb_port].line_state = pcmd->wValue;
		if(USB2UARTPort[usb_port].ownerid == MOD_PPP)
		{
			USB2UART_Sendilm(port, MSG_ID_UART_DSR_CHANGE_IND);		
		}
		/* do not need to do anything */
		break;
	case USB_ACM_SEND_BREAK:
		/* Break behavior */
		switch(pcmd->wValue)
		{
		case 0xffff:
			g_UsbACM[usb_port].break_detect = KAL_TRUE;
			break;
		case 0x0:
			g_UsbACM[usb_port].break_detect = KAL_FALSE;
			g_UsbACM[usb_port].break_number++;
			USB2UARTPort[usb_port].breakDet = KAL_TRUE;
			break;
		default:
//			if((g_UsbACM[usb_port].handle == 0)||(g_UsbACM[usb_port].handle == 0x7F))
//			{
				//GPTI_GetHandle(&g_UsbACM[usb_port].handle);   /*for break use!!*/
				USB_GPTI_GetHandle(&(g_UsbACM[usb_port].handle));//DclSGPT_Open(DCL_GPT_CB, 0);
//			}

			USB_GPTI_StopItem(g_UsbACM[usb_port].handle);
//			DclSGPT_Control((DCL_HANDLE)(g_UsbACM[usb_port].handle), SGPT_CMD_STOP, 0);
			
			g_UsbACM[usb_port].break_detect = KAL_TRUE;
			USB_GPTI_StartItem(g_UsbACM[usb_port].handle, (pcmd->wValue/10),USB_Acm_Break_Timeout, &USB2UARTPort[usb_port]);
//			start.u2Tick = (pcmd->wValue/10);
//			start.pfCallback = USB_Acm_Break_Timeout;
//			start.vPara = &USB2UARTPort[usb_port];
//			DclSGPT_Control((DCL_HANDLE)(g_UsbACM[usb_port].handle), SGPT_CMD_START, (DCL_CTRL_DATA_T*)&start);
			break;
		}
		break;
		
	case USB_ACM_SEND_ENCAPSULATED_COMMAND:
	case USB_ACM_GET_ENCAPSULATED_RESPONSE:
	case USB_ACM_SET_COMM_FEATURE:
	case USB_ACM_GET_COMM_FEATURE:
	case USB_ACM_CLEAR_COMM_FEATURE:
	default:
		bError = KAL_TRUE;
		break;
	}

	/* Stall command if an error occured */
	USB_EP0_Command_Hdlr(bError);
/*	
	if(USB_Get_Endpoint0_State() == USB_EP0_IDLE)
	{
		USB_Set_Endpoint0_State(USB_EP0_RX_STATUS);

		USB_Update_EP0_State(USB_EP0_DRV_STATE_READ_END, bError, KAL_TRUE);
	}
	else
	{
		USB_Update_EP0_State(USB_EP0_DRV_STATE_READ_END, bError, KAL_FALSE);
	}
*/	
}




/************************************************************
	Bulk EP OUT handle functions
*************************************************************/

/*
    Used to retreive exception log, all interrupts are disabled
    Note that this is special for sending exception log since interrupt is disabled when exception occurs
    It must not be used in normal time
*/
void USB2UART_Polling_Recv_Data(UART_PORT port)
{
	kal_uint32 usb_port = USB_PORT[port];

	/* This function can only be called after exception*/
//	if(INT_Exception_Enter == 0)
//		ASSERT(0);

//	USB_Exception_Check();

	/* Avoid sending ilm to UART owner*/
	g_UsbACM[usb_port].send_Txilm = KAL_FALSE;
	g_UsbACM[usb_port].send_Rxilm = KAL_FALSE;

	USB_Polling_Recv_Data();
}


/* 14MB/s version, handle multiple packets inside one ISR */

/* EP Bulk Out interrupt handler, called by EP interrupt */
static void USB_Acm_BulkOut_Hdr(UART_PORT port)
{
	kal_uint32 usb_port = USB_PORT[port];
	kal_uint32 RoomLeft;
	kal_uint32 nCount;
	kal_uint32 index;
#if defined(__USB_HIGH_SPEED_COM_PORT_ENABLE__)&& (!defined(DRV_USB_DMA_QUEUE_SUPPORT))
	kal_uint32 loop_count = 0;
#endif
	kal_uint8 data[3];
	kal_int32 remain;
	BUFFER_INFO *rx_buf_info = &(USB2UARTPort[usb_port].Rx_Buffer);
	kal_uint32 max_bulk_pkt_size;
	static kal_bool esc_timer_is_running = KAL_TRUE;
//	SGPT_CTRL_START_T start;

	//Assert dump: only TST can use USB in exception mode.
	if((USB_Exception_Check() == KAL_FALSE)&&(USB2UARTPort[usb_port].ownerid != MOD_TST_READER))
//	if((INT_Exception_Enter != 0 || (is_init_log_enable == KAL_TRUE && is_init_stage == KAL_TRUE))&&(USB2UARTPort[usb_port].ownerid != MOD_TST_READER))
		return;

	USB_Dbg_Trace(USB_ACM_RX_PKT, (kal_uint32)port, USB2UARTPort[usb_port].ownerid);

	/* Check current packet's data length */
	nCount = USB_EP_Rx_Pkt_Len(g_UsbACM[usb_port].rxpipe->byEP);

	/* This log cannot be executed when assertion because the system stack will overflow */
	usb_drv_trace2(USB2UARTPort[usb_port].ownerid, (kal_uint32)USBACM_PC_SENT, nCount, usb_port);

	USB_Dbg_Trace(USB_ACM_RX_PKT_LENGTH, nCount, 0);


	/* Stop escape GPT timer */
	if((esc_timer_is_running == KAL_TRUE)&&(USB2UARTPort[usb_port].ESCDet.GuardTime != 0))
	{
		USB_GPTI_StopItem(USB2UARTPort[usb_port].handle);
//		DclSGPT_Control((DCL_HANDLE)(USB2UARTPort[usb_port].handle), SGPT_CMD_STOP, 0);
#ifdef  __USB_HIGH_SPEED_COM_PORT_ENABLE__
		esc_timer_is_running = KAL_FALSE;
#endif
	}


	/* No UART owner, drop the data directly */
	if((USB2UARTPort[usb_port].ownerid != MOD_DRV_HISR)&&(nCount != 0))
	{
		/* RX complete callback */
		USB2UARTPort[usb_port].rx_cb(port);
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

		max_bulk_pkt_size = USB_Bulk_Max_Packet_Size();



#ifdef  __USB_HIGH_SPEED_COM_PORT_ENABLE__
		if(g_UsbACM[usb_port].b_is_high_speed_enable == KAL_TRUE)
		{
#ifndef DRV_USB_DMA_QUEUE_SUPPORT		
			/* 0 must due to NULL packet */
			while((nCount != 0)&&(loop_count != USB_ACM_RX_HDLR_PACKET_NUM))
			{
				loop_count++;

				if(nCount > 4)
				{
					if(nCount <= (USB_ACM_RX_BUFFER_SIZE - g_UsbACM[usb_port].rx_buf_data_len[g_UsbACM[usb_port].rx_buf_w_index]))
					{
						USB_EPFIFORead(g_UsbACM[usb_port].rxpipe->byEP, nCount,
							g_UsbACM[usb_port].rx_buf_addr[g_UsbACM[usb_port].rx_buf_w_index]+(g_UsbACM[usb_port].rx_buf_data_len[g_UsbACM[usb_port].rx_buf_w_index]), KAL_FALSE);
					}
					else
					{
						EXT_ASSERT(0, nCount, USB_ACM_RX_BUFFER_SIZE, g_UsbACM[usb_port].rx_buf_data_len[g_UsbACM[usb_port].rx_buf_w_index]);
					}

					USB2UARTPort[usb_port].Rec_state = UART_RecNormal;
					USB2UARTPort[usb_port].EscCount = 0;
				}
				else
				{
					USB_EPFIFORead(g_UsbACM[usb_port].rxpipe->byEP, nCount, data, KAL_TRUE);

					/* Check escape character */
					if(USB2UARTPort[usb_port].ESCDet.GuardTime != 0)
					{
						/* Need to check escape charater */
						for(index = 0; index < nCount; index++)
						{
							/* detect escape sequence  */
							if(USB2UARTPort[usb_port].Rec_state != UART_RecNormal)
							{
								if (data[index] == USB2UARTPort[usb_port].ESCDet.EscChar)
								{
									USB_Dbg_Trace(USB_ACM_ESCAPE_CHAR, (kal_uint32)USB2UARTPort[usb_port].EscCount, 0);
									USB2UARTPort[usb_port].EscCount++;

									if(USB2UARTPort[usb_port].EscCount == 3)
									{
										USB2UARTPort[usb_port].Rec_state = UART_Get3EscChar;
									}
									else if(USB2UARTPort[usb_port].EscCount > 3)
									{
										USB2UARTPort[usb_port].Rec_state = UART_RecNormal;
										USB2UARTPort[usb_port].EscCount = 0;
									}
								}
								else
								{
									USB2UARTPort[usb_port].Rec_state = UART_RecNormal;
									USB2UARTPort[usb_port].EscCount = 0;
								}
							}
						}
					}

					kal_mem_cpy(g_UsbACM[usb_port].rx_buf_addr[g_UsbACM[usb_port].rx_buf_w_index]+(g_UsbACM[usb_port].rx_buf_data_len[g_UsbACM[usb_port].rx_buf_w_index]),
						data, nCount);
				}

				/* Clear RxPktRdy */
				USB_EP_Rx_Ready(g_UsbACM[usb_port].rxpipe->byEP, USB_ENDPT_BULK);

				g_UsbACM[usb_port].rx_buf_data_len[g_UsbACM[usb_port].rx_buf_w_index] += nCount;

				/* Update write pointer, decide to disable IRQ_USB or not */
				if((nCount != max_bulk_pkt_size)||(USB_ACM_RX_BUFFER_SIZE == g_UsbACM[usb_port].rx_buf_data_len[g_UsbACM[usb_port].rx_buf_w_index]))
				{
					/* Short packet or buffer full will update write index */
					g_UsbACM[usb_port].rx_buf_w_index++;

					if(g_UsbACM[usb_port].rx_buf_w_index == USB_ACM_RX_BUFFER_NUM)
						g_UsbACM[usb_port].rx_buf_w_index = 0;

					g_UsbACM[usb_port].rx_buf_count++;

					USB_Dbg_Trace(USB_ACM_HIGHSPEED_MOVE_W_INDEX, g_UsbACM[usb_port].rx_buf_w_index, g_UsbACM[usb_port].rx_buf_count);
					usb_drv_trace4(USB2UARTPort[usb_port].ownerid, (kal_uint32)USBACM_MOVE_W_INDEX, g_UsbACM[usb_port].rx_buf_w_index, g_UsbACM[usb_port].rx_buf_count, g_UsbACM[usb_port].rx_buf_rc_index, g_UsbACM[usb_port].rx_buf_r_index);

					if(g_UsbACM[usb_port].rx_buf_count > USB_ACM_RX_BUFFER_NUM)
						ASSERT(0);

					/* Decide if we need to disable USB_IRQ */
					if(g_UsbACM[usb_port].rx_buf_w_index == g_UsbACM[usb_port].rx_buf_rc_index)
					{
						loop_count = USB_ACM_RX_HDLR_PACKET_NUM;
						USB_Mask_COM_Intr(port);
/*
						if(port == uart_port_usb)
							USB_Mask_Irq(USB_MASK_OWNER_COM_1);
				#if defined(__USB_MULTIPLE_COMPORT_SUPPORT__)
						else if(port == uart_port_usb2)
							USB_Mask_Irq(USB_MASK_OWNER_COM_2);
				#if defined (__USB_MODEM_CARD_SUPPORT__)
						else if(port == uart_port_usb3)
							USB_Mask_Irq(USB_MASK_OWNER_COM_3);
				#endif
				
				#endif
*/				
					}
				}


				if(loop_count != USB_ACM_RX_HDLR_PACKET_NUM)
				{
					if(USB_Get_RX_EP_ISR_Status(g_UsbACM[usb_port].rxpipe->byEP) == KAL_TRUE)
					{
						nCount = USB_EP_Rx_Pkt_Len(g_UsbACM[usb_port].rxpipe->byEP);

						USB_Clr_RX_EP_ISR(g_UsbACM[usb_port].rxpipe->byEP);

						/* 0 must due to NULL packet */
						if(nCount == 0)
							USB_EP_Rx_Ready(g_UsbACM[usb_port].rxpipe->byEP, USB_ENDPT_BULK);

						usb_drv_trace2(USB2UARTPort[usb_port].ownerid, (kal_uint32)USBACM_PC_SENT, nCount, usb_port);

						USB_Dbg_Trace(USB_ACM_RX_NEXT_PKT_LENGTH, nCount, 0);
					}
					else
					{
						nCount = 0;
						USB_Dbg_Trace(USB_ACM_RX_NEXT_PKT_LENGTH, 0, 0);
					}
				}
			}
#else
	//		ASSERT(0);
			/* Clear RxPktRdy, drop this packet */
			usb_drv_trace4(USB2UARTPort[usb_port].ownerid, (kal_uint32)USBACM_MOVE_W_INDEX, 0xFF, 0xFF, 0xFF, 0xFF);
			USB_EP_Rx_Ready(g_UsbACM[usb_port].rxpipe->byEP, USB_ENDPT_BULK);
#endif
		}
		else
#endif /* __USB_HIGH_SPEED_COM_PORT_ENABLE__ */
		{
#if 0		
/* under construction !*/
#else
			RoomLeft = USB2UART_GetBuffRoomLeft(rx_buf_info);
#endif
			if((nCount > max_bulk_pkt_size)||(RoomLeft < nCount))
			{
				if (nCount > max_bulk_pkt_size) USB_DUMP();
				EXT_ASSERT(0, nCount, max_bulk_pkt_size, RoomLeft);
			}

			/* Update roomleft parameter*/
			RoomLeft -= nCount;

			if(RoomLeft < max_bulk_pkt_size)
			{
				/* RX buffer is less than one max packet size, so mask the IRQ until UART owner get bytes,
				    and than enough room to put a complete packet */
//				USB_Set_UnMask_Irq(KAL_FALSE);
				USB_Mask_COM_Intr(port);
/*
				if(port == uart_port_usb)
					USB_Mask_Irq(USB_MASK_OWNER_COM_1);
			#if defined(__USB_MULTIPLE_COMPORT_SUPPORT__)
				else if(port == uart_port_usb2)
					USB_Mask_Irq(USB_MASK_OWNER_COM_2);
			#if defined (__USB_MODEM_CARD_SUPPORT__)
				else if(port == uart_port_usb3)
					USB_Mask_Irq(USB_MASK_OWNER_COM_3);
			#endif
			
			#endif
*/
			}
			else
			{
				/* Make sure that buffer left more than 64 bytes so that next receive it can push to buffer at a time */
//				USB_Set_UnMask_Irq(KAL_TRUE);
//				USB_UnMask_COM_Intr(port);


/*
				if(port == uart_port_usb)
					USB_UnMask_Irq(USB_MASK_OWNER_COM_1);
			#if defined(__USB_MULTIPLE_COMPORT_SUPPORT__)
				else if(port == uart_port_usb2)
					USB_UnMask_Irq(USB_MASK_OWNER_COM_2);
			#endif
*/
			}

			if(nCount > 4)
			{
				remain = (kal_int32)((BWrite(rx_buf_info) + nCount) - BLength(rx_buf_info));

				if(remain < 0)
				{
					USB_EPFIFORead(g_UsbACM[usb_port].rxpipe->byEP, nCount, BuffWrite(rx_buf_info), KAL_FALSE);
					BWrite(rx_buf_info) += nCount;
				}
				else
				{
					USB_EPFIFORead(g_UsbACM[usb_port].rxpipe->byEP, (nCount-remain), BuffWrite(rx_buf_info), KAL_TRUE);
					USB_EPFIFORead(g_UsbACM[usb_port].rxpipe->byEP, remain, BStartAddr(rx_buf_info), KAL_TRUE);
					BWrite(rx_buf_info) = remain;
				}

				USB2UARTPort[usb_port].Rec_state = UART_RecNormal;
				USB2UARTPort[usb_port].EscCount = 0;
			}
			else
			{
				USB_EPFIFORead(g_UsbACM[usb_port].rxpipe->byEP, nCount, data, KAL_TRUE);

				/* Check escape character */
				if(USB2UARTPort[usb_port].ESCDet.GuardTime != 0)
				{
					/* Need to check escape charater */
					for(index = 0; index < nCount; index++)
					{
						/* detect escape sequence  */
						if(USB2UARTPort[usb_port].Rec_state != UART_RecNormal)
						{
							if(data[index] == USB2UARTPort[usb_port].ESCDet.EscChar)
							{
								USB_Dbg_Trace(USB_ACM_ESCAPE_CHAR, (kal_uint32)USB2UARTPort[usb_port].EscCount, 0);
								USB2UARTPort[usb_port].EscCount++;

								if(USB2UARTPort[usb_port].EscCount == 3)
								{
									USB2UARTPort[usb_port].Rec_state = UART_Get3EscChar;
								}
								else if(USB2UARTPort[usb_port].EscCount > 3)
								{
									USB2UARTPort[usb_port].Rec_state = UART_RecNormal;
									USB2UARTPort[usb_port].EscCount = 0;
								}
							}
							else
							{
								USB2UARTPort[usb_port].Rec_state = UART_RecNormal;
								USB2UARTPort[usb_port].EscCount = 0;
							}
						}
					}
				}

				/* Push all the received data into rx ring buffer */
				for(index = 0; index < nCount; index++)
				{
					Buf_Push(rx_buf_info, data[index]);
				}
			}

			/* Clear RxPktRdy */
			USB_EP_Rx_Ready(g_UsbACM[usb_port].rxpipe->byEP, USB_ENDPT_BULK);
		} /* if(g_UsbACM[usb_port].b_is_high_speed_enable == KAL_TRUE) */
	}
	else /* if((USB2UARTPort[usb_port].ownerid != MOD_DRV_HISR)||(nCount != 0)) */
	{
		/* Clear RxPktRdy, drop this packet */
		USB_EP_Rx_Ready(g_UsbACM[usb_port].rxpipe->byEP, USB_ENDPT_BULK);
	}

#ifdef  __USB_HIGH_SPEED_COM_PORT_ENABLE__

	/* Check the next packet's data length */
	nCount = USB_EP_Rx_Pkt_Len(g_UsbACM[usb_port].rxpipe->byEP);

	if(nCount == 0)
	{
		/* 0 may be due to no packet or NULL packet */
		/* re-start escape GPT timer */
		if(USB2UARTPort[usb_port].ESCDet.GuardTime != 0)
		{
			USB_GPTI_StartItem(USB2UARTPort[usb_port].handle, (USB2UARTPort[usb_port].ESCDet.GuardTime/10), USB2UART_Timeout, &USB2UARTPort[usb_port]);
//			start.u2Tick = (USB2UARTPort[usb_port].ESCDet.GuardTime/10);
//			start.pfCallback = USB2UART_Timeout;
//			start.vPara = &USB2UARTPort[usb_port];
//			DclSGPT_Control((DCL_HANDLE)(USB2UARTPort[usb_port].handle), SGPT_CMD_START, (DCL_CTRL_DATA_T*)&start);

			esc_timer_is_running = KAL_TRUE;
		}
	}
#else
	/* re-start escape GPT timer */
	if(USB2UARTPort[usb_port].ESCDet.GuardTime != 0)
	{
		USB_GPTI_StartItem(USB2UARTPort[usb_port].handle, (USB2UARTPort[usb_port].ESCDet.GuardTime/10), USB2UART_Timeout, &USB2UARTPort[usb_port]);
//		start.u2Tick = (USB2UARTPort[usb_port].ESCDet.GuardTime/10);
//		start.pfCallback = USB2UART_Timeout;
//		start.vPara = &USB2UARTPort[usb_port];
//		DclSGPT_Control((DCL_HANDLE)(USB2UARTPort[usb_port].handle), SGPT_CMD_START, (DCL_CTRL_DATA_T*)&start);
	}
#endif
}


/* EP Bulk In reset handler */
static void USB_Acm_BulkIn_Reset(UART_PORT port)
{
	kal_uint32 usb_port = USB_PORT[port];


//#ifdef __USB_DOWNLOAD__
	if((USB_IS_LOGGING_PORT[port] == KAL_TRUE)
		||((g_UsbACM_Comm.acm_owner == USB_ACM_OWNER_FT)&&(USBDL_Mode_Type()== USBDL_MODE_NONE)))//(USBDL_Is_USB_Download_Mode() == KAL_FALSE)&&(USBDL_Is_USB_Fast_Meta_Mode()== KAL_FALSE)))
	{
		return;
	}
//#else
//	if((USB_Get_Device_Type() == USB_CDC_ACM_LOGGING)||(g_UsbACM_Comm.acm_owner == USB_ACM_OWNER_FT))
//	{
//		return;
//	}
//#endif

	g_UsbACM[usb_port].txpipe = &g_UsbACM[usb_port].data_ep_in_info->ep_status.epin_status;

	USB2UART_Clear_Tx_Buffer(port); /* set g_UsbACM.send_Txilm = KAL_TRUE here*/
	USB2UART_Clear_Tx_ISR_Buffer(port);
}


/* EP Bulk Out reset handler */
static void USB_Acm_BulkOut_Reset(UART_PORT port)
{
	kal_uint32 usb_port = USB_PORT[port];


//#ifdef __USB_DOWNLOAD__
	if((USB_IS_LOGGING_PORT[port] == KAL_TRUE)
		||((g_UsbACM_Comm.acm_owner == USB_ACM_OWNER_FT)&&(USBDL_Mode_Type()== USBDL_MODE_NONE)))//(USBDL_Is_USB_Download_Mode() == KAL_FALSE)&&(USBDL_Is_USB_Fast_Meta_Mode()== KAL_FALSE)))
	{
		return;
	}
//#else
//	if((USB_Get_Device_Type() == USB_CDC_ACM_LOGGING)||(g_UsbACM_Comm.acm_owner == USB_ACM_OWNER_FT))
//	{
//		return;
//	}
//#endif

	g_UsbACM[usb_port].rxpipe = &g_UsbACM[usb_port].data_ep_out_info->ep_status.epout_status;
	g_UsbACM[usb_port].send_Rxilm = KAL_TRUE;

	usb_drv_trace1(USB2UARTPort[usb_port].ownerid, (kal_uint32)USBACM_RESET_READY_TO_READ_FLAG, usb_port);

	USB2UART_Clear_Rx_Buffer(port);
}


/* When PC return ACK, handle ACM intr pipe state machine */
static void USB_Acm_IntrIn_Hdlr(UART_PORT port)
{
	kal_uint32 usb_port = USB_PORT[port];
	kal_uint32 len;
	kal_uint32 max_intr_pkt_size;


	USB_Dbg_Trace(USB_ACM_INTERRUPT_HANDLER, (kal_uint32)g_UsbACM[usb_port].intr_state, port);

	if(USB_Get_Device_State() != DEVSTATE_CONFIG)
	{
		/* USB reset */
		USB_Dbg_Trace(USB_ACM_INTERRUPT_RESET, 0, 0);
		g_UsbACM[usb_port].intr_state = ACM_INTR_IDLE;
		return;
	}
/*
#ifdef __USB_HS_ENABLE__
	if(USB_Is_High_Speed() == KAL_TRUE)
		max_intr_pkt_size = USB_EP_INTR_MAXP_HS;
	else
		max_intr_pkt_size = USB_EP_INTR_MAXP_FS;
#else
		max_intr_pkt_size = USB_EP_INTR_MAXP;
#endif
*/
	max_intr_pkt_size = USB_Intr_Max_Packet_Size();

	usb_drv_trace2(USB2UARTPort[usb_port].ownerid, (kal_uint32)USBACM_INTR, g_UsbACM[usb_port].intr_pkt.Data, usb_port);

	switch(g_UsbACM[usb_port].intr_state)
	{
	case ACM_INTR_SEND_ONE_PKT:
		g_UsbACM[usb_port].intr_state = ACM_INTR_SEND_LAST_PKT;

		len = ((kal_uint32)sizeof(UsbAcm_Intr_Pkt)) - max_intr_pkt_size;

		/* send last short packet */
		USB_Dbg_Trace(USB_ACM_SEND_INTERRUPT2, (kal_uint32)g_UsbACM[usb_port].intr_state, 0);
		usb_drv_trace2(USB2UARTPort[usb_port].ownerid, (kal_uint32)USBACM_INTR, g_UsbACM[usb_port].intr_pkt.Data, usb_port);

		USB_EPFIFOWrite(g_UsbACM[usb_port].intrpipe->byEP, len, (kal_uint8 *)(kal_uint32)&g_UsbACM[usb_port].intr_pkt + max_intr_pkt_size);
		USB_EP_Tx_Ready(g_UsbACM[usb_port].intrpipe->byEP, USB_ENDPT_INTR);
		break;

	case ACM_INTR_SEND_LAST_PKT:
		g_UsbACM[usb_port].intr_state = ACM_INTR_IDLE;

		/* Send another intr pkt */
		if(g_UsbACM[usb_port].is_intr_pending_pkt == KAL_TRUE)
		{
			g_UsbACM[usb_port].is_intr_pending_pkt = KAL_FALSE;

           #if 0 //mark 
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
		break;

	case ACM_INTR_IDLE:
	default:
		EXT_ASSERT(0, (kal_uint32)g_UsbACM[usb_port].intr_state, 0, 0);
		break;
	}
}


static void USB_Acm_IntrIn_Reset(UART_PORT port)
{
	kal_uint32 usb_port = USB_PORT[port];

	g_UsbACM[usb_port].intr_state = ACM_INTR_IDLE;
}


void USB_Acm1_CommIf_Create(void *ifname)
{
	USB_Acm_CommIf_Create(uart_port_usb, ifname);
}

void USB_Acm1_CommIf_Reset(void)
{
	USB_Acm_CommIf_Reset(uart_port_usb);
}

void USB_Acm1_CommIf_Enable(void)
{
	USB_Acm_CommIf_Enable(uart_port_usb);
}

void USB_Acm1_CommIf_Speed_Reset(kal_bool b_other_speed)
{
	USB_Acm_CommIf_Speed_Reset(uart_port_usb, b_other_speed);
}

void USB_Acm1_DataIf_Create(void *ifname)
{
	USB_Acm_DataIf_Create(uart_port_usb, ifname);
}

void USB_Acm1_DataIf_Reset(void)
{
	USB_Acm_DataIf_Reset(uart_port_usb);
}

void USB_Acm1_DataIf_Speed_Reset(kal_bool b_other_speed)
{
	USB_Acm_DataIf_Speed_Reset(uart_port_usb, b_other_speed);
}

void USB_Acm1_DataIf_Enable(void)
{
	USB_Acm_DataIf_Enable(uart_port_usb);
}



static void USB_Acm1_Ep0_SetLineCoding(void *data)
{
	USB_Acm_Ep0_SetLineCoding(uart_port_usb, data);
}

static void USB_Acm1_Ep0_Command(Usb_Ep0_Status* pep0state, Usb_Command* pcmd)
{
	USB_Acm_Ep0_Command(uart_port_usb, pep0state, pcmd);
}

static void USB_Acm1_BulkOut_Hdr(void)
{
	USB_Acm_BulkOut_Hdr(uart_port_usb);
}



static void USB_Acm1_BulkIn_Reset(void)
{
	USB_Acm_BulkIn_Reset(uart_port_usb);
}

static void USB_Acm1_BulkOut_Reset(void)
{
	USB_Acm_BulkOut_Reset(uart_port_usb);
}

static void USB_Acm1_IntrIn_Hdlr(void)
{
	USB_Acm_IntrIn_Hdlr(uart_port_usb);
}

static void USB_Acm1_IntrIn_Reset(void)
{
	USB_Acm_IntrIn_Reset(uart_port_usb);
}

#if defined(__USB_MULTIPLE_COMPORT_SUPPORT__)

void USB2UART_Tx_DMA2_Callback(void)
{
	USB2UART_Tx_DMA_Callback(uart_port_usb2);
}

#if defined (__USB_MODEM_CARD_SUPPORT__)
void USB2UART_Tx_DMA3_Callback(void)
{
	USB2UART_Tx_DMA_Callback(uart_port_usb3);
}
void USB2UART_Tx_DMA4_Callback(void)
{
	USB2UART_Tx_DMA_Callback(uart_port_usb4);
}
void USB2UART_Tx_DMA5_Callback(void)
{
	USB2UART_Tx_DMA_Callback(uart_port_usb5);
}
#endif

#ifndef   __USB_COMPORT_SUPPORT_TC01_DRIVER__

void USB_Acm2_CommIf_Create(void *ifname)
{
	USB_Acm_CommIf_Create(uart_port_usb2, ifname);
}


void USB_Acm2_CommIf_Reset(void)
{
	USB_Acm_CommIf_Reset(uart_port_usb2);
}


void USB_Acm2_CommIf_Enable(void)
{
	USB_Acm_CommIf_Enable(uart_port_usb2);
}


void USB_Acm2_CommIf_Speed_Reset(kal_bool b_other_speed)
{
	USB_Acm_CommIf_Speed_Reset(uart_port_usb2, b_other_speed);
}


void USB_Acm2_DataIf_Create(void *ifname)
{
	USB_Acm_DataIf_Create(uart_port_usb2, ifname);
}


void USB_Acm2_DataIf_Reset(void)
{
	USB_Acm_DataIf_Reset(uart_port_usb2);
}


void USB_Acm2_DataIf_Enable(void)
{
	USB_Acm_DataIf_Enable(uart_port_usb2);
}


void USB_Acm2_DataIf_Speed_Reset(kal_bool b_other_speed)
{
	USB_Acm_DataIf_Speed_Reset(uart_port_usb2, b_other_speed);
}

#if defined (__USB_MODEM_CARD_SUPPORT__)

void USB_Acm_DataCommIf_Create(void *ifname)
{
	kal_uint32 usb_port = USB_PORT[uart_port_usb];
//	kal_uint8 ep_tx_id;
//	kal_uint8 ep_rx_id;
	
	//create comm interface and EP info
	USB_Acm_CommIf_Create(uart_port_usb, ifname);
	
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
#else
	//create data interface and EP info
	gUsbDevice.resource_interface_number--; //release data interface
	USB_Acm_DataIf_Create(uart_port_usb, ifname);
	
	//copy data interface EP to comm interface
	g_UsbACM[usb_port].comm_if_info->ep_info[1] = g_UsbACM[usb_port].data_ep_in_info;
	g_UsbACM[usb_port].comm_if_info->ep_info[2] = g_UsbACM[usb_port].data_ep_out_info;
	((Usb_Cdc_If_Dscr*)g_UsbACM[usb_port].comm_if_info->ifdscr.classif)->bNumEndpoints += g_UsbACM[usb_port].data_if_info->ifdscr.stdif.bNumEndpoints;
#endif
}

void USB_Acm_DataCommIf_Reset(void)
{
	USB_Acm_CommIf_Reset(uart_port_usb);
	USB_Acm_DataIf_Reset(uart_port_usb);
}

void USB_Acm_DataCommIf_Enable(void)
{
	USB_Acm_CommIf_Enable(uart_port_usb);
	USB_Acm_DataIf_Enable(uart_port_usb);
}

void USB_Acm_DataCommIf_Speed_Reset(kal_bool b_other_speed)
{
	USB_Acm_CommIf_Speed_Reset(uart_port_usb, b_other_speed);
	USB_Acm_DataIf_Speed_Reset(uart_port_usb, b_other_speed);
}

void USB_Acm2_DataCommIf_Create(void *ifname)
{
	kal_uint32 usb_port = USB_PORT[uart_port_usb2];

	//create comm interface and EP info
	USB_Acm_CommIf_Create(uart_port_usb2, ifname);
	
	//create data interface and EP info
	gUsbDevice.resource_interface_number--; //release data interface
	USB_Acm_DataIf_Create(uart_port_usb2, ifname);
	
	//copy data interface EP to comm interface
	g_UsbACM[usb_port].comm_if_info->ep_info[1] = g_UsbACM[usb_port].data_ep_in_info;
	g_UsbACM[usb_port].comm_if_info->ep_info[2] = g_UsbACM[usb_port].data_ep_out_info;
	((Usb_Cdc_If_Dscr*)g_UsbACM[usb_port].comm_if_info->ifdscr.classif)->bNumEndpoints += g_UsbACM[usb_port].data_if_info->ifdscr.stdif.bNumEndpoints;
}
void USB_Acm2_DataCommIf_Reset(void)
{
	USB_Acm_CommIf_Reset(uart_port_usb2);
	USB_Acm_DataIf_Reset(uart_port_usb2);
}
void USB_Acm2_DataCommIf_Enable(void)
{
	USB_Acm_CommIf_Enable(uart_port_usb2);
	USB_Acm_DataIf_Enable(uart_port_usb2);
}
void USB_Acm2_DataCommIf_Speed_Reset(kal_bool b_other_speed)
{
	USB_Acm_CommIf_Speed_Reset(uart_port_usb2, b_other_speed);
	USB_Acm_DataIf_Speed_Reset(uart_port_usb2, b_other_speed);
}


void USB_Acm3_DataIf_Create(void *ifname)
{
	USB_Acm_DataIf_Create(uart_port_usb3, ifname);
}


void USB_Acm3_DataIf_Reset(void)
{
	USB_Acm_DataIf_Reset(uart_port_usb3);
}


void USB_Acm3_DataIf_Enable(void)
{
	USB_Acm_DataIf_Enable(uart_port_usb3);
}


void USB_Acm3_DataIf_Speed_Reset(kal_bool b_other_speed)
{
	USB_Acm_DataIf_Speed_Reset(uart_port_usb3, b_other_speed);
}
void USB_Acm4_DataIf_Create(void *ifname)
{
	USB_Acm_DataIf_Create(uart_port_usb4, ifname);
}
void USB_Acm4_DataIf_Reset(void)
{
	USB_Acm_DataIf_Reset(uart_port_usb4);
}
void USB_Acm4_DataIf_Enable(void)
{
	USB_Acm_DataIf_Enable(uart_port_usb4);
}
void USB_Acm4_DataIf_Speed_Reset(kal_bool b_other_speed)
{
	USB_Acm_DataIf_Speed_Reset(uart_port_usb4, b_other_speed);
}


void USB_Acm5_DataIf_Create(void *ifname)
{
	USB_Acm_DataIf_Create(uart_port_usb5, ifname);
}
void USB_Acm5_DataIf_Reset(void)
{
	USB_Acm_DataIf_Reset(uart_port_usb5);
}
void USB_Acm5_DataIf_Enable(void)
{
	USB_Acm_DataIf_Enable(uart_port_usb5);
}
void USB_Acm5_DataIf_Speed_Reset(kal_bool b_other_speed)
{
	USB_Acm_DataIf_Speed_Reset(uart_port_usb5, b_other_speed);
}
#endif

#endif /*  __USB_COMPORT_SUPPORT_TC01_DRIVER__ */

static void USB_Acm2_Ep0_SetLineCoding(void *data)
{
	USB_Acm_Ep0_SetLineCoding(uart_port_usb2, data);
}


static void USB_Acm2_Ep0_Command(Usb_Ep0_Status* pep0state, Usb_Command* pcmd)
{
	USB_Acm_Ep0_Command(uart_port_usb2, pep0state, pcmd);
}


static void USB_Acm2_BulkOut_Hdr(void)
{
	USB_Acm_BulkOut_Hdr(uart_port_usb2);
}


static void USB_Acm2_BulkIn_Reset(void)
{
	USB_Acm_BulkIn_Reset(uart_port_usb2);
}


static void USB_Acm2_BulkOut_Reset(void)
{
	USB_Acm_BulkOut_Reset(uart_port_usb2);
}


static void USB_Acm2_IntrIn_Hdlr(void)
{
	USB_Acm_IntrIn_Hdlr(uart_port_usb2);
}


static void USB_Acm2_IntrIn_Reset(void)
{
	USB_Acm_IntrIn_Reset(uart_port_usb2);
}

#if defined (__USB_MODEM_CARD_SUPPORT__)
static void USB_Acm3_Ep0_SetLineCoding(void *data)
{
	USB_Acm_Ep0_SetLineCoding(uart_port_usb3, data);
}
static void USB_Acm3_Ep0_Command(Usb_Ep0_Status* pep0state, Usb_Command* pcmd)
{
	USB_Acm_Ep0_Command(uart_port_usb3, pep0state, pcmd);
}
static void USB_Acm3_BulkOut_Hdr(void)
{
	USB_Acm_BulkOut_Hdr(uart_port_usb3);
}
static void USB_Acm3_BulkIn_Reset(void)
{
	USB_Acm_BulkIn_Reset(uart_port_usb3);
}
static void USB_Acm3_BulkOut_Reset(void)
{
	USB_Acm_BulkOut_Reset(uart_port_usb3);
}
static void USB_Acm3_IntrIn_Hdlr(void)
{
	USB_Acm_IntrIn_Hdlr(uart_port_usb3);
}
static void USB_Acm3_IntrIn_Reset(void)
{
	USB_Acm_IntrIn_Reset(uart_port_usb3);
}

////////////////
static void USB_Acm4_Ep0_SetLineCoding(void *data)
{
	USB_Acm_Ep0_SetLineCoding(uart_port_usb4, data);
}
static void USB_Acm4_Ep0_Command(Usb_Ep0_Status* pep0state, Usb_Command* pcmd)
{
	USB_Acm_Ep0_Command(uart_port_usb4, pep0state, pcmd);
}
static void USB_Acm4_BulkOut_Hdr(void)
{
	USB_Acm_BulkOut_Hdr(uart_port_usb4);
}
static void USB_Acm4_BulkIn_Reset(void)
{
	USB_Acm_BulkIn_Reset(uart_port_usb4);
}
static void USB_Acm4_BulkOut_Reset(void)
{
	USB_Acm_BulkOut_Reset(uart_port_usb4);
}
static void USB_Acm4_IntrIn_Hdlr(void)
{
	USB_Acm_IntrIn_Hdlr(uart_port_usb4);
}
static void USB_Acm4_IntrIn_Reset(void)
{
	USB_Acm_IntrIn_Reset(uart_port_usb4);
}
///////////////////
static void USB_Acm5_Ep0_SetLineCoding(void *data)
{
	USB_Acm_Ep0_SetLineCoding(uart_port_usb5, data);
}
static void USB_Acm5_Ep0_Command(Usb_Ep0_Status* pep0state, Usb_Command* pcmd)
{
	USB_Acm_Ep0_Command(uart_port_usb5, pep0state, pcmd);
}
static void USB_Acm5_BulkOut_Hdr(void)
{
	USB_Acm_BulkOut_Hdr(uart_port_usb5);
}
static void USB_Acm5_BulkIn_Reset(void)
{
	USB_Acm_BulkIn_Reset(uart_port_usb5);
}
static void USB_Acm5_BulkOut_Reset(void)
{
	USB_Acm_BulkOut_Reset(uart_port_usb5);
}
static void USB_Acm5_IntrIn_Hdlr(void)
{
	USB_Acm_IntrIn_Hdlr(uart_port_usb5);
}
static void USB_Acm5_IntrIn_Reset(void)
{
	USB_Acm_IntrIn_Reset(uart_port_usb5);
}
#endif

#endif


#ifdef __USB_TETHERING__

static void USB_ISD_Ep0_SendEncapsulated(void *data)
{
	kal_uint32 usb_port = USB_PORT[uart_port_usb];
	kal_uint32 nCount;

	// Debug	
	kal_uint8  temp[4];
	kal_uint32	tempp[3];
	kal_uint8 index;

	/* Read setting and send to RNDIS */
	nCount = USB_EP0_Pkt_Len();


	// check buffer addresss	
		tempp[0] = (kal_uint32)g_UsbACM[usb_port].rx_flc_buf_data_len[g_UsbACM[usb_port].rx_flc_buf_w_index];
		tempp[1] = (kal_uint32)g_UsbACM[usb_port].rx_flc_buf_addr[g_UsbACM[usb_port].rx_flc_buf_w_index];
	//	tempp[3] = 0;


	if((g_UsbACM[usb_port].rx_flc_temp_length != 0)||(g_UsbACM[usb_port].rx_flc_temp == KAL_TRUE))
			ASSERT(0);  // continue recieve 2 Command from PC

	if (nCount != 0)
	{
		if (nCount < USB_EP0_MAXP) // 64 N + short packet
		{
			if ((g_UsbACM[usb_port].rx_flc_buf_data_len[g_UsbACM[usb_port].rx_flc_buf_w_index]%USB_EP0_MAXP)!=0)
				ASSERT(0);
		}
			
	//	USB_EPFIFORead(0, nCount, g_UsbACM[usb_port].rx_flc_buf_addr[g_UsbACM[usb_port].rx_flc_buf_w_index], KAL_FALSE);
	//  after enumeration, UPS has not time to push buffer & already received EP0 Command
	
//		if ((kal_uint8 *)((kal_uint32)g_UsbACM[usb_port].rx_flc_buf_addr[g_UsbACM[usb_port].rx_flc_buf_w_index]+g_UsbACM[usb_port].rx_flc_buf_data_len[g_UsbACM[usb_port].rx_flc_buf_w_index]) == NULL)	
		if ((g_UsbACM[usb_port].rx_flc_buf_addr[g_UsbACM[usb_port].rx_flc_buf_w_index] == NULL) && (g_UsbACM[usb_port].rx_flc_buf_data_len[g_UsbACM[usb_port].rx_flc_buf_w_index] == 0))
		{
				if(g_UsbACM[usb_port].rx_flc_buf_count == 0) // ups has not push buffer yet
				{	 // queue data in HW
					g_UsbACM[usb_port].rx_flc_temp_length = nCount;
					g_UsbACM[usb_port].rx_flc_temp = KAL_TRUE;

					USB_EPFIFORead(0, nCount, g_UsbACM[usb_port].rx_flc_temp_buf_addr, KAL_FALSE);

					for (index=0; index<2; index++)
					{					
						temp[0] = *(g_UsbACM[usb_port].rx_flc_temp_buf_addr+(index*4+0)) ;//g_UsbACM[usb_port].rx_flc_temp_buffr[index*4+0];
						temp[1] = *(g_UsbACM[usb_port].rx_flc_temp_buf_addr+(index*4+1)) ;//g_UsbACM[usb_port].rx_flc_temp_buffr[index*4+1];
						temp[2] = *(g_UsbACM[usb_port].rx_flc_temp_buf_addr+(index*4+2)) ;//g_UsbACM[usb_port].rx_flc_temp_buffr[index*4+2];
						temp[3] = *(g_UsbACM[usb_port].rx_flc_temp_buf_addr+(index*4+3)) ;//g_UsbACM[usb_port].rx_flc_temp_buffr[index*4+3];
						
						usb_drv_trace4(USB2UARTPort[usb_port].ownerid, (kal_uint32)USBACM_RX_FLC_DATA_HEADER,temp[0],temp[1],temp[2],temp[3]);
					}

				}
				else
				{
					usb_drv_trace2(USB2UARTPort[usb_port].ownerid, (kal_uint32)USBACM_Drop,0,0);
					USB_EPFIFORead(0, nCount, g_UsbACM[usb_port].rx_flc_temp_buf_addr, KAL_FALSE);	
					nCount = 0;			
				}
		}
		else
		{
			USB_EPFIFORead(0, nCount, (kal_uint8 *)((kal_uint32)g_UsbACM[usb_port].rx_flc_buf_addr[g_UsbACM[usb_port].rx_flc_buf_w_index]+g_UsbACM[usb_port].rx_flc_buf_data_len[g_UsbACM[usb_port].rx_flc_buf_w_index]), KAL_FALSE);
			g_UsbACM[usb_port].rx_flc_buf_data_len[g_UsbACM[usb_port].rx_flc_buf_w_index] += nCount;	
		}
	}

	USB_Dbg_Trace(USB_ACM_RX_FLC_PKT_LENGTH, g_UsbACM[usb_port].rx_flc_buf_data_len[g_UsbACM[usb_port].rx_flc_buf_w_index], 1);
	USB_Dbg_Trace(USB_ACM_RX_FLC_PKT_LENGTH, (kal_uint32)g_UsbACM[usb_port].rx_flc_buf_addr[g_UsbACM[usb_port].rx_flc_buf_w_index], 2);
	USB_Dbg_Trace(USB_ACM_RX_FLC_PKT_LENGTH, (kal_uint32)g_UsbACM[usb_port].rx_flc_buf_addr[g_UsbACM[usb_port].rx_flc_buf_w_index]+ (kal_uint32)g_UsbACM[usb_port].rx_flc_buf_data_len[g_UsbACM[usb_port].rx_flc_buf_w_index], 3);


//	 Debug	==========================================
	tempp[2] = ((kal_uint32)g_UsbACM[usb_port].rx_flc_buf_addr[g_UsbACM[usb_port].rx_flc_buf_w_index]+g_UsbACM[usb_port].rx_flc_buf_data_len[g_UsbACM[usb_port].rx_flc_buf_w_index]);												
	usb_drv_trace4(USB2UARTPort[usb_port].ownerid, (kal_uint32)USBACM_RX_FLC_HIGHSPEED_BULK_OUT,tempp[0],tempp[1],tempp[2],0);



// check frame header
	temp[0] = *(g_UsbACM[usb_port].rx_flc_buf_addr[g_UsbACM[usb_port].rx_flc_buf_w_index]);
	temp[1] = *(g_UsbACM[usb_port].rx_flc_buf_addr[g_UsbACM[usb_port].rx_flc_buf_w_index]+ 0x01);
	temp[2] = *(g_UsbACM[usb_port].rx_flc_buf_addr[g_UsbACM[usb_port].rx_flc_buf_w_index]+ 0x02);
	temp[3] = *(g_UsbACM[usb_port].rx_flc_buf_addr[g_UsbACM[usb_port].rx_flc_buf_w_index]+ 0x03);
													
	usb_drv_trace4(USB2UARTPort[usb_port].ownerid, (kal_uint32)USBACM_RX_FLC_DATA_HEADER,temp[0],temp[1],temp[2],temp[3]);

//=================================

	

	if (nCount == USB_EP0_MAXP)
	{
		USB_Set_Endpoint0_State(USB_EP0_RX);
		USB_Update_EP0_State(USB_EP0_DRV_STATE_READ_END, KAL_FALSE, KAL_FALSE);
	}
	else
	{
		USB_Set_Endpoint0_State(USB_EP0_RX_STATUS);
		USB_Update_EP0_State(USB_EP0_DRV_STATE_READ_END, KAL_FALSE, KAL_TRUE);

		if (g_UsbACM[usb_port].rx_flc_temp == KAL_FALSE) // if data queue in HW, don't notice UPS & update pointer 
		{	
			if (nCount != 0)  // ther is no NULL packet at the end of the control transfer
			{
				g_UsbACM[usb_port].rx_flc_buf_w_index++;

				if(g_UsbACM[usb_port].rx_flc_buf_w_index == (RNDIS_RX_FLC_BUFFER_NUM+1))
					g_UsbACM[usb_port].rx_flc_buf_w_index = 0;

				if(g_UsbACM[usb_port].rx_flc_buf_count > RNDIS_RX_FLC_BUFFER_NUM)
					ASSERT(0);

				if(g_UsbACM[usb_port].send_ctrl_Rxilm == KAL_TRUE)
				{   
					g_UsbACM[usb_port].send_ctrl_Rxilm = KAL_FALSE;		
					USB2UART_Sendilm(uart_port_usb, MSG_ID_CTRL_UART_READY_TO_READ_IND);
				}
			}
		}

	}
}
	


/* Parse class specific request */
static void USB_ISD_Ep0_Command(Usb_Ep0_Status* pep0state, Usb_Command* pcmd)
{
	kal_uint32 usb_port = USB_PORT[uart_port_usb];
	kal_bool  bError = KAL_FALSE;
//	SGPT_CTRL_START_T start;


	if (g_UsbACM[usb_port].halt_flag == KAL_TRUE)
		g_UsbACM[usb_port].halt_flag = KAL_FALSE;


	usb_drv_trace2(USB2UARTPort[usb_port].ownerid, (kal_uint32)USBACM_EP0_COMMAND,(kal_uint32)pcmd->bRequest, usb_port);

	switch (pcmd->bRequest)
	{
	case USB_ACM_SEND_ENCAPSULATED_COMMAND:
		/* register handler to handle the get data*/
			USB_Register_EP0_RxHdlr(USB_ISD_Ep0_SendEncapsulated);
			USB_Set_Endpoint0_State(USB_EP0_RX);		
		break;
	case USB_ACM_GET_ENCAPSULATED_RESPONSE:

		/* tell host the current setting */
		USB_Generate_EP0Data(pep0state, pcmd, g_UsbACM[usb_port].tx_flc_data_addr, g_UsbACM[usb_port].tx_flc_count);
		g_UsbACM[usb_port].ctrl_data_done = KAL_TRUE;
		
		if(g_UsbACM[usb_port].send_ctrl_Txilm == KAL_TRUE)
		{
			USB2UART_Sendilm(uart_port_usb, MSG_ID_CTRL_UART_READY_TO_WRITE_IND);
			g_UsbACM[usb_port].send_ctrl_Txilm = KAL_FALSE;
		}		
		break;
	case USB_ACM_SET_LINE_CODING:
	case USB_ACM_GET_LINE_CODING:
	case USB_ACM_SET_CONTROL_LINE_STATE:		
	case USB_ACM_SEND_BREAK:
	case USB_ACM_SET_COMM_FEATURE:
	case USB_ACM_GET_COMM_FEATURE:
	case USB_ACM_CLEAR_COMM_FEATURE:
	default:
		bError = KAL_TRUE;
		break;
	}

	/* Stall command if an error occured */
	USB_EP0_Command_Hdlr(bError);
/*	
	if(USB_Get_Endpoint0_State() == USB_EP0_IDLE)
	{
		USB_Set_Endpoint0_State(USB_EP0_RX_STATUS);

		USB_Update_EP0_State(USB_EP0_DRV_STATE_READ_END, bError, KAL_TRUE);
	}
	else
	{
		USB_Update_EP0_State(USB_EP0_DRV_STATE_READ_END, bError, KAL_FALSE);
	}
*/	
}

static void USB_ISD_IntrIn_Hdlr(void)
{
	USB_Acm_IntrIn_Hdlr(uart_port_usb);
}

static void USB_ISD_IntrIn_Reset(void)
{
	USB_Acm_IntrIn_Reset(uart_port_usb);
}


void USB_ISD_CommIf_Create(void *ifname)
{	
	kal_uint32 usb_port = USB_PORT[uart_port_usb];
//	kal_uint8 ep_id;
//	kal_uint8 if_id;

	USB_Acm_CommIf_Create(uart_port_usb,ifname);

	g_UsbACM[usb_port].comm_if_info->if_class_specific_hdlr = USB_ISD_Ep0_Command;

	((Usb_Cdc_If_Dscr*)g_UsbACM[usb_port].comm_if_info->ifdscr.classif)->bInterfaceClass = USB_ISD_COMM_INTERFACE_CLASS_CODE;
	((Usb_Cdc_If_Dscr*)g_UsbACM[usb_port].comm_if_info->ifdscr.classif)->bInterfaceSubClass = USB_ISD_COMM_INTERFACE_SUBCLASS_CODE;
	((Usb_Cdc_If_Dscr*)g_UsbACM[usb_port].comm_if_info->ifdscr.classif)->bInterfaceProtocol = USB_ISD_COMM_INTERFACE_PROTOCOL_CODE;


#ifndef  __USB_COMPOSITE_REMOVE_IAD__
#if defined(__USB_COMPOSITE_DEVICE_SUPPORT__)
	if(USB_Get_Device_Type() == USB_COMPOSITE_RNDIS_COM)
	{
		g_UsbACM[usb_port].iad_desc->bFunctionClass = USB_ISD_COMM_INTERFACE_CLASS_CODE;
		g_UsbACM[usb_port].iad_desc->bFunctionSubClass = USB_ISD_COMM_INTERFACE_SUBCLASS_CODE;
		g_UsbACM[usb_port].iad_desc->bFunctionProtocol = USB_ISD_COMM_INTERFACE_PROTOCOL_CODE;

	}
#endif
#endif


	/* Endpoint handler */
	USB_Register_Drv_Info(USB_DRV_HDLR_EP_TX, g_UsbACM[usb_port].comm_ep_intr_info->ep_status.epin_status.byEP, USB_ISD_IntrIn_Hdlr);
	g_UsbACM[usb_port].comm_ep_intr_info->ep_reset = USB_ISD_IntrIn_Reset;

	g_UsbACM[usb_port].intr_pkt.bmRequestType = USB_CMD_STDIFOUT;
	g_UsbACM[usb_port].intr_pkt.bRequest = USB_ACM_NOTIF_NETWORK_CONNECTION;
	g_UsbACM[usb_port].intr_pkt.wValue = 0;
	g_UsbACM[usb_port].intr_pkt.wIndex = 0;//if_id;
	g_UsbACM[usb_port].intr_pkt.wLength = 0;
	g_UsbACM[usb_port].intr_pkt.Data = 0;	

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
#ifndef  __USB_COMPOSITE_REMOVE_IAD__
#if defined(__USB_COMPOSITE_DEVICE_SUPPORT__)
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
/* under construction !*/
#ifndef __USB_HS_ENABLE__
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
#endif



	
}

void USB_ISD_CommIf_Reset(void)
{
	USB_Acm_CommIf_Reset(uart_port_usb);
}

void USB_ISD_CommIf_Enable(void)
{
	USB_Acm_CommIf_Enable(uart_port_usb);
}

void USB_ISD_CommIf_Speed_Reset(kal_bool b_other_speed)
{
	USB_Acm_CommIf_Speed_Reset(uart_port_usb, b_other_speed);
}




/* 14MB/s version, handle multiple packets inside one ISR */

/* EP Bulk Out interrupt handler, called by EP interrupt */
static void USB_ISD_BulkOut_Hdr(void)
{
	kal_uint32 usb_port = USB_PORT[uart_port_usb];
	kal_uint32 nCount;
	kal_uint32 loop_count = 0;
	kal_uint32 max_bulk_pkt_size;
	
// Debug	
	kal_uint8  temp[4];
	kal_uint32  tempp[3];
	

	//Assert dump: only TST can use USB in exception mode.
	if((USB_Exception_Check() == KAL_FALSE)&&(USB2UARTPort[usb_port].ownerid != MOD_TST_READER))
	//	if((INT_Exception_Enter != 0 || (is_init_log_enable == KAL_TRUE && is_init_stage == KAL_TRUE))&&(USB2UARTPort[usb_port].ownerid != MOD_TST_READER))	
		return;

	USB_Dbg_Trace(USB_ACM_RX_PKT, 0, USB2UARTPort[usb_port].ownerid);

	/* Check current packet's data length */
	nCount = USB_EP_Rx_Pkt_Len(g_UsbACM[usb_port].rxpipe->byEP);

	/* This log cannot be executed when assertion because the system stack will overflow */

	USB_Dbg_Trace(USB_ACM_RX_PKT_LENGTH, nCount, 0);


	/* Stop escape GPT timer */
//	if((esc_timer_is_running == KAL_TRUE)&&(USB2UARTPort[usb_port].ESCDet.GuardTime != 0))
//	{
		//GPTI_StopItem(USB2UARTPort[usb_port].handle);
//		DclSGPT_Control((DCL_HANDLE)(USB2UARTPort[usb_port].handle), SGPT_CMD_STOP, 0);
//#ifdef  __USB_HIGH_SPEED_COM_PORT_ENABLE__
//		esc_timer_is_running = KAL_FALSE;
//#endif
//	}


	/* No UART owner, drop the data directly */
	if((USB2UARTPort[usb_port].ownerid != MOD_DRV_HISR)&&(nCount != 0))
	{
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
		max_bulk_pkt_size = USB_Bulk_Max_Packet_Size();

		if(g_UsbACM[usb_port].b_is_high_speed_enable == KAL_TRUE)
		{
			/* 0 must due to NULL packet */
//			while(nCount != 0)//&&(loop_count != USB_ACM_RX_HDLR_PACKET_NUM))
			while((nCount != 0)&&(loop_count != USB_RNDIS_RX_LOOP_COUNT))
//			if(nCount != 0)
			{
			
				usb_drv_trace2(USB2UARTPort[usb_port].ownerid, (kal_uint32)USBACM_PC_SENT, nCount, usb_port);  // temp remove

						
				tempp[1] = (kal_uint32)g_UsbACM[usb_port].rx_buf_addr[g_UsbACM[usb_port].rx_buf_w_index];
				tempp[0] = (kal_uint32)g_UsbACM[usb_port].isd_rx_buf_data_len[g_UsbACM[usb_port].rx_buf_w_index];


				if(g_UsbACM[usb_port].rx_buf_count > (RNDIS_RX_BUFFER_NUM))
						ASSERT(0);
								
				loop_count++;

				if ((g_UsbACM[usb_port].isd_rx_buf_data_len[g_UsbACM[usb_port].rx_buf_w_index] % max_bulk_pkt_size)!=0)
					ASSERT(0);   // w_index doesn't update


//				if (g_UsbACM[usb_port].isd_rx_buf_data_len[g_UsbACM[usb_port].rx_buf_w_index] == 0) // loop , when receive 512 , jump out loop --> doesn't change addr
//					temp_addr = (kal_uint32)g_UsbACM[usb_port].rx_buf_addr[g_UsbACM[usb_port].rx_buf_w_index];
//				else
//				{
//					if (temp_addr != (kal_uint32)g_UsbACM[usb_port].rx_buf_addr[g_UsbACM[usb_port].rx_buf_w_index])
//						ASSERT(0);
//				}
				
				if ((kal_uint8 *)((kal_uint32)g_UsbACM[usb_port].rx_buf_addr[g_UsbACM[usb_port].rx_buf_w_index]+ g_UsbACM[usb_port].isd_rx_buf_data_len[g_UsbACM[usb_port].rx_buf_w_index]) == NULL)
				{
					usb_drv_trace2(USB2UARTPort[usb_port].ownerid, (kal_uint32)USBACM_Drop,g_UsbACM[usb_port].rxpipe->byEP,g_UsbACM[usb_port].rx_buf_w_index);
					return;
				}
					
				USB_EPFIFORead(g_UsbACM[usb_port].rxpipe->byEP, nCount, (kal_uint8 *)((kal_uint32)g_UsbACM[usb_port].rx_buf_addr[g_UsbACM[usb_port].rx_buf_w_index]+ g_UsbACM[usb_port].isd_rx_buf_data_len[g_UsbACM[usb_port].rx_buf_w_index]), KAL_FALSE);

				tempp[2] = ((kal_uint32)g_UsbACM[usb_port].rx_buf_addr[g_UsbACM[usb_port].rx_buf_w_index]+ g_UsbACM[usb_port].isd_rx_buf_data_len[g_UsbACM[usb_port].rx_buf_w_index]);


				USB_Dbg_Trace(USB_ACM_RX_PKT_LENGTH, g_UsbACM[usb_port].isd_rx_buf_data_len[g_UsbACM[usb_port].rx_buf_w_index], 1);
				USB_Dbg_Trace(USB_ACM_RX_PKT_LENGTH, (kal_uint32)g_UsbACM[usb_port].rx_buf_addr[g_UsbACM[usb_port].rx_buf_w_index], 2);
				USB_Dbg_Trace(USB_ACM_RX_PKT_LENGTH, (kal_uint32)g_UsbACM[usb_port].rx_buf_addr[g_UsbACM[usb_port].rx_buf_w_index]+ (kal_uint32)g_UsbACM[usb_port].isd_rx_buf_data_len[g_UsbACM[usb_port].rx_buf_w_index], 3);


//   Debug  ==========================================

// check buffer addresss
//		tempp[3] = 0;
																
				usb_drv_trace4(USB2UARTPort[usb_port].ownerid, (kal_uint32)USBACM_RX_HIGHSPEED_BULK_OUT,tempp[0],tempp[1],tempp[2],0);

// index
				usb_drv_trace4(USB2UARTPort[usb_port].ownerid, (kal_uint32)USBACM_MOVE_W_INDEX, g_UsbACM[usb_port].rx_buf_w_index, g_UsbACM[usb_port].rx_buf_count, g_UsbACM[usb_port].rx_buf_rc_index, g_UsbACM[usb_port].rx_buf_r_index);



// check frame header
				temp[0] = *(g_UsbACM[usb_port].rx_buf_addr[g_UsbACM[usb_port].rx_buf_w_index]);
				temp[1] = *(g_UsbACM[usb_port].rx_buf_addr[g_UsbACM[usb_port].rx_buf_w_index]+ 0x01);
				temp[2] = *(g_UsbACM[usb_port].rx_buf_addr[g_UsbACM[usb_port].rx_buf_w_index]+ 0x02);
				temp[3] = *(g_UsbACM[usb_port].rx_buf_addr[g_UsbACM[usb_port].rx_buf_w_index]+ 0x03);
																
				usb_drv_trace4(USB2UARTPort[usb_port].ownerid, (kal_uint32)USBACM_RX_DATA_HEADER,temp[0],temp[1],temp[2],temp[3]); //temp remove

// only print header file, for check PC send error data  or not 

//=================================

				if(nCount == max_bulk_pkt_size)  // still has data to receive
					USB_EP_Rx_Ready(g_UsbACM[usb_port].rxpipe->byEP, USB_ENDPT_BULK); /* Clear RxPktRdy */

				g_UsbACM[usb_port].isd_rx_buf_data_len[g_UsbACM[usb_port].rx_buf_w_index] += nCount;

				/* Update write pointer, decide to disable IRQ_USB or not */
				if(nCount != max_bulk_pkt_size)
				{
					USB2UARTPort[usb_port].rx_cb(uart_port_usb);   /* RX complete callback */

					/* Short packet or buffer full will update write index */
					g_UsbACM[usb_port].rx_buf_w_index++;

					if(g_UsbACM[usb_port].rx_buf_w_index == (RNDIS_RX_BUFFER_NUM+1))
						g_UsbACM[usb_port].rx_buf_w_index = 0;


					USB_Dbg_Trace(USB_ACM_HIGHSPEED_MOVE_W_INDEX, g_UsbACM[usb_port].rx_buf_w_index, g_UsbACM[usb_port].rx_buf_count);
					usb_drv_trace4(USB2UARTPort[usb_port].ownerid, (kal_uint32)USBACM_MOVE_W_INDEX, g_UsbACM[usb_port].rx_buf_w_index, g_UsbACM[usb_port].rx_buf_count, g_UsbACM[usb_port].rx_buf_rc_index, g_UsbACM[usb_port].rx_buf_r_index);

					if(g_UsbACM[usb_port].rx_buf_count > RNDIS_RX_BUFFER_NUM)
						ASSERT(0);

					/* Decide if we need to disable USB_IRQ */
//					if(g_UsbACM[usb_port].rx_buf_w_index == g_UsbACM[usb_port].rx_buf_rc_index)
					if(g_UsbACM[usb_port].rx_buf_addr[g_UsbACM[usb_port].rx_buf_w_index] == NULL)	// no more bufer				
					{
						loop_count = USB_RNDIS_RX_LOOP_COUNT;
						g_UsbACM[usb_port].rx_full_data = KAL_TRUE;

						usb_drv_trace1(USB2UARTPort[usb_port].ownerid, (kal_uint32)USBACM_RX_NO_BUFFER, g_UsbACM[usb_port].rx_buf_count);

//						if(port == uart_port_usb)  // cannot disable interrupt:  Because control pipe should send response back to PC
//							USB_Mask_Irq(USB_MASK_OWNER_COM_1);
					}
					else
						USB_EP_Rx_Ready(g_UsbACM[usb_port].rxpipe->byEP, USB_ENDPT_BULK); /* Clear RxPktRdy */
				
				}

				if(loop_count != USB_RNDIS_RX_LOOP_COUNT)
				{
					if(USB_Get_RX_EP_ISR_Status(g_UsbACM[usb_port].rxpipe->byEP) == KAL_TRUE)
					{
						nCount = USB_EP_Rx_Pkt_Len(g_UsbACM[usb_port].rxpipe->byEP);

						USB_Clr_RX_EP_ISR(g_UsbACM[usb_port].rxpipe->byEP);

						// 0 must due to NULL packet */
						if(nCount == 0)
						{
						
							ASSERT(0);
							
							g_UsbACM[usb_port].rx_buf_w_index++;
							
							if(g_UsbACM[usb_port].rx_buf_w_index == (RNDIS_RX_BUFFER_NUM+1))
								g_UsbACM[usb_port].rx_buf_w_index = 0;

							if(g_UsbACM[usb_port].rx_buf_addr[g_UsbACM[usb_port].rx_buf_w_index] == NULL)	// no more bufer	
							{							
								loop_count = USB_RNDIS_RX_LOOP_COUNT;
								
								usb_drv_trace1(USB2UARTPort[usb_port].ownerid, (kal_uint32)USBACM_RX_NO_BUFFER, g_UsbACM[usb_port].rx_buf_count);

//								if(port == uart_port_usb)
//									USB_Mask_Irq(USB_MASK_OWNER_COM_1);
							}
							else
							{		
								USB_EP_Rx_Ready(g_UsbACM[usb_port].rxpipe->byEP, USB_ENDPT_BULK);
							}
						}
				
//						if(INT_Exception_Enter == 0)
//							usb_drv_trace2(USB2UARTPort[usb_port].ownerid, (kal_uint32)USBACM_PC_SENT, nCount, usb_port);  // temp remove

						USB_Dbg_Trace(USB_ACM_RX_NEXT_PKT_LENGTH, nCount, 0);
					}
					else
					{
						nCount = 0;
						USB_Dbg_Trace(USB_ACM_RX_NEXT_PKT_LENGTH, 0, 0);
}
				} // loop



			}  // while
		} // high speed
		else
			ASSERT(0);
		
	} // UART owner
				
}
static void USB_ISD_BulkIn_Reset(void)
{
	USB_Acm_BulkIn_Reset(uart_port_usb);
}

static void USB_ISD_BulkOut_Reset(void)
{
	USB_Acm_BulkOut_Reset(uart_port_usb);
}


void USB_ISD_DataIf_Create(void *ifname)
{
	kal_uint32 usb_port = USB_PORT[uart_port_usb];

	USB_Acm_DataIf_Create(uart_port_usb, ifname);

	/* Get resource number and register to gUsbDevice */
	g_UsbACM[usb_port].data_if_info->ifdscr.stdif.bInterfaceClass = USB_ISD_DATA_INTERFACE_CLASS_CODE;
	g_UsbACM[usb_port].data_if_info->ifdscr.stdif.bInterfaceSubClass = USB_ISD_DATA_INTERFACE_SUBCLASS_CODE;
	g_UsbACM[usb_port].data_if_info->ifdscr.stdif.bInterfaceProtocol = USB_ISD_DATA_INTERFACE_PROTOCOL_CODE;

	/* TX Endpoint handler */
	g_UsbACM[usb_port].data_ep_in_info->ep_reset = USB_ISD_BulkIn_Reset;

	/* RX Endpoint handler */
//		USB_Register_Drv_Info(USB_DRV_HDLR_EP_RX, ep_rx_id, NULL);
	USB_Register_Drv_Info(USB_DRV_HDLR_EP_RX, g_UsbACM[usb_port].data_ep_out_info->ep_status.epout_status.byEP, USB_ISD_BulkOut_Hdr);
	g_UsbACM[usb_port].data_ep_out_info->ep_reset = USB_ISD_BulkOut_Reset;

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
#ifndef __USB_HS_ENABLE__
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
#ifndef __USB_HS_ENABLE__
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
#endif

}

void USB_ISD_DataIf_Reset(void)
{
	kal_uint32 usb_port = USB_PORT[uart_port_usb];

	g_UsbACM[usb_port].send_UARTilm = KAL_FALSE;
	USB_Acm_DataIf_Reset(uart_port_usb);
}

void USB_ISD_DataIf_Enable(void)
{
	USB_Acm_DataIf_Enable(uart_port_usb);
}

void USB_ISD_DataIf_Speed_Reset(kal_bool b_other_speed)
{
	USB_Acm_DataIf_Speed_Reset(uart_port_usb, b_other_speed);
}

void USB_ISD_Stop_Transfer(void)
{
	kal_uint32 usb_port;
	kal_uint32 savedMask;
	kal_uint32 count = 0;


	for(usb_port = 0; usb_port < MAX_USB_PORT_NUM; usb_port++)
	{

		/* For TX, should sleep PPP until DMA stop running */
		if(g_UsbACM[usb_port].setup_dma == KAL_TRUE)
		{
			count = 0;

			while((g_UsbACM[usb_port].setup_dma == KAL_TRUE)&&(count != USBACM_HIGH_SPEED_LOOP)&&(USB_Get_Device_State() == DEVSTATE_CONFIG))
			{
				count++;
				kal_sleep_task(1);
			}

			savedMask = SaveAndSetIRQMask();
			if(g_UsbACM[usb_port].txpipe != NULL)
			{
				USB_Stop_DMA_Channel(g_UsbACM[usb_port].txpipe->byEP, USB_EP_TX_DIR);
				g_UsbACM[usb_port].setup_dma = KAL_FALSE;
			}
			RestoreIRQMask(savedMask);
			if(count == USBACM_HIGH_SPEED_LOOP)
			{
				usb_drv_trace1(USB2UARTPort[usb_port].ownerid, (kal_uint32)USBACM_DISABLE_HIGH_SPEED_IF_TIMEOUT, USBACM_HIGH_SPEED_LOOP);
				USB_Debug_Information(g_UsbACM[usb_port].txpipe->byEP, USB_EP_TX_DIR, KAL_FALSE);
				//ASSERT(0);
			}
		}
	}
}

#endif


#ifdef __MBIM_SUPPORT__
static void USB_MBIM_Ep0_Set_Ntb_Input_Size(void *data)
{
	kal_uint32 nCount;
	kal_uint32 NTB[64];

	/* Read setting and send to RNDIS */
	nCount = USB_EP0_Pkt_Len();
	if (nCount != 0)
	{
		USB_EPFIFORead(0, nCount, NTB, KAL_FALSE);
	}
	else
	{
		ASSERT(0);
	}
	
	mbim_sio_setNtbInputSize(NTB[0]);

	USB_Set_Endpoint0_State(USB_EP0_RX_STATUS);
	USB_Update_EP0_State(USB_EP0_DRV_STATE_READ_END, KAL_FALSE, KAL_TRUE);
}

static void USB_MBIM_Ep0_SendEncapsulated(void *data)
{
	kal_uint32 usb_port = USB_PORT[uart_port_usb];
	kal_uint32 nCount;
	Usb_Ep0_Status *pep0state = (void*)data;

	/* Read setting and send to RNDIS */
	nCount = USB_EP0_Pkt_Len();


	if((g_UsbACM[usb_port].rx_flc_temp_length != 0)||(g_UsbACM[usb_port].rx_flc_temp == KAL_TRUE))
			ASSERT(0);  // continue recieve 2 Command from PC

	pep0state->nBytesLeft -= nCount;
	
	if (nCount != 0)
	{
		if (nCount < USB_EP0_MAXP) //64 N + short packet
		{
			if ((g_UsbACM[usb_port].rx_flc_buf_data_len[g_UsbACM[usb_port].rx_flc_buf_w_index]%USB_EP0_MAXP)!=0)
				ASSERT(0);
		}
			
	//	USB_EPFIFORead(0, nCount, g_UsbACM[usb_port].rx_flc_buf_addr[g_UsbACM[usb_port].rx_flc_buf_w_index], KAL_FALSE);
	//  after enumeration, UPS has not time to push buffer & already received EP0 Command
	
//		if ((kal_uint8 *)((kal_uint32)g_UsbACM[usb_port].rx_flc_buf_addr[g_UsbACM[usb_port].rx_flc_buf_w_index]+g_UsbACM[usb_port].rx_flc_buf_data_len[g_UsbACM[usb_port].rx_flc_buf_w_index]) == NULL)
		if ((g_UsbACM[usb_port].rx_flc_buf_addr[g_UsbACM[usb_port].rx_flc_buf_w_index] == NULL) && (g_UsbACM[usb_port].rx_flc_buf_data_len[g_UsbACM[usb_port].rx_flc_buf_w_index] == 0))
		{
				if(g_UsbACM[usb_port].rx_flc_buf_count == 0) // ups has not push buffer yet
				{	 // queue data in HW
					g_UsbACM[usb_port].rx_flc_temp_length = nCount;
					g_UsbACM[usb_port].rx_flc_temp = KAL_TRUE;

					USB_EPFIFORead(0, nCount, g_UsbACM[usb_port].rx_flc_temp_buf_addr, KAL_FALSE);
				}
				else
				{
					//EXT_ASSERT(0,
					//	(kal_uint32)g_UsbACM[usb_port].rx_flc_buf_count,
					//	(kal_uint32)g_UsbACM[usb_port].rx_flc_buf_addr[g_UsbACM[usb_port].rx_flc_buf_w_index],
					//	(kal_uint32)g_UsbACM[usb_port].rx_flc_buf_data_len[g_UsbACM[usb_port].rx_flc_buf_w_index]);
					
					usb_drv_trace2(USB2UARTPort[usb_port].ownerid, (kal_uint32)USBACM_Drop,0,0);
					USB_EPFIFORead(0, nCount, g_UsbACM[usb_port].rx_flc_temp_buf_addr, KAL_FALSE);	
					nCount = 0;			
				}
		}
		else
		{
			USB_EPFIFORead(0, nCount, (kal_uint8 *)((kal_uint32)g_UsbACM[usb_port].rx_flc_buf_addr[g_UsbACM[usb_port].rx_flc_buf_w_index]+g_UsbACM[usb_port].rx_flc_buf_data_len[g_UsbACM[usb_port].rx_flc_buf_w_index]), KAL_FALSE);
			g_UsbACM[usb_port].rx_flc_buf_data_len[g_UsbACM[usb_port].rx_flc_buf_w_index] += nCount;	
		}
	}

//=================================

	if ((nCount == USB_EP0_MAXP)&&(pep0state->nBytesLeft > 0))
	{
		USB_Set_Endpoint0_State(USB_EP0_RX);
		USB_Update_EP0_State(USB_EP0_DRV_STATE_READ_END, KAL_FALSE, KAL_FALSE);
	}
	else
	{
		USB_Set_Endpoint0_State(USB_EP0_RX_STATUS);
		USB_Update_EP0_State(USB_EP0_DRV_STATE_READ_END, KAL_FALSE, KAL_TRUE);

		if (g_UsbACM[usb_port].rx_flc_temp == KAL_FALSE) // if data queue in HW, don't notice UPS & update pointer 
		{	
			if (nCount != 0)  // ther is no NULL packet at the end of the control transfer
			{
				g_UsbACM[usb_port].rx_flc_buf_w_index++;

				if(g_UsbACM[usb_port].rx_flc_buf_w_index == (RNDIS_RX_FLC_BUFFER_NUM+1))
					g_UsbACM[usb_port].rx_flc_buf_w_index = 0;

				if(g_UsbACM[usb_port].rx_flc_buf_count > RNDIS_RX_FLC_BUFFER_NUM)
					ASSERT(0);

				if(g_UsbACM[usb_port].send_ctrl_Rxilm == KAL_TRUE)
				{   
					g_UsbACM[usb_port].send_ctrl_Rxilm = KAL_FALSE;		
					USB2UART_Sendilm(uart_port_usb, MSG_ID_CTRL_UART_READY_TO_READ_IND);
				}
			}
		}

	}
}
	


/* Parse class specific request */
static void USB_MBIM_Ep0_Command(Usb_Ep0_Status* pep0state, Usb_Command* pcmd)
{
	kal_uint32 usb_port = USB_PORT[uart_port_usb];
	kal_bool  bError = KAL_FALSE;
//	SGPT_CTRL_START_T start;


	if (g_UsbACM[usb_port].halt_flag == KAL_TRUE)
		g_UsbACM[usb_port].halt_flag = KAL_FALSE;


	usb_drv_trace2(USB2UARTPort[usb_port].ownerid, (kal_uint32)USBACM_EP0_COMMAND,(kal_uint32)pcmd->bRequest, usb_port);

	switch (pcmd->bRequest)
	{
	case USB_ACM_SEND_ENCAPSULATED_COMMAND:
		{
			/*record wLength*/
			pep0state->nBytesLeft = pcmd->wLength;
			
			/* register handler to handle the get data*/
			g_UsbACM[usb_port].intr_pkt.bRequest = USB_ACM_NOTIF_RESPONSE_AVAILABLE;
			USB_Register_EP0_RxHdlr(USB_MBIM_Ep0_SendEncapsulated);
			USB_Set_Endpoint0_State(USB_EP0_RX);
		}
		break;
	case USB_ACM_GET_ENCAPSULATED_RESPONSE:
		{
			/* tell host the current setting */
			USB_Generate_EP0Data(pep0state, pcmd, g_UsbACM[usb_port].tx_flc_data_addr, g_UsbACM[usb_port].tx_flc_count);
			g_UsbACM[usb_port].ctrl_data_done = KAL_TRUE;
			
			if(g_UsbACM[usb_port].send_ctrl_Txilm == KAL_TRUE)
			{
				USB2UART_Sendilm(uart_port_usb, MSG_ID_CTRL_UART_READY_TO_WRITE_IND);
				g_UsbACM[usb_port].send_ctrl_Txilm = KAL_FALSE;
			}
		}
		break;
	case USB_NCM_GET_NTB_PARAMETERS:
		{
			/* request the function to report parameters that characterize the Network Control Block */
			kal_uint16 *ntb_ptr;
			kal_uint8 len;
			
			mbim_sio_getNtbParameters(&ntb_ptr, &len);
			USB_Generate_EP0Data(pep0state, pcmd, (void *)ntb_ptr, len);
		}
		break;
	case USB_NCM_RESET:
		{
			USB2UART_Sendilm(uart_port_usb, MSG_ID_MBIM_USB_RESET_IND);
			USB_Set_Endpoint0_State(USB_EP0_RX);
		}
		break;
	
	case USB_NCM_GET_NTB_INPUT_SIZE:
		{
			kal_uint32 size;
			mbim_sio_getNtbInputSize(&size);
			USB_Generate_EP0Data(pep0state, pcmd, &size, 4);
		}
		break;
		
	case USB_NCM_SET_NTB_INPUT_SIZE:
		if (pcmd->wLength != 0x04)
		{
			bError = KAL_TRUE;
		}
		else
		{
			USB_Register_EP0_RxHdlr(USB_MBIM_Ep0_Set_Ntb_Input_Size);
			USB_Set_Endpoint0_State(USB_EP0_RX);	
		}
		break;
		
	case USB_NCM_GET_NET_ADDRESS:
		{
			kal_uint8 *ptr;
			kal_uint8 len;
			
			mbim_sio_getNetAddress(&ptr, &len);
			USB_Generate_EP0Data(pep0state, pcmd, (void *)ptr, len);
		}
		break;
		
	case USB_ACM_SET_LINE_CODING:
	case USB_ACM_GET_LINE_CODING:
	case USB_ACM_SET_CONTROL_LINE_STATE:		
	case USB_ACM_SEND_BREAK:
	case USB_ACM_SET_COMM_FEATURE:
	case USB_ACM_GET_COMM_FEATURE:
	case USB_ACM_CLEAR_COMM_FEATURE:
	default:
		bError = KAL_TRUE;
		break;
	}

	/* Stall command if an error occured */
	USB_EP0_Command_Hdlr(bError);
/*	
	if(USB_Get_Endpoint0_State() == USB_EP0_IDLE)
	{
		USB_Set_Endpoint0_State(USB_EP0_RX_STATUS);

		USB_Update_EP0_State(USB_EP0_DRV_STATE_READ_END, bError, KAL_TRUE);
	}
	else
	{
		USB_Update_EP0_State(USB_EP0_DRV_STATE_READ_END, bError, KAL_FALSE);
	}
*/	
}

static void USB_MBIM_IntrIn_Hdlr(void)
{
	USB_Acm_IntrIn_Hdlr(uart_port_usb);
}

static void USB_MBIM_IntrIn_Reset(void)
{
	USB_Acm_IntrIn_Reset(uart_port_usb);
}


void USB_MBIM_CommIf_Create(void *ifname)
{	
	kal_uint32 usb_port = USB_PORT[uart_port_usb];
	kal_uint8 ep_id;
	kal_uint8 if_id;

	USB2UARTPort[usb_port].class_type = CDC_MBIM_CLASS;
	drv_trace0(TRACE_FUNC, (kal_uint32)USB_MBIM_CONFIG);
	

	/* Get resource number and register to gUsbDevice */
	g_UsbACM[usb_port].comm_if_info = USB_Get_Interface_Number(&if_id);
	g_UsbACM[usb_port].comm_ep_intr_info = USB_Get_Intr_Ep(&ep_id);

	/* Record interface name and interface descriptor length */
	g_UsbACM[usb_port].comm_if_info->interface_name_ptr = (kal_char *)ifname;
	g_UsbACM[usb_port].comm_if_info->ifdscr_size = USB_MBIM_IF_LENGTH; //USB_CDC_IF_LENGTH;
	g_UsbACM[usb_port].comm_ep_intr_info->epdscr_size = USB_EPDSC_LENGTH;

	/* Related endpoint info and class specific command handler */
	g_UsbACM[usb_port].comm_if_info->ep_info[0] = g_UsbACM[usb_port].comm_ep_intr_info;
	g_UsbACM[usb_port].comm_if_info->if_class_specific_hdlr = USB_MBIM_Ep0_Command;

	kal_mem_cpy(&(g_UsbACM[usb_port].comm_if_info->ifdscr.stdif), cdcacm_com_if_dscr, USB_CDC_IF_LENGTH);
	kal_mem_cpy(&(g_UsbACM[usb_port].comm_ep_intr_info->epdesc.stdep), cdcacm_intr_dscr, USB_EPDSC_LENGTH);

	/* Standard interface descriptor */
	((Usb_MBIM_If_Dscr*)g_UsbACM[usb_port].comm_if_info->ifdscr.classif)->bInterfaceNumber = if_id;
	((Usb_MBIM_If_Dscr*)g_UsbACM[usb_port].comm_if_info->ifdscr.classif)->iInterface =USB_Get_String_Number((void *)g_UsbACM_Comm.acm_param->comm_interface_string);
	
	/* Endpoint handler */
	USB_Register_Drv_Info(USB_DRV_HDLR_EP_TX, ep_id, USB_Acm1_IntrIn_Hdlr);
	g_UsbACM[usb_port].comm_ep_intr_info->ep_reset = USB_Acm1_IntrIn_Reset;



#ifndef  __USB_COMPOSITE_REMOVE_IAD__
#if defined(__USB_COMPOSITE_DEVICE_SUPPORT__)
		/* Construct IAD descriptor */
		g_UsbACM[usb_port].iad_desc = USB_Get_IAD_Number();
		g_UsbACM[usb_port].iad_desc->bLength = USB_IAD_LENGTH;
		g_UsbACM[usb_port].iad_desc->bDescriptorType = USB_INTERFACE_ASSOCIATION;
		g_UsbACM[usb_port].iad_desc->bInterfaceCount = USB_CDC_ACM_IF_NUMBER;

		g_UsbACM[usb_port].iad_desc->bFirstInterface = if_id;
		g_UsbACM[usb_port].iad_desc->bFunctionClass = USB_MBIM_COMM_INTERFACE_CLASS_CODE;
		g_UsbACM[usb_port].iad_desc->bFunctionSubClass = USB_MBIM_COMM_INTERFACE_SUBCLASS_CODE;
		g_UsbACM[usb_port].iad_desc->bFunctionProtocol = USB_MBIM_COMM_INTERFACE_PROTOCOL_CODE;
		g_UsbACM[usb_port].iad_desc->iFunction = ((Usb_Cdc_If_Dscr*)g_UsbACM[usb_port].comm_if_info->ifdscr.classif)->iInterface;
		
		if(g_UsbACM[usb_port].iad_desc->iFunction == 0x00)
			ASSERT(0);
#endif
#endif

	
	/* Header Functional Descriptor */
	((Usb_MBIM_If_Dscr*)g_UsbACM[usb_port].comm_if_info->ifdscr.classif)->HFbFunctionLength = 0x05;
	((Usb_MBIM_If_Dscr*)g_UsbACM[usb_port].comm_if_info->ifdscr.classif)->HFbDescriptorType = 0x24;
	((Usb_MBIM_If_Dscr*)g_UsbACM[usb_port].comm_if_info->ifdscr.classif)->HFbDescriptorSubtype = 0x00;
	((Usb_MBIM_If_Dscr*)g_UsbACM[usb_port].comm_if_info->ifdscr.classif)->bcdCDC = 0x0110;
	
	/* Union Functional Descriptor */
	((Usb_MBIM_If_Dscr*)g_UsbACM[usb_port].comm_if_info->ifdscr.classif)->UFbFunctionLength = 0x05;
	((Usb_MBIM_If_Dscr*)g_UsbACM[usb_port].comm_if_info->ifdscr.classif)->UFbDescriptorType = 0x24;
	((Usb_MBIM_If_Dscr*)g_UsbACM[usb_port].comm_if_info->ifdscr.classif)->UFbDescriptorSubtype = 0x06;
	((Usb_MBIM_If_Dscr*)g_UsbACM[usb_port].comm_if_info->ifdscr.classif)->bMasterInterface = if_id;
	((Usb_MBIM_If_Dscr*)g_UsbACM[usb_port].comm_if_info->ifdscr.classif)->bSlaveInterface0 = USB_Acm_Get_DataIf_Num(usb_port);//g_UsbACM.data_interface_id;

	/* Endpoint descriptor */
	g_UsbACM[usb_port].comm_ep_intr_info->epdesc.stdep.bEndpointAddress = (USB_EP_DIR_IN|ep_id);	/*InPipe*/
	g_UsbACM[usb_port].comm_ep_intr_info->epdesc.stdep.bInterval = 1;
	g_UsbACM[usb_port].comm_ep_intr_info->ep_status.epin_status.byEP = ep_id;
	g_UsbACM[usb_port].comm_ep_intr_info->ep_status.epin_status.nBytesLeft = USB_EP_NODATA;


	
	//=================================================
	//=================================================
	((Usb_MBIM_If_Dscr*)g_UsbACM[usb_port].comm_if_info->ifdscr.classif)->bInterfaceClass = USB_MBIM_COMM_INTERFACE_CLASS_CODE;
	((Usb_MBIM_If_Dscr*)g_UsbACM[usb_port].comm_if_info->ifdscr.classif)->bInterfaceSubClass = USB_MBIM_COMM_INTERFACE_SUBCLASS_CODE;
	((Usb_MBIM_If_Dscr*)g_UsbACM[usb_port].comm_if_info->ifdscr.classif)->bInterfaceProtocol = USB_MBIM_COMM_INTERFACE_PROTOCOL_CODE;
	
	((Usb_MBIM_If_Dscr*)g_UsbACM[usb_port].comm_if_info->ifdscr.classif)->MBIMbFunctionLength = 0x0C;
	((Usb_MBIM_If_Dscr*)g_UsbACM[usb_port].comm_if_info->ifdscr.classif)->MBIMbDescriptorType = 0x24;
	((Usb_MBIM_If_Dscr*)g_UsbACM[usb_port].comm_if_info->ifdscr.classif)->MBIMbDescriptorSubtype = USB_MBIM_DESCRIPTOR_CODE;
	((Usb_MBIM_If_Dscr*)g_UsbACM[usb_port].comm_if_info->ifdscr.classif)->MBIMbcdMBIMVersion = 0x0100;
	((Usb_MBIM_If_Dscr*)g_UsbACM[usb_port].comm_if_info->ifdscr.classif)->MBIMwMaxControlMessage = MBIM_MAX_CONTROL_MESSAGE;
	((Usb_MBIM_If_Dscr*)g_UsbACM[usb_port].comm_if_info->ifdscr.classif)->MBIMbNumberFiliters = MBIM_NUMBER_FILTERS;
	((Usb_MBIM_If_Dscr*)g_UsbACM[usb_port].comm_if_info->ifdscr.classif)->MBIMbMaxFiliterSize = MBIM_MAX_FILTER_SIZE;
	((Usb_MBIM_If_Dscr*)g_UsbACM[usb_port].comm_if_info->ifdscr.classif)->MBIMwMaxSegmentSize = MBIM_MAX_SEGMENT_SIZE;
	((Usb_MBIM_If_Dscr*)g_UsbACM[usb_port].comm_if_info->ifdscr.classif)->MBIMbmNetworkCapabilities = 0x20;


	/* Endpoint handler */
	USB_Register_Drv_Info(USB_DRV_HDLR_EP_TX, g_UsbACM[usb_port].comm_ep_intr_info->ep_status.epin_status.byEP, USB_MBIM_IntrIn_Hdlr);
	g_UsbACM[usb_port].comm_ep_intr_info->ep_reset = USB_MBIM_IntrIn_Reset;

	g_UsbACM[usb_port].intr_pkt.bmRequestType = USB_CMD_CLASSIFIN;
	g_UsbACM[usb_port].intr_pkt.bRequest = USB_ACM_NOTIF_RESPONSE_AVAILABLE;
	g_UsbACM[usb_port].intr_pkt.wValue = 0;
	g_UsbACM[usb_port].intr_pkt.wIndex = 0;//if_id;
	g_UsbACM[usb_port].intr_pkt.wLength = 0;
	g_UsbACM[usb_port].intr_pkt.Data = 0;	

	
}

void USB_MBIM_CommIf_Reset(void)
{
	USB_Acm_CommIf_Reset(uart_port_usb);
}

void USB_MBIM_CommIf_Enable(void)
{
	USB_Acm_CommIf_Enable(uart_port_usb);
}

void USB_MBIM_CommIf_Speed_Reset(kal_bool b_other_speed)
{
	USB_Acm_CommIf_Speed_Reset(uart_port_usb, b_other_speed);
}




/* 14MB/s version, handle multiple packets inside one ISR */

/* EP Bulk Out interrupt handler, called by EP interrupt */
static void USB_MBIM_BulkOut_Hdr(void)
{
	ASSERT(0);
				
}
static void USB_MBIM_BulkIn_Reset(void)
{
	USB_Acm_BulkIn_Reset(uart_port_usb);
}

static void USB_MBIM_BulkOut_Reset(void)
{
	USB_Acm_BulkOut_Reset(uart_port_usb);
}


void USB_MBIM_DataIf_Create(void *ifname)
{
	kal_uint32 usb_port = USB_PORT[uart_port_usb];

	USB_Acm_DataIf_Create(uart_port_usb, ifname);

	/* Get resource number and register to gUsbDevice */
	g_UsbACM[usb_port].data_if_info->ifdscr.stdif.bInterfaceClass = USB_MBIM_DATA_INTERFACE_CLASS_CODE;
	g_UsbACM[usb_port].data_if_info->ifdscr.stdif.bInterfaceSubClass = USB_MBIM_DATA_INTERFACE_SUBCLASS_CODE;
	g_UsbACM[usb_port].data_if_info->ifdscr.stdif.bInterfaceProtocol = USB_MBIM_DATA_INTERFACE_PROTOCOL_CODE;
	
	/* Using alternate setting; set original data interface endpoint number to 0*/
	g_UsbACM[usb_port].data_if_info->ifdscr.stdif.bNumEndpoints = 0; 
	
	/* Alternate interface setting inferface info*/
	g_UsbACM[usb_port].mbim_if_alter_info = USB_Get_Interface_Alternate_Setting(g_UsbACM[usb_port].data_interface_id);
	g_UsbACM[usb_port].mbim_if_alter_info->ifdscr_size = USB_IFDSC_LENGTH;
	g_UsbACM[usb_port].mbim_if_alter_info->ep_info[0] = g_UsbACM[usb_port].data_ep_in_info; 
	g_UsbACM[usb_port].mbim_if_alter_info->ep_info[1] = g_UsbACM[usb_port].data_ep_out_info;
	
	/* Alternate interface setting descriptor */
	g_UsbACM[usb_port].mbim_if_alter_info->stdif.bLength = USB_IFDSC_LENGTH;
	g_UsbACM[usb_port].mbim_if_alter_info->stdif.bDescriptorType = USB_INTERFACE;
	g_UsbACM[usb_port].mbim_if_alter_info->stdif.bInterfaceNumber = g_UsbACM[usb_port].data_interface_id;
	g_UsbACM[usb_port].mbim_if_alter_info->stdif.bAlternateSetting = 0x01;
	g_UsbACM[usb_port].mbim_if_alter_info->stdif.bNumEndpoints = 0x02;
	g_UsbACM[usb_port].mbim_if_alter_info->stdif.bInterfaceClass = USB_MBIM_DATA_INTERFACE_CLASS_CODE;
	g_UsbACM[usb_port].mbim_if_alter_info->stdif.bInterfaceSubClass = USB_MBIM_DATA_INTERFACE_SUBCLASS_CODE;
	g_UsbACM[usb_port].mbim_if_alter_info->stdif.bInterfaceProtocol = USB_MBIM_DATA_INTERFACE_PROTOCOL_CODE;
	g_UsbACM[usb_port].mbim_if_alter_info->stdif.iInterface = 0x0;

	/* TX Endpoint handler */
	g_UsbACM[usb_port].data_ep_in_info->ep_reset = USB_MBIM_BulkIn_Reset;

	/* RX Endpoint handler */
	USB_Register_Drv_Info(USB_DRV_HDLR_EP_RX, g_UsbACM[usb_port].data_ep_out_info->ep_status.epout_status.byEP, USB_MBIM_BulkOut_Hdr);
	g_UsbACM[usb_port].data_ep_out_info->ep_reset = USB_MBIM_BulkOut_Reset;
}

void USB_MBIM_DataIf_Reset(void)
{
	//kal_uint32 usb_port = USB_PORT[uart_port_usb];
	//g_UsbACM[usb_port].send_UARTilm = KAL_FALSE;
	USB_Acm_DataIf_Reset(uart_port_usb);
}

void USB_MBIM_DataIf_Enable(void)
{
	USB_Acm_DataIf_Enable(uart_port_usb);
}

void USB_MBIM_DataIf_Speed_Reset(kal_bool b_other_speed)
{
	USB_Acm_DataIf_Speed_Reset(uart_port_usb, b_other_speed);
}

void USB_MBIM_Stop_Transfer(void)
{
	kal_uint32 usb_port;
	kal_uint32 savedMask;
	kal_uint32 count = 0;


	for(usb_port = 0; usb_port < MAX_USB_PORT_NUM; usb_port++)
	{

		/* For TX, should sleep PPP until DMA stop running */
		if(g_UsbACM[usb_port].setup_dma == KAL_TRUE)
		{
			count = 0;

			while((g_UsbACM[usb_port].setup_dma == KAL_TRUE)&&(count != USBACM_HIGH_SPEED_LOOP)&&(USB_Get_Device_State() == DEVSTATE_CONFIG))
			{
				count++;
				kal_sleep_task(1);
			}

			savedMask = SaveAndSetIRQMask();
			if(g_UsbACM[usb_port].txpipe != NULL)
			{
				USB_Stop_DMA_Channel(g_UsbACM[usb_port].txpipe->byEP, USB_EP_TX_DIR);
				g_UsbACM[usb_port].setup_dma = KAL_FALSE;
			}
			RestoreIRQMask(savedMask);
			if(count == USBACM_HIGH_SPEED_LOOP)
			{
				usb_drv_trace1(USB2UARTPort[usb_port].ownerid, (kal_uint32)USBACM_DISABLE_HIGH_SPEED_IF_TIMEOUT, USBACM_HIGH_SPEED_LOOP);
				USB_Debug_Information(g_UsbACM[usb_port].txpipe->byEP, USB_EP_TX_DIR, KAL_FALSE);
				//ASSERT(0);
			}
		}
	}
}

#endif //__MBIM_SUPPORT__


#ifdef __ECM_SUPPORT__
	
static void USB_ECM_Ep0_Set_PowerFilter(void *data)
{
	kal_uint32 	usb_port = USB_PORT[uart_port_usb];
	kal_uint32 nCount;
	kal_uint32 Filter[64];

	// Read setting 
	nCount = USB_EP0_Pkt_Len();

	if (nCount != 0)
		USB_EPFIFORead(0, nCount, Filter, KAL_FALSE);

	if (g_UsbACM[usb_port].power_filter_length > 64)
		ASSERT(0);  //QQ ,  filter length ?
		
	ecm_sio_setEthernetPowerManagementPatternFilter(g_UsbACM[usb_port].power_filter_number, g_UsbACM[usb_port].power_filter_length,Filter); 

	USB_Set_Endpoint0_State(USB_EP0_RX_STATUS);
	USB_Update_EP0_State(USB_EP0_DRV_STATE_READ_END, KAL_FALSE, KAL_TRUE);
}


/* Parse class specific request */
static void USB_ECM_Ep0_Command(Usb_Ep0_Status* pep0state, Usb_Command* pcmd)
{
	kal_uint32 	usb_port = USB_PORT[uart_port_usb];
	kal_bool  	bError = KAL_FALSE;
	kal_uint16 	power_filter;
	kal_uint32 	statics;
	
//	SGPT_CTRL_START_T start;

	if (g_UsbACM[usb_port].halt_flag == KAL_TRUE)
		g_UsbACM[usb_port].halt_flag = KAL_FALSE;

	usb_drv_trace2(USB2UARTPort[usb_port].ownerid, (kal_uint32)USBACM_EP0_COMMAND,(kal_uint32)pcmd->bRequest, usb_port);

	switch (pcmd->bRequest)
	{
	case USB_ECM_SET_ETHERNET_POWER_MANAGEMENT_PATTERN_FILTER:
		 g_UsbACM[usb_port].power_filter_number = pcmd->wValue;
		 g_UsbACM[usb_port].power_filter_length = pcmd->wLength;
		 drv_trace2(TRACE_FUNC, (kal_uint32)USB_ECM_GET_POWER_FILTER,pcmd->wValue,pcmd->wLength);			 		 
		 USB_Register_EP0_RxHdlr(USB_ECM_Ep0_Set_PowerFilter);
		 USB_Set_Endpoint0_State(USB_EP0_RX);
		break;		
	case USB_ECM_GET_ETHERNET_POWER_MANAGEMENT_PATTERN_FILTER:
		power_filter = ecm_sio_getEthernetPowerManagementPatternFilter(pcmd->wValue);
		drv_trace1(TRACE_FUNC, (kal_uint32)USB_ECM_POWER_FILTER,power_filter);
	 	USB_Generate_EP0Data(pep0state, pcmd, &power_filter, 2);
		break;		
	case USB_ECM_SET_ETHERNET_PACKET_FILTER:
		drv_trace1(TRACE_FUNC, (kal_uint32)USB_ECM_SET_PACKET_FILTER,pcmd->wValue);				
		ecm_sio_setEthernetPacketFilter(pcmd->wValue);
		break;		
	case USB_ECM_GET_ETHERNET_STATIC:	
		statics = ecm_sio_getEthernetStatistic(pcmd->wValue);
		drv_trace1(TRACE_FUNC, (kal_uint32)USB_ECM_STATIC,statics);		
		USB_Generate_EP0Data(pep0state, pcmd, &statics, 4);
		break;
	case USB_ACM_SEND_ENCAPSULATED_COMMAND:	
	case USB_ACM_GET_ENCAPSULATED_RESPONSE:
	case USB_ECM_SET_ETHERNET_MULTICAST_FILTERS:
	default:
		bError = KAL_TRUE;
		break;
	}
	/* Stall command if an error occured */
	USB_EP0_Command_Hdlr(bError);
}

static void USB_ECM_IntrIn_Hdlr(void)
{	
	kal_uint32 usb_port = USB_PORT[uart_port_usb];
	
	USB_Dbg_Trace(USB_ACM_INTERRUPT_HANDLER, (kal_uint32)g_UsbACM[usb_port].intr_state, uart_port_usb);

	if(USB_Get_Device_State() != DEVSTATE_CONFIG)
	{
		/* USB reset */
		USB_Dbg_Trace(USB_ACM_INTERRUPT_RESET, 0, 0);
	}

	usb_drv_trace2(USB2UARTPort[usb_port].ownerid, (kal_uint32)USBACM_INTR, g_UsbACM[usb_port].intr_pkt.Data, usb_port);
	g_UsbACM[usb_port].intr_state = ACM_INTR_IDLE;
}

static void USB_ECM_IntrIn_Reset(void)
{
	USB_Acm_IntrIn_Reset(uart_port_usb);
}

void USB_ECM_CommIf_Create(void *ifname)
{	
	kal_uint32 usb_port = USB_PORT[uart_port_usb];
	kal_uint8 ep_id;
	kal_uint8 if_id;
	kal_uint8 mac_addr;
				
	USB2UARTPort[usb_port].class_type = CDC_ECM_CLASS;
	drv_trace0(TRACE_FUNC, (kal_uint32)USB_ECM_CONFIG);
	
	/* Get resource number and register to gUsbDevice */
	g_UsbACM[usb_port].comm_if_info = USB_Get_Interface_Number(&if_id);
	g_UsbACM[usb_port].comm_ep_intr_info = USB_Get_Intr_Ep(&ep_id);

	/* Endpoint handler */
	USB_Register_Drv_Info(USB_DRV_HDLR_EP_TX, ep_id, USB_ECM_IntrIn_Hdlr);
	g_UsbACM[usb_port].comm_ep_intr_info->ep_reset = USB_ECM_IntrIn_Reset;

	/* Record interface name and interface descriptor length */
	g_UsbACM[usb_port].comm_if_info->interface_name_ptr = (kal_char *)ifname;
	g_UsbACM[usb_port].comm_if_info->ifdscr_size = USB_ECM_IF_LENGTH; 
	g_UsbACM[usb_port].comm_ep_intr_info->epdscr_size = USB_EPDSC_LENGTH;

	/* Related endpoint info and class specific command handler */
	g_UsbACM[usb_port].comm_if_info->ep_info[0] = g_UsbACM[usb_port].comm_ep_intr_info;
	g_UsbACM[usb_port].comm_if_info->if_class_specific_hdlr = USB_ECM_Ep0_Command;

	kal_mem_cpy(&(g_UsbACM[usb_port].comm_if_info->ifdscr.stdif), cdcacm_com_if_dscr, USB_CDC_IF_LENGTH);
	kal_mem_cpy(&(g_UsbACM[usb_port].comm_ep_intr_info->epdesc.stdep), cdcacm_intr_dscr, USB_EPDSC_LENGTH);

	ecm_sio_getNetAddress(&g_UsbACM[usb_port].mac_addr_ptr);
	mac_addr  = USB_Get_String_Number((void *)g_UsbACM[usb_port].mac_addr_ptr);
	
	/* Standard interface descriptor */
	((Usb_Ecm_If_Dscr*)g_UsbACM[usb_port].comm_if_info->ifdscr.classif)->bInterfaceNumber = if_id;
	((Usb_Ecm_If_Dscr*)g_UsbACM[usb_port].comm_if_info->ifdscr.classif)->bInterfaceClass = USB_ECM_COMM_INTERFACE_CLASS_CODE;
	((Usb_Ecm_If_Dscr*)g_UsbACM[usb_port].comm_if_info->ifdscr.classif)->bInterfaceSubClass = USB_ECM_COMM_INTERFACE_SUBCLASS_CODE;
	((Usb_Ecm_If_Dscr*)g_UsbACM[usb_port].comm_if_info->ifdscr.classif)->bInterfaceProtocol = USB_ECM_COMM_INTERFACE_PROTOCOL_CODE;
	((Usb_Ecm_If_Dscr*)g_UsbACM[usb_port].comm_if_info->ifdscr.classif)->iInterface =USB_Get_String_Number((void *)g_UsbACM_Comm.acm_param->comm_interface_string);

#ifndef  __USB_COMPOSITE_REMOVE_IAD__
#if defined(__USB_COMPOSITE_DEVICE_SUPPORT__)
	/* Construct IAD descriptor */
	g_UsbACM[usb_port].iad_desc = USB_Get_IAD_Number();
	g_UsbACM[usb_port].iad_desc->bLength = USB_IAD_LENGTH;
	g_UsbACM[usb_port].iad_desc->bDescriptorType = USB_INTERFACE_ASSOCIATION;
	g_UsbACM[usb_port].iad_desc->bInterfaceCount = USB_CDC_ACM_IF_NUMBER;

	g_UsbACM[usb_port].iad_desc->bFirstInterface = if_id;
	g_UsbACM[usb_port].iad_desc->bFunctionClass = USB_ECM_COMM_INTERFACE_CLASS_CODE;
	g_UsbACM[usb_port].iad_desc->bFunctionSubClass = USB_ECM_COMM_INTERFACE_SUBCLASS_CODE;
	g_UsbACM[usb_port].iad_desc->bFunctionProtocol = USB_ECM_COMM_INTERFACE_PROTOCOL_CODE;
	g_UsbACM[usb_port].iad_desc->iFunction = ((Usb_Ecm_If_Dscr*)g_UsbACM[usb_port].comm_if_info->ifdscr.classif)->iInterface;

	if(g_UsbACM[usb_port].iad_desc->iFunction == 0x00)
		ASSERT(0);
#endif
#endif	
	/* Header Functional Descriptor */
	((Usb_Ecm_If_Dscr*)g_UsbACM[usb_port].comm_if_info->ifdscr.classif)->HFbFunctionLength = 0x05;
	((Usb_Ecm_If_Dscr*)g_UsbACM[usb_port].comm_if_info->ifdscr.classif)->HFbDescriptorType = 0x24;
	((Usb_Ecm_If_Dscr*)g_UsbACM[usb_port].comm_if_info->ifdscr.classif)->HFbDescriptorSubtype = 0x00;
	((Usb_Ecm_If_Dscr*)g_UsbACM[usb_port].comm_if_info->ifdscr.classif)->bcdCDC = 0x0110;
	
	/* Union Functional Descriptor */
	((Usb_Ecm_If_Dscr*)g_UsbACM[usb_port].comm_if_info->ifdscr.classif)->UFbFunctionLength = 0x05;
	((Usb_Ecm_If_Dscr*)g_UsbACM[usb_port].comm_if_info->ifdscr.classif)->UFbDescriptorType = 0x24;
	((Usb_Ecm_If_Dscr*)g_UsbACM[usb_port].comm_if_info->ifdscr.classif)->UFbDescriptorSubtype = 0x06;
	((Usb_Ecm_If_Dscr*)g_UsbACM[usb_port].comm_if_info->ifdscr.classif)->bMasterInterface = if_id;
	((Usb_Ecm_If_Dscr*)g_UsbACM[usb_port].comm_if_info->ifdscr.classif)->bSlaveInterface0 = USB_Acm_Get_DataIf_Num(usb_port);//g_UsbACM.data_interface_id;

	/* Ethernet Networking Functional Descriptor */
	((Usb_Ecm_If_Dscr*)g_UsbACM[usb_port].comm_if_info->ifdscr.classif)->ENFbFunctionLength = 0x0D;    
	((Usb_Ecm_If_Dscr*)g_UsbACM[usb_port].comm_if_info->ifdscr.classif)->ENFbDescriptorType = 0x24;
	((Usb_Ecm_If_Dscr*)g_UsbACM[usb_port].comm_if_info->ifdscr.classif)->ENFbDescriptorSubtype = 0x0F;
	((Usb_Ecm_If_Dscr*)g_UsbACM[usb_port].comm_if_info->ifdscr.classif)->iMACAddress = mac_addr;
//	((Usb_Ecm_If_Dscr*)g_UsbACM[usb_port].comm_if_info->ifdscr.classif)->bmEthernetStatistics = 0x00007F18;	
	((Usb_Ecm_If_Dscr*)g_UsbACM[usb_port].comm_if_info->ifdscr.classif)->bmEthernetStatistics1 = ECM_ETHERNET_STATISTICS >>24;
	((Usb_Ecm_If_Dscr*)g_UsbACM[usb_port].comm_if_info->ifdscr.classif)->bmEthernetStatistics2 = ECM_ETHERNET_STATISTICS >>16 ;
	((Usb_Ecm_If_Dscr*)g_UsbACM[usb_port].comm_if_info->ifdscr.classif)->bmEthernetStatistics3 = ECM_ETHERNET_STATISTICS >>8 ;
	((Usb_Ecm_If_Dscr*)g_UsbACM[usb_port].comm_if_info->ifdscr.classif)->bmEthernetStatistics4 = ECM_ETHERNET_STATISTICS >>0 ;
	((Usb_Ecm_If_Dscr*)g_UsbACM[usb_port].comm_if_info->ifdscr.classif)->wMaxSegmentSize1 =	(kal_uint8)ECM_MAX_SEGMENT_SIZE;
	((Usb_Ecm_If_Dscr*)g_UsbACM[usb_port].comm_if_info->ifdscr.classif)->wMaxSegmentSize2 =	(kal_uint16)ECM_MAX_SEGMENT_SIZE >> 8;	
	((Usb_Ecm_If_Dscr*)g_UsbACM[usb_port].comm_if_info->ifdscr.classif)->wNumberMCFilters1 = (kal_uint8)ECM_NUMBER_MC_FILTERS;
	((Usb_Ecm_If_Dscr*)g_UsbACM[usb_port].comm_if_info->ifdscr.classif)->wNumberMCFilters2 = (kal_uint16)ECM_NUMBER_MC_FILTERS >> 8;	
	((Usb_Ecm_If_Dscr*)g_UsbACM[usb_port].comm_if_info->ifdscr.classif)->bNumberPowerFilters = (kal_uint8)ECM_NUMBER_POWER_FILTERS;

	/* Endpoint descriptor */
	g_UsbACM[usb_port].comm_ep_intr_info->epdesc.stdep.bEndpointAddress = (USB_EP_DIR_IN|ep_id);	/*InPipe*/
	g_UsbACM[usb_port].comm_ep_intr_info->epdesc.stdep.bInterval = 1;
	g_UsbACM[usb_port].comm_ep_intr_info->ep_status.epin_status.byEP = ep_id;
	g_UsbACM[usb_port].comm_ep_intr_info->ep_status.epin_status.nBytesLeft = USB_EP_NODATA;

	/* Endpoint handler */
	USB_Register_Drv_Info(USB_DRV_HDLR_EP_TX, g_UsbACM[usb_port].comm_ep_intr_info->ep_status.epin_status.byEP, USB_ECM_IntrIn_Hdlr);
	g_UsbACM[usb_port].comm_ep_intr_info->ep_reset = USB_ECM_IntrIn_Reset;

	g_UsbACM[usb_port].notify_pkt.bmRequestType = USB_CMD_CLASSIFIN;
	g_UsbACM[usb_port].notify_pkt.bNotificationCode= 0;
	g_UsbACM[usb_port].notify_pkt.wValue = 0;
	g_UsbACM[usb_port].notify_pkt.wIndex = if_id;
	g_UsbACM[usb_port].notify_pkt.wLength = 0;	
}

void USB_ECM_CommIf_Reset(void)
{
	USB_Acm_CommIf_Reset(uart_port_usb);
}

void USB_ECM_CommIf_Enable(void)
{
	USB_Acm_CommIf_Enable(uart_port_usb);
}

void USB_ECM_CommIf_Speed_Reset(kal_bool b_other_speed)
{
	USB_Acm_CommIf_Speed_Reset(uart_port_usb, b_other_speed);
}


/* EP Bulk Out interrupt handler, called by EP interrupt */
static void USB_ECM_BulkOut_Hdr(void)
{
// ECM : use DMAQ transfer data
	ASSERT(0);				
}
static void USB_ECM_BulkIn_Reset(void)
{
	USB_Acm_BulkIn_Reset(uart_port_usb);
}

static void USB_ECM_BulkOut_Reset(void)
{
	USB_Acm_BulkOut_Reset(uart_port_usb);
}


void USB_ECM_DataIf_Create(void *ifname)
{
	kal_uint32 usb_port = USB_PORT[uart_port_usb];

	USB_Acm_DataIf_Create(uart_port_usb, ifname);

	/* Get resource number and register to gUsbDevice */
	g_UsbACM[usb_port].data_if_info->ifdscr.stdif.bInterfaceClass = USB_ECM_DATA_INTERFACE_CLASS_CODE;
	g_UsbACM[usb_port].data_if_info->ifdscr.stdif.bInterfaceSubClass = USB_ECM_DATA_INTERFACE_SUBCLASS_CODE;
	g_UsbACM[usb_port].data_if_info->ifdscr.stdif.bInterfaceProtocol = USB_ECM_DATA_INTERFACE_PROTOCOL_CODE;

	/* Using alternate setting; set original data interface endpoint number to 0*/
	g_UsbACM[usb_port].data_if_info->ifdscr.stdif.bNumEndpoints = 0; 

	/* Alternate interface setting inferface info*/
	g_UsbACM[usb_port].ecm_if_alter_info = USB_Get_Interface_Alternate_Setting(g_UsbACM[usb_port].data_interface_id);
	g_UsbACM[usb_port].ecm_if_alter_info->ifdscr_size = USB_IFDSC_LENGTH;
	g_UsbACM[usb_port].ecm_if_alter_info->ep_info[0] = g_UsbACM[usb_port].data_ep_in_info; 
	g_UsbACM[usb_port].ecm_if_alter_info->ep_info[1] = g_UsbACM[usb_port].data_ep_out_info;
	
	/* Alternate interface setting descriptor */
	g_UsbACM[usb_port].ecm_if_alter_info->stdif.bLength = USB_IFDSC_LENGTH;
	g_UsbACM[usb_port].ecm_if_alter_info->stdif.bDescriptorType = USB_INTERFACE;
	g_UsbACM[usb_port].ecm_if_alter_info->stdif.bInterfaceNumber = g_UsbACM[usb_port].data_interface_id;
	g_UsbACM[usb_port].ecm_if_alter_info->stdif.bAlternateSetting = 0x01;
	g_UsbACM[usb_port].ecm_if_alter_info->stdif.bNumEndpoints = 0x02;
	g_UsbACM[usb_port].ecm_if_alter_info->stdif.bInterfaceClass = USB_ECM_DATA_INTERFACE_CLASS_CODE;
	g_UsbACM[usb_port].ecm_if_alter_info->stdif.bInterfaceSubClass = USB_ECM_DATA_INTERFACE_SUBCLASS_CODE;
	g_UsbACM[usb_port].ecm_if_alter_info->stdif.bInterfaceProtocol = USB_ECM_DATA_INTERFACE_PROTOCOL_CODE;
	g_UsbACM[usb_port].ecm_if_alter_info->stdif.iInterface = 0x0;

	/* TX Endpoint handler */
	g_UsbACM[usb_port].data_ep_in_info->ep_reset = USB_ECM_BulkIn_Reset;

	/* RX Endpoint handler */
//		USB_Register_Drv_Info(USB_DRV_HDLR_EP_RX, ep_rx_id, NULL);
	USB_Register_Drv_Info(USB_DRV_HDLR_EP_RX, g_UsbACM[usb_port].data_ep_out_info->ep_status.epout_status.byEP, USB_ECM_BulkOut_Hdr);
	g_UsbACM[usb_port].data_ep_out_info->ep_reset = USB_ECM_BulkOut_Reset;

}

void USB_ECM_DataIf_Reset(void)
{
	kal_uint32 usb_port = USB_PORT[uart_port_usb];

	g_UsbACM[usb_port].send_UARTilm = KAL_FALSE;
	USB_Acm_DataIf_Reset(uart_port_usb);
}

void USB_ECM_DataIf_Enable(void)
{
	USB_Acm_DataIf_Enable(uart_port_usb);
}

void USB_ECM_DataIf_Speed_Reset(kal_bool b_other_speed)
{
	USB_Acm_DataIf_Speed_Reset(uart_port_usb, b_other_speed);
}

void USB_ECM_Stop_Transfer(void)
{
	kal_uint32 usb_port;
	kal_uint32 savedMask;
	kal_uint32 count = 0;


	for(usb_port = 0; usb_port < MAX_USB_PORT_NUM; usb_port++)
	{

		/* For TX, should sleep PPP until DMA stop running */
		if(g_UsbACM[usb_port].setup_dma == KAL_TRUE)
		{
			count = 0;

			while((g_UsbACM[usb_port].setup_dma == KAL_TRUE)&&(count != USBACM_HIGH_SPEED_LOOP)&&(USB_Get_Device_State() == DEVSTATE_CONFIG))
			{
				count++;
				kal_sleep_task(1);
			}

			savedMask = SaveAndSetIRQMask();
			if(g_UsbACM[usb_port].txpipe != NULL)
			{
				USB_Stop_DMA_Channel(g_UsbACM[usb_port].txpipe->byEP, USB_EP_TX_DIR);
				g_UsbACM[usb_port].setup_dma = KAL_FALSE;
			}
			RestoreIRQMask(savedMask);
			if(count == USBACM_HIGH_SPEED_LOOP)
			{
				usb_drv_trace1(USB2UARTPort[usb_port].ownerid, (kal_uint32)USBACM_DISABLE_HIGH_SPEED_IF_TIMEOUT, USBACM_HIGH_SPEED_LOOP);
				USB_Debug_Information(g_UsbACM[usb_port].txpipe->byEP, USB_EP_TX_DIR, KAL_FALSE);
				//ASSERT(0);
			}
		}
	}
}


#endif
/************************************************************
	FT mode rx functions
************************************************************/

/* Register callback function for rx data */
void USB_Acm_FT_Register_Rx_Cb(usb_acm_rx_ptr cb)
{
	g_UsbACM_Comm.ft_rx_cb = cb;
}


/* EP Bulk Out interrupt handler, called by EP interrupt */
static void USB_Acm_FT_BulkOut_Hdr(void)
{
	kal_uint32	nCount;


	/* check data lendth and ring buffer empty length*/
	nCount = USB_EP_Rx_Pkt_Len(g_UsbACM[g_UsbACM_Comm.ft_port_num].rxpipe->byEP);

	if(nCount > 0)
	{
		USB_EPFIFORead(g_UsbACM[g_UsbACM_Comm.ft_port_num].rxpipe->byEP, nCount, g_UsbACM_Comm.ft_data, KAL_FALSE);

		g_UsbACM_Comm.ft_data_len = nCount;

		/* Notify FT task */
		if(g_UsbACM_Comm.ft_rx_cb == NULL)
			ASSERT(0);

		g_UsbACM_Comm.ft_rx_cb();

		/* RX buffer is less than one max packet size, so unmask the IRQ until UART owner get bytes,
		    and enough room to put a complete packet */
		USB_Set_UnMask_Irq(KAL_FALSE);
	}

	/* Clear OutPktRdy */
	USB_EP_Rx_Ready(g_UsbACM[g_UsbACM_Comm.ft_port_num].rxpipe->byEP, USB_ENDPT_BULK);
}

#endif /*__USB_COM_PORT_ENABLE__*/


