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
 *   emi.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines the functionality of Code and Data cache.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/********************************************************************************************
 * README
 * Test platform after revision
 * [1] NOR Flash boot without remap , MT6229_EVB
 * [2] NAND Flash boot , MT6228_EVB
 * [3] NOR Flash boot with remap , MT6225 + Single Bank NOR Flash , for example CRYSTAL25 V3 SB
 ********************************************************************************************/


/*******************************************************************************
 * Include header files.
 *******************************************************************************/


#include "reg_base.h"
#include "emi_hw.h"
#include "emi_sw.h"
#include "cp15.h"
#include "init.h"
#include "intrCtrl.h"


/* RHR Remove */
//#include "kal_release.h"

/* RHR Add */
#include "kal_general_types.h"
#include "kal_public_api.h"

#include "ex_public.h"  //for register dump when exception happens

/**
  * To get the DRAM_CS information as device query source.
  */      
// #include "MemoryDevice_TypeDef.h"   
// #include "custom_EMI.h"
#ifdef __MTK_TARGET__
__attribute__((section("NONCACHEDZI"), zero_init)) 
#endif
kal_uint32 u32DummyRead;

#ifdef __MTK_TARGET__

/*******************************************************************************
  *
  * Define import global data.
  *
  *******************************************************************************/

#if defined(MT6238) || defined(MT6239)
/**
   * ENG_E1 or ENG_E2, used to determine weather SW need to force DRAM entering/exiting self-refresh mode or not.
  */
extern ECO_VERSION mt6238_version; 	
#endif /* MT6238 || MT6239 */

#if defined(MT6236) || defined(MT6236B) || defined(MT6276) || defined(MT6256)
extern kal_bool custom_ifLPSDRAM(void);
#endif

#if defined(__DYNAMICALLY_SET_EMI_ARB_SOFT_MODE__)
kal_uint32 SET_EMI_ARB_HARD_MODE_CNT = 0;
#if defined(MT6256)
#pragma arm section rwdata = "INTSRAM_RW", zidata = "INTSRAM_ZI"
kal_uint32 Set_EMI_BW_Graphic_Mode = 0;  //Set graphic port EMI BW limiter mode when RestoreIRQMask()
kal_uint32 Graphic_EMI_BW_Mode = 0;  //current graphic port EMI BW limiter mode for MM scenario
kal_uint32 RunTimeConfigCnt = 0;
#pragma arm section rwdata, zidata
#endif
#endif /* __DYNAMICALLY_SET_EMI_ARB_SOFT_MODE__ */

#if !defined(__UBL__)
EX_BBREG_DUMP emi_dump;
const kal_uint32 emi_dump_regions[] = {
#if defined(MT6280)
   EMI_base,   0x0200, 4,    /* EMI control and BW filter register  */
#else
   0, 0, 0
#endif
};
#endif /* !__UBL__ */

/*******************************************************************************
  * 
  * Define global data.
  *
  *******************************************************************************/

/**
   * Record whether we are within SW-handled self-refresh mode or not.
   */
#if defined(__EMI_SELFREFRESH_UNDER_SLEEP_CONTROLLED_BY_SW__)

#pragma arm section rwdata = "INTSRAM_RW", zidata = "INTSRAM_ZI"
kal_uint32 sdram_sr_en;
#pragma arm section rwdata, zidata

#endif	/* __EMI_SELFREFRESH_UNDER_SLEEP_CONTROLLED_BY_SW__ */


/**
   * Record the current gmc mask value.
   */
//static kal_uint32 gmc_mask;


/*******************************************************************************
  * 
  * Declare Internal function
  *
  *******************************************************************************/
  
#if defined(__EMI_INTERNAL_NECESSARY_DRIVER__)
kal_int32 __EMI_SetBW(EMI_MASTER_LIMITER *master_limiter);
kal_int32 __EMI_GetBW(EMI_MASTER_LIMITER *master_limiter);
kal_bool custom_ifLPSDRAM(void);
#endif


/*************************************************************************
* FUNCTION
*  INT_RetrieveFlashBaseAddr
*
* DESCRIPTION
*   This function returns flash base address to caller.
*
* CALLS
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/

#if defined(__EMI_INTERNAL_OPTIONAL_DRIVER__)

kal_int32 EMI_QueryIsRemapped(void)
{	
#if defined(__EMI_NO_DRIVER__)	 

   return -1;

#else /* __EMI_NO_DRIVER__ */

   kal_int32 emi_remap_reg_val;
   
   emi_remap_reg_val = *EMI_REMAP;
	
#if defined(MT6251)	

   if(SFI_MAP_FLASH_NA == (emi_remap_reg_val & SFI_REMAP_MASK)) 
   {
      return 0;
   }	

#else /* MT6251 */

   if(EMI_MAP_EXTERNALBOOT_FLASH_SRAM == (emi_remap_reg_val & EMI_REMAP_MASK)) 
   {
      return 0;
   }

#endif /* MT6251 */

   return 1;

#endif /* __EMI_NO_DRIVER__ */

}

#endif  /* __EMI_INTERNAL_OPTIONAL_DRIVER__ */


/*************************************************************************
* FUNCTION
*  EMI_QueryCurSetting
*
* DESCRIPTION
*   This function returns emi setting at run-time to display at engineering mode.
*
* CALLS
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/

/**
  * This option is to allow access to EMI while "MT6516"'s MD is built 
  * as stand-alone load.
  */
#if defined(__EMI_INTERNAL_OPTIONAL_DRIVER__)

kal_int32 EMI_QueryCurSetting(void *emi_setting)
{
#if defined(__EMI_NO_DRIVER__)	 

   return -1;

#else /* __EMI_NO_DRIVER__ */

   EMI_RUNTIME_Info *emi_cur_setting = (EMI_RUNTIME_Info *)emi_setting;

	 
#if defined(MT6223) || defined(MT6227D) || defined(MT6226D) || defined(MT6223P) || defined(MT6223D) || defined(MT6253) || defined(MT6252H) || defined(MT6252) || defined(MT6253E) || defined(MT6253L) || defined(MT6226) || defined(MT6226M) || defined(MT6227)
 
    emi_cur_setting->EMI_CONA_value = *EMI_CONA;
    emi_cur_setting->EMI_CONB_value = *EMI_CONB;
    emi_cur_setting->EMI_REMAP_value = *EMI_REMAP;
    emi_cur_setting->EMI_GEN_value = *EMI_GEN;
    emi_cur_setting->EMI_PREFETCH_value = *PREFETCH_CON;
    emi_cur_setting->reg_num = 5;

#if defined(MT6223) || defined(MT6227D) || defined(MT6226D) || defined(MT6223P) || defined(MT6223D) || defined(MT6253) || defined(MT6252H) || defined(MT6252) || defined(MT6253E) || defined(MT6253L)

    emi_cur_setting->EMI_ADMUX_value = *EMI_ADMUX;
    emi_cur_setting->reg_num = 6;

 #if defined(MT6253)
 
    emi_cur_setting->EMI_CLOCKDEL_value = *EMI_CLOCKDEL;
    emi_cur_setting->EMI_DELA_value = *EMI_DELA;
    emi_cur_setting->EMI_DELB_value = *EMI_DELB;
    emi_cur_setting->EMI_EXTCON_value = *EMI_EXTCON;
    emi_cur_setting->EMI_EXTCON2_value = *EMI_EXTCON2;
    emi_cur_setting->EMI_GEN2_value = *EMI_GEN2;
    emi_cur_setting->EMI_CONA_EXT_value = *EMI_CONA_EXT;
    emi_cur_setting->EMI_CONB_EXT_value = *EMI_CONB_EXT;
    emi_cur_setting->reg_num = 14;
 
 #elif defined(MT6252H) || defined(MT6252) || defined(MT6253E) || defined(MT6253L) /* MT6253 */
 
    emi_cur_setting->EMI_CLOCKDEL_value = *EMI_CLOCKDEL;
    emi_cur_setting->EMI_EXTCON_value = *EMI_EXTCON;
    emi_cur_setting->EMI_EXTCON2_value = *EMI_EXTCON2;
    emi_cur_setting->EMI_GEN2_value = *EMI_GEN2;
    emi_cur_setting->EMI_GEN3_value = *EMI_GEN3;
    emi_cur_setting->EMI_CONA_EXT_value = *EMI_CONA_EXT;
    emi_cur_setting->EMI_CONB_EXT_value = *EMI_CONB_EXT;
    emi_cur_setting->EMI_CONC_EXT_value = *EMI_CONC_EXT;
    emi_cur_setting->EMI_COND_EXT_value = *EMI_COND_EXT;
    emi_cur_setting->EMI_IOA_value = *EMI_IOA;
    emi_cur_setting->EMI_IOB_value = *EMI_IOB;
    emi_cur_setting->EMI_IOC_value = *EMI_IOC;
    emi_cur_setting->reg_num = 18;
    
 #endif /* MT6253 */
   
#endif /* MT6223 || MT6227D || MT6226D || MT6223P || MT6223D || MT6253 || MT6252H || MT6252 || MT6253E || MT6253L */
   

 #elif defined(MT6229) || defined(MT6230)|| defined(MT6228)|| defined(MT6225) /* MT6223 || MT6227D || MT6226D || MT6223P || MT6223D || MT6253 || MT6252H || MT6252 || MT6253E || MT6253L || MT6226 || MT6226M || MT6227 */
 
    emi_cur_setting->EMI_CONA_value = *EMI_CONA;
    emi_cur_setting->EMI_CONB_value = *EMI_CONB;
    emi_cur_setting->EMI_CONI_value = *EMI_CONI;
    emi_cur_setting->EMI_CONK_value = *EMI_CONK;
    emi_cur_setting->EMI_CONL_value = *EMI_CONL;
    emi_cur_setting->EMI_REMAP_value = *EMI_REMAP;
    emi_cur_setting->EMI_GENA_value = *EMI_GENA;
    emi_cur_setting->EMI_GENB_value = *EMI_GENB;
    emi_cur_setting->reg_num = 8;
   
 #if defined(MT6229) || defined(MT6230)
 
    emi_cur_setting->EMI_GENC_value = *EMI_GENC;
    emi_cur_setting->reg_num = 9;
   
 #endif /* MT6229 || MT6230 */
 
 #elif defined(MT6235) || defined(MT6235B) || defined(MT6238) || defined(MT6239) || defined(MT6268) || defined(MT6270A)  /* MT6223 || MT6227D || MT6226D || MT6223P || MT6223D || MT6253 || MT6252H || MT6252 || MT6253E || MT6253L */
 
    emi_cur_setting->EMI_CONA_value = *EMI_CONA;
    emi_cur_setting->EMI_CONB_value = *EMI_CONB;    
    emi_cur_setting->EMI_CONI_value = *EMI_CONI;
    emi_cur_setting->EMI_CONJ_value = *EMI_CONJ;
    emi_cur_setting->EMI_CONK_value = *EMI_CONK;
    emi_cur_setting->EMI_CONL_value = *EMI_CONL;
    emi_cur_setting->EMI_CONM_value = *EMI_CONM;
    emi_cur_setting->EMI_CONN_value = *EMI_CONN; 
    emi_cur_setting->EMI_GENA_value = *EMI_GENA;
    emi_cur_setting->EMI_GENB_value = *EMI_GENB;
    emi_cur_setting->EMI_GENC_value = *EMI_GENC;
    emi_cur_setting->EMI_GEND_value = *EMI_GEND;
    emi_cur_setting->reg_num = 12;

 #if defined(MT6238) || defined(MT6239) || defined(MT6268) || defined(MT6270A)
 
    emi_cur_setting->EMI_CONE_value = *EMI_CONE;
    emi_cur_setting->EMI_CONF_value = *EMI_CONF;
    emi_cur_setting->reg_num = 14;

 #if defined(MT6268) || defined(MT6270A) 

    emi_cur_setting->EMI_DELA_value = *EMI_DELA;
    emi_cur_setting->EMI_DELB_value = *EMI_DELB;
    emi_cur_setting->EMI_DELC_value = *EMI_DELC;
    emi_cur_setting->EMI_DELD_value = *EMI_DELD;
    emi_cur_setting->EMI_DELE_value = *EMI_DELE;
    emi_cur_setting->EMI_DELF_value = *EMI_DELF;
    emi_cur_setting->EMI_DELG_value = *EMI_DELG;
    emi_cur_setting->EMI_DELH_value = *EMI_DELH;
    emi_cur_setting->EMI_DELI_value = *EMI_DELI;
    emi_cur_setting->EMI_DELJ_value = *EMI_DELJ;    
    emi_cur_setting->EMI_ARBA_value = *EMI_ARBA;
    emi_cur_setting->EMI_ARBB_value = *EMI_ARBB;
    emi_cur_setting->EMI_ARBC_value = *EMI_ARBC;
    emi_cur_setting->EMI_ARBD_value = *EMI_ARBD;
    emi_cur_setting->EMI_ARBE_value = *EMI_ARBE;
    emi_cur_setting->EMI_ARBF_value = *EMI_ARBF;
    emi_cur_setting->EMI_ARBG_value = *EMI_ARBG;
    emi_cur_setting->EMI_ARBH_value = *EMI_ARBH;
    emi_cur_setting->EMI_ARBI_value = *EMI_ARBI;
    emi_cur_setting->reg_num = 33;    

#endif /* MT6268 */
   
#endif /* MT6238 || MT6239 || MT6268 || MT6270A */

#elif defined(MT6276) /* || defined(MT6573) do not allow to query emi setting on MD-standalone. */  /* MT6223 || MT6227D || MT6226D || MT6223P || MT6223D || MT6253 */
 
    emi_cur_setting->EMI_CONA_value = *EMI_CONA;
    emi_cur_setting->EMI_CONB_value = *EMI_CONB;  
    emi_cur_setting->EMI_CONE_value = *EMI_CONE;
    emi_cur_setting->EMI_CONF_value = *EMI_CONF;
    emi_cur_setting->EMI_CONI_value = *EMI_CONI;
    emi_cur_setting->EMI_CONJ_value = *EMI_CONJ;
    emi_cur_setting->EMI_CONK_value = *EMI_CONK;
    emi_cur_setting->EMI_CONL_value = *EMI_CONL;
    emi_cur_setting->EMI_CONM_value = *EMI_CONM;
    emi_cur_setting->EMI_CONN_value = *EMI_CONN; 
    emi_cur_setting->EMI_GENA_value = *EMI_GENA;
    emi_cur_setting->EMI_DRCT_value = *EMI_DRCT;
    emi_cur_setting->EMI_DDRV_value = *EMI_DDRV;
    emi_cur_setting->EMI_GEND_value = *EMI_GEND;
  
    emi_cur_setting->EMI_ARBA_value = *EMI_ARBA;
    emi_cur_setting->EMI_ARBB_value = *EMI_ARBB;
    emi_cur_setting->EMI_ARBC_value = *EMI_ARBC;
    emi_cur_setting->EMI_ARBD_value = *EMI_ARBD;
    emi_cur_setting->EMI_ARBE_value = *EMI_ARBE;
    emi_cur_setting->EMI_ARBF_value = *EMI_ARBF;

    emi_cur_setting->reg_num = 20;    

#elif defined(MT6236) || defined(MT6236B) /* MT6223 || MT6227D || MT6226D || MT6223P || MT6223D || MT6253 || MT6252H || MT6252 || MT6253E || MT6253L */

    emi_cur_setting->EMI_CONA_value = *EMI_CONA;
    emi_cur_setting->EMI_CONB_value = *EMI_CONB;    
    emi_cur_setting->EMI_CONI_value = *EMI_CONI;
    emi_cur_setting->EMI_CONJ_value = *EMI_CONJ;
    emi_cur_setting->EMI_CONK_value = *EMI_CONK;
    emi_cur_setting->EMI_CONL_value = *EMI_CONL;
    emi_cur_setting->EMI_CONM_value = *EMI_CONM;
    emi_cur_setting->EMI_CONN_value = *EMI_CONN; 
    emi_cur_setting->EMI_GENA_value = *EMI_GENA;
    emi_cur_setting->EMI_GENB_value = *EMI_GENB;
    emi_cur_setting->EMI_GENC_value = *EMI_GENC;
    emi_cur_setting->EMI_GEND_value = *EMI_GEND;
    emi_cur_setting->EMI_CONE_value = *EMI_CONE;
    emi_cur_setting->EMI_CONF_value = *EMI_CONF;
    emi_cur_setting->EMI_DELA_value = *EMI_DELA;
    emi_cur_setting->EMI_DELB_value = *EMI_DELB;
    emi_cur_setting->EMI_DELC_value = *EMI_DELC;
    emi_cur_setting->EMI_DELD_value = *EMI_DELD;
    emi_cur_setting->EMI_DELE_value = *EMI_DELE;
    emi_cur_setting->EMI_DELF_value = *EMI_DELF;
    emi_cur_setting->EMI_DELG_value = *EMI_DELG;
    emi_cur_setting->EMI_DELH_value = *EMI_DELH;
    emi_cur_setting->EMI_DELI_value = *EMI_DELI;
    emi_cur_setting->EMI_DELJ_value = *EMI_DELJ;    
    emi_cur_setting->EMI_ARBA_value = *EMI_ARBA;
    emi_cur_setting->EMI_ARBB_value = *EMI_ARBB;
    emi_cur_setting->EMI_ARBC_value = *EMI_ARBC;
    emi_cur_setting->EMI_ARBD_value = *EMI_ARBD;
    emi_cur_setting->EMI_ARBE_value = *EMI_ARBE;
    emi_cur_setting->EMI_ARBF_value = *EMI_ARBF;
    emi_cur_setting->EMI_ARBG_value = *EMI_ARBG;
    emi_cur_setting->EMI_ARBH_value = *EMI_ARBH;
    emi_cur_setting->EMI_ARBI_value = *EMI_ARBI;
    emi_cur_setting->reg_num = 33;    

#elif defined(MT6256) /* MT6223 || MT6227D || MT6226D || MT6223P || MT6223D || MT6253 */
 
    emi_cur_setting->EMI_CONA_value = *EMI_CONA;
    emi_cur_setting->EMI_CONB_value = *EMI_CONB;  
    emi_cur_setting->EMI_CONE_value = *EMI_CONE;
    emi_cur_setting->EMI_CONF_value = *EMI_CONF;
    emi_cur_setting->EMI_CONI_value = *EMI_CONI;
    emi_cur_setting->EMI_CONJ_value = *EMI_CONJ;
    emi_cur_setting->EMI_CONK_value = *EMI_CONK;
    emi_cur_setting->EMI_CONL_value = *EMI_CONL;
    emi_cur_setting->EMI_CONM_value = *EMI_CONM;
    emi_cur_setting->EMI_CONN_value = *EMI_CONN; 
    emi_cur_setting->EMI_GENA_value = *EMI_GENA;
    emi_cur_setting->EMI_DRCT_value = *EMI_DRCT;
    emi_cur_setting->EMI_DDRV_value = *EMI_DDRV;
    emi_cur_setting->EMI_GEND_value = *EMI_GEND;
  
    emi_cur_setting->EMI_ARBA_value = *EMI_ARBA;
    emi_cur_setting->EMI_ARBB_value = *EMI_ARBB;
    emi_cur_setting->EMI_ARBC_value = *EMI_ARBC;
    emi_cur_setting->EMI_ARBD_value = *EMI_ARBD;
    emi_cur_setting->EMI_ARBE_value = *EMI_ARBE;
    emi_cur_setting->EMI_ARBF_value = *EMI_ARBF;

    emi_cur_setting->reg_num = 20;    

#elif defined(MT6255) 
 
    emi_cur_setting->EMI_CONA_value = *EMI_CONA;
    emi_cur_setting->EMI_CONB_value = *EMI_CONB;  
    emi_cur_setting->EMI_CONE_value = *EMI_CONE;
    emi_cur_setting->EMI_CONF_value = *EMI_CONF;
    emi_cur_setting->EMI_CONI_value = *EMI_CONI;
    emi_cur_setting->EMI_CONJ_value = *EMI_CONJ;
    emi_cur_setting->EMI_CONK_value = *EMI_CONK;
    emi_cur_setting->EMI_CONL_value = *EMI_CONL;
    emi_cur_setting->EMI_CONM_value = *EMI_CONM;
    emi_cur_setting->EMI_CONN_value = *EMI_CONN; 
    emi_cur_setting->EMI_GENA_value = *EMI_GENA;
    emi_cur_setting->EMI_DRCT_value = *EMI_DRCT;
    emi_cur_setting->EMI_DDRV_value = *EMI_DDRV;
    emi_cur_setting->EMI_GEND_value = *EMI_GEND;
  
    emi_cur_setting->EMI_ARBA_value = *EMI_ARBA;
    emi_cur_setting->EMI_ARBB_value = *EMI_ARBB;
    emi_cur_setting->EMI_ARBC_value = *EMI_ARBC;
    emi_cur_setting->EMI_ARBD_value = *EMI_ARBD;
    emi_cur_setting->EMI_ARBE_value = *EMI_ARBE;

    emi_cur_setting->reg_num = 19;    

#elif defined(MT6280) 
 
    emi_cur_setting->EMI_CONI_value = *EMI_CONI;
    emi_cur_setting->EMI_CONJ_value = *EMI_CONJ;
    emi_cur_setting->EMI_CONK_value = *EMI_CONK;
    emi_cur_setting->EMI_CONL_value = *EMI_CONL;
    emi_cur_setting->EMI_CONM_value = *EMI_CONM;
    emi_cur_setting->EMI_CONN_value = *EMI_CONN; 
    emi_cur_setting->EMI_GENA_value = *EMI_GENA;
    emi_cur_setting->EMI_DRCT_value = *EMI_DRCT;
    emi_cur_setting->EMI_DDRV_value = *EMI_DDRV;
    emi_cur_setting->EMI_GEND_value = *EMI_GEND;
  
    emi_cur_setting->EMI_ARBA_value = *EMI_ARBA;
    emi_cur_setting->EMI_ARBB_value = *EMI_ARBB;
    emi_cur_setting->EMI_ARBC_value = *EMI_ARBC;
    emi_cur_setting->EMI_ARBD_value = *EMI_ARBD;

    emi_cur_setting->reg_num = 14;    


#endif  /* MT6223 || MT6227D || MT6226D || MT6223P || MT6223D || MT6253 || MT6252H || MT6252 || MT6253E || MT6253L || MT6226 || MT6226M || MT6227 */	

   return 0;

#endif /* __EMI_NO_DRIVER__ */

}

