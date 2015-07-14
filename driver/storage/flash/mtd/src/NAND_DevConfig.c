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
 *  NAND_DevConfig.C
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This is a NAND Flash and GPIO configuration file.
 *
 * Author:
 * -------
 * -------
 * -------
 *
 *==============================================================================
 *              HISTORY
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
 *
 *
 * removed!
 * removed!
 *
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#if defined(FLASH_DISKDRV_DEBUG) && !defined(__MTK_TARGET__)
//MSBB remove     #include "kal_non_specific_general_types.h"
#else
    //RHR remove    #include "kal_release.h"
#endif
#if defined(FLASH_DISKDRV_DEBUG) && !defined(__MTK_TARGET__) /*PC simulator*/
#else
//RHR remove #include "flash_opt.h"
#endif
#include "NAND_MTD_FDM50_internal.h"
#include "NAND_DAL.h"
#include "NAND_DAL_internal.h"

// Add for RHR
    #include "NAND_DevConfig.h"
//RHR remove     #include "kal_non_specific_general_types.h"
    #include "reg_base.h"
    #include "kal_general_types.h"    
// Add for RHR
#include "dcl.h"

#if defined(FLASH_DISKDRV_DEBUG) && !defined(__MTK_TARGET__)
   #include <assert.h>
   #define ASSERT    assert
   #define EXT_ASSERT(e, x, y, z)  assert(e)
   #define NAND_LOGGING
    #define kal_mem_set  memset
    #define kal_mem_cpy memcpy
    #define kal_mem_cmp memcmp
    #define NAND_GPIO_ReturnMode(a) (user_def_cs_num)
    extern kal_uint32 DummyNFI_Reg[1]; /*For simulator*/
    extern  kal_uint8 user_def_cs_num;
#endif

#if ( defined(NAND_SUPPORT)&&defined(__NAND_FDM_50__) && (defined(__NFI_VERSION2__)||defined (__NFI_VERSION3_1__)))

#if !defined(__UBL__)

/*single page cache support, usually apply to old type NAND*/
NAND_MTD_SUB_DRIVER SAMSUNG_SINGLE_CACHE_SUB_DRIVER =
{
    single_Page_Program,    /*ProgramPage*/
    single_Page_Read,       /*ReadPage*/
    NULL,                   /*CopyPage*/
    single_Block_Erase,     /*EraseBlock*/
    samsung_twoPlane_Program, /*TwoPlaneProgram*/
    samsung_twoDie_Program, /*TwoDieProgram*/
    NULL, /*FourPlaneProgram*/
    samsung_twoDie_twoPlane_Program, /*TwoDieTwoPlaneProgram*/
    single_Page_CacheProgram, /*CacheProgram*/
    NULL, /*TwoPlaneCacheProgram*/
    NULL, /*TwoDieCacheProgram*/
    NULL, /*FourPlaneCacheProgram*/
    NULL, /*TwoDieTwoPlaneCacheProgram*/
    samsung_twoPlane_Erase, /*TwoPlaneErase*/
    samsung_twoDie_Erase, /*TwoDieErase*/
    NULL, /*FourPlaneErase*/
    samsung_twoDie_twoPlane_Erase, /*TwoDieTwoPlaneErase*/
#ifdef __SECURITY_OTP__
	NAND_OTPAccess,
	NAND_OTPQueryLength,
#else // __SECURITY_OTP__
	NULL,
	NULL,
#endif // __SECURITY_OTP__
};
NAND_MTD_SUB_DRIVER SAMSUNG_SUB_DRIVER =
{
    single_Page_Program,    /*ProgramPage*/
    single_Page_Read,       /*ReadPage*/
    NULL,                   /*CopyPage*/
    single_Block_Erase,     /*EraseBlock*/
    samsung_twoPlane_Program, /*TwoPlaneProgram*/
    samsung_twoDie_Program, /*TwoDieProgram*/
    toshiba_fourPlane_Program, /*FourPlaneProgram(same as Toshiba)*/
    samsung_twoDie_twoPlane_Program, /*TwoDieTwoPlaneProgram*/
    NULL, /*CacheProgram*/
    NULL, /*TwoPlaneCacheProgram*/
    NULL, /*TwoDieCacheProgram*/
    NULL, /*FourPlaneCacheProgram*/
    NULL, /*TwoDieTwoPlaneCacheProgram*/
    samsung_twoPlane_Erase, /*TwoPlaneErase*/
    samsung_twoDie_Erase, /*TwoDieErase*/
    toshiba_fourPlane_Erase, /*FourPlaneErase (same as Toshiba)*/
    samsung_twoDie_twoPlane_Erase, /*TwoDieTwoPlaneErase*/
#ifdef __SECURITY_OTP__
	NAND_OTPAccess,
	NAND_OTPQueryLength,
#else // __SECURITY_OTP__
	NULL,
	NULL,
#endif // __SECURITY_OTP__
};

