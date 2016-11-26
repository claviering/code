#! /usr/bin/env python
# -*- coding: utf-8 -*-
# vim:fenc=utf-8
#
# Copyright © 2016 claviering <claviering@sunn>
#
# Distributed under terms of the WTFPL license.

l = []
for i in range(3):
    x = int (raw_input('integer:\n'))
    l.append(x)
l.sort()
print l