#endif  /* __EMI_INTERNAL_OPTIONAL_DRIVER__ */


/*************************************************************************
* FUNCTION
*  EMI_QueryDeviceModeByCS
*
* DESCRIPTION
*   This function returns device mode to caller.
*
* CALLS
*
* PARAMETERS
*    cs - chip select that caller want to query.
* RETURNS
*    device mode (Async/Page/Burst/SDR/DDRI/DDRII)
*************************************************************************/

#if defined(__EMI_INTERNAL_OPTIONAL_DRIVER__)

/**
   * We will support all chips' device mode query in the future, currently, only limited chips are supported.
   */
#if defined(MT6253T) || defined(MT6253) || defined(MT6252H) || defined(MT6252) || defined(MT6253E) || defined(MT6253L) || defined(MT6236) || defined(MT6236B)

EMI_DEVICE_MODE EMI_QueryDeviceModeByCS(EMI_CHIP_SELECT cs)
{	
#if defined(__EMI_NO_DRIVER__)	 

   return EMI_UNKNOWN_MODE;

#else /* __EMI_NO_DRIVER__ */

   kal_uint32 emi_con_reg_val;
   EMI_DEVICE_MODE dev_mode;

   if(cs > EMI_MAX_CS)
   {
	      ASSERT(0);
   }
	 
#if defined(_NAND_FLASH_BOOTING_) || defined(__NOR_FLASH_BOOTING__) || defined(__EMMC_BOOTING__)

#if defined(MT6253T) || defined(MT6253) || defined(MT6252H) || defined(MT6252) || defined(MT6253E) || defined(MT6253L)
   ASSERT(0);
#elif defined(MT6236) || defined(MT6236B) /* MT6253T || MT6253 || MT6252H || MT6252 || MT6253E || MT6253L */

   emi_con_reg_val = *(volatile kal_uint32*)EMI_CONN;
   dev_mode = EMI_GET_DEVICE_DRAM_MODE(emi_con_reg_val);      

#endif /* MT6253T || MT6253 || MT6252H || MT6252 || MT6253E || MT6253L */
	
#else /* _NAND_FLASH_BOOTING_ || __NOR_FLASH_BOOTING__ || __EMMC_BOOTING__ */


#if defined(MT6253T) || defined(MT6253) || defined(MT6252H) || defined(MT6252) || defined(MT6253E) || defined(MT6253L)
   emi_con_reg_val = *(volatile kal_uint32*)((kal_uint8*)EMI_CONA + (((kal_uint8)cs)<<2));
   dev_mode = EMI_GET_DEVICE_MODE(emi_con_reg_val);

#elif defined(MT6236) || defined(MT6236B) /* MT6253T || MT6253 */
   emi_con_reg_val = *(volatile kal_uint32*)((kal_uint8*)EMI_CONE + (((kal_uint8)cs)<<2));

   if(1 == EMI_IS_BURST_MODE(emi_con_reg_val))
   {
      dev_mode = EMI_BURST_MODE;
   }
   else
   {
   	emi_con_reg_val = *(volatile kal_uint32*)((kal_uint8*)EMI_CONA + (((kal_uint8)cs)<<2));

      if(1 == EMI_IS_PAGE_MODE(emi_con_reg_val))
      {
         dev_mode = EMI_PAGE_MODE;   
      }
      else if(1 == EMI_IS_ASYNC_MODE(emi_con_reg_val))
      {
         dev_mode = EMI_ASYNC_MODE;      
      }
      else
      {
         ASSERT(0);
      }
}

#endif /* MT6253T || MT6253 || MT6252H || MT6252 || MT6253E || MT6253L */

#endif /* _NAND_FLASH_BOOTING_ || __NOR_FLASH_BOOTING__ || __EMMC_BOOTING__ */

   return dev_mode;

#endif /* __EMI_NO_DRIVER__ */

}

#endif /* MT6253T || MT6253 || MT6252H || MT6252 || MT6253E || MT6253L || MT6236 ||  MT6236B */

#endif  /* __EMI_INTERNAL_OPTIONAL_DRIVER__ */


/*************************************************************************
* FUNCTION
*  EMI_QueryDeviceModeByMemType
*
* DESCRIPTION
*   This function returns device mode to caller.
*
* CALLS
*
* PARAMETERS
*    mem_type - mem_type that caller want to query.
* RETURNS
*    device mode (Async/Page/Burst/SDR/DDRI/DDRII)
*************************************************************************/

#if defined(__EMI_INTERNAL_OPTIONAL_DRIVER__)

/**
   * We will support all chips' device mode query in the future, currently, only limited chips are supported.
   */
#if defined(MT6253T) || defined(MT6253) || defined(MT6252H) || defined(MT6252) || defined(MT6253E) || defined(MT6253L) || defined(MT6236) || defined(MT6236B)

EMI_DEVICE_MODE EMI_QueryDeviceModeByMemType(EMI_MEMTYPE mem_type)
{	
#if defined(__EMI_NO_DRIVER__)	 

   return EMI_UNKNOWN_MODE;

#else /* __EMI_NO_DRIVER__ */

   EMI_CHIP_SELECT cs = EMI_UNKNOWN_CS;

#if defined(_NAND_FLASH_BOOTING_) || defined(__NOR_FLASH_BOOTING__) || defined(__EMMC_BOOTING__)

   /**
      * Here is the template for common chip, that is, when all Flash's (no matter NAND or NOR) contents will be shadowed to Ram, 
      * we always return Ram's mode no matter user want to query Flash or Ram. This is because user's data must be returned from Ram
      * under shadowed configuration.
      */
   if(EMI_FLASH == mem_type || EMI_RAM == mem_type)
   {
      /**
         * If it is NAND booting, we use customer's CSx as our query source.
         */
      //cs = (EMI_CHIP_SELECT)DRAM_CS;
      cs = EMI_CS0;
   }
   else
   {
      //return EMI_UNKNOWN_MODE;
      ASSERT(0);
   }
	
#else /* _NAND_FLASH_BOOTING_ || __NOR_FLASH_BOOTING__ || __EMMC_BOOTING__ */

   if(EMI_FLASH == mem_type)
   {
      cs = EMI_CS0;
   }
   else if(EMI_RAM == mem_type)
   {
      cs = EMI_CS1;
   }
   else
   {
      //return EMI_UNKNOWN_MODE;
      ASSERT(0);
   }
	
#endif /* _NAND_FLASH_BOOTING_ || __NOR_FLASH_BOOTING__ || __EMMC_BOOTING__ */

   if (cs == EMI_UNKNOWN_CS) 
   {
      return EMI_UNKNOWN_MODE;
   } 
   else 
   {
      return EMI_QueryDeviceModeByCS(cs);
   }
#endif /* __EMI_NO_DRIVER__ */

}

#endif /* MT6253T || MT6253 || MT6236 ||  MT6236B */

#endif  /* __EMI_INTERNAL_OPTIONAL_DRIVER__ */


/*************************************************************************
* FUNCTION
*  INT_DisableDataCache
*
* DESCRIPTION
*  This is specific function for flash driver only for disabling EMI's data cache. Only MT6223 MT6227D MT6253 series will use this function.
*
* CALLS
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/

#if defined(__EMI_INTERNAL_OPTIONAL_DRIVER__)

#if defined(__EMI_SNORCODE_LOCATE_EXTSRAM__)
#ifdef __MTK_TARGET__
__attribute__ ((section ("SNORCODE"))) 
#endif /* __MTK_TARGET__ */
#elif defined(__EMI_SNORCODE_LOCATE_INTSRAM__) /* __EMI_SNORCODE_LOCATE_EXTSRAM__ */
#ifdef __MTK_TARGET__
//__attribute__ ((section ("SNORCODE_INT"))) 
#endif /* __MTK_TARGET__ */
#else /* __EMI_SNORCODE_LOCATE_EXTSRAM__ */
#error "Unexpected compile option"
#endif /* __EMI_SNORCODE_LOCATE_EXTSRAM__ */

#if defined(__UBL__) && defined(__CARD_DOWNLOAD__)
#ifdef __MTK_TARGET__

#endif /* __MTK_TARGET__ */
#endif /* __UBL__ */

kal_int32 INT_DisableDataCache(void)
{
#if defined(__EMI_NO_DRIVER__)	 

   return -1;

#else /* __EMI_NO_DRIVER__ */

   kal_uint32  restore_value = 0;

#if defined(__EMI_WITH_CACHE_SUPPORT__)
   
   restore_value = *PREFETCH_CON;
   
/* On MT6252, the I/DPREF on EMI are used to decide either convert burst to single or not,
   and they should always be 1. Note that the I/D prefetching is no function on MT6252.
   However, we will still use/un-use I/D-Cache in some situatoin. 
   */
#if defined(__EMI_PREF_AS_NOB2S__)
   *PREFETCH_CON &= ~(0x10000);
#else
   *PREFETCH_CON &= ~(0x30000);
#endif // __EMI_PREF_AS_NOB2S__

#else /* __EMI_WITH_CACHE_SUPPORT__ */
   
   /**
      * Do nothing.
      */

#endif /* __EMI_WITH_CACHE_SUPPORT__ */

   return restore_value;

#endif /* __EMI_NO_DRIVER__ */
}

#endif  /* __EMI_INTERNAL_OPTIONAL_DRIVER__ */


/*************************************************************************
* FUNCTION
*  INT_RestoreDataCache
*
* DESCRIPTION
*  This is specific function for flash driver only for restoring EMI's data cache. Only MT6223 MT6227D MT6253 series will use this function.
*
* CALLS
*
* PARAMETERS
*  Value to be restored.
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/

#if defined(__EMI_INTERNAL_OPTIONAL_DRIVER__)

#if defined(__EMI_SNORCODE_LOCATE_EXTSRAM__)
#ifdef __MTK_TARGET__
__attribute__ ((section ("SNORCODE"))) 
#endif /* __MTK_TARGET__ */
#elif defined(__EMI_SNORCODE_LOCATE_INTSRAM__) /* __EMI_SNORCODE_LOCATE_EXTSRAM__ */
#ifdef __MTK_TARGET__
//__attribute__ ((section ("SNORCODE_INT"))) 
#endif /* __MTK_TARGET__ */
#else /* __EMI_SNORCODE_LOCATE_EXTSRAM__ */
#error "Unexpected compile option"
#endif /* __EMI_SNORCODE_LOCATE_EXTSRAM__ */

#if defined(__UBL__) && defined(__CARD_DOWNLOAD__)
#ifdef __MTK_TARGET__

#endif /* __MTK_TARGET__ */
#endif /* __UBL__ */

