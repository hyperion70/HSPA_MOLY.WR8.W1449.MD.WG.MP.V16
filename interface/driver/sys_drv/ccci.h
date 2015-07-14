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
 *   ccci.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   Header file of CCCI.
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
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *
 *
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __CCCI_H__
#define __CCCI_H__

extern void ccci_hal_init(void);
extern void ccci_init_handshake_phase1(void);
extern void ccci_init_handshake_phase2(kal_uint16 _boot_mode);
extern void ccci_hw_init(void);


#if defined(__MODEM_CCCI_EXIST__)

#include "kal_public_defs.h"


#if !defined(__SDIO_DEVICE_CONNECTIVITY__)

#if !(defined(MT6577) || defined(MT6575))
#define CCCI_INIT_HANDSHAKE_MODE1
#endif

#if defined(__TEE_SECURE_SHAREDMEM_SUPPORT__) || defined(__RPMB_SECURE_SHAREDMEM_SUPPORT__)
#define CCCI_RPCSRV_SUPPORT_SECURE
#endif

/*******************************************************************************
 * Define data structure.
 *******************************************************************************/
/* CCCI status */
typedef enum
{
    CCCI_IDLE = 0x00,
    CCCI_ACTIVE_READ = 0x01,
    CCCI_ACTIVE_WRITE = 0x02,
    CCCI_ACTIVE_ISR = 0x04
} CCCI_STATE_T;

/* CCCI logical channel */
/*      NOTICE: Negotiations With AP Owner Before Modification */
typedef enum
{
    CCCI_CONTROL_CHANNEL = 0,
    CCCI_CONTROL_CHANNEL_ACK =1,
    CCCI_SYSTEM_CHANNEL = 2,
    CCCI_SYSTEM_CHANNEL_ACK = 3,
    CCCI_PCM_CHANNEL = 4,
    CCCI_PCM_CHANNEL_ACK = 5,
    CCCI_TST_CHANNEL = 6,
    CCCI_TST_ACK_CHANNEL = 7,
    CCCI_TR_CHANNEL = 8,
    CCCI_TR_ACK_CHANNEL = 9,
    CCCI_AT_CHANNEL_TX = 10,
    CCCI_AT_ACK_CHANNEL_TX = 11,
    CCCI_AT_CHANNEL_RX = 12,
    CCCI_AT_ACK_CHANNEL_RX = 13,
    CCCI_FS_CHANNEL = 14,
    CCCI_FS_ACK_CHANNEL = 15,
    CCCI_PMIC_CHANNEL = 16,
    CCCI_PMIC_ACK_CHANNEL = 17,
    CCCI_UEM_CHANNEL = 18,
    CCCI_UEM_ACK_CHANNEL = 19,
    CCCI_CCMNI1_RX = 20,
    CCCI_CCMNI1_RX_ACK = 21,
    CCCI_CCMNI1_TX = 22,
    CCCI_CCMNI1_TX_ACK = 23,
    CCCI_CCMNI2_RX = 24,
    CCCI_CCMNI2_RX_ACK = 25,
    CCCI_CCMNI2_TX = 26,
    CCCI_CCMNI2_TX_ACK = 27,
    CCCI_CCMNI3_RX = 28,
    CCCI_CCMNI3_RX_ACK = 29,
    CCCI_CCMNI3_TX = 30,
    CCCI_CCMNI3_TX_ACK = 31,
    CCCI_IPC_RPC_CHANNEL = 32,
    CCCI_IPC_RPC_ACK_CHANNEL = 33,
    CCCI_MSGSVC_SEND_CHANNEL = 34,
    CCCI_MSGSVC_SEND_ACK_CHANNEL = 35,
    CCCI_MSGSVC_RCV_CHANNEL = 36,
    CCCI_MSGSVC_RCV_ACK_CHANNEL = 37,
    CCCI_GPS_CHANNEL_TX = 38,
    CCCI_GPS_ACK_CHANNEL_TX = 39,
    CCCI_GPS_CHANNEL_RX = 40,
    CCCI_GPS_ACK_CHANNEL_RX = 41,
    CCCI_MD_LOG_RX = 42,
    CCCI_MD_LOG_TX = 43,
    CCCI_MAX_CHANNEL = 44,
    CCCI_FORCE_RESET_MODEM_CHANNEL = 20090215
} CCCI_CHANNEL_T;

/* CCCI mailbox channel structure */
typedef struct
{
    kal_uint32 magic;   /* 0xFFFFFFFF */
    kal_uint32 id;
} CCCI_MAILBOX_T;

/* CCCI stream channel structure */
typedef struct
{
    kal_uint32 addr;
    kal_uint32 len;
} CCCI_STREAM_T;

/* CCCI channel buffer structure */
typedef struct
{
    kal_uint32 data[2];
    kal_uint32 channel;
    kal_uint32 reserved;
} CCCI_BUFF_T;

/* CCCI callback function prototype */
typedef void (*CCCI_CALLBACK)(CCCI_BUFF_T *buff);

typedef void (*CCCI_SYSMSGSVC_HISR_CALLBACK)(kal_uint32 param);
/* CCCI control structure */
typedef struct
{
    CCCI_STATE_T state;
    kal_uint32 owner;
    CCCI_BUFF_T buff;
    CCCI_CALLBACK funp;
    kal_eventgrpid event;
} CCCI_CTRL_T;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint16        B0;
} CCCI_COMMON_ILM_1B;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint16        HW0;
} CCCI_COMMON_ILM_2B;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32        W0;
} CCCI_COMMON_ILM_4B;

/* CCCI RunTime Data structure */
/*      NOTICE: Negotiations With AP Side Owner Before Modification */

/* DriverVersion */
#define CCCI_VERSION_75_77_80           0x20110118
#define CCCI_VERSION_NORMAL             0x20121001
#define CCCI_VERSION_SUPPORT_RPCSEC     0x20140101


