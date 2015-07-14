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
 *   dcm.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file provides APIs to get device information 
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

#ifdef __MTK_TARGET__

#include "reg_base.h"
#include "config_hw.h"
#include "init.h"
#include "cp15.h"
#include "us_timer.h"
#include "drv_comm.h"
#include "emi_hw.h"
#include "emi_sw.h"
#include "dma_hw.h"
#include "drvpdn.h"
#include "dcm.h"
#include "pll.h"
#include "us_timer.h"

#include "l1_interface.h"
#if defined(__CENTRALIZED_SLEEP_MANAGER__) && defined(__EVENT_BASED_TIMER__) && defined(MTK_SLEEP_ENABLE)
#include "ostd_public.h"
#endif

#include "kal_public_defs.h" //MSBB change #include "stack_config.h"
#include "kal_trace.h"

#include "kal_public_defs.h"

#include "kal_general_types.h"
#include "kal_internal_api.h"
#include "kal_public_api.h"

#include "SST_sla.h"
#include "system_trc.h"



#if defined (__MODEM_CCCI_EXIST__)
//debug purpose for MT6589 modem sys has no response
#include "ccci.h"
#endif //__MODEM_CCCI_EXIST__

#if defined(_MSC_VER) && (_MSC_VER >= 1500)
#define __SECTION__(name)
#define __ZI__ 
#else //#if defined(_MSC_VER) && (_MSC_VER >= 1500)
#if defined (__SECTION__)
#undef __SECTION__
#endif //#if defined (__SECTION__)
#define __SECTION__(name) __attribute__ ((section (#name)))
#define __ZI__          __attribute__ ((zero_init))
#endif ////#if defined(_MSC_VER) && (_MSC_VER >= 1500)

/*
 * NoteXXX: SaveAndSetIRQMask()/RestoreIRQMask() are APIs for appilcations to disable/restore
 *          IRQ. They will restrict the disable duration. But idle task disables IRQ for a 
 *          time due to DCM. Thus LockIRQ()/RestoreIRQ() are used here. Only the idle task
 *          can use them!! Other applications are not allowed to use LockIRQ()/RestoreIRQ().
 */
kal_uint32 LockIRQ(void);
void RestoreIRQ(kal_uint32);

extern void dormant_mode_activate(void);
extern void dormant_mode_init(void);
extern kal_bool OSTD_Allow_Dormant_Mode(void);
//#pragma arm section rwdata = "INTSRAM_RW" , rodata = "INTSRAM_RODATA" , zidata = "INTSRAM_ZI"

extern kal_uint32 dcm_mcubus_dcm_off;

volatile static kal_uint32 WFI_Handle_Count __SECTION__(INTSRAM_RW) =0 ;

volatile static kal_bool OST_ReadyToSlept __SECTION__(INTSRAM_RW) = KAL_FALSE;
volatile static kal_bool OST_AllowedToPowerDown __SECTION__(INTSRAM_RW)= KAL_FALSE;

volatile static kal_bool pll_save_mode_enabled __SECTION__(INTSRAM_RW) = KAL_FALSE;


#if defined( DCM_ENABLE )
 
kal_uint32 SaveAndSetIRQMask(void);
void RestoreIRQMask(kal_uint32);
void _mt6589_dcm_init(void);
int _dcm_hw_setting(kal_int32 on);

volatile static kal_int32 dcm_state __SECTION__(INTSRAM_RW) = -1;
volatile static kal_bool dcm_excuted __SECTION__(INTSRAM_RW) = KAL_FALSE;

#if defined(DCM_AUDIO_DSP_LOWPOWER_V2_SUPPORT)
volatile static kal_bool dcm_lpaudio_mode __SECTION__(INTSRAM_RW)  = KAL_FALSE;        /* Added for LP AUDIO */
volatile static kal_uint32 dcm_lpaudio_cnt __SECTION__(INTSRAM_RW)  = 0;
#endif /* DCM_AUDIO_DSP_LOWPOWER_V2_SUPPORT */

#if defined(__MTK_INTERNAL__)
/* under construction !*/
#if defined(__USE_HW_DCM_CYCLE_COUNTER__)
/* under construction !*/
#endif
#endif //__MTK_INTERNAL__

 /* dcm_state = 0, 104/52 MHz.
                1, 104/52->13/26 MHz transition.
                2, 13/26 Mhz.
                3, 13/26->104/52 MHz transition. */
static struct 
{
   kal_uint32   dcmForceDisalbe;
   kal_uint8   	dcmHandleCount;
   kal_uint32   dcmDisable;					/* Default not disable DCM */
   
   #if defined(__CENTRALIZED_SLEEP_MANAGER__) && defined(__EVENT_BASED_TIMER__) && defined(MTK_SLEEP_ENABLE)
   kal_bool OST_ReadyToSlept;
   Sleep_Time allow_sleep_dur;
   #endif
} dcm __SECTION__(INTSRAM_ZI) __ZI__; 
 
extern int custom_DynamicClockSwitch(mcu_clock_enum clock);
extern int custom_SFIDynamicClockSwitch_Init(void);
extern int custom_EMIDynamicClockSwitch_Init(void);

extern ECO_VERSION INT_ecoVersion(void);

void WFI_Disable( void )
{
   kal_uint32 _savedMask;
   _savedMask = SaveAndSetIRQMask();
   WFI_Handle_Count++;
   RestoreIRQMask(_savedMask);
}

void WFI_Enable( void )
{
   kal_uint32 _savedMask;
   _savedMask = SaveAndSetIRQMask();
   if( WFI_Handle_Count > 0 )
       WFI_Handle_Count--;
   RestoreIRQMask(_savedMask);
}



kal_bool DCM_Query_Status(void)
{
   kal_bool status = dcm_excuted;
   dcm_excuted = KAL_FALSE;/* Restored to default state */
   return status;
} 
kal_uint8 DCM_GetHandle( void )
{	
   ASSERT(dcm.dcmHandleCount<32);
   return dcm.dcmHandleCount++;   /* Using handle number from 0, not 1 */
}


