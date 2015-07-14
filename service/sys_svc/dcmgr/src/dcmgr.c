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
 *   dcmgr.c
 *
 * Project:
 * --------
 *   MAUI (MT6226/MT6227/MT6228/MT6229)
 *
 * Description:
 * ------------
 *   Dynamic Code Manager for dynamic code relocation into TCM(internal SRAM)
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#include "dcmgr.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "dcmgr_comp.h"
#include "simple_memory_manager.h"
#include "lzmadec.h"
#include "verno.h"
#include "cache_sw.h"
#include "us_timer.h"
#include "viva.h"
#if defined(__MTK_TARGET__)

//#define __DCMGR_LOG_LOAD_TIME__
//#define __DCMGR_LOG_DECOMPRESS_TIME__

#if defined(__DYNAMIC_CODE_MANAGER__) || defined(__DCM_WITH_COMPRESSION__)
static kal_semid   g_dcmgr_semid = NULL;
static kal_int32   demgr_lock_count = 0;
#endif /* __DYNAMIC_CODE_MANAGER__ || __DCM_WITH_COMPRESSION__ */

#if defined(__DYNAMIC_CODE_MANAGER__)

#if defined(DCM_SCAT_CODE1_AVAILABLE)
extern kal_uint32 Load$$DYNAMIC_CODE1$$Base;
extern kal_uint32 Image$$DYNAMIC_CODE1$$Length;
extern kal_uint32 Image$$DYNAMIC_CODE1$$ZI$$Length;
#endif

#if defined(DCM_SCAT_CODE2_AVAILABLE)
extern kal_uint32 Load$$DYNAMIC_CODE2$$Base;
extern kal_uint32 Image$$DYNAMIC_CODE2$$Length;
extern kal_uint32 Image$$DYNAMIC_CODE2$$ZI$$Length;
#endif

#if defined(DCM_SCAT_CODE3_AVAILABLE)
extern kal_uint32 Load$$DYNAMIC_CODE3$$Base;
extern kal_uint32 Image$$DYNAMIC_CODE3$$Length;
extern kal_uint32 Image$$DYNAMIC_CODE3$$ZI$$Length;
#endif

#if defined(DCM_SCAT_CODE4_AVAILABLE)
extern kal_uint32 Load$$DYNAMIC_CODE4$$Base;
extern kal_uint32 Image$$DYNAMIC_CODE4$$Length;
extern kal_uint32 Image$$DYNAMIC_CODE4$$ZI$$Length;
#endif

#if defined(DCM_SCAT_CODE5_AVAILABLE)
extern kal_uint32 Load$$DYNAMIC_CODE5$$Base;
extern kal_uint32 Image$$DYNAMIC_CODE5$$Length;
extern kal_uint32 Image$$DYNAMIC_CODE5$$ZI$$Length;
#endif

#if defined(DCM_SCAT_CODE6_AVAILABLE)
extern kal_uint32 Load$$DYNAMIC_CODE6$$Base;
extern kal_uint32 Image$$DYNAMIC_CODE6$$Length;
extern kal_uint32 Image$$DYNAMIC_CODE6$$ZI$$Length;
#endif

#if defined(DCM_SCAT_CODE7_AVAILABLE)
extern kal_uint32 Load$$DYNAMIC_CODE7$$Base;
extern kal_uint32 Image$$DYNAMIC_CODE7$$Length;
extern kal_uint32 Image$$DYNAMIC_CODE7$$ZI$$Length;
#endif

#if defined(DCM_SCAT_CODE8_AVAILABLE)
extern kal_uint32 Load$$DYNAMIC_CODE8$$Base;
extern kal_uint32 Image$$DYNAMIC_CODE8$$Length;
extern kal_uint32 Image$$DYNAMIC_CODE8$$ZI$$Length;
#endif

#if defined(DCM_SCAT_CODE9_AVAILABLE)
extern kal_uint32 Load$$DYNAMIC_CODE9$$Base;
extern kal_uint32 Image$$DYNAMIC_CODE9$$Length;
extern kal_uint32 Image$$DYNAMIC_CODE9$$ZI$$Length;
#endif

#if defined(DCM_SCAT_CODE10_AVAILABLE)
extern kal_uint32 Load$$DYNAMIC_CODE10$$Base;
extern kal_uint32 Image$$DYNAMIC_CODE10$$Length;
extern kal_uint32 Image$$DYNAMIC_CODE10$$ZI$$Length;
#endif

#if defined(DCM_SCAT_CODE11_AVAILABLE)
extern kal_uint32 Load$$DYNAMIC_CODE11$$Base;
extern kal_uint32 Image$$DYNAMIC_CODE11$$Length;
extern kal_uint32 Image$$DYNAMIC_CODE11$$ZI$$Length;
#endif

#if defined(DCM_SCAT_CODE12_AVAILABLE)
extern kal_uint32 Load$$DYNAMIC_CODE12$$Base;
extern kal_uint32 Image$$DYNAMIC_CODE12$$Length;
extern kal_uint32 Image$$DYNAMIC_CODE12$$ZI$$Length;
#endif

#if defined(DCM_SCAT_CODE13_AVAILABLE)
extern kal_uint32 Load$$DYNAMIC_CODE13$$Base;
extern kal_uint32 Image$$DYNAMIC_CODE13$$Length;
extern kal_uint32 Image$$DYNAMIC_CODE13$$ZI$$Length;
#endif

#if defined(DCM_SCAT_CODE14_AVAILABLE)
extern kal_uint32 Load$$DYNAMIC_CODE14$$Base;
extern kal_uint32 Image$$DYNAMIC_CODE14$$Length;
extern kal_uint32 Image$$DYNAMIC_CODE14$$ZI$$Length;
#endif

#if defined(DCM_SCAT_CODE15_AVAILABLE)
extern kal_uint32 Load$$DYNAMIC_CODE15$$Base;
extern kal_uint32 Image$$DYNAMIC_CODE15$$Length;
extern kal_uint32 Image$$DYNAMIC_CODE15$$ZI$$Length;
#endif

#if defined(DCM_SCAT_CODE16_AVAILABLE)
extern kal_uint32 Load$$DYNAMIC_CODE16$$Base;
extern kal_uint32 Image$$DYNAMIC_CODE16$$Length;
extern kal_uint32 Image$$DYNAMIC_CODE16$$ZI$$Length;
#endif

#if defined(DCM_SCAT_CODE17_AVAILABLE)
extern kal_uint32 Load$$DYNAMIC_CODE17$$Base;
extern kal_uint32 Image$$DYNAMIC_CODE17$$Length;
extern kal_uint32 Image$$DYNAMIC_CODE17$$ZI$$Length;
#endif

#if defined(DCM_SCAT_CODE18_AVAILABLE)
extern kal_uint32 Load$$DYNAMIC_CODE18$$Base;
extern kal_uint32 Image$$DYNAMIC_CODE18$$Length;
extern kal_uint32 Image$$DYNAMIC_CODE18$$ZI$$Length;
#endif

#if defined(DCM_SCAT_CODE19_AVAILABLE)
extern kal_uint32 Load$$DYNAMIC_CODE19$$Base;
extern kal_uint32 Image$$DYNAMIC_CODE19$$Length;
extern kal_uint32 Image$$DYNAMIC_CODE19$$ZI$$Length;
#endif

#if defined(DCM_SCAT_CODE20_AVAILABLE)
extern kal_uint32 Load$$DYNAMIC_CODE20$$Base;
extern kal_uint32 Image$$DYNAMIC_CODE20$$Length;
extern kal_uint32 Image$$DYNAMIC_CODE20$$ZI$$Length;
#endif