#if (defined(MT6575) || defined(MT6577) || defined(MT6280))
#define CCCI_CURRENT_VERSION      CCCI_VERSION_75_77_80
#else
    #if defined(CCCI_RPCSRV_SUPPORT_SECURE)
    #define CCCI_CURRENT_VERSION      CCCI_VERSION_SUPPORT_RPCSEC
#else
    #define CCCI_CURRENT_VERSION      CCCI_VERSION_NORMAL
    #endif
#endif

/* BootingStartID */
#define NORMAL_BOOT_ID            0
#define META_BOOT_ID              1

/* BootAttributes */
#define BOOT_ATTR_IS_CLEAN_BOOT   0x00000001


#define UART_MAX_PORT_NUM         8
#define NET_MAX_PORT_NUM          4

#if defined(CCCI_INIT_HANDSHAKE_MODE1)
/* return value of query misc info */
#define CCCI_MISC_INFO_NOT_EXIST   0x00000000
#define CCCI_MISC_INFO_NOT_SUPPORT 0x00000001
#define CCCI_MISC_INFO_SUPPORT     0x00000002
#endif /* CCCI_INIT_HANDSHAKE_MODE1 */

#if defined(CCCI_RPCSRV_SUPPORT_SECURE)

#if 0
/* under construction !*/
/* under construction !*/
#else
#define PREFIX_CCCI     0x49434343
#define POSTFIX_CCCI    0x49434343
#endif

typedef struct MODEM_RUNTIME_DATA_SEC_T
{
    kal_uint32   Prefix;               //'CCCI'
    kal_uint32   Rpc_Sec_ShareMemBase;
    kal_uint32   Rpc_Sec_ShareMemSize;
    kal_uint32   Postfix;              //'CCCI'
} MODEM_RUNTIME_DATA_SEC;

extern MODEM_RUNTIME_DATA_SEC ap_md_share_data_sec;

#endif //CCCI_RPCSRV_SUPPORT_SECURE

typedef struct MODEM_RUNTIME_DATA_T
{
    kal_uint8    Prefix[4];            // "CCIF"
    kal_uint8    Platform[8];          // Hardware Platform String ex: "MT6516E1"
    kal_uint32   DriverVersion;        // 0x00000929 since W09.29
    kal_uint32   BootChannel;          // Channel to ACK AP with boot ready
    kal_uint32   BootingStartID;       // MD is booting. NORMAL_BOOT_ID or META_BOOT_ID
    kal_uint32   BootAttributes;       // Attributes passing from AP to MD Booting
    kal_uint32   BootReadyID;          // MD response ID if boot successful and ready ,
    // Cannot equal to CCMSG_ID_DRV_VERSION_ERR
    kal_uint32   MdlogShareMemBase;
    kal_uint32   MdlogShareMemSize;
    kal_uint32   PcmShareMemBase;
    kal_uint32   PcmShareMemSize;
    kal_uint32   UartPortNum;
    kal_uint32   UartShareMemBase[UART_MAX_PORT_NUM];
    kal_uint32   UartShareMemSize[UART_MAX_PORT_NUM];
    kal_uint32   FileShareMemBase;
    kal_uint32   FileShareMemSize;
    kal_uint32   RpcShareMemBase;
    kal_uint32   RpcShareMemSize;
    kal_uint32   PmicShareMemBase;
    kal_uint32   PmicShareMemSize;
    kal_uint32   ExceShareMemBase;
    kal_uint32   ExceShareMemSize;     // 512 Bytes Required
    kal_uint32   SysShareMemBase;
    kal_uint32   SysShareMemSize;      // AP MD run-time share data
    kal_uint32   IPCShareMemBase;
    kal_uint32   IPCShareMemSize;      // AP MD run-time share data
#ifdef CCCI_INIT_HANDSHAKE_MODE1
    kal_uint32   MDULNetShareMemBase;
    kal_uint32   MDULNetShareMemSize;
    kal_uint32   MDDLNetShareMemBase;
    kal_uint32   MDDLNetShareMemSize;
    kal_uint32   NetPortNum;
    kal_uint32   NetULCtrlShareMemBase[NET_MAX_PORT_NUM];
    kal_uint32   NetULCtrlShareMemSize[NET_MAX_PORT_NUM];
    kal_uint32   NetDLCtrlShareMemBase[NET_MAX_PORT_NUM];
    kal_uint32   NetDLCtrlShareMemSize[NET_MAX_PORT_NUM];
    kal_uint32   ExtMDExcepInfoBase;
    kal_uint32   ExtMDExcepInfoSize;
    kal_uint32   IPCMDIlmShareMemBase;
    kal_uint32   IPCMDIlmShareMemSize;
    kal_uint32   MiscInfoBase;
    kal_uint32   MiscInfoSize;
#endif
    kal_uint32   CheckSum;
    kal_uint8    Postfix[4];       //"CCIF"
} MODEM_RUNTIME_DATA;

extern MODEM_RUNTIME_DATA ap_md_share_data;

#ifdef CCCI_INIT_HANDSHAKE_MODE1
typedef struct MODEM_RUNTIME_INFO_T
{
    kal_uint32 Prefix;             // "CCIF"
    kal_uint32 Platform_L;       // Hardware Platform String ex: "TK6516E0"
    kal_uint32 Platform_H;
    kal_uint32 DriverVersion;      // 0x00000923 since W09.23
    kal_uint32 RuntimedataBase;
    kal_uint32 RuntimedataSize;
    kal_uint32 Postfix;        //"CCIF"
} MODEM_RUNTIME_INFO;
#endif

typedef struct MODEM_EXCEPTION_EXT_T
{
    kal_uint32 exception_occur;
    kal_uint32 send_time;
    kal_uint32 wait_time;
} MODEM_EXCEPTION_EXT;

