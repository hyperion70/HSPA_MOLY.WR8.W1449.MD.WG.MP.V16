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
 *    usb_task.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file implements usb task
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "drv_comm.h"
//#include "stack_common.h"
#include "kal_public_defs.h" //MSBB change #include "stack_msgs.h"
#include "kal_public_api.h" //#include "stack_ltlcom.h" //MSBB change #include "app_ltlcom.h"       /* Task message communiction */
#include "syscomp_config.h"
#include "task_config.h"
//#include "stacklib.h"
//#include "reg_base.h"
#include "usb_comm.h"
#include "drvsignals.h"
#include "eint.h"
///#include "kal_release.h"
#include "init.h"

#include "dcl.h"
//#include "usb_drv.h"
#include "usb_phy_drv.h"
#include "usb_adap.h"
#include "usb.h"
//#include "usb_resource.h"
#ifdef __USB_MASS_STORAGE_ENABLE__
#include "usb_msdisk.h"
#include "usbms_drv.h"
#include "usbms_state.h"
#endif
#ifdef __USB_COM_PORT_ENABLE__
#include "usbacm_drv.h"
#include "usbacm_adap.h"
//#include "usbacm_ft.h"
#endif
#include "usb_trc.h"
#ifdef WEBCAM_SUPPORT
//#include "usbvideo_if.h"
#include "usbvideo_drv.h"
#include "usbvideo_state.h"
#endif
#ifdef __OTG_ENABLE__
//#include "otg_drv.h"
#include "otg.h"
#include "otg_if.h"
#endif
#if defined(__OTG_ENABLE__)||defined(__IC_USB_ENABLE__)
#include "usbd.h"
#include "usb_host_default_drv.h"
#include "usb_host_ms_state.h"
#include "usb_host_ms_drv.h"
//#include "gpio_sw.h"
#endif
#include "usb_mode.h"
#include "usb_task.h"
#include "usb_custom.h"
#include "usb_debug_tool.h"
#ifdef __USB_IMAGE_CLASS__
#include "usbimage_drv.h"
#endif
#ifdef   PICTBRIDGE_SUPPORT
#include "ptp_state.h"
#endif
#ifdef __MTP_ENABLE__
#include "usbimage_mtp_state.h"
#endif
///#include "app_buff_alloc.h"
//#include "nvram.h"
#include "nvram_interface.h"
//#include "nvram_user_defs.h"

#ifdef __USB_LOGGING__
#include "usbacm_logging.h"
#include "usblog_drv.h"
#include "device.h"
#endif
#if defined(__DM_LAWMO_SUPPORT__)
//#include "common_nvram_editor_data_item.h"
#endif
#ifdef __USB_LOGGING__
#include "drv_sw_features_usb.h"
#endif

//#include "fat_fs.h"
//#include "Rtfiles.h"

#ifdef __MULTI_BOOT__
#include "multiboot_config.h"
#endif /* __MULTI_BOOT__ */

#include "kal_public_defs.h" //MSBB change #include "stack_config.h"
///#include "task_main_func.h"
//#include "nvram_common_defs.h"
#include "nvram_data_items.h"
#include "uart_sw.h"
#include "usbvideo_custom.h"
///#include "kal_active_module.h"
#include "drv_features.h"
#include "intrCtrl.h"
#include "kal_public_api.h" //#include "stack_ltlcom.h"
#include "kal_trace.h"
#include "nvram_struct.h"
#include "nvram_enums.h"
#include "kal_general_types.h"
#include "nvram_data_items.h"
#include "kal_public_api.h"
#include "kal_public_defs.h"
//#if defined(__MTP_ENABLE__)||defined(__USB_MASS_STORAGE_ENABLE__)||defined(__OTG_SRP_HNP_APP_FIXED__)
#include "usb_custom_def.h"
//#endif

#include "drv_msgid.h"
#include "nvram_msgid.h"
#include "l4_msgid.h"

/************************************************************
	Extern functions
*************************************************************/
/* function to get buffer for usb boot mode*/
//extern void *kal_tmp_mem_alloc(kal_uint32 size);
/* get eint number*/
extern kal_uint8 custom_eint_get_channel(eint_channel_type type);
/* init eint */
extern void clear_ext_intr_init(kal_uint8 eint_no);
/* get USB boot mode */
extern kal_bool INT_USBBoot(void);
/* On EVB board, there may be no PMIC. */
//extern void BMT_sendMes2UEM(BMT_CHR_STAT status);
/* get target boot mode */
extern kal_uint16 INT_BootMode(void);
/* Com port nvram API */
extern void nvram_get_tst(kal_uint8 *port, kal_uint32 *baudrate);
extern void nvram_get_tst_l1(kal_uint8 *port, kal_uint32 *baudrate);
extern void nvram_get_ps(kal_uint8 *port, kal_uint32 *baudrate);
extern void nvram_get_tst_dsp(kal_uint8 *port, kal_uint32 *baudrate);
//extern void nvram_get_cti(kal_uint8 *port, kal_uint32 *baudrate);
#if defined(__USB_MODEM_CARD_SUPPORT__)
extern void DRV_RESET(void);
extern kal_uint8 custom_em_get_usb_cdrom_config(void);
#endif
#ifdef __USB_MASS_STORAGE_ENABLE__
extern void custom_usb_ms_init(void);
#endif

#ifdef WEBCAM_SUPPORT
extern DCL_STATUS USB_Video_Driver(DCL_DEV dev,DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data);
#endif

#ifdef __MTP_ENABLE__
extern DCL_STATUS USB_Image_Driver(DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data);
#endif


/* Exception flag */
extern kal_uint8 INT_Exception_Enter;

/************************************************************
	Global variables
*************************************************************/
#if defined(__SIM_PLUS__)
kal_bool g_usb_ms_simplus_exist;
#endif

kal_uint8 g_usb_logging_port_num = 0;
#ifdef __USB_LOGGING__
kal_uint8 g_usb_logging_mode = 0;
#endif

kal_bool USB_IS_LOGGING_PORT[uart_max_port];
void USB_EINT_HISR(void);

/************************************************************
	Local functions
*************************************************************/

static kal_bool usb_task_init(void);
static kal_bool usb_task_reset(void);

static void usb_task_main( task_entry_struct * task_entry_ptr);
#ifdef  __USB_MASS_STORAGE_ENABLE__
static void USB_Ms_State_Machine_Hdlr(ilm_struct *lim_ptr);
#endif
#ifdef   PICTBRIDGE_SUPPORT
static void USB_PTP_State_Machine_Hdlr(ilm_struct *lim_ptr);
#endif
#ifdef __MTP_ENABLE__
static void USB_MTP_State_Machine_Hdlr(ilm_struct *lim_ptr);
#endif
static void USB_Config_Req_Hdlr(USB_DEVICE_TYPE mode, kal_uint32 *parameter);
static void USB_Store_Serial_Value(ilm_struct *lim_ptr);
static kal_uint16 USB_Convert_String(kal_uint8 val);
static void USB_Constrct_Serial_String(kal_uint8 *pdu_ptr, kal_uint16 len);

static kal_bool  g_usb_cable_state;

#if defined(__OTG_ENABLE__)||defined(__MTP_ENABLE__)||defined(__USB_TETHERING__)
static kal_bool usb_config_flag = KAL_FALSE;
static kal_bool usb_plug_in_flag = KAL_FALSE;
static kal_bool usb_srp_flag = KAL_FALSE;
#endif

#if !defined(__CHARGER_USB_DETECT_WIHT_ONE_EINT__) && !defined(_USB_VBUS_DETECT_WITH_NIRQ_)
static kal_uint8 g_usb_eint_no;
#endif

kal_uint32 temp_current[3];// normal spec: 99,500 mA	


//DCL_HANDLE g_PWIC_Dcl_Handle;
//DCL_HANDLE g_PW_Dcl_Handle;
/*************************************************************************
* FUNCTION
*	usb_create
*
* DESCRIPTION
*	This function implements xyz entity's create handler.
*
* PARAMETERS
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_bool usb_create(comptask_handler_struct **handle)
{
#ifndef __USB_ENABLE__
	EXT_ASSERT(0, 0, 0, 0);
#endif

	static const comptask_handler_struct usb_handler_info =
	{
		usb_task_main,			/* task entry function */
		usb_task_init,		  	/* task initialization function */
		usb_task_reset			/* task reset handler */
	};

	#if !defined(__CHARGER_USB_DETECT_WIHT_ONE_EINT__) && !defined(_USB_VBUS_DETECT_WITH_NIRQ_)
	g_usb_eint_no = custom_eint_get_channel(usb_eint_chann);
	#endif

	// remove to avoid affecting touch panel function
	//clear_ext_intr_init(g_usb_eint_no);

	*handle = (comptask_handler_struct *)&usb_handler_info;
	return KAL_TRUE;
}

/*************************************************************************
* FUNCTION
*	usb_task_init
*
* DESCRIPTION
*	This function implements xyz's init handler
*
* PARAMETERS
*	task_index	-	task's index
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
static kal_bool usb_task_init(void)
{
#if defined(__SIM_PLUS__)||(defined(__USB_MASS_STORAGE_ENABLE__)&&defined(__MTP_ENABLE__))
	kal_uint8 	nvram_buffer[NVRAM_EF_SYS_CACHE_OCTET_SIZE];
#endif
#if defined(__DM_LAWMO_SUPPORT__)
#endif
//#if defined(__USB_MASS_STORAGE_ENABLE__)||defined(__MTP_ENABLE__)
//	kal_uint32 	buff_size;
//#endif
#ifdef __P_PROPRIETARY_COPYRIGHT__
/* under construction !*/
/* under construction !*/
#endif
#if defined(WEBCAM_SUPPORT)||defined(__USB_LOGGING__)
	kal_uint32 index;
#endif
#if defined(__IC_USB_ENABLE__) ||defined(__OTG_ENABLE__) 
	kal_uint32 index2;
#endif
#ifndef __MEUT__
#ifndef __USB_BOOT_NOT_CHECK_NVRAM_SETTING__
	kal_uint8 port_num1, port_num2, port_num3, port_num4;
	kal_uint32 baudrate;
#endif
#endif
//	PW_CTRL_IS_USB_BOOT CtrlVal;
//	DCL_HANDLE pmu_handle; // add for usb charging 
	kal_uint8 temp_power[USB_DEVDSC_CONFIGS];// normal spec: 100,200,300,400,500 mA
	//	USB_DRV_CTRL_GET_IP_VERSION_T dcl_data;
	kal_uint32	conf_no;
//	DCL_HANDLE pmu_handle;
	PMU_CTRL_CHR_SET_CHR_CURRENT set_chr_current;	
	kal_uint8 temp_index = 0;
#ifdef __USB_TETHERING__
	DCL_BOOL  dcl_data;
//	DCL_HANDLE handle;
#endif



	DclUSB_DRV_Initialize();
	g_USB_Dcl_Handle = DclUSB_DRV_Open(DCL_USB, FLAGS_NONE);

#ifdef __OTG_ENABLE__
	DclOTG_DRV_Initialize();
	g_OTG_Dcl_Handle = DclOTG_DRV_Open(DCL_USB, FLAGS_NONE);
#endif

	
//	if (g_PWIC_Dcl_Handle == 0)
//	   		g_PWIC_Dcl_Handle = DclPMU_Open(DCL_PMU, FLAGS_NONE);
	

	g_UsbMode.usb_boot =  USB_INT_USBBoot();

//	g_PW_Dcl_Handle = DclPMU_Open(DCL_PW, FLAGS_NONE);
//	DclPW_Control(g_PW_Dcl_Handle, PW_CMD_IS_USB_BOOT,(DCL_CTRL_DATA_T *)&CtrlVal);
//	g_UsbMode.usb_boot = (kal_bool)CtrlVal.val;

	USB_Get_Current_Table();

	if (gUsbDevice.get_chr_current_list.pCurrentList == NULL) // no PMU current table
	{
		temp_current[0] = 9900;
		temp_current[1] = 50000;
		temp_current[2] = 60000;		
				
		gUsbDevice.get_chr_current_list.pCurrentList = (DCL_UINT32 *)temp_current;
	}