#if defined(DCM_SCAT_CODE21_AVAILABLE)
extern kal_uint32 Load$$DYNAMIC_CODE21$$Base;
extern kal_uint32 Image$$DYNAMIC_CODE21$$Length;
extern kal_uint32 Image$$DYNAMIC_CODE21$$ZI$$Length;
#endif

#if defined(DCM_SCAT_CODE22_AVAILABLE)
extern kal_uint32 Load$$DYNAMIC_CODE22$$Base;
extern kal_uint32 Image$$DYNAMIC_CODE22$$Length;
extern kal_uint32 Image$$DYNAMIC_CODE22$$ZI$$Length;
#endif

#if defined(DCM_SCAT_CODE23_AVAILABLE)
extern kal_uint32 Load$$DYNAMIC_CODE23$$Base;
extern kal_uint32 Image$$DYNAMIC_CODE23$$Length;
extern kal_uint32 Image$$DYNAMIC_CODE23$$ZI$$Length;
#endif

/* Although introducing compiler warning,
   "C2564W: extended constant initialiser used",
   but code size saved, and readibility improved.
   Base, RO-length, ZI-length */
static const kal_uint32 DCM_linker_symbols_by_dynamic_code_id[DYNAMIC_CODE_NUM * 3] = {
/* DYNCMIC_CODE1 */
   #if defined(DCM_SCAT_CODE1_AVAILABLE)
   (kal_uint32)&Load$$DYNAMIC_CODE1$$Base,
   (kal_uint32)&Image$$DYNAMIC_CODE1$$Length,
   (kal_uint32)&Image$$DYNAMIC_CODE1$$ZI$$Length,
   #else
   0,0,0,
   #endif
/* DYNCMIC_CODE2 */
   #if defined(DCM_SCAT_CODE2_AVAILABLE)
   (kal_uint32)&Load$$DYNAMIC_CODE2$$Base,
   (kal_uint32)&Image$$DYNAMIC_CODE2$$Length,
   (kal_uint32)&Image$$DYNAMIC_CODE2$$ZI$$Length,
   #else
   0,0,0,
   #endif
/* DYNCMIC_CODE3 */
   #if defined(DCM_SCAT_CODE3_AVAILABLE)
   (kal_uint32)&Load$$DYNAMIC_CODE3$$Base,
   (kal_uint32)&Image$$DYNAMIC_CODE3$$Length,
   (kal_uint32)&Image$$DYNAMIC_CODE3$$ZI$$Length,
   #else
   0,0,0,
   #endif
/* DYNCMIC_CODE4 */
   #if defined(DCM_SCAT_CODE4_AVAILABLE)
   (kal_uint32)&Load$$DYNAMIC_CODE4$$Base,
   (kal_uint32)&Image$$DYNAMIC_CODE4$$Length,
   (kal_uint32)&Image$$DYNAMIC_CODE4$$ZI$$Length,
   #else
   0,0,0,
   #endif
/* DYNCMIC_CODE5 */
   #if defined(DCM_SCAT_CODE5_AVAILABLE)
   (kal_uint32)&Load$$DYNAMIC_CODE5$$Base,
   (kal_uint32)&Image$$DYNAMIC_CODE5$$Length,
   (kal_uint32)&Image$$DYNAMIC_CODE5$$ZI$$Length,
   #else
   0,0,0,
   #endif
/* DYNCMIC_CODE6 */
   #if defined(DCM_SCAT_CODE6_AVAILABLE)
   (kal_uint32)&Load$$DYNAMIC_CODE6$$Base,
   (kal_uint32)&Image$$DYNAMIC_CODE6$$Length,
   (kal_uint32)&Image$$DYNAMIC_CODE6$$ZI$$Length,
   #else
   0,0,0,
   #endif
/* DYNCMIC_CODE7 */
   #if defined(DCM_SCAT_CODE7_AVAILABLE)
	  (kal_uint32)&Load$$DYNAMIC_CODE7$$Base,
	  (kal_uint32)&Image$$DYNAMIC_CODE7$$Length,
	  (kal_uint32)&Image$$DYNAMIC_CODE7$$ZI$$Length,
   #else
	  0,0,0,
   #endif
/* DYNCMIC_CODE8 */
   #if defined(DCM_SCAT_CODE8_AVAILABLE)
   (kal_uint32)&Load$$DYNAMIC_CODE8$$Base,
   (kal_uint32)&Image$$DYNAMIC_CODE8$$Length,
   (kal_uint32)&Image$$DYNAMIC_CODE8$$ZI$$Length,
   #else
   0,0,0,
   #endif
/* DYNCMIC_CODE9 */
   #if defined(DCM_SCAT_CODE9_AVAILABLE)
   (kal_uint32)&Load$$DYNAMIC_CODE9$$Base,
   (kal_uint32)&Image$$DYNAMIC_CODE9$$Length,
   (kal_uint32)&Image$$DYNAMIC_CODE9$$ZI$$Length,
   #else
   0,0,0,
   #endif
/* DYNCMIC_CODE10 */
   #if defined(DCM_SCAT_CODE10_AVAILABLE)
   (kal_uint32)&Load$$DYNAMIC_CODE10$$Base,
   (kal_uint32)&Image$$DYNAMIC_CODE10$$Length,
   (kal_uint32)&Image$$DYNAMIC_CODE10$$ZI$$Length,
   #else
   0,0,0,
   #endif
/* DYNAMIC_CODE11 */
   #if defined(DCM_SCAT_CODE11_AVAILABLE)
   (kal_uint32)&Load$$DYNAMIC_CODE11$$Base,
   (kal_uint32)&Image$$DYNAMIC_CODE11$$Length,
   (kal_uint32)&Image$$DYNAMIC_CODE11$$ZI$$Length,
   #else
   0,0,0,
   #endif

/* DYNAMIC_CODE12 */
   #if defined(DCM_SCAT_CODE12_AVAILABLE)
   (kal_uint32)&Load$$DYNAMIC_CODE12$$Base,
   (kal_uint32)&Image$$DYNAMIC_CODE12$$Length,
   (kal_uint32)&Image$$DYNAMIC_CODE12$$ZI$$Length,
   #else
   0,0,0,
   #endif
   
/* DYNAMIC_CODE13 */
   #if defined(DCM_SCAT_CODE13_AVAILABLE)
   (kal_uint32)&Load$$DYNAMIC_CODE13$$Base,
   (kal_uint32)&Image$$DYNAMIC_CODE13$$Length,
   (kal_uint32)&Image$$DYNAMIC_CODE13$$ZI$$Length,
   #else
   0,0,0,
   #endif
   
/* DYNAMIC_CODE14 */
   #if defined(DCM_SCAT_CODE14_AVAILABLE)
   (kal_uint32)&Load$$DYNAMIC_CODE14$$Base,
   (kal_uint32)&Image$$DYNAMIC_CODE14$$Length,
   (kal_uint32)&Image$$DYNAMIC_CODE14$$ZI$$Length,
   #else
   0,0,0,
   #endif

/* DYNAMIC_CODE15 */
   #if defined(DCM_SCAT_CODE15_AVAILABLE)
   (kal_uint32)&Load$$DYNAMIC_CODE15$$Base,
   (kal_uint32)&Image$$DYNAMIC_CODE15$$Length,
   (kal_uint32)&Image$$DYNAMIC_CODE15$$ZI$$Length,
   #else
   0,0,0,
   #endif
/* DYNAMIC_CODE16 */
   #if defined(DCM_SCAT_CODE16_AVAILABLE)
   (kal_uint32)&Load$$DYNAMIC_CODE16$$Base,
   (kal_uint32)&Image$$DYNAMIC_CODE16$$Length,
   (kal_uint32)&Image$$DYNAMIC_CODE16$$ZI$$Length,
   #else
   0,0,0,
   #endif
   
/* DYNAMIC_CODE17 */
   #if defined(DCM_SCAT_CODE17_AVAILABLE)
   (kal_uint32)&Load$$DYNAMIC_CODE17$$Base,
   (kal_uint32)&Image$$DYNAMIC_CODE17$$Length,
   (kal_uint32)&Image$$DYNAMIC_CODE17$$ZI$$Length,
   #else
   0,0,0,
   #endif
   
/* DYNAMIC_CODE18 */
   #if defined(DCM_SCAT_CODE18_AVAILABLE)
   (kal_uint32)&Load$$DYNAMIC_CODE18$$Base,
   (kal_uint32)&Image$$DYNAMIC_CODE18$$Length,
   (kal_uint32)&Image$$DYNAMIC_CODE18$$ZI$$Length,
   #else
   0,0,0,
   #endif
   
/* DYNAMIC_CODE19 */
   #if defined(DCM_SCAT_CODE19_AVAILABLE)
   (kal_uint32)&Load$$DYNAMIC_CODE19$$Base,
   (kal_uint32)&Image$$DYNAMIC_CODE19$$Length,
   (kal_uint32)&Image$$DYNAMIC_CODE19$$ZI$$Length,
   #else
   0,0,0,
   #endif

/* DYNAMIC_CODE20 */
   #if defined(DCM_SCAT_CODE20_AVAILABLE)
   (kal_uint32)&Load$$DYNAMIC_CODE20$$Base,
   (kal_uint32)&Image$$DYNAMIC_CODE20$$Length,
   (kal_uint32)&Image$$DYNAMIC_CODE20$$ZI$$Length,
   #else
   0,0,0,
   #endif

/* DYNAMIC_CODE21 */
   #if defined(DCM_SCAT_CODE21_AVAILABLE)
   (kal_uint32)&Load$$DYNAMIC_CODE21$$Base,
   (kal_uint32)&Image$$DYNAMIC_CODE21$$Length,
   (kal_uint32)&Image$$DYNAMIC_CODE21$$ZI$$Length,
   #else
   0,0,0,
   #endif
   
/* DYNAMIC_CODE22 */
   #if defined(DCM_SCAT_CODE22_AVAILABLE)
   (kal_uint32)&Load$$DYNAMIC_CODE22$$Base,
   (kal_uint32)&Image$$DYNAMIC_CODE22$$Length,
   (kal_uint32)&Image$$DYNAMIC_CODE22$$ZI$$Length,
   #else
   0,0,0,
   #endif
   
/* DYNAMIC_CODE23 */
   #if defined(DCM_SCAT_CODE23_AVAILABLE)
   (kal_uint32)&Load$$DYNAMIC_CODE23$$Base,
   (kal_uint32)&Image$$DYNAMIC_CODE23$$Length,
   (kal_uint32)&Image$$DYNAMIC_CODE23$$ZI$$Length,
   #else
   0,0,0,
   #endif      
};

