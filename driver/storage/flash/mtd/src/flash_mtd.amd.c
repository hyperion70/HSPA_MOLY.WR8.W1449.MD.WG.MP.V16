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
 *    flash_mtd.amd.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This is flash MTD driver for AMD series devices.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================*/

/********************************************************/
/*                  Include Header Files                */
/********************************************************/
#include "DrvFlash.h"
#include "fs_errcode.h"


#include "flash_opt.h"
#include "flash_mtd.h"
#include "flash_mtd_internal.h"
#include "reg_base.h"
#include "us_timer.h"   ///< for time-logging to lsatisfy tERS requirement of Spansion WS-P in ESB
#include "nor_profile.h"
#include "flash_cfi_internal.h"

#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)
#include "intrCtrl.h"
#include "drv_comm.h"
#if defined(LA_TRIGGER_DEBUG)
#include "gpio_hw.h"
//#include "gpio_sw.h"
#endif
#endif /*__SINGLE_BANK_NOR_FLASH_SUPPORT__*/

#if defined(__FUE__)
#include "custom_fota.h"
#include "custom_img_config.h"
#include "fue_err.h"
#include "fue.h"
//#define __FUE_STRESS_TEST__
#endif

#include "kal_general_types.h"
#include "kal_public_api.h"
#include "combo_flash_init.h"
#include "flash_mtd_pf_dal.h"

#include "DrvFlash_UT.h"
#include "flash_mtd_ut.h"

#define dbg_text text

/********************************************************************************************
 * !!CAUTION!!
 * No matter what kinds of modifications are made in this file, corresponding verifications
 * are required on both multiple and single bank devices.
 * For example, sanity test should be passed on both Crystal25V3 and Crystal25V3SB projects.
 ********************************************************************************************/

#define TDMA_TQCNT         (volatile kal_uint16 *)(TDMA_base+0x00)
#define TDMA_WRAP          (volatile kal_uint16 *)(TDMA_base+0x04)

/*******************************************************************************
 *  Function declaration
 *******************************************************************************/
extern kal_uint32       INT_RetrieveFlashBaseAddr(void);
extern kal_bool         INT_QueryExceptionStatus(void);
#if (defined(__SPANSION_VS_R__) || defined(__SPANSION_WS_R__))

// since the program suspend and erase suspend command is different in VSR flash,
// the isProgram flag is use to distinguish whether the device is program busy or erase busy
// the falg is set/reset at function: UnalignedDataBufferProgram_WVSR, AlignedDataBufferProgram_WVSR, 
#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)
kal_bool isProgram = KAL_FALSE;
#endif  //__SINGLE_BANK_NOR_FLASH_SUPPORT__

kal_int32               WaitReady_WVSR(kal_uint32 BlkAddr);
#else //!__SPANSION_VS_R__ && !__SPANSION_WS_R__
kal_int32               WaitReady_AMD(kal_uint32 addr,kal_uint16 data);
#endif //__SPANSION_VS_R__ || __SPANSION_WS_R__

#if defined(__BASIC_LOAD_FLASH_TEST__)
#if (defined(__SPANSION_PL_N__) || defined(__AMD_SERIES_NOR__))
__inline static void    DelayAWhile_AMD(kal_bool Erase);
#endif   /* __SPANSION_PL_N__ || __AMD_SERIES_NOR__ */
#endif

/*******************************************************************************
 *  Variable declaration
 *******************************************************************************/
extern kal_uint32 gNonBlockingEraseBlockAddr; //extern form flash_mtd.c

#ifdef NOR_RESUME_SUSPEND_INTERVAL
kal_uint32              resume_time_g = NOR_DEFAULT_RESUME_TIME;  // to store suspend time (Qbit) to satisfy tERS
#endif

#if defined(__BASIC_LOAD_FLASH_TEST__)

extern void       NORTEST_Reset(void);
extern void       NORTEST_DisableWDT(void);
extern kal_uint32 NORTEST_GetCurrentTime(void);
extern void       NORTEST_ExceptionHandling(void);
extern kal_uint32 NORTEST_GetRandomNumber(void);
extern char       text[100];
extern kal_uint8  RandomNum;
extern kal_uint32 ProgramNum, EraseNum;
extern kal_uint8  PLTestOption;	// 0: Random reset    1: reset only in flash busy time.
extern kal_uint32 ResetTimeout;
extern kal_uint8  TestProgramFail;
extern kal_uint8  NORTestOption_ExceptionHandling;
static kal_bool ResetInNextBusy = KAL_FALSE;

//#undef kal_sprintf
//#undef dbg_print
//#undef dbg_print
//#define dbg_print(...)
//#define dbg_print(...)
//#define kal_sprintf(...)

/*******************************************************************************
 *  Basid load declaration
 *******************************************************************************/

// Debug Option
// Output debug message while program/erase fail
//#define OPERATION_FAIL_LOG

  
#define Cur_qbit (*(volatile kal_uint16 *)(TDMA_base + 0x00))
#define qwrap (*(volatile kal_uint16 *)(TDMA_base + 0x04))
#define dalay(us)  {\
    ASSERT(us<5000);\
    tqcnt1 = Cur_qbit;\
    while (1)\
    {        \
        tqcnt2 = Cur_qbit;\
        if (us < ( (tqcnt2 >= tqcnt1)? tqcnt2 - tqcnt1:(qwrap - tqcnt1) + tqcnt2 ) ) break;\
    }\
}

void ResetInBusy()
{
   if(ResetInNextBusy)
   {
      kal_uint16 tqcnt1, tqcnt2;
      dalay(Cur_qbit%65); /*delay 0~130us randomly*/
	
   	  NORTEST_Reset();
      while(1);
   }
}

#if defined(__FOTA_ENABLE__)

#include "fue_init.h"

extern void NORTEST_Delay_us(kal_uint32 count);
extern void NORTEST_Delay_30us(kal_uint32 count);
extern kal_uint32  NOR_counter;

#define BLTest(Num) \
	{\
		kal_uint32 val;\
		val = RandomNum + (*(volatile kal_uint32*)(COUNTER_32K))^(*(volatile kal_uint16 *)(TDMA_base + 0x00));\
		if (3 == Num) {\
			if (PLTestOption==0) {\
				if( (RandomNum & 0x7) == 3) {\
					NORTEST_Delay_us(100);\
					if(0 == (NOR_counter&0xF) )\
						triggerTestIRQ();\
					else\
						NOR_counter++;\
				}\
			} else if(PLTestOption==1) {\
				if ( (RandomNum & 0xF) == 7) {\
					val &= 0xFF;\
					NORTEST_Delay_us(val);\
					NORTEST_Reset();\
				}\
			} else { \
				if ( (RandomNum & 0xF) == 7) {\
					val &= 0xFF;\
					NORTEST_Delay_us(val);\
					NORTEST_Reset();\
				} else if((RandomNum & 0xF) == 3){\
					NORTEST_Delay_us(50);\
					if(0 == (NOR_counter&0xF) )\
						triggerTestIRQ();\
					else\
						NOR_counter++;\
				}\
			}\
		}\
		else if(0 == Num) {\
			if (PLTestOption==0) {\
				if( (RandomNum & 0x3) == 3) {\
					NORTEST_Delay_30us(10);\
					if(0 == (NOR_counter&0x1F) )\
						triggerTestIRQ();\
					else\
						NOR_counter++;\
				}\
			} else if(PLTestOption==1){\
				if ( (RandomNum & 0x7) == 7) {\
					val &= 0x7FFFF;\
					if(val<60)\
					val = 60;\
					NORTEST_Delay_30us(val>>5);\
					NORTEST_Reset();\
				}\
			} else { \
				if ( (RandomNum & 0x7) == 7) {\
					val &= 0x7FFFF;\
					if(val<60)\
					val = 60;\
					NORTEST_Delay_30us(val>>5);\
					NORTEST_Reset();\
				} else if((RandomNum & 0x7) == 3){\
					NORTEST_Delay_30us(4);\
					if(0 == (NOR_counter&0x1F) )\
						triggerTestIRQ();\
					else\
						NOR_counter++;\
				}\
			}\
		}\
	}

#elif defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)

#define BLTest(Num) \
	{\
		if (RandomNum == Num) {\
			if (PLTestOption==0) { \
				RandomNum = (RandomNum+1) % 5;\
				triggerTestIRQ();\
			} else { \
				if (ResetTimeout==0) {\
					if (RandomNum & 0x01) { \
						if(PLTestOption == 1)\
						NORTEST_Reset();\
						else \
						   ResetInNextBusy = KAL_TRUE; \
					} else { \
						triggerTestIRQ();\
					} \
				} else {\
					ResetTimeout--;\
					RandomNum = (RandomNum+1) % 5;\
					triggerTestIRQ();\
				}\
			}\
		}\
	}
#else    /* !__SINGLE_BANK_NOR_FLASH_SUPPORT__ && !__FOTA_ENABLE__ */

#define BLTest(Num) \
   {\
      if (RandomNum == Num)\
      {\
         if (NORTestOption_ExceptionHandling)\
         {\
         	NORTEST_ExceptionHandling();\
         }\
         else if (PLTestOption)\
         {\
            if (ResetTimeout==0) {\
               if(PLTestOption == 1)\
       	    NORTEST_Reset();\
       	       else \
       	          ResetInNextBusy = KAL_TRUE;\
            } else {\
               ResetTimeout--;\
               RandomNum = (RandomNum+1) % 5;\
            }\
         }\
      }\
   }

#endif   /* !__SINGLE_BANK_NOR_FLASH_SUPPORT__ && !__FOTA_ENABLE__ */

extern kal_uint8 IRQCode2Line[];

#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)

extern kal_bool NOR_FLASH_BUSY;
extern kal_bool NOR_FLASH_SUSPENDED;


// currently, no IRQ is enabled in FUE
// serial flash define its own IRQ triger function
#if !defined(__FUE__) && !defined(__SERIAL_FLASH_EN__)

kal_bool IRQ_ClearReady = KAL_TRUE;
void stopTriggerTestIRQ(void);

kal_uint32 irqStart, irqEnd, irqDuration;

void NORTestLISR(void)
{
   extern NOR_FLASH_DRV_Data  FlashDriveData;
   NOR_Flash_MTD_Data  *mtd_data = (NOR_Flash_MTD_Data *)FlashDriveData.MTDData;
   static kal_uint32    trigger_count = 0;
   volatile kal_uint32 *ram_ptr = 0;
   kal_uint32           randomNum;

  //  &Image$$ROM$$Base is MAUI start address, store vector table
  // note: NOR_Flash_Base_Address must be set to Non-Cacheable

   extern kal_uint32 Image$$ROM$$Base;
   volatile kal_uint32* rom_ptr = (kal_uint32 *)&Image$$ROM$$Base;
   kal_uint32 data_cache_id;

   /* check whether the flash is in ready state */
   MTD_ASSERT(~(mtd_data->Signature) == ((kal_uint32)mtd_data->RegionInfo), 0, 0, 0, NOR_MTD_DATA_CORRUPTED);

   // Check if suspend time is too long?
   irqEnd = ust_get_current_time();
   irqDuration = ust_get_duration(irqStart, irqEnd);
   basic_log("IrqDuration = %d qbit\r\n",irqDuration);
   if(irqDuration > 200) //should not more than 60 qbit to suspend flash!
   {      
      basic_log("IRQ disable more than 200 qbit. irqDuration = %d qbit\r\n",irqDuration);
      ASSERT(0);
   }

   // NOR flash should be ready to read. Check it by comparing RAM data and ROM data!
   // In ARM9 platform without L2 cache, NOR_Flash_Base_Address (i.e., start address of code region in NOR flash) is not allowed to access!
   #if !(defined(__ARM9_MMU__) || defined(__ARM11_MMU__))
   data_cache_id = INT_DisableDataCache();
   if( (ram_ptr[1] != rom_ptr[1]) || (ram_ptr[2] != rom_ptr[2]) ||
       (ram_ptr[3] != rom_ptr[3]) || (ram_ptr[4] != rom_ptr[4]) )
       MTD_ASSERT(0, 0, 0, 0, NOR_MTD_RAM_ROM_CONTENTS_UNMATCH);
   INT_RestoreDataCache(data_cache_id);
   #endif

   trigger_count++;

   #if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)
   kal_sprintf(text, ">>>>>>>>Enter NORTestLISR() %d times, suspend=%x, busy=%x\n\r", trigger_count, NOR_FLASH_SUSPENDED, NOR_FLASH_BUSY);
   #else
   kal_sprintf(text, ">>>>>>>>Enter NORTestLISR() %d times\n\r", trigger_count);
   #endif
   dbg_print(text);

   stopTriggerTestIRQ();
   IRQClearInt(TEST_IRQ_CODE);
   IRQ_ClearReady = KAL_TRUE;
   
   if (PLTestOption == 1)
   {
   	   // reset in busy time.
       if (ResetTimeout == 0)
       {
          NORTEST_Reset();
       }
   }

   if (NORTestOption_ExceptionHandling)
   {
      randomNum = NORTEST_GetRandomNumber();

      // exception simulator
      if (randomNum % 20 == 1)
      {
         NORTEST_ExceptionHandling();
      }
   }
}

void insertTestLISR(void)
{
   static kal_bool test_lisr_hooked = KAL_FALSE;

   if(!test_lisr_hooked)
   {
      IRQ_Register_LISR(TEST_IRQ_CODE, NORTestLISR,"FAKE NFI");
      IRQSensitivity(TEST_IRQ_CODE,LEVEL_SENSITIVE);
      IRQUnmask(TEST_IRQ_CODE);
      test_lisr_hooked = KAL_TRUE;
   }
}


__nor_section_RAM void stopTriggerTestIRQ(void)
{
   kal_uint8 line;

   if(!IRQ_ClearReady)
   {
      line = IRQCode2Line[TEST_IRQ_CODE];

      #if (defined(MT6253) || defined(MT6252) || defined(MT6252H))
      if (line<32) {
   		*IRQ_SOFTL &= ~(1 << line);
      } else {
         line = line - 32;
   		*IRQ_SOFTH &= ~(1 << line);
      }
      #elif (defined(MT6251))
        *IRQ_SOFT_CLR0 = (1 << line);
      #endif
   }
}

__nor_section_RAM void triggerTestIRQ(void)
{
   kal_uint8 line;

   irqStart = ust_get_current_time();

   if(IRQ_ClearReady)
   {
      IRQ_ClearReady = KAL_FALSE;
      line = IRQCode2Line[TEST_IRQ_CODE];
      #if ( defined(MT6229) || defined(MT6230) || defined(MT6235) || defined(MT6235) || defined(MT6235B) || defined(MT6253) || defined(MT6252) || defined(MT6252H))
      if (line<32) {
   		*IRQ_SOFTL = (1 << line);
      } else {
         line = line - 32;
   		*IRQ_SOFTH = (1 << line);
      }
      #elif (defined(MT6251) || defined(MT6255))
      *IRQ_SOFT_SET0 = (1 << line);
      #else
      *IRQ_SOFT = (1 << line);
      #endif
   }
}

#else // __FUE__ || __SERIAL_FLASH_EN__

void insertTestLISR(void)
{
}

void triggerTestIRQ(void)
{
}

#endif // !__FUE__ && !__SERIAL_FLASH_EN__

#endif /*__SINGLE_BANK_NOR_FLASH_SUPPORT__*/


#if (defined(__AMD_SERIES_NOR__) && defined(__SPANSION_PL_N__))
void DelayAWhile_TEST(kal_uint32 delayMethod, kal_uint32 delayTime)
{
	kal_uint32 loop;

	if (delayMethod == 0)			 // ABS version
	{
		DelayAWhile_UST(delayTime);
	}
	else if (delayMethod == 1)	    // AMD version
	{
		if (delayTime >= 50)
		{
			loop = delayTime / 50;
			while (loop--)
			{
				DelayAWhile_AMD(KAL_TRUE);
			}
		} else
		{
			loop = delayTime / 5;
			while (loop--)
			{
				DelayAWhile_AMD(KAL_FALSE);
			}
		}
	}

	return;
}
#endif  /* __AMD_SERIES_NOR__ && __SPANSION_PL_N__ */

#else   // !__BASIC_LOAD_FLASH_TEST__

#if defined(__FUE_STRESS_TEST__) && defined(__FUE__)

#include "fue_init.h"

extern void NORTEST_Delay_us(kal_uint32 count);
extern void NORTEST_Delay_30us(kal_uint32 count);
extern kal_uint8 RandomNum;
extern kal_uint8 PLTestOption;

#define triggerTestIRQ()

#define BLTest(Num) \
	{\
		kal_uint32 val = rand();\
		val += (*(volatile kal_uint32*)(COUNTER_32K))^(*(volatile kal_uint16 *)(TDMA_base + 0x00));\
		if (3 == Num) {\
			if (PLTestOption==0) { \
				if( (RandomNum & 0x7) == 3)\
					triggerTestIRQ();\
			} else { \
				if ( (RandomNum & 0xF) == 7) {\
					val %= 250;\
					NORTEST_Delay_us(val);\
					NORTEST_Reset();\
				} else if((RandomNum & 0xF) == 3){\
					triggerTestIRQ();\
				}\
			}\
		}\
		else if(0 == Num) {\
			if (PLTestOption==0) { \
				if( (RandomNum & 0x3) == 3)\
					triggerTestIRQ();\
			} else { \
				if ( (RandomNum & 0x7) == 7) {\
					val %= 600000;\
					if(val<60)\
						val = 60;\
					NORTEST_Delay_30us(val/30);\
					NORTEST_Reset();\
				} else if((RandomNum & 0x7) == 3){\
					triggerTestIRQ();\
				}\
			}\
		}\
	}

#else    /* !(__FUE_STRESS_TEST__ && __FUE__) */
#define BLTest(Num)
#endif   /* __FUE_STRESS_TEST__ && __FUE__ */

/*******************************************************************************
 *  MAUI load declaration 
 *******************************************************************************/
 
#define basic_printf(str, ...)
#define basic_print(str)
#define ResetInBusy()

#endif   //__BASIC_LOAD_FLASH_TEST__

#ifdef __AMD_SERIES_NOR__

/* ************************************************************
         SPANSION(AMD) NOR FLASH MTD Flash Driver
   ************************************************************ */

#ifdef __PAGE_BUFFER_PROGRAM__
extern kal_uint32 PAGE_BUFFER_SIZE;
#endif

#ifdef __SPANSION_PL_N__
extern kal_uint32 INT_GetCurrentTime(void);
#endif
#if (defined(__SPANSION_VS_R__) || defined(__SPANSION_WS_R__))
static int CheckDeviceReady_WVSR(void * DriveData, kal_uint32 BlockIndex);
#else
static int CheckDeviceReady_AMD(void * DriveData, kal_uint32 BlockIndex);
#endif

#ifdef __SPANSION_NS_N__
static void DYBCMD_AMD(void * D, volatile FLASH_CELL *fp, kal_uint32 ActionFlag);
#else 
#define DYBCMD_AMD(a,b,c)
#endif

/*-----------------------------------*/
#ifndef __NOR_FDM5__
#ifndef __COMBO_MEMORY_SUPPORT__
__nor_section_RAM static int MountDevice_AMD(void * DriveData, void *Info)
{
   NOR_MTD_FlashInfo * FlashInfo=Info;
   NOR_Flash_MTD_Data * D = DriveData;
   kal_uint32 i, MaxBlockSize = 0;

#if defined(__SPANSION_NS_J__) || defined(__SAMSUNG_SPANSION_NS_J_LIKE__)
   kal_uint32 block;
   volatile FLASH_CELL * fp;
   kal_uint32 savedMask;
   kal_uint32 data_cache_id;
#endif
#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__) && defined(__MULTI_BANK_NOR_DEVICE__)
   kal_uint32 TotalSize_Block = 0;
//   kal_uint32 TotalSize_Bank = 0;
#endif
   #if defined(__FOTA_DM__)
   kal_uint32 start_blk = 0;
   kal_uint32 end_blk = 0;
   #endif   /* __FOTA_DM__ */

   i = 0;
   FlashInfo->TotalBlocks = 0;
   while(D->RegionInfo[i].BlockSize != 0)
   {
      FlashInfo->BlockSize[i] = D->RegionInfo[i].BlockSize;
      FlashInfo->RegionBlocks[i] = D->RegionInfo[i].RegionBlocks;
      FlashInfo->TotalBlocks += D->RegionInfo[i].RegionBlocks;
#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__) && defined(__MULTI_BANK_NOR_DEVICE__)
      TotalSize_Block += D->RegionInfo[i].BlockSize * D->RegionInfo[i].RegionBlocks;
#endif

      if(D->RegionInfo[i].BlockSize > MaxBlockSize)
         MaxBlockSize = D->RegionInfo[i].BlockSize;
      i++;
   }
   FlashInfo->ActualRegionNum = i;
   FlashInfo->PageSize = 512;

#if defined(__SPANSION_NS_J__) || defined(__SAMSUNG_SPANSION_NS_J_LIKE__)
   /* In some NOR flash, all blocks are protected on power up. We unprotect them here. */

   #if defined(__FOTA_DM__)
   // unlock all FOTA reserved blocks in MAUI, unlock all blocks except for FUE block in FUE
   if( (FlashInfo->baseUnlockBlock != INVALID_BLOCK_INDEX) && (FlashInfo->endUnlockBlock != INVALID_BLOCK_INDEX) )
   {
      start_blk = FlashInfo->baseUnlockBlock;
      end_blk = FlashInfo->endUnlockBlock;
   }
   else
   {
      start_blk = 0;
      end_blk = FlashInfo->TotalBlocks;
   }
   for(block = start_blk; block < end_blk; block++)
   #else  /* !__FOTA_DM__ */
   // unlock all FS blocks in MAUI
   for(block = 0; block < FlashInfo->TotalBlocks; block++)
   #endif /* __FOTA_DM__ */
   {
      D->CurrAddr = BlockAddress(D, block);
      fp = (volatile FLASH_CELL *) D->CurrAddr;

      savedMask = SaveAndSetIRQMask();
      data_cache_id = INT_DisableDataCache();

      /* enter block protection/unprotection command sequence */
      fp[0] = 0x60;
      fp[0] = 0x60;

      #if defined(__SPANSION_NS_J__)
      *(kal_uint16*)(((kal_uint32)fp) | 0x80)  = 0x60;
      #elif defined(__SAMSUNG_SPANSION_NS_J_LIKE__)
      *(kal_uint16*)(((kal_uint32)fp) | 0x84)  = 0x60;
      #endif

      /* exit block protection/unprotection command sequence (by reset command) */
      fp[0] = 0xF0;

      INT_RestoreDataCache(data_cache_id);
      RestoreIRQMask(savedMask);
   }
#endif

#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__) && defined( __MULTI_BANK_NOR_DEVICE__)

      /*check customization */

   // CL_Add 2.21
   //disable for raw disk support
   //i=0;
   //while(D->BankInfo[i].BankSize != 0)
   //{
   //   TotalSize_Bank += D->BankInfo[i].BankSize * D->BankInfo[i].Banks;
   //   i++;
   //}
   //MTD_ASSERT(TotalSize_Bank==TotalSize_Block, 0, 0, 0, NOR_MTD_BANK_REGION_INFO_UNMATCH);
   // CL_Add

#endif

#if ( defined(__BASIC_LOAD_FLASH_TEST__) && defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__))
	 insertTestLISR();
#endif

   return FS_NO_ERROR;
}
#endif // !__COMBO_MEMORY_SUPPORT__
#endif // ! __NOR_FDM5__


