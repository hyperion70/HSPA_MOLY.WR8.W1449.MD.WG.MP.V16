/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2011
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
 *    i2c_pmic.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines the I2C DUAL driver.
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "drv_features.h"
#include "dcl.h"
#include "drv_comm.h"
#include "reg_base.h"
#include "intrCtrl.h"
#include	"stack_config.h"        /*MOD_UART1_HISR,MOD_UART2_HISR*/
#include "eint.h"
#include "bmt.h"
#include "kal_public_api.h"

#define DRV_I2C_PMIC

#include "i2c_pmic_hw.h"
#include "i2c_pmic_sw.h"
#include "drvpdn.h"
#include "us_timer.h" 

#include "dcm_sw.h"

//for test
#include "cp15.h"
#include "dcl_pmic6327_sw.h"
/*
#include "cp15.h"
cp15_clean_dcache
cp15_clean_dcache()
cp15_invalidate_icache()
建議要整個關I-bit的狀況下量
也就是先關I-bit, 做完上面兩件事，跑你的code
*/

#if defined(DRV_I2C_PMIC)

#if defined(__UBL__) || defined(__FUE__)
#ifdef __MTK_TARGET__

#if defined(__ARMCC_VERSION)
#if defined(__RVCT__)
#pragma arm section code = "EMIINITCODE", rodata = "EMIINITCONST", zidata = "EMIINITZI", rwdata = "EMIINITRW"
#else
#endif /*__RVCT__*/
#elif defined(__GNUC__)
#endif

#endif /* __MTK_TARGET__ */
#endif //#if defined(__UBL__) || defined(__FUE__)

//__emiinitzi static volatile kal_bool gPMIC6327IRQMasked = KAL_FALSE;
__emiinitzi kal_bool gPMIC6327IRQMasked = KAL_FALSE;
__emiinitzi static volatile kal_uint32 gsavedMask;

#if !defined(__UBL__) && !defined(__FUE__)	
#if defined(I2C_PMIC_DISABLE_DCM)
__emiinitzi kal_uint8 i2cDcmHandle;
#endif //#if !defined(__UBL__) && !defined(__FUE__)	
#endif //#if defined(I2C_PMIC_DISABLE_DCM)

__emiinitrw kal_uint8 i2cSample=0;
__emiinitrw kal_uint8 i2cStep=9;

#define RELEASE_PMIC6327_CHECK {\
    if (gPMIC6327IRQMasked == KAL_TRUE){\
        gPMIC6327IRQMasked = KAL_FALSE;\
        RestoreIRQMask(gsavedMask);\
    }\
}

#if defined(__OLD_PDN_ARCH__)
#define I2C_POWER_OFF()	do{DRV_I2C_ReadReg16(I2C_CG_PDN_CON_SET_ADDR) = I2C_CG_PDN_CON_BIT;}while(0);  /* Power off I2C */
#define I2C_POWER_ON()  do{DRV_I2C_ReadReg16(I2C_CG_PDN_CON_CLR_ADDR) = I2C_CG_PDN_CON_BIT;}while(0);  /* Power on I2C */	
#define I2C_DMA_POWER_ON()   do{DRV_I2C_ReadReg16(DRVPDN_CON0_CLR) = DRVPDN_CON0_DMA;}while(0);   /* Power on DMA */
#else // #if defined(__OLD_PDN_ARCH__)
  #if defined(DRV_I2C_PDN_NAME_I2C)
    #define I2C_POWER_OFF()	do{PDN_SET(PDN_I2C);}while(0);  /* Power off I2C */
    #define I2C_POWER_ON()  do{PDN_CLR(PDN_I2C);}while(0);  /* Power on I2C */	
  #else // #if defined(DRV_I2C_PDN_I2C)
    #define I2C_POWER_OFF()	do{PDN_SET(PDN_SCCB);}while(0);  /* Power off SCCB */
    #define I2C_POWER_ON()  do{PDN_CLR(PDN_SCCB);}while(0);  /* Power on SCCB */	
#endif // #if defined(DRV_I2C_PDN_I2C)
#define I2C_DMA_POWER_ON()   do{PDN_CLR(PDN_DMA);}while(0);  /* Power on DMA */
#endif // #if defined(__OLD_PDN_ARCH__)

#define I2C_PMIC_POWER_ON()         {I2C_POWER_ON();}
#define I2C_PMIC_POWER_OFF()        {}

