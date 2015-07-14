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
 * tst_lga_hw.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file defines the data structures for LogAcc HW
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __TST_LGA_HW_H__
#define __TST_LGA_HW_H__

#include "kal_general_types.h"
#include "reg_base.h" //for UART1/2/3 and LogAcc Base address

#if defined(__LOGACC_ENABLE__)

//**********************************************************************************
//  Define compile options
//**********************************************************************************
#define __LOGACC_DUAL_INDIRECT_ENABLE__

#if !defined(MT6516)
  #define __LOGACC_DUAL_MASTER__  //indicate the dual master available
#endif  //!defined(MT6516)

//New features for MT6276 and MT6573
#if defined(MT6276) || defined(MT6573) || defined(MT6575) || defined(MT6577)
  //Enable LogAcc V2 feature sets
  //Including: disable PS escaping
  //           BW limit
  //           ATB Output
  //          [BugFix] Incorrect output length under indirect mode
  #define __LOGACC_V2_FEATURES__  
#endif  //#if defined(MT6276) || defined(MT6573)

//**********************************************************************************
//  Declare typedefs
//**********************************************************************************
typedef enum 
{
  Single_Direct_Dedicated,
  Single_Indirect,  
  Dual_Direct_Dedicated,
#ifdef __LOGACC_DUAL_INDIRECT_ENABLE__  
  Dual_Indirect,
#endif  //#ifdef __LOGACC_DUAL_INDIRECT_ENABLE__  
  Dual_PS_DD_L1_ID, //Direct Dedicated PS and Indirect L1
  Dual_PS_ID_L1_DD //Direct Dedicated L1 and Indirect PS
} LGA_MODE;

//The following block is used to feed in data for Logacc HISR
typedef struct
{
  kal_uint8 irq_trigger;  //0:non HW irq trigger, 1: triggered by HW irq
  kal_uint8 dma_processing;     //If DMA is working on the data; 0: idle, 1: DMA processing, 2: ready to send
  kal_uint8 log2sd_processing;  //If log2Sd is working
  kal_uint8 irq_status;         //LogAcc status bytes
  kal_uint32 enc_len;           //HW encoded len
  kal_uint32 sent_len;        //lga_last_lenSent = enc_len-unsent_len
}
lga_hisr_control_struct_t;


//**********************************************************************************
//  Declare external varaibles
//**********************************************************************************
extern kal_uint8 tst_lga_ps_indirect; //indicate if LogAcc is in the indirect mode
extern LGA_MODE log_acc_conf;
extern lga_hisr_control_struct_t lga_hisr_contro_data; //contro LogAcc HISR activation

//**********************************************************************************
//  Declare functions
//**********************************************************************************
void tst_lga_stop_workaround(void);
void Lga_reInit(unsigned int ps_ptr, unsigned int l1_ptr);
void tst_lga_mark_dma_sent_state(kal_bool dma_processing);
kal_uint32 tst_lga_get_encode_size(kal_uint32 irqStatus);
void tst_lga_trigger_ps_channel(void);

//**********************************************************************************
//  Define constant numbers
//**********************************************************************************
//The size of the L1 buffer which is similar with UART ISR Buffer
#ifdef MT6516
  //For smart phone projects (2G), we use the smaller memory
  #define L1TRC_LGA_BUFFER_SIZE 1024
#else	//#ifdef MT6516
  //For WCDMA projects, we use the larger memory as the buffer
  //Per Barry's request, enlarge L1 buffer to 8K to avoid L1 log lost
  #define L1TRC_LGA_BUFFER_SIZE (1<<13)
#endif	//#ifdef MT6516

#ifdef __TST_LGA_DVT__
  #define TST_ENCODED_BUFFER_SIZE (32)
#else //#ifdef __TST_LGA_DVT__
  #define TST_ENCODED_BUFFER_SIZE (4096)
#endif  //#ifdef __TST_LGA_DVT__

#ifdef __LOGACC_DUAL_INDIRECT_ENABLE__
  //Indirect mode is used for USB.
  //If there are two USBs, we can enable this features
  #define TST_ENCODED_BUFFER_SIZE_DuPS (1024)
