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
 * tst_internal_def.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file provides definitions for TST internal usage
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __TST_INTERNAL_DEF_H__ 
#define __TST_INTERNAL_DEF_H__

#if !defined(GEN_FOR_PC)
  #include "tst_def.h"
#endif  //#if !defined(GEN_FOR_PC)

#if !defined(GEN_FOR_PC) && defined(UNIT_TEST)  
  
  #define __TST_EVENT_SYNC__
  
  #ifdef __TST_EVENT_SYNC__
#include "kal_public_api.h" //MSBB change     #include "kal_release.h"
    
    //used to sync between TST and TR
    #define TST_TR_EVENT_WAIT_TR_FINISH_LOGGING 0x1
    
    #define TST_Declare_Run_Token kal_eventgrpid tst_tr_event_g
    #define TST_Init_Run_Token do{tst_tr_event_g = kal_create_event_group("TSTTREVT");\
                                  kal_set_eg_events(tst_tr_event_g, TST_TR_EVENT_WAIT_TR_FINISH_LOGGING, KAL_OR);}while(0)
    #define TST_Stop_Run do{\
                            extern kal_eventgrpid tst_tr_event_g; \
                            kal_uint32 tst_tr_tmp_event_g;\
                            kal_retrieve_eg_events(	tst_tr_event_g, TST_TR_EVENT_WAIT_TR_FINISH_LOGGING,\
                                      KAL_OR_CONSUME, &tst_tr_tmp_event_g, KAL_NO_WAIT);\
                         }while(0)
    #define TST_Resume_Run do {\
                             extern kal_eventgrpid tst_tr_event_g; \
                             kal_set_eg_events(tst_tr_event_g, TST_TR_EVENT_WAIT_TR_FINISH_LOGGING, KAL_OR);\
                           } while(0)
    #define TST_Check_Run_Token do{\
                                  extern kal_eventgrpid tst_tr_event_g; \
                                  kal_uint32 tst_tr_tmp_event_g;\
                                  kal_retrieve_eg_events(	tst_tr_event_g, TST_TR_EVENT_WAIT_TR_FINISH_LOGGING,\
                                      KAL_OR, &tst_tr_tmp_event_g, KAL_SUSPEND);\
                                }while(0)
  #else //#ifdef __TST_EVENT_SYNC__
    #include <windows.h>
    extern CRITICAL_SECTION csTRPrintTrace;
    
    //stop TST to be
    #define TST_Declare_Run_Token CRITICAL_SECTION csTRPrintTrace
    #define TST_Init_Run_Token do{InitializeCriticalSection(&csTRPrintTrace);}while(0)
    #define TST_Stop_Run OSC_Critical_Section_Enter(&csTRPrintTrace)
    #define TST_Resume_Run OSC_Critical_Section_Leave (&csTRPrintTrace)
    #define TST_Check_Run_Token do{\
                              OSC_Critical_Section_Enter(&csTRPrintTrace);\
                              OSC_Critical_Section_Leave (&csTRPrintTrace);\
                            }while(0)

  #endif  //#ifdef __TST_EVENT_SYNC__
#else //#if !defined(GEN_FOR_PC) && defined(UNIT_TEST) && (!defined(__TST_HSL_SW_LOGGING__)|| defined(__TST_DEVELOP__))
  #define TST_Declare_Run_Token 
  #define TST_Init_Run_Token  do{;}while(0)
  #define TST_Stop_Run do{;}while(0)
  #define TST_Resume_Run do{;}while(0)
  #define TST_Check_Run_Token do{;}while(0)
#endif  //#if !defined(GEN_FOR_PC) && defined(UNIT_TEST) && (!defined(__TST_HSL_SW_LOGGING__)|| defined(__TST_DEVELOP__))

#ifdef __UMTS_RAT__
	#if defined(__UMTS_FDD_MODE__)
		#define GetUMTSCurrentTIme(sfn) do{\
																		  	kal_int16 nop_cfn;\
																		  	UL1_GetCurrentTime(&nop_cfn, &sfn);\
																			}while(0)
	#elif defined(__UMTS_TDD128_MODE__)
		#define GetUMTSCurrentTIme(sfn) do{\
																		  	kal_int16 nop_cfn;\
																		  	TL1_GetCurrentTime(&nop_cfn, &sfn);\
																			}while(0)
	#endif	//#if defined(__UMTS_FDD_MODE__)
#else  //#ifdef __UMTS_RAT__		
  #define GetUMTSCurrentTIme(sfn) do{}while(0)
