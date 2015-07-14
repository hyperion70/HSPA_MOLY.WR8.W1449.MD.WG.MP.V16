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
 * #include "ebm_if.h"
 *
 * int foo()
 * {
 *     EBM_LOG_T log;
 *
 *     // the default configuration is used to profile EMI bandwidth
 *     // you can configure emi monitor in your way by EM_SET_FILTER
 *     EBM_INIT();
 *
 *     // begin of bus-monitor logging
 *     EBM_START();
 *
 *     // SW to be measured
 *
 *     // end of bus-monitor logging
 *     EBM_PAUSE();
 *
 *     // retrieve log
 *     EBM_GET_MCU_IBUS_LOG(&log);
 *
 *     // print layer3 counter
 *     printf("ccnt = %d\n", log.ccnt);
 * }
 */

#if !defined(__EMI_MONITOR_H__)
#define __EMI_MONITOR_H__

/* RHR Add */
#include "kal_general_types.h"

/*******************************************************************************
 * Define Chip-dependet settings.
 *******************************************************************************/

#if defined(MT6253T) || defined(MT6253)
#define __EMI_MONITOR_SUPPORT__
#define EM_base 0x81000000
#endif  /* MT6253T || MT6253 */


/*******************************************************************************
 * Define HW register.
 *******************************************************************************/

#define EMI_MONCTL (volatile kal_uint16 *)(EM_base + 0x0020)
#define EMI_CYCCNT (volatile kal_uint32 *)(EM_base + 0x0024)
#define EMI_DBYTECNT (volatile kal_uint32 *)(EM_base + 0x0028)
#define EMI_RQCNT (volatile kal_uint32 *)(EM_base + 0x002c)
#define EMI_RQBCNT (volatile kal_uint32 *)(EM_base + 0x0030)
#define EMI_RQHWCNT (volatile kal_uint32 *)(EM_base + 0x0034)
#define EMI_RQWCNT (volatile kal_uint32 *)(EM_base + 0x0038)


/*******************************************************************************
 * Define constants.
 *******************************************************************************/

enum { 
    EM_MON_EN = 0x0001,

    EM_MON_CLR = 0x0002,

    EM_RD_REQ = 0x0000,
    EM_WR_REQ = 0x0004,
    EM_RW_REQ = 0x0008,
    
	 EM_NONULTRAHIGH_REQ = 0x0000,	 	 
	 EM_ULTRAHIGH_REQ = 0x0010,
	 EM_ULTRAHIGH_NONULTRAHIGH_REQ = 0x0020,	 	 

    EM_ALN_REQ = 0x0000,
    EM_NONALN_REQ = 0x0040,
    EM_ALN_NONALN_REQ = 0x0080,

	 EM_MCU_DATA_REQ = 0x0000, 	 
    EM_MCU_INST_REQ = 0x0100, 
	 EM_MCU_INST_DATA_REQ = 0x0200, 	 	 

 	 EM_SINGLE_REQ = 0x0000,
 	 EM_WRAP4_REQ = 0x0800,
 	 EM_INC4_REQ = 0x0c00,
 	 EM_INC8_REQ = 0x1400,
 	 EM_INC16_REQ = 0x1c00,
 	 EM_ALL_BURST_TYPE_REQ = 0x2000,		

    EM_MCU_PORT = 0x4000, 
	 EM_DMA_PORT = 0x8000
};


/*******************************************************************************
 * Define data structures.
 *******************************************************************************/

typedef struct EBM_LOG_STRUCT
{
    /* Cache (cache linefill) */
    kal_uint64 cache_hcnt0;
    kal_uint64 cache_ccnt0;
    kal_uint64 cache_hcnt1;
    kal_uint64 cache_ccnt1;

    /* AHB (DMA burst transaction) */	
    kal_uint32 ahb_databeat;

    /* EMI */
    kal_uint32 ccnt;    /* cycle count */
    kal_uint32 data_byte;    /* data byte count */										
    kal_uint32 req_cnt;    /* request number count */						
    kal_uint32 qual_byte_cnt;    /* qualified byte request number count */						
    kal_uint32 qual_2byte_cnt;    /* qualified 2-byte request number count */						
    kal_uint32 qual_4byte_cnt;    /* qualified 4-byte request number count */						
} EBM_LOG_T;


/*******************************************************************************
 * Define macros.
 *******************************************************************************/

#if defined(__EMI_MONITOR_SUPPORT__)

#define EM_SET_FILTER(v) \
        do {    \
            *EMI_MONCTL = (v); \
        } while (0)

