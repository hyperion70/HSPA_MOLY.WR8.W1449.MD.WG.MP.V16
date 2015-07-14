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
 * afe2.c
 *
 * Project:
 * --------
 *   Maui_sw
 *
 * Description:
 * ------------
 *   Audio Front End
 *
 * Author:
 * -------
 * -------
 *
 *------------------------------------------------------------------------------
 * $Revision:   1.20  $
 * $Modtime:   Aug 15 2005 14:00:06  $
 * $Log:   //mtkvs01/vmdata/Maui_sw/archives/mcu/l1audio/afe2.c-arc  $
 *
 * 03 11 2015 ting-ni.chen
 * [MOLY00098606] [Critical] [TB6582P1] [L0.MP2.MU.DEV] [Telephony] Make MO/MT call with SIM1 or SIM2, can't hear voice from each other
 * afe_common define bug
 *
 * 03 03 2015 miyavi.tsai
 * [MOLY00097589] [Rainier] patch merge form 6580_dev to WR8.1449MP
 * .
 *
 * 06 13 2013 sheila.chen
 * [MOLY00026004] [Volunteer Patch][MT6582] DRC2.0 final solution check-in
 * DRC 2.0 gain range modification (final solution) and Check-in for MT6582
 *
 * 05 22 2013 sheila.chen
 * [MOLY00023417] [Volunteer Patch] DRC2.0 (MagiLoudness) Integration, Fix gain setting error
 * DRC 2.0 bug fix (reference gain scope is incorrect)
 *
 * 05 14 2013 sheila.chen
 * [MOLY00022118] [Volunteer Patch] DRC2.0 (MagiLoudness) Integration
 * DRC 2.0 modification
 *
 * 03 13 2013 sheila.chen
 * [MOLY00008234] [MT6572/MT6582] Integration
 * Remove DSP DL -1db due to SDM gain change (from MT6572 and after)
 *
 * 01 25 2013 sheila.chen
 * [MOLY00009310] DL volume is incorrectly set under idle pcmnway begin
 * Gain is not apply immediatly
 *
 * 01 24 2013 sheila.chen
 * [MOLY00009310] DL volume is incorrectly set under idle pcmnway begin
 * Gain is apply too late
 *
 * 12 18 2012 sheila.chen
 * [MOLY00000112] [MT6583] Pre-integration
 * Set Mode modification
 *
 * 11 01 2012 sheila.chen
 * [MOLY00000112] [MT6583] Pre-integration
 * Sidetone Update
 * 
 * 10 25 2012 sheila.chen
 * [MOLY00000112] [MT6583] Pre-integration
 * 1. Gain
 * 
 * 2. Acoustic loopback
 * 
 * 3. p2w interface
 * 
 * 10 08 2012 sheila.chen
 * [MOLY00000112] [MT6583] Pre-integration
 * MT6589 phone call modification merge back
 * 
 * 09 20 2012 sheila.chen
 * [MOLY00000112] [MT6583] Pre-integration
 * add compile option for analog AFE
 * 
 * 08 21 2012 dior.lin
 * [MOLY00002430] Modify for MD2G wakeup by Audio
 * Modify MD2G wakeup by Audio.
 * 
 * 07 25 2012 sheila.chen
 * [MOLY00000112] [MT6583] Pre-integration
 * Phase in PCMNWAY, param AM manager with 2 parameter, and recording.
 *
 * 06 08 2012 kh.hung
 * removed!
 * .
 *
 * 05 15 2012 jy.huang
 * removed!
 * .
 *
 * 05 10 2012 jy.huang
 * removed!
 * .
 *
 *    Rev 1.0   Dec 31 2004 11:29:16   BM
 * Initial revision.
 *
 *******************************************************************************/

/*
============================================================================================================
------------------------------------------------------------------------------------------------------------
||                        INCLUDE FILES
------------------------------------------------------------------------------------------------------------
============================================================================================================
*/
#include "afe.h"

/*
============================================================================================================
------------------------------------------------------------------------------------------------------------
||                        Global Variables
------------------------------------------------------------------------------------------------------------
============================================================================================================
*/
AFE_STRUCT_T afe;
const unsigned short default_bt_pcm_out_enh_ref_vol = 0x1000; // 0db

//=============================================================================================
//                  AFE Unit Test
//=============================================================================================
#if UNIT_TEST_AFE2
kal_uint16 digital_gain_ut[129];
float digital_gain_ut_diff[128];
kal_uint16 get_digital_gain(kal_int8 index)
{
   AFE_SetOutputVolume(0, 0, index);
   return afe.aud[0].digital_gain;
}
void afe2_unit_test( void )
{
   kal_int8 digital_gain_index;

   for(digital_gain_index=-128; digital_gain_index<=0; digital_gain_index++) {
      digital_gain_ut[digital_gain_index+128] = get_digital_gain(digital_gain_index);
   }

   /// python cmd: 20 * math.log10(0x8000/21.0) = 63.86dB
   ASSERT(digital_gain_ut[0] == 21);
   ASSERT(digital_gain_ut[128] == 0x8000);

   for(digital_gain_index=-128; digital_gain_index<=-1; digital_gain_index++) {
      digital_gain_ut_diff[digital_gain_index+128] =
         digital_gain_ut[digital_gain_index+128+1] * 1.0F /
         digital_gain_ut[digital_gain_index+128];
      /// perfect value is math.pow(10.0, 0.5/20.0) = 1.05925
      ASSERT(digital_gain_ut_diff[digital_gain_index+128] >= 1.035F);
      ASSERT(digital_gain_ut_diff[digital_gain_index+128] <= 1.084F);
   }

   /// shall assert here
   get_digital_gain(1);
}
#endif

/*
============================================================================================================
------------------------------------------------------------------------------------------------------------
||                        AFE Internal Utility Functions
------------------------------------------------------------------------------------------------------------
============================================================================================================
*/

// static void _update_digital_gain(kal_int16 v_lowest, kal_int16 a_lowest);

/* ========================================================================= */
/*   AFE Event Handler                                                  */
/*   This function runs under the context of L1Audio Task                    */
/* ========================================================================= */
static void AFE_Event_Handler( void *data )
{
   ASSERT(!kal_if_hisr());
   
   AFE_Chip_Event_Handler(data);
}
void AFE_Init_status(kal_bool flag)
{
   afe.afe_init = flag;
}

//=============================================================================================
//                  AFE Init
//=============================================================================================
/*****************************************************************************
* FUNCTION
*  AFE_Init
* DESCRIPTION
*   This function is to initialize the AFE module.
*
* PARAMETERS
*  None
* RETURNS
*  None
* CALLER
*  L1Audio_Task, L1Audio_ResetDevice
* GLOBALS AFFECTED
*  None
*****************************************************************************/
void AFE_Init( void )
{
   static kal_bool afe_initialized = KAL_FALSE;
   int I;

   RB_INIT( afe.regq );

   afe.refresh          = KAL_FALSE;
#ifdef ANALOG_AFE_PATH_EXIST		
   afe.mic_src          = 0;	
   afe.sp_flag          = 0;
   afe.fir_flag         = 0;		
   afe.mic_flag         = 0;
#else
	afe.pathWork_flag        =0;
	afe.digitOnly_mic_volume = DG_DL_Speech; // 0db
#endif // ANALOG_AFE_PATH_EXIST 
	afe.digitOnly_sphEnhRef_digital_gain = DG_DL_Speech; // 0db   
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
   afe.accessory_flag   = KAL_FALSE;
   afe.ext_op_on        = KAL_FALSE;
   afe.ext_op_delay     = 0;
   afe.mute             = KAL_FALSE;
   afe.loopback         = KAL_FALSE;
   afe.bt_flag          = KAL_FALSE;
   afe.audio_fs         = 0;  //32K

#if defined(EXT_DAC_SUPPORT)
   afe.ext_dac_i2s_on   = KAL_FALSE;
   afe.ext_dac_add_st   = KAL_FALSE;
   afe.ext_dac_aud_func = -1;
   afe.ext_dac_level_gain  = 0x8000;
   EXT_DAC_Init();   
#endif       

   for( I = 0; I < L1SP_MAX_AUDIO; I++ ) {
      afe.aud[I].out_dev      = 0;
      afe.aud[I].volume       = 0x77;
#ifdef ANALOG_AFE_PATH_EXIST		
      afe.aud[I].digital_gain = 0x8000;  // (in 1.15 fixed-point) 0 dB
      afe.aud[I].digital_gain_index = 0;
      afe.aud[I].digital_gain_level = 100;
#else 
		afe.aud[I].digitOnly_digital_gain = 4096; // 0db. 
#endif // ANALOG_AFE_PATH_EXIST
      afe.aud[I].mute         = KAL_FALSE;

#if defined(__GAIN_TABLE_SUPPORT__)
      afe.aud[I].total_gain   = 0;
#endif

   }
#if defined(__GAIN_TABLE_SUPPORT__)
   afe.mic_total_gain = 0x0;
   afe.dual_path_loud_spk_gain = 0x0;
#endif

   afe.audioplay                 = KAL_FALSE;
   afe.aClk_on_request           = KAL_FALSE;
   afe.afe_state                 = AFE_STATE_OFF;
   afe.afe_hw_mute               = KAL_FALSE;
   afe.afe_event_handler_hw_mute = KAL_FALSE;
   afe.afe_audio_clk_hw_mute     = KAL_FALSE;
   afe.dis_idleOff_delay         = KAL_FALSE;
   // afe.v8k_off_request           = KAL_FALSE;
   afe.aClk_off_request          = KAL_FALSE;
   afe.toneLoopbackRec           = KAL_FALSE;

   afe.audio_dl_ena    = KAL_FALSE;
   afe.voice_dl_ena    = KAL_FALSE;
#ifdef ANALOG_AFE_PATH_EXIST		
   afe.system_poweroff = KAL_FALSE;
#endif
   if (KAL_FALSE == afe_initialized) {
      afe.aud_id = L1Audio_GetAudioID();
      L1Audio_SetEventHandler( afe.aud_id, AFE_Event_Handler );
      afe_initialized = KAL_TRUE;      
   }
#if UNIT_TEST_AFE2
   {
      afe2_unit_test();
   }
#endif

   afe.Audio_close_delay_expired = KAL_FALSE;
   afe.Pre_OutDev = 0;
   afe.Pre_aFunc  = -1;

	afe.voice8kMode = 1; // default value
   AFE_Chip_Init();
}

