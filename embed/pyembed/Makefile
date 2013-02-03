INC   = $(shell python-config --includes)
LIB   = -lpython2.7
FLAGS = -Wall -O2
NAME  = test_pyembed
EXENM = $(addsuffix .x,$(NAME))

all: $(EXENM)

$(EXENM): $(addsuffix .o,$(NAME)) pyembed.o
	g++ $(FLAGS) $^ -o $@ $(INC) $(LIB)

.PHONY: clean
clean:
	rm -f *.o *.x *.pyc
