#! /usr/bin/env python
# -*- coding: utf-8 -*-
# vim:fenc=utf-8
#
# Copyright © 2016 claviering <claviering@sunn>
#
# Distributed under terms of the WTFPL license.

i = int(raw_input('input'))
arr = [1000000,600000,400000,200000,100000,0]
rat = [0.01,0.015,0.03,0.05,0.075,0.1]
r = 0;
for idx in range(0,6):
    if i > arr[idx]:
        r += (i-arr[idx]) * rat[idx]
        print ((i-arr[idx]) * rat[idx])
        i = arr[idx]
print r