kal_uint8 AFE_GetAfeSate(void)
{
   return afe.afe_state;
}

#ifdef ANALOG_AFE_PATH_EXIST		
void SearchSpkFlag( kal_int16 *v_lowest, kal_int16 *a_lowest )
{
   kal_int16 I, val;
   
   if(afe.mute)
   {
      *v_lowest = -1; 
      *a_lowest = -1;  
      return;
   }   
   
   for( I = L1SP_MAX_AUDIO; I >= 0; I-- ) {
      if( afe.sp_flag & (1<<I) ) {
         val = (kal_uint16)afe.aud[I].out_dev;
         if( val & (L1SP_BUFFER_0|L1SP_BUFFER_1) )
            *v_lowest = I;
         if( val & L1SP_BUFFER_ST )
            *a_lowest = I;
      }
   }
   
   // move _update_digital_gain here for APM 
   _update_digital_gain(*v_lowest, *a_lowest); 
   
   if( *a_lowest >= 0 )
      if( afe.aud[*a_lowest].volume == 0 || afe.aud[*a_lowest].mute == KAL_TRUE )
      {
         *a_lowest = -1;
         AM_DSP_SetAudioDigitalGain(0); // *DP_DigiGain_Setting = 0;
         AM_DSP_SetSpeechDigitalGain(0); //*DP_VOL_OUT_PCM = 0; 
         AM_DSP_SetSpeechEnhRefDigitalGain(DG_DL_Speech);
      }
   if( *v_lowest >= 0 )
      if( afe.aud[*v_lowest].volume == 0 || afe.aud[*v_lowest].mute == KAL_TRUE )
         *v_lowest = -1;
   if (!kal_if_lisr())
		kal_trace(TRACE_STATE, AFE_DIGI_GAIN, AM_DSP_GetSpeechDigitalGain(), AM_DSP_GetAudioDigitalGain(), AM_GetSpeechEnhRefDigitalGain());
}
#else 

void SearchPathWorkingFlag(kal_int16 * v_lowest,kal_int16 * a_lowest)
{
	kal_int16 I;

	*v_lowest = -1; 
	*a_lowest = -1;
	
	if(afe.mute)
   {
      return;
   }   

	for( I = L1SP_MAX_AUDIO; I >= 0; I-- ) {
		if(afe.pathWork_flag & (1<<I)){
			switch (I){
				case L1SP_KEYTONE:
				case L1SP_TONE:
				case L1SP_SPEECH:
		      case L1SP_SND_EFFECT:
		      case L1SP_VOICE:
				case L1SP_DAI:
		      case L1SP_LINEIN:
				{
			
					*v_lowest = I;
					break;
		      }
				case L1SP_AUDIO:
				{
		      	*a_lowest = I;
					break;
				}
			}
		}
   }
}
#endif 

void AFE_SetRefresh( void )
{
   afe.refresh = KAL_TRUE;
}

void AFE_DELAY(uint16 delay)
{
   kal_uint32 curr_frc, latest_us;

   curr_frc = ust_get_current_time();//unit: micro second (us)
   do{
      latest_us = ust_get_current_time();;
   }while(delay > ust_get_duration(curr_frc, latest_us));
}

/*
============================================================================================================
------------------------------------------------------------------------------------------------------------
||                       Chapter: Digital/Analog Gain Related
------------------------------------------------------------------------------------------------------------
============================================================================================================
*/

//=============================================================================================
//                  Section: [Gain] Digital Gain Convert
//=============================================================================================

#ifdef ANALOG_AFE_PATH_EXIST

/// the value of the table is in 1.15 fixed-point
/// -64 dB = 20 log x => x = math.pow(10.0, -64.0/20) * 0x8000
static const kal_uint16 digital_gain_8db_table[8] = {
     21, /// -64 dB
     52, /// -56 dB
    130, /// -48 dB
    328, /// -40 dB
    823, /// -32 dB
   2068, /// -24 dB
   5193, /// -16 dB
  13045  ///  -8 dB
};

/// the value of the table is in 1.14 fixed-point
/// 0.5 dB = 20 log x => x = math.pow(10.0, 0.5/20) * 0x4000
static const kal_uint16 digital_gain_halfdb_table[15] = {
  17355, /// 0.5 dB
  18383, /// 1.0 dB
  19472, /// 1.5 dB
  20626, /// 2.0 dB
  21848, /// 2.5 dB
  23143, /// 3.0 dB
  24514, /// 3.5 dB
  25967, /// 4.0 dB
  27506, /// 4.5 dB
  29135, /// 5.0 dB
  30862, /// 5.5 dB
  32690, /// 6.0 dB
  34627, /// 6.5 dB
  36679, /// 7.0 dB
  38853  /// 7.5 dB
};

#if defined(__GAIN_TABLE_SUPPORT__)
static const kal_uint16 digital_gain_4db_table[17] = 
{
   32767,   /* 0     dB */
   20675,   /* -4    dB */
   13044,   /* -8    dB */
   8231,    /* -12   dB */
   5193,    /* -16   dB */
   3277,    /* -20   dB */
   2068,    /* -24   dB */
   1305 ,   /* -28   dB */
   823,     /* -32   dB */
   519,     /* -36   dB */
   328,     /* -40   dB */
   207,     /* -44   dB */
   130,     /* -48   dB */
   82,      /* -52   dB */
   52,      /* -56   dB */
   33,      /* -60   dB */
   21       /* -64   dB */
};
#endif

/// digital_gain_index: 0:0dB, -1:-0.5dB, ..., -128:-64dB
const kal_uint16 digital_gain_table[17] = 
{
   32767,   /* 0     dB */
   31838,   /* -0.25 dB */
   30934,   /* -0.5  dB */
   30057,   /* -0.75 dB */
   29204,   /* -1    dB */
   28375,   /* -1.25 dB */
   27570,   /* -1.5  dB */
   26788,   /* -1.75 dB */
   26028,   /* -2    dB */
   25290,   /* -2.25 dB */
   24572,   /* -2.5  dB */
   23875,   /* -2.75 dB */
   23197,   /* -3    dB */
   22539,   /* -3.25 dB */
   21900,   /* -3.5  dB */
   21278,   /* -3.75 dB */
   20675    /* -4    dB */
};

kal_uint16 _converted_digital_gain(kal_int8 digital_gain_index)
{
   kal_int8 converted_gain_index;
   kal_uint16 digital_gain; /// 1.15 fixed-point
   
   /// Uncomment the following to make sure MMI code is ready.
   ///ASSERT(digital_gain_index <= 0);
   converted_gain_index = digital_gain_index;
   if (0 == converted_gain_index) {
      digital_gain = 0x8000; /// 0 dB, special case
   } else {
      converted_gain_index = digital_gain_index + 128;
      /// Uncomment the following to make sure MMI code is ready.
      ///ASSERT(converted_gain_index >= 0);
      /// converted_gain_index: 0:-64dB, 1:-63.5dB, 127:-0.5dB
      digital_gain = digital_gain_8db_table[converted_gain_index>>4];
      if ((converted_gain_index&0x0F) > 0) {
         digital_gain = ((kal_uint32)digital_gain * digital_gain_halfdb_table[(converted_gain_index&0x0F)-1]) >> 14;
      }
   }
   return digital_gain;      
}


static void _update_digital_gain_imp(kal_int16 aud_func)
{
   kal_uint16 digital_gain = afe.aud[aud_func].digital_gain;
   kal_uint32 level_gain;

   level_gain = ((uint32)afe.aud[aud_func].digital_gain_level * 0x8000) / 100;
   switch (aud_func) {
      /// Speech
      case L1SP_SPEECH:
      case L1SP_SND_EFFECT:
      case L1SP_VOICE:
      case L1SP_KEYTONE:
      case L1SP_TONE:
         {
            if( (afe.aud[aud_func].mute == KAL_TRUE) || (afe.aud[aud_func].volume == 0) )
               AM_DSP_SetSpeechDigitalGain(0); //*DP_VOL_OUT_PCM = 0;
            else              
					AM_DSP_SetSpeechDigitalGain(((((kal_uint32)DG_DL_Speech * digital_gain) >> 15) * level_gain) >> 15);
         }
         break;
      
      case L1SP_AUDIO:   // Audio (DAF, AAC, WMA, WAV), MIDI, multi-channel wave, tone
         {
            kal_uint16 dsp_gain;
            if( afe.aud[aud_func].mute == KAL_TRUE )
               dsp_gain = 0;
            else
            {
               dsp_gain = ((((kal_uint32) DG_DAF * digital_gain) >> 15) * level_gain) >> 15;
            }
            AM_DSP_SetAudioDigitalGain(dsp_gain); // *DP_DigiGain_Setting = dsp_gain;
         }
         break;
      case L1SP_DAI:   // not really an audio function
         break;
      
      case L1SP_LINEIN:   // can't apply digital gain
         break;
      default:
         ASSERT(0);
   }
}


