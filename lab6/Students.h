//students header file
//Programmer: Logan Kelsch
//Date: 10/27

#ifndef STUDENTS_H
#define STUDENTS_H

//definition of the Struct Type Students
struct Students {
  char lastName[20]; // student's last name
  char firstName[20]; // student's first name
  int idNumber; // student ID
  Students(); // constructor
  void printStudent(); // print a student's information
};

#endif