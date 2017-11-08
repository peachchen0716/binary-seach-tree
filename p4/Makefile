CC=g++
OPTIONS=-c -O2

all: arborist

arborist: arborist.o bst.o
	$(CC) -o arborist arborist.o bst.o

arborist.o: arborist.cpp bst.h
	$(CC) $(OPTIONS) arborist.cpp

bst.o: bst.cpp bst.h
	$(CC) $(OPTIONS) bst.cpp

clean:
	rm -f arborist arborist.o bst.o
