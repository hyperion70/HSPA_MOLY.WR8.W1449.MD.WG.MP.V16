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
 * tst_lmu_hw.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file defines the data structures for LMU HW
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __TST_LMU_HW_H__
#define __TST_LMU_HW_H__

//Integrate ALC CSM writing into header to avoid the possible modification for SS team
#ifdef __TST_MALMO_SUPPORT__
  #include "MalmoDriver.h"
  extern unsigned char tst_alc_logging_enable;
  #ifndef __TST_MALMO_UT__
    #define ALC_WRITE_CSM(id) do{if (tst_alc_logging_enable){ALC_SEND_CSM(id);} }while(0)  
  #else //__TST_MALMO_UT__
    #define ALC_WRITE_CSM(id) tst_alc_write_csm(id)
  #endif  //__TST_MALMO_UT__
#else //__TST_MALMO_SUPPORT__
  #define ALC_WRITE_CSM(id) do{;}while(0)  
#endif  //__TST_MALMO_SUPPORT__

#if defined(__TST_LMU_LOGGING__) || defined(USE_DNT_LOGGING)

#if defined(__MTK_TARGET__)
  #include "intrCtrl.h"
  #include "tst_coresight_control.h"
  #include "reg_base.h"  
#else //__MTK_TARGET__
  #define LMU_ARM11_base (0x600E0000)
  #define LMU_FCORE4_base (0x600F0000)
  #define LMU_ARM11_AXI_SD_base (0x66000000)  
#endif  //__MTK_TARGET__

/*************************************************************************
* Definition declaration
 *************************************************************************/
 
//*************************************************************************
//LMU basic address configuration

#if !defined(__TST_ON_AOS__) && !defined(__FCORE__)
  //ARM side
  #define LMU_APB_BASE_ADDR LMU_ARM11_base   
  #define LMU_AXI_BASE_ADDR LMU_ARM11_AXI_SD_base  
  #define IRQ_LMU_CODE IRQ_LMU_MD_CODE  
  #define LMU_ATID_NUM ATID_LMU_MDARM  
#else
  //FCore side
  #define LMU_APB_BASE_ADDR LMU_FCORE4_base  
  #define LMU_AXI_BASE_ADDR LMU_FCORE4_AXI_SD_base  
  #define IRQ_LMU_CODE IRQ_LMU_DSP_CODE  
  #define LMU_ATID_NUM ATID_LMU_FCore4
#endif   

#if defined (MT6276) || defined (BB_MT6276) || defined(TK6280) || defined(BB_TK6280) 
  #define LMU_AXI_PROTECTION_ADDR (CONFIG_base+0x0550)
  
  #if !defined(__TST_ON_AOS__) && !defined(__FCORE__)    
    #define LMU_DISABLE_AXI_PROTECTION_BYTE (0x100)
  #else    
    #define LMU_DISABLE_AXI_PROTECTION_BYTE (0x200)
  #endif    
  
#elif defined (MT6573) || defined (BB_MT6573)  
  #define LMU_AXI_PROTECTION_ADDR (CONFIG_base+0x0428)
  
  #if !defined(__TST_ON_AOS__) && !defined(__FCORE__)    
    #define LMU_DISABLE_AXI_PROTECTION_BYTE (0x2)
  #else
    #define LMU_DISABLE_AXI_PROTECTION_BYTE (0x8)  
  #endif
  
#elif defined (MT6280) || defined (BB_MT6280)  
  #define MD_BUS_CONFIC_CONTROL (CONFIG_base+0x040)
  #define LMU_WAY_ENABLE_CODE (0x00018000)  
#else
  #error "Non-Supported platforms for LMU"
#endif  

#if defined (MT6276) || defined (BB_MT6276) || defined(TK6280) || defined(BB_TK6280) || defined (MT6573) || defined (BB_MT6573) 
    #define LMU_Bus_Way_Enable() do { \
                *(volatile unsigned int*) LMU_AXI_PROTECTION_ADDR |= LMU_DISABLE_AXI_PROTECTION_BYTE;\
            } while (0)
#elif defined (MT6280) || defined (BB_MT6280)  
    #define LMU_Bus_Way_Enable() do { \
                *(volatile unsigned int*) MD_BUS_CONFIC_CONTROL |= LMU_WAY_ENABLE_CODE;\
            } while (0)
#else
    #error "Non-Supported platforms for LMU"
#endif  
		
//The end of user defined LMU settings
//*************************************************************************

//*************************************************************************
//user defined LMU settings
#define LMU_USR_CONFIG_LMU_ENABLE 1

#define LMU_USR_CONFIG_CCSM_ENABLE 1

#define LMU_USR_CONFIG_FLUSH_ENABLE 0
#define LMU_USR_CONFIG_FIFO_SIZE (0x1000-1) //4KB
#define LMU_USR_CONFIG_BULK_FIFO_SIZE (0xc00-1)  //3KB, 75%
#define LMU_USR_CONFIG_DROP_RESUME_FIFO_SIZE 0x800  //2KB, 50%
#define LMU_USR_CONFIG_MAX_THROUGHPUT 0x10000  //64KB
#define LMU_USR_CONFIG_BULK_FULL_STALL_VAL 0x3  //3 emi cycles
#define LMU_USR_CONFIG_IRQ_MASK 0xF //all on
#define LMU_USR_CONFIG_ESCAPE_PATTERN 0xE5CF  //The pattern should be 0xE5CF????
#define LMU_USR_CONFIG_RESYNC_PATTERN 0xDBAC //2's complement of 0x2454
//The end of user defined LMU settings
//*************************************************************************
 
 
//*************************************************************************
//The LMU configuration related definitions

