//Main cpp file for lab 5
//Programmer: Logan Kelsch
//Date: 10/23

#include "Stack.h"
#include "Students.h"
#include <iostream>
using namespace std;


int main() {
  cout<<"Welcome to Logan's Stack Program!\n";//intro
  int stackType=0;//binary input for stack type
  while(stackType!=1&&stackType!=2){//while input is invalid
    cout<<"Would kind of stack would you like to make?\n\t1. Integer\n\t2. Student Data\n\n";
    cin>>stackType;
    if(stackType!=1&&stackType!=2){//illegal input
      cout<<"\nPlease enter a valid option.\n";
    }
  }
  int menuChoice=0;
  menu();//this function is seen printing menu options
  switch(stackType){
    case 1:
    //integer stack case
      {
        Stack<int>*intStack=new Stack<int>;//new stack<int>
        while(menuChoice!=4){
          cin>>menuChoice;
          if(menuChoice==1){//push function
            cout<<"\nPlease enter a new integer.\n";
            int newInt;//new int to be passed into stack
            cin>>newInt;
            intStack->push(newInt);//push function with data
          }
          if(menuChoice==2){//pop function
            intStack->pop();
          }
          if(menuChoice==3){//top stack print function
		  if(intStack->isEmpty()){//if stack is empty
			cout<<"\nStack is empty.\n";
		  } else {//if stack has contents
            cout<<"\nThe top of the stack is: "<<intStack->topStack()<<".\n";
          	}
	  }
          menu();
        }
      }
    break;
    case 2:
    //Student Data stack case
      {
        Stack<Students>*studStack = new Stack<Students>;//new stack<students>
        while(menuChoice!=4){
          cin>>menuChoice;
          if (menuChoice==1){//push selection
            Students *newStud;//new student data location placeholder
            studStack->push(*newStud);
          }
          if(menuChoice==2){//pup function
            studStack->pop();
          }
          if(menuChoice==3){//top stack function to print
		  if(studStack->isEmpty()){//if stack is empty
			cout<<"\nStack is empty.\n";
		  } else {//if stack has contents
            cout<<"\nStudent data on the top of the stack is:\n";
            studStack->topStack().printStudent();
          	}
	  }
          menu();
        }
      }
    break;
  }
  cout<<"\n\nThank you for using my program!";//outro
  return 0;
}