#endif	//#ifdef __UMTS_RAT__																
#ifdef __GEMINI__
  //In the GEMINI projects, kal_trace sends the active module id to Catcher
  //That's PS's requirement since they don't want to define two identical trace definitions.
  //However, after one and half year, JAVA team don't like this.
  //So, we create a list to exclude JAVA
  #define KAL_TRACE_STATIC_MOD_LIST_DECLARE() kal_uint8	kal_trace_static_mod_list[TST_MODULE_FILTER_LEN]
  #define KAL_TRACE_STATIC_MOD_LIST_INIT() do{memset(kal_trace_static_mod_list,0,TST_MODULE_FILTER_LEN);}while(0)
  #define KAL_TRACE_STATIC_MOD_APPEND(mod_id) do{kal_trace_static_mod_list[mod_id/8] += (0x01 << (mod_id%8));}while(0)
  #define KAL_TRACE_STATIC_MOD_REMOVE(mod_id) do{\
                                                if ((kal_trace_static_mod_list[mod_id/8] & (0x01 << (mod_id%8))) != 0)\
                                                  kal_trace_static_mod_list[mod_id/8] -= 0x01 << (mod_id%8);\
                                                }while(0)
  #define KAL_TRACE_CHECK_IF_STATIC_MOD(mod_id,result) do{result = (kal_trace_static_mod_list[mod_id/8] & (0x01 << (mod_id% 8)));}while(0)
#endif  //#ifdef __GEMINI__

//On some platforms, the users might pass the duplicated logs between modules
//TST can only log partial data of local or peer buf. We reuses the SAP bytes
//New bytes arrangement
//'M''L1''L2''L3''L4''X''Y''1'
//If the LSB is 1, that means we only partial data
#define TST_MSG_LOG_PARTIAL_LOCAL_MODE 0x80
#define TST_MSG_LOG_PARTIAL_PEER_MODE 0x40
#define TST_MSG_LOG_GET_PARTIAL_LENGTH(sap,len) do{len=(1<<(((kal_uint32)sap&0x38)>>3))*16;}while(0) 
#define TST_MSG_LOG_SAP_ENABLE 0x7  //0x4+0x2+0x1

//Add compile option checking for EMI monitor query
#if defined(__MTK_INTERNAL__)
  #if defined(__MTK_TARGET__) && !defined(__MAUI_BASIC__)
    #if defined(MT6236) || defined(MT6268)
/* under construction !*/
    #endif  //#if defined(MT6236) || defined(MT6268)
  #endif  //#if defined(__MTK_TARGET__) && !defined(__MAUI_BASIC__)
#endif  //#if defined(__MTK_INTERNAL__)
#if defined(__DSP_FCORE4__) && !defined(UNIT_TEST)
  #define __FCORE_MEMORY_DUMP_FROM_ARM__
  #define __FCORE_STATISTIC_RETRIVAL__
#endif  //#if defined(__DSP_FCORE4__) && !defined(UNIT_TEST)

