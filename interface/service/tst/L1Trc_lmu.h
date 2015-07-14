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
 * L1Trc_lmu.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file contains the variable declaraed and macr defined for layer 1 
 *	 trace functionalitywhen LMU Logging is enabled
 *   When __TST_LMU_LOGGING__ is defined, L1Trc_lmu.c will replace L1Trc.c
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#if defined(__TST_LMU_LOGGING__) || defined(__TST_MALMO_SUPPORT__)
#ifndef __L1_HW_TRACE_H__
#define __L1_HW_TRACE_H__
 
#include <string.h> //for memcpy
#include "kal_public_api.h"
#include "tst_lmu_hw.h"
#include "dcl.h"  //for uart port

/*************************************/
/* Definition used in generated code */
/*************************************/

/************/
/*Functions */
/************/

/*******************/
/* Variable        */
/*******************/
#ifndef TRC_EXT
  #ifdef TRC_C
  	#define TRC_EXT 
  #else
  	#define TRC_EXT extern
  #endif
#endif  //TRC_EXT

extern kal_bool lmu_fifo_full;
TRC_EXT kal_uint32 lmu_data_lost_count;
extern DCL_DEV   tst_L1Trc_port;
//For UART logging compatible
extern  kal_uint32 SaveAndSetIRQMask(void);
extern void RestoreIRQMask(kal_uint32);
extern kal_bool trc_check_vacancy(kal_uint32);
extern kal_bool g_tst_alc_l1_logging_enable;

#ifdef __TST_MALMO_SUPPORT__
  extern void trc_send_l1_word(kal_uint32 data);
  extern void trc_request_L1_space(kal_uint32 alc_pkt_size);
#endif  //#ifdef __TST_MALMO_SUPPORT__

/*******************************/
/* Macro for retrieving values */
/*******************************/

/*************************************/
/* Definition used in generated code */
/*************************************/

/*************************************/
/* Common Macros                     */
/*************************************/
//If the L1 token is modified, Please search the token first, 0xA6;
#ifdef __TST_LMU_LOGGING__
  #define TRC_WRITE_L1_LOST_INFO()                                              \
    do{                                                                       \
        kal_uint32 OutInt = 0xA20004A6;                                       \
        LMU_Write_Short_Word(OutInt);                                       \
        OutInt = (lmu_data_lost_count<<8)+0xFC;                               \
        LMU_Write_Short_Word(OutInt);                                       \
        lmu_data_lost_count=0;                                                \
      }while(0)
#else //__TST_LMU_LOGGING__
  #define TRC_WRITE_L1_LOST_INFO() do{}while(0)
#endif  //__TST_LMU_LOGGING__      


//Willie: Eliminate LMU related code
#define TRC_START_FILL_HEAER_PREPARE(NoBytes)  do{\
                                            kal_char checksum;                                            \
                                            OutInt = (((NoBytes+3)/4*4)<<8)+0xA6;                         \
                                            checksum = 0xA6 ^ ((OutInt>>8)&0xFF) ^ ((OutInt>>16)&0xFF);   \
                                            OutInt += ((kal_uint32)(checksum) << 24);                     \
                                            curOutBufPtr = (unsigned int*)outBuf;                         \
                                            *(curOutBufPtr++) = OutInt;                                   \
                                          }while(0)

//fill one character
#undef TRC_MAKE_CHAR_0c                                               
#define TRC_MAKE_CHAR_0c(buffer, offset, value)  do{OutInt = ((unsigned int)value&0xFF);}while(0)
#undef TRC_MAKE_CHAR_1c                                               
#define TRC_MAKE_CHAR_1c(buffer, offset, value)  do{OutInt += (((unsigned int)value&0xFF)<<8);}while(0)
#undef TRC_MAKE_CHAR_2c                                               
#define TRC_MAKE_CHAR_2c(buffer, offset, value)  do{OutInt += (((unsigned int)value&0xFF)<<16);}while(0)
#undef TRC_MAKE_CHAR_3c                                               
#define TRC_MAKE_CHAR_3c(buffer, offset, value)  do{OutInt += (((unsigned int)value&0xFF)<<24);\
                                                    *(curOutBufPtr++) = OutInt;  \
                                                   }while(0)

//fill 2 bytes short
//Catcher L1 parsing uses the big edianess
#undef TRC_MAKE_SHORT_0c                                               
#define TRC_MAKE_SHORT_0c(buffer, offset, value)  do{kal_uint32 tmpEdianInt = (((unsigned int)value&0xFF00)>>8)+(((unsigned int)value&0xFF)<<8);\
                                                     OutInt = tmpEdianInt;}while(0)
