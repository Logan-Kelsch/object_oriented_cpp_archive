//Student function file
//Programmer: Logan Kelsch
//Date: 10/27

#include "Students.h"//student header
#include<iostream>
using namespace std;
//students constructor
Students::Students(){
  cout<<"\nPlease enter the student's ID number:\n";
  cin>>idNumber;
  cout<<"\nPlease enter the first name:\n";
  cin>>firstName;
  cout<<"\nPlease enter the last name:\n";
  cin>>lastName;
}
//prints student data
void Students::printStudent(){
  cout<<"\n\nID Number: "<<idNumber;
  cout<<"\nFirst Name: "<<firstName;
  cout<<"\nLast Name: "<<lastName;
}