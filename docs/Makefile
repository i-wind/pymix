CXX = g++
CXXFLAGS = -I/usr/include/python2.7 -fPIC -Wall -ggdb
LDFLAGS  = -shared
LDLIBS   = -lpython2.7

COMPILE.cxx = $(COMPILE.cc)

%.o: %.cxx
	$(COMPILE.cxx) $(OUTPUT_OPTION) $<

noddy.so: noddy.o
	$(CXX) $(LDFLAGS) -o $@ $^ $(LDLIBS)

noddy.o: noddy.cxx

clean:
	rm -f *.o *.pyc noddy.so
