/*****************************************************************************
*  Copyright Statement:
*  -------------------
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
 *	NAND_MTD_FDM50.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This is a NAND Flash MTD driver header file.
 *
 * Author:
 * -------
 * -------
 * -------
 *
 *==============================================================================
 * 				HISTORY
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#ifndef NAND_MTD_FDM50_INTERNAL_H
#define NAND_MTD_FDM50_INTERNAL_H

/*******************************************************************************
 * Include Header Files
 *******************************************************************************/
#if defined __MTK_TARGET__
 #include "reg_base.h"
//RHR remove  #include "config_hw.h"
//RHR remove  #include "drvpdn.h"
// Add for RHR 
 #if defined(__NFI_VERSION3_1__)
//   #include "bl_NFI_V31.c"
 #endif 
 #include "dma_hw.h"
//RHR remove  #include "kal_non_specific_general_types.h"
//RHR remove  #include "kal_release.h" 
// #include "bl_NFI_V31.c"
 #include "kal_general_types.h"
 #include "kal_public_defs.h" 
// Add for RHR     
#endif

 #include "NAND_DevConfig.h"

/*******************************************************************************
 * Compiler definition
 *******************************************************************************/ 
#ifdef __MTK_TARGET__
	#if defined (__ARMCC_VERSION)
		#define __NAND_INLINE __inline
	#elif defined (__GNUC__)
		#define __NAND_INLINE inline
	#endif /* ARMCC , GNUC */
#else  /* __MTK_TARGET__ */
	#define __NAND_INLINE __inline
#endif /* __MTK_TARGET__ */

/*******************************************************************************
 * Message Log definition
 *******************************************************************************/
#if defined(__UBL__) || defined(__FUE__)
	#define nandlog_print
#elif defined(__MAUI_BASIC__) 
	#define nandlog_print dbg_print
#else
  #define nandlog_print tst_sys_trace
#endif  

/*******************************************************************************
 * define
 *******************************************************************************/

#ifndef NODEBUG
   #define DEBUG
#endif

#ifdef _MSC_VER
   #define INTERN _fastcall
   #define WATCOM_VOLATILE
#elif defined __BORLANDC__
   #define INTERN __fastcall
   #define WATCOM_VOLATILE
#else
   #define INTERN
   #define WATCOM_VOLATILE volatile   // Watcom compiler bug workaround
#endif

/*MTD status value must keep the low 16 bit to zero*/
#define MTD_STATUS_NO_ERROR           (0x00000000)
#define MTD_STATUS_ERROR              (0x00010000)
#define MTD_STATUS_CORRECTED          (0x00020000)
#define MTD_STATUS_EARLY_BAD          (0x00040000)
#define MTD_STATUS_FDM_BAD            (0x00080000)
#define MTD_STATUS_ID_NOT_SUPPORT     (0x00100000)
#define MTD_STATUS_PARA_ERROR         (0x00200000)

/* NAND flash plane setting */
#define NAND_PLANE_BLOCK_BIT0 (1 << 0)
#define NAND_PLANE_BLOCK_BIT1 (1 << 1)
#define NAND_PLANE_BLOCK_BIT2 (1 << 2)
#define NAND_PLANE_BLOCK_BIT3 (1 << 3)
#define NAND_PLANE_BLOCK_BIT4 (1 << 4)
#define NAND_PLANE_BLOCK_BIT5 (1 << 5)
#define NAND_PLANE_BLOCK_BIT6 (1 << 6)
#define NAND_PLANE_BLOCK_BIT7 (1 << 7)
#define NAND_PLANE_BLOCK_BIT8 (1 << 8)
#define NAND_PLANE_BLOCK_BIT9 (1 << 9)
#define NAND_PLANE_BLOCK_BIT10 (1 << 10)
#define NAND_PLANE_BLOCK_BIT11 (1 << 11)
#define NAND_PLANE_BLOCK_BIT12 (1 << 12)
#define NAND_PLANE_BLOCK_BIT13 (1 << 13)
#define NAND_PLANE_BLOCK_BIT14 (1 << 14)
#define NAND_PLANE_BLOCK_BIT15 (1 << 15)
#define NAND_PLANE_BLOCK_BIT16 (1 << 16)
/*******************************************************************************
 * NFI address definition
 *******************************************************************************/
#define DMA_NFI  0xf

#if defined __MTK_TARGET__

#if ((defined(MT6228)) || (defined(MT6229)) || (defined(MT6230)))
#define NFI_GPIO_CON    ((volatile UINT16P)(GPIO_base+0x01D0))		// gpio control pin
#define NFI_GPIO_DATA1  ((volatile UINT16P)(GPIO_base+0x0200))		// data bit 8-9
#define NFI_GPIO_DATA2  ((volatile UINT16P)(GPIO_base+0x0210))		// data bit 10-15
#elif ((defined(MT6219))|| (defined(MT6226))|| (defined(MT6226M)) || (defined(MT6227)))
#define NFI_GPIO_CON    ((volatile UINT16P)(GPIO_base+0x0180))
#elif (defined(MT6225))
#define NFI_GPIO_CON1    ((volatile UINT16P)(GPIO_base+0x0190))
#define NFI_GPIO_CON2    ((volatile UINT16P)(GPIO_base+0x01A0))
#elif (defined(MT6238)) || (defined(MT6239)) /*MAUI_00728731*/
#define NFI_GPIO_CON1    ((volatile UINT16P)(GPIO_base+0x1200))
#define NFI_GPIO_CON2    ((volatile UINT16P)(GPIO_base+0x1300))
#elif (defined (MT6235)) || (defined(MT6235B))/*MAUI_00728731*/
#define NFI_GPIO_CON1    ((volatile UINT16P)(GPIO_base+0x1300))
#define NFI_GPIO_CON2    ((volatile UINT16P)(GPIO_base+0x1400))
#elif (defined (MT6268A) || defined (MT6268) || defined(MT6236) || defined(MT6236B) || defined(MT6270A)|| defined(TK6280))
/*NAND control pin is dedicate */
//#define NFI_IO_DRV0       ((volatile UINT32P)(0x80000500))
//#define NFI_IO_DRV1       ((volatile UINT32P)(0x80000504))
#define NFI_IO_DRV0       ((volatile UINT32P)(CONFIG_base+0x0500))
#define NFI_IO_DRV1       ((volatile UINT32P)(CONFIG_base+0x0504))
#elif (defined(MT6256))
	#if defined(MT6256_S00)
		#define NFI_GPIO_MODE3    ((volatile UINT16P)(GPIO_base+0x0620))  //NLD11
		#define NFI_GPIO_MODE4    ((volatile UINT16P)(GPIO_base+0x0630))  //NLD12,NLD10,NLD9
		
		#define NFI_GPIO_MODE7    ((volatile UINT16P)(GPIO_base+0x0660)) //NLD8,NLD7,NLD6
		#define NFI_GPIO_MODE8    ((volatile UINT16P)(GPIO_base+0x0670)) //NLD5,NLD4,NLD3,NLD2
		#define NFI_GPIO_MODE9    ((volatile UINT16P)(GPIO_base+0x0680)) //NLD1,NLD0,NRNB,NCLE
		#define NFI_GPIO_MODE10   ((volatile UINT16P)(GPIO_base+0x0690)) //NALE,NWEB,NREB,NCE0B
		
		#define NFI_GPIO_MODE18   ((volatile UINT16P)(GPIO_base+0x0710))  //NLD15,NLD14
		#define NFI_GPIO_MODE19   ((volatile UINT16P)(GPIO_base+0x0720))  //NLD13
		
		#define NFI_IO_DRV0       ((volatile UINT32P)(CONFIG_base+0x0500))
		#define NFI_IO_DRV1       ((volatile UINT32P)(CONFIG_base+0x0504))
	#else
		#define NFI_GPIO_MODE6    ((volatile UINT16P)(GPIO_base+0x650)) // NLD15,x,x,x
		#define NFI_GPIO_MODE7    ((volatile UINT16P)(GPIO_base+0x660)) // NLD14,13,12,11
		#define NFI_GPIO_MODE8    ((volatile UINT16P)(GPIO_base+0x670)) // NLD10, 9, 8, 7
		#define NFI_GPIO_MODE9    ((volatile UINT16P)(GPIO_base+0x680)) // NLD 6, 5, 4, 3
		#define NFI_GPIO_MODE10   ((volatile UINT16P)(GPIO_base+0x690)) // NLD 2, 1, 0, RDY
		#define NFI_GPIO_MODE11   ((volatile UINT16P)(GPIO_base+0x6A0)) // CLE, ALE, WE, RE
		#define NFI_GPIO_MODE12   ((volatile UINT16P)(GPIO_base+0x6B0)) //   x, x, x, CE0
    #define NFI_IO_DRV1       ((volatile UINT32P)(CONFIG_base+0x0504))
#endif
#elif (defined(MT6255))
    #define NFI_IO_DRV1       ((volatile UINT32P)(CONFIG_base+0x0504))
#elif (defined(MT6280))    
		#define NFI_MD_CHIP_STATUS ((volatile UINT16P)(CONFIG_base+0x018))
		//NLD0~7 Bonding option is for Dougle Sip
		#define NFI_GPIO_1000        ((volatile UINT16P)(GPIO_base+0x1000))  //NLD0, 1, 2, 3
		#define NFI_GPIO_1100        ((volatile UINT16P)(GPIO_base+0x1100))  //NLD4, 5, 6, 7

		//NLD0~7 Bonding option is for Dongle MCP or WIFI router
		#define NFI_GPIO_1400        ((volatile UINT16P)(GPIO_base+0x1400))  //NLD0, 1
		#define NFI_GPIO_1500        ((volatile UINT16P)(GPIO_base+0x1500))  //NLD2, 3, 4, 5
		#define NFI_GPIO_1600        ((volatile UINT16P)(GPIO_base+0x1600))  //NLD6, 7

		#define NFI_GPIO_1200        ((volatile UINT16P)(GPIO_base+0x1200))  //NLD8, 9 , 10, 11
		#define NFI_GPIO_1300        ((volatile UINT16P)(GPIO_base+0x1300))  //NLD12, 13, 14, 15

		#define NFI_GPIO_2500        ((volatile UINT16P)(GPIO_base+0x2500))  //NRNB, NWEB, NREB, NCLE
		#define NFI_GPIO_2600        ((volatile UINT16P)(GPIO_base+0x2600))  //NALE, NCE0B		
		
		// driving mapping: 0/1/2/3==>4/8/12/16mA
		#define NFI_GPIO_DRV1       ((volatile UINT16P)(GPIO_base+0x3000))  
		#define NFI_GPIO_DRV6       ((volatile UINT16P)(GPIO_base+0x3500))  
		#define NFI_GPIO_SR1        ((volatile UINT16P)(GPIO_base+0x4000))  
		#define NFI_GPIO_SR2        ((volatile UINT16P)(GPIO_base+0x4100))  
		#define NFI_GPIO_SR3        ((volatile UINT16P)(GPIO_base+0x4200))  

