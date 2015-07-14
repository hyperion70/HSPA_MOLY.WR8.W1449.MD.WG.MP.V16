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
 *    flash_mtd_sf_ut.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   Serial Flash device unit test
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================*/
#include "flash_mtd_sf_ut.h"
#include "flash_mtd_ut.h"

#if defined(SF_DEBUG)

#if defined(__SF_DVT__)
#include "flash_mtd_sf_dal.h"
#include "flash_mtd_sf_dvt.h"
#else
#include "reg_base.h"
#include "intrCtrl.h"
#include "us_timer.h"
#include "flash_sf.h"
#include "kal_public_api.h" //MSBB change #include "kal_release.h"
#include "flash_mtd_sf_dal.h"
#include "flash_mtd_internal.h"
#include "custom_MemoryDevice.h"
#include "nor_profile.h"
#include "combo_flash_init.h"
#include "kal_debug.h"
#include "gpio_hw.h"
#include "gpio_sw.h"
#include "flash_mtd.h"
#endif

//-----------------------------------------------------------------------------
// [Section] RVCT and GCC
//-----------------------------------------------------------------------------
#define __sf_section_RAM             __attribute__ ((section ("SNORCODE")))

//-----------------------------------------------------------------------------
// External Functions
//-----------------------------------------------------------------------------
// custom\system\[BB]\custom_flash.c
extern kal_uint32 custom_get_NORFLASH_Base(void);
extern kal_uint32 custom_get_NORFLASH_ROMSpace(void);
extern kal_uint32 custom_get_fat_len(void);
// custom\system\[BB]\custom_scatstruct.c
extern kal_uint32 custom_get_1st_ROM_ROMBase(void);
extern kal_uint32 custom_get_1st_ROM_ROMLength(void);
// MISC
extern kal_uint32 rand(void);
extern void GetFDMLock(void);
extern void FH_Fixed_80Mhz(void);

// Serial Flash Configurations
#define SFUT_FLASHBASE custom_get_NORFLASH_Base()      // Memory bank base addr (0800_0000h or 0000_0000h)
#define SFUT_FSBASE    custom_get_NORFLASH_ROMSpace()  // FS base   (Phyiscal address on NOR)
#define SFUT_FSSIZE    custom_get_fat_len()            // FS length (phyiscal address on NOR)
#define SFUT_ROMBASE   custom_get_1st_ROM_ROMBase()    // ROM base address
#define SFUT_ROMSIZE   custom_get_1st_ROM_ROMLength()  // ROM length

//-----------------------------------------------------------------------------
// Internal Functions
//-----------------------------------------------------------------------------
void SFUT_Init(void);
kal_int32 SFUT_memcmp(void *destaddr, void *srcaddr, kal_uint32 length);
kal_int32 SFUT_memcpy(void *destaddr, void *srcaddr, kal_uint32 length);
void SFUT_CorruptFS(void);
void SFUT_CorruptROM(void);
void SFUT_CorruptNOR(void);
void SFUT_WrapReadTest(SF_MTD_Data *D, kal_uint32 address, kal_uint32 size);

//-----------------------------------------------------------------------------
// External Variables
//-----------------------------------------------------------------------------
// Mount Device
extern NOR_MTD_Driver NORFlashMtd;           // SF driver interface
extern SF_MTD_Data mtdflash;                 // SF driver data


//-----------------------------------------------------------------------------
// Internal Macros
//-----------------------------------------------------------------------------
#define KB(a)              (a<<10)

// Redefinition of Assert / Print API
//-------------------------------------
// Test results
kal_bool sfut_result;

#if (defined(IC_MODULE_TEST) || defined(IC_BURNIN_TEST))
extern void module_test_print(char *fmt,...);
extern kal_bool sfut_result;
#undef dbg_print
#undef ASSERT
#undef MTD_ASSERT
#define ASSERT(expr)  do { if(!(expr)) { sfut_result=KAL_FALSE; } } while(0)
#define MTD_ASSERT(expr, e1, e2, e3, code)  do { if(!(expr)) { sfut_result=KAL_FALSE; } } while(0)
#define dbg_print module_test_print
#endif

// Time utility
//-------------------------------------
#define SFUT_GetCurrentTime(...)  (*(volatile kal_uint32*)(TDMA_base+0x230))  // get 32Khz ticks
#define US32K(a) ((125*(a))>>2)     // 32Khz to us
#define USQCNT(a) (((a)*946)>>10)   // qbit to us

// Test Parameter
//-------------------------------------
// default serial flash page size
#define PAGE_SIZE 256

// Pattern Type
#define PATTERN_RANDOM     0xABC
#define PATTERN_SEQUENTIAL 0X123
#define PATTERN_END        0xDEAD

//-----------------------------------------------------------------------------
// Global Variables
//-----------------------------------------------------------------------------
// Interrupt Frequency Control
kal_uint32 SFUT_IntTimeCurr=0;
kal_uint32 SFUT_IntTimePrev=0;
kal_uint32 SFUT_IntTimeDiff=0;
kal_uint32 SFUT_IntFreq=0;
kal_uint32 SFUT_IntServeTime=0;
kal_uint32 SFUT_IntTriggerTime=0;
kal_uint32 SFUT_IntBusySuspend=0;

// Suspend frequency obtained from auto calibration
kal_uint32 SFUT_IntFreq_Erase=0;
kal_uint32 SFUT_IntFreq_Prog=0;

// Suspend Enable
kal_uint32 sfut_suspend_enable=0;

// erase distrubance check during suspend
kal_uint32 suspend_disturb_check_start=0;   // start of the block group
kal_uint32 suspend_disturb_check_end=0;     // end of the block group
kal_uint32 suspend_disturb_check_ptr=0;     // Pointer to the current erase block
kal_uint32 suspend_disturb_check_eu=0;      // erase unit used in the disturbance test

// Test Case Timing Facility:
// Get the test duration of each test case to evaluate the SLT cost.
kal_uint32 tc_time_start=0;   // Test case starting time
kal_uint32 tc_time_diff;      // Time difference
kal_uint32 tc_time_end;       // Test case ending time

// Default Erase Units to be tested, refer to SFUT_Init().
kal_uint32 eusize[8];         // The supported erase units of the deivce, where eusize[0] is the smallest one.

// SFUT test buffer (2 pages)
kal_uint32 sfut_buff[PAGE_SIZE/2];

/*
Program Patterns:
page  0: 0xF0F0F0F0 0x0F0F0F0F
page  1: 0x0F0F0F0F 0xF0F0F0F0
page  2: 0xAA55AA55 0x55AA55AA
page  3: 0x55AA55AA 0xAA55AA55
page  4: 0x33CC33CC 0xCC33CC33
page  5: 0xCC33CC33 0x33CC33CC
page  6: 0x00FF00FF 0xFF00FF00
page  7: 0xFF00FF00 0x00FF00FF
page  8: All 0xFF
page  9: All 0x00
page 10: sequentail pattern (0x00~0xFF)
page 11: random pattern
*/
typedef struct {
    kal_uint32 address;
    kal_uint32 pattern[2];
} tTestPattern;

tTestPattern sfut_TestPatterns[]= {
    // Addresss ,  Pattern 1  , Pattern 2
    {0,            {0xF0F0F0F0, 0x0F0F0F0F}},
    {PAGE_SIZE,    {0x0F0F0F0F, 0xF0F0F0F0}},
    {PAGE_SIZE*2,  {0xAA55AA55, 0x55AA55AA}},
    {PAGE_SIZE*3,  {0x55AA55AA, 0xAA55AA55}},
    {PAGE_SIZE*4,  {0x33CC33CC, 0xCC33CC33}},
    {PAGE_SIZE*5,  {0xCC33CC33, 0x33CC33CC}},
    {PAGE_SIZE*6,  {0x00FF00FF, 0xFF00FF00}},
    {PAGE_SIZE*7,  {0xFF00FF00, 0x00FF00FF}},
    {PAGE_SIZE*8,  {0xFFFFFFFF, 0xFFFFFFFF}},
    {PAGE_SIZE*9,  {0x00000000, 0x00000000}},
    {PAGE_SIZE*10, {PATTERN_SEQUENTIAL,0x0}},
    {PAGE_SIZE*11, {PATTERN_RANDOM,    0x0}},
    {PAGE_SIZE*12, {PATTERN_END,       0x0}}
};

// 1 Byte Over Program Test Pattern (F 7 3 1 0 | F E C 8 0)
kal_uint8 overprog_pattern[]= { 0xFF, 0xFE, 0x7E, 0x7C, 0x3C, 0x38, 0x18, 0x10, 0x00 };

//-----------------------------------------------------------------------------
// Output / Message Facility
//-----------------------------------------------------------------------------

