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
 *   dcl_uart.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   Header file of DCL (Driver Common Layer) for UART.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifdef DCL_DEFINITION_STRUCT
#ifndef  __DCL_UART_STRUCT__
#define   __DCL_UART_STRUCT__

#include "kal_public_api.h"
#if defined(__CMUX_SUPPORT__)
#include "cmux_vp_num.h"
#define VIRTUAL_PORT_NUM  CMUX_VP_NUM
#else  // #if defined(__CMUX_SUPPORT__)
//#include "bt_common_config.h"
#define VIRTUAL_PORT_NUM  0
#endif // #if defined(__CMUX_SUPPORT__)


#define DCL_UART_DEV \
		uart_port1=0x00, \
		uart_port2, \
		uart_port3,\
		uart_port_irda,\
		uart_port_usb = 0x10,\
		uart_port_usb2,\
		uart_port_usb3,\
		uart_port_usb4,\
		uart_port_usb5,\
		uart_max_port_usb = 0x20,\
		uart_port_bluetooth,\
		uart_port_swdbg,\
		uart_port_tst_ccci,\
		uart_port_at_ccci,\
		uart_port_ccmni1_ccci,\
		uart_port_ccmni2_ccci,\
		uart_port_ccmni3_ccci,\
		uart_port_gps_ccci,\
		start_of_virtual_port,\
		end_of_virtual_port = (VIRTUAL_PORT_NUM + start_of_virtual_port),\
		uart_port_dcc,\
		uart_port_lga1,\
		uart_port_lga2,\
		uart_port_lmu,\
		uart_port_sp_usb,\
		uart_port_sp_usb_dsp,\
		uart_port_mini_log,\
        uart_port_dual_talk,\
		uart_max_port,\
		uart_port_null = 99,


/*******************************************************************************
 * DCL_CTRL_CMD for UART
 *******************************************************************************/
