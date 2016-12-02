#! /usr/bin/env python
# -*- coding: utf-8 -*-
# vim:fenc=utf-8
#
# Copyright © 2016 claviering <claviering@sunn>
#
# Distributed under terms of the WTFPL license.

Sn = 100.0
Hn = Sn / 2
for n in range(2,11):
    Sn += 2 * Hn
    Hn /= 2
print 'Total of road is %f' %Sn
print 'The tenth is %f metet' %Hn