// GPIO LED Outputs for BB-Chip SLT Memory SLT
//--------------------------------------------
// GPIO LED Outputs
#if defined(SFUT_GPIO_LED_OUTPUT)
    #define SFUT_READY_WRAP() do { if (sfut_result) GPIO_WriteIO(1, SFUT_READY_WRAP_FUNCTION_LED_GPIO); } while(0)
    #define SFUT_READY_BASIC() do { if (sfut_result) GPIO_WriteIO(1, SFUT_READY_BASIC_FUNCTION_LED_GPIO); } while(0)
    #define SFUT_READY_SUSPEND() do { if (sfut_result) GPIO_WriteIO(1, SFUT_READY_SUSPEND_FUNCTION_LED_GPIO); } while(0)

// GPIO initialization
void SFUT_Init_GPIO(void)
{
    GPIO_ModeSetup(SFUT_READY_WRAP_FUNCTION_LED_GPIO, 0);
    GPIO_InitIO(OUTPUT, SFUT_READY_WRAP_FUNCTION_LED_GPIO);
    GPIO_WriteIO(KAL_FALSE, SFUT_READY_WRAP_FUNCTION_LED_GPIO);

    GPIO_ModeSetup(SFUT_READY_BASIC_FUNCTION_LED_GPIO, 0);
    GPIO_InitIO(OUTPUT, SFUT_READY_BASIC_FUNCTION_LED_GPIO);
    GPIO_WriteIO(KAL_FALSE, SFUT_READY_BASIC_FUNCTION_LED_GPIO);

    GPIO_ModeSetup(SFUT_READY_SUSPEND_FUNCTION_LED_GPIO, 0);
    GPIO_InitIO(OUTPUT, SFUT_READY_SUSPEND_FUNCTION_LED_GPIO);
    GPIO_WriteIO(KAL_FALSE, SFUT_READY_SUSPEND_FUNCTION_LED_GPIO);
}
#else
    #define SFUT_READY_WRAP()
    #define SFUT_READY_BASIC()
    #define SFUT_READY_SUSPEND()
    #define SFUT_Init_GPIO()
#endif


// Debug Message
//-------------------------------------
// Reuse text buffer instantiated in nortest.c
#if (defined(__NOR_FLASH_HARDWARE_TEST__) && defined(__MAUI_BASIC__))
extern char text[100];
#else
char text[100];
#endif

// Test case (items) processed
kal_uint32 testitem=1;

// Major Debug Message API
#if (defined(SFUT_DEBUG_LOG))
extern void dbg_print(char *fmt,...);
#define SFUT_DEBUG(...) do{\
        kal_sprintf((char *)(&text[0]), "[SF_UT] ");\
        kal_sprintf((char *)(&text[strlen(text)]), ##__VA_ARGS__);\
        dbg_print((char *)(&text[0]));\
} while(0)

// Test Case Time Message
#define SFUT_TESTTIME_Print(...)  do { \
    if (tc_time_start!=0) { \
        tc_time_end=SFUT_GetCurrentTime(); \
        tc_time_diff=NOR_PROFILE_TIME_DIFF(tc_time_start ,tc_time_end); \
        kal_sprintf((char *)(&text[0]), "[SF_UT] <<<<< Test Case #%02d: Time Taken %d us >>>>> \r\n", testitem-1, US32K(tc_time_diff)); \
        dbg_print((char *)(&text[0])); \
    } \
} while(0)

// Reset test case timer
#define SFUT_TESTTIME_Reset(...)  tc_time_start=0;

// Test Case Message
#define SFUT_TESTMSG(...) do{ \
        SFUT_TESTTIME_Print(); \
        kal_sprintf((char *)(&text[0]), "[SF_UT] <<<<< Test Case #%02d >>>>> ", testitem++);\
        kal_sprintf((char *)(&text[strlen(text)]), ##__VA_ARGS__);\
        dbg_print((char *)(&text[0]));\
        tc_time_start=SFUT_GetCurrentTime(); \
} while(0)

#else
#define SFUT_DEBUG(...)
#define SFUT_TESTTIME_Print(...)
#define SFUT_TESTTIME_Reset(...)
#define SFUT_TESTMSG(...)
#endif

// Internal RTC time wrap functions
//--------------------------------------------
#define DHMS2Second(D, H, M, S)   ((((((D)*24)+(H))*60)+(M))*60+(S))
#define MIN(N)                    (N*60)
#define HOUR(N)                   (N*3600)

// DVT version
//-------------
#if defined(__SF_DVT__)
#define sfut_rtc_time kal_uint32
void SFUT_RTCTInit(void)
{
    return;
}
void SFUT_RTCGetCurrentTime(sfut_rtc_time *rtctime)
{
    return;
}
kal_uint32 SFUT_RTCGetDuration(sfut_rtc_time *start, sfut_rtc_time *end)
{
    // DVT load does not have RTC timer driver, use loop count limit instead.
    return 1;
}
void SFUT_RTCPrint(sfut_rtc_time *rtctime)
{
    return;
}

// HAL version
//-------------
#elif defined(FLASH_MTD_INTERNAL_H)
#include "dcl.h"

#define sfut_rtc_time RTC_CTRL_GET_TIME_T
static DCL_HANDLE sfut_rtc_handler;

void SFUT_RTCTInit(void)
{
    sfut_rtc_handler = DclRTC_Open(DCL_RTC, FLAGS_NONE);
}

void SFUT_RTCGetCurrentTime(sfut_rtc_time *rtctime)
{
    DclRTC_Control(sfut_rtc_handler, RTC_CMD_GET_TIME, (DCL_CTRL_DATA_T *)rtctime);
}

kal_uint32 SFUT_RTCGetDuration(sfut_rtc_time *start, sfut_rtc_time *end)
{
    kal_uint32 start_sec, end_sec;

    start_sec = DHMS2Second(start->u1Day-1, start->u1Hour, start->u1Min, start->u1Sec);
    end_sec   = DHMS2Second(end->u1Day-1, end->u1Hour, end->u1Min, end->u1Sec);
    return (end_sec - start_sec);
}

void SFUT_RTCPrint(sfut_rtc_time *rtctime)
{
    SFUT_DEBUG(" Time %d:%d:%d:%d \r\n", rtctime->u1Day-1, rtctime->u1Hour, rtctime->u1Min, rtctime->u1Sec);
}

// non-HAL version
//----------------
#else
#include "rtc_sw.h"

#define sfut_rtc_time t_rtc
#define SFUT_RTCTInit()

void SFUT_RTCGetCurrentTime(sfut_rtc_time *rtctime)
{
    RTC_GetTime(rtctime);
}

kal_uint32 SFUT_RTCGetDuration(sfut_rtc_time *start, sfut_rtc_time *end)
{
    kal_uint32 start_sec, end_sec;
    start_sec = DHMS2Second(start->rtc_day, start->rtc_hour, start->rtc_min, start->rtc_sec);
    end_sec   = DHMS2Second(end->rtc_day, end->rtc_hour, end->rtc_min, end->rtc_sec);
    return (end_sec - start_sec);
}

void SFUT_RTCPrint(sfut_rtc_time *rtctime)
{
    SFUT_DEBUG(" Time %d:%d:%d:%d \r\n", rtctime->rtc_day, rtctime->rtc_hour, rtctime->rtc_min, rtctime->rtc_sec);
}

#endif // Internal RTC time wrap functions



// Test Coverage Information
//--------------------------------------------
// Note:
//   Following debug options must be enabled in SF DAL driver
//   SF_DAL_SUSPEND_STATISTICS, SF_DAL_ERASE_STATISTICS, SF_DAL_PROG_STATISTICS

#ifdef SFUT_SHOW_TEST_COVERAGE

// External statistic variables defined in dal driver
extern kal_uint32 SuspendCounter;
extern kal_uint32 EraseTotal;
extern kal_uint32 ProgTotal;

#define SFUT_TARGET_WINODW_ERASE  100        // in terms of nano second
#define SFUT_TARGET_WINODW_PROG    10        // in terms of nano second
#define SFUT_TARGET_TEST_COVERAGE  (0.0001)
double sfut_distrub_test_coverage_erase;     // = (1-p)^n
double sfut_distrub_test_coverage_program;   // = (1-p)^n

// Initialize test coverage variables
void SFUT_TestCoverage_Init(void)
{
    sfut_distrub_test_coverage_erase=1.0;
    sfut_distrub_test_coverage_program=1.0;
}


// Call after every erase operation that has suspends
void SFUT_TestCoverage_Erase(void)
{
    double p;

    if (SuspendCounter==0) return;
    p = ((double)(SuspendCounter)) / (US32K(EraseTotal)*(1000/SFUT_TARGET_WINODW_ERASE));
    sfut_distrub_test_coverage_erase *= (1.0-p);
}

// Call after every program operation that has suspends
void SFUT_TestCoverage_Program(void)
{
    double p;

    if (SuspendCounter==0) return;
    p = ((double)(SuspendCounter)) / (USQCNT(ProgTotal)*(1000/SFUT_TARGET_WINODW_PROG));
    sfut_distrub_test_coverage_program *= (1.0-p);
}