static kal_int32 current_dynamic_code_id[DCM_TARGET_NUM] = {
#if defined(DCM_TARGET_ADDRESS1)
     DYNAMIC_CODE_NONE,
#endif
#if defined(DCM_TARGET_ADDRESS2)
     DYNAMIC_CODE_NONE,
#endif
#if defined(DCM_TARGET_ADDRESS3)
     DYNAMIC_CODE_NONE,
#endif
};

static const kal_uint32 *DCM_target_pool_addr[DCM_TARGET_NUM] = {
#if defined(DCM_TARGET_ADDRESS1)
    (kal_uint32*) DCM_TARGET_ADDRESS1,
#endif
#if defined(DCM_TARGET_ADDRESS2)
    (kal_uint32*) DCM_TARGET_ADDRESS2,
#endif
#if defined(DCM_TARGET_ADDRESS3)
    (kal_uint32*) DCM_TARGET_ADDRESS3,
#endif
};

static const kal_uint32 DCM_target_pool_size[DCM_TARGET_NUM] = {
#if defined(DCM_TARGET_SIZE1)
    DCM_TARGET_SIZE1,
#endif
#if defined(DCM_TARGET_ADDRESS2)
    DCM_TARGET_SIZE2,
#endif
#if defined(DCM_TARGET_ADDRESS3)
    DCM_TARGET_SIZE3,
#endif
};
#endif /* __DYNAMIC_CODE_MANAGER__  */


#if defined(__DCM_WITH_COMPRESSION__)

/* 
 * imported function
 */
extern kal_bool INT_QueryExceptionStatus(void);
extern kal_uint32 custom_get_fat_addr(void);
extern kal_uint32 INT_RetrieveRemappedFlashBaseAddr(void);

/*
 * import global variable
 */

extern unsigned int Load$$ZIMAGE$$Base;
extern unsigned int Image$$ZIMAGE$$Length;
extern unsigned int Load$$DYNAMIC_COMP_CODE$$Base;
extern unsigned int Load$$JUMP_TABLE$$Base;

/* 
 * forward declaration 
 */
static void* decomp_mem_alloc(void* mem_ptr, kal_uint32 mem_size);
static void decomp_mem_free(void* mem_ptr, void* mem_address);
/* 
 * global variables 
 */
/* !!CAUTION!!
 * Following pointer must have volatile attribute to ensure that 
 * the compressed file header would be read from flash.
 * Otherwise, compiler would do optimization according to the dummy header content 
 * which would be updated by build script during image compression stage.
 */
volatile dcmgr_comp_header_t const *dcmgr_code_ptr = NULL;
kal_uint32 dcmgr_comp_image_num;
kal_uint32 dcmgr_decomp_buff_pool[DCMGR_DECOMP_BUFF_SIZE>>2];

/* 
 * static variables 
 */
static STSMM _dcmgr_decompress_smm;
static ISzAlloc dcmgr_decomp_Alloc = { decomp_mem_alloc, decomp_mem_free };

#ifdef __MTK_TARGET__
#pragma arm section rodata = "DYNAMIC_DUMMY_CODE_HEAD"
#endif /* __MTK_TARGET__ */
const kal_uint32 dcmgr_dummy_dynamic_code_head = DCMGR_KEY_ID_HEAD;
const dcmgr_comp_header_t dcmgr_dynamic_code_hdr = {
    DCMGR_KEY_ID_HEAD, DCMGR_KEY_ID_TAIL, VERNO_STR, 
    {HW_VER_STR " " BUILD_DATE_TIME_STR}, 0, 0
};
#ifdef __MTK_TARGET__
#pragma arm section rodata
#endif /* __MTK_TARGET__ */

#ifdef __MTK_TARGET__
#pragma arm section rodata = "DYNAMIC_DUMMY_CODE_END"
#endif /* __MTK_TARGET__ */
const kal_uint32 dcmgr_dummy_dynamic_code_end = DCMGR_KEY_ID_DUMMY;
#ifdef __MTK_TARGET__
#pragma arm section rodata
#endif /* __MTK_TARGET__ */

#if defined(DCM_COMP_SCAT_SBC_AVAILABLE)
extern kal_uint32 Load$$DYNAMIC_COMP_SBC$$Base;

