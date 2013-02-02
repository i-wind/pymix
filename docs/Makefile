C = gcc
CXX = g++
CXXFLAGS = -I/usr/include/python2.7 -fPIC -Wall -ggdb
CFLAGS = -I/usr/include/python2.7 -Wall -ggdb
LDFLAGS  = -shared
LDLIBS   = -lpython2.7

COMPILE.cxx = $(COMPILE.cc)

all: noddy.so shoddy.so embed

%.o: %.cxx
	$(COMPILE.cxx) $(OUTPUT_OPTION) $<

noddy.so: noddy.o
	$(CXX) $(LDFLAGS) -o $@ $^ $(LDLIBS)

noddy.o: noddy.cxx

#%.o: %.cc
#       $(COMPILE.cc) $(OUTPUT_OPTION) $<
#
shoddy.so: shoddy.o
	$(CXX) $(LDFLAGS) -o $@ $^ $(LDLIBS)

shoddy.o: shoddy.cc

embed: embed.o
	$(CC) -o $@ $< $(LDLIBS)

clean:
	rm -f *.o *.pyc *.so embed
