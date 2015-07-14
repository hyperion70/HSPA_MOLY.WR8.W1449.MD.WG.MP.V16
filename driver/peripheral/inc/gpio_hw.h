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
 *    gpio_hw.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file is intended for GPIO driver.
 *
 * Author:
 * -------
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _GPIO_HW_H
#define _GPIO_HW_H
   
#include "drv_features_gpio.h"
#include "reg_base.h"

#if !defined(DRV_GPIO_OFF)
#if defined(DRV_GPIO_REG_AS_6280)

#define  GPIO_DIR1			(GPIO_base+0x0000)
#define  GPIO_DIR2			(GPIO_base+0x0040)
#define  GPIO_DIR3		   (GPIO_base+0x0080)
#define  GPIO_DIR4		   (GPIO_base+0x00c0)
#define  GPIO_DIR5		   (GPIO_base+0x0100) 
#define  GPIO_DIR6		   (GPIO_base+0x0140)  
#define  GPIO_DIR7		   (GPIO_base+0x0180) 

/*********************************************************/

#define    GPIO_PULLEN1		 (GPIO_base+0x0200)
#define    GPIO_PULLEN2		 (GPIO_base+0x0240)
#define    GPIO_PULLEN3	  (GPIO_base+0x0280)
#define    GPIO_PULLEN4		(GPIO_base+0x02c0)
#define    GPIO_PULLEN5		(GPIO_base+0x0300)	
#define 	GPIO_PULLEN6      (GPIO_base+0x0340) 
#define    GPIO_PULLEN7 	 (GPIO_base+0x0380)

/*********************************************************/

#define  GPIO_PULLSEL1		 (GPIO_base+0x0400)
#define  GPIO_PULLSEL2		 (GPIO_base+0x0440)
#define  GPIO_PULLSEL3		 (GPIO_base+0x0480)
#define  GPIO_PULLSEL4	   (GPIO_base+0x04c0)
#define  GPIO_PULLSEL5	   (GPIO_base+0x0500) 
#define  GPIO_PULLSEL6     (GPIO_base+0x0540) 
#define  GPIO_PULLSEL7	   (GPIO_base+0x0580)

/*********************************************************/
#define  GPIO_DINV1 		 (GPIO_base+0x0600)
#define  GPIO_DINV2 		 (GPIO_base+0x0640)
#define  GPIO_DINV3 		 (GPIO_base+0x0680)
#define  GPIO_DINV4 		 (GPIO_base+0x06c0)
#define  GPIO_DINV5 		 (GPIO_base+0x0700) 
#define  GPIO_DINV6		   (GPIO_base+0x0740)
#define  GPIO_DINV7		  (GPIO_base+0x0780) 
/*********************************************************/
#define  GPIO_DOUT1 		 (GPIO_base+0x0800)
#define  GPIO_DOUT2 		 (GPIO_base+0x0840)
#define  GPIO_DOUT3 		 (GPIO_base+0x0880)
#define  GPIO_DOUT4 		 (GPIO_base+0x08c0)
#define  GPIO_DOUT5 		 (GPIO_base+0x0900)
#define   GPIO_DOUT6		  (GPIO_base+0x0940)  
#define   GPIO_DOUT7      	(GPIO_base+0x0980) 
/*********************************************************/
#define  GPIO_DIN1			 (GPIO_base+0x0a00)
#define  GPIO_DIN2			 (GPIO_base+0x0a40)
#define  GPIO_DIN3			 (GPIO_base+0x0a80)
#define  GPIO_DIN4			 (GPIO_base+0x0ac0)
#define  GPIO_DIN5			 (GPIO_base+0x0b00)
#define  GPIO_DIN6		   (GPIO_base+0x0b40)  
#define  GPIO_DIN7 		  (GPIO_base+0x0b80)  
/*********************************************************/
 #define GPIO_MODE0			  (GPIO_base+0x1000)
 #define GPIO_MODE1 		  (GPIO_base+0x1100)
 #define GPIO_MODE2 		  (GPIO_base+0x1200)
 #define GPIO_MODE3 		  (GPIO_base+0x1300)
 #define GPIO_MODE4 		  (GPIO_base+0x1400)
 #define GPIO_MODE5 		  (GPIO_base+0x1500)
 #define GPIO_MODE6 		  (GPIO_base+0x1600)
 #define GPIO_MODE7 		  (GPIO_base+0x1700)
 #define GPIO_MODE8 		  (GPIO_base+0x1800)
 #define GPIO_MODE9 		  (GPIO_base+0x1900)
 #define GPIO_MODE10 		  (GPIO_base+0x1A00)
 #define GPIO_MODE11 		  (GPIO_base+0x1B00)
 #define GPIO_MODE12		  (GPIO_base+0x1C00)
 #define GPIO_MODE13		  (GPIO_base+0x1D00)
 #define GPIO_MODE14		  (GPIO_base+0x1E00)
 #define GPIO_MODE15 		  (GPIO_base+0x1F00)
 #define GPIO_MODE16		  (GPIO_base+0x2000)
 #define GPIO_MODE17		  (GPIO_base+0x2100)
 #define GPIO_MODE18		  (GPIO_base+0x2200)
 #define GPIO_MODE19		  (GPIO_base+0x2300)
 #define GPIO_MODE20		  (GPIO_base+0x2400)
 #define GPIO_MODE21		  (GPIO_base+0x2500)
 #define GPIO_MODE22		  (GPIO_base+0x2600)
 #define GPIO_MODE23		  (GPIO_base+0x2700)
 #define GPIO_MODE24		  (GPIO_base+0x2800)
 /*********************************************************/