//The configuration registers for LMU
#define LMU_CONFIG_ADDR (LMU_APB_BASE_ADDR+0x0)  //point to CONFIG_ENABLES[15:0]
#define LMU_ENABLE_FLAG 0x1 //enable LMU
#define LMU_DISABLE_FLAG 0xFFFE //disable LMU, used for the power saving
#define LMU_CCSM_ENABLE_FLAG 0x2 //enable the conditional context switch marker
#define LMU_CCSM_DISABLE_FLAG 0xFFFD //disable the conditional context switch marker
#define LMU_FLUSH_ENABLE_FLAG 0x4 //Drop all incomming writes to LMU
#define LMU_FLUSH_DISABLE_FLAG 0xFFFB //Start to accept incomming write

//The register to set the ESC pattern
#define LMU_CONFIG_ESC_PATTERN_ADDR (LMU_APB_BASE_ADDR+0x4)  //point to ESC_SEQUENCE[15:0]

//The FIFO size setting register
#define LMU_CONFIG_FIFO_SIZE_ADDR (LMU_APB_BASE_ADDR+0x8) //point to FIFO_SIZE[15:0]

//The bulk FIFO size setting register
#define LMU_CONFIG_BULK_FIFO_MARKER_ADDR (LMU_APB_BASE_ADDR+0xC) //point to BULK_FIFO_MARKER[15:0]

//The register to set how many EMI cycles LMU should stall when the Bulk FIFO is full
#define LMU_CONFIG_BULK_FIFO_FULL_STALL_VAL_ADDR (LMU_APB_BASE_ADDR+0x1C) //point to BULK_WRITE_STALL_VAL[15:0]

//The register to set the IRQ mask
#define LMU_CONFIG_IRQ_MASK_ADDR (LMU_APB_BASE_ADDR+0x24)  //point to IRQ_MASK[15:0]

//The register to cpnfig ATID
#define LMU_CONFIG_ATID_ADDR (LMU_APB_BASE_ADDR+0x28)  //point to ATID[6:0]

//The end of the LMU configuration related definitions
//*************************************************************************


//*************************************************************************
//The LMU status related definitions

//The register to get/reset the current short msg stall count
#define LMU_INFO_SHORT_MSG_STALL_CNT_ADDR (LMU_APB_BASE_ADDR+0x10) //point to SHORTMSG_STALL_CNT[15:0]

//The register to get/reset the current bulk msg stall count
#define LMU_INFO_BULK_MSG_STALL_CNT_ADDR (LMU_APB_BASE_ADDR+0x14) //point to BULKMSG_STALL_CNT[15:0]

//The register to get the current FIFO depth
#define LMU_INFO_FIFO_DEPTH_ADDR (LMU_APB_BASE_ADDR+0x18)  //point to FIFO_DEPTH _STATUS[15:0]

//The register to show the current IRQ status
#define LMU_INFO_IRQ_STAT_ADDR (LMU_APB_BASE_ADDR+0x20)  //point to IRQ_STATUS[15:0]
#define LMU_INFO_IRQ_FIFO_FULL_VAL 0x1
#define LMU_INFO_IRQ_BULK_FIFO_FULL_VAL 0x2
#define LMU_INFO_IRQ_SHORT_MSG_STALL_CNT_OVR_VAL 0x4
#define LMU_INFO_IRQ_BULK_MSG_STALL_CNT_OVR_VAL 0x8

#define LMU_FIFO_FULL_HANDLE_INTERVAL (8)
#define LMU_FIFO_BULK_FULL_HANDLE_INTERVAL (16)

//The end of LMU status related definitions
//*************************************************************************

//*************************************************************************
//The start of LMU Data transfer register 

//The register to write L1 traces
#define LMU_SHORT_DATA_ADDR (LMU_AXI_BASE_ADDR+0x20) //point to SHORT_DATA[31:0]
#define LMU_SHORT_DATA_TS_ADDR (LMU_AXI_BASE_ADDR+0x120)  //point to SHORT_DATA_TS[31:0]
#define LMU_BULK_DATA_ADDR (LMU_AXI_BASE_ADDR+0xA0) //point to BULK_DATA[31:0]
#define LMU_BULK_DATA_TS_ADDR (LMU_AXI_BASE_ADDR+0x124)  //point to BULK_DATA_TS[31:0]  


//The register to emit <ESC><X>
#define LMU_ESC_X_ADDR (LMU_AXI_BASE_ADDR+0x128) //point to LMU_ESC_X[31:0]
#define LMU_ESC_X_TS_ADDR (LMU_AXI_BASE_ADDR+0x12C) //point to LMU_ESC_TS_X[31:0]

//TODO: define the final CSM value for task and LISR
#define LMU_WORD_CSM_TASK_VALUE 0x0
#define LMU_WORD_CSM_ISR_VALUE 0x8001
#define LMU_WORD_CSM_ISR_END_VALUE 0x8002
#define LMU_WORD_SWLA_TASK_VALUE 0x8000
#define LMU_WORD_SWLA_ISR_VALUE 0x8001
#define LMU_WORD_SWLA_ISR_END_VALUE 0x8002
#define LMU_WORD_SWLA_TAG_VALUE 0x8003
#define LMU_WORD_CSM_REG_LAYOUT_GAP 4

//The basic register of LMU ESC register
//TODO: specify the right address to write CSM
#define LMU_WORD_CSM_BASE_ADDR (LMU_AXI_BASE_ADDR+0x130)
//with timestamp
#define LMU_WORD_CSM_BASE_TS_ADDR (LMU_AXI_BASE_ADDR+0x40130)