extern kal_uint32 Image$$DYNAMIC_COMP_SBC$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_SBC$$Length;
extern kal_uint32 Image$$DYNAMIC_COMP_SBC_BODY$$Length;
extern kal_uint32 Image$$DYNAMIC_COMP_SBC_BODY$$ZI$$Length;

#pragma arm section rodata = "DYNAMIC_COMP_SBC_HEAD"
const dcmgr_image_header_t   dcmgr_dynamic_comp_sbc_head = {
    DCMGR_COMPRESS_ID, 0x31322D44, DYNAMIC_CODE_COMPRESS_SBC, (kal_uint32)&Image$$DYNAMIC_COMP_SBC$$Base
};
#pragma arm section rodata

#endif /* DCM_COMP_SCAT_SBC_AVAILABLE */

#if defined(DCM_COMP_SCAT_RESAMPLE_AVAILABLE)
extern kal_uint32 Load$$DYNAMIC_COMP_RESAMPLE$$Base;

extern kal_uint32 Image$$DYNAMIC_COMP_RESAMPLE$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_RESAMPLE$$Length;
extern kal_uint32 Image$$DYNAMIC_COMP_RESAMPLE_BODY$$Length;
extern kal_uint32 Image$$DYNAMIC_COMP_RESAMPLE_BODY$$ZI$$Length;

#pragma arm section rodata = "DYNAMIC_COMP_RESAMPLE_HEAD"
const dcmgr_image_header_t   dcmgr_dynamic_comp_resample_head = {
    DCMGR_COMPRESS_ID, 0x31322D44, DYNAMIC_CODE_COMPRESS_RESAMPLE, (kal_uint32)&Image$$DYNAMIC_COMP_RESAMPLE$$Base
};
#pragma arm section rodata

#endif /* DCM_COMP_SCAT_RESAMPLE_AVAILABLE */

#if defined(DCM_COMP_SCAT_BESLOUDNESS_AVAILABLE)
extern kal_uint32 Load$$DYNAMIC_COMP_BESLOUDNESS$$Base;

extern kal_uint32 Imag$$DYNAMIC_COMP_BESLOUDNESS$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_BESLOUDNESS$$Length;
extern kal_uint32 Image$$DYNAMIC_COMP_BESLOUDNESS_BODY$$Length;
extern kal_uint32 Image$$DYNAMIC_COMP_BESLOUDNESS_BODY$$ZI$$Length;

#pragma arm section rodata = "DYNAMIC_COMP_BESLOUDNESS_HEAD"
const dcmgr_image_header_t   dcmgr_dynamic_comp_besloudness_head = {
    DCMGR_COMPRESS_ID, 0x31322D44, DYNAMIC_CODE_COMPRESS_BESLOUDNESS, (kal_uint32)&Image$$DYNAMIC_COMP_BESLOUDNESS$$Base
};
#pragma arm section rodata

#endif /* DCM_COMP_SCAT_BESLOUDNESS_AVAILABLE */

#if defined(DCM_COMP_SCAT_MP4DEC_AVAILABLE)
extern kal_uint32 Load$$DYNAMIC_COMP_MP4DEC$$Base;

extern kal_uint32 Imag$$DYNAMIC_COMP_MP4DEC$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_MP4DEC$$Length;
extern kal_uint32 Image$$DYNAMIC_COMP_MP4DEC_BODY$$Length;
extern kal_uint32 Image$$DYNAMIC_COMP_MP4DEC_BODY$$ZI$$Length;

#pragma arm section rodata = "DYNAMIC_COMP_MP4DEC_HEAD"
const dcmgr_image_header_t   dcmgr_dynamic_comp_mp4dec_head = {
    DCMGR_COMPRESS_ID, 0x31322D44, DYNAMIC_CODE_COMPRESS_MP4DEC_C, (kal_uint32)&Image$$DYNAMIC_COMP_MP4DEC$$Base
};
#pragma arm section rodata

#endif /* DCM_COMP_SCAT_MP4DEC_AVAILABLE */

#if defined(DCM_COMP_SCAT_MP4ENC_AVAILABLE)
extern kal_uint32 Load$$DYNAMIC_COMP_MP4ENC$$Base;

extern kal_uint32 Imag$$DYNAMIC_COMP_MP4ENC$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_MP4ENC$$Length;
extern kal_uint32 Image$$DYNAMIC_COMP_MP4ENC_BODY$$Length;
extern kal_uint32 Image$$DYNAMIC_COMP_MP4ENC_BODY$$ZI$$Length;

#pragma arm section rodata = "DYNAMIC_COMP_MP4ENC_HEAD"
const dcmgr_image_header_t   dcmgr_dynamic_comp_mp4enc_head = {
    DCMGR_COMPRESS_ID, 0x31322D44, DYNAMIC_CODE_COMPRESS_MP4ENC_C, (kal_uint32)&Image$$DYNAMIC_COMP_MP4ENC$$Base
};
#pragma arm section rodata

#endif /* DCM_COMP_SCAT_MP4ENC_AVAILABLE */

#if defined(DCM_COMP_SCAT_H264DEC_AVAILABLE)
extern kal_uint32 Load$$DYNAMIC_COMP_H264DEC$$Base;

extern kal_uint32 Imag$$DYNAMIC_COMP_H264DEC$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_H264DEC$$Length;
extern kal_uint32 Image$$DYNAMIC_COMP_H264DEC_BODY$$Length;
extern kal_uint32 Image$$DYNAMIC_COMP_H264DEC_BODY$$ZI$$Length;

#pragma arm section rodata = "DYNAMIC_COMP_H264DEC_HEAD"
const dcmgr_image_header_t   dcmgr_dynamic_comp_h264dec_head = {
    DCMGR_COMPRESS_ID, 0x31322D44, DYNAMIC_CODE_COMPRESS_H264DEC_C, (kal_uint32)&Image$$DYNAMIC_COMP_H264DEC$$Base
};
#pragma arm section rodata

#endif /* DCM_COMP_SCAT_H264DEC_AVAILABLE */

static const dcmgr_image_header_t* DCM_image_list[DYNAMIC_CODE_COMPRESS_NUM+1] = {
#if defined(DCM_COMP_SCAT_SBC_AVAILABLE)
    &dcmgr_dynamic_comp_sbc_head,
#endif

#if defined(DCM_COMP_SCAT_RESAMPLE_AVAILABLE)
    &dcmgr_dynamic_comp_resample_head,
#endif

#if defined(DCM_COMP_SCAT_BESLOUDNESS_AVAILABLE)
    &dcmgr_dynamic_comp_besloudness_head,
#endif

#if defined(DCM_COMP_SCAT_MP4DEC_AVAILABLE)
    &dcmgr_dynamic_comp_mp4dec_head,
#endif

#if defined(DCM_COMP_SCAT_H264DEC_AVAILABLE)
    &dcmgr_dynamic_comp_h264dec_head,
#endif

#if defined(DCM_COMP_SCAT_MP4ENC_AVAILABLE)
    &dcmgr_dynamic_comp_mp4enc_head,
#endif

    NULL
};

