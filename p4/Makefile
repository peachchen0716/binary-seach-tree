CC=g++
OPTIONS=-g -c
#OPTIONS =-c -O2

all: arborist

arborist: arborist.o bst.o randbst.o splay.o redblack.o
	$(CC) -o arborist arborist.o bst.o randbst.o splay.o redblack.o

arborist.o: arborist.cpp bst.h randbst.h splay.h redblack.h
	$(CC) $(OPTIONS) arborist.cpp

bst.o: bst.cpp bst.h
	$(CC) $(OPTIONS) bst.cpp

randbst.o: bst.h randbst.cpp randbst.h
	$(CC) $(OPTIONS) randbst.cpp

splay.o: bst.h splay.cpp splay.h
	$(CC) $(OPTIONS) splay.cpp

redblack.o: bst.h redblack.cpp redblack.h
	$(CC) $(OPTIONS) redblack.cpp

clean:
	rm -f arborist arborist.o bst.o randbst.o splay.o redblack.o
