/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2012
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

/*******************************************************************************
 *
 * Filename:
 * ---------
 * media.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * Audio Playback/Record general interface
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#include "kal_public_api.h"
#include "kal_general_types.h"
#include "kal_public_defs.h"
#include "reg_base.h"
#include "fs_type.h"
#include "kal_trace.h"
#include "string.h"
#include "fsal.h"
#include "audcoeff_default.h"

#include "ddload.h"
#include "l1audio.h"
#include "audio_def.h"
#include "speech_def.h"
#include "am.h"
#include "media.h"
#include "afe.h"
#include "audio_enum.h"
#include "l1sp_trc.h"
#include "fs_errcode.h"

#if defined(__AUDIO_COMPONENT_SUPPORT__)
#include "AudComUtil.h"
#endif

#if VERIFY_DATA_TO_DSP
extern void VERIFY_DATA_TO_DSP_START( void );
extern void VERIFY_DATA_TO_DSP_RESUME( void );
extern void VERIFY_DATA_TO_DSP_STOP( void );
#endif


const kal_uint16 samplePerFrame[] = {80,441,120,160,441,240,320,441,480};
const kal_uint8  framDuration[] = {10,40,10,10,20,10,10,10,10};
const kal_uint8  SampleRateTable[] = {
   0x00, /*8000*/   0x11,/* 11025 */ 0x12,/* 12000 */
   0x20, /*16000,*/ 0x21,/* 22050,*/ 0x22,/* 24000,*/
   0x40, /*32000,*/ 0x41,/* 44100,*/ 0x42 /* 48000 */
};


#if 0 
#if defined(MT6280) || defined(MT6589)
/* under construction !*/
#else
/* under construction !*/
#endif
#endif 

#define WAV_ABORT_STATE 0x40
#define RECORD_PRESILENCE_NUM 2  //60ms

static struct {
   mediaControl   ctrl;
   bool           waiting;
   bool           paused;
   uint16         aud_id;
   void           (*media_handler)( Media_Event event );
   int32          recorded_time;
   kal_uint32     uStopTime;
   bool           fTimeUp;
   uint8          presilence;
} media;

struct {
   kal_uint32 uCurOffset;
   kal_uint32 uResumeFrameOffset;
} audResumeInfo;

/* Functions for Ring Buffer Access */

/* Reset the read/write pointers and odd bye flags of ring buffer */
/* This function should be called in Media_SetBuffer to reset the media buffer */
// Rey: Checked
void rb_ClearRB( void )
{
   media.ctrl.read = 0;
   media.ctrl.write = 0;
   media.ctrl.ob_flag_r = false;
   media.ctrl.ob_flag_w = false;
}

/* Return the count of data (in byte) in ring buffer */
/* Note that the data unit of return value is BYTE!!! */
// Rey: Checked
int32 rb_GetByteCount( void )
{
   int32 count;
   count = (int32)media.ctrl.write - (int32)media.ctrl.read;
   if( count < 0 )
      count += media.ctrl.rb_size;
   count <<= 1;
   if( media.ctrl.ob_flag_r )
      count ++;
   if( media.ctrl.ob_flag_w )
      count ++;
   return count;
}

/* Return the remaining space (in byte) of ring buffer */
/* Note that the data unit of return value is BYTE!!! */
// Rey: Checked
int32 rb_GetFreeSpace( void )
{
   int32 count;
   count = (int32)media.ctrl.read - (int32)media.ctrl.write - 1;
   if( count < 0 )
      count += (int32)media.ctrl.rb_size;
   count <<= 1;
   if( media.ctrl.ob_flag_r )
      count --;
   if( media.ctrl.ob_flag_w )
      count --;
   return count;
}

/* Get a byte from ring buffer */
// Rey: Checked
bool rb_GetByte( uint8* data_8 )
{
   if( rb_GetByteCount()==0 )
      return false;     // Buffer underflow
   if( media.ctrl.ob_flag_r )
   {
      *data_8 = media.ctrl.odd_byte_r;
      media.ctrl.ob_flag_r = false;
   }
   else
   {
      // Special Case: there's only one byte in ring buffer and the byte is in odd_byte_w
      if( media.ctrl.read == media.ctrl.write )
      {
         *data_8 = media.ctrl.odd_byte_w;
         media.ctrl.ob_flag_w = false;
         return true;
      }
      *data_8 = (uint8)media.ctrl.rb_base[media.ctrl.read];
      media.ctrl.odd_byte_r = (uint8)(media.ctrl.rb_base[media.ctrl.read] >> 8);
      media.ctrl.ob_flag_r = true;
      if( ++media.ctrl.read == media.ctrl.rb_size )
         media.ctrl.read = 0;
   }
   return true;
}

/* Get a word from ring buffer */
// Rey: Checked
bool rb_GetWord( uint16* data_16 )
{
   if( rb_GetByteCount() < 2 )
      return false;     // Buffer underflow
   if( media.ctrl.ob_flag_r )
   {
      // Special case: there is only one word in ring buffer...
      if( media.ctrl.read == media.ctrl.write )
      {
         *data_16 = media.ctrl.odd_byte_r | ((uint16)media.ctrl.odd_byte_w << 8);
         media.ctrl.ob_flag_r = false;
         media.ctrl.ob_flag_w = false;
         return true;
      }
      *data_16 = media.ctrl.odd_byte_r | (media.ctrl.rb_base[media.ctrl.read] << 8);
      media.ctrl.odd_byte_r = (uint8)(media.ctrl.rb_base[media.ctrl.read] >> 8);
   }
   else
      *data_16 = media.ctrl.rb_base[media.ctrl.read];
   if( ++media.ctrl.read == media.ctrl.rb_size )
      media.ctrl.read = 0;
   return true;
}

/* Get a double word from ring buffer */
// Rey: Checked
bool rb_GetDWord( uint32* data_32 )
{
   if( rb_GetByteCount() < 4 )
      return false;     // Buffer underflow
   if( media.ctrl.ob_flag_r )
   {
      *data_32 = media.ctrl.odd_byte_r;
      *data_32 |= ((uint32)media.ctrl.rb_base[media.ctrl.read] << 8);
      if( ++media.ctrl.read == media.ctrl.rb_size )
         media.ctrl.read = 0;
      // Special Case: there is only one double-word in ring buffer...
      if( media.ctrl.read == media.ctrl.write )
      {
         *data_32 |= ((uint32)media.ctrl.odd_byte_w << 24);
         media.ctrl.ob_flag_r = false;
         media.ctrl.ob_flag_w = false;
         return true;
      }
      *data_32 |= ((uint32)media.ctrl.rb_base[media.ctrl.read] << 24);
      media.ctrl.odd_byte_r = (uint8)(media.ctrl.rb_base[media.ctrl.read] >> 8);
   }
   else
   {
      *data_32 = media.ctrl.rb_base[media.ctrl.read];
      if( ++media.ctrl.read == media.ctrl.rb_size )
         media.ctrl.read = 0;
      *data_32 |= ((uint32)media.ctrl.rb_base[media.ctrl.read] << 16);
   }
   if( ++media.ctrl.read == media.ctrl.rb_size )
      media.ctrl.read = 0;
   return true;
}