#endif  //#ifdef __LOGACC_DUAL_INDIRECT_ENABLE__

#define TST_EVENT_TST_TASK_WAKEUP 0x020000

#ifdef __TST_LGA_DVT__
  //#define TST_RING_BUFFER_SIZE (1<<20)
  #define TST_RING_BUFFER_SIZE (1<<13)  //debug
#endif	//__TST_LGA_DVT__

//These addresses are defined in reg_base.h
#define LOGACC_UART1_base   UART1_base
#define LOGACC_UART2_base   UART2_base
#ifdef UART3_base
  #define LOGACC_UART3_base   UART3_base
#else //UART3_base
  #define LOGACC_UART3_base   0
#endif  //UART3_base

//Should define LOGACC_base in reg_base.h
#if !defined(LOGACC_base)
  #ifdef MT6516
    #define LOGACC_base         LA_base
  #else  
    #define LOGACC_base         LOG_base
  #endif
#endif  //LOGACC_base

#if !defined(IRQ_LA_CODE)
  #if defined(MT6270A) || defined(TK6280)  
    #define IRQ_LA_CODE         (1)  
  #endif  //#if defined(MT6270A) || defined(TK6280)     
#endif  //IRQ_LA_CODE

//Please refer to the data sheet
#if defined(MT6516)
  #define LOGACC_PWN_UP_base 0x811c0040
  #define LOGACC_PWN_WATCH_base 0x811c0000
  #define LOGACC_PWN_SET_FLAG 0x40000000
#elif defined(MT6268)	//#if defined(MT6516)
  #define LOGACC_PWN_UP_base (CONFIG_base+0x0324)
  #define LOGACC_PWN_WATCH_base (CONFIG_base+0x0304)
  #define LOGACC_PWN_SET_FLAG 0x1 
#elif defined(MT6270A) || defined(TK6280)//#if defined(MT6516)
  #define LOGACC_PWN_UP_base (CONFIG_base+0x0324)
  #define LOGACC_PWN_WATCH_base (CONFIG_base+0x0304)
  #define LOGACC_PWN_SET_FLAG 0x1   
#elif defined(MT6276)  
  #define LOGACC_PWN_UP_base (CONFIG_base+0x0324)
  #define LOGACC_PWN_WATCH_base (CONFIG_base+0x0304)
  #define LOGACC_PWN_SET_FLAG 0x1
  #if !defined(MT6276_S00)
    #define LOGACC_WAY_ENABLE_REG (CONFIG_base+0x0550)
    #define LOGACC_WAY_ENABLE_BIT (31)
  #endif  //#if !defined(MT6276_S00)
#elif defined(MT6573)  
  #define LOGACC_PWN_UP_base (CONFIG_base+0x0318)
  #define LOGACC_PWN_WATCH_base (CONFIG_base+0x0300)
  #define LOGACC_PWN_SET_FLAG 0x400 
#elif defined(MT6575)  
  #define LOGACC_PWN_UP_base (CONFIG_base+0x0324)
  #define LOGACC_PWN_WATCH_base (CONFIG_base+0x0304)
  #define LOGACC_PWN_SET_FLAG 0x1  
#elif defined(MT6577)  
  #define LOGACC_PWN_UP_base (CONFIG_base+0x0324)
  #define LOGACC_PWN_WATCH_base (CONFIG_base+0x0304)
  #define LOGACC_PWN_SET_FLAG 0x1   
#endif	//#if defined(MT6516)

#define LOGACC_CONTROL           (LOGACC_base+0x0000) /* Log Accelerator Control Setting */
/* Commands for LOGACC_CONTROL
*  LOGACC_CONTROL_Trig_L1      0x0001
*  LOGACC_CONTROL_Trig_PS      0x0002
*  LOGACC_CONTROL_DualMaster   0x0004
*  LOGACC_CONTROL_TxMode       0x0100
*  LOGACC_CONTROL_TxMode_DuPS  0x0200
*  LOGACC_CONTROL_TxUART       0x0400
*  LOGACC_CONTROL_TxUART_DuPS  0x0800
*  LOGACC_CONTROL_Reset        0x8000
*/

