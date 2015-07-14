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
 *    tp_drv.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file is defined for touch screen driver
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "drv_features.h"
#include "drv_comm.h"
#include "reg_base.h"
#if defined(DRV_ADC_TOUCH_SCREEN) && (defined(TOUCH_PANEL_SUPPORT) || defined(HAND_WRITING) || defined(DRV_ADC_TOUCH_SCREEN_BTMT))
#include "eint.h"
//#include "touch_panel_custom.h"
#include "touch_panel.h"
//#include    "touch_panel_spi.h"
#include "drv_hisr.h"
#include "ts_hw.h"
#include "intrCtrl.h"
#include "drvpdn.h"
//#include "gpt_sw.h"
#include "adc_hw.h"
#include "drv_trc.h"
#include "init.h"
//#include "kal_non_specific_general_types.h"
//#include "kal_release.h"
#include "kal_trace.h"

#include "kal_general_types.h"
#include "kal_public_defs.h"
#include "kal_public_api.h"
#include "us_timer.h"

extern void SLA_CustomLogging(kal_char *customJob, kal_uint32 saAction);

#if !defined(DRV_TS_OFF)

extern PFN_DCL_CALLBACK DclHTS_DownHandler_cb;
extern PFN_DCL_CALLBACK DclHTS_UpHandler_cb;

kal_uint16  ts_read_adc(kal_uint16 pos,kal_bool IsPressure);
#if defined(TOUCH_PANEL_PRESSURE)
kal_bool tp_pressure_check(void);
#endif

kal_uint32 tsSampleResolution = TS_CMD_DIFFERENTIAL;
kal_uint32 tsModeSelection    = TS_CMD_MODE_10BIT;

#if defined(__OLD_PDN_ARCH__)
#if defined(__OLD_PDN_DEFINE__)
#define TP_PDN_CLR		(DRV_TP_WriteReg(DRVPDN_CON1+0x20,(kal_uint16)DRVPDN_CON1_TP))
#elif defined(__APPLICATION_PROCESSOR__)
#define TP_PDN_CLR		(DRV_TP_WriteReg(CG_CON0,(kal_uint16)CG_CON0_TP))
#else // #if defined(__OLD_PDN_DEFINE__)
#define TP_PDN_CLR		DRV_TP_WriteReg(CG_CLR1 ,(kal_uint16)CG_CON1_TP)
#endif // #if defined(__OLD_PDN_DEFINE__)
#else //#if defined(__OLD_PDN_ARCH__)
#define TP_PDN_CLR		PDN_CLR(PDN_TP);
#endif //#if defined(__OLD_PDN_ARCH__)

//Mask these define, because we need to use #if  defined(__APPLICATION_PROCESSOR__) in TP_PDN_SET();
//#define TP_PDN_SET		(DRV_TP_WriteReg(DRVPDN_CON1+0x10,(kal_uint16)DRVPDN_CON1_TP))
// We re-define TP_PDN_SET because we shouldn't set PDN bit of TP when AUXADC_CON_RUN bit is set
// AUXADC CON_RUN bit may be set for a while even TP sample is done
//#if defined(TP_PDN_SET)
//#undef TP_PDN_SET
//#endif // #if defined(TP_PDN_SET)

void TP_PDN_SET(void)
{
	volatile kal_uint32 i;
	i = 0;
	while ( (DRV_TP_Reg(AUXADC_CON) & AUXADC_CON_RUN) != 0 ){
		i++;
		if (i>=1000){
			break;
		}
	}
#if defined(__OLD_PDN_ARCH__)
#if defined(__OLD_PDN_DEFINE__)
	DRV_TP_WriteReg(DRVPDN_CON1+0x10,(kal_uint16)DRVPDN_CON1_TP);
#elif defined(__APPLICATION_PROCESSOR__)
	DRV_TP_WriteReg(CG_SET0,(kal_uint16)CG_CON0_TP);
#else
	DRV_TP_WriteReg(CG_SET1,(kal_uint16)CG_CON1_TP);
#endif
#else //#if defined(__OLD_PDN_ARCH__)
   PDN_SET(PDN_TP);
#endif //#if defined(__OLD_PDN_ARCH__)
}

#if defined(DRV_MISC_CACHE_REGION_SUPPORT)
  // If cache is supported, put RW, ZI into cahched region
  #pragma arm section rwdata = "CACHEDRW" , zidata = "CACHEDZI"
#endif  // #if defined(DRV_MISC_CACHE_REGION_SUPPORT)



#if defined(DRV_AUX_ADC_TP_MESSED_UP_WA)

// To implement DRV_AUX_ADC_TP_MESSED_UP_WA, we read ADC in HISR
#define __READ_TP_DATA_IN_HISR__
#if defined(__READ_TP_DATA_IN_HISR__)
  #if defined(DRV_ADC_TOUCH_SCREEN_BTMT)
  kal_int16  gX, gY;
  #else // #if defined(DRV_ADC_TOUCH_SCREEN_BTMT)
extern kal_int16  gX, gY;
  #endif // #if defined(DRV_ADC_TOUCH_SCREEN_BTMT)
#ifdef TOUCH_PANEL_PRESSURE
  #if defined(DRV_ADC_TOUCH_SCREEN_BTMT)
  kal_bool gPressureCheck;
  #else // #if defined(DRV_ADC_TOUCH_SCREEN_BTMT)
extern kal_bool gPressureCheck;
extern  kal_uint16 gPressure;
  #endif // #if defined(DRV_ADC_TOUCH_SCREEN_BTMT)
#endif // #ifdef TOUCH_PANEL_PRESSURE
#endif // #if defined(__READ_TP_DATA_IN_HISR__)

#endif // #if defined(DRV_AUX_ADC_TP_MESSED_UP_WA)

