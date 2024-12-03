all: prog

prog: prog.o
	g++ prog.cpp -o prog

prog.o: prog.cpp
	g++ -c prog.cpp

clean:
	rm -rf *o prog