#define  GPIO_OTHER          (GPIO_base+0x5c00)

/*********************************************************/
#define  CLKO_MODE1 	 (GPIO_base+0x7000)
#define  CLKO_MODE2 	 (GPIO_base+0x7100)   

/*********************************************************/



#define  GPIO_DINV_ADRS(n)	(GPIO_DINV1+0x40*(n))  
	
   #define 	GPIO_DIR1_SET       (GPIO_DIR1+0x04)    
   #define 	GPIO_PULLEN1_SET    (GPIO_PULLEN1+0x04)      
   #define 	GPIO_PULLSEL1_SET   (GPIO_PULLSEL1+0x04)      
   #define 	GPIO_DOUT1_SET      (GPIO_DOUT1+0x04)    
   #define 	GPIO_MODE1_SET      (GPIO_MODE0+0x04)        
   #define  GPIO_MODE_SET(_no)  (GPIO_MODE1_SET+(0x100*(_no)))
   #define  GPIO_DIR_SET(_no)   (GPIO_DIR1_SET+(0x40*(_no)))  
   #define  GPIO_DOUT_SET(_no)  (GPIO_DOUT1_SET+(0x40*(_no)))  
   #define  GPIO_PULLEN_SET(_no)  (GPIO_PULLEN1_SET+(0x40*(_no)))  
   #define  GPIO_PULLSEL_SET(_no)  (GPIO_PULLSEL1_SET+(0x40*(_no)))  
	#define  GPIO_OTHER_SET      (GPIO_OTHER+0x04)
	
   #define 	GPIO_DIR1_CLR       (GPIO_DIR1+0x08)         
   #define 	GPIO_PULLEN1_CLR    (GPIO_PULLEN1+0x08)         
   #define 	GPIO_PULLSEL1_CLR   (GPIO_PULLSEL1+0x08)         
   #define 	GPIO_DOUT1_CLR      (GPIO_DOUT1+0x08)         
   #define 	GPIO_MODE1_CLR      (GPIO_MODE0+0x08)         
   #define  GPIO_MODE_CLR(_no)  (GPIO_MODE1_CLR+(0x100*(_no)))
   #define  GPIO_DIR_CLR(_no)   (GPIO_DIR1_CLR+(0x40*(_no)))
   #define  GPIO_DOUT_CLR(_no)  (GPIO_DOUT1_CLR+(0x40*(_no)))
   #define  GPIO_PULLEN_CLR(_no)  (GPIO_PULLEN1_CLR+(0x40*(_no)))  
   #define  GPIO_PULLSEL_CLR(_no)  (GPIO_PULLSEL1_CLR+(0x40*(_no)))  
	#define  GPIO_OTHER_CLR      (GPIO_OTHER+0x08)

	
   #define  GPIO_MODE(_no)      (GPIO_MODE0+(0x100*(_no))) 
   #define  GPIO_DOUT(_no)      (GPIO_DOUT1+(0x40*(_no)))
   #define  GPIO_DIR(_no)       (GPIO_DIR1+(0x40*(_no)))
   #define  GPIO_DIN(_no)       (GPIO_DIN1+(0x40*(_no)))
   #define  GPIO_PULLEN(_no)    (GPIO_PULLEN1+(0x40*(_no)))
   #define  GPIO_PULLSEL(_no)   (GPIO_PULLSEL1+(0x40*(_no))) 
 

   #define  CLKO_MODE(_no)      (CLKO_MODE1+(0x100*(_no)))  
   #define  CLKO_NUM            2

