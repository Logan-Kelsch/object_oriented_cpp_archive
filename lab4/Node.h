// Node header file
// Programmer: Logan Kelsch
// Date: 12/6

#ifndef NODE_H_
#define NODE_H_

class Node { // Node class to contain student data
public:
  char lastName[20];
  char firstName[20];
  int idNumber;     // Student ID number
  Node *next;       // pointer to next student in list
  Node();           // constructor
  void printNode(); // data print
};

#endif