__emiinitrw I2C_PMIC_STATE I2c_Pmic_State = I2C_PMIC_READY_STATE;
__emiinitzi kal_uint8 *pI2c_Pmic_Value=NULL;
//Point to the local variable of user that start the transaction
//for storing trascation result.
//This variable is assigned in pmic6327_reg_[write|read]_fast().
//The transaction result is assigned in i2c_pmic_polling_trans_comp().
__emiinitzi volatile kal_uint8 *pI2c_Pmic_Result=NULL;
__emiinitzi kal_uint32 I2c_Pmic_Current_Hw_Owner=0;

#if defined(I2C_PMIC_DBG_LOG_ENABLE)
kal_uint32 i2cCount[3];
#if !defined(__UBL__) && !defined(__FUE__)		
#define MAX_I2C_DBG_INFO_SIZE 300
I2C_PMIC_DBG_LOG i2clog[MAX_I2C_DBG_INFO_SIZE];
kal_uint16 i2ctime[100];
kal_uint16 i2ctime2[100];
kal_uint16 i2clogidx=0;
kal_uint32 lastI2ctime=0;
static kal_uint32 i2cReglog[16][2];
static kal_uint8  i2cRegLogindex = 0;
kal_uint32 numOfAssert=0;
kal_uint32 assertTime[100];

#endif //#if !defined(__UBL__) && !defined(__FUE__)		

__emiinitcode void i2c_pmic_log(I2C_PMIC_DBG_INFO type,kal_uint32 var)
{
#if !defined(__UBL__) && !defined(__FUE__)		
	//kal_uint32 savedMask = 0;
	kal_uint16 idx;

	//savedMask=SaveAndSetIRQMask();
	idx=i2clogidx;

	i2clog[idx].type=type;
	i2clog[idx].qbit=ust_get_current_time();
	i2clog[idx].token=var;
	i2clog[idx].hwowner=I2c_Pmic_Current_Hw_Owner;
    i2clog[idx].PDNStatus=DRV_Reg32(0xA0000000);
    if ((type==I2C_field_write)||(type==I2C_byte_write)||(type==I2C_byte_return))
    {
        i2cReglog[i2cRegLogindex][0] = DRV_Reg32(0xA00D0A20);
        i2cReglog[i2cRegLogindex][1] = DRV_Reg32(0xA00D0A24);
        i2cRegLogindex = (i2cRegLogindex+1)&0xF; // % 16
    }
	else if (type==I2C_write_sw_end)
	{
		i2clog[idx].time=ust_get_current_time()-lastI2ctime;
		i2ctime[i2clog[idx].time]++;

        if (I2C_PMIC_GET_START() == 0)
        {
			ASSERT(0);
        }
	}
	else if (type==I2C_read_sw_end)
	{
		i2clog[idx].time=ust_get_current_time()-lastI2ctime;
		i2ctime2[i2clog[idx].time]++;		

        if (I2C_PMIC_GET_START() == 0)
        {
			ASSERT(0);
        }
	}
	else
	{
		i2clog[idx].time=0;
	}
	i2clog[i2clogidx].irqmask=gsavedMask;
	lastI2ctime=ust_get_current_time();	
	i2clogidx++;
	if (i2clogidx>=MAX_I2C_DBG_INFO_SIZE)
		i2clogidx=0;

	//RestoreIRQMask(savedMask);
#endif //#if !defined(__UBL__) && !defined(__FUE__)		
}
#endif //#ifdef defined(I2C_PMIC_DBG_LOG_ENABLE)



__emiinitcode void i2c_pmic_init(void)
{
	I2C_PMIC_POWER_ON();
	// Set slave address
	I2C_PMIC_SET_SLAVE_ADDR(PMIC6327_I2C_ID);

	I2C_PMIC_SET_TIMING(i2cSample,i2cStep);

#if !defined(__UBL__) && !defined(__FUE__)	
#if defined(I2C_PMIC_DISABLE_DCM)
	i2cDcmHandle=DCM_GetHandle();
#endif //#if defined(I2C_PMIC_DISABLE_DCM)
#endif //#if !defined(__UBL__) && !defined(__FUE__)	
}

__emiinitcode void i2c_pmic_set_speed(kal_uint8 Sample,kal_uint8 Step)
{

	i2cSample=Sample;
	i2cStep=Step;
	
}

