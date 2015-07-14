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
 *
 * Filename:
 * ---------
 *   ul1cal.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   The structure definition of UL1 calibration data
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#ifndef UL1CAL_H
#define UL1CAL_H

/*===============================================================================*/

#include "kal_general_types.h"
#include "ul1d_rf_public.h"
#include "dcl.h"        //SmartPhone Project's CommonModemImage need this
#include "ul1d_rf_common.h"

/*===============================================================================*/

/* ------------------------------------------------------------------------- */
typedef struct
{
   kal_uint16 tempdacData[8];
}ul1cal_tempdacData_T; 

typedef struct
{
   U_sTEMPAGCOFFSET  pathlossData[CAL_TEMP_SECTION]; 
}ul1cal_pathlossData_T;

typedef struct
{
   U_sRAMPDATA txdacData; 
}ul1cal_txdacData_T;

/* PA 8-level control (MT6276, MT6573) */
typedef struct
{
   U_sPAOCTLVLSETTING txPaOctLevData; 
}ul1cal_txPaOctLevData_T;

typedef struct
{
   U_sPARACHTMCOMPDATA txPrachTmCompData;
}ul1cal_txPrachTmCompData_T;

#if defined (__UL1_HS_PLATFORM__) || defined (__UL1_HS_PLUS_PLATFORM__) 

typedef struct
{
   U_sUl1dRfCustomInputData umtsRfCustomInput;
}ul1cal_umtsRfCustomInput_T;

#endif

#if defined (__UMTS_R8__)
typedef struct
{
   U_sAGCOFFSETRXD  pathlossData; 
}ul1cal_pathlossRxdData_T;

typedef struct
{
   U_sPADRIFTSETTING txPaDriftCompData; 
}ul1cal_txPaDriftCompData_T;

#endif

/*------------- Single Software Load for Multiple Components Compatible -------------*/
/*****************************************************************************
* Constant    : UL1CUSTOM_MAX_RF_BPI_EVENT_NUM
* Group       : Real target, Internal, UL1D common operation
* Description : Constant to be used for record the maximum 3G BPI event
*               support numbers currently in use
*****************************************************************************/
#define UL1CUSTOM_MAX_RF_BPI_EVENT_NUM  (15)          //MT6280 Changes to 15

/*****************************************************************************
* Constant    : UL1CUSTOM_MAX_RF_SUPPORT_BAND_NUM
* Group       : Real target, Internal, UL1D common operation
* Description : Constant to be used for record the maximum 3G RF band
*               support numbers currently in use
*****************************************************************************/
#define UL1CUSTOM_MAX_RF_SUPPORT_BAND_NUM  (5)          //MT6280 Changes to 5

/*****************************************************************************
* Constant    : UL1CUSTOM_NULL_ACTION
*               UL1CUSTOM_GPIO_DETECTION_ID
*               UL1CUSTOM_ADC_DETECTION_ID
*               UL1CUSTOM_NVRAM_BARCODE_DETECTION_ID
* Group       : Real target, Internals, UL1D common operation
* Description : Constant to be used to define the value to be used in
*               enumeration Ul1CustomActionId
*****************************************************************************/
#define UL1CUSTOM_NULL_ACTION                (0)
#define UL1CUSTOM_GPIO_DETECTION_ID          (1)
#define UL1CUSTOM_ADC_DETECTION_ID           (2)
#define UL1CUSTOM_NVRAM_BARCODE_DETECTION_ID (3)

/*****************************************************************************
* Typedef     : Ul1CustomFunction
* Group       : Real target, Internals, UL1D common operation
* Type        : Function pointer
* Description : Internal typedef used by UL1 Custom action function prototype
*****************************************************************************/
typedef void (*Ul1CustomFunction)(void *usrDataPtr);

/*****************************************************************************
* Typedef     : Ul1CustomDynamicInitLnaPortTxPath
* Group       : Real target, Internals, UL1D common operation
* Type        : structure
* Description : Internal typedef used by UL1 Custom dynamic initialization data
*               for LNA port and Tx path setting
*****************************************************************************/
typedef struct
{
   /* User input to notify the band of the data to be modified */
   kal_uint32 bandToModify;

   /* LNA port selection */
   kal_uint8  lnaPortNum;

   /* TX output path selection */
   kal_uint8  txOutputSel; 

   /* RXD LNA port selection */
#if IS_URF_ORION_HPLUS || IS_URF_MT6167 || IS_URF_MT6166
   kal_uint8  lnaPortNum2;
#endif

} Ul1CustomDynamicInitLnaPortTxPath;