#define CHECK_LOG_START(a)
#define CHECK_LOG_STOP(a)
/*-----------------------------------*/
#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)

/*
 * Following global variables should be modified only when I-bit is disabled
 */
extern kal_bool            NOR_FLASH_BUSY;
extern kal_bool            NOR_FLASH_SUSPENDED;
extern kal_uint32          gNOR_ReturnReadyBegin;
extern kal_uint32          gNOR_ReturnReadyEnd;

#if defined(LA_TRIGGER_DEBUG)

#define LA_TRIGGER_PIN (43)
#define RETURN_TRIGGER_PIN (44)
#define CHECK_TRIGGER_PIN (45)
#define CACHE_TRIGGER_PIN (46)

void triggerLA(void)
{
   DRV_Reg(GPIO_DOUT3) |= 0x0800; //set GPIO pin state to high
            }
static void triggerReturn(void)
      {
   DRV_Reg(GPIO_DOUT3) |= 0x1000; //set GPIO pin state to high
      }
static void deassertReturn(void)
      {
   DRV_Reg(GPIO_DOUT3) &= ~(0x1000); //set GPIO pin state to low
            }
static void triggerCheck(void)
            {
   DRV_Reg(GPIO_DOUT3) |= 0x2000; //set GPIO pin state to high
            }
static void deassertCheck(void)
      {
   DRV_Reg(GPIO_DOUT3) &= ~(0x2000); //set GPIO pin state to low
      }
void triggerDisable(void)
{
   DRV_Reg(GPIO_DOUT3) |= 0x4000; //set GPIO pin state to high
            }
void deaseertDisable(void)
      {
   DRV_Reg(GPIO_DOUT3) &= ~(0x4000); //set GPIO pin state to low
      }
#else /* defined(LA_TRIGGER_DEBUG) */

#define triggerLA(a)
#define triggerReturn(a)
#define deassertReturn(a)
#define triggerCheck(a)
#define deassertCheck(a)
#define triggerDisable(a)
#define deaseertDisable(a)

#endif /* LA_TRIGGER_DEBUG */

/*******************************************************************//**
 * Issue erase command sequence
 *
 * @par Category:
 * NOR MTD (Enhanced Single Bank)
 *
 * @note
 * Set NOR_FLASH_BUSY = KAL_TRUE
 **********************************************************************/
#define EraseCommand_AMD(addr) \
   do{\
      addr[ADDR_UNLOCK_1] = CMD_UNLOCK_1;\
      addr[ADDR_UNLOCK_2] = CMD_UNLOCK_2;\
      addr[ADDR_UNLOCK_1] = CMD_SERASE;\
      addr[ADDR_UNLOCK_1] = CMD_UNLOCK_1;\
      addr[ADDR_UNLOCK_2] = CMD_UNLOCK_2;\
      addr[0]     = CMD_SERASE_END;\
      NOR_FLASH_BUSY = KAL_TRUE;\
   } while(0);

#define EraseCommand_WVSR(addr) \
   do{ \
      addr[ADDR_UNLOCK_1] = WVSR_CMD_CLR_SR; \
      addr[ADDR_UNLOCK_1] = CMD_SERASE; \
      addr[ADDR_UNLOCK_2] = CMD_SERASE_END; \
      NOR_FLASH_BUSY = KAL_TRUE;\
   } while(0);

#else /* !__SINGLE_BANK_NOR_FLASH_SUPPORT__ */


#if (defined(__SPANSION_VS_R__) || defined(__SPANSION_WS_R__))

__nor_section_RAM static void EraseCommand_WVSR(volatile FLASH_CELL *fp)
{
   kal_uint32 savedMask;

   savedMask = SaveAndSetIRQMask();
   fp[ADDR_UNLOCK_1] = WVSR_CMD_CLR_SR;
   fp[ADDR_UNLOCK_1] = CMD_SERASE;
   fp[ADDR_UNLOCK_2] = CMD_SERASE_END;

   RestoreIRQMask(savedMask);

}
#endif

#if defined(__AMD_SERIES_NOR_PROGRAM__) || defined(__TOSHIBA_TV__) || defined(__TOSHIBA_TY__)
/*******************************************************************//**
 * Issue erase command sequence
 *
 * @par Category:
 * NOR MTD (Multi-Bank / Low-Cost Single Bank)
 **********************************************************************/
__nor_section_RAM static void EraseCommand_AMD(volatile FLASH_CELL *fp)
{
   kal_uint32 savedMask;

   savedMask = SaveAndSetIRQMask();
   fp[ADDR_UNLOCK_1] = CMD_UNLOCK_1;
   fp[ADDR_UNLOCK_2] = CMD_UNLOCK_2;
   fp[ADDR_UNLOCK_1] = CMD_SERASE;
   fp[ADDR_UNLOCK_1] = CMD_UNLOCK_1;
   fp[ADDR_UNLOCK_2] = CMD_UNLOCK_2;
   fp[0]     = CMD_SERASE_END;
   RestoreIRQMask(savedMask);
}
#endif //__AMD_SERIES_NOR_PROGRAM__ || __TOSHIBA_TV__ || __TOSHIBA_TY__


#endif /* __SINGLE_BANK_NOR_FLASH_SUPPORT__ */

#ifdef __SPANSION_NS_N__

__nor_section_RAM static void DYBCMD_AMD(void * D, volatile FLASH_CELL *fp, kal_uint32 ActionFlag)
{
   kal_uint32 savedMask;


   #if defined(__COMBO_MEMORY_SUPPORT__)
   if(!(((PF_MTD_Data*)D)->CMD->DYB_Lock)) return;
   #endif


   savedMask = SaveAndSetIRQMask();

   if(ActionFlag == DYB_UNLOCK)
   {
      fp[ADDR_UNLOCK_1] = CMD_UNLOCK_1;
      fp[ADDR_UNLOCK_2] = CMD_UNLOCK_2;
      fp[ADDR_UNLOCK_1] = CMD_DYB_ENTER;
      fp[0] = CMD_DYB_ACT;
      fp[0] = CMD_DYB_CLR;
      fp[0] = CMD_DYB_EXIT1;
      fp[0] = CMD_DYB_EXIT2;
   }
   else
   {
      fp[ADDR_UNLOCK_1] = CMD_UNLOCK_1;
      fp[ADDR_UNLOCK_2] = CMD_UNLOCK_2;
      fp[ADDR_UNLOCK_1] = CMD_DYB_ENTER;
      fp[0] = CMD_DYB_ACT;
      fp[0] = CMD_DYB_SET;
      fp[0] = CMD_DYB_EXIT1;
      fp[0] = CMD_DYB_EXIT2;
   }
   RestoreIRQMask(savedMask);
}

#endif //__SPANSION_NS_N__

/*-----------------------------------*/




#if defined(__BASIC_LOAD_FLASH_TEST__)

#if defined(__SPANSION_PL_N__)

// obsolete, replaced by DelayAWhile_UST
__nor_section_RAM __inline static void DelayAWhile_AMD(kal_bool Erase)
{
   volatile kal_uint32 i;

   if (Erase==KAL_TRUE) {
		// Spec said maximum value is 50 us.
		for (i=0;i<COUNTER_50US;i++);
   } else {
		// Spec said PLN PBP needs to delay 4 us before polling.
		for (i=0;i<COUNTER_05US;i++);
   }

   return;
}

#endif /* __SPANSION_PL_N__ || __SECURITY_OTP__ */

#endif //__BASIC_LOAD_FLASH_TEST__

/*-----------------------------------*/

#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)

/*******************************************************************//**
 * Delay for Toshiba TV/TY series flash
 *
 * @par Category:
 * NOR MTD (Enhanced Single Bank)
 *
 * @note
 * 1. This delay is used to cover tBUSY, which is longer (300ns ~ 500ns) in erase-suspended mode.
 * 2. tBUSY in other modes (program/erase) are typical 90ns. We do not have to wait such short period of time.
 * 3. Use DelayAWhile_UST in __ARM9_MMU__ and __ARM11_MMU__ platform instead of for-loop to prevent too long execution time.
 * 4. Multi-bank does not have to delay awhile because flash will not be polled immediately after resume.
 * 5. Use DelayAWhile_UST(1) instead of loop counter after W10.09 to unify the delay method, no need maintain loop count if CPU frequency changed
 *    Delay will longer than 350ns due to function call overhead (around 8~10 us in 6253)
 **********************************************************************/
#if (defined(__TOSHIBA_TV__) || defined(__TOSHIBA_TY__))
__nor_section_RAM void tBUSYDelay(void)
{
//#if defined(__ARM9_MMU__) || defined(__ARM11_MMU__)
#if 1

	DelayAWhile_UST(1);

#else  /* !__ARM9_MMU__ && !__ARM11_MMU__ */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __ARM9_MMU__ || __ARM11_MMU__ */
}
#else // !__TOSHIBA_TV__ && !__TOSHIBA_TY__
#define tBUSYDelay()
#endif

#if defined(__SPANSION_VS_R__) || defined(__SPANSION_WS_R__)
/*******************************************************************//**
 * Check if device is ready (for program only)
 *
 * @par Category:
 * NOR MTD (VSR Enhanced Single Bank)
 *
 * @note
 * 1. Only called by ProgramData_WVSR()
 *
 * @remark
 * addr must be block align
 **********************************************************************/
__nor_section_RAM kal_int32 CheckReadyAndResume_WVSR(kal_uint32 addr)
{
   FLASH_CELL       stat_data;
   kal_uint32       data_cache_id;
   kal_uint32       savedMask = 0;
   kal_int32        status      = RESULT_FLASH_BUSY;
   #if defined(OPERATION_FAIL_LOG)
   kal_bool         isSuspend = KAL_FALSE;
   #endif

   // ensure that the status check is atomic
   savedMask = SaveAndSetIRQMask();
   
   if(NOR_FLASH_SUSPENDED)
   {
      SNOR_MTD_ASSERT(NOR_FLASH_BUSY, NOR_FLASH_SUSPENDED, addr, *(volatile kal_uint16*)addr);
      
      *(volatile kal_uint16*)addr = WVSR_CMD_PROGRAM_RESUME;
      
      NOR_FLASH_SUSPENDED = KAL_FALSE;
      gNOR_ReturnReadyEnd = NOR_DEFAULT_RETURN_READY_LATENCY;
      
      #ifdef NOR_RESUME_SUSPEND_INTERVAL
   	  resume_time_g = ust_get_current_time();  // get suspend time to guarantee tERS
   	  #endif
   	  
   	  #if defined(OPERATION_FAIL_LOG)
   	  isSuspend = KAL_TRUE;
   	  #endif
   	  
   }

   data_cache_id = INT_DisableDataCache();

   *(((volatile kal_uint16*)addr) + ADDR_UNLOCK_1) = WVSR_CMD_RD_SR;
   stat_data = *(volatile kal_uint16*)addr;

   if(stat_data & WVSR_READY_FLAG)
   {
      NOR_FLASH_BUSY = KAL_FALSE;
      
   	  if(stat_data & WVSR_PROGRAM_ERROR_FLAG)
   	  {
              status = RESULT_FLASH_FAIL;  	
          }
   	  else
   	  {
   	     status = RESULT_FLASH_DONE;
   	  }
   }else {
      status = RESULT_FLASH_BUSY;
   }

   INT_RestoreDataCache(data_cache_id);
   RestoreIRQMask(savedMask);
   

   return status;
}
#endif //__SPANSION_VS_R__  || __SPANSION_WS_R__ 
#if defined(__AMD_SERIES_NOR_PROGRAM__) || defined(__TOSHIBA_TV__) || defined(__TOSHIBA_TY__)
/*******************************************************************//**
 * Check if device is ready (for program only)
 *
 * @par Category:
 * NOR MTD (Enhanced Single Bank)
 *
 * @note
 * 1. Only called by ProgramData_AMD() and ProgramData_Toshiba()
 *
 **********************************************************************/
__nor_section_RAM kal_int32 CheckReadyAndResume_AMD(kal_uint32 addr,kal_uint16 data)
{
   kal_uint32        data_cache_id;
   static kal_uint16 check_data  = 0;
   static kal_uint16 toggle_data = 0;
   static kal_uint32 poll_times  = 0;
   kal_uint32        savedMask;
   kal_int32         status = RESULT_FLASH_BUSY;

   triggerCheck();

   savedMask = SaveAndSetIRQMask();

   if(NOR_FLASH_SUSPENDED)
   {
      // NOR_FLASH_BUSY should be set to KAL_TRUE after issue program commands
      SNOR_MTD_ASSERT(NOR_FLASH_BUSY, *(volatile kal_uint16*)addr, *(volatile kal_uint16*)addr, addr);

      *(volatile kal_uint16*)addr = CMD_RESU_SEC_ERASE;
      NOR_FLASH_SUSPENDED = KAL_FALSE;

      #ifdef __MONZA_2G__
      gNOR_ReturnReadyEnd = NOR_DEFAULT_RETURN_READY_LATENCY;
      #endif

      #ifdef NOR_RESUME_SUSPEND_INTERVAL
      resume_time_g = ust_get_current_time();  // get suspend time to guarantee tERS
      #endif

      tBUSYDelay();
   }

   data_cache_id = INT_DisableDataCache();

   check_data = *(volatile kal_uint16*)addr;
   toggle_data = *(volatile kal_uint16*)addr;

/*   if( ((check_data & POLL_BUSY) != (data & POLL_BUSY)) ||
       ((check_data ^ toggle_data) & TOGGLE_BUSY) )*/
   if ((check_data ^ toggle_data) & TOGGLE_BUSY)
   {
#ifndef __SST_NOR__
      if( check_data & POLL_TIMEOUT )
      {
         check_data = *(volatile kal_uint16*)addr;

         if( check_data == data )
         {
            NOR_FLASH_BUSY = KAL_FALSE;
            status = RESULT_FLASH_DONE;
         }
         else
         {
#if defined(__BASIC_LOAD_FLASH_TEST__)
PF_TIMEOUT:
#endif
            *(volatile kal_uint16*)addr = CMD_RESET;
            INT_RestoreDataCache(data_cache_id);  // Remove this line will cause stack 8 bytes more. Call 2 time no hurt.

            NOR_FLASH_BUSY = KAL_FALSE;
            status = RESULT_FLASH_FAIL;
            //SNOR_MTD_ASSERT(0,check_data,data,addr);
         }
      }

#ifdef __PAGE_BUFFER_PROGRAM__
      else if( check_data & TOGGLE_BUFFER_ABORT )
      {
         check_data = *(volatile kal_uint16*)addr;
         toggle_data = *(volatile kal_uint16*)addr;

         if ((check_data ^ toggle_data) & TOGGLE_BUSY) {  /* DQ6 is toggling */

            /* write to buffer abort reset to return the flash to ready state */
            *(((volatile kal_uint16*)addr) + ADDR_UNLOCK_1) = CMD_UNLOCK_1;
            *(((volatile kal_uint16*)addr) + ADDR_UNLOCK_2) = CMD_UNLOCK_2;
            *(((volatile kal_uint16*)addr) + ADDR_UNLOCK_1) = CMD_RESET;

            INT_RestoreDataCache(data_cache_id);
            MTD_SNOR_ASSERT(0, check_data, data, addr, NOR_MTD_PROGRAM_WRITE_BUFFER_FAIL);
         }
         else  /* not toggle, compare data */
         {
            NOR_FLASH_BUSY = KAL_FALSE;
            check_data = *(volatile kal_uint16*)addr;

            if( check_data!= data)
            {
               status = RESULT_FLASH_FAIL;
            } else {
               status = RESULT_FLASH_DONE;
            }
         }
      }
#endif /* __PAGE_BUFFER_PROGRAM__ */
      else
#endif /* !__SST_NOR__ */
      {
         check_data = *(volatile kal_uint16*)addr;
         toggle_data = *(volatile kal_uint16*)addr;

         if( (check_data == data) && !((toggle_data ^ check_data) & TOGGLE_BUSY) )
         {
            NOR_FLASH_BUSY = KAL_FALSE;
            status = RESULT_FLASH_DONE;
         }
      }
   }
   // DQ6 is not toggling
   else
   {
      #if defined(__BASIC_LOAD_FLASH_TEST__)
      if ( (TestProgramFail==3) && ((NORTEST_GetCurrentTime() % 8000) == 6888)) {
         goto PF_TIMEOUT;
	   }
      #endif

      if((check_data & POLL_BUSY) != (data & POLL_BUSY))
      {
         /**********************************************************************//**
          * DQ6 is not toggling means that flash is ready. (Erase suspended should be resumed above)
          *
          * In normal case, we should not enter here except that DQ6 is not reliable
          * (i.e., DQ6 stops toggling before flash is ready while DQ7 is still complement of data).
          * In such abnormal case, DQ7 provides double confirm here. (w08.29)
          **************************************************************************/

         // limit the polling times to handle bit-flipping phenomenon
         poll_times++;
         if (poll_times >= MAX_AMD_PGM_POLL_TIMES)
         {
            /**********************************************************************//**
             * program fail, maybe a bit-flipping phenomenon. ProgramFailHandle() will erase
             * this block to let bit-flipping phenomenon disappear.
             *
             * Note that NOR_FLASH_BUSY is still KAL_TRUE here! But that's ok, NOR_FLASH_BUSY
             * will be set to normal value when this block is marked as BLOCK_ERASING in
             * program fail handling.
             **************************************************************************/
            status = RESULT_FLASH_FAIL;
         }
         else
         {
            status = RESULT_FLASH_BUSY;   // default status
         }
      }
      // DQ7 is the same as original data, flash is ready
      else
      {
         NOR_FLASH_BUSY = KAL_FALSE;
         check_data = *(volatile kal_uint16*)addr;

         // check all FLASH_CELL data, not only DQ7
         if(check_data == data)
         {
            status = RESULT_FLASH_DONE;
         }
         else
         {
            status = RESULT_FLASH_FAIL;
         }
      }
   }

   INT_RestoreDataCache(data_cache_id);

   RestoreIRQMask(savedMask);

   deassertCheck();

   // reset poll_times if the device ready checking is done
   if (status != RESULT_FLASH_BUSY) {
      poll_times = 0;
   }

   return status;
}

#endif //__AMD_SERIES_NOR_PROGRAM__ || __TOSHIBA_TV__ || __TOSHIBA_TY__


#endif /* __SINGLE_BANK_NOR_FLASH_SUPPORT__ */


//Common word program function for AMD series flash except WVSR series
//Caller: ProgramData_TOSHIBA, ProgramData_AMD
#if defined(__AMD_SERIES_NOR_PROGRAM__) || defined(__TOSHIBA_TV__) || defined(__TOSHIBA_TY__)
__nor_section_RAM kal_int32 WordProgram_AMD(volatile FLASH_CELL* bp, volatile FLASH_CELL* Address, FLASH_CELL Data)
{
   kal_uint32 savedMask;
   kal_int32 result = RESULT_FLASH_BUSY;

   savedMask = SaveAndSetIRQMask();

   bp[ADDR_UNLOCK_1] = CMD_UNLOCK_1;
   bp[ADDR_UNLOCK_2] = CMD_UNLOCK_2;
   bp[ADDR_UNLOCK_1] = CMD_PROG;
   Address[0] = Data;

   NOR_PROFILE_MTD_WRITE_Start();
#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)

   NOR_FLASH_BUSY = KAL_TRUE;
   RestoreIRQMask(savedMask);
   do
   {
      result = CheckReadyAndResume_AMD((kal_uint32)Address, Data);
      BLTest(1);
   }
   while (result == RESULT_FLASH_BUSY);

#else  /* multi-bank */
   RestoreIRQMask(savedMask);
   result = WaitReady_AMD((kal_uint32)Address, Data);
#endif /* __SINGLE_BANK_NOR_FLASH_SUPPORT__ */
   NOR_PROFILE_MTD_WRITE_End();

   return result;

}
#endif //__AMD_SERIES_NOR_PROGRAM__ || __TOSHIBA_TV__ || __TOSHIBA_TY__

/*-----------------------------------*/
#if (defined(__TOSHIBA_TV__) || defined(__TOSHIBA_TY__))


// both TOSHIBA TV and TY use 8 word auto page program
#define PROGRAM_WORDS_TOSHIBA 8