typedef enum
{
    ECMSG_ID_TST_DSP_TRIGGER_ASSERT                = 0x00000001,   /* D2M, DSP triggers MCU assert */
    ECMSG_ID_TST_MCU_TRIGGER_ASSERT                = 0x00000002,   /* M2D, MCU triggers DSP assert */
    ECMSG_ID_TST_MEM_REGION_INFO                   = 0x00000003,   /* M2D, Query DSP memory region info */
    ECMSG_ID_VITI_NVRAM_STAT_READ_REQ              = 0x00000004,   /* D2M, Query VITI Stat in NVRAM */
    ECMSG_ID_VITI_NVRAM_STAT_READ_REPORT           = 0x00000005,   /* M2D, Report VITI Stat in NVRAM */
    ECMSG_ID_VITI_NVRAM_STAT_RESET                 = 0x00000006,   /* M2D, Report VITI Stat in NVRAM */
    ECMSG_ID_VITI_NVRAM_STAT_RESET_REPORT          = 0x00000007,   /* M2D, Report VITI Stat in NVRAM */
    ECMSG_ID_VITI_NVRAM_STAT_RESET_FLAG            = 0x00000008,   /* M2D, Report VITI Stat in NVRAM */
    ECMSG_ID_VITI_NVRAM_STAT_RESET_FLAG_REPORT     = 0x00000009,   /* M2D, Report VITI Stat in NVRAM */
    ECMSG_ID_TST_DSP_PORT_REPORT                   = 0x0000000A,   /* M2D, Report TST-DSP port */
    ECMSG_ID_TST_UART_READ_MSG                     = 0x0000000B,   /* M2D, Send UART_READY_TO_READ */
    ECMSG_ID_TST_UART_WRITE_MSG                    = 0x0000000C,   /* M2D, Send UART_READY_TO_WRITE */
    ECMSG_ID_MEM_DATA_QUERY_REQ                    = 0x0000000D,   /* M2D, Query Fcore memory range */
    ECMSG_ID_MEM_DATA_QUERY_ADDR_REQ               = 0x0000000E,   /* M2D, Query Fcore memory range */
    ECMSG_ID_MEM_DATA_ACK                          = 0x0000000F,   /* D2M, Dump Fcore memory data */    
    ECMSG_ID_VITI_Log_Info_REPORT                  = 0x00000010,   /* M2D, report the usb logging related info */
    ECMSG_ID_VITI_Log_Info_ACK                     = 0x00000011,   /* D2M, ack the usb logging related info */
    ECMSG_ID_VITI_USB_Log_Trigger_Req              = 0x00000012,   /* D2M, ask MCU to move the log */
    ECMSG_ID_VITI_USB_Log_Trigger_Ack              = 0x00000013,   /* M2D, ack DSP log movement request */
    ECMSG_ID_VITI_USB_Cmd_REPORT                   = 0x00000014,   /* M2D, Info DSP that some data are ready on the cmd buffer */
    ECMSG_ID_VITI_USB_Cmd_ACK                      = 0x00000015,   /* D2M, Notify MCU can move next data */
    ECMSG_ID_TST_DSP_USB_PORT_REPORT               = 0x00000016,   /* M2D, Report TST-DSP port when it's a usb port. */
    ECMSG_ID_TST_DSP_USB_PORT_ACK                  = 0x00000017,   /* D2M, Ack TST-DSP port when it's a usb port. */
    ECMSG_ID_TST_DSP_LMU_PORT_REPORT               = 0x00000018,    /* M2D, Report TST-DSP port when it's a lmu port. */
    ECMSG_ID_TST_DSP_SIB_BUF_ADDR_REPORT           = 0x00000019    /* M2D, Report SIB Buffer address */
} tst_mdci_cmd_msg_id_t;

#if defined(__FCORE_MEMORY_DUMP_FROM_ARM__)

  #define TST_DSP_MEM_MAP_MAX_NUM 32    
  #define TST_DSP_MDCI_WAIT_TIMEOUT (1000000) //1000000 us
  #define TST_DSP_MDCI_READ_MEM_WAIT_TIMEOUT (1000000)  //us

  /** The DMDSP memory region information */
  typedef struct
  {
      kal_uint32       region_count;       /* The number of memory blocks */
      kal_uint32       region_table_ptr;   /* The pointer to the memory region table */
      #if defined(__TST_FCORE_MEM_DUMP_V1__)  
        kal_uint32       reserved;           /* Reserved for future use */
      #endif  //#if !defined(__TST_FCORE_MEM_DUMP_V1__)  
  } dmdsp_mem_region_info_t;  //sync with struct_mem_dump_region_info
  
  /** The memory region mapping table entry */
  typedef struct
  {
      kal_uint32       region_start_addr;  /* The start address of the memory region,
                                             it's where the data should be restored to */
      kal_uint32       length;             /* The length of the memory block in bytes */
                                             
      kal_uint32       dump_start_addr;    /* The start address to dump this memory
                                             region, it's where the data are stored
                                             in target currently */
      #if !defined(__TST_FCORE_MEM_DUMP_V1__)  
        unsigned int size_per_transfer;      
      #endif  //#if defined(__TST_FCORE_MEM_DUMP_V1__)  
                                             
  } dmdsp_mem_region_mapping_t; //sync with struct_mem_dump_region_detail
    
  typedef struct
  {
    kal_uint32 virtual_addr[TST_DSP_MEM_MAP_MAX_NUM];
    kal_uint32 physical_addr[TST_DSP_MEM_MAP_MAX_NUM];  
    kal_uint32 range[TST_DSP_MEM_MAP_MAX_NUM];
    kal_uint32 valid_num;
  }tst_dsp_mem_mapping_t;
  
  

#endif  //#if defined(__FCORE_MEMORY_DUMP_FROM_ARM__)
//Kevin: disable USB DMA threshold mechanism
#define TST_USB_DISABLE_DMA_INTERVAL (200) //frames
#define TST_USB_DISABLE_DMA_INTERVAL_MS (1000) //ms