static const kal_uint32 DCM_comp_linker_symbols_by_dynamic_code_id[DYNAMIC_CODE_COMPRESS_NUM * 4] = {
/* DYNAMIC_SBC */
   #if defined(DCM_COMP_SCAT_SBC_AVAILABLE)
   (kal_uint32)&Image$$DYNAMIC_COMP_SBC$$Base,
   (kal_uint32)&Image$$DYNAMIC_COMP_SBC$$Length,
   (kal_uint32)&Image$$DYNAMIC_COMP_SBC_BODY$$Length,
   (kal_uint32)&Image$$DYNAMIC_COMP_SBC_BODY$$ZI$$Length,
   #else
   0,0,0,0,
   #endif

/* DYNAMIC_RESAMPLE */
   #if defined(DCM_COMP_SCAT_RESAMPLE_AVAILABLE)
   (kal_uint32)&Image$$DYNAMIC_COMP_RESAMPLE$$Base,
   (kal_uint32)&Image$$DYNAMIC_COMP_RESAMPLE$$Length,
   (kal_uint32)&Image$$DYNAMIC_COMP_RESAMPLE_BODY$$Length,
   (kal_uint32)&Image$$DYNAMIC_COMP_RESAMPLE_BODY$$ZI$$Length,
   #else
   0,0,0,0,
   #endif

/* DYNAMIC_BESLOUDNESS */
   #if defined(DCM_COMP_SCAT_BESLOUDNESS_AVAILABLE)
   (kal_uint32)&Image$$DYNAMIC_COMP_BESLOUDNESS$$Base,
   (kal_uint32)&Image$$DYNAMIC_COMP_BESLOUDNESS$$Length,
   (kal_uint32)&Image$$DYNAMIC_COMP_BESLOUDNESS_BODY$$Length,
   (kal_uint32)&Image$$DYNAMIC_COMP_BESLOUDNESS_BODY$$ZI$$Length,
   #else
   0,0,0,0,
   #endif

/* DYNAMIC_MP4DEC */
   #if defined(DCM_COMP_SCAT_MP4DEC_AVAILABLE)
   (kal_uint32)&Image$$DYNAMIC_COMP_MP4DEC$$Base,
   (kal_uint32)&Image$$DYNAMIC_COMP_MP4DEC$$Length,
   (kal_uint32)&Image$$DYNAMIC_COMP_MP4DEC_BODY$$Length,
   (kal_uint32)&Image$$DYNAMIC_COMP_MP4DEC_BODY$$ZI$$Length,
   #else
   0,0,0,0,
   #endif

/* DYNAMIC_H264DEC */
   #if defined(DCM_COMP_SCAT_H264DEC_AVAILABLE)
   (kal_uint32)&Image$$DYNAMIC_COMP_H264DEC$$Base,
   (kal_uint32)&Image$$DYNAMIC_COMP_H264DEC$$Length,
   (kal_uint32)&Image$$DYNAMIC_COMP_H264DEC_BODY$$Length,
   (kal_uint32)&Image$$DYNAMIC_COMP_H264DEC_BODY$$ZI$$Length,
   #else
   0,0,0,0,
   #endif

/* DYNAMIC_MP4ENC */
   #if defined(DCM_COMP_SCAT_MP4ENC_AVAILABLE)
   (kal_uint32)&Image$$DYNAMIC_COMP_MP4ENC$$Base,
   (kal_uint32)&Image$$DYNAMIC_COMP_MP4ENC$$Length,
   (kal_uint32)&Image$$DYNAMIC_COMP_MP4ENC_BODY$$Length,
   (kal_uint32)&Image$$DYNAMIC_COMP_MP4ENC_BODY$$ZI$$Length,
   #else
   0,0,0,0,
   #endif

};

static kal_int32 current_comp_dynamic_code_id[DCM_COMP_TARGET_NUM] = {
#if defined(DCM_COMP_TARGET_ADDRESS1)
     DYNAMIC_CODE_COMPRESS_NONE,
#endif
#if defined(DCM_COMP_TARGET_ADDRESS2)
     DYNAMIC_CODE_COMPRESS_NONE,
#endif
#if defined(DCM_COMP_TARGET_ADDRESS3)
     DYNAMIC_CODE_COMPRESS_NONE,
#endif
};

static const kal_uint32 *DCM_comp_target_pool_addr[DCM_COMP_TARGET_NUM] = {
#if defined(DCM_COMP_TARGET_ADDRESS1)
    (kal_uint32*) DCM_COMP_TARGET_ADDRESS1,
#endif
#if defined(DCM_COMP_TARGET_ADDRESS2)
    (kal_uint32*) DCM_COMP_TARGET_ADDRESS2,
#endif
#if defined(DCM_COMP_TARGET_ADDRESS3)
    (kal_uint32*) DCM_COMP_TARGET_ADDRESS3,
#endif
};

static const kal_uint32 DCM_comp_target_pool_size[DCM_COMP_TARGET_NUM] = {
#if defined(DCM_COMP_TARGET_ADDRESS1)
    DCM_COMP_TARGET_SIZE1,
#endif
#if defined(DCM_COMP_TARGET_ADDRESS2)
    DCM_COMP_TARGET_SIZE2,
#endif
#if defined(DCM_COMP_TARGET_ADDRESS3)
    DCM_COMP_TARGET_SIZE3,
#endif
};


#endif /* __DCM_WITH_COMPRESSION__ */

/*************************************************************************
*  don't modify anything behind this line ; unless bug fix
**************************************************************************/
#if defined(__DYNAMIC_CODE_MANAGER__)
static const kal_int32 DCM_pool_by_dynamic_code_id[DYNAMIC_CODE_NUM] = {
	DCM_TARGET_CONFIGURE
};
#endif /* __DYNAMIC_CODE_MANAGER__ */

#if defined(__DCM_WITH_COMPRESSION__)

static const kal_int32 DCM_comp_pool_by_dynamic_code_id[DYNAMIC_CODE_COMPRESS_NUM] = {
	DCM_COMP_TARGET_CONFIGURE
};

/*************************************************************************
* FUNCTION
*  decomp_mem_init
*
* DESCRIPTION
*   Dynamic code manager for decompress and relocate code into the overlay RAM region 
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
static void decomp_mem_init(void* buff_ptr, kal_uint32 buff_size)
{
    smmInit(&_dcmgr_decompress_smm, buff_ptr, buff_size);
}

/*************************************************************************
* FUNCTION
*  decomp_mem_alloc
*
* DESCRIPTION
*   Dynamic code manager for decompress and relocate code into the overlay RAM region 
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
static void* decomp_mem_alloc(void* mem_ptr, kal_uint32 mem_size)
{
    return smmMallocAligned(&_dcmgr_decompress_smm, mem_size, 4);
}

/*************************************************************************
* FUNCTION
*  decomp_mem_free
*
* DESCRIPTION
*   Dynamic code manager for decompress and relocate code into the overlay RAM region 
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
static void decomp_mem_free(void* mem_ptr, void* mem_address)
{
    /* do nothing */
}
/*************************************************************************
* FUNCTION
*  dcmgr_decomp_load
*
* DESCRIPTION
*   Dynamic code manager for decompress and relocate code into the overlay RAM region 
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
static void dcmgr_decomp_load(kal_uint32* dest_ptr, kal_uint32* src_ptr, kal_int32 img_size, kal_uint32 src_size)
{
    kal_uint32 destsize = 0, srcsize = 0;
    ELzmaStatus status;
    SRes ret;
#if defined(__DCMGR_LOG_DECOMPRESS_TIME__)
    static kal_uint32 dec_start = 0, dec_end = 0, dec_dur = 0;
    dec_start = ust_get_current_time();
#endif
    /* initialize malloc pool */
    decomp_mem_init(dcmgr_decomp_buff_pool, DCMGR_DECOMP_BUFF_SIZE);
    /* decompress target image */
    destsize = img_size;
    srcsize = src_size-13;

    ret = LzmaDecode((Byte*)dest_ptr, &destsize, ((const Byte*)src_ptr)+13, &srcsize, 
                     (const Byte*)src_ptr, LZMA_PROPS_SIZE, LZMA_FINISH_ANY, &status, 
                     &dcmgr_decomp_Alloc);
    EXT_ASSERT(ret == SZ_OK, ret, (kal_uint32)dest_ptr, (kal_uint32)src_ptr);

    /* clean and invalidate D-cache */
