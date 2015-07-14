#!/usr/bin/perl
#
#  Copyright Statement:
#  --------------------
#  This software is protected by Copyright and the information contained
#  herein is confidential. The software may not be copied and the information
#  contained herein may not be used or disclosed except with the written
#  permission of MediaTek Inc. (C) 2006
#
#  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
#  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
#  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
#  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
#  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
#  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
#  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
#  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
#  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
#  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
#  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
#  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
#
#  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
#  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
#  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
#  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
#  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
#
#  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
#  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
#  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
#  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
#  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
#
#*****************************************************************************
#*
#* Filename:
#* ---------
#*   emiGenSP.pl
#*
#* Project:
#* --------
#*
#*
#* Description:
#* ------------
#*   This script will
#*       1. generate fxied flash_opt.h for smart phone modem
#*       2. generate fixed custom_EMI.c for smart phone modem
#*       3. generate fixed custom_EMI.h for smart phone modem
#*       4. generate fixed custom_flash.c for smart phone modem
#*
#* Author:
#* -------
#*   Claudia Lo    (mtk01876)
#*
#*============================================================================
#*             HISTORY
#* Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
#*------------------------------------------------------------------------------
#* $Revision$
#* $Modtime$
#* $Log$
#* 
#* 07 27 2012 marvin.lin
#* [MOLY00001243] [MemoryStorage][Auto-Gen][EMI Gen/CFG Gen][Request For Design Change] to fix emi build warning on sp project
#* .
#*
#*
#*------------------------------------------------------------------------------
#* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
#*============================================================================
#****************************************************************************/

#****************************************************************************
# Included Modules
#****************************************************************************
use strict;

#****************************************************************************
# Constants
#****************************************************************************
1;
#my $DebugPrint    = 0; # 1 for debug; 0 for non-debug

#****************************************************************************
# subroutine:  custom_EMI_h_file_body_for_sp
# return:      custom_EMI.h file content for SP
#****************************************************************************
sub custom_EMI_h_file_body_for_sp
{
    my ($bb) = @_;
    my $template;
	   
    $template = <<"__TEMPLATE";
#ifndef __CUSTOM_EMI__
#define __CUSTOM_EMI__

/****************************************************************************
   *
   * Definition.
   *
   ****************************************************************************/

#define DRAM_CS                   0

/**
    * On new format, it has been replaced with EMI_EXTSRAM_SIZE defined at custom_emi_release.h, 
    * but we still keep it and will remove this definition when phasing in auto-gen.
    */
#define DRAM_SIZE                 1024  /* Density of LPSDRAM,in terms of Mbits */


/****************************************************
 * This part is for auto-gen validity CHECK *
 * Don't modify any content in this comment section *
 * CS0_PART_NUMBER: EDK1432CABH_60

 ****************************************************/

#endif /* __CUSTOM_EMI__ */

__TEMPLATE
	   
    return $template;
}

#****************************************************************************
# subroutine:  custom_EMI_c_file_body_for_sp
# return:      custom_EMI.c file content for SP
#****************************************************************************
sub custom_EMI_c_file_body_for_sp
{
    my ($bb) = @_;
    my $template;
	   
    $template = <<"__TEMPLATE";
#include "kal_public_api.h"
#include "pll.h"

#include "custom_EMI_release.h"

// temp solution to avoid build error for custom release
#include "custom_EMI.h"
#include "custom_MemoryDevice.h"

/*************************************
  *
  * Imported APIs.
  *
  *************************************/


/*************************************
  *
  * Global Variables.
  *
  *************************************/


/*************************************************************************
* FUNCTION
*  custom_setEMI()
*
* DESCRIPTION
*   This routine aims to set EMI
*
* PARAMETERS
*
* RETURNS
*  None
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_int8 custom_setEMI(void)
{

/**
  * MT6573 EMI will be init at CMM when bring-up.
  */    

   return 1;

}

