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
 * sp_enhance.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   speech enhancement functions (moved from am.c)  
 *
 * Author:
 * -------
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#include "kal_public_api.h"
#include "reg_base.h"

#include "l1audio.h"

#include "kal_trace.h"
#include "l1sp_trc.h"

//#include "speech_def.h"
#include "am.h"
#include "media.h"
//#include "afe.h"


#ifdef __TWOMICNR_SUPPORT__
#include "two_mic_NR_custom_if.h" 
#endif

#include "sal_def.h"
#include "sal_exp.h"

#if defined(__HQA_AUDIO__) && !(__HQA_AUDIO_SPEECH_ENHANCEMENT_COMMON__)
const unsigned short Speech_Common_Para[12] = 
{ 
     0,     0,     0,     0,    1,     0,     0,     0,     0,     0, 
     0,     0 
};
#else
#if defined(MT6280)
const unsigned short Speech_Common_Para[12] = 
{ 
     0,     0, 31000, 10752, 32769,     0,     0,     0,     0,     0, 
     0,     0 
};
#elif defined(MT6589) || defined(MT6572) || defined(MT6582) || defined(MT6592) || defined(MT6571)|| defined(MT6580)
const unsigned short Speech_Common_Para[12] = 
{ 
     0, 55997, 31000, 10752, 32769,     0,     0,     0,     0,     0, 
     0,     0 
};
#else
const unsigned short Speech_Common_Para[12] = 
{ 
     0, 55997, 31000, 10752,     0,     0,     0,     0,     0,     0, 
     0,     0 
};
#endif
#endif



/* ========================================================================= */


/* ========================================================================= */
/*   EC/AEC/EES control Functions                                            */
/* ========================================================================= */
#define  FLAG_EC_SUPP         1
#define  FLAG_DDL_UL_ENTRY    2
#define  FLAG_DDL_DL_ENTRY    4

#define  SPE_IDLE_STATE       0  /* MCU: 0 -> 1 */ 
#define  SPE_READY_STATE      1  /* DSP: 1 -> 2 */    
#define  SPE_WORKING_STATE    2  /* MCU: 2 -> 3 */ 
#define  SPE_STOP_STATE       3  /* DSP: 3 -> 0 */  


#define _wait_for_ready_( enh_mod )  \
{  \
   uint32 I;  \
   for( I = 0; ; I++ ) {  \
      if( SAL_ENH_IsReady(enh_mod))  \
         break;  \
      ASSERT_REBOOT( I < 20 );  \
      kal_sleep_task( 2 );  \
   }  \
}

#define _wait_for_idle_( enh_mod )  \
{  \
   uint32 I;  \
   for( I = 0; ; I++ ) {  \
      if( SAL_ENH_IsIdle(enh_mod))  \
         break;  \
      ASSERT_REBOOT( I < 20 );  \
      kal_sleep_task( 2 );  \
   }  \
}

#define SPE_INTERNALPAR_INDEX_AGC   0 
#define SPE_INTERNALPAR_INDEX_MAX   SAL_PARAMETERLEN_INTERNAL  // 16

#define _write_enh_internalPar_( enhIndex, value )  \
{  \
   volatile uint16 *addr;  \
   addr = SAL_ENH_GetInternalParAddr(); \
   *(addr+enhIndex) = value; \
}

extern kal_bool setCommonPara;
extern uint16 commonPara_0;

void SPE_LoadSpeechPara( uint16 c_para[NUM_COMMON_PARAS], uint16 m_para[NUM_MODE_PARAS],uint16 v_para[NUM_VOL_PARAS],
	uint16 m_paraWb[NUM_MODE_PARAS])
{
   uint16 *para;
   volatile uint16* dsp_ptr;
   int I;

   if(c_para)
   {
      para = c_para;      
      dsp_ptr = SAL_CommonPar_GetBuf();
      for(I = SAL_PARAMETERLEN_COMMON; --I >= 0 ; )
         *dsp_ptr++ = *para++;
   }

   if(setCommonPara)
   {
      dsp_ptr = SAL_CommonPar_GetBuf();
      *dsp_ptr = commonPara_0;
   } 

   if(m_para)
   {
      para = m_para;      
      dsp_ptr = SAL_ModePar_GetBuf_NB();       
      for(I = SAL_PARAMETERLEN_MODE_NB; --I >= 0 ; )
         *dsp_ptr++ = *para++; 


   }
	
#if defined(__AMRWB_LINK_SUPPORT__)
	if(m_paraWb)
	{
		para = m_paraWb;      
      dsp_ptr = SAL_ModePar_GetBuf_WB();       
      for(I = SAL_PARAMETERLEN_MODE_WB; --I >= 0 ; )
         *dsp_ptr++ = *para++; 

	}
#endif		

}