//	pmu_handle = DclPMU_Open(DCL_PMU, FLAGS_NONE);
//	DclPMU_Control(pmu_handle, CHR_GET_CHR_CURRENT_LIST, (DCL_CTRL_DATA_T *)&gUsbDevice.get_chr_current_list);
//	DclPMU_Close(pmu_handle);

	for (conf_no = 0; conf_no < (USB_DEVDSC_CONFIGS); conf_no++)
	{
		set_chr_current.current = (PMU_CHR_CURRENT_ENUM)gUsbDevice.get_chr_current_list.pCurrentList[conf_no];
	//		temp_current = (kal_uint32)set_chr_current.current; // fron min to max
	
		gUsbDevice.current_table_index = conf_no;
		
		if ((kal_uint32)set_chr_current.current > 50000)
			break;
		
		temp_power[conf_no] = (kal_uint8) ((kal_uint32)set_chr_current.current/200); // ex: 500	--> set value= 255
		drv_trace1(TRACE_FUNC, (kal_uint32)USB_CURRENT_TABLE,(PMU_CHR_CURRENT_ENUM)set_chr_current.current);
	} 
		

	for (temp_index = 0; temp_index < gUsbDevice.current_table_index; temp_index++)
	{
		gUsbDevice.multi_Max_Power[gUsbDevice.current_table_index - (temp_index+1)] = temp_power[temp_index];  // save current from max to min
	} 

	if (gUsbDevice.multi_Max_Power[0] > USB_CFGDSC_MAXPOWER)
		ASSERT(0);
//		EXT_ASSERT(0,(kal_uint32)gUsbDevice.multi_Max_Power[0],USB_CFGDSC_MAXPOWER,0);

	gUsbDevice.multi_Max_Power[USB_DEVDSC_CONFIGS-1] = 0;   /* The last item must be 0 */


//	gUsbDevice.multi_Max_Power[0] = temp_power[gUsbDevice.current_table_index-1];  // save current from max to min


	

	USB_Register_USB_HISR(USB_EINT_HISR);

/* Register HISR, not active, ensure we have enough memory space  */
#ifdef __OTG_ENABLE__
	DclOTG_DRV_Control(g_OTG_Dcl_Handle, OTG_DRV_CMD_DRV_CREATE_ISR, NULL);
//	OTG_Drv_Create_ISR();
	DclOTG_DRV_Control(g_OTG_Dcl_Handle, OTG_DRV_CMD_DMA_DRV_CREATE_ISR, NULL);
//	OTGDMA_Drv_Create_ISR();
#else
//	USB_Drv_Create_ISR();
	DclUSB_DRV_Control(g_USB_Dcl_Handle, USB_DRV_CMD_DRV_CREATE_ISR, NULL);
//	USBDMA_Drv_Create_ISR();
	DclUSB_DRV_Control(g_USB_Dcl_Handle, USB_DRV_CMD_DMA_DRV_CREATE_ISR, NULL);
#endif

#ifdef __IC_USB_ENABLE__
	IC_USB_Drv_Create_ISR();
	IC_USBDMA_Drv_Create_ISR();
#endif

#ifdef __DSPIRDBG__
	#ifdef __USB_SW_LOGGING_WITH_ISR__
	USB_LOGGING_DSP_Drv_Create_ISR();
	#endif
#endif

#if defined(__IC_USB_ENABLE__) ||defined(__OTG_ENABLE__) 
	for (index2 = 0; index2< USB_IP_NUM; index2++)
	{
		if (index2 < USB_EXT_IP_NUM)
			USBD_Register_Port_Info(index2, KAL_TRUE); // USB normal  port
		else
			USBD_Register_Port_Info(index2, KAL_FALSE); // IC USB port
			
		USBD_Init_Status(index2);
	}
#endif
	
#if defined(__SIM_PLUS__)
	/* Check SIM PLUS card exist or not in NVRAM column 4 */
	nvram_external_read_data(NVRAM_EF_SYS_CACHE_OCTET_LID,
		NVRAM_SYS_SIM_PLUS_SETTING, nvram_buffer, NVRAM_EF_SYS_CACHE_OCTET_SIZE);

	g_usb_ms_simplus_exist = nvram_buffer[0];
#endif

#if defined(__MTP_ENABLE__)&&defined(__USB_MASS_STORAGE_ENABLE__)
	/* Check USB boot mode in NVRAM */
	nvram_external_read_data(NVRAM_EF_SYS_CACHE_OCTET_LID,
		NVRAM_SYS_USB_BOOT_MODE, nvram_buffer, NVRAM_EF_SYS_CACHE_OCTET_SIZE);

	if(nvram_buffer[0] == 0)
		g_UsbMode.b_usb_boot_with_ms = KAL_TRUE;
	else
		g_UsbMode.b_usb_boot_with_ms = KAL_FALSE;
#endif

#if 0// Revise boot mode.
#if defined(__DM_LAWMO_SUPPORT__)
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

#ifdef __USB_MASS_STORAGE_ENABLE__
	custom_usb_ms_init();
#endif

	if(g_UsbMode.usb_boot == KAL_FALSE)
	{
#ifndef __MEUT__
#ifndef __USB_BOOT_NOT_CHECK_NVRAM_SETTING__
		/* Check engineering mode com port setting */
		nvram_get_tst(&port_num1, &baudrate);
		nvram_get_ps(&port_num2, &baudrate);
		nvram_get_tst_l1(&port_num3, &baudrate);
		nvram_get_tst_dsp(&port_num4, &baudrate);

#if defined(__DUAL_TALK_MODEM_SUPPORT__)
#if defined(__USB_MULTIPLE_COMPORT_SUPPORT__)
	 g_UsbMode.usb_comport_boot = USB_BOOT_TWO_PORT;
   #else
	 g_UsbMode.usb_comport_boot = USB_BOOT_ONE_PORT;   
   #endif
#elif defined(__SLT_MD_CATCHER_LOG_VIA_USB__)   
 	 g_UsbMode.usb_comport_boot = USB_BOOT_ONE_PORT;     
#else
#if defined(__USB_MULTIPLE_COMPORT_SUPPORT__)
		/* Check for USB port 1 */
		if(((UART_PORT)port_num1 == uart_port_usb)||((UART_PORT)port_num2 == uart_port_usb)||((UART_PORT)port_num3 == uart_port_usb)||((UART_PORT)port_num4 == uart_port_usb))
		{
			g_UsbMode.usb_comport_boot = USB_BOOT_ONE_PORT;
			g_UsbMode.com_port_num ++;
		}

		/* Check for USB port 2 */
		if(((UART_PORT)port_num1 == uart_port_usb2)||((UART_PORT)port_num2 == uart_port_usb2)||((UART_PORT)port_num3 == uart_port_usb2)||((UART_PORT)port_num4 == uart_port_usb2))
		{
			g_UsbMode.usb_comport_boot = USB_BOOT_TWO_PORT;
			g_UsbMode.com_port_num ++;
		}

		#if defined(__USB_MODEM_CARD_SUPPORT__)
		/* Check for USB port 3 */
		if(((UART_PORT)port_num1 == uart_port_usb3)||((UART_PORT)port_num3 == uart_port_usb3))
		{
			g_UsbMode.usb_comport_boot = USB_BOOT_THREE_PORT;
			g_UsbMode.com_port_num ++;
		}
		/* Check for USB port 4 */
		if(((UART_PORT)port_num1 == uart_port_usb4)||((UART_PORT)port_num3 == uart_port_usb4))
		{
			g_UsbMode.usb_comport_boot = USB_BOOT_FOUR_PORT;
			g_UsbMode.com_port_num ++;
		}
		/* Check for USB port 5 */
		if(((UART_PORT)port_num1 == uart_port_usb5)||((UART_PORT)port_num3 == uart_port_usb5))
		{
			g_UsbMode.usb_comport_boot = USB_BOOT_FIVE_PORT;
			g_UsbMode.com_port_num ++;
		}
		
		//MT6280 Force 5VOCM
		g_UsbMode.usb_comport_boot = USB_BOOT_FIVE_PORT;
		#endif
#else
		if(((UART_PORT)port_num1 == uart_port_usb)||((UART_PORT)port_num2 == uart_port_usb)||((UART_PORT)port_num3 == uart_port_usb)||((UART_PORT)port_num4 == uart_port_usb))
			g_UsbMode.usb_comport_boot = USB_BOOT_ONE_PORT;
#endif
#endif

#ifdef  __USB_LOGGING__
	#if !defined(__USB_MODEM_CARD_SUPPORT__)
	#ifdef __DSPIRDBG__
		if(g_usb_logging_mode == (kal_uint8)EM_USB_LOGGING_IRDBG)
		{
			g_usb_logging_port_num++;
			g_UsbMode.usb_comport_boot++;
			g_UsbMode.com_port_num ++;
		}
	#endif

	#ifdef __MODEM_3G_LOGGING__
		if(g_usb_logging_mode == (kal_uint8)EM_USB_LOGGING_3G_LOGGING)
		{
			g_usb_logging_port_num++;
			g_UsbMode.usb_comport_boot++;
			g_UsbMode.com_port_num ++;
		}
	#endif

		for (index = 0; index< uart_max_port ; index++)
			USB_IS_LOGGING_PORT[index] = KAL_FALSE;

		if(g_usb_logging_port_num == 1)
		{
			if(g_UsbMode.usb_comport_boot == USB_BOOT_ONE_PORT)
			{
				USB_IS_LOGGING_PORT[uart_port_usb] = KAL_TRUE;
			}
	#if defined(__USB_MULTIPLE_COMPORT_SUPPORT__)
			else if(g_UsbMode.usb_comport_boot == USB_BOOT_TWO_PORT)
			{
				USB_IS_LOGGING_PORT[uart_port_usb2] = KAL_TRUE;
			}
			else if(g_UsbMode.usb_comport_boot == USB_BOOT_THREE_PORT)
			{
				USB_IS_LOGGING_PORT[uart_port_usb3] = KAL_TRUE;
			}
	#endif
			else
			{
				ASSERT(0);
			}
		}
	#else
		#ifdef __DSPIRDBG__
		if(g_usb_logging_mode == (kal_uint8)EM_USB_LOGGING_IRDBG)
		{
			g_usb_logging_port_num++;
		}
		#endif

		#ifdef __MODEM_3G_LOGGING__
		if(g_usb_logging_mode == (kal_uint8)EM_USB_LOGGING_3G_LOGGING)
		{
			g_usb_logging_port_num++;
		}
		#endif

			USB_IS_LOGGING_PORT[uart_port_usb5] = KAL_TRUE;
	#endif

		/* 76 supports 3 MTK com ports at most */
		if((g_UsbMode.usb_comport_boot > MAX_USB_PORT_NUM)||(g_usb_logging_port_num > 1))
			ASSERT(0);
		

#endif //__USB_LOGGING__


// USB Pop up menu flag

		g_UsbMode.usb_menu_en = KAL_FALSE;// old flow (if EM has already set USB Port, should not pop up)

#ifdef __USB_TETHERING__
		DclUSB_DRV_Control(g_USB_Dcl_Handle, USB_DRV_CMD_GET_MENU_CONFIG, (DCL_CTRL_DATA_T *)&dcl_data);

		if ((kal_bool)dcl_data == KAL_TRUE)	
			g_UsbMode.usb_menu_en = KAL_TRUE;
#endif

#if defined(__COMPOSITE_WEBCAM__)||defined(__USB_DATA_CONNECTION__)
		g_UsbMode.usb_menu_en = KAL_TRUE;// old flow (if EM has already set USB Port, should not pop up)
#endif

// for current solution : will not pop up if EM setting already used all USB resource
#if !defined(__USB_DATA_CONNECTION__)
//Data connection is a feature with CD-ROM auto-install
//No use any port.
		if(g_UsbMode.com_port_num >1) //DSP Logging port + TST port --> cannot choose COM Port (USB HW resource limitation)
			g_UsbMode.usb_menu_en = KAL_FALSE;
#endif

// for further solution: EM should add API to check pop up menu or not.		


#endif  /* __USB_BOOT_NOT_CHECK_NVRAM_SETTING__ */
#endif /* __MEUT__ */
	}
	else
	{
		
		USB_Free_Memory();

#if defined(__IC_USB_ENABLE__)	// ICUSB should support MS function -> usb task
		IC_USB_PDNmode(KAL_FALSE);
		IC_USB_VSIM_Power_On(0);// power on Vsim
		IC_USB_POWER_ON(0,KAL_FALSE);// iccd index QQ test
#endif
#if 0// Revise boot mode.	
/* under construction !*/
/* under construction !*/
	#ifdef __USB_MASS_STORAGE_ENABLE__
		#ifdef __P_PROPRIETARY_COPYRIGHT__
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
		#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
		#ifdef __P_PROPRIETARY_COPYRIGHT__
/* under construction !*/
/* under construction !*/
		#endif
	#else
/* under construction !*/
	#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
	#ifdef __MTP_ENABLE__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
	#else
/* under construction !*/
	#endif
/* under construction !*/
#endif		
	}

	/* Get customize parameters */
	gUsbDevice.device_param = USB_GetCustomFunc()->get_device_param_func();
