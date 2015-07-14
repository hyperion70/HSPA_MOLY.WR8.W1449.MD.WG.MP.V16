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
 * l1sp.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   L1SP Interface 
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
 *
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
#include "kal_trace.h"
#include "string.h"
#include "reg_base.h"
#include "custom_equipment.h" /* custom_cfg_audio_ec_range() */
#include "device.h" /* MAX_VOL_LEVEL,  in ps\l4\include */
#include "audcoeff_default.h"

#include "audio_def.h"
#include "l1audio.h"
#include "l1audio_trace.h"
#include "l1sp_trc.h"
#include "l1audio_sph_trc.h"
#include "ddload.h"
#include "media.h"
#include "afe.h"
#include "am.h"
#include "vm.h"
#include "sal_def.h"
#include "sal_exp.h"

#include "sp_drv.h"

#include "l4_ps_api.h" 

#if defined(__DATA_CARD_SPEECH__) || defined(__BT_SCO_CODEC_SUPPORT__)
#include "sp_daca.h"
#endif

#ifdef __TWOMICNR_SUPPORT__
#include "two_mic_NR_custom_if.h"
#endif

#if !defined(__SMART_PHONE_MODEM__)
#include "apAudSysConfig.h"
#else
#include "sidetone.h"
#endif

#if defined(__CVSD_CODEC_SUPPORT__) 
#include "bt_sco_drv.h"
#endif

#define __BT_SUPPORT__

/* ------------------------------------------------------------------------------ */
/*  Speech Interface                                                              */
/* ------------------------------------------------------------------------------ */

typedef enum{
	L1SP_NVRAM_VALUES_FLAG_MODE = 0x1,
	L1SP_NVRAM_VALUES_FLAG_IN_FIR = 0x2,
	L1SP_NVRAM_VALUES_FLAG_OUT_FIR = 0x4,
	L1SP_NVRAM_VALUES_FLAG_WB_MODE = 0x8,
	L1SP_NVRAM_VALUES_FLAG_WB_IN_FIR = 0x10,
	L1SP_NVRAM_VALUES_FLAG_WB_OUT_FIR = 0x20,
	//L1SP_NVRAM_VALUES_FLAG_RECORD_MODE = 0x40,
	//L1SP_NVRAM_VALUES_FLAG_RECORD_IN_FIR = 0x80,
	L1SP_NVRAM_VALUES_FLAG_VOLUME_PARAM = 0x100,
}L1SP_INTERNAL_NVRAM_VALUES_FLAG; // for NvramValuesFlag

#define TOTAL_NUM_SPH_MODE (NUM_SPH_MODE+1) // new 1 for HAC
#define TOTAL_NUM_SPH_INPUT_FIR (NUM_SPH_INPUT_FIR+1) // new 1 for HAC
#define TOTAL_NUM_SPH_OUTPUT_FIR (NUM_SPH_OUTPUT_FIR+1)  // new 1 for HAC
static struct {
   uint16   aud_id;
#if defined(__SMART_PHONE_MODEM__)   
   uint16   aud_id_network_status;
#endif   
   uint8    sph_mode;
   // uint8    sph_level; // phase out
   uint16   sph_c_para[NUM_COMMON_PARAS];
   uint16   sph_m_para[NUM_MODE_PARAS];
   uint16   sph_v_para[NUM_VOL_PARAS]; // useless, should fine time to remove it  
	uint16   sph_m_paraWb[NUM_MODE_PARAS];
#if defined(__DUAL_MIC_SUPPORT__) || defined(__SMART_PHONE_MODEM__)	
   int16    sph_dmnr_para[NUM_DMNR_PARAM];
#if defined(__AMRWB_LINK_SUPPORT__)
   int16    sph_wb_dmnr_para[NUM_WB_DMNR_PARAM];
#endif
	int16    sph_lspk_dmnr_para[NUM_DMNR_PARAM];
#if defined(__AMRWB_LINK_SUPPORT__)
   int16    sph_lspk_wb_dmnr_para[NUM_WB_DMNR_PARAM];
#endif
#endif    

   uint8    mic_volume; //  [analog+digital gain]value corrently set to DSP&HW; when ANALOG_AFE_PATH_EXIST is NOT defined, this is 0
#if 0   
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
   uint16   spe_state;
   uint16   spe_app_mask;   //record the usage every application should have. Ex. phonecall should be turned on DMNR. please do not update the mask directly, please use function l1sp_updateSpeAppMask() to update
   uint16   spe_usr_mask;   //record the usage user choose. Size is NUM_OF_SPH_FLAG. Please use function l1sp_updateSpeUsrMaskWithWholeValue() to update
   uint16   spe_usr_sub_mask; // record the usage of enhancement sub feature. Sync with Sal_Enh_Dynamic_t definition.  Ex. phonecall should be turned on DMNR, but users can decide whether turn on or not.please do not update the mask directly, please use function l1sp_updateUsrSubMask() to update 
   bool     spe_flag;   
   uint16   isULMute; // flag to keep the DSP UL MUTE states
   bool     isDLMute; // flag to keep the DSP DL MUTE states
   
   uint32     forcedUnmuteController;
   bool     isUlEnhResultMute;
	bool     isUlSourceMute;
   bool     codec_mute; 
   L1SP_L4C_Event_Mode   codec_mute_mode;
   bool     tch_state; // true: TCH on; false: TCH off
   // bool     pcmplayback_flag; // only used in META taste function. // phase out.
   uint8    state; // recording the network is 2G or 3G      
#if 0      
/* under construction !*/
#endif

//#if defined(__BT_SUPPORT__)
   bool     bt_on; // include DSP BT path setting and AFE path switch
//#endif
#if defined( __UMTS_RAT__ ) || defined( __UMTS_TDD128_MODE__ )
   bool     interRAT;
#endif

	bool     isEnableNotchFilter; 
	bool     is2In1Spk; // the variable only meaning for under isEnableNotchFilter==true. Ture for is 2-in-1 speaker; False for 3-in-1 speaker

#if 0	
/* under construction !*/
/* under construction !*/
#endif
	
	void (*bgsOnHandler)(void); 
   void (*bgsOffHandler)(void); 
#if defined(__DATA_CARD_SPEECH__)
   void (*strmOnHandler)(void *); 
   void (*strmOffHandler)(void *);
   void (*strmHdl)(kal_uint32 event, void *param);
#endif      
   //value from nvram 
   uint16   setNvramValuesFlag; //bit 0 for sph_allModePara, bit 1 for sph_allInFirCoeff, bit 2 for sph_allOutFirCoeff, 
                                //bit 3 for sph_allWbModePara, bit 4 for sph_allWbInFirCoeff, bit 5 for sph_allWbOutFirCoeff
                                //bit 6 for recordModePara, bit 7 for recordInFirCoeff
                                //bit 8 for sph_allVolumePara 
   
	uint16   sph_allModePara[TOTAL_NUM_SPH_MODE][NUM_MODE_PARAS];   
   int16    sph_allInFirCoeff[TOTAL_NUM_SPH_INPUT_FIR][NUM_FIR_COEFFS];
   int16    sph_allOutFirCoeff[TOTAL_NUM_SPH_OUTPUT_FIR][NUM_FIR_COEFFS];
   uint16 sph_allVolumePara[3][7][4];
   uint16 sph_selectedOutFirIndex;
   
#ifdef WB_SPE_SUPPORT
   uint16   sph_allWbModePara[TOTAL_NUM_SPH_MODE][NUM_MODE_PARAS];
   int16    sph_allWbInFirCoeff[TOTAL_NUM_SPH_INPUT_FIR][NUM_WB_FIR_COEFFS];
   int16    sph_allWbOutFirCoeff[TOTAL_NUM_SPH_OUTPUT_FIR][NUM_WB_FIR_COEFFS];
#endif // WB_SPE_SUPPORT	

#if defined(__ECALL_SUPPORT__)
   void (*pcm4wayOnHandler)(void *); 
   void (*pcm4wayOffHandler)(void *);
#endif
	bool     isHacModeNeeded; // if AP send Hac paramters and FIRs to MD, the flag will be set. 
} l1sp;
kal_enhmutexid sp_mutex;
// static kal_bool lineon_flag = KAL_FALSE;  // line in--> phase out


// Line in related. Phase out
//extern void AFE_SetGainFastRamp(kal_bool enable);

#if defined(__BT_SUPPORT__)
bool L1SP_IsBluetoothOn( void )
{
   return (l1sp.sph_mode==SPH_MODE_BT_CORDLESS || l1sp.sph_mode==SPH_MODE_BT_EARPHONE || 
      l1sp.sph_mode==SPH_MODE_BT_CARKIT || l1sp.sph_mode==SPH_MODE_LINEIN_VIA_BT_CORDLESS);
}
#endif

void L1SP_UpdateSpeechPara( uint16 sph_m_para[NUM_MODE_PARAS] )
{
   memcpy(l1sp.sph_m_para, sph_m_para, NUM_MODE_PARAS*sizeof(uint16));
}

#if ( defined( __CENTRALIZED_SLEEP_MANAGER__ )&& defined( MTK_SLEEP_ENABLE ))
static kal_uint16 L1SP_GetAudID(void)/*Be careful.Before Locking SleepMode, to access DSP sherrif tasks much time. So access DSP must be after SetFlag*/
{
   kal_uint16 aud_id;
   aud_id = L1Audio_GetAudioID();
   L1Audio_SetFlag( aud_id );
   return aud_id;
}
static void L1SP_FreeAudID(kal_uint16 aud_id)
{
   L1Audio_ClearFlag( aud_id );
   L1Audio_FreeAudioID( aud_id );
}
#endif
/*******************************************************************/
/*   The new interface for DSP speech enhancement function / Bluetooth */
/*******************************************************************/
#define USE_AEC defined(AEC_ENABLE)
#define USE_EES defined(EES_ENABLE)

uint16 spe_table[SPH_MODE_UNDEFINED] = {
#if defined(__HQA_AUDIO__) && !(__HQA_AUDIO_AEC_NR_DRC__)
   0, 0, 0, 0, 0, 0, 0, 0, 
#elif defined(MT6280) || defined(MT6589) || defined(MT6572) || defined(MT6582) || defined(MT6592) || defined(MT6571)|| defined(MT6580)
   #if TDDNC_SUPPORT
	  	#if defined(__DUAL_MIC_SUPPORT__) || defined(__SMART_PHONE_MODEM__)//in FD216, DMNR's running depends on AP control
		  /* SPH_MODE_NORMAL */    SPE_AEC_FLAG + SPE_UL_NR_FLAG + SPE_DL_NR_FLAG + SPE_DMNR_FLAG + SPE_AGC_FLAG + SPH_ENH_MASK_SIDETONE + SPH_ENH_MASK_NOTCH_FILTER,
		#else
	     /* SPH_MODE_NORMAL */    SPE_AEC_FLAG + SPE_UL_NR_FLAG + SPE_DL_NR_FLAG + SPE_TDDNC_FLAG + SPE_AGC_FLAG + SPH_ENH_MASK_SIDETONE + SPH_ENH_MASK_NOTCH_FILTER,
	   #endif
		
      #if defined(AEC_ENABLE)           
      /* SPH_MODE_EARPHONE */    SPE_AEC_FLAG + SPE_UL_NR_FLAG + SPE_DL_NR_FLAG + SPE_TDDNC_FLAG + SPE_AGC_FLAG + SPH_ENH_MASK_SIDETONE,
      #else 
      /* SPH_MODE_EARPHONE */    SPE_UL_NR_FLAG + SPE_DL_NR_FLAG + SPE_TDDNC_FLAG + SPH_ENH_MASK_SIDETONE,
      #endif  

#if SPE_LOUDSPK_DMNR // by chip patch 
      #if defined(__DUAL_MIC_SUPPORT__) || defined(__SMART_PHONE_MODEM__)
      /* SPH_MODE_LOUDSPK */     SPE_EES_FLAG + SPE_UL_NR_FLAG + SPE_DL_NR_FLAG + SPE_DMNR_FLAG + SPE_AGC_FLAG + SPH_ENH_MASK_NOTCH_FILTER, // TDDNC v.s. DMNR is excluded
      #else
      /* SPH_MODE_LOUDSPK */     SPE_EES_FLAG + SPE_UL_NR_FLAG + SPE_DL_NR_FLAG + SPE_TDDNC_FLAG + SPE_AGC_FLAG + SPH_ENH_MASK_NOTCH_FILTER, // TDDNC v.s. DMNR is excluded
		#endif
#else 
		/* SPH_MODE_LOUDSPK */     SPE_EES_FLAG + SPE_UL_NR_FLAG + SPE_DL_NR_FLAG + SPE_TDDNC_FLAG + SPE_AGC_FLAG + SPH_ENH_MASK_NOTCH_FILTER, // TDDNC v.s. DMNR is excluded
#endif
      
      #if defined(AEC_ENABLE) && defined(__BT_SUPPORT__)         
      /* SPH_MODE_BT_EARPHONE */ SPE_AEC_FLAG + SPE_UL_NR_FLAG + SPE_DL_NR_FLAG,
      #else 
      /* SPH_MODE_BT_EARPHONE */ SPE_UL_NR_FLAG + SPE_DL_NR_FLAG,
      #endif
		
      /* SPH_MODE_BT_CORDLESS */ 0,
      
      /* SPH_MODE_BT_CARKIT */   SPE_EES_FLAG + SPE_UL_NR_FLAG + SPE_DL_NR_FLAG,

      /* SPH_MODE_AUX1 */        SPE_EES_FLAG + SPE_UL_NR_FLAG + SPE_DL_NR_FLAG + SPE_TDDNC_FLAG + SPE_AGC_FLAG + SPH_ENH_MASK_NOTCH_FILTER,
      
      /* SPH_MODE_AUX2 */        0, 

		#if defined(__DUAL_MIC_SUPPORT__) || defined(__SMART_PHONE_MODEM__)//in FD216, DMNR's running depends on AP control
		  /* HAC */                 SPE_AEC_FLAG + SPE_UL_NR_FLAG + SPE_DL_NR_FLAG + SPE_DMNR_FLAG + SPE_AGC_FLAG + SPH_ENH_MASK_SIDETONE + SPH_ENH_MASK_NOTCH_FILTER,
		#else
		  /* HAC */                 SPE_AEC_FLAG + SPE_UL_NR_FLAG + SPE_DL_NR_FLAG + SPE_TDDNC_FLAG + SPE_AGC_FLAG + SPH_ENH_MASK_SIDETONE + SPH_ENH_MASK_NOTCH_FILTER,
	   #endif
   #else
	  	#if defined(__DUAL_MIC_SUPPORT__) || defined(__SMART_PHONE_MODEM__)
		/* SPH_MODE_NORMAL */      SPE_AEC_FLAG + SPE_UL_NR_FLAG + SPE_DL_NR_FLAG + SPE_DMNR_FLAG + SPE_AGC_FLAG + SPH_ENH_MASK_SIDETONE + SPH_ENH_MASK_NOTCH_FILTER,
		#else
      /* SPH_MODE_NORMAL */      SPE_AEC_FLAG + SPE_UL_NR_FLAG + SPE_DL_NR_FLAG + SPE_AGC_FLAG + SPH_ENH_MASK_SIDETONE + SPH_ENH_MASK_NOTCH_FILTER,
      #endif
		
      #if defined(AEC_ENABLE)           
      /* SPH_MODE_EARPHONE */    SPE_AEC_FLAG + SPE_UL_NR_FLAG + SPE_DL_NR_FLAG + SPE_AGC_FLAG + SPH_ENH_MASK_SIDETONE,
      #else 
      /* SPH_MODE_EARPHONE */    SPE_UL_NR_FLAG + SPE_DL_NR_FLAG + SPE_AGC_FLAG + SPH_ENH_MASK_SIDETONE,
      #endif  
		
		  
		  #if SPE_LOUDSPK_DMNR // by chip patch 
            #if defined(__DUAL_MIC_SUPPORT__) || defined(__SMART_PHONE_MODEM__)
            /* SPH_MODE_LOUDSPK */     SPE_EES_FLAG + SPE_UL_NR_FLAG + SPE_DL_NR_FLAG + SPE_DMNR_FLAG + SPE_AGC_FLAG + SPH_ENH_MASK_NOTCH_FILTER, 
            #else
            /* SPH_MODE_LOUDSPK */     SPE_EES_FLAG + SPE_UL_NR_FLAG + SPE_DL_NR_FLAG + SPE_AGC_FLAG + SPH_ENH_MASK_NOTCH_FILTER, 
      		  #endif
      #else 
      		  /* SPH_MODE_LOUDSPK */     SPE_EES_FLAG + SPE_UL_NR_FLAG + SPE_DL_NR_FLAG  + SPE_AGC_FLAG + SPH_ENH_MASK_NOTCH_FILTER, 
      #endif
      
      #if defined(AEC_ENABLE) && defined(__BT_SUPPORT__)         
      /* SPH_MODE_BT_EARPHONE */ SPE_AEC_FLAG + SPE_UL_NR_FLAG + SPE_DL_NR_FLAG,
      #else 
      /* SPH_MODE_BT_EARPHONE */ SPE_UL_NR_FLAG + SPE_DL_NR_FLAG,
      #endif
		
      /* SPH_MODE_BT_CORDLESS */ 0,
      
      /* SPH_MODE_BT_CARKIT */   SPE_EES_FLAG + SPE_UL_NR_FLAG + SPE_DL_NR_FLAG,

		/* SPH_MODE_AUX1 */        SPE_EES_FLAG + SPE_UL_NR_FLAG + SPE_DL_NR_FLAG + SPE_AGC_FLAG + SPH_ENH_MASK_NOTCH_FILTER,
   #endif
#endif
   /* Line-in Cordless */        0 
};   