__nor_section_RAM kal_int32 BufferProgram_TOSHIBA(volatile FLASH_CELL* bp, volatile FLASH_CELL* fp, FLASH_CELL* prog_buffer)
{
   kal_uint32 savedMask;
   kal_int32 result = RESULT_FLASH_BUSY;
   kal_uint32 i;

   /* both TOSHIBA TV and TY use 8 word auto page program */

   savedMask = SaveAndSetIRQMask();

   bp[ADDR_UNLOCK_1] = CMD_UNLOCK_1;
   bp[ADDR_UNLOCK_2] = CMD_UNLOCK_2;
   bp[ADDR_UNLOCK_1] = 0xE6;

   for(i = 0; i < PROGRAM_WORDS_TOSHIBA; i++)
   {
      fp[i] = prog_buffer[i];
   }

#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)

   NOR_FLASH_BUSY = KAL_TRUE;
#endif

   RestoreIRQMask(savedMask);

   NOR_PROFILE_MTD_WRITE_Start();

#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)

   do
   {
      result = CheckReadyAndResume_AMD((kal_uint32)&fp[PROGRAM_WORDS_TOSHIBA-1], (kal_uint16)prog_buffer[PROGRAM_WORDS_TOSHIBA-1]);
      BLTest(3);
   }
   while(result == RESULT_FLASH_BUSY);
#else
   result = WaitReady_AMD((kal_uint32)&fp[PROGRAM_WORDS_TOSHIBA -1], (kal_uint16)prog_buffer[PROGRAM_WORDS_TOSHIBA-1]);

#endif

   NOR_PROFILE_MTD_WRITE_End();


   return result;

}


__nor_section_RAM int ProgramData_TOSHIBA(void * DriveData, void * Address, void * Data, kal_uint32 Length)
{
   kal_int32 result = RESULT_FLASH_BUSY;

#ifndef __NOR_FDM5__
   NOR_Flash_MTD_Data * D = DriveData;
   volatile FLASH_CELL *bp = (volatile FLASH_CELL *) (D->CurrAddr);
   ASSERT((~D->Signature == (kal_uint32)D->RegionInfo));
#else
   NOR_MTD_DATA *D= DriveData;
   NORLayoutInfo * Layout = D->LayoutInfo;
   volatile FLASH_CELL *bp = (volatile FLASH_CELL *)((kal_uint32)Address&(~((Layout->BlkSize-1))));
   ASSERT(D->Signature == ~((kal_uint32)D->LayoutInfo));
#endif

#ifdef DEBUG
   //can't write zero bytes into flash
   ASSERT(Length != 0);
#endif

   waitNonBlockEraseDone();

   NOR_PROFILE_MTD_WRITE_Count();

   switch (Length)
   {
      case sizeof(FLASH_CELL):
#if defined(DEBUG)
         //Misaligned write into flash
         ASSERT(!(((kal_uint32)Address) % sizeof(FLASH_CELL)));
#endif

#ifdef DEBUG
         //Attempt to set bits in flash!
         ASSERT(!(~((volatile FLASH_CELL*)Address)[0] & ((FLASH_CELL*)Data)[0]));
#endif

         result = WordProgram_AMD(bp, Address, *((FLASH_CELL*)Data));


         break;

      case 1:
      {
         volatile FLASH_CELL *fp;
         kal_uint32 ofs = ((kal_uint32) Address) & (sizeof(FLASH_CELL)-1);
         FLASH_CELL Cell;
         kal_uint8 *b = (kal_uint8*) &Cell;

         fp   = (void*) (((kal_uint32) Address) & ~(sizeof(FLASH_CELL)-1)); // round it down
         Cell = fp[0];

         b[ofs] = ((kal_uint8*)Data)[0];

#ifdef DEBUG
         //Attempt to set bits in flash!
         ASSERT(!((~fp[0]) & Cell))
#endif

         result = WordProgram_AMD(bp, fp, Cell);

      }
      break;
      default:
#ifdef DEBUG
         //Misaligned write into flash
         ASSERT(!(((kal_uint32)Address) % sizeof(FLASH_CELL)));
         //Misaligned length write into flash
         ASSERT(!(Length % sizeof(FLASH_CELL)));
         {
            kal_uint32 i;
            volatile FLASH_CELL *fp = (void*) Address;
            FLASH_CELL * V = Data;

            for (i=0; i<Length/sizeof(FLASH_CELL); i++)
               ASSERT(!((~fp[i]) & V[i]));//Attempt to set bits in flash!
         }
#endif

         {
            kal_uint32 i, j=0;
            kal_uint32 Words;
            volatile FLASH_CELL *fp;

            fp = (volatile FLASH_CELL *)Address;
            if((((kal_uint32)Data) % sizeof(FLASH_CELL)))
            {
               kal_uint8 *bdp =  (kal_uint8*)Data;
               FLASH_CELL Cell;
               kal_uint8 *b = (kal_uint8*)&Cell;

               FLASH_CELL prog_buffer[PROGRAM_WORDS_TOSHIBA];
               Words = (Length/sizeof(FLASH_CELL));
               b = (kal_uint8 *)prog_buffer;
               j = 0;

               while(Words > 0 )
               {
                  NOR_PROFILE_MTD_WRITE_Count();
                  if ((Words >= PROGRAM_WORDS_TOSHIBA) && (!((kal_uint32)fp & (PROGRAM_WORDS_TOSHIBA*sizeof(FLASH_CELL)-1))) )
                  {
                     for(i = 0; i < PROGRAM_WORDS_TOSHIBA*sizeof(FLASH_CELL); i++)
                     {
                        b[i] = bdp[j++];
                     }

                     result = BufferProgram_TOSHIBA(bp,fp,prog_buffer);

                     Words -= PROGRAM_WORDS_TOSHIBA;
                     fp += PROGRAM_WORDS_TOSHIBA;
                  }
                  else
                  {
                     b[0] = bdp[j++];
                     b[1] = bdp[j++];

                     result = WordProgram_AMD(bp, fp, Cell);

                     Words -= 1;
                     fp += 1;
                  }

                  if(result == RESULT_FLASH_FAIL)
                     return RESULT_FLASH_FAIL;

               }
            }
            else
            {
               FLASH_CELL *dp = (FLASH_CELL*)Data;

               Words = (Length/sizeof(FLASH_CELL));

               while(Words > 0 )
               {
                  if ((Words >= PROGRAM_WORDS_TOSHIBA) && (!((kal_uint32)fp & (PROGRAM_WORDS_TOSHIBA*sizeof(FLASH_CELL)-1))) )
                  {

                     result = BufferProgram_TOSHIBA(bp,fp,dp);

                     Words -= PROGRAM_WORDS_TOSHIBA;
                     fp += PROGRAM_WORDS_TOSHIBA;
                     dp += PROGRAM_WORDS_TOSHIBA;
                  }
                  else
                  {

                     result = WordProgram_AMD(bp, fp, dp[0]);

                     Words -= 1;
                     fp += 1;
                     dp += 1;
                  }

                  if(result == RESULT_FLASH_FAIL)
                     return RESULT_FLASH_FAIL;


               }
            }
         }
         break;
   }

   if(result == RESULT_FLASH_FAIL)
      return RESULT_FLASH_FAIL;

   return FS_NO_ERROR;
}
#endif //__TOSHIBA_TV__ || __TOSHIBA_TY__

#if (defined(__SPANSION_VS_R__) || defined(__SPANSION_WS_R__))

__nor_section_RAM kal_int32 UnalignedDataBufferProgram_WVSR(volatile FLASH_CELL* bp, volatile FLASH_CELL* fp, kal_uint8 * bdp, kal_uint32 ProgramWords, kal_bool isHeader)
{
   kal_uint32 savedMask;
   kal_int32 result = RESULT_FLASH_BUSY;

   kal_uint32 ISRCountBefore,ISRCountAfter;
   kal_uint32 i, j;

   volatile FLASH_CELL *dfp;

   FLASH_CELL Cell;
   kal_uint8 *b = (kal_uint8*)&Cell;
   dfp = fp;
   j = 0;

   ISRCountBefore = PROCESSING_IRQ_CNT;

   bp[ADDR_UNLOCK_1] = WVSR_CMD_CLR_SR;

   bp[ADDR_UNLOCK_1] = CMD_WRITETOBUFFER;
   bp[ADDR_UNLOCK_2] = ProgramWords -1;// set data count
   b[0] = bdp[j++];
   b[1] = bdp[j++];
   *dfp++ = Cell;

   for(i = 1; i < ProgramWords; i++)
   {
      b[0] = bdp[j++];
      b[1] = bdp[j++];
      *dfp++ = Cell;
   }

   savedMask = SaveAndSetIRQMask();

   bp[ADDR_UNLOCK_1] = CMD_BUFFERTOFLASH;
   ISRCountAfter = PROCESSING_IRQ_CNT;

   NOR_PROFILE_MTD_WRITE_Start();
#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)
   isProgram = KAL_TRUE;
   NOR_FLASH_BUSY = KAL_TRUE;
#endif
   RestoreIRQMask(savedMask);

#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)
   ResetInBusy();
   do
   {
      result = CheckReadyAndResume_WVSR((kal_uint32)bp);
      BLTest(1);
   }
   while (result == RESULT_FLASH_BUSY);
   isProgram = KAL_FALSE;
#else  /* multi-bank */
   result = WaitReady_WVSR((kal_uint32)bp);
#endif
   NOR_PROFILE_MTD_WRITE_End();

   if( (ISRCountBefore != ISRCountAfter) || isHeader)
   {
      //the unit of bdp is kal_uint8, start address of this round is from Length - programed bytes
      if(CompareData((void*)fp,(void*)bdp,ProgramWords*sizeof(FLASH_CELL))==KAL_TRUE)
      {
         if(isHeader)
         {
            result = RESULT_FLASH_FAIL;
         }
         else
         {
            MTD_ASSERT(0, 0, 0, 0, NOR_MTD_PROGRAM_COMP_DATA_FAIL);
         }
      }
   }



   return result;

}



__nor_section_RAM kal_int32 AlignedDataBufferProgram_WVSR(volatile FLASH_CELL* bp, volatile FLASH_CELL* fp, FLASH_CELL* dp, kal_uint32 ProgramWords, kal_bool isHeader)
{
   kal_uint32 savedMask;
   kal_int32 result = RESULT_FLASH_BUSY;
   kal_uint32 i;
   kal_uint32 ISRCountBefore,ISRCountAfter;

   volatile FLASH_CELL *dfp;
   FLASH_CELL *dtp;



   dfp = fp;
   dtp = dp;

   ISRCountBefore = PROCESSING_IRQ_CNT;

   bp[ADDR_UNLOCK_1] = WVSR_CMD_CLR_SR;

   bp[ADDR_UNLOCK_1] = CMD_WRITETOBUFFER;
   bp[ADDR_UNLOCK_2] = ProgramWords -1;// set data count

   for(i = 0; i < ProgramWords; i++)
   {
      *dfp++ = *dtp++;
   }

   savedMask = SaveAndSetIRQMask();

   bp[ADDR_UNLOCK_1] = CMD_BUFFERTOFLASH;
   ISRCountAfter = PROCESSING_IRQ_CNT;

#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)
   isProgram = KAL_TRUE;
   NOR_FLASH_BUSY = KAL_TRUE;
#endif
   RestoreIRQMask(savedMask);

#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)
   ResetInBusy();

   do
   {
      result = CheckReadyAndResume_WVSR((kal_uint32)bp);
      BLTest(1);
   }
   while (result == RESULT_FLASH_BUSY);

   isProgram = KAL_FALSE;

#else  /* multi-bank */

   result = WaitReady_WVSR((kal_uint32)bp);
#endif

   if( (ISRCountBefore != ISRCountAfter) || isHeader)
   {
      if (CompareData((void*)fp,(void*)dp,ProgramWords*sizeof(FLASH_CELL))==KAL_TRUE)
      {
         if (isHeader)
         {
            return RESULT_FLASH_FAIL;
         }
         else
         {
            MTD_ASSERT(0, 0, 0, 0, NOR_MTD_PROGRAM_COMP_DATA_FAIL);
         }
      }
   }


   return result;

}


__nor_section_RAM static int ProgramData_WVSR(void * DriveData, void * Address, void * Data, kal_uint32 Length)
{
   kal_int32 result = RESULT_FLASH_BUSY;

#ifndef __NOR_FDM5__
   NOR_Flash_MTD_Data * D = DriveData;
   volatile FLASH_CELL *bp = (volatile FLASH_CELL *) D->CurrAddr;
   ASSERT((~D->Signature == (kal_uint32)D->RegionInfo));
#else
   NOR_MTD_DATA *D= DriveData;
   NORLayoutInfo * Layout = D->LayoutInfo;
   volatile FLASH_CELL *bp = (volatile FLASH_CELL *)((kal_uint32)Address&(~((Layout->BlkSize-1))));
   ASSERT(D->Signature == ~((kal_uint32)D->LayoutInfo));
#endif

#if defined(__BASIC_LOAD_FLASH_TEST__)
   ProgramNum++;
#endif

#ifdef DEBUG
   //can't write zero bytes into flash
   ASSERT(Length != 0);
#endif

   waitNonBlockEraseDone();

   NOR_PROFILE_MTD_WRITE_Count();
   switch (Length)
   {
      case sizeof(FLASH_CELL):
      {
#ifdef DEBUG
         //Misaligned write into flash
         ASSERT(!(((kal_uint32)Address) % sizeof(FLASH_CELL)));
         //Attempt to set bits in flash!
         ASSERT(!(~((volatile FLASH_CELL*)Address)[0] & ((FLASH_CELL*)Data)[0]));
#endif

         result = AlignedDataBufferProgram_WVSR(bp, ((volatile FLASH_CELL*)Address), (FLASH_CELL*)Data, 1, KAL_TRUE);

         break;
         case 1:
         {
            volatile FLASH_CELL *fp;
            kal_uint32 ofs = ((kal_uint32) Address) & (sizeof(FLASH_CELL)-1);
            FLASH_CELL Cell;
            kal_uint8 *b = (kal_uint8*) &Cell;

            fp   = (volatile FLASH_CELL *) (((kal_uint32) Address) & ~(sizeof(FLASH_CELL)-1)); // round it down
            Cell = fp[0];

            b[ofs] = ((kal_uint8*)Data)[0];

#ifdef DEBUG
            //Attempt to set bits in flash!
            ASSERT(!((~fp[0]) & Cell))
#endif

            result = AlignedDataBufferProgram_WVSR(bp, fp, &Cell, 1, KAL_TRUE);

         }
         NOR_PROFILE_MTD_WRITE_End();

         break;

         default:

#ifdef DEBUG
            //Misaligned write into flash
            ASSERT(!(((kal_uint32)Address) % sizeof(FLASH_CELL)));
            //Misaligned length write into flash
            ASSERT(!(Length % sizeof(FLASH_CELL)));
            {
               kal_uint32 i;
               volatile FLASH_CELL *fp = (void*) Address;
               FLASH_CELL * V = Data;

               for (i=0; i<Length/sizeof(FLASH_CELL); i++)
                  ASSERT(!((~fp[i]) & V[i]));//Attempt to set bits in flash!
            }
#endif /*DEBUG*/

            {
               kal_uint32 Words;
               kal_uint32 ProgramWords;
               volatile FLASH_CELL *fp;

               fp = (volatile FLASH_CELL *)Address;
               if((((kal_uint32)Data) % sizeof(FLASH_CELL)))
               {
                  kal_uint8 *bdp =  (kal_uint8*)Data;

                  Words = (Length/sizeof(FLASH_CELL));
                  while(Words>0)
                  {
                     ProgramWords = Words > PAGE_BUFFER_SIZE ?  PAGE_BUFFER_SIZE : Words ;
                     if ((kal_uint32)fp & (sizeof(FLASH_CELL) * PAGE_BUFFER_SIZE - 1))
                     {
                        FLASH_CELL *pageb = (FLASH_CELL *)((kal_uint32)(fp+ PAGE_BUFFER_SIZE) & (~(sizeof(FLASH_CELL)*PAGE_BUFFER_SIZE -1)));
                        if ( ProgramWords > (pageb-fp))
                           ProgramWords = pageb - fp;
                     }

                     result = UnalignedDataBufferProgram_WVSR(bp, fp, bdp, ProgramWords, (kal_bool)(Length<=4));

                     if(result == RESULT_FLASH_FAIL)
                        return result;

                     Words -= ProgramWords;
                     fp += ProgramWords;
                     bdp += ProgramWords*sizeof(FLASH_CELL);
                  } //while
               }
               else /* !if((((kal_uint32)Data) % sizeof(FLASH_CELL))) */
               {
                  FLASH_CELL *dp = (FLASH_CELL*)Data;
                  Words = (Length/sizeof(FLASH_CELL));
                  while(Words>0)
                  {
                     ProgramWords = Words > PAGE_BUFFER_SIZE ?  PAGE_BUFFER_SIZE : Words ;
                     if ((kal_uint32)fp & (sizeof(FLASH_CELL)*PAGE_BUFFER_SIZE -1))
                     {
                        FLASH_CELL *pageb = (FLASH_CELL *)((kal_uint32)(fp+ PAGE_BUFFER_SIZE) & (~(sizeof(FLASH_CELL)*PAGE_BUFFER_SIZE -1)));
                        if ( ProgramWords > (pageb-fp))
                           ProgramWords = pageb - fp;
                     }

                     result = AlignedDataBufferProgram_WVSR(bp, fp, dp, ProgramWords, (kal_bool)(Length<=4));

                     if(result == RESULT_FLASH_FAIL)
                        return RESULT_FLASH_FAIL;

                     Words -= ProgramWords;
                     fp += ProgramWords;
                     dp += ProgramWords;
                  }
               }
            }
            break;
         }
   }

   if(result == RESULT_FLASH_FAIL)
      return RESULT_FLASH_FAIL;

   return FS_NO_ERROR;
}

#endif //__SPANSION_VS_R__ || __SPANSION_WS_R__

#if defined(__AMD_SERIES_NOR_PROGRAM__) //defined in flash_mtd.h

__nor_section_RAM kal_int32 UnalignedDataBufferProgram_AMD(volatile FLASH_CELL* bp, volatile FLASH_CELL* fp, kal_uint8 * bdp, kal_uint32 ProgramWords, kal_bool isHeader)
{
   kal_uint32 savedMask;
   kal_int32 result = RESULT_FLASH_BUSY;
   kal_uint32 ISRCountBefore,ISRCountAfter;
   kal_uint32 i, j;

   volatile FLASH_CELL *dfp;

   FLASH_CELL Cell;
   kal_uint8 *b = (kal_uint8*)&Cell;
   dfp = fp;
   j = 0;


   ISRCountBefore = PROCESSING_IRQ_CNT;

   bp[ADDR_UNLOCK_1] = CMD_UNLOCK_1;
   bp[ADDR_UNLOCK_2] = CMD_UNLOCK_2;
   *dfp = CMD_WRITETOBUFFER;
   *dfp = ProgramWords -1;// set data count
   b[0]=bdp[j++];
   b[1]=bdp[j++];
   *dfp++ = Cell;

   for(i = 1; i < ProgramWords; i++)
   {
      b[0]=bdp[j++];
      b[1]=bdp[j++];
      *dfp++ = Cell;
   }

   savedMask = SaveAndSetIRQMask();

   fp[0] = CMD_BUFFERTOFLASH;

   ISRCountAfter = PROCESSING_IRQ_CNT;


#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)  //single bank
   NOR_FLASH_BUSY = KAL_TRUE;
#endif

   RestoreIRQMask(savedMask);

   NOR_PROFILE_MTD_WRITE_Start();

#ifdef __SPANSION_PL_N__
   DelayAWhile_UST(5);  // Spansion PLN needs additional 5us delay after buffer program
#endif /* __SPANSION_PL_N__ */

#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)
   do
   {
      result = CheckReadyAndResume_AMD((kal_uint32)&fp[ProgramWords -1], (kal_uint16)Cell);
      BLTest(3);
   }
   while (result == RESULT_FLASH_BUSY);

#else  /* multi-bank */
   result = WaitReady_AMD((kal_uint32)&fp[ProgramWords -1], (kal_uint16)Cell);

#endif  /* __SINGLE_BANK_NOR_FLASH_SUPPORT__ */

   NOR_PROFILE_MTD_WRITE_End();

   if((ISRCountBefore != ISRCountAfter) || isHeader)
   {
      if(CompareData((void*)fp,(void*)bdp,ProgramWords*sizeof(FLASH_CELL))==KAL_TRUE)
      {
         if(isHeader)
         {
            return RESULT_FLASH_FAIL;
         }
         else
         {
            MTD_ASSERT(0, 0, 0, 0, NOR_MTD_PROGRAM_COMP_DATA_FAIL);
         }
      }
   }



   return result;

}


__nor_section_RAM kal_int32 AlignedDataBufferProgram_AMD(volatile FLASH_CELL* bp, volatile FLASH_CELL* fp, FLASH_CELL* dp, kal_uint32 ProgramWords, kal_bool isHeader)
{
   kal_uint32 savedMask;
   kal_int32 result = RESULT_FLASH_BUSY;
   kal_uint32 i;
   kal_uint32 ISRCountBefore,ISRCountAfter;

   volatile FLASH_CELL *dfp;
   FLASH_CELL *dtp;

   dfp = fp;
   dtp = dp;

   ISRCountBefore = PROCESSING_IRQ_CNT;

   bp[ADDR_UNLOCK_1] = CMD_UNLOCK_1;
   bp[ADDR_UNLOCK_2] = CMD_UNLOCK_2;
   *fp = CMD_WRITETOBUFFER;
   *fp = ProgramWords -1;// set data count

   for(i = 0; i < ProgramWords; i++)
   {
      *dfp++ = *dtp++;
   }

   savedMask = SaveAndSetIRQMask();

   *fp = CMD_BUFFERTOFLASH;
   ISRCountAfter = PROCESSING_IRQ_CNT;

#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)
   NOR_FLASH_BUSY = KAL_TRUE;
#endif
   RestoreIRQMask(savedMask);

   NOR_PROFILE_MTD_WRITE_Start();

#ifdef __SPANSION_PL_N__
   DelayAWhile_UST(5);  // Spansion PLN needs additional 5us delay after buffer program
#endif /* __SPANSION_PL_N__ */

#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)
   do
   {
      result = CheckReadyAndResume_AMD((kal_uint32)&fp[ProgramWords -1], (kal_uint16)dp[ProgramWords -1]);
      BLTest(3);
   }
   while (result == RESULT_FLASH_BUSY);

#else /* multi-bank */

   result = WaitReady_AMD((kal_uint32)&fp[ProgramWords -1], (kal_uint16)dp[ProgramWords -1]);

#endif /* __SINGLE_BANK_NOR_FLASH_SUPPORT__ */
   NOR_PROFILE_MTD_WRITE_End();

   if( (ISRCountBefore != ISRCountAfter) || isHeader)
   {
      if (CompareData((void*)fp,(void*)dp,ProgramWords)==KAL_TRUE)
      {
         if (isHeader)
         {
            return RESULT_FLASH_FAIL;
         }
         else
         {
            MTD_ASSERT(0, 0, 0, 0, NOR_MTD_PROGRAM_COMP_DATA_FAIL);
         }
      }
   }


   return result;

}