#define TST_CPHY_MSG_CONTAINER_BUF_SIZE (64*1024) /*64K*/
#define TST_MAKE_LEN_4N(len) do{len = (((len)+3)/4*4);}while(0)

//Define the data structure for tst_trace_data_collection
typedef struct
{
  unsigned int arg_buf_siz:16;
  unsigned int supportOption:8;
  unsigned int bInternalOnly:1;
  unsigned int bBriefTrace:2;  //0:non-brief trace, 1: brief trace without module id, 2:brief trace with module id
}
trace_data_info_t;

#if !defined(TRC_C) && !defined(DCC_C)//avoid they are included by L1trc.c
  extern void FillAndSendFrameInAssert(const tst_trace_exception_frame_arg *pArgs);    
  extern kal_bool FillAndSendFrame(const tst_trace_frame_arg *pArgs);
  extern kal_bool FillAndSendFrameToSPUSB(const tst_trace_frame_arg *pArgs);
  extern kal_bool FillAndSendFrameToSPUSBInAssert(const tst_trace_exception_frame_arg *pArgs);  
  extern kal_bool FillAndSendFrameToLMU(const tst_trace_frame_arg *pArgs);
  extern kal_bool FillAndSendFrameToLMUInAssert(const tst_trace_exception_frame_arg *pArgs);    
  extern kal_bool FillAndSendFrameToALC(const tst_trace_frame_arg *pArgs);
#endif  //#if !defined(TRC_C)

extern kal_bool g_tst_alc_ps_logging_enable;

  #ifdef __TST_ON_AOS__
    #define SYS_SYNC() asm volatile("ssync;")
  #else //#ifdef __TST_ON_AOS__    
    #define SYS_SYNC()
  #endif  //#ifdef __TST_ON_AOS__

//Define the macros to send packed data
#define TST_Send_Packed_Data(argFrameToSend) do{\
                                                 if (tst_PsTrc_port == uart_port_lmu)\
                                                   FillAndSendFrameToLMU(&argFrameToSend);\
                                                 else if (tst_PsTrc_port == uart_port_sp_usb)\
                                                   FillAndSendFrameToSPUSB(&argFrameToSend);\
                                                 else if (g_tst_alc_ps_logging_enable)\
                                                   FillAndSendFrameToALC(&argFrameToSend);\
                                                 else\
                                                   FillAndSendFrame(&argFrameToSend);\
                                               }while(0)
#define TST_Send_Packed_Data_With_Result(argFrameToSend,res) do{\
                                                 if (tst_PsTrc_port == uart_port_lmu)\
                                                   res = FillAndSendFrameToLMU(&argFrameToSend);\
                                                 else if (tst_PsTrc_port == uart_port_sp_usb)\
                                                   res = FillAndSendFrameToSPUSB(&argFrameToSend);\
                                                 else if (g_tst_alc_ps_logging_enable)\
                                                   res = FillAndSendFrameToALC(&argFrameToSend);\
                                                 else\
                                                   res = FillAndSendFrame(&argFrameToSend);\
                                               }while(0)                                                 
                                               
#define TST_Send_Packed_Data_Assert(argFrameToSend) do{\
                                                 if (tst_PsTrc_port == uart_port_lmu)\
                                                   FillAndSendFrameToLMUInAssert(&argFrameToSend);\
                                                 else if (tst_PsTrc_port == uart_port_sp_usb)\
                                                   FillAndSendFrameToSPUSBInAssert(&argFrameToSend);\
                                                 else\
                                                   FillAndSendFrameInAssert(&argFrameToSend);\
                                               }while(0)     
#define TST_Send_Packed_Data_META(argFrameToSend) do{\
												   												if (tst_PsTrc_port == uart_port_lmu)\
	  												 												FillAndSendFrameToLMU(&argFrameToSend);\
												   												else if (tst_PsTrc_port == uart_port_sp_usb)\
	  												 												FillAndSendFrameToSPUSB(&argFrameToSend);\
                                                   else if (g_tst_alc_ps_logging_enable)\
                                                     FillAndSendFrameToALC(&argFrameToSend);\
                                                   else\
                                                     FillAndSendFrame(&argFrameToSend);\
                                                  }while(0)     
#define TST_Send_Packed_Data_META_Assert(argFrameToSend) do{\
													if (tst_PsTrc_port == uart_port_lmu)\
			                                          FillAndSendFrameToLMUInAssert(&argFrameToSend);\
            			                            else if (tst_PsTrc_port == uart_port_sp_usb)\
                        			                  FillAndSendFrameToSPUSBInAssert(&argFrameToSend);\
                                    			    else\
                                                	  FillAndSendFrameInAssert(&argFrameToSend);\
													}while(0)