void SFUT_TestCoverage(void)
{
   SFUT_DEBUG("Test coverage: Erase %2.6lf, Program %2.6lf \r\n",
        (1.0-sfut_distrub_test_coverage_erase),
        (1.0-sfut_distrub_test_coverage_program)
   );
}
#else
#define SFUT_TestCoverage_Init()
#define SFUT_TestCoverage_Erase()
#define SFUT_TestCoverage_Program()
#define SFUT_TestCoverage()
#endif // SFUT_SHOW_TEST_COVERAGE


/*
[Basic Function]
  <Device Information>
    Read ID (QPI mode)

  <Erase Test>
    [Settings]
    1. Program blocks to zeros before erase

    [Steps]
    Erase 4/32/64 KB block without suspend
    Erase 4/32/64 KB block with busy suspend every 1024, 512, 256, 128 us

  <Program Test>
    Combinational Program Test:
      256 bytes page program
      4 bytes program
      3 bytes program
      2 bytes program
      1 byte over program test (FDM block state transition)
      1 byte over program test (FDM sector state transition)

<Direct Read Test>
    Combinational Read Test
    1. pattern 0 ~ 11
    2. start address 0, 4, 8, 12, ...

<Macro Mode Read Test>
    Combinational Read Test
    1. pattern 0 ~ 11
    2. start address 0, 4, 8, 12, ...
    3. cs go high
 */

//-----------------------------------------------------------------------------
/*!
  @brief
     Erase Function Used by SFUT
  @param[in] D Pointer to the SF MTD driver data.
  @param[in] address Erase address.
  @param[in] eraseunit Size of the erase unit in terms of bytes.
  @param[in] intfreq Interrupt frequency during erase operation, qbits per interrupt
*/
__sf_section_RAM kal_int32 SFUT_Erase(SF_MTD_Data *D, kal_uint32 address, kal_uint32 eraseunit, kal_uint32 intfreq)
{
  kal_int32 result;
  D->CMD->Erase=SF_CMD_ERASE_SECTOR;
  D->CurrAddr=(kal_uint8 *)address;

  SFUT_IntBusySuspend=intfreq;

  switch (eraseunit)    {
     // 4KB
     case 0x1000:
         D->CMD->Erase = D->CMD->Erase4K;
         break;
     // 32KB
     case 0x8000:
         D->CMD->Erase = D->CMD->Erase32K;
         break;
     // 64KB
     default:
         D->CMD->Erase = D->CMD->Erase64K;
         break;
  }
  // Call SF_DAL driver and set MSB to customize erase unit.
  // The most significant bit in block index is used to customize the erase unit.
  result=SF_DAL_EraseBlock(D, 0x80000000 | eraseunit);
  SFUT_IntBusySuspend=0;
  return result;
}

//-----------------------------------------------------------------------------
/*!
  @brief
     Fill the given buffer with sequentail pattern
  @param[out] buff The target buffer to be filled.
  @param[in] length Size of the buffer
  @remarks
     The pattern is 00h 01h 02h 03h ... FFh 00h ... etc.
*/
void SFUT_PatternFillSequential(void *buff, kal_uint32 length)
{
    kal_uint32   i;
    kal_uint8 *ptr=(kal_uint8*)buff;
    for (i=0; i<length; i++) *ptr++ = i&0xFF;
    return;
}

//-----------------------------------------------------------------------------
/*!
  @brief
     Fill the given buffer with random pattern
  @param[out] buff The target buffer to be filled.
  @param[in] length Size of the buffer
*/
void SFUT_PatternFillRandom(void *buff, kal_uint32 length)
{
    kal_uint32   i;
    kal_uint8 *ptr=(kal_uint8*)buff;
    for (i=0; i<length; i++) *ptr++ = rand()%0xFF;
    return;
}

//-----------------------------------------------------------------------------
/*!
  @brief
    Program Function Used by SFUT
  @param[in] D Pointer to the SF MTD driver data.
  @param[in] address The program address
  @param[in] pattern1 The program pattern of 0~3, 8~11, ... bytes
  @param[in] pattern2 The program pattern of 4~7, 12~15, ... bytes
  @param[in] length The program length
  @param[in] read_test If true, perform combinational direct read test after program
*/
__sf_section_RAM void SFUT_ProgramPattern(
    SF_MTD_Data *D, kal_uint32 address,
    kal_uint32 pattern1, kal_uint32 pattern2,
    kal_uint32 length, kal_bool read_test)
{
    kal_uint32  i, j;

    // Fiil buffer with given pattern: Sequtial, Random, or others
    if (pattern1 == PATTERN_SEQUENTIAL) {
        SFUT_PatternFillSequential(&sfut_buff[0], (length<PAGE_SIZE)?length:PAGE_SIZE );
        SFUT_DEBUG("Sequential Pattern, Addr: 0x%08X\r\n", address);
    }
    else if (pattern1 == PATTERN_RANDOM)    {
        SFUT_PatternFillRandom(&sfut_buff[0], (length<PAGE_SIZE)?length:PAGE_SIZE );
        SFUT_DEBUG("Random Pattern, Addr: 0x%08X\r\n", address);
    }
    else {
        for (i=0; i<(PAGE_SIZE/4); i+=2) {
            sfut_buff[i]=pattern1;
            sfut_buff[i+1]=pattern2;
        }
        SFUT_DEBUG("Pattern: 0x%08X 0x%08X Addr: 0x%08X\r\n", pattern1, pattern2, address);
    }

    // Program Page by Page
    for (i=length, j=address; i!=0;)  {
        if (i>=PAGE_SIZE)  {
            SF_DAL_ProgramData(D, (void*)j, &sfut_buff[0], PAGE_SIZE);
            // combinational read test
            if (read_test)  {
                if (SFUT_memcmp(&sfut_buff[0], (void*)j, PAGE_SIZE) < 0) sfut_result=KAL_FALSE;
            }
            j+=PAGE_SIZE;
            i-=PAGE_SIZE;
        }
        else {  // Less than one page
            SF_DAL_ProgramData(D, (void*)j, &sfut_buff[0], i);
            // combinational read test
            if (read_test)  {
                if (SFUT_memcmp(&sfut_buff[0], (void*)j, i) < 0) sfut_result=KAL_FALSE;
            }
            i=0;
        }
    }
}

//-----------------------------------------------------------------------------
/*!
  @brief
    SFUT Program Test Routine
  @param[in] D Pointer to the SF MTD driver data.
  @param[in] address The program address
*/
void SFUT_ProgramTest(SF_MTD_Data *D, kal_uint32 address)
{
  /*
    <Program Test>
      Combinational Program Test:
        256 bytes page program
        1~4 bytes combinational program
        1 byte over program test (FDM sector state transition)
  */
  kal_uint32 i, j, val;
  kal_uint8 *ptr=(kal_uint8*)&sfut_buff[0];
  kal_uint32 prog_len;

  // 256 bytes page program
  SFUT_TESTMSG("%d bytes page program and direct read test\r\n", PAGE_SIZE);

  for (i=0;sfut_TestPatterns[i].pattern[0]!=PATTERN_END;i++)   {
      SFUT_ProgramPattern(
          D,
          address+sfut_TestPatterns[i].address,
          sfut_TestPatterns[i].pattern[0],
          sfut_TestPatterns[i].pattern[1],
          PAGE_SIZE,
          KAL_TRUE
      );
   }

   // Get last page address
   address += sfut_TestPatterns[i].address;

   SFUT_PatternFillSequential(sfut_buff, PAGE_SIZE);

   // 1 ~ 4 bytes Combinational Program Test
   for (prog_len=4; prog_len!=0; prog_len--, address+=PAGE_SIZE) {
        SFUT_TESTMSG("%d byte program, addr: 0x%08X \r\n", prog_len, address);
        for (i=0; (i+prog_len)<=PAGE_SIZE; i+=prog_len) {
        //    SFUT_DEBUG("%08xh, %08xh, %02xh \r\n",i+address, &ptr[i], ptr[i]);
            SF_DAL_ProgramData(D, (void*)(i+address), &ptr[i], prog_len);
        }
   }

   // 1 Byte Over Program Test
   SFUT_TESTMSG("1 byte over program, addr: 0x%08X \r\n", i+address);
   for (i=0; i<256; i++)    {
      j=0;
      do {
        val=overprog_pattern[j++];
        SF_DAL_ProgramData(D, (void*)(i+address), &val, 1);
      } while (val!=0);
   }

   address+=PAGE_SIZE;
}