#define LOGACC_CONTROL_DISABLE      0x0       //The status that LogAcc is disabled.
#define LOGACC_CONTROL_Trig_L1      0x0001
#define LOGACC_CONTROL_Trig_PS      0x0002
#define LOGACC_CONTROL_TxMode       0x0100    /* Set direct or indirect mode*/
#define LOGACC_CONTROL_TxUART       0x0400    /* Set UART dedicated mode*/
#define LOGACC_CONTROL_DEBUG        0x4000    // Switch debug mode between L1 and PS
#define LOGACC_CONTROL_Reset        0x8000

#ifdef __LOGACC_DUAL_MASTER__
  #define LOGACC_CONTROL_DualMaster   0x0004
  #define LOGACC_CONTROL_TxMode_DuPS  0x0200    /* Set direct or indirect mode*/
  #define LOGACC_CONTROL_TxUART_DuPS  0x0800    /* Set UART dedicated mode*/
#endif //__LOGACC_DUAL_MASTER__

//New feature for MT6276 and MT6573
#ifdef __LOGACC_V2_FEATURES__
  #define LOGACC_CONTROL_No_PS_Escape        0x0008
  #define LOGACC_CONTROL_TxFIFO              0x1000
  
  #ifdef __LOGACC_DUAL_MASTER__
    #define LOGACC_CONTROL_TxFIFO_DuPS       0x2000
  #endif  //#ifdef __LOGACC_DUAL_MASTER__
#endif  //#ifdef __LOGACC_V2_FEATURES__

#define LOGACC_L1_IN_BUFFER_ADDR (LOGACC_base+0x0004) /* Address of L1 Input buffer      */
#define LOGACC_L1_IN_BUFFER_SIZE (LOGACC_base+0x0008) /* Size of L1 Input buffer         */
#define LOGACC_PS_IN_BUFFER_ADDR (LOGACC_base+0x000C) /* Address of PS Input buffer      */
#define LOGACC_PS_IN_BUFFER_SIZE (LOGACC_base+0x0010) /* Size of PS Input buffer         */
#define LOGACC_OUT_BUFFER_ADDR   (LOGACC_base+0x0014) /* Address of Output buffer (or UART)*/
#define LOGACC_OUT_BUFFER_SIZE   (LOGACC_base+0x0018) /* Size of Output buffer           */
#define LOGACC_ENCODED_DATA_SIZE (LOGACC_base+0x001C) /* Size of Encoded data            */
#define LOGACC_ENCODE_STATUS     (LOGACC_base+0x0020) /* Status of encoding              */
#define LOGACC_UART_SEL          (LOGACC_base+0x0024) /* which UART is using             */
#define LOGACC_L1_ENCODED_CURSOR (LOGACC_base+0x0028) /* Where in the L1 input buffer has been processed */
#define LOGACC_PS_ENCODED_CURSOR (LOGACC_base+0x002C) /* Where in the PS input buffer has been processed */

#ifdef __LOGACC_DUAL_MASTER__
  //<== added in 6268 for dual port option
  #define LOGACC_OUT_BUFFER_ADDR_DuPS   (LOGACC_base+0x0030) /* Address of Output buffer (or UART), for PS of Dual UART*/
  #define LOGACC_OUT_BUFFER_SIZE_DuPS   (LOGACC_base+0x0034) /* Size of Output buffer, for PS of Dual UART           */
  #define LOGACC_ENCODED_DATA_SIZE_DuPS (LOGACC_base+0x0038) /* Size of Encoded data, for PS of Dual UART            */
  #define LOGACC_ENCODE_STATUS_DuPS     (LOGACC_base+0x003C) /* Status of encoding, for PS of Dual UART              */
  #define LOGACC_UART_SEL_DuPS          (LOGACC_base+0x0040) /* which UART is using, for PS of Dual UART             */
#endif //#ifdef __LOGACC_DUAL_MASTER__

#define LOGACC_IRQ_STATUS             (LOGACC_base+0x0044) /* which TX0/TX1 fire a interrupt            */
#define LOGACC_DEBUG_STATE_MECHINE (LOGACC_base+0x0050) /* Log Accelerator Control Setting */