// The function modify original ProgramData_AMD and add
// 1. Enable IRQ while buffer program data trasnfering in ESB, support full page buffer program instead of only 8 words
__nor_section_RAM static int ProgramData_AMD(void * DriveData, void * Address, void * Data, kal_uint32 Length)
{
   kal_int32 result = RESULT_FLASH_BUSY;
#ifdef __SPANSION_NS_N__
   volatile FLASH_CELL *BlkAddr;
#endif

#ifndef __NOR_FDM5__
   NOR_Flash_MTD_Data * D = DriveData;
   volatile FLASH_CELL *bp = (volatile FLASH_CELL *) D->CurrAddr;
   ASSERT((~D->Signature == (kal_uint32)D->RegionInfo));
#else
   NOR_MTD_DATA *D= DriveData;
   NORLayoutInfo * Layout = D->LayoutInfo;
   volatile FLASH_CELL *bp = (volatile FLASH_CELL *)((kal_uint32)Address&(~((Layout->BlkSize-1))));
   ASSERT(D->Signature == ~((kal_uint32)D->LayoutInfo));
#endif

#ifdef __SPANSION_NS_N__
   BlkAddr = (volatile FLASH_CELL *)CalBlkAddr(DriveData, (kal_uint32)Address);
   DYBCMD_AMD(D,BlkAddr,DYB_UNLOCK);
#endif

#if defined(__BASIC_LOAD_FLASH_TEST__)
   ProgramNum++;
#endif

#ifdef DEBUG
   //can't write zero bytes into flash
   ASSERT(Length != 0);
#endif

   waitNonBlockEraseDone();

   NOR_PROFILE_MTD_WRITE_Count();
   switch (Length)
   {
      case sizeof(FLASH_CELL):
#ifdef DEBUG
         //Misaligned write into flash
         ASSERT(!(((kal_uint32)Address) % sizeof(FLASH_CELL)));
         //Attempt to set bits in flash!
         ASSERT(!(~((volatile FLASH_CELL*)Address)[0] & ((FLASH_CELL*)Data)[0]));
#endif

         result = WordProgram_AMD(bp, Address, *((FLASH_CELL*)Data));

         break;

      case 1:
      {
         volatile FLASH_CELL *fp;
         kal_uint32 ofs = ((kal_uint32) Address) & (sizeof(FLASH_CELL)-1);
         FLASH_CELL Cell;
         kal_uint8 *b = (kal_uint8*) &Cell;

         fp   = (volatile FLASH_CELL *) (((kal_uint32) Address) & ~(sizeof(FLASH_CELL)-1)); // round it down
         Cell = fp[0];

         b[ofs] = ((kal_uint8*)Data)[0];

#ifdef DEBUG
         //Attempt to set bits in flash!
         ASSERT(!((~fp[0]) & Cell))
#endif

         result = WordProgram_AMD(bp, fp, Cell);

         break;

      }
      
      default:

#ifdef DEBUG
         //Misaligned write into flash
         ASSERT(!(((kal_uint32)Address) % sizeof(FLASH_CELL)));
         //Misaligned length write into flash
         ASSERT(!(Length % sizeof(FLASH_CELL)));
         {
            kal_uint32 i;
            volatile FLASH_CELL *fp = (void*) Address;
            FLASH_CELL * V = Data;

            for (i=0; i<Length/sizeof(FLASH_CELL); i++)
               ASSERT(!((~fp[i]) & V[i]));//Attempt to set bits in flash!
         }
#endif /*DEBUG*/

         {
            kal_uint32 i, j;


// if __COMBO_MEMORY_SUPPORT__ is defined, check the current device PAGE_BUFFER_SIZE to ensure current device support page buffer program
// if PAGE_BUFFER_SIZE == 0, the current device only support single wod program
// if __COMBO_MEMORY_SUPPORT__ is not defined, always do single word program
#if defined(__COMBO_MEMORY_SUPPORT__)
            if(PAGE_BUFFER_SIZE == 0)
#endif //__COMBO_MEMORY_SUPPORT__				
#if !defined(__PAGE_BUFFER_PROGRAM__) || defined(__COMBO_MEMORY_SUPPORT__)
            {

               volatile FLASH_CELL *fp;

               fp = (volatile FLASH_CELL *)Address;
               if((((kal_uint32)Data) % sizeof(FLASH_CELL)))
               {
                  kal_uint8 *bdp =  (kal_uint8*)Data;
                  FLASH_CELL Cell;
                  kal_uint8 *b = (kal_uint8*)&Cell;
                  j = 0;
                  for(i = 0; i < Length/sizeof(FLASH_CELL); i++)
                  {
                     b[0] = bdp[j++];
                     b[1] = bdp[j++];

                     result = WordProgram_AMD(bp, fp, Cell);

                     if(result == RESULT_FLASH_FAIL)
                        return RESULT_FLASH_FAIL;

                  }

               }
               else /* !if((((kal_uint32)Data) % sizeof(FLASH_CELL))) */
               {
                  FLASH_CELL *dp = (FLASH_CELL*)Data;
                  for(i = 0; i < Length/sizeof(FLASH_CELL); i++)
                  {
                     result = WordProgram_AMD(bp, &fp[i],dp[i]);

                     if(result == RESULT_FLASH_FAIL)
                        return RESULT_FLASH_FAIL;

                  }
               }
            }
#endif // !__COMBO_MEMORY_SUPPORT__ && !__PAGE_BUFFER_PROGRAM__


#if defined(__PAGE_BUFFER_PROGRAM__)
#if defined(__COMBO_MEMORY_SUPPORT__)
               if(PAGE_BUFFER_SIZE != 0)
#endif
               {

                  kal_uint32 Words;
                  kal_uint32 ProgramWords;
                  volatile FLASH_CELL *fp;

                  fp = (volatile FLASH_CELL *)Address;
                  if((((kal_uint32)Data) % sizeof(FLASH_CELL)))
                  {
                     kal_uint8 *bdp =	(kal_uint8*)Data;

                     Words = (Length/sizeof(FLASH_CELL));
                     while(Words>0)
                     {
                        j = 0;
                        ProgramWords = Words > PAGE_BUFFER_SIZE ?	PAGE_BUFFER_SIZE : Words ;
                        if ((kal_uint32)fp & (sizeof(FLASH_CELL) * PAGE_BUFFER_SIZE - 1))
                        {
                           FLASH_CELL *pageb = (FLASH_CELL *)((kal_uint32)(fp+ PAGE_BUFFER_SIZE) & (~(sizeof(FLASH_CELL)*PAGE_BUFFER_SIZE -1)));
                           if ( ProgramWords > (pageb-fp))
                              ProgramWords = pageb - fp;
                        }

                        result = UnalignedDataBufferProgram_AMD(bp, fp, bdp, ProgramWords,(kal_bool)(Length<=4));

                        if(result == RESULT_FLASH_FAIL)
                           return RESULT_FLASH_FAIL;

                        Words -= ProgramWords;
                        fp += ProgramWords;
                        bdp += ProgramWords * sizeof(FLASH_CELL);
                     }


                  }
                  else /* !if((((kal_uint32)Data) % sizeof(FLASH_CELL))) */
                  {
                     FLASH_CELL *dp = (FLASH_CELL*)Data;

                     Words = (Length/sizeof(FLASH_CELL));
                     while(Words>0)
                     {
                        ProgramWords = Words > PAGE_BUFFER_SIZE ?	PAGE_BUFFER_SIZE : Words ;
                        if ((kal_uint32)fp & (sizeof(FLASH_CELL)*PAGE_BUFFER_SIZE -1))
                        {
                           FLASH_CELL *pageb = (FLASH_CELL *)((kal_uint32)(fp+ PAGE_BUFFER_SIZE) & (~(sizeof(FLASH_CELL)*PAGE_BUFFER_SIZE -1)));
                           if ( ProgramWords > (pageb-fp))
                              ProgramWords = pageb - fp;
                        }

                        result = AlignedDataBufferProgram_AMD(bp, fp, dp, ProgramWords, (kal_bool)(Length <= 4));


                        if(result == RESULT_FLASH_FAIL)
                           return RESULT_FLASH_FAIL;

                        Words -= ProgramWords;
                        fp += ProgramWords;
                        dp += ProgramWords;
                     }

                  }

               }

#endif //__PAGE_BUFFER_PROGRAM__

         }
         break;
   }
#ifdef __SPANSION_NS_N__
   DYBCMD_AMD(D,BlkAddr,DYB_LOCK);
#endif

   if(result == RESULT_FLASH_FAIL)
      return RESULT_FLASH_FAIL;

   return FS_NO_ERROR;
}

#endif //__TOSHIBA_TV__


// In FUE environment, no need to wait flash to become ready
#if !defined(__FUE__) && !defined(__UBL__)

#if (defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__))

extern NOR_FLASH_DRV_Data  FlashDriveData;

#if defined(__FOTA_DM__)
extern kal_bool            FOTA_Flash_busy;
extern NOR_FLASH_DRV_Data  NORFlashDriveData;
#endif /* __FOTA_DM__ */


// The below function is only invoked by MAUI, should not linked in bootloader
#if (defined(__SPANSION_VS_R__) || defined(__SPANSION_WS_R__))

__nor_section_RAM kal_bool isProgram_WVSR()
{
   return isProgram;
}
#endif


#if !defined(__COMBO_MEMORY_SUPPORT__)
#if (defined(__SPANSION_VS_R__) || defined(__SPANSION_WS_R__))
__nor_section_RAM static void waitReady(volatile FLASH_CELL *flash_base) /* instruction prefetch should be disabled */
{
   static FLASH_CELL s = 0 ;
   #ifdef NOR_RESUME_SUSPEND_INTERVAL
   kal_uint32        resume_to_suspend_duration;
   #endif
  
#ifdef NOR_RESUME_SUSPEND_INTERVAL

   /* if flash was ever resumed */
   if (resume_time_g != NOR_DEFAULT_RESUME_TIME)
   {
      /* get current time */
      resume_to_suspend_duration = ust_get_current_time();

      /* calculate duration from last resume */
      resume_to_suspend_duration = ust_qbit_to_us(ust_get_duration(resume_time_g, resume_to_suspend_duration));

      /* wait awhile to satisfy timing requirement (tERS) */
      if (resume_to_suspend_duration < NOR_RESUME_SUSPEND_INTERVAL)
      {
         DelayAWhile_UST(NOR_RESUME_SUSPEND_INTERVAL - resume_to_suspend_duration);
      }

      /* reset resume_time_g */
      resume_time_g = NOR_DEFAULT_RESUME_TIME;
   }

#endif   /* NOR_RESUME_SUSPEND_INTERVAL */  

  
   /* issue suspend command */
   if(isProgram)
      flash_base[ADDR_UNLOCK_1] = WVSR_CMD_PROGRAM_SUSPEND;
   else
      flash_base[ADDR_UNLOCK_1] = WVSR_CMD_ERASE_SUSPEND;
      
   #ifdef NOR_SUSPEND_LATENCY
   DelayAWhile_UST(NOR_SUSPEND_LATENCY);
   #else
   DelayAWhile_UST(5);
   #endif

   flash_base[ADDR_UNLOCK_1] = WVSR_CMD_RD_SR;

   s = flash_base[0];
   while(!(s&WVSR_READY_FLAG))
   {
      flash_base[ADDR_UNLOCK_1] = WVSR_CMD_RD_SR;
      s = flash_base[0];
   }
   NOR_FLASH_SUSPENDED = KAL_TRUE;

}

#else // !__SPANSION_VS_R__ && __SPANSION_WS_R__2010-09-13 18:34
/*******************************************************************//**
 * Issue suspend command and wait until flash is suspended
 *
 * @par Category:
 * NOR MTD (Enhanced Single Bank)
 *
 * @par Change Log:
 * 2008-11-20: Add Spansion WSP support: wait awhile to satisfy tERS before issue suspend
 *             command, then wait another 40us to satisfy tESL before polling.
 * 2008-11-27: Modify Spansion WSP support to general tESL and tERS support for all Spansion NOR flash.
 *
 * @note
 * Only called by Flash_ReturnReady
 **********************************************************************/
__nor_section_RAM static void waitReady(volatile FLASH_CELL *flash_base) /* instruction prefetch should be disabled */
{
   /*----------------------------------------------------------------
    * Local Variables
    *----------------------------------------------------------------*/

   static kal_uint16 toggle1 = 0 ;
   static kal_uint16 toggle2 = 0;
   #ifdef NOR_RESUME_SUSPEND_INTERVAL
   kal_uint32        resume_to_suspend_duration;
   #endif

   NOR_Flash_MTD_Data  *mtd_data = NULL;
   volatile kal_uint16 *check_ptr = NULL;

   #if defined(__FOTA_DM__)
   if(FOTA_Flash_busy)
   {
      mtd_data = (NOR_Flash_MTD_Data *)NORFlashDriveData.MTDData;
   }
   else
   #endif   /* __FOTA_DM__ */
   {
      mtd_data = (NOR_Flash_MTD_Data *)FlashDriveData.MTDData;
   }
   #if defined(__MULTI_BANK_NOR_DEVICE__)
   check_ptr = (volatile kal_uint16*)mtd_data->CurrPollAddr;
   #else
   check_ptr = (volatile kal_uint16*)mtd_data->BaseAddr;
   #endif //__MULTI_BANK_NOR_DEVICE__


   /*----------------------------------------------------------------
    * Code Body
    *----------------------------------------------------------------*/

#ifdef NOR_RESUME_SUSPEND_INTERVAL

   /* if flash was ever resumed */
   if (resume_time_g != NOR_DEFAULT_RESUME_TIME)
   {
      /* get current time */
      resume_to_suspend_duration = ust_get_current_time();

      /* calculate duration from last resume */
      resume_to_suspend_duration = ust_qbit_to_us(ust_get_duration(resume_time_g, resume_to_suspend_duration));

      /* wait awhile to satisfy timing requirement (tERS) */
      if (resume_to_suspend_duration < NOR_RESUME_SUSPEND_INTERVAL)
      {
         DelayAWhile_UST(NOR_RESUME_SUSPEND_INTERVAL - resume_to_suspend_duration);
      }

      /* reset resume_time_g */
      resume_time_g = NOR_DEFAULT_RESUME_TIME;
   }

#endif   /* NOR_RESUME_SUSPEND_INTERVAL */

   /* issue suspend command */
   flash_base[0] = CMD_SUSP_SEC_ERASE;

   /*---------------------------------------------------------------------
    * Spansion NOR flash requires tESL delay before starting to polling status bits.
    * !TODO: If DQ6 fails, the polling mechanism here needs to be changed! (ex. WS256P)
    * !CHALLENGE: We can't distinguish it's program suspend or erase suspend!
    * (a flag may be used to get such infomation)
    *---------------------------------------------------------------------*/

   #ifdef NOR_SUSPEND_LATENCY
   DelayAWhile_UST(NOR_SUSPEND_LATENCY);
   #else
   DelayAWhile_UST(5);
   #endif

   // polling until flash ready
   do{
      toggle1 = check_ptr[0];
      toggle2 = check_ptr[0];
   }while((toggle1 ^ toggle2) & TOGGLE_BUSY);
   
   NOR_FLASH_SUSPENDED = KAL_TRUE;

}
#endif //__SPANSION_VS_R__ || __SPANSION_WS_R__


#if (defined(__SPANSION_VS_R__) || defined(__SPANSION_WS_R__))
__nor_section_RAM void Flash_ReturnReady(void) /* should be invoked only when interrupt is disabled */
{
   NOR_Flash_MTD_Data *mtd_data = NULL;
   static FLASH_CELL s;
   kal_uint32 data_cache_id;
   volatile FLASH_CELL *flash_p = NULL;
   
   #if defined(__FOTA_DM__)
   if(FOTA_Flash_busy)
   {
      mtd_data = (NOR_Flash_MTD_Data *)NORFlashDriveData.MTDData;
   }
   else
   #endif   /* __FOTA_DM__ */
   {
      mtd_data = (NOR_Flash_MTD_Data *)FlashDriveData.MTDData;
   }

   ASSERT(~(mtd_data->Signature) == ((kal_uint32)mtd_data->RegionInfo));

   flash_p = (volatile FLASH_CELL *)mtd_data->CurrAddr;


   if((!NOR_FLASH_SUSPENDED) && NOR_FLASH_BUSY)
   {
      gNOR_ReturnReadyBegin = ust_get_current_time();  // get start time of Flash_ReturnReady (Only when flash is busy)

      data_cache_id = INT_DisableDataCache();

      flash_p[ADDR_UNLOCK_1] = WVSR_CMD_RD_SR;
      s = flash_p[0];

      if(!( s & WVSR_READY_FLAG))
      {
         waitReady(flash_p);
      }
      else
      {
         NOR_FLASH_BUSY = KAL_FALSE;
      }
      
      INT_RestoreDataCache(data_cache_id);

      gNOR_ReturnReadyEnd = ust_get_current_time();     // get end time of Flash_ReturnReady
   }

}

#else // !__SPANSION_VS_R__ && !__SPANSION_WS_R__

/*******************************************************************//**
 * Let flash return to ready status when an interrupt comes
 *
 * @par Category:
 * NOR MTD (Enhanced Single Bank)
 **********************************************************************/
__nor_section_RAM void Flash_ReturnReady(void) /* should be invoked only when interrupt is disabled */
{
   NOR_Flash_MTD_Data     *mtd_data    = NULL;
   static FLASH_CELL       status_1, status_2;
   kal_uint32              data_cache_id;
   volatile FLASH_CELL    *check_ptr    = NULL;

   #if defined(__FOTA_DM__)
   if(FOTA_Flash_busy)
   {
      mtd_data = (NOR_Flash_MTD_Data *)NORFlashDriveData.MTDData;
   }
   else
   #endif /* !__FOTA_DM__ */
   {
      mtd_data = (NOR_Flash_MTD_Data *)FlashDriveData.MTDData;
   }

   #if defined(__MULTI_BANK_NOR_DEVICE__)
   check_ptr = (volatile kal_uint16*)mtd_data->CurrPollAddr;
   #else
   check_ptr = (volatile kal_uint16*)mtd_data->BaseAddr;
   #endif //__MULTI_BANK_NOR_DEVICE__

   ASSERT(~(mtd_data->Signature) == ((kal_uint32)mtd_data->RegionInfo));

   if((!NOR_FLASH_SUSPENDED) && NOR_FLASH_BUSY)
   {
      gNOR_ReturnReadyBegin = ust_get_current_time();  // get start time of Flash_ReturnReady (only when flash is busy)

      data_cache_id = INT_DisableDataCache();

      status_1 = check_ptr[0];
      status_2 = check_ptr[0];

      if((status_1 ^ status_2) & TOGGLE_BUSY)
      {
         waitReady(check_ptr);
      }
      else
      {
         NOR_FLASH_BUSY = KAL_FALSE;
      }

      INT_RestoreDataCache(data_cache_id);

      gNOR_ReturnReadyEnd = ust_get_current_time();   // get end time of Flash_ReturnReady

   }
}
#endif //__SPANSION_VS_R__ || __SPANSION_WS_R__
#endif // !__COMBO_MEMORY_SUPPORT__


//Remove sleep mode deprecated function content: Flash_CheckReady, Flash_ResumeOperation, Flash_SuspendOperation

/* CAUTION:
 * Following functions are intended to be invoked ONLY in sleep mode
 */

 /*******************************************************************//**
 * Check if flash is ready
 *
 * @par Category:
 * NOR FDM 4.0 (Enhanced Single Bank / Sleep Mode Support)
 *
 * @note
 * 1. Use processedBankAddr(multi-bank device) or a RO data address(single-bank device) to check device status.
 * 2. Only called by SuspendEraseQueue()
 *
 * @return
 * KAL_TRUE : Flash is ready.
 * KAL_FALSE: Flash is busy.
 **********************************************************************/
__nor_section_RAM kal_bool Flash_CheckReady(void){return KAL_TRUE;}




 /*******************************************************************//**
 * Resume suspended erase operation during sleep mode.
 *
 * @par Category:
 * NOR FDM 4.0 (Enhanced Single Bank / Sleep Mode Support)
 *
 * @note
 * 1. This erase operation should be suspended by SuspendEraseQueue() before.
 * 2. Use bank address to issue resume command.
 * 3. Only called by ProcessEraseQueue()
 *
 * @remarks
 * The address to issue command must be set to Non-Cacheable!
 * In ARM9 platform, processedBankAddr should be located in FAT space and shoule be set to Non-Cacheable.
 **********************************************************************/
__nor_section_RAM void Flash_ResumeOperation(void){;}


 /*******************************************************************//**
 * Suspend ongoing erase operation issued by sleep mode.
 *
 * @par Category:
 * NOR FDM 4.0 (Enhanced Single Bank / Sleep Mode Support)
 *
 * @note
 * 1. This ongoing erase operation should be issued by ProcessEraseQueue()
 * 2. Only called by SuspendEraseQueue()
 *
 * @remarks
 * The address to issue command must be set to Non-Cacheable!
 * In ARM9 platform, processedBankAddr should be located in FAT space and shoule be set to Non-Cacheable.
 **********************************************************************/
