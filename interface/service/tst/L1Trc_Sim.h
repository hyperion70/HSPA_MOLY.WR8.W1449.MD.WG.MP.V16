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
 * L1Trc_Sim.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   Move out from L1trc.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifdef L1_SIM
 //For L1 Sime evironment
#ifndef __L1TRC_L1SIM_H__
#define __L1TRC_L1SIM_H__

#include "kal_public_api.h"

#define TRC_START_FILL_TASK TRC_START_FILL
#define TRC_END_FILL_TASK   TRC_END_FILL
#define TRC_START_FILL_ISR  TRC_START_FILL
#define TRC_END_FILL_ISR    TRC_END_FILL

//LMU compatible definitions
#define TRC_END_FILL_TASK_0w TRC_END_FILL
#define TRC_END_FILL_TASK_1w TRC_END_FILL
#define TRC_END_FILL_TASK_2w TRC_END_FILL
#define TRC_END_FILL_TASK_3w TRC_END_FILL
#define TRC_END_FILL_TASK_4w TRC_END_FILL
#define TRC_END_FILL_TASK_5w TRC_END_FILL
#define TRC_END_FILL_TASK_6w TRC_END_FILL
#define TRC_END_FILL_TASK_7w TRC_END_FILL

#define TRC_END_FILL_ISR_0w TRC_END_FILL
#define TRC_END_FILL_ISR_1w TRC_END_FILL
#define TRC_END_FILL_ISR_2w TRC_END_FILL
#define TRC_END_FILL_ISR_3w TRC_END_FILL
#define TRC_END_FILL_ISR_4w TRC_END_FILL
#define TRC_END_FILL_ISR_5w TRC_END_FILL
#define TRC_END_FILL_ISR_6w TRC_END_FILL
#define TRC_END_FILL_ISR_7w TRC_END_FILL

typedef void (*trc_setfilterfunc)(unsigned char *);

extern kal_char UL1TimeBuf[256];
extern kal_uint32 UL1TimeBufIdx;
extern kal_char L1TimeBuf[256];
extern kal_uint32 L1TimeBufIdx;

#define UL1_FN_SIZE 13
#define L1_FN_SIZE 10
#ifdef __GEMINI_GSM__
#define L1_FN_2_SIZE 11
#endif  //#ifdef __GEMINI_GSM__

#ifdef __GEMINI_WCDMA__
#define UL1_FN_2_SIZE 14
#endif  //#ifdef __GEMINI_WCDMA__
#define UL1_L1_FN_SIZE UL1_FN_SIZE+L1_FN_SIZE

#define TRC_SET_FILTER_FUNC			trc_setfilterfunc	
extern TRC_SET_FILTER_FUNC TRC_FILTER_FUNC_ARRAY[];
extern unsigned short TRC_NBR_MODULE;

/*Start filling data*/
//Allocate a loca buffer, prepare the current index, and calculate the checksum
#define TRC_START_FILL(NoBytes)                                 \
    extern int Catcher_Enable;                                  \
    kal_char tmpBuf[256];                                       \
    kal_uint32 cur_idx=3;                                       \
    kal_char checksum= (kal_char)(0xA5^((kal_char)NoBytes));    \
    if (Catcher_Enable != 1)  return;                           \
    tmpBuf[0] = (kal_char) 0xA5;                                \
    tmpBuf[1] = ((kal_char)NoBytes);                            \
    tmpBuf[2] = 0;                                              \
    do {} while(0)

//Complete the L1 packet and send out via shared memory
//Check if UL1/L1 Time information are not sent
#define TRC_END_FILL                                \
    do {                                            \
      extern int SendToCatcher(char *buf, int size);\
      tmpBuf[cur_idx++] = checksum;                   \
      if (UL1TimeBufIdx !=0)                        \
      {                                             \
        SendToCatcher(UL1TimeBuf,UL1TimeBufIdx);    \
        UL1TimeBufIdx = 0;                          \
      }                                             \
      if (L1TimeBufIdx !=0)                         \
      {                                             \
        SendToCatcher(L1TimeBuf,L1TimeBufIdx);      \
        L1TimeBufIdx = 0;                           \
      }                                             \
      SendToCatcher(tmpBuf, cur_idx);               \
    }while(0)  