void DCM_Enable( kal_uint8 handle )
{   
   kal_uint32 _savedMask;
   
   _savedMask = SaveAndSetIRQMask();
   dcm.dcmDisable &= ~(1 << handle);   
   if (dcm_state == -1) {
       RestoreIRQMask(_savedMask);
       return;
   }

   #if defined(__HW_DCM__)
   if(0 == dcm.dcmDisable)
   {
       #if defined(MT6575) || defined (MT6577)
       *DCM_RG_CK_DCM_EN |= 0xF; // MDMCU, bus, DCM enable
       #elif defined(MT6589) || defined(MT6572) || defined (MT6582) || defined (MT6592) || defined (MT6571) || defined(MT6580)
	   _dcm_hw_setting(1);

       #elif defined(MT6280)
       #if defined (__TRADITIONAL_MODEM_CARD__)  || defined (__SDIO_DEVICE_CONNECTIVITY__)
       *AP_DCM_CON_0 |= 0x70000;
       *AP_DCM_CON_0 |= 1;

       //usb dcm off, and set clock-gating for h0/h1/h2
       // nfi/hif/nli have to disable, due to buggy design with no nfi idle signal for dcm.
       *AP_PWR_DCM_DEBUG_CON1 = 0x7FFF & ~((1<<4) | (7<<12) | (7<<1));  
       *AP_NONPWR_DCM_DEBUG_CON1 = 0xF;

       ///APMCU , divided by 3 to get 80Mhz
	   // no APMCU DCM 

       /// AP infra bus dcm divider
	   // move to DCM_Prerequisite() 
	   // *AP_DCM_CON_1 = reg_aor(*AP_DCM_CON_1, ~((0x1F << 8) | (0x1F << 24)), ((HSAPBUS_FSEL << 8)|(1 << 24)));    

        ///EMI
        *EMI_DCM_CON_0 = reg_aor(*EMI_DCM_CON_0, ~(0x1F | (0x1f<<8) | (0x7f<<16)), (0x0f<<8) | (1<<24) | (0x0f<<16) | (1<<25));
        *EMI_DCM_CON_1 = reg_or(*EMI_DCM_CON_1, 0x1f);
        *EMI_DCM_CON_1 = reg_and(*EMI_DCM_CON_1, ~(1<<5));
        *EMI_DCM_CON_1 = reg_or(*EMI_DCM_CON_1, (1 << 5));
        *EMI_DCM_CON_1 = reg_and(*EMI_DCM_CON_1, ~(1<<5));
       #endif //#if defined (__TRADITIONAL_MODEM_CARD__)  || defined (__SDIO_DEVICE_CONNECTIVITY__)

       //here is a workaround for NT6280E1, to disable emi-axi dcm for prefetch buffer control
       *PWR_DCM_DEBUG_CON1 = reg_aor(0x0057 | ((1 << 20) | (0xF << 16)), ~(1<<7), (0 != dcm_mcubus_dcm_off) ? (1<<7) : 0); //0x4057; 

       *NONPWR_DCM_DEBUG_CON2 = 0x38; //=0x1b8;


       ///MDBUS
       *MDBUS_DCM_CON_0 = reg_aor(*MDBUS_DCM_CON_0, ~(0x1F | (0x1f<<8) | (0x7f<<16)), (0x0f<<8) | (1<<24) | (0x0f<<16) | (1<<25));
       *MDBUS_DCM_CON_1 = reg_or(*MDBUS_DCM_CON_1, 0x1F);
       *MDBUS_DCM_CON_1 = reg_and(*MDBUS_DCM_CON_1, ~(1<<5));
       *MDBUS_DCM_CON_1 = reg_or(*MDBUS_DCM_CON_1, (1 << 5));
       *MDBUS_DCM_CON_1 = reg_and(*MDBUS_DCM_CON_1, ~(1<<5));

       ///MDMCU
        *MDMCU_DCM_CON_0 = reg_aor(*MDMCU_DCM_CON_0, ~(0x1F | (0x7f<<16)), (0x1f<<8) | (1<<24) | (0x0f<<16) | (1<<25));
        *MDMCU_DCM_CON_1 = reg_or(*MDMCU_DCM_CON_1, 0x1F);
        *MDMCU_DCM_CON_1 = reg_and(*MDMCU_DCM_CON_1, ~(1<<5));
        *MDMCU_DCM_CON_1 = reg_or(*MDMCU_DCM_CON_1, (1 << 5));
        *MDMCU_DCM_CON_1 = reg_and(*MDMCU_DCM_CON_1, ~(1<<5));

        ///PWR domain
        *PWR_GLOBAL_CON1 = reg_aor(*PWR_GLOBAL_CON1, 
                                   ~(0x1f | (0x1f<<5) | (0x1f<<10) | (0x1f<<15) | (0x7f<<22)), 
                                   0x10 | (0x8<<5) | (1<<10) | (1<<15) | (0x0f<<22) | (1<<20) | (1<<21) | (1<<29));

       #endif
   }
   #endif  
   RestoreIRQMask(_savedMask);
}
void DCM_Disable( kal_uint8 handle )
{
   kal_uint32 _savedMask;
   
   _savedMask = SaveAndSetIRQMask();
   dcm.dcmDisable |= (1 << handle);
   if (dcm_state == -1) {
       RestoreIRQMask(_savedMask);
       return;
   }

   #if defined(__HW_DCM__)
   #if defined(MT6575) || defined (MT6577)
   *DCM_RG_CK_DCM_EN &= ~(0xF); // MDMCU, bus, DCM disable
   #elif defined(MT6589) || defined (MT6572) || defined (MT6582) || defined (MT6592) || defined (MT6571) || defined(MT6580)
   _dcm_hw_setting(0);

   #elif defined(MT6280)

   #if defined (__TRADITIONAL_MODEM_CARD__)  || defined (__SDIO_DEVICE_CONNECTIVITY__)
   *AP_DCM_CON_0 = reg_and(*AP_DCM_CON_0, 1<<16); 
   *AP_PWR_DCM_DEBUG_CON1 = 0; //dcm_ap_pwr; //0x7FFF & ~(1<<4);  //usb dcm off
   *AP_NONPWR_DCM_DEBUG_CON1 = 0; //dcm_ap_nonpwr; //0xF;

   ///EMI
   *EMI_DCM_CON_0 = reg_aor(*EMI_DCM_CON_0, ~((1<<24)), 0);
   *EMI_DCM_CON_1 = reg_or(*EMI_DCM_CON_1, 0x1<<1);
   *EMI_DCM_CON_1 = reg_and(*EMI_DCM_CON_1, ~(1<<5));
   *EMI_DCM_CON_1 = reg_or(*EMI_DCM_CON_1, (1 << 5));
   *EMI_DCM_CON_1 = reg_and(*EMI_DCM_CON_1, ~(1<<5));

   #endif //   #if defined (__TRADITIONAL_MODEM_CARD__)  || defined (__SDIO_DEVICE_CONNECTIVITY__)

   *PWR_DCM_DEBUG_CON1 = 0x3f80; 
   *NONPWR_DCM_DEBUG_CON2 = 0; //0x38; //=0x1b8;
   
   ///MDBUS
   *MDBUS_DCM_CON_0 = reg_aor(*MDBUS_DCM_CON_0, ~((1<<24)), 0);
   *MDBUS_DCM_CON_1 = reg_or(*MDBUS_DCM_CON_1, 0x1<<1);
   *MDBUS_DCM_CON_1 = reg_and(*MDBUS_DCM_CON_1, ~(1<<5));
   *MDBUS_DCM_CON_1 = reg_or(*MDBUS_DCM_CON_1, (1 << 5));
   *MDBUS_DCM_CON_1 = reg_and(*MDBUS_DCM_CON_1, ~(1<<5));

   ///MDMCU
   *MDMCU_DCM_CON_0 = reg_aor(*MDMCU_DCM_CON_0, ~((1<<24)), 0);
   *MDMCU_DCM_CON_1 = reg_or(*MDMCU_DCM_CON_1, 0x1<<1);
   *MDMCU_DCM_CON_1 = reg_and(*MDMCU_DCM_CON_1, ~(1<<5));
   *MDMCU_DCM_CON_1 = reg_or(*MDMCU_DCM_CON_1, (1 << 5));
   *MDMCU_DCM_CON_1 = reg_and(*MDMCU_DCM_CON_1, ~(1<<5));

   ///PWR domain
   *PWR_GLOBAL_CON1 = reg_aor(*PWR_GLOBAL_CON1, ~((1<<20)), 0);

   #endif
   #endif  
   RestoreIRQMask(_savedMask);
}

 
#if defined(__MTK_INTERNAL__) && defined (DCM_LPM_ENABLE)
#if defined (MT6280)
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
    #if defined (__TRADITIONAL_MODEM_CARD__)  || defined (__SDIO_DEVICE_CONNECTIVITY__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif //#if defined (__TRADITIONAL_MODEM_CARD__)  || defined (__SDIO_DEVICE_CONNECTIVITY__)
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
#if defined (__TRADITIONAL_MODEM_CARD__)  || defined (__SDIO_DEVICE_CONNECTIVITY__)
/* under construction !*/
/* under construction !*/
#endif //#if defined (__TRADITIONAL_MODEM_CARD__)  || defined (__SDIO_DEVICE_CONNECTIVITY__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined (__TRADITIONAL_MODEM_CARD__) || defined (__SDIO_DEVICE_CONNECTIVITY__)
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
#endif //#if defined (__TRADITIONAL_MODEM_CARD__)  || defined (__SDIO_DEVICE_CONNECTIVITY__)
/* under construction !*/
#if 0
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
#if defined (__TRADITIONAL_MODEM_CARD__)  || defined (__SDIO_DEVICE_CONNECTIVITY__)
/* under construction !*/
/* under construction !*/
#endif //#if defined (__TRADITIONAL_MODEM_CARD__)  || defined (__SDIO_DEVICE_CONNECTIVITY__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#elif defined (MT6589) 
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
#if 0 //this is for TOP LPM
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
#endif //#if 0
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
#elif defined(MT6572) || defined (MT6582) || defined (MT6592) || defined (MT6571) || defined(MT6580)
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
#if 0 //32k
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else //pll
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if 0 //32k
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
#else
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif //#if defined (MT6280)
#endif //__MTK_INTERNAL__          		  

#if (defined (MT6589) && !defined (__MD2__)) || defined (MT6572) || defined (MT6582) || defined (MT6592) || defined (MT6571) || defined(MT6580)
void DCM_Recovery(void)  __SECTION__(INTSRAM_ROCODE);
#endif //#if (defined (MT6589) && !defined (__MD2__)) || defined (MT6572) || defined (MT6592) || defined (MT6571) || defined(MT6580)
void Enter_DCM_mode(void);
void Leave_DCM_mode(void);

void DCM_Recovery(void)
{  
#if !defined(__HW_DCM__)
   /* UnGateDG */
   if( dcm_state == 2 ) 
   {
      dcm_state = 3; /* DCM @ 13/26->104/52MHz */
                                  
      /* I_Bit is disabled and Wait until EMI access is complete.
         Otherwise, some external(Burst/Async/Sync RAM), some will get problems. */
      EMI_Dummy_Read();
      /*A26=1 means will not get data via data cache, it will access EMI directly.*/
	  /* Change WS and clock rate. */
	  //custom_DynamicClockSwitch( MCU_xxxMHZ );

      #if defined(DCM_AUDIO_DSP_LOWPOWER_V2_SUPPORT)
        /* If we use SWDCM for Low Power Audio mode, we need to enable H/W DCM back */
      if(dcm_lpaudio_mode)
      {
          dcm_lpaudio_mode = KAL_FALSE;
      }
      #endif /* DCM_AUDIO_DSP_LOWPOWER_V2_SUPPORT */
      
      dcm_state = 0; /* DCM @ 104/52MHz */
      dcm_excuted = KAL_TRUE;/* Record the execution of DCM and print in L1SM_FrameTick */
   }
#else

   if(dcm_state == 2)
   {
       dcm_state = 3;

       #if defined(DCM_AUDIO_DSP_LOWPOWER_V2_SUPPORT)
         /* If we use SWDCM for Low Power Audio mode, we need to enable H/W DCM back */
       if(dcm_lpaudio_mode)
       {
            /*
             * Clear the Low Power Audio flag as we're going back to normal mode
             */
            dcm_lpaudio_mode = KAL_FALSE;
            
            /*
             * Enable HWDCM
             */
       }

       #else /* !DCM_AUDIO_DSP_LOWPOWER_V2_SUPPORT */

       /* Work around for MT6276E1, DCM_IRQ_CLR_EN can not be set */
       #if defined(MT6573)

       #ifndef __SMART_PHONE_MODEM__
       *DCM_RG_CK_DCM_EN &= ~(0x3);
       #endif /* __SMART_PHONE_MODEM__ */

       *DCM_MDARM_DCM_EN &= ~(0x3);
       *DCM_MDARM_CCTL |= ~(0xFFFFFEFF);

       #endif /* MT6573*/

       #endif  /* DCM_AUDIO_DSP_LOWPOWER_V2_SUPPORT */

       dcm_state = 0;
       dcm_excuted = KAL_TRUE;/* Record the execution of DCM and print in L1SM_FrameTick */
   }
#endif //!_HW_DCM__   
}


