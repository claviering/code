#! /usr/bin/env python
# -*- coding: utf-8 -*-
# vim:fenc=utf-8
#
# Copyright © 2016 claviering <claviering@sunn>
#
# Distributed under terms of the WTFPL license.

import time

print time.strftime('%Y-%m-%d %H:%M:%S',time.localtime(time.time()))

# 暂停一秒
time.sleep(1)

print time.strftime('%Y-%m-%d %H:%M:%S',time.localtime(time.time()))
