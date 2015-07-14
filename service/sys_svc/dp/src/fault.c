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
 *   fault.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file defines page fault hanlding for platforms with MMU.
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*******************************************************************************
 * Include header files.
 *******************************************************************************/

#include "cp15.h"
#include "mmu_int.h"
#include "mmu.h"
#include "cache_sw_int.h"
#include "cache_sw.h"
#include "intrCtrl.h"
#include "nfb_loader.h"
#include "page.h"
#include "system_trc.h"
#include "custom_scatstruct.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "kal_trace.h"
#include "kal_internal_api.h"
#include "SST_intrCtrl.h"
#include "FTL.h"
#include "NAND_DAL_Version.h" // For MAX_DEMAND_STACK_USED_BY_NAND_DRIVER


#if defined(__MTK_TARGET__) && defined(__DEMAND_PAGING__)
extern kal_int32 demp_do_page_fault(kal_uint32 error_type, kal_uint32 addr, kal_uint32 fsr, kal_uint32 pc_return);

kal_int32 do_page_fault(kal_uint32 error_type, kal_uint32 addr, kal_uint32 fsr, kal_uint32 pc_return)
{
    return demp_do_page_fault(error_type, addr, fsr, pc_return);
}
#endif


/*******************************************************************************
 * Import define...
 *******************************************************************************/
#if defined(__MTK_TARGET__) && defined(__DEMAND_PAGING__)

#if defined (__ARM_FPUV2__)
#define PAGE_SWAP_IN_STACK_VFP_CONTEXT_OVERHEAD (144 + 14)
#else
#define PAGE_SWAP_IN_STACK_VFP_CONTEXT_OVERHEAD (0)
#endif

#define PAGE_SWAP_IN_STACK_ARM_CONTEXT_SWITCH_OVERHEAD (17 * 4 + 8)
#define PAGE_SWAP_IN_STACK_CONTEXT_SWITCH_OVERHEAD ((PAGE_SWAP_IN_STACK_ARM_CONTEXT_SWITCH_OVERHEAD) + (PAGE_SWAP_IN_STACK_VFP_CONTEXT_OVERHEAD))

#define PAGE_SWAP_IN_STACK_BEFORE_FLASH_DRIVER (64 + 16 + 8)
#if defined(_NAND_FLASH_BOOTING_)
#define PAGE_SWAP_IN_STACK_SIZE ((PAGE_SWAP_IN_STACK_BEFORE_FLASH_DRIVER) + (MAX_DEMAND_STACK_USED_BY_NAND_DRIVER) + (PAGE_SWAP_IN_STACK_CONTEXT_SWITCH_OVERHEAD))
#elif defined(__EMMC_BOOTING__)
#define PAGE_SWAP_IN_STACK_SIZE ((PAGE_SWAP_IN_STACK_BEFORE_FLASH_DRIVER) + (1024) + (PAGE_SWAP_IN_STACK_CONTEXT_SWITCH_OVERHEAD))
#else
#define PAGE_SWAP_IN_STACK_SIZE ((PAGE_SWAP_IN_STACK_BEFORE_FLASH_DRIVER) + (1024) + (PAGE_SWAP_IN_STACK_CONTEXT_SWITCH_OVERHEAD))
#endif
/*******************************************************************************
 * Define global data.
 *******************************************************************************/

demp_ninfo_t demp_ninfo;
demp_page_t *demp_page_list;
kal_uint32 *demp_page_pool, demp_page_pool_size;

#if defined(__DEMAND_PAGING_DEBUG__)
demp_stats_t demp_stats;
#endif  /* __DEMAND_PAGING_DEBUG__ */

#if defined(__DEMAND_PAGING_FIFO__)
demp_page_t *demp_search_page, *demp_end_page;
#endif  /* __DEMAND_PAGING_FIFO__ */

#if defined(__DEMAND_PAGING_LRU__)
demp_page_t demp_lru;
#endif  /* __DEMAND_PAGING_LRU__ */

#if defined(__DEMAND_PAGING_LRU2Q__)
demp_page_t demp_active_head, demp_inactive_head, demp_lock_head;
#endif  /* __DEMAND_PAGING_LRU2Q__ */

static kal_int32 demp_err_code;
static kal_uint32 demp_nested_count;
static kal_uint8 swap_in_stack[PAGE_SWAP_IN_STACK_SIZE];
static kal_enhmutexid swap_in_mutex = NULL;

/* (accumulative lock size, max lock size) */
kal_uint32 demp_lock_count[][2] = 
{
  	{0, NAND_MAX_LOCK_SIZE},
  	{0, EMMC_MAX_LOCK_SIZE},
  	{0, AUDIO_MAX_LOCK_SIZE},
  	{0, VIDEO_MAX_LOCK_SIZE},
  	{0, TOTAL_MAX_LOCK_SIZE}
};
#ifdef __DEMAND_PAGING_PERFORMANCE_PROFILING__

demp_eval_pool dempPoolStats[100 * (512 >> (PAGE_CLUSTER-1))];  // page cluster base
demp_eval_time dempTaskInfo[256]; // 256 for task number
kal_uint32 pageCluster = PAGE_CLUSTER;
kal_uint32 executionTime = 0;  // Total execution Time 
kal_uint32 executionTimeStart = 0;
kal_uint32 worstFaultTime = 0;
kal_uint32 swapTime[SWAPTIMERANKNUM] = {0};
kal_bool dempProfiling = KAL_FALSE;
extern void * volatile TCD_Current_Thread;