#elif (defined (MT6253T) || defined (MT6253))
#define NFI_GPIO_CON1    ((volatile UINT16P)(GPIO_base+0x01C0))
#else   //MT6217, MT6218B 
#define NFI_GPIO_CON    ((volatile UINT16P)(GPIO_base+0x0130))
#endif

#define NFI_ACIF_CON0		((volatile UINT16P)(CONFIG_base + 0x700))
#define NFI_ACIF_CON1		((volatile UINT16P)(CONFIG_base + 0x704))
#define NFI_ACIF_CON2		((volatile UINT16P)(CONFIG_base + 0x708))
#define NFI_ACIF_CON3		((volatile UINT16P)(CONFIG_base + 0x70c))
#define NFI_ACIF_CON4		((volatile UINT16P)(CONFIG_base + 0x710))

#elif defined(FLASH_DISKDRV_DEBUG) && !defined(__MTK_TARGET__)
    #define NFI_GPIO_CON    ((volatile UINT16P)(DummyNFI_Reg))		// gpio control pin
    #define NFI_GPIO_DATA1  ((volatile UINT16P)(DummyNFI_Reg))		// data bit 8-9
    #define NFI_GPIO_DATA2  ((volatile UINT16P)(DummyNFI_Reg))		// data bit 10-15
    #define NFI_GPIO_CON1    ((volatile UINT16P)(DummyNFI_Reg))
    #define NFI_GPIO_CON2    ((volatile UINT16P)(DummyNFI_Reg))
	#define NFI_ACIF_CON0	 ((volatile UINT16P)(DummyNFI_Reg))
#endif

#if defined __MTK_TARGET__

#if defined(__NFI_VERSION3_1__)

#define NFI_CNFG        ((volatile UINT16P)(NFI_base+0x0000))
#define NFI_PAGEFMT     ((volatile UINT16P)(NFI_base+0x0004))
#define NFI_CON         ((volatile UINT16P)(NFI_base+0x0008))
#define NFI_ACCCON      ((volatile UINT32P)(NFI_base+0x000C))
#define NFI_INTR_EN     ((volatile UINT16P)(NFI_base+0x0010))
#define NFI_INTR        ((volatile UINT16P)(NFI_base+0x0014))

#define NFI_CMD         ((volatile UINT16P)(NFI_base+0x0020))

#define NFI_ADDRNOB     ((volatile UINT16P)(NFI_base+0x0030))
#define NFI_COLADDR     ((volatile UINT32P)(NFI_base+0x0034))
#define NFI_ROWADDR     ((volatile UINT32P)(NFI_base+0x0038))

#define NFI_STRDATA     ((volatile UINT16P)(NFI_base+0x0040))
#define NFI_CNRNB	    ((volatile UINT16P)(NFI_base+0x0044))

#define NFI_DATAW       ((volatile UINT32P)(NFI_base+0x0050))
#define NFI_DATAR       ((volatile UINT32P)(NFI_base+0x0054))
#define NFI_PIO_DIRDY   ((volatile UINT16P)(NFI_base+0x0058))

#define NFI_STA         ((volatile UINT32P)(NFI_base+0x0060))
#define NFI_FIFOSTA     ((volatile UINT16P)(NFI_base+0x0064))

#define NFI_ADDRCNTR    ((volatile UINT16P)(NFI_base+0x0070))

#define NFI_STRADDR     ((volatile UINT32P)(NFI_base+0x0080))
#define NFI_BYTELEN     ((volatile UINT16P)(NFI_base+0x0084))

#define NFI_CSEL        ((volatile UINT16P)(NFI_base+0x0090))
#define NFI_IOCON       ((volatile UINT16P)(NFI_base+0x0094))

#define NFI_FDM0L       ((volatile UINT32P)(NFI_base+0x00A0))
#define NFI_FDM0M       ((volatile UINT32P)(NFI_base+0x00A4))

#define NFI_FIFODATA0   ((volatile UINT32P)(NFI_base+0x0190))
#define NFI_FIFODATA1   ((volatile UINT32P)(NFI_base+0x0194))
#define NFI_FIFODATA2   ((volatile UINT32P)(NFI_base+0x0198))
#define NFI_FIFODATA3   ((volatile UINT32P)(NFI_base+0x019C))

#define NFI_MCON		((volatile UINT32P)(NFI_base+0x0200))
#define NFI_TOTALCNT	((volatile UINT32P)(NFI_base+0x0204))
#define NFI_RQCNT		((volatile UINT32P)(NFI_base+0x0208))
#define NFI_ACCNT		((volatile UINT32P)(NFI_base+0x020c))
#define NFI_MASTERSTA   ((volatile UINT32P)(NFI_base+0x0210))

#if defined(MT6276)
#define NFI_DEBUG_CON1  ((volatile UINT16P)(NFI_base+0x0180))
#else
#define NFI_DEBUG_CON1  ((volatile UINT16P)(NFI_base+0x0220))
#endif

/* NFI_CNFG */
#define CNFG_DMA             (0x0001)
#define CNFG_READ_EN         (0x0002)
#define CNFG_DMA_BURST_EN    (0x0004)
#define CNFG_BYTE_RW         (0x0040)
#define CNFG_HW_ECC_EN       (0x0100)
#define CNFG_AUTO_FMT_EN     (0x0200)
#define CNFG_OP_IDLE         (0x0000)
#define CNFG_OP_READ         (0x1000)
#define CNFG_OP_SRD          (0x2000)
#define CNFG_OP_PRGM         (0x3000)
#define CNFG_OP_ERASE        (0x4000)
#define CNFG_OP_RESET        (0x5000)
#define CNFG_OP_CUST         (0x6000)

#define CNFG_OP_MODE_MASK    (0x7000)
#define CNFG_OP_MODE_SHIFT   (12)

/* NFI_PAGEFMT */
#define PAGEFMT_512          (0x0000)
#define PAGEFMT_2K           (0x0001)
#define PAGEFMT_4K           (0x0002)

#define PAGEFMT_PAGE_MASK    (0x0003)

#define PAGEFMT_DBYTE_EN     (0x0008)

#define PAGEFMT_SPARE_16     (0x0000)
#define PAGEFMT_SPARE_26     (0x0001)
#define PAGEFMT_SPARE_27     (0x0002)
#define PAGEFMT_SPARE_28     (0x0003)
#define PAGEFMT_SPARE_MASK   (0x0030)
#define PAGEFMT_SPARE_SHIFT  (4)

#define PAGEFMT_FDM_MASK     (0x0F00)
#define PAGEFMT_FDM_SHIFT    (8)

#define PAGEFMT_FDM_ECC_MASK  (0xF000)
#define PAGEFMT_FDM_ECC_SHIFT (12)

#define PAGEFMT_FDM_ECC_DEFAULT		8
#define PAGEFMT_FDM_DEFAULT			8
#define PAGEFMT_FDM_ECC_SETTING 	((PAGEFMT_FDM_ECC_DEFAULT << PAGEFMT_FDM_ECC_SHIFT) | (PAGEFMT_FDM_DEFAULT << PAGEFMT_FDM_SHIFT))

/* NFI_CON */
#define CON_FIFO_FLUSH       (0x0001)
#define CON_NFI_RST          (0x0002)
#define CON_NFI_SRD          (0x0010)

#define CON_NFI_NOB_MASK     (0x0070)
#define CON_NFI_NOB_SHIFT    (5)

#define CON_NFI_BRD          (0x0100)
#define CON_NFI_BWR          (0x0200)

#define CON_NFI_SEC_MASK     (0xF000)
#define CON_NFI_SEC_SHIFT    (12)

/* NFI_ADDRNOB */
#define ADDR_COL_NOB_MASK    (0x0007)
#define ADDR_COL_NOB_SHIFT   (0)
#define ADDR_ROW_NOB_MASK    (0x0070)
#define ADDR_ROW_NOB_SHIFT   (4)

/* NFI_PIO_DIRDY */
#define PIO_DI_DRY			 (0x0001)

/* NFI_STA */
#define STA_READ_EMPTY       (0x00001000)
#define STA_ACC_LOCK         (0x00000010)
#define STA_CMD_STATE        (0x00000001)
#define STA_ADDR_STATE       (0x00000002)
#define STA_DATAR_STATE      (0x00000004)
#define STA_DATAW_STATE      (0x00000008)

#define STA_NAND_FSM_MASK    (0x1F000000)
#define STA_NAND_BUSY        (0x00000100)
#define STA_NAND_BUSY_RETURN (0x00000200)
#define STA_NFI_FSM_MASK     (0x000F0000)
#define STA_NFI_OP_MASK      (0x0000000F)

/* NFI_FIFOSTA */
#define FIFO_RD_EMPTY        	(0x0040)
#define FIFO_RD_FULL         	(0x0080)
#define FIFO_WR_FULL         	(0x8000)
#define FIFO_WR_EMPTY        	(0x4000)
#define FIFO_RD_REMAIN(x)    	(0x1F&(x))
#define FIFO_WR_REMAIN(x)    	((0x1F00&(x))>>8)
#define FIFO_PIO_READY(x)		(0x1 & x)

/* NFI_ADDRCNTR */
#define ADDRCNTR_CNTR(x)     ((0xF000&(x))>>12)
#define ADDRCNTR_OFFSET(x)   (0x03FF&(x))

/* NFI_CNRNB */
#define STROBE_TIMEOUT          (0xF1)

/* NFI_IOCON */
#define BRSTN_MASK				(0x00F0)
#define BRSTN_DEFAULT			(0x00F0)

#define NAND_SECTOR_SIZE        (512)
#define NAND_SECTOR_SHIFT		(9)

/*******************************************************************************
 * Macro definition
 *******************************************************************************/