#if (defined(MT6276)&&!defined(MT6276_S00)) || defined(MT6575) || defined(MT6577)
  #define LOGACC_UART_SLOWDOWN_REG (LOGACC_base+0x007C) /* UART SLOW Down register*/
  #define LOGACC_UART_SLOWDOWN_VAL (0x44)
#endif  //#if (defined(MT6276)&&!defined(MT6276_S00))

//Core state
#define LOGACC_DEBUG_WORK_BYTE 0x0F0000
#define LOGACC_DEBUG_IDLE_STATE 0x10000
#define LOGACC_DEBUG_CHECK_STATE 0x20000
#define LOGACC_DEBUG_TX_STATE 0x40000
#define LOGACC_DEBUG_UPDATE_STATE 0x80000

//TX Sate
#define LOGACC_DEBUG_TX_BYTE 0xFFFF
#define LOGACC_DEBUG_TX_IDLE 0x1
#define LOGACC_DEBUG_TX_RD_CORE 0x2
#define LOGACC_DEBUG_TX_RD_BURST 0x4
#define LOGACC_DEBUG_TX_RD_SINGLE 0x8
#define LOGACC_DEBUG_TX_CHECKSUM 0x10
#define LOGACC_DEBUG_TX_SEL 0x20
#define LOGACC_DEBUG_TX_8 0x40
#define LOGACC_DEBUG_TX_4 0x80
#define LOGACC_DEBUG_TX_1 0x100
#define LOGACC_DEBUG_TX_WAIT_NEXT 0x200
#define LOGACC_DEBUG_TX_WAIT_FULL 0x400
#define LOGACC_DEBUG_TX_WAIT_UART 0x800
#define LOGACC_DEBUG_TX_REMAIN 0x1000


#define LOGACC_IRQ_TX0          0x01
#define LOGACC_IRQ_TX1          0x02

#ifdef __TST_LGA_EMI_LOG_DEBUG__
  #define TST_LGA_EM_LOG_SET_NUM 4096
  extern kal_bool tst_lga_emi_logger_start(void);
#endif  //#ifdef __TST_LGA_EMI_LOG_DEBUG__

#ifdef __LOGACC_V2_FEATURES__
  #define LOGACC_BUS_SLOW_DOWN_ADDR     (LOGACC_base+0x0048)  //bus slow down control register
  #define LOGACC_ATID_SET_ADDR          (LOGACC_base+0x0074)  //The register to set the ATID
  #define LOGACC_ATB_FIFO_Depth_ADDR    (LOGACC_base+0x0078)  //The register shows how much data in the FIFO
  
  //define the ATID of LOGACC
  #define LOGACC_INFO_ATID_1    (4)
  #define LOGACC_INFO_ATID_2    (5)
#endif  //#ifdef __LOGACC_V2_FEATURES__

#define LOGACC_MAX_BUF_SIZ (0xFFFFF0) //(1<<24 -1 )/16*16

//**********************************************************************************
//  Define Macro
//**********************************************************************************

#ifdef __TST_LGA_EMI_LOG_DEBUG__
  #define LOGACC_TriggerL1()	do { \
                                      *(volatile kal_uint32 *) LOGACC_CONTROL |= LOGACC_CONTROL_Trig_L1;\
                                       tst_lga_emi_logger_start();\
                                 } while (0)
  #define LOGACC_TriggerPS()	do { \
                                   if (!tst_lga_ps_indirect)  \
                                   {\
                                      *(volatile kal_uint32 *) LOGACC_CONTROL |= LOGACC_CONTROL_Trig_PS; \
                                      tst_lga_emi_logger_start();\
                                   }\
                                 } while (0)
#else //#ifdef __TST_LGA_EMI_LOG_DEBUG__
  #define LOGACC_TriggerL1()	do { *(volatile kal_uint32 *) LOGACC_CONTROL |= LOGACC_CONTROL_Trig_L1; } while (0)
  #define LOGACC_TriggerPS()	do { \
                                   if (!tst_lga_ps_indirect)  \
                                      *(volatile kal_uint32 *) LOGACC_CONTROL |= LOGACC_CONTROL_Trig_PS; \
                                 } while (0)
  
