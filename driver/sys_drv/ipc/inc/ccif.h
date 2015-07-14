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
 *   ccif.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   Header file of CCIF.
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __CCIF_H__
#define __CCIF_H__

#if defined(__MODEM_CCCI_EXIST__)

#include "reg_base.h"

//- Special design for MT6280
#if defined(__REG_base_MT6280_H__)
#define MDCCIF_CTL_OFFSET		0x0100
#define MDCCIF_RSD_OFFSET		0x01E0
#define MDCCIF_TSD_OFFSET		0x0270

#elif defined(__REG_base_MT6580_H__) 
#define MDCCIF_CTL_OFFSET		0x0120
#define MDCCIF_RSD_OFFSET		0x0200
#define MDCCIF_TSD_OFFSET		0x0280

#elif defined(__REG_base_MT6572_H__) || defined(__REG_base_MT6571_H__)
#define MDCCIF_CTL_OFFSET		0x0120
#define MDCCIF_RSD_OFFSET		0x0200
#define MDCCIF_TSD_OFFSET		0x0280

//- Before new chip final data-in
//- It's better to make sure offset in ccif reg map as following
#else
#define MDCCIF_CTL_OFFSET		0x0000
#define MDCCIF_RSD_OFFSET		0x0100
#define MDCCIF_TSD_OFFSET		0x0180
#endif


/* define HW register */
#ifndef MDCCIF_base
#define MDCCIF_base 	0x81160000//CCIF_base
#endif /* MDCCIF_BASE */
#define MDCCIF_CON 		((volatile unsigned int *)(MDCCIF_base + MDCCIF_CTL_OFFSET + 0x0000))
#define MDCCIF_BUSY 	((volatile unsigned int *)(MDCCIF_base + MDCCIF_CTL_OFFSET + 0x0004))
#define MDCCIF_START 	((volatile unsigned int *)(MDCCIF_base + MDCCIF_CTL_OFFSET + 0x0008))
#define MDCCIF_TCHNUM 	((volatile unsigned int *)(MDCCIF_base + MDCCIF_CTL_OFFSET + 0x000C))
#define MDCCIF_RCHNUM 	((volatile unsigned int *)(MDCCIF_base + MDCCIF_CTL_OFFSET + 0x0010))

//- [Workaround] In MT6572, MD/AP ACK are inversed
#if defined(MT6572)
#define MDCCIF_ACK 		((volatile unsigned int *)(MDCCIF_base + MDCCIF_CTL_OFFSET - 0x20 + 0x0014))
#else
#define MDCCIF_ACK 		((volatile unsigned int *)(MDCCIF_base + MDCCIF_CTL_OFFSET + 0x0014))
#endif

/* for CHDATA, the first half space belongs to AP and the remaining space belongs to MD */
#define MDCCIF_TXCHDATA ((volatile unsigned int *)(MDCCIF_base + MDCCIF_TSD_OFFSET))
#define MDCCIF_RXCHDATA ((volatile unsigned int *)(MDCCIF_base + MDCCIF_RSD_OFFSET))
#define MDCCIF_INITDATA ((volatile unsigned int *)(MDCCIF_base + MDCCIF_RSD_OFFSET + 64))

/* define alias */
#define CCIF_CON 		MDCCIF_CON
#define CCIF_BUSY 		MDCCIF_BUSY
#define CCIF_START 		MDCCIF_START
#define CCIF_TCHNUM 	MDCCIF_TCHNUM
#define CCIF_RCHNUM 	MDCCIF_RCHNUM
#define CCIF_ACK 		MDCCIF_ACK
#define CCIF_TXCHDATA 	MDCCIF_TXCHDATA
#define CCIF_RXCHDATA 	MDCCIF_RXCHDATA


/* define constant */
#define CCIF_CON_SEQ 	0x00 /* sequencial */
#define CCIF_CON_ARB 	0x01 /* arbitrate */
#define CCIF_MAX_PHY 	8
#define CCIF_ALL_PHY_MASK    ((1 << CCIF_MAX_PHY) - 1)

#define MDCCIF_BOOTTRC_DATA    (MDCCIF_base + MDCCIF_TSD_OFFSET + 128 - 8)    /* Use last 8 bytes of TX buffer for bootup trace */

#endif /* #if __MODEM_CCCI_EXIST__ */

#endif  /* !__CCIF_H__ */

