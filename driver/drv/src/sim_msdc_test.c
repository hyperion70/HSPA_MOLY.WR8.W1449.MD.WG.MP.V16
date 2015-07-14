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
 * sim_msdc_test.c
 *
 * Project:
 * --------
 *   MT6268ADVT
 *
 * Description:
 * ------------
 *   This file is used when doing sim and msdc dvt, when enable __MSDC_BASIC_LOAD__, functions here will replace ssdbg1_main.
 *   The target of this file is to merge as many DVT loads into single test load as possible.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#if (defined( __MSDC_BASIC_LOAD__) || defined(DRV_SIM_BT)) //this should be defined as global option, without this option, this file won't be compiled

#include "kal_public_api.h" //MSBB change #include "kal_release.h"      /* Basic data type */
#include "drv_msgid.h"

#include "kal_public_defs.h" //MSBB change #include "stack_common.h"
#include "kal_public_defs.h" //MSBB change #include "stack_msgs.h"
#include "stack_ltlcom.h" //MSBB change #include "app_ltlcom.h"       /* Task message communiction */
#include "stack_ltlcom.h" //MSBB change #include "tst_ltlcom.h"

#include "syscomp_config.h"
#include "task_config.h"      /* Task creation */

#include "stacklib.h"         /* Basic type for dll, evshed, stacktimer */

#include "event_shed.h"       /* Event scheduler */

#include "stack_timer.h"      /* Stack timer */

#include "stdio.h"
#include "uart_sw.h"

#include "stack_timer.h"      /* Stack timer */


#include "stdio.h"
#include "uart_sw.h"
#include "fat_fs.h"
#include "gpt_sw.h"
#include "msdc_def.h"
#include "sd_def.h"

//#include "Rtfiles.h"
#include "fs_gprot.h"
#include "config_hw.h"
#include "intrCtrl.h"
#include "sim_hw.h"

#include "dma_hw.h"
#include "dma_sw.h"



#ifdef __CLKG_DEFINE__
#ifdef DRVPDN_CON1
#error "__CLKG_DEFINE__ & DRVPDN_CON1 are all defined"
#else
#define DRVPDN_CON1		CG_CON1
#endif

#ifdef DRVPDN_CON1_SIM
#error "__CLKG_DEFINE__ & DRVPDN_CON1_SIM are all defined"
#else
#define DRVPDN_CON1_SIM	CG_CON1_SIM
#endif

#ifdef DRVPDN_CON0
#error "__CLKG_DEFINE__ & DRVPDN_CON0 are all defined"
#else
#define DRVPDN_CON0		CG_CON0
#endif

#ifdef DRVPDN_CON0_SIM2
#error "__CLKG_DEFINE__ & DRVPDN_CON0_SIM2 are all defined"
#else
#define DRVPDN_CON0_SIM2	CG_CON0_SIM2
#endif

#ifdef DRVPDN_CON1_MSDC
#error "__CLKG_DEFINE__ & DRVPDN_CON1_MSDC are all defined"
#else
#define DRVPDN_CON1_MSDC	CG_CON1_MSDC
#endif

#ifdef DRVPDN_CON0_MSDC2
#error "__CLKG_DEFINE__ & DRVPDN_CON0_MSDC2 are all defined"
#else
#define DRVPDN_CON0_MSDC2	CG_CON0_MSDC2
#endif

#ifdef DRVPDN_CON1_CLR
#error "__CLKG_DEFINE__ & DRVPDN_CON1_CLR are all defined"
#else
#define DRVPDN_CON1_CLR	CG_CLR1
#endif

#ifdef DRVPDN_CON1_SET
#error "__CLKG_DEFINE__ & DRVPDN_CON1_SET are all defined"
#else
#define DRVPDN_CON1_SET	CG_SET1
#endif
#endif


#define MSDC_DVT
#ifdef MSDC_DVT

#ifdef __MSDC_BASIC_LOAD__
typedef struct ssdbg1_context_struct_t {
   stack_timer_struct  ssdbg1_timer0;
   stack_timer_struct  ssdbg1_base_timer;
   event_scheduler     *ssdbg1_event_scheduler_ptr;
   eventid             ssdbg1_event_id;
} ssdbg1_context_struct_t;

ssdbg1_context_struct_t ssdbg1_context;

typedef struct ssdbg2_context_struct_t {
   stack_timer_struct  ssdbg2_timer0;

   stack_timer_struct  ssdbg2_base_timer;
   event_scheduler     *ssdbg2_event_scheduler_ptr;
   eventid             ssdbg2_event_id;
} ssdbg2_context_struct_t;

ssdbg2_context_struct_t ssdbg2_context;


typedef struct {
   LOCAL_PARA_HDR
   kal_uint32 id;
} ssdbg1_localpara_struct;

#endif

#define LEN		32*1024
//#define LEN		512*1024
#define TIMES  100
//static kal_uint8 MyTxbuf[LEN];
//static kal_uint8 MyRxbuf[LEN];
//static kal_uint8 buffer[1024*8];
//static kal_uint32 fcount = 0;
#define BYTES_PER_ACCESS		17839
//#define WRITE_TEST
//#define CACHED_TEST

//#define NOT_4BYTES_ALIGN


#if defined(__MTK_TARGET__)
__attribute__((aligned(4)))
#endif
 kal_uint8 r[LEN+3], w[LEN+3], w1[LEN+3], r2[LEN+3], w2[LEN+3];

volatile kal_bool check_read_content = KAL_TRUE;
double	bestReadThroughput, worstReadThroughput, bestWriteThroughput, worstWriteThroughput;

#ifdef CACHED_TEST
kal_bool	cachedTest;
double	cachedBestReadThroughput, cachedWorstReadThroughput, cachedBestWriteThroughput, cachedWorstWriteThroughput;
#pragma arm section zidata = "CACHEDZI"
#if defined(__MTK_TARGET__)
__attribute__((aligned(4)))
#endif
 kal_uint8 cached_r[LEN+3], cached_w[LEN+3];
#pragma arm section zidata
#endif


void dummyFunction(void){}

#if defined(MSDC_SDIO_DVT) || defined(MSDC2_SDIO_DVT)
kal_bool waitingSDIOTest = KAL_TRUE;/*if SDIO test is doing, we have to make both task wait for SDIO test done*/
#else
kal_bool waitingSDIOTest = KAL_FALSE;
#endif

#ifdef MSDC2_SDIO_DVT
extern MSDC_HANDLE *msdc2_handle ;
#endif