extern MODEM_EXCEPTION_EXT *ap_md_exception_ext;
/* CCCI Message ID Passing Through CONTROL_CHANNEL and SYSTEM_CHANNEL */
/*      NOTICE: Negotiations With AP Owner Before Modification */

#undef     X_CCCI_SYSMSGSVC_CONF
#define	   X_CCCI_SYSMSGSVC_CONF(mSGNO, mODE, iD)	mSGNO,
typedef enum
{
    CCMSG_ID_START_BOOT        = 0x00000000,
    CCMSG_ID_NORMAL_BOOT_READY = 0x00000001,
    CCMSG_ID_META_BOOT_READY   = 0x00000002,
    CCMSG_ID_RESET             = 0x00000003,
    CCMSG_ID_EXCEPTION_CHECK   = 0x00000004,
    CCMSG_ID_DRV_VERSION_ERR   = 0x00000005,
    CCMSG_ID_EXCEPTION_REC_OK  = 0x00000006,
    /* System Channel */
    CCMSG_ID_MD_L4_MOD         = 0x0000000E,//add for RIL (AP task) and L4C (MD task) communication message
    CCMSG_ID_MD_L4_MAX_TX_PWR_RED_REQ = 0x0000000F,

    CCMSG_ID_MD_LEGACY_END     = 0x000000FF,
    CCMSG_ID_SYSMSGSVC_MASK    = 0x00000100,
    CCMSG_ID_SYSMSGSVC_START   = 0x00000100,
    CCMSG_ID_SYSMSGSVC_DUMMY   = 0x000000FF,
    //- section 0x100 ~ 0x1FF : reserved for system message service used
#include "ccci_sysmsgsvc_conf.h"
    CCMSG_ID_SYSMSGSVC_END,
    //- section 0x1000 ~ : Platform dependent workaround
    CCMSG_ID_MD_WDT_FLAG       = 0x00001000,    //- for MT6577/MT6589, AP cannot receive MD WDT interrupt issue.
} CONTROL_CHANNEL_MSG;
#undef     X_CCCI_SYSMSGSVC_CONF

#ifdef CCCI_INIT_HANDSHAKE_MODE1
#undef     X_CCCI_MISCINFO_CONF
#define    X_CCCI_MISCINFO_CONF(mSGNO)    mSGNO,
typedef enum
{
#include "ccci_misc_info_conf.h"
    CCCI_MISC_INFO_QUERY_END
} CCCI_MISC_INFO_ID_T;
#undef    X_CCCI_MISCINFO_CONF
#endif    /* CCCI_INIT_HANDSHAKE_MODE1 */

typedef struct CCCI_GIOPDU_DBGBLK_HEADER
{
    kal_uint32        port;
    kal_uint32        avai_in;
    kal_uint32        avai_out;
    kal_uint32        read_out;
    kal_uint32        header;
} CCCI_GIOPDU_DBGBLK_HEADER_T;

typedef struct CCCI_GIOPDU_DBGBLK_FOOTER
{
    kal_uint32        ender;
    kal_uint32        footer;
} CCCI_GIOPDU_DBGBLK_FOOTER_T;

#define CCCI_UART_GIO_PKT_HEADER_SIZE()            sizeof (CCCI_GIOPDU_DBGBLK_HEADER_T)
#define CCCI_UART_GIO_PKT_FOOTER_SIZE()            sizeof (CCCI_GIOPDU_DBGBLK_FOOTER_T)

extern void ccci_ups_get_UL_buffer_attribute (kal_uint8** addr, kal_uint32* length);

/*******************************************************************************
 * Define marco.
 *******************************************************************************/

/* initialize a CCCI mailbox buffer */
#define CCCI_INIT_MAILBOX(buff, mailbox_id)                            \
        do {                                                           \
            ((CCCI_MAILBOX_T *)(buff))->magic = 0xFFFFFFFF;            \
            ((CCCI_MAILBOX_T *)(buff))->id = (mailbox_id);             \
            (buff)->channel = CCCI_MAX_CHANNEL;                        \
            (buff)->reserved = 0;                                      \
        } while (0)

/* initialize a CCCI stream buffer */
#define CCCI_INIT_STREAM(buff, stream_addr, stream_len)                \
        do {                                                           \
            ((CCCI_STREAM_T *)(buff))->addr = (stream_addr);           \
            ((CCCI_STREAM_T *)(buff))->len = (stream_len);             \
            (buff)->channel = CCCI_MAX_CHANNEL;                        \
            (buff)->reserved = 0;                                      \
        } while (0)

#define CCCI_INIT_MAILBOX_WITH_RESERVED(buff, mailbox_id, res_value)   \
        do {                                                           \
            ((CCCI_MAILBOX_T *)(buff))->magic = 0xFFFFFFFF;            \
            ((CCCI_MAILBOX_T *)(buff))->id = (mailbox_id);             \
            (buff)->channel = CCCI_MAX_CHANNEL;                        \
            (buff)->reserved = res_value;                              \
        } while (0)

/* initialize a CCCI stream buffer */
#define CCCI_INIT_STREAM_WITH_RESERVED(buff, stream_addr, stream_len, res_value) \
        do {                                                                     \
            ((CCCI_STREAM_T *)(buff))->addr = (stream_addr);                     \
            ((CCCI_STREAM_T *)(buff))->len = (stream_len);                       \
            (buff)->channel = CCCI_MAX_CHANNEL;                                  \
            (buff)->reserved = res_value;                                        \
        } while (0)
/* check the CCCI buffer type */
#define CCCI_IS_MAILBOX(buff)   ((((CCCI_MAILBOX_T *)(buff))->magic == 0xFFFFFFFF)? 1: 0)

/* get the id of the CCCI mailbox buffer */
#define CCCI_MAILBOX_ID(buff)   (((CCCI_MAILBOX_T *)(buff))->id)

