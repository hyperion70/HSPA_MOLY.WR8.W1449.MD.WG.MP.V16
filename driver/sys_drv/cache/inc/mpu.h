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
 *   mpu.h
 *
 * Project:
 * --------
 *   MAUI Software
 *
 * Description:
 * ------------
 *   Header file for ARM MMU
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __MPU_H__
#define __MPU_H__

#include "kal_general_types.h"
#include "kal_public_api.h"
    
#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus */

/* This file is only for ARM MPU Enabled Plarforms, (Cortex-Rx) */
#if defined(__CR4__)
/******************************************************************
 * Driver Options
 ******************************************************************/
#if !defined(__SSDVT_TEST__) && (defined(MT6280) && !defined(__SMART_PHONE_MODEM__))
// [Note]
// This option defines whether EMI MPU protection is enabled to prevent Code Region Corruption
// 1. For MT6280 "Data Card" Product, EMI MPU is enabled by MD-Side(i.e. CR4).
// Thus this option should be defined if "MT6280" is defined.
// [*] defined(MT6280) && !defined(__SMART_PHONE_MODEM__) implies "MT6280 Data Card"
//
// 2. For MT6280 "Wifi Router" Product, we have Linux running on ARM9, which should be the real boss for memory management
// In this case, this option should not be defined. The EMI MPU remains as default for Linux to play with.
// [*] defined(MT6280) && defined(__SMART_PHONE_MODEM__) implies "MT6280 Wifi Router"

#define EMI_MPU_ENABLE        // Enable EMI MPU protection
#endif // MT6280 && !__SMART_PHONE_MODEM__

/******************************************************************
 * Define enums
 ******************************************************************/
/* Region size enum */
typedef enum RGN_SIZE_T
{
    RGN_SIZE_32B  =  4 ,
    RGN_SIZE_64B  =  5 ,
    RGN_SIZE_128B =  6 ,
    RGN_SIZE_256B =  7 ,
    RGN_SIZE_512B =  8 ,
    RGN_SIZE_1KB =   9 ,
    RGN_SIZE_2KB =  10 ,
    RGN_SIZE_4KB =  11 ,
    RGN_SIZE_8KB =  12 ,
    RGN_SIZE_16KB = 13 ,
    RGN_SIZE_32KB = 14 ,
    RGN_SIZE_64KB = 15 ,
    RGN_SIZE_128KB = 16 ,
    RGN_SIZE_256KB = 17 ,
    RGN_SIZE_512KB = 18 ,
    RGN_SIZE_1MB =   19 ,
    RGN_SIZE_2MB =   20 ,
    RGN_SIZE_4MB =   21 ,
    RGN_SIZE_8MB =   22 ,
    RGN_SIZE_16MB =  23 ,
    RGN_SIZE_32MB =  24 ,
    RGN_SIZE_64MB =  25 ,
    RGN_SIZE_128MB  = 26 ,
    RGN_SIZE_256MB  = 27 ,
    RGN_SIZE_512MB  = 28 ,
    RGN_SIZE_1GB    = 29 ,
    RGN_SIZE_2GB    = 30 ,
    RGN_SIZE_4GB    = 31
}RGN_SIZE_TYPE;

/* Region access permission and cacheability setting */
typedef enum REGION_ATTRIBUTE_T
{
    //12    10-8   5-3 2 1 0
    //XN    AP     TEX S C B  
    
    //XN
    MPU_XN                          = 0x00001000,

    //Share bit for Normal Type
    MPU_SHARE                       = 0x00000004,

    //Permission control
    MPU_PN_UN                       = 0x00000000,
    MPU_PRW_UN                      = 0x00000100,
    MPU_PRW_UR                      = 0x00000200,
    MPU_PRW_URW                     = 0x00000300,
    MPU_PR_UN                       = 0x00000500,
    MPU_PR_UR                       = 0x00000600, 
    
    //memory type
    MPU_SOM                         = 0x00000000,
    MPU_DEVICE_INS_OUTDEV           = 0x00000001, //Shared Device
    MPU_NORMAL_INWTRA_OUTWTRA       = 0x00000002,
    MPU_NORMAL_INWBRA_OUTWBRA       = 0x00000003,
    MPU_NORMAL_INNC_OUTNC           = 0x00000008,
    MPU_NORMAL_INWBWA_OUTWBWA       = 0x0000000B,
    MPU_DEVICE_INNS_OUTDEV          = 0x00000010  //Non-shsred device        
}REGION_ATTRIBUTE_TYPE;