typedef enum{
	L1SP_SPE_SUBMASK_BYMASK = 0,
	L1SP_SPE_SUBMASK_DONT_CARE_NO_STATE_MACHINE, // default true
	L1SP_SPE_SUBMASK_DONT_CARE_NO_EM_VALUE, // default true
	L1SP_SPE_SUBMASK_SKIP_DEFAULT_ON,
	L1SP_SPE_SUBMASK_SKIP,
}L1SP_SPE_SUBMASK_VALUES; // for NvramValuesFlag

L1SP_SPE_SUBMASK_VALUES spe_subMask_table[SPH_MODE_UNDEFINED][SAL_ENH_DYNAMIC_NUM] = {
	/* SPH_MODE_NORMAL */  
	{ L1SP_SPE_SUBMASK_SKIP, 
	  L1SP_SPE_SUBMASK_BYMASK, 
	  L1SP_SPE_SUBMASK_BYMASK, 
	  L1SP_SPE_SUBMASK_SKIP_DEFAULT_ON, 
	  L1SP_SPE_SUBMASK_SKIP_DEFAULT_ON, 
	  L1SP_SPE_SUBMASK_SKIP_DEFAULT_ON, 
	  L1SP_SPE_SUBMASK_DONT_CARE_NO_EM_VALUE,
	  L1SP_SPE_SUBMASK_BYMASK},
	/* SPH_MODE_EARPHONE */
	{ L1SP_SPE_SUBMASK_SKIP, 
	  L1SP_SPE_SUBMASK_DONT_CARE_NO_STATE_MACHINE, 
	  L1SP_SPE_SUBMASK_DONT_CARE_NO_EM_VALUE, 
	  L1SP_SPE_SUBMASK_SKIP_DEFAULT_ON, 
	  L1SP_SPE_SUBMASK_SKIP_DEFAULT_ON, 
	  L1SP_SPE_SUBMASK_SKIP_DEFAULT_ON,
	  L1SP_SPE_SUBMASK_DONT_CARE_NO_STATE_MACHINE,
	  L1SP_SPE_SUBMASK_BYMASK},
	/* SPH_MODE_LOUDSPK */
	{ L1SP_SPE_SUBMASK_SKIP, 
	  L1SP_SPE_SUBMASK_DONT_CARE_NO_EM_VALUE, 
	  L1SP_SPE_SUBMASK_DONT_CARE_NO_EM_VALUE, 
	  L1SP_SPE_SUBMASK_SKIP_DEFAULT_ON, 
	  L1SP_SPE_SUBMASK_SKIP_DEFAULT_ON, 
	  L1SP_SPE_SUBMASK_SKIP_DEFAULT_ON,
	  L1SP_SPE_SUBMASK_BYMASK,
	  L1SP_SPE_SUBMASK_BYMASK},
	/* SPH_MODE_BT_EARPHONE */
	{ L1SP_SPE_SUBMASK_SKIP, 
	  L1SP_SPE_SUBMASK_DONT_CARE_NO_STATE_MACHINE, 
	  L1SP_SPE_SUBMASK_DONT_CARE_NO_EM_VALUE, 
	  L1SP_SPE_SUBMASK_SKIP_DEFAULT_ON, 
	  L1SP_SPE_SUBMASK_SKIP_DEFAULT_ON, 
	  L1SP_SPE_SUBMASK_SKIP_DEFAULT_ON,
	  L1SP_SPE_SUBMASK_DONT_CARE_NO_STATE_MACHINE,
	  L1SP_SPE_SUBMASK_BYMASK},
	/* SPH_MODE_BT_CORDLESS */
	{ L1SP_SPE_SUBMASK_SKIP, 
	  L1SP_SPE_SUBMASK_DONT_CARE_NO_STATE_MACHINE, 
	  L1SP_SPE_SUBMASK_DONT_CARE_NO_EM_VALUE, 
	  L1SP_SPE_SUBMASK_SKIP_DEFAULT_ON, 
	  L1SP_SPE_SUBMASK_SKIP_DEFAULT_ON, 
	  L1SP_SPE_SUBMASK_SKIP_DEFAULT_ON,
	  L1SP_SPE_SUBMASK_DONT_CARE_NO_STATE_MACHINE,
	  L1SP_SPE_SUBMASK_BYMASK},
	/* SPH_MODE_BT_CARKIT */
	{ L1SP_SPE_SUBMASK_SKIP, 
	  L1SP_SPE_SUBMASK_DONT_CARE_NO_STATE_MACHINE, 
	  L1SP_SPE_SUBMASK_DONT_CARE_NO_EM_VALUE, 
	  L1SP_SPE_SUBMASK_SKIP_DEFAULT_ON, 
	  L1SP_SPE_SUBMASK_SKIP_DEFAULT_ON, 
	  L1SP_SPE_SUBMASK_SKIP_DEFAULT_ON,
	  L1SP_SPE_SUBMASK_DONT_CARE_NO_STATE_MACHINE,
	  L1SP_SPE_SUBMASK_BYMASK},
	/* SPH_MODE_AUX1 --> use for magic con-call*/ 
	{ L1SP_SPE_SUBMASK_SKIP, 
	  L1SP_SPE_SUBMASK_DONT_CARE_NO_STATE_MACHINE, 
	  L1SP_SPE_SUBMASK_DONT_CARE_NO_EM_VALUE, 
	  L1SP_SPE_SUBMASK_SKIP_DEFAULT_ON, 
	  L1SP_SPE_SUBMASK_SKIP_DEFAULT_ON, 
	  L1SP_SPE_SUBMASK_SKIP_DEFAULT_ON,
	  L1SP_SPE_SUBMASK_DONT_CARE_NO_STATE_MACHINE,
	  L1SP_SPE_SUBMASK_BYMASK},
	/* SPH_MODE_AUX2 */
	{ L1SP_SPE_SUBMASK_SKIP, 
	  L1SP_SPE_SUBMASK_DONT_CARE_NO_STATE_MACHINE, 
	  L1SP_SPE_SUBMASK_DONT_CARE_NO_STATE_MACHINE, 
	  L1SP_SPE_SUBMASK_DONT_CARE_NO_STATE_MACHINE, 
	  L1SP_SPE_SUBMASK_DONT_CARE_NO_STATE_MACHINE, 
	  L1SP_SPE_SUBMASK_DONT_CARE_NO_STATE_MACHINE,
	  L1SP_SPE_SUBMASK_DONT_CARE_NO_STATE_MACHINE},
	/* SPH_MODE_HAC like normal */  
	{ L1SP_SPE_SUBMASK_SKIP, 
	  L1SP_SPE_SUBMASK_BYMASK, 
	  L1SP_SPE_SUBMASK_BYMASK, 
	  L1SP_SPE_SUBMASK_SKIP_DEFAULT_ON, 
	  L1SP_SPE_SUBMASK_BYMASK, 
	  L1SP_SPE_SUBMASK_BYMASK, 
	  L1SP_SPE_SUBMASK_SKIP,
	  L1SP_SPE_SUBMASK_BYMASK,
	  L1SP_SPE_SUBMASK_SKIP,
	  L1SP_SPE_SUBMASK_BYMASK},
	/* LINEIN ?  */
	{ L1SP_SPE_SUBMASK_SKIP, 
	  L1SP_SPE_SUBMASK_DONT_CARE_NO_STATE_MACHINE, 
	  L1SP_SPE_SUBMASK_DONT_CARE_NO_EM_VALUE, 
	  L1SP_SPE_SUBMASK_SKIP_DEFAULT_ON, 
	  L1SP_SPE_SUBMASK_BYMASK, 
	  L1SP_SPE_SUBMASK_BYMASK,
	  L1SP_SPE_SUBMASK_SKIP,
	  L1SP_SPE_SUBMASK_BYMASK,
	  L1SP_SPE_SUBMASK_SKIP,
	  L1SP_SPE_SUBMASK_BYMASK}
	//
};

#if __RELOAD_DSP_COEFF__


void L1SP_Reload_SPE_Para( void )
{
   SPE_LoadSpeechPara(l1sp.sph_c_para, l1sp.sph_m_para, l1sp.sph_v_para, l1sp.sph_m_paraWb);
}
#endif

/* Phase out, 
void L1SP_Init_PCMPlayback(uint8 sph_mode, bool bDigitalGain, uint16 digital_gain)
{
	 unsigned short Speech_Normal_Mode_Para[16] = DEFAULT_SPEECH_NORMAL_MODE_PARA;
   unsigned short Speech_Earphone_Mode_Para[16] = DEFAULT_SPEECH_EARPHONE_MODE_PARA;
   unsigned short Speech_Loudspeaker_Mode_Para[16] = DEFAULT_SPEECH_LOUDSPK_MODE_PARA;
	 
	 switch(sph_mode) {
	 case SPH_MODE_NORMAL:
	     if(bDigitalGain == true) {
	        Speech_Normal_Mode_Para[7] = digital_gain;
	     }
	 	  L1SP_SetSpeechMode(SPH_MODE_NORMAL, Speech_Normal_Mode_Para);
	 		break;
	 case SPH_MODE_EARPHONE:
	     if(bDigitalGain == true) {
	        Speech_Earphone_Mode_Para[7] = digital_gain;
	     }
	 	  L1SP_SetSpeechMode(SPH_MODE_EARPHONE, Speech_Earphone_Mode_Para);
	 	  break;
	 case SPH_MODE_LOUDSPK: 
	     if(bDigitalGain == true) {
	        Speech_Loudspeaker_Mode_Para[7] = digital_gain;
	     }
	 	  L1SP_SetSpeechMode(SPH_MODE_LOUDSPK, Speech_Loudspeaker_Mode_Para);
	 	  break;
	 default:
	 	  break;
	 } 
}

void L1SP_EnableStrmPcmSPE(void)
{
	 l1sp.pcmplayback_flag = true;
}

void L1SP_DisableStrmPcmSPE(void)
{
	 l1sp.pcmplayback_flag = false;
}

bool L1SP_CheckStrmPcmSPE(void)
{
	 return l1sp.pcmplayback_flag;
}

*/