//-----------------------------------------------------------------------------
/*!
  @brief
    SFI Macro Mode Read Test
  @param[in] D Pointer to the SF MTD driver data.
  @param[in] address The read address on serial Flash
  @param[in] length The length of the read buffer
  @param[in] buff The pointer to the read buffer
*/
#if defined(MT6251)||defined(MT6252)
    #define SFUT_GetSFIReadCommand()   ((SFI_ReadReg32(RW_SFI_MISC_CTL) >> 16) & 0xFF)
    #define SFUT_IsModeQPI()           ((SFI_ReadReg32(RW_SFI_MAC_CTL) & SFI_QPI_EN))
    #define SFUT_GetSFIDummyCyc()      ((((SFI_ReadReg32(RW_SFI_MISC_CTL) >> 12) & 0xF)/3) +1)
#elif defined(MT6255)||defined(MT6250)||defined(MT6280)
    #define SFUT_GetSFIReadCommand()   ((SFI_ReadReg32(RW_SFI_DIRECT_CTL) >> 24) & 0xFF)
    #define SFUT_IsModeQPI()           ((SFI_ReadReg32(RW_SFI_DIRECT_CTL) & SFI_QPI_EN))
    #define SFUT_GetSFIDummyCyc()      (((SFI_ReadReg32(RW_SFI_DIRECT_CTL) >> 12) & 0xF) +1)
#else
    #error SFUT_GetSFIReadCommand is not defined.
#endif

__sf_section_RAM int SFUT_MacRead(SF_MTD_Data *D, kal_uint32 address, kal_uint32 length, void *buff)
{
    kal_uint32 cmd, cmdlen, dummycyc, i, savedMask, qpi_ctrl, qpi_en;
    kal_uint32 tmp=0;
    kal_uint8  *ptr=buff;

    SF_DAL_GetDevLock(D);

    cmd = SFUT_GetSFIReadCommand(); // Get Read Command

    if (SFUT_IsModeQPI()==0)   {
        // Convet to the Quad SPI read command
    for (i=0, tmp=0; i<8; i++) {
        tmp = tmp << 4;
        tmp = tmp | ((cmd>>7)&0x1);
        cmd = (cmd << 1) & 0xFF;
    }
    }

    savedMask = SaveAndSetIRQMask();

#if defined(MT6255) || defined(MT6250) || defined(MT6280)
    qpi_en=RW_SFI_DIRECT_CTL;
#else
    qpi_en=RW_SFI_MAC_CTL;
#endif

    qpi_ctrl = SFI_ReadReg32(qpi_en);

    // TODO: Determin cummy cycle, address length correctly
    // QPI mode
    if (SFUT_IsModeQPI())   {
        if (D->AddressCycle==3) {
        cmd = (SFI_ReverseByteOrder(address)&0xFFFFFF00) | cmd;
            SFI_WriteReg32(RW_SFI_GPRAM_DATA, cmd);
        cmdlen = 4;
        }
        else {
            address=SFI_ReverseByteOrder(address);
            cmd = (address<<8) | cmd;
        SFI_WriteReg32(RW_SFI_GPRAM_DATA, cmd);
            SFI_WriteReg32(RW_SFI_GPRAM_DATA+4, (address>>24));
            cmdlen=5;
        }
        dummycyc = SFUT_GetSFIDummyCyc()/2;
#if defined(MT6255) || defined(MT6250) || defined(MT6280)       
        if(SFUT_GetSFIDummyCyc()%2 == 1) // Add DEL_LATCH_LATENCY 1 to cover odd dummy cycle
            SFI_WriteReg32(RW_SFI_MISC_CTL, SFI_ReadReg32(RW_SFI_MISC_CTL)+1);
#endif       
        SFI_WriteReg32(RW_SFI_MAC_OUTL, cmdlen);
        SFI_WriteReg32(RW_SFI_MAC_INL, dummycyc + length); // assume 4T dummy cycle
        SFI_MacEnable();
        SFI_MacWaitReady();
#if defined(MT6255) || defined(MT6250) || defined(MT6280)
        if(SFUT_GetSFIDummyCyc()%2 == 1) // Add DEL_LATCH_LATENCY 1 to cover odd dummy cycle
            SFI_WriteReg32(RW_SFI_MISC_CTL, SFI_ReadReg32(RW_SFI_MISC_CTL)-1);
#endif            
        RestoreIRQMask(savedMask);
    }
    // SPI-Quad mode Mac Read
    else {
        if (D->AddressCycle==3) {
        cmdlen = 4+3;
        cmd = (SFI_ReverseByteOrder(address)&0xFFFFFF00) >> 8;
        SFI_WriteReg32(RW_SFI_GPRAM_DATA, tmp);
        SFI_WriteReg32(RW_SFI_GPRAM_DATA+4, cmd);
        }
        else {
            cmdlen = 4+4;
            cmd = SFI_ReverseByteOrder(address);
            SFI_WriteReg32(RW_SFI_GPRAM_DATA, tmp);
            SFI_WriteReg32(RW_SFI_GPRAM_DATA+4, cmd);
        }
        dummycyc= SFUT_GetSFIDummyCyc()/2;
#if defined(MT6255) || defined(MT6250) || defined(MT6280)        
        if(SFUT_GetSFIDummyCyc()%2 == 1) // Add DEL_LATCH_LATENCY 1 to cover odd dummy cycle
            SFI_WriteReg32(RW_SFI_MISC_CTL, SFI_ReadReg32(RW_SFI_MISC_CTL)+1);
#endif  
        SFI_WriteReg32(RW_SFI_MAC_OUTL, cmdlen);
        SFI_WriteReg32(RW_SFI_MAC_INL, dummycyc + length); // assume 4T dummy cycle
        SFI_WriteReg32(qpi_en, qpi_ctrl | SFI_QPI_EN);
        SFI_MacEnable();
        SFI_MacWaitReady();
#if defined(MT6255) || defined(MT6250) || defined(MT6280)         
        if(SFUT_GetSFIDummyCyc()%2 == 1) // Add DEL_LATCH_LATENCY 1 to cover odd dummy cycle
            SFI_WriteReg32(RW_SFI_MISC_CTL, SFI_ReadReg32(RW_SFI_MISC_CTL)-1);
#endif 
        SFI_WriteReg32(qpi_en, qpi_ctrl);
        RestoreIRQMask(savedMask);
    }

    for (i=0; i<length; i++)    {
        ptr[i]=SFI_ReadReg8(RW_SFI_GPRAM_DATA+cmdlen+dummycyc+i);
    }

    SF_DAL_FreeDevLock(D);

    return 0;
}

//-----------------------------------------------------------------------------
/*!
  @brief
    While loop busy wait for a period of time
  @param[in] us The waiting time in micro seconds
*/

#if defined (__SF_DVT__)
__sf_section_RAM void SFUT_busy_wait_us(kal_uint32 us)
{
    gpt4_busy_wait_us(us);
}
#else
__sf_section_RAM void SFUT_busy_wait_us(kal_uint32 us)
{
    kal_uint32 start_tick, curr_tick, diff;
    us = us * 13 / 12;
    start_tick = ust_get_current_time();

    do {
        curr_tick = ust_get_current_time();
        diff = ust_get_duration(start_tick, curr_tick);
    } while (diff < us);
}
#endif
//-----------------------------------------------------------------------------
/*!
  @brief
    SFUT Macro Mode Read Test Routine
  @param[in] D Pointer to the SF MTD driver data.
  @param[in] address The read address on serial Flash
  @param[in] latency_base CS high time range start (us)
  @param[in] latency_end CS high time range end (us)
  @param[in] latency_step CS high time increment at each test (us)

  @remarks
    The test patterns have to be programmed before calling this function.
*/
__sf_section_RAM void SFUT_MacRead_Test(SF_MTD_Data *D, kal_uint32 address,
    kal_uint32 latency_base, kal_uint32 latency_end, kal_uint32 latency_step)
{
    // Combinational mac read test
    kal_uint32 i, j;
    kal_uint32 ptr, latency;
    kal_uint32 data[2];

    SFUT_TESTMSG("Macro Mode Combinational Read Test @ %08X, latency: %d ~ %d, step %d\r\n",
        address, latency_base, latency_end, latency_step);

    for (latency=latency_base; latency<=latency_end; latency+=latency_step) {


#define SFUT_MAC_READ_FULL


#if defined(SFUT_MAC_READ_COMPACT)
        // option 1: Test only 0xF0F0F0F0 0x0F0F0F0F (save test time)
        for (i=0;i<1;i++)
#else
        // option 2: Test all patterns
        for (i=0;sfut_TestPatterns[i].pattern[0]!=PATTERN_SEQUENTIAL;i++)
#endif
           {

#if defined(SFUT_MAC_READ_DEBUG)
            SFUT_DEBUG("addr: %x, pattern: 0x%08X 0x%08X, %d us\r\n",
                address+sfut_TestPatterns[i].address,
                sfut_TestPatterns[i].pattern[0],
                sfut_TestPatterns[i].pattern[1],
                latency);
#endif

            ptr=address+sfut_TestPatterns[i].address;

            for (ptr=ptr, j=0; j<256; ptr+=8, j+=8)  {
                SFUT_busy_wait_us(latency);
                SFUT_MacRead(D, ptr, 4, &data[0]);
                SFUT_busy_wait_us(latency);
                SFUT_MacRead(D, ptr+4, 4, &data[1]);
                if (data[0]!=sfut_TestPatterns[i].pattern[0] || data[1]!=sfut_TestPatterns[i].pattern[1]) {
                    SFUT_DEBUG("Macro mode read fail @ 0x%08X, read: %08X, %08X ,expected: %08X, %08X \r\n",
                        ptr, data[0], data[1], sfut_TestPatterns[i].pattern[0], sfut_TestPatterns[i].pattern[1]);
                    sfut_result=KAL_FALSE;
                    return;
                }
            }
        }
    }
    return;
}



