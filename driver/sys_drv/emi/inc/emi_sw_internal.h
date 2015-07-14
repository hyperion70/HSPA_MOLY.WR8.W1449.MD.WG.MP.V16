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
 *   emi_sw_internal.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   Definition for CONFIG hardware registers
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __EMI_SW_INTERNAL_H__
#define __EMI_SW_INTERNAL_H__

/* RHR Add */
#include "kal_general_types.h"
#include "emi_hw.h"

/*********************************************
  *
  * High-level EMI feature definition.
  *
  ********************************************/

/**
   * Define whether supporting dynamic set EMI bandwidth to soft-mode control, it is mainly for GMC's bandwidth control. It is used under lock-down IRQ duration currently.
   */
#if defined(MT6236) || defined(MT6236B) || defined(MT6256) || defined(MT6255)

#define __DYNAMICALLY_SET_EMI_ARB_SOFT_MODE__

#endif  /* MT6236 || MT6236B || MT6256 ||MT6255*/


/**
   * Define whether supporting small cache within EMI controller.
   */
#if defined(MT6223) || defined(MT6223P) || defined(MT6253) || defined(MT6253T) || defined(MT6252H) || defined(MT6252) || defined(MT6253E) || defined(MT6253L)

#define __EMI_WITH_CACHE_SUPPORT__ 

#endif /* MT6223 || MT6223P || MT6253 || MT6253T || MT6252H || MT6252 || MT6253E || MT6253L */

/* On MT6252, the I/DPREF on EMI are used to decide either convert burst to single or not,
   and they should always be 1. Note that the I/D prefetching is no function on MT6252.
   However, we will still use/un-use I/D-Cache in some situatoin. 
   */
#if defined(MT6252H) || defined(MT6252)

#define __EMI_PREF_AS_NOB2S__

#endif

/**
   * Define whether we will leave the api exist but emptize the implementation. Mainly for smart-phone projects.
   */
#if defined(__SMART_PHONE_MODEM__) || defined(MT6251)

#define __EMI_NO_DRIVER__

#endif /* __SMART_PHONE_MODEM__ */


/**
   * Define EMI driver compilation.
   */
#if defined(__FUE__)

#define __EMI_INTERNAL_OPTIONAL_DRIVER__

#endif /* __FUE__ */

#if !defined(__FUE__)

#define __EMI_INTERNAL_OPTIONAL_DRIVER__
#define __EMI_INTERNAL_NECESSARY_DRIVER__
//#define __EMI_INTERNAL_TEST_DRIVER__

#endif /* !__FUE__ */


/**
   * Define whether entering/existing self-refresh mode under sleep mode is controlled by SW.
   */
#if defined(MT6235) || defined(MT6235B)

#define __EMI_SELFREFRESH_UNDER_SLEEP_CONTROLLED_BY_SW__

#endif /* MT6235 || MT6235B */


/**
   * Define whether EMI 2x clock is calibrated by SW.
   */
#if defined(MT6235) || defined(MT6235B) || defined(MT6238) || defined(MT6239)

#define __EMI_2XCLK_CALIBRATION_UNDER_SLEEP_CONTROLLED_BY_SW__

#endif /* MT6235 || MT6235B */


/**
   * Define single-bank NOR flash related driver's code placement, either locate at PSRAM-code or locate at INT.SRAM.
   */
#if defined(MT6223) || defined(MT6223P) || defined(MT6235) || defined(MT6235B) || defined(MT6253T) || defined(MT6253) || defined(MT6252H) || defined(MT6252) || defined(MT6253E) || defined(MT6253L)

#define __EMI_SNORCODE_LOCATE_EXTSRAM__

#else /* MT6223 || MT6223P || MT6235 || MT6235B || MT6253T || MT6253 || MT6252H || MT6252 || MT6253E || MT6253L */

#define __EMI_SNORCODE_LOCATE_INTSRAM__

#endif /* MT6223 || MT6223P || MT6235 || MT6235B || MT6253T || MT6253 || MT6252H || MT6252 || MT6253E || MT6253L */