#define EM_BEGIN_LOG_ALL()  \
        do {    \
            *EMI_MONCTL |= (EM_RW_REQ | EM_ULTRAHIGH_NONULTRAHIGH_REQ | EM_ALN_NONALN_REQ | EM_MCU_INST_DATA_REQ | EM_SINGLE_REQ);   \
            *EMI_MONCTL |= EM_MON_CLR;   \
            *EMI_MONCTL &= ~EM_MON_CLR;   \
            *EMI_MONCTL |= EM_MON_EN;   \
        } while (0)

#define EM_END_LOG_ALL()    \
        do {    \
            *EMI_MONCTL &= ~EM_MON_EN;   \
        } while (0)

#define EM_GET_LOG(l) \
        do {    \
            (l)->ccnt = *EMI_CYCCNT;  \
            (l)->data_byte = *EMI_DBYTECNT; \
            (l)->req_cnt = *EMI_RQCNT; \
            (l)->qual_byte_cnt = *EMI_RQBCNT; \
            (l)->qual_2byte_cnt = *EMI_RQHWCNT; \
            (l)->qual_4byte_cnt = *EMI_RQWCNT; \
        } while (0)

#define EM_CLEAR_LOG() \
        do {    \
            *EMI_MONCTL |= EM_MON_CLR;   \
            *EMI_MONCTL &= ~EM_MON_CLR;   \
        } while (0)

#define EM_START_LOG() \
        do {    \
            *EMI_MONCTL |= EM_MON_EN;   \
        } while (0)


#define EBM_GET_LOG(l) \
        do {    \
            (l)->cache_hcnt0 = (*CACHE_MON_HCNT0U << 32) | (*CACHE_MON_HCNT0L); \
            (l)->cache_ccnt0 = (*CACHE_MON_CCNT0U << 32) | (*CACHE_MON_CCNT0L); \
            (l)->cache_hcnt1 = (*CACHE_MON_HCNT1U << 32) | (*CACHE_MON_HCNT1L); \
            (l)->cache_ccnt1 = (*CACHE_MON_CCNT1U << 32) | (*CACHE_MON_CCNT1L); \
            (l)->ahb_databeat = *AHBMON_DBECNT; \
            (l)->ccnt = *EMI_CYCCNT;  \
            (l)->data_byte = *EMI_DBYTECNT; \
            (l)->req_cnt = *EMI_RQCNT; \
            (l)->qual_byte_cnt = *EMI_RQBCNT; \
            (l)->qual_2byte_cnt = *EMI_RQHWCNT; \
            (l)->qual_4byte_cnt = *EMI_RQWCNT; \
        } while (0)

#else   /* __EMI_MONITOR_SUPPORT__ */

#define EM_SET_FILTER(v)
#define EM_BEGIN_LOG_ALL()
#define EM_END_LOG_ALL()
#define EM_GET_LOG(l)
#define EM_CLEAR_LOG()
#define EM_START_LOG()

#define EBM_GET_LOG(l)

#endif  /* __EMI_MONITOR_SUPPORT__ */


/*******************************************************************************
 * Implement abstration interface.
 *******************************************************************************/

#define EBM_INIT() \
        do {    \
            CM_CLEAR_LOG();    \
            AM_CLEAR_LOG();    \
            EM_CLEAR_LOG();    \
            AM_SET_FILTER(AM_L2_GMC|AM_REZ_EW1|AM_REZ_EW2|AM_L2_VPORT|AM_L2_DMA|AM_L2_IR|AM_L2_WAVE|AM_L2_IRDBG1|AM_L2_IRDBG2|AM_L2_USB); \
            EM_SET_FILTER(EM_RW_REQ|EM_ULTRAHIGH_NONULTRAHIGH_REQ|EM_ALN_NONALN_REQ|EM_MCU_DATA_REQ|EM_SINGLE_REQ|EM_MCU_PORT); \
        } while (0)

#define EBM_START() \
        do {    \
            CM_START_LOG();    \
            AM_START_LOG();    \
            EM_START_LOG();    \
        } while (0)

#define EBM_PAUSE() \
        do {    \
            CM_END_LOG();    \
            AM_END_LOG_ALL();    \
            EM_END_LOG_ALL();    \
        } while (0)

#define EBM_GET_MCU_IBUS_LOG(l) \
        do {    \
            EBM_GET_LOG((l));    \
        } while (0)

#define EBM_GET_MCU_DBUS_LOG(l) \
        do {    \
            EBM_GET_LOG((l));    \
        } while (0)

#define EBM_RESUME()

#define EBM_STOP()  \
        do {    \
            CM_CLEAR_LOG();    \
            AM_CLEAR_LOG();    \
            EM_CLEAR_LOG();    \
        } while (0)

#endif  /* !__BUS_MONITOR_H__ */