//-----------------------------------------------------------------------------
/*!
  @brief
    SFI Wrap Read
  @param[in] D Pointer to the SF MTD driver data.
  @param[in] address The read address on serial Flash
  @remarks
    Test sequence:
    1. Direct Read
    2. Macro Mode Read
    3. Compare data with wrap around
    Caller: SFUT_WrapReadTest()
*/
kal_bool SFUT_WrapRead(SF_MTD_Data *D, kal_uint32 address)
{
    kal_uint32 drbuf[SFUT_WRAP_LEN/4], macbuf[SFUT_WRAP_LEN/4];
    kal_uint32 offset, group;
    kal_uint32 i;
    kal_bool   result=KAL_TRUE;

    // Get 32 bytes aligned read group
    offset=address%SFUT_WRAP_LEN;
    group=address-offset;

    // Only test on 4N address (0, 4, 8, 12, ...)
    if (0 != offset%4) return KAL_FALSE;

    // Macro Mode Read
    SFUT_MacRead(D, (address&SF_ADDRESS_MASK), SFUT_WRAP_LEN, &macbuf[0]);

    // Direct Read
    kal_mem_cpy(drbuf, (void*)group, SFUT_WRAP_LEN);

    // Compare 16 Bytes of Data
    for (i=0, offset/=4; i<SFUT_WRAP_LEN/4;i++) {
        if (macbuf[i]!=drbuf[(i+offset)%(SFUT_WRAP_LEN/4)])     {
            result=KAL_FALSE;
        }
    }

    if (result!=KAL_TRUE) {
        SFUT_DEBUG("Wrap read test fail @ 0x%08X (s: %08Xh o: %02Xh) \r\n", address, group, offset);
        SFUT_DEBUG("Mac: %08X %08X %08X %08X %08X %08X %08X %08X \r\n",
            macbuf[0], macbuf[1], macbuf[2], macbuf[3], macbuf[4], macbuf[5], macbuf[6], macbuf[7]);
        SFUT_DEBUG("Dir: %08X %08X %08X %08X %08X %08X %08X %08X \r\n",
            drbuf[0], drbuf[1], drbuf[2], drbuf[3], drbuf[4], drbuf[5], drbuf[6], drbuf[7]);
        sfut_result=KAL_FALSE;
    }

    return result;
}

//-----------------------------------------------------------------------------
/*!
  @brief
    SFI Wrap Read Test
  @param[in] D Pointer to the SF MTD driver data.
  @param[in] address The read address on serial Flash
  @param[in] size The test range from the given address
  @remarks
    Test sequence:
    1. Test at block boundary (Block End to Block Start)
    2. Random 32-byte Wrap Read for SFUT_WRAP_TEST_COUNT times
*/
void SFUT_WrapReadTest(SF_MTD_Data *D, kal_uint32 address, kal_uint32 size)
{
    kal_uint32 ptr, i;

    // 1. Block End (last 0xC address) > Block Start (first 0xC address)
    SFUT_TESTMSG("Wrap read test at block boundary \r\n");
    for (i=0; i<size; i+=KB(eusize[0])) {
        if ((i+KB(eusize[0])) > size) ptr=size-4;
        else ptr=i+KB(eusize[0])-4;
        SFUT_WrapRead(D, address+ptr);
        SFUT_WrapRead(D, address+i+0x1C);
    }

    // 2. Random Addresses
    SFUT_TESTMSG("Wrap read test at random address (%d) \r\n", SFUT_WRAP_TEST_COUNT);
    for (i=0; i<SFUT_WRAP_TEST_COUNT; i++)  {
        ptr=(rand()%size) & ~(0x3);
        SFUT_WrapRead(D, address+ptr);
    }
}

//-----------------------------------------------------------------------------
/*!
  @brief
    SFI Wrap Read Test
  @param[in] D Pointer to the SF MTD driver data.
  @param[in] address The read address on serial Flash
  @param[in] size The test range from the given address
  @remarks
    Test sequence:
    1. Test at block boundary (Block End to Block Start)
    2. Random 32-byte Wrap Read for SFUT_WRAP_TEST_COUNT times
*/
void SFUT_ReadTest(SF_MTD_Data *D, kal_uint32 address)
{
   //kal_uint32 i;
   //for (i=0; eusize[i+1]!=0; i++);
   //SFUT_Erase(D, address, KB(eusize[i]), 0);
   SFUT_ProgramPattern(
          D,
          address+sfut_TestPatterns[0].address,
          sfut_TestPatterns[0].pattern[0],
          sfut_TestPatterns[0].pattern[1],
          PAGE_SIZE,
          KAL_TRUE
      );
   SFUT_MacRead_Test(D, address, SFUT_CSHT_MIN, SFUT_CSHT_MAX, SFUT_CSHT_STEP);
}

void SFUT_EraseTest(SF_MTD_Data *D, kal_uint32 address)
{
  /*
    [Settings]
    1. Program blocks to zeros before erase

    [Steps]
    Erase 4/32/64 KB block without suspend
    Erase 4/32/64 KB block with busy suspend every 1024, 512, 256, 128 us
  */
  kal_uint32 i;

  if (KAL_TRUE == kal_query_systemInit()) {
      for (i=0; eusize[i]!=0; i++)  {
          SFUT_TESTMSG("Erase %dKB block (no suspend) \r\n", eusize[i]);
          SFUT_ProgramPattern(D, address, 0x0, 0x0, KB(eusize[i]), KAL_FALSE);
          SFUT_Erase(D, address, KB(eusize[i]), 0);
      }
  }
  else {
      for (i=0; eusize[i]!=0; i++)  {
          SFUT_TESTMSG("Erase %dKB block (busy suspend %d qbits) \r\n", eusize[i], SFUT_IntFreq_Erase);
          SFUT_ProgramPattern(D, address, 0x0, 0x0, KB(eusize[i]), KAL_FALSE);
          SFUT_Erase(D, address, KB(eusize[i]), SFUT_IntFreq_Erase);
      }
      }
  }


kal_uint32 SFUT_SuspendTest(SF_MTD_Data *D, kal_uint32 address, kal_uint32 erase_unit)
{
    kal_int32 i;
    kal_int32 result=FS_NO_ERROR;
    kal_uint32 int_freq_top, int_freq_bottom;

    // Step 1: Turning erase suspend latency, using binary approach.
    SFUT_TESTMSG("Suspend Frequency Test: Erase \r\n");
    int_freq_top=SFUT_ERASE_SUSPEND_FREQUENCY;   // i.e. last working intrrupt frequency.
    int_freq_bottom=1;

    for ( i=0; i<SFUT_SUSPEND_TEST_ITERATION; i++)    {
        SFUT_IntFreq_Erase=(int_freq_top+int_freq_bottom)/2;
        SFUT_DEBUG("Interrupt frequency %d us \r\n", SFUT_IntFreq_Erase);
        // If the erase was timeout, it will return FS_TIMEOUT
        result=SFUT_Erase(D, address+i*KB(erase_unit), KB(erase_unit), SFUT_IntFreq_Erase);
        if (result==FS_TIMEOUT)
            int_freq_bottom=SFUT_IntFreq_Erase;
        else
            int_freq_top=SFUT_IntFreq_Erase;
    }
    SFUT_IntFreq_Erase=int_freq_top;

    SFUT_DEBUG("Suspend Frequency: Erase %d us \r\n",SFUT_IntFreq_Erase);


    // Step 2: Turning program suspend latency
    SFUT_TESTMSG("Suspend Frequency Test: program \r\n");
    int_freq_top=SFUT_PROG_SUSPEND_FREQUENCY;   // i.e. last working intrrupt frequency.
    int_freq_bottom=1;

    SFUT_PatternFillSequential(&sfut_buff[0], PAGE_SIZE);

    for ( i=0; i<SFUT_SUSPEND_TEST_ITERATION; i++)    {
        SFUT_IntFreq_Prog=(int_freq_top+int_freq_bottom)/2;
        SFUT_DEBUG("Interrupt frequency %d us \r\n", SFUT_IntFreq_Prog);
        // If the erase was timeout, it will return FS_TIMEOUT
        SFUT_IntBusySuspend=SFUT_IntFreq_Prog;
        result=SF_DAL_ProgramData(D, (void*)(address+i*PAGE_SIZE), &sfut_buff[0], PAGE_SIZE);
        SFUT_IntBusySuspend=0;
        if (result==FS_TIMEOUT)
            int_freq_bottom=SFUT_IntFreq_Prog;
        else
            int_freq_top=SFUT_IntFreq_Prog;
}
    SFUT_IntFreq_Prog=int_freq_top;

    SFUT_DEBUG("Suspend Frequency: Program %d us\r\n", SFUT_IntFreq_Prog);

    return 0;
}

