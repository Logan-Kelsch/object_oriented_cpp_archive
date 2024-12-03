all: myprog

myprog: grocList.o listFunc.o
	g++ grocList.o listFunc.o -o myprog

grocList.o: grocList.cpp
	g++ -c grocList.cpp

listFunc.o: listFunc.cpp
	g++ -c listFunc.cpp

clean:
	rm -rf *o myprog