/* Peek the value of the incoming byte in ring buffer, without moving forward the read pointer */
// Rey: Checked
bool rb_PeekByte( uint8* data_8 )
{
   if( rb_GetByteCount()==0 )
      return false;     // Buffer underflow
   if( media.ctrl.ob_flag_r )
      *data_8 = media.ctrl.odd_byte_r;
   else
   {
      // Special Case: there's only one byte in ring buffer...
      if( media.ctrl.read == media.ctrl.write )
         *data_8 = media.ctrl.odd_byte_w;
      else
         *data_8 = (uint8)media.ctrl.rb_base[media.ctrl.read];
   }
   return true;
}

/* Peek the value of the incoming word in ring buffer, without moving forward the read pointer */
// Rey: Checked
bool rb_PeekWord( uint16* data_16 )
{
   if( rb_GetByteCount() < 2 )
      return false;     // Buffer underflow
   if( media.ctrl.ob_flag_r )
   {
      // Special Case: there is only one word in ring buffer
      if( media.ctrl.read == media.ctrl.write )
         *data_16 = media.ctrl.odd_byte_r | ((uint16)media.ctrl.odd_byte_w << 8);
      else
         *data_16 = media.ctrl.odd_byte_r | (media.ctrl.rb_base[media.ctrl.read] << 8);
   }
   else
      *data_16 = media.ctrl.rb_base[media.ctrl.read];
   return true;
}

/* Peek the value of the incoming double word in ring buffer, without moving forward the read pointer */
// Rey: Checked
bool rb_PeekDWord( uint32* data_32 )
{
   uint32 tmp_read;
   if( rb_GetByteCount() < 4 )
      return false;     // Buffer underflow
   tmp_read = media.ctrl.read;
   if( media.ctrl.ob_flag_r )
   {
      *data_32 = media.ctrl.odd_byte_r;
      *data_32 |= ((uint32)media.ctrl.rb_base[tmp_read] << 8);
      if( ++tmp_read == media.ctrl.rb_size )
         tmp_read = 0;
      if( tmp_read == media.ctrl.write )
         *data_32 |= ((uint32)media.ctrl.odd_byte_w << 24);
      else
         *data_32 |= ((uint32)media.ctrl.rb_base[tmp_read] << 24);
   }
   else
   {
      *data_32 = media.ctrl.rb_base[tmp_read];
      if( ++tmp_read == media.ctrl.rb_size )
         tmp_read = 0;
      *data_32 |= ((uint32)media.ctrl.rb_base[tmp_read] << 16);
   }
   return true;
}

/* Skip N byte in ring buffer, return the number of bytes skipped */
// Rey: Checked
uint32 rb_SkipNByte( uint32 skip_count )
{
   uint32 ret;
   if( skip_count == 0 )
      return 0;
   ret = rb_GetByteCount();
   if( ret <= skip_count )
   {
      rb_ClearRB();
      return ret;
   }
   ret = skip_count;
   if( media.ctrl.ob_flag_r )
   {
      media.ctrl.ob_flag_r = false;
      if( --skip_count == 0 )
         return 1;
   }
   media.ctrl.read += (skip_count >> 1);
   if( media.ctrl.read >= media.ctrl.rb_size )
      media.ctrl.read -= media.ctrl.rb_size;
   skip_count &= 0x01;
   if( skip_count == 0 )
      return ret;
   media.ctrl.odd_byte_r = (uint8)(media.ctrl.rb_base[media.ctrl.read] >> 8);
   media.ctrl.ob_flag_r = true;
   if( ++media.ctrl.read == media.ctrl.rb_size )
      media.ctrl.read = 0;
   return ret;
}

/* Skip N Words in ring buffer, return the number of words skipped */
// Rey: Checked
uint32 rb_SkipNWord( uint32 skip_count )
{
   uint32 ret;
   if( skip_count == 0 )
      return 0;
   ret = rb_GetByteCount();
   if( (ret >> 1) <= skip_count )
   {
      if((ret & 0x01) == 0)   // If ret is even, then the ring buffer should be cleared
      {
         rb_ClearRB();
         return (ret >> 1);
      }
      else
         ret >>= 1;
   }
   else
      ret = skip_count;

   if( ret == 0 )
      return 0;
   media.ctrl.read += ret - 1;
   if( media.ctrl.read >= media.ctrl.rb_size )
      media.ctrl.read -= media.ctrl.rb_size;
   if( media.ctrl.ob_flag_r )
      media.ctrl.odd_byte_r = (uint8)(media.ctrl.rb_base[media.ctrl.read] >> 8);
   if( ++media.ctrl.read == media.ctrl.rb_size )
      media.ctrl.read = 0;
   return ret;
}

/* Get len bytes from ring buffer to buffer */
/* The return value is the actual number of bytes moved */
int rb_GetNByte( uint8 *buffer, int len )
{
   uint8 *dst_ptr;
   const uint8 *src_ptr;
   int len_to_copy, remaining;
   if( len == 0 )
      return 0;
   ASSERT( buffer != NULL );
   len_to_copy = rb_GetByteCount();
   if( len_to_copy == 0 )
      return 0;
   if( len < len_to_copy )
      len_to_copy = len;
   remaining = len_to_copy;
   dst_ptr = buffer;
   if( media.ctrl.ob_flag_r )
   {
      *dst_ptr = media.ctrl.odd_byte_r;
      media.ctrl.ob_flag_r = false;
      if( --remaining == 0 )
         return 1;
      dst_ptr++;
   }
   if( media.ctrl.write < media.ctrl.read )
   {
      len = (media.ctrl.rb_size - media.ctrl.read ) << 1;
      if( len > remaining )
         len = remaining;
      src_ptr = (uint8*)&media.ctrl.rb_base[media.ctrl.read];
      memcpy( dst_ptr, src_ptr, len & 0xFFFFFFFE );
      dst_ptr += len;
      media.ctrl.read += (len >> 1);
      if( media.ctrl.read == media.ctrl.rb_size )
         media.ctrl.read = 0;
      remaining -= len;
      if( len & 0x01 )
      {
         media.ctrl.ob_flag_r = true;
         media.ctrl.odd_byte_r = *(src_ptr+len);
         if( ++media.ctrl.read == media.ctrl.rb_size )
            media.ctrl.read = 0;
         ASSERT( remaining == 0 );
         return len_to_copy;
      }
   }
   if( remaining )
   {
      src_ptr = (uint8*)&media.ctrl.rb_base[media.ctrl.read];
      memcpy( dst_ptr, src_ptr, remaining & 0xFFFFFFFE );
      media.ctrl.read += (remaining >> 1);
      if( remaining & 0x01 )
      {
         if( media.ctrl.read == media.ctrl.write )
         {
            *(dst_ptr+remaining - 1) = media.ctrl.odd_byte_w;
            media.ctrl.ob_flag_w = false;
         }else
         {
            *(dst_ptr+remaining - 1) = *(src_ptr+remaining - 1);
            media.ctrl.ob_flag_r = true;
            media.ctrl.odd_byte_r = *(src_ptr+remaining);
            media.ctrl.read ++;
         }
      }
   }
   return len_to_copy;
}