//--------------- New Modes ---------------------

void spe_setHacModeNeeded(bool isNeed)
{
	l1sp.isHacModeNeeded = isNeed;
}
uint16 l1sp_GetSpeState(void)
{
	return l1sp.spe_state;
}

void SetSpeechEnhancement( bool ec )
{

	//for data card, speech enhancment is not existing. 
#if defined(__DATA_CARD_SPEECH__) || defined(MT6280) 
   return; 
#endif // defined(__DATA_CARD_SPEECH__) || defined(MT6280)

#if defined(SPH_CHIP_BACK_PHONECALL_USED)
	return;
#endif // SPH_CHIP_BACK_PHONECALL_USED
   
   if ((!AM_IsAmInSpeechState()) || (!l1sp.spe_flag)) 
      return;
   ASSERT(l1sp.sph_mode<SPH_MODE_UNDEFINED);

   kal_trace( TRACE_INFO, L1SP_APPLY_MODE, (ec)?1:0, l1sp.sph_mode, -1, l1sp.mic_volume );
   if( ec ) {
      uint16 next_state, keep_on_state, on_state, off_state;  
		uint8 i;
		
		// Update Usr Sub Mask to DSP ENH Dynamic control, 
		// [Remind] ignore SAL_ENH_DYNAMIC_MUTE_UL, because DSP using same sherif to control
		for(i=SAL_ENH_DYNAMIC_DMNR_MUX; i<SAL_ENH_DYNAMIC_NUM ; i++){
			L1SP_SPE_SUBMASK_VALUES subMask = spe_subMask_table[l1sp.sph_mode][i]; 

			// bit wise update the sub mask (dynamic control for SPE)
			switch(subMask){
				case L1SP_SPE_SUBMASK_BYMASK:
					SAL_ENH_Dynamic_Ctrl(((l1sp.spe_usr_sub_mask & (1<<i))!=0), i);
					break; 
				case L1SP_SPE_SUBMASK_DONT_CARE_NO_STATE_MACHINE: // default true
				case L1SP_SPE_SUBMASK_DONT_CARE_NO_EM_VALUE:
				case L1SP_SPE_SUBMASK_SKIP_DEFAULT_ON:
					SAL_ENH_Dynamic_Ctrl(true, i);
					break;
				case L1SP_SPE_SUBMASK_SKIP:
					break;
			}
			kal_trace( TRACE_INFO, L1SP_SET_ENHANCEMENT_SUB_MASK, i, subMask);
			//SAL_ENH_Dynamic_Ctrl(((l1sp.spe_usr_sub_mask & (1<<i))!=0), i);
		}

	
      next_state = spe_table[l1sp.sph_mode];
	  // using l1sp.spe_mask to control the open/close of speech enhancment. 
      for(i=0; i< NUM_OF_SPH_FLAG; i++) {
	     uint16 tempMaskBit = (1<<i);
	     if((
	        ((l1sp.spe_app_mask & tempMaskBit) == 0 ) || 
	        ((l1sp.spe_usr_mask & tempMaskBit) == 0 ) 
	        )&& (next_state & tempMaskBit))
         {
            next_state -=tempMaskBit;
         }
	  }
	            
      switch( l1sp.sph_mode ) {
			case SPH_MODE_NORMAL:
				if(true == l1sp.isEnableNotchFilter){ // when ap turn ON notch filter
					if(true == l1sp.is2In1Spk) { // check speaker choise. 
						next_state &= (~SPH_ENH_MASK_NOTCH_FILTER);
					}
				}
			case SPH_MODE_LOUDSPK:
				if(false == l1sp.isEnableNotchFilter){ // when ap do NOT turn on notch filter under normal mode & loud speaker mode
					next_state &= (~SPH_ENH_MASK_NOTCH_FILTER);
				}
#if TDDNC_SUPPORT				
				if(0==(next_state&SPE_DMNR_FLAG)) { // when DMNR is off, use TDDNC
					next_state |= SPE_TDDNC_FLAG;
				}
#endif
				if(SPH_MODE_LOUDSPK == l1sp.sph_mode) {
					if(true == SPE_AgcInfo_IsNxpPaOn()) {
						next_state |= SPH_ENH_MASK_ECHO_REF; 
					}
				}
				break;

      #if defined(__BT_SUPPORT__)      // DSP_BT_SUPPORT
         case SPH_MODE_BT_EARPHONE:
         case SPH_MODE_BT_CORDLESS:
         case SPH_MODE_BT_CARKIT:
            ASSERT( AM_IsBluetoothOn() );
            break;
      #endif       
         default:
            break;         	
      }

		// dynamic download when turn on speech enhancement
		if(0 == l1sp.spe_state){
	 
#if defined(AEC_ENABLE) || defined(EES_ENABLE)
#if defined(SPH_CHIP_BACK_PHONECALL_USED) || defined(MT6280)
			// do not download speech enhancment
#else 

#if DSP_DYNAMDOWNLOAD_TDNC_DMNR_EXOR
      if(next_state&SPE_DMNR_FLAG)
      {  // DMNR
      	 if(l1sp.sph_mode == SPH_MODE_LOUDSPK)
      	 {
				    DSP_DynamicDownload( DDID_SPH_TCH_2 );   
			   } 
			   else 
			   {
				   DSP_DynamicDownload( DDID_SPH_TCH_1 );   
			   }      	 	 
      }
      else //  TDDNC
      {
         DSP_DynamicDownload( DDID_SPH_TCH_3 );       	 
      }

#elif SPE_LOUDSPK_DMNR
			if(l1sp.sph_mode == SPH_MODE_LOUDSPK){
				DSP_DynamicDownload( DDID_SPH_TCH_2 );   
			} else {
				DSP_DynamicDownload( DDID_SPH_TCH_1 );   
			}
#else
			DSP_DynamicDownload( DDID_NOISE_REDUCTION );   
#endif
#endif
#endif
		}

      keep_on_state = next_state & l1sp.spe_state; 
      on_state = next_state - keep_on_state; 
      off_state = l1sp.spe_state - keep_on_state;

      kal_trace( TRACE_INFO, L1SP_SET_ENHANCEMENT, keep_on_state, on_state, off_state);
   
      if(off_state != 0) 
         SPE_TurnOffProcess(off_state);   

    
      if(next_state != 0)
      {
         kal_trace( TRACE_INFO, L1SP_SPEECH_ENHANCEMENT, next_state,
            l1sp.sph_m_para[0], l1sp.sph_m_para[1], l1sp.sph_c_para[0], l1sp.sph_c_para[1] );

			// reload the parameters
         if(next_state & (SPE_AEC_FLAG + SPE_EES_FLAG + SPE_UL_NR_FLAG + SPE_DL_NR_FLAG + SPE_TDDNC_FLAG))
            SPE_LoadSpeechPara(l1sp.sph_c_para, l1sp.sph_m_para, l1sp.sph_v_para, l1sp.sph_m_paraWb);

#if defined(__DUAL_MIC_SUPPORT__) || defined(__SMART_PHONE_MODEM__)	
			if(next_state & SPE_DMNR_FLAG)
			{
				if(SPH_MODE_LOUDSPK == l1sp.sph_mode) { // load the loud speaker mode DMNR parameter
					SPE_LoadDmnrCoeffs(l1sp.sph_lspk_dmnr_para);
#if defined(__AMRWB_LINK_SUPPORT__)
					SPE_LoadWbDmnrCoeffs(l1sp.sph_lspk_wb_dmnr_para);
#endif //__AMRWB_LINK_SUPPORT__

				} else {				
			 		SPE_LoadDmnrCoeffs(l1sp.sph_dmnr_para);	
#if defined(__AMRWB_LINK_SUPPORT__)
					SPE_LoadWbDmnrCoeffs(l1sp.sph_wb_dmnr_para);
#endif //__AMRWB_LINK_SUPPORT__
				}

		 	}
#endif //__DUAL_MIC_SUPPORT__ || defined(__SMART_PHONE_MODEM__)	

         if(on_state != 0) 
            SPE_TurnOnProcess(on_state);

#if defined(__SMART_PHONE_MODEM__) // using software sidetone
			if(SPH_ENH_MASK_SIDETONE & on_state) {
				SIDETONE_TurnSwSidetoneOn(true);
			}
#endif // !defined(SMART_PHONE_HW_SIDETONE_SUPPORT)

			// notch filter for 3-in 1 speaker
			if( SPH_ENH_MASK_NOTCH_FILTER& on_state ) {
				//reload the coefficient
				AM_DSP_WriteNotchFilterParam();
				
				// turn on 
				SAL_NotchFilter_Enable(true , false);
			}
			
      }
      l1sp.spe_state = next_state;
      SPE_Clear_DLL_Entry(l1sp.spe_state);
   }
   else {
      if(l1sp.spe_state != 0)
      {
         SPE_TurnOffProcess(l1sp.spe_state);  

#if defined(__SMART_PHONE_MODEM__) // using software sidetone			
			if(SPH_ENH_MASK_SIDETONE & l1sp.spe_state) {
				SIDETONE_TurnSwSidetoneOn(false);
			}
#endif // !defined(SMART_PHONE_HW_SIDETONE_SUPPORT)		

			if(SPH_ENH_MASK_NOTCH_FILTER& l1sp.spe_state) {
				// turn off 
				SAL_NotchFilter_Enable(false , false);
			}
			
         l1sp.spe_state = 0;
         SPE_Clear_DLL_Entry(0);
      }
#ifdef __TWOMICNR_SUPPORT__
      if ( l1sp.sph_mode == SPH_MODE_LOUDSPK || l1sp.sph_mode == SPH_MODE_NORMAL )
      {
         Two_Mic_NR_chip_Sleep();
         kal_trace(TRACE_STATE, L1SP_2MIC_SLEEP);
      }
      else{
         Two_Mic_NR_chip_exit_Bypass_mode();
         kal_trace(TRACE_STATE, L1SP_2MIC_EXIT_BYPASS);
      }
#endif
#if defined(__TC01_VOICE_ENGINE__)
      VC_Stop();
      VS_Stop();
#endif
   }

#if 0
/* under construction !*/
/* under construction !*/
#if !USE_AEC
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
#endif	
}

void L1SP_LoadCommonSpeechPara( uint16 c_para[NUM_COMMON_PARAS] )
{
#if ( defined( __CENTRALIZED_SLEEP_MANAGER__ )&& defined( MTK_SLEEP_ENABLE ))
   kal_uint16 aud_id = L1SP_GetAudID();
#endif    
   memcpy(l1sp.sph_c_para, c_para, NUM_COMMON_PARAS*sizeof(uint16));
   SetSpeechEnhancement( true );
   
   // Some common parameters are used in non-speech function
   // Force to load common parameter
   SPE_LoadSpeechPara(l1sp.sph_c_para, NULL, NULL, NULL);
	
#if ( defined( __CENTRALIZED_SLEEP_MANAGER__ )&& defined( MTK_SLEEP_ENABLE ))
   L1SP_FreeAudID(aud_id);
#endif
}
void l1sp_setAllSpeechModePara(uint16 * speech_mode_para, int16 length)
{
	ASSERT((NUM_SPH_MODE*NUM_MODE_PARAS) == length);
	
	memcpy(l1sp.sph_allModePara, speech_mode_para, 
		NUM_SPH_MODE*NUM_MODE_PARAS*sizeof(uint16));
	l1sp.setNvramValuesFlag |= L1SP_NVRAM_VALUES_FLAG_MODE;
}

void spe_setHacSpeechModePara(kal_uint16 * modePara, kal_int16 length)
{
	ASSERT(NUM_MODE_PARAS == length);
	
	memcpy(l1sp.sph_allModePara[NUM_SPH_MODE], modePara, NUM_MODE_PARAS*sizeof(uint16));
}
void l1sp_SetWbSpeechPara( kal_uint16 m_para[NUM_MODE_PARAS] )
{
   memcpy( l1sp.sph_m_paraWb, m_para, NUM_MODE_PARAS*sizeof(uint16));
}
void l1sp_updateSpeAppMask(uint8 updateFlags, bool enable)
{
	if(enable)
		l1sp.spe_app_mask |= (updateFlags);
	else
		l1sp.spe_app_mask &= ~(updateFlags);

	kal_trace( TRACE_INFO, L1SP_UPDATE_SPE_MASKS, 2, l1sp.spe_app_mask, l1sp.spe_usr_mask, l1sp.spe_usr_sub_mask, updateFlags, enable);	
}

/*
void l1sp_updateSpeUsrMask(uint8 updateFlags, bool enable)
{
	if(enable)
		l1sp.spe_usr_mask |= (updateFlags);
	else
		l1sp.spe_usr_mask &= ~(updateFlags);

	kal_trace( TRACE_INFO, L1SP_UPDATE_SPE_MASKS, 2, l1sp.spe_app_mask, l1sp.spe_usr_mask, l1sp.spe_usr_sub_mask, updateFlags, enable);	
}
*/
void l1sp_updateSpeUsrMaskWithWholeValue(uint16 newValue)
{
	kal_uint16 orgValue = l1sp.spe_usr_mask;

	l1sp.spe_usr_mask  = newValue;
	
	kal_trace( TRACE_INFO, L1SP_UPDATE_SPE_MASKS, 3, l1sp.spe_app_mask, l1sp.spe_usr_mask, l1sp.spe_usr_sub_mask, newValue, orgValue);	
	
	if(l1sp.spe_state) // already turn on speech enhancement
      SetSpeechEnhancement(KAL_TRUE);
}

