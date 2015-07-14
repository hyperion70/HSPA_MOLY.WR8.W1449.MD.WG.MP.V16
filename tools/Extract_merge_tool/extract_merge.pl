use strict;
use Cwd;
&Usage if ($#ARGV <2);
while($#ARGV!=1)
{
	if($ARGV[0]=~/extract\b/)
	{
		my $setfile = &set($ARGV[1],$ARGV[2],$ARGV[3]);
		print "Extraction is done!"
	}elsif($ARGV[0]=~/merge\b/)
	{
		my $merged = &merge($ARGV[1],$ARGV[2]);
		print "The file is merged!"
	}
	else
	{
		&Usage;
	}
	last;
}
sub set
{
	my $reffile = $_[0];
	my $reduce = $_[1];
	my $strfile = $_[2];
	my $string = '';
	my $count = 1;

	my $path = getcwd;
	my $treffile = "$path/reftemp.txt";
	system("iconv.exe -f utf-16LE -t utf-8 $reffile >$treffile");
	my $treduce = "$path/reducetemp.txt";

	open (REDUCE,">>$treduce")or die"cannot open:$!";
	
	open (STRREL,"<$strfile")or die"cannot open:$!";
	
	open (REL,"<$treffile")or die"cannot open:$!";
	
	my $n=0;

	my @key;
	while(<STRREL>)
	{
		if(/\s.*?\s.*?\s(.*?)\s.*$/)
		{
			$key[$n++] = $1;
		}
	}
	close STRREL;
	
	my %rel;
	my $clean1 = <REL>;
	my $clean2 = <REL>;
	my $clean3 = <REL>;
	my $endline =0;
	my $count =0;
	while(<REL>)
 	{
 		if(/^##number/)
  		{
  			$endline = $_;
  		}elsif(/^(.*?)\s(.*?)$/)
 	 	{
  			$rel{$1} = $2;
 	 	}	
 	 	$count += 1;	
 	}
 	close REL;
 	
	print REDUCE $clean1;
	print REDUCE $clean2;
	print REDUCE $clean3;
	foreach my $num(@key)
	{
		if(exists $rel{$num})
		{
			print REDUCE "$num\t";
			print REDUCE $rel{$num}."\n";
		}
	}	
#	if($endline =~ /^##number(.*?)$/)
#	{
#		$endline =~ s/$1/$count/;
#	}
	if($endline =~ /^##number\s(.*?)$/)
	{
		$endline =~ s/$1/$count/;
	}
	print REDUCE $endline;
	close REDUCE;
	
	system("iconv.exe -f utf-8 -t utf-16LE $treduce>$reduce");
	system("del /Q /F reftemp.txt");
	system("del /Q /F reducetemp.txt");
}

sub merge
{
	my $reffile = $_[0];
	my $reduce = $_[1];
	
	my $path = getcwd;
	my $treffile = "$path/reftemp.txt";
	system("iconv.exe -f utf-16LE -t utf-8 $reffile >$treffile");
	my $treduce = "$path/reducetemp.txt";
	system("iconv.exe -f utf-16LE -t utf-8 $reduce >$treduce");
	
	open (REREDUCE,"<$treduce")or die"cannot open:$!";
	open (REL,"<$treffile")or die"cannot open:$!";
	my %rel;
	
	my $line1 = <REL>;
  	my $line2 = <REL>;
 	my $line3 = <REL>;
 	my $endline ='';
 	 my $count = 0;
 	while(<REL>)
 	{
 		if(/^##number/)
  		{
  			$endline = $_;
  		}elsif(/^(.*?)\s(.*?)$/)
 	 	{
  			$count += 1;
  			$rel{$count.$1} = $2;
 	 	}			
 	}
 	my %reduce;
 	while(<REREDUCE>)
 	{
 		if(/^(.*?)\s(.*?)$/)
 		{
  			$reduce{$1} = $2;
 		}
 	}
 ############merge
 foreach my $k (keys %reduce)
{
	foreach my $rek (keys %rel)
	{
		if($rek =~ /$k\b$/)
	 	{
			$rel{$rek} = $reduce{$k};
			last;
		}
	}
}
 
 close REREDUCE;
 close REL;
 open(FH,">$treffile")or die"cannot open:$!";
 print FH $line1;
 print FH $line2;
 print FH $line3;
 
 ##############################
 foreach my $m(sort asc_key(keys %rel))
 {
 	if($m =~ /\d+(.*?)$/)
 	{
 		print FH "$1\t";
 		print FH $rel{$m}."\n";
 	}
 	
 }
 print FH $endline;
 close(FH);
 	
 	system("iconv.exe -f utf-8 -t utf-16LE $treffile>$reffile");
 	system("del /Q /F reftemp.txt");
 #	system("iconv.exe -f utf-8 -t utf-16LE $treduce>$reduce");
 	system("del /Q /F reducetemp.txt");
}

sub asc_key
 {
 	$a <=> $b;
 }
 
sub copy1stline
{
	my $file = $_[0];
	my $newfile = $_[1];
	open (FILE,"<$file")or die"cannot open:$!";
	open (NEWFILE,">$newfile")or die"cannot open:$!";	
	my $result = <FILE>;
	print NEWFILE $result;
	close FILE;
	close NEWFILE;
}

sub Usage
{
	print "\nUsage:\n perl extract_merge.pl [Tool options] path1\\file1 path2\\file2 ...\n";
	print "\nDescription:\n";
	print " Tool options = extract   (Extract tool,needs 3 parameters)\n\n";
	print "   <path1\\file1> = path1\\ref_list.txt  (1st para:ref_list.txt including path)\n";
	print "   <path2\\file2> = path2\\result file   (2nd para:result file named by yourself including path)\n";
	print "   <path3\\file3> = path3\\string_resouce_usage.txt (3rd para:string_resouce_usage.txt including path)\n\n";
	print " Tool options = merge     (Merge tool,needs 2 parameters)\n\n";
	print "   <path1\\file1> = path1\\ref_list.txt  (1st para:ref_list.txt including path)\n";
	print "   <path2\\file2> = path2\\extract file  (2nd para:extract file got though extract tool including path)\n\n";
	print "Example:\n";
	print " perl extract_merge.pl extract F:\\home\\ref_list.txt F:\\home\\ResultFolder\\extract_result.txt F:\\home\\string_resouce_usage.txt\n";
	print " perl extract_merge.pl merge F:\\home\\ref_list.txt F:\\home\\ResultFolder\\extract_result.txt\n";
	exit 1;
}
