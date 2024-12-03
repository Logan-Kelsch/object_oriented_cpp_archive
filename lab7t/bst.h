//binary search tree header file with template
//Programmer: Logan Kelsch
//Date: 11/11/23

#ifndef BST_H
#define BST_H

#include "tnode.h"//tree node inclusion, for friend class
#include "students.h"//student struct header file
#include<iostream>
using namespace std;
//class for binary search tree with template
template <class DataType>
class BST{
friend class TNode<DataType>;//allow access to child/parent/data information
private:
  TNode<DataType> *root;//pointer to root node
  void Insert(TNode<DataType> *);//insert a new node into tree (root, new)
  TNode<DataType> *CreateNode();//create a node
  TNode<DataType> *Search(int);//search a node (root, data)
  void DelNode(TNode<DataType> *);//delete a node from the tree
  void Inorder(TNode<DataType> *);//print inorder walk, recursive
  void Preorder(TNode<DataType> *);//print preorder walk, recursive
  void Postorder(TNode<DataType> *);//print postorder walk, recursive
  TNode<DataType> *Max(TNode<DataType> *);//finds maximum of inputted tree
  TNode<DataType> *Min(TNode<DataType> *);//finds minimum of inputted tree
  TNode<DataType> *TSuccessor(TNode<DataType> *);//finds successor of inputted node
  void ClearTree(TNode<DataType> *);//deletes all nodes from tree (~BST), recursive
public:
  BST();//constructor
  ~BST();//destructor
  void InsertNode();//func to gather data and call private insert func
  void DeleteNode();//fund to gather data and call private delete func
  void SearchNode();//func to gather data and call private search func
  void Inorder_Walk();//public func to call private recursive walk func
  void Preorder_Walk();//public func to call private recursive walk func
  void Postorder_Walk();//punlic func to call private recursive walk func
};

#endif