typedef enum {
    BeforeErase=0,
    AfterErase=1,
    EraseSuspend=2,
    ProgramSuspend=3,
    BeforeProgram=4,
    AfterProgram=5
} SFUT_Enum_disturb_stage;

static const kal_uint8 *sfut_disturb_stage[]={
    "Before Erase",
    "After Erase",
    "Erase Suspended",
    "Program Suspended",
    "Before Program",
    "After Program"
};

kal_uint32 SFUT_DisturbanceCheck(kal_uint32 start, kal_uint32 end, kal_uint32 curr, kal_uint32 erase_unit, kal_int32 stage)
{
    kal_uint32 ptr, i, fail_count=0;
    kal_uint8  expected_val, read_val, seed;

    // for each page
    for (ptr=start; ptr<end; )  {
        // Skips current erasing block
        if (ptr==curr && stage==BeforeErase) {
            ptr+=erase_unit;
            continue;
        }

        // Skips the page that not yet programmed
        if (SFI_ReadReg32(ptr)==0xFFFFFFFF) {
            ptr+=PAGE_SIZE;
            continue;
        }

        seed=SFI_ReadReg8(ptr);

        // read backward
        for (i= (suspend_disturb_check_ptr!=0)?3:(PAGE_SIZE-1); i>0; i--) {
            read_val=SFI_ReadReg8(ptr+i);
            expected_val=seed+i;
            if (read_val!=expected_val) {
                SFUT_DEBUG("Disturbance Detected %s @ 0x%08x, expected: %02Xh, read: %02Xh \r\n",
                    sfut_disturb_stage[stage],
                    ptr+i, expected_val, read_val);
                fail_count++;
            }
        }
        ptr+=PAGE_SIZE;
    }
    return fail_count;
}


/*
[description]
   Erase/Program distrubance test, using smallest erase unit over a 256KB area.
[steps]
   1. Program seqentail patterns on the 256KB area before erase.
   2. Each page has different pattern seeds
   3. Sequentially erase the 256KB area using smallest erase unit (ex:4KB).
   4. After erase done,  check entire 256KB data except the erased sub-sector.
   5. Program pattern back to the erased block, page by page.
   6. After each page program, check the data with in the same sub-sector.
   7. Repeat step #3 till test time out
*/

kal_bool SFUT_DisturbanceTestLoop(
    SF_MTD_Data *D,
    kal_uint32 start,
    kal_uint32 end,
    kal_uint32 erase_unit,
    kal_uint32 program_suspend_frequency,
    kal_uint32 erase_suspend_frequency)
{
    sfut_rtc_time rtctime_current, rtctime_start;
    kal_uint8  *buff=(kal_uint8*)&sfut_buff[0];
    kal_uint32 ptr, i, j;

    suspend_disturb_check_start=start;
    suspend_disturb_check_end=end;
    suspend_disturb_check_eu=erase_unit;

    // Disable Erase/Program suspend, if the given suspend frequency euqals zero
    if (0==program_suspend_frequency) {
        sfut_suspend_enable|=SFUT_DISABLE_PROG_SUSPEND;
    }
    if (0==erase_suspend_frequency) {
        sfut_suspend_enable|=SFUT_DISABLE_ERASE_SUSPEND;
    }

    SFUT_RTCGetCurrentTime(&rtctime_start);

    // Stop Condition 1: Loop Limit Reached
    for (j=SFUT_DISTURBANCE_LOOP_LIMIT; j>0; j--)  {
        kal_uint32 totalblocks;

        SFUT_RTCGetCurrentTime(&rtctime_current);
        SFUT_RTCPrint(&rtctime_current);

        // Stop Condition 2: Test time out
        if (SFUT_RTCGetDuration(&rtctime_start, &rtctime_current) > HOUR(SFUT_DISTURBANCE_TIME_LIMIT)) break;

        // Stop Condition 3: Target test coverage is reached
        #ifdef SFUT_SHOW_TEST_COVERAGE

        // case 1: Target program test coverage is reached and there's no erase suspend test
        if ( (sfut_distrub_test_coverage_program < SFUT_TARGET_TEST_COVERAGE ) &&
             (erase_suspend_frequency==0) ) {
            break;
        }
        // case 2: Target erase test coverage is reached and there's no program suspend test
        else if ( (sfut_distrub_test_coverage_erase < SFUT_TARGET_TEST_COVERAGE) &&
                  (program_suspend_frequency==0) ) {
            break;
        }
        // case 3: Both erase/program test coverage are reached
        else if ( (sfut_distrub_test_coverage_program < SFUT_TARGET_TEST_COVERAGE) &&
                  (sfut_distrub_test_coverage_erase < SFUT_TARGET_TEST_COVERAGE) ) {
            break;
        }
        #endif  // SFUT_SHOW_TEST_COVERAGE

        // Randomly selects a block
        totalblocks = (end-start) / KB(erase_unit);
        ptr = start + KB(erase_unit)*(rand()%totalblocks);

        SFUT_DEBUG("<Distrubance Check> Erase %08Xh \r\n", ptr);
        // during erase: check data in nearby blocks after suspend
        suspend_disturb_check_ptr=ptr;

        if (SFUT_DisturbanceCheck(start, end, ptr, KB(erase_unit), BeforeErase) > 0) {
            ASSERT(0);
        }

        SFUT_Erase(D, ptr, KB(erase_unit), erase_suspend_frequency);
        SFUT_TestCoverage_Erase();

#ifdef SFUT_MSDC_CONCURRENCY_TEST
        kal_sleep_task(10);
#endif

        suspend_disturb_check_ptr=0;
        // after erase: check data in nearby blocks
        if (SFUT_DisturbanceCheck(start, end, ptr, KB(erase_unit), AfterErase) > 0) {
            ASSERT(0);
        }

        // program the pattern back to the erased block
        for (i=ptr+KB(erase_unit)-PAGE_SIZE; i>ptr; i-=PAGE_SIZE)   {
        SFUT_IntBusySuspend=program_suspend_frequency;
            SF_DAL_ProgramData(D, (void*)i, &buff[rand()&0xFF], PAGE_SIZE);
            SFUT_TestCoverage_Program();
            if (SFUT_DisturbanceCheck(ptr, ptr+KB(erase_unit), ptr, KB(erase_unit), AfterProgram) > 0) {
                ASSERT(0);
            }
        }

#ifdef SFUT_MSDC_CONCURRENCY_TEST
        kal_sleep_task(10);
#endif

        SFUT_IntBusySuspend=0;
        SFUT_TestCoverage();

    }

    // Resume erase/program suspend
    sfut_suspend_enable=0;

    return KAL_TRUE;
}


