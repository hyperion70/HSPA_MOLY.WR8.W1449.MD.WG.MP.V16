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
 *   sccb_v2.c
 *
 *
 * Description:
 * ------------
 *   SCCB/I2C V2 Driver
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
 *****************************************************************************/
#include "drv_comm.h"
#include "reg_base.h"
#include "i2c.h"    //*/ the new sccb_v2.h should be named i2c.h /*//
#include "drvpdn.h"

#include "dcl_i2c_owner.h"
#include "kal_general_types.h"
#include "intrCtrl.h"
#include "kal_public_api.h"
#include "kal_public_defs.h" //MSBB change #include "stack_config.h"
#include "kal_trace.h"
#include "kal_internal_api.h"
#include "cache_sw.h"

#if (!defined(DRV_I2C_OFF)) && defined(DRV_I2C_25_SERIES)

#if (defined(DRV_I2C_DMA_ENABLED))
#include "dma_hw.h"
#include "dma_sw.h"
#endif // #if (defined(DRV_I2C_DMA_ENABLED))

#if defined(__OLD_PDN_ARCH__)
#if defined(I2C_CG_PDN_CON0)
  #if defined(__OLD_PDN_DEFINE__)
    #define I2C_CG_PDN_CON_ADDR		(DRVPDN_CON0)
    #define I2C_CG_PDN_CON_SET_ADDR		(DRVPDN_CON0_SET)
    #define I2C_CG_PDN_CON_CLR_ADDR		(DRVPDN_CON0_CLR)
    #define I2C_CG_PDN_CON_BIT		(DRVPDN_CON0_SCCB)
  #elif defined(__CLKG_DEFINE__) // #if defined(__OLD_PDN_DEFINE__)
    #define I2C_CG_PDN_CON_ADDR		(CG_CON0)
    #define I2C_CG_PDN_CON_SET_ADDR		(CG_SET0)
    #define I2C_CG_PDN_CON_CLR_ADDR		(CG_CLR0)
    #define I2C_CG_PDN_CON_BIT		(CG_CON0_I2C)
  #endif // #if defined(__OLD_PDN_DEFINE__)
#elif defined(I2C_CG_PDN_CON1) // #if defined(I2C_CG_PDN_CON0)
  #if defined(__OLD_PDN_DEFINE__)
    #define I2C_CG_PDN_CON_ADDR		(DRVPDN_CON1)
    #define I2C_CG_PDN_CON_SET_ADDR		(DRVPDN_CON1_SET)
    #define I2C_CG_PDN_CON_CLR_ADDR		(DRVPDN_CON1_CLR)
    #define I2C_CG_PDN_CON_BIT		(DRVPDN_CON1_SCCB)
  #elif defined(__CLKG_DEFINE__) // #if defined(__OLD_PDN_DEFINE__)
    #define I2C_CG_PDN_CON_ADDR		(CG_CON1)
    #define I2C_CG_PDN_CON_SET_ADDR		(CG_SET1)
    #define I2C_CG_PDN_CON_CLR_ADDR		(CG_CLR1)
    #define I2C_CG_PDN_CON_BIT		(CG_CON1_I2C)
  #endif // #if defined(__OLD_PDN_DEFINE__)
#elif defined(I2C_CG_PDN_CON3) // #if defined(I2C_CG_PDN_CON0)
  #if defined(__OLD_PDN_DEFINE__)
    #define I2C_CG_PDN_CON_ADDR		(DRVPDN_CON3)
    #define I2C_CG_PDN_CON_SET_ADDR		(DRVPDN_CON3_SET)
    #define I2C_CG_PDN_CON_CLR_ADDR		(DRVPDN_CON3_CLR)
    #define I2C_CG_PDN_CON_BIT		(DRVPDN_CON3_SCCB)
  #elif defined(__CLKG_DEFINE__) // #if defined(__OLD_PDN_DEFINE__)
    #define I2C_CG_PDN_CON_ADDR		(CG_CON3)
    #define I2C_CG_PDN_CON_SET_ADDR		(CG_SET3)
    #define I2C_CG_PDN_CON_CLR_ADDR		(CG_CLR3)
    #define I2C_CG_PDN_CON_BIT		(CG_CON3_I2C)
  #endif // #if defined(__OLD_PDN_DEFINE__)
#else // #if defined(I2C_CG_PDN_CON0)
  #if defined(__OLD_PDN_DEFINE__)
    #define I2C_CG_PDN_CON_ADDR		(DRVPDN_CON02
    #define I2C_CG_PDN_CON_SET_ADDR		(DRVPDN_CON2_SET)
    #define I2C_CG_PDN_CON_CLR_ADDR		(DRVPDN_CON2_CLR)
    #define I2C_CG_PDN_CON_BIT		(DRVPDN_CON2_SCCB)
  #elif defined(__CLKG_DEFINE__) // #if defined(__OLD_PDN_DEFINE__)
    #define I2C_CG_PDN_CON_ADDR		(CG_CON2)
    #define I2C_CG_PDN_CON_SET_ADDR		(CG_SET2)
    #define I2C_CG_PDN_CON_CLR_ADDR		(CG_CLR2)
    #define I2C_CG_PDN_CON_BIT		(CG_CON2_I2C)
  #endif // #if defined(__OLD_PDN_DEFINE__)
