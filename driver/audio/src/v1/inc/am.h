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

/*******************************************************************************
 *
 * Filename:
 * ---------
 *	afe.c
 *
 * Project:
 * --------
 *   MT6208
 *
 * Description:
 * ------------
 *   Audio Manager
 *
 * Author:
 * -------
 * -------
 *
 *------------------------------------------------------------------------------
 * $Revision:   1.32  $
 * $Modtime:   Aug 01 2005 17:46:08  $
 * $Log:   //mtkvs01/vmdata/Maui_sw/archives/mcu/l1audio/am.h-arc  $
 *
 * 03 03 2015 miyavi.tsai
 * [MOLY00097589] [Rainier] patch merge form 6580_dev to WR8.1449MP
 * .
 *
 * 10 30 2014 thomas.chen
 * [MOLY00082662] PatchBack[[MOLY00012413][MOLY00020343][MOLY00020692][MOLY00020824][MOLY00064113][MOLY00038820][MOLY00040462][MOLY00043994][MOLY00055901][MOLY00072518][MOLY00070800][MOLY00050441][MOLY00050441]
 * .
 *
 * 09 26 2014 thomas.chen
 * [MOLY00068785] RF_INFO_NOTIFY & MSG_M2A_NETWORK_STATUS_NOTIFY
 * .
 *
 * 05 14 2013 sheila.chen
 * [MOLY00022118] [Volunteer Patch] DRC2.0 (MagiLoudness) Integration
 * DRC 2.0 modification
 *
 * 05 03 2013 sheila.chen
 * [MOLY00008234] [MT6572/MT6582] Integration
 * 3-in-1 speaker interface
 *
 * 01 08 2013 sheila.chen
 * [MOLY00008474] [MT6589] Fix 8k control bug when device switch
 * set mode bug fix
 *
 * 12 18 2012 sheila.chen
 * [MOLY00000112] [MT6583] Pre-integration
 * Set Mode modification
 *
 * 12 04 2012 sheila.chen
 * [MOLY00000112] [MT6583] Pre-integration
 * 1. depop when speech off
 * 2. remove vm playback function
 *
 * 11 21 2012 sheila.chen
 * [MOLY00000112] [MT6583] Pre-integration
 * Warming removal 3
 * 
 * CTM potential bug fix
 *
 * 11 15 2012 sheila.chen
 * [MOLY00000112] [MT6583] Pre-integration
 * Warning removal
 *
 * 11 06 2012 sheila.chen
 * [MOLY00000112] [MT6583] Pre-integration
 * 1. Remove AM SRC setting
 * 2. Enalbe SAL dual mic 
 *
 * 10 29 2012 jy.huang
 * [MOLY00000755] Check in 3G speech delay improvement(phase1+3)
 * .
 * 
 * 10 25 2012 sheila.chen
 * [MOLY00000112] [MT6583] Pre-integration
 * 1. Gain
 * 
 * 2. Acoustic loopback
 * 
 * 3. p2w interface
 * 
 * 09 25 2012 sheila.chen
 * [MOLY00002890] Remove Phase out function
 * Integration change.
 *  add Phone call usage code
 * 
 * 09 25 2012 thomas.chen
 * [MOLY00004111] Integrate the PNW and DACA interface with SAL
 * 09 20 2012 sheila.chen
 * [MOLY00000112] [MT6583] Pre-integration
 * add compile option for analog AFE
 * 
 * 09 11 2012 sheila.chen
 * [MOLY00000112] [MT6583] Pre-integration
 * Phase in call pcm record and epl record in the same time
 * 
 * 07 27 2012 sheila.chen
 * [MOLY00000112] [MT6583] Pre-integration
 * Fix build warning.
 * 
 * 07 25 2012 sheila.chen
 * [MOLY00000112] [MT6583] Pre-integration
 * Phase in PCMNWAY, param AM manager with 2 parameter, and recording.
 *
 * 07 16 2012 sheila.chen
 * [MOLY00000112] [MT6583] Pre-integration
 * Phase in 75+80. Integration change.
 *
 * 07 16 2012 kh.hung
 * [MOLY00000706] Remove compile warning
 * .
 *
 * 07 13 2012 jy.huang
 * [MOLY00000755] Check in 3G speech delay improvement(phase1+3)
 * .
 *
 * 06 08 2012 kh.hung
 * removed!
 * .
 *
 * 05 14 2012 jy.huang
 * removed!
 * .
 *
 * 05 11 2012 kh.hung
 * removed!
 * .
 *
 * 03 30 2012 thomas.chen
 * removed!
 * .
 *
 * 03 15 2012 thomas.chen
 * removed!
 * .
 *
 * 12 13 2011 thomas.chen
 * removed!
 * .
 *
 * 11 29 2011 lanus.chao
 * removed!
 * .
 *
 * 10 31 2011 dior.lin
 * removed!
 * Update I2S buffer size.
 *
 *******************************************************************************/