#else /* DCM_ENABLE */

kal_bool DCM_Query_Status(void) 
{
	return KAL_FALSE;
}
kal_uint8 DCM_GetHandle( void ) 
{
	return 0;
}
void DCM_Enable( kal_uint8 handle ) {}
void DCM_Disable( kal_uint8 handle ) {}

void DCM_IsIdleMode(kal_bool isCurMode) {}
void DCM_ForceDCM26MHz(kal_bool isDCM26MHz) {}

#endif /* DCM_ENABLE */


#if defined (MT6589)
/* only init the fsel/fdiv */
void _mt6589_dcm_init(void)
{
	//enabel MCU_bus/MCU_mcu/BUS_g0/BUS_g1 DCM (clk_off, the only supported in E1).
	//note: even the MCU_bus/MCU_mcu is de-featured in E1, the setting is no change else.
	*MD_GLOBAL_CON1 = reg_aor(*MD_GLOBAL_CON1, ~0x0fffff, 0x08910);
	// top MDMCU DCM
	//TOP MDMCU DCM has 1 bug, that fsel can not be changed.
	*MD_TOP_MDMCU_DCM_CON0 = reg_aor(*MD_TOP_MDMCU_DCM_CON0,  ~((0x1f<<8) | (0x1f<<0)), 0);
	*MD_TOP_MDMCU_DCM_CON1 = reg_aor(*MD_TOP_MDMCU_DCM_CON1, ~(0x1f<<0), (0x18<<0)); //set idle_fsel/fsel toggle sel
	*MD_TOP_MDMCU_DCM_CON1 = reg_and(*MD_TOP_MDMCU_DCM_CON1, ~(1<<5)); //toggle 0
	*MD_TOP_MDMCU_DCM_CON1 = reg_or(*MD_TOP_MDMCU_DCM_CON1, (1<<5)); //toggle 1
	*MD_TOP_MDMCU_DCM_CON1 = reg_and(*MD_TOP_MDMCU_DCM_CON1, ~(1<<5)); //toggle 0
	// top MDBUS DCM  (even this is defeatureed in E1)
///	*MD_TOP_MDBUS_DCM_CON0 = reg_aor(*MD_TOP_MDBUS_DCM_CON0, ~((0x1f<<8) | (0x1f<<0)), 0x10<<0);
	*MD_TOP_MDBUS_DCM_CON1 = reg_aor(*MD_TOP_MDBUS_DCM_CON1, ~(0x1f<<0), (0x18<<0)); //set idle_fsel/fsel toggle sel
	*MD_TOP_MDBUS_DCM_CON1 = reg_and(*MD_TOP_MDBUS_DCM_CON1, ~(1<<5)); //toggle 0
	*MD_TOP_MDBUS_DCM_CON1 = reg_or(*MD_TOP_MDBUS_DCM_CON1, (1<<5)); //toggle 1
	*MD_TOP_MDBUS_DCM_CON1 = reg_and(*MD_TOP_MDBUS_DCM_CON1, ~(1<<5)); //toggle 0
}


int _dcm_hw_setting(kal_int32 on)
{
	if (on != 0) {
	   //enabel MCU_bus/MCU_mcu/BUS_g0/BUS_g1 DCM (clk_off, the only supported in E1).
	   //note: even the MCU_bus/MCU_mcu is de-featured in E1, the setting is no change else.
	   *MD_GLOBAL_CON1 = reg_aor(*MD_GLOBAL_CON1, ~(0x0f<<22), ((0 != dcm_mcubus_dcm_off) ? (1<<25) : 0) | (1<<24) | (1<<23) | (1<<22));
	   // top MDMCU DCM
	   /** Astone, to disable TOP_MDMCU DCM.
		* because a 'protect' ACK signal will be block, while DCM activates. 
		* Thus sleep mode will fail.
		**/
	   /* *MD_TOP_MDMCU_DCM_CON0 |= (1<<24) ;  */
	   *MD_TOP_MDMCU_DCM_CON1 = reg_aor(*MD_TOP_MDMCU_DCM_CON1, ~(0x1f<<0), (0x1<<1)); //set dcm_en toggle sel
	   *MD_TOP_MDMCU_DCM_CON1 = reg_and(*MD_TOP_MDMCU_DCM_CON1, ~(1<<5)); //toggle 0
	   *MD_TOP_MDMCU_DCM_CON1 = reg_or(*MD_TOP_MDMCU_DCM_CON1, (1<<5)); //toggle 1
	   *MD_TOP_MDMCU_DCM_CON1 = reg_and(*MD_TOP_MDMCU_DCM_CON1, ~(1<<5)); //toggle 0
	   // top MDBUS DCM  (even this is defeatureed in E1)
///	   *MD_TOP_MDBUS_DCM_CON0 |= (1<<24) ; 
	   *MD_TOP_MDBUS_DCM_CON1 = reg_aor(*MD_TOP_MDBUS_DCM_CON1, ~(0x1f<<0), (1<<1)); //set dcm_en toggle sel
	   *MD_TOP_MDBUS_DCM_CON1 = reg_and(*MD_TOP_MDBUS_DCM_CON1, ~(1<<5)); //toggle 0
	   *MD_TOP_MDBUS_DCM_CON1 = reg_or(*MD_TOP_MDBUS_DCM_CON1, (1<<5)); //toggle 1
	   *MD_TOP_MDBUS_DCM_CON1 = reg_and(*MD_TOP_MDBUS_DCM_CON1, ~(1<<5)); //toggle 0
	}
	else {
		//disable MCU_bus/MCU_mcu/BUS_g0/BUS_g1 DCM
		//note: even the MCU_bus/MCU_mcu is de-featured in E1, the setting is no change else.
		*MD_GLOBAL_CON1 = reg_and(*MD_GLOBAL_CON1, ~((1<<25) | (1<<24) | (1<<23) | (1<<22))); 
		// top MDMCU DCM
		*MD_TOP_MDMCU_DCM_CON0 = reg_and(*MD_TOP_MDMCU_DCM_CON0, ~(1<<24)); 
		*MD_TOP_MDMCU_DCM_CON1 = reg_aor(*MD_TOP_MDMCU_DCM_CON1, ~(0x1f<<0), (1<<1)); //set dcm_en toggle sel
		*MD_TOP_MDMCU_DCM_CON1 = reg_and(*MD_TOP_MDMCU_DCM_CON1, ~(1<<5)); //toggle 0
		*MD_TOP_MDMCU_DCM_CON1 = reg_or(*MD_TOP_MDMCU_DCM_CON1, (1<<5)); //toggle 1
		*MD_TOP_MDMCU_DCM_CON1 = reg_and(*MD_TOP_MDMCU_DCM_CON1, ~(1<<5)); //toggle 0
		// top MDBUS DCM  (even this is defeatureed in E1)
		*MD_TOP_MDBUS_DCM_CON0 = reg_and(*MD_TOP_MDBUS_DCM_CON0, ~(1<<24)); 
		*MD_TOP_MDBUS_DCM_CON1 = reg_aor(*MD_TOP_MDBUS_DCM_CON1, ~(0x1f<<0), (1<<1)); //set dcm_en toggle sel
		*MD_TOP_MDBUS_DCM_CON1 = reg_and(*MD_TOP_MDBUS_DCM_CON1, ~(1<<5)); //toggle 0
		*MD_TOP_MDBUS_DCM_CON1 = reg_or(*MD_TOP_MDBUS_DCM_CON1, (1<<5)); //toggle 1
		*MD_TOP_MDBUS_DCM_CON1 = reg_and(*MD_TOP_MDBUS_DCM_CON1, ~(1<<5)); //toggle 0
	}

	return 0;
}
#elif defined (MT6572) || defined (MT6582) || defined (MT6592) || defined (MT6571) || defined(MT6580)

void _dcm_hw_top_mcu_dcm(int on)
{	
	if (on != 0) {
        // MD Level-1 DCM Enable
        *MD_TOP_MDMCU_DCM_CON0 = 0x030F0F00;
        *MD_TOP_MDMCU_DCM_CON1 = 0x3F;
        *MD_TOP_MDMCU_DCM_CON1 = reg_and(*MD_TOP_MDMCU_DCM_CON1, ~(1<<5));
        *MD_TOP_MDMCU_DCM_CON1 = reg_or(*MD_TOP_MDMCU_DCM_CON1, (1<<5));
        *MD_TOP_MDMCU_DCM_CON1 = reg_and(*MD_TOP_MDMCU_DCM_CON1, ~(1<<5));
	}
	else {
        // MD Level-1 DCM Disable
        *MD_TOP_MDMCU_DCM_CON0 = reg_and(*MD_TOP_MDMCU_DCM_CON0, ~(1<<24));
        *MD_TOP_MDMCU_DCM_CON1 = (1<<5) | (1<<1); //only dcm_en toggle
        *MD_TOP_MDMCU_DCM_CON1 = reg_and(*MD_TOP_MDMCU_DCM_CON1, ~(1<<5));
        *MD_TOP_MDMCU_DCM_CON1 = reg_or(*MD_TOP_MDMCU_DCM_CON1, (1<<5));
        *MD_TOP_MDMCU_DCM_CON1 = reg_and(*MD_TOP_MDMCU_DCM_CON1, ~(1<<5));
	}
}