#endif // #if defined(I2C_CG_PDN_CON0)
#endif // #if defined(__OLD_PDN_ARCH__)



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

/// I2C internal global variables
i2c_handle_struct i2c_handle[DCL_I2C_NUM_OF_OWNER];
i2c_status_struct dcl_i2c_status;
#if defined(DRV_I2C_BATCH_TRANSACTION_SUPPORT)
i2c_batch_data_struct *batch_data_ptr = NULL;
kal_uint32 transferred_batch_num = 0; //indicate the number of batches has been transferred.
kal_uint32 batch_num_total = 0;
kal_bool if_batch_mode = KAL_FALSE; //record if it is batch mode
#endif

#if defined(DRV_I2C_DMA_ENABLED)
kal_uint8 dcl_i2c_dma_port;		///TX port
DMA_INPUT dcl_i2c_dma_input;
DMA_HWMENU dcl_i2c_dma_menu;


kal_uint8 dcl_i2c_dma_port2;	///RX port
DMA_INPUT dcl_i2c_dma_input2;
DMA_HWMENU dcl_i2c_dma_menu2;


void dcl_i2c_DMA_init(void)
{
	#if defined(DRV_I2C_USE_DMA_V1_API)
	dcl_i2c_dma_port = DMA_GetChannel(DMA_I2CTX);

	dcl_i2c_dma_input.type = DMA_HWTX;
	dcl_i2c_dma_input.size = DMA_BYTE;
	dcl_i2c_dma_input.count = 0;
	dcl_i2c_dma_input.menu = (void *)&dcl_i2c_dma_menu;
	dcl_i2c_dma_input.callback = NULL;

	dcl_i2c_dma_menu.TMOD.burst_mode = KAL_FALSE;
	dcl_i2c_dma_menu.TMOD.cycle = 0;
	dcl_i2c_dma_menu.master = DMA_I2CTX;
	dcl_i2c_dma_menu.addr = 0;

	dcl_i2c_dma_port2 = DMA_GetChannel(DMA_I2CRX);

	dcl_i2c_dma_input2.type = DMA_HWRX;
	dcl_i2c_dma_input2.size = DMA_BYTE;
	dcl_i2c_dma_input2.count = 0;
	dcl_i2c_dma_input2.menu = (void *)&dcl_i2c_dma_menu2;
	dcl_i2c_dma_input2.callback = NULL;

	dcl_i2c_dma_menu2.TMOD.burst_mode = KAL_FALSE;
	dcl_i2c_dma_menu2.TMOD.cycle = 0;
	dcl_i2c_dma_menu2.master = DMA_I2CRX;
	dcl_i2c_dma_menu2.addr = 0;


	#elif defined(DRV_I2C_USE_DMA_V2_API)
	dcl_i2c_dma_port = DMA_GetChannel(DMA_I2C);		///TX port

	dcl_i2c_dma_input.type = DMA_HWTX;
	dcl_i2c_dma_input.size = DMA_BYTE;
	dcl_i2c_dma_input.count = 0;
	dcl_i2c_dma_input.fixed_pattern = KAL_FALSE;
	dcl_i2c_dma_input.menu = (void *)&dcl_i2c_dma_menu;
	dcl_i2c_dma_input.callback = NULL;

	dcl_i2c_dma_menu.TMOD.burst_mode = KAL_FALSE;
	dcl_i2c_dma_menu.TMOD.cycle = 0;
	dcl_i2c_dma_menu.master = DMA_I2C;
	dcl_i2c_dma_menu.addr = 0;

	dcl_i2c_dma_port2 = DMA_GetChannel(DMA_I2C2);	///RX port

	dcl_i2c_dma_input2.type = DMA_HWRX;
	dcl_i2c_dma_input2.size = DMA_BYTE;
	dcl_i2c_dma_input2.count = 0;
	dcl_i2c_dma_input2.fixed_pattern = 0;
	dcl_i2c_dma_input2.menu = (void *)&dcl_i2c_dma_menu2;
	dcl_i2c_dma_input2.callback = NULL;

	dcl_i2c_dma_menu2.TMOD.burst_mode = KAL_FALSE;
	dcl_i2c_dma_menu2.TMOD.cycle = 0;
	dcl_i2c_dma_menu2.master = DMA_I2C2;
	dcl_i2c_dma_menu2.addr = 0;

	#endif // #if defined(DRV_I2C_USE_DMA_V1_API)
}

