/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2001
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   bus_monitor_mt6276.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Header file for MT6276 EMI BUS monitor control.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*
 * Please note that this file will be remove in custom release!!
 * Use it for debugging only.
 *
 * Example 1:
 *
 * #include "emi_bus_monitor_mt6276.h"
 *
 * int foo1()
 * {
 *     EBM_TCNT_LOG_T log1, log2;
 *     kal_bool ret;
 *
 *     // Clear All Counter
 *     EBM_Clear_Counter();
 *
 *     // Select bus master 
 *     EBM_SEL_MASTER(1, MCU_DBUS);
 *     EBM_SEL_MASTER(2, MCU_IBUS);
 *
 *     // Set monitor read write request
 *     EBM_SET_RW_REQ(Read_Write);
 *
 *     // Start EBM
 *     EBM_Start();
 *
 *     // SW to be measured
 *
 *     // Pause EMI bus-monitor logging
 *     EBM_Pause_LOG();
 *
 *     // Check whether counter is overflow
 *     ret = EBM_Check_Overrun();
 *     
 *     // overflow, need to break down logging process
 *     ASSERT(ret == kal_false);
 *
 *     // retrieve log
 *     EBM_GET_LOG(1, &log1);
 *     EBM_GET_LOG(2, &log2);
 *
 *     // Clear counter if necessary
 *     EBM_Clear_Counter();
 *
 *     // print MCU monitor counter
 *     printf("MCU_DBUS bus_ccnt = %d, trans_all_cnt = %d, trans_cnt = %d, word_all_cnt = %d, word_cnt = %d, busy_all_cnt = %d, busy_cnt = %d\n", log1.bus_ccnt, log1.trans_all_cnt, log11.trans_cnt, log1.word_all_cnt, log1.word_cnt, log1.busy_all_cnt, log1.busy_cnt);
 *     printf("MCU_IBUS bus_ccnt = %d, trans_all_cnt = %d, trans_cnt = %d, word_all_cnt = %d, word_cnt = %d, busy_all_cnt = %d, busy_cnt = %d\n", log2.bus_ccnt, log2.trans_all_cnt, log12.trans_cnt, log2.word_all_cnt, log2.word_cnt, log2.busy_all_cnt, log2.busy_cnt);
 * }
 *
 * Example 2:
 *
 * #include "emi_bus_monitor_mt6276.h"
 *
 * int foo2()
 * {
 *     EBM_TCNT_LOG_T tcnt_log1, tcnt_log2;
 *     EBM_TTYPE_LOG_T ttype_log;
 *     kal_bool ret;
 *
 *     // Clear All Counter
 *     EBM_Clear_Counter();
 *
 *     // Select bus master 
 *     EBM_SEL_MASTER(1, MCU_IBUS);
 *     EBM_SEL_MASTER(2, MCU_DBUS);
 *     EBM_SEL_MASTER(3, MCU_DBUS);
 *     EBM_SEL_MASTER(4, MCU_DBUS);
 *     EBM_SEL_MASTER(5, MCU_DBUS);
 *     EBM_SEL_MASTER(6, MCU_DBUS);
 *
 *     // Select transaction type
 *     EBM_SEL_TTYPE(2, SINGLE_1B);
 *     EBM_SEL_TTYPE(3, SINGLE_2B);
 *     EBM_SEL_TTYPE(4, SINGLE_4B);
 *     EBM_SEL_TTYPE(5, INC4_4B);
 *     EBM_SEL_TTYPE(6, INC8_4B);
 *
 *     // Set monitor read write request
 *     EBM_SET_RW_REQ(Read_Write);
 *
 *     // Start EBM
 *     EBM_Start();
 *
 *     // SW to be measured
 *
 *     // Pause EMI bus-monitor logging
 *     EBM_Pause_LOG();
 *
 *     // Check whether counter is overflow
 *     ret = EBM_Check_Overrun();
 *     
 *     // overflow, need to break down logging process
 *     ASSERT(ret == kal_false);
 *
 *     // retrieve log
 *     EBM_GET_LOG(1, &tcnt_log1);
 *     EBM_GET_LOG(2, &tcnt_log2);
 *     EBM_GET_TTYPE_LOG(&ttype_log);
 *
 *     // Clear counter if necessary
 *     EBM_Clear_Counter();
 *
 *     return 0;
 * }
 */