#endif /*__DEMAND_PAGING_PERFORMANCE_PROFILING__*/
/*******************************************************************************
 * Define import global data.
 *******************************************************************************/

extern kal_uint32 page_tbl[];
extern FTL_FuncTbl ftlFuncTbl;

/*******************************************************************************
 * Define import function prototypes.
 *******************************************************************************/

extern kal_uint32 alloc_ptbl(kal_uint32 size);
extern kal_uint32 kal_get_mytask_priority(void);
extern kal_bool INT_QueryExceptionStatus(void);
extern kal_bool kal_if_hisr(void);
extern kal_bool kal_if_lisr(void);
extern kal_uint32 CheckIRQLock(void);
extern kal_uint32 INT_SwitchStackToRun(void *stack_start, kal_uint32 stack_size, kal_func_ptr func, kal_uint32 argc, ...);

/*************************************************************************
* FUNCTION
*  set_smallest_pd
*
* DESCRIPTION
*  This function sets the tiny page descriptor
*
* PARAMETERS
*  ptbl    -    address of page table
*  val     -    set value
*
* RETURNS
*  none
*
*************************************************************************/
void set_smallest_pd(kal_uint32 smallest_pd, kal_uint32 val)
{
    //prevent build warning: variable "temp" was set but never used
    volatile kal_uint32 temp;
    /* enforce cache in */
    temp = *(kal_uint32 *)(MAP2CREGVA(smallest_pd));

    /* write to cache */
    *(kal_uint32 *)(MAP2CREGVA(smallest_pd)) = val;

    cp15_clean_dcache_single((kal_uint32)MAP2CREGVA(smallest_pd));
}


/*************************************************************************
* FUNCTION
*  smallest_ptd_alloc
*
* DESCRIPTION
*  This function gets a find page table descriptor for the specified 
*  (virtual) address.
*
* PARAMETERS
*  vaddr    -   specified virtual address
*
* RETURNS
*  pointer to the fine page table descriptor
*
*************************************************************************/
kal_uint32 *smallest_ptd_alloc(kal_uint32 vaddr)
{
    if (!is_smallest_ptd(page_tbl[vaddr >> PAGE_SIZE_1MB_SHIFT])) {
        return NULL;
    }

    return (kal_uint32 *)&(page_tbl[vaddr >> PAGE_SIZE_1MB_SHIFT]);
}


/*************************************************************************
* FUNCTION
*  smallest_pd_alloc
*
* DESCRIPTION
*  This function gets a tiny page descriptor for the specified (virtual) 
*  address.
*
* PARAMETERS
*  vaddr    -   specified virtual address
*
* RETURNS
*  pointer to the tiny page descriptor
*
*************************************************************************/
kal_uint32 *smallest_pd_alloc(kal_uint32 vaddr)
{
    kal_uint32 *smallest_ptd;
    kal_uint32 *smallest_pd;

    smallest_ptd = smallest_ptd_alloc(vaddr);
    if (smallest_ptd == NULL) {
        /* out-of-memory */
        return NULL;
    }

    smallest_pd = (kal_uint32 *)(smallest_td_tba(*smallest_ptd)) + ((vaddr & FIRST_LEVEL_SMALLEST_L2PT_INDEX_RETRIEVE) >> SMALLEST_PAGE_SIZE_SHIFT);
    return smallest_pd;
}

/*************************************************************************
* FUNCTION
*  is_anyone_lock
*
* DESCRIPTION
*   
*  Check if any user lock this page
*
* PARAMETERS
*  page to check lock
*
* RETURNS
*  if there is anyone lock this page -> KAL_TRUE or KAL_FALSE 
*
*************************************************************************/
kal_bool is_anyone_lock(demp_page_t *page)
{
    kal_uint32 i = 0;
    for(i = 0; i < DEMP_LOCK_USER_NUM; i++){        
        if(page->lock_count[i] > 0)
	  return KAL_TRUE;
    }
    return KAL_FALSE;
}
/*************************************************************************
* FUNCTION
*  is_other_user_lock
*
* DESCRIPTION
*   
*  Check if user NOT in parameter lock this page
*
* PARAMETERS
*  page to check lock
*  user (except this user, is there other user lock this page?)
* RETURNS
*  if there is other user lock this page -> KAL_TRUE or KAL_FALSE 
*
*************************************************************************/
kal_bool is_other_user_lock(demp_page_t *page, kal_uint8 user)
{
    kal_uint32 i = 0;
    for(i = 0; i < DEMP_LOCK_USER_NUM; i++){
        if((page->lock_count[i] > 0) && (i != user))
	  return KAL_TRUE;
    }
    return KAL_FALSE;
}
#endif  /* __MTK_TARGET__ && __DEMAND_PAGING__ */
//above function won't expose to other users, so we don't keep dummy function
/*************************************************************************
* FUNCTION
*  demp_initial 
*
* DESCRIPTION
*  initialize demand paging structure 
* 
*
* PARAMETERS
*  no parameter 
*
* RETURNS
*  no return value
*
*************************************************************************/
#if defined(__MTK_TARGET__) && defined(__DEMAND_PAGING__)
void demp_initial(){
    kal_uint32 blk_size, addr, block, ret, i, j;
    kal_uint16** img_tbl;
    
    ret = custom_config_demp_page((kal_uint32 **)&demp_page_list, &demp_page_pool, &demp_page_pool_size);
    ASSERT(ret == 0);
    demp_page_list_init();
    img_tbl = (kal_uint16 **)custom_get_demp_image_table();
    for (i = 0; i < demp_bin_num(); i++) {
        demp_ninfo.img_tbl[i] = img_tbl[i];
        blk_size = demp_ninfo.blk_page_nr * (1 << demp_ninfo.npage_shift);
        block = demp_ninfo.block[i];
        for (addr = demp_ninfo.begin_addr[i], j = 0; addr < demp_ninfo.end_addr[i]; addr += blk_size, j++) {
            do {
                if(ftlFuncTbl.FTL_CheckGoodBlock(block, NULL) == 0) {
                    break;
                } else {
                    block++;
                    continue;
                }
            } while (1);
            *(demp_ninfo.img_tbl[i] + j) = block;
            block++;
        }
    }
    demp_debug_init();
    swap_in_mutex = kal_create_enh_mutex("DempSwap");

}
#else
void demp_initial(){

}
#endif  /* __MTK_TARGET__ && __DEMAND_PAGING__ */


