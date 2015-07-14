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
 *    flash_mtd_sf_dal.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   The MTD driver for serial Flash devices
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================*/

/**
 * @file flash_sf.c
 * @brief
 *    The MTD driver for serial Flash devices.
 *    Related compile options:
 *      __SERIAL_FLASH__ - Enable SF DAL driver
 *          SF_DAL_MXIC    - Enable MXIC series SF support
 *          SF_DAL_SST     - Enable SST series SF support
 *          SF_DAL_EON     - Enable EON series SF support
 *          SF_DAL_WINBOND - Enable WINBOND series SF support
 */

#include "flash_opt.h"
#include "flash_mtd_ut.h"

//-----------------------------------------------------------------------------
// [Section] RVCT and GCC
//-----------------------------------------------------------------------------

#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__) && defined(__MTK_TARGET__)
#if defined(__UBL__)
#define __sf_section_RAM             __attribute__ ((section ("INTERNCODE")))
#define __sf_section_SECOND_PART     __attribute__ ((section ("SECOND_PART")))
#define __sf_section_EMIINITCODE     __attribute__ ((section ("INTERNCODE")))
#else
#define __sf_section_RAM             __attribute__ ((section ("SNORCODE")))
#define __sf_section_SECOND_PART     __attribute__ ((section ("SECOND_PART")))
#define __sf_section_EMIINITCODE     __attribute__ ((section ("EMIINITCODE")))
#endif
#else //defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__) && defined(__MTK_TARGET__)
/* Reserve for  MoDIS */
#define __sf_section_RAM
#define __sf_section_SECOND_PART
#define __sf_section_EMIINITCODE
#endif //defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__) && defined(__MTK_TARGET__)
#define __NOR_LEAKAGE__

#ifdef __SERIAL_FLASH__

#ifdef __SF_DVT__
#include "flash_mtd_sf_dvt.h"
#include "flash_mtd_sf_dal.h"
#include "flash_mtd_sf_ut.h"
#else
#include "kal_general_types.h"
#include "kal_public_defs.h"
#include "kal_public_api.h"
#include "kal_debug.h"
#include "flash_mtd_internal.h"
#include "flash_sf.h"
#include "flash_mtd_sf_dal.h"
#include "flash_mtd_sf_ut.h"
#include "DrvFlash.h"
#include "fs_type.h"
#include "sfi_hw.h"
#include "reg_base.h"
#include "l1_interface.h"
#include "fs_errcode.h"
#include "nor_profile.h"
#include "combo_flash_init.h"
#include "us_timer.h"
#endif



#ifdef SF_DAL_ALL
    #define SF_DAL_SST
    #define SF_DAL_MXIC
    #define SF_DAL_EON
    #define SF_DAL_WINBOND
    #define SF_DAL_GIGADEVICE
    #define SF_DAL_NUMONYX
#endif

//-----------------------------------------------------------------------------
// [DAL] Instantiation Function
//-----------------------------------------------------------------------------
// (None)

//-----------------------------------------------------------------------------
// [DAL] Init functions
//-----------------------------------------------------------------------------
kal_int32 SF_DAL_Init_Common(NOR_MTD_Driver *driver, SF_MTD_Data *D);       // Caller: SF_DAL_Init_Vendor()
kal_int32 SF_DAL_Init_Vendor(NOR_MTD_Driver *driver, SF_MTD_Data *D);       // Caller: SF_DAL_Init_Vendor()
kal_int32 SF_DAL_Init_SST(NOR_MTD_Driver *driver, SF_MTD_Data *D);          // Caller: SF_DAL_Init_Vendor()
kal_int32 SF_DAL_Init_MXIC(NOR_MTD_Driver *driver, SF_MTD_Data *D);         // Caller: SF_DAL_Init_Vendor()
kal_int32 SF_DAL_Init_EON(NOR_MTD_Driver *driver, SF_MTD_Data *D);          // Caller: SF_DAL_Init_Vendor()
kal_int32 SF_DAL_Init_WINBOND(NOR_MTD_Driver *driver, SF_MTD_Data *D);      // Caller: SF_DAL_Init_Vendor(), SF_DAL_Init_GIGADEVICE()
kal_int32 SF_DAL_Init_WINBOND_OTP(NOR_MTD_Driver *driver, SF_MTD_Data *D);  // Caller: SF_DAL_Init_Vendor()
kal_int32 SF_DAL_Init_GIGADEVICE(NOR_MTD_Driver *driver, SF_MTD_Data *D);   // Caller: SF_DAL_Init_Vendor()

//-----------------------------------------------------------------------------
// [DAL] Lower Abstract
//-----------------------------------------------------------------------------
int SF_DAL_UnlockBlock_None(void *MTDData) { return FS_NO_ERROR; }
int SF_DAL_UnlockBlock_SST(void *MTDData);   // Caller: SF_DAL_IOCtrl()
int SF_DAL_UnlockBlock_MXIC(void *MTDData);  // Caller: SF_DAL_IOCtrl()
int SF_DAL_OTPRead_MXIC(void *MTDData, kal_uint32 Offset, void * BufferPtr, kal_uint32 Length);
int SF_DAL_OTPWrite_MXIC(void *MTDData, kal_uint32 Offset, void * BufferPtr, kal_uint32 Length);
int SF_DAL_OTPLock_MXIC(void *MTDData);
int SF_DAL_FailCheck(void *MTDData);
int SF_DAL_OTPRead_WINBOND(void *MTDData, kal_uint32 Offset, void * BufferPtr, kal_uint32 Length);
int SF_DAL_OTPWrite_WINBOND(void *MTDData, kal_uint32 Offset, void * BufferPtr, kal_uint32 Length);
int SF_DAL_OTPLock_WINBOND(void *MTDData);
int SF_DAL_OTPRead_SST(void *MTDData, kal_uint32 Offset, void * BufferPtr, kal_uint32 Length);
int SF_DAL_OTPWrite_SST(void *MTDData, kal_uint32 Offset, void * BufferPtr, kal_uint32 Length);
int SF_DAL_OTPLock_SST(void *MTDData);

//-----------------------------------------------------------------------------
// [DAL] Device Driver Componets (Interface to lower driver or physical device)
//-----------------------------------------------------------------------------
void SF_DAL_Dev_EraseBlock(SF_MTD_Data *D, kal_uint32 addr);
void SF_DAL_Dev_ReadID(SF_MTD_Data *D, kal_uint8 *id);
void SF_DAL_Dev_WriteEnable(SF_MTD_Data *D);
void SF_DAL_Dev_Resume(SF_MTD_Data *D);
void SF_DAL_Dev_Suspend(SF_MTD_Data *D);
kal_uint32 SF_DAL_Dev_ReadStatus(SF_MTD_Data *D, kal_uint8 cmd);
void SF_DAL_Dev_Command(SF_MTD_Data *D, const kal_uint32 cmd, kal_uint8 outlen);
void SF_DAL_Dev_Command_Ext(kal_uint8 *cmd, kal_uint8 *data, const kal_uint16 outl, const kal_uint16 inl);
void SF_DAL_Dev_CommandAddress(SF_MTD_Data *D, const kal_uint32 cmd, const kal_uint32 address);

//-----------------------------------------------------------------------------
// [DAL] System Init Stage Functions
//-----------------------------------------------------------------------------
void SF_DAL_Dev_WaitReady_EMIINIT(SF_MTD_Data *D);

//
// Note: Following functions do not have dev lock
//       SF_DAL_CheckDeviceReady()
//       SF_DAL_CheckReadyAndResume()
//       Flash_ReturnReady()
//

//-----------------------------------------------------------------------------
// External Functions
//-----------------------------------------------------------------------------
extern kal_uint32 EMIINIT_CMEM_NOR_GetUniformBlock(void);
extern void DelayAWhile_UST(kal_uint32 delay);  // defined in flash_mtd.c
extern kal_bool   INT_QueryExceptionStatus(void);
extern kal_bool CMEM_EMIINIT_CheckValidDeviceID(kal_uint8 *id);
extern kal_bool CMEM_CheckValidDeviceID(kal_uint8 *id);


//-----------------------------------------------------------------------------
// External Variables
//-----------------------------------------------------------------------------
extern kal_uint32          PAGE_BUFFER_SIZE;       // (custom_flash.c)
extern kal_bool            NOR_FLASH_BUSY;         // (flash_mtd.c) hould be modified only when I-bit is disabled
extern kal_bool            NOR_FLASH_SUSPENDED;    // (flash_mtd.c) should be modified only when I-bit is disabled
extern kal_uint32          gNOR_ReturnReadyBegin;  // (flash_mtd.c)
extern kal_uint32          gNOR_ReturnReadyEnd;    // (flash_mtd.c)
extern kal_bool            DelayResume;    // (Flash_mtd_sf_common.c) should be modified only when I-bit is disabled
extern kal_uint32          Image$$ROM$$Base;

#if !defined(__FUE__)
#if (defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__))
extern NOR_FLASH_DRV_Data  FlashDriveData;         // (custom_flash.c)
#endif
#if defined(__FOTA_DM__)
   extern kal_bool            FOTA_Flash_busy;
   extern NOR_FLASH_DRV_Data  NORFlashDriveData;
#endif   /* __FOTA_DM__ */
#endif // __FUE__

//-----------------------------------------------------------------------------
// Internal Macros
//-----------------------------------------------------------------------------

// Vendor Fix
//----------------------------------
kal_uint32 sf_dal_fix=0;

typedef enum {
    sf_fix_winbond_cv   =0x00000001,
    sf_fix_winbond_dw   =0x00000002,
    sf_fix_mxic_35e     =0x00000004,
    sf_fix_fidelix_q32a =0x00000008,
    sf_fix_gigadevice_b =0x00000010
} Enum_SF_FIX;

#ifdef __MTK_INTERNAL__
/* under construction !*/
#endif
#define SF_FIX_WINBOND_DW
#define SF_FIX_MXIC_35E
#define SF_FIX_GIGADEVICE_B

#if defined(SF_DAL_WINBOND) && defined(SF_FIX_WINBOND_CV)
kal_uint8 sf_fix_winbond_cv_resumed=1;

#define FIX_WINBOND_CV() do { \
    if (sf_dal_fix & sf_fix_winbond_cv) { \
        kal_uint32 savedMask; \
        ust_busy_wait(23); \
        savedMask = SaveAndSetIRQMask(); \
        if (sf_fix_winbond_cv_resumed==0)   { \
            SFI_Dev_Command(SF_CMD_WINBOND_RESUME); \
            sf_fix_winbond_cv_resumed=1; \
        } \
        RestoreIRQMask(savedMask); \
    } } while(0)

#else
#define FIX_WINBOND_CV()
#endif

// Busy wait
//----------------------------------
#if ( (defined(MT6258) || defined(MT6252) || defined(MT6255) || defined(MT6280)) )
#define SF_BR_BUSY_WAIT
#endif
kal_bool sf_dal_brbusy_wait=KAL_FALSE;

typedef enum {
    SF_256MS = 0x8000,
    SF_512MS = 0x9000,
    SF_1S    = 0xA000,
    SF_2S    = 0xB000,
    SF_4S    = 0xC000,
    SF_8S    = 0xD000,
    SF_16S   = 0xE000,
    SF_32S   = 0xF000,
    SF_BUSY  = 0x0001,
    SF_SUS   = 0x0002
} Enum_SF_NVReg;

#if (defined(SF_BR_BUSY_WAIT))
    #if ( (defined(MT6258) || defined(MT6252)) )
    #define SF_NVREG ((volatile kal_uint32*)(MIXED_base+0x0A28))
	#elif ( defined(MT6255) || defined(MT6280) )
	#define SF_NVREG ((volatile kal_uint32*)(SFI_base + 0x0018))
    #else
    #error "SF_NVREG was not defined"
    #endif
#endif

#ifdef SF_BR_BUSY_WAIT
#define SF_DAL_NVREG_BUSY_SET()  { SFI_WriteReg32(SF_NVREG, ((*SF_NVREG) |  SF_BUSY)); }
#define SF_DAL_NVREG_BUSY_CLR()  { SFI_WriteReg32(SF_NVREG, ((*SF_NVREG) & ~SF_BUSY)); }
#define SF_DAL_NVREG_SUS_SET()   { SFI_WriteReg32(SF_NVREG, ((*SF_NVREG) |  SF_SUS)); }
#define SF_DAL_NVREG_SUS_CLR()   { SFI_WriteReg32(SF_NVREG, ((*SF_NVREG) & ~SF_SUS)); }
#define SF_DAL_NVREG_SUS()       ( ((*SF_NVREG) & SF_SUS)!=0)
#define SF_DAL_NVREG_BUSY()      ( ((*SF_NVREG) & SF_BUSY)!=0)
#else
#define SF_DAL_NVREG_BUSY_SET()  {}
#define SF_DAL_NVREG_BUSY_CLR()  {}
#define SF_DAL_NVREG_SUS_SET()   {}
#define SF_DAL_NVREG_SUS_CLR()   {}
#define SF_DAL_NVREG_SUS()       (0)
#define SF_DAL_NVREG_BUSY()      (0)
#endif  // SF_BR_BUSY_WAIT

#define SF_DAL_FLAG_BUSY_SET()  { if (sf_dal_brbusy_wait) { SF_DAL_NVREG_BUSY_SET(); } NOR_FLASH_BUSY = KAL_TRUE; }
#define SF_DAL_FLAG_BUSY_CLR()  { if (sf_dal_brbusy_wait) { SF_DAL_NVREG_BUSY_CLR(); } NOR_FLASH_BUSY = KAL_FALSE; SFI_MaskAhbChannel(0);}
#define SF_DAL_FLAG_BUSY()      (NOR_FLASH_BUSY)
#define SF_DAL_FLAG_SUS_SET()   { if (sf_dal_brbusy_wait) { SF_DAL_NVREG_SUS_SET(); } NOR_FLASH_SUSPENDED = KAL_TRUE; SFI_MaskAhbChannel(0);}
#define SF_DAL_FLAG_SUS_CLR()   { if (sf_dal_brbusy_wait) { SF_DAL_NVREG_SUS_CLR(); } NOR_FLASH_SUSPENDED = KAL_FALSE; }
#define SF_DAL_FLAG_SUS()       (NOR_FLASH_SUSPENDED)

// Debug Macros
//----------------------------------
#if defined(__SF_DVT__)
#define SF_DAL_GetCurrentTime(...)  gpt4_get_current_tick()
#define SF_DAL_GetTimeDiff(s, e)    gpt4_get_duration_tick(s, e)
#define US32K(a)                    gpt4_tick2time_us(a)
#define USQCNT(a)                   gpt4_tick2time_us(a)
#define QBIT(a)                     gpt4_tick2time_us(a)
#else
#define SF_DAL_GetTimeDiff(s, e)    NOR_PROFILE_TIME_DIFF(s, e)
#if defined(MT6250)
#define SF_DAL_GetCurrentTime(...)  (*(volatile kal_uint32*)(MCU_TOPSM_base+0x104))
#elif defined(MT6280)
#define BASIC_TOPSM_base (0x80030000)
#define SF_DAL_GetCurrentTime(...)  (*(volatile kal_uint32*)(BASIC_TOPSM_base+0x104))
#else
#define SF_DAL_GetCurrentTime(...)  (*(volatile kal_uint32*)(TDMA_base+0x230))
#endif //defined(MT6250)
#define US32K(a) ((125*(a))>>2)     // 32KHz tick to us
#define USQCNT(a) (((a)*946)>>10)   // qbit to us
#define QBIT(a)                     (a)
#endif

//-----------------------------------------------------------------------------
// Internal Variables
//-----------------------------------------------------------------------------
kal_uint32 sf_dal_resume_time=NOR_DEFAULT_RESUME_TIME;
kal_uint32 sf_dal_flash_return_ready_max=0;

//-----------------------------------------------------------------------------
// Internal Functions
//-----------------------------------------------------------------------------
__sf_section_RAM kal_int32 sfi_60qbit_test(void)  {  return 0; }

//-----------------------------------------------------------------------------
// Basic Load Test Functions
//-----------------------------------------------------------------------------

// Interrupt Test
//----------------------------------
#if defined(SF_DEBUG)
#define LISR_Insert SFUT_LISRInsert
#define IntTrigger  SFUT_IntTrigger
#else
#define LISR_Insert(...)
#define IntTrigger(...)
#endif

// Interrupt Trigger Macros: Basic Load
//----------------------------------
#if defined(__BASIC_LOAD_FLASH_TEST__)
//extern void EraseDisturbCheck(NOR_FLASH_DRV_Data * D, kal_uint32 Block, kal_uint32 Range, kal_uint32 stage);
#define NORTEST_GetCurrentTime SF_DAL_GetCurrentTime
void NORTEST_Reset(void);
extern kal_uint8 RandomNum;
extern kal_uint32 ProgramNum, EraseNum;
extern kal_uint8 PLTestOption;	// 0: Random reset    1: reset only in flash busy time.
extern kal_uint32 ResetTimeout;

#define IntTest(Num) \
	{\
		if (RandomNum == Num) {\
			if (PLTestOption==0) { \
				RandomNum = (RandomNum+1) % 5;\
				IntTrigger();\
			} else { \
				if (ResetTimeout==0) {\
					if (RandomNum & 0x01) { \
						NORTEST_Reset();\
					} else { \
						IntTrigger();\
					} \
				} else {\
					ResetTimeout--; \
					RandomNum = (RandomNum+1) % 5;\
					IntTrigger(); \
				}\
			}\
		}\
		else { \
            SFUT_IntTest(IntTrigger); \
        } \
	}

// Interrupt Trigger Macros: FOTA Update Engine
//---------------------------------------------
#elif defined(__FUE_STRESS_TEST__) && defined(__FUE__)
#include "fue_init.h"

extern void NORTEST_Delay_us(kal_uint32 count);
extern void NORTEST_Delay_30us(kal_uint32 count);
extern void NORTEST_Reset(void);
extern kal_uint8 RandomNum;
extern kal_uint8 PLTestOption;

#define triggerTestIRQ()