/* get the addr of the CCCI stream buffer */
#define CCCI_STREAM_ADDR(buff)   (((CCCI_STREAM_T *)(buff))->addr)

/* get the len of the CCCI stream buffer */
#define CCCI_STREAM_LEN(buff)   (((CCCI_STREAM_T *)(buff))->len)


/*******************************************************************************
 * define global variable
 *******************************************************************************/
#define BOOT_CHECK_ID       0x5555FFFF /* magic id : Placed on reserved field */
#define EXCEPTION_CHECK_ID  0x45584350 /* EXCP     : Placed on reserved field */
#define EXCEPTION_REC_READY 0x45524543 /* EREC     : Placed on reserved field */
#define CCCI_WAIT_MAX_TIME  4615


/*******************************************************************************
 * define ccci error code
 *******************************************************************************/
typedef enum
{
    CCCI_SUCCESS                                      = 0,
    CCCI_FAIL                                         = -1001,
    CCCI_IN_USE                                       = -1002,
    CCCI_NOT_OWNER                                    = -1003,
    CCCI_INVALID_PARAM                                = -1004,
    CCCI_NO_PHY_CHANNEL                               = -1005,
    CCCI_IN_LISR                                      = -1006,
    CCCI_NO_DATA                                      = -1007,

    IPC_RPC_CCCI_ERROR_WRITE_NO_PHYSICAL_CHANNEL      = -2001,
    IPC_RPC_CCCI_ERROR_INPUT_PARAM_LEN_TO_LONG        = -2002,
    IPC_RPC_CCCI_ERROR_RETURN_OPID_NOT_SYNC           = -2003,
    IPC_RPC_CCCI_ERROR_USER_INPUT_PARAM_FULL          = -2004,
    IPC_RPC_CCCI_ERROR_USER_OUTPUT_PARAM_FULL         = -2005,
    IPC_RPC_CCCI_ERROR_SHARE_BUFFER_UNAVALIABLE       = -2006,
    IPC_RPC_CCCI_ERROR_BUFCOUNT_ZERO                  = -2007,
    IPC_RPC_CCCI_ERROR_RETURN_BASEADDR_NOT_SYNC       = -2008,
    IPC_RPC_CCCI_ERROR_RETURN_PARAM_NUM_MISMATCH      = -2009,
    IPC_RPC_CCCI_ERROR_RETURN_PARAMX_LEN_TO_LONG      = -2010,
    IPC_RPC_CCCI_ERROR_WRITE_BUFFER_FULL              = -2011,
    IPC_RPC_CCCI_ERROR_RETURN_IDX_MISMATCH            = -2012,
    IPC_RPC_CCCI_ERROR_BUFFER_INDEX_INVALID           = -2013,
    IPC_RPC_CCCI_ERROR_BUFFER_INDEX_OCCUPIED          = -2014,
    IPC_RPC_CCCI_ERROR_SECBUF_WRITE_UNAVAILABLE       = -2015,
    IPC_RPC_CCCI_ERROR_SECURITY_CHECK_FAIL            = -2016,


    IPC_MSG_CCCI_ERROR_WRITE_NO_PHYSICAL_CHANNEL      = -3001,
    IPC_MSG_CCCI_ERROR_WRITE_INTERNAL_FAIL            = -3002,
    IPC_MSG_CCCI_ERROR_SEND_ID_MISMATCH               = -3003,
    IPC_MSG_CCCI_ERROR_TXCB_ID_MISMATCH               = -3004,
    IPC_MSG_CCCI_ERROR_RECV_ID_MISMATCH               = -3005,

    FS_CCCI_ERROR_WRITE_NO_PHYSICAL_CHANNEL           = -4001,
    FS_CCCI_ERROR_INPUT_PARAM_LEN_TO_LONG             = -4002,
    FS_CCCI_ERROR_RETURN_OPID_NOT_SYNC                = -4003,
    FS_CCCI_ERROR_USER_INPUT_PARAM_FULL               = -4004,
    FS_CCCI_ERROR_USER_OUTPUT_PARAM_FULL              = -4005,
    FS_CCCI_ERROR_SHARE_BUFFER_UNAVALIABLE            = -4006,
    FS_CCCI_ERROR_BUFCOUNT_ZERO                       = -4007,
    FS_CCCI_ERROR_RETURN_BASEADDR_NOT_SYNC            = -4008,
    FS_CCCI_ERROR_RETURN_PARAM_NUM_MISMATCH           = -4009,
    FS_CCCI_ERROR_RETURN_PARAMX_LEN_TO_LONG           = -4010,
    FS_CCCI_ERROR_WRITE_BUFFER_FULL                   = -4011,
    FS_CCCI_ERROR_RETURN_IDX_MISMATCH                 = -4012,

    UART_CCCI_ERROR_WRITE_NO_PHYSICAL_CHANNEL         = -5001,

    DUMMY_CCCI_GLOBAL_ERROR_CODE
} CCCI_GLOBAL_ERROR_CODE;


/*******************************************************************************
 * define index for EXCEP DBG Logging
 *******************************************************************************/
#undef     X_CCCI_EXCEP_DBG_LOG_CONF
#define    X_CCCI_EXCEP_DBG_LOG_CONF(index, length)    index,
typedef enum
{
#include "ccci_excep_dbg_log_conf.h"
    CCCI_EXCEP_DBG_LOG_INDEX_MAX
} CCCI_EXCEP_DBG_LOG_INDEX;
#undef     X_CCCI_EXCEP_DBG_LOG_CONF

typedef enum {
    CCCI_EXCEP_DBG_HS_FS_WAIT_TIME = 0,
    CCCI_EXCEP_DBG_HS_LOG_MAX,
} CCCI_EXCEP_DBG_HS_INDEX;


/*******************************************************************************
 * Declare function prototype.
 * User APIs
 *******************************************************************************/
