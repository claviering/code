#! /usr/bin/env python
# -*- coding: utf-8 -*-
# vim:fenc=utf-8
#
# Copyright © 2016 claviering <claviering@sunn>
#
# Distributed under terms of the WTFPL license.

for n in range(100,1000):
    i = n % 10
    j = n / 10 % 10
    k = n / 100
    if n == i**3 + j**3 + k**3:
        print n