#undef TRC_MAKE_SHORT_1c                                               
#define TRC_MAKE_SHORT_1c(buffer, offset, value)  do{kal_uint32 tmpEdianInt = (((unsigned int)value&0xFF00)>>8)+(((unsigned int)value&0xFF)<<8);\
                                                     OutInt += (tmpEdianInt<<8);}while(0)
#undef TRC_MAKE_SHORT_2c                                               
#define TRC_MAKE_SHORT_2c(buffer, offset, value)  do{kal_uint32 tmpEdianInt = (((unsigned int)value&0xFF00)>>8)+(((unsigned int)value&0xFF)<<8);\
                                                     OutInt += (tmpEdianInt<<16);      \
                                                     *(curOutBufPtr++) = OutInt;          \
                                                  }while(0)
#undef TRC_MAKE_SHORT_3c                                               
#define TRC_MAKE_SHORT_3c(buffer, offset, value)  do{OutInt += ( (((unsigned int)value&0xFF00)>>8)<<24);        \
                                                     *(curOutBufPtr++) = OutInt;          \
                                                     OutInt = ((unsigned int)value&0xFF);       \
                                                  }while(0)

//fill the 3 bytes FN
#undef TRC_MAKE_FN_0c                                               
#define TRC_MAKE_FN_0c(buffer, offset, value)  do{kal_uint32 tmpEdianInt = (((unsigned int)value&0xFF0000)>>16)+((unsigned int)value&0xFF00)+(((unsigned int)value&0xFF)<<16);\
                                                  OutInt = tmpEdianInt;}while(0)
#undef TRC_MAKE_FN_1c                                               
#define TRC_MAKE_FN_1c(buffer, offset, value)  do{kal_uint32 tmpEdianInt = (((unsigned int)value&0xFF0000)>>16)+(((unsigned int)value&0xFF00))+(((unsigned int)value&0xFF)<<16);\
                                                  OutInt += (tmpEdianInt<<8);     \
                                                  *(curOutBufPtr++) = OutInt;          \
                                                 }while(0)
#undef TRC_MAKE_FN_2c                                               
#define TRC_MAKE_FN_2c(buffer, offset, value)  do{kal_uint32 tmpEdianInt = (((unsigned int)value&0xFF0000)>>16)+((unsigned int)value&0xFF00);\
                                                  OutInt += (tmpEdianInt<<16);      \
                                                  *(curOutBufPtr++) = OutInt;          \
                                                  OutInt = (((unsigned int)value&0xFF));      \
                                                 }while(0)
#undef TRC_MAKE_FN_3c                                               
#define TRC_MAKE_FN_3c(buffer, offset, value)  do{kal_uint32 tmpEdianInt = (((unsigned int)value&0xFF00)>>8)+(((unsigned int)value&0xFF)<<8);\
                                                  OutInt += (((unsigned int)value&0xFF0000)<<8);        \
                                                  *(curOutBufPtr++) = OutInt;          \
                                                  OutInt = tmpEdianInt;       \
                                                 }while(0)

//fill 4 bytes LONG
#undef TRC_MAKE_LONG_0c                                               
#define TRC_MAKE_LONG_0c(buffer, offset, value)  do{kal_uint32 tmpEdianInt = ((unsigned int)value>>24)+(((unsigned int)value&0xFF0000)>>8)+(((unsigned int)value&0xFF00)<<8)+(((unsigned int)value&0xFF)<<24);\
                                                    OutInt = tmpEdianInt;                      \
                                                    *(curOutBufPtr++) = OutInt;          \
                                                   }while(0)
#undef TRC_MAKE_LONG_1c                                               
#define TRC_MAKE_LONG_1c(buffer, offset, value)  do{kal_uint32 tmpEdianInt = (((unsigned int)value&0xFF000000)>>16)+((unsigned int)value&0xFF0000)+(((unsigned int)value&0xFF00)<<16);\
                                                    OutInt += tmpEdianInt;                \
                                                    *(curOutBufPtr++) = OutInt;          \
                                                    OutInt = ((unsigned int)value&0xFF);                \
                                                  }while(0)
#undef TRC_MAKE_LONG_2c                                               
#define TRC_MAKE_LONG_2c(buffer, offset, value)  do{kal_uint32 tmpEdianInt = (((unsigned int)value&0xFF000000)>>8)+(((unsigned int)value&0xFF0000)<<8);\
                                                    OutInt += tmpEdianInt;               \
                                                    *(curOutBufPtr++) = OutInt;          \
                                                    tmpEdianInt = (((unsigned int)value&0xFF00)>>8)+(((unsigned int)value&0xFF)<<8);\
                                                     OutInt = tmpEdianInt;               \
                                                  }while(0)
