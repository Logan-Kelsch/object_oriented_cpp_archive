//student header for template binary search tree
//programmer: Logan Kelsch
//Date: 11/10/23

#ifndef STUDENTS_H
#define STUDENTS_H
//struct for student data
struct Students{
  char lastName[20];//last name
  char firstName[20];//first name
  int idNumber;//id number
  Students();//constructor
  void printStudent();//function to print student data
};

#endif