/* Put bytes from buffer into ring buffer */
/* The return value is the actual number of bytes moved */
int rb_PutNByte( const uint8 *buffer, int len )
{
   uint8 *dst_ptr;
   const uint8 *src_ptr;
   int len_to_copy, remaining;
   if( len == 0 )
      return 0;
   ASSERT( buffer!=NULL );
   len_to_copy = rb_GetFreeSpace();
   if( len_to_copy == 0 )
      return 0;
   if( len_to_copy > len )
      len_to_copy = len;
   remaining = len_to_copy;
   src_ptr = buffer;
   if( media.ctrl.ob_flag_w )
   {
      media.ctrl.rb_base[media.ctrl.write]=media.ctrl.odd_byte_w | (uint16)*src_ptr << 8;
      media.ctrl.ob_flag_w = false;
      if( ++media.ctrl.write == media.ctrl.rb_size )
         media.ctrl.write = 0;
      if( --remaining == 0 )
         return 1;
      src_ptr++;
   }
   if( media.ctrl.write >= media.ctrl.read )
   {
      // step 1: copy from write index to the end of ring buffer
      len = (media.ctrl.rb_size - media.ctrl.write) << 1;
      if( remaining < len )
         len = remaining;
      dst_ptr = (uint8*)&(media.ctrl.rb_base[media.ctrl.write]);
      memcpy( dst_ptr, src_ptr, len & 0xFFFFFFFE );
      src_ptr += len;
      media.ctrl.write += (len >> 1);
      if( media.ctrl.write == media.ctrl.rb_size )
         media.ctrl.write = 0;
      remaining -= len;
      if( len & 0x01 )
      {
         media.ctrl.ob_flag_w = true;
         media.ctrl.odd_byte_w = *(src_ptr - 1);
         ASSERT( remaining == 0 );
         return len_to_copy;
      }
   }
   if( remaining )
   {
      dst_ptr = (uint8*)&(media.ctrl.rb_base[media.ctrl.write]);
      memcpy( dst_ptr, src_ptr, remaining & 0xFFFFFFFE );
      media.ctrl.write += (remaining >> 1);
      if( media.ctrl.write == media.ctrl.rb_size )
         media.ctrl.write = 0;
      if( remaining & 0x01 )
      {
         media.ctrl.ob_flag_w = true;
         media.ctrl.odd_byte_w = buffer[len_to_copy-1];
      }
   }
   return len_to_copy;
}

/* Put a byte into ringer buffer */
bool rb_PutByte( uint8 data_8 )
{
   if( rb_GetFreeSpace() == 0 )
      return false;     // Buffer overflow
   if( media.ctrl.ob_flag_w )
   {
      media.ctrl.ob_flag_w = false;
      media.ctrl.rb_base[media.ctrl.write] = media.ctrl.odd_byte_w | ((uint16)data_8 << 8);
      if( ++media.ctrl.write == media.ctrl.rb_size )
         media.ctrl.write = 0;
   }
   else
   {
      media.ctrl.odd_byte_w = data_8;
      media.ctrl.ob_flag_w = true;
   }
   return true;
}

/* Put a word into ring buffer */
bool rb_PutWord( uint16 data_16 )
{
   if( rb_GetFreeSpace() < 2 )
      return false;     // Buffer overflow
   if( media.ctrl.ob_flag_w )
   {
      media.ctrl.rb_base[media.ctrl.write] = media.ctrl.odd_byte_w | (data_16 << 8);
      media.ctrl.odd_byte_w = (uint8)(data_16 >> 8);
   }
   else
      media.ctrl.rb_base[media.ctrl.write] = data_16;
   if( ++media.ctrl.write == media.ctrl.rb_size )
      media.ctrl.write = 0;
   return true;
}

/* Put a double word into ring buffer */
bool rb_PutDWord( uint32 data_32 )
{
   if( rb_GetFreeSpace() < 4 )
      return false;     // Buffer overflow
   if( media.ctrl.ob_flag_w )
   {
      media.ctrl.rb_base[media.ctrl.write] = media.ctrl.odd_byte_w | ((uint16)data_32 << 8);
      if( ++media.ctrl.write == media.ctrl.rb_size )
         media.ctrl.write = 0;
      media.ctrl.rb_base[media.ctrl.write] = (uint16)(data_32 >> 8);
      media.ctrl.odd_byte_w = (uint8)(data_32 >> 24);
   }
   else
   {
      media.ctrl.rb_base[media.ctrl.write] = (uint16)data_32;
      if( ++media.ctrl.write == media.ctrl.rb_size )
         media.ctrl.write = 0;
      media.ctrl.rb_base[media.ctrl.write] = (uint16)(data_32 >> 16);
   }
   if( ++media.ctrl.write == media.ctrl.rb_size )
      media.ctrl.write = 0;
   return true;
}

/* Return media.ctrl.read */
uint32 rb_GetReadIndex( void )
{
   return media.ctrl.read;
}

/* Return media.ctrl.write */
uint32 rb_GetWriteIndex( void )
{
   return media.ctrl.write;
}

/* Return media.ctrl.rb_size */
uint32 rb_GetSize( void )
{
   return media.ctrl.rb_size << 1;
}

/* Return media.ctrl.odd_byte_r | ((uint16)media.ctrl.odd_byte_w)<<8 */
uint16 rb_GetOddByte( void )
{
   return media.ctrl.odd_byte_r | ((uint16)media.ctrl.odd_byte_w)<<8;
}