#define UART_CMDS \
	SIO_CMD_INIT = 0x00,\
	SIO_CMD_OPEN,\
	SIO_CMD_CLOSE,\
	SIO_CMD_GET_BYTES,\
	SIO_CMD_PUT_BYTES,\
	SIO_CMD_GET_RX_AVAIL,\
	SIO_CMD_GET_TX_AVAIL,\
	SIO_CMD_PUT_ISR_BYTES,\
	SIO_CMD_GET_ISR_TX_AVAIL,\
	SIO_CMD_PURGE,\
	SIO_CMD_SET_OWNER,\
	SIO_CMD_SET_FLOW_CTRL,\
	SIO_CMD_CONFIG_ESCAPE,\
	SIO_CMD_SET_DCB_CONFIG,\
	SIO_CMD_CTRL_DCD,\
	SIO_CMD_CTRL_BREAK, \
	SIO_CMD_CLR_RX_BUF,\
	SIO_CMD_CLR_TX_BUF, \
	SIO_CMD_SET_BAUDRATE, \
	SIO_CMD_SEND_ISR_DATA, \
	SIO_CMD_SEND_DATA, \
	SIO_CMD_GET_OWNER_ID, \
	SIO_CMD_SET_AUTOBAUD_DIV, \
	SIO_CMD_REG_TX_CB,\
	SIO_CMD_REG_RX_CB,\
	SIO_CMD_GET_UART_BYTE,\
	SIO_CMD_PUT_UART_BYTE,\
	SIO_CMD_PUT_UART_BYTES,\
	SIO_CMD_READ_DCB_CONFIG,\
	SIO_CMD_CTRL_RI,\
	SIO_CMD_GET_ESCAPE_INFO,\
	SIO_CMD_CTRL_DTR,\
	SIO_CMD_READ_HW_STATUS,\
	SIO_CMD_GET_UART_BYTE_WITH_TIMEOUT,\
	SIO_CMD_GIO_ENABLE,\
 	SIO_CMD_GIO_DISABLE,\
 	SIO_CMD_GIO_TX_SEND_DATA,\
 	SIO_CMD_GIO_TX_RECYCLE_GPD,\
 	SIO_CMD_GIO_TX_FLUSH_GPD,\
 	SIO_CMD_GIO_RX_RECV_DATA,\
 	SIO_CMD_GIO_RX_LOAD_GPD,\
 	SIO_CMD_GIO_RX_FLUSH_GPD,\
 	SIO_CMD_GIO_LOAD_DUMMY_GPD,\
	UART_CMD_UART_START = 0x100,\
	UART_CMD_SET_FIFO_TRIGGER,\
	UART_CMD_POWER_ON,\
	UART_CMD_CHECK_TX_BUF_EMPTY,\
	UART_CMD_CHECK_TX_SEND_OUT,\
	UART_CMD_GET_TX_BUF_SIZE,\
	UART_CMD_SLEEP_TX_ENABLE,\
	UART_CMD_CTRL_SLEEP_MODE,\
	UART_CMD_SWITCH_PORT,\
	UART_CMD_BOOTUP_INIT,\
	UART_CMD_BOOT_PUTBYTES,\
	UART_CMD_LOOPBACK,\
	UART_CMD_ASSERT_WAIT_SEND_OUT,\
	UART_CMD_CTRL_USE_VFIFO,\
	UART_CMD_GET_FLOW_CONTROL,\
	UART_CMD_REG_DEF_CB,\
	UART_CMD_BMT_PUT_BYTES,\
	UART_CMD_RECHANDLER_VFIFO,\
	UART_CMD_TRXHANDLER_VFIFO,\
	UART_CMD_RECTIMEOUTHANDLE,\
	UART_CMD_THRE_HDR_VFIFO,\
	UART_CMD_CTRL_TX_DMA,\
	UART_CMD_GET_MAX_BAUDRATE,\
	UART_CMD_UART_END,\
	USB_CMD_UART_START = 0x200,\
	USB_CMD_IS_CDCACM,\
	USB_CMD_HIGH_SPEED_IF_ENABLE, \
	USB_CMD_REG_TX_CB, \
	USB_CMD_TX_DATA_STATUS, \
	USB_CMD_SEND_DATA, \
	USB_CMD_GET_DATA, \
	USB_CMD_SEND_ISR_DATA, \
	USB_CMD_CTRL_SEND_DATA, \
	USB_CMD_CTRL_GET_DATA, \
	USB_CMD_HALT, \
	USB_CMD_FT_PORT, \
	USB_CMD_ACM_RING_BUFF_THRESHOLD_EN, \
	USB_CMD_USB2UART_TX_DMA_CBK, \
	USB_CMD_BOOT_PUTBYTES, \
	USB_CMD_IS_CDCACM_ACTIVE, \
	USB_CMD_GET_MPS, \
	USB_CMD_GET_TX_EP_NUMBER, \
	USB_CMD_GET_RX_EP_NUMBER, \
	USB_CMD_GET_HW_FIFO_ADDR, \
	USB_CMD_GET_HW_TXPKTRDY_ADDR, \
	USB_CMD_SET_HW_TXPKTRDY, \
	USB_CMD_HW_TX_DIRECT_PATH_ENABLE, \
	USB_CMD_PUSH_DATA, \
	USB_CMD_RX_RECV_DATA, \
	USB_CMD_TX_RECYCLE_GPD, \
	USB_CMD_TX_FLUSH_GPD, \
	USB_CMD_RX_FLUSH_GPD, \
	USB_CMD_CTRL_FLUSH_DATA, \
	USB_CMD_UART_END,


// 
typedef enum
{
	DCL_UART_TYPE = 0x00,
	DCL_UART_USB_TYPE,
	DCL_UART_BLUETOOTH_TYPE,
	DCL_UART_CMUX_TYPE,
	DCL_UART_SPPA_TYPE,
	DCL_UART_CCCI_TYPE,
	DCL_UART_DCC_TYPE,
	DCL_UART_LOGACC_TYPE,
	DCL_UART_LMU_TYPE,
	DCL_UART_SP_USB_TYPE,
	DCL_UART_MINI_LOG_TYPE,
	DCL_UART_DEV_TYPE_MAX
}SIO_TYPE_T;



typedef DCL_UINT32 UART_BAUDRATE_T;
typedef UART_BAUDRATE_T UART_baudrate;
typedef DCL_UINT16   UART_PORT;

#define     UART_BAUD_AUTO          0
#define     UART_BAUD_75            75
#define     UART_BAUD_150           150
#define     UART_BAUD_300           300
#define     UART_BAUD_600           600
#define     UART_BAUD_1200          1200
#define     UART_BAUD_2400          2400    
#define     UART_BAUD_4800          4800
#define     UART_BAUD_7200          7200
#define     UART_BAUD_9600          9600
#define     UART_BAUD_14400         14400
#define     UART_BAUD_19200         19200
#define     UART_BAUD_28800         28800
#define     UART_BAUD_33900         33900
#define     UART_BAUD_38400         38400
#define     UART_BAUD_57600         57600
#define     UART_BAUD_115200        115200
#define     UART_BAUD_230400        230400
#define     UART_BAUD_460800        460800
#define     UART_BAUD_921600        921600
#define     UART_BAUD_1500000       1500000 