__emiinitcode void i2c_pmic_set_gpio(void)
{
/*
1.	0xA00700C0 [8:7] = 2'b11
2.	0xA00702C0 [8:7] = 2'b11
3.	0xA00704C0 [8:7] = 2'b11
4.	0xA00708C0 [8:7] = 2'b11
5.	0xA0071D00 [12] = 1'b1
6.	0xA0071E00 [0] = 1'b1
*/
i2c_pmic_init();
#if !defined(__SIP_RAM_SIZE__)
/* Non-SIP */
I2C_PMIC_DRV_SetData(0xA00700C0,0x180,0x180);
I2C_PMIC_DRV_SetData(0xA00702C0,0x180,0x180);
I2C_PMIC_DRV_SetData(0xA00704C0,0x180,0x180);
I2C_PMIC_DRV_SetData(0xA00708C0,0x180,0x180);
I2C_PMIC_DRV_SetData(0xA0071D00,0x1000,0x1000);
I2C_PMIC_DRV_SetData(0xA0071E00,0x1,0x01);
	
#else
/* SIP */
I2C_PMIC_DRV_SetData(0xA0072100,0x1100,0x1100);
/*
//70
*GPIO_MODE12 &= ~(0xF << 8);
*GPIO_MODE12 |=  (0x1<< 8);
*GPIO_PULLEN5 |= (0x1 << 6);//pull enable
*GPIO_PULLSEL5 |= (0x1 << 6);//pull sel high
*GPIO_DIR5 |= (0x1 << 6); //dir out
*GPIO_DOUT5 |= (0x1 << 6); //out put high

//71
*GPIO_MODE12 &= ~(0xF << 12);
*GPIO_MODE12 |=  (0x1 << 12);
*GPIO_PULLEN5 |= (0x1 << 7);
*GPIO_PULLSEL5 |= (0x1 << 7);
*GPIO_DIR5 |= (0x1 << 7);
*GPIO_DOUT5 |= (0x1 << 7);
*/
#endif // #if !defined(__SIP_RAM_SIZE__)

}

__emiinitzi kal_uint32 pmicToken=0;
__emiinitcode kal_uint32 i2c_pmic_getToken(void)
{
	kal_uint32 irqsavedMask = 0;
	kal_uint32 token;
	irqsavedMask=SaveAndSetIRQMask();
	pmicToken++;	
	if (pmicToken==0)
		pmicToken++;
	token=pmicToken;
	RestoreIRQMask(irqsavedMask);
	return token;
}


