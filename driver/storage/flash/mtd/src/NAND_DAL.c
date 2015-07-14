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
 *  NAND_DAL.C
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This is a NAND Flash Device Abstraction Layer file.
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
 * removed!
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
#if defined(FLASH_DISKDRV_DEBUG) && !defined(__MTK_TARGET__) /*PC simulator*/
//MSBB remove #include "kal_non_specific_general_types.h"
#else
#include "kal_public_api.h" //MSBB change #include "kal_release.h"
#include "page.h"
#include "flash_opt.h"
#endif

//RHR remove #include "fat_fs.h"
#include "NAND_MTD_FDM50_internal.h"
#include "NAND_DAL.h"
#include "NAND_DAL_internal.h"
#include "NAND_DAL_Version.h"
#include "system_trc.h"
#include "nfi_hw_info.h"
// Add for RHR
//RHR remove #include "kal_non_specific_general_types.h"
#include "fs_errcode.h"
#include "fota_error.h"
#include "fs_type.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "kal_internal_api.h"
#include "kal_trace.h"
// Add for RHR

#ifdef FLASH_DISKDRV_DEBUG
   #if defined DAL_DLL_VERSION
       #define ASSERT(expr)    {if(!(expr)) { MTD_WriteErrMsg("[dbg_ASSERT]",#expr,__FILE__ ,__LINE__,0,0,0);return MTD_STATUS_ERROR;}}
       #define EXT_ASSERT(expr, x, y, z)  {if(!(expr)) { MTD_WriteErrMsg("[force_ASSERT]",#expr,__FILE__,__LINE__,x,y,z);return MTD_STATUS_ERROR;}}
   #else
   #include <assert.h>
   #define ASSERT    assert
   #define EXT_ASSERT(e, x, y, z)  assert(e)
   #endif
   #define NAND_LOGGING
    #define kal_mem_set  memset
    #define kal_mem_cpy memcpy
    #define kal_mem_cmp memcmp
    //#define pdn_nfi(expr) do { } while (0);
#endif

#if ( defined(NAND_SUPPORT)&& defined(__NAND_FDM_50__) && (defined(__NFI_VERSION2__)|| defined(__NFI_VERSION3_1__)))

#if defined (__NAND_LMT__)
extern const kal_bool bWholeImage;
#endif // defined (__NAND_LMT__)
#if defined(__SMART_MD_NFI_DRIVER__)    // Smart phone start alone driver
	#ifndef _NAND_FLASH_BOOTING_
		#define _NAND_FLASH_BOOTING_
	#endif
#endif
static struct_map_cache MapCache[MAX_MULTIPAGE_NUM][2] = {{{0}}};
static kal_uint8 MapCacheCount[MAX_MULTIPAGE_NUM]={0};

const kal_uint8 ZEROBIT[256] ={
8, 7, 7, 6, 7, 6, 6, 5, 7, 6, 6, 5, 6, 5, 5, 4,
7, 6, 6, 5, 6, 5, 5, 4, 6, 5, 5, 4, 5, 4, 4, 3,
7, 6, 6, 5, 6, 5, 5, 4, 6, 5, 5, 4, 5, 4, 4, 3,
6, 5, 5, 4, 5, 4, 4, 3, 5, 4, 4, 3, 4, 3, 3, 2,
7, 6, 6, 5, 6, 5, 5, 4, 6, 5, 5, 4, 5, 4, 4, 3,
6, 5, 5, 4, 5, 4, 4, 3, 5, 4, 4, 3, 4, 3, 3, 2,
6, 5, 5, 4, 5, 4, 4, 3, 5, 4, 4, 3, 4, 3, 3, 2,
5, 4, 4, 3, 4, 3, 3, 2, 4, 3, 3, 2, 3, 2, 2, 1,
7, 6, 6, 5, 6, 5, 5, 4, 6, 5, 5, 4, 5, 4, 4, 3,
6, 5, 5, 4, 5, 4, 4, 3, 5, 4, 4, 3, 4, 3, 3, 2,
6, 5, 5, 4, 5, 4, 4, 3, 5, 4, 4, 3, 4, 3, 3, 2,
5, 4, 4, 3, 4, 3, 3, 2, 4, 3, 3, 2, 3, 2, 2, 1,
6, 5, 5, 4, 5, 4, 4, 3, 5, 4, 4, 3, 4, 3, 3, 2,
5, 4, 4, 3, 4, 3, 3, 2, 4, 3, 3, 2, 3, 2, 2, 1,
5, 4, 4, 3, 4, 3, 3, 2, 4, 3, 3, 2, 3, 2, 2, 1,
4, 3, 3, 2, 3, 2, 2, 1, 3, 2, 2, 1, 2, 1, 1, 0};


#define _DAL_MAX_PAGE_SIZE_          NFI_MAX_DATA_SIZE_PER_PAGE
#define _DAL_MAX_SPARE_SIZE_         NFI_MAX_SPARE_SIZE_PER_PAGE

static kal_uint32 DAL_spare_buff[_DAL_MAX_SPARE_SIZE_/4]; /*DAL buff (for Copy)*/


char NAND_text_buff[100]; /*For debug message*/

kal_bool DAL_is_initialized = KAL_FALSE;
kal_uint8 CurDiskIndex = 0;
flash_info_2 Flash_Info;
add_convert Add_Cnvt;
extern mtd_if_para Mtd_para;

#if defined __UBL__ /*bootloader case*/
extern void dbg_print(kal_char *fmt, ...);
#endif

#if !defined(__FUE__)

extern void get_MTD_lock(void);
extern void free_MTD_lock(void);

#else /* __FUE__ */

#define init_MTD_lock()

#define get_MTD_lock()

#define free_MTD_lock()

#endif
#if defined (_NAND_FLASH_BOOTING_) || defined(__NANDFDM_MULTI_INSTANCE__) || (defined(__UP_PKG_ON_NAND__) && defined(NAND_SUPPORT))
kal_bool DemandPageingRead = KAL_FALSE;
static kal_uint16 DAL_Bank_Array[MAX_MULTIPAGE_NUM]; /*For DAL_fdmxx function*/
static kal_uint16 DAL_Bank_Array2[MAX_MULTIPAGE_NUM]; /*For DAL_fdmCopy function*/
#if !defined(__NANDFDM_MULTI_INSTANCE__)
static kal_uint32 FAT_Start_ZoneNum = DWORD_INVALID;
static kal_uint32 FAT_Start_Section_Offset = DWORD_INVALID;
#else  // !defined(__NANDFDM_MULTI_INSTANCE__)
static kal_uint32 FAT_Start_ZoneNum[NAND_DISK_NUM];
static kal_uint32 FAT_Start_Section_Offset[NAND_DISK_NUM];
#endif  //  !defined(__NANDFDM_MULTI_INSTANCE__)
#if !defined(__NANDFDM_MULTI_INSTANCE__)

extern const kal_uint32 NFB_BASE_ADDRESS;

extern const kal_uint32 NFB_ALLOCATED_FAT_SPACE;

#else  // !defined(__NANDFDM_MULTI_INSTANCE__)

extern kal_uint32 NFB_BASE_ADDRESS[NAND_DISK_NUM];
extern kal_uint32 NFB_ALLOCATED_FAT_SPACE[NAND_DISK_NUM];
extern const kal_uint8 NANDDiskNum;

#endif  //  !defined(__NANDFDM_MULTI_INSTANCE__)

extern kal_bool use_interrupt;  // KAL_TRUE for using interrupt; KAL_FALSE for using polling

#endif /* _NAND_FLASH_BOOTING_ || defined(__NANDFDM_MULTI_INSTANCE__) || (__UP_PKG_ON_NAND__ && NAND_SUPPORT) */

#if defined (_NAND_FLASH_BOOTING_) || defined(__NANDFDM_MULTI_INSTANCE__) || (defined(__UP_PKG_ON_NAND__)||defined(__SECURITY_OTP__) && defined(NAND_SUPPORT))
static kal_uint32 NFB_tmp_D_Buff[_DAL_MAX_PAGE_SIZE_/4];
static kal_uint32 NFB_tmp_S_Buff[_DAL_MAX_SPARE_SIZE_/4];
#endif
/*
 ****** Definition of dbg_ASSERT and force_ASSERT ******
 dbg_ASSERT:
          - For basic load prevalidation use. The code is used for RD debug.
 Force_ASSERT:
          - For normal check, if those parameters are incorrect, system will fail.
          - We expect it should be found in the earlier stage.
*/
#if ( defined(__NAND_FLASH_HARDWARE_TEST__) && defined(__MAUI_BASIC__))
    #if defined __UBL__ /*bootloader case*/
        #if defined BL_DEBUG
            #define dbg_ASSERT(expr) ASSERT(expr)
        #else
            #define dbg_ASSERT(expr) {do { } while (0);}
        #endif
    #else
        #define dbg_ASSERT(expr) ASSERT(expr)
    #endif
#else
    #if defined __UBL__ /*bootloader case*/
        #if defined BL_DEBUG
            #define dbg_ASSERT(expr) ASSERT(expr)
        #else
            #define dbg_ASSERT(expr) {do { } while (0);}
        #endif
    #else
        #define dbg_ASSERT(expr) {do { } while (0);}
    #endif
#endif

#if defined __UBL__ /*bootloader case*/
    #define force_ASSERT(expr, e1, e2, e3) {EXT_ASSERT(expr, e1, e2, e3);}
#else
    #define force_ASSERT(expr, e1, e2, e3) {EXT_ASSERT(expr, e1, e2, e3);}
#endif

#if defined(__AUDIO_DSP_LOWPOWER__)
NFI_Config_for_MP3_st NFI_ConfigforMP3;
#endif //#if defined(__AUDIO_DSP_LOWPOWER__)

#define devicePage(ceIdx) (Flash_Info.devicePage[ceIdx]) /*page number of the device*/
#define zonePage(ceIdx) (devicePage(ceIdx)/Flash_Info.zone_CE[ceIdx]) /*page number of the zone*/
#define diePage(ceIdx) (Flash_Info.diePage[ceIdx]) /*page number of the die*/
#define planePage(ceIdx) (Flash_Info.planePage[ceIdx]) /*page number of plane*/
#define devDriver(ceIdx) (Flash_Info.deviceInfo_CE[ceIdx].driverSet)

//#define DAL_VERIFICATION
//#define DAL_DEBUG_TEXT

#if ( defined(__NAND_FLASH_HARDWARE_TEST__) && defined(__MAUI_BASIC__) && !defined(__UBL__) )
	// Basic load in MAUI
	kal_uint32 D_Buff[_DAL_MAX_PAGE_SIZE_/4*8 + 8];

	
	#if defined(__MTK_TARGET__)
   	#if defined (__ARMCC_VERSION)
		__attribute__(( section("NONCACHEDZI"),zero_init)) kal_uint32 D_Buff_NC[_DAL_MAX_PAGE_SIZE_/4*8 + 8];
	  #elif defined (__GNUC__)
		__attribute__(( section("NONCACHEDZI"))) kal_uint32 D_Buff_NC[_DAL_MAX_PAGE_SIZE_/4*8 + 8];
	  #endif /* ARMCC , GNUC */

	#else
	kal_uint32 D_Buff_NC[_DAL_MAX_PAGE_SIZE_/4*8 + 8];
	#endif

	kal_uint32 S_Buff[512/4*8];
	kal_uint8 Mtd_Fail_Offset = 0xFF;
	kal_uint8 Fail_Bank = 0xFF;

#else // ( defined(__NAND_FLASH_HARDWARE_TEST__) && defined(__MAUI_BASIC__) && !defined(__UBL__) )
	// Basic load in bootloader
	// MAUI load
	#if ( defined(__EMULATE_NFB_BIT_ERROE__) )
	kal_uint32 D_Buff[_DAL_MAX_PAGE_SIZE_/4*2 + 8];
	kal_uint32 S_Buff[_DAL_MAX_SPARE_SIZE_/4*2];
	#endif //( defined(__EMULATE_NFB_BIT_ERROE__) )

#endif // ( defined(__NAND_FLASH_HARDWARE_TEST__) && defined(__MAUI_BASIC__) && !defined(__UBL__) )

#if ( defined(ECC_BIT_ERROR_TEST) || defined(__EMULATE_NFB_BIT_ERROE__) )

kal_bool ECCDisable = KAL_FALSE;

kal_uint32 EmulateBitError(DAL_ACC_Type Acc_Type, kal_uint8 ZoneNo, kal_uint16 *Bank, kal_uint16 PageAddr, kal_uint8 SectorNumPerPage, kal_uint32 *Data, kal_uint32 *Spare)
{

	kal_uint32 retVal, SectorNum, BitOffset, Offset;
    kal_bool Empty;

    retVal = DAL_ReadPage(Acc_Type, ZoneNo, Bank, PageAddr, 1, ((kal_uint8*)&Data[_DAL_MAX_PAGE_SIZE_/4])+4, (Acc_Type==CODE_ACC) ? NULL : (kal_uint8*)&Spare[_DAL_MAX_SPARE_SIZE_/4]) & 0xffff0000;
    if ( retVal != MTD_STATUS_NO_ERROR ) {
    	return retVal;
    }

    DAL_ReadPage(Acc_Type, ZoneNo, Bank, PageAddr, 1, (kal_uint8*)Data, (kal_uint8*)Spare);

    Empty = KAL_TRUE;
	for (Offset=0; Offset<SectorNumPerPage*0x10/4; Offset++) {
		if (Spare[Offset] != 0xffffffff) {
			Empty = KAL_FALSE;
			break;
		}
	}

    if (Empty==KAL_TRUE) {
    	return MTD_STATUS_ERROR;  // Return this to bypass this page.
    }

	for (SectorNum=0; SectorNum<SectorNumPerPage; SectorNum++) {
		if (1) {
    		for (Offset=(SectorNum*0x200)*8; Offset<(SectorNum*0x200+256)*8; Offset++) {
    			BitOffset = Offset & 0x07;
   				if (((kal_uint8*)Data)[Offset>>3] & (0x01 << BitOffset)) {
   					((kal_uint8*)Data)[Offset>>3] &= ~((0x01 << BitOffset));
   					break;
   				}
    		}
    		for (Offset=(SectorNum*0x200+511)*8; Offset>=(SectorNum*0x200+256)*8; Offset--) {
    			BitOffset = Offset & 0x07;
   				if (((kal_uint8*)Data)[Offset>>3] & (0x01 << BitOffset)) {
   					((kal_uint8*)Data)[Offset>>3] &= ~((0x01 << BitOffset));
   					break;
   				}
    		}
    		for (Offset=(SectorNum*0x10+(PageAddr&0x07))*8; Offset<(SectorNum*0x10+0x8)*8; Offset++) {
    			BitOffset = Offset & 0x07;
   				if (((kal_uint8*)Spare)[Offset>>3] & (0x01 << BitOffset)) {
   					((kal_uint8*)Spare)[Offset>>3] &= ~((0x01 << BitOffset));
   					break;
   				}
    		}
		}  else {
			// Here NFI will not return error when ECC code error. So Do the following two times may cause ECC failure.
			// ECC code error
			kal_uint32 StartAddr, EndAddr;

			if (Acc_Type==CODE_ACC) {
				StartAddr = (SectorNum*0x10+0x08+(rand() % 6))*8;
				EndAddr = (SectorNum*0x10+0x0e)*8;
			} else {
				StartAddr = (SectorNum*0x10+0x08+(PageAddr&0x07))*8;
				EndAddr = (SectorNum*0x10+0x10)*8;
			}
    		for (Offset=StartAddr; Offset<EndAddr; Offset++) {
    			BitOffset = Offset & 0x07;
   				if (((kal_uint8*)Spare)[Offset>>3] & (0x01 << BitOffset)) {
   					((kal_uint8*)Spare)[Offset>>3] &= ~((0x01 << BitOffset));
   					break;
   				}
    		}
		}
	}
	ECCDisable = KAL_TRUE;
	retVal = DAL_ProgramPage(Acc_Type, ZoneNo, Bank, PageAddr, 1, (kal_uint8*)Data, (kal_uint8*)Spare);
	ECCDisable = KAL_FALSE;

	return MTD_STATUS_NO_ERROR;
}

#endif // #if ( defined(ECC_BIT_ERROR_TEST) || defined(__EMULATE_NFB_BIT_ERROE__) )

#if ( defined(__NAND_FLASH_HARDWARE_TEST__) && defined(__MAUI_BASIC__) )

extern int rand(void);

typedef struct
{
    kal_uint8 ce;
    kal_uint8 die;
    kal_uint8 plane;
} phyAdd_struct;


#if ( !defined(__UBL__) )

void getPhyAdd_info (kal_uint8 ce_idx, kal_uint32 pageAdd, phyAdd_struct *p)
{
    kal_uint32 d_page;
    kal_uint16 blk_num;

    p->ce = ce_idx;

    d_page = ( (Flash_Info.deviceInfo_CE[ce_idx].supportMPType & EXTENDED_BLOCK) == EXTENDED_BLOCK) ? (diePage(ce_idx)/1024*(1024+16)) : diePage(ce_idx);
    p->die = pageAdd/d_page;

    blk_num = ( (pageAdd - p->die*d_page)/Flash_Info.blockPage ); /*the block number in the die*/
    d_page = (pageAdd - p->die*d_page); /*now d_page is the page offset in tearget die*/
    if ( (Flash_Info.deviceInfo_CE[ce_idx].supportMPType&(TWO_PLANE_OP|PLANE_INTERLACED)) == (TWO_PLANE_OP|PLANE_INTERLACED) )
    {
        p->plane = blk_num %2;
    }
    else if ( (Flash_Info.deviceInfo_CE[ce_idx].supportMPType&(FOUR_PLANE_OP|PLANE_INTERLACED)) == (FOUR_PLANE_OP|PLANE_INTERLACED) )
    {
        p->plane = blk_num %4;
    }
    else /*PLANE_CONTINUOUS */
    {
        if (d_page < planePage(ce_idx))
        {
            p->plane = d_page/planePage(ce_idx);
        }
        else if ( (Flash_Info.deviceInfo_CE[ce_idx].supportMPType&(TWO_PLANE_OP|PLANE_CONTINUOUS)) == (TWO_PLANE_OP|PLANE_CONTINUOUS) &&
             d_page < planePage(ce_idx)*2)
        {
            p->plane = d_page/planePage(ce_idx);
        }
        else if ( (Flash_Info.deviceInfo_CE[ce_idx].supportMPType&(FOUR_PLANE_OP|PLANE_CONTINUOUS)) == (FOUR_PLANE_OP|PLANE_CONTINUOUS) &&
                  d_page < planePage(ce_idx)*4 )
        {
            p->plane = d_page/planePage(ce_idx);
        }
        else
        {   /*only EXTENDED_BLOCK is possible to run here*/
            dbg_ASSERT(Flash_Info.deviceInfo_CE[ce_idx].supportMPType&EXTENDED_BLOCK);
            d_page -= diePage(ce_idx); /* - regular block area*/
            p->plane = d_page / (planePage(ce_idx) / 1024 * 16) ;
        }
    }
}

#if defined(ECC_BIT_ERROR_TEST)
void DAL_ECCTest(kal_bool Init)
{
    kal_uint32 i, j, k, l;
    kal_uint32 retVal, Offset;
    kal_uint16 b_arr[8];
    FLASH_INFO F_info;
    kal_uint8 *BufPtr = NULL;

	if (Init==KAL_TRUE) {
	    DAL_init();
	}
   	DAL_FDM_Flash_Info_Init (&F_info, 0);


    nandlog_print("ECC test start.\r\n");
    for (i=0;i< F_info.TotalZoneNum; i++)
    {
        for (j=0; j<F_info.PSectionNumInZone[i]; j++ )
        {
        	if ( (j & 0x7f)==0 ) {
	            nandlog_print("ECC already passed zone %xh, section %xh.\r\n",i,j);
			    
        	}
            for (k=0; k<F_info.BankNumber; k++)
            {
                b_arr[k] = j;
                if ( (retVal = DAL_CheckBadBlock(FAT_ACC, i, b_arr, k, KAL_FALSE, D_Buff, S_Buff)) ==  MTD_STATUS_NO_ERROR)
                {
                    for (l=0;l<F_info.PageNumPerSection; l+=F_info.BankNumber)
                    {
                    	retVal = EmulateBitError(FAT_ACC, i, b_arr, k+l, F_info.SectorNumPerPage, D_Buff, S_Buff);
                        if ( retVal == MTD_STATUS_NO_ERROR )
                        {
                        	BufPtr = NULL;
						    kal_mem_set(D_Buff, 0xFF, _DAL_MAX_PAGE_SIZE_+4);
						    kal_mem_set(S_Buff, 0xFF, _DAL_MAX_SPARE_SIZE_);

						DAL_ECC_TEST:

							if (BufPtr==NULL)
							{
								BufPtr = (kal_uint8 *)D_Buff;
							}
							else
							{
								BufPtr = (kal_uint8 *)D_Buff_NC;
							}

	                        retVal = DAL_ReadPage(FAT_ACC, i, b_arr, k+l, 1, (kal_uint8*)(BufPtr+(l%4)), (kal_uint8*)S_Buff) & 0xffff0000;
	                        if ( retVal == MTD_STATUS_ERROR ) {
	                        	nandlog_print("[Error]DAL_ReadPage return MTD_STATUS_ERROR.\r\n");
	                            dbg_ASSERT(0);
	                        }
							if ( kal_mem_cmp((BufPtr+(l%4)), ((kal_uint8*)&D_Buff[_DAL_MAX_PAGE_SIZE_/4])+4, F_info.SectorNumPerPage*0x200 ) )  {
	                        	nandlog_print("[Error] Main buffer comparison failure.\r\n");
	                            dbg_ASSERT(0);
							}

		                    #if defined(__NFI_VERSION3_1__)

							for (Offset=0; Offset<F_info.SectorNumPerPage*0x10/4; Offset+=(0x10/4)) {
			                    if ( (DAL_GetFDMData(FDMDATA_LBA, &(S_Buff[Offset]))!= DAL_GetFDMData(FDMDATA_LBA, &(S_Buff[_DAL_MAX_SPARE_SIZE_/4 + Offset]))) ||
			                    	 (DAL_GetFDMData(FDMDATA_BM, &(S_Buff[Offset])) != DAL_GetFDMData(FDMDATA_BM, &(S_Buff[_DAL_MAX_SPARE_SIZE_/4 + Offset])))) {
		                        	nandlog_print("FDM data comparison failure.\r\n");
			                        dbg_ASSERT(0);
			                    }
							}

							#else // defined(__NFI_VERSION3_1__)

							for (Offset=0; Offset<F_info.SectorNumPerPage*0x10/4; Offset+=(0x10/4)) {
								if ( (S_Buff[Offset]!=S_Buff[_DAL_MAX_SPARE_SIZE_/4+Offset]) ||
									 (S_Buff[Offset+1]!=S_Buff[_DAL_MAX_SPARE_SIZE_/4+Offset+1]) ) {
		                        	nandlog_print("[Error] FDM data comparison failure.\r\n");
		                            dbg_ASSERT(0);
								}
							}

							#endif // defined(__NFI_VERSION3_1__)

							if (BufPtr == (kal_uint8 *)D_Buff)
							{
								goto DAL_ECC_TEST;
							}
                        }
                    }
                }
                else
                {
#ifdef DAL_DEBUG_TEXT
                    nandlog_print("Bad block(0x%X) at (Z,BIdx,Block) = (%d,%d,%d)\r\n",retVal,i,k,j);
                    
#endif // DAL_DEBUG_TEXT
                }
            }
        }
    }
    nandlog_print("-> ECC error test pass\r\n ");    
	if (Init==KAL_TRUE) {
	    DAL_ShutDown();
	}
}
#endif // ECC_BIT_ERROR_TEST

