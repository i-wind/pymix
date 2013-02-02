INC   = -I/usr/include/python2.7
LIB   = -lpython2.7 -lboost_python
FLAGS = -shared -fPIC -DPIC -Wall -O2
NAME  = _url_parser
LIBNM = $(addsuffix .so,$(NAME))

all: $(LIBNM)

$(LIBNM): $(addsuffix .o,$(NAME))
	g++ $(FLAGS) $^ -o $@ $(INC) $(LIB)

$(addsuffix .o,$(NAME)): $(addprefix urlparser,.cpp .hpp)
	g++ $(FLAGS) -c -o $@ $< $(INC) $(LIB)

.PHONY: depends strip clean
depends:
	ldd $(LIBNM)

strip:
	strip $(LIBNM)

clean:
	rm -f *.o $(LIBNM)
