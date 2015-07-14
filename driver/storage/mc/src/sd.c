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
 *   sd.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   driver functons for SD/MMC
 *
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
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
 * removed!
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
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
#ifndef DRV_MSDC_OFF
#include "kal_public_api.h" //MSBB change #include "kal_release.h"
//RHR ADD
#include "kal_general_types.h"
//#include "btif_sw.h"
#include "kal_public_api.h"
#include "kal_public_defs.h"
#include "kal_debug.h"
#include "init.h"
//RHR REMOVE
/*
//MSBB remove #include "kal_non_specific_general_types.h"
//MSBB remove #include "app_buff_alloc.h"
#include "intrCtrl.h"
//#include "gpio_sw.h"
#include "init.h"
#include "pmic_features.h"
#include "pmu_sw.h"
#include "nucleus.h"
#include "ev_defs.h"
*/
//RHR
#include "kal_trace.h"
#include "dcl.h"
#include "drv_comm.h"
#include "drv_features.h"
#include "kal_public_defs.h" //MSBB change #include "stack_config.h"
#if !defined(__UBL__) || defined(__CARD_DOWNLOAD__) || defined(__EMMC_BOOTING__)
#include "us_timer.h"
#include "msdc_reg_adap.h"
#include "reg_base.h"
#include "msdc_api.h"
#include "msdc_def.h"
#include "sd_def.h"
#include "upll_ctrl.h"
#include "drv_trc.h"
#if defined(__AUDIO_DSP_LOWPOWER__)
#include "audlp_exp.h"
#endif

#include "dma_hw.h"

#if defined(__EMMC_BOOTING__)
#include "FTL.h"
#endif

#ifdef DRV_LSD
#include "msdc_lsd.h"

extern void LSD_Host74TCMDHigh(void);
extern kal_bool LSD_HostDetectBusy(void);
#endif

#if defined(__MSDC_SD_MMC__)
//global variables
T_SDC_HANDLE	gSD_blk[SD_NUM];
T_SDC_HANDLE	*gSD = gSD_blk;

static SDC_CMD_STATUS gblSDsta;

extern MSDC_Custom_Handle msdc_custom_handle;
void SD_Sleep4Wait(kal_int32 sleep_tick);
void SD_Use13M_Clock(void);
extern kal_uint8 MSDC_GetIOCtrlParam(void);
extern kal_bool INT_USBBoot(void);
#if defined(DRV_MSDC_LATCH_MT6276_SERIES)
extern void MSDC_SetLatchTuning(void);
#else
extern void MSDC_SetIOCONRegDLT(void);
#endif//#if defined(DRV_MSDC_LATCH_MT6276_SERIES)
//kal_uint32 sd_writeFailReason; // fix Lint warning
#if !defined(DRV_MSDC_LATCH_MT6276_SERIES)
void SD_SetRedDlt(kal_uint32 redDlt);
#endif//#if !defined(DRV_MSDC_LATCH_MT6276_SERIES)
extern void SLA_CustomLogging(kal_char *customJob, kal_int32 saAction); 

#ifdef DRV_MSDC_SDC_V3
static kal_uint32 sd_cmd_extra = ((64) << 24);	// CTOC = 64
#else
static kal_uint32 sd_cmd_extra = 0;
#endif

#if defined(__SIM_PLUS__)
#if !defined(__CUST_NEW__)
kal_char MSDC_GetClockWithoutSIMPlus(void);
#endif
#endif



#ifdef DCL_MSDC_INTERFACE
#include "dcl.h"

SDC_CMD_STATUS SD_SetCallBack(MSDC_CALLBACK callback1, MSDC_CALLBACK callback2, MSDC_CALLBACK callback3, MSDC_CALLBACK callback4, MSDC_CALLBACK callback5, MSDC_CALLBACK callback6);
SDC_CMD_STATUS SD_SetReadTestFlag(kal_uint32 readTestFlag);
SDC_CMD_STATUS SD_readTest(void);
SDC_CMD_STATUS SD_SetUpllClock(void);

#ifdef __MEUT__
SDDriver_t sd_driver_MTK1 =
{
    (DCL_SINGLE_BLK_RD)SD_ReadSingleBlock,
    (DCL_MUL_BLK_RD)SD_ReadMultiBlock,
    (DCL_SINGLE_BLK_WR)SD_WriteSingleBlock,
    (DCL_MUL_BLK_WR)SD_WriteMultiBlock,
    (DCL_SD_INITITALIZE)SD_Initialize,
    (DCL_SET_PRE_ERASE_CNT)SD_SetPreEraseBlk,
    (DCL_SD_SET_CALLBACK)SD_SetCallBack,
    (DCL_SET_READ_TEST_FLAG)SD_SetReadTestFlag,
    (DCL_SD_READ_TEST)SD_readTest,
    (DCL_SD_SET_UPLL_CLOCK_TEST)SD_SetUpllClock,
    (DCL_SD_ERASE_BLK)SD_FlushSectors,
};
#else
SDDriver_t sd_driver_MTK1 =
{
    (DCL_SINGLE_BLK_RD)SD_ReadSingleBlock,
    (DCL_MUL_BLK_RD)SD_ReadMultiBlock,
    (DCL_SINGLE_BLK_WR)SD_WriteSingleBlock,
    (DCL_MUL_BLK_WR)SD_WriteMultiBlock,
    (DCL_SD_INITITALIZE)SD_Initialize,
    (DCL_SET_PRE_ERASE_CNT)SD_SetPreEraseBlk,
    (DCL_SD_SET_CALLBACK)NULL,
    (DCL_SET_READ_TEST_FLAG)NULL,
    (DCL_SD_READ_TEST)NULL,
    (DCL_SD_SET_UPLL_CLOCK_TEST)NULL,
    (DCL_SD_ERASE_BLK)SD_FlushSectors,
};
#endif

#endif

#if defined( __MSDC_BASIC_LOAD__) || defined( __MEUT__)
#define MSDC_TESTBUFFER_SIZE	512
kal_uint32	msdc_testBuffer[(MSDC_TESTBUFFER_SIZE / 4)];
kal_uint32	msdc_writeBuffer[(MSDC_TESTBUFFER_SIZE / 4)];

#define CMD_DVT_TEST_STATUS 7
kal_uint32 msdc_ReadTestFlag;
MSDC_CALLBACK msdc_TestCallBack1;
MSDC_CALLBACK msdc_TestCallBack2;
MSDC_CALLBACK msdc_TestCallBack3;
MSDC_CALLBACK msdc_TestCallBack4;
MSDC_CALLBACK msdc_TestCallBack5;
MSDC_CALLBACK msdc_TestCallBack6;
static kal_uint32 sendCmdTimes = 0;
#endif

#ifdef __CARD_DOWNLOAD__
extern kal_bool MSDC_QueryIsPowerControllable(void);
extern void MSDC_SetPower(kal_bool enable);
#endif

/*************************************************************************
* FUNCTION
*  SD_Acmd42
*
* DESCRIPTION
*	connect/disconnect the 50K Ohm pull-up resistor on CD/DAT3
*
* PARAMETERS
*
* RETURNS
*	SDC_CMD_STATUS
*
* GLOBALS AFFECTED
*	gSD
*
* NOTE
*
*
*************************************************************************/

// Get CID(CMD2)
SDC_CMD_STATUS SD_Acmd42(kal_bool connect)
{
    SDC_CMD_STATUS status;

    // send APP_CMD
    if ((status = SD_Cmd55(gSD->mRCA)) != NO_ERROR)
        return status;

    // send cmd6
    if ((status = SD_Send_Cmd(SDC_CMD_ACMD42, connect)) != NO_ERROR)
        return status;

    //read R1
    if ((status = SD_CheckStatus()) != NO_ERROR)
        return status;

    gSD->mCD_DAT3 = KAL_FALSE;	// pull-up resistor is disconnected for data trnasfer
    return NO_ERROR;
}


#if defined(MSDC_MMC441_SUPPORT)

kal_bool SD_eMMC_ECSD_setValue(kal_uint8 addr, kal_uint8 value)
{
    //kal_uint32 r0; // [TODO]: eMMC
    //kal_bool status = KAL_FALSE;
    kal_uint8 *pData;

    if (192 <= addr) //addr above 192 is information registers, we can't write these registers
        ASSERT(0);

    MSDC_PDNControl(KAL_FALSE);

    if (NO_ERROR != SD_Switch_MMC40(SET_BYTE, addr, value, 0))
        ASSERT(0);

    //if(NO_ERROR != SD_GetStatus(gSD->mRCA,(kal_uint32*)&r0))
    //	ASSERT(0);
    if (NO_ERROR != SD_SendEXTCSD_MMC40(MSDC_Sector))
        ASSERT(0);

    pData = (kal_uint8 *)MSDC_Sector;

    if (value !=  *(pData + addr))
        ASSERT(0);

    //status = KAL_TRUE;
    MSDC_PDNControl(KAL_TRUE);
    return KAL_TRUE;
}

/*
	This API is to ask eMMC to start the partition.
	That is, this API should be called after configuring partition settings.
*/
kal_bool SD_eMMC_ECSD_StartPartition()
{
    kal_bool status;

    /*if this is not eMMC 4.4, assert it */
    //EMMC44_CHECK_AND_ASSERT;

    /*the device has been partitioned*/
    if (EMMC_MASK_PARTITION_SETTING & gSD->mCSD.ext_csd->partition_settig)
    {
        ASSERT(0);
    }

    status = SD_eMMC_ECSD_setValue(EXT_CSD_PARTITION_CONFIG_INDEX, 1);

    return status;
}

// unit: 512-byte
kal_uint32 SD_eMMC_getWpgSize()
{
    if ((1 & gSD->mCSD.ext_csd->erase_grp_def) && (gSD->mCSD.ext_csd->hc_wp_grp_size > 0))
        return 1024 * gSD->mCSD.ext_csd->hc_erase_grp_size * gSD->mCSD.ext_csd->hc_wp_grp_size;
    else
        return (gSD->mCSD.wp_grp_size_mmc >> 9);
}

/*
	This API is called to configure partition settings. Size unit is 512-byte.
*/
kal_bool SD_eMMC_ECSD_configPartition(eMMC_partitions partition, kal_uint32 startAddr, kal_uint32 size, kal_bool isEnhanced)
{
    kal_bool status;
    kal_uint32 maxEnhSizeMult;
    kal_uint32 wpgSize;
    kal_uint32 wpgNum;
    kal_uint32 partitionSize[5];
    kal_uint8	regIndex;
    kal_uint8 value[3];

    if (eMMC_GP_partition1 > partition || eMMC_user_Area < partition)
        ASSERT(0);

    /*if this is not eMMC 4.4, assert it */
    //EMMC44_CHECK_AND_ASSERT;

    /*1st, if this card does not support enhanced feature or does not support partition feature, we can not do this function*/

    /*	2nd, there is a limitation for the total size of enhanced memory area.
    	we have to know the total size of other existed enhanced area and check whether the setting violet the limitation.
    */
    maxEnhSizeMult = gSD->mCSD.ext_csd->max_enh_size_mult[0] | ( gSD->mCSD.ext_csd->max_enh_size_mult[1] << 8) | ( gSD->mCSD.ext_csd->max_enh_size_mult[2] << 16);

    /*get current all partition size*/
    partitionSize[eMMC_GP_partition1 - eMMC_GP_partition1] = gSD->mCSD.ext_csd->gp_size_mult[0] | ( gSD->mCSD.ext_csd->gp_size_mult[1] << 8) | ( gSD->mCSD.ext_csd->gp_size_mult[2] << 16);
    partitionSize[eMMC_GP_partition2 - eMMC_GP_partition1] = gSD->mCSD.ext_csd->gp_size_mult[3] | ( gSD->mCSD.ext_csd->gp_size_mult[4] << 8) | ( gSD->mCSD.ext_csd->gp_size_mult[5] << 16);
    partitionSize[eMMC_GP_partition3 - eMMC_GP_partition1] = gSD->mCSD.ext_csd->gp_size_mult[6] | ( gSD->mCSD.ext_csd->gp_size_mult[7] << 8) | ( gSD->mCSD.ext_csd->gp_size_mult[8] << 16);
    partitionSize[eMMC_GP_partition4 - eMMC_GP_partition1] = gSD->mCSD.ext_csd->gp_size_mult[9] | ( gSD->mCSD.ext_csd->gp_size_mult[10] << 8) | ( gSD->mCSD.ext_csd->gp_size_mult[11] << 16);
    partitionSize[eMMC_user_Area - eMMC_GP_partition1] = gSD->mCSD.ext_csd->enh_size_mult[0] | ( gSD->mCSD.ext_csd->enh_size_mult[1] << 8) | ( gSD->mCSD.ext_csd->enh_size_mult[2] << 16);

    /*calculate how many wpg we need to set*/
    wpgSize = SD_eMMC_getWpgSize();
    wpgNum = (size / wpgSize) + ((size % wpgSize) > 0 ? 1 : 0);

    /*replace old size with the new size we want to set*/
    partitionSize [partition - eMMC_GP_partition1] = wpgNum;

    if ((partitionSize[0] + partitionSize[1] + partitionSize[2] + partitionSize[3] + partitionSize[4]) > maxEnhSizeMult)
        return KAL_FALSE;

    /*everything check passed, now we can set the value*/
    if (eMMC_user_Area > partition)
        regIndex = EXT_CSD_GP_SIZE_MULT_GP0_INDEX + 3 * (partition - eMMC_GP_partition1);
    else
        regIndex = EXT_CSD_ENH_SIZE_MULT_INDEX;

    value[2] = wpgNum / 64;
    value[1] = (wpgNum - (value[2] * 64)) / 8;
    value[0] = wpgNum - (value[2] * 64) - (value[1] * 8);
    status = SD_eMMC_ECSD_setValue(regIndex, value[0]);

    if (KAL_TRUE != status)
        goto err_exit;

    status = SD_eMMC_ECSD_setValue(regIndex + 1, value[1]);

    if (KAL_TRUE != status)
        goto err_exit;

    status = SD_eMMC_ECSD_setValue(regIndex + 2, value[2]);

    if (KAL_TRUE != status)
        goto err_exit;

err_exit:
    return status;

}

/*
	This API is to configure to boot from specified partition.
	By this API, DA can decide from wich partition, will card output the boot code in boot mode.
*/
kal_bool SD_eMMC_ECSD_setCurrentPart(eMMC_partitions partition)
{
    kal_uint8 regValue;
    kal_bool status;
    eMMC_partitions pt;

  	if (0 == partition || eMMC_user_Area < partition)
        ASSERT(0);

    /*if this is not eMMC 4.4, assert it */
    //EMMC44_CHECK_AND_ASSERT;

    pt = (partition == eMMC_user_Area) ? 0 : partition;

    regValue = gSD->mCSD.ext_csd->partition_config;

    /*currently it uses the setting DA want, no need to change*/
    if (pt == (EMMC_MASK_PARTITION_CONFIG & regValue))
        return KAL_TRUE;

    regValue &= ~EMMC_MASK_PARTITION_CONFIG;
    regValue |= pt;
    status = SD_eMMC_ECSD_setValue(EXT_CSD_PARTITION_CONFIG_INDEX, regValue);

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined(__EMMC_BOOTING__)
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

    return status;
}

/*************************************************************************
* FUNCTION
*  SD_IsEMMC
*
* DESCRIPTION
*	Check inserted card is e-MMC 4.4
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*	gSD
*
*************************************************************************/
void SD_IsEmmcV44()
{
    /*	from eMMC 4.3, EXT_CSD_REV has maximum value 3, and from eMMC 4.4, EXT_CSD_REV new value 4, 5
    */
    if (3 < gSD->mCSD.ext_csd->ext_csd_rev)
    {
        if (0 != gSD->mCSD.ext_csd->boot_size_mul) //has boot partition, this is eMMC
        {
            gSD->emmc_info.isEmmcV44 = (kal_bool)KAL_TRUE;
            gSD->emmc_info.bootPartitionSize = 2 * 128 * gSD->mCSD.ext_csd->boot_size_mul;
            gSD->emmc_info.gp1PartitionSize = SD_eMMC_getWpgSize() *
                                              (gSD->mCSD.ext_csd->gp_size_mult[0]
                                               + ( gSD->mCSD.ext_csd->gp_size_mult[1] * 256)
                                               + ( gSD->mCSD.ext_csd->gp_size_mult[2] * 65536));

            /*from spec, alternated boot method is mandatory for eMMC4.4*/
            if ( 0 == (0x1 & gSD->mCSD.ext_csd->boot_info))
                ASSERT(0);

            /*we can't use the card that don't have RST signal support*/
            if ( 0x2 == (0x3 & gSD->mCSD.ext_csd->rst_function))
                ASSERT(0);

            if ( 0x1 == (0x1 & gSD->mCSD.ext_csd->partition_support))
                gSD->emmc_info.supportPartition = (kal_bool)KAL_TRUE;
            else
                gSD->emmc_info.supportPartition = (kal_bool)KAL_FALSE;

            if ( 0x2 == (0x2 & gSD->mCSD.ext_csd->partition_support))
                gSD->emmc_info.supportEnhancedPart = (kal_bool)KAL_TRUE;
            else
                gSD->emmc_info.supportEnhancedPart = (kal_bool)KAL_FALSE;
        }
        else   //normal mmc card without boot support
        {
            gSD->emmc_info.isEmmcV44 = (kal_bool)KAL_FALSE;
        }
    }
    else   //spec version below or equals to eMMC 4.3
    {
        gSD->emmc_info.isEmmcV44 = (kal_bool)KAL_FALSE;
    }
}

#endif//defined(MSDC_MMC441_SUPPORT)


/*************************************************************************
* FUNCTION
*  SD_SetMMC40_4bit_high_speed
*
* DESCRIPTION
*	Check inserted card is SD or MMC
*
* PARAMETERS
*
*
* RETURNS
*  SD_CARD or MMC_CARD
*
* GLOBALS AFFECTED
*	gMSDC_Handle
*
*************************************************************************/
SDC_CMD_STATUS SD_SetMMC40_bus_high_speed(void)
{
    kal_uint32 clock, hs;
//    kal_uint8 *pData;

#ifdef DRV_MSDC_MT6225_SERIES
    /*use larger driving current. In mt6225 and mt6227D, IOCON is 32 bit register and DLT cannot be 0*/
    //MSDC_LSD_WriteReg32(MSDC_IOCON,0x36);
    MSDC_ClearBits32(MSDC_IOCON, MSDC_IOCON_CMDRE);
    MSDC_SetIOCONRegDLT();
#else
    //MSDC_LSD_WriteReg(MSDC_IOCON,0x1B);
#endif

    SD_Use13M_Clock();
#if !defined(DRV_MSDC_CLK_MT6276_SERIES) && !defined(DRV_MSDC_CLK_MT6256_SERIES)
    MSDC_SetIOCONRegDLT();
#endif

#if !defined(__EMMC_BOOTING__)

    if (SD_SetBlength(512) != NO_ERROR)
        goto err;

#endif

#ifndef MSDC_SPECIAL_MMC_41_CARD

    // read the EXT_CSD
    if (SD_SendEXTCSD_MMC40(MSDC_Sector) != NO_ERROR)
        goto err;;

#endif

    /*calculate size*/
    if (MMC42_CARD == gMSDC_Handle->mMSDC_type)
    {
        gSD->mCSD.capacity = (kal_uint64)gSD->mCSD.ext_csd->sec_count * 512;
    }

#if defined(MSDC_MMC441_SUPPORT)
    SD_IsEmmcV44();
#endif

    // set high speed
#ifndef MSDC_SPECIAL_MMC_41_CARD

    if (gSD->mCSD.ext_csd->card_type & HS_52M)
#endif
    {
        // should be 52000
        //clock = 52000;
        clock = gMSDC_Handle->msdc_clock / 2;

        if (52000 < clock)
            clock = clock / 2;

        hs = 1;
        //MSDC_LSD_WriteReg32(MSDC_IOCON,0x010002FF);

#ifndef DRV_MSDC_CLK_SEARCH
        MSDC_LSD_ClearBits32(MSDC_CFG, MSDC_CFG_CRED);;
#endif
    }

#ifndef MSDC_SPECIAL_MMC_41_CARD
    else if (gSD->mCSD.ext_csd->card_type & HS_26M)
    {
        // should be 26000
        clock = 26000;
        hs = 1;
    }
    else
    {
        clock = 13000;
        hs = 0;
    }

#endif

    if (hs)
    {
        //! [TODO]: eMMC
        /* select proper power class
        if(SD_Switch_MMC40(SET_BYTE,EXT_CSD_POW_CLASS_INDEX,
        	(gSD->mCSD.ext_csd->pwr_52_360&0xf) ,0) != NO_ERROR)
        	goto err;
        */


        //! move to SD_tuneCLK2()
        /* enable high speed (26M or 52M)
        if(SD_Switch_MMC40(SET_BYTE,EXT_CSD_HIGH_SPPED_INDEX,
        	EXT_CSD_ENABLE_HIGH_SPEED,0) != NO_ERROR)
        	goto err;
        */

        // latch data at falling edge to cover the card driving capability
        // MSDC_LSD_SetBits32(MSDC_CFG,MSDC_CFG_RED);
    }

#ifndef DRV_LSD

#ifndef DRV_MSDC_CLK_SEARCH
    gMSDC_Handle->msdc_clock = MSDC_CLOCK;
    MSDC_SetClock(clock);
#endif

#else
    LSD_HostSetClock(LSD_SPEED_52M);
#endif

#if defined(DRV_MSDC_MT6225_SERIES) && !defined(DRV_MSDC_CLK_SEARCH)
    /*change DLT and set cmd latch at rising edge*/
    //MSDC_LSD_WriteReg32(MSDC_IOCON,0x8036);
    MSDC_SetBits32(MSDC_IOCON, MSDC_IOCON_CMDRE);
    MSDC_SetIOCONRegDLT();
#endif

    if (KAL_FALSE == gMSDC_Handle->trySingleLine)
    {
        // select bus width
#if defined(MMC40_USE_4BIT_BUS)
        // enable 4-bit bus width
        if (SD_Switch_MMC40(SET_BYTE, EXT_CSD_BUS_WIDTH_INDEX, BIT_4_MMC40, 0) != NO_ERROR)
            goto err;

#ifdef MSDC_SPECIAL_MMC_41_CARD

        if (KAL_TRUE == kal_query_systemInit()
            || KAL_TRUE == FTL_isPollingMode()
           )
        {
            MSDC_GPTI_BusyWait(2);
        }
        else
        {
            kal_sleep_task(4);
        }

#endif
        MSDC_LSD_SetBits32(SDC_CFG, SDC_CFG_MDLEN);
        gSD->bus_width = 4;
#elif defined(MMC40_USE_8BIT_BUS)

        // enable 8-bit bus width
        if (SD_Switch_MMC40(SET_BYTE, EXT_CSD_BUS_WIDTH_INDEX, BIT_8_MMC40, 0) != NO_ERROR)
            goto err;

        MSDC_LSD_SetBits32(SDC_CFG, SDC_CFG_MDLEN);
        MSDC_LSD_SetBits32(SDC_CFG, SDC_CFG_MDLEN8); // works when MDLEN is enabled.
        gSD->bus_width = 8;
#endif
    }

#ifndef MSDC_SPECIAL_MMC_41_CARD

    if (SD_SendEXTCSD_MMC40(MSDC_Sector) != NO_ERROR)
        goto err;;

#endif

    return NO_ERROR;
err:
    return ERR_MMC_BUS_HS_ERROR;
}
/*************************************************************************
* FUNCTION
*  SD_CheckSDorMMC
*
* DESCRIPTION
*	Check inserted card is SD or MMC
*
* PARAMETERS
*
*
* RETURNS
*  SD_CARD or MMC_CARD
*
* GLOBALS AFFECTED
*	gMSDC_Handle
*
*************************************************************************/
T_MSDC_CARD SD_CheckSDorMMC()
{
    SDC_CMD_STATUS status;

#if defined(SD_MMC_HIGH_DENSITY_SUPPORT)
    SD_Cmd8();
#endif
    status = SD_Acmd41_SD();

    if (status == NO_ERROR)
        return gMSDC_Handle->mMSDC_type;	// SD_CARD

    status = SD_Cmd1_MMC();

    if (status == NO_ERROR)
        return gMSDC_Handle->mMSDC_type;	// MMC_CARD

    return UNKNOWN_CARD;
}
/*************************************************************************
* FUNCTION
*  SD_SetDefault
*
* DESCRIPTION
*	set default values to gSD
*
* PARAMETERS
*
*
* RETURNS
*
* GLOBALS AFFECTED
*	gSD
*
*************************************************************************/
void SD_SetDefault(void)
{
    MSDC_LOCK_TAG tempLock;
    kal_mem_cpy(&tempLock, &gSD->mSDdrv_lock, sizeof(MSDC_LOCK_TAG));

    kal_mem_set(gSD, 0, sizeof(T_SDC_HANDLE));

    gSD->mBKLength = 512;
    gSD->mRCA = 0;
    gSD->mInactive = KAL_FALSE;
    gSD->mState = IDLE_STA;
    gSD->bus_width = 1;
    gSD->mCD_DAT3 = KAL_TRUE;

    kal_mem_cpy(&gSD->mSDdrv_lock, &tempLock, sizeof(MSDC_LOCK_TAG));
}

void SD_Use24M_Clock(void)
{
#ifndef DRV_LSD

    if (gMSDC_Handle->mMSDC_type == SD_CARD || gMSDC_Handle->mMSDC_type == SD20_LCS_CARD
        || gMSDC_Handle->mMSDC_type == SD20_HCS_CARD)
    {
#ifndef MSDC_2ND_CLK_MCPLL
#if defined(__UBL__) || defined(__FUE__)
        USBDL_CLK_ON(KAL_TRUE);
#else//defined(__UBL__) || defined(__FUE__)
        UPLL_Enable(UPLL_OWNER_MSDC);
#endif//defined(__UBL__) || defined(__FUE__)
#else
        MSDC_MCPLLEnable(MCPLL_MSDC1);
#endif
        MSDC_SetClockSource(MSDC_CLOCK_MCPLL);
        gMSDC_Handle->msdc_clock = MSDC_CLOCK_USB;
        MSDC_SetClock(MSDC_SD_OP_CLOCK);
        gSD->flags |= SD_FLAG_USE_USB_CLK;
    }

#else
    LSD_HostSetClock(LSD_SPEED_52M);
#endif
}

void SD_Use13M_Clock(void)
{
#ifndef DRV_LSD
    MSDC_SetClockSource(MSDC_CLOCK_MCU);
    gMSDC_Handle->msdc_clock = MSDC_CLOCK;
    MSDC_SetClock(MSDC_OP_CLOCK);
    gSD->flags &= ~SD_FLAG_USE_USB_CLK;
#else
    LSD_HostSetClock(LSD_SPEED_52M);
#endif
}

#ifdef	DRV_MSDC_CLK_MT6268_SERIES
void SD_Use30M_Clock(void)
{
    MSDC_SetClockSource(MSDC_CLOCK_MCU);
    gMSDC_Handle->msdc_clock = MSDC_CLOCK;
    MSDC_SetClock(MSDC_30M);
    gSD->flags &= ~SD_FLAG_USE_USB_CLK;
}

void SD_Use45M_Clock(void)
{
    MSDC_SetClockSource(MSDC_CLOCK_MCPLL);
    gMSDC_Handle->msdc_clock = MSDC_CLOCK_USB;
    MSDC_SetClock(MSDC_45M);
    gSD->flags |= SD_FLAG_USE_USB_CLK;
}
#endif

#ifdef DRV_MSDC_CLK_SEARCH

kal_uint32 whenToStop;
kal_uint32 stopTimeout = 300;

#if !defined(DRV_MSDC_LATCH_MT6276_SERIES)

void SD_SetRedDlt(kal_uint32 redDlt)
{
    kal_uint32 testingRED = 0, testingDLT = 0;

    testingRED = redDlt >> 16;
    testingDLT = redDlt & 0x0000FFFF;
    BitFieldWrite32((kal_uint32*)MSDC_CFG, (kal_uint32)testingRED, MSDC_CFG_CRED);
    BitFieldWrite32((kal_uint32*)MSDC_IOCON, testingDLT, MSDC_IOCON_DLT);
}
#endif//#if !defined(DRV_MSDC_LATCH_MT6276_SERIES)

kal_bool sd_DltTestWithClkStopped(kal_uint32 data_adrs)
{

    SDC_CMD_STATUS status1;
    kal_uint32 bufIndex, loopIndex;
    kal_uint32 timeoutIndex;
    kal_uint8 *bufPtr;
    kal_bool status;


    bufPtr = (kal_uint8 *)MSDC_Sector;

    if ((512 - 44) < whenToStop)
        ASSERT(0);

    //if(NO_ERROR != status1)
    //ASSERT(0);
    kal_mem_set(bufPtr, 0, 512);

#if defined(MSDC_MMC40_SUPPORT)

    if ((gMSDC_Handle->mMSDC_type == MMC_CARD || gMSDC_Handle->mMSDC_type == MMC42_CARD) && gSD->mCSD.spec_ver >= 4)
    {
        if ((status1 = SD_SendEXTCSD_MMC40(MSDC_Sector)) != NO_ERROR)
            return KAL_FALSE;
    }
    else
#endif
    {
        if ((status1 = SD_Send_Cmd(SDC_CMD_CMD17, data_adrs)) != NO_ERROR)
            return KAL_FALSE;
    }

    if ((status1 = SD_CheckStatus()) != NO_ERROR)
        return KAL_FALSE;

    bufIndex = 0;
    loopIndex = 0;

    /*move data from FIFO to buffer*/
    while (((bufIndex * 4) < 512) && (loopIndex < 50000))
    {
        if (MSDC_Reg(MSDC_STA) & MSDC_STA_FIFOCNT)
        {
            MSDC_Sector[bufIndex] = MSDC_Reg32(MSDC_DAT);
            bufIndex ++;

            /*the most impormant in this function, to make a delay to trigger crc error*/
            if ((bufIndex * 4 + 44) > whenToStop)
            {
                timeoutIndex = 0;

                while (timeoutIndex < stopTimeout)
                    timeoutIndex ++;
            }
        }

        loopIndex++;
    }

    if (MSDC_Reg(SDC_DATSTA) & SDC_DATSTA_DATCRCERR)
        status = KAL_FALSE;
    else
        status = KAL_TRUE;

    RESET_MSDC();

    /*write FIFOCLR to reset FIFO index*/
    MSDC_CLR_FIFO();

    return status;
}

