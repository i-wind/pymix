#!/usr/bin/env python

import noddy

nd = noddy.Noddy()

print nd, nd.__doc__, dir(nd), repr(nd), nd.__class__

nd.first = "Harry"
nd.last = "Trueman"

print nd.name()

# Noddy objects can participate in cycles. This is pretty silly,
# but it gives us an excuse to add support for the cyclic-garbage
# collector to the Noddy example.
n = noddy.Noddy()
l = [n]
n.first = l

print n.name()
