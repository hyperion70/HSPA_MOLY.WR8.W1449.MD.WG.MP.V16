#!/usr/bin/perl
#
#  Copyright Statement:
#  --------------------
#  This software is protected by Copyright and the information contained
#  herein is confidential. The software may not be copied and the information
#  contained herein may not be used or disclosed except with the written
#  permission of MediaTek Inc. (C) 2006
#
#  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
#  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
#  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
#  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
#  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
#  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
#  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
#  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
#  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
#  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
#  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
#  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
#
#  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
#  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
#  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
#  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
#  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
#
#  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
#  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
#  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
#  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
#  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
#
#*****************************************************************************
#*
#* Filename:
#* ---------
#*   ModemReservedSize_AutoConfig.pl
#*
#* Project:
#* --------
#*
#*
#* Description:
#* ------------
#*   This script parses sym/linker script 
#*   and give some recommendation or create new MEMORY config file
#* Author:
#* -------
#*   Qmei Yang  (mtk03726)
#*
#****************************************************************************/

#****************************************************************************
# Included Modules
#****************************************************************************
use strict;
BEGIN { push @INC, './tools/', './tools/MemoryUtility/' }  # add additional library path             
use auto_adjust_mem; #pm file name without case sensitivity
use FileInfoParser;
use sysGenUtility;
use CommonUtility;
use BasicMemInfoQuery;
use systemInfo;
use ldsFrame;
use File::Basename;
use File::Copy;
use File::Path;
use LinkerOutputParser;
use POSIX qw(floor ceil);
#****************************************************************************
# AutoCheckin Information
#****************************************************************************
use constant OWNER        => "";
#****************************************************************************
# Constants
#****************************************************************************
my $MODEMSIZE_CONFIG_VERNO    = " v0.06";
                               #  v0.06, 20130425 by mei, Not to limit SetMemorySegment() in NOR project only 
                               #  v0.05, 20130321 by mei, Support to show basic ram info during checking load view
                               #  v0.04, 20130321 by mei, Set MT6572&6582 to be 2 MB aligned
                               #  v0.03, 20130208 by mei, perl 5.58 can't support: make_path
                               #  v0.02, 20130124 by mei, to replace chip with cloned chip
                               #  v0.01, initial draft

#****************************************************************************
# Inputs
#****************************************************************************
my $MAP_PATH                    = $ARGV[0]; 
my $SYM_PATH                    = $ARGV[1];
my $LDS_PATH                    = $ARGV[2];
my $BUILD_FOLDER                = $ARGV[3];
my $FEATURE_CONFIG_H            = $ARGV[3] . "/custom_FeatureConfig.h";
my $MAKE_FILE                   = $ARGV[4];
my $INTERMEDIATE_FILE           = $ARGV[5];  #build/.../tmp/~ModemReservedSize_AutoConfig.tmp 
my $LOG_PATH                    = $ARGV[6];
my $PROJECT_NAME                = basename($MAKE_FILE);

print "Input:\n$ARGV[0]\n$ARGV[1]\n$ARGV[2]\n$ARGV[3]\n$ARGV[4]\n$ARGV[5]\n$ARGV[6]\n";

#****************************************************************************
# Global Variables
#****************************************************************************
my %MAKEFILE_OPTIONS;
my $g_bAutoConfig = 0;
my $ERR_CODE;
my $g_nExpectedROMSize = undef;
my $g_nExpectedRAMSize = undef;
my $g_strMsg;
#****************************************************************************
# >>>  Check if it's able to adjust
#****************************************************************************
my $bEnableAutoConfig = IsEnabledAutoConfig($MAKE_FILE, \%MAKEFILE_OPTIONS);
my $bHasHistory = sysUtil::HasCheckinHistory($LDS_PATH);
my $g_bb = sysUtil::SwitchToClonedChip(FileInfo::GetChip());
my $g_bSupportedToAdjustLoadView = sysUtil::isSupportedToAdjustLoadView($g_bb);
my $g_bSupportedToAdjustRAMSize = sysUtil::isSupportedToAdjustRAMSize($g_bb);
my $bSupportedCompiler = (FileInfo::GetCompiler() eq "GCC");
$g_bAutoConfig = ($bEnableAutoConfig 
             and (defined $bHasHistory and $bHasHistory == 0)
             and ($g_bSupportedToAdjustLoadView or $g_bSupportedToAdjustRAMSize) 
             and $bSupportedCompiler);

