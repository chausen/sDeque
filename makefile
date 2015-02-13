# sDeque Makefile
# February 11th, 2015

CC=g++
CFLAGS= -c -g

all: driver

driver: sDeque_main.o
	$(CC) -o sDeque sDeque_main.o

sDeque_main.o: sDeque_main.cpp
	$(CC) $(CFLAGS) sDeque_main.cpp

clean:
	rm -rf *.o driver