#define LMU_WORD_CSM_TASK_ADDR (LMU_WORD_CSM_BASE_ADDR+LMU_WORD_CSM_TASK_VALUE*LMU_WORD_CSM_REG_LAYOUT_GAP)
#define LMU_WORD_CSM_TASK_TS_ADDR (LMU_WORD_CSM_BASE_TS_ADDR+LMU_WORD_CSM_TASK_VALUE*LMU_WORD_CSM_REG_LAYOUT_GAP)

#define LMU_WORD_CSM_ISR_ADDR (LMU_WORD_CSM_BASE_ADDR+LMU_WORD_CSM_ISR_VALUE*LMU_WORD_CSM_REG_LAYOUT_GAP)
#define LMU_WORD_CSM_ISR_TS_ADDR (LMU_WORD_CSM_BASE_TS_ADDR+LMU_WORD_CSM_ISR_VALUE*LMU_WORD_CSM_REG_LAYOUT_GAP)

#define LMU_WORD_CSM_ISR_END_ADDR (LMU_WORD_CSM_BASE_ADDR+LMU_WORD_CSM_ISR_END_VALUE*LMU_WORD_CSM_REG_LAYOUT_GAP)
#define LMU_WORD_CSM_ISR_END_TS_ADDR (LMU_WORD_CSM_BASE_TS_ADDR+LMU_WORD_CSM_ISR_END_VALUE*LMU_WORD_CSM_REG_LAYOUT_GAP)

#define LMU_WORD_SWLA_TASK_ADDR (LMU_WORD_CSM_BASE_ADDR+LMU_WORD_SWLA_TASK_VALUE*LMU_WORD_CSM_REG_LAYOUT_GAP)
#define LMU_WORD_SWLA_TASK_TS_ADDR (LMU_WORD_CSM_BASE_TS_ADDR+LMU_WORD_SWLA_TASK_VALUE*LMU_WORD_CSM_REG_LAYOUT_GAP)

#define LMU_WORD_SWLA_ISR_ADDR (LMU_WORD_CSM_BASE_ADDR+LMU_WORD_SWLA_ISR_VALUE*LMU_WORD_CSM_REG_LAYOUT_GAP)
#define LMU_WORD_SWLA_ISR_TS_ADDR (LMU_WORD_CSM_BASE_TS_ADDR+LMU_WORD_SWLA_ISR_VALUE*LMU_WORD_CSM_REG_LAYOUT_GAP)

#define LMU_WORD_SWLA_ISR_END_ADDR (LMU_WORD_CSM_BASE_ADDR+LMU_WORD_SWLA_ISR_END_VALUE*LMU_WORD_CSM_REG_LAYOUT_GAP)
#define LMU_WORD_SWLA_ISR_END_TS_ADDR (LMU_WORD_CSM_BASE_TS_ADDR+LMU_WORD_SWLA_ISR_END_VALUE*LMU_WORD_CSM_REG_LAYOUT_GAP)

#define LMU_WORD_SWLA_TAG_ADDR (LMU_WORD_CSM_BASE_ADDR+LMU_WORD_SWLA_TAG_VALUE*LMU_WORD_CSM_REG_LAYOUT_GAP)
#define LMU_WORD_SWLA_TAG_TS_ADDR (LMU_WORD_CSM_BASE_TS_ADDR+LMU_WORD_SWLA_TAG_VALUE*LMU_WORD_CSM_REG_LAYOUT_GAP)

//The end of LMU Data transfer register
//*************************************************************************

#if !defined(_LANGUAGE_ASM)

typedef enum
{
  ENUM_TST_LMU_PS_LOG,
  ENUM_TST_LMU_L1_LOG
} TST_LMU_Log_type_t;

#endif  /* !defined(_LANGUAGE_ASM) */

/*************************************************************************
* Function declaration
 *************************************************************************/


/*************************************************************************
* Global variable declaration
 *************************************************************************/

/*************************************************************************
* Macros declaration
 *************************************************************************/

//*************************************************************************
//The begin of the LMU configuration commands
//enable or disable LMU
#define LMU_Config_Enable(setting) do {\
                                    if ( (setting&0x1) == 1)\
                                      *(volatile unsigned int*) LMU_CONFIG_ADDR |= LMU_ENABLE_FLAG;\
                                    else\
                                      *(volatile unsigned int*) LMU_CONFIG_ADDR &= LMU_DISABLE_FLAG;\
                                 } while (0) 


//enable or disable the conditional context switch marker
#define LMU_Config_CCSM_Enable(setting) do { \
                                    if ( (setting&0x1) == 1)\
                                      *(volatile unsigned int*) LMU_CONFIG_ADDR |= LMU_CCSM_ENABLE_FLAG;\
                                    else\
                                      *(volatile unsigned int*) LMU_CONFIG_ADDR &= LMU_CCSM_DISABLE_FLAG;\
                                 } while (0) 
                               
//start or stop the incomming writes to LMU
#define LMU_Config_Flush_Enable(setting) do { \
                                    if ( (setting&0x1) == 1)\
                                      *(volatile unsigned int*) LMU_CONFIG_ADDR |= LMU_FLUSH_ENABLE_FLAG;\
                                    else\
                                      *(volatile unsigned int*) LMU_CONFIG_ADDR &= LMU_FLUSH_DISABLE_FLAG;\
                                 } while (0) 
                               
//set the LMU FIFO size
//The default size is 0xFFFF
#define LMU_Config_FIFO_Size(fifo_size) do { \
                                    *(volatile unsigned int*) LMU_CONFIG_FIFO_SIZE_ADDR = fifo_size;\
                                 } while (0) 

//Set the LMU bulk FIFO size                           
#define LMU_Config_Bulk_FIFO_Size(fifo_size) do { \
                                    *(volatile unsigned int*) LMU_CONFIG_BULK_FIFO_MARKER_ADDR = fifo_size;\
                                 } while (0)                                