void DAL_Test (void)
{
    kal_uint32 i,j,k,l;
    static kal_uint32 count = 0;
    kal_uint32 retVal;
    kal_uint16 b_arr[8];
    FLASH_INFO F_info;
    kal_uint8 *BufPtr = NULL;

    DAL_init();
    DAL_FDM_Flash_Info_Init (&F_info, 0);

    nandlog_print("Count:%d -- TotalZoneNum:%d,BankNumber:%d\r\n",count, F_info.TotalZoneNum,F_info.BankNumber);
    
    count++;
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
    #endif

    #if 1

DAL_TEST_START:

	if (BufPtr==NULL)
	{
		BufPtr = (kal_uint8 *)D_Buff;
	}
	else
	{
		BufPtr = (kal_uint8 *)D_Buff_NC;
	}

    nandlog_print("-> Erase Test... \r\n");
    /*Erase all*/
    for (i=0;i< F_info.TotalZoneNum; i++)
    {
        for (j=0; j<F_info.PSectionNumInZone[i]; j++ )
        {
        	if ( (j & 0x7f)==0 ) {
	            nandlog_print("Erase test already passed zone %xh, section %xh.\r\n",i,j);
			    
        	}

            for (k=0;k< F_info.BankNumber; k++)
            {
                b_arr[k] = j;
                if ( (retVal = DAL_CheckBadBlock(FAT_ACC, i, b_arr, k,KAL_FALSE,D_Buff, S_Buff)) ==  MTD_STATUS_NO_ERROR)
                {
                    if ((DAL_EraseBlock(FAT_ACC, i,b_arr, k, 1) & 0xffff)==MTD_STATUS_ERROR) {
                    	goto BAD_BLOCK;
                    }
                    retVal = DAL_ReadPage(FAT_ACC, i,b_arr,k,1,(kal_uint8*)BufPtr,(kal_uint8*)S_Buff );
                    if ( retVal != MTD_STATUS_NO_ERROR )
                    {
                        nandlog_print("(Z,BIdx,Block) = (%d,%d,%d) read error in 1st page\r\n",i,k,j);
                        
                    }
                    for (l=0;l< F_info.SectorNumPerPage * 512;l++ )
                    {
                        if (BufPtr[l] != 0xFF )
                        {
	                        nandlog_print("[Error] After erase, data is not empty.\r\n");
	                        
                            dbg_ASSERT(0);
                        }
                    }
                    #if defined(__NFI_VERSION3_1__)

                    if ( (DAL_GetFDMData(FDMDATA_LBA, S_Buff)!=(kal_uint16)0xffff) ||
                    	 (DAL_GetFDMData(FDMDATA_BM, S_Buff)!=(kal_uint16)0xffff) ) {
                        nandlog_print("[Error] After erase, data is not empty.\r\n");
                        
                        dbg_ASSERT(0);
                    }

					#else // defined(__NFI_VERSION3_1__)

                    for (l=0;l< F_info.SectorNumPerPage * 16/4;l++ )
                    {
                        if (S_Buff[l] != 0xFFFFFFFF )
                        {
                            dbg_ASSERT(0);
                        }
                    }

                    #endif // defined(__NFI_VERSION3_1__)
                }
                else
                {
BAD_BLOCK:
                    nandlog_print("Bad block(0x%X) at (Z,BIdx,Block) = (%d,%d,%d)\r\n",retVal,i,k,j);
#ifdef DAL_DEBUG_TEXT
                    
#endif // DAL_DEBUG_TEXT
                }
            }
        }
    }
    nandlog_print("-> Erase check pass \r\n");

    kal_mem_set(S_Buff, 0xFF, sizeof(S_Buff));
    /*Program all with the logic address*/
    nandlog_print("-> Program test... \r\n");
    for (i=0;i< F_info.TotalZoneNum; i++)
    {
        for (j=0; j<F_info.PSectionNumInZone[i]; j++ )
        {
        	if ( (j & 0x7f)==0 ) {
	            nandlog_print("Program test already passed zone %xh, section %xh.\r\n",i,j);
			    
        	}

            for (k=0;k< F_info.BankNumber; k++)
            {
                b_arr[k] = j;
                if ( (retVal = DAL_CheckBadBlock(FAT_ACC, i, b_arr, k,KAL_FALSE,D_Buff, S_Buff)) ==  MTD_STATUS_NO_ERROR)
                {
                    for (l=0;l< F_info.PageNumPerSection ; l+= F_info.BankNumber)
                    {
                        kal_sprintf((char*)(BufPtr + (l%4)),"(Z,BIdx,Block,Page) = (%d,%d,%d,%d)\n",i,k,j,k+l );
						            DAL_SetFDMData((kal_uint16)j, (kal_uint16)j, FDMDATA_EMPTY | FDMDATA_LBA | FDMDATA_BM, S_Buff);
                        retVal = DAL_ProgramPage(FAT_ACC, i,b_arr,k+l,1,(kal_uint8*)(BufPtr + (l%4)),(kal_uint8*)S_Buff );
                        if ( retVal != MTD_STATUS_NO_ERROR )
                        {
                            nandlog_print("(Z,BIdx,Block,Page) = (%d,%d,%d,%d) program error\r\n",i,k,j,k+l );
                            
                            //dbg_ASSERT(0);
                            continue;
                        }

						kal_mem_set(S_Buff, 0xFF, sizeof(S_Buff));
						kal_mem_set(BufPtr, 0xFF, sizeof(D_Buff));
                        retVal = DAL_ReadPage(FAT_ACC, i,b_arr,k+l,1,(kal_uint8*)(BufPtr + (l%4)),(kal_uint8*)S_Buff ) & 0xffff0000;
                        if ( retVal == MTD_STATUS_ERROR )
                        {
                            nandlog_print("(Z,BIdx,Block,Page) = (%d,%d,%d,%d) read error\r\n",i,k,j,k+l );
                            
                            dbg_ASSERT(0);
                        }
                        kal_sprintf(NAND_text_buff,"(Z,BIdx,Block,Page) = (%d,%d,%d,%d)\n",i,k,j,k+l );
                        if (strcmp(NAND_text_buff,(char*)(BufPtr + (l%4)))!=0)
                        {
                            nandlog_print("(Z,BIdx,Block,Page) = (%d,%d,%d,%d) content error\r\n",i,k,j,k+l );
                            
                            dbg_ASSERT(0);
                        }

                    }
                }
                else
                {
#ifdef DAL_DEBUG_TEXT
                    nandlog_print("Bad block(0x%X) at (Z,BIdx,Block) = (%d,%d,%d)\r\n",retVal,i,k,j);
                    
#endif
                }
            }
        }
    }
    nandlog_print("-> Program check pass \r\n");

    /*Read all with the logic address*/
    nandlog_print("-> Read compare... \r\n");
    for (i=0;i< F_info.TotalZoneNum; i++)
    {
        for (j=0; j<F_info.PSectionNumInZone[i]; j++ )
        {
        	if ( (j & 0x7f)==0 ) {
	            nandlog_print("Read compare test already passed zone %xh, section %xh.\r\n",i,j);
			    
        	}
            for (k=0;k< F_info.BankNumber; k++)
            {
                b_arr[k] = j;
                if ( (retVal = DAL_CheckBadBlock(FAT_ACC, i, b_arr, k,KAL_FALSE,D_Buff, S_Buff)) ==  MTD_STATUS_NO_ERROR)
                {
                    for (l=0;l< F_info.PageNumPerSection ; l+= F_info.BankNumber)
                    {
                        retVal = DAL_ReadPage(FAT_ACC, i,b_arr,k+l,1,(kal_uint8*)BufPtr,(kal_uint8*)S_Buff ) & 0xffff0000;
                        if ( retVal == MTD_STATUS_ERROR )
                        {
                            nandlog_print("(Z,BIdx,Block,Page) = (%d,%d,%d,%d) read error\r\n",i,k,j,k+l );
                            
                            dbg_ASSERT(0);
                        }
                        kal_sprintf(NAND_text_buff,"(Z,BIdx,Block,Page) = (%d,%d,%d,%d)\n",i,k,j,k+l );
                        if (strcmp(NAND_text_buff,(char*)BufPtr)!=0)
                        {
                            nandlog_print("(Z,BIdx,Block,Page) = (%d,%d,%d,%d) content error\r\n",i,k,j,k+l );
                            
                            dbg_ASSERT(0);
                        }
                        if ( (DAL_GetFDMData(FDMDATA_LBA, S_Buff)!=(kal_uint16)j) ||
                        	 (DAL_GetFDMData(FDMDATA_BM, S_Buff)!=(kal_uint16)j) ) {
                            nandlog_print("(Z,BIdx,Block,Page) = (%d,%d,%d,%d) spare error\r\n",i,k,j,k+l );
                            
                            dbg_ASSERT(0);
                        }
                    }
                }
                else
                {
#ifdef DAL_DEBUG_TEXT
                    nandlog_print("Bad block(0x%X) at (Z,BIdx,Block) = (%d,%d,%d)\r\n",retVal,i,k,j);
                    
#endif // DAL_DEBUG_TEXT
                }
            }
        }
    }
    nandlog_print("-> Read back check pass \r\n");    

    if (BufPtr == (kal_uint8 *)D_Buff)
    {
    	goto DAL_TEST_START;
    }

    #endif
    DAL_ShutDown();
}

void DAL_Section_Test (void)
{
    kal_uint32 i,j,k,l,m;
    static kal_uint32 count = 0;
    kal_uint32 retVal = MTD_STATUS_NO_ERROR;
    kal_uint16 b_arr[8];
    FLASH_INFO F_info;

    DAL_init();
    DAL_FDM_Flash_Info_Init (&F_info, 0);

    nandlog_print("Count:%d -- TotalZoneNum:%d,BankNumber:%d\r\n",count, F_info.TotalZoneNum,F_info.BankNumber);
    
    /*Get the good section to test*/
    for (i=0;i< F_info.TotalZoneNum; i++)
    {
        for (j=0; j<F_info.PSectionNumInZone[i]; j+=0x20 )
        {
TEST_START:
            /*Bad block check*/
            for (k=0;k< F_info.BankNumber; k++)
            {
                b_arr[k] = j;
                if ( (retVal = DAL_CheckBadBlock(FAT_ACC, i, b_arr, k,KAL_FALSE,D_Buff, S_Buff)) !=  MTD_STATUS_NO_ERROR)
                    break;
            }
            if (k != F_info.BankNumber)
            {
                nandlog_print("Bad block(0x%X) at (Z,BIdx,Block) = (%d,%d,%d)\r\n",retVal,i,k,j);
                
                continue; /*go to next section*/
            }
            else
            {
			    /*continuous access test from 0 ~ bankNumber*/
			    nandlog_print("Bank operation test\r\n");
			    for (k=0;k< F_info.BankNumber; k++)
			    {
			        for (l=k;l<F_info.BankNumber;l++ )
			        {
			            nandlog_print("(Z,Section, Page) = (%d,%d,%d) -> (%d,%d,%d) test start\r\n",i,j,k,i,j,l);
			            
			            /*Erase*/
			            retVal = DAL_EraseBlock(FAT_ACC, i,b_arr, k, l-k+1 );
			            if ( retVal != MTD_STATUS_NO_ERROR )
			            {
			                nandlog_print("(Z,Section) = (%d,%d) erase fail\r\n",i,j);
			                
			                goto TEST_START;
			                //dbg_ASSERT(0);
			            }
			            /*Read back check*/
			            retVal = DAL_ReadPage(FAT_ACC, i,b_arr,k,l-k+1,(kal_uint8*)D_Buff,(kal_uint8*)S_Buff );
			            if ( retVal != MTD_STATUS_NO_ERROR )
			            {
			                nandlog_print("(Z,Section) = (%d,%d) read fail\r\n",i,j);
			                
			                dbg_ASSERT(0);
			            }
			            for (m=0;m< F_info.SectorNumPerPage * 512/4 * (l-k+1) ;m++ )
			            {
			                if (D_Buff[m] != 0xFFFFFFFF )
			                {
			                    nandlog_print("(Z,Section) = (%d,%d) read main check fail\r\n",i,j);
			                    
			                    dbg_ASSERT(0);
			                }
			            }
	                    #if defined(__NFI_VERSION3_1__)

			            for (m=0; m<F_info.SectorNumPerPage * 16/4 * (l-k+1); m += (16/4) )
			            {
		                    if ( (DAL_GetFDMData(FDMDATA_LBA, &(S_Buff[m]))!=(kal_uint16)0xffff) ||
		                    	 (DAL_GetFDMData(FDMDATA_BM, &(S_Buff[m]))!=(kal_uint16)0xffff) ) {
		                        nandlog_print("[Error] After erase, data is not empty.\r\n");
		                        
		                        dbg_ASSERT(0);
		                    }
			            }

						#else // defined(__NFI_VERSION3_1__)

			            for (m=0;m< F_info.SectorNumPerPage * 16/4 * (l-k+1) ;m++ )
			            {
			                if (S_Buff[m] != 0xFFFFFFFF )
			                {
			                    nandlog_print("(Z,Section) = (%d,%d) read spare check fail\r\n",i,j);
			                    
			                    dbg_ASSERT(0);
			                }
			            }

			            #endif //  defined(__NFI_VERSION3_1__)

			            /*Write*/
			            for (m=0;m<(l-k+1);m++)
			            {
			                kal_sprintf((char *)&D_Buff[Flash_Info.pageSize*m/4],"(Z,BIdx,Block,Page) = (%d,%d,%d,%d)\n",i,m+k,j,0);
			            }
						DAL_SetFDMData((kal_uint16)j, (kal_uint16)j, FDMDATA_EMPTY | FDMDATA_LBA | FDMDATA_BM, S_Buff);
			            retVal = DAL_ProgramPage(FAT_ACC, i,b_arr,k,l-k+1,(kal_uint8*)D_Buff,(kal_uint8*)S_Buff );
			            if ( retVal != MTD_STATUS_NO_ERROR )
			            {
			                nandlog_print("(Z,Section) = (%d,%d) program fail\r\n",i,j);
			                
			                goto TEST_START;
			                //dbg_ASSERT(0);
			            }
			            kal_mem_set(D_Buff, 0xFF, (l-k+1)*Flash_Info.pageSize );
			            /*Read back check*/
			            retVal = DAL_ReadPage(FAT_ACC, i,b_arr,k,l-k+1,(kal_uint8*)D_Buff,(kal_uint8*)S_Buff );
			            if ( retVal != MTD_STATUS_NO_ERROR )
			            {
			                nandlog_print("(Z,Section) = (%d,%d) read operation fail\r\n",i,j);
			                
			                dbg_ASSERT(0);
			            }
			            for (m=0;m<(l-k+1);m++)
			            {
			                kal_sprintf(NAND_text_buff,"(Z,BIdx,Block,Page) = (%d,%d,%d,%d)\n",i,m+k,j,0);
			                if (strcmp(NAND_text_buff,(char*)&D_Buff[Flash_Info.pageSize*m/4])!=0)
			                {
			                    nandlog_print("(Z,BIdx,Block,Page) = (%d,%d,%d,%d) content error\r\n",i,m+k,j,0 );
			                    
			                    dbg_ASSERT(0);
			                }
			            }
			            if ( (DAL_GetFDMData(FDMDATA_LBA, S_Buff)!=(kal_uint16)j) ||
			            	 (DAL_GetFDMData(FDMDATA_BM, S_Buff)!=(kal_uint16)j) ) {
			                nandlog_print("(Z,BIdx,Block,Page) = (%d,%d,%d,%d) Spare content error\r\n",i,0,j,0 );
			                
			                dbg_ASSERT(0);
			            }

			            /*Copy test*/
			            retVal = DAL_CopyPage(FAT_ACC, i,b_arr,b_arr, k,k+F_info.BankNumber, l-k+1 ,(kal_uint8*)D_Buff,(kal_uint8*)S_Buff,
			                                  sizeof(D_Buff)/Flash_Info.pageSize,0 );
			            if ( retVal != MTD_STATUS_NO_ERROR )
			            {
			                nandlog_print("(Z,Section) = (%d,%d) Copy fail\r\n",i,j);
			                
			                goto TEST_START;
			                //dbg_ASSERT(0);
			            }
			            kal_mem_set(D_Buff, 0xFF, (l-k+1)*Flash_Info.pageSize );
			            /*Read back check*/
			            retVal = DAL_ReadPage(FAT_ACC, i,b_arr,k+F_info.BankNumber,l-k+1,(kal_uint8*)D_Buff,(kal_uint8*)S_Buff );
			            if ( retVal != MTD_STATUS_NO_ERROR )
			            {
			                nandlog_print("(Z,Section) = (%d,%d) read operation fail\r\n",i,j);
			                
			                dbg_ASSERT(0);
			            }
			            for (m=0;m<(l-k+1);m++)
			            {
			                kal_sprintf(NAND_text_buff,"(Z,BIdx,Block,Page) = (%d,%d,%d,%d)\n",i,m+k,j,0);
			                if (strcmp(NAND_text_buff,(char*)&D_Buff[Flash_Info.pageSize*m/4])!=0)
			                {
			                    nandlog_print("(Z,BIdx,Block,Page) = (%d,%d,%d,%d) content error\r\n",i,m+k,j,1 );
			                    
			                    dbg_ASSERT(0);
			                }
			            }
			            if ( (DAL_GetFDMData(FDMDATA_LBA, S_Buff)!=(kal_uint16)j) ||
			            	 (DAL_GetFDMData(FDMDATA_BM, S_Buff)!=(kal_uint16)j) ) {
			                nandlog_print("(Z,BIdx,Block,Page) = (%d,%d,%d,%d) Spare content error\r\n",i,0,j,0 );
			                
			                dbg_ASSERT(0);
			            }
			#if defined DAL_VERIFICATION
			            /*DAL_MarkBlockBad and DAL_CheckBlockBad*/
			            DAL_MarkBlockBad(FAT_ACC, i, b_arr, k, KAL_TRUE, D_Buff, S_Buff);
			            retVal = DAL_CheckBadBlock (FAT_ACC, i, b_arr, k, KAL_FALSE, D_Buff, S_Buff);
			            if ( (retVal&MTD_STATUS_FDM_BAD) != MTD_STATUS_FDM_BAD )
			            {
			                nandlog_print("(Z,BIdx,Block) = (%d,%d,%d) read operation fail\r\n",i,k,j);
			                
			                dbg_ASSERT(0);
			            }
			            nandlog_print("(Z,Section, Page) = (%d,%d,%d) -> (%d,%d,%d) test success\r\n",i,j,k,i,j,l);
			            
			#endif
			        }
			    }

			    nandlog_print("Continueous program test\r\n");
			    /*bank number aligned continuous access test (cache operation test)*/
			    if (sizeof(D_Buff) >= Flash_Info.bankNum * Flash_Info.pageSize*2 )
			    {
			        for (l=F_info.BankNumber*2;l <= sizeof(D_Buff)/Flash_Info.pageSize;l+=F_info.BankNumber )
			        {
			            nandlog_print("(Z,Section, Page) = (%d,%d,%d) -> (%d,%d,%d) test start\r\n",i,j,0,i,j,l-1);
			            
			            /*Erase*/
			            retVal = DAL_EraseBlock(FAT_ACC, i,b_arr, 0, F_info.BankNumber );
			            if ( retVal != MTD_STATUS_NO_ERROR )
			            {
			                nandlog_print("(Z,Section) = (%d,%d) erase fail\r\n",i,j);
			                
			                goto TEST_START;
			            }
			            /*Read back check*/
			            retVal = DAL_ReadPage(FAT_ACC, i,b_arr,0, F_info.BankNumber, (kal_uint8*)D_Buff,(kal_uint8*)S_Buff );
			            if ( retVal != MTD_STATUS_NO_ERROR )
			            {
			                nandlog_print("(Z,Section) = (%d,%d) read fail\r\n",i,j);
			                
			                dbg_ASSERT(0);
			            }
			            for (m=0;m< F_info.SectorNumPerPage * 512/4 * F_info.BankNumber ;m++ )
			            {
			                if (D_Buff[m] != 0xFFFFFFFF )
			                {
			                    nandlog_print("(Z,Section) = (%d,%d) read check fail\r\n",i,j);
			                    
			                    dbg_ASSERT(0);
			                }
			            }
			            /*Write*/
			            for (m=0;m<l;m++)
			            {
			                kal_sprintf((char*)&D_Buff[Flash_Info.pageSize*m/4],"(Z,BIdx,Block,Page) = (%d,%d,%d,%d)\n",i,m%F_info.BankNumber,j,m/F_info.BankNumber);
			            }
						DAL_SetFDMData((kal_uint16)j, (kal_uint16)j, FDMDATA_EMPTY | FDMDATA_LBA | FDMDATA_BM, S_Buff);
			            retVal = DAL_ProgramPage(FAT_ACC, i,b_arr,0,l,(kal_uint8*)D_Buff,(kal_uint8*)S_Buff );
			            if ( retVal != MTD_STATUS_NO_ERROR )
			            {
			                nandlog_print("(Z,Section) = (%d,%d) program fail\r\n",i,j);
			                
			                dbg_ASSERT(0);
			            }
			            kal_mem_set(D_Buff, 0xFF, l*Flash_Info.pageSize );
			            /*Read back check*/
			            retVal = DAL_ReadPage(FAT_ACC, i,b_arr,0,l,(kal_uint8*)D_Buff,(kal_uint8*)S_Buff );
			            if ( retVal != MTD_STATUS_NO_ERROR )
			            {
			                nandlog_print("(Z,Section) = (%d,%d) read operation fail\r\n",i,j);
			                
			                dbg_ASSERT(0);
			            }
			            for (m=0;m<l;m++)
			            {
			                kal_sprintf(NAND_text_buff,"(Z,BIdx,Block,Page) = (%d,%d,%d,%d)\n",i,m%F_info.BankNumber,j,m/F_info.BankNumber);
			                if (strcmp(NAND_text_buff,(char*)&D_Buff[Flash_Info.pageSize*m/4])!=0)
			                {
			                    nandlog_print("(Z,BIdx,Block,Page) = (%d,%d,%d,%d) content error\r\n",i,m%F_info.BankNumber,j,m/F_info.BankNumber);
			                    
			                    dbg_ASSERT(0);
			                }
			            }
			            if ( (DAL_GetFDMData(FDMDATA_LBA, S_Buff)!=(kal_uint16)j) ||
			            	 (DAL_GetFDMData(FDMDATA_BM, S_Buff)!=(kal_uint16)j) ) {
			                nandlog_print("(Z,BIdx,Block,Page) = (%d,%d,%d,%d) Spare content error\r\n",i,0,j,0 );
			                
			                dbg_ASSERT(0);
			            }
			            nandlog_print("(Z,Section, Page) = (%d,%d,%d) -> (%d,%d,%d) test succes\r\n",i,j,0,i,j,l-1);
			            
			        }

			    }

            }
        }
    }
    DAL_ShutDown();
    nandlog_print("Test finish... \r");
}

/****************************************************************************
 * Function:
 *
 * Parameters:
 *
 * Returns:
 *
 * Description: While box test (make condition to let DAL returns error then check the error value
 *
 ****************************************************************************/
void DAL_WhileBox_Test (void)
{
    kal_uint32 i,j=0,k,l,m;
    kal_uint32 retVal = MTD_STATUS_NO_ERROR;
    kal_uint16 b_arr[8];
    FLASH_INFO F_info;

    DAL_init();
    DAL_FDM_Flash_Info_Init (&F_info, 0);

    /*Get the good section to test*/
    for (i=0;i< F_info.TotalZoneNum; i++)
    {
        for (j=0; j<F_info.PSectionNumInZone[i]; j++ )
        {
            /*Bad block check*/
            for (k=0;k< F_info.BankNumber; k++)
            {
                b_arr[k] = j;
                if ( (retVal = DAL_CheckBadBlock(FAT_ACC, i, b_arr, k,KAL_FALSE,D_Buff, S_Buff)) !=  MTD_STATUS_NO_ERROR)
                    break;
            }
            if (k != F_info.BankNumber)
            {
                nandlog_print("Bad block(0x%X) at (Z,BIdx,Block) = (%d,%d,%d)\r\n",retVal,i,k,j);
                
                continue; /*go to next section*/
            }
            else
            {
                goto MAIN;
            }
        }
    }
MAIN:
    /*DAL_EraseBlock test*/
    Fail_Bank = 0xFF; /*Reset*/
    for (k=0;k< F_info.BankNumber; k++)
    {
        for (l=k;l<F_info.BankNumber;l++ )
        {
            Fail_Bank = l;
            retVal = DAL_EraseBlock(FAT_ACC, i,b_arr, k, l-k+1 );
            dbg_ASSERT(retVal != MTD_STATUS_NO_ERROR);
            dbg_ASSERT((retVal&0xFFFF0000) == MTD_STATUS_ERROR);
            if ( (retVal&0xFFFF) != (1<<Fail_Bank) )
            {
                nandlog_print("DAL_EraseBlock get wrong return at (Z,BIdx) = (%d,%d)\r\n",i,l);
                
                dbg_ASSERT(0);
            }
        }
    }
    nandlog_print("Erase check pass \r\n");
    /*DAL_ProgramPage test*/
    Fail_Bank = 0xFF; /*Reset*/
    for (k=0;k< F_info.BankNumber; k++)
    {
        for (l=k;l<F_info.BankNumber;l++ )
        {
            for (m=0;m<(l-k+1);m++)
            {
                kal_sprintf((char*)&D_Buff[Flash_Info.pageSize*m/4],"(Z,BIdx,Block,Page) = (%d,%d,%d,%d)\n",i,m+k,j,0);
            }
            Fail_Bank = l;
            retVal = DAL_ProgramPage(FAT_ACC, i,b_arr, k, l-k+1 ,(kal_uint8*)D_Buff,(kal_uint8*)S_Buff );
            dbg_ASSERT(retVal != MTD_STATUS_NO_ERROR);
            dbg_ASSERT((retVal&0xFFFF0000) == MTD_STATUS_ERROR);
            if ( (retVal&0xFFFF) != (1<<Fail_Bank) )
            {
                nandlog_print("DAL_ProgramPage get wrong return at (Z,BIdx) = (%d,%d)\r\n",i,l);
                
                dbg_ASSERT(0);
            }
        }
    }
    nandlog_print("-> Write check pass \r\n");
    /*DAL_ReadPage test*/
    Fail_Bank = 0xFF; /*Reset*/
    for (k=0;k< F_info.BankNumber; k++)
    {
        for (l=k;l<F_info.BankNumber;l++ )
        {
            Fail_Bank = l;
            retVal = DAL_ReadPage(FAT_ACC, i,b_arr, k, l-k+1 ,(kal_uint8*)D_Buff,(kal_uint8*)S_Buff );
            dbg_ASSERT(retVal != MTD_STATUS_NO_ERROR);
            dbg_ASSERT((retVal&0xFFFF0000) == MTD_STATUS_ERROR);
            if ( (retVal&0xFFFF) != (1<<Fail_Bank) )
            {
                nandlog_print("DAL_ReadPage get wrong return at (Z,BIdx) = (%d,%d)\r\n",i,l);
                
                dbg_ASSERT(0);
            }
        }
    }
    nandlog_print("-> Read check pass \r\n");
    /*DAL_CopyPage test*/
    Fail_Bank = 0xFF; /*Reset*/
    {
        for (k=0;k< F_info.BankNumber; k++)
        {
            for (l=k;l<F_info.BankNumber;l++ )
            {
                Fail_Bank = l;
                retVal = DAL_CopyPage(FAT_ACC, i,b_arr,b_arr, k,k+F_info.BankNumber, l-k+1 ,(kal_uint8*)D_Buff,(kal_uint8*)S_Buff,
                                      sizeof(D_Buff)/Flash_Info.pageSize,0 );
                dbg_ASSERT(retVal != MTD_STATUS_NO_ERROR);
                dbg_ASSERT((retVal&0xFFFF0000) == MTD_STATUS_ERROR);
                if ( (retVal&0xFFFF) != (1<<Fail_Bank) )
                {
                    nandlog_print("DAL_CopyPage get wrong return at (Z,BIdx) = (%d,%d)\r\n",i,l);
                    
                    dbg_ASSERT(0);
                }
            }
        }
    }
    nandlog_print("-> Copy check pass \r\n");    
    DAL_ShutDown();
}
#endif // ( !defined(__UBL__) )
#endif // ( defined(__NAND_FLASH_HARDWARE_TEST__) && defined(__MAUI_BASIC__) )


/****************************************************************************
 * Function:
 *
 * Parameters:
 *
 * Returns:
 *
 * Description: It will change Flash_Info.multiProgram
 *                             Flash_Info.zone_CE
 *                             Flash_Info.bank_CE
 *                             Flash_Info.supportMPType
 *              according to the Flash_Info.deviceInfo_CE[ceIdx].driverSet and Flash_Info.supportMPType
 ****************************************************************************/