#define IntTest(Num) \
	{\
		kal_uint32 val = rand();\
		val += (*(volatile kal_uint32*)(COUNTER_32K))^(*(volatile kal_uint16 *)(TDMA_base + 0x00));\
		if (3 == Num) {\
			if (PLTestOption==0) { \
				if( (RandomNum & 0x7) == 3)\
					triggerTestIRQ();\
			} else { \
				if ( (RandomNum & 0xF) == 7) {\
					val %= 2100;\
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
					val %= 1500000;\
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

// Interrupt Trigger Macros: SF_DEBUG
//---------------------------------------------
#elif defined(SF_DEBUG)
    #define IntTest(...)  SFUT_IntTest(SFUT_IntTrigger);
#else
    #define IntTest(...)
#endif   // __NOR_FLASH_HARDWARE_TEST__ && __MAUI_BASIC__


//-----------------------------------------------------------------------------
// Serial Flash Debug Facilities
//-----------------------------------------------------------------------------

// Debug Message
//----------------------------------
#if (((defined(IC_MODULE_TEST) || defined(IC_BURNIN_TEST))) && !defined(__UBL__))
extern void module_test_print(char *fmt,...);
extern kal_bool sfut_result;
#undef dbg_print
#undef ASSERT
#undef MTD_ASSERT
#define ASSERT(expr)  do { if(!(expr)) { sfut_result=KAL_FALSE; } } while(0)
#define MTD_ASSERT(expr, e1, e2, e3, code)  do { if(!(expr)) { sfut_result=KAL_FALSE; } } while(0)
#define dbg_print module_test_print
#endif

#if (defined(__BASIC_LOAD_FLASH_TEST__) && !defined(__SERIAL_FLASH_MEMORY_SLT__))
    #include "DrvFlash_UT.h"
    extern void dbg_print(char *fmt,...);
    extern kal_uint8 FDM_UT_Item;        // defined in flash_mtd.c
    extern kal_uint8 NORProfileProcess;  // defined in nor_profile.c
    extern char text[100];               // defined in nor_test.c
    #define SF_DAL_DEBUG(...) if (FDM_UT_Item!=NOR_FDM_UT_PROFILING && NORProfileProcess==0)  do{\
            kal_sprintf((char *)(&text[0]), ##__VA_ARGS__);\
            dbg_print((char *)(&text[0]));\
    } while(0)
    #if (defined(__NORTEST_MULTI_USER__) && defined(DEBUG_KAL))
        #define SF_DAL_DEBUG_MULTI_USER  SF_DAL_DEBUG
    #else
        #define SF_DAL_DEBUG_MULTI_USER(...) {}
    #endif
#elif defined(SF_DEBUG) && defined(SFUT_DEBUG_LOG)
    extern void dbg_print(char *fmt,...);
    extern char text[100];  // defined in flash_mtd_sf_ut.c
    #define SF_DAL_DEBUG(...) do{\
        kal_sprintf((char *)(&text[0]), ##__VA_ARGS__);\
        dbg_print((char *)(&text[0]));\
    } while(0)
    #define SF_DAL_DEBUG_MULTI_USER(...) {}
#else
    #define SF_DAL_DEBUG(...) {}
    #define SF_DAL_DEBUG_MULTI_USER(...) {}
#endif


/* Debug Options
SF_DAL_CODE_REGION_CHECK (deafult on)
    - Description
        o Check code area after erase done
    - Purpose
        o To detect erase-hang after failed erase operation.
SF_DAL_ERASE_STATISTICS (default on)
    - Description
        o Enable erase-timer, suspend timer and erase-suspend counter.
    - Purpose
        o To get basic time statistics of erase operations (for erase fail analysis).
SF_DAL_PROG_STATISTICS (default on)
    - Description
        o Enable program-timer, suspend timer and program-suspend counter.
    - Purpose
        o To get basic time statistics of program operations (for program fail analysis).
SF_DAL_TIMESTAMP (default off)
    - Description
        o Enable time stamp log in erase /program
    - Purpose
        o Acquire suspend / resume time statistics for erase / program fail analysis.
SF_DAL_SUSPEND_CHECK  (default on)
    - Description
        o Enable suspend-to-ready time check in FlashRetrunReady()
    - Purpose
        o Check if the device suspend-to-ready latency violates the L1 timing constrains.
*/

// Presets
//----------------------------------
#if !defined(__UBL__)
#if defined(__SERIAL_FLASH_MEMORY_SLT__)
    #define SF_DAL_CODE_REGION_CHECK
    #define SF_DAL_SUSPEND_CHECK
    #define SF_DAL_PROG_STATISTICS
    #define SF_DAL_SUSPEND_STATISTICS
    #define SF_DAL_ERASE_STATISTICS
#elif defined(__BASIC_LOAD_FLASH_TEST__)
    #define SF_DAL_CODE_REGION_CHECK
    #define SF_DAL_TIMESTAMP
    #define SF_DAL_SUSPEND_CHECK
    #define SF_DAL_PROG_STATISTICS
    #define SF_DAL_SUSPEND_STATISTICS
    #define SF_DAL_ERASE_STATISTICS
#else
  // MAUI load and SF_DEBUG is defined
  #if defined(SF_DEBUG)
    #define SF_DAL_CODE_REGION_CHECK
    #define SF_DAL_TIMESTAMP
    #define SF_DAL_SUSPEND_CHECK
    #define SF_DAL_SUSPEND_STATISTICS
    #define SF_DAL_PROG_STATISTICS
    #define SF_DAL_ERASE_STATISTICS
  #else
  #endif
#endif
#endif


// Fail Beacons for LA
#define LA_PROGFAIL    0x33
#define LA_ERASEFAIL   0x33
#define LA_SUSPENDFAIL 0x33
#define LA_CODECORRUPT 0x33

// Code Region Check
//----------------------------------
#ifdef SF_DAL_CODE_REGION_CHECK
#define NORGuard1 (*(volatile kal_uint32*)(&Image$$ROM$$Base))
#define NORGuard2 (*(volatile kal_uint32*)(&Image$$ROM$$Base+0xFC))
kal_uint32 NORGuardPattern1;
kal_uint32 NORGuardPattern2;
#endif

// Suspend Fail Check
//----------------------------------
#ifdef SF_DAL_SUSPEND_CHECK
#if defined (__SF_DVT__)
#define SF_READY_LIMIT 1000
#else
#define SF_READY_LIMIT 150
#endif
// Suspend to Ready time
kal_uint32 sf_dal_suspend_ready_start_time=0;          //Qbits timer to check suspend to ready time
kal_uint32 sf_dal_suspend_ready_end_time=0;            //Qbits timer to check suspend to ready time
kal_uint32 sf_dal_suspend_ready_start_time_32kTimer=0; //32K Timer to check suspend to ready time
kal_uint32 sf_dal_suspend_ready_end_time_32kTimer=0;   //32K Timer to check suspend to ready time

kal_uint32 sf_dal_suspend_ready_time=0;                //Qbits timer to check suspend to ready time
kal_uint32 sf_dal_suspend_ready_time_32kTimer=0;       //32K Timer to check suspend to ready tim
kal_uint32 sf_dal_suspend_ready_time_max=0;
kal_uint32 sf_dal_suspend_fail_count;
// Polling ready state time
kal_uint32 sf_dal_polling_start_time;
kal_uint32 sf_dal_polling_stage_start_time;
kal_uint32 sf_dal_polling_end_time;
kal_uint32 sf_dal_polling_time_max=0;
kal_uint32 sf_dal_polling_time_stage_max=0;
kal_uint32 sf_dal_polling_count;
kal_uint32 sf_dal_polling_count_max=0;
#endif

// Erase Suspend Time Stamp
//----------------------------------
#ifdef SF_DAL_TIMESTAMP

#define TIME_STAMPS 256
typedef enum {
    TIME_STAMP_NONE=0,
    TIME_STAMP_SUSPEND=1,
    TIME_STAMP_RESUME=2
} sf_dal_time_stamp_type;

#define TIME_STAMP_GUARD 0xDEADDEAD

kal_uint32 timestamp[TIME_STAMPS];
sf_dal_time_stamp_type timestamp_type[TIME_STAMPS];
kal_int16  timestamp_ptr = -1;
kal_uint8 *stamp_prefix[3]={"Undef","S","R"};

// Stop logging time stamps
#define TimeStampStop()  { timestamp_ptr=-1; }
#define TimeStampStart() { timestamp_ptr=0;  }

// Add current time to time stamp queue.
// Skips, if time stamp is disabled (timestamp_ptr<0).
#define TimeStampSet(type) do   {   \
    if ((timestamp_ptr>=0)&&(timestamp_ptr<(TIME_STAMPS-1)))  {  \
    timestamp[timestamp_ptr]=(D->DriverStatus!=SFDRV_PROGRAMMING)?(SF_DAL_GetCurrentTime()):(ust_get_current_time()); \
    timestamp_type[timestamp_ptr]=type; \
    timestamp_ptr++;  }  \
} while(0)

// Clean up time stamp queue
#define TimeStampClear()  do  {   \
    kal_uint16 i; \
    for (i=0; i<TIME_STAMPS; timestamp[i]=0, timestamp_type[i]=TIME_STAMP_NONE, i++); \
    timestamp[TIME_STAMPS-1]=TIME_STAMP_GUARD;   \
    timestamp_ptr=-1; \
} while(0)

// Simple version of dump time stamp
#define TimeStampDumpErase() TimeStampDump(EraseTime_Start, stamp_prefix, SFDRV_ERASING)
#define TimeStampDumpProg()  TimeStampDump(ProgTime_Start, stamp_prefix, SFDRV_PROGRAMMING)

// Sequentially dump all time stamps from queue
__sf_section_RAM void TimeStampDump(kal_uint32 base, kal_uint8 **str, kal_uint8 type)
{
    kal_uint8 i;
    kal_uint32 diff;

    if (type!=SFDRV_PROGRAMMING)    {
        for (i=0; timestamp[i]!=0 && i<(TIME_STAMPS-1) ;i++)   {
            diff=SF_DAL_GetTimeDiff(base, timestamp[i]);
            SF_DAL_DEBUG("%s: %dus %s",
                str[timestamp_type[i]],
                US32K(diff),
                (timestamp_type[i+1]==TIME_STAMP_RESUME)?"":"\r\n");
        }
    }
    else    {
        for (i=0; timestamp[i]!=0 && i<(TIME_STAMPS-1) ;i++)   {
            diff=ust_get_duration(base, timestamp[i]);
            SF_DAL_DEBUG("%s: %dus %s",
                str[timestamp_type[i]],
                USQCNT(diff),
                (timestamp_type[i+1]==TIME_STAMP_RESUME)?"":"\r\n");
        }
    }

    if (timestamp_ptr==TIME_STAMPS-1) {
        SF_DAL_DEBUG("TimeStampFull\r\n");
    }
    if (timestamp[TIME_STAMPS-1]!=TIME_STAMP_GUARD) {
        SF_DAL_DEBUG("TimeStampCorrupt\r\n");
    }
    return;
}
#else
#define TimeStampDumpErase(...)
#define TimeStampDumpProg(...)
#define TimeStampStop()
#define TimeStampStart()
#define TimeStampClear()
#define TimeStampSet(...)
#define TimeStampDump(...)
#endif // SF_DAL_TIMESTAMP

// Suspend Time Statistics
//----------------------------------
#if defined(SF_DAL_SUSPEND_STATISTICS) || defined(SF_DAL_ERASE_STATISTICS)
//Common time stamps (32KHz/us counter)
kal_uint32 SuspendTime_Start;
kal_uint32 SuspendTime_End;
kal_uint32 SuspendTotal;
kal_uint32 SuspendCounter;

#define SF_Suspend_Init() do { SuspendCounter=SuspendTotal=0; } while (0)

#define SF_Suspend_Start() do {   \
    SuspendTime_Start = (D->DriverStatus==SFDRV_PROGRAMMING)?(ust_get_current_time()):(SF_DAL_GetCurrentTime()); \
    TimeStampSet(TIME_STAMP_SUSPEND); \
} while(0)

#define SF_Suspend_End() do {   \
    SuspendTime_End = (D->DriverStatus==SFDRV_PROGRAMMING)?(ust_get_current_time()):(SF_DAL_GetCurrentTime()); \
    TimeStampSet(TIME_STAMP_RESUME); \
    if (D->DriverStatus==SFDRV_PROGRAMMING) { \
        SuspendTotal    += ust_get_duration(SuspendTime_Start, SuspendTime_End); \
    }  \
    else { \
        SuspendTotal    += SF_DAL_GetTimeDiff(SuspendTime_Start, SuspendTime_End); \
    } \
} while(0)

#define SF_Suspend_Count() { \
    SuspendCounter++; \
}
#else
#define SF_Suspend_Init()
#define SF_Suspend_Start()
#define SF_Suspend_End()
#define SF_Suspend_Count()
#endif  // SF_DAL_SUSPEND_STATISTICS || SF_DAL_ERASE_STATISTICS

// Program Time Statistics
//----------------------------------
#ifdef SF_DAL_PROG_STATISTICS
//Program using us conter (4.7*2ms)
kal_uint32 ProgTime_Start;
kal_uint32 ProgTime_End;
kal_uint32 ProgTotal;
kal_uint32 ProgTotalMax=0;
kal_uint32 ProgTotalOverall=0;
kal_uint32 ProgTotalCount=0;

#define SF_PROG_TIME_LIMIT 3000  // Program Time Limit: 3 ms

#define SF_Prog_Init() do { \
    TimeStampStart(); SF_Suspend_Init(); \
    ProgTotal=0; \
} while(0)

#define SF_Prog_Start() do { \
    ProgTime_Start = ust_get_current_time(); \
} while(0)

#define SF_Prog_End() do { \
    ProgTime_End=ust_get_current_time(); \
    ProgTotal  +=ust_get_duration(ProgTime_Start, ProgTime_End); \
} while(0)
#else
#define SF_Prog_Init()
#define SF_Prog_Start()
#define SF_Prog_End()
#endif

// Erase Time Statistics
//----------------------------------
#ifdef SF_DAL_ERASE_STATISTICS
//Erase using 32KHz timer
kal_uint32 EraseTime_Start;
kal_uint32 EraseTime_End;
kal_uint32 EraseTotal;
kal_uint32 EraseSuspendFailTimeStamp;

#define SF_ERASE_TIME_LIMIT 2000000  // Erase Time Limit: 2 seconds

#define SF_Erase_Start()  do {  \
    TimeStampStart(); \
    EraseSuspendFailTimeStamp=0; SF_Suspend_Init(); \
    EraseTotal=0; \
    EraseTime_Start = SF_DAL_GetCurrentTime(); \
} while(0)

#define SF_Erase_End()  do {   \
    EraseTime_End = SF_DAL_GetCurrentTime(); \
    EraseTotal   += SF_DAL_GetTimeDiff(EraseTime_Start, EraseTime_End); \
} while(0)
#else
#define SF_Erase_Start()
#define SF_Erase_End()
#endif

// SF_DEBUG
//----------------------------------
#if defined(SF_DEBUG)

// Local Variables
kal_uint32 ProgRBLen;

// Fail Mark
//----------------------------------
__sf_section_RAM void SF_DAL_FailMark(SF_MTD_Data *D)
{
    kal_uint32 val=0;
    Flash_ProgramData((kal_uint8*)(D->BaseAddr-512), (kal_uint8*)(&val), 4);
}

// Blank Check
//----------------------------------
__sf_section_RAM void SF_DAL_BlankCheck(SF_MTD_Data *D, kal_uint8 *address, kal_uint32 length)
{
  kal_uint32 i;
  kal_uint32 val;
  kal_uint32 result=0;

  for (i=0 ; i<length; i++) {
    val=address[i];
    if (val!=0xFF)  {
      SF_DAL_Dev_Command(D, LA_ERASEFAIL, 1);
      SF_DAL_DEBUG("Blank Check Failed @ %08X = %02X, ", (kal_uint32)&address[i], val);
      result++;
    }
  }
  if (result!=0)  {
    SF_DAL_DEBUG("\r\n");
    TimeStampDumpErase();
    SF_DAL_FailMark(D);
    MTD_ASSERT(0, 0, 0, 0, NOR_MTD_ERASE_FAIL);
  }
  return;
}

// Memory Dump
//----------------------------------
__sf_section_RAM void SF_DAL_MemDump(SF_MTD_Data *D, kal_uint8 *address, kal_uint32 length)
{
    kal_uint32 i,j,k;

    for (i=0;i<length;)  {
        SF_DAL_DEBUG("%08X: ", (kal_uint32)(&address[i]));
        for (j=0;j<16&&i<length;j+=4)   {
            for (k=0;k<4&&i<length;k++,i++)   {
                SF_DAL_DEBUG("%02X",address[i]);
            }
            SF_DAL_DEBUG(" ");
        }
        SF_DAL_DEBUG("\r\n");
    }
}

#endif // SF_DEBUG
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Exported Global Functions
//-----------------------------------------------------------------------------
#if !defined(__FUE__) && !defined(__UBL__)
//-----------------------------------------------------------------------------
/*!
  @brief

   Data Compare

  @param[in] Address Pointer to the physical address that to be compared
  @param[in] Data Pointer to the data buffer
  @param[in] Size The length of data to be compared
*/

__sf_section_RAM kal_bool CompareData(void * Address, void * Data, kal_uint32 Length)
{
    kal_uint32 i;

    if((kal_uint32)Address&0x3==0 && (kal_uint32)Data&0x3==0)
    {
       kal_uint32* Source = (kal_uint32*)Address;
       kal_uint32* Dest = (kal_uint32*)Data;
       for(i=0;i<(Length>>2);i++)
       {
          if(Source[i] != Dest[i])
          	 return KAL_TRUE;
       }
    }
    else if((kal_uint32)Address&0x1==0 && (kal_uint32)Data&0x1==0)
    {
       kal_uint16* Source = (kal_uint16*)Address;
       kal_uint16* Dest = (kal_uint16*)Data;
       for(i=0;i<(Length>>1);i++)
       {
          if(Source[i] != Dest[i])
          	 return KAL_TRUE;
       }
    }
    else
    {
       kal_uint8* Source = (kal_uint8*)Address;
       kal_uint8* Dest = (kal_uint8*)Data;
       for(i=0;i<Length;i++)
       {
          if(Source[i] != Dest[i])
          	 return KAL_TRUE;
       }
    }
    return KAL_FALSE;
}

//-----------------------------------------------------------------------------
/*!
  @brief

    Program in sleep mode

  @param[in] Target Pointer to the physical address that to be programmed
  @param[in] Data Pointer to the data buffer
  @param[in] Size The length of data to be programmed

  @remarks
    Only called by SuspendEraseQueue() in sleep mode
    The maximum GPRAM utilization is 1+3+256B. A device lock is required.
*/
#if defined(__ERASE_QUEUE_ENABLE__) || defined(SF_DEBUG)
__sf_section_RAM void Flash_ProgramData(void *Target, void *Data, kal_uint32 Size)
{
    SF_MTD_Data    *D = (SF_MTD_Data *)FlashDriveData.MTDData;
    kal_uint32      address = (kal_uint32)Target;
    kal_uint8      *p_data  = Data;
    kal_uint32      cmd1 = 0, length, written;
    SF_Status       status;
    kal_uint32      savedMask;

    SF_DAL_GetDevLock(D);
    D->DriverStatus=SFDRV_PROGRAMMING;

    while (0!=Size) {
        // step1. length = calculate the offset to the page boundary
        length = PAGE_BUFFER_SIZE*2 - (address & (PAGE_BUFFER_SIZE*2 - 1));

        // stpe2. If program Length is greater than the offset to the page boundary
        length = written = ((Size > length) ? length : Size);

        if (!(sf_dal_fix & sf_fix_gigadevice_b))   {
            SF_DAL_Dev_WriteEnable(D);
        }

#if defined(__SFI_4BYTES_ADDRESS__)
        if (D->AddressCycle == 4)
        {
            cmd1=SFI_GPRAM_Write_C1A4(D->CMD->PageProg, address, &p_data, &length);
            SFI_GPRAM_Write(8, p_data, length);
        }
        else
#endif
        {
            cmd1=SFI_GPRAM_Write_C1A3(D->CMD->PageProg, address);
            SFI_GPRAM_Write(4, p_data, length);
        }

        savedMask=SaveAndSetIRQMask();
#if defined(SF_DAL_GIGADEVICE)
        if (sf_dal_fix & sf_fix_gigadevice_b)   {
            SFI_Dev_Command(D->CMD->WriteEnable);
        }
#endif
        SFI_WriteReg32(RW_SFI_MAC_OUTL, written + D->AddressCycle + 1);
        SFI_WriteReg32(RW_SFI_MAC_INL, 0);
        SFI_WriteReg32(RW_SFI_GPRAM_DATA, cmd1);
        SF_DAL_FLAG_BUSY_SET();
        SFI_MacEnable();
        SFI_MacWaitReady();
#if defined(SF_DAL_WINBOND) && defined(SF_FIX_WINBOND_CV)
        sf_fix_winbond_cv_resumed=0;
#endif
        RestoreIRQMask(savedMask);

#if defined(SF_DAL_WINBOND) && defined(SF_FIX_WINBOND_CV)
        FIX_WINBOND_CV();
#endif

        while (1)    {
            status = SF_DAL_Dev_ReadStatus(D, D->CMD->ReadReadyReg);
            if (0 == (status & D->StatusMap[SF_SR_BUSY]))
                break;
        }

#if defined(SF_DAL_GIGADEVICE)
        if (sf_dal_fix & sf_fix_gigadevice_b)
            SF_DAL_Dev_Command(D, SF_CMD_GIGADEVICE_HPM_ENTER_CMD, 4);
#endif

        SF_DAL_FLAG_BUSY_CLR();

        p_data += length;
        Size -= written;
        address += written;
    }

    D->DriverStatus=SFDRV_READY;
    SF_DAL_FreeDevLock(D);

    return;
}
#endif // __ERASE_QUEUE_ENABLE__