#define NFI_Wait_Ready(timeout)   while ( (*NFI_STA & STA_NAND_BUSY) && (timeout) ){timeout--;}
#define NFI_Empty_Page()          ((*NFI_STA & STA_READ_EMPTY)>0)
#define NFI_FIFO_Empty(timeout)   while ( !(*NFI_FIFOSTA & FIFO_WR_EMPTY) && (timeout) ){timeout--;}

#define NFI_WAIT_TRANSFER_DONE(sec_num, timeout) \
   do {\
         if(ADDRCNTR_CNTR(DRV_Reg(NFI_ADDRCNTR)) < sec_num)\
            timeout--;\
         else\
            break;\
   } while( timeout>0 );

#define NFI_FIFO_DEPTH (16) /* in bytes */

#elif defined(__NFI_VERSION2__)

#define NFI_ACCCON      ((volatile UINT32P)(NFI_base+0x0000))
#define NFI_PAGEFMT     ((volatile UINT16P)(NFI_base+0x0004))
#define NFI_OPCON       ((volatile UINT16P)(NFI_base+0x0008))
#define NFI_CMD         ((volatile UINT16P)(NFI_base+0x0010))
#define NFI_ADDNOB      ((volatile UINT16P)(NFI_base+0x0020))
#define NFI_ADDRL       ((volatile UINT32P)(NFI_base+0x0024))
#define NFI_ADDRM       ((volatile UINT32P)(NFI_base+0x0028))
#define NFI_DATAW       ((volatile UINT32P)(NFI_base+0x0030))
#define NFI_DATAWB      ((volatile UINT16P)(NFI_base+0x0034))
#define NFI_DATAR       ((volatile UINT32P)(NFI_base+0x0038))
#define NFI_DATARB		  ((volatile UINT16P)(NFI_base+0x003C))
#define NFI_PSTA        ((volatile UINT32P)(NFI_base+0x0040))
#define NFI_FIFOSTA     ((volatile UINT16P)(NFI_base+0x0044))
#define NFI_FIFODATA0   ((volatile UINT32P)(NFI_base+0x0050))
#define NFI_FIFODATA1   ((volatile UINT32P)(NFI_base+0x0054))
#define NFI_FIFODATA2   ((volatile UINT32P)(NFI_base+0x0058))
#define NFI_FIFODATA3   ((volatile UINT32P)(NFI_base+0x005C))
#define NFI_CON         ((volatile UINT16P)(NFI_base+0x0060))
#define NFI_INTR        ((volatile UINT32P)(NFI_base+0x0064))
#define NFI_INTR_EN     ((volatile UINT32P)(NFI_base+0x0068))
#define NFI_PAGECNTR    ((volatile UINT16P)(NFI_base+0x0070))
#define NFI_ADDRCNTR    ((volatile UINT16P)(NFI_base+0x0074))
#define NFI_SYM0_ADDR   ((volatile UINT16P)(NFI_base+0x0080))
#define NFI_SYM1_ADDR   ((volatile UINT16P)(NFI_base+0x0084))
#define NFI_SYM2_ADDR   ((volatile UINT16P)(NFI_base+0x0088))
#define NFI_SYM3_ADDR   ((volatile UINT16P)(NFI_base+0x008C))
#define NFI_SYM4_ADDR   ((volatile UINT16P)(NFI_base+0x0090))
#define NFI_SYM5_ADDR   ((volatile UINT16P)(NFI_base+0x0094))
#define NFI_SYM6_ADDR   ((volatile UINT16P)(NFI_base+0x0098))
#define NFI_SYM7_ADDR   ((volatile UINT16P)(NFI_base+0x009C))
#define NFI_SYMS0_ADDR  ((volatile UINT16P)(NFI_base+0x00A0))
#define NFI_SYMS1_ADDR  ((volatile UINT16P)(NFI_base+0x00A4))
#define NFI_SYMS2_ADDR  ((volatile UINT16P)(NFI_base+0x00A8))
#define NFI_SYMS3_ADDR  ((volatile UINT16P)(NFI_base+0x00AC))
#define NFI_SYM0_DAT    ((volatile UINT32P)(NFI_base+0x00B0))
#define NFI_SYM1_DAT    ((volatile UINT32P)(NFI_base+0x00B4))
#define NFI_SYM2_DAT    ((volatile UINT32P)(NFI_base+0x00B8))
#define NFI_SYM3_DAT    ((volatile UINT32P)(NFI_base+0x00BC))
#define NFI_SYM4_DAT    ((volatile UINT32P)(NFI_base+0x00C0))
#define NFI_SYM5_DAT    ((volatile UINT32P)(NFI_base+0x00C4))
#define NFI_SYM6_DAT    ((volatile UINT32P)(NFI_base+0x00C8))
#define NFI_SYM7_DAT    ((volatile UINT32P)(NFI_base+0x00CC))
#define NFI_SYMS0_DAT   ((volatile UINT32P)(NFI_base+0x00D0))
#define NFI_SYMS1_DAT   ((volatile UINT32P)(NFI_base+0x00D4))
#define NFI_SYMS2_DAT   ((volatile UINT32P)(NFI_base+0x00D8))
#define NFI_SYMS3_DAT   ((volatile UINT32P)(NFI_base+0x00DC))
#define NFI_PAR_0P      ((volatile UINT16P)(NFI_base+0x00E0))
#define NFI_PAR_0C      ((volatile UINT16P)(NFI_base+0x00E4))
#define NFI_PAR_1P      ((volatile UINT16P)(NFI_base+0x00E8))
#define NFI_PAR_1C      ((volatile UINT16P)(NFI_base+0x00EC))
#define NFI_PAR_2P      ((volatile UINT16P)(NFI_base+0x00F0))
#define NFI_PAR_2C      ((volatile UINT16P)(NFI_base+0x00F4))
#define NFI_PAR_3P      ((volatile UINT16P)(NFI_base+0x00F8))
#define NFI_PAR_3C      ((volatile UINT16P)(NFI_base+0x00FC))
#define NFI_PAR_4P      ((volatile UINT16P)(NFI_base+0x0100))
#define NFI_PAR_4C      ((volatile UINT16P)(NFI_base+0x0104))
#define NFI_PAR_5P      ((volatile UINT16P)(NFI_base+0x0108))
#define NFI_PAR_5C      ((volatile UINT16P)(NFI_base+0x010C))
#define NFI_PAR_6P      ((volatile UINT16P)(NFI_base+0x0110))
#define NFI_PAR_6C      ((volatile UINT16P)(NFI_base+0x0114))
#define NFI_PAR_7P      ((volatile UINT16P)(NFI_base+0x0118))
#define NFI_PAR_7C      ((volatile UINT16P)(NFI_base+0x011C))
#define NFI_PARS_0P     ((volatile UINT16P)(NFI_base+0x0120))
#define NFI_PARS_0C     ((volatile UINT16P)(NFI_base+0x0124))
#define NFI_PARS_1P     ((volatile UINT16P)(NFI_base+0x0128))
#define NFI_PARS_1C     ((volatile UINT16P)(NFI_base+0x012C))
#define NFI_PARS_2P     ((volatile UINT16P)(NFI_base+0x0130))
#define NFI_PARS_2C     ((volatile UINT16P)(NFI_base+0x0134))
#define NFI_PARS_3P     ((volatile UINT16P)(NFI_base+0x0138))
#define NFI_PARS_3C     ((volatile UINT16P)(NFI_base+0x013C))
#define NFI_ERRDET      ((volatile UINT32P)(NFI_base+0x0140))
#define NFI_PARECC      ((volatile UINT32P)(NFI_base+0x0144))
#define NFI_SCON        ((volatile UINT16P)(NFI_base+0x0148))
#define NFI_CSEL        ((volatile UINT16P)(NFI_base+0x0200))
#define NFI_IOCON       ((volatile UINT16P)(NFI_base+0x0204))

#else	// #if defined(__NFI_VERSION2__)
#define NFI_ACCCON      ((volatile UINT16P)(NFI_base+0x0000))
#define NFI_PAGEFMT     ((volatile UINT16P)(NFI_base+0x0004))
#define NFI_OPCON       ((volatile UINT16P)(NFI_base+0x0008))
#define NFI_CMD         ((volatile UINT16P)(NFI_base+0x000C))
#define NFI_ADDNOB      ((volatile UINT16P)(NFI_base+0x0010))
#define NFI_ADDRL       ((volatile UINT32P)(NFI_base+0x0014))
#define NFI_ADDRM       ((volatile UINT16P)(NFI_base+0x0018))
#define NFI_DATAW       ((volatile UINT32P)(NFI_base+0x001C))
#define NFI_DATAWB      ((volatile UINT16P)(NFI_base+0x0020))
#define NFI_DATAR       ((volatile UINT32P)(NFI_base+0x0024))
#define NFI_DATARB		((volatile UINT16P)(NFI_base+0x0028))
#define NFI_PSTA        ((volatile UINT16P)(NFI_base+0x002C))
#define NFI_FIFOCON     ((volatile UINT16P)(NFI_base+0x0030))
#define NFI_CON         ((volatile UINT16P)(NFI_base+0x0034))
#define NFI_INTR        ((volatile UINT16P)(NFI_base+0x0038))
#define NFI_INTR_EN     ((volatile UINT16P)(NFI_base+0x003C))
#define NFI_PAGECNTR		((volatile UINT16P)(NFI_base+0x0040))
#define NFI_ADDRCNTR		((volatile UINT16P)(NFI_base+0x0044))
#define NFI_SYM0_ADDR   ((volatile UINT16P)(NFI_base+0x0050))
#define NFI_SYM1_ADDR   ((volatile UINT16P)(NFI_base+0x0054))
#define NFI_SYM2_ADDR   ((volatile UINT16P)(NFI_base+0x0058))
#define NFI_SYM3_ADDR   ((volatile UINT16P)(NFI_base+0x005C))
#define NFI_SYM0_DAT    ((volatile UINT32P)(NFI_base+0x0060))
#define NFI_SYM1_DAT    ((volatile UINT32P)(NFI_base+0x0064))
#define NFI_SYM2_DAT    ((volatile UINT32P)(NFI_base+0x0068))
#define NFI_SYM3_DAT    ((volatile UINT32P)(NFI_base+0x006C))
#define NFI_ERRDET      ((volatile UINT16P)(NFI_base+0x0070))
#define NFI_PAR0        ((volatile UINT16P)(NFI_base+0x0080))
#define NFI_PAR1        ((volatile UINT16P)(NFI_base+0x0084))
#define NFI_PAR2        ((volatile UINT16P)(NFI_base+0x0088))
#define NFI_PAR3        ((volatile UINT16P)(NFI_base+0x008C))
#define NFI_PAR4        ((volatile UINT16P)(NFI_base+0x0090))
#define NFI_PAR5        ((volatile UINT16P)(NFI_base+0x0094))
#define NFI_PAR6        ((volatile UINT16P)(NFI_base+0x0098))
#define NFI_PAR7        ((volatile UINT16P)(NFI_base+0x009C))
#define NFI_CSEL			((volatile UINT16P)(NFI_base+0x0100))
#endif /*__NFI_VERSION2__*/

