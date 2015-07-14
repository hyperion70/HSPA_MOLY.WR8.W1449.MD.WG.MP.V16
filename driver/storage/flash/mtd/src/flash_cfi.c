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
 *   flash_cfi.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This module implements Common Flash Interface Query for NOR Flash Memory.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "kal_public_api.h" //MSBB change #include "kal_release.h"
#include "flash_opt.h"
#include "flash_cfi_internal.h"
#include "flash_cfi.h"
#include "flash_sf.h"

#if !defined(__UBL__) && ((defined(__NOR_FLASH_HARDWARE_TEST__) && defined(__MAUI_BASIC__)) || (defined(__NOR_CFI_SUPPORT__) && defined(__MTK_TARGET__) && !defined(_NAND_FLASH_BOOTING_) && !defined(__FS_SYSDRV_ON_NAND__)) )

#include "fat_fs.h"
#include "DrvFlash.h"
#include "kal_trace.h"
#include "kal_debug.h"

#define __NOR_CFI_PRINT__
// #define __NOR_CFI_DEBUG__

extern void DelayAWhile_UST(kal_uint32 delay);
extern kal_uint32 PAGE_BUFFER_SIZE;


//-----------------------------------------------------------------------------
// Message Array Entry
//-----------------------------------------------------------------------------
// Entry Structure
typedef struct tCFIStr {
    kal_uint16 id;
    const char *msg;
} TCFIStr;

// End of Debug Message (pivot)
#define CFI_END 0x1234

//-----------------------------------------------------------------------------
// Message: Algorithm Type
//-----------------------------------------------------------------------------
TCFIStr str_alg_type[] = {
    {CFI_ALG_NONE, "(None)"},
    {CFI_ALG_IntelSharpExt, "Intel/Sharp Extended"},
    {CFI_ALG_AMDFujitsu, "AMD/Fujitsu Standard"},
    {CFI_ALG_Intel, "Intel Standard"},
    {CFI_ALG_AMDFujitsuExt, "AMD/Fujitsu Extended"},
    {CFI_ALG_Winbond, "Winbond Standard"},
    {CFI_ALG_Mitsubishi, "Mistubishi Standard"},
    {CFI_ALG_MitsubishiExt, "Mistubishi Extended"},
    {CFI_ALG_SST, "SST Page Write"},
    {CFI_ALG_Intel_Perform, "Intel Performance Code"},
    {CFI_ALG_Intel_Data, "Intel Data Command"},
    {CFI_ALG_NA, "(Not Allowed)"},
    {CFI_END,"Unknown"}
};

//-----------------------------------------------------------------------------
// Message: Device Interface
//-----------------------------------------------------------------------------
TCFIStr str_dev_int[] = {
    {CFI_INT_X8, "x8-only asynchronous"},
    {CFI_INT_X16, "x16-only asynchronous"},
    {CFI_INT_X8X16, "Supports x8/x16 via BYTE# with asynchronous interface"},
    {CFI_INT_X32, "x32-only asynchronous interface"},
    {CFI_INT_X16X32, "Supports x16/x32 via WORD# with asynchronous interface"},
    {CFI_INT_NA, "(Not Allowed)"},
    {CFI_END, "Unknown"}
};

//-----------------------------------------------------------------------------
// Message: CFI Check Results
//-----------------------------------------------------------------------------
TCFIStr str_cfi_err[]={
    {CFIErr_NoError, "Pass. Please manually check the device ID."},
    {CFIErr_FATBeginUnalign, "FAT base address is not on block boundary"},
    {CFIErr_FATEndUnalign, "FAT end address is not on block boundary"},
    {CFIErr_FATSizeExceed, "FAT end address exceeds Flash size"},
    {CFIErr_ProgBufExceed, "Wrong Buffer program length"},
    {CFIErr_RegionInfoError, "RegionInfo[%d] is wrong (Block #%d)"},
    {CFIErr_RegionInfoBlkCnt, "RegionInfo[%d] block count is wrong, should be %d"},
    {CFIErr_RegionInfoBlkSize, "RegionInfo[%d] block size is wrong, should be 0x%x"},
    {CFIErr_BankInfoBnkCnt, "BankInfo[%d] bank count is wrong, should be %d"},
    {CFIErr_BankInfoBnkSize, "BankInfo[%d] bank size is wrong, should be 0x%x"},
    {CFIErr_NotAvailable, "The device does not support CFI. Please manually check the device ID."}
};

//-----------------------------------------------------------------------------
// External Functions / Predefines
//-----------------------------------------------------------------------------
extern kal_uint32       SaveAndSetIRQMask( void );
extern void             RestoreIRQMask(kal_uint32 irq);
extern kal_uint32       INT_DisableDataCache(void);
extern void             INT_RestoreDataCache(kal_uint32 dc);
extern kal_uint32       custom_get_NORFLASH_Base(void);     // custom_flash.c
extern kal_uint32       custom_get_fat_addr(void);          // custom_flash.c

// FDM 4.0
#ifndef __NOR_FDM5__
static NOR_Flash_MTD_Data *cfi_mtd_data;        // flash_cfi.c
extern kal_mutexid         fdm_reclaim_mutex;   // drvflash.c
extern NOR_FLASH_DRV_Data  FlashDriveData;      // custom_flash.c (FDM40)
extern const kal_char FLASH_ID[];               // custom_flash.c (!NFB)
extern void *MapWindow(void * DriveData, kal_uint32 BlockIndex, kal_uint32 WindowIndex);  // flash_mtd.c
extern void WaitEraseDone(NOR_FLASH_DRV_Data * D, kal_uint32 frame_tick);  // drvflash.c
#endif

// ROM
extern kal_uint32 custom_get_NORFLASH_ROMSpace(void);
extern kal_uint32 custom_get_NORFLASH_Size(void);
// FAT
extern kal_uint32 custom_get_fat_len(void);
extern kal_uint32 custom_get_fat_addr(void);


#define SWAP(x,y) {kal_uint32 z; z=x; x=y; y=z; }

//-----------------------------------------------------------------------------
// Internal Functions / Predefines
//-----------------------------------------------------------------------------
const char *CFI_Msg(kal_uint16 id, TCFIStr *str_list);
kal_uint32 cfi_block_size(MEM_DEV_CFI_T *CFIInfo, kal_uint32 address);
kal_uint32 cfi_bank_size(MEM_DEV_CFI_T *CFIInfo, kal_uint32 address);
kal_int32 CFI_ReadID(volatile FLASH_CELL *BaseAddr, MEM_DEV_CFI_T *CFIInfo);

void CFI_ConstructFATGeoInfo(MEM_DEV_CFI_T *CFIInfo);
kal_uint32 CFI_IsBlockBoundary(MEM_DEV_CFI_T *CFIInfo, kal_uint32 BlockAddr, kal_uint32 BlockSize);

kal_int32 CFI_QueryBankInfoAMD(volatile FLASH_CELL *BaseAddr, kal_uint16 PriExtAddr, MEM_DEV_CFI_T *CFIInfo);
kal_int32 CFI_QueryBankInfoNumonyx(volatile FLASH_CELL *BaseAddr, kal_uint16 PriExtAddr, MEM_DEV_CFI_T *CFIInfo);


//-----------------------------------------------------------------------------
/*!
  @brief
    Get last error message string

  @param[in] CFIInfo The pointer to the CFI info structure
  @param[out] str The pointer to the output string buffer
  @param[in] len The length of the output string buffer

  @retval
    NULL: if the string buffer is out of space.

  @remarks
    This function should be only invoked after CFI_CheckSettings()
*/

char *CFI_GetErrorMessage(MEM_DEV_CFI_T *CFIInfo, char *str, int len)
{
    if (str!=NULL)  {
        sprintf(str, CFI_Msg(CFIInfo->CheckResults, str_cfi_err), CFIInfo->CheckData1, CFIInfo->CheckData2);
        if (len<strlen(str))    {
            str[0]=0;
            return NULL;
        }
    }
    return str;
}

