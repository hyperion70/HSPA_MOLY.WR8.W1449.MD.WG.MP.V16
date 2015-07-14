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
 *  NAND_MTD_FDM50.C
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This is a NAND Flash MTD driver for NAND FDM 5.0.
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
 *
 * removed!
 *
 * removed!
 * removed!
 *
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

/*******************************************************************************
 * Include Header Files
 *******************************************************************************/
#if defined __MTK_TARGET__
#include "kal_public_api.h" //MSBB change     #include "kal_release.h"
//RHR remove     #include "init.h"
    #include "reg_base.h"
//RHR remove     #include "isrentry.h"
    #include "intrCtrl.h"
//RHR remove     #include "fat_fs.h"
    #include "NAND_MTD_FDM50_internal.h"
    #include "dma_sw.h"
    #include "dma_hw.h"
    #include "drvpdn.h"
    #include "l1sm_public.h"
    #include "drv_comm.h"
    #include "drv_hisr.h"
    #include "NAND_DAL.h"
  	#include "NAND_DAL_internal.h"
// Add for RHR
    #include "cache_sw.h"
//RHR remove     #include "kal_non_specific_general_types.h"
    #include "cp15.h"
    #include "fs_errcode.h"
    #include "fs_type.h"
    #include "config_hw.h"
    #include "kal_public_api.h"
    #include "kal_general_types.h"
    #include "kal_public_defs.h"
	  #include "kal_trace.h"
    #include "kal_internal_api.h"
    #include "custom_scatstruct.h"
// Add for RHR
#if defined(__NFI_VERSION3_1__)
    #include "ECC_hw.h"
    #include "sync_data.h"
#endif // defined(__NFI_VERSION3_1__)
#if defined(_NAND_FLASH_BOOTING_) && defined(__NAND_MDL_APPEND__)
#include "combo_flash_defs.h"
#include "combo_flash_init.h"
#endif
    #include "flash_opt.h"
    #if defined(__AUDIO_DSP_LOWPOWER__)
    #include "audlp_exp.h"
    #endif
    #include "dcl.h"    
#elif defined(FLASH_DISKDRV_DEBUG) && !defined(__MTK_TARGET__) // PC Simulator
    #include <stdio.h>
//MSBB remove     #include "kal_non_specific_general_types.h"
    #include "fat_fs.h"
    #include "NAND_MTD_FDM50_internal.h"
    #include "NAND_DAL.h"
  	#include "NAND_DAL_internal.h"
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

    #define kal_retrieve_eg_events(a,b,c,d,e) do { } while (0);
    #define kal_query_systemInit() (KAL_FALSE)
    #define INT_QueryExceptionStatus() (KAL_FALSE)
#endif

#if ( defined(__NAND_FDM_50__) && (defined(__NFI_VERSION2__)||defined(__NFI_VERSION3_1__)) )

#if ( defined(ECC_BIT_ERROR_TEST) || defined(__EMULATE_NFB_BIT_ERROE__) )
extern kal_bool ECCDisable;
#endif // ( defined(ECC_BIT_ERROR_TEST) || defined(__EMULATE_NFB_BIT_ERROE__) )

#if ( defined(__NAND_FLASH_HARDWARE_TEST__) && defined(__MAUI_BASIC__) && !defined(__UBL__))

/*******************************************************************************
 * For NAND FDM Unit test and Device verification
 *******************************************************************************/
#if defined(FLASH_DISKDRV_DEBUG) && !defined(__MTK_TARGET__) // PC Simulator
#else
#include "us_timer.h"
extern kal_uint32 INT_GetCurrentTime(void);
void NANDTest_Reset(void);
extern kal_bool ResetInNextBusy;
extern kal_uint32 wSBusyTimeR, wEBusyTimeR, wTotalBusyTimeR, wTotalBusyNumR;
extern kal_uint32 wSBusTimeR, wEBusTimeR, wTotalBusTimeR, wTotalBusNumR, wSetDMATimeR;
extern kal_uint32 wSBusyTimeW, wEBusyTimeW, wTotalBusyTimeW, wTotalBusyNumW;
extern kal_uint32 wSBusTimeW, wEBusTimeW, wTotalBusTimeW, wTotalBusNumW;
extern kal_bool ProfileDetail;
#endif


/*
FDM_UT_Item ==  0  Basic test - MTD/DAL/FDM Layer Test
FDM_UT_Item ==  1  Stressing test - FDM Layer Test
*/

kal_uint8 FDM_UT_Item = 1;
kal_uint32 FDM_ERROR_BIT[8] = {0};


#endif // ( defined(__NAND_FLASH_HARDWARE_TEST__) && defined(__MAUI_BASIC__) && !defined(__UBL__))
#if defined __UBL__ /*bootloader case*/
extern void dbg_print(kal_char *fmt, ...);
#endif
/*
 ****** Definition of dbg_ASSERT and force_ASSERT ******
 dbg_ASSERT:
          - For basic load prevalidation use. The code is used for RD debug.
 force_ASSERT:
          - For normal check, if those parameters are incorrect, system will fail.
          - We expect it should be found in the earlier stage.
*/
#if ( defined(__NAND_FLASH_HARDWARE_TEST__) && defined(__MAUI_BASIC__))
    #if defined __UBL__ /*bootloader case*/
        #if defined BL_DEBUG
            #define dbg_ASSERT(expr) {if(!(expr)) {dbg_print("dbg_ASSERT:%s line:%d\n",__FILE__,__LINE__);while(1); }}
        #else
            #define dbg_ASSERT(expr) {do { } while (0);}
        #endif
    #else
        #define dbg_ASSERT(expr) ASSERT(expr)
    #endif
#else
    #if defined __UBL__ /*bootloader case*/
        #if defined BL_DEBUG
            #define dbg_ASSERT(expr) {if(!(expr)) {dbg_print("dbg_ASSERT:%s line:%d\n",__FILE__,__LINE__);while(1); }}
        #else
            #define dbg_ASSERT(expr) {do { } while (0);}
        #endif
    #else
        #define dbg_ASSERT(expr) {do { } while (0);}
    #endif
#endif

#if defined __UBL__ /*bootloader case*/
    #define force_ASSERT(expr, e1, e2, e3) {if(!(expr)) {dbg_print("force_ASSERT:%s line:%d e1:%d,e2:%d,e3:%d\n",__FILE__,__LINE__, e1, e2, e3);while(1);}}
#else
    #define force_ASSERT(expr, e1, e2, e3) {EXT_ASSERT(expr, e1, e2, e3);}
#endif
#define NFI_SLEEP_MODE_INVALID_HANDLE 0xFF
static kal_uint8 NFI_sm_handler = NFI_SLEEP_MODE_INVALID_HANDLE;

/*******************************************************************************/
void pdn_nfi(kal_bool ON)
{
#if (defined __UBL__) || (defined __FUE__)
    /*NFI should be power on at bootload and fota case*/
#elif defined(FLASH_DISKDRV_DEBUG) && !defined(__MTK_TARGET__)
    /*Do nothing*/
#else
    if (ON)
    {
        // dbg_print("turn on MSDC\r\n");
        #if defined(__OLD_PDN_ARCH__)
        #if (!defined (MT6268A) && !defined (MT6268) && !defined(MT6516)) || (defined(__OLD_PDN_DEFINE__)) 
        DRVPDN_Disable(DRVPDN_CON1,DRVPDN_CON1_NFI,PDN_NFI);
        #elif (defined (MT6268A) || defined (MT6268) || defined(MT6516)) && (defined(__CLKG_DEFINE__))
	        #if (defined (MT6268A) || defined (MT6268))
	        DRVPDN_Disable(CG_CON1,CG_CON1_NFI,PDN_NFI);
	        #else
	        DRVPDN_Disable(CG_CON0,CG_CON0_NFI,PDN_NFI);
	        #endif        
        #else
            #error "Unknown power down control register"
        #endif 
        #else   /* __OLD_PDN_ARCH__ */
        if(NFI_sm_handler==NFI_SLEEP_MODE_INVALID_HANDLE)
        {
        	NFI_sm_handler = L1SM_GetHandle();
        }        
			  PDN_CLR(PDN_NFI); 
				L1SM_SleepDisable(NFI_sm_handler); //lock sleep mode
        #endif  /* __OLD_PDN_ARCH__ */            
     }
    else
    {
        // dbg_print("turn off NFI\r\n");
        #if defined(__OLD_PDN_ARCH__)
        #if (!defined (MT6268A) && !defined (MT6268) && !defined(MT6516)) || (defined(__OLD_PDN_DEFINE__))/*MAUI_00757139*/
        DRVPDN_Enable(DRVPDN_CON1,DRVPDN_CON1_NFI,PDN_NFI);
        #elif (defined (MT6268A) || defined (MT6268) || defined(MT6516)) && (defined(__CLKG_DEFINE__))
 	        #if (defined (MT6268A) || defined (MT6268))
	        DRVPDN_Enable (CG_CON1,CG_CON1_NFI,PDN_NFI);
	        #else
	        DRVPDN_Enable (CG_CON0,CG_CON0_NFI,PDN_NFI);
	        #endif 
        
        #else
            #error "Unknown power down control register"
        #endif      
        #else   /* __OLD_PDN_ARCH__ */
        if(NFI_sm_handler==NFI_SLEEP_MODE_INVALID_HANDLE)
        {
        	NFI_sm_handler = L1SM_GetHandle();
        }        
				PDN_SET(PDN_NFI); //power down dev
				L1SM_SleepEnable(NFI_sm_handler);  //unlock sleep mode                       
        #endif  /* __OLD_PDN_ARCH__ */     
    }
#endif        
}
// Check NFI driver is necessary or not
// Re-define compile option to sync
#if defined(MT6280)
  #if defined(__TRADITIONAL_MODEM_CARD__)  
		#define __USE_NFI_MTD_DRIVER__
	#elif defined(__NAND_DRV_IN_BL__)
	  #define __USE_NFI_MTD_DRIVER__
	#endif
#elif (!((defined(MT6573)||defined(MT6575))&& !defined(__SMART_MD_NFI_DRIVER__)))
	#define __USE_NFI_MTD_DRIVER__
#endif



// This function is only called by init to solve the issue which bootROM does not reset NFI.
// There is no need to call this function when NAND_SUPPORT is TRUE because MTD layer will be called.
void NFI_Reset(void)
{
#if defined(__USE_NFI_MTD_DRIVER__)
#if !defined(NAND_SUPPORT)
    pdn_nfi(KAL_TRUE);

#if defined(__NFI_VERSION3_1__)

   while(0 != DRV_Reg(NFI_MASTERSTA));

   *NFI_CON = CON_FIFO_FLUSH|CON_NFI_RST;
   while( (*NFI_STA & (STA_NFI_FSM_MASK|STA_NAND_FSM_MASK)) );

#elif defined(__NFI_VERSION2__)

    *NFI_CON=0x0;
    *NFI_OPCON = OPCON_RESET;
    while( (*NFI_PSTA& (~0x0300) ) );

#else

    *NFI_FIFOCON = RESET;
    *NFI_OPCON = 0;
    *NFI_CON = 0;

#endif /*__NFI_VERSION2__*/

    pdn_nfi(KAL_FALSE);

#endif  // !defined(NAND_SUPPORT)

#endif
}

#if defined(__USE_NFI_MTD_DRIVER__)

// ===========================================================
//     External reference declaration
// ===========================================================

#if defined(__MTK_TARGET__)

extern kal_bool INT_QueryExceptionStatus(void);

#endif // defined(__MTK_TARGET__)

extern kal_uint8 NFI_GPIO_Setting(void);

extern char NAND_text_buff[100]; /*For debug message*/
extern const kal_uint8 ZEROBIT[256];
#if defined(FLASH_DISKDRV_DEBUG) && !defined(__MTK_TARGET__)
    extern flash_list NAND_ID_Table[];
#else
	extern const flash_list NAND_ID_Table[];
#endif
extern flash_info_2 Flash_Info;
extern flash_list Default_ID_Table;
extern const kal_uint8 ID_512_Mask[8];
extern const kal_uint8 ID_2K_Mask[8];

// ===========================================================
//     Function declaration
// ===========================================================

kal_uint32 writefifo (nAND_Cmd_info* info);
void pagefmt_config(kal_uint8 IOWidth, kal_uint16 pageSize, kal_uint16 spare_size);

// ===========================================================
//     Global variable
// ===========================================================

#if defined(FLASH_DISKDRV_DEBUG) && !defined(__MTK_TARGET__) // PC Simulator
    char* file_name[2];
    void* file_hd[2];
    kal_uint8 user_def_cs_num;
    kal_uint32 user_def_id_data[2][2];/*2 CS, each need 2 DWORD size to describe*/
    kal_uint8 cur_CS;
    kal_uint32 DummyNFI_Reg[1]; /*For simulator*/
    kal_uint8 MTD_simu_buff[(4096+256)];
    const kal_uint32 DummyNFI_PSTA[1] = {0};
    #define PDN_CON0 ((volatile kal_uint16 *)(DummyNFI_Reg))  /*For simulator*/
    #define NFI_PSTA      ((volatile UINT32P)(DummyNFI_PSTA)) /*always return ready*/
    //simulation test
    static unsigned int PageWriteError, SpareWriteError, EraseError, PageReadError, SpareReadError;
#endif

#define NFI_EVENT   0x1
#if defined __MTK_TARGET__

#if !defined(__NFI_VERSION3_1__)
static DMA_FULLSIZE_HWMENU nfi_menu;
static kal_uint8       nfi_dmaport;
static DMA_INPUT       nfi_input;
#endif

#endif  // defined __MTK_TARGET__

#if (defined __UBL__)||(defined __FUE__)
#else // (defined __UBL__)||(defined __FUE__)
static kal_eventgrpid  nfi_egid = NULL;
#endif // (defined __UBL__)||(defined __FUE__)

static kal_bool is_initialized = KAL_FALSE;
static kal_uint8 CS_num = 1;

#if defined(__NFI_VERSION2__)
/*for readfifo*/
static kal_uint32 tmp_spare[64/sizeof(kal_uint32)];
/*for readfifo*/
#endif

//  Declaration for NAND flash booting

#if defined(_NAND_FLASH_BOOTING_) || defined(__NANDFDM_MULTI_INSTANCE__) || (defined(__UP_PKG_ON_NAND__) && defined(NAND_SUPPORT))

kal_uint32 NFB_FLASH_BASE_PAGE;
kal_int32                  NFBPageSize;
#if !defined(__NANDFDM_MULTI_INSTANCE__)
extern const kal_uint32   NFB_BASE_ADDRESS;
extern const kal_uint32 NFB_ALLOCATED_FAT_SPACE;
#else  // !defined(__NANDFDM_MULTI_INSTANCE__)
extern kal_uint32   NFB_BASE_ADDRESS[NAND_DISK_NUM];
extern kal_uint32 NFB_ALLOCATED_FAT_SPACE[NAND_DISK_NUM];
extern kal_uint8 CurDiskIndex;
#endif  // !defined(__NANDFDM_MULTI_INSTANCE__)
extern kal_bool DemandPageingRead;

#endif  // _NAND_FLASH_BOOTING_ || defined(__NANDFDM_MULTI_INSTANCE__) || (__UP_PKG_ON_NAND__ && NAND_SUPPORT)

#if defined DAL_VERIFICATION
extern kal_uint8 Mtd_Fail_Offset;
#endif

// For NAND flash booting
kal_bool use_interrupt;  // KAL_TRUE for using interrupt; KAL_FALSE for using polling

static nAND_Cmd_info Cmd_info;
mtd_if_para Mtd_para;
#if defined(__COMBO_MEMORY_SUPPORT__)
kal_uint8 ComboNANDID[8];
#endif
#if defined(_NAND_FLASH_BOOTING_) && defined(__NAND_MDL_APPEND__)
kal_bool bNAND_mdl_support;
#endif

#if !defined(__FUE__)

NAND_MTD_LOCK nfi_mtd_lock = {0, NULL, NULL};

// ===========================================================
//     Function definition
// ===========================================================

void init_MTD_lock(void)
{
    #if defined __UBL__ /*bootloader case*/
    #elif defined(FLASH_DISKDRV_DEBUG) && !defined(__MTK_TARGET__) /*PC simulator*/
    #else
    if (nfi_mtd_lock.mtd_enhmutex == NULL)
    {
        nfi_mtd_lock.mtd_enhmutex = kal_create_enh_mutex("MTD_NFI_LOCK");
        nfi_mtd_lock.lock_count = 0;
        nfi_mtd_lock.owner_id = NULL;
    }
    #endif
}

void get_MTD_lock(void)
{
    #if defined __UBL__ /*bootloader case*/
    /*Do nothing*/
    #elif defined(FLASH_DISKDRV_DEBUG) && !defined(__MTK_TARGET__) /*PC simulator*/
    /*Do nothing*/
    #else
    //kal_uint32 mask = 0;/*Remove unnecessary disable IRQ 2007/05/24 Yehudi Chang*/
    if( kal_query_systemInit() || INT_QueryExceptionStatus() )
        return;
    //mask = SaveAndSetIRQMask();/*Remove unnecessary disable IRQ 2007/05/24 Yehudi Chang*/
    if (kal_if_hisr() == KAL_TRUE || kal_if_lisr() == KAL_TRUE) /*MAUI_00756114*/
    {
        kal_uint32 retaddr0=0;
				#if defined(__MTK_TARGET__)
					#if defined(__ARMCC_VERSION)
						retaddr0 = (kal_uint32)__return_address();
					#elif defined(__GNUC__) 
						retaddr0 = (kal_uint32)__builtin_return_address(0);
					#endif /* __RVCT__ , __GNUC__ */         
				#endif  /* __MTK_TARGET__ */		
        EXT_ASSERT(0, retaddr0, 0, 0);
    }
    // start of kuohong MP3
#if defined(__AUDIO_DSP_LOWPOWER__)
    AUDMA_LOCK(AUDMA_ID_NFI);
#endif
    // end of kuohong MP3
    if( kal_get_current_task() == nfi_mtd_lock.owner_id )
    {
        force_ASSERT(0 != nfi_mtd_lock.lock_count, nfi_mtd_lock.lock_count, (kal_uint32)nfi_mtd_lock.owner_id, (kal_uint32)nfi_mtd_lock.mtd_enhmutex);
        nfi_mtd_lock.lock_count++;
        //RestoreIRQMask(mask);/*Remove unnecessary disable IRQ 2007/05/24 Yehudi Chang*/
    }
    else
    {
        if(nfi_mtd_lock.mtd_enhmutex == NULL)
        {
              init_MTD_lock();
        }
        //RestoreIRQMask(mask);/*Remove unnecessary disable IRQ 2007/05/24 Yehudi Chang*/
        kal_take_enh_mutex(nfi_mtd_lock.mtd_enhmutex);
        nfi_mtd_lock.owner_id = kal_get_current_task();
        nfi_mtd_lock.lock_count++;
    }
    #endif
}

void free_MTD_lock(void)
{
    #if defined __UBL__ /*bootloader case*/
    /*Do nothing*/
    #elif defined(FLASH_DISKDRV_DEBUG) && !defined(__MTK_TARGET__) /*PC simulator*/
    /*Do nothing*/
    #else
    //kal_uint32 mask = 0;/*Remove unnecessary disable IRQ 2007/05/24 Yehudi Chang*/
    if( kal_query_systemInit() || INT_QueryExceptionStatus() )
        return;
    //mask = SaveAndSetIRQMask();/*Remove unnecessary disable IRQ 2007/05/24 Yehudi Chang*/
#if defined(__AUDIO_DSP_LOWPOWER__)
    // start of kuohong MP3
    AUDMA_UNLOCK(AUDMA_ID_NFI);
    // end of kuohong MP3
#endif
    if( kal_get_current_task() == nfi_mtd_lock.owner_id )
    {
        force_ASSERT(nfi_mtd_lock.lock_count > 0, nfi_mtd_lock.lock_count, (kal_uint32)nfi_mtd_lock.owner_id, (kal_uint32)nfi_mtd_lock.mtd_enhmutex);
        nfi_mtd_lock.lock_count--;
        if(0 == nfi_mtd_lock.lock_count)
        {
            nfi_mtd_lock.owner_id = NULL;
            //RestoreIRQMask(mask);/*Remove unnecessary disable IRQ 2007/05/24 Yehudi Chang*/
            if(nfi_mtd_lock.mtd_enhmutex != NULL)
            {
              kal_give_enh_mutex(nfi_mtd_lock.mtd_enhmutex);
            }
        }
        //else /*Remove unnecessary disable IRQ 2007/05/24 Yehudi Chang*/
            //RestoreIRQMask(mask);/*Remove unnecessary disable IRQ 2007/05/24 Yehudi Chang*/
    }
    else
    {
        //RestoreIRQMask(mask);/*Remove unnecessary disable IRQ 2007/05/24 Yehudi Chang*/
        force_ASSERT(0, (kal_uint32)nfi_mtd_lock.owner_id, (kal_uint32)kal_get_current_task(), (kal_uint32)nfi_mtd_lock.mtd_enhmutex);
    }
    #endif
}

#else /* !defined(__FUE__) */

#define init_MTD_lock()

#define get_MTD_lock()

#define free_MTD_lock()

#endif /* !defined(__FUE__) */

/*******************************************************************************
 *  NFI bus semaphore
 *******************************************************************************/
/*Extend the NFI semaphore to all MTD API, merge to MTD lock 2007/05/08 Yehudi Chang - start*/
void get_NFI_bus(void)
{
    get_MTD_lock();
}

void free_NFI_bus(void)
{
    free_MTD_lock();
}
/*Extend the NFI semaphore to all MTD API, merge to MTD lock 2007/05/08 Yehudi Chang - End*/

#if ( defined(__NAND_FLASH_HARDWARE_TEST__) && defined(__MAUI_BASIC__) && !defined(__UBL__))
void dump_memory_to_uart_log(kal_uint32* buff, kal_uint32 leng)
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
#endif	
}
#endif

/****************************************************************************
 * Function:    send_command_add_data
 *
 * Parameters:  info                 command length, address, data information
 *
 * Returns:
 *
 * Description: It will send: cmd1, add, data, cmd2 to NAND
 *
 ****************************************************************************/
static __NAND_INLINE void send_command_add_data (kal_uint8 cmd1,kal_uint8 cmd2, nAND_Cmd_info* info )
{
    dbg_ASSERT(info->cmd_len == 2);
#if defined(__NFI_VERSION3_1__)
    *NFI_CMD = cmd1;
	while ((*NFI_STA) & STA_CMD_STATE);
	*NFI_COLADDR = info->add[0];
	*NFI_ROWADDR = info->add[1];
	if (Flash_Info.pageSize == 512) {
		*NFI_ADDRNOB = 1 | ((info->add_cycle-1)<<ADDR_ROW_NOB_SHIFT);
	} else {
		*NFI_ADDRNOB = 2 | ((info->add_cycle-2)<<ADDR_ROW_NOB_SHIFT);
	}
	while ((*NFI_STA) & STA_ADDR_STATE);
	writefifo(info);
    if ( info->intFlag != 0) {
        *NFI_INTR_EN = info->intFlag;
    }
	*NFI_CMD = cmd2;
	while ((*NFI_STA) & STA_CMD_STATE);
#else // defined(__NFI_VERSION3_1__)
    *NFI_CMD = cmd1;
    while (*NFI_PSTA & STATUS_CMD);
    *NFI_ADDRL = info->add[0];
    if (info->add_cycle > 4 )
        *NFI_ADDRM = info->add[1];
    *NFI_ADDNOB = info->add_cycle;
    while (*NFI_PSTA & STATUS_ADDR);
    writefifo(info);
    if ( info->intFlag != 0)
        *NFI_INTR_EN = info->intFlag;
    *NFI_CMD = cmd2;
    while (*NFI_PSTA & STATUS_CMD);
#endif // defined(__NFI_VERSION3_1__)
}

/****************************************************************************
 * Function:    send_command_add
 *
 * Parameters:  info                 command length, address, data information
 *
 * Returns:
 *
 * Description: It will send: cmd1, add, cmd2 to NAND
 *
 ****************************************************************************/
static __NAND_INLINE void send_command_add (kal_uint8 cmd1,kal_uint8 cmd2, nAND_Cmd_info* info )
{
    dbg_ASSERT(info->cmd_len <= 2);
#if defined(__NFI_VERSION3_1__)
    *NFI_CMD = cmd1;
	while ((*NFI_STA) & STA_CMD_STATE);
	*NFI_COLADDR = info->add[0];
	*NFI_ROWADDR = info->add[1];
	if (Flash_Info.pageSize == 512) {
		*NFI_ADDRNOB = 1 | ((info->add_cycle-1)<<ADDR_ROW_NOB_SHIFT);
	} else {
		*NFI_ADDRNOB = 2 | ((info->add_cycle-2)<<ADDR_ROW_NOB_SHIFT);
	}
	while ((*NFI_STA) & STA_ADDR_STATE);
    if ( info->intFlag != 0) {
        *NFI_INTR_EN = info->intFlag;
    }
    if ( info->cmd_len > 1) {
        *NFI_CMD = cmd2;
		while ((*NFI_STA) & STA_CMD_STATE);
    }
#else
    *NFI_CMD = cmd1;
    while (*NFI_PSTA & STATUS_CMD);
    *NFI_ADDRL = info->add[0];
    if (info->add_cycle > 4 )
        *NFI_ADDRM = info->add[1];
    *NFI_ADDNOB = info->add_cycle;
    while (*NFI_PSTA & STATUS_ADDR);
    if ( info->intFlag != 0)
        *NFI_INTR_EN = info->intFlag;
    if ( info->cmd_len > 1)
        *NFI_CMD = cmd2;
    while (*NFI_PSTA & STATUS_CMD);
#endif

#if defined(FLASH_DISKDRV_DEBUG) && !defined(__MTK_TARGET__)
/*Handle erase behavior in simulator case here*/
    if ( cmd1 == 0x60) /*erase command*/
    {
        int i,  size;
        fseek(file_hd[cur_CS], info->add[0]*(Flash_Info.pageSize+Flash_Info.spareSize), SEEK_SET);
        kal_mem_set(MTD_simu_buff, 0xFF, sizeof(MTD_simu_buff));
        for (i=0; i<Flash_Info.blockPage; i++)
        {
            fwrite(MTD_simu_buff, sizeof(char), (Flash_Info.pageSize+Flash_Info.spareSize), file_hd[cur_CS]);
        }
        fflush(file_hd[cur_CS]);
    }

#endif
}

#if defined(__NFI_VERSION3_1__)

static __NAND_INLINE void send_command_rowadd (kal_uint8 cmd1,kal_uint8 cmd2, nAND_Cmd_info* info )
{
    dbg_ASSERT(info->cmd_len <= 2);
    *NFI_CMD = cmd1;
	while ((*NFI_STA) & STA_CMD_STATE);
	*NFI_COLADDR = 0;
	*NFI_ROWADDR = info->add[0];
	*NFI_ADDRNOB = ((info->add_cycle)<<ADDR_ROW_NOB_SHIFT);
	while ((*NFI_STA) & STA_ADDR_STATE);
    if ( info->intFlag != 0) {
        *NFI_INTR_EN = info->intFlag;
    }
    if ( info->cmd_len > 1) {
        *NFI_CMD = cmd2;
		while ((*NFI_STA) & STA_CMD_STATE);
    }

#if defined(FLASH_DISKDRV_DEBUG) && !defined(__MTK_TARGET__)
/*Handle erase behavior in simulator case here*/
    if ( cmd1 == 0x60) /*erase command*/
    {
        int i,  size;
        fseek(file_hd[cur_CS], info->add[0]*(Flash_Info.pageSize+Flash_Info.spareSize), SEEK_SET);
        kal_mem_set(MTD_simu_buff, 0xFF, sizeof(MTD_simu_buff));
        for (i=0; i<Flash_Info.blockPage; i++)
        {
            fwrite(MTD_simu_buff, sizeof(char), (Flash_Info.pageSize+Flash_Info.spareSize), file_hd[cur_CS]);
        }
        fflush(file_hd[cur_CS]);
    }

#endif
}

#endif // #if defined(__NFI_VERSION3_1__)


static __NAND_INLINE void NFI_OP_RESET (void)
{
#if defined(__NFI_VERSION3_1__)
   while(0 != DRV_Reg(NFI_MASTERSTA));

   *NFI_CON = CON_FIFO_FLUSH|CON_NFI_RST;
   while( (*NFI_STA & (STA_NFI_FSM_MASK|STA_NAND_FSM_MASK)) );
#elif defined(__NFI_VERSION2__)
    *NFI_CON=0x0;
    *NFI_OPCON = OPCON_RESET;
    while( (*NFI_PSTA& (~0x0300) ) ); /*Except device busy status*/
#else
    *NFI_FIFOCON = RESET;
    *NFI_OPCON = 0;
    *NFI_CON = 0;
#endif /*__NFI_VERSION2__*/
}


kal_uint8 read_status(kal_uint8 cmd1, nAND_Cmd_info* info )
{
#if defined(FLASH_DISKDRV_DEBUG) && !defined(__MTK_TARGET__)
    return(kal_uint8)(0xE0); /*always ready and success in simulator case*/
#else
     NFI_OP_RESET();

#if defined(__NFI_VERSION3_1__)
	*NFI_CNFG = CNFG_OP_SRD|CNFG_READ_EN;
    *NFI_CMD = cmd1;
	while ((*NFI_STA) & STA_CMD_STATE);

    if (info->add_cycle)
    {
		*NFI_COLADDR = 0;
		*NFI_ROWADDR = info->add[0];
		*NFI_ADDRNOB = (info->add_cycle << ADDR_ROW_NOB_SHIFT);
		while ((*NFI_STA) & STA_ADDR_STATE);
    }
	*NFI_CON = ((1 << CON_NFI_NOB_SHIFT)|CON_NFI_SRD);
	while( !FIFO_PIO_READY(*NFI_PIO_DIRDY) );

#else
    *NFI_CMD = cmd1;
    while (*NFI_PSTA & STATUS_CMD);

    if (info->add_cycle)
    {
        *NFI_ADDRL = info->add[0];
        if (info->add_cycle > 4 )
            *NFI_ADDRM = info->add[1];
        *NFI_ADDNOB = info->add_cycle;
        while (*NFI_PSTA & STATUS_ADDR);
    }

    *NFI_OPCON = (NOB_BYTE | SINGLE_RD);
    while (*NFI_PSTA & STATUS_DATAR);
#endif

    return(kal_uint8)(*NFI_DATAR);
#endif
} /*  End of read_status */

#if 0
/* under construction !*/
#endif

#if defined(__NFI_VERSION3_1__)

// Description :
//		Only support two modes here.
//		1. DMA mode + auto-FMT + ECC.
//		2. MCU mode + auto-FMT + ECC.
kal_uint32 writefifo (nAND_Cmd_info* info)
{
#if defined(FLASH_DISKDRV_DEBUG) && !defined(__MTK_TARGET__)
    int i,  size;
    if ( Flash_Info.pageSize == 512)
    {
        fseek(file_hd[cur_CS], (info->add[0]>>8)*(Flash_Info.pageSize+Flash_Info.spareSize), SEEK_SET);
    }
    else
    {
        fseek(file_hd[cur_CS], ((info->add[1]<<16)|(info->add[0]>>16))*(Flash_Info.pageSize+Flash_Info.spareSize) , SEEK_SET);
    }
    size = fread(MTD_simu_buff, sizeof(char), Flash_Info.pageSize + Flash_Info.spareSize, file_hd[cur_CS]);
    ASSERT(size == Flash_Info.pageSize + Flash_Info.spareSize);

    /* Add Flash property  only 1->0*/
    if ( ((kal_uint32)info->buff) != NULL )
    {
        for(i=0; i<Flash_Info.pageSize; i++)
           MTD_simu_buff[i] &= info->buff[i];
    }
    if ( ((kal_uint32)info->spare) != NULL )
    {
        for(i=0; i<Flash_Info.spareSize; i++)
           MTD_simu_buff[ Flash_Info.pageSize + i ] &= info->spare[i];
    }

    if ( Flash_Info.pageSize == 512)
    {
        fseek(file_hd[cur_CS], (info->add[0]>>8)*(Flash_Info.pageSize+Flash_Info.spareSize), SEEK_SET);
    }
    else
    {
        fseek(file_hd[cur_CS], ((info->add[1]<<16)|(info->add[0]>>16))*(Flash_Info.pageSize+Flash_Info.spareSize) , SEEK_SET);
    }

    size = fwrite(MTD_simu_buff, sizeof(char), Flash_Info.pageSize + Flash_Info.spareSize, file_hd[cur_CS]);
    ASSERT(size == Flash_Info.pageSize + Flash_Info.spareSize);

    fflush(file_hd[cur_CS]);
    return MTD_STATUS_NO_ERROR;
#else
    kal_uint16 byte_rw_flag;
    kal_uint32 SecNo, Index;
    kal_uint16 flag_ECC;
    kal_uint8  FLAG_DMA;
    kal_uint8  SecNum = Flash_Info.pageSize>>9;
		#if (defined __UBL__) || (defined __FUE__) 
		#else
    	kal_uint32 event_group;    
    #endif

    if ( ((kal_uint32)info->buff)%4 == 0 && ((kal_uint32)info->buff_len)%4 == 0 )
    {
        byte_rw_flag = 0;
    }
    else
    {
        byte_rw_flag = BYTE_RW_EN;
    }

	// Only support auto-FMT now. So set FDM data here.
	if ( ((kal_uint32)info->spare) != 0 )
	{
		// Currently only support 8 bytes FDM data.
	    if ( ((kal_uint32)info->spare)%4 == 0 && ((kal_uint32)info->spare_len)%4 == 0 )
	    {
	    	// 4 bytes aligned.
           	for(SecNo = 0 ; SecNo < SecNum ; SecNo++)
           	{
           		kal_uint32* u32_spare = (kal_uint32*)&(info->spare[SecNo << 4]);

              	*(volatile unsigned int *)(NFI_FDM0L+(SecNo<<1)) = u32_spare[0];
              	*(volatile unsigned int *)(NFI_FDM0L+(SecNo<<1)+1) = u32_spare[1];
           	}
	    }
	    else
	    {
	    	// non 4 bytes aligned.
           	for(SecNo = 0 ; SecNo < SecNum ; SecNo++)
           	{
           		kal_uint32 TempVal;

           		TempVal = (info->spare[(SecNo<<4) + 3] << 24) +
           			      (info->spare[(SecNo<<4) + 2] << 16) +
           			      (info->spare[(SecNo<<4) + 1] <<  8) +
           			      (info->spare[(SecNo<<4) + 0]);
               	*(volatile unsigned int *)(NFI_FDM0L+(SecNo<<1)) = TempVal;

           		TempVal = (info->spare[(SecNo<<4) + 7] << 24) +
           			      (info->spare[(SecNo<<4) + 6] << 16) +
           			      (info->spare[(SecNo<<4) + 5] <<  8) +
           			      (info->spare[(SecNo<<4) + 4]);
              	*(volatile unsigned int *)(NFI_FDM0L+(SecNo<<1)+1) = TempVal;
           	}
	    }
	}

	#if (defined __FUE__)
	if ( 1 )
	#else // (defined __FUE__)
    if ( ((kal_uint32)info->buff) != 0 )
	#endif // (defined __FUE__)
    {
        #if (defined __UBL__) || (defined __FUE__) /*bootloader case always use MCU mode*/
        FLAG_DMA = 0;
        #else
        FLAG_DMA = (INT_QueryIsNonCachedRAM(info->buff, info->buff_len) != 0) ? 1:0;
        #endif

		#if ( defined(__NAND_FLASH_HARDWARE_TEST__) && defined(__MAUI_BASIC__) && !defined(__UBL__))
		if ((ProfileDetail==KAL_TRUE) && (FDM_UT_Item==10)) {
			wSBusTimeW = ust_get_current_time();
			wTotalBusNumW++;
		}
		#endif // ( defined(__NAND_FLASH_HARDWARE_TEST__) && defined(__MAUI_BASIC__) && !defined(__UBL__))

        if (FLAG_DMA == 0) /*move data by MCU*/
        {
			#if ( defined(ECC_BIT_ERROR_TEST) || defined(__EMULATE_NFB_BIT_ERROE__) )
	        if ((info->ECCFlag != ECC_SKIP) && !ECCDisable)
			#else // ( defined(ECC_BIT_ERROR_TEST) || defined(__EMULATE_NFB_BIT_ERROE__) )
	        if(info->ECCFlag != ECC_SKIP)
			#endif // ( defined(ECC_BIT_ERROR_TEST) || defined(__EMULATE_NFB_BIT_ERROE__) )
			{
	            flag_ECC = CNFG_HW_ECC_EN;
	            *ECC_ENCCNFG = ECC_CNFG_META8 | ECC_CNFG_NFI;
#if defined(__ECC_8_BIT_SUPPORT__)
				if(*NFI_PAGEFMT & (PAGEFMT_SPARE_26<<4))
				{
					*ECC_ENCCNFG = ECC_CNFG_META8 | ECC_CNFG_NFI | ECC_CNFG_ECC8;
				}
#endif		
	            START_ECC_ENC;
			}
	        else
	        {
	            flag_ECC = 0;
	        }
	        *NFI_CNFG |= (byte_rw_flag | flag_ECC);
       		*NFI_CON |= CON_NFI_BWR; // set burst write
	        if (info->CustomMode)
	        {
      			*NFI_STRDATA = 0x1;
	        }

           	for(SecNo = 0; SecNo < SecNum; SecNo++)
           	{
	            if (byte_rw_flag)
	            {
	                for (Index=0; Index<NAND_SECTOR_SIZE; Index++)
	                {
	                    while( !FIFO_PIO_READY(*NFI_PIO_DIRDY) );
	                    *NFI_DATAW = info->buff[(SecNo<<NAND_SECTOR_SHIFT) + Index];
	                }
	            }
	            else
	            {
	                for (Index=0; Index<(NAND_SECTOR_SIZE>>2); Index++)
	                {
	                    while( !FIFO_PIO_READY(*NFI_PIO_DIRDY) );
	                    *NFI_DATAW = ((kal_uint32*)info->buff)[(SecNo<<(NAND_SECTOR_SHIFT-2)) + Index];
	                }
	            }
           	}
        }
        else /*move data by DMA*/
        {
        	#if (defined __UBL__) || (defined __FUE__) /*bootloader case always use MCU mode*/

            force_ASSERT(0,0,0,0);

	        #else // (defined __UBL__) || (defined __FUE__)

	        #if defined __MTK_TARGET__

	        Data_Mem_Barrier();	// Force all memory write had done before data transfer in ARM11.

			#endif  // defined __MTK_TARGET__

			#if ( defined(ECC_BIT_ERROR_TEST) || defined(__EMULATE_NFB_BIT_ERROE__) )
	        if ((info->ECCFlag != ECC_SKIP) && !ECCDisable)
			#else // ( defined(ECC_BIT_ERROR_TEST) || defined(__EMULATE_NFB_BIT_ERROE__) )
	        if(info->ECCFlag != ECC_SKIP)
			#endif // ( defined(ECC_BIT_ERROR_TEST) || defined(__EMULATE_NFB_BIT_ERROE__) )
			{
	            flag_ECC = CNFG_HW_ECC_EN;
	            *ECC_ENCCNFG = ECC_CNFG_META8 | ECC_CNFG_NFI;
#if defined(__ECC_8_BIT_SUPPORT__)
				if(*NFI_PAGEFMT & (PAGEFMT_SPARE_26<<4))
				{
					*ECC_ENCCNFG = ECC_CNFG_META8 | ECC_CNFG_NFI | ECC_CNFG_ECC8;
				}
#endif				
    	        START_ECC_ENC;
	        }
	        else
	        {
	            flag_ECC = 0;
	        }
	        #if (defined __UBL__)||(defined __FUE__)
	        #else
            if (nfi_egid && use_interrupt == KAL_TRUE) {
            	*NFI_INTR_EN = AHB_DONE_EN;
            }
					#endif
			*NFI_STRADDR = (kal_uint32)(info->buff);
			*NFI_CNFG |= (byte_rw_flag | flag_ECC | CNFG_DMA | CNFG_DMA_BURST_EN);
       		*NFI_CON |= CON_NFI_BWR; // set burst write
	        if (info->CustomMode)
	        {
      			*NFI_STRDATA = 0x1;
	        }
	        #if (defined __UBL__)||(defined __FUE__)
	        #else
	        if (nfi_egid && use_interrupt == KAL_TRUE)
	        {
	            kal_retrieve_eg_events(nfi_egid, NFI_EVENT, KAL_OR_CONSUME, &event_group, KAL_SUSPEND);
	        }
					#endif

        	#endif // (defined __UBL__) || (defined __FUE__)
        }
		#if ( defined(__NAND_FLASH_HARDWARE_TEST__) && defined(__MAUI_BASIC__) && !defined(__UBL__))
		if ((ProfileDetail==KAL_TRUE) && (FDM_UT_Item==10)) {
			wEBusTimeW = ust_get_current_time();
			wTotalBusTimeW += ust_get_duration(wSBusTimeW, wEBusTimeW);
		}
		#endif // ( defined(__NAND_FLASH_HARDWARE_TEST__) && defined(__MAUI_BASIC__) && !defined(__UBL__))

		while (ADDRCNTR_CNTR(*NFI_ADDRCNTR) < SecNum);
    }

	WAIT_ENC_READY;
	STOP_ECC_ENC;

    return MTD_STATUS_NO_ERROR;

#endif
}

// Description :
//		Only support two modes here.
//		1. DMA mode + auto-FMT + ECC with auto-correction.
//		2. MCU mode + auto-FMT + ECC with error-location.
kal_uint32 readfifo (nAND_Cmd_info* info)
{
#if defined(FLASH_DISKDRV_DEBUG) && !defined(__MTK_TARGET__)
    int i,  size;
    if ( Flash_Info.pageSize == 512)
    {
        fseek(file_hd[cur_CS], (info->add[0]>>8)*(Flash_Info.pageSize+Flash_Info.spareSize), SEEK_SET);
    }
    else
    {
        fseek(file_hd[cur_CS], ((info->add[1]<<16)|(info->add[0]>>16))*(Flash_Info.pageSize+Flash_Info.spareSize) , SEEK_SET);
    }

    if ( ((kal_uint32)info->buff) != NULL )
    {
        size = fread(info->buff, sizeof(char), Flash_Info.pageSize, file_hd[cur_CS]);
        ASSERT(size == Flash_Info.pageSize);
    }
    if ( ((kal_uint32)info->spare) != NULL )
    {
        size = fread(info->spare, sizeof(char), Flash_Info.spareSize, file_hd[cur_CS]);
        ASSERT(size == Flash_Info.spareSize);
    }
    return MTD_STATUS_NO_ERROR;
#else

	kal_uint32 status = MTD_STATUS_NO_ERROR;
    kal_uint16 byte_rw_flag;
    kal_uint32 SecNo, Index;
    kal_uint16 flag_ECC = 0;
    kal_uint8  FLAG_DMA;
    kal_uint8  SecNum = Flash_Info.pageSize>>9;
#if defined(MT6276)    
    kal_uint8  bDmaXferAvail = KAL_FALSE;         // only 4 byte align can use DMA on MT6276
#endif    
		#if (defined __UBL__) || (defined __FUE__)
		#else
    	kal_uint32 event_group;    
    	kal_uint8  bDmaBurstAvail = KAL_FALSE;        // only 16 byte can use DMA burst mode    	
    #endif

		#if (!defined(__UBL__) && !defined(__FUE__))
    if(((kal_uint32)info->buff)%16 == 0)
    {
      bDmaBurstAvail = KAL_TRUE;
    }		
    #endif
    if ( ((kal_uint32)info->buff)%4 == 0 && ((kal_uint32)info->buff_len)%4 == 0 )
    {
        byte_rw_flag = 0;
				#if defined(MT6276)            
        bDmaXferAvail = KAL_TRUE;
        #endif
    }
    else
    {
        byte_rw_flag = CNFG_BYTE_RW;
    }

    /*Fill main page data*/
    if (
    #if (defined __UBL__) || (defined __FUE__)
        (1)/*It's possible to read code to 0x0 at bootloader*/
    #else
        ((kal_uint32)info->buff) != 0
    #endif
        )
    {
        #if (defined __UBL__) || (defined __FUE__) /*bootloader case always use MCU mode*/
        FLAG_DMA = 0;
        #else
        FLAG_DMA = (INT_QueryIsNonCachedRAM(info->buff, info->buff_len) != 0) ? 1:0;
				{
					kal_uint32 mmsysram_base ;
					kal_uint32 mmsysram_len ;
					kal_uint32 mmsysram_end ;
		  	  mmsysram_len = custom_get_SysRam_MaxSize();		  	  
					if(mmsysram_len!=0)
					{  // Force using PIO to move data, MMSYSRAM can not use DMA to access
						mmsysram_base = custom_get_SysRam_Base();
			   		mmsysram_end = mmsysram_base+mmsysram_len;
						if( ( ((kal_uint32)info->buff >= mmsysram_base) && ((kal_uint32)info->buff < mmsysram_end) ) ||
							( (((kal_uint32)info->buff+(kal_uint32)info->buff_len) >= mmsysram_base) && (((kal_uint32)info->buff+(kal_uint32)info->buff_len) < mmsysram_end) ) )
						{
				    		FLAG_DMA = 0;
						}
					}
				}		        	
        #endif        
        #if defined(MT6276)
        if(bDmaXferAvail!=KAL_TRUE)
        {
          FLAG_DMA = 0;
        }
        #endif
        if (FLAG_DMA == 0) /*move data by MCU*/
        {
	        if (info->ECCFlag != ECC_SKIP)
	        {
	            flag_ECC = CNFG_HW_ECC_EN;
	            *ECC_DECCNFG = DEC_CNFG_EMPTY_EN | DEC_CNFG_EL | DEC_CNFG_META8 | DEC_CNFG_NFI;
#if defined(__ECC_8_BIT_SUPPORT__)
				if(*NFI_PAGEFMT & (PAGEFMT_SPARE_26<<4))
				{
					*ECC_DECCNFG = DEC_CNFG_EMPTY_EN | DEC_CNFG_EL | DEC_CNFG_META8_26 | DEC_CNFG_NFI | DEC_CNFG_ECC8;
				}
#endif				
	            START_ECC_DEC;
	        }
	        else
	        {
	            flag_ECC = 0;
	        }
            *NFI_CNFG |= (byte_rw_flag | flag_ECC);

			#if ( defined(__NAND_FLASH_HARDWARE_TEST__) && defined(__MAUI_BASIC__) && !defined(__UBL__))
			if ((ProfileDetail==KAL_TRUE) && (FDM_UT_Item==10)) {
				while( !(*NFI_STA & STA_NAND_BUSY_RETURN) );

	      		wEBusyTimeR   = ust_get_current_time();
				wTotalBusyTimeR += ust_get_duration(wSBusyTimeR, wEBusyTimeR);

				wSBusTimeR = ust_get_current_time();
				wTotalBusNumR++;
			}
			#endif // ( defined(__NAND_FLASH_HARDWARE_TEST__) && defined(__MAUI_BASIC__) && !defined(__UBL__))

			while( !(*NFI_STA & STA_NAND_BUSY_RETURN) );
            *NFI_CON |= CON_NFI_BRD; // set burst read
	        if (info->CustomMode)
	        {
      			*NFI_STRDATA = 0x1;
	        }

            for (SecNo=0; SecNo<SecNum; SecNo++)
            {
	            if ( byte_rw_flag )
	            {
	                kal_uint8* u8_main= (kal_uint8*)info->buff;
	                for (Index=0; Index<NAND_SECTOR_SIZE; Index++)
	                {
						while( !FIFO_PIO_READY(*NFI_PIO_DIRDY) );
	                    u8_main[(SecNo<<NAND_SECTOR_SHIFT) + Index] = (kal_uint8)(*NFI_DATAR);
	                }
	            }
	            else
	            {
	                kal_uint32* u32_main=(kal_uint32*)info->buff;
	                for (Index=0; Index<(NAND_SECTOR_SIZE>>2); Index++)
	                {
						while( !FIFO_PIO_READY(*NFI_PIO_DIRDY) );
	                    u32_main[(SecNo<<(NAND_SECTOR_SHIFT-2)) + Index] = *NFI_DATAR;
	                }
	            }

	            if (flag_ECC)
	            {
	            	while( !((*ECC_DECDONE) & (1<<SecNo)) );
			        if( (*ECC_DECFER) & (1<<SecNo) )
			        {
			        	// Bit error happened. Get error location and correct.
	                	kal_uint32 ErrLocation, BytePos, UpdateData;
			        	kal_uint32 ErrNum = ((*ECC_DECENUM)>>(SecNo<<2))&0xF;
#if ( defined(__NAND_FLASH_HARDWARE_TEST__) && defined(__MAUI_BASIC__) && !defined(__UBL__))						
						FDM_ERROR_BIT[SecNo] = ErrNum;
#endif
						if (ErrNum)
						{
							if (ErrNum == 0x0f)
							{
								status = MTD_STATUS_ERROR;
							}
							else
							{
				                for(Index = 0; Index<ErrNum ;Index++)
				                {
				                    /* MCU error correction */
				                    ErrLocation = *(ECC_DECEL0 + (Index>>1));
				                    ErrLocation = ErrLocation >> ((Index&0x01)<<4) & 0x1FFF;
									BytePos = ErrLocation>>3;
				                    if ( BytePos < (NAND_SECTOR_SIZE+PAGEFMT_FDM_ECC_DEFAULT) )
				                    {
				                        /* BytePos is in FDM data and auto-format. */
				                        if(BytePos >= 0x200)
				                        {
				                           BytePos -= 0x200;
				                            if (BytePos >= 4)
				                            {
				                                UpdateData = *(NFI_FDM0M + (SecNo<<1));
				                                BytePos -= 4;
				                                UpdateData ^= ( 1<<((ErrLocation&0x7)+(BytePos<<3)) );
				                              	*(volatile unsigned int *)(NFI_FDM0M + (SecNo<<1)) = UpdateData;
				                            }
				                            else
				                            {
				                                UpdateData = *(volatile unsigned int *)(NFI_FDM0L + (SecNo<<1));
				                                UpdateData ^= ( 1<<((ErrLocation&0x7)+(BytePos<<3)) );
				                                *(volatile unsigned int *)(NFI_FDM0L + (SecNo<<1)) = UpdateData;
				                            }
				                        }
				                        else
				                        {
							            	kal_uint8* u8_main= ((kal_uint8*)info->buff) + (SecNo << 9);

				                           	*(u8_main+BytePos) ^= (1<<(ErrLocation&0x7));
				                        }
				                    }
								}

								if (status != MTD_STATUS_ERROR)
								{
									status = MTD_STATUS_CORRECTED;
								}
							}
						}
			        }
	            }
            }

   			while (ADDRCNTR_CNTR(*NFI_BYTELEN) < SecNum);	// Wait FDM data and ECC transfer complete.
        }
        else /*move data by DMA*/
        {
        	#if (defined __UBL__) || (defined __FUE__) /*bootloader case always use MCU mode*/
            force_ASSERT(0,0,0,0);
        	#else // (defined __UBL__) || (defined __FUE__)

	        if (info->ECCFlag != ECC_SKIP)
	        {
	            flag_ECC = CNFG_HW_ECC_EN;
	            *ECC_DECCNFG = DEC_CNFG_EMPTY_EN | DEC_CNFG_CORRECT | DEC_CNFG_META8 | DEC_CNFG_NFI;
#if defined(__ECC_8_BIT_SUPPORT__)
				if(*NFI_PAGEFMT & (PAGEFMT_SPARE_26<<4))
				{
					*ECC_DECCNFG = DEC_CNFG_EMPTY_EN | DEC_CNFG_CORRECT | DEC_CNFG_META8_26 | DEC_CNFG_NFI | DEC_CNFG_ECC8;
				}
#endif					
	            START_ECC_DEC;
	        }
	        else
	        {
	            flag_ECC = 0;
	        }

			#if ( defined(__NAND_FLASH_HARDWARE_TEST__) && defined(__MAUI_BASIC__) && !defined(__UBL__))
			if ((ProfileDetail==KAL_TRUE) && (FDM_UT_Item==10)) {
				while( !(*NFI_STA & STA_NAND_BUSY_RETURN) );

	      		wEBusyTimeR   = ust_get_current_time();
				wTotalBusyTimeR += ust_get_duration(wSBusyTimeR, wEBusyTimeR);

				wSBusTimeR = ust_get_current_time();
				wTotalBusNumR++;
			}
			#endif // ( defined(__NAND_FLASH_HARDWARE_TEST__) && defined(__MAUI_BASIC__) && !defined(__UBL__))

        	*NFI_STRADDR = (kal_uint32)info->buff;

			if( (byte_rw_flag == CNFG_BYTE_RW) || (bDmaBurstAvail==KAL_FALSE))
			{// NFI V3.1 when read to unalignment address, can not eable burst read
        	    *NFI_CNFG |= (byte_rw_flag | flag_ECC | CNFG_DMA );
            }
            else
            {
                *NFI_CNFG |= (byte_rw_flag | flag_ECC | CNFG_DMA | CNFG_DMA_BURST_EN);
            }
	        #if (defined __UBL__)||(defined __FUE__)
	        #else
            if (nfi_egid && use_interrupt == KAL_TRUE) {
            	*NFI_INTR_EN = AHB_DONE_EN;
            }
            else
					#endif            
            {
            	  IRQMask(IRQ_NFI_CODE);
            		*NFI_INTR_EN = AHB_DONE_EN;
            }
			while( !(*NFI_STA & STA_NAND_BUSY_RETURN) );
            *NFI_CON |= CON_NFI_BRD; // set burst read
	        if (info->CustomMode)
	        {
      			*NFI_STRDATA = 0x1;
	        }

			#if ( defined(__NAND_FLASH_HARDWARE_TEST__) && defined(__MAUI_BASIC__) && !defined(__UBL__))
			if ((ProfileDetail==KAL_TRUE) && (FDM_UT_Item==10)) {
				wSetDMATimeR = ust_get_current_time();
			}
			#endif // ( defined(__NAND_FLASH_HARDWARE_TEST__) && defined(__MAUI_BASIC__) && !defined(__UBL__))

	        #if (defined __UBL__)||(defined __FUE__)
	        #else
	        if (nfi_egid && use_interrupt == KAL_TRUE)
	        {
	            kal_retrieve_eg_events(nfi_egid, NFI_EVENT, KAL_OR_CONSUME, &event_group, KAL_SUSPEND);
	        }	      
	        else
					#endif	        
	        {
	        	kal_uint32 backup_status;
	        	while(1)
	        	{
	        		backup_status = *NFI_INTR;
	        		if(backup_status&AHB_DONE)
	        		{
	        			break;
	        		}
	        	}
            *NFI_INTR_EN = 0;
   					IRQClearInt(IRQ_NFI_CODE);
   				  IRQUnmask(IRQ_NFI_CODE);	 	        	
	        }

			while (ADDRCNTR_CNTR(*NFI_BYTELEN) < SecNum); // Wait FDM data and ECC transfer complete.

			#if defined __MTK_TARGET__

	        Data_Mem_Barrier();	// Force data transfer had done before CPU access in ARM11.

			#endif  // defined __MTK_TARGET__

			if (flag_ECC)
			{
				// Wait ECC auto-correction complete.
				while( *ECC_DECDONE != ((1<<SecNum)-1) );
				if ( (*ECC_DECFER) & ((1<<SecNum)-1) )
				{
					for (SecNo=0; SecNo<SecNum; SecNo++)
					{
						kal_uint32 ErrNum = ((*ECC_DECENUM)>>(SecNo<<2))&0xF;
#if ( defined(__NAND_FLASH_HARDWARE_TEST__) && defined(__MAUI_BASIC__) && !defined(__UBL__))						
						FDM_ERROR_BIT[SecNo] = ErrNum;
#endif
						if (ErrNum)
						{
							if (ErrNum == 0x0f)
							{
								status = MTD_STATUS_ERROR;
							}
							else
							{
								if (status != MTD_STATUS_ERROR)
								{
									status = MTD_STATUS_CORRECTED;
								}
							}
						}

					}
				}
			}

        	#endif // (defined __UBL__) || (defined __FUE__)
        }
		#if ( defined(__NAND_FLASH_HARDWARE_TEST__) && defined(__MAUI_BASIC__) && !defined(__UBL__))
		if ((ProfileDetail==KAL_TRUE) && (FDM_UT_Item==10)) {
			wEBusTimeR = ust_get_current_time();
			wTotalBusTimeR += ust_get_duration(wSBusTimeR, wEBusTimeR);
		}
		#endif // ( defined(__NAND_FLASH_HARDWARE_TEST__) && defined(__MAUI_BASIC__) && !defined(__UBL__))

    }

	if (flag_ECC)
	{
		#if ( defined(__NAND_FLASH_HARDWARE_TEST__) && defined(__MAUI_BASIC__) && !defined(__UBL__))
		if ((ProfileDetail==KAL_TRUE) && (FDM_UT_Item==10)) {
			wSBusTimeR = ust_get_current_time();
		}
		#endif // ( defined(__NAND_FLASH_HARDWARE_TEST__) && defined(__MAUI_BASIC__) && !defined(__UBL__))

		// Copy spare data from FDM register to buffer.
		if ( ((kal_uint32)info->spare) != 0 )
		{
			// Currently only support 8 bytes FDM data.
		    if ( ((kal_uint32)info->spare)%4 == 0 && ((kal_uint32)info->spare_len)%4 == 0 )
		    {
		    	// 4 bytes aligned.
               	for(SecNo = 0 ; SecNo < SecNum ; SecNo++)
               	{
               		kal_uint32* u32_spare = (kal_uint32*)&(info->spare[SecNo << 4]);

                  	u32_spare[0] = *(volatile unsigned int *)(NFI_FDM0L+(SecNo<<1));
                  	u32_spare[1] = *(volatile unsigned int *)(NFI_FDM0L+(SecNo<<1)+1);
               	}
		    }
		    else
		    {
		    	// non 4 bytes aligned.
               	for(SecNo = 0 ; SecNo < SecNum ; SecNo++)
               	{
               		kal_uint32 TempVal;

                  	TempVal = *(volatile unsigned int *)(NFI_FDM0L+(SecNo<<1));
                  	info->spare[(SecNo<<4) + 0] = (TempVal >>  0) & 0xff;
                  	info->spare[(SecNo<<4) + 1] = (TempVal >>  8) & 0xff;
                  	info->spare[(SecNo<<4) + 2] = (TempVal >> 16) & 0xff;
                  	info->spare[(SecNo<<4) + 3] = (TempVal >> 24) & 0xff;

                  	TempVal = *(volatile unsigned int *)(NFI_FDM0L+(SecNo<<1)+1);
                  	info->spare[(SecNo<<4) + 4] = (TempVal >>  0) & 0xff;
                  	info->spare[(SecNo<<4) + 5] = (TempVal >>  8) & 0xff;
                  	info->spare[(SecNo<<4) + 6] = (TempVal >> 16) & 0xff;
                  	info->spare[(SecNo<<4) + 7] = (TempVal >> 24) & 0xff;
               	}
		    }
		}

		#if ( defined(__NAND_FLASH_HARDWARE_TEST__) && defined(__MAUI_BASIC__) && !defined(__UBL__))
		if ((ProfileDetail==KAL_TRUE) && (FDM_UT_Item==10)) {
			wEBusTimeR = ust_get_current_time();
			wTotalBusTimeR += ust_get_duration(wSBusTimeR, wEBusTimeR);
		}
		#endif // ( defined(__NAND_FLASH_HARDWARE_TEST__) && defined(__MAUI_BASIC__) && !defined(__UBL__))
	}

	WAIT_DEC_READY;
	STOP_ECC_DEC;
	#if ( defined(__NAND_FLASH_HARDWARE_TEST__) && defined(__MAUI_BASIC__) && !defined(__UBL__))
	if(status==MTD_STATUS_ERROR)
	{
	  if ( Flash_Info.pageSize == 512)
	  {
      nandlog_print("Page:0x%xh has ECC Uncorrected\r\n",(info->add[0]>>8));	    
	  }
	  else
	  {
      nandlog_print("Page:0x%xh has ECC Uncorrected\r\n",((info->add[1]<<16)|(info->add[0]>>16)));
    }
    	  	  
	
	nandlog_print("Page:0x%xh ECC correcte Status (%d,%d,%d,%d) Bit \r\n",((info->add[1]<<16)|(info->add[0]>>16)), FDM_ERROR_BIT[0], FDM_ERROR_BIT[1], FDM_ERROR_BIT[2], FDM_ERROR_BIT[3]);
	
	
	dump_memory_to_uart_log((kal_uint32*)info->buff, Flash_Info.pageSize);
  }
  else if(status ==MTD_STATUS_CORRECTED)
	{
	  if ( Flash_Info.pageSize == 512)
	  {
	      nandlog_print("Page:0x%xh has ECC corrected %d Bit \r\n",(info->add[0]>>8), FDM_ERROR_BIT[0]);	    
		  
		  FDM_ERROR_BIT[0] = 0; //clear error bit		  
	  }
	  else
	  {
          nandlog_print("Page:0x%xh has ECC corrected (%d,%d,%d,%d) Bit \r\n",((info->add[1]<<16)|(info->add[0]>>16)), FDM_ERROR_BIT[0], FDM_ERROR_BIT[1], FDM_ERROR_BIT[2], FDM_ERROR_BIT[3]);
		  
		  FDM_ERROR_BIT[0] = 0; //clear error bit
		  FDM_ERROR_BIT[1] = 0; //clear error bit
		  FDM_ERROR_BIT[2] = 0; //clear error bit
		  FDM_ERROR_BIT[3] = 0; //clear error bit		  
    }
    	  
	}
	
	#endif
	return status;

#endif
}

#elif defined(__NFI_VERSION2__)

kal_uint32 writefifo (nAND_Cmd_info* info)
{
#if defined(FLASH_DISKDRV_DEBUG) && !defined(__MTK_TARGET__)
    int i,  size;
    if ( Flash_Info.pageSize == 512)
    {
        fseek(file_hd[cur_CS], (info->add[0]>>8)*(Flash_Info.pageSize+Flash_Info.spareSize), SEEK_SET);
    }
    else
    {
        fseek(file_hd[cur_CS], ((info->add[1]<<16)|(info->add[0]>>16))*(Flash_Info.pageSize+Flash_Info.spareSize) , SEEK_SET);
    }
    size = fread(MTD_simu_buff, sizeof(char), Flash_Info.pageSize + Flash_Info.spareSize, file_hd[cur_CS]);
    ASSERT(size == Flash_Info.pageSize + Flash_Info.spareSize);

    /* Add Flash property  only 1->0*/
    if ( ((kal_uint32)info->buff) != NULL )
    {
        for(i=0; i<Flash_Info.pageSize; i++)
           MTD_simu_buff[i] &= info->buff[i];
    }
    if ( ((kal_uint32)info->spare) != NULL )
    {
        for(i=0; i<Flash_Info.spareSize; i++)
           MTD_simu_buff[ Flash_Info.pageSize + i ] &= info->spare[i];
    }

    if ( Flash_Info.pageSize == 512)
    {
        fseek(file_hd[cur_CS], (info->add[0]>>8)*(Flash_Info.pageSize+Flash_Info.spareSize), SEEK_SET);
    }
    else
    {
        fseek(file_hd[cur_CS], ((info->add[1]<<16)|(info->add[0]>>16))*(Flash_Info.pageSize+Flash_Info.spareSize) , SEEK_SET);
    }

    size = fwrite(MTD_simu_buff, sizeof(char), Flash_Info.pageSize + Flash_Info.spareSize, file_hd[cur_CS]);
    ASSERT(size == Flash_Info.pageSize + Flash_Info.spareSize);

    fflush(file_hd[cur_CS]);
    return MTD_STATUS_NO_ERROR;
#else
    kal_uint16 byte_rw_flag;
    kal_uint16 flag_ECC;
    kal_uint16 init_ADDRCNTR,wrt_Len;
    kal_uint8  FLAG_DMA ;
		#if (defined __UBL__) || (defined __FUE__) 
		#else
    	kal_uint32 event_group;    
    #endif
    

    #if !defined(__NFI_VERSION2__)
    kal_uint32 parity[4];
    #endif

    #if !defined(__NFI_VERSION2__)
    kal_mem_set(parity, 0xFF, sizeof(parity));
    #endif
    if ( ((kal_uint32)info->buff)%4 == 0 && ((kal_uint32)info->buff_len)%4 == 0 &&
         ((kal_uint32)info->spare)%4 == 0 && ((kal_uint32)info->spare_len)%4 == 0  )
        byte_rw_flag = 0;
    else
        byte_rw_flag = BYTE_RW_EN;

    *NFI_OPCON = BURST_WR;
    init_ADDRCNTR = *NFI_ADDRCNTR ; /*record initial NFI_ADDRCNTR value*/
    wrt_Len = 0;

#if (defined __FUE__)
	if ( 1 )
#else // (defined __FUE__)
    if ( ((kal_uint32)info->buff) != NULL )
#endif // (defined __FUE__)
    {
        wrt_Len += info->buff_len;
        #if defined(__NFI_VERSION2__)

		#if ( defined(ECC_BIT_ERROR_TEST) || defined(__EMULATE_NFB_BIT_ERROE__) )
        if ((info->ECCFlag != ECC_SKIP) && !ECCDisable)
		#else // ( defined(ECC_BIT_ERROR_TEST) || defined(__EMULATE_NFB_BIT_ERROE__) )
        if(info->ECCFlag != ECC_SKIP)
		#endif // ( defined(ECC_BIT_ERROR_TEST) || defined(__EMULATE_NFB_BIT_ERROE__) )
            flag_ECC = AUTOECC_ENC_EN|MAIN_ECC_EN|SPARE_ECC_EN;
        else
            flag_ECC = 0;
        #endif

        #if defined(__NFI_VERSION2__)
            #if (defined __UBL__) || (defined __FUE__) /*bootloader case always use MCU mode*/
            FLAG_DMA = 0;
            #else
            FLAG_DMA = (INT_QueryIsNonCachedRAM(info->buff, info->buff_len) != 0) ? 1:0;
							#if defined (TK6280)            	
							FLAG_DMA = 0;
							#endif
            #endif
        #else
        FLAG_DMA = 1;
        #endif

#if ( defined(__NAND_FLASH_HARDWARE_TEST__) && defined(__MAUI_BASIC__) && !defined(__UBL__))
		if ((ProfileDetail==KAL_TRUE) && (FDM_UT_Item==10)) {
			wSBusTimeW = ust_get_current_time();
			wTotalBusNumW++;
		}
#endif // ( defined(__NAND_FLASH_HARDWARE_TEST__) && defined(__MAUI_BASIC__) && !defined(__UBL__))



        if (FLAG_DMA == 0) /*move data by MCU*/
        {
            #if defined(__NFI_VERSION2__)
            kal_uint32 i;
            *NFI_CON=(byte_rw_flag|flag_ECC|SW_PROGSPARE_EN);

            if (byte_rw_flag)
            {
                for (i=0;i<info->buff_len;i++)
                {
                    while (*NFI_FIFOSTA & WR_FULL_MASK);
                    *NFI_DATAWB = info->buff[i];
                }
            }
            else
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
#endif
                for (i=0;i<info->buff_len/4;i++)
                {
                    while (FIFO_WR_REMAIN(*NFI_FIFOSTA) > 12);
                    *NFI_DATAW = ((kal_uint32*)info->buff)[i];
                }
//            	}
            }
            #else
            force_ASSERT(0,0,0,0);
            #endif
        }
        else /*move data by DMA*/
        {
        #if (defined __UBL__) || (defined __FUE__) /*bootloader case always use MCU mode*/
            force_ASSERT(0,0,0,0);
        #else
            #if defined(__NFI_VERSION2__)
        *NFI_CON=(byte_rw_flag|flag_ECC|DMA_WR_EN|SW_PROGSPARE_EN);
        #else
        *NFI_CON =(DMA_WR_EN|SW_PROGSPARE_EN);
        #endif


        if (nfi_dmaport == 0)
            nfi_dmaport = DMA_FullSize_GetChannel(DMA_NFI);

        if (byte_rw_flag)
        {
            nfi_menu.destination  = (kal_uint32)NFI_DATAWB;
            nfi_input.size = DMA_BYTE;
            nfi_input.count = info->buff_len;
        }
        else
        {
            nfi_menu.destination  = (kal_uint32)NFI_DATAW;
            nfi_input.size = DMA_LONG;
            nfi_input.count = (info->buff_len/4);
        }
        nfi_menu.source = (kal_uint32)info->buff;
        nfi_input.type = DMA_HWTX;
        nfi_menu.TMOD.burst_mode = KAL_FALSE;
        
        #if (defined __UBL__)||(defined __FUE__)
        #else
        if (nfi_egid && use_interrupt == KAL_TRUE)
        {
            nfi_input.callback = NFI_DMA_Callback;
        }
        else
				#endif        
        {
            nfi_input.callback = NULL;
				}
        DMA_FullSize_Config(nfi_dmaport, &nfi_input, KAL_TRUE);
	      #if (defined __UBL__)||(defined __FUE__)
	      #else        
        if (nfi_egid && use_interrupt == KAL_TRUE)
        {
            kal_retrieve_eg_events(nfi_egid, NFI_EVENT, KAL_OR_CONSUME,
                                   &event_group, KAL_SUSPEND);
        }
        else
        #endif
        {
            while (IS_NFI_DMA_RUN);
        }

        /* wait until all data is transfered to NAND device */
        #if ( (defined(MT6218B)) || (defined(MT6219)) )
        while (!(*NFI_FIFOCON & WR_EMPTY_MASK));
        #else
        while(*NFI_ADDRCNTR < (init_ADDRCNTR + wrt_Len) );
        #endif

        DMA_FullSize_FreeChannel(nfi_dmaport);
        nfi_dmaport = 0;

        #if !defined(__NFI_VERSION2__)
        if (info->ECCFlag != ECC_SKIP)
        {
            if (Flash_Info.pageSize == 512)
            {
                parity[0] = *NFI_PAR6;
                parity[0] |= *NFI_PAR7 << 16;
            }
            else
            {
                parity[0] = *NFI_PAR0;
                parity[0] |= (*NFI_PAR1) << 16;
                parity[1] = (*NFI_PAR2);
                parity[1] |= (*NFI_PAR3) << 16;
                parity[2] = (*NFI_PAR4);
                parity[2] |= (*NFI_PAR5) << 16;
                parity[3] = (*NFI_PAR6);
                parity[3] |= (*NFI_PAR7) << 16;
            }
        }
        #endif
        #endif
        }
#if ( defined(__NAND_FLASH_HARDWARE_TEST__) && defined(__MAUI_BASIC__) && !defined(__UBL__))
		if ((ProfileDetail==KAL_TRUE) && (FDM_UT_Item==10)) {
			wEBusTimeW = ust_get_current_time();
			wTotalBusTimeW += ust_get_duration(wSBusTimeW, wEBusTimeW);
		}
#endif // ( defined(__NAND_FLASH_HARDWARE_TEST__) && defined(__MAUI_BASIC__) && !defined(__UBL__))

    }
    else /*do not process main page*/
    {
        #if defined(__NFI_VERSION2__)
        *NFI_CON = byte_rw_flag|SW_PROGSPARE_EN;
        #else
        *NFI_CON = SW_PROGSPARE_EN;
        #endif
    }
    /*else do nothing*/


    if ( ((kal_uint32)info->spare) != NULL )
    {
        kal_uint32 i;

#if ( defined(__NAND_FLASH_HARDWARE_TEST__) && defined(__MAUI_BASIC__) && !defined(__UBL__))
		if ((ProfileDetail==KAL_TRUE) && (FDM_UT_Item==10)) {
			wSBusTimeW = ust_get_current_time();
		}
#endif // ( defined(__NAND_FLASH_HARDWARE_TEST__) && defined(__MAUI_BASIC__) && !defined(__UBL__))


        wrt_Len += info->spare_len;
        if ( byte_rw_flag )
        {
            for (i=0;i<info->spare_len;i++)
            {
                while (*NFI_FIFOSTA & WR_FULL_MASK);
                #if defined(__NFI_VERSION2__)
                /*because the FDM/DAL only send 1 sector's spare data th NFI, so we can access 1st sector's spare only*/
                *NFI_DATAWB = info->spare[i]; /*auto ECC*/
                #else
                if (Flash_Info.pageSize == 512)
                {
                    if (i==0)
                        *NFI_DATAW = parity[0]; /*4 bytes ECC at 0~3*/
                    else if (i >= 4)
                        *NFI_DATAWB = info->spare[i];
                }
                else
                {
                    if (i%16 == 8)
                    {
                        *NFI_DATAW = parity[i/16]; /*4 bytes ECC at 16*n+8*/
                        i+=3;
                    }
                    else
                        *NFI_DATAWB = info->spare[i];
                }
                #endif
            }
        }
        else
        {
            for (i=0;i<info->spare_len/4;i++)
            {
                while (FIFO_WR_REMAIN(*NFI_FIFOSTA) > 12);
                #if defined(__NFI_VERSION2__)
                /*because the FDM/DAL only send 1 sector's spare data th NFI, so we can access 1st sector's spare only*/
                *NFI_DATAW = ((kal_uint32*)info->spare)[i]; /*auto ECC*/
                #else
                if (Flash_Info.pageSize == 512)
                {
                    if (i==0)
                        *NFI_DATAW = parity[0]; /*4 bytes ECC at 0~3*/
                    else
                        *NFI_DATAW = ((kal_uint32*)info->spare)[i];
                }
                else
                {
                    if (i%4 == 2)
                    {
                        *NFI_DATAW = parity[i/4]; /*4 bytes ECC at 16*n+8*/
                    }
                    else
                        *NFI_DATAW = ((kal_uint32*)info->spare)[i];
                }
                #endif
            }
        }
        while (!(*NFI_FIFOSTA & WR_EMPTY_MASK));

#if ( defined(__NAND_FLASH_HARDWARE_TEST__) && defined(__MAUI_BASIC__) && !defined(__UBL__))
		if ((ProfileDetail==KAL_TRUE) && (FDM_UT_Item==10)) {
			wEBusTimeW = ust_get_current_time();
			wTotalBusTimeW += ust_get_duration(wSBusTimeW, wEBusTimeW);
		}
#endif // ( defined(__NAND_FLASH_HARDWARE_TEST__) && defined(__MAUI_BASIC__) && !defined(__UBL__))

    }
    while (*NFI_PSTA & STATUS_DATAW);
    while(*NFI_ADDRCNTR < (init_ADDRCNTR + wrt_Len) );

    return MTD_STATUS_NO_ERROR;

#endif
}

void NFI_Correct(kal_uint8 * Dest,kal_uint8 * Spare, kal_uint32 Error, kal_uint32 errDET_PE_range)
{
#if defined(FLASH_DISKDRV_DEBUG) && !defined(__MTK_TARGET__)
/*Do nothing*/
#else
    kal_uint32 i,bound = 0;
    kal_uint16 UpdateAddr;
    kal_uint8 UpdateData;
    kal_uint32 Syndrome;

    if ((Error & ERRDET_PE_ALL)==0) /*If no recoverable error, return - Yehudi*/
    {
        return;
    }
    Error &= errDET_PE_range; /*Only process caller interested range*/

    if ((Error & (ERRDET_PEBLK0|ERRDET_PEBLK1|ERRDET_PEBLK2|ERRDET_PEBLK3|ERRDET_PEBLK4|ERRDET_PEBLK5|ERRDET_PEBLK6|ERRDET_PEBLK7) )!=0)
    { /*main area correctable error*/
        if (Flash_Info.pageSize == 512)
            bound = 2;
        else if (Flash_Info.pageSize == 2048)
            bound = 8;
        else
        {
            dbg_ASSERT(0);
        }

        for (i=0;i<bound;i++)
        {
            if ((Error>>(i+16))&1)
            {
                UpdateAddr = (*(volatile kal_uint16*)((kal_uint32)NFI_SYM0_ADDR + (4*i)) );
                Syndrome = (*(volatile kal_uint32*)((kal_uint32)NFI_SYM0_DAT + (4*i)) );
                UpdateData = ((Syndrome >> ((UpdateAddr & 0x03) << 3)) & 0xFF);
                Dest[UpdateAddr] ^= UpdateData;
            }
        }
    }
    if ((Error & (ERRDET_PESBLK0|ERRDET_PESBLK1|ERRDET_PESBLK2|ERRDET_PESBLK3) )!=0)
    {   /*spare area correctable error*/
        if (Flash_Info.pageSize == 512)
            bound = 1;
        else if (Flash_Info.pageSize == 2048)
            bound = 4;
        else
        {
            dbg_ASSERT(0);
        }
        for (i=0;i<bound;i++)
        {
            if ((Error>>(i+24))&1)
            {
                UpdateAddr = (*(volatile kal_uint16*)((kal_uint32)NFI_SYMS0_ADDR + (4*i)) );
                Syndrome = (*(volatile kal_uint32*)((kal_uint32)NFI_SYMS0_DAT + (4*i)) );
                UpdateData = ((Syndrome >> ((UpdateAddr & 0x03) << 3)) & 0xFF);
                Spare[UpdateAddr] ^= UpdateData;
            }
        }
    }
#endif
}

kal_uint32 readfifo (nAND_Cmd_info* info)
{
#if defined(FLASH_DISKDRV_DEBUG) && !defined(__MTK_TARGET__)
    int i,  size;
    if ( Flash_Info.pageSize == 512)
    {
        fseek(file_hd[cur_CS], (info->add[0]>>8)*(Flash_Info.pageSize+Flash_Info.spareSize), SEEK_SET);
    }
    else
    {
        fseek(file_hd[cur_CS], ((info->add[1]<<16)|(info->add[0]>>16))*(Flash_Info.pageSize+Flash_Info.spareSize) , SEEK_SET);
    }

    if ( ((kal_uint32)info->buff) != NULL )
    {
        size = fread(info->buff, sizeof(char), Flash_Info.pageSize, file_hd[cur_CS]);
        ASSERT(size == Flash_Info.pageSize);
    }
    if ( ((kal_uint32)info->spare) != NULL )
    {
        size = fread(info->spare, sizeof(char), Flash_Info.spareSize, file_hd[cur_CS]);
        ASSERT(size == Flash_Info.spareSize);
    }
    return MTD_STATUS_NO_ERROR;
#else
    kal_uint16 byte_rw_flag;
    kal_uint16 flag_ECC;
    kal_uint8  *spareAdd = NULL;
    kal_uint8  FLAG_DMA ;
		#if (defined __UBL__) || (defined __FUE__) 
		#else
    	kal_uint32 event_group;    
    #endif

    if ( ((kal_uint32)info->buff)%4 == 0 && ((kal_uint32)info->buff_len)%4 == 0 &&
         ((kal_uint32)info->spare)%4 == 0 && ((kal_uint32)info->spare_len)%4 == 0  )
        byte_rw_flag = 0;
    else
        byte_rw_flag = BYTE_RW_EN;

    /*Fill mian page  data*/
    if (
    #if (defined __UBL__) || (defined __FUE__)
        (1)/*It's possible to read code to 0x0 at bootloader*/
    #else
        ((kal_uint32)info->buff) != NULL
    #endif
        )
    {
        if (info->ECCFlag != ECC_SKIP)
            flag_ECC = MAIN_ECC_EN|SPARE_ECC_EN|AUTO_ECC_DEC;
        else
            flag_ECC = 0;

        #if (defined __UBL__) || (defined __FUE__) /*bootloader case always use MCU mode*/
        FLAG_DMA = 0;
        #else
        	#if defined(__WRITE_THROUGH_CACHEABLE__)
/* under construction !*/
        	#else // defined(__WRITE_THROUGH_CACHEABLE__)
        	FLAG_DMA = (INT_QueryIsNonCachedRAM(info->buff, info->buff_len) != 0) ? 1:0;
        	#endif // defined(__WRITE_THROUGH_CACHEABLE__)
        #endif

        if (FLAG_DMA == 0) /*move data by MCU*/
        {
            kal_uint32 i;
            *NFI_CON=(byte_rw_flag|flag_ECC|SW_PROGSPARE_EN);
            *NFI_OPCON = BURST_RD;                       // set burst read
#if ( defined(__NAND_FLASH_HARDWARE_TEST__) && defined(__MAUI_BASIC__) && !defined(__UBL__))
			if ((ProfileDetail==KAL_TRUE) && (FDM_UT_Item==10)) {
				while (*NFI_FIFOSTA & RD_EMPTY_MASK);

	      		wEBusyTimeR   = ust_get_current_time();
				wTotalBusyTimeR += ust_get_duration(wSBusyTimeR, wEBusyTimeR);

				wSBusTimeR = ust_get_current_time();
				wTotalBusNumR++;
			}
#endif // ( defined(__NAND_FLASH_HARDWARE_TEST__) && defined(__MAUI_BASIC__) && !defined(__UBL__))

            if ( byte_rw_flag )
            {
                kal_uint8* u8_main= (kal_uint8*)info->buff;
                for (i=0;i< info->buff_len ;i++)
                {
                    while (*NFI_FIFOSTA & RD_EMPTY_MASK);
                    u8_main[i] = *NFI_DATARB;
                }
            }
            else
            {
                kal_uint32* u32_main=(kal_uint32*)info->buff;
                for (i=0 ; i< info->buff_len/4; i++)
                {
                    while (FIFO_RD_REMAIN (*NFI_FIFOSTA ) < 4);
                    u32_main[i] = *NFI_DATAR;
                }
            }
        }
        else /*move data by DMA*/
        {
        #if (defined __UBL__) || (defined __FUE__) /*bootloader case always use MCU mode*/
            force_ASSERT(0,0,0,0);
        #else
        *NFI_CON=(byte_rw_flag|flag_ECC|DMA_RD_EN|SW_PROGSPARE_EN);
        *NFI_OPCON = BURST_RD;                       // set burst read

#if ( defined(__NAND_FLASH_HARDWARE_TEST__) && defined(__MAUI_BASIC__) && !defined(__UBL__))
			if ((ProfileDetail==KAL_TRUE) && (FDM_UT_Item==10)) {
				while (*NFI_FIFOSTA & RD_EMPTY_MASK);

	      		wEBusyTimeR   = ust_get_current_time();
				wTotalBusyTimeR += ust_get_duration(wSBusyTimeR, wEBusyTimeR);

				wSBusTimeR = ust_get_current_time();
				wTotalBusNumR++;
			}
#endif // ( defined(__NAND_FLASH_HARDWARE_TEST__) && defined(__MAUI_BASIC__) && !defined(__UBL__))

        if (nfi_dmaport == 0)
            nfi_dmaport = DMA_FullSize_GetChannel(DMA_NFI);

        if (byte_rw_flag)
        {
            nfi_menu.source  = (kal_uint32)NFI_DATARB;
            nfi_input.size = DMA_BYTE;
            nfi_input.count = info->buff_len;
        }
        else
        {
            nfi_menu.source  = (kal_uint32)NFI_DATAR;
            nfi_input.size = DMA_LONG;
            nfi_input.count = (info->buff_len/4);
        }

        nfi_menu.destination = (kal_uint32)info->buff;
        nfi_input.type = DMA_HWRX;
        nfi_menu.TMOD.burst_mode = KAL_FALSE;

	      #if (defined __UBL__)||(defined __FUE__)
	      #else
        if (nfi_egid && use_interrupt == KAL_TRUE)
        {
            nfi_input.callback = NFI_DMA_Callback;
        }
        else
        #endif
        {
            nfi_input.callback = NULL;
        }
        DMA_FullSize_Config(nfi_dmaport, &nfi_input, KAL_TRUE);

#if ( defined(__NAND_FLASH_HARDWARE_TEST__) && defined(__MAUI_BASIC__) && !defined(__UBL__))
		if ((ProfileDetail==KAL_TRUE) && (FDM_UT_Item==10)) {
			wSetDMATimeR = ust_get_current_time();
		}
#endif // ( defined(__NAND_FLASH_HARDWARE_TEST__) && defined(__MAUI_BASIC__) && !defined(__UBL__))
	      #if (defined __UBL__)||(defined __FUE__)
	      #else
        if (nfi_egid && use_interrupt == KAL_TRUE)
        {
            kal_retrieve_eg_events(nfi_egid,NFI_EVENT, KAL_OR_CONSUME,
                                   &event_group, KAL_SUSPEND);
        }
        else
        #endif
        {
            while (IS_NFI_DMA_RUN);
        }

        DMA_FullSize_FreeChannel(nfi_dmaport);/*Release DMA Channel - 2007/05/07 - Yehudi*/
        nfi_dmaport = 0;
       	#if defined(__WRITE_THROUGH_CACHEABLE__)
/* under construction !*/
		#endif // defined(__WRITE_THROUGH_CACHEABLE__)
        #endif
        }
#if ( defined(__NAND_FLASH_HARDWARE_TEST__) && defined(__MAUI_BASIC__) && !defined(__UBL__))
		if ((ProfileDetail==KAL_TRUE) && (FDM_UT_Item==10)) {
			wEBusTimeR = ust_get_current_time();
			wTotalBusTimeR += ust_get_duration(wSBusTimeR, wEBusTimeR);
		}
#endif // ( defined(__NAND_FLASH_HARDWARE_TEST__) && defined(__MAUI_BASIC__) && !defined(__UBL__))

    }
    else /*do not process main page*/
    {
        *NFI_CON = byte_rw_flag|SW_PROGSPARE_EN;
        *NFI_OPCON = BURST_RD;                       // set burst read
    }

    /*Fill spare data*/
    if ( ((kal_uint32)info->spare) != NULL || (info->ECCFlag != ECC_SKIP) )
    {
        kal_uint32 i;

        if ( (((kal_uint32)info->spare) == NULL) )
        {
            spareAdd = (kal_uint8*)tmp_spare;
        }
        else
        {
            spareAdd = info->spare;
        }

#if ( defined(__NAND_FLASH_HARDWARE_TEST__) && defined(__MAUI_BASIC__) && !defined(__UBL__))
		if ((ProfileDetail==KAL_TRUE) && (FDM_UT_Item==10)) {
			wSBusTimeR = ust_get_current_time();
		}
#endif // ( defined(__NAND_FLASH_HARDWARE_TEST__) && defined(__MAUI_BASIC__) && !defined(__UBL__))


        if ( byte_rw_flag )
        {
            kal_uint8* u8_spare= (kal_uint8*)spareAdd;
            for (i=0;i< Flash_Info.spareSize ;i++)
            {
                while (*NFI_FIFOSTA & RD_EMPTY_MASK);
                u8_spare[i] = *NFI_DATARB;
            }
        }
        else
        {
            kal_uint32* u32_spare=(kal_uint32*)spareAdd;
            for (i=0 ; i< Flash_Info.spareSize/4; i++)
            {
                while (FIFO_RD_REMAIN (*NFI_FIFOSTA ) < 4);
                u32_spare[i] = *NFI_DATAR;
            }
        }
#if ( defined(__NAND_FLASH_HARDWARE_TEST__) && defined(__MAUI_BASIC__) && !defined(__UBL__))
		if ((ProfileDetail==KAL_TRUE) && (FDM_UT_Item==10)) {
			wEBusTimeR = ust_get_current_time();
			wTotalBusTimeR += ust_get_duration(wSBusTimeR, wEBusTimeR);
		}
#endif // ( defined(__NAND_FLASH_HARDWARE_TEST__) && defined(__MAUI_BASIC__) && !defined(__UBL__))

    }
    while (*NFI_PSTA & STATUS_DATAR);

    /*ECC detection*/
#if ( (defined __UBL__) || (defined __FUE__) )
	// For bootloader, the starting address could be 0.
    if ( info->ECCFlag != ECC_SKIP )
#else // (defined __UBL__) || (defined __FUE__)
    if ( ((kal_uint32)info->buff) != NULL && (info->ECCFlag != ECC_SKIP) ) /*check ECC if ECC_flag==1 && length >4*/
#endif // (defined __UBL__) || (defined __FUE__)
    {
        kal_uint32 Error;
        kal_uint32 status = MTD_STATUS_NO_ERROR;
        kal_uint32 errDET_PE_range = 0,errDET_E_range = 0;
        Error = *NFI_ERRDET;

        dbg_ASSERT( info->ECCFlag == ECC_WHOLE);
        if (Error != 0)
        {
            #if 0  /*option for read both main page + spare at info->buff*/
/* under construction !*/
/* under construction !*/
            #endif
            dbg_ASSERT(spareAdd != NULL);

            if (Flash_Info.pageSize == 512)
            {
                if(info->spare != NULL)
                {
                    errDET_PE_range = (ERRDET_PEBLK0|ERRDET_PEBLK1|ERRDET_PESBLK0);
                    errDET_E_range = (ERRDET_EBLK0|ERRDET_EBLK1|ERRDET_ESBLK0);
                }
                else
                { /*caller only want main area data, only process main area ECC*/
                    errDET_PE_range = (ERRDET_PEBLK0|ERRDET_PEBLK1);
                    errDET_E_range = (ERRDET_EBLK0|ERRDET_EBLK1);
                }
            }
            else if (Flash_Info.pageSize == 2048)
            {
                if(info->spare != NULL)
                {
                    errDET_PE_range = ERRDET_PE_ALL;
                    errDET_E_range = ERRDET_E_ALL;
                }
                else
                { /*caller only want main area data, only process main area ECC*/
                    errDET_PE_range = ERRDET_PEBLK0|ERRDET_PEBLK1|ERRDET_PEBLK2|ERRDET_PEBLK3|ERRDET_PEBLK4|ERRDET_PEBLK5|ERRDET_PEBLK6|ERRDET_PEBLK7;
                    errDET_E_range = ERRDET_EBLK0|ERRDET_EBLK1|ERRDET_EBLK2|ERRDET_EBLK3|ERRDET_EBLK4|ERRDET_EBLK5|ERRDET_EBLK6|ERRDET_EBLK7;
                }
            }
            else /* __NFI_VERSION2__ support 512/2k page only*/
            {
                dbg_ASSERT(0);
            }

            if ( (Error & errDET_PE_range ) != 0)
            {
                NFI_Correct(info->buff,spareAdd,Error, errDET_PE_range);
                status = MTD_STATUS_CORRECTED;
            }
            if ( (Error & errDET_E_range ) != 0)
            {
                status = MTD_STATUS_ERROR;
            }

        }
        return status;
    }
    return MTD_STATUS_NO_ERROR;
#endif
}

#endif // __NFI_VERSION3_1__

kal_uint32 NFI_Pointer(kal_uint16 PointerCmd)
{
#if defined(__NFI_VERSION3_1__)
	*NFI_CNFG = CNFG_OP_CUST;
	*NFI_CMD = PointerCmd;
	while ((*NFI_STA) & STA_CMD_STATE);

	NFI_OP_RESET();
#else
   *NFI_CMD = PointerCmd;
   while (*NFI_PSTA & STATUS_CMD);

   *NFI_OPCON = OPCON_RESET;
   while(*NFI_PSTA != 0);
#endif

   return MTD_STATUS_NO_ERROR;
} /*  End of NFI_Pointer */


kal_uint32 nAND_RESET (void)
{
    /* Reset Command */
#if defined(__NFI_VERSION3_1__)
	NFI_OP_RESET();
	*NFI_CNFG = CNFG_OP_RESET;
	*NFI_CMD = RESET_CMD;
	while ((*NFI_STA) & STA_CMD_STATE);

	*NFI_CNRNB = STROBE_TIMEOUT;
	while ((*NFI_STA & STA_NAND_BUSY_RETURN)==0);
#else
	kal_uint32 Delay;
    /* Reset Command */
    *NFI_CMD = RESET_CMD;
	while (*NFI_PSTA & STATUS_CMD);
	// 200ns delay maximum.
	for (Delay=0; Delay<COUNTER_200nS; Delay++){
		#if defined(__MTK_TARGET__)
			#if defined(__ARMCC_VERSION)
				__asm{nop};
			#elif defined(__GNUC__) 
				__asm__("nop");
			#endif /* __RVCT__ , __GNUC__ */ 
		#endif /* __MTK_TARGET__ */
	}
	while (*NFI_PSTA & STATUS_BUSY);
#endif

   return MTD_STATUS_NO_ERROR;
}

/****************************************************************************
 * Function:    ID_Table_OrderCheck
 *
 * Parameters:  void
 *
 *
 *
 * Returns:     MTD_STATUS_ERROR        fail
 *              MTD_STATUS_NO_ERROR     success
 * Description: It is used to check the order in NAND_ID_Table
 *
 ****************************************************************************/
kal_uint32 ID_Table_OrderCheck (void)
{
    kal_uint16 mID = 0x00, ID_zero_bit,pre_ID_zero_bit = 0;
    kal_uint32 i,j, ret_Val = MTD_STATUS_NO_ERROR;

    for (i = 0; NAND_ID_Table[i].ID_info[0] != 0xFF ; i++)
    {
        if ( (NAND_ID_Table[i].ID_info[0]+(NAND_ID_Table[i].ID_info[1]<<8)) != mID)
        {
            /*case of new manufacture ID + device ID*/
        	pre_ID_zero_bit = 0;
            mID = (NAND_ID_Table[i].ID_info[0]+(NAND_ID_Table[i].ID_info[1]<<8));
            for (j=0;j<sizeof(NAND_ID_Table[i].ID_valid_mask);j++)
            {
                pre_ID_zero_bit += ZEROBIT[ NAND_ID_Table[i].ID_valid_mask[j] ];
            }
        }
        else
        {
        	ID_zero_bit = 0;
            for (j=0;j<sizeof(NAND_ID_Table[0].ID_valid_mask);j++)
            {
                ID_zero_bit += ZEROBIT[ NAND_ID_Table[i].ID_valid_mask[j] ];
            }
            if ( pre_ID_zero_bit > ID_zero_bit)
            {   /*case of previous device's ID valid bits < currents*/

#if ( defined(__NAND_FLASH_HARDWARE_TEST__) && defined(__MAUI_BASIC__) && !defined(__UBL__))
                nandlog_print("name_Enum:%d ID:%x %x %x %x %x order error with previous\r\n",
                             NAND_ID_Table[i].DevName_enum, NAND_ID_Table[i].ID_info[0],NAND_ID_Table[i].ID_info[1],
                             NAND_ID_Table[i].ID_info[2],NAND_ID_Table[i].ID_info[3],NAND_ID_Table[i].ID_info[4]) ;
                
#endif

                ret_Val = MTD_STATUS_ERROR;
            }
            pre_ID_zero_bit = ID_zero_bit;
        }
    }
    return ret_Val;
}
/****************************************************************************
 * Function:    FlashGetAttrib_By2ndID
 *
 * Parameters:  ID1     [Input]Manufacture ID
 *              ID2     [Input]device ID
 *              ID3     Internal Chip Number
 *              ID4     Page Size, Block Size,Redundant Area Size, Organization
 *              o_ID_table  [Output] Attribute of NAND
 *              
 * Returns:     MTD_STATUS_ERROR        fail
 *              MTD_STATUS_NO_ERROR     success
 * Description: It uses the 2nd ID (device ID) to set NAND default attribut, exclude the driverSet
 *              
 ****************************************************************************/
kal_uint32 FlashSetAttrib_ByFlashID(kal_uint8 *pID,flash_list *o_ID_table)
{
    kal_uint8 ID2,ID4;
    kal_uint32 retVal = MTD_STATUS_NO_ERROR;
    //ID1 = pID[0];
    ID2 = pID[1];
    //ID3 = pID[2];
    ID4 = pID[3];
    /*General setting*/
    o_ID_table->planeNum = 1;
    o_ID_table->dieNum = 1;
    o_ID_table->supportMPType = SIMPLE_OP;
    o_ID_table->supportMEType = SIMPLE_OP;

    /*By 2nd ID*/
    if ( (ID2&0xF0) == 0x70 || (ID2&0xF0) == 0x50 ||
         (ID2&0xF0) == 0x40 || (ID2&0xF0) == 0x30 )
    {
        /*small block (512/page) case */
        o_ID_table->pageSize = 512;
        o_ID_table->spareSize = 16;
        o_ID_table->blockPage = 32;
        switch (ID2)
        {
        case 0x73:/*3v*/
            o_ID_table->IOWidth = 8;
            o_ID_table->address_cycle = 3;
            o_ID_table->deviceSize = 16;
            break;
        case 0x35:/*1.8v*/
        case 0x75:/*3v*/
            o_ID_table->IOWidth = 8;
            o_ID_table->address_cycle = 3;
            o_ID_table->deviceSize = 32;
            break;
        case 0x45:/*1.8v*/
        case 0x55:/*3v*/
            o_ID_table->IOWidth = 16;
            o_ID_table->address_cycle = 3;
            o_ID_table->deviceSize = 32;
            break;
        case 0x36:/*1.8v*/
        case 0x76:/*3v*/
            o_ID_table->IOWidth = 8;
            o_ID_table->address_cycle = 4;
            o_ID_table->deviceSize = 64;
            break;
        case 0x46:/*1.8v*/
        case 0x56:/*3v*/
            o_ID_table->IOWidth = 16;
            o_ID_table->address_cycle = 4;
            o_ID_table->deviceSize = 64;
            break;
        case 0x78:/*1.8v*/
        case 0x79:/*3v*/
            o_ID_table->IOWidth = 8;
            o_ID_table->address_cycle = 4;
            o_ID_table->deviceSize = 128;
            break;
        case 0x72:/*1.8v*/
        case 0x74:/*3v*/
            o_ID_table->IOWidth = 16;
            o_ID_table->address_cycle = 4;
            o_ID_table->deviceSize = 128;
            break;
        default:
            o_ID_table->IOWidth = 0;
            o_ID_table->address_cycle = 0;
            o_ID_table->deviceSize = 0;
            retVal = MTD_STATUS_ERROR;
            break;
        }
    }
    else /*Large block (>= 2048/page) case*/
    {
        o_ID_table->pageSize = 2048;
        o_ID_table->spareSize = 64;
        o_ID_table->blockPage = 64;
        switch (ID2)
        {
        case 0xA0:/*1.8v*/
        case 0xF0:/*3v*/
        case 0xD0:/*3v TSB 43nm*/
            o_ID_table->IOWidth = 8;
            o_ID_table->address_cycle = 4;
            o_ID_table->deviceSize = 64;
            break;
        case 0xB0:/*1.8v*/
        case 0xC0:/*3v*/
            o_ID_table->IOWidth = 16;
            o_ID_table->address_cycle = 4;
            o_ID_table->deviceSize = 64;
            break;
        case 0xA1:/*1.8v*/
        case 0xF1:/*3v*/
        case 0xD1:/*3v TSB 43nm*/
            o_ID_table->IOWidth = 8;
            o_ID_table->address_cycle = 4;
            o_ID_table->deviceSize = 128;
            break;
        case 0xB1:/*1.8v*/
        case 0xC1:/*3v*/
            o_ID_table->IOWidth = 16;
            o_ID_table->address_cycle = 4;
            o_ID_table->deviceSize = 128;
            break;
        case 0xAA:/*1.8v*/
        case 0xDA:/*3v*/
            o_ID_table->IOWidth = 8;
            o_ID_table->address_cycle = 5;
            o_ID_table->deviceSize = 256;
            break;
        case 0xBA:/*1.8v*/
        case 0xCA:/*3v*/
            o_ID_table->IOWidth = 16;
            o_ID_table->address_cycle = 5;
            o_ID_table->deviceSize = 256;
            break;
        case 0xAC:/*1.8v*/
        case 0xDC:/*3v*/
            o_ID_table->IOWidth = 8;
            o_ID_table->address_cycle = 5;
            o_ID_table->deviceSize = 512;
#if defined(__NFI_VERSION3_1__)
            if((ID4&0x03)==0x02) // Samsung 4KB
            {
              o_ID_table->pageSize = 4096;
              o_ID_table->spareSize = 128;
              o_ID_table->blockPage = 64;
            }
#endif
            break;
        case 0xBC:/*1.8v*/
        case 0xCC:/*3v*/
            o_ID_table->IOWidth = 16;
            o_ID_table->address_cycle = 5;
            o_ID_table->deviceSize = 512;
#if defined(__NFI_VERSION3_1__)
            if((ID4&0x03)==0x02) // Samsung 4KB
            {
              o_ID_table->pageSize = 4096;
              o_ID_table->spareSize = 128;
              o_ID_table->blockPage = 64;
            }
#endif
            break;
        case 0xA3:/*1.8v*/
        case 0xD3:/*3v*/
            o_ID_table->IOWidth = 8;
            o_ID_table->address_cycle = 5;
            o_ID_table->deviceSize = 1024;
#if defined(__NFI_VERSION3_1__)
            if((ID4&0x03)==0x02) // Samsung 4KB
            {
              o_ID_table->pageSize = 4096;
              o_ID_table->spareSize = 128;
              o_ID_table->blockPage = 64;
            }
#endif
            break;
        case 0xB3:/*1.8v*/
        case 0xC3:/*3v*/
            o_ID_table->IOWidth = 16;
            o_ID_table->address_cycle = 5;
            o_ID_table->deviceSize = 1024;
#if defined(__NFI_VERSION3_1__)
            if((ID4&0x03)==0x02) // Samsung 4KB
            {
              o_ID_table->pageSize = 4096;
              o_ID_table->spareSize = 128;
              o_ID_table->blockPage = 64;
            }
#endif
            break;
        case 0xA5:/*1.8v*/
        case 0xD5:/*3v*/
            o_ID_table->IOWidth = 8;
            o_ID_table->address_cycle = 5;
            o_ID_table->deviceSize = 2048;
            break;
        case 0xB5:/*1.8v*/
        case 0xC5:/*3v*/
            o_ID_table->IOWidth = 16;
            o_ID_table->address_cycle = 5;
            o_ID_table->deviceSize = 2048;
            break;
        case 0xA7:/*1.8v*/
        case 0xD7:/*3v*/
            o_ID_table->IOWidth = 8;
            o_ID_table->address_cycle = 5;
            o_ID_table->deviceSize = 4096;
            break;
        case 0xB7:/*1.8v*/
        case 0xC7:/*3v*/
            o_ID_table->IOWidth = 16;
            o_ID_table->address_cycle = 5;
            o_ID_table->deviceSize = 4096;
            break;
        case 0xAE:/*1.8v*/
        case 0xDE:/*3v*/
            o_ID_table->IOWidth = 8;
            o_ID_table->address_cycle = 5;
            o_ID_table->deviceSize = 8192;
            break;
        case 0xBE:/*1.8v*/
        case 0xCE:/*3v*/
            o_ID_table->IOWidth = 16;
            o_ID_table->address_cycle = 5;
            o_ID_table->deviceSize = 8192;
            break;
        default:
            o_ID_table->IOWidth = 0;
            o_ID_table->address_cycle = 0;
            o_ID_table->deviceSize = 0;
            retVal = MTD_STATUS_ERROR;
            break;
        }
    }
#if defined(MT6280)    
// For L1S, pagefmt may be not initialized by BootROM
		if(o_ID_table->IOWidth) 									// 16 bit enable
		{
			*NFI_GPIO_1200 = 0x1111;							 	//NLD8, 9 , 10, 11
			*NFI_GPIO_1300 = 0x1111;							 	//NLD12, 13, 14, 15
		}
#endif    
    return retVal;
}

/****************************************************************************
 * Function:    FlashAttrib_AutoDetect 
 *
 * Parameters:  i_ID_table  [input] input ID table , refer to generate output table
 *              o_ID_table  [output] output ID table, modify the flash atribute by ID rule        
 *                            
 * Returns:     MTD_STATUS_ERROR        fail
 *              MTD_STATUS_NO_ERROR     success
 * Description: To detect the NAND attribute by ID rule and fill to o_ID_table.
 *              512 page device with ID > 2 can not be auto detected by ID rule, its attributes should ne fill manually,
 *                            
 ****************************************************************************/
kal_uint32 FlashAttrib_AutoDetect(flash_list *i_ID_table, flash_list *o_ID_table)
{
    kal_uint32 ret_IDStatus;
    const kal_uint32 all_one[2]={0xFFFFFFFF,0xFFFFFFFF};
    flash_list table_2ndID;
    nAND_ID *valid_mask, *id_p, *full_mask;



    kal_mem_set(&table_2ndID,0x00, sizeof(table_2ndID));

	if (i_ID_table != &Default_ID_Table)
	{
	
	    /*Get attribute from 2nd ID*/
	    ret_IDStatus = FlashSetAttrib_ByFlashID(i_ID_table->ID_info,&table_2ndID);
	}
	else 
	{
		// Automatic detection.
	    ret_IDStatus = FlashSetAttrib_ByFlashID(i_ID_table->ID_info,&table_2ndID);
	    if (ret_IDStatus == MTD_STATUS_ERROR) {
	    	// Automatic & not found. Detection failed.
	    	return MTD_STATUS_ERROR;
	    }
	    switch (table_2ndID.pageSize) {
      case 4096:
    	case 2048:
            kal_mem_cpy((kal_uint8*)i_ID_table->ID_valid_mask, (kal_uint8*)ID_2K_Mask, sizeof(i_ID_table->ID_valid_mask));
    		break;
    	case 512:
    	default: // Should not happen now.
            kal_mem_cpy((kal_uint8*)i_ID_table->ID_valid_mask, (kal_uint8*)ID_512_Mask, sizeof(i_ID_table->ID_valid_mask));
    		break;
	    }
	}
	

#if defined(_NAND_FLASH_BOOTING_) && defined(__NAND_MDL_APPEND__)
	if(KAL_TRUE== bNAND_mdl_support)
	{
		//don't detect these flash info.
		i_ID_table->blockPage = o_ID_table->blockPage;
		i_ID_table->pageSize =	o_ID_table->pageSize;
		i_ID_table->spareSize =	o_ID_table->spareSize;
	}
#endif

    id_p = (nAND_ID*)i_ID_table->ID_info;
    valid_mask = (nAND_ID*)i_ID_table->ID_valid_mask;
    full_mask = (nAND_ID*)all_one;

    /*default value of o_ID_table*/
    kal_mem_cpy(o_ID_table,i_ID_table,sizeof(flash_list));

    /*set o_ID_table->pageSize if AUTO_NAND_DETECT*/
    if (i_ID_table->pageSize == AUTO_NAND_DETECT)
    {
        if ( full_mask->pageSize == valid_mask->pageSize )
        {
            o_ID_table->pageSize = (1024<<id_p->pageSize);
            if ( id_p->pageSize == 0)/*It should not be 0 (page size 1024)*/
            {
#if !defined(__UBL__)
                nandlog_print("FlashAttrib_AutoDetect: strange page size : 1024. (512 page device can not be auto-detected)\r\n");
#endif // !defined(__UBL__)
                return MTD_STATUS_ERROR;
            }
        }
        else
        {
            if (ret_IDStatus == MTD_STATUS_NO_ERROR)
                o_ID_table->pageSize = table_2ndID.pageSize ;
            else
                return MTD_STATUS_ERROR;
        }
    }
    /*check 512 page device with auto-detection flag*/
    if ( o_ID_table->pageSize == 512)
    {
        if ( i_ID_table->ID_valid_mask[2] != 0 || i_ID_table->ID_valid_mask[3]!= 0 || i_ID_table->ID_valid_mask[4]!= 0)
        {   /*More than 2 ID bytes case, it do not support auto-detection*/
            if ( i_ID_table->pageSize == AUTO_NAND_DETECT || i_ID_table->spareSize == AUTO_NAND_DETECT ||
                 i_ID_table->IOWidth == AUTO_NAND_DETECT || i_ID_table->address_cycle == AUTO_NAND_DETECT ||
                 i_ID_table->planeNum == AUTO_NAND_DETECT || i_ID_table->dieNum == AUTO_NAND_DETECT ||
                 i_ID_table->blockPage == AUTO_NAND_DETECT || i_ID_table->deviceSize == AUTO_NAND_DETECT ||
                 i_ID_table->supportMPType == AUTO_NAND_DETECT || i_ID_table->supportMEType == AUTO_NAND_DETECT ||
                 i_ID_table->driverSet == (NAND_MTD_SUB_DRIVER*)AUTO_NAND_DETECT )
            {
#if !defined(__UBL__)
                nandlog_print("FlashAttrib_AutoDetect: 512 page device can not be auto-detected\r\n");
#endif // !defined(__UBL__)
#if defined(FLASH_DISKDRV_DEBUG) && !defined(__MTK_TARGET__) // PC Simulator
#else
                return MTD_STATUS_ERROR;
#endif // endif PC simulator
            }
        }
    }

    /*set o_ID_table->spareSize if AUTO_NAND_DETECT*/
    if (i_ID_table->spareSize == AUTO_NAND_DETECT)
    {
#if 0  // Remove spare size detection. Limit to 16 and 64 bytes.
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if !defined(__UBL__)
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif      	
        {
            if (ret_IDStatus == MTD_STATUS_NO_ERROR)
                o_ID_table->spareSize = table_2ndID.spareSize ;
            else
                return MTD_STATUS_ERROR;
        }
    }
    /*set o_ID_table->dieNum if AUTO_NAND_DETECT*/
    if (i_ID_table->dieNum == AUTO_NAND_DETECT)
    {
        if ( full_mask->dieNum == valid_mask->dieNum )
            o_ID_table->dieNum = (1<<id_p->dieNum);
        else
        {
            if (ret_IDStatus == MTD_STATUS_NO_ERROR)
                o_ID_table->dieNum = table_2ndID.dieNum ;
            else
                return MTD_STATUS_ERROR;
        }
    }
    /*set o_ID_table->planeNum if AUTO_NAND_DETECT*/


#if defined(ENABLE_ADVANCE_OPERATION)

    if (i_ID_table->planeNum == AUTO_NAND_DETECT)
    {
        if ( full_mask->planeNum == valid_mask->planeNum )
        {
            o_ID_table->planeNum = ( (1<<id_p->planeNum) / o_ID_table->dieNum) ;/*plane per die = plane per CE / #die per CE*/
        }
        else if ( full_mask->simultNum == valid_mask->simultNum )
        {
            o_ID_table->planeNum = (1<<id_p->simultNum) ;
        }
        else
        {
            if (ret_IDStatus == MTD_STATUS_NO_ERROR)
                o_ID_table->planeNum = table_2ndID.planeNum ;
            else
                return MTD_STATUS_ERROR;
        }
    }
#else  // defined(ENABLE_ADVANCE_OPERATION)

        o_ID_table->planeNum = 1;

#endif // defined(ENABLE_ADVANCE_OPERATION)


    /*set o_ID_table->deviceSize if AUTO_NAND_DETECT*/
    if (i_ID_table->deviceSize == AUTO_NAND_DETECT)
    {

#if defined(ENABLE_ADVANCE_OPERATION)

        if ( full_mask->planeSize == valid_mask->planeSize )
            o_ID_table->deviceSize = ((64/8)<<id_p->planeSize)*o_ID_table->planeNum*o_ID_table->dieNum;
        else
        {
            if (ret_IDStatus == MTD_STATUS_NO_ERROR)
                o_ID_table->deviceSize = table_2ndID.deviceSize ;
            else
                return MTD_STATUS_ERROR;
        }
        
#else  // defined(ENABLE_ADVANCE_OPERATION)

		// Need to have this because planeNum had been reset to 1. So use planesSize to calculate is not correct.
        if (ret_IDStatus == MTD_STATUS_NO_ERROR)
            o_ID_table->deviceSize = table_2ndID.deviceSize ;
        else
            return MTD_STATUS_ERROR;
		
#endif // defined(ENABLE_ADVANCE_OPERATION)
        
    }
    /*set o_ID_table->IOWidth if AUTO_NAND_DETECT*/
    if (i_ID_table->IOWidth == AUTO_NAND_DETECT)
    {
        if ( full_mask->IOWidth == valid_mask->IOWidth )
            o_ID_table->IOWidth = (8<<id_p->IOWidth) ;
        else
        {
            if (ret_IDStatus == MTD_STATUS_NO_ERROR)
                o_ID_table->IOWidth = table_2ndID.IOWidth ;
            else
                return MTD_STATUS_ERROR;
        }
        if ( o_ID_table->IOWidth != 8 && o_ID_table->IOWidth != 16)
        {
#if !defined(__UBL__)
            nandlog_print("FlashAttrib_AutoDetect: IOWidth error\r\n");
#endif
            return MTD_STATUS_ERROR;
        }
    }
    /*set o_ID_table->address_cycle if AUTO_NAND_DETECT*/
    if (i_ID_table->address_cycle == AUTO_NAND_DETECT)
    {
        if ( o_ID_table->deviceSize <= 32) {
            o_ID_table->address_cycle = 3;
        } else if (o_ID_table->deviceSize <= 128) {
            o_ID_table->address_cycle = 4;
            //if ( (o_ID_table->deviceSize==128) && (i_ID_table->ID_info[0]==POWERFLASH) ) {
	        //    o_ID_table->address_cycle = 5;
            //}
        } else {
            o_ID_table->address_cycle = 5;
        }
    }
    /*set o_ID_table->blockPage if AUTO_NAND_DETECT*/
    if (i_ID_table->blockPage == AUTO_NAND_DETECT)
    {
        if ( full_mask->blockSize == valid_mask->blockSize )
        {
            o_ID_table->blockPage = ((64*1024)<<id_p->blockSize)/o_ID_table->pageSize;
            if ( (1024<<id_p->pageSize) < 2048)/*It should not be 0 (spare size 8 for 512)*/
            {
#if !defined(__UBL__)
                nandlog_print("FlashAttrib_AutoDetect: 512 page's blockPage can not be AUTO_NAND_DETECT\r\n");
#endif
                return MTD_STATUS_ERROR;
            }
        }
        else
        {
            if (ret_IDStatus == MTD_STATUS_NO_ERROR)
                o_ID_table->blockPage = table_2ndID.blockPage ;
            else
                return MTD_STATUS_ERROR;
        }
    }
    /*set o_ID_table->supportMPType if AUTO_NAND_DETECT*/
    if (i_ID_table->supportMPType == AUTO_NAND_DETECT)
    {
        o_ID_table->supportMPType = 0;

        /*CACHE_PROGRAM*/
        if ( full_mask->cacheProgram == valid_mask->cacheProgram )
        {
            if (id_p->cacheProgram != 0)
                o_ID_table->supportMPType |= CACHE_PROGRAM;
        }
#if defined(ENABLE_ADVANCE_OPERATION)
        /*TWO_DIE_INTERLEAVE_OP*/
        if ( full_mask->dieInterleave == valid_mask->dieInterleave )
        {
            if (id_p->dieInterleave != 0 && o_ID_table->dieNum == 2)
            {
                if (o_ID_table->ID_info[0] != HYNIX) /*Some HYNIX devices show this bit but not support die interleave*/
                {
                    o_ID_table->supportMPType |= TWO_DIE_INTERLEAVE_OP;
                }
            }
        }
        /*TWO_PLANE_OP or FOUR_PLANE_OP*/
        if (o_ID_table->planeNum == 2)
        {
            o_ID_table->supportMPType |= TWO_PLANE_OP;
        }
        else if (o_ID_table->planeNum == 4)
        {
            o_ID_table->supportMPType |= FOUR_PLANE_OP;
        }
        /* PLANE_CONTINUOUS, PLANE_INTERLACED*/
        if ( ( o_ID_table->supportMPType&(TWO_PLANE_OP) ) != 0  ) /*multipage operation*/
        {
            if ( o_ID_table->ID_info[0] == TOSHIBA )
                o_ID_table->supportMPType |= PLANE_CONTINUOUS;
            else
                o_ID_table->supportMPType |= PLANE_INTERLACED;
        }
        else if ( ( o_ID_table->supportMPType&FOUR_PLANE_OP ) != 0 )
        {
            o_ID_table->supportMPType |= PLANE_INTERLACED;
        }
        /*EXTENDED_BLOCK*/
        if ( o_ID_table->ID_info[0] == TOSHIBA )
        {
            if ( (full_mask->ToshibaExt == valid_mask->ToshibaExt) &&
                 id_p->ToshibaExt != 0 )
            {
                o_ID_table->supportMPType |= EXTENDED_BLOCK;
            }
        }
#endif // #endif // defined(ENABLE_ADVANCE_OPERATION)

    }
    /*error check of o_ID_table->supportMPType*/
    if ( o_ID_table->ID_info[0] == TOSHIBA )
    {
        if ((o_ID_table->supportMPType&TWO_DIE_INTERLEAVE_OP) != 0)
        {
#if !defined(__UBL__)
            nandlog_print("FlashAttrib_AutoDetect: TOSHIBA Flash should not support die interleave\r\n");
#endif
            return MTD_STATUS_ERROR;
        }
    }
    if ( o_ID_table->ID_info[0] == SAMSUNG || o_ID_table->ID_info[0] == HYNIX || o_ID_table->ID_info[0] == ST)
    {
        if ( (( o_ID_table->supportMPType&(TWO_DIE_INTERLEAVE_OP|TWO_PLANE_OP|FOUR_PLANE_OP) ) != 0) &&
             ( (o_ID_table->supportMPType&CACHE_PROGRAM) && o_ID_table->driverSet->CacheProgram != NULL) )
        {
#if !defined(__UBL__)
            nandlog_print("FlashAttrib_AutoDetect: SAMSUNG/HYNIX/ST with multi-plane/die should not support cache program\r\n");
#endif
            return MTD_STATUS_ERROR;
        }
    }
    /*set o_ID_table->supportMEType if AUTO_NAND_DETECT*/
    if (i_ID_table->supportMEType == AUTO_NAND_DETECT)
    {
        o_ID_table->supportMEType = o_ID_table->supportMPType;
    }
    else /* ID_table->supportMEType set manually */
    {
        if (i_ID_table->supportMPType == AUTO_NAND_DETECT)
        {
            if  ( ( o_ID_table->supportMPType&(TWO_DIE_INTERLEAVE_OP|TWO_PLANE_OP|FOUR_PLANE_OP) ) == 0  &&
                  ( o_ID_table->supportMEType&(TWO_DIE_INTERLEAVE_OP|TWO_PLANE_OP|FOUR_PLANE_OP) ) != 0 )
            {   /*case of MP detection SIMPLE_OP but ME is !SIMPLE_OP manually*/
#if !defined(__UBL__)
                nandlog_print("FlashAttrib_AutoDetect: Conflict between Multi-page program/erase setting\r\n");
#endif
                return MTD_STATUS_ERROR;
            }
            else if ( ( o_ID_table->supportMPType&(TWO_DIE_INTERLEAVE_OP|TWO_PLANE_OP|FOUR_PLANE_OP) ) != 0  &&
                      ( o_ID_table->supportMEType&(TWO_DIE_INTERLEAVE_OP|TWO_PLANE_OP|FOUR_PLANE_OP) ) != 0 &&
                      (( o_ID_table->supportMPType&(TWO_DIE_INTERLEAVE_OP|TWO_PLANE_OP|FOUR_PLANE_OP) )&( o_ID_table->supportMEType&(TWO_DIE_INTERLEAVE_OP|TWO_PLANE_OP|FOUR_PLANE_OP) )) == 0 )
            {   /*case of MPType conflict with METype*/
#if !defined(__UBL__)
                nandlog_print("FlashAttrib_AutoDetect: Conflict between Multi-page program/erase setting\r\n");
#endif
                return MTD_STATUS_ERROR;
            }
        }
    }
    /*set o_ID_table->CopyBackType if AUTO_NAND_DETECT*/
    if (i_ID_table->CopyBackType == AUTO_NAND_DETECT)
    {
        o_ID_table->CopyBackType = 0;/*just a defaul value*/
    }
    /*set o_ID_table->driverSet if AUTO_NAND_DETECT*/
    if (i_ID_table->driverSet == (NAND_MTD_SUB_DRIVER*)AUTO_NAND_DETECT)
    {
        if ( o_ID_table->ID_info[0] == TOSHIBA )
        {
            o_ID_table->driverSet = &TOSHIBA_SUB_DRIVER;
        }
        else if ( o_ID_table->ID_info[0] == MICRON || o_ID_table->ID_info[0] == INTEL )
        {
            o_ID_table->driverSet = &MICRON_SUB_DRIVER;
        }
        else if ( o_ID_table->ID_info[0] == SAMSUNG )
        {
            if ( (o_ID_table->supportMPType&(TWO_DIE_INTERLEAVE_OP|TWO_PLANE_OP|FOUR_PLANE_OP)) != 0 )
            {
                o_ID_table->driverSet = &SAMSUNG_SUB_DRIVER;
            }
            else
            {
                o_ID_table->driverSet = &SAMSUNG_SINGLE_CACHE_SUB_DRIVER;
            }
        }
        else if ( o_ID_table->ID_info[0] == HYNIX || o_ID_table->ID_info[0] == ST || o_ID_table->ID_info[0] == POWERFLASH )
        {
            if ( (o_ID_table->supportMPType&(TWO_DIE_INTERLEAVE_OP|TWO_PLANE_OP|FOUR_PLANE_OP)) != 0 )
            {
                o_ID_table->driverSet = &HYNIX_ST_SUB_DRIVER;
            }
            else
            {
                o_ID_table->driverSet = &SAMSUNG_SINGLE_CACHE_SUB_DRIVER;
            }
        }
        else
        {
			o_ID_table->driverSet = &HYNIX_ST_SUB_DRIVER;
        }
    }
    return MTD_STATUS_NO_ERROR;
}

#if 0 /*for reference*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #if 0 /*temp mark 0*/
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
    #if 0 /*spare size value is not always match, specially for MLC*/
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
#endif

/****************************************************************************
 * Function:    InitializeMTDData
 *
 * Parameters:
 *
 * Returns:
 *
 * Description: It gets ID and will change Flash_Info.deviceInfo_CE
 *                                         Flash_Info.valid_CE
 *                                         Flash_Info.devicePage
 ****************************************************************************/
kal_int32 InitializeMTDData( void )       // read NAND ID and construct sub driver data
{
    kal_uint16 i,j,cs;
    kal_uint32 id_data[2];
    kal_uint32 totalSize=0;
    kal_bool FindFromFlashList;
#if defined(_NAND_FLASH_BOOTING_) && defined(__NAND_MDL_APPEND__)
	kal_uint16 sector_num;	
	CMEMFlashInfo Device_Info;
#endif	

    /* Search NAND flash ID and */
    for(cs = 0; cs < CS_num; cs++) /*[MAUI_00580753] apply CS_num -- 2007/12/04*/
    {
#if defined(__NFI_VERSION3_1__)
        while (*NFI_STA & STA_NAND_BUSY);  /*check device busy status*/
#else
        while (*NFI_PSTA & STATUS_BUSY);  /*check device busy status*/
#endif

        if(cs==0)
        {
            SET_NFI_CS0;
        }
        else
        {
            SET_NFI_CS1;
        }
        NFI_OP_RESET();
		nAND_RESET();
        NFI_OP_RESET();
#if defined(__NFI_VERSION3_1__)
		*NFI_CNFG = CNFG_OP_SRD | CNFG_READ_EN;
		*NFI_CMD = RD_ID_CMD;
		while ((*NFI_STA) & STA_CMD_STATE);

   		*NFI_COLADDR = 0;
		*NFI_ROWADDR = 0;
		*NFI_ADDRNOB = 1;
		while ((*NFI_STA) & STA_ADDR_STATE);

		*NFI_CON = CON_NFI_SRD;
		while((*NFI_STA) & STA_DATAR_STATE);
		for(i = 0 ; i < 2 ; i++)
		{
			while( !FIFO_PIO_READY(*NFI_PIO_DIRDY) );
			id_data[i] = *NFI_DATAR;
		}
		*NFI_CON = 0x0;
#else
        *NFI_CMD = RD_ID_CMD;
        while (*NFI_PSTA & STATUS_CMD);
        *NFI_ADDRL = 0;
        *NFI_ADDNOB = 1;
        while (*NFI_PSTA & STATUS_ADDR);

        *NFI_OPCON = (NOB_DWORD | SINGLE_RD);
        while (*NFI_PSTA & STATUS_DATAR);

        #if defined(__NFI_VERSION2__)
        while (FIFO_RD_REMAIN (*NFI_FIFOSTA ) < 4);
        #endif
        id_data[0] = *NFI_DATAR; /*First 4 bytes*/

        NFI_OP_RESET();
        *NFI_OPCON = (NOB_DWORD | SINGLE_RD);
        while (*NFI_PSTA & STATUS_DATAR);
        #if defined(__NFI_VERSION2__)
        while (FIFO_RD_REMAIN (*NFI_FIFOSTA ) < 4);
        #endif
        id_data[1] = *NFI_DATAR; /*Second 4 bytes*/
#endif
#if defined(__COMBO_MEMORY_SUPPORT__)
    ComboNANDID[0] = (kal_uint8)id_data[0];
    ComboNANDID[1] = (kal_uint8)(id_data[0]>>8);
    ComboNANDID[2] = (kal_uint8)(id_data[0]>>16);
    ComboNANDID[3] = (kal_uint8)(id_data[0]>>24);
    ComboNANDID[4] = (kal_uint8)id_data[1];
    ComboNANDID[5] = (kal_uint8)(id_data[1]>>8);
    ComboNANDID[6] = (kal_uint8)(id_data[1]>>16);
    ComboNANDID[7] = (kal_uint8)(id_data[1]>>24);    
#endif

#if defined(_NAND_FLASH_BOOTING_) && defined(__NAND_MDL_APPEND__)
	// kal_true: get device info from MDL
	// kal_false: not support in MDL list
	bNAND_mdl_support = CMEM_GetflashInfo((kal_uint8*)id_data, &Device_Info);
	if(bNAND_mdl_support == KAL_TRUE) //id match in MDL list
	{
		// block/page/spare size info is from list
		//b_autodectect = KAL_FALSE;
		if((Device_Info.page_size == 0) || \
		   (Device_Info.block_size == 0) || \
		   (Device_Info.spare_size == 0))
		{
			// in-valid info, please check MDL if fill correct flash info.
			bNAND_mdl_support = KAL_FALSE;
			force_ASSERT (0, Device_Info.page_size, Device_Info.spare_size, Device_Info.block_size);
		}
		else
		{
			force_ASSERT (((Device_Info.page_size % 512) == 0), Device_Info.page_size,0,0);
			sector_num = Device_Info.page_size / 512;
			force_ASSERT (((Device_Info.spare_size / sector_num) >= 16),Device_Info.spare_size,0,0);						

			// blockpage wii be check after FlashAttrib_AutoDetect
			Flash_Info.deviceInfo_CE[cs].blockPage = Device_Info.block_size * 1024 / Device_Info.page_size;
			Flash_Info.deviceInfo_CE[cs].pageSize = Device_Info.page_size;
			Flash_Info.deviceInfo_CE[cs].spareSize = Device_Info.spare_size;
		}
	}
#endif

	#if defined(FLASH_DISKDRV_DEBUG) && !defined(__MTK_TARGET__)
        MTD_Simu_SetIDData(id_data,cs);
        #endif

#if ( defined(__NAND_FLASH_HARDWARE_TEST__) && defined(__MAUI_BASIC__) && !defined(__UBL__))
            nandlog_print("CE%d ID = %x %x %x %x %x %x %x %x\r\n", cs,
             	id_data[0]&0xff, (id_data[0]>>8)&0xff, (id_data[0]>>16)&0xff, (id_data[0]>>24)&0xff,
             	id_data[1]&0xff, (id_data[1]>>8)&0xff, (id_data[1]>>16)&0xff, (id_data[1]>>24)&0xff);
            
#endif



        force_ASSERT ( MTD_STATUS_NO_ERROR == ID_Table_OrderCheck(),0,0,0 );

		FindFromFlashList = KAL_FALSE;
        kal_mem_set( Flash_Info.deviceInfo_CE[cs].ID_info, 0xFF, sizeof(Flash_Info.deviceInfo_CE[cs].ID_info) ); /*Reset value*/
        for (i = 0; NAND_ID_Table[i].ID_info[0] != 0xFF ; i++)
        {
            for (j=0;j<sizeof(NAND_ID_Table[0].ID_valid_mask);j++ )
            {
                if ( ( ((kal_uint8*)id_data)[j] & NAND_ID_Table[i].ID_valid_mask[j] ) !=
                     ( NAND_ID_Table[i].ID_info[j] & NAND_ID_Table[i].ID_valid_mask[j]) )
                    break;
            }
            if ( j == sizeof(NAND_ID_Table[0].ID_valid_mask) )
            {
                /*case of match*/ /*here means find device at NAND_ID_Table*/
                if ( MTD_STATUS_ERROR == FlashAttrib_AutoDetect((flash_list *)&NAND_ID_Table[i], &Flash_Info.deviceInfo_CE[cs]) )
                {
                	// NAND is in flash list but not in device ID list. Something wrong.
#if !defined(__UBL__)
		            nandlog_print("NAND ID detect error!\r\n");
#endif
                    force_ASSERT ( 0,0,0,0 );
                }
                FindFromFlashList = KAL_TRUE;
                break;
            }
        }

		if (FindFromFlashList==KAL_FALSE)
		{
            for (i=0; i<sizeof(NAND_ID_Table[0].ID_valid_mask);i++ )
            {
                Default_ID_Table.ID_info[i] = ((kal_uint8*)id_data)[i];
            }
			if (FlashAttrib_AutoDetect(&Default_ID_Table, &Flash_Info.deviceInfo_CE[cs])==MTD_STATUS_NO_ERROR) {
				FindFromFlashList = KAL_TRUE;
			}
		}

		if (FindFromFlashList==KAL_TRUE)
		{
            kal_uint8 k, sum;

            /* Flash_Info.deviceInfo_CE[cs] check, parameter should be order of 2 - start*/
            for (k=0, sum=0 ;k< sizeof(NAND_ID_Table[0].dieNum)*8;k++)
                sum += ((Flash_Info.deviceInfo_CE[cs].dieNum >> k) & 0x01);
            force_ASSERT( sum == 1, i, Flash_Info.deviceInfo_CE[cs].dieNum, sum);
            for (k=0, sum=0 ;k< sizeof(NAND_ID_Table[0].planeNum)*8;k++)
                sum += ((Flash_Info.deviceInfo_CE[cs].planeNum >> k) & 0x01);
            force_ASSERT( sum == 1, i, Flash_Info.deviceInfo_CE[cs].planeNum, sum);
            for (k=0, sum=0 ;k< sizeof(NAND_ID_Table[0].blockPage)*8;k++)
                sum += ((Flash_Info.deviceInfo_CE[cs].blockPage >> k) & 0x01);
            force_ASSERT( sum == 1, i, Flash_Info.deviceInfo_CE[cs].blockPage, sum);
            for (k=0, sum=0 ;k< sizeof(NAND_ID_Table[0].deviceSize)*8;k++)
                sum += ((Flash_Info.deviceInfo_CE[cs].deviceSize >> k) & 0x01);
            force_ASSERT( sum == 1, i, NAND_ID_Table[0].deviceSize, sum);

            force_ASSERT( (Flash_Info.deviceInfo_CE[cs].supportMPType&(PLANE_INTERLACED|PLANE_CONTINUOUS)) != (PLANE_INTERLACED|PLANE_CONTINUOUS),
                        Flash_Info.deviceInfo_CE[cs].supportMPType,0,0);
            force_ASSERT( (Flash_Info.deviceInfo_CE[cs].supportMPType&(PLANE_INTERLACED|EXTENDED_BLOCK)) != (PLANE_INTERLACED|EXTENDED_BLOCK),
                        Flash_Info.deviceInfo_CE[cs].supportMPType,0,0);
            if ( (Flash_Info.deviceInfo_CE[cs].supportMPType&(TWO_PLANE_OP|FOUR_PLANE_OP)) != 0 ) /*must define PLANE_INTERLACED or PLANE_CONTINUOUS in multi-plane*/
            {
                force_ASSERT( (Flash_Info.deviceInfo_CE[cs].supportMPType&(PLANE_INTERLACED|PLANE_CONTINUOUS)) != 0,
                            Flash_Info.deviceInfo_CE[cs].supportMPType,0,0);
            }

            Flash_Info.valid_CE[cs]   = KAL_TRUE;
            Flash_Info.devicePage[cs] = Flash_Info.deviceInfo_CE[cs].deviceSize * (1024 * 1024 / Flash_Info.deviceInfo_CE[cs].pageSize) ;
            Flash_Info.diePage[cs]    = Flash_Info.devicePage[cs] / Flash_Info.deviceInfo_CE[cs].dieNum ;
            Flash_Info.planePage[cs]  = Flash_Info.devicePage[cs] / Flash_Info.deviceInfo_CE[cs].dieNum / Flash_Info.deviceInfo_CE[cs].planeNum ;

            totalSize += Flash_Info.deviceInfo_CE[cs].deviceSize * 1024 * 1024;
		}

        if (cs == 0)
        {
            if( Flash_Info.valid_CE[0] == KAL_FALSE )
            {
                return MTD_STATUS_ID_NOT_SUPPORT;
            }
        }
        else if(cs == 1)
        {
            SET_NFI_CS1_END;
        }
    }

    #if (defined(_NAND_FLASH_BOOTING_) || defined(__NANDFDM_MULTI_INSTANCE__) || (defined(__UP_PKG_ON_NAND__) && defined(NAND_SUPPORT)) ) && !defined(__UBL__)
#if !defined(__NANDFDM_MULTI_INSTANCE__)
    dbg_ASSERT(totalSize >= NFB_ALLOCATED_FAT_SPACE + NFB_BASE_ADDRESS);
#else  // !defined(__NANDFDM_MULTI_INSTANCE__)
    dbg_ASSERT(totalSize >= NFB_ALLOCATED_FAT_SPACE[CurDiskIndex] + NFB_BASE_ADDRESS[CurDiskIndex]);
#endif  // !defined(__NANDFDM_MULTI_INSTANCE__)
    #endif

    //D->flash_info.region_num = D->flash_info.block_num/R_BLOCKS;  /*D->flash_info.region_num is decided at FDM layer FindControlBadBlock()*/

    return MTD_STATUS_NO_ERROR;

}
#if defined(__COMBO_MEMORY_SUPPORT__)
void MTD_ReadID(kal_uint32 id_num,kal_uint8* id_data)
{
  kal_mem_cpy(id_data,ComboNANDID,id_num );
}
#endif
/****************************************************************************
 * Function:    single_Page_Program
 *
 * Parameters:  mtd_drv_para *para
 *
 * Returns:   MTD_STATUS_NO_ERROR   No error
 *            MTD_STATUS_ERROR + index of error page (Low 16 bits)
 * Description: It will send: cmd1, add, data, cmd2 to NAND
 *
 ****************************************************************************/
kal_uint32 single_Page_Program (mtd_drv_para *para)
{
    kal_uint8 status;
		#if (defined __UBL__)||(defined __FUE__)    
		#else
    kal_uint32 event_group;
    #endif
    dbg_ASSERT(!(para->opFlag & SAMSUNG_D0_ILEAVE_OP) || (para->opFlag & SAMSUNG_D1_ILEAVE_OP));
    if (para->opFlag & FIRST_PROCESS)
    {
        NFI_OP_RESET();
        if (Flash_Info.pageSize == 512)
        {
            NFI_Pointer(0x00);

            #if !defined(__NFI_VERSION3_1__)
            Cmd_info.add[0] = (*para->page_p + para->pageOffset)<<8 ;
            #endif // !defined(__NFI_VERSION3_1__)

            dbg_ASSERT( para->addCycle <=4 );/*No dice with 512 page and cycle > 4*/
            //Cmd_info.add[1] = (*para->page_p)>>24 ; /*No dice with 512 page and cycle > 4*/
        }
        else
        {
        	#if !defined(__NFI_VERSION3_1__)
            Cmd_info.add[0] = (*para->page_p + para->pageOffset)<<16 ;
            Cmd_info.add[1] = (*para->page_p + para->pageOffset)>>16 ;
            #endif // !defined(__NFI_VERSION3_1__)
        }

		#if defined(__NFI_VERSION3_1__)
		Cmd_info.add[0] = 0; 	// Colume address
        Cmd_info.add[1] = *para->page_p + para->pageOffset; 	// Row address
        *NFI_CNFG = CNFG_OP_PRGM | CNFG_AUTO_FMT_EN;
        *NFI_CON = (Flash_Info.pageSize >> 9) << CON_NFI_SEC_SHIFT;
		#endif  // defined(__NFI_VERSION3_1__)

        dbg_ASSERT( (*para->page_p/Flash_Info.blockPage) == (*para->page_p + para->pageOffset)/Flash_Info.blockPage ); /*in same block*/
        // dbg_ASSERT( para->buff  );  // FUE may program buffer 0.
        Cmd_info.buff = para->buff;
        dbg_ASSERT( Flash_Info.pageSize%512 == 0 );
        Cmd_info.buff_len = Flash_Info.pageSize;
        dbg_ASSERT( para->spare );
        Cmd_info.spare = para->spare;

        #if defined(__NFI_VERSION3_1__)
        Cmd_info.spare_len = PAGEFMT_FDM_DEFAULT;
        Cmd_info.CustomMode = 0;
		#else // defined(__NFI_VERSION3_1__)
        Cmd_info.spare_len = Flash_Info.spareSize;
		#endif // defined(__NFI_VERSION3_1__)

        Cmd_info.intFlag = 0; /*Reset*/
        if (para->opFlag & SECOND_BUSY) /*here means FIRST_PROCESS + SECOND_BUSY*/
        {
        	#if (defined __UBL__)||(defined __FUE__)
	        #else
            if (nfi_egid && use_interrupt == KAL_TRUE)
                Cmd_info.intFlag = BUSY_RETURN_EN;
          #endif
        }
        Cmd_info.ECCFlag = ECC_WHOLE;
        Cmd_info.add_cycle = para->addCycle;
        Cmd_info.cmd_len = 2;

#if ( defined(__NAND_FLASH_HARDWARE_TEST__) && defined(__MAUI_BASIC__) && defined(__FDM_DEBUG__) && !defined(__UBL__))
		if (ResetInNextBusy==KAL_TRUE) {
			nandlog_print("Page:0x%xh !! busy program content !!\r\n",((Cmd_info.add[1]<<16)|(Cmd_info.add[0]>>16)));
			
			dump_memory_to_uart_log((kal_uint32*)Cmd_info.buff, Flash_Info.pageSize);
		}
#endif		
        send_command_add_data(0x80, 0x10, &Cmd_info);

        #if defined(__NFI_VERSION3_1__)
        *NFI_CNRNB = STROBE_TIMEOUT;
        #endif

#if ( defined(__NAND_FLASH_HARDWARE_TEST__) && defined(__MAUI_BASIC__) && !defined(__UBL__))
		if ((ProfileDetail==KAL_TRUE) && (FDM_UT_Item==10)) {
			wSBusyTimeW = ust_get_current_time();
			wTotalBusyNumW++;
		}

		if (ResetInNextBusy==KAL_TRUE) {
			NANDTest_Reset();
		}
#endif // ( defined(__NAND_FLASH_HARDWARE_TEST__) && defined(__MAUI_BASIC__) && !defined(__UBL__))

        if (para->opFlag & SECOND_BUSY) /*here means FIRST_PROCESS + SECOND_BUSY*/
        {
 	        	#if (defined __UBL__)||(defined __FUE__)
	        	#else
            if (nfi_egid && use_interrupt == KAL_TRUE)
            {
                kal_retrieve_eg_events(nfi_egid, NFI_EVENT, KAL_OR_CONSUME,
                                       &event_group, KAL_SUSPEND);
            }
            #endif
        }
    }
    if (para->opFlag & SECOND_BUSY)
    {
        Cmd_info.add_cycle = 0;
        while (!((status = read_status(0x70,&Cmd_info) )&RDY_BUSY)); /*Program busy*/

#if ( defined(__NAND_FLASH_HARDWARE_TEST__) && defined(__MAUI_BASIC__) && !defined(__UBL__))
		if ((ProfileDetail==KAL_TRUE) && (FDM_UT_Item==10)) {
			wEBusyTimeW = ust_get_current_time();
			wTotalBusyTimeW += ust_get_duration(wSBusyTimeW, wEBusyTimeW);
		}

		if ((PFTrigger==KAL_TRUE) && (PFTestCase & PF_MTD_TRIGGER)) {
			kal_uint8 Count;
			kal_uint32 PageAddr;

			PFTrigger = KAL_FALSE;
			Count=0;
			while (1) {
				if (ProgBadAddr[Count].Zone==0xff) {
					break;
				}
				PageAddr = (*para->page_p + para->pageOffset);
		        if (Flash_Info.pageSize == 512) {
		        	if ( (((ProgBadAddr[Count].Block<<5)+ProgBadAddr[Count].Page) == PageAddr) ||
		        		 ((ProgBadAddr[Count].Page==0xffff) && (ProgBadAddr[Count].Block == (PageAddr>>5))) ) {
		        		status |= PASS_FAIL;
		        		break;
		        	}
		        } else {
		        	if ( (((ProgBadAddr[Count].Block<<6)+ProgBadAddr[Count].Page) == PageAddr) ||
		        		 ((ProgBadAddr[Count].Page==0xffff) && (ProgBadAddr[Count].Block == (PageAddr>>6))) ) {
		        		status |= PASS_FAIL;
		        		break;
		        	}
		        }
				Count++;
			}

		}
#endif

        if (status&PASS_FAIL)
        {
            nAND_RESET();
            return (MTD_STATUS_ERROR|1);
        }
    }
    return MTD_STATUS_NO_ERROR;
}

/****************************************************************************
 * Function:    single_Page_CacheProgram
 *
 * Parameters:  mtd_drv_para *para
 *
 * Returns:   MTD_STATUS_NO_ERROR   No error
 *            MTD_STATUS_ERROR + index of error page (Low 16 bits)
 * Description: single page cache program function.
 *              [Note] The start page must match para->pageOffset == 0, max para->pageOffset can not over 15
 ****************************************************************************/
kal_uint32 single_Page_CacheProgram (mtd_drv_para *para)
{
    kal_uint8 status;
 		#if (defined __UBL__)||(defined __FUE__)    
		#else
    kal_uint32 event_group;
    #endif

    dbg_ASSERT( para->pageOffset < 16); /*Limited by return value*/
    if (para->opFlag & FIRST_PROCESS)
    {
        NFI_OP_RESET();
        if (Flash_Info.pageSize == 512)
        {
            NFI_Pointer(0x00);

            #if !defined(__NFI_VERSION3_1__)
            Cmd_info.add[0] = (*para->page_p + para->pageOffset)<<8 ;
            #endif // !defined(__NFI_VERSION3_1__)

            dbg_ASSERT( para->addCycle <=4 );/*No dice with 512 page and cycle > 4*/
            //Cmd_info.add[1] = (*para->page_p)>>24 ; /*No dice with 512 page and cycle > 4*/
        }
        else
        {
        	#if !defined(__NFI_VERSION3_1__)
            Cmd_info.add[0] = (*para->page_p + para->pageOffset)<<16 ;
            Cmd_info.add[1] = (*para->page_p + para->pageOffset)>>16 ;
            #endif // !defined(__NFI_VERSION3_1__)
        }

		#if defined(__NFI_VERSION3_1__)
		Cmd_info.add[0] = 0; 	// Colume address
        Cmd_info.add[1] = *para->page_p + para->pageOffset; 	// Row address
        *NFI_CNFG = CNFG_OP_CUST | CNFG_AUTO_FMT_EN;
        *NFI_CON = (Flash_Info.pageSize >> 9) << CON_NFI_SEC_SHIFT;
		#endif  // defined(__NFI_VERSION3_1__)

        dbg_ASSERT( (*para->page_p/Flash_Info.blockPage) == (*para->page_p + para->pageOffset)/Flash_Info.blockPage ); /*in same block*/
        //dbg_ASSERT( para->buff  );
        Cmd_info.buff = para->buff;
        dbg_ASSERT( Flash_Info.pageSize%512 == 0 );
        Cmd_info.buff_len = Flash_Info.pageSize;
        dbg_ASSERT( para->spare );
        Cmd_info.spare = para->spare;

        #if defined(__NFI_VERSION3_1__)
        Cmd_info.spare_len = PAGEFMT_FDM_DEFAULT;
        Cmd_info.CustomMode = 1;
		#else // defined(__NFI_VERSION3_1__)
        Cmd_info.spare_len = Flash_Info.spareSize;
		#endif // defined(__NFI_VERSION3_1__)

        Cmd_info.intFlag = 0; /*Reset*/
        if (para->opFlag & SECOND_BUSY) /*here means FIRST_PROCESS + SECOND_BUSY*/
        {
 	        #if (defined __UBL__)||(defined __FUE__)
	        #else
            if (nfi_egid && use_interrupt == KAL_TRUE)
                Cmd_info.intFlag = BUSY_RETURN_EN;
          #endif
        }
        Cmd_info.ECCFlag = ECC_WHOLE;
        Cmd_info.add_cycle = para->addCycle;
        Cmd_info.cmd_len = 2;
#if ( defined(__NAND_FLASH_HARDWARE_TEST__) && defined(__MAUI_BASIC__) && defined(__FDM_DEBUG__) && !defined(__UBL__))
		if (ResetInNextBusy==KAL_TRUE) {
			nandlog_print("Page:0x%xh !! busy program content !!\r\n",((Cmd_info.add[1]<<16)|(Cmd_info.add[0]>>16)));
			
			dump_memory_to_uart_log((kal_uint32*)Cmd_info.buff, Flash_Info.pageSize);
		}
#endif
        if ( para->opFlag & PROGRAM_CACHED)
            send_command_add_data(0x80, 0x15, &Cmd_info);
        else if ( para->opFlag & PROGRAM_FINAL)
            send_command_add_data(0x80, 0x10, &Cmd_info);

        #if defined(__NFI_VERSION3_1__)
        *NFI_CNRNB = STROBE_TIMEOUT;
        #endif

#if ( defined(__NAND_FLASH_HARDWARE_TEST__) && defined(__MAUI_BASIC__) && !defined(__UBL__))
		if ((ProfileDetail==KAL_TRUE) && (FDM_UT_Item==10)) {
			wSBusyTimeW = ust_get_current_time();
			wTotalBusyNumW++;
		}

		if (ResetInNextBusy==KAL_TRUE) {
			NANDTest_Reset();
		}
#endif

        if (para->opFlag & SECOND_BUSY) /*here means FIRST_PROCESS + SECOND_BUSY*/
        {
	        #if (defined __UBL__)||(defined __FUE__)
	        #else        
            if (nfi_egid && use_interrupt == KAL_TRUE)
            {
                kal_retrieve_eg_events(nfi_egid, NFI_EVENT, KAL_OR_CONSUME,
                                       &event_group, KAL_SUSPEND);
            }
					#endif            
        }
    }
    if (para->opFlag & SECOND_BUSY)
    {
        kal_uint8 status_chk;
        Cmd_info.add_cycle = 0;
        while (!((status = read_status(0x70,&Cmd_info) )&RDY_BUSY));

        if ( ( para->opFlag & PROGRAM_CACHED)&& para->pageOffset == 0)
            status_chk = 0x00;  /*invalid*/
        else if ( para->opFlag & PROGRAM_FINAL)
            status_chk = 0x01|0x02; /*previous + current*/
        else
            status_chk = 0x02; /*previous*/

#if ( defined(__NAND_FLASH_HARDWARE_TEST__) && defined(__MAUI_BASIC__) && !defined(__UBL__))
		if ((ProfileDetail==KAL_TRUE) && (FDM_UT_Item==10)) {
			wEBusyTimeW = ust_get_current_time();
			wTotalBusyTimeW += ust_get_duration(wSBusyTimeW, wEBusyTimeW);
		}

		if (status_chk & 0x03) {
			if ((PFTrigger==KAL_TRUE) && (PFTestCase & PF_MTD_TRIGGER)) {
				kal_uint8 Count;
				kal_uint32 PageAddr;

				PFTrigger = KAL_FALSE;
				Count=0;
				while (1) {
					if (ProgBadAddr[Count].Zone==0xff) {
						break;
					}
	        		if (status_chk & 0x01) {
						PageAddr = (*para->page_p + para->pageOffset);
	        		}
else
{
						PageAddr = (*para->page_p + para->pageOffset - 1);
	        		}
			        if (Flash_Info.pageSize == 512) {
			        	if ( (((ProgBadAddr[Count].Block<<5)+ProgBadAddr[Count].Page) == PageAddr) ||
			        		 ((ProgBadAddr[Count].Page==0xffff) && (ProgBadAddr[Count].Block==(PageAddr>>5))) ) {
			        		if (status_chk & 0x01) {
				        		status |= 0x01;
			        		} else {
				        		status |= 0x02;
			        		}
			        		break;
			        	}
			        } else {
			        	if ( (((ProgBadAddr[Count].Block<<6)+ProgBadAddr[Count].Page) == PageAddr) ||
			        		 ((ProgBadAddr[Count].Page==0xffff) && (ProgBadAddr[Count].Block==(PageAddr>>6))) ) {
			        		if (status_chk & 0x01) {
				        		status |= 0x01;
			        		} else {
				        		status |= 0x02;
			        		}
			        		break;
			        	}
			        }
					Count++;
				}
			}
		}
#endif

        if (status&status_chk)
        {
            while (!((status = read_status(0x70,&Cmd_info) )&INTERNAL_BUSY));
            nAND_RESET();
            return (MTD_STATUS_ERROR|1);
        }
    }
    return MTD_STATUS_NO_ERROR;
}

/****************************************************************************
 * Function:    single_Page_Program
 *
 * Parameters:  mtd_drv_para *para
 *
 * Returns:   MTD_STATUS_NO_ERROR   No error
 *            MTD_STATUS_ERROR + index of error page (Low 16 bits)
 * Description: It will send: cmd1, add, data, cmd2 to NAND
 *
 ****************************************************************************/
kal_uint32 single_Page_Read (mtd_drv_para *para)
{
    kal_uint8 status;
    kal_uint32 retVal;

    #if (defined __UBL__) || (defined __FUE__)
    /*It's possible to read code to 0x0 at bootloader*/
    #else
    dbg_ASSERT( para->buff  );
    #endif
    Cmd_info.buff = para->buff;
    dbg_ASSERT( Flash_Info.pageSize%512 == 0 );
    Cmd_info.buff_len = Flash_Info.pageSize;
    //dbg_ASSERT( para->spare );
    Cmd_info.spare = para->spare;

    #if defined(__NFI_VERSION3_1__)
    Cmd_info.spare_len = PAGEFMT_FDM_DEFAULT;
    Cmd_info.CustomMode = 0;
	#else // defined(__NFI_VERSION3_1__)
    Cmd_info.spare_len = Flash_Info.spareSize;
	#endif // defined(__NFI_VERSION3_1__)

    Cmd_info.ECCFlag = ECC_WHOLE;

    if (para->opFlag & FIRST_PROCESS)
    {
        NFI_OP_RESET();
        if (Flash_Info.pageSize == 512)
        {
            NFI_Pointer(0x00);

			#if !defined(__NFI_VERSION3_1__)

            Cmd_info.add[0] = (*para->page_p + para->pageOffset)<<8 ;
            dbg_ASSERT( para->addCycle <=4 );/*No dice with 512 page and cycle > 4*/
            //Cmd_info.add[1] = (*para->page_p)>>24 ; /*No dice with 512 page and cycle > 4*/

			#endif
        }
        else
        {
			#if !defined(__NFI_VERSION3_1__)

            Cmd_info.add[0] = (*para->page_p + para->pageOffset)<<16 ;
            Cmd_info.add[1] = (*para->page_p + para->pageOffset)>>16 ;

			#endif
        }

		#if defined(__NFI_VERSION3_1__)

		Cmd_info.add[0] = 0; 	// Colume address
        Cmd_info.add[1] = *para->page_p + para->pageOffset; 	// Row address
        *NFI_CNFG = CNFG_OP_READ | CNFG_AUTO_FMT_EN | CNFG_READ_EN;
		*NFI_CON = (Flash_Info.pageSize >> 9) << CON_NFI_SEC_SHIFT;

		#endif
        //dbg_ASSERT( (*para->page_p/Flash_Info.blockPage) == (*para->page_p + para->pageOffset)/Flash_Info.blockPage ); /*in same block*/

        Cmd_info.intFlag = 0;
        Cmd_info.add_cycle = para->addCycle;

        if (Flash_Info.pageSize == 512)
        {
            Cmd_info.cmd_len = 1;
            send_command_add(0x00, 0, &Cmd_info);
        }
        else
        {
            Cmd_info.cmd_len = 2;

            send_command_add(0x00, 0x30, &Cmd_info);
        }

#if ( defined(__NAND_FLASH_HARDWARE_TEST__) && defined(__MAUI_BASIC__) && !defined(__UBL__))
		if ((ProfileDetail==KAL_TRUE) && (FDM_UT_Item==10)) {
      		wSBusyTimeR   = ust_get_current_time();
			wTotalBusyNumR++;
		}
#endif // ( defined(__NAND_FLASH_HARDWARE_TEST__) && defined(__MAUI_BASIC__) && !defined(__UBL__))

		// Disable this now because read busy time should be long enough. If hang here, it is a good point to check here.
  /*    #if defined(__NFI_VERSION3_1__)

        *NFI_CNRNB = STROBE_TIMEOUT;

        #endif
    */
    }
    if (para->opFlag & SECOND_BUSY)
    {
        if (!(para->opFlag & FIRST_PROCESS))
        {
            Cmd_info.add_cycle = 0;
            while (!((status = read_status(0x70,&Cmd_info) )&RDY_BUSY));

            if (status&PASS_FAIL)
            {
                nAND_RESET();
                return (MTD_STATUS_ERROR|1);
            }
            *NFI_CMD = 0x00;    // read command

			#if defined(__NFI_VERSION3_1__)
            while ((*NFI_STA) & STA_CMD_STATE);
			#else // defined(__NFI_VERSION3_1__)
            while (*NFI_PSTA & STATUS_CMD);
            #endif // defined(__NFI_VERSION3_1__)

            NFI_OP_RESET();
        }
        retVal = readfifo(&Cmd_info);
        if (retVal == MTD_STATUS_ERROR)
        {
            nAND_RESET();
            return (MTD_STATUS_ERROR|1);
        }
        else if (retVal == MTD_STATUS_CORRECTED)
        {
            return (retVal|1);
        }
    }
    return MTD_STATUS_NO_ERROR;
}

/****************************************************************************
 * Function:    single_Block_Erase
 *
 * Parameters:  mtd_drv_para *para
 *
 * Returns:   MTD_STATUS_NO_ERROR   No error
 *            MTD_STATUS_ERROR + index of error page (Low 16 bits)
 * Description:
 *
 ****************************************************************************/
kal_uint32 single_Block_Erase (mtd_drv_para *para)
{
    kal_uint8 status;
		#if (defined __UBL__)||(defined __FUE__)    
		#else
    kal_uint32 event_group;
    #endif


    if (para->opFlag & FIRST_PROCESS)
    {
        NFI_OP_RESET();
        Cmd_info.add[0] = (*para->page_p + para->pageOffset) ;
        if (Flash_Info.pageSize == 512)
        {
            NFI_Pointer(0x00);
            Cmd_info.add_cycle = para->addCycle - 1;
            dbg_ASSERT( para->addCycle <=4 );/*No device with 512 page and cycle > 4*/
        }
        else /*2048*/
        {
            Cmd_info.add_cycle = para->addCycle - 2;
            dbg_ASSERT( para->addCycle <=6 );
        }
        //dbg_ASSERT( (*para->page_p/Flash_Info.blockPage) == (*para->page_p + para->pageOffset)/Flash_Info.blockPage ); /*in same block*/
        Cmd_info.intFlag = 0; /*Reset*/
        if (para->opFlag & SECOND_BUSY) /*here means FIRST_PROCESS + SECOND_BUSY*/
        {
 	        #if (defined __UBL__)||(defined __FUE__)
	        #else
            if (nfi_egid && use_interrupt == KAL_TRUE)
                Cmd_info.intFlag = BUSY_RETURN_EN;/*Cmd_info.intFlag = ERASE_COMPLETE_EN;*/
          #endif
        }
        Cmd_info.cmd_len = 2;

		#if defined(__NFI_VERSION3_1__)
        *NFI_CNFG = CNFG_OP_ERASE;
        *NFI_CON = (Flash_Info.pageSize >> 9) << CON_NFI_SEC_SHIFT;
		send_command_rowadd (0x60, 0xD0, &Cmd_info);
        *NFI_CNRNB = STROBE_TIMEOUT;
        #else // defined(__NFI_VERSION3_1__)
        send_command_add(0x60, 0xD0, &Cmd_info);
        #endif

#if ( defined(__NAND_FLASH_HARDWARE_TEST__) && defined(__MAUI_BASIC__) && !defined(__UBL__))
		if (ResetInNextBusy==KAL_TRUE) {
			NANDTest_Reset();
		}
#endif
        if (para->opFlag & SECOND_BUSY) /*here means FIRST_PROCESS + SECOND_BUSY*/
        {
	        	#if (defined __UBL__)||(defined __FUE__)
	        	#else        
            if (nfi_egid && use_interrupt == KAL_TRUE)
            {
                kal_retrieve_eg_events(nfi_egid, NFI_EVENT, KAL_OR_CONSUME,
                                       &event_group, KAL_SUSPEND);
            }
            #endif
        }
    }
    if (para->opFlag & SECOND_BUSY)
    {
        Cmd_info.add_cycle = 0;
        while (!((status = read_status(0x70,&Cmd_info) )&RDY_BUSY));

#if ( defined(__NAND_FLASH_HARDWARE_TEST__) && defined(__MAUI_BASIC__) && !defined(__UBL__))
		if ((EFTrigger==KAL_TRUE) && (EFTestCase & EF_MTD_TRIGGER)) {
			kal_uint8 Count;

			EFTrigger = KAL_FALSE;
			Count=0;
			while (1) {
				if (EraseBadAddr[Count].Zone==0xff) {
					break;
				}
		        if (Flash_Info.pageSize == 512) {
		        	if ( (EraseBadAddr[Count].Block<<5) == (*para->page_p + para->pageOffset) ) {
		        		status |= 0x01;
		        		break;
		        	}
		        } else {
		        	if ( (EraseBadAddr[Count].Block<<6) == (*para->page_p + para->pageOffset) ) {
		        		status |= 0x01;
		        		break;
		        	}
		        }
				Count++;
			}
		}
#endif
        if (status&PASS_FAIL)
        {
            nAND_RESET();
            return (MTD_STATUS_ERROR|1);
        }
    }
    return MTD_STATUS_NO_ERROR;
}


kal_uint32 toshiba_twoPlane_Program (mtd_drv_para *para)
{
    kal_uint8 status;
    kal_uint32 retVal;
		#if (defined __UBL__) || (defined __FUE__) 
		#else
    	kal_uint32 event_group;    
    #endif
        
    dbg_ASSERT( Flash_Info.pageSize >= 2048 );
    if (para->opFlag & FIRST_PROCESS)
    {
        /*plane 0*/
        NFI_OP_RESET();
        /*Fill Cmd_info - start*/

        #if defined(__NFI_VERSION3_1__)
		Cmd_info.add[0] = 0; 	// Colume address
        Cmd_info.add[1] = *para->page_p + para->pageOffset; 	// Row address
        *NFI_CNFG = CNFG_OP_CUST | CNFG_AUTO_FMT_EN;
        *NFI_CON = (Flash_Info.pageSize >> 9) << CON_NFI_SEC_SHIFT;
        #else // defined(__NFI_VERSION3_1__)
        Cmd_info.add[0] = (*para->page_p + para->pageOffset)<<16 ;
        Cmd_info.add[1] = (*para->page_p + para->pageOffset)>>16 ;
        #endif // defined(__NFI_VERSION3_1__)

        dbg_ASSERT( (*para->page_p/Flash_Info.blockPage) == (*para->page_p + para->pageOffset)/Flash_Info.blockPage ); /*in same block*/
        //dbg_ASSERT( para->buff  );
        Cmd_info.buff = para->buff;
        dbg_ASSERT( Flash_Info.pageSize%512 == 0 );
        Cmd_info.buff_len = Flash_Info.pageSize;
        dbg_ASSERT( para->spare );
        Cmd_info.spare = para->spare;

        #if defined(__NFI_VERSION3_1__)
        Cmd_info.spare_len = PAGEFMT_FDM_DEFAULT;
        Cmd_info.CustomMode = 1;
		#else // defined(__NFI_VERSION3_1__)
        Cmd_info.spare_len = Flash_Info.spareSize;
		#endif // defined(__NFI_VERSION3_1__)

        Cmd_info.ECCFlag = ECC_WHOLE;
        Cmd_info.add_cycle = para->addCycle;
        Cmd_info.cmd_len = 2;
        Cmd_info.intFlag = 0; /*Reset*/
        /*Fill Cmd_info - end*/
        send_command_add_data(0x80, 0x11, &Cmd_info);

        Cmd_info.add_cycle = 0;
        while (!((status = read_status(0x71,&Cmd_info) )&RDY_BUSY)); /*Dummy busy*/
        if (status&PASS_FAIL)
        {
            nAND_RESET();
            return (MTD_STATUS_ERROR|1);
        }
        /*plane 1*/
        NFI_OP_RESET();
        /*Fill Cmd_info - start*/

        #if defined(__NFI_VERSION3_1__)
		Cmd_info.add[0] = 0; 	// Colume address
        Cmd_info.add[1] = *(para->page_p+1) + para->pageOffset; 	// Row address
        *NFI_CNFG = CNFG_OP_CUST | CNFG_AUTO_FMT_EN;
        *NFI_CON = (Flash_Info.pageSize >> 9) << CON_NFI_SEC_SHIFT;
        #else // defined(__NFI_VERSION3_1__)
        Cmd_info.add[0] = (*(para->page_p+1) + para->pageOffset)<<16 ;
        Cmd_info.add[1] = (*(para->page_p+1) + para->pageOffset)>>16 ;
        #endif // defined(__NFI_VERSION3_1__)

        dbg_ASSERT( (*(para->page_p+1)/Flash_Info.blockPage) == (*(para->page_p+1) + para->pageOffset)/Flash_Info.blockPage ); /*in same block*/
        //dbg_ASSERT( para->buff  );
        //dbg_ASSERT( Flash_Info.pageSize%512 == 0 );
        Cmd_info.buff = &para->buff[0 + Flash_Info.pageSize];;
        Cmd_info.buff_len = Flash_Info.pageSize;
        //dbg_ASSERT( para->spare );
        if (para->opFlag & ONE_SPARE) {
	        Cmd_info.spare = &para->spare[0];
        } else {
	        Cmd_info.spare = &para->spare[0 + Flash_Info.spareSize];
        }

        #if defined(__NFI_VERSION3_1__)
        Cmd_info.spare_len = PAGEFMT_FDM_DEFAULT;
        Cmd_info.CustomMode = 1;
		#else // defined(__NFI_VERSION3_1__)
        Cmd_info.spare_len = Flash_Info.spareSize;
		#endif // defined(__NFI_VERSION3_1__)

        Cmd_info.ECCFlag = ECC_WHOLE;
        Cmd_info.add_cycle = para->addCycle;
        Cmd_info.cmd_len = 2;
        /*Fill Cmd_info - end*/
        Cmd_info.intFlag = 0; /*Reset*/
        if (para->opFlag & SECOND_BUSY)
        {
	        #if (defined __UBL__)||(defined __FUE__)
	        #else        
            if (nfi_egid && use_interrupt == KAL_TRUE)
                Cmd_info.intFlag = BUSY_RETURN_EN;
          #endif
        }
        send_command_add_data(0x80, 0x10, &Cmd_info);
        #if defined(__NFI_VERSION3_1__)
        *NFI_CNRNB = STROBE_TIMEOUT;
        #endif
        if (para->opFlag & SECOND_BUSY) /*here means FIRST_PROCESS + SECOND_BUSY*/
        {
	        #if (defined __UBL__)||(defined __FUE__)
	        #else        
            if (nfi_egid && use_interrupt == KAL_TRUE)
            {
                kal_retrieve_eg_events(nfi_egid, NFI_EVENT, KAL_OR_CONSUME,
                                       &event_group, KAL_SUSPEND);
            }
					#endif
        }
    }
    if (para->opFlag & SECOND_BUSY)
    {
        Cmd_info.add_cycle = 0;
        while (!((status = read_status(0x71,&Cmd_info) )&RDY_BUSY)); /*Program busy*/
        if (status&PASS_FAIL)
        {   /*Program fail*/
            retVal = MTD_STATUS_ERROR;
            /*check plane 0*/
            if (status& 0x02 ) /*plane 0 status*/
                retVal |= (1);

            /*check plane 1*/
            if (status& 0x04 ) /*plane 1 status*/
                retVal |= (1<<1);
            nAND_RESET();
            return retVal;
        }
    }
    return MTD_STATUS_NO_ERROR;
}


kal_uint32 toshiba_twoPlane_Erase (mtd_drv_para *para)
{
    kal_uint8 status;
    kal_uint32 retVal;
		#if (defined __UBL__) || (defined __FUE__) 
		#else
    	kal_uint32 event_group;    
    #endif

    dbg_ASSERT( Flash_Info.pageSize >= 2048 );
    if (para->opFlag & FIRST_PROCESS)
    {
        /*plane 0*/
        NFI_OP_RESET();
        /*Fill Cmd_info - start*/
        Cmd_info.add[0] = (*para->page_p + para->pageOffset) ;
        dbg_ASSERT( (*para->page_p/Flash_Info.blockPage) == (*para->page_p + para->pageOffset)/Flash_Info.blockPage ); /*in same block*/
        dbg_ASSERT( Flash_Info.pageSize%512 == 0 );
        Cmd_info.add_cycle = para->addCycle - 2;
        Cmd_info.cmd_len = 1;
        Cmd_info.intFlag = 0; /*Reset*/
        /*Fill Cmd_info - end*/
		#if defined(__NFI_VERSION3_1__)
        *NFI_CNFG = CNFG_OP_CUST;
        *NFI_CON = (Flash_Info.pageSize >> 9) << CON_NFI_SEC_SHIFT;
		send_command_rowadd (0x60, 0, &Cmd_info);
        #else // defined(__NFI_VERSION3_1__)
        send_command_add(0x60, 0, &Cmd_info);
        #endif // defined(__NFI_VERSION3_1__)

        /*plane 1*/
        NFI_OP_RESET();
        Cmd_info.add[0] = (*(para->page_p+1) + para->pageOffset) ;
        dbg_ASSERT( (*(para->page_p+1)/Flash_Info.blockPage) == (*(para->page_p+1) + para->pageOffset)/Flash_Info.blockPage ); /*in same block*/
        Cmd_info.add_cycle = para->addCycle - 2;
        Cmd_info.cmd_len = 2;
        /*Fill Cmd_info - end*/
        Cmd_info.intFlag = 0; /*Reset*/
        if (para->opFlag & SECOND_BUSY)
        {
	        #if (defined __UBL__)||(defined __FUE__)
	        #else        
            if (nfi_egid && use_interrupt == KAL_TRUE)
                Cmd_info.intFlag = BUSY_RETURN_EN;
          #endif
        }
		#if defined(__NFI_VERSION3_1__)
        *NFI_CNFG = CNFG_OP_CUST;
        *NFI_CON = (Flash_Info.pageSize >> 9) << CON_NFI_SEC_SHIFT;
		send_command_rowadd (0x60, 0xD0, &Cmd_info);
        *NFI_CNRNB = STROBE_TIMEOUT;
        #else // defined(__NFI_VERSION3_1__)
        send_command_add(0x60, 0xD0, &Cmd_info);
        #endif // defined(__NFI_VERSION3_1__)

        if (para->opFlag & SECOND_BUSY) /*here means FIRST_PROCESS + SECOND_BUSY*/
        {
	        #if (defined __UBL__)||(defined __FUE__)
	        #else        
            if (nfi_egid && use_interrupt == KAL_TRUE)
            {
                kal_retrieve_eg_events(nfi_egid, NFI_EVENT, KAL_OR_CONSUME,
                                       &event_group, KAL_SUSPEND);
            }
          #endif
        }
    }
    if (para->opFlag & SECOND_BUSY)
    {
        Cmd_info.add_cycle = 0;
        while (!((status = read_status(0x71,&Cmd_info) )&RDY_BUSY)); /*Program busy*/
        if (status&PASS_FAIL)
        {   /*Program fail*/
            retVal = MTD_STATUS_ERROR;
            /*check plane 0*/
            if (status& 0x02 ) /*plane 0 status*/
                retVal |= (1);

            /*check plane 1*/
            if (status& 0x04 ) /*plane 1 status*/
                retVal |= (1<<1);
            nAND_RESET();
            return retVal;
        }
    }
    return MTD_STATUS_NO_ERROR;
}

kal_uint32 toshiba_fourPlane_Program (mtd_drv_para *para)
{
    kal_uint8 status,i;
    kal_uint32 retVal;
		#if (defined __UBL__) || (defined __FUE__) 
		#else
    	kal_uint32 event_group;    
    #endif    
    //dbg_ASSERT( Flash_Info.pageSize >= 2048 ); /*not sure*/
    if (para->opFlag & FIRST_PROCESS)
    {
        /*plane 0 ~ 3*/
        for (i = 0; i < 3 ; i ++)
        {
            NFI_OP_RESET();
            /*Fill Cmd_info - start*/
            if (Flash_Info.pageSize == 512)
            {
                NFI_Pointer(0x00);

				#if !defined(__NFI_VERSION3_1__)
                Cmd_info.add[0] = (*(para->page_p+i)+ para->pageOffset)<<8 ;
				#endif // !defined(__NFI_VERSION3_1__)
                dbg_ASSERT( para->addCycle <=4 );/*No dice with 512 page and cycle > 4*/
            }
            else
            {
				#if !defined(__NFI_VERSION3_1__)
                Cmd_info.add[0] = (*(para->page_p+i) + para->pageOffset)<<16 ;
                Cmd_info.add[1] = (*(para->page_p+i) + para->pageOffset)>>16 ;
                #endif // !defined(__NFI_VERSION3_1__)
            }

			#if defined(__NFI_VERSION3_1__)
			Cmd_info.add[0] = 0; 	// Colume address
			Cmd_info.add[1] = *(para->page_p+i) + para->pageOffset; 	// Row address
			*NFI_CNFG = CNFG_OP_CUST | CNFG_AUTO_FMT_EN;
			*NFI_CON = (Flash_Info.pageSize >> 9) << CON_NFI_SEC_SHIFT;
			#endif // defined(__NFI_VERSION3_1__)

            dbg_ASSERT( (*(para->page_p+i)/Flash_Info.blockPage) == (*(para->page_p+i) + para->pageOffset)/Flash_Info.blockPage ); /*in same block*/
            //dbg_ASSERT( para->buff  );
            Cmd_info.buff = &para->buff[0 + i*Flash_Info.pageSize];
            dbg_ASSERT( Flash_Info.pageSize%512 == 0 );
            Cmd_info.buff_len = Flash_Info.pageSize;
            dbg_ASSERT( para->spare );
            if (para->opFlag & ONE_SPARE) {
	            Cmd_info.spare = &para->spare[0];
            } else {
            	Cmd_info.spare = &para->spare[0 + i*Flash_Info.spareSize];
            }

		    #if defined(__NFI_VERSION3_1__)
		    Cmd_info.spare_len = PAGEFMT_FDM_DEFAULT;
		    Cmd_info.CustomMode = 1;
			#else // defined(__NFI_VERSION3_1__)
            Cmd_info.spare_len = Flash_Info.spareSize;
			#endif // defined(__NFI_VERSION3_1__)

            Cmd_info.ECCFlag = ECC_WHOLE;
            Cmd_info.add_cycle = para->addCycle;
            Cmd_info.cmd_len = 2;
            Cmd_info.intFlag = 0; /*Reset*/
            /*Fill Cmd_info - end*/
            send_command_add_data(0x80, 0x11, &Cmd_info);

            Cmd_info.add_cycle = 0;
            while (!((status = read_status(0x71,&Cmd_info) )&RDY_BUSY)); /*Dummy busy*/
            if (status&PASS_FAIL)
            {
                nAND_RESET();
                return (MTD_STATUS_ERROR|(1<<i));
            }
        }
        /*plane 4*/
        NFI_OP_RESET();
        /*Fill Cmd_info - start*/
        if (Flash_Info.pageSize == 512)
        {
            NFI_Pointer(0x00);
            #if !defined(__NFI_VERSION3_1__)
            Cmd_info.add[0] = (*(para->page_p+3)+ para->pageOffset)<<8 ;
            #endif // !defined(__NFI_VERSION3_1__)
            dbg_ASSERT( para->addCycle <=4 );/*No dice with 512 page and cycle > 4*/
        }
        else
        {
            #if !defined(__NFI_VERSION3_1__)
            Cmd_info.add[0] = (*(para->page_p+3) + para->pageOffset)<<16 ;
            Cmd_info.add[1] = (*(para->page_p+3) + para->pageOffset)>>16 ;
            #endif // !defined(__NFI_VERSION3_1__)
        }
		#if defined(__NFI_VERSION3_1__)
		Cmd_info.add[0] = 0; 	// Colume address
		Cmd_info.add[1] = *(para->page_p+3) + para->pageOffset; 	// Row address
		*NFI_CNFG = CNFG_OP_CUST | CNFG_AUTO_FMT_EN;
		*NFI_CON = (Flash_Info.pageSize >> 9) << CON_NFI_SEC_SHIFT;
		#endif // defined(__NFI_VERSION3_1__)

        dbg_ASSERT( (*(para->page_p+3)/Flash_Info.blockPage) == (*(para->page_p+3) + para->pageOffset)/Flash_Info.blockPage ); /*in same block*/
        //dbg_ASSERT( para->buff  );
        //dbg_ASSERT( Flash_Info.pageSize%512 == 0 );
        Cmd_info.buff = &para->buff[0 + 3*Flash_Info.pageSize];
        Cmd_info.buff_len = Flash_Info.pageSize;
        //dbg_ASSERT( para->spare );
        if (para->opFlag & ONE_SPARE) {
	        Cmd_info.spare = &para->spare[0];
        } else {
        	Cmd_info.spare = &para->spare[0 + 3*Flash_Info.spareSize];
        }

        #if defined(__NFI_VERSION3_1__)
        Cmd_info.spare_len = PAGEFMT_FDM_DEFAULT;
	    Cmd_info.CustomMode = 1;
		#else // defined(__NFI_VERSION3_1__)
        Cmd_info.spare_len = Flash_Info.spareSize;
		#endif // defined(__NFI_VERSION3_1__)

        Cmd_info.ECCFlag = ECC_WHOLE;
        Cmd_info.add_cycle = para->addCycle;
        Cmd_info.cmd_len = 2;
        /*Fill Cmd_info - end*/
        Cmd_info.intFlag = 0; /*Reset*/
        if (para->opFlag & SECOND_BUSY)
        {
	        #if (defined __UBL__)||(defined __FUE__)
	        #else        
            if (nfi_egid && use_interrupt == KAL_TRUE)
                Cmd_info.intFlag = BUSY_RETURN_EN;
          #endif
        }
        send_command_add_data(0x80, 0x10, &Cmd_info);
        #if defined(__NFI_VERSION3_1__)
        *NFI_CNRNB = STROBE_TIMEOUT;
        #endif
        if (para->opFlag & SECOND_BUSY) /*here means FIRST_PROCESS + SECOND_BUSY*/
        {
	        #if (defined __UBL__)||(defined __FUE__)
	        #else        
            if (nfi_egid && use_interrupt == KAL_TRUE)
            {
                kal_retrieve_eg_events(nfi_egid, NFI_EVENT, KAL_OR_CONSUME,
                                       &event_group, KAL_SUSPEND);
            }
					#endif            
        }
    }
    if (para->opFlag & SECOND_BUSY)
    {
        Cmd_info.add_cycle = 0;
        while (!((status = read_status(0x71,&Cmd_info) )&RDY_BUSY)); /*Program busy*/
        if (status&PASS_FAIL)
        {   /*Program fail*/
            retVal = MTD_STATUS_ERROR;
            /*check plane 0*/
            if (status& 0x02 ) /*plane 0 status*/
                retVal |= (1);

            /*check plane 1*/
            if (status& 0x04 ) /*plane 1 status*/
                retVal |= (1<<1);

            /*check plane 2*/
            if (status& 0x08 ) /*plane 2 status*/
                retVal |= (1<<2);

            /*check plane 3*/
            if (status& 0x10 ) /*plane 3 status*/
                retVal |= (1<<3);
            nAND_RESET();
            return retVal;
        }
    }
    return MTD_STATUS_NO_ERROR;
}


kal_uint32 toshiba_fourPlane_Erase (mtd_drv_para *para)
{
    kal_uint8 status,i;
    kal_uint32 retVal;
		#if (defined __UBL__) || (defined __FUE__) 
		#else
    	kal_uint32 event_group;    
    #endif
    //dbg_ASSERT( Flash_Info.pageSize >= 2048 ); /*not sure*/
    if (para->opFlag & FIRST_PROCESS)
    {
        /*plane 0 ~ 3*/
        for (i = 0; i < 3 ; i ++)
        {
            NFI_OP_RESET();
            /*Fill Cmd_info - start*/
            Cmd_info.add[0] = (*(para->page_p+i) + para->pageOffset) ;
            dbg_ASSERT( (*(para->page_p+i)/Flash_Info.blockPage) == (*(para->page_p+i) + para->pageOffset)/Flash_Info.blockPage ); /*in same block*/
            dbg_ASSERT( Flash_Info.pageSize%512 == 0 );
            if (Flash_Info.pageSize == 512)
            {
                Cmd_info.add_cycle = para->addCycle - 1;
                dbg_ASSERT( para->addCycle <=4 );/*No device with 512 page and cycle > 4*/
            }
            else /*2048*/
            {
                Cmd_info.add_cycle = para->addCycle - 2;
                dbg_ASSERT( para->addCycle <=6 );
            }
            Cmd_info.cmd_len = 1;
            Cmd_info.intFlag = 0; /*Reset*/
            /*Fill Cmd_info - end*/

			#if defined(__NFI_VERSION3_1__)
	        *NFI_CNFG = CNFG_OP_CUST;
	        *NFI_CON = (Flash_Info.pageSize >> 9) << CON_NFI_SEC_SHIFT;
			send_command_rowadd (0x60, 0, &Cmd_info);
	        #else // defined(__NFI_VERSION3_1__)
            send_command_add(0x60, 0, &Cmd_info);
	        #endif // defined(__NFI_VERSION3_1__)
        }
        /*plane 4*/
        NFI_OP_RESET();
        /*Fill Cmd_info - start*/
        Cmd_info.add[0] = (*(para->page_p+3) + para->pageOffset);
        dbg_ASSERT( (*(para->page_p+3)/Flash_Info.blockPage) == (*(para->page_p+3) + para->pageOffset)/Flash_Info.blockPage ); /*in same block*/
        if (Flash_Info.pageSize == 512)
        {
            Cmd_info.add_cycle = para->addCycle - 1;
            dbg_ASSERT( para->addCycle <=4 );/*No device with 512 page and cycle > 4*/
        }
        else /*2048*/
        {
            Cmd_info.add_cycle = para->addCycle - 2;
            dbg_ASSERT( para->addCycle <=6 );
        }
        Cmd_info.cmd_len = 2;
        /*Fill Cmd_info - end*/
        Cmd_info.intFlag = 0; /*Reset*/
        if (para->opFlag & SECOND_BUSY)
        {
	        #if (defined __UBL__)||(defined __FUE__)
	        #else
            if (nfi_egid && use_interrupt == KAL_TRUE)
                Cmd_info.intFlag = BUSY_RETURN_EN;
          #endif
        }
		#if defined(__NFI_VERSION3_1__)
        *NFI_CNFG = CNFG_OP_CUST;
        *NFI_CON = (Flash_Info.pageSize >> 9) << CON_NFI_SEC_SHIFT;
		send_command_rowadd (0x60, 0xD0, &Cmd_info);
        *NFI_CNRNB = STROBE_TIMEOUT;
        #else // defined(__NFI_VERSION3_1__)
        send_command_add(0x60, 0xD0, &Cmd_info);
        #endif // defined(__NFI_VERSION3_1__)
        if (para->opFlag & SECOND_BUSY) /*here means FIRST_PROCESS + SECOND_BUSY*/
        {
	        #if (defined __UBL__)||(defined __FUE__)
	        #else        
            if (nfi_egid && use_interrupt == KAL_TRUE)
            {
                kal_retrieve_eg_events(nfi_egid, NFI_EVENT, KAL_OR_CONSUME,
                                       &event_group, KAL_SUSPEND);
            }
        	#endif
        }
    }
    if (para->opFlag & SECOND_BUSY)
    {
        Cmd_info.add_cycle = 0;
        while (!((status = read_status(0x71,&Cmd_info) )&RDY_BUSY)); /*Process busy*/
        if (status&PASS_FAIL)
        {   /*Program fail*/
            retVal = MTD_STATUS_ERROR;
            /*check plane 0*/
            if (status& 0x02 ) /*plane 0 status*/
                retVal |= (1);

            /*check plane 1*/
            if (status& 0x04 ) /*plane 1 status*/
                retVal |= (1<<1);

            /*check plane 2*/
            if (status& 0x08 ) /*plane 2 status*/
                retVal |= (1<<2);

            /*check plane 3*/
            if (status& 0x10 ) /*plane 3 status*/
                retVal |= (1<<3);
            nAND_RESET();
            return retVal;
        }
    }
    return MTD_STATUS_NO_ERROR;
}

/****************************************************************************
 * Function:    toshiba_twoPlane_CacheProgram
 *
 * Parameters:  mtd_drv_para *para
 *
 * Returns:   MTD_STATUS_NO_ERROR   No error
 *            MTD_STATUS_ERROR + index of error page (Low 16 bits)
 * Description: single page cache program function.
 *              [Note] The start page must match para->pageOffset == 0, max para->pageOffset can not over 15
 ****************************************************************************/
kal_uint32 toshiba_twoPlane_CacheProgram (mtd_drv_para *para)
{
    kal_uint8 status;
    kal_uint32 retVal;
		#if (defined __UBL__) || (defined __FUE__) 
		#else
    	kal_uint32 event_group;    
    #endif
    dbg_ASSERT( Flash_Info.pageSize >= 2048 );
    if (para->opFlag & FIRST_PROCESS)
    {
        /*plane 0*/
        NFI_OP_RESET();
        /*Fill Cmd_info - start*/

        #if defined(__NFI_VERSION3_1__)
		Cmd_info.add[0] = 0; 	// Colume address
        Cmd_info.add[1] = *para->page_p + para->pageOffset; 	// Row address
        *NFI_CNFG = CNFG_OP_CUST | CNFG_AUTO_FMT_EN;
        *NFI_CON = (Flash_Info.pageSize >> 9) << CON_NFI_SEC_SHIFT;
        #else // defined(__NFI_VERSION3_1__)
        Cmd_info.add[0] = (*para->page_p + para->pageOffset)<<16 ;
        Cmd_info.add[1] = (*para->page_p + para->pageOffset)>>16 ;
        #endif // defined(__NFI_VERSION3_1__)

        dbg_ASSERT( (*para->page_p/Flash_Info.blockPage) == (*para->page_p + para->pageOffset)/Flash_Info.blockPage ); /*in same block*/
        //dbg_ASSERT( para->buff  );
        Cmd_info.buff = para->buff;
        dbg_ASSERT( Flash_Info.pageSize%512 == 0 );
        Cmd_info.buff_len = Flash_Info.pageSize;
        dbg_ASSERT( para->spare );
        Cmd_info.spare = para->spare;

        #if defined(__NFI_VERSION3_1__)
        Cmd_info.spare_len = PAGEFMT_FDM_DEFAULT;
        Cmd_info.CustomMode = 1;
		#else // defined(__NFI_VERSION3_1__)
        Cmd_info.spare_len = Flash_Info.spareSize;
		#endif // defined(__NFI_VERSION3_1__)

        Cmd_info.ECCFlag = ECC_WHOLE;
        Cmd_info.add_cycle = para->addCycle;
        Cmd_info.cmd_len = 2;
        Cmd_info.intFlag = 0; /*Reset*/
        /*Fill Cmd_info - end*/
        send_command_add_data(0x80, 0x11, &Cmd_info);

        Cmd_info.add_cycle = 0;
        while (!((status = read_status(0x71,&Cmd_info) )&RDY_BUSY)); /*Dummy busy*/
        if (status&PASS_FAIL)
        {
            while (!((status = read_status(0x71,&Cmd_info) )&INTERNAL_BUSY));
            nAND_RESET();
            return (MTD_STATUS_ERROR|1);
        }
        /*plane 1*/
        NFI_OP_RESET();
        /*Fill Cmd_info - start*/

        #if defined(__NFI_VERSION3_1__)
		Cmd_info.add[0] = 0; 	// Colume address
        Cmd_info.add[1] = *(para->page_p+1) + para->pageOffset; 	// Row address
        *NFI_CNFG = CNFG_OP_CUST | CNFG_AUTO_FMT_EN;
        *NFI_CON = (Flash_Info.pageSize >> 9) << CON_NFI_SEC_SHIFT;
        #else // defined(__NFI_VERSION3_1__)
        Cmd_info.add[0] = (*(para->page_p+1) + para->pageOffset)<<16 ;
        Cmd_info.add[1] = (*(para->page_p+1) + para->pageOffset)>>16 ;
        #endif // defined(__NFI_VERSION3_1__)

        dbg_ASSERT( (*(para->page_p+1)/Flash_Info.blockPage) == (*(para->page_p+1) + para->pageOffset)/Flash_Info.blockPage ); /*in same block*/
        //dbg_ASSERT( para->buff  );
        //dbg_ASSERT( Flash_Info.pageSize%512 == 0 );
        Cmd_info.buff = &para->buff[0 + Flash_Info.pageSize];;
        Cmd_info.buff_len = Flash_Info.pageSize;
        //dbg_ASSERT( para->spare );
        if (para->opFlag & ONE_SPARE) {
	        Cmd_info.spare = &para->spare[0];
        } else {
	        Cmd_info.spare = &para->spare[0 + Flash_Info.spareSize];
        }
        #if defined(__NFI_VERSION3_1__)
        Cmd_info.spare_len = PAGEFMT_FDM_DEFAULT;
        Cmd_info.CustomMode = 1;
		#else // defined(__NFI_VERSION3_1__)
        Cmd_info.spare_len = Flash_Info.spareSize;
		#endif // defined(__NFI_VERSION3_1__)

        Cmd_info.ECCFlag = ECC_WHOLE;
        Cmd_info.add_cycle = para->addCycle;
        Cmd_info.cmd_len = 2;
        /*Fill Cmd_info - end*/
        Cmd_info.intFlag = 0; /*Reset*/
        if (para->opFlag & SECOND_BUSY)
        {
	        #if (defined __UBL__)||(defined __FUE__)
	        #else        
            if (nfi_egid && use_interrupt == KAL_TRUE)
                Cmd_info.intFlag = BUSY_RETURN_EN;
          #endif
        }

        if ( para->opFlag & PROGRAM_CACHED)
            send_command_add_data(0x80, 0x15, &Cmd_info);
        else if ( para->opFlag & PROGRAM_FINAL)
            send_command_add_data(0x80, 0x10, &Cmd_info);

        #if defined(__NFI_VERSION3_1__)
        *NFI_CNRNB = STROBE_TIMEOUT;
        #endif

        if (para->opFlag & SECOND_BUSY) /*here means FIRST_PROCESS + SECOND_BUSY*/
        {
	        #if (defined __UBL__)||(defined __FUE__)
	        #else        
            if (nfi_egid && use_interrupt == KAL_TRUE)
            {
                kal_retrieve_eg_events(nfi_egid, NFI_EVENT, KAL_OR_CONSUME,
                                       &event_group, KAL_SUSPEND);
            }
          #endif
        }
    }
    if (para->opFlag & SECOND_BUSY)
    {
        kal_uint8 status_chk;
        Cmd_info.add_cycle = 0;
        while (!((status = read_status(0x71,&Cmd_info) )&RDY_BUSY));

        if ( ( para->opFlag & PROGRAM_CACHED)&& para->pageOffset == 0)
            status_chk = 0x00;  /*invalid*/
        else if ( para->opFlag & PROGRAM_FINAL)
            status_chk = 0x02|0x04|0x08|0x10; /*previous + current*/
        else
            status_chk = 0x08|0x10; /*previous*/

        if (status&status_chk)
        {   /*Program fail*/
            retVal = MTD_STATUS_ERROR;

            /*check plane 0*/
            if (status& (0x02|0x04) ) /*plane 0 status*/
                retVal |= (1);

            /*check plane 1*/
            if (status& (0x08|0x10) ) /*plane 1 status*/
                retVal |= (1<<1);
            while (!((status = read_status(0x71,&Cmd_info) )&INTERNAL_BUSY));
            nAND_RESET();
            return retVal;
        }
    }
    return MTD_STATUS_NO_ERROR;
}


kal_uint32 toshiba_fourPlane_CacheProgram (mtd_drv_para *para)
{
    kal_uint8 status,i;
    kal_uint32 retVal;
		#if (defined __UBL__) || (defined __FUE__) 
		#else
    	kal_uint32 event_group;    
    #endif
    //dbg_ASSERT( Flash_Info.pageSize >= 2048 ); /*not sure*/
    if (para->opFlag & FIRST_PROCESS)
    {
        /*plane 0 ~ 3*/
        for (i = 0; i < 3 ; i ++)
        {
            NFI_OP_RESET();
            /*Fill Cmd_info - start*/

            #if defined(__NFI_VERSION3_1__)
			Cmd_info.add[0] = 0; 	// Colume address
	        Cmd_info.add[1] = *(para->page_p+i) + para->pageOffset; 	// Row address
	        *NFI_CNFG = CNFG_OP_CUST | CNFG_AUTO_FMT_EN;
	        *NFI_CON = (Flash_Info.pageSize >> 9) << CON_NFI_SEC_SHIFT;
            #else // defined(__NFI_VERSION3_1__)
            Cmd_info.add[0] = (*(para->page_p+i) + para->pageOffset)<<16 ;
            Cmd_info.add[1] = (*(para->page_p+i) + para->pageOffset)>>16 ;
            #endif // defined(__NFI_VERSION3_1__)

            dbg_ASSERT( (*(para->page_p+i)/Flash_Info.blockPage) == (*(para->page_p+i) + para->pageOffset)/Flash_Info.blockPage ); /*in same block*/
            //dbg_ASSERT( para->buff  );
            Cmd_info.buff = &para->buff[0 + i*Flash_Info.pageSize];
            dbg_ASSERT( Flash_Info.pageSize%512 == 0 );
            Cmd_info.buff_len = Flash_Info.pageSize;
            dbg_ASSERT( para->spare );
            if (para->opFlag & ONE_SPARE) {
	            Cmd_info.spare = &para->spare[0];
            } else {
  	        	Cmd_info.spare = &para->spare[0 + i*Flash_Info.spareSize];
            }
	        #if defined(__NFI_VERSION3_1__)
	        Cmd_info.spare_len = PAGEFMT_FDM_DEFAULT;
	        Cmd_info.CustomMode = 1;
			#else // defined(__NFI_VERSION3_1__)
            Cmd_info.spare_len = Flash_Info.spareSize;
			#endif // defined(__NFI_VERSION3_1__)

            Cmd_info.ECCFlag = ECC_WHOLE;
            Cmd_info.add_cycle = para->addCycle;
            Cmd_info.cmd_len = 2;
            Cmd_info.intFlag = 0; /*Reset*/
            /*Fill Cmd_info - end*/
            send_command_add_data(0x80, 0x11, &Cmd_info);

            Cmd_info.add_cycle = 0;
            while (!((status = read_status(0x71,&Cmd_info) )&RDY_BUSY)); /*Dummy busy*/
            if (status&PASS_FAIL)
            {
                nAND_RESET();
                return (MTD_STATUS_ERROR|(1<<i));
            }
        }
        /*plane 4*/
        NFI_OP_RESET();
        /*Fill Cmd_info - start*/

        #if defined(__NFI_VERSION3_1__)
		Cmd_info.add[0] = 0; 	// Colume address
        Cmd_info.add[1] = *(para->page_p+3) + para->pageOffset; 	// Row address
        *NFI_CNFG = CNFG_OP_CUST | CNFG_AUTO_FMT_EN;
        *NFI_CON = (Flash_Info.pageSize >> 9) << CON_NFI_SEC_SHIFT;
        #else // defined(__NFI_VERSION3_1__)
        Cmd_info.add[0] = (*(para->page_p+3) + para->pageOffset)<<16 ;
        Cmd_info.add[1] = (*(para->page_p+3) + para->pageOffset)>>16 ;
        #endif // defined(__NFI_VERSION3_1__)

        dbg_ASSERT( (*(para->page_p+3)/Flash_Info.blockPage) == (*(para->page_p+3) + para->pageOffset)/Flash_Info.blockPage ); /*in same block*/
        //dbg_ASSERT( para->buff  );
        //dbg_ASSERT( Flash_Info.pageSize%512 == 0 );
        Cmd_info.buff = &para->buff[0 + 3*Flash_Info.pageSize];
        Cmd_info.buff_len = Flash_Info.pageSize;
        //dbg_ASSERT( para->spare );
        if (para->opFlag & ONE_SPARE) {
	        Cmd_info.spare = &para->spare[0];
        } else {
	        Cmd_info.spare = &para->spare[0 + 3*Flash_Info.spareSize];
        }
        #if defined(__NFI_VERSION3_1__)
        Cmd_info.spare_len = PAGEFMT_FDM_DEFAULT;
		#else // defined(__NFI_VERSION3_1__)
        Cmd_info.spare_len = Flash_Info.spareSize;
		#endif // defined(__NFI_VERSION3_1__)

        Cmd_info.ECCFlag = ECC_WHOLE;
        Cmd_info.add_cycle = para->addCycle;
        Cmd_info.cmd_len = 2;
        /*Fill Cmd_info - end*/
        Cmd_info.intFlag = 0; /*Reset*/
        if (para->opFlag & SECOND_BUSY)
        {
	        #if (defined __UBL__)||(defined __FUE__)
	        #else        
            if (nfi_egid && use_interrupt == KAL_TRUE)
                Cmd_info.intFlag = BUSY_RETURN_EN;
					#endif                
        }
        if ( para->opFlag & PROGRAM_CACHED)
            send_command_add_data(0x80, 0x15, &Cmd_info);
        else if ( para->opFlag & PROGRAM_FINAL)
            send_command_add_data(0x80, 0x10, &Cmd_info);

        #if defined(__NFI_VERSION3_1__)
        *NFI_CNRNB = STROBE_TIMEOUT;
        #endif

        if (para->opFlag & SECOND_BUSY) /*here means FIRST_PROCESS + SECOND_BUSY*/
        {
	        #if (defined __UBL__)||(defined __FUE__)
	        #else        
            if (nfi_egid && use_interrupt == KAL_TRUE)
            {
                kal_retrieve_eg_events(nfi_egid, NFI_EVENT, KAL_OR_CONSUME,
                                       &event_group, KAL_SUSPEND);
            }
         #endif
        }
    }
    if (para->opFlag & SECOND_BUSY)
    {
        Cmd_info.add_cycle = 0;
        while (!((status = read_status(0x71,&Cmd_info) )&RDY_BUSY)); /*Program busy*/
        if (status&PASS_FAIL)
        {   /*Program fail*/
            retVal = MTD_STATUS_ERROR;
            /*check plane 0*/
            if (status& 0x02 ) /*plane 0 status*/
                retVal |= (1);

            /*check plane 1*/
            if (status& 0x04 ) /*plane 1 status*/
                retVal |= (1<<1);

            /*check plane 2*/
            if (status& 0x08 ) /*plane 2 status*/
                retVal |= (1<<2);

            /*check plane 3*/
            if (status& 0x10 ) /*plane 3 status*/
                retVal |= (1<<3);
            nAND_RESET();
            return retVal;
        }
    }
    return MTD_STATUS_NO_ERROR;
}

kal_uint32 samsung_twoPlane_Program (mtd_drv_para *para)
{
    kal_uint8 status;
    kal_uint32 retVal;
		#if (defined __UBL__) || (defined __FUE__) 
		#else
    	kal_uint32 event_group;    
    #endif
    dbg_ASSERT( Flash_Info.pageSize >= 2048 );
    if ( (*para->page_p + Flash_Info.blockPage) == *(para->page_p+1) )
    {   /*here means the request pages are pair*/
        if (para->opFlag & FIRST_PROCESS)
        {
            /*plane 0*/
            NFI_OP_RESET();
            /*Fill Cmd_info - start*/

   			#if defined(__NFI_VERSION3_1__)
			Cmd_info.add[0] = 0; 	// Colume address
	        Cmd_info.add[1] = *para->page_p + para->pageOffset; 	// Row address
	        *NFI_CNFG = CNFG_OP_CUST | CNFG_AUTO_FMT_EN;
	        *NFI_CON = (Flash_Info.pageSize >> 9) << CON_NFI_SEC_SHIFT;
   			#else // defined(__NFI_VERSION3_1__)
            Cmd_info.add[0] = (*para->page_p + para->pageOffset)<<16 ;
            Cmd_info.add[1] = (*para->page_p + para->pageOffset)>>16 ; /*Do not set to fixed low should be also OK (Information from Edward)*/
            #endif // defined(__NFI_VERSION3_1__)

            dbg_ASSERT( (*para->page_p/Flash_Info.blockPage) == (*para->page_p + para->pageOffset)/Flash_Info.blockPage ); /*in same block*/
            //dbg_ASSERT( para->buff  );
            Cmd_info.buff = para->buff;
            dbg_ASSERT( Flash_Info.pageSize%512 == 0 );
            Cmd_info.buff_len = Flash_Info.pageSize;
            dbg_ASSERT( para->spare );
            Cmd_info.spare = para->spare;

	        #if defined(__NFI_VERSION3_1__)
	        Cmd_info.spare_len = PAGEFMT_FDM_DEFAULT;
	        Cmd_info.CustomMode = 1;
			#else // defined(__NFI_VERSION3_1__)
            Cmd_info.spare_len = Flash_Info.spareSize;
			#endif // defined(__NFI_VERSION3_1__)

            Cmd_info.ECCFlag = ECC_WHOLE;
            Cmd_info.add_cycle = para->addCycle;
            Cmd_info.cmd_len = 2;
            Cmd_info.intFlag = 0; /*Reset*/
            /*Fill Cmd_info - end*/
            send_command_add_data(0x80, 0x11, &Cmd_info);

            Cmd_info.add_cycle = 0;
            if (para->opFlag & SAMSUNG_D0_ILEAVE_OP)
                while (!((status = read_status(0xF1,&Cmd_info) )&RDY_BUSY)); /*Dummy busy*/
            else if (para->opFlag & SAMSUNG_D1_ILEAVE_OP)
                while (!((status = read_status(0xF2,&Cmd_info) )&RDY_BUSY)); /*Dummy busy*/
            else
                while (!((status = read_status(0x70,&Cmd_info) )&RDY_BUSY)); /*Dummy busy*/

            if (status&PASS_FAIL)
            {
                nAND_RESET();
                return (MTD_STATUS_ERROR|3);
            }
            /*plane 1*/
            NFI_OP_RESET();
            /*Fill Cmd_info - start*/

   			#if defined(__NFI_VERSION3_1__)
			Cmd_info.add[0] = 0; 	// Colume address
	        Cmd_info.add[1] = *(para->page_p+1) + para->pageOffset; 	// Row address
	        *NFI_CNFG = CNFG_OP_CUST | CNFG_AUTO_FMT_EN;
	        *NFI_CON = (Flash_Info.pageSize >> 9) << CON_NFI_SEC_SHIFT;
   			#else // defined(__NFI_VERSION3_1__)
            Cmd_info.add[0] = (*(para->page_p+1) + para->pageOffset)<<16 ;
            Cmd_info.add[1] = (*(para->page_p+1) + para->pageOffset)>>16 ;
            #endif // defined(__NFI_VERSION3_1__)

            dbg_ASSERT( (*(para->page_p+1)/Flash_Info.blockPage) == (*(para->page_p+1) + para->pageOffset)/Flash_Info.blockPage ); /*in same block*/
            //dbg_ASSERT( para->buff  );
            //dbg_ASSERT( Flash_Info.pageSize%512 == 0 );
            Cmd_info.buff = &para->buff[0 + Flash_Info.pageSize];;
            Cmd_info.buff_len = Flash_Info.pageSize;
            //dbg_ASSERT( para->spare );
            if (para->opFlag & ONE_SPARE) {
	            Cmd_info.spare = &para->spare[0];
            } else {
	            Cmd_info.spare = &para->spare[0 + Flash_Info.spareSize];
            }
	        #if defined(__NFI_VERSION3_1__)
	        Cmd_info.spare_len = PAGEFMT_FDM_DEFAULT;
	        Cmd_info.CustomMode = 1;
			#else // defined(__NFI_VERSION3_1__)
            Cmd_info.spare_len = Flash_Info.spareSize;
			#endif // defined(__NFI_VERSION3_1__)

            Cmd_info.ECCFlag = ECC_WHOLE;
            Cmd_info.add_cycle = para->addCycle;
            Cmd_info.cmd_len = 2;
            /*Fill Cmd_info - end*/
            Cmd_info.intFlag = 0; /*Reset*/
            if (para->opFlag & SECOND_BUSY)
            {
	        			#if (defined __UBL__)||(defined __FUE__)
	        			#else            
                if (nfi_egid && use_interrupt == KAL_TRUE)
                    Cmd_info.intFlag = BUSY_RETURN_EN;
                #endif
            }
            send_command_add_data(0x81, 0x10, &Cmd_info);
	        #if defined(__NFI_VERSION3_1__)
	        *NFI_CNRNB = STROBE_TIMEOUT;
	        #endif
            if (para->opFlag & SECOND_BUSY) /*here means FIRST_PROCESS + SECOND_BUSY*/
            {
	        			#if (defined __UBL__)||(defined __FUE__)
	        			#else            
                if (nfi_egid && use_interrupt == KAL_TRUE)
                {
                    kal_retrieve_eg_events(nfi_egid, NFI_EVENT, KAL_OR_CONSUME,
                                           &event_group, KAL_SUSPEND);
                }
                #endif
            }
        }
        if (para->opFlag & SECOND_BUSY)
        {
            Cmd_info.add_cycle = 0;
            if (para->opFlag & SAMSUNG_D0_ILEAVE_OP)
                while (!((status = read_status(0xF1,&Cmd_info) )&RDY_BUSY)); /*Program busy*/
            else if (para->opFlag & SAMSUNG_D1_ILEAVE_OP)
                while (!((status = read_status(0xF2,&Cmd_info) )&RDY_BUSY)); /*Program busy*/
            else
                while (!((status = read_status(0x70,&Cmd_info) )&RDY_BUSY)); /*Program busy*/

#if ( defined(__NAND_FLASH_HARDWARE_TEST__) && defined(__MAUI_BASIC__) && !defined(__UBL__))
		if ((PFTrigger==KAL_TRUE) && (PFTestCase & PF_MTD_TRIGGER)) {
			kal_uint8 Count;
			kal_uint32 PageAddr0, PageAddr1;

			PFTrigger = KAL_FALSE;
			Count=0;
			while (1) {
				if (ProgBadAddr[Count].Zone==0xff) {
					break;
				}
				PageAddr0 = (*para->page_p + para->pageOffset);
				PageAddr1 = (*(para->page_p+1) + para->pageOffset);
	        	if ( (((ProgBadAddr[Count].Block<<6)+ProgBadAddr[Count].Page) == PageAddr0) ||
	        		 ((ProgBadAddr[Count].Page==0xffff) && (ProgBadAddr[Count].Block == (PageAddr0>>6))) ) {
	        		status |= PASS_FAIL;
	        		break;
	        	}
	        	if ( (((ProgBadAddr[Count].Block<<6)+ProgBadAddr[Count].Page) == PageAddr1) ||
	        		 ((ProgBadAddr[Count].Page==0xffff) && (ProgBadAddr[Count].Block == (PageAddr1>>6))) ) {
	        		status |= PASS_FAIL;
	        		break;
	        	}
				Count++;
			}

		}
#endif

            if (status&PASS_FAIL)
            {   /*Program fail*/
                retVal = MTD_STATUS_ERROR;
                retVal |= (1);
                retVal |= (1<<1);
                nAND_RESET();
                return retVal;
            }
        }
        return MTD_STATUS_NO_ERROR;
    }
    else
    { /*here means the request page is not in pair, use single write*/
        mtd_drv_para drv_data;

        drv_data.addCycle = para->addCycle;
        drv_data.pageOffset = para->pageOffset;
        if (para->opFlag & FIRST_PROCESS)
        {
            /*plane 0*/
            drv_data.page_p = para->page_p;
            drv_data.buff = para->buff;
            drv_data.spare = para->spare;
            drv_data.opFlag = FIRST_PROCESS;
            single_Page_Program(&drv_data);
            /*must complete the 1st single program - start*/
            Cmd_info.add_cycle = 0;
            if (para->opFlag & SAMSUNG_D0_ILEAVE_OP)
                while (!((status = read_status(0xF1,&Cmd_info) )&RDY_BUSY)); /*Program busy*/
            else if (para->opFlag & SAMSUNG_D1_ILEAVE_OP)
                while (!((status = read_status(0xF2,&Cmd_info) )&RDY_BUSY)); /*Program busy*/
            else
                while (!((status = read_status(0x70,&Cmd_info) )&RDY_BUSY)); /*Program busy*/

#if ( defined(__NAND_FLASH_HARDWARE_TEST__) && defined(__MAUI_BASIC__) && !defined(__UBL__))
			if ((PFTrigger==KAL_TRUE) && (PFTestCase & PF_MTD_TRIGGER)) {
				kal_uint8 Count;
				kal_uint32 PageAddr;

				PFTrigger = KAL_FALSE;
				Count=0;
				while (1) {
					if (ProgBadAddr[Count].Zone==0xff) {
						break;
					}
					PageAddr = (*para->page_p + para->pageOffset);
			        if (Flash_Info.pageSize == 512) {
			        	if ( (((ProgBadAddr[Count].Block<<5)+ProgBadAddr[Count].Page) == PageAddr) ||
			        		 ((ProgBadAddr[Count].Page==0xffff) && (ProgBadAddr[Count].Block == (PageAddr>>5))) ) {
			        		status |= PASS_FAIL;
			        		break;
			        	}
			        } else {
			        	if ( (((ProgBadAddr[Count].Block<<6)+ProgBadAddr[Count].Page) == PageAddr) ||
			        		 ((ProgBadAddr[Count].Page==0xffff) && (ProgBadAddr[Count].Block == (PageAddr>>6))) ) {
			        		status |= PASS_FAIL;
			        		break;
			        	}
			        }
					Count++;
				}

			}
#endif

            if (status&PASS_FAIL)
            {   /*Program fail*/
                retVal = MTD_STATUS_ERROR;
                retVal |= 1;
                nAND_RESET();
                return retVal;
            }
            /*must complete the 1st single program - end*/
            /*plane 1*/
            drv_data.addCycle = para->addCycle;
            drv_data.page_p = (para->page_p+1);
            drv_data.buff = &para->buff[0 + (1*Flash_Info.pageSize)];
            if (para->opFlag & ONE_SPARE) {
	            drv_data.spare = &para->spare[0];
            } else {
            	drv_data.spare = &para->spare[0 + (1*Flash_Info.spareSize)];
            }
            drv_data.opFlag = FIRST_PROCESS;
            single_Page_Program(&drv_data);
        }
        if (para->opFlag & SECOND_BUSY)
        {
            Cmd_info.add_cycle = 0;
            if (para->opFlag & SAMSUNG_D0_ILEAVE_OP)
                while (!((status = read_status(0xF1,&Cmd_info) )&RDY_BUSY)); /*Program busy*/
            else if (para->opFlag & SAMSUNG_D1_ILEAVE_OP)
                while (!((status = read_status(0xF2,&Cmd_info) )&RDY_BUSY)); /*Program busy*/
            else
                while (!((status = read_status(0x70,&Cmd_info) )&RDY_BUSY)); /*Program busy*/

#if ( defined(__NAND_FLASH_HARDWARE_TEST__) && defined(__MAUI_BASIC__) && !defined(__UBL__))
			if ((PFTrigger==KAL_TRUE) && (PFTestCase & PF_MTD_TRIGGER)) {
				kal_uint8 Count;
				kal_uint32 PageAddr;

				PFTrigger = KAL_FALSE;
				Count=0;
				while (1) {
					if (ProgBadAddr[Count].Zone==0xff) {
						break;
					}
					PageAddr = (*(para->page_p+1) + para->pageOffset);
			        if (Flash_Info.pageSize == 512) {
			        	if ( (((ProgBadAddr[Count].Block<<5)+ProgBadAddr[Count].Page) == PageAddr) ||
			        		 ((ProgBadAddr[Count].Page==0xffff) && (ProgBadAddr[Count].Block == (PageAddr>>5))) ) {
			        		status |= PASS_FAIL;
			        		break;
			        	}
			        } else {
			        	if ( (((ProgBadAddr[Count].Block<<6)+ProgBadAddr[Count].Page) == PageAddr) ||
			        		 ((ProgBadAddr[Count].Page==0xffff) && (ProgBadAddr[Count].Block == (PageAddr>>6))) ) {
			        		status |= PASS_FAIL;
			        		break;
			        	}
			        }
					Count++;
				}
			}
#endif
            if (status&PASS_FAIL)
            {   /*Program fail*/
                retVal = MTD_STATUS_ERROR;
                retVal |= (1<<1);
                nAND_RESET();
                return retVal;
            }
        }
        return MTD_STATUS_NO_ERROR;
    }
}


kal_uint32 samsung_twoPlane_Erase (mtd_drv_para *para)
{
    kal_uint8 status;
    kal_uint32 retVal;
		#if (defined __UBL__) || (defined __FUE__) 
		#else
    	kal_uint32 event_group;    
    #endif
    dbg_ASSERT( Flash_Info.pageSize >= 2048 );
    if ( (*para->page_p + Flash_Info.blockPage) == *(para->page_p+1) )
    {   /*here means the request blocks are pair*/
        if (para->opFlag & FIRST_PROCESS)
        {
            /*plane 0*/
            NFI_OP_RESET();
            /*Fill Cmd_info - start*/
            Cmd_info.add[0] = (*para->page_p + para->pageOffset) ;
            dbg_ASSERT( (*para->page_p/Flash_Info.blockPage) == (*para->page_p + para->pageOffset)/Flash_Info.blockPage ); /*in same block*/
            dbg_ASSERT( Flash_Info.pageSize%512 == 0 );
            Cmd_info.add_cycle = para->addCycle - 2;
            Cmd_info.cmd_len = 1;
            Cmd_info.intFlag = 0; /*Reset*/
            /*Fill Cmd_info - end*/

			#if defined(__NFI_VERSION3_1__)
	        *NFI_CNFG = CNFG_OP_CUST;
	        *NFI_CON = (Flash_Info.pageSize >> 9) << CON_NFI_SEC_SHIFT;
			send_command_rowadd (0x60, 0, &Cmd_info);
	        #else // defined(__NFI_VERSION3_1__)
            send_command_add(0x60, 0, &Cmd_info);
	        #endif // defined(__NFI_VERSION3_1__)

            /*plane 1*/
            NFI_OP_RESET();
            /*Fill Cmd_info - start*/
            Cmd_info.add[0] = (*(para->page_p+1) + para->pageOffset) ;
            dbg_ASSERT( (*(para->page_p+1)/Flash_Info.blockPage) == (*(para->page_p+1) + para->pageOffset)/Flash_Info.blockPage ); /*in same block*/
            Cmd_info.add_cycle = para->addCycle - 2;
            Cmd_info.cmd_len = 2;
            /*Fill Cmd_info - end*/
            Cmd_info.intFlag = 0; /*Reset*/
            if (para->opFlag & SECOND_BUSY)
            {
	        			#if (defined __UBL__)||(defined __FUE__)
	        			#else            
                if (nfi_egid && use_interrupt == KAL_TRUE)
                    Cmd_info.intFlag = BUSY_RETURN_EN;
                #endif
            }
			#if defined(__NFI_VERSION3_1__)
	        *NFI_CNFG = CNFG_OP_CUST;
	        *NFI_CON = (Flash_Info.pageSize >> 9) << CON_NFI_SEC_SHIFT;
			send_command_rowadd (0x60, 0xD0, &Cmd_info);
	        *NFI_CNRNB = STROBE_TIMEOUT;
	        #else // defined(__NFI_VERSION3_1__)
            send_command_add(0x60, 0xD0, &Cmd_info);
			#endif // defined(__NFI_VERSION3_1__)

            if (para->opFlag & SECOND_BUSY) /*here means FIRST_PROCESS + SECOND_BUSY*/
            {
	    			    #if (defined __UBL__)||(defined __FUE__)
				        #else
            
                if (nfi_egid && use_interrupt == KAL_TRUE)
                {
                    kal_retrieve_eg_events(nfi_egid, NFI_EVENT, KAL_OR_CONSUME,
                                           &event_group, KAL_SUSPEND);
                }
                #endif
            }
        }
        if (para->opFlag & SECOND_BUSY)
        {
            Cmd_info.add_cycle = 0;
            if (para->opFlag & SAMSUNG_D0_ILEAVE_OP)
                while (!((status = read_status(0xF1,&Cmd_info) )&RDY_BUSY)); /*Process busy*/
            else if (para->opFlag & SAMSUNG_D1_ILEAVE_OP)
                while (!((status = read_status(0xF2,&Cmd_info) )&RDY_BUSY)); /*Process busy*/
            else
                while (!((status = read_status(0x70,&Cmd_info) )&RDY_BUSY)); /*Process busy*/

#if ( defined(__NAND_FLASH_HARDWARE_TEST__) && defined(__MAUI_BASIC__) && !defined(__UBL__))
			if ((EFTrigger==KAL_TRUE) && (EFTestCase & EF_MTD_TRIGGER)) {
				kal_uint8 Count;

				EFTrigger = KAL_FALSE;
				Count=0;
				while (1) {
					if (EraseBadAddr[Count].Zone==0xff) {
						break;
					}
		        	if ( (EraseBadAddr[Count].Block<<6) == (*para->page_p + para->pageOffset) ) {
		        		status |= 0x01;
		        		break;
		        	}
		        	if ( (EraseBadAddr[Count].Block<<6) == (*(para->page_p+1) + para->pageOffset) ) {
		        		status |= 0x01;
		        		break;
		        	}
					Count++;
				}
			}
#endif
            if (status&PASS_FAIL)
            {   /*Erase fail*/
                retVal = MTD_STATUS_ERROR;
                retVal |= (1);
                retVal |= (1<<1);
                nAND_RESET();
                return retVal;
            }
        }
        return MTD_STATUS_NO_ERROR;
    }
    else
    { /*here means the request page is not in pair, use single erase*/
        mtd_drv_para drv_data;

        drv_data.addCycle = para->addCycle;
        drv_data.pageOffset = para->pageOffset;
        if (para->opFlag & FIRST_PROCESS)
        {
            /*plane 0*/
            drv_data.page_p = para->page_p;
            drv_data.opFlag = FIRST_PROCESS;
            single_Block_Erase(&drv_data);
            /*must complete the 1st single program - start*/
            Cmd_info.add_cycle = 0;
            if (para->opFlag & SAMSUNG_D0_ILEAVE_OP)
                while (!((status = read_status(0xF1,&Cmd_info) )&RDY_BUSY)); /*Program busy*/
            else if (para->opFlag & SAMSUNG_D1_ILEAVE_OP)
                while (!((status = read_status(0xF2,&Cmd_info) )&RDY_BUSY)); /*Program busy*/
            else
                while (!((status = read_status(0x70,&Cmd_info) )&RDY_BUSY)); /*Program busy*/

#if ( defined(__NAND_FLASH_HARDWARE_TEST__) && defined(__MAUI_BASIC__) && !defined(__UBL__))
			if ((EFTrigger==KAL_TRUE) && (EFTestCase & EF_MTD_TRIGGER)) {
				kal_uint8 Count;

				EFTrigger = KAL_FALSE;
				Count=0;
				while (1) {
					if (EraseBadAddr[Count].Zone==0xff) {
						break;
					}
		        	if ( (EraseBadAddr[Count].Block<<6) == (*para->page_p + para->pageOffset) ) {
		        		status |= 0x01;
		        		break;
		        	}
					Count++;
				}
			}
#endif
            if (status&PASS_FAIL)
            {   /*Program fail*/
                retVal = MTD_STATUS_ERROR;
                retVal |= (1);
                nAND_RESET();
                return retVal;
            }
            /*must complete the 1st single program - end*/
            /*plane 1*/
            drv_data.addCycle = para->addCycle;
            drv_data.page_p = (para->page_p+1);
            drv_data.opFlag = FIRST_PROCESS;
            single_Block_Erase(&drv_data);
        }
        if (para->opFlag & SECOND_BUSY)
        {
            Cmd_info.add_cycle = 0;
            if (para->opFlag & SAMSUNG_D0_ILEAVE_OP)
                while (!((status = read_status(0xF1,&Cmd_info) )&RDY_BUSY)); /*Program busy*/
            else if (para->opFlag & SAMSUNG_D1_ILEAVE_OP)
                while (!((status = read_status(0xF2,&Cmd_info) )&RDY_BUSY)); /*Program busy*/
            else
                while (!((status = read_status(0x70,&Cmd_info) )&RDY_BUSY)); /*Program busy*/

#if ( defined(__NAND_FLASH_HARDWARE_TEST__) && defined(__MAUI_BASIC__) && !defined(__UBL__))
			if ((EFTrigger==KAL_TRUE) && (EFTestCase & EF_MTD_TRIGGER)) {
				kal_uint8 Count;

				EFTrigger = KAL_FALSE;
				Count=0;
				while (1) {
					if (EraseBadAddr[Count].Zone==0xff) {
						break;
					}
		        	if ( (EraseBadAddr[Count].Block<<6) == (*(para->page_p+1) + para->pageOffset) ) {
		        		status |= 0x01;
		        		break;
		        	}
					Count++;
				}
			}
#endif
            if (status&PASS_FAIL)
            {   /*Program fail*/
                retVal = MTD_STATUS_ERROR;
                retVal |= (1<<1);
                nAND_RESET();
                return retVal;
            }
        }
        return MTD_STATUS_NO_ERROR;
    }
}

kal_uint32 samsung_twoDie_Program (mtd_drv_para *para)
{
    kal_uint8 status;
    mtd_drv_para drv_data;
    kal_uint32 retVal;
    kal_uint32 ret_die0 = MTD_STATUS_NO_ERROR, ret_die1 = MTD_STATUS_NO_ERROR;
    dbg_ASSERT( Flash_Info.pageSize >= 2048 );
    drv_data.addCycle = para->addCycle;
    drv_data.pageOffset = para->pageOffset;

    if (para->opFlag & FIRST_PROCESS)
    {
        /*die 0*/
        drv_data.page_p = para->page_p;
        drv_data.buff = para->buff;
        drv_data.spare = para->spare;
        drv_data.opFlag = FIRST_PROCESS;
        if (para->opFlag & ONE_SPARE) {
        	drv_data.opFlag |= ONE_SPARE;
        }
        ret_die0 = single_Page_Program(&drv_data);
        if ( ret_die0 == MTD_STATUS_NO_ERROR)
        {   /*die 1*/
            drv_data.page_p = (para->page_p+1);
            drv_data.buff = &para->buff[0 + (1*Flash_Info.pageSize)];
            if (para->opFlag & ONE_SPARE) {
	            drv_data.spare = &para->spare[0];
	        	drv_data.opFlag |= ONE_SPARE;
            } else {
            	drv_data.spare = &para->spare[0 + (1*Flash_Info.spareSize)];
            }
            drv_data.opFlag = FIRST_PROCESS;
            ret_die1 = single_Page_Program(&drv_data);
        }
    }
    if ( ret_die0 != MTD_STATUS_NO_ERROR || ret_die1 != MTD_STATUS_NO_ERROR )
    {
        retVal = MTD_STATUS_ERROR;
        retVal |= (ret_die0&0xFFFF);
        retVal |= ((ret_die1&0xFFFF)<<1);
        return retVal;
    }
    if (para->opFlag & SECOND_BUSY)
    {
        /*die 0*/
        while (!((status = read_status(0xF1,&Cmd_info) )&RDY_BUSY)); /*Program busy*/
        if (status&PASS_FAIL)
        {   /*Program fail*/
            ret_die0 = (MTD_STATUS_ERROR|1);
        }
        /*die 1*/
        while (!((status = read_status(0xF2,&Cmd_info) )&RDY_BUSY)); /*Program busy*/
        if (status&PASS_FAIL)
        {   /*Program fail*/
            ret_die1 = (MTD_STATUS_ERROR|1);
        }

        if ( ret_die0 != MTD_STATUS_NO_ERROR || ret_die1 != MTD_STATUS_NO_ERROR )
        {
            retVal = MTD_STATUS_ERROR;
            retVal |= (ret_die0&0xFFFF);
            retVal |= ((ret_die1&0xFFFF)<<1);
            return retVal;
        }
    }
    return MTD_STATUS_NO_ERROR;
}


kal_uint32 samsung_twoDie_Erase (mtd_drv_para *para)
{
    kal_uint8 status;
    mtd_drv_para drv_data;
    kal_uint32 retVal;
    kal_uint32 ret_die0 = MTD_STATUS_NO_ERROR, ret_die1 = MTD_STATUS_NO_ERROR;
    dbg_ASSERT( Flash_Info.pageSize >= 2048 );
    drv_data.addCycle = para->addCycle;
    drv_data.pageOffset = para->pageOffset;

    if (para->opFlag & FIRST_PROCESS)
    {
        /*die 0*/
        drv_data.page_p = para->page_p;
        drv_data.opFlag = FIRST_PROCESS;
        ret_die0 = single_Block_Erase(&drv_data);
        if ( ret_die0 == MTD_STATUS_NO_ERROR)
        {   /*die 1*/
            drv_data.page_p = (para->page_p+1);
            drv_data.opFlag = FIRST_PROCESS;
            ret_die1 = single_Block_Erase(&drv_data);
        }
    }
    if ( ret_die0 != MTD_STATUS_NO_ERROR || ret_die1 != MTD_STATUS_NO_ERROR )
    {
        retVal = MTD_STATUS_ERROR;
        retVal |= (ret_die0&0xFFFF);
        retVal |= ((ret_die1&0xFFFF)<<1);
        return retVal;
    }
    if (para->opFlag & SECOND_BUSY)
    {
        /*die 0*/
        while (!((status = read_status(0xF1,&Cmd_info) )&RDY_BUSY)); /*Program busy*/
        if (status&PASS_FAIL)
        {   /*Program fail*/
            ret_die0 = (MTD_STATUS_ERROR|1);
        }
        /*die 1*/
        while (!((status = read_status(0xF2,&Cmd_info) )&RDY_BUSY)); /*Program busy*/
        if (status&PASS_FAIL)
        {   /*Program fail*/
            ret_die1 = (MTD_STATUS_ERROR|1);
        }

        if ( ret_die0 != MTD_STATUS_NO_ERROR || ret_die1 != MTD_STATUS_NO_ERROR )
        {
            retVal = MTD_STATUS_ERROR;
            retVal |= (ret_die0&0xFFFF);
            retVal |= ((ret_die1&0xFFFF)<<1);
            return retVal;
        }
    }
    return MTD_STATUS_NO_ERROR;
}

kal_uint32 samsung_twoDie_twoPlane_Program (mtd_drv_para *para)
{
    mtd_drv_para drv_data;
    kal_uint32 retVal;
    kal_uint32 ret_die0 = MTD_STATUS_NO_ERROR, ret_die1 = MTD_STATUS_NO_ERROR;
    dbg_ASSERT( Flash_Info.pageSize >= 2048 );
    drv_data.addCycle = para->addCycle;
    drv_data.pageOffset = para->pageOffset;

    if (para->opFlag & FIRST_PROCESS)
    {
        /*die 0*/
        drv_data.page_p = para->page_p;
        drv_data.buff = para->buff;
        drv_data.spare = para->spare;
        drv_data.opFlag = FIRST_PROCESS|SAMSUNG_D0_ILEAVE_OP;
        if (para->opFlag & ONE_SPARE) {
            drv_data.opFlag |= ONE_SPARE;
        }
        ret_die0 = samsung_twoPlane_Program(&drv_data);
        if ( ret_die0 == MTD_STATUS_NO_ERROR)
        {   /*die 1*/
            drv_data.page_p = (para->page_p+2);
            drv_data.buff = &para->buff[0 + (2*Flash_Info.pageSize)];
            drv_data.opFlag = FIRST_PROCESS|SAMSUNG_D1_ILEAVE_OP;
            if (para->opFlag & ONE_SPARE) {
	            drv_data.spare = &para->spare[0];
	            drv_data.opFlag |= ONE_SPARE;
            } else {
            	drv_data.spare = &para->spare[0 + (2*Flash_Info.spareSize)];
            }
            ret_die1 = samsung_twoPlane_Program(&drv_data);
        }
    }
    if ( ret_die0 != MTD_STATUS_NO_ERROR || ret_die1 != MTD_STATUS_NO_ERROR )
    {

        retVal = MTD_STATUS_ERROR;
        retVal |= (ret_die0&0xFFFF);
        retVal |= ((ret_die1&0xFFFF)<<2);
        return retVal;
    }
    if (para->opFlag & SECOND_BUSY)
    {
        /*die 0*/
        drv_data.page_p = para->page_p;
        //drv_data.buff = para->buff;
        //drv_data.spare = para->spare;
        drv_data.opFlag = SECOND_BUSY|SAMSUNG_D0_ILEAVE_OP;
        ret_die0 = samsung_twoPlane_Program(&drv_data);
        /*die 1*/
        drv_data.page_p = (para->page_p+2);
        //drv_data.buff = &para->buff[0 + xxx];
        //drv_data.spare = para->spare[0 + xxx];
        drv_data.opFlag = SECOND_BUSY|SAMSUNG_D1_ILEAVE_OP;
        ret_die1 = samsung_twoPlane_Program(&drv_data);

        if ( ret_die0 != MTD_STATUS_NO_ERROR || ret_die1 != MTD_STATUS_NO_ERROR )
        {
            retVal = MTD_STATUS_ERROR;
            retVal |= (ret_die0&0xFFFF);
            retVal |= ((ret_die1&0xFFFF)<<2);
            return retVal;
        }
    }
    return MTD_STATUS_NO_ERROR;
}


kal_uint32 samsung_twoDie_twoPlane_Erase (mtd_drv_para *para)
{
    mtd_drv_para drv_data;
    kal_uint32 retVal;
    kal_uint32 ret_die0 = MTD_STATUS_NO_ERROR, ret_die1 = MTD_STATUS_NO_ERROR;
    dbg_ASSERT( Flash_Info.pageSize >= 2048 );
    drv_data.addCycle = para->addCycle;
    drv_data.pageOffset = para->pageOffset;

    if (para->opFlag & FIRST_PROCESS)
    {
        /*die 0*/
        drv_data.page_p = para->page_p;
        drv_data.opFlag = FIRST_PROCESS|SAMSUNG_D0_ILEAVE_OP;
        ret_die0 = samsung_twoPlane_Erase(&drv_data);
        if ( ret_die0 == MTD_STATUS_NO_ERROR)
        {   /*die 1*/
            drv_data.page_p = (para->page_p+2);
            drv_data.opFlag = FIRST_PROCESS|SAMSUNG_D1_ILEAVE_OP;
            ret_die1 = samsung_twoPlane_Erase(&drv_data);
        }
    }
    if ( ret_die0 != MTD_STATUS_NO_ERROR || ret_die1 != MTD_STATUS_NO_ERROR )
    {
        retVal = MTD_STATUS_ERROR;
        retVal |= (ret_die0&0xFFFF);
        retVal |= ((ret_die1&0xFFFF)<<2);
        return retVal;
    }
    if (para->opFlag & SECOND_BUSY)
    {
        /*die 0*/
        drv_data.page_p = para->page_p;
        //drv_data.buff = para->buff;
        //drv_data.spare = para->spare;
        drv_data.opFlag = SECOND_BUSY|SAMSUNG_D0_ILEAVE_OP;
        ret_die0 = samsung_twoPlane_Erase(&drv_data);
        /*die 1*/
        drv_data.page_p = (para->page_p+2);
        //drv_data.buff = &para->buff[0 + xxx];
        //drv_data.spare = para->spare[0 + xxx];
        drv_data.opFlag = SECOND_BUSY|SAMSUNG_D1_ILEAVE_OP;
        ret_die1 = samsung_twoPlane_Erase(&drv_data);

        if ( ret_die0 != MTD_STATUS_NO_ERROR || ret_die1 != MTD_STATUS_NO_ERROR )
        {
            retVal = MTD_STATUS_ERROR;
            retVal |= (ret_die0&0xFFFF);
            retVal |= ((ret_die1&0xFFFF)<<2);
            return retVal;
        }
    }
    return MTD_STATUS_NO_ERROR;
}

kal_uint32 micron_twoPlane_Program (mtd_drv_para *para)
{
    kal_uint8 status;
    kal_uint32 retVal;
		#if (defined __UBL__) || (defined __FUE__) 
		#else
    	kal_uint32 event_group;    
    #endif


#if ( defined(__NAND_FLASH_HARDWARE_TEST__) && defined(__MAUI_BASIC__) && !defined(__UBL__))
    kal_uint32 ErrorP = 0;
#endif

    dbg_ASSERT( Flash_Info.pageSize >= 2048 );
    if (para->opFlag & FIRST_PROCESS)
    {
        /*plane 0*/
        NFI_OP_RESET();
        /*Fill Cmd_info - start*/

        #if defined(__NFI_VERSION3_1__)
		Cmd_info.add[0] = 0; 	// Colume address
        Cmd_info.add[1] = *para->page_p + para->pageOffset; 	// Row address
        *NFI_CNFG = CNFG_OP_CUST | CNFG_AUTO_FMT_EN;
        *NFI_CON = (Flash_Info.pageSize >> 9) << CON_NFI_SEC_SHIFT;
        #else // defined(__NFI_VERSION3_1__)
        Cmd_info.add[0] = (*para->page_p + para->pageOffset)<<16 ;
        Cmd_info.add[1] = (*para->page_p + para->pageOffset)>>16 ;
        #endif // defined(__NFI_VERSION3_1__)

        dbg_ASSERT( (*para->page_p/Flash_Info.blockPage) == (*para->page_p + para->pageOffset)/Flash_Info.blockPage ); /*in same block*/
        //dbg_ASSERT( para->buff  );
        Cmd_info.buff = para->buff;
        dbg_ASSERT( Flash_Info.pageSize%512 == 0 );
        Cmd_info.buff_len = Flash_Info.pageSize;
        dbg_ASSERT( para->spare );
        Cmd_info.spare = para->spare;

        #if defined(__NFI_VERSION3_1__)
        Cmd_info.spare_len = PAGEFMT_FDM_DEFAULT;
        Cmd_info.CustomMode = 1;
		#else // defined(__NFI_VERSION3_1__)
        Cmd_info.spare_len = Flash_Info.spareSize;
		#endif // defined(__NFI_VERSION3_1__)

        Cmd_info.ECCFlag = ECC_WHOLE;
        Cmd_info.add_cycle = para->addCycle;
        Cmd_info.cmd_len = 2;
        Cmd_info.intFlag = 0; /*Reset*/
        /*Fill Cmd_info - end*/
        send_command_add_data(0x80, 0x11, &Cmd_info);

        /*Fill Cmd_info - start*/
        Cmd_info.add[0] = (*para->page_p + para->pageOffset) ; /*row address*/
        Cmd_info.add_cycle = para->addCycle - 2; /*row address cycle*/
        /*Fill Cmd_info - end*/
        while (!((status = read_status(0x78,&Cmd_info) )&RDY_BUSY)); /*Dummy busy*/
        if (status&PASS_FAIL)
        {
            nAND_RESET();
            return (MTD_STATUS_ERROR|1);
        }
        /*plane 1*/
        NFI_OP_RESET();
        /*Fill Cmd_info - start*/

        #if defined(__NFI_VERSION3_1__)
		Cmd_info.add[0] = 0; 	// Colume address
        Cmd_info.add[1] = *(para->page_p+1) + para->pageOffset; 	// Row address
        *NFI_CNFG = CNFG_OP_CUST | CNFG_AUTO_FMT_EN;
        *NFI_CON = (Flash_Info.pageSize >> 9) << CON_NFI_SEC_SHIFT;
        #else // defined(__NFI_VERSION3_1__)
        Cmd_info.add[0] = (*(para->page_p+1) + para->pageOffset)<<16 ;
        Cmd_info.add[1] = (*(para->page_p+1) + para->pageOffset)>>16 ;
        #endif // defined(__NFI_VERSION3_1__)

        dbg_ASSERT( (*(para->page_p+1)/Flash_Info.blockPage) == (*(para->page_p+1) + para->pageOffset)/Flash_Info.blockPage ); /*in same block*/
        //dbg_ASSERT( para->buff  );
        //dbg_ASSERT( Flash_Info.pageSize%512 == 0 );
        Cmd_info.buff = &para->buff[0 + Flash_Info.pageSize];;
        Cmd_info.buff_len = Flash_Info.pageSize;
        //dbg_ASSERT( para->spare );
        if (para->opFlag & ONE_SPARE) {
	        Cmd_info.spare = &para->spare[0];
        } else {
        	Cmd_info.spare = &para->spare[0 + Flash_Info.spareSize];
        }

        #if defined(__NFI_VERSION3_1__)
        Cmd_info.spare_len = PAGEFMT_FDM_DEFAULT;
        Cmd_info.CustomMode = 1;
		#else // defined(__NFI_VERSION3_1__)
        Cmd_info.spare_len = Flash_Info.spareSize;
		#endif // defined(__NFI_VERSION3_1__)

        Cmd_info.ECCFlag = ECC_WHOLE;
        Cmd_info.add_cycle = para->addCycle;
        Cmd_info.cmd_len = 2;
        /*Fill Cmd_info - end*/
        Cmd_info.intFlag = 0; /*Reset*/
        if (para->opFlag & SECOND_BUSY)
        {
	        #if (defined __UBL__)||(defined __FUE__)
	        #else        
            if (nfi_egid && use_interrupt == KAL_TRUE)
                Cmd_info.intFlag = BUSY_RETURN_EN;
          #endif
        }
        send_command_add_data(0x80, 0x10, &Cmd_info);
        #if defined(__NFI_VERSION3_1__)
        *NFI_CNRNB = STROBE_TIMEOUT;
        #endif

        if (para->opFlag & SECOND_BUSY) /*here means FIRST_PROCESS + SECOND_BUSY*/
        {
	        #if (defined __UBL__)||(defined __FUE__)
	        #else        
            if (nfi_egid && use_interrupt == KAL_TRUE)
            {
                kal_retrieve_eg_events(nfi_egid, NFI_EVENT, KAL_OR_CONSUME,
                                       &event_group, KAL_SUSPEND);
            }
          #endif
        }
    }
    if (para->opFlag & SECOND_BUSY)
    {
        Cmd_info.add_cycle = 0;
        while (!((status = read_status(0x70,&Cmd_info) )&RDY_BUSY)); /*Program busy*/

#if ( defined(__NAND_FLASH_HARDWARE_TEST__) && defined(__MAUI_BASIC__) && !defined(__UBL__))
		if ((PFTrigger==KAL_TRUE) && (PFTestCase & PF_MTD_TRIGGER)) {
			kal_uint8 Count;
			kal_uint32 PageAddr0, PageAddr1;

			PFTrigger = KAL_FALSE;
			Count=0;
			while (1) {
				if (ProgBadAddr[Count].Zone==0xff) {
					break;
				}
				PageAddr0 = (*para->page_p + para->pageOffset);
				PageAddr1 = (*(para->page_p+1) + para->pageOffset);
	        	if ( (((ProgBadAddr[Count].Block<<6)+ProgBadAddr[Count].Page) == PageAddr0) ||
	        		 ((ProgBadAddr[Count].Page==0xffff) && (ProgBadAddr[Count].Block == (PageAddr0>>6))) ) {
		        		status |= PASS_FAIL;
						ErrorP |= 0x01;
		        		break;
	        	}
	        	if ( (((ProgBadAddr[Count].Block<<6)+ProgBadAddr[Count].Page) == PageAddr1) ||
	        		 ((ProgBadAddr[Count].Page==0xffff) && (ProgBadAddr[Count].Block == (PageAddr1>>6))) ) {
		        		status |= PASS_FAIL;
		        		ErrorP |= 0x10;
						break;
	        	}
				Count++;
			}

		}
#endif

        if (status&PASS_FAIL)
        {   /*Program fail*/
            retVal = MTD_STATUS_ERROR;
            /*check plane 0*/
            /*Fill Cmd_info - start*/
            Cmd_info.add[0] = (*para->page_p + para->pageOffset) ; /*row address*/
            Cmd_info.add_cycle = para->addCycle - 2; /*row address cycle*/
            /*Fill Cmd_info - end*/
            while (!((status = read_status(0x78,&Cmd_info) )&RDY_BUSY)); /*Program busy*/
#if ( defined(__NAND_FLASH_HARDWARE_TEST__) && defined(__MAUI_BASIC__) && !defined(__UBL__))
			status |= (ErrorP & 0x01);
#endif
            if (status&PASS_FAIL)
            {
                retVal |= 1;
            }
            /*check plane 1*/
            /*Fill Cmd_info - start*/
            Cmd_info.add[0] = (*(para->page_p+1) + para->pageOffset); /*row address*/
            Cmd_info.add_cycle = para->addCycle - 2; /*row address cycle*/
            /*Fill Cmd_info - end*/
            while (!((status = read_status(0x78,&Cmd_info) )&RDY_BUSY)); /*Program busy*/
#if ( defined(__NAND_FLASH_HARDWARE_TEST__) && defined(__MAUI_BASIC__) && !defined(__UBL__))
			status |= ((ErrorP & 0x10)>>4);
#endif
            if (status&PASS_FAIL)
            {
                retVal |= (1<<1);
            }
            nAND_RESET();
            return retVal;
        }
    }
    return MTD_STATUS_NO_ERROR;
}


kal_uint32 micron_twoPlane_Erase (mtd_drv_para *para)
{
    kal_uint8 status;
    kal_uint32 retVal;
		#if (defined __UBL__) || (defined __FUE__) 
		#else
    	kal_uint32 event_group;    
    #endif

#if ( defined(__NAND_FLASH_HARDWARE_TEST__) && defined(__MAUI_BASIC__) && !defined(__UBL__))
	kal_uint32 ErrorP = 0;
#endif

    dbg_ASSERT( Flash_Info.pageSize >= 2048 );
    if (para->opFlag & FIRST_PROCESS)
    {
        /*plane 0*/
        NFI_OP_RESET();
        /*Fill Cmd_info - start*/
        Cmd_info.add[0] = (*para->page_p + para->pageOffset) ;
        dbg_ASSERT( (*para->page_p/Flash_Info.blockPage) == (*para->page_p + para->pageOffset)/Flash_Info.blockPage ); /*in same block*/
        dbg_ASSERT( Flash_Info.pageSize%512 == 0 );
        Cmd_info.add_cycle = para->addCycle - 2;
        Cmd_info.cmd_len = 2;
        Cmd_info.intFlag = 0; /*Reset*/
        /*Fill Cmd_info - end*/
		#if defined(__NFI_VERSION3_1__)
        *NFI_CNFG = CNFG_OP_CUST;
        *NFI_CON = (Flash_Info.pageSize >> 9) << CON_NFI_SEC_SHIFT;
		send_command_rowadd (0x60, 0xD1, &Cmd_info);
        #else // defined(__NFI_VERSION3_1__)
        send_command_add(0x60, 0xD1, &Cmd_info);
        #endif // defined(__NFI_VERSION3_1__)

        /*Fill Cmd_info - start*/
        Cmd_info.add[0] = (*para->page_p + para->pageOffset) ; /*row address*/
        Cmd_info.add_cycle = para->addCycle - 2; /*row address cycle*/
        /*Fill Cmd_info - end*/
        while (!((status = read_status(0x78,&Cmd_info) )&RDY_BUSY)); /*Dummy busy*/
        if (status&PASS_FAIL)
        {
            nAND_RESET();
            return (MTD_STATUS_ERROR|1);
        }
        /*plane 1*/
        NFI_OP_RESET();
        /*Fill Cmd_info - start*/
        Cmd_info.add[0] = (*(para->page_p+1) + para->pageOffset) ;
        dbg_ASSERT( (*(para->page_p+1)/Flash_Info.blockPage) == (*(para->page_p+1) + para->pageOffset)/Flash_Info.blockPage ); /*in same block*/
        Cmd_info.add_cycle = para->addCycle - 2;
        Cmd_info.cmd_len = 2;
        /*Fill Cmd_info - end*/
        Cmd_info.intFlag = 0; /*Reset*/
        if (para->opFlag & SECOND_BUSY)
        {
	        #if (defined __UBL__)||(defined __FUE__)
	        #else        
            if (nfi_egid && use_interrupt == KAL_TRUE)
                Cmd_info.intFlag = BUSY_RETURN_EN;
          #endif
        }
		#if defined(__NFI_VERSION3_1__)
        *NFI_CNFG = CNFG_OP_CUST;
        *NFI_CON = (Flash_Info.pageSize >> 9) << CON_NFI_SEC_SHIFT;
		send_command_rowadd (0x60, 0xD0, &Cmd_info);
        *NFI_CNRNB = STROBE_TIMEOUT;
        #else // defined(__NFI_VERSION3_1__)
        send_command_add(0x60, 0xD0, &Cmd_info);
		#endif // defined(__NFI_VERSION3_1__)

        if (para->opFlag & SECOND_BUSY) /*here means FIRST_PROCESS + SECOND_BUSY*/
        {
	        #if (defined __UBL__)||(defined __FUE__)
	        #else        
            if (nfi_egid && use_interrupt == KAL_TRUE)
            {
                kal_retrieve_eg_events(nfi_egid, NFI_EVENT, KAL_OR_CONSUME,
                                       &event_group, KAL_SUSPEND);
            }
          #endif
        }
    }
    if (para->opFlag & SECOND_BUSY)
    {
        Cmd_info.add_cycle = 0;
        while (!((status = read_status(0x70,&Cmd_info) )&RDY_BUSY)); /*Process busy*/
#if ( defined(__NAND_FLASH_HARDWARE_TEST__) && defined(__MAUI_BASIC__) && !defined(__UBL__))
		if ((EFTrigger==KAL_TRUE) && (EFTestCase & EF_MTD_TRIGGER)) {
			kal_uint8 Count;

			EFTrigger = KAL_FALSE;
			Count=0;
			while (1) {
				if (EraseBadAddr[Count].Zone==0xff) {
					break;
				}
	        	if ( (EraseBadAddr[Count].Block<<6) == (*para->page_p + para->pageOffset) ) {
	        		status |= 0x01;
	        		ErrorP |= 0x01;
	        		break;
	        	}
	        	if ( (EraseBadAddr[Count].Block<<6) == (*(para->page_p+1) + para->pageOffset) ) {
	        		status |= 0x01;
	        		ErrorP |= 0x02;
	        		break;
	        	}
				Count++;
			}
		}
#endif

        if (status&PASS_FAIL)
        {   /*Program fail*/
            retVal = MTD_STATUS_ERROR;
            /*check plane 0*/
            /*Fill Cmd_info - start*/
            Cmd_info.add[0] = (*para->page_p + para->pageOffset) ; /*row address*/
            Cmd_info.add_cycle = para->addCycle - 2; /*row address cycle*/
            /*Fill Cmd_info - end*/
            while (!((status = read_status(0x78,&Cmd_info) )&RDY_BUSY)); /*Process busy*/
#if ( defined(__NAND_FLASH_HARDWARE_TEST__) && defined(__MAUI_BASIC__) && !defined(__UBL__))
			status |= (ErrorP & 0x01);
#endif

            if (status&PASS_FAIL)
            {
                retVal |= 1;
            }
            /*check plane 1*/
            /*Fill Cmd_info - start*/
            Cmd_info.add[0] = (*(para->page_p+1) + para->pageOffset); /*row address*/
            Cmd_info.add_cycle = para->addCycle - 2; /*row address cycle*/
            /*Fill Cmd_info - end*/
            while (!((status = read_status(0x78,&Cmd_info) )&RDY_BUSY)); /*Process busy*/
#if ( defined(__NAND_FLASH_HARDWARE_TEST__) && defined(__MAUI_BASIC__) && !defined(__UBL__))
			status |= ((ErrorP & 0x02)>>1);
#endif

            if (status&PASS_FAIL)
            {
                retVal |= (1<<1);
            }
            nAND_RESET();
            return retVal;
        }
    }
    return MTD_STATUS_NO_ERROR;
}

/****************************************************************************
 * Function:    micron_twoPlane_CacheProgram
 *
 * Parameters:  mtd_drv_para *para
 *
 * Returns:   MTD_STATUS_NO_ERROR   No error
 *            MTD_STATUS_ERROR + index of error page (Low 16 bits)
 * Description: micron twoPlane cache program function.
 *              [Note] The start page must match para->pageOffset == 0, max para->pageOffset can not over 15
 ****************************************************************************/
kal_uint32 micron_twoPlane_CacheProgram (mtd_drv_para *para)
{
    kal_uint8 status;
    kal_uint32 retVal;
		#if (defined __UBL__) || (defined __FUE__) 
		#else
    	kal_uint32 event_group;    
    #endif

#if ( defined(__NAND_FLASH_HARDWARE_TEST__) && defined(__MAUI_BASIC__) && !defined(__UBL__))
	kal_uint32 ErrorP = 0;
#endif

    dbg_ASSERT( Flash_Info.pageSize >= 2048 );
    if (para->opFlag & FIRST_PROCESS)
    {
        /*plane 0*/
        NFI_OP_RESET();
        /*Fill Cmd_info - start*/

		#if defined(__NFI_VERSION3_1__)
		Cmd_info.add[0] = 0; 	// Colume address
        Cmd_info.add[1] = *para->page_p + para->pageOffset; 	// Row address
        *NFI_CNFG = CNFG_OP_CUST | CNFG_AUTO_FMT_EN;
        *NFI_CON = (Flash_Info.pageSize >> 9) << CON_NFI_SEC_SHIFT;
        #else // defined(__NFI_VERSION3_1__)
        Cmd_info.add[0] = (*para->page_p + para->pageOffset)<<16 ;
        Cmd_info.add[1] = (*para->page_p + para->pageOffset)>>16 ;
        #endif // defined(__NFI_VERSION3_1__)

        dbg_ASSERT( (*para->page_p/Flash_Info.blockPage) == (*para->page_p + para->pageOffset)/Flash_Info.blockPage ); /*in same block*/
        //dbg_ASSERT( para->buff  );
        Cmd_info.buff = para->buff;
        dbg_ASSERT( Flash_Info.pageSize%512 == 0 );
        Cmd_info.buff_len = Flash_Info.pageSize;
        dbg_ASSERT( para->spare );
        Cmd_info.spare = para->spare;

        #if defined(__NFI_VERSION3_1__)
        Cmd_info.spare_len = PAGEFMT_FDM_DEFAULT;
        Cmd_info.CustomMode = 1;
		#else // defined(__NFI_VERSION3_1__)
        Cmd_info.spare_len = Flash_Info.spareSize;
		#endif // defined(__NFI_VERSION3_1__)

        Cmd_info.ECCFlag = ECC_WHOLE;
        Cmd_info.add_cycle = para->addCycle;
        Cmd_info.cmd_len = 2;
        Cmd_info.intFlag = 0; /*Reset*/
        /*Fill Cmd_info - end*/
        send_command_add_data(0x80, 0x11, &Cmd_info);

        /*Fill Cmd_info - start*/
        Cmd_info.add[0] = (*para->page_p + para->pageOffset) ; /*row address*/
        Cmd_info.add_cycle = para->addCycle - 2; /*row address cycle*/
        /*Fill Cmd_info - end*/
        while (!((status = read_status(0x78,&Cmd_info) )&RDY_BUSY)); /*Dummy busy*/
        if (status&PASS_FAIL)
        {
            while (!((status = read_status(0x78,&Cmd_info) )&INTERNAL_BUSY));
            nAND_RESET();
            return (MTD_STATUS_ERROR|1);
        }
        /*plane 1*/
        NFI_OP_RESET();
        /*Fill Cmd_info - start*/

        #if defined(__NFI_VERSION3_1__)
		Cmd_info.add[0] = 0; 	// Colume address
        Cmd_info.add[1] = *(para->page_p+1) + para->pageOffset; 	// Row address
        *NFI_CNFG = CNFG_OP_CUST | CNFG_AUTO_FMT_EN;
        *NFI_CON = (Flash_Info.pageSize >> 9) << CON_NFI_SEC_SHIFT;
        #else // defined(__NFI_VERSION3_1__)
        Cmd_info.add[0] = (*(para->page_p+1) + para->pageOffset)<<16 ;
        Cmd_info.add[1] = (*(para->page_p+1) + para->pageOffset)>>16 ;
        #endif // defined(__NFI_VERSION3_1__)

        dbg_ASSERT( (*(para->page_p+1)/Flash_Info.blockPage) == (*(para->page_p+1) + para->pageOffset)/Flash_Info.blockPage ); /*in same block*/
        //dbg_ASSERT( para->buff  );
        //dbg_ASSERT( Flash_Info.pageSize%512 == 0 );
        Cmd_info.buff = &para->buff[0 + Flash_Info.pageSize];;
        Cmd_info.buff_len = Flash_Info.pageSize;
        //dbg_ASSERT( para->spare );
        if (para->opFlag & ONE_SPARE) {
	        Cmd_info.spare = &para->spare[0];
        } else {
        	Cmd_info.spare = &para->spare[0 + Flash_Info.spareSize];
        }
        #if defined(__NFI_VERSION3_1__)
        Cmd_info.spare_len = PAGEFMT_FDM_DEFAULT;
        Cmd_info.CustomMode = 1;
		#else // defined(__NFI_VERSION3_1__)
        Cmd_info.spare_len = Flash_Info.spareSize;
		#endif // defined(__NFI_VERSION3_1__)

        Cmd_info.ECCFlag = ECC_WHOLE;
        Cmd_info.add_cycle = para->addCycle;
        Cmd_info.cmd_len = 2;
        /*Fill Cmd_info - end*/
        Cmd_info.intFlag = 0; /*Reset*/
        if (para->opFlag & SECOND_BUSY)
        {
	        #if (defined __UBL__)||(defined __FUE__)
	        #else        
            if (nfi_egid && use_interrupt == KAL_TRUE)
                Cmd_info.intFlag = BUSY_RETURN_EN;
          #endif
        }

        if ( para->opFlag & PROGRAM_CACHED)
            send_command_add_data(0x80, 0x15, &Cmd_info);
        else if ( para->opFlag & PROGRAM_FINAL)
            send_command_add_data(0x80, 0x10, &Cmd_info);

        #if defined(__NFI_VERSION3_1__)
        *NFI_CNRNB = STROBE_TIMEOUT;
        #endif

        if (para->opFlag & SECOND_BUSY) /*here means FIRST_PROCESS + SECOND_BUSY*/
        {
	        #if (defined __UBL__)||(defined __FUE__)
	        #else        
            if (nfi_egid && use_interrupt == KAL_TRUE)
            {
                kal_retrieve_eg_events(nfi_egid, NFI_EVENT, KAL_OR_CONSUME,
                                       &event_group, KAL_SUSPEND);
            }
          #endif
        }
    }
    if (para->opFlag & SECOND_BUSY)
    {
        kal_uint8 status_chk;
        Cmd_info.add_cycle = 0;
        while (!((status = read_status(0x70,&Cmd_info) )&RDY_BUSY));

        if ( ( para->opFlag & PROGRAM_CACHED)&& para->pageOffset == 0)
            status_chk = 0x00;  /*invalid*/
        else if ( para->opFlag & PROGRAM_FINAL)
            status_chk = 0x01|0x02; /*previous + current*/
        else
            status_chk = 0x02; /*previous*/

#if ( defined(__NAND_FLASH_HARDWARE_TEST__) && defined(__MAUI_BASIC__) && !defined(__UBL__))
		if ((PFTrigger==KAL_TRUE) && (PFTestCase & PF_MTD_TRIGGER)) {
			kal_uint8 Count;
			kal_uint32 PageAddr0, PageAddr1;

			PFTrigger = KAL_FALSE;
			Count=0;
			while (1) {
				if (ProgBadAddr[Count].Zone==0xff) {
					break;
				}
				PageAddr0 = (*para->page_p + para->pageOffset);
				PageAddr1 = (*(para->page_p+1) + para->pageOffset);
	        	if ( (((ProgBadAddr[Count].Block<<6)+ProgBadAddr[Count].Page) == PageAddr0) ||
	        		 ((ProgBadAddr[Count].Page==0xffff) && (ProgBadAddr[Count].Block == (PageAddr0>>6))) ) {
					if (status_chk & 0x02) {
		        		status |= 0x02;
						ErrorP |= 0x02;
					} else {
		        		status |= PASS_FAIL;
						ErrorP |= 0x01;
					}
	        		break;
	        	}
	        	if ( (((ProgBadAddr[Count].Block<<6)+ProgBadAddr[Count].Page) == PageAddr1) ||
	        		 ((ProgBadAddr[Count].Page==0xffff) && (ProgBadAddr[Count].Block == (PageAddr1>>6))) ) {
					if (status_chk & 0x02) {
		        		status |= 0x02;
		        		ErrorP |= 0x20;
					} else {
		        		status |= PASS_FAIL;
		        		ErrorP |= 0x10;
					}
					break;
	        	}
				Count++;
			}

		}
#endif
        if (status&status_chk)
        {   /*Program fail*/
            retVal = MTD_STATUS_ERROR;
            /*check plane 0*/
            /*Fill Cmd_info - start*/
            Cmd_info.add[0] = (*para->page_p + para->pageOffset) ; /*row address*/
            Cmd_info.add_cycle = para->addCycle - 2; /*row address cycle*/
            /*Fill Cmd_info - end*/
            while (!((status = read_status(0x78,&Cmd_info) )&INTERNAL_BUSY)); /*Program busy*/

#if ( defined(__NAND_FLASH_HARDWARE_TEST__) && defined(__MAUI_BASIC__) && !defined(__UBL__))
			status |= (ErrorP & 0x03);
#endif

            if (status&(status_chk |PASS_FAIL))
            {
                retVal |= (1);
            }
            /*check plane 1*/
            /*Fill Cmd_info - start*/
            Cmd_info.add[0] = (*(para->page_p+1) + para->pageOffset); /*row address*/
            Cmd_info.add_cycle = para->addCycle - 2; /*row address cycle*/
            /*Fill Cmd_info - end*/
            while (!((status = read_status(0x78,&Cmd_info) )&INTERNAL_BUSY)); /*Program busy*/

#if ( defined(__NAND_FLASH_HARDWARE_TEST__) && defined(__MAUI_BASIC__) && !defined(__UBL__))
			status |= ((ErrorP & 0x30)>>4);
#endif

            if (status&(status_chk |PASS_FAIL))
            {
                retVal |= (1<<1);
            }
            nAND_RESET();
            return retVal;
        }
    }
    return MTD_STATUS_NO_ERROR;
}

kal_uint32 micron_twoDie_Program (mtd_drv_para *para)
{
    kal_uint8 status;
    mtd_drv_para drv_data;
    kal_uint32 retVal;
    kal_uint32 ret_die0 = MTD_STATUS_NO_ERROR, ret_die1 = MTD_STATUS_NO_ERROR;
    dbg_ASSERT( Flash_Info.pageSize >= 2048 );
    drv_data.addCycle = para->addCycle;
    drv_data.pageOffset = para->pageOffset;

    if (para->opFlag & FIRST_PROCESS)
    {
        /*die 0*/
        drv_data.page_p = para->page_p;
        drv_data.buff = para->buff;
        drv_data.spare = para->spare;
        drv_data.opFlag = FIRST_PROCESS;
        if (para->opFlag & ONE_SPARE) {

        	drv_data.opFlag |= ONE_SPARE;
        }
        ret_die0 = single_Page_Program(&drv_data);
        if ( ret_die0 == MTD_STATUS_NO_ERROR)
        {   /*die 1*/
            drv_data.page_p = (para->page_p+1);
            drv_data.buff = &para->buff[0 + (1*Flash_Info.pageSize)];
            drv_data.opFlag = FIRST_PROCESS;
            if (para->opFlag & ONE_SPARE) {
	            drv_data.spare = &para->spare[0];
	            drv_data.opFlag |= ONE_SPARE;
            } else {
	            drv_data.spare = &para->spare[0 + (1*Flash_Info.spareSize)];
            }
            ret_die1 = single_Page_Program(&drv_data);
         }
    }
    if ( ret_die0 != MTD_STATUS_NO_ERROR || ret_die1 != MTD_STATUS_NO_ERROR )
    {
        retVal = MTD_STATUS_ERROR;
        retVal |= (ret_die0&0xFFFF);
        retVal |= (ret_die1&0xFFFF)<<1;
        return retVal;
    }
    if (para->opFlag & SECOND_BUSY)
    {
        /*die 0*/
        Cmd_info.add[0] = (*para->page_p + para->pageOffset) ; /*row address*/
        Cmd_info.add_cycle = para->addCycle - 2; /*row address cycle*/
        while (!((status = read_status(0x78,&Cmd_info) )&RDY_BUSY)); /*Dummy busy*/
        if (status&PASS_FAIL)
        {   /*Program fail*/
            ret_die0 = (MTD_STATUS_ERROR|1);
        }
        /*die 1*/
        Cmd_info.add[0] = (*(para->page_p+1) + para->pageOffset) ; /*row address*/
        Cmd_info.add_cycle = para->addCycle - 2; /*row address cycle*/
        while (!((status = read_status(0x78,&Cmd_info) )&RDY_BUSY)); /*Dummy busy*/
        if (status&PASS_FAIL)
        {   /*Program fail*/
            ret_die1 = (MTD_STATUS_ERROR|1);
        }

        if ( ret_die0 != MTD_STATUS_NO_ERROR || ret_die1 != MTD_STATUS_NO_ERROR )
        {
            retVal = MTD_STATUS_ERROR;
            retVal |= (ret_die0&0xFFFF);
            retVal |= (ret_die1&0xFFFF)<<1;
            return retVal;
        }
    }
    return MTD_STATUS_NO_ERROR;
}


kal_uint32 micron_twoDie_Erase (mtd_drv_para *para)
{
    kal_uint8 status;
    mtd_drv_para drv_data;
    kal_uint32 retVal;
    kal_uint32 ret_die0 = MTD_STATUS_NO_ERROR, ret_die1 = MTD_STATUS_NO_ERROR;
    dbg_ASSERT( Flash_Info.pageSize >= 2048 );
    drv_data.addCycle = para->addCycle;
    drv_data.pageOffset = para->pageOffset;

    if (para->opFlag & FIRST_PROCESS)
    {
        /*die 0*/
        drv_data.page_p = para->page_p;
        drv_data.opFlag = FIRST_PROCESS;
        ret_die0 = single_Block_Erase(&drv_data);
        if ( ret_die0 == MTD_STATUS_NO_ERROR)
        {   /*die 1*/
            drv_data.page_p = (para->page_p+1);
            drv_data.opFlag = FIRST_PROCESS;
            ret_die1 = single_Block_Erase(&drv_data);
         }
    }
    if ( ret_die0 != MTD_STATUS_NO_ERROR || ret_die1 != MTD_STATUS_NO_ERROR )
    {
        retVal = MTD_STATUS_ERROR;
        retVal |= (ret_die0&0xFFFF);
        retVal |= (ret_die1&0xFFFF)<<1;
        return retVal;
    }
    if (para->opFlag & SECOND_BUSY)
    {
        /*die 0*/
        Cmd_info.add[0] = (*para->page_p + para->pageOffset) ; /*row address*/
        Cmd_info.add_cycle = para->addCycle - 2; /*row address cycle*/
        while (!((status = read_status(0x78,&Cmd_info) )&RDY_BUSY)); /* busy*/
        if (status&PASS_FAIL)
        {   /*Erase fail*/
            ret_die0 = (MTD_STATUS_ERROR|1);
        }
        /*die 1*/
        Cmd_info.add[0] = (*(para->page_p+1) + para->pageOffset) ; /*row address*/
        Cmd_info.add_cycle = para->addCycle - 2; /*row address cycle*/
        while (!((status = read_status(0x78,&Cmd_info) )&RDY_BUSY)); /* busy*/
        if (status&PASS_FAIL)
        {   /*Erase fail*/
            ret_die1 = (MTD_STATUS_ERROR|1);
        }

        if ( ret_die0 != MTD_STATUS_NO_ERROR || ret_die1 != MTD_STATUS_NO_ERROR )
        {
            retVal = MTD_STATUS_ERROR;
            retVal |= (ret_die0&0xFFFF);
            retVal |= (ret_die1&0xFFFF)<<1;
            return retVal;
        }
    }
    return MTD_STATUS_NO_ERROR;
}

kal_uint32 micron_twoDie_twoPlane_Program (mtd_drv_para *para)
{
    mtd_drv_para drv_data;
    kal_uint32 retVal;
    kal_uint32 ret_die0 = MTD_STATUS_NO_ERROR, ret_die1 = MTD_STATUS_NO_ERROR;
    dbg_ASSERT( Flash_Info.pageSize >= 2048 );
    drv_data.addCycle = para->addCycle;
    drv_data.pageOffset = para->pageOffset;

    if (para->opFlag & FIRST_PROCESS)
    {
        /*die 0*/
        drv_data.page_p = para->page_p;
        drv_data.buff = para->buff;
        drv_data.spare = para->spare;
        drv_data.opFlag = FIRST_PROCESS;
        if (para->opFlag & ONE_SPARE) {
        	drv_data.opFlag |= ONE_SPARE;
        }
        ret_die0 = micron_twoPlane_Program(&drv_data);
        if ( ret_die0 == MTD_STATUS_NO_ERROR)
        {   /*die 1*/
            drv_data.page_p = (para->page_p+2);
            drv_data.buff = &para->buff[0 + (2*Flash_Info.pageSize)];
            drv_data.opFlag = FIRST_PROCESS;
            if (para->opFlag & ONE_SPARE) {
	            drv_data.spare = &para->spare[0];
	            drv_data.opFlag |= ONE_SPARE;
            } else {
	            drv_data.spare = &para->spare[0 + (2*Flash_Info.spareSize)];
            }
            ret_die1 = micron_twoPlane_Program(&drv_data);
        }
    }
    if ( ret_die0 != MTD_STATUS_NO_ERROR || ret_die1 != MTD_STATUS_NO_ERROR )
    {
        retVal = MTD_STATUS_ERROR;
        retVal |= (ret_die0&0xFFFF);
        retVal |= (ret_die1&0xFFFF)<<2;
        return retVal;
    }
    if (para->opFlag & SECOND_BUSY)
    {
        /*die 0*/
        drv_data.page_p = para->page_p;
        //drv_data.buff = para->buff;
        //drv_data.spare = para->spare;
        drv_data.opFlag = SECOND_BUSY;
        ret_die0 = micron_twoPlane_Program(&drv_data);
        /*die 1*/
        drv_data.page_p = (para->page_p+2);
        //drv_data.buff = &para->buff[0 + xxx];
        //drv_data.spare = para->spare[0 + xxx];
        drv_data.opFlag = SECOND_BUSY;
        ret_die1 = micron_twoPlane_Program(&drv_data);

        if ( ret_die0 != MTD_STATUS_NO_ERROR || ret_die1 != MTD_STATUS_NO_ERROR )
        {
            retVal = MTD_STATUS_ERROR;
            retVal |= (ret_die0&0xFFFF);
            retVal |= (ret_die1&0xFFFF)<<2;
            return retVal;
        }
    }
    return MTD_STATUS_NO_ERROR;
}


kal_uint32 micron_twoDie_twoPlane_Erase (mtd_drv_para *para)
{
    mtd_drv_para drv_data;
    kal_uint32 retVal;
    kal_uint32 ret_die0 = MTD_STATUS_NO_ERROR, ret_die1 = MTD_STATUS_NO_ERROR;
    dbg_ASSERT( Flash_Info.pageSize >= 2048 );
    drv_data.addCycle = para->addCycle;
    drv_data.pageOffset = para->pageOffset;

    if (para->opFlag & FIRST_PROCESS)
    {
        /*die 0*/
        drv_data.page_p = para->page_p;
        drv_data.opFlag = FIRST_PROCESS;
        ret_die0 = micron_twoPlane_Erase(&drv_data);
        if ( ret_die0 == MTD_STATUS_NO_ERROR)
        {   /*die 1*/
            drv_data.page_p = (para->page_p+2);
            drv_data.opFlag = FIRST_PROCESS;
            ret_die1 = micron_twoPlane_Erase(&drv_data);
        }
    }
    if ( ret_die0 != MTD_STATUS_NO_ERROR || ret_die1 != MTD_STATUS_NO_ERROR )
    {
        retVal = MTD_STATUS_ERROR;
        retVal |= (ret_die0&0xFFFF);
        retVal |= (ret_die1&0xFFFF)<<2;
        return retVal;
    }
    if (para->opFlag & SECOND_BUSY)
    {
        /*die 0*/
        drv_data.page_p = para->page_p;
        //drv_data.buff = para->buff;
        //drv_data.spare = para->buff;
        drv_data.opFlag = SECOND_BUSY;
        ret_die0 = micron_twoPlane_Erase(&drv_data);
        /*die 1*/
        drv_data.page_p = (para->page_p+2);
        //drv_data.buff = &para->buff[0 + xxx];
        //drv_data.spare = para->spare[0 + xxx];
        drv_data.opFlag = SECOND_BUSY;
        ret_die1 = micron_twoPlane_Erase(&drv_data);

        if ( ret_die0 != MTD_STATUS_NO_ERROR || ret_die1 != MTD_STATUS_NO_ERROR )
        {
            retVal = MTD_STATUS_ERROR;
            retVal |= (ret_die0&0xFFFF);
            retVal |= (ret_die1&0xFFFF)<<2;
            return retVal;
        }
    }
    return MTD_STATUS_NO_ERROR;
}

kal_uint32 micron_twoDie_CacheProgram (mtd_drv_para *para)
{
    mtd_drv_para drv_data;
    kal_uint32 retVal;
    kal_uint32 ret_die0 = MTD_STATUS_NO_ERROR, ret_die1 = MTD_STATUS_NO_ERROR;
    dbg_ASSERT( Flash_Info.pageSize >= 2048 );
    drv_data.addCycle = para->addCycle;
    drv_data.pageOffset = para->pageOffset;

    if (para->opFlag & FIRST_PROCESS)
    {
        /*die 0*/
        drv_data.page_p = para->page_p;
        drv_data.buff = para->buff;
        drv_data.spare = para->spare;
        drv_data.opFlag = FIRST_PROCESS;
        if ( para->opFlag & PROGRAM_CACHED)
            drv_data.opFlag|=PROGRAM_CACHED;
        else if ( para->opFlag & PROGRAM_FINAL)
            drv_data.opFlag|=PROGRAM_FINAL;
        if (para->opFlag & ONE_SPARE) {
        	drv_data.opFlag |= ONE_SPARE;
        }
        ret_die0 = single_Page_CacheProgram(&drv_data);
        if ( ret_die0 == MTD_STATUS_NO_ERROR)
        {   /*die 1*/
            drv_data.page_p = (para->page_p+1);
            drv_data.buff = &para->buff[0 + (1*Flash_Info.pageSize)];
            drv_data.opFlag = FIRST_PROCESS;
            if (para->opFlag & ONE_SPARE) {
	            drv_data.spare = &para->spare[0];
	            drv_data.opFlag |= ONE_SPARE;
            } else {
            	drv_data.spare = &para->spare[0 + (1*Flash_Info.spareSize)];
            }
            if ( para->opFlag & PROGRAM_CACHED)
                drv_data.opFlag|=PROGRAM_CACHED;
            else if ( para->opFlag & PROGRAM_FINAL)
                drv_data.opFlag|=PROGRAM_FINAL;
            ret_die1 = single_Page_CacheProgram(&drv_data);
        }
    }
    if ( ret_die0 != MTD_STATUS_NO_ERROR || ret_die1 != MTD_STATUS_NO_ERROR )
    {
        retVal = MTD_STATUS_ERROR;
        retVal |= (ret_die0&0xFFFF);
        retVal |= (ret_die1&0xFFFF)<<1;
        return retVal;
    }
    if (para->opFlag & SECOND_BUSY)
    {
        /*die 0*/
        drv_data.page_p = para->page_p;
        //drv_data.buff = para->buff;
        //drv_data.spare = para->buff;
        drv_data.opFlag = SECOND_BUSY;
        if ( para->opFlag & PROGRAM_CACHED)
            drv_data.opFlag|=PROGRAM_CACHED;
        else if ( para->opFlag & PROGRAM_FINAL)
            drv_data.opFlag|=PROGRAM_FINAL;

        ret_die0 = single_Page_CacheProgram(&drv_data);
        /*die 1*/
        drv_data.page_p = (para->page_p+1);
        //drv_data.buff = &para->buff[0 + xxx];
        //drv_data.spare = para->spare[0 + xxx];
        drv_data.opFlag = SECOND_BUSY;
        if ( para->opFlag & PROGRAM_CACHED)
            drv_data.opFlag|=PROGRAM_CACHED;
        else if ( para->opFlag & PROGRAM_FINAL)
            drv_data.opFlag|=PROGRAM_FINAL;

        ret_die1 = single_Page_CacheProgram(&drv_data);

        if ( ret_die0 != MTD_STATUS_NO_ERROR || ret_die1 != MTD_STATUS_NO_ERROR )
        {
            retVal = MTD_STATUS_ERROR;
            retVal |= (ret_die0&0xFFFF);
            retVal |= (ret_die1&0xFFFF)<<1;
            return retVal;
        }
    }
    return MTD_STATUS_NO_ERROR;
}


kal_uint32 micron_twoDie_twoPlane_CacheProgram (mtd_drv_para *para)
{
    mtd_drv_para drv_data;
    kal_uint32 retVal;
    kal_uint32 ret_die0 = MTD_STATUS_NO_ERROR, ret_die1 = MTD_STATUS_NO_ERROR;
    dbg_ASSERT( Flash_Info.pageSize >= 2048 );
    drv_data.addCycle = para->addCycle;
    drv_data.pageOffset = para->pageOffset;

    if (para->opFlag & FIRST_PROCESS)
    {
        /*die 0*/
        drv_data.page_p = para->page_p;
        drv_data.buff = para->buff;
        drv_data.spare = para->spare;
        drv_data.opFlag = FIRST_PROCESS;
        if ( para->opFlag & PROGRAM_CACHED)
            drv_data.opFlag|=PROGRAM_CACHED;
        else if ( para->opFlag & PROGRAM_FINAL)
            drv_data.opFlag|=PROGRAM_FINAL;
		if (para->opFlag & ONE_SPARE) {
			drv_data.opFlag |= ONE_SPARE;
		}
        ret_die0 = micron_twoPlane_CacheProgram(&drv_data);
        if ( ret_die0 == MTD_STATUS_NO_ERROR)
        {   /*die 1*/
            drv_data.page_p = (para->page_p+2);
            drv_data.buff = &para->buff[0 + (2*Flash_Info.pageSize)];
            drv_data.opFlag = FIRST_PROCESS;
            if (para->opFlag & ONE_SPARE) {
	            drv_data.spare = &para->spare[0];
	            drv_data.opFlag |= ONE_SPARE;
            } else {
            	drv_data.spare = &para->spare[0 + (2*Flash_Info.spareSize)];
            }
            if ( para->opFlag & PROGRAM_CACHED)
                drv_data.opFlag|=PROGRAM_CACHED;
            else if ( para->opFlag & PROGRAM_FINAL)
                drv_data.opFlag|=PROGRAM_FINAL;
            ret_die1 = micron_twoPlane_CacheProgram(&drv_data);
        }
    }
    if ( ret_die0 != MTD_STATUS_NO_ERROR || ret_die1 != MTD_STATUS_NO_ERROR )
    {
        retVal = MTD_STATUS_ERROR;
        retVal |= (ret_die0&0xFFFF);
        retVal |= (ret_die1&0xFFFF)<<2;
        return retVal;
    }
    if (para->opFlag & SECOND_BUSY)
    {
        /*die 0*/
        drv_data.page_p = para->page_p;
        //drv_data.buff = para->buff;
        //drv_data.spare = para->buff;
        drv_data.opFlag = SECOND_BUSY;
        if ( para->opFlag & PROGRAM_CACHED)
            drv_data.opFlag|=PROGRAM_CACHED;
        else if ( para->opFlag & PROGRAM_FINAL)
            drv_data.opFlag|=PROGRAM_FINAL;

        ret_die0 = micron_twoPlane_Program(&drv_data);
        /*die 1*/
        drv_data.page_p = (para->page_p+2);
        //drv_data.buff = &para->buff[0 + xxx];
        //drv_data.spare = para->spare[0 + xxx];
        drv_data.opFlag = SECOND_BUSY;
        if ( para->opFlag & PROGRAM_CACHED)
            drv_data.opFlag|=PROGRAM_CACHED;
        else if ( para->opFlag & PROGRAM_FINAL)
            drv_data.opFlag|=PROGRAM_FINAL;

        ret_die1 = micron_twoPlane_Program(&drv_data);

        if ( ret_die0 != MTD_STATUS_NO_ERROR || ret_die1 != MTD_STATUS_NO_ERROR )
        {
            retVal = MTD_STATUS_ERROR;
            retVal |= (ret_die0&0xFFFF);
            retVal |= (ret_die1&0xFFFF)<<2;
            return retVal;
        }
    }
    return MTD_STATUS_NO_ERROR;
}

/*******************************************************************************
 *  OTP functions
 *******************************************************************************/
#define SAMSUNG_OTP_PAGE_NUM 6
#define HYNIX_OTP_PAGE_NUM  32
#define ESMT_OTP_PAGE_NUM  30
static const kal_uint32 Samsung_OTP_Page[SAMSUNG_OTP_PAGE_NUM] = {0x15, 0x16, 0x17, 0x18, 0x19, 0x1b};
static const kal_uint32 Hynix_OTP_Page[HYNIX_OTP_PAGE_NUM] = {0x20, 0x21,0x22,0x23,0x24,0x25,0x26,0x27,
                                                              0x28, 0x29,0x2A,0x2B,0x2C,0x2D,0x2E,0x2F,
                                                              0x30, 0x31,0x32,0x33,0x34,0x35,0x36,0x37,
                                                              0x38, 0x39,0x3A,0x3B,0x3C,0x3D,0x3E,0x3F};
static const kal_uint32 ESMT_OTP_Page[ESMT_OTP_PAGE_NUM] =   {0x01,0x02,0x03,0x04,0x05,0x06,
																															0x07,0x08,0x09,0x0a,0x0b,0x0c,
																															0x0d,0x0e,0x0f,0x10,0x11,0x12,
																															0x13,0x14,0x15,0x16,0x17,0x18,
																															0x19,0x1a,0x1b,0x1c,0x1d,0x1e};                                                              
kal_int32  NAND_OTPAccess(kal_int32 accesstype, kal_uint32 PageAddr, void *BufferPtr, void *SparePtr)
{
		kal_uint32 dStatus;
	  if((Flash_Info.deviceInfo_CE[0].ID_info[0]==HYNIX)||
	  	 (Flash_Info.deviceInfo_CE[0].ID_info[0]==ST))
	  {
	  	dStatus = hynix_OTPAccess(accesstype,PageAddr,BufferPtr,SparePtr);
	  }
	  else if((Flash_Info.deviceInfo_CE[0].ID_info[0]==MICRON))
	  {
	  	dStatus = micron_OTPAccess(accesstype,PageAddr,BufferPtr,SparePtr);
	  }
	  else if((Flash_Info.deviceInfo_CE[0].ID_info[0] == ESMT))
	  {
	  	dStatus = ESMT_OTPAccess(accesstype,PageAddr,BufferPtr,SparePtr);
	  }
	  else
	  {
	  	dStatus = samsung_OTPAccess(accesstype,PageAddr,BufferPtr,SparePtr);
	  }
	  return dStatus;
}
kal_int32 NAND_OTPQueryLength(kal_uint32 *Length)
{
		kal_uint32 dStatus;
	  if((Flash_Info.deviceInfo_CE[0].ID_info[0]==HYNIX)||
	  	 (Flash_Info.deviceInfo_CE[0].ID_info[0]==ST))
	  {
	  	dStatus = hynix_OTPQueryLength(Length);
	  }
	  else if((Flash_Info.deviceInfo_CE[0].ID_info[0]==MICRON))
	  {
	  	dStatus = micron_OTPQueryLength(Length);
	  }
	  else if((Flash_Info.deviceInfo_CE[0].ID_info[0] == ESMT))
	  {
	  	dStatus = ESMT_OTPQueryLength(Length);
	  }
	  else
	  {
	  	dStatus = samsung_OTPQueryLength(Length);
	  }
	  return dStatus;
}
void pagefmt_config(kal_uint8 IOWidth, kal_uint16 pageSize, kal_uint16 spare_size)
{
	if (8 == IOWidth)
	{
		if (512 == pageSize)
		{
			*NFI_PAGEFMT = PAGEFMT_512_8BIT;
		}
		else if (2048 == pageSize)
		{
			*NFI_PAGEFMT = PAGEFMT_2K_8BIT;
		}
#if defined(__NFI_VERSION3_1__)
		else if (4096 == pageSize)
		{
			*NFI_PAGEFMT = PAGEFMT_4K_8BIT;
		}
#endif		
	}
	else /* Flash_Info.deviceInfo_CE[0].IOWidth == 16*/
	{
		if (512 == pageSize)
		{
			*NFI_PAGEFMT = PAGEFMT_512_16BIT;
		}
		else if (2048 == pageSize)
		{
			*NFI_PAGEFMT = PAGEFMT_2K_16BIT;
		}
#if defined(__NFI_VERSION3_1__)
		else if (4096 == pageSize)
		{
			*NFI_PAGEFMT = PAGEFMT_4K_16BIT;
		}
#endif		
	}

#if defined(__NFI_VERSION3_1__)
	*NFI_PAGEFMT |= PAGEFMT_FDM_ECC_SETTING;
#endif	

#if defined(__ECC_8_BIT_SUPPORT__)	
	if(spare_size >= (26 * pageSize / 512)) //only support 8 bit ecc
	{
		*NFI_PAGEFMT |= (PAGEFMT_SPARE_26<<PAGEFMT_SPARE_SHIFT);
	}	
#endif

#if ((defined(MT6228)) || (defined(MT6229)) || (defined(MT6230)))
	if (16 == IOWidth)
	{
		*NFI_GPIO_DATA1 &= 0x0FFF;
        *NFI_GPIO_DATA2 &= 0xF000;
	}
#endif	
}
// Currently Offset should be page boundary and and length should be one page size.
kal_int32  samsung_OTPAccess(kal_int32 accesstype, kal_uint32 PageAddr, void *BufferPtr, void *SparePtr)
{
	kal_uint32 dErrorCode = FS_NO_ERROR;
	kal_uint32 retVal;

	if (PageAddr >= SAMSUNG_OTP_PAGE_NUM) {
		return FS_FLASH_OTP_OVERSCOPE;   
	}

	if ( (accesstype!=FS_OTP_READ) && (accesstype!=FS_OTP_WRITE) ) {
		return FS_NO_ERROR;
	}

	pdn_nfi(KAL_TRUE);
  #if (defined __UBL__)||(defined __FUE__)
  #else	
	if (! (nfi_egid && use_interrupt == KAL_TRUE) )
	{
	    if(nfi_egid && (kal_query_systemInit() == KAL_FALSE && INT_QueryExceptionStatus() == KAL_FALSE))
	        use_interrupt = KAL_TRUE;
	}
	#endif
	
	pagefmt_config(Flash_Info.deviceInfo_CE[0].IOWidth, Flash_Info.pageSize, Flash_Info.spareSize);	

   // 0. Switch to OTP mode
    SET_NFI_CS0;
	  NFI_OP_RESET();          
    *NFI_CMD = 0x30;

    #if defined(__NFI_VERSION3_1__)
   	while ((*NFI_STA) & STA_CMD_STATE);
    #else // defined(__NFI_VERSION3_1__)
    while (*NFI_PSTA & STATUS_CMD);	
    #endif // defined(__NFI_VERSION3_1__)
    		
	  NFI_OP_RESET();          
    *NFI_CMD = 0x65;
    
    #if defined(__NFI_VERSION3_1__)
   	while ((*NFI_STA) & STA_CMD_STATE);
    #else // defined(__NFI_VERSION3_1__)   
    while (*NFI_PSTA & STATUS_CMD);
    #endif // defined(__NFI_VERSION3_1__)
		NFI_OP_RESET();      
		
    // 1. Config OTP necessary parameter
	  Cmd_info.buff = BufferPtr;
    Cmd_info.buff_len = Flash_Info.pageSize;
    Cmd_info.spare = SparePtr;
    Cmd_info.ECCFlag = ECC_WHOLE;
    
    #if defined(__NFI_VERSION3_1__)
      Cmd_info.spare_len = PAGEFMT_FDM_DEFAULT;
      Cmd_info.CustomMode = 1;
	    Cmd_info.add[0] = 0; 	// Colume address
      Cmd_info.add[1] = Samsung_OTP_Page[PageAddr]; 	// Row address
      *NFI_CNFG = CNFG_OP_CUST | CNFG_AUTO_FMT_EN;
      *NFI_CON = (Flash_Info.pageSize >> 9) << CON_NFI_SEC_SHIFT;        
	  #else // defined(__NFI_VERSION3_1__)
      Cmd_info.spare_len = Flash_Info.spareSize;
      if (Flash_Info.pageSize == 512)
      {
          Cmd_info.add[0] = Samsung_OTP_Page[PageAddr]<<8 ; 
      }
      else
      {
          Cmd_info.add[0] = Samsung_OTP_Page[PageAddr]<<16 ; 
          Cmd_info.add[1] = Samsung_OTP_Page[PageAddr]>>16 ; 
      }    
	  #endif // defined(__NFI_VERSION3_1__)
       
    Cmd_info.intFlag = 0;
    Cmd_info.add_cycle = Flash_Info.deviceInfo_CE[0].address_cycle; 
	
    

	if (accesstype==FS_OTP_READ)
	{
	  
	    #if defined(__NFI_VERSION3_1__)
	   	*NFI_CNFG |= CNFG_READ_EN;
	    #endif // defined(__NFI_VERSION3_1__)

        if (Flash_Info.pageSize == 512)
        {
            Cmd_info.cmd_len = 1;
            send_command_add(0x00, 0, &Cmd_info);
        }
        else
        {
            Cmd_info.cmd_len = 2;
            send_command_add(0x00, 0x30, &Cmd_info);
        }

#if defined(__NFI_VERSION3_1__)
        *NFI_CNRNB = STROBE_TIMEOUT;
        while( !(*NFI_STA & STA_NAND_BUSY_RETURN) );/*check device busy status*/
#else
			{
				kal_uint32 Delay;
      	// 200ns delay maximum.
  	    for (Delay=0; Delay<COUNTER_200nS; Delay++){
					#if defined(__MTK_TARGET__)
						#if defined(__ARMCC_VERSION)
							__asm{nop};
						#elif defined(__GNUC__) 
							__asm__("nop");
						#endif /* __RVCT__ , __GNUC__ */ 
					#endif /* __MTK_TARGET__ */
	      }								
        while (*NFI_PSTA & STATUS_BUSY);  /*check device busy status*/
        NFI_OP_RESET();
      }
#endif               
       
       retVal = readfifo(&Cmd_info);
       if (retVal == MTD_STATUS_ERROR)
       {
            nAND_RESET();            
            //dErrorCode = FS_FLASH_OTP_UNKNOWERR;// Error handling is processed by Caller
       }
	}
	else if (accesstype==FS_OTP_WRITE)
	{
 		#if (defined __UBL__)||(defined __FUE__)    
		#else
    kal_uint32 event_group;
    #endif

	    #if defined(__NFI_VERSION3_1__)
	   	*NFI_CNFG &= ~CNFG_READ_EN;
	    #endif // defined(__NFI_VERSION3_1__)    
      #if (defined __UBL__)||(defined __FUE__)
      #else
		  if (nfi_egid && use_interrupt == KAL_TRUE) {
		      Cmd_info.intFlag = BUSY_RETURN_EN;
		  }
		  #endif
		  Cmd_info.cmd_len = 2;
		  send_command_add_data(0x80, 0x10, &Cmd_info);

      #if (defined __UBL__)||(defined __FUE__)
      #else
	    if (nfi_egid && use_interrupt == KAL_TRUE)
	    {
	        kal_retrieve_eg_events(nfi_egid, NFI_EVENT, KAL_OR_CONSUME,
	                               &event_group, KAL_SUSPEND);
	    }
	    #endif
			#if defined(__NFI_VERSION3_1__)
      while( !(*NFI_STA & STA_NAND_BUSY_RETURN) );/*check device busy status*/
			#else
			{
				kal_uint32 Delay;
    		// 200ns delay maximum.
	    	for (Delay=0; Delay<COUNTER_200nS; Delay++){
					#if defined(__MTK_TARGET__)
						#if defined(__ARMCC_VERSION)
							__asm{nop};
						#elif defined(__GNUC__) 
							__asm__("nop");
						#endif /* __RVCT__ , __GNUC__ */ 
					#endif /* __MTK_TARGET__ */
	    	}					
      	while (*NFI_PSTA & STATUS_BUSY);  /*check device busy status*/
      }
			#endif               
	}

	nAND_RESET();	// Reset command will have NAND back to normal mode.
	NFI_OP_RESET();          

	pdn_nfi(KAL_FALSE);
    
	return dErrorCode;	
}

kal_int32 samsung_OTPQueryLength(kal_uint32 *Length)
{
	*Length = SAMSUNG_OTP_PAGE_NUM * Flash_Info.pageSize;
	return FS_NO_ERROR;
}
kal_int32  hynix_OTPAccess(kal_int32 accesstype, kal_uint32 PageAddr, void *BufferPtr, void *SparePtr)
{
	kal_uint32 dErrorCode = FS_NO_ERROR;
	kal_uint32 retVal;
	
	if (PageAddr >= HYNIX_OTP_PAGE_NUM) {
		return FS_FLASH_OTP_OVERSCOPE;
	}

	if ( (accesstype!=FS_OTP_READ) && (accesstype!=FS_OTP_WRITE) ) {
		return FS_NO_ERROR;
	}

	pdn_nfi(KAL_TRUE);
  #if (defined __UBL__)||(defined __FUE__)
  #else	
	if (! (nfi_egid && use_interrupt == KAL_TRUE) )
	{
	    if(nfi_egid && (kal_query_systemInit() == KAL_FALSE && INT_QueryExceptionStatus() == KAL_FALSE))
	        use_interrupt = KAL_TRUE;
	}
	#endif
	pagefmt_config(Flash_Info.deviceInfo_CE[0].IOWidth, Flash_Info.pageSize, Flash_Info.spareSize);

  SET_NFI_CS0;

  // 0.Switch to OTP mode
	NFI_OP_RESET();
  *NFI_CMD = 0x04;
  #if defined(__NFI_VERSION3_1__)
   	while ((*NFI_STA) & STA_CMD_STATE);
  #else // defined(__NFI_VERSION3_1__)
    while (*NFI_PSTA & STATUS_CMD);	
  #endif // defined(__NFI_VERSION3_1__)
	NFI_OP_RESET();
  *NFI_CMD = 0x19;
  #if defined(__NFI_VERSION3_1__)
   	while ((*NFI_STA) & STA_CMD_STATE);
  #else // defined(__NFI_VERSION3_1__)   
    while (*NFI_PSTA & STATUS_CMD);
  #endif // defined(__NFI_VERSION3_1__)
  NFI_OP_RESET();
  
  // 1. Config OTP necessary parameter
 	Cmd_info.buff = BufferPtr;
  Cmd_info.buff_len = Flash_Info.pageSize;
  Cmd_info.spare = SparePtr;
  Cmd_info.ECCFlag = ECC_WHOLE;
  #if defined(__NFI_VERSION3_1__)
    Cmd_info.spare_len = PAGEFMT_FDM_DEFAULT;
    Cmd_info.CustomMode = 1;
  	Cmd_info.add[0] = 0; 	// Colume address
    Cmd_info.add[1] = Hynix_OTP_Page[PageAddr]; 	// Row address
    *NFI_CNFG = CNFG_OP_CUST | CNFG_AUTO_FMT_EN;
    *NFI_CON = (Flash_Info.pageSize >> 9) << CON_NFI_SEC_SHIFT;        
	#else // defined(__NFI_VERSION3_1__)
    Cmd_info.spare_len = Flash_Info.spareSize;
    if (Flash_Info.pageSize == 512)
    {
        Cmd_info.add[0] = Hynix_OTP_Page[PageAddr]<<8 ;
    }
    else
    {
        Cmd_info.add[0] = Hynix_OTP_Page[PageAddr]<<16 ;
        Cmd_info.add[1] = Hynix_OTP_Page[PageAddr]>>16 ;
    }    
	#endif // defined(__NFI_VERSION3_1__)
  
  Cmd_info.intFlag = 0;
  Cmd_info.add_cycle = Flash_Info.deviceInfo_CE[0].address_cycle; 
  
	if (accesstype==FS_OTP_READ)
	{		
	  #if defined(__NFI_VERSION3_1__)
   	*NFI_CNFG |= CNFG_READ_EN;
	  #endif // defined(__NFI_VERSION3_1__)

        if (Flash_Info.pageSize == 512)
        {
            Cmd_info.cmd_len = 1;
            send_command_add(0x00, 0, &Cmd_info);
        }
        else
        {
            Cmd_info.cmd_len = 2;
            send_command_add(0x00, 0x30, &Cmd_info);
        }
#if defined(__NFI_VERSION3_1__)
        *NFI_CNRNB = STROBE_TIMEOUT;
        while( !(*NFI_STA & STA_NAND_BUSY_RETURN) );/*check device busy status*/
#else
				{
					kal_uint32 Delay;
    	  	// 200ns delay maximum.
	      	for (Delay=0; Delay<COUNTER_200nS; Delay++){
						#if defined(__MTK_TARGET__)
							#if defined(__ARMCC_VERSION)
								__asm{nop};
							#elif defined(__GNUC__) 
								__asm__("nop");
							#endif /* __RVCT__ , __GNUC__ */ 
						#endif /* __MTK_TARGET__ */
  	    	}								
  	    }
        while (*NFI_PSTA & STATUS_BUSY);  /*check device busy status*/
        NFI_OP_RESET();        
#endif               
       retVal = readfifo(&Cmd_info);
       if (retVal == MTD_STATUS_ERROR)
       {
            nAND_RESET();            
            //dErrorCode = FS_FLASH_OTP_UNKNOWERR;// Error handling is processed by Caller
       }
	}
	else if (accesstype==FS_OTP_WRITE)
	{	    
	  #if (defined __UBL__)||(defined __FUE__)
	  #else
	  kal_uint32 event_group;
		if (nfi_egid && use_interrupt == KAL_TRUE) {
		    Cmd_info.intFlag = BUSY_RETURN_EN;
		}		
		#endif
	  #if defined(__NFI_VERSION3_1__)
	   	*NFI_CNFG &= ~CNFG_READ_EN;
	  #endif // defined(__NFI_VERSION3_1__)    		
		Cmd_info.cmd_len = 2;
		send_command_add_data(0x80, 0x10, &Cmd_info);
    #if (defined __UBL__)||(defined __FUE__)
    #else
	    if (nfi_egid && use_interrupt == KAL_TRUE)
	    {
	        kal_retrieve_eg_events(nfi_egid, NFI_EVENT, KAL_OR_CONSUME,
	                               &event_group, KAL_SUSPEND);
	    }
		#endif	    
			#if defined(__NFI_VERSION3_1__)
      while( !(*NFI_STA & STA_NAND_BUSY_RETURN) );/*check device busy status*/
			#else
			{
				kal_uint32 Delay;
    		// 200ns delay maximum.
	    	for (Delay=0; Delay<COUNTER_200nS; Delay++){
					#if defined(__MTK_TARGET__)
						#if defined(__ARMCC_VERSION)
							__asm{nop};
						#elif defined(__GNUC__) 
							__asm__("nop");
						#endif /* __RVCT__ , __GNUC__ */ 
					#endif /* __MTK_TARGET__ */
	    	}								
      	while (*NFI_PSTA & STATUS_BUSY);  /*check device busy status*/
      }
			#endif               

	}

	nAND_RESET();	// Reset command will have NAND back to normal mode.
	NFI_OP_RESET();

	pdn_nfi(KAL_FALSE);

	return dErrorCode;	
}

kal_int32 hynix_OTPQueryLength(kal_uint32 *Length)
{
	*Length = HYNIX_OTP_PAGE_NUM * Flash_Info.pageSize;
	return FS_NO_ERROR;
}
kal_int32  ESMT_OTPAccess(kal_int32 accesstype, kal_uint32 PageAddr, void *BufferPtr, void *SparePtr)
{
	kal_uint32 dErrorCode = FS_NO_ERROR;
	kal_uint32 retVal;
	kal_uint16 nfi_pagefmt;
	
	if (PageAddr >= ESMT_OTP_PAGE_NUM) {
		return FS_FLASH_OTP_OVERSCOPE;
	}

	if ( (accesstype!=FS_OTP_READ) && (accesstype!=FS_OTP_WRITE) ) {
		return FS_NO_ERROR;
	}

	pdn_nfi(KAL_TRUE);
  #if (defined __UBL__)||(defined __FUE__)
  #else	
	if (! (nfi_egid && use_interrupt == KAL_TRUE) )
	{
	    if(nfi_egid && (kal_query_systemInit() == KAL_FALSE && INT_QueryExceptionStatus() == KAL_FALSE))
	        use_interrupt = KAL_TRUE;
	}
	#endif
	pagefmt_config(Flash_Info.deviceInfo_CE[0].IOWidth, Flash_Info.pageSize, Flash_Info.spareSize);

  SET_NFI_CS0;

  // 0.Switch to OTP mode
  // sequence is CMD-0xEF-->Addr 0x90--> Data 0x01
	NFI_OP_RESET();
  #if defined(__NFI_VERSION3_1__)
    *NFI_CNFG = (CNFG_OP_CUST|BYTE_RW_EN);
    *NFI_CMD = 0xEF;      
   	while ((*NFI_STA) & STA_CMD_STATE);
  #else // defined(__NFI_VERSION3_1__)
    *NFI_CMD = 0xEF;
    while (*NFI_PSTA & STATUS_CMD);	
  #endif // defined(__NFI_VERSION3_1__)
	

  #if defined(__NFI_VERSION3_1__)
  	*NFI_COLADDR = 0x90;
	  *NFI_ADDRNOB = 1;
   	while ((*NFI_STA) & STA_ADDR_STATE);
  #else // defined(__NFI_VERSION3_1__)
  	*NFI_ADDRL = 0x90;
    *NFI_ADDNOB = 1;
  	while (*NFI_PSTA & STATUS_ADDR);
  #endif // defined(__NFI_VERSION3_1__)  
  
	#if defined(__NFI_VERSION3_1__)
 	 nfi_pagefmt = *NFI_PAGEFMT;
   *NFI_PAGEFMT = PAGEFMT_512_8BIT;   
   *NFI_CON = (0x1000|CON_NFI_BWR); // set burst write
   	 
	 *NFI_STRDATA = 1;
	 while( !FIFO_PIO_READY(*NFI_PIO_DIRDY) );
   *NFI_DATAW = 0x01;
   while (!(*NFI_FIFOSTA & FIFO_WR_EMPTY));

   *NFI_PAGEFMT =  nfi_pagefmt ;   
    NFI_OP_RESET();    	
	#else
 	 nfi_pagefmt = *NFI_PAGEFMT;
   *NFI_PAGEFMT = PAGEFMT_512_8BIT;
	 *NFI_CON = BYTE_RW_EN;
	 *NFI_OPCON = BURST_WR;  
	 while (*NFI_FIFOSTA & WR_FULL_MASK);
   *NFI_DATAWB = 0x01;        
   while (!(*NFI_FIFOSTA & WR_EMPTY_MASK));

   *NFI_PAGEFMT =  nfi_pagefmt ;   
   NFI_OP_RESET();          
  #endif
  
  // 1. Config OTP necessary parameter
 	Cmd_info.buff = BufferPtr;
  Cmd_info.buff_len = Flash_Info.pageSize;
  Cmd_info.spare = SparePtr;
  Cmd_info.ECCFlag = ECC_WHOLE;
  #if defined(__NFI_VERSION3_1__)
    Cmd_info.spare_len = PAGEFMT_FDM_DEFAULT;
    Cmd_info.CustomMode = 1;
  	Cmd_info.add[0] = 0; 	// Colume address
    Cmd_info.add[1] = ESMT_OTP_Page[PageAddr]; 	// Row address
    *NFI_CNFG = CNFG_OP_CUST | CNFG_AUTO_FMT_EN;
    *NFI_CON = (Flash_Info.pageSize >> 9) << CON_NFI_SEC_SHIFT;        
	#else // defined(__NFI_VERSION3_1__)
    Cmd_info.spare_len = Flash_Info.spareSize;
    if (Flash_Info.pageSize == 512)
    {
        Cmd_info.add[0] = ESMT_OTP_Page[PageAddr]<<8 ;
    }
    else
    {
        Cmd_info.add[0] = ESMT_OTP_Page[PageAddr]<<16 ;
        Cmd_info.add[1] = ESMT_OTP_Page[PageAddr]>>16 ;
    }    
	#endif // defined(__NFI_VERSION3_1__)
  
  Cmd_info.intFlag = 0;
  Cmd_info.add_cycle = Flash_Info.deviceInfo_CE[0].address_cycle; 
  
	if (accesstype==FS_OTP_READ)
	{		
	  #if defined(__NFI_VERSION3_1__)
   	*NFI_CNFG |= CNFG_READ_EN;
	  #endif // defined(__NFI_VERSION3_1__)

        if (Flash_Info.pageSize == 512)
        {
            Cmd_info.cmd_len = 1;
            send_command_add(0x00, 0, &Cmd_info);
        }
        else
        {
            Cmd_info.cmd_len = 2;
            send_command_add(0x00, 0x30, &Cmd_info);
        }
#if defined(__NFI_VERSION3_1__)
        *NFI_CNRNB = STROBE_TIMEOUT;
        while( !(*NFI_STA & STA_NAND_BUSY_RETURN) );/*check device busy status*/
#else
				{
					kal_uint32 Delay;
    	  	// 200ns delay maximum.
	      	for (Delay=0; Delay<COUNTER_200nS; Delay++){
						#if defined(__MTK_TARGET__)
							#if defined(__ARMCC_VERSION)
								__asm{nop};
							#elif defined(__GNUC__) 
								__asm__("nop");
							#endif /* __RVCT__ , __GNUC__ */ 
						#endif /* __MTK_TARGET__ */
  	    	}								
  	    }
        while (*NFI_PSTA & STATUS_BUSY);  /*check device busy status*/
        NFI_OP_RESET();        
#endif               
       retVal = readfifo(&Cmd_info);
       if (retVal == MTD_STATUS_ERROR)
       {
            nAND_RESET();            
            //dErrorCode = FS_FLASH_OTP_UNKNOWERR;// Error handling is processed by Caller
       }
	}
	else if (accesstype==FS_OTP_WRITE)
	{	    
	  #if (defined __UBL__)||(defined __FUE__)
	  #else
	  kal_uint32 event_group;
		if (nfi_egid && use_interrupt == KAL_TRUE) {
		    Cmd_info.intFlag = BUSY_RETURN_EN;
		}		
		#endif
	  #if defined(__NFI_VERSION3_1__)
	   	*NFI_CNFG &= ~CNFG_READ_EN;
	  #endif // defined(__NFI_VERSION3_1__)    		
		Cmd_info.cmd_len = 2;
		send_command_add_data(0x80, 0x10, &Cmd_info);
    #if (defined __UBL__)||(defined __FUE__)
    #else
	    if (nfi_egid && use_interrupt == KAL_TRUE)
	    {
	        kal_retrieve_eg_events(nfi_egid, NFI_EVENT, KAL_OR_CONSUME,
	                               &event_group, KAL_SUSPEND);
	    }
		#endif	    
			#if defined(__NFI_VERSION3_1__)
      while( !(*NFI_STA & STA_NAND_BUSY_RETURN) );/*check device busy status*/
			#else
			{
				kal_uint32 Delay;
    		// 200ns delay maximum.
	    	for (Delay=0; Delay<COUNTER_200nS; Delay++){
					#if defined(__MTK_TARGET__)
						#if defined(__ARMCC_VERSION)
							__asm{nop};
						#elif defined(__GNUC__) 
							__asm__("nop");
						#endif /* __RVCT__ , __GNUC__ */ 
					#endif /* __MTK_TARGET__ */
	    	}								
      	while (*NFI_PSTA & STATUS_BUSY);  /*check device busy status*/
      }
			#endif               

	}
 // Leave OTP mode
  // sequence is CMD-0xEF-->Addr 0x90--> Data 0x00
	NFI_OP_RESET();
  
  #if defined(__NFI_VERSION3_1__)
    *NFI_CNFG = (CNFG_OP_CUST|BYTE_RW_EN);
    *NFI_CMD = 0xEF;
   	while ((*NFI_STA) & STA_CMD_STATE);
  #else // defined(__NFI_VERSION3_1__)
    *NFI_CMD = 0xEF;
    while (*NFI_PSTA & STATUS_CMD);	
  #endif // defined(__NFI_VERSION3_1__)
	

  #if defined(__NFI_VERSION3_1__)
  	*NFI_COLADDR = 0x90;
	  *NFI_ADDRNOB = 1;
   	while ((*NFI_STA) & STA_ADDR_STATE);
  #else // defined(__NFI_VERSION3_1__)
  	*NFI_ADDRL = 0x90;
    *NFI_ADDNOB = 1;
  	while (*NFI_PSTA & STATUS_ADDR);
  #endif // defined(__NFI_VERSION3_1__)  

	#if defined(__NFI_VERSION3_1__)
 	 nfi_pagefmt = *NFI_PAGEFMT;
   *NFI_PAGEFMT = PAGEFMT_512_8BIT;   
   *NFI_CON = (0x1000|CON_NFI_BWR); // set burst write

	 *NFI_STRDATA = 1;
	 while( !FIFO_PIO_READY(*NFI_PIO_DIRDY) );
   *NFI_DATAW = 0x00;
   while (!(*NFI_FIFOSTA & FIFO_WR_EMPTY));

   *NFI_PAGEFMT =  nfi_pagefmt ;   
    NFI_OP_RESET();    	
	#else
 	 nfi_pagefmt = *NFI_PAGEFMT;
   *NFI_PAGEFMT = PAGEFMT_512_8BIT;
	 *NFI_CON = BYTE_RW_EN;
	 *NFI_OPCON = BURST_WR;  
	 while (*NFI_FIFOSTA & WR_FULL_MASK);
   *NFI_DATAWB = 0x00;        
   while (!(*NFI_FIFOSTA & WR_EMPTY_MASK));

   *NFI_PAGEFMT =  nfi_pagefmt ;   
   NFI_OP_RESET();          
  #endif 
	nAND_RESET();	// Reset command will have NAND back to normal mode.
	NFI_OP_RESET();

	pdn_nfi(KAL_FALSE);

	return dErrorCode;	
}

kal_int32 ESMT_OTPQueryLength(kal_uint32 *Length)
{
	*Length = ESMT_OTP_PAGE_NUM * Flash_Info.pageSize;
	return FS_NO_ERROR;
}
#define MICRON_OTP_PAGE_NUM 		30
#define MICRON_OTP_PAGE_size		2048

//static const kal_uint32 Samsung_OTP_Page[SAMSUNG_OTP_PAGE_NUM] = {0x15, 0x16, 0x17, 0x18, 0x19, 0x1b};
#define MICRON_SET_FEATURES_CMD 		0xEF
#define MICRON_GET_FEATURES_CMD 		0xEE

#define MICRON_OPERATION_MODE_ADDR 		0x90
#define MICRON_OTP_OPERATION_MODE 		0x00000001
#define MICRON_NORMAL_MODE 				0x00000000

//Micron OTP Page address: 0x02 - 0x1f ,total 30pages
#define MICRON_OTP_PAGEOFFSET 			0x02

#if defined(__NFI_VERSION3_1__)
static void micron_set_features(kal_uint8 feature_address,kal_uint32 method)
{
	kal_uint32  i;
	kal_uint16  nfi_pagefmt;

	kal_uint8 *data = (kal_uint8 *)&method; //enter OTP mode parameters.
	NFI_OP_RESET();
	*NFI_CON = (1 << CON_NFI_SEC_SHIFT);
  *NFI_CNFG = CNFG_OP_CUST|CNFG_BYTE_RW;

	// always use 8bits I/O interface to read device id
	nfi_pagefmt = *NFI_PAGEFMT;
	*NFI_PAGEFMT = PAGEFMT_512_8BIT;

	*NFI_CMD = MICRON_SET_FEATURES_CMD;
	while ((*NFI_STA) & STA_CMD_STATE);

	*NFI_ROWADDR = 0x0;
	*NFI_COLADDR = 0x90;
	*NFI_ADDRNOB = 0x1;

	while ((*NFI_STA) & STA_ADDR_STATE);

	// 5. set NFI_CON
	// set burst program by DWORD
	*NFI_CON |= CON_NFI_BWR ;
	*NFI_STRDATA = 1;
	for(i=0;i<4;i++)
	{
		 while( !FIFO_PIO_READY(*NFI_PIO_DIRDY) );
		 *NFI_DATAW = data[i];
	}
	while(*NFI_ADDRCNTR!=4);
	// wait flash ready
	*NFI_CNRNB = STROBE_TIMEOUT;
	while( !(*NFI_STA & STA_NAND_BUSY_RETURN) );/*check device busy status*/


	*NFI_PAGEFMT = nfi_pagefmt;
	NFI_OP_RESET();
	return;
}

static kal_uint32 micron_get_features(kal_uint8 feature_address)
{
	kal_uint16 nfi_pagefmt;
	kal_uint32 data;
	NFI_OP_RESET();
	*NFI_CNFG = CNFG_OP_SRD | CNFG_READ_EN;;

	// always use 8bits I/O interface to read device id
	nfi_pagefmt = *NFI_PAGEFMT;
	*NFI_PAGEFMT = PAGEFMT_512_8BIT;

	*NFI_CMD = MICRON_GET_FEATURES_CMD;
	while ((*NFI_STA) & STA_CMD_STATE);


	*NFI_ROWADDR = 0;
	*NFI_COLADDR = feature_address;
	*NFI_ADDRNOB = 1;


	while ((*NFI_STA) & STA_ADDR_STATE);
  // wait flash ready
  *NFI_CNRNB = STROBE_TIMEOUT;
  while( !(*NFI_STA & STA_NAND_BUSY_RETURN) );/*check device busy status*/

	*NFI_CON = (4 << CON_NFI_NOB_SHIFT)|CON_NFI_SRD;



	while( !FIFO_PIO_READY(*NFI_PIO_DIRDY) );
	data = *NFI_DATAR;

	*NFI_PAGEFMT = nfi_pagefmt;

	NFI_OP_RESET();
	return data;
}
#else
static void micron_set_features(kal_uint8 feature_address,kal_uint32 method)
{
	// TODO: Not support
}
static kal_uint32 micron_get_features(kal_uint8 feature_address)
{
  // TODO: Not support
}
#endif

kal_int32  micron_OTPAccess(kal_int32 accesstype, kal_uint32 PageAddr, void *BufferPtr, void *SparePtr)
{
	kal_uint32 dErrorCode = FS_NO_ERROR;
	kal_uint32 retVal;
	kal_uint32 feature;

	if (PageAddr >= MICRON_OTP_PAGE_NUM) {
		return FS_FLASH_OTP_OVERSCOPE;
	}

	if ( (accesstype!=FS_OTP_READ) && (accesstype!=FS_OTP_WRITE) ) {
		return FS_NO_ERROR;
	}

	pdn_nfi(KAL_TRUE);
	#if (defined __UBL__)||(defined __FUE__)
	#else	
	if (! (nfi_egid && use_interrupt == KAL_TRUE) )
	{
		if(nfi_egid && (kal_query_systemInit() == KAL_FALSE && INT_QueryExceptionStatus() == KAL_FALSE))
			use_interrupt = KAL_TRUE;
	}
	#endif
	if (Flash_Info.deviceInfo_CE[0].IOWidth == 8)
	{
		if (Flash_Info.pageSize == 512)
		{
#if defined(__NFI_VERSION3_1__)
			*NFI_PAGEFMT = PAGEFMT_512_8BIT | PAGEFMT_FDM_ECC_SETTING;
#else
			*NFI_PAGEFMT = PAGEFMT_512_8BIT;
#endif
		}
		else if (Flash_Info.pageSize == 2048)
		{
#if defined(__NFI_VERSION3_1__)
			*NFI_PAGEFMT = PAGEFMT_2K_8BIT | PAGEFMT_FDM_ECC_SETTING;
#else
			*NFI_PAGEFMT = PAGEFMT_2K_8BIT;
#endif
		}
#if defined(__NFI_VERSION3_1__)
		else if (Flash_Info.pageSize == 4096)
		{
				*NFI_PAGEFMT = PAGEFMT_4K_8BIT | PAGEFMT_FDM_ECC_SETTING;
		}
#endif
	}
	else /* Flash_Info.deviceInfo_CE[0].IOWidth == 16*/
	{
		if (Flash_Info.pageSize == 512)
		{
#if defined(__NFI_VERSION3_1__)
			*NFI_PAGEFMT = PAGEFMT_512_16BIT | PAGEFMT_FDM_ECC_SETTING;
#else
			*NFI_PAGEFMT = PAGEFMT_512_16BIT;
#endif
		}
		else if (Flash_Info.pageSize == 2048)
		{
#if defined(__NFI_VERSION3_1__)
			*NFI_PAGEFMT = PAGEFMT_2K_16BIT | PAGEFMT_FDM_ECC_SETTING;
#else
			*NFI_PAGEFMT = PAGEFMT_2K_16BIT;
#endif
		}
#if defined(__NFI_VERSION3_1__)
	  else if (Flash_Info.pageSize == 4096)
	  {
		  *NFI_PAGEFMT = PAGEFMT_4K_16BIT | PAGEFMT_FDM_ECC_SETTING;
	  }
#endif
    #if ((defined(MT6228)) || (defined(MT6229)) || (defined(MT6230)))
			*NFI_GPIO_DATA1 &= 0x0FFF;
			*NFI_GPIO_DATA2 &= 0xF000;
    #endif
	}


   // 0. Switch to OTP mode
	SET_NFI_CS0;
	micron_set_features(MICRON_OPERATION_MODE_ADDR,MICRON_OTP_OPERATION_MODE);


//check set feature is or not OK. if not, ASSERT!!!
	feature = micron_get_features(MICRON_OPERATION_MODE_ADDR);
	if(MICRON_OTP_OPERATION_MODE != (feature&0xff))
		force_ASSERT(0, accesstype, PageAddr, feature);
	NFI_OP_RESET();

// 1. Config OTP necessary parameter
	Cmd_info.buff = BufferPtr;
	Cmd_info.buff_len = Flash_Info.pageSize;
	Cmd_info.spare = SparePtr;
	Cmd_info.ECCFlag = ECC_WHOLE;

#if defined(__NFI_VERSION3_1__)
	Cmd_info.spare_len = PAGEFMT_FDM_DEFAULT;
	Cmd_info.CustomMode = 1;
	Cmd_info.add[0] = 0;// Colume address
	Cmd_info.add[1] = PageAddr+MICRON_OTP_PAGEOFFSET; 	// Row address
	*NFI_CNFG = CNFG_OP_CUST | CNFG_AUTO_FMT_EN;
	*NFI_CON = (Flash_Info.pageSize >> 9) << CON_NFI_SEC_SHIFT;
#else // defined(__NFI_VERSION3_1__)
	Cmd_info.spare_len = Flash_Info.spareSize;
	if (Flash_Info.pageSize == 512)
	{
	Cmd_info.add[0] = Samsung_OTP_Page[PageAddr]<<8 ;
	}
	else
	{
	Cmd_info.add[0] = Samsung_OTP_Page[PageAddr]<<16 ;
	Cmd_info.add[1] = Samsung_OTP_Page[PageAddr]>>16 ;
	}
#endif // defined(__NFI_VERSION3_1__)

	Cmd_info.intFlag = 0;
	Cmd_info.add_cycle = Flash_Info.deviceInfo_CE[0].address_cycle;

	if (accesstype==FS_OTP_READ)
	{
    #if defined(__NFI_VERSION3_1__)
		*NFI_CNFG |= CNFG_READ_EN;
    #endif // defined(__NFI_VERSION3_1__)

		if (Flash_Info.pageSize == 512)
		{
			Cmd_info.cmd_len = 1;
			send_command_add(0x00, 0, &Cmd_info);
		}
		else
		{
			Cmd_info.cmd_len = 2;
			send_command_add(0x00, 0x30, &Cmd_info);
		}

#if defined(__NFI_VERSION3_1__)
		*NFI_CNRNB = STROBE_TIMEOUT;
		while( !(*NFI_STA & STA_NAND_BUSY_RETURN) );/*check device busy status*/
#else
			{
				kal_uint32 Delay;
      	// 200ns delay maximum.
  	    for (Delay=0; Delay<COUNTER_200nS; Delay++){
					#if defined(__MTK_TARGET__)
						#if defined(__ARMCC_VERSION)
							__asm{nop};
						#elif defined(__GNUC__)
							__asm__("nop");
						#endif /* __RVCT__ , __GNUC__ */
					#endif /* __MTK_TARGET__ */
	      }
	    }
        while (*NFI_PSTA & STATUS_BUSY);  /*check device busy status*/
        NFI_OP_RESET();
#endif
	   retVal = readfifo(&Cmd_info);
	   if (retVal == MTD_STATUS_ERROR)
       {
			nAND_RESET();
            //dErrorCode = FS_FLASH_OTP_UNKNOWERR;// Error handling is processed by Caller
	   }
	}
	else if (accesstype==FS_OTP_WRITE)
	{
		#if (defined __UBL__) || (defined __FUE__) 
		#else
    	kal_uint32 event_group;    
    #endif
    #if defined(__NFI_VERSION3_1__)
		*NFI_CNFG &= ~CNFG_READ_EN;
    #endif // defined(__NFI_VERSION3_1__)

  #if (defined __UBL__)||(defined __FUE__)
  #else
	if (nfi_egid && use_interrupt == KAL_TRUE) {
	Cmd_info.intFlag = BUSY_RETURN_EN;
	}
	#endif
	Cmd_info.cmd_len = 2;
	send_command_add_data(0x80, 0x10, &Cmd_info);

  #if (defined __UBL__)||(defined __FUE__)
  #else
	if (nfi_egid && use_interrupt == KAL_TRUE)
	{
		kal_retrieve_eg_events(nfi_egid, NFI_EVENT, KAL_OR_CONSUME,
		&event_group, KAL_SUSPEND);
	}
	#endif
#if defined(__NFI_VERSION3_1__)
	while( !(*NFI_STA & STA_NAND_BUSY_RETURN) );/*check device busy status*/
#else
	{
		kal_uint32 Delay;
		// 200ns delay maximum.
		for (Delay=0; Delay<COUNTER_200nS; Delay++){
				#if defined(__MTK_TARGET__)
					#if defined(__ARMCC_VERSION)
						__asm{nop};
					#elif defined(__GNUC__)
						__asm__("nop");
					#endif /* __RVCT__ , __GNUC__ */
				#endif /* __MTK_TARGET__ */
		}
	}
	while (*NFI_PSTA & STATUS_BUSY);	/*check device busy status*/
#endif
	}

//GO back to normal mode
	micron_set_features(MICRON_OPERATION_MODE_ADDR,MICRON_NORMAL_MODE);

	nAND_RESET();	// Reset command will have NAND back to normal mode.
	NFI_OP_RESET();

//check set feature is or not OK. if not, ASSERT!!!
	feature = micron_get_features(MICRON_OPERATION_MODE_ADDR);
	if(MICRON_NORMAL_MODE != (feature&0xff))
		force_ASSERT(0, accesstype, PageAddr, feature);
	NFI_OP_RESET();

	pdn_nfi(KAL_FALSE);

	return dErrorCode;
}

kal_int32 micron_OTPQueryLength(kal_uint32 *Length)
{
	*Length = MICRON_OTP_PAGE_size*MICRON_OTP_PAGE_NUM;

	return FS_NO_ERROR;
}

/*******************************************************************************
 *  MTD functions
 *******************************************************************************/

#if defined(FLASH_DISKDRV_DEBUG) && !defined(__MTK_TARGET__)

#ifdef __NAND_LMT__

extern char ReadBackImage[2][100];

void MTD_LMT_Open_Device_File(void)
{
	int i;
    for ( i = 0; i < 2 && (Flash_Info.valid_CE[i] == KAL_TRUE); i++)
    {
		file_name[i] = ReadBackImage[i];
        file_hd[i] = fopen(file_name[i], "rb+"); /*for read and update (not allow append)*/
    }
}

#else // __NAND_LMT__

void MTD_Simu_Create_Device_File (void)
{
    int i, j, k;
    kal_uint32 devSize;
    #if 1
    file_name[0] = ".\\NANDflash_device0.img";
    file_name[1] = ".\\NANDflash_device1.img";
    #else
/* under construction !*/
/* under construction !*/
    #endif
    kal_mem_set(MTD_simu_buff, 0xFF, sizeof(MTD_simu_buff));
    for ( i = 0; i < 2 && (Flash_Info.valid_CE[i] == KAL_TRUE); i++)
    {
        devSize = Flash_Info.deviceInfo_CE[i].deviceSize*1024*1024;
        devSize = (Flash_Info.deviceInfo_CE[i].supportMPType& EXTENDED_BLOCK) == EXTENDED_BLOCK ? devSize/1024*(1024+16) : devSize;
        if( (file_hd[i] = fopen(file_name[i], "rb+")) == NULL )
        {
           // it doesn't exist
           file_hd[i] = fopen(file_name[i], "wb+");
           for (j=0;j < devSize/Flash_Info.deviceInfo_CE[i].pageSize; j++ )
           {
               fwrite(MTD_simu_buff, sizeof(char), (Flash_Info.deviceInfo_CE[i].pageSize+Flash_Info.deviceInfo_CE[i].spareSize), file_hd[i]);
           }
        }
        else
        {
           long file_size = 0;
           fseek(file_hd[i], 0, SEEK_END);
           file_size = ftell(file_hd[i]);

           if (file_size != devSize/Flash_Info.deviceInfo_CE[i].pageSize*(Flash_Info.deviceInfo_CE[i].pageSize+Flash_Info.deviceInfo_CE[i].spareSize) )
           {
              fseek(file_hd[i], 0, SEEK_SET);
              fclose(file_hd[i]);
              // truncate the file
              file_hd[i] = fopen(file_name[i], "wb");
              fclose(file_hd[i]);
              // reopen
              file_hd[i] = fopen(file_name[i], "wb+");
              for (j=0;j < devSize/Flash_Info.deviceInfo_CE[i].pageSize; j++ )
              {
                  fwrite(MTD_simu_buff, sizeof(char), (Flash_Info.deviceInfo_CE[i].pageSize+Flash_Info.deviceInfo_CE[i].spareSize), file_hd[i]);
              }
           }

           fseek(file_hd[i], 0, SEEK_END);
           if( 0 == ftell(file_hd[i]) )
           {
               for (j=0;j < devSize/Flash_Info.deviceInfo_CE[i].pageSize; j++ )
               {
                   fwrite(MTD_simu_buff, sizeof(char), (Flash_Info.deviceInfo_CE[i].pageSize+Flash_Info.deviceInfo_CE[i].spareSize), file_hd[i]);
               }
           }
        }
        fflush(file_hd[i]);
        fclose(file_hd[i]);
        file_hd[i] = fopen(file_name[i], "rb+"); /*for read and update (not allow append)*/
    }
}

#endif // __NAND_LMT__

void MTD_Simu_SetUserDefID(kal_uint32 cs0_ID_0_3,kal_uint32 cs0_ID_4_7,kal_uint32 cs1_ID_0_3,kal_uint32 cs1_ID_4_7)
{
    user_def_cs_num = 2;
    user_def_id_data[0][0] = cs0_ID_0_3;
    user_def_id_data[0][1] = cs0_ID_4_7;
    user_def_id_data[1][0] = cs1_ID_0_3;
    user_def_id_data[1][1] = cs1_ID_4_7;
}

void MTD_Simu_SetIDData(kal_uint32* id_data,kal_uint8 cs)
{
    id_data[0] = user_def_id_data[cs][0];
    id_data[1] = user_def_id_data[cs][1];
}


#if defined DAL_DLL_VERSION
void MTD_WriteErrMsg(char* title, char* exp, char* f, kal_uint32 line, kal_uint32 e1, kal_uint32 e2, kal_uint32 e3)
{
    //char msg[128];
    char* file_name;
    void* file_hd = NULL;

    file_name = ".\\ErrMsg.txt";

    if( (file_hd = fopen(file_name, "a+")) != NULL )
    {
        fprintf(file_hd,"%s file:%s line:%d expr:%s e1:%d e2:%d e3:%d\r\n",title,f,line,exp,e1,e2,e3);

        fclose(file_hd);
    }
}
#endif

#endif

kal_int32 MTD_MountDevice( void)
{
    //NAND_FLASH_DRV_DATA * D = DriveData;
    kal_int32 check_value = 0;


#if !defined(__NFI_VERSION2__) && !defined(__NFI_VERSION3_1__)
    if(SuperAND_MTD_MountDevice(DriveData) == MTD_STATUS_NO_ERROR)
    {
        SuperAND_MTD_Init();
        return SUPERAND_MOUNTED;
    }
#endif

    pdn_nfi(KAL_TRUE);

    #if defined(FLASH_DISKDRV_DEBUG) && !defined(__MTK_TARGET__)
    CS_num = NFI_GPIO_Setting();
    #else
    if(!is_initialized)
    {
    /* set NFI conrol bin in GPIO
     * it should be consistent with GPIO_init() of custom\drv\misc_drv\XXX\gpio_drv.c
     */
        CS_num = NFI_GPIO_Setting();
    #if defined(__NFI_VERSION2__) || defined(__NFI_VERSION3_1__)
	    #if (defined (MT6268A) || defined (MT6268) || defined (MT6270A) || defined (TK6280)  || defined(MT6276)|| defined(MT6573)|| defined(MT6575)|| defined(MT6577))	    
		*NFI_ACCCON = 0x20023334;
		#elif defined(MT6280)
		*NFI_ACCCON = 0x30035446;
		#else // (defined (MT6268A) || defined (MT6268) || defined (MT6270A))
        *NFI_ACCCON = 0x20023333;
        #endif // (defined (MT6268A) || defined (MT6268) || defined (MT6270A))
    #else // defined(__NFI_VERSION2__)
        *NFI_ACCCON = ACCCON | (((NFI_W2R<<6)|(NFI_WH<<4)) | ((NFI_WST<<2)|NFI_RLC));
    #endif // defined(__NFI_VERSION2__)

        /* initialize DMA and interrupt*/
    #if defined(__NFI_VERSION2__)
		   // Disable power-down control of DMA
			#ifndef __OLD_PDN_ARCH__
   		PDN_CLR(PDN_DMA);
			#elif defined(MT6235) || defined(MT6235B) 
   		*(volatile kal_uint16 *)(DRVPDN_CON0_CLR) = DRVPDN_CON0_DMA;
			#elif defined(MT6268) || defined(MT6268T)
   		*(volatile kal_uint16 *)(CG_CLR0) = CG_CON0_DMA;
			#endif
    #endif
        *NFI_INTR_EN = 0x0;    // disable interrupt

        #if (defined __UBL__) || (defined __FUE__)
        /*Do not create nfi_egid in boot loader and fota case*/
        #else
        if ( kal_query_boot_mode() != USBMS_BOOT
#if defined(__FUE__)
     		 && (kal_query_boot_mode() != FUE_BOOT )
#endif
       	   )
        {
            nfi_egid = kal_create_event_group("NFI_EG");

            //nfi_hisr_id = kal_create_hisr("NFI_HISR",1,512,nfi_hisr,NULL);
            DRV_Register_HISR(DRV_NFI_HISR_ID, nfi_hisr);

            IRQ_Register_LISR(IRQ_NFI_CODE, nfi_lisr, "NFI_LISR");
            IRQSensitivity(IRQ_NFI_CODE, EDGE_SENSITIVE);
            IRQUnmask(IRQ_NFI_CODE);
        }
        #endif

        #if defined(__NFI_VERSION3_1__)

		*NFI_IOCON = ((*NFI_IOCON) & (kal_uint16)(~BRSTN_MASK)) | BRSTN_DEFAULT;
		*ECC_FDMADDR = (kal_uint32)NFI_FDM0L;

        #else

        nfi_menu.TMOD.burst_mode = KAL_FALSE;
        nfi_menu.master = DMA_NFI;
        nfi_menu.source = NULL;
        nfi_menu.destination = NULL;

        nfi_input.type = DMA_HWTX;
        nfi_input.size = DMA_BYTE;
        nfi_input.menu = &nfi_menu;
        nfi_input.count = 0;
        #if (defined __UBL__)||(defined __FUE__)
        #else
        if (nfi_egid == 0)
        {
            nfi_input.callback = NULL;
        }
        else
				#endif        
        {
            nfi_input.callback = NFI_DMA_Callback;
        }

    	#endif // defined(__NFI_VERSION3_1__)

        // initially set NFI chip select dir and out data
        INITIALIZE_NFI_DIR_DOUT;
    }
    #endif

    NFI_OP_RESET();
    /* use 512-byte page and 8-bit IO format for read ID  */
    *NFI_PAGEFMT = PAGEFMT_512_8BIT;
    check_value = InitializeMTDData( );

    #if defined(__NFI_VERSION2__) || defined(__NFI_VERSION3_1__)
    #if (defined (MT6268A) || defined (MT6268) || defined (MT6270A) || defined (TK6280) || defined (MT6276)|| defined(MT6573)|| defined(MT6575)|| defined(MT6577))    
	  *NFI_ACCCON = 0x20022124;
	  #elif defined(MT6280)
	  *NFI_ACCCON = 0x30033225;
	  #else 
    if (Flash_Info.deviceInfo_CE[0].pageSize == 512) {
    	// Small page.
        *NFI_ACCCON = 0x20022123;
    } else {
    	// Large lage 2KB
        *NFI_ACCCON = 0x20022113;
    }
    #if (defined(__AST2001__)&&defined(__AST_E1__))
    *NFI_ACCCON = 0x20022134;	// Fix AST2001 bug, release WST 2T and read 1T
    #endif // #if (define(__AST2001__)&&defined(__AST_E1__))
    
    #endif	
    #endif  // defined(__NFI_VERSION2__) || defined(__NFI_VERSION3_1__)

    #if defined(__NFI_VERSION2__)
    *NFI_SCON = 0x0008; /*protect 8 bytes of spare area from byte0*/
    #endif // defined(__NFI_VERSION2__)

    #if defined(FLASH_DISKDRV_DEBUG) && !defined(__MTK_TARGET__) && !defined(DAL_DLL_VERSION)

    #ifdef __NAND_LMT__
    MTD_LMT_Open_Device_File();
    #else // __NAND_LMT__
    MTD_Simu_Create_Device_File();
    #endif // __NAND_LMT__

    #endif

    NFI_OP_RESET();
    pdn_nfi(KAL_FALSE);

    if(!is_initialized)
    {
        is_initialized = KAL_TRUE;
    }

    if (check_value == MTD_STATUS_NO_ERROR)
    {
        return FS_NO_ERROR;
    }
    else if( check_value == MTD_STATUS_ID_NOT_SUPPORT )
        return FS_NAND_DEVICE_NOT_SUPPORTED;
    else
        return FS_FLASH_MOUNT_ERROR;
}   /*  End of MountDevice */

/****************************************************************************
 * Function:    MTD_CE_Interleave_Program
 *
 * Parameters:  mtd_drv_para *para
 *
 * Returns:   MTD_STATUS_NO_ERROR   No error
 *            MTD_STATUS_ERROR + index of error page (Low 16 bits)
 * Description:
 *
 ****************************************************************************/
kal_uint32 MTD_CE_Interleave_Program (mtd_if_para* Para)
{
    mtd_drv_para drv_data;
    kal_uint16 page_size;
    kal_uint32 multi_page_num_CE0;
    kal_uint8  m_idx_CE0, m_idx_CE1;
    kal_uint32 failPage;
    kal_uint32 retVal;
    kal_uint8  pre_op_flag;
    /*Para check*/
    //dbg_ASSERT(Para->buff);
    dbg_ASSERT(Para->spare);
    dbg_ASSERT(Para->ce < 2);
    dbg_ASSERT(Para->m_idx < MAX_MULTIPAGE_FUNCTION_NUM);
    dbg_ASSERT( Flash_Info.pageSize%512 == 0 );
    dbg_ASSERT( Para->length <= 16); /*Limited by return value*/

    pdn_nfi(KAL_TRUE);
	  #if (defined __UBL__)||(defined __FUE__)
	  #else    
    if (! (nfi_egid && use_interrupt == KAL_TRUE) )
    {
        if(nfi_egid && (kal_query_systemInit() == KAL_FALSE && INT_QueryExceptionStatus() == KAL_FALSE))
            use_interrupt = KAL_TRUE;
    }
    #endif
    page_size = Flash_Info.pageSize;

	pagefmt_config(Flash_Info.deviceInfo_CE[0].IOWidth, Flash_Info.pageSize, Flash_Info.spareSize);

    dbg_ASSERT( Para->m_idx == Flash_Info.CE_interleave_mOP_Idx[0]);
    m_idx_CE0 = Flash_Info.CE_interleave_mOP_Idx[0];
    m_idx_CE1 = Flash_Info.CE_interleave_mOP_Idx[1];

    multi_page_num_CE0 = Flash_Info.multiProgram [0][m_idx_CE0].multiPageNum;
    //multi_page_num_CE1 = Flash_Info.multiProgram [1][m_idx_CE1].multiPageNum;    
    dbg_ASSERT((multi_page_num_CE0 + Flash_Info.multiProgram [1][m_idx_CE1].multiPageNum) == Para->length);
    pre_op_flag = 0x00; /*NULL*/

    SET_NFI_CS0;
    drv_data.page_p = &Para->pageIdx[0];
    drv_data.pageOffset = 0;
    drv_data.addCycle = Flash_Info.deviceInfo_CE[0].address_cycle;
    drv_data.buff = &Para->buff[0];
    drv_data.spare = &Para->spare[0];
    drv_data.opFlag = pre_op_flag|FIRST_PROCESS;
    if (Para->opFlag & ONE_SPARE) {
	    drv_data.opFlag |= ONE_SPARE;
    }
    retVal = Flash_Info.multiProgram [0][ m_idx_CE0 ].func_p (&drv_data);
    if (retVal != MTD_STATUS_NO_ERROR)
    {
        return retVal;
    }

    SET_NFI_CS1;
    drv_data.page_p = &Para->pageIdx[ Flash_Info.bank_CE[0] ];
    drv_data.pageOffset = 0;
    drv_data.addCycle = Flash_Info.deviceInfo_CE[1].address_cycle;
    drv_data.buff = &Para->buff[0 + (multi_page_num_CE0*page_size)];
    drv_data.opFlag = pre_op_flag|FIRST_PROCESS;
    if (Para->opFlag & ONE_SPARE) {
	    drv_data.spare = &Para->spare[0];
	    drv_data.opFlag |= ONE_SPARE;
    } else {
	    drv_data.spare = &Para->spare[0 + (multi_page_num_CE0*Flash_Info.spareSize)];
    }
    retVal = Flash_Info.multiProgram [1][ m_idx_CE1 ].func_p (&drv_data);
    SET_NFI_CS1_END;
    if (retVal != MTD_STATUS_NO_ERROR)
    {
        failPage = (retVal&0xFFFF);
        retVal = retVal&0xFFFF0000;
        retVal |= failPage << multi_page_num_CE0 ; /*return the bank index*/
        return retVal;
    }

    SET_NFI_CS0;
    drv_data.page_p = &Para->pageIdx[0];
    drv_data.pageOffset = 0;
    drv_data.addCycle = Flash_Info.deviceInfo_CE[0].address_cycle;
    //drv_data.buff = &Para->buff[0 + xxxx ];
    //drv_data.spare = &Para->spare[0 + xxxx ];
    drv_data.opFlag = pre_op_flag|SECOND_BUSY;
    retVal = Flash_Info.multiProgram [0][ m_idx_CE0 ].func_p (&drv_data);
    #if defined DAL_VERIFICATION
    if (Mtd_Fail_Offset != 0xFF)
    { /*test case*/
        if (Mtd_Fail_Offset < multi_page_num_CE0)
            retVal = MTD_STATUS_ERROR|(1<<Mtd_Fail_Offset);
    }
    #endif
    if (retVal != MTD_STATUS_NO_ERROR)
    {
        return retVal;
    }

    SET_NFI_CS1;
    drv_data.page_p = &Para->pageIdx[ Flash_Info.bank_CE[0] ];
    drv_data.pageOffset = 0;
    drv_data.addCycle = Flash_Info.deviceInfo_CE[1].address_cycle;
    //drv_data.buff = &Para->buff[0 + xxxx];
    //drv_data.spare = &Para->spare[0 + xxxx];
    drv_data.opFlag = pre_op_flag|SECOND_BUSY;
    retVal = Flash_Info.multiProgram [1][ m_idx_CE1 ].func_p (&drv_data);
    SET_NFI_CS1_END;
    #if defined DAL_VERIFICATION
    if (Mtd_Fail_Offset != 0xFF)
    { /*test case*/
        if (Mtd_Fail_Offset >= multi_page_num_CE0)
            retVal = MTD_STATUS_ERROR|(1<<(Mtd_Fail_Offset-multi_page_num_CE0));
    }
    #endif
    if (retVal != MTD_STATUS_NO_ERROR)
    {
        failPage = (retVal&0xFFFF);
        retVal = retVal&0xFFFF0000;
        //retVal |= failPage << (drv_data.pageOffset * multi_page_num + multi_page_num_CE0) ;  /*to return the exactly offset of page*/
        retVal |= failPage << multi_page_num_CE0 ; /*return the bank index*/
        return retVal;
    }
    NFI_OP_RESET();
    pdn_nfi(KAL_FALSE);
    return retVal;
}

/****************************************************************************
 * Function:    MTD_CE_Interleave_Program
 *
 * Parameters:  mtd_drv_para *para
 *
 * Returns:   MTD_STATUS_NO_ERROR   No error
 *            MTD_STATUS_ERROR + index of error bank (Low 16 bits)
 * Description: Para->length can large than 16
 *
 ****************************************************************************/
kal_uint32 MTD_CE_Interleave_CacheProgram (mtd_if_para* Para)
{
    mtd_drv_para drv_data;
    kal_uint16 page_size;
    kal_uint16 writenPage;
    kal_uint32 multi_page_num, multi_page_num_CE0, multi_page_num_CE1;
    kal_uint8  m_idx_CE0, m_idx_CE1;
    kal_uint32 failPage;
    kal_uint32 retVal = MTD_STATUS_NO_ERROR;
    kal_uint8  pre_op_flag;
    /*Para check*/
    //dbg_ASSERT(Para->buff);
    dbg_ASSERT(Para->spare);
    dbg_ASSERT(Para->ce < 2);
    dbg_ASSERT(Para->m_idx < MAX_MULTIPAGE_FUNCTION_NUM);
    dbg_ASSERT( Flash_Info.pageSize%512 == 0 );
    //dbg_ASSERT( Para->length <= 16); /*Limited by return value*/

    pdn_nfi(KAL_TRUE);
    #if (defined __UBL__)||(defined __FUE__)
    #else
    if (! (nfi_egid && use_interrupt == KAL_TRUE) )
    {
        if(nfi_egid && (kal_query_systemInit() == KAL_FALSE && INT_QueryExceptionStatus() == KAL_FALSE))
            use_interrupt = KAL_TRUE;
    }
    #endif
    page_size = Flash_Info.pageSize;

	pagefmt_config(Flash_Info.deviceInfo_CE[0].IOWidth, Flash_Info.pageSize, Flash_Info.spareSize);

    /*use cache function*/
    dbg_ASSERT( Para->m_idx == Flash_Info.CE_cache_interleave_mOP_Idx[0]);
    m_idx_CE0 = Flash_Info.CE_cache_interleave_mOP_Idx[0];
    m_idx_CE1 = Flash_Info.CE_cache_interleave_mOP_Idx[1];
    dbg_ASSERT( Flash_Info.multiProgram [0][m_idx_CE0].multiPageNum == 0xFF );
    dbg_ASSERT( Flash_Info.multiProgram [1][m_idx_CE1].multiPageNum == 0xFF );

    multi_page_num_CE0 = Flash_Info.multiProgram [0][m_idx_CE0].startAlign;
    multi_page_num_CE1 = Flash_Info.multiProgram [1][m_idx_CE1].startAlign;
    multi_page_num = multi_page_num_CE0 + multi_page_num_CE1;
    dbg_ASSERT ( Para->length%multi_page_num == 0 );
    pre_op_flag = PROGRAM_CACHED;

    writenPage = 0;
    while (writenPage < Para->length )
    {
        if ( writenPage >= Para->length - multi_page_num )
        {  /*last one*//*cache function*/
            pre_op_flag = PROGRAM_FINAL;
        }
        SET_NFI_CS0;
        drv_data.page_p = &Para->pageIdx[0];
        drv_data.pageOffset = writenPage/multi_page_num;
        drv_data.addCycle = Flash_Info.deviceInfo_CE[0].address_cycle;
        drv_data.buff = &Para->buff[0 + (writenPage*page_size)];
        drv_data.opFlag = pre_op_flag|FIRST_PROCESS;
        if (Para->opFlag & ONE_SPARE) {
	        drv_data.spare = &Para->spare[0];
	        drv_data.opFlag |= ONE_SPARE;
        } else {
	        drv_data.spare = &Para->spare[0 + (writenPage*Flash_Info.spareSize)];
        }
        retVal = Flash_Info.multiProgram [0][ m_idx_CE0 ].func_p (&drv_data);
        if (retVal != MTD_STATUS_NO_ERROR)
        {
            #if 0 /*to return the exactly offset of page*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #endif
            break;
        }

        SET_NFI_CS1;
        drv_data.page_p = &Para->pageIdx[ Flash_Info.bank_CE[0] ];
        drv_data.pageOffset = writenPage/multi_page_num;
        drv_data.addCycle = Flash_Info.deviceInfo_CE[1].address_cycle;
        drv_data.buff = &Para->buff[0 + ((writenPage + multi_page_num_CE0)*page_size)];
        drv_data.opFlag = pre_op_flag|FIRST_PROCESS;
        if (Para->opFlag & ONE_SPARE) {
	        drv_data.spare = &Para->spare[0];
	        drv_data.opFlag |= ONE_SPARE;
        } else {
	        drv_data.spare = &Para->spare[0 + ((writenPage + multi_page_num_CE0)*Flash_Info.spareSize)];
        }
        retVal = Flash_Info.multiProgram [1][ m_idx_CE1 ].func_p (&drv_data);
        SET_NFI_CS1_END;
        if (retVal != MTD_STATUS_NO_ERROR)
        {
            failPage = (retVal&0xFFFF);
            retVal = retVal&0xFFFF0000;
            //retVal |= failPage << (drv_data.pageOffset * multi_page_num + multi_page_num_CE0) ;  /*to return the exactly offset of page*/
            retVal |= failPage << multi_page_num_CE0 ; /*return the bank index*/
            break;
        }

        SET_NFI_CS0;
        drv_data.page_p = &Para->pageIdx[0];
        drv_data.pageOffset = writenPage/multi_page_num;
        drv_data.addCycle = Flash_Info.deviceInfo_CE[0].address_cycle;
        //drv_data.buff = &Para->buff[0 + xxxx ];
        //drv_data.spare = &Para->spare[0 + xxxx ];
        drv_data.opFlag = pre_op_flag|SECOND_BUSY;
        retVal = Flash_Info.multiProgram [0][ m_idx_CE0 ].func_p (&drv_data);
        writenPage +=multi_page_num_CE0;
        if (retVal != MTD_STATUS_NO_ERROR)
        {
            #if 0 /*to return the exactly offset of page*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #endif
            break;
        }

        SET_NFI_CS1;
        drv_data.page_p = &Para->pageIdx[ Flash_Info.bank_CE[0] ];
        drv_data.pageOffset = writenPage/multi_page_num;
        drv_data.addCycle = Flash_Info.deviceInfo_CE[1].address_cycle;
        //drv_data.buff = &Para->buff[0 + xxxx];
        //drv_data.spare = &Para->spare[0 + xxxx];
        drv_data.opFlag = pre_op_flag|SECOND_BUSY;
        retVal = Flash_Info.multiProgram [1][ m_idx_CE1 ].func_p (&drv_data);
        writenPage +=multi_page_num_CE1;
        SET_NFI_CS1_END;
        if (retVal != MTD_STATUS_NO_ERROR)
        {
            failPage = (retVal&0xFFFF);
            retVal = retVal&0xFFFF0000;
            //retVal |= failPage << (drv_data.pageOffset * multi_page_num + multi_page_num_CE0) ;  /*to return the exactly offset of page*/
            retVal |= failPage << multi_page_num_CE0 ; /*return the bank index*/
            break;
        }
    }
    NFI_OP_RESET();
    pdn_nfi(KAL_FALSE);
    return retVal;
}


kal_uint32 MTD_Program (mtd_if_para* Para)
{
    mtd_drv_para drv_data;   
    kal_uint32 retVal;
    /*Para check - Start*/
    //dbg_ASSERT(Para->buff);
    dbg_ASSERT(Para->spare);
    dbg_ASSERT(Para->ce < 2);
    dbg_ASSERT(Para->m_idx < MAX_MULTIPAGE_FUNCTION_NUM);
    dbg_ASSERT( Flash_Info.pageSize%512 == 0 );
    dbg_ASSERT(Flash_Info.multiProgram [(Para->ce)][(Para->m_idx)].multiPageNum == Para->length);
    dbg_ASSERT( Para->length <= 16); /*Limited by return value*/
    /*Para check - End*/
    pdn_nfi(KAL_TRUE);
    #if (defined __UBL__)||(defined __FUE__)
    #else    
    if (! (nfi_egid && use_interrupt == KAL_TRUE) )
    {
        if(nfi_egid && (kal_query_systemInit() == KAL_FALSE && INT_QueryExceptionStatus() == KAL_FALSE))
            use_interrupt = KAL_TRUE;
    }
		#endif
	pagefmt_config(Flash_Info.deviceInfo_CE[0].IOWidth, Flash_Info.pageSize, Flash_Info.spareSize);
	
    if (Para->ce == 0)
    {
        SET_NFI_CS0;
    }
    else
    {
        SET_NFI_CS1;
    }

    drv_data.addCycle = Flash_Info.deviceInfo_CE[ (Para->ce) ].address_cycle;
    drv_data.page_p = &Para->pageIdx[0];
    drv_data.opFlag = FULL_OPERATION;
    drv_data.pageOffset = 0;
    drv_data.buff = &Para->buff[0];
    drv_data.spare = &Para->spare[0];
    if (Para->opFlag & ONE_SPARE) {
    	drv_data.opFlag |= ONE_SPARE;
    }
    retVal = Flash_Info.multiProgram [(Para->ce)][(Para->m_idx) ].func_p (&drv_data);
    #if defined DAL_VERIFICATION
    if (Mtd_Fail_Offset != 0xFF)
    { /*test case*/
        retVal = MTD_STATUS_ERROR|(1<<Mtd_Fail_Offset);
    }
    #endif
    if (Para->ce == 1)
        SET_NFI_CS1_END;

    // Need to add following two lines in order to reset FSM and disassert CS.
    NFI_OP_RESET();

    pdn_nfi(KAL_FALSE);
    return retVal;
}

kal_uint32 MTD_CacheProgram (mtd_if_para* Para)
{
    mtd_drv_para drv_data;
    kal_uint16 writenPage;
    kal_uint32 multi_page_num, failPage;
    kal_uint32 retVal = MTD_STATUS_NO_ERROR;
    /*Para check - Start*/
    //dbg_ASSERT(Para->buff);
    dbg_ASSERT(Para->spare);
    dbg_ASSERT(Para->ce < 2);
    dbg_ASSERT(Para->m_idx < MAX_MULTIPAGE_FUNCTION_NUM);
    dbg_ASSERT( Flash_Info.pageSize%512 == 0 );
    dbg_ASSERT( Para->length <= 16); /*Limited by return value*/
    /*Para check - End*/
    pdn_nfi(KAL_TRUE);
    #if (defined __UBL__)||(defined __FUE__)
    #else    
    if (! (nfi_egid && use_interrupt == KAL_TRUE) )
    {
        if(nfi_egid && (kal_query_systemInit() == KAL_FALSE && INT_QueryExceptionStatus() == KAL_FALSE))
            use_interrupt = KAL_TRUE;
    }
		#endif
	pagefmt_config(Flash_Info.deviceInfo_CE[0].IOWidth, Flash_Info.pageSize, Flash_Info.spareSize);

    if (Para->ce == 0)
    {
        SET_NFI_CS0;
    }
    else
    {
        SET_NFI_CS1;
    }

    drv_data.addCycle = Flash_Info.deviceInfo_CE[ (Para->ce) ].address_cycle;
    drv_data.page_p = &Para->pageIdx[0];
    multi_page_num = Flash_Info.multiProgram [(Para->ce)][(Para->m_idx)].startAlign; /*cache function*/
    drv_data.opFlag = FULL_OPERATION|PROGRAM_CACHED;
    writenPage = 0;
    while (writenPage < Para->length )
    {
        if ( writenPage >= Para->length - multi_page_num )
        {  /*last time*/
            drv_data.opFlag = FULL_OPERATION|PROGRAM_FINAL; /*cache function*/
        }
        drv_data.pageOffset = writenPage/multi_page_num;
        drv_data.buff = &Para->buff[0 + (writenPage*Flash_Info.pageSize)];
        if (Para->opFlag & ONE_SPARE) {
	        drv_data.spare = &Para->spare[0];
	        drv_data.opFlag |= ONE_SPARE;
        } else {
	        drv_data.spare = &Para->spare[0 + (writenPage*Flash_Info.spareSize)];
        }
        retVal = Flash_Info.multiProgram [(Para->ce)][(Para->m_idx) ].func_p (&drv_data);
        if (retVal != MTD_STATUS_NO_ERROR)
        {
            failPage = (retVal&0xFFFF);
            retVal = retVal&0xFFFF0000;
            //retVal |= failPage << (drv_data.pageOffset * multi_page_num) ;
            retVal |= failPage;
            break;
        }
        writenPage += multi_page_num;
    }


    if (Para->ce == 1)
        SET_NFI_CS1_END;

    NFI_OP_RESET();

    pdn_nfi(KAL_FALSE);
    return retVal;
}


kal_uint32 MTD_Read(mtd_if_para* Para)
{
    mtd_drv_para drv_data;
    kal_uint32 retVal;

    /*Para check - Start*/
    #if (defined __UBL__) || (defined __FUE__)
    /*It's possible to read code to 0x0 at bootloader*/
    #else
    force_ASSERT(Para->buff,0,0,0);
    #endif
    //dbg_ASSERT(Para->spare);
    dbg_ASSERT(Para->ce < 2);
    dbg_ASSERT(Para->m_idx < MAX_MULTIPAGE_FUNCTION_NUM);
    dbg_ASSERT( Flash_Info.pageSize%512 == 0 );
    dbg_ASSERT( 1 == Para->length ); /*support single page read only now*/
    dbg_ASSERT( Para->length <= 16); /*Limited by return value*/
    /*Para check - End*/

    pdn_nfi(KAL_TRUE);
	  #if (defined __UBL__)||(defined __FUE__)
	  #else    
    if (! (nfi_egid && use_interrupt == KAL_TRUE) )
    {
#if defined(_NAND_FLASH_BOOTING_) || (defined(__UP_PKG_ON_NAND__) && defined(NAND_SUPPORT))
        if(!DemandPageingRead && nfi_egid && (kal_query_systemInit() == KAL_FALSE && INT_QueryExceptionStatus() == KAL_FALSE))
#else // _NAND_FLASH_BOOTING_
        if(nfi_egid && (kal_query_systemInit() == KAL_FALSE && INT_QueryExceptionStatus() == KAL_FALSE))
#endif // _NAND_FLASH_BOOTING_ || (__UP_PKG_ON_NAND__ && NAND_SUPPORT)
            use_interrupt = KAL_TRUE;
    }
		#endif
	pagefmt_config(Flash_Info.deviceInfo_CE[0].IOWidth, Flash_Info.pageSize, Flash_Info.spareSize);

    if (Para->ce == 0)
    {
        SET_NFI_CS0;
    }
    else
    {
        SET_NFI_CS1;
    }

    drv_data.addCycle = Flash_Info.deviceInfo_CE[ (Para->ce) ].address_cycle;
    drv_data.page_p = &Para->pageIdx[0];
    drv_data.opFlag = FULL_OPERATION;
    drv_data.pageOffset = 0;
    drv_data.buff = &Para->buff[0];
    drv_data.spare = &Para->spare[0];
    retVal = single_Page_Read (&drv_data);
    #if defined DAL_VERIFICATION
    if (Mtd_Fail_Offset != 0xFF)
    { /*test case*/
        retVal = MTD_STATUS_ERROR|(1<<Mtd_Fail_Offset);
    }
    #endif
    if (Para->ce == 1)
        SET_NFI_CS1_END;

#if defined(__NFI_VERSION3_1__)
	NFI_OP_RESET();
#elif defined(__NFI_VERSION2__)
    *NFI_CON=0x0;
    *NFI_OPCON = OPCON_RESET;	// Also wait NAND ready for 528B NAND with sequential read support.
    while (*NFI_PSTA != 0);
#else
    *NFI_FIFOCON = RESET;
    *NFI_OPCON = 0;
    *NFI_CON = 0;
#endif /*__NFI_VERSION2__*/

    pdn_nfi(KAL_FALSE);
    return retVal;
}


kal_uint32 MTD_Erase(mtd_if_para* Para)
{
    mtd_drv_para drv_data;
    kal_uint32 retVal;

    /*Para check - Start*/
    dbg_ASSERT( Para->ce < 2);
    dbg_ASSERT( Para->m_idx < MAX_MULTIPAGE_FUNCTION_NUM);
    dbg_ASSERT( Flash_Info.pageSize%512 == 0 );
    dbg_ASSERT( Para->length <= 16); /*Limited by return value*/
    dbg_ASSERT( Flash_Info.multiErase [(Para->ce)][(Para->m_idx)].multiPageNum == Para->length);
    dbg_ASSERT (Flash_Info.multiErase [(Para->ce)][(Para->m_idx) ].func_p);

    //dbg_ASSERT(Para->m_idx < MAX_MULTIPAGE_FUNCTION_NUM);
    /*Para check - End*/

    pdn_nfi(KAL_TRUE);
	  #if (defined __UBL__)||(defined __FUE__)
	  #else    
    if (! (nfi_egid && use_interrupt == KAL_TRUE) )
    {
        if(nfi_egid && (kal_query_systemInit() == KAL_FALSE && INT_QueryExceptionStatus() == KAL_FALSE))
            use_interrupt = KAL_TRUE;
    }
		#endif
	pagefmt_config(Flash_Info.deviceInfo_CE[0].IOWidth, Flash_Info.pageSize, Flash_Info.spareSize);

    if (Para->ce == 0)
    {
        SET_NFI_CS0;
    }
    else
    {
        SET_NFI_CS1;
    }

    drv_data.addCycle = Flash_Info.deviceInfo_CE[ (Para->ce) ].address_cycle;
    drv_data.page_p = &Para->pageIdx[0];
    drv_data.pageOffset = 0;
    drv_data.opFlag = FULL_OPERATION;

    retVal = Flash_Info.multiErase [(Para->ce)][(Para->m_idx) ].func_p (&drv_data);
    #if defined DAL_VERIFICATION
    if (Mtd_Fail_Offset != 0xFF)
    { /*test case*/
        retVal = MTD_STATUS_ERROR|(1<<Mtd_Fail_Offset);
    }
    #endif

    if (Para->ce == 1)
        SET_NFI_CS1_END;

    NFI_OP_RESET();

    pdn_nfi(KAL_FALSE);
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
/*The content of MTD_MarkBlockBad would be different with BaseBand chip*/
/*Use FDM bad block mark*/
kal_uint32 MTD_MarkBlockBad (mtd_if_para* Para)
{
    mtd_drv_para drv_data;
    kal_uint16 page_size;
    kal_uint32 failPage;
    kal_uint32 retVal;

    /*Para check - Start*/
    dbg_ASSERT(Para->buff);
    dbg_ASSERT(Para->spare);
    dbg_ASSERT(Para->ce < 2);
    dbg_ASSERT( Flash_Info.pageSize%512 == 0 );
    /*Para check - End*/
    /*Mark bad in NAND spare*/
    page_size = Flash_Info.pageSize;
    if (page_size == 512)
    {   /*The action of mark maybe different according to the BB chip's NFI version*/
        ((kal_uint8*)Para->spare)[5] &= FDM_BAD_BLOCK_MARK_512; /*use &= to adapte the original mark, ex: 0x00(early bad)*/
    }
    else
    {   /*The action of mark maybe different according to the BB chip's NFI version*/
        ((kal_uint16*)Para->spare)[0] &= FDM_BAD_BLOCK_MARK_2K; /*use &= to adapte the original mark, ex: 0x00(early bad)*/
    }

    /*Single Program*/
    pdn_nfi(KAL_TRUE);
    #if (defined __UBL__)||(defined __FUE__)
	  #else
    if (! (nfi_egid && use_interrupt == KAL_TRUE) )
    {
        if(nfi_egid && (kal_query_systemInit() == KAL_FALSE && INT_QueryExceptionStatus() == KAL_FALSE))
            use_interrupt = KAL_TRUE;
    }
		#endif
	pagefmt_config(Flash_Info.deviceInfo_CE[0].IOWidth, Flash_Info.pageSize, Flash_Info.spareSize);

    if (Para->ce == 0)
    {
        SET_NFI_CS0;
    }
    else
    {
        SET_NFI_CS1;
    }

    drv_data.addCycle = Flash_Info.deviceInfo_CE[ (Para->ce) ].address_cycle;
    drv_data.page_p = &Para->pageIdx[0];

    drv_data.opFlag = FULL_OPERATION;
    drv_data.pageOffset = 0;
    drv_data.buff = Para->buff;
    drv_data.spare = Para->spare;
    retVal = single_Page_Program(&drv_data);

    if (retVal != MTD_STATUS_NO_ERROR)
    {
        failPage = retVal&0xFFFF;
        retVal = retVal&0xFFFF0000;
        retVal |= failPage << (drv_data.pageOffset) ;
    }
    if (Para->ce == 1)
        SET_NFI_CS1_END;

    NFI_OP_RESET();

    pdn_nfi(KAL_FALSE);
    return retVal;
}

/****************************************************************************
 * Function:
 *
 * Parameters:
 *
 * Returns:      MTD_STATUS_ERROR - The block is a Bad block
 *               MTD_STATUS_NO_ERROR - Block mark is all 1 (or only 1 zero) in 1 byte
 * Description:  This function is use to check the early bad (manufacture mark bad)
 *
 ****************************************************************************/
/*The content of MTD_MarkBlockBad would be different with BaseBand chip*/
/*Use FDM bad block mark*/
kal_uint32 MTD_CheckBlockBad (mtd_if_para* Para)
{
    mtd_drv_para drv_data;
    kal_uint16 page_size;
    kal_uint32 retVal = MTD_STATUS_NO_ERROR;

    /*Para check - Start*/
    dbg_ASSERT(Para->buff);
    dbg_ASSERT(Para->spare);
    dbg_ASSERT(Para->ce < 2);
    dbg_ASSERT( Flash_Info.pageSize%512 == 0 );
    /*Para check - End*/

    pdn_nfi(KAL_TRUE);
    #if (defined __UBL__)||(defined __FUE__)
    #else    
    if (! (nfi_egid && use_interrupt == KAL_TRUE) )
    {
        if(nfi_egid && (kal_query_systemInit() == KAL_FALSE && INT_QueryExceptionStatus() == KAL_FALSE))
            use_interrupt = KAL_TRUE;
    }
    #endif
    page_size = Flash_Info.pageSize;

	pagefmt_config(Flash_Info.deviceInfo_CE[0].IOWidth, Flash_Info.pageSize, Flash_Info.spareSize);

    if (Para->ce == 0)
    {
        SET_NFI_CS0;
    }
    else
    {
        SET_NFI_CS1;
    }

    drv_data.addCycle = Flash_Info.deviceInfo_CE[ (Para->ce) ].address_cycle;
    drv_data.page_p = &Para->pageIdx[0];
    drv_data.opFlag = FULL_OPERATION;
    drv_data.pageOffset = 0;
    drv_data.buff = Para->buff;
    drv_data.spare = Para->spare;
    single_Page_Read (&drv_data);
    if (Para->ce == 1)
        SET_NFI_CS1_END;

    NFI_OP_RESET();

    pdn_nfi(KAL_FALSE);

    /*Check bad block Mark in NAND spare*/
    page_size = Flash_Info.pageSize;
    /*  in __NFI_VERSION2_, eraly bad mark is in the same position of FDM bad block mark, here use condition (ZERO_OF_BAD_BLOCK_MARK_512 + 2) to identify early bad*/
    if (page_size == 512)
    {
		/*
        if ( ZEROBIT[((kal_uint8*)Para->spare)[5] ] >= (ZERO_OF_FDM_BAD_BLOCK_MARK_512 + 2) )
        {
            retVal = MTD_STATUS_ERROR;
        }
        */

        if ( ZEROBIT[((FDMData_512*)Para->spare)->BI ] >= (ZERO_OF_FDM_BAD_BLOCK_MARK_512 + 2) )
        {
            retVal = MTD_STATUS_ERROR;
        }
    }
    else
    {
    	/*
        if ( ZEROBIT[((kal_uint8*)Para->spare)[0] ] >= (ZERO_OF_FDM_BAD_BLOCK_MARK_512 + 2) )
        {
            retVal = MTD_STATUS_ERROR;
        }
        else {
			if (Flash_Info.deviceInfo_CE[0].IOWidth == 16) {
	        	if (  ZEROBIT[((kal_uint8*)Para->spare)[1] ] >= (ZERO_OF_FDM_BAD_BLOCK_MARK_512 + 2) )
	        	{
	            	retVal = MTD_STATUS_ERROR;
	        	}
			}
        }
        */
        if ( ZEROBIT[((FDMData_2k*)Para->spare)->BI & 0xff] >= (ZERO_OF_FDM_BAD_BLOCK_MARK_512 + 2) )
        {
            retVal = MTD_STATUS_ERROR;
        }
        else
        {
			if (Flash_Info.deviceInfo_CE[0].IOWidth == 16) {
	        	if (  ZEROBIT[(((FDMData_2k*)Para->spare)->BI & 0xFF00)>>8 ] >= (ZERO_OF_FDM_BAD_BLOCK_MARK_512 + 2) )
	        	{
	            	retVal = MTD_STATUS_ERROR;
	        	}
			}
        }
    }

    return retVal;
}
/****************************************************************************
 * Function:
 *
 * Parameters:
 *
 * Returns:  MTD_STATUS_NO_ERROR
 *
 * Description:
 *
 ****************************************************************************/
kal_uint32 MTD_NAND_Reset(mtd_if_para* Para)
{
//    kal_uint16 page_size;
    /*Para check - Start*/
    dbg_ASSERT( Para->ce < 2);
    /*Para check - End*/
    pdn_nfi(KAL_TRUE);
/*    page_size = Flash_Info.pageSize;
    if (Flash_Info.deviceInfo_CE[0].IOWidth == 8)
    {
        if (page_size == 512)
        {
            *NFI_PAGEFMT = PAGEFMT_512_8BIT;
        }
        else if (page_size == 2048)
        {
            *NFI_PAGEFMT = PAGEFMT_2K_8BIT;
        }
    }
    else
    {
        if (page_size == 512)
        {
            *NFI_PAGEFMT = PAGEFMT_512_16BIT;
        }
        else if (page_size == 2048)
        {
            *NFI_PAGEFMT = PAGEFMT_2K_16BIT;
        }
        #if ((defined(MT6228)) || (defined(MT6229)) || (defined(MT6230)))
            *NFI_GPIO_DATA1 &= 0x0FFF;
            *NFI_GPIO_DATA2 &= 0xF000;
        #endif
    }*/
    if (Para->ce == 0)
    {
        SET_NFI_CS0;
    }
    else
    {
        SET_NFI_CS1;
    }
    NFI_OP_RESET();
    nAND_RESET();
    if (Para->ce == 1)
        SET_NFI_CS1_END;
    pdn_nfi(KAL_FALSE);
    return MTD_STATUS_NO_ERROR;
}

/*******************************************************************************/
kal_int32 MTD_ShutDown(void)
{
#if defined(FLASH_DISKDRV_DEBUG) && !defined(__MTK_TARGET__)
    if( NULL != file_hd[0] )
       fclose(file_hd[0]);
    if( NULL != file_hd[1] )
       fclose(file_hd[1]);
#else
#if defined(_NAND_FLASH_BOOTING_) || defined(__NANDFDM_MULTI_INSTANCE__) || (defined(__UP_PKG_ON_NAND__) && defined(NAND_SUPPORT))
    #if (defined __UBL__) || (defined __FUE__)
    #else
		pdn_nfi(KAL_TRUE);
    #if defined(__NFI_VERSION3_1__)
    	while (*NFI_STA & STA_NAND_BUSY);
    #else  // defined(__NFI_VERSION3_1__)
      while (IS_NFI_DMA_RUN);
      while (*NFI_PSTA & STATUS_BUSY);
      DMA_Stop(nfi_dmaport);
    #endif // defined(__NFI_VERSION3_1__)
    pdn_nfi(KAL_FALSE);
    #endif
 #endif /* _NAND_FLASH_BOOTING || defined(__NANDFDM_MULTI_INSTANCE__) || (__UP_PKG_ON_NAND__ && NAND_SUPPORT) */
#endif

    return FS_NO_ERROR;
} /*  End of ShutDown */


#if !defined(__FUE__)

/*******************************************************************************/
void nfi_lisr(void)
{
    #if (defined __UBL__) || (defined __FUE__)
    /*In bootloader and fota case, it should not get in */
        force_ASSERT(0, 0, 0, 0);
    #elif defined(FLASH_DISKDRV_DEBUG) && !defined(__MTK_TARGET__)
    /*Do nothing*/
    #else
    IRQMask(IRQ_NFI_CODE);
    //kal_activate_hisr(nfi_hisr_id);
    drv_active_hisr(DRV_NFI_HISR_ID);
    #endif
}


/*******************************************************************************/
void nfi_hisr(void)
{
#if defined(FLASH_DISKDRV_DEBUG) && !defined(__MTK_TARGET__)
/*Do nothing*/
#else

    #if (defined __UBL__) || (defined __FUE__)
    /*In bootloader and fota case, it should not get in */
        force_ASSERT(0, 0, 0, 0);
    #else
    kal_uint32 intr_status;

    intr_status = *NFI_INTR;
    *NFI_INTR_EN = 0x0;
#if defined(__NFI_VERSION3_1__)
    if (intr_status & (WR_COMPLETE | ERASE_COMPLETE | BUSY_RETURN | AHB_DONE))
#else
    if (intr_status & (WR_COMPLETE | ERASE_COMPLETE | BUSY_RETURN))
#endif
        kal_set_eg_events(nfi_egid, NFI_EVENT, KAL_OR);
    else if(intr_status != 0)
        force_ASSERT(0, intr_status, 0, 0);

    IRQClearInt(IRQ_NFI_CODE);
    IRQUnmask(IRQ_NFI_CODE);
    #endif
#endif
}


/*******************************************************************************/
void NFI_DMA_Callback(void)
{
    #if (defined __UBL__) || (defined __FUE__)
    /*In bootloader and fota case, it should not get in */
        force_ASSERT(0, 0, 0, 0);
    #elif defined(FLASH_DISKDRV_DEBUG) && !defined(__MTK_TARGET__)
    /*Do nothing*/
    #else
   if (nfi_egid)
      kal_set_eg_events(nfi_egid, NFI_EVENT, KAL_OR);
    #endif
}

#else // !defined(__FUE__)

void NFI_DMA_Callback(void)
{
   ASSERT(0);
}

#endif // !defined(__FUE__)


void NAND_GPIO_InitIO(char direction, char port)
{
	DCL_HANDLE handle;
	handle=DclGPIO_Open(DCL_GPIO,port);
	if(0==direction)
		DclGPIO_Control(handle,GPIO_CMD_SET_DIR_IN,0);
	else if(1==direction)
		DclGPIO_Control(handle,GPIO_CMD_SET_DIR_OUT,0);
	else
		ASSERT(0);
	DclGPIO_Close(handle);
}
char NAND_GPIO_ReturnMode(char port)
{
	DCL_HANDLE handle;
	DCL_CTRL_DATA_T data;
	handle=DclGPIO_Open(DCL_GPIO,port);
	DclGPIO_Control(handle,GPIO_CMD_RETURN_MODE,&data);
	DclGPIO_Close(handle);
	return data.rReturnMode.u1RetMode;
}
char NAND_GPIO_ReadIO(char port)
{
	DCL_HANDLE handle;
	GPIO_CTRL_READ_T data;
	handle=DclGPIO_Open(DCL_GPIO,port);
	DclGPIO_Control(handle,GPIO_CMD_READ,(DCL_CTRL_DATA_T*)&data);
	DclGPIO_Close(handle);
	return data.u1IOData;
	
}
void NAND_GPIO_WriteIO(char data, char port)
{
	DCL_HANDLE handle;
	handle=DclGPIO_Open(DCL_GPIO,port);	
	if(0==data)
		DclGPIO_Control(handle,GPIO_CMD_WRITE_LOW,0);
	else if(1==data)
		DclGPIO_Control(handle,GPIO_CMD_WRITE_HIGH,0);
	else
		{
			DclGPIO_Close(handle);
			ASSERT(0);
		}
	DclGPIO_Close(handle);	
}
kal_bool NAND_INT_USBBoot(void) // Backward compatible
{
#if (defined(__FUE__)||defined(__UBL__))
  return KAL_FALSE;
#else
	PW_CTRL_IS_USB_BOOT CtrlVal;
	DCL_HANDLE handle;
	handle=DclPW_Open(DCL_PW, FLAGS_NONE);
	DclPW_Control(handle, PW_CMD_IS_USB_BOOT,(DCL_CTRL_DATA_T *)&CtrlVal);
	DclPW_Close(handle);
	return (kal_bool)CtrlVal.val;
#endif//#if (defined(__FUE__)||defined(__UBL__))
}
/*******************************************************************************
 *  Sub-functions
 *******************************************************************************/
/*******************************************************************************/
// Sanity check for NAND device; only used in factory mode
/*-----------------------------------*/

#else
/*In no NFI platform, ext_camera.c is still possible to call get_NFI_bus() and free_NFI_bus()*/
void get_NFI_bus(void)
{
}

void free_NFI_bus(void)
{
}
#endif  // ifdef(MT6205)

#endif /*( defined(__NAND_FDM_50__) && defined(__NFI_VERSION2__) )*/