void _dcm_hw_init(void)
{
    _dcm_hw_setting(1);
}

int _dcm_hw_setting(kal_int32 on)
{
    if (on != 0) { 
        /** 
         * DCM enable sequence:  level-2 DCM enable, then level-1 DCM enable
         **/

        // MD Level-2 DCM Enable
        *MD_GLOBAL_CON1 = reg_or(*MD_GLOBAL_CON1, (1<<25)|(1<<24)|(1<<23)|(1<<22)|(3<<20));
        #if defined (MT6572) || defined (MT6582) || defined (MT6592)
        // Although this module-slow-down feature only works on MT6571, but it's set on
        // MT6572/MT6582/MT6592 golden setting, so keep it set on them.
        // Remove this feature on MT6571 due to topsm f32k edge sample issue,
        // which is discovered in MOLY00041024
        // [2014-1221] MT6580 apply the same setting
        *MD_GLOBAL_SET0 = (1<<31)|(1<<30);
        #endif

        // MD Level-1 DCM Enable
        *MD_TOP_MDMCU_DCM_CON0 = 0x030F0F00;
        *MD_TOP_MDMCU_DCM_CON1 = 0x3F;
        *MD_TOP_MDMCU_DCM_CON1 = reg_and(*MD_TOP_MDMCU_DCM_CON1, ~(1<<5));
        *MD_TOP_MDMCU_DCM_CON1 = reg_or(*MD_TOP_MDMCU_DCM_CON1, (1<<5));
        *MD_TOP_MDMCU_DCM_CON1 = reg_and(*MD_TOP_MDMCU_DCM_CON1, ~(1<<5));

        *MD_TOP_MDBUS_DCM_CON0 = 0x030F0F00;
        *MD_TOP_MDBUS_DCM_CON1 = 0x3F;
        *MD_TOP_MDBUS_DCM_CON1 = reg_and(*MD_TOP_MDBUS_DCM_CON1, ~(1<<5));
        *MD_TOP_MDBUS_DCM_CON1 = reg_or(*MD_TOP_MDBUS_DCM_CON1, (1<<5));
        *MD_TOP_MDBUS_DCM_CON1 = reg_and(*MD_TOP_MDBUS_DCM_CON1, ~(1<<5));
    }
    else {
        /** 
         * DCM disable sequence: level-1 Bus DCM disable, then level-2 Bus DCM disable
         **/

        // MD Level-1 DCM Disable
        *MD_TOP_MDMCU_DCM_CON0 = reg_and(*MD_TOP_MDMCU_DCM_CON0, ~(1<<24));
        *MD_TOP_MDMCU_DCM_CON1 = (1<<5) | (1<<1); //only dcm_en toggle
        *MD_TOP_MDMCU_DCM_CON1 = reg_and(*MD_TOP_MDMCU_DCM_CON1, ~(1<<5));
        *MD_TOP_MDMCU_DCM_CON1 = reg_or(*MD_TOP_MDMCU_DCM_CON1, (1<<5));
        *MD_TOP_MDMCU_DCM_CON1 = reg_and(*MD_TOP_MDMCU_DCM_CON1, ~(1<<5));

        *MD_TOP_MDBUS_DCM_CON0 = reg_and(*MD_TOP_MDBUS_DCM_CON0, ~(1<<24));
        *MD_TOP_MDBUS_DCM_CON1 = (1<<5) | (1<<1);
        *MD_TOP_MDBUS_DCM_CON1 = reg_and(*MD_TOP_MDBUS_DCM_CON1, ~(1<<5));
        *MD_TOP_MDBUS_DCM_CON1 = reg_or(*MD_TOP_MDBUS_DCM_CON1, (1<<5));
        *MD_TOP_MDBUS_DCM_CON1 = reg_and(*MD_TOP_MDBUS_DCM_CON1, ~(1<<5));

        // MD Level-2 DCM Disable
        *MD_GLOBAL_CON1 = reg_and(*MD_GLOBAL_CON1, ~((1<<25)|(1<<24)|(1<<23)|(1<<22)|(3<<20)));
        #if defined (MT6572) || defined (MT6582) || defined (MT6592)
        // Although this module-slow-down feature only works on MT6571, but it's set on
        // MT6572/MT6582/MT6592 golden setting, so keep it set on them.
        // Remove this feature on MT6571 due to topsm f32k edge sample issue,
        // which is discovered in MOLY00041024
        // [2014-1221] MT6580 apply the same setting
        *MD_GLOBAL_CLR0 = (1<<31)|(1<<30);  
        #endif
    }

	return 0;
}
#endif //#if defined (MT6589)


void Enter_DCM_mode(void)
{
    #if defined(MT6575) || defined (MT6577)
    *DCM_RG_CK_DCM_EN = 0xF; // MDMCU, bus, DCM enable
    *DCM_RG_CK_DCM_DSP_EN = 0xF; //DSP, bus, DCM enable

    #elif defined(MT6589)
	_mt6589_dcm_init();

	_dcm_hw_setting(1);

    #elif defined(MT6572) || defined (MT6582) || defined (MT6592) || defined (MT6571) || defined(MT6580)
	_dcm_hw_setting(1);


    #elif defined(MT6280)
#if defined (__TRADITIONAL_MODEM_CARD__)  || defined (__SDIO_DEVICE_CONNECTIVITY__)
    
    *AP_DCM_CON_0 |= 0x70000;
    *AP_DCM_CON_0 |= 1;

    //usb dcm off, and set clock-gating for h0/h1/h2
    // nfi/hif/nli have to disable, due to buggy design with no nfi idle signal for dcm.
    *AP_PWR_DCM_DEBUG_CON1 = 0x7FFF & ~((1<<4) | (0x07<<12) | (7<<1)); 
    *AP_NONPWR_DCM_DEBUG_CON1 = 0xF;

    /// MPLL should be 320Mhz.
    ///APMCU , divided by 3 to get 80Mhz
	// setup within DCM_Prerequisite()



    /// ap infra, setup within DCM_Prerequisite()
    //*AP_DCM_CON_1 = reg_aor(*AP_DCM_CON_1, ~((0x1F << 8) | (0x1F << 24)), ((HSAPBUS_FSEL << 8)|(1 << 24)));    

    ///EMI
    *EMI_DCM_CON_0 = reg_aor(*EMI_DCM_CON_0, ~(0x1F | (0x1f<<8) | (0x7f<<16)), (0x0f<<8) | (1<<24) | (0x0f<<16) | (1<<25));
    *EMI_DCM_CON_1 = reg_or(*EMI_DCM_CON_1, 0x1f);
    *EMI_DCM_CON_1 = reg_and(*EMI_DCM_CON_1, ~(1<<5));
    *EMI_DCM_CON_1 = reg_or(*EMI_DCM_CON_1, (1 << 5));
    *EMI_DCM_CON_1 = reg_and(*EMI_DCM_CON_1, ~(1<<5));
#endif //#if defined (__TRADITIONAL_MODEM_CARD__)  || defined (__SDIO_DEVICE_CONNECTIVITY__)

    *PWR_DCM_DEBUG_CON1 = reg_aor(0x0057 | ((1 << 20) | (0xF << 16)), ~(1<<7), (0 != dcm_mcubus_dcm_off) ? (1<<7) : 0) ; //0x4057; 
    //*PWR_DCM_DEBUG_CON1 |= ((1 << 20) | (0xF << 16));

    *NONPWR_DCM_DEBUG_CON2 = 0x38; //=0x1b8;

    ///MDBUS
    *MDBUS_DCM_CON_0 = reg_aor(*MDBUS_DCM_CON_0, ~(0x1F | (0x1f<<8) | (0x7f<<16)), (0x0f<<8) | (1<<24) | (0x0f<<16) | (1<<25));
    *MDBUS_DCM_CON_1 = reg_or(*MDBUS_DCM_CON_1, 0x1F);
    *MDBUS_DCM_CON_1 = reg_and(*MDBUS_DCM_CON_1, ~(1<<5));
    *MDBUS_DCM_CON_1 = reg_or(*MDBUS_DCM_CON_1, (1 << 5));
    *MDBUS_DCM_CON_1 = reg_and(*MDBUS_DCM_CON_1, ~(1<<5));

    ///MDMCU
    *MDMCU_DCM_CON_0 = reg_aor(*MDMCU_DCM_CON_0, ~(0x1F | (0x7f<<16)), (0x1f<<8) | (1<<24) | (0x0f<<16) | (1<<25));
    *MDMCU_DCM_CON_1 = reg_or(*MDMCU_DCM_CON_1, 0x1F);
    *MDMCU_DCM_CON_1 = reg_and(*MDMCU_DCM_CON_1, ~(1<<5));
    *MDMCU_DCM_CON_1 = reg_or(*MDMCU_DCM_CON_1, (1 << 5));
    *MDMCU_DCM_CON_1 = reg_and(*MDMCU_DCM_CON_1, ~(1<<5));

    ///PWR domain
    *PWR_GLOBAL_CON1 = reg_aor(*PWR_GLOBAL_CON1, 
                               ~(0x1f | (0x1f<<5) | (0x1f<<10) | (0x1f<<15) | (0x7f<<22)), 
                               0x10 | (0x8<<5) | (1<<10) | (1<<15) | (0x0f<<22) | (1<<20) | (1<<21) | (1<<29));


    #endif
}