#ifdef __MSDC_BASIC_LOAD__
void MSDC_DVT_readWrite(void)
{

	

#ifdef MULTIPLE_WRITE_TEST
	gMSDC_Handle->mIsPresent = KAL_TRUE;
	simple_multi_write_test();
	return;
#endif




	kal_int32 i,j, result = 0, count = 0;
	kal_uint32 access = 17893;
	FS_HANDLE hFile=0, wFile = 0;
	kal_wchar full_name[100];
	kal_uint32  file_size,len,total_len;
	kal_uint32 time_1,time_2;
	double rate;
	volatile kal_bool format = 0;
	kal_uint8 offset1 = 0,offset2 = 0;
	kal_uint32 timeUsedinFS;
	 int card;
        kal_uint8 path[10];
        FS_DiskInfo info;

	kal_uint32	testTimes = 0;	



	result = FS_TestMSDC(gMSDC_Handle);
	if(result < FS_NO_ERROR){
		dbg_print("memory card card not present %d !!\r\n", result);
		return;
        	while(1)
        		kal_sleep_task(1000);
	}
	
	card = FS_GetDrive(FS_DRIVE_V_REMOVABLE, 1, FS_NO_ALT_DRIVE);

        if (card >= FS_NO_ERROR)
        {
            kal_wsprintf((WCHAR*) path, "%c:\\", card);

            result = FS_GetDiskInfo((WCHAR*) path, &info, FS_DI_BASIC_INFO | FS_DI_FREE_SPACE);
            if (result < RTF_NO_ERROR)
            {
            	ASSERT(0);
            }
         
            
        }
        else{
        	dbg_print("memory card card not present!!\r\n");
        	return;
        	while(1)
        		kal_sleep_task(1000);
        }

#ifdef HW_FAST_FORMAT_TEST
	while(1){
		time_1 = drv_get_current_time();
		result = FS_GeneralFormat((WCHAR*) path, FS_FORMAT_HIGH, NULL);
		if(FS_NO_ERROR == result){
			time_2 = drv_get_current_time();
			dbg_print("format done %d, %f\n\r", time_2 - time_1, (double)(0.0005 * writeSectorsCount * 32000)/(double)(writeTimeCount));
			writeSectorsCount = writeTimeCount = 0;
			kal_sleep_task(1500);
		}
		else{
			dbg_print("format failed: %d \n\r", result);
			while(1)
        			kal_sleep_task(1000);

		}
	}
#endif
	//DumpDiskInfo("d:\\");
	kal_wsprintf(full_name, "%c:\\Write.bin", card);
	for(i=0;i<LEN+3;i++)
	{
		w[i+offset1] = i%256;
		r[i+offset2] = 0;

#ifdef	CACHED_TEST
		cached_w[i+offset1] = i%256;
		cached_r[i+offset2] = 0;		
#endif

	}

#if defined(NOT_4BYTES_ALIGN)
		// test W to B or B to W(DMA)
		offset1 = (kal_uint32)w % 4;
		if(offset1 == 0)
			offset1 = 1;
		else 
			offset1 = 0;

		offset2 = (kal_uint32)r % 4;
		if(offset2 == 0)
			offset2 = 1;
		else 
			offset2 = 0;
		for(i=0;i<LEN+3;i++)
		{
			w[i+offset1] = i%256;
			r[i+offset2] = 0;
		}
#endif


	while(1){


#if 1//write 
		
		count++;
		//Search_Dir(L"C:\\");
		FS_Delete(full_name);
#ifdef	CACHED_TEST
			if(KAL_TRUE == cachedTest)
				cachedTest = KAL_FALSE;
			else
				cachedTest = KAL_TRUE;

			if(KAL_TRUE == cachedTest)
				dbg_print("\r\n===========Cached Write Test Start(%d) ====================\r\n",count);
			else
#endif		
		dbg_print("\r\n==================Write Test Start(%d) ====================\r\n",count);

		hFile = FS_Open(full_name, FS_CREATE|FS_READ_WRITE);
		if(hFile <= 0){
			dbg_print("open file failed \r\n");
			return ;
		}
		//ASSERT(hFile>0);
		
#if defined(NOT_4BYTES_ALIGN)
		// test W to B or B to W(DMA)
		offset1 = (kal_uint32)w % 4;
		if(offset1 == 0)
			offset1 = 1;
		else 
			offset1 = 0;

		offset2 = (kal_uint32)r % 4;
		if(offset2 == 0)
			offset2 = 1;
		else 
			offset2 = 0;
		for(i=0;i<LEN+3;i++)
		{
			w[i+offset1] = i%256;
			r[i+offset2] = 0;
		}
#endif		
		i = 0;
		total_len = 0;
	
		kal_get_time(&time_1);
		//readSectorCount = writeSectorCount = readTime = writeTime = writeSectorCount2 = writeTime2 = 0;
		//writeTime3 = writeTime4 = writeTime5 = writeTime6 = 0;
		while(1)
		{

#ifdef	CACHED_TEST
			if(KAL_TRUE == cachedTest)
				result = FS_Write(hFile,cached_w+offset1,LEN,&len);
			else
#endif
			result = FS_Write(hFile,w+offset1,LEN,&len);
			total_len += len;
			i++;
			if(result < 0 ){
				if(result == RTF_DISK_FULL){
					dbg_print("Disk Full %d\r\n", total_len);
					FS_Close(hFile);
					return;
				}
				else{
					dbg_print("write fail %d at: %d \r\n",result, total_len);
					FS_Close(hFile);
					return;

					break;
				}
			}
			if(len != LEN){
				dbg_print("write length not correct \r\n");
				FS_Close(hFile);
				return;
			}
			if(i%TIMES == 0)
			{
				kal_get_time(&time_2);
			   rate = (double)(LEN*TIMES)/(double)(time_2-time_1);
				dbg_print("write[%d], total: %d, rate %f \r\n", i, total_len,rate/0.004615);
				//dbg_print("%d, %d, %d , %d\r\n", writeTime3 , writeTime4 , writeTime5,writeTime6);
				//readSectorCount = writeSectorCount = readTime = writeTime = writeSectorCount2 = writeTime2= 0;
				//writeTime3 = writeTime4 = writeTime5 = writeTime6 = 0;
#ifdef	CACHED_TEST
			if(KAL_TRUE == cachedTest){
				if((rate/0.004615) > cachedBestWriteThroughput || 0 == cachedBestWriteThroughput)
					cachedBestWriteThroughput = (rate/0.004615);
				if((rate/0.004615) < cachedWorstWriteThroughput || 0 == cachedWorstWriteThroughput)
					cachedWorstWriteThroughput = (rate/0.004615);
			}
			else
#endif					
			{
				if((rate/0.004615) > bestWriteThroughput || 0 == bestWriteThroughput)
					bestWriteThroughput = (rate/0.004615);
				if((rate/0.004615) < worstWriteThroughput || 0 == worstWriteThroughput)
					worstWriteThroughput = (rate/0.004615);
			}

				kal_get_time(&time_1);
				

				if(i == TIMES*5) break;
			}
		}
		FS_Close(hFile);

#ifdef	CACHED_TEST
		if(KAL_TRUE == cachedTest)
			dbg_print("\r\nbest: %f, worst:%f\r\n", cachedBestWriteThroughput, cachedWorstWriteThroughput);
		else
#endif
		dbg_print("\r\nbest: %f, worst:%f\r\n", bestWriteThroughput, worstWriteThroughput);

		dbg_print("\r\n==================Write Test End(%d) ====================\r\n",count);
#endif //write

#if 1 // read test

#ifdef	CACHED_TEST
			if(KAL_TRUE == cachedTest)
				dbg_print("\r\n==========Cached Read Test Start(%d) ====================\r\n",count);
			else
#endif
		dbg_print("\r\n==================Read Test Start(%d) ====================\r\n",count);

		timeUsedinFS = 0;
		i = 0;
		total_len = 0;
		hFile = FS_Open(full_name, FS_READ_WRITE);
		if(hFile <= 0){
			dbg_print("FS open failed\r\n");
			return;
		}

		ASSERT(hFile>0);
		
		while(1){
			kal_get_time(&time_1);

#ifdef	CACHED_TEST
			if(KAL_TRUE == cachedTest)
				result = FS_Read(hFile,cached_r +offset1,LEN,&len);
			else
#endif			
			result = FS_Read(hFile,r+offset2,LEN,&len);

			kal_get_time(&time_2);
			timeUsedinFS += (time_2 - time_1);
			i++;
			total_len += len;

			if(check_read_content)
			{
#ifdef	CACHED_TEST
				if(KAL_TRUE == cachedTest){
					for(j=0;j<len;j++){
						if(cached_r[j+offset2] != cached_w[j+offset1])
						{
							dbg_print("read not the same , at: %d, %d, %d, %d \r\n", total_len, j, offset2, offset1);
							while(1);
						}
					
					}
				}
				else
#endif			
				{
					for(j=0;j<len;j++){
						if(r[j+offset2] != w[j+offset1])
						{
							dbg_print("read not the same , at: %d, %d, %d, %d \r\n", total_len, j, offset2, offset1);
							FS_Close(hFile);
							return;
						}
					
					}
				}
				dbg_print(".");
#ifdef	CACHED_TEST
			if(KAL_TRUE == cachedTest)
				memset(cached_r,0,sizeof(cached_r));
			else
#endif	
				memset(r,0,sizeof(r));
			}			
			if(result < 0){
				if(result != RTF_DISK_FULL){
					dbg_print("read fail %d, at: %d \r\n", result, total_len);
					FS_Close(hFile);
					return;
				}
				else{
					dbg_print("Disk Full \r\n");
					FS_Close(hFile);
					return;
				}
			}
			if(len != LEN){
				dbg_print("length not correct \r\n");
				FS_Close(hFile);
				return;
			}
			if(i%TIMES == 0){
				
			   rate = (double)(LEN*TIMES)/(double)timeUsedinFS;
				dbg_print("read[%d], total: %d, rate: %f \r\n", i, total_len,rate/0.004615);

#ifdef	CACHED_TEST
			if(KAL_TRUE == cachedTest){
				if((rate/0.004615) > cachedBestReadThroughput || 0 == cachedBestReadThroughput)
					cachedBestReadThroughput = (rate/0.004615);
				if((rate/0.004615) < cachedWorstReadThroughput || 0 == cachedWorstReadThroughput)
					cachedWorstReadThroughput = (rate/0.004615);
			}
			else
#endif					
			{
				if((rate/0.004615) > bestReadThroughput || 0 == bestReadThroughput)
					bestReadThroughput = (rate/0.004615);
				if((rate/0.004615) < worstReadThroughput || 0 == worstReadThroughput)
					worstReadThroughput = (rate/0.004615);
			}

				timeUsedinFS = 0;
				if(i == TIMES*5) break;
			}
		}
		FS_Close(hFile);

#ifdef	CACHED_TEST
		if(KAL_TRUE == cachedTest)
			dbg_print("\r\nbest: %f, worst:%f\r\n", cachedBestReadThroughput, cachedWorstReadThroughput);
		else
#endif
		dbg_print("\r\nbest: %f, worst:%f\r\n", bestReadThroughput, worstReadThroughput);
		
		dbg_print("\r\n==================Read Test End(%d) ====================\r\n",count);
		FS_Delete(full_name);
#endif  // read test

		testTimes ++;
		if(5 == testTimes)
			return;
	}
   //=======================================//




}
#endif

