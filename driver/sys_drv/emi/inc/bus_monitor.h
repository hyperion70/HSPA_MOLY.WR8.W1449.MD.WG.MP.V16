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
 * #include "bus_monitor.h"
 *
 * int foo()
 * {
 *     BM_LOG_T log;
 *
 *     // set layer2 filters
 *     BM_SET_L2_FILTER(0xFF);
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
 *     printf("layer3 accnt = %d, tcnt = %d, wcnt = %d\n", log.l3_accnt, log.l3_tcnt, log.l3_wcnt);
 * }
 */

#if !defined(__BUS_MONITOR_H__)
#define __BUS_MONITOR_H__


/* RHR Add */
#include "kal_general_types.h"


/*******************************************************************************
 * Define Chip-dependet settings.
 *******************************************************************************/

#if defined(MT6238) || defined(MT6239) || defined(MT6235) || defined(MT6235B)
#define __BUS_MONITOR_SUPPORT__
#define BM_base 0x810e0000
#endif  /* MT6238 || MT6239 || MT6235 || MT6235B */


/*******************************************************************************
 * Define HW register.
 *******************************************************************************/

#define BM_CON (volatile kal_uint32 *)(BM_base + 0x0000)
#define BM_LYR2_HMASTER (volatile kal_uint32 *)(BM_base + 0x0004)
#define BM_CYCLE_CNT (volatile kal_uint32 *)(BM_base + 0x0008)
#define BM_LYR1_ACCNT (volatile kal_uint32 *)(BM_base + 0x0010)
#define BM_LYR1_TCNT (volatile kal_uint32 *)(BM_base + 0x0014)
#define BM_LYR1_WCNT (volatile kal_uint32 *)(BM_base + 0x0018)
#define BM_LYR2_ACCNT (volatile kal_uint32 *)(BM_base + 0x030)
#define BM_LYR2_TCNT (volatile kal_uint32 *)(BM_base + 0x0034)
#define BM_LYR2_WCNT (volatile kal_uint32 *)(BM_base + 0x0038)
#define BM_LYR3_ACCNT (volatile kal_uint32 *)(BM_base + 0x070)
#define BM_LYR3_TCNT (volatile kal_uint32 *)(BM_base + 0x0074)
#define BM_LYR3_WCNT (volatile kal_uint32 *)(BM_base + 0x0078)
#define BM_LYR4_ACCNT (volatile kal_uint32 *)(BM_base + 0x090)
#define BM_LYR4_TCNT (volatile kal_uint32 *)(BM_base + 0x0094)
#define BM_LYR4_WCNT (volatile kal_uint32 *)(BM_base + 0x0098)


/*******************************************************************************
 * Define constants.
 *******************************************************************************/

enum { BM_L2_VFIFO = 0x01, BM_L2_DMA = 0x02, BM_L2_WAVETBL = 0x04, 
       BM_L2_USB = 0x08, BM_L2_IRDBG1 = 0x10, BM_L2_IRDBG2 = 0x20,
       BM_L2_IRDA = 0x40, BM_L2_PWM = 0x80 };


/*******************************************************************************
 * Define data structures.
 *******************************************************************************/

typedef struct BM_LOG_STRUCT
{
    kal_uint32 ccnt;    /* total cycle count */
    kal_uint32 l1_accnt, l1_tcnt, l1_wcnt;  /* layer1 AHB counter */
    kal_uint32 l2_accnt, l2_tcnt, l2_wcnt;  /* layer2 AHB counter */
    kal_uint32 l3_accnt, l3_tcnt, l3_wcnt;  /* layer3 AHB counter */
    kal_uint32 l4_accnt, l4_tcnt, l4_wcnt;  /* layer4 AHB counter */
} BM_LOG_T;


/*******************************************************************************
 * Define macros.
 *******************************************************************************/

#if defined(__BUS_MONITOR_SUPPORT__)

#define BM_SET_L2_FILTER(v) \
        do {    \
            *BM_LYR2_HMASTER = 0x000000FF & (v); \
        } while (0)

#define BM_BEGIN_LOG_ALL()  \
        do {    \
            *BM_CON = 0x00000002;   \
            *BM_CON = 0x00000001;   \
        } while (0)

#define BM_END_LOG_ALL()    \
        do {    \
            *BM_CON = 0x00000000;   \
        } while (0)

#define BM_GET_LOG(l) \
        do {    \
            (l)->ccnt = *BM_CYCLE_CNT;  \
            (l)->l1_accnt = *BM_LYR1_ACCNT; \
            (l)->l1_tcnt = *BM_LYR1_TCNT; \
            (l)->l1_wcnt = *BM_LYR1_WCNT; \
            (l)->l2_accnt = *BM_LYR2_ACCNT; \
            (l)->l2_tcnt = *BM_LYR2_TCNT; \
            (l)->l2_wcnt = *BM_LYR2_WCNT; \
            (l)->l3_accnt = *BM_LYR3_ACCNT; \
            (l)->l3_tcnt = *BM_LYR3_TCNT; \
            (l)->l3_wcnt = *BM_LYR3_WCNT; \
            (l)->l4_accnt = *BM_LYR4_ACCNT; \
            (l)->l4_tcnt = *BM_LYR4_TCNT; \
            (l)->l4_wcnt = *BM_LYR4_WCNT; \
        } while (0)

#else   /* __BUS_MONITOR_SUPPORT__ */

#define BM_SET_L2_FILTER(v)
#define BM_BEGIN_LOG_ALL()
#define BM_END_LOG_ALL()
#define BM_GET_LOG(l)

#endif  /* __BUS_MONITOR_SUPPORT__ */

#endif  /* !__BUS_MONITOR_H__ */

