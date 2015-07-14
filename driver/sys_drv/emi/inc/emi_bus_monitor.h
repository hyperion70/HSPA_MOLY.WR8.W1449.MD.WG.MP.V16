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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*
 * Please note that this file will be remove in custom release!!
 * Use it for debugging only.
 *
 * Example to use emi bus monitor:
 *
 * #include "emi_bus_monitor.h"
 *
 * int foo()
 * {
 *     EBM_LOG_T log;
 *     kal_bool ret;
 *
 *     // Clear All Counter
 *     EBM_Clear_Counter();
 *
 *     // Select bus master 
 *     EBM_SEL_MASTER(MCU_DBUS | MCU_IBUS);
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
 *     EBM_GET_LOG(&log);
 *
 *     // Clear counter if necessary
 *     EBM_Clear_Counter();
 *
 *     // print MCU monitor counter
 *     printf("MCU_BUS bus_ccnt = %d, trans_all_cnt = %d, trans_cnt = %d, word_all_cnt = %d, word_cnt = %d, busy_all_cnt = %d, busy_cnt = %d\n", log.bus_ccnt, log.trans_all_cnt, log.trans_cnt, log.word_all_cnt, log.word_cnt, log.busy_all_cnt, log.busy_cnt);
 * }
 */

#if !defined(__EMI_BUS_MONITOR_H__)
#define __EMI_BUS_MONITOR_H__

#include "reg_base.h"

/* RHR Add */
#include "kal_general_types.h"


/*******************************************************************************
 * Define Chip-dependet settings.
 *******************************************************************************/

#if defined(MT6268A) || defined(MT6268) || defined(MT6270A)
#define __EMI_BUS_MONITOR_SUPPORT__
#endif  /* MT6268A || MT6268*/


/*******************************************************************************
 * Define HW register.
 *******************************************************************************/
#if defined(MT6268A)
#define EMI_BMEN (volatile kal_uint32 *)(EMI_base + 0x0140)
#define EMI_BCNT (volatile kal_uint32 *)(EMI_base + 0x0148)
#define EMI_TACT (volatile kal_uint32 *)(EMI_base + 0x0150)
#define EMI_TSCT (volatile kal_uint32 *)(EMI_base + 0x0158)
#define EMI_WACT (volatile kal_uint32 *)(EMI_base + 0x0160)
#define EMI_WSCT (volatile kal_uint32 *)(EMI_base + 0x0168)
#define EMI_BACT (volatile kal_uint32 *)(EMI_base + 0x0170)
#define EMI_BSCT (volatile kal_uint32 *)(EMI_base + 0x0178)
#endif

#if defined(MT6268) || defined(MT6270A)
#define EMI_BMEN  (volatile kal_uint32 *)(EMI_base + 0x0160)
#define EMI_BCNT  (volatile kal_uint32 *)(EMI_base + 0x0168)
#define EMI_TACT  (volatile kal_uint32 *)(EMI_base + 0x0170)
#define EMI_TSCT  (volatile kal_uint32 *)(EMI_base + 0x0178)
#define EMI_WACT  (volatile kal_uint32 *)(EMI_base + 0x0180)
#define EMI_WSCT  (volatile kal_uint32 *)(EMI_base + 0x0188)
#define EMI_BACT  (volatile kal_uint32 *)(EMI_base + 0x0190)
#define EMI_BSCT  (volatile kal_uint32 *)(EMI_base + 0x0198)
#define EMI_MSEL  (volatile kal_uint32 *)(EMI_base + 0x0260)
#define EMI_TSCT2 (volatile kal_uint32 *)(EMI_base + 0x0268)
#define EMI_TSCT3 (volatile kal_uint32 *)(EMI_base + 0x0270)
#define EMI_WSCT2 (volatile kal_uint32 *)(EMI_base + 0x0278)
#define EMI_WSCT3 (volatile kal_uint32 *)(EMI_base + 0x0280)
#endif

/*******************************************************************************
 * Define constants.
 *******************************************************************************/
/*
M0 : None
M1 : MCU D-BUS
M2 : DMA BUS (LYR2)
M3 : None
M4 : MCU I-BUS
M5 : WCDMA BUS
M6 : MD2G BUS (2G Modem)
M7 : GMC1
M8:  GMC2
*/
enum { MCU_DBUS=0x2, DMA_BUS=0x4, MCU_IBUS=0x10, WCDMA_BUS=0x20, MD2G_BUS=0x40, GMC1_BUS=0x80, GMC2_BUS=0x100 };

enum { Read_Write=0x0, Read_Only=0x1, Write_Only=0x2 };
/*******************************************************************************
 * Define data structures.
 *******************************************************************************/