#ifdef SIM_DVT_REG_TEST
sim_reg_readCheck(kal_uint16 *regAddr, kal_uint16 regValue, char *testItem)
{
	kal_uint16	simReg;
	char			errorMessage[100];
	
	simReg = DRV_Reg(regAddr);
	if(regValue != simReg){
		kal_sprintf(errorMessage, "Error:address %x read back %x while do %s\n\r", (kal_uint32)regAddr, simReg, testItem);
		dbg_print(errorMessage);
	}
}



void sim_reg_resetCheck(kal_uint32 AddrSpace)
{
	
	sim_reg_readCheck((kal_uint16 *)(SIM_CTRL+AddrSpace),			0x0000,	"resetTest");//SIM_CTRL is SIM_CONT
	sim_reg_readCheck((kal_uint16 *)(SIM_CONF+AddrSpace),		0x0000,	"resetTest");
	sim_reg_readCheck((kal_uint16 *)(SIM_BRR+AddrSpace),			0x05d1,	"resetTest");
	sim_reg_readCheck((kal_uint16 *)(SIM_IRQEN+AddrSpace),		0x0000,	"resetTest");
	sim_reg_readCheck((kal_uint16 *)(SIM_STS+AddrSpace),			0x0000,	"resetTest");
	sim_reg_readCheck((kal_uint16 *)(SIM_RETRY+AddrSpace),		0x0303,	"resetTest");
	sim_reg_readCheck((kal_uint16 *)(SIM_TIDE+AddrSpace),			0x0000,	"resetTest");
	sim_reg_readCheck((kal_uint16 *)(SIM_COUNT+AddrSpace),		0x0000,	"resetTest");
	sim_reg_readCheck((kal_uint16 *)(SIM_ATIME+AddrSpace),		0xAFC7,	"resetTest");
	sim_reg_readCheck((kal_uint16 *)(SIM_DTIME+AddrSpace),		0x03E7,	"resetTest");
	sim_reg_readCheck((kal_uint16 *)(SIM_TOUT+AddrSpace),			0x0983,	"resetTest");//SIM_TOUT is SIM_WTIME
	sim_reg_readCheck((kal_uint16 *)(SIM_base+0x4C+AddrSpace),	0x000A,	"resetTest");//SIM+004Ch is SIM_GTIME
	sim_reg_readCheck((kal_uint16 *)(SIM_base+0x50+AddrSpace),	0x000F,	"resetTest");//SIM+0050h is SIM_ETIME
	sim_reg_readCheck((kal_uint16 *)(SIM_INS+AddrSpace),			0x0000,	"resetTest");
	sim_reg_readCheck((kal_uint16 *)(SIM_IMP3+AddrSpace),			0x0000,	"resetTest");//SIM_IMP3 is SIM_P3
	sim_reg_readCheck((kal_uint16 *)(SIM_SW1+AddrSpace),			0x0000,	"resetTest");
	sim_reg_readCheck((kal_uint16 *)(SIM_SW2+AddrSpace),			0x0000,	"resetTest");
	sim_reg_readCheck((kal_uint16 *)(SIM_base+0x70+AddrSpace),	0x0001,	"resetTest");//SIM+0070h is SIM_ATRSTA
	sim_reg_readCheck((kal_uint16 *)(SIM_base+0x74+AddrSpace),	0x0001,	"resetTest");//SIM+0074h is SIM_T0STA
	
}