void Leave_DCM_mode(void)
{
    #if defined(MT6575) || defined (MT6577)
    *DCM_RG_CK_DCM_EN = 0x0; // MDMCU, bus, DCM disable
    *DCM_RG_CK_DCM_DSP_EN = 0x0; //DSP, bus, DCM disable

    #elif defined(MT6589) || defined(MT6572) || defined(MT6592) || defined (MT6571) || defined(MT6580)
	_dcm_hw_setting(0);

    #elif defined(MT6280)
#if defined (__TRADITIONAL_MODEM_CARD__)  || defined (__SDIO_DEVICE_CONNECTIVITY__)
    *AP_DCM_CON_0 = reg_and(*AP_DCM_CON_0, 1<<16); 
    *AP_PWR_DCM_DEBUG_CON1 = 0; //dcm_ap_pwr; //0x7FFF & ~(1<<4);  //usb dcm off
    *AP_NONPWR_DCM_DEBUG_CON1 = 0; //dcm_ap_nonpwr; //0xF;

    ///EMI
    *EMI_DCM_CON_0 = reg_aor(*EMI_DCM_CON_0, ~((1<<24)), 0);
    *EMI_DCM_CON_1 = reg_or(*EMI_DCM_CON_1, 0x1<<1);
    *EMI_DCM_CON_1 = reg_and(*EMI_DCM_CON_1, ~(1<<5));
    *EMI_DCM_CON_1 = reg_or(*EMI_DCM_CON_1, (1 << 5));
    *EMI_DCM_CON_1 = reg_and(*EMI_DCM_CON_1, ~(1<<5));

#endif //#if defined (__TRADITIONAL_MODEM_CARD__)  || defined (__SDIO_DEVICE_CONNECTIVITY__)

    *PWR_DCM_DEBUG_CON1 = 0x3f80; // 0x0057 | ((1 << 20) | (0xF << 16)) ; //0x4057; 
    *NONPWR_DCM_DEBUG_CON2 = 0; //0x38; //=0x1b8;

    ///MDBUS
    *MDBUS_DCM_CON_0 = reg_aor(*MDBUS_DCM_CON_0, ~((1<<24)), 0);
    *MDBUS_DCM_CON_1 = reg_or(*MDBUS_DCM_CON_1, 0x1<<1);
    *MDBUS_DCM_CON_1 = reg_and(*MDBUS_DCM_CON_1, ~(1<<5));
    *MDBUS_DCM_CON_1 = reg_or(*MDBUS_DCM_CON_1, (1 << 5));
    *MDBUS_DCM_CON_1 = reg_and(*MDBUS_DCM_CON_1, ~(1<<5));

    ///MDMCU
    *MDMCU_DCM_CON_0 = reg_aor(*MDMCU_DCM_CON_0, ~((1<<24)), 0);
    *MDMCU_DCM_CON_1 = reg_or(*MDMCU_DCM_CON_1, 0x1<<1);
    *MDMCU_DCM_CON_1 = reg_and(*MDMCU_DCM_CON_1, ~(1<<5));
    *MDMCU_DCM_CON_1 = reg_or(*MDMCU_DCM_CON_1, (1 << 5));
    *MDMCU_DCM_CON_1 = reg_and(*MDMCU_DCM_CON_1, ~(1<<5));

    ///PWR domain
    *PWR_GLOBAL_CON1 = reg_aor(*PWR_GLOBAL_CON1, ~((1<<20)), 0);

    #endif
}



