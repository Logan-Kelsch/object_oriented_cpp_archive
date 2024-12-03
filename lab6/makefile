all: prog

prog: lab6.o queue.o Students.o
	g++ lab6.cpp queue.cpp Students.cpp -o prog

lab6.o: lab6.cpp
	g++ -c lab6.cpp

queue.o: queue.cpp
	g++ -c queue.cpp

Students.o: Students.cpp
	g++ -c Students.cpp

clean:
	rm -rf *o prog
