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
 *   l1_fh_interface.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   Interface for frequency hopping.
 *
 * Author:
 * -------
 * -------
 *
 *------------------------------------------------------------------------------
 * $Revision:     $
 * $Modtime:      $
 * $Log:   //mtkvs01/vmdata/Maui_sw/archives/mcu/interface/l1interface/l1_fh_interface.h-arc  $
 *
 * 03 03 2015 sherman.chung
 * [MOLY00088188] [MT6580][L1D] MT6580 BringUp L1D L1D_RF Driver Check In
 * .
 *
 * 08 22 2013 vend_cuthbert.kao
 * [MOLY00034524] [MT6592][MT6571][L1D][Modify] MT6592 BB Driver + MT6571 BB Driver + MT6165 RF Driver integration
 * .
 *
 * 01 29 2013 sean.yang
 * [MOLY00009515] [L1D][Modify] Check-in MT6572/MT6582 codes
 * .
 *
 * 01 10 2013 sean.yang
 * [MOLY00008403] [L1D][Modify] Add MT6572/MT6582/MT6166 chip option
 * .
 *
 * 01 07 2013 sean.yang
 * [MOLY00008403] [L1D][Modify] Add MT6572/MT6166 chip option
 * .
 *
 * 09 20 2012 sean.yang
 * [MOLY00003835] [L1D][Modify] Add the option for MT6589
 * .
 *
 * 08 28 2012 samuel.yang
 * [MOLY00002746] [L1D][Modify] Macro rename for UDVT load
 * .
 *
 * 08 21 2012 sean.yang
 * [MOLY00002460] [L1D][Modify] Check-in MT6583 codes
 * .
 *
 * 04 09 2012 samuel.yang
 * removed!
 * .
 *
 * 11 08 2011 jason.lai
 * removed!
 * .
 *
 * 10 21 2011 th.yeh
 * removed!
 * .
 *
 * 06 16 2011 cs.wu
 * removed!
 * .
 *
 * 04 28 2011 victo.chen
 * removed!
 * .
 *
 * 12 26 2010 cs.wu
 * removed!
 * .
 *
 * 12 15 2010 chang-kuan.lin
 * removed!
 * .
 *
 * 12 08 2010 chuwei.lo
 * removed!
 * .
 *
 * 11 22 2010 chang-kuan.lin
 * removed!
 * .
 *
 * 10 26 2010 chuwei.lo
 * removed!
 * .
 *
 * 10 05 2010 chuwei.lo
 * removed!
 * .
 *
 * 07 31 2010 samuel.yang
 * removed!
 * .
 *
 ****************************************************************************/

#ifndef  _L1_FH_INTERFACE_H_
#define  _L1_FH_INTERFACE_H_
/* ------------------------------------------------------------------------- */

#include "kal_general_types.h"

#define  DOWN_HOPPING                  0
#define  UP_HOPPING                    1

#define SPLL_FH_TABLE_MAX_SIZE        10

#if (defined MT6253)||(defined MT6253L)||(defined MT6252)||(defined MT6253E)||(defined MT6252H)
#define MPLL_FH_TABLE_SIZE            13
#elif (defined MT6236)||(defined MT6236B)
#define MPLL_FH_TABLE_SIZE             9
#elif (defined MT6256)||(defined MT6255)||(defined MT6250)||(defined MT6280)||(defined MT6583)||(defined MT6589)||(defined MT6572)||(defined MT6582)||(defined MT6592)||(defined MT6571)||(defined MT6580)
#define MPLL_FH_TABLE_SIZE            64
#elif (defined MT6251) // for 6251, dynamic FH should be always on
//   #if IS_MPLL_DYNAMIC_FH_SUPPORT
#define MPLL_FH_TABLE_SIZE           140
//   #else
//#define MPLL_FH_TABLE_SIZE 103
//   #endif
#endif

#if (defined MT6236)||(defined MT6236B)
//if FM_CH is N, We will decide the collision happen when MPLL_CLK=N(+/-)FM_Collision_Range
//Multiply FM_Collision_range by 120 to reserve the floating point
#define LCD_CLK_SCALE                120
#define RATIO_AHB_VALUE                1
#define MPLL_F_FACTOR                 24 // this is to reserve floating point of MPLL freq
#define LCD_ONE_SCALE                 14
#else // IS_CHIP_MT6253
//Multiply FM_Collision_range by 100 to reserve the floating point, for example, 19 means 0.19MHz
#define LCD_CLK_SCALE                100
#define RATIO_AHB_VALUE                2
#define MPLL_F_FACTOR                  2  // this is to reserve floating point of MPLL freq
#define LCD_ONE_SCALE                 14
#endif //IS_CHIP_MT6236