//Toy increase TS_DEBOUNCE_TIME for work around the ADC X+ Y+ will shift in the very first
//UI response time and ADC correct location trade-off.
#if defined(DRV_TOUCH_PANEL_CUSTOMER_PARAMETER)
extern  kal_uint32 TS_DEBOUNCE_TIME;
#elif defined(LIBRA35_DEMO_BB) // NOT only Libra35 panel have quality problem
#define  TS_DEBOUNCE_TIME     (36*32)  //36ms
#elif defined(TRULY_HVGA_LCM)
#define  TS_DEBOUNCE_TIME     (48*32)  //48ms
#else
#define  TS_DEBOUNCE_TIME     (10*32)  //10ms
#endif

#if ( defined(DRV_TP_6238_SETTING) || defined(DRV_TP_6235_SETTING)  || defined(DRV_TP_6268_SETTING) || defined(DRV_TP_6253_SETTING))
ECO_VERSION gTPChipECOVersion;		// Indicate the Chip ECO version
#endif // #if ( defined(DRV_TP_6238_SETTING) || defined(DRV_TP_6235_SETTING) )
kal_bool gTPPerformADCTPMessedUPWA;		// Indicate whether to perform AUX ADC TP messed up WA
kal_bool gTPPerformADCUnsableWA;			// Indicate whether to perform ADC unsable WA
kal_bool gTPPerformNoTPUpINTRWA;			// Indicate whether to perform NO TP up intr WA
kal_bool gTPCheckPressueAsState;			// Indicate we need to check pressure value to judge TP is pressed or NOT
													// H/W state register is NOT reliable
// Define to enable check TP level in CB function
// This is a workaround for the chips (MT6235 E1, E2) which has problem on TS_STAT register
// Sometimes up state is NOT real time updated under some specific scenario
void TPUpdateNotify(void);
// Toy add ts_power_down_PENIRQ for avoid: 
// driver sampling and analog IRQ occur at the same time, 
// it will cause ADC thought pen is still down and reset debunce time.
void ts_power_down_PENIRQ(void);
static kal_uint16 ts_read_adc_adc_3835_WA(kal_uint16 pos,kal_bool IsPressure);
kal_bool tp_level(void);
kal_bool tp_state;		// Read back value of TP state
  
//althought not access in ts_drv.c, but it is accessed in touch_panel.c
/*lint -e552*/kal_bool tp_up_intr_lost_flag = KAL_FALSE;/*lint +e552*/	// Indicate if there is TP UP intr missed

#if defined(DRV_ADC_TOUCH_SCREEN_BTMT)
  TouchPanelDataStruct TP;
  kal_bool    touch_panel_state;
kal_uint32   TP_FILTER_THRESHOLD;
kal_uint32   TP_PRESSURE_THRESHOLD_HIGH;
kal_uint32   TP_PRESSURE_THRESHOLD_LOW;
#else // #if defined(DRV_ADC_TOUCH_SCREEN_BTMT)
extern kal_bool    touch_panel_state;
extern kal_uint32   TP_FILTER_THRESHOLD;
extern kal_uint32   TP_PRESSURE_THRESHOLD_HIGH;
extern kal_uint32   TP_PRESSURE_THRESHOLD_LOW;
#endif // #if defined(DRV_ADC_TOUCH_SCREEN_BTMT)

kal_hisrid ts_hisr;

#if defined(DRV_MISC_CACHE_REGION_SUPPORT)
  // If cache is supported, put RW, ZI into cahched region
  #pragma arm section rwdata, zidata
#endif  // #if defined(DRV_MISC_CACHE_REGION_SUPPORT)


// A function to detect whether TP is touched or NOT
// This function is added after MT6238/MT6235 TP module bug is found
kal_bool tp_level(void){
#if ( defined(DRV_TP_6238_SETTING) || defined(DRV_TP_6235_SETTING) || defined(DRV_TP_6268_SETTING) || defined(DRV_TP_6253_SETTING))
	kal_bool   tppc;
	
   if (gTPCheckPressueAsState){
      tppc = tp_pressure_check();
      if(tppc)
         return (kal_bool)touch_down_level;
      else
         return (kal_bool)touch_up_level;
   }else{
      if (DRV_TP_Reg(AUX_TS_CON) & TS_CON_STATUS_MASK){
         return (kal_bool)touch_down_level;
      }
      return (kal_bool)touch_up_level;
   }
#else // #if ( defined(DRV_TP_6238_SETTING) || defined(DRV_TP_6235_SETTING) )
   if (DRV_TP_Reg(AUX_TS_CON) & TS_CON_STATUS_MASK){
      return (kal_bool)touch_down_level;
   }
   return (kal_bool)touch_up_level;
#endif // #if ( defined(DRV_TP_6238_SETTING) || defined(DRV_TP_6235_SETTING) )
}
kal_bool tp_level_pressure(kal_uint32 *pressure)
{
#if ( defined(DRV_TP_6238_SETTING) || defined(DRV_TP_6235_SETTING) || defined(DRV_TP_6268_SETTING) || defined(DRV_TP_6253_SETTING))
	kal_bool   tppc;
	
   if (gTPCheckPressueAsState){
      tppc = tp_pressure_check_value(pressure);
      if(tppc)
         return (kal_bool)touch_down_level;
      else
         return (kal_bool)touch_up_level;
   }else{
      if (DRV_TP_Reg(AUX_TS_CON) & TS_CON_STATUS_MASK){
         return (kal_bool)touch_down_level;
      }
      return (kal_bool)touch_up_level;
   }
#else // #if ( defined(DRV_TP_6238_SETTING) || defined(DRV_TP_6235_SETTING) )
   *pressure = tp_pressure_value();//must get correct pressure value
   if (DRV_TP_Reg(AUX_TS_CON) & TS_CON_STATUS_MASK){
      return (kal_bool)touch_down_level;
   }
   return (kal_bool)touch_up_level;
#endif // #if ( defined(DRV_TP_6238_SETTING) || defined(DRV_TP_6235_SETTING) )
}
// This function is to set a event to TP task to indicate we are at UP state
// TP task will perform UP Handler after receive the message
// The function is added for TP UP intr missed issue
void TPUpdateNotify(void){
	if (gTPPerformNoTPUpINTRWA){
		if (kal_if_hisr()){
			touch_panel_state = (kal_bool)touch_up_level;
			if (TP.state == DOWN){
				kal_set_eg_events(TP.event,1,KAL_OR);
				drv_trace0(TRACE_GROUP_10, TP_NOT_UP_TO_DATE_NOTIFY);
				TP.state = UP;
			}
		}
	}
}