/*****************************************************************************
* Typedef     : Ul1CustomDynamicInitUmtsBpiData
* Group       : Real target, Internals, UL1D common operation
* Type        : structure
* Description : Internal typedef used by UL1 Custom dynamic initialization data
*               3G BPI data
*****************************************************************************/
typedef struct
{
   /* User input to notify the band of the data to be modified */
   kal_uint32 bandToModify;

   /* ASM logics */
   kal_uint16 asmLogics[UL1CUSTOM_MAX_RF_BPI_EVENT_NUM];

   /* PA enable control bits */
//   kal_uint8 paEnables[UL1CUSTOM_MAX_RF_BPI_EVENT_NUM];

} Ul1CustomDynamicInitUmtsBpiData;

/*****************************************************************************
* Typedef     : Ul1CustomDynamicInitUmtsTxRampData
* Group       : Real target, Internals, UL1D common operation
* Type        : structure
* Description : Internal typedef used by UL1 Custom dynamic initialization data
*               3G Tx Ramp data
*****************************************************************************/
typedef struct
{
   /* 3G TX Ramp data array */
   U_sRAMPDATA *TxRampData[UL1CUSTOM_MAX_RF_SUPPORT_BAND_NUM];

} Ul1CustomDynamicInitUmtsTxRampData;

/*****************************************************************************
* Typedef     : Ul1CustomDynamicInitUmtsTxPaOctLvlData
* Group       : Real target, Internals, UL1D common operation
* Type        : structure
* Description : Internal typedef used by UL1 Custom dynamic initialization data
*               3G Tx PA oct-level data
*****************************************************************************/
typedef struct
{
   /* 3G TX Ramp data array */
   U_sPAOCTLVLSETTING *TxPaOctLvl[UL1CUSTOM_MAX_RF_SUPPORT_BAND_NUM];

} Ul1CustomDynamicInitUmtsTxPaOctLvlData;

/*****************************************************************************
* Typedef     : Ul1CustomDynamicInitUmtsRxPathLossData
* Group       : Real target, Internals, UL1D common operation
* Type        : structure
* Description : Internal typedef used by UL1 Custom dynamic initialization data
*               3G Rx path loss data
*****************************************************************************/
typedef struct
{
   /* 3G TX Ramp data array */
   U_sTEMPAGCOFFSET *RxPathLoss[UL1CUSTOM_MAX_RF_SUPPORT_BAND_NUM];

} Ul1CustomDynamicInitUmtsRxPathLossData;

/*****************************************************************************
* Typedef     : Ul1CustomDynamicInitUmtsTxPrachTmCompData
* Group       : Real target, Internals, UL1D common operation
* Type        : structure
* Description : Internal typedef used by UL1 Custom dynamic initialization data
*               3G Tx PRACH TM comp. data
*****************************************************************************/
typedef struct
{
   /* 3G TX PRACH TM comp data array */
   U_sPARACHTMCOMPDATA *TxPrachTmComp[UL1CUSTOM_MAX_RF_SUPPORT_BAND_NUM];

} Ul1CustomDynamicInitUmtsTxPrachTmCompData;

/*****************************************************************************
* Typedef     : Ul1CustomDynamicInitUmtsTempDac
* Group       : Real target, Internals, UL1D common operation
* Type        : structure
* Description : Internal typedef used by UL1 Custom dynamic initialization data
*               3G temperature DAC data
*****************************************************************************/
typedef struct
{
   /* 3G Temperature DAC */
   kal_uint16 *UTempDac;

} Ul1CustomDynamicInitUmtsTempDac;


/*****************************************************************************
* Typedef     : Ul1CustomDynamicInitUmtsTxPaDriftCompData
* Group       : Real target, Internals, UL1D common operation
* Type        : structure
* Description : Internal typedef used by UL1 Custom dynamic initialization data
*               3G Tx PA drift comp. data
*****************************************************************************/
typedef struct
{
   /* 3G TX PA Drift comp data array */
   U_sPADRIFTSETTING *TxPaDriftComp[UL1CUSTOM_MAX_RF_SUPPORT_BAND_NUM];

} Ul1CustomDynamicInitUmtsTxPaDriftCompData;


