INC   = $(shell python-config --includes)
LIB   = -lpython2.7 -lboost_python
FLAGS = -shared -fPIC -DPIC -DWITH_PYTHON -Wall -O2
CPPFLAGS = -Wall -O2
NAME  = _url_parser
LIBNM = $(addsuffix .so,$(NAME))

all: $(LIBNM) hello_ext.so example.x

$(LIBNM): $(addsuffix .o,$(NAME))
	g++ $(FLAGS) $^ -o $@ $(INC) $(LIB)

$(addsuffix .o,$(NAME)): $(addprefix urlparser,.cpp .hpp)
	g++ $(FLAGS) -c -o $@ $< $(INC) $(LIB)

hello_ext.so: hello_ext.cpp
	g++ $(FLAGS) $^ -o $@ $(INC) $(LIB)

example.x: example.cpp
	g++ $(CPPFLAGS) $^ -o $@ $(INC) $(LIB)

.PHONY: depends strip clean
depends:
	ldd $(LIBNM)

strip:
	strip $(LIBNM) hello_ext.so

clean:
	rm -f *.o *.pyc *.so *.x
