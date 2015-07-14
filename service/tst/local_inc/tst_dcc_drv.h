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

/*******************************************************************************
 * Filename:
 * ---------
 *	tst_dcc_drv.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file includes the declaration of DCC driver on target for both ARM and FCore
 *
 * Author:
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

#ifndef __TST_DCC_DRV_H__
#define __TST_DCC_DRV_H__

//*******************************************************************************
// Define useful typedef for DCC
//*******************************************************************************
#if defined(__IVP__)
  #define __TST_DVT__
#endif  //#if defined(__IVP__)

#if defined(__ADS__) || defined(__RVCT__) || defined(__TST_DVT__) || defined(__GNUC__)
  #include "reg_base.h"
  #include "intrCtrl.h"
#endif  //#if defined(__ADS__) || defined(__RVCT__) || defined(__TST_DVT__)

typedef unsigned int uint32;
typedef int int32;
typedef unsigned short uint16;
typedef short int16;
typedef unsigned char uint8;
typedef char int8;

typedef enum
{
  DCC_FALSE=0,
  DCC_TRUE=1
}
dcc_bool;

//The following structure is used to keep thte status of DCC transmission pointers
//We keep this information when the TX buf is full or RX buf is empty
typedef struct
{
  uint32 tx_end;
  uint32 rx_end;
}
dcc_pre_transmission_status_t;

typedef enum
{
  DCC_TX_DIR,
  DCC_RX_DIR
}
dcc_transmission_direction_t;

typedef enum
{
  DCC_EXC_ERR = -1,
  DCC_EXC_OK,
  DCC_EXC_CMD,
  DCC_EXC_ACK,
  DCC_EXC_UNKNOWN,
  DCC_EXC_NOTHING
  
}
DCC_Exchange_Word_Ret;

#define DCC_ACCESS_MAGIC_NUM_1 '_MtK'
#define DCC_ACCESS_MAGIC_NUM_2 '_DcF'
#define DCC_RW_BUF_MAGIC_NUM 'MtDb'

//#define DCC_EXCHANGE_BLK_MAGIC_1 '_MtK'
#define DCC_EXCHANGE_BLK_MAGIC_1 'Wcp_'
#define DCC_EXCHANGE_BLK_VER (1013)
#define DCC_EXCHANGE_BLK_DNT_READY (0x24549ABC)
#define DCC_EXCHANGE_BLK_POSTMAN_READY (0x02812969)
//#define DCC_EXCHANGE_BLK_MAGIC_2 'sCfG'

//This field is meaningless for target
//It's only useful for SIB SW

#if defined(__ADS__) || defined(__RVCT__) || defined(__TST_DVT__) || defined(__GNUC__)
  #define CONFIG_DCC_CH_VAL 0
#elif defined(__FCORE__)
  #define CONFIG_DCC_CH_VAL 2
#elif defined(__DCC_SIM_ON_PC__)
  #define CONFIG_DCC_CH_VAL 0 //simulate ARM DCC
#endif  


//Workaround for TK6280 DEM interrupt issue, use LogAcc interrupt instead for compiling
#if defined(TK6280) || defined(BB_TK6280) 
	#define IRQ_CORESIGHT_DCC_MD_CODE IRQ_LA_CODE 
#endif

#if defined(__ADS__) || defined(__RVCT__) || defined(__TST_DVT__) || defined(__GNUC__)
  #define DCC_DEM_EXCAHNGE_ADDR (DEM_base)
  #define DCC_DEM_TRIG_INT_ADDR (DEM_base+0x4)  //should be useless for target SW
  #define IRQ_DCC_CODE (IRQ_CORESIGHT_DCC_MD_CODE)
#elif defined(__FCORE__)  //#if defined(__ADS__) || defined(__RVCT__) || defined(__TST_DVT__)    
  #define DCC_DEM_EXCAHNGE_ADDR (DEM_base+0x10)
  #define DCC_DEM_TRIG_INT_ADDR (DEM_base+0x14)  //should be useless for target SW
  #define IRQ_DCC_CODE (IRQ_CORESIGHT_DCC_DSP_CODE)
#elif defined(__DCC_SIM_ON_PC__)  //#elif defined(BFAOS)
  extern unsigned int dem_exchange_reg;
  extern unsigned int dem_trig_int_reg;
  #define DCC_DEM_EXCAHNGE_ADDR ((unsigned int)&dem_exchange_reg)
  #define DCC_DEM_TRIG_INT_ADDR ((unsigned int)&dem_trig_int_reg)  //should be useless for target SW    
#endif  //#elif defined(__DCC_SIM_ON_PC__)

#define DCC_DEM_RAISE_EVENT_REG_ADDDR (DEM_base+0x20)
#define DCC_DEM_MD_ARM_EXCAHNGE_ADDR (DEM_base)
  
#ifdef __DCC_SIM_ON_PC__
  extern unsigned int dem_raise_reg;  
  #undef DCC_DEM_RAISE_EVENT_REG_ADDDR
  #define DCC_DEM_RAISE_EVENT_REG_ADDDR ((unsigned int)&dem_raise_reg)
#endif  //#ifdef __DCC_SIM_ON_PC__

#define DCC_WRITE_DEM_EXCHANGE_WORD(data) do{*(volatile unsigned int*)DCC_DEM_EXCAHNGE_ADDR = data;}while(0)
#define DCC_READ_DEM_EXCHANGE_WORD(data) do{data = *(volatile unsigned int*)DCC_DEM_EXCAHNGE_ADDR;}while(0)

#define DCC_INIT_EXC_WORD_PATTERN (0x41000000)


//*******************************************************************************
// Define data structure
//*******************************************************************************
typedef struct
{
  uint32 rx_buf_read_start;
  uint32 rx_buf_read_end;
  uint32 rx_buf_siz;
  uint8* rx_buf_ptr;
  uint32 tx_buf_write_start;
  uint32 tx_buf_write_end;
  uint32 tx_buf_siz;
  uint8* tx_buf_ptr;  
  uint32 last_sib_ex_word;
  uint8 loop_back_mode; //1: enable, 0: disable; This feature should be supported by upper APs
}
DCC_Control_Block_t;

//This structure is used to put into exchange resigster to tell Postman where the exchange block is
typedef struct // Must be 32-bit aligned.
{
    uint32	magic;                // Equal to ¡¥Wcp_¡¦    
    uint32  version;              // DCC_EXCHANGE_BLK_VER (1013)
    uint32  postman_session_id;    // 0x02812969
    uint32  dnt_initialized;      // 0x24549ABC
    uint32  dcc_info_block;       // The address to  DccConfigRecord_t
    uint32  reserved;             // 
} DebugSwConfig_t;

// This structure (on target in global g_dccConfigRec) can be in NOR-Flash. Should be 
// created/initialized before starting to use DCC API.
typedef struct
{
   uint32 magic1;       // '_MtK'
   uint32 magic2;       // '_DcF'
   uint8  version;         // 0x0001 for now.
   uint8  reservedFlags;   // 0x0000 for now.
   uint8  t2HExtraBuffSize;// Number of extra 32 BYTE blocks in buffer from target to host. Max is 255
   uint8  h2TExtraBuffSize;// Number of extra 32 BYTE blocks in buffer from host to target. Max is 255
   uint32 h2TBuffAddr;     // physical address for H2T buffer (Written by SIB, Read by target)
   uint32 t2HBuffAddr;     // physical address for T2H buffer (Written by Target, Read by SIB)   
   uint32 channel;        // Value to write to above address to trig an software interrupt.
} DccConfigRecord_t;

//define the command type used by DCC channel
typedef enum
{
   DCC_CMD_NOP       =0x00,
   DCC_CMD_INIT      =0x01,
   DCC_CMD_PING      =0x02,
   DCC_CMD_LOOP_BACK =0x03
} DccCmd_t;

//*******************************************************************************
// Define useful macro
//*******************************************************************************

#ifndef STRUCT_MEMBER_OFFSET
   #define STRUCT_MEMBER_OFFSET(structure, member)((unsigned int) &(((structure *) 0)->member))
#endif

// Data order: (low to high) rdIndex:12, wrIndex:12, cmd:3, ack:3,change:2
#define dcc_buf_struct_t(extra) \
struct \
{ \
   volatile uint32         magic;  \
   volatile uint32         excWord; \
   volatile uint32         data[6+extra*8]; \
}


//bit field operation
#define DCC_RAISE_HAND() do{*(volatile int*) DCC_DEM_RAISE_EVENT_REG_ADDDR |= (1<<CONFIG_DCC_CH_VAL);}while(0)
#define SET_EXCHANGE_WORD(exchange_word,value, bit_length, bit_order) do{\
                                                                        exchange_word -= ( exchange_word & (((1<<(bit_length))-1) << bit_order));\
                                                                        exchange_word += (value << bit_order);\
                                                                      }while(0)

#define DCC_EXC_WORD_SET_READ_IDX(exchange_word, value) SET_EXCHANGE_WORD(exchange_word,value/4,12,0)
																													 
#define DCC_EXC_WORD_SET_WRITE_IDX(exchange_word, value) SET_EXCHANGE_WORD(exchange_word,value/4,12,12)
																														
#define DCC_EXC_WORD_SET_CMD(exchange_word, value) SET_EXCHANGE_WORD(exchange_word,value,3,24)
																										  
#define DCC_EXC_WORD_SET_ACK(exchange_word, value) SET_EXCHANGE_WORD(exchange_word,value,3,27)
																											
#define DCC_EXC_WORD_SET_CHANGE(exchange_word, value) do{ exchange_word ^= (value << 30);}while(0)

#define GET_EXCHANGE_WORD(exchange_word,value, bit_length, bit_order) do{value = ((exchange_word & (((1<<(bit_length))-1) << bit_order)) >> bit_order); }while(0)                  
                                                                      
#define DCC_EXC_WORD_GET_READ_IDX(exchange_word, value) do{\
                                                          GET_EXCHANGE_WORD(exchange_word,value,12,0);\
                                                          value = value*4;\
                                                        }while(0);
#define DCC_EXC_WORD_GET_WRITE_IDX(exchange_word, value) do{\
                                                           GET_EXCHANGE_WORD(exchange_word,value,12,12);\
                                                           value = value*4;\
                                                         }while(0)
#define DCC_EXC_WORD_GET_CMD(exchange_word, value) GET_EXCHANGE_WORD(exchange_word,value,3,24)
#define DCC_EXC_WORD_GET_ACK(exchange_word, value) GET_EXCHANGE_WORD(exchange_word,value,3,27)
#define DCC_EXC_WORD_GET_CHANGE(exchange_word, value) GET_EXCHANGE_WORD(exchange_word,value,2,30)
//To prevent RVCT 3.1 bug
#define DCC_EXC_WORD_GET_RW_IDX(exchange_word, rd_idx, wr_idx) do{\
                                                                GET_EXCHANGE_WORD(exchange_word,wr_idx,24,0);\
                                                                rd_idx = (wr_idx&0xFFF)<<2;\
                                                                wr_idx = (wr_idx&0xFFF000)>>10;\
                                                              }while(0)

#define DCC_CLEAR_IRQ_REG() do{*(volatile int*)DCC_DEM_TRIG_INT_ADDR = 0;}while(0)

//define the alignment type
//#if defined(__ADS__) || defined(__RVCT__) || defined(__TST_DVT__)    
#if defined(__MTK_TARGET__)
  #define FORCE_ADDR_ALIGN __attribute__((aligned(4))) //word aligned
#elif defined(__FCORE__) //#if defined(__MTK_TARGET__)
  //TODO: specify proper compile option
  #define FORCE_ADDR_ALIGN __align(4) //word aligned
#else //#if defined(__MTK_TARGET__)
  #define FORCE_ADDR_ALIGN
#endif  //#if defined(__MTK_TARGET__)

//define the information bit used in the change field
#define DCC_CHANGE_CMD    (0x1) // Toggles when writting new command.
#define DCC_CHANGE_ACK    (0x2) // Toggles when getting a ack.

//get the ring buffer size
#define DCC_Get_Free_Write_Buf_Size(free_size, buf_start, buf_end, buf_size) do{\
                              if (buf_start < buf_end){\
                                free_size = buf_end - buf_start - 4;}\
                              else{\
                                free_size = buf_size + buf_end - buf_start - 4;}\
                              }while(0)

#define DCC_Get_Free_Read_Buf_Size(free_size, buf_start, buf_end, buf_size) do{\
                              if (buf_start <= buf_end){\
                                free_size = (buf_end - buf_start);}\
                              else{\
                                free_size = buf_size + buf_end - buf_start;}\
                              }while(0)

//*******************************************************************************
// Define Constant
//*******************************************************************************
#ifdef __DCC_SIM_ON_PC__
  #define TST_DCC_RX_INFO_BUF_ADDR (&(g_DccAccessObj->refInData))
  #define TST_DCC_TX_INFO_BUF_ADDR (&(g_DccAccessObj->refOutData))
  #define TST_DCC_SIB_TARGET_INFO
  #define ASSERT assert  
#elif defined(__ADS__) || defined(__RVCT__) || defined(__GNUC__) || defined(__TST_DVT__)//#ifdef __DCC_SIM_ON_PC__
  //For ARM
  //TODO: specify the proper address and proper compile option
  #define TST_DCC_RX_INFO_BUF_ADDR
  #define TST_DCC_TX_INFO_BUF_ADDR
  
  #if defined(__TST_DVT__)
    #define ASSERT(exp) do{if (!(exp)) {\
                          dcc_print_msg(0, "Target asserts!!(%s,%s,%d)\n", __FILE__, __FUNCTION__, __LINE__);\
                          while(1);}\
                        }while(0)
  #endif  //#if defined(__TST_DVT__)

#elif defined(__FCORE__) //#ifdef __DCC_SIM_ON_PC__
  //For FCore
  //TODO: specify the proper address and proper compile option
  #define TST_DCC_RX_INFO_BUF_ADDR
  #define TST_DCC_TX_INFO_BUF_ADDR  
#else //#ifdef __DCC_SIM_ON_PC__
    #error "Non-supported platform"
#endif  //#ifdef __DCC_SIM_ON_PC__

// Extra defines how many extra 32-byte blocks should be used.
// Settings it to 0 gives in and out buffers with 6 UINT32 words.
// define how much buffer for DCC driver: size == 32*(x)+24 bytes
#define DCC_CONFIG_T2H_EXTRA (32)
#define DCC_CONFIG_H2T_EXTRA (32)

typedef struct _dcc_buf_T2H_struct_t
{
   volatile uint32         magic;  
   volatile uint32         excWord; 
   volatile uint32         data[6+DCC_CONFIG_T2H_EXTRA*8]; 
}dcc_buf_T2H_struct_t;

typedef struct _dcc_buf_H2T_struct_t
{
   volatile uint32         magic;  
   volatile uint32         excWord; 
   volatile uint32         data[6+DCC_CONFIG_T2H_EXTRA*8]; 
}dcc_buf_H2T_struct_t;


//*******************************************************************************
// Define function declaration
//*******************************************************************************

#endif  //__TST_DCC_DRV_H__