static void _update_digital_gain(kal_int16 v_lowest, kal_int16 a_lowest)
{
#if defined(__BT_SUPPORT__)
   if(AM_IsBluetoothOn()) // for the case of bluetooth use
   {
      if( afe.aud[L1SP_AUDIO].mute == KAL_TRUE )
         AM_DSP_SetAudioDigitalGain(0) ; // *DP_DigiGain_Setting = 0;
      else
      {
      #if defined(__GAIN_TABLE_SUPPORT__)
         kal_uint32 level_gain;

         level_gain = ((uint32)afe.aud[L1SP_AUDIO].digital_gain_level * 0x8000) / 100;         
			AM_DSP_SetAudioDigitalGain(((((kal_uint32) DG_DAF * afe.aud[L1SP_AUDIO].digital_gain) >> 15) * level_gain) >> 15);
		#else
		
         AM_DSP_SetAudioDigitalGain(AFE_GetAudioDigiGain(KAL_FALSE));
      #endif
      }
      if( afe.aud[L1SP_VOICE].mute == KAL_TRUE || afe.aud[L1SP_SPEECH].mute == KAL_TRUE )
         AM_DSP_SetSpeechDigitalGain(0); //*DP_VOL_OUT_PCM = 0;
      else
      {
      #if defined(__GAIN_TABLE_SUPPORT__)
			AM_DSP_SetSpeechDigitalGain((((kal_uint32)DG_DL_Speech * afe.aud[L1SP_SPEECH].digital_gain) >> 15));
         
      #else
			AM_DSP_SetSpeechDigitalGain(default_bt_pcm_out_vol);
         
      #endif
      }

      if( afe.aud[L1SP_LINEIN].mute == KAL_TRUE && AM_IsBTCordlessMode())
         AM_DSP_SetSpeechUplinkDigitalGain(0); //*DP_VOL_IN_PCM = 0;
      else
         AM_DSP_SetSpeechUplinkDigitalGain(DG_Microphone); // *DP_VOL_IN_PCM = DG_Microphone;
      return;
   }
#endif //defined(__BT_SUPPORT__)

   if (v_lowest >= 0) {
      if (a_lowest >= 0) // Voice Amp ON && Audio Amp ON
      {
         _update_digital_gain_imp(v_lowest);
         _update_digital_gain_imp(a_lowest);
      } 
      else  //Voice Amp ON && Audio Amp OFF
      {
         _update_digital_gain_imp(v_lowest);
      }
   } 
   else if (a_lowest >= 0)   // Voice Amp OFF && Audio Amp ON
   {
      _update_digital_gain_imp(a_lowest);
   } 
   else  // Voice Amp OFF && Audio Amp OFF; Restore the values to default value (for Bluetooth)
   {
      AM_DSP_SetSpeechDigitalGain(DG_DL_Speech); //*DP_VOL_OUT_PCM = DG_DL_Speech;
   #if defined(EXT_DAC_SUPPORT)
      if(afe.ext_dac_aud_func == -1)
   #endif
       AM_DSP_SetAudioDigitalGain(DG_DAF); // *DP_DigiGain_Setting = DG_DAF;
   }
}
#else
const kal_uint16 digitOnly_quater_dB_tableForSpeech[296] = 
{
	10289, 9997, 9713, 9438, /* 8  ~ 7.25 dB*/
	9170, 8910, 8657, 8411, /* 7   ~ 6.25 dB*/
	8173, 7941, 7715, 7497, /* 6   ~ 5.25 dB*/
	7284, 7077, 6876, 6681, /* 5   ~ 4.25 dB*/
	6492, 6308, 6129, 5955, /* 4   ~ 3.25 dB*/
	5786, 5622, 5462, 5307, /* 3   ~ 2.25 dB*/
	5120, 5010, 4868, 4730, /* 2   ~ 1.25 dB*/    // uplink begin (2 db == 5120 == 0x1400)
	4596, 4465, 4339, 4216, /* 1   ~ 0.25 dB*/
	4096, 3980, 3867, 3757, /* 0   ~ -0.75   dB*/ //  downlink begin (0 db == 4096 == 0x1000) ==> chip newer then MT6572
	3645, 3547, 3446, 3349, /* -1  ~ -1.75   dB*/ // downlink begin (-1db == 3645 == 0xE3D) ==> Old chip MT6280 & MT6589 
	3254, 3161, 3072, 2984, /* -2  ~ -2.75   dB*/
	2900, 2817, 2738, 2660, /* -3  ~ -3.75   dB*/
	2584, 2511, 2440, 2371, /* -4  ~ -4.75   dB*/
	2303, 2238, 2175, 2113, /* -5  ~ -5.75   dB*/
	2053, 1995, 1938, 1883, /* -6  ~ -6.75   dB*/
	1830, 1778, 1727, 1678, /* -7  ~ -7.75   dB*/
	1631, 1584, 1539, 1496, /* -8  ~ -8.75   dB*/
	1453, 1412, 1372, 1333, /* -9  ~ -9.75   dB*/
	1295, 1259, 1223, 1188, /* -10 ~ -10.75  dB*/
	1154, 1122, 1090, 1059, /* -11 ~ -11.75  dB*/
	1029, 1000, 971 , 944 , /* -12 ~ -12.75  dB*/
	917 , 891 , 866 , 841 , /* -13 ~ -13.75  dB*/
	817 , 794 , 772 , 750 , /* -14 ~ -14.75  dB*/
	728 , 708 , 688 , 668 , /* -15 ~ -15.75  dB*/
	649 , 631 , 613 , 595 , /* -16 ~ -16.75  dB*/
	579 , 562 , 546 , 531 , /* -17 ~ -17.75  dB*/
	516 , 501 , 487 , 473 , /* -18 ~ -18.75  dB*/
	460 , 447 , 434 , 422 , /* -19 ~ -19.75  dB*/
	410 , 398 , 387 , 376 , /* -20 ~ -20.75  dB*/
	365 , 355 , 345 , 335 , /* -21 ~ -21.75  dB*/
	325 , 316 , 307 , 298 , /* -22 ~ -22.75  dB*/
	290 , 282 , 274 , 266 , /* -23 ~ -23.75  dB*/
	258 , 251 , 244 , 237 , /* -24 ~ -24.75  dB*/
	230 , 224 , 217 , 211 , /* -25 ~ -25.75  dB*/
	205 , 199 , 194 , 188 , /* -26 ~ -26.75  dB*/
	183 , 178 , 173 , 168 , /* -27 ~ -27.75  dB*/
	163 , 158 , 154 , 150 , /* -28 ~ -28.75  dB*/
	145 , 141 , 137 , 133 , /* -29 ~ -29.75  dB*/
	130 , 126 , 122 , 119 , /* -30 ~ -30.75  dB*/
	115 , 112 , 109 , 106 , /* -31 ~ -31.75  dB*/
	103 , 100 , 97  , 94  , /* -32 ~ -32.75  dB*/
	92  , 89  , 87  , 84  , /* -33 ~ -33.75  dB*/
	82  , 79  , 77  , 75  , /* -34 ~ -34.75  dB*/
	73  , 71  , 69  , 67  , /* -35 ~ -35.75  dB*/
	65  , 63  , 61  , 60  , /* -36 ~ -36.75  dB*/
	58  , 56  , 55  , 53  , /* -37 ~ -37.75  dB*/
	52  , 50  , 49  , 47  , /* -38 ~ -38.75  dB*/
	46  , 45  , 43  , 42  , /* -39 ~ -39.75  dB*/
	41  , 40  , 39  , 38  , /* -40 ~ -40.75  dB*/
	37  , 35  , 34  , 33  , /* -41 ~ -41.75  dB*/
	33  , 32  , 31  , 30  , /* -42 ~ -42.75  dB*/
	29  , 28  , 27  , 27  , /* -43 ~ -43.75  dB*/
	26  , 25  , 24  , 24  , /* -44 ~ -44.75  dB*/
	23  , 22  , 22  , 21  , /* -45 ~ -45.75  dB*/
	21  , 20  , 19  , 19  , /* -46 ~ -46.75  dB*/
	18  , 18  , 17  , 17  , /* -47 ~ -47.75  dB*/
	16  , 16  , 15  , 15  , /* -48 ~ -48.75  dB*/
	15  , 14  , 14  , 13  , /* -49 ~ -49.75  dB*/
	13  , 13  , 12  , 12  , /* -50 ~ -50.75  dB*/
	12  , 11  , 11  , 11  , /* -51 ~ -51.75  dB*/
	10  , 10  , 10  , 9   , /* -52 ~ -52.75  dB*/
	9   , 9   , 9   , 8   , /* -53 ~ -53.75  dB*/
	8   , 8   , 8   , 7   , /* -54 ~ -54.75  dB*/
	7   , 7   , 7   , 7   , /* -55 ~ -55.75  dB*/
	6   , 6   , 6   , 6   , /* -56 ~ -56.75  dB*/
	6   , 6   , 5   , 5   , /* -57 ~ -57.75  dB*/
	5   , 5   , 5   , 5   , /* -58 ~ -58.75  dB*/
	5   , 4   , 4   , 4   , /* -59 ~ -59.75  dB*/
	4   , 4   , 4   , 4   , /* -60 ~ -60.75  dB*/
	4   , 4   , 3   , 3   , /* -61 ~ -61.75  dB*/
	3   , 3   , 3   , 3   , /* -62 ~ -62.75  dB*/
	3   , 3   , 3   , 3   , /* -63 ~ -63.75  dB*/
	3   , 3   , 2   , 2   , /* -64 ~ -64.75  dB*/
	2   , 2   , 2   , 2   , /* -65 ~ -65.75  dB*/
};

/**
	Only use when MODEM do not have analog device, ie. ANALOG_AFE_PATH_EXIST is NOT defined

	@digitalGainQDb: input digital gain value in dB. 4 step/1db. 
	  for example: digitalGainDb=1  --> 0.25 dB; digitalGainDb=FFF4(-12) --> -3dB
	@isDL: true for downlink, false for uplink
	@return: value set to dsp
	  
*/
kal_uint16 _digitOnly_convert_digital_gain_forSpeech(kal_int16 digitalGainQDb, kal_bool isDl)
{
	kal_int16 idx = (-digitalGainQDb);

	if(isDl){
#if defined(MT6280) || defined(MT6589)		
		idx += 36; // begin from -1 db 
#else 
		idx += 32; // begin from 0 db 
#endif
	} else {
		// for UL. useless now
	}
	
	return digitOnly_quater_dB_tableForSpeech[idx];
	
}