#if !defined(__EMI_BUS_MONITOR_MT6573_H__)
#define __EMI_BUS_MONITOR_MT6573_H__


/* RHR Add */
#include "reg_base.h"
#include "kal_general_types.h"
#include "kal_public_api.h"


/*******************************************************************************
 * Define HW register.
 *******************************************************************************/

#define EMI_BMEN   (volatile kal_uint32 *)(EMI_base + 0x0400)
#define EMI_BCNT   (volatile kal_uint32 *)(EMI_base + 0x0408)
#define EMI_TACT   (volatile kal_uint32 *)(EMI_base + 0x0410)
#define EMI_TSCT   (volatile kal_uint32 *)(EMI_base + 0x0418)
#define EMI_WACT   (volatile kal_uint32 *)(EMI_base + 0x0420)
#define EMI_WSCT   (volatile kal_uint32 *)(EMI_base + 0x0428)
#define EMI_BACT   (volatile kal_uint32 *)(EMI_base + 0x0430)
#define EMI_BSCT   (volatile kal_uint32 *)(EMI_base + 0x0438)
#define EMI_MSEL   (volatile kal_uint32 *)(EMI_base + 0x0440)
#define EMI_TSCT2  (volatile kal_uint32 *)(EMI_base + 0x0448)
#define EMI_TSCT3  (volatile kal_uint32 *)(EMI_base + 0x0450)
#define EMI_WSCT2  (volatile kal_uint32 *)(EMI_base + 0x0458)
#define EMI_WSCT3  (volatile kal_uint32 *)(EMI_base + 0x0460)
#define EMI_MSEL2  (volatile kal_uint32 *)(EMI_base + 0x0468)
#define EMI_MSEL3  (volatile kal_uint32 *)(EMI_base + 0x0470)
#define EMI_MSEL4  (volatile kal_uint32 *)(EMI_base + 0x0478)
#define EMI_MSEL5  (volatile kal_uint32 *)(EMI_base + 0x0480)
#define EMI_MSEL6  (volatile kal_uint32 *)(EMI_base + 0x0488)
#define EMI_MSEL7  (volatile kal_uint32 *)(EMI_base + 0x0490)
#define EMI_MSEL8  (volatile kal_uint32 *)(EMI_base + 0x0498)
#define EMI_MSEL9  (volatile kal_uint32 *)(EMI_base + 0x04A0)
#define EMI_MSEL10 (volatile kal_uint32 *)(EMI_base + 0x04A8)
#define EMI_BMID0  (volatile kal_uint32 *)(EMI_base + 0x04B0)
#define EMI_BMID1  (volatile kal_uint32 *)(EMI_base + 0x04B8)
#define EMI_BMID2  (volatile kal_uint32 *)(EMI_base + 0x04C0)
#define EMI_BMID3  (volatile kal_uint32 *)(EMI_base + 0x04C8)
#define EMI_BMID4  (volatile kal_uint32 *)(EMI_base + 0x04D0)
#define EMI_BMID5  (volatile kal_uint32 *)(EMI_base + 0x04D8)