__emiinitcode kal_bool i2c_pmic_polling_trans_comp(I2C_PMIC_POLLING_TYPE type,kal_uint8 *pVal,kal_uint32 token)
{
	kal_uint8 tmp;

	if(I2c_Pmic_State!=I2C_PMIC_READY_STATE)
	{
		if (type!=I2C_PMIC_QUERY && I2c_Pmic_Current_Hw_Owner!=token)
		{
#if defined(I2C_PMIC_DBG_LOG_ENABLE)		
			I2C_PMIC_LOG(I2C_polling_other_finish_mine,token); 
			i2cCount[0]++;
#endif //#if defined(I2C_PMIC_DBG_LOG_ENABLE)
			return KAL_TRUE;		
		}
	
		tmp = I2C_PMIC_DRV_ReadReg16(I2CP_INTR_STAT);

		if (tmp & I2CP_INTR_STAT_ACK_ERR_MASK)
		{	// ack err
#if defined(I2C_PMIC_DBG_LOG_ENABLE)
#if !defined(__UBL__) && !defined(__FUE__)
            assertTime[numOfAssert%100] = drv_get_current_time();
            numOfAssert++;
#endif //#if !defined(__UBL__) && !defined(__FUE__)

            if(I2c_Pmic_State==I2C_PMIC_READ_STATE)
			{
                if (I2c_Pmic_Current_Hw_Owner!=token)
				{
					I2C_PMIC_LOG(I2C_polling_finish_other_reading_error,token);
					i2cCount[2]++;
				}
				else
				{
					I2C_PMIC_LOG(I2C_polling_finish_reading_error,token); 			
				}
            }
            else
            {
                if (I2c_Pmic_Current_Hw_Owner!=token)
				{
					I2C_PMIC_LOG(I2C_polling_finish_other_writing_error,token);
					i2cCount[1]++;
				}
				else
				{
					I2C_PMIC_LOG(I2C_polling_finish_writing_error,token); 			
				}
            }
#endif //#if defined(I2C_PMIC_DBG_LOG_ENABLE)

            I2C_PMIC_CLEAR_INTR_STAT((I2CP_INTR_STAT_TRANS_COMP_MASK | I2CP_INTR_STAT_ACK_ERR_MASK));
            *pI2c_Pmic_Result = KAL_FALSE;
            pI2c_Pmic_Result = NULL;
            I2c_Pmic_State=I2C_PMIC_READY_STATE;
            return KAL_TRUE;
		}
		else if (tmp & I2CP_INTR_STAT_TRANS_COMP_MASK)
		{	// transaction complete
			I2C_PMIC_CLEAR_INTR_STAT((I2CP_INTR_STAT_TRANS_COMP_MASK | I2CP_INTR_STAT_ACK_ERR_MASK));

#if defined(I2C_PMIC_DBG_PATTERN_ENABLE)
            //=======Fill in special pattern start========
        	I2C_PMIC_SET_SLAVE_ADDR(0xFFFF);
        	I2C_PMIC_DRV_WriteReg16(I2CP_TRANSFER_LEN,0xFFFF);
        	I2C_PMIC_DRV_WriteReg16(I2CP_TRANSFER_LEN_AUX,0xFFFF);
        	I2C_PMIC_SET_TIMING(0x7,0x3F);
        	I2C_PMIC_SET_TRANSAC_LEN(0xFFFF);
        	I2C_PMIC_DRV_WriteReg16(I2CP_CTRL,0xFFFF);
            //=======Fill in special pattern end========
#endif //#if define(I2C_PMIC_DBG_PATTERN_ENABLE)

			if(I2c_Pmic_State==I2C_PMIC_READ_STATE)
			{
#if defined(I2C_PMIC_DBG_LOG_ENABLE)			
				if (I2c_Pmic_Current_Hw_Owner!=token)
				{
					I2C_PMIC_LOG(I2C_polling_finish_other_reading,token);
					i2cCount[2]++;
				}
				else
				{
					I2C_PMIC_LOG(I2C_polling_finish_reading,token); 			
				}
#endif //#if defined(I2C_PMIC_DBG_LOG_ENABLE)

				*pI2c_Pmic_Value = (kal_uint8)(I2C_PMIC_DRV_ReadReg16(I2CP_DATA_PORT));
				pI2c_Pmic_Value=NULL;
				*pI2c_Pmic_Result = KAL_TRUE;
                pI2c_Pmic_Result = NULL;
				I2c_Pmic_State=I2C_PMIC_READY_STATE;

				return KAL_TRUE;				
			}

#if defined(I2C_PMIC_DBG_LOG_ENABLE)
				if (I2c_Pmic_Current_Hw_Owner!=token)
				{
					I2C_PMIC_LOG(I2C_polling_finish_other_writing,token);
					i2cCount[1]++;
				}
				else
				{
					I2C_PMIC_LOG(I2C_polling_finish_writing,token); 			
				}
#endif //#if defined(I2C_PMIC_DBG_LOG_ENABLE)				
			
            *pI2c_Pmic_Result = KAL_TRUE;
            pI2c_Pmic_Result = NULL;
			I2c_Pmic_State=I2C_PMIC_READY_STATE;
			

			return KAL_TRUE;
		}                
	}
	else
	{
		if(type==I2C_PMIC_READ)
		{
			I2C_PMIC_LOG(I2C_polling_rdy_read,token); 
		}
		else if(type==I2C_PMIC_WRITE)
		{
			I2C_PMIC_LOG(I2C_polling_rdy_write,token); 
		}
		else
		{
			I2C_PMIC_LOG(I2C_polling_rdy_query,token); 
		}
	
		return KAL_TRUE;
	}

	return KAL_FALSE;
}

__emiinitcode void i2c_pmic_polling_loop(I2C_PMIC_POLLING_TYPE type,kal_uint8 *pVal,kal_uint32 token)
{
	kal_bool return_value;
	volatile kal_uint32 counter = 0;
	
	kal_uint32 savedMask = 0;

	while(1)
	{
#if !defined(__UBL__) && !defined(__FUE__)
			savedMask=SaveAndSetIRQMask();
#endif //#if !defined(__UBL__) && !defined(__FUE__)

		return_value = i2c_pmic_polling_trans_comp(type,pVal,token);

		if(return_value)
		{
			counter = 0;
			break;
		}
		else
		{

			if(counter > 100000)
			{
#if !defined(__UBL__) && !defined(__FUE__)			    
				ASSERT(0);
#endif //#if !defined(__UBL__) && !defined(__FUE__)				
			}     
#if !defined(__UBL__) && !defined(__FUE__)	
				RestoreIRQMask(savedMask);
#endif //#if !defined(__UBL__) && !defined(__FUE__)				
			counter++;
			continue;
		}
	}    

		gsavedMask=savedMask;
		gPMIC6327IRQMasked = KAL_TRUE;
}

