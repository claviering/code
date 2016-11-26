#! /usr/bin/env python
# -*- coding: utf-8 -*-
# vim:fenc=utf-8
#
# Copyright © 2016 claviering <claviering@sunn>
#
# Distributed under terms of the WTFPL license.

def fib(n):
    a,b = 1,1
    for i in range(n-1):
        a,b = b,a+b
    return a
print fib(10)
