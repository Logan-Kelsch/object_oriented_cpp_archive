all: prog

prog: lab7.o bst.o students.o tnode.o
	g++ lab7.cpp bst.cpp students.cpp tnode.cpp -o prog

lab7.o: lab7.cpp
	g++ -c lab7.cpp

bst.o: bst.cpp
	g++ -c bst.cpp

tnode.o: tnode.cpp
	g++ -c tnode.cpp

students.o: students.cpp
	g++ -c students.cpp

clear:
	rm -rf *o prog