print "-----------------------------------------------------------------\n";
print "Check if it's able to adjust($g_bAutoConfig):\n";
print "bEnableAutoConfig      = $bEnableAutoConfig\n";
print "bHasHistory            = $bHasHistory\n";
print "SupportedMDAutoConfig = (LoadView=$g_bSupportedToAdjustLoadView or RamSize=$g_bSupportedToAdjustRAMSize)\n";
print "bSupportedCompiler     = $bSupportedCompiler\n";
my $strPrompt = (!$g_bAutoConfig) ? "disabled" : "enabled";
PrintLog("AutoConfig is $strPrompt\n");
#****************************************************************************
# >>>  Main Flow
#****************************************************************************
if(!$g_bAutoConfig) # not able to config
{
    if(!$bSupportedCompiler)
    {
        print "Unsupported Compiler: ".FileInfo::GetCompiler()."\n";
        $ERR_CODE = ERR::CANNOT_ADJUST;
    }
    else
    {
        $ERR_CODE = CheckLoadViewSize($MAKE_FILE, $LDS_PATH, $MAP_PATH, $SYM_PATH, $INTERMEDIATE_FILE);
    }
}
else
{
    $ERR_CODE = AutoAdjust($MAKE_FILE, $LDS_PATH, $MAP_PATH, $SYM_PATH);
}

#****************************************************************************
# oo >>>  Finished
#****************************************************************************
PrintLog("-----------------------------------------------------------------\n");
PrintLog("RESULT = ". ERR::QueryErrMeaning($ERR_CODE)."\n");
CommonUtil::WriteFileContent($INTERMEDIATE_FILE, $g_strMsg);
exit $ERR_CODE;


