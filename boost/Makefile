include Make.defaults
include Make.rules

INC   = $(shell python-config --includes)
LIB   = -lpython2.7 -lboost_python
FLAGS = -shared -fPIC -DPIC -DWITH_PYTHON -Wall -O2
CPPFLAGS = -Wall -O2
NAME  = _url_parser
LIBNM = $(addsuffix .so,$(NAME))
HWOBJS = hello_world.o
OBJS = handle_error.o parse_config.o config_parser.o

all: $(LIBNM) hello_ext.so example.x hello.so helloworld.x parse_config.x

$(LIBNM): $(addsuffix .o,$(NAME))
	g++ $(FLAGS) $^ -o $@ $(INC) $(LIB)

$(addsuffix .o,$(NAME)): $(addprefix urlparser,.cpp .hpp)
	g++ $(FLAGS) -c -o $@ $< $(INC) $(LIB)

hello_ext.so: hello_ext.cpp
	g++ $(FLAGS) $^ -o $@ $(INC) $(LIB)

example.x: example.cpp
	g++ $(CPPFLAGS) $^ -o $@ $(INC) $(LIB)

hello.so: hello.cpp
	g++ $(FLAGS) $^ -o $@ $(INC) $(LIB)

helloworld.x: $(HWOBJS)
	$(LD) -o $@ $^ $(PY_LDFLAGS) $(LDFLAGS) $(BOOST_LDFLAGS)

parse_config.x: $(OBJS)
	$(LD) -o $@ $^ $(PY_LDFLAGS) $(LDFLAGS) $(BOOST_LDFLAGS)

.PHONY: depends strip clean
depends:
	ldd $(LIBNM)

strip:
	strip $(LIBNM) hello_ext.so

clean:
	rm -f *.o *.pyc *.so *.x
