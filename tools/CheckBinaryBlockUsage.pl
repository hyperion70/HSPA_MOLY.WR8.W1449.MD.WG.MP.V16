#!/usr/bin/perl
#
#  Copyright Statement:
#  --------------------
#  This software is protected by Copyright and the information contained
#  herein is confidential. The software may not be copied and the information
#  contained herein may not be used or disclosed except with the written
#  permission of MediaTek Inc. (C) 2008
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
#
#*****************************************************************************
#*
#* Filename:
#* ---------
#*   CheckBinaryBlockUsage.pl
#*
#* Project:
#* --------
#*   Maui_Software
#*
#* Description:
#* ------------
#*   This script will check if code ROM size is enough for all binaries.
#*
#*------------------------------------------------------------------------------
#* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
#*============================================================================
#****************************************************************************/

#****************************************************************************
# Usage
#****************************************************************************
BEGIN { push @INC, '.\\tools\\' }  # add additional library path             
use Getopt::Std;
use POSIX;

sub Usage {
  print "perl CheckBinaryBlockUsage.pl ~flash_cfg_tmp.c <BIN_FILE_PATH> <NEED_BUILD_BOOTLOADER_flag> <FOTA_ENABLE_flag>\n";
  exit(1);
}

use File::stat;
use File::Basename;
use Math::BigInt;

#****************************************************************************
# parsing command arguments
#****************************************************************************
$DebugPrint = 1;
while ($#ARGV != -1) {
  if ($ARGV[0] =~ /-h/i) {
    &Usage;
  } elsif ($#ARGV == 7) {
    $FLASH_CFG = $ARGV[0];
    (!-e $FLASH_CFG) && die "$FLASH_CFG does NOT EXIST!\n";
    $binary_path = $ARGV[1];
    $NEED_BUILD_BOOTLOADER = $ARGV[2];
    $bootloader_path = $ARGV[3];
    $bootloader_ext_path = $ARGV[4];
    $platform = $ARGV[5];
    $str_BB_path    = $ARGV[6];
     $THEMF= $ARGV[7];
    last;
  } else {
  print "test $#ARGV\n";
    &Usage;
  }
}

print "Running tools\\CheckBinaryBlockUsage.pl ....\n";

$THEMF                    =~ s/^.\\|^\\//;

my %MAKEFILE_OPTIONS;

&Parse_Makefile($THEMF,\%MAKEFILE_OPTIONS);

if (-d $binary_path) {
  if (opendir(SUBDIRS, $binary_path)) {
    @childdirs = sort readdir(SUBDIRS);
    closedir(SUBDIRS);
  } else {
    warn "Could not open $binary_path\n";
    next;
  }
  foreach $dir (@childdirs) {
    next if ($dir eq ".");
    next if ($dir eq "..");
    $d = $binary_path . "\\". $dir;
    if (-e $d) {
    	if (($d !~ /\.(bin|txt)$/i) && ($d !~ /\SECURE_RO/i) && ($d !~ /\EXT_BOOTLOADER/i)){
        push(@binary, $d);
    	}
  	}
  }
}

if (uc($NEED_BUILD_BOOTLOADER) eq "TRUE") {
  if (-e "$bootloader_path") {
    push(@binary, $bootloader_path);
  } else {
    die "$bootloader_path does not exist!\n";
  }
   if (-e "$bootloader_ext_path") {
    push(@binary, $bootloader_ext_path);
  } else {
    die "$bootloader_ext_path does not exist!\n";
  }
}

#if (uc($FOTA_ENABLE) ne "NONE") {
#  if (-e "$fota_path") {
#    push(@binary, $fota_path);
#  } else {
#    die "Error:$fota_path does not exist!\n";
#  }
#}
print "@binary\n";
#}
# Get code rom size from ~flash_cfg_tmp.c
open (FLASH_CFG, "<$FLASH_CFG") or die "Cannot open $FLASH_CFG\n";
    
while ($line = <FLASH_CFG>)
{
	$backup = $/; undef $/;
  $reading = <FLASH_CFG>;
  $/ = $backup;
}
close FLASH_CFG;  #End of open (FLASH_CFG, "<$FLASH_CFG")