void sim_reg_RAWCheck(kal_uint32 AddrSpace)
{
#ifdef __OLD_PDN_ARCH__
	DRVPDN_Disable(DRVPDN_CON1,DRVPDN_CON1_SIM,PDN_SIM);
#else
	DRVPDN_Disable(PDN_SIM);
#endif
	
	
	DRV_WriteReg((SIM_CTRL+AddrSpace), 0xAAAA);
	sim_reg_readCheck((kal_uint16 *)(SIM_CTRL+AddrSpace),			0x0002,	"RAWCheck_1");
	DRV_WriteReg((SIM_CTRL+AddrSpace), 0x0000);
	DRV_WriteReg((SIM_CTRL+AddrSpace), 0x5555);
	sim_reg_readCheck((kal_uint16 *)(SIM_CTRL+AddrSpace),			0x0001,	"RAWCheck_2");
	DRV_WriteReg((SIM_CTRL+AddrSpace), 0x0000);

	DRV_WriteReg((SIM_CONF+AddrSpace), 0xAAAA);
	sim_reg_readCheck((kal_uint16 *)(SIM_CONF+AddrSpace),		0x02aa,	"RAWCheck_3");
	DRV_WriteReg((SIM_CONF+AddrSpace), 0x0000);
	DRV_WriteReg((SIM_CONF+AddrSpace), 0x5555);
	sim_reg_readCheck((kal_uint16 *)(SIM_CONF+AddrSpace),		0x0555,	"RAWCheck_4");
	DRV_WriteReg((SIM_CONF+AddrSpace), 0x0000);

	DRV_WriteReg((SIM_BRR+AddrSpace), 0xAAAA);
	sim_reg_readCheck((kal_uint16 *)(SIM_BRR+AddrSpace),			0x02aa,	"RAWCheck_5");
	DRV_WriteReg((SIM_BRR+AddrSpace), 0x0000);
	DRV_WriteReg((SIM_BRR+AddrSpace), 0x5555);
	sim_reg_readCheck((kal_uint16 *)(SIM_BRR+AddrSpace),			0x0555,	"RAWCheck_6");
	DRV_WriteReg((SIM_BRR+AddrSpace), 0x0000);

	DRV_WriteReg((SIM_IRQEN+AddrSpace), 0xAAAA);
	sim_reg_readCheck((kal_uint16 *)(SIM_IRQEN+AddrSpace),		0x02aa,	"RAWCheck_7");
	DRV_WriteReg((SIM_IRQEN+AddrSpace), 0x0000);
	DRV_WriteReg((SIM_IRQEN+AddrSpace), 0x5555);
	sim_reg_readCheck((kal_uint16 *)(SIM_IRQEN+AddrSpace),		0x0555,	"RAWCheck_8");
	DRV_WriteReg((SIM_IRQEN+AddrSpace), 0x0000);

	DRV_WriteReg((SIM_STS+AddrSpace), 0xAAAA);
	sim_reg_readCheck((kal_uint16 *)(SIM_STS+AddrSpace),			0x0000,	"RAWCheck_9");
	DRV_WriteReg((SIM_STS+AddrSpace), 0x0000);
	DRV_WriteReg((SIM_STS+AddrSpace), 0x5555);
	sim_reg_readCheck((kal_uint16 *)(SIM_STS+AddrSpace),			0x0000,	"RAWCheck_10");
	DRV_WriteReg((SIM_STS+AddrSpace), 0x0000);

	DRV_WriteReg((SIM_RETRY+AddrSpace), 0xAAAA);
	sim_reg_readCheck((kal_uint16 *)(SIM_RETRY+AddrSpace),		0x0202,	"RAWCheck_11");
	DRV_WriteReg((SIM_RETRY+AddrSpace), 0x0000);
	DRV_WriteReg((SIM_RETRY+AddrSpace), 0x5555);
	sim_reg_readCheck((kal_uint16 *)(SIM_RETRY+AddrSpace),		0x0505,	"RAWCheck_12");
	DRV_WriteReg((SIM_RETRY+AddrSpace), 0x0000);

	DRV_WriteReg((SIM_TIDE+AddrSpace), 0xAAAA);
	sim_reg_readCheck((kal_uint16 *)(SIM_TIDE+AddrSpace),			0x0a0a,	"RAWCheck_13");
	DRV_WriteReg((SIM_TIDE+AddrSpace), 0x0000);
	DRV_WriteReg((SIM_TIDE+AddrSpace), 0x5555);
	sim_reg_readCheck((kal_uint16 *)(SIM_TIDE+AddrSpace),			0x0505,	"RAWCheck_14");
	DRV_WriteReg((SIM_TIDE+AddrSpace), 0x0000);

	DRV_WriteReg((SIM_COUNT+AddrSpace), 0xAAAA);
	sim_reg_readCheck((kal_uint16 *)(SIM_COUNT+AddrSpace),		0x0000,	"RAWCheck_15");
	DRV_WriteReg((SIM_COUNT+AddrSpace), 0x0000);
	DRV_WriteReg((SIM_COUNT+AddrSpace), 0x5555);
	sim_reg_readCheck((kal_uint16 *)(SIM_COUNT+AddrSpace),		0x0000,	"RAWCheck_16");
	DRV_WriteReg((SIM_COUNT+AddrSpace), 0x0000);

	DRV_WriteReg((SIM_ATIME+AddrSpace), 0xAAAA);
	sim_reg_readCheck((kal_uint16 *)(SIM_ATIME+AddrSpace),		0xaaaa,	"RAWCheck_17");
	DRV_WriteReg((SIM_ATIME+AddrSpace), 0x0000);
	DRV_WriteReg((SIM_ATIME+AddrSpace), 0x5555);
	sim_reg_readCheck((kal_uint16 *)(SIM_ATIME+AddrSpace),		0x5555,	"RAWCheck_18");
	DRV_WriteReg((SIM_ATIME+AddrSpace), 0x0000);

	DRV_WriteReg((SIM_DTIME+AddrSpace), 0xAAAA);
	sim_reg_readCheck((kal_uint16 *)(SIM_DTIME+AddrSpace),		0x0aaa,	"RAWCheck_19");
	DRV_WriteReg((SIM_DTIME+AddrSpace), 0x0000);
	DRV_WriteReg((SIM_DTIME+AddrSpace), 0x5555);
	sim_reg_readCheck((kal_uint16 *)(SIM_DTIME+AddrSpace),		0x0555,	"RAWCheck_20");
	DRV_WriteReg((SIM_DTIME+AddrSpace), 0x0000);
	
	DRV_WriteReg((SIM_TOUT+AddrSpace), 0xAAAA);
	sim_reg_readCheck((kal_uint16 *)(SIM_TOUT+AddrSpace),			0xAAAA,	"RAWCheck_21");
	DRV_WriteReg((SIM_TOUT+AddrSpace), 0x0000);
	DRV_WriteReg((SIM_TOUT+AddrSpace), 0x5555);
	sim_reg_readCheck((kal_uint16 *)(SIM_TOUT+AddrSpace),			0x5555,	"RAWCheck_22");
	DRV_WriteReg((SIM_TOUT+AddrSpace), 0x0000);

	DRV_WriteReg((SIM_base+0x4C+AddrSpace), 0xAAAA);
	sim_reg_readCheck((kal_uint16 *)(SIM_base+0x4C+AddrSpace),	0x000a,	"RAWCheck_23");
	DRV_WriteReg((SIM_base+0x4C+AddrSpace), 0x0000);
	DRV_WriteReg((SIM_base+0x4C+AddrSpace), 0x5555);
	sim_reg_readCheck((kal_uint16 *)(SIM_base+0x4C+AddrSpace),	0x0005,	"RAWCheck_24");
	DRV_WriteReg((SIM_base+0x4C+AddrSpace), 0x0000);

	DRV_WriteReg((SIM_base+0x50+AddrSpace), 0xAAAA);
	sim_reg_readCheck((kal_uint16 *)(SIM_base+0x50+AddrSpace),	0x002a,	"RAWCheck_25");
	DRV_WriteReg((SIM_base+0x50+AddrSpace), 0x0000);
	DRV_WriteReg((SIM_base+0x50+AddrSpace), 0x5555);
	sim_reg_readCheck((kal_uint16 *)(SIM_base+0x50+AddrSpace),	0x0015,	"RAWCheck_26");
	DRV_WriteReg((SIM_base+0x50+AddrSpace), 0x0000);

	DRV_WriteReg((SIM_INS+AddrSpace), 0xAAAA);
	sim_reg_readCheck((kal_uint16 *)(SIM_INS+AddrSpace),			0x00aa,	"RAWCheck_27");
	DRV_WriteReg((SIM_INS+AddrSpace), 0x0000);
	DRV_WriteReg((SIM_INS+AddrSpace), 0x5555);
	sim_reg_readCheck((kal_uint16 *)(SIM_INS+AddrSpace),			0x0155,	"RAWCheck_28");
	DRV_WriteReg((SIM_INS+AddrSpace), 0x0000);

	DRV_WriteReg((SIM_IMP3+AddrSpace), 0xAAAA);
	sim_reg_readCheck((kal_uint16 *)(SIM_IMP3+AddrSpace),			0x00aa,	"RAWCheck_29");
	DRV_WriteReg((SIM_IMP3+AddrSpace), 0x0000);
	DRV_WriteReg((SIM_IMP3+AddrSpace), 0x5555);
	sim_reg_readCheck((kal_uint16 *)(SIM_IMP3+AddrSpace),			0x0055,	"RAWCheck_30");
	DRV_WriteReg((SIM_IMP3+AddrSpace), 0x0000);

	DRV_WriteReg((SIM_SW1+AddrSpace), 0xAAAA);
	sim_reg_readCheck((kal_uint16 *)(SIM_SW1+AddrSpace),			0x0000,	"RAWCheck_31");
	DRV_WriteReg((SIM_SW1+AddrSpace), 0x0000);
	DRV_WriteReg((SIM_SW1+AddrSpace), 0x5555);
	sim_reg_readCheck((kal_uint16 *)(SIM_SW1+AddrSpace),			0x0000,	"RAWCheck_32");
	DRV_WriteReg((SIM_SW1+AddrSpace), 0x0000);

	DRV_WriteReg((SIM_SW2+AddrSpace), 0xAAAA);
	sim_reg_readCheck((kal_uint16 *)(SIM_SW2+AddrSpace),			0x0000,	"RAWCheck_33");
	DRV_WriteReg((SIM_SW2+AddrSpace), 0x0000);
	DRV_WriteReg((SIM_SW2+AddrSpace), 0x5555);
	sim_reg_readCheck((kal_uint16 *)(SIM_SW2+AddrSpace),			0x0000,	"RAWCheck_34");
	DRV_WriteReg((SIM_SW2+AddrSpace), 0x0000);

}
#endif

#ifdef DRV_SIM_BT
kal_uint32 tempReg;
kal_uint32 sim_bt_testingSIMSEL, sim_bt_currentAddrSpace;