/*********************************************
  *
  * Constant/define
  *
  ********************************************/

/**
   * SFI boot-mode configuration.
   */
#define SFI_MAP_FLASH_NA 0x0
#define SFI_REMAP_MASK 0x10000

/**
   * EMI boot-mode configuration.
   */
#define EMI_MAP_EXTERNALBOOT_FLASH_SRAM  2
#define EMI_MAP_EXTERNALBOOT_SRAM_FLASH  3
#define EMI_REMAP_MASK 3


/**
   * EMI dummy read configuration (used under SW DCM and Sleep Mode).
   * Read non-existing bank, on old EMI design, the non-existing bank will have lowest priority for serving the request. 
   * We later on apply the same address for dummy read even EMI design has been modified since it makes no difference.
   */
#if defined(TK6516) || defined(MT6516)

// code size has been shrinked and is smaller than 4MB
//#define EMI_Dummy_Read_Base 0x00600000
#define EMI_Dummy_Read_Base 0x003e0000

#elif defined(MT6573) || defined(MT6575)

#define EMI_Dummy_Read_Base 0x00600000

#elif defined(MT6238) || defined(MT6239) || defined(MT6235)  || defined(MT6235B) || defined(MT6268A) || defined(MT6268) || defined(MT6236) || defined(MT6236B) || defined(MT6270A) || defined(MT6276) || defined(MT6256) || defined(MT6255) || defined(TK6280) || defined(MT6280)/* TK6516 || MT6516 */

/**
   * The EA26 bit is used to bypass the L2 cache on some architecture.
   */
#define EMI_Dummy_Read_Base 0x28000000

#else /* TK6516 || MT6516 */

/**
   * The EA25 bit is used to bypass the L2 cache on some architecture.
   */
//#define EMI_Dummy_Read_Base 0x00600000

#endif /* TK6516 || MT6516 */


/**
   * Define EMI BW related configuration.
   */ 
#if defined(MT6236) || defined(MT6236B) || defined(MT6276) || defined(MT6256) || defined(MT6255) 

#define EMI_BW_PERCENT_TRANS_TO_REGISTER 128
#define EMI_BW_PERCENT_SCALE 100
#define EMI_BW_SOFTMODE_BIT_OFFSET 14

#define EMI_BW_MAX_GNT_CNT_MARK 0x000000FF
#define EMI_BW_MAX_GNT_CNT_SHIFT 0

#define EMI_BW_SOFT_MODE_MARK 0x00004000
#define EMI_BW_SOFT_MODE_SHIFT 14

#define EMI_BW_FILTER_EN_MARK 0x00001000
#define EMI_BW_FILTER_EN_SHIFT 12

#endif  /* MT6236 || MT6236B || MT6276 || MT6256 || defined(MT6255)*/



/*********************************************
  *
  * Enum
  *
  ********************************************/

typedef enum
{
    EMI_CS0 = 0,
    EMI_CS1 = 1,
    EMI_CS2 = 2,
    EMI_CS3 = 3,
    EMI_MAX_CS = 3,
    EMI_UNKNOWN_CS = 0xff
} EMI_CHIP_SELECT;


typedef enum
{
    EMI_FLASH = 0,
    EMI_RAM = 1,
    EMI_MAX_MEMTYPE = 1
} EMI_MEMTYPE;


typedef enum
{
    EMI_UNKNOWN_MODE = 0,
    EMI_ASYNC_MODE,
    EMI_PAGE_MODE,
    EMI_BURST_MODE,
    EMI_SDR_16_MODE,
    EMI_SDR_32_MODE,
    EMI_DDRI_16_MODE,
    EMI_DDRI_32_MODE,
    EMI_DDRII_16_MODE,
    EMI_DDRII_32_MODE,
    EMI_DDRIII_16_MODE
} EMI_DEVICE_MODE;


/**
   * Define scenarios for requiring different GMC EMI bandwidth.
    */