#define EMI_TTYPE1   (volatile kal_uint32 *)(EMI_base + 0x0500)
#define EMI_TTYPE2   (volatile kal_uint32 *)(EMI_base + 0x0508)
#define EMI_TTYPE3   (volatile kal_uint32 *)(EMI_base + 0x0510)
#define EMI_TTYPE4   (volatile kal_uint32 *)(EMI_base + 0x0518)
#define EMI_TTYPE5   (volatile kal_uint32 *)(EMI_base + 0x0520)
#define EMI_TTYPE6   (volatile kal_uint32 *)(EMI_base + 0x0528)
#define EMI_TTYPE7   (volatile kal_uint32 *)(EMI_base + 0x0530)
#define EMI_TTYPE8   (volatile kal_uint32 *)(EMI_base + 0x0538)
#define EMI_TTYPE9   (volatile kal_uint32 *)(EMI_base + 0x0540)
#define EMI_TTYPE10  (volatile kal_uint32 *)(EMI_base + 0x0548)
#define EMI_TTYPE11  (volatile kal_uint32 *)(EMI_base + 0x0550)
#define EMI_TTYPE12  (volatile kal_uint32 *)(EMI_base + 0x0558)
#define EMI_TTYPE13  (volatile kal_uint32 *)(EMI_base + 0x0560)
#define EMI_TTYPE14  (volatile kal_uint32 *)(EMI_base + 0x0568)
#define EMI_TTYPE15  (volatile kal_uint32 *)(EMI_base + 0x0570)
#define EMI_TTYPE16  (volatile kal_uint32 *)(EMI_base + 0x0578)
#define EMI_TTYPE17  (volatile kal_uint32 *)(EMI_base + 0x0580)
#define EMI_TTYPE18  (volatile kal_uint32 *)(EMI_base + 0x0588)
#define EMI_TTYPE19  (volatile kal_uint32 *)(EMI_base + 0x0590)
#define EMI_TTYPE20  (volatile kal_uint32 *)(EMI_base + 0x0598)
#define EMI_TTYPE21  (volatile kal_uint32 *)(EMI_base + 0x05A0)

/*******************************************************************************
 * Define constants.
 *******************************************************************************/

/*
 * M0 : MM1
 * M1 : MM2
 * M2 : APMCU
 * M3 : AUD/APPERI/DEBUG
 * M4 : FCORE
 * M5 : MDMCU
 * M6 : 2G/3G/MDPERI
 * M7 : DUMMY READ
 */
enum { MM1 = 0x1, MM2 = 0x2, APARM = 0x4, AUDIO_APPERI = 0x8, FCORE_DMA = 0x10, ARM = 0x20, TWOG3G_PERI = 0x40, DUMMY_READ = 0x80 };	

enum { Read_Write = 0x0, Read_Only = 0x1, Write_Only = 0x2 };

enum { SINGLE_1B = 0x40, SINGLE_2B = 0x50, SINGLE_4B = 0x60, SINGLE_8B = 0x70,
       INC2_4B = 0x61, INC2_8B = 0x71, INC3_4B = 0x62, INC3_8B = 0x72, 
       INC4_4B = 0x63, INC4_8B = 0x73, INC5_4B = 0x64, INC6_4B = 0x65, 
       INC7_4B = 0x66, WR2_8B = 0x33, WR4_8B = 0x33 };


/*******************************************************************************
 * Define data structures.
 *******************************************************************************/

/* data structure for EMI transaction counts */
typedef struct _EBM_TCNT_LOG_T
{
    kal_uint32 bus_ccnt;
    kal_uint32 trans_all_cnt;
    kal_uint32 trans_cnt;
    kal_uint32 word_all_cnt;
    kal_uint32 word_cnt;
    kal_uint32 busy_all_cnt;
    kal_uint32 busy_cnt;
} EBM_TCNT_LOG_T;

/* data structure for EMI transaction type */
typedef struct _EBM_TTYPE_LOG_T
{
    kal_uint32 ttype1, ttype2, ttype3, ttype4, ttype5, ttype6;
    kal_uint32 ttype7, ttype8, ttype9, ttype10, ttype11, ttype12;
    kal_uint32 ttype13, ttype14, ttype15;
} EBM_TTYPE_LOG_T;

/* data structure for EMI transcation log */
typedef struct _EBM_LOG_T
{
    EBM_TCNT_LOG_T tcnt;
    EBM_TTYPE_LOG_T ttype;
} EBM_LOG_T;


/*******************************************************************************
 * Define macros.
 *******************************************************************************/