/**
	@newValue: 
	typedef enum{
                // ==> SAL_ENH_DYNAMIC_MUTE_UL, bit 0. Please DO NOT use it
		SPE_DYNAMIC_MASK_DMNR = 0x1, // ==> SAL_ENH_DYNAMIC_DMNR_MUX, bit 1
		SPE_DYNAMIC_MASK_VCE  = 0x2, // ==> SAL_ENH_DYNAMIC_VCE_MUX, bit 2
		SPE_DYNAMIC_MASK_BWE  = 0x4, // ==> SAL_ENH_DYNAMIC_BWE_MUX, bit 3
		SPE_DYNAMIC_MASK_DLNR  = 0x8, // ==> SAL_ENH_DYNAMIC_DLNR_MUX, bit 4  // undefined in AP
		SPE_DYNAMIC_MASK_ULNR  = 0x10, // ==> SAL_ENH_DYNAMIC_DLNR_MUX, bit 5 // undefined in AP
		SPE_DYNAMIC_MASK_LSPK_DMNR  = 0x20, // ==> SAL_ENH_DYNAMIC_DLNR_MUX, bit 6
		SPE_DYNAMIC_MASK_SIDEKEYCTRL_DGAIN = 0x40, // ==> SAL_ENH_DYNAMIC_SIDEKEYCTRL_DGAIN_MUX, bit 7
	}SPE_SUB_MASK_T;
	
*/
void l1sp_updateSpeUsrSubMaskWithWholeValue(uint16 newValue)
{
	kal_uint16 orgValue = l1sp.spe_usr_sub_mask;

	l1sp.spe_usr_sub_mask  = (newValue<<1);
	
	kal_trace( TRACE_INFO, L1SP_UPDATE_SPE_MASKS, 4, l1sp.spe_app_mask, l1sp.spe_usr_mask, l1sp.spe_usr_sub_mask, newValue, orgValue);	
	
	if(l1sp.spe_state) // already turn on speech enhancement
      SetSpeechEnhancement(KAL_TRUE);
}

#if defined(__DUAL_MIC_SUPPORT__) || defined(__SMART_PHONE_MODEM__)	

/**
	Not support parameter rewirte under application begin runnning
*/
void L1SP_SetDMNRPara( const kal_int16 DMNR_para[NUM_DMNR_PARAM] )
{
	
	memcpy(&l1sp.sph_dmnr_para, DMNR_para, NUM_DMNR_PARAM*sizeof(uint16));
	// SPE_LoadDmnrCoeffs(l1sp.sph_dmnr_para); // load the data to DSP before turn on
}

#if defined(__AMRWB_LINK_SUPPORT__)
/**
	Not support parameter rewirte under application begin runnning
*/
void L1SP_SetWbDMNRPara( const kal_int16 WB_DMNR_para[NUM_WB_DMNR_PARAM] )
{
	memcpy(&l1sp.sph_wb_dmnr_para, WB_DMNR_para, NUM_WB_DMNR_PARAM*sizeof(uint16));
	// SPE_LoadWbDmnrCoeffs(l1sp.sph_wb_dmnr_para); // load the data to DSP before turn on 
}
#endif //__AMRWB_LINK_SUPPORT__

/**
	Not support parameter rewirte under application begin runnning
*/
void L1SP_SetLSpkDMNRPara( const kal_int16 LSpk_DMNR_para[NUM_DMNR_PARAM] )
{	
	memcpy(&l1sp.sph_lspk_dmnr_para, LSpk_DMNR_para, NUM_DMNR_PARAM*sizeof(uint16));
	// SPE_LoadDmnrCoeffs(l1sp.sph_dmnr_para); // load the data to DSP before turn on
}

#if defined(__AMRWB_LINK_SUPPORT__)

/**
	Not support parameter rewirte under application begin runnning
*/
void L1SP_SetLSpkWbDMNRPara( const kal_int16 LSpk_Wb_DMNR_para[NUM_WB_DMNR_PARAM] )
{
	memcpy(&l1sp.sph_lspk_wb_dmnr_para, LSpk_Wb_DMNR_para, NUM_WB_DMNR_PARAM*sizeof(uint16));
	// SPE_LoadWbDmnrCoeffs(l1sp.sph_wb_dmnr_para); // load the data to DSP before turn on 
}
#endif //__AMRWB_LINK_SUPPORT__

#endif //__DUAL_MIC_SUPPORT__ || defined(__SMART_PHONE_MODEM__)	



kal_uint8 L1SP_GetSpeechMode( void )
{
    return l1sp.sph_mode;
}


static void changeSpeechMode(uint8 afterSalDevMode, uint8 prev_sph_mode, uint8 after_sph_mode, 
	uint16 m_paras[NUM_MODE_PARAS])
{
	kal_bool preIsBt;
	kal_bool afterIsBt;
	kal_bool isSpeechOn; 
	kal_bool isAmInSpeechState;

	kal_trace( TRACE_INFO, L1SP_CHANGE_ENH_MODE, prev_sph_mode, after_sph_mode, l1sp.sph_mode); 

	preIsBt = ( (SPH_MODE_BT_EARPHONE==prev_sph_mode) || 
		(SPH_MODE_BT_CORDLESS==prev_sph_mode) ||
		(SPH_MODE_BT_CARKIT==prev_sph_mode) );
	afterIsBt = ( (SPH_MODE_BT_EARPHONE==after_sph_mode) || 
		(SPH_MODE_BT_CORDLESS==after_sph_mode) ||	
		(SPH_MODE_BT_CARKIT==after_sph_mode) );
	isSpeechOn = AM_IsSpeechOn();
	isAmInSpeechState = AM_IsAmInSpeechState();

#if defined(__CVSD_CODEC_SUPPORT__) 
   if( (prev_sph_mode != after_sph_mode) && BT_SCO_IS_SPEECH_ON() )
   {
      BT_SCO_SPEECH_OFF();
   }
#endif
	
	// Always turn off the enhancement first in order to feed the parameter to DSP in the run time(under call)
	// beacuse enhancement only get the parameter under enable state machine
	SetSpeechEnhancement( false );
	
   // setBt(after_sph_mode, prev_sph_mode);
   if(preIsBt != afterIsBt){ // need off on speech , due to speech buffer changes between VBI and DAI
   	// turn off DSP app
   	if(true == isAmInSpeechState){
			if(true == isSpeechOn) {
				AM_SpeechOff(1); // turn off 8k and speech off

			} else { // cordless mode / speech 
				
				// if( prev_sph_mode == SPH_MODE_BT_CORDLESS ) {
			  	// 	AM_BTCordlessOff();
		   	// } else {		   		
					ASSERT(0); // Do not handle here. Please handle it on application
					// AM_PCM_EX_Off(AM_PCMEX_TYPE type,uint32 p2exData)
		   	// }
				
			}
   	}
			
		if(l1sp.bt_on)
		{
			AM_BluetoothOff();
			l1sp.bt_on = false;
		}
   }

	// Begin apply the new device and enhancement parameter
	// setSrcControl(prev_sph_mode, mode);
	if((SPH_MODE_BT_EARPHONE==after_sph_mode) || 
		(SPH_MODE_BT_CARKIT==after_sph_mode)) {
		// get sampling rate information from AFE information
		if(0== AFE_GetVoice8KMode()) { // NB
			SAL_Set_Device(SAL_DEV_BT_EARPHONE_NB);
		} else { //WB
			SAL_Set_Device(SAL_DEV_BT_EARPHONE_WB);
		}
	} else {
		SAL_Set_Device(afterSalDevMode);
	}
	
	l1sp.sph_mode = after_sph_mode;		
	
	memcpy(l1sp.sph_m_para, m_paras, NUM_MODE_PARAS*sizeof(uint16));

	if(preIsBt != afterIsBt){ // need off on speech, due to speech buffer changes between VBI and DAI
		
		if(afterIsBt)
		{
			if ((after_sph_mode==SPH_MODE_BT_CORDLESS || after_sph_mode==SPH_MODE_LINEIN_VIA_BT_CORDLESS)) 
         {
         	AM_BluetoothOn(1);
			} else {
				AM_BluetoothOn(2);
			}
			
			l1sp.bt_on = true;
		}

		if(true == isAmInSpeechState){
			if(true == isSpeechOn) {				
				// [REMIND]L1SP_STATE_xx can mapping to RAT_2G_MODE using "index -1"
				AM_SpeechOn((L1SP_GetState()-1), 1); 
				
			} else { // cordless mode / speech 
				
				// if( after_sph_mode == SPH_MODE_BT_CORDLESS ) {
			  	// 	AM_BTCordlessOn();
		   	// } else {		   		
					ASSERT(0); // Do not handle here. Please handle it on application
					// AM_PCM_EX_Off(AM_PCMEX_TYPE type,uint32 p2exData)
		   	// }
				
			}
   	}
   }
	
   kal_trace( TRACE_INFO, L1SP_SET_MODE, l1sp.sph_mode, -1, l1sp.mic_volume );
   SetSpeechEnhancement( true );

#if defined(__CVSD_CODEC_SUPPORT__) 
   if( (SPH_MODE_BT_EARPHONE==after_sph_mode) || (SPH_MODE_BT_CARKIT==after_sph_mode) )
   {
      if(isSpeechOn && !BT_SCO_IS_SPEECH_ON())
      {
         kal_bool is_WB = AFE_GetVoice8KMode() == 1 ? KAL_TRUE : KAL_FALSE;
         BT_SCO_SPEECH_ON(is_WB);
      }
   }
#endif

}


void l1sp_SetSpeechMode( uint8 devMode, uint8 mode, uint16 m_para[NUM_MODE_PARAS] )
{
   uint8 prev_sph_mode = l1sp.sph_mode;
#if ( defined( __CENTRALIZED_SLEEP_MANAGER__ )&& defined( MTK_SLEEP_ENABLE ))
   kal_uint16 aud_id = L1SP_GetAudID();
#endif   

#ifdef SPH_CHIP_BACK_MODE_FIX_TO_NORMAL
	devMode = SAL_DEV_NORMAL;
   mode = SPH_MODE_NORMAL; // force setting to normal mode
#endif

   kal_trace(TRACE_INFO, L1SP_PHONE_CALL, 4, prev_sph_mode, mode);
  	kal_trace(TRACE_INFO, L1SP_MODE_VALUE, m_para[0], m_para[1], m_para[2], m_para[3], m_para[4], m_para[5], m_para[6], m_para[7], m_para[8], m_para[9], m_para[10], m_para[11], m_para[12], m_para[13], m_para[14], m_para[15]);
	changeSpeechMode(devMode, l1sp.sph_mode, mode, m_para);   
	
#if ( defined( __CENTRALIZED_SLEEP_MANAGER__ )&& defined( MTK_SLEEP_ENABLE ))
   L1SP_FreeAudID(aud_id);
#endif   		
}

static void l1sp_getFirMappingByScene(const uint32 scene, 
	uint8 *devMode, uint8 *enhMode,
	uint8 *inFir, uint8 *outFir)
{
	uint8 tempDevMode = 0xff; 
	uint8 tempEnhMode = 0xff;
	uint8 tempInFir = 0xff; 
	uint8 tempOutFir = 0xff;
	
	switch(scene) {
	case SPH_ENH_AND_FIR_SCENE_NORMAL:
		tempDevMode = SAL_DEV_NORMAL; // SPH_MODE_NORMAL;
		tempEnhMode = SPH_MODE_NORMAL;
		tempInFir = SPH_FIR_COEFF_NORMAL;
		tempOutFir = SPH_FIR_COEFF_NORMAL;
		
		break;
	case SPH_ENH_AND_FIR_SCENE_EARPHONE:
	case SPH_ENH_AND_FIR_SCENE_LOUDSPK:
		tempDevMode = scene; // SAL_DEV_EARPHONE or SAL_DEV_LOUDSPK
		tempEnhMode = scene;
		tempInFir = scene;
		tempOutFir = scene;
		break;	
#if defined(__BT_SUPPORT__)		
	case SPH_ENH_AND_FIR_SCENE_BT_EARPHONE:	
	case SPH_ENH_AND_FIR_SCENE_BT_CARKIT:
		tempDevMode = SAL_DEV_BT_EARPHONE_NB; //scene;
		tempEnhMode = scene;
		tempInFir = SPH_FIR_COEFF_BT; 
		tempOutFir = SPH_FIR_COEFF_BT;
		break;

	case SPH_ENH_AND_FIR_SCENE_BT_CORDLESS:		
#if defined(MT6280) || defined(MT6589) || defined(MT6572) || defined(MT6582) || defined(MT6592) || defined(MT6571)|| defined(MT6580)// hw did not support
		ASSERT(0);
#else 
		tempDevMode = SAL_DEV_BT_CORDLESS; //scene;
		tempEnhMode = scene;
		tempInFir = SPH_FIR_COEFF_BT; 
		tempOutFir = SPH_FIR_COEFF_BT;
#endif		
		break;
#endif
	case SPH_ENH_AND_FIR_SCENE_AUX1: // AUX is use to  loud speaker mode
		tempDevMode = SAL_DEV_LOUDSPK; //scene
		tempEnhMode = SPH_MODE_AUX1; //scene
		tempInFir = SPH_FIR_COEFF_HANDFREE;
		tempOutFir = SPH_FIR_COEFF_HANDFREE;
		break;
	case SPH_ENH_AND_FIR_SCENE_AUX2:
		tempDevMode = SPH_MODE_NORMAL;
		tempEnhMode = SPH_MODE_AUX2;
		tempInFir = SPH_FIR_COEFF_NORMAL;
		tempOutFir = SPH_FIR_COEFF_NORMAL;
		break;		
	case SPH_ENH_AND_FIR_SCENE_HAC:
		ASSERT(true == l1sp.isHacModeNeeded); // is AP did not set the mode parameter. assert it directly! 
		
		tempDevMode = SPH_MODE_NORMAL;
		tempEnhMode = SPH_MODE_HAC;
		tempInFir = SPH_FIR_COEFF_HAC;
		tempOutFir = SPH_FIR_COEFF_HAC;
		break;		
	default:
		{
			ASSERT(0);
		}

	}
	
	*devMode = tempDevMode;
	*enhMode = tempEnhMode;
	*inFir = tempInFir;
	*outFir = tempOutFir;
	
}