//Set up how many cycles PS should wait when the bulk FIFO is full
#define LMU_Config_Bulk_Full_Stall_Cycles(stall_cycle) do { \
                                    *(volatile unsigned int*) LMU_CONFIG_BULK_FIFO_FULL_STALL_VAL_ADDR = stall_cycle;\
                                 } while (0)   

//Set the IRQ mask of the LMU
#define LMU_Config_IRQ_Mask(irq_mask) do { \
                                  *(volatile unsigned int*) LMU_CONFIG_IRQ_MASK_ADDR = (irq_mask&0xF);\
                               } while (0)   

//Get the IRQ mask of the LMU
#define LMU_Get_IRQ_Mask(irq_mask) do { \
                                  irq_mask = *(volatile unsigned int*) LMU_CONFIG_IRQ_MASK_ADDR;\
                               } while (0)   

//Set the IRQ mask of the LMU
#define LMU_Config_ATID(atid) do { \
                                  *(volatile unsigned int*) LMU_CONFIG_ATID_ADDR = (atid&0xFF);\
                               } while (0)   

//config the LMU ESC word pattern
#define LMU_Config_ESC_Pattern(esc_pattern) do { \
                                    *(volatile unsigned int*) LMU_CONFIG_ESC_PATTERN_ADDR = esc_pattern;\
                                 } while (0)                                   

//The end of the LMU configuration commands
//*************************************************************************

//*************************************************************************
//The start of the LMU information retrieval commands
//get the stall cnt of the short msg
#define LMU_Info_Get_Short_Msg_Stall_Cnt(stall_cnt) do { \
                                  stall_cnt = *(volatile unsigned int*) LMU_INFO_SHORT_MSG_STALL_CNT_ADDR;\
                               } while (0)
                               
//reset the stall cnt of the short msg
#define LMU_Info_Reset_Short_Msg_Stall_Cnt() do { \
                                  *(volatile unsigned int*) LMU_INFO_SHORT_MSG_STALL_CNT_ADDR=0;\
                               } while (0)
                               
//get the stall cnt of the bulk msg
#define LMU_Info_Get_Bulk_Msg_Stall_Cnt(stall_cnt) do { \
                                  stall_cnt = *(volatile unsigned int*) LMU_INFO_BULK_MSG_STALL_CNT_ADDR;\
                               } while (0)
                               
//reset the stall cnt of the bulk msg
#define LMU_Info_Reset_Bulk_Msg_Stall_Cnt() do { \
                                  *(volatile unsigned int*) LMU_INFO_BULK_MSG_STALL_CNT_ADDR=0;\
                               } while (0)                               
                               
//get the FIFO depth
#define LMU_Info_Get_Current_FIFO_Usage(fifo_usage) do { \
                                    fifo_usage = *(volatile unsigned int*) LMU_INFO_FIFO_DEPTH_ADDR;\
                                 } while (0)    

//get/reset the info about stall cnt overflow

//get the irq status when LMU launches a interrupt
#define LMU_Info_Get_LMU_IRQ_Status(status) do { \
                                    status = *(volatile unsigned int*) LMU_INFO_IRQ_STAT_ADDR;\
                                 } while (0)

//reset the status bits of LMU IRQ status
//W1C
#define LMU_Info_Reset_LMU_IRQ_Status() do { \
                                    *(volatile unsigned int*) LMU_INFO_IRQ_STAT_ADDR = 0xF;\
                                 } while (0)                               

//The end of the LMU information retrieval commands
//*************************************************************************

//*************************************************************************
//The start of LMU data transfer commands
 
//Output a ESC X pattern
#define LMU_Write_ESC_X(esc_x) do { \
                                    *(volatile unsigned int*) LMU_ESC_X_ADDR = (esc_x&0xFFFF);\
                                 } while (0) 

//Output a ESC X pattern
#define LMU_Write_ESC_X_TS(esc_x) do { \
                                  *(volatile unsigned int*) LMU_ESC_X_TS_ADDR = (esc_x&0xFFFF);\
                               } while (0) 
 

//output the context switch marker for Task with timestamp
#define LMU_Write_Task_CSM_TS(thread_id)	do { \
                                  *(volatile unsigned int*) LMU_WORD_CSM_TASK_TS_ADDR = thread_id;\
                                      } while (0) 
                               
//output the context switch marker for LISR with timestamp
#define LMU_Write_ISR_CSM_TS(isr_id)	do { \
                                  *(volatile unsigned int*) LMU_WORD_CSM_ISR_TS_ADDR = isr_id;\
                               } while (0) 

//output the context switch marker end for LISR with timestamp
#define LMU_Write_ISR_END_CSM_TS()	do { \
                                    *(volatile unsigned int*) LMU_WORD_CSM_ISR_END_TS_ADDR = 0;\
                                 } while (0)  

//output the context switch marker for SWLA tag with timestamp
#define LMU_Write_SWLA_TAG_CSM_TS(thread_id)	do { \
                                    *(volatile unsigned int*) LMU_WORD_CSM_SWLA_TAG_TS_ADDR = thread_id;\
                                      } while (0) 

//output word data to a certain CSM addr
#define LMU_Write_CSM_Addr(reg_num, value)do { \
                                    *(volatile unsigned int*) (LMU_WORD_CSM_BASE_ADDR+(reg_num*LMU_WORD_CSM_REG_LAYOUT_GAP)) = value;\
                                 } while (0)  
                               
//output word data to a certain CSM addr with timestamp
#define LMU_Write_CSM_Addr_TS(reg_num, value) do { \
                                    *(volatile unsigned int*) (LMU_WORD_CSM_BASE_TS_ADDR+(reg_num*LMU_WORD_CSM_REG_LAYOUT_GAP)) = value;\
                                 } while (0)  