/*Do not support Hynix, ST's 2 die operation*/
NAND_MTD_SUB_DRIVER HYNIX_ST_SUB_DRIVER =
{
    single_Page_Program,    /*ProgramPage*/
    single_Page_Read,       /*ReadPage*/
    NULL,                   /*CopyPage*/
    single_Block_Erase,     /*EraseBlock*/
    samsung_twoPlane_Program, /*TwoPlaneProgram*/
    NULL, /*TwoDieProgram*/
    toshiba_fourPlane_Program, /*FourPlaneProgram(same as Toshiba)*/
    NULL, /*TwoDieTwoPlaneProgram*/
    NULL, /*CacheProgram*/
    NULL, /*TwoPlaneCacheProgram*/
    NULL, /*TwoDieCacheProgram*/
    NULL, /*FourPlaneCacheProgram*/
    NULL, /*TwoDieTwoPlaneCacheProgram*/
    samsung_twoPlane_Erase, /*TwoPlaneErase*/
    NULL, /*TwoDieErase*/
    toshiba_fourPlane_Erase, /*FourPlaneErase (same as Toshiba)*/
    NULL, /*TwoDieTwoPlaneErase*/
#ifdef __SECURITY_OTP__
    NAND_OTPAccess,
    NAND_OTPQueryLength,
#else // __SECURITY_OTP__
    NULL,
    NULL,
#endif // __SECURITY_OTP__

};

NAND_MTD_SUB_DRIVER TOSHIBA_SUB_DRIVER =
{
    single_Page_Program,    /*ProgramPage*/
    single_Page_Read,       /*ReadPage*/
    NULL,                   /*CopyPage*/
    single_Block_Erase,     /*EraseBlock*/
    toshiba_twoPlane_Program, /*TwoPlaneProgram*/
    NULL, /*TwoDieProgram*/
    toshiba_fourPlane_Program, /*FourPlaneProgram(same as Toshiba)*/
    NULL, /*TwoDieTwoPlaneProgram*/
    single_Page_CacheProgram, /*CacheProgram*/
    toshiba_twoPlane_CacheProgram, /*TwoPlaneCacheProgram*/
    NULL, /*TwoDieCacheProgram*/
    toshiba_fourPlane_CacheProgram, /*FourPlaneCacheProgram*/
    NULL, /*TwoDieTwoPlaneCacheProgram*/
    toshiba_twoPlane_Erase, /*TwoPlaneErase*/
    NULL, /*TwoDieErase*/
    toshiba_fourPlane_Erase, /*FourPlaneErase (same as Toshiba)*/
    NULL, /*TwoDieTwoPlaneErase*/
	NULL,
	NULL,
};

NAND_MTD_SUB_DRIVER MICRON_SUB_DRIVER =
{
    single_Page_Program,    /*ProgramPage*/
    single_Page_Read,       /*ReadPage*/
    NULL,                   /*CopyPage*/
    single_Block_Erase,     /*EraseBlock*/
    micron_twoPlane_Program, /*TwoPlaneProgram*/
    micron_twoDie_Program, /*TwoDieProgram*/
    NULL, /*FourPlaneProgram(same as Toshiba)*/
    micron_twoDie_twoPlane_Program, /*TwoDieTwoPlaneProgram*/
    single_Page_CacheProgram, /*CacheProgram*/
    micron_twoPlane_CacheProgram, /*TwoPlaneCacheProgram*/
    micron_twoDie_CacheProgram, /*TwoDieCacheProgram*/
    NULL, /*FourPlaneCacheProgram*/
    micron_twoDie_twoPlane_CacheProgram, /*TwoDieTwoPlaneCacheProgram*/
    micron_twoPlane_Erase, /*TwoPlaneErase*/
    micron_twoDie_Erase, /*TwoDieErase*/
    NULL, /*FourPlaneErase (same as Toshiba)*/
    micron_twoDie_twoPlane_Erase, /*TwoDieTwoPlaneErase*/
#ifdef __SECURITY_OTP__
    NAND_OTPAccess,
    NAND_OTPQueryLength,
#else // __SECURITY_OTP__
    NULL,
    NULL,
#endif // __SECURITY_OTP__
};

