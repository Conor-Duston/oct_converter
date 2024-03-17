CC=gcc
src=converter_code/
bin=bin/


all: $(bin)oct_converter $(bin)lib_oct_converter.so clean

$(bin)oct_converter: $(src)converter.c
	$(CC) $(src)converter.c -o $(bin)oct_converter

$(bin)lib_oct_converter.so: $(bin)oct_converter.o
	$(CC) $(bin)oct_converter.o -shared -o $(bin)lib_oct_converter.so 

$(bin)oct_converter.o: $(src)converter.c $(src)converter.h
	$(CC) -c $(src)converter.c -o $(bin)oct_converter.o -fPIC

clean:
	rm -f $(bin)*.o