void dcl_i2c_DMA_tx(kal_uint32 addr, kal_uint32 datalen)
{


	#if defined(DRV_I2C_USE_DMA_V1_API) // #if defined(DRV_I2C_DIRECT_CONFIG_DMA_REGISTER)
	DMA_Stop(dcl_i2c_dma_port);
	dcl_i2c_dma_input.count = datalen;
	dcl_i2c_dma_menu.addr = (kal_uint32)addr;
	DMA_Config(dcl_i2c_dma_port, &dcl_i2c_dma_input, KAL_TRUE);	
	#elif defined(DRV_I2C_DIRECT_CONFIG_DMA_REGISTER)
	I2C_STOP_DMA_TRANSFER(DMA_I2C_TX_CHANNEL);
	I2C_SET_TX_DMA_CONTROL(DMA_I2C_TX_CHANNEL,DMA_MASTER_I2C_TX);
	I2C_SET_DMA_PROGRAMMABLE_ADDR(DMA_I2C_TX_CHANNEL,(kal_uint32)addr);
	I2C_SET_DMA_TRANSFER_COUNT(DMA_I2C_TX_CHANNEL,datalen);
	I2C_START_DMA_TRANSFER(DMA_I2C_TX_CHANNEL);
	#elif defined(DRV_I2C_USE_DMA_V2_API) // #if defined(DRV_I2C_DIRECT_CONFIG_DMA_REGISTER)
	DMA_Stop(dcl_i2c_dma_port);
	dcl_i2c_dma_input.type = DMA_HWTX;
	dcl_i2c_dma_input.count = datalen;
	dcl_i2c_dma_menu.addr = (kal_uint32)addr;
	DMA_Config(dcl_i2c_dma_port, &dcl_i2c_dma_input, KAL_TRUE);
	#else // #if defined(DRV_I2C_USE_DMA_V1_API)
	  #error "Need to specify one DMA usage"
	#endif // #if defined(DRV_I2C_USE_DMA_V1_API)

}

void dcl_i2c_DMA_rx(kal_uint32 addr, kal_uint32 datalen)
{

	#if defined(DRV_I2C_USE_DMA_V1_API) // #if defined(DRV_I2C_DIRECT_CONFIG_DMA_REGISTER)
	DMA_Stop(dcl_i2c_dma_port2);
	dcl_i2c_dma_input2.count = datalen;
	dcl_i2c_dma_menu2.addr = (kal_uint32)addr;
	DMA_Config(dcl_i2c_dma_port2, &dcl_i2c_dma_input2, KAL_TRUE);	
	#elif defined(DRV_I2C_DIRECT_CONFIG_DMA_REGISTER)
	I2C_STOP_DMA_TRANSFER(DMA_I2C_RX_CHANNEL);
	I2C_SET_RX_DMA_CONTROL(DMA_I2C_RX_CHANNEL,DMA_MASTER_I2C_RX);
	I2C_SET_DMA_PROGRAMMABLE_ADDR(DMA_I2C_RX_CHANNEL,(kal_uint32)addr);
	I2C_SET_DMA_TRANSFER_COUNT(DMA_I2C_RX_CHANNEL,datalen);
	I2C_START_DMA_TRANSFER(DMA_I2C_RX_CHANNEL);
	#elif defined(DRV_I2C_USE_DMA_V2_API) // #if defined(DRV_I2C_DIRECT_CONFIG_DMA_REGISTER)
	DMA_Stop(dcl_i2c_dma_port2);
	dcl_i2c_dma_input2.type = DMA_HWRX;
	dcl_i2c_dma_input2.count = datalen;
	dcl_i2c_dma_menu2.addr = (kal_uint32)addr;
	DMA_Config(dcl_i2c_dma_port2, &dcl_i2c_dma_input2, KAL_TRUE);
	#else // #if defined(DRV_I2C_DIRECT_CONFIG_DMA_REGISTER)
	  #error "Need to specify one DMA usage"
	#endif // #if defined(DRV_I2C_DIRECT_CONFIG_DMA_REGISTER)
}

void dcl_i2c_DMA_tx_and_rx(kal_uint32 tx_addr, kal_uint32 tx_datalen, kal_uint32 rx_addr, kal_uint32 rx_datalen)
{
	#if defined(DRV_I2C_DMA_NOT_SUPPORT_READ_AFTER_WRITE)
	ASSERT(0);  // Does NOT support this capability
	#endif // #if defined(DRV_I2C_DMA_NOT_SUPPORT_READ_AFTER_WRITE)

	dcl_i2c_DMA_tx(tx_addr, tx_datalen);
	dcl_i2c_DMA_rx(rx_addr, rx_datalen);

}

kal_bool dcl_i2c_DMA_rx_done_cacheability(kal_uint32 addr, kal_uint32 datalen)
{
	#if defined(__WRITE_THROUGH_CACHEABLE__)
/* under construction !*/
/* under construction !*/
	#endif // #if defined(__WRITE_THROUGH_CACHEABLE__)
	return KAL_TRUE;
	
}



kal_bool dcl_i2c_DMA_check_tx_buffer_cacheability(kal_uint32 addr, kal_uint32 datalen)
{
	#if defined(__DYNAMIC_SWITCH_CACHEABILITY__)
	if ( INT_QueryIsCachedRAM((kal_uint32)addr, (kal_uint32)datalen) )
	{
		// EXT_ASSERT(0, (kal_uint32)para, (kal_uint32)datalen, 0);
		return KAL_FALSE;
	}
	#endif // #if defined(__DYNAMIC_SWITCH_CACHEABILITY__)

	return KAL_TRUE;
}