#ifdef __USB_MASS_STORAGE_ENABLE__
	g_UsbMS.ms_param = USB_GetCustomFunc()->get_ms_param_func();
#endif
#ifdef __USB_COM_PORT_ENABLE__
	g_UsbACM_Comm.acm_param = USB_GetCustomFunc()->get_acm_param_func();
#endif
#ifdef WEBCAM_SUPPORT
	g_USBVideo.custom_param = USB_GetCustomFunc()->get_video_param_func();

	DclUSB_DRV_RegisterCallback(g_USB_Dcl_Handle,EVENT_NULL,USB_VIDEO_CLASS_CODE,(void *)&USB_Video_Driver);

	for(index = 0; index < (kal_uint32)USBVIDEO_VIDEO_SIZE_MAX; index++)
	{
		g_USBVideo.video_control.default_jpeg_max_size[index] = 0;
		g_USBVideo.video_control.b_set_default_jpeg_max_size[index] = KAL_FALSE;
	}
#endif
#ifdef  PICTBRIDGE_SUPPORT
	g_USBImage.image_param = USB_GetCustomFunc()->get_image_param_func();
#endif
#ifdef __MTP_ENABLE__
	g_USBImage.mtp_image_param = USB_GetCustomFunc()->get_mtp_image_param_func();
	DclUSB_DRV_RegisterCallback(g_USB_Dcl_Handle,EVENT_NULL,USB_IMAGE_CLASS_CODE,(void *)&USB_Image_Driver);
#endif




	return KAL_TRUE;
}


/*************************************************************************
* FUNCTION
*	usb_task_reset
*
* DESCRIPTION
*	This function implements xyz's reset handler
*
* PARAMETERS
*	task_index	-	task's index
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
static kal_bool usb_task_reset(void)
{
  	/* Do task's reset here.
	 * Notice that: shouldn't execute modules reset handler since
	 * stack_task_reset() will do. */
	return KAL_TRUE;
}


/*************************************************************************
* FUNCTION
*	usb_task_main
*
* DESCRIPTION
*	This function implements xyz task's entry function
*
* PARAMETERS
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/
static void usb_task_main( task_entry_struct * task_entry_ptr )
{
#if defined(IC_MODULE_TEST) && !defined(__SLT_MD_CATCHER_LOG_VIA_USB__)
	ilm_struct current_ilm;
	volatile kal_uint32 id;


	DclUSB_DRV_Control(g_USB_Dcl_Handle, USB_DRV_CMD_INITIALIZE_DRV_PHASE_1, NULL);
//	USB_Initialize_Drv_Phase1();

	while(1)
	{
		msg_receive_extq(&current_ilm);
		id = current_ilm.msg_id;
		destroy_ilm(&current_ilm);
	}
#else /* IC_MODULE_TEST */
	ilm_struct current_ilm;
//	kal_uint32 my_index;
	drvuem_usbcfg_req_struct *usbcfg;
#ifdef __MTP_ENABLE__
	usb_mtp_enable_rsp_struct *usb_mtp_rsp;
#endif
#if defined(__OTG_ENABLE__)||defined(__IC_USB_ENABLE__)
	usb_host_usbattach_ind_struct *usb_host_attach;
#endif
#if defined(__OTG_ENABLE__)&&defined(__CHARGER_USB_DETECT_WIHT_ONE_EINT__)
	DCL_BOOL dcl_data;
#endif
#if defined(__OTG_ENABLE__)
	OTG_DRV_CTRL_GET_PLUG_TYPE_T  dcl_plug_type;
	OTG_PLUG_TYPE plug_type;
#endif

#ifdef __USB_TETHERING__
//	ilm_struct *ilm = NULL;
	rndis_usb_config_cnf_struct  *result; 
#endif


	/* add for usb charging */
//	ilm_struct *ilm_charge = NULL;
//	bmt_usb_ind_struct *ind;


	DCL_STATUS  dcl_status;

	/* For adding module id */
//	my_index = kal_get_current_task_index();//  kal_get_my_task_index(&my_index);
	kal_set_active_module_id(MOD_USB);

	USB_Set_Device_Type(USB_UNKOWN);
	/* set external interrupt polarity and register it */
	g_usb_cable_state = gUsbDevice.device_param->cable_plugin_level;

#ifdef __OTG_ENABLE__
//	if ((USBDL_Is_USB_Download_Mode() == KAL_FALSE)&&(INT_IsBootForUSBAT() == KAL_FALSE))
//		OTG_VBusEnable(KAL_FALSE);  //session bit will cause disconnect

#ifdef __CHARGER_USB_DETECT_WIHT_ONE_EINT__
	dcl_data = DCL_FALSE;
	DclOTG_DRV_Control(g_OTG_Dcl_Handle, OTG_DRV_CMD_HOST_SET_VBUS_HIGH, (DCL_CTRL_DATA_T *)&dcl_data);
//	OTG_Host_Set_VBUS_high(KAL_FALSE);
#endif

	/* Set plug type as B, and enable ID pin detect */
	DclOTG_DRV_Control(g_OTG_Dcl_Handle, OTG_DRV_CMD_INIT_A_PLUG_DETECT, NULL);
//	OTG_Init_A_Plug_Detect();
#endif /* __OTG_ENABLE__ */

	USB_Init_Mode();

#ifndef __MEUT__

	if(INT_IsBootForUSBAT() == KAL_FALSE)
	{
		if(USBDL_Mode_Type()!= USBDL_MODE_USB_DOWNLOAD)//(USBDL_Is_USB_Download_Mode() == KAL_FALSE)
		{
			dcl_status = DclUSB_DRV_Control(g_USB_Dcl_Handle, USB_DRV_CMD_CHECK_IC_UART_SHARE_PAD_CAPABILITY, NULL);

			if(dcl_status == STATUS_OK)
			{
				/* OK means this IC has USB/UART share pad function */
				if(INT_BootMode() != MTK_FACTORY_MODE)
				{
					/* We need to make sure that we are not in UART META mode, otherwise, we may switch the path from UART to USB after init function */
					DclUSB_DRV_Control(g_USB_Dcl_Handle, USB_DRV_CMD_INITIALIZE_DRV_PHASE_1, NULL);
//					USB_Initialize_Drv_Phase1();  //USB current consumption will cause disconnect
				}
			}
			else
			{
				DclUSB_DRV_Control(g_USB_Dcl_Handle, USB_DRV_CMD_INITIALIZE_DRV_PHASE_1, NULL);
//				USB_Initialize_Drv_Phase1();  //USB current consumption will cause disconnect
			}
		}
	}


	if(INT_BootMode() != MTK_FACTORY_MODE)
	{
		//need to apply PMU HAL, but PMU isn't ready now.
		//pmic_adpt_reg_usb_int(g_usb_cable_state, USB_EINT_HISR);
	}

#endif /* __MEUT__ */

	/* Request for unique string to construct serial string */
//	if(g_UsbMode.usb_boot == KAL_FALSE)  // Revise boot mode.
	{
		USB_Send_Msg(USB_SEND_MSG_READ_UNIQUE_STRING);
	}

	dcl_status = DclUSB_DRV_Control(g_USB_Dcl_Handle, USB_DRV_CMD_CHECK_IC_DMA_LIMIT_CAPABILITY, NULL);

	if(dcl_status == STATUS_OK)
	{
		/* OK means we need to limit DMa burst mode */
		USB_Set_DMA_Burst_Mode(DMA_MODE_INC4);
	}
	else
	{
		USB_Set_DMA_Burst_Mode(DMA_MODE_INC16);
	}

#ifdef DRV_USB_FORCE_TRIGGER_ONE_EINT
	#ifndef __MEUT__
	/* This is used to bypass PMU VBUS detection. Force trigger EINT if the load didn't support PMU */
	if(INT_BootMode() != MTK_FACTORY_MODE)
	#endif
	{
		kal_sleep_task(20); //EINT debounce time
		USB_EINT_HISR();
	}