#endif  //#ifdef __TST_LGA_EMI_LOG_DEBUG__                 

#define LOGACC_ForceTriggerPS()	do {*(volatile kal_uint32 *) LOGACC_CONTROL |= LOGACC_CONTROL_Trig_PS; } while (0)
#define LOGACC_SetDirectMode()	do { *(volatile kal_uint32 *) LOGACC_CONTROL |= LOGACC_CONTROL_TxMode; } while (0)
#define LOGACC_SetIndirectMode() do { *(volatile kal_uint32 *) LOGACC_CONTROL &= (~LOGACC_CONTROL_TxMode); } while (0)
//Do not change the setting of Dedicated UART while transmission
//Force set to direct mode
#define LOGACC_SetDedicatedUART() \
   do {\
        *(volatile kal_uint32 *) LOGACC_CONTROL |= LOGACC_CONTROL_TxMode; \
        *(volatile kal_uint32 *) LOGACC_CONTROL |= LOGACC_CONTROL_TxUART; \
   }while(0)
#define LOGACC_UnsetDedicatedUART() do{*(volatile kal_uint32 *) LOGACC_CONTROL &= (~LOGACC_CONTROL_TxUART);}while(0)
#define LOGACC_Reset_Start_HW() do { *(volatile kal_uint32 *) LOGACC_CONTROL |= LOGACC_CONTROL_Reset; } while (0)
#define LOGACC_Reset_Stop_HW() do { *(volatile kal_uint32 *) LOGACC_CONTROL &= (~LOGACC_CONTROL_Reset); } while (0)
#define LOGACC_GetControlStatus(status) do { status = *(volatile kal_uint32 *) LOGACC_CONTROL; } while (0)
#define LOGACC_DisableAll() do { *(volatile kal_uint32 *) LOGACC_CONTROL &= LOGACC_CONTROL_DISABLE; } while (0)

//switch the debug mode between L1 and PS
#define LOGACC_Switch_Debug_Mode() do{*(volatile kal_uint32 *) LOGACC_CONTROL ^= LOGACC_CONTROL_DEBUG;}while(0)
#define LOGACC_Switch_L1_Debug_Mode() do{*(volatile kal_uint32 *) LOGACC_CONTROL &= (~LOGACC_CONTROL_DEBUG);}while(0)
#define LOGACC_Switch_PS_Debug_Mode() do{*(volatile kal_uint32 *) LOGACC_CONTROL |= LOGACC_CONTROL_DEBUG;}while(0)


#define LOGACC_SetL1InBuffer(addr, size) \
  do { \
    *(volatile kal_uint32 *) LOGACC_L1_IN_BUFFER_ADDR = (kal_uint32)addr; \
    *(volatile kal_uint32 *) LOGACC_L1_IN_BUFFER_SIZE = size; \
  } while (0)
  
#define LOGACC_SetPSInBuffer(addr, size) \
  do { \
    *(volatile kal_uint32 *) LOGACC_PS_IN_BUFFER_ADDR = (kal_uint32)addr; \
    *(volatile kal_uint32 *) LOGACC_PS_IN_BUFFER_SIZE = size; \
  } while (0)

#define LOGACC_SetOutBufferIndirectMode(addr, size) \
  do { \
    *(volatile kal_uint32 *) LOGACC_OUT_BUFFER_ADDR = (kal_uint32)addr; \
    *(volatile kal_uint32 *) LOGACC_OUT_BUFFER_SIZE = size; \
  } while (0)

#ifdef __LOGACC_DUAL_MASTER__      
  #define LOGACC_SetOutputBufferDirectMode(port) \
    do { \
      if (port == uart_port1) { *(volatile kal_uint32 *) LOGACC_OUT_BUFFER_ADDR = LOGACC_UART1_base;\
                                *(volatile kal_uint32 *) LOGACC_UART_SEL = 0x01;} \
      else if (port == uart_port2) { *(volatile kal_uint32 *) LOGACC_OUT_BUFFER_ADDR = LOGACC_UART2_base; \
                                *(volatile kal_uint32 *) LOGACC_UART_SEL = 0x02;} \
      else if (port == uart_port3) { *(volatile kal_uint32 *) LOGACC_OUT_BUFFER_ADDR = LOGACC_UART3_base;\
                                *(volatile kal_uint32 *) LOGACC_UART_SEL = 0x04;} \
    } while (0)