typedef struct{
   unsigned int special_pattern;	//0xE5CF2454
   unsigned int type;	//・FLC2・ or ．CTRL・
   unsigned int version;	//1
   unsigned int header_size; // sizeof(monitor_file_header_t)
   unsigned int total_levels_offset;
   unsigned int used_count_offset;
   unsigned int used_buf_info_offset;
   unsigned int reserved;
} monitor_file_header_t;

#if defined(UNIT_TEST)
  #define TST_Enter_Win32_CS(g_cs) do{\
                                   if (OSC_If_OSCAR_Context()){\
                                     OSC_Critical_Section_Enter((void *)(&g_cs));\
                                   }else{\
                                     EnterCriticalSection((void *)(&g_cs));\
                                   }\
                                 }while(0)
  
  #define TST_Leave_Win32_CS(g_cs) do{\
                                   if (OSC_If_OSCAR_Context()){\
                                     OSC_Critical_Section_Leave((void *)(&g_cs));\
                                   }else{\
                                     LeaveCriticalSection((void *)(&g_cs));\
                                   }\
                                 }while(0)
                                 
  #define TST_Init_Win32_CS(g_cs) do{\
                                   if (OSC_If_OSCAR_Context()){\
                                     OSC_Critical_Section_Initialize((void *)(&g_cs));\
                                   }else{\
                                     InitializeCriticalSection((void *)(&g_cs));\
                                   }\
                                 }while(0)
#endif    //#if defined(UNIT_TEST)

//release buf flag
#define TST_RELEASE_CMD_BUF (0x1)
#define TST_RELEASE_MSG_BUF (0x2)
#define TST_RELEASE_UTMSG_BUF (0x4)
#define TST_RELEASE_POSTMAN_CMD_BUF (0x8)

//Clean cache operation
//Should make the addr and size are cache-line aligned
#define TST_Get_Dynamic_Switch_VAddr(vaddr, addr) do{\
                                                      vaddr = addr;\
                                                      dynamic_switch_cacheable_region(&vaddr,32,0);\
                                                  }while(0)

#define TST_Clean_Cache(addr, size) do{ \
                                        kal_uint32 vaddr = (addr)/32*32;\
                                        kal_uint32 vsize = ((addr)-vaddr+(size)+31)/32*32;\
                                        if (vsize>dbg_longest_flush_length){dbg_longest_flush_length=vsize;dbg_ori_len=size;dbg_times=4;}\
                                        dynamic_switch_cacheable_region(&vaddr,vsize,0);\
                                      }while(0)

#define TST_Clean_Cache_RingBuf(addr, size, ring_buf_start, ring_buf_size) do{ \
                                                              kal_uint32 vaddr = (addr)/32*32;\
                                                              kal_uint32 vsize = ((addr)-vaddr+(size)+31)/32*32;\
                                                              if (vaddr+vsize > (ring_buf_start)+(ring_buf_size)){\
                                                                if (((ring_buf_start)+(ring_buf_size)-vaddr)>dbg_longest_flush_length){dbg_longest_flush_length=(ring_buf_start)+(ring_buf_size)-vaddr;dbg_ori_len=size;dbg_times=1;}\
                                                                dynamic_switch_cacheable_region(&vaddr,(ring_buf_start)+(ring_buf_size)-vaddr,0);\
                                                                vsize = vsize-((ring_buf_start)+(ring_buf_size)-((addr)/32*32));\
                                                                vaddr = (ring_buf_start);\
                                                                if (vsize>dbg_longest_flush_length){dbg_longest_flush_length=vsize;dbg_ori_len=size;dbg_times=2;}\
                                                                dynamic_switch_cacheable_region(&vaddr,vsize,0);\
                                                              }else{\
                                                                if (vsize>dbg_longest_flush_length){dbg_longest_flush_length=vsize;dbg_ori_len=size;dbg_times=3;}\
                                                                dynamic_switch_cacheable_region(&vaddr,vsize,0);\
                                                              }\
                                                            }while(0)

typedef struct
{
  kal_bool bLast;
  kal_bool isPSLog;
  kal_uint8 access_type; //0: 1 byte, 1: 2 bytes, 2: 4 bytes
}
tst_mux_send_info_t;

#define LogAcc_Disable_UART_VFIFO_Link(port) do{\
                                              if ((port>= uart_port1)&& (port<= uart_port3))\
                                              {tst_hal_UART_VFIFO_TX_DMA_Enable(port,KAL_FALSE);}\
                                            }while(0)