extern void ccif_lisr(void);
extern kal_int32 ccci_init(kal_uint32 channel, CCCI_CALLBACK funp);
extern kal_int32 ccci_deinit(kal_uint32 channel);
extern kal_int32 ccci_stream_write(kal_uint32 channel, kal_uint32 addr, kal_uint32 len);
extern kal_int32 ccci_stream_read(kal_uint32 channel, kal_uint32 *addr, kal_uint32 *len);
extern kal_int32 ccci_stream_read_with_reserved(kal_uint32 channel, kal_uint32 *addr, kal_uint32 *len, kal_uint32 *reserved);
extern kal_int32 ccci_stream_write_with_reserved(kal_uint32 channel, kal_uint32 addr, kal_uint32 len,kal_uint32 reserved);
extern kal_int32 ccci_mailbox_write(kal_uint32 channel, kal_uint32 id);
extern kal_int32 ccci_mailbox_read(kal_uint32 channel);
extern kal_int32 ccci_mailbox_write_with_reserved(kal_uint32 channel, kal_uint32 id,kal_uint32 reserved);
extern kal_int32 ccci_mailbox_read_with_reserved(kal_uint32 channel,kal_uint32 *reserved);
extern void ccci_GetShareMemInfo( kal_uint32 **info, kal_uint16* count );
extern void ccci_CalculateShareMem(kal_uint32 *start_addr, kal_uint32 *end_addr , kal_uint32 *size);
extern kal_bool ccci_queryBootAttributes(kal_uint32 mask);
extern kal_bool ccci_chk_sententry_not_receive(kal_uint32 query_log, kal_uint32 data);

/*******************************************************************************
 * Declare function prototype.
 * Kernel/System Use APIs
 *******************************************************************************/

extern kal_int32 ccci_read(kal_uint32 channel, CCCI_BUFF_T *buff);
extern kal_int32 ccci_write_internal(kal_uint32 channel, CCCI_BUFF_T *buff,kal_bool check_lisr);
#define ccci_write(a,b) ccci_write_internal((kal_uint32)(a), (CCCI_BUFF_T *)(b), (kal_bool)1)
extern kal_int32 ccci_owner_init(kal_uint32 channel, kal_taskid task, CCCI_CALLBACK funp);
extern kal_uint32 ccci_query_sharemem_addr(kal_uint32 channel,kal_uint32 *size);
extern void ccci_change_owner_only(kal_uint32 channel,module_type owner);

extern void ccif_init(kal_uint32 arb);
extern kal_bool ccci_chk_recentry_in_queue(kal_uint32 query_log, kal_bool Is_Ack_All_if_found);
extern void ccci_init_handshake_phase1(void);
extern void ccci_init_handshake_phase2(kal_uint16 _boot_mode);
extern void ccci_exception_handshake(void) ;
extern void ccci_exception_info_passed(void) ;
extern void ccci_except_ack(CCCI_BUFF_T *bufp);

extern kal_int32 ccci_register_sysmsgsvc_callback(kal_uint32 msgno, CCCI_SYSMSGSVC_HISR_CALLBACK funp);
extern kal_bool ccci_send_message(kal_uint32 message, kal_uint32 reserved);
extern kal_int32 ccci_read_and_wait(CCCI_CHANNEL_T channel, CCCI_BUFF_T *buff, kal_uint32 ticks);

#ifdef CCCI_INIT_HANDSHAKE_MODE1
extern kal_int32 ccci_misc_info_feature_support(kal_uint32 op_id, kal_uint32 len, void *pReturn);
#endif

//- API for SP bootup trace
#if defined(__SP_BOOTTRC_ENABLE__)
extern void ccci_boottrc_write_log_sharemem(kal_uint32 index, kal_uint32 value);
extern kal_int32 ccci_boottrc_query_sharemem(kal_uint32 *addr, kal_uint32 *size);
extern void ccci_boottrc_clear_sharemem();
#endif

//- API for EXCEP DBG Logging
extern kal_int32 ccci_excep_dbg_logging(kal_uint32 index, void* addr);
extern kal_uint32 ccci_excep_dbg_get_swla_addr(void);



















#elif defined(__SMART_PHONE_MODEM__) //- __SDIO_DEVICE_CONNECTIVITY__ && __SMART_PHONE_MODEM__
extern kal_bool INT_QueryExceptionStatus(void);
/*******************************************************************************
 * Define data structure.
 *******************************************************************************/

/* CCCI API return value */
typedef enum
{
    CCCI_SUCCESS = 0,
    CCCI_FAIL = -1001,
    CCCI_IN_USE = -1002,
    CCCI_NOT_OWNER = -1003,
    CCCI_INVALID_PARAM = -1004,
    CCCI_NO_PHY_CHANNEL = -1005,
    CCCI_IN_LISR = -1006,
    CCCI_NO_DATA = -1007
} CCCI_RETURNVAL_T;

/* CCCI status */
typedef enum
{
    CCCI_IDLE = 0x00,
    CCCI_ACTIVE_READ = 0x01,
    CCCI_ACTIVE_WRITE = 0x02,
    CCCI_ACTIVE_ISR = 0x04
} CCCI_STATE_T;

