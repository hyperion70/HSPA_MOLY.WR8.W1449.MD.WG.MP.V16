#!/usr/bin/perl -w
#
# [Author]
# yinli.liang@mediatek.com
#
# [Script Purpose]
# - An integrated script to scan sprintf/vsprintf/vsnprintf/vsscanf/sscanf variable-parameter number.
# - If the number is bigger than the setting, will build error.
#
# [USAGE]
# perl sprintf_parameter_parser.pl xxx.elf xxx.map
#
# [Revision]
# -"V0.4" 2013/05/02: <yinli.liang> replace die to warning to reduce build fail possibility
# -"V0.3" 2013/04/25: <yinli.liang> bug fix for vsprintf/vsnprintf/vsscanf
# -"V0.1" 2013/03/15: <yinli.liang> check in WR8
# -"V0.2" 2013/02/01: <yinli.liang> Beta release
# 
#

use strict;

#searching function list, will be clear and reset if found vsprintf/vsnprintf/vsscanf
#keys=func_name, value=call-times
my %interest_func_list = (
"__wrap_sprintf" => 0,
"__wrap_snprintf" => 0,
"__wrap_sscanf" => 0,
"__wrap_vsprintf" => 0,
"__wrap_vsnprintf" => 0,
"__wrap_vsscanf" => 0,
);

#need to find caller function list,will be clear if found vsprintf/vsnprintf/vsscanf
my %need_caller_func_list =(
"__wrap_vsprintf" => 0,
"__wrap_vsnprintf" => 0,
"__wrap_vsscanf" => 0,
);

#found caller function list, caller of the functions in %need_caller_func_list
my %found_caller_func_list;
my %save_found_caller_func_list;

####################below codes needed when statistic all sprintf/sscanf family usage#########
#max variable-parameter info
#keys=func_name, value=[variable-parameter number, related format-str]
#my %max_parameters_table = (
#	"__wrap_sprintf" => [0,''],
#	"__wrap_snprintf" => [0,''],
#	"__wrap_sscanf" => [0,''],
#	"__wrap_vsprintf" => [0,''],
#	"__wrap_vsnprintf" => [0,''],
#	"__wrap_vsscanf" => [0,''],
#);
####################before codes needed when statistic all sprintf/sscanf family usage########

#default setting of max-parameters
my $default_max_parameters = 8;

#max variable-parameter number scanned, this value will be used in trio.c 
#when enable max self-adjust functionality
my $max_parameters=0;

#record the caller whose variable-parameter number exceed the setting max-parameter number
#key = format-str absolute address,value = file_name|func_callee|func_caller|para_count|fmt_str
my %exceed_max_para_table;

my $err_sop_path = "./tools/C_Library/error_hanling_SOP.txt";

($ARGV[0] and $ARGV[1] and $ARGV[2] and $ARGV[3]) or die "Error: Usage: $0 <tool_path> <elf_file> <map_file> <tmp_dir>\n";
open(FILE_ELF, $ARGV[1]) || die "Error: Cannot open file $ARGV[1] : $!\n";
close(FILE_ELF);
open(FILE_MAP, $ARGV[2]) || die "Error: Cannot open file $ARGV[2] : $!\n";
close(FILE_MAP);
my $tool_path = $ARGV[0];
my $elf_file = $ARGV[1];
my $map_file = $ARGV[2];
my $tmp_dir = $ARGV[3];

#open(RECORD,">$tmp_dir/sprintf_sscanf_shrinking_record.log") || die "Error: Cannot create file $tmp_dir/sprintf_sscanf_shrinking_record.log\n";
#my $record_str;

#my $start = time;
(not system ("$tool_path -d --no-show-raw-insn $elf_file > $tmp_dir/objdump_tmp.txt")) || die "Error: Cannot generate temporary file:$tmp_dir/objdump_tmp.txt\n";
#my $objdump_time = time;


my $position=0;
my $position_beg=0;
my $position_end=0;

my $last_func_caller;
my $func_caller;
my $func_callee;
my %fmt_str_addr;

#############begin: variables used to statistic script run-time######
#my $itest_time_beg;
#my $itest_time_end;
#my $total_itest_time=0;
#my $dump_inc_data=0;
#my $total_dump_inc_data=0;
#my $total_inc_count=0;
#my $scan_time=0;
#############end: variables used to statistic script run-time########
AGAIN:
open(FILE_OBJDUMP, "$tmp_dir/objdump_tmp.txt") || die "Error: Cannot open file $tmp_dir/objdump_tmp.txt\n";
#step_1: scan to find interested function-call	
while (<FILE_OBJDUMP>)
{
	my $line = $_;
	#scan to found function call for interest function list
	#fetch caller function
	if ($line =~ m/<.*>:/)
	{
		$last_func_caller = $func_caller;
		($func_caller) = ($line =~ m/.* <(.*)>:/g);
		$position = tell(FILE_OBJDUMP);
		#print "[main]$func_caller:$position\n";
		if($position_beg)
		{
			#$itest_time_beg = time;
			my $arr_str;
			$position_end = $position;
			#print "[main]$func_caller: position_beg:$position_beg,position_eng:$position_end\n";
			seek(FILE_OBJDUMP,$position_beg,0);
			read(FILE_OBJDUMP,$arr_str,$position_end-$position_beg);
			handle_interest_funcion($last_func_caller,$arr_str,\%fmt_str_addr);
			seek(FILE_OBJDUMP,$position_end,0);
			$position_beg=0;
			$position_end=0;
			#$itest_time_end = time;
			#$total_itest_time += $itest_time_end - $itest_time_beg;
		}
	}
	elsif($position_beg)	
	{#already found interested function, just scan to found scope of the function
		next;
	}
	elsif ($line =~ m/(b|bl|blx)(eq|ne|cs|cc|mi|pl|vs|vc|hi|ls|ge|lt|gt|le){0,1}(\.\S){0,1}[ \t]+(\S*) <(\S*)>/)
	{
	  ($func_callee) = ($line =~ m/(?:b\S*|bl\S*|blx\S*)[ \t]+\S* <(\S*)>/g);
	  if($line  =~ m/__(\S+)_veneer/)              
	  {
	  	($func_callee) = ($line =~ m/__(\S+)_veneer/);
	  	#print "[main]:$func_caller:$func_callee\n";
	  }
	  elsif ($line =~ m/__(\S+)_from_[thumb|arm]/)
	  {
	  	($func_callee) = ($line =~ m/__(\S+)_from_[thumb|arm]/);
	  	#print "[main]:$func_caller:$func_callee\n";
	  }
	  #check is in %interest_func_list or not
	  if (exists $interest_func_list{$func_callee})
	  {
	  	#print "[main]:$func_caller:$func_callee:$position\n";
	  		if(!$position_beg){$position_beg = $position;}
	  }
	}	
}

