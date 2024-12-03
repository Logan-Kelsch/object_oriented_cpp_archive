// link.h
// header file for node
// Programmer: Logan Kelsch
// Date: 9/30 - 10/1/23

#ifndef LINK_H_
#define LINK_H_

struct node { // node structure to contain individual item info
  // example of item file input format:
  // 33 Avocado n/t n/p/s 0.99
  int itemNum;       // item number in file
  char itemName[40]; // item name
  double units;      // number of units or pounds.
  double unitPrice;  // price per unit or pound
  double tax;        // total item tax of amount purchased
  double subtotal;   // total item cost pre tax
  double itemTotal;  // total item cost post tax
  node *next;        // points to next item in linked list
};

node *createNode(); // used to generate node and gather information from user.
node *insertNode(node *, node *); // inserts new data to list, maintains order.
node *deleteNode(node *, int); // removes individual user data from linked list.
void printReceipt(node *);     // prints out final list of all items
void printLast(node *, int);   // prints out last item added to list.
void intro();                  // prints out menu options

#endif