__nor_section_RAM void Flash_SuspendOperation(void){;}


 /*******************************************************************//**
 * Program block header issued by sleep mode.
 *
 * @par Category:
 * NOR FDM 4.0 (VSR Enhanced Single Bank / Sleep Mode Support)
 *
 * @note
 * 1. Only called by SNOR_ReclaimBlock_post()
 *
 * @remarks
 * The address to be write should be block align
 * 
 **********************************************************************/
__nor_section_RAM void Flash_ProgramData(void *target, void *src, kal_uint32 size){;}

#endif   /* __SINGLE_BANK_NOR_FLASH_SUPPORT__ */


#else    /* __FUE__ */
// In FUE environment, no need to wait flash to become ready
void Flash_ReturnReady(void)
{
   return;
}
#endif   /* !__FUE__ */

#if !defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)
#if (defined(__SPANSION_VS_R__) || defined(__SPANSION_WS_R__))
__nor_section_RAM kal_int32 WaitReady_WVSR(kal_uint32 BlkAddr)
{
   kal_uint16        stat_data;
   kal_uint32        data_cache_id;
   volatile FLASH_CELL *bp = (volatile FLASH_CELL *) BlkAddr;
   kal_uint32        poll_times = 0;
   kal_int32         Result = RESULT_FLASH_DONE;

   data_cache_id = INT_DisableDataCache();

   ResetInBusy();

   while(1)
   {
      BLTest(3); //Random Reset while device program busy (Multi-bank)

     bp[ADDR_UNLOCK_1] = WVSR_CMD_RD_SR;
     stat_data = bp[0];
     if(stat_data & WVSR_READY_FLAG)
     {
       if(stat_data & WVSR_PROGRAM_ERROR_FLAG)
       { 
	  //return program fail  
          Result = RESULT_FLASH_FAIL;
       }       
       break; //default Result = RESULT_FLASH_DONE
     }
     else 
     {
       poll_times++;
       if (poll_times >= MAX_AMD_PGM_POLL_TIMES)
       {
          // return program fail
          Result = RESULT_FLASH_FAIL;
          break;
       }
     }
   }

   INT_RestoreDataCache(data_cache_id);
   return Result;
}
#endif //__SPANSION_VS_R__ || __SPANSION_WS_R__

#if defined(__AMD_SERIES_NOR_PROGRAM__) || defined(__TOSHIBA_TV__) || defined(__TOSHIBA_TY__)

/*******************************************************************//**
 * Check if device is ready (for program only)
 *
 * @par Category:
 * NOR MTD (Multi-Bank and Low-Cost Single Bank)
 *
 * @notes
 * Only called by ProgramData_AMD(), ProgramData_Toshiba() and LockEraseBlkAddr_AMD()
 *
 * @remarks
 * This function must wait until flash is ready or failed.
 *
 **********************************************************************/
__nor_section_RAM kal_int32 WaitReady_AMD(kal_uint32 addr,kal_uint16 data)
{
   kal_uint16        stat_data;
   kal_uint32        data_cache_id;
   kal_uint16        data_toggle1 = 0, data_toggle2 = 0;
   kal_uint32        poll_times = 0;
   kal_int32         Result = RESULT_FLASH_DONE;

   data_cache_id = INT_DisableDataCache();

   ResetInBusy();

   #ifndef __SST_NOR__
   while(1)
   {
      BLTest(3); //Random Reset while device program busy (Multi-bank)
      
      data_toggle1 = *(volatile kal_uint16*)addr;
      data_toggle2 = *(volatile kal_uint16*)addr;

      // DQ6 is NOT toggling
      if( !((data_toggle1 ^ data_toggle2) & TOGGLE_BUSY) ) {

         // Check DQ7 to confirm device is ready (to prevent DQ6 stoping toggle before flash is ready, found this issue in WS256P)
         if ((data_toggle2 & POLL_BUSY) == (data & POLL_BUSY))
         {
            // DQ7 is the same as data bit 7, flash is ready
            break;
         }
         else
         {
            /**********************************************************************//**
             * DQ6 is not toggling means that flash is ready.
             *
             * In normal case, we should not enter here except that DQ6 is not reliable
             * (i.e., DQ6 stops toggling before flash is ready while DQ7 is complement of data).
             * In such abnormal case, DQ7 provides double confirm here. (w08.29)
             **************************************************************************/
            // limit the polling times to not hanging here if bit-flipping happens
            poll_times++;
            if (poll_times >= MAX_AMD_PGM_POLL_TIMES)
            {
               // return program fail
               Result = RESULT_FLASH_FAIL;
               break;
            }
            else
            {
               // continue to polling DQ7
               continue;
            }
         }
      }

      // DQ6 is still toggling
      stat_data = data_toggle2;

      if(stat_data & POLL_TIMEOUT) // DQ5 = 1, may imply a timeout happens
      {
         stat_data = *(volatile kal_uint16*)addr;

         // DQ7 is ready
         if((stat_data & POLL_BUSY) == (data & POLL_BUSY))
         {
            break;
         }
         else
         {
            // DQ7 not ready, this is a timeout, program fail
            *(volatile kal_uint16*)addr = CMD_RESET;
            Result = RESULT_FLASH_FAIL;
            break;
         }
      }
      #ifdef __PAGE_BUFFER_PROGRAM__
      else if (stat_data & TOGGLE_BUFFER_ABORT)
      {
         data_toggle1 = *(volatile kal_uint16*)addr;
         data_toggle2 = *(volatile kal_uint16*)addr;
         if( !((data_toggle1 ^ data_toggle2) & TOGGLE_BUSY) ) {
            // Not toggle
            break;
         } else {
            // Still toggle -> Toggle buffer abort
            *(((volatile kal_uint16*)addr)+ADDR_UNLOCK_1) = CMD_UNLOCK_1;
            *(((volatile kal_uint16*)addr)+ADDR_UNLOCK_2) = CMD_UNLOCK_2;
            *(((volatile kal_uint16*)addr)+ADDR_UNLOCK_1) = CMD_RESET;
            INT_RestoreDataCache(data_cache_id);
            MTD_ASSERT(0, 0, 0, 0, NOR_MTD_PROGRAM_WRITE_BUFFER_FAIL);
         }
      }
      #endif /* __PAGE_BUFFER_PROGRAM__ */
   }

   stat_data = *(volatile kal_uint16*)addr;
   if ( stat_data != data )
   {
       Result = RESULT_FLASH_FAIL;
   }

   #else /* __SST_NOR__ */
   /* use toggle method instead of data polling method */
   /* SST also can use data polling method, but need to disable DQ5 check */
   /* because SST don't support DQ5 */
   while(1)
   {
      data_toggle1 = *(volatile kal_uint16*)addr;
      data_toggle2 = *(volatile kal_uint16*)addr;
      if( !((data_toggle1^data_toggle2) & TOGGLE_BUSY) )
      {
         data_toggle1 = *(volatile kal_uint16*)addr;
         data_toggle2 = *(volatile kal_uint16*)addr;
         if(data_toggle1 == data_toggle2)
         {
            stat_data = *(volatile kal_uint16*)addr;
            if(stat_data != data) {
               Result = RESULT_FLASH_FAIL;
            }
            break;
         }
      }
   }
   #endif /* !__SST_NOR__ */

   INT_RestoreDataCache(data_cache_id);
   return Result;
}

#endif // __AMD_SERIES_NOR_PROGRAM__ || __TOSHIBA_TV__ || __TOSHIBA_TY__
#endif /* !__SINGLE_BANK_NOR_FLASH_SUPPORT__ */

/*******************************************************************//**
 * Shutdown NOR flash device
 *
 * @par Category:
 * NOR MTD (NOR FDM 4.0, AMD-series)
 *
 * @param[in] DriveData       NOR flash MTD data
 *
 * @remarks
 * This function must be placed on RAM because flash may be busy/resumed inside!
 **********************************************************************/
#ifndef __NOR_FDM5__
#ifndef __COMBO_MEMORY_SUPPORT__
#if (defined(__SPANSION_VS_R__) || defined(__SPANSION_WS_R__))
__nor_section_RAM static int ShutDown_WVSR(void * DriveData)
{
   NOR_Flash_MTD_Data  *D = DriveData;
   volatile FLASH_CELL *fp = (volatile FLASH_CELL*)D->CurrAddr;
   FLASH_CELL          stat_data;
   kal_uint32          data_cache_id;
   #if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)
   kal_uint32          saved_mask;
   #endif //ESB

   data_cache_id = INT_DisableDataCache();

   while(1)
   { 

      #if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)
      saved_mask = SaveAndSetIRQMask();

      // resume suspended operation issued by ISR (ESB only)
      if(NOR_FLASH_SUSPENDED)
      {
         *(volatile FLASH_CELL*)fp = CMD_RESU_SEC_ERASE;

         NOR_FLASH_SUSPENDED = KAL_FALSE;

         gNOR_ReturnReadyEnd = NOR_DEFAULT_RETURN_READY_LATENCY;

         #ifdef NOR_RESUME_SUSPEND_INTERVAL
         resume_time_g = ust_get_current_time();  // get suspend time to guarantee tERS
         #endif         
      }
      #endif  /* __SINGLE_BANK_NOR_FLASH_SUPPORT__ */


      //read status register
      fp[ADDR_UNLOCK_1] = WVSR_CMD_RD_SR;
      stat_data = fp[0];
      
      //if device ready, break; else loop again
      if(stat_data & WVSR_READY_FLAG)
      {
         #if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)
         NOR_FLASH_BUSY = KAL_FALSE;
         RestoreIRQMask(saved_mask);
         #endif /* __SINGLE_BANK_NOR_FLASH_SUPPORT__ */
   	break; 
   }
      else
      {
         #if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)
         RestoreIRQMask(saved_mask);
         #endif /* __SINGLE_BANK_NOR_FLASH_SUPPORT__ */
      }
   }

   D->CurrAddr = NULL;

   INT_RestoreDataCache(data_cache_id);

   return FS_NO_ERROR;
}
#else /*!(defined(__SPANSION_VS_R__) || defined(__SPANSION_WS_R__))*/
__nor_section_RAM static int ShutDown_AMD(void * DriveData)
{
   NOR_Flash_MTD_Data  *D = DriveData;
   volatile FLASH_CELL *fp = (volatile FLASH_CELL*)D->CurrAddr;
   FLASH_CELL          s1, s2;
   kal_uint32          data_cache_id;
   #if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)
   kal_uint32          saved_mask;
   #endif  /* __SINGLE_BANK_NOR_FLASH_SUPPORT__ */

   data_cache_id = INT_DisableDataCache();

   while(1)
   {
      #if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)
      saved_mask = SaveAndSetIRQMask();

      // if NOR_FLASH_SUSPEND is TRUE, NOR_FLASH_BUSY should be also TRUE!
      if(NOR_FLASH_SUSPENDED)
      {
         fp[0] = CMD_RESU_SEC_ERASE; /* resume suspended erase operation */
         NOR_FLASH_SUSPENDED = KAL_FALSE;

         #ifdef __MONZA_2G__
         gNOR_ReturnReadyEnd = NOR_DEFAULT_RETURN_READY_LATENCY;
         #endif

         #ifdef NOR_RESUME_SUSPEND_INTERVAL
         resume_time_g = ust_get_current_time();  // get suspend time to guarantee tERS
         #endif

         tBUSYDelay();
      }
      #endif /* __SINGLE_BANK_NOR_FLASH_SUPPORT__ */

      s1 = fp[0];
      s2 = fp[0];

      // if DQ6 is not toggling, break
      if (!((s1 ^ s2) & TOGGLE_BUSY))
      {
         // here we can't poll DQ7 to double confirm because we don't know the programmed data.

         #if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)
         NOR_FLASH_BUSY = KAL_FALSE;
         RestoreIRQMask(saved_mask);
         #endif /* __SINGLE_BANK_NOR_FLASH_SUPPORT__ */

         break;
      }
      // DQ6 is toggling
      else
      {
         // DQ5 = 1: maybe timeout or bit 5 of data is exactly 1
         if(s2 & TOGGLE_TIMEOUT)
         {
            s1 = fp[0];
            s2 = fp[0];

            // if DQ6 is toggling, timeout! if not, flash is ready.
            if ((s1 ^ s2) & TOGGLE_BUSY)
            {
               fp[0] = CMD_RESET;
            }

            #if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)
            NOR_FLASH_BUSY = KAL_FALSE;
            RestoreIRQMask(saved_mask);
            #endif /* __SINGLE_BANK_NOR_FLASH_SUPPORT__ */

            // both case should leave this while-loop
            break;
         }

         // DQ5 = 0: flash is busy, loops again.
         #if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)
         RestoreIRQMask(saved_mask);
         #endif /* __SINGLE_BANK_NOR_FLASH_SUPPORT__ */
      }
   }

   D->CurrAddr = NULL;

   INT_RestoreDataCache(data_cache_id);

   return FS_NO_ERROR;
}
#endif /*(defined(__SPANSION_VS_R__) || defined(__SPANSION_WS_R__))*/
#endif // __COMBO_MEMORY_SUPPORT__
#endif // !__NOR_FDM5__

/*-----------------------------------*/
#if defined(__COMBO_MEMORY_SUPPORT__)

extern NOR_MTD_Driver NORFlashMtd;

__nor_section_RAM void PF_DAL_Dev_EraseBlock_AMD( volatile FLASH_CELL *fp)
{
   kal_uint32 savedMask;

   savedMask = SaveAndSetIRQMask();

   fp[ADDR_UNLOCK_1] = CMD_UNLOCK_1;
   fp[ADDR_UNLOCK_2] = CMD_UNLOCK_2;
   fp[ADDR_UNLOCK_1] = CMD_SERASE;
   fp[ADDR_UNLOCK_1] = CMD_UNLOCK_1;
   fp[ADDR_UNLOCK_2] = CMD_UNLOCK_2;
   fp[0] 	= CMD_SERASE_END;
#if  defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)
   NOR_FLASH_BUSY = KAL_TRUE;
#endif
   RestoreIRQMask(savedMask);

#if defined(__SPANSION_PL_N__)
   DelayAWhile_UST(54);  // 50 us to cover tSEA, and another 4 us is required to wait before polling (PL-N only)
#endif   /* __SPANSION_PL_N__ */

}

#if defined(__SPANSION_VS_R__) || defined(__SPANSION_WS_R__)
__nor_section_RAM void PF_DAL_Dev_EraseBlock_WVSR( volatile FLASH_CELL *fp)
{
   kal_uint32 savedMask;

   savedMask = SaveAndSetIRQMask();

   fp[ADDR_UNLOCK_1] = WVSR_CMD_CLR_SR;
   fp[ADDR_UNLOCK_1] = CMD_SERASE;
   fp[ADDR_UNLOCK_2] = CMD_SERASE_END;
#if  defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)
   NOR_FLASH_BUSY = KAL_TRUE;
#endif

   RestoreIRQMask(savedMask);
}
#endif


__nor_section_RAM static int EraseBlock_AMD(void * DriveData, kal_uint32 BlockIndex) /* MapWindow required */
{
   int (*CheckDeviceReady)(void *, kal_uint32);

#ifndef __NOR_FDM5__
   PF_MTD_Data * D = DriveData;
   volatile FLASH_CELL * fp = (volatile FLASH_CELL *) D->CurrAddr;
#ifdef DEBUG
   //EraseBlock: block not mapped
   ASSERT(D->CurrAddr == BlockAddress(D, BlockIndex));
#endif
   ASSERT((~D->Signature == (kal_uint32)D->RegionInfo));
#else
   NOR_MTD_DATA *D= DriveData;
   volatile FLASH_CELL * fp = (volatile FLASH_CELL *)BlockAddress(D,BlockIndex);
   ASSERT(D->Signature == ~((kal_uint32)D->LayoutInfo));
#endif

#if defined(__BASIC_LOAD_FLASH_TEST__)
   EraseNum++;
#endif

   // TODO: check the assign is correct
   CheckDeviceReady = NORFlashMtd.CheckDeviceReady;

   waitNonBlockEraseDone();

   DYBCMD_AMD(D, fp,DYB_UNLOCK);

   // TODO: initialize Erase block function in init function
   D->CMD->CMD_EraseBlock(fp);

#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)
   while( FS_FLASH_ERASE_BUSY == CheckDeviceReady(DriveData, BlockIndex) )
   {
      // polling flash status per 1 ms to avoid heavy EMI traffic
      DelayAWhile_UST(1000);
      BLTest(0);
   }

#else    /* multi-bank */
   while (CheckDeviceReady(DriveData, BlockIndex) != FS_NO_ERROR);
#endif   /* __SINGLE_BANK_NOR_FLASH_SUPPORT__ */

   DYBCMD_AMD(D, fp,DYB_LOCK);

   return FS_NO_ERROR;
}



/*-----------------------------------*/

__nor_section_RAM static int NonBlockEraseBlock_AMD(void * DriveData, kal_uint32  BlockIndex) /* Added by Eric */
{
#ifndef __NOR_FDM5__
   PF_MTD_Data * D = DriveData;
   volatile FLASH_CELL * fp = (volatile FLASH_CELL *) D->CurrAddr;
#ifdef DEBUG
   //EraseBlock: block not mapped
   ASSERT(D->CurrAddr == BlockAddress(D, BlockIndex));
#endif   /* DEBUG */
   ASSERT((~D->Signature == (kal_uint32)D->RegionInfo));
#else    /* __NOR_FDM5__ */
   NOR_MTD_DATA *D= DriveData;
   volatile FLASH_CELL * fp = (volatile FLASH_CELL *)BlockAddress(D,BlockIndex);
   ASSERT(D->Signature == ~((kal_uint32)D->LayoutInfo));
#endif   /* !__NOR_FDM5__ */

   waitNonBlockEraseDone();

   DYBCMD_AMD(D, fp,DYB_UNLOCK);

   D->CMD->CMD_EraseBlock(fp);

#if defined(__BASIC_LOAD_FLASH_TEST__)
   EraseNum++;
#endif

   // do random powerloss in busy time (multi-bank only)
#if !(defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__))
   BLTest(2);
#endif

   gNonBlockingEraseBlockAddr = (kal_uint32)fp;

   return FS_NO_ERROR;
}


#else // !__COMBO_MEMORY_SUPPORT__
__nor_section_RAM static int EraseBlock_AMD(void * DriveData, kal_uint32 BlockIndex) /* MapWindow required */
{
#if  defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)
   kal_uint32 savedMask;
#endif /* __SINGLE_BANK_NOR_FLASH_SUPPORT__ */

#ifndef __NOR_FDM5__
   NOR_Flash_MTD_Data * D = DriveData;
   volatile FLASH_CELL * fp = (volatile FLASH_CELL *) D->CurrAddr;
   #ifdef DEBUG
      //EraseBlock: block not mapped
      ASSERT(D->CurrAddr == BlockAddress(D, BlockIndex));
   #endif
   ASSERT((~D->Signature == (kal_uint32)D->RegionInfo));
#else
   NOR_MTD_DATA *D= DriveData;
   volatile FLASH_CELL * fp = (volatile FLASH_CELL *)BlockAddress(D,BlockIndex);
   ASSERT(D->Signature == ~((kal_uint32)D->LayoutInfo));
#endif

#if defined(__BASIC_LOAD_FLASH_TEST__)
	EraseNum++;
#endif

   waitNonBlockEraseDone();

   DYBCMD_AMD(D, fp,DYB_UNLOCK);

#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)
   savedMask = SaveAndSetIRQMask();
#endif /* __SINGLE_BANK_NOR_FLASH_SUPPORT__ */

#if (defined(__SPANSION_VS_R__) || defined(__SPANSION_WS_R__))
   EraseCommand_WVSR(fp);
#else
   EraseCommand_AMD(fp);
#endif
#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)
   RestoreIRQMask(savedMask);
#endif   /* __SINGLE_BANK_NOR_FLASH_SUPPORT__ */

   #if defined(__SPANSION_PL_N__)
   DelayAWhile_UST(54);  // 50 us to cover tSEA, and another 4 us is required to wait before polling (PL-N only)
   #endif   /* __SPANSION_PL_N__ */

#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)
#if (defined(__SPANSION_VS_R__) || defined(__SPANSION_WS_R__))
   while( FS_FLASH_ERASE_BUSY == CheckDeviceReady_WVSR(DriveData, BlockIndex) ) {
      // polling flash status per 1 ms to avoid heavy EMI traffic
      DelayAWhile_UST(1000);
      BLTest(0);
   }

#else
   while( FS_FLASH_ERASE_BUSY == CheckDeviceReady_AMD(DriveData, BlockIndex) ) {
      // polling flash status per 1 ms to avoid heavy EMI traffic
      DelayAWhile_UST(1000);
      BLTest(0);
   }
#endif
   
#else    /* multi-bank */
#if (defined(__SPANSION_VS_R__) || defined(__SPANSION_WS_R__))
   while (CheckDeviceReady_WVSR(DriveData, BlockIndex) != FS_NO_ERROR);
#else
   while (CheckDeviceReady_AMD(DriveData, BlockIndex) != FS_NO_ERROR);
#endif
#endif   /* __SINGLE_BANK_NOR_FLASH_SUPPORT__ */

   DYBCMD_AMD(D, fp,DYB_LOCK);

   return FS_NO_ERROR;
}
/*-----------------------------------*/
__nor_section_RAM static int NonBlockEraseBlock_AMD(void * DriveData, kal_uint32  BlockIndex) /* Added by Eric */
{
#ifndef __NOR_FDM5__
   NOR_Flash_MTD_Data * D = DriveData;
   volatile FLASH_CELL * fp = (volatile FLASH_CELL *) D->CurrAddr;
   #if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)
   kal_uint32 savedMask = 0;
   #endif   /* __SINGLE_BANK_NOR_FLASH_SUPPORT__ */
   #ifdef DEBUG
   //EraseBlock: block not mapped
   ASSERT(D->CurrAddr == BlockAddress(D, BlockIndex));
   #endif   /* DEBUG */
   ASSERT((~D->Signature == (kal_uint32)D->RegionInfo));
#else    /* __NOR_FDM5__ */
   NOR_MTD_DATA *D= DriveData;
   volatile FLASH_CELL * fp = (volatile FLASH_CELL *)BlockAddress(D,BlockIndex);
   ASSERT(D->Signature == ~((kal_uint32)D->LayoutInfo));
#endif   /* !__NOR_FDM5__ */

   waitNonBlockEraseDone();
   
   DYBCMD_AMD(D, fp,DYB_UNLOCK);

   #if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)
   savedMask = SaveAndSetIRQMask();
   #endif   /* __SINGLE_BANK_NOR_FLASH_SUPPORT__ */

   #if (defined(__SPANSION_VS_R__) || defined(__SPANSION_WS_R__))
   EraseCommand_WVSR(fp);
   #else	  
   EraseCommand_AMD(fp);
   #endif

   #if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)
   RestoreIRQMask(savedMask);
   #endif   /* __SINGLE_BANK_NOR_FLASH_SUPPORT__ */

   #if defined(__BASIC_LOAD_FLASH_TEST__)
 	EraseNum++;
   #endif

   // do random powerloss in busy time (multi-bank only)
   #if !(defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__))
   BLTest(2);
   #endif

   #ifdef __SPANSION_PL_N__
   DelayAWhile_UST(54);  // 50 us to cover tSEA, and another 4 us is required to wait before polling (PL-N only)
   #endif	/* __SPANSION_PL_N__ */

   gNonBlockingEraseBlockAddr = (kal_uint32)fp;

   return FS_NO_ERROR;
}
#endif //__COMBO_MEMORY_SUPPORT__