#if defined(__DYNAMIC_SWITCH_CACHEABILITY__)
    clean_and_invalidate_dcache((kal_uint32)dest_ptr, (img_size+0x1f)&(~0x1f));
#endif /* __DYNAMIC_SWITCH_CACHEABILITY__ */

    /* invalidate I-cache */
#if defined(__DYNAMIC_SWITCH_CACHEABILITY__) || defined(__WRITE_THROUGH_CACHEABLE__)
    invalidate_icache((kal_uint32)dest_ptr, (img_size+0x1f)&(~0x1f));
#endif /* __DYNAMIC_SWITCH_CACHEABILITY__ || __WRITE_THROUGH_CACHEABLE__ */

#if defined(__DCMGR_LOG_DECOMPRESS_TIME__)
    dec_end = ust_get_current_time();
    dec_dur = ust_get_duration(dec_start, dec_end);
#endif
}

#else /* __DCM_WITH_COMPRESSION__ */
/* dummy decompression loader if DCM with compression is not enabled. */
//static void dcmgr_decomp_load(kal_uint32* dest_ptr, kal_uint32* src_ptr, kal_int32 img_size, kal_uint32 src_size) { }

#endif /* __DCM_WITH_COMPRESSION__ */

#if defined(__DYNAMIC_CODE_MANAGER__) || defined(__DCM_WITH_COMPRESSION__)

/*************************************************************************
* FUNCTION
*  dcmgr_copy_load
*
* DESCRIPTION
*   Dynamic code manager for relocate code into the overlay TCM region 
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
static void dcmgr_copy_load(kal_uint32* dest_ptr, kal_uint32* src_ptr,  kal_int32 img_size, kal_uint32 src_size)
{
    kal_mem_cpy(dest_ptr, src_ptr, img_size);
}

/*************************************************************************
* FUNCTION
*  DCM_Load
*
* DESCRIPTION
*   Dynamic code manager for relocate code into the overlay TCM region 
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
void DCM_Load( kal_int32 dynamic_code_id, kal_uint32 **remaining_buf, kal_uint32 *buf_size )
{
   kal_uint32 *src_ptr=0, *dst_ptr;
   kal_uint32 code_size=0, zi_size=0, src_size = 0, dst_addr = 0;
   kal_int32  pool_id;
   kal_int32  temp;
   kal_uint32 pool_num = 0;
   kal_int32  invalid_id = 0;
   kal_int32 *curr_id_ptr = NULL;
   kal_uint32 idx = 0;
   kal_uint32 align_check = 0;
   load_func_ptr    curr_loader_ptr = NULL;
   const kal_int32 *pool_by_id_ptr = NULL;
   //const kal_uint32 *linker_symbol_ptr = NULL;
   const kal_uint32 **pool_addr_ptr = NULL;
   const kal_uint32 *pool_size_ptr = NULL;
#if defined(__DCMGR_LOG_LOAD_TIME__)
    static kal_uint32 load_start = 0, load_end = 0, load_dur = 0;
    load_start = ust_get_current_time();
#endif
     
   /* invalid code id --- query available address & length */
   if( 
#if defined(__DYNAMIC_CODE_MANAGER__)
       (dynamic_code_id < 0 || dynamic_code_id >= DYNAMIC_CODE_NUM) 
#endif /* __DYNAMIC_CODE_MANAGER__ */
#if defined(__DCM_WITH_COMPRESSION__)
   #if defined(__DYNAMIC_CODE_MANAGER__)
       && 
   #endif /* __DYNAMIC_CODE_MANAGER__ */
       (dynamic_code_id < DYNAMIC_CODE_COMPRESS_BEGIN || dynamic_code_id >= DYNAMIC_CODE_COMPRESS_END) 
#endif /* __DCM_WITH_COMPRESSION__ */
     ) 
   {   
      /* 
       * Assert due to invalid code id.
       */
#define  INVALID_CODE_ID     0
       ASSERT(INVALID_CODE_ID);
       return;
   }
   else
   {   

   /* valid code id --- check source exists and check target pool already occupied */
#if defined(__DYNAMIC_CODE_MANAGER__)
      if(dynamic_code_id < DYNAMIC_CODE_NUM)
      {   
          /* DCM with TCM case */
          pool_by_id_ptr = DCM_pool_by_dynamic_code_id;
          curr_id_ptr = current_dynamic_code_id;
          //linker_symbol_ptr = DCM_linker_symbols_by_dynamic_code_id;
          pool_addr_ptr = DCM_target_pool_addr;
          pool_size_ptr = DCM_target_pool_size;
          pool_num = DCM_TARGET_NUM;
          invalid_id = DYNAMIC_CODE_NONE;
          curr_loader_ptr = dcmgr_copy_load;
          /* setup src address, length */
          src_ptr = (kal_uint32 *)DCM_linker_symbols_by_dynamic_code_id[(dynamic_code_id&DYNAMIC_POOL_ID_MASK) * 3 + 0];
          code_size = DCM_linker_symbols_by_dynamic_code_id[(dynamic_code_id&DYNAMIC_POOL_ID_MASK) * 3 + 1];
          zi_size = DCM_linker_symbols_by_dynamic_code_id[(dynamic_code_id&DYNAMIC_POOL_ID_MASK) * 3 + 2];
          /* 4 byte alignment is required */
          align_check = 3;
          src_size = DCMGR_INVALID_VAL;
          dst_addr = DCMGR_INVALID_VAL;
      }
#endif /* __DYNAMIC_CODE_MANAGER__ */
#if defined(__DCM_WITH_COMPRESSION__)
      if( (dynamic_code_id < DYNAMIC_CODE_COMPRESS_END) && (dynamic_code_id >= DYNAMIC_CODE_COMPRESS_BEGIN) )
      {
          /* DCM with compression case */
          pool_by_id_ptr = DCM_comp_pool_by_dynamic_code_id;
          curr_id_ptr = current_comp_dynamic_code_id;
          //linker_symbol_ptr = DCM_comp_linker_symbols_by_dynamic_code_id;
          pool_addr_ptr = DCM_comp_target_pool_addr;
          pool_size_ptr = DCM_comp_target_pool_size;
          pool_num = DCM_COMP_TARGET_NUM;
          invalid_id = DYNAMIC_CODE_COMPRESS_NONE;
          curr_loader_ptr = dcmgr_decomp_load;

          /* setup src address, length */
          //code_size = DCM_comp_linker_symbols_by_dynamic_code_id[(dynamic_code_id&DYNAMIC_POOL_ID_MASK) * 4 + 1]+
          //            DCM_comp_linker_symbols_by_dynamic_code_id[(dynamic_code_id&DYNAMIC_POOL_ID_MASK) * 4 + 2];
          zi_size = DCM_comp_linker_symbols_by_dynamic_code_id[(dynamic_code_id&DYNAMIC_POOL_ID_MASK) * 4 + 3];

          for(idx = 0 ; idx < dcmgr_comp_image_num ; idx++)
          {
              if(dcmgr_code_ptr->dcmgr_img_list[idx].dcmgr_exec_info.dcmgr_img_id == dynamic_code_id)
              {
                  /* image to be loaded is found */
                  src_ptr = (kal_uint32 *)(((kal_uint32)dcmgr_code_ptr)+
                                           dcmgr_code_ptr->dcmgr_img_list[idx].dcmgr_file_pos);
                  code_size = dcmgr_code_ptr->dcmgr_img_list[idx].dcmgr_bin_size;
                  src_size = dcmgr_code_ptr->dcmgr_img_list[idx].dcmgr_comp_size;
                  dst_addr = dcmgr_code_ptr->dcmgr_img_list[idx].dcmgr_exec_info.dcmgr_img_exec_base;
                  break;
              }
          }
          /* compressed binary with corresponding ID is not found */
          EXT_ASSERT( idx < dcmgr_comp_image_num, dynamic_code_id, 0 , 0);
          /* byte alignment is enough */
          align_check = 0;
      }
#endif /* __DCM_WITH_COMPRESSION__ */

      /* get target execution pool index */
      pool_id = pool_by_id_ptr[dynamic_code_id&DYNAMIC_POOL_ID_MASK];
      pool_id--;   /* SEE Also : DCM_TARGET_CONFIGURE definiation */

      /* enter critical scetion to protect shared resource */
      DCMGR_ENTER_CRITICAL_SECTION

#define  DCM_SOURCE_NOT_EXISTS 0
      if (pool_id < 0 || pool_id >= pool_num)
         ASSERT(DCM_SOURCE_NOT_EXISTS);

#define  DCM_POOL_OCCUPIED     0
      if (curr_id_ptr[pool_id] != invalid_id)
         EXT_ASSERT( DCM_POOL_OCCUPIED,
                     (kal_uint32)curr_id_ptr[pool_id],
                     (kal_uint32)dynamic_code_id, 
                     (kal_uint32)pool_id);

   /* setup src address, length */
#define  DCM_CHECK_FOUR_BYTE_ALIGN   0
      EXT_ASSERT( ((kal_uint32)src_ptr&align_check)==0 && (code_size&align_check)==0, \
                 (kal_uint32)src_ptr, (kal_uint32)code_size, 0);
      EXT_ASSERT( (zi_size&3)==0, (kal_uint32)zi_size, 0 , 0);
   
      /* get target execution pool address */
      dst_ptr = (kal_uint32*) pool_addr_ptr[pool_id];
      if(DCMGR_INVALID_VAL != dst_addr)
      {
          /* check the consistence between code and compressed image */
          EXT_ASSERT( dst_addr == (kal_uint32)dst_ptr, dst_addr, (kal_uint32)dst_ptr, 0);
      }

      temp = pool_size_ptr[pool_id] - code_size - zi_size;

      /* Move code from flash into ISRAM/TCM/External RAM */
      curr_loader_ptr(dst_ptr, src_ptr, code_size, src_size);
   
      /* TODO: potential alignment issue that causes out of valid range access */
      dst_ptr += (code_size+3)>>2;
      src_ptr += (code_size+3)>>2;
   /* Clean ZI data area */
   while( zi_size > 0 ) 
   {        
      *dst_ptr++ = 0;
      zi_size -= 4;
   }

   if( remaining_buf != (kal_uint32**)0) 
   {
      *remaining_buf = dst_ptr;
      *buf_size = temp;
   }
   
   /* clean the remaining buffer */
   while ( temp > 0 ) 
   { 
      *dst_ptr++ = 0;
      temp -= 4;
   }

      curr_id_ptr[pool_id] = dynamic_code_id;

      /* loading process is done */
      DCMGR_LEAVE_CRITICAL_SECTION
   }

