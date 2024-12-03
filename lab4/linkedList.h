// linkedlist header file
// Programmer: Logan Kelsch
// Date: 12/6

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include "Node.h" //bring in node class data

class LinkedList { // list to contain student information
private:
  Node *list = new Node;        // pointer list
  Node *createNode();           // creates node to be used in list
  Node *searchLocation(int ID); // searches list for location utility
public:
  LinkedList();            // list constructor
  ~LinkedList();           // list destructor
  void insertNode();       // adds node data to list, avoids dupe
  void deleteNode(int ID); // searches and deletes node data
  void printList();        // prints out list data
  void searchNode(int ID); // searches and prints node data
};
#endif