#endif //defined(DRV_GPIO_REG_AS_6280)
#endif /*!defined(DRV_GPIO_OFF)*/

/******************************************************************************/
#if defined(DRV_GPIO_SP_ON)
	 

	#define GPIO_base AP_GPIO_base

	 /*************************************************************************/ 
	#if defined(DRV_GPIO_REG_AS_6572)
		#define  GPIO_DIR0       (GPIO_base+0X0000)
		#define  GPIO_MODE0       (GPIO_base+0X0300)
		#define  GPIO_DOUT0      (GPIO_base+0X0100)
		#define  GPIO_DIN0		(GPIO_base+0X0200)	 
	#elif defined(DRV_GPIO_REG_AS_6582)
		#define  GPIO_DIR0       (GPIO_base+0X0000)
		#define  GPIO_MODE0       (GPIO_base+0X0600)
		#define  GPIO_DOUT0      (GPIO_base+0X0400)
		#define  GPIO_PULLEN0    (GPIO_base+0X0100)
		#define  GPIO_PULLSEL0    (GPIO_base+0X0200)
		#define  GPIO_DIN0		(GPIO_base+0X0500)
	
	#elif defined(DRV_GPIO_REG_AS_6592)
		#define  GPIO_DIR0		 (GPIO_base+0X0000)
		#define  GPIO_MODE0 	  (GPIO_base+0X0600)
		#define  GPIO_DOUT0 	 (GPIO_base+0X0400)
		#define  GPIO_PULLEN0	 (GPIO_base+0X0100)
		#define  GPIO_PULLSEL0	  (GPIO_base+0X0200)
		#define  GPIO_DIN0		(GPIO_base+0X0500)
	#elif defined(DRV_GPIO_REG_AS_6571)
		#define  GPIO_DIR0		 (GPIO_base+0X0000)
		#define  GPIO_MODE0 	  (GPIO_base+0X0300)
		#define  GPIO_DOUT0 	 (GPIO_base+0X0100)
		//#define  GPIO_PULLEN0	 (GPIO_base+0X0100)
		//#define  GPIO_PULLSEL0	  (GPIO_base+0X0200)
		#define  GPIO_DIN0		(GPIO_base+0X0200)	
	#elif defined(DRV_GPIO_REG_AS_6580)
		#define  GPIO_DIR0		 (GPIO_base+0X0000)
		#define  GPIO_MODE0 	  (GPIO_base+0X0054)
		#define  GPIO_DOUT0 	 (GPIO_base+0X0024)
		//#define  GPIO_PULLEN0	 (GPIO_base+0X0100)
		//#define  GPIO_PULLSEL0	  (GPIO_base+0X0200)
		#define  GPIO_DIN0		(GPIO_base+0X0048)	
		
	#else//
		#define  GPIO_DIR0     (GPIO_base+0X0000)
		#define  GPIO_MODE0     (GPIO_base+0X0C00)
		#define  GPIO_DOUT0    (GPIO_base+0X0800)
		#define  GPIO_INV0     (GPIO_base+0X0600)
		#define  GPIO_PULLEN0  (GPIO_base+0X0200)
		#define  GPIO_PULSEL0  (GPIO_base+0X0400)
		#define  GPIO_DIN0	  (GPIO_base+0X0A00)
	#endif//DRV_GPIO_REG_AS_6572

	#if defined(DRV_MD_GPIO_CONFIG0)
		#define DRV_GPIO_REG_16BIT	//regist is 16 bit //put this feature to here just for easy config
		#define  GPIO_NUM_IN_16BIT_MODE_REG 		5
		#define  BITS_OF_ONE_MODE_IN_16BIT_REG		3
		#define  OFFSET_TO_NEXT_REG      			0x10
	#elif defined(DRV_MD_GPIO_CONFIG1)
		#define DRV_GPIO_REG_16BIT	//regist is 16 bit
		#define  GPIO_NUM_IN_16BIT_MODE_REG 		4
		#define  BITS_OF_ONE_MODE_IN_16BIT_REG		4
		#define  OFFSET_TO_NEXT_REG      			0x10
	#elif defined(DRV_MD_GPIO_CONFIG2)	
		#define DRV_GPIO_REG_32BIT	//regist is 32 bit
		#define  BITS_OF_ONE_MODE_IN_32BIT_REG		4
		#define  GPIO_NUM_IN_32BIT_MODE_REG 		8
		#define  OFFSET_TO_NEXT_REG      			0x10
	#elif defined(DRV_MD_GPIO_CONFIG3)
		#define DRV_GPIO_REG_32BIT	//regist is 32 bit
		#define  BITS_OF_ONE_MODE_IN_32BIT_REG		4
		#define  GPIO_NUM_IN_32BIT_MODE_REG 		8
		#define  OFFSET_TO_NEXT_REG      			0x0C
	#endif