#undef TRC_MAKE_LONG_3c                                               
#define TRC_MAKE_LONG_3c(buffer, offset, value)  do{kal_uint32 tmpEdianInt = (((unsigned int)value&0xFF0000)>>16)+((unsigned int)value&0xFF00)+(((unsigned int)value&0xFF)<<16);\
                                                    OutInt += ((unsigned int)value&0xFF000000);               \
                                                    *(curOutBufPtr++) = OutInt;          \
                                                    OutInt = tmpEdianInt;                 \
                                                  }while(0)


#if defined(__L1BOXSTER__)
//In L1BOXSTER mode, the input paramters are 3

//insert the padding character
//padding at the forth bytes in a word
#undef TRC_PAD_CHAR
#define TRC_PAD_CHAR(buffer, offset, char_value) do{\
										OutInt = ((OutInt&0xFFFFFF)+((unsigned int)char_value<<24));\
										*(curOutBufPtr++) = OutInt;}while(0)
//insert the padding short
//padding at the third and forth bytes in a word
#undef TRC_PAD_SHORT
#define TRC_PAD_SHORT(buffer, offset, short_value) do{\
										  OutInt = ((OutInt&0xFFFF)+((unsigned int)short_value<<16));\
										  *(curOutBufPtr++) = OutInt;}while(0)
//insert the padding 3 bytes
//padding at the second, third and forth bytes in a word
#undef TRC_PAD_FN
#define TRC_PAD_FN(buffer, offset, fn_value) do{\
									OutInt = ((OutInt&0xFF)+((unsigned int)fn_value<<8));\
									*(curOutBufPtr++) = OutInt;}while(0)
#else
//insert the padding character
//padding at the forth bytes in a word
#undef TRC_PAD_CHAR
#define TRC_PAD_CHAR(char_value) do{\
                                    OutInt = ((OutInt&0xFFFFFF)+((unsigned int)char_value<<24));\
                                    *(curOutBufPtr++) = OutInt;}while(0)
//insert the padding short
//padding at the third and forth bytes in a word
#undef TRC_PAD_SHORT
#define TRC_PAD_SHORT(short_value) do{\
                                      OutInt = ((OutInt&0xFFFF)+((unsigned int)short_value<<16));\
                                      *(curOutBufPtr++) = OutInt;}while(0)
//insert the padding 3 bytes
//padding at the second, third and forth bytes in a word
#undef TRC_PAD_FN
#define TRC_PAD_FN(fn_value) do{\
                                OutInt = ((OutInt&0xFF)+((unsigned int)fn_value<<8));\
                                *(curOutBufPtr++) = OutInt;}while(0)
#endif

#undef TRC_SEND_NON_LMU
#define TRC_SEND_NON_LMU(buffer, offset)  do{\
                                  kal_uint32 data_size = ((unsigned int)curOutBufPtr-(unsigned int) outBuf);\
                                  memcpy(&buffer[offset],(unsigned char*)outBuf, data_size);\
                                  offset += data_size;\
                              }while(0)

#ifdef __TST_LMU_LOGGING__
  #define TRC_LMU_SEND_2W(outBuf) lmu_issue_2words_burst_write(outBuf,(volatile kal_uint32 *)LMU_SHORT_DATA_ADDR)
  #define TRC_LMU_SEND_3W(outBuf) lmu_issue_3words_burst_write(outBuf,(volatile kal_uint32 *)LMU_SHORT_DATA_ADDR)
  #define TRC_LMU_SEND_4W(outBuf) lmu_issue_4words_burst_write(outBuf,(volatile kal_uint32 *)LMU_SHORT_DATA_ADDR)
  #define TRC_LMU_SEND_5W(outBuf) lmu_issue_5words_burst_write(outBuf,(volatile kal_uint32 *)LMU_SHORT_DATA_ADDR)
  #define TRC_LMU_SEND_6W(outBuf) lmu_issue_6words_burst_write(outBuf,(volatile kal_uint32 *)LMU_SHORT_DATA_ADDR)
  #define TRC_LMU_SEND_7W(outBuf) lmu_issue_7words_burst_write(outBuf,(volatile kal_uint32 *)LMU_SHORT_DATA_ADDR)  
