INC   = $(shell python-config --includes)
LIB   = -lpython2.7
LFLAGS = -shared -fPIC -DPIC
FLAGS = -Wall -O2
NAME  = test_pyembed
EXENM = $(addsuffix .x,$(NAME))

all: libpyembed.so $(EXENM) users.x

libpyembed.so: pyembed.o
	g++ $(FLAGS) $(LFLAGS) -o $@ $^ $(INC) $(LIB)

pyembed.o: pyembed.cpp
	g++ -c $(FLAGS) $(LFLAGS) $^ -o $@ $(INC)

$(EXENM): $(addsuffix .o,$(NAME))
	g++ $(FLAGS) $^ -o $@ $(INC) $(LIB) -L. -Wl,-rpath,. -lpyembed

users.x: users.cpp
	g++ $(FLAGS) $^ -o $@ $(INC) $(LIB) -L. -Wl,-rpath,. -lpyembed -lm -lpthread -ltk8.5

.PHONY: clean
clean:
	rm -f *.o *.x *.so *.pyc