enum 
{ 
#if defined(MT6236) || defined(MT6236B)
    MM_SCE_MMI = 0, 
    MM_SCE_CAM_PREV, 
    MM_SCE_CAP, 
    MM_CSE_CAP_OFFLINE, 
    MM_CSE_CAP_P1_OFFLINE, 
    MM_CSE_CAP_P2_OFFLINE, 
    MM_SCE_VIDEO_REC, 
    MM_SCE_VIDEO_REC_FR2X,
    MM_SCE_VIDEO_PLAY,
    MM_SCE_VIDEO_REC_HVGA,            /* Video record resolution HVGA */
    MM_SCE_VIDEO_REC_HVGA_FR2X,
    MM_SCE_VIDEO_PLAY_HVGA,
    MM_SCE_VIDEO_REC_D1, 
    MM_SCE_VIDEO_PLAY_D1, 
    MM_SCE_END
#elif defined(MT6276) /* MT6236 || MT6236B */
    MM_SCE_MMI = 0, 
    MM_SCE_CAM_PREV, 
    MM_SCE_CAP, 
    MM_SCE_VIDEO_REC, 
    MM_SCE_VIDEO_PLAY,
    MM_SCE_END,
    SS_FCORE_LOGGING
#elif defined(MT6256) /* MT6236 || MT6236B */
    MM_SCE_MMI = 0, 
    MM_SCE_CAM_PREV,             /* Camera preview for WVGA panel */
    MM_SCE_CAP, 
    MM_SCE_VIDEO_REC, 
    MM_SCE_VIDEO_PLAY,
    MM_SCE_MMI_2D, 
    MM_SCE_MMI_3D, 
    MM_SCE_VLW,                       /* video playback without display rotation for WQVGA panel */
    MM_SCE_VIDEO_PLAY_HVGA, /* Video paly for HVGA panel */
    MM_SCE_CAM_PREV_HVGA,   /* camera preview for HVGA panel */
    MM_SCE_VLW_HVGA,            /* video playback without display rotation for HVGA panel */
    MM_SCE_MMI_3D_1_LCD_LAYER, 
    MM_SCE_MMI_3D_2_LCD_LAYER, 
    MM_SCE_END
#elif defined(MT6255) /* MT6236 || MT6236B */
    MM_SCE_MMI = 0, 
    MM_SCE_CAM_PREV, 
    MM_SCE_CAP, 
    MM_SCE_VIDEO_REC, 
    MM_SCE_VIDEO_PLAY,
    MM_SCE_MMI_2D, 
    MM_SCE_MMI_3D, 
    MM_SCE_END, 
#else /* MT6236 || MT6236B */
    MM_SCE_MMI = 0, 
    MM_SCE_CAM_PREV, 
    MM_SCE_CAP, 
    MM_SCE_VIDEO_REC, 
    MM_SCE_VIDEO_PLAY,
    MM_SCE_END
#endif  /* MT6236 || MT6236B */
};

/* SRAM repair HW module*/
typedef enum
{
	MFG_MMSYS = 0,
	MDSYS,
	HSPA,
	TDDSYS	
}REPAIR_MODULE;

/*********************************************
  *
  * Struct
  *
  ********************************************/

/**
   * This information is used to query EMI run-time configuration and show on the engineering mode.
   */