//-----------------------------------------------------------------------------
/*!
  @brief
    Wait until the deivce is ready
  @remarks
    !NOTE! The API should be invoked only when interrupt is disabled
    Since system calls are not allowed while I bit is disabled,
    the device lock is prohibted.
*/
__sf_section_RAM void Flash_ReturnReady(void)
{
    SF_MTD_Data         *D = NULL;
    SF_Status            status;

    gNOR_ReturnReadyBegin = ust_get_current_time(); // get start time of Flash_ReturnReady (Only when flash is busy)

    #if defined(__FOTA_DM__)
    if(FOTA_Flash_busy)
    {
        D = (SF_MTD_Data *)NORFlashDriveData.MTDData;
    }
    else
    #endif   /* __FOTA_DM__ */
    {
        D = (SF_MTD_Data *)FlashDriveData.MTDData;
    }

    ASSERT((~D->Signature == (kal_uint32)D->RegionInfo));

    // No Suspend Conditions
    // 1. For those deivces that do not support program-suspend (buffer length < 32 bytes).
    // 2. Serial Flash Unit Test: Erase/Program w/o suspend.
    // 3. NOR_NO_SUSPEND is defiend.
    if ( (PAGE_BUFFER_SIZE<16)&&(D->DriverStatus==SFDRV_PROGRAMMING)
#if defined(SF_DEBUG)
         || ((sfut_suspend_enable & SFUT_DISABLE_ERASE_SUSPEND)&&(D->DriverStatus==SFDRV_ERASING))
         || ((sfut_suspend_enable & SFUT_DISABLE_PROG_SUSPEND)&&(D->DriverStatus==SFDRV_PROGRAMMING))
#endif
#if defined(NOR_NO_SUSPEND)
         || (1)
#endif
        )  {
        while (1)   {
            status = SF_DAL_Dev_ReadStatus(D, D->CMD->ReadReadyReg);
            if (0 == (status & D->StatusMap[SF_SR_BUSY])) break;
        }
    }

    if ( (PAGE_BUFFER_SIZE<16)&&(D->DriverStatus==SFDRV_PROGRAMMING)) SF_Prog_End();

#if defined(SF_DAL_WINBOND) && defined(SF_FIX_WINBOND_CV)
    if (sf_dal_fix & sf_fix_winbond_cv) {
        ust_busy_wait(23);
        if (sf_fix_winbond_cv_resumed==0)   {
            SFI_Dev_Command(SF_CMD_WINBOND_RESUME);
            sf_fix_winbond_cv_resumed=1;
        }
        ust_busy_wait(23);
    }
#endif

    if((!SF_DAL_FLAG_SUS()) && SF_DAL_FLAG_BUSY())
    {
#ifdef SF_DAL_SUSPEND_CHECK
        SF_Status status_suspend;
        kal_uint32 time_stamp=0;
        sf_dal_polling_end_time=0;
        sf_dal_polling_count=0;
        sf_dal_suspend_ready_start_time = ust_get_current_time();
		sf_dal_suspend_ready_start_time_32kTimer = SF_DAL_GetCurrentTime();
#endif

        status = SF_DAL_Dev_ReadStatus(D, D->CMD->ReadReadyReg);

        // if flash is busy, suspend any on-going operations
        if (0 != (status & D->StatusMap[SF_SR_BUSY]))
        {
            // 1. Issue suspend command
#ifdef SF_DAL_SUSPEND_CHECK
            sf_dal_suspend_fail_count=0;
            time_stamp=SF_DAL_GetCurrentTime();
            sf_dal_polling_start_time=ust_get_current_time();
            sf_dal_polling_stage_start_time=sf_dal_polling_start_time;
#endif
            SF_DAL_Dev_Suspend(D);

            // 2. wait for device ready
            while (1)
            {
                status = SF_DAL_Dev_ReadStatus(D, D->CMD->ReadReadyReg);
                if (0 == (status & D->StatusMap[SF_SR_BUSY]))
                    break;

#ifdef SF_DAL_SUSPEND_CHECK
                status_suspend = SF_DAL_Dev_ReadStatus(D, D->CMD->ReadSuspendReg);
                sf_dal_polling_end_time=ust_get_current_time();
                sf_dal_polling_end_time=ust_get_duration(sf_dal_polling_stage_start_time, sf_dal_polling_end_time);
                // If the polling time is greater than SF_READY_LIMIT/2
                // 1. Check the suspend flag
                // 2. If SUS flag was not set, issue another suspend command
                if (QBIT(sf_dal_polling_end_time) > SF_READY_LIMIT/2)   {
                    if (sf_dal_polling_end_time > sf_dal_polling_time_stage_max) {
                        sf_dal_polling_time_stage_max=sf_dal_polling_end_time;
                    }
                    sf_dal_polling_count++;
                    if ((0 == (status_suspend & D->StatusMap[SF_SR_WSE])) &&
                        (0 == (status_suspend & D->StatusMap[SF_SR_WSP])) ) {
						SF_DAL_Dev_Command(D, LA_SUSPENDFAIL, 1);
                        sf_dal_suspend_fail_count++;
                        SF_DAL_Dev_Suspend(D);
                    }
                    sf_dal_polling_stage_start_time=ust_get_current_time();
                }
#endif
            }

#if defined(SF_DAL_MXIC) && defined(SF_FIX_MXIC_35E)
            // erase resume only
            if ((sf_dal_fix & sf_fix_mxic_35e)&&(D->DriverStatus==SFDRV_ERASING))  {
                // WREN
                SFI_WriteReg32(RW_SFI_GPRAM_DATA, 0x00000006);
                SFI_WriteReg32(RW_SFI_MAC_INL, 0);
                SFI_WriteReg32(RW_SFI_MAC_OUTL, 1); // 1B cmd
                SFI_MacEnable();
                SFI_MacWaitReady();

                // Program
                SFI_WriteReg32(RW_SFI_GPRAM_DATA+4, 0xFFFFFFFF);
                SFI_WriteReg32(RW_SFI_MAC_OUTL, 6); // 1B cmd, 3B adrr, 2B data
                SFI_WriteReg32(RW_SFI_GPRAM_DATA, 0x00000002);
                SFI_MacEnable();
                SFI_MacWaitReady();

                // Wait Ready
                do {
                  SFI_WriteReg32(RW_SFI_GPRAM_DATA, 0x00000005);
                  SFI_WriteReg32(RW_SFI_MAC_INL, 1);
                  SFI_WriteReg32(RW_SFI_MAC_OUTL, 1);
                  SFI_MacEnable();
                  SFI_MacWaitReady();
                  status = (SFI_ReadReg32(RW_SFI_GPRAM_DATA)>>8) & 1;
                } while(status);
            }
#endif

#ifdef SF_DAL_SUSPEND_CHECK
            sf_dal_polling_end_time=ust_get_current_time();
            sf_dal_polling_end_time=ust_get_duration(sf_dal_polling_start_time, sf_dal_polling_end_time);
#endif

            SF_DAL_FLAG_SUS_SET();
        }
        else
        {
#if defined(SF_DAL_WINBOND) && defined(SF_FIX_WINBOND_DW)
            if ((sf_dal_fix & sf_fix_winbond_dw)&&(D->DeviceLockOwner==KAL_NILTASK_ID))   {
                status=SF_DAL_Dev_ReadStatus(D, D->CMD->ReadSuspendReg);
                if ((0 == (status & D->StatusMap[SF_SR_WSE])) &&
                    (0 == (status & D->StatusMap[SF_SR_WSP])) ) {
                    SFI_Dev_Command(SF_CMD_WINBOND_RESUME);
                    SFI_Dev_Command(SF_CMD_WINBOND_RESUME);
                }
            }
#endif
            SF_DAL_FLAG_BUSY_CLR();
        }
#ifdef SF_DAL_SUSPEND_CHECK
        sf_dal_suspend_ready_end_time = ust_get_current_time();
		sf_dal_suspend_ready_end_time_32kTimer = SF_DAL_GetCurrentTime();
		sf_dal_suspend_ready_time_32kTimer = SF_DAL_GetTimeDiff(sf_dal_suspend_ready_start_time_32kTimer,sf_dal_suspend_ready_end_time_32kTimer);
        sf_dal_suspend_ready_time = ust_get_duration(sf_dal_suspend_ready_start_time, sf_dal_suspend_ready_end_time);
        if (sf_dal_suspend_ready_time_max < sf_dal_suspend_ready_time)  {
            sf_dal_suspend_ready_time_max = sf_dal_suspend_ready_time;
            sf_dal_polling_time_max = sf_dal_polling_end_time;
            sf_dal_polling_count_max = sf_dal_polling_count;
            EraseSuspendFailTimeStamp =  SF_DAL_GetTimeDiff(EraseTime_Start, time_stamp);
        }
#endif
    }

#if defined(SF_DAL_GIGADEVICE)
    if (sf_dal_fix & sf_fix_gigadevice_b)
        SFI_Dev_Command(SF_CMD_GIGADEVICE_HPM_ENTER);
#endif

    gNOR_ReturnReadyEnd = ust_get_current_time();   // get end time of Flash_ReturnReady

    {
      kal_uint32 duration=ust_get_duration(gNOR_ReturnReadyBegin, gNOR_ReturnReadyEnd);
    	if (sf_dal_flash_return_ready_max < duration) {
    	   sf_dal_flash_return_ready_max = duration;
    	}
   	}
    /* If NOR_FLASH_SUSPENDED==NOR_FLASH_BUSY==TRUE, must unmask SFC AHB Channel 2 and 3 to make SF accessible to them. */
    SFI_MaskAhbChannel(0);

    return;
}

//-----------------------------------------------------------------------------
/*!
  @brief
    Check the device is ready
  @retval
    KAL_TRUE: Device is ready
    KAL_FALSE: Deivce is busy
  @remarks
    Only called by ProcessEraseQueue() in sleep mode
  @remarks
    GPRAM utilization is 1+1B. A device lock is not necessary for GPRAM.
*/
#if defined(__ERASE_QUEUE_ENABLE__)
__sf_section_RAM kal_bool Flash_CheckReady(void)
{
    SF_MTD_Data *D = (SF_MTD_Data*)FlashDriveData.MTDData;
    SF_Status    status;
    kal_bool     result  = KAL_FALSE;

    ASSERT((~D->Signature == (kal_uint32)D->RegionInfo));

    SF_DAL_GetDevLock(D);

    status = SF_DAL_Dev_ReadStatus(D, D->CMD->ReadReadyReg);

    if (0 == (status & D->StatusMap[SF_SR_BUSY]))
    {
        SF_DAL_FLAG_BUSY_CLR();
        result = KAL_TRUE;
    }

    SF_DAL_FreeDevLock(D);

   return result;
}
#endif  // __ERASE_QUEUE_ENABLE__

//-----------------------------------------------------------------------------
/*!
  @brief
    Resumes any suspended operations
  @remarks
    Only called by ProcessEraseQueue() in sleep mode
    GPRAM utilization is 1B. A device lock is not necessary.
*/
#if defined(__ERASE_QUEUE_ENABLE__)
__sf_section_RAM void Flash_ResumeOperation(void)
{
   SF_MTD_Data    *D = (SF_MTD_Data *)FlashDriveData.MTDData;

   MTD_SNOR_ASSERT(SF_DAL_FLAG_BUSY() && SF_DAL_FLAG_SUS() , SF_DAL_FLAG_BUSY(), SF_DAL_FLAG_SUS() , 0, NOR_MTD_ESB_BUSY_FLAG_MISMATCH);

   SF_DAL_Dev_Resume(D);
}
#endif // __ERASE_QUEUE_ENABLE__

//-----------------------------------------------------------------------------
/*!
  @brief
    Suspends any ongoing operations
  @remarks
    Only called by ProcessEraseQueue() in sleep mode
    GPRAM utilization is 1B. A device lock is not necessary.
*/
#if defined(__ERASE_QUEUE_ENABLE__)
__sf_section_RAM void Flash_SuspendOperation(void)
{
    SF_MTD_Data    *D = (SF_MTD_Data *)FlashDriveData.MTDData;
    SF_Status       status;

    MTD_SNOR_ASSERT(SF_DAL_FLAG_BUSY() && !(SF_DAL_FLAG_SUS() ), SF_DAL_FLAG_BUSY(), SF_DAL_FLAG_SUS() , 0, NOR_MTD_ESB_BUSY_FLAG_MISMATCH);

    ASSERT((~D->Signature == (kal_uint32)D->RegionInfo));

    SF_DAL_Dev_Suspend(D);

    while (1)
    {
        status = SF_DAL_Dev_ReadStatus(D, D->CMD->ReadReadyReg);

        if (0 == (status & D->StatusMap[SF_SR_BUSY]))
            break;
    }

    SF_DAL_FLAG_SUS_SET();
}
#endif // __ERASE_QUEUE_ENABLE__

#else // !(__FUE__) && !(__UBL__)

__sf_section_RAM void Flash_ReturnReady(void)
{
   return;
}

#endif // __UBL__

//-----------------------------------------------------------------------------
// [DAL] Process control
//-----------------------------------------------------------------------------
#if !defined(__FUE__) && !defined(__UBL__)
//-----------------------------------------------------------------------------
/*! @remarks
  [Device Lock]
  * Purpose
      > To support FOTA
          - FDM may not be the only user of the MTD driver
      > To protect the program data in GPRAM
          - Any command toward serial Flash requires GPRAM
          - If an interrupt comes during data transfer between local buf. and GPRAM,
            it may corrput the data already transferrd to GPRAM.
  * Constrains
      > A task can not get the same resouce twice
          - To avoid self-dead-lock
      > A task can not get the resouce while interrupt is disabled
          - System calls are prohibited when I bit is disabled

 [NOTE! Important]
 * Issue
      > Deivce lock cannot be applied to all routines, due to self-dead lock and IRQ disable.
          - The device lock cannot be applied to following functions
            FlashReturnReady() [IRQ disable]
            SF_DAL_CheckDeviceReady() [Self-deadlock]
            SF_DAL_CheckReadyAndResume() [Self-deadlock]
 * Description
      > Every program transaction consists of 1B of command, 3B of address,
        and 1~256B of data in sequential.
      > If an interrupt comes during Local Buf.¡÷GPRAM and reads Flash status,
        it may corrput the program command and a part of program address.
 *  Solution
      > Always write first 4 bytes (command+address) to GPRAM after IRQs are disabled.
      > The device lock must be applied to SF_DAL_ProgramData, Flash_ProgramData and
        SF_DAL_IOCtrl, because their GPRAM utilization > 4 bytes.

 [Routines that needs device lock protection]
 * Erase / Program routines
 * SST block unlock routines (1+10B)

 [Routines that can not be device locked]
 * FlashReturnReady() [IRQ disabled]
 * Suspend

*/
//-----------------------------------------------------------------------------
/*!
  @brief
    Create the device lock that protects SFC GPRAM[0x004-0x199] and erase/program
  @remarks
    Only called by SF_DAL_MountDevice().
    Do nothing, if the lock already exists.
*/
__sf_section_RAM void SF_DAL_CreateDevLock(SF_MTD_Data *D)
{
    if (D->DeviceLock == NULL)   {
        D->DeviceLock = kal_create_sem("SFI_DEV_LOCK", 1);
    }
}

//-----------------------------------------------------------------------------
/*!
  @brief
    Accquire the deivce lock.
  @remarks
*/
__sf_section_RAM void SF_DAL_GetDevLock(SF_MTD_Data *D)
{

   if( kal_query_systemInit() || INT_QueryExceptionStatus() )
      return;


   if (D->DeviceLockOwner == kal_get_current_task()) {
       D->DeviceLockDepth++;
       ASSERT(D->DeviceLockDepth<16);
       SF_DAL_DEBUG_MULTI_USER("A. Mulit SF_DEV Lock, count= %d \r\n", D->DeviceLockDepth);
       return;
   }

   SF_DAL_DEBUG_MULTI_USER("[%s] -- 1. Try to get SF_DEV Lock \r\n", ((kal_internal_taskid)kal_get_current_thread_ID())->task_name);

   kal_take_sem(D->DeviceLock, KAL_INFINITE_WAIT);

   ASSERT(D->DeviceLockOwner==KAL_NILTASK_ID);

   D->DeviceLockOwner = kal_get_current_task();

   SF_DAL_DEBUG_MULTI_USER("[%s] -- 2. Get SF_DEV Lock successfully \r\n", ((kal_internal_taskid)kal_get_current_thread_ID())->task_name);

}

//-----------------------------------------------------------------------------
/*!
  @brief
    Release the deivce lock.
*/
__sf_section_RAM void SF_DAL_FreeDevLock(SF_MTD_Data *D)
{
   if( kal_query_systemInit() || INT_QueryExceptionStatus() )
      return;

   ASSERT(D->DeviceLockOwner==kal_get_current_task());

   if (D->DeviceLockDepth > 0) {
        SF_DAL_DEBUG_MULTI_USER("B. Release multi SF_DEV Lock, count= %d \r\n", D->DeviceLockDepth);
        D->DeviceLockDepth--;
        return;
   }

   D->DeviceLockOwner = KAL_NILTASK_ID;
   kal_give_sem(D->DeviceLock);

   SF_DAL_DEBUG_MULTI_USER("[%s] -- 3. Release SF_DEV Lock successfully \r\n", ((kal_internal_taskid)kal_get_current_thread_ID())->task_name);

}
#else  // !(__FUE__) && !(__UBL__)

#define SF_DAL_CreateDevLock(...)
#define SF_DAL_GetDevLock(...)
#define SF_DAL_FreeDevLock(...)

#endif // !(__FUE__) && !(__UBL__)

//-----------------------------------------------------------------------------
// [DAL] Init functions
//-----------------------------------------------------------------------------

/*
  Serial Flash Support Options
  SF_DAL_SST
  SF_DAL_MXIC
  SF_DAL_EON
*/
//-----------------------------------------------------------------------------
/*!
  @brief
   SST serial Flash init function, determine the device ID of the SST Serial
   NOR Flash, initialize status map and driver abstract

  @param[in] driver Pointer to the driver-interface
  @param[in] data Pointer to the driver-data
  @retval
     FS_FLASH_MOUNT_ERROR: The device is not recognizable
     FS_NO_ERROR: Init successful
  @remarks
     Caller: SF_DAL_Init_Driver()
     SST Support compile option "SF_DAL_SST"
     GPRAM utilization is 1+(BPB/8)B. A device lock is Required.
*/
#if defined(SF_DAL_SST)
__sf_section_SECOND_PART kal_int32 SF_DAL_Init_SST(NOR_MTD_Driver *driver, SF_MTD_Data *D)
{
    SF_Status          *smap;

    // Status map
    smap = D->StatusMap;
    smap[SF_SR_BUSY] = SF_SST_SR_BUSY;
    smap[SF_SR_WEL]  = SF_SST_SR_WEL;
    smap[SF_SR_WSE]  = SF_SST_SR_WSE;
    smap[SF_SR_WSP]  = SF_SST_SR_WSP;

    // Status Registers
    D->CMD->ReadSuspendReg=SF_CMD_READ_SR;
    D->CMD->ReadSecurityReg=SF_CMD_SST_READ_SECURITY_ID;
    D->SuspendLatency = 11;

    switch (D->FlashID[2])    {
        case 0x28:  // SST WF: 8 Mbit (1 MB), 1.8V
            D->BPRBitCount=32; break;
        case 0x21:  // SST WF: 16 Mbit (2 MB), 1.8V
            D->BPRBitCount=48; break;
        case 0x22:  // SST WF: 32 Mbit (4 MB), 1.8V
        case 0x02:  // SST VF: 32 Mbit (4 MB), 2.8V
            D->BPRBitCount=80; break;
        case 0x23:  // SST WF: 64 Mbit (8 MB), 1.8V
        case 0x03:  // SST VF: 64 Mbit (8 MB), 2.8V
            D->BPRBitCount=144; break;
        default:
            return FS_FLASH_MOUNT_ERROR;
    }

    // Abstract Functions
    D->UnlockBlock=SF_DAL_UnlockBlock_SST;

#ifdef __SECURITY_OTP__
    D->OTPLength=24;
    D->OTPBase=8;
    D->OTPRead=SF_DAL_OTPRead_SST;
    D->OTPWrite=SF_DAL_OTPWrite_SST;
    D->OTPLock=SF_DAL_OTPLock_MXIC;
    D->CMD->OTPProg=SF_CMD_SST_PROG_SECURITY_ID;
    D->CMD->OTPRead=SF_CMD_SST_READ_SECURITY_ID;
    D->CMD->OTPLock=SF_CMD_SST_LOCK_SECURITY_ID;
    smap[SF_SR_OTPLOCK] = SF_SST_SR_SEC;
#endif

    return FS_NO_ERROR;
}
#endif  //  defined(SF_DAL_SST)

//-----------------------------------------------------------------------------
/*!
  @brief
   MXIC serial Flash init function, determine the device ID of the MXIC Serial
   NOR Flash, initialize status map and driver abstract

  @param[in] driver Pointer to the driver-interface
  @param[in] data Pointer to the driver-data
  @retval
     FS_FLASH_MOUNT_ERROR: The device is not recognizable
     FS_NO_ERROR: Init successful
  @remarks
     Caller: SF_DAL_Init_Driver()
     MXIC Support compile option "SF_DAL_MXIC"
*/
#if defined(SF_DAL_MXIC)
__sf_section_SECOND_PART kal_int32 SF_DAL_Init_MXIC(NOR_MTD_Driver *driver, SF_MTD_Data *D)
{
    SF_Status          *smap;

    // Status map
    smap = D->StatusMap;
    smap[SF_SR_BUSY] = SF_MXIC_SR_BUSY;
    smap[SF_SR_WEL]  = SF_MXIC_SR_WEL;

    smap[SF_SR_WSE]  = SF_MXIC_SR_WSE;
    smap[SF_SR_WSP]  = SF_MXIC_SR_WSP;

    smap[SF_SR_BP]   = SF_MXIC_SR_BP;
    smap[SF_SR_SRWD] = SF_MXIC_SR_SRWD;
    smap[SF_SR_FAIL] = SF_MXIC_SSR_PFAIL | SF_MXIC_SSR_EFAIL;

    // Status Registers
    D->CMD->ReadSuspendReg=SF_CMD_MXIC_READ_SEC_SR;
    D->CMD->ReadSecurityReg=SF_CMD_MXIC_READ_SEC_SR;
    D->CMD->WriteSecurityReg=SF_CMD_MXIC_WRITE_SEC_SR;
    D->CMD->ReadBPReg=SF_CMD_READ_SR;
    D->CMD->WriteBPReg=SF_CMD_WRITE_SR;
    D->CMD->ReadFailReg=SF_CMD_MXIC_READ_SEC_SR;
    D->SuspendLatency = 22;
	//For MXIC 3V device
	if (D->FlashID[1]==0x20 && D->FlashID[2]!=0x19) 
	{
		D->CMD->Suspend=SF_CMD_WINBOND_SUSPEND;
    	D->CMD->Resume=SF_CMD_WINBOND_RESUME;
	}

    // Device Data
    // Abstract Functions
    D->UnlockBlock=SF_DAL_UnlockBlock_MXIC;

#ifdef __SECURITY_OTP__
    D->OTPLength=496;
    D->OTPBase=0x10;
    D->OTPRead=SF_DAL_OTPRead_MXIC;
    D->OTPWrite=SF_DAL_OTPWrite_MXIC;
    D->OTPLock=SF_DAL_OTPLock_MXIC;
    D->CMD->OTPProg=SF_CMD_PAGE_PROG;
    D->CMD->OTPEnter=SF_CMD_MXIC_ENTER_SECURED_OTP;
    D->CMD->OTPExit=SF_CMD_MXIC_EXIT_SECURED_OTP;
    D->CMD->OTPLock=SF_CMD_MXIC_WRITE_SEC_SR;
    smap[SF_SR_OTPLOCK] = SF_MXIC_SSR_LDSO;
#endif

    return FS_NO_ERROR;
}
#endif  // defined(SF_DAL_MXIC)

//-----------------------------------------------------------------------------
/*!
  @brief
   EON serial Flash init function, determine the device ID of the EON Serial
   NOR Flash, initialize status map and driver abstract

  @param[in] driver Pointer to the driver-interface
  @param[in] data Pointer to the driver-data
  @retval
     FS_FLASH_MOUNT_ERROR: The device is not recognizable
     FS_NO_ERROR: Init successful
  @remarks
     Caller: SF_DAL_Init_Driver()
     EON Support compile option "EON_DAL_MXIC"
*/
#if defined(SF_DAL_EON)

__sf_section_SECOND_PART kal_int32 SF_DAL_Init_EON(NOR_MTD_Driver *driver, SF_MTD_Data *D)
{
    SF_Status          *smap;

    // Status map
    smap = D->StatusMap;
    smap[SF_SR_BUSY] = SF_MXIC_SR_BUSY;
    smap[SF_SR_WEL]  = SF_MXIC_SR_WEL;
    smap[SF_SR_WSE]  = SF_EON_SSR_WSE;
    smap[SF_SR_WSP]  = SF_EON_SSR_WSP;

    smap[SF_SR_BP]   = SF_MXIC_SR_BP;
    smap[SF_SR_SRWD] = SF_MXIC_SR_SRWD;

    // Command Override
    D->CMD->ReadID_QPI=SF_CMD_READ_ID;
    // Status Registers
    D->CMD->ReadSuspendReg=SF_CMD_EON_READ_SUSPEND_SR;
    D->CMD->ReadSecurityReg=SF_CMD_EON_READ_SUSPEND_SR;
    D->CMD->ReadBPReg=SF_CMD_READ_SR;
    D->CMD->WriteBPReg=SF_CMD_WRITE_SR;
    D->SuspendLatency = 22;

    // Device Data
    // Abstract Functions
    D->UnlockBlock=SF_DAL_UnlockBlock_MXIC;

    return FS_NO_ERROR;
}
#endif // defined(SF_DAL_EON)