#if (defined MT6256)||(defined MT6255)||(defined MT6250)||(defined MT6280)||(defined MT6583)||(defined MT6589)||(defined MT6572)||(defined MT6582)||(defined MT6592)||(defined MT6571)||(defined MT6580)
#define FHSET_SET_A_EQUAL_B(a,b) \
{ a.fh_set_l = b.fh_set_l;       \
  a.fh_set_h = b.fh_set_h;       \
}
#else
#define FHSET_SET_A_EQUAL_B(a,b) ((a) = (b))
#endif

#if (defined MT6256)||(defined MT6255)||(defined MT6250)||(defined MT6280)||(defined MT6583)||(defined MT6589)||(defined MT6572)||(defined MT6582)||(defined MT6592)||(defined MT6571)||(defined MT6580)
typedef  struct
{  unsigned int    fh_set_l;
   unsigned int    fh_set_h;
}  sFHset;
#else
typedef unsigned short sFHset;
#endif

#if (defined MT6236)||(defined MT6236B)
extern const int MPLL_F[MPLL_FH_TABLE_SIZE];
#elif (defined MT6253)||(defined MT6253L)||(defined MT6252)||(defined MT6253E)||(defined MT6252H)
extern const int MPLL_F[2][MPLL_FH_TABLE_SIZE];
#endif

/*----------------------------------------------------------*/
/* interface for FM to update MPLL CLK Setting              */
/*----------------------------------------------------------*/
void       L1D_FH_FM_TurnOn( kal_bool is_on );
void       L1D_FH_FM_Set_FHset( sFHset FM_FHset );
kal_uint8  L1D_FH_GetHoppingType( void );
void       L1D_FH_FM_SetFreq( kal_int16 FM_Freq );

/*----------------------------------------------------------*/
/* interface for ATV to update MPLL CLK Setting             */
/*----------------------------------------------------------*/
void       L1D_FH_ATV_TurnOn( kal_bool is_on );
void       L1D_FH_ATV_MPLLCLK_Select( kal_uint32 MPLL_index );
kal_uint16 L1D_FH_ATV_Get_MPLL_Setting( void );
kal_uint32 L1D_FH_ATV_Get_Ori_Setting ( void );

/*----------------------------------------------------------*/
/* interface for LCD_Driver to update MPLL FH Table         */
/*----------------------------------------------------------*/
void       L1D_LCD_Cycle_Calculate( void );
void       FM_LCD_Cycle_Calculate( void );
/*----------------------------------------------------------*/
/* interface for RD to set MPLL CLK circular_ramp           */
/*----------------------------------------------------------*/
void       L1D_MPLL_CLK_Circular_Ramp( void );

/* ------------------------------------------------------------------------- */

/*-------------------------------------------------------------*/
/* Interface to enable the frequency hopping for the UDVT load */
/*-------------------------------------------------------------*/
#if (defined __UDVT__)
   #if (defined MT6250)