/**
	The whole function is workable when "defined(__DUAL_MIC_SUPPORT__)"
*/
void SPE_LoadDmnrCoeffs(kal_int16 dmnr_para[NUM_DMNR_PARAM])
{
#if defined(__DUAL_MIC_SUPPORT__) || defined(__SMART_PHONE_MODEM__)	

	int i;
	volatile uint16* dsp_ptr;

	dsp_ptr = SAL_DMNR_GetFltCoefAddr_NB();


	for( i = 0; i<SAL_FLTCOEFLEN_DMNR_NB; i++) {
		*dsp_ptr++ = dmnr_para[i];
	}
	
	//*DP_DMNR_CONTROL |= 0x0020; //bit5 of NB

#endif //__DUAL_MIC_SUPPORT__ || defined(__SMART_PHONE_MODEM__)	
}


/**
	The whole function is workable when "defined(__DUAL_MIC_SUPPORT__) &&  defined(__AMRWB_LINK_SUPPORT__)"
*/
void SPE_LoadWbDmnrCoeffs(kal_int16 wb_dmnr_para[NUM_WB_DMNR_PARAM])
{
#if (defined(__DUAL_MIC_SUPPORT__) || defined(__SMART_PHONE_MODEM__)	) &&  defined(__AMRWB_LINK_SUPPORT__)

	int i;
	volatile uint16* dsp_ptr;
		
	dsp_ptr = SAL_DMNR_GetFltCoefAddr_WB();
	
	for( i = 0; i<SAL_FLTCOEFLEN_DMNR_WB; i++) {
		*dsp_ptr++ = wb_dmnr_para[i];
	}

	//*DP_DMNR_CONTROL |= 0x0040; //bit5 of WB
	
#endif //(__DUAL_MIC_SUPPORT__|| defined(__SMART_PHONE_MODEM__)	) &&  __AMRWB_LINK_SUPPORT__
}

/* ========================================================================= */
typedef struct 
{
	uint16 delayAndSwitch4Dsp;
	
	// NXP related inforamtion.
	uint16    nxpPaMicIndex; 	
	bool     isNxpPaOn;
	
	
} _SPE_AGC_INFO_T;

static _SPE_AGC_INFO_T speAgcInfo;

void SPE_SetAgcInfo(bool isNxpOn, uint16 nxpPaMicIndex, uint16 delayAndSwitch4Dsp)
{
	speAgcInfo.isNxpPaOn = isNxpOn;
	speAgcInfo.nxpPaMicIndex = nxpPaMicIndex;
	speAgcInfo.delayAndSwitch4Dsp = delayAndSwitch4Dsp;
}

bool SPE_AgcInfo_IsNxpPaOn(void)
{
	return speAgcInfo.isNxpPaOn;
}