#endif

	while(1)
	{
		msg_receive_extq(&current_ilm);

		switch(current_ilm.msg_id)
		{
		case MSG_ID_USB_FT_START_REQ:
			g_UsbMode.mode_param |= 1<<(kal_uint32)USB_MODE_FT_START_DONE;
	#ifdef __OTG_ENABLE__
			OTG_Mode_Selection();
	#else
			USB_Mode_Selection();
	#endif
			break;

		case MSG_ID_NVRAM_READ_CNF:
			g_UsbMode.mode_param |= 1<<(kal_uint32)USB_MODE_NVRAM_READ_DONE;
			/* store the string value got from NVRAM */
			USB_Store_Serial_Value(&current_ilm); /* store in gUsbDevice.serial_string   */

// Normal flow:  NVRAM_Read_CNF + Cable IN
// if Cable IN + Cable OUT + NVRAM_Read_CNF
			if((g_UsbMode.cable_type == USB_MODE_CABLE_PLUGOUT) && (g_UsbMode.previous_cable_type != USB_MODE_CABLE_PLUGOUT))
				break;  //Cable plug out, Not initial state(g_UsbMode.cable_type =g_UsbMode.previous_cable_type = USB_MODE_CABLE_PLUGOUT)
			else   /* 1. Cable In + NVRAM_Done   2. NVRAM_Done + Cable In */
			{
	#ifdef __OTG_ENABLE__
				OTG_Mode_Selection();
	#else
				USB_Mode_Selection();
	#endif
				break;
			}

		case MSG_ID_BMT_USB_READ_CALI_DONE_IND:
			g_UsbMode.mode_param |= 1<<(kal_uint32)USB_MODE_BMT_READ_DONE;

	#ifdef __OTG_ENABLE__
			OTG_Mode_Selection();
	#else
			USB_Mode_Selection();
	#endif
			break;

	#ifdef __OTG_ENABLE__
		case MSG_ID_USB_A_PLUGIN_IND:
			
			if (g_UsbMode.cable_type == USB_MODE_CABLE_ERROR)  
			{	
				g_UsbMode.cable_type = USB_MODE_CABLE_PLUGOUT;
				break;
			}
				
			if (g_UsbMode.usb_boot == KAL_FALSE)
			{	
				DclOTG_DRV_Control(g_OTG_Dcl_Handle, OTG_DRV_CMD_GET_PLUG_TYPE, (DCL_CTRL_DATA_T  *)&dcl_plug_type);
				plug_type = (OTG_PLUG_TYPE)dcl_plug_type.type;
	
	//			if(OTG_Get_Plug_Type() == OTG_PLUG_A)
				if(plug_type == OTG_PLUG_A)
				{
					if(g_UsbMode.cable_type == USB_MODE_CABLE_PLUGOUT)
					{
						g_UsbMode.previous_cable_type = USB_MODE_CABLE_PLUGOUT;
						g_UsbMode.cable_type = USB_MODE_CABLE_A_PLUGIN;
						OTG_Mode_Selection();
					}
					else if (g_UsbMode.cable_type == USB_MODE_CABLE_B_PLUGIN)
					{
						/* B EINT does not come yet */
						g_UsbMode.previous_cable_type = USB_MODE_CABLE_B_PLUGIN;
						g_UsbMode.cable_type = USB_MODE_CABLE_A_PLUGIN;
					}
				}
				else
				{
						OTG_Display_Message(OTG_DISPLAY_MSG_UN_SUPPORT_CABLE);
						g_UsbMode.cable_type = USB_MODE_CABLE_PLUGOUT;
//						ASSERT(0);
				}
			}
			break;

		case MSG_ID_USB_A_PLUGOUT_IND:
			if((g_UsbMode.cable_type == USB_MODE_CABLE_A_PLUGIN)||(g_UsbMode.cable_type == USB_MODE_CABLE_ERROR)&&(g_UsbMode.usb_boot == KAL_FALSE))
			{
				g_UsbMode.previous_cable_type = USB_MODE_CABLE_A_PLUGIN;
				g_UsbMode.cable_type = USB_MODE_CABLE_PLUGOUT;
				OTG_Mode_Selection();
			}
			break;
	#endif /* __OTG_ENABLE__ */

		case MSG_ID_USB_B_PLUGIN_IND:

//EM setting  flag (further plan)

#ifdef  __USB_COMPLIANCE_CHARGE__
			USB_Send_Msg(USB_SEND_BMT_STOP_CHARGE);
			drv_trace0(TRACE_FUNC, (kal_uint32)USB_TEST_LOAD);

//			ind = (bmt_usb_ind_struct*)construct_local_para(sizeof(bmt_usb_ind_struct), TD_CTRL);				
//			ind->usb_ind = PMU_CHARGE_CURRENT_0_00_MA;
//			USB_Send_Msg_Ext_Queue(ilm_charge,MOD_BMT, MSG_ID_BMT_USB_IND, ind);			
#else
	// drag 500 mA current
			if (USB_Default_Charging() == KAL_TRUE) // force USB charging 
			{
				USB_Send_Msg(USB_SEND_BMT_CHARGE_MAX);
//				ind = (bmt_usb_ind_struct*)construct_local_para(sizeof(bmt_usb_ind_struct), TD_CTRL);				
//				ind->usb_ind = (PMU_CHR_CURRENT_ENUM)gUsbDevice.get_chr_current_list.pCurrentList[gUsbDevice.current_table_index - 1];				
//				USB_Send_Msg_Ext_Queue(ilm_charge,MOD_BMT, MSG_ID_BMT_USB_IND, ind);				
			}
			else		
			{
	// drag min current or do not drag current
				if ((kal_uint32)gUsbDevice.get_chr_current_list.pCurrentList[0] < 10100)
				{
					USB_Send_Msg(USB_SEND_BMT_CHARGE_MIN);
//					ind = (bmt_usb_ind_struct*)construct_local_para(sizeof(bmt_usb_ind_struct), TD_CTRL);
//					ind->usb_ind = (PMU_CHR_CURRENT_ENUM)gUsbDevice.get_chr_current_list.pCurrentList[0];
//					USB_Send_Msg_Ext_Queue(ilm_charge, MOD_BMT, MSG_ID_BMT_USB_IND, ind);
				}	
			}
#endif

			USB_Set_Device_State(DEVSTATE_DEFAULT);

	#ifdef __OTG_ENABLE__
			DclOTG_DRV_Control(g_OTG_Dcl_Handle, OTG_DRV_CMD_GET_PLUG_TYPE, (DCL_CTRL_DATA_T  *)&dcl_plug_type);
			plug_type = (OTG_PLUG_TYPE)dcl_plug_type.type;

					// plug in A to A cable
					// detect A first --> detect B
			if (g_UsbMode.cable_type == USB_MODE_CABLE_ERROR)  
			{
				OTG_Display_Message(OTG_DISPLAY_MSG_UN_SUPPORT_CABLE);
//				g_UsbMode.cable_type = USB_MODE_CABLE_PLUGOUT;
				break;
			}	
				
//			if((OTG_Get_Plug_Type() == OTG_PLUG_B)&&(g_UsbMode.cable_type == USB_MODE_CABLE_PLUGOUT))
			if((plug_type == OTG_PLUG_B)&&(g_UsbMode.cable_type == USB_MODE_CABLE_PLUGOUT))
			{
				g_UsbMode.previous_cable_type = USB_MODE_CABLE_PLUGOUT;
				g_UsbMode.cable_type = USB_MODE_CABLE_B_PLUGIN;

				/* Configure USB as CDC ACM here */
				OTG_Mode_Selection();
//				gUsbDevice.usb_cable_in = KAL_TRUE;
			}
	#else  /* __OTG_ENABLE__ */

			if(g_UsbMode.cable_type == USB_MODE_CABLE_PLUGOUT)
			{
				g_UsbMode.previous_cable_type = USB_MODE_CABLE_PLUGOUT;
				g_UsbMode.cable_type = USB_MODE_CABLE_B_PLUGIN;

				/* Configure USB as CDC ACM at plug in message if this flag are not normal */
				if((g_UsbMode.usb_comport_boot == USB_NORMAL_BOOT)||(g_UsbMode.usb_menu_en == KAL_TRUE))
				{
					USB_Mode_Selection();
				}
				else if((g_UsbMode.usb_comport_boot == USB_BOOT_ONE_PORT)&&(g_UsbMode.usb_menu_en == KAL_FALSE))
				{
//			#ifdef __USB_LOGGING__
//					if(g_usb_boot_as_logging_tool == KAL_TRUE)
//					{
//						USB_Config_Type(USB_CDC_ACM_LOGGING, KAL_TRUE, NULL);
//					}
//					else
//			#endif
					{
						if (INT_IsBootForUSBAT() == KAL_TRUE)
						{
							USB_Mode_Selection();
						}
						else
						{
							USB_Config_Type(USB_CDC_ACM, KAL_TRUE, NULL);
						}
					}
				}
		#if defined(__USB_MULTIPLE_COMPORT_SUPPORT__)
				else if((g_UsbMode.usb_comport_boot >= USB_BOOT_TWO_PORT)&&(g_UsbMode.usb_menu_en == KAL_FALSE))
				{
				#if defined(__USB_MODEM_CARD_SUPPORT__)
					#ifndef __MEUT__
					#ifdef __MBIM_SUPPORT__					
					if(((custom_em_get_usb_cdrom_config() & 0x02) == 0x02)) //Return : 0 no morphing ; 1 for morphing
					{
						USB_Config_Type(USB_MORPHING_MBIM, KAL_TRUE, NULL);								
					}
					else 
					#endif
					if (((custom_em_get_usb_cdrom_config() & 0x01) == 0x00)) //Return¡G 0 for CD-ROM¡A1 for COM port
					{
						USB_Config_Type(USB_MASS_STORAGE_CDROM_ONLY, KAL_TRUE, NULL);
					}
					else
					#endif /*__MEUT__*/
					USB_Mode_Switch(USB_COMPOSITE_DEVICES);
				#else
					USB_Config_Type(USB_COMPOSITE_MULTI_COM, KAL_TRUE, NULL);
				#endif
				}
		#endif

//				gUsbDevice.usb_cable_in = KAL_TRUE;
			}
	#endif /* __OTG_ENABLE__ */
			break;

		case MSG_ID_USB_B_PLUGOUT_IND:
			USB_Set_Device_State(DEVSTATE_DEFAULT);

	#ifdef __OTG_ENABLE__
			if(g_UsbMode.cable_type == USB_MODE_CABLE_B_PLUGIN)
			{
				g_UsbMode.previous_cable_type = USB_MODE_CABLE_B_PLUGIN;
				g_UsbMode.cable_type = USB_MODE_CABLE_PLUGOUT;

				if (g_UsbMode.usb_boot == KAL_FALSE)
				{
					if((g_UsbMode.mode_param&(1<<(kal_uint32)USB_MODE_NVRAM_READ_DONE)) == 0)
					{
						USB_Dbg_Trace(USB_TASK_UNMASK_EINT, 1, 0);
						USB_CHR_USB_EINT_UnMask();
//						Dcl_Chr_Det_Control(g_PWIC_Dcl_Handle, CHR_DET_CMD_UNMASK_EINT, NULL); //Unmask EINT for next detection
						
						/* if usb_comport_boot > BOOT_ONE_PORT, still need to do USB_Release_Type()*/
						if (g_UsbMode.usb_comport_boot == USB_NORMAL_BOOT)	
							break;
					}
				}

		#ifdef __MTP_ENABLE__
				if(g_USBImage.b_wait_enable_rsp == KAL_TRUE)
				{
					g_USBImage.b_is_pending_disable_mtp_msg = KAL_TRUE;
//					g_USBImage.b_mtp_release_type = KAL_TRUE;
				}
				else
		#endif
				{
					OTG_B_Set_Session_Valid(KAL_FALSE);
					/* g_USBImage.b_mtp_release_type = KAL_TRUE; */
					OTG_Mode_Selection();
				}
			}
			else if(g_UsbMode.cable_type == USB_MODE_CABLE_A_PLUGIN)
			{
				/* Before B EINT, A already plug in */
				g_UsbMode.previous_cable_type = USB_MODE_CABLE_A_PLUGIN;
				g_UsbMode.cable_type = USB_MODE_CABLE_ERROR;

				if (g_UsbMode.usb_boot == KAL_FALSE)
				{
					if((g_UsbMode.mode_param&(1<<(kal_uint32)USB_MODE_NVRAM_READ_DONE)) == 0)
						break;
				}

		#ifdef __MTP_ENABLE__
				if(g_USBImage.b_wait_enable_rsp == KAL_TRUE)
				{
					g_USBImage.b_is_pending_disable_mtp_msg = KAL_TRUE;
//					g_USBImage.b_mtp_release_type = KAL_TRUE;
				}
				else
		#endif
				{
					OTG_B_Set_Session_Valid(KAL_FALSE);
					/* g_USBImage.b_mtp_release_type = KAL_TRUE; */
					OTG_Mode_Selection();
				}
			}
	#else
			if(g_UsbMode.cable_type == USB_MODE_CABLE_B_PLUGIN)
			{
				g_UsbMode.previous_cable_type = USB_MODE_CABLE_B_PLUGIN;
				g_UsbMode.cable_type = USB_MODE_CABLE_PLUGOUT;

				if (g_UsbMode.usb_boot == KAL_FALSE)
				{
					if((g_UsbMode.mode_param&(1<<(kal_uint32)USB_MODE_NVRAM_READ_DONE)) == 0)
					{
						USB_Dbg_Trace(USB_TASK_UNMASK_EINT, 1, 0);
						USB_CHR_USB_EINT_UnMask();
//						Dcl_Chr_Det_Control(g_PWIC_Dcl_Handle, CHR_DET_CMD_UNMASK_EINT, NULL); //Unmask EINT for next detection
						
						/* if usb_comport_boot > BOOT_ONE_PORT, still need to do USB_Release_Type()*/
						if (g_UsbMode.usb_comport_boot == USB_NORMAL_BOOT)	
							break;
					}
				}

		#ifdef __MTP_ENABLE__
				if(g_USBImage.b_wait_enable_rsp == KAL_TRUE)
				{
					g_USBImage.b_is_pending_disable_mtp_msg = KAL_TRUE;
//					g_USBImage.b_mtp_release_type = KAL_TRUE;
				}
				else
		#endif
				{
					/* g_USBImage.b_mtp_release_type = KAL_TRUE; */
					USB_Mode_Selection();
				}
			}
	#endif

	#if defined(__CHARGER_USB_DETECT_WIHT_ONE_EINT__)&& defined(DRV_MISC_CHR_USB_EINT_CENTRAL_UNMASK)
		#ifdef __MTP_ENABLE__
			if((g_USBImage.b_mtp_release_type == KAL_FALSE)&&(g_USBImage.b_wait_enable_rsp == KAL_FALSE))
			{
				USB_Dbg_Trace(USB_TASK_UNMASK_EINT, 1, 0);
				USB_CHR_USB_EINT_UnMask();
//				Dcl_Chr_Det_Control(g_PWIC_Dcl_Handle, CHR_DET_CMD_UNMASK_EINT, NULL); //Unmask EINT for next detection
			}
		#else
			USB_Dbg_Trace(USB_TASK_UNMASK_EINT, 1, 0);
			USB_CHR_USB_EINT_UnMask();
//			Dcl_Chr_Det_Control(g_PWIC_Dcl_Handle, CHR_DET_CMD_UNMASK_EINT, NULL); //Unmask EINT for next detection
		#endif
	#endif
			break;

		case MSG_ID_DRVUEM_USBCFG_REQ:
			USB_Dbg_Trace(USB_USBCFG_REQ, 0, 0);
			usbcfg = (drvuem_usbcfg_req_struct *)current_ilm.local_para_ptr;

	#if defined(__OTG_ENABLE__)||defined(__MTP_ENABLE__)||defined(__USB_TETHERING__)
	  			if(usb_srp_flag == KAL_TRUE)
		  	{
			  	usb_srp_flag = KAL_FALSE;
			}
	  		else
	  		{
	  			if(usb_config_flag == KAL_TRUE)
	  				ASSERT(0);
	  		}

	  		usb_config_flag = KAL_TRUE;
	#endif

			//if ((g_UsbMode.com_port_num > 1)&&(usbcfg->mode != USB_COMPOSITE_MULTI_COM))
			if ((g_UsbMode.com_port_num > 1)&&(usbcfg->mode != USB_COMPOSITE_MULTI_COM)&&(usbcfg->mode != USB_COMPOSITE_DEVICES))
			{
				// EM set as multi com but doesn't  choose COM Port  function  --> HW resource limitation
				USB_Send_Config_Cnf_Msg(usbcfg->mode, KAL_FALSE);                                    

				/* Cable plug In */
				if((g_UsbMode.cable_type == USB_MODE_CABLE_B_PLUGIN) && (g_UsbMode.previous_cable_type != USB_MODE_CABLE_B_PLUGIN)
					 && (USB_Get_Device_Type() == USB_UNKOWN))
				{
					USB_Set_Device_Type(USB_CANNOT_CONFIG);
				}
			}
			else  // composite function (ex: Webcam+ COM)(multi COM)  or single function (ex: MTP) 
			{

	#ifdef __MTP_ENABLE__
	  			if(usbcfg->mode == USB_IMAGE_MTP)
	  			{
		  			if(g_UsbMode.cable_type != USB_MODE_CABLE_PLUGOUT)
		  			{
			  			/* 32KB buffer */
			  			//g_USBImage.mtp_image_buffer = (USB_IMAGE_MTP_BUFFER *)usbcfg->parameter;
			  			if(g_USBImage.mtp_image_buffer == NULL)
			  				g_USBImage.mtp_image_buffer = (USB_IMAGE_MTP_BUFFER *)USB_Get_Memory(USBMS_MAX_BUFFERSIZE);//(USB_IMAGE_MTP_BUFFER *)USB_TEST_Buffer;
	  
			  			if(g_USBImage.b_wait_disable_rsp == KAL_TRUE)
		  				{
		  					ASSERT(0);
			  			}
			  			else
			  			{
			  				/* Send MTP enable msg to MTP task */
			  				USB_MTP_Image_Send_Msg(USB_MTP_IMAGE_MSG_ENABLE_REQ);
			  			}
			  		}
			  		else
			  		{
			  			USB_Send_Config_Cnf_Msg(USB_IMAGE_MTP, KAL_FALSE);
			  		}
			  	}
			  	else if(usbcfg->mode == USB_STOP_MTP)
			  	{
			  		if((g_USBImage.b_wait_enable_rsp == KAL_TRUE)&&(g_UsbMode.usb_boot == KAL_TRUE))
			  			g_USBImage.b_delay_mtp_stop_config = KAL_TRUE;
			  		else
			  			USB_Config_Req_Hdlr(usbcfg->mode, usbcfg->parameter);
		  		}
		  		else
		  		{
		  			USB_Config_Req_Hdlr(usbcfg->mode, usbcfg->parameter);
		  		}
	#else /* __MTP_ENABLE__ */
	  			USB_Config_Req_Hdlr(usbcfg->mode, usbcfg->parameter);
	#endif
			}

			break;

#ifdef __OTG_ENABLE__
		case MSG_ID_OTG_HDLR_IND:
			{
				otg_hdlr_ind_struct *hdlr_ind = (otg_hdlr_ind_struct *)current_ilm.local_para_ptr;
				OTG_Hdlr_Select(hdlr_ind->type, hdlr_ind->parameter);
			}
			break;

		case MSG_ID_USBD_START_HNP:
	#ifdef __OTG_SRP_HNP_APP_FIXED__
			OTG_Config_HNP(USB_MASS_STORAGE, NULL);
	#else

			/* Configure USB as CDC ACM at plug in message if this flag are not normal */
			if((g_UsbMode.usb_comport_boot == USB_NORMAL_BOOT)||(g_UsbMode.usb_menu_en == KAL_TRUE))
			{
				g_UsbMode.b_start_hnp = KAL_TRUE;

				/* Notify UEM */
				USB_Send_Msg(USB_SEND_MSG_PLUG_IN);
			}
			else if((g_UsbMode.usb_comport_boot == USB_BOOT_ONE_PORT)&&(g_UsbMode.usb_menu_en == KAL_FALSE))
			{
//		#ifdef __USB_LOGGING__
//				if(g_usb_boot_as_logging_tool == KAL_TRUE)
//					OTG_Config_HNP(USB_CDC_ACM_LOGGING, NULL);
//				else
//		#endif
					OTG_Config_HNP(USB_CDC_ACM, NULL);
			}
		#if defined(__USB_MULTIPLE_COMPORT_SUPPORT__)
			else if((g_UsbMode.usb_comport_boot >= USB_BOOT_TWO_PORT)&&(g_UsbMode.usb_menu_en == KAL_FALSE))
			{
				OTG_Config_HNP(USB_COMPOSITE_MULTI_COM, NULL);
			}
		#endif
	#endif /* __OTG_SRP_HNP_APP_FIXED__ */
			break;

		// Add for SRP EM test, In real case, this should check OTG status first
		case MSG_ID_SRP_INIT:
			DclOTG_DRV_Control(g_OTG_Dcl_Handle, OTG_DRV_CMD_GET_PLUG_TYPE, (DCL_CTRL_DATA_T  *)&dcl_plug_type);
			plug_type = (OTG_PLUG_TYPE)dcl_plug_type.type;

//			if(OTG_Get_Plug_Type() == OTG_PLUG_B)
			if(plug_type == OTG_PLUG_B)
			{
				OTG_DRV_CTRL_GET_STATE_T dcl_state;
				OTG_STATE  otg_state;


				DclOTG_DRV_Control(g_OTG_Dcl_Handle, OTG_DRV_CMD_GET_STATE, (DCL_CTRL_DATA_T *)&dcl_state);
				otg_state = (OTG_STATE)dcl_state.state;

				if((otg_state == OTG_STATE_START) ||(otg_state == OTG_STATE_B_IDLE))
				{
					if(g_UsbMode.b_start_srp == KAL_TRUE)
					{
						/* It means user select to start SRP in EM,
						   but he does not choose any function(MS, CDC ACM....), for example, user presses back */
			#ifndef __OTG_SRP_HNP_APP_FIXED__
						/* Notify UEM plug out first, otherwise next plug in will make MMI assert */
						USB_Send_Msg(USB_SEND_MSG_PLUG_OUT);
			#endif
					}

					/* g_UsbMode.b_start_srp = KAL_TRUE here */
					OTG_Start_SRP();

			#ifdef __OTG_SRP_HNP_APP_FIXED__
					OTG_Config_SRP(USB_MASS_STORAGE, NULL);
			#else

					/* Configure USB as CDC ACM at plug in message if this flag are not normal */
					if((g_UsbMode.usb_comport_boot == USB_NORMAL_BOOT)||(g_UsbMode.usb_menu_en == KAL_TRUE))
					{
						/* Notify UEM */
						USB_Send_Msg(USB_SEND_MSG_PLUG_IN);
					}
					else if((g_UsbMode.usb_comport_boot == USB_BOOT_ONE_PORT)&&(g_UsbMode.usb_menu_en == KAL_FALSE))
					{
//				#ifdef __USB_LOGGING__
//						if(g_usb_boot_as_logging_tool == KAL_TRUE)
//							OTG_Config_SRP(USB_CDC_ACM_LOGGING, NULL);
//						else
//				#endif
							OTG_Config_SRP(USB_CDC_ACM, NULL);
					}
				#if defined(__USB_MULTIPLE_COMPORT_SUPPORT__)
					else if((g_UsbMode.usb_comport_boot >= USB_BOOT_TWO_PORT)&&(g_UsbMode.usb_menu_en == KAL_FALSE))
					{
						OTG_Config_SRP(USB_COMPOSITE_MULTI_COM, NULL);
					}
				#endif
			#endif  /* __OTG_SRP_HNP_APP_FIXED__ */
				}
			}
			break;

		/* mass storage host messages */
		case MSG_ID_USB_MSHOST_START_IND:

#if defined(__IC_USB_ENABLE__)

			if(g_UsbMode.usb_boot == KAL_TRUE)
			{
				g_UsbMode.b_int_usb_detect = KAL_TRUE;
	#ifdef __OTG_ENABLE__
				OTG_Mode_Selection();
	#else
				USB_Mode_Selection();
	#endif
			}
#endif
			usb_host_attach = (usb_host_usbattach_ind_struct *)current_ilm.local_para_ptr;
			USB_Host_Ms_State_Start(usb_host_attach->feature_index);
			break;

		case MSG_ID_USB_MSHOST_QUERY_IND:
			usb_host_attach = (usb_host_usbattach_ind_struct *)current_ilm.local_para_ptr;			
			USB_Host_Ms_State_Main(usb_host_attach->feature_index);
			break;
			
		case MSG_ID_USB_MSHOST_CLEAR_STALL_IND:
			usb_host_attach = (usb_host_usbattach_ind_struct *)current_ilm.local_para_ptr;			
//			USB_Host_Ms_Clear_Stall(usb_host_attach->feature_index);   // QQ test
			break;

#endif  /* __OTG_ENABLE__ */

	#if defined(__OTG_ENABLE__)||defined(__IC_USB_ENABLE__)
		case MSG_ID_USB_HOST_ATTACH_IND:
			usb_host_attach = (usb_host_usbattach_ind_struct *)current_ilm.local_para_ptr;
			USBD_Attatch_Hdlr(usb_host_attach->usb_ip_port, (USB_HCD_STATUS)usb_host_attach->result, usb_host_attach->param);
			break;
	#endif

	#ifdef __USB_MASS_STORAGE_ENABLE__
		/* Mass storage client messages */
		case MSG_ID_USB_MSDRV_REC_DONE_CONF:
		case MSG_ID_USB_MSDRV_TRX_DONE_CONF:
		case MSG_ID_USB_MSDRV_CLEAR_STALL_REQ:
			/* After USB_reset HISR and before stop DMA, a DMA callbcak happen,
			this callback message may come after reset message, and make MS state machine error */
			if((USB_Get_Device_State() == DEVSTATE_CONFIG)&&(g_UsbMS.ms_is_reset == KAL_FALSE))
			{
				USB_Ms_State_Machine_Hdlr(&current_ilm);   //if USB receive reset message just after Enumeration,ignore previous message.
			}
			break;

		case MSG_ID_USB_MSDRV_RESET_IND:
			USB_Ms_State_Machine_Hdlr(&current_ilm);
			break;
	#endif


	#ifdef __USB_TETHERING__
		case MSG_ID_RNDIS_USB_CONFIG_REQ:


			/* Notify UPS USB is config */
			result = (rndis_usb_config_cnf_struct*)construct_local_para(sizeof(rndis_usb_config_cnf_struct), TD_CTRL);


			if ((g_UsbMode.usb_comport_boot == USB_BOOT_ONE_PORT)||(g_UsbMode.com_port_num >= 2))
			{
				/* Notify UPS USB is config */
				result->confirm = KAL_FALSE;
			}
			else
			{
				result->confirm = KAL_TRUE;

				if (g_UsbMode.cable_type == USB_MODE_CABLE_B_PLUGIN)
				{
					if(g_UsbMode.usb_comport_boot != USB_NORMAL_BOOT)
						USB_Config_Type(USB_COMPOSITE_RNDIS_COM, KAL_TRUE, NULL);
					else
						USB_Config_Type(USB_RNDIS, KAL_TRUE, NULL);			
				}
				else  // USB cable out
				{
					result->confirm = KAL_FALSE;
				}
			}

			USB_Send_Msg_Ext_Queue(MOD_UPS_HIGH, MSG_ID_RNDIS_USB_CONFIG_CNF, result);
			
//			DRV_BuildPrimitive(ilm, MOD_USB, MOD_UPS, MSG_ID_RNDIS_USB_CONFIG_CNF, result); 
//			msg_send_ext_queue(ilm);
//			g_UsbMode.rndis_cnf_response = KAL_FALSE;

			break;

		case MSG_ID_RNDIS_USB_DETACH_REQ:
			USB_Release_Type(KAL_TRUE, KAL_FALSE);
			USB_Send_Msg(RNDIS_USB_DETACH_CNF);		
			break;
//	MSG_ID_RNDIS_USB_DETACH_CNF,


	#endif


	#ifdef WEBCAM_SUPPORT
		/* Video class related messages */
		case MSG_ID_USB_MED_SET_CAMERA_ATTR_CNF:
		case MSG_ID_USB_ENUM_DONE:
		case MSG_ID_MED_USB_START_VIDEO_REQ:
		case MSG_ID_USB_VIDEO_COMPLETE:
		case MSG_ID_USB_VIDEO_DMA_DONE:
		case MSG_ID_USB_VIDEO_CHANGE_SIZE:
		case MSG_ID_USB_STILL_CAPTURE:
		case MSG_ID_USB_STILL_COMPLETE:
		case MSG_ID_USB_VIDEO_STILL_DMA_DONE:
		case MSG_ID_USB_VIDEO_STILL_DMA_PARTIAL:
		case MSG_ID_MED_USB_DEVICE_STILL_REQ:
		case MSG_ID_MED_USB_PAUSE_REQ:
		case MSG_ID_USB_VIDEO_INCALL_DMA_DONE:
		case MSG_ID_USB_VIDEO_INCALL_TIMEOUT:
		case MSG_ID_USB_VIDEO_INCALL_CHANGE_SIZE:
		case MSG_ID_MED_USB_RESUME_VIDEO_REQ:
			/* If device type is no longer video because of plugging out cable, still return error message to media task*/
			USBVideo_Parse_Med_Msg(&current_ilm, USB_Get_Device_Type());
			break;

		case MSG_ID_USB_VIDEO_ABORT:	/* OS sleep and then wakeup, reset USB, called at USBVideo_VS_If_Reset() */
		case MSG_ID_MED_USB_STOP_REQ:	 /*  media task want to stop webcam */

			USB_Dbg_Trace(USB_VIDEO_STOP_MSG, USB_Get_Device_Type(), 0);

			if((USB_Get_Device_Type() == USB_VIDEO)||(USB_Get_Device_Type() == USB_COMPOSITE_VIDEO_COM))
			{
		#ifdef __OTG_ENABLE__
				OTG_B_EnDis_HNP(KAL_FALSE);
		#endif
				/* Disable D+ pull high, but plug out is false */
				USB_Release_Type(KAL_TRUE, KAL_FALSE);
		#if defined(__OTG_ENABLE__)
				/* When in SRP and user chooses webcam, the MED will send stop msg, and UEM will config USB again and again */
				/* Add this flag to prevent assert */
				if(g_UsbMode.b_start_srp == KAL_TRUE)
					usb_srp_flag = KAL_TRUE;
		#endif
			}

			/* In order to return corresponding error message to media task */
			USBVideo_Parse_Med_Msg(&current_ilm, USB_Get_Device_Type());/*device type as UNKNOWN */
			break;
			
		case MSG_ID_MED_USB_DISCONNECT_REQ:  // MT call : while webcam hasn't enumerate 
			// because there will be re-connect message, so do not change video state & only need to pull down DP
			// when User select webcam, but do no double clock Webcam icon on PC side --> there is no USB Video enumeration done message
			// under this condition, MT call comes --> MED will stop webcam & want to disconnect from PC (to prevent user click webcam icon on PC :Webcam cannot do in background)			
			// when MT call end, pull up DP , re-enumeration
		#ifdef __OTG_ENABLE__
				OTG_B_EnDis_HNP(KAL_FALSE);
		#endif
			USB_Release_Type(KAL_TRUE, KAL_FALSE);
		#if defined(__OTG_ENABLE__)
				/* When in SRP and user chooses webcam, the MED will send stop msg, and UEM will config USB again and again */
				/* Add this flag to prevent assert */
			if(g_UsbMode.b_start_srp == KAL_TRUE)
				usb_srp_flag = KAL_TRUE;
		#endif
			break;
			
		case MSG_ID_MED_USB_CONNECT_REQ:  // MT call end : while webcam hasn't enumerate
			USB_Config_Type(USB_VIDEO, KAL_TRUE, NULL);
			// MED task will re-send buffer 
			USBVideo_Parse_Med_Msg(&current_ilm, USB_Get_Device_Type());			
			break;
			
	#endif /* WEBCAM_SUPPORT */

	#ifdef PICTBRIDGE_SUPPORT
		case MSG_ID_USB_PTPIMAGE_DATA_RX_DONE_CONF:
		case MSG_ID_USB_PTPIMAGE_DATA_TX_DONE_CONF:
			if((USB_Get_Device_State() == DEVSTATE_CONFIG)&&(g_USBImage.image_ep0_reset == KAL_FALSE))
			{
				USB_PTP_State_Machine_Hdlr(&current_ilm);
			}
			break;

		case MSG_ID_USB_PTPIMAGE_RESET_IND:
			USB_PTP_State_Machine_Hdlr(&current_ilm);
			break;

		case MSG_ID_MMI_USB_DPS_HREQUEST_CONF:
		case MSG_ID_MMI_USB_DPS_HRESPONSE_CONF:
		case MSG_ID_MMI_USB_DPS_DREQUEST_REQ:
		case MSG_ID_MMI_USB_DPS_DRESPONSE_REQ:
		case MSG_ID_MMI_USB_START_JOB_REQ:
		case MSG_ID_MMI_USB_CLOSE_JOB_REQ:
			if((USB_Get_Device_State() != DEVSTATE_CONFIG)||(g_USBImage.usb_image_stop == KAL_TRUE))
			{
				/* DO nothing */
			}
			else
			{
				if(USB_Get_Device_Type() == USB_IMAGE)
				{
					PTP_Parse_MMI_Meg(&current_ilm);
				}
				else
				{
					EXT_ASSERT(0, (kal_uint32)USB_Get_Device_Type(), 0, 0);
				}
			}
			break;

		case MSG_ID_MMI_USB_PTP_HOST_RESET_CNF:
			if((USB_Get_Device_Type() == USB_IMAGE)||(USB_Get_Device_Type() == USB_UNKOWN))
			{
				PTP_Parse_MMI_Meg(&current_ilm);
			}
			else
			{
				EXT_ASSERT(0, (kal_uint32)USB_Get_Device_Type(), 0, 0);
			}
			break;
	#endif /* PICTBRIDGE_SUPPORT */

	#ifdef __MTP_ENABLE__
		case MSG_ID_USB_MTP_ENABLE_RSP:
			USB_Dbg_Trace(USB_MTP_RECEIVE_ENABLE_RSP, g_USBImage.b_wait_enable_rsp, g_USBImage.b_is_pending_disable_mtp_msg);

			if(g_USBImage.b_wait_enable_rsp == KAL_FALSE)
				ASSERT(0);
			g_USBImage.b_wait_enable_rsp = KAL_FALSE;

			usb_mtp_rsp = (usb_mtp_enable_rsp_struct *)current_ilm.local_para_ptr;

			if((usb_mtp_result_enum)usb_mtp_rsp->result_code == USB_MTP_RESULT_OK)
			{
				g_USBImage.mtp_state = IMAGE_MTP_ENABLE;
			}
			else
			{
				g_USBImage.mtp_state = IMAGE_MTP_DISABLE;
			}

			/* To UEM */
#if 0	// Revise boot mode.		
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
		#ifdef __OTG_ENABLE__
/* under construction !*/
		#else
/* under construction !*/
/* under construction !*/
/* under construction !*/
		#endif
/* under construction !*/
/* under construction !*/
#endif				
			{
				/* Normal mode */
				/* If cable plug out first, and then USB receive enable response, then USB will not config as MTP */
				USB_Config_Req_Hdlr(USB_IMAGE_MTP, (kal_uint32 *)g_USBImage.mtp_image_buffer);
			}

			/* To handle delay plug out */
			/* g_USBImage.b_is_pending_disable_mtp_msg == KAL_TRUE must be cable out */
			if(g_USBImage.b_is_pending_disable_mtp_msg == KAL_TRUE)
			{
				/* Should send MTP disable msg here */
		#ifdef __OTG_ENABLE__
				OTG_B_Set_Session_Valid(KAL_FALSE);
				OTG_Mode_Selection();
		#else
				USB_Mode_Selection();
		#endif

				g_USBImage.b_is_pending_disable_mtp_msg = KAL_FALSE;

				if((g_USBImage.mtp_state == IMAGE_MTP_ENABLE)&&(g_USBImage.b_mtp_release_type == KAL_FALSE))
				{
					/* Go into here must because of cable plug out before USB receive enable response*/
					USB_Release_MTP_Status();
					g_USBImage.b_mtp_release_type = KAL_TRUE;
				}
			}

			if(g_USBImage.b_delay_mtp_stop_config == KAL_TRUE)
			{
				if(g_UsbMode.usb_boot == KAL_FALSE)
					ASSERT(0);

				g_USBImage.b_delay_mtp_stop_config = KAL_FALSE;
				USB_Config_Req_Hdlr(USB_STOP_MTP, NULL);
			}
			break;

		case MSG_ID_USB_MTP_DISABLE_RSP:
			USB_Dbg_Trace(USB_MTP_RECEIVE_DISABLE_RSP, g_USBImage.b_wait_disable_rsp, g_USBImage.b_mtp_release_type);

			if(g_USBImage.b_wait_disable_rsp == KAL_FALSE)
				ASSERT(0);
			g_USBImage.b_wait_disable_rsp = KAL_FALSE;

			/* Cable plug out or STOP_MTP both will call USB_MTP_Release() */
			if(g_USBImage.b_mtp_release_type == KAL_TRUE)
			{
				/* Cable out */
				g_USBImage.b_mtp_release_type = KAL_FALSE;
				drv_trace0(TRACE_FUNC, (kal_uint32)USB_PLUG_OUT);

				/* Notify UEM, MS mode must send this message to shut down */
				USB_Send_Msg(USB_SEND_MSG_PLUG_OUT);

				USB_Dbg_Trace(USB_TASK_UNMASK_EINT, 2, 0);
				/* Unmask EINT for next detection until MTP send disable response msg */
				USB_CHR_USB_EINT_UnMask();
//				Dcl_Chr_Det_Control(g_PWIC_Dcl_Handle, CHR_DET_CMD_UNMASK_EINT, NULL);
			}

			if(g_USBImage.b_mtp_stop_type == KAL_TRUE)
			{
				/* STOP_MTP */
				g_USBImage.b_mtp_stop_type = KAL_FALSE;

				if(g_UsbMode.cable_type != USB_MODE_CABLE_PLUGOUT)
				{
					USB_Send_Config_Cnf_Msg(USB_STOP_MTP, KAL_TRUE);
				}
				else
				{
					USB_Send_Config_Cnf_Msg(USB_STOP_MTP, KAL_FALSE);
				}
			}
			break;

		case MSG_ID_USB_MTP_OPERATION_RSP:
			if(g_USBImage.b_wait_req_rsp == KAL_FALSE)
				ASSERT(0);
			g_USBImage.b_wait_req_rsp = KAL_FALSE;

			USB_MTP_Parse_MTP_Meg(&current_ilm);
			break;

		case MSG_ID_USB_MTP_EVENT_IND:
			USB_MTP_Parse_MTP_Event_Meg(&current_ilm);
			break;

		case MSG_ID_USB_MTPIMAGE_DATA_RX_DONE_CONF:
		case MSG_ID_USB_MTPIMAGE_DATA_TX_DONE_CONF:
			if((USB_Get_Device_State() == DEVSTATE_CONFIG)&&(g_USBImage.image_ep0_reset == KAL_FALSE)&&(g_USBImage.mtp_state == IMAGE_MTP_ENABLE))
			{
				USB_MTP_State_Machine_Hdlr(&current_ilm);
			}
			break;

		case MSG_ID_USB_MTPIMAGE_CANCEL_IND:
			if((USB_Get_Device_State() == DEVSTATE_CONFIG)&&(g_USBImage.image_ep0_reset == KAL_FALSE))
			{
				USB_MTP_State_Machine_Hdlr(&current_ilm);
			}
			break;

		case MSG_ID_USB_MTPIMAGE_RESET_IND:
			USB_MTP_State_Machine_Hdlr(&current_ilm);
			break;
	#endif /* __MTP_ENABLE__ */

	#ifdef __USB_STRESS_TEST__
		case MSG_ID_USB_TEST_START_IND:
			USB_ECHO_TEST();
			break;
	#endif

	#ifdef __USB_LOGGING__
		case MSG_ID_USB_LOGGING_START_IND:
			USBACM_LOGGING_Start_Hdlr();
			break;

	#ifdef __MODEM_3G_LOGGING__
			/* 3G only, user want to reset logging HW */
		case MSG_ID_USB_LOGGING_RESET_IND:
			USBACM_LOGGING_Reset_Hdlr();
			break;
	#endif
		case MSG_ID_USB_LOGGING_CONNECT_IND:
			USBACM_LOGGING_Connect_Hdlr();
			break;

		case MSG_ID_USB_LOGGING_DISCONNECT_IND:
			USBACM_LOGGING_Discon_Hdlr();
			break;

	#endif /* __USB_LOGGING__*/
		default:
			EXT_ASSERT(0, (kal_uint32)current_ilm.msg_id, 0, 0);
			break;
		}
		destroy_ilm(&current_ilm);
	}