#step_2: last function need to be handled
if($position_beg)
{
	seek(FILE_OBJDUMP,$position_beg,0);	
	my $arr_str;
	while (<FILE_OBJDUMP>)
	{
		$arr_str .= $_;
	}
	handle_interest_funcion($func_caller,$arr_str,\%fmt_str_addr);
	$position_beg=0;
	$position_end=0;
}

#step_3: if found func vsprintf/vsnprintf/vsscanf, rescan objdump_tmp.txt
if(scalar keys %found_caller_func_list)
{
	#foreach (keys %found_caller_func_list)
	#{print "[found_caller_func_list]:$_,$found_caller_func_list{$_}\n";}
	close(FILE_OBJDUMP);
	undef %interest_func_list;
	undef %need_caller_func_list;
	%save_found_caller_func_list = %found_caller_func_list;
	foreach (keys %found_caller_func_list)
	{
			$interest_func_list{$_} = 0;
	}

	undef %found_caller_func_list;
	goto AGAIN;
}

#$scan_time = time;
#step_4: parse collected format-str info
{
	if(scalar keys %fmt_str_addr)
	{
		#$itest_time_beg = time;
		my %fmt_str_info = &get_fmt_info(keys %fmt_str_addr);
		&parse_fmt_info(\%fmt_str_info,\%fmt_str_addr);
		#foreach my $key (keys %fmt_str_addr)
		#{
	  #  my $fmt_str_aref = $fmt_str_addr{$key};
	  #  foreach my $info (@$fmt_str_aref)
	  #  {
	  #  	print "$key => $info\n";
	  #  }
		#}
		&statistic_parameter_number(\%fmt_str_info,\%fmt_str_addr);
		#$itest_time_end = time;
		#$total_itest_time += $itest_time_end - $itest_time_beg;
	}	
}
#step_5: get the max-parameter number
#######################below codes needed when statistic all sprintf/sscanf family usage##############
#foreach (keys %max_parameters_table)
#{
#	print "key=$_,para_num=$max_parameters_table{$_}[0],fmt_str=$max_parameters_table{$_}[1]\n";
#}
######################before codes needed when statistic all sprintf/sscanf family usage##############

#step_6: construct error-handling SOP and print
my $flow_run_time = time;
if(scalar keys %exceed_max_para_table)
{
	my %func_list = &find_file_name(%exceed_max_para_table);
	
	#error message construct
	my $err_msg = &get_template_caution($default_max_parameters);
  $err_msg .= "----------------------------------------- FUNCTION LIST ------------------------------------------------\n\n";
	$err_msg .= &get_function_list(%func_list);
	$err_msg .= "---------------------------------------- ERROR HANDLING SOP --------------------------------------------\n";
	$err_msg .= &get_template_errorHandlingSOP_1($default_max_parameters);
	$err_msg .= &get_template_errorHandlingSOP_2;
	$err_msg .= "\n\n===========================================END==========================================================\n";
	
	print $err_msg;
}
else
{
	my $err_msg = "\n=======================================================================\n";
	$err_msg .= "none user was found whose variable-parameters number exceed the strict, ";
	$err_msg .= "\nwhen using sprintf/snprintf/vsprintf/vsprintf/sscanf/vsscanf\n";	
	$err_msg .= "\n===================================END===================================\n";	
	print $err_msg;
}
my $find_file_owner_time = time;
close(FILE_ELF);
close(FILE_OBJDUMP);
#close(RECORD);