__emiinitcode void i2c_pmic_speedup(kal_uint32 token)
{

#if !defined(__UBL__) && !defined(__FUE__)	
#if defined(I2C_PMIC_DISABLE_DCM)
	DCM_Disable(i2cDcmHandle);
#endif //#if defined(I2C_PMIC_DISABLE_DCM)
#endif //#if !defined(__UBL__) && !defined(__FUE__)	
	i2c_pmic_polling_loop(I2C_PMIC_QUERY,NULL,token);
}

__emiinitcode kal_bool pmic6327_reg_write_fast(kal_uint8 reg, kal_uint8 val,kal_uint32 token)
{	
    volatile kal_bool I2c_Pmic_Result = KAL_FALSE;
    
	I2c_Pmic_State = I2C_PMIC_WRITE_STATE;
	I2c_Pmic_Current_Hw_Owner=token;
    pI2c_Pmic_Result = &I2c_Pmic_Result;

	I2C_PMIC_POWER_ON();

#if defined(__UBL__) || defined(__FUE__)	
	i2c_pmic_set_gpio();
#endif //#if defined(__UBL__) || defined(__FUE__)	

	//  Clear FIFO
	I2C_PMIC_CLEAR_FIFO(1);

	// Clear intr stat
	//I2C_PMIC_CLEAR_INTR_STAT(I2CP_INTR_STAT_TRANS_COMP_MASK | I2CP_INTR_STAT_ACK_ERR_MASK|I2CP_INTR_STAT_HSNAK_ERR_MASK|I2CP_INTR_STAT_TIMEOUT_MASK);
	I2C_PMIC_DRV_WriteReg16(I2CP_INTR_STAT,0x17);

	// Set slave address
	I2C_PMIC_SET_SLAVE_ADDR(PMIC6327_I2C_ID);

	// Set transfter length
	//I2C_PMIC_SET_TRANSFER_LEN(2, 0);
	I2C_PMIC_DRV_WriteReg16(I2CP_TRANSFER_LEN,2);
	I2C_PMIC_DRV_WriteReg16(I2CP_TRANSFER_LEN_AUX,0);

	//I2C_PMIC_SET_TIMING(1, 2);
	I2C_PMIC_SET_TIMING(i2cSample,i2cStep);

	// Set transaction length
	I2C_PMIC_SET_TRANSAC_LEN(1);

	// Set disable direction change
	//I2C_PMIC_SET_DIR_CHANGE(0);
	//I2C_PMIC_SET_ACKERR_DET_EN(1);
	//I2C_PMIC_SET_RESTART(0);
	I2C_PMIC_DRV_WriteReg16(I2CP_CTRL,0x20);

	I2C_PMIC_CLR_INTR((I2CP_INTR_MASK_TRANS_COMP_MASK | I2CP_INTR_MASK_ACK_ERR_MASK));

	// Fill data port
	I2C_PMIC_SET_DATA_PORT(reg);

	// Fill data port
	I2C_PMIC_SET_DATA_PORT(val);

	// Start transaction
	I2C_PMIC_SET_START(1);

	I2C_PMIC_LOG(I2C_write_sw_end,token); 

#if !defined(__UBL__) && !defined(__FUE__)	
	RELEASE_PMIC6327_CHECK;
#endif //#if !defined(__UBL__) && !defined(__FUE__)	

	i2c_pmic_polling_loop(I2C_PMIC_WRITE,NULL,token);


#if !defined(__UBL__) && !defined(__FUE__)	
	RELEASE_PMIC6327_CHECK;
#endif //#if !defined(__UBL__) && !defined(__FUE__)


#if !defined(__UBL__) && !defined(__FUE__)	
#if defined(I2C_PMIC_DISABLE_DCM)
	DCM_Enable(i2cDcmHandle);
#endif //#if defined(I2C_PMIC_DISABLE_DCM)
#endif //#if !defined(__UBL__) && !defined(__FUE__)	

	return I2c_Pmic_Result;

}