#define EBM_SEL_MASTER(c, m)    \
        do {    \
            if ((c) == 1) { \
                *EMI_BMEN = *EMI_BMEN | ((m) << 16);    \
                *EMI_MSEL8 = (*EMI_MSEL8 & 0xffffff00) | (m); \
            } else if ((c) == 2) {  \
                *EMI_MSEL = (*EMI_MSEL & 0xffffff00) | (m); \
            } else if ((c) == 3) {  \
                *EMI_MSEL = (*EMI_MSEL & 0xff00ffff) | ((m) << 16); \
            } else if ((c) == 4) {  \
                *EMI_MSEL2 = (*EMI_MSEL2 & 0xffffff00) | (m); \
            } else if ((c) == 5) {  \
                *EMI_MSEL2 = (*EMI_MSEL2 & 0xff00ffff) | ((m) << 16); \
            } else if ((c) == 6) {  \
                *EMI_MSEL3 = (*EMI_MSEL3 & 0xffffff00) | (m); \
            } else if ((c) == 7) {  \
                *EMI_MSEL3 = (*EMI_MSEL3 & 0xff00ffff) | ((m) << 16); \
            } else if ((c) == 8) {  \
                *EMI_MSEL4 = (*EMI_MSEL4 & 0xffffff00) | (m); \
            } else if ((c) == 9) {  \
                *EMI_MSEL4 = (*EMI_MSEL4 & 0xff00ffff) | ((m) << 16); \
            } else if ((c) == 10) {  \
                *EMI_MSEL5 = (*EMI_MSEL5 & 0xffffff00) | (m); \
            } else if ((c) == 11) {  \
                *EMI_MSEL5 = (*EMI_MSEL5 & 0xff00ffff) | ((m) << 16); \
            } else if ((c) == 12) {  \
                *EMI_MSEL6 = (*EMI_MSEL6 & 0xffffff00) | (m); \
            } else if ((c) == 13) {  \
                *EMI_MSEL6 = (*EMI_MSEL6 & 0xff00ffff) | ((m) << 16); \
            } else if ((c) == 14) {  \
                *EMI_MSEL7 = (*EMI_MSEL7 & 0xffffff00) | (m); \
            } else if ((c) == 15) {  \
                *EMI_MSEL7 = (*EMI_MSEL7 & 0xff00ffff) | ((m) << 16); \
            } else {    \
                ASSERT(0);  \
            }   \
        } while (0)

#define EBM_SEL_TTYPE(c, t) \
        do {    \
            if ((c) == 1) { \
                *EMI_BMEN = (*EMI_BMEN & 0x00fffffff) | ((kal_uint32)(t) << 24);    \
                *EMI_MSEL8 = (*EMI_MSEL8 & 0xffff00ff) | ((kal_uint32)(t) << 8); \
            } else if ((c) == 2) {  \
                *EMI_MSEL = (*EMI_MSEL & 0xffff00ff) | ((kal_uint32)(t) << 8); \
            } else if ((c) == 3) {  \
                *EMI_MSEL = (*EMI_MSEL & 0x00ffffff) | ((kal_uint32)(t) << 24); \
            } else if ((c) == 4) {  \
                *EMI_MSEL2 = (*EMI_MSEL2 & 0xffff00ff) | ((kal_uint32)(t) << 8); \
            } else if ((c) == 5) {  \
                *EMI_MSEL2 = (*EMI_MSEL2 & 0x00ffffff) | ((kal_uint32)(t) << 24); \
            } else if ((c) == 6) {  \
                *EMI_MSEL3 = (*EMI_MSEL3 & 0xffff00ff) | ((kal_uint32)(t) << 8); \
            } else if ((c) == 7) {  \
                *EMI_MSEL3 = (*EMI_MSEL3 & 0x00ffffff) | ((kal_uint32)(t) << 24); \
            } else if ((c) == 8) {  \
                *EMI_MSEL4 = (*EMI_MSEL4 & 0xffff00ff) | ((kal_uint32)(t) << 8); \
            } else if ((c) == 9) {  \
                *EMI_MSEL4 = (*EMI_MSEL4 & 0x00ffffff) | ((kal_uint32)(t) << 24); \
            } else if ((c) == 10) {  \
                *EMI_MSEL5 = (*EMI_MSEL5 & 0xffff00ff) | ((kal_uint32)(t) << 8); \
            } else if ((c) == 11) {  \
                *EMI_MSEL5 = (*EMI_MSEL5 & 0x00ffffff) | ((kal_uint32)(t) << 24); \
            } else if ((c) == 12) {  \
                *EMI_MSEL6 = (*EMI_MSEL6 & 0xffff00ff) | ((kal_uint32)(t) << 8); \
            } else if ((c) == 13) {  \
                *EMI_MSEL6 = (*EMI_MSEL6 & 0x00ffffff) | ((kal_uint32)(t) << 24); \
            } else if ((c) == 14) {  \
                *EMI_MSEL7 = (*EMI_MSEL7 & 0xffff00ff) | ((kal_uint32)(t) << 8); \
            } else if ((c) == 15) {  \
                *EMI_MSEL7 = (*EMI_MSEL7 & 0x00ffffff) | ((kal_uint32)(t) << 24); \
            } else {    \
                ASSERT(0);  \
            }   \
        } while (0)

