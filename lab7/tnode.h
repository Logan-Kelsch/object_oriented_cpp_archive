//Tree node class structure
//Programmer: Logan Kelsch
//Date: 11/6/23

#ifndef TNODE_H
#define TNODE_H
//Tree node class for each node of data in binary search tree
class TNode{
private:
  TNode *p;//parent
  TNode *l;//left child
  TNode *r;//right child
  int data;//node data
public:
  TNode();//constructor
  void printNode();//print tree node data
  friend class BST;//friend class of binary search tree to allow access to data
};
//menu function prototypes placed here
int menu();//print and pick func for menu
int walkMenu();//print and pick func for walk-print menu

#endif