void INT_RestoreDataCache(kal_uint32 restore_value)
{
#if defined(__EMI_NO_DRIVER__)	 

   return;

#else /* __EMI_NO_DRIVER__ */

#if defined(__EMI_WITH_CACHE_SUPPORT__)
   
   *PREFETCH_CON = restore_value;
   
#else /* __EMI_WITH_CACHE_SUPPORT__ */
   
   /**
      * Do nothing.
      */

#endif /* __EMI_WITH_CACHE_SUPPORT__ */

   return;

#endif /* __EMI_NO_DRIVER__ */

}


#endif  /* __EMI_INTERNAL_OPTIONAL_DRIVER__ */


/*************************************************************************
* FUNCTION
*  INT_DRAMSelfRefreshModeEnable
*
* DESCRIPTION
*  This function is used to force DRAM enter Self-Refresh Mode.
*
* CALLS
*
* PARAMETERS
*  Value to be restored.
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/

#if defined(__EMI_INTERNAL_NECESSARY_DRIVER__)

#if defined(__EMI_SELFREFRESH_UNDER_SLEEP_CONTROLLED_BY_SW__)

#pragma arm section code= "INTSRAM_ROCODE", rodata = "INTSRAM_RODATA", rwdata = "INTSRAM_RW"

void INT_DRAMSelfRefreshModeEnable(void)
{

#if defined(__EMI_NO_DRIVER__)	 

   return;

#else /* __EMI_NO_DRIVER__ */

   kal_int32 l_i2Delay;
   kal_uint32 irq;
   
   /**
      * Eliminate compile warning 
      */
   irq = 0;

   irq = SaveAndSetIRQMask();
   {
      /** 
          * NoteXXX: In the new sleep mode design, a wakeup interrupt will be triggered
          *          when system wakes up from sleep mode.
          *          The vector table must be locked down in the cache since
          *          SDRAM is still in self-refresh mode.
          */
      sdram_sr_en = 1;
   
      cp15_invalidate_icache_single(0x00);
      cp15_invalidate_icache_single(0x20);
      cp15_invalidate_icache_single(0x40);
      cp15_invalidate_dcache_single(0x00);
      cp15_invalidate_dcache_single(0x20);
      cp15_invalidate_dcache_single(0x40);
   
      /* lock I-CACHE way 1~3 */
      cp15_lockdown_icache(0xE);
      /* load specific addresses into I-CACHE */
      cp15_prefetch_icache_line(0x00);
      cp15_prefetch_icache_line(0x20);
      cp15_prefetch_icache_line(0x40);
   
      /* lock I-CACHE way 0 */
      cp15_lockdown_icache(0x1);
      /* lock D-CACHE way 1~3 */
      cp15_lockdown_dcache(0xE);
      /* load specific addresses into D-CACHE */
      l_i2Delay = (kal_int32)(*(volatile kal_uint32 *)0x00);
      l_i2Delay = (kal_int32)(*(volatile kal_uint32 *)0x20);
      l_i2Delay = (kal_int32)(*(volatile kal_uint32 *)0x40);
   
      /* lock D-CACHE way 0 */
      cp15_lockdown_dcache(0x1);
   
      /**
         * Force EMI entering S.R. mode.
         */
      *EMI_CONN &= ~(0x00000002);
      for(l_i2Delay = 0; l_i2Delay < 10; l_i2Delay++);
      *EMI_CONN |= 0x00000020;
      for(l_i2Delay = 0; l_i2Delay < 255; l_i2Delay++);
   }
   RestoreIRQMask(irq);

#endif /* __EMI_NO_DRIVER__ */

}

#pragma arm section code, rodata, rwdata

#endif	/* __EMI_SELFREFRESH_UNDER_SLEEP_CONTROLLED_BY_SW__ */

#endif  /* __EMI_INTERNAL_NECESSARY_DRIVER__ */



/*************************************************************************
* FUNCTION
*  INT_DRAMSelfRefreshModeDisable
*
* DESCRIPTION
*  This function is used to force DRAM exit Self-Refresh Mode.
*
* CALLS
*
* PARAMETERS
*  Value to be restored.
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/

#if defined(__EMI_INTERNAL_NECESSARY_DRIVER__)

#if defined(__EMI_SELFREFRESH_UNDER_SLEEP_CONTROLLED_BY_SW__)

#pragma arm section code= "INTSRAM_ROCODE", rodata = "INTSRAM_RODATA", rwdata = "INTSRAM_RW"

void INT_DRAMSelfRefreshModeDisable(void)
{

#if defined(__EMI_NO_DRIVER__)	 

   return;

#else /* __EMI_NO_DRIVER__ */

   kal_int32 l_i2Delay;
   kal_uint32 irq;

   /**
      * Eliminate compile warning 
      */
   irq = 0;

   irq = SaveAndSetIRQMask();
   {
      /**
         * Force EMI leaving S.R. mode.
         */	
      *EMI_CONN &= ~(0x00000020);
      for(l_i2Delay = 0; l_i2Delay < 10; l_i2Delay++);
      *EMI_CONN |= 0x00000002;
      for(l_i2Delay = 0; l_i2Delay < 255; l_i2Delay++);
   
      /* unlock I-CACHE way 0~3 */
      cp15_lockdown_icache(0x0);
      /* unlock D-CACHE way 0~3 */
      cp15_lockdown_dcache(0x0);
   
      sdram_sr_en = 0;
   }
   RestoreIRQMask(irq);

#endif /* __EMI_NO_DRIVER__ */

}

#pragma arm section code, rodata, rwdata

#endif	/* __EMI_SELFREFRESH_UNDER_SLEEP_CONTROLLED_BY_SW__ */

#endif  /* __EMI_INTERNAL_NECESSARY_DRIVER__ */



/*************************************************************************
* FUNCTION
*  INT_DRAMSelfRefreshModeEnable
*
* DESCRIPTION
*  This function is used to force DRAM enter Self-Refresh Mode.
*
* CALLS
*
* PARAMETERS
*  Value to be restored.
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/

#if defined(__EMI_INTERNAL_NECESSARY_DRIVER__)

#if defined(__EMI_2XCLK_CALIBRATION_UNDER_SLEEP_CONTROLLED_BY_SW__)

#pragma arm section code= "INTSRAM_ROCODE", rodata = "INTSRAM_RODATA", rwdata = "INTSRAM_RW"

void INT_CalibrateEMI2xClock(void)
{
#if defined(__EMI_NO_DRIVER__)	 

   return;

#else /* __EMI_NO_DRIVER__ */

	kal_int16 l_i2Delay;

#if defined(MT6238) || defined(MT6239)

    if(ENG_E1 == mt6238_version)
    {
        /* Disable SCLK_EN/DCLK_EN first. */
        *EMI_GENA = 0x0008880A;
        for(l_i2Delay = 0; l_i2Delay < 255; l_i2Delay++);
        
        /* Enable SCLK_EN first to sync EMI 2x & 1x clock */
        *(volatile kal_uint32 *)EMI_GENA = 0x00088C0A;
        for(l_i2Delay = 0; l_i2Delay < 255; l_i2Delay++);
        
        /* Enable DCLK_EN */
        *(volatile kal_uint32 *)EMI_GENA = 0x00088E0A;
        for(l_i2Delay = 0; l_i2Delay < 255; l_i2Delay++);
     }
    else if(ENG_E2 == mt6238_version)
    {
        /* Disable HCLKX2_CK_ON first. */
        *(volatile kal_uint32 *)EMI_GENA &= 0xFFFFFEFF;		
        /* Enable HCLKX2_CK_ON first. */
        *(volatile kal_uint32 *)EMI_GENA |= 0x00000100;
    }

#elif defined(MT6235) || defined(MT6235B) /* MT6238 || MT6239 */

    /* Disable SCLK_EN/DCLK_EN first. */
    *(volatile kal_uint32 *)EMI_GENA = 0x0008880A;
    for(l_i2Delay = 0; l_i2Delay < 255; l_i2Delay++);
    
    /* Enable SCLK_EN first to sync EMI 2x & 1x clock */
    *(volatile kal_uint32 *)EMI_GENA = 0x00088C0A;
    for(l_i2Delay = 0; l_i2Delay < 255; l_i2Delay++);
    
    /* Enable DCLK_EN */
    *(volatile kal_uint32 *)EMI_GENA = 0x00088E0A;
    for(l_i2Delay = 0; l_i2Delay < 255; l_i2Delay++);

#endif /* MT6238 || MT6239 */
	
#endif /* __EMI_NO_DRIVER__ */

}

#pragma arm section code, rodata, rwdata

#endif	/* __EMI_2XCLK_CALIBRATION_UNDER_SLEEP_CONTROLLED_BY_SW__ */

#endif  /* __EMI_INTERNAL_NECESSARY_DRIVER__ */


/*************************************************************************
* FUNCTION
*  EMI_SetScenarioBW
*
* DESCRIPTION
*  This function sets EMI arbitrator for GMC.
*
* PARAMETERS
*  scenario   -   multimedia scenario (different scenario implies different
*                 required EMI bandwidth)
*
* RETURNS
*  0 for success; negative value for failure
*
*************************************************************************/
#if ( !defined(__UBL__)) 

#if defined(__EMI_INTERNAL_NECESSARY_DRIVER__)
#if defined(MT6256) || defined(MT6255)
    static kal_uint32 is_3D_MMI = 0;
    static kal_uint32 is_MM_Scenario = 0;
    static kal_uint32 is_3D_MMI_2_LAYER_LCD = 0;
    static kal_semid EMI_sem = 0;
