cflags  := `python2.7-config --cflags`
ldflags := `python2.7-config --ldflags`
TARGET  := hello_world
name    := call_function
name_t  := call_thread
name_2  := call_thread_2
name_s  := call_socket
name_m  := call_mmap

all: $(TARGET).x $(name).x call_class.x $(name_t).x $(name_2).x $(name_s).x $(name_m).x

$(TARGET).x: $(TARGET).o
	g++ -o $@ $<

$(TARGET).o: $(TARGET).cpp

$(name).x: $(name).o
	gcc -o $@ $< $(ldflags)

$(name).o: $(name).c
	gcc -c $<

call_class.x: call_class.o
	@echo $(ldflags)
	gcc -o $@ $< $(ldflags)

call_class.o: call_class.c
	gcc -c $<

$(name_t).x:
	gcc -o $@ $(name_t).c $(ldflags)

$(name_2).x:
	gcc -o $@ $(name_2).c $(ldflags)

$(name_s).x:
	gcc -o $@ $(name_s).c $(ldflags)

$(name_m).x:
	gcc -o $@ $(name_m).c $(ldflags)

clean:
	rm -rf *.o *.pyc *.x