#if defined(EMI_MPU_ENABLE)
typedef enum EMI_MPU_APC_T
{
    EMI_MPU_NOPORTECT               = 0x0,
    EMI_MPU_SRW_NSNA                = 0x1,
    EMI_MPU_SRW_NSR                 = 0x2,
    EMI_MPU_SRW_NSW                 = 0x3,
    EMI_MPU_SR_NSNA                 = 0x4,
    EMI_MPU_NOACCESS                = 0x5
}EMI_MPU_APC;
#endif /* EMI_MPU_ENABLE */

/******************************************************************
 * Define constants
 ******************************************************************/
/* Max MPU regions number*/
/* CR4 12 regions */
#define MPU_REGION_NUM                12
#define MPU_REGION_MAX_SIZE           RGN_SIZE_4GB
#define MPU_REGION_MIN_SIZE           RGN_SIZE_32B

#define MPU_REGION_SP_KERNEL         (MPU_REGION_NUM -1)

#define DISABLE_SUB_NONE              0

#if defined(MT6280)
/* NOTE: TO BE REMOVED!!!!!!!
 * APB Regions are now defined using custom region framework
 * Following macros are only used in bootloader, and should be removed ... (soon)
 */
/* dependent on common platform memory layout */
#define APB_REGION_ADDR_MD            0x80000000
#define APB_REGION_ADDR_MD_SD         0x88000000
#define APB_REGION_ADDR_AP            0xA0000000
#define APB_REGION_ADDR_AP_SD         0xA8000000
#define APB_REGION_SIZE               RGN_SIZE_128MB
#define LMU_REGION_ADDR               0x60000000
#endif // MT6280

#define MPU_DUMP_MAGIC                (kal_uint32)(0x4D505500) //"MPU"

#if defined(EMI_MPU_ENABLE)
/* EMI MPU region count */
#define EMI_MPU_REGION_NUM            8
/* EMI MPU domain count */
#define EMI_MPU_DOMAIN_NUM            3

/* Register base define */
/* EMI MPU Region start/end address setting */
#define EMI_MPU_REGION_base           (EMI_base+0x0160)
#define EMI_MPU_REGION_offset         (0x8)
/* Access control setting */
#define EMI_MPU_AC_base               (EMI_base+0x01A0)
#define EMI_MPU_AC_offset             (0x8)
/* Violation status */
#define EMI_MPU_VIO_STATUS_base       (EMI_base+0x01F0)
/* Violation address */
#define EMI_MPU_VIO_ADDRESS_base      (EMI_base+0x01F8)
/* Key */
#define EMI_MPU_KEY_base              (EMI_base+0x0650)
/* Password */
#define EMI_MPU_PASSWORD_base         (EMI_base+0x0658)
/* Lock Status */
#define EMI_MPU_LOCK_STATUS_base      (EMI_base+0x0660)

#endif /* EMI_MPU_ENABLE */

/******************************************************************
 * Define macros
 ******************************************************************/
/* Disable subregion n */
#define DISABLE_SUB(n)                ((1 << ((n) & 7))<<8)

#if defined(EMI_MPU_ENABLE)
#define EMI_MPU_Get_Password(r)       (0)
#define EMI_MPU_Clear_Status() \
    do { \
        *(volatile kal_uint32*)(EMI_MPU_VIO_STATUS_base)=0x80000000; \
    } while(0)
    
#define EMI_MPU_Unlock(r) \
    do { \
        kal_uint32 pwd; \
        pwd = EMI_MPU_Get_Password(r); \
        *(volatile kal_uint32*)(EMI_MPU_KEY_base) = (pwd<<3)|((r)&0x00000007); \
    } while(0)
    