const char *CFI_GetCommandSetName(kal_uint16 id)
{
    return CFI_Msg(id, str_alg_type);
}


//-----------------------------------------------------------------------------
/*!
  @brief
    (DEBUG) Output debug message to console

  @param[in] fmt format string
  @param[in] ... variable argument list

  @retval
    Always 0
  @remarks
    Debug only, don't use.
*/

static kal_char cfi_buf[CFI_TEXT_BUFF_SIZE];
extern void dbg_print(char *fmt,...);

void CFI_Error(const char *fmt, ...)
{
    const char *prefix="[CFI] ";
    va_list args;

    kal_sprintf((char *)(&cfi_buf[0]),prefix);

    va_start(args, fmt);
    vsprintf((char *)(&cfi_buf[strlen(prefix)]), fmt, args);

    #if ( defined(__NOR_FLASH_HARDWARE_TEST__) && defined(__MAUI_BASIC__) )
        dbg_print((char *)(&cfi_buf[0]));         // Basic load
    #else
    if (KAL_TRUE == kal_query_systemInit()) {
        kal_bootup_print((char *)(&cfi_buf[0]));  // Bootup
    }
    else {
        tst_sys_trace((kal_uint8 *)(&cfi_buf[0])); // Default
    }
    #endif

    return;
}

#ifdef __NOR_CFI_DEBUG__
#define CFI_Debug CFI_Error
#else
#define CFI_Debug(...)
#endif

#ifdef __NOR_CFI_PRINT__
#define CFI_Print CFI_Error
#else
#define CFI_Print(...)
#endif

//-----------------------------------------------------------------------------
// Debug message output facility in Basic Load
//-----------------------------------------------------------------------------

#if ( defined(__NOR_FLASH_HARDWARE_TEST__) && defined(__MAUI_BASIC__) )

#define CFI_TEST_LIMIT 1000000
kal_uint32 CFI_Access_Counter, CFI_Check_Counter;

extern void triggerTestIRQ(void);  // defined in flash_mtd.amd.c
extern kal_uint8 PLTestOption;	   // 2: CFI Stress 3: CFI Power loss
extern void NORTEST_Reset(void);
extern char text[100];
extern kal_uint32 ResetTimeout;    // defined in nortest.c
extern kal_uint8 RandomNum;        // defined in nortest.c

#if (defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__) && defined(__CFI_STRESS__))
#define BLTest(Num) \
	{\
        if (RandomNum == Num) {\
			if (PLTestOption==0) { \
				RandomNum = (RandomNum+1) % 5;\
				triggerTestIRQ();\
			} \
            else { \
				if (ResetTimeout==0) {\
					if (RandomNum & 0x01) { \
						NORTEST_Reset();\
					} else { \
						triggerTestIRQ();\
					} \
				} else {\
					ResetTimeout--;\
					RandomNum = (RandomNum+1) % 5;\
					triggerTestIRQ();\
				}\
			}\
		}\
	}
#else   // defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__) && defined(__CFI_STRESS__)
#define BLTest(...)
#endif  // defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__) && defined(__CFI_STRESS__)

#else    // ( defined(__NOR_FLASH_HARDWARE_TEST__) && defined(__MAUI_BASIC__) )
#define BLTest(...)
#endif   // ( defined(__NOR_FLASH_HARDWARE_TEST__) && defined(__MAUI_BASIC__) )

//-----------------------------------------------------------------------------
/*!
  @brief
    (DEBUG) Get strings from message array by mesage id

  @param[in] id Message ID
  @param[in] str_list Message list

  @retval
    const string pointer to the correspond messagee
  @remarks
    Debug only, don't use.
*/
const char *CFI_Msg(kal_uint16 id, TCFIStr *str_list)
{
    kal_uint16 i;   // iterator

    for (i=0 ; i<0xFFFE ; i++)  {
        if ((str_list[i].id == id) ||
            (str_list[i].id == CFI_END)) {
            break;
        }
    }
    return str_list[i].msg;
}

//-----------------------------------------------------------------------------
/*!
  @brief
    Output GeometryInfo to console
*/
void CFI_DumpGeo(MEM_DEV_GEOMETRY_T *info, const char *name)
{
    kal_uint16 i;

    if (name!=NULL) {
        CFI_Print("  %s[] = { ", name);
    }
    else    {
        CFI_Print("  RegionInfo[] = { ");
    }
    for (i=0; info[i].Size !=0 && i<CFI_REGIONINFO_SIZE; i++)    {
        CFI_Print("    {0x%x, 0x%x}, ", info[i].Size, info[i].Count);
    }
    CFI_Print("    {0x%x, 0x%x} };", info[i].Size, info[i].Count);
}


//-----------------------------------------------------------------------------
/*!
  @brief
    Output BlockInfo to console
*/
void CFI_DumpBlk(MEM_DEV_BLOCK_T *info, const char *name)
{
    kal_uint16 i;

    if (name!=NULL) {
        CFI_Print("  %s[] = { ", name);
    }
    else    {
        CFI_Print("  BlockInfo[] = { ");
    }
    for (i=0; info[i].Size !=0 && i<CFI_BLOCKINFO_SIZE; i++)    {
        CFI_Print("    {0x%x, 0x%x}, ", info[i].Offset, info[i].Size);
    }
    CFI_Print("    {0x%x, 0x%x} };", info[i].Offset, info[i].Size);
}


//-----------------------------------------------------------------------------
/*!
  @brief
    Output all information to console
*/
void CFI_DumpInfo(MEM_DEV_CFI_T *CFIInfo)
{
    CFI_Print("NOR Flash ID = { 0x%04X, 0x%04X, 0x%04X, 0x%04X }",
        CFIInfo->FlashID[0], CFIInfo->FlashID[1],
        CFIInfo->FlashID[2], CFIInfo->FlashID[3]);

    CFI_Print("ProgramBufferSize: %d Bytes", CFIInfo->ProgramBufferSize);

    CFI_Print("<The geometry of entire Flash>");

    // Basic Info
    CFI_Print("Number of entries in RegionInfo[]: %d", CFIInfo->RegionCount);
    CFI_Print("Number of entries in BankInfo[]: %d", CFIInfo->BankCount);
    CFI_Print("Total Blocks: %d", CFIInfo->TotalBlocks);

    // Region Info
    CFI_DumpGeo(CFIInfo->RegionInfo, "CFI_RegionInfo");

    // Block Info
    CFI_DumpBlk(CFIInfo->BlockInfo, "CFI_BlockInfo");

    // Bank Info
    CFI_DumpGeo(CFIInfo->BankInfo, "CFI_BankInfo");

    CFI_Print("<The geometry start from FAT base address %08X>", custom_get_fat_addr());

    // FAT Region Info
    CFI_DumpGeo(CFIInfo->FAT_RegionInfo, "FAT_RegionInfo");

    // FAT Bank Info
    CFI_DumpGeo(CFIInfo->FAT_BankInfo, "FAT_BankInfo");

    return;
}

//-----------------------------------------------------------------------------
/*!
  @brief
    Get FDM Lock
*/
void CFI_FDMLockRetrieve(void)
{
   #if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)
   extern void GetFDMLock(void);
   if (fdm_reclaim_mutex==KAL_NILMUTEX_ID) {
        MapWindow(FlashDriveData.MTDData, 0, 0);
        return;
   }
   GetFDMLock();

   #elif defined(__NOR_FDM5__)
   extern void nFDM_LOCK(void);
   nFDM_LOCK();

   #else
   extern void FDM_LOCK(void);
   if (fdm_reclaim_mutex==KAL_NILMUTEX_ID) {
        MapWindow(FlashDriveData.MTDData, 0, 0);
        return;
   }
   FDM_LOCK();

   #endif

   return;
}

