#!/usr/bin/env python

import _url_parser

def printData(parser):
    print "\n\n%s\n%s\n%s\n%s\n%s\n%s\n%s" % (parser.url, parser.queryString,
                          parser.path, parser.extension, parser.protocol,
                          parser.host, parser.port)

parser = _url_parser.UrlParser("http://localhost:80/foo.html?beta=5&q=1:2:3")
printData(parser)

parser.parse("127.0.0.1:8888/try/foo.psp?id=12&value=36")
printData(parser)
