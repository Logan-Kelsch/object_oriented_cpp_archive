//file1.cpp
//Programmer: Logan Kelsch
//Dte: 9/6/23


#include <iostream>
#include "file2.h"
using namespace std;

int main(){
	int i = 3;
	int sq;

	sq = SquareIt(i);
	cout << "Square of : << i << " is " << sq << endl;
	return 0;
}