kal_bool dcl_i2c_DMA_check_rx_buffer_cacheability(kal_uint32 addr, kal_uint32 datalen)
{
	#if defined(__DYNAMIC_SWITCH_CACHEABILITY__)
	if ( INT_QueryIsCachedRAM((kal_uint32)addr, (kal_uint32)datalen) )
	{
		// EXT_ASSERT(0, (kal_uint32)para, (kal_uint32)datalen, 0);
		return KAL_FALSE;
	}
	#endif // #if defined(__DYNAMIC_SWITCH_CACHEABILITY__)

	return KAL_TRUE;
}

#endif // #if defined(DRV_I2C_DMA_ENABLED)


//*/ abstract the HW register config API /*//
//called in i2c_write -> dcl_i2c_hw_cfg (owner, I2C_TRANSACTION_WRITE, para, datalen, NULL, 0, 1);
//called in i2c_read -> dcl_i2c_hw_cfg (owner, I2C_TRANSACTION_READ, NULL, 0, para, datalen, 1);
//called in i2c_cont_write -> dcl_i2c_hw_cfg (owner, I2C_TRANSACTION_CONT_WRITE, para, datalen_in_transfer, NULL, 0, transfer_num);
//called in i2c_cont_read -> dcl_i2c_hw_cfg (owner, I2C_TRANSACTION_CONT_READ, NULL, 0, para, datalen_in_transfer, transfer_num);
//called in i2c_write_and_read -> dcl_i2c_hw_cfg (owner, I2C_TRANSACTION_WRITE_AND_READ, write_buffer, write_len, read_buffer, read_len, 2);
void dcl_i2c_hw_cfg (DCL_I2C_OWNER owner, I2C_TRANSACTION_TYPE type, kal_uint8* write_buffer, kal_uint32 write_len, kal_uint8* read_buffer, kal_uint32 read_len, kal_uint32 transfer_num)
{ 
	i2c_handle_struct* handle=&i2c_handle[owner];
	i2c_config_struct* config=&handle->i2c_config;
	kal_uint32 count_write, count_read, i;

#if(defined (DRV_I2C_DMA_ENABLED))
    if (((!config->is_DMA_enabled) && (read_len>DRV_I2C_FIFO_DEPTH || write_len>DRV_I2C_FIFO_DEPTH)) ||
         (config->is_DMA_enabled && (type == I2C_TRANSACTION_WRITE_AND_READ) && (read_len>DRV_I2C_DMA_DEPTH_AUX || write_len>DRV_I2C_DMA_DEPTH)) ||
         (config->is_DMA_enabled && (type != I2C_TRANSACTION_WRITE_AND_READ) && (read_len>DRV_I2C_DMA_DEPTH || write_len>DRV_I2C_DMA_DEPTH)))
    {
        ASSERT(0); 
    }
#else 
    if (read_len>DRV_I2C_FIFO_DEPTH || write_len>DRV_I2C_FIFO_DEPTH) //if u want a transcation with len>8, please enable DMA.
    {
        ASSERT(0);
    }
#endif 

	count_write = write_len*transfer_num;
	count_read = read_len*transfer_num;
	
	CLEAR_I2C_FIFO;
	CLEAR_I2C_STA;
//	ENABLE_I2C_INT;
	DRV_I2C_ClearBits16(REG_I2C_INT_MASK, I2C_HS_NACK_ERR);
	DRV_I2C_ClearBits16(REG_I2C_INT_MASK, I2C_TRANSAC_ACK_ERR);
	DRV_I2C_SetBits16(REG_I2C_INT_MASK, I2C_TRANSAC_COMPLETE);
	
	SET_I2C_STEP_CNT_DIV(handle->fs_step_cnt_div);
	SET_I2C_SAMPLE_CNT_DIV(handle->fs_sample_cnt_div);
	
	SET_I2C_TRANSACTION_LENGTH(transfer_num);
	
	if (handle->i2c_config.transaction_mode == I2C_TRANSACTION_FAST_MODE)
	{
		SET_I2C_FAST_MODE;
		SET_I2C_ST_BETWEEN_TRANSFER;
		if (config->delay_len>0)
		{
			SET_I2C_DELAY_LENGTH(config->delay_len-1);
		}
		if ((config->delay_len == 0)&&((type == I2C_TRANSACTION_CONT_WRITE)||(type == I2C_TRANSACTION_CONT_READ)))
		{
			SET_I2C_RS_BETWEEN_TRANSFER;
		}
	}
	else if (handle->i2c_config.transaction_mode == I2C_TRANSACTION_HIGH_SPEED_MODE)
	{
		SET_I2C_HS_STEP_CNT_DIV(handle->hs_step_cnt_div);
		SET_I2C_HS_SAMPLE_CNT_DIV(handle->hs_sample_cnt_div);
		SET_I2C_HS_MODE;
		SET_I2C_RS_BETWEEN_TRANSFER;
	}

	DISABLE_I2C_DIR_CHANGE;	
    DISABLE_I2C_DMA_TRANSFER;

	if ((type == I2C_TRANSACTION_WRITE)||(type == I2C_TRANSACTION_CONT_WRITE))
	{
		SET_I2C_SLAVE_ADDRESS(config->slave_address,I2C_WRITE_BIT);
		SET_I2C_TRANSFER_LENGTH(write_len);
        dcl_i2c_status.number_of_read=0;

		#if (defined (DRV_I2C_DMA_ENABLED))
		dcl_i2c_status.is_DMA_enabled = config->is_DMA_enabled;
		if (dcl_i2c_status.is_DMA_enabled)
		{
			ENABLE_I2C_DMA_TRANSFER;
			if (!dcl_i2c_DMA_check_tx_buffer_cacheability((kal_uint32)write_buffer, count_write))
			{
				ASSERT(0); // Buffer cacheability check failed
			}
			dcl_i2c_DMA_tx((kal_uint32)write_buffer, count_write);
		}
		else
		#endif // #if (defined (DRV_I2C_DMA_ENABLED))
		{
			for (i=0;i<count_write;i++) 
			{
				DRV_I2C_WriteReg16(REG_I2C_DATA_PORT, *(write_buffer+i));
			}  
		}
	}
	else if ((type == I2C_TRANSACTION_READ)||(type == I2C_TRANSACTION_CONT_READ))
	{
		SET_I2C_SLAVE_ADDRESS(config->slave_address,I2C_READ_BIT);
		SET_I2C_TRANSFER_LENGTH(read_len);
		
		#if(defined (DRV_I2C_DMA_ENABLED))
		dcl_i2c_status.is_DMA_enabled = config->is_DMA_enabled;
		if (dcl_i2c_status.is_DMA_enabled)
		{
			dcl_i2c_status.number_of_read=0;	
			ENABLE_I2C_DMA_TRANSFER;
			if (!dcl_i2c_DMA_check_rx_buffer_cacheability((kal_uint32)read_buffer, count_read))
			{
				ASSERT(0); // Buffer cacheability check failed
			}
			dcl_i2c_DMA_rx((kal_uint32)read_buffer, count_read);
		}
		else
		#endif // #if(defined (DRV_I2C_DMA_ENABLED))
		{
			dcl_i2c_status.number_of_read = count_read;	
            dcl_i2c_status.read_buffer=read_buffer;
		}	
	}
	else if (type == I2C_TRANSACTION_WRITE_AND_READ)
	{	
		SET_I2C_SLAVE_ADDRESS(config->slave_address,I2C_WRITE_BIT);
		SET_I2C_TRANSFER_LENGTH(write_len);
		SET_I2C_AUX_TRANSFER_LENGTH(read_len);
		ENABLE_I2C_DIR_CHANGE;
		SET_I2C_RS_BETWEEN_TRANSFER;
		
		#if(defined (DRV_I2C_DMA_ENABLED))
		dcl_i2c_status.is_DMA_enabled = config->is_DMA_enabled;
		if (dcl_i2c_status.is_DMA_enabled)
		{
			dcl_i2c_status.number_of_read=0;	
			ENABLE_I2C_DMA_TRANSFER;
			if (!dcl_i2c_DMA_check_tx_buffer_cacheability((kal_uint32)write_buffer, write_len))
			{
				ASSERT(0); // Buffer cacheability check failed
			}
			if (!dcl_i2c_DMA_check_rx_buffer_cacheability((kal_uint32)read_buffer, read_len))
			{
				ASSERT(0); // Buffer cacheability check failed
			}
			dcl_i2c_DMA_tx_and_rx((kal_uint32)write_buffer, write_len, (kal_uint32)read_buffer, read_len);	
		}
		else
		#endif // #if(defined (DRV_I2C_DMA_ENABLED))
		{
			dcl_i2c_status.number_of_read = read_len;
            dcl_i2c_status.read_buffer=read_buffer;
			for (i=0;i<write_len;i++)
			{
				DRV_I2C_WriteReg16(REG_I2C_DATA_PORT, (*(write_buffer+i)));
			}  
		}	
	}
	START_I2C_TRANSACTION;	
}