#endif /* IC_MODULE_TEST */
}



/************************************************************
	Class driver APIs
*************************************************************/
#ifdef  __USB_MASS_STORAGE_ENABLE__

static void USB_Ms_State_Machine_Hdlr(ilm_struct *lim_ptr)
{
#if defined(__USB_MODEM_CARD_SUPPORT__)
	//if (USB_Get_Device_Type() == USB_MASS_STORAGE || USB_Get_Device_Type() == USB_COMPOSITE_MULTI_COM)
	if (USB_Get_Device_Type() == USB_MASS_STORAGE || USB_Get_Device_Type() == USB_COMPOSITE_MULTI_COM|| USB_Get_Device_Type() == USB_COMPOSITE_DEVICES
		|| USB_Get_Device_Type() == USB_MORPHING_MBIM)
#else
	if(USB_Get_Device_Type() == USB_MASS_STORAGE)
#endif
	{
		USB_Ms_State_Main(lim_ptr);
	}
	else if(USB_Get_Device_Type() != USB_UNKOWN) /* be configured as MS_STOP mode */
	{
      	ASSERT(0);
//		EXT_ASSERT(0, (kal_uint32)USB_Get_Device_Type(), 0, 0);
	}
}

#endif

#ifdef   PICTBRIDGE_SUPPORT