/*************************************************************************
* FUNCTION
*  do_page_fault
*
* DESCRIPTION
*  This function handles page fault.
*
* PARAMETERS
*  error_type   -   3 for instruction fault; 4 for data fault
*  addr         -   fault address
*
* RETURNS
*  0 for success; others for failure
*
*************************************************************************/
#if defined(__MTK_TARGET__) && defined(__DEMAND_PAGING__)
kal_int32 demp_do_page_fault(kal_uint32 error_type, kal_uint32 addr, kal_uint32 fsr, kal_uint32 pc_return)
{
    kal_uint32 irq, task_index, org_pd_permission;
    kal_uint32 *smallest_pd;
    kal_int32 demp_bin, ret = -1, i;
    demp_page_t *page;
    MMU_PAGE_CONFIG_T pagc;
    kal_int32 demp_balance_count, prio;
    kal_bool concurrency = KAL_FALSE;
#if  defined(__DEMAND_PAGING_PERFORMANCE_PROFILING__)
    kal_uint32 pageStart, index,  faultTickStart;
    kal_int32 timeDur;
#endif
    demp_log_begin;

    /* update the nested counter */
    irq = SaveAndSetIRQMask();
    demp_nested_count++;
    RestoreIRQMask(irq);    

    
    /* get fault address */
    if (error_type == 3) {
        /* address is already the fault address */
    } else if (error_type == 4) {
        if ((fsr & FSR_STATUS_MASK) != FSR_STATUS_TRAN_PAGE) {	
            demp_err_code = -1;
            demp_trace(SYSTRACE_GROUP_DEMP, DEMP_ERR_CODE, demp_err_code);
            
            return demp_err_code;
        }
    } else {
        demp_err_code = -2;
        demp_trace(SYSTRACE_GROUP_DEMP, DEMP_ERR_CODE, demp_err_code);        
        
        return demp_err_code;
    }

    /* check which bin va residents */
    /* and ensure the address can be swaped in */	
    for (demp_bin = 0; demp_bin < demp_bin_num(); demp_bin++) {
        if (demp_begin(demp_bin) <= addr && addr <= demp_end(demp_bin)) {
            break;
        }
    }
    if (demp_bin >= demp_bin_num()) {
        demp_err_code = -3;
        demp_trace(SYSTRACE_GROUP_DEMP, DEMP_ERR_CODE, demp_err_code);
        
        return demp_err_code;
    }

    /* check if HISR/LISR abuse */
    if (!INT_QueryExceptionStatus() && kal_if_lisr()) {
        kal_fatal_error_handler(KAL_ERROR_DEMP_LISR_MISUSE_DEMP_FAILED, pc_return);
    }
    else if(!INT_QueryExceptionStatus() && kal_if_hisr()){
        kal_fatal_error_handler(KAL_ERROR_DEMP_HISR_MISUSE_DEMP_FAILED, pc_return);
    }
    /*Check irq is lock or not*/
    if(kal_query_systemInit() == KAL_FALSE && INT_QueryExceptionStatus() == KAL_FALSE){
        irq = CheckIRQLock();
        if(irq != 0)
            kal_fatal_error_handler(KAL_ERROR_DEMP_LOCKOUT_IBIT_MISUSE_DEMP_FAILED, pc_return);
    }
    /* log enter demand paging after checking HISR/LISR misuse */
#if defined(__DEMAND_PAGING_DEBUG__)
    kal_get_my_task_index(&task_index);
    prio = kal_get_mytask_priority();
#endif    
    demp_trace(SYSTRACE_GROUP_DEMP, DEMP_PAGE_FAULT_ENTER, task_index, prio, error_type, addr, fsr, demp_nested_count);    
#if defined(__DEMAND_PAGING_PERFORMANCE_PROFILING__)
     irq = SaveAndSetIRQMask();	   
     index = kal_get_current_task_index();
     if(dempProfiling == KAL_TRUE && demp_bin == 0){
          pageStart = (addr - demp_begin(demp_bin)) >> (demp_npage_shift() + PAGE_CLUSTER - 1);
          if(dempPoolStats[pageStart].totalFaultCount == 0){
	          strncpy(dempPoolStats[pageStart].Owner,  ((TC_TCB *)TCD_Current_Thread)->tc_name, TASKNAMELEN);
          }	    
         if(dempPoolStats[pageStart].totalFaultCount < HISTORYNUM)
              dempPoolStats[pageStart].lastAccessAddr[dempPoolStats[pageStart].totalFaultCount] = addr;
          dempPoolStats[pageStart].totalFaultCount++;          
          dempTaskInfo[index].status = 1;
          dempTaskInfo[index].faultCountPerTask++;          
          faultTickStart = ust_get_current_time();
      }
      RestoreIRQMask(irq);
#endif	
    /*
     * allocate one free page 
     */

    demp_trace(SYSTRACE_GROUP_DEMP, DEMP_PAGE_ALLOC_ENTER);
    demp_balance_count = 0;
    do {
        irq = SaveAndSetIRQMask();

        /* check if the tpd is valid before page allocation */
        smallest_pd = smallest_pd_alloc(DEMP_ADDR_ALIGN_PAGE(addr));
        if(smallest_pd == NULL) {
            ASSERT(0);
            //return -1;
        }
        /* if the tpd has been updated by another fault (including pages locked), return immediately */	
        if(is_smallest_pd(*smallest_pd)) {
            RestoreIRQMask(irq);

            return 0;
        }

        demp_page_alloc(page, addr, concurrency);

        if (demp_page_is_inuse(page)) {
            /* reeanble IRQ temporarily */
            RestoreIRQMask(irq);

            /*
            * NoteXXX: If there is no page in active queue and inactive queue,
            *          it will fall in an infinite loop between demp_page_alloc & demp_lru2q_balance.
            *          This may happen when continuous preemption occurs,
            *          so we have an assumption here:
            *          Number of total page must larger than number of demand paging user.
            */
            demp_lru2q_balance(irq, SaveAndSetIRQMask, RestoreIRQMask);
            demp_balance_count++;

            continue;
        } else {
            /* theoretically, you would never get a locked page */
            if (is_anyone_lock(page)) {
                ASSERT(0);
            }
		
            demp_page_set_inuse(page);

            RestoreIRQMask(irq);
            break;
        }
    } while (1);
    demp_trace(SYSTRACE_GROUP_DEMP, DEMP_PAGE_ALLOC_EXIT, page->va, page->pa, demp_balance_count);

    if (demp_page_is_valid(page, addr)) {
        /* swap out in-use page */
        demp_trace(SYSTRACE_GROUP_DEMP, DEMP_PAGE_SWAPOUT_ENTER, page->va, addr);

        smallest_pd = smallest_pd_alloc(page->va);
        if (smallest_pd == NULL) {
            ASSERT(0);
        }

        /*
         * do swap out
         */

#if defined(__ARM11_MMU__)
        DEFAULT_RO_CB((MMU_PAGE_CONFIG_PTR)&pagc);
#endif /* __ARM11_MMU__ */
        irq = SaveAndSetIRQMask();
        org_pd_permission = is_smallest_pd(*smallest_pd); //if org_pd_permission > 0 , users can access this page
        if(page->pa == (*(smallest_pd) & ~SMALLEST_PAGE_SIZE_MASK)){
#if defined(__ARM11_MMU__)
	        if(!org_pd_permission){ // for ARM11 case, set pd permission: accessible. (For invalidate cache operation)
	        	for (i = NR_TLB; i != 0; i--) {
	            set_smallest_pd((kal_uint32)(smallest_pd + i - 1), mk_smallest_pd(page->pa + ((i - 1) << FIRST_LEVEL_SMALLEST_L2PT_INDEX_SHIFT), &pagc));	            
	            cp15_invalidate_tlb_single(page->va + ((i - 1) << FIRST_LEVEL_SMALLEST_L2PT_INDEX_SHIFT));
	          }
	        }
	        /* drain the write buffer */
	        cp15_drain_write_buffer();
#endif /* __ARM11_MMU__ */
	        /* invalidate ICache and DCache for swap-out regions */
	        invalidate_cache_per_page(page->va);
	        /* invalidate smallest_pd and TLB for swap-out regions */
	        if(!org_pd_permission){
	           for (i = NR_TLB; i != 0; i--) {
	              set_smallest_pd((kal_uint32)(smallest_pd + i - 1), (*(smallest_pd + i - 1)) & ~SMALLEST_PAGE_SIZE_MASK);	                
	              cp15_invalidate_tlb_single(page->va + ((i - 1) << FIRST_LEVEL_SMALLEST_L2PT_INDEX_SHIFT));
	           }
	        }
	        /* drain the write buffer */
	        cp15_drain_write_buffer();
        }
        RestoreIRQMask(irq);

        demp_log_swapout(page);
        
        demp_trace(SYSTRACE_GROUP_DEMP, DEMP_PAGE_SWAPOUT_EXIT);
    }

    /* initliaze the page */
    demp_page_init(page);

    if (!demp_page_is_data_avail(page, addr)) {
        demp_trace(SYSTRACE_GROUP_DEMP, DEMP_PAGE_SWAPIN_ENTER, page->va, addr, prio);
    	
        /* ensure alignment */
        page->va = DEMP_ADDR_ALIGN_PAGE(addr);

        demp_log_nandr_1();

        /* do swap in */
        {
            // KeTing: Use a dedicate stack for swap in to save the task stack size
            // KeTing: Note static local variables will not reside on the stack
            
            if (kal_query_systemInit() == KAL_FALSE && INT_QueryExceptionStatus() == KAL_FALSE)
            {
                kal_take_enh_mutex(swap_in_mutex);
            }
            ret = INT_SwitchStackToRun(swap_in_stack, PAGE_SWAP_IN_STACK_SIZE,
                                       (kal_func_ptr)Swapin_Read, 3, demp_bin, page->va, page->pa);          

            if (kal_query_systemInit() == KAL_FALSE && INT_QueryExceptionStatus() == KAL_FALSE)
            {
                kal_give_enh_mutex(swap_in_mutex);
            }
        }

        if (ret == -1) {
            demp_page_set_free(page, irq, SaveAndSetIRQMask, RestoreIRQMask);
            
            demp_err_code = -4;
            demp_trace(SYSTRACE_GROUP_DEMP, DEMP_ERR_CODE, demp_err_code);
            
            return demp_err_code;
        }

        demp_log_nandr_2();
        
        demp_trace(SYSTRACE_GROUP_DEMP, DEMP_PAGE_SWAPIN_EXIT, page->va, addr, prio);
    }

    /*
     * Update the page table.
     */

    /* get the related tiny page descriptor */
    smallest_pd = smallest_pd_alloc(page->va);
    if (smallest_pd == NULL) {
        //demp_page_set_free(page, irq, SaveAndSetIRQMask, RestoreIRQMask);
        ASSERT(0);
        //return -1;
    }

    demp_trace(SYSTRACE_GROUP_DEMP, DEMP_PTABLE_UPDATE_ENTER, smallest_pd, *smallest_pd);

    irq = SaveAndSetIRQMask();
       
    if (is_smallest_pd(*smallest_pd)) {
        /* already swap-in by another fault */
        page->va = 0;
        /* drain the write buffer */
        cp15_drain_write_buffer();
    } else {
      
        DEFAULT_RO_CB((MMU_PAGE_CONFIG_PTR)&pagc);
        /* if other user is using page belong to me... */
        if(concurrency == KAL_TRUE){
#if defined(__ARM11_MMU__)
	         for (i = NR_TLB; i != 0; i--) {
	            set_smallest_pd((kal_uint32)(smallest_pd + i - 1), mk_smallest_pd(*smallest_pd + ((i - 1) << FIRST_LEVEL_SMALLEST_L2PT_INDEX_SHIFT), &pagc));	            
	            cp15_invalidate_tlb_single(page->va + ((i - 1) << FIRST_LEVEL_SMALLEST_L2PT_INDEX_SHIFT));
	         }
	         /* drain the write buffer */
	         cp15_drain_write_buffer();
#endif /* __ARM11_MMU__ */        	
           invalidate_cache_per_page(page->va); // invalidate fault addr's cache to prevent race condition for VIPT cache
        }
        
        for (i = NR_TLB; i != 0; i--) {
            set_smallest_pd((kal_uint32)(smallest_pd + i - 1), mk_smallest_pd(page->pa + ((i - 1) << FIRST_LEVEL_SMALLEST_L2PT_INDEX_SHIFT), &pagc));
            cp15_invalidate_tlb_single(page->va + ((i - 1) << FIRST_LEVEL_SMALLEST_L2PT_INDEX_SHIFT));
        }
                
        /* drain the write buffer */
        cp15_drain_write_buffer();
        
        demp_log_swapin(page);
    }
    
    RestoreIRQMask(irq);

    demp_trace(SYSTRACE_GROUP_DEMP, DEMP_PTABLE_UPDATE_EXIT, smallest_pd, *smallest_pd);

    /* OK to unlock the page now */
    demp_page_set_free(page, irq, SaveAndSetIRQMask, RestoreIRQMask);

    demp_log(error_type, addr);
    
    /* update the nested counter */
    irq = SaveAndSetIRQMask();
    demp_nested_count--;
    RestoreIRQMask(irq);
    
#if defined(__DEMAND_PAGING_PERFORMANCE_PROFILING__)
    irq = SaveAndSetIRQMask();
    if(dempProfiling == KAL_TRUE && dempTaskInfo[index].status == 1 && demp_bin == 0){
        timeDur = (ust_get_duration(faultTickStart, ust_get_current_time()) - dempTaskInfo[index].preemptTime);
        if(timeDur > worstFaultTime)	  
              worstFaultTime = timeDur;
        dempPoolStats[pageStart].totalFaultTime += timeDur;
        dempTaskInfo[index].status = 0;
        dempTaskInfo[index].preemptTime = 0;	  
    }
    RestoreIRQMask(irq);
#endif    

    demp_trace(SYSTRACE_GROUP_DEMP, DEMP_PAGE_FAULT_EXIT, task_index, prio, error_type, addr, fsr);
    return 0;
}
#else
kal_int32 demp_do_page_fault(kal_uint32 error_type, kal_uint32 addr, kal_uint32 fsr, kal_uint32 pc_return){
	return -1;
}
#endif  /* __MTK_TARGET__ && __DEMAND_PAGING__ */
#if defined(__DEMAND_PAGING_PERFORMANCE_PROFILING__) && defined(__MTK_TARGET__) && defined(__DEMAND_PAGING__)
void demp_preempt_time_start(){
    kal_uint16 index;
    kal_uint32 irq;
    if(kal_if_hisr() || kal_if_lisr()){
    	;
    }
    else{	    	
	if(TCD_Current_Thread != NU_NULL){
	      irq = SaveAndSetIRQMask();
	      index = kal_get_current_task_index();
          if(dempTaskInfo[index].status == 1){
	          dempTaskInfo[index].status = 2;
                      dempTaskInfo[index].preemptTimeStart = ust_get_current_time(); 
	      }
	      RestoreIRQMask(irq);
	}
    }
}

