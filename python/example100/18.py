#! /usr/bin/env python
# -*- coding: utf-8 -*-
# vim:fenc=utf-8
#
# Copyright © 2016 claviering <claviering@sunn>
#
# Distributed under terms of the WTFPL license.

sum = 0
n = int(raw_input('n=:\n'))
a = int(raw_input('a=:\n'))
d = a
for count in range (n):
    sum = sum + a
    print sum 
    a = d + a * 10