static void USB_PTP_State_Machine_Hdlr(ilm_struct *lim_ptr)
{
	if((USB_Get_Device_Type() == USB_IMAGE)||(USB_Get_Device_Type() == USB_UNKOWN))
	{
		/* When USB cable is plugged out and then plugged in quickly,
			the reset interrupt may issue because USB task does not handle plug out msg yet, so GPIO(D+) is still high */
		PTP_Parse_USB_Meg(lim_ptr);
	}
	else
	{
			  ASSERT(0);
		//		EXT_ASSERT(0, (kal_uint32)USB_Get_Device_Type(), 0, 0);

	}
}

#endif

#ifdef __MTP_ENABLE__

static void USB_MTP_State_Machine_Hdlr(ilm_struct *lim_ptr)
{
	if((USB_Get_Device_Type() == USB_IMAGE_MTP)||(USB_Get_Device_Type() == USB_UNKOWN))
	{
		/* When USB cable is plugged out and then plugged in quickly,
			the reset interrupt may issue because USB task does not handle plug out msg yet, so GPIO(D+) is still high */
		USB_MTP_Parse_USB_Meg(lim_ptr);
	}
	else
	{
			  ASSERT(0);
		//		EXT_ASSERT(0, (kal_uint32)USB_Get_Device_Type(), 0, 0);

	}
}