#else  // !defined(__UBL__)

// For Bootloader case, only need to include read routines.
NAND_MTD_SUB_DRIVER SAMSUNG_SINGLE_CACHE_SUB_DRIVER =
{
#if ( defined(__NAND_FLASH_HARDWARE_TEST__) && defined(__MAUI_BASIC__) && defined(__EMULATE_NFB_BIT_ERROE__) ) || ( defined(__UBL_NAND_FULL_DRIVER__) )
    single_Page_Program,    /*ProgramPage*/
#else
    NULL,    /*ProgramPage*/
#endif
    single_Page_Read,       /*ReadPage*/
    NULL,                   /*CopyPage*/
#if ( defined(__UBL_NAND_FULL_DRIVER__) )
    single_Block_Erase,     /*EraseBlock*/
#else // ( defined(__UBL_NAND_FULL_DRIVER__) )
    NULL,     /*EraseBlock*/
#endif //( defined(__UBL_NAND_FULL_DRIVER__) )
    NULL, /*TwoPlaneProgram*/
    NULL, /*TwoDieProgram*/
    NULL, /*FourPlaneProgram*/
    NULL, /*TwoDieTwoPlaneProgram*/
    NULL, /*CacheProgram*/
    NULL, /*TwoPlaneCacheProgram*/
    NULL, /*TwoDieCacheProgram*/
    NULL, /*FourPlaneCacheProgram*/
    NULL, /*TwoDieTwoPlaneCacheProgram*/
    NULL, /*TwoPlaneErase*/
    NULL, /*TwoDieErase*/
    NULL, /*FourPlaneErase*/
    NULL, /*TwoDieTwoPlaneErase*/
	NULL,
	NULL,
};
NAND_MTD_SUB_DRIVER SAMSUNG_SUB_DRIVER =
{
#if ( defined(__NAND_FLASH_HARDWARE_TEST__) && defined(__MAUI_BASIC__) && defined(__EMULATE_NFB_BIT_ERROE__) ) || ( defined(__UBL_NAND_FULL_DRIVER__) )
    single_Page_Program,    /*ProgramPage*/
#else
    NULL,    /*ProgramPage*/
#endif
    single_Page_Read,       /*ReadPage*/
    NULL,                   /*CopyPage*/
#if ( defined(__UBL_NAND_FULL_DRIVER__) )
    single_Block_Erase,     /*EraseBlock*/
#else // ( defined(__UBL_NAND_FULL_DRIVER__) )
    NULL,     /*EraseBlock*/
#endif //( defined(__UBL_NAND_FULL_DRIVER__) )
	NULL, /*TwoPlaneProgram*/
    NULL, /*TwoDieProgram*/
    NULL, /*FourPlaneProgram(same as Toshiba)*/
    NULL, /*TwoDieTwoPlaneProgram*/
    NULL, /*CacheProgram*/
    NULL, /*TwoPlaneCacheProgram*/
    NULL, /*TwoDieCacheProgram*/
    NULL, /*FourPlaneCacheProgram*/
    NULL, /*TwoDieTwoPlaneCacheProgram*/
    NULL, /*TwoPlaneErase*/
    NULL, /*TwoDieErase*/
    NULL, /*FourPlaneErase (same as Toshiba)*/
    NULL, /*TwoDieTwoPlaneErase*/
	NULL,
	NULL,
};

/*Do not support Hynix, ST's 2 die operation*/
NAND_MTD_SUB_DRIVER HYNIX_ST_SUB_DRIVER =
{
#if ( defined(__NAND_FLASH_HARDWARE_TEST__) && defined(__MAUI_BASIC__) && defined(__EMULATE_NFB_BIT_ERROE__) ) || ( defined(__UBL_NAND_FULL_DRIVER__) )
    single_Page_Program,    /*ProgramPage*/
#else
    NULL,    /*ProgramPage*/
#endif
    single_Page_Read,       /*ReadPage*/
    NULL,                   /*CopyPage*/
#if ( defined(__UBL_NAND_FULL_DRIVER__) )
    single_Block_Erase,     /*EraseBlock*/
#else // ( defined(__UBL_NAND_FULL_DRIVER__) )
    NULL,     /*EraseBlock*/
#endif //( defined(__UBL_NAND_FULL_DRIVER__) )
	NULL, /*TwoPlaneProgram*/
    NULL, /*TwoDieProgram*/
    NULL, /*FourPlaneProgram(same as Toshiba)*/
    NULL, /*TwoDieTwoPlaneProgram*/
    NULL, /*CacheProgram*/
    NULL, /*TwoPlaneCacheProgram*/
    NULL, /*TwoDieCacheProgram*/
    NULL, /*FourPlaneCacheProgram*/
    NULL, /*TwoDieTwoPlaneCacheProgram*/
    NULL, /*TwoPlaneErase*/
    NULL, /*TwoDieErase*/
    NULL, /*FourPlaneErase (same as Toshiba)*/
    NULL, /*TwoDieTwoPlaneErase*/
	NULL,
	NULL,
};