sub AutoAdjust
{
    my ($MAKE_FILE, $LDS_PATH, $MAP_PATH, $SYM_PATH)= @_;
    # 1. ROM(LoadViewSize)
    my $nLoadViewSize = BasicMemInfo::CMD_GetLoadViewSize($MAKE_FILE, $LDS_PATH, $MAP_PATH, $SYM_PATH, undef);#\&PrintLog
    $g_nExpectedROMSize = BasicMemInfo::GetMBAlignment($nLoadViewSize, 1); 
    # 2. RAM Size # reserved margin at least 0.5MB
    my ($nRAMUsage, $nRAMMargin, $nReservedSize) = BasicMemInfo::CMD_GetRAMUsage($MAKE_FILE, $LDS_PATH, $MAP_PATH, $SYM_PATH, undef);
    $g_nExpectedRAMSize = GetExpectedRAMSize($g_nExpectedROMSize, $nRAMUsage + $nReservedSize, 0.5*1024*1024);
    # 3. Get LDS ROM Length and RAM Length, and the 1stRegion Base in RAM
    my $nROM_Length = hex(sysInfo::GetMemoryInfo("ROM", 2, $LDS_PATH));
    my $nRAM_Length = hex(sysInfo::GetMemoryInfo("RAM", 2, $LDS_PATH));
    my $ERsInRAM_aref = BasicMemInfo::GetERsInRAM($MAKE_FILE, $LDS_PATH, $MAP_PATH, $SYM_PATH, undef);
    my $n1stERInRAMVMA = hex(&LinkerOutputParser::GetExeRegionInfo($ERsInRAM_aref->[0], Region::VMA));
    my $nMB = ($g_nExpectedROMSize+$g_nExpectedRAMSize)/(1024*1024);
    
    PrintLog("----------------------------Auto Adjust--------------------------\n");
    PrintLog("Actual ROM(Load View) Size = ". CommonUtil::Dec2Hex($nLoadViewSize)."\n");
    PrintLog("current ROM Length in LDS= ". CommonUtil::Dec2Hex($nROM_Length)."\n");
    PrintLog("current RAM Origin in LDS = ". sysInfo::GetMemoryInfo("RAM", 1, $LDS_PATH). "\n");
    PrintLog("current RAM Length in LDS= ". CommonUtil::Dec2Hex($nRAM_Length)."\n");
    PrintLog("current 1stER in ram = ".$ERsInRAM_aref->[0].", VMA=". CommonUtil::Dec2Hex($n1stERInRAMVMA)."\n");
    PrintLog("current RAM Usage = ".CommonUtil::Dec2Hex($nRAMUsage)."\n");
    PrintLog("current RAM Reserved Sizes = ".CommonUtil::Dec2Hex($nReservedSize)."\n");
    PrintLog("current RAM Margin = ".CommonUtil::Dec2Hex($nRAMMargin)."\n");
    PrintLog("expected ROM Sizes = ". CommonUtil::Dec2Hex($g_nExpectedROMSize)."\n");
    PrintLog("expected RAM Sizes = ". CommonUtil::Dec2Hex($g_nExpectedRAMSize)."\n");
    PrintLog("expected MD Sizes to be ". sysUtil::GetMD_AlignmentByChip($g_bb) ."MB aligned:\n");
    PrintLog("expected MD Sizes(ROM+RAM) = ". CommonUtil::Dec2Hex($g_nExpectedROMSize+$g_nExpectedRAMSize)." = $nMB MB \n");
    PrintLog("-----------------------------------------------------------------\n");
    
    my $err;
    if(($g_bSupportedToAdjustLoadView and (($nLoadViewSize > $nROM_Length) or ($n1stERInRAMVMA != $g_nExpectedROMSize))) 
    or ($g_bSupportedToAdjustRAMSize  and ($g_nExpectedRAMSize != $nRAM_Length) )) # RAM size is RAM BASE+LEN
    {
        my $strFilePath = PrepareFileToModify();
        ModifyMEMORY($strFilePath);
        $err = ERR::AUTOCONFIG_SELF_MODIFY_SUCCESS;
        RecommendDuringAutoAdjust($err, $nLoadViewSize, $nROM_Length, 
                                 $n1stERInRAMVMA, $ERsInRAM_aref->[0], $nRAM_Length, ($nRAMUsage + $nReservedSize));
    }
    else
    {
        $err = ERR::NO_NEED_TO_UPDATE;
        $err = RecommendDuringAutoAdjust($err, $nLoadViewSize, $nROM_Length, 
                                 $n1stERInRAMVMA, $ERsInRAM_aref->[0], $nRAM_Length, ($nRAMUsage + $nReservedSize));
    }
    return $err;
}

sub RecommendDuringAutoAdjust
{
    my ($err, $nLoadViewSize, $nROM_Length, $n1stERInRAMVMA, $ER1st, $nRAM_Length, $nRAMTotalUsage) = @_;
    if($nLoadViewSize > $nROM_Length)
    {
        if(!$g_bSupportedToAdjustLoadView)
        {
            PrintLog("Actual ROM(Load View) Size > ROM Length in LDS\n");
            PrintLog("[Recommend] Setting ROM Length to " . CommonUtil::Dec2Hex($g_nExpectedROMSize)."\n");
        }
        $err = ERR::CANNOT_ADJUST;
    }
    if($n1stERInRAMVMA != $nLoadViewSize)
    {
        if(!$g_bSupportedToAdjustLoadView)
        {
            PrintLog("[Recommend] Setting the base address of $ER1st to ".CommonUtil::Dec2Hex($g_nExpectedROMSize)."\n");
        }
        $err = ERR::CANNOT_ADJUST if($n1stERInRAMVMA < $nLoadViewSize);
    }
    if($g_nExpectedRAMSize != $nRAM_Length)
    {
        if(!$g_bSupportedToAdjustRAMSize)
        {
            PrintLog("[Recommend] Setting RAM Length to " . CommonUtil::Dec2Hex($g_nExpectedRAMSize)."\n");
        }
        $err = ERR::CANNOT_ADJUST if($nRAM_Length < $nRAMTotalUsage);
    }
    return $err;
}

