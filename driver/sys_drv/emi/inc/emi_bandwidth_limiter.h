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
 *   emi_bandwidth_limiter.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Header file for the control of  emi bandwidth limiter.
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#if !defined(__EMI_BANDWIDTH_LIMITER_H__)
#define __EMI_BANDWIDTH_LIMITER_H__

#include "reg_base.h"

#if defined(MT6268) || defined(MT6270A)
#define __EMI_BANDWIDTH_LIMITER_SUPPORT__
#endif

/*******************************************************************************
 * Define HW register.
 *******************************************************************************/
#define EMI_ARB(master)   (volatile kal_uint32 *)(EMI_base + 0x0200 + 8*master)


/*******************************************************************************
 * Define constants.
 *******************************************************************************/
enum{
    BW_FILTER_LEN_256 = 0,
    BW_FILTER_LEN_512 = 1,
    BW_FILTER_LEN_1024 = 2,
    BW_FILTER_LEN_2048 = 3
};

enum { 
       BW_MCU_DBUS=0x1, 
	      BW_DMA_BUS=0x2, 
	      BW_MCU_IBUS=0x4, 
	      BW_WCDMA_BUS=0x5, 
	      BW_MD2G_BUS=0x6, 
	      BW_GMC1_BUS=0x7, 
	      BW_GMC2_BUS=0x8
};

/*******************************************************************************
 * Define macros.
 *******************************************************************************/
#if defined(__EMI_BANDWIDTH_LIMITER_SUPPORT__) 

#define BW_SET_FILTER_LEN( filter_len ) *EMI_ARB(0) = ( *EMI_ARB(0) & 0xFFFFF3FF )|(filter_len<<10)
#define BW_SET_MAX_GNT( master,grant ) *EMI_ARB(master) = (*EMI_ARB(master) & 0xFFFFFF00)|grant
#define BW_ENABLE_LIMITER( master ) *EMI_ARB(master) |= (1<<12)
#define BW_DISABLE_LIMITER( master ) *EMI_ARB(master) &= ~(1<<12)
#define BW_ENABLE_SOFT_MODE( master ) *EMI_ARB(master) |= (1<<14)
#define BW_DISABLE_SOFT_MODE( master ) *EMI_ARB(master) &= ~(1<<14)

#endif  /* __EMI_BANDWIDTH_LIMITER_SUPPORT__ */

#endif  //__EMI_BANDWIDTH_LIMITER_H__