/*************************************************************************
* FUNCTION
*  custom_InitDRAM()
*
* DESCRIPTION
*   This routine aims to set EMI and initialize LPSDRAM
*
* PARAMETERS
*
* RETURNS
*  None
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_int8 custom_InitDRAM(void)
{
   return -1;

}

#if ( !defined(__UBL__) && !defined(__FUE__) )
  /* __FUE__ , __UBL__ compile option is used for FOTA or USB Bootloader build
   * add this compile option to avoid compiling functions other than custom_setEMI()
   */

/*************************************************************************
* FUNCTION
*  custom_setAdvEMI()
*
* DESCRIPTION
*   This routine aims to set additional EMI
*   This is special for device which needs to set device configuration
*   register to turn-on special mode.
*
* PARAMETERS
*
* RETURNS
*  1:
*
* GLOBALS AFFECTED
*
*************************************************************************/

#ifdef __MTK_TARGET__
__attribute__ ((section ("INTSRAM_ROCODE"))) 
#endif /* __MTK_TARGET__ */


kal_int8 custom_setAdvEMI(void)
{
   kal_int8    status = 0;

   return status;
}




/*************************************************************************
* FUNCTION
*  custom_get_EXTSRAM_size()
*
* DESCRIPTION
*  Return predefined external SRAM size.
*
* PARAMETERS
*
* RETURNS
*  None
*
* GLOBALS AFFECTED
*
*************************************************************************/
void
custom_get_EXTSRAM_size(kal_uint32 *size)
{
   *size = (kal_uint32)EMI_EXTSRAM_SIZE;
}

/*************************************************************************
* FUNCTION
*  custom_ifLPSDRAM()
*
* DESCRIPTION
*  Query if the memory device is LPSDRAM
*
* PARAMETERS
*
* RETURNS
*  KAL_TRUE: The memory device is LPSDRAM
*  KAL_FALSE: The memory device is not LPSDRAM
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_bool
custom_ifLPSDRAM(void)
{
#if defined(DRAM_CS) && defined(DRAM_SIZE)
   return KAL_TRUE;
#else
   return KAL_FALSE;
#endif      
}


/*************************************************************************
* FUNCTION
*  custom_DynamicClockSwitch
*
* DESCRIPTION
*  This function dedicates to switch the system clock and adjust the EMI
*  according to the working system clock.
*
* PARAMETERS
*  clock    -    clock to switch
*
* RETURNS
*  0 for success; -1 for failure
*
*************************************************************************/
#ifdef DCM_ENABLE

#ifdef __MTK_TARGET__
__attribute__ ((section ("INTSRAM_ROCODE"))) 
#endif /* __MTK_TARGET__ */

int custom_DynamicClockSwitch(mcu_clock_enum clock)
{

   return -1;
}

#endif  /* DCM_ENABLE */


/*************************************************************************
* FUNCTION
*  custom_EMIDynamicClockSwitch_Init
*
* DESCRIPTION
*  This function is used to Init setting for DCM
*
* PARAMETERS
*
*
* RETURNS
*  0 for success; -1 for failure
*
*************************************************************************/

int custom_EMIDynamicClockSwitch_Init(void)
{

    return 0;
}



#endif /* !__UBL__ && !__FUE__ */

__TEMPLATE

    return $template;
}

