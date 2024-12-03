//student function file for template binary search tree
//programmer: Logan Kelsch
//Date: 11/10/23

#include"students.h"
#include<iostream>
using namespace std;
//constructor
Students::Students(){
  cout<<"\nPlease Enter First Name: ";
  cin>>firstName;//first name c string
  cout<<"\nPlease Enter Last Name: ";
  cin>>lastName;//last name c string
  cout<<"\nPlease Enter ID Number: ";
  cin>>idNumber;//student's id number
}
//print student data function
void Students::printStudent(){
  cout<<"\nID Number: "<<idNumber;//output id number
  cout<<"\nStudent Name: "<<lastName<<", "<<firstName<<endl;//output full
}