#else //#ifdef __TST_LMU_LOGGING__
  #define TRC_LMU_SEND_2W(outBuf) do{}while(0)
  #define TRC_LMU_SEND_3W(outBuf) do{}while(0)
  #define TRC_LMU_SEND_4W(outBuf) do{}while(0)
  #define TRC_LMU_SEND_5W(outBuf) do{}while(0)
  #define TRC_LMU_SEND_6W(outBuf) do{}while(0)
  #define TRC_LMU_SEND_7W(outBuf) do{}while(0)  
#endif  //#ifdef __TST_LMU_LOGGING__

#ifdef __TST_MALMO_SUPPORT__
  #define TRC_BUFFER_FULL_ALC_SEND() do{\
                                       kal_uint32* tmpOutPtr;\
                                       for (tmpOutPtr = outBuf;tmpOutPtr < curOutBufPtr; ++tmpOutPtr)\
                                         trc_send_l1_word(*tmpOutPtr);\
                                       }while(0)
#else //#ifdef __TST_MALMO_SUPPORT__
  #define TRC_BUFFER_FULL_ALC_SEND() do{}while(0)
#endif  //#ifdef __TST_MALMO_SUPPORT__

#undef TRC_BUFFER_FULL
#define TRC_BUFFER_FULL(buffer,offset) \
                         if (g_tst_alc_l1_logging_enable){                   \
                           TRC_BUFFER_FULL_ALC_SEND();                               \
                         }else{                                                      \
                           TRC_SEND_NON_LMU(buffer,offset);                          \
                         }                                                           \
                         curOutBufPtr = (unsigned int*)outBuf;                       \
                         do{}while(0)

  //savedMask is for UART logging compatible
  #undef TRC_START_FILL
  #define TRC_START_FILL(NoBytes)                                               \
      kal_uint32 savedMask=0;                                                   \
      kal_uint32 outBuf[7];                                                     \
      kal_uint32 OutInt;                                                        \
      kal_uint32* curOutBufPtr;                                                 \
      unsigned int TRC_LOCAL;                                                   \
      if (g_tst_alc_l1_logging_enable){                                 \
        trc_request_L1_space(NoBytes);                                          \
        TRC_START_FILL_HEAER_PREPARE(NoBytes);                                  \
      }else{                                                                    \
        savedMask = SaveAndSetIRQMask();                                        \
        if(!trc_check_vacancy(NoBytes)){                                        \
          RestoreIRQMask(savedMask);                                            \
          return;                                                               \
        }                                                                       \
        curOutBufPtr = (kal_uint32*)outBuf;                                     \
      }                                                                         \
      do{}while(0)   

  #undef TRC_START_FILL_TASK
  #define TRC_START_FILL_TASK TRC_START_FILL
  #undef TRC_START_FILL_ISR
  #define TRC_START_FILL_ISR TRC_START_FILL

#if defined(__TST_UNIT_TEST__)
  TRC_EXT kal_uint32 trc_previous_bufptr;
  #undef TRC_GET_OUTPUT_DATA
  #define TRC_GET_OUTPUT_DATA(ptr,size)  do{\
                                             if (tst_L1Trc_port != uart_port_lmu){\
                                               ptr = (unsigned int*)trc_buf;\
                                               size = trc_bufptr-trc_previous_bufptr;\
                                               trc_previous_bufptr = trc_bufptr;\
                                             }else{\
                                               ptr=(unsigned int*)outBuf;\
                                               size = (unsigned int)curOutBufPtr - (unsigned int)outBuf;\
                                             }\
                                          }while(0)