#endif
kal_int32 EMI_SetScenarioBW(kal_uint32 scenario)
{

#if defined(__EMI_NO_DRIVER__)	 

    //ret = -1; 
    return -1;

#else /* __EMI_NO_DRIVER__ */

    kal_int32 ret = 0;

#if defined(MT6276)
    static kal_uint8 is_fcore_logging = 0;
#endif

#if defined(MT6236) || defined(MT6236B)

    /***************
      *
      * MT6236 chip
      *
      **************/

    EMI_MASTER_LIMITER master_limiter;

    /**
       * Get current EMI bandwidth settings.
       */
    ASSERT(0 == __EMI_GetBW(&master_limiter));

    if (KAL_TRUE == custom_ifLPSDRAM()) 
    {
        /**
           * MT6236 + DDRx16.
           * The MM's EMI BW is based on MM designer's simulation result.
           */

        switch (scenario) 
        {
            case MM_SCE_MMI:
                /**
                    * This scenario switches back to normal EMI bandwidth allocation.
                    * GMC1 EMI BW: 22.66%.
                    * GMC2 EMI BW: 19.53%
                    */
                master_limiter.emi_bw.gmc1_port_bw = 23;
                master_limiter.emi_bw.gmc2_port_bw = 20;
                break;
    
            case MM_SCE_CAM_PREV:

                /**
                    * GMC1 EMI BW: 16.41%.
                    * GMC2 EMI BW: 31.25%
                    */
                master_limiter.emi_bw.gmc1_port_bw = 16;
                master_limiter.emi_bw.gmc2_port_bw = 31;
                break;
    
            case MM_SCE_CAP:
                /**
                    * GMC1 EMI BW: 25%.
                    * GMC2 EMI BW: 17.19%
                    */
                master_limiter.emi_bw.gmc1_port_bw = 25;
                master_limiter.emi_bw.gmc2_port_bw = 17;
                break;
    
            case MM_CSE_CAP_OFFLINE:
                /**
                    * GMC1 EMI BW: 38.9%.
                    * GMC2 EMI BW: 18%
                    */
                master_limiter.emi_bw.gmc1_port_bw = 39;
                master_limiter.emi_bw.gmc2_port_bw = 18;
                break;
    
            case MM_CSE_CAP_P1_OFFLINE:
                /* impossible */
                ASSERT(0);
                break;
                
            case MM_CSE_CAP_P2_OFFLINE:
                /* impossible */
                ASSERT(0);
                break;            
    
            case MM_SCE_VIDEO_REC:
                /**
                    * GMC1 EMI BW: 10.94%.
                    * GMC2 EMI BW: 23.44%
                    */
                master_limiter.emi_bw.gmc1_port_bw = 11;
                master_limiter.emi_bw.gmc2_port_bw = 23;
                break;

            case MM_SCE_VIDEO_REC_FR2X:
                /**
                    * GMC1 EMI BW: 13.17%.
                    * GMC2 EMI BW: 25.04%
                    */
                master_limiter.emi_bw.gmc1_port_bw = 13;
                master_limiter.emi_bw.gmc2_port_bw = 25;
                break;
    
            case MM_SCE_VIDEO_PLAY:
                /**
                    * GMC1 EMI BW: 6.25%.
                    * GMC2 EMI BW: 23.44%
                    */
                master_limiter.emi_bw.gmc1_port_bw = 6;
                master_limiter.emi_bw.gmc2_port_bw = 23;
                break;
    
            case MM_SCE_VIDEO_REC_HVGA:
                /**
                    * GMC1 EMI BW: 12.3%.
                    * GMC2 EMI BW: 30.25%
                    */
                master_limiter.emi_bw.gmc1_port_bw = 12;
                master_limiter.emi_bw.gmc2_port_bw = 30;
                break;

            case MM_SCE_VIDEO_REC_HVGA_FR2X:
                /**
                    * GMC1 EMI BW: 16.32%.
                    * GMC2 EMI BW: 34.15%
                    */
                master_limiter.emi_bw.gmc1_port_bw = 16;
                master_limiter.emi_bw.gmc2_port_bw = 34;
                break;

            case MM_SCE_VIDEO_PLAY_HVGA:
                /**
                    * GMC1 EMI BW: 10.02%.
                    * GMC2 EMI BW: 33.83%
                    */
                master_limiter.emi_bw.gmc1_port_bw = 10;
                master_limiter.emi_bw.gmc2_port_bw = 34;
                break;
    
            case MM_SCE_VIDEO_REC_D1:
                /**
                    * GMC1 EMI BW: 11.72%.
                    * GMC2 EMI BW: 41.99%
                    */
                master_limiter.emi_bw.gmc1_port_bw = 12;
                master_limiter.emi_bw.gmc2_port_bw = 42;
                break;
    
            case MM_SCE_VIDEO_PLAY_D1:
                /**
                    * GMC1 EMI BW: 13.66%.
                    * GMC2 EMI BW: 39.99%
                    */
                master_limiter.emi_bw.gmc1_port_bw = 14;
                master_limiter.emi_bw.gmc2_port_bw = 40;
                break;
    
            default:
                ret = -1;
                break;
        }
    }
    else 
    {
        /**
           * MT6236 + ADMUX 
           */

        switch (scenario) 
        {
            case MM_SCE_MMI:
                /**
                    * This scenario switches back to normal EMI bandwidth allocation.
                    * GMC1 EMI BW: 16.98%.
                    * GMC2 EMI BW: 16.01%
                    */
                master_limiter.emi_bw.gmc1_port_bw = 17;
                master_limiter.emi_bw.gmc2_port_bw = 16;
                break;

            case MM_SCE_CAM_PREV:
                /**
                    * GMC1 EMI BW: 0%.
                    * GMC2 EMI BW: 35.35%
                    */
                master_limiter.emi_bw.gmc1_port_bw = 0;
                master_limiter.emi_bw.gmc2_port_bw = 35;
                break;
    
            case MM_SCE_CAP:
                /**
                    * GMC1 EMI BW: 23.11%.
                    * GMC2 EMI BW: 0%
                    */
                master_limiter.emi_bw.gmc1_port_bw = 23;
                master_limiter.emi_bw.gmc2_port_bw = 0;
                break;
    
            case MM_CSE_CAP_OFFLINE:
                /**
                    * GMC1 EMI BW: 33.71%.
                    * GMC2 EMI BW: 2.02%
                    */
                master_limiter.emi_bw.gmc1_port_bw = 34;
                master_limiter.emi_bw.gmc2_port_bw = 2;
                break;
    
            case MM_CSE_CAP_P1_OFFLINE:
                /**
                    * GMC1 EMI BW: 0%.
                    * GMC2 EMI BW: 35.43%
                    */
                master_limiter.emi_bw.gmc1_port_bw = 0;
                master_limiter.emi_bw.gmc2_port_bw = 35;;
                break;
                
            case MM_CSE_CAP_P2_OFFLINE:
                /**
                    * GMC1 EMI BW: 15.43%.
                    * GMC2 EMI BW: 20.47%
                    */
                master_limiter.emi_bw.gmc1_port_bw = 15;
                master_limiter.emi_bw.gmc2_port_bw = 20;
                break;            
        
            case MM_SCE_VIDEO_REC:
                /**
                    * GMC1 EMI BW: 5%.
                    * GMC2 EMI BW: 30.52%
                    */
                master_limiter.emi_bw.gmc1_port_bw = 5;
                master_limiter.emi_bw.gmc2_port_bw = 30;
                break;
    
            case MM_SCE_VIDEO_PLAY:
                /**
                    * GMC1 EMI BW: 1.22%.
                    * GMC2 EMI BW: 31.08%
                    */
                master_limiter.emi_bw.gmc1_port_bw = 1;
                master_limiter.emi_bw.gmc2_port_bw = 31;
                break;
    
            default:
                ret = -1;
                break;
        }
    }

    /**
       * Set EMI bandwidth settings according to requested scenarios.
       */
    ASSERT(0 == __EMI_SetBW(&master_limiter));
  

#elif defined(MT6276) /* MT6236 || MT6236B */

    /***************
      *
      * MT6276 chip
      *
      **************/

    EMI_MASTER_LIMITER master_limiter;

    /**
       * Get current EMI bandwidth settings.
       */
    ASSERT(0 == __EMI_GetBW(&master_limiter));

    // MT6276M has no MMI, EMI_SetScenarioBW() should not be invoked
    if (CHIP_MT6276M == INT_ChipName())
    {
        if (scenario == SS_FCORE_LOGGING)
        {
            /**
                * Only for USB logging in eng. mode
                */

            /**
                * Determine bandwidth allocation.
                */

            master_limiter.emi_bw.mcu_port_bw = 45;
            master_limiter.emi_bw.fcore_port_bw = 30;
            master_limiter.emi_bw.md2g3gauddbg_port_bw = 6;
            master_limiter.emi_bw.peri_port_bw = 8;
            master_limiter.emi_bw.mm_port_bw = 0;
        
            /**
               * Determine soft mode or hard mode for bandwidth allocation.
               */    
            master_limiter.emi_softmode.mcu_port_softmode = 1;
            master_limiter.emi_softmode.fcore_port_softmode = 1;
            master_limiter.emi_softmode.md2g3gauddbg_port_softmode = 0;
            master_limiter.emi_softmode.peri_port_softmode = 1;
            master_limiter.emi_softmode.mm_port_softmode = 1;

            is_fcore_logging = 1;
        } 
        else
        {
            ret = -1;
        }
    } 
    else if (custom_ifLPSDRAM() == KAL_TRUE) 
    {

        if (is_fcore_logging && (scenario!=SS_FCORE_LOGGING)) {
           ASSERT(0);
        }
        
        /**
           * MT6276 + DDRx32.
           * The MM's EMI BW is based on MM designer's simulation result.
           */

        switch (scenario) 
        {

#if defined(MT6276_S00)

            case MM_SCE_MMI:
                /**
                    * This scenario switches back to normal EMI bandwidth allocation.
                    * MCU EMI BW: 30%.
                    * Fcore EMI BW: 13.52%.
                    * FcoreDMA EMI BW: 0%.
                    * MD2G3G EMI BW: 5.17%.
                    * MM EMI BW: 28.29%.
                    * DMADBGAUD EMI BW: 13.42%.
                    */

                /**
                   * Determine bandwidth allocation.
                   */
                master_limiter.emi_bw.mcu_port_bw = 30;
                master_limiter.emi_bw.fcore_port_bw = 14;
                master_limiter.emi_bw.fcoredma_port_bw = 0;
                master_limiter.emi_bw.md2g3g_port_bw = 5;
                master_limiter.emi_bw.mm_port_bw = 28;
                master_limiter.emi_bw.dmadgbaud_port_bw = 13;
            
                /**
                   * Determine soft mode or hard mode for bandwidth allocation.
                   */    
                master_limiter.emi_softmode.mcu_port_softmode = 1;
                master_limiter.emi_softmode.fcore_port_softmode = 1;
                master_limiter.emi_softmode.fcoredma_port_softmode = 1;
                master_limiter.emi_softmode.md2g3g_port_softmode = 0;
                master_limiter.emi_softmode.mm_port_softmode = 0;
                master_limiter.emi_softmode.dmadgbaud_port_softmode = 0;

                break;

            case MM_SCE_CAM_PREV:
                /**
                    * MCU EMI BW: 30%.
                    * Fcore EMI BW: 10%.
                    * FcoreDMA EMI BW: 0%.
                    * MD2G3G EMI BW: 5.17%.
                    * MM EMI BW: 28.67%.
                    * DMADBGAUD EMI BW: 14.5%.
                    */

                /**
                   * Determine bandwidth allocation.
                   */
                master_limiter.emi_bw.mcu_port_bw = 30;
                master_limiter.emi_bw.fcore_port_bw = 10;
                master_limiter.emi_bw.fcoredma_port_bw = 0;
                master_limiter.emi_bw.md2g3g_port_bw = 5;
                master_limiter.emi_bw.mm_port_bw = 29;
                master_limiter.emi_bw.dmadgbaud_port_bw = 15;
            
                /**
                   * Determine soft mode or hard mode for bandwidth allocation.
                   */    
                master_limiter.emi_softmode.mcu_port_softmode = 1;
                master_limiter.emi_softmode.fcore_port_softmode = 1;
                master_limiter.emi_softmode.fcoredma_port_softmode = 1;
                master_limiter.emi_softmode.md2g3g_port_softmode = 0;
                master_limiter.emi_softmode.mm_port_softmode = 0;
                master_limiter.emi_softmode.dmadgbaud_port_softmode = 0;
                break;
    
            case MM_SCE_CAP:
                /**
                    * MCU EMI BW: 30%.
                    * Fcore EMI BW: 10%.
                    * FcoreDMA EMI BW: 0%.
                    * MD2G3G EMI BW: 5.17%.
                    * MM EMI BW: 33.66%.
                    * DMADBGAUD EMI BW: 16.21%.
                    */

                /**
                   * Determine bandwidth allocation.
                   */
                master_limiter.emi_bw.mcu_port_bw = 30;
                master_limiter.emi_bw.fcore_port_bw = 10;
                master_limiter.emi_bw.fcoredma_port_bw = 0;
                master_limiter.emi_bw.md2g3g_port_bw = 5;
                master_limiter.emi_bw.mm_port_bw = 34;
                master_limiter.emi_bw.dmadgbaud_port_bw = 16;
            
                /**
                   * Determine soft mode or hard mode for bandwidth allocation.
                   */    
                master_limiter.emi_softmode.mcu_port_softmode = 1;
                master_limiter.emi_softmode.fcore_port_softmode = 1;
                master_limiter.emi_softmode.fcoredma_port_softmode = 1;
                master_limiter.emi_softmode.md2g3g_port_softmode = 0;
                master_limiter.emi_softmode.mm_port_softmode = 0;
                master_limiter.emi_softmode.dmadgbaud_port_softmode = 0;
                break;
          
            case MM_SCE_VIDEO_REC:
                /**
                    * MCU EMI BW: 30%.
                    * Fcore EMI BW: 13.57%.
                    * FcoreDMA EMI BW: 0%.
                    * MD2G3G EMI BW: 5.17%.
                    * MM EMI BW: 31.23%.
                    * DMADBGAUD EMI BW: 16.21%.
                    */

                /**
                   * Determine bandwidth allocation.
                   */
                master_limiter.emi_bw.mcu_port_bw = 30;
                master_limiter.emi_bw.fcore_port_bw = 14;
                master_limiter.emi_bw.fcoredma_port_bw = 0;
                master_limiter.emi_bw.md2g3g_port_bw = 5;
                master_limiter.emi_bw.mm_port_bw = 31;
                master_limiter.emi_bw.dmadgbaud_port_bw = 16;
            
                /**
                   * Determine soft mode or hard mode for bandwidth allocation.
                   */    
                master_limiter.emi_softmode.mcu_port_softmode = 1;
                master_limiter.emi_softmode.fcore_port_softmode = 1;
                master_limiter.emi_softmode.fcoredma_port_softmode = 1;
                master_limiter.emi_softmode.md2g3g_port_softmode = 0;
                master_limiter.emi_softmode.mm_port_softmode = 0;
                master_limiter.emi_softmode.dmadgbaud_port_softmode = 0;
                break;
    
            case MM_SCE_VIDEO_PLAY:
                /**
                    * MCU EMI BW: 30%.
                    * Fcore EMI BW: 16.65% & 15.59% (MP4/H.264).
                    * FcoreDMA EMI BW: 0%.
                    * MD2G3G EMI BW: 5.17%.
                    * MM EMI BW: 25.06% & 26.12% (MP4/H.264).
                    * DMADBGAUD EMI BW: 19.07%.
                    */

                /**
                   * Determine bandwidth allocation.
                   */
                master_limiter.emi_bw.mcu_port_bw = 30;
                master_limiter.emi_bw.fcore_port_bw = 17;
                master_limiter.emi_bw.fcoredma_port_bw = 0;
                master_limiter.emi_bw.md2g3g_port_bw = 5;
                master_limiter.emi_bw.mm_port_bw = 26;
                master_limiter.emi_bw.dmadgbaud_port_bw = 19;
            
                /**
                   * Determine soft mode or hard mode for bandwidth allocation.
                   */    
                master_limiter.emi_softmode.mcu_port_softmode = 1;
                master_limiter.emi_softmode.fcore_port_softmode = 1;
                master_limiter.emi_softmode.fcoredma_port_softmode = 1;
                master_limiter.emi_softmode.md2g3g_port_softmode = 0;
                master_limiter.emi_softmode.mm_port_softmode = 0;
                master_limiter.emi_softmode.dmadgbaud_port_softmode = 0;
                break;
        
            case SS_FCORE_LOGGING:
                /**
                    * Only for USB logging in eng. mode
                    */

                /**
                   * Determine bandwidth allocation.
                   */
                master_limiter.emi_bw.mcu_port_bw = 30;
                master_limiter.emi_bw.fcore_port_bw = 30;
                master_limiter.emi_bw.fcoredma_port_bw = 0;
                master_limiter.emi_bw.md2g3g_port_bw = 5;
                master_limiter.emi_bw.mm_port_bw = 22;
                master_limiter.emi_bw.dmadgbaud_port_bw = 13;
            
                /**
                   * Determine soft mode or hard mode for bandwidth allocation.
                   */    
                master_limiter.emi_softmode.mcu_port_softmode = 1;
                master_limiter.emi_softmode.fcore_port_softmode = 1;
                master_limiter.emi_softmode.fcoredma_port_softmode = 1;
                master_limiter.emi_softmode.md2g3g_port_softmode = 0;
                master_limiter.emi_softmode.mm_port_softmode = 1;
                master_limiter.emi_softmode.dmadgbaud_port_softmode = 0;

                is_fcore_logging = 1;

                break;

            default:
                ret = -1;
                break;


#else /* MT6276_S00 */

            case MM_SCE_MMI:
                /**
                    * This scenario switches back to normal EMI bandwidth allocation.
                    */

                /**
                   * Determine bandwidth allocation.
                   */
                master_limiter.emi_bw.mcu_port_bw = 30;
                master_limiter.emi_bw.fcore_port_bw = 14;
                master_limiter.emi_bw.md2g3gauddbg_port_bw = 6;
                master_limiter.emi_bw.peri_port_bw = 8;
                master_limiter.emi_bw.mm_port_bw = 42;
            
                /**
                   * Determine soft mode or hard mode for bandwidth allocation.
                   */    
                master_limiter.emi_softmode.mcu_port_softmode = 1;
                master_limiter.emi_softmode.fcore_port_softmode = 1;
                master_limiter.emi_softmode.md2g3gauddbg_port_softmode = 0;
                master_limiter.emi_softmode.peri_port_softmode = 1;
                master_limiter.emi_softmode.mm_port_softmode = 0;

                break;

            case MM_SCE_CAM_PREV:
                /**
                   * Determine bandwidth allocation.
                   */
                master_limiter.emi_bw.mcu_port_bw = 30;
                master_limiter.emi_bw.fcore_port_bw = 10;
                master_limiter.emi_bw.md2g3gauddbg_port_bw = 6;
                master_limiter.emi_bw.peri_port_bw = 12;
                master_limiter.emi_bw.mm_port_bw = 42;
            
                /**
                   * Determine soft mode or hard mode for bandwidth allocation.
                   */    
                master_limiter.emi_softmode.mcu_port_softmode = 1;
                master_limiter.emi_softmode.fcore_port_softmode = 1;
                master_limiter.emi_softmode.md2g3gauddbg_port_softmode = 0;
                master_limiter.emi_softmode.peri_port_softmode = 1;
                master_limiter.emi_softmode.mm_port_softmode = 0;

                break;
    
            case MM_SCE_CAP:
                /**
                   * Determine bandwidth allocation.
                   */
                master_limiter.emi_bw.mcu_port_bw = 30;
                master_limiter.emi_bw.fcore_port_bw = 10;
                master_limiter.emi_bw.md2g3gauddbg_port_bw = 6;
                master_limiter.emi_bw.peri_port_bw = 12;
                master_limiter.emi_bw.mm_port_bw = 42;
            
                /**
                   * Determine soft mode or hard mode for bandwidth allocation.
                   */    
                master_limiter.emi_softmode.mcu_port_softmode = 1;
                master_limiter.emi_softmode.fcore_port_softmode = 1;
                master_limiter.emi_softmode.md2g3gauddbg_port_softmode = 0;
                master_limiter.emi_softmode.peri_port_softmode = 1;
                master_limiter.emi_softmode.mm_port_softmode = 0;

                break;
          
            case MM_SCE_VIDEO_REC:
                /**
                   * Determine bandwidth allocation.
                   */
                master_limiter.emi_bw.mcu_port_bw = 30;
                master_limiter.emi_bw.fcore_port_bw = 17;
                master_limiter.emi_bw.md2g3gauddbg_port_bw = 6;
                master_limiter.emi_bw.peri_port_bw = 10;
                master_limiter.emi_bw.mm_port_bw = 37;
            
                /**
                   * Determine soft mode or hard mode for bandwidth allocation.
                   */    
                master_limiter.emi_softmode.mcu_port_softmode = 1;
                master_limiter.emi_softmode.fcore_port_softmode = 1;
                master_limiter.emi_softmode.md2g3gauddbg_port_softmode = 0;
                master_limiter.emi_softmode.peri_port_softmode = 1;
                master_limiter.emi_softmode.mm_port_softmode = 0;

                break;
    
            case MM_SCE_VIDEO_PLAY:
                /**
                   * Determine bandwidth allocation.
                   */
                master_limiter.emi_bw.mcu_port_bw = 30;
                master_limiter.emi_bw.fcore_port_bw = 17;
                master_limiter.emi_bw.md2g3gauddbg_port_bw = 6;
                master_limiter.emi_bw.peri_port_bw = 10;
                master_limiter.emi_bw.mm_port_bw = 37;
            
                /**
                   * Determine soft mode or hard mode for bandwidth allocation.
                   */    
                master_limiter.emi_softmode.mcu_port_softmode = 1;
                master_limiter.emi_softmode.fcore_port_softmode = 1;
                master_limiter.emi_softmode.md2g3gauddbg_port_softmode = 0;
                master_limiter.emi_softmode.peri_port_softmode = 1;
                master_limiter.emi_softmode.mm_port_softmode = 0;

                break;
        
            case SS_FCORE_LOGGING:
                /**
                    * Only for USB logging in eng. mode
                    */

                /**
                   * Determine bandwidth allocation.
                   */
                master_limiter.emi_bw.mcu_port_bw = 30;
                master_limiter.emi_bw.fcore_port_bw = 30;
                master_limiter.emi_bw.md2g3gauddbg_port_bw = 6;
                master_limiter.emi_bw.peri_port_bw = 8;
                master_limiter.emi_bw.mm_port_bw = 26;
            
                /**
                   * Determine soft mode or hard mode for bandwidth allocation.
                   */    
                master_limiter.emi_softmode.mcu_port_softmode = 1;
                master_limiter.emi_softmode.fcore_port_softmode = 1;
                master_limiter.emi_softmode.md2g3gauddbg_port_softmode = 0;
                master_limiter.emi_softmode.peri_port_softmode = 1;
                master_limiter.emi_softmode.mm_port_softmode = 1;

                is_fcore_logging = 1;

                break;

            default:
                ret = -1;
                break;

#endif /* MT6276_S00 */

        }
    }
    else 
    {
        /**
            * MT6276 + ADMUX.
            * We do not support ADMUX bandwidth control at this stage since the ADMUX's bandwidth requirement is insufficient on ADMUX device.
            */
        ASSERT(0);        
    }

    /**
       * Set EMI bandwidth settings according to requested scenarios.
       */
    ASSERT(0 == __EMI_SetBW(&master_limiter));
  

#elif defined(MT6256) /* MT6236 || MT6236B */

    /***************
      *
      * MT6256 chip
      *
      **************/

    EMI_MASTER_LIMITER master_limiter;
    kal_bool isSystemInit;

    isSystemInit = kal_query_systemInit();

    if (isSystemInit == KAL_TRUE)
    {
         return ret;         
    }

    if ((KAL_TRUE ==  kal_if_hisr()) || (KAL_TRUE ==  kal_if_lisr()))
    {
         ASSERT(0);
    }

    if (0 == EMI_sem)
    {
        EMI_sem = kal_create_sem("EMI_SEMA", 1);
    }
    
    kal_take_sem(EMI_sem, KAL_INFINITE_WAIT);
    
    /**
       * Get current EMI bandwidth settings.
       */
    ASSERT(0 == __EMI_GetBW(&master_limiter));

    if (custom_ifLPSDRAM() == KAL_TRUE)    
    {

        #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif 
        
        /**
           * MT6256 + DDRx16.
           * The MM's EMI BW is based on MM designer's simulation result.
           */

        switch (scenario) 
        {
            case MM_SCE_MMI:
                /**
                    * This scenario switches back to normal EMI bandwidth allocation.
                    */

                /**
                   * Determine bandwidth allocation.
                   */
                master_limiter.emi_bw.mcu_port_bw = 24;
                master_limiter.emi_bw.mm_port_bw = 47;
                master_limiter.emi_bw.dma_port_bw = 2;
                master_limiter.emi_bw.md2g_peri_port_bw = 7;
                master_limiter.emi_bw.dsp_port_bw = 8;
                master_limiter.emi_bw.graphic_port_bw = 12;

                if  (1 == is_3D_MMI)
                {
                    master_limiter.emi_bw.mm_port_bw = 12;
                    master_limiter.emi_bw.graphic_port_bw = 47;
                }
                /**
                   * Determine soft mode or hard mode for bandwidth allocation.
                   */    
                master_limiter.emi_softmode.mcu_port_softmode = 1;
                master_limiter.emi_softmode.mm_port_softmode = 0;
                master_limiter.emi_softmode.dma_port_softmode = 1;
                master_limiter.emi_softmode.md2g_peri_port_softmode = 1;
                master_limiter.emi_softmode.dsp_port_softmode = 1;
                master_limiter.emi_softmode.graphic_port_softmode = 0;

                is_MM_Scenario = 0;
                
                break;

            case MM_SCE_MMI_3D:
                /**
                    * This scenario set more EMI BW to MM under MMI scenario.
                    */
                is_3D_MMI = 1;
                
                if (1 ==  is_MM_Scenario)  //Under MM scenario, DON'T change BW setting until exit MM scenario
                {
                   kal_give_sem(EMI_sem);
                   return ret;
                }

                /**
                   * Modify MM & Graphic BW setting under MMI sceanrio
                   */
                if (1 ==  is_3D_MMI_2_LAYER_LCD)
                {
                    //master_limiter.emi_bw.mcu_port_bw = 24;
                    master_limiter.emi_bw.mm_port_bw = 24;
                    //master_limiter.emi_bw.dma_port_bw = 2;
                    //master_limiter.emi_bw.md2g_peri_port_bw = 7;
                    //master_limiter.emi_bw.dsp_port_bw = 8;
                    master_limiter.emi_bw.graphic_port_bw = 35;
                }
                else if (0 ==  is_3D_MMI_2_LAYER_LCD)
                {
                //master_limiter.emi_bw.mcu_port_bw = 24;
                master_limiter.emi_bw.mm_port_bw = 12;
                //master_limiter.emi_bw.dma_port_bw = 2;
                //master_limiter.emi_bw.md2g_peri_port_bw = 7;
                //master_limiter.emi_bw.dsp_port_bw = 8;
                master_limiter.emi_bw.graphic_port_bw = 47;
                }
                else
                {
                     ASSERT(0);
                }

                break;

            case MM_SCE_MMI_2D:
                /**
                    * This scenario set more EMI BW to Graphic under MMI scenario.
                    */
                 is_3D_MMI = 0;

                if (1 ==  is_MM_Scenario)   //Under MM scenario, DON'T change BW setting until exit MM scenario
                {
                   kal_give_sem(EMI_sem);
                   return ret;
                }

                /**
                   * Modify MM & Graphic BW setting under MMI sceanrio
                   */
                //master_limiter.emi_bw.mcu_port_bw = 24;
                master_limiter.emi_bw.mm_port_bw = 47;
                //master_limiter.emi_bw.dma_port_bw = 2;
                //master_limiter.emi_bw.md2g_peri_port_bw = 7;
                //master_limiter.emi_bw.dsp_port_bw = 8;
                master_limiter.emi_bw.graphic_port_bw = 12;

                break;

            case MM_SCE_MMI_3D_1_LCD_LAYER:
                /**
                    * This scenario set more EMI BW to MM under MMI scenario.
                    */
                is_3D_MMI_2_LAYER_LCD = 0;
                
                if ((1 ==  is_MM_Scenario) || (0 == is_3D_MMI)) //Under MM scenario or not 3D MMI, DON'T change BW setting until exit MM scenario
                {
                   kal_give_sem(EMI_sem);
                   return ret;
                }

                /**
                   * Modify MM & Graphic BW setting under MMI sceanrio
                   */
                //master_limiter.emi_bw.mcu_port_bw = 24;
                master_limiter.emi_bw.mm_port_bw = 12;
                //master_limiter.emi_bw.dma_port_bw = 2;
                //master_limiter.emi_bw.md2g_peri_port_bw = 7;
                //master_limiter.emi_bw.dsp_port_bw = 8;
                master_limiter.emi_bw.graphic_port_bw = 47;

                break;

            case MM_SCE_MMI_3D_2_LCD_LAYER:
                /**
                    * This scenario set more EMI BW to MM under MMI scenario.
                    */
                is_3D_MMI_2_LAYER_LCD = 1;
                
                if ((1 ==  is_MM_Scenario) || (0 == is_3D_MMI)) //Under MM scenario or not 3D MMI, DON'T change BW setting until exit MM scenario
                {
                   kal_give_sem(EMI_sem);
                   return ret;
                }

                /**
                   * Modify MM & Graphic BW setting under MMI sceanrio
                   */
                //master_limiter.emi_bw.mcu_port_bw = 24;
                master_limiter.emi_bw.mm_port_bw = 24;
                //master_limiter.emi_bw.dma_port_bw = 2;
                //master_limiter.emi_bw.md2g_peri_port_bw = 7;
                //master_limiter.emi_bw.dsp_port_bw = 8;
                master_limiter.emi_bw.graphic_port_bw = 35;

                break;

            case MM_SCE_CAM_PREV:
                /**
                   * Determine bandwidth allocation.
                   */
                master_limiter.emi_bw.mcu_port_bw = 24;
                master_limiter.emi_bw.mm_port_bw = 47;
                master_limiter.emi_bw.dma_port_bw = 2;
                master_limiter.emi_bw.md2g_peri_port_bw = 7;
                master_limiter.emi_bw.dsp_port_bw = 8;
                master_limiter.emi_bw.graphic_port_bw = 12;

                /**
                   * Determine soft mode or hard mode for bandwidth allocation.
                   */    
                master_limiter.emi_softmode.mcu_port_softmode = 1;
                master_limiter.emi_softmode.mm_port_softmode = 0;
                master_limiter.emi_softmode.dma_port_softmode = 1;
                master_limiter.emi_softmode.md2g_peri_port_softmode = 1;
                master_limiter.emi_softmode.dsp_port_softmode = 1;
                master_limiter.emi_softmode.graphic_port_softmode = 1;

                is_MM_Scenario = 1;

                break;
    
            case MM_SCE_CAP:
                /**
                   * Determine bandwidth allocation.
                   */
                master_limiter.emi_bw.mcu_port_bw = 24;
                master_limiter.emi_bw.mm_port_bw = 44;
                master_limiter.emi_bw.dma_port_bw = 2;
                master_limiter.emi_bw.md2g_peri_port_bw = 10;
                master_limiter.emi_bw.dsp_port_bw = 8;
                master_limiter.emi_bw.graphic_port_bw = 12;

                /**
                   * Determine soft mode or hard mode for bandwidth allocation.
                   */    
                master_limiter.emi_softmode.mcu_port_softmode = 1;
                master_limiter.emi_softmode.mm_port_softmode = 0;
                master_limiter.emi_softmode.dma_port_softmode = 1;
                master_limiter.emi_softmode.md2g_peri_port_softmode = 1;
                master_limiter.emi_softmode.dsp_port_softmode = 1;
                master_limiter.emi_softmode.graphic_port_softmode = 1;

                is_MM_Scenario = 1;

                break;
          
            case MM_SCE_VIDEO_REC:
                /**
                   * Determine bandwidth allocation.
                   */
                master_limiter.emi_bw.mcu_port_bw = 24;
                master_limiter.emi_bw.mm_port_bw = 47;
                master_limiter.emi_bw.dma_port_bw = 2;
                master_limiter.emi_bw.md2g_peri_port_bw = 7;
                master_limiter.emi_bw.dsp_port_bw = 8;
                master_limiter.emi_bw.graphic_port_bw = 12;

                /**
                   * Determine soft mode or hard mode for bandwidth allocation.
                   */    
                master_limiter.emi_softmode.mcu_port_softmode = 1;
                master_limiter.emi_softmode.mm_port_softmode = 0;
                master_limiter.emi_softmode.dma_port_softmode = 1;
                master_limiter.emi_softmode.md2g_peri_port_softmode = 1;
                master_limiter.emi_softmode.dsp_port_softmode = 1;
                master_limiter.emi_softmode.graphic_port_softmode = 1;

                is_MM_Scenario = 1;

                break;
    
            case MM_SCE_VIDEO_PLAY:
                /**
                   * Determine bandwidth allocation.
                   */
                master_limiter.emi_bw.mcu_port_bw = 24;
                master_limiter.emi_bw.mm_port_bw = 44;
                master_limiter.emi_bw.dma_port_bw = 2;
                master_limiter.emi_bw.md2g_peri_port_bw = 8;
                master_limiter.emi_bw.dsp_port_bw = 8;
                master_limiter.emi_bw.graphic_port_bw = 12;

                /**
                   * Determine soft mode or hard mode for bandwidth allocation.
                   */    
                master_limiter.emi_softmode.mcu_port_softmode = 1;
                master_limiter.emi_softmode.mm_port_softmode = 0;
                master_limiter.emi_softmode.dma_port_softmode = 1;
                master_limiter.emi_softmode.md2g_peri_port_softmode = 1;
                master_limiter.emi_softmode.dsp_port_softmode = 1;
                master_limiter.emi_softmode.graphic_port_softmode = 1;

                is_MM_Scenario = 1;

                break;

            case MM_SCE_VLW:
                /**
                   * Determine bandwidth allocation.
                   */
                master_limiter.emi_bw.mcu_port_bw = 24;
                master_limiter.emi_bw.mm_port_bw = 38;
                master_limiter.emi_bw.dma_port_bw = 2;
                master_limiter.emi_bw.md2g_peri_port_bw = 9;
                master_limiter.emi_bw.dsp_port_bw = 8;
                master_limiter.emi_bw.graphic_port_bw = 18;

                /**
                   * Determine soft mode or hard mode for bandwidth allocation.
                   */    
                master_limiter.emi_softmode.mcu_port_softmode = 1;
                master_limiter.emi_softmode.mm_port_softmode = 0;
                master_limiter.emi_softmode.dma_port_softmode = 1;
                master_limiter.emi_softmode.md2g_peri_port_softmode = 1;
                master_limiter.emi_softmode.dsp_port_softmode = 1;
                master_limiter.emi_softmode.graphic_port_softmode = 1;

                is_MM_Scenario = 1;

                break;

            case MM_SCE_VIDEO_PLAY_HVGA:
                /**
                   * Determine bandwidth allocation.
                   */
                master_limiter.emi_bw.mcu_port_bw = 24;
                master_limiter.emi_bw.mm_port_bw = 25;
                master_limiter.emi_bw.dma_port_bw = 2;
                master_limiter.emi_bw.md2g_peri_port_bw = 9;
                master_limiter.emi_bw.dsp_port_bw = 8;
                master_limiter.emi_bw.graphic_port_bw = 31;

                /**
                   * Determine soft mode or hard mode for bandwidth allocation.
                   */    
                master_limiter.emi_softmode.mcu_port_softmode = 1;
                master_limiter.emi_softmode.mm_port_softmode = 0;
                master_limiter.emi_softmode.dma_port_softmode = 1;
                master_limiter.emi_softmode.md2g_peri_port_softmode = 1;
                master_limiter.emi_softmode.dsp_port_softmode = 1;
                master_limiter.emi_softmode.graphic_port_softmode = 1;

                is_MM_Scenario = 1;

                break;

            case MM_SCE_CAM_PREV_HVGA:
                /**
                   * Determine bandwidth allocation.
                   */
                master_limiter.emi_bw.mcu_port_bw = 24;
                master_limiter.emi_bw.mm_port_bw = 26;
                master_limiter.emi_bw.dma_port_bw = 2;
                master_limiter.emi_bw.md2g_peri_port_bw = 7;
                master_limiter.emi_bw.dsp_port_bw = 8;
                master_limiter.emi_bw.graphic_port_bw = 33;

                /**
                   * Determine soft mode or hard mode for bandwidth allocation.
                   */    
                master_limiter.emi_softmode.mcu_port_softmode = 1;
                master_limiter.emi_softmode.mm_port_softmode = 0;
                master_limiter.emi_softmode.dma_port_softmode = 1;
                master_limiter.emi_softmode.md2g_peri_port_softmode = 1;
                master_limiter.emi_softmode.dsp_port_softmode = 1;
                master_limiter.emi_softmode.graphic_port_softmode = 1;

                is_MM_Scenario = 1;

                break;

            case MM_SCE_VLW_HVGA:
                /**
                   * Determine bandwidth allocation.
                   */
                master_limiter.emi_bw.mcu_port_bw = 24;
                master_limiter.emi_bw.mm_port_bw = 23;
                master_limiter.emi_bw.dma_port_bw = 2;
                master_limiter.emi_bw.md2g_peri_port_bw = 9;
                master_limiter.emi_bw.dsp_port_bw = 8;
                master_limiter.emi_bw.graphic_port_bw = 33;

                /**
                   * Determine soft mode or hard mode for bandwidth allocation.
                   */    
                master_limiter.emi_softmode.mcu_port_softmode = 1;
                master_limiter.emi_softmode.mm_port_softmode = 0;
                master_limiter.emi_softmode.dma_port_softmode = 1;
                master_limiter.emi_softmode.md2g_peri_port_softmode = 1;
                master_limiter.emi_softmode.dsp_port_softmode = 1;
                master_limiter.emi_softmode.graphic_port_softmode = 1;

                is_MM_Scenario = 1;

                break;


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
       #endif 
       
            default:
                ret = -1;
                break;

        }
    }
    else 
    {
        /**
            * MT6256 + ADMUX.
            * We do not support ADMUX bandwidth control at this stage since the ADMUX's bandwidth requirement is insufficient on ADMUX device.
            */
        ASSERT(0);        
    }

    /**
       * Set EMI bandwidth settings according to requested scenarios.
       */
    ASSERT(0 == __EMI_SetBW(&master_limiter));

     kal_give_sem(EMI_sem);
#elif defined(MT6255)

#else /* MT6236 || MT6236B */

    /**
       * Do nothing for those BB does not support dynamic EMI BW allocation mechanism.
       */

#endif /* MT6236 || MT6236B */

    return ret;
    
#endif /* __EMI_NO_DRIVER__ */

}

