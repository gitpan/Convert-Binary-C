################################################################################
#
# $Project: /Convert-Binary-C $
# $Author: mhx $
# $Date: 2011/04/10 12:32:26 +0200 $
# $Revision: 9 $
# $Source: /tests/235_basic.t $
#
################################################################################
#
# Copyright (c) 2002-2011 Marcus Holland-Moritz. All rights reserved.
# This program is free software; you can redistribute it and/or modify
# it under the same terms as Perl itself.
#
################################################################################

use Test;
use Convert::Binary::C @ARGV;

$^W = 1;

BEGIN { plan tests => 54 }

my $c = new Convert::Binary::C;

for my $t ( 'char'
          , 'signed char'
          , 'unsigned char'
          , 'short'
          , 'signed short'
          , 'unsigned short'
          , 'short int'
          , 'signed short int'
          , 'unsigned short int'
          , 'int'
          , 'signed int'
          , 'unsigned int'
          , 'long'
          , 'signed long'
          , 'unsigned long'
          , 'long int'
          , 'signed long int'
          , 'unsigned long int'
          , 'long long int'
          , 'signed long long int'
          , 'unsigned long long int'
          , 'long long'
          , 'signed long long'
          , 'unsigned long long'
          , 'float'
          , 'double'
          , 'long double'
          ) {
  my $in = $t;
  $in =~ s/\b/ /g;
  ok($c->typeof($in), $t);
  ok($c->sizeof($in) > 0);
}