#endif  //#if defined(__TST_UNIT_TEST__)                                          

  #undef TRC_END_FILL_NON_LMU
  #define TRC_END_FILL_NON_LMU() do{\
                                  TRC_SEND_NON_LMU(trc_buf,trc_bufptr);\
                                  RestoreIRQMask(savedMask);\
                                }while(0)


  #undef TRC_END_FILL_0w 
  #define TRC_END_FILL_0w  if (tst_L1Trc_port != uart_port_lmu && !g_tst_alc_l1_logging_enable){  \
                             RestoreIRQMask(savedMask);                                  \
                           }                                                             \
                           do{}while(0)

  #undef TRC_END_FILL_1w 
  #define TRC_END_FILL_1w   if (g_tst_alc_l1_logging_enable){                   \
                               TRC_BUFFER_FULL_ALC_SEND();                              \
                            }else{                                                      \
                               TRC_END_FILL_NON_LMU();                                  \
                            }                                                           \
                            do{}while(0)

  #undef TRC_END_FILL_2w 
  #define TRC_END_FILL_2w   if (g_tst_alc_l1_logging_enable){                   \
                               TRC_BUFFER_FULL_ALC_SEND();                              \
                            }else{                                                      \
                               TRC_END_FILL_NON_LMU();                                  \
                            }                                                           \
                            do{}while(0)

  #undef TRC_END_FILL_3w 
  #define TRC_END_FILL_3w   if (g_tst_alc_l1_logging_enable){                   \
                               TRC_BUFFER_FULL_ALC_SEND();                              \
                            }else{                                                      \
                               TRC_END_FILL_NON_LMU();                                  \
                            }                                                           \
                            do{}while(0)

  #undef TRC_END_FILL_4w 
  #define TRC_END_FILL_4w   if (g_tst_alc_l1_logging_enable){                   \
                               TRC_BUFFER_FULL_ALC_SEND();                              \
                            }else{                                                      \
                               TRC_END_FILL_NON_LMU();                                  \
                            }                                                           \
                            do{}while(0)

  #undef TRC_END_FILL_5w 
  #define TRC_END_FILL_5w   if (g_tst_alc_l1_logging_enable){                   \
                               TRC_BUFFER_FULL_ALC_SEND();                              \
                            }else{                                                      \
                               TRC_END_FILL_NON_LMU();                                  \
                            }                                                           \
                            do{}while(0)

  #undef TRC_END_FILL_6w 
  #define TRC_END_FILL_6w   if (g_tst_alc_l1_logging_enable){                   \
                               TRC_BUFFER_FULL_ALC_SEND();                              \
                            }else{                                                      \
                               TRC_END_FILL_NON_LMU();                                  \
                            }                                                           \
                            do{}while(0)

  #undef TRC_END_FILL_7w 
  #define TRC_END_FILL_7w   if (g_tst_alc_l1_logging_enable){                   \
                               TRC_BUFFER_FULL_ALC_SEND();                              \
                            }else{                                                      \
                               TRC_END_FILL_NON_LMU();                                  \
                            }                                                           \
                            do{}while(0)

  #undef TRC_TASK_BUFFER_FULL  
  #define TRC_TASK_BUFFER_FULL(TRC_LOCAL) TRC_BUFFER_FULL(trc_buf,trc_bufptr)
  #undef TRC_ISR_BUFFER_FULL
  #define TRC_ISR_BUFFER_FULL(TRC_LOCAL) TRC_BUFFER_FULL(trc_buf,trc_bufptr)
  
  #undef TRC_END_FILL_TASK_0w 
  #undef TRC_END_FILL_TASK_1w 
  #undef TRC_END_FILL_TASK_2w 
  #undef TRC_END_FILL_TASK_3w 
  #undef TRC_END_FILL_TASK_4w 
  #undef TRC_END_FILL_TASK_5w 
  #undef TRC_END_FILL_TASK_6w 
  #undef TRC_END_FILL_TASK_7w 
  
  #undef TRC_END_FILL_ISR_0w
  #undef TRC_END_FILL_ISR_1w
  #undef TRC_END_FILL_ISR_2w
  #undef TRC_END_FILL_ISR_3w
  #undef TRC_END_FILL_ISR_4w
  #undef TRC_END_FILL_ISR_5w
  #undef TRC_END_FILL_ISR_6w
  #undef TRC_END_FILL_ISR_7w
  
  #define TRC_END_FILL_TASK_0w TRC_END_FILL_0w
  #define TRC_END_FILL_TASK_1w TRC_END_FILL_1w
  #define TRC_END_FILL_TASK_2w TRC_END_FILL_2w
  #define TRC_END_FILL_TASK_3w TRC_END_FILL_3w
  #define TRC_END_FILL_TASK_4w TRC_END_FILL_4w
  #define TRC_END_FILL_TASK_5w TRC_END_FILL_5w
  #define TRC_END_FILL_TASK_6w TRC_END_FILL_6w
  #define TRC_END_FILL_TASK_7w TRC_END_FILL_7w
  
  #define TRC_END_FILL_ISR_0w TRC_END_FILL_0w
  #define TRC_END_FILL_ISR_1w TRC_END_FILL_1w
  #define TRC_END_FILL_ISR_2w TRC_END_FILL_2w
  #define TRC_END_FILL_ISR_3w TRC_END_FILL_3w
  #define TRC_END_FILL_ISR_4w TRC_END_FILL_4w
  #define TRC_END_FILL_ISR_5w TRC_END_FILL_5w
  #define TRC_END_FILL_ISR_6w TRC_END_FILL_6w
  #define TRC_END_FILL_ISR_7w TRC_END_FILL_7w

#endif  //#ifndef __L1_TRACE_H__
#endif  //#if defined(__TST_LMU_LOGGING__) || defined(__TST_MALMO_SUPPORT__)
