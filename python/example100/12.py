#! /usr/bin/env python
# -*- coding: utf-8 -*-
# vim:fenc=utf-8
#
# Copyright © 2016 claviering <claviering@sunn>
#
# Distributed under terms of the WTFPL license.

h = 0
leap = 1
from math import sqrt
from sys import stdout
for m in range(101,201):
    k = int(sqrt(m + 1))
    for i in range (2,k + 1):
        if m % i == 0:
            leap = 0
            break
    if leap == 1:
        print '%-4d' % m
        h += 1
    leap = 1
print 'total: %d' % h 