typedef struct 
{
    kal_uint32 reg_num;

#if defined(MT6223) || defined(MT6227D) || defined(MT6226D) || defined(MT6223P) || defined(MT6223D) || defined(MT6253) || defined(MT6252H) || defined(MT6252) || defined(MT6253E) || defined(MT6253L) || defined(MT6226) || defined(MT6226M) || defined(MT6227)
 
    kal_uint32 EMI_CONA_value;
    kal_uint32 EMI_CONB_value;
    kal_uint32 EMI_REMAP_value;
    kal_uint32 EMI_GEN_value;
    kal_uint32 EMI_PREFETCH_value;

#if defined(MT6223) || defined(MT6227D) || defined(MT6226D) || defined(MT6223P) || defined(MT6223D) || defined(MT6253) || defined(MT6252H) || defined(MT6252) || defined(MT6253E) || defined(MT6253L)

    kal_uint32 EMI_ADMUX_value;
 
 #if defined(MT6253)
 
    kal_uint32 EMI_CLOCKDEL_value;
    kal_uint32 EMI_DELA_value;
    kal_uint32 EMI_DELB_value;
    kal_uint32 EMI_EXTCON_value;
    kal_uint32 EMI_EXTCON2_value;
    kal_uint32 EMI_GEN2_value;
    kal_uint32 EMI_CONA_EXT_value;
    kal_uint32 EMI_CONB_EXT_value;
 
 #elif defined(MT6252H) || defined(MT6252) || defined(MT6253E) || defined(MT6253L) /* MT6253 */

    kal_uint32 EMI_CLOCKDEL_value;
    kal_uint32 EMI_EXTCON_value;
    kal_uint32 EMI_EXTCON2_value;
    kal_uint32 EMI_GEN2_value;
    kal_uint32 EMI_GEN3_value;    
    kal_uint32 EMI_CONA_EXT_value;
    kal_uint32 EMI_CONB_EXT_value;
    kal_uint32 EMI_CONC_EXT_value;
    kal_uint32 EMI_COND_EXT_value;
    kal_uint32 EMI_IOA_value;
    kal_uint32 EMI_IOB_value;    
    kal_uint32 EMI_IOC_value;    

 #endif /* MT6253 */
   
#endif /* MT6223 || MT6227D || MT6226D || MT6223P || MT6223D || MT6253 || MT6252H || MT6252 || MT6253E || MT6253L */

   
 #elif defined(MT6229) || defined(MT6230)|| defined(MT6228)|| defined(MT6225) /* MT6223 || MT6227D || MT6226D || MT6223P || MT6223D || MT6253 || MT6252H || MT6252 || MT6253E || MT6253L || MT6226 || MT6226M || MT6227 */
 
    kal_uint32 EMI_CONA_value;
    kal_uint32 EMI_CONB_value;
    kal_uint32 EMI_CONI_value;
    kal_uint32 EMI_CONK_value;
    kal_uint32 EMI_CONL_value;
    kal_uint32 EMI_REMAP_value;
    kal_uint32 EMI_GENA_value;
    kal_uint32 EMI_GENB_value;
   
 #if defined(MT6229) || defined(MT6230)
 
    kal_uint32 EMI_GENC_value;
   
 #endif /* MT6229 || MT6230 */
 
 #elif defined(MT6235) || defined(MT6235B) || defined(MT6238) || defined(MT6239) || defined(MT6268) || defined(MT6236) || defined(MT6236B) ||defined(MT6270A) /* MT6223 || MT6227D || MT6226D || MT6223P || MT6223D || MT6253 || MT6252H || MT6252 || MT6253E || MT6253L || MT6226 || MT6226M || MT6227 */
 
    kal_uint32 EMI_CONA_value;
    kal_uint32 EMI_CONB_value;
     
    kal_uint32 EMI_CONI_value;
    kal_uint32 EMI_CONJ_value;
    kal_uint32 EMI_CONK_value;
    kal_uint32 EMI_CONL_value;
    kal_uint32 EMI_CONM_value;
    kal_uint32 EMI_CONN_value;	
 
    kal_uint32 EMI_GENA_value;
    kal_uint32 EMI_GENB_value;
    kal_uint32 EMI_GENC_value;
    kal_uint32 EMI_GEND_value;

#if defined(MT6238) || defined(MT6239) || defined(MT6268) || defined(MT6236) || defined(MT6236B) || defined(MT6270A)

    kal_uint32 EMI_CONE_value;
    kal_uint32 EMI_CONF_value;

#if defined(MT6268) || defined(MT6236) || defined(MT6236B) || defined(MT6270A)

    kal_uint32 EMI_DELA_value;
    kal_uint32 EMI_DELB_value;
    kal_uint32 EMI_DELC_value;
    kal_uint32 EMI_DELD_value;
    kal_uint32 EMI_DELE_value;
    kal_uint32 EMI_DELF_value;
    kal_uint32 EMI_DELG_value;
    kal_uint32 EMI_DELH_value;
    kal_uint32 EMI_DELI_value;
    kal_uint32 EMI_DELJ_value;
    
    kal_uint32 EMI_ARBA_value;
    kal_uint32 EMI_ARBB_value;
    kal_uint32 EMI_ARBC_value;
    kal_uint32 EMI_ARBD_value;
    kal_uint32 EMI_ARBE_value;
    kal_uint32 EMI_ARBF_value;
    kal_uint32 EMI_ARBG_value;
    kal_uint32 EMI_ARBH_value;
    kal_uint32 EMI_ARBI_value;

#endif  /* MT6268 || MT6236 || MT6236B */

#endif /* MT6238 || MT6239 || MT6268 || MT6236 || MT6236B */

#elif defined(MT6256)  || defined(MT6276) || defined(MT6255)

    kal_uint32 EMI_CONA_value;
    kal_uint32 EMI_CONB_value;
    kal_uint32 EMI_CONE_value;
    kal_uint32 EMI_CONF_value;
    kal_uint32 EMI_CONI_value;
    kal_uint32 EMI_CONJ_value;
    kal_uint32 EMI_CONK_value;
    kal_uint32 EMI_CONL_value;
    kal_uint32 EMI_CONM_value;
    kal_uint32 EMI_CONN_value;	
 
    kal_uint32 EMI_GENA_value;
    kal_uint32 EMI_DRCT_value;
    kal_uint32 EMI_DDRV_value;
    kal_uint32 EMI_GEND_value;
    
    kal_uint32 EMI_ARBA_value;
    kal_uint32 EMI_ARBB_value;
    kal_uint32 EMI_ARBC_value;
    kal_uint32 EMI_ARBD_value;
    kal_uint32 EMI_ARBE_value;
    kal_uint32 EMI_ARBF_value;

#elif defined(MT6280)
    kal_uint32 EMI_CONI_value;
    kal_uint32 EMI_CONJ_value;
    kal_uint32 EMI_CONK_value;
    kal_uint32 EMI_CONL_value;
    kal_uint32 EMI_CONM_value;
    kal_uint32 EMI_CONN_value;	
 
    kal_uint32 EMI_GENA_value;
    kal_uint32 EMI_DRCT_value;
    kal_uint32 EMI_DDRV_value;
    kal_uint32 EMI_GEND_value;
    
    kal_uint32 EMI_ARBA_value;
    kal_uint32 EMI_ARBB_value;
    kal_uint32 EMI_ARBC_value;
    kal_uint32 EMI_ARBD_value;

#endif  /* MT6223 || MT6227D || MT6226D || MT6223P || MT6223D || MT6253 || MT6252H || MT6252 || MT6253E || MT6253L || MT6226 || MT6226M || MT6227 */
} EMI_RUNTIME_Info;