typedef enum {
      LEN_5=5,
      LEN_6,
      LEN_7,
      LEN_8
} UART_BITS_PER_CHAR_T;

typedef enum {
      SB_1=1,
      SB_2,
      SB_1_5
} UART_STOP_BITS_T;

typedef enum {
      PA_NONE=0,
      PA_ODD,
      PA_EVEN,
      PA_MARK,
      PA_SPACE
} UART_PARITY_T;

/*
#if defined(FC_NONE)
#undef FC_NONE
#endif
*/

typedef enum {
      FC_NONE=1,
      FC_HW,
      FC_SW
} UART_FLOW_CTRL_MODE_T;

typedef enum {
      DCL_NONE_VFIFO,
      DCL_RX_VFIFO,
      DCL_TX_VFIFO,
      DCL_TXRX_VFIFO
} UART_VFIFO_T;

typedef enum {
      uart_sleep_on_tx_allow = 0,
      uart_sleep_on_tx_forbid
} UART_SLEEP_ON_TX;



typedef struct
{
   UART_BAUDRATE_T      u4Baud; 
   DCL_UINT8            u1DataBits; //UART_BITS_PER_CHAR_T
   DCL_UINT8            u1StopBits; //UART_STOP_BITS_T
   DCL_UINT8            u1Parity; //UART_PARITY_T
   DCL_UINT8            u1FlowControl; //UART_FLOW_CTRL_MODE_T
   DCL_UCHAR            ucXonChar;
   DCL_UCHAR            ucXoffChar;
   DCL_BOOLEAN             fgDSRCheck;
} UART_CONFIG_T;

typedef enum 
{
	DCL_IO_Low=0,
	DCL_IO_High
} IO_LEVEL_T;


typedef enum {
      DCL_RX_BUF,
      DCL_TX_BUF
} UART_BUFFER_T;

typedef enum {
      DCL_UART_SLEEP_ON_TX_ALLOW = 0,
      DCL_UART_SLEEP_ON_TX_FORBID,
} UART_SLEEP_ON_TX_T;

typedef enum {
      DCL_UART_BY_VFIFO,
      DCL_UART_BY_DMA,
      DCL_UART_BY_MCU,
      DCL_UART_BY_UNKNOWN
} UART_WORK_MODE;

//UART_CMD_INIT
typedef struct
{
	DCL_UINT32 u4Flag;
}UART_CTRL_INIT_T;

//UART_CMD_OPEN
typedef struct
{
  DCL_UINT32 u4OwenrId;
}UART_CTRL_OPEN_T;

//UART_CMD_CLOSE
typedef struct
{
  DCL_UINT32 u4OwenrId;
}UART_CTRL_CLOSE_T;

//UART_CMD_GET_BYTES
typedef struct
{
	DCL_UINT16 u2Length;
	DCL_UINT32 u4OwenrId;
	DCL_UINT16	u2RetSize;
	DCL_UINT8* puBuffaddr;
	DCL_UINT8*  pustatus;
	
}UART_CTRL_GET_BYTES_T;

//UART_CMD_PUT_BTYES
//UART_CMD_PUT_ISR_BYTES
typedef struct
{
	DCL_UINT16 u2Length;
	DCL_UINT32 u4OwenrId;
	DCL_UINT16	u2RetSize;
	DCL_UINT8* puBuffaddr;
}UART_CTRL_PUT_BYTES_T;

//UART_CMD_GET_RX_AVAIL
typedef struct
{
	DCL_UINT16 u2RetSize;
}UART_CTRL_RX_AVAIL_T;

//UART_CMD_GET_TX_AVAIL
//UART_CMD_GET_ISR_TX_AVAIL
typedef struct
{
	DCL_UINT16 u2RetSize;
}UART_CTRL_TX_AVAIL_T;

//UART_CMD_PURGE
typedef struct
{
	DCL_UINT32 u4OwenrId;
	UART_BUFFER_T dir;
}UART_CTRL_PURGE_T;

//UART_CMD_SET_OWNER
//UART_CMD_GET_OWNER_ID
typedef struct
{
	DCL_UINT32 u4OwenrId;
}UART_CTRL_OWNER_T;

//UART_CMD_SET_FLOW_CTRL
typedef struct
{
	DCL_UINT32 u4OwenrId;
	DCL_BOOL 	bXON;
}UART_CTRL_FLOW_CTRL_T;

//UART_CMD_CONFIG_ESCAPE
typedef struct
{
   DCL_UINT32 u4OwenrId;
   DCL_UINT8  uEscChar;
   DCL_UINT16 u2ESCGuardtime;
} UART_CTRL_CONFIG_ESP_T;