void demp_preempt_time_end(){
    kal_uint16 index;
    kal_int32 timeDur, irq;
    if(kal_if_hisr() || kal_if_lisr()){
    	;
    }
    else{	            
        if(TCD_Current_Thread != NU_NULL){
            irq = SaveAndSetIRQMask();
            index = kal_get_current_task_index();
            if(dempTaskInfo[index].status == 2){
                  dempTaskInfo[index].status = 1;
          timeDur = ust_get_duration(dempTaskInfo[index].preemptTimeStart, ust_get_current_time());
	      if(timeDur > 0)
            dempTaskInfo[index].preemptTime += timeDur;
           }
              RestoreIRQMask(irq);
        }	    	
    }
}
#else
void demp_preempt_time_start(){

}
void demp_preempt_time_end(){

}
#endif  /* __MTK_TARGET__ && __DEMAND_PAGING__ */

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
#if defined(__MTK_TARGET__) && defined(__DEMAND_PAGING__)
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MTK_TARGET__ && __DEMAND_PAGING__ */
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
#if defined(__MTK_TARGET__) && defined(__DEMAND_PAGING__)
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MTK_TARGET__ && __DEMAND_PAGING__ */
#endif
/*************************************************************************
* FUNCTION
*     do_pages_lock
*
* DESCRIPTION
*     This function locks continuous pages.
*
* PARAMETERS
*     user   -   lock user
*     addr   -   starting address
*     length -   number of bytes be locked
*
* RETURNS
*     0: successful
*     -1: failed
*
*************************************************************************/
#if defined(__MTK_TARGET__) && defined(__DEMAND_PAGING__)
kal_int32 do_pages_lock(demp_lock_user user, kal_uint32 addr, kal_uint32 length) {
    kal_int32 ret = -1;
    kal_uint32 demp_page_size = (1 << (PAGE_SHIFT_2K + (PAGE_CLUSTER - 1)));
    kal_uint32 lock_count, align_addr, lock_addr, lr;
    //prevent build warning: variable "data" was set but never used
    volatile kal_uint32 data; 
    kal_uint32 irq, pa, i, j;
    kal_uint32 *smallest_pd;
    demp_page_t *page;

    GET_RETURN_ADDRESS(lr);

    demp_trace(SYSTRACE_GROUP_DEMP, DEMP_LOCK_ENTER, user, addr, length);

    /* check if valid lock users */
	if (user >= DEMP_LOCK_USER_NUM) {
        kal_fatal_error_handler(KAL_ERROR_DEMP_INVALID_LOCK_USER_FAILED, lr);
    }
	
    /* adjust the memory range to be locked */
    align_addr = addr & ~(demp_page_size - 1); /* round down & make alignment */
    length += (addr & (demp_page_size - 1)); /* compensate length*/
    lock_count = length / demp_page_size;
    if ((length & (demp_page_size - 1)) != 0)
    {
        lock_count += 1;
    }

    /* lock each page */
    ret = 0;
    for (i = 0; i < lock_count; i++)
    {
        lock_addr = align_addr + (i * demp_page_size);
        /* ensure the memory range could be swaped in */
        for (j = 0; j < demp_bin_num(); j++) {
            if (demp_begin(j) <= lock_addr && lock_addr <= demp_end(j)) {
                break;
            }
        }
        if (j >= demp_bin_num()) {
            ret = -1;
            continue;
        }
		
        /* get the page descriptor */
        smallest_pd = smallest_pd_alloc(lock_addr);
        if (smallest_pd == NULL) {
            ASSERT(0);
            //return -1;
        }

        do {
            /* do a dummy read to enforce swaping in the memory page if necessary */
            data = *(volatile kal_uint32 *)lock_addr;
    
            irq = SaveAndSetIRQMask();
            pa = *smallest_pd & ~SMALLEST_PAGE_SIZE_MASK;
            demp_page_search(pa, page);
            if (is_smallest_pd(*smallest_pd)) { /* already swap-in */

                if(is_anyone_lock(page) == KAL_FALSE){ // is there anyone lock this page ? NO                        
		                demp_page_set_lock(page);
                        demp_lock_count[user][ACC_IDX] += demp_page_size;
                        if (user == DEMP_LOCK_AUDIO || user == DEMP_LOCK_VIDEO) {
                            demp_lock_count[DEMP_LOCK_AUDIO_VIDEO][ACC_IDX] += demp_page_size;
                        }					
                        /* lock quota check */
                        if ((demp_lock_count[user][ACC_IDX] >= demp_lock_count[user][MAX_IDX]) ||
                            (demp_lock_count[DEMP_LOCK_AUDIO_VIDEO][ACC_IDX] >= demp_lock_count[DEMP_LOCK_AUDIO_VIDEO][MAX_IDX])) {
                            RestoreIRQMask(irq);
                            kal_fatal_error_handler(KAL_ERROR_DEMP_EXHAUST_LOCK_QUOTA_FAILED, lr);
                        }
                }
                else{ // Yes
                    if (page->lock_count[user] == 0) {
                        demp_lock_count[user][ACC_IDX] += demp_page_size;
                        if (user == DEMP_LOCK_AUDIO || user == DEMP_LOCK_VIDEO) {
                            demp_lock_count[DEMP_LOCK_AUDIO_VIDEO][ACC_IDX] += demp_page_size;
                        }					
                        /* lock quota check */
                        if ((demp_lock_count[user][ACC_IDX] >= demp_lock_count[user][MAX_IDX]) ||
                            (demp_lock_count[DEMP_LOCK_AUDIO_VIDEO][ACC_IDX] >= demp_lock_count[DEMP_LOCK_AUDIO_VIDEO][MAX_IDX])) {
                            RestoreIRQMask(irq);
                            kal_fatal_error_handler(KAL_ERROR_DEMP_EXHAUST_LOCK_QUOTA_FAILED, lr);
                        }
                    }
                    else if ((kal_uint8)(page->lock_count[user] + 1) == 0) {
                        /* lock counter overflow */
                         kal_fatal_error_handler(KAL_ERROR_DEMP_OVER_LOCK_UNLOCK_FAILED, lr);
                    }
                }
                page->lock_count[user]++;                		    
                RestoreIRQMask(irq);

                break;
            } else {
                /* invalidate the TLB entry in case of infinite loop */
                for (j = NR_TLB; j != 0; j--) {
                    cp15_invalidate_tlb_single(page->va + ((j - 1) << FIRST_LEVEL_SMALLEST_L2PT_INDEX_SHIFT));
                }
            	  
                /* redo */
                RestoreIRQMask(irq);
                continue;
            }
        } while(1);
		
        demp_trace(SYSTRACE_GROUP_DEMP, DEMP_LOCK, lock_addr);
    }

    demp_trace(SYSTRACE_GROUP_DEMP, DEMP_LOCK_EXIT, user, addr, length);

    return ret;
}
#else
kal_int32 do_pages_lock(demp_lock_user user, kal_uint32 addr, kal_uint32 length) {
    return -1;
}
#endif /* __MTK_TARGET__ && __DEMAND_PAGING__ */
/*************************************************************************
* FUNCTION
*     do_pages_unlock
*
* DESCRIPTION
*     This function un-locks continuous pages; it's a counterpart of do_pages_lock.
*
* PARAMETERS
*     user   -   lock user
*     addr   -   starting address
*     length -   number of bytes be unlocked
*
* RETURNS
*     0: successful
*     -1: failed
*
*************************************************************************/
#if defined(__MTK_TARGET__) && defined(__DEMAND_PAGING__)
kal_int32 do_pages_unlock(demp_lock_user user, kal_uint32 addr, kal_uint32 length) {
    kal_int32 ret = -1;
    kal_uint32 demp_page_size = (1 << (PAGE_SHIFT_2K + (PAGE_CLUSTER - 1)));
    kal_uint32 lock_count, align_addr, unlock_addr, lr;
    kal_uint32 irq, pa, i, j;
    kal_uint32 *smallest_pd;
    demp_page_t *page;

    GET_RETURN_ADDRESS(lr);

    demp_trace(SYSTRACE_GROUP_DEMP, DEMP_UNLOCK_ENTER, user, addr, length);

	/* check if valid lock users */
	if (user >= DEMP_LOCK_USER_NUM) {
        kal_fatal_error_handler(KAL_ERROR_DEMP_INVALID_LOCK_USER_FAILED, lr);
    }
	
    /* adjust the memory range to be locked */	
    align_addr = addr & ~(demp_page_size - 1); /* round down */
    length += (addr & (demp_page_size - 1)); /* compensate length*/
    lock_count = length / demp_page_size;
    if ((length & (demp_page_size - 1)) != 0)
    {
        lock_count += 1;
    }

    /* unlock each page */	
    ret = 0;
    for (i = 0; i < lock_count; i++)
    {
        unlock_addr = align_addr + (i * demp_page_size);
		
        /* ensure the memory range could be swaped in */
        for (j = 0; j < demp_bin_num(); j++) {
            if (demp_begin(j) <= unlock_addr && unlock_addr <= demp_end(j)) {
                break;
            }
        }
        if (j >= demp_bin_num()) {
            ret = -1;
            continue;
        }

        /* get the page descriptor */
        smallest_pd = smallest_pd_alloc(unlock_addr);
        if (smallest_pd == NULL) {
            ASSERT(0);
        }

        do {
            if (is_smallest_pd(*smallest_pd)) {
                /* already swap-in */
                pa = *smallest_pd & ~SMALLEST_PAGE_SIZE_MASK;
                demp_page_search(pa, page);
                irq = SaveAndSetIRQMask();
	              if(is_other_user_lock(page, user) == KAL_FALSE){ // is there are other user lock this page ? NO
                    if (page->lock_count[user] == 1) {
                        demp_page_set_unlock(page);	
                        demp_lock_count[user][ACC_IDX] -= demp_page_size;
                        if (user == DEMP_LOCK_AUDIO || user == DEMP_LOCK_VIDEO) {
                            demp_lock_count[DEMP_LOCK_AUDIO_VIDEO][ACC_IDX] -= demp_page_size;
                        }
                    }
                    else if (page->lock_count[user] == 0) {
                        /* invalid unlock */
                        kal_fatal_error_handler(KAL_ERROR_DEMP_OVER_LOCK_UNLOCK_FAILED, lr);					
                    }
	              }
	              else{ // Yes
                    if (page->lock_count[user] == 1) {
                        demp_lock_count[user][ACC_IDX] -= demp_page_size;
                        if (user == DEMP_LOCK_AUDIO || user == DEMP_LOCK_VIDEO) {
                            demp_lock_count[DEMP_LOCK_AUDIO_VIDEO][ACC_IDX] -= demp_page_size;
                        }
                    }
                    else if (page->lock_count[user] == 0) {
                        /* invalid unlock */
                        kal_fatal_error_handler(KAL_ERROR_DEMP_OVER_LOCK_UNLOCK_FAILED, lr);					
                    }
	              }
                page->lock_count[user]--;
                RestoreIRQMask(irq);
                break;
            } else {
                /* invalid unlock */
                kal_fatal_error_handler(KAL_ERROR_DEMP_OVER_LOCK_UNLOCK_FAILED, lr);
            }
        } while (1);

        demp_trace(SYSTRACE_GROUP_DEMP, DEMP_UNLOCK, unlock_addr);
    }

    demp_trace(SYSTRACE_GROUP_DEMP, DEMP_UNLOCK_EXIT, user, addr, length);

    return ret;
}
#else
kal_int32 do_pages_unlock(demp_lock_user user, kal_uint32 addr, kal_uint32 length) {
    return -1;	
}
#endif /* __MTK_TARGET__ && __DEMAND_PAGING__ */

