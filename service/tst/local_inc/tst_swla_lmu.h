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
 *   tst_swla_lmu.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file provides macros for SWLA logging
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __TST_SWLA_LMU_H__ 
#define __TST_SWLA_LMU_H__

#include "dcl.h"
#include "tst_lmu_hw.h"
 
/*************************************************************************
* Typedefs
 *************************************************************************/
typedef enum
{
  SWLA_RAM_Logging,
  SWLA_LMU_Logging
}
SWLA_Logging_Type_Enum;

typedef enum 
{
   SWLA_TAG_NEST_BEGIN   = 0xE0,
   SWLA_TAG_NEST_END     = 0xE1,
   SWLA_TAG_SINGLE_LABEL = 0xE2,
   SWLA_TAG_BEGIN_POINT  = 0xE3,
   SWLA_TAG_END_POINT    = 0xE4
} SWLA_TAG_T;

typedef enum
{
  Custom_End,
  Custom_Start,
  Custom_Label
}SWLA_Action_Enum_t;

/*************************************************************************
* External variables
 *************************************************************************/
extern DCL_DEV   tst_PsTrc_port;
 
/*************************************************************************
* Useful macros
 *************************************************************************/ 
#if defined(__TST_MODULE__) && defined(__TST_DNT_LOGGING__)
  #define SWLA_Retrieve_Logging_Type(logging_type) do{\
                                                      if (tst_PsTrc_port == uart_port_lmu)\
                                                        logging_type = SWLA_LMU_Logging;\
                                                      else\
                                                        logging_type = SWLA_RAM_Logging;\
                                                     }while(0)
#else //#if defined(__TST_MODULE__) && defined(__TST_DNT_LOGGING__)
  #define SWLA_Retrieve_Logging_Type(logging_type) do{logging_type = SWLA_RAM_Logging;}while(0)
#endif  //#if defined(__TST_MODULE__) && defined(__TST_DNT_LOGGING__)                                                   

#define SWLA_LMU_Thread_Logging_Begin(thread_id, data_length) LMU_Write_CSM_Addr_TS((0x8000|(((data_length)+2)<<8)), thread_id)
#define SWLA_LMU_Thread_Logging_Finish() do{}while(0)

#define SWLA_LMU_ISR_Start_Logging_Begin(thread_id, data_length) LMU_Write_CSM_Addr_TS((0x8001|(((data_length)+2)<<8)), thread_id)
#define SWLA_LMU_ISR_Start_Logging_Finish() do{}while(0)

#define SWLA_LMU_ISR_End_Logging_Begin(thread_id, data_length) LMU_Write_CSM_Addr_TS((0x8002|(((data_length)+2)<<8)), thread_id)
#define SWLA_LMU_ISR_End_Logging_Finish() do{}while(0)

#define SWLA_LMU_Header_Packet_Begin(header_length) LMU_Write_CSM_Addr_TS((0x8004|(((header_length)+2)<<8)), 0)
#define SWLA_LMU_Header_Packet_Finish() do{}while(0)

#define SWLA_LMU_Custom_Logging_Begin(custom_id, data_length, action) do{\
                                                                        custom_id = ((custom_id>>8)<<8);\
                                                                        if (action == Custom_Start) custom_id += SWLA_TAG_NEST_BEGIN;\
                                                                        else if (action == Custom_End) custom_id += SWLA_TAG_NEST_END;\
                                                                        else custom_id += SWLA_TAG_SINGLE_LABEL;\
                                                                        LMU_Write_CSM_Addr_TS((0x8003|(((data_length)+2)<<8)), custom_id);\
                                                                      }while(0)
#define SWLA_LMU_Custom_Logging_Finish() do{}while(0)

#define SWLA_LMU_HW_Logging_Begin(custom_id, data_length, action) do{\
                                                                        custom_id = ((custom_id>>8)<<8);\
                                                                        if (action == Custom_Start) custom_id += SWLA_TAG_BEGIN_POINT;\
                                                                        else custom_id += SWLA_TAG_END_POINT;\
                                                                        LMU_Write_CSM_Addr_TS((0x8003|(((data_length)+2)<<8)), custom_id);\
                                                                      }while(0)

#define SWLA_LMU_HW_Logging_Finish() do{}while(0)

#define SWLA_LMU_Log_Data_ptr(ptr, ptr_length) LMU_Write_Short_Ary(ptr, ptr_length)
#define SWLA_LMU_Log_Word(word_data) LMU_Write_Short_Word(word_data)

#endif  //__TST_SWLA_LMU_H__
 
