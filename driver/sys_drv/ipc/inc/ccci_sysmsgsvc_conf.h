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
 *   ccci_sysmsgsvc_conf.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   user enum for ccci system message service
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
 *
 *
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

//- flag bit mask
//- 7 6 5 4 3 2 1 0 LSB
//- 0 0 0 x x x x x
//- | |
//- | |--> ilm local param neeeded
//- | 	
//- |--> ilm needed

#if defined(__MODEM_CCCI_EXIST__)
//                    CCCI_MSG_ID                                       flag     ilm_msg_id
X_CCCI_SYSMSGSVC_CONF(CCMSG_ID_SYSMSGSVC_L1_DORMANT,                    0,       0)								            //- add for L1 dormant mode used
X_CCCI_SYSMSGSVC_CONF(CCMSG_ID_SYSMSGSVC_L1_SLEEPMASKING,               0,       0)                           //- add for L1 sleep/un-sleep mode used
X_CCCI_SYSMSGSVC_CONF(CCMSG_ID_MD_L4_TX_PWR_LEV_REQ,                    0xC0,    MSG_ID_L4C_MEAS_INFO_REQ)              //- add for L1 TX Power
X_CCCI_SYSMSGSVC_CONF(CCMSG_ID_SYSMSGSVC_L1_QUERY_RF_TEMPERATURE,       0,       0)                           //- add for query L1 RF temperature
X_CCCI_SYSMSGSVC_CONF(CCMSG_ID_SYSMSGSVC_L1_QUERY_3G_RF_TEMPERATURE,    0,       0)                           //- add for query L1 3G RF temperature
X_CCCI_SYSMSGSVC_CONF(CCMSG_ID_SYSMSGSVC_L1_QUERY_AP_VOLTAGE,           0,       0)                           //- add for L1 to query AP volatage. Used for TX and RX.
X_CCCI_SYSMSGSVC_CONF(CCMSG_ID_SYSMSGSVC_LOCK_AP_26M,                   0,       0)                           //- add for USB to lock 26M on AP side. Only used in MT6280
X_CCCI_SYSMSGSVC_CONF(CCMSG_ID_SYSMSGSVC_L4_SIM_INFO,                   0xC0,    MSG_ID_L4C_REGIONAL_PHONE_MODE_REQ)    //- add to send information to AP. Feature: Regional Animation. MD window: Hong
X_CCCI_SYSMSGSVC_CONF(CCMSG_ID_SYSMSGSVC_ICUSB_AP_NOTIFY,               0,       0)
X_CCCI_SYSMSGSVC_CONF(CCMSG_ID_SYSMSGSVC_L1_CRYSTAL_THERMAL_CHANGE,     0,       0)                           //- add for L1 thermal issue in 6571. MD window: Rick.Wu
X_CCCI_SYSMSGSVC_CONF(CCMSG_ID_SYSMSGSVC_L4_TX_PWR_REDU_REQ,            0,       0)                           //- add for L4 for TX power reduction. MD window: Bob.Chiang

#endif


