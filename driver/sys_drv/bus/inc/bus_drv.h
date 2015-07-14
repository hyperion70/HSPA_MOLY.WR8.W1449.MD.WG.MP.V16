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
 *   bus_drv.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file is intended for BUS driver.
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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

#ifndef __BUS_DRV_H__
#define __BUS_DRV_H__

#include "kal_general_types.h"
#include "bus_hw.h"

/*
#define enableVirtualMapping Bus_Virtual_Mapping_Enable
#define disableVirtualMapping Bus_Virtual_Mapping_Disable  
#define enableMcuOutstanding Bus_Enable_MCU_Outstanding  
#define enablePrefetchBuffer Bus_PFB_Enable  
#define disablePrefetchBuffer Bus_PFB_Disable  
*/

// Control Bus Remapping
extern void Bus_Virtual_Mapping_Enable(void);
extern void Bus_Virtual_Mapping_Disable(void);
// Control Prefetch Buffer
extern void Bus_PFB_Enable(void);
extern void Bus_PFB_Disable(void);
// Other Bus Control
extern void Bus_Init(void);
extern void Bus_Enable_MCU_Outstanding(void);


/*******************************************************************************
 * Feature Option
 *******************************************************************************/
// Turned-On MD EMI latency profiling of TL1/2GL1 SW
// Note: It uses MD ELM and conflicts with SWLA ELM add-on
#if defined(__MTK_INTERNAL__) 
/* under construction !*/
    #if defined(MT6589) && defined(__MD2__) && defined(__UMTS_TDD128_MODE__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* MT6589 MD2  && __UMTS_TDD128_MODE__*/
/* under construction !*/
    #if (defined(MT6572) || defined(MT6582) || defined(MT6592) || defined(MT6571) || defined(MT6580)) && !defined(__SWLA_EBM_ADDON_SUPPORT__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif
/* under construction !*/
#endif /* __MTK_INTERNAL__ */

/*******************************************************************************
 * Macro
 *******************************************************************************/

/**************************************/
// Control EMI High priority
#if defined(MT6589)
    #if defined(__MD1__)
        #define BUS_MCU2EMI_ULTRA_SET() \
            do {\
        	    *MD2EMI_ULTRA_HIGH_SET0 = 0x00000001;\
            } while (0)
        #define BUS_MCU2EMI_ULTRA_CLR() \
            do {\
        	    *MD2EMI_ULTRA_HIGH_CLR0 = 0x00000001;\
            } while (0)
    #elif defined(__MD2__)
        #define BUS_MCU2EMI_ULTRA_SET() \
            do {\
        	    *MD2EMI_ULTRA_HIGH_SET0 = 0x00000003;\
            } while (0)
        #define BUS_MCU2EMI_ULTRA_CLR() \
            do {\
        	    *MD2EMI_ULTRA_HIGH_CLR0 = 0x00000003;\
            } while (0)
    #endif
#elif defined(MT6572) || defined(MT6571) || defined(MT6580)
    // do nothing
    #define BUS_MCU2EMI_ULTRA_SET()
    #define BUS_MCU2EMI_ULTRA_CLR()
#elif defined(MT6582) || defined(MT6592)
    #define BUS_MCU2EMI_ULTRA_SET() \
        do {\
            *MD2EMI_ULTRA_HIGH_SET0 = 0x00000003;\
        } while (0)
    #define BUS_MCU2EMI_ULTRA_CLR() \
        do {\
            *MD2EMI_ULTRA_HIGH_CLR0 = 0x00000003;\
        } while (0)     
#else
    // do nothing
    #define BUS_MCU2EMI_ULTRA_SET()
    #define BUS_MCU2EMI_ULTRA_CLR()
#endif
/**************************************/


/**************************************/
//#define __DYNAMIC_DRAMC_ULTRA__

// Dynamic DRAMC ULTRA
#if defined(MT6589) && defined(__MD2__) && defined(__DYNAMIC_DRAMC_ULTRA__)
    #define BUS_DYNAMIC_DRAMC_ULTRA_SET() \
        do {\
            extern kal_uint32 BUS_TESTB_DRAMC_ULtra_On;\
            *EMI_TESTB = BUS_TESTB_DRAMC_ULtra_On;\
        } while (0)

    #define BUS_DYNAMIC_DRAMC_ULTRA_CLR() \
        do {\
            extern kal_uint32 BUS_TESTB_DRAMC_ULtra_Off;\
            *EMI_TESTB = BUS_TESTB_DRAMC_ULtra_Off;\
        } while (0)
