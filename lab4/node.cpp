// Node cpp function file
// Programmer: Logan Kelsch
// Date: 12/6

#include "Node.h"
#include <iostream>
using namespace std;

// constructor
Node::Node() {
  next = NULL; // ensures next node pointer is NULL
}

void Node::printNode() { // prints out node data
  cout << "\nID Number: " << idNumber;
  cout << "\nFirst Name: " << firstName;
  cout << "\nLast Name: " << lastName << endl;
}