/**
   * Record the EMI BW allocation for different EMI port. The bandwidth allocation here is in terms of %, for example, setting mcu_port_bw to be 11 means giving MCU 11% EMI BW.
   */
typedef struct 
{
#if defined(MT6236) || defined(MT6236B)

    unsigned int mcu_port_bw;
    unsigned int dma_port_bw;
    unsigned int gmc1_port_bw;
    unsigned int gmc2_port_bw;

#elif defined(MT6276) || defined(MT6573) /* MT6236 || MT6236B */

#if defined(MT6276_S00)

    unsigned int mcu_port_bw;
    unsigned int fcore_port_bw;
    unsigned int fcoredma_port_bw;
    unsigned int md2g3g_port_bw;
    unsigned int mm_port_bw;
    unsigned int dmadgbaud_port_bw;

#else /* MT6276_S00 */

    /**
       * MT6276 E2 change the slave port design, the following codes are arranged from port_0 to port_4.
       */
    unsigned int mcu_port_bw;
    unsigned int fcore_port_bw;
    unsigned int md2g3gauddbg_port_bw;
    unsigned int peri_port_bw;
    unsigned int mm_port_bw;

#endif /* MT6276_S00 */

#elif defined(MT6256) /* MT6236 || MT6236B */

    unsigned int mcu_port_bw;
    unsigned int mm_port_bw;
    unsigned int dma_port_bw;
    unsigned int md2g_peri_port_bw;
    unsigned int dsp_port_bw;
    unsigned int graphic_port_bw;

#elif defined(MT6255) /* MT6255 */

    unsigned int mcu_port_bw;
    unsigned int mm_port_bw;
    unsigned int dma_port_bw;
    unsigned int md2g_peri_port_bw;
    unsigned int dsp_port_bw;
    unsigned int graphic_port_bw;

#else /* MT6236 || MT6236B */

    unsigned int dummy_port_bw;

#endif /* MT6236 || MT6236B */
} EMI_MASTER_BW;