__emiinitcode kal_bool pmic6327_reg_read_fast(kal_uint8 reg, kal_uint8 *pVal,kal_uint32 token)
{
    volatile kal_bool I2c_Pmic_Result = KAL_FALSE;
    
	pI2c_Pmic_Value=pVal;
	I2c_Pmic_State = I2C_PMIC_READ_STATE;   
	I2c_Pmic_Current_Hw_Owner=token;
    pI2c_Pmic_Result = &I2c_Pmic_Result;
	
	I2C_PMIC_POWER_ON();

#if defined(__UBL__) || defined(__FUE__)	
	i2c_pmic_set_gpio();
#endif //#if defined(__UBL__) || defined(__FUE__)		

	// Clear FIFO
	I2C_PMIC_CLEAR_FIFO(1);

	//I2C_PMIC_CLEAR_INTR_STAT(I2CP_INTR_STAT_TRANS_COMP_MASK | I2CP_INTR_STAT_ACK_ERR_MASK|I2CP_INTR_STAT_HSNAK_ERR_MASK|I2CP_INTR_STAT_TIMEOUT_MASK);
	I2C_PMIC_DRV_WriteReg16(I2CP_INTR_STAT,0x17);

	// Set slave address
	I2C_PMIC_SET_SLAVE_ADDR(PMIC6327_I2C_ID);

	// Set transfter length
	//I2C_PMIC_SET_TRANSFER_LEN(1, 1);
	I2C_PMIC_DRV_WriteReg16(I2CP_TRANSFER_LEN,1);
	I2C_PMIC_DRV_WriteReg16(I2CP_TRANSFER_LEN_AUX,1);

	//I2C_PMIC_SET_TIMING(1, 2);
	I2C_PMIC_SET_TIMING(i2cSample,i2cStep);

	// Set transaction length
	I2C_PMIC_SET_TRANSAC_LEN(2);

	// Set enable direction change, use STOP condition between transfers
	//I2C_PMIC_SET_DIR_CHANGE(1);
	//I2C_PMIC_SET_ACKERR_DET_EN(0);
	//I2C_PMIC_SET_RESTART(1);
	I2C_PMIC_DRV_WriteReg16(I2CP_CTRL,0x12);

	I2C_PMIC_CLR_INTR((I2CP_INTR_MASK_TRANS_COMP_MASK | I2CP_INTR_MASK_ACK_ERR_MASK));

	// Fill data port
	I2C_PMIC_SET_DATA_PORT(reg);

	// Start transaction
	I2C_PMIC_SET_START(1);

	I2C_PMIC_LOG(I2C_read_sw_end,token); 

#if !defined(__UBL__) && !defined(__FUE__)	
	RELEASE_PMIC6327_CHECK;
#endif //#if !defined(__UBL__) && !defined(__FUE__)


	i2c_pmic_polling_loop(I2C_PMIC_READ,pVal,token);


#if !defined(__UBL__) && !defined(__FUE__)	
	RELEASE_PMIC6327_CHECK;
#endif //#if !defined(__UBL__) && !defined(__FUE__)

#if !defined(__UBL__) && !defined(__FUE__)	
#if defined(I2C_PMIC_DISABLE_DCM)
	DCM_Enable(i2cDcmHandle);
#endif //#if defined(I2C_PMIC_DISABLE_DCM)
#endif //#if !defined(__UBL__) && !defined(__FUE__)	

	return I2c_Pmic_Result;

}

#if defined(__UBL__) || defined(__FUE__)
#ifdef __MTK_TARGET__

#if defined(__ARMCC_VERSION)
#if defined(__RVCT__)
#pragma arm section code, rodata, zidata, rwdata
#else
#endif /*__RVCT__*/
#elif defined(__GNUC__)
#endif

#endif /* __MTK_TARGET__ */
#endif //#if defined(__UBL__) || defined(__FUE__)


#if !defined(__UBL__) && !defined(__FUE__)	
kal_uint8 i2caddr=0x64;
kal_uint8 i2cval=0x32;
kal_uint8 i2cAns;


extern void dcl_pmic6327_byte_write(DCL_UINT8 addr, DCL_UINT8 val, DCL_UINT32 bank);
void i2c_write(void)
{

	dcl_pmic6327_byte_write(i2caddr,i2cval,0);

}

extern DCL_UINT8 dcl_pmic6327_byte_return(DCL_UINT8 addr, DCL_UINT32 bank);
DCL_UINT8 i2c_read(void)
{

	dcl_pmic6327_byte_return(i2caddr,0);
        return 0;
}
#endif //#if !defined(__UBL__) && !defined(__FUE__)	


#endif // #if defined(DRV_I2C_PMIC)

