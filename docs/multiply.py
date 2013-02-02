#!/usr/bin/env python

# usage: $ call multiply multiply 3 2
def multiply(a,b):
    print "Will compute", a, "times", b
    c = 0
    for i in range(0, a):
        c = c + b
    return c
