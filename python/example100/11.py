#! /usr/bin/env python
# -*- coding: utf-8 -*-
# vim:fenc=utf-8
#
# Copyright © 2016 claviering <claviering@sunn>
#
# Distributed under terms of the WTFPL license.

f1 = 1
f2 = 1
for i in range(1,21):
    print '%12ld %12ld' % (f1,f2),
    if (i % 3) == 0:
        print ''
    f1 = f1 + f2
    f2 = f1 + f2