/**
	new interface to replace L1SP_SetSpeechMode(), L1SP_Write_Audio_Coefficients(), 
	L1SP_Write_WB_Audio_Coefficients() in the same time. 

	if you want to use personal configuration, you can use original interfaces. 

	@scene: [Input] scenario for different enhancement and fir combination. 
*/
void L1SP_SetSpeechEnhanceAndFir(uint32 scene, uint32 updatedCoeff)

{
	uint8 modeIndex = 0;
	uint8 inFirIndex = 0;
	uint8 outFirIndex = 0;
	uint8 devModeIndex = 0; 


	//speech mode
//----------------- original scenario ---------------
	if(scene <SPH_MODE_UNDEFINED)
	{ //keeping the original scenario

		l1sp_getFirMappingByScene(scene, &devModeIndex, &modeIndex, 
			&inFirIndex, &outFirIndex);

#ifdef WB_SPE_SUPPORT 
		if((updatedCoeff == 0) || (updatedCoeff&SPH_ENH_AND_FIR_UPDATE_TYPE_WB_FIR)!=0){
			if((l1sp.setNvramValuesFlag & L1SP_NVRAM_VALUES_FLAG_WB_IN_FIR)
				&& (l1sp.setNvramValuesFlag & L1SP_NVRAM_VALUES_FLAG_WB_OUT_FIR)) {

				AM_WriteWbFirCoeffs(l1sp.sph_allWbInFirCoeff[inFirIndex],
					l1sp.sph_allWbOutFirCoeff[outFirIndex]);
				// l1sp_Write_WB_Audio_Coefficients(l1sp.sph_allWbInFirCoeff[inFirIndex], l1sp.sph_allWbOutFirCoeff[outFirIndex]);
			}
		}
#endif	
	
		// Write NB FIR
		// this function needs to after WB Fir Coeffs are set. Because BKF enable is in this function
		if((updatedCoeff == 0) || (updatedCoeff&SPH_ENH_AND_FIR_UPDATE_TYPE_NB_FIR)!=0)
			L1SP_Write_Audio_Coefficients_ByFirIndex(inFirIndex, outFirIndex); 
		//l1sp_Write_Audio_Coefficients(l1sp.sph_allInFirCoeff[inFirIndex], l1sp.sph_allOutFirCoeff[outFirIndex]);

	
		//speech mode
#ifdef WB_SPE_SUPPORT 
		if((updatedCoeff == 0) || (updatedCoeff&SPH_ENH_AND_FIR_UPDATE_TYPE_WB_ENH_MODE)!=0){
			if(l1sp.setNvramValuesFlag & L1SP_NVRAM_VALUES_FLAG_WB_MODE)//(l1sp.has_all_wb_sph_m_para)
				l1sp_SetWbSpeechPara(l1sp.sph_allWbModePara[modeIndex]);
		}
#endif 		
		if((updatedCoeff == 0) || (updatedCoeff&SPH_ENH_AND_FIR_UPDATE_TYPE_NB_ENH_MODE)!=0)
			l1sp_SetSpeechMode(devModeIndex, modeIndex, l1sp.sph_allModePara[modeIndex]);
	

	}
//---------------------- undefined cases --------------------
	else { // undefined cases. 
		kal_trace ( TRACE_INFO, L1SP_USELESS_SET, scene, 0, 0);
	}
	
	kal_trace( TRACE_INFO, L1SP_SET_ENH_FIR, scene, modeIndex, inFirIndex, outFirIndex, l1sp.spe_usr_mask, l1sp.spe_app_mask);
	
}

void l1sp_setAllSpeechFirCoeff_InputOnly(int16 *speech_input_FIR_coeffs, int16 length)
{
	ASSERT((NUM_SPH_INPUT_FIR*NUM_FIR_COEFFS) == length);
	
	memcpy(l1sp.sph_allInFirCoeff, speech_input_FIR_coeffs, 
		NUM_SPH_INPUT_FIR*NUM_FIR_COEFFS*sizeof(int16));
	l1sp.setNvramValuesFlag |= L1SP_NVRAM_VALUES_FLAG_IN_FIR;

}

void spe_setHacSpeechFirCoeff_InputOnly(kal_int16 *fIR_coeffs, kal_int16 length)
{
	ASSERT(NUM_FIR_COEFFS == length);
	
	memcpy(l1sp.sph_allInFirCoeff[NUM_SPH_INPUT_FIR], fIR_coeffs, NUM_FIR_COEFFS*sizeof(int16));
}
void l1sp_setAllSpeechFirCoeff_OutputOnly(int16 *speech_output_FIR_coeffs, int16 length)
{
	ASSERT((NUM_SPH_OUTPUT_FIR*NUM_FIR_COEFFS) == length);
	
	memcpy(l1sp.sph_allOutFirCoeff, speech_output_FIR_coeffs,
		NUM_SPH_OUTPUT_FIR*NUM_FIR_COEFFS*sizeof(int16));
	l1sp.setNvramValuesFlag |= L1SP_NVRAM_VALUES_FLAG_OUT_FIR;
}

void spe_setHacSpeechFirCoeff_OutputOnly(kal_int16 *fIR_coeffs, kal_int16 length)
{
	ASSERT(NUM_FIR_COEFFS == length);
	
	memcpy(l1sp.sph_allOutFirCoeff[NUM_SPH_OUTPUT_FIR], fIR_coeffs, NUM_FIR_COEFFS*sizeof(int16));
}
void l1sp_setAllWbSpeechModePara(uint16 * speech_mode_para, int16 length)
{
#ifdef WB_SPE_SUPPORT
	ASSERT((NUM_SPH_MODE*NUM_MODE_PARAS) == length);
	
	memcpy(l1sp.sph_allWbModePara, speech_mode_para, 
		NUM_SPH_MODE*NUM_MODE_PARAS*sizeof(uint16));
	l1sp.setNvramValuesFlag |= L1SP_NVRAM_VALUES_FLAG_WB_MODE; // (1<<3) bit [3]
#endif // WB_SPE_SUPPORT
}

void spe_setHacWbSpeechModePara(kal_uint16 * modePara, kal_int16 length)
{
	ASSERT(NUM_MODE_PARAS == length);
	
	memcpy(l1sp.sph_allWbModePara[NUM_SPH_MODE], modePara, NUM_MODE_PARAS*sizeof(uint16));
}
void l1sp_setAllWbSpeechFirCoeff_InputOnly(
		int16 *speech_input_FIR_coeffs, int16 length)
{
#ifdef WB_SPE_SUPPORT
	ASSERT((NUM_SPH_INPUT_FIR*NUM_WB_FIR_COEFFS) == length);
	memcpy(l1sp.sph_allWbInFirCoeff, speech_input_FIR_coeffs, 
		length*sizeof(int16));
	l1sp.setNvramValuesFlag |= L1SP_NVRAM_VALUES_FLAG_WB_IN_FIR; // (1<<4) bit [4]
#endif // WB_SPE_SUPPORT
}

void spe_setHacWbSpeechFirCoeff_InputOnly(kal_int16 *fIR_coeffs, kal_int16 length)
{
	ASSERT(NUM_WB_FIR_COEFFS == length);
	
	memcpy(l1sp.sph_allWbInFirCoeff[NUM_SPH_INPUT_FIR], fIR_coeffs, NUM_WB_FIR_COEFFS*sizeof(int16));
}
void l1sp_setAllWbSpeechFirCoeff_OutputOnly(
		int16 *speech_output_FIR_coeffs, int16 length)
{
#ifdef WB_SPE_SUPPORT
	ASSERT((NUM_SPH_OUTPUT_FIR*NUM_WB_FIR_COEFFS) == length);
	memcpy(l1sp.sph_allWbOutFirCoeff, speech_output_FIR_coeffs,
		length*sizeof(int16));
	l1sp.setNvramValuesFlag |= L1SP_NVRAM_VALUES_FLAG_WB_OUT_FIR; // (1<<4) bit [4]
#endif //WB_SPE_SUPPORT
}
void spe_setHacWbSpeechFirCoeff_OutputOnly(kal_int16 *fIR_coeffs, kal_int16 length)
{
	ASSERT(NUM_WB_FIR_COEFFS == length);
	
	memcpy(l1sp.sph_allWbOutFirCoeff[NUM_SPH_OUTPUT_FIR], fIR_coeffs, NUM_WB_FIR_COEFFS*sizeof(int16));
}
/**
	@index: [Input] Identify which LID is going to provide
	@buffer: [Output] Buffer with the contain the result
	@len: [Input] Length of the output buffer
*/
void L1SP_GetNvramInfoByIndex(L1SP_NVRAM_INFO_INDEX index, void *buffer, uint16 len)
{
	switch(index)
	{
#if WB_SPE_SUPPORT
	case L1SP_NVRAM_INFO_INDEX_WB_SPEECH_INPUT_FIR:
	{
		ASSERT(len == (NUM_SPH_INPUT_FIR * NUM_WB_FIR_COEFFS));
		memcpy(buffer, l1sp.sph_allWbInFirCoeff, sizeof(kal_uint16) * NUM_SPH_INPUT_FIR * NUM_WB_FIR_COEFFS);
	}
		break;
	case L1SP_NVRAM_INFO_INDEX_WB_SPEECH_OUTPUT_FIR:
	{
		ASSERT(len == (NUM_SPH_OUTPUT_FIR * NUM_WB_FIR_COEFFS));
		memcpy(buffer, l1sp.sph_allWbOutFirCoeff, sizeof(kal_uint16) * NUM_SPH_OUTPUT_FIR * NUM_WB_FIR_COEFFS);
	}
		break;
	case L1SP_NVRAM_INFO_INDEX_WB_SPEECH_MODE_PARAM:
	{
		ASSERT(len == (NUM_SPH_MODE * NUM_MODE_PARAS));
		memcpy(l1sp.sph_allWbModePara, buffer, sizeof(kal_uint16) * NUM_SPH_MODE * NUM_MODE_PARAS);
	}
		break;
#endif // WB_SPE_SUPPORT
	default:
		ASSERT(0); 
	}
}
/**
	MED can put all nvram structure to AUD via this function. Audio/Speech driver will parsing the LID by itself. 
	
	@index: [Input] Identify which LID is used to parsing the buffer
	@buffer: [Input] Buffer with the contain from nvram
	@len: [Input] Length of the input buffer
*/
void L1SP_SetNvramInfoByIndex(L1SP_NVRAM_INFO_INDEX index, uint8* buffer, uint16 len)
{
	switch(index)
	{
	case L1SP_NVRAM_INFO_INDEX_UNDEF:		

		break;
	case L1SP_NVRAM_INFO_INDEX_PARAM:
	{
		int16 bufCur=0;

		//NB input FIR
		l1sp_setAllSpeechFirCoeff_InputOnly((int16 *)(buffer + bufCur), 6 * NUM_FIR_COEFFS);
        bufCur += (sizeof(kal_uint16)* 6 * NUM_FIR_COEFFS);

		//NB output FIR
		l1sp_setAllSpeechFirCoeff_OutputOnly((int16 *)(buffer + bufCur), 6 * NUM_FIR_COEFFS);
        bufCur += (sizeof(kal_uint16)* 6 * NUM_FIR_COEFFS);

		//selected FIR
		kal_mem_cpy(&(l1sp.sph_selectedOutFirIndex), (buffer + bufCur), sizeof(kal_uint16));
		bufCur += sizeof(kal_uint16);
		
		//common
		{
		uint16 *data = (uint16 *)(buffer + bufCur);
		L1SP_LoadCommonSpeechPara(data); //common paramter will copy into l1sp.sph_c_para in this function
		bufCur += sizeof(kal_uint16) * 12; //hardcoding size
		}

		//mode parameter
		l1sp_setAllSpeechModePara((uint16 *)(buffer + bufCur), ( NUM_SPH_MODE * 16));
		bufCur += (sizeof(kal_uint16)* NUM_SPH_MODE * 16);

		kal_mem_cpy(l1sp.sph_allVolumePara, (buffer + bufCur), (sizeof(kal_uint16)*3*7*4));
		l1sp.setNvramValuesFlag |= L1SP_NVRAM_VALUES_FLAG_VOLUME_PARAM;
		
		/*		
	    	kal_uint16 Media_Playback_Maximum_Swing;
    		kal_int16 Melody_FIR_Coeff_Tbl[25];
	    	kal_int16 audio_compensation_coeff[3][45];
		*/
	}
		break;
		
#if WB_SPE_SUPPORT
	case L1SP_NVRAM_INFO_INDEX_WB_SPEECH_INPUT_FIR:
	{
		memcpy(l1sp.sph_allWbInFirCoeff, buffer, sizeof(kal_uint16) * NUM_SPH_INPUT_FIR * NUM_WB_FIR_COEFFS);
		l1sp.setNvramValuesFlag |= L1SP_NVRAM_VALUES_FLAG_WB_IN_FIR; // (1<<4) bit [4]
	}
		break;
	case L1SP_NVRAM_INFO_INDEX_WB_SPEECH_OUTPUT_FIR:
	{
		memcpy(l1sp.sph_allWbOutFirCoeff, buffer, sizeof(kal_uint16) * NUM_SPH_OUTPUT_FIR * NUM_WB_FIR_COEFFS);
		l1sp.setNvramValuesFlag |= L1SP_NVRAM_VALUES_FLAG_WB_OUT_FIR; // (1<<5) bit [5]
	}
		break;
	case L1SP_NVRAM_INFO_INDEX_WB_SPEECH_MODE_PARAM:
	{
		memcpy(l1sp.sph_allWbModePara, buffer, sizeof(kal_uint16) * NUM_SPH_MODE * NUM_MODE_PARAS);
		l1sp.setNvramValuesFlag |= L1SP_NVRAM_VALUES_FLAG_WB_MODE; // (1<<3) bit [3]
	}
		break;
#endif

#if 0 //defined(__HD_RECORD__)
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
#if defined(__STEREO_RECORD__)
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif //__HD_RECORD__	

	default:
		ASSERT(0); 
	}
		
}