//******************************************************
// Toy add ts_power_down_PENIRQ() for avoid: 
// driver sampling and analog IRQ occur at the same time, 
// it will cause ADC thought pen is still down and reset debunce time.
//******************************************************
void ts_power_down_PENIRQ(void)
{
	kal_uint16  reg;
#if !defined(__OLD_PDN_ARCH__)
   kal_uint32  status;
#endif //#if defined(__OLD_PDN_ARCH__)


// Power down PENIRQ begin

// we should 1.close the PENIRQ, 2.sampling, 3.enable the PENIRQ
// below operation will close the PENIRQ as step 1.
// and after this function done, the next sampling will sampling first then open PENIRQ(by TS_CMD_PD_YDRV_SH)

  // 0x20 won't trigger data to be sampled, TS_CMD_PD_IRQ_SH=1 means disable IRQ before next sampling
  // althought one DRV_TP_WriteReg, but the execution will be done in sequence.
  reg = 0x20 | TS_CMD_PD_IRQ_SH;
	DRV_TP_WriteReg(AUX_TS_CMD, reg);
	// TS_CON_SPL_TRIGGER=1 trigger sample process without PENIRQ.
	DRV_TP_WriteReg(AUX_TS_CON, TS_CON_SPL_TRIGGER);
  		
	while(TS_CON_SPL_MASK & DRV_TP_Reg(AUX_TS_CON))
	{
#if defined(__OLD_PDN_ARCH__)
#if defined(__OLD_PDN_DEFINE__)
		ASSERT(!(DRV_TP_Reg(DRVPDN_CON1) & (kal_uint16)DRVPDN_CON1_TP));
#endif
#else //#if defined(__OLD_PDN_ARCH__)
      PDN_STATUS(PDN_TP, status, kal_uint32);
      if(status != 0)
      {   ASSERT(0);  }
#endif //#if defined(__OLD_PDN_ARCH__)
	}
// Power down PENIRQ end
}
#if !defined(DRV_MISC_TDMA_NO_TIME) //drv_get_current_time() will assert if def TDMA_NO_TIME
#define DEADLOCK_DEBUG
#endif
// This function is only used for MT6238/MT6235
static kal_uint16 ts_read_adc_adc_3835_WA(kal_uint16 pos,kal_bool IsPressure )
{
	kal_uint16  reg;
	kal_uint32 i;
	kal_uint32 sample_count = 1;
#if defined(DRV_TOUCH_PANEL_MULTIPLE_PICK)
   extern kal_uint32   TP_MULTIPLE_POINT_SELECTION;
   kal_uint16 sample[32]={0};
   kal_uint32 j,itmp;
#else
	kal_uint16 sample[3] = {0,0,0};
	kal_uint16 delta12, delta23, delta13;
#endif
	kal_uint32 savedMask;
	#if defined(DEADLOCK_DEBUG)
	kal_uint32 TPWaitSync1;
	#endif
#if !defined(__OLD_PDN_ARCH__)
   kal_uint32  status;
#endif //#if defined(__OLD_PDN_ARCH__)

	
	if (gTPPerformADCUnsableWA){
#if defined(DRV_TOUCH_PANEL_MULTIPLE_PICK)
      sample_count = TP_MULTIPLE_POINT_SELECTION;
#else
		sample_count = 3;
#endif
	}
	
   if(KAL_TRUE == IsPressure) // measure pressure
   	{
   	 sample_count = 1;
   	}
	TP_PDN_CLR;
   
	for (i=0;i<sample_count;i++){
   
   	reg = pos|tsModeSelection|tsSampleResolution|TS_CMD_PD_YDRV_SH;
   	DRV_TP_WriteReg(AUX_TS_CMD, reg);
   	if (gTPPerformADCTPMessedUPWA)
        {
			// We must be in HISR
			// Just polling the AUXADC module state, we can only issue TP sample comamnd when AUXADC module is idle
	    #if defined(DEADLOCK_DEBUG)
			TPWaitSync1 = drv_get_current_time();
			#endif
			while (1){
				if ( (DRV_TP_Reg(AUXADC_CON) & AUXADC_CON_RUN) == 0 ){
					savedMask = SaveAndSetIRQMask();
					// Check AUXADC_CON_RUN again to avoid some other ISR preempts
					if ( (DRV_TP_Reg(AUXADC_CON) & AUXADC_CON_RUN) == 0 ){
						// Check if any SYNC mode request is issued
						if ( DRV_TP_Reg(AUXADC_SYNC) == 0 ){
							// No SYNC mode request
							// AUXADC_IMM check can be ignored, 
							// because for IMM mode, write 1 to specific channel will make ADC module 
							// to sample immdediately ==> AUXADC_CON_RUN presents IMMD mode state
							DRV_TP_WriteReg(AUX_TS_CON, TS_CON_SPL_TRIGGER);
							RestoreIRQMask(savedMask);
							break;
						}else{
							// Means we already issue SYNC mode sample request, 
							// but ADC module is waiting for TDMA event or at WARMUP state
							// We need to avoid issue TP sample request within critical time slot
							// TODO
						}
					}
					RestoreIRQMask(savedMask);
				}
				#if defined(DEADLOCK_DEBUG)
				// For check whether HW already deadlock.
				ASSERT(drv_get_duration_ms(TPWaitSync1) < 20);
				#endif
			}
                }
		else // if (gTPPerformADCTPMessedUPWA)
		{
   		DRV_TP_WriteReg(AUX_TS_CON, TS_CON_SPL_TRIGGER);
		}

#if defined(DRV_TOUCH_PANEL_MULTIPLE_PICK)//sorting then pick the middle 3 point, and average them.
	if(i>1)
	{
      j = i-1;   //when i = 2~(TP_MULTIPLE_POINT_SELECTION-1) do bubble sort
      while(j>0) //bubble sort, sort before polling, gain from useless while() loop
      {
         if(sample[j] < sample[j-1]) //sorting 1 ~ (i-1)
         {
            itmp = sample[j-1];
            sample[j-1] = sample[j];
            sample[j] = itmp;
            j--;
         }
         else
            break;
      }
	}
#endif //#if defined(DRV_TOUCH_PANEL_MULTIPLE_PICK)
   
   	while(TS_CON_SPL_MASK & DRV_TP_Reg(AUX_TS_CON))
   	{
#if defined(__OLD_PDN_ARCH__)
#if defined(__OLD_PDN_DEFINE__)
			ASSERT(!(DRV_TP_Reg(DRVPDN_CON1) & (kal_uint16)DRVPDN_CON1_TP));
#else // #if defined(__OLD_PDN_DEFINE__)
			//ASSERT(!(DRV_TP_Reg(DRVPDN_CON1) & (kal_uint16)DRVPDN_CON1_TP));
			// TTTTTT
#endif // #if defined(__OLD_PDN_DEFINE__)
#else //#if defined(__OLD_PDN_ARCH__)
      PDN_STATUS(PDN_TP, status, kal_uint32);
      if(status != 0)
      {   ASSERT(0);  }
#endif //#if defined(__OLD_PDN_ARCH__)
	   }
   
   	reg = DRV_TP_Reg(AUX_TS_DATA0);
#if defined(DRV_TOUCH_PANEL_MULTIPLE_PICK)
      //bubble sort last point
      if(i == (sample_count-1) )
      {
         j=i;
         sample[j] = reg;
         while(j>0) //bubble sort, sort before polling, gain from useless while() loop
         {
            if(sample[j] < sample[j-1]) //sorting 1 ~ (i-1)
            {
               itmp = sample[j-1];
               sample[j-1] = sample[j];
               sample[j] = itmp;
               j--;
            }
            else
               break;
         }
      }
      else 
         sample[i] = reg;//prevent the last sorting cover by next sample[i]=reg
#else //#if defined(DRV_TOUCH_PANEL_MULTIPLE_PICK)
   	
		sample[i] = reg;
#endif //#if defined(DRV_TOUCH_PANEL_MULTIPLE_PICK)
   }

   TP_PDN_SET();
   
#if defined(DRV_TOUCH_PANEL_MULTIPLE_PICK)
   if (gTPPerformADCUnsableWA){
      j = (TP_MULTIPLE_POINT_SELECTION>>1);
	  if(sample_count>2)
      reg = (sample[j-1]+sample[j]+sample[j+1])/3;
	  else if(sample_count == 2)
		reg = (sample[0]+sample[1])/2;
	  else
	  	reg = sample[0];
   }else{
      reg = sample[0];
   }
#else //#if defined(DRV_TOUCH_PANEL_MULTIPLE_PICK)
	if (gTPPerformADCUnsableWA){
   	// Check 
   	// Delta 1 and 2
   	if (sample[0] >= sample[1]){
   		delta12 = sample[0] - sample[1];
		}else{
			delta12 = sample[1] - sample[0];
		}
		// Delta 2 and 3
		if (sample[1] >= sample[2]){
   		delta23 = sample[1] - sample[2];
		}else{
			delta23 = sample[2] - sample[1];
		}
		// Delta 1 and 3
		if (sample[0] >= sample[2]){
   		delta13 = sample[0] - sample[2];
		}else{
			delta13 = sample[2] - sample[0];
		}
		if (delta12 < delta23){
			if (delta12 < delta13){
				// delta12 is min
				reg = (kal_uint16)( (sample[0] + sample[1])/2 );
			}else{
				// delta13 is min
				reg = (kal_uint16)( (sample[0] + sample[2])/2 );
			}
		}else{
			if (delta23 < delta13){
				// delta23 is min
				reg = (kal_uint16)( (sample[1] + sample[2])/2 );
			}else{
				// delta13 is min
				reg = (kal_uint16)( (sample[0] + sample[2])/2 );
			}
		}
	}else{
		reg = sample[0];
	}
#endif //#if defined(DRV_TOUCH_PANEL_MULTIPLE_PICK)
#if defined(DRV_ADC_SAMPLE_12bIT)
   return reg;
#else
   return (reg<<2);
#endif//#if !defined(DRV_ADC_12bIT)
}