void _digitOnly_update_digital_gain(kal_int16 v_lowest, kal_int16 a_lowest)
{
#if defined(__BT_SUPPORT__) // DSP_BT_SUPPORT
   if(AM_IsBluetoothOn()) // for the case of bluetooth use
   {
   	// don't care audio function 

		// speech function
      if( afe.aud[L1SP_VOICE].mute == KAL_TRUE || afe.aud[L1SP_SPEECH].mute == KAL_TRUE ) {
         AM_DSP_SetSpeechDigitalGain(0); //*DP_VOL_OUT_PCM = 0;
         AM_DSP_SetSpeechEnhRefDigitalGain(default_bt_pcm_out_enh_ref_vol); // truly 0db in DSP
      }
      else
      {
      #if defined(__GAIN_TABLE_SUPPORT__)
			AM_DSP_SetSpeechDigitalGain(afe.aud[v_lowest].digitOnly_digital_gain );
			AM_DSP_SetSpeechEnhRefDigitalGain(afe.digitOnly_sphEnhRef_digital_gain);
      #else
			AM_DSP_SetSpeechDigitalGain(default_bt_pcm_out_vol);
         AM_DSP_SetSpeechEnhRefDigitalGain(default_bt_pcm_out_enh_ref_vol); // truly 0db in DSP
      #endif
      }

		// don't care line-in function, which is phase out
      return;
   }
#endif //defined(__BT_SUPPORT__) // DSP_BT_SUPPORT

   if (v_lowest >= 0) {
      if (a_lowest >= 0) // Voice Amp ON && Audio Amp ON
      {
         ASSERT(0); // should not have audio function
         // AM_DSP_SetAudioDigitalGain(afe.aud[a_lowest].digitOnly_digital_gain );
      } 
      else  //Voice Amp ON && Audio Amp OFF
      {
      	if(KAL_TRUE == afe.aud[v_lowest].mute){
				AM_DSP_SetSpeechDigitalGain(0);
				AM_DSP_SetSpeechEnhRefDigitalGain(DG_DL_Speech); // default is 0db from ap side
      	} else {
	         AM_DSP_SetSpeechDigitalGain(afe.aud[v_lowest].digitOnly_digital_gain );
				AM_DSP_SetSpeechEnhRefDigitalGain(afe.digitOnly_sphEnhRef_digital_gain);
      	}
      }
   } 
   else if (a_lowest >= 0)   // Voice Amp OFF && Audio Amp ON
   {
      ASSERT(0); // should not have audio function

		// AM_DSP_SetAudioDigitalGain(afe.aud[a_lowest].digitOnly_digital_gain );
   } 
   else  // Voice Amp OFF && Audio Amp OFF; Restore the values to default value
   {
       AM_DSP_SetSpeechDigitalGain(DG_DL_Speech); //*DP_VOL_OUT_PCM = DG_DL_Speech;
       AM_DSP_SetSpeechEnhRefDigitalGain(DG_DL_Speech); // default is 0db from ap side
       AM_DSP_SetAudioDigitalGain(DG_DAF); // *DP_DigiGain_Setting = DG_DAF;
   }
	
   if (!kal_if_lisr())
		kal_trace(TRACE_STATE, AFE_DIGI_GAIN, AM_DSP_GetSpeechDigitalGain(), AM_DSP_GetAudioDigitalGain(), AM_GetSpeechEnhRefDigitalGain());
}

#endif // #ifdef ANALOG_AFE_PATH_EXIST

//=============================================================================================
//                  Section: [Gain] Digital Gain Setting  (Set/Get/Mute)
//=============================================================================================
#ifdef ANALOG_AFE_PATH_EXIST
void AFE_SetDigitalGain( kal_uint8 aud_func, kal_uint8 level )
{
   ASSERT(level<=100);
   kal_trace(TRACE_STATE, AFE_SET_GIDI_GAIN, aud_func, level);
#if defined(__BT_SUPPORT__) // FIXME: DSP_BT_SUPPORT
   if(AM_IsBluetoothOn()) {
      // for the case of bluetooth use 
      return;
   }
#endif
   afe.aud[aud_func].digital_gain_level = level;
#if defined(EXT_DAC_SUPPORT)
   if( aud_func == L1SP_AUDIO )
      afe.ext_dac_level_gain = ((kal_uint32)level * 0x8000) / 100;
#endif
   AFE_SetRefresh();
}

kal_uint16 AFE_GetDigiGain( void )
{
   kal_uint16 gain;
   
   {
      gain = AM_DSP_GetSpeechDigitalGain();//  *DP_VOL_OUT_PCM;
      gain = ( gain >= 0x1000 )? 0x7FFF : (gain << 3);
   }
   return gain;
}

kal_uint16 AFE_GetAudioDigiGain( kal_bool isAPM)
{
   kal_uint32 level_gain;
   kal_uint16 digital_gain;
   
   if(isAPM)
   {
   #if defined(__BT_SUPPORT__) // FIXME: DSP_BT_SUPPORT
      if(AM_IsBluetoothOn()) // for the case of bluetooth use
      {
         if( afe.aud[L1SP_AUDIO].mute == KAL_TRUE )
            return 0;
         else
            return 0x7FFF;
      }
   #endif
   }
   
   digital_gain = afe.aud[L1SP_AUDIO].digital_gain;
   level_gain = ((uint32)afe.aud[L1SP_AUDIO].digital_gain_level * 0x8000) / 100;
   {
      kal_uint16 dsp_gain;
      if( afe.aud[L1SP_AUDIO].mute == KAL_TRUE )
         dsp_gain = 0;
      else
      {
         dsp_gain = ((((kal_uint32) DG_DAF * digital_gain) >> 15) * level_gain) >> 15;
      }
      return dsp_gain;
   }
}

void AFE_SetDigitalMute( kal_bool mute )
{
   DelayCmd dc;
   
  dc.addr = AFE_AMCU_CON1;
   if(mute == KAL_TRUE) {
     dc.val = (*AFE_AMCU_CON1 & ~(0xC)) | (0xC);
   }
   else {
      dc.val = (*AFE_AMCU_CON1 & ~(0xC)) | (0x0);
   }
  RB_PUT( afe.regq, dc );
}
#else
/**
	@aud_func: 
	@digitalGainQdB: input digital gain value in quarter dB, i.e. 4 step/1db. 
	  for example: digitalGainDb=1  --> 0.25 dB; digitalGainDb=FFF4(-12) --> -3dB
*/
void AFE_DigitalOnly_SetDigitalGain(kal_uint8 aud_func, kal_int16 digitalGainQdB)
{	
   kal_trace(TRACE_STATE, AFE_SET_GIDI_GAIN, aud_func, digitalGainQdB);
	ASSERT((digitalGainQdB)<=0 && (digitalGainQdB>=-256)); // value frome -64 db to 0 db
	
	if ((L1SP_AUDIO != aud_func)
		&& (L1SP_DAI != aud_func)
		&&(L1SP_LINEIN != aud_func)) {
		afe.aud[aud_func].digitOnly_digital_gain = _digitOnly_convert_digital_gain_forSpeech(digitalGainQdB, true); 
	} else {
		// do nothing		
	}
	
	L1Audio_SetEvent(afe.aud_id, NULL);
}

#endif

/**

	@digitalGainQdB: input digital gain value in quarter dB, i.e. 4 step/1db. 
	  for example: digitalGainDb=1  --> 0.25 dB; digitalGainDb=FFF4(-12) --> -3dB
*/
void AFE_DigitalOnly_SetEnhRefDigitalGain(kal_int16 refDigitalGainQdB)
{
	kal_trace(TRACE_STATE, AFE_SET_SPH_REF_GIDI_GAIN, refDigitalGainQdB);
	ASSERT((refDigitalGainQdB)<=0 && (refDigitalGainQdB>=-28)); // value from -7 db to 0 db
	
	afe.digitOnly_sphEnhRef_digital_gain = _digitOnly_convert_digital_gain_forSpeech(refDigitalGainQdB, true);
	
	L1Audio_SetEvent(afe.aud_id, NULL);
}

//=============================================================================================
//                  Section: [Gain] Analog Gain Related
//=============================================================================================
kal_uint16 AFE_AGainRangeConvert(kal_uint16 org_vol)
{
#if __AFE_ANALOG_GAIN_UPPER_BOUND__
   return (org_vol > MAX_PGA_GAIN) ? MAX_PGA_GAIN : org_vol;
#else
   return org_vol;
#endif
}

/*****************************************************************************
* FUNCTION
*  AFE_GetPGAGainInfo
* DESCRIPTION
*  Get PGA gain information
*
* PARAMETERS
*  eBuffer       - AFE buffer type
*  pi2MaxGain    - Maximum gain in dB (ex. 22 means +22dB)
*  pu2Step       - Gain step in dB (ex. 2 means +2dB)
*  pu2TotalLevel - Totoal gain level (ex. 16 means there are 16 levels could 
*                  be applied)
* RETURNS
*  None
* CALLER
*  Task
*****************************************************************************/
void AFE_GetPGAGainInfo(AFE_BUFFER_T eBuffer, kal_int16 *pi2MaxGain, 
                        kal_uint16 *pu2Step, kal_uint16 *pu2TotalLevel)
{
   ASSERT((pi2MaxGain != NULL) && (pu2Step != NULL) && (pu2TotalLevel != NULL));
   ASSERT(eBuffer < AFE_BUFFER_MAX);
   *pu2TotalLevel = 16;
   switch(eBuffer)
   {
      case AFE_BUFFER_NONE:
         *pi2MaxGain = 0;
         *pu2Step = 0;
         break;
      case AFE_BUFFER_AUDIO:
         *pi2MaxGain = 23;  // +23dB
         *pu2Step = 3;      // 3dB/step
         break;
      case AFE_BUFFER_VOICE:
         *pi2MaxGain = 8;   // +8dB
         *pu2Step = 2;      // 2dB/step
         break;
      case AFE_BUFFER_MIC:
         *pi2MaxGain = 48;
         *pu2Step = 2;
         *pu2TotalLevel = 32;
         break;
   
      default:
         break;
   }
}