my ($addr, $len, $total_block, $bad_block);
if ($reading =~ /int\s+flash_base_address\s*=\s*(.*);/)
{
  $addr = `perl -e "print ($1)" 2>&1`;
  $base_block = $addr / (128*1024);
}
if ($reading =~ /int\s+allocated_fat_space\s*=\s*(.*);/)
{
  $len = `perl -e "print ($1)" 2>&1`;
}

$total_block = 0;
foreach $file (@binary) {
  
  $block = ceil(&get_size($file)/(128*1024));
  $total_block+=$block;
  printf("\t[i]\$file size = %30d KB, block # = %d\n", &get_size($file)/1024, $block) if $DebugPrint == 1;
}
 my $FLASHOPTGENH_HANDLE = $str_BB_path . "\/custom_flash.h";
my $NAND_flash_size;
my $bad_block_size;
print "makefile option : $MAKEFILE_OPTIONS{'enlarge_code_bbm'}\n";
if($MAKEFILE_OPTIONS{'enlarge_code_bbm'} eq 'TRUE')
{
     open (FLASHOPTGENH_HANDLE, "<$FLASHOPTGENH_HANDLE") or die "Cannot open $FLASHOPTGENH_HANDLE\n";
  while (<FLASHOPTGENH_HANDLE>) {
        if (/^#define NOR_FLASH_SIZE\s*(\w*)/)
        {
            $NAND_flash_size = $1;
        }
    }
    print "nand flash size:$NAND_flash_size\n";
    $bad_block_size = ceil(hex($NAND_flash_size)/(128*1024));
$bad_block = ceil($bad_block_size * (0.02));
print "\t[i]\$bad_block # =$bad_block \n" ;

}
else
{
$bad_block = ceil($total_block * (0.02));
print "\t[i]\$bad_block # =$bad_block \n" if $DebugPrint == 1;
}



# Add 7 blocks for image list
$total_block = $total_block + 7;

$total_block = $total_block + $bad_block;

if ($total_block > $base_block) 
{
  print "Error: BIN ($total_block blocks) and FAT ($base_block blocks) on NAND Flash overlap risk were detected.\n";
  print "Please decrease ROM sizes by reducing features or adjust custom_MemoryDevice.h configuration.\n";
  exit(1);
}
else
{
    print "BIN size = ($total_block blocks) on NAND Flash.\n";
}    
exit;  

#if ($query_mode == 0) {
  open (FILE_HANDLE, "<$themf") or die "cannot open $themf\n";
  while (<FILE_HANDLE>) {
    if (/^(\S+)\s*=\s*(\S+)/) {
      $keyname = lc($1);
      defined($${keyname}) && warn "$1 redefined in $themf!\n";
      $${keyname} = uc($2);
    }
  }

  if ($secure_support eq "TRUE") {
    $sec_support = 1;
    ($secure_version !~ /\d{1,4}/) && die "SECURE_VERSION: $secure_version should be a integer no longer than 4 digits!\n";
    ($secure_jtag_enable !~ /(TRUE|FALSE)/) && die "SECURE_JTAG_ENABLE: $secure_jtag_enable should be TRUE or FALSE!\n";
    $secure_jtag_enable = ($secure_jtag_enable =~ /TRUE/)? 1 : 0;
    (length($secure_custom_name) > 31) && die "SECURE_CUSTOM_NAME: $secure_custom_name should NOT exceed 31 bytes!\n";
  }
    
my %BBtbl_EMI = 
   (
      'MT6225'       => 1,
      'MT6228'       => 1,
      'MT6229'       => 2,
      'MT6230'       => 2,
      'MT6235'       => 3,
      'MT6235B'      => 3,
      'MT6238'       => 3,
      'MT6239'       => 3,
      'MT6268A'      => 3,
   );
  if (($nand_flash_booting ne "NONE") || (exists $BBtbl_EMI{$platform}))
  {
      open (CUSTOM_EMI_H, "<$memory_cfg") or die "cannot open $memory_cfg\n";
      $backup = $/; undef $/;
      $reading = <CUSTOM_EMI_H>;
      $/ = $backup;
      close CUSTOM_EMI_H;  #End of open (FLASH_CFG, "<$FLASH_CFG")
       
      if  ($reading =~ /\n\s*#define\s+DRAM_CS\s+/gs
       and $reading =~ /\n\s*#define\s+DRAM_SIZE\s+/gs)
      {
         $needEMIInfo = 1;
      }
  }
#}
#****************************************************************************
# parsing flash configuration from a file or a string
#****************************************************************************
my $full_hex_str = '';
my $full_emi_str; 

if ($FLASH_CFG =~ /custom_MemoryDevice\.h/i)
{
# parsing flash configuration from custom_MemoryDevice.h (NAND_FLASH_BOOTING)

  open (FLASH_CFG, "<$FLASH_CFG") or die "cannot open $FLASH_CFG\n";
    
  while ($line = <FLASH_CFG>)
  {
      if ($line =~ /^\s*#define\s+NAND_BOOTING_FLASH_BASE_ADDRESS\s+(0x[0-9A-Fa-f]+)/)
      {
         $addr = hex $1;
      }
      if ($line =~ /^\s*#define\s+NAND_BOOTING_ALLOCATED_FAT_SPACE\s+(0x[0-9A-Fa-f]+)/)
      {
         $len = hex $1;
      }
  }
  close FLASH_CFG;  #End of open (FLASH_CFG, "<$FLASH_CFG")
    
  $hex_str = sprintf("%02X%04X%04X%04X%04X%08X%08X", 1 , 0, 0, 0, 0, $addr, $len);
  $full_hex_str .= $hex_str;

  print "[Flash Cfg 0] $hex_str\n" if $DebugPrint == 1;

} 
elsif ($FLASH_CFG =~ /flash_opt\.h/i)
{
# parsing flash configuration from flash_opt.h (NOR-XIP)

  open (FLASH_CFG, "<$FLASH_CFG") or die "cannot open $FLASH_CFG\n";

  $backup = $/; undef $/;
  $reading = <FLASH_CFG>;
  $/ = $backup;

  close FLASH_CFG;  #End of open (FLASH_CFG, "<$FLASH_CFG")

  #// FLASH_BASE_ADDRESS_FOR_SCATTER 0x01C00000
  #// ALLOCATED_FAT_SPACE_FOR_SCATTER 0x00400000
  if ($reading =~ /\/\/\s+FLASH_BASE_ADDRESS_FOR_SCATTER\s+(0x[0-9A-Fa-f]+)/gs)
  {
      $addr = hex $1;
  }
  if ($reading =~ /\/\/\s+ALLOCATED_FAT_SPACE_FOR_SCATTER\s+(0x[0-9A-Fa-f]+)/gs)
  {
      $len = hex $1;
  }

  if (($system_drive_on_nand eq "TRUE") && ($nand_flash_booting eq "NONE"))
  {
      $addr = 0x0;
      $len = 0x0;
  }

  $hex_str = sprintf("%02X%04X%04X%04X%04X%08X%08X", 1, 0, 0, 0, 0, $addr, $len);
  $full_hex_str .= $hex_str;
}
elsif ($FLASH_CFG =~ /flash_cfg_tmp\.c/i)
{
  open (FLASH_CFG, "<$FLASH_CFG") or die "cannot open $FLASH_CFG\n";

  $backup = $/; undef $/;
  $reading = <FLASH_CFG>;
  $/ = $backup;

  close FLASH_CFG;  #End of open (FLASH_CFG, "<$FLASH_CFG")
  
  #int flash_base_address =  0x00E00000 ;
  #int flash_base_address =  ( (0xD00000)  + 0x00100000) ;
  #int allocated_fat_space =  0x00200000 ;
  #int allocated_fat_space =  ( (0x300000)  - 0x00100000) ;
  if ($reading =~ /int\s+flash_base_address\s*=\s*(.*);/)
  {
  	$addr = `perl -e "print ($1)" 2>&1`;
  }
  if ($reading =~ /int\s+allocated_fat_space\s*=\s*(.*);/)
  {
  	$len = `perl -e "print ($1)" 2>&1`;
  }
  $hex_str = sprintf("%02X%04X%04X%04X%04X%08X%08X", 1, 0, 0, 0, 0, $addr, $len);
  $full_hex_str .= $hex_str;
}
elsif ($FLASH_CFG =~ /\.[ch]/i)
{
    die "Not Support $FLASH_CFG parsing Yet";
}
else
{
# parsing flash configuration from a string
    $full_hex_str = $FLASH_CFG;
    $full_emi_str = $EMI_INFO;
    if ((length($full_emi_str) == 0)
     && (($platform eq "MT6228") || ($platform eq "MT6229") || ($platform eq "MT6225") || ($platform eq "MT6230"))
    ) {
        die "Cannot get EMI_INFO.";
    }
    print "full_hex_str=$full_hex_str\n" if $DebugPrint == 1;
    
    print "[Flash Cfg 0] $FLASH_CFG\n" if $DebugPrint == 1;
}

######################################
#Get register values from custom_MEI.h
######################################
## Check DRAM setting in custom_EMI.h 

#if ($needEMIInfo == 1 and not defined $full_emi_str)
#{
#     $full_emi_str = getRegisterAddress($platform, $memory_cfg);
#}
#elsif (not defined $full_emi_str)
#{
#     $full_emi_str = '';
#}

##################################################################################################################
    
######################################
# Binary String 
######################################
$flash_len = length($full_hex_str);
if ( ($flash_len == 2)
  || ((($flash_len-34)%32) !=0)
  || ($flash_len > 34+5*32) )
{
    die "The length of $full_hex_str ($flash_len) should be 34+32n. (5>=n>=0)\n";
}
$flash_device_count = hex(substr($full_hex_str, 0, 2));

if ((($flash_len-2)/32) != $flash_device_count)
{
    die "($flash_len-2)/32 should be $flash_device_count\n";
}


#****************************************************************************
# in query, output @cfg_list with hex string
#****************************************************************************
if ($query_mode == 1) {
  print "FLASH_CFG = $full_hex_str\n";
  print "EMI_INFO = $full_emi_str\n";
  exit(0);
}

#****************************************************************************
# Parse symbol file
#****************************************************************************
(open(LOGF, "<$symFile")) || die "$symFile can NOT been opened\n";
my %SYM_TBL = 
   (
      'INT_Vectors'      => undef,
      'IMG_INFO'         => undef,
      'EMI_INFO'         => undef,
      'g_CustParaCfg'    => undef,
      'g_secinfo'        => undef,
      'g_secinfo_tail'   => undef,
   );

my %SYM_LEN = 
   (
      'g_CustParaCfg'    => undef,
   );

my $prev_symbol;
while(<LOGF>)
{
   # 0x00000000 A INT_Vectors
   if (/^0x(\S+)\s+\w\s+(\S+)$/)
   {
      if (exists $SYM_TBL{$2})
      {
         $SYM_TBL{$2} = hex($1);
      }
      

      if (exists $SYM_LEN{$prev_symbol})
      {
         $SYM_LEN{$prev_symbol} = hex($1) - $SYM_TBL{$prev_symbol};
      }
      $prev_symbol = $2;
   }
}
close(LOGF);

#****************************************************************************
# Validation symbol and feature combination
#****************************************************************************
die "Could not find IMG_INFO in $symFile\n" unless defined $SYM_TBL{'IMG_INFO'};
if ($sec_support)
{
   die "Could not find g_secinfo in $symFile\n" unless defined $SYM_TBL{'g_secinfo'};
}

#****************************************************************************
# Setup BINARY File Offset
#****************************************************************************
my %ROM_POS = 
   (
      'IMG_INFO'         => undef,
      'EMI_INFO'         => undef,
      'g_CustParaCfg'    => undef,
      'g_secinfo'        => undef,
      'g_secinfo_tail'   => undef,
   );
map { $ROM_POS{$_} = $SYM_TBL{$_} - $SYM_TBL{'INT_Vectors'}; } keys %ROM_POS;


#****************************************************************************
# set ROMINFO version
#****************************************************************************
if ((($system_drive_on_nand eq "TRUE") && ($nand_flash_booting eq "NONE")))
{
        $rom_info_ver = "MTK_ROMINFO_v05";
}

#****************************************************************************
# append information to the file
#****************************************************************************
open (FILE, "+<$file") or die "cannot open $file\n";
binmode(FILE);

seek(FILE, $ROM_POS{'IMG_INFO'}, 0);

    seek(FILE, 16, 1);


    print FILE "$bin_name";
    print FILE "\0" x (128 -length($bin_name));
    print FILE "$verno";
    print FILE "\0" x (64 -length($verno));

if ($FLASH_CFG =~ /custom_MemoryDevice\.h/i)
{
    print FILE pack("H4", "ffff");
} else {
    print FILE pack("H4", "0000");
}

    $flash_len = length($full_hex_str);
    print FILE pack("v1", $flash_device_count);

for ($i=0; $i<$flash_device_count; $i++)
{
    $menuID = hex(substr($full_hex_str, 2+32*$i, 4));
    $devID = hex(substr($full_hex_str, 6+32*$i, 4));
    $extID1 = hex(substr($full_hex_str, 10+32*$i, 4));
    $extID2 = hex(substr($full_hex_str, 14+32*$i, 4));
    $fatAddr = hex(substr($full_hex_str, 18+32*$i, 8));
    $fatLen = hex(substr($full_hex_str, 26+32*$i, 8));
    print FILE pack("v1", $menuID);
    print FILE pack("v1", $devID);
    print FILE pack("v1", $extID1);
    print FILE pack("v1", $extID2);
    print FILE pack("V1", $fatAddr);
    print FILE pack("V1", $fatLen);
}

if ($cust_para_support eq "TRUE")
{
    seek(FILE, 12+(6-$flash_device_count)*16, 1);
    print FILE pack("V1", $SYM_TBL{'g_CustParaCfg'});
    print FILE pack("V1", $SYM_LEN{'g_CustParaCfg'});
}

if ($sec_support == 1)
{
  #Parse scatter file to get SECINFO_TAIL address.
  open(scat,"$scat") || die "Cannot open $sact. Error:$!\n";
  my $line = 0;
  my $rom_base = "";
  my $rom_line = 0;
  my $secondary_rom_base = "0";
  my $secondary_rom_line = 0;
  my $third_rom_base = "0";
  my $third_rom_line = 0;
  my $secinfo_tail_line = 0;
  my $secinfo_tail_base = "0";
  my $multiROM = "";
  while(<scat>){
    $line++;

    if(index($_,"ROM") == 0){
      $rom_line = $line;
      if($_ =~ /[\w]+[\s](.+?)[\s]/ && $1 ne "+0x0"){
        $rom_base = $1;
        # Get ROM binary length.
        if ($file =~ /(.+)\\ROM/) {
          $bin_path = $1;
          $rom_length = get_length($file);
        }
      }
    } elsif(index($_,"SECONDARY_ROM") == 0){
      $secondary_rom_line = $line;
      if($_ =~ /[\w]+[\s](.+?)[\s]/){
        $secondary_rom_base = $1;
        if ($secondary_rom_base =~ /\+(.+)/) {
          $secondary_rom_offset = hex $1;
          $secondary_rom_base = $rom_length + $secondary_rom_offset;
          $secondary_rom_length = get_length("$bin_path\\SECONDARY_ROM");
        }
      }
    } elsif(index($_,"THIRD_ROM") == 0){
      $third_rom_line = $line;
      if($_ =~ /[\w]+[\s](.+?)[\s]/){
        $third_rom_base = $1;
        if ($third_rom_base =~ /\+(.+)/) {
          $third_rom_offset = $1;
          $third_rom_base = $secondary_rom_length + $third_rom_offset;
        }
      }
    } elsif ($_ =~ /^[a-zA-Z].+/) {
      $third_rom_line = $line;
      if($_ =~ /[\w]+[\s](.+?)[\s]/){
        $third_rom_base = $1;
        if ($third_rom_base =~ /\+(.+)/) {
          $third_rom_offset = $1;
          $third_rom_base = $secondary_rom_length + $third_rom_offset;
        }
      }
    } elsif(index($_,"SECINFO_TAIL") >= 0){
      $secinfo_tail_line = $line;
    }
  }
  close(scat);
 
  if($secondary_rom_line == 0) {
    $secinfo_tail_base = $rom_base;
  } elsif($secondary_rom_line > $secinfo_tail_line){ #SECINFO_TAIL locates at ROM
    $secinfo_tail_base = $rom_base;
  } elsif(($secinfo_tail_line > $secondary_rom_line) && ($third_rom_line > $secinfo_tail_line)){#SECINFO_TAIL locates at SECONDARY_ROM
    $secinfo_tail_base = $secondary_rom_base;
    $multiROM = "SECONDARY";
  } elsif(($secinfo_tail_line > $third_rom_line) && (third_rom_line != "0")) {#SECINFO_TAIL locates at THIRD_ROM
    $secinfo_tail_base = $third_rom_base;
    $multiROM = "THIRD";
  }

#************************************************************
#Start to write secinfo to ROM
#************************************************************	
    seek(FILE, $ROM_POS{'g_secinfo'} + 20, 0);
    print FILE pack("V1", $secure_jtag_enable);
    print FILE "$secure_custom_name";
    print FILE "\0" x (32 -length($secure_custom_name));
    seek(FILE, $ROM_POS{'g_secinfo'} + 60, 0);
    print FILE pack("V1", $secure_version);
    
    if ($secinfo_tail_base =~ /0x/i) {
      $secinfo_tail_base = hex($secinfo_tail_base);
    }

    # Verify the address of g_secinfo_tail
    seek(FILE, $ROM_POS{'g_secinfo'} + 80, 0);
    my $addr_secinfo_tail;
    die "cannot read $file\n" unless (my $chnum = (read FILE, $addr_secinfo_tail, 4));
    $addr_secinfo_tail = unpack ("V1",$addr_secinfo_tail);
    die "secinfo tail don't match\n" if ($SYM_TBL{'g_secinfo_tail'} != $addr_secinfo_tail);
        
    if(length($multiROM) > 0){
      if($multiROM eq "SECONDARY"){
        $file =~ s/ROM/SECONDARY_ROM/;
        open(multiFILE,"+<$file") || die "Cannot open $file. Error:$!\b";
      } elsif($multiROM eq "THIRD"){
        $file =~ s/ROM/THIRD_ROM/;
        open(multiFILE,"$file") || die "Cannot open $file. Error:$!\b";
      }
#      $addr_secinfo_tail = $ROM_POS{'g_secinfo_tail'} % 0x08000000;
      $addr_secinfo_tail = $ROM_POS{'g_secinfo_tail'};
      $addr_secinfo_tail = $addr_secinfo_tail - $secinfo_tail_base;
      seek(multiFILE, $addr_secinfo_tail+20, 0);
      print multiFILE pack("V1", $secure_jtag_enable);
      print multiFILE "$secure_custom_name";
      print multiFILE "\0" x (32 -length($secure_custom_name));
      seek(multiFILE, $addr_secinfo_tail+60, 0);
      print multiFILE pack("V1", $secure_version);
      close(multiFILE);
    } else {
      $addr_secinfo_tail = unpack ("V1",$addr_secinfo_tail) % 0x08000000;

      seek(FILE, $ROM_POS{'g_secinfo_tail'} + 20, 0);    
      print FILE pack("V1", $secure_jtag_enable);
      print FILE "$secure_custom_name";
      print FILE "\0" x (32 -length($secure_custom_name));
      seek(FILE, $ROM_POS{'g_secinfo_tail'} + 60, 0);
      print FILE pack("V1", $secure_version);
    }
}

if ($rom_info_ver eq "MTK_ROMINFO_v05")
{
    $cust_para_addr = hex(0);
    $cust_para_len = hex(0);
    $bit_ctrl = hex(0);

    #Read the bit_ctrl first then OR needed bit
    seek(FILE, $ROM_POS{'IMG_INFO'} + 328, 0);
    (read FILE, $bit_ctrl, 4);
    $bit_ctrl=unpack("V1",$bit_ctrl);
    
    if (($system_drive_on_nand eq "TRUE") && ($nand_flash_booting eq "NONE"))
    {
            $bit_ctrl = $bit_ctrl | 0x00000002;
    }
    
  
  
    seek(FILE, $ROM_POS{'IMG_INFO'} + 320, 0);
    print FILE pack("V1", $cust_para_addr);
      
    seek(FILE, $ROM_POS{'IMG_INFO'} + 324, 0);
    print FILE pack("V1", $cust_para_len);
  
    seek(FILE, $ROM_POS{'IMG_INFO'} + 328, 0);
    print FILE pack("V1", $bit_ctrl);
}

close FILE;

#************************************************************
#Start to write IMG_FOTA_INFO to BIN file for FOTA
#************************************************************




#*********************************************************************************
# Calculate checksum of IMG_FOTA_INFO string (Check sum of "MTK_FOTA_ROMINFO_V01")
#*********************************************************************************


#****************************************************************************
# Write Platform ID and Project ID
#****************************************************************************


#****************************************************************************
# Get array numbers
#****************************************************************************


#****************************************************************************
# Write file size of each ROM image
#****************************************************************************




#****************************************************************************
# Write XOR value of whole structure
# For image information: initial key is (0x86)
#****************************************************************************


exit 0;

#******************************************************************************
# FUNCTION
#  get_size
# DESCRIPTION
#  xxx
# PARAMETERS
#  binary path
# RETURNS
#  binary size
#******************************************************************************

sub get_size(){
  ($path) = @_;
  $rom_size = stat("$path")->size;
  return $rom_size;
}

sub Parse_Makefile
{
	#my %MAKEFILE_OPTIONS_LOCAL;
  my $keyname;
  my ($THEMF_LOCAL, $MAKEFILE_OPTIONS_LOCAL) = @_;
  
  &error_handler("$THEMF_LOCAL: NOT exist!", __FILE__, __LINE__) if (!-e $THEMF_LOCAL);

if ($THEMF_LOCAL =~ /make\\(\w+)_(\w+).mak/i) {
  $MAKEFILE_OPTIONS_LOCAL->{'MODE'} = uc($2);
}

open (FILE_HANDLE, "<$THEMF_LOCAL") or &error_handler("$THEMF_LOCAL: file error!", __FILE__, __LINE__);
while (<FILE_HANDLE>) {
  if (/^(\S+)\s*=\s*(\S+)/) {
    $keyname = lc($1);
    #print "keyname : $keyname\n";
    defined($MAKEFILE_OPTIONS_LOCAL->{$keyname}) && warn "$1 redefined in $THEMF_LOCAL!\n";
    $MAKEFILE_OPTIONS_LOCAL->{$keyname} = uc($2);
    #print "$keyname : $MAKEFILE_OPTIONS_LOCAL->{$keyname}\n";
  }
}
close (FILE_HANDLE);
#my $PLATFORM  = $MAKEFILE_OPTIONS{'platform'};
#my $MCU_CLOCK = $MAKEFILE_OPTIONS{'mcu_clock'};
#my $COMBO_MEM = $MAKEFILE_OPTIONS{'combo_memory_support'};
#print "PLATFORM=$PLATFORM, MCU_CLOCK=$MCU_CLOCK\n";
print "PLATFORM=$MAKEFILE_OPTIONS_LOCAL->{'platform'}, MCU_CLOCK=$MAKEFILE_OPTIONS_LOCAL->{'mcu_clock'}\n";
#return %MAKEFILE_OPTIONS_LOCAL;
}

sub error_handler
{
      my ($error_msg, $file, $line_no) = @_;
      
      my $final_error_msg = "EMIGEN ERROR: $error_msg at $file line $line_no\n";
      print $final_error_msg;
      die $final_error_msg;
}