/* CCCI logical channel */
/*      NOTICE: Negotiations With AP Owner Before Modification */
typedef enum
{
    CCCI_CONTROL_CHANNEL = 0,
    CCCI_CONTROL_CHANNEL_ACK =1,
    CCCI_SYSTEM_CHANNEL = 2,
    CCCI_SYSTEM_CHANNEL_ACK = 3,
    CCCI_PCM_CHANNEL = 4,
    CCCI_PCM_CHANNEL_ACK = 5,
    CCCI_TST_CHANNEL = 6,
    CCCI_TST_ACK_CHANNEL = 7,
    CCCI_TR_CHANNEL = 8,
    CCCI_TR_ACK_CHANNEL = 9,
    CCCI_AT_CHANNEL_TX = 10,
    CCCI_AT_ACK_CHANNEL_TX = 11,
    CCCI_AT_CHANNEL_RX = 12,
    CCCI_AT_ACK_CHANNEL_RX = 13,
    CCCI_FS_CHANNEL = 14,
    CCCI_FS_ACK_CHANNEL = 15,
    CCCI_PMIC_CHANNEL = 16,
    CCCI_PMIC_ACK_CHANNEL = 17,
    CCCI_UEM_CHANNEL = 18,
    CCCI_UEM_ACK_CHANNEL = 19,
    CCCI_CCMNI1_RX = 20,
    CCCI_CCMNI1_RX_ACK = 21,
    CCCI_CCMNI1_TX = 22,
    CCCI_CCMNI1_TX_ACK = 23,
    CCCI_CCMNI2_RX = 24,
    CCCI_CCMNI2_RX_ACK = 25,
    CCCI_CCMNI2_TX = 26,
    CCCI_CCMNI2_TX_ACK = 27,
    CCCI_CCMNI3_RX = 28,
    CCCI_CCMNI3_RX_ACK = 29,
    CCCI_CCMNI3_TX = 30,
    CCCI_CCMNI3_TX_ACK = 31,
    CCCI_IPC_RPC_CHANNEL = 32,
    CCCI_IPC_RPC_ACK_CHANNEL = 33,
    CCCI_MSGSVC_SEND_CHANNEL = 34,
    CCCI_MSGSVC_SEND_ACK_CHANNEL = 35,
    CCCI_MSGSVC_RCV_CHANNEL = 36,
    CCCI_MSGSVC_RCV_ACK_CHANNEL = 37,
    CCCI_GPS_CHANNEL_TX = 38,
    CCCI_GPS_ACK_CHANNEL_TX = 39,
    CCCI_GPS_CHANNEL_RX = 40,
    CCCI_GPS_ACK_CHANNEL_RX = 41,
    CCCI_MD_LOG_RX = 42,
    CCCI_MD_LOG_TX = 43,
    CCCI_MAX_CHANNEL = 44,
    CCCI_FORCE_RESET_MODEM_CHANNEL = 20090215
} CCCI_CHANNEL_T;

/* CCCI mailbox channel structure */
typedef struct
{
    kal_uint32 magic;   /* 0xFFFFFFFF */
    kal_uint32 id;
} CCCI_MAILBOX_T;

/* CCCI stream channel structure */
typedef struct
{
    kal_uint32 addr;
    kal_uint32 len;
} CCCI_STREAM_T;

/* CCCI channel buffer structure */
typedef struct
{
    kal_uint32 data[2];
    kal_uint32 channel;
    kal_uint32 reserved;
} CCCI_BUFF_T;

/* CCCI callback function prototype */
typedef void (*CCCI_CALLBACK)(CCCI_BUFF_T *buff);

typedef void (*CCCI_SYSMSGSVC_HISR_CALLBACK)(kal_uint32 param);
/* CCCI control structure */
typedef struct
{
    CCCI_STATE_T state;
    kal_uint32 owner;
    CCCI_BUFF_T buff;
    CCCI_CALLBACK funp;
    kal_eventgrpid event;
} CCCI_CTRL_T;

typedef struct
{
    kal_uint8        ref_count;
    kal_uint16        msg_len;
    kal_uint16        B0;
} CCCI_COMMON_ILM_1B;

typedef struct
{
    kal_uint8        ref_count;
    kal_uint16        msg_len;
    kal_uint16        HW0;
} CCCI_COMMON_ILM_2B;

typedef struct
{
    kal_uint8        ref_count;
    kal_uint16        msg_len;
    kal_uint16        W0;
} CCCI_COMMON_ILM_4B;

/* transaction info for debug facility */
typedef struct
{
    kal_uint32    tick;
    CCCI_CTRL_T    ct;
} CCCI_TRANS_LOG;


#define UART_MAX_PORT_NUM 6    //need to sync with AP side

/* CCCI RunTime Data structure */
/* NOTICE: Negotiations With AP Side Owner Before Modification */
typedef struct MODEM_RUNTIME_DATA_T
{
    kal_uint8    Prefix[4];            // "CCIF"
    kal_uint8    Platform[8];          // Hardware Platform String ex: "MT6516E1"
    kal_uint32   DriverVersion;        // 0x00000929 since W09.29
    kal_uint32   BootChannel;          // Channel to ACK AP with boot ready
    kal_uint32   BootingStartID;       // MD is booting. NORMAL_BOOT_ID or META_BOOT_ID or early exception memory dump
    kal_uint32   BootAttributes;       // Attributes passing from AP to MD Booting
    kal_uint32   BootReadyID;          // MD response ID if boot successful and ready ,
    // Cannot equal to CCMSG_ID_DRV_VERSION_ERR
    kal_uint32   MdlogShareMemBase;
    kal_uint32   MdlogShareMemSize;
    kal_uint32   PcmShareMemBase;
    kal_uint32   PcmShareMemSize;
    kal_uint32   UartPortNum;
    kal_uint32   UartShareMemBase[UART_MAX_PORT_NUM];
    kal_uint32   UartShareMemSize[UART_MAX_PORT_NUM];
    kal_uint32   FileShareMemBase;
    kal_uint32   FileShareMemSize;
    kal_uint32   RpcShareMemBase;
    kal_uint32   RpcShareMemSize;
    kal_uint32   PmicShareMemBase;
    kal_uint32   PmicShareMemSize;
    kal_uint32   ExceShareMemBase;
    kal_uint32   ExceShareMemSize;     // 512 Bytes Required
    kal_uint32   SysShareMemBase;
    kal_uint32   SysShareMemSize;
    kal_uint32   IPCShareMemBase;
    kal_uint32   IPCShareMemSize;
    kal_uint32   CheckSum;
    kal_uint8    Postfix[4];       //"CCIF"
} MODEM_RUNTIME_DATA;


