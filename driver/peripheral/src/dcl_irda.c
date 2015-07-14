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
 *    dcl_irda.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines DCL (Driver Common Layer) of the IRDA driver.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "drv_features.h"
#include "drv_comm.h"
#include "kal_public_api.h" //MSBB change #include	"kal_release.h"
#include "kal_public_defs.h" //MSBB change #include	"stack_common.h"  
#include "kal_public_defs.h" //MSBB change #include	"stack_msgs.h"
#include "stack_ltlcom.h" //MSBB change #include "app_ltlcom.h"
#if defined(__FLC2__) //EVB load has FLC define, but basic load do not have this header file.
#include "flc_api.h"
#endif //#if defined(__FLC2__)
#ifdef __IRDA_SUPPORT__
#include "irFramer_sw.h"
#endif  // __IRDA_SUPPORT__
#include "dcl.h"

#ifdef DCL_IRDA_INTERFACE

#define DCL_IRDA_MAGIC_NUM  0x40000000
#define DCL_IRDA_IS_HANDLE_MAGIC(handl_) ((handl_)& DCL_IRDA_MAGIC_NUM)
#define DCL_IRDA_GET_DEV(handle_) ((handle_) & (~DCL_IRDA_MAGIC_NUM))
#ifdef __IRDA_SUPPORT__
static kal_bool fgSIrDAOpen = KAL_FALSE;
extern kal_bool irda_tun_on;
#endif //__IRDA_SUPPORT__

/*************************************************************************
* FUNCTION
*  DclIRDA_Initialize
*
* DESCRIPTION
*  This function is to initialize IRDA module. 
*
* PARAMETERS
*	DCL_STATUS_OK
*  STATUS_UNSUPPORTED - IrDA is not supported or enabled.
*
* RETURNS
*  none
*
*************************************************************************/
DCL_STATUS DclIRDA_Initialize(void)
{
   extern kal_bool irda_init(void);
   
#ifdef __IRDA_SUPPORT__
   irda_init(INDX_IRDA); //the task_indx does not be handled in init function.
   return STATUS_OK;
#else // __IRDA_SUPPORT__
   return STATUS_UNSUPPORTED;
#endif  // __IRDA_SUPPORT__
}

/*************************************************************************
* FUNCTION
*  DclIRDA_Open
*
* DESCRIPTION
*  This function is to open the IRDA module and get a handle. Note that 
* multiple opens are not allowed.
*
* PARAMETERS
*	eDev - only valid for DCL_IRDA
*	flags - no sepcial flags is needed. Please use FLAGS_NONE
*
* RETURNS
*	DCL_HANDLE_INVALID - Open failed.
*  STATUS_UNSUPPORTED - IrDA is not supported or enabled.
*  other value - a valid handle
*
*************************************************************************/
DCL_HANDLE DclIRDA_Open(DCL_DEV eDev, DCL_FLAGS flags)
{
#ifdef __IRDA_SUPPORT__
   if ((eDev != DCL_IRDA) || (fgSIrDAOpen == KAL_TRUE))
   {
      ASSERT(0);
      return DCL_HANDLE_INVALID;
   }
   IRDA_Open();
   irda_tun_on=KAL_TRUE;
   fgSIrDAOpen = KAL_TRUE;
   return (DCL_IRDA_MAGIC_NUM | DCL_IRDA);
#else // __IRDA_SUPPORT__
   return STATUS_UNSUPPORTED;
#endif  // __IRDA_SUPPORT__
}

/*************************************************************************
* FUNCTION
*  DclIRDA_ReadData
*
* DESCRIPTION
*  This function is not supported for the IRDA module now.
*
* PARAMETERS
*	N/A
*
* RETURNS
*	STATUS_UNSUPPORTED
*
*************************************************************************/
DCL_STATUS DclIRDA_ReadData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN *buf_len, DCL_OPTIONS options)
{
   return STATUS_UNSUPPORTED;
}

/*************************************************************************
* FUNCTION
*  DclIRDA_WriteData
*
* DESCRIPTION
*  This function is not supported for the IRDA module now.
*
* PARAMETERS
*	N/A
*
* RETURNS
*	STATUS_UNSUPPORTED
*
*************************************************************************/
DCL_STATUS DclIRDA_WriteData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN *buf_len, DCL_OPTIONS options)
{
   return STATUS_UNSUPPORTED;
}