#define LogAcc_Enable_UART_VFIFO_Link(port) do{\
                                              if ((port>= uart_port1)&& (port<= uart_port3))\
                                              {tst_hal_UART_VFIFO_TX_DMA_Enable(port,KAL_TRUE);}\
                                            }while(0)

typedef enum
{
  #if defined(__LOGACC_ENABLE__)
    TST_HISR_LGA,
  #endif  //__LOGACC_ENABLE__
  #if defined(__TST_DCC_ENABLED__)    
    TST_HISR_DCC,
  #endif  //#if defined(__TST_DCC_ENABLED__)
  #if defined(__TST_LMU_LOGGING__)
    TST_HISR_LMU,
  #endif  //__TST_LMU_LOGGING__
   
  #if defined(__LOGACC_ENABLE__) || defined(__SMART_PHONE_MODEM__)
    TST_HISR_TST_ALARM_CLOCK,  //active a HISR to trigger TST task to work
  #endif  //#if defined(__LOGACC_ENABLE__) || defined(__SMART_PHONE_MODEM__)
  
  TST_HISR_MAX_NUM
}
tst_hisr_type;

//workaround
#if defined(__GEMINI__) && !defined(GEMINI_PLUS)
  #define GEMINI_PLUS 2
#endif  //GEMINI_PLUS

typedef enum
{
  TST_LOG_PORT_PS,
  TST_LOG_PORT_L1,
  TST_LOG_PORT_RX,
  TST_LOG_PORT_DSP,
  TST_LOG_PORT_MAX,
}
tst_log_port_enum_t;

#if defined(__USB_HIGH_SPEED_COM_PORT_ENABLE__)
  extern kal_bool tst_use_highspeed_usb_if[];
  #define LOG_GetBytes(rcv_bytes, type, port, hs_ptr, buf, length, status, owner) do{\
                                                                 if(tst_use_highspeed_usb_if[type]){\
                                                                   rcv_bytes = tst_hal_UART_DMA_GetBytes(port, hs_ptr, status, owner);\
                                                                 }else{\
                                                                   rcv_bytes = tst_hal_UART_GetBytes(port, buf, length, status, owner);\
                                                                 }\
                                                               }while(0)  
  #define LOG_PutBytes(send_bytes, type, fc , port, buf, length, owner) do{\
                                                                         if(tst_use_highspeed_usb_if[type]){\
                                                                            send_bytes = tst_hal_UART_DMA_PutBytes(port,buf, length, owner);\
                                                                         }else{\
                                                                            send_bytes = tst_sendLog(port, fc, buf, length);\
                                                                         }\
                                                                       }while(0)
  #define LOG_PutISRBytes(send_bytes, type, fc , port, buf, length, owner) do{\
                                                                         if(tst_use_highspeed_usb_if[type]){\
                                                                            send_bytes = tst_hal_UART_DMA_PutISRBytes(port,buf, length, owner);\
                                                                         }else{\
                                                                            send_bytes = tst_sendISRLog(port, fc, buf, length);\
                                                                         }\
                                                                       }while(0)
  #define LOG_Parse_Data( type, hsbuf_ptr, buf_ptr, get_length, frame_type,checksum,cmd_ptr, local_ptr, peer_ptr, rframe_length) do{\
                            if(tst_use_highspeed_usb_if[type]){\
                              tst_parse_receive_data(hsbuf_ptr, get_length, frame_type,checksum,cmd_ptr, local_ptr, peer_ptr, rframe_length);\
                            }else{\
                              tst_parse_receive_data(buf_ptr, get_length, frame_type,checksum,cmd_ptr, local_ptr, peer_ptr, rframe_length);\
                            }\
                          }while(0)  
#else //#if defined(__USB_HIGH_SPEED_COM_PORT_ENABLE__)
  #define LOG_GetBytes(rcv_bytes, type, port, hs_ptr, buf, length, status, owner) do{rcv_bytes = tst_hal_UART_GetBytes(port, buf, length, status, owner);}while(0)
  #define LOG_PutBytes(send_bytes, type, fc , port, buf, length, owner) do{\
                                                                         send_bytes = tst_sendLog(port, fc, buf, length);\
                                                                       }while(0)
  #define LOG_PutISRBytes(send_bytes, type, fc , port, buf, length, owner) do{\
                                                                           send_bytes = tst_sendISRLog(port, fc, buf, length);\
                                                                         }\
                                                                       }while(0)
  #define LOG_Parse_Data( type, hsbuf_ptr, buf_ptr, get_length, frame_type,checksum,cmd_ptr, local_ptr, peer_ptr, rframe_length) do{\
                             tst_parse_receive_data(buf_ptr, get_length, frame_type,checksum,cmd_ptr, local_ptr, peer_ptr, rframe_length);\
                          }while(0)                                                                     