//UART_CMD_SET_DCB_COFIG
//UART_CMD_READ_DCB_CONFIG

typedef struct
{
	DCL_UINT32 u4OwenrId;
	UART_CONFIG_T  rUARTConfig;
} UART_CTRL_DCB_T;

//UART_CMD_CTRL_DCD

typedef struct
{
	DCL_UINT32 u4OwenrId;
	IO_LEVEL_T rIOLevelDCD;
} UART_CTRL_DCD_T;

//UART_CMD_GET_FLOW_CONTROL
typedef struct
{
	DCL_UINT32 u4OwenrId;
	UART_FLOW_CTRL_MODE_T FlowCtrlMode;
}UART_CTRL_GET_FC_T;


//UART_CMD_CTRL_BREAK
typedef struct
{
  DCL_UINT32 u4OwenrId;
   IO_LEVEL_T rIOLevelBRK;
} UART_CTRL_BREAK_T;

//UART_CMD_CLR_RX_BUF
//UART_CMD_CLR_TX_BUF
typedef struct
{
   DCL_UINT32 u4OwenrId;
} UART_CTRL_CLR_BUFFER_T;

//UART_CMD_SET_BAUDRATE
typedef struct
{
   DCL_UINT32 u4OwenrId;
   UART_BAUDRATE_T baudrate;
} UART_CTRL_BAUDRATE_T;

//UART_CMD_SEND_ISR_DATA
//UART_CMD_SEND_DATA
typedef struct
{
	DCL_UINT32 u4OwenrId;
	DCL_UINT8* puBuffaddr;
	DCL_UINT16 u2Length;
	DCL_UINT8 umode;
	DCL_UINT8 uescape_char;
	DCL_UINT16 u2RetSize;
}UART_CTRL_SEND_DATA_T;

//UART_CMD_SET_AUTOBAUD_DIV
typedef struct
{
   DCL_UINT32 u4OwenrId;
} UART_CTRL_AUTO_BAUDDIV_T;

typedef void (*DCL_UART_TX_FUNC)(DCL_UINT32 u4Port); 
typedef void (*DCL_UART_RX_FUNC)(DCL_UINT32 u4Port) ; 


//UART_CMD_REG_TX_CB
typedef struct
{
   DCL_UINT32 u4OwenrId;
   DCL_UART_TX_FUNC func;
} UART_CTRL_REG_TX_CB_T;

	
//UART_CMD_REG_RX_CB
typedef struct
{
	  DCL_UINT32 u4OwenrId;

   DCL_UART_RX_FUNC func;
} UART_CTRL_REG_RX_CB_T;

typedef enum
{
	UART_TX = 0,
	UART_RX,
	DSP_TX,
	DSP_RX
}UART_IO_DIR;

//UART_CMD_REG_DEF_CB
typedef struct
{
	UART_IO_DIR dir;
}UART_CTRL_REG_DEF_CB_T;

//UART_CMD_GET_UART_BYTE
typedef struct
{
	DCL_UINT8 uByte;
}UART_CTRL_GET_UART_BYTE_T;

//SIO_CMD_GET_UART_BYTE_WITH_TIMEOUT
typedef struct
{
	DCL_UINT8 u1retByte;  
	DCL_UINT8 uByte;
	DCL_UINT32 u4timeout_value;	
}UART_CTRL_GET_UART_BYTE_WITH_TIMEOUT_T;


//UART_CMD_PUT_UART_BYTE
typedef struct
{
	DCL_UINT8  uData;
}UART_CTRL_PUT_UART_BYTE_T;

//UART_CMD_PUT_UART_BYTES
typedef struct
{
	DCL_UINT8* puBuffaddr;
	DCL_UINT16 u2Length;
	
}UART_CTRL_PUT_UART_BYTES_T;

//UART_CMD_CTRL_RI
typedef struct
{
	 DCL_UINT32 u4OwenrId;
	IO_LEVEL_T rIOLevelSRI;

}UART_CTRL_RI_T;

//UART_CMD_CTRL_DTR
typedef struct
{
	 DCL_UINT32 u4OwenrId;
	IO_LEVEL_T rIOLevelDTR;
}UART_CTRL_DTR_T;

//UART_CMD_READ_HW_STATUS
typedef struct
{
	IO_LEVEL_T rIOLevelDSR;
	IO_LEVEL_T rIOLevelCTS;
}UART_CTRL_RHS_T;