#endif

static void USB_Config_Req_Hdlr(USB_DEVICE_TYPE type, kal_uint32 *parameter)
{
#ifdef __OTG_ENABLE__
	#ifdef __OTG_SRP_HNP_APP_FIXED__
	/* Should not receive this msg because USB does not send plug in to UEM, except USB boot mode UEM send MS_STOP cmd */
	if((g_UsbMode.usb_boot == KAL_FALSE)||(type != USB_STOP_MS))
		ASSERT(0);
	#endif

	if(g_UsbMode.b_start_hnp == KAL_TRUE)
	{
		OTG_Config_HNP(type, parameter);
	}
	else if (g_UsbMode.b_start_srp == KAL_TRUE)
	{
		/* For SRP function, all the software resource initialization should be configured before SRP,
		    After A device provide VBUS, B device should connect D+ within 1 sec*/
		OTG_Config_SRP(type, parameter);
	}
	else
	{
		/* Normal config request from MMI */
		if(g_UsbMode.cable_type != USB_MODE_CABLE_PLUGOUT)
		{
	#ifdef __MTP_ENABLE__
			if(type == USB_IMAGE_MTP)
			{
				if(g_USBImage.mtp_state == IMAGE_MTP_ENABLE)
				{
					g_UsbMode.usb_config_result = KAL_TRUE;
					USB_Config_Type(type, KAL_TRUE, parameter);
				}
				else
				{
					g_UsbMode.usb_config_result = KAL_FALSE;
				}
			}
			else
			{
				USB_Config_Type(type, KAL_TRUE, parameter);
			}

			/* the UEM CNF msg of USB_STOP_MTP will be sent after MSG_ID_USB_MTP_DISABLE_RSP */
			if(type != USB_STOP_MTP)
				USB_Send_Config_Cnf_Msg(type, g_UsbMode.usb_config_result);
//			else if((type == USB_STOP_MTP)&&(g_UsbMode.usb_config_result == KAL_FALSE))
//				USB_Send_Config_Cnf_Msg(type, KAL_TRUE);

	#else  /* __MTP_ENABLE__ */
			USB_Config_Type(type, KAL_TRUE, parameter);
			if (gUsbDevice.usb_send_config_result == KAL_TRUE)
			{
				USB_Send_Config_Cnf_Msg(type, g_UsbMode.usb_config_result);
			}
			gUsbDevice.usb_send_config_result = KAL_TRUE;
	#endif
		}
		else
		{
			USB_Send_Config_Cnf_Msg(type, KAL_FALSE);
		}
	}
#else /* __OTG_ENABLE__ */
	/* Config request from MMI */
	if(g_UsbMode.cable_type != USB_MODE_CABLE_PLUGOUT)
	{
#ifdef __MTP_ENABLE__
		if(type == USB_IMAGE_MTP)
		{
			if(g_USBImage.mtp_state == IMAGE_MTP_ENABLE)
			{
				g_UsbMode.usb_config_result = KAL_TRUE;
				USB_Config_Type(type, KAL_TRUE, parameter);
			}
			else
			{
				g_UsbMode.usb_config_result = KAL_FALSE;
			}
		}
		else
		{
			USB_Config_Type(type, KAL_TRUE, parameter);
		}

		/* the UEM CNF msg of USB_STOP_MTP will be sent after MSG_ID_USB_MTP_DISABLE_RSP */
		if(type != USB_STOP_MTP)
			USB_Send_Config_Cnf_Msg(type, g_UsbMode.usb_config_result);
//		else if((type == USB_STOP_MTP)&&(g_UsbMode.usb_config_result == KAL_FALSE))
//			USB_Send_Config_Cnf_Msg(type, KAL_TRUE);

#else  /* __MTP_ENABLE__ */
		USB_Config_Type(type, KAL_TRUE, parameter);
		if (gUsbDevice.usb_send_config_result == KAL_TRUE)
		{
			USB_Send_Config_Cnf_Msg(type, g_UsbMode.usb_config_result);
		}
		gUsbDevice.usb_send_config_result = KAL_TRUE;

#endif
	}
	else
	{
		USB_Send_Config_Cnf_Msg(type, KAL_FALSE);
	}
#endif /* __OTG_ENABLE__ */
}


/************************************************************
	serial string  functions
*************************************************************/

/*store unique data to serial string*/
/*this function is used for normal mode, NVRAM task respondes the string by message*/
static void USB_Store_Serial_Value(ilm_struct *ilm_ptr)
{
	kal_uint16     len;
	nvram_read_cnf_struct *parm_ptr = (nvram_read_cnf_struct *) ilm_ptr->local_para_ptr;
	kal_uint8 *pdu_ptr = get_peer_buff_pdu(ilm_ptr->peer_buff_ptr, &len);

	if((parm_ptr->result == (kal_uint8)NVRAM_IO_ERRNO_OK)||(parm_ptr->result == (kal_uint8)NVRAM_IO_ERRNO_INIT))
	{
		//construct serial string
		USB_Constrct_Serial_String(pdu_ptr, len);
	}
	else
	{
		ASSERT(0);
	}
}


/*get and store unique data to serial string*/
/*this function is used for mass storage mode because NAVRAM task not created in mass storage mode*/
void USB_Get_Serial_Value(void)
{
#ifndef __MEUT__
	kal_uint8 *serial_buf;
	kal_uint16 record, size;

	if(nvram_get_info((kal_uint8)UNI_ID, &record, &size) != NVRAM_ERRNO_SUCCESS)
		ASSERT(0);
//		EXT_ASSERT(0, 0, 0, 0);

	serial_buf = (kal_uint8*)USB_Get_Memory(size);//get_ctrl_buffer(size);

	/* read unique string data from NVRAM, and construct USB serial string before init mass sotrage*/
	if( nvram_external_read_data((kal_uint8)UNI_ID,1, serial_buf, size) == KAL_TRUE )
	{
		USB_Constrct_Serial_String(serial_buf, size);
	}
	else
	{
		ASSERT(0);
	}

//	free_ctrl_buffer(serial_buf);
#endif /* __MEUT__ */
}

/* convert from val to string type (ascii code)*/
static kal_uint16 USB_Convert_String(kal_uint8 val)
{
	kal_uint16 ret;

	if(val>0xf)
		ASSERT(0);

	ret = (val>=0xa)?(val-0xa+0x61):(val+0x30);

	/* convert to a-f ascii code*/
//	if(val>=0xa)
//		ret = val - 0xa + 0x61;
	/* convert to 0-9 ascii code*/
//	else
//		ret = val + 0x30;

	return ret;

}

/* convert from unique charaters to serial string for USB*/
static void USB_Constrct_Serial_String(kal_uint8 *pdu_ptr, kal_uint16 len)
{
	kal_uint32 i;
	kal_uint32 serial_len;

	/* length must be even */
	if(((USB_SERIAL_STRING_LEN&0x1)!=0)||(len==0))
		ASSERT(0);

	serial_len = (len< (USB_SERIAL_STRING_LEN>>1)) ? len:(USB_SERIAL_STRING_LEN>>1);

	/* string type and length*/
	gUsbDevice.serial_string[0] = 0x0320;

	/* convert from pdu_ptr to USB serial string */
	for(i=0; i<(serial_len-1); i++)
	{
		gUsbDevice.serial_string[(i<<1)+1] = USB_Convert_String((pdu_ptr[i]&0xf0)>>4);
		gUsbDevice.serial_string[(i<<1)+2] = USB_Convert_String(pdu_ptr[i]&0xf);
	}
	gUsbDevice.serial_string[((serial_len-1)<<1)+1] = USB_Convert_String((pdu_ptr[(serial_len-1)]&0xf0)>>4);
}


/************************************************************
	cable and message uitility  functions
*************************************************************/

