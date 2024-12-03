// link.h
// header file for node
// Programmer: Logan Kelsch
// Date: 9/22/23-9/26/23

#ifndef LINK_H_
#define LINK_H_

struct node { // node structure to contain individual user info
  char firstName[20];
  char lastName[20];
  int idNumber;
  node *next; // points to next user in linked list
};

node *createNode(); // used to generate node and gather information from user.
node *insertNode(node *, node *); // inserts new data to list, maintains order.
node *searchNode(node *, int);    // checks list for user data.
node *deleteNode(node *, int); // removes individual user data from linked list.
void printList(node *);        // prints out list of all user ID numbers

#endif