/*************************************************************************
* FUNCTION
*  DclIRDA_Configure
*
* DESCRIPTION
*  This function is to configure for the IRDA module.
*
* PARAMETERS
*	handle - a valid handle return by DclIRDA_Open()
*  configure - a ponter to IRDAT_CONFIG_T structure which is a member of union 
*              DCL_CONFIGURE_T.
*
* RETURNS
*	STATUS_OK - successfully set the configuratuib.
*  STATUS_INVALID_HANDLE - It's a invalid handle.
*  STATUS_UNSUPPORTED - IrDA is not supported or enabled.
*
*************************************************************************/
DCL_STATUS DclIRDA_Configure(DCL_HANDLE handle, DCL_CONFIGURE_T *configure)
{
#ifdef __IRDA_SUPPORT__
   IrDataConfig rConfig;
   IrDataConfig *prConfig = &rConfig;
   IRDA_CONFIG_T *prIrDAConfig;

   if (!DCL_IRDA_IS_HANDLE_MAGIC(handle))
   {
      ASSERT(0);
      return STATUS_INVALID_HANDLE;
   }
   prIrDAConfig = &(configure->rIRDACofig);
   prConfig->modulation_1p63 = (prIrDAConfig->fgModulation1p63==DCL_TRUE) ? KAL_TRUE:KAL_FALSE;
   prConfig->bof_type_0xff = (prIrDAConfig->fgBOFType0xff==DCL_TRUE) ? KAL_TRUE:KAL_FALSE;
   prConfig->mir_double_sta_num = (prIrDAConfig->uMirDoubleStaNum > DCL_MIR_DOUBLE_STA_MAX) ? DCL_MIR_DOUBLE_STA_MAX:prIrDAConfig->uMirDoubleStaNum;
   IRDA_Config(prConfig);
   return STATUS_OK;
#else // __IRDA_SUPPORT__
   return STATUS_UNSUPPORTED;
#endif  // __IRDA_SUPPORT__
}


/*************************************************************************
* FUNCTION
*  DclIRDA_RegisterCallback
*
* DESCRIPTION
*  This function is not supported for the IRDA module now.
*
* PARAMETERS
*	N/A
*
* RETURNS
*	STATUS_UNSUPPORTED
*
*************************************************************************/
DCL_STATUS DclIRDA_RegisterCallback(DCL_HANDLE handle, DCL_EVENT event, PFN_DCL_CALLBACK callback)
{
   return STATUS_UNSUPPORTED;
}


/*************************************************************************
* FUNCTION
*  DclIRDA_Control
*
* DESCRIPTION
*  This function is not supported for the IRDA module now.
*
* PARAMETERS
*	N/A
*
* RETURNS
*	STATUS_UNSUPPORTED
*
*************************************************************************/
DCL_STATUS DclIRDA_Control(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data)
{
   return STATUS_UNSUPPORTED;
}

/*************************************************************************
* FUNCTION
*  DclIRDA_Close
*
* DESCRIPTION
*  This function is to close the IRDA module.
*
* PARAMETERS
*	handle  - hanlde previous got from DclIRDA_Open()
*
* RETURNS
*	DCL_STATUS_OK - successfully close the IRDA module.
*  STATUS_NOT_OPENED - IrDA hasn't been opened yet.
*  STATUS_INVALID_HANDLE - It's a invalid handle.
*  STATUS_UNSUPPORTED - IrDA is not supported or enabled.
*
*************************************************************************/
DCL_STATUS DclIRDA_Close(DCL_HANDLE handle)
{
#ifdef __IRDA_SUPPORT__
   if(fgSIrDAOpen == KAL_FALSE)
   {
      ASSERT(0);
      return STATUS_NOT_OPENED;
   }
   if (!DCL_IRDA_IS_HANDLE_MAGIC(handle))
   {
      ASSERT(0);
      return STATUS_INVALID_HANDLE;
   }
   IRDA_Close(CONTENTION_BAUD);
   irda_tun_on = KAL_FALSE;
   fgSIrDAOpen = KAL_FALSE;
   return STATUS_OK;
#else // __IRDA_SUPPORT__
   return STATUS_UNSUPPORTED;
#endif  // __IRDA_SUPPORT__
}


#endif //#ifdef DCL_IRDA_INTERFACE