void DCM_Init( void )
{

    #if defined(__MCU_DORMANT_MODE__)
    dormant_mode_init();
    #endif


    #if defined( DCM_ENABLE )

    #if defined(__COMBO_MEMORY_SUPPORT__)
    custom_EMIDynamicClockSwitch_Init();
    #endif /* __COMBO_MEMORY_SUPPORT__ */
    #if defined(__SERIAL_FLASH_EN__)
    custom_SFIDynamicClockSwitch_Init();
    #endif /* __SERIAL_FLASH_EN__ */

#if defined(MT6572) || defined (MT6582) || defined (MT6592) || defined (MT6571) || defined(MT6580)
	
	_dcm_hw_init();


#if defined (DCM_LPM_ENABLE) //this is for TOP LPM
	{
#include "pll.h"
    
		*PLL_CLKSW_FDIV2 = reg_aor(*PLL_CLKSW_FDIV2 , ~(0x0f<<0), (4<<0));
		*PLL_CLKSW_FDIV6 = reg_or(*PLL_CLKSW_FDIV6 , 0x04);
		*PLL_CLKSW_FDIV6 = reg_or(*PLL_CLKSW_FDIV6 , 0x0100);
		*PLL_CLKSW_FDIV6 = reg_and(*PLL_CLKSW_FDIV6 , ~0x0100);
	}
	PDN_CLR(PDN_LPM);
#endif //#if 0


#endif //#if defined(MT6572) || defined (MT6582) || defined (MT6592) || defined (MT6571) || defined(MT6580)

    #if defined(MT6589)
	
	//enabel MCU_bus/MCU_mcu/BUS_g0/BUS_g1 DCM (clk_off, the only supported in E1).
	//note: even the MCU_bus/MCU_mcu is de-featured in E1, the setting is no change else.
	_dcm_hw_setting(0);
	
	_mt6589_dcm_init();

	_dcm_hw_setting(1);

    // 
#if defined(__MTK_INTERNAL__)
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
#endif //#if defined (__MTK_INTERNAL__)

	#endif

    #if defined(MT6280)

#if defined(__TRADITIONAL_MODEM_CARD__)  || defined (__SDIO_DEVICE_CONNECTIVITY__)
    /** for WHQA00012236 workaround, 
     * to disable apsys slave ahb dcm.
     */
    *AP_BUS_IDLE_CON_1 = reg_aor(*AP_BUS_IDLE_CON_1, ~(0x3<<0), 2);

    // select APMCU as 26MHz clock
    // enable to switch idle_fsel when in DCM state    
    // gate APMCU clock
    *AP_DCM_CON_0 |= 0x70000;

    // AP PWR module DCM enable
    //usb dcm off, and set clock-gating for h0/h1/h2
    // nfi/hif/nli have to disable, due to buggy design with no nfi idle signal for dcm.
    *AP_PWR_DCM_DEBUG_CON1 = 0x7FFF & ~((1<<4) | (0x07<<12) | (7<<1)); 
    // AP NONPWR module DCM enable
    *AP_NONPWR_DCM_DEBUG_CON1 = 0xF;

    if(1) {
        /**** AP INFRASYS DCM Start ****/
    
        //AP_DCM_CON_1 [12:8] = 5'h10 // hsap_fsel , should not below 60Mhz due to USB sharing clock with apbus 
        ///*AP_DCM_CON_1 &= ~(0x1F << 8);
        ///*AP_DCM_CON_1 |= (0x10 << 8);
        //AP_DCM_CON_1 [28:24] = 5'h01 // hsap_idle_fsel
        ///*AP_DCM_CON_1 &= ~(0x1F << 24);
        ///*AP_DCM_CON_1 |= (1 << 24);

        //replace with DCM_Prerequisite()
		//*AP_DCM_CON_1 = reg_aor(*AP_DCM_CON_1, ~((0x1F << 8) | (0x1F << 24)), ((HSAPBUS_FSEL << 8)|(1 << 24)));    
    
#if !defined(__MEUT__)
         //AP_DCM_CON_0 [0] = 1'b1 // dcm_en
        *AP_DCM_CON_0 |= 1;
#endif
    }

    if(1) {
        /**** EMI ****/
        //EMI_DCM_CON_0[4:0] = 5'b0 // fsel
        //EMI_DCM_CON_0[12:8] = 5'hF // idle_fsel
        //EMI_DCM_CON_0[22:16] = 7'hF // dbc_cnt
        //EMI_DCM_CON_0[25] = 1'b1 // dbc_en
        /* *EMI_DCM_CON_0 &= ~0x1F; */
        /* *EMI_DCM_CON_0 &= ~(0x1F << 8); */
        /* *EMI_DCM_CON_0 |= (0xF << 8); */
        /* *EMI_DCM_CON_0 &= ~(0x7F << 16); */
        /* *EMI_DCM_CON_0 |= (0xF << 16); */
        /* *EMI_DCM_CON_0 |= (1 << 25); */
    
#if !defined(__MEUT__)
        //EMI_DCM_CON_0[24] = 1'b1 // dcm_en
        ///*EMI_DCM_CON_0 |= (1 << 24);
        *EMI_DCM_CON_0 = reg_aor(*EMI_DCM_CON_0, ~(0x1F | (0x1F << 8) | (0x7F << 16)),
                                 ((0xF << 8) | (0xF << 16) | (1 << 25) | (1 << 24)));
#else
        ///*EMI_DCM_CON_0 &= ~(1 << 24);
        *EMI_DCM_CON_0 = reg_aor(*EMI_DCM_CON_0, ~(0x1F | (0x1F << 8) | (0x7F << 16) | (1 << 24)),
                                 ((0xF << 8) | (0xF << 16) | (1 << 25)));
#endif
        //EMI_DCM_CON_1[4:0] = 5'h1F // apb_sel
        *EMI_DCM_CON_1 |= 0x1F;
    
        //EMI_DCM_CON_1[5] = 1'b0 // apb_tog
        *EMI_DCM_CON_1 &= ~(1 << 5);
    
        //EMI_DCM_CON_1[5] = 1'b1 // apb_tog
        *EMI_DCM_CON_1 |= (1 << 5);    
    
        //EMI_DCM_CON_1[5] = 1'b0 // apb_tog
        *EMI_DCM_CON_1 &= ~(1 << 5);
    }

#endif //#if defined(__TRADITIONAL_MODEM_CARD__)  || defined (__SDIO_DEVICE_CONNECTIVITY__)

    // PWR module/bus DCM enable
    // bus enable settings should be the same (all enabled or all disabled)
    // adoe, sdctl, pdma should be disabled
	// f2s dcm disable.
    *PWR_DCM_DEBUG_CON1 = 0x0057; //0x4057; 
    // enable f2s_en_gen debounce.  
    *PWR_DCM_DEBUG_CON1 |= ((1 << 20) | (0xF << 16));

    // NONPWR module DCM enable
    // pdma, uart, sdctl and SIM should be disabled
    *NONPWR_DCM_DEBUG_CON2 = 0x38; //=0x1b8; 

    if(1) {
        /**** MDBUS DCM Start ****/
        //MDBUS_DCM_CON_0[4:0] = 5'b0
        //MDBUS_DCM_CON_0[12:8] = 5'hf 
        ///*MDBUS_DCM_CON_0 &= ~(0x1F);
        ///*MDBUS_DCM_CON_0 &= ~(0x1F << 8);
        ///*MDBUS_DCM_CON_0 |= (0xF << 8);
        //MDBUS_DCM_CON_0[22:16] = 7'hF 
        //MDBUS_DCM_CON_0[25] = 1'b1
        ///*MDBUS_DCM_CON_0 &= ~(0x7F << 16);
        ///*MDBUS_DCM_CON_0 |= (0xF << 16);
        ///*MDBUS_DCM_CON_0 |= (1 << 25);
    
#if !defined(__MEUT__)
        //MDBUS_DCM_CON_0[24] = 1'b1
        ///*MDBUS_DCM_CON_0 |= (1 << 24);
        *MDBUS_DCM_CON_0 = reg_aor(*MDBUS_DCM_CON_0, 
                                   ~(0x1F | (0x1F << 8) | (0x7F << 16)), 
                                   ((0xF << 8) | (0xF << 16)|(1 << 25) | (1 << 24)));
#else
        // not enabled 
        //*MDBUS_DCM_CON_0 &= ~(1 << 24);
        *MDBUS_DCM_CON_0 = reg_aor(*MDBUS_DCM_CON_0, 
                                   ~(0x1F | (0x1F << 8) | (0x7F << 16) | (1<<24)), 
                                   ((0xF << 8) | (0xF << 16)|(1 << 25)));
#endif
    
    
        //MDBUS_DCM_CON_1[4:0] = 5'h1F 
        *MDBUS_DCM_CON_1 |= 0x1F;
    
        //MDBUS_DCM_CON_1[5] = 1'b0
        *MDBUS_DCM_CON_1 &= ~(1 << 5);

        //MDBUS_DCM_CON_1[5] = 1'b1
        *MDBUS_DCM_CON_1 |= (1 << 5);

        //MDBUS_DCM_CON_1[5] = 1'b0
        *MDBUS_DCM_CON_1 &= ~(1 << 5);
    }


    if(1) {
        /**** MDMCU DCM ****/
        //MDMCU_DCM_CON_0[4:0] = 5'b0 // fsel
        //MDMCU_DCM_CON_0[12:8] = 5'h1F // idle_fsel
        //MDMCU_DCM_CON_0[22:16] = 7'hF // dbc_cnt
        //MDMCU_DCM_CON_0[25] = 1'b1 // dbc_en
        ///*MDMCU_DCM_CON_0 &= ~0x1F;
        ///*MDMCU_DCM_CON_0 |= (0x1F << 8);
        ///*MDMCU_DCM_CON_0 &= ~(0x7F << 16);
        ///*MDMCU_DCM_CON_0 |= (0xF << 16);
        ///*MDMCU_DCM_CON_0 |= (1 << 25);
#if !defined(__MEUT__)
        //MDMCU_DCM_CON_0[24] = 1'b1 // dcm_en
        ///*MDMCU_DCM_CON_0 |= (1 << 24);
        *MDMCU_DCM_CON_0 = reg_aor(*MDMCU_DCM_CON_0, ~(0x1F | (0x7F << 16)), (0x1F << 8) | (0xF << 16) | (1 << 25) | (1 << 24));
#else
        //MDMCU_DCM_CON_0[24] = 1'b1 // dcm_en
        ///*MDMCU_DCM_CON_0 &= ~(1 << 24);
        *MDMCU_DCM_CON_0 = reg_aor(*MDMCU_DCM_CON_0, ~(0x1F | (0x7F << 16) | (1 << 24)), (0x1F << 8) | (0xF << 16) | (1 << 25));
#endif    
    
        //MDMCU_DCM_CON_1[4:0] = 5'h1F // apb_sel
        *MDMCU_DCM_CON_1 |= 0x1F;

        //MDMCU_DCM_CON_1[5] = 1'b0 // apb_tog
        *MDMCU_DCM_CON_1 &= ~(1 << 5);
    
        //MDMCU_DCM_CON_1[5] = 1'b1 // apb_tog
        *MDMCU_DCM_CON_1 |= (1 << 5);
    
        //MDMCU_DCM_CON_1[5] = 1'b0 // apb_tog
        *MDMCU_DCM_CON_1 &= ~(1 << 5);
    }

    if(1) {
        /**** MD INFRASYS ****/
        //MD_PWR_GLOBAL_CON1[4:0] = 5'h10 // hfmd_fsel
        //MD_PWR_GLOBAL_CON1[9:5] = 5'h08 // hsmd_fsel
        //MD_PWR_GLOBAL_CON1[14:10] = 5'h01 // hfmd_idle_fsel
        //MD_PWR_GLOBAL_CON1[19:15] = 5'h01 // hsmd_idle_fsel
        //MD_PWR_GLOBAL_CON1[28:22] = 7'hf
        //MD_PWR_GLOBAL_CON1[21] = 1'b1 // dbc_en    
        //MD_PWR_GLOBAL_CON1[29] = 1'b1 // pllck_sel
        /* *PWR_GLOBAL_CON1 &= ~(0x1F); */
        /* *PWR_GLOBAL_CON1 |= 0x10; */
        /* *PWR_GLOBAL_CON1 &= ~(0x1F << 5); */
        /* *PWR_GLOBAL_CON1 |= (0x8 << 5); */
        /* *PWR_GLOBAL_CON1 &= ~(0x1F << 10); */
        /* *PWR_GLOBAL_CON1 |= (0x1 << 10); */
        /* *PWR_GLOBAL_CON1 &= ~(0x1F << 15); */
        /* *PWR_GLOBAL_CON1 |= (1 << 15); */
        /* *PWR_GLOBAL_CON1 &= ~(0x7F << 22);         */
        /* *PWR_GLOBAL_CON1 |= (0xF << 22); */
        /* *PWR_GLOBAL_CON1 |= (1 << 21); */
        /* *PWR_GLOBAL_CON1 |= (1 << 29);     */
    
#if !defined(__MEUT__)
        //MD_PWR_GLOBAL_CON1[20] = 1'b1 // dcm_en
        ///*PWR_GLOBAL_CON1 |= (1 << 20);
        *PWR_GLOBAL_CON1 = reg_aor(*PWR_GLOBAL_CON1, ~(0x1F | (0x1F << 5) | (0x1F << 10) | (0x1F << 15) | (0x7F << 22)), 
                                   (0x10 | (0x8 << 5) | (0x1 << 10) | (1 << 15) | (0xF << 22) | (1 << 21) | (1 << 29) | (1 << 20)));
#else
        //MD_PWR_GLOBAL_CON1[20] = 1'b1 // dcm_en
        ///*PWR_GLOBAL_CON1 &= ~(1 << 20);
        *PWR_GLOBAL_CON1 = reg_aor(*PWR_GLOBAL_CON1, ~(0x1F | (0x1F << 5) | (0x1F << 10) | (0x1F << 15) | (0x7F << 22) | (1 << 20)), 
                                   (0x10 | (0x8 << 5) | (0x1 << 10) | (1 << 15) | (0xF << 22) | (1 << 21) | (1 << 29)));
#endif
    
    }

    #elif defined(MT6573)
    
    #ifndef __SMART_PHONE_MODEM__
    *DCM_RG_CK_ALW_ON &= 0x00;
    *DCM_BUS_GATED_EN |= 0x00FF;
    *DCM_RG_CK_DCM_EN &= ~(0x80);
    /* idle frequency setting */
    *EMI_IDLE_FSEL = 0x1F;
    *FBUS_IDLE_FSEL = 0x1;
    *SBUS_IDLE_FSEL = 0x1;
    #endif /* __SMART_PHONE_MODEM__ */

    #elif defined(MT6575) || defined (MT6577)

    // When clock switch setting is stable, gated global_con register
    *DCM_RG_GLOBALCON_CON = *DCM_RG_GLOBALCON_CON | (1<<1); 
    *DCM_PERI_BUS_CON0 = *DCM_PERI_BUS_CON0 | (1<<31); // for LOC_ACC entering DCM

    *DCM_HW_MISC0 |= 0x606;
    // bit[1] 	= 1: MD2GSYS bus clock is gated when MD2GSYS MTCMOS
    // bit[2] 	= 1: MCU clock switch is switched to 26MHz when MCU clock is gated
    // bit[3] 	= 1: MD2GSYS subsys clock is gated when MD2GSYS MTCMOS
    // bit[4] 	= 1: HSPASYS subsys clock is gated when HSPASYS MTCMOS
    // bit[9] 	= 1: DSP clock switch is switched to 26MHz when DSP clock is gated
    // bit[10] 	= 1: MCU clock is gated when MCU MTCMOS
    *DCM_HW_MISC0 = *DCM_HW_MISC0 & 0xf7ff;   // Enable HW_DCM auto detection (bit[11] : MD2GSYS)
    *DCM_HW_MISC0 = *DCM_HW_MISC0 & 0xefff;   // Enable HW_DCM auto detection (bit[12] : P_DMA)


    // Low power setting
    *DCM_RG_CK_ALW_ON = 0x0; // all CG controlled by HW
    *DCM_BUS_GATED_EN = 0xffff; // bus gated enable
    // Lowest frequency setting
    *DCM_FBUS_IDLE_FSEL = 0x1;  // 15.36MHz for AFC
    *DCM_SBUS_IDLE_FSEL = 0x1; // 15.36MHz for AFC
    // HW control bus protection when enterning ARM MTCMOS mode
    *DCM_ARM_BUS_ACCESS_CON &= ~(0x00010000); 

    #if !defined(__MEUT__)
    *DCM_RG_CK_DCM_EN = 0x100F; // MDMCU, bus, DCM enable
    #else
    *DCM_DSP_IDLE_FSEL  = 0x1f; // 8.125MHz
    #endif

    #ifndef __SMART_PHONE_MODEM__
    // AP side DCM and lowest frequency setting
    *DCM_INFRA_TOPCKGEN_DCMCTL |= 0x7;
    *DCM_INFRA_TOPCKGEN_DCMFSEL = 0x07000000;
    *((volatile UINT32P)0xC00041DC) |= (0x3 << 24);/* enable EMI DCM */
    *DCM_INFRA_GLOBALCON_DCMCTL |= ((0x1 << 8) | 0x1);
    *DCM_INFRA_GLOBALCON_DCMFSEL = 0x0;
    *DCM_PERI_GLOBALCON_DCMCTL |= 0x1;
    *DCM_PERI_GLOBALCON_DCMFSEL = 0x0;
    *DCM_MMSYS2_GLOBALCON_DCMCTL = (0x1<<9) | (0x1<<8) | (0x1);
    #endif /* __SMART_PHONE_MODEM__ */

    #endif //#if defined (MT6280)

    #if defined(__MTK_INTERNAL__)
#if defined (DCM_LPM_ENABLE) //! (defined(MT6589) || defined (MT6572)) 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif //#if 0 //disable for MT6589
/* under construction !*/
    #endif //__MTK_INTERNAL__
	
    {
        kal_uint32 _savedMask;
        _savedMask = SaveAndSetIRQMask();
        dcm_state = 0;
        RestoreIRQMask(_savedMask);
    }
    #endif // DCM_ENABLE	
    
}