//output the context switch marker for Task
#define LMU_Write_SWLA_Task_CSM(thread_id)	do { \
                                  *(volatile unsigned int*) LMU_WORD_SWLA_TASK_ADDR = thread_id;\
                               } while (0) 
                               
//output the context switch marker for LISR
#define HSL_Write_SWLA_ISR_CSM(isr_id)	do { \
                                  *(volatile unsigned int*) HSL_WORD_SWLA_ISR_ADDR = isr_id;\
                               } while (0) 

//output the context switch marker end for LISR
#define HSL_Write_SWLA_ISR_END_CSM(isr_id)	do { \
                                  *(volatile unsigned int*) HSL_WORD_SWLA_ISR_END_ADDR = isr_id;\
                                } while (0)                                

//output the context switch marker for SWLA Custom Logging
#define HSL_Write_SWLA_TAG_CSM(thread_id)	do { \
                                  *(volatile unsigned int*) HSL_WORD_SWLA_TAG_ADDR = thread_id;\
                               } while (0) 

//output the context switch marker for Task with timestamp
#define HSL_Write_SWLA_Task_CSM_With_TS(thread_id)	do { \
                                  *(volatile unsigned int*) HSL_WORD_SWLA_TASK_TS_ADDR = thread_id;\
                                      } while (0) 
                               
//output the context switch marker for LISR with timestamp
#define HSL_Write_SWLA_ISR_CSM_With_TS(isr_id)	do { \
                                  *(volatile unsigned int*) HSL_WORD_SWLA_ISR_TS_ADDR = isr_id;\
                               } while (0) 

//output the context switch marker end for LISR with timestamp
#define HSL_Write_SWLA_ISR_END_CSM_With_TS()	do { \
                                  *(volatile unsigned int*) HSL_WORD_SWLA_ISR_END_TS_ADDR = 0;\
                               } while (0)  

//output the context switch marker for SWLA tag with timestamp
#define HSL_Write_SWLA_TAG_CSM_With_TS(thread_id)	do { \
                                  *(volatile unsigned int*) HSL_WORD_SWLA_TAG_TS_ADDR = thread_id;\
                                      } while (0) 

//write one word PS data to LMU (with escaping)
#define LMU_Write_Bulk_Word(data) do { \
                                    *(volatile unsigned int*) (LMU_BULK_DATA_ADDR) = data;\
                                 } while (0)  

//write one word L1 data to LMU (with escaping)
#define LMU_Write_Short_Word(data) do { \
                                    *(volatile unsigned int*) (LMU_SHORT_DATA_ADDR) = data;\
                                 } while (0)  

//write one word PS data to LMU (with escaping)
#define LMU_Write_Bulk_Word_TS(data) do { \
                                    *(volatile unsigned int*) (LMU_BULK_DATA_TS_ADDR) = data;\
                                 } while (0)  

//write one word L1 data to LMU (with escaping)
#define LMU_Write_Short_Word_TS(data) do { \
                                    *(volatile unsigned int*) (LMU_SHORT_DATA_TS_ADDR) = data;\
                                 } while (0)  

//write one bulk PS data to LMU
#define LMU_Write_Bulk_Ary(buf_ary, write_len) do{\
                                                      unsigned int* data_to_write_idx = (unsigned int*)buf_ary;\
                                                      while (data_to_write_idx < (unsigned int*)(&buf_ary[write_len]))       \
                                                        { *(volatile unsigned int*) LMU_BULK_DATA_ADDR = *(data_to_write_idx++);} \
                                                     }while(0)

//write one bulk PS data to LMU with timestamp
#define LMU_Write_Bulk_Ary_TS(buf_ary, write_len) do{\
                                                      unsigned int* data_to_write_idx = (unsigned int*)buf_ary;\
                                                      while (data_to_write_idx < (unsigned int*)(&buf_ary[write_len]))       \
                                                        { *(volatile unsigned int*) LMU_BULK_DATA_TS_ADDR = *(data_to_write_idx++);} \
                                                     }while(0)                                                         

//write one bulk L1 data to LMU
#define LMU_Write_Short_Ary(buf_ary, write_len) do{\
                                                      unsigned int* data_to_write_idx = (unsigned int*)buf_ary;\
                                                      while (data_to_write_idx < (unsigned int*)(&buf_ary[write_len]))       \
                                                        { *(volatile unsigned int*) LMU_SHORT_DATA_ADDR = *(data_to_write_idx++);} \
                                                     }while(0)                                                      

//write one bulk L1 data to LMU with timestamp
#define LMU_Write_Short_Ary_TS(buf_ary, write_len) do{\
                                                      unsigned int* data_to_write_idx = (unsigned int*)buf_ary;\
                                                      while (data_to_write_idx < (unsigned int*)(&buf_ary[write_len]))       \
                                                        { *(volatile unsigned int*) LMU_SHORT_DATA_TS_ADDR = *(data_to_write_idx++);} \
                                                     }while(0)  

//write one bulk L1 data to LMU
#define LMU_Write_Data_Ary(buf_ary, write_len, dst_ptr) do{\
                                                      unsigned int* data_to_write_idx = (unsigned int*)buf_ary;\
                                                      while (data_to_write_idx < (unsigned int*)(&buf_ary[write_len]))       \
                                                        { *(volatile unsigned int*) (dst_ptr) = *(data_to_write_idx++);} \
                                                     }while(0)                                                      


//The end of LMU data transfer commands
//*************************************************************************