typedef struct EBM_LOG_STRUCT
{
    kal_uint32 bus_ccnt;                  /* total bus cycle count */
    kal_uint32 trans_all_cnt, trans_cnt;  /* all master and some master transaction count */
    kal_uint32 word_all_cnt, word_cnt;    /* all master and some master word(8bytes) count */
    kal_uint32 busy_all_cnt, busy_cnt;    /* all master and some master busy count */
} EBM_LOG_T;


/*******************************************************************************
 * Define macros.
 *******************************************************************************/

#if defined(__EMI_BUS_MONITOR_SUPPORT__)

#define EBM_SEL_MASTER(v) \
        {\
        	*EMI_BMEN = (0x000001f6&v)<<16;\
        }

#define EBM_SET_RW_REQ(v) \
        {\
        	*EMI_BMEN = (*EMI_BMEN&0xffffff00) | (v<<4);\
        }
        
#define EBM_Start() \
        {\
        	*EMI_BMEN |= 1;\
        }

#define EBM_Pause_LOG() \
        {\
        	*EMI_BMEN |= 2;\
        }

#define EBM_Check_Overrun() ((*EMI_BMEN&0x100)==0?KAL_FALSE:KAL_TRUE)

#define EBM_GET_LOG(l) \
        {\
        	(l)->bus_ccnt = *EMI_BCNT; \
        	(l)->trans_all_cnt = *EMI_TACT; \
        	(l)->trans_cnt = *EMI_TSCT; \
        	(l)->word_all_cnt = *EMI_WACT; \
        	(l)->word_cnt = *EMI_WSCT; \
        	(l)->busy_all_cnt = *EMI_BACT; \
        	(l)->busy_cnt = *EMI_BSCT; \
        }

#define EBM_Clear_Counter() \
        {\
        	*EMI_BMEN &= 0xfffffffc;\
        }

#define EBM_Restart_Counter() \
        {\
        	*EMI_BMEN &= 0xfffffffd;\
        }

#if defined(MT6268) || defined(MT6270A)

#define EBM_SEL_MASTER2(v) \
        {\
        	*EMI_MSEL = (*EMI_MSEL&0x01f60000)|(0x000001f6&v);\
        }
#define EBM_SEL_MASTER3(v) \
        {\
        	*EMI_MSEL = (*EMI_MSEL&0x000001f6)|((0x000001f6&v)<<16);\
        }

/*Sel2 doesn't support master busy count in the MT6268*/
#define EBM_GET_LOG2(l) \
        {\
        	(l)->bus_ccnt = *EMI_BCNT; \
        	(l)->trans_all_cnt = *EMI_TACT; \
        	(l)->trans_cnt = *EMI_TSCT2; \
        	(l)->word_all_cnt = *EMI_WACT; \
        	(l)->word_cnt = *EMI_WSCT2; \
        	(l)->busy_all_cnt = *EMI_BACT; \
        	(l)->busy_cnt = 0; \
        }
/*Sel3 doesn't support master busy count in the MT6268*/
#define EBM_GET_LOG3(l) \
        {\
        	(l)->bus_ccnt = *EMI_BCNT; \
        	(l)->trans_all_cnt = *EMI_TACT; \
        	(l)->trans_cnt = *EMI_TSCT3; \
        	(l)->word_all_cnt = *EMI_WACT; \
        	(l)->word_cnt = *EMI_WSCT3; \
        	(l)->busy_all_cnt = *EMI_BACT; \
        	(l)->busy_cnt = 0; \
        }

#endif

#else   /* __EMI_BUS_MONITOR_SUPPORT__ */

#define EBM_SEL_MASTER(v) 
#define EBM_SET_RW_REQ(v)
#define EBM_Start()
#define EBM_Pause_LOG()
#define EBM_Check_Overrun()
#define EBM_GET_LOG(l)
#define EBM_Clear_Counter()
#define EBM_Restart_Counter()
#define EBM_SEL_MASTER2(v)
#define EBM_SEL_MASTER3(v)
#define EBM_GET_LOG2(l)
#define EBM_GET_LOG3(l)

#endif  /* __EMI_BUS_MONITOR_SUPPORT__ */


/*******************************************************************************
 * Implement abstration interface.
 *******************************************************************************/

#define EBM_INIT()  \
        do {    \
            EBM_Clear_Counter();    \
            EBM_SEL_MASTER(MCU_DBUS | MCU_IBUS);    \
            EBM_SET_RW_REQ(Read_Write); \
        } while (0)

#define EBM_START() \
        do {    \
            EBM_Start();    \
        } while (0)

#define EBM_PAUSE() \
        do {    \
            EBM_Pause_LOG();    \
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
            EBM_Clear_Counter();    \
        } while (0)

#endif  /* !__EMI_BUS_MONITOR_H__ */

