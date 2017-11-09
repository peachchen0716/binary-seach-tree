CC=g++
#OPTIONS=-g -c
OPTIONS =-c -O2

all: arborist

arborist: arborist.o bst.o randbst.o
	$(CC) -o arborist arborist.o bst.o randbst.o

arborist.o: arborist.cpp bst.h randbst.h
	$(CC) $(OPTIONS) arborist.cpp

bst.o: bst.cpp bst.h
	$(CC) $(OPTIONS) bst.cpp

randbst.o: bst.h randbst.cpp randbst.h
	$(CC) $(OPTIONS) randbst.cpp

clean:
	rm -f arborist arborist.o bst.o randbst.o