#if !defined(DRV_MSDC_LATCH_MT6276_SERIES)

kal_bool SD_setCLKAndTest(kal_uint32 targetCLK)
{
    kal_uint32 testingCLK;
    kal_uint8	testingRED, testingDLT;
    kal_uint8	maxDLT;
    kal_bool half_DLT_tested = KAL_FALSE;
    SDC_CMD_STATUS status;
    kal_uint32 resp[2];
    kal_uint32 loopIndex;

    testingCLK = targetCLK;

    if (MSDC_CLOCK == gMSDC_Handle->msdc_clock) /*use first CLK source*/
    {
#ifndef MSDC_2ND_CLK_MCPLL
#if !defined(__UBL__) && !defined(__FUE__)
        UPLL_Disable(UPLL_OWNER_MSDC);
#endif//!defined(__UBL__) && !defined(__FUE__)
#else
        MSDC_MCPLLDisable(MCPLL_MSDC1);
#endif
        MSDC_SetClockSource(MSDC_CLOCK_MCU);
        gMSDC_Handle->msdc_clock = MSDC_CLOCK;
        gSD->flags &= ~SD_FLAG_USE_USB_CLK;
    }
    else /*use 2nd CLK source*/
    {
#ifndef MSDC_2ND_CLK_MCPLL
#if defined(__UBL__) || defined(__FUE__)
        USBDL_CLK_ON(KAL_TRUE);
#else//defined(__UBL__) || defined(__FUE__)
        UPLL_Enable(UPLL_OWNER_MSDC);
#endif//defined(__UBL__) || defined(__FUE__)
#else
        MSDC_MCPLLEnable(MCPLL_MSDC1);
#endif
        MSDC_SetClockSource(MSDC_CLOCK_MCPLL);
        gMSDC_Handle->msdc_clock = MSDC_CLOCK_USB;
        gSD->flags |= SD_FLAG_USE_USB_CLK;
    }

    MSDC_SetClock(testingCLK);


    BitFieldWrite32((kal_uint32*)MSDC_IOCON, 0, MSDC_IOCON_CMDRE);
    status = SD_GetStatus(gSD->mRCA, resp);

    if (NO_ERROR != status)
    {
        BitFieldWrite32((kal_uint32*)MSDC_IOCON, 1, MSDC_IOCON_CMDRE);
        status = SD_GetStatus(gSD->mRCA, resp);

        if (NO_ERROR != status)
        {
            return KAL_FALSE;
        }
    }

#ifdef DRV_MSDC_2_DLT_FOR_RD_WR
    gMSDC_Handle->msdc_clkTuneTriedRd = 0;
#endif
    testingRED = 0;

    while (2 != testingRED)
    {
        if (1 < testingRED)
            ASSERT(0);

        BitFieldWrite32((kal_uint32*)MSDC_CFG, (kal_uint32)testingRED, MSDC_CFG_CRED);
        maxDLT = gMSDC_Handle->msdc_clock / gMSDC_Handle->op_clock;
        testingDLT = maxDLT / 2;
        half_DLT_tested = KAL_FALSE;

        while (KAL_TRUE != half_DLT_tested || (testingDLT * 2) != maxDLT) /*break when KAL_TRUE == half_DLT_tested && (testingDLT*2) == maxDLT*/
        {
            if (0 == testingDLT)
            {
                ASSERT(0);
            }

#ifdef DRV_MSDC_2_DLT_FOR_RD_WR
            /*we record tried DLT here, no matter DLT pass or fail in this test is recorded*/
            gMSDC_Handle->msdc_clkTuneTriedRd |= (1 << (16 * testingRED + (testingDLT - 1)));
            gMSDC_Handle->msdc_RedDlt_forRd =  (testingRED << 16) + testingDLT;
#endif

            if ((testingDLT * 2) == maxDLT)
            {
                half_DLT_tested = KAL_TRUE;
            }

            BitFieldWrite32((kal_uint32*)MSDC_IOCON, testingDLT, MSDC_IOCON_DLT);

            if (gSD->flags & SD_FLAG_SD_TYPE_CARD)
                status = SD_ReadSCR(resp);

#if defined(MSDC_MMC40_SUPPORT)
            else
                status = SD_SendEXTCSD_MMC40(MSDC_Sector);

#endif

            if (NO_ERROR == status)
            {
#ifdef __MSDC_BASIC_LOAD__
                dbg_print("\n\rtesting (%d, %x) for speed:%d", testingRED, testingDLT, targetCLK);
#endif

#if defined(MSDC_TRACE_LEVEL3)
                MSDC_add_dbg_msg(msdc_dbg_event_SD_clk_tuning, MSDC_Reg32(MSDC_CFG), MSDC_Reg32(MSDC_IOCON));
#endif
                status = SD_SetBlength(512);

                if (NO_ERROR == status)
                {
                    for (loopIndex = 6; NO_ERROR == status && 0 < loopIndex; loopIndex--)
                    {
                        if (gSD->flags & SD_FLAG_HCS_SUPPORT)
                            status = SD_ReadSingleBlock(loopIndex, MSDC_Sector);
                        else
                            status = SD_ReadSingleBlock(loopIndex * 512, MSDC_Sector);
                    }

                    if (NO_ERROR == status && 0 == loopIndex)
                    {
                        /*multiple block read pass, we now do clk stop test*/
                        if (sd_DltTestWithClkStopped(0))
                        {
#ifdef __MSDC_BASIC_LOAD__
                            dbg_print(" pass\n\r");
#endif
                            return KAL_TRUE;
                        }

                    }
                    else
                    {
#ifdef __MSDC_BASIC_LOAD__
                        dbg_print(" fail:%d", status);
#endif
                    }

                    status = NO_ERROR;
                }
            }

            testingDLT++;

            if (testingDLT > maxDLT)
                testingDLT = 1;
        }

        testingRED ++;
    }

    return KAL_FALSE;
}


kal_uint32 SD_tuneCLK2()
{
    kal_uint32 maxSpeed;
    kal_uint32 testing1stClk, testing2ndClk, testingClk;
    kal_uint32 testTimes;
    kal_uint8 *pData;

    testing1stClk = MSDC_CLOCK / 2;
    testing2ndClk = MSDC_CLOCK_USB / 2;

    maxSpeed = 25000;

    if (gSD->flags & SD_FLAG_SD_TYPE_CARD)
    {
        if (gSD->flags & SD_FLAG_HS_SUPPORT)
        {
            //maxSpeed = 50000 + 20000;
            maxSpeed = 50000;
        }
        else if (gSD->flags & SD_FLAG_LIMITED_HIGH_SPEED_CARD)
        {
            maxSpeed = 26000;
        }
    }
    else
    {
        if (gSD->mCSD.ext_csd->card_type & HS_52M)
        {
            maxSpeed = 52000;
        }
        else if (gSD->mCSD.ext_csd->card_type & HS_26M)
        {
            maxSpeed = 26000;
        }

    }

#ifdef DRV_MSDC_CLK_MT6253_SERIES

    /*for ESD stability*/
    if (0x2 == (MSDC_Reg(0x83010890) & 0x8002))
    {
		tst_sys_trace("[MSDC]:debug mode");

        if (25000 < gMSDC_Handle->msdc_clkTuneUpperBund)
            gMSDC_Handle->msdc_clkTuneUpperBund = gMSDC_Handle->msdc_clkTuneUpperBund / 2;
    }

#endif

    if (maxSpeed > gMSDC_Handle->msdc_clkTuneUpperBund)
        maxSpeed = gMSDC_Handle->msdc_clkTuneUpperBund;

    testTimes = 0;

    while (20 > testTimes)
    {
        if (testing1stClk > testing2ndClk) /*we process first CLK source*/
        {
            testingClk = testing1stClk;
            gMSDC_Handle->msdc_clock = MSDC_CLOCK;
            testing1stClk = (testing1stClk / 2);

        }
        else /*we process second CLK source*/
        {
            testingClk = testing2ndClk;
            gMSDC_Handle->msdc_clock = MSDC_CLOCK_USB;
            testing2ndClk = (testing2ndClk / 2);
#ifdef DRV_MSDC_NOT_USE_2ND_CLK
            /*we don't use second clk source*/
            continue;
#endif
        }

        if (testingClk <= maxSpeed ) /*we have the testing upper bound that we only test clk slow than this*/
        {
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

            if (SD_setCLKAndTest(testingClk))
            {
                //gMSDC_Handle->msdc_clkTuneUpperBund = testingClk;
                return testingClk;
            }
        }

        /*current testing clk failed*/
        if (6000 > testing1stClk && 6000 > testing2ndClk)
            return 0;

        testTimes ++;
    }

    /*we didn't find a suitable clk and didn't return false in while loop, a strange status*/
    ASSERT(0);
    /*add a return to fix build warning*/
    return 0;
}

#else//!defined(DRV_MSDC_LATCH_MT6276_SERIES)

kal_bool SD_IsClkInRange(kal_uint32 clk)
{
    kal_uint32 maxSpeed;

    maxSpeed = 25000;

    if (gSD->flags & SD_FLAG_SD_TYPE_CARD)
    {
        if (gSD->flags & SD_FLAG_HS_SUPPORT)
        {
            //maxSpeed = 50000 + 20000;
            maxSpeed = 50000;
        }
        else if (gSD->flags & SD_FLAG_LIMITED_HIGH_SPEED_CARD)
        {
            maxSpeed = 26000;
        }
    }
    else
    {
        if (gSD->mCSD.ext_csd->card_type & HS_52M)
        {
            maxSpeed = 52000;
        }
        else if (gSD->mCSD.ext_csd->card_type & HS_26M)
        {
            maxSpeed = 26000;
        }
    }

    if (maxSpeed > gMSDC_Handle->msdc_clkTuneUpperBund)
        maxSpeed = gMSDC_Handle->msdc_clkTuneUpperBund;

    if (clk <= maxSpeed)
    {
        return KAL_TRUE;
    }

    return KAL_FALSE;
}

kal_bool SD_CanCmdBeLatched(void)
{
    SDC_CMD_STATUS status = NO_ERROR;
    kal_uint32 resp[2];

    status = SD_GetStatus(gSD->mRCA, resp);

    if (NO_ERROR == status)
    {
#ifdef __MSDC_BASIC_LOAD__
        dbg_print(" pass\n\r");
#endif
        return KAL_TRUE;
    }

#ifdef __MSDC_BASIC_LOAD__
    dbg_print(" fail:%d", status);
#endif
    return KAL_FALSE;
}

kal_bool SD_CanDataBeLatched(msdc_clk_setting cs)
{
    SDC_CMD_STATUS status = NO_ERROR;
    kal_uint32 resp[2];
    kal_uint32 loopIndex;

    if (gSD->flags & SD_FLAG_SD_TYPE_CARD)
        status = SD_ReadSCR(resp);

    if (NO_ERROR != status)
    {
        return KAL_FALSE;
    }

#ifdef __MSDC_BASIC_LOAD__
    dbg_print("\n\rtesting (%d, %d) for speed: %d", cs.clksrc, cs.sclkf, cs.cardClk);
#endif

#ifdef MSDC_TRACE_LEVEL3
    MSDC_add_dbg_msg(msdc_dbg_event_SD_clk_tuning, MSDC_Reg32(MSDC_CFG), MSDC_Reg32(MSDC_CLKACB_CFG));
#endif
    status = SD_SetBlength(512);

    if (NO_ERROR != status)
    {
        return KAL_FALSE;
    }

    for (loopIndex = 6; NO_ERROR == status && 0 < loopIndex; loopIndex--)
    {
        if (gSD->flags & SD_FLAG_HCS_SUPPORT)
            status = SD_ReadSingleBlock(loopIndex, MSDC_Sector);
        else
            status = SD_ReadSingleBlock(loopIndex * 512, MSDC_Sector);
    }

    if (NO_ERROR == status && 0 == loopIndex)
    {
        /*multiple block read pass, we now do clk stop test*/
        if (sd_DltTestWithClkStopped(0))
        {
#ifdef __MSDC_BASIC_LOAD__
            dbg_print(" pass\n\r");
#endif
            return KAL_TRUE;
        }
    }

#ifdef __MSDC_BASIC_LOAD__
    dbg_print(" fail:%d", status);
#endif
    return KAL_FALSE;
}

SDC_CMD_STATUS MSDC_AutoCalibrate(
    msdc_acb_mode		mode,
    msdc_acb_scan_mode	scanMode,
    msdc_acb_tun_scheme	tunScheme,
    kal_uint8			tunBlockNum
)
{
    kal_uint32 clkacb_cfg = 0, clkacb_sta = 0;
//    SDC_CMD_STATUS status = NO_ERROR;
    kal_uint32 t1;
//    kal_uint8 times = 0;

    clkacb_cfg |= MSDC_CLKACB_CFG_CLK_LATCH; // multiple phase clock

    switch (mode)
    {
        case MSDC_AM_CMD:
            clkacb_cfg &= ~MSDC_CLKACB_CFG_ACB_MODE;
            MSDC_WriteReg32(SDC_ARG, (kal_uint32)gSD->mRCA << 16); // CMD13 arg: RCA
            break;

        case MSDC_AM_DAT:
            clkacb_cfg |= MSDC_CLKACB_CFG_ACB_MODE;
            MSDC_WriteReg32(SDC_ARG, 0);	// MSDC CMD18 will start from address 0
            break;

        default:
            ASSERT(0);
            return ERR_ACB_FAIL;
    }

    switch (scanMode)
    {
        case MSDC_ASM_DET:
            clkacb_cfg &= ~MSDC_CLKACB_CFG_SCANMODE;
            break;

        case MSDC_ASM_FULL:
            clkacb_cfg |= MSDC_CLKACB_CFG_SCANMODE;
            break;

        default:
            ASSERT(0);
            return ERR_ACB_FAIL;
    }

    switch (tunScheme)
    {
        case MSDC_ATS_DETECT:
            clkacb_cfg &= ~(MSDC_CLKACB_CFG_COARSE_EN | MSDC_CLKACB_CFG_FINE_EN);
            ASSERT(0);
            break;

        case MSDC_ATS_COARSE:
            clkacb_cfg |= MSDC_CLKACB_CFG_COARSE_EN;
            break;

        case MSDC_ATS_FINE:
            clkacb_cfg |= MSDC_CLKACB_CFG_FINE_EN;
            break;

        default:
            ASSERT(0);
            return ERR_ACB_FAIL;
    }

    if (tunBlockNum > 0xff)
    {
        ASSERT(0);
    }
    else
    {
        clkacb_cfg |= (tunBlockNum << 16) & MSDC_CLKACB_CFG_TUN_BLOCK_NUM;
    }

    clkacb_cfg |= MSDC_CLKACB_CFG_CLKTUN_ON;

    //read out data sta to make sure we will read latest one in the future
    gMSDC_Handle->cmd_sta = *(volatile kal_uint16*)SDC_CMDSTA;
    gMSDC_Handle->dat_sta = *(volatile kal_uint16*)SDC_DATSTA;

    MSDC_SetBits32(MSDC_CLKACB_CFG, clkacb_cfg | MSDC_CLKACB_CFG_CLKTUN_ON); // start tuning

    t1 = drv_get_current_time();
    MSDC_START_TIMER(MSDC_TIMEOUT_PERIOD_ACB);

    // MSDC_CLKACB_STA_CLKTUN_DONE will be triggered even when MSDC_CLKACB_STA_ACB_TO was triggered
    while ((0 == ((clkacb_sta = MSDC_Reg32(MSDC_CLKACB_STA)) & MSDC_CLKACB_STA_CLKTUN_DONE)) &&
           MSDC_Check_Card_Present() &&
           !gMSDC_Handle->is_timeout
          )
    {
        // should be finished within 15s [jocelyn's comment @ FPGA]
        if (drv_get_duration_ms(t1) > MSDC_TIMEOUT_PERIOD_ACB * 11)
            gMSDC_Handle->is_timeout = KAL_TRUE;
    }

    MSDC_STOP_TIMER();

    //read out data sta to make sure we will read latest one in the future
    gMSDC_Handle->cmd_sta = *(volatile kal_uint16*)SDC_CMDSTA;
    gMSDC_Handle->dat_sta = *(volatile kal_uint16*)SDC_DATSTA;

    if (gMSDC_Handle->is_timeout)
    {
		tst_sys_trace("[MSDC] ACB timeout (GPT)\n\r");
        ASSERT(0);
        return MSDC_GPT_TIMEOUT_ERR;
    }

    if (clkacb_sta & MSDC_CLKACB_STA_ACB_TO)
    {
		tst_sys_trace("[MSDC] ACB timeout\n\r");
        ASSERT(0);
        return ERR_ACB_TIMEOUT;
    }

    return NO_ERROR;
}

kal_uint32 MSDC_ManuCalibrate(
    msdc_clk_setting	cs,
    msdc_acb_mode 		mode
)
{
    kal_uint8 i, j;
    kal_uint32 phaseArraySeamless = 0;

    // command manual-calibrate
    for (i = 0; i < (1 << (cs.sclkf + 1)); i ++)
    {
        for (j = 0; j < DIV_CLKSRC(cs.clksrc); j ++)
        {
            switch (mode)
            {
                case MSDC_AM_CMD:
                    MSDC_SetData32(MSDC_CLKACB_CFG, MSDC_CLKACB_CFG_CMD_PHASE, (i << 27) | (j << 24));

                    if (KAL_TRUE == SD_CanCmdBeLatched())
                        phaseArraySeamless |= 1 << (j + i * DIV_CLKSRC(cs.clksrc));

                    break;

                case MSDC_AM_DAT:
                    MSDC_SetData32(MSDC_CLKACB_CFG, MSDC_CLKACB_CFG_DAT_PHASE, (i << 11) | (j << 8));

                    if (KAL_TRUE == SD_CanDataBeLatched(cs))
                        phaseArraySeamless |= 1 << (j + i * DIV_CLKSRC(cs.clksrc));

                    break;

                default:
                    ASSERT(0);
                    break;
            }
        }
    }

    return phaseArraySeamless;
}

#define MAX_NUM_MULTI_PHASE	32
SDC_CMD_STATUS FindMostConsecutiveBits(
    kal_uint32 word,
    kal_uint8 wordLen,
    kal_uint8 threshold,
    kal_uint8 *pos
)
{
    kal_uint8 confidenceCnt[MAX_NUM_MULTI_PHASE];
    //kal_uint32 mask = 0;
    kal_int8 i = 0, j = 0;
    kal_uint8 pos_of_largest = 0, test_pos = 0;
//    kal_uint8 len_of_MostConsecutiveBits = 0;

    kal_mem_set(confidenceCnt, 0, MAX_NUM_MULTI_PHASE * sizeof(kal_uint8));

    for (i = 0; i < wordLen; i ++)
    {
        if (0 == ((1 << i) & word))
            continue;	// bit i is '0', then skip

        confidenceCnt[i] = 1;

        for (j = 1; j < wordLen; j ++)
        {
            test_pos = ((i + j) < wordLen) ? (i + j) : (i + j - wordLen);

            if (0 == ((1 << test_pos) & word))
                break;
            else
                confidenceCnt[i]++;	// bit (i+j) is '1', then benefit to bit i
        }

        if (confidenceCnt[i] > confidenceCnt[pos_of_largest])
            pos_of_largest = i;

        i += confidenceCnt[i] - 1;	// skip following continuous '1' for speedup
    }

//    len_of_MostConsecutiveBits = (confidenceCnt[pos_of_largest] + threshold - 1);

    // find nothing!
    if (confidenceCnt[pos_of_largest] < threshold)
        return ERR_NOT_FOUND;

    // choose the middle of the most consecutive bits
    *pos = pos_of_largest + (confidenceCnt[pos_of_largest] / 2);

    if (*pos >= wordLen)	// rounding
        *pos -= wordLen;

    return NO_ERROR;
}

SDC_CMD_STATUS MSDC_AutoCalibrate_FindBestLatchWindow(
    msdc_acb_scan_mode scanMode,
    kal_uint8 *pos
)
{
    // TODO: MSDC_ASM_DET

    // MSDC_ASM_FULL
    kal_uint32 crcsta = 0;
    kal_uint32 crcWord = 0;
    SDC_CMD_STATUS status = NO_ERROR;

    crcsta = MSDC_Reg32(MSDC_CLKACB_CRCSTA1);

    // confirm enable bit number in CRCSTA is FULL mode
    if (MSDC_CLKACB_CRC_STA_ENABLE != (crcsta & MSDC_CLKACB_CRC_STA_ENABLE))
    {
        ASSERT(0);
        return ERR_ACB_STA_ENABLE_FAIL;
    }

    // 2's compliment of the CRC 16-bits: 1 => OKAY bit
    crcWord = (kal_uint16)((~crcsta) & MSDC_CLKACB_CRC_STA_CRC);
    status = FindMostConsecutiveBits(crcWord, 16, 3, pos);

    return status;
}

SDC_CMD_STATUS MSDC_ManuCali_FindBestLatchWindow(
    msdc_clk_setting cs,
    kal_uint32 phaseArraySeamless,
    kal_uint8 *pos
)
{
    SDC_CMD_STATUS status = NO_ERROR;
    kal_uint8 posSeamless = 0, sclkf = 0, clksrc = 0;

    status = FindMostConsecutiveBits(
                 phaseArraySeamless,
                 DIV_SCLKF(cs.sclkf) * DIV_CLKSRC(cs.clksrc),
                 3,
                 &posSeamless
             );

    if (NO_ERROR != status)
        return ERR_NOT_FOUND;

    sclkf = posSeamless / DIV_CLKSRC(cs.clksrc);
    clksrc = posSeamless - sclkf * DIV_CLKSRC(cs.clksrc);
    *pos = sclkf << 3 | clksrc;

    return NO_ERROR;
}

kal_uint32 SD_ClkTuning_AutoCalibrate(msdc_clk_setting cs)
{
//    kal_uint32 clkacb_cfg = 0, clkacb_sta = 0;
    SDC_CMD_STATUS status = NO_ERROR;
    kal_uint8 pos = 0;

    // 1. command auto-calibrate
    status = MSDC_AutoCalibrate(MSDC_AM_CMD, MSDC_ASM_FULL, MSDC_ATS_COARSE, 10);

    if (NO_ERROR == status)
    {
        status = MSDC_AutoCalibrate_FindBestLatchWindow(MSDC_ASM_FULL, &pos);

        if (NO_ERROR == status)
        {
            // found CMD latch, and then fill it into CMD_PHASE
            MSDC_SetData32(MSDC_CLKACB_CFG, MSDC_CLKACB_CFG_CMD_PHASE, ((kal_uint32)pos) << 24);
        }
        else
        {
            // TODO: not found CMD latch in coarse-tune, try fine-tune
        }
    }
    else
        return status;

    // 2. data auto-calibrate
    status = MSDC_AutoCalibrate(MSDC_AM_DAT, MSDC_ASM_FULL, MSDC_ATS_COARSE, 10);

    if (NO_ERROR == status)
    {
        status = MSDC_AutoCalibrate_FindBestLatchWindow(MSDC_ASM_FULL, &pos);

        if (NO_ERROR == status)
        {
            // found CMD latch, and then fill it into CMD_PHASE
            MSDC_SetData32(MSDC_CLKACB_CFG, MSDC_CLKACB_CFG_DAT_PHASE, ((kal_uint32)pos) << 8);
        }
        else
        {
            // TODO: not found CMD latch in coarse-tune, try fine-tune
        }
    }
    else
        return status;

    return NO_ERROR;
}

kal_uint32 SD_ClkTuning_ManualCalibrate(msdc_clk_setting cs)
{
    SDC_CMD_STATUS status = NO_ERROR;
    kal_uint8 pos = 0;
    kal_uint32 phaseArraySeamless = 0;

    MSDC_SetBits32(MSDC_CLKACB_CFG, MSDC_CLKACB_CFG_CLK_LATCH); // multiple phase clock

    // 1. command manual-calibrate
    phaseArraySeamless = MSDC_ManuCalibrate(cs, MSDC_AM_CMD);
    status = MSDC_ManuCali_FindBestLatchWindow(cs, phaseArraySeamless, &pos);

    if (NO_ERROR == status)
    {
        // found CMD latch, and then fill it into CMD_PHASE
        MSDC_SetData32(MSDC_CLKACB_CFG, MSDC_CLKACB_CFG_CMD_PHASE, ((kal_uint32)pos) << 24);
    }
    else
        return status;

    // 2. data manual-calibrate
    phaseArraySeamless = MSDC_ManuCalibrate(cs, MSDC_AM_DAT);
    status = MSDC_ManuCali_FindBestLatchWindow(cs, phaseArraySeamless, &pos);

    if (NO_ERROR == status)
    {
        // found CMD latch, and then fill it into DAT_PHASE
        MSDC_SetData32(MSDC_CLKACB_CFG, MSDC_CLKACB_CFG_DAT_PHASE, ((kal_uint32)pos) << 8);
    }
    else
        return status;

    return NO_ERROR;
}

kal_uint32 SD_ClkTuning_FeedbackClk(msdc_clk_setting cs)
{
    kal_int32 i = 0;

    MSDC_ClearBits32(MSDC_CLKACB_CFG, MSDC_CLKACB_CFG_CLK_LATCH); // feedback clock

    for (i = 0; i < 2; i ++)
    {
        if (i == 0)
        {
            //exchange this temporarily.
            //MSDC_SetBits32(MSDC_CLKACB_CFG, MSDC_CLKACB_CFG_CLKPAD_RED);
            MSDC_ClearBits32(MSDC_CLKACB_CFG, MSDC_CLKACB_CFG_CLKPAD_RED);

        }
        else
        {
            //MSDC_ClearBits32(MSDC_CLKACB_CFG, MSDC_CLKACB_CFG_CLKPAD_RED);
            MSDC_SetBits32(MSDC_CLKACB_CFG, MSDC_CLKACB_CFG_CLKPAD_RED);
        }

        // check errors (e.g. CRC) with this configuration
        if (KAL_FALSE == SD_CanCmdBeLatched())
            continue;

        if (KAL_TRUE == SD_CanDataBeLatched(cs))
            return NO_ERROR;
    }

    return ERR_NOT_FOUND;
}

kal_uint32 SD_tuneCLK2()
{
    msdc_clk_setting cs;

    for (cs.sclkf = 0; cs.sclkf < MSDC_SCLKF_NUM; cs.sclkf ++)
    {
        // criteria : clock should > 12.5MHz	// TODO: [Samuel]
        //if (cs.sclkf >= 2)
        //	ASSERT(0);

        for (cs.clksrc = 0; cs.clksrc < MSDC_CLKSRC_NUM; cs.clksrc ++)
        {
            cs.cardClk = gMsdcClksrcRate[cs.clksrc] / DIV_SCLKF(cs.sclkf);

            if (SD_IsClkInRange(cs.cardClk) && gMSDC_Handle->mIsPresent)
            {
                // configure MSDC_CFG
                MSDC_SetData32(MSDC_CFG, MSDC_CFG_CLKSRC, cs.clksrc << 3);
                MSDC_SetData32(MSDC_CFG, MSDC_CFG_SCLKF, cs.sclkf << 8);

                if (cs.cardClk >= 25000) // 25MHz
                {
                    if (gMSDC_Handle->tuningTopology.HighSpeed)
                    {
                        if (NO_ERROR == gMSDC_Handle->tuningTopology.HighSpeed(cs))
                            return cs.cardClk;
                    }
                }
                else
                {
                    if (gMSDC_Handle->tuningTopology.NormalSpeed1)
                    {
                        if (NO_ERROR == gMSDC_Handle->tuningTopology.NormalSpeed1(cs))
                            return cs.cardClk;
                    }

                    if (gMSDC_Handle->tuningTopology.NormalSpeed2)
                    {
                        if (NO_ERROR == gMSDC_Handle->tuningTopology.NormalSpeed2(cs))
                            return cs.cardClk;
                    }
                }
            }
        }
    }

    return 0;
}

#endif//!defined(DRV_MSDC_LATCH_MT6276_SERIES)

#endif//#ifdef DRV_MSDC_CLK_SEARCH