sim_bt()
{	
	kal_uint32 loopIndex1, loopIndex2;
	kal_uint16 regValue;
	kal_uint32 baseAddrSpace, currentAddrSpace;
	kal_uint32 time1=0;
	kal_uint32 time2; //time2 is used to calculate total execution time in this function for specific setting

	dbg_print("sim_bt start\n\r");

	/*disable interrupt so that our operation won't bring up interrupt*/
	IRQMask(IRQ_SIM_CODE);
	IRQMask(IRQ_SIM2_CODE);

#if defined(MT6253) || defined(MT6253D) || defined(MT6253E) || defined(MT6253L)
	/*sim2 GPIO setting*/
	DRV_SetBits(0x80020220, 0x5000);
	DRV_SetBits(0x800203d0, 0x1);
	DRV_ClearBits(0x80020090, 0xc000);
	DRV_ClearBits(0x80020390, 0x1);
#endif

#ifdef __OLD_PDN_ARCH__
	DRVPDN_Disable(DRVPDN_CON0,DRVPDN_CON0_SIM2,PDN_SIM2);
	DRVPDN_Disable(DRVPDN_CON1,DRVPDN_CON1_SIM,PDN_SIM);
#else
	DRVPDN_Disable(PDN_SIM2);
	DRVPDN_Disable(PDN_SIM);
#endif
	
	baseAddrSpace = SIM2_base - SIM_base;
	
	/*power on SIM1, do APB read/ write test*/



	currentAddrSpace = sim_bt_currentAddrSpace;
	//sim_bt_currentAddrSpace = 0;
	//sim_bt_testingSIMSEL = 0;




#ifdef SIM_DVT_REG_TEST
	sim_reg_resetCheck(0);
	sim_reg_RAWCheck(0);
	sim_reg_resetCheck(baseAddrSpace);
	sim_reg_RAWCheck(baseAddrSpace);
#endif

test:

	/*set SIMSEL = 1.8V or 3V, turn on SIMIF activation procedure*/
	if(sim_bt_testingSIMSEL){
		DRV_SetBits(SIM_CONF+currentAddrSpace, SIM_CONF_SIMSEL);
	}
	else{
		DRV_ClearBits(SIM_CONF+currentAddrSpace, SIM_CONF_SIMSEL);
	}
	
	/*76 VSIM2 has some issue and need to turn on via PMIC*/
#if defined(MT6276) || defined(MT6573)
	if(currentAddrSpace){ //sim2
		if(sim_bt_testingSIMSEL)
			pmic_adpt_set_vsim2(PMIC_VSIM_3_0);
		else
			pmic_adpt_set_vsim2(PMIC_VSIM_1_8);
	}
	pmic_adpt_vsim_enable(KAL_TRUE);
#endif
	
	time2 = drv_get_current_time();
	
	DRV_WriteReg(SIM_BRR+currentAddrSpace, 0x5D1);
	DRV_WriteReg(SIM_RETRY+currentAddrSpace, 0x303);
	DRV_WriteReg(SIM_ATIME+currentAddrSpace, 0x30);
	DRV_WriteReg(SIM_DTIME+currentAddrSpace, 0x30);
	DRV_WriteReg(SIM_TOUT+currentAddrSpace, 0x983);
	DRV_WriteReg(SIM_base+0x4C+currentAddrSpace, 0xA);
	DRV_WriteReg(SIM_base+0x50+currentAddrSpace, 0xF);
	DRV_WriteReg(SIM_CTRL+currentAddrSpace, SIM_CTRL_SIMON);

	//since 53, 36 has interrupt disappear issue, we can't keep polling here, we delay a absolutly time then polling the bit
	loopIndex2 = 0;
	time1 = drv_get_current_time();
	while(0x100 > drv_get_duration_tick(time1 ,drv_get_current_time()) && 0x400000 > loopIndex2)
			loopIndex2 ++;

	/*set to speed64 to reduce testing time*/
	DRV_WriteReg(SIM_BRR+currentAddrSpace, 0x101);
	
	loopIndex2 = 0;
	/*wait until activation done*/
	while(0x100 != DRV_Reg(SIM_base+0x70+currentAddrSpace) && 0x400000 > loopIndex2)
			loopIndex2 ++;

		
	/*clear IRQ, and FIFO, and configure other register settings*/
	tempReg = DRV_Reg(SIM_STS+currentAddrSpace);
	DRV_WriteReg(SIM_COUNT+currentAddrSpace, 0);
	DRV_WriteReg(SIM_TIDE+currentAddrSpace, 0x0101);
	DRV_SetBits(SIM_IRQEN+currentAddrSpace, SIM_IRQEN_TX);
	
	/*write FIFO, and wait TXTIDE interrupt, repeat 10 times*/
	for(loopIndex1 = 0; 10 > loopIndex1; loopIndex1++){
		regValue = DRV_Reg(SIM_STS+currentAddrSpace);
		for (loopIndex2 = 0; 30 >loopIndex2; loopIndex2++){
			DRV_WriteReg8(SIM_DATA+currentAddrSpace, 0x5a);

		}
		
		loopIndex2 = 0;
		while(SIM_STS_TX != DRV_Reg(SIM_STS+currentAddrSpace))
			loopIndex2 ++;
		//dbg_print("SIM TXTIDE trigger when loop %d\n\r", loopIndex2);
	}

	/*set bigger TXTIDE, repeat write FIFO and read FIFO 10 times*/
	DRV_WriteReg(SIM_TIDE+currentAddrSpace, 0x0F0F);
	for(loopIndex1 = 0; 10 > loopIndex1; loopIndex1++){

		for (loopIndex2 = 0; 30 >loopIndex2; loopIndex2++){
			DRV_WriteReg8(SIM_DATA+currentAddrSpace, 0x5a);
		}
		for (loopIndex2 = 0; 30 >loopIndex2; loopIndex2++){
			regValue = DRV_Reg8(SIM_DATA+currentAddrSpace);
		}
	}

	/*from MT6236, ACD comment to keep specific voltage for enough duration*/
	if(0 == sim_bt_currentAddrSpace && 0 == sim_bt_testingSIMSEL){ /*test SIM1 1.8V end*/
		while(100 > drv_get_duration_ms(time2));
	}
	else if(0 == sim_bt_currentAddrSpace && 1 == sim_bt_testingSIMSEL){/*test SIM1 3V end*/
		while(100 > drv_get_duration_ms(time2));
	}
	else{ /*SIM2 1.8V or 3V*/
		while(80 > drv_get_duration_ms(time2));
		
		/*GPIO mode test*/
		//following is the chip dependent test code from ACD analog designer, we use chip version to seperate it
#ifdef MT6236
		time2 = drv_get_current_time();
		/*
		0x801B089C=0x1 --> enable SIM2 GPIO mode
		0x801D0040=0xE --> set SCLK2/SRST2/SIO2 as GPO
		0x801D0680=0x15 --> remove GPIO gating function
		0x801D0440=0x0->0xE --> repeat toggle data for SCLK2/SRST2/SIO2

		0x801D0040=0x0 --> set SCLK2/SRST2/SIO2 as GPI repeat toggle SIM2 GPIO mode between GPO and GPI
		*/

		DRV_WriteReg32(0x801B089C, 0x1);
		//DRV_ClearBits32(0x801D0680, 0x54); //set to GPIO mode
//		DRV_WriteReg32(0x801D0680, 0x15);
		
		while(20 > drv_get_duration_ms(time2)){
			volatile kal_uint32 regValueTemp;
			DRV_SetBits32(0x801D0040, 0xE); //output mode
			DRV_SetBits32(0x801D0440, 0xE); //output all 1
			DRV_ClearBits32(0x801D0440, 0xE); //ouput all 0
			DRV_ClearBits32(0x801D0040, 0xE); //input mode
			regValueTemp = DRV_Reg32(0x801D0540); //read input register to read back data
			regValueTemp = DRV_Reg32(0x801D0540);
		}
		
		DRV_WriteReg32(0x801B089C, 0x0); //change back to SIM mode
//		DRV_SetBits32(0x801D0680, 0x54); //change GPIO back to SIM mode
#endif
	}


	/*deactivate SIMIF*/
	Drv_WriteReg(SIM_IRQEN+currentAddrSpace, SIM_IRQEN_SIMOFF);
	DRV_WriteReg(SIM_CTRL+currentAddrSpace, 0);

	//since 53, 36 has interrupt disappear issue, we can't keep polling here, we delay a absolutly time then polling the bit
	loopIndex2 = 0;
	time1 = drv_get_current_time();
	while(0x100 > drv_get_duration_tick(time1 ,drv_get_current_time()) && 0x400000 > loopIndex2)
			loopIndex2 ++;

	/*wait until deactivation done*/
	loopIndex2 = 0;
	while(SIM_STS_SIMOFF != DRV_Reg(SIM_STS+currentAddrSpace) && 0x400000 > loopIndex2)
			loopIndex2 ++;
	if(0x400000 == loopIndex2)
		ASSERT(0);

#if defined(MT6276) || defined(MT6573)
	if(currentAddrSpace){ //sim2
		pmic_adpt_vsim_enable(KAL_FALSE);
	}
#endif

	/*SIM1 1.8V -> SIM1 3V -> SIM2 1.8V -> SIM2 3V*/

	if(0 == sim_bt_currentAddrSpace && 0 == sim_bt_testingSIMSEL){ /*test SIM1 1.8V end, change to 3V*/
		sim_bt_testingSIMSEL = 1;
		//goto test;
	}
	else if(0 == sim_bt_currentAddrSpace && 1 == sim_bt_testingSIMSEL){/*test SIM1 3V end, change to test SIM2 1.8V*/
		sim_bt_currentAddrSpace = baseAddrSpace;
		sim_bt_testingSIMSEL = 0;
		//goto test;
	}
	else if(baseAddrSpace == sim_bt_currentAddrSpace && 0 == sim_bt_testingSIMSEL){/*test SIM1 3V end, change to test SIM2 1.8V*/
		sim_bt_currentAddrSpace = baseAddrSpace;
		sim_bt_testingSIMSEL = 1;
		//goto test;
	}
	else{ /*SIM2 3V end, goto SIM1 1.8V*/
		sim_bt_currentAddrSpace = 0;
		sim_bt_testingSIMSEL = 0;
		
	}

	dbg_print("sim_bt end\n\r");
}
#endif