//*************************************************************************
// Burst access Macros
//*************************************************************************
#if !defined (__TST_ON_AOS__) && !defined(__FCORE__)
  //used for ARM
  #define LMU_BURST_WRITE_2WORD_BULK(src_ary) do{\
                                                    int access_port=LMU_BULK_DATA_ADDR;\
                                                    __asm\
                                                    { \
                                                      mov r0, src_ary;\
                                                      mov r1, access_port;\
                                                      ldmia R0!, {r4-r5};\
                                                      stmia r1!, {r4-r5};\
                                                    }\
                                                  }while(0)
  #define LMU_BURST_WRITE_3WORD_BULK(src_ary) do{\
                                                    int access_port=LMU_BULK_DATA_ADDR;\
                                                    __asm\
                                                    { \
                                                      mov r0, src_ary;\
                                                      mov r1, access_port;\
                                                      ldmia R0!, {r4-r6};\
                                                      stmia r1!, {r4-r6};\
                                                    }\
                                                  }while(0)
  #define LMU_BURST_WRITE_4WORD_BULK(src_ary) do{\
                                                    int access_port=LMU_BULK_DATA_ADDR;\
                                                    __asm\
                                                    { \
                                                      mov r0, src_ary;\
                                                      mov r1, access_port;\
                                                      ldmia R0!, {r4-r7};\
                                                      stmia r1!, {r4-r7};\
                                                    }\
                                                  }while(0)
  #define LMU_BURST_WRITE_5WORD_BULK(src_ary) do{\
                                                    int access_port=LMU_BULK_DATA_ADDR;\
                                                    __asm\
                                                    { \
                                                      mov r0, src_ary;\
                                                      mov r1, access_port;\
                                                      ldmia R0!, {r4-r8};\
                                                      stmia r1!, {r4-r8};\
                                                    }\
                                                  }while(0)
  #define LMU_BURST_WRITE_6WORD_BULK(src_ary) do{\
                                                    int access_port=LMU_BULK_DATA_ADDR;\
                                                    __asm\
                                                    { \
                                                      mov r0, src_ary;\
                                                      mov r1, access_port;\
                                                      ldmia R0!, {r4-r9};\
                                                      stmia r1!, {r4-r9};\
                                                    }\
                                                  }while(0)
  #define LMU_BURST_WRITE_7WORD_BULK(src_ary) do{\
                                                    int access_port=LMU_BULK_DATA_ADDR;\
                                                    __asm\
                                                    { \
                                                      mov r0, src_ary;\
                                                      mov r1, access_port;\
                                                      ldmia R0!, {r4-r10};\
                                                      stmia r1!, {r4-r10};\
                                                    }\
                                                  }while(0)     
  
  //input registers name directly
  //used for header output                                                
  #define LMU_BURST_WRITE_2WORD_BULK_2(reg1, reg2) do{\
                                                    int access_port=LMU_BULK_DATA_ADDR;\
                                                    __asm\
                                                    { \
                                                      mov r1, access_port;\
                                                      mov r4, reg1;\
                                                      mov r5, reg2;\
                                                      stmia r1!, {r4-r5};\
                                                    }\
                                                  }while(0)
  #define LMU_BURST_WRITE_3WORD_BULK_2(reg1, reg2, reg3) do{\
                                                    int access_port=LMU_BULK_DATA_ADDR;\
                                                    __asm\
                                                    { \
                                                      mov r1, access_port;\
                                                      mov r4, reg1;\
                                                      mov r5, reg2;\
                                                      mov r6, reg3;\
                                                      stmia r1!, {r4-r6};\
                                                    }\
                                                  }while(0)
  #define LMU_BURST_WRITE_4WORD_BULK_2(reg1, reg2, reg3, reg4) do{\
                                                    int access_port=LMU_BULK_DATA_ADDR;\
                                                    __asm\
                                                    { \
                                                      mov r1, access_port;\
                                                      mov r4, reg1;\
                                                      mov r5, reg2;\
                                                      mov r6, reg3;\
                                                      mov r7, reg4;\
                                                      stmia r1!, {r4-r7};\
                                                    }\
                                                  }while(0)           
  
  #define LMU_BURST_WRITE_2WORD_SHORT(src_ary) do{\
                                                    int access_port=LMU_SHORT_DATA_ADDR;\
                                                    __asm\
                                                    { \
                                                      mov r0, src_ary;\
                                                      mov r1, access_port;\
                                                      ldmia R0!, {r4-r5};\
                                                      stmia r1!, {r4-r5};\
                                                    }\
                                                  }while(0)
  #define LMU_BURST_WRITE_3WORD_SHORT(src_ary) do{\
                                                    int access_port=LMU_SHORT_DATA_ADDR;\
                                                    __asm\
                                                    { \
                                                      mov r0, src_ary;\
                                                      mov r1, access_port;\
                                                      ldmia R0!, {r4-r6};\
                                                      stmia r1!, {r4-r6};\
                                                    }\
                                                  }while(0)
  #define LMU_BURST_WRITE_4WORD_SHORT(src_ary) do{\
                                                    int access_port=LMU_SHORT_DATA_ADDR;\
                                                    __asm\
                                                    { \
                                                      mov r0, src_ary;\
                                                      mov r1, access_port;\
                                                      ldmia R0!, {r4-r7};\
                                                      stmia r1!, {r4-r7};\
                                                    }\
                                                  }while(0)
  #define LMU_BURST_WRITE_5WORD_SHORT(src_ary) do{\
                                                    int access_port=LMU_SHORT_DATA_ADDR;\
                                                    __asm\
                                                    { \
                                                      mov r0, src_ary;\
                                                      mov r1, access_port;\
                                                      ldmia R0!, {r4-r8};\
                                                      stmia r1!, {r4-r8};\
                                                    }\
                                                  }while(0)
  #define LMU_BURST_WRITE_6WORD_SHORT(src_ary) do{\
                                                    int access_port=LMU_SHORT_DATA_ADDR;\
                                                    __asm\
                                                    { \
                                                      mov r0, src_ary;\
                                                      mov r1, access_port;\
                                                      ldmia R0!, {r4-r9};\
                                                      stmia r1!, {r4-r9};\
                                                    }\
                                                  }while(0)
  #define LMU_BURST_WRITE_7WORD_SHORT(src_ary) do{\
                                                    int access_port=LMU_SHORT_DATA_ADDR;\
                                                    __asm\
                                                    { \
                                                      mov r0, src_ary;\
                                                      mov r1, access_port;\
                                                      ldmia R0!, {r4-r10};\
                                                      stmia r1!, {r4-r10};\
                                                    }\
                                                  }while(0)  
  
  //input registers name directly
  //used for header output   
  #define LMU_BURST_WRITE_2WORD_SHORT_2(reg1 ,reg2) do{\
                                                    int access_port=LMU_SHORT_DATA_ADDR;\
                                                    __asm\
                                                    { \
                                                      mov r1, access_port;\
                                                      mov r4, reg1;\
                                                      mov r5, reg2;\
                                                      stmia r1!, {r4-r5};\
                                                    }\
                                                  }while(0)
  #define LMU_BURST_WRITE_3WORD_SHORT_2(reg1 ,reg2, reg3) do{\
                                                    int access_port=LMU_SHORT_DATA_ADDR;\
                                                    __asm\
                                                    { \
                                                      mov r1, access_port;\
                                                      mov r4, reg1;\
                                                      mov r5, reg2;\
                                                      mov r6, reg3;\
                                                      stmia r1!, {r4-r6};\
                                                    }\
                                                  }while(0)
  #define LMU_BURST_WRITE_4WORD_SHORT_2(reg1 ,reg2, reg3, reg4) do{\
                                                    int access_port=LMU_SHORT_DATA_ADDR;\
                                                    __asm\
                                                    { \
                                                      mov r1, access_port;\
                                                      mov r4, reg1;\
                                                      mov r5, reg2;\
                                                      mov r6, reg3;\
                                                      mov r7, reg4;\
                                                      stmia r1!, {r4-r7};\
                                                    }\
                                                  }while(0)
