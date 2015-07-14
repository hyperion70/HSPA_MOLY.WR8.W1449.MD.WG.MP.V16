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
 *   l1d_custom_rf.h
 *
 * Project:
 * --------
 *   MT6166
 *
 * Description:
 * ------------
 *   MT6166 2G RF constance definition
 *
 * Author:
 * -------
 *
 *
 *==============================================================================
 *******************************************************************************/

#ifndef  _L1D_CUSTOM_RF_H_
#define  _L1D_CUSTOM_RF_H_
/* --------------------------------------------------------------------------- */

#if !defined(MT6166_2G_RF)
   #error "rf files mismatch with compile option!"
#endif

#if IS_BPI_V2_PT3A_SUPPORT
/*--------------------------------------------------------*/
/*   Event Timing Define                                  */
/*--------------------------------------------------------*/
/*MT6166*/
/*MT6166*/ #define  QB_SR1               166
/*MT6166*/ #define  QB_SR2               45   /* SR2 should be larger  than (QB_RX_FENA_2_FSYNC+8QB)*/
/*MT6166*/ #define  QB_SR2M              39
/*MT6166*/ #define  QB_SR3               3    /* SR3 should be larger than (QB_RX_FSYNC_2_FENA+2QB) */
/*MT6166*/ #define  QB_PR1               167  /* QB_PR1>QB_SR1 to prevent RF conflict among 2/3G    */
/*MT6166*/ #define  QB_PR2               50
/*MT6166*/ #define  QB_PR3               7
/*MT6166*/ #define  QB_ST1               280
/*MT6166*/ #define  QB_ST2B              33   /* ST2B should be larger  than (QB_TX_FENA_2_FSYNC+8QB)*/
/*MT6166*/ #define  QB_ST3               38   /* ST3  should be larger  than (QB_TX_FSYNC_2_FENA+7QB)*/
/*MT6166*/ #define  QB_PT1               282  /* QB_PT1>QB_ST1 to prevent RF conflict among 2/3G     */
/*MT6166*/ #define  QB_PT2               56
/*MT6166*/ #define  QB_PT2B              6
/*MT6166*/ #define  QB_PT3               33
/*MT6166*/ #define  QB_PT3A              46
/*MT6166*/ #define  QB_ST2M_G8           10
/*MT6166*/ #define  QB_ST2M_8G           6
/*MT6166*/ #define  QB_PT2M1_G8          -1
/*MT6166*/ #define  QB_PT2M2_G8          -3
/*MT6166*/ #define  QB_PT2M1_8G          10
/*MT6166*/ #define  QB_PT2M2_8G          4
/*MT6166*/
/*MT6166*/
/*MT6166*/ #define  QB_APCON             14 //OH:11
/*MT6166*/ #define  QB_APCMID            20 //OH:18
/*MT6166*/ #define  QB_APCOFF            6  //56: 6
/*MT6166*/ #define  QB_APCDACON          18 //0
/*MT6166*/ #define  TX_PROPAGATION_DELAY 47 //56:47 / OH:46
/*MT6166*/
/*MT6166*/
/*MT6166*/ /*--------------------------------------------------*/
/*MT6166*/ /*   define  BPI data for MT6166                    */
/*MT6166*/ /*--------------------------------------------------*/
/*MT6166*/ /*  PRCB : bit   pin                                */
/*MT6166*/ /*          0    ASM_VCTRL_A                        */
/*MT6166*/ /*          1    ASM_VCTRL_B                        */
/*MT6166*/ /*          2    ASM_VCTRL_C                        */
/*MT6166*/ /*          3    ASM_VCTRL_D/WG_GGE_PA_EN           */
/*MT6166*/ /*         12    SP3T_A_V1                          */
/*MT6166*/ /*         13    SP3T_B_V2                          */
/*MT6166*/ /*         16    ANTENNA_CONFLICT_2G                */
/*MT6166*/ /*         17    SPI_SWITCH_TO_2G                   */
/*MT6166*/ /*         18    GSM_ERR_DET_ID                     */
/*MT6166*/ /*         20    M23G_PA_INDICATOR                  */
/*MT6166*/ /*--------------------------------------------------*/
/*MT6166*/
/*MT6166*/ /*------------------------------------------------------*/
/*MT6166*/ /*  GSM_ERR_DET_ID(Pin:18) has no dedicate output pin,  */
/*MT6166*/ /*  and it is mapped to bit "18" for SW control.        */
/*MT6166*/ /*  For accurate RF conflict detection, this value must */
/*MT6166*/ /*  set "18" and is unchangable.                        */
/*MT6166*/ /*------------------------------------------------------*/
/*MT6166*/ #define  GSM_ERR_DET_ID         (               18) /* For accurate RF conflict detection(2G/FDD), this value must set "18" */
/*MT6166*/                                                     /* and is unchangable.                                                  */
/*MT6166*/ #define  PDATA_GSM_ERR_DET      (1<<GSM_ERR_DET_ID)
/*MT6166*/ #define  SPI_SWITCH_TO_2G       (1<<17)
/*MT6166*/
/*MT6166*/ #define  PDATA_GMSK              0x000000
/*MT6166*/ #define  PDATA_8PSK              0x000004
/*MT6166*/ 
/*MT6166*/ #define  PDATA_GSM850_PR1       (0x000000           |PDATA_GSM_ERR_DET|SPI_SWITCH_TO_2G)
/*MT6166*/ #define  PDATA_GSM850_PR2       (0x000006           |PDATA_GSM_ERR_DET|SPI_SWITCH_TO_2G)
/*MT6166*/ #define  PDATA_GSM850_PR3       (0x000000           |SPI_SWITCH_TO_2G                  )
/*MT6166*/ #define  PDATA_GSM_PR1          (0x000000           |PDATA_GSM_ERR_DET|SPI_SWITCH_TO_2G)
/*MT6166*/ #define  PDATA_GSM_PR2          (0x000006           |PDATA_GSM_ERR_DET|SPI_SWITCH_TO_2G)
/*MT6166*/ #define  PDATA_GSM_PR3          (0x000000           |SPI_SWITCH_TO_2G                  )
/*MT6166*/ #define  PDATA_DCS_PR1          (0x000000           |PDATA_GSM_ERR_DET|SPI_SWITCH_TO_2G)
/*MT6166*/ #define  PDATA_DCS_PR2          (0x000004           |PDATA_GSM_ERR_DET|SPI_SWITCH_TO_2G)
/*MT6166*/ #define  PDATA_DCS_PR3          (0x000000           |SPI_SWITCH_TO_2G                  )
/*MT6166*/ #define  PDATA_PCS_PR1          (0x000000           |PDATA_GSM_ERR_DET|SPI_SWITCH_TO_2G)
/*MT6166*/ #define  PDATA_PCS_PR2          (0x000004           |PDATA_GSM_ERR_DET|SPI_SWITCH_TO_2G)
/*MT6166*/ #define  PDATA_PCS_PR3          (0x000000           |SPI_SWITCH_TO_2G                  )
/*MT6166*/ #define  PDATA_GSM850_PT1       (0x000000           |PDATA_GSM_ERR_DET|SPI_SWITCH_TO_2G) 
/*MT6166*/ #define  PDATA_GSM850_PT2       (0x000001           |PDATA_GSM_ERR_DET|SPI_SWITCH_TO_2G) 
/*MT6166*/ #define  PDATA_GSM850_PT2B      (0x100009           |PDATA_GSM_ERR_DET|SPI_SWITCH_TO_2G)
/*MT6166*/ #define  PDATA_GSM850_PT3       (0x000000           |PDATA_GSM_ERR_DET|SPI_SWITCH_TO_2G)
/*MT6166*/ #define  PDATA_GSM850_PT3A      (0x000000           |SPI_SWITCH_TO_2G                  )
/*MT6166*/ #define  PDATA_GSM850_PT2M1_G8  (0x100009|PDATA_8PSK|PDATA_GSM_ERR_DET|SPI_SWITCH_TO_2G)
/*MT6166*/ #define  PDATA_GSM850_PT2M2_G8  (0x100009|PDATA_8PSK|PDATA_GSM_ERR_DET|SPI_SWITCH_TO_2G)
/*MT6166*/ #define  PDATA_GSM850_PT2M1_8G  (0x000001           |PDATA_GSM_ERR_DET|SPI_SWITCH_TO_2G)
/*MT6166*/ #define  PDATA_GSM850_PT2M2_8G  (0x100009           |PDATA_GSM_ERR_DET|SPI_SWITCH_TO_2G)
/*MT6166*/ #define  PDATA_GSM_PT1          (0x000000           |PDATA_GSM_ERR_DET|SPI_SWITCH_TO_2G)
/*MT6166*/ #define  PDATA_GSM_PT2          (0x000001           |PDATA_GSM_ERR_DET|SPI_SWITCH_TO_2G)
/*MT6166*/ #define  PDATA_GSM_PT2B         (0x100009           |PDATA_GSM_ERR_DET|SPI_SWITCH_TO_2G)
/*MT6166*/ #define  PDATA_GSM_PT3          (0x000000           |PDATA_GSM_ERR_DET|SPI_SWITCH_TO_2G)
/*MT6166*/ #define  PDATA_GSM_PT3A         (0x000000           |SPI_SWITCH_TO_2G                  )
/*MT6166*/ #define  PDATA_GSM_PT2M1_G8     (0x100009|PDATA_8PSK|PDATA_GSM_ERR_DET|SPI_SWITCH_TO_2G)
/*MT6166*/ #define  PDATA_GSM_PT2M2_G8     (0x100009|PDATA_8PSK|PDATA_GSM_ERR_DET|SPI_SWITCH_TO_2G) 
/*MT6166*/ #define  PDATA_GSM_PT2M1_8G     (0x000001           |PDATA_GSM_ERR_DET|SPI_SWITCH_TO_2G)
/*MT6166*/ #define  PDATA_GSM_PT2M2_8G     (0x100009           |PDATA_GSM_ERR_DET|SPI_SWITCH_TO_2G)
/*MT6166*/ #define  PDATA_DCS_PT1          (0x000000           |PDATA_GSM_ERR_DET|SPI_SWITCH_TO_2G)
/*MT6166*/ #define  PDATA_DCS_PT2          (0x000003           |PDATA_GSM_ERR_DET|SPI_SWITCH_TO_2G)
/*MT6166*/ #define  PDATA_DCS_PT2B         (0x10000B           |PDATA_GSM_ERR_DET|SPI_SWITCH_TO_2G)
/*MT6166*/ #define  PDATA_DCS_PT3          (0x000000           |PDATA_GSM_ERR_DET|SPI_SWITCH_TO_2G)
/*MT6166*/ #define  PDATA_DCS_PT3A         (0x000000           |SPI_SWITCH_TO_2G                  )
/*MT6166*/ #define  PDATA_DCS_PT2M1_G8     (0x10000B|PDATA_8PSK|PDATA_GSM_ERR_DET|SPI_SWITCH_TO_2G)
/*MT6166*/ #define  PDATA_DCS_PT2M2_G8     (0x10000B|PDATA_8PSK|PDATA_GSM_ERR_DET|SPI_SWITCH_TO_2G) 
/*MT6166*/ #define  PDATA_DCS_PT2M1_8G     (0x000003           |PDATA_GSM_ERR_DET|SPI_SWITCH_TO_2G)
/*MT6166*/ #define  PDATA_DCS_PT2M2_8G     (0x10000B           |PDATA_GSM_ERR_DET|SPI_SWITCH_TO_2G)
/*MT6166*/ #define  PDATA_PCS_PT1          (0x000000           |PDATA_GSM_ERR_DET|SPI_SWITCH_TO_2G)
/*MT6166*/ #define  PDATA_PCS_PT2          (0x000003           |PDATA_GSM_ERR_DET|SPI_SWITCH_TO_2G)
/*MT6166*/ #define  PDATA_PCS_PT2B         (0x10000B           |PDATA_GSM_ERR_DET|SPI_SWITCH_TO_2G)
/*MT6166*/ #define  PDATA_PCS_PT3          (0x000000           |PDATA_GSM_ERR_DET|SPI_SWITCH_TO_2G)
/*MT6166*/ #define  PDATA_PCS_PT3A         (0x000000           |SPI_SWITCH_TO_2G                  )
/*MT6166*/ #define  PDATA_PCS_PT2M1_G8     (0x10000B|PDATA_8PSK|PDATA_GSM_ERR_DET|SPI_SWITCH_TO_2G)
/*MT6166*/ #define  PDATA_PCS_PT2M2_G8     (0x10000B|PDATA_8PSK|PDATA_GSM_ERR_DET|SPI_SWITCH_TO_2G) 
/*MT6166*/ #define  PDATA_PCS_PT2M1_8G     (0x000003           |PDATA_GSM_ERR_DET|SPI_SWITCH_TO_2G)
/*MT6166*/ #define  PDATA_PCS_PT2M2_8G     (0x10000B           |PDATA_GSM_ERR_DET|SPI_SWITCH_TO_2G)
/*MT6166*/ #define  PDATA_INIT             (0x000000           |SPI_SWITCH_TO_2G                  )
/*MT6166*/ #define  PDATA_IDLE             (0x000000           |SPI_SWITCH_TO_2G                  )
#else
/*--------------------------------------------------------*/
/*   Event Timing Define                                  */
/*--------------------------------------------------------*/
/*MT6166*/
/*MT6166*/ #define  QB_SR1               166
/*MT6166*/ #define  QB_SR2               45   /* SR2 should be larger  than (QB_RX_FENA_2_FSYNC+8QB)*/
/*MT6166*/ #define  QB_SR2M              22
/*MT6166*/ #define  QB_SR3               3    /* SR3 should be larger than (QB_RX_FSYNC_2_FENA+2QB) */
/*MT6166*/ #define  QB_PR1               167  /* QB_PR1>QB_SR1 to prevent RF conflict among 2/3G    */
/*MT6166*/ #define  QB_PR2               50
/*MT6166*/ #define  QB_PR3               7
/*MT6166*/ #define  QB_ST1               280
/*MT6166*/ #define  QB_ST2B              33   /* ST2B should be larger  than (QB_TX_FENA_2_FSYNC+8QB)*/
/*MT6166*/ #define  QB_ST3               38   /* ST3  should be larger  than (QB_TX_FSYNC_2_FENA+7QB)*/
/*MT6166*/ #define  QB_PT1               282  /* QB_PT1>QB_ST1 to prevent RF conflict among 2/3G     */
/*MT6166*/ #define  QB_PT2               56
/*MT6166*/ #define  QB_PT2B              6
/*MT6166*/ #define  QB_PT3               46
/*MT6166*/ #define  QB_ST2M_G8           10
/*MT6166*/ #define  QB_ST2M_8G           6
/*MT6166*/ #define  QB_PT2M1_G8          -1
/*MT6166*/ #define  QB_PT2M2_G8          -3
/*MT6166*/ #define  QB_PT2M1_8G          10
/*MT6166*/ #define  QB_PT2M2_8G          4
/*MT6166*/
/*MT6166*/
/*MT6166*/ #define  QB_APCON             14 //OH:11
/*MT6166*/ #define  QB_APCMID            20 //OH:18
/*MT6166*/ #define  QB_APCOFF            6  //56: 6
/*MT6166*/ #define  QB_APCDACON          18 //0
/*MT6166*/ #define  TX_PROPAGATION_DELAY 47 //56:47 / OH:46
/*MT6166*/
/*MT6166*/
/*MT6166*/ /*--------------------------------------------------*/
/*MT6166*/ /*   define  BPI data for MT6166                    */
/*MT6166*/ /*--------------------------------------------------*/
/*MT6166*/ /*  PRCB : bit   pin                                */
/*MT6166*/ /*          0    ASM_VCTRL_A                        */
/*MT6166*/ /*          1    ASM_VCTRL_B                        */
/*MT6166*/ /*          2    ASM_VCTRL_C                        */
/*MT6166*/ /*          3    ASM_VCTRL_D/WG_GGE_PA_EN           */
/*MT6166*/ /*         12    SP3T_A_V1                          */
/*MT6166*/ /*         13    SP3T_B_V2                          */
/*MT6166*/ /*         16    ANTENNA_CONFLICT_2G                */
/*MT6166*/ /*         17    SPI_SWITCH_TO_2G                   */
/*MT6166*/ /*         18    GSM_ERR_DET_ID                     */
/*MT6166*/ /*         20    M23G_PA_INDICATOR                  */
/*MT6166*/ /*--------------------------------------------------*/
/*MT6166*/
/*MT6166*/ /*------------------------------------------------------*/
/*MT6166*/ /*  GSM_ERR_DET_ID(Pin:18) has no dedicate output pin,  */
/*MT6166*/ /*  and it is mapped to bit "18" for SW control.        */
/*MT6166*/ /*  For accurate RF conflict detection, this value must */
/*MT6166*/ /*  set "18" and is unchangable.                        */
/*MT6166*/ /*------------------------------------------------------*/
/*MT6166*/ #define  GSM_ERR_DET_ID         (               18) /* For accurate RF conflict detection(2G/FDD), this value must set "18" */
/*MT6166*/                                                     /* and is unchangable.                                                  */
/*MT6166*/ #define  PDATA_GSM_ERR_DET      (1<<GSM_ERR_DET_ID)
/*MT6166*/ #define  SPI_SWITCH_TO_2G       (1<<17)
/*MT6166*/
/*MT6166*/ #define  PDATA_GMSK              0x000000
/*MT6166*/ #define  PDATA_8PSK              0x000004
/*MT6166*/ 
/*MT6166*/ #define  PDATA_GSM850_PR1       (0x000000           |PDATA_GSM_ERR_DET|SPI_SWITCH_TO_2G)
/*MT6166*/ #define  PDATA_GSM850_PR2       (0x000006           |PDATA_GSM_ERR_DET|SPI_SWITCH_TO_2G)
/*MT6166*/ #define  PDATA_GSM850_PR3       (0x000000           |SPI_SWITCH_TO_2G                  )
/*MT6166*/ #define  PDATA_GSM_PR1          (0x000000           |PDATA_GSM_ERR_DET|SPI_SWITCH_TO_2G)
/*MT6166*/ #define  PDATA_GSM_PR2          (0x000006           |PDATA_GSM_ERR_DET|SPI_SWITCH_TO_2G)
/*MT6166*/ #define  PDATA_GSM_PR3          (0x000000           |SPI_SWITCH_TO_2G                  )
/*MT6166*/ #define  PDATA_DCS_PR1          (0x000000           |PDATA_GSM_ERR_DET|SPI_SWITCH_TO_2G)
/*MT6166*/ #define  PDATA_DCS_PR2          (0x000004           |PDATA_GSM_ERR_DET|SPI_SWITCH_TO_2G)
/*MT6166*/ #define  PDATA_DCS_PR3          (0x000000           |SPI_SWITCH_TO_2G                  )
/*MT6166*/ #define  PDATA_PCS_PR1          (0x000000           |PDATA_GSM_ERR_DET|SPI_SWITCH_TO_2G)
/*MT6166*/ #define  PDATA_PCS_PR2          (0x000004           |PDATA_GSM_ERR_DET|SPI_SWITCH_TO_2G)
/*MT6166*/ #define  PDATA_PCS_PR3          (0x000000           |SPI_SWITCH_TO_2G                  )
/*MT6166*/ #define  PDATA_GSM850_PT1       (0x000000           |PDATA_GSM_ERR_DET|SPI_SWITCH_TO_2G) 
/*MT6166*/ #define  PDATA_GSM850_PT2       (0x000001           |PDATA_GSM_ERR_DET|SPI_SWITCH_TO_2G) 
/*MT6166*/ #define  PDATA_GSM850_PT2B      (0x100009           |PDATA_GSM_ERR_DET|SPI_SWITCH_TO_2G)
/*MT6166*/ #define  PDATA_GSM850_PT3       (0x000000           |SPI_SWITCH_TO_2G                  )
/*MT6166*/ #define  PDATA_GSM850_PT2M1_G8  (0x100009|PDATA_8PSK|PDATA_GSM_ERR_DET|SPI_SWITCH_TO_2G)
/*MT6166*/ #define  PDATA_GSM850_PT2M2_G8  (0x100009|PDATA_8PSK|PDATA_GSM_ERR_DET|SPI_SWITCH_TO_2G)
/*MT6166*/ #define  PDATA_GSM850_PT2M1_8G  (0x000001           |PDATA_GSM_ERR_DET|SPI_SWITCH_TO_2G)
/*MT6166*/ #define  PDATA_GSM850_PT2M2_8G  (0x100009           |PDATA_GSM_ERR_DET|SPI_SWITCH_TO_2G)
/*MT6166*/ #define  PDATA_GSM_PT1          (0x000000           |PDATA_GSM_ERR_DET|SPI_SWITCH_TO_2G)
/*MT6166*/ #define  PDATA_GSM_PT2          (0x000001           |PDATA_GSM_ERR_DET|SPI_SWITCH_TO_2G)
/*MT6166*/ #define  PDATA_GSM_PT2B         (0x100009           |PDATA_GSM_ERR_DET|SPI_SWITCH_TO_2G)
/*MT6166*/ #define  PDATA_GSM_PT3          (0x000000           |SPI_SWITCH_TO_2G                  )
/*MT6166*/ #define  PDATA_GSM_PT2M1_G8     (0x100009|PDATA_8PSK|PDATA_GSM_ERR_DET|SPI_SWITCH_TO_2G)
/*MT6166*/ #define  PDATA_GSM_PT2M2_G8     (0x100009|PDATA_8PSK|PDATA_GSM_ERR_DET|SPI_SWITCH_TO_2G) 
/*MT6166*/ #define  PDATA_GSM_PT2M1_8G     (0x000001           |PDATA_GSM_ERR_DET|SPI_SWITCH_TO_2G)
/*MT6166*/ #define  PDATA_GSM_PT2M2_8G     (0x100009           |PDATA_GSM_ERR_DET|SPI_SWITCH_TO_2G)
/*MT6166*/ #define  PDATA_DCS_PT1          (0x000000           |PDATA_GSM_ERR_DET|SPI_SWITCH_TO_2G)
/*MT6166*/ #define  PDATA_DCS_PT2          (0x000003           |PDATA_GSM_ERR_DET|SPI_SWITCH_TO_2G)
/*MT6166*/ #define  PDATA_DCS_PT2B         (0x10000B           |PDATA_GSM_ERR_DET|SPI_SWITCH_TO_2G)
/*MT6166*/ #define  PDATA_DCS_PT3          (0x000000           |SPI_SWITCH_TO_2G                  )
/*MT6166*/ #define  PDATA_DCS_PT2M1_G8     (0x10000B|PDATA_8PSK|PDATA_GSM_ERR_DET|SPI_SWITCH_TO_2G)
/*MT6166*/ #define  PDATA_DCS_PT2M2_G8     (0x10000B|PDATA_8PSK|PDATA_GSM_ERR_DET|SPI_SWITCH_TO_2G) 
/*MT6166*/ #define  PDATA_DCS_PT2M1_8G     (0x000003           |PDATA_GSM_ERR_DET|SPI_SWITCH_TO_2G)
/*MT6166*/ #define  PDATA_DCS_PT2M2_8G     (0x10000B           |PDATA_GSM_ERR_DET|SPI_SWITCH_TO_2G)
/*MT6166*/ #define  PDATA_PCS_PT1          (0x000000           |PDATA_GSM_ERR_DET|SPI_SWITCH_TO_2G)
/*MT6166*/ #define  PDATA_PCS_PT2          (0x000003           |PDATA_GSM_ERR_DET|SPI_SWITCH_TO_2G)
/*MT6166*/ #define  PDATA_PCS_PT2B         (0x10000B           |PDATA_GSM_ERR_DET|SPI_SWITCH_TO_2G)
/*MT6166*/ #define  PDATA_PCS_PT3          (0x000000           |SPI_SWITCH_TO_2G                  )
/*MT6166*/ #define  PDATA_PCS_PT2M1_G8     (0x10000B|PDATA_8PSK|PDATA_GSM_ERR_DET|SPI_SWITCH_TO_2G)
/*MT6166*/ #define  PDATA_PCS_PT2M2_G8     (0x10000B|PDATA_8PSK|PDATA_GSM_ERR_DET|SPI_SWITCH_TO_2G) 
/*MT6166*/ #define  PDATA_PCS_PT2M1_8G     (0x000003           |PDATA_GSM_ERR_DET|SPI_SWITCH_TO_2G)
/*MT6166*/ #define  PDATA_PCS_PT2M2_8G     (0x10000B           |PDATA_GSM_ERR_DET|SPI_SWITCH_TO_2G)
/*MT6166*/ #define  PDATA_INIT             (0x000000           |SPI_SWITCH_TO_2G                  )
/*MT6166*/ #define  PDATA_IDLE             (0x000000           |SPI_SWITCH_TO_2G                  )
#endif
/*MT6166*/
/*MT6166*//*----------------------------------------------*/
/*MT6166*//*   APC Compensate Thresholds                  */
/*MT6166*//*----------------------------------------------*/
/*MT6166*/
/*MT6166*/ #define    SECONDS2FRAME(n)                     ((int)((n)*1000/4.615))
/*MT6166*/ #define    VOLT2UVOLT(n)                        ((int)((n)*1000000))
/*MT6166*/ #define    TEMP2MTEMP(n)                        ((int)((n)*1000))
/*MT6166*/
/*MT6166*/ #define    BAT_VOLTAGE_SAMPLE_PERIOD_SECOND     180
/*MT6166*/ #define    BAT_VOLTAGE_SAMPLE_PERIOD            SECONDS2FRAME(BAT_VOLTAGE_SAMPLE_PERIOD_SECOND)
/*MT6166*/ #define    BAT_VOLTAGE_AVERAGE_COUNT            1
/*MT6166*/ #define    BAT_LOW_VOLTAGE_TRHESHOLD            (3.5)
/*MT6166*/ #define    BAT_HIGH_VOLTAGE_TRHESHOLD           (4.0)
/*MT6166*/ #define    BAT_LOW_VOLTAGE                      VOLT2UVOLT(BAT_LOW_VOLTAGE_TRHESHOLD)
/*MT6166*/ #define    BAT_HIGH_VOLTAGE                     VOLT2UVOLT(BAT_HIGH_VOLTAGE_TRHESHOLD)
/*MT6166*/
/*MT6166*/ #define    BAT_TEMPERATURE_SAMPLE_PERIOD_SECOND 180
/*MT6166*/ #define    BAT_TEMPERATURE_SAMPLE_PERIOD        SECONDS2FRAME(BAT_TEMPERATURE_SAMPLE_PERIOD_SECOND)
/*MT6166*/ #define    BAT_TEMPERATURE_AVERAGE_COUNT        1
/*MT6166*/ #define    BAT_LOW_TEMPERATURE_TRHESHOLD        (0)
/*MT6166*/ #define    BAT_HIGH_TEMPERATURE_TRHESHOLD       (50)
/*MT6166*/ #define    BAT_LOW_TEMPERATURE                  TEMP2MTEMP(BAT_LOW_TEMPERATURE_TRHESHOLD)
/*MT6166*/ #define    BAT_HIGH_TEMPERATURE                 TEMP2MTEMP(BAT_HIGH_TEMPERATURE_TRHESHOLD)
/*MT6166*/
/*MT6166*/ #define    RF_TEMPERATURE_SAMPLE_PERIOD_SECOND  1
/*MT6166*/ #define    RF_TEMPERATURE_SAMPLE_PERIOD         SECONDS2FRAME(RF_TEMPERATURE_SAMPLE_PERIOD_SECOND)
/*MT6166*/ #define    RF_TEMPERATURE_AVERAGE_COUNT         1
/*MT6166*/
/*MT6166*//*----------------------------------------------*/
/*MT6166*//*   Voltage Compensate Parameter               */
/*MT6166*//*----------------------------------------------*/
/*MT6166*/
/*MT6166*/ #define    MINUTES2FRAME(n)                     ((int)((n)*13000))
/*MT6166*/ #define    AP_UPDATE_VOLTINFO_PERIOD            MINUTES2FRAME(5)
/*MT6166*/
/*MT6166*//*----------------------------------------------*/
/*MT6166*//*   Crystal parameter                          */
/*MT6166*//*----------------------------------------------*/
/*MT6166*/ #if  IS_AFC_VCXO_SUPPORT
/*MT6166*/ #define Custom_RF_XO_CapID   155 /* RF SOP, Range:0~255 */
/*MT6166*/ #else
/*MT6166*/ #define Custom_RF_XO_CapID   0   /* For MT6166 with VCTCXO */
/*MT6166*/ #endif
/*MT6166*/
/*MT6166*/ /********************************************/
/*MT6166*/ /* Define your band mode selection on       */
/*MT6166*/ /* High Band and Low Band receivers         */
/*MT6166*/ /*        LNA_1 : 2GHB                      */
/*MT6166*/ /*        LNA_2 : 2GLB                      */
/*MT6166*/ /*        LNA_3 : B40                       */
/*MT6166*/ /*        LNA_4 : B1                        */
/*MT6166*/ /*        LNA_5 : B5                        */
/*MT6166*/ /*        LNA_6 : B2                        */
/*MT6166*/ /*        LNA_7 : B8                        */
/*MT6166*/ /********************************************/
/*MT6166*/
/*MT6166*/ #define GSM850_PATH_SEL LNA_2
/*MT6166*/ #define GSM_PATH_SEL    LNA_2
/*MT6166*/ #define DCS_PATH_SEL    LNA_1
/*MT6166*/ #define PCS_PATH_SEL    LNA_1
/*MT6166*/
/*MT6166*//*======================================================================================== */
/*MT6166*/
/*MT6166*/ /*----------------------------------------------*/
/*MT6166*/ /*   TX Power Control (TXPC) Support            */
/*MT6166*/ /*----------------------------------------------*/
/*MT6166*/
/*MT6166*/ #define IS_BSI_CLOSED_LOOP_TXPC_ON      0
/*MT6166*/
/*MT6166*/ #define TXPC_EPSK_TP_SLOPE_LB          ((26<<8)+22) /* Unit: degree/dB. Temperature increment that causes 1-dB EPSK TX power drop */
/*MT6166*/ #define TXPC_EPSK_TP_SLOPE_HB          ((27<<8)+22) /* Two slope method : [( temp<20:slpoe1)<<8 + (temp>=20:slpoe2)], slope must < 256 */
/*MT6166*/
/*MT6166*/ /*----------------------------------------------*/
/*MT6166*/ /*   DCXO LPM parameter                         */
/*MT6166*/ /*----------------------------------------------*/
/*MT6166*/ #define CUSTOM_CLOAD_FREQ_OFFSET   88940 /*in unit of Hz*/
/*MT6166*/
/*MT6166*/ /*----------------------------------------------------*/
/*MT6166*/ /*   Enable or disable the clock1, 2, 3, and 4 output */
/*MT6166*/ /*   1 : Enable                                       */
/*MT6166*/ /*   0 : Disable                                      */
/*MT6166*/ /*----------------------------------------------------*/
/*MT6166*/ #define CLK1_EN                         1 /* CLK1 is enabled for BB */
/*MT6166*/ #define CLK2_EN                         0
/*MT6166*/ #define CLK3_EN                         0
/*MT6166*/ #define CLK4_EN                         1
/*MT6166*/
/*MT6166*/ /*----------------------------------------------*/
/*MT6166*/ /*   TX power rollback parameter                */
/*MT6166*/ /*----------------------------------------------*/
/*MT6166*/ /*Unit: 1/8 dB*/
/*MT6166*/ /*GSM850 GMSK*/
/*MT6166*/ #define GSM850_TX_ROLLBACK_2T_GMSK      8
/*MT6166*/ #define GSM850_TX_ROLLBACK_3T_GMSK     24
/*MT6166*/ #define GSM850_TX_ROLLBACK_4T_GMSK     32
/*MT6166*/ #define GSM850_TX_ROLLBACK_5T_GMSK     40
/*MT6166*/ 
/*MT6166*/ /*GSM GMSK*/
/*MT6166*/ #define GSM_TX_ROLLBACK_2T_GMSK         8
/*MT6166*/ #define GSM_TX_ROLLBACK_3T_GMSK        24
/*MT6166*/ #define GSM_TX_ROLLBACK_4T_GMSK        32
/*MT6166*/ #define GSM_TX_ROLLBACK_5T_GMSK        40
/*MT6166*/ 
/*MT6166*/ /*DCS GMSK*/
/*MT6166*/ #define DCS_TX_ROLLBACK_2T_GMSK         8
/*MT6166*/ #define DCS_TX_ROLLBACK_3T_GMSK        24
/*MT6166*/ #define DCS_TX_ROLLBACK_4T_GMSK        32
/*MT6166*/ #define DCS_TX_ROLLBACK_5T_GMSK        40
/*MT6166*/ 
/*MT6166*/ /*PCS GMSK*/
/*MT6166*/ #define PCS_TX_ROLLBACK_2T_GMSK         8
/*MT6166*/ #define PCS_TX_ROLLBACK_3T_GMSK        24
/*MT6166*/ #define PCS_TX_ROLLBACK_4T_GMSK        32
/*MT6166*/ #define PCS_TX_ROLLBACK_5T_GMSK        40
/*MT6166*/ 
/*MT6166*/ /*GSM850 EPSK*/
/*MT6166*/ #define GSM850_TX_ROLLBACK_2T_EPSK      8
/*MT6166*/ #define GSM850_TX_ROLLBACK_3T_EPSK     24
/*MT6166*/ #define GSM850_TX_ROLLBACK_4T_EPSK     32
/*MT6166*/ #define GSM850_TX_ROLLBACK_5T_EPSK     40
/*MT6166*/ 
/*MT6166*/ /*GSM EPSK*/
/*MT6166*/ #define GSM_TX_ROLLBACK_2T_EPSK         8
/*MT6166*/ #define GSM_TX_ROLLBACK_3T_EPSK        24
/*MT6166*/ #define GSM_TX_ROLLBACK_4T_EPSK        32
/*MT6166*/ #define GSM_TX_ROLLBACK_5T_EPSK        40
/*MT6166*/ 
/*MT6166*/ /*DCS EPSK*/
/*MT6166*/ #define DCS_TX_ROLLBACK_2T_EPSK         8
/*MT6166*/ #define DCS_TX_ROLLBACK_3T_EPSK        24
/*MT6166*/ #define DCS_TX_ROLLBACK_4T_EPSK        32
/*MT6166*/ #define DCS_TX_ROLLBACK_5T_EPSK        40
/*MT6166*/ 
/*MT6166*/ /*PCS EPSK*/
/*MT6166*/ #define PCS_TX_ROLLBACK_2T_EPSK         8
/*MT6166*/ #define PCS_TX_ROLLBACK_3T_EPSK        24
/*MT6166*/ #define PCS_TX_ROLLBACK_4T_EPSK        32
/*MT6166*/ #define PCS_TX_ROLLBACK_5T_EPSK        40
/*MT6166*/ /*============================================================================== */
/*MT6166*/
/*MT6166*/ /*----------------------------------------------*/
/*MT6166*/ /*   One-bin Support Definition                 */
/*MT6166*/ /*----------------------------------------------*/
/*MT6166*/
/*MT6166*/ #define L1D_CUSTOM_DYNAMIC_SUPPORT        (L1D_CUSTOM_GPIO_ENABLE|L1D_CUSTOM_ADC_ENABLE|L1D_CUSTOM_BARCODE_ENABLE)
/*MT6166*/
/*MT6166*/ /* Constants to enable "Dynamic Initialization RF parameters" mechanism                 */
/*MT6166*/ #define L1D_CUSTOM_GPIO_ENABLE            0
/*MT6166*/ #define L1D_CUSTOM_ADC_ENABLE             0
/*MT6166*/ #define L1D_CUSTOM_BARCODE_ENABLE         0
/*MT6166*/
/*MT6166*/ /* Constants to define number of sets can be represented by each mechanism respectively */
/*MT6166*/ #define L1D_CUSTOM_GPIO_SET_NUMS          2
/*MT6166*/ #define L1D_CUSTOM_ADC_SET_NUMS           2
/*MT6166*/ #define L1D_CUSTOM_BARCODE_SET_NUMS       2
/*MT6166*/
/*MT6166*/ /* Constants to first, second, and third index for the representation in configuration  */
/*MT6166*/ /* set index table                                                                      */
/*MT6166*/
/*MT6166*/ /* The value can be set:                                                                */
/*MT6166*/ /* L1D_CUSTOM_GPIO_DETECTION_ID                                                         */
/*MT6166*/ /* L1D_CUSTOM_ADC_DETECTION_ID                                                          */
/*MT6166*/ /* L1D_CUSTOM_BARCODE_DETECTION_ID                                                      */
/*MT6166*/ /* L1D_CUSTOM_NULL_ACTION                                                               */
/*MT6166*/ /* Note:                                                                                */
/*MT6166*/ /* 1. Should not define L1D_CUSTOM_FIRST_INDEX to L1D_CUSTOM_NULL_ACTION                */
/*MT6166*/ /*    while L1D_CUSTOM_SECOND_INDEX or L1D_CUSTOM_THIRD_INDEX is not L1D_CUSTOM_NULL_ACTION */
/*MT6166*/ /* 2. Should not define L1D_CUSTOM_SECOND_INDEX or L1D_CUSTOM_FIRST_INDEX to            */
/*MT6166*/ /*    L1D_CUSTOM_NULL_ACTION while L1D_CUSTOM_THIRD_INDEX is not L1D_CUSTOM_NULL_ACTION */
/*MT6166*/ #define L1D_CUSTOM_FIRST_INDEX            L1D_CUSTOM_NULL_ACTION
/*MT6166*/ #define L1D_CUSTOM_SECOND_INDEX           L1D_CUSTOM_NULL_ACTION
/*MT6166*/ #define L1D_CUSTOM_THIRD_INDEX            L1D_CUSTOM_NULL_ACTION
/*MT6166*/
/*MT6166*/ /* For trace output to debug ( L1D_CustomDynamicDebug() )                               */
/*MT6166*/ #define L1D_CUSTOM_DEBUG_ENABLE           0
/*MT6166*/
/*MT6166*/ /*------*/
/*MT6166*/ /* GPIO */
/*MT6166*/ /*------*/
/*MT6166*/ /* Customization constant to be used for customer to determine the number of GPIO       */
/*MT6166*/ /* detection pins in use                                                                */
/*MT6166*/ #define L1D_CUSTOM_GPIO_NUM_OF_DETECT_PINS_IN_USE    1
/*MT6166*/ /*--------------------------------------------------------------------------------------*/
/*MT6166*/
/*MT6166*/ /*-----*/
/*MT6166*/ /* ADC */
/*MT6166*/ /*-----*/
/*MT6166*/ /*Customization constant to be used for customer to determine the bits of ADC in use    */
/*MT6166*/ #define L1D_CUSTOM_ADC_BITS                          12      // ADC is 12 bit (1/4096) per step
/*MT6166*/
/*MT6166*/ /* Constant to be used to determine the maximum input voltage on the board              */
/*MT6166*/ /* (in micro volt unit)                                                                 */
/*MT6166*/ #define L1D_CUSTOM_ADC_MAX_INPUT_VOLTAGE             1500000 // uV
/*MT6166*/
/*MT6166*/ /* Customization constant to be used for customer to determine the inaccuracy margin    */
/*MT6166*/ /* on the board (in micro volt unit)                                                    */
/*MT6166*/ #define L1D_CUSTOM_ADC_INACCURACY_MARGIN             25000   // uV uint
/*MT6166*/
/*MT6166*/ /* Constant to be used to determine the each step level of ADC voltage to level         */
/*MT6166*/ /* look-up table on the board (in micro volt unit)                                      */
/*MT6166*/ /* L1D_CUSTOM_ADC_VOLT_LVL_RESOLUTION_THRESHOLD - two times inaccuracy margin           */
/*MT6166*/ /* L1D_CUSTOM_ADC_VOLT_LVL_STEP_SIZE            - step size of consecutive levels       */
/*MT6166*/ /* L1D_CUSTOM_ADC_VOLT_LVL_MIN_LVL_STEP         - the first level upper bound to 0 volt */
/*MT6166*/ #define L1D_CUSTOM_ADC_VOLT_LVL_RESOLUTION_THRESHOLD (L1D_CUSTOM_ADC_INACCURACY_MARGIN * 2)
/*MT6166*/ #define L1D_CUSTOM_ADC_VOLT_LVL_STEP_SIZE            ((L1D_CUSTOM_ADC_MAX_INPUT_VOLTAGE) / (L1D_CUSTOM_ADC_LEVEL_TOTAL-1))
/*MT6166*/ #define L1D_CUSTOM_ADC_VOLT_LVL_MIN_LVL_STEP         (L1D_CUSTOM_ADC_VOLT_LVL_STEP_SIZE / 2)
/*MT6166*/
/*MT6166*/ /* Sample of ADC votlage to level look-up table                                         */
/*MT6166*/
/*MT6166*/ /* ADC levels - 4                                                                       */
/*MT6166*/ /* Level   Upper(uV)       Lower(uV)                                                    */
/*MT6166*/ /* 0       250000          0                                                            */
/*MT6166*/ /* 1       750000          250000                                                       */
/*MT6166*/ /* 2       1250000         750000                                                       */
/*MT6166*/ /* 3       1500000         1250000                                                      */
/*MT6166*/
/*MT6166*/ /* Customization constant to be used for customer to determine number of ADC levels to  */
/*MT6166*/ /* be used to distinguish between the RF HW configurations                              */
/*MT6166*/
/*MT6166*/ #define L1D_CUSTOM_ADC_LEVEL_TOTAL        4
/*MT6166*/
/*MT6166*/ /* Customization constant to be used for customer to determine number of ADC channel    */
/*MT6166*/ /* measurement counts (in 2's order) ex: 7 => 2^7 = 128                                 */
/*MT6166*/ #define L1D_CUSTOM_ADC_MEAS_COUNT_2_ORDER 7 //2^7 = 128
/*MT6166*/
/*MT6166*/ #define L1D_CUSTOM_ADC_LVL0               (L1D_CUSTOM_ADC_VOLT_LVL_MIN_LVL_STEP)
/*MT6166*/ #define L1D_CUSTOM_ADC_LVL1               (L1D_CUSTOM_ADC_LVL0 + L1D_CUSTOM_ADC_VOLT_LVL_STEP_SIZE)
/*MT6166*/ #define L1D_CUSTOM_ADC_LVL2               (L1D_CUSTOM_ADC_LVL1 + L1D_CUSTOM_ADC_VOLT_LVL_STEP_SIZE)
/*MT6166*/ #define L1D_CUSTOM_ADC_LVL3               (L1D_CUSTOM_ADC_LVL2 + L1D_CUSTOM_ADC_VOLT_LVL_STEP_SIZE)
/*MT6166*/ #define L1D_CUSTOM_ADC_LVL4               (L1D_CUSTOM_ADC_LVL3 + L1D_CUSTOM_ADC_VOLT_LVL_STEP_SIZE)
/*MT6166*/ #define L1D_CUSTOM_ADC_LVL5               (L1D_CUSTOM_ADC_LVL4 + L1D_CUSTOM_ADC_VOLT_LVL_STEP_SIZE)
/*MT6166*/ #define L1D_CUSTOM_ADC_LVL6               (L1D_CUSTOM_ADC_LVL5 + L1D_CUSTOM_ADC_VOLT_LVL_STEP_SIZE)
/*MT6166*/ /*--------------------------------------------------------------------------------------*/
/*MT6166*/
/*MT6166*/ /*---------*/
/*MT6166*/ /* BarCode */
/*MT6166*/ /*---------*/
/*MT6166*/ /* Customization constant to be used for customer to determine the n-th digit of        */
/*MT6166*/ /* UE barcode to detect the RF configurations; n starts from 0                          */
/*MT6166*/ #define L1D_CUSTOM_BARCODE_READ_DIGIT_NUM 0
/*MT6166*/
/*MT6166*/ /* Customization constant to be used for customer to determine at most three (for now)  */
/*MT6166*/ /* kinds of ASM representation barcode digit number (in ASCII) to detect the RF         */
/*MT6166*/ /* configurations                                                                       */
/*MT6166*/ #define L1D_CUSTOM_BARCODE_DIGIT_VALUE_1  0
/*MT6166*/ #define L1D_CUSTOM_BARCODE_DIGIT_VALUE_2  1
/*MT6166*/ #define L1D_CUSTOM_BARCODE_DIGIT_VALUE_3  2
/*MT6166*/ /*--------------------------------------------------------------------------------------*/
/*MT6166*/
/*MT6166*/ /* Constants for the second and third index base to be calculated */
/*MT6166*/ #if L1D_CUSTOM_GPIO_ENABLE
/*MT6166*/ #define L1D_CUSTOM_GPIO_NUMS_IN_CALC      L1D_CUSTOM_GPIO_SET_NUMS
/*MT6166*/ #else
/*MT6166*/ #define L1D_CUSTOM_GPIO_NUMS_IN_CALC      1
/*MT6166*/ #endif
/*MT6166*/
/*MT6166*/ #if L1D_CUSTOM_ADC_ENABLE
/*MT6166*/ #define L1D_CUSTOM_ADC_NUMS_IN_CALC       L1D_CUSTOM_ADC_SET_NUMS
/*MT6166*/ #else
/*MT6166*/ #define L1D_CUSTOM_ADC_NUMS_IN_CALC       1
/*MT6166*/ #endif
/*MT6166*/
/*MT6166*/ #if L1D_CUSTOM_BARCODE_ENABLE
/*MT6166*/ #define L1D_CUSTOM_BARCODE_NUMS_IN_CALC   L1D_CUSTOM_BARCODE_SET_NUMS
/*MT6166*/ #else
/*MT6166*/ #define L1D_CUSTOM_BARCODE_NUMS_IN_CALC   1
/*MT6166*/ #endif
/*MT6166*/
/*MT6166*/ #define L1D_CUSTOM_TOTAL_SET_NUMS         L1D_CUSTOM_GPIO_NUMS_IN_CALC*L1D_CUSTOM_ADC_NUMS_IN_CALC*L1D_CUSTOM_BARCODE_NUMS_IN_CALC
/*MT6166*/
/*MT6166*/ /* Customization constant to be used for customer to determine if the AuxADC calibration*/
/*MT6166*/ /* is enabled or not                                                                    */
/*MT6166*/ #define L1D_CUSTOM_ADC_CALIBRATE_ENABLE   0
#endif

