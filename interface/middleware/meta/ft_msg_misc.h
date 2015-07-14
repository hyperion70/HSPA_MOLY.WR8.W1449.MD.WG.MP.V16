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
/*******************************************************************************
*  Modification Notice:
*  --------------------------
*  This software is modified by MediaTek Inc. and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2001
*
*******************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *   ft_msg_misc.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Messages definition of MISC category of FT Library
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 * 				HISTORY
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#ifndef __FT_MSG_MISC_H__
#define __FT_MSG_MISC_H__
#include "ft_msg_common.h"



/*******************************************************************************
*
*  Message structures defined for MISC Command 
*
*******************************************************************************/


typedef enum 
{
    FT_MISC_OP_GET_IMEI_LOC = 0
   ,FT_MISC_OP_GET_IMEI_VALUE
   ,FT_MISC_OP_GET_CAL_INFO
	 ,FT_MISC_OP_VERIFY_TEMP_SML_FILE
	 ,FT_MISC_OP_QUERY_NVRAM_FOLDER
	 ,FT_MISC_OP_VERIFY_NVRAM_ATTR_SETTING_COMPLETE
	 ,FT_MISC_OP_ENABLE_PATH_LIMITION
   ,FT_MISC_OP_DISABLE_PATH_LIMITION
   ,FT_MISC_OP_GET_IMEI_REC_NUM
   ,FT_MISC_OP_SET_IMEI_VALUE
   ,FT_MISC_OP_GET_NVRAM_FOLDER_AMOUNT
   ,FT_MISC_OP_CHECK_SIM1_INSERTED
   ,FT_MISC_OP_CHECK_SIM2_INSERTED
   ,FT_MISC_OP_SET_MUIC_CHARGER_MODE  //  __DRV_EXT_CHARGER_DETECTION__
   ,FT_MISC_OP_CALDATA_INTEGRITY_START_REC
   ,FT_MISC_OP_CALDATA_INTEGRITY_STOP_REC
   ,FT_MISC_OP_CALDATA_INTEGRITY_ADD_ONE
   ,FT_MISC_OP_CALDATA_INTEGRITY_DEL_ONE
   ,FT_MISC_OP_CALDATA_INTEGRITY_DEL_ALL
   ,FT_MISC_OP_CALDATA_INTEGRITY_CHECK_ONE
   ,FT_MISC_OP_CALDATA_INTEGRITY_CHECK_ALL
   ,FT_MISC_OP_GET_ADC_FROM_EFUSE
   ,FT_MISC_OP_GET_CALFLAG_ENUM
   ,FT_MISC_OP_GET_RF_CAL_ENV_ENUM
   ,FT_MISC_OP_GET_RF_CAL_LOSS_SETTING_ENUM
   ,FT_MISC_OP_GET_RF_TEST_POWER_RESULT_ENUM
   ,FT_MISC_OP_GET_ADC_MAX_CHANNEL
   ,FT_MISC_OP_GET_TADC_INDEX
   ,FT_MISC_OP_GET_RID
   ,FT_MISC_OP_CHECK_GEMINI_PLUS_SIM_INSERTED
   ,FT_MISC_OP_GET_MMI_CACHE_ENUM_INDEX
   ,FT_MISC_OP_SET_WIFI_MAC_ADDR
   ,FT_MISC_OP_GET_BARCODE_VALUE
   ,FT_MISC_OP_END
   
}FT_MISC_CMD_TYPE;

typedef struct
{
	kal_uint16					record_index;
	kal_uint8						imei[8];
	kal_uint8						svn;
}FT_MISC_SET_IMEI_VALUE_REQ_T;

typedef struct
{
	 kal_uint16         u2LidEnum;
	 kal_uint16         u2RID;
}FT_MISC_CAL_DATA_INTEGRITY_ENTRY;