#elif defined(FLASH_DISKDRV_DEBUG) && !defined(__MTK_TARGET__)

	#if defined(__NFI_VERSION3_1__)

	#define NFI_CNFG        ((volatile UINT16P)(DummyNFI_Reg))
	#define NFI_PAGEFMT     ((volatile UINT16P)(DummyNFI_Reg))
	#define NFI_CON         ((volatile UINT16P)(DummyNFI_Reg))
	#define NFI_ACCCON      ((volatile UINT32P)(DummyNFI_Reg))
	#define NFI_INTR_EN     ((volatile UINT16P)(DummyNFI_Reg))
	#define NFI_INTR        ((volatile UINT16P)(DummyNFI_Reg))

	#define NFI_CMD         ((volatile UINT16P)(DummyNFI_Reg))

	#define NFI_ADDRNOB     ((volatile UINT16P)(DummyNFI_Reg))
	#define NFI_COLADDR     ((volatile UINT32P)(DummyNFI_Reg))
	#define NFI_ROWADDR     ((volatile UINT32P)(DummyNFI_Reg))

	#define NFI_STRDATA     ((volatile UINT16P)(DummyNFI_Reg))
	#define NFI_CNRNB	    ((volatile UINT16P)(DummyNFI_Reg))

	#define NFI_DATAW       ((volatile UINT32P)(DummyNFI_Reg))
	#define NFI_DATAR       ((volatile UINT32P)(DummyNFI_Reg))
	#define NFI_PIO_DIRDY   ((volatile UINT16P)(DummyNFI_Reg))

	#define NFI_STA         ((volatile UINT32P)(DummyNFI_Reg))
	#define NFI_FIFOSTA     ((volatile UINT16P)(DummyNFI_Reg))

	#define NFI_ADDRCNTR    ((volatile UINT16P)(DummyNFI_Reg))

	#define NFI_STRADDR     ((volatile UINT32P)(DummyNFI_Reg))
	#define NFI_BYTELEN     ((volatile UINT16P)(DummyNFI_Reg))

	#define NFI_CSEL        ((volatile UINT16P)(DummyNFI_Reg))
	#define NFI_IOCON       ((volatile UINT16P)(DummyNFI_Reg))

	#define NFI_FDM0L       ((volatile UINT32P)(DummyNFI_Reg))
	#define NFI_FDM0M       ((volatile UINT32P)(DummyNFI_Reg))

	#define NFI_FIFODATA0   ((volatile UINT32P)(DummyNFI_Reg))
	#define NFI_FIFODATA1   ((volatile UINT32P)(DummyNFI_Reg))
	#define NFI_FIFODATA2   ((volatile UINT32P)(DummyNFI_Reg))
	#define NFI_FIFODATA3   ((volatile UINT32P)(DummyNFI_Reg))

	#define NFI_MCON		((volatile UINT32P)(DummyNFI_Reg))
	#define NFI_TOTALCNT	((volatile UINT32P)(DummyNFI_Reg))
	#define NFI_RQCNT		((volatile UINT32P)(DummyNFI_Reg))
	#define NFI_ACCNT		((volatile UINT32P)(DummyNFI_Reg))

    #elif defined(__NFI_VERSION2__)

    #define NFI_ACCCON      ((volatile UINT32P)(DummyNFI_Reg))
    #define NFI_PAGEFMT     ((volatile UINT16P)(DummyNFI_Reg))
    #define NFI_OPCON       ((volatile UINT16P)(DummyNFI_Reg))
    #define NFI_CMD         ((volatile UINT16P)(DummyNFI_Reg))
    #define NFI_ADDNOB      ((volatile UINT16P)(DummyNFI_Reg))
    #define NFI_ADDRL       ((volatile UINT32P)(DummyNFI_Reg))
    #define NFI_ADDRM       ((volatile UINT32P)(DummyNFI_Reg))
    #define NFI_DATAW       ((volatile UINT32P)(DummyNFI_Reg))
    #define NFI_DATAWB      ((volatile UINT16P)(DummyNFI_Reg))
    #define NFI_DATAR       ((volatile UINT32P)(DummyNFI_Reg))
    #define NFI_DATARB		((volatile UINT16P)(DummyNFI_Reg))
    //#define NFI_PSTA      ((volatile UINT32P)(DummyNFI_Reg)) /*Marked in simulator case and define at nand_mtd.c*/
    #define NFI_FIFOSTA     ((volatile UINT16P)(DummyNFI_Reg))
    #define NFI_FIFODATA0   ((volatile UINT32P)(DummyNFI_Reg))
    #define NFI_FIFODATA1   ((volatile UINT32P)(DummyNFI_Reg))
    #define NFI_FIFODATA2   ((volatile UINT32P)(DummyNFI_Reg))
    #define NFI_FIFODATA3   ((volatile UINT32P)(DummyNFI_Reg))
    #define NFI_CON         ((volatile UINT16P)(DummyNFI_Reg))
    #define NFI_INTR        ((volatile UINT32P)(DummyNFI_Reg))
    #define NFI_INTR_EN     ((volatile UINT32P)(DummyNFI_Reg))
    #define NFI_PAGECNTR    ((volatile UINT16P)(DummyNFI_Reg))
    #define NFI_ADDRCNTR    ((volatile UINT16P)(DummyNFI_Reg))
    #define NFI_SYM0_ADDR   ((volatile UINT16P)(DummyNFI_Reg))
    #define NFI_SYM1_ADDR   ((volatile UINT16P)(DummyNFI_Reg))
    #define NFI_SYM2_ADDR   ((volatile UINT16P)(DummyNFI_Reg))
    #define NFI_SYM3_ADDR   ((volatile UINT16P)(DummyNFI_Reg))
    #define NFI_SYM4_ADDR   ((volatile UINT16P)(DummyNFI_Reg))
    #define NFI_SYM5_ADDR   ((volatile UINT16P)(DummyNFI_Reg))
    #define NFI_SYM6_ADDR   ((volatile UINT16P)(DummyNFI_Reg))
    #define NFI_SYM7_ADDR   ((volatile UINT16P)(DummyNFI_Reg))
    #define NFI_SYMS0_ADDR  ((volatile UINT16P)(DummyNFI_Reg))
    #define NFI_SYMS1_ADDR  ((volatile UINT16P)(DummyNFI_Reg))
    #define NFI_SYMS2_ADDR  ((volatile UINT16P)(DummyNFI_Reg))
    #define NFI_SYMS3_ADDR  ((volatile UINT16P)(DummyNFI_Reg))
    #define NFI_SYM0_DAT    ((volatile UINT32P)(DummyNFI_Reg))
    #define NFI_SYM1_DAT    ((volatile UINT32P)(DummyNFI_Reg))
    #define NFI_SYM2_DAT    ((volatile UINT32P)(DummyNFI_Reg))
    #define NFI_SYM3_DAT    ((volatile UINT32P)(DummyNFI_Reg))
    #define NFI_SYM4_DAT    ((volatile UINT32P)(DummyNFI_Reg))
    #define NFI_SYM5_DAT    ((volatile UINT32P)(DummyNFI_Reg))
    #define NFI_SYM6_DAT    ((volatile UINT32P)(DummyNFI_Reg))
    #define NFI_SYM7_DAT    ((volatile UINT32P)(DummyNFI_Reg))
    #define NFI_SYMS0_DAT   ((volatile UINT32P)(DummyNFI_Reg))
    #define NFI_SYMS1_DAT   ((volatile UINT32P)(DummyNFI_Reg))
    #define NFI_SYMS2_DAT   ((volatile UINT32P)(DummyNFI_Reg))
    #define NFI_SYMS3_DAT   ((volatile UINT32P)(DummyNFI_Reg))
    #define NFI_PAR_0P      ((volatile UINT16P)(DummyNFI_Reg))
    #define NFI_PAR_0C      ((volatile UINT16P)(DummyNFI_Reg))
    #define NFI_PAR_1P      ((volatile UINT16P)(DummyNFI_Reg))
    #define NFI_PAR_1C      ((volatile UINT16P)(DummyNFI_Reg))
    #define NFI_PAR_2P      ((volatile UINT16P)(DummyNFI_Reg))
    #define NFI_PAR_2C      ((volatile UINT16P)(DummyNFI_Reg))
    #define NFI_PAR_3P      ((volatile UINT16P)(DummyNFI_Reg))
    #define NFI_PAR_3C      ((volatile UINT16P)(DummyNFI_Reg))
    #define NFI_PAR_4P      ((volatile UINT16P)(DummyNFI_Reg))
    #define NFI_PAR_4C      ((volatile UINT16P)(DummyNFI_Reg))
    #define NFI_PAR_5P      ((volatile UINT16P)(DummyNFI_Reg))
    #define NFI_PAR_5C      ((volatile UINT16P)(DummyNFI_Reg))
    #define NFI_PAR_6P      ((volatile UINT16P)(DummyNFI_Reg))
    #define NFI_PAR_6C      ((volatile UINT16P)(DummyNFI_Reg))
    #define NFI_PAR_7P      ((volatile UINT16P)(DummyNFI_Reg))
    #define NFI_PAR_7C      ((volatile UINT16P)(DummyNFI_Reg))
    #define NFI_PARS_0P     ((volatile UINT16P)(DummyNFI_Reg))
    #define NFI_PARS_0C     ((volatile UINT16P)(DummyNFI_Reg))
    #define NFI_PARS_1P     ((volatile UINT16P)(DummyNFI_Reg))
    #define NFI_PARS_1C     ((volatile UINT16P)(DummyNFI_Reg))
    #define NFI_PARS_2P     ((volatile UINT16P)(DummyNFI_Reg))
    #define NFI_PARS_2C     ((volatile UINT16P)(DummyNFI_Reg))
    #define NFI_PARS_3P     ((volatile UINT16P)(DummyNFI_Reg))
    #define NFI_PARS_3C     ((volatile UINT16P)(DummyNFI_Reg))
    #define NFI_ERRDET      ((volatile UINT32P)(DummyNFI_Reg))
    #define NFI_PARECC      ((volatile UINT32P)(DummyNFI_Reg))
    #define NFI_SCON        ((volatile UINT16P)(DummyNFI_Reg))
    #define NFI_CSEL        ((volatile UINT16P)(DummyNFI_Reg))
    #define NFI_IOCON       ((volatile UINT16P)(DummyNFI_Reg))

    #else	// #if defined(__NFI_VERSION2__)
    #define NFI_ACCCON      ((volatile UINT16P)(DummyNFI_Reg))
    #define NFI_PAGEFMT     ((volatile UINT16P)(DummyNFI_Reg))
    #define NFI_OPCON       ((volatile UINT16P)(DummyNFI_Reg))
    #define NFI_CMD         ((volatile UINT16P)(DummyNFI_Reg))
    #define NFI_ADDNOB      ((volatile UINT16P)(DummyNFI_Reg))
    #define NFI_ADDRL       ((volatile UINT32P)(DummyNFI_Reg))
    #define NFI_ADDRM       ((volatile UINT16P)(DummyNFI_Reg))
    #define NFI_DATAW       ((volatile UINT32P)(DummyNFI_Reg))
    #define NFI_DATAWB      ((volatile UINT16P)(DummyNFI_Reg))
    #define NFI_DATAR       ((volatile UINT32P)(DummyNFI_Reg))
    #define NFI_DATARB		((volatile UINT16P)(DummyNFI_Reg))
    #define NFI_PSTA        ((volatile UINT16P)(DummyNFI_Reg))
    #define NFI_FIFOCON     ((volatile UINT16P)(DummyNFI_Reg))
    #define NFI_CON         ((volatile UINT16P)(DummyNFI_Reg))
    #define NFI_INTR        ((volatile UINT16P)(DummyNFI_Reg))
    #define NFI_INTR_EN     ((volatile UINT16P)(DummyNFI_Reg))
    #define NFI_PAGECNTR		((volatile UINT16P)(DummyNFI_Reg))
    #define NFI_ADDRCNTR		((volatile UINT16P)(DummyNFI_Reg))
    #define NFI_SYM0_ADDR   ((volatile UINT16P)(DummyNFI_Reg))
    #define NFI_SYM1_ADDR   ((volatile UINT16P)(DummyNFI_Reg))
    #define NFI_SYM2_ADDR   ((volatile UINT16P)(DummyNFI_Reg))
    #define NFI_SYM3_ADDR   ((volatile UINT16P)(DummyNFI_Reg))
    #define NFI_SYM0_DAT    ((volatile UINT32P)(DummyNFI_Reg))
    #define NFI_SYM1_DAT    ((volatile UINT32P)(DummyNFI_Reg))
    #define NFI_SYM2_DAT    ((volatile UINT32P)(DummyNFI_Reg))
    #define NFI_SYM3_DAT    ((volatile UINT32P)(DummyNFI_Reg))
    #define NFI_ERRDET      ((volatile UINT16P)(DummyNFI_Reg))
    #define NFI_PAR0        ((volatile UINT16P)(DummyNFI_Reg))
    #define NFI_PAR1        ((volatile UINT16P)(DummyNFI_Reg))
    #define NFI_PAR2        ((volatile UINT16P)(DummyNFI_Reg))
    #define NFI_PAR3        ((volatile UINT16P)(DummyNFI_Reg))
    #define NFI_PAR4        ((volatile UINT16P)(DummyNFI_Reg))
    #define NFI_PAR5        ((volatile UINT16P)(DummyNFI_Reg))
    #define NFI_PAR6        ((volatile UINT16P)(DummyNFI_Reg))
    #define NFI_PAR7        ((volatile UINT16P)(DummyNFI_Reg))
    #define NFI_CSEL			((volatile UINT16P)(DummyNFI_Reg))
    #endif /*__NFI_VERSION2__*/