uint16 rb_GetOBFlag( void )
{
   uint16 ret=0;
   if( media.ctrl.ob_flag_r )
      ret |= 1;
   if( media.ctrl.ob_flag_w )
      ret |= 2;
   return ret;
}

/* ------------------------------------------------------------------------------ */
/*
static void mediaDataRequest( void )
{
   if( media.waiting || media.ctrl.eof || (media.ctrl.end_status == MEDIA_END) )
      return;
   if( mediaGetFreeSpace() >= media.ctrl.rb_threshold ) {
      mediaSetEvent( MEDIA_DATA_REQUEST );
      media.waiting = true;
   }
}
*/

void mediaDataNotification( void )
{
   if( media.waiting )
      return;
   if( mediaGetDataCount() >= media.ctrl.rb_threshold) {
      mediaSetEvent( MEDIA_DATA_NOTIFICATION );
      media.waiting = true;
      //kal_prompt_trace(MOD_L1SP,"[I2S]rec data notify");
   }
}

#ifndef __L1_STANDALONE__ // avoid link error

extern kal_bool Media_IsRecordTimeUp( void );

void mediaHisr( uint16 flag )
{
   switch( flag ) {
#if 0		
/* under construction !*/
/* under construction !*/
#endif 

   // case DP_D2C_PCM_R:                     
   // case DP_D2C_PCM_TCH_R:
      // TBD
      break;

   // case DP_D2C_SE_DONE:
   case DP_D2C_PCM_REC_INT:				    /* PCM Recording */
      media.recorded_time += 20;
      if(media.recorded_time <= 0)
         return;

// #if defined(__VM_CODEC_SUPPORT__)
      if ( media.ctrl.format == MEDIA_FORMAT_GSM_FR ||
          media.ctrl.format == MEDIA_FORMAT_GSM_HR || media.ctrl.format == MEDIA_FORMAT_GSM_EFR)
      {
         vmRecordHisr();
      }
      else
// #endif
      {
         ASSERT(0);
      }
      mediaDataNotification();
      break;

// #if defined(__VM_CODEC_SUPPORT__)
   // case DP_D2C_SE_SD_DONE:
   case DP_D2C_VM_REC_INT:                 /* Voice Memo Recording */
      media.recorded_time += 20;
      if(media.recorded_time <= 0)
         return;
      if ( media.ctrl.format == MEDIA_FORMAT_GSM_FR ||
          media.ctrl.format == MEDIA_FORMAT_GSM_HR || media.ctrl.format == MEDIA_FORMAT_GSM_EFR)
      {
         vmRecordHisr();
         mediaDataNotification();
      }
      break;
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif // vm playback phase-out
// #endif
   }
}
#endif

kal_bool fPowerOffAudio = KAL_FALSE;

void Media_PowerOff(void)
{
   fPowerOffAudio = KAL_TRUE;
#ifdef ANALOG_AFE_PATH_EXIST	
   AFE_FastCloseSpk();
#endif
}

/* ------------------------------------------------------------------------------ */
/*  Media File Playback/Recording Interface                                       */
/* ------------------------------------------------------------------------------ */
extern void AudioPP_Loudness_Registry( void );

void Media_SetOutputDevice( uint8 device )
{
#ifdef ANALOG_AFE_PATH_EXIST
   AFE_SetOutputDevice( L1SP_VOICE, device );
   AFE_SetOutputDevice( L1SP_AUDIO, device );
#endif //#ifdef ANALOG_AFE_PATH_EXIST	
}

void  Media_SetOutputVolume( uint8 volume1, int8 digital_gain_index )
{
#ifdef ANALOG_AFE_PATH_EXIST
   AFE_SetOutputVolume( L1SP_VOICE, volume1, digital_gain_index );
   AFE_SetOutputVolume( L1SP_AUDIO, volume1, digital_gain_index );
#endif 	
}

void Media_SetBuffer( uint16 *buffer, uint32 buf_len )
{
   media.ctrl.rb_base = buffer;
   media.ctrl.rb_size = buf_len;
   rb_ClearRB();
   media.ctrl.eof     = false;
   media.ctrl.file_len = 0;

   Media_SetRBOffset(0);
}

void Media_GetWriteBuffer( uint16 **buffer, uint32 *buf_len )
{
   int32 count;

   if( media.ctrl.read > media.ctrl.write )
      count = (int32)media.ctrl.read - (int32)media.ctrl.write - 1;
   else if( media.ctrl.read == 0 )
      count = (int32)media.ctrl.rb_size - (int32)media.ctrl.write - 1;
   else
      count = (int32)media.ctrl.rb_size - (int32)media.ctrl.write;

   *buffer = &media.ctrl.rb_base[media.ctrl.write];
   *buf_len = (uint32)count;
}

void Media_WriteDataDone( uint32 len )
{
   media.ctrl.write += len;
   if( media.ctrl.write >= media.ctrl.rb_size )
      media.ctrl.write = 0;
   media.waiting = false;
}

void Media_WriteDataDone_NoWaiting( uint32 len )
{
   media.ctrl.write += len;
   if( media.ctrl.write >= media.ctrl.rb_size )
      media.ctrl.write = 0;
}

void Media_DataFinished( void )
{
   media.ctrl.eof = true;
}

void Media_GetReadBuffer( uint16 **buffer, uint32 *buf_len )
{
   int32 count;

   if( media.ctrl.write >= media.ctrl.read )
      count = (int32)media.ctrl.write - (int32)media.ctrl.read;
   else
      count = (int32)media.ctrl.rb_size - (int32)media.ctrl.read;

   *buffer = &media.ctrl.rb_base[media.ctrl.read];
   *buf_len = (uint32)count;
}

void Media_ReadDataDone( uint32 len )
{
   media.ctrl.read += len;
   media.ctrl.file_len += len;
   if( media.ctrl.read >= media.ctrl.rb_size )
      media.ctrl.read = 0;
   media.waiting = false;
}

int32 mediaGetFreeSpace( void )
{
   int32 count;

   count = (int32)media.ctrl.read - (int32)media.ctrl.write - 1;
   if( count < 0 )
      count += (int32)media.ctrl.rb_size;
   return count;
}

int32 mediaGetDataCount( void )
{
   int32 count;

   count = (int32)media.ctrl.write - (int32)media.ctrl.read;
   if( count < 0 )
      count += media.ctrl.rb_size;
   return count;
}

void mediaIncRecordTime( void )
{
   media.recorded_time += 20;
}

kal_int32 Media_GetDataCount( void )
{
   return mediaGetDataCount();
}

bool mediaIsDataConsumed( void )
{
   return media.ctrl.isDataConsumed;
}