sub PrepareFileToModify
{
    ldsFrame::CleanCallBackFunc();
    my $strDefaultMEMORYPath = ldsFrame::GetPath($g_bb, ldsFrame::MEMORY);
    my $strFilePath = $strDefaultMEMORYPath;
    if($strDefaultMEMORYPath =~ /custom\/system\/(.+)/i)
    {
        my $strTemp = $1;
        $BUILD_FOLDER .= "/" if($BUILD_FOLDER !~ /\/$/);
        $strFilePath = $BUILD_FOLDER . $strTemp;
        if(!-e $strFilePath)
        {
            my $DIR = dirname($strFilePath);
            mkpath($DIR) if(!-f $DIR);
            print "[PrepareFileToModify]copy $strDefaultMEMORYPath \nto $strFilePath\n";
            copy($strDefaultMEMORYPath, $strFilePath) or config_die("Copy Fail!");
            # chmod for read-only codebase
            chmod(0640, $strFilePath) if($^O eq "MSWin32");
        }
    }
    return $strFilePath;
}
sub ModifyMEMORY
{
    my ($strFilePath) = @_;
    &ldsFrame::CleanCallBackFunc();
    &ldsFrame::SetCallBackFunc("GetChip", \&GetChip);
    &ldsFrame::SetCallBackFunc("SetMemorySegment", \&SetMemorySegment);
    &ldsFrame::SetCallBackFunc("GetCustomFolder", \&GetCustomFolder);
    my $strContent = ldsFrame::GenMEMORY(ldsFrame::MAIN);
    CommonUtil::WriteFileContent($strFilePath, $strContent);
    print "Generate $strFilePath successfully!\n";
}
sub GetCustomFolder  #ldsFrame's callback func
{
    return $BUILD_FOLDER;
}
sub GetChip  # ldsFrame's callback func
{
    return $g_bb;
}

sub GetExpectedRAMSize
{
    my ($nLVMBAlignedSize, $nRAMSize, $nReservedSize) = @_;
    my $nOrgSize = $nLVMBAlignedSize + $nRAMSize;
    my $nExpectedRamSize = BasicMemInfo::GetMBAlignment($nOrgSize, sysUtil::GetMD_AlignmentByChip($g_bb));
    if(($nExpectedRamSize - $nOrgSize) < $nReservedSize)
    {
        $nExpectedRamSize = BasicMemInfo::GetMBAlignment($nOrgSize+$nReservedSize, sysUtil::GetMD_AlignmentByChip($g_bb));
    }
    return $nExpectedRamSize - $nLVMBAlignedSize;
}

sub SetMemorySegment # ldsFrame's callback func
{
    my ($MEMORY_SEGMENT_aref) = @_;
    my $nIndex = 0;
    my $NCPrefix = sysUtil::GetNonCacheablePrefix($g_bb);
    my $CPrefix = sysUtil::GetCacheablePrefix($g_bb);
    foreach my $i (@$MEMORY_SEGMENT_aref)
    {
        my $strName = $i->[0];
        if($strName eq "ROM")
        {
            if($g_bSupportedToAdjustLoadView)
            {
                $MEMORY_SEGMENT_aref->[$nIndex]->[2] = CommonUtil::Dec2Hex($g_nExpectedROMSize);
                PrintLog("Modify ROM Length = ".CommonUtil::Dec2Hex($g_nExpectedROMSize)."\n");
            }
        }
        else
        {
            if($NCPrefix == 0)
            {
                if($strName eq "RAM" and $g_bSupportedToAdjustLoadView)
                {
                    $MEMORY_SEGMENT_aref->[$nIndex]->[1] = CommonUtil::Dec2Hex($g_nExpectedROMSize);
                    PrintLog("Modify RAM ORIGIN = ".CommonUtil::Dec2Hex($g_nExpectedROMSize)."\n");
                }    
            }
            elsif($CPrefix == 0)
            {#on MOLY
                if($strName eq "VRAM" and $g_bSupportedToAdjustLoadView)
                {
                    $MEMORY_SEGMENT_aref->[$nIndex]->[1] = CommonUtil::Dec2Hex($g_nExpectedROMSize);
                    PrintLog("Modify VRAM ORIGIN = ".CommonUtil::Dec2Hex($g_nExpectedROMSize)."\n");
                }
            }
            if($strName eq "RAM" and $g_bSupportedToAdjustRAMSize)
            {
                $MEMORY_SEGMENT_aref->[$nIndex]->[2] = CommonUtil::Dec2Hex($g_nExpectedRAMSize);
                PrintLog("Modify RAM Length = ".CommonUtil::Dec2Hex($g_nExpectedRAMSize)."\n");
            }
        }
        $nIndex++;
    }
}

