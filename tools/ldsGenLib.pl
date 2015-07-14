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
#*   ldsGenLib.pl
#*
#* Project:
#* --------
#*
#*
#* Description:
#* ------------
#*   This script is to generate memory layout
#*
#* Author:
#* -------
#*   Qmei Yang (mtk03726)
#*
#****************************************************************************/
#****************************************************************************
# Included Modules
#****************************************************************************
use strict;
BEGIN { push @INC, './tools/' }  # add additional library path
use sysGenUtility;
use ldsFrame;
use FileInfoParser;
use config_MemSegment;
use tools::pack_dep_gen;
PrintDependModule();

#****************************************************************************
# 0 >>> exit;
#****************************************************************************
return 1;
#****************************************************************************
# ldsGen Version
#****************************************************************************
sub ldsGen_verno
{
    return " m0.34 + ldsFrame.pm ".&ldsFrame::ldsFrame_verno;
           # m0.34 , 20150123 by carl, Set MT6572 default MD size limit to 18MB
           # m0.33 , 20150122 by carl, Set MT6572 default MD size limit to 20MB
           # m0.32 , 20130725 by mei, Set MT6592 default MD size limit to 22MB
           # m0.31 , 20130725 by mei, Support MT6571
           # m0.30 , 20130725 by mei, Support MT6592
           # m0.28 , 20130228 by mei, Support read MEMORY input before setting default value
           # m0.26 , 20130124 by mei, Change MT6280's layout design
           # m0.25 , 20130115 by mei, Support to read MEMORY input as default value if ever defining it
           #                          Remove VRAM due to not using it in MEMORY Config file anymore
           #                          Remove GenSTART_RAM due to using ORIGIN(RAM) instead of it
           # m0.24 , 20130113 by mei, Support getting template from build/../custom/system first
           # m0.23 , 20121217 by mei, Support MT6572 & MT6582
           # m0.22 , 20121031 by mei, Support not to make error code become a function name 
           # m0.21 , 20121002 by mei, [Reserved for MOLY]
           # m0.20 , 20121030 by mei, Use ROM to limit load view in MT6589
           # m0.19 , 20121030 by mei, Enlarge MT6280 RamSize(18MB) for RNDIS Dongle
           # m0.18 , 20121029 by mei, Support RESERVED_FOR_DUMMY_END for generating MEMORY
           # m0.17 , 20121019 by mei, Change MT6280 RamSize(16MB: CCCI constraint) for RNDIS Dongle
           #                          Change MT6280 RamSize(18MB) for Hosted Dongle
           # m0.16 , 20121002 by mei, Replace GenSTART_ROM by ORIGIN(ROM)
           # m0.15 , 20120923 by mei, Rename MT6583 to MT6589
           # m0.14 , 20120920 by mei, Support BOOT_CERT
           # m0.13 , 20120918 by mei, Modify MT6583_MD1/MD2 ram size by modes
           # m0.12 , 20120830 by mei, Modify MT6583_MD2 ram size
           # m0.11 , 20120817 by mei, Support MT6583
           # m0.10 , 20120702 by mei, Support EWS
           # m0.09 , 20120702 by mei, Support not to duplicate too many chips via SwitchToClonedChip()
           # m0.08 , 20120628 by mei, Support adding EXT_BL_LOAD_MEM
           # m0.07 , 20120604 by mei, Make SetRegionList() more flexible
           # m0.06 , 20120530 by mei, Support MT6575(MT6515)
           # m0.05 , 20120528 by mei, Support EXTSRAM +0x0 ALIGN 1MB: in only RAM view
           # m0.04 , 20120528 by mei, Support path and filename case sensitive on Linux
           # m0.03 , 20120528 by mei, Use /Discard/ instead of EMPTY region
           # m0.02 , 20120512 by mei, Support BL Linker Script
           # m0.01 , 20120507 by mei, initial version
}

#****************************************************************************
# Constants
#****************************************************************************