typedef union 
{
   kal_bool   m_bcheckImeiFlag;
   FT_MISC_SET_IMEI_VALUE_REQ_T m_rIMEIData;
   kal_uint16 m_u1RecordIndex;
   kal_uint8      m_u1ChargerMode;
   FT_MISC_CAL_DATA_INTEGRITY_ENTRY  m_rCalDataOne;
   /// [IN] requested RID length for the RID query operation
   kal_uint8 m_RIDLength;
   /// [IN] requested SIM index for the SIM insertion test operation
   kal_uint8 m_u1SimIndex;
   /// [IN] MMI cache enum value query
   kal_uint16                        m_u2MmiCacheEnumValue;
   kal_uint8                         buffer[6];
}FT_MISC_CMD_U;

typedef struct
{
  kal_uint8 buf[20];   // default: 10 digits  
  kal_uint8 buf_len;

}FT_IMEI_DATA_T;

typedef struct 
{
	kal_uint16 m_stop_enum_value;
	kal_uint16 m_total_lid_num;
	kal_uint16 m_stop_index;
	
}FT_NVRAM_SETTINGS_VERIFY_T;

typedef struct
{
	 kal_uint8        m_u1LastFrame;  // to mark it is the last frame for FT_MISC_OP_GET_CAL_INFO
   kal_uint16       m_u2TotalNum;  // only valid when lastframe = 1;
	
}FT_CAL_INFO_T;


typedef struct
{
	  kal_bool bAllPass;
	  kal_uint16 u2LastLID;
	  kal_uint16 u2LastRID;
}FT_MISC_CAL_DATA_INTEGRITY_CHECK_CNF_T;
typedef struct 
{
   kal_bool      bADCStoredInEfuse;
   kal_uint16     u2ADCChnNum;    
}FT_MISC_GET_ADC_FROM_EFUSE_CNF_T;

typedef struct
{ 
   /// [OUT] requested RID length (unit: bytes)
   kal_uint8 buf_len;
   /// [OUT] RID raw buffer returned from the target side 
   kal_uint8 buf[16];
}META_RID_DATA_T;

typedef union
{
   kal_uint8                   m_u1IMEILoc;
   FT_IMEI_DATA_T              m_rIMEIData;
   kal_uint8                   m_u1LastFrame;
   kal_bool                    m_bCheckResult; 
   kal_uint8                   m_u1VerifyResult;
   FT_NVRAM_SETTINGS_VERIFY_T  m_rNvramVerifyResult;
   kal_uint16                              m_u2IMEIRecords;
   kal_uint16                              m_u2RecordIndex;
   kal_uint8                               m_u1NVRAMFolderAmount;
   kal_uint8                               m_u1SIMInserted;
   kal_uint8                               m_u1CurRecNum;
   FT_MISC_CAL_DATA_INTEGRITY_CHECK_CNF_T  m_rCalCheckAll;
   FT_MISC_GET_ADC_FROM_EFUSE_CNF_T        m_rGetAdcFromEfuse; 
   kal_uint16                              m_u2CalFlagEnum;
   kal_uint8                               m_u1ADCMaxChannel;
   kal_uint8                               m_u1TADCChannelIndex;
   kal_uint16                              m_u2Enum;
   /// [OUT] RID data structure contains RID length and buffer from target side
   META_RID_DATA_T                         m_rRIDData;
   /// [OUT] MMI cache enum value index of the NVRAM cache byte
   kal_uint16                              m_u2NvramDataIndexOfMmiCacheEnumValue;                         
}FT_MISC_CNF_U;

typedef struct
{
    FT_H               header;
    FT_MISC_CMD_TYPE   type;
    FT_MISC_CMD_U      cmd;    

}FT_MISC_REQ;

typedef struct
{
    FT_H                header;
    FT_MISC_CMD_TYPE	  type;
    FT_MISC_CNF_U       result;
	  kal_uint32				  status;
}FT_MISC_CNF;

#endif // #ifndef __FT_MSG_MISC_H__