kal_uint16  ts_read_adc_multiple_average(kal_uint16 pos, kal_bool IsPressure )
{
	kal_uint16  reg;
	kal_uint32 i;
	kal_uint32 sample_count = 1;
	extern kal_uint32   TP_MULTIPLE_POINT_SELECTION;
	kal_uint16 sample[32]={0};
	kal_uint32 j,itmp;
#if !defined(__OLD_PDN_ARCH__)
   kal_uint32  status;
#endif //#if defined(__OLD_PDN_ARCH__)
	
	sample_count = TP_MULTIPLE_POINT_SELECTION;

	if(KAL_TRUE == IsPressure) // measure pressure
	 {
	  sample_count = 1;
	 }

	TP_PDN_CLR;

	for (i=0;i<sample_count;i++)
	{
		reg = pos|tsModeSelection|tsSampleResolution|TS_CMD_PD_YDRV_SH;
		DRV_TP_WriteReg(AUX_TS_CMD, reg);
		DRV_TP_WriteReg(AUX_TS_CON, TS_CON_SPL_TRIGGER);

	if(i>1)
	{
		j = i-1;   //when i = 2~(TP_MULTIPLE_POINT_SELECTION-1) do bubble sort
		while(j>0) //bubble sort, sort before polling, gain from useless while() loop
		{
			if(sample[j] < sample[j-1]) //sorting 1 ~ (i-1)
			{
				itmp = sample[j-1];
				sample[j-1] = sample[j];
				sample[j] = itmp;
				j--;
			}
			else
			break;
		}
	}
   
		while(TS_CON_SPL_MASK & DRV_TP_Reg(AUX_TS_CON))
		{
#if defined(__OLD_PDN_ARCH__)
#if defined(__OLD_PDN_DEFINE__)
			ASSERT(!(DRV_TP_Reg(DRVPDN_CON1) & (kal_uint16)DRVPDN_CON1_TP));
#else // #if defined(__OLD_PDN_DEFINE__)
			//ASSERT(!(DRV_TP_Reg(DRVPDN_CON1) & (kal_uint16)DRVPDN_CON1_TP));
			// TTTTTT
#endif // #if defined(__OLD_PDN_DEFINE__)
#else //#if defined(__OLD_PDN_ARCH__)
			PDN_STATUS(PDN_TP, status, kal_uint32);
			if(status != 0)
			{   ASSERT(0);  }
#endif //#if defined(__OLD_PDN_ARCH__)
		}
   
		reg = DRV_TP_Reg(AUX_TS_DATA0);
		//bubble sort last point
      if(i == (sample_count-1) )
		{
			j=i;
			sample[j] = reg;
			while(j>0) //bubble sort, sort before polling, gain from useless while() loop
			{
				if(sample[j] < sample[j-1]) //sorting 1 ~ (i-1)
				{
					itmp = sample[j-1];
					sample[j-1] = sample[j];
					sample[j] = itmp;
					j--;
				}
				else
					break;
			}
		}
		else 
			sample[i] = reg;//prevent the last sorting cover by next sample[i]=reg
	}

	TP_PDN_SET();
	j = (TP_MULTIPLE_POINT_SELECTION>>1);
	  if(sample_count>2)
	reg = (sample[j-1]+sample[j]+sample[j+1])/3;
	  else if(sample_count == 2)
		reg = (sample[0]+sample[1])/2;
	  else
	  	reg = sample[0];

#if defined(DRV_ADC_SAMPLE_12bIT)
   return reg;
#else
   return (reg<<2);
#endif//#if !defined(DRV_ADC_12bIT)}
}