mediaControl *mediaGetControl( void )
{
   return &media.ctrl;
}

/* get .wav file header, return starting address pointer & header-length in byte*/
void Media_GetFileHeader( uint8 **header, uint32 *len )
{
   ASSERT(0);
}
/* ------------------------------------------------------------------------------ */

#ifdef PCM_EX_UNIT_TEST
#include "pcm4way.h"
static uint32 pcm_ex_test_on = 0;
static uint16 PCM_BUF[160];
static uint16 PCM_UL_BUF[8][160];
static uint16 PCM_DL_BUF[8][160];
static uint32 pcm_buf_rw;

void pcm4way_hisrHdl()
{
   uint32 I;
   int16 *buf1, *buf2;

   buf1 = (int16*)PCM_UL_BUF[pcm_buf_rw];
   buf2 = (int16*)PCM_BUF;
   for(I = 160; I > 0 ; I--)
      *buf2++ = (*buf1++) >> 2;
   PCM4WAY_GetFromMic((uint16*)PCM_UL_BUF[pcm_buf_rw]);
   buf1 = (int16*)PCM_UL_BUF[pcm_buf_rw];
   buf2 = (int16*)PCM_BUF;
   for(I = 160; I > 0 ; I--)
      (*buf2++) += (*buf1++) >> 2 * 3;
   PCM4WAY_PutToSE((const uint16*)PCM_BUF);

   buf1 = (int16*)PCM_DL_BUF[pcm_buf_rw];
   buf2 = (int16*)PCM_BUF;
   for(I = 160; I > 0 ; I--)
      *buf2++ = (*buf1++) >> 2;
   PCM4WAY_GetFromSD((uint16*)PCM_DL_BUF[pcm_buf_rw]);
   buf1 = (int16*)PCM_DL_BUF[pcm_buf_rw];
   buf2 = (int16*)PCM_BUF;
   for(I = 160; I > 0 ; I--)
      (*buf2++) += (*buf1++) >> 2 * 3;
   PCM4WAY_PutToSpk((const uint16*)PCM_BUF);

   pcm_buf_rw ++;
   pcm_buf_rw &= 0x7;
}

void pcm2way_hisrHdl()
{
   uint32 I;
   int16 *buf1, *buf2;

   buf1 = (int16*)PCM_UL_BUF[pcm_buf_rw];
   buf2 = (int16*)PCM_BUF;
   for(I = 160; I > 0 ; I--)
      *buf2++ = (*buf1++) >> 2;
   PCM2WAY_GetFromMic((uint16*)PCM_UL_BUF[pcm_buf_rw]);
   buf1 = (int16*)PCM_UL_BUF[pcm_buf_rw];
   buf2 = (int16*)PCM_BUF;
   for(I = 160; I > 0 ; I--)
      (*buf2++) += (*buf1++) >> 2 * 3;
   PCM2WAY_PutToSpk((const uint16*)PCM_BUF);

   pcm_buf_rw ++;
   pcm_buf_rw &= 0x7;
}

#endif

kal_bool Media_IsRecordSilence( void )
{
   if(media.presilence > RECORD_PRESILENCE_NUM)
   {
      return KAL_FALSE;
   }
   media.presilence++;
   return KAL_TRUE;
}

kal_bool Media_IsRecordTimeUp( void )
{
   if((media.uStopTime && media.recorded_time > media.uStopTime) || media.fTimeUp)
   {
      if(media.fTimeUp==KAL_FALSE)
      {
         mediaSetEvent( MEDIA_STOP_TIME_UP );
         media.fTimeUp = KAL_TRUE;
         media.waiting = KAL_TRUE;
      }
      return KAL_TRUE;
   }
   return KAL_FALSE;
}

void Media_SetRecordedStopTime( kal_uint32 uStopTime )
{
   media.uStopTime = uStopTime;
}

kal_uint32 Media_GetRecordedTime( void )
{
   if(media.recorded_time <= 0)
      return 0;
   return media.recorded_time;
}

kal_uint32 Media_IncRecordedTime( kal_uint32 val )
{
   media.recorded_time += val;
   
   return media.recorded_time;
}

void Media_SetRecordedTime( kal_uint32 val )
{
   media.recorded_time = val;
}

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
#ifndef __L1_STANDALONE__ // avoid link error
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
#if defined(__DUAL_MIC_SUPPORT__)
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined(__ENABLE_AUDIO_DVT__)
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
#else
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#endif

#if 0
#ifndef __L1_STANDALONE__ // avoid link error
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
#if VERIFY_DATA_TO_DSP
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
#ifndef __L1_STANDALONE__ // avoid link error
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
#if VERIFY_DATA_TO_DSP
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
#endif
/* under construction !*/
#ifndef __L1_STANDALONE__ // avoid link error
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
#if VERIFY_DATA_TO_DSP
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#endif //#if 0

Media_Status Media_Control( Media_Ctrl ctrl_no, int32 ctrl_val )
{
   return MEDIA_BAD_COMMAND;
}


void Media_SetMelodyFilter( uint16 len, const int16 *filter )
{

}

void Media_MuteSpeaker( bool mute )
{
   AFE_MuteSpeaker( L1SP_AUDIO, mute );
   AFE_MuteSpeaker( L1SP_VOICE, mute );
}

/* ------------------------------------------------------------------------------ */
void mediaHandler( void *data )     /* This function works in L1Audio Task */
{
   Media_Event event = (Media_Event)(int32)data;

   if( event == MEDIA_TERMINATED || !L1Audio_CheckFlag( media.aud_id ))      /* MEDIA_TERMINATED is no longer used */
      return;
   if( event == MEDIA_END || event == MEDIA_ERROR ) {
      L1Audio_ClearFlag( media.aud_id );
      media.waiting = false;
   }
   media.media_handler( event );
}
/* ------------------------------------------------------------------------------ */
void mediaInit( uint16 aud_id )
{
   media.aud_id = aud_id;
   L1Audio_SetEventHandler( media.aud_id, mediaHandler );

   media.ctrl.rb_threshold = MEDIA_RB_DEFAULT_THRESHOLD;
   media.ctrl.max_swing = (int32)Media_Playback_Maximum_Swing >> 3;
   media.ctrl.key_shift = 0;
   media.ctrl.level = 100;
   media.ctrl.rb_base = (uint16*)0;
   media.uStopTime = 0;
   media.fTimeUp = KAL_FALSE;
}

/* If the event is MEDIA_END or MEDIA_ERROR, make sure DSP has been stopped
   before calling this function. Refer to the function: mediaHandler */
void mediaSetEvent( Media_Event event )
{
   L1Audio_SetEvent( media.aud_id, (void *)event );
}