/*****************************************************************************
* FUNCTION
*  AFE_GetPathUsage
* DESCRIPTION
*  This function is to get current AFE buffer usage in each mode
*
* PARAMETERS
*  u1AudFunc  - L1SP_KEYTONE/L1SP_TONE/L1SP_SPEECH/L1SP_SND_EFFECT/L1SP_AUDIO/..
*  ePhoneMode - Phone mode
*  epBuffer   - AFE buffer type
* RETURNS
*  None
* CALLER
*  Task
*****************************************************************************/
void AFE_GetPathUsage(kal_uint8 u1AudFunc, PHONE_MODE_T ePhoneMode, AFE_BUFFER_T *peBuffer)
{
    ASSERT(peBuffer != NULL);
    ASSERT(ePhoneMode < PHONE_MODE_MAX);

    {
        switch (ePhoneMode)
        {
        case PHONE_MODE_HANDSET:
            if (L1SP_SPEAKER1 & (L1SP_BUFFER_0|L1SP_BUFFER_1))
            {
               *peBuffer =  AFE_BUFFER_VOICE;
            }
            else if (L1SP_SPEAKER1 & L1SP_BUFFER_ST)
            {
                *peBuffer =  AFE_BUFFER_AUDIO;
            }
            else
            {
                *peBuffer = AFE_BUFFER_NONE;
            }
            break;
        case PHONE_MODE_HEADSET:
            if (L1SP_SPEAKER2 & (L1SP_BUFFER_0|L1SP_BUFFER_1))
            {
               *peBuffer =  AFE_BUFFER_VOICE;
            }
            else if (L1SP_SPEAKER2 & L1SP_BUFFER_ST)
            {
                *peBuffer =  AFE_BUFFER_AUDIO;
            }
            else
            {
                *peBuffer = AFE_BUFFER_NONE;
            }
            break;
        case PHONE_MODE_HANDFREE:
            if (L1SP_LOUD_SPEAKER & (L1SP_BUFFER_0|L1SP_BUFFER_1))
            {
               *peBuffer =  AFE_BUFFER_VOICE;
            }
            else if (L1SP_LOUD_SPEAKER & L1SP_BUFFER_ST)
            {
                *peBuffer =  AFE_BUFFER_AUDIO;
            }
            else
            {
                *peBuffer = AFE_BUFFER_NONE;
            }
            break;
        case PHONE_MODE_BT_EARPHONE:
            *peBuffer = AFE_BUFFER_NONE;
            break;
        default:
            break;

        }
    }
}


/*****************************************************************************
* FUNCTION
*  AFE_GetNVRAMDigitalGainSupport
* DESCRIPTION
*  This function return if support digital setting from NVRAM data
*
* PARAMETERS
*  None
* RETURNS
*  KAL_TRUE   - Support digital gain
*  KAL_FALSE  - Not support digital gain
* CALLER
*  Task
*****************************************************************************/
kal_bool AFE_GetNVRAMDigitalGainSupport(void)
{
#ifdef __NVRAM_AFE_DIGITAL_GAIN_SUPPORT__
   return KAL_TRUE;
#else
   return KAL_FALSE;
#endif
}

#if 0 //def ANALOG_AFE_PATH_EXIST
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
#endif // ANALOG_AFE_PATH_EXIST
//=============================================================================================
//                  Section: [Gain] __GAIN_TABLE_SUPPORT__ Specific Functions
//=============================================================================================
#if defined(__GAIN_TABLE_SUPPORT__)
/*****************************************************************************
* FUNCTION
*  AFE_SetOutputGainControl
* DESCRIPTION
*  This function set detail gain value to internal analog gain, digital gain, external amp gain
*
* PARAMETERS
*  aud_func    - audio function
*  total_gain  - containes analog gain[26:31](6 bits), digital gain[18:25](8 bits), external amp gain[0:17](18bits)
* RETURNS
*  None
* CALLER
*  Task
*****************************************************************************/
#ifdef ANALOG_AFE_PATH_EXIST
void AFE_SetOutputGainControl(uint8 aud_func, uint32 total_gain)
{
   kal_uint16 digi_gain;
   kal_uint8 gain_index;
   afe.aud[aud_func].total_gain = total_gain;
   afe.aud[aud_func].volume = (uint8)((total_gain >> 26) << 4);// ( >>26 ) << 2  to be 8 bits, which fulfill afe.aud[aud_func].volume design
   gain_index = (kal_uint8)((total_gain << 6) >> 24);
   
   digi_gain = digital_gain_4db_table[gain_index >> 4];// * digital_gain_quadb_table[gain_index & 0xF];
   if((gain_index & 0xF) > 0){
      digi_gain = ((kal_uint32)digi_gain * digital_gain_table[(gain_index&0x0F)]) >> 15;
   }
   afe.aud[aud_func].digital_gain = digi_gain;
   afe_prompt_trace(MOD_L1SP, "afe set gain control func %d dev %x sp_flag %x",aud_func, afe.aud[aud_func].out_dev, afe.sp_flag);
   afe_prompt_trace(MOD_L1SP, "AFE set func %d gain_ctrl Ana %d Dig %d(%d) Ext %x", aud_func, total_gain >> 26, gain_index, digi_gain, total_gain & 0x3FFFF);
   kal_brief_trace(TRACE_STATE, AFE_SET_OUTPUT_GAIN_CONTROL, aud_func, total_gain >> 26, gain_index, digi_gain, total_gain & 0x3FFFF);
   AFE_SetRefresh();
}
#endif 

/*****************************************************************************
* FUNCTION
*  AFE_SetMicGainControl
* DESCRIPTION
*  This function set detail gain value to mic :internal analog gain, digital gain, external device gain
*
* PARAMETERS
*  mic_gain  - containes analog gain[26:31], digital gain[18:25], external amp gain[0:17]
* RETURNS
*  None
* CALLER
*  Task
*****************************************************************************/
void AFE_SetMicGainControl(uint32 total_gain)
{
   kal_uint16 digi_gain;
   kal_uint8 gain_index;
   afe.mic_total_gain = total_gain;
   // afe.mic_volume = (uint8)(total_gain >> 26) // phase out

   gain_index = (kal_uint8)((total_gain << 6) >> 24);
   digi_gain = digital_gain_4db_table[gain_index >> 4];// * digital_gain_quadb_table[gain_index & 0xF];
   if((gain_index & 0xF) > 0){
      digi_gain = ((kal_uint32)digi_gain * digital_gain_table[(gain_index&0x0F)]) >> 15;
   }
   AM_DSP_SetSpeechUplinkDigitalGain( digi_gain * DG_Microphone ) >> 15); //*DP_VOL_IN_PCM = ( digi_gain * DG_Microphone ) >> 15;
   kal_trace(TRACE_STATE, AFE_SET_MIC_GAIN_CONTROL, total_gain >> 26, gain_index, digi_gain );
   AFE_SetRefresh();
}


/*****************************************************************************
* FUNCTION
*  AFE_GetAllPathUsage
* DESCRIPTION
*  This function is to get current AFE buffer usage in each mode
*
* PARAMETERS
*  u1AudFunc[in]  - AUD_VOLUME_CTN = 0, tone
*   AUD_VOLUME_KEY,              1: keytone 
*   AUD_VOLUME_MIC,              2: microphone 
*   AUD_VOLUME_FMR,              3: FM Radio 
*   AUD_VOLUME_SPH,              4: Speech 
*   AUD_VOLUME_SID,              5: Side-tone 
*   AUD_VOLUME_MEDIA,            6: Multi-Media 
*   AUD_VOLUME_TVO,              7: TV-OUT 
*
*  u1Path[in] -  AUD_PATH_RECEIVER,          -speaker
*                AUD_PATH_HEADSET,           -Headset
*                AUD_PATH_SPEAKER,           -Loudspeaker
*                AUD_DUAL                    -headset and loudspeaker
*
*  epBuffer[out]   - AFE buffer type
*  pu2TotalLevel[out] - total level number of epBuffer
*  digigain[out]   - true: support digital gain
*                    false: not support
*  ext_dac[out]    - NULL
*                    L1SP_EXT_DAC_BUF0
*                    L1SP_EXT_DAC_BUF1
*  ctrl_point[out] - numbers of control point of ext_dac
* RETURNS
*  None
* CALLER
*  Task
*****************************************************************************/
void AFE_GetAllPathUsage(aud_volume_enum u1AudFunc, aud_path_enum u1Path,
                        AFE_BUFFER_T *peBuffer, kal_uint16 *pu2TotalLevel,
                        kal_bool *digital_gain,
                        kal_uint8 *ext_dac, kal_uint16 *ctrl_point)
{
   #define AFE_BUFFER_AUD_GAINLEVEL   16
   #define AFE_BUFFER_VOICE_GAINLEVEL 16
   #define AFE_BUFFER_MIC_GAINLEVEL   64

   if(u1AudFunc == AUD_VOLUME_SID){
      *peBuffer = AFE_BUFFER_NONE;
      *pu2TotalLevel = 0;
      *digital_gain = KAL_FALSE;
      *ctrl_point = 0;
      *ext_dac = 0;
      return;
   }
   switch (u1Path) {
      case AUD_PATH_RECEIVER:
         if(u1AudFunc == AUD_VOLUME_KEY || u1AudFunc == AUD_VOLUME_CTN || u1AudFunc == AUD_VOLUME_SPH){
            *peBuffer = AFE_BUFFER_VOICE;
            *pu2TotalLevel = AFE_BUFFER_VOICE_GAINLEVEL;
            *digital_gain = KAL_TRUE;

         } else  if (u1AudFunc == AUD_VOLUME_MIC){
            *peBuffer = AFE_BUFFER_MIC;
            *pu2TotalLevel = AFE_BUFFER_MIC_GAINLEVEL;
            *digital_gain = KAL_TRUE;
         }
         else{
            *peBuffer = AFE_BUFFER_NONE;
            *pu2TotalLevel = 0;
            *digital_gain = KAL_FALSE;
         }
         *ext_dac = 0;
         *ctrl_point = 0;
         break;      

      case AUD_PATH_HEADSET:
      case AUD_PATH_DUAL:
      #if defined(LG_EXT_AMP_SUPPORT)
         if(u1AudFunc == AUD_VOLUME_SPH || u1AudFunc == AUD_VOLUME_CTN){
            *peBuffer = AFE_BUFFER_VOICE;
            *pu2TotalLevel = AFE_BUFFER_VOICE_GAINLEVEL;
            *digital_gain = KAL_TRUE;
            *ctrl_point = EXT_DAC_Volume_Ctrl_Point(u1AudFunc,u1Path);
            if(*ctrl_point > 0)
               *ext_dac = L1SP_SPEAKER2 & (L1SP_EXT_DAC_BUF0 | L1SP_EXT_DAC_BUF1);
         } else
      #endif
         if(u1AudFunc != AUD_VOLUME_MIC){
            *peBuffer = AFE_BUFFER_AUDIO;
            *pu2TotalLevel = AFE_BUFFER_AUD_GAINLEVEL;
            if(u1AudFunc != AUD_VOLUME_FMR)
               *digital_gain = KAL_TRUE;
            else
               *digital_gain = KAL_FALSE;
         #if defined(LG_EXT_AMP_SUPPORT)
            *ctrl_point = EXT_DAC_Volume_Ctrl_Point(u1AudFunc,u1Path);
         #else
            *ctrl_point = 0;
         #endif
            if(*ctrl_point > 0)
               *ext_dac = L1SP_SPEAKER2 & (L1SP_EXT_DAC_BUF0 | L1SP_EXT_DAC_BUF1);
         } else if (u1AudFunc == AUD_VOLUME_MIC){
            *peBuffer = AFE_BUFFER_MIC;
            *pu2TotalLevel = AFE_BUFFER_MIC_GAINLEVEL;
            *digital_gain = KAL_TRUE;
            *ctrl_point = 0;
            *ext_dac = 0;
         }
         break;              
      case AUD_PATH_SPEAKER:
      #if defined(LG_EXT_AMP_SUPPORT)
         if(u1AudFunc == AUD_VOLUME_SPH  || u1AudFunc == AUD_VOLUME_CTN){
            *peBuffer = AFE_BUFFER_VOICE;
            *pu2TotalLevel = AFE_BUFFER_VOICE_GAINLEVEL;
            *digital_gain = KAL_TRUE;
            *ctrl_point = EXT_DAC_Volume_Ctrl_Point(u1AudFunc,u1Path);
            if(*ctrl_point > 0)
               *ext_dac = L1SP_LOUD_SPEAKER & (L1SP_EXT_DAC_BUF0 | L1SP_EXT_DAC_BUF1);
         } else
      #endif
         if(u1AudFunc != AUD_VOLUME_MIC){
            *peBuffer = AFE_BUFFER_AUDIO;
            *pu2TotalLevel = AFE_BUFFER_AUD_GAINLEVEL;
            if(u1AudFunc != AUD_VOLUME_FMR)
               *digital_gain = KAL_TRUE;
            else
               *digital_gain = KAL_FALSE;
      #if defined(LG_EXT_AMP_SUPPORT)
            *ctrl_point = EXT_DAC_Volume_Ctrl_Point(u1AudFunc,u1Path);
      #else
            *ctrl_point = 0;
      #endif
            if(*ctrl_point > 0)
               *ext_dac = L1SP_LOUD_SPEAKER & (L1SP_EXT_DAC_BUF0 | L1SP_EXT_DAC_BUF1);
         } else if (u1AudFunc == AUD_VOLUME_MIC){
            *peBuffer = AFE_BUFFER_MIC;
            *pu2TotalLevel = AFE_BUFFER_MIC_GAINLEVEL;
            *digital_gain = KAL_TRUE;
            *ctrl_point = 0;
            *ext_dac = 0;
         }
         break;
      case AUD_PATH_BT:
         if(u1AudFunc != AUD_VOLUME_MIC){
            *peBuffer = AFE_BUFFER_NONE;
            *pu2TotalLevel = 0;
            *digital_gain = KAL_TRUE;
            *ctrl_point = 0;
            *ext_dac = 0;
         } else if (u1AudFunc == AUD_VOLUME_MIC){
            *peBuffer = AFE_BUFFER_NONE;
            *pu2TotalLevel = 0;
            *digital_gain = KAL_TRUE;
            *ctrl_point = 0;
            *ext_dac = 0;
         }
         break;         
      case AUD_PATH_UNKNOWN:
         //only for FM microphone setting
         if(u1AudFunc == AUD_VOLUME_MIC){
            *peBuffer = AFE_BUFFER_MIC;
            *pu2TotalLevel = AFE_BUFFER_MIC_GAINLEVEL;
            *digital_gain = KAL_TRUE;
            *ctrl_point = 0;
            *ext_dac = 0;
         }
         break;
      default:
         ASSERT(0);
   }
}