kal_bool SFUT_DisturbanceTest(SF_MTD_Data *D, kal_uint32 address)
{
    kal_uint32  erase_unit, i;
    kal_uint32  start, end, ptr;
    kal_uint8  *buff=(kal_uint8*)&sfut_buff[0];
	
#ifndef __SERIAL_FLASH_MEMORY_SLT__ //Memory SLT can not test too long(Money concerns), thus only use smallest erase unit to do Disturbance Test
	kal_uint16 b=1,a;
	kal_uint8 count=0;
	kal_uint8 first_UniformErase=0;
	a = D->UniformBlock;
	//Scan UniformBlock to find Native device supported erase unit
	//ex: UniformBlock = 0110 0100, device supports 4KB, 32KB, 64KB erase
	//      DisturbanceTest of 4KB  : 1. Erase Distrubance Test 2. Program Disturbacne Test 3. Erase+Program Distrubance Test
	//      DisturbanceTest of 32KB: 1. Erase Distrubance Test 
	//      DisturbanceTest of 64KB: 1. Erase Distrubance Test 
	//32KB and 64KB Erase Disturbance Test are added here to cover all native erase unit supported by the device
	
	for(count=0 ; count<16 ; count++,a=a>>1)
	{
		if(a&b)
		{
			first_UniformErase++;
			erase_unit = 1 <<(count);

			//Set "SFUT_IntFreq_Prog" and "SFUT_IntFreq_Erase" to zero in order to tune Suspend frequency for specific erase_unit (4KB/32KB/64KB)
			SFUT_IntFreq_Prog = SFUT_IntFreq_Erase =0; 
#else
	
	// Find the smallest erase unit (must be uniform)
	for (i=0; eusize[i+1]!=0; i++);
	erase_unit=eusize[i];
#endif
		    if (SFUT_IntFreq_Prog==0 || SFUT_IntFreq_Erase==0)  {
		        SFUT_SuspendTest(D, address, erase_unit);
		    }

		    SFUT_TESTMSG("Distrubance Test Initialization (erase unit: %dKB)\r\n", erase_unit);

		    // Assume the end of the FS is aligned to 256KB boundary
		    start = SFUT_FSBASE + SFUT_FLASHBASE;
		    end = start + SFUT_FSSIZE;

		    // To Speed up the test, the test range is limited to 256KB.
		    if (SFUT_FSSIZE >= KB(256))   {
		        start = end - KB(256);
		    }

		    SFUT_DEBUG("<Distrubance Check> Test range: %08Xh ~ %08Xh \r\n", start, end);

		    // Erase all blocks with in the same 256KB group (using largest uniform blocks)
		    for (ptr=start; ptr<end; ptr+=KB(eusize[0]))  {
		        SFUT_Erase(D, ptr, KB(eusize[0]), 0);
		    }

		    // Fill the buffer with sequential pattern (2 pages)
		    SFUT_PatternFillSequential(&sfut_buff[0], PAGE_SIZE*2);

		    // program all patterns page by page
		    for (ptr=start; ptr<end; ptr+=PAGE_SIZE)    {
		        //SFUT_DEBUG("<Distrubance Check> Program Patterns to %08Xh \r\n", ptr);
		        SF_DAL_ProgramData(D, (void*)ptr, &buff[rand()&0xFF], PAGE_SIZE);
		    }

		    SFUT_TestCoverage_Init();

#ifdef SFUT_TEST_ERASE_DISTURBANCE
		    SFUT_TESTMSG("Erase Distrubance Test \r\n");
		    SFUT_DisturbanceTestLoop(
		        D,
		        start,
		        end,
		        erase_unit,
		        0,
		        SFUT_IntFreq_Erase);
#endif

#ifdef SFUT_TEST_PROG_DISTURBANCE
		    SFUT_TESTMSG("Program Distrubance Test \r\n");
#ifndef __SERIAL_FLASH_MEMORY_SLT__
			//Only do Program Disturbance Test once
			if(first_UniformErase == 1)
#endif
		    	SFUT_DisturbanceTestLoop(
		      	   D,
		      	   start,
		     	   end,
		      	   erase_unit,
		       	   SFUT_IntFreq_Prog,
		     	   0);
#endif

#if defined(SFUT_TEST_ERASE_DISTURBANCE) && defined(SFUT_TEST_PROG_DISTURBANCE)
		    SFUT_TESTMSG("Erase+Program Distrubance Test \r\n");
#ifndef __SERIAL_FLASH_MEMORY_SLT__
			//Only do Program Disturbance Test once
			if(first_UniformErase == 1)
#endif
			    SFUT_DisturbanceTestLoop(
			        D,
			        start,
			        end,
			        erase_unit,
			        SFUT_IntFreq_Prog,
			        SFUT_IntFreq_Erase);
#endif

    		SFUT_TestCoverage();
#ifndef __SERIAL_FLASH_MEMORY_SLT__
		}
	}
#endif
    return KAL_TRUE;
}

kal_bool SFUT_IsFirstBoot(void)
{
    kal_uint32 ptr = SFUT_FSBASE;
    kal_uint32 baseaddr = SFUT_FLASHBASE;
    kal_uint32 fsend = baseaddr + ptr;

    // For each block defined in combom memory region info
    for (; ptr<fsend; ptr+=CMEM_BlockSize(ptr))    {
        // Check the block was erased
        if (SFI_ReadReg32(ptr+baseaddr) != 0xFFFFFFFF)   {
            return KAL_FALSE;
        }
    }
    return KAL_TRUE;
}

void SFUT_Init(void)
{
    kal_uint32 i=0, blksize;

    // RTC Clock Init
    SFUT_RTCTInit();

    // GPIO Init
    SFUT_Init_GPIO();

    // Insert LISR
    SFUT_LISRInsert();

    // Mount SF Driver
    SF_DAL_MountDevice(&mtdflash, &sfut_buff[0]);
    SFUT_DEBUG("Flash ID: 0x%02X 0x%02X 0x%2X \r\n",
        mtdflash.FlashID[0], mtdflash.FlashID[1], mtdflash.FlashID[2]);

    // Erase Units
    kal_mem_set(eusize, 0, 8);
    // always let eusize[0] be the largest erase unit (for erase disturbance check)
    eusize[i++]=64;

    // Vendor Specific Test Options
    switch (mtdflash.FlashID[0])    {
        // Accepts 4, 64KB erase
        case SF_DAL_TYPE_EON:
        case SF_DAL_TYPE_FIDELIX:
            eusize[i++]=4;
            break;
        // Accpets 4, 32, 64 KB erase
        case SF_DAL_TYPE_SST:
        case SF_DAL_TYPE_MXIC:
        case SF_DAL_TYPE_WINBOND:
            eusize[i++]=32;
            eusize[i++]=4;
            break;
        // default: Current Combom Memory Block Size and 64KB erase
        default:
            blksize=CMEM_BlockSize(SFUT_FSBASE);
            switch (blksize) {
                case 0x8000: eusize[i++]=32;
                case 0x1000: eusize[i++]=4;
                break;
            }
            break;
    }

    // Frequenct Hopping
    #if (defined(__NOR_FLASH_HARDWARE_TEST__) && defined(__MAUI_BASIC__))
    FH_Fixed_80Mhz();
    #endif
}

#if (!defined(__MAUI_BASIC__))
extern kal_uint16 L1_ASSERT_BYPASS;
#endif

kal_bool SFUT_DeviceTest(void)
{
    SF_MTD_Data *D = &mtdflash;
    kal_uint32 baseaddr = SFUT_FLASHBASE+SFUT_FSBASE;
    sfut_result=KAL_TRUE;

    // init stage does not have interrupts
    // 1st stage: stack_init() > SFUT_DeviceTest()
    if (KAL_TRUE == kal_query_systemInit()) {
        SFUT_DEBUG("====== Serial Flash Device Funcational Phase 1 ====== \r\n");
        SFUT_DEBUG("Test Address: 0x%08X, Ranage 0x%08X \r\n", SFUT_FSBASE, SFUT_FSSIZE);
        SFUT_Init();

#ifdef SFUT_TEST_ERASE_PROGRAM_WITHOUT_SUSPEND
        SFUT_EraseTest(D, baseaddr);
        SFUT_ProgramTest(D, baseaddr);
#endif

        SFUT_READY_BASIC();

#ifdef SFUT_TEST_MACRO_READ
        SFUT_ReadTest(D, baseaddr-PAGE_SIZE*3);
#endif
        SFUT_TESTTIME_Print();
        SFUT_TESTTIME_Reset();
        SFUT_READY_WRAP();
    }
    // interrupt test
    // 2nd stage: ssdbg1_main() > NOR_Flash_Test() > SFUT_DeviceTest()
    else  {
        SFUT_DEBUG("====== Serial Flash Device Funcational Phase 2 ====== \r\n");

#if (defined(IC_MODULE_TEST) || defined(IC_BURNIN_TEST))
        // Persist FDM lock to prevent other task reading corrupted FS
        GetFDMLock();
#else
        // Memory SLT and Device Test do not involved with NOR FDM
        // The MTD drive is already intialized in 1st stage.
#endif

        #if (!defined(__MAUI_BASIC__))
        L1_ASSERT_BYPASS=0x3;
        #endif

        SFUT_SuspendTest(D, baseaddr, eusize[0]);

#ifdef SFUT_TEST_ERASE_PROGRAM_WITH_SUSPEND
        SFUT_EraseTest(D, baseaddr);
        SFUT_IntBusySuspend=SFUT_IntFreq_Prog;
        SFUT_ProgramTest(D, baseaddr);
        SFUT_IntBusySuspend=0;
#endif

#ifdef SFUT_TEST_WRAP_READ
        //Do WrapReadTest only if the Device has Wrap Read support 
        if( SFI_GetWrapMode )
        SFUT_WrapReadTest(D, SFUT_ROMBASE, SFUT_ROMSIZE);
#endif

#if defined(SFUT_TEST_ERASE_DISTURBANCE) && defined(SFUT_TEST_PROG_DISTURBANCE)
        SFUT_DisturbanceTest(D, baseaddr);
#endif

        SFUT_TESTTIME_Print();
        SFUT_DEBUG("====== Serial Flash Device Funcational Test End ====== \r\n");
        SFUT_DEBUG("Test Result: %s \r\n", ((sfut_result)?"Pass":"Fail") );
        SFUT_DEBUG("====== Serial Flash Device Funcational Test End ====== \r\n");

        SFUT_READY_SUSPEND();
        // SFUT_CorruptNOR();
    }
    return sfut_result;
}