#endif /*__MTK_TARGET__*/

/*******************************************************************************
 * NFI register definition
 *******************************************************************************/
/* NFI_ACCCON - example
	*NFI_ACCCON = ACCCON | (((NFI_W2R<<6)|(NFI_WH<<4)) | ((NFI_WST<<2)|NFI_RLC));

	*NFI_ACCCON = 0x07C6	// C2R=111, W2R=11, WH=00, WST=00, RLT=10

*/
#define ACCCON						0x0700	// C2R=111
#define NFI_W2R					3			// 0:2T, 1:4T, 2:6T, 3:8T ; recommanded value=3
#define NFI_WH						3			// 0:0T, 1:1T, 2:2T, 3:3T ; recommanded value=1
#define NFI_WST					3			// 0:0T, 1:1T, 2:2T, 3:3T ; recommanded value=1
#define NFI_RLC					3			// 0:0T, 1:1T, 2:2T, 3:3T ; recommanded value=2

/* NFI_PAGEFMT; support for PAGEFMT_PageSize_BusWidth */
#if defined(__NFI_VERSION3_1__)
// Set FDM_ECC_NUM to 8 and FDM_NUM to 8 by default.
#define PAGEFMT_512_8BIT   	0x0000
#define PAGEFMT_512_16BIT  	0x0008
#define PAGEFMT_2K_8BIT		0x0001
#define PAGEFMT_2K_16BIT	0x0009
#define PAGEFMT_4K_8BIT		0x0002
#define PAGEFMT_4K_16BIT	0x000A
#elif defined(__NFI_VERSION2__)
#define PAGEFMT_512_8BIT   	0x0010  /*Enable ECC block size = 256*/
#define PAGEFMT_512_16BIT  	0x0110  /*Enable ECC block size = 256*/
#define PAGEFMT_2K_8BIT		0x0015  /*Enable ECC block size = 256*/
#define PAGEFMT_2K_16BIT	0x0119  /*Enable ECC block size = 256*/
#else
#define PAGEFMT_512_8BIT   	0x0020
#define PAGEFMT_512_16BIT  	0x0120
#define PAGEFMT_2K_8BIT			0x0025
#define PAGEFMT_2K_16BIT		0x0125
#endif

#define	IO_ACCESS_8BIT			8
#define	IO_ACCESS_16BIT		16

#if defined(__NFI_VERSION3_1__)

#else 

/* NFI_OPCON */
#define BURST_RD           	0x0001
#define BURST_WR           	0x0002
#define ECC_RD_INIT        	0x0010
#define ECC_WR_INIT        	0x0020
#define SINGLE_RD          	0x0100
#define NOB_BYTE           	0x1000
#define NOB_WORD           	0x2000
#define NOB_DWORD          	0x0000
#if defined(__NFI_VERSION2__)
#define OPCON_RESET 0x0C00
#endif
#endif

/* Nand flash command */
#define RD_1ST_CMD         	0x00
#define RD_2ND_HALF_CMD     	0x01	// only for 512B page-size
#define RD_SPARE_CMD       	0x50	// only for 512B page-size
#define RD_2ND_CYCLE_CMD		0x30	// only for 2KB  page-size
#define INPUT_DATA_CMD     	0x80
#define PROG_DATA_CMD      	0x10
#define BLOCK_ERASE1_CMD   	0x60
#define BLOCK_ERASE2_CMD   	0xD0
#define RD_ID_CMD          	0x90
#define RD_STATUS_CMD      	0x70
#define RESET_CMD          	0xFF
#define CP_READ_CMD        	0x35
#define CP_INPUT_CMD_2K    	0x85
#define CP_INPUT_CMD_512   	0x8A
#define CP_PROG_CMD_TOSHIBA	0x15

/* NFI_PSTA */
#define STATUS_CMD         	0x1
#define STATUS_ADDR        	0x2
#define STATUS_DATAR       	0x4
#define STATUS_DATAW       	0x8
#define STATUS_BUSY        	0x100

/* NFI_FIFOCON */
#if defined(__NFI_VERSION3_1__)
// Nothing here.
#elif defined(__NFI_VERSION2__)

#define RD_EMPTY_MASK  0x40
#define RD_FULL_MASK     0x80
#define WR_EMPTY_MASK 	0x4000
#define WR_FULL_MASK    0x8000
#if defined(FLASH_DISKDRV_DEBUG) && !defined(__MTK_TARGET__)
    #define FIFO_RD_REMAIN(x) (16) /*simulate the fifo is full in read*/
    #define FIFO_WR_REMAIN(x) (0)  /*simulate the fifo is empty in write*/
#else
    #define FIFO_RD_REMAIN(x) (0x1F&(x))
    #define FIFO_WR_REMAIN(x) ((0x1F00&(x))>>8)
#endif

#else

#define RD_EMPTY_MASK      	0x001
#define RD_FULL_MASK       	0x002
#define WR_EMPTY_MASK      	0x004
#define WR_FULL_MASK      		0x008
#define FIFO_FLUSH         	0x010
#define RESET              	0x020

#endif



/* NFI_CON */
#if defined(__NFI_VERSION3_1__)
#define BYTE_RW_EN				0x0040
#else
#define BYTE_RW_EN				0x8000
#endif
#define READ_CON_EN				0x0400
#define PROGRAM_CON_EN			0X0200
#define ERASE_CON_EN				0X0100
#define SW_PROGSPARE_EN    	0x0020
#define MULTI_PAGE_RD_EN   	0x0010
#define AUTOECC_ENC_EN     	0x0008
#define AUTOECC_DEC_EN     	0x0004
#define DMA_WR_EN          	0x0002
#define DMA_RD_EN          	0x0001

#if defined(__NFI_VERSION2__)
#define MAIN_ECC_EN      0x200
#define SPARE_ECC_EN     0x100
#define AUTO_ECC_ENC    0x8
#define AUTO_ECC_DEC    0x4
#define ECC_FALSE      0x0
#endif 

