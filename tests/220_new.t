################################################################################
#
# $Project: /Convert-Binary-C $
# $Author: mhx $
# $Date: 2011/04/10 12:32:24 +0200 $
# $Revision: 13 $
# $Source: /tests/220_new.t $
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

BEGIN {
  plan tests => 3;
}

# This test is basically only for the 901_memory.t test

$c = eval { new Convert::Binary::C };
ok( $@, '' );

$c = eval { new Convert::Binary::C 'foo' };
ok( $@, qr/^Number of configuration arguments to new must be even/ );

$c = eval { new Convert::Binary::C foo => 42 };
ok( $@, qr/^Invalid option 'foo'/ );