#if defined(SF_DAL_GIGADEVICE) || defined(SF_DAL_WINBOND)
//-----------------------------------------------------------------------------
/*!
  @brief
   Winbond serial Flash init function, determine the device ID of the WINBOND Serial
   NOR Flash, initialize status map and driver abstract

  @param[in] driver Pointer to the driver-interface
  @param[in] data Pointer to the driver-data
  @retval
     FS_FLASH_MOUNT_ERROR: The device is not recognizable
     FS_NO_ERROR: Init successful
  @remarks
     Caller: SF_DAL_Init_Driver()
     Winbond Support compile option "SF_DAL_WINBOND"
*/
__sf_section_SECOND_PART kal_int32 SF_DAL_Init_WINBOND(NOR_MTD_Driver *driver, SF_MTD_Data *D)
{
    SF_Status          *smap;

    // Status map
    smap = D->StatusMap;
    smap[SF_SR_BUSY] = SF_MXIC_SR_BUSY;
    smap[SF_SR_WEL]  = SF_MXIC_SR_WEL;
    smap[SF_SR_WSE]  = SF_WINBOND_SSR_SUS;
    smap[SF_SR_WSP]  = SF_WINBOND_SSR_SUS;
    smap[SF_SR_BP]   = SF_MXIC_SR_BP;
    smap[SF_SR_SRWD] = SF_MXIC_SR_SRWD;

    // Command Override
    D->CMD->ReadID_QPI=SF_CMD_READ_ID;
    // Status Registers
    D->CMD->ReadSuspendReg=SF_CMD_WINBOND_READ_SUSPEND_SR;
    D->CMD->ReadSecurityReg=SF_CMD_WINBOND_READ_SUSPEND_SR;
    D->CMD->ReadBPReg=SF_CMD_READ_SR;
    D->CMD->WriteBPReg=SF_CMD_WRITE_SR;
    D->CMD->Suspend=SF_CMD_WINBOND_SUSPEND;
    D->CMD->Resume=SF_CMD_WINBOND_RESUME;
    D->SuspendLatency = 22;

    // Device Data
    // Abstract Functions
    D->UnlockBlock=SF_DAL_UnlockBlock_None;

    return FS_NO_ERROR;
}
#endif

#if defined(SF_DAL_WINBOND)
__sf_section_SECOND_PART kal_int32 SF_DAL_Init_WINBOND_OTP(NOR_MTD_Driver *driver, SF_MTD_Data *D)
{
#ifdef __SECURITY_OTP__
    SF_Status          *smap;
    // Status map
    smap = D->StatusMap;
    D->OTPLength=1024;
    D->OTPBase=0; //Security register 0 is reserved for Winbond
    D->OTPRead=SF_DAL_OTPRead_WINBOND;
    D->OTPWrite=SF_DAL_OTPWrite_WINBOND;
    D->OTPLock=SF_DAL_OTPLock_WINBOND;
    D->CMD->OTPEnter=SF_CMD_SST_QPIRST;
    D->CMD->OTPExit=SF_CMD_SST_QPIEN;
    D->CMD->OTPProg=SF_CMD_WINBOND_PROG_SECURITY_REG;
    D->CMD->OTPRead=SF_CMD_WINBOND_READ_SECURITY_REG;
    smap[SF_SR_OTPLOCK] = SF_WINBOND_SSR_OTP;
#endif

    return FS_NO_ERROR;
}

#endif // defined(SF_DAL_WINBOND)

//-----------------------------------------------------------------------------
/*!
  @brief
   Giga Device serial Flash init function, determine the device ID,
   initialize status map and driver abstract

  @param[in] driver Pointer to the driver-interface
  @param[in] data Pointer to the driver-data
  @retval
     FS_FLASH_MOUNT_ERROR: The device is not recognizable
     FS_NO_ERROR: Init successful
  @remarks
     Caller: SF_DAL_Init_Driver()
     GIGADEVICE Support compile option "SF_DAL_GIGADEVICE"
*/
#if defined(SF_DAL_GIGADEVICE)
__sf_section_SECOND_PART kal_int32 SF_DAL_Init_GIGADEVICE(NOR_MTD_Driver *driver, SF_MTD_Data *D)
{
    SF_Status *smap=D->StatusMap;

    SF_DAL_Init_WINBOND(driver, D);

    // Config status map
    smap[SF_SR_WSE]  = 0;
    smap[SF_SR_WSP]  = 0;
    D->SuspendLatency = 2;

    return FS_NO_ERROR;
}
#endif


//-----------------------------------------------------------------------------
/*!
  @brief
   Numonyx serial Flash init function, determine the device ID,
   initialize status map and driver abstract

  @param[in] driver Pointer to the driver-interface
  @param[in] data Pointer to the driver-data
  @retval
     FS_FLASH_MOUNT_ERROR: The device is not recognizable
     FS_NO_ERROR: Init successful
  @remarks
     Caller: SF_DAL_Init_Driver()
     NUMONYX Support compile option "SF_DAL_NUMONYX"
*/

#if defined(SF_DAL_NUMONYX)

__sf_section_SECOND_PART kal_int32 SF_DAL_Init_NUMONYX(NOR_MTD_Driver *driver, SF_MTD_Data *D)
{
    SF_Status          *smap;

    // Status map
    smap = D->StatusMap;
    smap[SF_SR_BUSY] = SF_MXIC_SR_BUSY;
    smap[SF_SR_WEL]  = SF_MXIC_SR_WEL;
    smap[SF_SR_WSE]  = SF_NUMONYX_SSR_WSE;
    smap[SF_SR_WSP]  = SF_NUMONYX_SSR_WSP;
    smap[SF_SR_BP]   = SF_MXIC_SR_BP;
    smap[SF_SR_SRWD] = SF_MXIC_SR_SRWD;

    // Command Override
    D->CMD->ReadID_QPI=SF_CMD_READ_ID;
    // Status Registers
    D->CMD->ReadSuspendReg=SF_CMD_NUMONYX_READ_FLAG_SR;
    D->CMD->ReadSecurityReg=SF_CMD_NUMONYX_READ_LOCK_SR;
    D->CMD->ReadBPReg=SF_CMD_READ_SR;
    D->CMD->WriteBPReg=SF_CMD_WRITE_SR;
    D->CMD->Suspend=SF_CMD_WINBOND_SUSPEND;
    D->CMD->Resume=SF_CMD_WINBOND_RESUME;
    D->SuspendLatency = 17;

    // Abstract Functions
    D->UnlockBlock=SF_DAL_UnlockBlock_None;

    return FS_NO_ERROR;
}

#endif // defined(SF_DAL_Init_NUMONYX)

/*
// Init Function Tempalte
#if defined(SF_DAL_XXX)
kal_int32 SF_DAL_Init_XXX(NOR_MTD_Driver *driver, SF_MTD_Data *D)
{
    SF_Status          *smap;

    // Status map
    smap = D->StatusMap;

    // Command Override
    // Status Registers
    // Abstract Functions
    return FS_NO_ERROR;
}
#endif // defined(SF_DAL_XXX)
*/


//-----------------------------------------------------------------------------
/*!
  @brief
   Common serial Flash init function, initialize status map and driver abstract.

  @param[in] driver Pointer to the driver-interface
  @param[in] data Pointer to the driver-data

  @remarks
     Caller: SF_DAL_Init_Driver()
*/
__sf_section_SECOND_PART kal_int32 SF_DAL_Init_Common(NOR_MTD_Driver *driver, SF_MTD_Data *D)
{
    // Initialize First Abstract Layer Functions (Interface to NOR FDM)
    driver->MountDevice = SF_DAL_MountDevice;
    driver->ShutDown = SF_DAL_ShutDown;
    driver->MapWindow = MapWindow;
    driver->EraseBlock = SF_DAL_EraseBlock;
    driver->ProgramData = SF_DAL_ProgramData;
    driver->NonBlockEraseBlock = SF_DAL_NonBlockEraseBlock;
    driver->CheckDeviceReady = SF_DAL_CheckDeviceReady;
    driver->SuspendErase = SF_DAL_SuspendErase;
    driver->ResumeErase = SF_DAL_ResumeErase;
    driver->BlankCheck = NULL;

#ifdef __SECURITY_OTP__
    driver->OTPAccess = SF_DAL_OTPAccess;
    driver->OTPQueryLength = SF_DAL_OTPQueryLength;
    D->OTPLength=0;
#else
    driver->OTPAccess = NULL;
    driver->OTPQueryLength = NULL;
#endif

    driver->LockEraseBlkAddr = SF_DAL_LockEraseBlkAddr;
    driver->IsEraseSuspended = NULL;
    driver->IOCtrl = SF_DAL_IOCtrl;

#if defined(__SFI_4BYTES_ADDRESS__)
    if (custom_get_NORFLASH_Size()>0x1000000)
    {
        D->AddressCycle = 4;
    }
    else
#endif
    {
        D->AddressCycle = 3;
    }

    // Initialize Common Deivce Commands
    D->CMD->ReadFailReg=0;
    D->CMD->ReadID_QPI=SF_CMD_READ_ID_QPI;
    D->CMD->ReadID_SPI=SF_CMD_READ_ID;
    D->CMD->PageProg=SF_CMD_PAGE_PROG;
    D->CMD->Erase4K=SF_CMD_ERASE_SECTOR;
    D->CMD->Erase32K=SF_CMD_ERASE_SMALL_BLOCK;
    D->CMD->Erase64K=SF_CMD_ERASE_BLOCK;
    D->CMD->Suspend=SF_CMD_SUSPEND;
    D->CMD->Resume=SF_CMD_RESUME;
    D->CMD->WriteEnable=SF_CMD_WREN;

    // Status Registers
    D->CMD->ReadReadyReg=SF_CMD_READ_SR;

    // Block Protection Bits (SST only)
    D->BPRBitCount=0;

    // Mutex
    D->DeviceLockOwner = KAL_NILTASK_ID;
    D->DeviceLock = NULL;
    D->DeviceLockDepth = 0;
    D->SuspendLatency = 5;

    return FS_NO_ERROR;
}

//-----------------------------------------------------------------------------
/*!
  @brief
   Common serial Flash init function, initialize status map and driver abstract.

  @param[in] driver Pointer to the driver-interface
  @param[in] data Pointer to the driver-data

  @remarks
     Caller: SF_DAL_Init_Driver()
*/
__sf_section_SECOND_PART kal_int32 SF_DAL_Init_Vendor(NOR_MTD_Driver *driver, SF_MTD_Data *D)
{
    kal_int32 result;

    switch (D->FlashID[0])    {
    #if defined(SF_DAL_SST)
        case SF_DAL_TYPE_SST:
            result = SF_DAL_Init_SST(driver, D);
            break;
    #endif
    #if defined(SF_DAL_MXIC)
        case SF_DAL_TYPE_MXIC:
        #if defined(SF_FIX_MXIC_35E)
            sf_dal_fix |= sf_fix_mxic_35e;
        #endif
            result = SF_DAL_Init_MXIC(driver, D);
            break;
    #endif
    #if defined(SF_DAL_EON)
        case SF_DAL_TYPE_EON:
            result = SF_DAL_Init_EON(driver, D);
            break;
    #endif
    #if defined(SF_DAL_WINBOND)
        case SF_DAL_TYPE_WINBOND:
        #if defined(SF_FIX_WINBOND_DW)
            sf_dal_fix |= sf_fix_winbond_dw;
        #endif
            result  = SF_DAL_Init_WINBOND(driver, D);
            result |= SF_DAL_Init_WINBOND_OTP(driver, D);
            break;
        case SF_DAL_TYPE_FIDELIX:
        #if defined(SF_FIX_FIDELIX_Q32A)
            sf_dal_fix |= sf_fix_fidelix_q32a;
        #endif
            result = SF_DAL_Init_WINBOND(driver, D);
            break;
    #endif
    #if defined(SF_DAL_GIGADEVICE)
        case SF_DAL_TYPE_GIGADEVICE:
            if(D->FlashID[1] == 0x40) //Enter HPM mode Only for GD 3V device
            	sf_dal_fix |= sf_fix_gigadevice_b;
            result = SF_DAL_Init_GIGADEVICE(driver, D);
            break;
    #endif
    #if defined(SF_DAL_NUMONYX)
        case SF_DAL_TYPE_NUMONYX:
        case SF_DAL_TYPE_NUMONYX_W:
            result = SF_DAL_Init_NUMONYX(driver, D);
            break;
    #endif
        default:
            result = FS_FLASH_MOUNT_ERROR;
            break;
    }

    return result;
}

//-----------------------------------------------------------------------------
/*!
  @brief
   Driver Abstract Layer Main Init Function

  @param[in] driver Pointer to the driver-interface
  @param[in] data Pointer to the driver-data
  @param[in] baseaddr Base address of the serial Flash
  @param[in] paramter Device parameter (Uniform Block Size)

  @retval
     FS_FLASH_MOUNT_ERROR: The device is not recognizable
     FS_NO_ERROR: Init successful
*/
__sf_section_SECOND_PART kal_int32 SF_DAL_Init_Driver(NOR_MTD_Driver *driver, SF_MTD_Data *D, kal_uint32 baseaddr, kal_uint32 parameter)
{
    kal_int32 result;

    // Check All pointers are valid
    if (driver==NULL || D==NULL) {
        return FS_FLASH_MOUNT_ERROR;
    }

    if (D->CMD==NULL || D->StatusMap==NULL)   {
        return FS_FLASH_MOUNT_ERROR;
    }

#if (defined(SF_DEBUG) && defined(SF_DAL_CODE_REGION_CHECK))
    NORGuardPattern1 = NORGuard1;
    NORGuardPattern2 = NORGuard2;
#endif

    D->BaseAddr = (kal_uint8*)baseaddr;
    D->UniformBlock = parameter;

    // Common Initiailzation
    SF_DAL_Init_Common(driver, D);

    // Read Vendor ID
    D->CMD->ReadID_QPI = SF_CMD_READ_ID_QPI;
    SF_DAL_Dev_ReadID(D, D->FlashID);

    if (D->FlashID[0]==0xFF || D->FlashID[0]==0x00 || (CMEM_CheckValidDeviceID(D->FlashID) == KAL_FALSE))    {
        D->CMD->ReadID_QPI = SF_CMD_READ_ID;
        SF_DAL_Dev_ReadID(D, D->FlashID);
    }

    // Vendor Specific Initialization
    result = SF_DAL_Init_Vendor(driver, D);

    return result;
}

//-----------------------------------------------------------------------------
// [DAL] First Level Abstract (Interface to upper driver)
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
/*!
  @brief
    MTD Layer Mount Device, unlock all blocks to allow read/write access.

  @param[in] MTDData Pointer to the MTD driver data
  @param[in] Info Pointer to the FlashInfo structure

  @retval
    FS_NO_ERROR: Successful

  @remarks
    The device lock is created in this routine.
    This function will invoke UnlockBlock() functional pointer given in the MTD data.
*/
__sf_section_SECOND_PART int SF_DAL_MountDevice(void *MTDData, void *Info)
{
    NOR_MTD_FlashInfo  *FlashInfo = Info;
    SF_MTD_Data        *D         = MTDData;
    kal_uint32          i         = 0;
    kal_int32 result; 
    SF_DAL_CreateDevLock(D);

    // config geometry (FlashInfo)
    FlashInfo->TotalBlocks = 0;

    while (D->RegionInfo[i].BlockSize != 0)
    {
      FlashInfo->BlockSize[i] = D->RegionInfo[i].BlockSize;
      FlashInfo->RegionBlocks[i] = D->RegionInfo[i].RegionBlocks;
      FlashInfo->TotalBlocks += D->RegionInfo[i].RegionBlocks;

      i++;
    }

    FlashInfo->ActualRegionNum = i;
    FlashInfo->PageSize = 512;

#if defined(SF_DAL_WINBOND) && defined(SF_FIX_WINBOND_CV)
    if (D->FlashID[0]==SF_DAL_TYPE_WINBOND && D->FlashID[1]==0x40) {
        kal_uint8 uid[6];
        uid[0]=SF_CMD_WINBOND_READ_UNIQUE_ID;
        SF_DAL_Dev_Command_Ext(&uid[0], &uid[1], 1, 5);
        if (uid[5]==0x0) {
            sf_dal_fix |= sf_fix_winbond_cv;
            D->StatusMap[SF_SR_WSE] = D->StatusMap[SF_SR_WSP] = 0;
        }
    }
#endif


#if defined(SF_BR_BUSY_WAIT)
    if ( (SFI_DevMode & SFI_QPI_EN) !=0)   {
        sf_dal_brbusy_wait=KAL_FALSE;
    }
    else    {
        sf_dal_brbusy_wait=KAL_TRUE;
    }
#endif //SF_BR_BUSY_WAIT
    // Fota and Card DL may directly use SF_DAL_MountDevice to mount MTD in bootloader.
    SF_DAL_Dev_Resume(D); //Issue a resume command because GD has no suspend flags, and device suspend flag is not set yet during WDT.
    // Resume previous suspend operation if any, clear NV busy flag, otherwise, bootrom will wait extra 4 seconds.
    do   {
        result = SF_DAL_CheckDeviceReady(D, 0);
    } while (FS_FLASH_ERASE_BUSY == result);

    LISR_Insert(); //For Basic load test

#if defined(__UBL__)
    // Reset NV Reg: Fota and Card DL may directly use SF_DAL_MountDevice to mount MTD in bootloader.
    // If WDT reset happens during UnlockBlock program operation, bootRom must wait Device Ready.
#if defined(SF_BR_BUSY_WAIT)
    if ( (SFI_DevMode & SFI_QPI_EN) ==0)
    {
        i	= *SF_NVREG & 0xFFFF0000;
        i  |= (SF_BUSY | SF_4S);
        SFI_WriteReg32(SF_NVREG, i);
    }
#endif //SF_BR_BUSY_WAIT
    // Fota and Card DL may directly use SF_DAL_MountDevice to mount MTD in bootloader.
    // Unlock all blocks, PCT needs to do unlockBlock each boot-up. 
    D->UnlockBlock(D);
#endif //__UBL__
	
    return FS_NO_ERROR;
}

//-----------------------------------------------------------------------------
/*!
  @brief
    Shutdown the serial Flash, resume and wait any unfinished operations.

  @param[in] MTDData Pointer to the MTD driver data

  @retval
    FS_NO_ERROR: Successful
  @remarks
    This function must be placed on RAM because flash may be busy/resumed inside!
    GPRAM utilization is 1+1. A device lock is not necessary.
*/
__sf_section_SECOND_PART int SF_DAL_ShutDown(void *MTDData)
{
    SF_MTD_Data            *D = MTDData;
    SF_Status               status;
    kal_uint32              saved_mask;

    SF_DAL_GetDevLock(D);

    while (1)
    {
        saved_mask = SaveAndSetIRQMask();

        // resume suspended operation issued by ISR (ESB only)
        if(SF_DAL_FLAG_SUS())
        {
            SF_DAL_Dev_Resume(D);
            gNOR_ReturnReadyEnd = NOR_DEFAULT_RETURN_READY_LATENCY;
        }

        // read status register
        status = SF_DAL_Dev_ReadStatus(D, D->CMD->ReadReadyReg);

        // if flash is ready, break, else loops again
        if (0 == (status & D->StatusMap[SF_SR_BUSY]))
        {
            SF_DAL_FLAG_BUSY_CLR();
            RestoreIRQMask(saved_mask);
            break;
        }
        else
        {
            RestoreIRQMask(saved_mask);
        }
    }

    D->CurrAddr = NULL;

    SF_DAL_FreeDevLock(D);
    return FS_NO_ERROR;
}

//-----------------------------------------------------------------------------
/*!
  @brief
    Erase / Lock / Unlock a block

  @param[in] MTDData Pointer to the MTD driver data
  @param[in] CtrlAction Enumeration value of control actions
  @param[in] CtrlData Pointer to the control data

  @retval
    FS_NO_ERROR: Successful
  @remarks
    Enumeration of Control actions are listed as follows:
      SF_IOCTRL_UNLOCK_BLOCK
      SF_IOCTRL_ENABLE_QPI (deprecated)
      SF_IOCTRL_CONFIG_BURST_LEN (deprecated)
      SF_IOCTRL_QUERY_READ_COMMAND (deprecated)

  @remarks
    The device lock is inserted in the sub-routines, not in IOCtrl()
*/
__sf_section_SECOND_PART int SF_DAL_IOCtrl(void *MTDData, kal_uint32 CtrlAction, void * CtrlData)
{
    SF_MTD_Data        *D  = MTDData;
    if (CtrlAction == SF_IOCTRL_UNLOCK_BLOCK)     {
        D->UnlockBlock(D);
    }
    else if (CtrlAction == SF_IOCTRL_GET_PROGRAM_FAIL_HANDLE_TYPE)  {
        if ((D->FlashID[0] == SF_DAL_TYPE_MXIC)&&(D->RegionInfo[0].BlockSize==0x40000))   {
            return SF_DAL_TYPE_MXIC;
        }
    }
    else {
        MTD_SNOR_ASSERT(0, 0, 0, 0, NOR_MTD_UNSUPPORTED_FUNCTION);
    }
    return FS_NO_ERROR;
}