/*-----------------------------------*/
#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)

__nor_section_RAM static int CheckDeviceReady_WVSR(void * DriveData, kal_uint32 BlockIndex) 
{
   FLASH_CELL       stat_data;
   kal_uint32       data_cache_id;
   kal_uint32       savedMask = 0;
   kal_int32        status      = FS_DATA_ERROR;

#ifndef __NOR_FDM5__
   NOR_Flash_MTD_Data * D = DriveData;
   volatile FLASH_CELL * fp = (volatile FLASH_CELL *) D->CurrAddr;
#ifdef DEBUG
   //EraseBlock: block not mapped
   ASSERT(D->CurrAddr == BlockAddress(D, BlockIndex));
#endif
   ASSERT((~D->Signature == (kal_uint32)D->RegionInfo));
#else  /* __NOR_FDM5__ */
   NOR_MTD_DATA *D= DriveData;
   volatile FLASH_CELL * fp = (volatile FLASH_CELL *)BlockAddress(D,BlockIndex);
   ASSERT(D->Signature == ~((kal_uint32)D->LayoutInfo));
#endif /* !__NOR_FDM5__ */

   // ensure that the status check is atomic
   savedMask = SaveAndSetIRQMask();
   data_cache_id = INT_DisableDataCache();

   fp[ADDR_UNLOCK_1] = WVSR_CMD_RD_SR;
   stat_data = fp[0];

   if(stat_data & WVSR_READY_FLAG)
   {
   	  if(stat_data & WVSR_ERASE_SUSPEND) 
   	  {
   	     SNOR_MTD_ASSERT(NOR_FLASH_BUSY, NOR_FLASH_SUSPENDED, (kal_uint32)fp, (fp[0] << 16) | fp[0] );
   	     
   	     fp[0] = CMD_RESU_SEC_ERASE;
   	     NOR_FLASH_SUSPENDED = KAL_FALSE;
   	     gNOR_ReturnReadyEnd = NOR_DEFAULT_RETURN_READY_LATENCY;
   	     
   	     #ifdef NOR_RESUME_SUSPEND_INTERVAL
   	     resume_time_g = ust_get_current_time();  // get suspend time to guarantee tERS
   	     #endif
   	     
   	     status = FS_FLASH_ERASE_BUSY;
   	  }
   	  else if(stat_data & WVSR_ERASE_ERROR_FLAG)
   	  {
         MTD_ASSERT(0, 0, 0, 0, NOR_MTD_ERASE_FAIL);	  	
   	  }
   	  else
   	  {
   	     //fp[0] = read array mode; // no need to switch to read array mode
   	     NOR_FLASH_BUSY = KAL_FALSE;
   	     NOR_FLASH_SUSPENDED = KAL_FALSE;
   	     status = FS_NO_ERROR;
   	  }
   	
   }else {
      status = FS_FLASH_ERASE_BUSY;
   }

   INT_RestoreDataCache(data_cache_id);
   RestoreIRQMask(savedMask);
   
   return status;
}

/*******************************************************************//**
 * Check if device is ready (for erase only)
 *
 * @par Category:
 * NOR MTD (Enhanced Single Bank)
 *
 * @par Change Log:
 * 08.29: Add DQ7 mechanism to tolerate the situation that DQ6 stop toggling before flash is ready (found in W256P),
 *        however, DQ7 may not work due to the bit-flipping phenomenon (found in GLN), a maximum polling times is needed for
 *        not hanging inside this function.
 *
 * @note
 * 1. Only called by EraseBlock_AMD() and EraseBlockList()
 * 2. DQ6 -> DQ2 -> (DQ7) -> Check if read data is 0xFFFF
 *
 **********************************************************************/
__nor_section_RAM static int CheckDeviceReady_AMD(void * DriveData, kal_uint32 BlockIndex) /* for erase operation only, MapWindow required */
{
   FLASH_CELL        s1, s2;
   kal_uint32        data_cache_id;
   kal_int32         status      = FS_DATA_ERROR;
   static kal_uint32 test_times  = 0;   ///< for re-tring erase command if DQ6 is toggling and DQ5 is 1 (timeout)
   static kal_uint32 poll_times  = 0;   ///< for counting how many times for DQ7 polling

#if defined(NOR_FLASH_BLANK_VERIFICATION)
   kal_uint32 idx = 0;
#endif
#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)
   kal_uint32 savedMask = 0;
#endif
#ifndef __NOR_FDM5__
   NOR_Flash_MTD_Data * D = DriveData;
   volatile FLASH_CELL * fp = (volatile FLASH_CELL *) D->CurrAddr;
   SNOR_MTD_ASSERT((~D->Signature == (kal_uint32)D->RegionInfo), (kal_uint32)(~D->Signature), (kal_uint32)D->RegionInfo, 0);
   //EraseBlock: block not mapped

   // CurrAddr must be set to block align address
   SNOR_MTD_ASSERT(D->CurrAddr == BlockAddress(D, BlockIndex), (kal_uint32)(D->CurrAddr), (kal_uint32)BlockAddress(D, BlockIndex), 0);
   
#else
   NOR_MTD_DATA *D= DriveData;
   volatile FLASH_CELL * fp = (volatile FLASH_CELL *)BlockAddress(D,BlockIndex);
   SNOR_MTD_ASSERT(D->Signature == ~((kal_uint32)D->LayoutInfo), 0, 0, 0);
#endif

   /* ensure that the status check is atomic */
   savedMask = SaveAndSetIRQMask();

   data_cache_id = INT_DisableDataCache();

   s1 = fp[1];
   s2 = fp[1];

   // DQ6 is toggling
   if ((s1 ^ s2) & TOGGLE_BUSY)
   {
      #ifndef __SST_NOR__
      // DQ5 = 1, maybe time out or the bit 5 of data is exactly 1
      if(s2 & TOGGLE_TIMEOUT)
      {
         s1 = fp[1];
         s2 = fp[1];
         // DQ6 is toggling
         if( (s1 ^ s2) & TOGGLE_BUSY )
         {
            // operation timed out, issue reset command to return to ready status
            fp[0] = CMD_RESET;

            // retry at most 2 times
            test_times++;
            if (test_times > 2)
	            MTD_SNOR_ASSERT(0, 0, 0, 0, NOR_MTD_ERASE_TIMEOUT);

            // erase again
            EraseCommand_AMD(fp);
            status = FS_FLASH_ERASE_BUSY;
         }
         else
         {
            NOR_FLASH_BUSY = KAL_FALSE;
            test_times = 0;
            status = FS_NO_ERROR;
         }
      }
      else
         status = FS_FLASH_ERASE_BUSY;
      #else /* !__SST_NOR__ */
      status = FS_FLASH_ERASE_BUSY;
      #endif/* __SST_NOR__ */
   }
   // DQ7 = 0
   else if (!(s2 & POLL_BUSY))
   {
     /**********************************************************************//**
      * DQ6 is not toggling: flash should be ready (DQ7=Data=1) or erase suspend (DQ7=1).
      *
      * In normal case, we should not enter here except that DQ6 is not reliable
      * (i.e., DQ6 stops toggling before flash is ready, DQ7=0). In such abnormal case,
      * DQ7 provides double confirm here. (w08.29)
      **************************************************************************/

      // limit the polling times to not hanging here if bit-flipping happens
      poll_times++;
      if (poll_times >= MAX_AMD_ERASE_POLL_TIMES)
      {
         // issue reset command to return to ready status
         fp[0] = CMD_RESET;
         MTD_SNOR_ASSERT(0, 0, 0, 0, NOR_MTD_ERASE_POLL_BUSY_FAIL);
      }
      else
      {
         status = FS_FLASH_ERASE_BUSY;
      }
   }
   // DQ2 is toggling, DQ6 is NOT toggling and DQ7 = 1: flash is erase suspended
   else if (((s1 ^ s2) & TOGGLE_ERASE_SUSPEND))
   {
      // NOR_FLASH_BUSY should be set to KAL_TRUE in EraseCommand_AMD()
      SNOR_MTD_ASSERT( NOR_FLASH_BUSY, NOR_FLASH_SUSPENDED, (kal_uint32)fp, (fp[0] << 16) | fp[0] );

      fp[0] = CMD_RESU_SEC_ERASE;
      NOR_FLASH_SUSPENDED = KAL_FALSE;

      gNOR_ReturnReadyEnd = NOR_DEFAULT_RETURN_READY_LATENCY;

      #ifdef NOR_RESUME_SUSPEND_INTERVAL
      resume_time_g = ust_get_current_time();  // get suspend time to guarantee tERS
      #endif

      tBUSYDelay();

      status = FS_FLASH_ERASE_BUSY;
   }
   // DQ2 and DQ6 are both not toggling, and DQ7 is 1 (erase done or erase suspended)
   else
   {
      s1 = fp[1];
      s2 = fp[1];

      // confirm if erase finishes
      if(s2 == 0xffff)
      {
         NOR_FLASH_BUSY = KAL_FALSE;
         /********************************************//**
          * If an interrupt comes during program/erase, in waitReady(), the device may deny the
          * "Suspend Erase/Program" command because the device is near/already ready. However,
          * NOR_FLASH_SUSPENDED is still be set to KAL_TRUE.
          *
          * In such case, after back to erase/program operation, CheckDeviceReady will reach here
          * because flash is not busy and not erase suspended (but with NOR_FLASH_SUSPENDED = KAL_TRUE). If NOR_FLASH_SUSPENDED
          * is not set to KAL_FALSE here, next time when an interrupt comes during erase/program
          * operation, Flash_ReturnReady() will be misleaded by wrong NOR_FLASH_SUSPENDED and return
          * to IRQ handler directly even if flash is still erasing/programing, leading to an execution
          * error! (Added in w08.28)
          ***********************************************/
         NOR_FLASH_SUSPENDED = KAL_FALSE;
         test_times = 0;

         status = FS_NO_ERROR;
      }
      /* data compare failed! (not 0xFF) */
      else
      {
         /* return flash to read mode */
         fp[0] = CMD_RESET;

         #ifdef NOR_FLASH_TYPE_SPANSION_PL_J
         if(!(s1 ^ s2))
         {
            EraseCommand_AMD(fp);
         }
         status = FS_FLASH_ERASE_BUSY;
         #else  /* !NOR_FLASH_TYPE_SPANSION_PL_J */
         INT_RestoreDataCache(data_cache_id);
         MTD_SNOR_ASSERT(0, 0, 0, 0, NOR_MTD_ERASE_COMP_DATA_FAIL);
         #endif /* NOR_FLASH_TYPE_SPANSION_PL_J */
	  }
   }

   INT_RestoreDataCache(data_cache_id);

   RestoreIRQMask(savedMask);

   SNOR_MTD_ASSERT(status != FS_DATA_ERROR, 0, 0, 0);

   // blank check: check if this block is all 0xFF (basic load only)
   #if defined(__BASIC_LOAD_FLASH_TEST__)
   if (status == FS_NO_ERROR)
   {
      kal_uint32 i, blockCellCnt;

      blockCellCnt = BlockSize(DriveData, BlockIndex) / sizeof(FLASH_CELL);
      for (i = 0; i < blockCellCnt; ++i) {
         if (fp[i] != 0xFFFF) {
            fp[0] = CMD_RESET;
            NORTEST_DisableWDT();
            MTD_SNOR_ASSERT(0, 0, 0, 0, NOR_MTD_ERASE_COMP_BLOCK_DATA_FAIL);
         }
      }
   }
   #endif //__BASIC_LOAD_FLASH_TEST__ 

   // reset polling times if we allow to not call CheckDeviceReady again
   if (status != FS_FLASH_ERASE_BUSY) {
      poll_times = 0;
   }

   return status;
}
#else  /* !__SINGLE_BANK_NOR_FLASH_SUPPORT__ */
#if (defined(__SPANSION_VS_R__) || defined(__SPANSION_WS_R__))
__nor_section_RAM static int CheckDeviceReady_WVSR(void * DriveData, kal_uint32 BlockIndex) 
{
   FLASH_CELL       stat_data;
   kal_uint32        data_cache_id;
   kal_int32         status      = FS_DATA_ERROR;
   static kal_uint32 test_times  = 0;
   static kal_uint32 poll_times  = 0;
   
#ifndef __NOR_FDM5__
   NOR_Flash_MTD_Data * D = DriveData;
   volatile FLASH_CELL * fp = (volatile FLASH_CELL *) D->CurrAddr;
   #ifdef DEBUG
   //EraseBlock: block not mapped
   ASSERT(D->CurrAddr == BlockAddress(D, BlockIndex));
   #endif
   ASSERT((~D->Signature == (kal_uint32)D->RegionInfo));
#else  /* __NOR_FDM5__ */
   NOR_MTD_DATA *D= DriveData;
   volatile FLASH_CELL * fp = (volatile FLASH_CELL *)BlockAddress(D,BlockIndex);
   ASSERT(D->Signature == ~((kal_uint32)D->LayoutInfo));
#endif /* !__NOR_FDM5__ */

   data_cache_id = INT_DisableDataCache();

      fp[ADDR_UNLOCK_1] = WVSR_CMD_RD_SR;
      stat_data = fp[0];

      if(stat_data & WVSR_READY_FLAG)
      {
        if(stat_data & WVSR_ERASE_ERROR_FLAG)
        { 
         MTD_ASSERT(0, 0, 0, 0, NOR_MTD_ERASE_FAIL);	  	
        }
        else
        { 
      	 status = FS_NO_ERROR;
        }
   	
   }else {
      	 status = FS_FLASH_ERASE_BUSY;
      }

   // blank check: check if this block is all 0xFF (basic load only)
   #if defined(__BASIC_LOAD_FLASH_TEST__)
   if (status == FS_NO_ERROR)
   {
      kal_uint32 i;
      kal_uint32 blockCellCnt = BlockSize(DriveData, BlockIndex) / sizeof(FLASH_CELL);

      for (i = 0; i < blockCellCnt; ++i) {
         if (fp[i] != 0xFFFF) {
            fp[0] = CMD_RESET;
            NORTEST_DisableWDT();
            MTD_ASSERT(0, 0, 0, 0, NOR_MTD_ERASE_COMP_BLOCK_DATA_FAIL);
         }
      }
   }
   #endif // __BASIC_LOAD_FLASH_TEST__ 

   INT_RestoreDataCache(data_cache_id);
   
   BLTest(0); //Random Reset while device erase busy (Multi-bank)
   
   //Reset block address of non-blocking erase
   if((gNonBlockingEraseBlockAddr == (kal_uint32)fp) && (FS_NO_ERROR == status))
   {
      gNonBlockingEraseBlockAddr = INVALID_BLOCK_ADDR;   	
   }

   return status;
}
#endif /*!(defined(__SPANSION_VS_R__) || defined(__SPANSION_WS_R__))*/

#if defined(__AMD_SERIES_NOR_PROGRAM__) || defined(__TOSHIBA_TV__) || defined(__TOSHIBA_TY__)
/*******************************************************************//**
 * Check if device is ready (for erase only)
 *
 * @par Category:
 * NOR MTD (Multi-Bank and Low-Cost Single Bank)
 *
 * @note
 * 1. Only called by EraseBlock_AMD() and EraseBlockList()
 *
 **********************************************************************/
__nor_section_RAM static int CheckDeviceReady_AMD(void * DriveData, kal_uint32 BlockIndex) /* Added by Eric */
{
   FLASH_CELL        s1, s2;
   kal_uint32        data_cache_id;
   kal_int32         status      = FS_DATA_ERROR;
   static kal_uint32 test_times  = 0;
   static kal_uint32 poll_times  = 0;

#ifndef __NOR_FDM5__
   NOR_Flash_MTD_Data * D = DriveData;
   volatile FLASH_CELL * fp = (volatile FLASH_CELL *) D->CurrAddr;
   #ifdef DEBUG
   //EraseBlock: block not mapped
   ASSERT(D->CurrAddr == BlockAddress(D, BlockIndex));
   #endif
   ASSERT((~D->Signature == (kal_uint32)D->RegionInfo));
#else  /* __NOR_FDM5__ */
   NOR_MTD_DATA *D= DriveData;
   volatile FLASH_CELL * fp = (volatile FLASH_CELL *)BlockAddress(D,BlockIndex);
   ASSERT(D->Signature == ~((kal_uint32)D->LayoutInfo));
#endif /* !__NOR_FDM5__ */

   data_cache_id = INT_DisableDataCache();

   s1 = fp[1];
   s2 = fp[1];

   // DQ6 is toggling
   if ((s1 ^ s2) & TOGGLE_BUSY)
   {
      #ifndef __SST_NOR__
      if(s2 & TOGGLE_TIMEOUT)
      {
         s1 = fp[1];
         s2 = fp[1];
         if((s1 ^ s2) & TOGGLE_BUSY)
         {
            // operation timed out
            fp[0] = CMD_RESET;
            test_times++;
            if (test_times > 2) {
            	MTD_ASSERT(0, 0, 0, 0, NOR_MTD_ERASE_TIMEOUT);
            }

            EraseCommand_AMD(fp);
            status = FS_FLASH_ERASE_BUSY;
         }
         else
         {
            test_times = 0;
            status = FS_NO_ERROR;
         }
      }
      else
      {
         status = FS_FLASH_ERASE_BUSY;
      }
      #else  /* __SST_NOR__ */
      status = FS_FLASH_ERASE_BUSY;
      #endif /* !__SST_NOR__ */
   }
   else if (!(s2 & POLL_BUSY))
   {
      /**********************************************************************//**
       * DQ6 is not toggling, flash should be ready (i.e., DQ7=Data=1).
       *
       * In normal case, we should not enter here except that DQ6 is not reliable
       * (i.e., DQ6 stops toggling before flash is ready, DQ7=0). In such abnormal case,
       * DQ7 provides double confirm here. (w08.29)
       **************************************************************************/

      // limit the polling times to not hanging here if bit-flipping happens
      poll_times++;
      if (poll_times >= MAX_AMD_ERASE_POLL_TIMES)
      {
         s2 = fp[1];

         // compare data
         if (s2 == 0xFFFF)
         {
            status = FS_NO_ERROR;
         }
         else
         {
            fp[0] = CMD_RESET;
            MTD_ASSERT(0, 0, 0, 0, NOR_MTD_ERASE_POLL_BUSY_FAIL);
         }
      }
      else
      {
         status = FS_FLASH_ERASE_BUSY;
      }
   }

   /* DQ2 is toggling and DQ6 is NOT toggling. */
   else if (((s1 ^ s2) & TOGGLE_ERASE_SUSPEND))
   {
      /* This condition is redundant in NOR FDM 4.0 because erase will not be suspended during CheckDeviceReady in multi-bank.
         But may be used in NOR FDM 5.0 by IDLE reclaim */

      if(!((s1 ^ s2) & TOGGLE_BUSY))
      {
         // flash is erase suspended
         fp[0] = CMD_RESU_SEC_ERASE;
      }
      status = FS_FLASH_ERASE_BUSY;
   }
   else
   {
      s1 = fp[1];
      s2 = fp[1];

      if(s2 == 0xffff)
      {
         test_times = 0;
         status = FS_NO_ERROR;
      }
      else
      {
         fp[0] = CMD_RESET;/* ensure flash in read mode */

         #ifdef NOR_FLASH_TYPE_SPANSION_PL_J
         /* the erase operation is reset abnormally */
         if(!(s1 ^ s2))
         {
            /* MAUI_00218339: S71PL129JB0BAW9U need another busy time before     */
            /* polling, modify to allow second erase command to solve this issue */
            test_times++;
            if (test_times > 1)
               ASSERT(0);
            EraseCommand_AMD(fp);
         }
         status = FS_FLASH_ERASE_BUSY;
         #else
         //ASSERT(0);
         MTD_ASSERT(0, 0, 0, 0, NOR_MTD_ERASE_COMP_DATA_FAIL); // assert or not assert in production release?
         status = FS_NO_ERROR;
         #endif
      }
   }

   // blank check: check if this block is all 0xFF (basic load only)
   #if defined(__BASIC_LOAD_FLASH_TEST__)
   if (status == FS_NO_ERROR)
   {
      kal_uint32 i;
      kal_uint32 blockCellCnt = BlockSize(DriveData, BlockIndex) / sizeof(FLASH_CELL);

      for (i = 0; i < blockCellCnt; ++i) {
         if (fp[i] != 0xFFFF) {
            fp[0] = CMD_RESET;
            NORTEST_DisableWDT();
            MTD_ASSERT(0, 0, 0, 0, NOR_MTD_ERASE_COMP_BLOCK_DATA_FAIL);
         }
      }
   }
   #endif // __BASIC_LOAD_FLASH_TEST__ 

   // reset poll_times if device ready checking is done
   if (status != FS_FLASH_ERASE_BUSY) {
      poll_times = 0;
   }

   INT_RestoreDataCache(data_cache_id);
   
   BLTest(0); //Random Reset while device erase busy (Multi-bank)
   
   //Reset block address of non-blocking erase
   if((gNonBlockingEraseBlockAddr == (kal_uint32)fp) && (FS_NO_ERROR == status))
   {
      gNonBlockingEraseBlockAddr = INVALID_BLOCK_ADDR;   	
   }

   return status;
}
#endif /*(defined(__SPANSION_VS_R__) || defined(__SPANSION_WS_R__))*/
#endif /* __SINGLE_BANK_NOR_FLASH_SUPPORT__ */