/* NFI_ERRDET */
#if defined(__NFI_VERSION3_1__)
// Nothing here.
#elif defined(__NFI_VERSION2__)
/*uncorrectable error*/
#define ERRDET_EBLK0    0x00000001
#define ERRDET_EBLK1    0x00000002
#define ERRDET_EBLK2    0x00000004
#define ERRDET_EBLK3    0x00000008
#define ERRDET_EBLK4    0x00000010
#define ERRDET_EBLK5    0x00000020
#define ERRDET_EBLK6    0x00000040
#define ERRDET_EBLK7    0x00000080
#define ERRDET_ESBLK0   0x00000100
#define ERRDET_ESBLK1   0x00000200
#define ERRDET_ESBLK2   0x00000400
#define ERRDET_ESBLK3   0x00000800
#define ERRDET_E_ALL    0x00000FFF
/*correctable error*/
#define ERRDET_PEBLK0   0x00010000
#define ERRDET_PEBLK1   0x00020000
#define ERRDET_PEBLK2   0x00040000
#define ERRDET_PEBLK3   0x00080000
#define ERRDET_PEBLK4   0x00100000
#define ERRDET_PEBLK5   0x00200000
#define ERRDET_PEBLK6   0x00400000
#define ERRDET_PEBLK7   0x00800000
#define ERRDET_PESBLK0  0x01000000
#define ERRDET_PESBLK1  0x02000000
#define ERRDET_PESBLK2  0x04000000
#define ERRDET_PESBLK3  0x08000000
#define ERRDET_PE_ALL   0x0FFF0000
#endif 

/* Status register */
#define RDY_BUSY           	0x40
#define INTERNAL_BUSY      	0x20
#define PASS_FAIL          	0x01


#define IS_NFI_DMA_RUN 	 *(volatile kal_uint32 *)DMA_GLBSTA & (kal_uint32)DMA_GLBSTA_RUN(nfi_dmaport)

/* NFI_INTR_EN */

/* NFI_INTR */
#if defined(__NFI_VERSION3_1__)
#define RD_COMPLETE_EN		(0x0001)
#define WR_COMPLETE_EN		(0x0002)
#define RESET_COMPLETE_EN	(0x0004)
#define ERASE_COMPLETE_EN	(0x0008)
#define BUSY_RETURN_EN		(0x0010)
#define ACC_LOCK_EN			(0x0020)
#define AHB_DONE_EN			(0x0040)
#define ALL_EN             	(0x007F)
#elif defined(__NFI_VERSION2__)
#define RD_COMPLETE_EN     0x1000
#define WR_COMPLETE_EN     0x2000
#define RESET_COMPLETE_EN  0x4000
#define ERASE_COMPLETE_EN  0x8000
#define BUSY_RETURN_EN     0x10000000
#define ALL_EN         0x1000f000
#else
#define RD_COMPLETE_EN     	0x01
#define WR_COMPLETE_EN     	0x02
#define RESET_COMPLETE_EN  	0x04
#define ERASE_COMPLETE_EN  	0x08
#define ERR_DET_EN         	0x10
#define ERR_COR_EN         	0x20
#define BUSY_RETURN_EN     	0x40
#define ALL_EN             	0x7F
#endif

/* NFI_INTR */
#if defined(__NFI_VERSION3_1__)
#define RD_COMPLETE			(0x0001)
#define WR_COMPLETE			(0x0002)
#define RESET_COMPLETE		(0x0004)
#define ERASE_COMPLETE		(0x0008)
#define BUSY_RETURN			(0x0010)
#define ACC_LOCK		    (0x0020)
#define AHB_DONE			(0x0040)
#elif defined(__NFI_VERSION2__)
#define RD_COMPLETE        0x1000
#define WR_COMPLETE       0x2000
#define RESET_COMPLETE   0x4000
#define ERASE_COMPLETE  0x8000
#define BUSY_RETURN        0x10000000
#else
#define RD_COMPLETE        0x0001
#define WR_COMPLETE        0x0002
#define RESET_COMPLETE     0x0004
#define ERASE_COMPLETE     0x0008
#define ERR_DET0           0x0010
#define ERR_DET1           0x0020
#define ERR_DET2           0x0040
#define ERR_DET3           0x0080
#define ERR_COR0           0x0100
#define ERR_COR1           0x0200
#define ERR_COR2           0x0400
#define ERR_COR3           0x0800
#define BUSY_RETURN        0x1000
#endif /*__NFI_VERSION2__*/


/*******************************************************************************
 * NAND MTD declaration
 *******************************************************************************/
 // NAND flash maker ID
#define TOSHIBA		0x98
#define SAMSUNG		0xEC
#define HYNIX		0xAD
#define ST			0x20
#define MICRON		0x2C
#define	INTEL		0x89
#define SPANSION	0x01
#define POWERFLASH	0x92
#define ESMT        0xC8

typedef struct NAND_ID_tag
{
    kal_uint32 mID:8;            /*[Byte1]*/
    kal_uint32 dID:8;            /*[Byte2]*/
    kal_uint32 dieNum:2;         /*[Byte3] number of Die (per CE) = (1<<value)*/
    kal_uint32 cellType:2;       /*[Byte3] Cell Type = (2<<value) Level cell, value >= 1 is MLC*/
    kal_uint32 simultNum:2;      /*[Byte3] Number of Simutaneously Programmed Page = (1<<value), for each die*/
    kal_uint32 dieInterleave:1;  /*[Byte3] die Interleave support Flag: 1 support; 0 Not Support*/
    kal_uint32 cacheProgram:1;   /*[Byte3] cache Program support Flag: 1 support; 0 Not Support*/
    kal_uint32 pageSize:2;       /*[Byte4] page Size = (1024<<value)*/
    kal_uint32 spareSize:1;      /*[Byte4] spare Size per 512 = (8<<value) */
    kal_uint32 accessTime0:1;    /*[Byte4]*/
    kal_uint32 blockSize:2;      /*[Byte4] block Size = (64k<<value)*/
    kal_uint32 IOWidth:1;        /*[Byte4] IOWidth = (8<<value)*/
    kal_uint32 accessTime1:1;    /*[Byte4]*/
    kal_uint32 byte5Rev0:1;      /*[Byte5]*/
    kal_uint32 ToshibaExt:1;     /*[Byte5] [Toshiba] Extended block flag*/
    kal_uint32 planeNum:2;       /*[Byte5] number of plane (per CE) = (1<<value) (Toshiba does not suuport)*/
    kal_uint32 planeSize:3;      /*[Byte5] plane Size= (64Mb<<value) (Toshiba does not suuport)*/
    kal_uint32 byte5Rev1:1;      /*[Byte5]*/
    kal_uint32 Reserve:24;       /*[Byte6~8]*/
}nAND_ID;


typedef struct
{
    kal_uint8  cmd[2];
    kal_uint8  cmd_len;
    kal_uint32 add[2]; /*Max 8 x uint8 address cycle*/
    kal_uint8  add_cycle;
    kal_uint8  *buff;
    kal_uint32 buff_len;
    kal_uint8  *spare;
    kal_uint32 spare_len;
    kal_uint32 intFlag;
    kal_uint8  ECCFlag;
#if defined(__NFI_VERSION3_1__)
    kal_uint8  CustomMode;
#endif // defined(__NFI_VERSION3_1__)
}nAND_Cmd_info;


typedef struct mtd_lock_tag {
   kal_uint32  lock_count;
   kal_taskid  owner_id;
   kal_enhmutexid mtd_enhmutex;
} NAND_MTD_LOCK;

#if defined(__AUDIO_DSP_LOWPOWER__)
typedef struct {
   kal_uint32    nfi_ACCCON_reg;        // NFI R/W access timing  (MAX: 0xFFFFFFFF)
   kal_uint32    nfi_page_size;         // PAGE_512. PAGE_2K   (MAX: 4096)
   kal_uint32    nfi_spare_size;        //  SPARE_SIZE ==> 16 bytes (MAX:16)
   kal_uint32    nfi_pages_per_block;   // PAGE_512 ==> 32, PAGE2K ==> 64  (MAX : 128)
   kal_uint32    nfi_fdm_size;          // ECC protection area  of fdm data in NAND is defined by nfi_fdm_size  //(MAX:8)
   kal_uint32    nfi_sector_num;        // PAGE2K=4, PAGE512=1 (MAX:8)
   kal_uint32    nfi_data_sectors;      // Define sectors number for read at each transaction. (MAX:8)
   kal_uint32    nfi_col_num;           // parameter for nand  (MAX:2)
   kal_uint32    nfi_row_num;           // parameter for nand (MAX:4)
   kal_uint32    nfi_io_width;          // BUS width: 8bits / 16 bits nand device (MAX:1)
} NFI_Config_for_MP3_st;
#endif // #if defined(__AUDIO_DSP_LOWPOWER__)

// define NFI CS0/1 DIR, DOUT, CON
#if ( (defined(MT6218B)) )
#define NFI_CS_DIR		((volatile UINT16P)(GPIO_base+0x0010))		// GPIO 30 as NFI CS0
#define NFI_CS_DOUT		((volatile UINT16P)(GPIO_base+0x00A0))
#elif ( (defined(MT6219)) )
#define NFI_CS_DIR		((volatile UINT16P)(GPIO_base+0x0010))		// GPIO 30 as NFI CS0
#define NFI_CS_DOUT		((volatile UINT16P)(GPIO_base+0x00D0))
#endif



#if ( (defined(MT6218B)) || (defined(MT6219)))
#define INITIALIZE_NFI_DIR_DOUT \
{\
	*NFI_CS_DIR |= 0x4100;\
	*NFI_CS_DOUT |= 0x4100;\
}

// set GPIO 30 as NFI CS0
#define SET_NFI_CS0 \


// set GPIO 30 as GPIO and GPIO 24 DOUT=0
#define SET_NFI_CS1 \
{\
	*NFI_GPIO_CON &= 0xCFFF;\
	*NFI_CS_DOUT &= 0xFEFF;\
}

// set GPIO 24 DOUT=1
#define SET_NFI_CS1_END \
{\
   *NFI_GPIO_CON |= 0x1000;\
	*NFI_CS_DOUT |= 0x0100;\
}
#elif (defined(MT6225))
#define INITIALIZE_NFI_DIR_DOUT

/* GPIO42 as CS0 */
#define SET_NFI_CS0 \
{\
	*NFI_GPIO_CON2 |= 0x10;\
	*NFI_CSEL = 0;\
}