#if defined(__RTL_SIMULATION_FOR_60QBIT__)
__sf_section_SECOND_PART void SF_DAL_60qbitTest(void)
{
    SF_MTD_Data *sfdal_data=FlashDriveData.MTDData;

    sfdal_D->CurrAddr=sfdal_D->BaseAddr-sfdal_D->RegionInfo[0].BlockSize;
    SF_DAL_EraseBlock(sfdal_data, -1);
    SF_DAL_ProgramData(sfdal_data, (void*)(sfdal_D->CurrAddr), (void*)custom_get_INTSRAMCODE_Base(), 0x200);
    return;
}
#endif //__RTL_SIMULATION_FOR_60QBIT__


//-----------------------------------------------------------------------------
/*!
  @brief
    Program data into the serial NOR Flash

  @param[in] MTDData Pointer to the MTD driver data
  @param[in] Address Pointer to the physical address that going to be programmed
  @param[in] Data Pointer to the data buffer
  @param[in] Length Length of data buffer

  @retval
    RESULT_FLASH_FAIL: Data compare failed in SF_DAL_CheckReadyAndResume().
    RESULT_FLASH_BUSY: The deivce is busy.
    RESULT_FLASH_DONE: Program successful.

  @remarks
    The maximum GPRAM utilization is 1+3+256B. A device lock is required.
*/

extern volatile kal_uint32 processing_irqCnt;

#if defined(SF_DEBUG)
__sf_section_RAM int SF_DAL_ProgramCheck(SF_MTD_Data *D, void *Address, kal_uint8 *p_data, kal_uint32 Length)
{
    kal_int32 result=RESULT_FLASH_DONE;
    kal_uint8 fail_flag=0;
    kal_uint32 offset, last_data, val, i;
    kal_uint8 *p_local_data=(kal_uint8*)Address;

    for (offset=0 ; offset<Length ; offset++, p_data++, p_local_data++)   {
        val=SFI_ReadReg8(p_local_data);
        if (*p_data!=val) {
            if (ProgRBLen>4)  {
                SF_DAL_Dev_Command(D, LA_PROGFAIL, 1);
                SF_DAL_DEBUG("[SF_DAL] Program Fail <Addr:%08X Len:%d> @ Offset %d NOR:%08X(%02X) RAM:%08X(%02X)\r\n", Address, ProgRBLen, offset, p_local_data, val, p_data, *p_data);
                SF_DAL_FailMark(D);
                SF_DAL_DEBUG("[RAM @ %08X] \r\n",(kal_uint32)p_data);
                SF_DAL_MemDump(D, p_data, Length);
                SF_DAL_DEBUG("[NOR @ %08X] \r\n",(kal_uint32)Address);
                SF_DAL_MemDump(D, Address, Length);
                SF_DAL_DEBUG("Flipping test @ %08X\r\n", p_local_data);
                do {
                   last_data=val;
                   for (i=0;(val=SFI_ReadReg8(p_local_data)) == last_data; i++);
                   SF_DAL_Dev_Command(D, LA_PROGFAIL, 1);
                   SF_DAL_DEBUG("#%d:%02X,", i, val);
                }
                while(1);
            }
            fail_flag=1;
            result = RESULT_FLASH_FAIL;
            SF_DAL_DEBUG("[SF_DAL] Program Fail <Addr:%08X Len:%d> @ Offset %d NOR:%08X(%02X) RAM:%08X(%02X)\r\n", Address, Length, offset, p_local_data, val, p_data, *p_data);
        }
        else if (fail_flag)  {
          SF_DAL_DEBUG("[SF_DAL] Check NOR:%08X(%02X) RAM:%08X(%02X)\r\n", p_local_data, val, p_data, *p_data);
        }
    }

    if ( (fail_flag) && ProgRBLen>4) MTD_SNOR_ASSERT(0, 0, 0, 0, NOR_MTD_PROGRAM_COMP_DATA_FAIL);

    return result;
}
#endif // SF_DEBUG

/*Mini Bootloader does not need to do Erase and Program Operation*/
/*Therefore, use dummy function to avoid mini Bootloader out of size*/
#if (!defined(__NOR_FULL_DRIVER__) || defined(__MINI_BOOTLOADER__)) && defined(__UBL__)

__sf_section_RAM int SF_DAL_ProgramData(void *MTDData, void *Address, void *Data, kal_uint32 Length)
{
    return FS_UNSUPPORTED_DRIVER_FUNCTION;
}
#else //(!defined(__NOR_FULL_DRIVER__) || defined(__MINI_BOOTLOADER__)) && defined(__UBL__)
__sf_section_RAM int SF_DAL_ProgramData(void *MTDData, void *Address, void *Data, kal_uint32 Length)
{
    SF_MTD_Data     *D=MTDData;
    kal_uint32      savedMask;
    kal_uint32      address         = (kal_uint32)Address;
    kal_uint8      *p_data          = Data;
    kal_uint8      *p_data_first;           // to save the last byte for data compare in CheckReadyAndResume()
    kal_int32       result          = RESULT_FLASH_BUSY;
    kal_uint32      written;                // length for single round program
    kal_uint32      length;                 // length for single round program
    kal_uint32      cmd1;

    ASSERT((~D->Signature == (kal_uint32)D->RegionInfo));

#if defined(SF_DEBUG)
    ProgRBLen=Length;
#endif

    /*
     * SFI's GPRAM (General purpose SRAM) only supports 4-byte data transfer.
     * The reason is GPRAM is connected with APB bus which does not support byte access.
     *
     * (Only AHB bus supports data size option HSIZE[]: 8, 16 or 32 bits.
     * Please refer to AMBA 2.0 spec for details.)
     *
     * Thus driver must check source buffer address first and cover non 4-byte aligned case.
     * For example, move source data to a temporary aligned buffer using byte read / write,
     * then move data from aligned buffer to GPRAM using 4-byte data transfer.
     */
    SF_DAL_GetDevLock(D);

    D->DriverStatus=SFDRV_PROGRAMMING;

    /*
     * Wait device ready after get deivce lock (for non-block erase).
     * > Keep device lock management invisible to other modules.
     * > So that FOTA needs not to retrieve lock and wait Flash ready before calling MTD program,
     */

    do   {
        result = SF_DAL_CheckDeviceReady(D, 0);
    	IntTest(2);
    } while (FS_FLASH_ERASE_BUSY == result);

    /*
     *  Page program loop
     */
    while (0 != Length)
    {
        p_data_first    = p_data;
        /*
         * Calculate how many bytes to write this loop
         *
         * !NOTE! BUFFER_PROGRAM_ITERATION_LENGTH should be larger than SF_MAX_PAGE_PROG_SIZE
         */

        // step1. length = calculate the offset to the page boundary
        length = PAGE_BUFFER_SIZE*2 - (address & (PAGE_BUFFER_SIZE*2 - 1));

        // stpe2. If program Length is greater than the offset to the page boundary
        length = written = ((Length > length) ? length : Length);

		if (!(sf_dal_fix & sf_fix_gigadevice_b))   { //For GD 3V device, WE cmd should put into IRQMask Region to avoid enter HPM mode again before Program.
        	SF_DAL_Dev_WriteEnable(D);
	    }


        // step3. Handling 3/4 bytes address
#if defined(__SFI_4BYTES_ADDRESS__)
        if (D->AddressCycle == 4)
        {
            cmd1=SFI_GPRAM_Write_C1A4(D->CMD->PageProg, address, &p_data, &length);
            SFI_GPRAM_Write(8, p_data, length);
        }
        else
#endif
        {
            cmd1=SFI_GPRAM_Write_C1A3(D->CMD->PageProg, address);
            SFI_GPRAM_Write(4, p_data, length);
        }

        // step 4: copy bufer to GPRAM
        TimeStampClear();
        SF_Prog_Init();
        savedMask = SaveAndSetIRQMask();
        NOR_PROFILE_60Q_START();
		#if defined(SF_DAL_GIGADEVICE)   //For GD 3V device, WE cmd should put into IRQMask Region to avoid enter HPM mode again before Program.
   			 if (sf_dal_fix & sf_fix_gigadevice_b)   {
        		SFI_Dev_Command(D->CMD->WriteEnable);
    		 }
		#endif
        SFI_WriteReg32(RW_SFI_GPRAM_DATA, cmd1);
        SFI_WriteReg32(RW_SFI_MAC_OUTL, written + D->AddressCycle + 1);
        SFI_WriteReg32(RW_SFI_MAC_INL , 0);
        SF_DAL_FLAG_BUSY_SET();
        SF_Prog_Start();
        SFI_MacEnable();
        SFI_MacWaitReady();

#if defined(SF_DAL_WINBOND) && defined(SF_FIX_FIDELIX_Q32A)
        if (sf_dal_fix & sf_fix_fidelix_q32a) {
            ust_busy_wait(2);
            SFI_WriteReg32(RW_SFI_MAC_OUTL, 1);
            SFI_WriteReg32(RW_SFI_GPRAM_DATA, SF_CMD_WINBOND_SUSPEND);
            SFI_MacEnable();
            SFI_MacWaitReady();
            ust_busy_wait(6);
            SFI_WriteReg32(RW_SFI_GPRAM_DATA, SF_CMD_WINBOND_RESUME);
            SFI_MacEnable();
            SFI_MacWaitReady();
            sf_dal_resume_time=ust_get_current_time();
        }
#endif

        NOR_PROFILE_60Q_END();

#if defined(SF_DAL_WINBOND) && defined(SF_FIX_WINBOND_CV)
        sf_fix_winbond_cv_resumed=0;
#endif

        RestoreIRQMask(savedMask);

        NOR_PROFILE_MTD_WRITE_Start();

#if defined(SF_DAL_WINBOND) && defined(SF_FIX_WINBOND_CV)
        FIX_WINBOND_CV();
#endif

        do  {
            result = SF_DAL_CheckReadyAndResume(D, (kal_uint32)address + written - 1, *(p_data_first + written - 1));
        	IntTest(2);
        } while (RESULT_FLASH_BUSY == result);

        if (PAGE_BUFFER_SIZE>=16) SF_Prog_End();

#ifdef SF_DAL_PROG_STATISTICS
        ProgTotalMax=(USQCNT(ProgTotal)>ProgTotalMax)?USQCNT(ProgTotal):ProgTotalMax;
        if (written==PAGE_BUFFER_SIZE*2)  {
            ProgTotalOverall+=USQCNT(ProgTotal);
            ProgTotalCount++;
        }
#endif

#ifdef SF_DAL_SUSPEND_STATISTICS
        if (SuspendCounter>0)        {
            TimeStampDumpProg();
            SF_DAL_DEBUG("[SF_DAL] Prog Sus %d times %dus/%dus/%dus @ Addr/Len: %08Xh/%Xh \r\n",
            SuspendCounter, USQCNT(ProgTotal), USQCNT(SuspendTotal), USQCNT((ProgTotal-SuspendTotal)), address, written);
        }
#endif

#ifdef SF_DAL_SUSPEND_CHECK
        //Add 32KTimer to measure Suspend to Ready time violation, coz Qbits timer only has range 0~4999 (Qbits).
        //If suspend to Ready time exceeds this range, it's highly possible that this fail will be missed.
        if (QBIT(sf_dal_suspend_ready_time_max)>SF_READY_LIMIT || sf_dal_suspend_fail_count>0 || US32K(sf_dal_suspend_ready_time_32kTimer)>SF_READY_LIMIT)	{
            SF_DAL_DEBUG("Suspend to Ready time violation: %d qbits, expected: %d qbits \r\n", QBIT(sf_dal_suspend_ready_time_max), SF_READY_LIMIT);
            SF_DAL_DEBUG("Suspend to Ready time violation(32K Timer): %d us, expected: %d qbits \r\n", US32K(sf_dal_suspend_ready_time_32kTimer), SF_READY_LIMIT);
            SF_DAL_DEBUG("Polling Time: %d, Polling Stage max time: %d, Polling Counts (max): %d (%d) \r\n",
                QBIT(sf_dal_polling_time_max), QBIT(sf_dal_polling_time_stage_max), sf_dal_polling_count, sf_dal_polling_count_max);
            SF_DAL_DEBUG("Suspend Fail Counts: %d\r\n", sf_dal_suspend_fail_count);
            ASSERT(0);
        }
#endif

        TimeStampStop();

        NOR_PROFILE_MTD_WRITE_End();
        NOR_PROFILE_MTD_WRITE_Count();

        p_data += length;
        Length -= written;
        address += written;

        if (RESULT_FLASH_DONE != result) break;
    }

// Program Fail Check
#if ( defined(__BASIC_LOAD_FLASH_TEST__) && defined(SF_DEBUG))
    if (NORProfileProcess==0 && result != FS_TIMEOUT)
        result=SF_DAL_ProgramCheck(MTDData, Address, Data, ProgRBLen);
#endif

#if defined(__BASIC_LOAD_FLASH_TEST__)
    ProgramNum++;
#endif


#ifdef SF_DAL_PROG_STATISTICS
    //This check is mainly for tuning "suspend frequency" for Device functional test.
    //Move FS_TIMEOUT check to here from program while loop, otherwise when writing 512 byte, if first 256 byte timeout.
    //The next 256 byte will not be written, causing data compare fail.
    if (USQCNT(ProgTotal)>SF_PROG_TIME_LIMIT) {
        result = FS_TIMEOUT;
    }
#endif

    D->DriverStatus=SFDRV_READY;

    SF_DAL_FreeDevLock(D);

    if (result == RESULT_FLASH_DONE) return FS_NO_ERROR;
    return result;
}
#endif //(!defined(__NOR_FULL_DRIVER__) || defined(__MINI_BOOTLOADER__)) && defined(__UBL__)

//-----------------------------------------------------------------------------
/*!
  @brief
    Erase a block

  @param[in] MTDData Pointer to the MTD driver data
  @param[in] BlockIndex The physical block ID of the erasing block

  @retval
    FS_NO_ERROR: Successful

  @remarks
    GPRAM utilization is 1+3B. A device lock is not necessary for GPRAM.
    But it is required to protect the device from simultaneously erase program.
*/

/*Mini Bootloader does not need to do Erase and Program Operation*/
/*Therefore, use dummy function to avoid mini Bootloader out of size*/
#if (!defined(__NOR_FULL_DRIVER__) || defined(__MINI_BOOTLOADER__)) && defined(__UBL__)
__sf_section_RAM int SF_DAL_EraseBlock(void *MTDData, kal_uint32 BlockIndex)
{
        return FS_UNSUPPORTED_DRIVER_FUNCTION;
}
#else //(!defined(__NOR_FULL_DRIVER__) || defined(__MINI_BOOTLOADER__)) && defined(__UBL__)
__sf_section_RAM int SF_DAL_EraseBlock(void *MTDData, kal_uint32 BlockIndex)
{
    kal_int32            result;
    kal_uint32           blocksize;
    kal_uint32           eraseunit;
    kal_uint32           eraseaddr;
    kal_uint32           iteration=1;
    SF_MTD_Data         *D = MTDData;

    ASSERT((~D->Signature == (kal_uint32)D->RegionInfo));

    SF_DAL_GetDevLock(D);
    D->DriverStatus=SFDRV_ERASING;

    // 0. wait device ready before issue another erase command

    do   {
//L1 Support: For Winbond 3V series suspend-to-ready over time workaround, if DelayResume == KAL_TRUE, resume erase will not be performed
// This compile option: Modem Hard Real Time Enhancement (__MD_HRT_RECOVERY__) will only be enabled in make file of chosen project which adopts Winbond 3V old sample.
//Winbond 3V old sample has suspend-to-ready over time symptom which will cause L1 to lose Frame.
#if defined(__MD_HRT_RECOVERY__)
		if(DelayResume == KAL_TRUE)
			result = FS_FLASH_ERASE_BUSY ;
		else
#endif //__MD_HRT_RECOVERY__
        result = SF_DAL_CheckDeviceReady(D, BlockIndex);
    	IntTest(2);
    } while (FS_FLASH_ERASE_BUSY == result);

    // BlockIndex b31=0: Use Combo Memory Block Size
    if (BlockIndex>>31==0)  {
        kal_uint32 a, b, c;

        // Get Pseodo Block Size
        blocksize = CMEM_BlockSize((kal_uint32)D->CurrAddr);
        // Default Erase Unit (in case of non-pseudo-size block)
        eraseunit = blocksize;

        // Find the smallest erase unit from Block Size
        // a: supported uniform blocks
        // b: pseudo block size
        //
        // consider (4, 32, 64 KB uniform blocks)
        // pseido 8KB block
        // c=0           | c=1       | c=2, erase unit = 2^(2+10)=4KB  | c=3
        // a: 0110 0100  > 0011 0010 > 0001 1001 (a%2==1 save b        > 0000 1100
        // b: 0000 1000  > 0000 0100 > 0000 0010  iteration=2, and c)  > 0000 0001 (b%1==1 stop search)
		a=D->UniformBlock;
		b=(blocksize>>10);
		//If that erase unit is natively supported by the device, skip pseudo block search.
		if(0 == (a&b))
		{
        	for (c=0; (b&0x1)==0 ;a=a>>1, b=b>>1, c++)    {
            	if (a&0x1) {
                	iteration = b;
            	    eraseunit = 1 << (c+10);
        	    }
    	    }
		}

        switch (eraseunit)    {
            case 0x1000:  D->CMD->Erase = D->CMD->Erase4K;  break; // 4KB
            case 0x8000:  D->CMD->Erase = D->CMD->Erase32K; break; // 32KB
            case 0x10000: D->CMD->Erase = D->CMD->Erase64K; break; // 64KB
            default: ASSERT(0);
        }
    }
    // BlockIndex b31=1: The erase unit is b30~b0, and the erase command is already placed in D->CMD
    else {
        eraseunit = (BlockIndex<<1)>>1;
    }

    // Erase Iterations
    for (eraseaddr=(kal_uint32)D->CurrAddr ; iteration>0 ; iteration--, eraseaddr+=eraseunit) {
        SF_DAL_Dev_EraseBlock(D, eraseaddr);

#if defined(SF_DAL_WINBOND) && defined(SF_FIX_WINBOND_CV)
        FIX_WINBOND_CV();
#endif

        // 3. wait ready
        while (1)        {
//L1 Support: For Winbond 3V series suspend-to-ready over time workaround, if DelayResume == KAL_TRUE, resume erase will not be performed
// This compile option: Modem Hard Real Time Enhancement (__MD_HRT_RECOVERY__) will only be enabled in make file of chosen project which adopts Winbond 3V old sample.
//Winbond 3V old sample has suspend-to-ready over time symptom which will cause L1 to lose Frame.
#if defined(__MD_HRT_RECOVERY__)
			if(DelayResume == KAL_TRUE)
				result = FS_FLASH_ERASE_BUSY ;
			else
#endif //__MD_HRT_RECOVERY__
            result = SF_DAL_CheckDeviceReady(D, BlockIndex);
            if (FS_FLASH_ERASE_BUSY != result) break;
            IntTest(2);
        }
        SF_Erase_End();

#if defined(__BASIC_LOAD_FLASH_TEST__)
        EraseNum++;
#endif

#if defined(SF_DEBUG)
        // Make sure that NOR flash is accessible
      #ifdef SF_DAL_CODE_REGION_CHECK
        if ( (NORGuard1 != NORGuardPattern1) || (NORGuard2 != NORGuardPattern2))    {
            SF_DAL_Dev_Command(D, LA_CODECORRUPT, 1);
            SF_DAL_FailMark(D);
            MTD_SNOR_ASSERT(0, 0, 0, 0, NOR_MTD_ERASE_FAIL);
        }
      #endif

      #ifdef SF_DAL_ERASE_STATISTICS
        SF_DAL_DEBUG("[SF_DAL] Erase suspended %d times @ Addr/EU: %08Xh/%Xh \r\n", SuspendCounter, eraseaddr, eraseunit);
            SF_DAL_DEBUG("[SF_DAL] TotalErase: %dus ,TotalSuspend: %dus, NetErase: %dus\r\n",
            US32K(EraseTotal), US32K(SuspendTotal), US32K(EraseTotal-SuspendTotal));
      #endif

      #ifdef SF_DAL_SUSPEND_CHECK
        //Add 32KTimer to measure Suspend to Ready time violation, coz Qbits timer only has range 0~4999 (Qbits).
        //If suspend to Ready time exceeds this range, it's highly possible that this fail will be missed.
        if (QBIT(sf_dal_suspend_ready_time_max)>SF_READY_LIMIT || sf_dal_suspend_fail_count>0 || US32K(sf_dal_suspend_ready_time_32kTimer)>SF_READY_LIMIT)    {
            SF_DAL_DEBUG("Suspend to Ready time violation: %d qbits, expected: %d qbits \r\n", QBIT(sf_dal_suspend_ready_time_max), SF_READY_LIMIT);
            SF_DAL_DEBUG("Suspend to Ready time violation(32K Timer): %d us, expected: %d qbits \r\n", US32K(sf_dal_suspend_ready_time_32kTimer), SF_READY_LIMIT);
            SF_DAL_DEBUG("Polling Time: %d, Polling Stage max time: %d, Polling Counts (max): %d (%d) \r\n",
                QBIT(sf_dal_polling_time_max), QBIT(sf_dal_polling_time_stage_max), sf_dal_polling_count, sf_dal_polling_count_max);
            SF_DAL_DEBUG("Suspend Fail Counts: %d\r\n", sf_dal_suspend_fail_count);
            SF_DAL_DEBUG("Suspend Fail Time Stamp: %d us\r\n", US32K(EraseSuspendFailTimeStamp));
            TimeStampDumpErase();
            ASSERT(0);
        }
      #endif
        SF_DAL_BlankCheck(D, (kal_uint8*)eraseaddr, eraseunit);
        TimeStampStop();
#endif // SF_DEBUG
    }

    D->DriverStatus=SFDRV_READY;
    SF_DAL_FreeDevLock(D);

#if defined(SF_DEBUG) && defined(SF_DAL_ERASE_STATISTICS)
    if (US32K(EraseTotal)>SF_ERASE_TIME_LIMIT)  {
        return FS_TIMEOUT;
    }
#endif

    return result;
}
#endif //(!defined(__NOR_FULL_DRIVER__) || defined(__MINI_BOOTLOADER__)) && defined(__UBL__)

