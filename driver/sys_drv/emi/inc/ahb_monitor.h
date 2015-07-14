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
 *   bus_monitor.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Header file for BUS monitor control.
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*
 * Please note that this file will be remove in custom release!!
 * Use it for debugging only.
 *
 * Example to use bus monitor:
 *
 * #include "ahb_monitor.h"
 *
 * int foo()
 * {
 *     BM_LOG_T log;
 *
 *     // set layer2 filters
 *     BM_SET_FILTER(BM_ARM7);
 *
 *     // begin of bus-monitor logging
 *     BM_BEGIN_LOG_ALL();
 *
 *     // SW to be measured
 *
 *     // end of bus-monitor logging
 *     BM_END_LOG_ALL();
 *
 *     // retrieve log
 *     BM_GET_LOG(&log);
 *
 *     // print layer3 counter
 *     printf("accnt = %d\n", log.accnt);
 * }
 */

#if !defined(__AHB_MONITOR_H__)
#define __AHB_MONITOR_H__


/* RHR Add */
#include "kal_general_types.h"


/*******************************************************************************
 * Define Chip-dependet settings.
 *******************************************************************************/

#if defined(MT6253T) || defined(MT6253)
#define __AHB_MONITOR_SUPPORT__
#define AM_base 0x810b0000
#endif  /* MT6253T || MT6253 */


/*******************************************************************************
 * Define HW register.
 *******************************************************************************/

#define AHBMON_EN (volatile kal_uint32 *)(AM_base + 0x0000)
#define AHBMON_RW (volatile kal_uint32 *)(AM_base + 0x0004)
#define AHBMON_ISEL (volatile kal_uint32 *)(AM_base + 0x0008)
#define AHBMON_SRCSEL (volatile kal_uint32 *)(AM_base + 0x000c)
#define AHBMON_ADDRSEL (volatile kal_uint32 *)(AM_base + 0x0010)
#define AHBMON_ACNT (volatile kal_uint32 *)(AM_base + 0x0014)
#define AHBMON_MAXLAT (volatile kal_uint32 *)(AM_base + 0x0018)
#define AHBMON_CPCNT (volatile kal_uint32 *)(AM_base + 0x001c)
#define AHBMON_DPCNT (volatile kal_uint32 *)(AM_base + 0x0020)
#define AHBMON_ICNT (volatile kal_uint32 *)(AM_base + 0x0024)
#define AHBMON_RCNT (volatile kal_uint32 *)(AM_base + 0x0028)
#define AHBMON_DBECNT (volatile kal_uint32 *)(AM_base + 0x002c)
#define AHBMON_DBYCNT (volatile kal_uint32 *)(AM_base + 0x0030)
#define AHBMON_CLR (volatile kal_uint32 *)(AM_base + 0x0034)
#define AHBMON_SYSRAM4_ERR (volatile kal_uint32 *)(AM_base + 0x0038)
#define AHBMON_SYSRAM5_ERR (volatile kal_uint32 *)(AM_base + 0x003C)


/*******************************************************************************
 * Define constants.
 *******************************************************************************/

enum { 
    AM_ARM7 = 0x01, 
    AM_L2_GMC = 0x02, 
    AM_REZ_EW1 = 0x04, 
    AM_REZ_EW2 = 0x08, 
    AM_L2_VPORT = 0x10, 
    AM_L2_DMA = 0x20, 
    AM_L2_IR = 0x40,
    AM_L2_WAVE = 0x80, 
    AM_L2_IRDBG1 = 0x100, 
    AM_L2_IRDBG2 = 0x200, 
    AM_L2_USB = 0x400, 
    AM_REZ_IRW = 0x800,  
    AM_L4_GMC = 0x1000     
};


/*******************************************************************************
 * Define data structures.
 *******************************************************************************/

typedef struct AM_LOG_STRUCT
{
    kal_uint32 accnt;    /* active cycle count */
    kal_uint32 max_lat;    /* max latency */
    kal_uint32 cmd_cyc;    /* command phase cycle count */
    kal_uint32 data_cyc;    /* data phase cycle count */		
    kal_uint32 idle_cyc;    /* idle cycle count */				
    kal_uint32 req_num;    /* request number count */						
    kal_uint32 data_beat_num;    /* data beat count */								
    kal_uint32 data_byte;    /* data byte count */										
} AM_LOG_T;


/*******************************************************************************
 * Define macros.
 *******************************************************************************/

#if defined(__AHB_MONITOR_SUPPORT__)

#define AM_SET_FILTER(v) \
        do {    \
            *AHBMON_SRCSEL = 0x00000FFF & (v); \
        } while (0)

#define AM_BEGIN_LOG_ALL()  \
        do {    \
            *AHBMON_CLR = 0x00000001;   \
            *AHBMON_CLR = 0x00000000;   \
            *AHBMON_RW = 0x00000001;   \
            *AHBMON_EN = 0x00000001;   \
        } while (0)

#define AM_END_LOG_ALL()    \
        do {    \
            *AHBMON_EN = 0x00000000;   \
        } while (0)

#define AM_GET_LOG(l) \
        do {    \
            (l)->accnt = *AHBMON_ACNT;  \
            (l)->max_lat = *AHBMON_MAXLAT; \
            (l)->cmd_cyc = *AHBMON_CPCNT; \
            (l)->data_cyc = *AHBMON_DPCNT; \
            (l)->idle_cyc = *AHBMON_ICNT; \
            (l)->req_num = *AHBMON_RCNT; \
            (l)->data_beat_num = *AHBMON_DBECNT; \
            (l)->data_byte = *AHBMON_DBYCNT; \
        } while (0)

#define AM_CLEAR_LOG() \
        do {    \
            *AHBMON_CLR = 0x00000001;   \
            *AHBMON_CLR = 0x00000000;   \
        } while (0)

#define AM_START_LOG() \
        do {    \
            *AHBMON_RW = 0x00000001;   \
            *AHBMON_EN = 0x00000001;   \
        } while (0)

#else   /* __AHB_MONITOR_SUPPORT__ */

#define AM_SET_FILTER(v)
#define AM_BEGIN_LOG_ALL()
#define AM_END_LOG_ALL()
#define AM_GET_LOG(l)
#define AM_CLEAR_LOG()
#define AM_START_LOG()

#endif  /* __AHB_MONITOR_SUPPORT__ */

#endif  /* !__AHB_MONITOR_H__ */