#define EBM_SET_RW_REQ(v) \
        {\
        	*EMI_BMEN = (*EMI_BMEN & 0xffffffcf) | ((v) << 4);\
        }
        
#define EBM_Start() \
        {\
        	*EMI_BMEN |= 0x401;\
        }

#define EBM_Pause_LOG() \
        {\
        	*EMI_BMEN |= 2;\
        }

#define EBM_Check_Overrun() ((*EMI_BMEN&0x100)==0?KAL_FALSE:KAL_TRUE)

#define EBM_GET_TCNT_LOG(c, l)   \
        do {    \
        	(l)->bus_ccnt = *EMI_TSCT;  \
        	(l)->trans_all_cnt = *EMI_TACT; \
        	(l)->word_all_cnt = *EMI_WACT;  \
        	(l)->busy_all_cnt = *EMI_BACT;  \
            if ((c) == 1) { \
                (l)->trans_cnt = *EMI_TSCT; \
                (l)->word_cnt = *EMI_WSCT;  \
                (l)->busy_cnt = *EMI_BSCT;  \
            } else if ((c) == 2) {  \
                (l)->trans_cnt = *EMI_TSCT2; \
                (l)->word_cnt = *EMI_WSCT2;  \
                (l)->busy_cnt = 0;  \
            } else if ((c) == 3) {  \
                (l)->trans_cnt = *EMI_TSCT3; \
                (l)->word_cnt = *EMI_WSCT3;  \
                (l)->busy_cnt = 0;  \
            } else {    \
                ASSERT(0);  \
            }   \
        } while (0)

#define EBM_GET_TTYPE_LOG(l)    \
        do {    \
            (l)->ttype1 = *(EMI_TTYPE1);    \
            (l)->ttype2 = *(EMI_TTYPE2);    \
            (l)->ttype3 = *(EMI_TTYPE3);    \
            (l)->ttype4 = *(EMI_TTYPE4);    \
            (l)->ttype5 = *(EMI_TTYPE5);    \
            (l)->ttype6 = *(EMI_TTYPE6);    \
            (l)->ttype7 = *(EMI_TTYPE7);    \
            (l)->ttype8 = *(EMI_TTYPE8);    \
            (l)->ttype9 = *(EMI_TTYPE9);    \
            (l)->ttype10 = *(EMI_TTYPE10);    \
            (l)->ttype11 = *(EMI_TTYPE11);    \
            (l)->ttype12 = *(EMI_TTYPE12);    \
            (l)->ttype13 = *(EMI_TTYPE13);    \
            (l)->ttype14 = *(EMI_TTYPE14);    \
            (l)->ttype15 = *(EMI_TTYPE15);    \
        } while (0)