NAND_MTD_SUB_DRIVER TOSHIBA_SUB_DRIVER =
{
#if ( defined(__NAND_FLASH_HARDWARE_TEST__) && defined(__MAUI_BASIC__) && defined(__EMULATE_NFB_BIT_ERROE__) ) || ( defined(__UBL_NAND_FULL_DRIVER__) )
    single_Page_Program,    /*ProgramPage*/
#else
    NULL,    /*ProgramPage*/
#endif
    single_Page_Read,       /*ReadPage*/
    NULL,                   /*CopyPage*/
#if ( defined(__UBL_NAND_FULL_DRIVER__) )
    single_Block_Erase,     /*EraseBlock*/
#else // ( defined(__UBL_NAND_FULL_DRIVER__) )
    NULL,     /*EraseBlock*/
#endif //( defined(__UBL_NAND_FULL_DRIVER__) )
	NULL, /*TwoPlaneProgram*/
    NULL, /*TwoDieProgram*/
    NULL, /*FourPlaneProgram(same as Toshiba)*/
    NULL, /*TwoDieTwoPlaneProgram*/
    NULL, /*CacheProgram*/
    NULL, /*TwoPlaneCacheProgram*/
    NULL, /*TwoDieCacheProgram*/
    NULL, /*FourPlaneCacheProgram*/
    NULL, /*TwoDieTwoPlaneCacheProgram*/
    NULL, /*TwoPlaneErase*/
    NULL, /*TwoDieErase*/
    NULL, /*FourPlaneErase (same as Toshiba)*/
    NULL, /*TwoDieTwoPlaneErase*/
	NULL,
	NULL,
};

NAND_MTD_SUB_DRIVER MICRON_SUB_DRIVER =
{
#if ( defined(__NAND_FLASH_HARDWARE_TEST__) && defined(__MAUI_BASIC__) && defined(__EMULATE_NFB_BIT_ERROE__) ) || ( defined(__UBL_NAND_FULL_DRIVER__) )
    single_Page_Program,    /*ProgramPage*/
#else
    NULL,    /*ProgramPage*/
#endif
    single_Page_Read,       /*ReadPage*/
    NULL,                   /*CopyPage*/
#if ( defined(__UBL_NAND_FULL_DRIVER__) )
    single_Block_Erase,     /*EraseBlock*/
#else // ( defined(__UBL_NAND_FULL_DRIVER__) )
    NULL,     /*EraseBlock*/
#endif //( defined(__UBL_NAND_FULL_DRIVER__) )
	NULL, /*TwoPlaneProgram*/
    NULL, /*TwoDieProgram*/
    NULL, /*FourPlaneProgram(same as Toshiba)*/
    NULL, /*TwoDieTwoPlaneProgram*/
    NULL, /*CacheProgram*/
    NULL, /*TwoPlaneCacheProgram*/
    NULL, /*TwoDieCacheProgram*/
    NULL, /*FourPlaneCacheProgram*/
    NULL, /*TwoDieTwoPlaneCacheProgram*/
    NULL, /*TwoPlaneErase*/
    NULL, /*TwoDieErase*/
    NULL, /*FourPlaneErase (same as Toshiba)*/
    NULL, /*TwoDieTwoPlaneErase*/
	NULL,
	NULL,
};

#endif  // !defined(__UBL__)
/*******************************************************************************
 *  Global variable
 *******************************************************************************/
#define NFI_EVENT   0x1

flash_list Default_ID_Table =
      { simu_NAND_1/*DevName_enum*/, {'D','E','F','A','U','L','T',0xFF}/*ID_info*/,
        {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}/*ID_valid_mask*/, AUTO_NAND_DETECT/*IOWidth*/, AUTO_NAND_DETECT/*address_cycle*/,
        AUTO_NAND_DETECT/*planeNum*/, AUTO_NAND_DETECT/*dieNum*/, AUTO_NAND_DETECT/*pageSize*/,AUTO_NAND_DETECT/*spareSize*/,AUTO_NAND_DETECT/*blockPage*/,AUTO_NAND_DETECT/*deviceSize (MByte)*/,
        AUTO_NAND_DETECT/*supportMPType*/, AUTO_NAND_DETECT/*supportMEType*/, AUTO_NAND_DETECT/*CopyBackType*/, (NAND_MTD_SUB_DRIVER*)AUTO_NAND_DETECT/*driverSet*/};

