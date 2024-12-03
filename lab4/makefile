all: prog

prog: main.o linkedlist.o node.o
	g++ main.cpp linkedlist.cpp node.cpp -o prog

main.o: main.cpp
	g++ -c main.cpp

linkedlist.o: linkedlist.cpp
	g++ -c linkedlist.cpp

node.o: node.cpp
	g++ -c node.cpp

clear:
	rm -rf *o prog