//-----------------------------------------------------------------------------
/*!
  @brief
    Erase a block

  @param[in] MTDData Pointer to the MTD driver data
  @param[in] BlockIndex Deserted, don't care.

  @retval
    Always FS_UNSUPPORTED_DRIVER_FUNCTION

  @remarks
    This function is an empty function. Currently all serial Flashes are
    single bank devices, and non-blocking operations are forbidden.
*/
__sf_section_RAM int SF_DAL_NonBlockEraseBlock(void *MTDData, kal_uint32 BlockIndex)
{
    return FS_UNSUPPORTED_DRIVER_FUNCTION;
}

//-----------------------------------------------------------------------------
/*!
  @brief
    Check if the program is completed, failed or busy.

  @param[in] MTDData Pointer to the MTD driver data
  @param[in] addr The last programmed address in Flash.
  @param[in] data The last byte of the data buffer in RAM.

  @retval
    RESULT_FLASH_DONE: The program is completed without error.
    RESULT_FLASH_BUSY: The device is busy.
    RESULT_FLASH_FAIL: Program fail

  @remarks
    After device ready, it compares the last byte in the program buffer and
    the programmed address, returns FAIL if the values are different.
    GPRAM utilization is 1+1B: A device lock is not necessary.
*/

__sf_section_RAM kal_int32 SF_DAL_CheckReadyAndResume(void *MTDData, kal_uint32 addr, kal_uint8 data)
{
    kal_uint32          savedMask;
    SF_MTD_Data        *D               = MTDData;
    kal_int32           result          = RESULT_FLASH_BUSY;    // default result is busy
    kal_uint8           check_data;
    kal_uint16          status_busy;

    // Read device status
    status_busy = SF_DAL_Dev_ReadStatus(D, D->CMD->ReadReadyReg);

    // Flash is suspended due to interrupt => Resume
    if(SF_DAL_FLAG_SUS())
    {
        MTD_SNOR_ASSERT(SF_DAL_FLAG_BUSY(), *(volatile kal_uint16*)addr, *(volatile kal_uint16*)addr, addr, NOR_MTD_ESB_BUSY_FLAG_MISMATCH);

        SF_DAL_Dev_Resume(D);

        gNOR_ReturnReadyEnd = NOR_DEFAULT_RETURN_READY_LATENCY;
    }
    // Flash is not suspended and ready => Validate programmed data
    else  if (0 == (status_busy & D->StatusMap[SF_SR_BUSY]) )
    {
        savedMask=SaveAndSetIRQMask();

        SF_DAL_FLAG_BUSY_CLR();

        // Compare last programmed byte
        check_data = *(volatile kal_uint8*)addr;

        if (check_data == data)        {
            result = RESULT_FLASH_DONE;
        }
        else        {
            result = RESULT_FLASH_FAIL;
        }
        RestoreIRQMask(savedMask);
    }

    if (result == RESULT_FLASH_DONE)
        if (SF_DAL_FailCheck(D) != FS_NO_ERROR)
            return RESULT_FLASH_FAIL;

#if defined(SF_DAL_PROG_STATISTICS)
    if  (D->DriverStatus==SFDRV_PROGRAMMING)    {
        SF_Prog_End();
        if (USQCNT(ProgTotal)>SF_PROG_TIME_LIMIT)   {
            SFUT_IntBusySuspend=0;
        }
        ProgTotal=0;
    }
#endif

    return result;
}

//-----------------------------------------------------------------------------
/*!
  @brief
    Check if the device is ready.

  @param[in] MTDData Pointer to the MTD driver data
  @param[in] BlockIndex The physical block ID (not used in SF driver)

  @retval
    FS_NO_ERROR: The device is ready
    FS_FLASH_ERASE_BUSY: The device is busy.

  @remarks
    GPRAM utilization is 1+1B: A device lock is not necessary.
*/
__sf_section_RAM kal_int32 SF_DAL_CheckDeviceReady(void *MTDData, kal_uint32 BlockIndex)
{
    kal_int32               result;
    kal_uint32              savedMask       = 0;
    SF_MTD_Data            *D               = MTDData;
    SF_Status               status_busy, status_suspend;

    ASSERT((~D->Signature == (kal_uint32)D->RegionInfo));

    // Read Status
    status_busy    = SF_DAL_Dev_ReadStatus(D, D->CMD->ReadReadyReg);
    status_suspend = SF_DAL_Dev_ReadStatus(D, D->CMD->ReadSuspendReg);

    /* ensure that the status check is atomic */
    savedMask = SaveAndSetIRQMask();

    if (0 == (status_busy & D->StatusMap[SF_SR_BUSY]))
    {
        SF_Status check_status = D->StatusMap[SF_SR_WSE] | D->StatusMap[SF_SR_WSP] ;

        // erase suspended or program suspended
        if (  (0 != (status_suspend & check_status)) ||  // check suspend flags
              ( (0 == check_status) && SF_DAL_FLAG_SUS()) )    // devices that do not have suspend flags => check driver flag
        {
            MTD_SNOR_ASSERT(SF_DAL_FLAG_BUSY(), SF_DAL_FLAG_SUS(), status_suspend, status_busy, NOR_MTD_ESB_BUSY_FLAG_MISMATCH);

            // issue resume command
            SF_DAL_Dev_Resume(D);
            gNOR_ReturnReadyEnd = NOR_DEFAULT_RETURN_READY_LATENCY;
            result =  FS_FLASH_ERASE_BUSY;
        }
        else // flash is neither busy nor suspended
        {
#if defined(SF_DAL_WINBOND) && defined(SF_FIX_WINBOND_DW)
            if (sf_dal_fix & sf_fix_winbond_dw)   {
                SFI_Dev_Command(SF_CMD_WINBOND_RESUME);
                SFI_Dev_Command(SF_CMD_WINBOND_RESUME);
            }
#endif
            SF_DAL_FLAG_BUSY_CLR();
            /********************************************//**
             * If an interrupt comes during program/erase, in Flash_ReturnReady(), the device may deny the
             * "Suspend Erase/Program" command because the device is near/already ready. However,
             * NOR_FLASH_SUSPENDED is still be set to KAL_TRUE.
             *
             * In such case, after back to erase/program operation, CheckDeviceReady will reach here
             * because flash is not busy and not erase suspended (but with NOR_FLASH_SUSPENDED = KAL_TRUE). If NOR_FLASH_SUSPENDED
             * is not set to KAL_FALSE here, next time when an interrupt comes during erase/program
             * operation, Flash_ReturnReady() will be misleaded by wrong NOR_FLASH_SUSPENDED and return
             * to IRQ handler directly even if flash is still erasing/programing, leading to an execution
             * error! (Since W08.28)
             ***********************************************/
            SF_DAL_FLAG_SUS_CLR();

            result = FS_NO_ERROR;
        }
    }
    else
    {
        result = FS_FLASH_ERASE_BUSY;
    }

#if defined(SF_DAL_ERASE_STATISTICS)
    if  (D->DriverStatus==SFDRV_ERASING) {
        SF_Erase_End();
        if (US32K(EraseTotal)>SF_ERASE_TIME_LIMIT)  {
            SFUT_IntBusySuspend=0;
        }
        EraseTotal=0;
    }
#endif

    RestoreIRQMask(savedMask);

    if (FS_NO_ERROR == result)
        result = SF_DAL_FailCheck(D);

    return result;
}

//-----------------------------------------------------------------------------
/*!
  @brief
    Issues a suspend command to the device

  @param[in] MTDData Pointer to the MTD driver data
  @param[in] BlockIndex Unused parameter, don't care

  @retval
    FS_NO_ERROR: Successful

  @remarks
    GPRAM utilization is 1B. A device lock is not necessary for GPRAM.
    Since suspend operation is applied on erase and program while the device busy.
    The device lock must not be used in this routine.
*/

/*Mini Bootloader does not need to do Erase and Program Operation*/
/*Therefore, use dummy function to avoid mini Bootloader out of size*/
#if (!defined(__NOR_FULL_DRIVER__) || defined(__MINI_BOOTLOADER__)) && defined(__UBL__)
__sf_section_RAM int SF_DAL_SuspendErase(void *MTDData, kal_uint32 BlockIndex)
{
    return FS_UNSUPPORTED_DRIVER_FUNCTION;
}
#else //(!defined(__NOR_FULL_DRIVER__) || defined(__MINI_BOOTLOADER__)) && defined(__UBL__)
__sf_section_RAM int SF_DAL_SuspendErase(void *MTDData, kal_uint32 BlockIndex)
{
    SF_MTD_Data        *D  = MTDData;
    SF_Status           status;
    kal_uint32          savedMask;

    savedMask = SaveAndSetIRQMask();

    // 1. Issue suspend command
    SF_DAL_Dev_Suspend(D);

    // 2. wait for device ready

    while (1)
    {
        status = SF_DAL_Dev_ReadStatus(D, D->CMD->ReadReadyReg);

        if (0 == (status & D->StatusMap[SF_SR_BUSY]))
            break;
    }

    SF_DAL_FLAG_SUS_SET();

    RestoreIRQMask(savedMask);

    return FS_NO_ERROR;
}
#endif //(!defined(__NOR_FULL_DRIVER__) || defined(__MINI_BOOTLOADER__)) && defined(__UBL__)

//-----------------------------------------------------------------------------
/*!
  @brief
    Resumes any suspended erase operations

  @param[in] MTDData Pointer to the MTD driver data
  @param[in] BlockIndex Unused parameter, don't care

  @retval
    FS_NO_ERROR: Successful

  @remarks
    GPRAM utilization is 1. A device lock is not necessary.
*/

/*Mini Bootloader does not need to do Erase and Program Operation*/
/*Therefore, use dummy function to avoid mini Bootloader out of size*/
#if (!defined(__NOR_FULL_DRIVER__) || defined(__MINI_BOOTLOADER__)) && defined(__UBL__)
__sf_section_RAM int SF_DAL_ResumeErase(void *MTDData, kal_uint32 BlockIndex)
{
    return FS_UNSUPPORTED_DRIVER_FUNCTION;
}
#else //(!defined(__NOR_FULL_DRIVER__) || defined(__MINI_BOOTLOADER__)) && defined(__UBL__)
__sf_section_RAM int SF_DAL_ResumeErase(void *MTDData, kal_uint32 BlockIndex)
{
    SF_MTD_Data        *D=MTDData;

    SF_DAL_GetDevLock(D);
    SF_DAL_Dev_Resume(D);
    SF_DAL_FreeDevLock(D);

    return FS_NO_ERROR;
}
#endif //(!defined(__NOR_FULL_DRIVER__) || defined(__MINI_BOOTLOADER__)) && defined(__UBL__)
//-----------------------------------------------------------------------------
/*!
  @brief
    Erase / Lock / Unlock a block

  @param[in] MTDData Pointer to the MTD driver data
  @param[in] BlkAddr Pointer to the physical block base address
  @param[in] ACTION Can be one of ACTION_UNLOCK, ACTION_LOCK, or ACTION_ERASE.

  @retval
    FS_NO_ERROR: Successful
  @remarks
    GPRAM utilization is 1+3B. A device lock is not necessary.
*/
#if defined(__FOTA_ENABLE__)
__sf_section_RAM int SF_DAL_LockEraseBlkAddr(void *MTDData, void *BlkAddr, kal_uint32 ACTION)
{
    SF_MTD_Data        *D;

    if (ACTION_UNLOCK == ACTION || ACTION_LOCK == ACTION) return FS_NO_ERROR;

    SF_DAL_GetDevLock(D);

    if (ACTION_ERASE == ACTION)
    {
        SF_DAL_Dev_EraseBlock(D,(kal_uint32)BlkAddr);

        // 3. wait ready
        while (FS_FLASH_ERASE_BUSY == SF_DAL_CheckDeviceReady(D, 0)) // BlockIndex is useless for CheckDeviceReady_SST, pass 0 to it.
        {
            IntTest(2);
        }

        #if defined(__BASIC_LOAD_FLASH_TEST__)
        EraseNum++;
        #endif
    }
    else
    {
        MTD_SNOR_ASSERT(0, 0, 0, 0, NOR_MTD_UNSUPPORTED_FUNCTION);
    }

    SF_DAL_FreeDevLock(D);
    return FS_NO_ERROR;
}
#else
__sf_section_RAM int SF_DAL_LockEraseBlkAddr(void *MTDData, void *BlkAddr, kal_uint32 ACTION)
{
    return FS_NO_ERROR;
}
#endif

//-----------------------------------------------------------------------------
// [DAL] Lower Abstract
//-----------------------------------------------------------------------------

#if !defined(__NOR_LEAKAGE__)
/*
   Block unlock functions for non-leakage load.
*/

//-----------------------------------------------------------------------------
/*!
  @brief
    <SST> Block unlock procedure
  @param[in] MTDData Pointer to the MTD driver data
  @retval
    FS_NO_ERROR: Successful
  @remarks
    Caller: SF_DAL_IOCtrl()
    GPRAM utilization is 1+1B. A device lock is not necessary for GPRAM.
*/
#if defined(SF_DAL_SST)

__sf_section_RAM int SF_DAL_UnlockBlock_SST(void *MTDData)
{
    SF_MTD_Data    *D = (SF_MTD_Data*)MTDData;
    kal_uint32      byte_BPR, i;
    kal_uint32     *p_ram = (unsigned int*)RW_SFI_GPRAM_DATA;
    kal_uint32      savedMask;

    SF_DAL_GetDevLock(D);

    SF_DAL_Dev_WriteEnable(D);

    byte_BPR = (D->BPRBitCount + 7) / 8;

    savedMask = SaveAndSetIRQMask();

    // clear all block protection bits
    SFI_MacEnable();
    SFI_WriteReg32(p_ram++, SF_CMD_WBPR);           // including 3 bytes zeros

    for (i = 0; i < byte_BPR - 3; i += 4, p_ram++)  // 3 bytes are with command
    {
        SFI_WriteReg32(p_ram, 0);
    }

    SFI_WriteReg32(RW_SFI_MAC_OUTL, 1 + byte_BPR);
    SFI_WriteReg32(RW_SFI_MAC_INL , 0);
    SFI_MacWaitReady();

    RestoreIRQMask(savedMask);

#if defined(__BASIC_LOAD_FLASH_TEST__)
    // DEBUG: confirm results
    {
        kal_uint32 data;
        kal_uint32 word_BPR;
        kal_uint32 shift;

        savedMask = SaveAndSetIRQMask();
        SFI_MacEnable();
        SFI_WriteReg32(RW_SFI_GPRAM_DATA, SF_CMD_RBPR);
        SFI_WriteReg32(RW_SFI_MAC_OUTL, 1);
        SFI_WriteReg32(RW_SFI_MAC_INL , byte_BPR);
        SFI_MacWaitReady();
        RestoreIRQMask(savedMask);

        // Determine the number of DWORDs need to check
        word_BPR = (byte_BPR+4) >> 2;

        // Clear the command we send (SF_CMD_RBPR)
        data = SFI_ReadReg32(RW_SFI_GPRAM_DATA);
        data = data & 0xFFFFFF00;
        SFI_WriteReg32(RW_SFI_GPRAM_DATA, data);

        // Clear last DWORD
        p_ram = (kal_uint32*)RW_SFI_GPRAM_DATA;
        p_ram = p_ram + (word_BPR-1);
        data  = SFI_ReadReg32(p_ram);
        shift = (byte_BPR+1)&0x03;       // Remainder of total check bytes (ie. (byte_BPR+cmd) % 4 )
        shift = ((4-shift)&0x03) << 3;   // The number of MSB bits need to be shifted out
        data  = data << shift;
        SFI_WriteReg32(p_ram, data);

        for (p_ram = (kal_uint32*)RW_SFI_GPRAM_DATA, i = 0; i < word_BPR; p_ram++, i++)
        {
            data = SFI_ReadReg32(p_ram);
            MTD_SNOR_ASSERT(data == 0, 0, 0, 0, NOR_MTD_SF_WRITE_PROTECT_ERROR);
        }
    }
#endif   // __NOR_FLASH_HARDWARE_TEST__ && __MAUI_BASIC__

    SF_DAL_FreeDevLock(D);

    return FS_NO_ERROR;
}
#endif   // defined(SF_DAL_SST)

//-----------------------------------------------------------------------------
/*!
  @brief
    <MXIC><EON> Block unlock procedure
  @param[in] MTDData Pointer to the MTD driver data
  @retval
    FS_NO_ERROR: Successful
  @remarks
    Caller: SF_DAL_IOCtrl()
    GPRAM utilization is 1+1B. A device lock is not necessary for GPRAM.
*/
#if defined(SF_DAL_MXIC) || defined(SF_DAL_EON) || defined(SF_DAL_WINBOND)
__sf_section_RAM int SF_DAL_UnlockBlock_MXIC(void *MTDData)
{
    SF_MTD_Data    *D = (SF_MTD_Data*)MTDData;
    SF_MTD_CMD     *C = D->CMD;
    kal_uint32      data, savedMask;
    kal_int32       result;

    SF_DAL_GetDevLock(D);

    // write enable
    SF_DAL_Dev_WriteEnable(D);

    // Read status and check if WEL is latched
    data = SF_DAL_Dev_ReadStatus(D, C->ReadReadyReg);
    if (data & D->StatusMap[SF_SR_WEL] == 0) {
        SF_DAL_FreeDevLock(D);
        return FS_ACCESS_DENIED;
    }

    data = SF_DAL_Dev_ReadStatus(D, C->ReadBPReg);
    // Clear all block protect bits
    data = data & ~ ( D->StatusMap[SF_SR_BP] | D->StatusMap[SF_SR_SRWD] );

    // Add WRSR command
    data = ( (kal_uint32)C->WriteBPReg) |  (data << 8);

    // write status resgister
    savedMask = SaveAndSetIRQMask();
    SF_DAL_FLAG_BUSY_SET();
    SF_DAL_Dev_Command(D, data, 2);
    RestoreIRQMask(savedMask);

    do   {
        result = SF_DAL_CheckDeviceReady(D, 0);
    } while (FS_FLASH_ERASE_BUSY == result);

#if defined(__BASIC_LOAD_FLASH_TEST__)
    data = SF_DAL_Dev_ReadStatus(D, C->ReadBPReg);

    if (data & D->StatusMap[SF_SR_BP] )   {
        MTD_SNOR_ASSERT(data == 0, 0, 0, 0, NOR_MTD_SF_WRITE_PROTECT_ERROR);
    }
#endif

    SF_DAL_FreeDevLock(D);

    return FS_NO_ERROR;
}

#endif // defined(SF_DAL_MXIC) || defined(SF_DAL_EON) || defined(SF_DAL_WINBOND)

#endif // !__NOR_LEAKAGE__

//-----------------------------------------------------------------------------
/*!
  @brief
    Program Fail / Erase Fail check
  @param[in] MTDData Pointer to the MTD driver data
  @retval
    FS_NO_ERROR: Program/Erase successful, or fail check is not supported.
    RESULT_FLASH_FAIL: Program/Erase fail
  @remarks
    Caller: SF_DAL_CheckReadyAndResume, SF_DAL_CheckDeviceReady
    GPRAM utilization is 1+1B. A device lock is not necessary for GPRAM.
*/
__sf_section_RAM int SF_DAL_FailCheck(void *MTDData)
{
    SF_MTD_Data    *D = (SF_MTD_Data*)MTDData;
    kal_uint16     status;

#if defined(SF_DAL_GIGADEVICE)
    if (sf_dal_fix & sf_fix_gigadevice_b)
        SF_DAL_Dev_Command(D, SF_CMD_GIGADEVICE_HPM_ENTER_CMD, 4);
#endif

    if (D->CMD->ReadFailReg)    {
        status=SF_DAL_Dev_ReadStatus(D, D->CMD->ReadFailReg);
        if (status & D->StatusMap[SF_SR_FAIL])    {
            return RESULT_FLASH_FAIL;
        }
    }
    return FS_NO_ERROR;
}

//-----------------------------------------------------------------------------
// [DAL] Device Driver Componets (Interface to lower driver or physical device)
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
/*!
  @brief
    Read 3 bytes ID (Vendor + Density + Device)

  @param[in] MTDData Pointer to the MTD driver data
  @param[out] id The pointer to the array that ID to be stored
*/
__sf_section_RAM void SF_DAL_Dev_ReadID(SF_MTD_Data *D, kal_uint8 *id)
{
    kal_uint8 cmd;

    if (SFI_DevMode!=0)  {
        cmd=D->CMD->ReadID_QPI;
    }
    else {
        cmd=D->CMD->ReadID_SPI;
    }
    SF_DAL_Dev_Command_Ext(&cmd, id, 1, SF_FLASH_ID_LENGTH);
}