#****************************************************************************
# Global Variables
#****************************************************************************
my $g_bb = undef;
my $g_nRamSize = undef;
my $g_bNeedBL = undef;
my $g_BBFolder = undef;
my $g_MakeFilePath = undef;
my $g_MakeFile_ref = undef;
#****************************************************************************
# Input Parameters
#****************************************************************************

#****************************************************************************
# subroutines
#****************************************************************************

#****************************************************************************
# Unsupport: $flash_href, $flash_blk_href
#            $nor_device, $fota_cfg,
#            $mem_dev_h_cfg
#            $IsFlashtoolLayoutInput, $use_dummy_scatter, $feature_config, $nFactoryBinSize
#****************************************************************************
sub ldsGen_main
{
    ($g_bb, $g_nRamSize, $g_bNeedBL, $g_BBFolder, $g_MakeFilePath) = @_;
    $g_bb = &sysUtil::SwitchToClonedChip($g_bb);
    $g_MakeFile_ref = &FileInfo::GetMakeFileRef($g_MakeFilePath);
    my $strLayout = &GenLDSProcess();
    return $strLayout;
}
sub GenLDSProcess
{
    &ldsFrame::CleanCallBackFunc();
    &ldsFrame::SetCallBackFunc("GetChip", \&GetChip);
    &ldsFrame::SetCallBackFunc("CollectMemorySetting", \&CollectMemorySetting);
    &ldsFrame::SetCallBackFunc("SetMemorySegment", \&SetMemorySegment) if(&FileInfo::is_NOR());
    &ldsFrame::SetCallBackFunc("SetRegionList", \&SetRegionList);
    &ldsFrame::SetCallBackFunc("GetCustomFolder", \&GetCustomFolder);
    
    return &ldsFrame::GenLDS(ldsFrame::MAIN);
}
sub GetChip  #CallBack func
{
    return $g_bb;
}
sub GetCustomFolder #CallBack func
{
    return $g_BBFolder;   
}

sub CollectMemorySetting  #CallBack func
{
    my ($MEMORYPath, $RegionList_ref, $Index_ref) = @_;
    my $bb = $g_bb;
    $bb =~ s/\_(\S+)//;
    my $func = "$bb\_MemorySetting";
    &sysUtil::sysgen_die("Unsupported Memory Setting on $g_bb! $func must exist.", __FILE__, __LINE__) if not defined &{$func}; 
    no strict 'refs';
    my %Setting;
    RefineMEMORYWithInput($MEMORYPath, \%Setting);
    &{$func}(\%Setting);
    my $nReservedSize = &GetReservedSize_FromBottomToTop_OnRAM(undef, $RegionList_ref, $Index_ref,
                                           "DSP_RX", "DUMMY_END");
    $Setting{"RESERVED_FOR_DUMMY_END"} = &CommonUtil::Dec2Hex($nReservedSize);
    $Setting{"CACHEABLE_PREFIX"} = &CommonUtil::Dec2Hex(sysUtil::GetCacheablePrefix($g_bb));
    $Setting{"NONCACHEABLE_PREFIX"} = &CommonUtil::Dec2Hex(sysUtil::GetNonCacheablePrefix($g_bb));
    
    return \%Setting;
}

sub SetMemorySegment   #CallBack func
{   
    my ($MEMORY_SEGMENT_aref) = @_;
    #nor
}

sub RefineMEMORYWithInput
{
    my ($MEMORYPath, $Setting_href) = @_;
    my $Memory_aref = &ldsInfo::ParseMEMORY(&CommonUtil::GetFileContent($MEMORYPath));
    foreach my $info (@$Memory_aref)
    {
        if($info->[0] eq "ROM")
        {
            my $strBase = GetUsefulInfo($info->[1]);
            my $strLen = GetUsefulInfo($info->[2]);
            $Setting_href->{ROM_BASE} = $strBase if(defined $strBase);
            $Setting_href->{ROM_LEN}  = $strLen  if(defined $strLen);
        }
        elsif($info->[0] eq "RAM")
        {
            my $strBase = GetUsefulInfo($info->[1]);
            my $strLen = GetUsefulInfo($info->[2]);
            $Setting_href->{RAM_BASE} = $strBase if(defined $strBase);
            $Setting_href->{RAM_LEN}  = $strLen  if(defined $strLen);
        }
        elsif($info->[0] eq "VRAM")
        {
            my $strBase = GetUsefulInfo($info->[1]);
            my $strLen = GetUsefulInfo($info->[2]);
            $Setting_href->{VRAM_BASE} = $strBase if(defined $strBase);
            $Setting_href->{VRAM_LEN}  = $strLen  if(defined $strLen);
        }
    }
}
sub GetUsefulInfo
{
    my ($strInput) = @_;
    $strInput =~ s/\[(.+)\]|\s//g;
    $strInput = undef if($strInput !~ /^0x(\w+)$|(\w+)$/);
    return $strInput;
}