bool mediaKeytoneForbidden( void )
{
   return false;
}

void Media_SetRBThreshold( uint16 threshold )
{
   media.ctrl.rb_threshold = threshold;
}

void Media_SetRBOffset( kal_uint32 uOffset )
{
   ASSERT( uOffset < media.ctrl.rb_size);

   media.ctrl.uOffset = uOffset;
}

#ifndef __L1_STANDALONE__ // avoid link error

//interface for audiohdl
void rbGetWriteBuffer( AUD_RB_INFO *rb, kal_uint8 **buffer, kal_uint32 *buf_len )// in bytes
{
   int32 count;

   if( rb->read > rb->write )
      count = rb->read - rb->write - 1;
   else if( rb->read == 0 )
      count = rb->rb_size - rb->write - 1;
   else
      count = rb->rb_size - rb->write;

   ASSERT( count>=0 );
   *buffer = (uint8 *)&rb->rb_base[rb->write];
   *buf_len = count;
}

void rbGetReadBuffer( AUD_RB_INFO *rb, kal_uint8 **buffer, kal_uint32 *buf_len )// in bytes
{
   int32 count;

   if( rb->write >= rb->read )
      count = rb->write - rb->read;
   else
      count = rb->rb_size - rb->read;

   ASSERT( count>=0 );
   *buffer = (uint8 *)&rb->rb_base[rb->read];
   *buf_len = count;
}

void rbReadDataDone( AUD_RB_INFO *rb, kal_uint32 len ) // in bytes
{
   rb->read += len;

   ASSERT(rb->read <= rb->rb_size);
   if( rb->read == rb->rb_size )
      rb->read = 0;

   kal_brief_trace( TRACE_GROUP_AUD_PROCESS, L1AUDIO_READ_BYTE, len );
}


void rbWriteDataDone( AUD_RB_INFO *rb, kal_uint32 len ) // in bytes
{
   rb->write += len;

   ASSERT(rb->write <= rb->rb_size);
   if( rb->write == rb->rb_size )
      rb->write = 0;
}

int32 rbGetFreeSpace( AUD_RB_INFO *rb )
{
   int32 count;

   count = rb->read - rb->write - 1;
   if( count < 0 )
      count += rb->rb_size;
   return count; // free size in byte
}

int32 rbGetDataCount( AUD_RB_INFO *rb )
{
   return rb->rb_size - rbGetFreeSpace(rb) - 1;
}
//interface for audiohdl end

static void mhdlSetBuffer( MHdl *hdl, kal_uint8 *buffer, kal_uint32 buf_len )
{
   kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_SET_BUFFER, buffer, buf_len, hdl->isAllocRingBuffer,hdl,0,0);
   if(hdl->isAllocRingBuffer == KAL_TRUE)
   {
      hdl->FreeBufferInternal(hdl);
   }
   hdl->rbInfo.rb_base = buffer;
   hdl->rbInfo.rb_size = buf_len;
   hdl->rbInfo.write = 0;
   hdl->rbInfo.read = 0;
   hdl->eof = false;
   hdl->waiting = false;
}

static void mhdlGetWriteBuffer( MHdl *hdl, kal_uint8 **buffer, kal_uint32 *buf_len )// in bytes
{
   rbGetWriteBuffer(&hdl->rbInfo, buffer, buf_len);
}

static void mhdlGetReadBuffer( MHdl *hdl, kal_uint8 **buffer, kal_uint32 *buf_len )// in bytes
{
   rbGetReadBuffer(&hdl->rbInfo, buffer, buf_len);
}

static Media_Status mhdlSetLevel( MHdl *hdl, kal_uint8 level )
{
   ASSERT( level <= 100 );
   hdl->volume_level = level;
#ifdef ANALOG_AFE_PATH_EXIST	
   AFE_SetDigitalGain( L1SP_AUDIO, level );
   AFE_SetDigitalGain( L1SP_VOICE, level );
#else
#endif
   return MEDIA_SUCCESS;
}

static void mhdlWriteDataDone( MHdl *hdl, kal_uint32 len ) // in bytes
{
   kal_brief_trace (TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_WRITE_DATA_DONE, hdl, len,0,0,0,0);
   rbWriteDataDone(&hdl->rbInfo, len);
   hdl->isUnderflow = KAL_FALSE;
}

static void mhdlReadDataDone( MHdl *hdl, kal_uint32 len ) // in bytes
{
   rbReadDataDone(&hdl->rbInfo, len);
}

static void mhdlDataFinished( MHdl *hdl )
{
   kal_brief_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_DATA_FINISH, hdl, hdl->mediaType,0,0,0,0);
   hdl->eof = true;
}

static void mhdlFinishWriteData( MHdl *hdl )
{
   hdl->waiting = KAL_FALSE;
   hdl->isUnderflow = KAL_FALSE;
   hdl->bReadingData = KAL_FALSE;
}

static void mhdlResetMediaBuf( MHdl *hdl )
{
   hdl->rbInfo.write = 0;
   hdl->rbInfo.read = 0;
   hdl->eof = KAL_FALSE;
   hdl->waiting = KAL_FALSE;
   hdl->isUnderflow = KAL_FALSE;

}
static kal_uint8 mhdlGetLevel( MHdl *hdl )
{
   return hdl->volume_level;
}

static Media_Status mhdlSetStartTime( MHdl *hdl, kal_uint32 msStartTime )
{
   hdl->start_time = msStartTime;
   hdl->uSeekProgress = 0;
   hdl->uCurSeekFrm = 0;
   kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_SET_START_TIME, hdl->mediaType, msStartTime,0,0,0,0);
   return MEDIA_SUCCESS;
}

static Media_Status mhdlSetStopTime( MHdl *hdl, kal_uint32 msStopTime )
{
   hdl->stop_time = msStopTime;
   kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_SET_STOP_TIME, hdl->mediaType, msStopTime,0,0,0,0);
   return MEDIA_SUCCESS;
}

static void mhdlSetStoreFlag( MHdl *hdl, kal_bool fStoreLastFileOffset )
{
   hdl->fStoreFileOffset = fStoreLastFileOffset;
}

static void mhdlStoreFileOffset(MHdl *hdl)
{
   audResumeInfo.uResumeFrameOffset = audResumeInfo.uCurOffset;
}

static kal_uint32 mhdlGetFileOffset(MHdl *hdl)
{
   return 0;
}

static void mhdlSetFileOffset( MHdl *hdl, kal_uint32 uCurOffset)
{
   audResumeInfo.uResumeFrameOffset = uCurOffset;
}