//-----------------------------------------------------------------------------
/*!
  @brief
    Command wrapper function <Suspend>

  @param[in] MTDData Pointer to the MTD driver data
*/
__sf_section_RAM void SF_DAL_Dev_Suspend(SF_MTD_Data *D)
{
    kal_uint32 savedMask;
    kal_uint32 currtime, difftime;

    SF_Suspend_Count();
    SF_Suspend_Start();
    if (sf_dal_resume_time!=NOR_DEFAULT_RESUME_TIME)    {
        currtime=ust_get_current_time();
        difftime=ust_get_duration(sf_dal_resume_time, currtime);
        if (difftime < D->SuspendLatency)    {
            DelayAWhile_UST(D->SuspendLatency - difftime);
        }
    }

    savedMask = SaveAndSetIRQMask();
    SFI_Dev_Command(D->CMD->Suspend);
#if defined(SF_DAL_GIGADEVICE)
    if (sf_dal_fix & sf_fix_gigadevice_b)
        SFI_Dev_Command(SF_CMD_GIGADEVICE_HPM_ENTER);
#endif
    RestoreIRQMask(savedMask);
}

//-----------------------------------------------------------------------------
/*!
  @brief
    Command wrapper function <Resume>

  @param[in] MTDData Pointer to the MTD driver data
*/
__sf_section_RAM void SF_DAL_Dev_Resume(SF_MTD_Data *D)
{
    kal_uint32 savedMask;

    savedMask = SaveAndSetIRQMask();
#if defined(SF_DAL_GIGADEVICE)
    if (sf_dal_fix & sf_fix_gigadevice_b)
        SFI_Dev_Command(SF_CMD_GIGADEVICE_HPM_EXIT);
#endif
    SFI_Dev_Command(D->CMD->Resume);
    if (D->SuspendLatency!=0) {
        sf_dal_resume_time=ust_get_current_time();
    }
    SF_Suspend_End();
    SF_DAL_FLAG_SUS_CLR();
    RestoreIRQMask(savedMask);
}

//-----------------------------------------------------------------------------
/*!
  @brief
    Command wrapper function <WriteEnable>

  @param[in] MTDData Pointer to the MTD driver data
*/
__sf_section_RAM void SF_DAL_Dev_WriteEnable(SF_MTD_Data *D)
{
    SF_DAL_Dev_Command(D, D->CMD->WriteEnable, 1);
}

//-----------------------------------------------------------------------------
/*!
  @brief
    Command wrapper function <EraseBlock>
  @param[in] MTDData Pointer to the MTD driver data
*/

    /*Mini Bootloader does not need to do Erase and Program Operation*/
    /*Therefore, use dummy function to avoid mini Bootloader out of size*/
#if (!defined(__NOR_FULL_DRIVER__) || defined(__MINI_BOOTLOADER__)) && defined(__UBL__)
__sf_section_RAM void SF_DAL_Dev_EraseBlock(SF_MTD_Data *D, kal_uint32 addr){}
#else //(!defined(__NOR_FULL_DRIVER__) || defined(__MINI_BOOTLOADER__)) && defined(__UBL__)
__sf_section_RAM void SF_DAL_Dev_EraseBlock(SF_MTD_Data *D, kal_uint32 addr)
{
    kal_uint32 savedMask;

    if (!(sf_dal_fix & sf_fix_gigadevice_b))   {
        SF_DAL_Dev_WriteEnable(D);
    }

    TimeStampClear();

    savedMask = SaveAndSetIRQMask();

#if defined(SF_DAL_GIGADEVICE)
    if (sf_dal_fix & sf_fix_gigadevice_b)   {
        SFI_Dev_Command(D->CMD->WriteEnable);
    }
#endif

    SF_Erase_Start();
    SF_DAL_FLAG_BUSY_SET();
    SFI_Dev_CommandAddress(D->CMD->Erase, addr, D->AddressCycle);

#if defined(SF_DAL_WINBOND) && defined(SF_FIX_WINBOND_CV)
    sf_fix_winbond_cv_resumed=0;
#endif

    RestoreIRQMask(savedMask);
}
#endif //(!defined(__NOR_FULL_DRIVER__) || defined(__MINI_BOOTLOADER__)) && defined(__UBL__)

//-----------------------------------------------------------------------------
/*!
  @brief
    Generic reads a status register (SR)

  @param[in] cmd The SR read command, it can be ready SR, security SR, or suspend SR
  @retval Status register's state
*/

__sf_section_RAM kal_uint32 SF_DAL_Dev_ReadStatus(SF_MTD_Data *D, kal_uint8 cmd)
{
    kal_uint32 savedMask;
    kal_uint32 result;

    savedMask = SaveAndSetIRQMask();
    SFI_MacEnable();
    SFI_WriteReg32(RW_SFI_GPRAM_DATA, cmd);
    SFI_WriteReg32(RW_SFI_MAC_OUTL, 1);
    SFI_WriteReg32(RW_SFI_MAC_INL , 1);
    SFI_MacWaitReady();
    result=(unsigned char)(SFI_ReadReg32(RW_SFI_GPRAM_DATA) >> 8);
    RestoreIRQMask(savedMask);

    return result;
}

//-----------------------------------------------------------------------------
/*!
  @brief
    Issues a command to serial Flash
  @param[in] The command to be issued
  @remarks
    Mask out IRQs to prevent faulty read in MAC mode
*/
__sf_section_RAM void SF_DAL_Dev_Command(SF_MTD_Data *D, const kal_uint32 cmd, kal_uint8 outlen)
{
    kal_uint32 savedMask;

    savedMask = SaveAndSetIRQMask();
    SFI_MacEnable();
    SFI_WriteReg32(RW_SFI_GPRAM_DATA, cmd);
    SFI_WriteReg32(RW_SFI_MAC_OUTL, outlen);
    SFI_WriteReg32(RW_SFI_MAC_INL , 0);
    SFI_MacWaitReady();
    RestoreIRQMask(savedMask);
    return;
}

//-----------------------------------------------------------------------------
/*!
  @brief
    Issue generic command to serial Flash, and read results.

  @param[in] cmd Pointer to the commands that to be sent
  @param[out] data Pointer to the data buffer that to be stored
  @param[in] outl Length of commands (in bytes)
  @param[in] intl Length of read data
*/
__sf_section_RAM void SF_DAL_Dev_Command_Ext(kal_uint8 *cmd, kal_uint8 *data, const kal_uint16 outl, const kal_uint16 inl)
{
    kal_uint32 savedMask;

    savedMask = SaveAndSetIRQMask();
    SFI_Dev_Command_Ext(cmd, data, outl, inl);
    RestoreIRQMask(savedMask);
    return;
}

#ifdef __SECURITY_OTP__

#if defined(SF_DAL_MXIC) || defined(SF_DAL_SST)
//-----------------------------------------------------------------------------
/*!
  @brief

  @param[in] DriveData Pointer to the MTD driver data

  @see
    SF_DAL_OTPAccess()

  @retval
    FS_NO_ERROR: no error
*/
__sf_section_RAM int SF_DAL_OTPLock_MXIC(void *MTDData)
{
    kal_uint32           savedMask;
    kal_int32            result;
    SF_MTD_Data         *D = (SF_MTD_Data *)MTDData;

    // Asserts, if the device has not mounted yet.
    ASSERT((~D->Signature == (kal_uint32)D->RegionInfo));

    // Write Lock Register
    SF_DAL_GetDevLock(D);

    savedMask = SaveAndSetIRQMask();
    SF_DAL_Dev_WriteEnable(D);
    SF_DAL_Dev_Command(D, D->CMD->OTPLock, 1);
    RestoreIRQMask(savedMask);

    // Wait ready
    do   {
        result = SF_DAL_CheckDeviceReady(D, 0);
    } while (FS_FLASH_ERASE_BUSY == result);

    SF_DAL_FreeDevLock(D);

    return FS_NO_ERROR;
}
#endif  // SF_DAL_MXIC || SF_DAL_SST

#if defined(SF_DAL_MXIC)
//-----------------------------------------------------------------------------
/*!
  @brief

  @param[in] MTDData Pointer to the MTD driver data
  @param[in] Offset The start address of the OTP registers to be read (in bytes)
  @param[in] BufferPtr: The data buffer that OTP-data to be stored
  @param[in] Length Transfer length, it shall not exceeds the length of OTP registers (in bytes)

  @see
    OTPAccess_MXIC()

  @retval
    FS_NO_ERROR: no error
    FS_FLASH_OTP_OVERSCOPE: writing range is out of OTP range
    FS_FLASH_OTP_LOCK_ALREADY: OTP area is already locked

  @remarks
    This function shall only invoked before MAUI initialization (ex: bootloader),
    Otherwise, the caller must be aware of 60qbits assertion in MAUI.
*/
__sf_section_RAM int SF_DAL_OTPWrite_MXIC(void *MTDData, kal_uint32 Offset, void * BufferPtr, kal_uint32 Length)
{
    kal_uint32           savedMask;
    kal_uint32           i;
    kal_uint32           cmd;
    kal_uint32           optr;
    kal_uint8           *bptr;
    SF_MTD_Data         *D = (SF_MTD_Data *)MTDData;
    kal_uint32           status;

    // Asserts, if the device has not mounted yet.
    ASSERT((~D->Signature == (kal_uint32)D->RegionInfo));

    // Check if the device is already locked
    status=SF_DAL_Dev_ReadStatus(D, D->CMD->ReadSecurityReg);

    if (status & D->StatusMap[SF_SR_OTPLOCK]) {
        return FS_FLASH_OTP_LOCK_ALREADY;
    }

    // check if read scope is out of range
    if (0 == Length) {
        return FS_NO_ERROR;
    }
    if ( (Offset > D->OTPLength) ||
         (Offset+ Length)> D->OTPLength )
    {
       return FS_FLASH_OTP_OVERSCOPE;
    }

    bptr = BufferPtr;
    optr = D->OTPBase + Offset;

    SF_DAL_GetDevLock(D);
    // Program data into OTP registers.
    // In order to avoid 60qbits assert, program 1 byte at a time.
    // Keep the operation atomic.
    for (i=0; i<Length; i++, bptr++, optr++)    {
        savedMask = SaveAndSetIRQMask();
        // Enter Secured OTP (ENSO) mode
        SF_DAL_Dev_Command(D, D->CMD->OTPEnter, 1);
        SF_DAL_Dev_WriteEnable(D);
        cmd = (SFI_ReverseByteOrder(optr) & 0xFFFFFF00) | D->CMD->OTPProg;
        SFI_WriteReg32(RW_SFI_GPRAM_DATA,  cmd);
        SFI_WriteReg32(RW_SFI_GPRAM_DATA+4, *bptr);
        SFI_WriteReg32(RW_SFI_MAC_OUTL, 5);
        SFI_WriteReg32(RW_SFI_MAC_INL , 0);
        SFI_MacEnable();
        SFI_MacWaitReady();
        // Wait Device Ready
        do {
            status = SF_DAL_Dev_ReadStatus(D, D->CMD->ReadReadyReg);
        } while(status & D->StatusMap[SF_SR_BUSY]);
        // Leave Secured OTP (ENSO) mode
        SF_DAL_Dev_Command(D, D->CMD->OTPExit, 1);
        RestoreIRQMask(savedMask);
    }
    SF_DAL_FreeDevLock(D);

    return FS_NO_ERROR;
}

//-----------------------------------------------------------------------------
/*!
  @brief

  @param[in] MTDData Pointer to the MTD driver data
  @param[in] Offset The start address of the OTP registers to be read (in bytes)
  @param[in] BufferPtr: The data buffer that OTP-data to be stored
  @param[in] Length Transfer length, it shall not exceeds the length of OTP registers (in bytes)

  @see
    OTPAccess_MXIC()

  @retval
    FS_NO_ERROR: Operation successful
    FS_FLASH_OTP_OVERSCOPE: Out of OTP writing range
*/
__sf_section_RAM int SF_DAL_OTPRead_MXIC(void *MTDData, kal_uint32 Offset, void * BufferPtr, kal_uint32 Length)
{
    kal_uint32           savedMask;
    SF_MTD_Data         *D = (SF_MTD_Data *)MTDData;
    kal_int32            i, j;      // iterator
    kal_uint8           *bptr;   // pointer to BufferPtr
    kal_uint8           *optr;   // offset to OTP Registers

    // Asserts, if the device has not mounted yet.
    ASSERT((~D->Signature == (kal_uint32)D->RegionInfo));

    /* check if read scope is out of range */
    if (0 == Length) {
        return FS_NO_ERROR;
    }
    if ( (Offset > D->OTPLength) ||
         (Offset+ Length)> D->OTPLength )
    {
       return FS_FLASH_OTP_OVERSCOPE;
    }

    optr = D->BaseAddr + D->OTPBase + Offset;
    bptr = BufferPtr;

    // To avoid 60qbits assert, read most 32 bytes at a time.
    // => The size of SFC read buffer is 32 bytes
    for (i=0; i<Length; i+=32)   {
        savedMask = SaveAndSetIRQMask();
        // Enter Secured OTP (ENSO) mode
        SF_DAL_Dev_Command(D, D->CMD->OTPEnter, 1);
        // Read Secured OTP
        // [Note]
        // 1. Always use FS base address as the Flash base addr.
        //    =>After entering OTP mode, OTP data are available on every block offsets
        //      (depends on vendor).
        //    =>FS area are not cached, so that there's no need to disable caches.
        // 2. Do not use memcpy(), because it is an XIP function on Flash.
        for (j=i; j<i+32 && j<Length; j++, bptr++, optr++)  {
            *bptr = *optr;
        }
        // Leave Secured OTP (ENSO) mode
        SF_DAL_Dev_Command(D, D->CMD->OTPExit, 1);
        RestoreIRQMask(savedMask);
    }

    return FS_NO_ERROR;
}
#endif // SF_DAL_MXIC

#if defined(SF_DAL_WINBOND)
//-----------------------------------------------------------------------------
/*!
  @brief

  @param[in] DriveData Pointer to the MTD driver data

  @see
    SF_DAL_OTPAccess()

  @retval
    FS_NO_ERROR: no error
*/
__sf_section_RAM int SF_DAL_OTPLock_WINBOND(void *MTDData)
{
    kal_uint32          data_SR1, data_SR2, savedMask;
    kal_int32           result;
    kal_uint32          cmd;
    SF_MTD_Data         *D = (SF_MTD_Data *)MTDData;

    // Asserts, if the device has not mounted yet.
    ASSERT((~D->Signature == (kal_uint32)D->RegionInfo));

    SF_DAL_GetDevLock(D);

    // write enable
    SF_DAL_Dev_WriteEnable(D);

    data_SR1 = SF_DAL_Dev_ReadStatus(D, D->CMD->ReadBPReg);
    data_SR2 = SF_DAL_Dev_ReadStatus(D, D->CMD->ReadSuspendReg);

    cmd = D->CMD->WriteBPReg;
    data_SR1 = data_SR1 << 8;
    data_SR2 = data_SR2 | SF_WINBOND_SSR_OTP;

    cmd = (cmd<<16) | data_SR1 | data_SR2;

    // write status resgister
    savedMask = SaveAndSetIRQMask();
    SF_DAL_FLAG_BUSY_SET();
    SFI_Dev_Command(cmd);
    RestoreIRQMask(savedMask);

    do   {
        result = SF_DAL_CheckDeviceReady(D, 0);
    } while (FS_FLASH_ERASE_BUSY == result);

    SF_DAL_FreeDevLock(D);

    return FS_NO_ERROR;
}

//-----------------------------------------------------------------------------
/*!
  @brief

  @param[in] MTDData Pointer to the MTD driver data
  @param[in] Offset The start address of the OTP registers to be read (in bytes)
  @param[in] BufferPtr: The data buffer that OTP-data to be stored
  @param[in] Length Transfer length, it shall not exceeds the length of OTP registers (in bytes)

  @see
    OTPAccess()

  @retval
    FS_NO_ERROR: no error
    FS_FLASH_OTP_OVERSCOPE: writing range is out of OTP range
    FS_FLASH_OTP_LOCK_ALREADY: OTP area is already locked

  @remarks
    The physical discontinuous address is covered by the funciton. It's continuous to upper layer users.
*/
__sf_section_RAM int SF_DAL_OTPWrite_WINBOND(void *MTDData, kal_uint32 Offset, void * BufferPtr, kal_uint32 Length)
{
    kal_uint32          savedMask;
    kal_uint32          i;
    kal_uint32          cmd;
    kal_uint32          optr_logical, optr_physical;  //offset pointer
    kal_uint8           *bptr;
    SF_MTD_Data         *D = (SF_MTD_Data *)MTDData;
    kal_uint32          status;
    kal_uint32          save_QPI;

    // Asserts, if the device has not mounted yet.
    ASSERT((~D->Signature == (kal_uint32)D->RegionInfo));

    // Check if the device is already locked
    status=SF_DAL_Dev_ReadStatus(D, D->CMD->ReadSecurityReg);
    if (status & D->StatusMap[SF_SR_OTPLOCK]) {
        return FS_FLASH_OTP_LOCK_ALREADY;
    }

    // check if read scope is out of range
    if (0 == Length) {
        return FS_NO_ERROR;
    }
    if ( (Offset > D->OTPLength) ||
         (Offset+ Length)> D->OTPLength )
    {
       return FS_FLASH_OTP_OVERSCOPE;
    }

    bptr = BufferPtr;
    optr_logical = D->OTPBase + Offset;

    SF_DAL_GetDevLock(D);
    // Program data into OTP registers.
    // In order to avoid 60qbits assert, program 1 byte at a time.
    // Keep the operation atomic.
    for (i=0; i<Length; i++, bptr++, optr_logical++)    {
        //make the upper application transparent to the physical address
        optr_physical = ((optr_logical<<4)&0xF000)|(optr_logical&0x00FF);
        cmd = (SFI_ReverseByteOrder(optr_physical) & 0xFFFFFF00) | D->CMD->OTPProg;
        //Save current mode
		save_QPI = SFI_DevMode;
        //switch to SPI mode
        savedMask = SaveAndSetIRQMask();
        // Note: Winbond 0xFF command reserves wrap settings
        SFI_Dev_Command(D->CMD->OTPEnter);  // Switch device to SPI mode
        SFI_SetDevMode(0); // Switch SFC to SPI mode

        //program data
        SF_DAL_Dev_WriteEnable(D);
        SFI_WriteReg32(RW_SFI_GPRAM_DATA,  cmd);
        SFI_WriteReg32(RW_SFI_GPRAM_DATA+4, *bptr);
        SFI_WriteReg32(RW_SFI_MAC_OUTL, 5);
        SFI_WriteReg32(RW_SFI_MAC_INL , 0);
        SFI_MacEnable();
        SFI_MacWaitReady();

        // Wait Device Ready
        do {
            status = SF_DAL_Dev_ReadStatus(D, D->CMD->ReadReadyReg);
        } while(status & D->StatusMap[SF_SR_BUSY]);

        //switch to previous mode
        SFI_Dev_Command(D->CMD->OTPExit);  // Switch device to QPI mode
        SFI_SetDevMode(save_QPI);  // Switch SFC to QPI mode
        RestoreIRQMask(savedMask);
    }
    SF_DAL_FreeDevLock(D);

    return FS_NO_ERROR;
}

//-----------------------------------------------------------------------------
/*!
  @brief

  @param[in] MTDData Pointer to the MTD driver data
  @param[in] Offset The start address of the OTP registers to be read (in bytes)
  @param[in] BufferPtr: The data buffer that OTP-data to be stored
  @param[in] Length Transfer length, it shall not exceed the length of OTP registers (in bytes)

  @see
    OTPAccess_MXIC()

  @retval
    FS_NO_ERROR: Operation successful
    FS_FLASH_OTP_OVERSCOPE: Out of OTP writing range

  @remarks
    The physical discontinuous address is covered by the funciton. It's continuous to upper layer users.
*/
__sf_section_RAM int SF_DAL_OTPRead_WINBOND(void *MTDData, kal_uint32 Offset, void * BufferPtr, kal_uint32 Length)
{
    kal_uint32          savedMask;
    SF_MTD_Data         *D = (SF_MTD_Data *)MTDData;
    kal_int32           i;
    kal_uint8           *bptr;   // pointer to BufferPtr
    kal_uint32          optr_logical, optr_physical;  //offset pointer
    kal_uint32           cmd;
    kal_uint32          save_QPI;

    // Asserts, if the device has not mounted yet.
    ASSERT((~D->Signature == (kal_uint32)D->RegionInfo));

    /* check if read scope is out of range */
    if (0 == Length) {
        return FS_NO_ERROR;
    }
    if ( (Offset > D->OTPLength) ||
         (Offset+ Length)> D->OTPLength )
    {
       return FS_FLASH_OTP_OVERSCOPE;
    }

    bptr = BufferPtr;
    optr_logical = D->OTPBase + Offset;

    for (i=0; i<Length; i++, bptr++, optr_logical++)  {
        //make the upper application transparent to the physical address
        optr_physical = ((optr_logical<<4)&0xF000)|(optr_logical&0x00FF);
        cmd = (SFI_ReverseByteOrder(optr_physical) & 0xFFFFFF00) | D->CMD->OTPRead;

        //Save current mode
		save_QPI = SFI_DevMode;

        //switch to SPI mode
        savedMask = SaveAndSetIRQMask();
        SFI_Dev_Command(D->CMD->OTPEnter);  // Switch the device to SPI mode

        SFI_SetDevMode(0); // Switch SFC to SPI mode        

        //Read data
        SFI_WriteReg32(RW_SFI_GPRAM_DATA,  cmd);
        SFI_WriteReg32(RW_SFI_MAC_OUTL, 4);
        SFI_WriteReg32(RW_SFI_MAC_INL , 2);//read 1 byte + 1 dummy cycle
        SFI_MacEnable();
        SFI_MacWaitReady();

        *bptr = SFI_ReadReg8(RW_SFI_GPRAM_DATA+5);

        //switch to previous mode
        SFI_Dev_Command(D->CMD->OTPExit); // Switch the device to QPI mode
        SFI_SetDevMode(save_QPI); // Switch SFC to QPI mode
        RestoreIRQMask(savedMask);
    }

    return FS_NO_ERROR;
}
#endif // SF_DAL_WINBOND

