//Tree node class structure
//Programmer: Logan Kelsch
//Date: 11/6/23

#ifndef TNODE_H
#define TNODE_H

template<typename DataType> class BST;
//Tree node class for each node of data in binary search tree
template <class DataType>
class TNode{
private:
  TNode<DataType> *p;//parent
  TNode<DataType> *l;//left child
  TNode<DataType> *r;//right child
  DataType data;//node data
  int dataNum;
public:
  TNode();//constructor
  void printNode();//print tree node data
  friend class BST<DataType>;//friend class of binary search tree to allow access to data
};
//menu function prototypes placed here
int menu();//print and pick func for menu
int walkMenu();//print and pick func for walk-print menu

#endif