static kal_uint32 mhdlGetCurrentTime( MHdl *hdl )
{
   kal_uint32 uTSTime = 0;
   hdl->fStoreFileOffset = false;

   kal_brief_trace ( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_GET_CURRENT_TIME, hdl->mediaType, hdl->current_time, hdl->start_time, uTSTime,0,0,0);

   if(uTSTime)
   {
      hdl->current_time = hdl->start_time+uTSTime;
   }

   if (hdl->current_time < hdl->start_time)
      return hdl->start_time;
   else
      return hdl->current_time;
}

static kal_uint32 mhdlGetTotalDuration( MHdl *hdl )
{
   kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_GET_TOTAL_DUR_NONAST, hdl, hdl->mediaType, hdl->uTotalDuration,0,0,0);
   return hdl->uTotalDuration;
}

static int32 mhdlGetFreeSpace( MHdl *hdl )
{
   return rbGetFreeSpace(&hdl->rbInfo);
}

static int32 mhdlGetDataCount( MHdl *hdl )
{
   return hdl->rbInfo.rb_size - mhdlGetFreeSpace(hdl) - 1;
}

void mhdlCallbackTask( void *data )
{
   MHdl *hdl = (MHdl *)data;
   Media_Event uEvent = (Media_Event)hdl->data;
   hdl->handler( hdl, uEvent );
}

void mhdlException( MHdl *hdl, Media_Event event )
{
   kal_brief_trace (TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_MHDL_EXCEPTION, hdl->mediaType, event,0,0,0,0);

   hdl->data = (uint32)event;
   L1Audio_SetEvent( hdl->aud_id, hdl );
}

void mhdlAllowSleep( MHdl *hdl )
{
   if(L1Audio_CheckFlag( hdl->aud_id ))                 //Dior add
      L1Audio_ClearFlag( hdl->aud_id );
   ktUnlock();
}

void mhdlDisallowSleep( MHdl *hdl )
{
   if(!L1Audio_CheckFlag( hdl->aud_id ))                 //Dior add
      L1Audio_SetFlag( hdl->aud_id ); // disable sleep mode
   ktLock();
}

static void mhdlDataRequestInternal( MHdl *hdl, Media_Event end_status, Media_Event event)
{
   kal_uint32 data_count;
   kal_uint32 free_space;

   kal_brief_trace ( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_DATA_REQUEST, hdl->waiting, hdl->eof, hdl->DataRequestThreshold, hdl->GetFreeSpace(hdl),0,0,0,0);

   if (hdl->waiting)
   {
      return;
   }

   if (end_status != MEDIA_UPDATE_DUR)
   {
      if ( hdl->eof || (end_status == MEDIA_END) )
         return;
   }

   data_count = hdl->GetDataCount(hdl);
   free_space = hdl->GetFreeSpace(hdl);

   if(  (hdl->DataRequestMode==MEDIA_FREE_SPACE_MODE && (free_space > hdl->DataRequestThreshold))
      ||(data_count<MEDIA_MIN_DATA_THRESHOLD))
   {
      mhdlException( hdl, event );
      hdl->waiting = true;
   }
   else if(hdl->DataRequestMode==MEDIA_DATA_COMSUME_MODE)
   {
      if(hdl->rbInfo.read > hdl->LastRingBufferRead)
      {
         if(hdl->rbInfo.read - hdl->LastRingBufferRead > hdl->DataRequestThreshold)
         {
            mhdlException( hdl, event );
            hdl->waiting = true;
            hdl->LastRingBufferRead = hdl->rbInfo.read;
         }
      }
      else
      {
         if(hdl->rbInfo.read + hdl->rbInfo.rb_size - hdl->LastRingBufferRead > hdl->DataRequestThreshold)
         {
            mhdlException( hdl, event );
            hdl->waiting = true;
            hdl->LastRingBufferRead = hdl->rbInfo.read;
         }
      }
   }
}

void mhdlDataRequest( MHdl *hdl, Media_Event end_status)
{
   mhdlDataRequestInternal(hdl, end_status, MEDIA_DATA_REQUEST);
}

void mhdlDataRequestNone( MHdl *hdl, Media_Event end_status)
{
   mhdlDataRequestInternal(hdl, end_status, MEDIA_NONE);
}

void mhdlDataNotification( MHdl *hdl )
{
   if( hdl->waiting )
      return;

   if( hdl->GetDataCount(hdl) >= (MEDIA_RB_DEFAULT_THRESHOLD << 2) ) {
      mhdlException( hdl, MEDIA_DATA_NOTIFICATION );
      hdl->waiting = true;
   }
}

static void mhdlSetUserData( MHdl *hdl, void* pAppData)
{
   hdl->pApplicateData = pAppData;
}

static void mhdlGetUserData( MHdl *hdl, void** pAppData)
{
   *pAppData = hdl->pApplicateData;
}

static Media_Status mhdlReachValidRegion( MHdl *hdl )
{
   return MEDIA_SUCCESS;
}

static void mhdlBuildCache( MHdl *hdl, Media_Status *eLastRet, kal_uint32 *uProgress )
{
   *eLastRet = MEDIA_SUCCESS;
   *uProgress=100;
}

static void mhdlSetCacheTbl( MHdl *hdl, kal_uint8 *ptr, kal_uint32 usize )
{
}

static kal_uint32 mhdlGetCacheDur(MHdl *hdl)
{
   return hdl->uTotalDuration;
}

static void mhdlSetDataRequestThreshold(MHdl *hdl, Media_Buffer_Mode mode, kal_uint32 threshold, void* param)
{
   hdl->DataRequestThreshold = threshold;
   hdl->DataRequestMode = mode;
}

static void mhdlSetBufferInternal(MHdl *hdl , kal_uint32 uSize)
{
   kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_SET_BUFFER_INTERNAL, hdl, hdl->rbInfo.rb_base, hdl->isAllocRingBuffer,uSize,0,0);
   if(hdl->rbInfo.rb_base == NULL)
   {
      hdl->rbInfo.rb_base = (kal_uint8 *)audio_alloc_mem_cacheable( uSize * sizeof(kal_uint8) );
      ASSERT(hdl->rbInfo.rb_base);
      hdl->rbInfo.rb_size = uSize;
      hdl->isAllocRingBuffer = KAL_TRUE;
      mhdlResetMediaBuf(hdl);
   }
}

static void mhdlFreeBufferInternal(MHdl *hdl)
{
   kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_FREE_BUFFER_INTERNAL, hdl, hdl->rbInfo.rb_base, hdl->isAllocRingBuffer,0,0,0);
   if(hdl->isAllocRingBuffer)
   {
      ASSERT(hdl->rbInfo.rb_base);
      audio_free_mem( (void **) &hdl->rbInfo.rb_base );
      hdl->rbInfo.rb_base = NULL;
      hdl->rbInfo.rb_size = 0;
      hdl->isAllocRingBuffer = KAL_FALSE;
   }
}