kal_uint32 init_multiProgram ( void )
{
    kal_uint8   m_idx, ce_idx;
    kal_uint16  supportMPType_ce[2] = {0,0};
    kal_uint32  bank_len_zone;
    kal_mem_set( Flash_Info.multiProgram, 0x00, sizeof(Flash_Info.multiProgram));
    for (ce_idx=0; ce_idx<2;ce_idx++)
    {
        for (m_idx=0; m_idx<MAX_MULTIPAGE_FUNCTION_NUM;m_idx++)
        {
            Flash_Info.multiProgram[ce_idx][m_idx].startAlign = 0xFF;
        }
    }

    /*Operation function setting for each CE device*/
    for (ce_idx=0; ce_idx<2;ce_idx++)
    {
        if (Flash_Info.valid_CE[ce_idx] == KAL_FALSE)
            continue;
        /*The CACHE_PROGRAM, TWO_DIE_INTERLEAVE_OP, TWO_PLANE_OP, FOUR_PLANE_OP flags need to be redefined*/
        supportMPType_ce[ce_idx] = Flash_Info.supportMPType[ce_idx]& (~(CACHE_PROGRAM|TWO_DIE_INTERLEAVE_OP|TWO_PLANE_OP|FOUR_PLANE_OP));
        m_idx = 1; /*Flash_Info.multiProgram[ce_idx][0] reserve to cache function*/
        Flash_Info.bank_CE[ce_idx] = 1;
        /*non-support operation */
        dbg_ASSERT((Flash_Info.supportMPType[ce_idx] & (TWO_DIE_INTERLEAVE_OP|FOUR_PLANE_OP)) != (TWO_DIE_INTERLEAVE_OP|FOUR_PLANE_OP));
        dbg_ASSERT((Flash_Info.supportMPType[ce_idx] & (TWO_PLANE_OP|FOUR_PLANE_OP)) != (TWO_PLANE_OP|FOUR_PLANE_OP));
        /*multiple 4 check */
        if ( ( (Flash_Info.supportMPType[ce_idx] & (TWO_DIE_INTERLEAVE_OP|TWO_PLANE_OP)) == (TWO_DIE_INTERLEAVE_OP|TWO_PLANE_OP))
             && (devDriver(ce_idx)->TwoDieTwoPlaneProgram != NULL) )
        {
            dbg_ASSERT(Flash_Info.deviceInfo_CE[ce_idx].dieNum == 2);
            dbg_ASSERT(Flash_Info.deviceInfo_CE[ce_idx].planeNum == 2 );

            if ( (Flash_Info.supportMPType[ce_idx] & CACHE_PROGRAM)
                 && (devDriver(ce_idx)->TwoDieTwoPlaneCacheProgram != NULL)
                 && (Flash_Info.multiProgram[ce_idx][0].func_p == NULL) )
            {
                Flash_Info.multiProgram[ce_idx][0].func_p = devDriver(ce_idx)->TwoDieTwoPlaneCacheProgram ;
                Flash_Info.multiProgram[ce_idx][0].multiPageNum = 0xFF;
                Flash_Info.multiProgram[ce_idx][0].startAlign = 4;
                supportMPType_ce[ce_idx]|=CACHE_PROGRAM;
            }
            Flash_Info.multiProgram[ce_idx][m_idx].func_p = devDriver(ce_idx)->TwoDieTwoPlaneProgram ;
            Flash_Info.multiProgram[ce_idx][m_idx].multiPageNum = 4;
            Flash_Info.multiProgram[ce_idx][m_idx].startAlign = 4;
            supportMPType_ce[ce_idx]|=(TWO_DIE_INTERLEAVE_OP|TWO_PLANE_OP);
            if (m_idx == 1)
            {
                Flash_Info.bank_CE[ce_idx] = 4;
            }
            m_idx++;
        }
        else if ( ( (Flash_Info.supportMPType[ce_idx] & FOUR_PLANE_OP) == (FOUR_PLANE_OP))
                  && (devDriver(ce_idx)->FourPlaneProgram != NULL) )
        {
           dbg_ASSERT(Flash_Info.deviceInfo_CE[ce_idx].planeNum == 4);
            if ( (Flash_Info.supportMPType[ce_idx] & CACHE_PROGRAM)
                 && (devDriver(ce_idx)->FourPlaneProgram != NULL)
                 && (Flash_Info.multiProgram[ce_idx][0].func_p == NULL))
            {
                Flash_Info.multiProgram[ce_idx][0].func_p = devDriver(ce_idx)->FourPlaneCacheProgram ;
                Flash_Info.multiProgram[ce_idx][0].multiPageNum = 0xFF;
                Flash_Info.multiProgram[ce_idx][0].startAlign = 4;
                supportMPType_ce[ce_idx]|=CACHE_PROGRAM;
            }
            Flash_Info.multiProgram[ce_idx][m_idx].func_p = devDriver(ce_idx)->FourPlaneProgram ;
            Flash_Info.multiProgram[ce_idx][m_idx].multiPageNum = 4;
            Flash_Info.multiProgram[ce_idx][m_idx].startAlign = 4;
            supportMPType_ce[ce_idx]|=(FOUR_PLANE_OP);
            if (m_idx == 1)
            {
                Flash_Info.bank_CE[ce_idx] = 4;
            }
            m_idx++;
        }
        /*multiple 2 check */
        if ( ( (Flash_Info.supportMPType[ce_idx] & TWO_PLANE_OP) == TWO_PLANE_OP)
             && (devDriver(ce_idx)->TwoPlaneProgram != NULL) )
        {
           dbg_ASSERT(Flash_Info.deviceInfo_CE[ce_idx].planeNum == 2);
            if ( (Flash_Info.multiProgram[ce_idx][0].func_p == NULL)
                 && (Flash_Info.supportMPType[ce_idx] & CACHE_PROGRAM)
                 && (devDriver(ce_idx)->TwoPlaneCacheProgram != NULL)
               )
            {
                Flash_Info.multiProgram[ce_idx][0].func_p = devDriver(ce_idx)->TwoPlaneCacheProgram ;
                Flash_Info.multiProgram[ce_idx][0].multiPageNum = 0xFF;
                Flash_Info.multiProgram[ce_idx][0].startAlign = 2;
                supportMPType_ce[ce_idx]|=CACHE_PROGRAM;
            }

            Flash_Info.multiProgram[ce_idx][m_idx].func_p = devDriver(ce_idx)->TwoPlaneProgram ;
            Flash_Info.multiProgram[ce_idx][m_idx].multiPageNum = 2;
            Flash_Info.multiProgram[ce_idx][m_idx].startAlign = 2;
            supportMPType_ce[ce_idx]|=TWO_PLANE_OP;
            if (m_idx == 1)
            {
                Flash_Info.bank_CE[ce_idx] = 2;
            }
            m_idx++;
        }
        else if ( ((Flash_Info.supportMPType[ce_idx] & TWO_DIE_INTERLEAVE_OP) == TWO_DIE_INTERLEAVE_OP)
                  && (devDriver(ce_idx)->TwoDieProgram != NULL) )
        {
           dbg_ASSERT(Flash_Info.deviceInfo_CE[ce_idx].dieNum == 2);
            if ( (Flash_Info.multiProgram[ce_idx][0].func_p == NULL)
                 && (Flash_Info.supportMPType[ce_idx] & CACHE_PROGRAM)
                 && (devDriver(ce_idx)->TwoDieCacheProgram != NULL)
               )
            {
                Flash_Info.multiProgram[ce_idx][0].func_p = devDriver(ce_idx)->TwoDieCacheProgram ;
                Flash_Info.multiProgram[ce_idx][0].multiPageNum = 0xFF;
                Flash_Info.multiProgram[ce_idx][0].startAlign = 2;
                supportMPType_ce[ce_idx]|=CACHE_PROGRAM;
            }

            Flash_Info.multiProgram[ce_idx][m_idx].func_p = devDriver(ce_idx)->TwoDieProgram ;
            Flash_Info.multiProgram[ce_idx][m_idx].multiPageNum = 2;
            Flash_Info.multiProgram[ce_idx][m_idx].startAlign = 2;
            supportMPType_ce[ce_idx]|=TWO_DIE_INTERLEAVE_OP;
            if (m_idx == 1)
            {
                Flash_Info.bank_CE[ce_idx] = 2;
            }
            m_idx++;
        }
        /*1 page operation check */
        if ( (devDriver(ce_idx)->ProgramPage != NULL) )
        {
            if ( (Flash_Info.multiProgram[ce_idx][0].func_p == NULL)
                 && (Flash_Info.supportMPType[ce_idx] & CACHE_PROGRAM)
                 && (devDriver(ce_idx)->CacheProgram != NULL)
               )
            {
                Flash_Info.multiProgram[ce_idx][0].func_p = devDriver(ce_idx)->CacheProgram ;
                Flash_Info.multiProgram[ce_idx][0].multiPageNum = 0xFF;
                Flash_Info.multiProgram[ce_idx][0].startAlign = 1; /*any position % 1 == 0*/
                supportMPType_ce[ce_idx]|=CACHE_PROGRAM;
            }

            Flash_Info.multiProgram[ce_idx][m_idx].func_p = devDriver(ce_idx)->ProgramPage ;
            Flash_Info.multiProgram[ce_idx][m_idx].multiPageNum = 1;
            Flash_Info.multiProgram[ce_idx][m_idx].startAlign = 1; /*any position % 1 == 0*/
            if (m_idx == 1)
            {
                Flash_Info.bank_CE[ce_idx] = 1;
            }
            m_idx++;
        }
        /*set Flash_Info.supportMPType[ce_idx]*/
        Flash_Info.supportMPType[ce_idx] = supportMPType_ce[ce_idx];
        /*set Flash_Info.zone_CE[ce_idx]*/
        /*bank_len_zone must be smaller than planePage(ce_idx)*/
        bank_len_zone = devicePage(ce_idx)/Flash_Info.bank_CE[ce_idx] < planePage(ce_idx) ? devicePage(ce_idx)/Flash_Info.bank_CE[ce_idx] : planePage(ce_idx);
        Flash_Info.zone_CE[ce_idx] = devicePage(ce_idx)/(bank_len_zone*Flash_Info.bank_CE[ce_idx]);
    }
    return MTD_STATUS_NO_ERROR;
}
/****************************************************************************
 * Function:
 *
 * Parameters:
 *
 * Returns:
 *
 * Description: It will change Flash_Info.multiErase
 *                             Flash_Info.supportMEType
 *              according to the Flash_Info.deviceInfo_CE[ceIdx].driverSet and Flash_Info.supportMEType
 ****************************************************************************/
kal_uint32 init_multiErase ( void )
{
    kal_uint8   m_idx, ce_idx;
    kal_uint16  supportMEType_ce[2] = {0,0};

    kal_mem_set( Flash_Info.multiErase, 0x00, sizeof(Flash_Info.multiErase));
    for (ce_idx=0; ce_idx<2;ce_idx++)
    {
        for (m_idx=0; m_idx<MAX_MULTIPAGE_FUNCTION_NUM;m_idx++)
        {
            Flash_Info.multiErase[ce_idx][m_idx].startAlign = 0xFF;
        }
    }
    /*Operation function setting for each CE device*/
    for (ce_idx=0; ce_idx<2;ce_idx++)
    {
        if (Flash_Info.valid_CE[ce_idx] == KAL_FALSE)
            continue;

        Flash_Info.supportMEType[ce_idx] &= Flash_Info.supportMPType[ce_idx]; /*Multi Block erase support must follow (or less than) Multi-Page erase support*/
        /*The TWO_DIE_INTERLEAVE_OP, TWO_PLANE_OP, FOUR_PLANE_OP flags need to be redefined*/
        supportMEType_ce[ce_idx] = Flash_Info.supportMEType[ce_idx]& (~(TWO_DIE_INTERLEAVE_OP|TWO_PLANE_OP|FOUR_PLANE_OP));
        m_idx = 0;
        /*multiple 4 check */
        if ( ((Flash_Info.supportMEType[ce_idx] & (TWO_DIE_INTERLEAVE_OP|TWO_PLANE_OP)) == (TWO_DIE_INTERLEAVE_OP|TWO_PLANE_OP))
             && (devDriver(ce_idx)->TwoDieTwoPlaneErase != NULL) )
        {
           dbg_ASSERT(Flash_Info.deviceInfo_CE[ce_idx].dieNum == 2);
           dbg_ASSERT(Flash_Info.deviceInfo_CE[ce_idx].planeNum == 2);

            Flash_Info.multiErase[ce_idx][m_idx].func_p = devDriver(ce_idx)->TwoDieTwoPlaneErase ;
            Flash_Info.multiErase[ce_idx][m_idx].multiPageNum = 4;
            Flash_Info.multiErase[ce_idx][m_idx].startAlign = 4;
            supportMEType_ce[ce_idx]|=(TWO_DIE_INTERLEAVE_OP|TWO_PLANE_OP);
            m_idx++;
        }
        else if ( ((Flash_Info.supportMEType[ce_idx] & FOUR_PLANE_OP) == FOUR_PLANE_OP)
                  && (devDriver(ce_idx)->FourPlaneErase != NULL) )
        {
           dbg_ASSERT(Flash_Info.deviceInfo_CE[ce_idx].planeNum == 4);
            Flash_Info.multiErase[ce_idx][m_idx].func_p = devDriver(ce_idx)->FourPlaneErase ;
            Flash_Info.multiErase[ce_idx][m_idx].multiPageNum = 4;
            Flash_Info.multiErase[ce_idx][m_idx].startAlign = 4;
            supportMEType_ce[ce_idx]|=(FOUR_PLANE_OP);
            m_idx++;
        }
        /*multiple 2 check */
        if ( ((Flash_Info.supportMEType[ce_idx] & TWO_PLANE_OP) == TWO_PLANE_OP)
             && (devDriver(ce_idx)->TwoPlaneErase != NULL) )
        {
           dbg_ASSERT(Flash_Info.deviceInfo_CE[ce_idx].planeNum == 2);
            Flash_Info.multiErase[ce_idx][m_idx].func_p = devDriver(ce_idx)->TwoPlaneErase ;
            Flash_Info.multiErase[ce_idx][m_idx].multiPageNum = 2;
            Flash_Info.multiErase[ce_idx][m_idx].startAlign = 2;
            supportMEType_ce[ce_idx]|=TWO_PLANE_OP;
            m_idx++;
        }
        else if ( ((Flash_Info.supportMEType[ce_idx] & TWO_DIE_INTERLEAVE_OP) == TWO_DIE_INTERLEAVE_OP)
                  && (devDriver(ce_idx)->TwoDieErase != NULL) )
        {
           dbg_ASSERT(Flash_Info.deviceInfo_CE[ce_idx].dieNum == 2);

            Flash_Info.multiErase[ce_idx][m_idx].func_p = devDriver(ce_idx)->TwoDieErase ;
            Flash_Info.multiErase[ce_idx][m_idx].multiPageNum = 2;
            Flash_Info.multiErase[ce_idx][m_idx].startAlign = 2;
            supportMEType_ce[ce_idx]|=TWO_DIE_INTERLEAVE_OP;
            m_idx++;
        }
        /*1 page operation check */
        if ( (devDriver(ce_idx)->EraseBlock != NULL) )
        {
            Flash_Info.multiErase[ce_idx][m_idx].func_p = devDriver(ce_idx)->EraseBlock ;
            Flash_Info.multiErase[ce_idx][m_idx].multiPageNum = 1;
            Flash_Info.multiErase[ce_idx][m_idx].startAlign = 1; /*any position % 1 == 0*/
            m_idx++;
        }
        /*set Flash_Info.supportMEType[ce_idx]*/
        Flash_Info.supportMEType[ce_idx] = supportMEType_ce[ce_idx];
    }
    return MTD_STATUS_NO_ERROR;
}

kal_uint32 init_CE_interleave (void)
{
#if defined(ENABLE_ADVANCE_OPERATION)
    kal_uint8 m_idx, ce_idx;
#endif  // defined(ENABLE_ADVANCE_OPERATION)

    Flash_Info.CE_interleave_Flag = KAL_FALSE;
    Flash_Info.CE_cache_interleave_Flag = KAL_FALSE;

#if defined(ENABLE_ADVANCE_OPERATION)
    if (Flash_Info.valid_CE[1] == KAL_FALSE)
        return FS_NAND_DEVICE_NOT_SUPPORTED;
    /*FDM request the total bank number is order of 2*/
    if ( Flash_Info.bank_CE[0] != Flash_Info.bank_CE[1])
        return FS_NAND_DEVICE_NOT_SUPPORTED;
    /*zone number of each CE must be the same then CE_interleave can be support*/
    if ( Flash_Info.zone_CE[0] != Flash_Info.zone_CE[1] )
        return FS_NAND_DEVICE_NOT_SUPPORTED;
    /*bank size in zone of each CE must be the same then CE_interleave can be support*/
    if ( devicePage(0)/Flash_Info.zone_CE[0]/Flash_Info.bank_CE[0] != devicePage(1)/Flash_Info.zone_CE[1]/Flash_Info.bank_CE[1])
        return FS_NAND_DEVICE_NOT_SUPPORTED;

    if ( (Flash_Info.valid_CE[0] == KAL_TRUE && Flash_Info.valid_CE[1] == KAL_TRUE)
         #if 1 /*Limit CE interleave exists only at same device or not*/
         && kal_mem_cmp(&Flash_Info.deviceInfo_CE[0], &Flash_Info.deviceInfo_CE[1], sizeof(Flash_Info.deviceInfo_CE[0]) )==0 /*could loose this condition*/
         #endif
         )
    {
        for (ce_idx=0; ce_idx<2;ce_idx++)
        {
            Flash_Info.CE_cache_interleave_mOP_Idx[ce_idx] = 0xFF;
            Flash_Info.CE_interleave_mOP_Idx[ce_idx] = 0xFF;
            for (m_idx=0; m_idx< MAX_MULTIPAGE_FUNCTION_NUM; m_idx++)
            {
                if ( Flash_Info.multiProgram[ce_idx][m_idx].func_p != NULL && Flash_Info.multiProgram[ce_idx][m_idx].multiPageNum == 0xFF) /* cache function*/
                {
                    Flash_Info.CE_cache_interleave_mOP_Idx[ce_idx]= m_idx;
                    break;
                }
            }
            for (m_idx=0; m_idx< MAX_MULTIPAGE_FUNCTION_NUM; m_idx++)
            {
                if ( Flash_Info.multiProgram[ce_idx][m_idx].func_p != NULL && Flash_Info.multiProgram[ce_idx][m_idx].multiPageNum != 0xFF) /* non-cache function*/
                {
                    Flash_Info.CE_interleave_mOP_Idx[ce_idx]= m_idx;
                    break;
                }
            }
        }
        if (Flash_Info.CE_cache_interleave_mOP_Idx[0]!=0xFF && Flash_Info.CE_cache_interleave_mOP_Idx[1]!=0xFF)
            Flash_Info.CE_cache_interleave_Flag = KAL_TRUE;
        if (Flash_Info.CE_interleave_mOP_Idx[0]!=0xFF && Flash_Info.CE_interleave_mOP_Idx[1]!=0xFF)
            Flash_Info.CE_interleave_Flag = KAL_TRUE;
    }
#endif // defined(ENABLE_ADVANCE_OPERATION)
    return MTD_STATUS_NO_ERROR;
}
#if defined(__AUDIO_DSP_LOWPOWER__)
void DAL_MP3InitVariable(void)
{
    NFI_ConfigforMP3.nfi_ACCCON_reg = *NFI_ACCCON;
    NFI_ConfigforMP3.nfi_page_size = Flash_Info.pageSize;
    NFI_ConfigforMP3.nfi_spare_size = 16;
    NFI_ConfigforMP3.nfi_pages_per_block = Flash_Info.blockPage;
    NFI_ConfigforMP3.nfi_fdm_size = 8;// FDM size fixed to 8 Bytes
    NFI_ConfigforMP3.nfi_sector_num = (Flash_Info.pageSize/512);
    NFI_ConfigforMP3.nfi_data_sectors = (Flash_Info.pageSize/512);
    if(Flash_Info.pageSize==512)
    {
        NFI_ConfigforMP3.nfi_col_num = 1;
        NFI_ConfigforMP3.nfi_row_num = (Flash_Info.deviceInfo_CE[0].address_cycle-1);
    }
    else
    {
        NFI_ConfigforMP3.nfi_col_num = 2;
        NFI_ConfigforMP3.nfi_row_num = (Flash_Info.deviceInfo_CE[0].address_cycle-2);
    }
    if(Flash_Info.deviceInfo_CE[0].IOWidth==16)
    {
        NFI_ConfigforMP3.nfi_io_width = 1;
    }
    else
    {
        NFI_ConfigforMP3.nfi_io_width = 0;
    }
}
#endif //#if defined(__AUDIO_DSP_LOWPOWER__)

/****************************************************************************
 * Function:
 *
 * Parameters:  void
 *
 * Returns:     FS_NO_ERROR
 *              FS_NAND_DEVICE_NOT_SUPPORTED
 *              FS_FLASH_MOUNT_ERROR
 * Description:
 *
 ****************************************************************************/
 /*Note: Please DO NOT modify the function name, because append2.pl use this function name to identify
* __NAND_FDM_50__ and apply the MTK_ROMInfo_v06_ST */

kal_int32 DAL_init (void)
{
    //kal_uint8 m_idx, ce_idx, i;
    kal_uint8 ce_idx;
    kal_uint8 bank_num;
    kal_uint32 bank_len_zone;  /*bank length in zone, unit by page*/
    kal_int32 retVal;
    get_MTD_lock();
    kal_mem_set(&Flash_Info,0x00, sizeof(Flash_Info) );

    /*Get CE# ID and set dev_driver, devicePage*/ /*2 CE must : same block size, same page size, same EXTENDED_BLOCK or not*/ /*same PLANE_INTERLACED or PLANE_CONTINUOUS ??*/
    retVal = MTD_MountDevice();
    if (retVal != FS_NO_ERROR)
    {
        DAL_is_initialized = KAL_TRUE;
        free_MTD_lock();
        return retVal;
    }
    if (Flash_Info.valid_CE[1] == KAL_TRUE)
    {
        dbg_ASSERT(Flash_Info.deviceInfo_CE[0].pageSize == Flash_Info.deviceInfo_CE[1].pageSize);
        dbg_ASSERT(Flash_Info.deviceInfo_CE[0].spareSize == Flash_Info.deviceInfo_CE[1].spareSize);
        dbg_ASSERT(Flash_Info.deviceInfo_CE[0].blockPage == Flash_Info.deviceInfo_CE[1].blockPage);
        dbg_ASSERT(Flash_Info.deviceInfo_CE[0].IOWidth == Flash_Info.deviceInfo_CE[1].IOWidth);
        dbg_ASSERT( (Flash_Info.deviceInfo_CE[0].supportMPType&EXTENDED_BLOCK) == (Flash_Info.deviceInfo_CE[1].supportMPType&EXTENDED_BLOCK));
        dbg_ASSERT( (Flash_Info.deviceInfo_CE[0].supportMPType&PLANE_INTERLACED) == (Flash_Info.deviceInfo_CE[1].supportMPType&PLANE_INTERLACED)); /*FDM layer limitation*/
        if (Flash_Info.deviceInfo_CE[0].supportMPType&EXTENDED_BLOCK) /**only support 2 same NAND with EXTENDED_BLOCK*/
        {
            #if defined(__MTK_TARGET__)
            force_ASSERT(kal_mem_cmp(&Flash_Info.deviceInfo_CE[0],&Flash_Info.deviceInfo_CE[1], sizeof(Flash_Info.deviceInfo_CE[0])) == 0, 0,0,0);
            #endif
            force_ASSERT( Flash_Info.deviceInfo_CE[0].supportMPType& PLANE_CONTINUOUS,Flash_Info.deviceInfo_CE[0].supportMPType,0,0 );
        }
    }
    Flash_Info.pageSize = Flash_Info.deviceInfo_CE[0].pageSize;
    Flash_Info.spareSize = Flash_Info.deviceInfo_CE[0].spareSize;
    #if !(defined __UBL__)
    force_ASSERT( sizeof(DAL_spare_buff) >= Flash_Info.spareSize,sizeof(DAL_spare_buff),Flash_Info.spareSize,0);
    #endif
    Flash_Info.blockPage = Flash_Info.deviceInfo_CE[0].blockPage;
    /*Operation function setting for each CE device*/
    Flash_Info.supportMPType[0] = Flash_Info.deviceInfo_CE[0].supportMPType;
    Flash_Info.supportMPType[1] = (Flash_Info.valid_CE[1] == KAL_TRUE) ?  Flash_Info.deviceInfo_CE[1].supportMPType : 0;

    init_multiProgram ();

    Flash_Info.supportMEType[0] = Flash_Info.deviceInfo_CE[0].supportMEType;
    Flash_Info.supportMEType[1] = Flash_Info.deviceInfo_CE[1].supportMEType;
    init_multiErase ();

    /* Set Flash_Info.CE_interleave parameters*/
    init_CE_interleave();

    /*shrink Zone size if both CE have device and different zone size*/
    if (Flash_Info.valid_CE[0] == KAL_TRUE && Flash_Info.valid_CE[1] == KAL_TRUE)
    {
        if ( Flash_Info.CE_interleave_Flag == KAL_FALSE )
        {
            bank_num = Flash_Info.bank_CE[0] < Flash_Info.bank_CE[1] ? Flash_Info.bank_CE[0] : Flash_Info.bank_CE[1] ;
            while (!(bank_num == Flash_Info.bank_CE[0] && bank_num == Flash_Info.bank_CE[1]))
            {
                for (ce_idx=0; ce_idx<2;ce_idx++)
                {
                    if ( Flash_Info.bank_CE[ce_idx] >  bank_num)
                    {
                        if ((Flash_Info.supportMPType[ce_idx]&TWO_DIE_INTERLEAVE_OP)!=0)
                        {
                            Flash_Info.supportMPType[ce_idx]&=(~TWO_DIE_INTERLEAVE_OP);
                            Flash_Info.bank_CE[ce_idx]/=2;
                        }
                        else if ((Flash_Info.supportMPType[ce_idx]&FOUR_PLANE_OP)!=0)
                        {
                            Flash_Info.supportMPType[ce_idx]&=(~FOUR_PLANE_OP);
                            Flash_Info.bank_CE[ce_idx]/=4;
                        }
                        else if ((Flash_Info.supportMPType[ce_idx]&TWO_PLANE_OP)!=0)
                        {
                            Flash_Info.supportMPType[ce_idx]&=(~TWO_PLANE_OP);
                            Flash_Info.bank_CE[ce_idx]/=2;
                        }
                        bank_num = bank_num < Flash_Info.bank_CE[ce_idx] ? bank_num : Flash_Info.bank_CE[ce_idx];
                        dbg_ASSERT(bank_num > 0);
                    }
                }
            }
            /*after setting of Flash_Info.supportMPType[ce_idx], re-assign Flash_Info.multiProgram*/
            init_multiProgram ( );
            init_multiErase ();
            dbg_ASSERT(Flash_Info.bank_CE[0] == Flash_Info.bank_CE[1]);
        }
        bank_len_zone = (devicePage(0)/Flash_Info.zone_CE[0]/Flash_Info.bank_CE[0] < devicePage(1)/Flash_Info.zone_CE[1]/Flash_Info.bank_CE[1] ) ?
                        devicePage(0)/Flash_Info.zone_CE[0]/Flash_Info.bank_CE[0] : devicePage(1)/Flash_Info.zone_CE[1]/Flash_Info.bank_CE[1];

        Flash_Info.zone_CE[0] = devicePage(0) / (bank_len_zone * Flash_Info.bank_CE[0]);
        Flash_Info.zone_CE[1] = devicePage(1) / (bank_len_zone * Flash_Info.bank_CE[1]);
    }
    /*else is single CE case, Flash_Info.zone_CE[0] is set by init_multiProgram*/

    Flash_Info.bankNum = (Flash_Info.CE_interleave_Flag == KAL_FALSE ? (Flash_Info.bank_CE[0]):(Flash_Info.bank_CE[0]+Flash_Info.bank_CE[1]));
    Flash_Info.zoneNum = (Flash_Info.CE_interleave_Flag == KAL_FALSE ? (Flash_Info.zone_CE[0]+Flash_Info.zone_CE[1]):(Flash_Info.zone_CE[0]));
    force_ASSERT( MAX_MULTIPAGE_NUM >= Flash_Info.bankNum,Flash_Info.bankNum,0,0 );
    if (Flash_Info.deviceInfo_CE[0].supportMPType&EXTENDED_BLOCK) /*if using EXTENDED_BLOCK NAND, must full support multi-page operation*/
    {
        force_ASSERT( Flash_Info.zoneNum == 1,Flash_Info.zoneNum,0,0 );
    }
    kal_mem_set(MapCache, 0xFF, sizeof(MapCache));
    kal_mem_set(MapCacheCount, 0xFF, sizeof(MapCacheCount));

    DAL_is_initialized = KAL_TRUE;
#if defined (__AUDIO_DSP_LOWPOWER__)
    DAL_MP3InitVariable();
#endif //__AUDIO_DSP_LOWPOWER__
    free_MTD_lock();
    return FS_NO_ERROR;
}
/****************************************************************************
 * Function:
 *
 * Parameters:  void
 *
 * Returns:     FS_NO_ERROR
 *
 * Description:
 *
 ****************************************************************************/
