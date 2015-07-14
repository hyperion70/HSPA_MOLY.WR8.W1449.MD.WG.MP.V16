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
 *   clib.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   For C library type & function porting on MAUI.
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
 */
 
#ifndef CLIB_H
#define CLIB_H

#ifdef __cplusplus
extern "C" {
#endif

#if !defined(GEN_FOR_PC)

/* custom mtk_jmpbuf definition
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 */
#include <setjmp.h>
#if defined(__MTK_TARGET__) && defined(__RVCT__) && !defined(__TARGET_FPU_VFP) && !defined(__ARM_FPUV2__)
typedef long long mtk_jmpbuf[6];
#else
typedef jmp_buf mtk_jmpbuf;
#endif
#define __MTK_JMPBUF_DEFINED__ 1

#define __CLK_TCK ((int)(1000/4.615))

/* ADS1.2/VS2008 miss strtok_r definition */
char *strtok_r(char *s1, const char *s2, char **ptr);

/* only check the not support function when building target */
#if defined(__MTK_TARGET__)
/* ADS1.2 miss localtime_r/gmtime_r definition */
#include <time.h>
struct tm *localtime_r(const time_t *timer, struct tm *result);
struct tm *gmtime_r(const time_t *timer, struct tm *result);

#if defined(__RVCT__) || defined(__GNUC__)    
#include <stdio.h>
#include <stdarg.h>
#include <wchar.h>

#ifndef __cplusplus /* mark all using deprecated symbol as an error,except cplusplus */
#if defined(__RVCT__)
#pragma diag_error 1361,2570
#elif defined(__GNUC__)
#pragma GCC diagnostic error "-Wdeprecated-declarations"
#endif 
#endif/*__cplusplus*/
#define NOTSUPPORT_FUNCTION __attribute__((deprecated))
#define INIT_NOTSUPPORT_FUNCTION
#define LINKTIME_CHECKING
#define WANT_CLIB_LIST
#include "clib_list.h"

#endif /*defined(__RVCT__) || defined(__GNUC__) */

#elif defined(KAL_ON_OSCAR)
/* On VS2008, I can't include time.h directly because VS2008 time.h conflict with obigo03 library 
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 */
#define localtime_r(timer, tm_p) (struct tm *)((*(tm_p) = *localtime(timer)), (tm_p))
#define gmtime_r(timer, tm_p) localtime_r(timer, tm_p)
#endif/*defined(__MTK_TARGET__)*/

void clib_basic_init(void);
void clib_init(void);

#endif /* !GEN_FOR_PC */

#ifdef __cplusplus
}
#endif

#endif