/**
	@device: device using in speech. pleae refer to 
		#define  L1SP_BUFFER_0        0x01    // NOTE: Don't use buffer definition directly
		#define  L1SP_BUFFER_1        0x02    //       Use speaker definition below
		#define  L1SP_BUFFER_ST       0x04
		#define  L1SP_BUFFER_EXT      0x08
		#define  L1SP_BUFFER_EXT_G    0x10
		#define  L1SP_STEREO2MONO     0x20     // Do not use this term for speaker definition
		#define  L1SP_BUFFER_ST_M     (L1SP_BUFFER_ST|L1SP_STEREO2MONO)
		#define  L1SP_EXT_DAC_BUF0    0x40 
		#define  L1SP_EXT_DAC_BUF1    0x80
	Phase-out function without using
*/
void L1SP_SetOutputDevice( uint8 device )
{
#if 0 //def ANALOG_AFE_PATH_EXIST
/* under construction !*/
/* under construction !*/
#endif // #ifdef ANALOG_AFE_PATH_EXIST
}

/**
	@return: device using in speech.
	Phase-out function without using
*/
uint8 L1SP_GetOutputDevice(void)
{
   return 0; //l1sp.output_dev;
}

/**
	Function is used when MODEM side has PGA gain & DSP digital gain control 
	i.e. ANALOG_AFE_PATH_EXIST is defined
	
	@volume1: MMI(EM) value from 0 to 256	
	@digital_gain_index:unit is 0.5 db. Value from 0 to -64db (seems option)
*/
void L1SP_SetOutputVolume( uint8 volume1, int8 digital_gain_index )
{
#if 0 // ANALOG_AFE_PATH_EXIST  
/* under construction !*/
/* under construction !*/
#endif
}

#if defined(__GAIN_TABLE_SUPPORT__)
void L1SP_SetOutputGainControl( uint32 gain )
{
#if 0 // ANALOG_AFE_PATH_EXIST  
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
}
#endif

#ifndef ANALOG_AFE_PATH_EXIST  // ONLY exist digital path and hw
void l1sp_digiOnly_SetOutputVolume(int16 digitalGain)
{
	AFE_DigitalOnly_SetDigitalGain( L1SP_SPEECH, digitalGain );
}
#endif