#define EMI_MPU_Lock(r) \
    do { \
        kal_uint32 pwd; \
        pwd = EMI_MPU_Get_Password(r); \
        *(volatile kal_uint32*)(EMI_MPU_KEY_base) = (pwd<<3)|((r)&0x00000007); \
    } while(0)

#define EMI_MPU_Set_Region_APC(r, domain, apc) \
    do { \
        *(volatile kal_uint32*)(EMI_MPU_AC_base+((r)/2*EMI_MPU_AC_offset)) &= ~((0x7)<<(((domain)*3)+(16*((r)%2)))); \
        *(volatile kal_uint32*)(EMI_MPU_AC_base+((r)/2*EMI_MPU_AC_offset)) |= (apc)<<(((domain)*3)+(16*((r)%2))); \
    } while(0)
    
#define EMI_MPU_Set_Region_Address(r, start, end) \
    do { \
        *(volatile kal_uint32*)(EMI_MPU_REGION_base+(r)*EMI_MPU_REGION_offset) = (((start)>>14)<<16)|(end)>>14; \
    } while(0)
    
#endif /* EMI_MPU_ENABLE */


#define CPU_SET_STACK_MPU_PROTECT(region_num, stk_bndy)                        \
do{                                                                            \
    mpu_set_region_primitive(                                                  \
        region_num,                                                            \
        (kal_uint32)(stk_bndy) & (0xFFFFFFE0),              							     \
        RGN_SIZE_32B,                                                          \
        (MPU_PR_UR|MPU_NORMAL_INWBWA_OUTWBWA),                                 \
        1                                                                      \
    );                                                                         \
}while(0)

#define CPU_SAVE_STACK_MPU_PROTECT(region_num, mpu_set)                        \
do{                                                                            \
    mpu_get_region((region_num), (mpu_set));                                   \
}while(0)

#define CPU_RESTORE_STACK_MPU_PROTECT(mpu_set)                                 \
do{                                                                            \
    mpu_set_region_primitive(                                                  \
        (mpu_set)->rgn_no,                                                       \
        (mpu_set)->addr,                                                         \
        (mpu_set)->size,                                                         \
        (mpu_set)->attribute,                                                    \
        1                                                                      \
    );                                                                         \
}while(0)

/******************************************************************
 * Define date structures
 ******************************************************************/
/* MPU setting for one region */
typedef struct REGION_SETTING_T
{
   kal_uint32            addr;                /* Region base address */
   RGN_SIZE_TYPE         size;                /* Region range (size) */
   kal_uint32            rgn_no;              /* Region number */
   REGION_ATTRIBUTE_TYPE attribute;           /* Region attrubute */
   kal_uint32            disable_subregion;   /* Flags for disabled sub-region */
   kal_uint32            enable;              /* Region Enable/Disable */
} REGION_SETTING_TYPE;

/* MPU Setting Dump Data Structure */
typedef struct MPU_REGION_T
{
    kal_uint32            Region_Base_Address;
    kal_uint32            Region_Size_Enable;
    kal_uint32            Region_Access_Control;  
} _MPU_REGION;
typedef struct MPU_DUMP_T
{
    kal_uint32            magic_pattern;          /* Magic pattern to check if this dump data is valid */    
    _MPU_REGION           region[MPU_REGION_NUM]; /* Setting for each region */
} MPU_DUMP;



/******************************************************************
 * Export Function Prototypes
 ******************************************************************/
extern void MpuPreInit(void);
extern void MPU_Init(void);
extern void mpu_clear_all_regions(void);
extern kal_bool mpu_dump(MPU_DUMP * mpu_dump_output);
extern void mpu_set_region_primitive(kal_uint32 index, kal_uint32 addr, RGN_SIZE_TYPE region_size, REGION_ATTRIBUTE_TYPE attribute, kal_uint32 enable);

#endif /* __CR4__ */
#if defined(__cplusplus)
} // extern "C"
#endif /* __cplusplus */
#endif  /* __MPU_H__ */