/* Send message to other tasks */
void USB_Send_Msg(USB_SEND_MSG_TYPE usb_msg_type)
{
#ifndef __L1_STANDALONE__
	drvuem_usbdetect_ind_struct *usbdetect_req;
#endif

#ifndef __MEUT__
	local_para_struct *local_ptr = NULL;
	kal_uint16 record;
	kal_uint16 size;
#endif /* __MEUT__ */
	bmt_usb_ind_struct *ind;
//	ilm_struct *ilm_charge = NULL;

//	ilm_struct *usb_ilm = NULL;
#ifdef	__TC01__
/* under construction !*/
/* under construction !*/
#endif
//	module_type 	src_mod;

	/* In assert mode, we cannot send message.
	 * Thus, we just retun.
	 */
	if(INT_Exception_Enter != 0)
		return;

	switch(usb_msg_type)
	{
			case USB_SEND_MSG_PLUG_IN:
			{
#if defined(__OTG_ENABLE__)||defined(__MTP_ENABLE__)||defined(__USB_TETHERING__)
				if((g_UsbMode.usb_comport_boot != USB_NORMAL_BOOT)&&(g_UsbMode.usb_menu_en == KAL_FALSE))
					ASSERT(0);
		
				if((usb_plug_in_flag == KAL_TRUE)&&(g_UsbMode.usb_boot == KAL_FALSE))
					ASSERT(0);
		
				usb_plug_in_flag = KAL_TRUE;
#endif
		
				/*Notify UEM*/
				/* for USB_UNKOWN, show selection screen*/
				/* for USB_MASS_STORAGE, UEM latch power*/
#ifndef __L1_STANDALONE__
				usbdetect_req = (drvuem_usbdetect_ind_struct*)construct_local_para(
						  sizeof(drvuem_usbdetect_ind_struct), TD_CTRL);

				usbdetect_req->action = DETECT_ACTION_PLUGIN;
		
				USB_Send_Msg_Ext_Queue(MOD_UEM, MSG_ID_DRVUEM_USBDETECT_IND, usbdetect_req);
		
		//		DRV_BuildPrimitive(usb_ilm, src_mod, MOD_UEM, MSG_ID_DRVUEM_USBDETECT_IND, usbdetect_req);
#endif
			}
			break;

			case USB_SEND_MSG_PLUG_OUT:
#if defined(__OTG_ENABLE__)||defined(__MTP_ENABLE__)||defined(__USB_TETHERING__)
				if((g_UsbMode.usb_comport_boot != USB_NORMAL_BOOT)&&(g_UsbMode.usb_menu_en == KAL_FALSE))
					ASSERT(0);
		
				if((usb_plug_in_flag == KAL_FALSE)&&(g_UsbMode.usb_boot == KAL_FALSE))
					ASSERT(0);
		
				usb_plug_in_flag = KAL_FALSE;
#endif
		
				/*Notify UEM cable plug out*/
#ifndef __L1_STANDALONE__
				usbdetect_req = (drvuem_usbdetect_ind_struct*)construct_local_para(
						  sizeof(drvuem_usbdetect_ind_struct), TD_CTRL);

				usbdetect_req->action = DETECT_ACTION_PLUGOUT;
		
				USB_Send_Msg_Ext_Queue(MOD_UEM, MSG_ID_DRVUEM_USBDETECT_IND, usbdetect_req);
		
		//		DRV_BuildPrimitive(usb_ilm, src_mod, MOD_UEM, MSG_ID_DRVUEM_USBDETECT_IND, usbdetect_req);
#endif
				
			break;

			case USB_SEND_BMT_START_CHARGE:				
			case USB_SEND_BMT_STOP_CHARGE:				
			case USB_SEND_BMT_CHARGE_MIN:				
			case USB_SEND_BMT_CHARGE_MAX:
				ind = (bmt_usb_ind_struct*)construct_local_para(sizeof(bmt_usb_ind_struct), TD_CTRL);				
				ind->usb_ind = PMU_CHARGE_CURRENT_0_00_MA;

				if(usb_msg_type == USB_SEND_BMT_START_CHARGE)
				{			
					if (gUsbDevice.config_num <= gUsbDevice.current_table_index)
						ind->usb_ind = (PMU_CHR_CURRENT_ENUM)gUsbDevice.get_chr_current_list.pCurrentList[gUsbDevice.current_table_index-gUsbDevice.config_num];
				}
				else if(usb_msg_type == USB_SEND_BMT_CHARGE_MIN)
				{
					ind->usb_ind = (PMU_CHR_CURRENT_ENUM)gUsbDevice.get_chr_current_list.pCurrentList[0];					
				}
				else if(usb_msg_type == USB_SEND_BMT_CHARGE_MAX)
				{
					ind->usb_ind = (PMU_CHR_CURRENT_ENUM)gUsbDevice.get_chr_current_list.pCurrentList[gUsbDevice.current_table_index - 1];
				}
//			else //USB_SEND_BMT_STOP_CHARGE
//			{
//				ind->usb_ind = PMU_CHARGE_CURRENT_0_00_MA;
//			}
				
				USB_Send_Msg_Ext_Queue(MOD_BMT, MSG_ID_BMT_USB_IND, ind);
				
				drv_trace2(TRACE_FUNC, (kal_uint32)USB_CONFIG_NUM,gUsbDevice.config_num,gUsbDevice.current_table_index);
				
			break;

#ifdef	__TC01__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined(__OTG_ENABLE__)||defined(__MTP_ENABLE__)||defined(__USB_TETHERING__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
#ifndef __L1_STANDALONE__
/* under construction !*/
#if defined(__TC01__)||defined(__USB_DATA_CONNECTION__)||defined (__USB_MODEM_CARD_SUPPORT__)
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
#endif
/* under construction !*/
/* under construction !*/
#endif			

			case USB_SEND_MSG_READ_UNIQUE_STRING:
#ifndef __MEUT__
				/* Send msg to NVRAM, read serial string data*/
				if(nvram_get_info((kal_uint8)UNI_ID, &record, &size) != NVRAM_ERRNO_SUCCESS)
					ASSERT(0);
				
				local_ptr = construct_local_para(sizeof(nvram_read_req_struct), TD_CTRL);
		
				((nvram_read_req_struct *)local_ptr)->file_idx = (kal_uint8)UNI_ID;
				((nvram_read_req_struct *)local_ptr)->para = 1; // enum misuse: NVRAM_SYS_AUTO_DETECT
		
				USB_Send_Msg_Ext_Queue(MOD_NVRAM, MSG_ID_NVRAM_READ_REQ, local_ptr);
		
		//		DRV_BuildPrimitive(usb_ilm, src_mod, MOD_NVRAM, MSG_ID_NVRAM_READ_REQ, local_ptr);
#endif /* __MEUT__ */

			break;
#ifdef __P_PROPRIETARY_COPYRIGHT__
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

#ifdef __USB_TETHERING__

			case RNDIS_USB_CONFIG_CNF:
				/*Notify RNDIS*/
		USB_Send_Msg_Ext_Queue(MOD_UPS_HIGH, MSG_ID_RNDIS_USB_CONFIG_CNF, NULL);
				
		//		DRV_BuildPrimitive(usb_ilm, src_mod, MOD_UPS, MSG_ID_RNDIS_USB_CONFIG_CNF, NULL);	

			break;	

			case RNDIS_USB_DETACH_CNF:
				/*Notify RNDIS*/
		USB_Send_Msg_Ext_Queue(MOD_UPS_HIGH, MSG_ID_RNDIS_USB_DETACH_CNF, NULL);
				
		//		DRV_BuildPrimitive(usb_ilm, src_mod, MOD_UPS, MSG_ID_RNDIS_USB_DETACH_CNF, NULL);  

			break;	
#endif			

			default : 
//				usb_ilm = NULL;
				ASSERT(0);
			//	EXT_ASSERT(0, (kal_uint32)usb_msg_type, 0, 0);

			break;
	}
}


void USB_Send_Config_Cnf_Msg(USB_DEVICE_TYPE mode, kal_bool result)
{
//	ilm_struct *usb_ilm = NULL;
	drvuem_usbcfg_cnf_struct *usb_prim;
//	module_type src_mod;


//	if(kal_if_hisr() == KAL_TRUE)
//		src_mod = MOD_DRV_HISR;
//	else
//		src_mod = MOD_USB;

#if defined(__OTG_ENABLE__)||defined(__MTP_ENABLE__)||defined(__USB_TETHERING__)
	if((g_UsbMode.usb_comport_boot != USB_NORMAL_BOOT)&&(g_UsbMode.usb_menu_en == KAL_FALSE))
		ASSERT(0);

	if(usb_config_flag == KAL_FALSE)
		ASSERT(0);
	usb_config_flag = KAL_FALSE;
#endif

	/* Notify UEM */
	usb_prim = (drvuem_usbcfg_cnf_struct*)
				construct_local_para(sizeof(drvuem_usbcfg_cnf_struct), TD_CTRL);
	usb_prim->mode = mode;
	usb_prim->result = result;


	USB_Send_Msg_Ext_Queue(MOD_UEM, MSG_ID_DRVUEM_USBCFG_CNF, usb_prim);

//	DRV_BuildPrimitive(usb_ilm,  src_mod, MOD_UEM, MSG_ID_DRVUEM_USBCFG_CNF, usb_prim);
//	msg_send_ext_queue(usb_ilm);
}


/* Add for usb charging, check the cable status */
kal_bool USB_GetCableStatus(void)
{
	return (g_usb_cable_state!=gUsbDevice.device_param->cable_plugin_level)?(KAL_TRUE):(KAL_FALSE);
}


#ifdef __USB_ENABLE__

/* external interrupt HISR */
void USB_EINT_HISR(void)
{
//	ilm_struct *usb_hisr_ilm = NULL;
	DCL_BOOL  dcl_data;
//	DCL_HANDLE bmt_handler;
//	BMT_CTRL_SENDMES2UEM_T bmt_cmd_data1;
#if defined(__OTG_ENABLE__)
	OTG_DRV_CTRL_GET_Reg_T dcl_otg_cable;
#endif


	if (g_usb_cable_state != gUsbDevice.device_param->cable_plugin_level) /*Must modify for different level, plug out*/
	{
		USB_Dbg_Trace(USB_DBG_CABLE_PLUG_OUT, 0, 0);
//		gUsbDevice.usb_cable_in = KAL_FALSE;
		USB_Set_Device_State(DEVSTATE_DEFAULT);

		USB_Send_Msg_Ext_Queue(MOD_USB,MSG_ID_USB_B_PLUGOUT_IND,NULL);

//		DRV_BuildPrimitive(usb_hisr_ilm,MOD_DRV_HISR,MOD_USB,MSG_ID_USB_B_PLUGOUT_IND,NULL);
//		msg_send_ext_queue(usb_hisr_ilm);

		#if defined(__USB_MODEM_CARD_EINT_RESET__)
			DRV_RESET();
		#endif

		/* On EVB board, there may be no PMIC. */
		USB_BMT_NO_CHARGING_OUT();
 //		bmt_handler = DclBMT_Open(DCL_BMT,FLAGS_NONE);
//		bmt_cmd_data1.ChargerMsg = DCL_BMT_USB_NO_CHARGING_OUT;
//		DclBMT_Control(bmt_handler, BMT_CMD_SENDMES2UEM, (DCL_CTRL_DATA_T *)&bmt_cmd_data1); // New API with CMD & DATA
	}
	else  /* first time USB cable plug in  */
	{
	#if defined(__CHARGER_USB_DETECT_WIHT_ONE_EINT__)&& defined(DRV_MISC_CHR_USB_EINT_CENTRAL_UNMASK)
//	     if (g_PWIC_Dcl_Handle == 0)
//	     		g_PWIC_Dcl_Handle = DclPMU_Open(DCL_PMU, FLAGS_NONE);
		USB_CHR_USB_EINT_UnMask();

//	     	Dcl_Chr_Det_Control(g_PWIC_Dcl_Handle, CHR_DET_CMD_UNMASK_EINT, NULL); //Unmask EINT for next detection
	#endif

		USB_Dbg_Trace(USB_DBG_CABLE_PLUG_IN, 0, 0);

	#ifdef __OTG_ENABLE__

		DclOTG_DRV_Control(g_OTG_Dcl_Handle, OTG_DRV_CMD_IS_A_CABLE_IN,(DCL_CTRL_DATA_T *)&dcl_otg_cable);
	
		if ((kal_bool)dcl_otg_cable.return_value == KAL_TRUE)  // plug in A to A Cable
			g_UsbMode.cable_type = USB_MODE_CABLE_ERROR;


		if(gUsbOtg.b_check_srp == KAL_TRUE)
		{
			/* Means SRP succeed, so A device turn on Vbus */
			/* For SRP, we already turn on phy power */
			OTG_B_Set_Session_Valid(KAL_TRUE);
		}
	#endif

		dcl_data = DCL_TRUE;

	#ifdef __USB_COM_PORT_ENABLE__ //__USB_DOWNLOAD__
		if(USBDL_Mode_Type()== USBDL_MODE_NONE)//((USBDL_Is_USB_Download_Mode() == KAL_FALSE)&&(INT_IsBootForUSBAT() == KAL_FALSE))
		{
//			USB_UART_Share(KAL_TRUE);
			DclUSB_DRV_Control(g_USB_Dcl_Handle, USB_DRV_CMD_USB_UART_SHARE, (DCL_CTRL_DATA_T  *)&dcl_data);
		}
	#else
		/* We must call this function in USB_EINT_HISR() in the case that USB and UART with one GPIO */
//		USB_UART_Share(KAL_TRUE);
		DclUSB_DRV_Control(g_USB_Dcl_Handle, USB_DRV_CMD_USB_UART_SHARE, (DCL_CTRL_DATA_T  *)&dcl_data);
	#endif


		USB_Send_Msg_Ext_Queue(MOD_USB,MSG_ID_USB_B_PLUGIN_IND,NULL);

//		DRV_BuildPrimitive(usb_hisr_ilm,MOD_DRV_HISR,MOD_USB,MSG_ID_USB_B_PLUGIN_IND,NULL);
//		msg_send_ext_queue(usb_hisr_ilm);

 		/* On EVB board, there may be no PMIC. */
 		USB_BMT_NO_CHARGING_IN();
 //		bmt_handler = DclBMT_Open(DCL_BMT,FLAGS_NONE);
//		bmt_cmd_data1.ChargerMsg = DCL_BMT_USB_NO_CHARGING_IN;
//		DclBMT_Control(bmt_handler, BMT_CMD_SENDMES2UEM, (DCL_CTRL_DATA_T *)&bmt_cmd_data1); // New API with CMD & DATA
	}

	g_usb_cable_state = (g_usb_cable_state == KAL_FALSE)?(KAL_TRUE):(KAL_FALSE);

	/* for charger USB, charger will handle this part */
	#if !defined(__CHARGER_USB_DETECT_WIHT_ONE_EINT__) && !defined(_USB_VBUS_DETECT_WITH_NIRQ_)
	EINT_Set_Polarity(g_usb_eint_no,g_usb_cable_state);
	#endif
}


#endif