void spe_AGC_config(bool isOn, bool isEchoRefOn)
{
	
	Sal_AGC_Config_t cfg;
	memset(&cfg, 0, sizeof(Sal_AGC_Config_t));

	kal_trace(TRACE_INFO, SPE_AGC_CONFIG_INFO, isOn, AM_DSP_GetSpeechUplinkDigitalGain(), 
		speAgcInfo.isNxpPaOn, speAgcInfo.nxpPaMicIndex, speAgcInfo.delayAndSwitch4Dsp,
		isEchoRefOn);
	
	if(isOn) { // turn on 
		_write_enh_internalPar_(SPE_INTERNALPAR_INDEX_AGC, speAgcInfo.delayAndSwitch4Dsp)
		
		cfg.main_switch = true;
		cfg.gain_switch = true;
		cfg.hpiir_switch = true;
		cfg.vad_switch = true;
		cfg.init_req = true;

		cfg.cosim = false;
		
		SAL_AGC1_Config(&cfg);
		SAL_AGC2_Config(&cfg);
		SAL_AGC3_Config(&cfg);
		SAL_AGC4_Config(&cfg);
		
		if(speAgcInfo.isNxpPaOn && isEchoRefOn){
			cfg.main_switch = false;
			cfg.gain_switch = false;
			cfg.hpiir_switch = false;
			cfg.vad_switch = false;
			cfg.init_req = false;

			cfg.cosim = false;

			switch(speAgcInfo.nxpPaMicIndex){
				case 0x1: 
					SAL_AGC1_Config(&cfg);
					break;
				case 0x2:
					SAL_AGC2_Config(&cfg);
					break;					
				case 0x4:
					SAL_AGC3_Config(&cfg);
					break;					
				case 0x8:
					SAL_AGC4_Config(&cfg);
					break;
				default:
					
					ASSERT(0);
			}
			
		}
	} else { // turn off
		
		cfg.main_switch = false;
		cfg.gain_switch = false;
		cfg.hpiir_switch = false;
		cfg.vad_switch = false;
		cfg.init_req = false;

		cfg.cosim = false;
		
		SAL_AGC1_Config(&cfg);
		SAL_AGC2_Config(&cfg);
		SAL_AGC3_Config(&cfg);
		SAL_AGC4_Config(&cfg);
	}
}

/* ========================================================================= */
extern const unsigned short Speech_Normal_Mode_Para[16];
#ifdef __AMRWB_LINK_SUPPORT__
extern const unsigned short WB_Speech_Normal_Mode_Para[16];
#endif 

extern const unsigned short Speech_Vol_Para[4];

void SPE_Init( void )
{

	// init the AGC as off in every channal
	_write_enh_internalPar_(SPE_INTERNALPAR_INDEX_AGC, 0)
	spe_AGC_config(false, false); 
	
#ifdef __AMRWB_LINK_SUPPORT__
	SPE_LoadSpeechPara((uint16 *)Speech_Common_Para, (uint16 *)Speech_Normal_Mode_Para, (uint16 *)Speech_Vol_Para, (uint16 *)WB_Speech_Normal_Mode_Para );
#else
   SPE_LoadSpeechPara((uint16 *)Speech_Common_Para, (uint16 *)Speech_Normal_Mode_Para, (uint16 *)Speech_Vol_Para, NULL );
#endif
}

void SPE_TurnOnProcess(uint16 on_state)
{
	kal_trace( TRACE_INFO, L1SP_ENHANCE_ON_OFF, 1, on_state);

	
	if(on_state & (SPE_AGC_FLAG)){ 
		// [REMIND], DMNR Calibration need AGC. When following setting modify, please don't forget the code in am.c
		spe_AGC_config(true, 0!=(on_state & SPH_ENH_MASK_ECHO_REF));
	}

   if(on_state & (SPE_AEC_FLAG + SPE_EES_FLAG + SPE_UL_NR_FLAG))
   	  SAL_ENH_SetULPath(true);
   
   if(on_state & (SPE_DL_NR_FLAG + SPE_AEC_FLAG))
   	 SAL_ENH_SetDLPath(true);


   if(on_state & SPE_UL_NR_FLAG)
   		SAL_ENH_SetInit(SAL_ENH_NR_UL);
   if(on_state & SPE_DL_NR_FLAG)
   		SAL_ENH_SetInit(SAL_ENH_NR_DL);

#if defined(__DUAL_MIC_SUPPORT__) || defined(__SMART_PHONE_MODEM__)	
	//REMIND: DMNR should enable before AEC, because it's part of AEC, 
	//AEC will do DMNR initialization when DMNR control is set	
	//DMNR will run, base on AEC is running!!!
	if(on_state & SPE_DMNR_FLAG){ 
		SAL_ENH_SetInit(SAL_ENH_DMNR);
	}
#endif

   if(on_state & ( SPE_AEC_FLAG + SPE_EES_FLAG))
   {
      switch(on_state & ( SPE_AEC_FLAG + SPE_EES_FLAG))
      {
         case SPE_AEC_FLAG:          
		 	SAL_ENH_SetInit(SAL_ENH_AEC);
            _wait_for_ready_(SAL_ENH_AEC);
            break;
         case SPE_EES_FLAG:          
		 	SAL_ENH_SetInit(SAL_ENH_AEC);
            _wait_for_ready_(SAL_ENH_AEC);
            break;
         // case SPE_ES_FLAG: 
         //   break;
         default: 
            ASSERT(false);    
      }   
   }

#if TDDNC_SUPPORT
   if(on_state & SPE_TDDNC_FLAG){
   	SAL_ENH_SetInit(SAL_ENH_TDNC);
    _wait_for_ready_(SAL_ENH_TDNC);
   }
#endif    
   
   if(on_state & SPE_UL_NR_FLAG)
   	_wait_for_ready_(SAL_ENH_NR_UL);
   if(on_state & SPE_DL_NR_FLAG)
   	_wait_for_ready_(SAL_ENH_NR_DL);

#if defined(__DUAL_MIC_SUPPORT__) || defined(__SMART_PHONE_MODEM__)	
	   //REMIND: DMNR depends on the running of AEC
	   if(on_state & SPE_DMNR_FLAG){ 
   	_wait_for_ready_(SAL_ENH_DMNR);
	   }
#endif
     
}