//-----------------------------------------------------------------------------
/*!
  @brief
    Relase FDM Lock
*/
void CFI_FDMLockRelease(void)
{
   #if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)
   extern void FreeFDMLock(void);
   if (fdm_reclaim_mutex==KAL_NILMUTEX_ID) return;
   FreeFDMLock();

   #elif defined(__NOR_FDM5__)
   extern void nFDM_UNLOCK(void);
   nFDM_UNLOCK();

   #else
   extern void FDM_UNLOCK(void);
   if (fdm_reclaim_mutex==KAL_NILMUTEX_ID) return;
   FDM_UNLOCK();

   #endif

   return;
}

//-----------------------------------------------------------------------------
/*!
  @brief
    Wait Erase operation done
*/
void CFI_WaitEraseDone(void)
{
   #if (defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__) || defined(__NOR_FDM5__))
   return;
   #else // !__SINGLE_BANK_NOR_FLASH_SUPPORT__ && __NOR_FDM4__
   //#define INVALID_BLOCK_INDEX   0xFFFFFFFF
   if( FlashDriveData.ReclaimBlockID != 0xFFFFFFFF )
   {
      WaitEraseDone(&FlashDriveData, 70);
   }
   #endif
}


//-----------------------------------------------------------------------------
/*!
  @brief
    Read NOR Flash / Serial Flash ID
  @param[in] BaseAddr Pointer to the Flash base address
  @param[in] CFIInfo Pointer to output CFIInfo

  @retval
    CFI query results on given offset.
*/
kal_int32 CFI_ReadID(volatile FLASH_CELL *BaseAddr, MEM_DEV_CFI_T *CFIInfo)
{
    kal_mem_set(CFIInfo->FlashID, 0, CFI_FLASH_ID_LENGTH);

    if (KAL_TRUE != kal_query_systemInit()) {
        CFI_FDMLockRetrieve();
        CFI_WaitEraseDone();
    }

    NOR_ReadID(BaseAddr, CFIInfo->FlashID);

    if (KAL_TRUE != kal_query_systemInit()) {
        CFI_FDMLockRelease();
    }
    return CFIInfo->FlashID[0];
}

//-----------------------------------------------------------------------------
/*!
  @brief
    Output BlockInfo to console

  @param[in] BaseAddr Pointer to the NOR Flash memory base address
  @param[in] offset  Query offset
  @param[in] length  Query length

  @retval
    CFI query results on given offset.
*/
kal_int32 CFI_Query(volatile FLASH_CELL *BaseAddr, kal_uint16 offset, kal_uint8 length)
{
    kal_uint32 savedMask;
    kal_uint32 data_cache_id;
    kal_uint32 result=0;
    kal_uint8 *buf=(kal_uint8*)(&result);
    kal_uint8 i;

    volatile FLASH_CELL *fp = (volatile FLASH_CELL*)(BaseAddr+offset);

    if (KAL_TRUE != kal_query_systemInit()) {
        CFI_FDMLockRetrieve();
        CFI_WaitEraseDone();
    }

    // Note: Request FDM lock before it was initiailized will case fatal errors.
    savedMask = SaveAndSetIRQMask();
    data_cache_id = INT_DisableDataCache();
    *(BaseAddr+CFI_CMD_ADDR) = CFI_CMD_ENTR;

    BLTest(1);  // CFI: Powerloss Test

    for (i=0 ; i < 4 && i < length; i++)   {
        buf[i]=fp[i];
    }
    *(BaseAddr) = CFI_CMD_EXIT1;
    *(BaseAddr) = CFI_CMD_EXIT2;

    INT_RestoreDataCache(data_cache_id);
    RestoreIRQMask(savedMask);

    if (KAL_TRUE != kal_query_systemInit()) {
        CFI_FDMLockRelease();
    }

    BLTest(0);  // Interrupt Test

    return result;
}

//-----------------------------------------------------------------------------
/*!
  @brief
    Query CFI Geometry, and the results will be filled into a CFI info structure
    defined in flash_cfi.h. The caller must pass a pointer to an allocated CFI info.

  @param[in] BaseAddr Pointer to the NOR Flash memory base address
  @param[out] CFIInfo Pointer to the CFI info

  @retval
    Number of regions

  @remarks
    This function update CFI_RegionInfo and call sub-query functions by vendor ID,
    and the CFI_BankInfo will be updated in sub-query.
*/

kal_int32 CFI_QueryGeometry(volatile FLASH_CELL *BaseAddr, MEM_DEV_CFI_T *CFIInfo)
{
    kal_uint32 tmp;
    kal_uint16 PriExtAddr;
    kal_uint16 prialg;
//    kal_uint16 extver;
    kal_uint8 i;


    #if ( defined(__NOR_FLASH_HARDWARE_TEST__) && defined(__MAUI_BASIC__) )
    CFI_Access_Counter++;
    if (CFI_Access_Counter%1000==0) {
        CFI_Error("==== #%d Query / #%d Checks ==== ", CFI_Access_Counter, CFI_Check_Counter);
    }
    if (CFI_Access_Counter==CFI_TEST_LIMIT) {
        CFI_Error("========== CFI Stress Test Finished, There was no errors ========== ");
        while(1);
    }
    #endif

    // Clear CFI Info
    kal_mem_set(CFIInfo, 0, sizeof(MEM_DEV_CFI_T));

    // Query ADMUX NOR Flash ID
    CFI_ReadID(BaseAddr, CFIInfo);
    CFI_Print("NOR Flash ID = { 0x%04X, 0x%04X, 0x%04X, 0x%04X }",
        CFIInfo->FlashID[0], CFIInfo->FlashID[1],
        CFIInfo->FlashID[2], CFIInfo->FlashID[3]);

    //-------------------------------------------------------------------------
    // Part 1: CFI Standard Query (for RegionInfo)
    //-------------------------------------------------------------------------
    tmp=CFI_QRY$;

    if (CFI_QRYSTR != tmp)  {
        CFI_Print("[10h] Unknow Identify String %08X, expected: %08X, Vendor Specific Query Aborted.", tmp, CFI_QRYSTR);
        CFIInfo->CheckResults=CFIErr_NotAvailable;
        return 0;
    }

    // Query Primary Algorithm
    CFIInfo->CommandSet = CFI_PRIALG$;

    // Query Region Count 0x2C
    CFIInfo->RegionCount = CFI_REGCNT$;
    CFIInfo->TotalBlocks = 0;

    // Query Region Info 0x2D
    for (i=0; i<CFIInfo->RegionCount; i++) {
        CFIInfo->RegionInfo[i].Count = CFI_Query(BaseAddr, CFI_REGINF + i*4 , 2) + 1;
        CFIInfo->RegionInfo[i].Size  = CFI_Query(BaseAddr, CFI_REGINF + i*4 + 2, 2) << 8;
        CFIInfo->TotalBlocks += CFIInfo->RegionInfo[i].Count;
    }
    CFIInfo->RegionInfo[i].Count=0;
    CFIInfo->RegionInfo[i].Size=0;

    // Query Flash Density (Size) in bytes
    CFIInfo->Size = CFI_EXP2(CFI_SIZE$);

    // Query Page Buffer size  0x2A, the unit of query result is in exponetial of 2 (bytes)
    CFIInfo->ProgramBufferSize = CFI_EXP2(CFI_WBSIZE$);

    //-------------------------------------------------------------------------
    // Part 2: CFI Primary Vendor-Specific Query (for BankInfo)
    //-------------------------------------------------------------------------
    // Query primary algorithm
    prialg = CFI_PRIALG$;

    // Query primary algorithm extension address
    // Note: the base addr must not be modified
    PriExtAddr = CFI_PRIEXT$;

    // Query primary algorithm extension identify string "PRI"
    if (CFI_PRISTR != CFI_Query(BaseAddr, PriExtAddr+CFI_EXTQRY, 3))   {
        CFI_Print("[%02xh] Unknow Primary Extension Identify String %08X, expected: %08X", PriExtAddr+CFI_EXTQRY, CFI_Query(BaseAddr, PriExtAddr+CFI_EXTQRY, 3), CFI_PRISTR);
        return 0;
    }

    CFI_Print("[13h] Primary Algorithm = %x, %s ", prialg, CFI_Msg(prialg, str_alg_type));
    CFI_Print("[%02Xh] Extention version: %c.%c ", PriExtAddr+CFI_EXTVER1, CFI_Query(BaseAddr, PriExtAddr+CFI_EXTVER1, 1), CFI_Query(BaseAddr, PriExtAddr+CFI_EXTVER2, 1));

    // extver = (CFI_Query(BaseAddr, PriExtAddr+CFI_EXTVER1, 1) - '0')*10 + (CFI_Query(BaseAddr, PriExtAddr+CFI_EXTVER2, 1) - '0');

    CFIInfo->BankCount=0;
    CFIInfo->BankInfo[0].Count=0;
    CFIInfo->BankInfo[0].Size=0;

    switch (prialg)   {
        case CFI_ALG_NONE:
            break;

        // Intel Series NOR Flash: BankInfo only available after v1.4
        case CFI_ALG_IntelSharpExt:
        case CFI_ALG_Intel:
        case CFI_ALG_Intel_Perform:
        case CFI_ALG_Intel_Data:
//            if (extver >= 14)   {
                CFIInfo->BankCount=CFI_QueryBankInfoNumonyx(BaseAddr, PriExtAddr, CFIInfo);
//            }
            break;

        // AMD Series NOR Flash: BankInfo only available after v1.3
        case CFI_ALG_AMDFujitsu:
        case CFI_ALG_AMDFujitsuExt:
//            if (extver > 12)    {
                CFIInfo->BankCount=CFI_QueryBankInfoAMD(BaseAddr, PriExtAddr, CFIInfo);
//            }

            break;

        case CFI_ALG_Winbond:
            break;

        case CFI_ALG_Mitsubishi:
        case CFI_ALG_MitsubishiExt:
            break;

        case CFI_ALG_SST:
            break;
    default:
        break;
    }

    //-------------------------------------------------------------------------
    // Part 3: Construct FAT_RegionInfo and FAT_BankInfo
    //-------------------------------------------------------------------------
    CFI_ConstructFATGeoInfo(CFIInfo);
    CFI_DumpInfo(CFIInfo);

    return CFIInfo->RegionCount;
}


