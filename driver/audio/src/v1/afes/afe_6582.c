/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2011
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
 * afe_6255.h
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 *  MT6583 chip dependent afe driver
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#if defined(MT6582)

#include "afe.h"

void AFE_SetSamplingRate( uint32 freq )
{
   *AFE_AMCU_CON1 |= 0x0C00;  // turn off HW FIR

#if defined(EXT_DAC_SUPPORT) 
   switch (freq) {
      case 0x00: 
      case 0x20:
      case 0x40:     
         afe.ext_dac_freq = 32000;     
         break;
      case 0x11:
      case 0x21:  
      case 0x41:
         afe.ext_dac_freq = 44100;
         break;
      case 0x12: 
      case 0x22:  
      case 0x42: 
         afe.ext_dac_freq = 48000;
         break;
   }
#endif    
   
   afe.audio_fs = freq;
}

//=============================================================================================
//                 External Amplifier
//=============================================================================================
/*****************************************************************************
* FUNCTION
*  AFE_TurnOnExtAmplifier
*  AFE_TurnOffExtAmplifier
* DESCRIPTION
*   These two function are to turn on/off external amplifier individually
*****************************************************************************/
void AFE_TurnOnExtAmplifier( void )
{
   afe.gpio_lock = KAL_TRUE;
   AFE_SwitchExtAmplifier( true );
   afe.ext_op_on = KAL_TRUE;
}

void AFE_TurnOffExtAmplifier( void )
{
   AFE_SwitchExtAmplifier( false );
   afe.gpio_lock = KAL_FALSE;
   afe.ext_op_on = KAL_FALSE;
}

//=============================================================================================
//                  AFE Loop back
//=============================================================================================

/// Caller: Task
void AFE_TurnOnLoopback( void )
{
   *AFE_VLB_CON |= 0x0022;     // for digital loopback
   *AFE_VLB_CON |= 0x0002;
   afe.loopback = KAL_TRUE;
   kal_brief_trace(TRACE_STATE, AFE_SWITCH_LOOPBACK, '+');
}