#endif  /* __EMI_INTERNAL_NECESSARY_DRIVER__ */

#endif //#if ( !defined(__UBL__)) 

/*************************************************************************
* FUNCTION
*  INT_EnableEmiB2S
*
* DESCRIPTION
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*  None
*
* RETURNS
*  0
*
*************************************************************************/

#if defined(__EMI_INTERNAL_NECESSARY_DRIVER__)

/**
   * !!! I will phase out this driver.
   */

#if defined(MT6253) || defined(MT6252H) || defined(MT6252) || defined(MT6253E) || defined(MT6253L)

void INT_EnableEmiB2S(void)
{
#if defined(__EMI_NO_DRIVER__)	 

   return;

#else /* __EMI_NO_DRIVER__ */

   /**
     * After re-testing MT6253D concurrency, the B2S functionality does not need to be enabled.
     * We will ask L1 to remove the function call after MT6253D WT cache QC done.
     */	
   //*EMI_GEN2 |= 0x00000010;

#endif /* __EMI_NO_DRIVER__ */

}

#endif	/* MT6253 || MT6252H || MT6252 || MT6253E || MT6253L */

#endif  /* __EMI_INTERNAL_NECESSARY_DRIVER__ */


/*************************************************************************
* FUNCTION
*  INT_DisableEmiB2S
*
* DESCRIPTION
*  This function used to gate DMA and GMC.
*  NoteXXX: This function is dedicated for IDLE.
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*  None
*
* RETURNS
*  0
*
*************************************************************************/