kal_int32 DAL_ShutDown (void)
{
    kal_int32 retVal;
    get_MTD_lock();
    retVal = MTD_ShutDown();
    free_MTD_lock();
    return retVal;
}

kal_int32 DAL_FDM_Flash_Info_Init ( FLASH_INFO* fdm_flash_info, kal_uint32 DiskIndex)
{
    kal_uint32 FAT_start_position;
    kal_uint32 FAT_length;
    kal_uint32 zone_len;
    kal_uint16 i;
    kal_uint8  FAT_start_z, FAT_end_z;
    kal_uint32 sectionPage = 0;

    get_MTD_lock();

    /*fill fdm_flash_info->BankNumber*/
    fdm_flash_info->BankNumber = Flash_Info.bankNum;
    /*fill fdm_flash_info->SectorNumPerPage*/
    fdm_flash_info->SectorNumPerPage = Flash_Info.pageSize/512;
    /*fill fdm_flash_info->PageNumPerSection*/
    fdm_flash_info->PageNumPerSection = fdm_flash_info->BankNumber * Flash_Info.blockPage;
    /*fill fdm_flash_info->PageNumPerSection*/
    sectionPage = fdm_flash_info->PageNumPerSection;
    for (i = 0; i < 32; i++)
    {
        if (sectionPage == (kal_uint32)(1<<i))
            break;
    }
    dbg_ASSERT(i < 32);
    fdm_flash_info->SectionShiftNum = i;

    /*fill fdm_flash_info->Plane_PagePair*/
    if ((Flash_Info.deviceInfo_CE[0].driverSet->TwoPlaneProgram == samsung_twoPlane_Program) &&
    	(Flash_Info.supportMPType[0] & TWO_PLANE_OP))
    {
        fdm_flash_info->Plane_PagePair = KAL_TRUE;
    }
    else
    {
        fdm_flash_info->Plane_PagePair = KAL_FALSE;
    }

		#if (defined (_NAND_FLASH_BOOTING_) || defined(__NANDFDM_MULTI_INSTANCE__) || (defined(__UP_PKG_ON_NAND__) && defined(NAND_SUPPORT)) ) && (!defined(__UBL__)||(defined(__UBL__)&&defined(__NAND_SUPPORT_RAW_DISK__)))
	#if !defined(__NANDFDM_MULTI_INSTANCE__)
    FAT_start_position = NFB_BASE_ADDRESS;
    FAT_length = NFB_ALLOCATED_FAT_SPACE;
	#else // !defined(__NANDFDM_MULTI_INSTANCE__)
    FAT_start_position = NFB_BASE_ADDRESS[DiskIndex];
    FAT_length = NFB_ALLOCATED_FAT_SPACE[DiskIndex];
	#endif // !defined(__NANDFDM_MULTI_INSTANCE__)


    FAT_start_position = (FAT_start_position + (Flash_Info.pageSize -1)) / Flash_Info.pageSize ; /*move to page aligned and unit by page*/
    FAT_start_position = (FAT_start_position + (sectionPage - 1)) / sectionPage * sectionPage; /*move to section aligned*/
    FAT_length /= Flash_Info.pageSize; /*reduce size to page aligned and unit by page*/
    FAT_length = FAT_length / sectionPage * sectionPage; /*reduce size to section aligned*/
    #else
    FAT_start_position = 0;  /*unit by page*/
    FAT_length = devicePage(0) + (Flash_Info.valid_CE[1] == KAL_TRUE ? devicePage(1) : 0); /*full NAND size is used for FAT */
    FAT_length = (Flash_Info.supportMPType[0]& EXTENDED_BLOCK) ? FAT_length/1024*(1024+16):FAT_length; /*consider EXTENDED_BLOCK size*/
    FAT_length = FAT_length / sectionPage * sectionPage; /*reduce size to section aligned*/
    #endif /* _NAND_FLASH_BOOTING_ || defined(__NANDFDM_MULTI_INSTANCE__) || (__UP_PKG_ON_NAND__ && NAND_SUPPORT) */
    /*calculate zone_len*/
    if (Flash_Info.CE_interleave_Flag == KAL_FALSE)
    {
        if ( Flash_Info.valid_CE[1] == KAL_TRUE )
        {
            dbg_ASSERT( zonePage(0) == zonePage(1) );
        }
        zone_len = zonePage(0);
    }
    else
    {
        zone_len = zonePage(0) + zonePage(1);
    }

    /*fill fdm_flash_info->ExtendBlock*/
    if ( (Flash_Info.supportMPType[0]& EXTENDED_BLOCK) == EXTENDED_BLOCK)
    {
        zone_len = zone_len / 1024 * (1024+16);
        fdm_flash_info->ExtendBlock = KAL_TRUE;
    }
    else
    {
        fdm_flash_info->ExtendBlock = KAL_FALSE;
    }
    FAT_start_z = FAT_start_position / zone_len;
    FAT_end_z = ( FAT_start_position+FAT_length - 1 ) / zone_len;
    /*fill fdm_flash_info->TotalZoneNum*/
    fdm_flash_info->TotalZoneNum = FAT_end_z - FAT_start_z + 1;
    dbg_ASSERT(fdm_flash_info->TotalZoneNum <= NUM_OF_ZONES);
    /*fill fdm_flash_info->PSectionNumInZone*/
    /*first one*/
    fdm_flash_info->PSectionNumInZone[0] =
        (zone_len - (FAT_start_position % zone_len)) < FAT_length ? (zone_len - (FAT_start_position % zone_len))/sectionPage : FAT_length/sectionPage;
    for (i = FAT_start_z + 1; i < FAT_end_z; i++)
    {
        fdm_flash_info->PSectionNumInZone[i - FAT_start_z] = zone_len/sectionPage;
    }
#if defined(__NANDFDM_MULTI_INSTANCE__)
    fdm_flash_info->TotalPSectionNumInZone = zone_len/sectionPage;
#endif // defined(__NANDFDM_MULTI_INSTANCE__)
    if (FAT_end_z > FAT_start_z)
       fdm_flash_info->PSectionNumInZone[FAT_end_z - FAT_start_z] = ( (( FAT_start_position+ FAT_length - 1)  % zone_len) + 1)/sectionPage;/*last one*/

    #if defined (_NAND_FLASH_BOOTING_) || defined(__NANDFDM_MULTI_INSTANCE__) || (defined(__UP_PKG_ON_NAND__) && defined(NAND_SUPPORT))
    /*Fill the global variables FAT_Start_ZoneNum and FAT_Start_Section_Offset*/
	#if !defined(__NANDFDM_MULTI_INSTANCE__)
    FAT_Start_ZoneNum = FAT_start_z;
    FAT_Start_Section_Offset = (FAT_start_position % zone_len)/sectionPage;
	#else // !defined(__NANDFDM_MULTI_INSTANCE__)
    FAT_Start_ZoneNum[DiskIndex] = FAT_start_z;
    FAT_Start_Section_Offset[DiskIndex] = (FAT_start_position % zone_len)/sectionPage;
	#endif //!defined(__NANDFDM_MULTI_INSTANCE__)
	#if defined (__NAND_LMT__)

	{
		extern kal_uint32 IM_FAT_Start_Section;
		extern kal_uint32 IM_FAT_Start_Zone;

		IM_FAT_Start_Section = FAT_Start_Section_Offset;
		IM_FAT_Start_Zone = FAT_Start_ZoneNum;
		if (!bWholeImage) {

			FAT_Start_Section_Offset = 0;
			FAT_Start_ZoneNum = 0;
		}
	}

	#endif // defined (__NAND_LMT__)

    #endif /* _NAND_FLASH_BOOTING_ || defined(__NANDFDM_MULTI_INSTANCE__) || (__UP_PKG_ON_NAND__ && NAND_SUPPORT) */

    free_MTD_lock();
    return MTD_STATUS_NO_ERROR;
}


kal_uint32 readMapCache(add_convert* AddInfo,kal_uint8* ce_p, kal_uint32* Zoffset_p,kal_uint32* Boffset_p )
{
    kal_uint8 bIdx = AddInfo->pageIdx%Flash_Info.bankNum;
    if ( AddInfo->bankArry[bIdx] == MapCache[bIdx][0].blockNum )
    {
        if (AddInfo->zoneNum == MapCache[bIdx][0].zoneNum )
        {
            *Zoffset_p = MapCache[bIdx][0].zoneOffset;
            *Boffset_p = MapCache[bIdx][0].bankOffset;
            *ce_p = MapCache[bIdx][0].ce;
            return KAL_TRUE;
        }
    }
    else if ( AddInfo->bankArry[bIdx] == MapCache[bIdx][1].blockNum )
    {
        if (AddInfo->zoneNum == MapCache[bIdx][1].zoneNum )
        {
            *Zoffset_p = MapCache[bIdx][1].zoneOffset;
            *Boffset_p = MapCache[bIdx][1].bankOffset;
            *ce_p = MapCache[bIdx][1].ce;
            return KAL_TRUE;
        }
    }
    return KAL_FALSE;
}

kal_uint32 writeMapCache(add_convert* AddInfo, kal_uint32 Zoffset,kal_uint32 Boffset )
{
    kal_uint8 bIdx = AddInfo->pageIdx%Flash_Info.bankNum;
    kal_uint8 cnt = MapCacheCount[bIdx]%2;

    MapCache[bIdx][cnt].zoneNum = AddInfo->zoneNum;
    MapCache[bIdx][cnt].blockNum = AddInfo->bankArry[bIdx];

    MapCache[bIdx][cnt].ce = AddInfo->ce;
    MapCache[bIdx][cnt].zoneOffset = Zoffset;
    MapCache[bIdx][cnt].bankOffset = Boffset;

    MapCacheCount[bIdx] = cnt ? 0:1;
    return KAL_TRUE;
}
/*Can not support EXTENDED_BLOCK now*/
kal_uint32 addressMap(add_convert* AddInfo)
{

    kal_uint8  ce_idx, zoneNum;
    kal_uint32 zoneOffset;
    kal_uint8  cacheHitFlag;
    kal_uint8  bk_idx_die; /*bank index refer to the die*/
    kal_uint32 bankOffset, pageOffset;
    kal_uint16 blk_num;
    kal_uint32 tmp, bank_len_zone;

    ce_idx = BYTE_INVALID;
    zoneOffset = DWORD_INVALID;
    bankOffset = DWORD_INVALID;
    cacheHitFlag = readMapCache(AddInfo,&ce_idx,&zoneOffset,&bankOffset);
    /*Get the zoneOffset (unit by page) -- Start*/
    if ( zoneOffset == DWORD_INVALID)
    {
      #if defined(__NANDFDM_TOTAL_BBM__)
      bk_idx_die = AddInfo->pageIdx%Flash_Info.bankNum; /*now bk_idx_die is bk_idx of all Flash*/
      blk_num = AddInfo->bankArry[bk_idx_die];
      if(blk_num&BBM_GLOBAL_ADDR)
      {
        zoneNum = 0;
      }
      else
      {
        zoneNum = AddInfo->zoneNum;
      }
      #else  //#if defined(__NANDFDM_TOTAL_BBM__)
        zoneNum = AddInfo->zoneNum;
      #endif //#if defined(__NANDFDM_TOTAL_BBM__)
         /*Get the CE of zone*/
        if (Flash_Info.CE_interleave_Flag == KAL_FALSE)
        {
            if (zoneNum < Flash_Info.zone_CE[0])
                ce_idx = 0;
            else
            {
                ce_idx = 1;
                zoneNum -= Flash_Info.zone_CE[0];
            }
            dbg_ASSERT( zoneNum <= Flash_Info.zone_CE[ce_idx]);
        }
        else
        {
            if (AddInfo->pageIdx % Flash_Info.bankNum < Flash_Info.bank_CE[0]  )
            {
                ce_idx = 0;
            }
            else
            {
                ce_idx = 1;
            }
            dbg_ASSERT( zoneNum <= Flash_Info.zone_CE[0]);
        }

        #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #else
        tmp = planePage(ce_idx)*Flash_Info.bank_CE[ce_idx]; /* tmp = n die size, n = bank_CE[ce_idx]/die plane Numer (deviceInfo_CE[ceIdx].planeNum) */
        zoneOffset =  tmp* (zoneNum/(tmp/zonePage(ce_idx)))  ; /*here zoneOffset is page that part of die aligned */
        zoneNum -= (zoneOffset/zonePage(ce_idx)); /*here zoneNum is reminder part of !(die aligned)*/
        if ( (Flash_Info.supportMPType[ce_idx]& EXTENDED_BLOCK) == EXTENDED_BLOCK)
            zoneOffset = zoneOffset / 1024 * (1024+16) ;
        #endif

        if ( (Flash_Info.supportMPType[ce_idx]& EXTENDED_BLOCK) == EXTENDED_BLOCK)
        {
            dbg_ASSERT(zoneNum == 0); /*in EXTENDED_BLOCK case, zone should be die aligned*/
        }
        bank_len_zone = zonePage(ce_idx)/Flash_Info.bank_CE[ce_idx];
        tmp = bank_len_zone * zoneNum; /* tmp = bank_len_zone * zoneNum */

        if ( (Flash_Info.supportMPType[ce_idx]&(TWO_PLANE_OP|PLANE_INTERLACED)) == (TWO_PLANE_OP|PLANE_INTERLACED) )
        {
            zoneOffset += tmp*2;
        }
        else if ( (Flash_Info.supportMPType[ce_idx]&(FOUR_PLANE_OP|PLANE_INTERLACED)) == (FOUR_PLANE_OP|PLANE_INTERLACED) )
        {
            zoneOffset += tmp*4;
        }
        else
        {
            zoneOffset += tmp;
        }
         /*here get the correct zoneOffset*/
    }
    /*Get the zoneOffset (unit by page) -- End*/
    /*Get the bankOffset (unit by page) -- Start*/
    if (bankOffset == DWORD_INVALID)
    {
        bk_idx_die = AddInfo->pageIdx%Flash_Info.bankNum; /*now bk_idx_die is bk_idx of all Flash*/
        blk_num = AddInfo->bankArry[bk_idx_die];
        #if defined(__NANDFDM_TOTAL_BBM__)
        if(blk_num&BBM_GLOBAL_ADDR)
        {
          blk_num &=(~BBM_GLOBAL_ADDR);
        }
        #endif
        if ( Flash_Info.CE_interleave_Flag == KAL_TRUE && ce_idx == 1)
        {
            bk_idx_die -= Flash_Info.bank_CE[0];
        }
         /*now bk_idx_die is bk_idx of ce_idx*/
        bankOffset = 0;
        if ( (Flash_Info.supportMPType[ce_idx]& TWO_DIE_INTERLEAVE_OP) == TWO_DIE_INTERLEAVE_OP)
        {
            if ( bk_idx_die >= (Flash_Info.bank_CE[ce_idx]/2) )
            {
                if ( (Flash_Info.supportMPType[ce_idx]& EXTENDED_BLOCK) == EXTENDED_BLOCK)
                    bankOffset += diePage(ce_idx) / 1024 * (1024+16) ; /*here zone offset is the page that part of 1st die*/
                else
                    bankOffset += diePage(ce_idx);
                //bk_idx_die /= 2;
                bk_idx_die -= (Flash_Info.bank_CE[ce_idx]/2);
            }
        }
         /*now bk_idx_die is bk_idx of die*/
        if ( (Flash_Info.supportMPType[ce_idx]&(TWO_PLANE_OP|PLANE_INTERLACED)) == (TWO_PLANE_OP|PLANE_INTERLACED) )
        {
            bankOffset += (blk_num*2+bk_idx_die) * Flash_Info.blockPage;
        }
        else if ( (Flash_Info.supportMPType[ce_idx]&(FOUR_PLANE_OP|PLANE_INTERLACED)) == (FOUR_PLANE_OP|PLANE_INTERLACED) )
        {
            bankOffset += (blk_num*4+bk_idx_die) * Flash_Info.blockPage;
        }
        else /*PLANE_CONTINUOUS */
        {
            if (Flash_Info.supportMPType[ce_idx]& EXTENDED_BLOCK)
            {
                if ( blk_num < planePage(ce_idx)/Flash_Info.blockPage ) /*not inside the extended block area case*/
                {
                    bankOffset += bk_idx_die*planePage(ce_idx)+ blk_num* Flash_Info.blockPage;
                }
                else
                {   /*only EXTENDED_BLOCK is possible to run here*/
                    dbg_ASSERT(Flash_Info.supportMPType[ce_idx]& EXTENDED_BLOCK);
                    bankOffset += diePage(ce_idx); /* + regular block area page*/
                    bankOffset += bk_idx_die * planePage(ce_idx) / 1024 * 16; /* + full extended blocks of planes*/
                    bankOffset += ( blk_num - planePage(ce_idx)/Flash_Info.blockPage )* Flash_Info.blockPage; /* + extended block offset*/
                }
            }
            else
            {   /*!EXTENDED_BLOCK case*/
                bankOffset += bk_idx_die*planePage(ce_idx)+ blk_num* Flash_Info.blockPage;
            }
        }
         /*here get the correct bankOffset*/
    }
    /*Get the bankOffset (unit by page) -- End*/
    /*Get the pageOffset (unit by page) -- Start*/
    dbg_ASSERT( AddInfo->pageIdx < Flash_Info.bankNum*Flash_Info.blockPage);
    pageOffset = AddInfo->pageIdx/Flash_Info.bankNum;
    /*Get the bankOffset (unit by page) -- End*/
    /*fill to AddInfo*/
    AddInfo->phyPage = zoneOffset + bankOffset + pageOffset;
    AddInfo->ce = ce_idx;
    #if defined(__NANDFDM_TOTAL_BBM__)
    if(AddInfo->phyPage>=Flash_Info.devicePage[0])
    {
      ASSERT(Flash_Info.valid_CE[1]==KAL_TRUE);
      AddInfo->ce = 1;
      AddInfo->phyPage = (AddInfo->phyPage-Flash_Info.devicePage[0]);
    }
    #endif

	force_ASSERT(AddInfo->phyPage<Flash_Info.devicePage[AddInfo->ce],
		AddInfo->phyPage, Flash_Info.devicePage[AddInfo->ce], AddInfo->ce);
    if (cacheHitFlag == KAL_FALSE)
        writeMapCache(AddInfo,zoneOffset,bankOffset);

    return MTD_STATUS_NO_ERROR;
}


/****************************************************************************
 * Function:
 *
 * Parameters:  Spare - spare buffer, only FDM Data (about 8 bytes) inside
 *                      if Spare == NULL, mean the spare data is careless
 *
 * Returns:     Low 2 byte: error Page
 *              High 2 byte: error code
 * Description:
 *
 ****************************************************************************/