if($tool_path =~ m/linux/i)
{#for linux version
	if(-e "$tmp_dir/fmt_tmp.txt")
	{(not system ("rm $tmp_dir/fmt_tmp.txt")) || die "Error: Cannot remove temporary file:$tmp_dir/fmt_tmp.txt\n";}
	if(-e "$tmp_dir/objdump_tmp.txt")
	{(not system ("rm $tmp_dir/objdump_tmp.txt")) || die "Error: Cannot remove temporary file:$tmp_dir/objdump_tmp.txt\n";}
}
else
{#for windows version
	my $win_tmp_dir = $tmp_dir;
	$win_tmp_dir =~ s/\//\\/g;
	if(-e "$win_tmp_dir\\fmt_tmp.txt")
	{(not system ("del $win_tmp_dir\\fmt_tmp.txt")) || die "Error: Cannot remove temporary file:$win_tmp_dir\\fmt_tmp.txt\n";}
	if(-e "$win_tmp_dir\\objdump_tmp.txt")
	{(not system ("del $win_tmp_dir\\objdump_tmp.txt")) || die "Error: Cannot remove temporary file:$win_tmp_dir\\objdump_tmp.txt\n";}
}
#############begin: statistic script run-time######
#my $total_run_time = time - $start;
#$find_file_owner_time -= $flow_run_time;
#$scan_time -= $objdump_time;
#$scan_time -= $total_itest_time;
#$flow_run_time -= $objdump_time;
#$objdump_time -= $start;
#print "Total run time:											  $total_run_time(s)\n";
#print "[1]objdump file:											$objdump_time(s)\n";
#print "[2]flow(logic) run time:							$flow_run_time(s)\n";
#print "	[2.1]scan time:											$scan_time(s)\n";
#print "	[2.2]handle sprintf/sscanf time:		$total_itest_time(s)\n";
#print "[3]find file-name and contruct SOP:	  $find_file_owner_time(s)\n";
#print "Objdump inc.data: $total_dump_inc_data(s), times=$total_inc_count\n";
#############end: statistic script run-time########

#step_7: exit
if($max_parameters > $default_max_parameters)
{
	exit 1;	
}
else
{
	exit 0;
}