#ifdef MSDC_SDIO_DVT
extern void test_sdio_ini(void );

void MSDC_DVT_SDIO_test(void)
{
	test_sdio_ini();
}
#endif

#ifdef MSDC2_SDIO_DVT
extern void test_sdio_ini(void );

void MSDC2_DVT_SDIO_test(void)
{
	test_sdio_ini();
}
#endif

#ifdef __MSDC_BASIC_LOAD__
void ssdbg1_main ( task_entry_struct * task_entry_ptr )
{
   ilm_struct current_ilm;
   ssdbg1_localpara_struct *paraptr;
   kal_uint32 my_index;
   double	bestReadThroughput4Bit, worstReadThroughput4Bit, bestWriteThroughput4Bit, worstWriteThroughput4Bit;

#ifdef SIM_DVT_REG_TEST
   sim_reg_resetCheck();
   sim_reg_RAWCheck();
#endif

#ifdef MSDC_SDIO_DVT
   MSDC_DVT_SDIO_test();
   gMSDC_Handle->mIsInitialized = KAL_FALSE;
   waitingSDIOTest = KAL_FALSE;
#endif

   if(waitingSDIOTest){
   	kal_sleep_task(20);
   }


   kal_get_my_task_index (&my_index);
   stack_set_active_module_id ( my_index, MOD_SSDBG1 );

   /* Initialize ILM, and timer */
   stack_init_timer(&ssdbg1_context.ssdbg1_timer0, "SSDBG1 Timer0", MOD_SSDBG1);

   stack_start_timer(&ssdbg1_context.ssdbg1_timer0, 0, 10);

	MSDC_GetCardStatus(&MSDC_Blk[0], 0);
	MSDC_DVT_readWrite();
   while ( 1 ) {

	//MSDC_DVT_sleepModeCardDetectionTestMT6268A();
      //receive_msg_ext_q(task_info_g[task_entry_ptr->task_indx].task_ext_qid, &current_ilm );
      //msg_receive_extq(task_info_g[task_entry_ptr->task_indx].task_ext_qid, &current_ilm );
      msg_receive_extq(&current_ilm);

      switch (current_ilm.msg_id) {
      case MSG_ID_MSDC_CARD_DETECT_IND:
      	  MSDC_GetCardStatus(&MSDC_Blk[0], 0);
      	  bestReadThroughput = 0;
      	  worstReadThroughput = 0;
      	  bestWriteThroughput = 0;
      	  worstWriteThroughput = 0;
      	  dbg_print("card plug in/out");
      	  MSDC_Blk[0].trySingleLine = KAL_FALSE;
         MSDC_DVT_readWrite();
         bestReadThroughput4Bit = bestReadThroughput;
      	  bestReadThroughput = 0;
      	  worstReadThroughput4Bit = worstReadThroughput;
      	  worstReadThroughput = 0;
      	  bestWriteThroughput4Bit = bestWriteThroughput;
      	  bestWriteThroughput = 0;
      	  worstWriteThroughput4Bit = worstWriteThroughput;
      	  worstWriteThroughput = 0;
      	  MSDC_Blk[0].trySingleLine = KAL_TRUE;
      	  MSDC_Blk[0].mIsInitialized = KAL_FALSE;
         MSDC_DVT_readWrite();
         
         dbg_print("4 bit mode:");
         dbg_print("\r\nwrite best: %f, worst:%f\r\n", bestWriteThroughput4Bit, worstWriteThroughput4Bit);
         dbg_print("\r\nread best: %f, worst:%f\r\n", bestReadThroughput4Bit, worstReadThroughput4Bit);
         dbg_print("1 bit mode:");
         dbg_print("\r\nwrite best: %f, worst:%f\r\n", bestWriteThroughput, worstWriteThroughput);
         dbg_print("\r\nread best: %f, worst:%f\r\n", bestReadThroughput, worstReadThroughput);
         break;
      default:
         break;
      }
      free_ilm(&current_ilm);
   }
}
#endif

#ifdef __MSDC_BASIC_LOAD__
#ifdef DRV_MSDC_MT6238_SERIES
void MSDC2_DVT_readWrite(void);


void
ssdbg2_main ( task_entry_struct * task_entry_ptr )
{
   ilm_struct current_ilm;
   ssdbg1_localpara_struct *paraptr;
   kal_uint32 my_index;


#ifdef MSDC2_SDIO_DVT
   MSDC2_DVT_SDIO_test();
   msdc2_handle->mIsInitialized = KAL_FALSE;
   waitingSDIOTest = KAL_FALSE;
#endif

   if(waitingSDIOTest){
   	kal_sleep_task(20);
   }


   kal_get_my_task_index (&my_index);
   stack_set_active_module_id ( my_index, MOD_SSDBG2 );

   /* Initialize ILM, and timer */
   stack_init_timer(&ssdbg2_context.ssdbg2_timer0, "SSDBG2 Timer0", MOD_SSDBG2);

   stack_start_timer(&ssdbg2_context.ssdbg2_timer0, 0, 10);

	MSDC_GetCardStatus2(&MSDC_Blk[1], 0);
	MSDC2_DVT_readWrite();
   while ( 1 ) {

	//MSDC_DVT_sleepModeCardDetectionTestMT6268A();
      //receive_msg_ext_q(task_info_g[task_entry_ptr->task_indx].task_ext_qid, &current_ilm );
      //msg_receive_extq(task_info_g[task_entry_ptr->task_indx].task_ext_qid, &current_ilm );
      msg_receive_extq(&current_ilm);

      switch (current_ilm.msg_id) {
      case MSG_ID_MSDC_CARD_DETECT_IND:
      	  MSDC_GetCardStatus2(&MSDC_Blk[1], 0);
      	  dbg_print("card plug in/out");
         MSDC2_DVT_readWrite();
         break;
      default:
         break;
      }
      free_ilm(&current_ilm);
   }
}