//UART_CMD_SET_FIFO_TRIGGER
typedef struct
{
	DCL_UINT16 tx_level;
	DCL_UINT16 rx_level;
}UART_CTRL_SFT_T;

//UART_CMD_POWER_ON
typedef struct
{
	DCL_BOOL bFlag_Poweron;
}UART_CTRL_POWERON_T;

//UART_CMD_CHECK_TX_BUF_EMPTY
typedef struct
{
	DCL_BOOL bFlag;
}UART_CTRL_CHECK_TBE_T;

//	UART_CMD_CHECK_TX_SEND_OUT
typedef struct
{
	DCL_BOOL bFlag;
}UART_CTRL_CHECK_TSO_T;

//UART_CMD_GET_TX_BUF_SIZE
typedef struct
{
	DCL_UINT32* ptotal_size;
	DCL_UINT32* preturn_size;
}UART_CTRL_GET_TBS_T;


//UART_CMD_SLEEP_TX_ENABLE
typedef struct
{
	UART_SLEEP_ON_TX_T bFlag;
}UART_CTRL_SLEEP_ON_TX_ENABLE_T;

//UART_CMD_CTRL_SLEEP_MODE
typedef struct
{
	DCL_BOOL bFlag;
}UART_CTRL_SLEEP_ENABLE_T;


//UART_CMD_BOOT_PUTBYTES
typedef struct
{
	DCL_UINT8* puBuffaddr;
	DCL_UINT16 u2Length;
}UART_CTRL_BOOT_PUTBYTES_T;


//UART_CMD_CTRL_USE_VFIFO
typedef struct
{
	DCL_BOOL	bUseVFifo;
}UART_CTRL_USE_VFIFO_T;	

//UART_CMD_GET_MAX_BAUDRATE
typedef struct
{
	kal_uint32 max_baudrate;
}UART_CTRL_GET_MAXBAUDRATE_T;

//SIO_CMD_GIO_ENABLE
//ccci on sdio use UART interface
typedef struct
{
	kal_uint8  status;
	DCL_UINT32 option;
	DCL_UINT32 u4OwnerId;
}UART_GIO_ENABLE_T;

//SIO_CMD_GIO_DISABLE
typedef struct
{
	kal_uint8  status;
	DCL_UINT32 option;
	DCL_UINT32 u4OwnerId;
}UART_GIO_DISABLE_T;

//SIO_CMD_GIO_TX_SEND_DATA
typedef struct
{
//	DCL_UINT16	u2RetSize; //need to sync with STAN for handle of non-blocking behavior
	DCL_UINT8* pOut_GPD;
	DCL_UINT8* pIn_GPD;
	DCL_UINT8* pIn_GPD_last; /* add for MT6583 */
	DCL_UINT32 option;
	DCL_UINT32 u4OwnerId;
}UART_GIO_TX_SEND_DATA_T;

//SIO_CMD_GIO_TX_RECYCLE_GPD
typedef struct
{
	DCL_UINT32 option;
	DCL_UINT32 u4OwnerId;
	DCL_UINT8* pOut_GPD;
}UART_GIO_TX_RECYCLE_GPD_T;

//SIO_CMD_GIO_TX_FLUSH_GPD
typedef struct
{
	DCL_UINT32 option;
	DCL_UINT32 u4OwnerId;
	DCL_UINT8* pOut_GPD;
}UART_GIO_TX_FLUSH_GPD_T;

//SIO_CMD_GIO_RX_RECV_DATA
typedef struct
{
	DCL_UINT32 option;
	DCL_UINT32 u4OwnerId;
	DCL_UINT8* pOut_GPD;
}UART_GIO_RX_RECV_DATA_T;

//SIO_CMD_GIO_RX_LOAD_GPD
typedef struct
{
	DCL_UINT8* pIn_GPD;
        DCL_UINT8* pIn_GPD_last; /*add for MT6583*/
	DCL_UINT32 option;
	DCL_UINT32 u4OwnerId;
	DCL_UINT8* pOut_GPD;     /*add for MT6583*/
}UART_GIO_RX_LOAD_GPD_T;

//SIO_CMD_GIO_RX_FLUSH
typedef struct
{
	DCL_UINT32 option;
	DCL_UINT32 u4OwnerId;
	DCL_UINT8* pOut_GPD;
}UART_GIO_RX_FLUSH_GPD_T;

//SIO_CMD_LOAD_DUMMY_GPD
typedef struct
{
	DCL_UINT8* pTX_GPD;
	DCL_UINT32 TX_size;
	DCL_UINT8* pRX_GPD;
	DCL_UINT32 RX_size;
}UART_GIO_LOAD_DUMMY_GPD_T;

