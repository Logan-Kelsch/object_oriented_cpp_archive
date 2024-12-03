all: prog

prog: lab5.o Stack.o Students.o
	g++ lab5.cpp Stack.cpp Students.cpp -o prog

lab5: lab5.cpp
	g++ -c lab5.cpp

Stack: Stack.cpp
	g++ -c Stack.cpp

Students: Students.cpp
	g++ -c Students.cpp

clean:
	rm -fr *o prog