void SPE_TurnOffProcess(uint16 off_state)
{
   kal_trace( TRACE_INFO, L1SP_ENHANCE_ON_OFF, 0, off_state);
   if(off_state & SPE_UL_NR_FLAG)
   	SAL_ENH_SetOff(SAL_ENH_NR_UL);
   if(off_state & SPE_DL_NR_FLAG)
   	SAL_ENH_SetOff(SAL_ENH_NR_DL);

#if defined(__DUAL_MIC_SUPPORT__) || defined(__SMART_PHONE_MODEM__)	
	//REMIND: DMNR should disable before AEC, because it's part of AEC
	if(off_state & SPE_DMNR_FLAG){
	SAL_ENH_SetOff(SAL_ENH_DMNR);
	}
#endif

   if(off_state & (SPE_AEC_FLAG + SPE_EES_FLAG))
   { 
      switch(off_state & (SPE_AEC_FLAG + SPE_EES_FLAG))//MT6280, ES V.S. (EES V.S. AEC)
      {
         case SPE_AEC_FLAG:          
			SAL_ENH_SetOff(SAL_ENH_AEC);
			_wait_for_idle_(SAL_ENH_AEC);
            break;
         case SPE_EES_FLAG: 
			SAL_ENH_SetOff(SAL_ENH_AEC);
			_wait_for_idle_(SAL_ENH_AEC);
            break;
         // case SPE_ES_FLAG: 
         //    break;
         default: 
            ASSERT(false);    
      }
   }                      
       
#if TDDNC_SUPPORT
   if(off_state & SPE_TDDNC_FLAG){
	  SAL_ENH_SetOff(SAL_ENH_TDNC);
      _wait_for_idle_(SAL_ENH_TDNC);
   }
#endif 
                                             
   if(off_state & SPE_UL_NR_FLAG)
	_wait_for_idle_(SAL_ENH_NR_UL);
   if(off_state & SPE_DL_NR_FLAG)
	_wait_for_idle_(SAL_ENH_NR_DL);
   
#if defined(__DUAL_MIC_SUPPORT__) || defined(__SMART_PHONE_MODEM__)	
	//REMIND: DMNR should disable before AEC, because it's part of AEC
	if(off_state & SPE_DMNR_FLAG){
	_wait_for_idle_(SAL_ENH_DMNR);
	}
#endif


	if(off_state & SPE_AGC_FLAG){
		spe_AGC_config(false, false);
	}
	
}

void SPE_Clear_DLL_Entry(uint16 cur_state)
{
   if(!(cur_state & (SPE_AEC_FLAG + SPE_EES_FLAG + SPE_UL_NR_FLAG)))
   	SAL_ENH_SetULPath(false);
   
   if(!(cur_state & (SPE_DL_NR_FLAG + SPE_AEC_FLAG)))
   	SAL_ENH_SetDLPath(false);
}