typedef enum {
      NONE_VFIFO,
      RX_VFIFO,
      TX_VFIFO,
      TXRX_VFIFO
} UART_TxRx_VFIFO_support;

typedef enum {
      RX_BUF,
      TX_BUF
} UART_buffer;

typedef enum {
   Compensate_None = 0,
   Compensate_Wait,
   Compensate_AT,
   Compensate_at
}UART_Compensate_enum;


typedef enum {
      len_5=5,
      len_6,
      len_7,
      len_8
} UART_bitsPerCharacter;

typedef enum {
      sb_1=1,
      sb_2,
      sb_1_5
} UART_stopBits;

typedef enum {
      pa_none=0,
      pa_odd,
      pa_even,
      pa_mark,
      pa_space
} UART_parity;

typedef enum {
      fc_none=1,
      fc_hw,
      fc_sw
} UART_flowCtrlMode;

typedef struct
{
      UART_baudrate                 baud; 
      UART_bitsPerCharacter         dataBits;
      UART_stopBits                 stopBits;
      UART_parity                   parity;
      UART_flowCtrlMode             flowControl;
      kal_uint8                     xonChar;
      kal_uint8                     xoffChar;
      kal_bool                      DSRCheck;
} UARTDCBStruct;

typedef struct
{
      kal_uint8                      EscChar;
      kal_uint16                     GuardTime;
} UART_ESCDetectStruct;

typedef struct
{
      kal_uint8                      *rx_buffer;   /* data buffer */
      kal_uint8                      *tx_buffer;   /* data buffer */
      kal_uint8                      *txISR_buffer;  /* data buffer */
} UART_RingBufferStruct;


   typedef enum {
      uart_null_buffer=0,
      uart_isr_buffer,
      uart_normal_buffer
   } UART_RingBuffer_Type;

   typedef struct
   {
         UART_RingBuffer_Type            type;
         kal_uint16                      index;
   } UART_RingBuffer_SaveIndex;


typedef struct
{
	kal_uint16	       tst_port_ps;
	kal_uint16         ps_port;	
	UART_baudrate      tst_baudrate_ps;
	UART_baudrate      ps_baudrate;
	kal_bool           High_Speed_SIM_Enabled;
	kal_uint8          swdbg;	
   kal_uint8          uart_power_setting; /* For DCM, Start [Set UART POWER], CTI  */
   kal_uint8          cti_uart_port;
   UART_baudrate      cti_baudrate;
   kal_uint8           tst_port_l1;
   UART_baudrate       tst_baudrate_l1;
    kal_uint8          tst_output_mode;
    kal_uint8	      usb_logging_mode;
    kal_uint16 tst_port_dsp;
    UART_baudrate       tst_baud_rate_dsp;
    kal_uint8   usb_cdrom_config;
	kal_uint16	speech_port;
	kal_uint16	ndis_port;
} port_setting_struct;

/*start of local parameter struct */

typedef struct  
{       
  LOCAL_PARA_HDR			/* LOCAL_PARA_HDR */	
	DCL_UINT16 	port;
}uart_ready_to_read_ind_struct; 

typedef struct  
{       
  LOCAL_PARA_HDR		/* LOCAL_PARA_HDR */	
	DCL_UINT16 	port;
}uart_ready_to_write_ind_struct;
//ccci on sdio use UART interface
 typedef struct  
 {		 
	 LOCAL_PARA_HDR		 /* LOCAL_PARA_HDR */	 
	 DCL_UINT16  port;
 }uart_ready_to_free_ind_struct;

 
 typedef struct  
{       
  LOCAL_PARA_HDR			/* LOCAL_PARA_HDR */	
	DCL_UINT16 	port;
}uart_dsr_change_ind_struct;
 
 typedef struct  
{       
  LOCAL_PARA_HDR			/* LOCAL_PARA_HDR */	
	DCL_UINT16 	port;
}uart_escape_detected_ind_struct;

 typedef struct  
{       
  LOCAL_PARA_HDR			/* LOCAL_PARA_HDR */	
	DCL_UINT16 	port;
}uart_plugin_ind_struct;

 typedef struct  
{       
  LOCAL_PARA_HDR		/* LOCAL_PARA_HDR */	
	DCL_UINT16 	port;
}uart_plugout_ind_struct;  