/*****************************************************************************
* Typedef     : Ul1CustomActionId
* Group       : Real target, Internals, UL1D common operation
* Type        : Enumeration
* Description : Internal typedef used by UL1 Custom action ID constant value
*****************************************************************************/
typedef enum
{
   UL1CUSTOM_NULL_ACTION_ID = UL1CUSTOM_NULL_ACTION,
   UL1CUSTOM_BASE_PROC_ACTION_ID = UL1CUSTOM_NULL_ACTION_ID,
   UL1CUSTOM_GPIO_DETECTION = UL1CUSTOM_GPIO_DETECTION_ID,
   UL1CUSTOM_ADC_DETECTION = UL1CUSTOM_ADC_DETECTION_ID,
   UL1CUSTOM_NVRAM_BARCODE_DETECTION = UL1CUSTOM_NVRAM_BARCODE_DETECTION_ID,
   UL1CUSTOM_MAX_PROC_ACTIONS

} Ul1CustomActionId;

/*****************************************************************************
* Typedef     : Ul1CustomDynamicInitResultRFParams
* Group       : Real target, Internals, UL1D common operation
* Type        : Enumeration
* Description : Internal typedef used by UL1 Custom Dynamic init debug
*****************************************************************************/
typedef struct
{
   /* BPI data allocation */
   U_sUl1dRfBpiData umtsPdata;

   /* RF Hign-band and Low-band indicator */
   U_sUl1dRfBandIndicator umtsBandIndicator;

   /* RX LNA port selection */
   U_sUl1dRfRxLnaPortSel umtsRxLnaPortSel;

   /* TX output path selection */
   U_sUl1dRfTxPathSel umtsTxPathSel;

#if IS_URF_ORION_HPLUS || IS_URF_MT6167 || IS_URF_MT6166
   /* RXd Path Setting (Main/Diversity on off Switch) */
   U_sUl1dRxdPathSetting   umtsRxdPathSetting;

   /* PA Drift Compensation (On/Off Switch Mask) */
   kal_uint32 umtsPADriftCompensation;
#endif   
   

} Ul1CustomDynamicInitResultRFParams;

/*****************************************************************************
* Typedef     : Ul1CustomDynamicInitDebug
* Group       : Real target, Internals, UL1D common operation
* Type        : Enumeration
* Description : Internal typedef used by UL1 Custom Dynamic init debug
*****************************************************************************/
typedef struct
{
   kal_uint16 combined_config_index;
   kal_uint8  first_config_index_base;
   kal_uint8  second_config_index_base;
   kal_uint8  third_config_index_base;
   kal_int32  gpio_get_pin_rpc_status;
   #if(IS_3G_DRDI_REMAP_SUPPORT)
   kal_uint32 gpio_return_pin_num[4];
   kal_uint32 gpio_pin_value[4];
   #else
   kal_uint32 gpio_return_pin_num[3];
   kal_uint32 gpio_pin_value[3];
   #endif/*IS_3G_DRDI_REMAP_SUPPORT*/
   kal_uint32 gpio_combined_pin_value;
   kal_int32  adc_get_ch_num_rpc_status;
   DCL_STATUS adc_dcl_handle_status;
   DCL_STATUS adc_cal_dcl_handle_status;
   kal_uint32 adc_get_ch_num;
   kal_uint32 adc_dac_read_result;
   kal_uint32 adc_volt_translate_result;
   kal_uint8  adc_volt_level;
   kal_bool   barcode_lid_read_status;
   kal_uint8  barcode_digit_read_result;
   kal_bool   umts_tempdac_lid_write_status;
   kal_bool   umts_txrampdata_lid_write_status;
   kal_bool   umts_txpaoctlvl_lid_write_status;
   kal_bool   umts_rxpathloss_lid_write_status;   
   kal_bool   umts_txprachtmcomp_lid_write_status;
   kal_bool   umts_rf_params_lid_write_status;
   Ul1CustomDynamicInitResultRFParams custom_dynamic_init_result_params;
   kal_bool   umts_txpadriftcomp_lid_write_status;

} Ul1CustomDynamicInitDebug;
/*------------- Single Software Load for Multiple Components Compatible -------------*/


#endif 	