#if defined(SF_DAL_SST)

//-----------------------------------------------------------------------------
/*!
  @brief

  @param[in] MTDData Pointer to the MTD driver data
  @param[in] Offset The start address of the OTP registers to be read (in bytes)
  @param[in] BufferPtr: The data buffer that OTP-data to be stored
  @param[in] Length Transfer length, it shall not exceeds the length of OTP registers (in bytes)

  @see
    OTPAccess_MXIC()

  @retval
    FS_NO_ERROR: no error
    FS_FLASH_OTP_OVERSCOPE: writing range is out of OTP range
    FS_FLASH_OTP_LOCK_ALREADY: OTP area is already locked

  @remarks
    This function shall only invoked before MAUI initialization (ex: bootloader),
    Otherwise, the caller must be aware of 60qbits assertion in MAUI.
    The physical discontinuous address is covered by the funciton. It's continuous to upper layer users.
*/
__sf_section_RAM int SF_DAL_OTPWrite_SST(void *MTDData, kal_uint32 Offset, void * BufferPtr, kal_uint32 Length)
{
    kal_uint32           savedMask;
    kal_uint32           i;
    kal_uint32           cmd;
    //kal_uint32           optr;
    kal_uint32          optr;  //offset pointer
    kal_uint8           *bptr;
    SF_MTD_Data         *D = (SF_MTD_Data *)MTDData;
    kal_uint32           status;

    // Asserts, if the device has not mounted yet.
    ASSERT((~D->Signature == (kal_uint32)D->RegionInfo));

    // Check if the device is already locked
    status=SF_DAL_Dev_ReadStatus(D, D->CMD->ReadSecurityReg);

    if (status & D->StatusMap[SF_SR_OTPLOCK]) {
        return FS_FLASH_OTP_LOCK_ALREADY;
    }

    // check if read scope is out of range
    if (0 == Length) {
        return FS_NO_ERROR;
    }
    if ( (Offset > D->OTPLength) ||
         (Offset+ Length)> D->OTPLength )
    {
       return FS_FLASH_OTP_OVERSCOPE;
    }

    bptr = BufferPtr;
    optr = D->OTPBase + Offset;

    SF_DAL_GetDevLock(D);
    // Program data into OTP registers.
    // In order to avoid 60qbits assert, program 1 byte at a time.
    // Keep the operation atomic.
    for (i=0; i<Length; i++, bptr++, optr++)    {
        cmd = (*bptr << 16 ) | (optr << 8) | D->CMD->OTPProg;
        savedMask = SaveAndSetIRQMask();

        //program data
        SF_DAL_Dev_WriteEnable(D);
        SFI_WriteReg32(RW_SFI_GPRAM_DATA,  cmd);
        SFI_WriteReg32(RW_SFI_MAC_OUTL, 3);// 1 cmd + 1 address + 1 data
        SFI_WriteReg32(RW_SFI_MAC_INL , 0);
        SFI_MacEnable();
        SFI_MacWaitReady();
        // Wait Device Ready
        do {
            status = SF_DAL_Dev_ReadStatus(D, D->CMD->ReadReadyReg);
        } while(status & D->StatusMap[SF_SR_BUSY]);

        RestoreIRQMask(savedMask);
    }
    SF_DAL_FreeDevLock(D);

    return FS_NO_ERROR;
}

//-----------------------------------------------------------------------------
/*!
  @brief

  @param[in] MTDData Pointer to the MTD driver data
  @param[in] Offset The start address of the OTP registers to be read (in bytes)
  @param[in] BufferPtr: The data buffer that OTP-data to be stored
  @param[in] Length Transfer length, it shall not exceeds the length of OTP registers (in bytes)

  @see
    OTPAccess_MXIC()

  @retval
    FS_NO_ERROR: Operation successful
    FS_FLASH_OTP_OVERSCOPE: Out of OTP writing range

  @remarks
    The physical discontinuous address is covered by the funciton. It's continuous to upper layer users.
*/
__sf_section_RAM int SF_DAL_OTPRead_SST(void *MTDData, kal_uint32 Offset, void * BufferPtr, kal_uint32 Length)
{
    kal_uint32           savedMask;
    SF_MTD_Data         *D = (SF_MTD_Data *)MTDData;
    kal_int32            i;
    kal_uint8           *bptr, *indata_ptr;   // pointer to BufferPtr
    kal_uint32          optr;  //offset pointer
    kal_uint32           cmd;
    // Asserts, if the device has not mounted yet.
    ASSERT((~D->Signature == (kal_uint32)D->RegionInfo));

    /* check if read scope is out of range */
    if (0 == Length) {
        return FS_NO_ERROR;
    }
    if ( (Offset > D->OTPLength) ||
         (Offset+ Length)> D->OTPLength )
    {
       return FS_FLASH_OTP_OVERSCOPE;
    }

    bptr = BufferPtr;
    optr = D->OTPBase + Offset;
    cmd = (optr<<8) | D->CMD->OTPRead;

    savedMask = SaveAndSetIRQMask();

    //Read data
    SFI_WriteReg32(RW_SFI_GPRAM_DATA,  cmd);
    SFI_WriteReg32(RW_SFI_MAC_OUTL, 2);// 1 cmd + 1 address cycle
    SFI_WriteReg32(RW_SFI_MAC_INL , Length+2);//read length + 2 dummy cycles
    SFI_MacEnable();
    SFI_MacWaitReady();

    indata_ptr = (kal_uint8*)(RW_SFI_GPRAM_DATA+4);//shift out 1 cmd, 1 address and 2 dummy cycles
    for (i=0; i<Length; i++, bptr++, indata_ptr++)  {
        *bptr = *indata_ptr;
    }

    RestoreIRQMask(savedMask);

    return FS_NO_ERROR;
}
#endif
//-----------------------------------------------------------------------------
/*!
  @brief
    Query the length of OTP Registers

  @param[in] MTDData Pointer to the MTD driver data
  @param[out] LengthPtr Pointer to the unsigned integer to be stored

  @see
    OTPAccess_MXIC()

  @retval
    Always FS_NO_ERROR
*/
__sf_section_RAM int SF_DAL_OTPQueryLength(void *MTDData, UINT *LengthPtr)
{
    SF_MTD_Data         *D = (SF_MTD_Data *)MTDData;
    *LengthPtr = D->OTPLength;
     return FS_NO_ERROR;
}

//-----------------------------------------------------------------------------
/*!
  @brief
    Access one time programmable (OTP) registers, the operations  can be one of
    FS_OTP_READ, FS_OTP_WRITE, or FS_OTP_LOCK. The operation enumerations are
    defined in flash_mtd_sf_dal.h.

  @param[in] MTDData Pointer to the MTD driver data
  @param[in] accesstype FS_OTP_READ, FS_OTP_WRITE, or FS_OTP_LOCK
  @param[in] Offset The start address of the OTP registers to be accessed (in bytes)
  @param[in] BufferPtr: The data buffer that OTP-data to be stored
  @param[in] Length Transfer length, it shall not exceed the length of OTP registers (in bytes)

  @see
    OTPAccess_MXIC()

  @retval
    FS_UNSUPPORTED_DRIVER_FUNCTION: The driver/deivce does not support OTP.
    FS_FLASH_OTP_OVERSCOPE: writing range is out of OTP range
    FS_FLASH_OTP_LOCK_ALREADY: OTP area is already locked
    FS_NO_ERROR: Operation Successful.

  @remarks
    Once OTP locked, the OTP registers are no longer writable, and FS_OTP_WRITE will
    return FS_FLASH_OTP_LOCK_ALREADY.

*/
__sf_section_RAM int SF_DAL_OTPAccess(void *MTDData, int accesstype, UINT Offset, void * BufferPtr, UINT Length)
{
    SF_MTD_Data         *D = (SF_MTD_Data *)MTDData;

    if (D->OTPLength==0)    {
        return FS_UNSUPPORTED_DRIVER_FUNCTION;
    }

    switch (accesstype)  {
        case FS_OTP_READ:
            return D->OTPRead(D, Offset, BufferPtr, Length);
        case FS_OTP_WRITE:
            return D->OTPWrite(D, Offset, BufferPtr, Length);
        case FS_OTP_LOCK:
            return D->OTPLock(D);
        default:
            break;
   }

   return FS_UNSUPPORTED_DRIVER_FUNCTION;
}
#endif //__SECURITY_OTP__

//-----------------------------------------------------------------------------
// Leckage Workaround Codes
//-----------------------------------------------------------------------------
#if defined(__NOR_LEAKAGE__)


//-----------------------------------------------------------------------------
/*!
  @brief
      Initialize and Mount the MTD driver in INIT stage
  @param[in] driver Pointer to the driver-interface
  @param[in] data Pointer to the driver-data
  @param[in] baseaddr Base address of the serial Flash
*/

/*Mini Bootloader does not need to do Erase and Program Operation*/
/*Therefore, use dummy function to avoid mini Bootloader out of size*/
#if (!defined(__NOR_FULL_DRIVER__) || defined(__MINI_BOOTLOADER__)) && defined(__UBL__)
__sf_section_SECOND_PART kal_int32 SF_DAL_Mount_Driver_EMIINIT(NOR_MTD_Driver *driver, SF_MTD_Data *D, kal_uint32 baseaddr)
{
    return FS_UNSUPPORTED_DRIVER_FUNCTION;
}
#else //(!defined(__NOR_FULL_DRIVER__) || defined(__MINI_BOOTLOADER__)) && defined(__UBL__)
__sf_section_SECOND_PART kal_int32 SF_DAL_Mount_Driver_EMIINIT(NOR_MTD_Driver *driver, SF_MTD_Data *D, kal_uint32 baseaddr)
{
    kal_int32 result;
    kal_uint8 cmd;

    D->BaseAddr = (kal_uint8*)baseaddr;

    // Common Initiailzation
    SF_DAL_Init_Common(driver, D);

    cmd=SF_CMD_READ_ID_QPI;
    SFI_Dev_Command_Ext(&cmd, D->FlashID, 1, SF_FLASH_ID_LENGTH);

    if (D->FlashID[0]==0x00 || D->FlashID[0]==0xFF || (CMEM_EMIINIT_CheckValidDeviceID(D->FlashID) == KAL_FALSE)) {
        cmd=SF_CMD_READ_ID;
        SFI_Dev_Command_Ext(&cmd, D->FlashID, 1, SF_FLASH_ID_LENGTH);
    }

    D->UniformBlock=EMIINIT_CMEM_NOR_GetUniformBlock();

    // Policy Specific Initialization
    // (None)

    // Vendor Specific Initialization
    result = SF_DAL_Init_Vendor(driver, D);
    if (result != FS_NO_ERROR) return result;

    // Resume previous suspend operation if any
    SFI_Dev_Command(D->CMD->Resume);
#if defined(SF_DAL_WINBOND) && defined(SF_FIX_WINBOND_DW)
    SFI_Dev_Command(D->CMD->Resume);
#endif

    SF_DAL_Dev_WaitReady_EMIINIT(D);

#if defined(SF_BR_BUSY_WAIT)
    if ( (SFI_DevMode & SFI_QPI_EN) ==0)   {
        kal_uint32 i;
        // Reset NV Reg
        i   = *SF_NVREG & 0xFFFF0000;
        i  |= (SF_BUSY | SF_4S);
        SFI_WriteReg32(SF_NVREG, i);
    }
#endif // SF_BR_BUSY_WAIT

    D->UnlockBlock(D);

    return result;
}
#endif //(!defined(__NOR_FULL_DRIVER__) || defined(__MINI_BOOTLOADER__)) && defined(__UBL__)


//-----------------------------------------------------------------------------
/*!
  @brief
    Wait device ready in init stage.
  @param[in] MTDData Pointer to the MTD driver data
*/
__sf_section_EMIINITCODE void SF_DAL_Dev_WaitReady_EMIINIT(SF_MTD_Data *D)
{
    SF_Status    status;
    do   {
        SFI_Dev_Command_Ext(&D->CMD->ReadReadyReg, &status, 1, 1);
    } while (0 != (status & D->StatusMap[SF_SR_BUSY]));
}

/*
   Block unlock functions for leakage load.
*/

//-----------------------------------------------------------------------------
/*!
  @brief
    <SST> Block unlock procedure
  @param[in] MTDData Pointer to the MTD driver data
  @retval
    FS_NO_ERROR: Successful
  @remarks
    Caller: SF_DAL_IOCtrl()
    GPRAM utilization is 1+1B. A device lock is not necessary for GPRAM.
*/
#if defined(SF_DAL_SST)
__sf_section_EMIINITCODE int SF_DAL_UnlockBlock_SST(void *MTDData)
{
    SF_MTD_Data    *D = (SF_MTD_Data*)MTDData;
    kal_uint32      byte_BPR, i;
    kal_uint32     *p_ram = (unsigned int*)RW_SFI_GPRAM_DATA;

    SFI_Dev_Command(D->CMD->WriteEnable);
    SF_DAL_Dev_WaitReady_EMIINIT(D);

    byte_BPR = (D->BPRBitCount + 7) / 8;

    // clear all block protection bits
    SFI_MacEnable();
    SFI_WriteReg32(p_ram++, SF_CMD_WBPR);           // including 3 bytes zeros

    for (i = 0; i < byte_BPR - 3; i += 4, p_ram++)  // 3 bytes are with command
    {
        SFI_WriteReg32(p_ram, 0);
    }

    SFI_WriteReg32(RW_SFI_MAC_OUTL, 1 + byte_BPR);
    SFI_WriteReg32(RW_SFI_MAC_INL , 0);
    SFI_MacWaitReady();
    SF_DAL_Dev_WaitReady_EMIINIT(D);

    return FS_NO_ERROR;
}

#endif   // defined(SF_DAL_SST)

//-----------------------------------------------------------------------------
/*!
  @brief
    <MXIC><EON> Block unlock procedure
  @param[in] MTDData Pointer to the MTD driver data
  @retval
    FS_NO_ERROR: Successful
  @remarks
    Caller: SF_DAL_IOCtrl()
    GPRAM utilization is 1+1B. A device lock is not necessary for GPRAM.
*/
#if defined(SF_DAL_MXIC) || defined(SF_DAL_EON) || defined(SF_DAL_WINBOND)
__sf_section_EMIINITCODE int SF_DAL_UnlockBlock_MXIC(void *MTDData)
{
    SF_MTD_Data  *D  = MTDData;
    kal_uint32    unlock;
    kal_uint8     cmd;

    // Write Enable
    SFI_Dev_Command(D->CMD->WriteEnable);
    SF_DAL_Dev_WaitReady_EMIINIT(D);

    // Read BP Register and clear all block protect bits
    SFI_Dev_Command_Ext(&D->CMD->ReadBPReg, &cmd, 1, 1);
    unlock = D->CMD->WriteBPReg;
    unlock = (unlock << 8) | (cmd & ~ (D->StatusMap[SF_SR_BP] | D->StatusMap[SF_SR_SRWD]));

    // Write BP Register
    SFI_Dev_Command(unlock);
    SF_DAL_Dev_WaitReady_EMIINIT(D);

    return FS_NO_ERROR;
}

#endif // defined(SF_DAL_MXIC) || defined(SF_DAL_EON) || defined(SF_DAL_WINBOND)

#if defined(__BASIC_LOAD_FLASH_TEST__)
//-----------------------------------------------------------------------------
/*!
  @brief
    Program in INIT stage

  @param[in] MTDData Pointer to the MTD driver data
  @param[in] Address Pointer to the physical address that going to be programmed
  @param[in] Data Pointer to the data buffer
  @param[in] Length Length of data buffer
*/

__sf_section_EMIINITCODE void SF_DAL_ProgramData_EMIINIT(void *MTDData, kal_uint32 address, void *Data, kal_uint32 Size)
{
    SF_MTD_Data    *D = (SF_MTD_Data *)MTDData;
    kal_uint8      *p_data  = Data;
    kal_uint32      cmd1 = 0;

    // 0. wait device ready before issue another erase command
    SF_DAL_Dev_WaitReady_EMIINIT(D);

    SFI_Dev_Command(D->CMD->WriteEnable);

#if defined(__SFI_4BYTES_ADDRESS__)
    if (D->AddressCycle == 4)
    {
        cmd1=SFI_GPRAM_Write_C1A4(D->CMD->PageProg, address, &p_data, &Size);
        SFI_GPRAM_Write(8, p_data, Size);
    }
    else
#endif
    {
        cmd1=SFI_GPRAM_Write_C1A3(D->CMD->PageProg, address);
        SFI_GPRAM_Write(4, p_data, Size);
    }

    SFI_WriteReg32(RW_SFI_MAC_OUTL, Size + D->AddressCycle + 1);
    SFI_WriteReg32(RW_SFI_MAC_INL, 0);
    SFI_WriteReg32(RW_SFI_GPRAM_DATA, cmd1);
    SFI_MacEnable();
    SFI_MacWaitReady();

    // 3. wait ready
    SF_DAL_Dev_WaitReady_EMIINIT(D);

    return;
}
#endif

//-----------------------------------------------------------------------------
/*!
  @brief
    Erase a block in INIT stage
  @param[in] MTDData Pointer to the MTD driver data
  @param[in] BlockSize Size of the block in bytes
  @param[in] Address Pointer to the physical block address that going to be erased
*/

/*Mini Bootloader does not need to do Erase and Program Operation*/
/*Therefore, use dummy function to avoid mini Bootloader out of size*/
#if (!defined(__NOR_FULL_DRIVER__) || defined(__MINI_BOOTLOADER__)) && defined(__UBL__)
__sf_section_EMIINITCODE int SF_DAL_EraseBlock_EMIINIT(void *MTDData, kal_uint32 BlockSize, kal_uint32 Address)
{
    return FS_UNSUPPORTED_DRIVER_FUNCTION;
}
#else //(!defined(__NOR_FULL_DRIVER__) || defined(__MINI_BOOTLOADER__)) && defined(__UBL__)
__sf_section_EMIINITCODE int SF_DAL_EraseBlock_EMIINIT(void *MTDData, kal_uint32 BlockSize, kal_uint32 Address)
{
    kal_uint32           cmd;
    kal_uint32     a, b, c;
    kal_uint32     iteration=1, eraseunit, eraseaddr;
    SF_MTD_Data         *D = MTDData;

    // 0. wait device ready before issue another erase command
    SF_DAL_Dev_WaitReady_EMIINIT(D);

    // Default Erase Unit (in case of non-pseudo-size block)
    eraseunit = BlockSize;

    // Find the smallest erase unit from Block Size
    // a: supported uniform blocks
    // b: pseudo block size
    //
    // consider (4, 32, 64 KB uniform blocks)
    // pseido 8KB block
    // c=0           | c=1       | c=2, erase unit = 2^(2+10)=4KB  | c=3
    // a: 0110 0100  > 0011 0010 > 0001 1001 (a%2==1 save b        > 0000 1100
    // b: 0000 1000  > 0000 0100 > 0000 0010  iteration=2, and c)  > 0000 0001 (b%1==1 stop search)
	a=D->UniformBlock;
	b=(BlockSize>>10);
	//If that erase unit is natively supported by the device, skip pseudo block search.
	if(0 == (a&b))
	{
		for (c=0; (b&0x1)==0 ;a=a>>1, b=b>>1, c++)    {
			if (a&0x1) {
		    	iteration = b;
		        eraseunit = 1 << (c+10);
		    }
		}
	}


    // Get Erase Command
    switch (eraseunit)    {
        case 0x1000: cmd = D->CMD->Erase4K;   break;
        case 0x8000: cmd = D->CMD->Erase32K;  break;
        default:     cmd = D->CMD->Erase64K;  break;
    }

    for (eraseaddr=Address ; iteration>0 ; iteration--, eraseaddr+=eraseunit) {
        // 1. write enable
        SFI_Dev_Command(D->CMD->WriteEnable);
        // 2. Erase
        SFI_Dev_CommandAddress(cmd, eraseaddr, D->AddressCycle);
        // 3. wait ready
        SF_DAL_Dev_WaitReady_EMIINIT(D);
    }

    return FS_NO_ERROR;
}
#endif //(!defined(__NOR_FULL_DRIVER__) || defined(__MINI_BOOTLOADER__)) && defined(__UBL__)

/*!
  @brief
    Release SFI channel2 and channel3 in INIT stage
    To make sure channel2 and channel3 could be used in MAUI.
    Currently, only for MT6250.
    Root cause: NOR_FLASH_BUSY is used during INIT stage(SFI_MacLeave) but it is not initialized yet.
    May cause channel2 and 3 being masked and not released after leaving ScanSerialflashBlocks()
*/
__sf_section_EMIINITCODE void SF_DAL_ReleaseSFIChannels_EMIINIT(void)
{
    SFI_MaskAhbChannel(0);
}

#ifdef __MTK_TARGET__
#pragma arm section code
#endif

#else  // __NOR_LEAKAGE__

__sf_section_EMIINITCODE kal_int32 SF_DAL_Mount_Driver_EMIINIT(NOR_MTD_Driver *driver, SF_MTD_Data *D, kal_uint32 baseaddr)
{
    return FS_UNSUPPORTED_DRIVER_FUNCTION;
}
__sf_section_EMIINITCODE int SF_DAL_EraseBlock_EMIINIT(void *MTDData, kal_uint32 BlockSize, kal_uint32 Address)
{
    return FS_UNSUPPORTED_DRIVER_FUNCTION;
}
__sf_section_EMIINITCODE void SF_DAL_ProgramData_EMIINIT(void *MTDData, kal_uint32 address, void *Data, kal_uint32 Size)
{
    return;
}
__sf_section_EMIINITCODE void SF_DAL_ReleaseSFIChannels_EMIINIT(void)
{
    return;
}

#endif // __NOR_LEAKAGE__


#endif // __SERIAL_FLASH__


