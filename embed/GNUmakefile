TARGET = hello_world

all: $(TARGET).x

$(TARGET).x: $(TARGET).o
	g++ -o $@ $<

$(TARGET).o: $(TARGET).cpp

clean:
	rm -rf *.o $(TARGET).x
