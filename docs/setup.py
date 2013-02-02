#!/usr/bin/env python
# $ python setup.py build

from distutils.core import setup, Extension

setup(name="noddy", version="1.0",
      ext_modules=[
            Extension("noddy", ["noddy.cxx"]),
            Extension("shoddy", ["shoddy.cc"]),
         ])