/* GPIO34 as CS1 */
#define SET_NFI_CS1 \
{\
	*NFI_GPIO_CON1 |= 0x20;\
	*NFI_CSEL = 1;\
}

#define SET_NFI_CS0_END \
{\
	*NFI_GPIO_CON2 &= 0xFFEF;\
}

#define SET_NFI_CS1_END \
{\
	*NFI_GPIO_CON1 &= 0xFFDF;\
}

#elif (defined(__NFI_VERSION2__) || defined(__NFI_VERSION3_1__))  && defined(__MTK_TARGET__)

#define INITIALIZE_NFI_DIR_DOUT

#define SET_NFI_CS0 \
	*NFI_CSEL = 0;

#define SET_NFI_CS1 \
	*NFI_CSEL = 1;

#define SET_NFI_CS1_END

#elif defined(FLASH_DISKDRV_DEBUG) && !defined(__MTK_TARGET__)

#define INITIALIZE_NFI_DIR_DOUT

#define SET_NFI_CS0 \
	cur_CS = 0;

#define SET_NFI_CS1 \
	cur_CS = 1;

#define SET_NFI_CS1_END

#else		// MT6217 , MT6226, MT6226M, MT6227, MT6228, MT6229
#define INITIALIZE_NFI_DIR_DOUT

#define SET_NFI_CS0 \
	*NFI_CSEL = 0;

#define SET_NFI_CS1 \
	*NFI_CSEL = 1;

#define SET_NFI_CS1_END

#endif



/*******************************************************************************
 * structure definition for flash supply list and MTD
 *******************************************************************************/

typedef struct
{
    kal_uint32* page_p;
    kal_uint8  *buff;
    kal_uint8  *spare;
    kal_uint16 pageOffset; /*Pnysical PageIndex = (*page_p)+pageOffset*/
    kal_uint8  addCycle;
    kal_uint8  opFlag;
}mtd_drv_para;
/*For mtd_drv_para.opFlag*/
#define FIRST_PROCESS           0x01
#define SECOND_BUSY             0x02
#define FULL_OPERATION          (FIRST_PROCESS|SECOND_BUSY)
#define ONE_SPARE				0x04
#define PROGRAM_CACHED           0x10
#define PROGRAM_FINAL            0x20
#define SAMSUNG_D0_ILEAVE_OP     0x40 /*samsung die 0 interleave operation*/
#define SAMSUNG_D1_ILEAVE_OP     0x80 /*samsung die 1 interleave operation*/
typedef struct multiPage_operation_tag
{
    kal_uint32 (*func_p) (mtd_drv_para* Para);          /**/
    kal_uint8 startAlign;       /*start page alignment limitation*/
    kal_uint8 multiPageNum;    /*the max page numner func_p can access. 0xFF means continue to end of block*/
}mPage_operation;

#define MAX_MULTIPAGE_FUNCTION_NUM 6
#define MAX_MULTIPAGE_NUM 8 /*max MULTI-PAGE num (CE0+CE1)*//*It should <= 16 due to MTD return value */

typedef struct
{
    kal_uint8  *buff;
    kal_uint8  *spare;
    kal_uint32 pageIdx[MAX_MULTIPAGE_NUM];
    kal_uint16 length;
    kal_uint8  ce;
    kal_uint8  m_idx;  /*index of Flash_Info.multiProgram*/
    kal_uint8  opFlag;
}mtd_if_para;


typedef struct
{
	kal_uint32     (* ProgramPage)                   (mtd_drv_para* Para);
	kal_uint32     (* ReadPage)                      (mtd_drv_para* Para);
	kal_uint32     (* CopyPage)                      (mtd_drv_para* Para);
	kal_uint32     (* EraseBlock)                    (mtd_drv_para* Para);
/*Multi Page Program functions*/
	kal_uint32     (* TwoPlaneProgram)               (mtd_drv_para* Para);/*multiple 2*/
	kal_uint32     (* TwoDieProgram)                 (mtd_drv_para* Para);/*multiple 2*/
	kal_uint32     (* FourPlaneProgram)              (mtd_drv_para* Para);/*multiple 4*/
	kal_uint32     (* TwoDieTwoPlaneProgram)         (mtd_drv_para* Para);/*multiple 4*/
	kal_uint32     (* CacheProgram)                  (mtd_drv_para* Para);
	kal_uint32     (* TwoPlaneCacheProgram)          (mtd_drv_para* Para);
	kal_uint32     (* TwoDieCacheProgram)            (mtd_drv_para* Para);
	kal_uint32     (* FourPlaneCacheProgram)         (mtd_drv_para* Para);
	kal_uint32     (* TwoDieTwoPlaneCacheProgram)    (mtd_drv_para* Para);
/*Multi Block Erase functions*/
	kal_uint32     (* TwoPlaneErase)               (mtd_drv_para* Para);/*multiple 2*/
	kal_uint32     (* TwoDieErase)                 (mtd_drv_para* Para);/*multiple 2*/
	kal_uint32     (* FourPlaneErase)              (mtd_drv_para* Para);/*multiple 4*/
	kal_uint32     (* TwoDieTwoPlaneErase)         (mtd_drv_para* Para);/*multiple 4*/
/* OTP related function */
	kal_int32  	   (* OTPAccess)                   (kal_int32 accesstype, kal_uint32 PageAddr, void *BufferPtr, void *SparePtr);
	kal_int32      (* OTPQueryLength)              (kal_uint32 *Length);
} NAND_MTD_SUB_DRIVER;

typedef struct
{
    nand_Name               DevName_enum;        /*Device name*/
    kal_uint8               ID_info[8];    /*equal sizeof(nAND_ID)*/
    kal_uint8               ID_valid_mask[8];  /*valid-bit mask of ID_info*/
    kal_uint8               IOWidth;
    kal_uint8               address_cycle; /*row add cycle + column add cycle*/
    kal_uint8               planeNum;      /*number of plane per die, min 1*/
    kal_uint8               dieNum;        /*number of die per device(CE), min 1*/
    kal_uint16              pageSize;
    kal_uint16              spareSize;
    kal_uint16              blockPage;
    kal_uint16              deviceSize;    /*unit by MByte (so max < 64GB), exclude the extended block size*/
    kal_uint16              supportMPType; /*Supported Multi-page program type*//*supportOpType*/
    kal_uint16              supportMEType; /*Supported Multi-Block Erase type*//*supportOpType*/
    kal_uint16              CopyBackType;  /*Type of Copyback*/
    NAND_MTD_SUB_DRIVER*        driverSet;     /*driverSet + supportOpType = supported driver*/
}flash_list /*device_info*/;
/*device feature/operation support (for flash_list.supportOpType)*/
#define SIMPLE_OP               (0x0000)
/*Do not use (0x0001), it use by AUTO_NAND_DETECT (0x0011)*/
#define TWO_PLANE_OP            (0x0002)
#define FOUR_PLANE_OP           (0x0004)
#define TWO_DIE_INTERLEAVE_OP   (0x0008)
/*Do not use (0x0010), it use by AUTO_NAND_DETECT (0x0011)*/
#define CACHE_PROGRAM           (0x0020)
#define EXTENDED_BLOCK          (0x0040)
#define PLANE_INTERLACED        (0x0080) /*block number is interlaced between plane*/
#define PLANE_CONTINUOUS        (0x0100) /*block number is continuous in plane*/

#define AUTO_NAND_DETECT        (0x0011) /*auto-detection definition of all excepte (supportMPType and supportMEType)*/


/* indicate if write ECC fields while program page */
enum
{
    ECC_SKIP = 0,            // don't program spare area
    ECC_FIRST_HALF,      // only program first and second ECC fields
    ECC_SECOND_HALF,     // only program third and fourth ECC fields
    ECC_WHOLE            // program whole ECC fields
};
/*******************************************************************************
 *  Macro definition
 *******************************************************************************/
#if !defined(__NFI_VERSION3_1__)

#if defined(MCU_13M)
/* 1T ~= 77 ns */
#define COUNTER_200nS	(3)

#elif defined(MCU_26M)
/* 1T ~= 38 ns */
#define COUNTER_200nS 	(6)

#elif defined(MCU_52M)
/* 1T ~= 19 ns */
#define COUNTER_200nS 	(11)

#elif defined(MCU_78M)
/* 1T ~= 12.8 ns */
#define COUNTER_200nS 	(16)

#elif defined(MCU_104M)
/* 1T ~= 9.6 ns */
#define COUNTER_200nS 	(21)

#elif defined(MCU_122_88M)
/* 1T ~= 8.13 ns */
#define COUNTER_200nS 	(25)

#elif defined(MCU_208M)
/* 1T ~= 4.8 ns */
#define COUNTER_200nS   (42)

#elif defined(MCU_245_76M)
/* 1T ~= 4 ns */
#define COUNTER_200nS   (50)

#elif defined(MCU_260M)
/* 1T ~= 3.8 ns */
#define COUNTER_200nS   (52)

#elif defined(MCU_312M)
/* 1T ~= 3.2 ns */

#define COUNTER_200nS   (63)

#elif defined(MCU_368_64M)
/* 1T ~= 2.7 ns */
#define COUNTER_200nS   (75)

#elif (defined(MCU_491_52M) || defined(MCU_492M) || defined(MCU_480M))
/* 1T ~= 2.0 ns */
#define COUNTER_200nS   (100)

#else
#error "Unsupported MCU clock rate for busy wait loop!"

#endif

#endif // !defined(__NFI_VERSION3_1__)

/*******************************************************************************
 *  MTD function declaration
 *******************************************************************************/
//kal_int32 MTD_MountDevice	(void * DriveData);
kal_int32 MTD_MountDevice( void);
kal_uint32 MTD_CE_Interleave_Program (mtd_if_para* Para);
kal_uint32 MTD_CE_Interleave_CacheProgram (mtd_if_para* Para);
kal_uint32 MTD_Program (mtd_if_para* Para);
kal_uint32 MTD_CacheProgram (mtd_if_para* Para);
kal_uint32 MTD_Read(mtd_if_para* Para);
kal_uint32 MTD_Erase(mtd_if_para* Para);
kal_uint32 MTD_MarkBlockBad (mtd_if_para* Para);
kal_uint32 MTD_CheckBlockBad (mtd_if_para* Para);
kal_uint32 MTD_NAND_Reset(mtd_if_para* Para);
kal_int32 MTD_ShutDown	(void);