void mhdlInitEx( MHdl *hdl, uint32 hisrMagic, void hisrHdlr( void *data ) )
{
   ASSERT(hdl);

   memset(hdl, 0, sizeof(MHdl));
   hdl->stop_time = 0xFFFFFFFF;

   hdl->SetBufferInternal = mhdlSetBufferInternal;
   hdl->FreeBufferInternal = mhdlFreeBufferInternal;
   hdl->SetBuffer = mhdlSetBuffer;
   hdl->GetWriteBuffer = mhdlGetWriteBuffer;
   hdl->GetReadBuffer = mhdlGetReadBuffer;
   hdl->WriteDataDone = mhdlWriteDataDone;
   hdl->FinishWriteData = mhdlFinishWriteData;
   hdl->ResetMediaBuf = mhdlResetMediaBuf;
   hdl->ReadDataDone = mhdlReadDataDone;
   hdl->DataFinished = mhdlDataFinished;
   hdl->GetFreeSpace = mhdlGetFreeSpace;
   hdl->GetDataCount = mhdlGetDataCount;
   hdl->SetLevel = mhdlSetLevel;
   hdl->GetLevel = mhdlGetLevel;
   hdl->SetStartTime = mhdlSetStartTime;
   hdl->SetStopTime = mhdlSetStopTime;
   hdl->GetCurrentTime = mhdlGetCurrentTime;
   hdl->GetTotalDuration = mhdlGetTotalDuration;
   hdl->SetStoreFlag = mhdlSetStoreFlag;
   hdl->StoreFileOffset = mhdlStoreFileOffset;
   hdl->GetFileOffset = mhdlGetFileOffset;
   hdl->SetFileOffset = mhdlSetFileOffset;
   hdl->ReachValidRegion = mhdlReachValidRegion;
   hdl->SetUserData = mhdlSetUserData;
   hdl->GetUserData = mhdlGetUserData;
   hdl->BuildCache  = mhdlBuildCache;
   hdl->SetCacheTbl = mhdlSetCacheTbl;
   hdl->GetCacheDuration = mhdlGetCacheDur;
   hdl->SetDataRequestThreshold = mhdlSetDataRequestThreshold;
   hdl->DataRequestThreshold = MEDIA_RB_DEFAULT_THRESHOLD << 2;
   hdl->DataRequestMode = MEDIA_FREE_SPACE_MODE;
}

void mhdlInit( MHdl *hdl, uint32 hisrMagic, void hisrHdlr( void *data ) )
{
   mhdlInitEx( hdl, hisrMagic, hisrHdlr );

   if(0xFFFF != hisrMagic){
      mhdlSetLevel( hdl, 100 );
      hdl->aud_id = L1Audio_GetAudioID();
      L1Audio_SetEventHandler( hdl->aud_id, mhdlCallbackTask );
   }
}

void mhdlFinalize( MHdl *hdl, uint32 hisrMagic )
{
   if(0xFFFF != hisrMagic)
   {
      mhdlSetLevel( hdl, 100 );
      L1Audio_FreeAudioID( hdl->aud_id );
   }
}

void mhdlHookInit( MHdl *hdl, uint32 hisrMagic, void hisrHdlr( void *data ) )
{
   if(0xFFFF != hisrMagic){
      L1Audio_HookHisrHandler( hisrMagic, hisrHdlr, (void*)hdl );
   }
}

void mhdlHookFinalize( uint32 hisrMagic )
{
   if(0xFFFF != hisrMagic){
      L1Audio_UnhookHisrHandler( hisrMagic );
   }
}

void autMoveDataForAlign( MHdl *hdl ) //for aacmfplaystrm / dafmfplaystrm
{
   int32 dataCount, I;
   uint8 *dest, *src;

   if ( 0 == (hdl->rbInfo.read & 0x1) )
      return;

   dataCount = hdl->GetDataCount( hdl );
   if (hdl->rbInfo.read <= hdl->rbInfo.write) {
      dest = hdl->rbInfo.rb_base;
      src = hdl->rbInfo.rb_base + hdl->rbInfo.read;
      for (I = dataCount-1; I>=0; I--) {
         *dest++ = *src++;
      }

      // Update read pointer
      hdl->rbInfo.read = 0;
   } else {
      int32 segment = hdl->rbInfo.rb_size - hdl->rbInfo.read;

      // First segment
      dest = hdl->rbInfo.rb_base + hdl->rbInfo.read - 1;
      src = hdl->rbInfo.rb_base + hdl->rbInfo.read;
      for (I = segment-1; I>=0; I--) {
         *dest++ = *src++;
      }

      // The last byte of ring buffer
      *dest = hdl->rbInfo.rb_base[0];

      // Seconf segment
      dest = hdl->rbInfo.rb_base;
      src = hdl->rbInfo.rb_base + 1;
      for (I = hdl->rbInfo.write-2; I>=0; I--) {
         *dest++ = *src++;
      }

      // Update read pointer
      hdl->rbInfo.read -= 1;
   }

   // Update write pointer
   hdl->rbInfo.write = hdl->rbInfo.read + dataCount;
   if (hdl->rbInfo.write >= hdl->rbInfo.rb_size)
      hdl->rbInfo.write -= hdl->rbInfo.rb_size;
}
#endif // #ifndef __L1_STANDALONE__
/* ------------------------------------------------------------------------------ */

void autTchReadFromDSP( int16 *buf, kal_uint32 pageNum )
{
   ASSERT(0); //FIXME: Need to rewrite the recording function under speech
}

void Media_EnableHardwareMuteSleep(kal_bool enable)
{
#if HW_MUTE_SUPPORT_PLATFORM
   AFE_EnableHardwareMuteSleep(enable);
#endif
}

//-------------------------------------------

//FIXME:
/**
  @return: mapping to "Media_Speech_Feature" to indicate the feature existing.
*/
kal_uint32 Media_GetSpeechFeatureCapability(void)

{
  uint32 features = MEDIA_SPEECH_FEATURE_NONE;

#if defined(__AMRWB_LINK_SUPPORT__) //Speech phone call is WB
  features |= MEDIA_SPEECH_FEATURE_WB_LINK_SUPPORT;
#endif

  return features;
}

kal_int32 autGetBytes(MHdl *hdl, STFSAL *pstFSAL, kal_uint32 uLen, kal_uint8 *pbBuf)
{
   ASSERT(0);
   
   return 0;
}