/*MT6250*/ #define  FREE_RUN_BASE                   0
/*MT6250*/
/*MT6250*/ /* ----------------- */
/*MT6250*/ /* FHCON0 Setting    */
/*MT6250*/ /* --------------------------------------------------------------------------------------------------------------------- */
/*MT6250*/ #define TDMA_FHCON0_MASK                 0xFCFF
/*MT6250*/ /* --------------------------------------------------------------------------------------------------------------------- */
/*MT6250*/
/*MT6250*/ /* ----------------- */
/*MT6250*/ /* FHCON2 Setting    */
/*MT6250*/ /* --------------------------------------------------------------------------------------------------------------------- */
/*MT6250*/ #define UPSRAM_BUSY                      0       /* Freq-hopping SRAM operation busy indicator                           */
/*MT6250*/ #define UPSRAM_CS                        1       /* Freq-hopping SRAM chip-select                                        */
/*MT6250*/ #define UPSRAM_ATRIG                     0       /* Freq-hopping SRAM R/W address initialization indicator               */
/*MT6250*/ #define UPSRAM_RW_ADDR                   0       /* Freq-hopping SRAM read/write initial address setting                 */
/*MT6250*/ #define UPSRAM_DELSEL                    1       /* Freq-hopping SRAM delay select setting                               */
/*MT6250*/ #define TDMA_FHCON2_DEFAULT              ((UPSRAM_BUSY << 15) | (UPSRAM_CS << 10) | (UPSRAM_DELSEL<< 8) | (UPSRAM_ATRIG << 7) | (UPSRAM_RW_ADDR))
/*MT6250*/ /* --------------------------------------------------------------------------------------------------------------------- */
/*MT6250*/
/*MT6250*/ /* ----------------- */
/*MT6250*/ /* FHCON3 Setting    */
/*MT6250*/ /* --------------------------------------------------------------------------------------------------------------------- */
/*MT6250*/ #define TDMA_FHCON3_DEFAULT_INT          (2<<10)
/*MT6250*/ /* --------------------------------------------------------------------------------------------------------------------- */
/*MT6250*/
/*MT6250*/ /* ----------------- */
/*MT6250*/ /* FHCON4 Setting    */
/*MT6250*/ /* --------------------------------------------------------------------------------------------------------------------- */
/*MT6250*/ #define MPLL_FSM_EN                      1       /* MPLL fsm enable control                                              */
/*MT6250*/
/*MT6250*/ /* -- frequency hopping free run parameter ----------------------------------------------------------------------------- */
/*MT6250*/ #define MNPLL_FRDDS_EN                   1       /* FH_FREE_RUN_EN                                                       */
/*MT6250*/ #define MNPLL_FRDDS_DTS                  1       /* FH_FREE_RUN_Time_STEP                                                */
/*MT6250*/ #define MNPLL_FRDDS_DYS                  3       /* FH_FREE_RUN_Freq_STEP                                                */
/*MT6250*/
/*MT6250*/ /* -- frequency hopping soft start parameter --------------------------------------------------------------------------- */
/*MT6250*/ #define MNPLL_FHCTL_GSMEN                0       /* Enable the receiving of TDMA strobes for triggering soft start FH    */
/*MT6250*/ #define MNPLL_SFSTR_EN                   1       /* FH_SOFT_START_EN                                                     */
/*MT6250*/ #define MNPLL_SFSTR_DTS                  1       /* FH_SOFT_START_Time_STEP                                              */
/*MT6250*/ #define MNPLL_SFSTR_DYS                  2       /* FH_SOFT_START_Freq_STEP                                              */
/*MT6250*/
/*MT6250*/ #define TDMA_FHCON4_DEFAULT              ((0x3)                    | (MNPLL_SFSTR_EN  <<  2) | (MNPLL_FRDDS_EN  << 3) |   \
/*MT6250*/                                           (MNPLL_SFSTR_DTS  <<  4) | (MNPLL_SFSTR_DYS <<  6) | (MNPLL_FRDDS_DTS << 8) |   \
/*MT6250*/                                           (MNPLL_FRDDS_DYS  << 12) | (MPLL_FSM_EN     << 15))
/*MT6250*/
/*MT6250*/ #define L1D_SET_MNPLL_FH_TYPE()          HW_WRITE( TDMA_FHCON(4), TDMA_FHCON4_DEFAULT )
/*MT6250*/
/*MT6250*/
/*MT6250*/ /* ----------------- */
/*MT6250*/ /* FHCON5 Setting    */
/*MT6250*/ /* --------------------------------------------------------------------------------------------------------------------- */
/*MT6250*/ #define MNPLL_FREE_RUN_RANGE             0x1D00  /* 0 ~ -1.85% (97.5 * 0.98147 = 95.693MHz > 104 * 0.92 = 95.68MHz)      */
/*MT6250*/ #define L1D_SET_MNPLL_FREE_RUN_RANGE()   HW_WRITE( TDMA_FHCON(5), MNPLL_FREE_RUN_RANGE )
/*MT6250*/ /* --------------------------------------------------------------------------------------------------------------------- */
/*MT6250*/
/*MT6250*/ /* ----------------- */
/*MT6250*/ /* FHCON6 Setting    */
/*MT6250*/ /* --------------------------------------------------------------------------------------------------------------------- */
/*MT6250*/ #define L1D_SET_EFPLL_FH_TYPE()                  /* There is no EFPLL in MT6250                                          */
/*MT6250*/ /* --------------------------------------------------------------------------------------------------------------------- */
/*MT6250*/
/*MT6250*/ /* ----------------- */
/*MT6250*/ /* FHCON7 Setting    */
/*MT6250*/ /* --------------------------------------------------------------------------------------------------------------------- */
/*MT6250*/ #define L1D_SET_EFPLL_FREE_RUN_RANGE()           /* There is no EFPLL in MT6250                                          */
/*MT6250*/ /* --------------------------------------------------------------------------------------------------------------------- */
/*MT6250*/
   #elif (defined MT6280)