kal_uint16  ts_read_adc(kal_uint16 pos,kal_bool IsPressure)
{
#if ( defined(DRV_TP_6238_SETTING) || defined(DRV_TP_6235_SETTING) || defined(DRV_TP_6268_SETTING) || defined(DRV_TP_6253_SETTING))
	// We have a special sample function for MT6238/MT6235
	return ts_read_adc_adc_3835_WA(pos,IsPressure);
#elif defined(DRV_TOUCH_PANEL_MULTIPLE_PICK)
	return ts_read_adc_multiple_average(pos,IsPressure);
#else // #if ( defined(DRV_TP_6238_SETTING) || defined(DRV_TP_6235_SETTING) )

#if !defined(__OLD_PDN_ARCH__)
   kal_uint32  status;
#endif //#if defined(__OLD_PDN_ARCH__)
	// Generic internal TP sample function
	kal_uint16  reg;
	TP_PDN_CLR;
	reg = pos|tsModeSelection|tsSampleResolution|TS_CMD_PD_YDRV_SH;
	DRV_TP_WriteReg(AUX_TS_CMD, reg);

	DRV_TP_WriteReg(AUX_TS_CON, TS_CON_SPL_TRIGGER);

	while(TS_CON_SPL_MASK & DRV_TP_Reg(AUX_TS_CON))
	{
#if defined(__OLD_PDN_ARCH__)
#if defined(__OLD_PDN_DEFINE__)		
		ASSERT(!(DRV_TP_Reg(DRVPDN_CON1) & (kal_uint16)DRVPDN_CON1_TP));
#else // #if defined(__OLD_PDN_DEFINE__)		
		// TODO
#endif // #if defined(__OLD_PDN_DEFINE__)		
#else //#if defined(__OLD_PDN_ARCH__)
      PDN_STATUS(PDN_TP, status, kal_uint32);
      if(status != 0)
      {   ASSERT(0);  }
#endif //#if defined(__OLD_PDN_ARCH__)
	}
   
	reg = DRV_TP_Reg(AUX_TS_DATA0);

	TP_PDN_SET();
#if defined(DRV_ADC_SAMPLE_12bIT)
	return reg;
#else
	return (reg<<2);
#endif //#if !defined(DRV_ADC_SAMPLE_12bIT)	
	
#endif // #if ( defined(DRV_TP_6238_SETTING) || defined(DRV_TP_6235_SETTING) )
	
}