kal_int32 DAL_ProgramPage(DAL_ACC_Type Acc_Type, kal_uint8 ZoneNo, kal_uint16 *Bank, kal_uint16 PageAddr, kal_uint16 PageLength, kal_uint8 *Data, kal_uint8 *Spare)
{
    kal_uint8  m_idx = 0;
    kal_uint8  bk_idx_ce;
    kal_uint8  ce_idx = 0;
    kal_uint16 writingLen,writenLen,  i;
    kal_uint32 (*mtd_fp) (mtd_if_para*);
    kal_uint32 retVal = MTD_STATUS_NO_ERROR;
   	#if defined(__DEMAND_PAGING__) && !defined(__FUE__) && !defined(__UBL__)
    kal_uint32 LockLength = PageLength*Flash_Info.pageSize;	
    #endif 
		// Get demand lock before MTD lock to keep to avoid potential dead lock.
		// eg. Get MTD but can not get demand lock.
    #if defined(__DEMAND_PAGING__) && !defined(__FUE__) && !defined(__UBL__)
    if (Acc_Type == FAT_ACC) {
	    demp_lock_pages(DEMP_LOCK_NAND, (kal_uint32)Data, LockLength);
    }
    #endif 

    get_MTD_lock();

    #if defined (_NAND_FLASH_BOOTING_) || defined(__NANDFDM_MULTI_INSTANCE__) || (defined(__UP_PKG_ON_NAND__) && defined(NAND_SUPPORT))
    if (Acc_Type == FAT_ACC)
    {
        for (i=0;i< Flash_Info.bankNum; i++)
        {
          #if defined(__NANDFDM_TOTAL_BBM__)
          if(Bank[i]&BBM_GLOBAL_ADDR)
          {
            DAL_Bank_Array[i] = Bank[i];
          }
          else
          #endif //#if defined(__NANDFDM_TOTAL_BBM__)
	        if (ZoneNo == 0)
    	    {
#if !defined(__NANDFDM_MULTI_INSTANCE__)
                DAL_Bank_Array[i] = Bank[i] + FAT_Start_Section_Offset;
#else // !defined(__NANDFDM_MULTI_INSTANCE__)
                DAL_Bank_Array[i] = Bank[i] + FAT_Start_Section_Offset[CurDiskIndex];
#endif //!defined(__NANDFDM_MULTI_INSTANCE__)
            } else {
                DAL_Bank_Array[i] = Bank[i];
            }
        }
        Bank = DAL_Bank_Array;
#if !defined(__NANDFDM_MULTI_INSTANCE__)
        ZoneNo += FAT_Start_ZoneNum;
#else // !defined(__NANDFDM_MULTI_INSTANCE__)
        ZoneNo += FAT_Start_ZoneNum[CurDiskIndex];
#endif // !defined(__NANDFDM_MULTI_INSTANCE__)
    }
    #else
    if (Acc_Type != FAT_ACC)
    {
        dbg_ASSERT(0);
        #if defined (_NAND_FLASH_BOOTING_)
	    if (Acc_Type == FAT_ACC) {
    	    demp_unlock_pages(DEMP_LOCK_NAND, (kal_uint32)Data, LockLength);
	    }
        #endif        
        free_MTD_lock();        
        return MTD_STATUS_PARA_ERROR;
    }
    #endif /* _NAND_FLASH_BOOTING_ || defined(__NANDFDM_MULTI_INSTANCE__) || (__UP_PKG_ON_NAND__ && NAND_SUPPORT))*/
    /*boundary check*/
    if ( (ZoneNo >= Flash_Info.zoneNum) || ( PageAddr+PageLength > Flash_Info.bankNum*Flash_Info.blockPage ) )
    {
    	  force_ASSERT(0,ZoneNo,(PageAddr+PageLength),0);        
        #if defined(__DEMAND_PAGING__) && !defined(__FUE__) && !defined(__UBL__)
	    if (Acc_Type == FAT_ACC) {
	        demp_unlock_pages(DEMP_LOCK_NAND, (kal_uint32)Data, LockLength);
	    }
        #endif        
        free_MTD_lock();        
        return MTD_STATUS_PARA_ERROR;
    }

    writenLen = 0;
    kal_mem_set(&Mtd_para, 0x00,sizeof(Mtd_para));
    Add_Cnvt.zoneNum = ZoneNo ;
    Add_Cnvt.bankArry = Bank;
    while ( PageLength )
    {
        /*Get the mtd_fp, m_idx & writingLen*/
        mtd_fp = NULL;
        writingLen = 0;
        if ( Flash_Info.CE_interleave_Flag == KAL_TRUE )
        {
            if ( (PageAddr % Flash_Info.bankNum) == 0)
            {
                if (PageLength >= Flash_Info.bankNum*2 &&
                    Flash_Info.CE_cache_interleave_Flag == KAL_TRUE)
                {
                    writingLen = Flash_Info.bankNum * (PageLength / Flash_Info.bankNum);
                    writingLen = writingLen < 16 ? writingLen : 16; /*Maximun number to MTD is 16*/
                    m_idx = Flash_Info.CE_cache_interleave_mOP_Idx[0];
                    mtd_fp = MTD_CE_Interleave_CacheProgram;
                }
                else if ( PageLength >= Flash_Info.bankNum )
                {
                    writingLen = Flash_Info.bankNum ;
                    m_idx = Flash_Info.CE_interleave_mOP_Idx[0];
                    mtd_fp = MTD_CE_Interleave_Program;
                }
            }
        }
        if (mtd_fp == NULL)
        {
            Add_Cnvt.pageIdx = PageAddr;
            addressMap(&Add_Cnvt);
            ce_idx = Add_Cnvt.ce;
            bk_idx_ce = PageAddr%Flash_Info.bankNum;
            if ( Flash_Info.CE_interleave_Flag == KAL_TRUE && ce_idx == 1)
            {
                bk_idx_ce -= Flash_Info.bank_CE[0];
            }
            for (m_idx=0; m_idx< MAX_MULTIPAGE_FUNCTION_NUM; m_idx++)
            {
                if ( Flash_Info.multiProgram[ce_idx][m_idx].func_p != NULL
                     && ((bk_idx_ce%Flash_Info.multiProgram[ce_idx][m_idx].startAlign) ==0) )
                {   /*cache program check*/
                    if ( Flash_Info.multiProgram[ce_idx][m_idx].multiPageNum == 0xFF 
                         && (PageLength >= Flash_Info.multiProgram[ce_idx][m_idx].startAlign*2)
                         && Flash_Info.CE_interleave_Flag == KAL_FALSE )
                    {
                        writingLen = (Flash_Info.multiProgram[ce_idx][m_idx].startAlign)*(PageLength/(Flash_Info.multiProgram[ce_idx][m_idx].startAlign));
                        writingLen = writingLen < 16 ? writingLen : 16; /*Maximun number to MTD is 16*/
                        mtd_fp = MTD_CacheProgram;
                        break;
                    }
                    else if (PageLength >= Flash_Info.multiProgram[ce_idx][m_idx].multiPageNum)
                    {
                        writingLen = (Flash_Info.multiProgram[ce_idx][m_idx].multiPageNum);
                        mtd_fp = MTD_Program;
                        break;
                    }
                }
            }
            /*here m_idx point to the corresponding multiProgram function */
        }
        dbg_ASSERT(writingLen <= PageLength);
        dbg_ASSERT(mtd_fp != NULL);
        //writingLen = writingLen < 16 ? writingLen : 16; /*limited by MTD return*/
        /* Fill Mtd_para*/
        Mtd_para.buff = &Data[(writenLen*Flash_Info.pageSize)];
        Mtd_para.spare = &Spare[0];
        Mtd_para.m_idx = m_idx;
        Mtd_para.length = writingLen;
        if (mtd_fp == MTD_CacheProgram || mtd_fp == MTD_CE_Interleave_CacheProgram)
        {   /*cache program case*/
            for ( i = 0; i < Flash_Info.bankNum; i++)
            {
                if (Acc_Type == RAW_ACC) {
			    	kal_uint32 ZoneLen;

				    ZoneLen = (Flash_Info.CE_interleave_Flag == KAL_FALSE) ? zonePage(0) : zonePage(0) + zonePage(1);
			 	    Mtd_para.pageIdx[i] = ((ZoneNo*ZoneLen) + (Bank[0]*Flash_Info.bankNum))*Flash_Info.blockPage + PageAddr + i;
			 	    Mtd_para.ce = 0;
			    } else {
	                Add_Cnvt.pageIdx = PageAddr+i;
	                addressMap(&Add_Cnvt);
	                Mtd_para.pageIdx[i] = Add_Cnvt.phyPage;
	                Mtd_para.ce = Add_Cnvt.ce;
			    }
                if (Flash_Info.deviceInfo_CE[Add_Cnvt.ce].deviceSize*1024*1024 <= Flash_Info.pageSize*Add_Cnvt.phyPage)
                {
                    dbg_ASSERT (0);
                    #if defined(__DEMAND_PAGING__) && !defined(__FUE__) && !defined(__UBL__)
				    if (Acc_Type == FAT_ACC) {
	                    demp_unlock_pages(DEMP_LOCK_NAND, (kal_uint32)Data, LockLength);
				    }
                    #endif                    
                    free_MTD_lock();                    
                    return MTD_STATUS_PARA_ERROR;
                }
            }
        }
        else
        {   /*! cache program case*/
            dbg_ASSERT(writingLen <= MAX_MULTIPAGE_NUM);
            for ( i = 0; i < writingLen; i++)
            {
                if (Acc_Type == RAW_ACC) {
			    	kal_uint32 ZoneLen;

				    ZoneLen = (Flash_Info.CE_interleave_Flag == KAL_FALSE) ? zonePage(0) : zonePage(0) + zonePage(1);
			 	    Mtd_para.pageIdx[i] = ((ZoneNo*ZoneLen) + (Bank[0]*Flash_Info.bankNum)) * Flash_Info.blockPage + PageAddr + i;
			 	    Mtd_para.ce = 0;
			    } else {            
	                Add_Cnvt.pageIdx = PageAddr+i;
	                addressMap(&Add_Cnvt);
	                Mtd_para.pageIdx[i] = Add_Cnvt.phyPage;
	                Mtd_para.ce = Add_Cnvt.ce;
			    }
                if (Flash_Info.deviceInfo_CE[Add_Cnvt.ce].deviceSize*1024*1024 <= Flash_Info.pageSize*Add_Cnvt.phyPage)
                {
                    dbg_ASSERT (0);
                    #if defined(__DEMAND_PAGING__) && !defined(__FUE__) && !defined(__UBL__)
				    if (Acc_Type == FAT_ACC) {
	                    demp_unlock_pages(DEMP_LOCK_NAND, (kal_uint32 )Data, LockLength);
				    }
                    #endif                    
                    free_MTD_lock();
                    
                    return MTD_STATUS_PARA_ERROR;
                }
            }
        }
        #if defined DAL_VERIFICATION
        if (Fail_Bank != 0xFF)
        {   /*test case*/
            if (Fail_Bank >=PageAddr && Fail_Bank<(PageAddr+writingLen) )
                Mtd_Fail_Offset = Fail_Bank - PageAddr;
        }
        #endif

        Mtd_para.opFlag |= ONE_SPARE;
        /*call MTD function*/
        retVal = mtd_fp(&Mtd_para);
#if ( defined(__NAND_FLASH_HARDWARE_TEST__) && defined(__MAUI_BASIC__) && !defined(__UBL__) )
		if ((PFTrigger==KAL_TRUE) && (PFTestCase & PF_DAL_TRIGGER)) {
			kal_uint8 Index, Count;

			PFTrigger = KAL_FALSE;
			for (Index=0; Index<writingLen; Index++) {
				Count=0;
				while (1) {
					if (ProgBadAddr[Count].Zone==0xff) {
						break;
					}
					if ( (ZoneNo==ProgBadAddr[Count].Zone) && 
						 ((Add_Cnvt.bankArry[(PageAddr+Index) % Flash_Info.bankNum]&(~BBM_GLOBAL_ADDR))==ProgBadAddr[Count].Block) &&
						 ((ProgBadAddr[Count].Page==0xffff) || (Add_Cnvt.pageIdx==ProgBadAddr[Count].Page)) ) 
					{
						retVal |= (0x01 << ((PageAddr+Index) % Flash_Info.bankNum));
            if(PF_EF_AutoTest== KAL_TRUE)
            {
              nandlog_print("Program Before PFTestCase:0x%X Block:0x%X Page:0x%X\r\n",PFTestCase,ProgBadAddr[Count].Block,Add_Cnvt.pageIdx );
              
              PFTestCase &=(~PFTrigerByTestCase);
              nandlog_print("Program After PFTestCase:0x%X Block:0x%X Page:0x%X\r\n",PFTestCase,ProgBadAddr[Count].Block,Add_Cnvt.pageIdx );
              
            }
					}
					Count++;
				}

			}
		}
#endif

        #if defined DAL_VERIFICATION
        if (Fail_Bank != 0xFF)
        {   /*test case*/
            if (Fail_Bank >=PageAddr && Fail_Bank<(PageAddr+writingLen) )
                Mtd_Fail_Offset = 0xFF; /*Reset*/
        }
        #endif
        if ( retVal != MTD_STATUS_NO_ERROR)
        {
            retVal = (retVal&0xFFFF0000)|((retVal&0x0000FFFF)<<(PageAddr%Flash_Info.bankNum));
            break;
        }
        /*set PageAddr & PageLength*/
        PageAddr += writingLen;
        writenLen += writingLen;
        PageLength -= writingLen;
    }
    #if defined(__DEMAND_PAGING__) && !defined(__FUE__) && !defined(__UBL__)
    if (Acc_Type == FAT_ACC) {
	    demp_unlock_pages(DEMP_LOCK_NAND, (kal_uint32 )Data, LockLength);
    }
    #endif    
    free_MTD_lock();    
    return retVal;
}


/****************************************************************************
 * Function:
 *
 * Parameters:  Spare - spare buffer, it will put all the spare data of the page
 *
 * Returns:     Low 2 byte: error code
 *              High 2 byte: error Page
 * Description:
 *
 ****************************************************************************/
kal_int32 DAL_ReadPage_internal(DAL_ACC_Type Acc_Type, kal_uint8 ZoneNo, kal_uint16 *Bank, kal_uint16 PageAddr, kal_uint16 PageLength, kal_uint8 *Data, kal_uint8 *Spare)
{
    //kal_uint8  m_idx = 0;
    //kal_uint8  bk_idx_ce;
    //kal_uint8  ce_idx = 0;
    kal_uint16  readingLen,Done_Len, i;
    kal_uint32 (*mtd_fp) (mtd_if_para*);
    kal_uint32 retVal = MTD_STATUS_NO_ERROR, mtd_retVal;

    get_MTD_lock();
    #if defined (_NAND_FLASH_BOOTING_) || defined(__NANDFDM_MULTI_INSTANCE__) || (defined(__UP_PKG_ON_NAND__) && defined(NAND_SUPPORT))
    if (Acc_Type == FAT_ACC)
    {
        for (i=0;i< Flash_Info.bankNum; i++)
        {
#if defined(__NANDFDM_TOTAL_BBM__)
          if(Bank[i]&BBM_GLOBAL_ADDR)
          {
            DAL_Bank_Array[i] = Bank[i];
          }
          else
#endif //#if defined(__NANDFDM_TOTAL_BBM__)
	        if (ZoneNo == 0)
	        {
#if !defined(__NANDFDM_MULTI_INSTANCE__)
                DAL_Bank_Array[i] = Bank[i] + FAT_Start_Section_Offset;
#else // !defined(__NANDFDM_MULTI_INSTANCE__)
                DAL_Bank_Array[i] = Bank[i] + FAT_Start_Section_Offset[CurDiskIndex];
#endif // !defined(__NANDFDM_MULTI_INSTANCE__)
	        } else {
                DAL_Bank_Array[i] = Bank[i];
	        }
        }
        Bank = DAL_Bank_Array;
#if !defined(__NANDFDM_MULTI_INSTANCE__)
        ZoneNo += FAT_Start_ZoneNum;
#else  // !defined(__NANDFDM_MULTI_INSTANCE__)
        ZoneNo += FAT_Start_ZoneNum[CurDiskIndex];
#endif	// !defined(__NANDFDM_MULTI_INSTANCE__)
    }
    #else
    if (Acc_Type != FAT_ACC)
    {
        dbg_ASSERT(0);
        free_MTD_lock();
        return MTD_STATUS_PARA_ERROR;
    }
    #endif /* _NAND_FLASH_BOOTING_ || defined(__NANDFDM_MULTI_INSTANCE__) || (__UP_PKG_ON_NAND__ && NAND_SUPPORT)) */
    /*boundary check*/
    if ( (ZoneNo >= Flash_Info.zoneNum) || ( PageAddr+PageLength > Flash_Info.bankNum*Flash_Info.blockPage ) )
    {
    	  force_ASSERT(0,ZoneNo,(PageAddr+PageLength),0);
        free_MTD_lock();
        return MTD_STATUS_PARA_ERROR;
    }

    Done_Len = 0;
    kal_mem_set(&Mtd_para, 0x00,sizeof(Mtd_para));
    Add_Cnvt.zoneNum = ZoneNo ;
    Add_Cnvt.bankArry = Bank;
    while ( PageLength )
    {
        /*Get the mtd_fp, m_idx & readingLen*/
        readingLen = 1;
        mtd_fp = MTD_Read;
        /* Fill Mtd_para*/
        Mtd_para.buff = &Data[(Done_Len*Flash_Info.pageSize)];
        if (Spare==NULL) {

        	Mtd_para.spare = NULL;
        } else {
	        Mtd_para.spare = &Spare[(Done_Len*Flash_Info.spareSize)];
        }
        Mtd_para.length = readingLen;
        for ( i = 0; i < readingLen; i++)
        {
            Add_Cnvt.pageIdx = PageAddr+i;
            addressMap(&Add_Cnvt);
            Mtd_para.pageIdx[i] = Add_Cnvt.phyPage;
            Mtd_para.ce = Add_Cnvt.ce;
            #if 0 /*bootloader test*/
/* under construction !*/
/* under construction !*/
            #endif
            if (Flash_Info.deviceInfo_CE[Add_Cnvt.ce].deviceSize*1024*1024 <= Flash_Info.pageSize*Add_Cnvt.phyPage)
            {
                dbg_ASSERT (0);
                free_MTD_lock();
                return MTD_STATUS_PARA_ERROR;
            }
        }
        #if defined DAL_VERIFICATION
        if (Fail_Bank != 0xFF)
        {   /*test case*/
            if (Fail_Bank >=PageAddr && Fail_Bank<(PageAddr+readingLen) )
                Mtd_Fail_Offset = Fail_Bank - PageAddr;
        }
        #endif
        /*call MTD function*/

        mtd_retVal = mtd_fp(&Mtd_para);
        #if defined DAL_VERIFICATION
        if (Fail_Bank != 0xFF)
        {   /*test case*/
            if (Fail_Bank >=PageAddr && Fail_Bank<(PageAddr+readingLen) )
                Mtd_Fail_Offset = 0xFF; /*Reset*/
        }
        #endif
        if ( mtd_retVal != MTD_STATUS_NO_ERROR)
        {
            retVal |= (mtd_retVal&0xFFFF0000)|((mtd_retVal&0x0000FFFF)<<(PageAddr%Flash_Info.bankNum));
            //break;/*Do not stop even read error*/
        }
        /*set PageAddr & PageLength*/
        PageAddr += readingLen;
        Done_Len += readingLen;
        PageLength -= readingLen;
    }
    free_MTD_lock();
    return retVal;
}

//if read fail, retry twice
kal_int32 DAL_ReadPage(DAL_ACC_Type Acc_Type, kal_uint8 ZoneNo, kal_uint16 *Bank, kal_uint16 PageAddr, kal_uint16 PageLength, kal_uint8 *Data, kal_uint8 *Spare)
{
	kal_uint32 retVal = MTD_STATUS_NO_ERROR;
	kal_uint32 trycount = 0;


	retVal = DAL_ReadPage_internal(Acc_Type, ZoneNo, Bank, PageAddr, PageLength, Data, Spare);
	if ((retVal & 0xffff0000) == MTD_STATUS_ERROR)
	{
DAL_ReadPage_Retry_R:	
		trycount++;		
		#if ( defined(__NAND_FLASH_HARDWARE_TEST__) && defined(__MAUI_BASIC__) && !defined(__UBL__))
			nandlog_print("DAL_ReadPage Retry %d time\r\n", trycount);
			
		#endif
		if ((DAL_ReadPage_internal(Acc_Type, ZoneNo, Bank, PageAddr, PageLength, Data, Spare)& 0xffff0000) == MTD_STATUS_ERROR)
		{
			if (trycount < 3)
			{
				goto DAL_ReadPage_Retry_R;
			}					
		}				
	}
	//return first time read return value, even second time read succeed.
	//when first time read fail, caller will know this page is risky.
	return retVal;
}
/****************************************************************************
 * Function:    DAL_CopyPage
 *
 * Parameters:  kal_uint8 ZoneNo     The Zone number
 *              kal_uint16 *srcBank  The copy source bank array
 *              kal_uint16 *dstBank  The copy source bank array
 *              kal_uint16 PageLength The desired copy length (unit by page)
 *              kal_uint8 *Data_buff   copy function Working buffer
 *              kal_uint8 *Spare_buff  copy function Working buffer
 *              kal_uint32 buff_len  Working buffer length, unit by page
 *              kal_uint8  SDataNumber - The number of Upper layer sending Data in Spare_buff,
 *                                      if >= 1 means dst spare should be assigned with data in Spare_buff
 * Returns:     Low 2 byte: error code
 *              High 2 byte: error Page
 * Description: [Important Note]: If PageLength > 1 The source pages should have the same spare content!
 *
 ****************************************************************************/
kal_int32 DAL_CopyPage(DAL_ACC_Type Acc_Type, kal_uint8 ZoneNo, kal_uint16 *srcBank, kal_uint16 *dstBank, kal_uint16 srcPageAddr, kal_uint16 dstPageAddr, kal_uint16 PageLength, kal_uint8 *Data_buff, kal_uint8 *Spare_buff, kal_uint32 buff_len, kal_uint8 SDataNumber)
{
    kal_bool   fgNeedCheckBound = KAL_TRUE;
    kal_uint8  m_idx = 0;
    kal_uint8  bk_idx_ce;
    kal_uint8  ce_idx = 0;
    kal_uint8  bCurrZone;
    kal_uint16 writingLen, i;
    kal_uint16 *pCurrSrcBank,*pCurrDstBank;

    kal_uint32 (*mtd_program_fp) (mtd_if_para*);
    kal_uint32 retVal= MTD_STATUS_NO_ERROR, mtd_retVal;
    bCurrZone = ZoneNo;
    pCurrSrcBank = srcBank;
    pCurrDstBank = dstBank;
    writingLen = 0;
    while ( PageLength )
    {
        get_MTD_lock();
        #if defined (_NAND_FLASH_BOOTING_) || defined(__NANDFDM_MULTI_INSTANCE__) || (defined(__UP_PKG_ON_NAND__) && defined(NAND_SUPPORT))
        if (Acc_Type == FAT_ACC)
        {
            for (i=0;i< Flash_Info.bankNum; i++)
            {
#if (defined(__NANDFDM_TOTAL_BBM__) && defined(__NANDFDM_MULTI_INSTANCE__))
              if(srcBank[i]&BBM_GLOBAL_ADDR)
              {
                DAL_Bank_Array[i] = srcBank[i];
              }
              else
              {
                if (ZoneNo == 0)
                {
                  DAL_Bank_Array[i] = srcBank[i] + FAT_Start_Section_Offset[CurDiskIndex];
                }
                else
                {
                  DAL_Bank_Array[i] = srcBank[i];
                }
              }
              if(dstBank[i]&BBM_GLOBAL_ADDR)
              {
                DAL_Bank_Array2[i] = dstBank[i];
              }
              else
              {
                if (ZoneNo == 0)
                {
                  DAL_Bank_Array2[i] = dstBank[i] + FAT_Start_Section_Offset[CurDiskIndex];
                } else {
                  DAL_Bank_Array2[i] = dstBank[i];
                }
              }
#else
    	        if (ZoneNo == 0)
    	        {
#if !defined(__NANDFDM_MULTI_INSTANCE__)
                    DAL_Bank_Array[i] = srcBank[i] + FAT_Start_Section_Offset;
                    DAL_Bank_Array2[i] = dstBank[i] + FAT_Start_Section_Offset;
#else  // !defined(__NANDFDM_MULTI_INSTANCE__)
                    DAL_Bank_Array[i] = srcBank[i] + FAT_Start_Section_Offset[CurDiskIndex];
                    DAL_Bank_Array2[i] = dstBank[i] + FAT_Start_Section_Offset[CurDiskIndex];
#endif // !defined(__NANDFDM_MULTI_INSTANCE__)
    	        } else {
                    DAL_Bank_Array[i] = srcBank[i];
                    DAL_Bank_Array2[i] = dstBank[i];
    	        }
#endif //#if defined(__NANDFDM_TOTAL_BBM__)
            }
            pCurrSrcBank = DAL_Bank_Array;
            pCurrDstBank = DAL_Bank_Array2;
#if !defined(__NANDFDM_MULTI_INSTANCE__)
            bCurrZone = ZoneNo + FAT_Start_ZoneNum;
#else  // !defined(__NANDFDM_MULTI_INSTANCE__)
            bCurrZone = ZoneNo +  FAT_Start_ZoneNum[CurDiskIndex];
#endif // !defined(__NANDFDM_MULTI_INSTANCE__)
        }
        #else
        if (Acc_Type != FAT_ACC)
        {
            dbg_ASSERT(0);
            free_MTD_lock();
            return MTD_STATUS_PARA_ERROR;
        }
        #endif /* _NAND_FLASH_BOOTING || defined(__NANDFDM_MULTI_INSTANCE__) || (__UP_PKG_ON_NAND__ && NAND_SUPPORT)) */

        if(fgNeedCheckBound==KAL_TRUE)
        {
          fgNeedCheckBound = KAL_FALSE;
          /*parameter check*/
          if ( bCurrZone >= Flash_Info.zoneNum || srcPageAddr+PageLength > Flash_Info.bankNum*Flash_Info.blockPage ||
               dstPageAddr+PageLength > Flash_Info.bankNum*Flash_Info.blockPage ||
               (srcPageAddr%Flash_Info.bankNum) != (dstPageAddr%Flash_Info.bankNum) || SDataNumber >= Flash_Info.spareSize)
          {
              force_ASSERT(0,bCurrZone,(srcPageAddr+PageLength),0);
              free_MTD_lock();
              return MTD_STATUS_PARA_ERROR;
          }
        }
        if ( SDataNumber > 0)
        {
            kal_mem_set(DAL_spare_buff, 0xFF, Flash_Info.spareSize );
            kal_mem_cpy(DAL_spare_buff, Spare_buff, SDataNumber );
        }

        /*read + write method*/
        Add_Cnvt.zoneNum = bCurrZone ;

        /*Get the mtd_program_fp, m_idx & writingLen*/
        mtd_program_fp = NULL;
        if ( Flash_Info.CE_interleave_Flag == KAL_TRUE )
        {
            if ( (dstPageAddr % Flash_Info.bankNum) == 0)
            {
                if ( (PageLength < buff_len ? PageLength : buff_len) >= Flash_Info.bankNum*2 &&
                    Flash_Info.CE_cache_interleave_Flag == KAL_TRUE)
                {
                    writingLen = Flash_Info.bankNum * ( (PageLength < buff_len ? PageLength : buff_len) / Flash_Info.bankNum );
                    m_idx = Flash_Info.CE_cache_interleave_mOP_Idx[0];
                    mtd_program_fp = MTD_CE_Interleave_CacheProgram;
                }
                else if ( (PageLength < buff_len ? PageLength : buff_len) >= Flash_Info.bankNum )
                {
                    writingLen = Flash_Info.bankNum;
                    m_idx = Flash_Info.CE_interleave_mOP_Idx[0];
                    mtd_program_fp = MTD_CE_Interleave_Program;
                }
            }
        }
        if (mtd_program_fp == NULL)
        {
            Add_Cnvt.pageIdx = dstPageAddr;
            Add_Cnvt.bankArry = pCurrDstBank;
            addressMap(&Add_Cnvt);
            ce_idx = Add_Cnvt.ce;
            bk_idx_ce = dstPageAddr%Flash_Info.bankNum;
            if ( Flash_Info.CE_interleave_Flag == KAL_TRUE && ce_idx == 1)
            {
                bk_idx_ce -= Flash_Info.bank_CE[0];
            }
            for (m_idx=0; m_idx< MAX_MULTIPAGE_FUNCTION_NUM; m_idx++)
            {
                if ( Flash_Info.multiProgram[ce_idx][m_idx].func_p != NULL
                     && ((bk_idx_ce%Flash_Info.multiProgram[ce_idx][m_idx].startAlign) ==0) )
                {   /*cache program check*/
                    if ( Flash_Info.multiProgram[ce_idx][m_idx].multiPageNum == 0xFF
                         && ( (PageLength < buff_len ? PageLength : buff_len) >= Flash_Info.multiProgram[ce_idx][m_idx].startAlign*2)
                         && Flash_Info.CE_interleave_Flag == KAL_FALSE )
                    {
                        writingLen = (Flash_Info.multiProgram[ce_idx][m_idx].startAlign)*((PageLength < buff_len ? PageLength : buff_len)/(Flash_Info.multiProgram[ce_idx][m_idx].startAlign));
                        mtd_program_fp = MTD_CacheProgram;
                        break;
                    }
                    else if ( (PageLength < buff_len ? PageLength : buff_len) >= Flash_Info.multiProgram[ce_idx][m_idx].multiPageNum)
                    {
                        writingLen = (Flash_Info.multiProgram[ce_idx][m_idx].multiPageNum);
                        mtd_program_fp = MTD_Program;
                        break;
                    }
                }
            }
            /*here m_idx point to the corresponding multiProgram function */
        }
        dbg_ASSERT(writingLen <= PageLength);
        dbg_ASSERT(mtd_program_fp != NULL);
        /*here get all information to process multi-page write, now read data out*/
        /* Fill Mtd_para*/
        kal_mem_set(&Mtd_para, 0x00,sizeof(Mtd_para));
        Mtd_para.length = 1; /*single read only*/
        Add_Cnvt.bankArry = pCurrSrcBank;
        for ( i = 0; i < writingLen; i++)
        {
            Add_Cnvt.pageIdx = srcPageAddr+i;
            addressMap(&Add_Cnvt);
            Mtd_para.pageIdx[0] = Add_Cnvt.phyPage;
            Mtd_para.ce = Add_Cnvt.ce;
            Mtd_para.buff = &Data_buff[ i*Flash_Info.pageSize ];
      			if (SDataNumber>0) {
	            Mtd_para.spare = &Spare_buff[0];
      			} else {
	            Mtd_para.spare = &Spare_buff[ i*Flash_Info.spareSize ];
		      	}
            if (Flash_Info.deviceInfo_CE[Add_Cnvt.ce].deviceSize*1024*1024 <= Flash_Info.pageSize*Add_Cnvt.phyPage)
            {
                dbg_ASSERT (0);
                free_MTD_lock();
                return MTD_STATUS_PARA_ERROR;
            }
            /*call MTD_Read function*/
            mtd_retVal = MTD_Read(&Mtd_para);
            if ( (mtd_retVal & 0xffff0000) == MTD_STATUS_ERROR)
            {
            	kal_uint8 try_count = 0;
DAL_COPY_PAGE_RETRY:				
            	//re-try to read the same page when read fail.
            	if (try_count < 3)
            	{
				#if ( defined(__NAND_FLASH_HARDWARE_TEST__) && defined(__MAUI_BASIC__) && !defined(__UBL__))            	
            		nandlog_print("DAL_CopyPage Retry %d time\r\n", try_count);
					
				#endif
	            	mtd_retVal = MTD_Read(&Mtd_para);
					if ( (mtd_retVal & 0xffff0000) == MTD_STATUS_ERROR)
					{
						try_count++;
						goto DAL_COPY_PAGE_RETRY;
						
					}
            	}			
            }
			//if ( mtd_retVal != MTD_STATUS_NO_ERROR)
        	//{
                //retVal |= (mtd_retVal&0xFFFF0000)|((mtd_retVal&0x0000FFFF)<<((srcPageAddr+i)%Flash_Info.bankNum));
                //break;/*Do not stop even read error*/
            //}
        }
        /*Now process the write part*/
        /* Fill Mtd_para*/
        kal_mem_set(&Mtd_para, 0x00,sizeof(Mtd_para));
        Mtd_para.buff = Data_buff;
        Mtd_para.spare = (SDataNumber > 0 ? (kal_uint8*)DAL_spare_buff : Spare_buff);
        Mtd_para.m_idx = m_idx;
        Mtd_para.length = writingLen;

        Add_Cnvt.bankArry = pCurrDstBank;
        for ( i = 0; i < writingLen; i++)
        {
            Add_Cnvt.pageIdx = dstPageAddr+i;
            addressMap(&Add_Cnvt);
            Mtd_para.pageIdx[i] = Add_Cnvt.phyPage;
            Mtd_para.ce = Add_Cnvt.ce;
            if (Flash_Info.deviceInfo_CE[Add_Cnvt.ce].deviceSize*1024*1024 <= Flash_Info.pageSize*Add_Cnvt.phyPage)
            {
                dbg_ASSERT (0);
                free_MTD_lock();
                return MTD_STATUS_PARA_ERROR;
            }
        }
        #if defined DAL_VERIFICATION
        if (Fail_Bank != 0xFF)
        {   /*test case*/
            if (Fail_Bank >=srcPageAddr && Fail_Bank<(srcPageAddr+writingLen) )
                Mtd_Fail_Offset = Fail_Bank - srcPageAddr;
        }
        #endif
        /*call MTD function*/
        if (SDataNumber>0) {
	        Mtd_para.opFlag |= ONE_SPARE;
        } else {
	        Mtd_para.opFlag &= (~ONE_SPARE);
        }

        mtd_retVal = mtd_program_fp(&Mtd_para);
#if ( defined(__NAND_FLASH_HARDWARE_TEST__) && defined(__MAUI_BASIC__) && !defined(__UBL__))
		if ((PFTrigger==KAL_TRUE) && (PFTestCase & PF_DAL_TRIGGER)) {
			kal_uint8 Index, Count;

			PFTrigger = KAL_FALSE;
			for (Index=0; Index<writingLen; Index++) {
				Count=0;
				while (1) {
					if (ProgBadAddr[Count].Zone==0xff) {
						break;
					}
					if ( (bCurrZone==ProgBadAddr[Count].Zone) &&
						 ((Add_Cnvt.bankArry[(dstPageAddr+Index) % Flash_Info.bankNum]&(~BBM_GLOBAL_ADDR))==ProgBadAddr[Count].Block) &&
						 ((ProgBadAddr[Count].Page==0xffff) || (Add_Cnvt.pageIdx==ProgBadAddr[Count].Page)) )
					{
						retVal |= (0x01 << ((dstPageAddr+Index) % Flash_Info.bankNum));
            if(PF_EF_AutoTest== KAL_TRUE)
            {
              nandlog_print("Copy Before PFTestCase:0x%X Block:0x%X Page:0x%X\r\n",PFTestCase,ProgBadAddr[Count].Block,Add_Cnvt.pageIdx );
              
              PFTestCase &=(~PFTrigerByTestCase);
              nandlog_print("Copy After PFTestCase:0x%X Block:0x%X Page:0x%X\r\n",PFTestCase,ProgBadAddr[Count].Block,Add_Cnvt.pageIdx );
              

            }
					}
					Count++;
				}

			}
		}
#endif
        #if defined DAL_VERIFICATION
        if (Fail_Bank != 0xFF)
        {   /*test case*/
            if (Fail_Bank >=srcPageAddr && Fail_Bank<(srcPageAddr+writingLen) )
                Mtd_Fail_Offset = 0xFF; /*Reset*/
        }
        #endif
        if ( mtd_retVal != MTD_STATUS_NO_ERROR)
        {
            retVal |= (mtd_retVal&0xFFFF0000)|((mtd_retVal&0x0000FFFF)<<(dstPageAddr%Flash_Info.bankNum));
            break;
        }
        /*set PageAddr & PageLength*/
        srcPageAddr += writingLen;
        dstPageAddr += writingLen;
        PageLength -= writingLen;
        free_MTD_lock();
    }

    return retVal;
}