void _dcl_i2c_status_handler(kal_uint32 sta)
{
	kal_uint32 i;
	kal_uint8* read_buffer=dcl_i2c_status.read_buffer;
    kal_uint32 number_of_read=dcl_i2c_status.number_of_read;
	i2c_handle_struct* handle=&i2c_handle[dcl_i2c_status.owner];

	if (sta == I2C_TRANSAC_COMPLETE) //This transaction is done now
	{
        #if(defined (DRV_I2C_DMA_ENABLED))
		if (!handle->i2c_config.is_DMA_enabled) //copy the read data to the previous transcation owner
        #endif // #if(defined (DRV_I2C_DMA_ENABLED))
		{
			for (i=0;i<number_of_read;i++)
			{
				read_buffer[i]=(DRV_I2C_ReadReg16(REG_I2C_DATA_PORT) & 0xff); //copy the read data to the previous transcation owner
			}
		}
		handle->transaction_result = I2C_TRANSACTION_COMPLETE;
	}
	else
	{
		if (sta & I2C_TRANSAC_ACK_ERR)
			handle->transaction_result = I2C_TRANSACTION_ACKERR;
		else if (sta & I2C_HS_NACK_ERR)
			handle->transaction_result = I2C_TRANSACTION_HS_NACKERR;
		else //if got this, check register INTR_STAT to debug
			handle->transaction_result = I2C_TRANSACTION_FAIL;
	}
	dcl_i2c_status.state=I2C_READY_STATE;
	I2C_POWER_OFF();
}