void tp_read_adc(kal_uint16 *x, kal_uint16 *y)
{
#define TOTAL_CNT    1
   kal_uint8 retry;        
   kal_uint16 temp_x=0, temp_y=0;
   kal_int16 diff_x=0, diff_y=0;
   
   for(retry=0;retry<TOTAL_CNT;retry++)
   {
      /*Y ADC*/
      *y=ts_read_adc(TS_CMD_ADDR_Y, KAL_FALSE);
   
      /*X ADC*/
      *x=ts_read_adc(TS_CMD_ADDR_X, KAL_FALSE);
// Please remove below switch method after JADE36 V1 phase out.
#if defined(JADE36_DEMO_BB) //Jade36 V1 tp layout problem. 
      temp_x = *y;
      *y = 4096 - *x;
      *x = temp_x;
#endif 
// Please remove above switch method after JADE36 V1 phase out.
      if(temp_x==0&&temp_y==0)
      {
         temp_x=*x;
         temp_y=*y;
      }
      else
      {
         diff_x=temp_x-*x;
         diff_y=temp_y-*y;
         if(diff_x>TP_FILTER_THRESHOLD||diff_x<-TP_FILTER_THRESHOLD
            ||diff_y>TP_FILTER_THRESHOLD||diff_y<-TP_FILTER_THRESHOLD)
         {
            temp_x=*x;
            temp_y=*y;
            *x=4095;                  
            *y=4095;            
         }
         else
         {
         	if(*x!=4095&&*y!=4095)
            	return;
         }                        
      }
   }
}

#ifdef TOUCH_PANEL_PRESSURE
kal_bool tp_pressure_check(void)
{
   
   kal_uint8 retry;        
   kal_uint16 x, z1, z2;
   kal_uint32 pressure = 0;
   
   for(retry=0;retry<1/*TOUCH_PANEL_RETRY*/;retry++)
   {
      /*X ADC*/
      x=ts_read_adc(TS_CMD_ADDR_X,KAL_TRUE);
      //kal_prompt_trace(MOD_TP_TASK, "pressure x value: %d", x);

      /*Z1 ADC*/
      z1=ts_read_adc(TS_CMD_ADDR_Z1,KAL_TRUE);
      //kal_prompt_trace(MOD_TP_TASK, "pressure z1 value: %d", z1);

      /*Z2 ADC*/
      z2=ts_read_adc(TS_CMD_ADDR_Z2,KAL_TRUE);
      //kal_prompt_trace(MOD_TP_TASK, "pressure z2 value: %d", z2);
      if((z1 > 0) && (z2 > z1))
      {
         pressure = (kal_uint32)(x*(z2-z1)/z1) >> 2; /* Rx*x/4096*(z2/z1 - 1), assume Rx=1024 */
         //kal_prompt_trace(MOD_TP_TASK, "pressure: %d", pressure);
         
         drv_trace4(TRACE_GROUP_10, TP_PRESSURE_VALUE, pressure, x, z1, z2);
         //if (pressure > TOUCH_PRESSURE_THRESHOLD2)
           // kal_prompt_trace(MOD_TP_TASK, "pressure is above %d. value: %d", TOUCH_PRESSURE_THRESHOLD2, pressure);
         if ((pressure > TP_PRESSURE_THRESHOLD_HIGH) || (pressure <= TP_PRESSURE_THRESHOLD_LOW)){
         	drv_trace1(TRACE_GROUP_10, TP_PRESSURE_RESULT, 0);
            return KAL_FALSE; 
         }else{
         	drv_trace1(TRACE_GROUP_10, TP_PRESSURE_RESULT, 1);
            return KAL_TRUE; 
      }
   }
   }
   //kal_prompt_trace(MOD_TP_TASK, "pressure: 0 (no value)");

	drv_trace4(TRACE_GROUP_10, TP_PRESSURE_VALUE, pressure, x, z1, z2);
	drv_trace1(TRACE_GROUP_10, TP_PRESSURE_RESULT, 0);
   
   return KAL_FALSE;
}

kal_bool tp_pressure_check_value(kal_uint32 *pressure)
{
   *pressure = tp_pressure_value();
   if ((*pressure > TP_PRESSURE_THRESHOLD_HIGH) || (*pressure <= TP_PRESSURE_THRESHOLD_LOW)){
      drv_trace1(TRACE_GROUP_10, TP_PRESSURE_RESULT, 0);
      return KAL_FALSE; 
   }else{
      drv_trace1(TRACE_GROUP_10, TP_PRESSURE_RESULT, 1);
      return KAL_TRUE; 
   }
//   drv_trace1(TRACE_GROUP_10, TP_PRESSURE_RESULT, 0);
   //return KAL_FALSE;//Warning:  #111-D: statement is unreachable
}

kal_uint32 tp_pressure_value(void)
{
   kal_uint16 x, z1, z2;
   kal_uint32 pressure = 0;
   
   /*X ADC*/
   x=ts_read_adc(TS_CMD_ADDR_X,KAL_TRUE);

   /*Z1 ADC*/
   z1=ts_read_adc(TS_CMD_ADDR_Z1,KAL_TRUE);

   /*Z2 ADC*/
   z2=ts_read_adc(TS_CMD_ADDR_Z2,KAL_TRUE);
   if((z1 > 0) && (z2 > z1))
   {
      pressure = (kal_uint32)(x*(z2-z1)/z1) >> 2; /* Rx*x/4096*(z2/z1 - 1), assume Rx=1024 */
      drv_trace4(TRACE_GROUP_10, TP_PRESSURE_VALUE, pressure, x, z1, z2);
   }
   return pressure;
}
#endif /*TOUCH_PANEL_PRESSURE*/
void tp_set_cmd_para(kal_uint32 sr, kal_uint32 ms)
{
	switch(sr)
	{
	   case 0://DCL_TS_CMD_DIFFERENTIAL
	      tsSampleResolution = TS_CMD_DIFFERENTIAL;
	   break;
	   case 1://DCL_TS_CMD_SINGLE_END
	      tsSampleResolution = TS_CMD_SINGLE_END;
	   break;
	   default:
	   break;   
   }
	switch(ms)
	{
	   case 2://DCL_TS_CMD_MODE_8BIT
	      tsModeSelection = TS_CMD_MODE_8BIT;
	   break;
	   case 3://DCL_TS_CMD_MODE_10BIT
	      tsModeSelection = TS_CMD_MODE_10BIT;
	   break;
	   default:
	   break;   
   }
}

