#!/usr/bin/perl
#
#  Copyright Statement:
#  --------------------
#  This software is protected by Copyright and the information contained
#  herein is confidential. The software may not be copied and the information
#  contained herein may not be used or disclosed except with the written
#  permission of MediaTek Inc. (C) 2007
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
#*   build_fota_bin_for_diff.pl
#*
#* Description:
#* ------------
#*   This script can append some information to a file
#*   1. -P page_size
#*   2. -B block_size
#*   3. -I image_size
#*
#* Author:
#* ---------
#* Frank Wu
#*
#* Build Time:
#* -----------
#* 2007/05/08
#*
#*------------------------------------------------------------------------------
#* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
#*============================================================================
#****************************************************************************/

#****************************************************************************
# Usage
#****************************************************************************
sub Usage {
  print "perl build_fota_bin_for_diff.pl -output file_name -P page_size -B block_size -I image_size input_file\n";
  exit(1);
}

#****************************************************************************
# parsing command arguments
#****************************************************************************

$DebugPrint = 0;
$outputFlag = 0;
$pagesizeFlag = 0;
$blocksizeFlag = 0;
$imagesizeFlag = 0;
$PFlag = 0;
$BFlag = 0;
$IFlag = 0;
$OFlag = 0;

$outfile = "";
$pageSize = 0;
$blockSize = 0;
$imageSize = 0;
$bin_name = "";
     

while ($#ARGV != -1) {
  if ($ARGV[0] =~ /-h/i) {
    &Usage;
  } elsif ($ARGV[0] =~ /-output/i) {
    $outputFlag = 1;
  } elsif ($outputFlag == 1) {
  	$outfile = $ARGV[0];
  	$OFlag = 1;
  	$outputFlag = 0;
  } elsif ($ARGV[0] =~ /-P/i) {
  	$pagesizeFlag = 1;
  	$PFlag = 1;
  } elsif ($pagesizeFlag == 1) {
  	$pageSize = $ARGV[0];
  	$pagesizeFlag = 0;
  } elsif ($ARGV[0] =~ /-B/i) {
  	$blocksizeFlag = 1;
  	$BFlag = 1;
  } elsif ($blocksizeFlag == 1) {
  	$blockSize = $ARGV[0];
  	$blocksizeFlag = 0;
  } elsif ($ARGV[0] =~ /-I/i) {
  	$imagesizeFlag = 1;
  	$IFlag = 1;
  } elsif ($imagesizeFlag == 1) {
  	$imageSize = $ARGV[0];
  	$imagesizeFlag = 0;
  } else {
  	$bin_name = $ARGV[0];
  }
  shift(@ARGV);
}

if ($imagesizeFlag == 1) {
	print "Please specify an image size after -I argument.\n";
	exit(0);
} elsif ($blocksizeFlag == 1)  {
	print "Please specify a block size after -B argument.\n";
	exit(0);
} elsif ($pagesizeFlag == 1)  {
	print "Please specify a page size after -P argument.\n";
	exit(0);
} elsif ($outputFlag == 1) {
	print "Please specify an output file name after -output argument.\n";
	exit(0);
}
if ($OFlag == 0) {
	print "Please use -output argument to specify the output file.\n";
	exit(0);
}

(!-e $bin_name) && die "Please specify the input binary file or $bin_name does NOT EXIST!\n";
system("copy /y $bin_name $outfile > nul");

#********************************************************
#To insert 0xFF data to ($blockSize - $pageSize) address
#********************************************************
if ($pageSize =~ /^0x(\S+)/) {
	$pageSize = hex($1);
}
if ($blockSize =~ /^0x(\S+)/) {
	$blockSize = hex($1);
}

if ($pageSize != 0 && $blockSize == 0) {
	print "Page size was specified but block size was not specified.\n";
	print "Please use -B to specify the block size.\n";
	exit(0);
} elsif ($pageSize == 0 && $blockSize != 0) {
	print "Block size was specified but page size was not specified.\n";
	print "Please use -P to specify the page size.\n";
	exit(0);
}

if ($PFlag == 1 && $BFlag == 1){
	if ($blockSize - $pageSize < 0) {
		print "Block size ($blockSize bytes) should be greater or equal to page size ($pageSize bytes).\n";
		print "Please specify the block size again.\n";
		exit(0);
	} else {
		print "Insert data...\n";
		open (binFile,"+<$outfile") || die "Cannot open $outfile\n";
		$size = (stat($outfile))[7];
		binmode(binFile);
		seek(binFile, $blockSize - $pageSize, 0);
		$curpos = tell(binFile); 
		$RECSIZE = $size - tell(binFile);
		read(binFile,$BUFFER,$RECSIZE)==$RECSIZE or die "Reading: $!";
		seek(binFile, -$RECSIZE, 1);
		print binFile pack("H2","FF") x $pageSize;
		print binFile $BUFFER;
		close(binFile);
		print "Complete to insert data!\n";
	}
}

#********************************************************
#To append 0xFF data to extend binary size to $imageSize
#********************************************************

if ($imageSize =~ /^0x(\S+)/) {
	$imageSize = hex($1);
}

if ($imageSize > 0)
{
	print "Append data...\n";
	$size = (stat($outfile))[7];
	if ($size >= $imageSize) {
		print "Error! The original binary file has a bigger file size ($size bytes) than the specified image size ($imageSize bytes).\n";
		print "Please specify a new image size which is greater than the original binary file size.\n";
		exit(0);
	} else {
		open (binFile,"+<$outfile") || die "Cannot open $outfile\n";
		binmode(binFile);
		seek(binFile, $size, 0);
		print binFile pack("H2","FF") x ($imageSize - $size);
		close(binFile);
		print "Complete to append data! The binary file size is $imageSize bytes (",$imageSize/1024/1024," MB).\n";
		print "The output file is \"$outfile\".\n";
	}
} elsif ($IFlag == 1) {
	print "Please specify an image size which was greater than 0.";
	exit(0);
}