#ifdef __MEUT__
kal_bool	msdcOddNumberSizeTestByDMA;
kal_bool	msdcDoNotRST;
SDC_CMD_STATUS msdcReadTest(kal_uint32 size, kal_uint8 *compareBuffer, kal_uint32 data_adrs)
{

    SDC_CMD_STATUS status1;
    kal_uint32	bufIndex, loopIndex;
    kal_uint8		*bufPtr;
    //kal_uint32    taskID;
    static kal_char u4PrintBuff[20];
    kal_bool onceLoop = 0;
    //int i;
	tst_sys_trace("------------Entering msdcReadTest----------");

    if (size > MSDC_TESTBUFFER_SIZE)
        ASSERT(0);

    bufPtr = (kal_uint8 *)msdc_testBuffer;
    status1 = SD_SetBlength(size);

    if (NO_ERROR != status1)
    {
        sprintf (u4PrintBuff, "SD_SetBlength status1!!%d", status1);
        tst_sys_trace(u4PrintBuff);
        ASSERT(0);
    }

    kal_mem_set(bufPtr, 0, MSDC_TESTBUFFER_SIZE);
    sendCmdTimes = 1;

    if ((status1 = SD_Send_Cmd(SDC_CMD_CMD17, data_adrs)) != NO_ERROR)
    {
        sprintf (u4PrintBuff, "SD_Send_Cmd status1!!%d", status1);
        tst_sys_trace(u4PrintBuff);
        ASSERT(0);

    }

    //SD_Send_Cmd(SDC_CMD_CMD17,data_adrs);
    if ((status1 = SD_CheckStatus()) != NO_ERROR)
    {
        sprintf (u4PrintBuff, "SD_CheckStatus status1!!%d", status1);
        tst_sys_trace(u4PrintBuff);
        ASSERT(0);
    }

    // SD_CheckStatus();
    //kal_get_my_task_index(&taskID);

    bufIndex = 0;
    loopIndex = 0;
    tst_sys_trace("------------Entering loop----------");
    sprintf (u4PrintBuff, "msdc_ReadTestFlag flag!!%d", msdc_ReadTestFlag);
    tst_sys_trace(u4PrintBuff);

    /*move data from FIFO to buffer*/
    while (((bufIndex * 4) <= size) && (loopIndex < 50000))
    {

        if (MSDC_Reg(MSDC_STA)&MSDC_STA_FIFOCNT)
        {
            msdc_testBuffer[bufIndex] = MSDC_Reg32(MSDC_DAT);
            bufIndex ++;
        }

        if ((msdc_ReadTestFlag & 0x2) && (onceLoop == 0))
        {
            ASSERT(NULL != msdc_TestCallBack2);
            msdc_TestCallBack2();
            onceLoop = 1;
        }

        loopIndex++;
    }

    if (msdc_ReadTestFlag & 0x4)
    {
        ASSERT(NULL != msdc_TestCallBack3);
        msdc_TestCallBack3();
    }

    // for (i =0;i<300;i++);
    if ((status1 = SD_WaitDatRdyOrTo()) != NO_ERROR)
    {
        ASSERT(0);
    }	/*compare*/

    bufIndex = 0;

    for (bufIndex = 0; bufIndex < size; bufIndex++)
    {
        if (*(bufPtr + bufIndex) != *(compareBuffer + bufIndex))
            ASSERT(0);
    }

    if (KAL_FALSE == msdcDoNotRST)
    {
        MSDC_LSD_SetBits32(MSDC_CFG, MSDC_CFG_RST);
        bufIndex = 5000;

        while (bufIndex--);

        MSDC_LSD_SetBits32(MSDC_CFG, MSDC_CFG_RST);
        bufIndex = 50000;

        while (bufIndex--);
    }

    /*write FIFOCLR to reset FIFO index*/
    MSDC_WriteReg(MSDC_STA, MSDC_STA_FIFOCLR);

    return status1;
}

#endif


#ifdef __MSDC_BASIC_LOAD__

kal_bool	msdcOddNumberSizeTestByDMA;
kal_bool	msdcDoNotRST;
SDC_CMD_STATUS msdcTransferLengthTest(kal_uint32 size, kal_uint8 *compareBuffer, kal_uint32 data_adrs)
{

    SDC_CMD_STATUS status1;
    kal_uint32	bufIndex, loopIndex;
    kal_uint8		*bufPtr;


    if (size > MSDC_TESTBUFFER_SIZE)
        ASSERT(0);

    bufPtr = (kal_uint8 *)msdc_testBuffer;
    status1 = SD_SetBlength(size);

    if (NO_ERROR != status1)
        ASSERT(0);

    kal_mem_set(bufPtr, 0, MSDC_TESTBUFFER_SIZE);

    if ((status1 = SD_Send_Cmd(SDC_CMD_CMD17, data_adrs)) != NO_ERROR)
        ASSERT(0);

    if ((status1 = SD_CheckStatus()) != NO_ERROR)
        ASSERT(0);

    bufIndex = 0;
    loopIndex = 0;

    /*move data from FIFO to buffer*/
    while (((bufIndex * 4) <= size) && (loopIndex < 50000))
    {
        if (MSDC_Reg(MSDC_STA)&MSDC_STA_FIFOCNT)
        {
            msdc_testBuffer[bufIndex] = MSDC_Reg32(MSDC_DAT);
            bufIndex ++;
        }

        loopIndex++;
    }

    /*compare*/
    bufIndex = 0;

    for (bufIndex = 0; bufIndex < size; bufIndex++)
    {
        if (*(bufPtr + bufIndex) != *(compareBuffer + bufIndex))
            ASSERT(0);
    }

    if (KAL_FALSE == msdcDoNotRST)
    {
        MSDC_LSD_SetBits32(MSDC_CFG, MSDC_CFG_RST);
        bufIndex = 5000;

        while (bufIndex--);

        MSDC_LSD_ClearBits32(MSDC_CFG, MSDC_CFG_RST);
        bufIndex = 50000;

        while (bufIndex--);
    }

    /*write FIFOCLR to reset FIFO index*/
    MSDC_WriteReg(MSDC_STA, MSDC_STA_FIFOCLR);

    return status1;
}

SDC_CMD_STATUS msdcWriteLengthTest(kal_uint32 size, kal_uint8 *compareBuffer, kal_uint32 data_adrs, kal_bool notChange)
{

    SDC_CMD_STATUS status1;
    kal_uint32	bufIndex, loopIndex;
    kal_uint8		*bufPtr, *writeBufPtr;


    if (size > 56)
        ASSERT(0);

    bufPtr = (kal_uint8 *)msdc_testBuffer;
    writeBufPtr = (kal_uint8 *)msdc_writeBuffer;
    status1 = SD_SetBlength(size);

    if (NO_ERROR != status1)
        ASSERT(0);

    kal_mem_set(bufPtr, 0, MSDC_TESTBUFFER_SIZE);


    if (notChange)
    {
        kal_mem_cpy(writeBufPtr, compareBuffer, size);
    }
    else
    {
        kal_mem_set(writeBufPtr, (kal_uint8)size, size);
    }

    /*RST MSDC or index may not reset well*/
    if (KAL_FALSE == msdcDoNotRST)
    {
        MSDC_LSD_SetBits32(MSDC_CFG, MSDC_CFG_RST);
        bufIndex = 5000;

        while (bufIndex--);

        MSDC_LSD_ClearBits32(MSDC_CFG, MSDC_CFG_RST);
        bufIndex = 50000;

        while (bufIndex--);
    }

    /*write FIFOCLR to reset FIFO index*/
    MSDC_WriteReg(MSDC_STA, MSDC_STA_FIFOCLR);

    if ((status1 = SD_Send_Cmd(SDC_CMD_CMD24, data_adrs)) != NO_ERROR)
        ASSERT(0);

    if ((status1 = SD_CheckStatus()) != NO_ERROR)
        ASSERT(0);

    bufIndex = 0;
    loopIndex = 0;

    /*move data from FIFO to buffer*/
    while (((bufIndex * 4) <= size) && (loopIndex < 50000))
    {
        if (MSDC_Reg(MSDC_STA)&MSDC_STA_BE)
        {
            MSDC_WriteReg32(MSDC_DAT, msdc_writeBuffer[bufIndex]);
            bufIndex ++;
        }

        loopIndex++;
    }

    /*MCU runs much faster than SD interface, give some delay*/
    while (bufIndex < 5000)
    {
        bufIndex++;
    }

    if (SDC_DATSTA_BLKDONE != MSDC_Reg(SDC_DATSTA))
        ASSERT(0);

    if (KAL_FALSE == msdcDoNotRST)
    {
        /*RST MSDC or index may not reset well*/
        MSDC_LSD_SetBits32(MSDC_CFG, MSDC_CFG_RST);
        bufIndex = 5000;

        while (bufIndex--);

        MSDC_LSD_ClearBits32(MSDC_CFG, MSDC_CFG_RST);
        bufIndex = 50000;

        while (bufIndex--);
    }

    /*write FIFOCLR to reset FIFO index*/
    MSDC_WriteReg(MSDC_STA, MSDC_STA_FIFOCLR);

    if ((status1 = SD_Send_Cmd(SDC_CMD_CMD17, data_adrs)) != NO_ERROR)
        ASSERT(0);

    if ((status1 = SD_CheckStatus()) != NO_ERROR)
        ASSERT(0);

    bufIndex = 0;
    loopIndex = 0;

    /*move data from FIFO to buffer*/
    while (((bufIndex * 4) <= size) && (loopIndex < 50000))
    {
        if (MSDC_Reg(MSDC_STA)&MSDC_STA_FIFOCNT)
        {
            msdc_testBuffer[bufIndex] = MSDC_Reg32(MSDC_DAT);
            bufIndex ++;
        }

        loopIndex = 0;
    }

    /*compare*/
    bufIndex = 0;

    for (bufIndex = 0; bufIndex < size; bufIndex++)
    {
        if (*(bufPtr + bufIndex) != *(writeBufPtr + bufIndex))
            ASSERT(0);
    }

    return status1;
}
#endif

/*************************************************************************
* FUNCTION
*  SD_Initialize
*
* DESCRIPTION
*	Initial SD controller and card
*
* PARAMETERS
*
*
* RETURNS
*  SDC_CMD_STATUS
*
* GLOBALS AFFECTED
*	gSD
*
*************************************************************************/
SDC_CMD_STATUS SD_Initialize(void)
{
    kal_uint32 cid[4], csd[4], scr[4];
    kal_uint16 rca;
    SDC_CMD_STATUS status;
    DCL_HANDLE handle;
    PMU_CTRL_LDO_BUCK_SET_EN val;
	#if !defined(MT6280)
    PMU_CTRL_LDO_BUCK_SET_VOLTAGE val1;
	#endif

#if defined(MT6250)
    PMU_CTRL_LDO_BUCK_SET_STB_EN ldo_buck_set_stb_en;
#endif

#if defined(DRV_MSDC_LATCH_MT6276_SERIES)
#if !defined(__UBL__) && !defined(__FUE__)
	
	handle = DclPMU_Open(DCL_PMU, FLAGS_NONE);
	
	#if !defined(MT6280)
	val1.voltage = PMU_VOLT_03_300000_V;
	val1.mod = VMC;	
	DclPMU_Control(handle, LDO_BUCK_SET_VOLTAGE, (DCL_CTRL_DATA_T *)&val1);
    #endif

    //pmic_adpt2_vmc_enable(KAL_TRUE); //replaced by DCL
    val.enable = KAL_TRUE;
    val.mod = VMC;
    DclPMU_Control(handle, LDO_BUCK_SET_EN, (DCL_CTRL_DATA_T *)&val);

    //
    // For MT6250E1, PMU soft start enable/disable issue will cause voltage drop.
    // Before initialization, enable soft start to prevent mis-trigger OC.
    // After card plug out, disable soft start.
    //
#if defined(MT6250)

    if (INT_SW_SecVersion() == SW_SEC_0)
    {

        ldo_buck_set_stb_en.mod = VMC;
        ldo_buck_set_stb_en.enable = DCL_FALSE;
        DclPMU_Control(handle, LDO_BUCK_SET_STB_EN, (DCL_CTRL_DATA_T *)&ldo_buck_set_stb_en);
    }

#endif

    DclPMU_Close(handle);
#endif//!defined(__UBL__) && !defined(__FUE__)
    gMSDC_Handle->tuningTopology.HighSpeed = SD_ClkTuning_FeedbackClk;//SD_ClkTuning_AutoCalibrate;
    gMSDC_Handle->tuningTopology.NormalSpeed1 = SD_ClkTuning_FeedbackClk;
    gMSDC_Handle->tuningTopology.NormalSpeed2 = NULL;//SD_ClkTuning_ManualCalibrate;
#endif//defined(DRV_MSDC_LATCH_MT6276_SERIES)

#if defined(MSDC_MMC441_SUPPORT)
    gSD->emmc_info.isEmmcV44 = KAL_FALSE;
#endif

#ifdef __CARD_DOWNLOAD__

    if (MSDC_QueryIsPowerControllable())
    {
        /* fix [MAUI_02438803] The popup of card plug in/out keeps coming continuosly. */
        //MSDC_SetPower(KAL_FALSE);
        //kal_sleep_task(2);
        MSDC_SetPower(KAL_TRUE);
    }

#else//__CARD_DOWNLOAD__

#ifdef __DRV_MSDC_VMC_FROM_PMIC__
    //if we don't use DAT3 for carddetection and uses PMIC_VMC as power source, we can switch it off then on for HW reset
#if !defined(__MSDC_TFLASH_DAT3_1BIT_HOT_PLUG__)
#ifdef PMIC_6318_REG_API
    //pmic_vmc_enable(KAL_FALSE); // replaced by DCL
    val.enable = KAL_FALSE;
    val.mod = VBT;
    handle = DclPMU_Open(DCL_PMU, FLAGS_NONE);
    DclPMU_Control(handle, LDO_BUCK_SET_EN, (DCL_CTRL_DATA_T *)&val);
    DclPMU_Close(handle);

    if (KAL_TRUE == FTL_isPollingMode())
    {
        MSDC_GPTI_BusyWait(10);
    }
    else
    {
        kal_sleep_task(2);
    }

    //pmic_vmc_enable(KAL_TRUE); // replaced by DCL
    val.enable = KAL_TRUE;
    val.mod = VBT;
    handle = DclPMU_Open(DCL_PMU, FLAGS_NONE);
    DclPMU_Control(handle, LDO_BUCK_SET_EN, (DCL_CTRL_DATA_T *)&val);
    DclPMU_Close(handle);
#endif
#if defined(PMIC_6235_REG_API)||defined(PMIC_6238_REG_API)
    // Add by GuoXin
    //pmu_set_vbt_en(KAL_FALSE); // replaced by DCL
    val.enable = KAL_FALSE;
    val.mod = VBT;
    handle = DclPMU_Open(DCL_PMU, FLAGS_NONE);
    DclPMU_Control(handle, LDO_BUCK_SET_EN, (DCL_CTRL_DATA_T *)&val);
    DclPMU_Close(handle);

    if (KAL_TRUE == FTL_isPollingMode())
    {
        MSDC_GPTI_BusyWait(10);
    }
    else
    {
        kal_sleep_task(2);
    }

    //pmu_set_vbt_en(KAL_TRUE); // replaced by DCL
    val.enable = KAL_TRUE;
    val.mod = VBT;
    handle = DclPMU_Open(DCL_PMU, FLAGS_NONE);
    DclPMU_Control(handle, LDO_BUCK_SET_EN, (DCL_CTRL_DATA_T *)&val);
    DclPMU_Close(handle);
    // Add by GuoXin
#endif
#endif
#endif//__DRV_MSDC_VMC_FROM_PMIC__

#endif//__CARD_DOWNLOAD__

    //add by songshan
#if (defined(AVANTECH6239_DEMO_BB)||((defined(LIPTON_BB))&&(!defined(__LIPTON_REV_C__))))
    //GPIO_WriteIO(0, GPIO_EXT_SD_LDO_SWITCH); // replaced by DCL
    handle = DclGPIO_Open(DCL_GPIO, GPIO_EXT_SD_LDO_SWITCH);
    DclGPIO_Control(handle, GPO_CMD_WRITE_LOW, 0);
    DclGPIO_Close(handle);

    if (KAL_TRUE == FTL_isPollingMode())
    {
        MSDC_GPTI_BusyWait(10);
    }
    else
    {
        kal_sleep_task(2);
    }

    //GPIO_WriteIO(1, GPIO_EXT_SD_LDO_SWITCH); // replaced by DCL
    handle = DclGPIO_Open(DCL_GPIO, GPIO_EXT_SD_LDO_SWITCH);
    DclGPIO_Control(handle, GPO_CMD_WRITE_HIGH, 0);
    DclGPIO_Close(handle);
#endif

    //add by songshan
    if (gMSDC_Handle->msdc_custom_handle.PowerCtrl)
    {
        gMSDC_Handle->msdc_custom_handle.PowerCtrl(KAL_FALSE);
        kal_sleep_task(2);
        gMSDC_Handle->msdc_custom_handle.PowerCtrl(KAL_TRUE);
    }

    if (gMSDC_Handle->mIsInitialized == KAL_TRUE)
    {
        return NO_ERROR;
    }

#if !defined(__UBL__) && !defined(__FUE__)
#ifdef  __TST_WRITE_TO_FILE__ 			/*error recording: considering error recording additionally*/

    if (KAL_FALSE == INT_QueryExceptionStatus())
#endif
        // reset the events
        kal_set_eg_events(gMSDC_Handle->MSDC_Events, 0, KAL_AND);

#else//!defined(__UBL__) && !defined(__FUE__)
    // TODO: [Samuel]
#endif//!defined(__UBL__) && !defined(__FUE__)

    // reset msdc
#ifndef DRV_LSD

    if (MSDC_Reg32(MSDC_CFG) & MSDC_CFG_RST)
#else
    ASSERT(LSD_Support());

    if (LSD_Reg32(MSDC_CFG) & MSDC_CFG_RST)
#endif
    {
        MSDC_LSD_ClearBits32(MSDC_CFG, MSDC_CFG_RST);
    }
    else
    {
        RESET_MSDC();
    }

    //#if defined(MT6225)
#if defined(DRV_MSDC_MT6225_SERIES)
    MSDC_LSD_SetBits32(MSDC_CFG, MSDC_CFG_CRED);
#endif

#if defined(__EMMC_BOOTING__)
    MSDC_ClearBits32(MSDC_IOCON, MSDC_IOCON_CMDRE);
#endif

    // set the output driving capability from customization interface
#if defined(__SIM_PLUS__)
#if defined(DRV_MSDC_MT6225_SERIES)
    MSDC_LSD_WriteReg32(MSDC_IOCON, 0x2DB);
#else
    MSDC_LSD_WriteReg(MSDC_IOCON, 0x2DB);
#endif
#else
#if defined(DRV_MSDC_MT6225_SERIES)
    MSDC_SetData32(MSDC_IOCON, 0xff, MSDC_GetIOCtrlParam());
#elif defined(DRV_MSDC_IOCON_V2)
    MSDC_SetData32(
        MSDC_IOCON,
        MSDC_IOCON_ODCCFG0 | MSDC_IOCON_ODCCFG1 | MSDC_IOCON_SCRCFG0 | MSDC_IOCON_SCRCFG1,
        MSDC_GetIOCtrlParam()
    );
#if defined(DRV_MSDC_IOCON_MT6255_SERIES)
    MSDC_SetBits32(MSDC_IOCON, MSDC_IOCON_SAMPON);
#endif//defined(DRV_MSDC_IOCON_MT6255_SERIES)
#if defined(DRV_MSDC_IOCON_MT6276_SERIES)
    MSDC_SetData32(MSDC_IOCON, MSDC_IOCON_SAMPLEDLY, 1 << 24);
#endif//defined(DRV_MSDC_IOCON_MT6276_SERIES)
#if defined(DRV_MSDC_LATCH_MT6276_SERIES)
    MSDC_ClearBits32(MSDC_CLKACB_CFG, MSDC_CLKACB_CFG_CLKPAD_RED);
#endif
#else
    MSDC_SetData(MSDC_IOCON, 0xff, MSDC_GetIOCtrlParam());
#endif
#endif//__SIM_PLUS__

    // set read timeout x5ms
    /*in 50MHZ case, we should set 80 to have at least 100ms timeout*/
    BitFieldWrite32((kal_uint32*)SDC_CFG, (kal_uint32)80, SDC_CFG_DTOC);
    //set clock of serial clcok for initialization
#ifndef DRV_LSD
    MSDC_SetClockSource(MSDC_CLOCK_MCU);
    gMSDC_Handle->msdc_clock = MSDC_CLOCK;
    MSDC_SetClock(MSDC_INI_CLOCK);
#else
    LSD_HostSetClock(LSD_SPEED_INIT);
#endif
    // disable 4-bit
    MSDC_LSD_ClearBits32(SDC_CFG, SDC_CFG_MDLEN);
    // initial global sturctures
    SD_SetDefault();
#if defined(DRV_MSDC_LATCH_MT6276_SERIES)
    MSDC_SetLatchTuning();
#else
    MSDC_SetIOCONRegDLT();
#endif//#if defined(DRV_MSDC_LATCH_MT6276_SERIES)

#if defined(DRV_MSDC_IOCON_V2)
    MSDC_WriteReg32(MSDC_IOCON1, 0x22222);
#endif//#if defined(DRV_MSDC_IOCON_V2)

#if defined(__SIM_PLUS__)

    // turn on the power of the MMC of the SIM+
    if (INT_USBBoot() == KAL_TRUE && current_card == SD_SIM)
    {
        static kal_bool is_first = KAL_TRUE;

        if (is_first)
        {
            is_first = KAL_FALSE;

            //GPIO_WriteIO(1, GPIO_LDO_SWITCH); // replaced by DCL
            handle = DclGPIO_Open(DCL_GPIO, GPIO_LDO_SWITCH);
            DclGPIO_Control(handle, GPO_CMD_WRITE_HIGH, 0);
            DclGPIO_Close(handle);

            MSDC_GPTI_BusyWait(300);
        }
    }

#endif

#ifdef DRV_MSDC_ENHANCED_PULL_CTRL
    MSDC_SetBits32(MSDC_CFG, 0x0c000000);
#endif

#ifdef DRV_LSD
    LSD_Host74TCMDHigh();
#else
    /* enable 74 SD clk by s/w */
    MSDC_SetBits32(MSDC_CFG, 0x80);
    {
        kal_uint32 i;

        for (i = 0; i < 100000; i++);
    }
    /* stop SD clk by s/w */
    MSDC_ClearBits32(MSDC_CFG, 0x80);
#endif
    // send the card to IDLE state
    status = SD_Reset();
    SD_INITIALIZE_STATUS_CHECK();

    // and validate the OCR  (CMD0,CMD1 or ADMD41)
    if (SD_CheckSDorMMC() == UNKNOWN_CARD)
    {
        SD_TRACE2(TRACE_GROUP_5, MSDC_GENERAL_FAIL, MSDC_DRV_TRC_FILE_SD, __LINE__);
        status = ERR_STATUS;
        goto err;
    }

    // get CID(CMD2)
    status = SD_GetCID(cid);
    SD_INITIALIZE_STATUS_CHECK();
    // get or set RCA(CMD3)
    status = SD_ValidateRCA(&rca);
    SD_INITIALIZE_STATUS_CHECK();
    // get CSD and analysis the CSD(CMD9)
    status = SD_GetCSD(gSD->mRCA, csd);
    SD_INITIALIZE_STATUS_CHECK();

    // Set driver stage register DSR to default value (0x0404)(CMD4)
    if (gSD->mCSD.dsr_imp)
        if ((status = SD_SetDSR()) != NO_ERROR)
        {
            //dbg_print("6\r\n");
            SD_TRACE2(TRACE_GROUP_5, MSDC_GENERAL_FAIL, MSDC_DRV_TRC_FILE_SD, __LINE__);
            goto err;
        }

#ifndef DRV_LSD
#if !defined(__MSDC_NO_WRITE_PROTECT__)
    // check write proctect switch(WP at SDC_STA)
#if defined(__SIM_PLUS__)

    if (current_card == SD_EXT)
#endif
    {
        if ((MSDC_Reg(SDC_STA) & SDC_STA_WP))
        {
            gSD->mWPEnabled = KAL_TRUE;
			tst_sys_trace("[MSDC]WP\r\n");
        }
    }

#endif
#endif
    // select the card (CMD7) ,maybe locked
    status = SD_SelectCard(gSD->mRCA);
    SD_INITIALIZE_STATUS_CHECK();

    if (status == CARD_IS_LOCKED)
        gSD->mIsLocked = KAL_TRUE;

#if defined(DRV_MSDC_IOCON_MT6268_SERIES)
    BitFieldWrite32((kal_uint32*)MSDC_IOCON, 1, MSDC_IOCON_CMDSEL);
#endif

#ifdef DRV_MSDC_CLK_SEARCH

    if (SD_tuneCLK2() == 0)
        SD_TRACE2(TRACE_GROUP_5, MSDC_ERROR_TUNECLKFAIL, MSDC_Reg32(MSDC_CFG), MSDC_Reg32(MSDC_IOCON));

#endif

#if defined(SD_MMC_HIGH_DENSITY_SUPPORT)

    if (gSD->flags & SD_FLAG_SD_TYPE_CARD)
#else
    if (gMSDC_Handle->mMSDC_type == SD_CARD)
#endif
    {
        status = SD_ReadSCR(scr);
        SD_INITIALIZE_STATUS_CHECK();
#if defined(MSDC_USE_USB_CLK)	&& !defined(__SIM_PLUS__)
        SD_Use24M_Clock();
        MSDC_SetIOCONRegDLT();
#else
        //#if defined(DRV_MSDC_CLK_MT6276_SERIES)
        //		MSDC_SetClock(MSDC_OP_CLOCK); // TODO: better clock design?
        //#else
#ifndef	DRV_MSDC_CLK_SEARCH

        /*JRD SIM+ issue on 2007_03_08, JRD data line signal not stable, we can't use 24M even without SIM+ existence*/
        if ((!MSDC_Blk[SD_SIM].mIsInitialized) && (MSDC_24M == MSDC_GetClockWithoutSIMPlus()))
            SD_Use24M_Clock();
        else
            SD_Use13M_Clock();

#endif
        //#endif//#if defined(DRV_MSDC_CLK_MT6276_SERIES)
#endif

#if defined(MSDC_SD_BITS4_BUS)

        if (KAL_FALSE == gMSDC_Handle->trySingleLine)
        {
            status = SD_SetBusWidth(BIT_4W);
            SD_INITIALIZE_STATUS_CHECK();

        }

#endif

#if !defined(__MSDC_TFLASH_DAT3_1BIT_HOT_PLUG__)
        status = SD_Acmd42(KAL_FALSE);
        SD_INITIALIZE_STATUS_CHECK();
#endif

        if (gSD->flags & SD_FLAG_CMD6_SUPPORT)
        {
            status = SD_SelectHighSpeed_SD11();

            if (status == NO_ERROR)
            {
				tst_sys_trace("SD_SelectHighSpeed_SD11 pass\r\n");
                gSD->flags |= SD_FLAG_HS_ENABLED;
                //1 NEED to Modify such as using 48M clock

#ifndef	DRV_MSDC_CLK_SEARCH
                MSDC_SetClockSource(MSDC_CLOCK_MCU);
                gMSDC_Handle->msdc_clock = MSDC_CLOCK;
                MSDC_SetClock(26000);
#if !defined(DRV_MSDC_CLK_MT6276_SERIES) && !defined(DRV_MSDC_CLK_MT6256_SERIES)
                MSDC_SetIOCONRegDLT();
#endif//#if defined(DRV_MSDC_CLK_MT6276_SERIES)
#endif
            }
        }
    }
    else
    {
#if defined(MSDC_MMC40_SUPPORT)

        if ((gMSDC_Handle->mMSDC_type == MMC_CARD || gMSDC_Handle->mMSDC_type == MMC42_CARD) && gSD->mCSD.spec_ver >= 4)
        {
            if (gMSDC_Handle->mMSDC_type == MMC_CARD) /*we don't need to change MMC42_CARD to MMC40_CARD*/
                gMSDC_Handle->mMSDC_type = MMC40_CARD;

#if 0
#if defined(MSDC_MMC441_SUPPORT)
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
#else
            status = SD_SetMMC40_bus_high_speed();
            SD_INITIALIZE_STATUS_CHECK();
#if defined(MSDC_MMC441_SUPPORT)

            if ( gSD->mCSD.ext_csd->ext_csd_rev >= 5 )
            {
                // set ERASE_GROUP_DEF[175] before issuing read, write, erase, write protect
                status = SD_Switch_MMC40(SET_BYTE, EXT_CSD_ERASE_GRP_DEF, 1 , 0);
                SD_INITIALIZE_STATUS_CHECK();
            }

#endif
#endif
        }
        else
#endif
        {
            SD_Use13M_Clock();
#if !defined(DRV_MSDC_LATCH_MT6276_SERIES)
            MSDC_SetIOCONRegDLT();
#endif//#if defined(DRV_MSDC_LATCH_MT6276_SERIES)
        }
    }

    //! patch for MT6268/6253/6516 and later chips
#if defined(DRV_MSDC_IOCON_MT6268_SERIES)
    BitFieldWrite32((kal_uint32*)MSDC_IOCON, 1, MSDC_IOCON_CMDSEL);
#endif

#ifdef DRV_MSDC_CLK_SEARCH

    if (!(gMSDC_Handle->msdc_clkTuneUpperBund = SD_tuneCLK2()))
    {
        SD_TRACE2(TRACE_GROUP_5, MSDC_ERROR_TUNECLKFAIL, MSDC_Reg32(MSDC_CFG), MSDC_Reg32(MSDC_IOCON));
        status = ERR_ERRORS;
        goto err;
    }

#endif


#ifdef __MSDC_BASIC_LOAD__

    if (0 == (gSD->flags & SD_FLAG_HCS_SUPPORT))
    {
        /*here we test non 4N trasnfer in DVT basic load*/
        /*read sector 0 to buffer*/
        status = SD_SetBlength(512);
        SD_ReadSingleBlock(0, MSDC_Sector);

        if (msdcOddNumberSizeTestByDMA)
        {
            status = SD_SetBlength(11);
            SD_ReadSingleBlock(0, msdc_testBuffer);
        }

        msdcTransferLengthTest(100, (kal_uint8 *)MSDC_Sector, 0);
        msdcTransferLengthTest(11, (kal_uint8 *)MSDC_Sector, 0);
        msdcTransferLengthTest(10, (kal_uint8 *)MSDC_Sector, 0);
        msdcTransferLengthTest(9, (kal_uint8 *)MSDC_Sector, 0);

        /*because some card can support partial block size read, but can't support partial size write*/
        if (1 == gSD->mCSD.w_blk_part)
        {
            msdcWriteLengthTest(9, (kal_uint8 *)MSDC_Sector, 0, KAL_FALSE);
            msdcWriteLengthTest(10, (kal_uint8 *)MSDC_Sector, 0, KAL_FALSE);
            msdcWriteLengthTest(11, (kal_uint8 *)MSDC_Sector, 0, KAL_FALSE);
            msdcWriteLengthTest(11, (kal_uint8 *)MSDC_Sector, 0, KAL_TRUE);
            tst_sys_trace("non-4N transfer write verified okay");
        }

        tst_sys_trace("non-4N transfer verified okay");
    }

#endif


    // set block length (CMD16)
    status = SD_SetBlength(512);
    SD_INITIALIZE_STATUS_CHECK();
err:

    if (status != NO_ERROR)
    {
        tst_sys_trace("SD mount fail!");
        SD_SetDefault();
        gMSDC_Handle->mIsInitialized = KAL_FALSE;
        gMSDC_Handle->mIsPresent = KAL_FALSE;
        MSDC_turnOnVMC(gMSDC_Handle->mIsPresent);
		MSDC_PDNControl(KAL_TRUE);
    }
    else
    {
        tst_sys_trace("SD mount ok!");
        gMSDC_Handle->mIsInitialized = KAL_TRUE;
    }

    kal_set_eg_events(gMSDC_Handle->MSDC_Events, 0, KAL_AND);

    //
    // For memory dump debug convenient, assign local variable to global variable.
    //
    gblSDsta = status;

    //
    // Modify the return value to a general value to make dclsd_control can identify this in switch case.
    //
    return ((status == NO_ERROR) ? NO_ERROR : ERR_STATUS);
}