#define TRC_START_FILL_UL1Time(NoBytes)                          \
    extern int Catcher_Enable;                                   \
    kal_char* tmpBuf = &UL1TimeBuf[0];                           \
    kal_uint32 cur_idx=3;                                        \
    kal_char checksum=(kal_char)(0xA5 ^ ((kal_char)NoBytes));    \
    if (Catcher_Enable != 1)  return;                            \
    tmpBuf[0] = (kal_char) 0xA5;                                 \
    tmpBuf[1] = ((kal_char)NoBytes);                             \
    tmpBuf[2] = 0;                                               \
    do {} while(0)

//Complete the UL1 time information packet
//Keep it unsent untill the next L1 trace comes
#define TRC_END_FILL_UL1Time                        \
    do {                                            \
      tmpBuf[cur_idx++] = checksum;                   \
      UL1TimeBufIdx = cur_idx;                      \
    }while(0)  
    
#define TRC_START_FILL_L1Time(NoBytes)                           \
    extern int Catcher_Enable;                                   \
    kal_char* tmpBuf = &L1TimeBuf[0];                            \
    kal_uint32 cur_idx=3;                                        \
    kal_char checksum= (kal_char)((0xA5 ^ ((kal_char)NoBytes))); \
    if (Catcher_Enable != 1)  return;                            \
    tmpBuf[0] = (kal_char) 0xA5;                                 \
    tmpBuf[1] = ((kal_char)NoBytes);                             \
    tmpBuf[2] = 0;                                               \
    do {} while(0)


//Complete the UL1 time information packet
//Keep it unsent untill the next L1 trace comes
#define TRC_END_FILL_L1Time                         \
    do {                                            \
      tmpBuf[cur_idx++] = checksum;                   \
      L1TimeBufIdx = cur_idx;                       \
    }while(0)      

//Fill data bytes
#define TRC_MAKE_CHAR(buffer, offset, value)        \
    do {                                            \
      tmpBuf[cur_idx++] = (kal_char) value;         \
      checksum ^= (kal_char) value;                 \
    } while(0)

/* TRC_MAKE_BYTE */
#define TRC_MAKE_BYTE TRC_MAKE_CHAR

/* TRC_MAKE_UBYTE */
#define TRC_MAKE_UBYTE TRC_MAKE_CHAR

/* TRC_MAKE_SHORT */
#define TRC_MAKE_SHORT(buffer, offset, value)                      \
    do {                                                           \
        tmpBuf[cur_idx++] = (kal_char) (((value)>>8) & 0xFF);      \
        checksum ^= (kal_char) (((value)>>8) & 0xFF);              \
        tmpBuf[cur_idx++] = (kal_char) (value &0xFF);              \
        checksum ^= (kal_char) (value &0xFF);                      \
    } while(0)
    
/* TRC_MAKE_USHORT */
#define TRC_MAKE_USHORT TRC_MAKE_SHORT
    
/* TRC_MAKE_LONG */
#define TRC_MAKE_LONG(buffer, offset, value)                    \
    do {                                                        \
        tmpBuf[cur_idx++] = (kal_char) (((value)>>24) & 0xFF);  \
        checksum ^= (kal_char) (((value)>>24) & 0xFF);          \
        tmpBuf[cur_idx++] = (kal_char) (((value)>>16) & 0xFF);  \
        checksum ^= (kal_char) (((value)>>16) & 0xFF);          \
        tmpBuf[cur_idx++] = (kal_char) (((value)>>8) & 0xFF);   \
        checksum ^= (kal_char) (((value)>>8) & 0xFF);           \
        tmpBuf[cur_idx++] = (kal_char) (value & 0xFF);          \
        checksum ^= (kal_char) (value & 0xFF);                  \
    } while(0)
    