#endif  //#if defined(__USB_HIGH_SPEED_COM_PORT_ENABLE__)

//DSP-MCU Sharing memory exchange block
typedef struct
{
  unsigned int header;  //should be 0x2454CDEF
  unsigned short verno; //should be 0x1
  unsigned short length;  //sizeof(tst_dsp_shared_mem_ctrl_block_t)  
}
tst_viti_shared_mem_buf_info_block_header_t;

typedef struct
{
  unsigned int cmd_buf_ptr; //point to MCU=>DSP data buffer
  unsigned int cmd_buf_length; //
  unsigned int cmd_buf_ptr_start; //the start pointer of cmd_buf_ptr
  unsigned int cmd_buf_ptr_end; //the end pointer of cmd_buf_ptr  
  unsigned int log_buf_ptr; //point to DSP=>MCU data buffer
  unsigned int log_buf_length; //
  unsigned int log_buf_ptr_start; //the start pointer of log_buf_ptr
  unsigned int log_buf_ptr_end; //the end pointer of log_buf_ptr
}
tst_viti_shared_mem_buf_info_block_t;

typedef struct
{
  unsigned int header;  //should be 0x2454CDEF
  unsigned short verno; //should be 0x1
  unsigned short length;  //sizeof(tst_dsp_shared_mem_ctrl_block_t)  
  unsigned int cmd_buf_ptr; //point to MCU=>DSP data buffer
  unsigned int cmd_buf_length; //
  unsigned int cmd_buf_ptr_start; //the start pointer of cmd_buf_ptr
  unsigned int cmd_buf_ptr_end; //the end pointer of cmd_buf_ptr  
  unsigned int log_buf_ptr; //point to DSP=>MCU data buffer
  unsigned int log_buf_length; //
  unsigned int log_buf_ptr_start; //the start pointer of log_buf_ptr
  unsigned int log_buf_ptr_end; //the end pointer of log_buf_ptr
}
tst_viti_shared_mem_ctrl_block_t;

#define TST_VITI_SHARE_MEM_HEADER (0x2454CDEF)
#define TST_VITI_SHARE_MEM_VERNO (0x1)
#define TST_VITI_SHARE_MEM_BUF_SIZE (sizeof(tst_viti_shared_mem_ctrl_block_t))

#define TST_VITI_EVENT_USB_HS_WRITE_OK   0x01
#define TST_VITI_EVENT_USB_WRITE_OK       0x02

typedef enum
{
	TST_FREE_MOD_TR,
	TST_FREE_MOD_TST,
	TST_FREE_MOD_TFT,
	TST_FREE_MOD_END	
}
tst_free_mod_enum_t;

typedef enum 
{
  MEM_SYS, 
  MEM_BB, 
  MEM_DSP, 
  MEM_SLA,
#if defined(__FCORE_MEMORY_DUMP_FROM_ARM__)
  MEM_DMDSP,
#endif  //#if defined(__FCORE_MEMORY_DUMP_FROM_ARM__)
#if defined(__AST_TL1_TDD__)
  MEM_AST,
#endif  
  MEM_MMv2,
  MEM_TYPE_END,
} Tst_Mem_Type;

typedef enum
{
  TST_TR_CMD_TRIGGER_CCCI,
  TST_TR_CMD_SP_USB_THROUGHPUT_MEASURE,
  TST_TR_CMD_END
}
TST_TR_INTERNAL_CMD_enum_t;

#if defined(__SLIM_PROJECT_32_3__) || defined(__SLIM_PROJECT_16_3__) || defined( __32_3_SEG__)|| defined( __16_3_SEG__)
  #define ASSERT_RS232_BUFFER_LENGTH         672
#else
  #define ASSERT_RS232_BUFFER_LENGTH         1300
#endif

#if defined(__LOGACC_ENABLE__)
  #define LGA_HEADER_LEN 4  //4 for 1 ready byte + 3 length bytes
#else
  #define LGA_HEADER_LEN 0  
#endif  //#if defined(__LOGACC_ENABLE__) && !defined(UNIT_TEST)