/****************************************************************************
 * Function:
 *
 * Parameters:
 *
 * Returns:     Low 2 byte: error code
 *              High 2 byte: error Page
 * Description:
 *
 ****************************************************************************/
kal_int32 DAL_EraseBlock(DAL_ACC_Type Acc_Type, kal_uint8 ZoneNo, kal_uint16 *Bank,kal_uint8 start, kal_uint8 length)
{
    kal_uint8  m_idx = 0;
    kal_uint8  bk_idx_ce;
    kal_uint8  ce_idx = 0;
    kal_uint8  erasingLen, i;
    kal_uint32 (*mtd_fp) (mtd_if_para*);
    kal_uint32 retVal = MTD_STATUS_NO_ERROR;

    get_MTD_lock();
    #if defined (_NAND_FLASH_BOOTING_) || defined(__NANDFDM_MULTI_INSTANCE__) || (defined(__UP_PKG_ON_NAND__) && defined(NAND_SUPPORT))
    if (Acc_Type == FAT_ACC)
    {
        for (i=0;i< Flash_Info.bankNum; i++)
        {
#if defined(__NANDFDM_TOTAL_BBM__)
          if(Bank[i]&BBM_GLOBAL_ADDR)
          {
            DAL_Bank_Array[i] = Bank[i];
          }
          else
#endif //#if defined(__NANDFDM_TOTAL_BBM__)
	        if (ZoneNo == 0)
	        {
#if !defined(__NANDFDM_MULTI_INSTANCE__)
                DAL_Bank_Array[i] = Bank[i] + FAT_Start_Section_Offset;
#else // !defined(__NANDFDM_MULTI_INSTANCE__)
                DAL_Bank_Array[i] = Bank[i] + FAT_Start_Section_Offset[CurDiskIndex];
#endif //!defined(__NANDFDM_MULTI_INSTANCE__)
	        } else {
                DAL_Bank_Array[i] = Bank[i];
	        }
        }
        Bank = DAL_Bank_Array;
#if !defined(__NANDFDM_MULTI_INSTANCE__)
        ZoneNo += FAT_Start_ZoneNum;
#else // !defined(__NANDFDM_MULTI_INSTANCE__)
        ZoneNo += FAT_Start_ZoneNum[CurDiskIndex];
#endif //!defined(__NANDFDM_MULTI_INSTANCE__)
    }
    #else
    if (Acc_Type != FAT_ACC)
    {
        dbg_ASSERT(0);
        free_MTD_lock();
        return MTD_STATUS_PARA_ERROR;
    }
    #endif /* _NAND_FLASH_BOOTING_ || defined(__NANDFDM_MULTI_INSTANCE__) || (__UP_PKG_ON_NAND__ && NAND_SUPPORT)) */
    /*boundary check*/
    if ( ZoneNo >= Flash_Info.zoneNum || start+length > Flash_Info.bankNum )
    {
        force_ASSERT(0,ZoneNo,0,0);
        free_MTD_lock();
        return MTD_STATUS_PARA_ERROR;
    }

    kal_mem_set(&Mtd_para, 0x00,sizeof(Mtd_para));
    Add_Cnvt.zoneNum = ZoneNo ;
    Add_Cnvt.bankArry = Bank;
    while ( length )
    {
        /*Get the mtd_fp, m_idx & erasingLen*/
        mtd_fp = NULL;
        erasingLen = 0;
        Add_Cnvt.pageIdx = start;
        addressMap(&Add_Cnvt);
        ce_idx = Add_Cnvt.ce;
        bk_idx_ce = start%Flash_Info.bankNum;
        if ( Flash_Info.CE_interleave_Flag == KAL_TRUE && ce_idx == 1)
        {
            bk_idx_ce -= Flash_Info.bank_CE[0];
        }
        for (m_idx=0; m_idx< MAX_MULTIPAGE_FUNCTION_NUM; m_idx++)
        {
            if ( Flash_Info.multiErase[ce_idx][m_idx].func_p != NULL
                 && ((bk_idx_ce%Flash_Info.multiErase[ce_idx][m_idx].startAlign) ==0)
                 && length >= Flash_Info.multiErase[ce_idx][m_idx].multiPageNum )
            {
                erasingLen = (Flash_Info.multiErase[ce_idx][m_idx].multiPageNum);
                mtd_fp = MTD_Erase;
                break;
            }
        }
        /*here m_idx point to the corresponding multiErase function */
        dbg_ASSERT(erasingLen < MAX_MULTIPAGE_NUM);
        dbg_ASSERT(erasingLen <= length);
        dbg_ASSERT(mtd_fp != NULL);
        /* Fill Mtd_para*/
        Mtd_para.buff = NULL;
        Mtd_para.spare = NULL;
        Mtd_para.m_idx = m_idx;
        Mtd_para.length = erasingLen;
        for ( i = 0; i < erasingLen; i++)
        {
            if (Acc_Type == RAW_ACC) {
		    	kal_uint32 ZoneLen;

			    ZoneLen = (Flash_Info.CE_interleave_Flag == KAL_FALSE) ? zonePage(0) : zonePage(0) + zonePage(1);
		 	    Mtd_para.pageIdx[i] = ((ZoneNo*ZoneLen) + (Bank[0]*Flash_Info.bankNum) + start + i)* Flash_Info.blockPage;
		 	    Mtd_para.ce = 0;
		    } else {
	            Add_Cnvt.pageIdx = start + i; /*first page of block*/
	            addressMap(&Add_Cnvt);
	            Mtd_para.pageIdx[i] = Add_Cnvt.phyPage;
	            Mtd_para.ce = Add_Cnvt.ce;
		    }
            if (Flash_Info.deviceInfo_CE[Add_Cnvt.ce].deviceSize*1024*1024 <= Flash_Info.pageSize*Add_Cnvt.phyPage)
            {
                dbg_ASSERT (0);
                free_MTD_lock();
                return MTD_STATUS_PARA_ERROR;
            }
        }
        #if defined DAL_VERIFICATION
        if (Fail_Bank != 0xFF)
        {   /*test case*/
            if (Fail_Bank >=start && Fail_Bank<(start+erasingLen) )
                Mtd_Fail_Offset = Fail_Bank - start;
        }
        #endif
        /*call MTD function*/
        retVal = mtd_fp(&Mtd_para);
        #if defined DAL_VERIFICATION
        if (Fail_Bank != 0xFF)
        {   /*test case*/
            if (Fail_Bank >=start && Fail_Bank<(start+erasingLen) )
                Mtd_Fail_Offset = 0xFF; /*Reset*/
        }
        #endif
#if ( defined(__NAND_FLASH_HARDWARE_TEST__) && defined(__MAUI_BASIC__) && !defined(__UBL__))
		if ((EFTrigger==KAL_TRUE) && (EFTestCase & EF_DAL_TRIGGER)) {
			kal_uint8 Index, Count;

			EFTrigger = KAL_FALSE;
			for (Index=0; Index<erasingLen; Index++) {
				Count=0;
				while (1) {
					if (EraseBadAddr[Count].Zone==0xff) {
						break;
					}
					if ( (ZoneNo==EraseBadAddr[Count].Zone) &&
						 ((Add_Cnvt.bankArry[start+Index]&(~BBM_GLOBAL_ADDR))==EraseBadAddr[Count].Block) &&
						 ((start+Index)==EraseBadAddr[Count].Bank) )
					{
						retVal |= (0x01 << (start+Index));
            if(PF_EF_AutoTest==KAL_TRUE)
            {
              nandlog_print("Before EFTestCase:0x%X \r\n",EFTestCase);
              
              EFTestCase &=(~EFTrigerByTestCase);
              nandlog_print("After EFTestCase:0x%X \r\n",EFTestCase);
              

            }
					}
					Count++;
				}

			}
		}
#endif

        if ( retVal != MTD_STATUS_NO_ERROR)
        {
            retVal = (retVal&0xFFFF0000)|((retVal&0x0000FFFF)<<start);
            break;
        }
        start += erasingLen;
        length -= erasingLen;
    }
    free_MTD_lock();
    return retVal;
}

/****************************************************************************
 * Function:
 *
 * Parameters:
 *
 * Returns:
 *
 * Description:
 *
 ****************************************************************************/
kal_int32 DAL_MarkBlockBad(DAL_ACC_Type Acc_Type, kal_uint8 ZoneNo, kal_uint16 *Bank,kal_uint8 Block_offset, kal_bool EraseBlock, kal_uint32 *Data_buff, kal_uint32 *Spare_buff)
{
    kal_uint8  m_idx = 0;
    kal_uint8  ce_idx = 0;
   	kal_uint32 ZoneLen = 0;

    get_MTD_lock();
    #if defined (_NAND_FLASH_BOOTING_) || defined(__NANDFDM_MULTI_INSTANCE__) || (defined(__UP_PKG_ON_NAND__) && defined(NAND_SUPPORT))
    if (Acc_Type == FAT_ACC)
    {
	    kal_uint8  i;
        for (i=0;i< Flash_Info.bankNum; i++)
        {
#if defined(__NANDFDM_TOTAL_BBM__)
          if(Bank[i]&BBM_GLOBAL_ADDR)
          {
            DAL_Bank_Array[i] = Bank[i];
          }
          else
#endif //#if defined(__NANDFDM_TOTAL_BBM__)
	        if (ZoneNo == 0)
	        {
#if !defined(__NANDFDM_MULTI_INSTANCE__)
                DAL_Bank_Array[i] = Bank[i] + FAT_Start_Section_Offset;
#else // !defined(__NANDFDM_MULTI_INSTANCE__)
                DAL_Bank_Array[i] = Bank[i] + FAT_Start_Section_Offset[CurDiskIndex];
#endif //!defined(__NANDFDM_MULTI_INSTANCE__)
	        } else {
                DAL_Bank_Array[i] = Bank[i];
	        }
        }
        Bank = DAL_Bank_Array;
#if !defined(__NANDFDM_MULTI_INSTANCE__)
        ZoneNo += FAT_Start_ZoneNum;
#else // !defined(__NANDFDM_MULTI_INSTANCE__)
        ZoneNo += FAT_Start_ZoneNum[CurDiskIndex];
#endif //!defined(__NANDFDM_MULTI_INSTANCE__)
    }
    #else
    if (Acc_Type != FAT_ACC)
    {
        dbg_ASSERT(0);
        free_MTD_lock();
        return MTD_STATUS_PARA_ERROR;
    }
    #endif /* _NAND_FLASH_BOOTING || defined(__NANDFDM_MULTI_INSTANCE__) || (__UP_PKG_ON_NAND__ && NAND_SUPPORT)) */
    /*boundary check*/
    if ( ZoneNo >= Flash_Info.zoneNum || Block_offset >= Flash_Info.bankNum )
    {
        force_ASSERT(0,ZoneNo,0,0);
        free_MTD_lock();
        return MTD_STATUS_PARA_ERROR;
    }

    if (Acc_Type == RAW_ACC) {
	    ZoneLen = (Flash_Info.CE_interleave_Flag == KAL_FALSE) ? zonePage(0) : zonePage(0) + zonePage(1);
    }
    kal_mem_set(&Mtd_para, 0x00,sizeof(Mtd_para));
    Add_Cnvt.zoneNum = ZoneNo ;
    Add_Cnvt.bankArry = Bank;
    Add_Cnvt.pageIdx = Block_offset; /*first page of block*/
    addressMap(&Add_Cnvt);
    if (Flash_Info.deviceInfo_CE[Add_Cnvt.ce].deviceSize*1024*1024 <= Flash_Info.pageSize*Add_Cnvt.phyPage)
    {
        dbg_ASSERT (0);
        free_MTD_lock();
        return MTD_STATUS_PARA_ERROR;
    }
    if (EraseBlock == KAL_TRUE)
    {
        ce_idx = Add_Cnvt.ce;
        for (m_idx=0; m_idx< MAX_MULTIPAGE_FUNCTION_NUM; m_idx++)
        {
            if ( 1 == Flash_Info.multiErase[ce_idx][m_idx].multiPageNum
                 && Flash_Info.multiErase[ce_idx][m_idx].func_p != NULL)
                break;
        }
        dbg_ASSERT( m_idx != MAX_MULTIPAGE_FUNCTION_NUM );
        /* Fill Mtd_para*/
        Mtd_para.buff = NULL;
        Mtd_para.spare = NULL;
        Mtd_para.m_idx = m_idx;
        Mtd_para.length = 1;
	    if (Acc_Type == RAW_ACC) {
	 	    Mtd_para.pageIdx[0] = ((ZoneNo*ZoneLen) + (Bank[0]*Flash_Info.bankNum) + Block_offset) * Flash_Info.blockPage;
	 	    Mtd_para.ce = 0;

	    } else {
        Mtd_para.pageIdx[0] = Add_Cnvt.phyPage;
        Mtd_para.ce = Add_Cnvt.ce;

	    }
        MTD_Erase(&Mtd_para);
    }
    /*Read the target page back*/
    /* Fill Mtd_para*/
    kal_mem_set(&Mtd_para, 0x00,sizeof(Mtd_para));
    Mtd_para.length = 1; /*single read only*/
    Mtd_para.m_idx = 0; /*No use*/
    if (Acc_Type == RAW_ACC) {
 	    Mtd_para.pageIdx[0] = ((ZoneNo*ZoneLen) + (Bank[0]*Flash_Info.bankNum) + Block_offset) * Flash_Info.blockPage;
 	    Mtd_para.ce = 0;

    } else {
    Mtd_para.pageIdx[0] = Add_Cnvt.phyPage;
    Mtd_para.ce = Add_Cnvt.ce;
 	}
    Mtd_para.buff = (kal_uint8*)&Data_buff[0];
    Mtd_para.spare = (kal_uint8*)&Spare_buff[0];
    MTD_Read(&Mtd_para);

    //kal_mem_set(Data_buff, 0xFF, sizeof(Flash_Info.pageSize));
    //kal_mem_set(Spare_buff, 0xFF, sizeof(Flash_Info.spareSize));

    if (Flash_Info.pageSize == 512)
    {
        ((FDMData_512*)Spare_buff) -> BI &= FDM_BAD_BLOCK_MARK_512; /*use &= to adapte the original mark, ex: 0x00(early bad)*/
    }
    else
    {
        ((FDMData_2k*)Spare_buff) -> BI &= FDM_BAD_BLOCK_MARK_2K;  /*use &= to adapte the original mark, ex: 0x00(early bad)*/
    }

    /* Fill Mtd_para*/
    Mtd_para.buff = (kal_uint8*)Data_buff;
    Mtd_para.spare =(kal_uint8*) Spare_buff;
    Mtd_para.m_idx = 0; /*No use*/
    Mtd_para.length = 1; /*No use*/
    if (Acc_Type == RAW_ACC) {
 	    Mtd_para.pageIdx[0] = ((ZoneNo*ZoneLen) + (Bank[0]*Flash_Info.bankNum) + Block_offset) * Flash_Info.blockPage;
 	    Mtd_para.ce = 0;

    } else {
    Mtd_para.pageIdx[0] = Add_Cnvt.phyPage;
    Mtd_para.ce = Add_Cnvt.ce;
	}
    MTD_MarkBlockBad(&Mtd_para);

    free_MTD_lock();
    return MTD_STATUS_NO_ERROR;
}

/****************************************************************************
 * Function:
 *
 * Parameters:   kal_bool newFlash This flag make condition to check: if BI != 0xFF_FF, it's early bad
 *
 * Returns:      MTD_STATUS_NO_ERROR - The block is a good block
 *               MTD_STATUS_EARLY_BAD - The block is a bad block of early bad
 *               MTD_STATUS_FDM_BAD - The block is a bad block of FDM bad
 *               (MTD_STATUS_EARLY_BAD|MTD_STATUS_FDM_BAD)
 * Description:
 *
 ****************************************************************************/
kal_int32 DAL_CheckBadBlock (DAL_ACC_Type Acc_Type, kal_uint8 ZoneNo, kal_uint16 *Bank,kal_uint8 Block_offset, kal_bool newFlash, kal_uint32 *Data_buff, kal_uint32 *Spare_buff)
{
    kal_uint32 mtd_retVal, retVal = MTD_STATUS_NO_ERROR;
    kal_bool FirstCheck = KAL_TRUE;

    get_MTD_lock();
    #if defined (_NAND_FLASH_BOOTING_) || defined(__NANDFDM_MULTI_INSTANCE__) || (defined(__UP_PKG_ON_NAND__) && defined(NAND_SUPPORT))
    if (Acc_Type == FAT_ACC)
    {
	    kal_uint8 i;
        for (i=0;i< Flash_Info.bankNum; i++)
        {
#if defined(__NANDFDM_TOTAL_BBM__)
        if(Bank[i]&BBM_GLOBAL_ADDR)
        {
          DAL_Bank_Array[i] = Bank[i];
        }
        else
#endif //#if defined(__NANDFDM_TOTAL_BBM__)
	        if (ZoneNo == 0)
	        {
#if !defined(__NANDFDM_MULTI_INSTANCE__)
                DAL_Bank_Array[i] = Bank[i] + FAT_Start_Section_Offset;
#else  // !defined(__NANDFDM_MULTI_INSTANCE__)
                DAL_Bank_Array[i] = Bank[i] + FAT_Start_Section_Offset[CurDiskIndex];
#endif  // !defined(__NANDFDM_MULTI_INSTANCE__)
	        } else {
                DAL_Bank_Array[i] = Bank[i];
	        }
        }
        Bank = DAL_Bank_Array;
#if !defined(__NANDFDM_MULTI_INSTANCE__)
        ZoneNo += FAT_Start_ZoneNum;
#else  // !defined(__NANDFDM_MULTI_INSTANCE__)
        ZoneNo += FAT_Start_ZoneNum[CurDiskIndex];
#endif  // !defined(__NANDFDM_MULTI_INSTANCE__)
    }
    #else
    if (Acc_Type != FAT_ACC)
    {
        dbg_ASSERT(0);
        free_MTD_lock();
        return MTD_STATUS_PARA_ERROR;
    }
    #endif /* _NAND_FLASH_BOOTING_ || defined(__NANDFDM_MULTI_INSTANCE__) || (__UP_PKG_ON_NAND__ && NAND_SUPPORT)) */
    /*boundary check*/
    if ( ZoneNo >= Flash_Info.zoneNum || Block_offset >= Flash_Info.bankNum )
    {
        force_ASSERT(0,ZoneNo,0,0);
        free_MTD_lock();
        return MTD_STATUS_PARA_ERROR;
    }

    kal_mem_set(&Mtd_para, 0x00,sizeof(Mtd_para));
    Add_Cnvt.zoneNum = ZoneNo ;
    Add_Cnvt.bankArry = Bank;
    Add_Cnvt.pageIdx = Block_offset; /*first page of block*/
    addressMap(&Add_Cnvt);
    if (Flash_Info.deviceInfo_CE[Add_Cnvt.ce].deviceSize*1024*1024 <= Flash_Info.pageSize*Add_Cnvt.phyPage)
    {
        dbg_ASSERT (0);
        free_MTD_lock();
        return MTD_STATUS_PARA_ERROR;
    }
    /* Fill Mtd_para*/
    Mtd_para.buff = (kal_uint8*)Data_buff;
    Mtd_para.spare = (kal_uint8*)Spare_buff;
    Mtd_para.m_idx = 0; /*No use*/
    Mtd_para.length = 1; /*No use*/
    if (Acc_Type == RAW_ACC) {
    	kal_uint32 ZoneLen;

	    ZoneLen = (Flash_Info.CE_interleave_Flag == KAL_FALSE) ? zonePage(0) : zonePage(0) + zonePage(1);
 	    Mtd_para.pageIdx[0] = ((ZoneNo*ZoneLen) + (Bank[0]*Flash_Info.bankNum) + Block_offset) * Flash_Info.blockPage;
	    Mtd_para.ce = 0;
    } else {
	    Mtd_para.pageIdx[0] = Add_Cnvt.phyPage; /*2k page need to check 2nd page in newFlash case*/
	    Mtd_para.ce = Add_Cnvt.ce;
    }

MTD_BB_CHECK:

    mtd_retVal = MTD_CheckBlockBad(&Mtd_para);

    if (mtd_retVal != MTD_STATUS_NO_ERROR) /*no early bad mark in MTD, check the FDM mark whether be OK*/
    {
        retVal |= MTD_STATUS_EARLY_BAD;
    }

    if (Flash_Info.pageSize == 512)
    {
        if ( ( ZEROBIT [((FDMData_512*)Spare_buff)->BI ] >= 2 ) &&
             ( ZEROBIT [((FDMData_512*)Spare_buff)->BI ] <= (ZERO_OF_FDM_BAD_BLOCK_MARK_512 + 1) ) )
            retVal |= MTD_STATUS_FDM_BAD;
    }
    else
    {
        kal_uint8 zeroCount;

        zeroCount = ZEROBIT [((FDMData_2k*)Spare_buff)->BI & 0xFF ];
        if ( ( zeroCount >= 2 ) &&
             ( zeroCount <= (ZERO_OF_FDM_BAD_BLOCK_MARK_512 + 1) ) )
            retVal |= MTD_STATUS_FDM_BAD;

		if (Flash_Info.deviceInfo_CE[0].IOWidth == 16) {
	        zeroCount = ZEROBIT [(((FDMData_2k*)Spare_buff)->BI & 0xFF00)>>8 ] ;
	        if ( ( zeroCount >= 2 ) &&
	             ( zeroCount <= (ZERO_OF_FDM_BAD_BLOCK_MARK_512 + 1) ) )
	            retVal |= MTD_STATUS_FDM_BAD;
		}

    }

    if ( FirstCheck == KAL_TRUE)
    {
    	FirstCheck = KAL_FALSE;

	    if ( newFlash == KAL_TRUE)
	    {
	        if (Flash_Info.pageSize == 512)
	        {
			#if defined(__NFI_VERSION3_1__)
		        if ( ((kal_uint8*)Spare_buff)[5]  != 0xFF )
	       	#else // defined(__NFI_VERSION3_1__)
	            if ( ((FDMData_512*)Spare_buff)->BI != 0xFF )
            #endif // defined(__NFI_VERSION3_1__)
	            {
	                retVal |= MTD_STATUS_EARLY_BAD;
	            }

	            if ( (retVal&MTD_STATUS_EARLY_BAD) != MTD_STATUS_EARLY_BAD )
	            {
	                Mtd_para.pageIdx[0] ++; /*second page*/
	                MTD_CheckBlockBad(&Mtd_para);
			#if defined(__NFI_VERSION3_1__)
			        if ( ((kal_uint8*)Spare_buff)[5]  != 0xFF )
	       	#else // defined(__NFI_VERSION3_1__)
		            if ( ((FDMData_512*)Spare_buff)->BI != 0xFF )
            #endif // defined(__NFI_VERSION3_1__)
            		{
		                retVal |= MTD_STATUS_EARLY_BAD;
            		}
	            }
	        }
	        else
	        {
	        	// Offset 0 and offset 2048.
	        	if ( Mtd_para.buff[0] != 0xff ) {
	                retVal |= MTD_STATUS_EARLY_BAD;
	        	}
	        	if ( (Flash_Info.deviceInfo_CE[Mtd_para.ce].IOWidth==16) && (Mtd_para.buff[1]!=0xff) ) {
	                retVal |= MTD_STATUS_EARLY_BAD;
	        	}

			#if defined(__NFI_VERSION3_1__)
            if (Flash_Info.pageSize == 2048)
            {
				if ( (((kal_uint8*)Data_buff)[2048-48]!=0xff) || (((kal_uint8*)Data_buff)[2048-48+1]!=0xff) )
              {
                    retVal |= MTD_STATUS_EARLY_BAD;
              }
            }
            else
            {
              if ( (((kal_uint8*)Data_buff)[4096-(16*7)]!=0xff) || (((kal_uint8*)Data_buff)[4096-(16*7)+1]!=0xff) )
              {
                    retVal |= MTD_STATUS_EARLY_BAD;
              }
            }
			#else // defined(__NFI_VERSION3_1__)
	            if ( ((FDMData_2k*)Spare_buff)->BI != 0xFFFF )
				{
	                retVal |= MTD_STATUS_EARLY_BAD;
				}
      			#endif // defined(__NFI_VERSION3_1__)
	            /*for 2k page, the bad mark is possible to put at 2nd page*/
	            if ( (retVal&MTD_STATUS_EARLY_BAD) != MTD_STATUS_EARLY_BAD )
	            {
					        if (Flash_Info.deviceInfo_CE[Mtd_para.ce].ID_info[0]==POWERFLASH) {
						      // last page
						        Mtd_para.pageIdx[0] += (Flash_Info.blockPage-1);
					        } else {
						        // second page
		                Mtd_para.pageIdx[0] ++;
					        }
	                MTD_CheckBlockBad(&Mtd_para);
		        	    if ( Mtd_para.buff[0] != 0xff ) {
		                retVal |= MTD_STATUS_EARLY_BAD;
		        	    }
		        	    if ( (Flash_Info.deviceInfo_CE[Mtd_para.ce].IOWidth==16) && (Mtd_para.buff[1]!=0xff) ) {
		                retVal |= MTD_STATUS_EARLY_BAD;
		        	}
				#if defined(__NFI_VERSION3_1__)
              if (Flash_Info.pageSize == 2048)
              {
					if ( (((kal_uint8*)Data_buff)[2048-48]!=0xff) || (((kal_uint8*)Data_buff)[2048-48+1]!=0xff) )
                {
                      retVal |= MTD_STATUS_EARLY_BAD;
                }
              }
              else
              {
                if ( (((kal_uint8*)Data_buff)[4096-(16*7)]!=0xff) || (((kal_uint8*)Data_buff)[4096-(16*7)+1]!=0xff) )
                {
                      retVal |= MTD_STATUS_EARLY_BAD;
                }
              }
				#else // defined(__NFI_VERSION3_1__)
 	                if ( ((FDMData_2k*)Spare_buff)->BI != 0xFFFF )
              {
	                    retVal |= MTD_STATUS_EARLY_BAD;
	            }
#endif // defined(__NFI_VERSION3_1__)
	            }
	        }

#if !defined(__NFI_VERSION3_1__)
// For code image bad block check, no new flash case.
	        if (Acc_Type == CODE_ACC) {
	        	goto MTD_BB_CHECK;
	        }
#endif //#if !(defined(__NFI_VERSION3_1__))
	    } else {
	    	// No new flash
	        if (Acc_Type == CODE_ACC) {
				if (Flash_Info.deviceInfo_CE[Mtd_para.ce].ID_info[0]==POWERFLASH) {
					// last page
					Mtd_para.pageIdx[0] += (Flash_Info.blockPage-1);
				} else {
					// second page
		            Mtd_para.pageIdx[0] ++;
				}
	        	goto MTD_BB_CHECK;
	        }
	    }
    }

    free_MTD_lock();
    return retVal;
}