#****************************************************************************
# subroutine:  custom_EMI_release_h_file_body_for_sp
# return:      custom_EMI_release.h file content for SP
#****************************************************************************
sub custom_EMI_release_h_file_body_for_sp
{
    my ($bb) = @_;
    my $template;
	   
    $template = <<"__TEMPLATE";
#ifndef __CUSTOM_EMI_RELEASE__
#define __CUSTOM_EMI_RELEASE__

/***********************************
    *
    * Definition
    * 
    *********************************/

/**
  * Define EMI's clock rate.
  * comes from EMI_CLK definition in custom_MemoryDevice.h, or highest freq in MDL 
  */
#define __EMI_CLK_200MHZ__

/**
  * Define memory's mode.
  */
#define __EMI_DEVICE_LPDDR1__


/**
  * Define RAM size in Bytes.
  * We have sync with WinMo owner that MD can use from 0x0~0x02000000 (32MB) DRAM size.
  */
#define EMI_EXTSRAM_SIZE (((256)<<20)>> 3)



/***********************************
    *
    * Enum
    * 
    *********************************/

/**
    * EMI clock rate for query.
    */
typedef enum emi_clock_enum_t 
{
   EMI_CLK_UNKNOWN,
   EMI_CLK_13MHZ,
   EMI_CLK_15_36MHZ,
   EMI_CLK_26MHZ,
   EMI_CLK_30_72MHZ,
   EMI_CLK_39MHZ,
   EMI_CLK_52MHZ,
   EMI_CLK_61_44MHZ,
   EMI_CLK_65MHZ,
   EMI_CLK_78MHZ,
   EMI_CLK_91MHZ,
   EMI_CLK_104MHZ,
   EMI_CLK_122_88MHZ,
   EMI_CLK_166MHZ,
   EMI_CLK_200MHZ,
   EMI_CLK_208MHZ,
   EMI_CLK_245_76MHZ,
   EMI_CLK_333MHZ,
   EMI_CLK_400MHZ
} emi_clock_enum;

/**
    * EMI driving current for query.
    */
typedef enum emi_drv_enum_t 
{
   EMI_DRV_UNKNOWN = 0,
   EMI_DRV_2MA = 2,
   EMI_DRV_4MA = 4,
   EMI_DRV_6MA = 6,
   EMI_DRV_8MA = 8,
   EMI_DRV_10MA = 10,
   EMI_DRV_12MA = 12,
   EMI_DRV_14MA = 14,
   EMI_DRV_16MA = 16,
   EMI_DRV_18MA = 18,
   EMI_DRV_20MA = 20
} emi_drv_enum;



/***********************************
    *
    * Exposed APIs.
    * 
    *********************************/

extern emi_clock_enum custom_EMI_QueryFullSpeedClock( void );



#endif /* __CUSTOM_EMI_RELEASE__ */

__TEMPLATE
	   
    return $template;
}

#****************************************************************************
# subroutine:  custom_flash_c_file_body_for_sp
# return:      custom_flash.c file content for SP
#****************************************************************************
sub custom_flash_h_file_body_for_sp
{
    my ($bb) = @_;
    my $template;
	   
    $template = <<"__TEMPLATE";

#ifdef REMAPPING
#define NOR_FLASH_BASE_ADDR 0x10000000
#define RAM_BASE_ADDR       0x00000000
#else
#define NOR_FLASH_BASE_ADDR 0x00000000
#define RAM_BASE_ADDR       0x10000000
#endif

/*******************************************************************************
   NOTICE. NOR FLASH BLOCKS SIZE LOOKUP TABLE
          Each entry element
          {Offset, Block_Size},
               Offset:     the offset address
               Block_Size: the size of block
 *******************************************************************************/
/*
FLASH_REGIONINFO_VAR_MODIFIER FlashBlockTBL NOTREADYYET[] =
{
   {0x0,0x40000},
   EndBlockInfo
};
*/

const kal_char FLASH_ID[] = "0x0089,0x8881";
/****************************************************
 * This part is for auto-gen validity CHECK *
 * Don't modify any content in this comment section *
 * CS0_PART_NUMBER: PF38F5060M0Y3DG
 * CS1_PART_NUMBER: PF38F5060M0Y3DG
 * NOR_FLASH_DENSITY: 0x04000000
 * NOR_FLASH_SIZE(Mb): 512
 
FLASH_REGIONINFO_VAR_MODIFIER FlashRegionInfo oriRegionInfo[] =
{
   {0x40000,16},
   EndoriRegionInfo
};


static NORBankInfo oriBankInfo[] =
{
   { 0x800000, 8 }, 
   EndBankInfo
};

 ****************************************************/
__TEMPLATE
	   
    return $template;
}

#****************************************************************************
# subroutine:  flash_opt_h_file_body_for_sp
# return:      flash_opt.h file content for SP
#****************************************************************************
sub flash_opt_gen_h_file_body_for_sp
{
    my ($bb) = @_;
    my $template;
	   
    $template = <<"__TEMPLATE";

/*
 *******************************************************************************
 PART 1:
   FLASH CONFIG Options Definition here
 *******************************************************************************
*/
#define __SMART_PHONE_PLATFORM__

__TEMPLATE
	   
    return $template;
}
