all: Myprog

Myprog: linkedlist.o linkFun.o
	g++ linkedlist.o linkFun.o -o Myprog

linkedlist.o: linkedlist.cpp
	g++ -c linkedlist.cpp

linkFun.o: linkFun.cpp
	g++ -c linkFun.cpp

clean:
	rm -rf *o Myprog