void MSDC2_DVT_readWrite(void)
{




	kal_int32 i,j, result = 0, count = 0;
	kal_uint32 access = 17893;
	FS_HANDLE hFile=0, wFile = 0;
	kal_wchar full_name[100];
	kal_uint32  file_size,len,total_len;
	kal_uint32 time_1,time_2;
	double rate;
	volatile kal_bool format = 0;
	kal_uint8 offset1 = 0,offset2 = 0;
	kal_uint32 timeUsedinFS;
	 int card;
        kal_wchar path[10];
        FS_DiskInfo info;

	
	result = FS_TestMSDC(&MSDC_Blk[1]);
	if (result < FS_NO_ERROR)
       {
       	 dbg_print("\r\n2nd Card not found\r\n",count);
               while(1){
               	kal_sleep_task(20);
               }
       }
	card = FS_GetDrive(FS_DRIVE_V_REMOVABLE, 2, FS_NO_ALT_DRIVE);

        if (card >= FS_NO_ERROR)
        {
            kal_wsprintf(path, "%c:\\", card);

            result = FS_GetDiskInfo((WCHAR*) path, &info, FS_DI_BASIC_INFO | FS_DI_FREE_SPACE);
            if (result < RTF_NO_ERROR)
            {
            	dbg_print("\r\nget disk info of %s failed\r\n",path);
            	ASSERT(0);
            }
         
            
        }
	//DumpDiskInfo("d:\\");
	kal_wsprintf(full_name, "%c:\\Write.bin", card);
	for(i=0;i<LEN+3;i++)
	{
		w2[i+offset1] = i%256;
		r2[i+offset2] = 0;
	}

#if defined(NOT_4BYTES_ALIGN)
		// test W to B or B to W(DMA)
		offset1 = (kal_uint32)w % 4;
		if(offset1 == 0)
			offset1 = 1;
		else 
			offset1 = 0;

		offset2 = (kal_uint32)r % 4;
		if(offset2 == 0)
			offset2 = 1;
		else 
			offset2 = 0;
		for(i=0;i<LEN+3;i++)
		{
			w[i+offset1] = i%256;
			r[i+offset2] = 0;
		}
#endif

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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
	while(1){

#if 0 // read & write testing
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

#if 1//write 
		
		count++;
		//Search_Dir(L"C:\\");
		FS_Delete(full_name);
		dbg_print("\r\n==================[MSDC2]:Write Test Start(%d) ====================\r\n",count);
		hFile = FS_Open(full_name, FS_CREATE|FS_READ_WRITE);
		if(hFile <= 0)
			continue;
		//ASSERT(hFile>0);
		
#if defined(NOT_4BYTES_ALIGN)
		// test W to B or B to W(DMA)
		offset1 = (kal_uint32)w % 4;
		if(offset1 == 0)
			offset1 = 1;
		else 
			offset1 = 0;

		offset2 = (kal_uint32)r % 4;
		if(offset2 == 0)
			offset2 = 1;
		else 
			offset2 = 0;
		for(i=0;i<LEN+3;i++)
		{
			w[i+offset1] = i%256;
			r[i+offset2] = 0;
		}
#endif		
		i = 0;
		total_len = 0;
	
		kal_get_time(&time_1);
		//readSectorCount = writeSectorCount = readTime = writeTime = writeSectorCount2 = writeTime2 = 0;
		//writeTime3 = writeTime4 = writeTime5 = writeTime6 = 0;
		while(1)
		{
			
			result = FS_Write(hFile,w2+offset1,LEN,&len);
			total_len += len;
			i++;
			if(result < 0 ){
				if(result == RTF_DISK_FULL)
					dbg_print("[MSDC2]:Disk Full %d\r\n", total_len);
				else
					dbg_print("[MSDC2]:write fail %d at: %d \r\n",result, total_len);

				break;
			}
			if(len != LEN)
				break;
			if(i%TIMES == 0)
			{
				kal_get_time(&time_2);
			   rate = (double)(LEN*TIMES)/(double)(time_2-time_1);
				dbg_print("[MSDC2]:write[%d], total: %d, rate %f \r\n", i, total_len,rate/0.004615);
				//dbg_print("%d, %d, %d , %d\r\n", writeTime3 , writeTime4 , writeTime5,writeTime6);
				//readSectorCount = writeSectorCount = readTime = writeTime = writeSectorCount2 = writeTime2= 0;
				//writeTime3 = writeTime4 = writeTime5 = writeTime6 = 0;
				kal_get_time(&time_1);

				if(i == TIMES*5) break;
			}
		}
		FS_Close(hFile);
		dbg_print("\r\n==================[MSDC2]:Write Test End(%d) ====================\r\n",count);
#endif //write

#if 1 // read test
		dbg_print("\r\n==================[MSDC2]:Read Test Start(%d) ====================\r\n",count);
		timeUsedinFS = 0;
		i = 0;
		total_len = 0;
		hFile = FS_Open(full_name, FS_READ_WRITE);
		if(hFile <= 0)
			continue;

		ASSERT(hFile>0);
		while(1){
			kal_get_time(&time_1);
			result = FS_Read(hFile,r2+offset2,LEN,&len);
			kal_get_time(&time_2);
			timeUsedinFS += (time_2 - time_1);
			i++;
			total_len += len;

			if(check_read_content)
			{
				for(j=0;j<len;j++){
					if(r2[j+offset2] != w2[j+offset1])
					{
						dbg_print("[MSDC2]:read not the same , at: %d \r\n", total_len);
						while(1);
					}
					
				}
				//dbg_print(".");
				memset(r2,0,sizeof(r2));
			}			
			if(result < 0){
				if(result != RTF_DISK_FULL)
					dbg_print("[MSDC2]:read fail %d, at: %d \r\n", result, total_len);
				else
					dbg_print("[MSDC2]:Disk Full \r\n");
			}
			if(len != LEN)
				break;
			if(i%TIMES == 0){
				
			   rate = (double)(LEN*TIMES)/(double)timeUsedinFS;
				dbg_print("[MSDC2]:read[%d], total: %d, rate: %f \r\n", i, total_len,rate/0.004615);
				timeUsedinFS = 0;
				if(i == TIMES*5) break;
			}
		}
		FS_Close(hFile);
		dbg_print("\r\n==================[MSDC2]:Read Test End(%d) ====================\r\n",count);
		FS_Delete(full_name);
#endif  // read test
	}
   //=======================================//





}
#else
void ssdbg2_main ( task_entry_struct * task_entry_ptr )
{
}
#endif
#endif

#else //this is the original MSDC test code full set

void ssdbg1_main ( task_entry_struct * task_entry_ptr )