#if defined(__DCMGR_LOG_LOAD_TIME__)
    load_end = ust_get_current_time();
    load_dur = ust_get_duration(load_start, load_end);
#endif
}


/*************************************************************************
* FUNCTION
*   DCM_Unload
*
* DESCRIPTION
*   Terminate the usage of DCM
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
void DCM_Unload( kal_int32 dynamic_code_id ) /* TODO - add DCM with compression support */
{
   if( 
#if defined(__DYNAMIC_CODE_MANAGER__)
       (dynamic_code_id < 0 || dynamic_code_id >= DYNAMIC_CODE_NUM)
#endif /* __DYNAMIC_CODE_MANAGER__ */
#if defined(__DCM_WITH_COMPRESSION__)
   #if defined(__DYNAMIC_CODE_MANAGER__)
       &&
   #endif /* __DYNAMIC_CODE_MANAGER__ */
       (dynamic_code_id < DYNAMIC_CODE_COMPRESS_BEGIN || dynamic_code_id >= DYNAMIC_CODE_COMPRESS_END) 
#endif /* __DCM_WITH_COMPRESSION__ */
     )
   {   
      /* do-nothing */
   }
   else
   {
      /* enter critical scetion to protect shared resource */
      DCMGR_ENTER_CRITICAL_SECTION

#if defined(__DYNAMIC_CODE_MANAGER__)
      if(dynamic_code_id < DYNAMIC_CODE_NUM)
      {
          current_dynamic_code_id[DCM_pool_by_dynamic_code_id[dynamic_code_id&DYNAMIC_POOL_ID_MASK] - 1] 
          = DYNAMIC_CODE_NONE;
      }
#endif /* __DYNAMIC_CODE_MANAGER__ */
#if defined(__DCM_WITH_COMPRESSION__)
      if( (dynamic_code_id < DYNAMIC_CODE_COMPRESS_END) && (dynamic_code_id >= DYNAMIC_CODE_COMPRESS_BEGIN) )
      {
          current_comp_dynamic_code_id[DCM_comp_pool_by_dynamic_code_id[dynamic_code_id&DYNAMIC_POOL_ID_MASK] - 1] 
          = DYNAMIC_CODE_COMPRESS_NONE;
      }
#endif /* __DCM_WITH_COMPRESSION__ */

      /* loading process is done */
      DCMGR_LEAVE_CRITICAL_SECTION

      /* SEE Also : DCM_TARGET_CONFIGURE definiation */
   }
}

/*************************************************************************
* FUNCTION
*   DCM_Isloaded
*
* DESCRIPTION
*   query if the DCM code already loaded
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
kal_bool DCM_Isloaded( kal_int32 dynamic_code_id ) /* TODO - add DCM with compression support */
{
   if( 
#if defined(__DYNAMIC_CODE_MANAGER__)
       (dynamic_code_id < 0 || dynamic_code_id >= DYNAMIC_CODE_NUM)
#endif /* __DYNAMIC_CODE_MANAGER__ */
#if defined(__DCM_WITH_COMPRESSION__)
   #if defined(__DYNAMIC_CODE_MANAGER__)
       &&
   #endif /* __DYNAMIC_CODE_MANAGER__ */
       (dynamic_code_id < DYNAMIC_CODE_COMPRESS_BEGIN || dynamic_code_id >= DYNAMIC_CODE_COMPRESS_END) 
#endif /* __DCM_WITH_COMPRESSION__ */
     )
   {   
      return KAL_FALSE;
   }
   else
   {
      /* enter critical scetion to protect shared resource */
      DCMGR_ENTER_CRITICAL_SECTION

#if defined(__DYNAMIC_CODE_MANAGER__)
      if(dynamic_code_id < DYNAMIC_CODE_NUM)
   {
          if(current_dynamic_code_id[DCM_pool_by_dynamic_code_id[dynamic_code_id&DYNAMIC_POOL_ID_MASK]-1]
             == dynamic_code_id)
      return KAL_TRUE;
   }
#endif /* __DYNAMIC_CODE_MANAGER__ */
#if defined(__DCM_WITH_COMPRESSION__)
      if( (dynamic_code_id < DYNAMIC_CODE_COMPRESS_END) && (dynamic_code_id >= DYNAMIC_CODE_COMPRESS_BEGIN) )
   {
          if(current_comp_dynamic_code_id[DCM_comp_pool_by_dynamic_code_id[dynamic_code_id&DYNAMIC_POOL_ID_MASK]-1]
             == dynamic_code_id)
      return KAL_TRUE;
   }
#endif /* __DCM_WITH_COMPRESSION__ */

      /* loading process is done */
      DCMGR_LEAVE_CRITICAL_SECTION

      /* SEE Also : DCM_TARGET_CONFIGURE definiation */
   }

   return KAL_FALSE;
}