#********************************************************************************
# subroutine:  get_r1_or_r2_addr
# input :      $idx:				 begin index of arrary, in order to speed up scanning
#							 $callee_name: callee name, one of the $interest_func_list
#              $info: 			 an array reference, saved function info
# return:      $address: 		 r1 or r2 relative-address in function
#********************************************************************************
sub get_r1_or_r2_addr
{
	my($idx,$callee_name,$info) = @_;
	my @arr_info = @$info;
	my $address;
	my ($reg_1,$reg_2);
	
	if($callee_name =~ m/sn/)
	{
		$reg_1 = "r2";
		$reg_2 = "a3";
		#print "[get_r1_or_r2_addr]found $callee_name\n";
	}
	else
	{
		$reg_1 = "r1";
		$reg_2 = "a2";
		#print "[get_r1_or_r2_addr]found $callee_name\n";
	}
	do
	{
		my $line = $arr_info[$idx];
		#print "[get_r1_or_r2_addr]$line";
		if ($line =~ m/ldr(eq|ne|cs|cc|mi|pl|vs|vc|hi|ls|ge|lt|gt|le){0,1}\s+($reg_1|$reg_2),\s+\[pc,\s+\#\d+\]/)
		{
			($address) = ($line =~ m/\s+\;\s+\({0,1}([\da-f]+)\s+<.*>\){0,1}/);
			#print "[get_r1_or_r2_addr]found_r1:$address\n";
			return $address;
		}
		elsif($line =~ m/(?:mov|add)(?:s){0,1}\s+(?:$reg_1|$reg_2),\s+(r\d|a[1-4]|v[1-8]|sb|sl|fp|ip|sp|lr){1}/)
		{
			#special case when get r1 from another register, e.g. ldr	r9, [pc, #1328]; mov	r1, r9
			#special case when get r1 from another register, e.g. ldr	r5, [pc, #264]; adds	r1, r5, #0
			$reg_1 = $1;
			$reg_2 = $reg_1;
			#print "[get_r1_or_r2_addr]found special case: $reg_1 => $`<$&>$'\n";
		}
	}while($idx--);
		
	return $address;
}

#**********************************************************************************************
# subroutine:  handle_interest_funcion
# input :      $func_caller: caller name, who calls the function in $interest_func_list 
#              $func_str: an array reference, saved function info
#							 $fmt_str_href: a hash reference, saved found fmt-str absolute address and 
#															relative callee name
# return:      none
#	note:				 if found vsprintf/vsnprintf/vsscanf, will only record in %found_caller_func_list
#**********************************************************************************************
sub handle_interest_funcion
{
	my ($func_caller,$func_str,$fmt_str_href) = @_;
	my @func_info = split /\n/,$func_str;
	my $line;
	my $count=0;
	my $func_callee;
	my %fmt_related_addr;
	foreach (@func_info)
	{
		$count++;
		$line=$_;
		# fetch callee function	and get fmt relative-addr
		if ($line =~ m/(b|bl|blx)(eq|ne|cs|cc|mi|pl|vs|vc|hi|ls|ge|lt|gt|le){0,1}(\.\S){0,1}[ \t]+(\S*) <(\S*)>/)
		{
		  ($func_callee) = ($line =~ m/(?:b\S*|bl\S*|blx\S*)[ \t]+\S* <(\S*)>/g);
		 	#print "[handle_interest_funcion]:$func_caller:$func_callee\n";
		  if($line  =~ m/__(\S+)_veneer/)              
		  {
		  	($func_callee) = ($line =~ m/__(\S+)_veneer/);
		  	#print "[handle_interest_funcion]:$func_caller:$func_callee\n";
		  }
		  elsif ($line =~ m/__(\S+)_from_[thumb|arm]/)
		  {
		  	($func_callee) = ($line =~ m/__(\S+)_from_[thumb|arm]/);
		  	#print "[handle_interest_funcion]:$func_caller:$func_callee\n";
		  }
		  #check is in %interest_func_list or not
		  if (exists $interest_func_list{$func_callee})
		  {
		  	if (exists $need_caller_func_list{$func_callee})#for vsprintf/vsnprintf/vsscanf
		  	{
		  		$found_caller_func_list{$func_caller} = $func_callee;
	  			#$record_str .= "$func_caller: $func_callee --\n";
		  	}
		  	else
		  	{
		  		#print "[handle_interest_funcion]$func_callee:$func_info[$count-1]\n";
		  		my $tmp_callee = $func_callee;
		  		if(exists $save_found_caller_func_list{$func_callee})
		  		{
		  			if($save_found_caller_func_list{$func_callee} eq '__wrap_vsnprintf')
		  			{$tmp_callee = 'vsnprintf';} #vsnprintf: fomat string is in r2
		  			else
		  			{$tmp_callee = 'vsprintf';}  #vsprintf/vsscanf: fomat string is in r1	
		  		}
		  		my $addr = &get_r1_or_r2_addr($count-1,$tmp_callee,\@func_info);
		  		#$record_str .= "$func_caller: $func_callee 0x$addr\n";
		  		if(defined ($addr) )
		  		{
	  		  	if(not exists $fmt_related_addr{$addr}) #same relative addr only need to record once
	  		  	{	
	  		  		$fmt_related_addr{$addr} = $func_callee;
	  					#print "[handle_interest_funcion]$fmt_related_addr{$addr} => $addr\n";		
	  				}
		  		}
		  		else
		  		{
		  			#die "Error: [handle_interest_funcion]not found r1 address,func_name=$func_caller, callee_name=$func_callee,line=$_\n";
		  			print "Warning: [handle_interest_funcion]not found r1 address,func_name=$func_caller, callee_name=$func_callee,line=$_\n";
			  	}
	  		}
		  }
		}		
	}
	
	if(scalar keys %fmt_related_addr)#found func in %interest_func_list
	{
		&get_fmt_absolute_addr(\%fmt_related_addr,\@func_info,$func_caller,$fmt_str_href);
	}
}

#**********************************************************************************************
# subroutine:  get_fmt_absolute_addr 
# input :      $addr: 			  a hash reference, saved relative-addr info in a function
#              $func_info: 	  an array reference, saved function info
#							 $func_caller: 	function caller name
#							 $fmt_str_href: a hash reference, saved found fmt-str absolute address and 
#															relative callee/caller name
#return: 		none, save in $fmt_str_href
#**********************************************************************************************
sub get_fmt_absolute_addr
{
	my($addr,$func_info,$func_caller,$fmt_str_href) = @_;	
	my %fmt_rel_addr = %$addr;
	my @func_info = @$func_info;
	my $len = $#func_info;
	
	foreach (reverse sort keys %fmt_rel_addr)
	{
		#print "[get_fmt_absolute_addr]$_,$fmt_rel_addr{$_}\n";
		while($len>=0)
		{
			my $line = $func_info[$len];	
			#print "[get_fmt_absolute_addr]line=$line";
			if($line =~ m/\.word/)
			{
				my($addr1,$addr2) = ($line =~ m/^\s*([\da-f]+):\s+\.word\s+([0x\da-f]+)/);
				#print "[get_fmt_absolute_addr]addr1=$addr1,addr2=$addr2\n";
				if($addr1 eq $_) 
				{
					my $temp_str = $fmt_rel_addr{$addr1} . '|' . $func_caller;	#format: func_callee|func_caller
					push @{$fmt_str_href->{$addr2}},$temp_str;
					#print "[get_fmt_absolute_addr]rel_addr=0x$addr1,keys=$addr2,value=$fmt_rel_addr{$addr2}\n";	
					#$record_str .= "0x$addr1 => $addr2\n";
					$len--;
					last;
				}
			}
			$len--;
		}
	}
}

#**********************************************************************************************
# subroutine:  statistic_parameter_number
# input :    	 $fmt_str_info: a hash reference, saved format string info
#							 $fmt_str_addr: a hash reference, saved callee/caller name and parmeter count
# return:      none, will save related value in global variable: %max_parameters_table 
#							 and %exceed_max_para_table
#**********************************************************************************************
sub statistic_parameter_number
{
	my ($fmt_str_info,$fmt_str_addr) = @_;
	my %fmt_str_info = %$fmt_str_info;
	
	foreach my $key (sort keys %fmt_str_info)
	{
		my $fmt_str = $fmt_str_info{$key};
		my $fmt_str_addr_aref = $fmt_str_addr->{$key};
		#print "[statistic_parameter_number]key=$key,fmt_str=$fmt_str\n";
		foreach my $line (@$fmt_str_addr_aref)
    {
    	my ($func_callee,$func_caller,$para_count) = ($line =~ m/(\S+)\|(\S+)\|(\S+)/);	#format: func_callee|func_caller|para_count
    	####################################below codes needed when statistic all sprintf/sscanf family usage###############
    	#if(exists $save_found_caller_func_list{$func_callee})
			#{
			#	$func_callee = $save_found_caller_func_list{$func_callee};
				#print "[statistic_parameter_number]$func_callee\n";
			#}
			#if ($para_count > $max_parameters_table{$func_callee}[0])
			#{
			#	$max_parameters_table{$func_callee} = [$para_count,$fmt_str];
			#}	
			#####################
			#in order to print log used to statistics in excel
			#$record_str .= "$key:$func_caller:$func_callee:$para_count:$fmt_str\n";
			#####################
			##easy to read
			#$record_str .= "$key:$func_caller,$func_callee,this_num:$para_count,max_until_now:$max_parameters_table{$func_callee}[0]\n=>$fmt_str\n";		
			#####################
			####################################before codes needed when statistic all sprintf/sscanf family usage###############
			if($para_count > $max_parameters)	{$max_parameters = $para_count};
			if($para_count > $default_max_parameters)
			{
				my $value = '--' .'|' .$line .'|' .$fmt_str;
				push @{$exceed_max_para_table{$key}},$value;
			}	
			else
			{
				last;	#remeber to mask when need to statistic all sprintf/sscanf family usage
			}
    }
	}
	#if($record_str)
	#{
	#	$record_str .= "\n\n";
	#	print RECORD $record_str;
	#}
}

#**********************************************************************************************
# subroutine:  get_fmt_info
# input :      @fmt_abs_arr:  an array, saved all absolute-addr info
# return:      %fmt_str:			an hash, saved format-str info relative to the absolute-addr
#**********************************************************************************************
sub get_fmt_info
{
	my @fmt_abs_addr = sort @_;
	my $beg_addr = hex $fmt_abs_addr[0];
	my $len = ((hex $fmt_abs_addr[$#fmt_abs_addr]) - $beg_addr) + 128;#assume one string max-length is 128Byte
	if($len > 64*1024) 
	{
		#max load 64K inc.data at one time, if not enough, will load more data later.
		#64k is a experimentation result in our project, under this value, just need to objdump about 5-times inc.data
		$len = 64*1024;											
	}
	my $end_addr = $beg_addr + $len;
	
	#the objdump result is arranged as 16-bytes perline, and 4-bytes is a basic-unit,
	#the length pf the ascii-character of the last-unit has some relation with the begin address.
	#e.g. if $beg_addr is 0x4a246a(0x4a246a%4=2), the objdump result will be like below:
 	#4a246a 6369 70686572 3d25752c 696e7465 6772 cipher=%u,integr
  #4a247a 6974 793d2575 00706463 705f5352 4e53 ity=%u.pdcp_SRNS
  #4a248a 5f72 656c6f00 66647063 68006564 6368 _relo.fdpch.edch
  #......
	#[6772]will be the last-group of ascii data, the length is (0x4a246a%4=2)*2,
	#and the related format-str will be at the back of [6772].
	my $offset = ($beg_addr % 4) * 2;	
	
	#print "[get_fmt_info] beg_addr = $fmt_abs_addr[0],length=$len,offset=$offset\n";	 
	#$dump_inc_data = time;
	(not system ("$tool_path -s --start-address=$beg_addr --stop-address=$end_addr $elf_file > $tmp_dir/fmt_tmp.txt")) || die "Error: Cannot generate temporary file:$tmp_dir/fmt_tmp.txt\n";
	#$total_dump_inc_data += (time - $dump_inc_data);
	#$total_inc_count++;
	open(FMT, "$tmp_dir/fmt_tmp.txt") || die "Error: Cannot open file $tmp_dir/fmt_tmp.txt\n";	
	my %fmt_str_info;
	my $need_more_data = 0;
	my $last_key = undef;
	my $cur_key = undef;
	my $cur_beg_pos = undef;
	my $new_beg_pos = undef;
	foreach my $key(@fmt_abs_addr)
	{
		my $get_fmt_str = 0;																		 #0:false,1:true
		my $full_fmt_str = undef;
		$last_key = $cur_key;
		$cur_key = hex $key;	
		#print "key=$key\n";
		if($cur_key && $last_key && ($cur_key - $last_key > 16)) #16-bytes per-line, no-need to update file-position if less than 16
		{
			$cur_beg_pos = $new_beg_pos;
			#print "[get_fmt_info]cur_key=$cur_key,last_key=$last_key,$cur_beg_pos\n";
		}
		($get_fmt_str,$full_fmt_str,$new_beg_pos) = &get_full_fmt_str($offset,$cur_key,$cur_beg_pos);
		if(1 != $get_fmt_str)
		{
			#print "[get_fmt_info]need_more_data:$cur_key\n";
			$need_more_data++;
			if($need_more_data>1)
			{
				die "Error: [get_fmt_info](address: $key)not found suitable format-str\n";
			}
			$beg_addr = $cur_key;
			$end_addr = $beg_addr + 64*1024 + 128;
			$offset = ($beg_addr % 4) * 2;
			#$dump_inc_data = time;
			close(FMT);
			(not system ("$tool_path -s --start-address=$beg_addr --stop-address=$end_addr $elf_file > $tmp_dir/fmt_tmp.txt")) || die "Error: Cannot generate temporary file:$tmp_dir/fmt_tmp.txt\n";
			#$total_dump_inc_data += (time - $dump_inc_data);
			open(FMT, "$tmp_dir/fmt_tmp.txt") || die "Error: Cannot open file $tmp_dir/fmt_tmp.txt\n";	
			#$total_inc_count++;
			$cur_key = undef;
			$cur_beg_pos = undef;
			redo;
		}	
		else
		{
			$fmt_str_info{$key} = $full_fmt_str;		
			$need_more_data = 0;
		}	
	}
	close(FMT);
	#foreach (keys %fmt_str_info)
	#{
	#	print "[get_fmt_info]key=$_ =>fmt_str=$fmt_str_info{$_}\n";	
	#}
	return %fmt_str_info;	
}


#**********************************************************************************************
# subroutine:  get_full_fmt_str
# input :      $offset:  			offset in per-line of inc.data,used to divide asc-str and fmt-str
#              $key: 	 	 			abslute address, used to find suitable begin-address in inc.data
#							 $beg_position	file position, will scan from this position
# return:      $get_fmt_str: 	true: found format-str, false: not found format-str
#							 $full_fmt_str:	found complete format-str
#**********************************************************************************************
sub get_full_fmt_str
{
		my ($offset,$key,$beg_position) = @_;
		my $found_begin_addr=0;
		my $off_in_str=0;
		my $addr=0;
		my $full_fmt_str = undef;
		my $get_fmt_str = 0; #0:false,1:true
		my $new_position = undef;		 #begin addr;
		my $first_line;
		if($beg_position)	
		{
			seek(FMT,$beg_position,0);
			#print "[get_full_fmt_str]key=$key,set file position: $beg_position\n";
		}	
		else
		{
			seek(FMT,0,0);
			#print "[get_full_fmt_str]key=$key,set file position:at the begin\n";
		}
		while (<FMT>)
		{
			chomp ;
			if (/^\s*([\da-f]+)\s+/)
			{
				#step0: find suitable begin_addr.
				my $line = $' ;
				if (!$found_begin_addr)
				{
					$addr = hex $1;
					if($key >= $addr && $key < $addr+16) 							#16-byte one-line
					{
						$off_in_str = $key  - $addr;	
						$found_begin_addr = 1;
						$first_line = 1;
						$new_position = tell(FMT);
						#print "[get_full_fmt_str]found_beg_addr: offset=$off_in_str,$_\n";
					}
					else
					{
						#print "[get_full_fmt_str]next:key=$key,addr=$addr,$_\n";
						next;	
					}
				}
				#print "[get_full_fmt_str]xxx:$_\n";
				#step1:get line info (should be asc_str + fmt_str).
				#find fmt_str position.
				if ($line =~ m/\s\w{$offset}\s/)
				{
					my $fmt_str = $' ;
					
					#step2: find tail of asc_str.
					my $fmt_len = length($fmt_str);
					my $asc_len = length($line)-$fmt_len;
					my $asc_str= substr($line,0,$asc_len);
					#print "[get_full_fmt_str]offset=$offset:$asc_str=>$fmt_str\n";
					
					$asc_str =~ s/\s*//g;															#eliminate blank space
					#step3: get the full fmt_str line by line
					my $tail = index($asc_str,'00');
					#get the first line
					if($first_line)
					{
						$first_line = 0;
						if(-1 != $tail )
						{
							do
							{
								if($off_in_str > $tail/2)
								{
									$tail = index($asc_str,'00',$tail+1); 								#check another tail is occur or not
								}
								else
								{
									$full_fmt_str .= substr($fmt_str,$off_in_str,($tail/2 - $off_in_str));	#get the string from offset to tail
									#print "[1][get_full_fmt_str]tail=$tail,ful: $full_fmt_str\n";
									$get_fmt_str=1;
									goto RETURN;
								}
							}while($tail != -1);
							$full_fmt_str .= substr($fmt_str,$off_in_str);								#get the string from offset to the end of the line
							#print "[2][get_full_fmt_str]tail=$tail,cnt: $full_fmt_str\n";
							next;																													#get next line in @inc_info
						}
						else
						{
							$full_fmt_str .= substr($fmt_str,$off_in_str);								#get the string from offset to the end of the line
							#print "[3][get_full_fmt_str]tail=$tail,cnt: $full_fmt_str\n";
							next;																													#get next line in @inc_info	
						}
					}
					
					#get the left lines	
					if(-1 != $tail )
					{
						$full_fmt_str .= substr($fmt_str,0,$tail/2);									#get the string from begin to tail
						#print "[4][get_full_fmt_str]tail=$tail,ful: $full_fmt_str\n";
						$get_fmt_str=1;
						goto RETURN;
					}
					else
					{
						$full_fmt_str .= substr($fmt_str,0);														#get the total line
						#print "[5][get_full_fmt_str]tail=$tail,cnt: $full_fmt_str\n";
					}	
				}
			}
			elsif(/^Contents of section .debug_info:/)
			{
				$full_fmt_str = undef;
				$get_fmt_str = 0;
				goto RETURN;
			}
		}
RETURN: 
	return ($get_fmt_str,$full_fmt_str,$new_position);
}

#***************************************************************************************************
# subroutine:  parse_fmt_info
# input :      $fmt_str_info: a hash reference, saved format-str of every absolute-addr
#              $fmt_str_addr: a hash reference, saved format-str absolute-addr and callee/caller name 
# return:      none, will add parameter-count in $fmt_str_info
#***************************************************************************************************
sub parse_fmt_info
{
	my ($fmt_str_info,$fmt_str_addr) = @_;
	my %fmt_str_info = %$fmt_str_info;

	foreach (keys %fmt_str_info)
	{
		#print "[parse_fmt_info]fmt_str:$_\n";
    my $is_sscanf = 0;
    my $is_sprintf = 0;
    my $count_sscanf = 0;
    my $count_sprintf = 0;
    my $func_ref = $fmt_str_addr->{$_};
    #step0:check callee is sprintf family or sscanf family
    foreach my $func_name (@$func_ref)
    {
    	if($is_sscanf && $is_sprintf)
  		{
  			last;
  		}
    	my ($callee_name,$caller_name) = ($func_name =~ m/(\S+)\|(\S+)/); 		#format: callee|caller	
			if(($callee_name eq '__wrap_sscanf')  
				 or (exists $save_found_caller_func_list{$callee_name}
				and ($save_found_caller_func_list{$callee_name} eq '__wrap_vsscanf')))							
			{
				$is_sscanf =1 ;				#found callee: sscanf family
			}
			else																																		
			{
				$is_sprintf = 1 ; 		#found callee: sprintf family
			}
   	}
   	
   	#step1:parse one format string with special callee
		my $fmt_str = $fmt_str_info{$_};
	  my $callee_name;
	  if($is_sscanf)
	  {
	  	$callee_name = '__wrap_sscanf'; 		#sscanf family
	  	$count_sscanf = parse_one_fmt_str($fmt_str,$callee_name);
	  }
	  if($is_sprintf)
	  {
	  	$callee_name = '__wrap_sprintf';		#sprintf family
	  	$count_sprintf = parse_one_fmt_str($fmt_str,$callee_name);
	  }
  
	  #step3:save parse result of every callee
	  foreach my $func_name (@$func_ref)
	  {
	  	my ($callee_name,$caller_name) = ($func_name =~ m/(\S+)\|(\S+)/); 		#format: callee|caller
	  	my $count;
	  	if(($callee_name eq '__wrap_sscanf') 
	  	   or (exists $save_found_caller_func_list{$callee_name} 
	  	   and ($save_found_caller_func_list{$callee_name} eq '__wrap_vsscanf')))
	  	{
	  		$count = $count_sscanf;
	  	}
	  	else
	  	{
	  		$count = $count_sprintf;
	  	}
	  	$func_name .= '|' . $count;																			#now: callee|caller|count
	  																		
	 		#print "[parse_fmt_info]$_:$caller_name=>$callee_name:$count\n";
	 		#print "[parse_fmt_info]$func_name\n";	
	  }
	}
}
#**********************************************************************************************
# subroutine:  parse_one_fmt_str
# input :      $fmt_str: 			format string
#              $callee_name: 	callee name
# return:      $count:				parameter count in format-str
#**********************************************************************************************
sub parse_one_fmt_str
{
	my ($fmt_str,$callee_name) = @_;
		my $valid_count=0;
		my $where = index($fmt_str,'%');		
		if(-1 != $where)
		{
			$fmt_str = substr($fmt_str,$where);	
		}
		else 
	{
		#print "[parse_one_fmt_str]not found <%>: $fmt_str\n";
		return $valid_count;
	}
	my @fmt_str_list = split /%/,$fmt_str;
	#print "[parse_one_fmt_str]@fmt_str_list len=$#fmt_str_list\n";
	#for sscanf family => format: [%[*][width][size]type|''|'\t'|'\n'|symbols except %]
	if ($callee_name eq '__wrap_sscanf')
	{
		foreach (@fmt_str_list)
		{
			#print "[parse_one_fmt_str]$_\n";
			if($_ eq '')
			{#e.g. %%,this case will be ignored.
				next;
			}	
			
			if (/^(\*)\w+/)
			{#e.g. %*s%s, %*s will be ignored.
				#print "[parse_one_fmt_str]$`<$&>$'\n";
				next;
			}
			
			if (/^\[(.*)\]+/)
			{#group only for sscanf family: e.g. %[a-z]
				#print "[parse_one_fmt_str]$`<$&>$'\n";
				$valid_count++;
				next;
			}
			
			#if(/[(\d+)?[h{1,2}|l{1,2}|j|t|z]?[c-g|i|n-p|s|u|x]|\s+|(\d\D)*]/i)
			if(/((\d+)?(h{1,2}|l{1,2}|j|t|z)?([c-g]|i|[n-p]|s|u|x))/i)
			{
				#format: %[*][width][size]type
				#width:	(\d+)?
				#size: 	(h{1,2}|l{1,2}|j|t|z)?
				#type: 	([c-g]|i|[n-p]|s|u|x)
				#print "[parse_one_fmt_str]$`<$&>$'\n";
				$valid_count++;
			}
			else
			{
				print "Warning: [parse_one_fmt_str]undefine format found:\n =>func-name: $callee_name,full fmt-str: $fmt_str\n =>invalid fmt-str:$_\n";
			}
		}
		return $valid_count;
	}
	else	#for sprintf family => format: %[pos][flags][width][.prec][size]type
	{
		foreach (@fmt_str_list)
		{
			#print "[parse_one_fmt_str]$_\n";
			if($_ eq '')#e.g. %%,this case will be ignored.
			{
				next;
			}	
			
			#if (/(^\d+\$)?[-|\+|' '|0|\#|\']*([\*(?:\d+\$)?|\d+])?(\.[\*(?:\d+\$)?|\d+])?[h{1,2}|l{1,2}|j|t|z]?[a|c-g|i|n-p|s|u|x]/i)
			if (/(^\d+\$)?(?:-|\+|' '|0|\#|\')*(\*(?:\d+\$)?|\d+)?(?:\.(\*(\d+\$)?|\d+))?(h{1,2}|l{1,2}|j|t|z)?(a|[c-g]|i|[n-p]|s|u|x)/i)
			{
				#format: %[pos][flags][width][.prec][size]type
				#pos:		(^\d+\$)? 
				#flags: (?:-|\+|' '|0|\#|\')*
				#width:	(\*(?:\d+\$)?|\d+)?
				#prec: 	(?:\.(\*(\d+\$)?|\d+))?
				#size: 	(h{1,2}|l{1,2}|j|t|z)?
				#type: 	(a|[c-g]|i|[n-p]|s|u|x)
				#print "[parse_one_fmt_str]$`<$&>$'\n";	
				$valid_count++;
				#print	"[parse_one_fmt_str]$`<$&>$',$valid_count\n";
				if($1)
				{
					#print	"[parse_one_fmt_str]position found:$1\n";
					$valid_count++;
				}
				if($2)
				{
					#print "[parse_one_fmt_str]wide found: $2\n";
					if($2=~m/\*/)
					{	
						$valid_count++;
					}
				}
				if ($3)
				{
					#print "[parse_one_fmt_str]prec found: $3\n";
					if($3=~m/\*/)
					{
						$valid_count++;
					}
				}
			}
		else
		{
				print "Warning: [parse_one_fmt_str]undefine format found:\n =>func-name: $callee_name,full fmt-str: $fmt_str\n =>invalid fmt-str:$_\n";
			}
		}
		return $valid_count;	
	}
}


#**********************************************************************************************
# subroutine:  find_file_name
# input :      %exceed_max_para_table: all callers who use function in $interest_func_list but 
#																			 exceed parameter strict
# return:      %exceed_max_para_table: add file-name which the function belongs to
#**********************************************************************************************
sub find_file_name
{
	my %exceed_max_para_table = @_;
	my $count = 0;
	my $arr_size = 0;
	open(FILE_MAP, $map_file) || die "Error: Cannot open file $map_file: $!\n";
	foreach my $key (keys %exceed_max_para_table)
	{
		my $max_para_info_aref = $exceed_max_para_table{$key};
		$arr_size += scalar @$max_para_info_aref;
	}
	#print "[find_file_name]arr_size = $arr_size\n";
	foreach (<FILE_MAP>)
	{
		my $line = $_;
		if($line =~ m/^[\w|_]{1,}\s+\S+\(\w+\.obj\)/)
		{
			(my $obj_name) = ($line=~ m/\((\w+\.obj)\)/);
			#print "[find_file_name]obj_name=$obj_name,$line";
			foreach my $key (keys %exceed_max_para_table)
			{
				my $max_para_info_aref = $exceed_max_para_table{$key};
				foreach my $info (@$max_para_info_aref)
		    {
		    	#format: file_name|func_callee|func_caller|para_count|fmt_str
		    	my ($file_name,$func_callee,$func_caller,$para_count,$fmt_str) = ($info =~ m/(\S+)\|(\S+)\|(\S+)\|(\S+)\|(.+)/);	
		    	if($file_name ne '--') 	
					{
						next;																#	file_name already found.
					}
		    	elsif ($line =~ m/^$func_caller/)			#found the line include $func_caller
		    	{
					  $info = $obj_name . substr($info,2);#skip '--'
						$count++;
						#print "[find_file_name]count=$count,info=$info\n";
						if($count == $arr_size)
						{
							goto OVER;
						}
		    	}
		    }
    	}
    }
  }
    	
OVER:	
	close(FILE_MAP);
	return %exceed_max_para_table;    
}


#**********************************************************************************************
# subroutine:  get_template_caution
# input :      $max_parameters:  max parameters count
# return:      $template:				 string with caution info
#**********************************************************************************************
sub get_template_caution
{
	my $max_parameters = $_[0];
	my $template = <<"__TEMPLATE";
	
========================================================================================================
                       									  [!!Caution!!]
In order to reduce the stack-size usage in sprintf and sscanf,the variable-parameters count is stricted, 
the max number of support variable-parameters is $max_parameters. 
This limitation is also apply to all sprintf/sscanf family functions, 
that is sprintf/snprintf/vsprintf/vsnprintf/sscanf/vsscanf.    
variable-parameters(...) is the third input-parameters(for snprintf/vsnprintf, the fourth input-parameters):
		int sprintf(char* buffer, const char*format, ...);
		int sscanf(const char*buffer,const char*format,...);  
         
Some functions in the following object list use sprintf or sscanf family fuction, 
but their variable-parameters exceed the strict which may exist stack-overflow risk. 
Please fix it with Error Handling SOP as below.
__TEMPLATE
    return $template;
}

#**********************************************************************************************
# subroutine:  get_function_list
# input :      $para_table:  max parameters count with related info
# return:      $err_msg:		 string with function info
#**********************************************************************************************
sub get_function_list
{
	my %para_table = @_;
	my $err_msg;
	foreach my $key (keys %para_table)
	{
		my $para_aref = $para_table{$key};
		foreach my $info (@$para_aref)
    {
    	#format: file_name|func_callee|func_caller|para_count|fmt_str
		  my ($file_name,$func_callee,$func_caller,$para_count,$fmt_str) = ($info =~ m/(\S+)\|(\S+)\|(\S+)\|(\S+)\|(.+)/);	
		  if($info =~ m/__wrap_/)
		  {
		  	($func_callee) =($func_callee =~ m/__wrap_(\S+)/);  		  	
		  }
		  $err_msg .= "Error: Function $func_caller in $file_name use $func_callee but exceed parameter strict. Please follow the SOP in ./build/[PROJECT_NAME]/[FLAVOR]/bin/log/cLib_stacksize_shrink.log to fix it!\n";
			$err_msg .= "\t=>func_caller = $func_caller, func_callee = $func_callee\n";
			$err_msg .= "\t=>file_name = $file_name\n";
			$err_msg .= "\t=>para-num = $para_count\n\t=>format_str = $fmt_str\n\n\n";  	
    }
  }
	return $err_msg;
}

#**********************************************************************************************
# subroutine:  get_template_errorHandlingSOP_1
# input :      $para_table:  max parameters count with related info
# return:      $template:		 string with background
#**********************************************************************************************
sub get_template_errorHandlingSOP_1
{
	my $max_parameters = $_[0];
	my $template = <<"__TEMPLATE";
																					[background]
As described in Caution, the sprintf and sscanf family takes much stack-size on current thread. sprintf 
is about 1040-Byte and sscanf is about 1392-Byte. What's more, through analyzing the source-code, we 
found the stack-size consume has big relations with the max number of support variable-parameters. If 
the max-value is restricted to $max_parameters, which will save about ($max_parameters*24)Byte, and it 
will reduce the stack-overflow risk.
											
__TEMPLATE
		return $template;
}

#**********************************************************************************************
# subroutine:  get_template_errorHandlingSOP_2
# input :      none
# return:      $content: string with all error-handling SOP in error_hanling_SOP.txt
#**********************************************************************************************
sub get_template_errorHandlingSOP_2
{
	my $content;
	open FILE, "<$err_sop_path" or die("Error: Cannot open file $err_sop_path : $!\n");
	{
	  local $/;
	  $content = <FILE>;
	}
	close FILE;
	chomp($content);
	return $content;
}