#else //__LOGACC_DUAL_MASTER__    
  #define LOGACC_SetOutputBufferDirectMode(port) \
    do { \
      if (port == uart_port1) { *(volatile kal_uint32 *) LOGACC_OUT_BUFFER_ADDR = LOGACC_UART1_base;\
                                *(volatile kal_uint32 *) LOGACC_UART_SEL = 0x01;} \
      else if (port == uart_port2) { *(volatile kal_uint32 *) LOGACC_OUT_BUFFER_ADDR = LOGACC_UART2_base; \
                                *(volatile kal_uint32 *) LOGACC_UART_SEL = 0x02;} \
    } while (0)
#endif //__LOGACC_DUAL_MASTER__    

#define LOGACC_GetEncodedDataSize(size)  do { size = *(volatile kal_uint32 *) LOGACC_ENCODED_DATA_SIZE; } while (0)
#define LOGACC_TriggerContinueEncoding() do { *(volatile kal_uint32 *) LOGACC_ENCODE_STATUS = 0x00; } while (0)
#define LOGACC_GetTriggerEncodingState(status) do { status = *(volatile kal_uint32 *) LOGACC_ENCODE_STATUS; } while (0)
  
  
#define LOGACC_GetL1BufferCursor(addr) do { addr = *(volatile kal_uint32 *) LOGACC_L1_ENCODED_CURSOR; } while (0)
  
//Patch for MT6268 LogAcc SW Workaround
#ifdef __TST_STOP_LGA_UNDER_USB__
  extern kal_bool tst_usb_logging_port_used;
  extern kal_uint32 tst_ptr_buffer_start;
  #define LOGACC_GetPSBufferCursor(addr) do { \
                                          if (tst_usb_logging_port_used)\
                                            addr = tst_ptr_buffer_start;\
                                          else\
                                            addr = *(volatile kal_uint32 *) LOGACC_PS_ENCODED_CURSOR;\
                                          } while (0)
#else //#ifdef __TST_STOP_LGA_UNDER_USB__
  #define LOGACC_GetPSBufferCursor(addr) do { addr = *(volatile kal_uint32 *) LOGACC_PS_ENCODED_CURSOR; } while (0)
#endif  //#ifdef __TST_STOP_LGA_UNDER_USB__