void tp_irq_enable(kal_bool on)
{
}    

void TS_LISR(void)
{
   IRQMask(IRQ_TS_CODE);
   //kal_activate_hisr(ts_hisr);
   drv_active_hisr(DRV_AUXADC_HISR_ID);
}

void TS_HISR(void)
{
	//kal_uint16 status;
//#define DRV_TP_STATIS_DELAY
#if defined(__READ_TP_DATA_IN_HISR__)
		kal_uint16 tmpX, tmpY;
#endif // #if defined(__READ_TP_DATA_IN_HISR__)

//kal_prompt_trace(MOD_TP_TASK,"TS_HISR s=%d", ust_get_current_time());
drv_trace1(TRACE_GROUP_10, TS_HISR_START,  ust_get_current_time());
SLA_CustomLogging("HIR",1);
  //toy add gTPCheckPressueAsState for prevent both TS_HISR & TPUpdateNotify execute kal_set_eg_events, it will trigger up_handler twice
	if (gTPPerformADCTPMessedUPWA || gTPCheckPressueAsState){

		// For different chips, have different level decision method
		// We put the detail check for each chip in tp_level() for code readness
		tp_state = tp_level();
		if(tp_state == touch_down_level)
		{
			DRV_TP_WriteReg(AUX_TS_DEBT, 10*32);
		}
		else
		{
		      DRV_TP_WriteReg(AUX_TS_DEBT, TS_DEBOUNCE_TIME);
		}
		// If the current S/W stat flag is same as read back H/W state, it means we lost one intr
		if (tp_state == touch_panel_state){
			// This means we lost interrupt
			if (touch_panel_state == (kal_bool)touch_down_level){
				// We lost UP intr
				// Need to set a flag to indicate we lost up flag
				tp_up_intr_lost_flag = KAL_TRUE;
				//kal_prompt_trace(MOD_TP_TASK, "up lost");
				drv_trace0(TRACE_GROUP_10, TP_UP_INTR_LOST);
			}else{
				// We lost Down intr
				// It is OK, we just pretend the paired (down -> up) intr never came
				IRQClearInt(IRQ_TS_CODE);
				IRQUnmask(IRQ_TS_CODE);
				//kal_prompt_trace(MOD_TP_TASK, "down lost");
				#if defined(DRV_TP_PENUP_FIXED)
				drv_trace0(TRACE_GROUP_10, TP_HISR_UP);
				#else
				drv_trace0(TRACE_GROUP_10, TP_DOWN_INTR_LOST);
				#endif
			//kal_prompt_trace(MOD_TP_TASK,"TS_HISR e1=%d", ust_get_current_time());
                          drv_trace1(TRACE_GROUP_10, TS_HISR_END,  ust_get_current_time());
			SLA_CustomLogging("HIR",0);	
				return;
			}
		}else{
			// Update TP state
			touch_panel_state = tp_state;
		}

	}else{
		// For other chips which do NOT have AUXADC TP messed up issue
		if (DRV_TP_Reg(AUX_TS_CON) & TS_CON_STATUS_MASK){
			touch_panel_state = (kal_bool)touch_down_level;
		}else{
			touch_panel_state = (kal_bool)touch_up_level;
		}
	}


   //status = DRV_TP_Reg(AUX_TS_CON);
   //if (status & TS_CON_STATUS_MASK)
   if (touch_panel_state==(kal_bool)touch_down_level)/*low*/
   {
   	
#if defined(__READ_TP_DATA_IN_HISR__)
			tp_read_adc(&tmpX, &tmpY);
			gX = (kal_int16)tmpX;
			gY = (kal_int16)tmpY;
			#if defined(__PORTRAIT_LCM_SIMULATE_LANDSCAPE_LCM__) || defined(__LCM_SCANLINE_ROTATION_SUPPORT__)
			{
				// Swap X-axis and Y-axis ADC value for Portrait LCM simuates Landscape LCM
				// For this condition, driver reports X-axis coordinate value by refering TP Y-axis ADC value
				//                     driver reports Y-axis coordinate value by refering TP X-axis ADC value
				kal_int16 swap_temp;
				swap_temp = gX;
				gX = gY;
				gY = swap_temp;
			}
			#endif // #if defined(__PORTRAIT_LCM_SIMULATE_LANDSCAPE_LCM__)

#ifdef TOUCH_PANEL_PRESSURE
                    gPressure = (kal_uint16)tp_pressure_value();
			gPressureCheck = tp_pressure_check();
#endif // #ifdef TOUCH_PANEL_PRESSURE
#endif // #if defined(__READ_TP_DATA_IN_HISR__)


       DclHTS_DownHandler_cb(0);
       
   }
   else
   {
   	  DclHTS_UpHandler_cb(0);	
  
   }
   
	IRQClearInt(IRQ_TS_CODE);
	IRQUnmask(IRQ_TS_CODE);
//	kal_prompt_trace(MOD_TP_TASK,"TS_HISR e2=%d", ust_get_current_time());
        drv_trace1(TRACE_GROUP_10, TS_HISR_END,  ust_get_current_time());
	SLA_CustomLogging("HIR",0);
}
void ts_drv_init(void)
{
   kal_uint16  x;
#if defined(DRV_TP_ADC_WARM_UP_ISSUE_WA)
   kal_uint16 tmp;
#endif // #if defined(DRV_TP_ADC_WARM_UP_ISSUE_WA)
   if (ts_hisr == NULL)
   {
      //ts_hisr = kal_create_hisr("TS_HISR",2,512,TS_HISR,NULL);
      ts_hisr=(void*)0x1234;
      DRV_Register_HISR(DRV_AUXADC_HISR_ID, TS_HISR);
   }
   
// If MT6238 or MT6235, we need to check ECO version
#if ( defined(DRV_TP_6238_SETTING) || defined(DRV_TP_6235_SETTING)  || defined(DRV_TP_6268_SETTING) || defined(DRV_TP_6253_SETTING))
	gTPChipECOVersion = INT_ecoVersion();
	// not check version anymore, apply in all version.
		gTPCheckPressueAsState = KAL_TRUE;
#endif // #if ( defined(DRV_TP_6238_SETTING) || defined(DRV_TP_6235_SETTING) )

#if defined(DRV_AUX_ADC_TP_MESSED_UP_WA)
	// Check which ECO version apply the WA
	#if defined (DRV_TP_6238_SETTING)
	if ( (gTPChipECOVersion == ENG_E1) || (gTPChipECOVersion == ENG_E2) ){
		gTPPerformADCTPMessedUPWA = KAL_TRUE;
	}
	// Check which ECO version apply the WA
	#elif defined (DRV_TP_6235_SETTING)
	if ( (gTPChipECOVersion == ECO_E1) || (gTPChipECOVersion == ECO_E2) ){
		gTPPerformADCTPMessedUPWA = KAL_TRUE;
	}
	#elif (defined (DRV_TP_6268_SETTING) || defined(DRV_TP_6253_SETTING))
	  gTPPerformADCTPMessedUPWA = KAL_TRUE;
	#endif // #if defined (DRV_TP_6268_SETTING)
#endif // #if defined(DRV_AUX_ADC_TP_MESSED_UP_WA)
	
#if defined(DRV_TP_STAT_NOT_UP_TO_DATE_WA)
	// not check version anymore, apply in all version.
		gTPPerformNoTPUpINTRWA = KAL_TRUE;
#endif // #if defined(DRV_TP_STAT_NOT_UP_TO_DATE_WA)
	
#if ( defined (DRV_TP_6238_SETTING) || defined (DRV_TP_6235_SETTING)  || defined(DRV_TP_6268_SETTING) ||defined(DRV_TP_6253_SETTING))
	gTPPerformADCUnsableWA = KAL_TRUE;
#endif // #if ( defined (DRV_TP_6238_SETTING) || defined (DRV_TP_6235_SETTING) )

   x=ts_read_adc(TS_CMD_ADDR_X,KAL_FALSE);
   x = DRV_TP_Reg(AUX_TS_CON);
   if (x & TS_CON_STATUS_MASK)
      touch_panel_state=(kal_bool)touch_down_level;
   else
      touch_panel_state=(kal_bool)touch_up_level;
      
#if defined(DRV_AUX_ADC_TP_MESSED_UP_WA)
	touch_panel_state = tp_level();
#endif //#if defined(DRV_AUX_ADC_TP_MESSED_UP_WA)
	
   
#if defined(DRV_TP_ADC_WARM_UP_ISSUE_WA)
// MT6235 E4, MT6238 E3, MT6268A E1 has ADC warm up register cause TP failed issue
// Need to disable warm up to make TP sample work
	tmp =DRV_TP_Reg(AUXADC_CON);
	tmp &= ~AUXADC_CON_PUWAIT_EN;
	DRV_TP_WriteReg(AUXADC_CON,tmp);
#endif // #if defined(DRV_TP_ADC_WARM_UP_ISSUE_WA)
   DRV_TP_WriteReg(AUX_TS_DEBT, TS_DEBOUNCE_TIME);
   //DRV_TP_WriteReg(AUX_TS_CMD, TS_CMD_PD_IRQ_SH);
   IRQ_Register_LISR(IRQ_TS_CODE, TS_LISR,"TS Handler");
   IRQSensitivity(IRQ_TS_CODE,EDGE_SENSITIVE);
   IRQUnmask(IRQ_TS_CODE);

   
   
}