extern MODEM_RUNTIME_DATA ap_md_share_data;
/* CCCI Message ID Passing Through CONTROL_CHANNEL and SYSTEM_CHANNEL */
/*      NOTICE: Negotiations With AP Owner Before Modification */
typedef enum
{
    CCMSG_ID_START_BOOT        = 0x00000000,
    CCMSG_ID_NORMAL_BOOT_READY = 0x00000001,
    CCMSG_ID_META_BOOT_READY   = 0x00000002,
    CCMSG_ID_RESET             = 0x00000003,
    CCMSG_ID_EXCEPTION_CHECK   = 0x00000004,
    CCMSG_ID_DRV_VERSION_ERR   = 0x00000005,
    CCMSG_ID_EXCEPTION_REC_OK  = 0x00000006,
    /* System Channel */
    CCMSG_ID_MD_L4_MOD         = 0x0000000E,//add for RIL (AP task) and L4C (MD task) communication message
    CCMSG_ID_MD_L4_MAX_TX_PWR_RED_REQ    = 0x0000000F,
} CONTROL_CHANNEL_MSG;

/*******************************************************************************
 * Define common marco.
 *******************************************************************************/

/* DriverVersion */
#define CCCI_CURRENT_VERSION      0x20110118

/* BootingStartID */
#define NORMAL_BOOT_ID            0
#define META_BOOT_ID              1

/* BootAttributes */
#define BOOT_ATTR_IS_CLEAN_BOOT   0x00000001

#define BOOT_CHECK_ID       0x5555FFFF /* magic id : Placed on reserved field */
#define EXCEPTION_CHECK_ID  0x45584350 /* EXCP     : Placed on reserved field */
#define EXCEPTION_REC_READY 0x45524543 /* EREC     : Placed on reserved field */
#define CCCI_WAIT_MAX_TIME  4615

/* initialize a CCCI mailbox buffer */
#define CCCI_INIT_MAILBOX(buff, mailbox_id) \
        do {    \
            ((CCCI_MAILBOX_T *)(buff))->magic = 0xFFFFFFFF; \
            ((CCCI_MAILBOX_T *)(buff))->id = (mailbox_id);  \
            (buff)->channel = CCCI_MAX_CHANNEL;  \
            (buff)->reserved = 0;    \
        } while (0)

/* initialize a CCCI stream buffer */
#define CCCI_INIT_STREAM(buff, stream_addr, stream_len) \
        do {    \
            ((CCCI_STREAM_T *)(buff))->addr = (stream_addr); \
            ((CCCI_STREAM_T *)(buff))->len = (stream_len);  \
            (buff)->channel = CCCI_MAX_CHANNEL;  \
            (buff)->reserved = 0;    \
        } while (0)

/* check the CCCI buffer type */
#define CCCI_IS_MAILBOX(buff)   ((((CCCI_MAILBOX_T *)(buff))->magic == 0xFFFFFFFF)? 1: 0)

/* get the id of the CCCI mailbox buffer */
#define CCCI_MAILBOX_ID(buff)   (((CCCI_MAILBOX_T *)(buff))->id)

/* get the addr of the CCCI stream buffer */
#define CCCI_STREAM_ADDR(buff)   (((CCCI_STREAM_T *)(buff))->addr)

/* get the len of the CCCI stream buffer */
#define CCCI_STREAM_LEN(buff)   (((CCCI_STREAM_T *)(buff))->len)

/*******************************************************************************
 * Declare function prototype.
 * User APIs
 *******************************************************************************/
extern kal_int32 ccci_owner_init(CCCI_CHANNEL_T channel, kal_taskid task, CCCI_CALLBACK funp);
extern kal_int32 ccci_init(CCCI_CHANNEL_T channel, CCCI_CALLBACK funp);
extern kal_int32 ccci_deinit(CCCI_CHANNEL_T channel);
extern kal_int32 ccci_mailbox_write(CCCI_CHANNEL_T channel, kal_uint32 id);
extern kal_int32 ccci_mailbox_write_with_reserved(CCCI_CHANNEL_T channel, kal_uint32 id,kal_uint32 reserved);
extern kal_int32 ccci_read(CCCI_CHANNEL_T channel, CCCI_BUFF_T *buff);
extern kal_int32 ccci_mailbox_read(CCCI_CHANNEL_T channel);
extern kal_int32 ccci_mailbox_read_with_reserved(CCCI_CHANNEL_T channel,kal_uint32 *reserved);
extern kal_int32 ccci_stream_write(CCCI_CHANNEL_T channel, kal_uint32 addr, kal_uint32 len);
extern kal_int32 ccci_stream_write_with_reserved(CCCI_CHANNEL_T channel, kal_uint32 addr, kal_uint32 len,kal_uint32 reserved);
extern kal_int32 ccci_stream_read(CCCI_CHANNEL_T channel, kal_uint32 *addr, kal_uint32 *len);
extern kal_int32 ccci_stream_read_with_reserved(CCCI_CHANNEL_T channel, kal_uint32 *addr, kal_uint32 *len, kal_uint32 *reserved);
extern kal_bool ccci_queryBootAttributes(kal_uint32 mask);
extern void ccci_hisr(void);

/*******************************************************************************
 * Declare function prototype.
 * Kernel/System Use APIs
 *******************************************************************************/
extern void ccci_change_owner_only(CCCI_CHANNEL_T channel,module_type owner);

//following API should be implement individual in CCIF/SDIO
extern void ccci_init_handshake_phase1(void);
extern void ccci_init_handshake_phase2(kal_uint16 _boot_mode);
extern void ccci_exception_handshake(void);
extern void ccci_exception_info_passed(void);
extern kal_uint32 ccci_read_and_wait(CCCI_CHANNEL_T channel, CCCI_BUFF_T *buff, kal_uint32 ticks);