#if defined(__EMI_INTERNAL_NECESSARY_DRIVER__)

/**
   * !!! I will phase out this driver.
   */


#if defined(MT6253) || defined(MT6252H) || defined(MT6252) || defined(MT6253E) || defined(MT6253L)

void INT_DisableEmiB2S(void)
{
#if defined(__EMI_NO_DRIVER__)	 

   return;

#else /* __EMI_NO_DRIVER__ */

   /**
     * After re-testing MT6253D concurrency, the B2S functionality does not need to be enabled.
     * We will ask L1 to remove the function call after MT6253D WT cache QC done.
     */		
   //*EMI_GEN2 &= ~0x00000010;

#endif /* __EMI_NO_DRIVER__ */

}

#endif	/* MT6253 || MT6252H || MT6252 || MT6253E || MT6253L */

#endif  /* __EMI_INTERNAL_NECESSARY_DRIVER__ */


/*************************************************************************
* FUNCTION
*
*  __EMI_SetBW
*
* DESCRIPTION
*  This function sets EMI arbitrator for GMC.
*
* PARAMETERS
*  master_limiter  - applications used to set the emi bw setting.
*
* RETURNS
*  0 for success; negative value for failure
*
*************************************************************************/

#if defined(__EMI_INTERNAL_NECESSARY_DRIVER__)

kal_int32 __EMI_SetBW(EMI_MASTER_LIMITER *master_limiter)
{
#if defined(__EMI_NO_DRIVER__)	 

   //ret = -1;
   return -1;

#else /* __EMI_NO_DRIVER__ */

    kal_int32 ret = 0;
    kal_int32 irq_mask = 0;

#if !defined(MT6280)
    volatile kal_uint32 arb_val; // volatile to avoid compile warning
#endif

    irq_mask = SaveAndSetIRQMask();
    {

#if defined(MT6236) || defined(MT6236B)
  
        /**
           * Set EMI bandwidth and soft/hard mode.
           */
        arb_val = *EMI_ARBA & ~(EMI_BW_MAX_GNT_CNT_MARK | EMI_BW_SOFT_MODE_MARK);
        *EMI_ARBA = arb_val | ((((master_limiter->emi_bw).mcu_port_bw * EMI_BW_PERCENT_TRANS_TO_REGISTER) / EMI_BW_PERCENT_SCALE) | ((master_limiter->emi_softmode).mcu_port_softmode << EMI_BW_SOFTMODE_BIT_OFFSET));
        
        arb_val = *EMI_ARBC & ~(EMI_BW_MAX_GNT_CNT_MARK | EMI_BW_SOFT_MODE_MARK);
        *EMI_ARBC = arb_val | (((master_limiter->emi_bw).mcu_port_bw * EMI_BW_PERCENT_TRANS_TO_REGISTER) / EMI_BW_PERCENT_SCALE | ((master_limiter->emi_softmode).mcu_port_softmode << EMI_BW_SOFTMODE_BIT_OFFSET));
    
        arb_val = *EMI_ARBB & ~(EMI_BW_MAX_GNT_CNT_MARK | EMI_BW_SOFT_MODE_MARK);
        *EMI_ARBB = arb_val | (((master_limiter->emi_bw).dma_port_bw * EMI_BW_PERCENT_TRANS_TO_REGISTER) / EMI_BW_PERCENT_SCALE | ((master_limiter->emi_softmode).dma_port_softmode << EMI_BW_SOFTMODE_BIT_OFFSET));
    
        arb_val = *EMI_ARBH & ~(EMI_BW_MAX_GNT_CNT_MARK | EMI_BW_SOFT_MODE_MARK);
        *EMI_ARBH = arb_val | (((master_limiter->emi_bw).gmc1_port_bw * EMI_BW_PERCENT_TRANS_TO_REGISTER) / EMI_BW_PERCENT_SCALE | ((master_limiter->emi_softmode).gmc1_port_softmode << EMI_BW_SOFTMODE_BIT_OFFSET));
    
        arb_val = *EMI_ARBI & ~(EMI_BW_MAX_GNT_CNT_MARK | EMI_BW_SOFT_MODE_MARK);
        *EMI_ARBI = arb_val | (((master_limiter->emi_bw).gmc2_port_bw * EMI_BW_PERCENT_TRANS_TO_REGISTER) / EMI_BW_PERCENT_SCALE | ((master_limiter->emi_softmode).gmc2_port_softmode << EMI_BW_SOFTMODE_BIT_OFFSET));

#elif defined(MT6276) /* MT6236 || MT6236B */

#if defined(MT6276_S00)

        /**
           * Set EMI bandwidth and soft/hard mode.
           */
        arb_val = *EMI_ARBA & ~(EMI_BW_MAX_GNT_CNT_MARK | EMI_BW_SOFT_MODE_MARK);
        *EMI_ARBA = arb_val | ((((master_limiter->emi_bw).mcu_port_bw * EMI_BW_PERCENT_TRANS_TO_REGISTER) / EMI_BW_PERCENT_SCALE) | ((master_limiter->emi_softmode).mcu_port_softmode << EMI_BW_SOFTMODE_BIT_OFFSET));
    
        arb_val = *EMI_ARBB & ~(EMI_BW_MAX_GNT_CNT_MARK | EMI_BW_SOFT_MODE_MARK);
        *EMI_ARBB = arb_val | (((master_limiter->emi_bw).fcore_port_bw * EMI_BW_PERCENT_TRANS_TO_REGISTER) / EMI_BW_PERCENT_SCALE | ((master_limiter->emi_softmode).fcore_port_softmode << EMI_BW_SOFTMODE_BIT_OFFSET));
    
        arb_val = *EMI_ARBC & ~(EMI_BW_MAX_GNT_CNT_MARK | EMI_BW_SOFT_MODE_MARK);
        *EMI_ARBC = arb_val | (((master_limiter->emi_bw).fcoredma_port_bw * EMI_BW_PERCENT_TRANS_TO_REGISTER) / EMI_BW_PERCENT_SCALE | ((master_limiter->emi_softmode).fcoredma_port_softmode << EMI_BW_SOFTMODE_BIT_OFFSET));
    
        arb_val = *EMI_ARBD & ~(EMI_BW_MAX_GNT_CNT_MARK | EMI_BW_SOFT_MODE_MARK);
        *EMI_ARBD = arb_val | (((master_limiter->emi_bw).md2g3g_port_bw * EMI_BW_PERCENT_TRANS_TO_REGISTER) / EMI_BW_PERCENT_SCALE | ((master_limiter->emi_softmode).md2g3g_port_softmode << EMI_BW_SOFTMODE_BIT_OFFSET));
    
        arb_val = *EMI_ARBE & ~(EMI_BW_MAX_GNT_CNT_MARK | EMI_BW_SOFT_MODE_MARK);
        *EMI_ARBE = arb_val | (((master_limiter->emi_bw).mm_port_bw * EMI_BW_PERCENT_TRANS_TO_REGISTER) / EMI_BW_PERCENT_SCALE | ((master_limiter->emi_softmode).mm_port_softmode << EMI_BW_SOFTMODE_BIT_OFFSET));
    
        arb_val = *EMI_ARBF & ~(EMI_BW_MAX_GNT_CNT_MARK | EMI_BW_SOFT_MODE_MARK);
        *EMI_ARBF = arb_val | (((master_limiter->emi_bw).dmadgbaud_port_bw * EMI_BW_PERCENT_TRANS_TO_REGISTER) / EMI_BW_PERCENT_SCALE | ((master_limiter->emi_softmode).dmadgbaud_port_softmode << EMI_BW_SOFTMODE_BIT_OFFSET));

#else /* MT6276_S00 */

        /**
           * Set EMI bandwidth and soft/hard mode.
           */
        arb_val = *EMI_ARBA & ~(EMI_BW_MAX_GNT_CNT_MARK | EMI_BW_SOFT_MODE_MARK);
        *EMI_ARBA = arb_val | ((((master_limiter->emi_bw).mcu_port_bw * EMI_BW_PERCENT_TRANS_TO_REGISTER) / EMI_BW_PERCENT_SCALE) | ((master_limiter->emi_softmode).mcu_port_softmode << EMI_BW_SOFTMODE_BIT_OFFSET));
    
        arb_val = *EMI_ARBB & ~(EMI_BW_MAX_GNT_CNT_MARK | EMI_BW_SOFT_MODE_MARK);
        *EMI_ARBB = arb_val | (((master_limiter->emi_bw).fcore_port_bw * EMI_BW_PERCENT_TRANS_TO_REGISTER) / EMI_BW_PERCENT_SCALE | ((master_limiter->emi_softmode).fcore_port_softmode << EMI_BW_SOFTMODE_BIT_OFFSET));
    
        arb_val = *EMI_ARBC & ~(EMI_BW_MAX_GNT_CNT_MARK | EMI_BW_SOFT_MODE_MARK);
        *EMI_ARBC = arb_val | (((master_limiter->emi_bw).md2g3gauddbg_port_bw * EMI_BW_PERCENT_TRANS_TO_REGISTER) / EMI_BW_PERCENT_SCALE | ((master_limiter->emi_softmode).md2g3gauddbg_port_softmode << EMI_BW_SOFTMODE_BIT_OFFSET));
    
        arb_val = *EMI_ARBD & ~(EMI_BW_MAX_GNT_CNT_MARK | EMI_BW_SOFT_MODE_MARK);
        *EMI_ARBD = arb_val | (((master_limiter->emi_bw).peri_port_bw * EMI_BW_PERCENT_TRANS_TO_REGISTER) / EMI_BW_PERCENT_SCALE | ((master_limiter->emi_softmode).peri_port_softmode << EMI_BW_SOFTMODE_BIT_OFFSET));
    
        arb_val = *EMI_ARBE & ~(EMI_BW_MAX_GNT_CNT_MARK | EMI_BW_SOFT_MODE_MARK);
        *EMI_ARBE = arb_val | (((master_limiter->emi_bw).mm_port_bw * EMI_BW_PERCENT_TRANS_TO_REGISTER) / EMI_BW_PERCENT_SCALE | ((master_limiter->emi_softmode).mm_port_softmode << EMI_BW_SOFTMODE_BIT_OFFSET));
    

#endif /* MT6276_S00 */

#elif defined(MT6256) /* MT6236 || MT6236B */

        /**
           * Set EMI bandwidth and soft/hard mode.
           */
#if defined(__DYNAMICALLY_SET_EMI_ARB_SOFT_MODE__)
        Graphic_EMI_BW_Mode = ((master_limiter->emi_softmode).graphic_port_softmode << EMI_BW_SOFTMODE_BIT_OFFSET);

        if (RunTimeConfigCnt > 0)  //in hard run time
        {
            Set_EMI_BW_Graphic_Mode = 0;  //hard mode
        }
        else
        {
            Set_EMI_BW_Graphic_Mode = Graphic_EMI_BW_Mode;
        }
#endif       

        arb_val = *EMI_ARBA & ~(EMI_BW_MAX_GNT_CNT_MARK | EMI_BW_SOFT_MODE_MARK);
        *EMI_ARBA = arb_val | ((((master_limiter->emi_bw).mcu_port_bw * EMI_BW_PERCENT_TRANS_TO_REGISTER) / EMI_BW_PERCENT_SCALE) | ((master_limiter->emi_softmode).mcu_port_softmode << EMI_BW_SOFTMODE_BIT_OFFSET));
    
        arb_val = *EMI_ARBB & ~(EMI_BW_MAX_GNT_CNT_MARK | EMI_BW_SOFT_MODE_MARK);
        *EMI_ARBB = arb_val | (((master_limiter->emi_bw).mm_port_bw * EMI_BW_PERCENT_TRANS_TO_REGISTER) / EMI_BW_PERCENT_SCALE | ((master_limiter->emi_softmode).mm_port_softmode << EMI_BW_SOFTMODE_BIT_OFFSET));
    
        arb_val = *EMI_ARBC & ~(EMI_BW_MAX_GNT_CNT_MARK | EMI_BW_SOFT_MODE_MARK);
        *EMI_ARBC = arb_val | (((master_limiter->emi_bw).dma_port_bw * EMI_BW_PERCENT_TRANS_TO_REGISTER) / EMI_BW_PERCENT_SCALE | ((master_limiter->emi_softmode).dma_port_softmode << EMI_BW_SOFTMODE_BIT_OFFSET));
    
        arb_val = *EMI_ARBD & ~(EMI_BW_MAX_GNT_CNT_MARK | EMI_BW_SOFT_MODE_MARK);
        *EMI_ARBD = arb_val | (((master_limiter->emi_bw).md2g_peri_port_bw * EMI_BW_PERCENT_TRANS_TO_REGISTER) / EMI_BW_PERCENT_SCALE | ((master_limiter->emi_softmode).md2g_peri_port_softmode << EMI_BW_SOFTMODE_BIT_OFFSET));
 
        arb_val = *EMI_ARBE & ~(EMI_BW_MAX_GNT_CNT_MARK | EMI_BW_SOFT_MODE_MARK);
        *EMI_ARBE = arb_val | (((master_limiter->emi_bw).dsp_port_bw * EMI_BW_PERCENT_TRANS_TO_REGISTER) / EMI_BW_PERCENT_SCALE | ((master_limiter->emi_softmode).dsp_port_softmode << EMI_BW_SOFTMODE_BIT_OFFSET));
    
#if defined(__DYNAMICALLY_SET_EMI_ARB_SOFT_MODE__)
        arb_val = *EMI_ARBF & ~(EMI_BW_MAX_GNT_CNT_MARK);  //only modify BW setting, soft/hard mode will be set on RestoreIRQMask(irq_mask) by Set_EMI_BW_Graphic_Mode
        *EMI_ARBF = arb_val | (((master_limiter->emi_bw).graphic_port_bw * EMI_BW_PERCENT_TRANS_TO_REGISTER) / EMI_BW_PERCENT_SCALE);
#else
        arb_val = *EMI_ARBF & ~(EMI_BW_MAX_GNT_CNT_MARK | EMI_BW_SOFT_MODE_MARK);
        *EMI_ARBF = arb_val | (((master_limiter->emi_bw).graphic_port_bw * EMI_BW_PERCENT_TRANS_TO_REGISTER) / EMI_BW_PERCENT_SCALE | ((master_limiter->emi_softmode).graphic_port_softmode << EMI_BW_SOFTMODE_BIT_OFFSET));
#endif   
   

#elif defined(MT6255)
#else /* MT6236 || MT6236B */
        /**
           * Do nothing for those BB does not support dynamic EMI BW allocation mechanism.
           */

#endif /* MT6236 || MT6236B */

    }
    RestoreIRQMask(irq_mask);  //for MT6256, it will set Graphic mode by Set_EMI_BW_Graphic_Mode

    return ret;
    
#endif /* __EMI_NO_DRIVER__ */

}

#endif  /* __EMI_INTERNAL_NECESSARY_DRIVER__ */



/*************************************************************************
* FUNCTION
*
*  __EMI_SetBW
*
* DESCRIPTION
*  This function gets EMI arbitrator for GMC.
*
* PARAMETERS
*  master_limiter  - applications used to get the emi bw setting.
*
* RETURNS
*  0 for success; negative value for failure
*
*************************************************************************/

#if defined(__EMI_INTERNAL_NECESSARY_DRIVER__)

