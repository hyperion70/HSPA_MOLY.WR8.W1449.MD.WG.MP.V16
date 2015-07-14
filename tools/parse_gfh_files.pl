my $gfh_files = $ARGV[0];
my $cfg_temp = $ARGV[1];

open(FILEHANDLE, "$gfh_files") or die "can't open $!";
foreach (<FILEHANDLE>)
  {
    $line =~ s/\s+$//;    
    if($_ =~ /SECURE/){
    	print "tools\\gfh_process\.pl $cfg_temp -secro $_ \n";
      $result = system("perl tools\\gfh_process.pl $cfg_temp -secro $_");
    }else{
      print "tools\\gfh_process\.pl $cfg_temp -maui $_\n";
      $result = system("perl tools\\gfh_process.pl $cfg_temp -maui $_");
    }
    if ($result != 0)
    {
      print "Error: Failed in gfh_process.pl\n";
      exit 1;
    }
}
close FILEHANDLE;