//<=== added in 6268 for dual port option
#ifdef __LOGACC_DUAL_MASTER__   
  #define LOGACC_EnableDualMaster()	do { *(volatile kal_uint32 *) LOGACC_CONTROL |= LOGACC_CONTROL_DualMaster; } while (0)
  #define LOGACC_DisableDualMaster()	do { *(volatile kal_uint32 *) LOGACC_CONTROL &= (~LOGACC_CONTROL_DualMaster); } while (0)
  #define LOGACC_SetDirectModeDuPS()	do { *(volatile kal_uint32 *) LOGACC_CONTROL |= LOGACC_CONTROL_TxMode_DuPS; } while (0)
  #define LOGACC_SetIndirectModeDuPS() do { *(volatile kal_uint32 *) LOGACC_CONTROL &= (~LOGACC_CONTROL_TxMode_DuPS); } while (0)
  
  //Do not change the setting of Dedicated UART while transmission
  //Force set to direct mode
  #define LOGACC_SetDedicatedUARTDuPS() \
     do {\
          *(volatile kal_uint32 *) LOGACC_CONTROL |= LOGACC_CONTROL_TxMode_DuPS; \
          *(volatile kal_uint32 *) LOGACC_CONTROL |= LOGACC_CONTROL_TxUART_DuPS; \
     }while(0)
  #define LOGACC_UnsetDedicatedUARTDuPS() do{*(volatile kal_uint32 *) LOGACC_CONTROL &= (~LOGACC_CONTROL_TxUART_DuPS);}while(0)
  
  #define LOGACC_SetOutBufferIndirectModeDuPS(addr, size) \
    do { \
      *(volatile kal_uint32 *) LOGACC_OUT_BUFFER_ADDR_DuPS = (kal_uint32)addr; \
      *(volatile kal_uint32 *) LOGACC_OUT_BUFFER_SIZE_DuPS = size; \
    } while (0)
  
  #define LOGACC_SetOutputBufferDirectModeDuPS(port) \
    do { \
      if (port == uart_port1) { *(volatile kal_uint32 *) LOGACC_OUT_BUFFER_ADDR_DuPS = LOGACC_UART1_base;\
                                *(volatile kal_uint32 *) LOGACC_UART_SEL_DuPS = 0x01;} \
      else if (port == uart_port2) { *(volatile kal_uint32 *) LOGACC_OUT_BUFFER_ADDR_DuPS = LOGACC_UART2_base;\
                                *(volatile kal_uint32 *) LOGACC_UART_SEL_DuPS = 0x02;} \
      else if (port == uart_port3) { *(volatile kal_uint32 *) LOGACC_OUT_BUFFER_ADDR_DuPS = LOGACC_UART3_base;\
                                *(volatile kal_uint32 *) LOGACC_UART_SEL_DuPS = 0x04;} \
    } while (0)
  
  #define LOGACC_GetEncodedDataSizeDuPS(size)  do { size = *(volatile kal_uint32 *) LOGACC_ENCODED_DATA_SIZE_DuPS; } while (0)
  #define LOGACC_TriggerContinueEncodingDuPS() do { *(volatile kal_uint32 *) LOGACC_ENCODE_STATUS_DuPS = 0x00; } while (0)
  #define LOGACC_GetTriggerEncodingStateDuPS(status) do { status = *(volatile kal_uint32 *) LOGACC_ENCODE_STATUS_DuPS; } while (0)
#else //#ifdef __LOGACC_DUAL_MASTER__ 
  #define LOGACC_DisableDualMaster()	do { ; } while (0)
  #define LOGACC_GetEncodedDataSizeDuPS(size) do{size=0;}while(0)
#endif //#ifdef __LOGACC_DUAL_MASTER__   

#define LOGACC_GetIRQStatus(status) do { status = *(volatile kal_uint16 *) LOGACC_IRQ_STATUS;} while (0)

//#define LOGACC_COSIM_LOG(ch) do { *(volatile kal_uint8 *) LOGACC_COSIM_LOG_ADDR = ch; } while (0)

//#undef __LOGACC_DUAL_MASTER__ 

//check if LogAcc is idle

#define LOGACC_DEBUG_WORKING_STATE(status) do {\
                                                status = *(volatile kal_uint32 *) LOGACC_DEBUG_STATE_MECHINE;\
                                                status &= LOGACC_DEBUG_WORK_BYTE;\
                                              }while(0)
                                              
#define LOGACC_DEBUG_GET_TX_STATE(status) do {\
                                                status = *(volatile kal_uint32 *) LOGACC_DEBUG_STATE_MECHINE;\
                                                status &= LOGACC_DEBUG_TX_BYTE;\
                                              }while(0)                                              

//power on LogAcc at bit 30 of 
#ifdef LOGACC_PWN_UP_base
  #define LOGACC_Power_Up()	do {*(volatile kal_uint32 *) LOGACC_PWN_UP_base |= LOGACC_PWN_SET_FLAG;}while(0)
  #define LOGACC_Check_Power_Up(status) do {\
                                       			 if (((*(volatile kal_uint32 *) LOGACC_PWN_WATCH_base) & LOGACC_PWN_SET_FLAG) == 0)\
                                       				 status = 1;\
                                       			 else\
                                       			 	 status = 0;\
                                     			 }while(0)
#else	////LOGACC_PWN_UP_base
  #define LOGACC_Power_Up()	do {;}while(0)
  #define LOGACC_Check_Power_Up(status) do{status=1;}while(0)
#endif	//LOGACC_PWN_UP_base