void CFI_ConstructFATGeoInfo(MEM_DEV_CFI_T *CFIInfo)
{
    kal_uint16 ptr;
    kal_uint32 fat_base, fat_end, addr, size;

    fat_base=custom_get_fat_addr();
    fat_end=fat_base+custom_get_fat_len();


    CFI_Print("Construct FAT_RegionInfo[] and FAT_BankInfo[]");

    if (CFIInfo->Size==0)   {
        CFI_Print("Construction aborted, CFIInfo was not initialized");
        return;
    }

    CFIInfo->FAT_BankInfo[0].Size=0;
    CFIInfo->FAT_BankInfo[0].Count=0;
    CFIInfo->FAT_RegionInfo[0].Size=0;
    CFIInfo->FAT_RegionInfo[0].Count=0;

    // make sure that the base/end address are of block boundary
    if ( 0 != CFI_IsBlockBoundary(CFIInfo, fat_base, 0)) {
        CFI_Print("Construction aborted, the FAT base %08X were not aligned to block boundary", fat_base);
        return;
    }
    if (0 != CFI_IsBlockBoundary(CFIInfo, fat_end, 0)) {
       CFI_Print("Construction aborted, the FAT end %08X were not aligned to block boundary", fat_end);
       return;
    }

    //-----------------------------------------------------
    // Construct FAT_RegionInfo[]
    //-----------------------------------------------------
    if (CFIInfo->RegionInfo[0].Size!=0) {
        for (ptr=0, addr=fat_base ; addr<fat_end;)  {
            size=cfi_block_size(CFIInfo, addr);

            // add this block into fat region info
            if (addr==fat_base)    {
                CFIInfo->FAT_RegionInfo[ptr].Size=size;
                CFIInfo->FAT_RegionInfo[ptr].Count=1;
            }
            else if (size==CFIInfo->FAT_RegionInfo[ptr].Size)   {
                CFIInfo->FAT_RegionInfo[ptr].Count++;
            }
            else {
                ptr++;
                CFIInfo->FAT_RegionInfo[ptr].Size=size;
                CFIInfo->FAT_RegionInfo[ptr].Count=1;
            }
            addr+=size;
        }
        ptr++;
        CFIInfo->FAT_RegionInfo[ptr].Size=0;
        CFIInfo->FAT_RegionInfo[ptr].Count=0;

        if (ptr>=CFI_REGIONINFO_SIZE)   {
            CFI_Print("FAT_RegionInfo[] Exceeds CFI_REGIONINFO_SIZE %d", CFI_REGIONINFO_SIZE);
            ASSERT(0);
        }
    }
    else    {
            CFI_Print("CFI_RegionInfo[] doesn't exist");
    }

    // FAT Region Info
    // CFI_DumpGeo(CFIInfo->FAT_RegionInfo, "FAT_RegionInfo");

    //-----------------------------------------------------
    // Construct FAT_BankInfo[]
    //-----------------------------------------------------
    // Make sure there is more than one bank
    if (CFIInfo->BankCount!=0)  {
        for (ptr=0, addr=fat_base ; addr<fat_end;) {
            size=cfi_bank_size(CFIInfo, addr);
            if (size==0)    {
                CFI_Print("Address out of range in CFI_BankInfo[]");
                break;
            }

            if ( (size+addr) > fat_end)    {
                size = fat_end-addr;
            }

            // add this block into fat region info
            if (addr==fat_base)    {
                CFIInfo->FAT_BankInfo[0].Size=size;
                CFIInfo->FAT_BankInfo[0].Count=1;
            }
            else if (size==CFIInfo->FAT_BankInfo[ptr].Size)   {
                CFIInfo->FAT_BankInfo[ptr].Count++;
            }
            else {
                ptr++;
                CFIInfo->FAT_BankInfo[ptr].Size=size;
                CFIInfo->FAT_BankInfo[ptr].Count=1;
            }
            addr+=size;
        }
        ptr++;
        CFIInfo->FAT_BankInfo[ptr].Size=0;
        CFIInfo->FAT_BankInfo[ptr].Count=0;

        if (ptr>=CFI_BANKINFO_SIZE)   {
            CFI_Print("FAT_BankInfo[] Exceeds CFI_BANKINFO_SIZE %d", CFI_BANKINFO_SIZE);
            ASSERT(0);
        }
    }
    else    {
            CFI_Print("CFI_BankInfo[] doesn't exist");
    }

    // FAT Bank Info
    // CFI_DumpGeo(CFIInfo->FAT_BankInfo, "FAT_BankInfo");

    return;
}




//-----------------------------------------------------------------------------
/*!
  @brief
    Construct BlockInfo[] by the RegionInfo[]

  @param[in] CFIInfo Pointer to the CFI info

  @retval
    None
*/

void CFI_ConstructBlockInfo(MEM_DEV_CFI_T *CFIInfo)
{
    kal_uint16 i;

    CFIInfo->BlockInfo[0].Offset=0;

    for (i=0; CFIInfo->RegionInfo[i].Size!=0; i++)  {
        CFIInfo->BlockInfo[i].Size = CFIInfo->RegionInfo[i].Size;
        CFIInfo->BlockInfo[i+1].Offset = CFIInfo->BlockInfo[i].Offset + CFIInfo->RegionInfo[i].Size * CFIInfo->RegionInfo[i].Count;
    }
    CFIInfo->BlockInfo[i].Offset=0;
    CFIInfo->BlockInfo[i].Size=0;
}