#ifndef AM_H
#define AM_H

#include "common_def.h"
#include "sal_def.h"

#define  ASP_TYPE_VOICE       0

#define  ASP_FS_8K            0x00
#define  ASP_FS_11K           0x11
#define  ASP_FS_12K           0x12
#define  ASP_FS_16K           0x20
#define  ASP_FS_22K           0x21
#define  ASP_FS_24K           0x22
#define  ASP_FS_32K           0x40
#define  ASP_FS_44K           0x41
#define  ASP_FS_48K           0x42

typedef enum{
   AM_RECORD_NONE = 0, 
   AM_RECORD_8K,
   AM_RECORD_16K
}AM_RECORD_FORMAT; 

void     AM_Init( void );
void     AM_SetDSP2GReset(bool v);
bool     AM_AudioManager( bool handover,uint16 speech_mode, int8 sub_channel );
void     AM_AudioManager_OS_Tick( void );
void     AM_FlushQFunction( void );
void     AM_FillSilencePattern( volatile uint16 *addr, uint16 info, uint16 speech_mode );
void     AM_FillSilencePatternInBuffer( uint16 *buffer, uint16 speech_mode );
uint16   AM_GetSpeechPatternLength( uint8 speech_mode );
bool     AM_CodecMode_IsLegal(uint8 codec_mode);
void     AM_SpeechOn(uint32 rat_mode, uint32 extraInfo);
void     AM_SpeechOff( uint32 info );
bool     AM_IsSpeechOn( void );
void     AM_SetDAIMode ( uint8 mode );
bool     AM_IsDAIMode( void );
void     AM_WriteFirCoeffs( const int16 *in_coeff, const int16 *out_coeff );
void AM_WriteWbFirCoeffs( const int16 wb_in_coeff[90], const int16 wb_out_coeff[90] );
void     AM_VMRecordOn( uint16 speech_mode );
void     AM_VMRecordOff( void );
#if 0 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
void     AM_KeyToneOn( void );
void     AM_KeyToneOff( void );
void     AM_ToneOn( void );
void     AM_ToneOff( void );
void     AM_PCM8K_PlaybackOn( void );
void     AM_PCM8K_PlaybackOff( bool wait );
void     AM_PCM16K_PlaybackOn( void );       /* PCM16K is for MT6205B only */
void     AM_PCM16K_PlaybackOff( bool wait );

uint32   AM_GetRecordFormat(void);
typedef enum{
   AM_PCM8KREC_APP_TYPE_PCMREC = 0,
   AM_PCM8KREC_APP_TYPE_VMEPL,
}AM_PCM8KREC_APP_TYPE; 

void     AM_PCM8K_RecordOn( AM_PCM8KREC_APP_TYPE appType );
void     AM_PCM8K_RecordOff( bool wait, AM_PCM8KREC_APP_TYPE appType );
void     AM_PCM16K_RecordOn( void );         /*PCM16K recording support 6219 and latter version*/
void     AM_PCM16K_RecordOff( bool wait );
bool     AM_IsVMPlaybackOn( void );
void     AM_VRRecordOn( uint32 trainPhase );
void     AM_VRRecordOff( uint32 trainPhase );
bool     AM_IsULSpeechMuted( void );
void     AM_Mute_UL_EnhResult_Speech(bool mute);
void     AM_Mute_UL_Source_Speech(bool mute);
void     AM_Mute_UL_Codec_Speech( bool mute );
void     AM_Mute_DL_8K_Speech( bool mute );
void     AM_Mute_DL_Speech_Traffic( bool mute );