/********************************************************************************/

	//#define  OFFSET_TO_NEXT_REG      			0x10
	#define  OFFSET_OF_SET_REG       			0x04
	#define  OFFSET_OF_CLR_REG	    			0x08
	#define  LENGTH_OF_32BIT_REG  				32
	#define  LENGTH_OF_16BIT_REG				16
	#define  BITS_MASK_IN_16BIT_MODE_REG		((1<<BITS_OF_ONE_MODE_IN_16BIT_REG)-1)	
	#define  BITS_MASK_IN_32BIT_MODE_REG		((1<<BITS_OF_ONE_MODE_IN_32BIT_REG)-1)	
	 
	#define  GPIO_MODE0_SET		 (GPIO_MODE0 + OFFSET_OF_SET_REG)
	#define  GPIO_MODE0_CLR		 (GPIO_MODE0 + OFFSET_OF_CLR_REG)
	#define  GPIO_MODE_SET(_no)  (GPIO_MODE0_SET+(OFFSET_TO_NEXT_REG*(_no)))
	#define  GPIO_MODE_CLR(_no)  (GPIO_MODE0_CLR+(OFFSET_TO_NEXT_REG*(_no)))
	#define  GPIO_MODE(_no)      (GPIO_MODE0+(OFFSET_TO_NEXT_REG*(_no)))
	 
	#define  GPIO_DIR0_SET		 (GPIO_DIR0 + OFFSET_OF_SET_REG)
	#define  GPIO_DIR0_CLR		 (GPIO_DIR0 + OFFSET_OF_CLR_REG)
	#define  GPIO_DIR_SET(_no)   (GPIO_DIR0_SET+(OFFSET_TO_NEXT_REG*(_no))) 
	#define  GPIO_DIR_CLR(_no)   (GPIO_DIR0_CLR+(OFFSET_TO_NEXT_REG*(_no)))
	#define  GPIO_DIR(_no)       (GPIO_DIR0+(OFFSET_TO_NEXT_REG*(_no)))
	 
	#define  GPIO_DOUT0_SET		 (GPIO_DOUT0 + OFFSET_OF_SET_REG)
	#define  GPIO_DOUT0_CLR		 (GPIO_DOUT0 + OFFSET_OF_CLR_REG)
	#define  GPIO_DOUT_SET(_no)  (GPIO_DOUT0_SET+(OFFSET_TO_NEXT_REG*(_no)))  
	#define  GPIO_DOUT_CLR(_no)  (GPIO_DOUT0_CLR+(OFFSET_TO_NEXT_REG*(_no)))
	#define  GPIO_DOUT(_no)      (GPIO_DOUT0+(OFFSET_TO_NEXT_REG*(_no)))

	#define  GPIO_PULLEN0_SET		 (GPIO_PULLEN0 + OFFSET_OF_SET_REG)
	#define  GPIO_PULLEN0_CLR		 (GPIO_PULLEN0 + OFFSET_OF_CLR_REG)
	#define  GPIO_PULLEN_SET(_no)  (GPIO_PULLEN0_SET+(OFFSET_TO_NEXT_REG*(_no)))
	#define  GPIO_PULLEN_CLR(_no)  (GPIO_PULLEN0_CLR+(OFFSET_TO_NEXT_REG*(_no)))	
	#define  GPIO_PULLEN(_no)    (GPIO_PULLEN0+(OFFSET_TO_NEXT_REG*(_no)))
	 
	#define  GPIO_PULLSEL0_SET		 (GPIO_PULLSEL0 + OFFSET_OF_SET_REG)
	#define  GPIO_PULLSEL0_CLR		 (GPIO_PULLSEL0 + OFFSET_OF_CLR_REG)
    #define  GPIO_PULLSEL_SET(_no)  (GPIO_PULLSEL0_SET+(OFFSET_TO_NEXT_REG*(_no))) 
    #define  GPIO_PULLSEL_CLR(_no)  (GPIO_PULLSEL0_CLR+(OFFSET_TO_NEXT_REG*(_no)))
	#define  GPIO_PULLSEL(_no)   (GPIO_PULLSEL0+(OFFSET_TO_NEXT_REG*(_no)))
	 
	#define  GPIO_DIN(_no)       (GPIO_DIN0+(OFFSET_TO_NEXT_REG*(_no)))
#endif
	 
	 /****************************************************************************/

#endif   /*_GPIO_HW_H*/