//-----------------------------------------------------------------------------
/*!
  @brief
    Lookup the block size of the given block address

  @param[in] CFIInfo Pointer to the CFI info
  @param[in] address Base address of the block

  @retval
    Size of the block on given address
*/
kal_uint32 cfi_block_size(MEM_DEV_CFI_T *CFIInfo, kal_uint32 address)
{
    kal_uint16 i;

    for (i=0; CFIInfo->BlockInfo[i+1].Size!=0; i++)   {
        if (address >= CFIInfo->BlockInfo[i].Offset &&
            address <  CFIInfo->BlockInfo[i+1].Offset)  {
            break;
        }
    }
    return CFIInfo->BlockInfo[i].Size;
}

//-----------------------------------------------------------------------------
/*!
  @brief
    Lookup the bank size of the given address, if the address is not aligned to
    bank boundary, returns the length to next bank boundary.

  @param[in] CFIInfo Pointer to the CFI info
  @param[in] address The given address

  @retval
    Length to next bank boundary
*/

kal_uint32 cfi_bank_size(MEM_DEV_CFI_T *CFIInfo, kal_uint32 address)
{
    kal_uint16 i, j;

    for (i=0; CFIInfo->BankInfo[i].Size!=0; i++)   {
        for (j=0; j<CFIInfo->BankInfo[i].Count; j++)    {
            if (address >= CFIInfo->BankInfo[i].Size)    {
                address -= CFIInfo->BankInfo[i].Size;
            }
            else    {
                return (CFIInfo->BankInfo[i].Size-address);
            }
        }
    }
    return 0;
}


//-----------------------------------------------------------------------------
/*!
  @brief
    Get Geometry from CFI vendor-specific query (AMD), and update CFI_BankInfo
    static structure

  @param[in] BaseAddr Pointer to the CFI primary vendor-specific query base address

  @retval
    Number of Banks
*/

kal_int32 CFI_QueryBankInfoAMD(volatile FLASH_CELL *BaseAddr, kal_uint16 PriExtAddr, MEM_DEV_CFI_T *CFIInfo)
{
    kal_uint8  boot_flag;
    kal_uint16 block_count, total_blocks, bank_ptr;
    kal_int16  i, j;
    kal_uint32 bank_size, block_size, address;

    CFI_Print("Vendor Specific Query <AMD> ");
    CFIInfo->BankCount = CFI_Query(BaseAddr, PriExtAddr+CFI_AMD_BNKCNT, 1);

    CFI_Print("[%02Xh] Bank Count = %d ", PriExtAddr+CFI_AMD_BNKCNT, CFIInfo->BankCount);

    boot_flag = CFI_Query(BaseAddr, PriExtAddr+CFI_AMD_BOOTFLAG, 1);

    CFI_Print("[%02Xh] Bootflag = %d (%s) ", PriExtAddr+CFI_AMD_BOOTFLAG, boot_flag, (boot_flag==2)?("Bottom"):(boot_flag==3?("Top"):("Unknown")));

    // Swap the Region Info for top boot (Toshiba Only)
    if (CFIInfo->RegionCount>1 && CFIInfo->FlashID[0]==0x0098) {
        if ((boot_flag==3)&&(CFIInfo->RegionInfo[0].Size!=CFIInfo->RegionInfo[1].Size))   {
            SWAP(CFIInfo->RegionInfo[0].Size, CFIInfo->RegionInfo[CFIInfo->RegionCount-1].Size);
            SWAP(CFIInfo->RegionInfo[0].Count, CFIInfo->RegionInfo[CFIInfo->RegionCount-1].Count);
        }
    }

    CFI_ConstructBlockInfo(CFIInfo);

    // If the Queried Bank Count is Zero
    // Simply Returns 0
    if (CFIInfo->BankCount==0)  {
        return 0;
    }

    total_blocks=0;
    address=0;
    bank_ptr=0;

    CFIInfo->BankInfo[0].Count = 0;
    CFIInfo->BankInfo[0].Size = 0;

    // for each bank
    for (i=0 ; i<CFIInfo->BankCount ; i++)  {
        // Retrieve number of blocks within the bank
        block_count = CFI_Query(BaseAddr, PriExtAddr+CFI_AMD_BNKINF+i, 1);
        bank_size = 0;

        CFI_Debug("[%02Xh] Bank %d Region has %d blocks", PriExtAddr+CFI_AMD_BNKINF+i, i, CFI_Query(BaseAddr, PriExtAddr+CFI_AMD_BNKINF+i, 1));

        if ( (total_blocks+block_count) >CFIInfo->TotalBlocks)    {
            CFI_Print("Error: the BankInfo is mismatch with the RegionInfo in total blocks");
            return 0;
        }

        for (j=0; j<block_count; j++, total_blocks++)    {
            block_size = cfi_block_size(CFIInfo, address);
            CFI_Debug("Block No %d @ %08Xh, Size=%08X Bytes", total_blocks, address, block_size);
            bank_size += block_size;
            address += block_size;
        }

        if (i==0)    {
            CFIInfo->BankInfo[bank_ptr].Size=bank_size;
            CFIInfo->BankInfo[bank_ptr].Count=1;

        }
        else if (bank_size==CFIInfo->BankInfo[bank_ptr].Size)   {
            CFIInfo->BankInfo[bank_ptr].Count++;
        }
        else {
            bank_ptr++;
            CFIInfo->BankInfo[bank_ptr].Size=bank_size;
            CFIInfo->BankInfo[bank_ptr].Count=1;
        }
    }

    // If there is more than one banks
    if (CFIInfo->BankInfo[0].Size!=0 && total_blocks!=CFIInfo->TotalBlocks) {
        CFI_Print("Error: the BankInfo is mismatch with the RegionInfo in total blocks");
        return 0;
    }

    // Add EndRegionInfo
    bank_ptr++;
    CFIInfo->BankInfo[bank_ptr].Count = 0;
    CFIInfo->BankInfo[bank_ptr].Size = 0;

    if (bank_ptr>=CFI_REGIONINFO_SIZE)   {
        CFI_Print("CFI_BankInfo[] Exceeds CFI_BANKINFO_SIZE %d", CFI_BANKINFO_SIZE);
        ASSERT(0);
    }

    return i;
}

//-----------------------------------------------------------------------------
/*!
  @brief
    Get Geometry from CFI vendor-specific query (Numonyx), and update CFI_BankInfo
    static structure

  @param[in] BaseAddr Pointer to the CFI primary vendor-specific query base address

  @retval
    Number of Banks
*/
kal_int32 CFI_QueryBankInfoNumonyx(volatile FLASH_CELL *BaseAddr, kal_uint16 PriExtAddr, MEM_DEV_CFI_T *CFIInfo)
{
    kal_uint32 block_size, bank_size;
    kal_uint16 bank_count, bank_identicals, block_type_count, block_count;
    kal_uint16 bank_fieldsize, bank_base, block_base;
    kal_int16  i, j;

    CFI_ConstructBlockInfo(CFIInfo);

    bank_count = CFI_Query(BaseAddr, PriExtAddr+CFI_NUMONYX_BNKCNT, 1);
    bank_base = CFI_NUMONYX_REGINF;

    CFIInfo->BankInfo[0].Count=0;
    CFIInfo->BankInfo[0].Size=0;

    // Iterates all banks
    for (i=0 ; i<bank_count ; i++)  {
        bank_fieldsize = CFI_Query(BaseAddr, PriExtAddr+bank_base, 2);
        bank_identicals = CFI_Query(BaseAddr, PriExtAddr+bank_base + 2 , 1);
        block_type_count = CFI_Query(BaseAddr,  PriExtAddr+bank_base + 7, 1);
        block_base = bank_base + 8;
        bank_size=0;

        // Iterates all block types in each bank
        for (j=0 ; j<block_type_count ; j++) {
            block_count = CFI_Query(BaseAddr, PriExtAddr+block_base, 2) + 1;      // Number of identical blocks in the partition
            block_size = CFI_Query(BaseAddr, PriExtAddr+block_base + 2, 2) << 8;  // Size of the identical blocks
            bank_size = bank_size + block_count * block_size;
            block_base = block_base + 14;
        }

        CFIInfo->BankInfo[i].Count = bank_identicals;
        CFIInfo->BankInfo[i].Size = bank_size;

        bank_base = bank_base + bank_fieldsize;
    }

    CFIInfo->BankInfo[i].Count=0;
    CFIInfo->BankInfo[i].Size=0;

    return bank_count;
}


