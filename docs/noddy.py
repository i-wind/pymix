#!/usr/bin/env python

import noddy

nd = noddy.Noddy()

print nd, nd.__doc__, dir(nd), repr(nd), nd.__class__

nd.first = "Harry"
nd.last = "Trueman"
nd.number = 8

print "%s %s %d" % (nd.first, nd.last, nd.number)
print nd.name()
