CC = g++
DEBUG = -g -Wall -O0 -pedantic-errors
CFLAGS=-std=c++14
LFLAGS=-std=c++14
COMPILE=$(CC) $(DEBUG) $(CFLAGS) -c
LINK=$(CC) $(DEBUG) $(LFLAGS)
RM=rm -f

all: sortingDr

sortingDr: sortingDr.o Sorting.o
	g++ -Wall -std=c++14 -g -O0 -pedantic-errors -o sortingDr sortingDr.o Sorting.o
sortingDr.o: sortingDr.cpp Sorting.h
	g++ -Wall -std=c++14 -g -O0 -pedantic-errors -c sortingDr.cpp
Sorting.o: Sorting.cpp Sorting.h
	g++ -Wall -std=c++14 -g -O0 -pedantic-errors -c Sorting.cpp
clean:
	rm -rf sortingDr
	rm -rf *.o