// 4 for "STX, LenHi, LenLo, frame_type"
#define TST_LOST_IND_ARY_MAX_SIZ (36)
#define FRAME_DROPPING_INDICATOR_LEN  (LGA_HEADER_LEN+4 + sizeof(tst_brief_trace_header_struct) + 16)

#ifdef __TST_PERFORMANCE_PROFILE__
  #define TST_PROFILE_START(name) SLA_CustomLogging(name,1);
  #define TST_PROFILE_STOP(name) SLA_CustomLogging(name,0);
  #define TST_PROFILE_MARK(name) SLA_CustomLogging(name,2);
#else
  #define TST_PROFILE_START(name) do{;}while(0)
  #define TST_PROFILE_STOP(name) do{;}while(0)
  #define TST_PROFILE_MARK(name) do{;}while(0)
#endif

#ifdef __TST_UT_DEBUG_ENABLE__
  void tst_ut_systrace(char *format,...);
#else //__TST_UT_DEBUG_ENABLE__
  #define tst_ut_systrace(...)
#endif  //__TST_UT_DEBUG_ENABLE__


//define the waiting interval
#define TST_ASSERT_GET_BYTES_TIMEOUT_VALUE 4096
//Timestamp update Facilities
extern kal_uint32 L1I_GetTimeStamp(void);

#if defined(__MTK_TARGET__) || defined(__TST_ON_AOS_PC__)
  extern kal_uint32 tst_cur_timestamp;
  #define L1I_GET_TIMESTAMP() tst_cur_timestamp
#else
  #define L1I_GET_TIMESTAMP L1I_GetTimeStamp
#endif

#ifdef __TST_PERFORMANCE_PROFILE__
  #define TST_PROFILE_START(name) SLA_CustomLogging(name,1);
  #define TST_PROFILE_STOP(name) SLA_CustomLogging(name,0);
  #define TST_PROFILE_MARK(name) SLA_CustomLogging(name,2);
#else
  #define TST_PROFILE_START(name) do{;}while(0)
  #define TST_PROFILE_STOP(name) do{;}while(0)
  #define TST_PROFILE_MARK(name) do{;}while(0)
#endif

#define TST_RING_BUF_POS_UPDATE(pos, size) do{if(pos >= size) pos -= size;}while(0)
#define TST_RING_BUF_POS_ADD(pos, orgval, val, size) do{\
                                                        pos = orgval + val;\
                                                        if(pos >= size)\
                                                          pos -= size;\
                                                      }while(0)
#define TST_RING_BUF_POS_ADD_AND_WRAP(pos, orgval, val, size, wrap) do{\
															pos = orgval + val;\
															if(pos >= size)\
															  {pos -= size; wrap=KAL_TRUE;}\
														  }while(0)

//We allows users to register callback function for UT msg injection
//By this mechanism, users can do the deliberated actions on the msg content before sending data
//For example, we can replace the control buffer inside UT msgs to the fixed mem pool 
#define TST_UT_MSG_REPLACE_COUNT (4)

#define TST_DUMP_FILE_CLIP_TMP_BUF_SIZE (512)

#if defined(__MTK_TARGET__)
  //#define __tstrwdata __attribute__((section ("INTERNRW"))) 
  //#define __tstrodata __attribute__((section ("INTERNCONST"))) 
  //#define __tstzidata __attribute__((zero_init, section ("INTERNZI"))) 
  #define __tstrwdata
  #define __tstrodata 
  #define __tstzidata  
  #define __tstnczidata __attribute__((zero_init, section ("NONCACHEDZI"))) 
  #define __tstnczidata4 __attribute__((zero_init, section ("NONCACHEDZI"),aligned(4)))
  #define __tstncrwdata4 __attribute__((section ("NONCACHEDRW"),aligned(4)))
  #define __tstnczidata16 __attribute__((zero_init, section ("NONCACHEDZI") , aligned(16)))
  #define __tstnczidata32 __attribute__((zero_init, section ("NONCACHEDZI") , aligned(32)))
  #define __tstzidata4 __attribute__((aligned (4)))  
  #define __tstintsramrwdata __attribute__ ((section ("INTSRAM_RW")))
  
#else //#if defined(__MTK_TARGET__)
  #define __tstrwdata 
  #define __tstrodata 
  #define __tstzidata 
  #define __tstnczidata
  #define __tstnczidata4
  #define __tstncrwdata4 
  #define __tstnczidata16
  #define __tstnczidata32
  #define __tstzidata4
  #define __tstintsramrwdata
  
#endif //#if defined(__MTK_TARGET__)

#endif  //#ifndef __TST_INTERNAL_DEF_H__ 
 
