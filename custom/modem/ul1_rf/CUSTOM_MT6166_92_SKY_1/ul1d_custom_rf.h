/*******************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2001
*
*******************************************************************************/

/*******************************************************************************
 *
 * Filename:
 * ---------
 *	ul1d_custom_rf.h
 *
 * Project:
 * --------
 *   MT6166
 *
 * Description:
 * ------------
 *   MT6166 UMTS FDD RF
 *
 * Author:
 * -------
 * -------
 *

 *******************************************************************************/
#ifndef  _UL1D_CUSTOM_RF_H_
#define  _UL1D_CUSTOM_RF_H_
/* ------------------------------------------------------------------------- */
#if !defined(MT6166_RF) 
   #error "rf files mismatch with compile option!"
#endif
#include "ul1d_rf_cid.h"

/*MT6166*/ 
/*MT6166*/ #define  PA_SECTION   3
/*MT6166*/ 
/*MT6166*/ /*--------------------------------------------------------*/
/*MT6166*/ /*   Event Timing Define                                  */
/*MT6166*/ /*--------------------------------------------------------*/
/*MT6166*/ #define  TC_PR1               MICROSECOND_TO_CHIP(200)
/*MT6166*/ #define  TC_PR2               MICROSECOND_TO_CHIP(100)
/*MT6166*/ #define  TC_PR2B              MICROSECOND_TO_CHIP( 50)
/*MT6166*/ #define  TC_PR3               MICROSECOND_TO_CHIP( 20)                                         
/*MT6166*/ 
/*MT6166*/ #define  TC_PT1               MICROSECOND_TO_CHIP(200)
/*MT6166*/ #define  TC_PT2               MICROSECOND_TO_CHIP(100)
/*MT6166*/ #define  TC_PT2B              MICROSECOND_TO_CHIP( 50)
/*MT6166*/ #define  TC_PT3               MICROSECOND_TO_CHIP( 10)
/*MT6166*/ 
/*MT6166*/
/*MT6166*/ /* the following parameter is chip resolution */
/*MT6166*/ #define MAX_OFFSET        (24*4) //this value must be equal to max of the following 4 offset value
/*MT6166*/ /* Set VM timing same as PGABSI_OFFSET1 */
/*MT6166*/ // Rich modification for the vm_offset as 37
/*MT6166*/ #define VM_OFFSET         (42)//(33)   //54 //63 chips
/*MT6166*/ #define VBIAS_OFFSET      (59)   //59 chips
/*MT6166*/ #define DC2DC_OFFSET      (24*4)
/*MT6166*/ #define VGA_OFFSET        (24*4)
/*MT6166*/ #define MIPI_OFFSET       (59)   //59 chips
/*MT6166*/ 
/*MT6166*/ 
/*MT6166*/ /*---------------------------------------------------------------------*/
/*MT6166*/ /*   define  BPI data for MT6166  (shall be modified by real case)     */
/*MT6166*/ /*---------------------------------------------------------------------*/
/*MT6166*/ /*    PRCB : bit  BPI   pin function                                   */
/*MT6166*/ /*            0    0    ASM_VCTA                                       */
/*MT6166*/ /*            1    1    ASM_VCTB                                       */
/*MT6166*/ /*            2    2    ASM_VCTC                                       */
/*MT6166*/ /*            3    3    ASM_VCTD/WG_GGE_PA_EN                          */
/*MT6166*/ /*            4    4    Reserved                                       */
/*MT6166*/ /*            5    5    Reserved                                       */
/*MT6166*/ /*            6    6    Reserved                                       */
/*MT6166*/ /*            7    7    W_PA_B1_EN                                     */
/*MT6166*/ /*            8    8    W_PA_B2_EN                                     */
/*MT6166*/ /*            9    9    W_PA_B5_EN                                     */
/*MT6166*/ /*            10   10   W_PA_B8_EN                                     */
/*MT6166*/ /*            11   11   TD_PA_B40_EN                                   */
/*MT6166*/ /*            12   12   SP3T_A_V1                                      */
/*MT6166*/ /*            13   13   SP3T_B_V2                                      */
/*MT6166*/ /*            14   14   Reserved                                       */
/*MT6166*/ /*            15   15   Reserved                                        */
/*MT6166*/ /*---------------------------------------------------------------------*/
/*MT6166*/
/*MT6166*/ //* --------------------- PDATA_BAND1 Start ---------------------------*/
/*MT6166*/ #define  PDATA_BAND1_PR1      0x0005
/*MT6166*/ #define  PDATA_BAND1_PR2      0x0005
/*MT6166*/ #define  PDATA_BAND1_PR2B     0x0005
/*MT6166*/ #define  PDATA_BAND1_PR3      0x0000
/*MT6166*/ #define  PDATA_BAND1_PT1      0x0005
/*MT6166*/ #define  PDATA_BAND1_PT2      0x0085
/*MT6166*/ #define  PDATA_BAND1_PT2B     0x0085
/*MT6166*/ #define  PDATA_BAND1_PT3      0x0000
/*MT6166*/ /* --------------------- PDATA_BAND1 End ------------------------------*/
/*MT6166*/ /* --------------------- PDATA_BAND2 Start ----------------------------*/ 
/*MT6166*/ #define  PDATA_BAND2_PR1      0x0007
/*MT6166*/ #define  PDATA_BAND2_PR2      0x0007
/*MT6166*/ #define  PDATA_BAND2_PR2B     0x0007
/*MT6166*/ #define  PDATA_BAND2_PR3      0x0000
/*MT6166*/ #define  PDATA_BAND2_PT1      0x0007
/*MT6166*/ #define  PDATA_BAND2_PT2      0x0107
/*MT6166*/ #define  PDATA_BAND2_PT2B     0x0107
/*MT6166*/ #define  PDATA_BAND2_PT3      0x0000
/*MT6166*/ /* --------------------- PDATA_BAND2 End ------------------------------*/
/*MT6166*/ /* --------------------- PDATA_BAND5 Start ----------------------------*/ 
/*MT6166*/ #define  PDATA_BAND5_PR1      0x0005
/*MT6166*/ #define  PDATA_BAND5_PR2      0x0005
/*MT6166*/ #define  PDATA_BAND5_PR2B     0x0005
/*MT6166*/ #define  PDATA_BAND5_PR3      0x0000
/*MT6166*/ #define  PDATA_BAND5_PT1      0x0005
/*MT6166*/ #define  PDATA_BAND5_PT2      0x0205
/*MT6166*/ #define  PDATA_BAND5_PT2B     0x0205
/*MT6166*/ #define  PDATA_BAND5_PT3      0x0000
/*MT6166*/ /* --------------------- PDATA_BAND5 End ------------------------------*/
/*MT6166*/ /* --------------------- PDATA_BAND8 Start ----------------------------*/ 
/*MT6166*/ #define  PDATA_BAND8_PR1      0x0002
/*MT6166*/ #define  PDATA_BAND8_PR2      0x0002
/*MT6166*/ #define  PDATA_BAND8_PR2B     0x0002
/*MT6166*/ #define  PDATA_BAND8_PR3      0x0000
/*MT6166*/ #define  PDATA_BAND8_PT1      0x0002
/*MT6166*/ #define  PDATA_BAND8_PT2      0x0402
/*MT6166*/ #define  PDATA_BAND8_PT2B     0x0402
/*MT6166*/ #define  PDATA_BAND8_PT3      0x0000
/*MT6166*/ /* --------------------- PDATA_BAND8 End ------------------------------*/
/*MT6166*/ 
/*MT6166*/ /****************************************************************************/
/*MT6166*/ /* Define your band mode selection on one of five main path LNA ports.      */
/*MT6166*/ /* Each of the 5 independent LNA/mixer/divider are either dedicated to      */
/*MT6166*/ /* either high (VCO divide-by-2) or low (VCO divide-by-4) band.             */
/*MT6166*/ /* There are three high band and two low band to choose.                    */
/*MT6166*/ /* LNA1/3/5 are for high band; LNA2/4 are for low band                      */
/*MT6166*/ /* All options are listed below:                                            */
/*MT6166*/ /* LNA1_HIGH_BAND/LNA2_LOW_BAND/LNA3_HIGH_BAND                              */
/*MT6166*/ /* LNA4_LOW_BAND/LNA5_HIGH_BAND/NON_USED_BAND                               */
/*MT6166*/ /****************************************************************************/
/*MT6166*/ #define    BAND1_CHANNEL_SEL    LNA3_HIGH_BAND
/*MT6166*/ #define    BAND2_CHANNEL_SEL    NON_USED_BAND
/*MT6166*/ #define    BAND3_CHANNEL_SEL    NON_USED_BAND
/*MT6166*/ #define    BAND4_CHANNEL_SEL    NON_USED_BAND
/*MT6166*/ #define    BAND5_CHANNEL_SEL    NON_USED_BAND
/*MT6166*/ #define    BAND6_CHANNEL_SEL    NON_USED_BAND
/*MT6166*/ #define    BAND8_CHANNEL_SEL    NON_USED_BAND
/*MT6166*/ #define    BAND9_CHANNEL_SEL    NON_USED_BAND
/*MT6166*/ #define    BAND10_CHANNEL_SEL   NON_USED_BAND
/*MT6166*/ #define    BAND11_CHANNEL_SEL   NON_USED_BAND
/*MT6166*/ #define    BAND19_CHANNEL_SEL   NON_USED_BAND
/*MT6166*/
/*MT6166*/ /************************************************************/
/*MT6166*/ /* Define your tx output selection                          */
/*MT6166*/ /* There are two high band and one low band to choose.      */
/*MT6166*/ /* All options are listed below:                            */
/*MT6166*/ /* TX_HIGH_BAND3/TX_HIGH_BAND2/TX_LOW_BAND1/TX_NULL_BAND    */
/*MT6166*/ /************************************************************/
/*MT6166*/ #define    BAND1_OUTPUT_SEL     TX_HIGH_BAND2
/*MT6166*/ #define    BAND2_OUTPUT_SEL     TX_NULL_BAND
/*MT6166*/ #define    BAND3_OUTPUT_SEL     TX_NULL_BAND
/*MT6166*/ #define    BAND4_OUTPUT_SEL     TX_NULL_BAND
/*MT6166*/ #define    BAND5_OUTPUT_SEL     TX_NULL_BAND
/*MT6166*/ #define    BAND6_OUTPUT_SEL     TX_NULL_BAND
/*MT6166*/ #define    BAND8_OUTPUT_SEL     TX_NULL_BAND
/*MT6166*/ #define    BAND9_OUTPUT_SEL     TX_NULL_BAND
/*MT6166*/ #define    BAND10_OUTPUT_SEL    TX_NULL_BAND
/*MT6166*/ #define    BAND11_OUTPUT_SEL    TX_NULL_BAND
/*MT6166*/ #define    BAND19_OUTPUT_SEL    TX_NULL_BAND
/*MT6166*/ 
/*MT6166*/ /************************************************************/
/*MT6166*/ /* For Single SW vs. multiple HW feature                    */
/*MT6166*/ /* Let the NVRAN BPI setting overwrite the GPIO BPI setting,*/ 
/*MT6166*/ /* If they are not the same (wrong config. by customer)     */
/*MT6166*/ /************************************************************/
/*MT6166*/ #define    RF_SETTING_BY_NVRAM   KAL_TRUE 
/*MT6166*/ /************************************************************/
/*MT6166*/ /* For using the V-battery as instead setting               */ 
/*MT6166*/ /************************************************************/
/*MT6166*/ #define    PMU_PASETTING         KAL_TRUE 
/*MT6166*/ /************************************************************/                                         
/*MT6166*/ /* For RXD single test, customer may use the RXD only,      */
/*MT6166*/ /* need to write RX_MAIN_PATH_ON & RX_DIVERSITY_PATH_ON to  */
/*MT6166*/ /* 0xFFFFFFFF after test                               */
/*MT6166*/ /************************************************************/ 
/*MT6166*/ #define    RX_DIVERSITY_ALWAYS_ON KAL_FALSE
/*MT6166*/ /************************************************************/ 
/*MT6166*/ /* For PA drift compensation by different band's PA         */ 
/*MT6166*/ /************************************************************/ 
/*MT6166*/ #define    PA_DIRFT_COMPENSATION 0x00000000
/*MT6166*/
/*MT6166*/ /************************************************************/     
/*MT6166*/ /* For MPR back off for SAR& lowering PA temerature& UPA/DPA*/ 
/*MT6166*/ /* PAPR concern                                             */ 
/*MT6166*/ /************************************************************/ 
/*MT6166*/ #define    MPR_BACK_OFF_HSDPA_BAND1  MPRSetting2
/*MT6166*/ #define    MPR_BACK_OFF_HSDPA_BAND2  MPRSetting2
/*MT6166*/ #define    MPR_BACK_OFF_HSDPA_BAND3  MPRSetting2
/*MT6166*/ #define    MPR_BACK_OFF_HSDPA_BAND4  MPRSetting2
/*MT6166*/ #define    MPR_BACK_OFF_HSDPA_BAND5  MPRSetting2
/*MT6166*/ #define    MPR_BACK_OFF_HSDPA_BAND6  MPRSetting2
/*MT6166*/ #define    MPR_BACK_OFF_HSDPA_BAND8  MPRSetting2
/*MT6166*/ #define    MPR_BACK_OFF_HSDPA_BAND9  MPRSetting2
/*MT6166*/ #define    MPR_BACK_OFF_HSDPA_BAND10 MPRSetting2
/*MT6166*/ #define    MPR_BACK_OFF_HSDPA_BAND11 MPRSetting2
/*MT6166*/ #define    MPR_BACK_OFF_HSDPA_BAND19 MPRSetting2
/*MT6166*/ #define    MPR_BACK_OFF_HSUPA_BAND1  MPRSetting2
/*MT6166*/ #define    MPR_BACK_OFF_HSUPA_BAND2  MPRSetting2
/*MT6166*/ #define    MPR_BACK_OFF_HSUPA_BAND3  MPRSetting2
/*MT6166*/ #define    MPR_BACK_OFF_HSUPA_BAND4  MPRSetting2
/*MT6166*/ #define    MPR_BACK_OFF_HSUPA_BAND5  MPRSetting2
/*MT6166*/ #define    MPR_BACK_OFF_HSUPA_BAND6  MPRSetting2
/*MT6166*/ #define    MPR_BACK_OFF_HSUPA_BAND8  MPRSetting2
/*MT6166*/ #define    MPR_BACK_OFF_HSUPA_BAND9  MPRSetting2
/*MT6166*/ #define    MPR_BACK_OFF_HSUPA_BAND10 MPRSetting2
/*MT6166*/ #define    MPR_BACK_OFF_HSUPA_BAND11 MPRSetting2
/*MT6166*/ #define    MPR_BACK_OFF_HSUPA_BAND19 MPRSetting2
/*MT6166*/            
/*MT6166*/ /************************************************************/     
/*MT6166*/ /* At MT6582+MT6323PMIC, Vrf18_1(MD1) can use bulk/LDO mode */
/*MT6166*/ /* take bulk mode as default value*/
/*MT6166*/ /************************************************************/  
/*MT6166*/ #define    ULTRA_LOW_COST_EN      KAL_FALSE 
/*MT6166*/ 
/*MT6166*/ /** VPA mode setting: TRUE: force PWM mode, FALSE: Auto */
/*MT6166*/ #define    VPA_FPWM_MODE          KAL_FALSE
/*MT6166*/
/*MT6166*/ #define    RX_HIGHBAND1_INDICATOR UMTSBand1
/*MT6166*/ #define    RX_HIGHBAND2_INDICATOR UMTSBandNone
/*MT6166*/ #define    RX_LOWBAND1_INDICATOR  UMTSBandNone
/*MT6166*/ #define    RX_LOWBAND2_INDICATOR  UMTSBandNone

/*============================================================================== */

#endif