/* TRC_MAKE_ULONG */
#define TRC_MAKE_ULONG TRC_MAKE_LONG

/* TRC_MAKE_FN */
#define TRC_MAKE_FN(buffer, offset, value)                       \
    do {                                                         \
        tmpBuf[cur_idx++] = (kal_char) (((value)>>16) & 0xFF);   \
        checksum ^= (kal_char) (((value)>>16) & 0xFF);           \
        tmpBuf[cur_idx++] = (kal_char) (((value)>>8) & 0xFF);    \
        checksum ^= (kal_char) (((value)>>8) & 0xFF);            \
        tmpBuf[cur_idx++] = (kal_char) (value & 0xFF);           \
        checksum ^= (kal_char) (value & 0xFF);                   \
    } while(0)
   
//For LMU related macros compatible
#define TRC_MAKE_CHAR_0c TRC_MAKE_CHAR
#define TRC_MAKE_CHAR_1c TRC_MAKE_CHAR
#define TRC_MAKE_CHAR_2c TRC_MAKE_CHAR
#define TRC_MAKE_CHAR_3c TRC_MAKE_CHAR

#define TRC_MAKE_SHORT_0c TRC_MAKE_SHORT
#define TRC_MAKE_SHORT_1c TRC_MAKE_SHORT
#define TRC_MAKE_SHORT_2c TRC_MAKE_SHORT
#define TRC_MAKE_SHORT_3c TRC_MAKE_SHORT

#define TRC_MAKE_FN_0c TRC_MAKE_FN
#define TRC_MAKE_FN_1c TRC_MAKE_FN
#define TRC_MAKE_FN_2c TRC_MAKE_FN
#define TRC_MAKE_FN_3c TRC_MAKE_FN

#define TRC_MAKE_LONG_0c TRC_MAKE_LONG
#define TRC_MAKE_LONG_1c TRC_MAKE_LONG
#define TRC_MAKE_LONG_2c TRC_MAKE_LONG
#define TRC_MAKE_LONG_3c TRC_MAKE_LONG  

#define TRC_ISR_BUFFER_FULL(TRC_LOCAL)
#define TRC_TASK_BUFFER_FULL(TRC_LOCAL)
#define TRC_PAD_CHAR(char_value)
#define TRC_PAD_SHORT(short_value)
#define TRC_PAD_FN(fn_value)

#define TRC_MERGE_2S_MACRO(v1, v2) ( (kal_uint32)(v1&0xFFFF) + ( ((kal_uint32)v2)<<16 ))
#define TRC_MERGE_1S_2C_MACRO(v1, v2, v3) ( (kal_uint32)(v1&0xFFFF) + ( ( (kal_uint32)(v2&0xFF) )<<16) + ( ((kal_uint32)v3)<<24) )
#define TRC_MERGE_4C_MACRO(v1, v2, v3, v4) ( (kal_uint32)(v1&0xFF) + ( ((kal_uint32)(v2&0xFF))<<8) + ( ((kal_uint32)(v3&0xFF))<<16) + ( ((kal_uint32)v4)<<24))

kal_uint32 TRC_MERGE_2S_FUNC( kal_uint16 v1, kal_uint16 v2 );
kal_uint32 TRC_MERGE_1S_2C_FUNC( kal_uint16 v1, kal_char v2 , kal_char v3);
kal_uint32 TRC_MERGE_4C_FUNC( kal_char v1, kal_char v2 , kal_char v3, kal_char v4);

#define TRC_MERGE_2S(v1, v2) TRC_MERGE_2S_MACRO((v1), (v2))
#define TRC_MERGE_1S_2C(v1, v2, v3) TRC_MERGE_1S_2C_MACRO((v1), (v2), (v3))
#define TRC_MERGE_4C(v1, v2, v3, v4) TRC_MERGE_4C_MACRO((v1), (v2), (v3), (v4))
#endif  //__L1TRC_L1SIM_H__ 

#endif //#ifdef L1_SIM