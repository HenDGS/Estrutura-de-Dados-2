CC=gcc 
CFLAGS=-Wall

all: main
main: main.o
main.o: main.c function.c function.h

clean:
	rm -f main main.o
run: main
	./program