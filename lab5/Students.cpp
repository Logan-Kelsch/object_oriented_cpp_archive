//Student function file
//Programmer: Logan Kelsch
//Date: 10/23

#include "Students.h"
#include<iostream>
using namespace std;


Students::Students(){
  cout<<"\nPlease enter the student's ID number:\n";
  cin>>idNumber;
  cout<<"\nPlease enter the first name:\n";
  cin>>firstName;
  cout<<"\nPlease enter the last name:\n";
  cin>>lastName;
}


//consider creating "Create student" function
void Students::printStudent(){
  cout<<"\n\nID Number: "<<idNumber;
  cout<<"\nFirst Name: "<<firstName;
  cout<<"\nLast Name: "<<lastName;
}