kal_int32 __EMI_GetBW(EMI_MASTER_LIMITER *master_limiter)
{
#if defined(__EMI_NO_DRIVER__)	 

   //ret = -1;
   return -1;

#else /* __EMI_NO_DRIVER__ */

    kal_int32 ret = 0;
    kal_int32 irq_mask = 0;

    irq_mask = SaveAndSetIRQMask();
    {

#if defined(MT6236) || defined(MT6236B)
  
        /**
           * Get EMI bandwidth and soft/hard mode.
           */
        master_limiter->emi_bw.mcu_port_bw = ((((*EMI_ARBA & EMI_BW_MAX_GNT_CNT_MARK) >> EMI_BW_MAX_GNT_CNT_SHIFT)  * EMI_BW_PERCENT_SCALE) / EMI_BW_PERCENT_TRANS_TO_REGISTER);
        master_limiter->emi_bw.dma_port_bw = ((((*EMI_ARBB & EMI_BW_MAX_GNT_CNT_MARK) >> EMI_BW_MAX_GNT_CNT_SHIFT) * EMI_BW_PERCENT_SCALE) / EMI_BW_PERCENT_TRANS_TO_REGISTER);
        master_limiter->emi_bw.gmc1_port_bw = ((((*EMI_ARBH & EMI_BW_MAX_GNT_CNT_MARK) >> EMI_BW_MAX_GNT_CNT_SHIFT) * EMI_BW_PERCENT_SCALE) / EMI_BW_PERCENT_TRANS_TO_REGISTER);
        master_limiter->emi_bw.gmc2_port_bw = ((((*EMI_ARBI & EMI_BW_MAX_GNT_CNT_MARK) >> EMI_BW_MAX_GNT_CNT_SHIFT) * EMI_BW_PERCENT_SCALE) / EMI_BW_PERCENT_TRANS_TO_REGISTER);
    
        /**
           * Get soft mode or hard mode for bandwidth allocation.
           */    
        master_limiter->emi_softmode.mcu_port_softmode = ((*EMI_ARBA & EMI_BW_SOFT_MODE_MARK) >> EMI_BW_SOFT_MODE_SHIFT);
        master_limiter->emi_softmode.dma_port_softmode = ((*EMI_ARBB & EMI_BW_SOFT_MODE_MARK) >> EMI_BW_SOFT_MODE_SHIFT);
        master_limiter->emi_softmode.gmc1_port_softmode = ((*EMI_ARBH & EMI_BW_SOFT_MODE_MARK) >> EMI_BW_SOFT_MODE_SHIFT);
        master_limiter->emi_softmode.gmc2_port_softmode = ((*EMI_ARBI & EMI_BW_SOFT_MODE_MARK) >> EMI_BW_SOFT_MODE_SHIFT);

#elif defined(MT6276) /* MT6236 || MT6236B */


    /**
       * MT6276 E1 and E2's EMI port is different.
       */
#if defined(MT6276_S00)

        /**
           * Get EMI bandwidth and soft/hard mode.
           */
        master_limiter->emi_bw.mcu_port_bw = ((((*EMI_ARBA & EMI_BW_MAX_GNT_CNT_MARK) >> EMI_BW_MAX_GNT_CNT_SHIFT)  * EMI_BW_PERCENT_SCALE) / EMI_BW_PERCENT_TRANS_TO_REGISTER);
        master_limiter->emi_bw.fcore_port_bw = ((((*EMI_ARBB & EMI_BW_MAX_GNT_CNT_MARK) >> EMI_BW_MAX_GNT_CNT_SHIFT) * EMI_BW_PERCENT_SCALE) / EMI_BW_PERCENT_TRANS_TO_REGISTER);
        master_limiter->emi_bw.fcoredma_port_bw = ((((*EMI_ARBC & EMI_BW_MAX_GNT_CNT_MARK) >> EMI_BW_MAX_GNT_CNT_SHIFT) * EMI_BW_PERCENT_SCALE) / EMI_BW_PERCENT_TRANS_TO_REGISTER);
        master_limiter->emi_bw.md2g3g_port_bw = ((((*EMI_ARBD & EMI_BW_MAX_GNT_CNT_MARK) >> EMI_BW_MAX_GNT_CNT_SHIFT) * EMI_BW_PERCENT_SCALE) / EMI_BW_PERCENT_TRANS_TO_REGISTER);
        master_limiter->emi_bw.mm_port_bw = ((((*EMI_ARBE & EMI_BW_MAX_GNT_CNT_MARK) >> EMI_BW_MAX_GNT_CNT_SHIFT) * EMI_BW_PERCENT_SCALE) / EMI_BW_PERCENT_TRANS_TO_REGISTER);
        master_limiter->emi_bw.dmadgbaud_port_bw = ((((*EMI_ARBF & EMI_BW_MAX_GNT_CNT_MARK) >> EMI_BW_MAX_GNT_CNT_SHIFT) * EMI_BW_PERCENT_SCALE) / EMI_BW_PERCENT_TRANS_TO_REGISTER);
    
        /**
           * Get soft mode or hard mode for bandwidth allocation.
           */    
        master_limiter->emi_softmode.mcu_port_softmode = ((*EMI_ARBA & EMI_BW_SOFT_MODE_MARK) >> EMI_BW_SOFT_MODE_SHIFT);
        master_limiter->emi_softmode.fcore_port_softmode = ((*EMI_ARBB & EMI_BW_SOFT_MODE_MARK) >> EMI_BW_SOFT_MODE_SHIFT);
        master_limiter->emi_softmode.fcoredma_port_softmode = ((*EMI_ARBC & EMI_BW_SOFT_MODE_MARK) >> EMI_BW_SOFT_MODE_SHIFT);
        master_limiter->emi_softmode.md2g3g_port_softmode = ((*EMI_ARBD & EMI_BW_SOFT_MODE_MARK) >> EMI_BW_SOFT_MODE_SHIFT);
        master_limiter->emi_softmode.mm_port_softmode = ((*EMI_ARBE & EMI_BW_SOFT_MODE_MARK) >> EMI_BW_SOFT_MODE_SHIFT);
        master_limiter->emi_softmode.dmadgbaud_port_softmode = ((*EMI_ARBF & EMI_BW_SOFT_MODE_MARK) >> EMI_BW_SOFT_MODE_SHIFT);

#else /* MT6276_S00 */

        /**
           * Get EMI bandwidth and soft/hard mode.
           */
        master_limiter->emi_bw.mcu_port_bw = ((((*EMI_ARBA & EMI_BW_MAX_GNT_CNT_MARK) >> EMI_BW_MAX_GNT_CNT_SHIFT)  * EMI_BW_PERCENT_SCALE) / EMI_BW_PERCENT_TRANS_TO_REGISTER);
        master_limiter->emi_bw.fcore_port_bw = ((((*EMI_ARBB & EMI_BW_MAX_GNT_CNT_MARK) >> EMI_BW_MAX_GNT_CNT_SHIFT) * EMI_BW_PERCENT_SCALE) / EMI_BW_PERCENT_TRANS_TO_REGISTER);
        master_limiter->emi_bw.md2g3gauddbg_port_bw = ((((*EMI_ARBC & EMI_BW_MAX_GNT_CNT_MARK) >> EMI_BW_MAX_GNT_CNT_SHIFT) * EMI_BW_PERCENT_SCALE) / EMI_BW_PERCENT_TRANS_TO_REGISTER);
        master_limiter->emi_bw.peri_port_bw = ((((*EMI_ARBD & EMI_BW_MAX_GNT_CNT_MARK) >> EMI_BW_MAX_GNT_CNT_SHIFT) * EMI_BW_PERCENT_SCALE) / EMI_BW_PERCENT_TRANS_TO_REGISTER);
        master_limiter->emi_bw.mm_port_bw = ((((*EMI_ARBE & EMI_BW_MAX_GNT_CNT_MARK) >> EMI_BW_MAX_GNT_CNT_SHIFT) * EMI_BW_PERCENT_SCALE) / EMI_BW_PERCENT_TRANS_TO_REGISTER);
    
        /**
           * Get soft mode or hard mode for bandwidth allocation.
           */    
        master_limiter->emi_softmode.mcu_port_softmode = ((*EMI_ARBA & EMI_BW_SOFT_MODE_MARK) >> EMI_BW_SOFT_MODE_SHIFT);
        master_limiter->emi_softmode.fcore_port_softmode = ((*EMI_ARBB & EMI_BW_SOFT_MODE_MARK) >> EMI_BW_SOFT_MODE_SHIFT);
        master_limiter->emi_softmode.md2g3gauddbg_port_softmode = ((*EMI_ARBC & EMI_BW_SOFT_MODE_MARK) >> EMI_BW_SOFT_MODE_SHIFT);
        master_limiter->emi_softmode.peri_port_softmode = ((*EMI_ARBD & EMI_BW_SOFT_MODE_MARK) >> EMI_BW_SOFT_MODE_SHIFT);
        master_limiter->emi_softmode.mm_port_softmode = ((*EMI_ARBE & EMI_BW_SOFT_MODE_MARK) >> EMI_BW_SOFT_MODE_SHIFT);

#endif /* MT6276_S00 */


#elif defined(MT6256) /* MT6236 || MT6236B */

        /**
           * Get EMI bandwidth and soft/hard mode.
           */
        master_limiter->emi_bw.mcu_port_bw = ((((*EMI_ARBA & EMI_BW_MAX_GNT_CNT_MARK) >> EMI_BW_MAX_GNT_CNT_SHIFT)  * EMI_BW_PERCENT_SCALE) / EMI_BW_PERCENT_TRANS_TO_REGISTER);
        master_limiter->emi_bw.mm_port_bw = ((((*EMI_ARBB & EMI_BW_MAX_GNT_CNT_MARK) >> EMI_BW_MAX_GNT_CNT_SHIFT) * EMI_BW_PERCENT_SCALE) / EMI_BW_PERCENT_TRANS_TO_REGISTER);
        master_limiter->emi_bw.dma_port_bw = ((((*EMI_ARBC & EMI_BW_MAX_GNT_CNT_MARK) >> EMI_BW_MAX_GNT_CNT_SHIFT) * EMI_BW_PERCENT_SCALE) / EMI_BW_PERCENT_TRANS_TO_REGISTER);
        master_limiter->emi_bw.md2g_peri_port_bw = ((((*EMI_ARBD & EMI_BW_MAX_GNT_CNT_MARK) >> EMI_BW_MAX_GNT_CNT_SHIFT) * EMI_BW_PERCENT_SCALE) / EMI_BW_PERCENT_TRANS_TO_REGISTER);
        master_limiter->emi_bw.dsp_port_bw = ((((*EMI_ARBE & EMI_BW_MAX_GNT_CNT_MARK) >> EMI_BW_MAX_GNT_CNT_SHIFT) * EMI_BW_PERCENT_SCALE) / EMI_BW_PERCENT_TRANS_TO_REGISTER);
        master_limiter->emi_bw.graphic_port_bw = ((((*EMI_ARBF & EMI_BW_MAX_GNT_CNT_MARK) >> EMI_BW_MAX_GNT_CNT_SHIFT) * EMI_BW_PERCENT_SCALE) / EMI_BW_PERCENT_TRANS_TO_REGISTER);
    
        /**
           * Get soft mode or hard mode for bandwidth allocation.
           */    
        master_limiter->emi_softmode.mcu_port_softmode = ((*EMI_ARBA & EMI_BW_SOFT_MODE_MARK) >> EMI_BW_SOFT_MODE_SHIFT);
        master_limiter->emi_softmode.mm_port_softmode = ((*EMI_ARBB & EMI_BW_SOFT_MODE_MARK) >> EMI_BW_SOFT_MODE_SHIFT);
        master_limiter->emi_softmode.dma_port_softmode = ((*EMI_ARBC & EMI_BW_SOFT_MODE_MARK) >> EMI_BW_SOFT_MODE_SHIFT);
        master_limiter->emi_softmode.md2g_peri_port_softmode = ((*EMI_ARBD & EMI_BW_SOFT_MODE_MARK) >> EMI_BW_SOFT_MODE_SHIFT);
        master_limiter->emi_softmode.dsp_port_softmode = ((*EMI_ARBE & EMI_BW_SOFT_MODE_MARK) >> EMI_BW_SOFT_MODE_SHIFT);
        master_limiter->emi_softmode.graphic_port_softmode = ((*EMI_ARBF & EMI_BW_SOFT_MODE_MARK) >> EMI_BW_SOFT_MODE_SHIFT);

#elif defined(MT6255)
#else /* MT6236 || MT6236B */

        /**
           * Do nothing for those BB does not support dynamic EMI BW allocation mechanism.
           */

#endif /* MT6236 || MT6236B */

    }
    RestoreIRQMask(irq_mask);

    return ret;
    
#endif /* __EMI_NO_DRIVER__ */

}


#endif  /* __EMI_INTERNAL_NECESSARY_DRIVER__ */


/*************************************************************************
* FUNCTION
*
*  __EMI_SetBW
*
* DESCRIPTION
*  This function shows the example that how to sets EMI bw.
*
* PARAMETERS
*  VOID
*
* RETURNS
*  0 for success; negative value for failure
*
*************************************************************************/

#if defined(__EMI_INTERNAL_TEST_DRIVER__)

kal_int32 __EMI_TEST_GetSetBW(void)
{
#if defined(__EMI_NO_DRIVER__)	 

   //ret = -1;
   return -1;

#else /* __EMI_NO_DRIVER__ */

    kal_int32 ret = 0;
    
#if defined(MT6236) || defined(MT6236B)

    EMI_MASTER_LIMITER master_limiter;

    ASSERT(0 == __EMI_GetBW(&master_limiter));
  
    /**
       * Determine bandwidth allocation (we can only modified those we want to change since we use the read-modify-write method).
       */
    master_limiter.emi_bw.mcu_port_bw = 20;
    master_limiter.emi_bw.dma_port_bw = 20;
    master_limiter.emi_bw.gmc1_port_bw = 30;
    master_limiter.emi_bw.gmc2_port_bw = 30;

    /**
       * Determine soft mode or hard mode for bandwidth allocation (we can only modified those we want to change since we use the read-modify-write method).
       */    
    master_limiter.emi_softmode.mcu_port_softmode = 1;
    master_limiter.emi_softmode.dma_port_softmode = 1;
    master_limiter.emi_softmode.gmc1_port_softmode = 0;
    master_limiter.emi_softmode.gmc2_port_softmode = 0;
    
    ASSERT(0 == __EMI_SetBW(&master_limiter));

#else /* MT6236 || MT6236B */

    /**
       * Do nothing. 
       */

#endif /* MT6236 || MT6236B */

    return ret;

#endif /* __EMI_NO_DRIVER__ */

}

#endif  /* __EMI_INTERNAL_TEST_DRIVER__ */



/*************************************************************************
* FUNCTION
*
*  EMI_SwitchRunTimeConfig
*
* DESCRIPTION
*  This function switch EMI configuration into real-time APP setting or normal APP setting.
*
* PARAMETERS
*  VOID
*
* RETURNS
*  0 for success; negative value for failure
*
*************************************************************************/

#if defined(__EMI_INTERNAL_NECESSARY_DRIVER__)