void AFE_TurnOffLoopback( void )
{
   *AFE_VLB_CON &= ~0x62;    // for digital loopback
   afe.loopback = KAL_FALSE;

   kal_brief_trace(TRACE_STATE, AFE_SWITCH_LOOPBACK, '-');
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
//=============================================================================================
//                  Audio/8K Clock Related
//=============================================================================================
void AFE_TurnOn8K( void )
{
#ifdef L1D_TEST
 extern  int  PollLoopbackMode(void);
   if( PollLoopbackMode() !=1 )
#endif
   {
      // afe.v8k_off_request = KAL_FALSE;
      *MD2GSYS_CG_CLR2 =  PDN_CON2_VAFE;

		// choose BT v.s. voice down link 
		if( afe.bt_flag == KAL_TRUE) {// VBT (DAI)
			*AFE_VMCU_CON1 |= 0x1;
		}else {// voice downlink
			*AFE_VMCU_CON1 &= ~0x1;
		}
		
      if( afe.voice8kMode == 0 )//narrow band, 4k mode;
         *AFE_VMCU_CON1 |= 0x200;
      else
         *AFE_VMCU_CON1 &= ~0x200;
      *AFE_VMCU_CON    |= 0x0001;
      AFE_SetRefVol(KAL_TRUE);

		// [Remind] [MT6589] This sherif is used when sw sidetone
		// MT6589 uses hw sidetone. So remove it. 
		// For chip uses sw sidetone, please ask SAL to provide interface
      //*DP_8K_LIMITER_CTRL &= ~0x1;
      
		L1Audio_Msg_AFE_Switch( L1AUDIO_Str_onoff(1), AFE_Switch_Name(0) );
   }
}

void AFE_TurnOff8K( void )
{
   // afe.v8k_off_request = KAL_TRUE;
   *MD2GSYS_CG_SET2 = PDN_CON2_VAFE;
   *AFE_VMCU_CON  &= ~0x0001;   
	L1Audio_Msg_AFE_Switch( L1AUDIO_Str_onoff(0), AFE_Switch_Name(0) );
		
}

void AFE_TurnOff8K_Direct( void )
{
   *MD2GSYS_CG_SET2 = PDN_CON2_VAFE;
   *AFE_VMCU_CON  &= ~0x0001;
	L1Audio_Msg_AFE_Switch( L1AUDIO_Str_onoff(0), AFE_Switch_Name(0) );
}

void AFE_TurnOnAudioClock( kal_uint8 clock )
{
   kal_uint16 SampleRate = 0;
   afe.aClk_off_request = KAL_FALSE;   
   AFE_SetRefVol(KAL_TRUE);

   switch (clock) {
      case ASP_FS_8K:
         SampleRate = 0;     
         break;
      case ASP_FS_11K:
         SampleRate = 1;     
         break;               
      case ASP_FS_12K: 
         SampleRate = 2;     
         break;         
      case ASP_FS_16K:
         SampleRate = 4;     
         break;            
      case ASP_FS_22K:
         SampleRate = 5;     
         break;        
      case ASP_FS_24K:  
         SampleRate = 6;     
         break;             
      case ASP_FS_32K:     
         SampleRate = 8;     
         break;        
      case ASP_FS_44K:
         SampleRate = 9;     
         break;                       
      case ASP_FS_48K: 
         SampleRate = 10;     
         break;
   }
   //SampleRate = (clock&3) + 8; //8: 32kHz, 9: 44kHz, 10: 48kHz
   *AFE_AMCU_CON1 = (*AFE_AMCU_CON1 & ~0x03C0) | (SampleRate<<6);

   *MD2GSYS_CG_CLR2 = PDN_CON2_AAFE;
   *AFE_AMCU_CON0 |= 0x0001;
}

void AFE_TurnOffAudioClock( void )
{
   afe.aClk_off_request = KAL_TRUE;    
}

// For hardware equalizer
// The coefficient can be written into register only when the power is on
void AFE_TurnOnAudioPower( void )
{
   *MD2GSYS_CG_CLR2 = PDN_CON2_AAFE;
}

void AFE_TurnOffAudioPower( void )
{
   *MD2GSYS_CG_SET2 = PDN_CON2_AAFE;
}

//=============================================================================================
//                 Update VGain / AGain
//=============================================================================================
#ifdef ANALOG_AFE_PATH_EXIST
static void UpdateAGain( kal_uint8 aud_func )
{
   kal_uint16 vol = afe.aud[aud_func].volume;
   
   if( (aud_func == L1SP_SPEECH) )
   {
      UpdateSidetone( (kal_int8)(vol >> 3) );
   }
   else
      *DP_SIDETONE_VOL = 0;
}

static void UpdateVGain( kal_uint8 aud_func )
{
   kal_uint16 vol = afe.aud[aud_func].volume;
   if( (aud_func == L1SP_SPEECH) )
   {
      UpdateSidetone( (kal_int8)(vol >> 3) );
   }
   else
      *DP_SIDETONE_VOL = 0;
}
#endif

//=============================================================================================
//                  Output Volume Releated Functions
//=============================================================================================
/*****************************************************************************
* FUNCTION
*  AFE_SetOutputVolume
* DESCRIPTION
*   This function is to set the output volume of an audio function.
*
* PARAMETERS
*  aud_func - the audio function
*  volume - range is from 0 to 255
* RETURNS
*  None
* GLOBALS AFFECTED
*  None
*****************************************************************************/
#ifdef ANALOG_AFE_PATH_EXIST

void AFE_SetOutputVolume( kal_uint8 aud_func, kal_uint8 volume1, kal_int8 digital_gain_index )
{  
   kal_uint8 digital_gain_index1 = digital_gain_index;
   kal_uint8 volume = volume1;

   if (AFE_GetNVRAMDigitalGainSupport())
   {
      digital_gain_index1 = volume1 & 0x0F;
      afe.aud[aud_func].volume = volume;
      afe.aud[aud_func].digital_gain_index = digital_gain_index1;
      afe.aud[aud_func].digital_gain = digital_gain_table[digital_gain_index1];
      //kal_prompt_trace(MOD_L1SP, "vol, digital_index, digital_gain = (0x%x, 0x%x, 0x%x) \r\n", volume, digital_gain_index1, afe.aud[aud_func].digital_gain);
   }
   else
   {
      afe.aud[aud_func].volume = volume;
      afe.aud[aud_func].digital_gain_index = digital_gain_index1;
      afe.aud[aud_func].digital_gain = _converted_digital_gain(digital_gain_index1);

      if( (afe.aud[aud_func].out_dev & (L1SP_BUFFER_0|L1SP_BUFFER_1)) || (afe.aud[aud_func].out_dev & (L1SP_BUFFER_ST|L1SP_BUFFER_EXT)) ) //Use digital gain to compesate the analog gain
      {
         if(volume<68) //lower bound is 68
         {
            kal_int16 tmp_gain_index;
            tmp_gain_index = (kal_int16)digital_gain_index;
            tmp_gain_index -= (((68-volume)>>2)<<1);

            if(tmp_gain_index>-128)
               digital_gain_index = (kal_int8)tmp_gain_index;
            else
               digital_gain_index = -128;

            afe.aud[aud_func].volume = volume;
            afe.aud[aud_func].digital_gain_index = digital_gain_index;
            afe.aud[aud_func].digital_gain = _converted_digital_gain(digital_gain_index);
         }
      }
   }  

#if defined(EXT_DAC_SUPPORT) 
   // Note : extrenal DAC is used as earphone or TV-out only 
   // case 1 : play amr with melody volume (7-level case)  
   if(aud_func == L1SP_VOICE && (afe.aud[L1SP_VOICE].out_dev & (L1SP_EXT_DAC_BUF0|L1SP_EXT_DAC_BUF1)))
   {
      kal_uint32 i, type;
      if(!(afe.aud[L1SP_VOICE].out_dev & L1SP_BUFFER_EXT) && (volume1 != 0)) // for play both case : apply AFE gain is OK 
      {
      #if defined(TV_OUT_SUPPORT)   
         if(audio_tv_cable_in)
            type = AUD_VOLUME_TVO;
         else 
      #endif    
            type = AUD_VOLUME_MEDIA;    
         for(i = 0 ; i < AUD_MAX_VOLUME_LEVEL ; i ++)
         {
            // find the closest level
            if(aud_get_volume_gain(VOL_HEADSET, type, i) > volume1) 
               break;
         }
         if(i > 0) i--;
         afe.aud[aud_func].volume = aud_get_volume_gain(VOL_HEADSET, AUD_VOLUME_SPH, i); // apply speech volume       
      }    
   }
   
   // case 2 : play Audio both on earphone and LoudSpk 
   if(aud_func == L1SP_AUDIO && (afe.aud[L1SP_AUDIO].out_dev & (L1SP_EXT_DAC_BUF0|L1SP_EXT_DAC_BUF1)))
   {
      if((afe.aud[L1SP_AUDIO].out_dev & L1SP_BUFFER_EXT) && (volume1 != 0)) // play both 
      {
         kal_uint32 i, type;
         for(i = 0 ; i < AUD_MAX_VOLUME_LEVEL ; i ++)
         {              
            //  find the closest level 
            if(aud_get_volume_gain(VOL_NORMAL, AUD_VOLUME_MEDIA, i) > volume1)
               break;            
         }          
         if(i > 0) i--;
      #if defined(TV_OUT_SUPPORT)            
         if(audio_tv_cable_in)
            type = AUD_VOLUME_TVO;
         else 
      #endif    
            type = AUD_VOLUME_MEDIA;    
         afe.ext_dac_aud_vol = aud_get_volume_gain(VOL_HEADSET, type, i);         
      }
      else 
         afe.ext_dac_aud_vol = volume1;  
   }
   
   if(afe.ext_dac_i2s_on)
   { 
      if(((SND_SRC_MAP>>aud_func*2)&3) == SRC_AUDIO_DAC) 
      {            
         EXT_DAC_SetVolume(afe.aud[aud_func].out_dev & (L1SP_EXT_DAC_BUF0|L1SP_EXT_DAC_BUF1), afe.ext_dac_aud_vol);  
      }
   }
#endif
   
   AFE_SetRefresh();
   if(kal_if_hisr())
      kal_dev_trace(TRACE_STATE, AFE_SET_OUTPUT_VOLUME, aud_func, volume1, digital_gain_index);
   else
      kal_brief_trace(TRACE_STATE, AFE_SET_OUTPUT_VOLUME, aud_func, volume1, digital_gain_index);
}

#endif
/*****************************************************************************
* FUNCTION
*  AFE_SetLevelVolume
* DESCRIPTION
*   This function is to set the proper analog gain and digital gain 
*   based on a MaxAnalogGain and the desired (step * 0.5* level)dB attenuation. 
* 
* PARAMETERS
*  aud_func - the audio function
*  MaxAnalogGain - the maximum volume without any attenuation 
*  step - attenuation step quantity , 0.5dB unit   
*  level - the multiplier of attenuation step; 
*          so the total attenuation is (step * 0.5* level)dB  
*
* GLOBALS AFFECTED
*  None
*****************************************************************************/
#ifdef ANALOG_AFE_PATH_EXIST
void AFE_SetLevelVolume(kal_uint8 aud_func, kal_uint8 MaxAnalogGain, kal_uint8 step, kal_uint8 level)
{
   uint8 vol_step, vol_step_unit;
   uint8 a_gain, a_atten, d_atten;
   
   kal_trace(TRACE_STATE, AFE_SET_LEVEL_VOLUME, aud_func, MaxAnalogGain, step, level);
#if defined(EXT_DAC_SUPPORT)  
   {
      uint8 out_dev;
      out_dev = afe.aud[aud_func].out_dev; 
      // Note : extrenal DAC is used as earphone or TV-out only 
      // case 1 : play amr with melody volume (7-level case)  
      if(aud_func == L1SP_VOICE && (out_dev & (L1SP_EXT_DAC_BUF0|L1SP_EXT_DAC_BUF1)))
      {
         if(!(out_dev & L1SP_BUFFER_EXT)) // for play both case : apply AFE gain is OK 
         {
            // use AFE gain 
            aud_get_melody_volume_setting(VOL_NORMAL, &MaxAnalogGain, &step);
         }
      }
      
      // case 2 : play Audio both on earphone and LoudSpk 
      if(aud_func == L1SP_AUDIO && (out_dev & (L1SP_EXT_DAC_BUF0|L1SP_EXT_DAC_BUF1)))
      {
         uint8 ext_dac_max_vol, ext_dac_step;
         if(afe.aud[L1SP_AUDIO].out_dev & L1SP_BUFFER_EXT) // play both 
         {
         #if defined(TV_OUT_SUPPORT)
            if(audio_tv_cable_in)
               aud_get_melody_volume_setting(VOL_TV_OUT, &ext_dac_max_vol, &ext_dac_step);
            else 
         #endif    
               aud_get_melody_volume_setting(VOL_HEADSET,&ext_dac_max_vol, &ext_dac_step);
         }
         else 
         {
            ext_dac_max_vol = MaxAnalogGain;  
            ext_dac_step = step;
         }
         a_gain = ext_dac_max_vol / L1SP_EXT_DAC_STEP;

         a_atten = (ext_dac_step * level) / L1SP_EXT_DAC_STEP_UNIT; 
         d_atten = (ext_dac_step * level) % L1SP_EXT_DAC_STEP_UNIT; 
         ASSERT(d_atten == 0); // For current EXT_DAC interface, this must be 0.
         
         if(a_gain >= a_atten)  
            a_gain -= a_atten;
         else 
         {
            a_atten -= a_gain;
            a_gain = 0;
            d_atten += a_atten * L1SP_EXT_DAC_STEP_UNIT;
            if(d_atten > 128)
               d_atten = 128;
         }
         afe.ext_dac_aud_vol = a_gain * L1SP_EXT_DAC_STEP;  

         if(afe.ext_dac_i2s_on)                        
            EXT_DAC_SetVolume(out_dev & (L1SP_EXT_DAC_BUF0|L1SP_EXT_DAC_BUF1), afe.ext_dac_aud_vol);
      }
   }
#endif 


   vol_step = 4;   
   vol_step_unit = 2; // 1dB = 2 * 0.5dB
   
   a_gain = MaxAnalogGain / vol_step;

   a_atten = (step * level) / vol_step_unit; 
   d_atten = (step * level) % vol_step_unit; 

   if(a_gain >= a_atten)  
      a_gain -= a_atten;
   else 
   {
      a_atten -= a_gain;
      a_gain = 0;
      d_atten += a_atten * vol_step_unit;
      if(d_atten > 128)
         d_atten = 128;
   }

   afe.aud[aud_func].volume = a_gain * vol_step + 1; // plus 1 to avoid volume == 0 (this will turn off speaker) 
   afe.aud[aud_func].digital_gain_index = 0 - d_atten; 
   afe.aud[aud_func].digital_gain = _converted_digital_gain( 0-d_atten);       

   //if( (afe.aud[aud_func].out_dev & (L1SP_BUFFER_0|L1SP_BUFFER_1)) || (afe.aud[aud_func].out_dev & (L1SP_BUFFER_ST|L1SP_BUFFER_EXT)) ) //Use digital gain to compesate the analog gain
   {
      kal_int8 digital_gain_index;
      kal_uint8 volume;

      volume = afe.aud[aud_func].volume;
      digital_gain_index = afe.aud[aud_func].digital_gain_index;
       
      if(volume<68) //lower bound is 68
      { 
         kal_int16 tmp_gain_index;
         tmp_gain_index = (kal_int16)digital_gain_index;
         tmp_gain_index -= (((68-volume)>>2)<<1);
   
         if(tmp_gain_index>-128)
            digital_gain_index = (kal_int8)tmp_gain_index;
         else
            digital_gain_index = -128;
   
         afe.aud[aud_func].volume = volume;
         afe.aud[aud_func].digital_gain_index = digital_gain_index;
         afe.aud[aud_func].digital_gain = _converted_digital_gain(digital_gain_index);
       }
   }

   AFE_SetRefresh();
}  
#else


#endif //ANALOG_AFE_PATH_EXIST
//=============================================================================================
//                  Section: [AFE Feature] ABB Registers Backup/Store (for 65nm projects)
//=============================================================================================

void _AfeRegisterBackupByChip(void)
{
#if __RELOAD_HW_COEFF__
   
#endif
}

void _AfeRegisterStoreByChip(void)
{
#if __RELOAD_HW_COEFF__
   
#endif
}

//=============================================================================================
//                  VAPDN Related
//=============================================================================================

void AFE_SetRefVol(kal_bool fgEnable)
{
   // Both AFE_Event_Handler & AFE Manager will call this function, 
   // so need to add critical section protection
}

//=============================================================================================
//                  Chip Specific AFE Init
//=============================================================================================
void AFE_Chip_Init( void )
{  
	// [Tips] The following sherif is used under SW sidetone only. 
	// It will initial value is zero when DSP chip init, so we don't need to clean it. 
   //*DP_SIDETONE_VOL  = 0;
   
#ifdef ANALOG_AFE_PATH_EXIST	
   AM_DSP_SetSpeechUplinkDigitalGain(DG_Microphone); // *DP_VOL_IN_PCM    = DG_Microphone;	
   AM_DSP_SetSpeechDigitalGain(DG_DL_Speech); //*DP_VOL_OUT_PCM   = DG_DL_Speech;
   AM_DSP_SetAudioDigitalGain(DG_DAF); // *DP_DigiGain_Setting = DG_DAF;;
#endif

   *AFE_VMCU_CON      = 0;
   *AFE_AMCU_CON0     = 0;

   *AFE_AMCU_CON1     = 0;
   
   *AFE_VDB_CON       = 0xC018;  
   *AFE_VLB_CON       &= ~0xF7;
   /* set EQ cofficient*/
   AFE_Initialize();         // Set AFE_VAC_CON0::VCALI (chip dependent) and AFE_VMCU_CON1
   AFE_SetRefVol(KAL_TRUE);
   
   *AFE_VMCU_CON1 = 0x8000;
   // *DSP_AGC_CTRL    = 0xB82A;
   
}

/* ========================================================================= */
/*   AFE Chip Event Handler                                                  */
/*   This function runs under the context of L1Audio Task                    */
/* ========================================================================= */
void AFE_Chip_Event_Handler( void *data )
{
	kal_int16 v_lowest, a_lowest;

#if ( defined( __CENTRALIZED_SLEEP_MANAGER__ )&& defined( MTK_SLEEP_ENABLE ))
	//Be careful.Before Locking SleepMode, to access DSP sherrif tasks much time. So access DSP must be after SetFlag
	// because the event will happen whenever AP call related function 
	L1Audio_SetFlag( afe.aud_id );
#endif 

	SearchPathWorkingFlag(&v_lowest, &a_lowest);
	_digitOnly_update_digital_gain(v_lowest, a_lowest);

	// mic digital gain related
	/* no hw mute exit, so remove it
	if(afe.mic_mute){
		// AM_DSP_SetSpeechUplinkSwAgcGain(); AM_DSP_SetSpeechUplinkDigitalGain(0);
	}else {
	*/
	if(AM_IsBluetoothOn()) { // for the case of bluetooth use
		AM_DSP_SetSpeechUplinkSwAgcGain(0); // make agc gain as 0 under bt mode
	} else {
		AM_DSP_SetSpeechUplinkSwAgcGain(afe.digitOnly_mic_volume);
	}
	/*
	}
	*/

#if ( defined( __CENTRALIZED_SLEEP_MANAGER__ )&& defined( MTK_SLEEP_ENABLE ))
	L1Audio_ClearFlag( afe.aud_id );
#endif

}

/*
============================================================================================================
------------------------------------------------------------------------------------------------------------
||                        AFE Manager 
------------------------------------------------------------------------------------------------------------
============================================================================================================
*/
/* ========================================================================= */
/*   AFE Manager                                                             */
/*   This function runs under the context of L1 ISR                          */
/* ========================================================================= */
void AFE_Manager( void )
{   
   DelayCmd dc;
   if( afe.ext_op_delay != 0 ) {
      if( afe.ext_op_delay > 0 ) {
         if( --afe.ext_op_delay == 0 ) {
            AFE_SwitchExtAmplifier( true );
            afe.ext_op_on = KAL_TRUE;
         }
      }
      else { /* afe.ext_op_delay < 0 */
         if( ++afe.ext_op_delay == 0 ) {
            AFE_SwitchExtAmplifier( false );
            afe.ext_op_on = KAL_FALSE;
         }
      }
   }
   
   if( !RB_EMPTY( afe.regq ) ) {
      RB_GET( afe.regq, dc );
      *dc.addr = dc.val;
   }

   if( afe.refresh )
   {
      afe.refresh = KAL_FALSE;
      L1Audio_LSetEvent(afe.aud_id, NULL);
   }
   /*
   if(afe.v8k_off_request)
   {
      *MD2GSYS_CG_SET2 = PDN_CON2_VAFE;
      *AFE_VMCU_CON  &= ~0x0001;
      afe.v8k_off_request = KAL_FALSE;
		L1Audio_Msg_AFE_Switch( L1AUDIO_Str_onoff(0), AFE_Switch_Name(0) );
   }
   */
   if(afe.aClk_off_request)
   {
      *MD2GSYS_CG_SET2 = PDN_CON2_AAFE;
      *AFE_AMCU_CON0  &= ~0x0001;
      afe.aClk_off_request = KAL_FALSE;
   }
}

/*
============================================================================================================
------------------------------------------------------------------------------------------------------------
||                        AFE Feature or Chip Sepcific Functions
------------------------------------------------------------------------------------------------------------
============================================================================================================
*/
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

/**
	@return: 0 == narrow band, 4k mode; 1 == wide band, 8k mode;
*/
kal_uint8 AFE_GetVoice8KMode(void)
{
	return afe.voice8kMode;
}


/**
	@mode: 0 == narrow band, 4k mode; 1 == wide band, 8k mode;
*/
void AFE_SetVoice8KMode(kal_uint8 mode)
{
   afe.voice8kMode = mode;
}

#endif //#if defined(MT6582)