/*****************************************************************************
* FUNCTION
*  AFE_GetExtPGAInfo
* DESCRIPTION
*  This function is to get info of external DAC or AMP
*
* PARAMETERS
*  ext_dac[in] - L1SP_EXT_DAC_BUF0
*                L1SP_EXT_DAC_BUF1
*  ctrl_point[in]   - index of control pointer 0~
*  total_level[out] - numbers of level of this ext_dac
*  bit_number[out]  - numbers of bits of this ext_dac
* RETURNS
*  None
* CALLER
*  Task
*****************************************************************************/
void AFE_GetExtPGAInfo(kal_uint8 ext_dac, kal_uint16 ctrl_point, kal_uint8* total_level, kal_uint8* bit_number)
{
#if defined(LG_EXT_AMP_SUPPORT)
   EXT_DAC_GetCtrlPointBitLevel(ext_dac, ctrl_point, total_level, bit_number);
#else
   total_level = 0;
   bit_number = 0;
#endif
}

/*****************************************************************************
* FUNCTION
*  AFE_GetExtPGAInfo
* DESCRIPTION
*  This function is to get info of external DAC or AMP
*
* PARAMETERS
*  ext_dac[in] - L1SP_EXT_DAC_BUF0
*                L1SP_EXT_DAC_BUF1
*  ctrl_point[in]   - index of control pointer 0~
*  total_level[in]  - numbers of level of this ext_dac to be copied
*  gain_map[out]    - the array to store actual gain of this control_point, ex:gain_map[0]=-65, gain_map[1]=-55
* RETURNS
*  None
* CALLER
*  Task
*****************************************************************************/
void AFE_GetExtPGAGainMap(kal_uint8 ext_dac, kal_uint16 ctrl_point, kal_uint8 total_level, kal_int8* gain_map)
{
#if defined(LG_EXT_AMP_SUPPORT)
   EXT_DAC_GetCtrlPointGainMap(ext_dac, ctrl_point, gain_map);
#endif
}

/*****************************************************************************
* FUNCTION
*  AFE_GetPGAGainMap
* DESCRIPTION
*  This function is to get gain map of AFE buffer
*
* PARAMETERS
*  eBuffer[in] - AFE buffer type
*  u2TotalLevel[in] - numbers of level of this afe_buffer to be copied
*  gain_map[out]    - the array to store actual gain of AFE buffer
* RETURNS
*  None
* CALLER
*  Task
*****************************************************************************/
void AFE_GetPGAGainMap(AFE_BUFFER_T eBuffer, kal_uint16 u2TotalLevel, kal_int8 *pPGA_Map)
{
   kal_uint32 i = 0;
   switch (eBuffer) {
      case AFE_BUFFER_AUDIO:
         for( i = 0 ; i < u2TotalLevel ; i++ )
            pPGA_Map[i] = -22 + i * 3;
         break;
      case AFE_BUFFER_VOICE:
         for( i = 0 ; i < u2TotalLevel ; i++ )
            pPGA_Map[i] = -22 + i * 2;
         break;
      case AFE_BUFFER_MIC:
         for( i = 0 ; i < u2TotalLevel ; i++ )
            pPGA_Map[i] = -20 + i;
         break;
      default:
         break;
   }
}

/*****************************************************************************
* FUNCTION
*  AFE_GetOutputGainControl
* DESCRIPTION
*  This function get detail gain value to internal analog gain, digital gain, external amp gain
*
* PARAMETERS
*  aud_func    - audio function
* RETURNS
*  total_gain  - containes analog gain[26:31](6 bits), digital gain[18:25](8 bits), external amp gain[0:17](18bits)
* CALLER
*  Task
*****************************************************************************/
kal_uint32 AFE_GetOutputGainControl(kal_uint8 aud_func)
{
   return afe.aud[aud_func].total_gain;
}

void AFE_SetOutputGainControlDualPath( kal_uint8 aud_func, kal_uint32 ext_amp_gain )
{
#if defined(LG_EXT_AMP_SUPPORT) 
   afe.dual_path_loud_spk_gain = (ext_amp_gain & 0x3FFFF);
   kal_trace(TRACE_STATE, AFE_SET_DUAL_PATH_GAIN, afe.dual_path_loud_spk_gain);
#endif
}

#endif // __GAIN_TABLE_SUPPORT__

//=============================================================================================
//                  Section: [Gain] Device Gain (Mute/Output Volume)
//=============================================================================================
#if 0 //def ANALOG_AFE_PATH_EXIST
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

void AFE_DigitalOnly_SetMicrophoneVolume( kal_uint8 mic_volume )
{
	kal_brief_trace(TRACE_STATE, AFE_SET_MIC_VOLUME, mic_volume);
	ASSERT((mic_volume)>=0 && (mic_volume<=120)); // range is 0~ 30 dB
	
	// if((mic_volume)<=0 && (mic_volume>=-256)){
	afe.digitOnly_mic_volume = (mic_volume>>2); // 4 is 1 db 
	//} else {

	//}
	
	// AFE_SetRefresh(); 
	L1Audio_SetEvent(afe.aud_id, NULL);
}
#endif 

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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

/*****************************************************************************
* FUNCTION
*  AFE_Mute
* DESCRIPTION
*   This function is to mute both microphone and speaker.
*
* PARAMETERS
*  mute - true : mute ; false : unmute ¡@¡@
* RETURNS
*  None
* GLOBALS AFFECTED
*  None
*****************************************************************************/
void AFE_Mute( kal_bool mute )
{
   afe.mute = mute;
   AFE_SetRefresh();
}

void AFE_MuteSpeaker( kal_uint8 aud_func, kal_bool mute )
{
   afe.aud[aud_func].mute = mute;
   kal_trace(TRACE_STATE, AFE_MUTE_SPEAKER, aud_func, mute);
   AFE_SetRefresh();
}

kal_bool AFE_IsSpeakerMuted( kal_uint8 aud_func)
{
   return afe.aud[aud_func].mute;
}

#ifdef ANALOG_AFE_PATH_EXIST

void  AFE_GetOutputVolume( kal_uint8 aud_func, kal_uint8 *volume1, kal_int8 *digital_gain_index )
{
   *volume1 = afe.aud[aud_func].volume;
   *digital_gain_index = afe.aud[aud_func].digital_gain_index;
}
#else 
void AFE_DigitalOnly_GetOutputVolume(kal_uint8 aud_func, kal_uint8 *vol)
{
	*vol = afe.aud[aud_func].digitOnly_digital_gain;
}

#endif // ANALOG_AFE_PATH_EXIST

/*
============================================================================================================
------------------------------------------------------------------------------------------------------------
||                       Chapter: Path/Device Control
------------------------------------------------------------------------------------------------------------
============================================================================================================
*/