/*MT6280*/ #define FREE_RUN_BASE                    0         //FH_table[0]=0 => down 0%
/*MT6280*/
/*MT6280*/ /* ----------------- */
/*MT6280*/ /* FHCON0 Setting    */
/*MT6280*/ /* --------------------------------------------------------------------------------------------------------------------- */
/*MT6280*/ #define TDMA_FHCON0_MASK                 0xFCFF  /* [1:0]=0x3: Config settle delay for PLL stable to be 100 us           */
/*MT6280*/ #define L1D_SET_FHTABLE_INDEX()                                                                                           \
/*MT6280*/ {  unsigned short d16 = HW_READ(TDMA_FHCON(0)) & TDMA_FHCON0_MASK;                                                        \
/*MT6280*/    HW_WRITE( TDMA_FHCON(0), d16 );                                                                                        \
/*MT6280*/ }
/*MT6280*/ /* --------------------------------------------------------------------------------------------------------------------- */
/*MT6280*/
/*MT6280*/ /* ----------------- */
/*MT6280*/ /* FHCON2 Setting    */
/*MT6280*/ /* --------------------------------------------------------------------------------------------------------------------- */
/*MT6280*/ #define UPSRAM_BUSY                      0       /* Freq-hopping SRAM operation busy indicator                           */
/*MT6280*/ #define UPSRAM_CS                        1       /* Freq-hopping SRAM chip-select                                        */
/*MT6280*/ #define UPSRAM_ATRIG                     0       /* Freq-hopping SRAM R/W address initialization indicator               */
/*MT6280*/ #define UPSRAM_RW_ADDR                   0       /* Freq-hopping SRAM read/write initial address setting                 */
/*MT6280*/ #define TDMA_FHCON2_DEFAULT              ((UPSRAM_BUSY << 15) | (UPSRAM_CS << 10) | (UPSRAM_ATRIG << 7) | (UPSRAM_RW_ADDR))
/*MT6280*/ /* --------------------------------------------------------------------------------------------------------------------- */
/*MT6280*/
/*MT6280*/ /* ----------------- */
/*MT6280*/ /* FHCON3 Setting    */
/*MT6280*/ /* --------------------------------------------------------------------------------------------------------------------- */
/*MT6280*/ #define TDMA_FHCON3_DEFAULT_INT          (4<<9)  /* [11:9]=0x4 means that the integer part of DDS setting is 12          */
/*MT6280*/ /* --------------------------------------------------------------------------------------------------------------------- */
/*MT6280*/
/*MT6280*/ /* ----------------- */
/*MT6280*/ /* FHCON4 Setting    */
/*MT6280*/ /* --------------------------------------------------------------------------------------------------------------------- */
/*MT6280*/ #define MNPLL_FHCTL_GSMEN                1       /* [0]     enable/disable frequency hopping (config by L1)              */
/*MT6280*/ #define MNPLL_FSM_EN                     1       /* [15]    MPLL fsm enable control                                      */
/*MT6280*/
/*MT6280*/ /* -- frequency hopping free-run parameter ----------------------------------------------------------------------------- */
/*MT6280*/    #if IS_MPLLFH_FREE_RUN_ON
/*MT6280*/ #define MNPLL_FRDDS_EN                   1       /* [2]     enable/disable free-run frequency hopping (config by L1)     */
/*MT6280*/    #else
/*MT6280*/ #define MNPLL_FRDDS_EN                   0       /* [2]     enable/disable free-run frequency hopping (config by L1)     */
/*MT6280*/    #endif
/*MT6280*/ #define MNPLL_FRDDS_DTS                  1       /* [10:9]  config time step for free-run frequency hopping              */
/*MT6280*/ #define MNPLL_FRDDS_DYS                  3       /* [14:12] config DDS step for free-run frequency hopping               */
/*MT6280*/
/*MT6280*/ /* -- frequency hopping soft-start parameter --------------------------------------------------------------------------- */
/*MT6280*/ #define MNPLL_SFSTR_EN                   1       /* [1]     enable/disable soft-start frequency hopping (config by L1)   */
/*MT6280*/ #define MNPLL_SFSTR_DTS                  1       /* [4:3]   config time step for soft-start frequency hopping            */
/*MT6280*/ #define MNPLL_SFSTR_DYS                  2       /* [7:6]   config DDS step for soft-start frequency hopping             */
/*MT6280*/
/*MT6280*/ /* -- frequency hopping default setting -------------------------------------------------------------------------------- */
/*MT6280*/ #define TDMA_FHCON4_MASK                 (0x0)   /* clear all bits                                                       */
/*MT6280*/ #define TDMA_FHCON4_DEFAULT              ((MNPLL_FHCTL_GSMEN  )|(MNPLL_SFSTR_EN <<1)|(MNPLL_SFSTR_DTS<< 3)|               \
/*MT6280*/                                           (MNPLL_SFSTR_DYS<< 6)|(MNPLL_FRDDS_DTS<<9)|(MNPLL_FRDDS_DYS<<12)|               \
/*MT6280*/                                           (MNPLL_FSM_EN   <<15))
/*MT6280*/
/*MT6280*/ /* -- configure free-run ----------------------------------------------------------------------------------------------- */
/*MT6280*/ #define L1D_SET_MNPLL_FH_TYPE()                                                                                           \
/*MT6280*/ {  unsigned short d16 = HW_READ(TDMA_FHCON(4)) & TDMA_FHCON4_MASK;                                                        \
/*MT6280*/    HW_WRITE( TDMA_FHCON(4), d16|TDMA_FHCON4_DEFAULT|(MNPLL_FRDDS_EN<<2) );                                                \
/*MT6280*/ }
/*MT6280*/ /* --------------------------------------------------------------------------------------------------------------------- */
/*MT6280*/
/*MT6280*/ /* ----------------- */
/*MT6280*/ /* FHCON5 Setting    */
/*MT6280*/ /* --------------------------------------------------------------------------------------------------------------------- */
/*MT6280*/ #define MNPLL_FREE_RUN_RANGE             0x7600  /* 0x76=118, n=118*4=472 (down 7.13%)                                   */
/*MT6280*/ #define L1D_SET_MNPLL_FREE_RUN_RANGE()   HW_WRITE( TDMA_FHCON(5), MNPLL_FREE_RUN_RANGE );
/*MT6280*/ /* --------------------------------------------------------------------------------------------------------------------- */
/*MT6280*/
/*MT6280*/ /* ----------------- */
/*MT6280*/ /* FHCON6 Setting    */
/*MT6280*/ /* --------------------------------------------------------------------------------------------------------------------- */
/*MT6280*/ #define TDMA_FHCON6_MASK                 TDMA_FHCON4_MASK
/*MT6280*/ #define TDMA_FHCON6_DEFAULT              TDMA_FHCON4_DEFAULT
/*MT6280*/
/*MT6280*/ #define L1D_SET_EFPLL_FH_TYPE()                                                                                           \
/*MT6280*/ {  unsigned short d16 = HW_READ( TDMA_FHCON(6) ) & TDMA_FHCON6_MASK;                                                      \
/*MT6280*/    HW_WRITE( TDMA_FHCON(6), d16|TDMA_FHCON6_DEFAULT|(MNPLL_FRDDS_EN<<2) );                                                \
/*MT6280*/ }
/*MT6280*/ /* --------------------------------------------------------------------------------------------------------------------- */
/*MT6280*/
/*MT6280*/ /* ----------------- */
/*MT6280*/ /* FHCON7 Setting    */
/*MT6280*/ /* --------------------------------------------------------------------------------------------------------------------- */
/*MT6280*/ #define EFPLL_FREE_RUN_RANGE             MNPLL_FREE_RUN_RANGE
/*MT6280*/ #define L1D_SET_EFPLL_FREE_RUN_RANGE()   HW_WRITE( TDMA_FHCON(7), EFPLL_FREE_RUN_RANGE );
/*MT6280*/ /* --------------------------------------------------------------------------------------------------------------------- */
/*MT6280*/
   #elif (defined MT6572) || (defined MT6582)||(defined MT6592)||(defined MT6571)||(defined MT6580)