//New feature for MT6276 and MT6573
#ifdef __LOGACC_V2_FEATURES__
  #define LOGACC_DISABLE_PS_ESCAPING() do{*(volatile kal_uint32 *) LOGACC_CONTROL |= LOGACC_CONTROL_No_PS_Escape;}while(0)
  #define LOGACC_ENABLE_TX_FIFO_MODE() do{*(volatile kal_uint32 *) LOGACC_CONTROL |= LOGACC_CONTROL_TxFIFO;}while(0)
  
  //Unit: 4T
  #define LOGACC_SET_SLOW_DOWN_COUNT(val) do{*(volatile kal_uint32 *) LOGACC_BUS_SLOW_DOWN_ADDR |= (val&0xFF);}while(0)  
  
  #define LOGACC_SET_TX_ATID(id) do{*(volatile kal_uint32 *) LOGACC_ATID_SET_ADDR |= (id&0x7F);}while(0)  
  #define LOGACC_GET_TX_ATB_FIFO_DEPTH(depth) do{depth = ((*(volatile kal_uint32 *) LOGACC_ATB_FIFO_Depth_ADDR)&0xFF);}while(0)  
  #define LOGACC_SET_L1_READ_PTR(ptr) do{*(volatile kal_uint32*)LOGACC_L1_ENCODED_CURSOR = ptr;}while(0)
  #define LOGACC_SET_PS_READ_PTR(ptr) do{*(volatile kal_uint32*)LOGACC_PS_ENCODED_CURSOR = ptr;}while(0)
  
  #ifdef __LOGACC_DUAL_MASTER__
    #define LOGACC_ENABLE_TX_FIFO_MODE_DuPS() do{*(volatile kal_uint32 *) LOGACC_CONTROL |= LOGACC_CONTROL_TxFIFO_DuPS;}while(0)    
    #define LOGACC_SET_SLOW_DOWN_COUNT_DuPS(val) do{*(volatile kal_uint32 *) LOGACC_BUS_SLOW_DOWN_ADDR |= ((val<<8)&0xFF00);}while(0)
    #define LOGACC_SET_TX_ATID_DuPS(id) do{*(volatile kal_uint32 *) LOGACC_ATID_SET_ADDR |= ((id<<8)&0x7F00);}while(0)  
    #define LOGACC_GET_TX_ATB_FIFO_DEPTH_DuPS(depth) do{depth = ((*(volatile kal_uint32 *) LOGACC_ATB_FIFO_Depth_ADDR)>>8&0xFF);}while(0)  
  #endif  //#ifdef __LOGACC_DUAL_MASTER__

#else //__LOGACC_V2_FEATURES__
  #define LOGACC_SET_L1_READ_PTR(ptr) do { ; } while (0)
  #define LOGACC_SET_PS_READ_PTR(ptr) do { ; } while (0)
#endif  //__LOGACC_V2_FEATURES__

#ifdef LOGACC_WAY_ENABLE_REG
  #define LOGACC_SET_WAY_ENABLE() do{*(volatile kal_uint32 *) LOGACC_WAY_ENABLE_REG |= ((kal_uint32)1<<LOGACC_WAY_ENABLE_BIT);}while(0)    
#else
  #define LOGACC_SET_WAY_ENABLE() do { ; } while (0)
#endif  //LOGACC_WAY_ENABLE_REG

#ifdef LOGACC_UART_SLOWDOWN_REG
  #define LOGACC_SET_UART_SLOW_DOWN() do{*(volatile kal_uint32 *) LOGACC_UART_SLOWDOWN_REG |= LOGACC_UART_SLOWDOWN_VAL;}while(0)    
#else //LOGACC_UART_SLOWDOWN_REG
  #define LOGACC_SET_UART_SLOW_DOWN() do { ; } while (0)
#endif  //LOGACC_UART_SLOWDOWN_REG

#define LOGACC_GET_CUR_READ_LEN(len) do{len = *(volatile int*) (LOGACC_base+0x5c);}while (0)

#endif  //#if defined(__LOGACC_ENABLE__)
#endif  //__TST_LGA_HW_H__