#if defined(__DEMAND_PAGING_PERFORMANCE_PROFILING__) && defined(__MTK_TARGET__) && defined(__DEMAND_PAGING__)
// KeTing: To support change pool size on the fly
void do_page_pool_size_change(kal_uint32 sizeInMegaByte)
{
   kal_uint32 newSize = (sizeInMegaByte * 1024 * 1024) + TOTAL_MAX_LOCK_SIZE;

   // KeTing: check the argument
   {
      ASSERT(sizeInMegaByte <= 5); // KeTing: Max allowable pool size
      ASSERT(sizeInMegaByte >= 1); // KeTing: Min allowable pool size

      // KeTing: The size is not changed, do nothing
      if (newSize - demp_page_pool_size == 0)
      {
         return;
      }

      // KeTing: The new size should be larger then the origin
      ASSERT((kal_int32)(newSize - demp_page_pool_size) > 0);
   }

   // KeTing: the main body
   {
      // KeTing: Locate the new control blocks
      kal_uint32 newControlBlockStart = demp_page_pool_size >> (PAGE_SHIFT_2K + (PAGE_CLUSTER - 1));
      kal_uint32 newControlBlockEnd = newSize >> (PAGE_SHIFT_2K + (PAGE_CLUSTER - 1));
      kal_uint32 savedMask;

      savedMask = SaveAndSetIRQMask();
      // KeTing: Split the unused control block pool
      {
         //(demp_page_list + unusedControlBlock)->prev = (demp_page_list + increasedSize - 1);
         //(demp_page_list + increasedSize - 1)->next = (demp_page_list + unusedControlBlock);
         (demp_page_list + newControlBlockEnd)->prev = (demp_page_list + newControlBlockStart)->prev;
         ((demp_page_list + newControlBlockEnd)->prev)->next = (demp_page_list + newControlBlockEnd);
      }

      // KeTing: Insert the new page to the head of inactive list
      {
         (demp_page_list + newControlBlockStart)->prev = (demp_inactive_head.next)->prev;
         (demp_page_list + newControlBlockEnd - 1)->next = (demp_inactive_head.next);
         (demp_inactive_head.next)->prev = (demp_page_list + newControlBlockEnd - 1);
         ((demp_page_list + newControlBlockStart)->prev)->next = (demp_page_list + newControlBlockStart);
         demp_inactive_head.next = (demp_page_list + newControlBlockStart);
      }
      RestoreIRQMask(savedMask);

      // KeTing: Note this variable will be never changed besides this function
      // KeTing: Thus we do not have to put it in the critical section
      demp_page_pool_size = newSize;
   }
}
#endif  /* __DEMAND_PAGING_PERFORMANCE_PROFILING__ */