/*************************************************************************
* FUNCTION
*   DCM_IsAvailable
*
* DESCRIPTION
*   query if the DCM pool for the dynamic_code_id is free
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
kal_bool DCM_IsAvailable( kal_int32 dynamic_code_id ) /* TODO - add DCM with compression support */
{
   if( 
#if defined(__DYNAMIC_CODE_MANAGER__)
       (dynamic_code_id < 0 || dynamic_code_id >= DYNAMIC_CODE_NUM)
#endif /* __DYNAMIC_CODE_MANAGER__ */
#if defined(__DCM_WITH_COMPRESSION__)
   #if defined(__DYNAMIC_CODE_MANAGER__)
       &&
   #endif /* __DYNAMIC_CODE_MANAGER__ */
       (dynamic_code_id < DYNAMIC_CODE_COMPRESS_BEGIN || dynamic_code_id >= DYNAMIC_CODE_COMPRESS_END) 
#endif /* __DCM_WITH_COMPRESSION__ */
     )
   {   
      return KAL_FALSE;
   }
   else
   {
      /* enter critical scetion to protect shared resource */
      DCMGR_ENTER_CRITICAL_SECTION

#if defined(__DYNAMIC_CODE_MANAGER__)
      if(dynamic_code_id < DYNAMIC_CODE_NUM)
   {
          if(current_dynamic_code_id[DCM_pool_by_dynamic_code_id[dynamic_code_id&DYNAMIC_POOL_ID_MASK]-1]
             == DYNAMIC_CODE_NONE)
              return KAL_TRUE;
      }
#endif /* __DYNAMIC_CODE_MANAGER__ */
#if defined(__DCM_WITH_COMPRESSION__)
      if( (dynamic_code_id < DYNAMIC_CODE_COMPRESS_END) && (dynamic_code_id >= DYNAMIC_CODE_COMPRESS_BEGIN) )
   {
          if(current_comp_dynamic_code_id[DCM_comp_pool_by_dynamic_code_id[dynamic_code_id&DYNAMIC_POOL_ID_MASK]-1]
             == DYNAMIC_CODE_COMPRESS_NONE)
      return KAL_TRUE;
   }
#endif /* __DCM_WITH_COMPRESSION__ */

      /* loading process is done */
      DCMGR_LEAVE_CRITICAL_SECTION

      /* SEE Also : DCM_TARGET_CONFIGURE definiation */
   }
   return KAL_FALSE;
}

#if defined(__DCM_WITH_COMPRESSION__)
/*************************************************************************
* FUNCTION
*   DCM_ImageAmount
*
* DESCRIPTION
*   query how many images are dynamically lodable
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
static kal_uint32 DCM_ImageAmount(void)
{
    kal_uint32                 idx = 0;

    for(idx = 0 ; idx < DYNAMIC_CODE_COMPRESS_NUM ; idx++)
    {
        if(NULL == DCM_image_list[idx])
        {
            break;
        }
    }
    return idx;
}

/*************************************************************************
* FUNCTION
*   DCM_SearchImage
*
* DESCRIPTION
*   query how many images are dynamically lodable
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
static kal_uint32 DCM_SearchImage(void)
{
    kal_uint32  comp_pattern = 0;
    kal_uint32  zimage_size = 0;
    kal_uint32  idx = 0;
    kal_uint8   *look_ptr = NULL;
    kal_uint8   *compare_ptr = NULL;
    kal_uint8   *end_ptr = NULL;
    kal_uint8   *ret_ptr = NULL;

#if (0)
#if defined(__ZIMAGE_SUPPORT__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* !__ZIMAGE_SUPPORT__ */
#endif

    look_ptr = (kal_uint8 *)vivaInfo.dcmcmp_base;
    end_ptr = (kal_uint8 *)(custom_get_fat_addr()+INT_RetrieveRemappedFlashBaseAddr());

    compare_ptr = (kal_uint8 *)&comp_pattern;
    while(look_ptr < end_ptr)
    {
        /* try to find first key */
        for(idx = 0 ; idx < 4 ; idx++)
        {
            compare_ptr[idx] = look_ptr[idx];
        }
        if(DCMGR_KEY_ID_HEAD == comp_pattern)
        {
            ret_ptr = look_ptr;
            look_ptr += 4;
            /* try to find second key */
            for(idx = 0 ; idx < 4 ; idx++)
            {
                compare_ptr[idx] = look_ptr[idx];
            }
            if(DCMGR_KEY_ID_TAIL == comp_pattern)
            {
                return (kal_uint32)ret_ptr;
            }
        }
        else
        {
            look_ptr++;
        }
    };
    return DCMGR_INVALID_VAL;
}
#endif /* __DCM_WITH_COMPRESSION__ */


/*************************************************************************
* FUNCTION
*   DCMGR_Init
*
* DESCRIPTION
*   
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
void DCMGR_Init( void )
{
    kal_uint32 hdr_addr = 0;

#if defined(__DCM_WITH_COMPRESSION__)
    /* keep constant data from being removed by linker */
    dcmgr_code_ptr = &dcmgr_dynamic_code_hdr;

    hdr_addr = DCM_SearchImage();
    EXT_ASSERT( DCMGR_INVALID_VAL != hdr_addr, 0, 0, 0);

    dcmgr_code_ptr = (volatile dcmgr_comp_header_t const *)hdr_addr;
    dcmgr_comp_image_num = DCM_ImageAmount();
    if( dcmgr_code_ptr->dcmgr_img_num != dcmgr_comp_image_num )
    {
        /* number of image is not consistent between compressed file and primary ROM */
        EXT_ASSERT(0, dcmgr_code_ptr->dcmgr_img_num, dcmgr_comp_image_num, 0);
        return;
    }
#endif /* __DCM_WITH_COMPRESSION__ */

    g_dcmgr_semid = kal_create_sem("DCMGR_load", 1);
}

#else /* __DYNAMIC_CODE_MANAGER__ || __DCM_WITH_COMPRESSION__ */

/* 
 * Empty expoted fuction to make linker happy.
 */
void DCM_Load( kal_int32 dynamic_code_id, kal_uint32 **remaining_buf, kal_uint32 *buf_size ) { }

void DCM_Unload( kal_int32 dynamic_code_id ) { }

kal_bool DCM_Isloaded( kal_int32 dynamic_code_id ) { return KAL_FALSE; }

kal_bool DCM_IsAvailable( kal_int32 dynamic_code_id ) { return KAL_FALSE; }

#endif /* __DYNAMIC_CODE_MANAGER__ || __DCM_WITH_COMPRESSION__ */

#endif /* __MTK_TARGET__ */
