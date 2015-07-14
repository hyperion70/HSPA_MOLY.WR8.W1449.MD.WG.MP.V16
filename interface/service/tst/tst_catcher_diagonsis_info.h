/*******************************************************************************
*  Modification Notice:
*  --------------------------
*  This software is modified by MediaTek Inc. and the information contained
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
*******************************************************************************/


/*****************************************************************************
 *
 * Filename:
 * ---------
 * tst_catcher_diagonsis_info.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file contains the exception handle diagnosis Info of Catcher
 *   With this file, catcher can detect the memory dump failure cause and find the proper owner.
 * 
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

#ifndef __TST_CATCHER_DIAGONOSIS_INFO_H__
#define __TST_CATCHER_DIAGONOSIS_INFO_H__


#if defined(GEN_FOR_PC)

typedef enum
{
  //Format: CATCHER_EXC_MODULES_[Function],
  //Format: CATCHER_EXC_OWNER_[Function]_[Owner Fist Name]_[Owner Last Name]  = CATCHER_EXC_MODULES_[Function],
  CATCHER_EXC_MODULES_UARTUSB,
  CATCHER_EXC_OWNER_USB_Arvin_Wang=CATCHER_EXC_MODULES_UARTUSB,   //owners should be up-to-date
  CATCHER_EXC_OWNER_UART_Liming_Ma=CATCHER_EXC_MODULES_UARTUSB, //owners should be up-to-date
  CATCHER_EXC_MODULES_WATCHDOG,
  CATCHER_EXC_OWNER_WATCHDOG_Liming_Ma = CATCHER_EXC_MODULES_WATCHDOG, //owners should be up-to-date
  CATCHER_EXC_MODULES_LCD,
  CATCHER_EXC_OWNER_LCD_Tianshu_Qiu = CATCHER_EXC_MODULES_LCD, //owners should be up-to-date
  CATCHER_EXC_MODULES_DSP,
  CATCHER_EXC_OWNER_DSP_Fabian_Shih = CATCHER_EXC_MODULES_DSP, //owners should be up-to-date 
  CATCHER_EXC_MODULES_CCCI,
  CATCHER_EXC_OWNER_CCCI_Pupa_Chen = CATCHER_EXC_MODULES_CCCI, //owners should be up-to-date
  CATCHER_EXC_MODULES_FLC,
  CATCHER_EXC_OWNER_FLC_TC_Chang = CATCHER_EXC_MODULES_FLC, //owners should be up-to-date
  CATCHER_EXC_MODULES_FLASH,
  CATCHER_EXC_OWNER_FLASH_ChunHung_Wu = CATCHER_EXC_MODULES_FLASH, //owners should be up-to-date  
  CATCHER_EXC_MODULES_FS,
  CATCHER_EXC_OWNER_FS_Perry_Hsu = CATCHER_EXC_MODULES_FS, //owners should be up-to-date    
  CATCHER_EXC_MODULES_NVRAM,
  CATCHER_EXC_OWNER_NVRAM_ChiaLing_Ko = CATCHER_EXC_MODULES_NVRAM, //owners should be up-to-date
  CATCHER_EXC_MODULES_SS,
  CATCHER_EXC_OWNER_ExceptionHandle_Ken_Lin = CATCHER_EXC_MODULES_SS, //owners should be up-to-date
  CATCHER_EXC_MODULES_TST,  
  CATCHER_EXC_OWNER_TST_Shyla_Lan = CATCHER_EXC_MODULES_TST, //owners should be up-to-date
  CATCHER_EXC_MODULES_CATCHER,
  CATCHER_EXC_OWNER_Catcher_Wanting_Lai = CATCHER_EXC_MODULES_CATCHER, //owners should be up-to-date
}
catcher_exception_handler_owner_list_t;

typedef enum
{ //format OWNER____[trace name]
  //____ can't be shown in the trace name
  OWNER____TST_EX_MSG_DUMP_UART_RING_BUFFER_START             = CATCHER_EXC_MODULES_UARTUSB,
  OWNER____TST_EX_MSG_DUMP_UART_RING_BUFFER_END               = CATCHER_EXC_MODULES_TST,
  OWNER____TST_EX_MSG_DISABLE_LGA_BUF_UNDER_SS_START          = CATCHER_EXC_MODULES_TST,
  OWNER____TST_EX_MSG_DISABLE_LGA_BUF_UNDER_SS_END            = CATCHER_EXC_MODULES_TST,
  OWNER____TST_EX_MSG_CLEAN_UART_UNDER_SS_START               = CATCHER_EXC_MODULES_UARTUSB,
  OWNER____TST_EX_MSG_CLEAN_UART_UNDER_SS_END                 = CATCHER_EXC_MODULES_TST,
  OWNER____TST_EX_MSG_DUMP_PS_BUF_START                       = CATCHER_EXC_MODULES_TST,
  OWNER____TST_EX_MSG_DUMP_PS_BUF_END                         = CATCHER_EXC_MODULES_TST,
  OWNER____TST_EX_MSG_DISABLE_LGA_BUF_START                   = CATCHER_EXC_MODULES_TST,
  OWNER____TST_EX_MSG_DISABLE_LGA_BUF_END                     = CATCHER_EXC_MODULES_TST,
  OWNER____TST_EX_MSG_REOPEN_PORT_START                       = CATCHER_EXC_MODULES_UARTUSB,
  OWNER____TST_EX_MSG_REOPEN_PORT_END                         = CATCHER_EXC_MODULES_TST,
  OWNER____TST_EX_MSG_OPEN_PORT_START                         = CATCHER_EXC_MODULES_UARTUSB,
  OWNER____TST_EX_MSG_OPEN_PORT_END                           = CATCHER_EXC_MODULES_TST,
  OWNER____TST_EX_MSG_CLEAN_UART_START                        = CATCHER_EXC_MODULES_UARTUSB,
  OWNER____TST_EX_MSG_CLEAN_UART_END                          = CATCHER_EXC_MODULES_TST,  
  OWNER____TST_EX_MSG_CLOSE_PORT_START                        = CATCHER_EXC_MODULES_UARTUSB,
  OWNER____TST_EX_MSG_CLOSE_PORT_END                          = CATCHER_EXC_MODULES_TST,
  OWNER____TST_EX_MSG_CHANGE_L1_PORT                          = CATCHER_EXC_MODULES_TST,
  OWNER____TST_EX_MSG_NESTED_EX_DETECTED                      = CATCHER_EXC_MODULES_SS,
  OWNER____TST_EX_MSG_DUMP_SST_LOG_START                      = CATCHER_EXC_MODULES_SS,
  OWNER____TST_EX_MSG_DUMP_SST_LOG_END                        = CATCHER_EXC_MODULES_TST,
  OWNER____TST_EX_MSG_DRV_EX_HANDLER_STA                      = CATCHER_EXC_MODULES_UARTUSB,
  OWNER____TST_EX_MSG_DRV_EX_HANDLER_END                      = CATCHER_EXC_MODULES_TST,
  
  OWNER____TST_EX_MSG_DUMP_LGA_BUF_START                      = CATCHER_EXC_MODULES_TST,
  OWNER____TST_EX_MSG_DUMP_LGA_BUF_END                        = CATCHER_EXC_MODULES_TST,
  OWNER____TST_EX_MSG_REDUMP_PS_BUF_START                     = CATCHER_EXC_MODULES_TST,
  OWNER____TST_EX_MSG_REDUMP_PS_BUF_END                       = CATCHER_EXC_MODULES_TST,
  OWNER____TST_EX_MSG_REDUMP_L1_BUF_START                     = CATCHER_EXC_MODULES_TST,
  OWNER____TST_EX_MSG_REDUMP_L1_BUF_END                       = CATCHER_EXC_MODULES_TST,
  //OWNER____TST_EX_MSG_GET_CATCHER_CMD                         = CATCHER_EXC_MODULES_TST,  //information only, Catcher should not use this trace for disgnosis
  OWNER____TST_EX_MSG_GET_CATCHER_CMD_CHECKSUM_ERROR          = CATCHER_EXC_MODULES_UARTUSB,

  OWNER____SST_EXC_WATCHDOG_RESET_ENTER                   = CATCHER_EXC_MODULES_WATCHDOG,
  OWNER____SST_EXC_WATCHDOG_RESET_EXIT                      = CATCHER_EXC_MODULES_SS,
  OWNER____SST_EXC_WATCHDOG_DISABLE_ENTER                = CATCHER_EXC_MODULES_WATCHDOG,
  OWNER____SST_EXC_WATCHDOG_DISABLE_EXIT                   = CATCHER_EXC_MODULES_SS,
  OWNER____SST_EXC_OPEN_LOGGING_PORT_ENTER               = CATCHER_EXC_MODULES_TST,
  OWNER____SST_EXC_OPEN_LOGGING_PORT_EXIT                  = CATCHER_EXC_MODULES_SS,
  OWNER____SST_EXC_NOTIFY_DSP_ENTER                              = CATCHER_EXC_MODULES_DSP,
  OWNER____SST_EXC_NOTIFY_DSP_EXIT                                 = CATCHER_EXC_MODULES_SS,
  OWNER____SST_EXC_CCCI_HANDSHAKING_ENTER                 = CATCHER_EXC_MODULES_CCCI,
  OWNER____SST_EXC_CCCI_HANDSHAKING_EXIT                    = CATCHER_EXC_MODULES_SS,
  OWNER____SST_EXC_RESET_HARDWARE_ENTER                    = CATCHER_EXC_MODULES_SS,
  OWNER____SST_EXC_RESET_HARDWARE_EXIT                       = CATCHER_EXC_MODULES_SS,
  OWNER____SST_EXC_INIT_EXCEPTION_RECORD_ENTER        = CATCHER_EXC_MODULES_SS,
  OWNER____SST_EXC_INIT_EXCEPTION_RECORD_EXIT           = CATCHER_EXC_MODULES_SS,
  OWNER____SST_EXC_CLEAR_PENDING_LOG_ENTER                = CATCHER_EXC_MODULES_TST,
  OWNER____SST_EXC_CLEAR_PENDING_LOG_EXIT                   = CATCHER_EXC_MODULES_SS,
  OWNER____SST_EXC_OUTPUT_DSP_LOG_ENTER                      = CATCHER_EXC_MODULES_SS,
  OWNER____SST_EXC_OUTPUT_DSP_LOG_EXIT                        = CATCHER_EXC_MODULES_SS,
  OWNER____SST_EXC_OUTPUT_EXC_MSG_ENTER                     = CATCHER_EXC_MODULES_SS,
  OWNER____SST_EXC_OUTPUT_EXC_MSG_EXIT                        = CATCHER_EXC_MODULES_SS,
  OWNER____SST_EXC_INVOKE_SST_ENGINE_ENTER                = CATCHER_EXC_MODULES_SS,
  OWNER____SST_EXC_INVOKE_SST_ENGINE_EXIT                   = CATCHER_EXC_MODULES_SS,
  OWNER____SST_EXC_LCD_DISPLAY_ENTER                             = CATCHER_EXC_MODULES_SS,
  OWNER____SST_EXC_LCD_DISPLAY_EXIT                               = CATCHER_EXC_MODULES_SS,
  OWNER____SST_EXC_INIT_DEBUG_PRINT_ENTER                  = CATCHER_EXC_MODULES_LCD,
  OWNER____SST_EXC_INIT_DEBUG_PRINT_EXIT                     = CATCHER_EXC_MODULES_SS,
  OWNER____SST_EXC_DSP_DISPLAY_ENTER                            = CATCHER_EXC_MODULES_SS,
  OWNER____SST_EXC_DSP_DISPLAY_EXIT                               = CATCHER_EXC_MODULES_SS,
  OWNER____SST_EXC_DEBUG_PRINT_ENTER                            = CATCHER_EXC_MODULES_LCD,
  OWNER____SST_EXC_DEBUG_PRINT_EXIT                               = CATCHER_EXC_MODULES_SS,
  OWNER____SST_EXC_OUTPUT_EXCEPTION_RECORD_ENTER   = CATCHER_EXC_MODULES_SS,
  OWNER____SST_EXC_OUTPUT_EXCEPTION_RECORD_EXIT      = CATCHER_EXC_MODULES_SS,
  OWNER____SST_EXC_PASS_CCCI_EXCINFO_ENTER                 = CATCHER_EXC_MODULES_CCCI,
  OWNER____SST_EXC_PASS_CCCI_EXCINFO_EXIT                    = CATCHER_EXC_MODULES_SS,
  OWNER____SST_EXC_FLC_DEBUG_INFO_ENTER                      = CATCHER_EXC_MODULES_FLC,
  OWNER____SST_EXC_FLC_DEBUG_INFO_EXIT                         = CATCHER_EXC_MODULES_SS,
  OWNER____SST_EXC_INIT_FDD_TABLE_ENTER                       = CATCHER_EXC_MODULES_FLASH,
  OWNER____SST_EXC_INIT_FDD_TABLE_EXIT                          = CATCHER_EXC_MODULES_SS,
  OWNER____SST_EXC_SAVE_EXCEPTION_RECORD_ENTER        = CATCHER_EXC_MODULES_SS,
  OWNER____SST_EXC_SAVE_EXCEPTION_RECORD_EXIT           = CATCHER_EXC_MODULES_SS,
  OWNER____SST_EXC_FS_UNLOCK_ALL_ENTER                         = CATCHER_EXC_MODULES_FS,
  OWNER____SST_EXC_FS_UNLOCK_ALL_EXIT                            = CATCHER_EXC_MODULES_SS,
  OWNER____SST_EXC_FS_SHUTDOWN_ENTER                           = CATCHER_EXC_MODULES_FS,
  OWNER____SST_EXC_FS_SHUTDOWN_EXIT                              = CATCHER_EXC_MODULES_SS,
  OWNER____SST_EXC_NVRAM_WRITE_EXC_ENTER                    = CATCHER_EXC_MODULES_NVRAM,
  OWNER____SST_EXC_NVRAM_WRITE_EXC_EXIT                       = CATCHER_EXC_MODULES_SS,
  OWNER____SST_EXC_TST_DUMP2FILE_ENTER                          = CATCHER_EXC_MODULES_TST,
  OWNER____SST_EXC_TST_DUMP2FILE_EXIT                            = CATCHER_EXC_MODULES_SS,
  OWNER____SST_EXC_DUMP_USB_DEBUG_DATA_ENTER           = CATCHER_EXC_MODULES_UARTUSB,
  OWNER____SST_EXC_DUMP_USB_DEBUG_DATA_EXIT              = CATCHER_EXC_MODULES_SS,
  OWNER____SST_EXC_HANDOVER2TST                                       = CATCHER_EXC_MODULES_TST,
}
catcher_exception_handler_owner_mapping_t;

typedef enum{
        sys_mem___Ken_Lin,
        dsp_mem___ChuWei_Lo,
        bb_reg___Ken_Lin,
        swla___Ken_Lin,
        fcore_mem___Fabian_Shih,
        fcore_swla___Fabian_Shih,
        ast_mem___Chuansheng_Zhang,
        mmv2_mem___Shuguang_Wen
}catcher_BEE_failed_readmem_owner;

#endif //#if defined(GEN_FOR_PC) 
 
#endif //__TST_CATCHER_DIAGONOSIS_INFO_H__