//-----------------------------------------------------------------------------
/*!
  @brief
    Check if the given block address is on the block boundary and the block size is correct
  @param[in] CFIInfo Pointer to the CFI structure
  @param[in] BlockAddr The base address of the the given block
  @param[in] BlockSize The size of the given block
  @retval
    Nonzero: Given address is on block boundary
    Zero:    Given address is not on block boundary
  @remarks
    CFI_ConstructBlockInfo() must be invoked before calling this routine
*/
kal_uint32 CFI_IsBlockBoundary(MEM_DEV_CFI_T *CFIInfo, kal_uint32 BlockAddr, kal_uint32 BlockSize)
{
    kal_uint32 i;
    kal_uint32 result;

    for (i=0; CFIInfo->BlockInfo[i].Size!=0 ;i++) {
        if (CFIInfo->BlockInfo[i].Offset <= BlockAddr &&
            (CFIInfo->BlockInfo[i+1].Offset > BlockAddr || CFIInfo->BlockInfo[i+1].Size==0) ) break;
    }

    // In case of wrong block info
    if (CFIInfo->BlockInfo[i].Size==0) {
        return 1;
    }

    result=(BlockAddr-CFIInfo->BlockInfo[i].Offset) % CFIInfo->BlockInfo[i].Size;

    CFI_Debug("0x%08X: BlockInfo[%d] <0x%X> #%d (%s)",
        BlockAddr, i,
        CFIInfo->BlockInfo[i].Offset,
        (BlockAddr-CFIInfo->BlockInfo[i].Offset) / CFIInfo->BlockInfo[i].Size,
        (result)?"Unaligned":"Aligned");

    if (BlockSize!=0 && (BlockSize != CFIInfo->BlockInfo[i].Size) )    {
        CFI_Debug("0x%08X: BlockSize mismatch %08X, %08X", BlockSize, CFIInfo->BlockInfo[i].Size);
        return BlockSize;
    }

    return result;
}

//-----------------------------------------------------------------------------
/*!
  @brief
    This macro is only used by CFI_CheckSettings() to set error codes.
*/
#define CFI_Check_Result(info, result, dat1, dat2)  do {   \
    info->CheckResults=result;  \
    info->CheckData1=dat1;      \
    info->CheckData2=dat2;      \
} while(0)

//-----------------------------------------------------------------------------
/*!
  @brief
    Verify NOR Flash settings via given CFI structure.
  @param[in] CFIInfo Pointer to the CFI structure
  @retval
    ==0: (=CFIErr_NoError) There is no error.
    !=0: Refer to error codes
  @remarks
    The returned code can be interpreted by CFI_GetErrorMessage()
*/
kal_int32 CFI_CheckSettings(MEM_DEV_CFI_T *CFIInfo)
{
    kal_uint16 i, j, blkno;
    kal_uint32 addr;
	kal_uint32 BufferProgramLength;

#if ( defined(__NOR_FLASH_HARDWARE_TEST__) && defined(__MAUI_BASIC__) )
    if (CFI_Access_Counter%1000==0) {
        CFI_Error("#%d Check Setting ", CFI_Access_Counter);
    }
#endif

    CFI_Print("<Check> NOR Flash ID (MAUI): { %s }", FLASH_ID);

    CFI_Print("<Check> NOR Flash ID (RDID) : { 0x%04X, 0x%04X, 0x%04X, 0x%04X }",
        CFIInfo->FlashID[0], CFIInfo->FlashID[1],
        CFIInfo->FlashID[2], CFIInfo->FlashID[3]);

    CFIInfo->CheckResults=CFIErr_NoError;
    CFIInfo->CheckData1=0;
    CFIInfo->CheckData2=0;

    if (CFIInfo->Size==0)   {
        CFI_Print("CFI Query was not valid, check aborted");
        CFIInfo->CheckResults=CFIErr_NotAvailable;
        return CFIErr_NotAvailable;
    }

    //----------------------------------------------
    // FAT Settings
    //----------------------------------------------
    // Check 1: FAT base address must be aligned to block boundary
    addr=custom_get_fat_addr();
    CFI_Print("<Check> FAT base address %08X", addr);
    if (CFI_IsBlockBoundary(CFIInfo ,addr, 0) != 0) {
        CFI_Check_Result(CFIInfo, CFIErr_FATBeginUnalign, addr, 0);
        return CFIErr_FATBeginUnalign;
    }

    // Check 2: FAT end address must be aligned to block boundary
    addr+=custom_get_fat_len();
    CFI_Print("<Check> FAT end address %08X", addr);
    if (CFI_IsBlockBoundary(CFIInfo ,addr, 0) != 0) {
        CFI_Check_Result(CFIInfo, CFIErr_FATEndUnalign, addr, 0);
        return CFIErr_FATEndUnalign;
    }
    // Check 3: The end of FAT must not exceed the size of NOR Flash
    if ( addr > CFIInfo->Size )   {
        CFI_Check_Result(CFIInfo, CFIErr_FATSizeExceed, addr, 0);
        return CFIErr_FATSizeExceed;
    }

    //----------------------------------------------
    // MTD Driver
    //----------------------------------------------
#if defined(__PAGE_BUFFER_PROGRAM__)
#if defined(__COMBO_MEMORY_SUPPORT__)
    BufferProgramLength = PAGE_BUFFER_SIZE;
#else
    BufferProgramLength = BUFFER_PROGRAM_ITERATION_LENGTH;
#endif

    CFI_Print("<Check> Program Buffer Size %d bytes", BufferProgramLength*2);
    if ( BufferProgramLength*2 > CFIInfo->ProgramBufferSize ) {
        CFI_Check_Result(CFIInfo, CFIErr_ProgBufExceed, (BufferProgramLength*2), CFIInfo->ProgramBufferSize);
        return CFIErr_ProgBufExceed;
    }
#endif /* __PAGE_BUFFER_PROGRAM__ */

#if defined(__NOR_FDM5__)
    CFI_Print("FDM 5.0 RegionInfo[]/BankInfo[] was not available");
#else  // __NOR_FDM5__
    cfi_mtd_data   = FlashDriveData.MTDData;
    //----------------------------------------------
    // Check BankInfo[] and RegionInfo[]
    //----------------------------------------------
    addr=custom_get_fat_addr();
    blkno=0;
    // Make sure that NOR Driver is mounted
    if ( ~(cfi_mtd_data->Signature) == ((kal_uint32)cfi_mtd_data->RegionInfo))   {

        CFI_DumpBlk( (MEM_DEV_BLOCK_T *)cfi_mtd_data->RegionInfo, "NOR_RegionInfo");
        CFI_DumpBlk( (MEM_DEV_BLOCK_T *)cfi_mtd_data->BankInfo, "NOR_BankInfo");

        if (CFIInfo->FAT_RegionInfo[0].Size!=0) {
            //----------------------------------------------
            // Region Info (Block Boundary Check)
            //----------------------------------------------
            for (i=0; cfi_mtd_data->RegionInfo[i].BlockSize!=0; i++)  {
                for (j=0; j<cfi_mtd_data->RegionInfo[i].RegionBlocks; j++)    {
                    if (CFI_IsBlockBoundary(CFIInfo, addr, cfi_mtd_data->RegionInfo[i].BlockSize) != 0) {
                        CFI_Check_Result(CFIInfo, CFIErr_RegionInfoError, i, blkno);
                        return CFIErr_RegionInfoError;
                    }
                    blkno++;
                    addr += cfi_mtd_data->RegionInfo[i].BlockSize;
                }
            }
            //----------------------------------------------
            // Region Info
            //----------------------------------------------
            for (i=0; cfi_mtd_data->RegionInfo[i].BlockSize!=0 || CFIInfo->FAT_RegionInfo[i].Size!=0 ;i++)  {
                if ( (cfi_mtd_data->RegionInfo[i].BlockSize != CFIInfo->FAT_RegionInfo[i].Size) )   {
                    CFI_Check_Result(CFIInfo, CFIErr_RegionInfoBlkSize, i, CFIInfo->FAT_RegionInfo[i].Size);
                    return CFIErr_RegionInfoBlkSize;
                }
                if ( (cfi_mtd_data->RegionInfo[i].RegionBlocks != CFIInfo->FAT_RegionInfo[i].Count) )   {
                    CFI_Check_Result(CFIInfo, CFIErr_RegionInfoBlkCnt, i, CFIInfo->FAT_RegionInfo[i].Count);
                    return CFIErr_RegionInfoBlkCnt;
                }
            }
        }
        else {
            CFI_Print("FAT_RegionInfo[] not available, check aborted.");
        }

#if (defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__) && defined(__MULTI_BANK_NOR_DEVICE__) || defined(__ARM9_MMU__) || defined(__ARM11_MMU__))

        if (CFIInfo->FAT_BankInfo[0].Size!=0) {
            //----------------------------------------------
            // Bank Info
            //----------------------------------------------
            for (i=0; cfi_mtd_data->BankInfo[i].BankSize!=0 || CFIInfo->FAT_BankInfo[i].Size!=0 ;i++)  {
                if ( (cfi_mtd_data->BankInfo[i].BankSize != CFIInfo->FAT_BankInfo[i].Size) )   {
                    CFI_Check_Result(CFIInfo, CFIErr_BankInfoBnkSize, i, CFIInfo->FAT_BankInfo[i].Size);
                    return CFIErr_BankInfoBnkSize;
                }
                if ( (cfi_mtd_data->BankInfo[i].Banks != CFIInfo->FAT_BankInfo[i].Count) )   {
                    CFI_Check_Result(CFIInfo, CFIErr_BankInfoBnkCnt, i, CFIInfo->FAT_BankInfo[i].Count);
                    return CFIErr_BankInfoBnkCnt;
                }
            }
        }
        else    {
            CFI_Print("FAT_BankInfo[] not available, check aborted.");
        }
#else  // __SINGLE_BANK_NOR_FLASH_SUPPORT__) && (defined(__MULTI_BANK_NOR_DEVICE__) || defined(__ARM9_MMU__) || defined(__ARM11_MMU__)
        CFI_Print("Not ESB configuration, BankInfo[] check canceled");
#endif // __SINGLE_BANK_NOR_FLASH_SUPPORT__) && (defined(__MULTI_BANK_NOR_DEVICE__) || defined(__ARM9_MMU__) || defined(__ARM11_MMU__)

    }
    else {
        CFI_Print("MTD driver was not initialized, RegionInfo[] BankInfo[] check canceled");
    }
#endif // __NOR_FDM5__

    // CFI Stress Test: Asserts if the check is failed
#if ( defined(__NOR_FLASH_HARDWARE_TEST__) && defined(__MAUI_BASIC__) )
    ASSERT(CFIInfo->CheckResults==CFIErr_NoError);
    CFI_Check_Counter++;
#endif

    return CFIInfo->CheckResults;
}

