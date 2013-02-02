#!/usr/bin/env python

import _numbers

class Numbers:
    def __init__(self, an_int, a_float):
        #Check an_int
        if type(an_int) != type(1):
            raise TypeError, "Fool! an_int must be an integer"
        #Check a_float
        if type(a_float) != type(3.14159):
            raise TypeError, "Fool! a_float must be a float"
        self.this = _numbers.PyNumbers(an_int, a_float)

    def MemberMult(self):
        return _numbers.PyNumbers_MembMult(self.this)


if __name__ == "__main__":

    num = Numbers(2, 3.2)
    print num.MemberMult()
