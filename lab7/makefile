all: prog

prog: lab7.o bst.o tnode.o
	g++ lab7.o bst.o tnode.o -o prog

lab7.o: lab7.cpp
	g++ -c lab7.cpp

bst.o: bst.cpp
	g++ -c bst.cpp

tnode.o: tnode.cpp
	g++ -c tnode.cpp

clean:
	rm -rf *o prog