//-----------------------------------------------------------------------------
/*!
  @brief
    Decode CFI data and output to console / sys trace.

  @param[in] data Pointer to the CFI structure read by CFI_Read()

  @retval
    Number of regions
*/

kal_int32 CFI_QueryAll(volatile FLASH_CELL *BaseAddr)
{
    kal_uint32 i;

    kal_uint32 blockcount;
    kal_uint32 blocksize;

    kal_uint32 ident   = CFI_QRY$;
    kal_uint16 prialg  = CFI_PRIALG$;
    kal_uint16 priext  = CFI_PRIEXT$;
    kal_uint16 altalg  = CFI_ALTALG$;
    kal_uint16 altext  = CFI_ALTEXT$;
    kal_uint16 devint  = CFI_DEVINT$;
    kal_uint16 devsize = CFI_SIZE$;
    kal_uint16 bufsize = CFI_WBSIZE$;
    kal_uint8  vccmin  = CFI_VCCMIN$;
    kal_uint8  vccmax  = CFI_VCCMAX$;
    kal_uint8  vppmin  = CFI_VPPMIN$;
    kal_uint8  vppmax  = CFI_VPPMAX$;
    kal_uint8  ttwprog = CFI_WPRGTT$;
    kal_uint8  ttbprog = CFI_BPRGTT$;
    kal_uint8  tteblk  = CFI_BLKETT$;
    kal_uint8  ttechp  = CFI_CHPETT$;
    kal_uint8  mtwprog = CFI_WPRGMT$;
    kal_uint8  mtbprog = CFI_BPRGMT$;
    kal_uint8  mteblk  = CFI_BLKEMT$;
    kal_uint8  mtechp  = CFI_CHPEMT$;
    kal_uint8  regcnt  = CFI_REGCNT$;

    CFI_Print("[10h] Query String = \'%c\', \'%c\', \'%c\' ", ident & 0xFF, ident>>8 & 0xFF, ident>>16 & 0xFF);

    if (ident!=CFI_QRYSTR)  {
        CFI_Print("The device does not support CFI Query");
        return 0;
    }

    CFI_Print("[13h] Primary Algorithm = %x, %s ", prialg, CFI_Msg(prialg, str_alg_type));
    CFI_Print("[15h] Primary Algorithm Extension offset = %x ", priext);
    CFI_Print("[17h] Alternative Algorithm = %x, %s ", altalg, CFI_Msg(altalg, str_alg_type));
    CFI_Print("[19h] Alternative Algorithm Extension offset = %x ", altext);

    CFI_Print("[1Bh] Vcc Min = %d.%d V ", CFI_VOLT(vccmin), CFI_MILVOLT(vccmin));
    CFI_Print("[1Ch] Vcc Max = %d.%d V ", CFI_VOLT(vccmax), CFI_MILVOLT(vccmax));
    CFI_Print("[1Dh] Vpp Min = %d.%d V ", CFI_VOLT(vppmin), CFI_MILVOLT(vppmin));
    CFI_Print("[1Eh] Vpp Max = %d.%d V ", CFI_VOLT(vppmax), CFI_MILVOLT(vppmax));

    CFI_Print("[1Fh] %02xh Typical timeout per single byte/word/D-word program = %d us ", ttwprog, CFI_EXP2(ttwprog) );
    CFI_Print("[20h] %02xh Typical timeout for maximum-size multi-byte program = %d us ", ttbprog, CFI_EXP2(ttbprog) );
    CFI_Print("[21h] %02xh Typical timeout per individual block erase = %d ms ", tteblk, CFI_EXP2(tteblk) );

  	CFI_Print("[22h] %02xh Typical timeout for full chip erase = %d ms ", ttechp, (ttechp!=0)?CFI_EXP2(ttechp):0 );

    CFI_Print("[23h] %02xh Maximum timeout per single byte/word/D-word program = %d us ", mtwprog, CFI_EXP2(ttwprog + mtwprog) );
    CFI_Print("[24h] %02xh Maximum timeout for maximum-size multi-byte program = %d us ", mtbprog, CFI_EXP2(ttbprog + mtbprog) );
    CFI_Print("[25h] %02xh Maximum timeout per individual block erase = %d ms ", mteblk, CFI_EXP2(tteblk + mteblk) );

   	CFI_Print("[26h] %02xh Maximum timeout for full chip erase = %d ms ", mtechp, ((ttechp+mtechp)!=0)?CFI_EXP2(ttechp+mtechp):0 );

    CFI_Print("[27h] %02xh Device = 0x%X bytes / %d KB / %d MB / %d Mbits", devsize, CFI_EXP2(devsize), CFI_EXP2(devsize-10), CFI_EXP2(devsize-20), CFI_EXP2(devsize-17));
    CFI_Print("[28h] %02xh Flash Device Interface = %d, %s ", devint, devint, CFI_Msg(devint, str_dev_int) );
    CFI_Print("[2Ah] %02xh Maximum number of bytes in multi-byte program = %d bytes ", bufsize, CFI_EXP2(bufsize) );
    CFI_Print("[2Ch] %02xh Number of Erase Block Regions = %d ", regcnt, regcnt);

    for (i=0; i < regcnt; i++) {
        blockcount = CFI_Query(BaseAddr, CFI_REGINF + i*4 , 2);
        blocksize  = CFI_Query(BaseAddr, CFI_REGINF + i*4 + 2, 2);
        blockcount += 1;  // The block count = queried value plus 1
        blocksize  = blocksize * 256;   // the block size = queried value * 256 Bytes
        CFI_Print("[%02xh] %04xh_%04xh <Region %d> Block Count = %d, Block Size = %d bytes ( %d x %d KB)", CFI_REGINF+i*4, blockcount, blocksize>>8, i, blockcount, blocksize, blockcount, blocksize >> 10);
    }
    return regcnt;
}

