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
 *   ccci_excep_dbg_log_conf.h
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *   Header file of confiuration of EXCEP DBG LOG.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __CCCI_EXCEP_DBG_LOIG_CONF_H__
#define __CCCI_EXCEP_DBG_LOIG_CONF_H__
#if defined(__MODEM_CCCI_EXIST__)

//- Format: Index, Length
X_CCCI_EXCEP_DBG_LOG_CONF(CCCI_EXCEP_DBG_IDLE_TASK_DCM_ENTER, 4)
X_CCCI_EXCEP_DBG_LOG_CONF(CCCI_EXCEP_DBG_IDLE_TASK_DCM_LEAVE, 4)
X_CCCI_EXCEP_DBG_LOG_CONF(CCCI_EXCEP_DBG_IDLE_TASK_SLEEP_ENTER, 4)
X_CCCI_EXCEP_DBG_LOG_CONF(CCCI_EXCEP_DBG_IDLE_TASK_SLEEP_LEAVE, 4)
X_CCCI_EXCEP_DBG_LOG_CONF(CCCI_EXCEP_DBG_IDLE_TASK_WFI_ENTER, 4)
X_CCCI_EXCEP_DBG_LOG_CONF(CCCI_EXCEP_DBG_IDLE_TASK_WFI_LEAVE, 4)
X_CCCI_EXCEP_DBG_LOG_CONF(CCCI_EXCEP_DBG_INT_EXCEPTION_ENTER, 4)
X_CCCI_EXCEP_DBG_LOG_CONF(CCCI_EXCEP_DBG_EXCEPTION_FLOW_INDEX, 4)
X_CCCI_EXCEP_DBG_LOG_CONF(CCCI_EXCEP_DBG_SWLA_LOG_MARK, 4)          //- Reserved for SWLA logging.
X_CCCI_EXCEP_DBG_LOG_CONF(CCCI_EXCEP_DBG_SWLA_LOG_TIME, 4)          //- Reserved for SWLA logging.
X_CCCI_EXCEP_DBG_LOG_CONF(CCCI_EXCEP_DBG_EPOF_ENTER, 4)             // for recording EPOF enter
X_CCCI_EXCEP_DBG_LOG_CONF(CCCI_EXCEP_DBG_INFINITESLEEP_WFI, 4)      // for recording EPOF into infinite sleep  
X_CCCI_EXCEP_DBG_LOG_CONF(CCCI_EXCEP_DBG_SW_WDT_TIME, 4)            // for recording EPON/EE(production version) trigger wdt

#endif /* __MODEM_CCCI_EXIST__ */
#endif  /* __CCCI_EXCEP_DBG_LOIG_CONF_H__ */