#define UART_CTRLS \
	  UART_CTRL_INIT_T    rUARTCtrlInit;\
      UART_CTRL_OPEN_T    rUARTCtrlOPEN; \
      UART_CTRL_CLOSE_T	  rUARTCtrlCLOSE; \
      UART_CTRL_GET_BYTES_T rUARTCtrlGETBYTES; \
      UART_CTRL_PUT_BYTES_T rUARTCtrlPUTBYTES; \
      UART_CTRL_RX_AVAIL_T  rUARTCtrlRXAVAIL; \
      UART_CTRL_TX_AVAIL_T  rUARTCtrlTXAVAIL; \
      UART_CTRL_PURGE_T		rUARTCtrlPURGE; \
      UART_CTRL_OWNER_T		rUARTCtrlOWNER; \
      UART_CTRL_FLOW_CTRL_T rUARTCtrlFLOWCTRL; \
      UART_CTRL_CONFIG_ESP_T rUARTCtrlCONFIGESP; \
      UART_CTRL_DCB_T		rUARTCtrlDCB; \
      UART_CTRL_DCD_T       rUARTCtrlDCD;\
      UART_CTRL_BREAK_T      rUARTCtrlBREAK;\
      UART_CTRL_CLR_BUFFER_T	rUARTCtrlCLRBUFFER;\
      UART_CTRL_BAUDRATE_T     rUARTCtrlBAUDRATE;\
      UART_CTRL_SEND_DATA_T     rUARTCtrlSENDDATA;\
      UART_CTRL_AUTO_BAUDDIV_T  rUARTCtrlAUTOBAUDDIV;\
      UART_CTRL_REG_TX_CB_T     rUARTCtrlREGTXCB;\
      UART_CTRL_REG_RX_CB_T    rUARTCtrlREGRXCB;\
      UART_CTRL_GET_UART_BYTE_T  rUARTCtrlGETUARTBYTE;\
      UART_CTRL_GET_UART_BYTE_WITH_TIMEOUT_T rUARTCtrlGETUARTBYTEWithTimeOut;\
      UART_CTRL_PUT_UART_BYTE_T  rUARTCtrlPUTUARTBYTE;\
      UART_CTRL_PUT_UART_BYTES_T rUARTCtrlPUTUARTBYTES;\
      UART_CTRL_RI_T              rUARTCtrlRI;\
      UART_CTRL_DTR_T               rUARTCtrlDTR;\
      UART_CTRL_RHS_T                rUARTCtrlRHS;\
      UART_CTRL_SFT_T				rUARTCtrlSFT;\
	  UART_CTRL_POWERON_T           rUARTCtrlPoweron;\
	  UART_CTRL_CHECK_TBE_T			rUARTCtrlCheckBUFEMP;\
	  UART_CTRL_CHECK_TSO_T			rUARTCtrlCheckTXSendOut;\
	  UART_CTRL_GET_TBS_T			rUARTCtrlGetTxBufSize;\
	  UART_CTRL_SLEEP_ON_TX_ENABLE_T	rUARTCtrlSleepOnTxEnable;\
	  UART_CTRL_SLEEP_ENABLE_T		rUARTCtrlSleepEnable;\
	  UART_CTRL_BOOT_PUTBYTES_T		rUARTCtrlBootPutBytes;\
	  UART_CTRL_USE_VFIFO_T			rUARTCtrlUseVFifo;\
    UART_CTRL_REG_DEF_CB_T		rUARTCtrlRegDefCB;\
    UART_CTRL_GET_MAXBAUDRATE_T   rUARTCtrlGetMaxBaudrate;\
	  UART_CTRL_GET_FC_T			rUARTCtrlGetFC;\
	  UART_GIO_ENABLE_T		rUARTGIOEnable;\
	  UART_GIO_DISABLE_T	rUARTGIODisable;\
	  UART_GIO_TX_SEND_DATA_T	rUARTGIOTXSendData;\
	  UART_GIO_TX_RECYCLE_GPD_T	rUARTGIOTXRecycleGPD;\
	  UART_GIO_TX_FLUSH_GPD_T	rUARTGIOTXFlushGPD;\
	  UART_GIO_RX_RECV_DATA_T	rUARTGIORXRecvData;\
	  UART_GIO_RX_LOAD_GPD_T	rUARTGIORXLoadGPD;\
	  UART_GIO_RX_FLUSH_GPD_T	rUARTGIORXFlushGPD;\
	  UART_GIO_LOAD_DUMMY_GPD_T rUARTGIOLOADDUMMYGPD;

      

#endif
#endif

#ifdef DCL_DEFINITION_PROTOTYPE
#ifndef __DCL_UART_H_PROTOTYPE__
#define __DCL_UART_H_PROTOTYPE__

typedef DCL_STATUS(*SeriPort_HANLDER_CB)(DCL_DEV dev, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data);