/*MT6572*/ #define FREE_RUN_BASE                    0         //FH_table[0]=0 => down 0%
/*MT6572*/
/*MT6572*/ /* ----------------- */
/*MT6572*/ /* FHCON0 Setting    */
/*MT6572*/ /* --------------------------------------------------------------------------------------------------------------------- */
/*MT6572*/ #define TDMA_FHCON0_MASK                 0xFCFF  /* [1:0]=0x3: Config settle delay for PLL stable to be 100 us           */
/*MT6572*/ #define L1D_SET_FHTABLE_INDEX()                                                                                           \
/*MT6572*/ {  unsigned short d16 = HW_READ(TDMA_FHCON(0)) & TDMA_FHCON0_MASK;                                                        \
/*MT6572*/    HW_WRITE( TDMA_FHCON0, d16 );                                                                                          \
/*MT6572*/ }
/*MT6572*/ /* --------------------------------------------------------------------------------------------------------------------- */
/*MT6572*/
/*MT6572*/ /* ----------------- */
/*MT6572*/ /* FHCON2 Setting    */
/*MT6572*/ /* --------------------------------------------------------------------------------------------------------------------- */
/*MT6572*/ #define UPSRAM_BUSY                      0       /* Freq-hopping SRAM operation busy indicator                           */
/*MT6572*/ #define UPSRAM_CS                        1       /* Freq-hopping SRAM chip-select                                        */
/*MT6572*/ #define UPSRAM_ATRIG                     0       /* Freq-hopping SRAM R/W address initialization indicator               */
/*MT6572*/ #define UPSRAM_RW_ADDR                   0       /* Freq-hopping SRAM read/write initial address setting                 */
/*MT6572*/ #define TDMA_FHCON2_DEFAULT              ((UPSRAM_BUSY << 15) | (UPSRAM_CS << 10) | (UPSRAM_ATRIG << 7) | (UPSRAM_RW_ADDR))
/*MT6572*/ /* --------------------------------------------------------------------------------------------------------------------- */
/*MT6572*/
/*MT6572*/ /* ----------------- */
/*MT6572*/ /* FHCON3 Setting    */
/*MT6572*/ /* --------------------------------------------------------------------------------------------------------------------- */
/*MT6572*/ #define TDMA_FHCON3_DEFAULT_INT          0
/*MT6572*/ /* --------------------------------------------------------------------------------------------------------------------- */
/*MT6572*/
/*MT6572*/ /* ----------------- */
/*MT6572*/ /* FHCON4 Setting    */
/*MT6572*/ /* --------------------------------------------------------------------------------------------------------------------- */
/*MT6572*/ #define MNPLL_FHCTL_GSMEN                1       /* [0]     enable/disable frequency hopping (config by L1)              */
/*MT6572*/ #define MNPLL_FSM_EN                     1       /* [15]    MPLL fsm enable control                                      */
/*MT6572*/
/*MT6572*/ /* -- frequency hopping free-run parameter ----------------------------------------------------------------------------- */
/*MT6572*/    #if IS_MPLLFH_FREE_RUN_ON
/*MT6572*/ #define MNPLL_FRDDS_EN                   1       /* [2]     enable/disable free-run frequency hopping (config by L1)     */
/*MT6572*/    #else
/*MT6572*/ #define MNPLL_FRDDS_EN                   0       /* [2]     enable/disable free-run frequency hopping (config by L1)     */
/*MT6572*/    #endif
/*MT6572*/ #define MNPLL_FRDDS_DTS                  2       /* [10:9]  config time step for free-run frequency hopping              */
/*MT6572*/ #define MNPLL_FRDDS_DYS                  2       /* [14:12] config DDS step for free-run frequency hopping               */
/*MT6572*/
/*MT6572*/ /* -- frequency hopping soft-start parameter --------------------------------------------------------------------------- */
/*MT6572*/ #define MNPLL_SFSTR_EN                   1       /* [1]     enable/disable soft-start frequency hopping (config by L1)   */
/*MT6572*/ #define MNPLL_SFSTR_DTS                  2       /* [4:3]   config time step for soft-start frequency hopping            */
/*MT6572*/ #define MNPLL_SFSTR_DYS                  1       /* [7:6]   config DDS step for soft-start frequency hopping             */
/*MT6572*/
/*MT6572*/ /* -- frequency hopping default setting -------------------------------------------------------------------------------- */
/*MT6572*/ #define TDMA_FHCON4_MASK                 (0x0)   /* clear all bits                                                       */
/*MT6572*/ #define TDMA_FHCON4_DEFAULT              ((MNPLL_FHCTL_GSMEN  )|(MNPLL_SFSTR_EN <<1)|(MNPLL_SFSTR_DTS<< 3)|               \
/*MT6572*/                                           (MNPLL_SFSTR_DYS<< 6)|(MNPLL_FRDDS_DTS<<9)|(MNPLL_FRDDS_DYS<<12)|               \
/*MT6572*/                                           (MNPLL_FSM_EN   <<15))
/*MT6572*/
/*MT6572*/ /* -- configure free-run ----------------------------------------------------------------------------------------------- */
/*MT6572*/ #define L1D_SET_MNPLL_FH_TYPE()                                                                                           \
/*MT6572*/ {  unsigned short d16 = HW_READ(TDMA_FHCON(4)) & TDMA_FHCON4_MASK;                                                        \
/*MT6572*/    HW_WRITE( TDMA_FHCON(4), d16|TDMA_FHCON4_DEFAULT|(MNPLL_FRDDS_EN<<2) );                                                \
/*MT6572*/ }
/*MT6572*/ /* --------------------------------------------------------------------------------------------------------------------- */
/*MT6572*/
/*MT6572*/ /* ----------------- */
/*MT6572*/ /* FHCON5 Setting    */
/*MT6572*/ /* --------------------------------------------------------------------------------------------------------------------- */
/*MT6572*/ #define MNPLL_FREE_RUN_RANGE             0x0076  /* down 5%)                                                             */
/*MT6572*/ #define L1D_SET_MNPLL_FREE_RUN_RANGE()   HW_WRITE( TDMA_FHCON(5), MNPLL_FREE_RUN_RANGE );
/*MT6572*/ /* --------------------------------------------------------------------------------------------------------------------- */
/*MT6572*/
/*MT6572*/ /* ----------------- */
/*MT6572*/ /* FHCON6 Setting    */
/*MT6572*/ /* --------------------------------------------------------------------------------------------------------------------- */
/*MT6572*/ #define TDMA_FHCON6_MASK                 TDMA_FHCON4_MASK
/*MT6572*/ #define TDMA_FHCON6_DEFAULT              TDMA_FHCON4_DEFAULT
/*MT6572*/
/*MT6572*/ #define L1D_SET_EFPLL_FH_TYPE()
/*MT6572*/ {  unsigned short d16 = HW_READ(TDMA_FHCON(6)) & TDMA_FHCON6_MASK;                                                        \
/*MT6572*/    HW_WRITE( TDMA_FHCON(6), d16|TDMA_FHCON6_DEFAULT|(MNPLL_FRDDS_EN<<2) );                                                \
/*MT6572*/ }
/*MT6572*/ /* --------------------------------------------------------------------------------------------------------------------- */
/*MT6572*/
/*MT6572*/ /* ----------------- */
/*MT6572*/ /* FHCON7 Setting    */
/*MT6572*/ /* --------------------------------------------------------------------------------------------------------------------- */
/*MT6572*/ #define EFPLL_FREE_RUN_RANGE             MNPLL_FREE_RUN_RANGE
/*MT6572*/ #define L1D_SET_EFPLL_FREE_RUN_RANGE()   HW_WRITE( TDMA_FHCON(7), EFPLL_FREE_RUN_RANGE );
/*MT6572*/ /* --------------------------------------------------------------------------------------------------------------------- */
/*MT6572*/
   #elif (defined MT6583)||(defined MT6589)