#ifdef __MEUT__
SDC_CMD_STATUS SD_SetCallBack(MSDC_CALLBACK callback1, MSDC_CALLBACK callback2, MSDC_CALLBACK callback3, MSDC_CALLBACK callback4, MSDC_CALLBACK callback5, MSDC_CALLBACK callback6)
{
    msdc_TestCallBack1 = callback1;
    msdc_TestCallBack2 = callback2;
    msdc_TestCallBack3 = callback3;
    msdc_TestCallBack4 = callback4;
    msdc_TestCallBack5 = callback5;
    msdc_TestCallBack6 = callback6;

    return NO_ERROR;
}
SDC_CMD_STATUS SD_SetReadTestFlag(kal_uint32 readTestFlag)
{
    msdc_ReadTestFlag = readTestFlag;
    return NO_ERROR;
}
SDC_CMD_STATUS SD_readTest(void)
{

    msdcReadTest(512, (kal_uint8 *)MSDC_Sector, 0);
    return NO_ERROR;
}

SDC_CMD_STATUS SD_SetUpllClock(void)
{

    SD_Use24M_Clock();
#if defined(DRV_MSDC_LATCH_MT6276_SERIES)
    MSDC_SetLatchTuning();
#else
    MSDC_SetIOCONRegDLT();
#endif//#if defined(DRV_MSDC_LATCH_MT6276_SERIES)
    return NO_ERROR;
}
#endif


void SD_InvertN(kal_uint8 *dest, kal_uint8 *src, kal_uint8 len)
{
    int i;

    for (i = 0; i < len; i++)
        *(dest + len - 1 - i) = *(src + i);

}
/*************************************************************************
* FUNCTION
*  power2
*
* DESCRIPTION
*	Calculate the power of 2
*
* PARAMETERS
*	num:
*
* RETURNS
*  2^num
*
* GLOBALS AFFECTED
*
*************************************************************************/
static kal_uint32 power2(kal_uint32 num)
{
    return 1 << num;
}

/*************************************************************************
* FUNCTION
*  SD_AnalysisCSD
*
* DESCRIPTION
*	Analysis Card Specific Data and store in the member of gSD
*
* PARAMETERS
*	csd: input csd for analysis
* RETURNS
*
* GLOBALS AFFECTED
*	gSD
*
*************************************************************************/
void SD_AnalysisCSD(kal_uint32* csd)
{
    kal_uint8 *ptr;
    kal_uint32 c_mult, c_size;

    ptr = (kal_uint8*)csd;
    c_mult = c_size = 0;
    // these offsets refer to the spec. of SD and MMC
    GetBitFieldN((kal_uint8*)&gSD->mCSD.csd_ver, ptr, 126, 2);
    GetBitFieldN((kal_uint8*)&gSD->mCSD.tacc, ptr, 112, 8);
    GetBitFieldN((kal_uint8*)&gSD->mCSD.nsac, ptr, 104, 8);
    GetBitFieldN((kal_uint8*)&gSD->mCSD.tran_speed, ptr, 96, 8);
    GetBitFieldN((kal_uint8*)&gSD->mCSD.ccc, ptr, 84, 12);
    GetBitFieldN((kal_uint8*)&gSD->mCSD.r_blk_len, ptr, 80, 4);
    gSD->mCSD.r_blk_len = power2(gSD->mCSD.r_blk_len);
    GetBitFieldN((kal_uint8*)&gSD->mCSD.r_blk_part, ptr, 79, 1);
    GetBitFieldN((kal_uint8*)&gSD->mCSD.w_blk_misali, ptr, 78, 1);
    GetBitFieldN((kal_uint8*)&gSD->mCSD.r_blk_misali, ptr, 77, 1);
    GetBitFieldN((kal_uint8*)&gSD->mCSD.dsr_imp, ptr, 76, 1);
    GetBitFieldN((kal_uint8*)&gSD->mCSD.w_blk_part, ptr, 21, 1);
    GetBitFieldN((kal_uint8*)&gSD->mCSD.w_blk_len, ptr, 22, 4);
    gSD->mCSD.w_blk_len = power2(gSD->mCSD.w_blk_len);
    GetBitFieldN((kal_uint8*)&gSD->mCSD.wp_grp_enable, ptr, 31, 1);

    // there are some difference of CSD between SD and MMC
    if (gMSDC_Handle->mMSDC_type == MMC_CARD || gMSDC_Handle->mMSDC_type == MMC42_CARD)
    {
        GetBitFieldN((kal_uint8*)&gSD->mCSD.spec_ver, ptr, 122, 4);
        GetBitFieldN((kal_uint8*)&gSD->mCSD.erase_sec_size_mmc, ptr, 42, 5);
        gSD->mCSD.erase_sec_size_mmc = (gSD->mCSD.erase_sec_size_mmc + 1) * gSD->mCSD.w_blk_len;
        GetBitFieldN((kal_uint8*)&gSD->mCSD.erase_grp_size_mmc, ptr, 37, 5);
        gSD->mCSD.erase_grp_size_mmc = (gSD->mCSD.erase_grp_size_mmc + 1) * gSD->mCSD.erase_sec_size_mmc;
        GetBitFieldN((kal_uint8*)&gSD->mCSD.wp_grp_size_mmc, ptr, 32, 5);
        gSD->mCSD.wp_grp_size_mmc = (gSD->mCSD.wp_grp_size_mmc + 1) * gSD->mCSD.erase_grp_size_mmc;
    }
    else // SD_CARD
    {
        GetBitFieldN((kal_uint8*)&gSD->mCSD.erase_sec_size_sd, ptr, 39, 7);
        gSD->mCSD.erase_sec_size_sd += 1;
        GetBitFieldN((kal_uint8*)&gSD->mCSD.wp_prg_size_sd, ptr, 32, 7);
        gSD->mCSD.wp_prg_size_sd = (gSD->mCSD.wp_prg_size_sd + 1) * gSD->mCSD.erase_sec_size_sd;
        GetBitFieldN((kal_uint8*)&gSD->mCSD.erase_blk_en_sd, ptr, 46, 1);
    }

#if defined(SD_MMC_HIGH_DENSITY_SUPPORT)

    if (gMSDC_Handle->mMSDC_type == SD20_HCS_CARD && gSD->mCSD.csd_ver >= SD_CSD_VER_20)
    {
        GetBitFieldN((kal_uint8*)&c_size, ptr, 48, 22);
        gSD->mBKNum = (c_size + 1);
        gSD->mCSD.capacity = (kal_uint64)gSD->mBKNum * 512 * 1024;
    }
    else
#endif
    {
        GetBitFieldN((kal_uint8*)&c_mult, ptr, 47, 3);
        c_mult = power2(c_mult + 2);
        GetBitFieldN((kal_uint8*)&c_size, ptr, 62, 12);
        gSD->mBKNum = (c_size + 1) * c_mult;
        gSD->mCSD.capacity = (kal_uint64)(c_size + 1) * (kal_uint64)c_mult * (kal_uint64)gSD->mCSD.r_blk_len;
    }

}

/*************************************************************************
* FUNCTION
*  SD_AnalysisCID
*
* DESCRIPTION
*	Analysis Card Identificaton and store in the member of gSD
*
* PARAMETERS
*	cid: input of card ID for analysis
* RETURNS
*
* GLOBALS AFFECTED
*	gSD
*
*************************************************************************/
void SD_AnalysisCID(kal_uint32* cid)
{
    kal_uint8	i;
    kal_uint8* pcid;
    pcid = (kal_uint8*)cid;

    if (gMSDC_Handle->mMSDC_type == MMC_CARD || MMC42_CARD == gMSDC_Handle->mMSDC_type)
    {
        GetBitFieldN((kal_uint8*)&gSD->mCID.year, pcid, 8, 4);
        gSD->mCID.year += 1997;
        GetBitFieldN((kal_uint8*)&gSD->mCID.month, pcid, 12, 4);
        GetBitFieldN((kal_uint8*)&gSD->mCID.psn, pcid, 16, 32);
        GetBitFieldN((kal_uint8*)&gSD->mCID.prv, pcid, 48, 8);

        for (i = 0; i < 6; i++)
            gSD->mCID.pnm[i] = *(pcid + 7 + i);

        GetBitFieldN((kal_uint8*)&gSD->mCID.oid, pcid, 104, 16);
        GetBitFieldN((kal_uint8*)&gSD->mCID.mid, pcid, 120, 8);

        // special case handling
        {
            kal_uint8 pnm[] = {0xFF, 0xFF, 0xFF, 0xFF, 0x36, 0x31};

            if (gSD->mCID.mid == 6 && gSD->mCID.oid == 0 &&
                !kal_mem_cmp(gSD->mCID.pnm, pnm, 6))
            {
                gSD->flags |= SD_FLAG_MMC_MRSW_FAIL;
            }
        }
#ifdef __CMMB_CAS_FULL_CARD_SUPPORT__
        {
            kal_uint8 fullCardPnm[] = {0x55, 0x59, 0x4E, 0x41, 0x49, 0x54};

            if (!kal_mem_cmp(gSD->mCID.pnm, fullCardPnm, 6)) /*Tianyu does not provide MID and OID*/
            {
                SD_setFullCard(KAL_TRUE);
                gMSDC_Handle->msdc_clkTuneUpperBund = 15000;
            }
            else
                SD_setFullCard(KAL_FALSE);
        }
#endif

    }
    else // SD_CARD
    {
        gSD->mCID.mid = *(pcid + 15);
        gSD->mCID.oid = *(pcid + 13) + 256 * (*(pcid + 14));

        for (i = 0; i < 5; i++)
            gSD->mCID.pnm[i] = *(pcid + 8 + i);

        gSD->mCID.prv = *(pcid + 7);
        //gSD->mCID.psn = *(kal_uint32*)(pcid+3);
        gSD->mCID.psn = (*(kal_uint32*)(pcid + 4) << 8) | *(pcid + 3);
        gSD->mCID.month = (kal_uint8)GET_BIT(*(pcid + 1), 0, BIT_MASK_4);
        gSD->mCID.year = GET_BIT(*(pcid + 1), 4, BIT_MASK_4) + 16 * GET_BIT(*(pcid + 2), 0, BIT_MASK_4) + 2000;
    }

#ifdef MSDC_TRACE_LEVEL1
    drv_trace2(TRACE_GROUP_6, MSDC_INFORM_CID, gSD->mCID.mid, gSD->mCID.oid);
#endif
}

/*************************************************************************
* FUNCTION
*  SD_AnalysisSCR
*
* DESCRIPTION
*	Analysis SD Card Configuration Register and store in the member of gSD
*
* PARAMETERS
*	scr: input of scr for analysis
* RETURNS
*
* GLOBALS AFFECTED
*	gSD
*
* NOTE
*	Only for SD card.
*
*************************************************************************/
void SD_AnalysisSCR(kal_uint32* scr)
{
    kal_uint8 *pscr;

    pscr = (kal_uint8*)scr;
    gSD->mSCR.spec_ver = (SD_SPEC)((kal_uint8)GET_BIT(*(pscr), 0, BIT_MASK_4));

    if (gSD->mSCR.spec_ver > SD_SPEC_101)
        gSD->flags |= SD_FLAG_CMD6_SUPPORT;

    gSD->mSCR.dat_after_erase = (kal_uint8)GET_BIT(*(pscr + 1), 7, BIT_MASK_1);
    gSD->mSCR.security = (kal_uint8)GET_BIT(*(pscr + 1), 4, BIT_MASK_3);
    gSD->mSCR.bus_width = (kal_uint8)GET_BIT(*(pscr + 1), 0, BIT_MASK_4);
}

/*************************************************************************
* FUNCTION
*  SD_WaitCmdRdyOrTo
*
* DESCRIPTION
*	Wait until command ready or timeout
*
* PARAMETERS
*
* RETURNS
*	SDC_CMD_STATUS
*
* GLOBALS AFFECTED
*
* NOTE
*	Interrupt driven and polling are both implemented
*
*************************************************************************/
SDC_CMD_STATUS SD_WaitCmdRdyOrTo(void)
{

    MSDC_START_TIMER(MSDC_TIMEOUT_PERIOD_CMD);

#ifdef MSDC_USE_INT
    {
        kal_uint32 	flags = 0;
        kal_uint16 sdc_cmdsta = 0;

        if (!gMSDC_Handle->mIsPresent)
            return ERR_CARD_NOT_PRESENT;

        kal_retrieve_eg_events(gMSDC_Handle->MSDC_Events, EVENT_SDCMDIRQ, KAL_AND_CONSUME, &flags, KAL_SUSPEND);
        MSDC_STOP_TIMER();

        sdc_cmdsta = MSDC_Reg(SDC_CMDSTA);
        gMSDC_Handle->cmd_sta = sdc_cmdsta;

        if (sdc_cmdsta & SDC_CMDSTA_CMDTO)
        {
            tst_sys_trace("[MSDC]:cmd timeout");
            return ERR_CMD_TIMEOUT;
        }
        else if (sdc_cmdsta & SDC_CMDSTA_RSPCRCERR)
        {
            tst_sys_trace("[MSDC]:cmd crc");
            return ERR_CMD_RSPCRCERR;
        }
        else if (sdc_cmdsta & SDC_CMDSTA_CMDRDY)
            return NO_ERROR;
    }
#else
    {
        volatile kal_uint16 sdc_cmdsta;
        kal_uint32 t1;

        t1 = drv_get_current_time();

        do
        {
            if (drv_get_duration_ms(t1) > MSDC_TIMEOUT_PERIOD_CMD * 11)
                gMSDC_Handle->is_timeout = KAL_TRUE;
            else if(drv_get_duration_ms(t1)>10)
                SD_Sleep4Wait(1);

#ifndef DRV_LSD
            sdc_cmdsta = MSDC_Reg(SDC_CMDSTA);
#else
            sdc_cmdsta = LSD_Reg32(SDC_CMDSTA);
#endif
        }
        while (!sdc_cmdsta && MSDC_Check_Card_Present() && !gMSDC_Handle->is_timeout);

        MSDC_STOP_TIMER();

        MSDC_CLR_INT();
        gMSDC_Handle->cmd_sta = sdc_cmdsta;

        if (sdc_cmdsta & SDC_CMDSTA_CMDTO)
        {
#ifdef MSDC_TRACE_LEVEL2
            drv_trace4(TRACE_GROUP_4, MSDC_ERROR_CMDTIMEOUT, sdc_cmdsta, drv_get_current_time(),
                       MSDC_Reg(SDC_STA), MSDC_Reg32(MSDC_IOCON));
#endif
            return ERR_CMD_TIMEOUT;
        }
        else if (sdc_cmdsta & SDC_CMDSTA_RSPCRCERR)
        {
#ifdef MSDC_TRACE_LEVEL1
            drv_trace4(TRACE_GROUP_4, MSDC_ERROR_RSPCRC, sdc_cmdsta, drv_get_current_time(),
                       MSDC_Reg(SDC_STA), MSDC_Reg32(MSDC_IOCON));
#endif
            return ERR_CMD_RSPCRCERR;
        }
        else if (sdc_cmdsta & SDC_CMDSTA_CMDRDY)
            return NO_ERROR;
    }

    if (gMSDC_Handle->is_timeout)
        return MSDC_GPT_TIMEOUT_ERR;

#endif

    return NO_ERROR;
}

/*************************************************************************
* FUNCTION
*  SD_WaitDatRdyOrTo
*
* DESCRIPTION
*	Wait until data ready or timeout
*
* PARAMETERS
*
* RETURNS
*	SDC_CMD_STATUS
*
* GLOBALS AFFECTED
*
* NOTE
*	Interrupt driven and polling are both implemented
*
*************************************************************************/
SDC_CMD_STATUS SD_WaitDatRdyOrTo(void)
{
    MSDC_START_TIMER(MSDC_TIMEOUT_PERIOD_DAT);

#ifdef MSDC_USE_INT
    {
        kal_uint16 sdc_datsta = 0;
        kal_uint32 	flags = 0;

        if (!gMSDC_Handle->mIsPresent)
            return ERR_CARD_NOT_PRESENT;

        kal_retrieve_eg_events(gMSDC_Handle->MSDC_Events, EVENT_SDDATIRQ, KAL_AND_CONSUME, &flags, KAL_SUSPEND);
        MSDC_STOP_TIMER();
        sdc_datsta = MSDC_Reg(SDC_DATSTA);
        gMSDC_Handle->dat_sta = sdc_datsta;

        if (sdc_datsta & SDC_DATSTA_DATTO)
        {
            tst_sys_trace("[MSDC]:dat timeout");
            return ERR_DAT_TIMEOUT;
        }
        else if (sdc_datsta & SDC_DATSTA_DATCRCERR)
        {
            tst_sys_trace("[MSDC]:dat crc");
            return ERR_DAT_CRCERR;
        }
        else if (sdc_datsta & SDC_DATSTA_BLKDONE)
            return NO_ERROR;
    }
#else
    {
        volatile kal_uint16 sdc_datsta;
        kal_uint32 t1;

        t1 = drv_get_current_time();

        do
        {
            if (drv_get_duration_ms(t1) > MSDC_TIMEOUT_PERIOD_DAT * 11)
                gMSDC_Handle->is_timeout = KAL_TRUE;
            else if(drv_get_duration_ms(t1)>10)
                SD_Sleep4Wait(1);

#ifndef DRV_LSD
            sdc_datsta = MSDC_Reg(SDC_DATSTA);
#else
            sdc_datsta = LSD_Reg32(SDC_DATSTA);
#endif
        }
        while (!sdc_datsta && MSDC_Check_Card_Present() && !gMSDC_Handle->is_timeout);

        MSDC_STOP_TIMER();
        MSDC_CLR_INT();
        gMSDC_Handle->dat_sta = sdc_datsta;

        if (KAL_TRUE == kal_query_systemInit())
        {
#if defined(MSDC_TRACE_LEVEL3)
            MSDC_add_dbg_msg(msdc_dbg_event_SD_datsta_systemInit, gMSDC_Handle->dat_sta, gMSDC_Handle->is_timeout);
#endif
        }

        if (sdc_datsta & SDC_DATSTA_DATTO)
        {
            tst_sys_trace("[MSDC]:dat timeout");
#ifdef MSDC_TRACE_LEVEL1
            drv_trace4(TRACE_GROUP_4, MSDC_ERROR_DATTIMEOUT, sdc_datsta, drv_get_current_time(),
                       MSDC_Reg(SDC_STA), MSDC_Reg32(MSDC_IOCON));
#endif
            return ERR_DAT_TIMEOUT;
        }
        else if (sdc_datsta & SDC_DATSTA_DATCRCERR)
        {
#ifdef MSDC_TRACE_LEVEL1
            drv_trace4(TRACE_GROUP_4, MSDC_ERROR_DATCRC, sdc_datsta, drv_get_current_time(),
                       MSDC_Reg(SDC_STA), MSDC_Reg32(MSDC_IOCON));
#endif
            return ERR_DAT_CRCERR;
        }
        else if (sdc_datsta & SDC_DATSTA_BLKDONE)
            return NO_ERROR;
    }

    if (gMSDC_Handle->is_timeout)
        return MSDC_GPT_TIMEOUT_ERR;

#endif

    return NO_ERROR;
}
/*************************************************************************
* FUNCTION
*  SD_WaitCardNotBusy
*
* DESCRIPTION
*	Wait until card is not busy (R1b)
*
* PARAMETERS
*
* RETURNS
*	void
*
* GLOBALS AFFECTED
*
* NOTE
*	Interrupt driven and polling are both implemented
*
*************************************************************************/
extern kal_bool FTL_isPollingMode();
kal_uint32 direct_msdc_entry = 0;

SDC_CMD_STATUS SD_WaitCardNotBusy(void)
{
    kal_uint32 t1, t2;
    kal_uint16 exec_times = 0;
    kal_uint32 	flags = 0, mult;
#ifdef __MSDC_BASIC_LOAD__
    mult = 50;
#else
    mult = 11;
#endif

    //register kal_uint16 msdc_int;

    t1 = drv_get_current_time();
    MSDC_START_TIMER(MSDC_TIMEOUT_PERIOD_DAT);
    t2 = drv_get_current_time();
    MSDC_SLA_Start_Logging("R1B");
#if defined(MSDC_USE_INT)
    {
        if (!gMSDC_Handle->mIsPresent)
            return;

        kal_retrieve_eg_events(gMSDC_Handle->MSDC_Events, EVENT_SDR1BIRQ, KAL_AND_CONSUME, &flags, KAL_SUSPEND);
    }
#elif defined(R1B_INTERRUPT_MODE)

    if (kal_query_systemInit() == KAL_TRUE
#ifdef  __TST_WRITE_TO_FILE__	/*error recording: considering error recording additionally*/
        || (KAL_TRUE == INT_QueryExceptionStatus())
#endif
       )
    {
        while (SD_IS_R1B_BUSY && MSDC_Check_Card_Present() && !gMSDC_Handle->is_timeout)
        {
            if (drv_get_duration_ms(t1) > 1 && kal_query_systemInit() == KAL_FALSE && (KAL_FALSE == INT_QueryExceptionStatus()))
            {
                exec_times ++;

                if (KAL_TRUE == FTL_isPollingMode())
                {
                    MSDC_GPTI_BusyWait(5);
                }
                else
                {
                    kal_sleep_task(1);
                }
            }

            if (drv_get_duration_ms(t1) > MSDC_TIMEOUT_PERIOD_DAT * mult)
            {
#ifndef DRV_LSD
                drv_trace1(TRACE_GROUP_5, MSDC_FAIL_WAITNOTBUSY_TIMEOUT, MSDC_Reg(SDC_STA));
#else
                drv_trace1(TRACE_GROUP_5, MSDC_FAIL_WAITNOTBUSY_TIMEOUT, 0);
#endif
                gMSDC_Handle->is_timeout = KAL_TRUE;
            }
        };
    }
    else
    {
        // kal_set_eg_events(gMSDC_Handle->MSDC_Events,EVENT_SDR1BIRQ,KAL_AND);
        // IRQUnmask(IRQ_MSDC_CODE);

        if (!gMSDC_Handle->mIsPresent)
            return ERR_INVALID_CARD;

        //while (SD_IS_R1B_BUSY);

        //if (SD_IS_R1B_BUSY)
        //{
        kal_retrieve_eg_events(gMSDC_Handle->MSDC_Events, EVENT_SDR1BIRQ, KAL_OR_CONSUME, &flags, KAL_SUSPEND);
        //}
        //else
        //{
        //    direct_msdc_entry++;
        //}

#ifdef R1B_DEBUG
        drv_trace2(TRACE_GROUP_6, MSDC_INFORM_R1B_DEBUG, direct_msdc_entry, gMSDC_Handle->LISR_Entry_Count);
        drv_trace8(TRACE_GROUP_6, MSDC_INFORM_R1B_DEBUG_2, gMSDC_Handle->SDCMDIRQ_Entry_Count, \
                   gMSDC_Handle->SDMCIRQ_Entry_Count, gMSDC_Handle->SDDATIRQ_Entry_Count, gMSDC_Handle->SDR1bIRQ_Entry_count, \
                   gMSDC_Handle->SDIOIRQ_Entry_Count, gMSDC_Handle->SDPINIRQ_Entry_Count, 0, 0);
#endif
    }

#else
    {
        while (SD_IS_R1B_BUSY && MSDC_Check_Card_Present() && !gMSDC_Handle->is_timeout)
        {
            if (drv_get_duration_ms(t1) > 1 && kal_query_systemInit() == KAL_FALSE && (KAL_FALSE == INT_QueryExceptionStatus()))
            {
                exec_times ++;

                if (KAL_TRUE == FTL_isPollingMode())
                {
                    MSDC_GPTI_BusyWait(5);
                }
                else
                {
                    kal_sleep_task(1);
                }
            }

            if (drv_get_duration_ms(t1) > MSDC_TIMEOUT_PERIOD_DAT * mult)
            {
#ifdef MSDC_TRACE_LEVEL1
                drv_trace1(TRACE_GROUP_5, MSDC_FAIL_WAITNOTBUSY_TIMEOUT, MSDC_Reg(SDC_STA));
#endif
                gMSDC_Handle->is_timeout = KAL_TRUE;
            }
        };
    }
#endif
    MSDC_SLA_Stop_Logging("R1B");
#ifdef MSDC_TRACE_LEVEL2
    drv_trace2(TRACE_GROUP_6, MSDC_INFORM_CARD_PROGRAMMING, drv_get_duration_ms(t2), exec_times);
#endif

    MSDC_CLR_INT();
    MSDC_STOP_TIMER();
#if 0
/* under construction !*/
#else

    if (!SD_IS_R1B_BUSY && gMSDC_Handle->is_timeout == KAL_FALSE) //guilin
        return NO_ERROR;
    else
        return ERR_CMD_TIMEOUT;

#endif
}

/*************************************************************************
* FUNCTION
*  SD_CheckStatus
*
* DESCRIPTION
*	Check command status
*
* PARAMETERS
*
* RETURNS
*	SDC_CMD_STATUS
*
* GLOBALS AFFECTED
*
* NOTE
*
*************************************************************************/
SDC_CMD_STATUS SD_CheckStatus()
{
    kal_uint32 status;

    MSDC_LSD_ReadReg32(SDC_RESP0, &status);

#ifdef MSDC_TRACE_LEVEL2
    drv_trace2(TRACE_GROUP_6, MSDC_INFORM_R0, status, __LINE__);
#endif

    if ((status & SDC_CSTA_MASK) == 0 )
        return NO_ERROR;

    if (status & SDC_CARD_IS_LOCKED)
        return CARD_IS_LOCKED;

    return ERR_STATUS;
}