// Description
//	This function is only used for FOTA for compatility.
kal_uint8 IsGoodBlock(void* D, void * Spare)
{
    kal_uint8  good_block = 1;

    if (Flash_Info.pageSize == 512) {
        if ( ZEROBIT [((FDMData_512*)Spare)->BI ] >= 2 ) {
	        good_block = 0;
        }
    } else {
        kal_uint8 zeroCount;
        zeroCount = ZEROBIT [((FDMData_2k*)Spare)->BI & 0xFF ];
        if ( zeroCount >= 2 ) {
            good_block = 0;
        }

		if (Flash_Info.deviceInfo_CE[0].IOWidth == 16) {
	        zeroCount = ZEROBIT [(((FDMData_2k*)Spare)->BI & 0xFF00)>>8 ] ;
	        if ( zeroCount >= 2 ) {
	            good_block = 0;
	        }
		}
    }

    return good_block;
}

/****************************************************************************
 * Function:   DAL_NAND_Reset
 *
 * Parameters: void
 *
 * Returns:    MTD_STATUS_NO_ERROR
 *
 * Description:
 *
 ****************************************************************************/
kal_int32 DAL_NAND_Reset(void)
{
    get_MTD_lock();
    if ( Flash_Info.valid_CE[0] == KAL_TRUE )
    {
        Mtd_para.ce = 0;
        MTD_NAND_Reset(&Mtd_para);
    }
    if ( Flash_Info.valid_CE[1] == KAL_TRUE )
    {
        Mtd_para.ce = 1;
        MTD_NAND_Reset(&Mtd_para);
    }
    free_MTD_lock();
    return MTD_STATUS_NO_ERROR;
}

/****************************************************************************
 * Function:
 *
 * Parameters:
 *
 * Returns:
 *
 * Description:
 *
 ****************************************************************************/
kal_uint16 DAL_GetFDMData(kal_uint8 FDMType, kal_uint32 *Spare_buff)
{
	kal_uint16 Data = 0;

    if (Flash_Info.pageSize == 512)
    {
        switch(FDMType) {
        case FDMDATA_BM:
        case FDMDATA_PA:
            Data = ((FDMData_512*)Spare_buff) -> BM_PA;
            break;
        case FDMDATA_LBA:
            Data = ((FDMData_512*)Spare_buff) -> LBA;
            break;
        case FDMDATA_BI:
            Data = ((FDMData_512*)Spare_buff) -> BI;
            break;
        case FDMDATA_4XCTL:
            Data = ((FDMData_512*)Spare_buff) -> PBA;
        	break;
        default:
            dbg_ASSERT(0);
        }
    }
    else
    {
        switch(FDMType) {
        case FDMDATA_BM:
        case FDMDATA_PA:
        case FDMDATA_4XCTL:
            Data = ((FDMData_2k*)Spare_buff) -> BM_PA;
            break;
        case FDMDATA_LBA:
            Data = ((FDMData_2k*)Spare_buff) -> LBA;
            break;
        case FDMDATA_BI:
            Data = ((FDMData_2k*)Spare_buff) -> BI;
            break;
        default:
            dbg_ASSERT(0);
        }
    }
	return Data;
}

/****************************************************************************
 * Function:
 *
 * Parameters:
 *
 * Returns:
 *
 * Description:
 *
 ****************************************************************************/
void DAL_SetFDMData(kal_uint16 BMPA, kal_uint16 LBA, kal_uint8 Option, kal_uint32 *Spare_buff)
{
    if (Flash_Info.pageSize == 512)
    {
        if (Option & FDMDATA_EMPTY)
            kal_mem_set(Spare_buff, 0xFF, sizeof(FDMData_512) );

        if (Option & (FDMDATA_BM | FDMDATA_PA))
        {
            ((FDMData_512*)Spare_buff) -> BM_PA = BMPA;
        }

        if (Option & FDMDATA_LBA)
        {
            ((FDMData_512*)Spare_buff) -> LBA = LBA;
        }
    }
    else
    {
        if (Option & FDMDATA_EMPTY)
            kal_mem_set(Spare_buff, 0xFF, sizeof(FDMData_2k) );

        if (Option & (FDMDATA_BM | FDMDATA_PA))
        {
            ((FDMData_2k*)Spare_buff) -> BM_PA = BMPA;
        }

        if (Option & FDMDATA_LBA)
        {
            ((FDMData_2k*)Spare_buff) -> LBA = LBA;
        }
    }
}

/****************************************************************************
 * Function:     DAL_GetDALVersion
 *
 * Parameters:
 *
 * Returns:      DAL_VERISON
 *
 * Description:  Return the DAL version of this load
 *
 ****************************************************************************/
kal_uint8 DAL_GetDALVersion(void)
{
    return DAL_MINOR_VER2;
}

/****************************************************************************
 * Function:     DAL_GetDALVersion
 *
 * Parameters:   dal_ver    The DAL version that record at File system
 *
 * Returns:      KAL_TRUE   Format it
 *               KAL_FALSE  Do not format it
 *
 * Description:  FDM uses this fucntion to query DAL if format trigger or not
 *
 ****************************************************************************/
kal_bool DAL_FormatQuery(kal_uint8 dal_ver)
{
    return dal_ver != DAL_VERISON ? KAL_TRUE : KAL_FALSE ;
}

kal_bool NANDsanitycheck_Factory(void)
{
    if ( DAL_is_initialized == 0 )
    {
        FLASH_INFO F_info;
        DAL_init();
        DAL_FDM_Flash_Info_Init (&F_info, 0);
    }
    return (kal_bool)Flash_Info.valid_CE[0];
}

void DAL_GetDeviceInfo (kal_uint8 cs, flash_list* p)
{
    if (Flash_Info.valid_CE[cs] == KAL_TRUE)
    {
        kal_mem_cpy(p, &Flash_Info.deviceInfo_CE[cs], sizeof(flash_list));
    }
    else
    {
        kal_mem_set(p, 0xFF, sizeof(flash_list) ); /*Reset value*/
    }
}
/****************************************************************************
 * Function:
 *
 * Parameters:  Block       Logic block in code view (input)
 *              Page        The page index in the Block (input)
 *              cs_p        output of chip select
 *              page_idx_p  output of physical page index
 * Returns:     MTD_STATUS_NO_ERROR
 *
 * Description:
 *
 ****************************************************************************/
#if defined(FLASH_DISKDRV_DEBUG) || (defined _NAND_FLASH_BOOTING_)
kal_int32 DAL_NFB_AddressConvert(kal_uint32 Block, kal_uint32 Page, kal_uint8* cs_p, kal_uint32* page_idx_p)
{
    kal_uint32 zone_len;
    kal_uint8 zone_off;
    kal_uint16 b_arr[MAX_MULTIPAGE_NUM];
    kal_int32 k, retVal = MTD_STATUS_NO_ERROR;
    get_MTD_lock();
    zone_len = (Flash_Info.CE_interleave_Flag == KAL_FALSE) ? zonePage(0) : zonePage(0) + zonePage(1);
    /*calculate the DAL parameter*/
    zone_off = Block/zone_len;
    Block -= zone_off*zone_len;
    for (k=0;k< Flash_Info.bankNum; k++)
    {
        b_arr[k] = (Block/Flash_Info.bankNum);
    }
    Page = Page*Flash_Info.bankNum + Block%Flash_Info.bankNum ;
    Add_Cnvt.zoneNum = zone_off ;
    Add_Cnvt.bankArry = b_arr;
    Add_Cnvt.pageIdx = Page;
    retVal = addressMap(&Add_Cnvt);
    *cs_p = Add_Cnvt.ce;
    *page_idx_p = Add_Cnvt.phyPage;
    if (Flash_Info.deviceInfo_CE[Add_Cnvt.ce].deviceSize*1024*1024 <= Flash_Info.pageSize*Add_Cnvt.phyPage)
    {
        dbg_ASSERT (0);
        free_MTD_lock();
        return MTD_STATUS_PARA_ERROR;
    }
    free_MTD_lock();
    return retVal;
}


#endif

#if defined(_NAND_FLASH_BOOTING_) || (defined(__UP_PKG_ON_NAND__) && defined(NAND_SUPPORT))

int NFB_ErasePhysicalBlock(kal_uint32 PhyBlock, kal_bool DALRemap)
{
    //FLASH_INFO F_info;
    kal_uint8 zone_off;
    kal_uint16 b_arr[MAX_MULTIPAGE_NUM];
    kal_int32 NFBStatus = -1,k;
    kal_uint32 zone_len, BankNo;

    if ( DAL_is_initialized == 0 )
    {
        NFBStatus = DAL_init();
        force_ASSERT( NFBStatus == FS_NO_ERROR ,NFBStatus ,0 ,0);
    }
    //DAL_FDM_Flash_Info_Init (&F_info, 0);
    if ( PhyBlock==0xFFFFFFFF) /*1st access access of NFB*/
    {
        return Flash_Info.deviceInfo_CE[0].IOWidth;
    }

    DAL_NAND_Reset();

    zone_len = (Flash_Info.CE_interleave_Flag == KAL_FALSE) ? zonePage(0) : zonePage(0) + zonePage(1);

    /*calculate the DAL parameter*/
    zone_off = PhyBlock/zone_len;
    PhyBlock -= zone_off*zone_len;
    for (k=0;k< Flash_Info.bankNum; k++)
    {
        b_arr[k] = (PhyBlock/Flash_Info.bankNum);
    }
    BankNo = PhyBlock%Flash_Info.bankNum;
    NFBStatus = DAL_CheckBadBlock (DALRemap ? CODE_ACC : RAW_ACC, zone_off, b_arr, BankNo, KAL_FALSE, NFB_tmp_D_Buff, NFB_tmp_S_Buff);
    if ( NFBStatus != MTD_STATUS_NO_ERROR )
    {
        return ERROR_NFB_BAD_BLOCK;
    }

	NFBStatus = DAL_EraseBlock(DALRemap ? CODE_ACC : RAW_ACC, zone_off, b_arr, BankNo, 1) & 0xffff;

	if (NFBStatus) {
		// Program failure.
		return ERROR_NFB_ERASE;
	}

    return ERROR_NFB_SUCCESS;

}

int NFB_ProgramPhysicalSpare(kal_uint32 PhyBlock, kal_uint32 PhyPage, void * Data, kal_bool chksum, kal_bool DALRemap)
{
    //FLASH_INFO F_info;
    kal_uint8 zone_off;
    kal_uint16 b_arr[MAX_MULTIPAGE_NUM];
    kal_int32 NFBStatus = -1,k;
    kal_uint32 zone_len;
/*	kal_uint16 *word_ptr = NULL;
	kal_uint8  *byte_ptr = NULL;
    kal_uint32 end_count = 0;
	kal_uint32 idx = 0;
	kal_uint16 sum_val = 0;
	kal_uint16 temp_val = 0;
    kal_uint8  *pack_ptr = (kal_uint8 *)&temp_val;*/

    if ( DAL_is_initialized == 0 )
    {
        NFBStatus = DAL_init();
        force_ASSERT( NFBStatus == FS_NO_ERROR ,NFBStatus ,0 ,0);
    }
    //DAL_FDM_Flash_Info_Init (&F_info, 0);
    if ( PhyBlock==0xFFFFFFFF && PhyPage==0xFFFFFFFF ) /*1st access access of NFB*/
    {
        return Flash_Info.deviceInfo_CE[0].IOWidth;
    }

    DAL_NAND_Reset();

    zone_len = (Flash_Info.CE_interleave_Flag == KAL_FALSE) ? zonePage(0) : zonePage(0) + zonePage(1);

    /*calculate the DAL parameter*/
    zone_off = PhyBlock/zone_len;
    PhyBlock -= zone_off*zone_len;
    for (k=0;k< Flash_Info.bankNum; k++)
    {
        b_arr[k] = (PhyBlock/Flash_Info.bankNum);
    }
    PhyPage = PhyPage*Flash_Info.bankNum + PhyBlock%Flash_Info.bankNum ;

	/* check alignment */
/*	if(((kal_uint32)Data) & 0x01)
	{
		byte_ptr = (kal_uint8 *)Data;
	}
	else
	{
		word_ptr = (kal_uint16 *)Data;
	}

	if (chksum) {
		if( Flash_Info.pageSize == 2048 )
		{
			end_count = 31;
		}
		else if ( Flash_Info.pageSize == 512 )
		{
			end_count = 7;
		}
		else
		{
			ASSERT(0);
		}

		if(word_ptr)
		{
			for(idx = 0 ; idx < end_count ; idx++)
			{
				sum_val += word_ptr[idx];
			}
			word_ptr[idx] = sum_val;
		}
		else
		{
			for(idx = 0 ; idx < end_count ; idx++)
			{
				pack_ptr[0] = byte_ptr[(idx<<1)];
				pack_ptr[1] = byte_ptr[1+(idx<<1)];
				sum_val += temp_val;
			}
			temp_val = sum_val;
			byte_ptr[idx<<1] = pack_ptr[0];
			byte_ptr[1+(idx<<1)] = pack_ptr[1];
		}
	}*/

    kal_mem_set(NFB_tmp_D_Buff, 0xFF, Flash_Info.pageSize);
	NFBStatus = DAL_ProgramPage(DALRemap ? CODE_ACC : RAW_ACC, zone_off, b_arr, PhyPage, 1, (kal_uint8*)NFB_tmp_D_Buff, (kal_uint8*)Data) & 0xffff;

	if (NFBStatus) {
		// Program failure.
		return ERROR_NFB_PROGRAM;
	}

    return ERROR_NFB_SUCCESS;

}

int NFB_ProgramPhysicalPage(kal_uint32 PhyBlock, kal_uint32 PhyPage, void * Data, kal_bool DALRemap)
{
    //FLASH_INFO F_info;
    kal_uint8 zone_off;
    kal_uint16 b_arr[MAX_MULTIPAGE_NUM];
    kal_int32 NFBStatus = -1,k;
    kal_uint32 zone_len;

    if ( DAL_is_initialized == 0 )
    {
        NFBStatus = DAL_init();
        force_ASSERT( NFBStatus == FS_NO_ERROR ,NFBStatus ,0 ,0);
    }
    //DAL_FDM_Flash_Info_Init (&F_info, 0);
    if ( PhyBlock==0xFFFFFFFF && PhyPage==0xFFFFFFFF ) /*1st access access of NFB*/
    {
        return Flash_Info.deviceInfo_CE[0].IOWidth;
    }

    DAL_NAND_Reset();

    zone_len = (Flash_Info.CE_interleave_Flag == KAL_FALSE) ? zonePage(0) : zonePage(0) + zonePage(1);

    /*calculate the DAL parameter*/
    zone_off = PhyBlock/zone_len;
    PhyBlock -= zone_off*zone_len;
    for (k=0;k< Flash_Info.bankNum; k++)
    {
        b_arr[k] = (PhyBlock/Flash_Info.bankNum);
    }
    PhyPage = PhyPage*Flash_Info.bankNum + PhyBlock%Flash_Info.bankNum ;

    NFBStatus = DAL_CheckBadBlock (DALRemap ? CODE_ACC : RAW_ACC, zone_off,b_arr, PhyBlock%Flash_Info.bankNum, KAL_FALSE, NFB_tmp_D_Buff, NFB_tmp_S_Buff);
    if ( NFBStatus != MTD_STATUS_NO_ERROR )
    {
        return ERROR_NFB_BAD_BLOCK;
    }

    kal_mem_set(NFB_tmp_S_Buff, 0xFF, 64);
	NFBStatus = DAL_ProgramPage(DALRemap ? CODE_ACC : RAW_ACC, zone_off, b_arr, PhyPage, 1, Data, (kal_uint8*)NFB_tmp_S_Buff) & 0xffff;

	if (NFBStatus) {
		// Program failure.
		return ERROR_NFB_PROGRAM;
	}

    return Flash_Info.pageSize;
}

int	NFB_MarkBadBlock(kal_uint32 PhyBlock, kal_bool DALRemap)
{
    kal_uint8 zone_off;
    kal_uint16 b_arr[MAX_MULTIPAGE_NUM];
    kal_int32 NFBStatus = -1,k;
    kal_uint32 zone_len;

    if ( DAL_is_initialized == 0 )
    {
        NFBStatus = DAL_init();
        force_ASSERT( NFBStatus == FS_NO_ERROR ,NFBStatus ,0 ,0);
    }

    DAL_NAND_Reset();

    zone_len = (Flash_Info.CE_interleave_Flag == KAL_FALSE) ? zonePage(0) : zonePage(0) + zonePage(1);

    /*calculate the DAL parameter*/
    zone_off = PhyBlock/zone_len;
    PhyBlock -= zone_off*zone_len;
    for (k=0;k< Flash_Info.bankNum; k++)
    {
        b_arr[k] = (PhyBlock/Flash_Info.bankNum);
    }

	NFBStatus = DAL_MarkBlockBad(DALRemap ? CODE_ACC : RAW_ACC, zone_off, b_arr, PhyBlock%Flash_Info.bankNum, KAL_TRUE, NFB_tmp_D_Buff, NFB_tmp_S_Buff);

	if (NFBStatus) {
		return ERROR_NFB_PROGRAM;
	}

    return ERROR_NFB_SUCCESS;

}

int	NFB_ProgramPhysicalPageWithSpare(kal_uint32 PhyBlock, kal_uint32 PhyPage, void *Data, void *Spare, kal_bool DALRemap)
{
    kal_uint8 zone_off;
    kal_uint16 b_arr[MAX_MULTIPAGE_NUM];
    kal_int32 NFBStatus = -1,k;
    kal_uint32 zone_len;

    if ( DAL_is_initialized == 0 )
    {
        NFBStatus = DAL_init();
        force_ASSERT( NFBStatus == FS_NO_ERROR ,NFBStatus ,0 ,0);
    }

    DAL_NAND_Reset();

    zone_len = (Flash_Info.CE_interleave_Flag == KAL_FALSE) ? zonePage(0) : zonePage(0) + zonePage(1);

    /*calculate the DAL parameter*/
    zone_off = PhyBlock/zone_len;
    PhyBlock -= zone_off*zone_len;
    for (k=0;k< Flash_Info.bankNum; k++)
    {
        b_arr[k] = (PhyBlock/Flash_Info.bankNum);
    }
    PhyPage = PhyPage*Flash_Info.bankNum + PhyBlock%Flash_Info.bankNum ;

    NFBStatus = DAL_CheckBadBlock (DALRemap ? CODE_ACC : RAW_ACC, zone_off,b_arr, PhyBlock%Flash_Info.bankNum, KAL_FALSE, NFB_tmp_D_Buff, NFB_tmp_S_Buff);
    if ( NFBStatus != MTD_STATUS_NO_ERROR )
    {
        return ERROR_NFB_BAD_BLOCK;
    }

	NFBStatus = DAL_ProgramPage(DALRemap ? CODE_ACC : RAW_ACC, zone_off, b_arr, PhyPage, 1, (kal_uint8*)Data, (kal_uint8*)Spare) & 0xffff;

	if (NFBStatus) {
		// Program failure.
		return ERROR_NFB_PROGRAM;
	}

    return Flash_Info.pageSize;

}