/*******************************************************************//**
 * Suspend erasing block
 *
 * @par Category:
 * NOR MTD (General)
 *
 * @remarks
 * This function is NOT allowed to use for program suspend! Because this function will
 * use polling to check if flash is suspended. However program-suspended block is not
 * allowed to read!
 *
 * @note
 * Only used by NOR(SIB)_ReadSectors, SuspendEraseQueue(LCSB) and FDM 5.0
 **********************************************************************/
#if !defined(__COMBO_MEMORY_SUPPORT__)
#if (defined(__SPANSION_VS_R__) || defined(__SPANSION_WS_R__))
__nor_section_RAM static int SuspendErase_WVSR(void * DriveData, kal_uint32 BlockIndex)
{
   FLASH_CELL stat_data;
   kal_uint32 data_cache_id;
   kal_int32 result; 
   #ifdef NOR_RESUME_SUSPEND_INTERVAL
   kal_uint32 resume_to_suspend_duration;
   #endif   

#ifndef __NOR_FDM5__
   NOR_Flash_MTD_Data * D = DriveData;
   volatile FLASH_CELL * fp = (volatile FLASH_CELL *) D->CurrAddr;
   #if (defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__))
   kal_uint32 savedMask;
   #endif
#else
   NOR_MTD_DATA *D= DriveData;
   volatile FLASH_CELL * fp = (volatile FLASH_CELL *)BlockAddress(D,BlockIndex);
#endif

#ifdef NOR_RESUME_SUSPEND_INTERVAL
   /*******************************************************************//**
    * Disable interrupt to let resume_time_g be correct.
    * !NOTE: This delay in ESB/LCSB may cause 60-qbit assert! (Now ESB will not use this function)
    **********************************************************************/
   #if (defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__))
   savedMask = SaveAndSetIRQMask();
   #endif

   /* if flash was ever resumed */
   if (resume_time_g != NOR_DEFAULT_RESUME_TIME)
   {
      /* get current time */
      resume_to_suspend_duration = ust_get_current_time();

      /* calculate duration from last resume */
      resume_to_suspend_duration = ust_qbit_to_us(ust_get_duration(resume_time_g, resume_to_suspend_duration));

      /* wait awhile to satisfy timing requirement (tERS) */
      if (resume_to_suspend_duration < NOR_RESUME_SUSPEND_INTERVAL)
      {
         DelayAWhile_UST(NOR_RESUME_SUSPEND_INTERVAL - resume_to_suspend_duration);
      }

      /* reset resume_time_g */
      resume_time_g = NOR_DEFAULT_RESUME_TIME;
   }

   #if (defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__))
   RestoreIRQMask(savedMask);
   #endif
#endif   /* NOR_RESUME_SUSPEND_INTERVAL */

   #if (defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__))
   savedMask = SaveAndSetIRQMask();
   #endif

   data_cache_id = INT_DisableDataCache();

   fp[0]     = CMD_SUSP_SEC_ERASE;

   /*******************************************************************//**
    * Spansion NOR flash requires tESL delay before starting to polling status bits.
    * !NOTE: This delay in ESB/LCSB may cause 60-qbit assert! (Now ESB will not use this function)
    **********************************************************************/

   #ifdef NOR_SUSPEND_LATENCY
   DelayAWhile_UST(NOR_SUSPEND_LATENCY);
   #endif

   while(1)     
   {
      fp[ADDR_UNLOCK_1] = WVSR_CMD_RD_SR;
      stat_data = fp[0];
      if(stat_data & WVSR_READY_FLAG)
      {
        if(stat_data & WVSR_ERASE_SUSPEND)
        {  
           //erase suspend successfully
           result = FS_NO_ERROR;
        }
        else
        { 
            if(stat_data & WVSR_ERASE_ERROR_FLAG)
            { 
             //erase fail,suspend didn't really happen
             result = FS_FLASH_ERASE_BUSY;
             ASSERT(0);
            }
            else
            { 
             //erase successfully,suspend didn't really happen
             result = FS_NO_ERROR;
             //ASSERT(0);
            }
        }         
        break;
      }       
   }
   

   INT_RestoreDataCache(data_cache_id);

   #if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)
   NOR_FLASH_SUSPENDED = KAL_TRUE;
   RestoreIRQMask(savedMask);
   #endif

   BLTest(2);  // Do exception simulation randomly after flash is suspended.

   return result;
}

#else/*!(defined(__SPANSION_VS_R__) || defined(__SPANSION_WS_R__))*/

/*******************************************************************//**
 * Suspend erasing block
 *
 * @par Category:
 * NOR MTD (General)
 *
 * @remarks
 * This function is NOT allowed to use for program suspend! Because this function will
 * use polling to check if flash is suspended. However program-suspended block is not
 * allowed to read!
 *
 * @note
 * Only used by NOR(SIB)_ReadSectors, SuspendEraseQueue(LCSB) and FDM 5.0
 **********************************************************************/
__nor_section_RAM static int SuspendErase_AMD(void * DriveData, kal_uint32 BlockIndex) /* Added by Eric */
{
   FLASH_CELL s;
   kal_uint32 data_cache_id;
   #ifdef NOR_RESUME_SUSPEND_INTERVAL
   kal_uint32 resume_to_suspend_duration;
   #endif

#ifndef __NOR_FDM5__
   NOR_Flash_MTD_Data * D = DriveData;
   volatile FLASH_CELL * fp = (volatile FLASH_CELL *) D->CurrAddr;
   #if (defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__))
   kal_uint32 savedMask;
   #endif
#else
   NOR_MTD_DATA *D= DriveData;
   volatile FLASH_CELL * fp = (volatile FLASH_CELL *)BlockAddress(D,BlockIndex);
#endif

#ifdef NOR_RESUME_SUSPEND_INTERVAL
   /*******************************************************************//**
    * Disable interrupt to let resume_time_g be correct.
    * !NOTE: This delay in ESB/LCSB may cause 60-qbit assert! (Now ESB will not use this function)
    **********************************************************************/
   #if (defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__))
   savedMask = SaveAndSetIRQMask();
   #endif

   /* if flash was ever resumed */
   if (resume_time_g != NOR_DEFAULT_RESUME_TIME)
   {
      /* get current time */
      resume_to_suspend_duration = ust_get_current_time();

      /* calculate duration from last resume */
      resume_to_suspend_duration = ust_qbit_to_us(ust_get_duration(resume_time_g, resume_to_suspend_duration));

      /* wait awhile to satisfy timing requirement (tERS) */
      if (resume_to_suspend_duration < NOR_RESUME_SUSPEND_INTERVAL)
      {
         DelayAWhile_UST(NOR_RESUME_SUSPEND_INTERVAL - resume_to_suspend_duration);
      }

      /* reset resume_time_g */
      resume_time_g = NOR_DEFAULT_RESUME_TIME;
   }

   #if (defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__))
   RestoreIRQMask(savedMask);
   #endif
#endif   /* NOR_RESUME_SUSPEND_INTERVAL */

   #if (defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__))
   savedMask = SaveAndSetIRQMask();
   #endif

   data_cache_id = INT_DisableDataCache();

   fp[0]     = CMD_SUSP_SEC_ERASE;

   /*******************************************************************//**
    * Spansion NOR flash requires tESL delay before starting to polling status bits.
    * !NOTE: This delay in ESB/LCSB may cause 60-qbit assert! (Now ESB will not use this function)
    **********************************************************************/

   #ifdef NOR_SUSPEND_LATENCY
   DelayAWhile_UST(NOR_SUSPEND_LATENCY);
   #endif

   // polling DQ7. If block is erasing, DQ7 = 0, if block is erase-suspended, DQ7 = 1
   s = fp[0];
   while(!(s & POLL_BUSY))
      s = fp[0];

   INT_RestoreDataCache(data_cache_id);

   #if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)
   NOR_FLASH_SUSPENDED = KAL_TRUE;
   #endif

   #if (defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__))
   RestoreIRQMask(savedMask);
   #endif

   BLTest(2);  // Do exception simulation randomly after flash is suspended.

   return FS_NO_ERROR;
}
#endif /*(defined(__SPANSION_VS_R__) || defined(__SPANSION_WS_R__))*/

/*******************************************************************//**
 * Resume suspended operation
 *
 * @par Category:
 * NOR MTD (General)
 *
 * @note
 * Used in ALL FDM version (MB, ESB, LCSB and SIBLEY)
 **********************************************************************/
__nor_section_RAM static int ResumeErase_AMD(void * DriveData, kal_uint32 BlockIndex) /* Added by Eric */
{
   #if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)
   kal_uint32 savedMask;
   #endif
   #ifndef __NOR_FDM5__
   NOR_Flash_MTD_Data  *D  = DriveData;
   volatile FLASH_CELL *fp = (volatile FLASH_CELL *) D->CurrAddr;
   #else  /* __NOR_FDM5__ */
   NOR_MTD_DATA *D= DriveData;
   volatile FLASH_CELL *fp = (volatile FLASH_CELL *)BlockAddress(D, BlockIndex);
   #endif /* !__NOR_FDM5__ */

   #if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)
   savedMask = SaveAndSetIRQMask();         // Disable interrupt to let NOR_FLASH_SUSPENDED and resume_time_g be correct.
   #endif

   fp[0]     = CMD_RESU_SEC_ERASE;

   #ifdef NOR_RESUME_SUSPEND_INTERVAL
   resume_time_g = ust_get_current_time();  // get suspend time to guarantee tERS
   #endif

   #if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)
   NOR_FLASH_SUSPENDED = KAL_FALSE;

   tBUSYDelay();

   RestoreIRQMask(savedMask);
   #endif /* __SINGLE_BANK_NOR_FLASH_SUPPORT__ */

   return FS_NO_ERROR;
}
#endif // !__COMBO_MEMORY_SUPPORT__


#if defined(__FOTA_ENABLE__)
#if !defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)
#if defined(__COMBO_MEMORY_SUPPORT__)
__nor_section_RAM static int PF_DAL_LockEraseBlkAddr(void * DriveData, void *BlkAddr,UINT ACTION)
{
	  
	  if(ACTION == ACTION_UNLOCK)
	  {
		 return 0;
	  }
	  else if(ACTION== ACTION_LOCK)
	  {
		 return 0;
	  }
	  else if (ACTION== ACTION_ERASE)
	  {

         EraseBlock_AMD(DriveData, BlockIndex(DriveData, (kal_uint32)BlkAddr));
	  }
   else
   {
      ASSERT(0);
   }
   return FS_NO_ERROR;
}

#else
__nor_section_RAM static int LockEraseBlkAddr_AMD(void * DriveData, void *BlkAddr,UINT ACTION)
{
   kal_uint32 savedMask;
   kal_uint32 data_cache_id;
   volatile FLASH_CELL * fp = (volatile FLASH_CELL *) BlkAddr;

   if(ACTION == ACTION_UNLOCK)
   {
      return 0;
   }
   else if(ACTION== ACTION_LOCK)
   {
      return 0;
   }
   else if (ACTION== ACTION_ERASE)
   {
#if (defined(__SPANSION_VS_R__) || defined(__SPANSION_WS_R__))
      EraseCommand_WVSR(fp);
#else
      EraseCommand_AMD(fp);
#endif      
      #ifdef __SPANSION_PL_N__
      DelayAWhile_UST(54);  // 50 us to cover tSEA, and another 4 us is required to wait before polling (PL-N only)
      #endif
#if (defined(__SPANSION_VS_R__) || defined(__SPANSION_WS_R__))
      WaitReady_WVSR((kal_uint32)fp);
#else
      WaitReady_AMD((kal_uint32)fp,0xFFFF);
#endif
   }
   else
   {
      ASSERT(0);
   }
   return FS_NO_ERROR;
}
#endif
#else /* __SINGLE_BANK_NOR_FLASH_SUPPORT__ */

__nor_section_RAM static int LockEraseBlkAddr_AMD(void * DriveData, void *BlkAddr,UINT ACTION)
{
   return FS_NO_ERROR;
}

#endif /* !__SINGLE_BANK_NOR_FLASH_SUPPORT__ */
#endif /* __FOTA_ENABLE__ */

/********************************************/
/*                                          */
/*           FDM5.0 MTD SUPPORT             */
/*                                          */
/********************************************/
#ifdef __NOR_FDM5__

__nor_section_RAM static int MountDevice_AMD(void * DriveData, void * Info)
{
   NOR_MTD_DATA * D = DriveData;
   NORLayoutInfo * Layout = D->LayoutInfo;
   kal_uint32 TotalPhysicalPages;
   kal_uint32 TblEntryShift=0,j=1;
   kal_uint32 block;
   volatile FLASH_CELL * fp;
   kal_uint32 savedMask;
   kal_uint32 data_cache_id;
   

   // check and assign D->LayoutInfo
   TotalPhysicalPages = (Layout->BlkSize)/(Layout->PageSize)*(Layout->TotalBlks);
   while(j<TotalPhysicalPages)
   {
      j = j << 1;
      TblEntryShift++;
   }
   TblEntryShift = TblEntryShift>>1;
   if((TblEntryShift) >8)
	   TblEntryShift=8;
   Layout->TblEntrys = 1<<TblEntryShift;

   if ( (Layout->TblEntrys * Layout->TotalLSMT) < TotalPhysicalPages)
      ASSERT(0);

   /* unlock all blocks */
   for(block=0; block< Layout->TotalBlks; block++)
   {

      fp = (volatile FLASH_CELL *) BlockAddress(D, block);

      savedMask = SaveAndSetIRQMask();
      data_cache_id = INT_DisableDataCache();

      /* enter block protection/unprotection command sequence */
      fp[0] = 0x60;
      fp[0] = 0x60;

      #if defined(__SPANSION_NS_J__)
      *(kal_uint16*)(((kal_uint32)fp) | 0x80)  = 0x60;
      #elif defined(__SAMSUNG_SPANSION_NS_J_LIKE__)
      *(kal_uint16*)(((kal_uint32)fp) | 0x84)  = 0x60;
      #endif

      /* exit block protection/unprotection command sequence (by reset command) */
      fp[0] = 0xF0;


      INT_RestoreDataCache(data_cache_id);
      RestoreIRQMask(savedMask);
   }

   return FS_NO_ERROR;
}

__nor_section_RAM static int ShutDown_AMD(void * DriveData)
{
   NOR_MTD_DATA        *D = DriveData;
   NORBankInfo         *BankInfo = D->LayoutInfo->BankInfo;
   volatile FLASH_CELL *fp = (volatile FLASH_CELL*)D->BaseAddr;
   FLASH_CELL          s1, s2;
   kal_uint32          i = 0, j = 0;
   kal_uint32          data_cache_id;

   data_cache_id = INT_DisableDataCache();

   for(i=0;BankInfo[i].Banks !=0;i++)
      for(j=0;j<BankInfo[i].Banks;j++)
      {
         while(1)
         {
            s1 = fp[0];
            s2 = fp[0];
            if ((s1 ^ s2)==0)
               break;
            else
            {
               if(s2 & TOGGLE_TIMEOUT)
               {
                  s1 = fp[0];
                  s2 = fp[0];
                  if ((s1 ^ s2)==0)
                     break;
                  else
                  {
                     fp[0] = CMD_RESET;
                     break;
                  }
               }
            }
         }
         fp= (volatile FLASH_CELL*)((kal_uint32)fp + (kal_uint32)BankInfo[i].BankSize);
      }

   INT_RestoreDataCache(data_cache_id);

   return FS_NO_ERROR;
}
#endif /* __NOR_FDM5__ */


/*--------------------------------------------------------------------------
     Single bank NOR flash support
  --------------------------------------------------------------------------*/
#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)

#if !defined(__FUE__)


#ifdef __SPANSION_GL_N__
#define ERASE_ROUNDS (32)
__nor_section_RAM kal_int32 EraseBlockList(void * DriveData, kal_uint32* list, kal_uint32 items)
{
   NOR_Flash_MTD_Data *D = (NOR_Flash_MTD_Data *)DriveData;
   kal_uint32 savedMask;
   kal_uint32 rounds = 0;
   kal_uint32 idx = 0, start = 0;
   volatile FLASH_CELL *fp = (volatile FLASH_CELL*)D->BaseAddr;
   while(items)
   {
      if(items > ERASE_ROUNDS)
         rounds = ERASE_ROUNDS;
      else
         rounds = items;

      savedMask = SaveAndSetIRQMask();
      fp[ADDR_UNLOCK_1] = CMD_UNLOCK_1;
      fp[ADDR_UNLOCK_2] = CMD_UNLOCK_2;
      fp[ADDR_UNLOCK_1] = CMD_SERASE;
      fp[ADDR_UNLOCK_1] = CMD_UNLOCK_1;
      fp[ADDR_UNLOCK_2] = CMD_UNLOCK_2;
      for(idx = 0; idx < rounds; idx++)
      {
         fp = (volatile FLASH_CELL*)BlockAddress(D, list[idx+start]);
         fp[0] = CMD_SERASE_END;
      }
      D->CurrAddr = (BYTE *)fp;/* for CheckDeviceReady_AMD() use */
      RestoreIRQMask(savedMask);
      while(FS_FLASH_ERASE_BUSY == CheckDeviceReady_AMD(D, list[idx-1+start]));
      start += rounds;
      items -= rounds;
   }
   return 0;
}
#endif/* __SPANSION_GL_N__ */

/* ------------------------------------------------------------------ */
#if (defined(__SPANSION_VS_R__) || defined(__SPANSION_WS_R__))

__nor_section_RAM kal_bool IsEraseSuspended_WVSR(void * DriveData, kal_uint32 BlockIndex)
{
   kal_uint16 stat_data = 0;
   kal_uint32 data_cache_id = 0, savedMask = 0;
#ifndef __NOR_FDM5__
   NOR_Flash_MTD_Data * D = DriveData;
   volatile FLASH_CELL * fp = (volatile FLASH_CELL *) D->CurrAddr;
   #ifdef DEBUG
      SNOR_MTD_ASSERT(D->CurrAddr == BlockAddress(D, BlockIndex), (kal_uint32)(D->CurrAddr), (kal_uint32)(BlockAddress(D, BlockIndex)), BlockIndex);
   #endif
#else
   NOR_MTD_DATA *D= DriveData;
   volatile FLASH_CELL * fp = (volatile FLASH_CELL *)BlockAddress(D,BlockIndex);
#endif

   savedMask = SaveAndSetIRQMask();

   data_cache_id = INT_DisableDataCache();

   // Ready Status
   fp[ADDR_UNLOCK_1] = WVSR_CMD_RD_SR;
   stat_data = fp[0];

   // Switch back to Array mode automatically

   INT_RestoreDataCache(data_cache_id);
   RestoreIRQMask(savedMask);

   if(stat_data & WVSR_READY_FLAG)
   {
      if(stat_data & WVSR_ERASE_SUSPEND)
      {
         return KAL_TRUE;
      }
   }
   
   return KAL_FALSE;
}

#else //!__SPANSION_VS_R__ && __SPANSION_WS_R__

__nor_section_RAM kal_bool IsEraseSuspended_AMD(void * DriveData, kal_uint32 BlockIndex)
{
   kal_uint16 data_toggle1 = 0, data_toggle2 = 0;
   kal_uint32 data_cache_id = 0, savedMask = 0;
   kal_bool   status = KAL_FALSE;
#ifndef __NOR_FDM5__
   NOR_Flash_MTD_Data * D = DriveData;
   volatile FLASH_CELL * fp = (volatile FLASH_CELL *) D->CurrAddr;
   #ifdef DEBUG
      #if (defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__))
      SNOR_MTD_ASSERT(D->CurrAddr == BlockAddress(D, BlockIndex), (kal_uint32)(D->CurrAddr), (kal_uint32)(BlockAddress(D, BlockIndex)), BlockIndex);
      #else
      //EraseBlock: block not mapped
      ASSERT(D->CurrAddr == BlockAddress(D, BlockIndex));
      #endif
   #endif
#else
   NOR_MTD_DATA *D= DriveData;
   volatile FLASH_CELL * fp = (volatile FLASH_CELL *)BlockAddress(D,BlockIndex);
#endif

   #if (defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__))
   savedMask = SaveAndSetIRQMask();
   #endif

   data_cache_id = INT_DisableDataCache();

   data_toggle1 = fp[1];
   data_toggle2 = fp[1];

   INT_RestoreDataCache(data_cache_id);
   #if (defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__))
   RestoreIRQMask(savedMask);
   #endif

   if ( (data_toggle1 ^ data_toggle2) & TOGGLE_ERASE_SUSPEND )
   {
      if(!((data_toggle1 ^ data_toggle2) & TOGGLE_BUSY))
      {
         /* flash is erase suspended */
         status = KAL_TRUE;
      }
      status = KAL_FALSE;
   }
   return status;
}
#endif //__SPANSION_VS_R__ || __SPANSION_WS_R__


#else    /* __FUE__ */

kal_bool IsEraseSuspended_AMD(void * DriveData, kal_uint32 BlockIndex)
{
   return KAL_FALSE;
}

kal_bool IsEraseSuspended_WVSR(void * DriveData, kal_uint32 BlockIndex)
{
   return KAL_FALSE;
}

#endif   /* !__FUE__ */