sub ShowBasicInfo
{
    my ($MAKE_FILE, $LDS_PATH, $MAP_PATH, $SYM_PATH, $INTERMEDIATE_FILE, $nExpectedROMSize)= @_;
    my ($nRAMUsage, $nRAMMargin, $nReservedSize) = BasicMemInfo::CMD_GetRAMUsage($MAKE_FILE, $LDS_PATH, $MAP_PATH, $SYM_PATH, undef);
    my $nExpectedRAMSize = BasicMemInfo::GetMBAlignment($nRAMUsage+$nReservedSize, 1);
    my $nMB = ($nExpectedROMSize + $nExpectedRAMSize)/(1024*1024);
    PrintLog("-----------------Current BasicInfo for reference-----------------\n");
    PrintLog("current RAM Usage = ".CommonUtil::Dec2Hex($nRAMUsage)."\n");
    PrintLog("current RAM Reserved Sizes = ".CommonUtil::Dec2Hex($nReservedSize)."\n");
    PrintLog("current RAM Margin = ".CommonUtil::Dec2Hex($nRAMMargin)."\n");
    PrintLog("After 1MB aligned:\n");
    PrintLog("ROM Sizes = ". CommonUtil::Dec2Hex($nExpectedROMSize)."\n");
    PrintLog("RAM Sizes (RAM Usage + Reserved Sizes) = ". CommonUtil::Dec2Hex($nExpectedRAMSize)."\n");
    PrintLog("Actual MD Usage(ROM+RAM) = ". CommonUtil::Dec2Hex($nExpectedROMSize+$nExpectedRAMSize)." = $nMB MB \n");
    PrintLog("-----------------------------------------------------------------\n");
}