/**
   * Record the EMI BW soft-mode or hard-mode allocation for different EMI port.
   */
typedef struct 
{
#if defined(MT6236) || defined(MT6236B)

    unsigned int mcu_port_softmode;
    unsigned int dma_port_softmode;
    unsigned int gmc1_port_softmode;
    unsigned int gmc2_port_softmode;

#elif defined(MT6276) || defined(MT6573) /* MT6236 || MT6236B */

#if defined(MT6276_S00)

    unsigned int mcu_port_softmode;
    unsigned int fcore_port_softmode;
    unsigned int fcoredma_port_softmode;
    unsigned int md2g3g_port_softmode;
    unsigned int mm_port_softmode;
    unsigned int dmadgbaud_port_softmode;

#else /* MT6276_S00 */

    /**
       * MT6276 E2 change the slave port design, the following codes are arranged from port_0 to part_4.
       */
    unsigned int mcu_port_softmode;
    unsigned int fcore_port_softmode;
    unsigned int md2g3gauddbg_port_softmode;
    unsigned int peri_port_softmode;
    unsigned int mm_port_softmode;

#endif /* MT6276_S00 */

#elif defined(MT6256) /* MT6236 || MT6236B */

    unsigned int mcu_port_softmode;
    unsigned int mm_port_softmode;
    unsigned int dma_port_softmode;
    unsigned int md2g_peri_port_softmode;
    unsigned int dsp_port_softmode;
    unsigned int graphic_port_softmode;

#elif defined(MT6255) /* MT6236 || MT6236B */

    unsigned int mcu_port_softmode;
    unsigned int mm_port_softmode;
    unsigned int dma_port_softmode;
    unsigned int md2g_peri_port_softmode;
    unsigned int dsp_port_softmode;
    unsigned int graphic_port_softmode;
    
#else /* MT6236 || MT6236B */

    unsigned int dummy_port_softmode;

#endif /* MT6236 || MT6236B */
} EMI_MASTER_SOFTMODE;


/**
   * High-level structure wrap EMI bandwidth allocation and soft/hard-mode configuration for EMI bandwidth control.
   */
typedef struct 
{
#if defined(MT6236) || defined(MT6236B)

    EMI_MASTER_BW emi_bw;
    EMI_MASTER_SOFTMODE emi_softmode;

#elif defined(MT6276) || defined(MT6256) || defined(MT6573) || defined(MT6255)/* MT6236 || MT6236B */

    EMI_MASTER_BW emi_bw;
    EMI_MASTER_SOFTMODE emi_softmode;

#else /* MT6236 || MT6236B */

    EMI_MASTER_BW emi_bw;
    EMI_MASTER_SOFTMODE emi_softmode;

#endif /* MT6236 || MT6236B */
} EMI_MASTER_LIMITER;



/*********************************************
  *
  * Macro
  *
  ********************************************/

/******
   *
   * EMI query run-time device-mode.
   *
   *****/
#if defined(MT6253T) || defined(MT6253) || defined(MT6252H) || defined(MT6252) || defined(MT6253E) || defined(MT6253L)

#define EMI_DEVICE_MODE_BIT 0x00030000
#define EMI_AMODE_BIT 0x00030000
#define EMI_PMODE_BIT 0x00010000
#define EMI_BMODE_BIT 0x00020000