const kal_uint8 ID_512_Mask[8] = {0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
const kal_uint8 ID_2K_Mask[8] = {0xFF, 0xFF, 0xFF, 0xFF, 0x7C, 0x00, 0x00, 0x00};

/*[Notice] NAND_ID_Table should sort by
1. manufacture ID group;
2 ID valid bite (from large -> small)*/
#if defined(FLASH_DISKDRV_DEBUG) && !defined(__MTK_TARGET__) /*PC simulator*/
    flash_list NAND_ID_Table[] =
#else
const flash_list NAND_ID_Table[] =
#endif
{
 /*Simulation (FAKE NAND)*/
    /*ID_byte == 2*/
    /* Fake NAND for simulation(refer to K9F1208U0M) */
    { simu_NAND_0/*DevName_enum*/,{'0','1','F','A','K','E',0xFF,0xFF}/*ID_info*/,
      {0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x00,0x00}/*ID_valid_mask*/, 8/*IOWidth*/, 4/*address_cycle*/,
       4/*planeNum*/,  1/*dieNum*/, 512/*pageSize*/,16/*spareSize*/,32/*blockPage*/,64/*deviceSize (MByte)*/,FOUR_PLANE_OP|PLANE_INTERLACED/*supportMPType*/,FOUR_PLANE_OP|PLANE_INTERLACED/*supportMEType*/,AUTO_NAND_DETECT/*CopyBackType*/, (NAND_MTD_SUB_DRIVER*)AUTO_NAND_DETECT/*driverSet*/},

 /*Samsung*/
    /*ID_byte == 3*/
    /* K9F1G08U0A */
    { SAMSUNG_K9F1G08U0A/*DevName_enum*/, {0xEC,0xF1,0x80,0x15,0x40,0xFF,0xFF,0xFF}/*ID_info*/,
      {0xFF,0xFF,0x80,0xFF,0x00/*0x7C*/,0x00,0x00,0x00}/*ID_valid_mask*/,AUTO_NAND_DETECT/*IOWidth*/, AUTO_NAND_DETECT/*address_cycle*/,
      AUTO_NAND_DETECT/*planeNum*/,  AUTO_NAND_DETECT/*dieNum*/, AUTO_NAND_DETECT/*pageSize*/,AUTO_NAND_DETECT/*spareSize*/,AUTO_NAND_DETECT/*blockPage*/,AUTO_NAND_DETECT/*deviceSize (MByte)*/,
      AUTO_NAND_DETECT/*supportMPType*/,AUTO_NAND_DETECT/*supportMEType*/,AUTO_NAND_DETECT/*CopyBackType*/, (NAND_MTD_SUB_DRIVER*)AUTO_NAND_DETECT/*driverSet*/},

/*Hynix*/
    /*ID_byte == 4*/
    { HYNIX_HY27UF081G2A/*DevName_enum*/, {0xAD,0xF1,0x80,0x1D,0xFF,0xFF,0xFF,0xFF}/*ID_info*/,
      {0xFF,0xFF,0xFF,0xFF,0x00,0x00,0x00,0x00}/*ID_valid_mask*/, AUTO_NAND_DETECT/*IOWidth*/, AUTO_NAND_DETECT/*address_cycle*/,
      AUTO_NAND_DETECT/*planeNum*/,  AUTO_NAND_DETECT/*dieNum*/, AUTO_NAND_DETECT/*pageSize*/,AUTO_NAND_DETECT/*spareSize*/,AUTO_NAND_DETECT/*blockPage*/,AUTO_NAND_DETECT/*deviceSize (MByte)*/,
      AUTO_NAND_DETECT/*supportMPType*/,AUTO_NAND_DETECT/*supportMEType*/,AUTO_NAND_DETECT/*CopyBackType*/, (NAND_MTD_SUB_DRIVER*)AUTO_NAND_DETECT/*driverSet*/},

    { PTC_FST1G54AUCA/*DevName_enum*/, {0x92,0xF1,0x00,0x15,0x00,0xFF,0xFF,0xFF}/*ID_info*/,
      {0xFF,0xFF,0x0F,0x7F,0x02,0x00,0x00,0x00}/*ID_valid_mask*/, AUTO_NAND_DETECT/*IOWidth*/, 5/*address_cycle*/,
      AUTO_NAND_DETECT/*planeNum*/,  AUTO_NAND_DETECT/*dieNum*/, AUTO_NAND_DETECT/*pageSize*/,AUTO_NAND_DETECT/*spareSize*/,AUTO_NAND_DETECT/*blockPage*/,AUTO_NAND_DETECT/*deviceSize (MByte)*/,
      CACHE_PROGRAM/*supportMPType*/,AUTO_NAND_DETECT/*supportMEType*/,AUTO_NAND_DETECT/*CopyBackType*/, (NAND_MTD_SUB_DRIVER*)AUTO_NAND_DETECT/*driverSet*/},

/*Last one*/
    { MAX_NAND_NAME/*DevName_enum*/,{0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF}/*ID_info*/,
      {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}/*ID_valid_mask*/, 0, 0, 0,  0, 0,0,0,0,0,0,0}   // End of ID Table
};


#if defined(FLASH_DISKDRV_DEBUG) && !defined(__MTK_TARGET__)
    extern kal_uint32 DummyNFI_Reg[1]; /*For simulator*/
    #define NAND_GPIO_ReturnMode(a) (user_def_cs_num)
#endif
kal_uint8 NFI_GPIO_Setting(void)
{
    kal_uint8 CS_num = 1;
#if ((defined(MT6228)) || (defined(MT6229)) || (defined(MT6230)))
    *NFI_GPIO_CON &= 0x000F;
    if (NAND_GPIO_ReturnMode(25) == 2) {CS_num = 2;} /*[MAUI_00580753]NAND_CS1 GPIO detection -- 2007/12/04*/   
#elif defined(MT6225)
    //*NFI_GPIO_CON1 &= 0x03CF;
    //*NFI_GPIO_CON1 |= 0x5420;
    *NFI_GPIO_CON1 &= 0x03FF;
    *NFI_GPIO_CON1 |= 0x5400;
    if (NAND_GPIO_ReturnMode(34) == 2) {CS_num = 2;} /*[MAUI_00580753]NAND_CS1 GPIO detection -- 2007/12/04*/   
    *NFI_GPIO_CON2 &= 0xFFC0;
    *NFI_GPIO_CON2 |= 0x0015;
#elif defined(MT6217)
    *NFI_GPIO_CON &= 0xC003;
    *NFI_GPIO_CON |= 0x1554;
    if (NAND_GPIO_ReturnMode(24) == 2) {CS_num = 2;} /*[MAUI_00580753]NAND_CS1 GPIO detection -- 2007/12/04*/   
#elif (defined(MT6238)) || (defined(MT6239)) /*MAUI_00728731*/
    //*NFI_GPIO_CON1 &= 0x0F3F;			// Use CS1 by default.
    //*NFI_GPIO_CON1 |= 0x5080;
    *NFI_GPIO_CON1 &= 0x0FFF;			// Normal setting. Auto-detect the setting.
    *NFI_GPIO_CON1 |= 0x5000;
    if (NAND_GPIO_ReturnMode(19) == 2) {CS_num = 2;} /*[MAUI_00580753]NAND_CS1 GPIO detection -- 2007/12/04*/   
    *NFI_GPIO_CON2 &= 0xFF00;
    *NFI_GPIO_CON2 |= 0x0055;
    // Configure the NLD driving(NLD_OD) and NAND driving(NAND_OD)
    *NFI_ACIF_CON0 &= 0x1fff;
    //*NFI_ACIF_CON0 |= ((7<<13) | (7<<9));   // bit 15_13:NLD_OD. bit 11~9:NAND_OD.   0x7: 8mA with slew rate on.
    *NFI_ACIF_CON0 |= (7<<13);   // bit 15_13:NLD_OD. bit 11~9:NAND_OD.   0x7: 8mA with slew rate on.
#elif (defined (MT6235)) || (defined(MT6235B))/*MAUI_00728731*/
    //*NFI_GPIO_CON1 &= 0xF3FF;			// Use CS1 by default
    //*NFI_GPIO_CON1 |= 0x0800;
    if (NAND_GPIO_ReturnMode(29) == 2) {CS_num = 2;} /*[MAUI_00580753]NAND_CS1 GPIO detection -- 2007/12/04*/   
    *NFI_GPIO_CON2 &= 0xC003;
    *NFI_GPIO_CON2 |= 0x1554;
    // Configure the NLD driving(NLD_OD) and NAND driving(NAND_OD)
    *NFI_ACIF_CON0 &= 0x1fff;
//    *NFI_ACIF_CON0 |= ((7<<13) | (7<<9));   // bit 15_13:NLD_OD. bit 11~9:NAND_OD.   0x7: 8mA with slew rate on.
    *NFI_ACIF_CON0 |= (7<<13);   // bit 15_13:NLD_OD. bit 11~9:NAND_OD.   0x7: 8mA with slew rate on.
#elif (defined (MT6268A) || defined (MT6268)) /*MAUI_00757139*/
	/*NAND control pin is dedicate */
    if (NAND_GPIO_ReturnMode(83) == 2) {CS_num = 2;} /*[MAUI_00580753]NAND_CS1 GPIO detection -- 2007/12/04*/   
    // Configure the NLD driving(NLD_OD) and NAND driving(NAND_OD)
    *NFI_ACIF_CON3 &= 0xf03f;
    *NFI_ACIF_CON3 |= ((7<<9) | (5<<6));   // bit 11_9:NLD_OD. bit 8~6:NAND_OD.   0x7: 8mA with slew rate on.
#elif (defined (MT6253T) || defined (MT6253))
	if (NAND_GPIO_ReturnMode(46) == 2) {CS_num = 2;}
    *NFI_GPIO_CON1 &= 0x000F;
    *NFI_GPIO_CON1 |= 0x5550;
    // Configure the NLD driving(NLD_OD) and NAND driving(NAND_OD)
    *NFI_ACIF_CON1 &= 0xfff8;
    *NFI_ACIF_CON1 |= (5<<0);   // bit 2~0:NFI. bit1:E4, bit0:E8
#elif (defined(MT6236) || defined(MT6236B))
	if (NAND_GPIO_ReturnMode(51) == 3) {CS_num = 2;}
  // Configure the NLD driving(NLD_OD) and NAND driving(NAND_OD)
  // bit 6   : NLD Slew rate, 0: Fast, 1: Slow
  // bit 5..3: NLD output driving 8mA(Hex:6)
  // bit 2   : NAND control slew rate
  // bit 1..0 +IODRV0 bit 31: NAND control driving 8mA
  *NFI_IO_DRV0 &=0x7FFFFFFF;
  *NFI_IO_DRV1 &=0xFFFFFF80;
  *NFI_IO_DRV1 |= ((1<<6)|(6<<3)|(1<<2)|(6>>1));
#elif (defined(MT6270A) || defined(TK6280))
	if (NAND_GPIO_ReturnMode(27) == 2) {CS_num = 2;}    
#elif (defined(MT6256))
	if (NAND_GPIO_ReturnMode(18) == 7) {CS_num = 2;}  	   
	#if defined(MT6256_S00) //Kuohong
	   // Sel ect those GPIO
	  *NFI_GPIO_MODE7 = (*NFI_GPIO_MODE7 & 0x00FF) | 0x1100; //NLD7,NLD6
	  *NFI_GPIO_MODE8 = 0x1111;                              //NLD5,NLD4,NLD3,NLD2
	  *NFI_GPIO_MODE9 = 0x1111;                              //NLD1,NLD0,NRNB,NCLE
	  *NFI_GPIO_MODE10 = 0x1111;                             //NCE0B,NALE,NWEB,NREB
	  #if 0 // Reserved for 16 bit check
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
	  #endif // end of =Reserved for 16 bit check
	  // Configure the NLD driving(NLD_OD) and NAND driving(NAND_OD)
	  *NFI_IO_DRV1 &=0xFFFFF88F;
	  // [10]   :NLD8~NLD0 SR control
	  // [9..8] :NLD8~NLD0 output driving control
	  // [6]    :NRNB, NCLE, NALE, NWEB, NREB, NCEB SR control
	  // [5..4] :NRNB, NCLE, NALE, NWEB, NREB, NCEB output driving control
	  *NFI_IO_DRV1 |= ((1<<10)|(1<<8)|(1<<6)|(1<<4));
	  
  #else
    *NFI_DEBUG_CON1 &=0xFFFB;  // Disable NFI writebuffable
    	#if 0 // Reserved for 16 bit check
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
		#endif // end of =Reserved for 16 bit check
		*NFI_GPIO_MODE8 &= ~(0x000F);										  // NLD10, 9, 8, 7
		*NFI_GPIO_MODE8 |=   0x0001;    
		*NFI_GPIO_MODE9  = 0x1111;                        // NLD 6, 5, 4, 3   
		*NFI_GPIO_MODE10 = 0x1111;                        // NLD 2, 1, 0, RDY 
		*NFI_GPIO_MODE11 = 0x1111;                        // CLE, ALE, WE, RE 
		*NFI_GPIO_MODE12 &= ~(0x000F);
		*NFI_GPIO_MODE12 |=   0x0001;   										//   x, x, x, CE0  
		*NFI_IO_DRV1 &=~(0x00000777);
		*NFI_IO_DRV1 |= (0x00000555); 									 // 8 mA and Slow slew rate
  #endif
#elif defined(MT6276)
  if (NAND_GPIO_ReturnMode(83) == 2) {CS_num = 2;}  	
  // [14..11]: NWEB, NREB
  // [10..8] : NRNB, NCLE, NALE, NCE0B
  // [7.. 4] : NLD17~NLD0
  *NFI_ACIF_CON4 &= 0x000F;
  *NFI_ACIF_CON4 |= ((0x0B<<11)|(0x06<<8)|(0x0B<<4));
  #if !defined(MT6276_S00)
  *NFI_DEBUG_CON1 &=0xFFFD;
  #endif
#elif defined(MT6573)
	//** Kuohong : Need to add later.
#elif defined(MT6575)
	//** Kuohong : Need to add later.
#elif defined(MT6577)
	//** Kuohong : Need to add later.
#elif defined(MT6255)
    *NFI_DEBUG_CON1 &=0xFFFB;  // Disable NFI writebuffable
  // MT6255 dedicated pin for NAND booting.
  if (NAND_GPIO_ReturnMode(61) == 5) {CS_num = 2;}  	
  *NFI_IO_DRV1 &= 0xFFFFF00F;
  *NFI_IO_DRV1 |= ((1<<10)|(1<<8)|(1<<6)|(1<<4));
#elif defined(MT6280)
    *NFI_DEBUG_CON1 &=0xFFFB;  // Disable NFI writebuffable  
    // MT6280 dedicated pin for NAND booting
	  //read bonding option,  DONGLE_SIP mode
		if(*NFI_MD_CHIP_STATUS&0x0002)
		{	
			*NFI_GPIO_1000 = 0x1111;							//NLD0, 1, 2, 3
			*NFI_GPIO_1100 = 0x1111;							//NLD4, 5, 6, 7
		
		}
		else 
		{		
		
			*NFI_GPIO_1400 = (*NFI_GPIO_1400 & 0x00FF)|0x4400;	//NLD0,1 
			*NFI_GPIO_1500 = 0x4444;							//NLD2,3,4,5 
			*NFI_GPIO_1600 = (*NFI_GPIO_1600 & 0xFF00)|0x0044; 	//NLD6,7
		}	
	
		*NFI_GPIO_2500 = 0x1111;							 	//NRNB, NWEB, NREB, NCLE
		*NFI_GPIO_2600 = (*NFI_GPIO_2600 & 0xFF00) | 0x0011; 	//NALE, NCE0B            
		
    // No plan to support 2 CE NAND from pinmux table
		// Driving setting, default 8mA
		//NLD7~0, NLD8~15
		*NFI_GPIO_DRV1 &=~(0x0003<<14) | (0x0003<<8); 
		*NFI_GPIO_DRV1 |= (0x0001<<14) | (0x0001<<8);		
	  // CE0, ALE, CLE, NRE, NWE, NRNB
		*NFI_GPIO_DRV6 &=~((0x0003<<12)|(0x0003<<10)|(0x0003<<8)|(0x0003<<6)|(0x0003<<4)|(0x0003<<2)); 
		*NFI_GPIO_DRV6 |= ((0x0001<<12)|(0x0001<<10)|(0x0001<<8)|(0x0001<<6)|(0x0001<<4)|(0x0001<<2)); 
		
		// Enable Slew rate control		
		// NLD7~0, NLD8~15
		*NFI_GPIO_SR1 |= ((0x0001<<5) |(0x0001<<3));
		// CLE, NRE, NWE, NRNB
		*NFI_GPIO_SR2 |= ((0x0001<<15)|(0x0001<<14)|(0x0001<<13)|(0x0001<<12));
	  // CE0, ALE
		*NFI_GPIO_SR3 |= ((0x0001<<1)|(0x0001<<0));  
#else
    *NFI_GPIO_CON &= 0xC003;
    *NFI_GPIO_CON |= 0x1554;
#endif
    return CS_num;
}

#endif /*( defined(__NAND_FDM_50__) && (defined(__NFI_VERSION2__) || defined(__NFI_VERSION3_1__)))*/