//-----------------------------------------------------------------------------
/*!
  @brief
     Memory compare with read test
  @param[in] src The source address on Serial Flash
  @param[in] dest The destination address on PSRAM/INTSRAM
  @retval
     >0: Number of bytes copied
     -1: copy failed
 */
__sf_section_RAM kal_int32 SFUT_memcmp(void *destaddr, void *srcaddr, kal_uint32 length)
{
    // Stripping read sequence:
    // Jump to another 32 bytes boundary, so that SFC can refill its read buffer.

    // [Full Ver.]
    //  0, 32, 64, ..., 480
    //  1, 33, 65, ..., 481
    //  ....
    //  31, 63, 95, ..., 511

    // [Simple Ver.] since SFC always issue 32bits aligned address
    //  0, 32, 64, ..., 480
    //  4, 36, 68, ..., 484
    //  ...
    //  28, 60, 92, ..., 508

    // Verification group:
    // 0~31, 32~63, 64~71, ..., 480~511

    kal_uint8 *src=srcaddr, *dest=destaddr;
    kal_uint32 i, j, k, g, p;
    kal_uint32 srcdata, destdata; // , savedMask;
    kal_bool failed=KAL_FALSE;

    // Stripping read sequence (full ver.)
    // For different starting offest (0~31 or 0~28)
    for (i=0; i<32; i+=4)    {
        // For 32bytes groups in the page
        for (j=i ; j<length; j+=32)   {
            g=(j>>5)<<5; // Get group number
            //SF_DAL_DEBUG("%03X: ", j);
            //savedMask = SaveAndSetIRQMask();
            // for each byte in the same warp read
            for (k=0; k<32; k++)    {
                p=g+(k+j-g)%32; // Get offset
                //SF_DAL_DEBUG("%03X ", p);
                srcdata=src[p];
                destdata=dest[p];
                if (srcdata!=destdata)  {
                    //RestoreIRQMask(savedMask);
                    SFUT_DEBUG("Read Fail: Start,Offset=%08X,%08X(%d,%d)  NOR:%08X(%02X) RAM:%08X(%02X) \r\n",
                        &src[j], &src[p], j%32, p%32,
                        &src[p], srcdata,
                        &dest[p], destdata);
                    k=0;
                    failed=KAL_TRUE;
                    //savedMask = SaveAndSetIRQMask();
                }
            }
            //SF_DAL_DEBUG("\r\n");
            //RestoreIRQMask(savedMask);
        }
    }
    //SF_DAL_DEBUG("\r\n");

    if (failed) return -1;
    return length;
}

__sf_section_RAM kal_int32 SFUT_memcpy(void *destaddr, void *srcaddr, kal_uint32 length)
{
    // Copy entire memory
    kal_mem_cpy(destaddr, srcaddr, length);

    // Memory compare
    // skips those length < 32 bytes, and performance profiling
    #if (defined(__NOR_FLASH_HARDWARE_TEST__) && defined(__MAUI_BASIC__))
    if (0 != NORProfileProcess) return length;
    #endif
    if (0 != length%32) return length;
    return SFUT_memcmp(destaddr, srcaddr, length);
}
//-----------------------------------------------------------------------------
// SLT Test API
//-----------------------------------------------------------------------------

__sf_section_RAM void SFUT_CorruptFS(void)
{
    kal_uint32 i, data;
    kal_uint32 address;

    // Align address to 4 KB offset
    address = SFUT_FSBASE + SFUT_FLASHBASE + SFUT_FSSIZE - KB(128);
    address = (address >> 12) << 12;

    data=0x01000000;

    // Program on Every 4KB offset
    for (i=0; i<KB(128); i+=KB(4))   {
        Flash_ProgramData((void*)(address+i), &data ,4);
    }
}

__sf_section_RAM void SFUT_CorruptROM(void)
{
    kal_uint32 i, data=0;
    for (i=0; i<KB(128); i+=KB(4))   {
        Flash_ProgramData((void*)i, &data ,4);
    }
}

__sf_section_RAM void SFUT_CorruptNOR(void)
{
    SFUT_CorruptFS();
    SFUT_CorruptROM();
}



//-----------------------------------------------------------------------------
// Serial Flash Test LISR
//-----------------------------------------------------------------------------
#if defined(__SF_DVT__)
void SFUT_LISRInsert(void)
{
}

void SFUT_IntTrigger(void)
{
    Flash_ReturnReady();
}

#else  // SF_DVT

extern kal_bool NOR_FLASH_BUSY;
extern kal_bool NOR_FLASH_SUSPENDED;

#if !defined(__FUE__) /* currently, no IRQ is enabled in FUE */
kal_bool SFUT_IRQ_ClearReady = KAL_TRUE;

// Interrupt Service Routine
void SFUT_LISR(void)
{
   extern NOR_FLASH_DRV_Data  FlashDriveData;
   NOR_Flash_MTD_Data  *mtd_data = (NOR_Flash_MTD_Data *)FlashDriveData.MTDData;
   static kal_uint32    trigger_count = 0;
   volatile kal_uint32 *ram_ptr = 0;

  //  &Image$$ROM$$Base is MAUI start address, store vector table
  // note: NOR_Flash_Base_Address must be set to Non-Cacheable

   extern kal_uint32 Image$$ROM$$Base;
   volatile kal_uint32* rom_ptr = (kal_uint32 *)&Image$$ROM$$Base;
   kal_uint32 data_cache_id;

   /* check whether the flash is in ready state */
   MTD_ASSERT(~(mtd_data->Signature) == ((kal_uint32)mtd_data->RegionInfo), 0, 0, 0, NOR_MTD_DATA_CORRUPTED);

   SFUT_IntServeTime = ust_get_current_time();
   SFUT_IntServeTime = ust_get_duration(SFUT_IntTriggerTime, SFUT_IntServeTime);
   if (SFUT_IntServeTime>1000)  {
       SFUT_DEBUG("Interrupt serve time is too long \r\n");
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

   // distrubance check in LISR
#if defined(SFUT_DISTURBANCE_CHECK_IN_LISR)
   if (suspend_disturb_check_ptr!=0)    {
            // during erase: check data in nearby blocks
            if (SFUT_DisturbanceCheck(
                    suspend_disturb_check_start,
                    suspend_disturb_check_end,
                    suspend_disturb_check_ptr,
                    KB(suspend_disturb_check_eu)) > 0) {
                ASSERT(0);
            }
   }
#endif

   SFUT_IntServe();
   IRQClearInt(TEST_IRQ_CODE);
   SFUT_IRQ_ClearReady = KAL_TRUE;
}

// Register LISR
void SFUT_LISRInsert(void)
{
   static kal_bool test_lisr_hooked = KAL_FALSE;

   if(!test_lisr_hooked)
   {
      IRQ_Register_LISR(TEST_IRQ_CODE, SFUT_LISR,"FAKE NFI");
      IRQSensitivity(TEST_IRQ_CODE,LEVEL_SENSITIVE);
      IRQUnmask(TEST_IRQ_CODE);
      test_lisr_hooked = KAL_TRUE;
   }
}


// Mark Interrupt as served
__sf_section_RAM void SFUT_IntServe(void)
{
   kal_uint8 line;

   if(!SFUT_IRQ_ClearReady)
   {
      line = TEST_IRQ_CODE;

      #if (defined(MT6253) || defined(MT6252) || defined(MT6252H))
      if (line<32) {
   		*IRQ_SOFTL &= ~(1 << line);
      } else {
         line = line - 32;
   		*IRQ_SOFTH &= ~(1 << line);
      }
      #elif (defined(MT6251) || defined(MT6255) || defined(MT6280)  || defined(MT6250))
        *IRQ_SOFT_CLR0 = (1 << TEST_IRQ_CODE);
      #else
      #error "Undefined Software Interrupt"
      #endif
   }
}

// Mark Interrupt as trigger
__sf_section_RAM void SFUT_IntTrigger(void)
{
   kal_uint8 line;

   SFUT_IntTriggerTime = ust_get_current_time();

   if(SFUT_IRQ_ClearReady)
   {
      SFUT_IRQ_ClearReady = KAL_FALSE;
      line = TEST_IRQ_CODE;
      #if (defined(MT6252) || defined(MT6252H))
      if (line<32) {
   		*IRQ_SOFTL = (1 << line);
      } else {
         line = line - 32;
   		*IRQ_SOFTH = (1 << line);
      }
      #elif (defined(MT6251) || defined(MT6255) || defined(MT6280) || defined(MT6250))
      *IRQ_SOFT_SET0 = (1 << TEST_IRQ_CODE);
      #else
      #error "Undefined Software Interrupt"
      #endif
   }
}


#else /* __FUE__ */

void SFUT_LISRInsert(void)
{
}

void SFUT_IntTrigger(void)
{
}

#endif /* !__FUE__ */

#endif // __SF_DVT__

#endif // SF_DEBUG