#define EMI_GET_DEVICE_MODE(con_val) ((EMI_DEVICE_MODE)((con_val & EMI_DEVICE_MODE_BIT)>>16+EMI_ASYNC_MODE))
#define EMI_IS_ASYNC_MODE(con_val) (con_val & EMI_AMODE_BIT == 0? 0: 1)
#define EMI_IS_PAGE_MODE(con_val) (con_val & EMI_PMODE_BIT == 0? 0: 1)
#define EMI_IS_BURST_MODE(con_val) (con_val & EMI_BMODE_BIT == 0? 0: 1)

#elif defined(MT6236) || defined(MT6236B) /* MT6253T || MT6253 || MT6252H || MT6252 || MT6253E || MT6253L */

#define EMI_DEVICE_DRAM_MODE_BIT 0x00030000
#define EMI_AMODE_BIT 0x04000000
#define EMI_PMODE_BIT 0x04000000
#define EMI_BMODE_BIT 0x20000000

#define EMI_IS_ASYNC_MODE(con_val) (con_val & EMI_AMODE_BIT == 0? 1: 0)
#define EMI_IS_PAGE_MODE(con_val) (con_val & EMI_PMODE_BIT == 0? 0: 1)
#define EMI_IS_BURST_MODE(con_val) (con_val & EMI_BMODE_BIT == 0? 0: 1)
#define EMI_GET_DEVICE_DRAM_MODE(con_val) ((EMI_DEVICE_MODE)(((con_val & EMI_DEVICE_DRAM_MODE_BIT)>>16)+EMI_SDR_16_MODE))

#endif /* MT6253T || MT6253 || MT6252H || MT6252 || MT6253E || MT6253L */


/******
   *
   * API for block all EMI transactions.
   *
   *****/
#if defined(MT6276) || defined(MT6256) || defined(MT6255) || defined(MT6280)

#define __EMI_BlockAllTransactions()  \
        do {    \
            *EMI_CONM = 0x003F; \
        } while (0)

#define __EMI_UnblockAllTransactions()  \
        do {    \
            *EMI_CONM = 0x0000; \
        } while (0)

#else /* MT6276 */

#define __EMI_BlockAllTransactions()
#define __EMI_UnblockAllTransactions()

#endif /* MT6276 */


/******
   *
   * API for disable dummy read.
   *
   *****/
#if defined(MT6276) || defined(MT6256) || defined(MT6255) || defined(MT6280)

#define __EMI_DisableDummyRead()  \
        do {    \
            *EMI_DRCT &= ~0x1; \
        } while (0)

#define __EMI_EnableDummyRead()  \
        do {    \
            *EMI_DRCT |= 0x1; \
        } while (0)

#else /* MT6276 */

#define __EMI_DisableDummyRead()
#define __EMI_EnableDummyRead() 

#endif /* MT6276 */


/******
   *
   * API for blocking under EMI enter idle state.
   *
   *****/
#if defined(MT6276) || defined(MT6256) || defined(MT6255) || defined(MT6280)

#define __EMI_WaitEmiEnterIdleState()  \
        do {    \
            while( ( *EMI_CONN & (1<<10) ) == 0 ); \
        } while (0)

#else /* MT6276 */

#define __EMI_WaitEmiEnterIdleState()

#endif /* MT6276 */




/*********************************************
 *
 * (HAL) Internal APIs.
 *
 ********************************************/
 
// Expose
//extern kal_int32 EMI_QueryCurSetting(EMI_RUNTIME_Info* emi_setting);

extern EMI_DEVICE_MODE EMI_QueryDeviceModeByMemType(EMI_MEMTYPE mem_type);		
extern kal_int32 EMI_SetScenarioBW(kal_uint32 scenario);
extern void EMI_reg_dump_init(void);

/* return -1 : fail , 0 : cuccess */
extern int SRAM_repair(REPAIR_MODULE module);
#endif  /* !__EMI_SW_INTERNAL_H__ */