kal_int32 NFB_ReadPhysicalPage(kal_uint32 PhyBlock, kal_uint32 PhyPage, void * Data)
{
    kal_uint8 zone_off;
    kal_uint16 b_arr[MAX_MULTIPAGE_NUM];
    kal_int32 NFBStatus = -1,k;
    static kal_uint32 zone_len = DWORD_INVALID;
    static kal_uint32 blockStatus[3] = {DWORD_INVALID,DWORD_INVALID,DWORD_INVALID}; /*record block status*/
#if ( defined(__EMULATE_NFB_BIT_ERROE__) )
    FLASH_INFO F_info;
	kal_bool CompareError = KAL_FALSE;
#endif // ( defined(__EMULATE_NFB_BIT_ERROE__) )

    if ( DAL_is_initialized == 0 )
    {
        NFBStatus = DAL_init();
        force_ASSERT( NFBStatus == FS_NO_ERROR ,NFBStatus ,0 ,0);
    }
    //DAL_FDM_Flash_Info_Init (&F_info, 0);   // 2010.1.11 mtk02493 remark for useless
    if ( PhyBlock==0xFFFFFFFF && PhyPage==0xFFFFFFFF ) /*1st access access of NFB*/
    {
        return Flash_Info.deviceInfo_CE[0].IOWidth;
    }

    DAL_NAND_Reset();

    if (zone_len == DWORD_INVALID)
    {
        zone_len = (Flash_Info.CE_interleave_Flag == KAL_FALSE) ? zonePage(0) : zonePage(0) + zonePage(1);
    }
    /*calculate the DAL parameter*/
    zone_off = PhyBlock/zone_len;
    PhyBlock -= zone_off*zone_len;
    for (k=0;k< Flash_Info.bankNum; k++)
    {
        b_arr[k] = (PhyBlock/Flash_Info.bankNum);
    }
    PhyPage = PhyPage*Flash_Info.bankNum + PhyBlock%Flash_Info.bankNum ;
    get_MTD_lock(); /*protect blockStatus*/
    if ( (blockStatus[0]==zone_off) &&
    	 (blockStatus[1]==PhyBlock) )
    {
        free_MTD_lock();
    }
    else
    {
        free_MTD_lock();
        NFBStatus = DAL_CheckBadBlock (CODE_ACC, zone_off,b_arr, PhyBlock%Flash_Info.bankNum,KAL_FALSE,NFB_tmp_D_Buff,NFB_tmp_S_Buff);
        get_MTD_lock();
        blockStatus[0]=zone_off;
        blockStatus[1]=PhyBlock;
        blockStatus[2]=NFBStatus;
        free_MTD_lock();
    }
    if ( blockStatus[2] != MTD_STATUS_NO_ERROR )
    {
        return ERROR_NFB_BAD_BLOCK;
    }


#if ( defined(__EMULATE_NFB_BIT_ERROE__) )
  DAL_FDM_Flash_Info_Init (&F_info, 0);   // 2010.1.11 mtk02493 move to here
	EmulateBitError(CODE_ACC, zone_off, b_arr, PhyPage, F_info.SectorNumPerPage, D_Buff, S_Buff);

#if ( defined(__NAND_FLASH_HARDWARE_TEST__) && defined(__MAUI_BASIC__) )
#if defined(__UBL__)
		dbg_print("NFB download into address %xh\n\r", Data);
#else // defined(__UBL__)
    nandlog_print("NFB download into address %xh\r\n", Data);
    
#endif // !defined(__UBL__)
#endif // ( defined(__NAND_FLASH_HARDWARE_TEST__) && defined(__MAUI_BASIC__) )

#endif // ( defined(__EMULATE_NFB_BIT_ERROE__) )

    NFBStatus = DAL_ReadPage (CODE_ACC,zone_off,b_arr,PhyPage,1,Data,(kal_uint8*)NULL) & 0xffff0000; /*null spare buff point mean do not care spare data*/

#if ( defined(__EMULATE_NFB_BIT_ERROE__) )

	// The following needs to be tested only when secondary ROM is un-cachable.
	// Otherwise, kal_mem_cmp will corrupt the last page if the starting address is not cache line alignment.
	// That is because MTD use DMA move but kal_mem_cmp use CPU move and will have cache have the data of next oage.
	if ( kal_mem_cmp(Data, &D_Buff[_DAL_MAX_PAGE_SIZE_/4], F_info.SectorNumPerPage*0x200 - 32 ) )  {
		kal_uint32 Offset;
		for (Offset=0; Offset<Flash_Info.pageSize/4; Offset++) {
			if ( ((kal_uint32*)Data)[Offset] != D_Buff[(_DAL_MAX_PAGE_SIZE_/4)+Offset] ) {

#if ( defined(__NAND_FLASH_HARDWARE_TEST__) && defined(__MAUI_BASIC__) )
				
#if defined(__UBL__)
				dbg_print("NFB compare error in ECC test. Address %x. Wrong data=%x, Right data=%x\n\r", &(((kal_uint32*)Data)[Offset]),
	    			((kal_uint32*)Data)[Offset], D_Buff[(_DAL_MAX_PAGE_SIZE_/4)+Offset]);
#else // defined(__UBL__)
			    nandlog_print("NFB compare error in ECC test. Address %x. Wrong data=%x, Right data=%x\r\n", &(((kal_uint32*)Data)[Offset]),
	    			((kal_uint32*)Data)[Offset], D_Buff[(_DAL_MAX_PAGE_SIZE_/4)+Offset]);
			      
#endif // defined(__UBL__)			    

#endif // ( defined(__NAND_FLASH_HARDWARE_TEST__) && defined(__MAUI_BASIC__) )

			    CompareError = KAL_TRUE;
			}
		}
	}


	if (CompareError==KAL_TRUE) {

#if ( defined(__NAND_FLASH_HARDWARE_TEST__) && defined(__MAUI_BASIC__) )

#if defined(__UBL__)
		dbg_print("NFB compare error in ECC test.\n\r");
#else // defined(__UBL__)
	  	nandlog_print("NFB compare error in ECC test.\r\n");
#endif // defined(__UBL__)

#endif // ( defined(__NAND_FLASH_HARDWARE_TEST__) && defined(__MAUI_BASIC__) )

		dbg_ASSERT(0);
	}

#endif // ( defined(__EMULATE_NFB_BIT_ERROE__) )


    #if defined(__FUE__)
    if ( NFBStatus == MTD_STATUS_ERROR ) {
    	return ERROR_NFB_READ;
    } else if ( NFBStatus != MTD_STATUS_NO_ERROR ) {
    	if (NFBStatus == MTD_STATUS_CORRECTED) {
    		return ERROR_NFB_ECC_CORRECTED;
    	}
    }
    #else // defined(__FUE__)
    if ( NFBStatus == MTD_STATUS_ERROR ) {
    	return ERROR_NFB_READ;
    }
    #endif // defined(__FUE__)

    return Flash_Info.pageSize;
}

int NFB_ReadPhysicalSpare(kal_uint32 PhyBlock, kal_uint32 PhyPage, void * Data, kal_bool chksum)
{
    kal_uint8 zone_off;
    kal_uint16 b_arr[MAX_MULTIPAGE_NUM];
    kal_int32 NFBStatus = -1,k;
    kal_uint32 zone_len = DWORD_INVALID;
/*	kal_uint8  *byte_ptr = NULL;
	kal_uint16 *word_ptr = NULL;
	kal_uint8  *pack_byte = NULL;
	kal_uint16 temp_val = 0;
	kal_uint16 sum_val = 0;
	kal_uint32 spare_size = 0;
	kal_uint32 i = 0;*/


    if ( DAL_is_initialized == 0 )
    {
        NFBStatus = DAL_init();
        force_ASSERT( NFBStatus == FS_NO_ERROR ,NFBStatus ,0 ,0);
    }
    if ( PhyBlock==0xFFFFFFFF && PhyPage==0xFFFFFFFF ) /*1st access access of NFB*/
    {
        return Flash_Info.deviceInfo_CE[0].IOWidth;
    }

    DAL_NAND_Reset();

    zone_len = (Flash_Info.CE_interleave_Flag == KAL_FALSE) ? zonePage(0) : zonePage(0) + zonePage(1);

    /*calculate the DAL parameter*/
    zone_off = PhyBlock/zone_len;
    PhyBlock -= zone_off*zone_len;
    for (k=0;k< Flash_Info.bankNum; k++)
    {
        b_arr[k] = (PhyBlock/Flash_Info.bankNum);
    }
    PhyPage = PhyPage*Flash_Info.bankNum + PhyBlock%Flash_Info.bankNum ;


    NFBStatus = DAL_ReadPage (CODE_ACC, zone_off, b_arr, PhyPage, 1, (kal_uint8*)NFB_tmp_D_Buff, (kal_uint8*)Data) & 0xffff0000;
	// Edward : May not use NFBStatus to check because this is full page read with ECC correction..
	// In NAND FDM 4.x FOTA, read spare does not return error.

/*	if( chksum ) {
		if (Flash_Info.pageSize == 2048) {
			spare_size = 64;
		}
		else if (Flash_Info.pageSize == 512) {
			spare_size = 16;
		}

		if(((kal_uint32)Data) & 0x01) // not word aligned
		{
			byte_ptr = (kal_uint8 *)Data;
			for(i = 0 ; i < ((spare_size >> 1) - 1) ; i++)
			{
				pack_byte[0] = byte_ptr[i<<1];
				pack_byte[1] = byte_ptr[1+(i<<1)];
				sum_val += temp_val;
			}
			pack_byte[0] = byte_ptr[i>>1];
			pack_byte[1] = byte_ptr[1+(i>>1)];
			if(sum_val != temp_val)
			{
				NFBStatus = ERROR_NFB_CHECKSUM;
			}
			else
			{
				NFBStatus = ERROR_NFB_SUCCESS;
			}
		}
		else
		{
			word_ptr = (kal_uint16 *)Data;
			for(i = 0 ; i < ((spare_size >> 1) - 1) ; i++)
			{
				sum_val += word_ptr[i];
			}
			if(sum_val != word_ptr[i])
			{
				NFBStatus = ERROR_NFB_CHECKSUM;
			}
			else
			{
				NFBStatus = ERROR_NFB_SUCCESS;
			}
		}
   }
   else */
   {
   		NFBStatus = ERROR_NFB_SUCCESS;
   }

   return NFBStatus;
}

//#if defined(__FOTA_DM__)

kal_int32 NFB_ReadPhysicalPageWithSpare(kal_uint32 PhyBlock, kal_uint32 PhyPage, kal_uint8* Data)
{
    //FLASH_INFO F_info;
    kal_uint8 zone_off;
    kal_uint16 b_arr[MAX_MULTIPAGE_NUM];
    kal_int32 NFBStatus = -1,k;
    static kal_uint32 zone_len = DWORD_INVALID;
    static kal_uint32 blockStatus[3] = {DWORD_INVALID,DWORD_INVALID,DWORD_INVALID}; /*record block status*/

    if ( DAL_is_initialized == 0 )
    {
        NFBStatus = DAL_init();
        force_ASSERT( NFBStatus == FS_NO_ERROR ,NFBStatus ,0 ,0);
    }
    //DAL_FDM_Flash_Info_Init (&F_info, 0);  //2010.01.12 kuohong remark
    if ( PhyBlock==0xFFFFFFFF && PhyPage==0xFFFFFFFF ) /*1st access access of NFB*/
    {
        return Flash_Info.deviceInfo_CE[0].IOWidth;
    }

    DAL_NAND_Reset();

    if (zone_len == DWORD_INVALID)
    {
        zone_len = (Flash_Info.CE_interleave_Flag == KAL_FALSE) ? zonePage(0) : zonePage(0) + zonePage(1);
    }
    /*calculate the DAL parameter*/
    zone_off = PhyBlock/zone_len;
    PhyBlock -= zone_off*zone_len;
    for (k=0;k< Flash_Info.bankNum; k++)
    {
        b_arr[k] = (PhyBlock/Flash_Info.bankNum);
    }
    PhyPage = PhyPage*Flash_Info.bankNum + PhyBlock%Flash_Info.bankNum ;
    get_MTD_lock(); /*protect blockStatus*/
    if ( (blockStatus[0]==zone_off) &&
    	 (blockStatus[1]==PhyBlock) )
    {
        free_MTD_lock();
    }
    else
    {
        free_MTD_lock();
        NFBStatus = DAL_CheckBadBlock (CODE_ACC, zone_off,b_arr, PhyBlock%Flash_Info.bankNum,KAL_FALSE,NFB_tmp_D_Buff,NFB_tmp_S_Buff);
        get_MTD_lock();
        blockStatus[0]=zone_off;
        blockStatus[1]=PhyBlock;
        blockStatus[2]=NFBStatus;
        free_MTD_lock();
    }
    if ( blockStatus[2] != MTD_STATUS_NO_ERROR )
    {
        return ERROR_NFB_BAD_BLOCK;
    }

    NFBStatus = DAL_ReadPage (CODE_ACC,zone_off,b_arr,PhyPage,1,Data,(kal_uint8*)&Data[Flash_Info.pageSize]) & 0xffff0000;

	// It will return fail because that flashtool use checksum instead of spare ECC.
/*    if ( NFBStatus == MTD_STATUS_ERROR ) {
    	return ERROR_NFB_READ;
    } else if ( NFBStatus != MTD_STATUS_NO_ERROR ) {
    	if (NFBStatus == MTD_STATUS_CORRECTED) {
    		return ERROR_NFB_ECC_CORRECTED;
    	}
    }*/

    return Flash_Info.pageSize;
}

//#endif // defined(__FOTA_DM__)


kal_int32 NFB_CheckGoodBlock2(kal_uint32 Block, kal_bool DALRemap)
{
    kal_uint32 zone_len;
    kal_uint8 zone_off;
    kal_uint16 b_arr[MAX_MULTIPAGE_NUM];
    kal_int32 k, retVal;
    zone_len = (Flash_Info.CE_interleave_Flag == KAL_FALSE) ? zonePage(0) : zonePage(0) + zonePage(1);
    /*calculate the DAL parameter*/
    zone_off = Block/zone_len;
    Block -= zone_off*zone_len;
    for (k=0;k< Flash_Info.bankNum; k++)
    {
        b_arr[k] = (Block/Flash_Info.bankNum);
    }
    DAL_NAND_Reset();
    retVal = DAL_CheckBadBlock (DALRemap ? CODE_ACC : RAW_ACC, zone_off,b_arr, Block%Flash_Info.bankNum,KAL_FALSE,NFB_tmp_D_Buff,NFB_tmp_S_Buff);
    if (retVal == MTD_STATUS_NO_ERROR)
        return 0;
    else
        return -1;
}

kal_int32 NFB_CheckGoodBlock(kal_uint32 Block)
{
    return demp_CheckGoodBlock(Block);
}

kal_int32 demp_CheckGoodBlock(kal_uint32 Block) /*MAUI_00592819*/
{
    kal_uint32 zone_len;
    kal_uint8 zone_off;
    kal_uint16 b_arr[MAX_MULTIPAGE_NUM];
    kal_int32 k, retVal;
    zone_len = (Flash_Info.CE_interleave_Flag == KAL_FALSE) ? zonePage(0) : zonePage(0) + zonePage(1);
    /*calculate the DAL parameter*/
    zone_off = Block/zone_len;
    Block -= zone_off*zone_len;
    for (k=0;k< Flash_Info.bankNum; k++)
    {
        b_arr[k] = (Block/Flash_Info.bankNum);
    }
    DAL_NAND_Reset();
    retVal = DAL_CheckBadBlock (CODE_ACC, zone_off,b_arr, Block%Flash_Info.bankNum,KAL_FALSE,NFB_tmp_D_Buff,NFB_tmp_S_Buff);
    if (retVal == MTD_STATUS_NO_ERROR)
        return 0;
    else
        return -1;
}
kal_int32 demp_ReadPhysicalPage(kal_uint32 PhyBlock, kal_uint32 PhyPage, void * Data) /*MAUI_00592819*/
{
    kal_uint8 zone_off;
    kal_uint16 b_arr[MAX_MULTIPAGE_NUM];
    kal_int32 NFBStatus = -1,k;
    static kal_uint32 zone_len = DWORD_INVALID;
    kal_bool old_use_interrupt;
#if !defined(__FUE__) && !defined(__UBL__) && defined(__NFB_ON_DEMAND_PAGE_IN__)
    extern kal_uint32 kal_get_mytask_priority(void);
    extern NAND_MTD_LOCK nfi_mtd_lock;
    kal_int32 task_index, prio;
#endif /* !__FUE__ && !__UBL__ */

    /* Confirmed by CC, demp_ReadPhysicalPage will 100% be called after NFB_ReadPhysicalPage, so dont care DAL init stage*/
    if (zone_len == DWORD_INVALID)
    {
        zone_len = (Flash_Info.CE_interleave_Flag == KAL_FALSE) ? zonePage(0) : zonePage(0) + zonePage(1);
    }
    /*calculate the DAL parameter*/
    zone_off = PhyBlock/zone_len;
    PhyBlock -= zone_off*zone_len;
    for (k=0;k< Flash_Info.bankNum; k++)
    {
        b_arr[k] = (PhyBlock/Flash_Info.bankNum);
    }
    PhyPage = PhyPage*Flash_Info.bankNum + PhyBlock%Flash_Info.bankNum ;
    /* Confirmed by CC, demp_ReadPhysicalPage don't need to check bad block because demp_CheckGoodBlock will be called to know bad blocks position*/
#if !defined(__FUE__) && !defined(__UBL__) && defined(__NFB_ON_DEMAND_PAGE_IN__)
    if(nfi_mtd_lock.owner_id != NULL){
        kal_trace(SYSTRACE_GROUP_DEMP, DEMP_PAGE_LOCK_TAKEN,
                  *(kal_int32*)(((NU_TASK*)(nfi_mtd_lock.owner_id))->tc_argc), nfi_mtd_lock.lock_count);
    }
    else {
        kal_trace(SYSTRACE_GROUP_DEMP, DEMP_PAGE_LOCK_AVAILABLE);
    }
#endif /* !__FUE__ && !__UBL__ */
    get_MTD_lock();		// Need to use lock to protect use_interrupt.
#if !defined(__FUE__) && !defined(__UBL__) && defined(__NFB_ON_DEMAND_PAGE_IN__)
    kal_get_my_task_index(&task_index);
    prio = kal_get_mytask_priority();
    kal_trace(SYSTRACE_GROUP_DEMP, DEMP_PAGE_GET_LOCK, task_index, prio);
#endif /* !__FUE__ && !__UBL__ */

	DemandPageingRead = KAL_TRUE;
	old_use_interrupt = use_interrupt;
    use_interrupt = KAL_FALSE;	// Need to set FALSE to avoid context switch. If context switch, FT task in META mode will be swtich out and L1Audio get control and assert.
    NFBStatus = DAL_ReadPage (CODE_ACC,zone_off,b_arr,PhyPage,1,Data,(kal_uint8*)NULL) & 0xffff0000; /*null spare buff point mean do not care spare data*/
    use_interrupt = old_use_interrupt;
    DemandPageingRead = KAL_FALSE;

#if !defined(__FUE__) && !defined(__UBL__) && defined(__NFB_ON_DEMAND_PAGE_IN__)
    prio = kal_get_mytask_priority();
    kal_trace(SYSTRACE_GROUP_DEMP, DEMP_PAGE_FREE_LOCK, task_index, prio);
#endif /* !__FUE__ && !__UBL__ */
    free_MTD_lock();

    if ( NFBStatus == MTD_STATUS_ERROR )
        return -1;
    else
        return Flash_Info.pageSize;
}


#endif /* _NAND_FLASH_BOOTING_ || (__UP_PKG_ON_NAND__ && NAND_SUPPORT) */

#if defined(__SECURITY_OTP__)&& defined(NAND_SUPPORT)

kal_int32 DAL_OTPAccess(kal_int32 accesstype, kal_uint32 Offset, void * BufferPtr, kal_uint32 Length)
{

	kal_int32 Status, PageAddr, AccessLength=0;
	kal_uint8 *BufAddr = (kal_uint8 *)BufferPtr;

	if (devDriver(0)->OTPAccess==NULL) {
		return FS_FLASH_OTP_UNKNOWERR;
	}

    if (DAL_is_initialized == 0) {
        Status = DAL_init();
        force_ASSERT(Status == FS_NO_ERROR, Status, 0, 0);
    }

    DAL_NAND_Reset();

    get_MTD_lock();


	while (1) {
	    PageAddr = Offset/Flash_Info.pageSize;
	    if (accesstype==FS_OTP_READ) {
			Status = devDriver(0)->OTPAccess(FS_OTP_READ, PageAddr, NFB_tmp_D_Buff, NFB_tmp_S_Buff);
			if (Status!=FS_NO_ERROR) {
				break;
			}
			AccessLength = Flash_Info.pageSize - (Offset % Flash_Info.pageSize);
			if (Length >= AccessLength) {
				kal_mem_cpy(BufAddr, ((kal_uint8*)NFB_tmp_D_Buff)+(Offset % Flash_Info.pageSize), AccessLength);
			} else {
				// Last time.
				kal_mem_cpy(BufAddr, ((kal_uint8*)NFB_tmp_D_Buff)+(Offset % Flash_Info.pageSize), Length);
			}
	    } else if (accesstype==FS_OTP_WRITE) {
	    	AccessLength = Flash_Info.pageSize - (Offset % Flash_Info.pageSize);
			kal_mem_set(NFB_tmp_D_Buff, 0xff, Flash_Info.pageSize);
			kal_mem_set(NFB_tmp_S_Buff, 0xff, Flash_Info.spareSize);
			if (Length >= AccessLength) {
				kal_mem_cpy(((kal_uint8*)NFB_tmp_D_Buff)+(Offset % Flash_Info.pageSize), BufAddr, AccessLength);
			} else {
				// Last time.
				kal_mem_cpy(((kal_uint8*)NFB_tmp_D_Buff)+(Offset % Flash_Info.pageSize), BufAddr, Length);
			}
			Status = devDriver(0)->OTPAccess(FS_OTP_WRITE, PageAddr, NFB_tmp_D_Buff, NFB_tmp_S_Buff);
	    } else {
			Status = devDriver(0)->OTPAccess(accesstype, PageAddr, NULL, NULL);
			break;
	    }

		Offset += AccessLength;
		BufAddr += AccessLength;
		if (Length <= AccessLength) {
			Length = 0;
			break;
		} else {
			Length -= AccessLength;
		}
	}
    free_MTD_lock();

	return Status;

}

kal_int32 DAL_OTPQueryLength(kal_uint32 *LengthPtr)
{
	kal_int32 Status;

	if (devDriver(0)->OTPQueryLength==NULL) {
		return FS_FLASH_OTP_UNKNOWERR;
	}

    if (DAL_is_initialized == 0) {
        Status = DAL_init();
        force_ASSERT(Status == FS_NO_ERROR, Status, 0, 0);
    }

    DAL_NAND_Reset();

    get_MTD_lock();
    Status = devDriver(0)->OTPQueryLength(LengthPtr);
    free_MTD_lock();

	return Status;
}

#else // __SECURITY_OTP__

kal_int32 DAL_OTPAccess(kal_int32 accesstype, kal_uint32 Offset, void * BufferPtr, kal_uint32 Length)
{
	return FS_UNSUPPORTED_DRIVER_FUNCTION;
}

kal_int32 DAL_OTPQueryLength(kal_uint32 *LengthPtr)
{
	return FS_UNSUPPORTED_DRIVER_FUNCTION;
}

#endif // __SECURITY_OTP__

kal_int32 DAL_GetDeviceIDInfo(void *pInfo)
{
	FS_DeviceInfo *DeviceInfo = (FS_DeviceInfo *)pInfo;
	kal_uint32 Index;
	for (Index=0; Index<8; Index++) {
		DeviceInfo->DeviceInfo.NAND.DeviceID[Index] = Flash_Info.deviceInfo_CE[0].ID_info[Index];
	}

	DeviceInfo->DeviceInfo.NAND.PageSize = Flash_Info.deviceInfo_CE[0].pageSize + Flash_Info.deviceInfo_CE[0].spareSize;
	DeviceInfo->DeviceInfo.NAND.BlockSize = Flash_Info.deviceInfo_CE[0].blockPage * DeviceInfo->DeviceInfo.NAND.PageSize;
	DeviceInfo->DeviceInfo.NAND.DeviceSize = Flash_Info.deviceInfo_CE[0].deviceSize + Flash_Info.deviceInfo_CE[1].deviceSize;
	return FS_NO_ERROR;
}
kal_uint32 DAL_GetBlockSize(void)
{
  return (Flash_Info.deviceInfo_CE[0].blockPage*Flash_Info.deviceInfo_CE[0].pageSize);
}
kal_uint32 DAL_GetPageSize(void)
{
  return (Flash_Info.deviceInfo_CE[0].pageSize);
}

kal_int32 DAL_LPage2PPage(DAL_ACC_Type Acc_Type, kal_uint8 ZoneNo, kal_uint16 *Bank, kal_uint16 PageAddr)
{
    //kal_uint8  m_idx = 0;
    //kal_uint8  bk_idx_ce;
    //kal_uint8  ce_idx = 0;
    kal_uint16  i;
    kal_uint32 retVal = MTD_STATUS_NO_ERROR;

    get_MTD_lock();
    #if defined (_NAND_FLASH_BOOTING_) || defined(__NANDFDM_MULTI_INSTANCE__) || (defined(__UP_PKG_ON_NAND__) && defined(NAND_SUPPORT))
    if (Acc_Type == FAT_ACC)
    {
        for (i=0;i< Flash_Info.bankNum; i++)
        {
#if defined(__NANDFDM_TOTAL_BBM__)
          if(Bank[i]&BBM_GLOBAL_ADDR)
          {
            DAL_Bank_Array[i] = Bank[i];
          }
          else
#endif //#if defined(__NANDFDM_TOTAL_BBM__)
	        if (ZoneNo == 0)
	        {
#if !defined(__NANDFDM_MULTI_INSTANCE__)
                DAL_Bank_Array[i] = Bank[i] + FAT_Start_Section_Offset;
#else // !defined(__NANDFDM_MULTI_INSTANCE__)
                DAL_Bank_Array[i] = Bank[i] + FAT_Start_Section_Offset[CurDiskIndex];
#endif // !defined(__NANDFDM_MULTI_INSTANCE__)
	        } else {
                DAL_Bank_Array[i] = Bank[i];
	        }
        }
        Bank = DAL_Bank_Array;
#if !defined(__NANDFDM_MULTI_INSTANCE__)
        ZoneNo += FAT_Start_ZoneNum;
#else  // !defined(__NANDFDM_MULTI_INSTANCE__)
        ZoneNo += FAT_Start_ZoneNum[CurDiskIndex];
#endif	// !defined(__NANDFDM_MULTI_INSTANCE__)
    }
    #else
    if (Acc_Type != FAT_ACC)
    {
        dbg_ASSERT(0);
        free_MTD_lock();
        return MTD_STATUS_PARA_ERROR;
    }
    #endif /* _NAND_FLASH_BOOTING_ || defined(__NANDFDM_MULTI_INSTANCE__) || (__UP_PKG_ON_NAND__ && NAND_SUPPORT)) */
    /*boundary check*/
    if ( (ZoneNo >= Flash_Info.zoneNum)  )
    {
        force_ASSERT(0,ZoneNo,0,0);
        free_MTD_lock();
        return MTD_STATUS_PARA_ERROR;
    }

    kal_mem_set(&Mtd_para, 0x00,sizeof(Mtd_para));
    Add_Cnvt.zoneNum = ZoneNo ;
    Add_Cnvt.bankArry = Bank;
    Add_Cnvt.pageIdx = PageAddr;
    addressMap(&Add_Cnvt);
    retVal = Add_Cnvt.phyPage; // Add_Cnvt.ce reserved for future use
    Mtd_para.ce = Add_Cnvt.ce;
    if (Flash_Info.deviceInfo_CE[Add_Cnvt.ce].deviceSize*1024*1024 <= Flash_Info.pageSize*Add_Cnvt.phyPage)
    {
      dbg_ASSERT (0);
      free_MTD_lock();
      return MTD_STATUS_PARA_ERROR;
    }
    free_MTD_lock();
    return retVal;
}
#endif /*( defined(__NAND_FDM_50__) && defined(__NFI_VERSION2__) )*/