void l1sp_digiOnly_SetEnhRefOutputVolume(int16 digitalRefGain)
{
	AFE_DigitalOnly_SetEnhRefDigitalGain(digitalRefGain);
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
#endif

/**
	this function is to replace L1SP_SetSpeechVolumeLevel()
	
	@level: [input] speech volume level for speech
	@v_paraIndex: [input] volume paramter (saving in nvram) index
*/
void L1SP_SetSpeechVolumeLevelByIndex(kal_uint8 level, kal_uint8 v_paraIndex)
{
//  phase out. 
// 	L1SP_SetSpeechVolumeLevel(level, l1sp.sph_allVolumePara[v_paraIndex][level]);
}

/**
	Phase out function without using
	@src: microhpone source for speech, plese refer to
		#define  L1SP_LNA_0           0
		#define  L1SP_LNA_1           1
		#define  L1SP_LNA_DIGITAL     2
		#define  L1SP_LNA_FMRR        3
	
*/
void L1SP_SetInputSource( uint8 src )
{
#if 0 //def ANALOG_AFE_PATH_EXIST    
/* under construction !*/
#endif
}

/**
	Phase out function without using
	@return: microphone source for speech
*/
uint8 L1SP_GetInputSource( void )
{
	return 0; // AFE_GetInputSource();
}


/**
	@mic_volume: MMI(EM) value. Including Analog & digital gain
*/
void L1SP_SetMicrophoneVolume( uint8 mic_volume )
{
}

#ifndef ANALOG_AFE_PATH_EXIST  // ONLY exist digital path and hw
void l1sp_digiOnly_SetMicrophoneVolume(int16 digitalGain)
{
	AFE_DigitalOnly_SetMicrophoneVolume(digitalGain);
}
#endif

#if defined(__GAIN_TABLE_SUPPORT__)
void L1SP_SetMicGainControl( uint32 mic_gain )
{
   //kal_trace( TRACE_INFO, L1SP_SET_MIC_VOL, mic_volume, l1sp.sph_m_para[4]);
   kal_uint32 mic_volume = mic_gain >> 26;
   kal_trace( TRACE_INFO, L1SP_SET_MIC_GAIN_CONTROL, mic_gain);
   //if( (l1sp.sph_m_para[4] & 0x2000) )
   {
      if(mic_volume >= 10)
         mic_volume -= 10;//down 10 dB
      else
         mic_volume = 0;
   }
   mic_gain = (mic_gain & 0x03FFFFFF) | (mic_volume << 26);
   //kal_trace( TRACE_INFO, L1SP_ADAPT_MIC_VOL, mic_volume);	
   kal_trace( TRACE_INFO, L1SP_ADAPT_MIC_GAIN_CONTROL, mic_gain);

   AFE_SetMicGainControl( mic_gain );
   
   SetSpeechEnhancement( true );
}
#endif

uint8 L1SP_GetMicrophoneVolume( void )
{
   return 0;
}

/**
	Phase out function without using
	@sidetone: value from EM, which is 0~255. 
*/
void L1SP_SetSidetoneVolume( uint8 sidetone )
{
	// keep API header to avoid link error
}

/**
	Phase out function without using
	@return: value from EM, which is 0~255. 
*/
uint8 L1SP_GetSidetoneVolume( void )
{
	// keep API header to avoid link error, 
	return 0;
}
void SP_MuteUlEnhResult(bool mute)
{
#if ( defined( __CENTRALIZED_SLEEP_MANAGER__ )&& defined( MTK_SLEEP_ENABLE ))
			kal_uint16 aud_id = L1SP_GetAudID();
#endif  
	l1sp.isUlEnhResultMute = mute;
	AM_Mute_UL_EnhResult_Speech(mute);

#if ( defined( __CENTRALIZED_SLEEP_MANAGER__ )&& defined( MTK_SLEEP_ENABLE ))
   L1SP_FreeAudID(aud_id);
#endif 

}

void SP_MuteUlSource(bool mute)
{
#if ( defined( __CENTRALIZED_SLEEP_MANAGER__ )&& defined( MTK_SLEEP_ENABLE ))
			kal_uint16 aud_id = L1SP_GetAudID();
#endif  
	l1sp.isUlSourceMute = mute;
	AM_Mute_UL_Source_Speech(mute);

#if ( defined( __CENTRALIZED_SLEEP_MANAGER__ )&& defined( MTK_SLEEP_ENABLE ))
   L1SP_FreeAudID(aud_id);
#endif 

}


void SP_MuteController() // central controll, and placed between L1Audio_SetFlag and L1Audio_ClearFlag
{
   //return; returning at this point will be equal to disable this feature
   kal_trace(TRACE_INFO, L1SP_MUTE_CONTROL_STATUS, 2, l1sp.isULMute, l1sp.isDLMute, l1sp.codec_mute, l1sp.forcedUnmuteController);
   //DL 
   if(l1sp.forcedUnmuteController){
      AM_Mute_DL_8K_Speech(l1sp.isDLMute); 
      AM_Mute_DL_Speech_Traffic(false);  
   
      //UL
      AM_Mute_UL_Codec_Speech(0 != l1sp.isULMute);            
   }else{
      AM_Mute_DL_8K_Speech(l1sp.isDLMute);
      AM_Mute_DL_Speech_Traffic(l1sp.codec_mute);  
   
      //UL
      if(l1sp.codec_mute){
         AM_Mute_UL_Codec_Speech(true);         
      }else{      
         AM_Mute_UL_Codec_Speech(0 != l1sp.isULMute);     
      }
   }
}

void SP_MuteUlFromDiffPos(bool mute, SP_MIC_MUTE_POS pos)
{
#if ( defined( __CENTRALIZED_SLEEP_MANAGER__ )&& defined( MTK_SLEEP_ENABLE ))
		kal_uint16 aud_id = L1SP_GetAudID();
#endif   

	if(mute) 
		l1sp.isULMute |= pos; 
	else 
		l1sp.isULMute &= (~pos);

	// AM_Mute_UL_Codec_Speech( 0 != l1sp.isULMute );
	SP_MuteController();
	
#if ( defined( __CENTRALIZED_SLEEP_MANAGER__ )&& defined( MTK_SLEEP_ENABLE ))
   L1SP_FreeAudID(aud_id);
#endif      	
}

/**
	For MED use ONLY!!! 
	other function please use void SP_MuteUlFromDiffPos(bool mute, SP_MIC_MUTE_POS pos)
*/
void L1SP_MuteMicrophone( bool mute )
{	
   
   //AFE_MuteMicrophone( mute ); // do not use AFE_MuteMicrophone for speech enhancement
   // AM_MuteULSpeech( mute );
   // l1sp.isULMute = mute;
   SP_MuteUlFromDiffPos(mute, SP_MIC_MUTE_POS_FROM_MED);
}

void L1SP_MuteSpeaker( bool mute )
{
#ifdef ANALOG_AFE_PATH_EXIST
   AFE_MuteSpeaker( L1SP_SPEECH, mute );
#else

#if ( defined( __CENTRALIZED_SLEEP_MANAGER__ )&& defined( MTK_SLEEP_ENABLE ))
   kal_uint16 aud_id = L1SP_GetAudID();
#endif      
	//AM_MuteDLSpeech( mute );
   l1sp.isDLMute = mute;
   SP_MuteController();
#if ( defined( __CENTRALIZED_SLEEP_MANAGER__ )&& defined( MTK_SLEEP_ENABLE ))
   L1SP_FreeAudID(aud_id);
#endif      
	
#endif
}

bool SP_IsSpeakerMute(void)
{
        return (l1sp.isDLMute!=0);
}

bool SP_IsMicMute(void)
{
	return (l1sp.isULMute!=0);
}

/**
	For MED use ONLY!!! 
	other function please use SP_IsMicMute() instead
*/
bool L1SP_IsMicrophoneMuted( void )
{
	return (l1sp.isULMute&SP_MIC_MUTE_POS_FROM_MED)!=0; 
   // return AM_IsULSpeechMuted();
}

extern void CSR_SP3G_Callback( SP3G_Event event, void *data );
extern void vt_SP3G_Callback( kal_uint8 event, void *data );

#if defined( __UMTS_RAT__ ) || defined( __UMTS_TDD128_MODE__ )
void L1SP_3G_Request(void)
{  
   if(l1sp.state ==  L1SP_STATE_3G_SPEECH_ON)
   {
      CSR_SP3G_Callback(SP3G_CODEC_READY, (void*)SP3G_Rab_Id());
      return;
   }
}
#endif

void L1SP_SetState(uint8 state)
{
#if defined( __UMTS_RAT__ ) || defined( __UMTS_TDD128_MODE__ )
   if( ( l1sp.state == L1SP_STATE_3G_SPEECH_ON && state == L1SP_STATE_2G_SPEECH_ON ) ||
      ( l1sp.state == L1SP_STATE_2G_SPEECH_ON && state == L1SP_STATE_3G_SPEECH_ON ) )
      l1sp.interRAT = true;
#endif
   l1sp.state = state; 
   L1Audio_Msg_Speech_State(L1Audio_Speech_State(state));
}

uint8 L1SP_GetState( void )
{
   return l1sp.state; 
}


kal_bool L1SP_IsSpeechOn( void )
{
    return (AM_IsSpeechOn());
}

bool voc_flag = false;


void L1SP_Speech_On( uint8 RAT_Mode )
{
   kal_uint32 module_id = MOD_L1AUDIO_SPH_SRV;
   kal_uint32 voc_ptn = TVCI_CREATE_FILE;
   kal_uint32 *voc_ptn_ptr = &voc_ptn;
   
   kal_trace(TRACE_INFO, L1SP_PHONE_CALL, 0, RAT_Mode, -1);
	
   if( AM_IsSpeechOn() )
   {
#if defined(__CVSD_CODEC_SUPPORT__) 
      if((L1SP_GetSpeechMode() == SPH_MODE_BT_EARPHONE || L1SP_GetSpeechMode() == SPH_MODE_BT_CARKIT) && !BT_SCO_IS_SPEECH_ON())
      {
         kal_bool is_WB = AFE_GetVoice8KMode() == 1 ? KAL_TRUE : KAL_FALSE;
         BT_SCO_SPEECH_ON(is_WB);
      }
#endif
      return;
   }

#if (!defined(__SMART_PHONE_MODEM__)) && (!defined(__DATA_CARD_SPEECH__))
	ApAudSys_config();
#endif // defined(__SMART_PHONE_MODEM__)

   // for phone call used. 
   l1sp.aud_id = L1Audio_GetAudioID();
   L1Audio_SetFlag( l1sp.aud_id );     /* To lock sleep mode */

   SP_MuteController();
	//Check the mute status, this should always unmute. 
	ASSERT(SAL_Mute_Check(SAL_MUTE_DL_8K)==0);
	
#if !defined(__SMART_PHONE_MODEM__)
	// this two function is useless under smart phone, remove it to reduce process time
   TONE_StopAndWait();
   KT_StopAndWait();
#endif
   
   l1sp_updateSpeAppMask(0xff, true);

#ifdef ANALOG_AFE_PATH_EXIST
   AFE_SetDigitalGain(L1SP_SPEECH, 100);
#else

#endif


#if defined( __UMTS_RAT__ ) || defined( __UMTS_TDD128_MODE__ )
#ifdef __VIDEO_CALL_SUPPORT__
   if( RAT_Mode == RAT_3G324M_MODE )
      sp3g_speech_init( RAT_3G324M_MODE );
   else
#endif
      //In Dual mode, allow 2G/3G capability at initialization stage  for InterRAT HO
      //if 3G324M, there is no InterRAT
      sp3g_speech_init( RAT_3G_MODE );
   L1Audio_Msg_SP(0);
     
	// choose the mode is 2g /3g
   if( SP3G_Rab_State() && RAT_Mode != RAT_3G324M_MODE ){
      RAT_Mode = RAT_3G_MODE;
   }else if ( l1sp.tch_state ){
      RAT_Mode = RAT_2G_MODE;
   }else if(RAT_Mode != RAT_3G324M_MODE ){
   	  RAT_Mode = RAT_2G_MODE;
   }
   l1sp.interRAT = false;
   
   kal_trace(TRACE_INFO, L1SP_PHONE_CALL, 1, SP3G_Rab_State(), -1);
#endif
   
   kal_trace(TRACE_INFO, L1SP_PHONE_CALL, 2,  l1sp.tch_state, RAT_Mode);
   
   L1Audio_Msg_SP(1);
   AM_SpeechOn(RAT_Mode, 0);
   L1Audio_Msg_SP(2);



   switch(RAT_Mode)
   {
      case RAT_2G_MODE:
#if defined( __UMTS_RAT__ ) || defined( __UMTS_TDD128_MODE__ )      	
         kal_take_enh_mutex( sp_mutex );           
         if( SP3G_Rab_State()){
		         void SP3G_Rab_Est_sub();
		         SP3G_Rab_Est_sub();              	
         }else
#endif         	
         {
      	   AM_SetDSP2GReset(true);
           L1SP_SetState(L1SP_STATE_2G_SPEECH_ON);           	
         }
#if defined( __UMTS_RAT__ ) || defined( __UMTS_TDD128_MODE__ )      	         
         kal_give_enh_mutex(sp_mutex);
   #if !defined(__L1_STANDALONE__)
         #if !defined( __UMTS_TDD128_MODE__ )
         {
            if(query_ps_conf_test_mode()==PS_CONF_TEST_FTA)
               SP3G_SetDTX(false);
            else
               SP3G_SetDTX(true);
         }
         #endif  
   #endif             
#endif         	         
 
         break;
#if defined( __UMTS_RAT__ ) || defined( __UMTS_TDD128_MODE__ )
      case RAT_3G_MODE: 
         L1SP_SetState(L1SP_STATE_3G_SPEECH_ON);
         CSR_SP3G_Callback(SP3G_CODEC_READY, (void*)SP3G_Rab_Id());
#if !defined(__L1_STANDALONE__)
    #if !defined( __UMTS_TDD128_MODE__ )
         {
            if(query_ps_conf_test_mode()==PS_CONF_TEST_FTA)
               SP3G_SetDTX(false);
            else
               SP3G_SetDTX(true);
         }
    #endif
#endif         
         break;
#ifdef __VIDEO_CALL_SUPPORT__
      case RAT_3G324M_MODE: 
         L1SP_SetState(L1SP_STATE_3G324M_SPEECH_ON);
         vt_SP3G_Callback( (kal_uint8)SP3G_CODEC_READY, (void*)0 );
         break;
#endif
#endif
      default: 
         ASSERT(false);
   }
   kal_trace(TRACE_INFO, L1SP_PHONE_CALL, 3, -1, -1);

#ifndef __L1_STANDALONE__ // avoid link error
   if(!tst_trace_check_ps_filter_off(TRACE_GROUP_VM, &module_id, 0x2))
   {
      tst_vc_response(TVCI_VM_LOGGING, (const kal_uint8*)voc_ptn_ptr, 4);
      VMREC_Start(NULL, 0, true);
      voc_flag = true;
   }
#endif

	//always unmute DSP uplink when speech on (This is to keep the mute definition)
	SP_MuteUlEnhResult(false); 

   SetSpeechEnhancement( true );

	//always unmute DSP uplink when speech on (This is to keep the mute definition)
	SP_MuteUlFromDiffPos(false, SP_MIC_MUTE_POS_FROM_ALL); 
	L1SP_MuteSpeaker(false);

	
// for phone call usage   
#if !DATA_CARD_DISABLE_INTERNAL
#if defined(__DATA_CARD_SPEECH__)
   if (l1sp.strmOnHandler != NULL)
      l1sp.strmOnHandler( NULL );
#endif
#endif

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif 

#if defined(__ECALL_SUPPORT__)
   if (l1sp.pcm4wayOnHandler != NULL)
      l1sp.pcm4wayOnHandler( (void *)0);
#endif

#if defined(__CVSD_CODEC_SUPPORT__) 
   if(L1SP_GetSpeechMode() == SPH_MODE_BT_EARPHONE || L1SP_GetSpeechMode() == SPH_MODE_BT_CARKIT)
   {
      kal_bool is_WB = AFE_GetVoice8KMode() == 1 ? KAL_TRUE : KAL_FALSE;
      BT_SCO_SPEECH_ON(is_WB);
   }
#endif
  L1Audio_Msg_SP(4);
}


#if defined(__DATA_CARD_SPEECH__)
void L1SP_Register_Strm_Handler(
   void (*onHandler)(void *hdl),
   void (*offHandler)(void *hdl),
   void (*hdl)(kal_uint32 event, void *param))
{
   l1sp.strmOnHandler  = onHandler;
   l1sp.strmOffHandler = offHandler;
   l1sp.strmHdl        = hdl;
   //For MOLY00004781, sometimes auto script hit that register handler later than speech on. In this case, we let daca run.
   if( AM_IsSpeechOn() ){
      l1sp.strmOnHandler(NULL);
   }
}

void L1SP_UnRegister_Strm_Handler( void )
{
   if(AM_IsDataCardOn() && (l1sp.strmOffHandler != NULL)){
      /* Normal     Case: PLUGIN(RegisterHandler)-->SpeechOn(OnHandler)-->SpeechOff(OffHandler) -->PLUGOUT(UnRegisterHandler)
         Unexpected Case: PLUGIN(RegisterHandler)-->SpeechOn(OnHandler)-->PLUGOUT(UnRegisterHandler), registerHandler again -->SpeechOff(OffHandler)     */      
      DACA_Stop(DACA_APP_TYPE_ACTIVE_UL_DL_WB);   
   }
   l1sp.strmOnHandler  = NULL;
   l1sp.strmOffHandler = NULL;
}
#endif

#if defined(__ECALL_SUPPORT__)
void L1SP_Register_Pcm4WayService(void (*onHandler)(void *), void (*offHandler)(void *))
{
   l1sp.pcm4wayOnHandler = onHandler; 
   l1sp.pcm4wayOffHandler = offHandler;
}

void L1SP_UnRegister_Pcm4Way_Service( void )
{
   l1sp.pcm4wayOnHandler = NULL; 
   l1sp.pcm4wayOffHandler = NULL;
}
#endif

void L1SP_Speech_Off( void )
{
   kal_uint32 voc_ptn = TVCI_CLOSE_FILE;
   kal_uint32 *voc_ptn_ptr = &voc_ptn;

#if defined(__CVSD_CODEC_SUPPORT__) 
   if(BT_SCO_IS_SPEECH_ON())
   {
      BT_SCO_SPEECH_OFF();
   }
#endif
  
   if( !AM_IsSpeechOn() )
      return;

	// mute DL to prevent sound pushes to hardware buffer then causes noise. Sync with the end of speech unumte
	L1SP_MuteSpeaker(true);
		
#if !DATA_CARD_DISABLE_INTERNAL      
//FIXME: for phone call usage
#if defined(__DATA_CARD_SPEECH__)
   if (l1sp.strmOffHandler != NULL)
      l1sp.strmOffHandler( NULL );
#endif
#endif

#if defined(__ECALL_SUPPORT__)
   if (l1sp.pcm4wayOffHandler != NULL)
      l1sp.pcm4wayOffHandler( (void *)0 );
#endif

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

   SetSpeechEnhancement( false );

   #ifndef __L1_STANDALONE__ // avoid link error
   // kal_uint32 module_id = MOD_L1AUDIO_SPH_SRV;	   
   // if(!tst_trace_check_ps_filter_off(TRACE_GROUP_VM, &module_id, 0x2) && voc_flag)
   if(voc_flag)
   {
      tst_vc_response(TVCI_VM_LOGGING, (const kal_uint8*)voc_ptn_ptr, 4);
	  VMREC_Stop(true);
	  voc_flag = false;
   }
	#endif

   AM_SpeechOff(0);


#if defined( __UMTS_RAT__ )
   {
      uint8 state;
      state = l1sp.state;
      
      if(l1sp.state == L1SP_STATE_3G_SPEECH_ON || l1sp.interRAT
#ifdef __VIDEO_CALL_SUPPORT__
          || l1sp.state == L1SP_STATE_3G324M_SPEECH_ON
#endif
      ){
         L1SP_SetState(L1SP_STATE_3G_SPEECH_CLOSING);
      }
      sp3g_speech_close();
         
    /* only these cases should wait state, if only 2G happen, then return to idle */
      if( state == L1SP_STATE_3G_SPEECH_ON || l1sp.interRAT
#ifdef __VIDEO_CALL_SUPPORT__
          || state == L1SP_STATE_3G324M_SPEECH_ON
#endif
      ){
         //uint32 waitTime;
#ifdef __VIDEO_CALL_SUPPORT__
         if( state == L1SP_STATE_3G324M_SPEECH_ON )
            vt_SP3G_Callback( (kal_uint8)SP3G_CODEC_CLOSED, (void*)0);
         else
#endif
            CSR_SP3G_Callback(SP3G_CODEC_CLOSED, (void*)SP3G_Rab_Id());
         /*
         for(waitTime = 0 ; ; waitTime ++)
         {     
            if(l1sp.state == L1SP_STATE_3G_SPEECH_CLOSED)
               break;
            ASSERT(waitTime < 20);     
            kal_sleep_task(1);
         }*/
      }
   }
#endif
   L1SP_SetState( L1SP_STATE_IDLE );

#if defined(__VIBRATION_SPEAKER_SUPPORT__)
   VIBR_Vibration_Activate();
#endif

	//always unmute DSP uplink after speech off to keep the mute definition
	SP_MuteUlEnhResult(false);
	SP_MuteUlFromDiffPos(false, SP_MIC_MUTE_POS_FROM_ALL); 
	L1SP_MuteSpeaker(false);
	
   L1Audio_ClearFlag( l1sp.aud_id );
   L1Audio_FreeAudioID( l1sp.aud_id );
}

void L1SP_Set_DAI_Mode( uint8 mode )
{
	//this feature is phased out
}

void L1SP_SetAfeLoopback( bool enable )
{
#if ( defined( __CENTRALIZED_SLEEP_MANAGER__ )&& defined( MTK_SLEEP_ENABLE ))
   kal_uint16 aud_id = L1SP_GetAudID();
#endif         
   if( enable )
      AFE_TurnOnLoopback();
   else
      AFE_TurnOffLoopback();
#if ( defined( __CENTRALIZED_SLEEP_MANAGER__ )&& defined( MTK_SLEEP_ENABLE ))
   L1SP_FreeAudID(aud_id);
#endif      
}

void L1SP_SetFIR( bool enable )
{
   if( enable ){
		
#ifdef ANALOG_AFE_PATH_EXIST		
      AFE_TurnOnFIR( L1SP_SPEECH );
      AFE_TurnOnFIR( L1SP_VOICE );
#endif // ANALOG_AFE_PATH_EXIST		

   }else{
   
#ifdef ANALOG_AFE_PATH_EXIST   
      AFE_TurnOffFIR( L1SP_SPEECH );
      AFE_TurnOffFIR( L1SP_VOICE );
#endif //ANALOG_AFE_PATH_EXIST

   }
}

void l1sp_Write_Audio_Coefficients( const int16 in_coeff[45], const int16 out_coeff[45] )
{
#if ( defined( __CENTRALIZED_SLEEP_MANAGER__ )&& defined( MTK_SLEEP_ENABLE ))
   kal_uint16 aud_id = L1SP_GetAudID();
#endif   
   AM_WriteFirCoeffs( in_coeff, out_coeff );
#if ( defined( __CENTRALIZED_SLEEP_MANAGER__ )&& defined( MTK_SLEEP_ENABLE ))
   L1SP_FreeAudID(aud_id);
#endif   
}

void L1SP_Write_Audio_Coefficients_ByFirIndex( const uint8 inFirIndex, 
	const uint8 outOrIn2FirIndex)
{

	int16 inCoeff[NUM_FIR_COEFFS];
	int16 outOrIn2Coeff[NUM_FIR_COEFFS];
		
	if(inFirIndex == 0xff) {
		inCoeff[0] = 0x7fff;
		memset(&inCoeff[1], 0, (NUM_FIR_COEFFS-1)*sizeof(int16));
	} else {
		memcpy(inCoeff, l1sp.sph_allInFirCoeff[inFirIndex], (NUM_FIR_COEFFS)*sizeof(int16));		
	}

	if(outOrIn2FirIndex == 0xff) {
		outOrIn2Coeff[0] = 0x7fff;
		memset(&outOrIn2Coeff[1], 0, (NUM_FIR_COEFFS-1)*sizeof(int16));
	} else {
		memcpy(outOrIn2Coeff, l1sp.sph_allOutFirCoeff[outOrIn2FirIndex], (NUM_FIR_COEFFS)*sizeof(int16));		
	}

	l1sp_Write_Audio_Coefficients( inCoeff, outOrIn2Coeff );
	
}

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif



void L1SP_EnableSpeechEnhancement( bool enable )
{
   if(enable)
   {
      l1sp.spe_flag = true;
      SetSpeechEnhancement(true);
   }
   else 
   {
      SetSpeechEnhancement(false);
      l1sp.spe_flag = false;
   }      
}

void L1SP_LoadSpeechPara( void ) 
{
#if ( defined( __CENTRALIZED_SLEEP_MANAGER__ )&& defined( MTK_SLEEP_ENABLE ))
   kal_uint16 aud_id = L1SP_GetAudID();
#endif   
   SPE_LoadSpeechPara(l1sp.sph_c_para, l1sp.sph_m_para, l1sp.sph_v_para, l1sp.sph_m_paraWb);      
#if ( defined( __CENTRALIZED_SLEEP_MANAGER__ )&& defined( MTK_SLEEP_ENABLE ))
   L1SP_FreeAudID(aud_id);
#endif      
}

extern void spc_send_network_status_notify(void);

void l1sp_NetworkStatusNotification(void)
{
#if defined(__SMART_PHONE_MODEM__)     
   if(kal_if_lisr())
	   L1Audio_LSetEvent(l1sp.aud_id_network_status, NULL);
	else
	   L1Audio_SetEvent(l1sp.aud_id_network_status, NULL);
#endif	   
}

void L1SP_Init( void )
{
   l1sp.tch_state = KAL_FALSE;   
#ifdef SPH_CHIP_BACK_PHONECALL_USED
	l1sp.sph_mode = SPH_MODE_NORMAL;
#else
   l1sp.sph_mode = SPH_MODE_UNDEFINED;
#endif

#if (!defined(__SMART_PHONE_MODEM__)) && (!defined(__DATA_CARD_SPEECH__))
	ApAudSys_config();
#endif


   SP_SetForcedUnMuteController(L1SP_FORCEDUNMUTE_ALL, false);

   memset(&l1sp.sph_c_para, 0, NUM_COMMON_PARAS*sizeof(uint16));
   memset(&l1sp.sph_m_para, 0, NUM_MODE_PARAS*sizeof(uint16));
   memset(&l1sp.sph_v_para, 0, NUM_VOL_PARAS*sizeof(uint16));
	memset(&l1sp.sph_m_paraWb, 0, NUM_MODE_PARAS*sizeof(uint16));
   
#if defined(__DUAL_MIC_SUPPORT__) || defined(__SMART_PHONE_MODEM__)	
   memset(&l1sp.sph_dmnr_para, 0, NUM_DMNR_PARAM*sizeof(uint16));
#ifdef __AMRWB_LINK_SUPPORT__   
   memset(&l1sp.sph_wb_dmnr_para, 0, NUM_WB_DMNR_PARAM*sizeof(uint16));
#endif
#endif 

#ifdef ANALOG_AFE_PATH_EXIST
   l1sp.mic_volume = AFE_GetMicrophoneVolume(); // get initial value
#else
	l1sp.mic_volume = 0;
#endif

//#if defined(__BT_SUPPORT__)   
   l1sp.bt_on = false;
//#endif

#if defined( __UMTS_RAT__ )
   sp3g_init();
   l1sp.interRAT = false;
#endif

   SPE_Init();
   l1sp.spe_flag = true;
   l1sp.isDLMute = l1sp.isULMute = false;
   l1sp.codec_mute = true;
   l1sp.codec_mute_mode = L1SP_L4C_EVENT_NONE;
   l1sp.spe_state = 0;
   
   //default set the DMNR on
   l1sp.spe_app_mask = 0xffff;
   l1sp.spe_usr_mask = 0xffff;
	// TODO: loud speaker mode DMNR
	l1sp.spe_usr_sub_mask = 0x003E; // default value to turn on , sync with Sal_Enh_Dynamic_t bit wise definition
	
#if 0 // ANALOG_AFE_PATH_EXIST  
/* under construction !*/
/* under construction !*/
#endif
   // l1sp.pcmplayback_flag = KAL_FALSE; phase out
   l1sp.isEnableNotchFilter = false;

   
#if defined(__DATA_CARD_SPEECH__)
   l1sp.strmOnHandler  = NULL;
   l1sp.strmOffHandler = NULL;
   l1sp.strmHdl = NULL;
#endif      
#if defined(__ECALL_SUPPORT__)
   l1sp.pcm4wayOnHandler = NULL; 
   l1sp.pcm4wayOffHandler = NULL;
#endif
   L1SP_SetState(L1SP_STATE_IDLE);
#if defined(__SMART_PHONE_MODEM__)   
	l1sp.aud_id_network_status = L1Audio_GetAudioID();
	L1Audio_SetEventHandler(l1sp.aud_id_network_status, (L1Audio_EventHandler)spc_send_network_status_notify);  
#endif	

   l1sp.setNvramValuesFlag = 0;
   memset(l1sp.sph_allModePara, 0, NUM_SPH_MODE*NUM_MODE_PARAS*sizeof(uint16));
   memset(l1sp.sph_allInFirCoeff, 0, NUM_SPH_INPUT_FIR*NUM_FIR_COEFFS*sizeof(int16));
   memset(l1sp.sph_allOutFirCoeff, 0, NUM_SPH_OUTPUT_FIR*NUM_FIR_COEFFS*sizeof(int16));
   memset(l1sp.sph_allVolumePara, 0, 3*7*4*sizeof(uint16));
   
   l1sp.sph_selectedOutFirIndex = 0;
}
kal_bool L1SP_TCH_State( void )
{
   return l1sp.tch_state;
}

extern kal_uint32 SP3G_GetCodecMode(void);
// This is invoked by 2G L1D(LISR)
void L1SP_TCH_Notify( bool bOn )
{

   if( !bOn ){ // for 2G->3G handover, mute speech in case Speech_Off command too late to avoid noise
      L1Audio_Msg_TCH_NOTIFY(L1AUDIO_Str_onoff(0), L1Audio_Speech_State(l1sp.state));
      l1sp.tch_state = KAL_FALSE;
      //mute speech
#if defined( __UMTS_RAT__ )      
      if( SP3G_Rab_State() && l1sp.state != L1SP_STATE_3G_SPEECH_ON && l1sp.state != L1SP_STATE_IDLE){//3G->2G fail case, TCH will be off
         SP3G_Reset();
         AM_InterRAT_G2W(SP3G_GetCodecMode());
         L1SP_SetState( L1SP_STATE_3G_SPEECH_ON );
      }
#endif      
      //else if( l1sp.state == L1SP_STATE_2G_SPEECH_ON ) 
         // in case speech off first then TCH off notify.(2G only. If in 3G, then don't care)
         //*DP_SC_MUTE |= 0x0002;
   }
   else{
      L1Audio_Msg_TCH_NOTIFY(L1AUDIO_Str_onoff(1), L1Audio_Speech_State(l1sp.state));
      l1sp.tch_state = KAL_TRUE;
      //*DP_SC_MUTE &= ~0x0002;
#if defined( __UMTS_RAT__ )      
      if( l1sp.state == L1SP_STATE_3G_SPEECH_ON ){//3G->2G HO
         AM_InterRAT_W2G();
         L1SP_SetState( L1SP_STATE_2G_SPEECH_ON );
      }
#endif      
   }

}

void L1SP_SpeechLoopBackEnable(kal_bool fgEnable)
{
	 SAL_LBK_Codec(fgEnable);
}

//-----------------------------------------------------------------------------
// Line in related. Phase out
/* 

void LINEIN_SetOutputDevice( uint8 device )
{
   AFE_SetOutputDevice( L1SP_LINEIN, device );
}

void LINEIN_SetOutputVolume( uint8 volume1, int8 digital_gain_index )
{
   AFE_SetOutputVolume( L1SP_LINEIN, volume1, digital_gain_index );
}

void LINEIN_Open()
{

   if (!lineon_flag){
      ktLock();
#ifdef ANALOG_AFE_PATH_EXIST	      
      AFE_TurnOnSpeaker(L1SP_LINEIN);
#endif      
      lineon_flag = KAL_TRUE;
   }
}

void LINEIN_Close()
{
   if(lineon_flag){
#if defined(MT6252H) || defined(MT6252)
      AFE_SetGainFastRamp(KAL_TRUE);    
#endif

#ifdef ANALOG_AFE_PATH_EXIST	
      AFE_TurnOffSpeaker(L1SP_LINEIN);
#endif      

#if defined(MT6252H) || defined(MT6252)
      kal_sleep_task(3);
      AFE_SetGainFastRamp(KAL_FALSE);    
#endif

      ktUnlock();
      lineon_flag = KAL_FALSE;
   }
#if defined(__VIBRATION_SPEAKER_SUPPORT__)
   VIBR_Vibration_Activate();
#endif
}

void LINEIN_MuteSpeaker( bool mute )
{
   AFE_MuteSpeaker( L1SP_LINEIN, mute );
}

#if defined(__GAIN_TABLE_SUPPORT__)
void LINEIN_SetOutputGainControl( kal_uint32 gain ){
#ifdef ANALOG_AFE_PATH_EXIST
   AFE_SetOutputGainControl( L1SP_LINEIN, gain );
#endif    
}

void LINEIN_SetOutputGainControlDualPath( kal_uint32 ext_amp_gain ){
   AFE_SetOutputGainControlDualPath( L1SP_LINEIN, ext_amp_gain );
}
#endif
*/
//-----------------------------------------------------------------------------

void ABF_SetAcousticLoopback( kal_bool loopback )
{
   return;
}
kal_bool ABF_GetAcousticLoopbackStatus( void )
{
   return KAL_FALSE;
}


/* Just for Factory Usage */
void L1SP_AcousticLoopbackOn (void)
{
#if defined( __ACOUSTIC_LOOPBACK_SUPPORT__ )      
   AcousticLoopbackOn();
#endif   
}

/* Just for Factory Usage */
void L1SP_AcousticLoopbackOff (void)
{
#if defined( __ACOUSTIC_LOOPBACK_SUPPORT__ )         
   AcousticLoopbackOff();
#endif   
}

/* Just for Factory Usage */
void L1SP_AcousticLoopbackSpeechMode(kal_uint8 u1Mode)
{
#if defined( __ACOUSTIC_LOOPBACK_SUPPORT__ )   
   AcousticLoopbackSpeechMode(u1Mode);
#endif       
}

/* Just for Factory Usage */
kal_bool L1SP_AcousticLoopbackStatus(void)
{
#if defined( __ACOUSTIC_LOOPBACK_SUPPORT__ )
   AcousticLoopbackStatus();
#endif

   return KAL_FALSE;
}

/* Just for Factory Usage */
void L1SP_AcousticLoopbackBypassMode(kal_uint8 u1Mode)
{
#if defined( __ACOUSTIC_LOOPBACK_SUPPORT__ )   
   AcousticLoopbackBypassMode(u1Mode);
#endif    
}

/* Just for Factory Usage */
void L1SP_AcousticLoopbackLength (kal_uint32 u4Length)
{
#if defined( __ACOUSTIC_LOOPBACK_SUPPORT__ )   
   AcousticLoopbackLength(u4Length);
#endif   
}

void L1SP_MutePCMOuputPort ( kal_bool fMute )
{

}

//-----------------------------------------------------------------------------

void l1sp_setNotchFilterParam(int16 *param, bool is2In1Spk)
{
	AM_SetNotchFilterParam(param);
	l1sp.isEnableNotchFilter = true;
	l1sp.is2In1Spk = is2In1Spk;
}

void SP_L4C_SetEvent(L1SP_L4C_Event event, L1SP_L4C_Event_Mode mode)
{
   kal_trace(TRACE_INFO, L1SP_L4C_EVENT, event, mode, l1sp.codec_mute_mode);
   kal_trace(TRACE_INFO, L1SP_MUTE_CONTROL_STATUS, 0, l1sp.isULMute, l1sp.isDLMute, l1sp.codec_mute, l1sp.forcedUnmuteController);
   
   ASSERT( L1SP_L4C_EVENT_NONE == l1sp.codec_mute_mode || mode == l1sp.codec_mute_mode );
   
   switch(event){
   case L1SP_L4C_ESPEECH_0:
      ASSERT(!l1sp.codec_mute);
      l1sp.codec_mute = true;
      l1sp.codec_mute_mode = L1SP_L4C_EVENT_NONE;
      break;   
   case L1SP_L4C_ESPEECH_1:
      ASSERT(l1sp.codec_mute);
      l1sp.codec_mute = false;
      l1sp.codec_mute_mode = mode;
      break;      
   default:
      ASSERT(0);   
   }

   {   
#if ( defined( __CENTRALIZED_SLEEP_MANAGER__ )&& defined( MTK_SLEEP_ENABLE ))
   kal_uint16 aud_id = L1SP_GetAudID();
#endif      
   SP_MuteController();
#if ( defined( __CENTRALIZED_SLEEP_MANAGER__ )&& defined( MTK_SLEEP_ENABLE ))
   L1SP_FreeAudID(aud_id);
#endif  
   kal_trace(TRACE_INFO, L1SP_MUTE_CONTROL_STATUS, 1, l1sp.isULMute, l1sp.isDLMute, l1sp.codec_mute, l1sp.forcedUnmuteController);
   }
}

void SP_SetForcedUnMuteController(L1SP_FORCEDUNMUTE_BITMASK mask, bool b)
{
   kal_trace(TRACE_INFO, L1SP_FORCED_UNMUTE_CONTROLLER, l1sp.forcedUnmuteController, mask, b); 
   if(b){  
      l1sp.forcedUnmuteController |= mask;
   }else{
      l1sp.forcedUnmuteController &= (~mask);
   }
   kal_trace(TRACE_INFO, L1SP_FORCED_UNMUTE_CONTROLLER_1, l1sp.forcedUnmuteController); 
   
   {
#if ( defined( __CENTRALIZED_SLEEP_MANAGER__ )&& defined( MTK_SLEEP_ENABLE ))
   kal_uint16 aud_id = L1SP_GetAudID();
#endif      
   SP_MuteController();
#if ( defined( __CENTRALIZED_SLEEP_MANAGER__ )&& defined( MTK_SLEEP_ENABLE ))
   L1SP_FreeAudID(aud_id);
#endif     
   }
}