//=============================================================================================
//                  Section: [Path] Speaker Functions
//=============================================================================================

/*****************************************************************************
* FUNCTION
*  AFE_TurnSpeakerOn
* DESCRIPTION
*   This function is to turn on the speaker of an audio function.
*
* PARAMETERS
*  aud_func - the audio function
* RETURNS
*  None
* CALLER
*  Task
* GLOBALS AFFECTED
*  None
*****************************************************************************/
#ifdef ANALOG_AFE_PATH_EXIST
void AFE_TurnOnSpeaker( kal_uint8 aud_func )
{
   kal_uint32 savedMask;
   savedMask = SaveAndSetIRQMask();    /* Disable interrupt to prevent race condition */  
   afe.sp_flag |= (1<<aud_func);
   RestoreIRQMask(savedMask);
   AFE_SetRefresh();
   L1Audio_Msg_AFE_TurnSpk( L1AUDIO_Str_onoff(1), L1AUDIO_Func_Name(aud_func) );
}
#endif
/*****************************************************************************
* FUNCTION
*  AFE_TurnSpeakerOff
* DESCRIPTION
*   This function is to turn off the speaker of an audio function.
*
* PARAMETERS
*  aud_func - the audio function
* RETURNS
*  None
* CALLER
*  Task, L1Audio_HISR(via AM_AudioPlaybackOff)
* GLOBALS AFFECTED
*  None
*****************************************************************************/
#ifdef ANALOG_AFE_PATH_EXIST
void AFE_TurnOffSpeaker( kal_uint8 aud_func )
{
   kal_uint32 savedMask;
   savedMask = SaveAndSetIRQMask();    /* Disable interrupt to prevent race condition */
   afe.sp_flag &= ~(1<<aud_func);
   RestoreIRQMask(savedMask);
   AFE_SetRefresh();
   L1Audio_Msg_AFE_TurnSpk( L1AUDIO_Str_onoff(0), L1AUDIO_Func_Name(aud_func) );
}


void AFE_FastCloseSpk(void)
{
   afe.system_poweroff = KAL_TRUE;
}
#endif

//=============================================================================================
//                  Section: [Path] Microphone Functions
//=============================================================================================
/*****************************************************************************
* FUNCTION
*  AFE_TurnMicrophoneOn
* DESCRIPTION
*   This function is to turn on the microphone of an audio function.
*
* PARAMETERS
*  aud_func - the audio function
* RETURNS
*  None
* CALLER
*  Task
* GLOBALS AFFECTED
*  None
*****************************************************************************/
#ifdef ANALOG_AFE_PATH_EXIST
void AFE_TurnOnMicrophone( kal_uint8 aud_func )
{
   kal_uint32 savedMask;
   savedMask = SaveAndSetIRQMask();    // Disable interrupt to prevent race condition
   afe.mic_flag |= (1<<aud_func);
   RestoreIRQMask(savedMask);
#if defined(__DUAL_MIC_SUPPORT__)
   *DP2_DUALMIC_CTRL |= 1;
#endif

   AFE_SetRefresh();

   ///Currently, when video recording, video LISR will call Media_Record.
   L1Audio_Msg_AFE_TurnMIC( L1AUDIO_Str_onoff(1), L1AUDIO_Func_Name(aud_func) );
}
#endif 

/*****************************************************************************
* FUNCTION
*  AFE_TurnOffMicrophone
* DESCRIPTION
*   This function is to turn off the microphone of an audio function.
*
* PARAMETERS
*  aud_func - the audio function
* RETURNS
*  None
* CALLER
*  Task
* GLOBALS AFFECTED
*  None
*****************************************************************************/
#ifdef ANALOG_AFE_PATH_EXIST

void AFE_TurnOffMicrophone( kal_uint8 aud_func )
{
   kal_uint32 savedMask;
   /// Disable interrupt to prevent race condition
   savedMask = SaveAndSetIRQMask();
   afe.mic_flag &= ~(1<<aud_func);
   RestoreIRQMask(savedMask);
   
   AFE_SetRefresh();

   ///Currently, when video recording, video LISR will call Media_Record.
   L1Audio_Msg_AFE_TurnMIC( L1AUDIO_Str_onoff(0), L1AUDIO_Func_Name(aud_func) );
}

kal_bool AFE_IsMicrophoneOn( kal_uint8 aud_func )
{
   return (kal_bool)((afe.mic_flag & (1<<aud_func)) != 0);
}
#endif 

//=============================================================================================
//                  Section: [Path] AFE Path Use Functions (when no Analog path existing)
//=============================================================================================
/*****************************************************************************
* FUNCTION
*   AFE_TurnOnPathWork
* DESCRIPTION
*   This function is to turn on the working path of an audio function.
*
* PARAMETERS
*  aud_func - the audio function
* RETURNS
*  None
* CALLER
*  Task
* GLOBALS AFFECTED
*  None
*****************************************************************************/
#ifndef ANALOG_AFE_PATH_EXIST // suing when analog path is NOT exiting

void AFE_TurnOnPathWork( kal_uint8 aud_func )
{
	kal_uint32 savedMask;
	savedMask = SaveAndSetIRQMask(); 	// Disable interrupt to prevent race condition
	afe.pathWork_flag|= (1<<aud_func);
	RestoreIRQMask(savedMask);

	// AFE_SetRefresh();
	L1Audio_SetEvent(afe.aud_id, NULL);

	///Currently, when video recording, video LISR will call Media_Record.
	L1Audio_Msg_AFE_TurnPath( L1AUDIO_Str_onoff(1), L1AUDIO_Func_Name(aud_func) );
}
#endif


/*****************************************************************************
* FUNCTION
*  AFE_TurnOffPathWork
* DESCRIPTION
*   This function is to turn off the working path of an audio function.
*
* PARAMETERS
*  aud_func - the audio function
* RETURNS
*  None
* CALLER
*  Task
* GLOBALS AFFECTED
*  None
*****************************************************************************/
#ifndef ANALOG_AFE_PATH_EXIST // suing when analog path is NOT exiting
void AFE_TurnOffPathWork( kal_uint8 aud_func )
{
   kal_uint32 savedMask;
   /// Disable interrupt to prevent race condition
   savedMask = SaveAndSetIRQMask();
   afe.pathWork_flag &= ~(1<<aud_func);
   RestoreIRQMask(savedMask);
   
   // AFE_SetRefresh();
	L1Audio_SetEvent(afe.aud_id, NULL);
	
   ///Currently, when video recording, video LISR will call Media_Record.
   L1Audio_Msg_AFE_TurnPath( L1AUDIO_Str_onoff(0), L1AUDIO_Func_Name(aud_func) );
}
#endif


//=============================================================================================
//                  Section: [Path] BT Functions
//=============================================================================================
void AFE_SetBtFlag(kal_bool on)
{
	afe.bt_flag = on;
}

/* phase out
void AFE_TurnOnBluetooth( kal_uint16 param )
{
   ASSERT( (*AFE_VDB_CON & 0x0020) == 0 );   // To make sure that BT and DAI are not turned simultaneously
	
   *AFE_VDB_CON |= 0x0008; //Just match WM8904 
   *AFE_VDB_CON    |= (0x0010 | param );
	
   // afe.bt_flag = KAL_TRUE;
   AFE_SetBtFlag(KAL_TRUE);
#ifndef ANALOG_AFE_PATH_EXIST
   *AFE_VMCU_CON1    |= 0x0001;//vbtdai data is sent to dai module
#endif

#if defined(__BT_SUPPORT__)
   // Frame Sync
   if ( !BtRadio_Get_PCM_ShortSync() ) {
      // Long Sync
      *AFE_VDB_CON |= 0x0008;
   }
   AFE_SetRefresh();
#endif //defined(__BT_SUPPORT__)
}


void AFE_TurnOffBluetooth( void ) 
{
   *AFE_VDB_CON    &= ~0x0018;
#ifndef ANALOG_AFE_PATH_EXIST
   *AFE_VMCU_CON1    &= ~0x0001;//vdl data is sent to dai module
#else // existing analog path
   // afe.bt_flag = KAL_FALSE;
   AFE_SetBtFlag(KAL_FALSE);

   {
      kal_int16 v_lowest = -1, a_lowest = -1;
      if( afe.sp_flag ){
         SearchSpkFlag( &v_lowest, &a_lowest );
      }
   }
   AFE_SetRefresh();
#endif // ANALOG_AFE_PATH_EXIST
}
*/
/*
void AFE_TurnOnPcm( kal_uint16 param )
{
   *AFE_VDB_CON    |= (0x0010 | param );
   *AFE_VMCU_CON1  &= ~0x0001;//vbtdai data is sent to dai module
}
void AFE_TurnOffPcm( kal_uint16 param )
{
   *AFE_VDB_CON    &= ~0x0018;
   *AFE_VMCU_CON1  |= 0x0001;//vdl data is sent to dai module
}
*/
//=============================================================================================
//                  Section: [Path] DAI Related Functions
//=============================================================================================
void AFE_TurnOnDAI( void )
{
   ASSERT(0);//it shouldn't be used
   //*AFE_VDB_CON |= 0x0020;
   //L1Audio_Msg_AFE_Switch( L1AUDIO_Str_onoff(1), AFE_Switch_Name(1) );
}

void AFE_TurnOffDAI( void )
{
    ASSERT(0);//it shouldn't be used
   //*AFE_VDB_CON &= ~0x0020;
   //L1Audio_Msg_AFE_Switch( L1AUDIO_Str_onoff(0), AFE_Switch_Name(1) );
}