typedef struct 
{
	SIO_TYPE_T DevType;
	SeriPort_HANLDER_CB SeriportHandlerCb;
}Seriport_HANDLER_T;


/*************************************************************************
* FUNCTION
*  DclUART_Open
*
* DESCRIPTION
*  This function is to open the UART module and get a handle. Note that 
* multiple opens are prohibited.
*
* PARAMETERS
*	eDev - only valid for DCL_UART1, DCL_UART2, DCL_UART3(if exists) and 
*         DCL_UART_XXX.
*	flags - module_type | FLAGS_UART_USE_VFIFO
*          module_type: KAL module type enum value
*          FLAGS_UART_USE_VFIFO: flags that specifies to use Virtual FIFO
*                                or not for UART device. Note that it's 
*                                only valide for eDev with DCL_UART1, 
*                                DCL_UART2, DCL_UART3(if exists)
*
* RETURNS
*  STATUS_FAIL - Open failed.
*  STATUS_ALREADY_OPENED - This device has already been opened.
*  STATUS_INVALID_DEVICE - The device is not valid.
*  STATUS_SET_VFIFO_FAIL - Fail to use Vitual FIFO for the UART port.
*  other value - a valid handle
*
*************************************************************************/
extern DCL_HANDLE DclSerialPort_Open(DCL_DEV dev, DCL_FLAGS flags);

/*************************************************************************
* FUNCTION
*  DclUART_Configure
*
* DESCRIPTION
*  This function is to configure for the UART module.
*
* PARAMETERS
*	handle - a valid handle return by DclUART_Open()
*  configure - a ponter to UART_CONFIG_T structure which is a member of union 
*              DCL_CONFIGURE_T.
*
* RETURNS
*	STATUS_OK - successfully register the callback function.
*  STATUS_INVALID_HANDLE - It's a invalid handle.
*  STATUS_NOT_OPENED - The module has not been opened.
*  STATUS_INVALID_CONFIGURATION - the configuration is not valid.
*
*************************************************************************/
extern DCL_STATUS DclSerialPort_Configure(DCL_HANDLE handle, DCL_CONFIGURE_T *configure);
/*************************************************************************
* FUNCTION
*  DclUART_RegisterCallback
*
* DESCRIPTION
*  This function is to register callback funtion for the UART module now.
*
* PARAMETERS
*	handle - a valid handle return by DclUART_Open()
*  event   - EVENT_UART_TX_READY_TO_WRITE: to register the ready-to-write
*            callback function.
*            EVENT_UART_RX_READY_TO_READ: to register the ready-to-read
*            callback function.
*            (Note that the above events can be "OR" together, ex:
*            EVENT_UART_TX_READY_TO_WRITE|EVENT_UART_RX_READY_TO_READ)
*  callback - the callback function when the corresponding event happens
*
* RETURNS
*  STATUS_OK - successfully register the callback function.
*  STATUS_INVALID_HANDLE - It's a invalid handle.
*  STATUS_NOT_OPENED - The module has not been opened.
*  STATUS_INVALID_EVENT - The event parameter is invalid.
*
*************************************************************************/
extern DCL_STATUS DclSerialPort_RegisterCallback(DCL_HANDLE handle, Seriport_HANDLER_T* uart_handler_cb);
/*************************************************************************
* FUNCTION
*  DclUART_Control
*
* DESCRIPTION
*  This function is support UART module commands.
*
* CALLS  
*	It is called to send command to control the UART module.
*
* PARAMETERS
*	handle - a valid handle return by DclUART_OPEN()
*   cmd   - please refer to dcl_uart.h
*   data - please refer to dcl_uart.h
*	
* RETURNS
*	STATUS_OK: command is executed successfully.
*   STATUS_INVALID_CMD: It's a invalid command.
*   STATUS_INVALID_HANDLE: It's a invalid handle.
*
*************************************************************************/
extern DCL_STATUS DclSerialPort_Control(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data);
/*************************************************************************
* FUNCTION
*  DclUART_Close
*
* DESCRIPTION
*  This function is to close the UART module.
*
* PARAMETERS
*	handle  - hanlde previous got from DclUART_Open()
*
* RETURNS
*	DCL_STATUS_OK - successfully close the UART module.
*  STATUS_INVALID_HANDLE - invalid handle
*  STATUS_NOT_OPENED - the UART module hasn't been opened yet.
*
*************************************************************************/
extern DCL_STATUS DclSerialPort_Close(DCL_HANDLE handle);


#endif // #ifndef __DCL_UART_H_PROTOTYPE__
#endif // #ifdef DCL_DEFINITION_PROTOTYPE