void _dcl_i2c_lisr(void)
{
	kal_uint32 savedMask;
	kal_uint32 sta;
	//test lisr executive time
	//kal_uint32 start_qbit,end_qbit;//

 	//start_qbit = HW_TDMA_GET_TQCNT();//
 	
	savedMask = SaveAndSetIRQMask();

	sta = DRV_I2C_ReadReg16(REG_I2C_INT_STA); //sta=REG_I2C_INT_STA;

#if defined(DRV_I2C_BATCH_TRANSACTION_SUPPORT)
	if(if_batch_mode)
	{
		if (sta == I2C_TRANSAC_COMPLETE)
		{
			transferred_batch_num ++;
			if (transferred_batch_num == batch_num_total)
			{
				dcl_i2c_status.state=I2C_READY_STATE;
				if_batch_mode = KAL_FALSE;
				I2C_POWER_OFF();				
			}
			else
			{
				batch_data_ptr ++;
				switch (batch_data_ptr->transaction_type)
				{
					case I2C_TRANSACTION_WRITE:
					{
						dcl_i2c_status.number_of_read=0;
						dcl_i2c_hw_cfg (dcl_i2c_status.owner, I2C_TRANSACTION_WRITE, batch_data_ptr->transaction_data.single_write.data, batch_data_ptr->transaction_data.single_write.data_len, NULL, 0, 1);
					}
					break;
					case I2C_TRANSACTION_READ:
					{
						dcl_i2c_status.read_buffer=batch_data_ptr->transaction_data.single_read.data;
						dcl_i2c_hw_cfg (dcl_i2c_status.owner, I2C_TRANSACTION_READ, NULL, 0, batch_data_ptr->transaction_data.single_read.data, batch_data_ptr->transaction_data.single_read.data_len, 1);
					}
					break;
					case I2C_TRANSACTION_CONT_WRITE:
					{
						dcl_i2c_status.number_of_read=0;
						dcl_i2c_hw_cfg (dcl_i2c_status.owner, I2C_TRANSACTION_CONT_WRITE, batch_data_ptr->transaction_data.cont_write.data, batch_data_ptr->transaction_data.cont_write.data_len, NULL, 0, batch_data_ptr->transaction_data.cont_write.transfer_num);
					}
					break;
					case I2C_TRANSACTION_CONT_READ:
					{
						dcl_i2c_status.read_buffer=batch_data_ptr->transaction_data.cont_read.data;
						dcl_i2c_hw_cfg (dcl_i2c_status.owner, I2C_TRANSACTION_CONT_READ, NULL, 0, batch_data_ptr->transaction_data.cont_read.data, batch_data_ptr->transaction_data.cont_read.data_len, batch_data_ptr->transaction_data.cont_read.transfer_num);
					}
					break;
					case I2C_TRANSACTION_WRITE_AND_READ:
					{	
						dcl_i2c_status.read_buffer=batch_data_ptr->transaction_data.write_and_read.indata;
						dcl_i2c_hw_cfg (dcl_i2c_status.owner, I2C_TRANSACTION_WRITE_AND_READ, batch_data_ptr->transaction_data.write_and_read.outdata, batch_data_ptr->transaction_data.write_and_read.outdata_len, batch_data_ptr->transaction_data.write_and_read.indata, batch_data_ptr->transaction_data.write_and_read.indata_len, 2);	
					}
					break;	
					default:
						//ASSERT(0);
					break;
				}
			}
		}
		else
		{
			dcl_i2c_status.state=I2C_READY_STATE;
			if_batch_mode = KAL_FALSE;
			I2C_POWER_OFF();
		}
	
	}
	else
#endif	
	{
        _dcl_i2c_status_handler(sta);
	}
 	
	RestoreIRQMask(savedMask);
	//end_qbit = HW_TDMA_GET_TQCNT();//
}


void dcl_i2c_init(void)
{
    if(dcl_i2c_status.state != I2C_IDLE_STATE)
        return;
	dcl_i2c_status.state=I2C_READY_STATE;
  
	IRQ_Register_LISR(IRQ_I2C_CODE, _dcl_i2c_lisr,"DCL I2C ISR");
	IRQUnmask(IRQ_I2C_CODE);
    
	ENABLE_I2C_ACK_ERR_DET; //Always enable ack error detection
	ENABLE_I2C_NAKERR_DET;  //Always enable nack error detection

#if (defined(DRV_I2C_DMA_ENABLED))
	dcl_i2c_status.is_DMA_enabled=KAL_FALSE;
	dcl_i2c_DMA_init();
#endif // #if (defined(DRV_I2C_DMA_ENABLED))

#if defined(MT6276)
	DRV_WriteReg32((CONFG_base+0x714), (DRV_Reg32((CONFG_base+0x714))|0x10));// for gpio input high/low active
#endif

}