// PCMNWAY function inside AM 
typedef enum {
	AM_PCMEX_TYPE_DEDICATION = 0, // under call
	AM_PCMEX_TYPE_IDLE_WO_ENH, // without call, voice path, no enhancement
	AM_PCMEX_TYPE_IDLE, // without call, speech quality like, with enhancement
	AM_PCMEX_TYPE_REC_ONLY_CAL,  // record only DMNR calibration
	AM_PCMEX_TYPE_REC_PLAY_CAL,  // rec&play DMNR calibration
	AM_PCMEX_TYPE_DACA_DEDICATION,  // data card under call (speech on)
	AM_PCMEX_TYPE_DACA_IDLE_WO_ENH, // data card without call, voice path, no enhancement 
	AM_PCMEX_TYPE_DACA_IDLE, // data card without call, speech quality like, with enhancement

	AM_PCMEX_TYPE_UNDEF = 0xffff,
} AM_PCMEX_TYPE;

void     AM_PCM_EX_On( AM_PCMEX_TYPE type, uint32 cfg_ptr);
void     AM_PCM_EX_Off( AM_PCMEX_TYPE type, uint32 cfg_ptr);
bool     AM_IsVoIPOn( void );
bool     AM_IsConflictState( void );
bool     AM_IsKeyToneOn( void );
bool     AM_IsToneOn( void );
bool     AM_IsVoiceOn( void );
// [Phase out] PCM path control functions, defualt is 16k PCM, so we don't need to open it. 
// PCM path control functions
//void     AM_PCM_Mode_Off(void);
//void     AM_PCM_Mode_On(kal_uint16 data);
//kal_bool AM_IsPcmModeOn( void );

// Bluetooth earphone control functions
void     AM_BluetoothOn( uint8 bt_mode);
void     AM_BluetoothOff( void );
bool     AM_IsBluetoothOn( void );
bool     AM_IsBTCordlessMode( void );

// Bluetooth cordkess mode control functions
void     AM_BTCordlessOn( void );
void     AM_BTCordlessOff( void );

// Sound effect control functions
void     AM_SND_PlaybackOn( void );
void     AM_SND_PlaybackOff( bool wait );

// Functions for modem loopback test 
void     AM_SetLoopBackTest( bool enable );
bool     AM_IsLoopBackTest( void );

void     AM_EnableToneLoopBackFlag( kal_bool param );

// InterRAT
void     AM_InterRAT_W2G( void );
void     AM_InterRAT_G2W( kal_uint32 codec );
void     AM_3G_INTRARAT(kal_uint32 codec);

//block filter run time switch function, used in sp_enhance.c
void     AM_SwitchCompFilter( kal_uint16 par );
//block filter turn on/off
void     AM_TurnOnBlockFilter( void );
void     AM_TurnOffBlockFilter( void );


bool     AM_IsAmInSpeechState( void );

bool     AM_IsDataCardOn( void );

// sw digital gain related
void AM_DSP_SetAudioDigitalGain(kal_uint16 digitalVol);
kal_uint16 AM_DSP_GetAudioDigitalGain(void);
void AM_DSP_SetSpeechDigitalGain(kal_uint16 digitalVol);
kal_uint16 AM_DSP_GetSpeechDigitalGain(void);
void AM_DSP_SetSpeechUplinkDigitalGain(kal_uint16 digitalVol);
kal_uint16 AM_DSP_GetSpeechUplinkDigitalGain(void);
void AM_DSP_SetSpeechUplinkSwAgcGain(kal_uint16 digitalVol);
kal_uint16 AM_GetSpeechEnhRefDigitalGain(void);
void AM_DSP_SetSpeechEnhRefDigitalGain(kal_uint16 digitalVol);

// dsp filter/enhancement parameter/coefficient related
void AM_SetNotchFilterParam(int16 *param);
void AM_DSP_WriteNotchFilterParam(void);

kal_bool AM_IsSpeechWB( void );
uint32   AM_GetNetworkRate( void );
#endif