/*************************************************************************
* FUNCTION
*  SD_Send_Cmd
*
* DESCRIPTION
*	to launch the command packet to the card
*
* PARAMETERS
*	1. cmd: the content of SDC_CMD register
*	2. arg: the argument(if the command need no argument, fill it with 0)
*
* RETURNS
*	SDC_CMD_STATUS
*
* GLOBALS AFFECTED
*
* NOTE
*	1. Check if controller is available  before launch any commands
*	2. Maybe add check if card is busy (R1b)
*************************************************************************/
SDC_CMD_STATUS SD_Send_Cmd(kal_uint32 cmd, kal_uint32 arg)
{
    SDC_CMD_STATUS status;
    kal_uint32 t1;

    t1 = drv_get_current_time();
    MSDC_START_TIMER(MSDC_TIMEOUT_PERIOD_CMD);

    // check the controller is ready (stop transaction will fail)
    if (cmd != SDC_CMD_CMD12)
    {
        while (SD_IS_SDC_BUSY && MSDC_Check_Card_Present() && !gMSDC_Handle->is_timeout)
        {
            if (drv_get_duration_ms(t1) > MSDC_TIMEOUT_PERIOD_CMD * 11)
                gMSDC_Handle->is_timeout = KAL_TRUE;
            else if(drv_get_duration_ms(t1)>10)
                SD_Sleep4Wait(1);
        }
    }
    else
    {
        while (SD_IS_CMD_BUSY && MSDC_Check_Card_Present() && !gMSDC_Handle->is_timeout)
        {
            if (drv_get_duration_ms(t1) > MSDC_TIMEOUT_PERIOD_CMD * 11)
                gMSDC_Handle->is_timeout = KAL_TRUE;
            else if(drv_get_duration_ms(t1)>10)
                SD_Sleep4Wait(1);
        }
    }

    MSDC_STOP_TIMER();

    if (gMSDC_Handle->is_timeout)
        return MSDC_GPT_TIMEOUT_ERR;

    MSDC_CLR_INT();

    gMSDC_Handle->cmd_sta = MSDC_Reg(SDC_CMDSTA);
    gMSDC_Handle->dat_sta = MSDC_Reg(SDC_DATSTA);

#ifdef MSDC_TRACE_LEVEL1
    drv_trace4(TRACE_GROUP_6, MSDC_INFORM_BEFORE_SEND_CMD, gMSDC_Handle->cmd_sta, gMSDC_Handle->dat_sta, MSDC_Reg(SDC_CMD), __LINE__);
#endif

    // fill out the argument
    MSDC_LSD_WriteReg32(SDC_ARG, arg);

    // launch the command
    if (0x8D != cmd)
    {
#ifdef MSDC_TRACE_LEVEL3
        MSDC_add_dbg_msg(msdc_dbg_event_SD_CMD_issue, cmd, MSDC_Reg(DMA_RLCT(gMSDC_Handle->msdc_dmaport)));
        MSDC_add_dbg_msg(msdc_dbg_event_SD_CMD_issue2, arg, MSDC_Reg32(SDC_CFG));
#endif
    }

    MSDC_LSD_WriteReg32(SDC_CMD, cmd | sd_cmd_extra);

    if ((status = SD_WaitCmdRdyOrTo()) != NO_ERROR)
        return status;

    return NO_ERROR;
}

/*************************************************************************
* FUNCTION
*  SD_Reset
*
* DESCRIPTION
*	reset all cards to idle state
*
* PARAMETERS
*	1. cmd: the content of SDC_CMD register
*	2. arg: the argument(if the command need no argument, fill it with 0)
*
* RETURNS
*	SDC_CMD_STATUS
*
* GLOBALS AFFECTED
*
* NOTE
*
*************************************************************************/
SDC_CMD_STATUS SD_Reset(void)
{
    SDC_CMD_STATUS status;

    status = SD_Send_Cmd(SDC_CMD_CMD0, SDC_NO_ARG);
    gSD->mState = IDLE_STA;

    return status;
}

/*************************************************************************
* FUNCTION
*  SD_Cmd55
*
* DESCRIPTION
*	APP_CMD: inidicate to the card that the next command is an application specified command
*			rather than a standard command
*
* PARAMETERS
*	rca: relative card address
*
* RETURNS
*	SDC_CMD_STATUS
*
* GLOBALS AFFECTED
*
* NOTE
*
*************************************************************************/
SDC_CMD_STATUS SD_Cmd55(kal_uint16 rca)
{
    SDC_CMD_STATUS status;

    if ((status = SD_Send_Cmd(SDC_CMD_CMD55, (kal_uint32)rca << 16)) != NO_ERROR)
        return status;

    //read R1
    if ((status = SD_CheckStatus()) != NO_ERROR)
        return status;

    //check APP_CMD bit in status register
    MSDC_LSD_ReadReg32(SDC_RESP0, &status);

#ifdef MSDC_TRACE_LEVEL2
    drv_trace2(TRACE_GROUP_6, MSDC_INFORM_R0, status, __LINE__);
#endif

    if (!(status & R1_APP_CMD_5))
        return ERR_APPCMD_FAILED;

    return NO_ERROR;
}
/*************************************************************************
* FUNCTION
*  SD_Cmd8
*
* DESCRIPTION
*	1. Sends SD Memory Card interface conditions for support larger than 2G cards
*	2. check if the card is compliant to SD2.0 or higher
*	3. only performed while at IDLE state.
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*	gSD->mIsCMD8
*
*************************************************************************/
void SD_Cmd8(void)
{
    kal_uint32 resp;

    if (SD_Send_Cmd(SDC_CMD_CMD8, SDC_CMD8_ARG) != NO_ERROR)
    {
        tst_sys_trace("SD_Cmd8 fail \r\n");
        SD_Reset();
        gSD->mCMD8Resp = SD_CMD8_RESP_NORESP;
        return;
    }

    MSDC_LSD_ReadReg32(SDC_RESP0, &resp);

#ifdef MSDC_TRACE_LEVEL2
    drv_trace2(TRACE_GROUP_6, MSDC_INFORM_R0, resp, __LINE__);
#endif

    if (resp == SDC_CMD8_ARG)
        gSD->mCMD8Resp = SD_CMD8_RESP_VALID;
    else
        gSD->mCMD8Resp = SD_CMD8_RESP_INVALID;
}

/*************************************************************************
* FUNCTION
*  SD_Cmd1_MMC
*
* DESCRIPTION
*	 asks all cards in idle state to send their OCR in the response on the CMD line
*
* PARAMETERS
*
* RETURNS
*	SDC_CMD_STATUS
*
* GLOBALS AFFECTED
*	gSD
*
* NOTE
*	only works for MMC
*
*************************************************************************/
SDC_CMD_STATUS SD_Cmd1_MMC(void)
{
    SDC_CMD_STATUS status;
    kal_uint32 _ocr, ocr_i, t1, t2;

#if defined(SD_MMC_HIGH_DENSITY_SUPPORT)

    if (gSD->mCMD8Resp == SD_CMD8_RESP_INVALID)
        return ERR_CMD8_INVALID;

    ocr_i = (SDC_OCR_DEFAULT | MMC_HIGH_DESITY_CHECK_BIT);
#else
    ocr_i = SDC_OCR_DEFAULT;
#endif

    if (gMSDC_Handle->is_init_timeout == KAL_TRUE)
        return ERR_R3_OCR_BUSY;

    t2 = drv_get_current_time();

    do
    {
        t1 = drv_get_current_time();
        MSDC_START_TIMER(MSDC_TIMEOUT_PERIOD_DAT);

        while ((MSDC_IS_BUSY)
               && MSDC_Check_Card_Present() && !gMSDC_Handle->is_timeout)
        {
            if (drv_get_duration_ms(t1) > MSDC_TIMEOUT_PERIOD_DAT * 11)
                gMSDC_Handle->is_timeout = KAL_TRUE;
        };

        MSDC_STOP_TIMER();

        if (gMSDC_Handle->is_timeout)
            return MSDC_GPT_TIMEOUT_ERR;

#ifdef MSDC_TRACE_LEVEL2
        drv_trace4(TRACE_GROUP_6, MSDC_INFORM_BEFORE_SEND_CMD, MSDC_Reg(SDC_CMDSTA), MSDC_Reg(SDC_DATSTA), MSDC_Reg(SDC_CMD), __LINE__);
#endif

        MSDC_LSD_WriteReg32(SDC_ARG, ocr_i);
        MSDC_LSD_WriteReg32(SDC_CMD, SDC_CMD_CMD1 | sd_cmd_extra);

        if ((status = SD_WaitCmdRdyOrTo())  != NO_ERROR)
        {
            return status;
        }

        MSDC_LSD_ReadReg32(SDC_RESP0, &_ocr);
        drv_trace1(TRACE_GROUP_6, MSDC_INFORM_CMD1OCR, _ocr);

        if ((_ocr & SDC_OCR_DEFAULT) == 0)
            return ERR_OCR_NOT_SUPPORT;

        if (!gMSDC_Handle->mIsPresent)
            return MSDC_CARD_NOT_PRESENT;

        if (!(_ocr & SDC_OCR_BUSY))
        {
            if (drv_get_duration_ms(t2) > MSDC_TIMEOUT_PERIOD_INI)
            {
                gMSDC_Handle->is_init_timeout = KAL_TRUE;
                break;
            }

            if ((kal_query_systemInit() == KAL_TRUE)
#ifdef  __TST_WRITE_TO_FILE__ 			/*error recording: considering error recording additionally*/
                || (KAL_TRUE == INT_QueryExceptionStatus())
#endif
                || KAL_TRUE == FTL_isPollingMode()
               )
            {
                MSDC_GPTI_BusyWait(30);
            }
            else
            {
                kal_sleep_task(7);
            }

        }
        else
            break;
    }
    while (1);

    if (gMSDC_Handle->is_init_timeout)
        return ERR_CMD_TIMEOUT;

#if defined(SD_MMC_HIGH_DENSITY_SUPPORT)

    if ((_ocr & MMC_HIGH_DESITY_CHECK_MSK) == MMC_HIGH_DESITY_CHECK_BIT)
    {
        gSD->flags |= SD_FLAG_HCS_SUPPORT;
        gMSDC_Handle->mMSDC_type = MMC42_CARD;
        tst_sys_trace("MMC4.2 or higher");
    }
    else
#endif
        gMSDC_Handle->mMSDC_type = MMC_CARD;

    gSD->mInactive = KAL_FALSE;
    gSD->mSDC_ocr = _ocr;
    gSD->mState = READY_STA;

    return NO_ERROR;
}

/*************************************************************************
* FUNCTION
*  SD_Acmd41_SD
*
* DESCRIPTION
*	asks all cards in idle state to send their OCR in the response on the CMD line
*	OCR: Operation Condition Register
*
* PARAMETERS
*
* RETURNS
*	SDC_CMD_STATUS
*
* GLOBALS AFFECTED
*	gSD
*
* NOTE
*	only works for SD
*
*************************************************************************/
SDC_CMD_STATUS SD_Acmd41_SD(void)
{

    SDC_CMD_STATUS		status;
    kal_uint32			_ocr = 0, ocr_i = 0, t1, t2;

#if defined(SD_MMC_HIGH_DENSITY_SUPPORT)

    if (gSD->mCMD8Resp == SD_CMD8_RESP_NORESP)
        ocr_i = SDC_OCR_DEFAULT;
    else if (gSD->mCMD8Resp == SD_CMD8_RESP_VALID)
        ocr_i = (SDC_OCR_DEFAULT | SD_ACMD41_HCS);
    else if (gSD->mCMD8Resp == SD_CMD8_RESP_INVALID)
        return ERR_CMD8_INVALID;

#else
    ocr_i = SDC_OCR_DEFAULT;
#endif

    gMSDC_Handle->is_init_timeout = KAL_FALSE;
    t2 = drv_get_current_time();

    do
    {
        t1 = drv_get_current_time();
        MSDC_START_TIMER(MSDC_TIMEOUT_PERIOD_CMD);

        while ((MSDC_IS_BUSY)
               && MSDC_Check_Card_Present() && !gMSDC_Handle->is_timeout)
        {
            if (drv_get_duration_ms(t1) > MSDC_TIMEOUT_PERIOD_CMD * 11)
                gMSDC_Handle->is_timeout = KAL_TRUE;
            else if(drv_get_duration_ms(t1)>10)
                SD_Sleep4Wait(1);
        };

        MSDC_STOP_TIMER();

        if (gMSDC_Handle->is_timeout)
            return MSDC_GPT_TIMEOUT_ERR;

        status = SD_Cmd55(SDC_RCA_DEFAULT);

        if (status != NO_ERROR)
        {
            return status;
        }

        MSDC_START_TIMER(MSDC_TIMEOUT_PERIOD_CMD);
        t1 = drv_get_current_time();

        while ((MSDC_IS_BUSY)
               && MSDC_Check_Card_Present() && !gMSDC_Handle->is_timeout)
        {
            if (drv_get_duration_ms(t1) > MSDC_TIMEOUT_PERIOD_CMD * 11)
                gMSDC_Handle->is_timeout = KAL_TRUE;
            else if(drv_get_duration_ms(t1)>10)
                SD_Sleep4Wait(1);
        };

        MSDC_STOP_TIMER();

        if (gMSDC_Handle->is_timeout)
            return MSDC_GPT_TIMEOUT_ERR;

#ifndef DRV_LSD
        drv_trace4(TRACE_GROUP_6, MSDC_INFORM_BEFORE_SEND_CMD, MSDC_Reg(SDC_CMDSTA), MSDC_Reg(SDC_DATSTA), MSDC_Reg(SDC_CMD), __LINE__);
#endif
        MSDC_LSD_WriteReg32(SDC_ARG, ocr_i);
        MSDC_LSD_WriteReg32(SDC_CMD, SDC_CMD_CMD41_SD | sd_cmd_extra);

        if ((status = SD_WaitCmdRdyOrTo())  != NO_ERROR)
        {
            return status;
        }

        MSDC_LSD_ReadReg32(SDC_RESP0, &_ocr);

#ifdef MSDC_TRACE_LEVEL1
        drv_trace1(TRACE_GROUP_6, MSDC_INFORM_ACMD41OCR, _ocr);
#endif

        if ((_ocr & SDC_OCR_DEFAULT) == 0)
            return ERR_OCR_NOT_SUPPORT;

        if (!gMSDC_Handle->mIsPresent)
            return ERR_CARD_NOT_PRESENT;

        if (!(_ocr & SDC_OCR_BUSY))
        {
            if (drv_get_duration_ms(t2) > MSDC_TIMEOUT_PERIOD_INI)
            {
                gMSDC_Handle->is_init_timeout = KAL_TRUE;
                break;
            }

            if ((kal_query_systemInit() == KAL_TRUE)
#ifdef  __TST_WRITE_TO_FILE__ 			/*error recording: considering error recording additionally*/
                || (KAL_TRUE == INT_QueryExceptionStatus())
#endif
                || KAL_TRUE == FTL_isPollingMode()
               )
            {
                MSDC_GPTI_BusyWait(30);
            }
            else
            {
                kal_sleep_task(7);
            }
        }
        else
            break;
    }
    while (1);

    if (gMSDC_Handle->is_init_timeout)
        return ERR_R3_OCR_BUSY;

    gSD->mInactive = KAL_FALSE;
    gSD->mSDC_ocr = _ocr;
#if defined(SD_MMC_HIGH_DENSITY_SUPPORT)
    gSD->flags |= SD_FLAG_SD_TYPE_CARD;

    if (_ocr & SD_ACMD41_HCS)
    {
        gSD->flags |= SD_FLAG_HCS_SUPPORT;
        gMSDC_Handle->mMSDC_type = SD20_HCS_CARD;
        tst_sys_trace("SD2.0 or higher");
    }
    else if (gSD->mCMD8Resp == SD_CMD8_RESP_VALID)
        gMSDC_Handle->mMSDC_type = SD20_LCS_CARD;
    else
#endif
        gMSDC_Handle->mMSDC_type = SD_CARD;

    gSD->mState = READY_STA;

    return NO_ERROR;
}

/*************************************************************************
* FUNCTION
*  SD_GetCID
*
* DESCRIPTION
*	Read Card Identification.
*
* PARAMETERS
*
* RETURNS
*	SDC_CMD_STATUS
*
* GLOBALS AFFECTED
*	gSD
*
* NOTE
*
*
*************************************************************************/

// Get CID(CMD2)
SDC_CMD_STATUS SD_GetCID(kal_uint32 Cid[4])
{
    int i;
    SDC_CMD_STATUS status;

    if ((status = SD_Send_Cmd(SDC_CMD_CMD2, SDC_NO_ARG)) != NO_ERROR)
        return status;

    //read R2
    for (i = 0; i < 4; i++)
        MSDC_LSD_ReadReg32((SDC_RESP0 + i * sizeof(kal_uint32)), &Cid[i]);

    SD_AnalysisCID(Cid);
    gSD->mState = IDENT_STA;

    return NO_ERROR;
}

/*************************************************************************
* FUNCTION
*  SD_ValidateRCA
*
* DESCRIPTION
*	assing or read RCA
*
* PARAMETERS
*	pRca: used for input or output RCA
*
* RETURNS
*	SDC_CMD_STATUS
*
* GLOBALS AFFECTED
*	gSD
*
* NOTE
*	RCA is assinged to MMC card fixed to SDC_RCA_MMC(1)
*
*************************************************************************/

// assign or read RCA
SDC_CMD_STATUS SD_ValidateRCA(kal_uint16* pRca)
{
    SDC_CMD_STATUS status;
    kal_uint32 resp;
    kal_uint8  state;

#if defined(SD_MMC_HIGH_DENSITY_SUPPORT)

    if (gSD->flags & SD_FLAG_SD_TYPE_CARD )
#else
    if (gMSDC_Handle->mMSDC_type == SD_CARD)
#endif
    {
        //read RCA form card
        if ((status = SD_Send_Cmd(SDC_CMD_CMD3_SD, SDC_NO_ARG)) != NO_ERROR)
            return status;

        //read R6
        MSDC_LSD_ReadReg32(SDC_RESP0, &resp);
#ifdef MSDC_TRACE_LEVEL1
        drv_trace2(TRACE_GROUP_6, MSDC_INFORM_R0, resp, __LINE__);
#endif
        *pRca = resp >>  16;
        gSD->mRCA = *pRca;

    }
    else
    {
        //assign RCA to card
        if ((status = SD_Send_Cmd(SDC_CMD_CMD3_MMC, (kal_uint32)SDC_RCA_MMC << 16)) != NO_ERROR)
            return status;

        //read R1
        MSDC_LSD_ReadReg32(SDC_RESP0, &resp);
#ifdef MSDC_TRACE_LEVEL1
        drv_trace2(TRACE_GROUP_6, MSDC_INFORM_R0, resp, __LINE__);
#endif
        SD_GetStatus(SDC_RCA_MMC, &resp);
        state = 0;
        GetBitFieldN((kal_uint8*)&state, (kal_uint8*)&resp, 9, 4);

        if (STBY_STA != state)
            return ERR_RCA_FAIL;

        *pRca = gSD->mRCA = SDC_RCA_MMC;
    }

    gSD->mState = STBY_STA;
    return NO_ERROR;
}

/*************************************************************************
* FUNCTION
*  SD_SetDSR
*
* DESCRIPTION
*	set default value to the DSR
*
* PARAMETERS
*
* RETURNS
*	SDC_CMD_STATUS
*
* GLOBALS AFFECTED
*
* NOTE
*	SDC_DSR_DEFAULT(0x404)
*
*************************************************************************/
SDC_CMD_STATUS SD_SetDSR(void)
{
    return SD_Send_Cmd(SDC_CMD_CMD4, (kal_uint32)SDC_DSR_DEFAULT << 16);
}

/*************************************************************************
* FUNCTION
*  SD_SelectCard
*
* DESCRIPTION
*	select/deselect card
*
* PARAMETERS
*	rca: relative card address
*
* RETURNS
*	SDC_CMD_STATUS
*
* GLOBALS AFFECTED
*
* NOTE
*
*************************************************************************/
SDC_CMD_STATUS SD_SelectCard(kal_uint16 rca)
{
    SDC_CMD_STATUS status;

    if ((status = SD_Send_Cmd(SDC_CMD_CMD7, (kal_uint32)rca << 16)) != NO_ERROR)
        return status;

    //read R1b
    if ((status = SD_WaitCardNotBusy()) != NO_ERROR)
        return status;

    if ((status = SD_CheckStatus()) != NO_ERROR)
        return status;

    return NO_ERROR;
}

/*************************************************************************
* FUNCTION
*  SD_GetCSD
*
* DESCRIPTION
*	Get CSD from addressed card
*
* PARAMETERS
*	rca: relative card address
*	Csd: used for containing read CSD
*
* RETURNS
*	SDC_CMD_STATUS
*
* GLOBALS AFFECTED
*
* NOTE
*
*************************************************************************/
SDC_CMD_STATUS SD_GetCSD(kal_uint16 rca, kal_uint32 Csd[4])
{
    SDC_CMD_STATUS status;
    kal_uint32 i;

    if ((status = SD_Send_Cmd(SDC_CMD_CMD9, (kal_uint32)rca << 16)) != NO_ERROR)
        return status;

    // read R2
    for (i = 0; i < 4; i++)
    {
#ifndef DRV_LSD
        MSDC_LSD_ReadReg32((volatile kal_uint32 *)(SDC_RESP0 + i * 4), &Csd[i]);
#else
        MSDC_LSD_ReadReg32(SDC_RESP0 + i, &Csd[i]);
#endif
    }

    // analysis CSD...
    SD_AnalysisCSD(Csd);

    return NO_ERROR;
}

// addressed send CID
SDC_CMD_STATUS SD_GetAddressedCID(kal_uint16 rca, kal_uint32 Cid[4])
{
    SDC_CMD_STATUS status;
    kal_uint32 i;

    if ((status = SD_Send_Cmd(SDC_CMD_CMD10, (kal_uint32)rca << 16)) != NO_ERROR)
        return status;

    // read R2
    for (i = 0; i < 4; i++)
    {
#ifndef DRV_LSD
        MSDC_LSD_ReadReg32((volatile kal_uint32 *)(SDC_RESP0 + i * 4), &Cid[i]);
#else
        MSDC_LSD_ReadReg32(SDC_RESP0 + i, &Cid[i]);
#endif
    }

    return NO_ERROR;
}


/*************************************************************************
* FUNCTION
*  SD_StopTrans
*
* DESCRIPTION
*	Stop Muli-Block operation
*
* PARAMETERS
*
* RETURNS
*	SDC_CMD_STATUS
*
* GLOBALS AFFECTED
*
* NOTE
*	definition of SD_STOP_SLOW is used for some erroneous card
*************************************************************************/
SDC_CMD_STATUS SD_StopTrans(kal_bool isTx)
{
    SDC_CMD_STATUS status;
    kal_uint32 retry = 0; 
#if defined(SD_STOP_SLOW) && !defined(DRV_MSDC_STOP_TRANS_WITH_TIMEOUT)
	kal_uint32 whileIndex;
#endif
#if defined(SD_STOP_SLOW) && defined(DRV_MSDC_STOP_TRANS_WITH_TIMEOUT)
    kal_uint32 t1 = 0;
#endif


    while (retry < 30)
    {
#ifdef LSD_STOP_IMMEDIATLY
        extern kal_bool LSD_stoped;

        if (LSD_stoped)
            break;

#endif

        if ((status = SD_Send_Cmd(SDC_CMD_CMD12, SDC_NO_ARG)) != NO_ERROR)
        {
            retry ++;
        }
        else
        {
            break;
        }
    }

    if (retry >= 30)
    {
        return status;
    }

    if (isTx)
        SD_WaitCardNotBusy();


#ifdef SD_STOP_SLOW

#ifdef DRV_MSDC_STOP_TRANS_WITH_TIMEOUT
    t1 = drv_get_current_time();
    MSDC_START_TIMER(MSDC_TIMEOUT_PERIOD_DAT0_LOW);

    while ((SD_IS_R1B_BUSY)
           && MSDC_Check_Card_Present() && !gMSDC_Handle->is_timeout)
    {
        if (drv_get_duration_ms(t1) > MSDC_TIMEOUT_PERIOD_DAT0_LOW * 11)
            gMSDC_Handle->is_timeout = KAL_TRUE;
    };

    MSDC_STOP_TIMER();

    if (gMSDC_Handle->is_timeout)
    {
        tst_sys_trace("MSDC error: [CMD12]DAT line busy over 250ms");
        // ASSERT(0);
        return MSDC_GPT_TIMEOUT_ERR;
    }

    t1 = drv_get_current_time();
    MSDC_START_TIMER(MSDC_TIMEOUT_PERIOD_CARD_NOT_RDY);

    while (MSDC_Check_Card_Present() && !gMSDC_Handle->is_timeout)
    {
        SD_GetStatus(gSD->mRCA, (kal_uint32*)&status);

        //if (((status & R1_CUR_STATE) >> 9) == TRAN_STA)
        if (status & R1_READY_FOR_DATA_8) // fix MAUI_02829325
            break;

        if (KAL_FALSE == kal_query_systemInit() && (KAL_FALSE == INT_QueryExceptionStatus()))
            kal_sleep_task(2);

        if (drv_get_duration_ms(t1) > MSDC_TIMEOUT_PERIOD_CARD_NOT_RDY * 11)
            gMSDC_Handle->is_timeout = KAL_TRUE;
    };

    MSDC_STOP_TIMER();

    if (gMSDC_Handle->is_timeout)
    {
        tst_sys_trace("MSDC error: [CMD12] card not back to TRANSFER state in 2s");
        // ASSERT(0);
        return MSDC_GPT_TIMEOUT_ERR;
    }

#else
    whileIndex = 0x40000;

    while (SD_IS_R1B_BUSY && whileIndex)
        whileIndex--;

    whileIndex = 0x100;

    do
    {
        SD_GetStatus(gSD->mRCA, (kal_uint32*)&status);

        if (((status & R1_CUR_STATE) >> 9) ==  TRAN_STA)
            break;

        if (KAL_FALSE == kal_query_systemInit() && (KAL_FALSE == INT_QueryExceptionStatus()))
        {
            if (KAL_TRUE == FTL_isPollingMode())
            {
                MSDC_GPTI_BusyWait(10);
            }
            else
            {
                kal_sleep_task(2);
            }
        }

        whileIndex--;
    }
    while (0 != whileIndex);

#endif//DRV_MSDC_STOP_TRANS_WITH_TIMEOUT

#endif//SD_STOP_SLOW

    return NO_ERROR;
}

/*************************************************************************
* FUNCTION
*  SD_GetStatus
*
* DESCRIPTION
*	addressed send status
*
* PARAMETERS
*
* RETURNS
*	SDC_CMD_STATUS
*
* GLOBALS AFFECTED
*
* NOTE
*
*************************************************************************/
SDC_CMD_STATUS SD_GetStatus(kal_uint16 rca, kal_uint32* resp)
{
    SDC_CMD_STATUS status;

    if ((status = SD_Send_Cmd(SDC_CMD_CMD13, (kal_uint32)rca << 16)) != NO_ERROR)
        return status;

    MSDC_LSD_ReadReg32(SDC_RESP0, resp);

#ifdef MSDC_TRACE_LEVEL2
    drv_trace2(TRACE_GROUP_6, MSDC_INFORM_R0, *resp, __LINE__);
#endif

    if ((*resp) & SDC_CARD_ECC_FAILED)
    {
#ifdef MSDC_TRACE_LEVEL1
        drv_trace1(TRACE_GROUP_4, MSDC_ERROR_CARDINTERNALECCFAIL, *resp);
#endif
    }

    return NO_ERROR;
}

/*************************************************************************
* FUNCTION
*  SD_SetBlength
*
* DESCRIPTION
*	set block length
*
* PARAMETERS
*	BKLength: block length u want to set
*
* RETURNS
*	SDC_CMD_STATUS
*
* GLOBALS AFFECTED
*	gSD->mBKLength
*
* NOTE
*
*************************************************************************/
SDC_CMD_STATUS SD_SetBlength(kal_uint32 BKLength)
{
    SDC_CMD_STATUS status;

    // maximal value of block length is 2048
    if (BKLength > SDC_MAX_BKLENGTH)
        return ERR_INVALID_BKLENGTH;

    if (!gSD->mCSD.r_blk_part && BKLength < gSD->mCSD.max_r_blk_len )
        return ERR_INVALID_BKLENGTH;

    if ((status = SD_Send_Cmd(SDC_CMD_CMD16, BKLength)) != NO_ERROR)
        return status;

    //read R1
    status = SD_CheckStatus();
    // 2. configure the controller
    gSD->mBKLength = BKLength;
    BitFieldWrite32((kal_uint32*)SDC_CFG, BKLength, SDC_CFG_BLKLEN);

    return NO_ERROR;
}