#else
    // do nothing
    #define BUS_DYNAMIC_DRAMC_ULTRA_SET()
    #define BUS_DYNAMIC_DRAMC_ULTRA_CLR()
#endif
/**************************************/

/**************************************/
// Monitor MD ELM Latency during CTIRQ1
typedef struct _CTIRQ_ELM_PROFILE_T
{
    kal_int32 duration;
    kal_uint32 w_trans;
    kal_uint32 r_trans;
    kal_uint32 avg_rlat;
    kal_uint32 avg_wlat;
} CTIRQ_ELM_PROFILE_T;

#if (defined(MT6572) || defined(MT6582) || defined(MT6592)) && defined(__GL1_SW_PROFILE_ELM__)
    #define BUS_CTIRQ_PROFILE_ELM_START() \
        do {\
            extern kal_uint32 elm_history_idx; \
            extern CTIRQ_ELM_PROFILE_T elm_history[64]; \
            elm_history_idx = (elm_history_idx + 1) % 64 ; \
            elm_history[elm_history_idx].duration = 0;\
            *MD_MCU_ELM_CON = 0x00000000;\
            *MD_MCU_ELM_CON = 0x00000001;\
        } while (0)
    #define BUS_CTIRQ_PROFILE_ELM_LOG(m, n) \
        do {\
            extern kal_uint32 elm_history_idx; \
            extern CTIRQ_ELM_PROFILE_T elm_history[64]; \
            extern CTIRQ_ELM_PROFILE_T elm_history_w_worst; \
            extern CTIRQ_ELM_PROFILE_T elm_history_r_worst; \
            extern kal_uint32 ctirq_w_latency; \
            extern kal_uint32 ctirq_r_latency; \
            elm_history[elm_history_idx].duration = (kal_int32)(n - m); \
            if (elm_history[elm_history_idx].duration > 60) { \
                *MD_MCU_ELM_CON = 0x00000003; \
        	    elm_history[elm_history_idx].w_trans = *MD_MCU_ELM_STATUS; \
                *MD_MCU_ELM_CON = 0x0000000B; \
        	    ctirq_w_latency = *MD_MCU_ELM_STATUS; \
                *MD_MCU_ELM_CON = 0x00000013; \
        	    elm_history[elm_history_idx].r_trans = *MD_MCU_ELM_STATUS; \
                *MD_MCU_ELM_CON = 0x0000001B; \
        	    ctirq_r_latency = *MD_MCU_ELM_STATUS; \
        	    if (elm_history[elm_history_idx].w_trans > 0) elm_history[elm_history_idx].avg_wlat = ctirq_w_latency / elm_history[elm_history_idx].w_trans; \
        	    else elm_history[elm_history_idx].avg_wlat = 0; \
        	    if (elm_history[elm_history_idx].r_trans > 0 ) elm_history[elm_history_idx].avg_rlat = ctirq_r_latency / elm_history[elm_history_idx].r_trans; \
        	    else elm_history[elm_history_idx].avg_rlat = 0; \
        	    if (elm_history[elm_history_idx].avg_wlat > elm_history_w_worst.avg_wlat) { \
        	        elm_history_w_worst.duration = elm_history[elm_history_idx].duration; \
        	        elm_history_w_worst.w_trans = elm_history[elm_history_idx].w_trans; \
        	        elm_history_w_worst.r_trans = elm_history[elm_history_idx].r_trans; \
        	        elm_history_w_worst.avg_wlat = elm_history[elm_history_idx].avg_wlat; \
        	        elm_history_w_worst.avg_rlat = elm_history[elm_history_idx].avg_rlat; \
        	    } \
        	    if (elm_history[elm_history_idx].avg_rlat > elm_history_r_worst.avg_rlat) { \
        	        elm_history_r_worst.duration = elm_history[elm_history_idx].duration; \
        	        elm_history_r_worst.w_trans = elm_history[elm_history_idx].w_trans; \
        	        elm_history_r_worst.r_trans = elm_history[elm_history_idx].r_trans; \
        	        elm_history_r_worst.avg_wlat = elm_history[elm_history_idx].avg_wlat; \
        	        elm_history_r_worst.avg_rlat = elm_history[elm_history_idx].avg_rlat; \
        	    } \
        	} else { \
      	        elm_history[elm_history_idx].w_trans = 0; \
       	        elm_history[elm_history_idx].r_trans = 0; \
       	        elm_history[elm_history_idx].avg_wlat = 0; \
       	        elm_history[elm_history_idx].avg_rlat = 0; \
            } \
        } while (0)