//----------------------------I2C internal arbiteration------------------------------
//--When return from this function, I bit is turned off!!--
kal_uint32 dcl_i2c_wait_transaction_complete_and_lock(DCL_I2C_OWNER owner)
{
	kal_uint32 savedMask;

	if ((kal_query_systemInit()==KAL_FALSE)&&(kal_if_lisr()==KAL_FALSE))
	{
		while(1)
		{
		    savedMask = kal_take_thread_protect();
			if (dcl_i2c_status.state==I2C_READY_STATE)
			{
				
				if (dcl_i2c_status.state==I2C_READY_STATE) //The I2C is currently free
				{
					dcl_i2c_status.state=I2C_BUSY_STATE; //Lock it
					dcl_i2c_status.owner=owner;
			
					I2C_POWER_ON();
	    			//RestoreIRQMask(savedMask);//dongming add this for 60qbit fatal error
					return savedMask;//dongming change it for 60 qbit fatal error. will not use savedMask any more
				}
				else
				{
					kal_give_thread_protect(savedMask); // What a pity, that the handle is locked by somebody again. back to waiting loop
				}
			}
			else if (i2c_handle[owner].i2c_config.get_handle_wait==KAL_FALSE)
			{
				return 0;
			}
			else
			{
				kal_give_thread_protect(savedMask);
			}
		}//end of while
	}
	else
	{
		if (dcl_i2c_status.state!=I2C_READY_STATE)
		{
			ASSERT(0);
		}

		dcl_i2c_status.state=I2C_BUSY_STATE; //Lock it
		dcl_i2c_status.owner=owner;
		
		I2C_POWER_ON();
	}

	return 0;
}



void dcl_i2c_wait_transaction_complete(kal_uint32 savedMask)
{
	
	if ((kal_query_systemInit()==KAL_FALSE)&&(kal_if_lisr()==KAL_FALSE))
	{
		//RestoreIRQMask(savedMask);
		kal_give_thread_protect(savedMask);
		while (dcl_i2c_status.state == I2C_BUSY_STATE)
		{
			;
		}
		return;
	}
	else
	{
		kal_uint32 sta;
		do
		{
			sta = DRV_I2C_ReadReg16(REG_I2C_INT_STA); 
		} while((sta & I2C_TRANSAC_COMPLETE) == 0);

        _dcl_i2c_status_handler(sta);
	}
}



//----------------------------I2C Configuration APIs-------------------------------
void dcl_i2c_set_transaction_speed(DCL_I2C_OWNER owner,I2C_TRANSACTION_MODE mode,kal_uint16* Fast_Mode_Speed,kal_uint16* HS_Mode_Speed)
{
	kal_uint32	step_cnt_div;
	kal_uint32	sample_cnt_div;
	kal_uint32	temp;

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
#endif

	//Fast Mode Speed
	for (sample_cnt_div=1;sample_cnt_div<=8;sample_cnt_div++)
	{
		if (NULL != Fast_Mode_Speed)
		{
			temp=((*Fast_Mode_Speed)*2*sample_cnt_div);	
		}
		else
		{
			temp = 1*2*sample_cnt_div;
		}
		step_cnt_div=(I2C_CLOCK_RATE+temp-1)/temp;	//cast the <1 part
   
		if (step_cnt_div<=64) 
		{
			break;
		}
	}
	if (step_cnt_div>64 && sample_cnt_div>8)
	{
		step_cnt_div=64;
		sample_cnt_div=8;
	}


    
	if (NULL != Fast_Mode_Speed)
	{
        *Fast_Mode_Speed = I2C_CLOCK_RATE/2/sample_cnt_div/step_cnt_div; 
        i2c_handle[owner].fs_sample_cnt_div=sample_cnt_div-1;
        i2c_handle[owner].fs_step_cnt_div=step_cnt_div-1;
        i2c_handle[owner].i2c_config.transaction_mode=I2C_TRANSACTION_FAST_MODE;
 
	}
  
	//HS Mode Speed
	if (mode==I2C_TRANSACTION_HIGH_SPEED_MODE) 
	{ 
		for (sample_cnt_div=1;sample_cnt_div<=8;sample_cnt_div++)
		{
			if (NULL != HS_Mode_Speed)
			{
				temp=((*HS_Mode_Speed)*2*sample_cnt_div);	
			}
			else
			{
				temp=(1*2*sample_cnt_div);	
			}
			step_cnt_div=(I2C_CLOCK_RATE+temp-1)/temp;
			if (step_cnt_div<=8) 
			{
				break;
			}
		}
		if (NULL != HS_Mode_Speed)
		{
			*HS_Mode_Speed=I2C_CLOCK_RATE/2/sample_cnt_div/step_cnt_div; 
            i2c_handle[owner].hs_sample_cnt_div=sample_cnt_div-1;
            i2c_handle[owner].hs_step_cnt_div=step_cnt_div-1;
            i2c_handle[owner].i2c_config.transaction_mode=I2C_TRANSACTION_HIGH_SPEED_MODE;
		}
	}
}