#define EBM_Clear_Counter() \
        {\
        	*EMI_BMEN &= 0xfffffffc;\
        }

#define EBM_Restart_Counter() \
        {\
        	*EMI_BMEN &= 0xfffffffd;\
        }


/*******************************************************************************
 * Implement abstration interface.
 *******************************************************************************/

#define EBM_INIT()  \
        do {    \
            EBM_Clear_Counter();    \
            EBM_SEL_MASTER(1, ARM);    \
            EBM_SEL_MASTER(2, ARM);    \
            EBM_SEL_MASTER(3, ARM);    \
            EBM_SEL_MASTER(4, ARM);    \
            EBM_SEL_MASTER(5, ARM);    \
            EBM_SEL_MASTER(6, ARM);    \
            EBM_SEL_MASTER(7, ARM);    \
            EBM_SEL_MASTER(8, ARM);    \
            EBM_SEL_MASTER(9, ARM);    \
            EBM_SEL_MASTER(10, ARM);    \
            EBM_SEL_MASTER(11, ARM);    \
            EBM_SEL_MASTER(12, ARM);    \
            EBM_SEL_MASTER(13, ARM);    \
            EBM_SEL_MASTER(14, ARM);    \
            EBM_SEL_MASTER(15, ARM);    \
            EBM_SEL_TTYPE(1, SINGLE_1B);    \
            EBM_SEL_TTYPE(2, SINGLE_2B);    \
            EBM_SEL_TTYPE(3, SINGLE_4B);    \
            EBM_SEL_TTYPE(4, SINGLE_8B);    \
            EBM_SEL_TTYPE(5, INC2_4B);      \
            EBM_SEL_TTYPE(6, INC2_8B);      \
            EBM_SEL_TTYPE(7, INC3_4B);      \
            EBM_SEL_TTYPE(8, INC3_8B);      \
            EBM_SEL_TTYPE(9, INC4_4B);      \
            EBM_SEL_TTYPE(10, INC4_8B);     \
            EBM_SEL_TTYPE(11, INC5_4B);     \
            EBM_SEL_TTYPE(12, INC6_4B);     \
            EBM_SEL_TTYPE(13, INC7_4B);     \
            EBM_SEL_TTYPE(14, WR2_8B);      \
            EBM_SEL_TTYPE(15, WR4_8B);      \
            EBM_SET_RW_REQ(Read_Write);     \
        } while (0)

#define EBM_START() \
        do {    \
            EBM_Start();    \
        } while (0)

#define EBM_PAUSE() \
        do {    \
            EBM_Pause_LOG();    \
        } while (0)

#define EBM_GET_MCU_IBUS_LOG(l)  \
        do {    \
            kal_bool ret;   \
            ret = EBM_Check_Overrun();  \
            ASSERT(ret == KAL_FALSE);   \
            EBM_GET_TCNT_LOG(2, &((l)->tcnt)); \
        } while (0)

#define EBM_GET_MCU_DBUS_LOG(l)  \
        do {    \
            kal_bool ret;   \
            ret = EBM_Check_Overrun();  \
            ASSERT(ret == KAL_FALSE);   \
            EBM_GET_TCNT_LOG(2, &((l)->tcnt)); \
            EBM_GET_TTYPE_LOG(&((l)->ttype));   \
        } while (0)

#define EBM_GET_MCU_BUS_LOG(l)  \
        do {    \
            kal_bool ret;   \
            ret = EBM_Check_Overrun();  \
            ASSERT(ret == KAL_FALSE);   \
            EBM_GET_TCNT_LOG(2, &((l)->tcnt)); \
            EBM_GET_TTYPE_LOG(&((l)->ttype));   \
        } while (0)
        
#define EBM_RESUME()    \
        do {    \
            EBM_Restart_Counter();  \
        } while (0)

#define EBM_STOP()  \
        do {    \
            EBM_Clear_Counter() \
        } while (0)

#endif  /* !__EMI_BUS_MONITOR_MT6573_H__ */