/*MT6583*/ #define FREE_RUN_BASE                    0         //FH_table[0]=0 => down 0%
/*MT6583*/
/*MT6583*/ /* ----------------- */
/*MT6583*/ /* FHCON0 Setting    */
/*MT6583*/ /* --------------------------------------------------------------------------------------------------------------------- */
/*MT6583*/ #define TDMA_FHCON0_MASK                 0xFCFF  /* [1:0]=0x3: Config settle delay for PLL stable to be 100 us           */
/*MT6583*/ #define L1D_SET_FHTABLE_INDEX()                                                                                           \
/*MT6583*/ {  unsigned short d16 = HW_READ(TDMA_FHCON(0)) & TDMA_FHCON0_MASK;                                                        \
/*MT6583*/    HW_WRITE( TDMA_FHCON0, d16 );                                                                                          \
/*MT6583*/ }
/*MT6583*/ /* --------------------------------------------------------------------------------------------------------------------- */
/*MT6583*/
/*MT6583*/ /* ----------------- */
/*MT6583*/ /* FHCON2 Setting    */
/*MT6583*/ /* --------------------------------------------------------------------------------------------------------------------- */
/*MT6583*/ #define UPSRAM_BUSY                      0       /* Freq-hopping SRAM operation busy indicator                           */
/*MT6583*/ #define UPSRAM_CS                        1       /* Freq-hopping SRAM chip-select                                        */
/*MT6583*/ #define UPSRAM_ATRIG                     0       /* Freq-hopping SRAM R/W address initialization indicator               */
/*MT6583*/ #define UPSRAM_RW_ADDR                   0       /* Freq-hopping SRAM read/write initial address setting                 */
/*MT6583*/ #define TDMA_FHCON2_DEFAULT              ((UPSRAM_BUSY << 15) | (UPSRAM_CS << 10) | (UPSRAM_ATRIG << 7) | (UPSRAM_RW_ADDR))
/*MT6583*/ /* --------------------------------------------------------------------------------------------------------------------- */
/*MT6583*/
/*MT6583*/ /* ----------------- */
/*MT6583*/ /* FHCON3 Setting    */
/*MT6583*/ /* --------------------------------------------------------------------------------------------------------------------- */
/*MT6583*/ #define TDMA_FHCON3_DEFAULT_INT          0
/*MT6583*/ /* --------------------------------------------------------------------------------------------------------------------- */
/*MT6583*/
/*MT6583*/ /* ----------------- */
/*MT6583*/ /* FHCON4 Setting    */
/*MT6583*/ /* --------------------------------------------------------------------------------------------------------------------- */
/*MT6583*/ #define MNPLL_FHCTL_GSMEN                1       /* [0]     enable/disable frequency hopping (config by L1)              */
/*MT6583*/ #define MNPLL_FSM_EN                     1       /* [15]    MPLL fsm enable control                                      */
/*MT6583*/
/*MT6583*/ /* -- frequency hopping free-run parameter ----------------------------------------------------------------------------- */
/*MT6583*/    #if IS_MPLLFH_FREE_RUN_ON
/*MT6583*/ #define MNPLL_FRDDS_EN                   1       /* [2]     enable/disable free-run frequency hopping (config by L1)     */
/*MT6583*/    #else
/*MT6583*/ #define MNPLL_FRDDS_EN                   0       /* [2]     enable/disable free-run frequency hopping (config by L1)     */
/*MT6583*/    #endif
/*MT6583*/ #define MNPLL_FRDDS_DTS                  2       /* [10:9]  config time step for free-run frequency hopping              */
/*MT6583*/ #define MNPLL_FRDDS_DYS                  2       /* [14:12] config DDS step for free-run frequency hopping               */
/*MT6583*/
/*MT6583*/ /* -- frequency hopping soft-start parameter --------------------------------------------------------------------------- */
/*MT6583*/ #define MNPLL_SFSTR_EN                   1       /* [1]     enable/disable soft-start frequency hopping (config by L1)   */
/*MT6583*/ #define MNPLL_SFSTR_DTS                  2       /* [4:3]   config time step for soft-start frequency hopping            */
/*MT6583*/ #define MNPLL_SFSTR_DYS                  1       /* [7:6]   config DDS step for soft-start frequency hopping             */
/*MT6583*/
/*MT6583*/ /* -- frequency hopping default setting -------------------------------------------------------------------------------- */
/*MT6583*/ #define TDMA_FHCON4_MASK                 (0x0)   /* clear all bits                                                       */
/*MT6583*/ #define TDMA_FHCON4_DEFAULT              ((MNPLL_FHCTL_GSMEN  )|(MNPLL_SFSTR_EN <<1)|(MNPLL_SFSTR_DTS<< 3)|               \
/*MT6583*/                                           (MNPLL_SFSTR_DYS<< 6)|(MNPLL_FRDDS_DTS<<9)|(MNPLL_FRDDS_DYS<<12)|               \
/*MT6583*/                                           (MNPLL_FSM_EN   <<15))
/*MT6583*/
/*MT6583*/ /* -- configure free-run ----------------------------------------------------------------------------------------------- */
/*MT6583*/ #define L1D_SET_MNPLL_FH_TYPE()                                                                                           \
/*MT6583*/ {  unsigned short d16 = HW_READ(TDMA_FHCON(4)) & TDMA_FHCON4_MASK;                                                        \
/*MT6583*/    HW_WRITE( TDMA_FHCON(4), d16|TDMA_FHCON4_DEFAULT|(MNPLL_FRDDS_EN<<2) );                                                \
/*MT6583*/ }
/*MT6583*/ /* --------------------------------------------------------------------------------------------------------------------- */
/*MT6583*/
/*MT6583*/ /* ----------------- */
/*MT6583*/ /* FHCON5 Setting    */
/*MT6583*/ /* --------------------------------------------------------------------------------------------------------------------- */
/*MT6583*/ #define MNPLL_FREE_RUN_RANGE             0x00BD  /* down 8%)                                                             */
/*MT6583*/ #define L1D_SET_MNPLL_FREE_RUN_RANGE()   HW_WRITE( TDMA_FHCON(5), MNPLL_FREE_RUN_RANGE );
/*MT6583*/ /* --------------------------------------------------------------------------------------------------------------------- */
/*MT6583*/
/*MT6583*/ /* ----------------- */
/*MT6583*/ /* FHCON6 Setting    */
/*MT6583*/ /* --------------------------------------------------------------------------------------------------------------------- */
/*MT6583*/ //#define TDMA_FHCON6_MASK                 TDMA_FHCON4_MASK
/*MT6583*/ //#define TDMA_FHCON6_DEFAULT              TDMA_FHCON4_DEFAULT
/*MT6583*/
/*MT6583*/ #define L1D_SET_EFPLL_FH_TYPE()          /* There is no EFPLL in MT6583                                                  */
/*MT6583*/ /* --------------------------------------------------------------------------------------------------------------------- */
/*MT6583*/
/*MT6583*/ /* ----------------- */
/*MT6583*/ /* FHCON7 Setting    */
/*MT6583*/ /* --------------------------------------------------------------------------------------------------------------------- */
/*MT6583*/ //#define EFPLL_FREE_RUN_RANGE             MNPLL_FREE_RUN_RANGE
/*MT6583*/ #define L1D_SET_EFPLL_FREE_RUN_RANGE()   /* There is no EFPLL in MT6583                                                  */
/*MT6583*/ /* --------------------------------------------------------------------------------------------------------------------- */
/*MT6583*/
   #endif

typedef struct
{
   sFHset FHset_Modem;
} L1DFHParamUDVT;

#endif // (defined __UDVT__)

#endif

