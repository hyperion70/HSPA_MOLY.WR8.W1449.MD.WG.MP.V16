/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2010
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
 * Filename:
 * ---------
 * ps_em_enum.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is for engineer mode.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Log$
 *
 * 05 24 2013 hong.yu
 * [MOLY00023597] [Volunteer Patch][Fast Dormancy] Telefonica_2013Q1_TR-UMTSR-FASTD-002d
 * GENERAL_BIT_FOR_DISABLE_SCRI_ONLY
 *
 * 01 30 2013 xuejing.chen
 * [MOLY00008978] modify or remove CTA related code
 * remove CTA related bit mask.
 *
 * 01 28 2013 xuejing.chen
 * [MOLY00008978] modify or remove CTA related code
 * replace CTA mode with Integrity Protection OFF mode
 *
 * 12 18 2012 vend_edwin.liu
 * [MOLY00007674] [MT6589][DoCoMo][3G][IOT][FD&ETWS][461-1101-0101] CSCB channel cannot turn on the 40960~43007 by default setting
 * .
 *
 * 10 30 2012 hong.yu
 * [MOLY00005424] IOT/Operator Test Mode
 * fix typo
 * 
 * 10 26 2012 hong.yu
 * [MOLY00005424] IOT/Operator Test Mode
 * check in test profile definition
 * 
 * 10 12 2012 chi-chung.lin
 * [MOLY00004506] [MT6280] DoCoMo RPLMN Selection compile option `__RPLMN_INFO_CELL_SELECTION__' removal
 * .
 *
 * 07 17 2012 lexel.yu
 * [MOLY00000844] [L4C] Factory mode auto camp on and auto answer
 * Integration change. 
 *
 * 05 09 2012 chenhao.gong
 * removed!
 * .
 *
 * 05 09 2012 lijuan.qi
 * removed!
 * .
 *
 * 05 04 2012 lexel.yu
 * removed!
 * Integration change. 
 *
 * 11 18 2011 chenhao.gong
 * removed!
 * .
 *
 * 11 09 2011 chenhao.gong
 * removed!
 * .
 *
 * 10 28 2011 lexel.yu
 * removed!
 * Integration change.
 *
 * 09 27 2011 lexel.yu
 * removed!
 * Integration change. 
 *
 * 06 10 2011 lexel.yu
 * removed!
 * Integration change. 
 *
 * 05 11 2011 xi.li
 * removed!
 * .
 *
 * 04 20 2011 xuechao.wang
 * removed!
 * .
 *
 * 03 09 2011 popcafa.shih
 * removed!
 * .
 *
 * 03 04 2011 xi.li
 * removed!
 * .
 *
 * 03 01 2011 junzhen.qin
 * removed!
 * .
 *
 * 02 24 2011 yongjiao.yu
 * removed!
 * .
 *
 * 02 17 2011 yongjiao.yu
 * removed!
 * FDD2TDD code sync stage 3, CTA menu, steady_inactive_ind.
 *
 * 12 08 2010 yc.chen
 * removed!
 * .
 *
 * 11 24 2010 zhiwei.wang
 * removed!
 * Patch NVRAM parts for EM menu.
 *
 * 11 23 2010 chenhao.gong
 * removed!
 * L4 Add PS conformance test EM menu support & AT command Support
 *
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __PS_EM_ENUM_H__
#define __PS_EM_ENUM_H__

/* Constants defined for PS conformance test mode special profile*/


typedef enum
{
    PS_CONF_TEST_NONE,
    PS_CONF_TEST_CTA,
    PS_CONF_TEST_IP_OFF = PS_CONF_TEST_CTA, /* mtk80420: remove CTA mode, replace with Integrity Protection OFF mode */
    PS_CONF_TEST_FTA,
    PS_CONF_TEST_IOT,
    PS_CONF_TEST_OPERATOR,
    PS_CONF_TEST_FACTORY,
    /* Add new test mode here! */
    PS_CONF_TEST_END
} ps_conf_test_mode_enum;

/***************
 * Define bit mask for MMI and PS, each special setting occupy 1 bit.  $$$ 1 bit, please
 * Please try to use the format like this:
 * (MODE)_(MENUNAME)_BIT_FOR_(MODULE)
 * eg. CTA_INTEGRITY_CHECK_BIT_FOR_MM
 *     FTA_ABC_FOR_XYZ or FTA_AB_C_FOR_XYZ_MNQ
 *************** */

/* General bits, and these bits CAN NOT taken by others whatever mode it's (CTA/FTA/IOT) 
   Please avoid to add any more bits here! */
#define GENERAL_BIT_FOR_DISABLE_SCRI_AND_FD 0x00800000
#define GENERAL_BIT_FOR_DISABLE_SCRI_ONLY   0x00400000

/* CTA Items */
#define CTA_CFQUERY_BIT_FOR_SS                  0x00000010
/* mtk80420: remove CTA related bit mask */

/* Add new definition here! */

/* FTA Items */
#define FTA_TEST_ANITE      0x00000001
#define FTA_TEST_CRTUG      0x00000002
#define FTA_TEST_CRTUW      0x00000004
#define FTA_TEST_ANRITSU    0x00000008
#define FTA_TEST_CMW500     0x00000010
/* Add new definition here! */

/* IOT items */
#define IOT_TEST_NSN       0x00000001
#define IOT_TEST_DCM_CB    0x00000002 /*It will enable CBMI 0xA000~0xA7FF for DoCoMo IOT*/

/* Add new definition here! */

/* Operator Test Items */
#define OPERATOR_TEST_MS_USIM_COMPATIBLE    0x00000001
#define OPERATOR_TEST_ATNT                  0x00000002
#define OPERATOR_TEST_TMOBILE               0x00000004
#define OPERATOR_TEST_ORANGE                0x00000008
#define OPERATOR_TEST_VODAFONE              0x00000010
#define OPERATOR_TEST_O2                    0x00000020
#define OPERATOR_TEST_TELEFONICA            0x00000040
#define OPERATOR_TEST_DOCOMO                0x00000080
#define OPERATOR_TEST_SOFTBANK              0x00000100
#define OPERATOR_TEST_VIVO                  0x00000200
#define OPERATOR_TEST_CLARO                 0x00000400
#define OPERATOR_TEST_TIM                   0x00000800
/* Add new definition here! */

/* Factory Items */
#define FACTORY_MODEM_VIRTUAL_SIM_ON_BIT_FOR_L4C                0x00000001
#define FACTORY_MODEM_AUTO_BOOT_AND_AUTO_ANSWER_BIT_FOR_L4C     0x00000002
/* Add new definition here! */

/* -----------For NW EVENT start--------------------- */
#define MAX_LEN_OF_NW_EVENT_NAME 20  
#define MAX_LEN_OF_NW_GROUP_NAME 5
#define EM_NW_NUM_OF_QUEUE_EVENT 32  

typedef enum
{
/* John Tang 2006/11/13 */
#ifdef __UMTS_RAT__
    
    /* MOD_UMAC */
    EM_NW_EVENT_ID_UMAC_EVENT_START,

    EM_NW_EVENT_ID_UMAC_EVENT_END,

    /* MOD_CSCE */
    EM_NW_EVENT_ID_CSCE_CELL_RESELECTION_EVENT,
    EM_NW_EVENT_ID_CSCE_NEW_CELL_SELECTED_EVENT,
    EM_NW_EVENT_ID_CSCE_OUT_OF_SERVICE_EVENT,
    EM_NW_EVENT_ID_CSCE_IN_SERVICE_EVENT,
    
    /* MOD_MEME */
    EM_NW_EVENT_ID_MEME_EVENT_SPECIFIC_CELL_IND,

    /* MOD_RRCE */
    EM_NW_EVENT_ID_RRCE_IRHO_3G2_EVENT, 
    EM_NW_EVENT_ID_RRCE_IRCCO_3G2_EVENT,
    EM_NW_EVENT_ID_RRCE_IRCR_3G2_EVENT,

    /* MOD_SLCE */
    EM_NW_EVENT_ID_SLCE_EVENT_START,

    EM_NW_EVENT_ID_SLCE_EVENT_END,

#endif /* __UMTS_RAT__ */

    EM_NW_EVENT_ID_TEST0,     /* 0 */
    EM_NW_EVENT_ID_TEST1,
    EM_NW_EVENT_ID_TEST2,
    EM_NW_EVENT_ID_TEST3,
    EM_NW_EVENT_ID_TEST4,
    EM_NW_EVENT_ID_TEST5,
    EM_NW_EVENT_ID_TEST6,     /* 5 */
    EM_NW_EVENT_ID_TEST7,
    EM_NW_EVENT_ID_TEST8,
    EM_NW_EVENT_ID_TEST9,
    EM_NW_EVENT_ID_TEST10,
    EM_NW_EVENT_ID_TEST11,    /* 10 */
    EM_NW_EVENT_ID_TEST12,
    EM_NW_EVENT_ID_TEST13,
    EM_NW_EVENT_ID_TEST14,
    EM_NW_EVENT_ID_TEST15,
    EM_NW_EVENT_ID_TEST16,    /* 15 */
    EM_NW_EVENT_ID_TEST17,
    EM_NW_EVENT_ID_TEST18,
    EM_NW_EVENT_ID_TEST19,
    EM_NW_EVENT_ID_TEST20,
    EM_NW_EVENT_ID_TEST21,    /* 20 */
    EM_NW_EVENT_ID_TEST22,
    EM_NW_EVENT_ID_TEST23,
    EM_NW_EVENT_ID_TEST24,
    EM_NW_EVENT_ID_TEST25,
    EM_NW_EVENT_ID_TEST26,    /* 25 */
    EM_NW_EVENT_ID_TEST27,
    EM_NW_EVENT_ID_TEST28,
    EM_NW_EVENT_ID_TEST29,
    EM_NW_EVENT_ID_TEST30,
    EM_NW_EVENT_ID_TEST31,    /* 30 */
    EM_NW_EVENT_ID_TEST32,
    EM_NW_EVENT_ID_TEST33,
    EM_NW_EVENT_ID_TEST34,
    EM_NW_EVENT_ID_TEST35,
    EM_NW_EVENT_ID_TEST36,    /* 35 */
    EM_NW_EVENT_ID_TEST37,
    
    /* RAC Event start */
    EM_NW_EVENT_ID_CELL_POWER_LEVEL_IND,
    EM_NW_EVENT_ID_GMMREG_ATTACH_CNF,

    /* RAC Event End */
    
    EM_NW_EVENT_ID_MAX
    
} EM_NW_EVENT_ID_ENUM;

typedef enum
{
#ifdef __UMTS_RAT__
    //EM_NW_EVENT_GROUP_UMAC,
    EM_NW_EVENT_GROUP_CSCE,
    EM_NW_EVENT_GROUP_MEME,
    EM_NW_EVENT_GROUP_RRCE,
    //EM_NW_EVENT_GROUP_SLCE,
#endif /* __UMTS_RAT__ */
    EM_NW_EVENT_GROUP_RAC,
    /* don't remove this item and add new item before it */
    EM_NW_MAX_NO_OF_GROUP
} EM_NW_EVENT_GROUP_ENUM;
/* -----------For NW EVENT end------------------------- */


#endif  /* __PS_EM_ENUM_H__ */