sub SetRegionList  #CallBack func
{
    my ($BasicRegionList_ref, $Index_ref, $MEMORYSetting_href) = @_;
    my @RegionList;
    foreach my $item (@$BasicRegionList_ref)
    {
        my $strCondition = $item->[$Index_ref->{Condition}];
        next if($strCondition ne "" and 0 == &FileInfo::EvaluateFeatureOptionCondition($strCondition, $g_MakeFile_ref));
        push @RegionList, $item;
    }
    for(my $i=0; $i<= $#RegionList; $i++)
    {
        my $nColumnCount = scalar(@{$RegionList[$i]});
        for(my $j=0; $j <= $nColumnCount; $j++)
        {
            if($RegionList[$i]->[$j] =~/\[(\w+)\]/)
            {
                my $strToReplace = $1;
                no strict 'refs';
                my $func = "Gen".$1;
                my $template = &{$func}($MEMORYSetting_href, \@RegionList, $Index_ref) if (exists &{$func})
                  or &sysUtil::sysgen_die("$func() doesn't exists!", __FILE__, __LINE__);
                $RegionList[$i]->[$j] =~ s/\[$strToReplace\]/$template/g;
            }  
        }
    }
    return \@RegionList;
}

sub GenITCM_BASE # Fill in RegionList.csv
{
    my ($MEMORYSetting_href, $RegionList_aref, $Index_ref) = @_;
    my $Keyword = "ITCM";
    $Keyword = "TCM" if(&sysUtil::is_CR4($g_bb));
    return $MEMORYSetting_href->{$Keyword}->[0];
}
sub GenDTCM_BASE # Fill in RegionList.csv
{
    my ($MEMORYSetting_href, $RegionList_aref, $Index_ref) = @_;
    my $Keyword = "DTCM";
    return $MEMORYSetting_href->{$Keyword}->[0];
}
sub GenDTCM_SIZE # Fill in RegionList.csv
{
    my ($MEMORYSetting_href, $RegionList_aref, $Index_ref) = @_;
    my $Keyword = "DTCM";
    return $MEMORYSetting_href->{$Keyword}->[1];
}
sub GenDUMMY_END # Fill in RegionList.csv
{
    my ($MEMORYSetting_href, $RegionList_aref, $Index_ref) = @_;
    return &GetAddress_FromBottomToTop_OnRAM($MEMORYSetting_href, $RegionList_aref, $Index_ref,
                                           "DSP_RX", "DUMMY_END");
}
sub GenBOOT_CERT_BASE
{
    my ($MEMORYSetting_href, $RegionList_aref, $Index_ref) = @_;
    return &GetAddress_FromBottomToTop_OnRAM($MEMORYSetting_href, $RegionList_aref, $Index_ref,
                                           "DSP_RX", "BOOT_CERT");
}

sub GetReservedSize_FromBottomToTop_OnRAM
{
    my ($MEMORYSetting_href, $RegionList_aref, $Index_ref, $strBottom, $strTop) = @_;
    my @TopDownRegions;
    my $NameIndex = $Index_ref->{Name};
    my $MaxSizeIndex = $Index_ref->{MaxSize};
    my $bStart = 0;
    
    foreach my $region (@$RegionList_aref)
    {
        if($region->[$NameIndex] =~/$strTop/i)
        {
            $bStart=1;
        }
        elsif($region->[$NameIndex] =~/$strBottom/i)
        {
            push(@TopDownRegions, $region);
            $bStart=0;
        }
        if($bStart ==1)
        {
            push(@TopDownRegions, $region);
        }
    }
    my $nReservedSize;
    foreach my $item (@TopDownRegions)
    {
        my $strSize = $item->[$MaxSizeIndex];
        if($item->[$MaxSizeIndex] =~/\[(\S+)\]/)
        {
            no strict 'refs';
            my $func = "Gen".$1;
            $strSize = &{$func}($MEMORYSetting_href, $RegionList_aref, $Index_ref) if (exists &{$func})
              or &sysUtil::sysgen_die("$func() doesn't exists!", __FILE__, __LINE__);
            
        }
        $nReservedSize += hex($strSize);
    }
    return $nReservedSize;
}
sub GetAddress_FromBottomToTop_OnRAM
{
    my ($MEMORYSetting_href, $RegionList_aref, $Index_ref, $strBottom, $strTop) = @_;
    my $nReservedSize = &GetReservedSize_FromBottomToTop_OnRAM($MEMORYSetting_href, $RegionList_aref, $Index_ref, $strBottom, $strTop);
    my $nRamSize = hex($MEMORYSetting_href->{RAM}->[0]) + hex($MEMORYSetting_href->{RAM}->[1]);
    my $nBase = $nRamSize - $nReservedSize;
    my $strTopRegionName;
    my $NameIndex = $Index_ref->{Name};
    foreach my $item (@$RegionList_aref)
    {
        if($item->[$NameIndex] =~ /$strTop/i)
        {
            $strTopRegionName = $item->[$NameIndex];
            last;
        }
    }
        $nBase = $strTopRegionName =~ /cached/i ? (sysUtil::GetCacheablePrefix($g_bb) | $nBase) : $nBase;
    return &CommonUtil::Dec2Hex($nBase);
}
sub GenTX_BASE # Fill in RegionList.csv
{
    my ($MEMORYSetting_href, $RegionList_aref, $Index_ref) = @_;
    my $nRamSize = hex($MEMORYSetting_href->{RAM}->[0]) + hex($MEMORYSetting_href->{RAM}->[1]);
    my ($nTXLength,$nRXLength) = &sysUtil::DSPTXRX_query_length($g_bb, $g_MakeFile_ref->{mode});
    return &CommonUtil::Dec2Hex($nRamSize - $nRXLength - $nTXLength);
}
sub GenRX_BASE # Fill in RegionList.csv
{
    my ($MEMORYSetting_href, $RegionList_aref, $Index_ref) = @_;
    my $nRamSize = hex($MEMORYSetting_href->{RAM}->[0]) + hex($MEMORYSetting_href->{RAM}->[1]);
    my ($nTXLength,$nRXLength) = &sysUtil::DSPTXRX_query_length($g_bb, $g_MakeFile_ref->{mode});
    return &CommonUtil::Dec2Hex($nRamSize - $nRXLength);
}
sub GenTX_SIZE # Fill in RegionList.csv
{
    my ($MEMORYSetting_href, $RegionList_aref, $Index_ref) = @_;
    my ($nTXLength,$nRXLength) = &sysUtil::DSPTXRX_query_length($g_bb, $g_MakeFile_ref->{mode});
    return &CommonUtil::Dec2Hex($nTXLength);
}
sub GenRX_SIZE # Fill in RegionList.csv
{
    my ($MEMORYSetting_href, $RegionList_aref, $Index_ref) = @_;
    my ($nTXLength,$nRXLength) = &sysUtil::DSPTXRX_query_length($g_bb, $g_MakeFile_ref->{mode});
    return &CommonUtil::Dec2Hex($nRXLength);
}

###################################################################################################
# 
#  MemorySetting By chip
#
###################################################################################################
sub MT6280_MemorySetting  # Called by CollectMemorySetting($Setting_href)
{
    my ($Setting_href) = @_;
    my $nROMSize = GetPredefinedValue($Setting_href, "RAM_BASE", "ROM_LEN", 0x600000);
    my $nTotalSize = $g_nRamSize;
    if(&FileInfo::is_RNDISDongle())
    {  
        $nTotalSize = 0x1200000; #18MB # Requested by CCCI's constraints[CR: MOLY00005511]
    }
    elsif(&FileInfo::is_HostedDongle())
    {
        $nTotalSize = 0x1200000; #18MB
    }
    SetExistentValueByDefault($Setting_href, "ROM_LEN", $nROMSize);
    SetExistentValueByDefault($Setting_href, "RAM_BASE", $nROMSize);
    SetExistentValueByDefault($Setting_href, "RAM_LEN", ($nTotalSize - $nROMSize));
}
sub MT6575_MemorySetting  # Called by CollectMemorySetting($Setting_href)
{
    my ($Setting_href) = @_;
    my ($fbase, $flength, $rambase, $rs);
    if(&FileInfo::find("MODE", 'GPRS'))
    {
        $fbase                = 0x0;
        $flength              = 0x400000;
        $rs                   = 0x300000;  # 0x700000-0x400000
    }
    else
    {
        $fbase                = 0x0;
        $flength              = 0x600000;
        $rs                   = 0xD00000;  # 0x1300000-0x600000
    }
    SetExistentValueByDefault($Setting_href, "ROM_BASE", $fbase);
    SetExistentValueByDefault($Setting_href, "ROM_LEN",  $flength);
    SetExistentValueByDefault($Setting_href, "RAM_BASE", (sysUtil::GetNonCacheablePrefix($g_bb) | $flength));
    SetExistentValueByDefault($Setting_href, "RAM_LEN",  $rs);
}

sub MT6589_MemorySetting
{#smart phone doesn't use $g_nRamSize
    my ($Setting_href) = @_;
    my ($nTotalSize, $nROMSize) = (0, 0); # RamSize means MD available space
    if(&FileInfo::find("MODE", "GPRS"))
    {
        $nTotalSize = ($g_bb eq "MT6589_MD1") ?  0xA00000 : 0x800000; #MT6589_MD1_GPRS(10MB), MT6589_MD2_GPRS(8MB)
        $nROMSize = ($g_bb eq "MT6589_MD1") ?  0x400000 : 0x400000; #MT6589_MD1_GPRS(4MB), MT6589_MD2_GPRS(4MB)
    }
    else
    {
        $nTotalSize = ($g_bb eq "MT6589_MD1") ?  0x1600000 : 0x1500000; #MT6589_MD1_HSPA(22MB), MT6589_MD2_TDD128HSPA(21MB)
        $nROMSize = ($g_bb eq "MT6589_MD1") ?  0x700000 : 0x600000; #MT6589_MD1_HSPA(7MB), MT6589_MD2_TDD128HSPA(6MB)
    }
    &sysUtil::sysgen_die("RamSize($nTotalSize) can't be 0 in MT6589_MemorySetting()!", __FILE__, __LINE__) 
        if(0==$nTotalSize);
    $nROMSize = GetPredefinedValue($Setting_href, "RAM_BASE", "ROM_LEN", $nROMSize);
    SetExistentValueByDefault($Setting_href, "ROM_LEN",  $nROMSize);
    SetExistentValueByDefault($Setting_href, "RAM_BASE", (sysUtil::GetNonCacheablePrefix($g_bb) | $nROMSize));
    SetExistentValueByDefault($Setting_href, "RAM_LEN",  ($nTotalSize - $nROMSize));
}
sub MT6572_MemorySetting
{#smart phone doesn't use $g_nRamSize
    my ($Setting_href) = @_;
    my ($nTotalSize, $nROMSize) = (0, 0); # RamSize means MD available space
    
    $nROMSize =    0x600000; # 6 MB
    $nTotalSize = 0x1200000; # 18 MB
        
    &sysUtil::sysgen_die("RamSize($nTotalSize) can't be 0 in MT6589_MemorySetting()!", __FILE__, __LINE__) 
        if(0==$nTotalSize);
    $nROMSize = GetPredefinedValue($Setting_href, "RAM_BASE", "ROM_LEN", $nROMSize);
    SetExistentValueByDefault($Setting_href, "ROM_LEN",  $nROMSize);
    SetExistentValueByDefault($Setting_href, "RAM_BASE", (sysUtil::GetNonCacheablePrefix($g_bb) | $nROMSize));
    SetExistentValueByDefault($Setting_href, "RAM_LEN",  ($nTotalSize - $nROMSize));
}

sub Default_MemorySetting
{
    my ($Setting_href) = @_;
    my ($nTotalSize, $nROMSize) = (0x1600000, 0x500000); #22MB, 5MB
    $nROMSize = GetPredefinedValue($Setting_href, "RAM_BASE", "ROM_LEN", $nROMSize);
    SetExistentValueByDefault($Setting_href, "ROM_LEN",  $nROMSize);
    SetExistentValueByDefault($Setting_href, "RAM_BASE", (sysUtil::GetNonCacheablePrefix($g_bb) | $nROMSize));
    SetExistentValueByDefault($Setting_href, "RAM_LEN",  ($nTotalSize - $nROMSize));    
}
sub MT6592_MemorySetting
{
    my ($Setting_href) = @_;
    Default_MemorySetting($Setting_href);
    my $nTotalSize= hex($Setting_href->{"ROM_LEN"})+hex($Setting_href->{"RAM_LEN"});
    &sysUtil::sysgen_die("TotalMDSize($nTotalSize) exceeds AP mpu setting(22MB)!", __FILE__, __LINE__) 
        if($nTotalSize>0x1600000);
}
sub MT6580_MemorySetting
{ # ref MT6589_MD1 design
    my ($Setting_href) = @_;
    my ($nTotalSize, $nROMSize) = (0x1600000, 0x700000); #22MB, 7MB
    $nROMSize = GetPredefinedValue($Setting_href, "RAM_BASE", "ROM_LEN", $nROMSize);
    SetExistentValueByDefault($Setting_href, "ROM_LEN",  $nROMSize);
    SetExistentValueByDefault($Setting_href, "RAM_BASE", (sysUtil::GetNonCacheablePrefix($g_bb) | $nROMSize));
    SetExistentValueByDefault($Setting_href, "RAM_LEN",  ($nTotalSize - $nROMSize));    
    
    $nTotalSize= hex($Setting_href->{"ROM_LEN"})+hex($Setting_href->{"RAM_LEN"});
    &sysUtil::sysgen_die("TotalMDSize($nTotalSize) exceeds AP mpu setting(22MB)!", __FILE__, __LINE__) 
        if($nTotalSize>0x1600000);
}
sub MT6571_MemorySetting
{
    my ($Setting_href) = @_;
    Default_MemorySetting($Setting_href);
    my $nTotalSize= hex($Setting_href->{"ROM_LEN"})+hex($Setting_href->{"RAM_LEN"});
    &sysUtil::sysgen_die("TotalMDSize($nTotalSize) exceeds AP mpu setting(22MB)!", __FILE__, __LINE__) 
        if($nTotalSize>0x1600000);
}
sub SetExistentValueByDefault
{
    my ($Setting_href, $strKey, $nValue) = @_;
    $Setting_href->{$strKey}  = (defined $Setting_href->{$strKey}) ? 
                                         $Setting_href->{$strKey} : CommonUtil::Dec2Hex($nValue);
}
sub GetPredefinedValue
{   # to collocate with AAPMC
    my ($Setting_href, $strFirst, $strSecond, $nDefaultValue) = @_;
    my $nValue = $nDefaultValue;
    if(defined $Setting_href->{$strFirst}) #1st Priority
    {
        $nValue = hex($Setting_href->{$strFirst});
    }
    elsif(defined $Setting_href->{$strSecond}) #2nd Priority
    {
        $nValue = hex($Setting_href->{$strSecond});
    }
    return $nValue;
    
}