//-----------------------------------------------------------------------------
/*!
  @brief
    This function queries all available CFI entries, and output to console /
    systrace.
*/
void CFI_NOR_Main(void)
{
    MEM_DEV_CFI_T NORCFIInfo;

    CFI_Print("-----[CFI query: NOR Flash Info]-----");
    CFI_QueryAll(CFI_NOR_BASE$);
    CFI_Print("-----[CFI query: NOR Flash Geometry]-----");
    CFI_QueryGeometry(CFI_NOR_BASE$, &NORCFIInfo);
    CFI_Print("-----[Check MAUI NOR Flash settings]-----");
    CFI_CheckSettings(&NORCFIInfo);
    CFI_Print("-----[Results]-----");
    CFI_Print(CFI_Msg(NORCFIInfo.CheckResults, str_cfi_err), NORCFIInfo.CheckData1, NORCFIInfo.CheckData2);
    CFI_Print("-----[End of CFI]-----");

    return;
}

#else   // ((defined(__NOR_FLASH_HARDWARE_TEST__) && defined(__MAUI_BASIC__)) || (defined(__NOR_CFI_SUPPORT__) && defined(__MTK_TARGET__) && !defined(_NAND_FLASH_BOOTING_) && !defined(__FS_SYSDRV_ON_NAND__)) )

void CFI_NOR_Main(void)
{
    return;
}

// General functions
kal_int32 CFI_Query(volatile FLASH_CELL *BaseAddr, kal_uint16 offset, kal_uint8 length)
{
    return 0;
}

kal_int32 CFI_QueryAll(volatile FLASH_CELL *BaseAddr)
{
    return 0;
}

void CFI_DumpInfo(MEM_DEV_CFI_T *CFIInfo)
{
    return;
}

// Reserved For EM
kal_int32 CFI_QueryGeometry(volatile FLASH_CELL *BaseAddr, MEM_DEV_CFI_T *CFIInfo)
{
    return 0;
}

kal_int32 CFI_CheckSettings(MEM_DEV_CFI_T *CFIInfo)
{
    return 0;
}

char *CFI_GetErrorMessage(MEM_DEV_CFI_T *CFIInfo, char *str, int len)
{
    return NULL;
}

const char *CFI_GetCommandSetName(kal_uint16 id)
{
    return NULL;
}


#endif // !(__UBL__) && (((__NOR_FLASH_HARDWARE_TEST__) && (__MAUI_BASIC__)) || ((__NOR_CFI_SUPPORT__) && (__MTK_TARGET__) && !(_NAND_FLASH_BOOTING_) && !(__FS_SYSDRV_ON_NAND__)) )

#if (!defined(__FS_SYSDRV_ON_NAND__) && !defined(_NAND_FLASH_BOOTING_))

#include "DrvFlash.h"

extern kal_uint32 SaveAndSetIRQMask(void);
extern void RestoreIRQMask(kal_uint32 irq);
extern kal_uint32 INT_DisableDataCache(void);
extern void INT_RestoreDataCache(kal_uint32 dc);
extern kal_bool CMEM_CheckValidDeviceID(kal_uint8 *id);

//-----------------------------------------------------------------------------
/*!
  @brief
    Read NOR Flash ID

  @param[in] BaseAddr Pointer to the NOR Flash memory base address
  @param[out] flashid Array of FlashID, the maximum length is 4
  @retval
    Query result, byte aligned.

  @remarks
    Limited to the length return value (32 bits), the given length shall not exceed 4 (bytes)
    This function must be put in RAM
*/

__nor_section_RAM void NOR_ReadID(volatile FLASH_CELL *BaseAddr, kal_uint16 *flashid)
{
    kal_uint32 savedMask;

    // Read Serial Flash ID
#if defined(__SERIAL_FLASH__)
    {
        kal_uint8 cmd, id[SF_FLASH_ID_LENGTH], i;

        cmd=SF_CMD_READ_ID_QPI;
        savedMask = SaveAndSetIRQMask();
        SFI_Dev_Command_Ext(&cmd, id, 1, SF_FLASH_ID_LENGTH);
        RestoreIRQMask(savedMask);

        if (id[0]==0x00 || id[0]==0xFF || (CMEM_CheckValidDeviceID(id) == KAL_FALSE)) {
            cmd=SF_CMD_READ_ID;
            savedMask = SaveAndSetIRQMask();
            SFI_Dev_Command_Ext(&cmd, id, 1, SF_FLASH_ID_LENGTH);
            RestoreIRQMask(savedMask);
        }

        for (i=0;i<SF_FLASH_ID_LENGTH;i++) flashid[i]=id[i];
    }
    // Read ADMUX NOR Flash ID
#else  // ADMUX
    {
        kal_uint32 data_cache_id;
        volatile FLASH_CELL *fp = (volatile FLASH_CELL*)(BaseAddr);

        // Note: Request FDM lock before it was initiailized will case fatal errors.
        savedMask = SaveAndSetIRQMask();
        data_cache_id = INT_DisableDataCache();

        *(BaseAddr+CFI_RDID_UNLOCK_ADR1)=CFI_RDID_UNLOCK_DAT1;
        *(BaseAddr+CFI_RDID_UNLOCK_ADR2)=CFI_RDID_UNLOCK_DAT2;
        *(BaseAddr+CFI_RDID_ADR)=CFI_RDID_CMD;

        flashid[0]=fp[0];
        flashid[1]=fp[1];
        flashid[2]=fp[2];
        flashid[3]=fp[3];

        *(BaseAddr) = CFI_CMD_EXIT1;
        *(BaseAddr) = CFI_CMD_EXIT2;

        INT_RestoreDataCache(data_cache_id);
        RestoreIRQMask(savedMask);
    }
#endif  // defined(__SERIAL_FLASH__)
    return;
}

#endif // !defined __FS_SYSDRV_ON_NAND__) && (!defined(_NAND_FLASH_BOOTING_)

kal_int32 CFI_NOR_Flash(void)
{
	CFI_NOR_Main();
	return 0;
}