#else   //#if !defined (__TST_ON_AOS__)
  #define LMU_BURST_WRITE_2WORD_BULK(src_ary) LMU_Write_Bulk_Ary(src_ary,2)
  #define LMU_BURST_WRITE_3WORD_BULK(src_ary) LMU_Write_Bulk_Ary(src_ary,3)
  #define LMU_BURST_WRITE_4WORD_BULK(src_ary) LMU_Write_Bulk_Ary(src_ary,4)
  #define LMU_BURST_WRITE_5WORD_BULK(src_ary) LMU_Write_Bulk_Ary(src_ary,5)
  #define LMU_BURST_WRITE_6WORD_BULK(src_ary) LMU_Write_Bulk_Ary(src_ary,6)
  #define LMU_BURST_WRITE_7WORD_BULK(src_ary) LMU_Write_Bulk_Ary(src_ary,7)
  
  //input registers name directly
  //used for header output                                                
  #define LMU_BURST_WRITE_2WORD_BULK_2(reg1, reg2) do{\
                                                    LMU_Write_Bulk_Word(reg1);\
                                                    LMU_Write_Bulk_Word(reg2);\
                                                  }while(0)
  #define LMU_BURST_WRITE_3WORD_BULK_2(reg1, reg2, reg3) do{\
                                                    LMU_Write_Bulk_Word(reg1);\
                                                    LMU_Write_Bulk_Word(reg2);\
                                                    LMU_Write_Bulk_Word(reg3);\
                                                  }while(0)
  #define LMU_BURST_WRITE_4WORD_BULK_2(reg1, reg2, reg3, reg4) do{\
                                                    LMU_Write_Bulk_Word(reg1);\
                                                    LMU_Write_Bulk_Word(reg2);\
                                                    LMU_Write_Bulk_Word(reg3);\
                                                    LMU_Write_Bulk_Word(reg4);\
                                                  }while(0)           
  
  #define LMU_BURST_WRITE_2WORD_SHORT(src_ary) LMU_Write_Bulk_Ary(src_ary,2)
  #define LMU_BURST_WRITE_3WORD_SHORT(src_ary) LMU_Write_Bulk_Ary(src_ary,3)
  #define LMU_BURST_WRITE_4WORD_SHORT(src_ary) LMU_Write_Bulk_Ary(src_ary,4)
  #define LMU_BURST_WRITE_5WORD_SHORT(src_ary) LMU_Write_Bulk_Ary(src_ary,5)
  #define LMU_BURST_WRITE_6WORD_SHORT(src_ary) LMU_Write_Bulk_Ary(src_ary,6)
  #define LMU_BURST_WRITE_7WORD_SHORT(src_ary) LMU_Write_Bulk_Ary(src_ary,7)
  
  //input registers name directly
  //used for header output   
  #define LMU_BURST_WRITE_2WORD_SHORT_2(reg1 ,reg2) do{\
                                                    LMU_Write_Short_Word(reg1);\
                                                    LMU_Write_Short_Word(reg2);\
                                                  }while(0)
  #define LMU_BURST_WRITE_3WORD_SHORT_2(reg1 ,reg2, reg3) do{\
                                                    LMU_Write_Short_Word(reg1);\
                                                    LMU_Write_Short_Word(reg2);\
                                                    LMU_Write_Short_Word(reg3);\
                                                  }while(0)
  #define LMU_BURST_WRITE_4WORD_SHORT_2(reg1 ,reg2, reg3, reg4) do{\
                                                    LMU_Write_Short_Word(reg1);\
                                                    LMU_Write_Short_Word(reg2);\
                                                    LMU_Write_Short_Word(reg3);\
                                                    LMU_Write_Short_Word(reg4);\
                                                  }while(0)