#if defined(FLASH_DISKDRV_DEBUG) && !defined(__MTK_TARGET__)
void MTD_Simu_Create_Device_File (void);
void MTD_Simu_SetUserDefID(kal_uint32 cs0_ID_0_3,kal_uint32 cs0_ID_4_7,kal_uint32 cs1_ID_0_3,kal_uint32 cs1_ID_4_7);
void MTD_Simu_SetIDData(kal_uint32* id_data,kal_uint8 cs);
#if defined DAL_DLL_VERSION
void MTD_WriteErrMsg(char* title, char* exp, char* f, kal_uint32 line, kal_uint32 e1, kal_uint32 e2, kal_uint32 e3);
#endif

#endif
//kal_int32 MTD_EraseBlock	(void * DriveData, kal_uint32 BlockIndex);
/*******************************************************************************
 *  Sub-function declaration
 *******************************************************************************/
kal_uint32 single_Page_Program (mtd_drv_para *para);
kal_uint32 single_Page_CacheProgram (mtd_drv_para *para);
kal_uint32 single_Page_Read (mtd_drv_para *para);
kal_uint32 single_Block_Erase (mtd_drv_para *para);
kal_uint32 toshiba_twoPlane_Program (mtd_drv_para *para);
kal_uint32 toshiba_twoPlane_Erase (mtd_drv_para *para);
kal_uint32 toshiba_fourPlane_Program (mtd_drv_para *para);
kal_uint32 toshiba_fourPlane_Erase (mtd_drv_para *para);
kal_uint32 toshiba_twoPlane_CacheProgram (mtd_drv_para *para);
kal_uint32 toshiba_fourPlane_CacheProgram (mtd_drv_para *para);
kal_uint32 samsung_twoPlane_Program (mtd_drv_para *para);
kal_uint32 samsung_twoPlane_Erase (mtd_drv_para *para);
kal_uint32 samsung_twoDie_Program (mtd_drv_para *para);
kal_uint32 samsung_twoDie_Erase (mtd_drv_para *para);
kal_uint32 samsung_twoDie_twoPlane_Program (mtd_drv_para *para);
kal_uint32 samsung_twoDie_twoPlane_Erase (mtd_drv_para *para);
kal_int32  samsung_OTPAccess(kal_int32 accesstype, kal_uint32 PageAddr, void *BufferPtr, void *SparePtr);
kal_int32  samsung_OTPQueryLength(kal_uint32 *Length);
kal_int32  hynix_OTPAccess(kal_int32 accesstype, kal_uint32 PageAddr, void *BufferPtr, void *SparePtr);
kal_int32  hynix_OTPQueryLength(kal_uint32 *Length);
kal_int32  ESMT_OTPAccess(kal_int32 accesstype, kal_uint32 PageAddr, void *BufferPtr, void *SparePtr);
kal_int32  ESMT_OTPQueryLength(kal_uint32 *Length);
kal_int32  micron_OTPAccess(kal_int32 accesstype, kal_uint32 PageAddr, void *BufferPtr, void *SparePtr);
kal_int32  micron_OTPQueryLength(kal_uint32 *Length);
kal_int32  NAND_OTPAccess(kal_int32 accesstype, kal_uint32 PageAddr, void *BufferPtr, void *SparePtr);
kal_int32  NAND_OTPQueryLength(kal_uint32 *Length);
kal_uint32 micron_twoPlane_Program (mtd_drv_para *para);
kal_uint32 micron_twoPlane_Erase (mtd_drv_para *para);
kal_uint32 micron_twoPlane_CacheProgram (mtd_drv_para *para);
kal_uint32 micron_twoDie_Program (mtd_drv_para *para);
kal_uint32 micron_twoDie_Erase (mtd_drv_para *para);
kal_uint32 micron_twoDie_twoPlane_Program (mtd_drv_para *para);
kal_uint32 micron_twoDie_twoPlane_Erase (mtd_drv_para *para);
kal_uint32 micron_twoDie_CacheProgram (mtd_drv_para *para);
kal_uint32 micron_twoDie_twoPlane_CacheProgram (mtd_drv_para *para);

kal_uint32 FlashCheckID(const flash_list *ID_table);

kal_uint8 read_status(kal_uint8 cmd1, nAND_Cmd_info* info );
kal_int32 InitializeMTD(void * DriveData);
void nfi_lisr(void);
void nfi_hisr(void);
void NFI_DMA_Callback(void);
void pdn_nfi(kal_bool ON);
void NAND_GPIO_InitIO(char direction, char port);
char NAND_GPIO_ReturnMode(char port);
char NAND_GPIO_ReadIO(char port);
void NAND_GPIO_WriteIO(char data, char port);
kal_bool NAND_INT_USBBoot(void);

/******************************************************************************
 * SuperAND flash device definition                                           *
 ******************************************************************************/
#define SUPERAND_PAGE_READ_CMD  0x00    /* Can be recognized by NFI */
#define SUPERAND_SEQ_READ_CMD   0x0F    /* Can't be recognized by NFI */
#define SUPERAND_READ_END_CMD   0xF0    /* Can't be recognized by NFI */
#define SUPERAND_REWRITE_CMD    0x1F    /* Can't be recognized by NFI */
#define SUPERAND_PROG_CMD       0x10    /* Can be recognized by NFI */

#define SUPERAND_ADDR_CYCLE     0x04
#define SUPERAND_BYTES_PER_SECTOR   (SUPERAND_PAGES_PER_SECTOR << 9)
#define SUPERAND_PAGES_PER_SECTOR   0x04
#define SUPERAND_SECTOR_MASK    (SUPERAND_PAGES_PER_SECTOR - 1)
#define SUPERAND_PAGES_PER_EXT_SECTOR   0x08
#define SUPERAND_EXT_SSECTOR_MASK    (SUPERAND_PAGES_PER_EXT_SECTOR - 1)


#define SUPERAND_PAGEFMT_8BIT   0x0005
#define SUPERAND_PAGEFMT_16BIT  0x0105

#define SUPERAND_ACCCON         0x07FF

#define PAGES2BYTES(pages)      ((pages) << 9)
#define PAGES2DWORDS(pages)     ((pages) << 7)

#define MAX_DEVICE_NUM          2

typedef struct
{
   kal_uint16     id;
   kal_uint16     plane_size;      // in MBytes
   kal_uint16     block_size;      // in KBytes
   kal_uint8      io_width;        // 8 or 16 bits
}  superand_flash_list;
#define SUPERAND_FLASH_LIST_END {0xFFFF, 0, 0, 0}

typedef struct
{
	kal_int32     (* MountDevice)    (void * DriveData);
	kal_int32     (* ShutDown)       (void * DriveData);
	kal_int32     (* ReadPages)      (void * DriveData, kal_uint32 PageIndex, kal_uint32 Pages, kal_uint8 * Data);
	kal_int32     (* RewritePages)   (void * DriveData, kal_uint32 PageIndex, kal_uint32 Pages, kal_uint8 * Data);
	kal_int32     (* ProgramData)    (void * DriveData, kal_uint32 PageIndex, kal_uint32 Bytes, kal_uint8 * Data);
	kal_int32     (* EraseBlock)     (void * DriveData, kal_uint32 PageIndex);
	kal_int32     (* ReadGoodBlkCnt) (void * DriveData);
} SuperAND_MTD_DRIVER;

#if (defined(MT6218B) || defined(MT6219))
#define COMPUTE_ADDRESS_AND_SET_CSEL \
{\
    kal_uint32 page_idx = PageIndex;\
    kal_uint16 *paddr = (kal_uint16*)&addr;\
    paddr[0] = (D->io_width == 8) ? (kal_uint16)((page_idx&0x3) << 9) : (kal_uint16)((page_idx&0x3) << 8);\
    paddr[1] = page_idx >> 2;\
}
#else
#define COMPUTE_ADDRESS_AND_SET_CSEL \
{\
    kal_uint32 page_idx = PageIndex;\
    kal_uint16 *paddr = (kal_uint16*)&addr;\
    if(page_idx >= D->pages_of_first_device)\
    {\
        *NFI_CSEL = 0x1;\
        page_idx -= D->pages_of_first_device;\
    }else{\
        *NFI_CSEL = 0x0;\
    }\
    paddr[0] = (D->io_width == 8) ? (kal_uint16)((page_idx&0x3) << 9) : (kal_uint16)((page_idx&0x3) << 8);\
    paddr[1] = page_idx >> 2;\
}
#endif

void SuperAND_MTD_Init(void);
kal_int32 SuperAND_MTD_MountDevice(void * DriveData);
kal_int32 SuperAND_MTD_ShutDown(void * DriveData);
kal_int32 SuperAND_MTD_ReadPages(void * DriveData, kal_uint32 PageIndex, kal_uint32 Pages, kal_uint8 * Data);
kal_int32 SuperAND_MTD_RewritePages(void * DriveData, kal_uint32 PageIndex, kal_uint32 Pages, kal_uint8 * Data);
kal_int32 SuperAND_MTD_ProgramData(void * DriveData, kal_uint32 PageIndex, kal_uint32 Bytes, kal_uint8 * Data);
kal_int32 SuperAND_MTD_EraseBlock(void * DriveData, kal_uint32 PageIndex);
kal_int32 SuperAND_MTD_ReadGoodBlkCnt(void * DriveData);

kal_uint16 superand_read_device_id(kal_uint16 csel);
kal_bool superand_checkdevice(void * DriveData);
kal_int32 superand_writefifo(void * DriveData, kal_uint32 PageIndex, kal_uint8 * Data, kal_uint32 Bytes, kal_bool rewrite);
void superand_readfifo(kal_uint8 * Data, kal_uint32 Pages);
kal_uint8 superand_read_status(void);


extern kal_uint32 custom_part_secs;

extern NAND_MTD_SUB_DRIVER SAMSUNG_SINGLE_CACHE_SUB_DRIVER;
extern NAND_MTD_SUB_DRIVER SAMSUNG_SUB_DRIVER;
extern NAND_MTD_SUB_DRIVER HYNIX_ST_SUB_DRIVER;
extern NAND_MTD_SUB_DRIVER TOSHIBA_SUB_DRIVER;
extern NAND_MTD_SUB_DRIVER MICRON_SUB_DRIVER;

#endif //NAND_MTD_FDM50_INTERNAL_H


