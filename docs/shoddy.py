#!/usr/bin/env python

import shoddy

s = shoddy.Shoddy(range(3))
s.extend(s)
print len(s)

print s
print s.increment()
print s.increment()