#ifdef __MTK_TARGET__
__attribute__ ((section ("INTSRAM_ROCODE"))) 
#endif /* __MTK_TARGET__ */
kal_int32 EMI_SwitchRunTimeConfig(kal_bool is_runtime)
{
#if defined(__EMI_NO_DRIVER__)	 

    //ret = -1;
    return -1;
   
#else /* __EMI_NO_DRIVER__ */

    kal_int32 ret = 0;

#if defined(MT6276)
    volatile kal_int32 irq_mask = 0; // volatile to avoid compile warning 

    irq_mask = SaveAndSetIRQMask();
    {
        if(KAL_TRUE == is_runtime)
        {
            /**
               * Mask all requests to EMI.
               */
            __EMI_BlockAllTransactions();
            
            /**
               * Disable dummy read function.
               */
            __EMI_DisableDummyRead();

            /**
               * Poll the assertion of EMI_IDLE.
               */
            __EMI_WaitEmiEnterIdleState();
            
            /**
               * Switch to real-time configuration - disable PDN.
               */
            *EMI_CONN |= (1<<4); 
            
            /**
               * Switch to real-time configuration - enable PPCT.
               */
            *EMI_PPCT |= 0xFFFF0000;

            /**
               * Unmask all requests to EMI.
               */
            __EMI_UnblockAllTransactions();
            
            /**
               * Enable the dummy read function.
               */
            __EMI_EnableDummyRead();        
        }
        else if(KAL_FALSE == is_runtime)
        {
            /**
               * Mask all requests to EMI.
               */
            __EMI_BlockAllTransactions();
            
            /**
               * Disable dummy read function.
               */
            __EMI_DisableDummyRead();

            /**
               * Poll the assertion of EMI_IDLE.
               */
            __EMI_WaitEmiEnterIdleState();
            
            /**
               * Switch to non-real-time configuration - enable PDN.
               */
            *EMI_CONN &= ~(1<<4); 
            
            /**
               * Switch to non-real-time configuration - disable PPCT.
               */
            *EMI_PPCT &= ~(0xFFFF0000);

            /**
               * Unmask all requests to EMI.
               */
            __EMI_UnblockAllTransactions();
            
            /**
               * Enable the dummy read function.
               */
            __EMI_EnableDummyRead();                
        }
        else
        {
            ASSERT(0);
        }
    }
    RestoreIRQMask(irq_mask);


#elif defined(MT6253) /* MT6276 */
    volatile kal_int32 irq_mask = 0; // volatile to avoid compile warning 

    irq_mask = SaveAndSetIRQMask();
    {
        if(KAL_TRUE == is_runtime)
        {
            /**
              * On MT6253  & MT6253D, if we have to set run-time configuration, we will enable B2S functionality, but
              * after re-testing MT6253D concurrency, the B2S functionality does not need to be enabled.
              * We will ask L1 to remove the function call after MT6253D WT cache QC done.
              */		
            //*EMI_GEN2 |= 0x00000010;
        }
        else if(KAL_FALSE == is_runtime)
        {
            //*EMI_GEN2 &= ~0x00000010;                
        }
        else
        {
            ASSERT(0);
        }
    }
    RestoreIRQMask(irq_mask);

#elif  defined(MT6252H) || defined(MT6252)
    volatile kal_int32 irq_mask = 0; // volatile to avoid compile warning 

    irq_mask = SaveAndSetIRQMask();
    {
        if(KAL_TRUE == is_runtime)
        {
            //B2S_GMS, B2S_DMA
            //*EMI_GEN2 |= 0x00000050;
        }
        else if(KAL_FALSE == is_runtime)
        {
            //*EMI_GEN2 &= ~0x00000050;                
        }
        else
        {
            ASSERT(0);
        }
    }
    RestoreIRQMask(irq_mask);

#elif defined(MT6236) || defined(MT6236B)
    volatile kal_int32 irq_mask = 0; // volatile to avoid compile warning 

    irq_mask = SaveAndSetIRQMask();
    {
        if(KAL_TRUE == is_runtime)
        {
            /**
              * On MT6236, we will set GMC's bandwidth allocation as hard-mode under real-time duration.
              */		
            *EMI_ARBH &= ~0x00004000;
            *EMI_ARBI &= ~0x00004000;
        }
        else if(KAL_FALSE == is_runtime)
        {
            *EMI_ARBH |= 0x00004000;
            *EMI_ARBI |= 0x00004000;
        }
        else
        {
            ASSERT(0);
        }
    }
    RestoreIRQMask(irq_mask);

#elif defined(MT6238) || defined(MT6239) /* MT6276 */
    volatile kal_int32 irq_mask = 0; // volatile to avoid compile warning 

    irq_mask = SaveAndSetIRQMask();
    {
        if(KAL_TRUE == is_runtime)
        {
            /**
              * On MT6238, we will block GMC's high-proirity under real-time duration if necessary. Currently, there is no requirement to do so.
              */		
            //EMI_DISABLE_GMC_HIGHPRIO(1, 1, 0);
        }
        else if(KAL_FALSE == is_runtime)
        {
            //EMI_ENABLE_GMC_HIGHPRIO(1, 1, 0);
        }
        else
        {
            ASSERT(0);
        }
    }
    RestoreIRQMask(irq_mask);

#elif defined(MT6256) /* MT6276 */
#if defined(__DYNAMICALLY_SET_EMI_ARB_SOFT_MODE__)
    volatile kal_int32 irq_mask = 0; // volatile to avoid compile warning 

    irq_mask = SaveAndSetIRQMask();
    {
        if(KAL_TRUE == is_runtime)  //enter hard run time
        {
            Set_EMI_BW_Graphic_Mode = 0;  //hard mode

            RunTimeConfigCnt++;
        }
        else if(KAL_FALSE == is_runtime)
        {
            if (RunTimeConfigCnt > 0)
            {
                 RunTimeConfigCnt--;
            }
            else
            {
                 ASSERT(0);  
            }
            
            if (0 == RunTimeConfigCnt)  //exit hard run time
            {
                 Set_EMI_BW_Graphic_Mode = Graphic_EMI_BW_Mode;
            }
            else  //still in hard runl time
            {
                 Set_EMI_BW_Graphic_Mode = 0;  //hard mode
            }
        }
        else
        {
            ASSERT(0);
        }
    }
    RestoreIRQMask(irq_mask); //it will set Graphic mode by Set_EMI_BW_Graphic_Mode

#endif // #if defined(__DYNAMICALLY_SET_EMI_ARB_SOFT_MODE__)

#else /* MT6276 */

    /**
       * Do nothing. 
       */

#endif /* MT6276 */

    return ret;
    
#endif /* __EMI_NO_DRIVER__ */

}


#endif  /* __EMI_INTERNAL_NECESSARY_DRIVER__ */


#if !defined(__UBL__)
/*************************************************************************
* FUNCTION
*
*  EMI_reg_dump_init
*
* DESCRIPTION
*  Register EMI register dump region when exception happens
*
* PARAMETERS
*  VOID
*
* RETURNS
*  void
*
*************************************************************************/
void EMI_reg_dump_init(void) {
   /* register bb reg dump */
   emi_dump.regions = (kal_uint32*)emi_dump_regions;
   emi_dump.num = sizeof(emi_dump_regions) / (sizeof(kal_uint32) * 3);
   emi_dump.bbreg_dump_callback = NULL;
   EX_REGISTER_BBREG_DUMP(&emi_dump);
}
#endif /* !__UBL__ */


#if defined(__RF_DESENSE_TEST__)
void EMI_SetMinDrivingCurrent(void)
{
    #if defined(MT6256) || defined(MT6255)
     *EMI_DRVA = 0x66666666;
     *EMI_DRVB = 0x00660000; 
    #endif //#if defined(MT6256)

     return;
}
#endif //#if defined(__RF_DESENSE_TEST__)


#endif /* __MTK_TARGET__ */

/*************************************************************************
* FUNCTION
*  SRAM_repair()
*
* DESCRIPTION
*   This routine use to repair SRAM
*
* PARAMETERS
*
* RETURNS
*  -1 : fail
*    0 : cuccess
*
*************************************************************************/
/*  hspa_sw_repair ; tddsys_sw_repair
     0 : pass 1st MBIST,  
     1 : 1st MBIST fail , but pass 2nd MBIST
     -1 : 1st & 2nd MBIST fail
*/     
kal_int32 hspa_sw_repair = 0, tddsys_sw_repair = 0;

int SRAM_repair(REPAIR_MODULE module)
{
    int result = 0;
	
#ifdef __MTK_TARGET__
#if defined(MT6572)		
    volatile unsigned int i; 

    i = *((volatile UINT32P)0xA0009170);
    if ( (i & 0x00200000) == 0)   //no e-fuse, bypass sw repair 
    {
         return 0;
    }
	
    switch(module)
    {	   
     case MDSYS:

	  /* 1st mbist */	
	  /* MDSYS SRAM repair */
	  *((volatile UINT32P)0x800e0044) = 0x00000000;	// MBIST_RESETB_ADDR = 3'h0
	  *((volatile UINT32P)0x800e0044) = 0x00000003;	// MBIST_RESETB_ADDR = 3'h3
	  *((volatile UINT32P)0x800e0000) = 0x00000ff6;	// MBIST_START_0_ADDR = 15'h0ff6
	
	  //wait for mbist
	  while (*((volatile UINT32P)0x800e0024) != 0x00001fec);  // MBIST_DONE_0_ADDR == 16'h1fec
	
	  // check status
	  if ((*((volatile UINT32P)0x800e0030) != 0x00000000) ||(*((volatile UINT32P)0x800e0034) != 0x00000000) ||
	  	(*((volatile UINT32P)0x800e0048) != 0x00000000) ||(*((volatile UINT32P)0x800e004c) != 0x00000000) ||
	  	(*((volatile UINT32P)0x800e0050) != 0x00000000) || (*((volatile UINT32P)0x800e0054) != 0x00000000))	  	
	  {
              /* load fuse */
		*((volatile UINT32P)0x800e0044) = 0x00000007;	// MBIST_RESETB_ADDR = 3'h7

	       /* 2nd mbist */
		*((volatile UINT32P)0x800e0044) = 0x00000000;  // MBIST_RESETB_ADDR = 3'h0
		*((volatile UINT32P)0x800e0044) = 0x00000003;  // MBIST_RESETB_ADDR = 3'h3
		*((volatile UINT32P)0x800e0000) = 0x00000ff6;  // MBIST_START_0_ADDR = 15'h0ff6

	       //wait for mbist
	       while (*((volatile UINT32P)0x800e0024) != 0x00001fec);  // MBIST_DONE_0_ADDR == 16'h1fec
	
	        // check status
       	if ((*((volatile UINT32P)0x800e0030) != 0x00000000) ||(*((volatile UINT32P)0x800e0034) != 0x00000000) ||
       	   (*((volatile UINT32P)0x800e0048) != 0x00000000) ||(*((volatile UINT32P)0x800e004c) != 0x00000000) ||
       	   (*((volatile UINT32P)0x800e0050) != 0x00000000) || (*((volatile UINT32P)0x800e0054) != 0x00000000))
	  	
	       {
                   result = -1;
	       }
	  }
	  
	  *((volatile UINT32P)0x800e0044) = 0x00000000;	// MBIST_RESETB_ADDR = 3'h0
	  *((volatile UINT32P)0x800e0000) = 0x00000000;	// MBIST_START_0_ADDR = 15'h0000

	 break;
	  
     case HSPA:

	   hspa_sw_repair = 0;
	  /* HSPA SRAM repair */
	  *((volatile UINT32P)0x836e007c) = 0x00000000;	// MBIST_RESETB_ADDR = 1'h0
	  *((volatile UINT32P)0x836e008c) = 0x00000000;	// MBIST_REPAIR_RSTB_ADDR = 1'h0
	  for (i=0; i<10; i++);
	  *((volatile UINT32P)0x836e007c) = 0x00000001;	// MBIST_RESETB_ADDR = 1'h1
	  *((volatile UINT32P)0x836e008c) = 0x00000001;	// MBIST_REPAIR_RSTB_ADDR = 1'h1
	  *((volatile UINT32P)0x836e0000) = 0x00000080;	// MBIST_START_0_ADDR = 13'h0080
	
	  //wait for mbist
	  while (*((volatile UINT32P)0x836e002c) != 0x00000004);  // MBIST_DONE_0_ADDR == 20'h0_0004
	
	   // check status
	  if ((*((volatile UINT32P)0x836e0030) != 0x00000000) || (*((volatile UINT32P)0x836e0034) != 0x00000000) ||
	  	(*((volatile UINT32P)0x836e0038) != 0x00000000) || (*((volatile UINT32P)0x836e0090) != 0x00000000) || 
	  	(*((volatile UINT32P)0x836e0094) != 0x00000000))
	  {
	     hspa_sw_repair = 1;
		 
	     /* load fuse */
   	     *((volatile UINT32P)0x836e00a8) = 0x00000001;  // MBIST_LOAD_FUSE_ADDR = 1'h1   	 
            for (i=0; i<10; i++);
   	     *((volatile UINT32P)0x836e00a8) = 0x00000000;  // MBIST_LOAD_FUSE_ADDR = 1'h0

	      /* 2nd mbist */
	      *((volatile UINT32P)0x836e007c) = 0x00000000;	// MBIST_RESETB_ADDR = 1'h0
	      *((volatile UINT32P)0x836e008c) = 0x00000000;	// MBIST_REPAIR_RSTB_ADDR = 1'h0
	      *((volatile UINT32P)0x836e0000) = 0x00000000;	// MBIST_START_0_ADDR = 13'h0000
	      for (i=0; i<10; i++);
	      *((volatile UINT32P)0x836e007c) = 0x00000001;	// MBIST_RESETB_ADDR = 1'h1
	      *((volatile UINT32P)0x836e008c) = 0x00000001;	// MBIST_REPAIR_RSTB_ADDR = 1'h1
	      *((volatile UINT32P)0x836e0000) = 0x00000080;	// MBIST_START_0_ADDR = 13'h0080
		  
	      //wait for mbist
	      while (*((volatile UINT32P)0x836e002c) != 0x00000004);  // MBIST_DONE_0_ADDR == 20'h0_0004
		  
	      // check status
	      if ((*((volatile UINT32P)0x836e0030) != 0x00000000) || (*((volatile UINT32P)0x836e0034) != 0x00000000) ||
		  (*((volatile UINT32P)0x836e0038) != 0x00000000) || (*((volatile UINT32P)0x836e0090) != 0x00000000) || 
		  (*((volatile UINT32P)0x836e0094) != 0x00000000))
	      {
                  result = -1;				  
	           hspa_sw_repair = -1;
	      }
	  }
	  
	  *((volatile UINT32P)0x836e007c) = 0x00000000;	// MBIST_RESETB_ADDR = 1'h0
	  *((volatile UINT32P)0x836e008c) = 0x00000000;	// MBIST_REPAIR_RSTB_ADDR = 1'h0
	  *((volatile UINT32P)0x836e0000) = 0x00000000;	// MBIST_START_0_ADDR = 13'h0000

	  break;
	
     case TDDSYS:

         tddsys_sw_repair = 0;	
	  /* TDDSYS SRAM repair */
	  // tddsys_mbist_config
	  *((volatile UINT32P)0x84050068) = 0x00000000;	// MBIST_RESETB_ADDR = 1'h0
	  *((volatile UINT32P)0x84050068) = 0x00000001;	// MBIST_RESETB_ADDR = 1'h1
	  *((volatile UINT32P)0x84050000) = 0x3b438000;	// MBIST_START_0_ADDR = 32'h3b43_8000
	
	  //wait for mbist
	  while (*((volatile UINT32P)0x8405001c) != 0x76870000);  // MBIST_DONE_0_ADDR == 32'h7687_0000
		
	  // check status
	  if ((*((volatile UINT32P)0x84050024) != 0x00000000) || (*((volatile UINT32P)0x84050028) != 0x00000000) ||
	  	(*((volatile UINT32P)0x8405002c) != 0x00000000) || (*((volatile UINT32P)0x84050030) != 0x00000000) ||
	  	(*((volatile UINT32P)0x84050034) != 0x00000000) || (*((volatile UINT32P)0x84050060) != 0x00000000) ||
	       (*((volatile UINT32P)0x84050064) != 0x00000000))
	  {	  
	        tddsys_sw_repair = 1;

		 /* load fuse */
	       *((volatile UINT16P)0x8400001e) = 0x004d;	// MBIST_CTRL_ADDR = 16'h004d
		for (i=0; i<10; i++);
		*((volatile UINT16P)0x8400001e) = 0x000d;	// MBIST_CTRL_ADDR = 16'h000d

      	       /* 2nd mbist */
      		*((volatile UINT32P)0x84050068) = 0x00000000;  // MBIST_RESETB_ADDR = 1'h0
      		*((volatile UINT32P)0x84050068) = 0x00000001;  // MBIST_RESETB_ADDR = 1'h1
      		*((volatile UINT32P)0x84050000) = 0x3b438000;  // MBIST_START_0_ADDR = 32'h3b43_8000

       	//wait for mbist
              while (*((volatile UINT32P)0x8405001c) != 0x76870000);  // MBIST_DONE_0_ADDR == 32'h7687_0000
       		
       	// check status
       	if ((*((volatile UINT32P)0x84050024) != 0x00000000) || (*((volatile UINT32P)0x84050028) != 0x00000000) ||
       	   (*((volatile UINT32P)0x8405002c) != 0x00000000) || (*((volatile UINT32P)0x84050030) != 0x00000000) ||
       	   (*((volatile UINT32P)0x84050034) != 0x00000000) || (*((volatile UINT32P)0x84050060) != 0x00000000) ||
       	   (*((volatile UINT32P)0x84050064) != 0x00000000))
       	  {
                     result = -1;				 
        		tddsys_sw_repair = -1;
       	  }
	  }
	  
	  *((volatile UINT32P)0x84050068) = 0x00000000;	// MBIST_RESETB_ADDR = 1'h0
	  *((volatile UINT32P)0x84050000) = 0x00000000;	// MBIST_START_0_ADDR = 32'h0000

	  break;
	
	default:

	  result = -1;
         break;	
	}
#endif  /* #if defined(MT6572) */		
#endif /* __MTK_TARGET__ */

    return result;
}