{

	

#ifdef MULTIPLE_WRITE_TEST
	gMSDC_Handle->mIsPresent = KAL_TRUE;
	simple_multi_write_test();
	return;
#endif

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
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

//MSDC_Initialize();
//SD_Initialize();




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

{
	kal_int32 i,j, result = 0, count = 0;
	kal_uint32 access = 17893;
	FS_HANDLE hFile=0, wFile = 0;
	kal_wchar full_name[100];
	kal_uint32  file_size,len,total_len;
	kal_uint32 time_1,time_2;
	double rate;
	volatile kal_bool format = 0;
	kal_uint8 offset1 = 0,offset2 = 0;
	kal_uint32 timeUsedinFS;
	 int card;
        kal_uint8 path[10];
        FS_DiskInfo info;

	#if 0 //defined(MTK_FORMAT)
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
	
#ifdef TRANSCEND_CARD_ISSUE
	j = 0;
	if(gMSDC_Handle->mIsInitialized){
		while(1){
			result = FS_SdDrv.ReadSectors(gMSDC_Handle,0x200,4,w);
			//result = FS_SdDrv.ReadSectors(gMSDC_Handle,0x100000,4,w);
			//result = FS_SdDrv.ReadSectors(gMSDC_Handle,0x700000,4,w);
			result = FS_SdDrv.ReadSectors(gMSDC_Handle,0xf02c80,4,w);
			/*
			for(i = 0; i<10; i++){
				w[i] = w[i]+1;
			}
			result = FS_SdDrv.WriteSectors(gMSDC_Handle,0xf04c80,4,w);
			result = FS_SdDrv.ReadSectors(gMSDC_Handle,0xf04c80,4,r);
			*/
			for(i = 0; i<10; i++){
				if(w[i] !=  x[i]){
					dbg_print("%d-th byte has different in %d-th turn,%d, %d\r\n", i,j+1,result,clkNeedB4Data);
				}	
			}
			if(w[0] != x[0]){
				errorCount ++;
				dbg_print("error rate %d/%d\r\n",errorCount, j);
			}
			j++;
			if((j & 0xff) == 0){
				dbg_print("finish %d-th turns\r\n", j);
			}
			
		}

	}
	else{
		while(1);
	}
#endif

#ifdef WRITE_ALL_ZERO_DATA
	j = 0;
	//if(gMSDC_Handle->mIsInitialized){
		DumpDiskInfo("d:\\");
		/*make all zero data*/
		kal_mem_set(allZeroDataArray, 0, 512);
		i = min(gSD->mCSD.capacity/512, 50);
		for (j=0; j<i; j++){
			result = FS_SdDrv.WriteSectors(gMSDC_Handle,j,1,allZeroDataArray);
			if(0 != result){
				dbg_print("write %d-th sector fail \r\n", j);
				break;
			}
		}
		if(0 == result){
			dbg_print("clear all sector to zero doen\r\n");
		}
		while(1);
	
	//}
	//else{
	//	while(1);
	//}
#endif


	result = FS_TestMSDC(gMSDC_Handle);
	if(result < FS_NO_ERROR){
		dbg_print("memory card card not present %d !!\r\n", result);
        	while(1)
        		kal_sleep_task(1000);
	}
	
	card = FS_GetDrive(FS_DRIVE_V_REMOVABLE, 1, FS_NO_ALT_DRIVE);

        if (card >= FS_NO_ERROR)
        {
            kal_wsprintf((WCHAR*) path, "%c:\\", card);

            result = FS_GetDiskInfo((WCHAR*) path, &info, FS_DI_BASIC_INFO | FS_DI_FREE_SPACE);
            if (result < RTF_NO_ERROR)
            {
            	ASSERT(0);
            }
         
            
        }
        else{
        	dbg_print("memory card card not present!!\r\n");
        	while(1)
        		kal_sleep_task(1000);
        }

#ifdef HW_FAST_FORMAT_TEST
	while(1){
		time_1 = drv_get_current_time();
		result = FS_GeneralFormat((WCHAR*) path, FS_FORMAT_HIGH, NULL);
		if(FS_NO_ERROR == result){
			time_2 = drv_get_current_time();
			dbg_print("format done %d, %f\n\r", time_2 - time_1, (double)(0.0005 * writeSectorsCount * 32000)/(double)(writeTimeCount));
			writeSectorsCount = writeTimeCount = 0;
			kal_sleep_task(1500);
		}
		else{
			dbg_print("format failed: %d \n\r", result);
			while(1)
        			kal_sleep_task(1000);

		}
	}
#endif
	//DumpDiskInfo("d:\\");
	kal_wsprintf(full_name, "%c:\\Write.bin", card);
	for(i=0;i<LEN+3;i++)
	{
		w[i+offset1] = i%256;
		r[i+offset2] = 0;

#ifdef	CACHED_TEST
		cached_w[i+offset1] = i%256;
		cached_r[i+offset2] = 0;		
#endif

	}

#if defined(NOT_4BYTES_ALIGN)
		// test W to B or B to W(DMA)
		offset1 = (kal_uint32)w % 4;
		if(offset1 == 0)
			offset1 = 1;
		else 
			offset1 = 0;

		offset2 = (kal_uint32)r % 4;
		if(offset2 == 0)
			offset2 = 1;
		else 
			offset2 = 0;
		for(i=0;i<LEN+3;i++)
		{
			w[i+offset1] = i%256;
			r[i+offset2] = 0;
		}
#endif

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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

	while(1){

#if 0 // read & write testing
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

#if 1//write 
		
		count++;
		//Search_Dir(L"C:\\");
		FS_Delete(full_name);
#ifdef	CACHED_TEST
			if(KAL_TRUE == cachedTest)
				cachedTest = KAL_FALSE;
			else
				cachedTest = KAL_TRUE;

			if(KAL_TRUE == cachedTest)
				dbg_print("\r\n===========Cached Write Test Start(%d) ====================\r\n",count);
			else
#endif		
		dbg_print("\r\n==================Write Test Start(%d) ====================\r\n",count);

		hFile = FS_Open(full_name, FS_CREATE|FS_READ_WRITE);
		if(hFile <= 0)
			continue;
		//ASSERT(hFile>0);
		
#if defined(NOT_4BYTES_ALIGN)
		// test W to B or B to W(DMA)
		offset1 = (kal_uint32)w % 4;
		if(offset1 == 0)
			offset1 = 1;
		else 
			offset1 = 0;

		offset2 = (kal_uint32)r % 4;
		if(offset2 == 0)
			offset2 = 1;
		else 
			offset2 = 0;
		for(i=0;i<LEN+3;i++)
		{
			w[i+offset1] = i%256;
			r[i+offset2] = 0;
		}
#endif		
		i = 0;
		total_len = 0;
	
		kal_get_time(&time_1);
		//readSectorCount = writeSectorCount = readTime = writeTime = writeSectorCount2 = writeTime2 = 0;
		//writeTime3 = writeTime4 = writeTime5 = writeTime6 = 0;
		while(1)
		{

#ifdef	CACHED_TEST
			if(KAL_TRUE == cachedTest)
				result = FS_Write(hFile,cached_w+offset1,LEN,&len);
			else
#endif
			result = FS_Write(hFile,w+offset1,LEN,&len);
			total_len += len;
			i++;
			if(result < 0 ){
				if(result == RTF_DISK_FULL)
					dbg_print("Disk Full %d\r\n", total_len);
				else
					dbg_print("write fail %d at: %d \r\n",result, total_len);

				break;
			}
			if(len != LEN)
				break;
			if(i%TIMES == 0)
			{
				kal_get_time(&time_2);
			   rate = (double)(LEN*TIMES)/(double)(time_2-time_1);
				dbg_print("write[%d], total: %d, rate %f \r\n", i, total_len,rate/0.004615);
				//dbg_print("%d, %d, %d , %d\r\n", writeTime3 , writeTime4 , writeTime5,writeTime6);
				//readSectorCount = writeSectorCount = readTime = writeTime = writeSectorCount2 = writeTime2= 0;
				//writeTime3 = writeTime4 = writeTime5 = writeTime6 = 0;
#ifdef	CACHED_TEST
			if(KAL_TRUE == cachedTest){
				if((rate/0.004615) > cachedBestWriteThroughput || 0 == cachedBestWriteThroughput)
					cachedBestWriteThroughput = (rate/0.004615);
				if((rate/0.004615) < cachedWorstWriteThroughput || 0 == cachedWorstWriteThroughput)
					cachedWorstWriteThroughput = (rate/0.004615);
			}
			else
#endif					
			{
				if((rate/0.004615) > bestWriteThroughput || 0 == bestWriteThroughput)
					bestWriteThroughput = (rate/0.004615);
				if((rate/0.004615) < worstWriteThroughput || 0 == worstWriteThroughput)
					worstWriteThroughput = (rate/0.004615);
			}

				kal_get_time(&time_1);
				

				if(i == TIMES*5) break;
			}
		}
		FS_Close(hFile);

#ifdef	CACHED_TEST
		if(KAL_TRUE == cachedTest)
			dbg_print("\r\nbest: %f, worst:%f\r\n", cachedBestWriteThroughput, cachedWorstWriteThroughput);
		else
#endif
		dbg_print("\r\nbest: %f, worst:%f\r\n", bestWriteThroughput, worstWriteThroughput);

		dbg_print("\r\n==================Write Test End(%d) ====================\r\n",count);
#endif //write

#if 1 // read test

#ifdef	CACHED_TEST
			if(KAL_TRUE == cachedTest)
				dbg_print("\r\n==========Cached Read Test Start(%d) ====================\r\n",count);
			else
#endif
		dbg_print("\r\n==================Read Test Start(%d) ====================\r\n",count);

		timeUsedinFS = 0;
		i = 0;
		total_len = 0;
		hFile = FS_Open(full_name, FS_READ_WRITE);
		if(hFile <= 0)
			continue;

		ASSERT(hFile>0);
		
		while(1){
			kal_get_time(&time_1);

#ifdef	CACHED_TEST
			if(KAL_TRUE == cachedTest)
				result = FS_Read(hFile,cached_r +offset1,LEN,&len);
			else
#endif			
			result = FS_Read(hFile,r+offset2,LEN,&len);

			kal_get_time(&time_2);
			timeUsedinFS += (time_2 - time_1);
			i++;
			total_len += len;

			if(check_read_content)
			{
#ifdef	CACHED_TEST
				if(KAL_TRUE == cachedTest){
					for(j=0;j<len;j++){
						if(cached_r[j+offset2] != cached_w[j+offset1])
						{
							dbg_print("read not the same , at: %d, %d, %d, %d \r\n", total_len, j, offset2, offset1);
							while(1);
						}
					
					}
				}
				else
#endif			
				{
					for(j=0;j<len;j++){
						if(r[j+offset2] != w[j+offset1])
						{
							dbg_print("read not the same , at: %d, %d, %d, %d \r\n", total_len, j, offset2, offset1);
							while(1);
						}
					
					}
				}
				dbg_print(".");
#ifdef	CACHED_TEST
			if(KAL_TRUE == cachedTest)
				memset(cached_r,0,sizeof(cached_r));
			else
#endif	
				memset(r,0,sizeof(r));
			}			
			if(result < 0){
				if(result != RTF_DISK_FULL)
					dbg_print("read fail %d, at: %d \r\n", result, total_len);
				else
					dbg_print("Disk Full \r\n");
			}
			if(len != LEN)
				break;
			if(i%TIMES == 0){
				
			   rate = (double)(LEN*TIMES)/(double)timeUsedinFS;
				dbg_print("read[%d], total: %d, rate: %f \r\n", i, total_len,rate/0.004615);

#ifdef	CACHED_TEST
			if(KAL_TRUE == cachedTest){
				if((rate/0.004615) > cachedBestReadThroughput || 0 == cachedBestReadThroughput)
					cachedBestReadThroughput = (rate/0.004615);
				if((rate/0.004615) < cachedWorstReadThroughput || 0 == cachedWorstReadThroughput)
					cachedWorstReadThroughput = (rate/0.004615);
			}
			else
#endif					
			{
				if((rate/0.004615) > bestReadThroughput || 0 == bestReadThroughput)
					bestReadThroughput = (rate/0.004615);
				if((rate/0.004615) < worstReadThroughput || 0 == worstReadThroughput)
					worstReadThroughput = (rate/0.004615);
			}

				timeUsedinFS = 0;
				if(i == TIMES*5) break;
			}
		}
		FS_Close(hFile);

#ifdef	CACHED_TEST
		if(KAL_TRUE == cachedTest)
			dbg_print("\r\nbest: %f, worst:%f\r\n", cachedBestReadThroughput, cachedWorstReadThroughput);
		else
#endif
		dbg_print("\r\nbest: %f, worst:%f\r\n", bestReadThroughput, worstReadThroughput);
		
		dbg_print("\r\n==================Read Test End(%d) ====================\r\n",count);
		FS_Delete(full_name);
#endif  // read test
	}
   //=======================================//

}
#endif

}

#endif//MSDC_DVT
#endif//__MSDC_BASIC_LOAD__
