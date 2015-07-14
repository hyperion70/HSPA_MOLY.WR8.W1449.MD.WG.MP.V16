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
 *   ccci_misc_info_conf.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   user enum for ccci misc info query service
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
 *
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#if defined(__MODEM_CCCI_EXIST__) && !defined(__SDIO_DEVICE_CONNECTIVITY__) && defined(CCCI_INIT_HANDSHAKE_MODE1)

X_CCCI_MISCINFO_CONF(CCMSG_ID_MISCINFO_HIF_DMA_REMAP)   //- add for DMA to query HIF-DMA remap address
X_CCCI_MISCINFO_CONF(CCMSG_ID_MISCINFO_RTC_32K_LESS)	//- add for L1 to query 32K-less information in AP
X_CCCI_MISCINFO_CONF(CCMSG_ID_MISCINFO_RANDOM_SEED_NUM) //- add for sram repair function to get random seed number from AP
X_CCCI_MISCINFO_CONF(CCMSG_ID_MISCINFO_GPS_COCLOCK)     //- add for L1D to query GPS co-clock information from AP
X_CCCI_MISCINFO_CONF(CCMSG_ID_MISCINFO_SBP_ID)          //- add for single bin file feature, requested by hong
#endif