#elif (defined(MT6571) || defined(MT6580)) && defined(__GL1_SW_PROFILE_ELM__)
    #define BUS_CTIRQ_PROFILE_ELM_START() \
        do {\
            extern kal_uint32 elm_history_idx; \
            extern CTIRQ_ELM_PROFILE_T elm_history[64]; \
            elm_history_idx = (elm_history_idx + 1) % 64 ; \
            elm_history[elm_history_idx].duration = 0;\
            *MD_MCU_ELM_CON = 0x00000000;\
            *MD_MCU_ELM_CON = 0x00000001;\
        } while (0)
    #define BUS_CTIRQ_PROFILE_ELM_LOG(m, n) \
        do {\
            extern kal_uint32 elm_history_idx; \
            extern CTIRQ_ELM_PROFILE_T elm_history[64]; \
            extern CTIRQ_ELM_PROFILE_T elm_history_w_worst; \
            extern CTIRQ_ELM_PROFILE_T elm_history_r_worst; \
            extern kal_uint32 ctirq_w_latency; \
            extern kal_uint32 ctirq_r_latency; \
            elm_history[elm_history_idx].duration = (kal_int32)(n - m); \
            if (elm_history[elm_history_idx].duration > 60) { \
        	    elm_history[elm_history_idx].w_trans = *MD_MCU_ELM_STATUS0; \
        	    ctirq_w_latency = *MD_MCU_ELM_STATUS1; \
        	    elm_history[elm_history_idx].r_trans = *MD_MCU_ELM_STATUS2; \
        	    ctirq_r_latency = *MD_MCU_ELM_STATUS3; \
        	    if (elm_history[elm_history_idx].w_trans > 0) elm_history[elm_history_idx].avg_wlat = ctirq_w_latency / elm_history[elm_history_idx].w_trans; \
        	    else elm_history[elm_history_idx].avg_wlat = 0; \
        	    if (elm_history[elm_history_idx].r_trans > 0 ) elm_history[elm_history_idx].avg_rlat = ctirq_r_latency / elm_history[elm_history_idx].r_trans; \
        	    else elm_history[elm_history_idx].avg_rlat = 0; \
        	    if (elm_history[elm_history_idx].avg_wlat > elm_history_w_worst.avg_wlat) { \
        	        elm_history_w_worst.duration = elm_history[elm_history_idx].duration; \
        	        elm_history_w_worst.w_trans = elm_history[elm_history_idx].w_trans; \
        	        elm_history_w_worst.r_trans = elm_history[elm_history_idx].r_trans; \
        	        elm_history_w_worst.avg_wlat = elm_history[elm_history_idx].avg_wlat; \
        	        elm_history_w_worst.avg_rlat = elm_history[elm_history_idx].avg_rlat; \
        	    } \
        	    if (elm_history[elm_history_idx].avg_rlat > elm_history_r_worst.avg_rlat) { \
        	        elm_history_r_worst.duration = elm_history[elm_history_idx].duration; \
        	        elm_history_r_worst.w_trans = elm_history[elm_history_idx].w_trans; \
        	        elm_history_r_worst.r_trans = elm_history[elm_history_idx].r_trans; \
        	        elm_history_r_worst.avg_wlat = elm_history[elm_history_idx].avg_wlat; \
        	        elm_history_r_worst.avg_rlat = elm_history[elm_history_idx].avg_rlat; \
        	    } \
        	} else { \
      	        elm_history[elm_history_idx].w_trans = 0; \
       	        elm_history[elm_history_idx].r_trans = 0; \
       	        elm_history[elm_history_idx].avg_wlat = 0; \
       	        elm_history[elm_history_idx].avg_rlat = 0; \
            } \
        } while (0)
#else
    #define BUS_CTIRQ_PROFILE_ELM_START()
    #define BUS_CTIRQ_PROFILE_ELM_LOG(m, n)
#endif

/**************************************/

#endif  /* !__BUS_DRV_H__ */