sub CheckLoadViewSize
{
    my ($MAKE_FILE, $LDS_PATH, $MAP_PATH, $SYM_PATH, $INTERMEDIATE_FILE)= @_;
    my $err;
    #Check LoadView size with ROM Length and 1st RAM Base
    # 1. ROM(LoadViewSize)
    my $nActualROMSize = BasicMemInfo::CMD_GetLoadViewSize($MAKE_FILE, $LDS_PATH, $MAP_PATH, $SYM_PATH, undef);
    my $nExpectedROMSize = BasicMemInfo::GetMBAlignment($nActualROMSize, 1);
    # 2. ROM of MEMORY in LDS
    my $nROM_Length = hex(sysInfo::GetMemoryInfo("ROM", 2, $LDS_PATH));
    # 3. VMA of 1st Region in RAM
    my $ERsInRAM_aref = BasicMemInfo::GetERsInRAM($MAKE_FILE, $LDS_PATH, $MAP_PATH, $SYM_PATH, undef);
    my $n1stERInRAMVMA = 0x0FFFFFFF & hex(&LinkerOutputParser::GetExeRegionInfo($ERsInRAM_aref->[0], Region::VMA));
    
    PrintLog("-------------------------Check Load View------------------------\n");
    PrintLog("Actual ROM(Load View) Size = ". CommonUtil::Dec2Hex($nActualROMSize)."\n");
    PrintLog("current ROM Length in LDS= ". CommonUtil::Dec2Hex($nROM_Length)."\n");
    PrintLog("current RAM Origin in LDS = ". sysInfo::GetMemoryInfo("RAM", 1, $LDS_PATH). "\n");
    PrintLog("current 1st ER in ram = ".$ERsInRAM_aref->[0].", VMA=". CommonUtil::Dec2Hex($n1stERInRAMVMA)."\n");
    PrintLog("-----------------------------------------------------------------\n");
    ShowBasicInfo($MAKE_FILE, $LDS_PATH, $MAP_PATH, $SYM_PATH, $INTERMEDIATE_FILE, $nExpectedROMSize);
    #-----------------------------------------------------
    if(($nActualROMSize > $nROM_Length) or ($nActualROMSize > $n1stERInRAMVMA))
    {
        if($nActualROMSize > $nROM_Length)
        {
            PrintLog("Actual ROM(Load View) Size > ROM Length in LDS\n");
            PrintLog("[Recommend] Setting ROM Length to " . CommonUtil::Dec2Hex($nExpectedROMSize)."\n");
        }
        if($nActualROMSize > $n1stERInRAMVMA)
        {
            PrintLog("Actual ROM(Load View) Size > 1st VMA in RAM\n");
            PrintLog("[Recommend] Setting the base address of " . $ERsInRAM_aref->[0] . 
                        " to " . CommonUtil::Dec2Hex($nExpectedROMSize)."\n");
        }
        $err = ERR::ERR_LOADVIEWSIZE_INSUFFICIENT;
    }
    else
    {
        if($n1stERInRAMVMA != $nExpectedROMSize)
        {
            PrintLog("[Recommend] Setting the base address of " . $ERsInRAM_aref->[0] . 
                    " to " . CommonUtil::Dec2Hex($nExpectedROMSize)."\n");
        }
        if($nROM_Length < $nExpectedROMSize)
        {
            PrintLog("[Recommend] Setting ROM Length to " . CommonUtil::Dec2Hex($nExpectedROMSize)."\n");
        }
        if(!(($nROM_Length < $nExpectedROMSize) or ($n1stERInRAMVMA != $nExpectedROMSize)))
        {
            PrintLog("[Load View Analysis] PASS \n");
        }
        PrintLog("-----------------------------------------------------------------\n");
        $err = IsPrvLinkedPASS($INTERMEDIATE_FILE) ? ERR::NO_MODIFY : ERR::CANNOT_ADJUST;
        ($err == ERR::NO_MODIFY) ? PrintLog("Previous Linkage: PASS\n") : PrintLog("Previous Linkage: FAIL\n");
    }
    return $err;
}

sub PrintLog
{
    my ($strContent) = @_;
    print $strContent;
    $g_strMsg .= $strContent;
}

sub IsEnabledAutoConfig
{
    my ($MK_PATH, $mk_option_href) = @_; 
    if(1 != &FileInfo::Parse_MAKEFILE($MK_PATH, $mk_option_href))
    {
        print "MakeFile Parse Error: ERR_UNEXPECTED\n";
        exit ERR::ERR_UNEXPECTED;
    }
    my $bEnable = FileInfo::get(uc("ModemReservedSize_AutoConfig")) eq "TRUE" ? 1 : 0;
    return $bEnable;
}

sub IsPrvLinkedPASS
{
    my ($INTERMEDIATE_FILE) = @_;
    my $strContent = CommonUtil::GetFileContent($INTERMEDIATE_FILE);
    return $strContent eq ""; # equal "" = PASS, having contents = FAIL
}

#****************************************************************************
# subroutine:  config_die
# sample code: (message, __FILE__, __LINE__)
# input:       $error_msg, $file, $line_no
#****************************************************************************
sub config_die
{
    my ($error_msg) = @_;
    my ($pack_name, $file, $line_no) = caller;
    &AUTO_ADJUST::error_handler($error_msg, $file, $line_no, 'ModemReservedSize_Config');
}