#endif //#if !defined (__TST_ON_AOS__)

/*************************************************************************
* Function declaration
 *************************************************************************/
#if !defined(_LANGUAGE_ASM) 
  void lmu_issue_2words_burst_write(unsigned int* src, volatile unsigned int *dst);
  void lmu_issue_3words_burst_write(unsigned int* src, volatile unsigned int *dst);
  void lmu_issue_4words_burst_write(unsigned int* src, volatile unsigned int *dst);
  void lmu_issue_5words_burst_write(unsigned int* src, volatile unsigned int *dst);
  void lmu_issue_6words_burst_write(unsigned int* src, volatile unsigned int *dst);
  void lmu_issue_7words_burst_write(unsigned int* src, volatile unsigned int *dst);
  void lmu_issue_2words_burst_write_2(unsigned int reg1, unsigned int reg2, volatile unsigned int *dst);
#endif  //#if !defined(_LANGUAGE_ASM)

//***************************************
//exported to Scheduler start
//output the context switch marker for Task
  #define LMU_Write_Task_CSM(thread_id)	do { \
                                    *(volatile unsigned int*) LMU_WORD_CSM_TASK_ADDR = thread_id;\
                                    ALC_WRITE_CSM(thread_id);                                    \
                                 } while (0) 
  
  //output the context switch marker for LISR
  #if !defined(__FCORE__) || !defined(_LANGUAGE_ASM)
    #define LMU_Write_ISR_CSM(isr_id)	do { \
                                      *(volatile unsigned int*) LMU_WORD_CSM_ISR_ADDR = isr_id;\
                                      ALC_WRITE_CSM(isr_id);                                   \
                                   } while (0) 
  #else //#if !defined(__FCORE__)                               
    #define LMU_Write_ISR_CSM(pReg, dReg)                                                   \
                /* Write to LMU CSM for ISR */                                              \
                pReg##.L = LMU_WORD_CSM_ISR_ADDR & 0xFFFF;                                  \
                ##pReg##.H = LMU_WORD_CSM_ISR_ADDR >> 16;                                   \
                [pReg] = dReg;
  #endif  //#if !defined(__FCORE__)            
  
  //output the context switch marker end for LISR
  #if !defined(__FCORE__) || !defined(_LANGUAGE_ASM)
    #define LMU_Write_ISR_END_CSM(isr_id)	do { \
                                      *(volatile unsigned int*) LMU_WORD_CSM_ISR_END_ADDR = isr_id;\
                                      ALC_WRITE_CSM(isr_id);                                       \
                                    } while (0)                                
  #else //#if !defined(__FCORE__)  
    #define LMU_Write_ISR_END_CSM(pReg, dReg)                                               \
                pReg##.L = LMU_WORD_CSM_ISR_END_ADDR & 0xFFFF;                              \
                ##pReg##.H = LMU_WORD_CSM_ISR_END_ADDR >> 16;                               \
                dReg = 0;                                                                   \
                [pReg] = dReg;
  #endif  //#if !defined(__FCORE__)
  
  //output the context switch marker end for LISR
  #if !defined(__FCORE__) || !defined(_LANGUAGE_ASM)
    #define LMU_Write_ISR_END_RESUME_CSM(marker)	do { \
                                      *(volatile unsigned int*) LMU_WORD_SWLA_TAG_ADDR = marker;\
                                      ALC_WRITE_CSM(marker);                                   \
                                    } while (0)                                
  #else //#if !defined(__FCORE__)  
    #define LMU_Write_ISR_END_RESUME_CSM(pReg, dReg)                                               \
                pReg##.L = LMU_WORD_SWLA_TAG_ADDR & 0xFFFF;                              \
                ##pReg##.H = LMU_WORD_SWLA_TAG_ADDR >> 16;                               \
                dReg = 0;                                                                   \
                [pReg] = dReg;
  #endif  //#if !defined(__FCORE__)
  
  //output irq marker after nested interrupt end  
  #define LMU_Write_ISR_RESUME_CSM(marker)	ALC_WRITE_CSM(marker)                                             

//exported to Scheduler end
//***************************************

#else //#if defined(__TST_LMU_LOGGING__) || defined(USE_DNT_LOGGING)

#define LMU_Write_CSM_Addr_TS(reg_num, value)
#define LMU_Write_Short_Ary(ptr, ptr_length)
#define LMU_Write_Short_Word(word_data)

  //***************************************
  //exported to Scheduler start
  #define LMU_Write_Task_CSM(thread_id) ALC_WRITE_CSM(thread_id)
  #if !defined(__FCORE__) || !defined(_LANGUAGE_ASM)
    #define LMU_Write_ISR_CSM(isr_id) ALC_WRITE_CSM(isr_id)
    #define LMU_Write_ISR_END_CSM(isr_id) ALC_WRITE_CSM(isr_id)
    #define LMU_Write_ISR_END_RESUME_CSM(marker) ALC_WRITE_CSM(marker)
    #define LMU_Write_ISR_RESUME_CSM(marker) ALC_WRITE_CSM(marker)
  #else
    #define LMU_Write_ISR_CSM(pReg, dReg)
    #define LMU_Write_ISR_END_CSM(pReg, dReg)  
    #define LMU_Write_ISR_END_RESUME_CSM(pReg, dReg)  
    #define LMU_Write_ISR_RESUME_CSM(pReg, dReg) 
  #endif

//exported to Scheduler end
//***************************************

#endif  //#if defined(__TST_LMU_LOGGING__) || defined(USE_DNT_LOGGING)
#endif  //#ifndef __TST_LMU_HW_H__ 