/*************************************************************************
* FUNCTION
*  SD_ReadSingleBlock
*
* DESCRIPTION
*	1. read a single block form data_adrs of card to the rxbuffer
*	2. the block length is set by set block length
*
* PARAMETERS
*	data_adrs: starting address to read
*	rxbuffer: as name
*
* RETURNS
*	SDC_CMD_STATUS
*
* GLOBALS AFFECTED
*
* NOTE
*	the size of rxbuffer should be 4*n (n : integer)
*
*************************************************************************/
#ifdef DRV_MSDC_SLIM
SDC_CMD_STATUS SD_ReadSingleBlock(kal_uint32 data_adrs, kal_uint32* rxbuffer) // slim
{
    return SD_ReadMultiBlock(data_adrs, rxbuffer, 1); // slim
}
#else
SDC_CMD_STATUS SD_ReadSingleBlock(kal_uint32 data_adrs, kal_uint32* rxbuffer)
{
    kal_uint32 count, whileIndex;
    SDC_CMD_STATUS status;


    EnableMSDC_DMA();
    count = MSDC_SD_BLOCK_SIZE;
    MSDC_DMATransferFirst((kal_uint32)rxbuffer, count, KAL_FALSE);
#ifdef DRV_LSD
    LSD_HostSetBuffer((kal_uint8 *)rxbuffer);
#endif

    if ((status = SD_Send_Cmd(SDC_CMD_CMD17, data_adrs)) != NO_ERROR)
        goto ERR_Exit;

    if ((status = SD_CheckStatus()) != NO_ERROR)
        goto ERR_Exit;

    status = MSDC_DMATransferFinal();

    if (status != NO_ERROR)
    {
#if defined(MSDC_TRACE_LEVEL3)
        MSDC_add_dbg_msg(msdc_dbg_event_SD_datTimeOut_sta, MSDC_Reg(SDC_DATSTA), gMSDC_Handle->dat_sta);
#endif
        goto ERR_Exit;
    }

    if ((status = SD_WaitDatRdyOrTo()) != NO_ERROR)
        goto ERR_Exit;

    DisableMSDC_DMA();
    MSDC_CLR_FIFO();

#ifdef SD_STOP_SLOW
    {
        kal_uint32 cardStatus;
        whileIndex = 0x40000;

        while (SD_IS_R1B_BUSY && whileIndex)
            whileIndex--;

        whileIndex = 0x100;

        do
        {
            status = SD_GetStatus(gSD->mRCA, (kal_uint32*)&cardStatus);

            if (NO_ERROR != status)
            {
                tst_sys_trace("[MSDC]CMD13 fail when singleBlockRead!");
                goto ERR_Exit;
            }

            whileIndex--;
        }
        while (((cardStatus & R1_CUR_STATE) >> 9 !=  TRAN_STA) && (0 != whileIndex));
    }
#endif

#ifdef MSDC_SYNC_CLEAR
    RESET_MSDC();
#endif
    return NO_ERROR;
ERR_Exit:
    {
        kal_uint32 tmp;

#ifdef MSDC_USE_INT
        kal_set_eg_events(gMSDC_Handle->MSDC_Events, 0, KAL_AND);
#endif
        DisableMSDC_DMA();
        RESET_MSDC();

        // SD_StopTrans(KAL_FALSE);
        SD_GetStatus(gSD->mRCA, (kal_uint32*)&tmp);
        MSDC_LSD_ReadReg32(SDC_DATSTA, &tmp);
        MSDC_CLR_FIFO();
        return status;
    }

}
#endif
/*************************************************************************
* FUNCTION
*  SD_ReadMultiBlock
*
* DESCRIPTION
*	read num of blocks into rxbuffer
*
* PARAMETERS
*	data_adrs: starting address to read
*	rxbuffer: as name
*	num: number of blocks to read
*
* RETURNS
*	SDC_CMD_STATUS
*
* GLOBALS AFFECTED
*
* NOTE
*
*************************************************************************/
#ifdef DRV_MSDC_SLIM
SDC_CMD_STATUS SD_ReadMultiBlock(kal_uint32 data_adrs, kal_uint32* rxbuffer, kal_uint32 num) // slim
{
    SDC_CMD_STATUS status;
    kal_uint32 j, count , whileIndex;
#ifndef MSDC_DMA
    kal_uint32 i;
#endif

    EnableMSDC_DMA();
    count = MSDC_SD_BLOCK_SIZE;
    MSDC_DMATransferFirst((kal_uint32)rxbuffer, count * num, KAL_FALSE);
#ifndef DRV_LSD
    //read out data sta to make sure we will read latest one in the future
    gMSDC_Handle->dat_sta = MSDC_Reg(SDC_DATSTA);

    if ((status = SD_Send_Cmd((num == 1 ? SDC_CMD_CMD17 : SDC_CMD_CMD18), data_adrs)) != NO_ERROR)
#else
    if (num > SD_CMD_MAX_BLOCK_NUM)
        ASSERT(0);

    LSD_HostSetBuffer((kal_uint8 *)rxbuffer);

    if ((status = SD_Send_Cmd((num == 1 ? SDC_CMD_CMD17 : SDC_CMD_CMD18) | (num << 16) , data_adrs)) != NO_ERROR)
#endif
        goto ERR_Exit;

    if ((status = SD_CheckStatus()) != NO_ERROR)
        goto ERR_Exit;

    count = MSDC_SD_BLOCK_SIZE;
    status = MSDC_DMATransferFinal();

    if (status != NO_ERROR)
    {
        gMSDC_Handle->dat_sta = MSDC_Reg(SDC_DATSTA);

#ifdef MSDC_TRACE_LEVEL3
        MSDC_add_dbg_msg(msdc_dbg_event_SD_datTimeOut_sta, MSDC_Reg(DMA_RLCT(gMSDC_Handle->msdc_dmaport)), gMSDC_Handle->dat_sta);
#endif

        if (gMSDC_Handle->dat_sta & SDC_DATSTA_DATTO)
        {
#ifdef MSDC_TRACE_LEVEL1
            //tst_sys_trace("[MSDC]:dat timeout");
#endif
        }

        if (gMSDC_Handle->dat_sta & SDC_DATSTA_DATCRCERR)
        {
#ifdef MSDC_TRACE_LEVEL1
            //tst_sys_trace("[MSDC]:dat crc");
#endif
        }

#ifdef MSDC_TRACE_LEVEL1
        drv_trace1(TRACE_GROUP_5, MSDC_FAIL_CMD18_DMA_TRANSFER, gMSDC_Handle->dat_sta);
#endif
        goto ERR_Exit;
    }

    if ((status = SD_WaitDatRdyOrTo()) != NO_ERROR)
        goto ERR_Exit;


    MSDC_CLR_INT();
    DisableMSDC_DMA();

    if (num == 1)
    {
#ifdef SD_STOP_SLOW
        {
            kal_uint32 cardStatus;
            whileIndex = 0x40000;

            while (SD_IS_R1B_BUSY && whileIndex)
                whileIndex--;

            whileIndex = 0x100;

            do{
                status = SD_GetStatus(gSD->mRCA, (kal_uint32*)&cardStatus);

                if (NO_ERROR != status)
                {
                    //tst_sys_trace("[MSDC]CMD13 fail when singleBlockRead!");
                    goto ERR_Exit;
                }

                whileIndex--;
            }
            while (((cardStatus & R1_CUR_STATE) >> 9 !=  TRAN_STA) && (0 != whileIndex));
        }
#endif
    }
    else
    {
        if (gSD->flags & SD_FLAG_MMC_MRSW_FAIL)
        {
            kal_uint32 delay = 200;

            while (delay--);
        }

        if ((status = SD_StopTrans(KAL_FALSE)) != NO_ERROR)
        {
            //if((data_adrs/gSD->mBKLength + j) < gSD->mBKNum)
            goto ERR_Exit;
        }
    }

    MSDC_CLR_FIFO();

#ifdef MSDC_SYNC_CLEAR
    RESET_MSDC();
#endif
    return NO_ERROR;

ERR_Exit:

#ifdef MSDC_USE_INT
    kal_set_eg_events(gMSDC_Handle->MSDC_Events, 0, KAL_AND);
#endif
    DisableMSDC_DMA();
    RESET_MSDC();

    if (num > 1)
        SD_StopTrans(KAL_FALSE);

    SD_GetStatus(gSD->mRCA, (kal_uint32*)&j);
    MSDC_LSD_ReadReg32(SDC_DATSTA, &j);
    MSDC_CLR_FIFO();
    return status;

}
#else
SDC_CMD_STATUS SD_ReadMultiBlock(kal_uint32 data_adrs, kal_uint32* rxbuffer, kal_uint32 num)
{
    SDC_CMD_STATUS status;
    kal_uint32 j, count;
#ifndef MSDC_DMA
    kal_uint32 i;
#endif

    EnableMSDC_DMA();
    count = MSDC_SD_BLOCK_SIZE;
    MSDC_DMATransferFirst((kal_uint32)rxbuffer, count * num, KAL_FALSE);
#ifndef DRV_LSD
    //read out data sta to make sure we will read latest one in the future
    gMSDC_Handle->dat_sta = MSDC_Reg(SDC_DATSTA);

    if ((status = SD_Send_Cmd(SDC_CMD_CMD18, data_adrs)) != NO_ERROR)
#else
    if (num > SD_CMD_MAX_BLOCK_NUM)
        ASSERT(0);

    LSD_HostSetBuffer((kal_uint8 *)rxbuffer);

    if ((status = SD_Send_Cmd(SDC_CMD_CMD18 | (num << 16) , data_adrs)) != NO_ERROR)
#endif
        goto ERR_Exit;

    if ((status = SD_CheckStatus()) != NO_ERROR)
        goto ERR_Exit;

    count = MSDC_SD_BLOCK_SIZE;
    status = MSDC_DMATransferFinal();

    if (status != NO_ERROR)
    {
        gMSDC_Handle->dat_sta = MSDC_Reg(SDC_DATSTA);

#ifdef MSDC_TRACE_LEVEL3
        MSDC_add_dbg_msg(msdc_dbg_event_SD_datTimeOut_sta, MSDC_Reg(DMA_RLCT(gMSDC_Handle->msdc_dmaport)), gMSDC_Handle->dat_sta);
#endif

        if (gMSDC_Handle->dat_sta & SDC_DATSTA_DATTO)
        {
#ifdef MSDC_TRACE_LEVEL1
            tst_sys_trace("[MSDC]:dat timeout");
#endif
        }

        if (gMSDC_Handle->dat_sta & SDC_DATSTA_DATCRCERR)
        {
#ifdef MSDC_TRACE_LEVEL1
            tst_sys_trace("[MSDC]:dat crc");
#endif
        }

#ifdef MSDC_TRACE_LEVEL1
        drv_trace1(TRACE_GROUP_5, MSDC_FAIL_CMD18_DMA_TRANSFER, gMSDC_Handle->dat_sta);
#endif
        goto ERR_Exit;
    }

    if ((status = SD_WaitDatRdyOrTo()) != NO_ERROR)
        goto ERR_Exit;


    MSDC_CLR_INT();
    DisableMSDC_DMA();

    if (gSD->flags & SD_FLAG_MMC_MRSW_FAIL)
    {
        kal_uint32 delay = 200;

        while (delay--);
    }

    if ((status = SD_StopTrans(KAL_FALSE)) != NO_ERROR)
    {
        //if((data_adrs/gSD->mBKLength + j) < gSD->mBKNum)
        goto ERR_Exit;
    }

    MSDC_CLR_FIFO();

#ifdef MSDC_SYNC_CLEAR
    RESET_MSDC();
#endif
    return NO_ERROR;

ERR_Exit:

#ifdef MSDC_USE_INT
    kal_set_eg_events(gMSDC_Handle->MSDC_Events, 0, KAL_AND);
#endif
    DisableMSDC_DMA();
    RESET_MSDC();
    SD_StopTrans(KAL_FALSE);
    SD_GetStatus(gSD->mRCA, (kal_uint32*)&j);
    MSDC_LSD_ReadReg32(SDC_DATSTA, &j);
    MSDC_CLR_FIFO();
    return status;

}
#endif


#if defined(MT6255)
//__attribute__ ((section ("EXT_BOOTLOADER_CODE"))) SDC_CMD_STATUS SD_DummySingleWrite(kal_uint32 address, kal_uint32 *buf)
SDC_CMD_STATUS SD_DummySingleWrite(kal_uint32 address, kal_uint32 *buf)
{
    SDC_CMD_STATUS status;
    kal_uint32 count;

    RESET_MSDC();
    EnableMSDC_DMA();
    count = MSDC_SD_BLOCK_SIZE;

    MSDC_DMATransferFirst((kal_uint32)buf, count, KAL_TRUE);

    if ((status = SD_Send_Cmd(SDC_CMD_CMD24, address)) != NO_ERROR)
        return status;

    if ((status = SD_CheckStatus()) != NO_ERROR)
        return status;

    status = MSDC_DMATransferFinal();

    if (status != NO_ERROR)
        return status;

    // wait R1b interrupt because cmd24 is configured as R1b response but cmd25 needn't
    if ((status = SD_WaitCardNotBusy()) != NO_ERROR)
        return status;

    if ((status = SD_WaitDatRdyOrTo()) != NO_ERROR)
        return status;

    DisableMSDC_DMA();
    MSDC_CLR_FIFO();

    return NO_ERROR;
}
#endif

/*************************************************************************
* FUNCTION
*  SD_WriteSingleBlock
*
* DESCRIPTION
*	write a single block
*
* PARAMETERS
*	address: starting address to write
*	txbuffer: as name
*
* RETURNS
*	SDC_CMD_STATUS
*
* GLOBALS AFFECTED
*
* NOTE
*	block length is set by Set_Block_Length
*
*************************************************************************/
#ifdef DRV_MSDC_SLIM
//__attribute__ ((section ("EXT_BOOTLOADER_CODE"))) SDC_CMD_STATUS SD_WriteSingleBlock(kal_uint32 address, kal_uint32* txbuffer) // slim
SDC_CMD_STATUS SD_WriteSingleBlock(kal_uint32 address, kal_uint32* txbuffer)
{
    return SD_WriteMultiBlock(address, txbuffer, 1); // slim
}
#else
//__attribute__ ((section ("EXT_BOOTLOADER_CODE"))) SDC_CMD_STATUS SD_WriteSingleBlock(kal_uint32 address, kal_uint32* txbuffer)
SDC_CMD_STATUS SD_WriteSingleBlock(kal_uint32 address, kal_uint32* txbuffer)
{
    SDC_CMD_STATUS status;
    kal_uint32 count, whileIndex;
#ifdef DRV_MSDC_FORCE_WAIT_FOR_PROG_R1B_MALFUNCTION
    kal_uint32 cardStatus = 0;
    kal_uint32 t1 = 0;
#endif
    kal_uint32 *ptr;
#if defined(MT6225)
    kal_bool is_aligned;
    ECO_VERSION eco;
    eco = INT_ecoVersion();
#endif

#ifdef DRV_MSDC_2_DLT_FOR_RD_WR
    kal_uint32 triedDLTTimes = 0;

retryDLT:
#endif

    if (gSD->mWPEnabled)
        return ERR_WRITE_PROTECT;

    EnableMSDC_DMA();
    count = MSDC_SD_BLOCK_SIZE;

#if defined(MT6225)

    if (eco <= ECO_E3)
    {
        is_aligned = ((kal_uint32)txbuffer % 4 == 0);

        if (is_aligned)
        {
            ptr = txbuffer;
        }
        else
        {
            kal_mem_cpy(MSDC_Sector, txbuffer, 512);
            ptr = MSDC_Sector;
        }
    }
    else
    {
        ptr = txbuffer;
    }

#else
    ptr = txbuffer;
#endif

#if defined(MT6255)

    //
    // Apply dummy write solution at 6255E1, E2 and E3.
    //
    if ((INT_SW_SecVersion() == SW_SEC_0 ) ||
        (INT_SW_SecVersion() == SW_SEC_1 )
       )
    {

        status = SD_DummySingleWrite(address, txbuffer);

        if (status != NO_ERROR)
        {
            tst_sys_trace("Dummy write fail");
            goto ERR_Exit;
        }
    }

#endif
    EnableMSDC_DMA();
    count = MSDC_SD_BLOCK_SIZE;
    MSDC_DMATransferFirst((kal_uint32)ptr, count, KAL_TRUE);
#ifdef DRV_LSD
    LSD_HostSetBuffer((kal_uint8 *)txbuffer);
#endif

    if ((status = SD_Send_Cmd(SDC_CMD_CMD24, address)) != NO_ERROR)
        goto ERR_Exit;

    if ((status = SD_CheckStatus()) != NO_ERROR)
        goto ERR_Exit;

    status = MSDC_DMATransferFinal();

    if (status != NO_ERROR)
        goto ERR_Exit;

    // wait R1b interrupt because cmd24 is configured as R1b response but cmd25 needn't
    if ((status = SD_WaitCardNotBusy()) != NO_ERROR)
        goto ERR_Exit;

    DisableMSDC_DMA();

    if ((status = SD_WaitDatRdyOrTo()) != NO_ERROR)
    {
        if (ERR_DAT_CRCERR == status
#ifdef MSDC_DEFECT_WRITE_CRCERR	// WHQA_0006199 workaround for MT6236E2 write crc not reported (solution 2)
            || MSDC_GPT_TIMEOUT_ERR == status //write crc not reported
#endif
           )
        {
            tst_sys_trace("[MSDC]:dat crc");
#ifdef DRV_MSDC_FORCE_WAIT_FOR_PROG_R1B_MALFUNCTION
            // it's a fake crc error reported due to mis-latch, and R1b is useless.
            kal_sleep_task(55);	// wait for 250 ms (the largest period of programming from spec)

            t1 = drv_get_current_time();
            MSDC_START_TIMER(MSDC_TIMEOUT_PERIOD_CARD_NOT_RDY);

            while (MSDC_Check_Card_Present() && !gMSDC_Handle->is_timeout)
            {
                SD_GetStatus(gSD->mRCA, (kal_uint32*)&cardStatus);

                if (((cardStatus & R1_CUR_STATE) >> 9) == TRAN_STA)
                    break;

                if (KAL_FALSE == kal_query_systemInit() && (KAL_FALSE == INT_QueryExceptionStatus()))
                    kal_sleep_task(2);

                if (drv_get_duration_ms(t1) > MSDC_TIMEOUT_PERIOD_CARD_NOT_RDY * 11)
                    gMSDC_Handle->is_timeout = KAL_TRUE;
            };

            MSDC_STOP_TIMER();

            if (gMSDC_Handle->is_timeout)
            {
                tst_sys_trace("MSDC error: [CMD24] card not back to TRANSFER state in 2s");
                //ASSERT(0);
                return MSDC_GPT_TIMEOUT_ERR;
            }

#endif
#ifdef DRV_MSDC_2_DLT_FOR_RD_WR

            /*remove this assertion, it is reasonable for card to go into prg state now*/
            //if(SD_IS_SDC_BUSY)
            //ASSERT(0);
            /*we record tried DLT here, no matter DLT pass or fail in this test is recorded*/
            if (triedDLTTimes < 3)
            {

                /**/
                if (MSDC_DLT_NOT_TESTED == gMSDC_Handle->msdc_clkTuneTriedWr)
                    gMSDC_Handle->msdc_clkTuneTriedWr = 0;

                /*this is single block write, so we don't need to send CMD12*/
                DisableMSDC_DMA();

                /*find a DLT and change to it*/
                {
                    kal_uint32 searchDLTIndex = 0;
                    kal_uint32 testingRED = 0, testingDLT = 0;

                    while ((gMSDC_Handle->msdc_clkTuneTriedWr & (1 << searchDLTIndex)) && (32 > searchDLTIndex))
                    {
                        searchDLTIndex ++;

                        //all of DLT is used for RED = 0 case, search RED = 1 cases
                        if (searchDLTIndex == (gMSDC_Handle->msdc_clock / gMSDC_Handle->op_clock))
                            searchDLTIndex = 16;
                    }

                    if (31 < searchDLTIndex)
                        goto ERR_Exit;

                    /*there is some DLT unused, try it*/
                    testingRED = (16 > searchDLTIndex) ? 0 : 1;
                    testingDLT = searchDLTIndex - ((1 == testingRED) ? 16 : 0) + 1 ;
                    gMSDC_Handle->msdc_clkTuneTriedWr |= (1 << searchDLTIndex);
                    gMSDC_Handle->msdc_RedDlt_forWr =  (testingRED << 16) + testingDLT;
                    BitFieldWrite32((kal_uint32*)MSDC_CFG, (kal_uint32)testingRED, MSDC_CFG_CRED);
#if defined(DRV_MSDC_LATCH_MT6276_SERIES)
#else
                    BitFieldWrite32((kal_uint32*)MSDC_IOCON, testingDLT, MSDC_IOCON_DLT);
#endif//#if defined(DRV_MSDC_LATCH_MT6276_SERIES)
                }

                triedDLTTimes ++;

                /*retry again*/
                goto retryDLT;

            }

#endif
        }
        else if (ERR_DAT_TIMEOUT == status)
            ASSERT(0);

        goto ERR_Exit;
    }

#ifdef SD_STOP_SLOW
    {
        kal_uint32 cardStatus;
        //wait 1.2s at moust.
        whileIndex = 0x100;

        while (SD_IS_R1B_BUSY && whileIndex)
        {
            if ((kal_query_systemInit() == KAL_TRUE)
#ifdef  __TST_WRITE_TO_FILE__ 			/*error recording: considering error recording additionally*/
                || (KAL_TRUE == INT_QueryExceptionStatus())
#endif
                || KAL_TRUE == FTL_isPollingMode()
               )
            {
                MSDC_GPTI_BusyWait(4);
            }
            else
            {
                kal_sleep_task(1);
            }

            whileIndex--;
        }

        whileIndex = 0x100;

        do
        {
            status = SD_GetStatus(gSD->mRCA, (kal_uint32*)&cardStatus);

            if (NO_ERROR != status)
            {
                tst_sys_trace("[MSDC]CMD13 fail when singleBlockWrite!");
                goto ERR_Exit;
            }

            whileIndex--;
        }
        while (((cardStatus & R1_CUR_STATE) >> 9 !=  TRAN_STA) && (0 != whileIndex));
    }
#endif

    return NO_ERROR;
ERR_Exit:
    {
        kal_uint32 tmp;

#ifdef MSDC_USE_INT
        kal_set_eg_events(gMSDC_Handle->MSDC_Events, 0, KAL_AND);
#endif
        DisableMSDC_DMA();
        RESET_MSDC();
        //SD_StopTrans(KAL_TRUE);
        SD_GetStatus(gSD->mRCA, (kal_uint32*)&tmp);
        MSDC_LSD_ReadReg32(SDC_DATSTA, &tmp);
        return status;
    }

}
#endif

