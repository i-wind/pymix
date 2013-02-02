CC = gcc
CXX = g++
CXXFLAGS = -I/usr/include/python2.7 -fPIC -Wall -ggdb
CFLAGS = -I/usr/include/python2.7 -Wall -ggdb
LDFLAGS  = -shared
LDLIBS   = -lpython2.7

COMPILE.cxx = $(COMPILE.cc)

%.o: %.cxx
	$(COMPILE.cxx) $(OUTPUT_OPTION) $<

all: noddy.so shoddy.so call embed _numbers.so

call: call.o
	$(CC) -o $@ $< $(LDLIBS)

embed: embed.o
	$(CC) -o $@ $< $(LDLIBS)

noddy.so: noddy.o
	$(CXX) $(LDFLAGS) -o $@ $^ $(LDLIBS)

noddy.o: noddy.cxx

#%.o: %.cc
#       $(COMPILE.cc) $(OUTPUT_OPTION) $<
#
shoddy.so: shoddy.o
	$(CXX) $(LDFLAGS) -o $@ $^ $(LDLIBS)

shoddy.o: shoddy.cc

_numbers.so: numbers.o
	$(CXX) $(LDFLAGS) -o $@ $^ $(LDLIBS)

clean:
	rm -f *.o *.pyc *.so call embed