extern kal_int32 ccci_register_sysmsgsvc_callback(kal_uint32 msgno, CCCI_SYSMSGSVC_HISR_CALLBACK funp);
extern kal_bool ccci_send_message(kal_uint32 message, kal_uint32 reserved);


/*******************************************************************************
 * the SDIO specific header file or structure or enum or extern & propotype APIs
 *******************************************************************************/

/*******************************************************************************
 * Define Compile option
 *******************************************************************************/
//#define __UT_CCCI_ON_SDIO__    //for UT
//#define __CCCI_DEBUG_INFO__    //catcher log
//#define __CCCI_IT_DEBUG_INFO__ //uart log
//#define __IT_LB__ //for IT purpose, in real load we should remove the define of __IT_LB__
//#define __FS_TEST__
//#define __IPC_RPC_TEST__
//#define __IT_Error_Handle__
//#define  __UPS_IT_TEST__
//#define __IPCMSG_DEBUG_TRACE__

/*******************************************************************************
 * porting the uart driver for log
 *******************************************************************************/
#if defined (__CCCI_DEBUG_INFO__)
extern tst_sys_trace(char *);
#define CCCI_TRACE(info) tst_sys_trace(info)
#elif defined (__CCCI_IT_DEBUG_INFO__)
extern void ccci_dbg_print(char *fmt,...);
extern void ccci_itoa(char **buf, int i, int base);
#define CCCI_TRACE(info) ccci_dbg_print(debug_info)
#else
#define CCCI_TRACE(info)
#endif

/* defined the log no. for each channel */
#define TX_num 5
#define RX_num 3
#define TX_GIO_num 3
#define RX_GIO_num 1
#define TX_GIO_base 2
#define queue_count 16
#define TX_queue_count 48
#define RX_queue_count queue_count
#define RECYCLE_queue_count 64
#define DebugEntryNo queue_count
#define TEST_LEN 100

//define the size of ccci overhead, the 16 bytes in ccci descriptor
#define CCCI_HAL_OVERHEAD_WORD 4
#define CCCI_HAL_OVERHEAD sizeof(CCCI_BUFF_T)

//the CCCI shared memory size
#define mMdlogShareMemSize 65536 // (4096)*16 ==> (the max size of Mdlogger) * queue_count
#define mPcmShareMemSize 16400 // (16384) ==> (PCM buffer)
#define mUartShareMemSize 32792//16408//(tx,rx, tx_buff, rx_buff) = (12, 12, 8K, 8K)16384 // 197400 //(4kB+16)(TX: 32+RX:16)+CCCI_UARTB_T(12)*2
#define mFileShareMemSize 82020 // (16+4+16384)*5 ==> (FS op, CCCI header, FS buffer) * 5 concurrency task
#define mRpcShareMemSize 4136 // (16+4+2048+4)*2 ==> (RPC op, CCCI header, RPC buffer) * 2 concurrency task
#define mPmicShareMemSize 32 // (16+16) ==> (CCCI header, PMIC buffer)
#define mExceShareMemSize 528 // (16+512) ==> (CCCI header, Exception buffer)
#define mSysShareMemSize 36 // (36) ==> system buffer  
#define mIPCShareMemSize  8304 // 16+12*2+24*2+(4+8)*2+8192 ==> (CCCI header, (tx/rx offset, size)*2, ilm_struct*2, (local+peer)*2, IPC buffer )

/*******************************************************************************
 * the extern variables
 *******************************************************************************/

extern kal_uint32* get_gio_handle();
extern kal_uint32* get_ngio_handle();
extern void sdio_ccci_init(void);

extern kal_int32 ccci_write_internal_sdio(CCCI_CHANNEL_T channel, CCCI_BUFF_T *buff, kal_bool check_lisr, kal_uint32 rx_queue);
extern kal_bool ccci_chk_recentry_in_queue(kal_uint32 query_log);
extern void ccci_CalculateShareMem(kal_uint32 *start_addr, kal_uint32 *end_addr , kal_uint32 *size);

//transparent for previous users
#define ccci_write(a,b) ccci_write_internal_sdio(a,b,1,0)
//dedicated for TST
#define ccci_write_internal(a,b,c) ccci_write_internal_sdio(a,b,c,1)

//the ccci control pool
extern CCCI_CTRL_T ccci_ctrl_pool[CCCI_MAX_CHANNEL];

//the extern info of gTX and gRX
extern kal_uint32 sdio_tx_readindx[TX_num];
extern kal_uint32 sdio_tx_writeindx[TX_num];
extern kal_uint32 sdio_rx_readindx[RX_num];
extern kal_uint32 sdio_rx_writeindx[RX_num];

//the shared memory
extern kal_uint8 MDUartShareMemBase[UART_MAX_PORT_NUM][mUartShareMemSize];
extern kal_uint8 MDMdlogShareMemBase[mMdlogShareMemSize];
extern kal_uint8 MDPcmShareMemBase[mPcmShareMemSize];
extern kal_uint8 MDRpcShareMemBase[mRpcShareMemSize];
extern kal_uint8 MDPmicShareMemBase[mPmicShareMemSize];
extern kal_uint8 MDExceShareMemBase[mExceShareMemSize];
extern kal_uint8 MDSysShareMemBase[mSysShareMemSize];
extern kal_uint8 MDIPCShareMemBase[mIPCShareMemSize];
extern kal_uint8 MDFileShareMemBase[mFileShareMemSize];

#endif /* #if !defined(__SDIO_DEVICE_CONNECTIVITY__) */




#endif /*__MODEM_CCCI_EXIST__ */
#endif  /* !__CCCI_H__ */