void SD_Sleep4Wait(kal_int32 sleep_tick)
{
    if ((kal_query_systemInit() == KAL_TRUE)
#ifdef  __TST_WRITE_TO_FILE__ 			/*error recording: considering error recording additionally*/
                || (KAL_TRUE == INT_QueryExceptionStatus())
#endif
                || KAL_TRUE == FTL_isPollingMode()
        )
        {
             while(sleep_tick>0)
             {
                //MSDC_GPTI_BusyWait(30);
                ust_busy_wait(4615);
                sleep_tick--;
             }
        }
        else
        {
             kal_sleep_task(sleep_tick);
        }
}
/*************************************************************************
* FUNCTION
*	SD_WriteMultiBlock
*
* DESCRIPTION
*	write num blocks starting at address
*
* PARAMETERS
*	address: starting address to write
*	txbuffer: as name
*	num: number of blocks to write
*
* RETURNS
*	SDC_CMD_STATUS
*
* GLOBALS AFFECTED
*
* NOTE
*	block length is set by Set_Block_Length
*
*************************************************************************/
#ifndef DRV_MSDC_SLIM
//__attribute__ ((section ("EXT_BOOTLOADER_CODE"))) SDC_CMD_STATUS SD_WriteMultiBlock(kal_uint32 address, kal_uint32* txbuffer, kal_uint32 num)
SDC_CMD_STATUS SD_WriteMultiBlock(kal_uint32 address, kal_uint32* txbuffer, kal_uint32 num)
{
    SDC_CMD_STATUS status;
    kal_uint32 count;
#ifdef DRV_MSDC_2_DLT_FOR_RD_WR
    kal_uint32 triedDLTTimes = 0;

retryDLT:
#endif



#if defined(MT6225)
    kal_uint32 *ptr;
#elif defined(MSDC_MULTI_BLOCK_WRITE)
#else
    kal_uint32 *ptr;
#endif

#if defined(MT6225)
    kal_bool is_aligned, dma_issue;
    ECO_VERSION eco;

    is_aligned = KAL_FALSE;
    dma_issue = KAL_FALSE;
    ptr = txbuffer;
    eco = INT_ecoVersion();

    if (eco <= ECO_E3)
        dma_issue = KAL_TRUE;

#endif

    if (gSD->mWPEnabled)
        return ERR_WRITE_PROTECT;

#if defined(MT6255)

    if ((INT_SW_SecVersion() == SW_SEC_0 ) ||
        (INT_SW_SecVersion() == SW_SEC_1 )
       )
    {

        status = SD_DummySingleWrite(address, txbuffer);

        if (status != NO_ERROR)
        {
            tst_sys_trace("Dummy write fail");
            goto ERR_Exit;
        }
    }

#endif
    EnableMSDC_DMA();
    count = MSDC_SD_BLOCK_SIZE;
#if defined(MT6225)

    if (dma_issue)
    {
        is_aligned = ((kal_uint32)txbuffer % 4 == 0);

        if (is_aligned)
        {
            MSDC_DMATransferFirst((kal_uint32)txbuffer, count * num, KAL_TRUE);
        }
        else
        {
            kal_mem_cpy(MSDC_Sector, txbuffer, 512);
            ptr = txbuffer;
            MSDC_DMATransferFirst((kal_uint32)MSDC_Sector, count, KAL_TRUE);
        }
    }
    else
    {
        MSDC_DMATransferFirst((kal_uint32)txbuffer, count * num, KAL_TRUE);
    }

#elif defined(MSDC_MULTI_BLOCK_WRITE)
    MSDC_DMATransferFirst((kal_uint32)txbuffer, count * num, KAL_TRUE);
#else
    ptr = txbuffer;
    MSDC_DMATransferFirst((kal_uint32)ptr, count, KAL_TRUE);
#endif
#ifndef DRV_LSD

    if ((status = SD_Send_Cmd(SDC_CMD_CMD25, address)) != NO_ERROR)
#else
    if (num > SD_CMD_MAX_BLOCK_NUM)
        ASSERT(0);

    LSD_HostSetBuffer((kal_uint8 *)txbuffer);

    if ((status = SD_Send_Cmd(SDC_CMD_CMD25 | (num << 16) , address)) != NO_ERROR)
#endif
        goto ERR_Exit;

    if ((status = SD_CheckStatus()) != NO_ERROR)
        goto ERR_Exit;

#if defined(MT6225)

    if (dma_issue)
    {
        if (is_aligned)
        {
            status = MSDC_DMATransferFinal();

            if (status != NO_ERROR)
                goto ERR_Exit;

            if ((status = SD_WaitDatRdyOrTo()) != NO_ERROR)
                goto ERR_Exit;
        }
        else
        {
            kal_uint32 j;

            for (j = 0; j < num; j++)
            {
                if (gMSDC_Handle->mIsPresent  == KAL_FALSE)
                {
                    status = ERR_CARD_NOT_PRESENT;
                    goto ERR_Exit;
                }

                if (j != 0)
                {
                    kal_mem_cpy(MSDC_Sector, ptr, 512);
                    MSDC_DMATransferFirst((kal_uint32)MSDC_Sector, count, KAL_TRUE);
                }

                status = MSDC_DMATransferFinal();
#ifdef __DRV_MSDC_FAST_FORMAT__

                if (KAL_FALSE == gMSDC_Handle->MSDC_fastFormat)
#endif
                    ptr += MSDC_SD_BLOCK_SIZE;

                if (status != NO_ERROR)
                    goto ERR_Exit;

                if ((status = SD_WaitDatRdyOrTo()) != NO_ERROR)
                    goto ERR_Exit;
            }
        }
    }
    else
    {
        status = MSDC_DMATransferFinal();

        if (status != NO_ERROR)
            goto ERR_Exit;

        if ((status = SD_WaitDatRdyOrTo()) != NO_ERROR)
            goto ERR_Exit;
    }

#elif defined(MSDC_MULTI_BLOCK_WRITE) /*chips after MT6225 goes this way, 35,38,16, 53,..*/
    status = MSDC_DMATransferFinal();

    if (status != NO_ERROR)
    {
#if defined(MSDC_TRACE_LEVEL3)
        MSDC_add_dbg_msg(msdc_dbg_event_SD_multi_blk_write_issue1, MSDC_Reg(DMA_RLCT(gMSDC_Handle->msdc_dmaport)), status);
#endif
        //sd_writeFailReason = 1;
        gMSDC_Handle->dat_sta = MSDC_Reg(SDC_DATSTA);
#if 0	// to prevent from WHQA_0006199 happened again
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

        if (gMSDC_Handle->dat_sta & SDC_DATSTA_DATTO)
            ASSERT(0);

        if (gMSDC_Handle->dat_sta & SDC_DATSTA_DATCRCERR
#ifdef MSDC_DEFECT_WRITE_CRCERR	// WHQA_0006199 workaround for MT6236E2 write crc not reported (solution 2)
            || (MSDC_Reg(SDC_STA) & (SDC_STA_FEDATBUSY | SDC_STA_DATBUSY)) == SDC_STA_DATBUSY
#endif
           )
        {
            tst_sys_trace("[MSDC]:dat crc");
#ifdef DRV_MSDC_2_DLT_FOR_RD_WR

            /*remove this assertion, it is reasonable for card to go into prg state now*/
            //if(SD_IS_SDC_BUSY)
            //ASSERT(0);
            /*we record tried DLT here, no matter DLT pass or fail in this test is recorded*/
            if (triedDLTTimes < 3)
            {

                /**/
                if (MSDC_DLT_NOT_TESTED == gMSDC_Handle->msdc_clkTuneTriedWr)
                    gMSDC_Handle->msdc_clkTuneTriedWr = 0;

                /*should we send stop here? Of course, since card may still in receiving state if he doesn't have crc error event internally*/
                /*send CMD12*/
                DisableMSDC_DMA();

                if ((status = SD_StopTrans(KAL_TRUE)) != NO_ERROR)
                {
                    tst_sys_trace("[MSDC]retry DLT but Stop failed");
                    goto ERR_Exit;
                }

                /*find a DLT and change to it*/
                {
                    kal_uint32 searchDLTIndex = 0;
                    kal_uint32 testingRED = 0, testingDLT = 0;

                    while ((gMSDC_Handle->msdc_clkTuneTriedWr & (1 << searchDLTIndex)) && (32 > searchDLTIndex))
                    {
                        searchDLTIndex ++;

                        //all of DLT is used for RED = 0 case, search RED = 1 cases
                        if (searchDLTIndex == (gMSDC_Handle->msdc_clock / gMSDC_Handle->op_clock))
                            searchDLTIndex = 16;
                    }

                    if (31 < searchDLTIndex)
                        goto ERR_Exit;

                    /*there is some DLT unused, try it*/
                    testingRED = (16 > searchDLTIndex) ? 0 : 1;
                    testingDLT = searchDLTIndex - ((1 == testingRED) ? 16 : 0) + 1 ;
                    gMSDC_Handle->msdc_clkTuneTriedWr |= (1 << searchDLTIndex);
                    gMSDC_Handle->msdc_RedDlt_forWr =  (testingRED << 16) + testingDLT;
                    BitFieldWrite32((kal_uint32*)MSDC_CFG, (kal_uint32)testingRED, MSDC_CFG_CRED);
#if defined(DRV_MSDC_LATCH_MT6276_SERIES)
#else
                    BitFieldWrite32((kal_uint32*)MSDC_IOCON, testingDLT, MSDC_IOCON_DLT);
#endif//#if defined(DRV_MSDC_LATCH_MT6276_SERIES)
                }
                /*following comes from 1682190, flush the FIFO in MSDC before retry DLT*/
                RESET_MSDC();

                if (MSDC_Reg(MSDC_STA) & MSDC_STA_FIFOCNT)
                    ASSERT(0);

                triedDLTTimes ++;

                /*retry again*/
                goto retryDLT;

            }

#endif
        }

        goto ERR_Exit;
    }

    if ((status = SD_WaitDatRdyOrTo()) != NO_ERROR)
    {
#if defined(MSDC_TRACE_LEVEL3)
        MSDC_add_dbg_msg(msdc_dbg_event_SD_multi_blk_write_issue2, status, 0);
#endif
        //sd_writeFailReason = 2;
        goto ERR_Exit;
    }

#else // not MT6225
    {
        kal_uint32 j;

        for (j = 0; j < num; j++)
        {
            if (gMSDC_Handle->mIsPresent  == KAL_FALSE)
            {
                status = ERR_CARD_NOT_PRESENT;
                goto ERR_Exit;
            }

            if (j != 0)
            {
                MSDC_DMATransferFirst((kal_uint32)ptr, count, KAL_TRUE);
            }

            status = MSDC_DMATransferFinal();

            /*in MSDC ealier than MT6225, the DAM run in different way and we have to take care the buffer pointer*/
#ifdef __DRV_MSDC_FAST_FORMAT__

            if (KAL_FALSE == gMSDC_Handle->MSDC_fastFormat)
#endif
                ptr += MSDC_SD_BLOCK_SIZE;

            if (status != NO_ERROR)
                goto ERR_Exit;

            if ((status = SD_WaitDatRdyOrTo()) != NO_ERROR)
                goto ERR_Exit;
        }

    }
#endif // MT6225

    DisableMSDC_DMA();

    if ((status = SD_StopTrans(KAL_TRUE)) != NO_ERROR)
        goto ERR_Exit;

    MSDC_CLR_INT();
#ifdef MSDC_USE_INT
    kal_set_eg_events(gMSDC_Handle->MSDC_Events, 0, KAL_AND);
#endif

    return NO_ERROR;
ERR_Exit:
    {
        kal_uint32 tmp;

#ifdef MSDC_USE_INT
        kal_set_eg_events(gMSDC_Handle->MSDC_Events, 0, KAL_AND);
#endif
        DisableMSDC_DMA();
        RESET_MSDC();
        SD_StopTrans(KAL_TRUE);
        SD_GetStatus(gSD->mRCA, (kal_uint32*)&tmp);
        MSDC_LSD_ReadReg32(SDC_DATSTA, &tmp);
        return status;
    }

}
#else
//__attribute__ ((section ("EXT_BOOTLOADER_CODE"))) SDC_CMD_STATUS SD_WriteMultiBlock(kal_uint32 address, kal_uint32* txbuffer, kal_uint32 num) // slim
SDC_CMD_STATUS SD_WriteMultiBlock(kal_uint32 address, kal_uint32* txbuffer, kal_uint32 num) // slim
{
    SDC_CMD_STATUS status;
    kal_uint32 count, whileIndex;
#ifdef DRV_MSDC_FORCE_WAIT_FOR_PROG_R1B_MALFUNCTION
    kal_uint32 cardStatus = 0;
#endif
#ifdef DRV_MSDC_2_DLT_FOR_RD_WR
    kal_uint32 triedDLTTimes = 0;

retryDLT:
#endif



#if defined(MT6225)
    kal_uint32 *ptr;
#elif defined(MSDC_MULTI_BLOCK_WRITE)
#else
    kal_uint32 *ptr;
#endif

#if defined(MT6225)
    kal_bool is_aligned, dma_issue;
    ECO_VERSION eco;

    is_aligned = KAL_FALSE;
    dma_issue = KAL_FALSE;
    ptr = txbuffer;
    eco = INT_ecoVersion();

    if (eco <= ECO_E3)
        dma_issue = KAL_TRUE;

#endif

    if (gSD->mWPEnabled)
        return ERR_WRITE_PROTECT;

#if defined(MT6255)

    if ((INT_SW_SecVersion() == SW_SEC_0 ) ||
        (INT_SW_SecVersion() == SW_SEC_1 )
       )
    {

        status = SD_DummySingleWrite(address, txbuffer);

        if (status != NO_ERROR)
        {
            tst_sys_trace("Dummy write fail");
            goto ERR_Exit;
        }
    }

#endif
    EnableMSDC_DMA();
    count = MSDC_SD_BLOCK_SIZE;
#if defined(MT6225)

    if (dma_issue)
    {
        is_aligned = ((kal_uint32)txbuffer % 4 == 0);

        if (is_aligned)
        {
            MSDC_DMATransferFirst((kal_uint32)txbuffer, count * num, KAL_TRUE);
        }
        else
        {
            kal_mem_cpy(MSDC_Sector, txbuffer, 512);
            ptr = txbuffer;
            MSDC_DMATransferFirst((kal_uint32)MSDC_Sector, count, KAL_TRUE);
        }
    }
    else
    {
        MSDC_DMATransferFirst((kal_uint32)txbuffer, count * num, KAL_TRUE);
    }

#elif defined(MSDC_MULTI_BLOCK_WRITE)
    MSDC_DMATransferFirst((kal_uint32)txbuffer, count * num, KAL_TRUE);
#else
    ptr = txbuffer;
    MSDC_DMATransferFirst((kal_uint32)ptr, count, KAL_TRUE);
#endif
#ifndef DRV_LSD

    if ((status = SD_Send_Cmd((num == 1 ? SDC_CMD_CMD24 : SDC_CMD_CMD25), address)) != NO_ERROR)
#else
    if (num > SD_CMD_MAX_BLOCK_NUM)
        ASSERT(0);

    LSD_HostSetBuffer((kal_uint8 *)txbuffer);

    if ((status = SD_Send_Cmd((num == 1 ? SDC_CMD_CMD24 : SDC_CMD_CMD25) | (num << 16) , address)) != NO_ERROR)
#endif
        goto ERR_Exit;

    if ((status = SD_CheckStatus()) != NO_ERROR)
        goto ERR_Exit;

#if defined(MT6225)

    if (dma_issue)
    {
        if (is_aligned)
        {
            status = MSDC_DMATransferFinal();

            if (status != NO_ERROR)
                goto ERR_Exit;

            if ((status = SD_WaitDatRdyOrTo()) != NO_ERROR)
                goto ERR_Exit;
        }
        else
        {
            kal_uint32 j;

            for (j = 0; j < num; j++)
            {
                if (gMSDC_Handle->mIsPresent  == KAL_FALSE)
                {
                    status = ERR_CARD_NOT_PRESENT;
                    goto ERR_Exit;
                }

                if (j != 0)
                {
                    kal_mem_cpy(MSDC_Sector, ptr, 512);
                    MSDC_DMATransferFirst((kal_uint32)MSDC_Sector, count, KAL_TRUE);
                }

                status = MSDC_DMATransferFinal();
#ifdef __DRV_MSDC_FAST_FORMAT__

                if (KAL_FALSE == gMSDC_Handle->MSDC_fastFormat)
#endif
                    ptr += MSDC_SD_BLOCK_SIZE;

                if (status != NO_ERROR)
                    goto ERR_Exit;

                if ((status = SD_WaitDatRdyOrTo()) != NO_ERROR)
                    goto ERR_Exit;
            }
        }
    }
    else
    {
        status = MSDC_DMATransferFinal();

        if (status != NO_ERROR)
            goto ERR_Exit;

        if ((status = SD_WaitDatRdyOrTo()) != NO_ERROR)
            goto ERR_Exit;
    }

#elif defined(MSDC_MULTI_BLOCK_WRITE) /*chips after MT6225 goes this way, 35,38,16, 53,..*/
    status = MSDC_DMATransferFinal();

    if (status != NO_ERROR)
    {
#if defined(MSDC_TRACE_LEVEL3)
        MSDC_add_dbg_msg(msdc_dbg_event_SD_multi_blk_write_issue1, MSDC_Reg(DMA_RLCT(gMSDC_Handle->msdc_dmaport)), status);
#endif
        //sd_writeFailReason = 1;
        gMSDC_Handle->dat_sta = MSDC_Reg(SDC_DATSTA);
#if 0	// to prevent from WHQA_0006199 happened again
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

        if (gMSDC_Handle->dat_sta & SDC_DATSTA_DATTO)
            ASSERT(0);

        if (gMSDC_Handle->dat_sta & SDC_DATSTA_DATCRCERR
#ifdef MSDC_DEFECT_WRITE_CRCERR	// WHQA_0006199 workaround for MT6236E2 write crc not reported (solution 2)
            || (MSDC_Reg(SDC_STA) & (SDC_STA_FEDATBUSY | SDC_STA_DATBUSY)) == SDC_STA_DATBUSY
#endif
           )
        {
            tst_sys_trace("[MSDC]:dat crc");
#ifdef DRV_MSDC_2_DLT_FOR_RD_WR

            /*remove this assertion, it is reasonable for card to go into prg state now*/
            //if(SD_IS_SDC_BUSY)
            //ASSERT(0);
            /*we record tried DLT here, no matter DLT pass or fail in this test is recorded*/
            if (triedDLTTimes < 3)
            {

                /**/
                if (MSDC_DLT_NOT_TESTED == gMSDC_Handle->msdc_clkTuneTriedWr)
                    gMSDC_Handle->msdc_clkTuneTriedWr = 0;

                /*should we send stop here? Of course, since card may still in receiving state if he doesn't have crc error event internally*/
                /*send CMD12*/
                DisableMSDC_DMA();

                if ((num > 1) && ((status = SD_StopTrans(KAL_TRUE))) != NO_ERROR)
                {
                    tst_sys_trace("[MSDC]retry DLT but Stop failed");
                    goto ERR_Exit;
                }

                /*find a DLT and change to it*/
                {
                    kal_uint32 searchDLTIndex = 0;
                    kal_uint32 testingRED = 0, testingDLT = 0;

                    while ((gMSDC_Handle->msdc_clkTuneTriedWr & (1 << searchDLTIndex)) && (32 > searchDLTIndex))
                    {
                        searchDLTIndex ++;

                        //all of DLT is used for RED = 0 case, search RED = 1 cases
                        if (searchDLTIndex == (gMSDC_Handle->msdc_clock / gMSDC_Handle->op_clock))
                            searchDLTIndex = 16;
                    }

                    if (31 < searchDLTIndex)
                        goto ERR_Exit;

                    /*there is some DLT unused, try it*/
                    testingRED = (16 > searchDLTIndex) ? 0 : 1;
                    testingDLT = searchDLTIndex - ((1 == testingRED) ? 16 : 0) + 1 ;
                    gMSDC_Handle->msdc_clkTuneTriedWr |= (1 << searchDLTIndex);
                    gMSDC_Handle->msdc_RedDlt_forWr =  (testingRED << 16) + testingDLT;
                    BitFieldWrite32((kal_uint32*)MSDC_CFG, (kal_uint32)testingRED, MSDC_CFG_CRED);
#if defined(DRV_MSDC_LATCH_MT6276_SERIES)
#else
                    BitFieldWrite32((kal_uint32*)MSDC_IOCON, testingDLT, MSDC_IOCON_DLT);
#endif//#if defined(DRV_MSDC_LATCH_MT6276_SERIES)
                }
                /*following comes from 1682190, flush the FIFO in MSDC before retry DLT*/
                RESET_MSDC();

                if (MSDC_Reg(MSDC_STA) & MSDC_STA_FIFOCNT)
                    ASSERT(0);

                triedDLTTimes ++;

                /*retry again*/
                goto retryDLT;

            }

#endif
        }

        goto ERR_Exit;
    }

    // wait R1b interrupt because cmd24 is configured as R1b response but cmd25 needn't
    if ((num == 1) && ((status = SD_WaitCardNotBusy()) != 0))
        goto ERR_Exit;

    if ((status = SD_WaitDatRdyOrTo()) != NO_ERROR)
    {
#if defined(MSDC_TRACE_LEVEL3)
        MSDC_add_dbg_msg(msdc_dbg_event_SD_multi_blk_write_issue2, status, 0);
#endif
        //sd_writeFailReason = 2;
        goto ERR_Exit;
    }

#else // not MT6225
    {
        kal_uint32 j;

        for (j = 0; j < num; j++)
        {
            if (gMSDC_Handle->mIsPresent  == KAL_FALSE)
            {
                status = ERR_CARD_NOT_PRESENT;
                goto ERR_Exit;
            }

            if (j != 0)
            {
                MSDC_DMATransferFirst((kal_uint32)ptr, count, KAL_TRUE);
            }

            status = MSDC_DMATransferFinal();

            /*in MSDC ealier than MT6225, the DAM run in different way and we have to take care the buffer pointer*/
#ifdef __DRV_MSDC_FAST_FORMAT__

            if (KAL_FALSE == gMSDC_Handle->MSDC_fastFormat)
#endif
                ptr += MSDC_SD_BLOCK_SIZE;

            if (status != NO_ERROR)
                goto ERR_Exit;

            if ((status = SD_WaitDatRdyOrTo()) != NO_ERROR)
                goto ERR_Exit;
        }

    }
#endif // MT6225

    DisableMSDC_DMA();

    if ((num > 1) && ((status = SD_StopTrans(KAL_TRUE))) != NO_ERROR)
        goto ERR_Exit;

#ifdef SD_STOP_SLOW

    if (num == 1)
    {
        kal_uint32 cardStatus;
        kal_uint32 time1, time2, time3;
        //wait 1.2s at moust.
        //time1 = drv_get_current_time();
        whileIndex = 0x100;

        while (SD_IS_R1B_BUSY && whileIndex)
        {
            if ((kal_query_systemInit() == KAL_TRUE)
#ifdef  __TST_WRITE_TO_FILE__ 			/*error recording: considering error recording additionally*/
                || (KAL_TRUE == INT_QueryExceptionStatus())
#endif
                || KAL_TRUE == FTL_isPollingMode()
               )
            {
                MSDC_GPTI_BusyWait(4);
            }
            else
            {
                kal_sleep_task(1);
            }

            whileIndex--;
        }

        whileIndex = 0x100;

        do
        {
            status = SD_GetStatus(gSD->mRCA, (kal_uint32*)&cardStatus);

            if (NO_ERROR != status)
            {
                tst_sys_trace("[MSDC]CMD13 fail when singleBlockWrite!");
                goto ERR_Exit;
            }

            whileIndex--;
        }
        while (((cardStatus & R1_CUR_STATE) >> 9 !=  TRAN_STA) && (0 != whileIndex));
    }

#endif


    MSDC_CLR_INT();
#ifdef MSDC_USE_INT
    kal_set_eg_events(gMSDC_Handle->MSDC_Events, 0, KAL_AND);
#endif

    return NO_ERROR;
ERR_Exit:
    {
        kal_uint32 tmp;

#ifdef MSDC_USE_INT
        kal_set_eg_events(gMSDC_Handle->MSDC_Events, 0, KAL_AND);
#endif
        DisableMSDC_DMA();
        RESET_MSDC();

        if (num > 1)SD_StopTrans(KAL_TRUE);

        SD_GetStatus(gSD->mRCA, (kal_uint32*)&tmp);
        MSDC_LSD_ReadReg32(SDC_DATSTA, &tmp);
        return status;
    }

}
#endif


/*************************************************************************
* FUNCTION
*	SD_SetBusWidth
*
* DESCRIPTION
*	ACMD6: set the data width 00 for 1 bit, 10 for 4 bits
*
* PARAMETERS
*	width: indicate the bus width
*
* RETURNS
*	SDC_CMD_STATUS
*
* GLOBALS AFFECTED
*
* NOTE
*	Not every card support 4-bits bus
*	only for SD
*
*************************************************************************/
SDC_CMD_STATUS SD_SetBusWidth(SD_BITWIDTH width)
{
    SDC_CMD_STATUS status;

    // check if card support 4 bits bus
    if ((width == BIT_4W) && !(gSD->mSCR.bus_width & 0x04))
        return ERR_NOT_SUPPORT_4BITS;

    // send APP_CMD
    if ((status = SD_Cmd55(gSD->mRCA)) != NO_ERROR)
        return status;

    // send cmd6
    if ((status = SD_Send_Cmd(SDC_CMD_ACMD6, width)) != NO_ERROR)
        return status;

    //read R1
    if ((status = SD_CheckStatus()) != NO_ERROR)
        return status;

    if (BIT_4W == width)
    {
        // set the controler MDLEN to enable 4-bit bus width
        MSDC_LSD_SetBits32(SDC_CFG, SDC_CFG_MDLEN);
        gSD->bus_width = 4;
    }
    else if (BIT_1W == width)
    {
        // clear the controler MDLEN to enable 1-bit bus width
        MSDC_LSD_ClearBits32(SDC_CFG, SDC_CFG_MDLEN);
        gSD->bus_width = 1;
    }

    return NO_ERROR;
}

/*************************************************************************
* FUNCTION
*	SD_ReadSCR
*
* DESCRIPTION
*	ACMD51: read the SD Configuration Register(8bytes block read)
*
* PARAMETERS
*	scr: used for store SCR
*
* RETURNS
*	SDC_CMD_STATUS
*
* GLOBALS AFFECTED
*
* NOTE
*	Make sure the size of SCR is 8 bytes
*
*************************************************************************/
SDC_CMD_STATUS SD_ReadSCR(kal_uint32* scr)
{
    SDC_CMD_STATUS status;
    kal_uint32 i, t1;

    ASSERT((kal_uint32)scr % 4  == 0);

    // set block length(MSDC_CFG)
    if ((status = SD_SetBlength(8)) != NO_ERROR)
        return status;

    // send APP_CMD
    if ((status = SD_Cmd55(gSD->mRCA)) != NO_ERROR)
        return status;

    // send command
    if ((status = SD_Send_Cmd(SDC_CMD_ACMD51, SDC_NO_ARG)) != NO_ERROR)
        return status;

    //read R1
    if ((status = SD_CheckStatus()) != NO_ERROR)
        return status;

    // read data(8bytes)
#ifndef DRV_LSD
    // failed to use DMA with burst mode
    t1 = drv_get_current_time();
    MSDC_START_TIMER(MSDC_TIMEOUT_PERIOD_DAT);

    for (i = 0; i < 2;)
    {
        if (drv_get_duration_ms(t1) > MSDC_TIMEOUT_PERIOD_DAT * 11)
            gMSDC_Handle->is_timeout = KAL_TRUE;
        else if(drv_get_duration_ms(t1)>10)
            SD_Sleep4Wait(1);

        if (!gMSDC_Handle->mIsPresent)
            return ERR_CARD_NOT_PRESENT;

        if (gMSDC_Handle->is_timeout)
            return MSDC_GPT_TIMEOUT_ERR;

        if (MSDC_Reg(MSDC_STA) & MSDC_STA_DRQ)//!MSDC_IS_FIFO_EMPTY
        {
            *(kal_uint32*)(scr + i) = MSDC_Reg32(MSDC_DAT);
            i++;
        }
    }

#else
    LSD_readFIFO(scr , 2);

#endif

    if ((status = SD_WaitDatRdyOrTo()) != NO_ERROR)
        return status;

    MSDC_STOP_TIMER();
    // analysis scr
    SD_AnalysisSCR(scr);
    //	if ( (gSD->mSCR.bus_width&0x5)==0 )
    //	    return ERR_INVALID_CARD;
    // clean EVENT_SDDATIRQ
#ifdef MSDC_USE_INT
    kal_set_eg_events(gMSDC_Handle->MSDC_Events, 0, KAL_AND);
#endif
    MSDC_CLR_FIFO();
    return NO_ERROR;

}

/*************************************************************************
* FUNCTION
*	SD_SetPreEraseBlk
*
* DESCRIPTION
*	ACMD23: set the number of write blocksto be pre-erased before writing
*	used for faster multiple Block Write
*
* PARAMETERS
*	num: used for storing number of blocks during multi-block operation
*
* RETURNS
*	SDC_CMD_STATUS
*
* GLOBALS AFFECTED
*
* NOTE
*
*************************************************************************/
SDC_CMD_STATUS SD_SetPreEraseBlk(kal_uint32 num)
{
    SDC_CMD_STATUS status;

    //[22:0] number of blocks
    num &= 0x003FFF;

    // send APP_CMD
    if ((status = SD_Cmd55(gSD->mRCA)) != NO_ERROR)
        return status;

    // send CMD23
    if ((status = SD_Send_Cmd(SDC_CMD_ACMD23, num)) != NO_ERROR)
        return status;

    //read R1
    if ((status = SD_CheckStatus()) != NO_ERROR)
        return status;

    return NO_ERROR;
}

/*************************************************************************
* FUNCTION
*	SD_EraseCmdClass
*
* DESCRIPTION
*	groups of erase commands including CMD32 ~CMD38
*
* PARAMETERS
*	cmd: indicate which command to execute
*	address: starting address wiht write protection
*
* RETURNS
*	SDC_CMD_STATUS
*
* GLOBALS AFFECTED
*
* NOTE
*	CMD34~CMD37 are only for MMC
*
*************************************************************************/
SDC_CMD_STATUS SD_EraseCmdClass(kal_uint32 cmd , kal_uint32 address)
{
    SDC_CMD_STATUS status;
    kal_uint32 sdcard_status;
    kal_set_eg_events(gMSDC_Handle->MSDC_Events, 0, KAL_AND);

    if (cmd != SDC_CMD_CMD38)
    {
        if ((status = SD_Send_Cmd(cmd, address)) != NO_ERROR)
            return status;
    }
    else if ((status = SD_Send_Cmd(cmd, SDC_NO_ARG)) != NO_ERROR)
        return status;

    //read R1
    if ((status = SD_CheckStatus()) != NO_ERROR)
        return status;

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else

    if (cmd == SDC_CMD_CMD38)
    {

        if ((status = SD_WaitCardNotBusy()) != NO_ERROR)
            return status;

        do
        {
            if ((status = SD_GetStatus(gSD->mRCA, (kal_uint32*)&sdcard_status)) != NO_ERROR)
                return status;

            if (gMSDC_Handle->mIsPresent == KAL_FALSE)
                return ERR_INVALID_CARD;
        }
        while (CurState(sdcard_status) != TRAN_STA);
    }

#endif
    return NO_ERROR;
}
/*************************************************************************
* FUNCTION
*	SD_Switch_MMC40
*
* DESCRIPTION
*	CMD6: set the command set or write to the EXT_CSD (for MMC4.0)
*
* PARAMETERS
*	access: access mode
*	index: index to EXT_CSD
*  value: value to write to EXT_CSD
*	set:	selected command set
*
* RETURNS
*	SDC_CMD_STATUS
*
* GLOBALS AFFECTED
*
* NOTE
*
*************************************************************************/
SDC_CMD_STATUS SD_Switch_MMC40(kal_uint8 access, kal_uint8 index, kal_uint8 value, kal_uint8 set)
{
    SDC_CMD_STATUS status = NO_ERROR;
    kal_uint32 arg = 0;
    kal_uint32 resp = 0;
    kal_bool retry = KAL_FALSE;
//    kal_uint8 *pData = NULL;

switch_start:

    arg = (access << 24) | (index << 16) | (value << 8) | set;

    // send command
    if ((status = SD_Send_Cmd(SDC_CMD_CMD6_MMC40, arg)) != NO_ERROR)
    {
        goto ERR_Exit;
    }

#ifndef DRV_LSD

    //read R1b
    if ((status = SD_WaitCardNotBusy()) != NO_ERROR)
        goto ERR_Exit;

#endif

    SD_GetStatus(gSD->mRCA, (kal_uint32*)&status);

    //read R1
    if ((status = SD_CheckStatus()) != NO_ERROR)
        goto ERR_Exit;

    MSDC_LSD_ReadReg32(SDC_RESP0, &resp);

    if ((resp & MMC_SWITCH_ERROR) != 0)
    {
        if (retry == KAL_FALSE)
        {
#ifdef MSDC_TRACE_LEVEL2
            drv_trace2(TRACE_GROUP_6, MSDC_INFORM_R0, resp, __LINE__);
#endif
            retry = KAL_TRUE;
            goto switch_start;
        }
        else
        {
            MSDC_CLR_FIFO();
            RESET_MSDC();
            return ERR_MMC_SWITCH_ERROR;
        }
    }

    MSDC_CLR_FIFO();
    RESET_MSDC();
    return NO_ERROR;

ERR_Exit:
    MSDC_CLR_FIFO();
    RESET_MSDC();
    return status;
}

/*************************************************************************
* FUNCTION
*	SD_SendEXTCSD_MMC40
*
* DESCRIPTION
*	CMD8: read the content of EXT_CSD register
*
* PARAMETERS
*	kal: access mode
*	index: index to EXT_CSD
*  value: value to write to EXT_CSD
*	set:	selected command set
*
* RETURNS
*	SDC_CMD_STATUS
*
* GLOBALS AFFECTED
*
* NOTE
*
*************************************************************************/
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef DRV_LSD
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
SDC_CMD_STATUS SD_SendEXTCSD_MMC40(kal_uint32* rxbuffer)
{
    SDC_CMD_STATUS status;
//    SDC_CMD_STATUS status1;
//    kal_bool retry = KAL_FALSE;
    kal_uint32 idx = 0;
    kal_uint32 t1;
//start:

    // read the block of 512 bytes (make sure the rxbuffer is 4 byte aligned)
    if ((status = SD_Send_Cmd(SDC_CMD_CMD8_MMC40, SDC_NO_ARG)) != NO_ERROR)
        goto ERR_Exit;

    //read R1
    if ((status = SD_CheckStatus()) != NO_ERROR)
        goto ERR_Exit;

    idx = 0;
    t1 = drv_get_current_time();

    /*move data from FIFO to buffer*/
    while ((idx * 4 < 512) &&  gMSDC_Handle->is_timeout != KAL_TRUE)
    {
        if (MSDC_Reg(MSDC_STA)&MSDC_STA_FIFOCNT)
        {
            *(rxbuffer + idx) = MSDC_Reg32(MSDC_DAT);
            idx ++;
        }

        //if (drv_get_duration_ms(t1) > MSDC_TIMEOUT_PERIOD_CMD*11)
        if (drv_get_duration_ms(t1) > 3000)
            gMSDC_Handle->is_timeout = KAL_TRUE;
    }

    if ((status = SD_WaitDatRdyOrTo()) != NO_ERROR)
        goto ERR_Exit;

    if (gMSDC_Handle->is_timeout == KAL_TRUE)
    {
        status = MSDC_GPT_TIMEOUT_ERR;
        goto ERR_Exit;
    }



    RESET_MSDC();
    MSDC_CLR_FIFO();

    kal_mem_cpy(MSDC_eCSD, rxbuffer, 512);
    gSD->mCSD.ext_csd = (T_EXT_CSD_MMC40 *)MSDC_eCSD;//rxbuffer;
    return NO_ERROR;

ERR_Exit:
    MSDC_CLR_FIFO();
    RESET_MSDC();
    gMSDC_Handle->is_timeout = KAL_FALSE;
    return status;
}
#endif

/*************************************************************************
* FUNCTION
*	SD_Switch_SD11
*
* DESCRIPTION
*	CMD6: switch command to query and select the specific functions. (SD1.1 or later)
* PARAMETERS
*	arg: argument
*	resp: buffer to contain the ther 64 bytes status information
*
* RETURNS
*	SDC_CMD_STATUS
*
* GLOBALS AFFECTED
*
* NOTE
*
*************************************************************************/
SDC_CMD_STATUS SD_Switch_SD11(kal_uint32 arg, T_SWITCH_STATUS* info)
{
    SDC_CMD_STATUS status = NO_ERROR;

    BitFieldWrite32((kal_uint32*)SDC_CFG, SD_CMD6_RESP_LEN, SDC_CFG_BLKLEN);
    EnableMSDC_DMA();
    MSDC_DMATransferFirst((kal_uint32)info, (SD_CMD6_RESP_LEN >> 2), KAL_FALSE);

    if ((status = SD_Send_Cmd(SDC_CMD_CMD6_SD11, arg)) != NO_ERROR)
        goto exit;

    if ((status = SD_CheckStatus()) != NO_ERROR)
        goto exit;

    status = MSDC_DMATransferFinal();

exit:
    DisableMSDC_DMA();
    return status;
}

