use Config;
$file = shift;
open OUT, ">$file" or die "Can't create $file: $!";
print OUT <<"!GROK!THIS!";
$Config{startperl} -w
!GROK!THIS!
print OUT <<'!NO!SUBS!';
################################################################################
#
# $Project: /Convert-Binary-C $
# $Author: mhx $
# $Date: 2003/01/03 03:18:58 +0100 $
# $Revision: 6 $
# $Snapshot: /Convert-Binary-C/0.12 $
# $Source: /bin/perltypes.PL $
#
################################################################################
# 
# Copyright (c) 2002-2003 Marcus Holland-Moritz. All rights reserved.
# This program is free software; you can redistribute it and/or modify
# it under the same terms as Perl itself.
# 
################################################################################

#===============================================================================
#
#   Parse perl's header files and play around with the types they define.
#
#===============================================================================

use Convert::Binary::C;
use Data::Dumper;
use strict;

my $base;
-d "$_/include" and $base = "$_/include" and last for qw( t ../t );
defined $base or die <<MSG;
Please run this script from either the 'examples' directory
or the distribution base directory.
MSG

#----------------------------------------
# Create an object, set the include path.
#----------------------------------------

my $c = new Convert::Binary::C Include => ["$base/perlinc", "$base/include"];

#------------------
# Parse the C file.
#------------------

eval { $c->parse_file( "$base/include.c" ) };

#-----------------------
# Check for parse error.
#-----------------------

if( $@ ) {
  die "Parse error: $@";
}

#----------------------------
# Dump out the configuration.
#----------------------------

print Dumper( $c->configure );

#----------------------------
# Print all the enumerations.
#----------------------------

my @enums = $c->enum_names;
print "\nenums: @enums\n\n";

#---------------------------------------------------------------------------
# Print all structs, sorted by size; skip all structs smaller than 50 bytes.
#---------------------------------------------------------------------------

print "large structs:\n\n";

my @structs = sort { $c->sizeof( $b ) <=> $c->sizeof( $a ) }
              grep { $c->sizeof( $_ ) >= 50 }
              $c->struct_names;

for my $struct ( @structs ) {
  printf "struct %-20s => %4d bytes\n", $struct, $c->sizeof( $struct );
}

print "\n";

#-----------------------------------------------
# Dump the definition of the __socket_type enum
#-----------------------------------------------

print Data::Dumper->Dump( [$c->enum('__socket_type')], ['__socket_type'] );
!NO!SUBS!

close OUT or die "Can't close $file: $!";
chmod 0755, $file or die "Can't reset permissions for $file: $!\n";