//----------------------------NEW I2C Transaction APIs-------------------------------
/*************************************************************************
* FUNCTION
*	dcl_i2c_batch_transaction
*
* DESCRIPTION
*	This function support the non-blocking mode transaction through I2C
*
* PARAMETERS
*  owner : Who wants to transfer data 
*  BatchData  : non-blocking transaction data
*  BatchNum: Number of Batches to transfer
*
* RETURNS
*	I2C_TRANSACTION_RESULT
*************************************************************************/
//I2C_TRANSACTION_RESULT dcl_i2c_batch_transaction(DCL_I2C_OWNER owner, i2c_batch_data_struct *batch_data, kal_uint32 batch_num)
#if defined(DRV_I2C_BATCH_TRANSACTION_SUPPORT)
I2C_TRANSACTION_RESULT dcl_i2c_batch_transaction(DCL_I2C_OWNER owner, i2c_batch_data_struct *batch_data, kal_uint32 batch_num)
{
	if (dcl_i2c_status.state==I2C_BUSY_STATE)
	{
		//return I2C_TRANSACTION_IS_BUSY;
		ASSERT(0);
	}
	
	dcl_i2c_status.state = I2C_BUSY_STATE;
	dcl_i2c_status.owner = owner;
		
	I2C_POWER_ON();
	transferred_batch_num = 0;
	batch_num_total = batch_num;
	if_batch_mode = KAL_TRUE;
	
	batch_data_ptr = batch_data;
	switch (batch_data_ptr->transaction_type)
	{
		case I2C_TRANSACTION_WRITE:
		{
			dcl_i2c_status.number_of_read=0;
			dcl_i2c_hw_cfg (owner, I2C_TRANSACTION_WRITE, batch_data_ptr->transaction_data.single_write.data, batch_data_ptr->transaction_data.single_write.data_len, NULL, 0, 1);
		}
		break;
		case I2C_TRANSACTION_READ:
		{
			dcl_i2c_status.read_buffer=batch_data_ptr->transaction_data.single_read.data;
			dcl_i2c_hw_cfg (owner, I2C_TRANSACTION_READ, NULL, 0, batch_data_ptr->transaction_data.single_read.data, batch_data_ptr->transaction_data.single_read.data_len, 1);
		}
		break;
		case I2C_TRANSACTION_CONT_WRITE:
		{
			dcl_i2c_status.number_of_read=0;
			dcl_i2c_hw_cfg (owner, I2C_TRANSACTION_CONT_WRITE, batch_data_ptr->transaction_data.cont_write.data, batch_data_ptr->transaction_data.cont_write.data_len, NULL, 0, batch_data_ptr->transaction_data.cont_write.transfer_num);
		}
		break;
		case I2C_TRANSACTION_CONT_READ:
		{
			dcl_i2c_status.read_buffer=batch_data_ptr->transaction_data.cont_read.data;
			dcl_i2c_hw_cfg (owner, I2C_TRANSACTION_CONT_READ, NULL, 0, batch_data_ptr->transaction_data.cont_read.data, batch_data_ptr->transaction_data.cont_read.data_len, batch_data_ptr->transaction_data.cont_read.transfer_num);
		}
		break;
		case I2C_TRANSACTION_WRITE_AND_READ:
		{	
			dcl_i2c_status.read_buffer=batch_data_ptr->transaction_data.write_and_read.indata;
			dcl_i2c_hw_cfg (owner, I2C_TRANSACTION_WRITE_AND_READ, batch_data_ptr->transaction_data.write_and_read.outdata, batch_data_ptr->transaction_data.write_and_read.outdata_len, batch_data_ptr->transaction_data.write_and_read.indata, batch_data_ptr->transaction_data.write_and_read.indata_len, 2);	
		}
		break;	
		default:
		//	ASSERT(0);
		break;
	}
	return I2C_TRANSACTION_SUCCESS;
}

I2C_TRANSACTION_RESULT dcl_i2c_get_batch_transaction_result(DCL_I2C_OWNER owner,kal_uint32* batch_num)
{	
	if (dcl_i2c_status.state==I2C_BUSY_STATE)
	{
		return I2C_TRANSACTION_IS_BUSY;
	}
	if (transferred_batch_num != batch_num_total)
	{
		*batch_num = transferred_batch_num;
		return I2C_TRANSACTION_FAIL;
	}
	return I2C_TRANSACTION_SUCCESS;
}

#endif  //defined(DRV_I2C_BATCH_TRANSACTION_SUPPORT)

#endif

/*************************************************************************
* FUNCTION
*    CameraSccbPadEnable
*
* DESCRIPTION
*    This function enable/disable camera interface pad(include sccb)
*
* PARAMETERS
*    On to enable pad
*
* RETURNS
*    None
*
* GLOBALS AFFECTED
*
*************************************************************************/
void CameraSccbPadEnable(kal_bool On)
{
    kal_uint32 mask = SaveAndSetIRQMask();
    if(On == KAL_TRUE)
    {
        #if defined(MT6256)
        *((volatile unsigned int *) (CONFIG_base + 0x100)) &= (~0x4);  //enable CAM PAD
        #elif defined(MT6276)
        *((volatile unsigned int *) (CONFIG_base + 0x714)) |=  0x10 ;  //enable CAM PAD
        #endif
    }
    else
    {
        #if defined(MT6256)
        *((volatile unsigned int *) (CONFIG_base + 0x100)) |= (0x4);  //disbale CAM PAD
        #elif defined(MT6276)
        ///do nothing, we keep CAM_IE on for MT6276 since CAM and CTP share same I2C bus
        #endif
    }
    RestoreIRQMask(mask);
    
    return;
}