//=============================================================================================
//                  Section: [Path] External DAC Interface Related Functions
//=============================================================================================
/// External DAC Interface / fmt: 1 = I2S, 0 = EIAJ / cycle: 32 or 16
/*void AFE_TurnOnEDI( kal_uint16 dir, kal_uint16 fmt, kal_uint16 cycle )
{   
   kal_bool slave_mode = (kal_bool)Media_I2S_SLAVE_MODE;
   kal_uint16 en2 = 0;
   ASSERT( fmt < 2 );
   ASSERT( cycle == 16 || cycle == 32 );
   if(dir)
   {
      // DSP workaround for I2S HW issue, audio clock 8K->16K
      *AFE_VAM_SET &= ~0x07;
      *AFE_VAM_SET |= 0x02;
      *AFE_VDB_CON &= ~0x0040;
   }
   else
   {
      *AFE_VDB_CON |= 0x0040;
   }
   *AFE_EDI_CON = ( (en2<<15) | (dir<<8) | (slave_mode<<7) | ((cycle-1)<<2) | (fmt<<1) | 1);
   kal_trace( TRACE_STATE, AFE_SET_EDI, dir, cycle, fmt );
}

void AFE_TurnOffEDI( void )
{
   *AFE_EDI_CON &= ~0x8001;
   *AFE_VDB_CON &= ~0x0040;
   // DSP workaround for I2S HW issue, audio clock 16K->8K
   *AFE_VAM_SET &= ~0x07;
   *AFE_VAM_SET |= 0x05;
}

kal_bool AFE_IsEDIOn( void )
{
   if (*AFE_VDB_CON & 0x0040)
      return KAL_TRUE;
   else
      return KAL_FALSE;
}
*/
//=============================================================================================
//                  Section: [Path] MicBias Functions (for accessory detection use)
//=============================================================================================
/*****************************************************************************
* FUNCTION
*  AFE_TurnOnMicBias , AFE_TurnOffMicBias
*       : Add for accessory detection use
* CALLER
*  AUX_EINT_HISR
*****************************************************************************/
#ifdef ANALOG_AFE_PATH_EXIST
kal_uint8 AFE_TurnOnMicBias( void )
{
   if( afe.accessory_flag == KAL_TRUE )
      return 0;
   afe.accessory_flag = KAL_TRUE;
   AFE_SetRefresh();

   L1Audio_Msg_AFE_Switch( L1AUDIO_Str_onoff(1), AFE_Switch_Name(4) );

   return (afe.mic_src==L1SP_LNA_1);
}

void AFE_TurnOffMicBias(void)
{
   if( afe.accessory_flag == KAL_FALSE )
      return;
   
   afe.accessory_flag = KAL_FALSE;
   AFE_SetRefresh();

   L1Audio_Msg_AFE_Switch( L1AUDIO_Str_onoff(0), AFE_Switch_Name(4) );
}
#endif // #ifdef ANALOG_AFE_PATH_EXIST
//=============================================================================================
//                  Section: [Path] Input/Output Source/Device Related
//=============================================================================================
/*****************************************************************************
* FUNCTION
*  AFE_SetOutputDevice
* DESCRIPTION
*   This function is to set the output device of an audio function.
*
* PARAMETERS
*  aud_func - the audio function
*  device - be L1SP_SPEAKER1, L1SP_SPEAKER2, or L1SP_LOUDSPEAKER
* RETURNS
*  None
* GLOBALS AFFECTED
*  None
*****************************************************************************/
#ifdef ANALOG_AFE_PATH_EXIST
void AFE_SetOutputDevice( kal_uint8 aud_func, kal_uint8 device )
{
#if defined(EXT_DAC_SUPPORT)   
   if(device & (L1SP_EXT_DAC_BUF0 | L1SP_EXT_DAC_BUF1))
   {
      if(!(device & L1SP_BUFFER_ST))
      {
         switch((SND_SRC_MAP>>aud_func*2)&3) 
         { 
            case SRC_AUDIO_DAC:
               afe.ext_dac_add_st = KAL_TRUE;
            case SRC_VOICE_DAC:   
            case SRC_EXT_INPUT:
               device |= L1SP_BUFFER_ST;
               break;
         }
      }
      else
         afe.ext_dac_add_st = KAL_FALSE;
   }
#endif

   afe.aud[aud_func].out_dev = device;   
   AFE_SetRefresh();
   if (!kal_if_hisr() && !kal_if_lisr())
      kal_brief_trace(TRACE_STATE, AFE_SET_OUTPUT_DEVICE, aud_func, device);
}
#endif

kal_uint8 AFE_GetOutputDevice( kal_uint8 aud_func )
{
   return afe.aud[aud_func].out_dev;
}

#ifdef ANALOG_AFE_PATH_EXIST
void AFE_SetInputSource( kal_uint8 src )
{
#if __AFE_DIGITAL_MIC_SUPPORT__
   if( src == L1SP_LNA_0 && L1SP_MICROPHONE1 == L1SP_LNA_DIGITAL )
      src = L1SP_LNA_DIGITAL;
#endif
   afe.mic_src = src;
   AFE_SetRefresh();
   ASSERT(!kal_if_hisr());
   kal_brief_trace(TRACE_STATE, AFE_SET_INPUT_SRC, src);
}


kal_uint8 AFE_GetInputSource( void )
{
   return afe.mic_src;
}


kal_bool AFE_IsAudioLoudSpk( void )
{
   if(afe.aud[L1SP_AUDIO].out_dev & L1SP_BUFFER_EXT)
      return KAL_TRUE;
   else 
      return KAL_FALSE;
}

kal_bool AFE_IsAudioEarphone( void )
{
   if(afe.aud[L1SP_AUDIO].out_dev & L1SP_BUFFER_ST) //earphone
      return KAL_TRUE;
   else 
      return KAL_FALSE;
}
#endif // ANALOG_AFE_PATH_EXIST

/*
============================================================================================================
------------------------------------------------------------------------------------------------------------
||                       Chapter: Audio/Speech Rleated Features
------------------------------------------------------------------------------------------------------------
============================================================================================================
*/

//=============================================================================================
//                  Section: [AUD/SPH] FIR Functions
//=============================================================================================
/*****************************************************************************
* FUNCTION
*  AFE_TurnOnFIR
* DESCRIPTION
*   This function is to turn on the FIR filter of an audio function.
*
* PARAMETERS
*  aud_func - the audio function
* RETURNS
*  None
* CALLER
*  Task
* GLOBALS AFFECTED
*  None
*****************************************************************************/
#ifdef ANALOG_AFE_PATH_EXIST
void AFE_TurnOnFIR( kal_uint8 aud_func )
{
   kal_uint32 savedMask;
   /// Disable interrupt to prevent race condition
   savedMask = SaveAndSetIRQMask();
   afe.fir_flag |= (1<<aud_func);
   RestoreIRQMask(savedMask);

   AFE_SetRefresh();
   ASSERT(!kal_if_hisr());
   kal_brief_trace(TRACE_STATE, AFE_SWITCH_FIR, '+', aud_func);
}
#endif // ANALOG_AFE_PATH_EXIST

/*****************************************************************************
* FUNCTION
*  AFE_TurnFirOff
* DESCRIPTION
*   This function is to turn off the FIR filter of an audio function.
*
* PARAMETERS
*  aud_func - the audio function
* RETURNS
*  None
* CALLER
*  Task
* GLOBALS AFFECTED
*  None
*****************************************************************************/
#ifdef ANALOG_AFE_PATH_EXIST
void AFE_TurnOffFIR( kal_uint8 aud_func )
{
   kal_uint32 savedMask;
   /// Disable interrupt to prevent race condition
   savedMask = SaveAndSetIRQMask();
   afe.fir_flag &= ~(1<<aud_func);
   RestoreIRQMask(savedMask);

   AFE_SetRefresh();
   ASSERT(!kal_if_hisr());
   kal_brief_trace(TRACE_STATE, AFE_SWITCH_FIR, '-', aud_func);
}

kal_bool AFE_IsFIROn( kal_uint8 aud_func )
{
   return (kal_bool)((afe.fir_flag & (1<<aud_func)) != 0);
}
#endif // ANALOG_AFE_PATH_EXIST
//=============================================================================================
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
#endif

/*
============================================================================================================
------------------------------------------------------------------------------------------------------------
||                       Chapter: AFE Related Features
------------------------------------------------------------------------------------------------------------
============================================================================================================
*/

//=============================================================================================
//                  Section: [AFE Feature] ABB Registers Backup/Store (for 65nm projects)
//=============================================================================================
void AFE_RegisterBackup(void)
{
#if __RELOAD_HW_COEFF__

#if (defined(MT6572) || defined(MT6582) || defined(MT6592))
	L1Audio_Msg_AFE_RegBackup( L1AUDIO_Str_Bool(1) );
	afe.regbak.VMCU_CON  = *AFE_VMCU_CON;
	afe.regbak.VDB_CON	 = *AFE_VDB_CON;
	afe.regbak.VLB_CON	 = *AFE_VLB_CON;
	afe.regbak.AMCU_CON0 = *AFE_AMCU_CON0;
	afe.regbak.AMCU_CON1 = *AFE_AMCU_CON1;
	afe.regbak.EDI_CON	 = *AFE_EDI_CON;
	afe.regbak.VMCU_CON1 = *AFE_VMCU_CON1;

_AfeRegisterBackupByChip();

#else //MT6580
   L1Audio_Msg_AFE_RegBackup( L1AUDIO_Str_Bool(1) );
   
   _AfeRegisterBackupByChip();
#endif
#endif
}

void AFE_RegisterStore(void)
{
#if __RELOAD_HW_COEFF__

#if (defined(MT6572) || defined(MT6582) || defined(MT6592))
  L1Audio_Msg_AFE_RegBackup( L1AUDIO_Str_Bool(0) );
  *AFE_VMCU_CON  = afe.regbak.VMCU_CON;  
  *AFE_VDB_CON	 = afe.regbak.VDB_CON; 
  *AFE_VLB_CON	 = afe.regbak.VLB_CON;	 
  *AFE_AMCU_CON0 = afe.regbak.AMCU_CON0;
  *AFE_AMCU_CON1 = afe.regbak.AMCU_CON1; 
  *AFE_EDI_CON	 = afe.regbak.EDI_CON;	 
  *AFE_VMCU_CON1 = afe.regbak.VMCU_CON1;
  
  _AfeRegisterStoreByChip();

#else //MT6580

   L1Audio_Msg_AFE_RegBackup( L1AUDIO_Str_Bool(0) );
   
   _AfeRegisterStoreByChip();
#endif
#endif
}

//=============================================================================================
//                  Section: [AFE Feature] AFE Loop back
//=============================================================================================
void AFE_EnableToneLoopBackFlag( kal_bool param )
{
   if(param)
      afe.toneLoopbackRec = KAL_TRUE;
   else
      afe.toneLoopbackRec = KAL_FALSE;
}

kal_bool AFE_GetLoopbackStatus( void )
{
   return afe.loopback;
}