#endif   /* __SINGLE_BANK_NOR_FLASH_SUPPORT__ */


/****************************************************************************/
/*                                                                          */
/*                    Support NOR Flash OTP Function                        */
/*                                                                          */
/****************************************************************************/

#ifdef __SECURITY_OTP__

extern kal_uint32 INT_RetrieveFlashBaseAddr(void);

static const kal_uint32 NOR_OTPOffset = 0x100;
static const kal_uint32 NOR_OTPLength = 0x100;

#define CMD_OTP_ENTRY 0x88
#define CMD_OTP_EXIT  0x90
#define CMD_OTP_ZERO  0x00
#define CMD_AUTOSELECT_ENTRY 0x90
#define CMD_AUTOSELECT_EXIT  0xF0
#define CMD_LOCKREG_ENTRY    0x40
#define CMD_LOCKREG_PROG     0xA0
#define CMD_LOCKREG_EXIT1    0x90
#define CMD_LOCKREG_EXIT2    0x00


#define OTP_ERR_NONE 0
#define OTP_ERR_OVERSCOPE 1
#define OTP_ERR_BUSY 2
#define OTP_ERR_WAIT 3

/*------------------------------------------------------------------------------
 * NOTE: When r/w OTP region, NOR flash must enter "OTP mode". Therefore OTP related
 * functions must be put in RAM to avoid code fetch issue.
 *-------------------------------------------------------------------- W09.08 --*/

__nor_section_RAM kal_int32
OTPCheckWriteReady_AMD(kal_uint32 addr,kal_uint16 data)
{
   kal_uint16 data_test1,data_test2;
   kal_uint32 data_cache_id;
   kal_int32 status = OTP_ERR_NONE;


   data_cache_id = INT_DisableDataCache();
   data_test1 = *(volatile kal_uint16*)addr;
   if((data_test1 & POLL_BUSY) == (data & POLL_BUSY))
   {
      data_test1 = *(volatile kal_uint16*)addr;
      data_test2 = *(volatile kal_uint16*)addr;
      if (data_test2 == data)
         status = OTP_ERR_NONE;
      else
      {
         status = OTP_ERR_WAIT;
      }
   }
#ifndef __SST_NOR__
   else if(data_test1 & POLL_TIMEOUT) //DQ5 = 1 may imply a timeout happens
   {
      data_test1 = *(volatile kal_uint16*)addr;
      data_test2 = *(volatile kal_uint16*)addr;

      if((data_test1 ^ data_test2) & TOGGLE_BUSY)
      {
         status = OTP_ERR_WAIT;
      }
   }
#endif
   else
   {
      status = OTP_ERR_BUSY;
   }
   INT_RestoreDataCache(data_cache_id);
   return status;
}

/*************************************************************************
* FUNCTION
*    OTPRead
*
* DESCRIPTION
*    This function implements the OTP read function, first it enter
*    secured silicon sector, and read data from "Offset", totally read
*    "Length" bytes, then exit secured silicon sector mode
*
* PARAMETERS
*    D: driver structure
*    Offset: the start position want to read (unit:bytes)
*    BufferPtr: the buffer address want to read to
*    Length: total length want to read (unit: bytes)
*
* RETURNS
*   FS_NO_ERROR: no error
*   FS_FLASH_OTP_OVERSCOPE: reading range is out of OTP range
*
*************************************************************************/

/* While the Secured Silicon Sector access is enabled, simultaneous
 * operations are not allow fro bank A.
 */

__nor_section_RAM kal_int32
OTPRead_AMD(void * DriveData,
            kal_uint32 Offset,
            void * BufferPtr,
            kal_uint32 Length)
{
   NOR_Flash_MTD_Data * MTDData = DriveData;
   kal_uint32 savedMask,i;
   volatile FLASH_CELL *BaseAddr;
   kal_uint8 *src,*dest;
   kal_uint32 data_cache_id;

   /* drvier initialization test */
   ASSERT((~MTDData->Signature == (kal_uint32)MTDData->RegionInfo));

   BaseAddr = (volatile FLASH_CELL *)(INT_RetrieveFlashBaseAddr() | 0x4000000);
   src = (kal_uint8 *)((kal_uint32)BaseAddr + NOR_OTPOffset + Offset);
   dest =(kal_uint8 *)BufferPtr;

   /* Base Addr check */
   ASSERT(!(((kal_uint32)BaseAddr) % sizeof(FLASH_CELL)));

   /* check if read scope is out of range */
   if( (Offset > NOR_OTPLength) ||
       (Offset+ Length)> NOR_OTPLength )
   {
      return FS_FLASH_OTP_OVERSCOPE;
   }

   /* Disable Interrupt */
   savedMask = SaveAndSetIRQMask();
   data_cache_id = INT_DisableDataCache();

   /* Enter Secured Silicon Sector Mode */
   BaseAddr[ADDR_UNLOCK_1] = CMD_UNLOCK_1;
   BaseAddr[ADDR_UNLOCK_2] = CMD_UNLOCK_2;
   BaseAddr[ADDR_UNLOCK_1] = CMD_OTP_ENTRY;

   /* Read Secured Silicon Sector Data */
   for(i=0; i< Length; i++)
      dest[i] = src[i];

   /* Exit Secured Silicon Sector Mode */
   BaseAddr[ADDR_UNLOCK_1] = CMD_UNLOCK_1;
   BaseAddr[ADDR_UNLOCK_2] = CMD_UNLOCK_2;
   BaseAddr[ADDR_UNLOCK_1] = CMD_OTP_EXIT;
   BaseAddr[0] =  CMD_OTP_ZERO;

   /* Enable Interrupt */
   INT_RestoreDataCache(data_cache_id);
   RestoreIRQMask(savedMask);

   return FS_NO_ERROR;
}

/*************************************************************************
* FUNCTION
*    OTPWrite
*
* DESCRIPTION
*    This function implements the OTP write function, first it enter
*    secured silicon sector, and write data from "Offset", totally write
*    "Length" bytes, then exit secured silicon sector mode.
*    Be carefully, do not set bit to one if it is zero
*
* PARAMETERS
*    D: driver structure
*    Offset: the start position want to write (unit:bytes)
*    BufferPtr: the buffer address want to write from
*    Length: total length want to write (unit: bytes)
*
* RETURNS
*   FS_NO_ERROR: no error
*   FS_FLASH_OTP_OVERSCOPE: writing range is out of OTP range
*   FS_FLASH_OTP_LOCK_ALREADY: OTP area is already locked
*
*************************************************************************/


__nor_section_RAM kal_int32
OTPWrite_AMD(void * DriveData,
             kal_uint32 Offset,
             void * BufferPtr,
             kal_uint32 Length)
{
   NOR_Flash_MTD_Data * MTDData = DriveData;
   kal_uint32 savedMask,DoneLength=0;
   volatile FLASH_CELL *BaseAddr;
   FLASH_CELL IndicatorBit;
   kal_int32 status;

   kal_uint8 *src,*dest;
   kal_uint16 *dest16;
   FLASH_CELL CELL;
   kal_uint8 *CELLPtr = (kal_uint8 *)&CELL;

   /* drvier initialization test */
   ASSERT((~MTDData->Signature == (kal_uint32)MTDData->RegionInfo));

   BaseAddr = (volatile FLASH_CELL*)(INT_RetrieveFlashBaseAddr() | 0x4000000);
   dest = (kal_uint8 *)((kal_uint32)BaseAddr + NOR_OTPOffset + Offset);
   src =(kal_uint8 *)BufferPtr;

   /* Base Addr check */
   ASSERT(!(((kal_uint32)BaseAddr) % sizeof(FLASH_CELL)));

   /* check if read scope is out of range */
   if( (Offset > NOR_OTPLength) ||
       (Offset+ Length)> NOR_OTPLength )
   {
      return FS_FLASH_OTP_OVERSCOPE;
   }

   /* Disable Interrupt */
   savedMask = SaveAndSetIRQMask();

   /* Enter Auto Select Mode */
   BaseAddr[ADDR_UNLOCK_1] = CMD_UNLOCK_1;
   BaseAddr[ADDR_UNLOCK_2] = CMD_UNLOCK_2;
   BaseAddr[ADDR_UNLOCK_1] = CMD_AUTOSELECT_ENTRY;

   IndicatorBit = BaseAddr[3];

   /* Exit Auto Select Mode */
   BaseAddr[0] = CMD_AUTOSELECT_EXIT;

   /* Enable Interrupt */
   RestoreIRQMask(savedMask);

   if ((IndicatorBit & 0x40))
   {
      return FS_FLASH_OTP_LOCK_ALREADY;
   }

   while ( DoneLength < Length )
   {
      /* Disable Interrupt */
      savedMask = SaveAndSetIRQMask();

      /* Enter Secured Silicon Sector Mode */
      BaseAddr[ADDR_UNLOCK_1] = CMD_UNLOCK_1;
      BaseAddr[ADDR_UNLOCK_2] = CMD_UNLOCK_2;
      BaseAddr[ADDR_UNLOCK_1] = CMD_OTP_ENTRY;

      //enter write command to flash
      if ( ((kal_uint32)dest&(sizeof(FLASH_CELL)-1)) || ((Length-DoneLength)==1) ) //not word align
      {
         kal_uint32 ofs = ((kal_uint32) dest) & (sizeof(FLASH_CELL)-1);
         kal_uint8 *b = (kal_uint8 *)&CELL;

         dest16 = (kal_uint16 *)(((kal_uint32)dest) & ~(sizeof(FLASH_CELL)-1));
         CELL = dest16[0];
         b[ofs] = src[0];

      }
      else //word align
      {
         dest16 = (kal_uint16 *)dest;
         CELLPtr[0] = src[0];
         CELLPtr[1] = src[1];
      }
      /*check write content:attempt to set bits in flash (0->1) */
      if((~(dest16[0])) & CELL)
      {
         /* exit secured Silicon Sector Mode */
         BaseAddr[ADDR_UNLOCK_1] = CMD_UNLOCK_1;
         BaseAddr[ADDR_UNLOCK_2] = CMD_UNLOCK_2;
         BaseAddr[ADDR_UNLOCK_1] = CMD_OTP_EXIT;
         BaseAddr[0] =  CMD_OTP_ZERO;
         BaseAddr[0] = CMD_RESET;
         /* Enable Interrupt */
         RestoreIRQMask(savedMask);
         ASSERT(0);
      }

      //write one word to flash
      BaseAddr[ADDR_UNLOCK_1] = CMD_UNLOCK_1;
      BaseAddr[ADDR_UNLOCK_2] = CMD_UNLOCK_2;
      BaseAddr[ADDR_UNLOCK_1] = CMD_PROG;
      dest16[0] = CELL;
      DelayAWhile_UST(5);

      /* check till ready */
      while(1)
      {

         status = OTPCheckWriteReady_AMD((kal_uint32)dest16 ,(kal_uint16) CELL);
         if(status == OTP_ERR_NONE)
         {
            break;
         }else if(status == OTP_ERR_WAIT)
         {
            /* exit secured Silicon Sector Mode */
            BaseAddr[ADDR_UNLOCK_1] = CMD_UNLOCK_1;
            BaseAddr[ADDR_UNLOCK_2] = CMD_UNLOCK_2;
            BaseAddr[ADDR_UNLOCK_1] = CMD_OTP_EXIT;
            BaseAddr[0] =  CMD_OTP_ZERO;
            BaseAddr[0] = CMD_RESET;
            /* Enable Interrupt */
            RestoreIRQMask(savedMask);
            ASSERT(0);
         }
      }
      /* Exit Secured Silicon Sector Mode */
      BaseAddr[ADDR_UNLOCK_1] = CMD_UNLOCK_1;
      BaseAddr[ADDR_UNLOCK_2] = CMD_UNLOCK_2;
      BaseAddr[ADDR_UNLOCK_1] = CMD_OTP_EXIT;
      BaseAddr[0] =  CMD_OTP_ZERO;
      /* Enable Interrupt */
      RestoreIRQMask(savedMask);

      /* addr offset */
      if ( ((kal_uint32)dest&(sizeof(FLASH_CELL)-1)) || ((Length-DoneLength)==1) ) //not word align
      {
         dest+=1;
         src+=1;
         DoneLength+=1;
      }
      else
      {
         dest+=2;
         src+=2;
         DoneLength+=2;
      }
   }
   return FS_NO_ERROR;
}

/*************************************************************************
* FUNCTION
*    OTPLock
*
* DESCRIPTION
*    This function implements the OTP lock function.
* PARAMETERS
*    D: driver structure
*
* RETURNS
*   FS_NO_ERROR: no error
*   FS_FLASH_OTP_LOCK_ALREADY: OTP area is already locked
*
*************************************************************************/
__nor_section_RAM kal_int32 OTPLock_AMD(void * DriveData)
{
   NOR_Flash_MTD_Data * MTDData = DriveData;
   kal_uint32 savedMask;
   volatile FLASH_CELL *BaseAddr = (volatile FLASH_CELL*)(INT_RetrieveFlashBaseAddr() | 0x4000000);
   FLASH_CELL IndicatorBit,CELL;
   kal_int32 status;


   /* drvier initialization test */
   ASSERT((~MTDData->Signature == (kal_uint32)MTDData->RegionInfo));


   /* Disable Interrupt */
   savedMask = SaveAndSetIRQMask();

   /* Enter Auto Select Mode */
   BaseAddr[ADDR_UNLOCK_1] = CMD_UNLOCK_1;
   BaseAddr[ADDR_UNLOCK_2] = CMD_UNLOCK_2;
   BaseAddr[ADDR_UNLOCK_1] = CMD_AUTOSELECT_ENTRY;

   // offset 03h: Indicator bits
   // DQ6: Customer lock bit (1: locked)
   // DQ7: Factory lock bit
   IndicatorBit = BaseAddr[3];

   /* Exit Auto Select Mode */
   BaseAddr[0] = CMD_AUTOSELECT_EXIT;

   // check DQ6 (customer lock bit)
   if ((IndicatorBit & 0x40))
   {
      /* Enable Interrupt */
      RestoreIRQMask(savedMask);
      return FS_FLASH_OTP_LOCK_ALREADY;
   }

   /* Enter Lock Register Mode */
   BaseAddr[ADDR_UNLOCK_1] = CMD_UNLOCK_1;
   BaseAddr[ADDR_UNLOCK_2] = CMD_UNLOCK_2;
   BaseAddr[ADDR_UNLOCK_1] = CMD_LOCKREG_ENTRY;

   // program Lock Register DQ0: Secured Silicon Sector (OTP region) Protection bit
   // 0: Locked / 1: Unlocked
   CELL = BaseAddr[0];
   CELL &= 0xFFFE;
   BaseAddr[0] = CMD_LOCKREG_PROG;
   BaseAddr[0] = CELL;

   // delay awhile, for example, PL-N requires 4 us delay before check status bits.
   DelayAWhile_UST(50);

   /* check till ready */
   while( (status = OTPCheckWriteReady_AMD((kal_uint32)BaseAddr ,(kal_uint16) CELL)) != OTP_ERR_NONE)
   {
      if (status == OTP_ERR_WAIT)
      {
         BaseAddr[0] = CMD_RESET;
         /* Enable Interrupt */
         RestoreIRQMask(savedMask);
         ASSERT(0);
      }
   }

   BaseAddr[0] = CMD_LOCKREG_EXIT1;
   BaseAddr[0] = CMD_LOCKREG_EXIT2;

   /* Enable Interrupt */
   RestoreIRQMask(savedMask);

   return FS_NO_ERROR;
}

__nor_section_RAM kal_int32
OTPAccess_AMD(void * DriveData, kal_int32 accesstype, kal_uint32 Offset, void * BufferPtr, kal_uint32 Length)
{
   if (accesstype==FS_OTP_READ)
   {
      return OTPRead_AMD(DriveData, Offset, BufferPtr,Length);
   }
   else if (accesstype==FS_OTP_WRITE)
   {
      return OTPWrite_AMD(DriveData,Offset,BufferPtr,Length);
   }
   else if (accesstype==FS_OTP_LOCK)
   {
      return OTPLock_AMD(DriveData);
   }
   else
   {
      ASSERT(0);
   }
}

__nor_section_RAM kal_int32
OTPQueryLength_AMD(void * DriveData, UINT *LengthPtr)
{
   *LengthPtr = NOR_OTPLength;
   return FS_NO_ERROR;
}


# endif /*__SECURITY_OTP__*/

/*-----------------------------------*/
#if !defined(__COMBO_MEMORY_SUPPORT__)
#if (defined(__SPANSION_VS_R__) || defined(__SPANSION_WS_R__))
const NOR_MTD_Driver DriverName =
{
   MountDevice_AMD,
   ShutDown_WVSR,
   MapWindow,
   EraseBlock_AMD,
   ProgramData_WVSR,
   NonBlockEraseBlock_AMD,
#ifdef __UBL__
   NULL,
#else
   CheckDeviceReady_WVSR,
#endif
   SuspendErase_WVSR,
   ResumeErase_AMD,
   NULL,
#ifdef __SECURITY_OTP__
   OTPAccess_AMD,
   OTPQueryLength_AMD,
#else
   NULL,
   NULL,
#endif
#if defined(__FOTA_ENABLE__)
   LockEraseBlkAddr_AMD
#else
   NULL
#endif
#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)
   ,IsEraseSuspended_WVSR
#else
   ,NULL
#endif

};
#else //!__SPANSION_VS_R__ &&!__SPANSION_VS_R__
const NOR_MTD_Driver DriverName =
{
   MountDevice_AMD,
   ShutDown_AMD,
   MapWindow,
   EraseBlock_AMD,
#if (defined(__TOSHIBA_TV__) || defined(__TOSHIBA_TY__))
   ProgramData_TOSHIBA,
#else
   ProgramData_AMD,
#endif
   NonBlockEraseBlock_AMD,
#ifdef __UBL__
   NULL,
#else
   CheckDeviceReady_AMD,
#endif   
   SuspendErase_AMD,
   ResumeErase_AMD,
   NULL,
#ifdef __SECURITY_OTP__
   OTPAccess_AMD,
   OTPQueryLength_AMD,
#else
   NULL,
   NULL,
#endif
#if defined(__FOTA_ENABLE__)
   LockEraseBlkAddr_AMD
#else
   NULL
#endif
#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)
   ,IsEraseSuspended_AMD
#else
   ,NULL
#endif

};
#endif //__SPANSION_VS_R__ || __SPANSION_WS_R__
#else //__COMBO_MEMORY_SUPPORT__

const NOR_MTD_Driver NORFlashMtd_AMD =
{
   PF_DAL_MountDevice,
   PF_DAL_ShutDown,
   MapWindow,
   EraseBlock_AMD,
   NULL, //ProgramData_WVSR, ProgramData_TOSHIBA, ProgramData_AMD
   NonBlockEraseBlock_AMD,
   NULL, //CheckDeviceReady_WVSR, CheckDeviceReady_AMD
   PF_DAL_SuspendErase,
   PF_DAL_ResumeErase,
   NULL,
#ifdef __SECURITY_OTP__
   OTPAccess_AMD,
   OTPQueryLength_AMD,
#else
   NULL,
   NULL,
#endif
#if defined(__FOTA_ENABLE__)
   PF_DAL_LockEraseBlkAddr
#else
   NULL
#endif
   ,NULL //IsEraseSuspended_WVSR, IsEraseSuspended_AMD: deprecated, not used in FDM (ESB)

};

void ADMUX_DAL_Init_Common(NOR_MTD_Driver *driver, PF_MTD_Data *data)
{
    PF_Status          *map;

	*driver = NORFlashMtd_AMD;
	data->CMD->Resume = CMD_RESU_SEC_ERASE;
	data->CMD->Suspend = CMD_SUSP_SEC_ERASE;
    map  = (PF_Status*) data->StatusMap;
	map[PF_SR_READY] = PF_AMD_SR_READY;

}


#ifdef __AMD_SERIES_NOR_PROGRAM__

kal_int32 ADMUX_DAL_Init_AMD(NOR_MTD_Driver *driver, PF_MTD_Data *data)
{
	ADMUX_DAL_Init_Common(driver, data);

   driver->ProgramData = ProgramData_AMD;
   driver->CheckDeviceReady = CheckDeviceReady_AMD;
   data->CMD->CMD_EraseBlock = PF_DAL_Dev_EraseBlock_AMD;
   data->CMD->CMD_ReadStatus = PF_DAL_Dev_ReadStatus_AMD;

   return CMEM_NO_ERROR;   	
}
#endif

#if defined(__SPANSION_VS_R__) || defined(__SPANSION_WS_R__)
kal_int32 ADMUX_DAL_Init_WVSR(NOR_MTD_Driver *driver, PF_MTD_Data *data)
{

   PF_Status		  *map;

   ADMUX_DAL_Init_Common(driver, data);
   
   driver->ProgramData = ProgramData_WVSR;
   driver->CheckDeviceReady = CheckDeviceReady_WVSR;
   data->CMD->CMD_EraseBlock = PF_DAL_Dev_EraseBlock_WVSR;
   data->CMD->CMD_ReadStatus = PF_DAL_Dev_ReadStatus_WVSR;
   map	= (PF_Status*) data->StatusMap;
   map[PF_SR_READY] = PF_INTEL_SR_READY;

   return CMEM_NO_ERROR;
}
#endif

#if (defined(__TOSHIBA_TV__) || defined(__TOSHIBA_TY__))
kal_int32 ADMUX_DAL_Init_TOSHIBA(NOR_MTD_Driver *driver, PF_MTD_Data *data)
{
   ADMUX_DAL_Init_Common(driver, data);

   driver->ProgramData = ProgramData_TOSHIBA;
   driver->CheckDeviceReady = CheckDeviceReady_AMD;
   data->CMD->CMD_EraseBlock = PF_DAL_Dev_EraseBlock_AMD;
   data->CMD->CMD_ReadStatus = PF_DAL_Dev_ReadStatus_AMD;
   
   return CMEM_NO_ERROR;
}
#endif

#endif // !__COMBO_MEMORY_SUPPORT__


#endif //__AMD_SERIES_NOR__