#if defined(DCM_AUDIO_DSP_LOWPOWER_V2_SUPPORT)

#if defined(L1D_TEST)
extern kal_int8 L1DTest_L1SM_Is_Slept(void);
#else
extern kal_bool L1SM_Is_Slept(void);
#endif  /* L1D_TEST */

extern kal_bool AUDLP_Check_LowPower_Status(void);

#endif  /* DCM_AUDIO_DSP_LOWPOWER_V2_SUPPORT */

//#pragma arm section code = "INTERNCODE"
//#pragma arm section code = "INTSRAM_ROCODE"
#if defined (MT6589) && !defined (__MD2__)
void DCM_Handler( void ) __SECTION__(INTSRAM_ROCODE);
#endif //#if defined (MT6589) && !defined (__MD2__)

void DCM_Handler( void )
{

   /* Partial sleep mode for MCU and AVB block.
      To force MCU and AVB bus CLK stopped when system is in idle task.
      System will run again and CLK resume automatically only when IRQ comes.
   */
   	
   #if defined( DCM_ENABLE )
      kal_uint32 _savedMask;
      register kal_uint32 start, end, duration;

      #if defined(__CENTRALIZED_SLEEP_MANAGER__) && defined(__EVENT_BASED_TIMER__) && defined(MTK_SLEEP_ENABLE)
        kal_get_sleep_time(&dcm.allow_sleep_dur);
      #endif /* __CENTRALIZED_SLEEP_MANAGER__ */
      
   #if defined(__MCU_DORMANT_MODE__)
      OST_AllowedToPowerDown = OSTD_Allow_Dormant_Mode();
   #endif /* __MCU_DORMANT_MODE__ */
	  
      _savedMask = LockIRQ();

      start = ust_get_current_time();

      #if defined(__CENTRALIZED_SLEEP_MANAGER__) && defined(__EVENT_BASED_TIMER__) && defined(MTK_SLEEP_ENABLE)
         /* Enable nIRQ wake-up event after I-Bit OFF. */
         OSTD_EnableNIRQ();
        /* Get confirm. (return for next while loop if it is invalid sleep time) */
        if( kal_is_valid_sleep_time( &(dcm.allow_sleep_dur) ) == 0 )
        {
            /* Disable nIRQ wake-up event before I-Bit ON. */
            OSTD_DisableNIRQ();
           RestoreIRQ(_savedMask);
           return;
        }
        /* Check & Trigger OST Pause Mode:
           MUST be called inside of I-Bit protection:
           If return value is KAL_FALSE, not going to sleep and maybe then execute DCM. 
           If return value is KAL_TRUE, going to sleep and bypass DCM. */
        OST_ReadyToSlept = OSTD_CheckSleep();
	    dcm.OST_ReadyToSlept = OST_ReadyToSlept;
      #endif /* __CENTRALIZED_SLEEP_MANAGER__ */

      /* Check if DMA, GMC and LCD_DMA is in Power Down Mode. */
      #if defined(MT6573)
      if ( DCM_ENABLE_CHECK &&
           dcm.dcmDisable == 0 &&
           dcm.dcmForceDisalbe == 0 )
      #else
      if ( DCM_ENABLE_CHECK &&
           OST_ReadyToSlept == KAL_FALSE && 
           dcm.dcmDisable == 0 &&
           dcm.dcmForceDisalbe == 0 )
      #endif
      {

         /*To access an address not in existance will ensure that EMI access is complete.*/
		  EMI_Dummy_Read();
         /*A26=1 means will not get data via data cache, it will access EMI directly.*/
         
         dcm_state = 1; /* DCM @ 104/52->13/26Mhz */ 

         #if !defined(__HW_DCM__)
		 ///custom_DynamicClockSwitch( MCU_xxxMHZ );  
         #endif         
         
         #if defined(DCM_AUDIO_DSP_LOWPOWER_V2_SUPPORT)
             /* Check if we should switch to SWDCM in Low Power Audio mode, it's decided by
                the API provided by audio and also L1 sleep mode */
           #if defined(L1D_TEST)
             if (AUDLP_Check_LowPower_Status() && L1DTest_L1SM_Is_Slept())
           #else
             if (AUDLP_Check_LowPower_Status() && L1SM_Is_Slept())
           #endif
             {
                /*
                 * Set the flag for Low Power Audio mode
                 */
                dcm_lpaudio_mode = KAL_TRUE;
                dcm_lpaudio_cnt++;
                
                /*
                 * Dummy Read to force EMI to leave DCM mode, assume PPCT will keep it from
                 * going back to DCM again
                 */
				EMI_Dummy_Read();
                
             }
         #endif /* DCM_AUDIO_DSP_LOWPOWER_V2_SUPPORT */
         
         dcm_state = 2; /* DCM @ 13/26MHz */
         
         /* check if IRQ is disabled for more than 60 qbits */
         end = ust_get_current_time();
         duration = ust_get_duration(start, end);
		 
         if (duration > 60) {
            if( !L1_CHECK_ASSERT_BYPASS() )
               EXT_ASSERT(0, duration, start, end);
         }
		 
          #if defined(MT6573)
             #ifndef __SMART_PHONE_MODEM__
             *DCM_RG_CK_DCM_EN |= 0x3;
             #endif /* __SMART_PHONE_MODEM__ */
             *DCM_MDARM_DCM_EN |= 0x3;
             *DCM_MDARM_CCTL &= 0xFFFFFEFF;
          #else 
			 // do nothing
          #endif
      
          /* When DTCM is used by other subsys, ARM can not gate clock. */
          if(WFI_Handle_Count == 0 )
          {
#if defined (__MODEM_CCCI_EXIST__)
			  volatile kal_uint32 usc;
			  usc = ust_get_current_time();
			  ccci_excep_dbg_logging(CCCI_EXCEP_DBG_IDLE_TASK_DCM_ENTER, (void*)&usc);
#endif //#if defined (__MODEM_CCCI_EXIST__)

              arm_enter_standby_mode(0);

#if defined (__MODEM_CCCI_EXIST__)
			  usc = ust_get_current_time();
			  ccci_excep_dbg_logging(CCCI_EXCEP_DBG_IDLE_TASK_DCM_LEAVE, (void*)&usc);
#endif //#if defined (__MODEM_CCCI_EXIST__)
          }

          #if defined(__MTK_INTERNAL__)
/* under construction !*/
          #endif //__MTK_INTERNAL__
      } 
      else // not dcm (sleep or just cpu standby)
      {
          #if defined(DCM_AUDIO_DSP_LOWPOWER_V2_SUPPORT)
          /* Check if we should switch to SWDCM in Low Power Audio mode, it's decided by
             the API provided by audio and also L1 sleep mode */
          #if defined(L1D_TEST)
          if (AUDLP_Check_LowPower_Status() && L1DTest_L1SM_Is_Slept())
          #else
          if (AUDLP_Check_LowPower_Status() && L1SM_Is_Slept())
          #endif
          {
              dcm_state = 1; /* DCM @ 104/52->13/26Mhz */ 

              /*
               * Set the flag for Low Power Audio mode
               */
              dcm_lpaudio_mode = KAL_TRUE;
              dcm_lpaudio_cnt++;

              /*
               * Dummy Read to force EMI to leave DCM mode, assume PPCT will keep it from
               * going back to DCM again
               */
              EMI_Dummy_Read();

              dcm_state = 2; /* DCM @ 13/26MHz */
          }
          #endif /* DCM_AUDIO_DSP_LOWPOWER_V2_SUPPORT */

          /* When DTCM is used by other subsys, ARM can not gate clock. */          
          if(WFI_Handle_Count == 0 )
          {
#if defined (__MODEM_CCCI_EXIST__)
			  volatile kal_uint32 usc, type, OST_InfiniteSlept;
			  OST_InfiniteSlept = OSTD_Infinite_Sleep_Query();
			  type = (KAL_TRUE == OST_ReadyToSlept) ? CCCI_EXCEP_DBG_IDLE_TASK_SLEEP_ENTER : CCCI_EXCEP_DBG_IDLE_TASK_WFI_ENTER;
			  usc = ust_get_current_time();
			  if (KAL_TRUE == OST_InfiniteSlept)
			      ccci_excep_dbg_logging(CCCI_EXCEP_DBG_INFINITESLEEP_WFI, (void*)&usc);
			  else
			      ccci_excep_dbg_logging(type, (void*)&usc);
#endif //#if defined (__MODEM_CCCI_EXIST__)


              if(KAL_TRUE == OST_ReadyToSlept)
              {
#if defined(MT6572) || defined (MT6582) || defined (MT6592) || defined (MT6571) || defined(MT6580)
/**
 * workaround: to disable TOP MDMCU DCM to push "axi_sleep_protect ready".
 * TOP MDMCU DCM will gating mcu_clock that are referenced by AXI_Sleep_Protect, 
 * which will lost protect ready while WFI for entering sleep.
 **/
				  _dcm_hw_top_mcu_dcm(0);
#endif //#if defined(MT6572) || defined (MT6582) || defined (MT6592) || defined (MT6571) || defined(MT6580)


                  #if defined(__MCU_DORMANT_MODE__)
				  if (KAL_TRUE == OST_AllowedToPowerDown)
					  dormant_mode_activate();
				  else
					  arm_enter_standby_mode(0);

                  #else /* __MCU_DORMANT_MODE__ */
				  arm_enter_standby_mode(0);
                  #endif /* __MCU_DORMANT_MODE__ */


#if defined(MT6572) || defined (MT6582) || defined (MT6592) || defined (MT6571) || defined(MT6580)
				  _dcm_hw_top_mcu_dcm(1);
#endif //#if defined(MT6572) || defined (MT6582) || defined (MT6592) || defined (MT6571) || defined(MT6580)
              }
              else
              {
                  arm_enter_standby_mode(0);
              }

#if defined (__MODEM_CCCI_EXIST__)
			  usc = ust_get_current_time();
			  type = (type == CCCI_EXCEP_DBG_IDLE_TASK_SLEEP_ENTER) ? CCCI_EXCEP_DBG_IDLE_TASK_SLEEP_LEAVE : CCCI_EXCEP_DBG_IDLE_TASK_WFI_LEAVE;
			  ccci_excep_dbg_logging(type, (void*)&usc);
#endif //#if defined (__MODEM_CCCI_EXIST__)

          }
      }           
      
      #if defined(__CENTRALIZED_SLEEP_MANAGER__) && defined(__EVENT_BASED_TIMER__) && defined(MTK_SLEEP_ENABLE)
      /* Disable nIRQ wake-up event before I-Bit ON. */
      OSTD_DisableNIRQ();
      #endif /* __CENTRALIZED_SLEEP_MANAGER__ */
      RestoreIRQ(_savedMask);

   #else //DCM_ENABLE

      kal_uint32 _savedMask;
      #if defined(__CENTRALIZED_SLEEP_MANAGER__) && defined(__EVENT_BASED_TIMER__) && defined(MTK_SLEEP_ENABLE)
      Sleep_Time allow_sleep_dur;

      kal_get_sleep_time(&allow_sleep_dur);
      #endif /* __CENTRALIZED_SLEEP_MANAGER__ */

      #if defined(__MCU_DORMANT_MODE__)
      OST_AllowedToPowerDown = OSTD_Allow_Dormant_Mode();
      #endif /* __MCU_DORMANT_MODE__ */
	  
      _savedMask = LockIRQ();

      #if defined(__CENTRALIZED_SLEEP_MANAGER__) && defined(__EVENT_BASED_TIMER__) && defined(MTK_SLEEP_ENABLE)
      /* Enable nIRQ wake-up event after I-Bit OFF. */
      OSTD_EnableNIRQ();
      /* Get confirm */
      if( kal_is_valid_sleep_time( &allow_sleep_dur ) == 0 )
      {
         /* Disable nIRQ wake-up event before I-Bit ON. */
         OSTD_DisableNIRQ();
         RestoreIRQ(_savedMask);
         return;
      }
      /* Check & Trigger OST Pause Mode:
           MUST be called inside of I-Bit protection:
           No need to check return value while DCM disabled. */
      OST_ReadyToSlept = OSTD_CheckSleep();
      #endif /* __CENTRALIZED_SLEEP_MANAGER__ */
	  
      /*To temporarily avoid the problem on AHB.*/

	  if(WFI_Handle_Count == 0 )
	  {
#if defined (__MODEM_CCCI_EXIST__)
		  volatile kal_uint32 usc, type, OST_InfiniteSlept;
		  OST_InfiniteSlept = OSTD_Infinite_Sleep_Query();
		  type = (KAL_TRUE == OST_ReadyToSlept) ? CCCI_EXCEP_DBG_IDLE_TASK_SLEEP_ENTER : CCCI_EXCEP_DBG_IDLE_TASK_WFI_ENTER;
		  usc = ust_get_current_time();
		  if (KAL_TRUE == OST_InfiniteSlept)
		      ccci_excep_dbg_logging(CCCI_EXCEP_DBG_INFINITESLEEP_WFI, (void*)&usc);
		  else
		      ccci_excep_dbg_logging(type, (void*)&usc);
#endif //#if defined (__MODEM_CCCI_EXIST__)


		  if( (KAL_TRUE == OST_ReadyToSlept) )
		  {
#if defined(MT6572) || defined (MT6582) || defined (MT6592) || defined (MT6571) || defined(MT6580)
			  _dcm_hw_top_mcu_dcm(0);
#endif //#if defined(MT6572) || defined (MT6582) || defined (MT6592) || defined (MT6571) || defined(MT6580)


              #if defined(__MCU_DORMANT_MODE__)
			  if (KAL_TRUE == OST_AllowedToPowerDown)
				  dormant_mode_activate();
			  else 
				  arm_enter_standby_mode(0);

              #else /* __MCU_DORMANT_MODE__ */
			  arm_enter_standby_mode(0);
              #endif /* __MCU_DORMANT_MODE__ */


#if defined(MT6572) || defined (MT6582) || defined (MT6592) || defined (MT6571) || defined(MT6580)
			  _dcm_hw_top_mcu_dcm(1);
#endif //#if defined(MT6572) || defined (MT6582) || defined (MT6592) || defined (MT6571) || defined(MT6580)

		  }
		  else
		  {
#if 1 
			  arm_enter_standby_mode(0);
#else //for bring-up load, remove WFI to avoid clock gating.	
/* under construction !*/
#endif
		  }

#if defined (__MODEM_CCCI_EXIST__)
		  usc = ust_get_current_time();
		  type = (type == CCCI_EXCEP_DBG_IDLE_TASK_SLEEP_ENTER) ? CCCI_EXCEP_DBG_IDLE_TASK_SLEEP_LEAVE : CCCI_EXCEP_DBG_IDLE_TASK_WFI_LEAVE;
		  ccci_excep_dbg_logging(type, (void*)&usc);
#endif //#if defined (__MODEM_CCCI_EXIST__)

	  }


      #if defined(__CENTRALIZED_SLEEP_MANAGER__) && defined(__EVENT_BASED_TIMER__) && defined(MTK_SLEEP_ENABLE)
      /* Disable nIRQ wake-up event before I-Bit ON. */
      OSTD_DisableNIRQ();
      #endif /* __CENTRALIZED_SLEEP_MANAGER__ */
      RestoreIRQ(_savedMask);

   #endif /* defined(DCM_ENABLE)*/       
}


void enter_PLL_save_mode(pll_use_scenario_t pll_scenario) {}
void leave_PLL_save_mode(pll_use_scenario_t pll_scenario) {}


#else  /* __MTK_TARGET__ */
   
#endif