/*************************************************************************
* FUNCTION
*	SD_Switch_SD11
*
* DESCRIPTION
*	Enable the high speed interface to support up to 50M Hz clock
*
* PARAMETERS
*	arg: argument
*	resp: buffer to contain the ther 64 bytes status information
*
* RETURNS
*	SDC_CMD_STATUS
*
* GLOBALS AFFECTED
*
* NOTE
*
*************************************************************************/
#ifndef DRV_MSDC_CORRECT_CMD6
SDC_CMD_STATUS SD_SelectHighSpeed_SD11(void)
{
    SDC_CMD_STATUS status;
    T_SWITCH_STATUS *p = (T_SWITCH_STATUS*)MSDC_Sector;

    if ((status = SD_Switch_SD11(SD_CMD6_QUERY_HIGH_SPEED, p)) != NO_ERROR)
        return status;

    if (p->max_current == 0)
        return ERR_SD_HS_FAIL;

    if ((p->group1_info & (1 << SD_FUNC_HIGH_SPEED)) &&
        (p->group1_result == SD_FUNC_HIGH_SPEED))
    {
        if ((status = SD_Switch_SD11(SD_CMD6_SELECT_HIGH_SPEED, p)) != NO_ERROR)
            return status;

        if (p->max_current == 0)
            return ERR_SD_HS_FAIL;

        if (p->group1_result == SD_FUNC_HIGH_SPEED)
            gSD->flags |= SD_FLAG_HS_SUPPORT;
    }
    else
        return ERR_SD_HS_FAIL;


    return NO_ERROR;
}
#else
SDC_CMD_STATUS SD_SelectHighSpeed_SD11(void)
{
    SDC_CMD_STATUS status;
    kal_uint8 *bytePtr;
    kal_uint16	max_current, group1_info;
    kal_uint8		group1_result;

    if ((status = SD_Switch_SD11(SD_CMD6_QUERY_HIGH_SPEED, (T_SWITCH_STATUS*)MSDC_Sector)) != NO_ERROR)
        return status;

    bytePtr = (kal_uint8 *)MSDC_Sector;
    max_current = (((*(kal_uint8 *)bytePtr) << 8) | (*(kal_uint8 *)(bytePtr + 1)));
    group1_info = (((*(kal_uint8 *)(bytePtr + 12)) << 8) | (*(kal_uint8 *)(bytePtr + 13)));
    group1_result = ((*(kal_uint8 *)(bytePtr + 16)) & 0xf);

    if (max_current == 0)
        return ERR_SD_HS_FAIL;

    if ((group1_info & (1 << SD_FUNC_HIGH_SPEED)) &&
        (group1_result == SD_FUNC_HIGH_SPEED))
    {
        /*we do not send CMD6 select high speed to Kinston cards*/
        //if(( 0x1B == gSD->mCID.mid && 0x534d == gSD->mCID.oid) || ( 0x2 == gSD->mCID.mid && 0x544d == gSD->mCID.oid)){
        //	tst_sys_trace("kinston cards");
        //	gSD->flags |= SD_FLAG_LIMITED_HIGH_SPEED_CARD;
        //	return ERR_SD_HS_FAIL;
        //}

        if ((status = SD_Switch_SD11(SD_CMD6_SELECT_HIGH_SPEED, (T_SWITCH_STATUS*)MSDC_Sector)) != NO_ERROR)
            return status;

        max_current = (((*(kal_uint8 *)bytePtr) << 8) | (*(kal_uint8 *)(bytePtr + 1)));
        group1_info = (((*(kal_uint8 *)(bytePtr + 12)) << 8) | (*(kal_uint8 *)(bytePtr + 13)));
        group1_result = ((*(kal_uint8 *)(bytePtr + 16)) & 0xf);

        if (max_current == 0)
            return ERR_SD_HS_FAIL;

        if (group1_result == SD_FUNC_HIGH_SPEED)
            gSD->flags |= SD_FLAG_HS_SUPPORT;
    }
    else
        return ERR_SD_HS_FAIL;


    return NO_ERROR;
}
#endif

SDC_CMD_STATUS SD_GoInactive(kal_uint16 rca)
{
    SDC_CMD_STATUS status;

    if ((status = SD_Send_Cmd(SDC_CMD_CMD15, (kal_uint32)rca << 16)) != NO_ERROR)
        return status;

    return NO_ERROR;
}

SDC_CMD_STATUS SD_ReadStream_MMC(kal_uint32 address, kal_uint32* rxbuffer, kal_uint32 bytes)
{
    SDC_CMD_STATUS status;
    kal_uint32 count;
#ifndef MSDC_DMA
    kal_uint32 i;
#endif

    MSDC_CLR_FIFO();
    count = (bytes % 4) ? (bytes / 4 + 1) : (bytes / 4);
#ifdef MSDC_DMA
    EnableMSDC_DMA();
    MSDC_DMATransferFirst((kal_uint32)rxbuffer, count, KAL_FALSE);
#endif

    //launch stream read command
    if ((status = SD_Send_Cmd(SDC_CMD_CMD11_MMC, address)) != NO_ERROR)
    {
        goto ERR_Exit;
    }

    //read R1
    if ((status = SD_CheckStatus()) != NO_ERROR)
    {
        SD_WaitDatRdyOrTo();
        goto ERR_Exit;
    }


#ifdef MSDC_DMA
    status = MSDC_DMATransferFinal();

    if (status != NO_ERROR)
    {
        goto ERR_Exit;
    }

#else

    //size assumed to be multiple of 4
    for (i = 0; i < count;)
    {
        //check fifo is not empty
        if (!MSDC_IS_FIFO_EMPTY)
        {
            *(rxbuffer + i) = MSDC_Reg32(MSDC_DAT);
            i++;
        }
    }

#endif
    DisableMSDC_DMA();
    SD_StopTrans(KAL_FALSE);
    MSDC_CLR_FIFO();
    return NO_ERROR;

ERR_Exit:
    {
        kal_uint32 tmp;

#ifdef MSDC_USE_INT
        kal_set_eg_events(gMSDC_Handle->MSDC_Events, 0, KAL_AND);
#endif
        DisableMSDC_DMA();
        RESET_MSDC();

        SD_StopTrans(KAL_FALSE);
        SD_GetStatus(gSD->mRCA, (kal_uint32*)&tmp);
        MSDC_LSD_ReadReg32(SDC_DATSTA, &tmp);
        MSDC_CLR_FIFO();
        return status;
    }

}


// write data stream from card only for MMC
SDC_CMD_STATUS SD_WriteStream_MMC(kal_uint32 address, kal_uint32* txbuffer, kal_uint32 bytes)
{
    SDC_CMD_STATUS status;
    kal_uint32 count;
#ifndef MSDC_DMA
    kal_uint32 i;
#endif

    if (!gSD->mCSD.w_blk_part && (address + bytes) % 512 != 0)
        return ERR_ERRORS;

    MSDC_CLR_FIFO();
    count = (bytes % 4) ? (bytes / 4 + 1) : (bytes / 4);
#ifdef MSDC_DMA
    EnableMSDC_DMA();
    MSDC_DMATransferFirst((kal_uint32)txbuffer, count, KAL_TRUE);
#endif

    if ((status = SD_Send_Cmd(SDC_CMD_CMD20_MMC, address)) != NO_ERROR)
    {
        goto ERR_Exit;
    }

    if ((status = SD_CheckStatus()) != NO_ERROR)
    {
        goto ERR_Exit;
    }

#ifdef MSDC_DMA
    status = MSDC_DMATransferFinal();

    if (status != NO_ERROR)
    {
        goto ERR_Exit;
    }

#else

    for (i = 0; i < count;)
    {

        if (!MSDC_IS_FIFO_FULL)
        {
            MSDC_WriteReg32(MSDC_DAT, *(txbuffer + i));
            i++;
        }

        // check data ready (512 bytes)
        if ((i % 128) == 0)
            SD_WaitCardNotBusy();
    }

#endif
    DisableMSDC_DMA();
    SD_StopTrans(KAL_TRUE);
    MSDC_CLR_FIFO();
    return NO_ERROR;

ERR_Exit:
    {
        kal_uint32 tmp;

#ifdef MSDC_USE_INT
        kal_set_eg_events(gMSDC_Handle->MSDC_Events, 0, KAL_AND);
#endif
        DisableMSDC_DMA();
        RESET_MSDC();

        SD_StopTrans(KAL_TRUE);
        SD_GetStatus(gSD->mRCA, (kal_uint32*)&tmp);
        MSDC_LSD_ReadReg32(SDC_DATSTA, &tmp);
        MSDC_CLR_FIFO();
        return status;
    }
}

//program CSD, transfer CSD through data line
SDC_CMD_STATUS SD_ProgramCSD(kal_uint32 Csd[4])
{
    SDC_CMD_STATUS status;
    kal_uint32 i;

    if ((status = SD_Send_Cmd(SDC_CMD_CMD27, 0)) != NO_ERROR)
        return status;

    //read R1
    if ((status = SD_CheckStatus()) != NO_ERROR)
    {
        SD_WaitDatRdyOrTo();
        return status;
    }

    //clear fifo
    MSDC_CLR_FIFO();

    //send CSD 128 bits = 4x32
    for (i = 0; i < 4; i++)
        MSDC_WriteReg32(MSDC_DAT, Csd[i]);

    //wait until crc status token received
    if ((status = SD_WaitDatRdyOrTo()) != NO_ERROR)
        return status;

    //wait until programming is finished
    SD_WaitCardNotBusy();
    return NO_ERROR;
}


//set write protect
SDC_CMD_STATUS SD_SetWriteProtect(kal_uint32 address)
{
    SDC_CMD_STATUS status;

    if ((status = SD_Send_Cmd(SDC_CMD_CMD28, address)) != NO_ERROR)
        return status;

    if ((status = SD_CheckStatus()) != NO_ERROR)
        return status;

    //wait until data line is ready
    SD_WaitCardNotBusy();
    return NO_ERROR;
}

//clear write protect
SDC_CMD_STATUS SD_ClrWriteProtect(kal_uint32 address)
{
    SDC_CMD_STATUS status;

    if ((status = SD_Send_Cmd(SDC_CMD_CMD29, address)) != NO_ERROR)
        return status;

    if ((status = SD_CheckStatus()) != NO_ERROR)
        return status;

    SD_WaitCardNotBusy();
    return NO_ERROR;
}

// send write protect(single block read)
SDC_CMD_STATUS SD_SendWriteProtect(kal_uint32 address, kal_uint32* WPBits32)
{
    SDC_CMD_STATUS status;
    kal_uint32	tmp;

    BitFieldWrite32((kal_uint32*)SDC_CFG, 4, SDC_CFG_BLKLEN);
    MSDC_CLR_FIFO();

    if ((status = SD_Send_Cmd(SDC_CMD_CMD30, address)) != NO_ERROR)
        return status;

    if ((status = SD_CheckStatus()) != NO_ERROR)
        return status;

    //read 32 write protection bits
    MSDC_LSD_ReadReg32(MSDC_DAT, &tmp);
    MSDC_InvertN((kal_uint8*)WPBits32, (kal_uint8*)&tmp, 4);
    // configure the controller to the original block length
    BitFieldWrite32((kal_uint32*)SDC_CFG, gSD->mBKLength, SDC_CFG_BLKLEN);

    return NO_ERROR;
}

// CMD39: Fast IO-used to write and read 8 bit register
SDC_CMD_STATUS SD_FastIO_MMC(kal_uint16 rca, kal_bool isWrite, kal_uint8 reg_adrs, kal_uint8 data)
{
    SDC_CMD_STATUS status;
    kal_uint32 arg = 0;

    arg = rca << 16;
    arg |= isWrite << 15;
    arg |= reg_adrs << 8;
    arg |= data;

    if ((status = SD_Send_Cmd(SDC_CMD_CMD39_MMC, arg)) != NO_ERROR)
        return status;

    if ((status = SD_CheckStatus()) != NO_ERROR)
        return status;

    return NO_ERROR;
}


// Sets the system into interrupt mode (MMC)
SDC_CMD_STATUS SD_GoIRQ_MMC(void)
{
    SDC_CMD_STATUS status;

    if ((status = SD_Send_Cmd(SDC_CMD_CMD40_MMC, SDC_NO_ARG)) != NO_ERROR)
        return status;

    status = *(kal_uint32*)SDC_RESP0;
#ifdef MSDC_TRACE_LEVEL2
    drv_trace2(TRACE_GROUP_6, MSDC_INFORM_R0, status, __LINE__);
#endif

    return NO_ERROR;
}

// Used to set/reset password ,lock/unlock the card and force erase total card.
// similiar to a signle block write structure.(CMD42)
// max password length = 16
SDC_CMD_STATUS SD_LockUnlock(SD_LOCK_OP op, kal_char* Oldpwd, kal_char* Newpwd, kal_uint8 Oldlen, kal_uint8 Newlen)
{
    SDC_CMD_STATUS status;
    kal_uint8 lockbk[SDC_MAX_LOCKBK];
    kal_uint32 i, blklen, *ptr = (kal_uint32*)lockbk, count;

    if (Oldlen > 16 || Newlen > 16)
        return ERR_ERRORS;

    /* save the original block length*/
    blklen = gSD->mBKLength;

    kal_mem_set(lockbk, 0, SDC_MAX_LOCKBK);

    switch (op)
    {
        case SET_PWD:
            lockbk[0] = 0x01;
            break;

        case CLR_PWD:
            lockbk[0] = 0x02;
            break;

        case LOCK_CARD:
            lockbk[0] = 0x04;
            break;

        case UNLOCK_CARD:
            lockbk[0] = 0x00;
            break;

        case ERASE:
            lockbk[0] = 0x08;
            break;
    }

    lockbk[1] = Oldlen + Newlen;
    kal_mem_cpy(&lockbk[2], Oldpwd, Oldlen);
    kal_mem_cpy(&lockbk[2 + Oldlen], Newpwd, Newlen);

    /* set block length */
    if (op != ERASE)
    {
        SD_SetBlength(2 + lockbk[1]);
        count = ((lockbk[1] + 2) % sizeof(kal_uint32)) ? ((lockbk[1] + 2) / sizeof(kal_uint32) + 1) :
                ((lockbk[1] + 2) / sizeof(kal_uint32));
    }
    else
    {
        SD_SetBlength(1);
        count = 1;
    }

    /* send command */
    if ((status = SD_Send_Cmd(SDC_CMD_CMD42, SDC_NO_ARG)) != NO_ERROR)
        return status;

    /* read R1b */
    SD_CheckStatus();
    /* clear FIFO */
    MSDC_CLR_FIFO();
    count = ((lockbk[1] + 2) % sizeof(kal_uint32)) ? ((lockbk[1] + 2) / sizeof(kal_uint32) + 1) :
            ((lockbk[1] + 2) / sizeof(kal_uint32));
#ifndef DRV_LSD

    /* write data into fifo */
    for (i = 0; i < count;)
    {
        if (!MSDC_IS_FIFO_FULL)
        {
            MSDC_WriteReg32(MSDC_DAT, *(kal_uint32*)(ptr + i));
            i++;
        }
    }

#endif
    /* wait until crc status token received */
    status = SD_WaitDatRdyOrTo();
    /* wait util card has finished programming */
    SD_WaitCardNotBusy();
    // restore the block length back
    SD_SetBlength(blklen);
    /* check status*/
    SD_GetStatus(gSD->mRCA, &status);

    if (status & R1_LOCK_UNLOCK_FAILED_24)
        return ERR_LOCK_UNLOCK_FAILED;

    if ((op == LOCK_CARD) && !(status & R1_CARD_IS_LOCKED_25))
        return ERR_LOCK_UNLOCK_FAILED;

    if ((op == UNLOCK_CARD) && (status & R1_CARD_IS_LOCKED_25))
        return ERR_LOCK_UNLOCK_FAILED;

    return NO_ERROR;
}

// ACMD13: read SD status(512bits = 64bytes single block read)
SDC_CMD_STATUS SD_GetSDStatus(kal_uint32* sd_status)
{
    SDC_CMD_STATUS status;
    kal_uint32 blklen, i;

    // save the orignial block length
    blklen = gSD->mBKLength;

    // set block length
    if ((status = SD_SetBlength(64)) != NO_ERROR)
        return status;

    // clear fifo
    MSDC_CLR_FIFO();

    // send APP_CMD
    if ((status = SD_Cmd55(gSD->mRCA)) != NO_ERROR)
        return status;

    // send CMD13
    if ((status = SD_Send_Cmd(SDC_CMD_ACMD13, SDC_NO_ARG)) != NO_ERROR)
        return status;

    //read R1
    if ((status = SD_CheckStatus()) != NO_ERROR)
        return status;

    // read sd status(64bytes = 4x16)
#ifndef DRV_LSD

    for (i = 0; i < 16;)
    {
        if (!MSDC_IS_FIFO_EMPTY)
        {
            *(kal_uint32*)(sd_status + i) = MSDC_Reg32(MSDC_DAT);
            i++;
        }
    }

#endif

    // resotre block length
    if ((status = SD_SetBlength(blklen)) != NO_ERROR)
        return status;

    return NO_ERROR;
}
//ACMD22: get the number of written write blocks(4bytes single block read)
SDC_CMD_STATUS SD_GetNumWrittenBlk(kal_uint32* num)
{
    SDC_CMD_STATUS status;
    kal_uint32 blklen, tmp;

    // save the orignial block length
    blklen = gSD->mBKLength;

    // set block length
    if ((status = SD_SetBlength(4)) != NO_ERROR)
        return status;

    // clear fifo
    MSDC_CLR_FIFO();

    // send APP_CMD
    if ((status = SD_Cmd55(gSD->mRCA)) != NO_ERROR)
        return status;

    // send CMD22
    if ((status = SD_Send_Cmd(SDC_CMD_ACMD22, SDC_NO_ARG)) != NO_ERROR)
        return status;

    //read R1
    if ((status = SD_CheckStatus()) != NO_ERROR)
        return status;

    // read the number of written write blocks(4bytes)
#ifndef DRV_LSD

    while (MSDC_IS_FIFO_EMPTY);

#endif
    tmp = MSDC_Reg32(MSDC_DAT);
    MSDC_InvertN((kal_uint8*)num, (kal_uint8*)&tmp, 4);

    // resotre block length
    if ((status = SD_SetBlength(blklen)) != NO_ERROR)
        return status;

    return NO_ERROR;
}

#ifdef DRV_MSDC_HW_CONTENTION
extern kal_semid dclMsdcArb;
#endif

void SD_startFastFormat(void)
{
#if defined(__AUDIO_DSP_LOWPOWER__)
    AUDMA_LOCK(AUDMA_ID_MSDC);
#endif

#ifdef DRV_MSDC_HW_CONTENTION
    kal_uint32 retAddr;

#if defined(__RVCT__)
    /* RVCT doesn't support inline assemlber; bypass temporarily */
    retAddr = 0;
#else   /* __RVCT__ */
    /* get the return address */
    __asm
    {
        MOV retAddr, lr
    }
#endif  /* __RVCT__ */


    if (NULL == dclMsdcArb)
        ASSERT(0);

    if (kal_query_systemInit() == KAL_FALSE)
    {
        /*must gain resource here before calling writeSectors*/
        kal_take_sem(dclMsdcArb, 1);
        SD_setArbRetAddr(retAddr);
        SD_setArbThdId((kal_uint32)kal_get_current_thread_ID());
    }

#endif


#ifdef DRV_LSD
    LSD_startFastFormat();
#elif defined(__DRV_MSDC_FAST_FORMAT__)
    gMSDC_Handle->MSDC_fastFormat = KAL_TRUE;
#endif
}

void SD_closeFastFormat(void)
{

#ifdef DRV_LSD
    LSD_closeFastFormat();
#elif defined(__DRV_MSDC_FAST_FORMAT__)
    gMSDC_Handle->MSDC_fastFormat = KAL_FALSE;
#endif

#ifdef DRV_MSDC_HW_CONTENTION

    if (kal_query_systemInit() == KAL_FALSE)
    {
        /*when the semaphore is returned, we set thdId to zero, but not retAddr, we can know that it is released from here*/
        SD_setArbThdId(NULL);
        kal_give_sem(dclMsdcArb);
    }

#endif

#if defined(__AUDIO_DSP_LOWPOWER__)
    AUDMA_UNLOCK(AUDMA_ID_MSDC);
#endif
}


//__attribute__ ((section ("EXT_BOOTLOADER_CODE")))SDC_CMD_STATUS SD_FlushSectors(kal_uint32 startSector, kal_uint32 sectorNum)
SDC_CMD_STATUS SD_FlushSectors(kal_uint32 startSector, kal_uint32 sectorNum)
{
    SDC_CMD_STATUS status;
    kal_uint32 sectorMult;

    if (gSD->flags & SD_FLAG_HCS_SUPPORT)
        sectorMult = 1;
    else
        sectorMult = SECTOR_SIZE;

    MSDC_PDNControl(KAL_FALSE);

    // there are differences between SD and MMC
    // tag erase start(CMD32)
    if ((status = SD_EraseCmdClass(SDC_CMD_CMD32, sectorMult * startSector)) != NO_ERROR)
    {
        goto ErrorExit;
    }

    // tag erase end(CMD33)
    if ((status = SD_EraseCmdClass(SDC_CMD_CMD33, sectorMult * (startSector + sectorNum - 1))) != NO_ERROR)
    {
        goto ErrorExit;
    }

    // erase...(CMD38)
    if ((status = SD_EraseCmdClass(SDC_CMD_CMD38, 0)) != NO_ERROR)
    {
        goto ErrorExit;
    }

ErrorExit:
    MSDC_PDNControl(KAL_TRUE);
    return status;
}

#ifdef IC_MODULE_TEST

kal_bool MSDC_ModuleTest_Report(void)
{
    SDC_CMD_STATUS status;

    if (gMSDC_Handle->mIsInitialized == KAL_FALSE)
        return KAL_FALSE;

    MSDC_PDNControl(KAL_FALSE);

    gMSDC_Handle->mIsInitialized = KAL_TRUE;
    gMSDC_Handle->trySingleLine = KAL_TRUE;

    status = SD_Initialize();

    if (status == NO_ERROR)
        return KAL_TRUE;
    else
        return KAL_FALSE;

}
#endif

#else
#ifdef DRV_LSD
T_SDC_HANDLE	gSD_blk[SD_NUM];
T_SDC_HANDLE	*gSD = gSD_blk;
#endif
#endif //  defined(__MSDC_SD_MMC__)

#ifdef MSDC_DEBUG

#define TST_ADRS	512*12
static kal_uint8 rxbuffer[512 * 32], txbuffer[512 * 32];
//static kal_uint8 rxbuffer[512],txbuffer[512];
kal_uint32 SD_MMC_Test(void)
{

    kal_uint32 result, resp;
    int i;
    SDC_CMD_STATUS status;

    // initialize MSDC
    MSDC_Initialize();
    // initialize SDC
    SD_Initialize();


    //////////////////////////
    //Mass data Tansfer(8M)//
    //////////////////////////
#ifdef MASS
    {
        int block_num, i, j, cmp, loop = 1;
        kal_uint32 ticks;

#ifdef BITS4_BUS

        if (gMSDC_Handle->mMSDC_type == SD_CARD)
        {
            if (status = SD_SetBusWidth(BIT_4W))
                return status;
        }

#endif

        for (i = 0; i < 512 * 32; i++)
            txbuffer[i] = i % 256;

        j = 0;
        ticks = NU_Retrieve_Clock();

        while (loop)
        {
            status = SD_WriteMultiBlock(j * 512 * 32, (uint32*)txbuffer, 32);

            if (status)
            {
                ticks = NU_Retrieve_Clock() - ticks  ;
                //dbg_print("SD_WriteMultiBlock failed! %d \n\r",ticks);
                //while(1);
            }

            status = SD_ReadMultiBlock(j * 512 * 32, (uint32*)rxbuffer, 32);

            if (status)
            {
                ticks = NU_Retrieve_Clock() - ticks  ;
                //dbg_print("SD_ReadMultiBlock failed! %d \n\r",ticks);
                //while(1);
            }

            ticks = NU_Retrieve_Clock() - ticks  ;

            cmp = memcmp(txbuffer, rxbuffer, 512 * 32);

            if (cmp)
            {
                ticks = NU_Retrieve_Clock() - ticks  ;
                //dbg_print("compare failed! %d \n\r",ticks);
                //while(1);
            }

            //dbg_print("Check %d OK!\t",j);
            kal_mem_set(rxbuffer, 0, 512 * 32);
            j++;

            if (j * 32 >= gSD->mBKNum - 32)
            {
                static count = 0;
                ticks = NU_Retrieve_Clock() - ticks  ;
                //dbg_print("\n\r###############################\n\r",ticks);
                //dbg_print("end of card %d at count %d\n\r",ticks,count++);
                //dbg_print("\n\r###############################\n\r",ticks);

                j = 0;
                ticks = NU_Retrieve_Clock();

                //while(1);
            }
        }

        /*
        	// (1) using single block transfer
        	ticks = NU_Retrieve_Clock();
        	block_num  = 32;
        	//block_num  = 1024;
        	for(i=0;i<block_num;i++)
        		if(status = SD_WriteSingleBlock(i*512,(kal_uint32*)txbuffer))
        			break;

        	ticks = NU_Retrieve_Clock()- ticks  ;
        	ticks = NU_Retrieve_Clock();
        	for(i=0;i<block_num;i++)
        	{
        		if(status = SD_ReadSingleBlock(i*512,(kal_uint32*)rxbuffer))
        			break;
        	}
        	ticks = NU_Retrieve_Clock()- ticks  ;

        	// (2) using multiple block transfer(requied to rewind the buffer pointer)
        	ticks = NU_Retrieve_Clock();
        	status = SD_WriteMultiBlock(0,(kal_uint32*)txbuffer,block_num);
        	ticks = NU_Retrieve_Clock()- ticks  ;

        	ticks = NU_Retrieve_Clock();
        	status = SD_ReadMultiBlock(0,(kal_uint32*)rxbuffer,block_num);
        	ticks = NU_Retrieve_Clock()- ticks  ;
        */

    }
#endif // end of MASS

#ifdef SD_ERASE

    // there are differences between SD and MMC
    // tag erase start(CMD32)
    if (status = SD_EraseCmdClass(SDC_CMD_CMD32, 0))
        return status;

    // tag erase end(CMD33)
    if (status = SD_EraseCmdClass(SDC_CMD_CMD33, 512 * 32))
        return status;

    // erase...(CMD38)
    if (status = SD_EraseCmdClass(SDC_CMD_CMD38, 0))
        return status;

    // check result of erase
    // single block read (CMD17)
    if (status = SD_ReadSingleBlock(0, (kal_uint32*)rxbuffer))
        return status;

    result = 0;

    for (i = 0; i < 512; i++)
    {
        if (gSD->mSCR.dat_after_erase)
        {
            if (rxbuffer[i] != 0xff)
                result++;
        }
        else
        {
            if (rxbuffer[i] != 0x00)
                result++;
        }
    }

#endif

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef BITS4_BUS
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif // end of 0

}
#endif	// FPGA_DEBUG

#endif//!defined(__UBL__) || defined(__CARD_DOWNLOAD__) || defined(__EMMC_BOOTING__)

#else //DRV_MSDC_OFF
#include "kal_public_api.h" //MSBB change #include "kal_release.h"
//RHR ADD
#include "kal_general_types.h"
//#include "btif_sw.h"
#include "kal_public_api.h"
#include "kal_internal_api.h"
#include "kal_public_defs.h"
//RHR REMOVE
/*
//MSBB remove #include "kal_non_specific_general_types.h"
//MSBB remove #include "app_buff_alloc.h"
#include "intrCtrl.h"
//#include "gpio_sw.h"
#include "init.h"
#include "pmic_features.h"
#include "pmu_sw.h"
#include "nucleus.h"
#include "ev_defs.h"
*/
//RHR
#include "gpt_sw.h"
#include "drv_comm.h"
#include "reg_base.h"
#include "msdc_def.h"
#include "sd_def.h"
#include "upll_ctrl.h"
#include	"Drv_trc.h"
#ifdef DCL_MSDC_INTERFACE
#include "DCL.h"
void SD_dummyAPI(void) {}
SDC_CMD_STATUS SD_SetBlength(kal_uint32 BKLength) {}
SDDriver_t sd_driver_MTK1 =
{
    (DCL_SINGLE_BLK_RD)SD_dummyAPI,
    (DCL_MUL_BLK_RD)SD_dummyAPI,
    (DCL_SINGLE_BLK_WR)SD_dummyAPI,
    (DCL_MUL_BLK_WR)SD_dummyAPI,
    (DCL_SD_INITITALIZE)SD_dummyAPI,
    (DCL_SET_PRE_ERASE_CNT)SD_dummyAPI,
    (DCL_SD_SET_CALLBACK)SD_dummyAPI,
    (DCL_SET_READ_TEST_FLAG)SD_dummyAPI,
    (DCL_SD_READ_TEST)SD_dummyAPI,
    (DCL_SD_SET_UPLL_CLOCK_TEST)SD_dummyAPI,
    (DCL_SD_ERASE_BLK)SD_dummyAPI,
};
#endif //DCL_MSDC_INTERFACE

void SD_startFastFormat(void) {}
void SD_closeFastFormat(void) {}
T_SDC_HANDLE	gSD_blk[SD_NUM];
T_SDC_HANDLE	*gSD = gSD_blk;

#if defined( __MSDC_BASIC_LOAD__) || defined( __MEUT__)
kal_uint32 msdc_ReadTestFlag;
#endif

#endif //DRV_MSDC_OFF