#if defined(DRV_TP_NO_EXT_EINT)
void ts_mask_int(void)
{
   IRQMask(IRQ_TS_CODE);
}

void ts_unmask_int(void)
{
   IRQUnmask(IRQ_TS_CODE);
}
#endif //#if defined(DRV_TP_NO_EXT_EINT)

#else //#if !defined(DRV_TS_OFF)

/*lint -e552*/kal_bool tp_up_intr_lost_flag = KAL_FALSE;/*lint +e552*/	// Indicate if there is TP UP intr missed
void tp_irq_enable(kal_bool on){}
kal_bool tp_level(void){}
void TP_PDN_SET(void){}
kal_bool tp_pressure_check(void){}
kal_uint32 tp_pressure_value(void){}
void tp_read_adc(kal_uint16 *x, kal_uint16 *y){}
void tp_set_cmd_para(kal_uint32 sr, kal_uint32 ms){}
void TPUpdateNotify(void){}
void ts_drv_init(void){}
void ts_power_down_PENIRQ(void){}
kal_uint16  ts_read_adc(kal_uint16 pos,kal_bool IsPressure){}
static kal_uint16 ts_read_adc_adc_3835_WA(kal_uint16 pos){}
void ts_mask_int(void){}
void ts_unmask_int(void){}
#endif //#if !defined(DRV_TS_OFF)


#endif //#if defined(DRV_ADC_TOUCH_SCREEN) && (defined(TOUCH_PANEL_SUPPORT) || defined(HAND_WRITING) || defined(DRV_ADC_TOUCH_SCREEN_BTMT))
