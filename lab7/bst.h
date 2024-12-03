//binary search tree header file
//Programmer: Logan Kelsch
//Date: 11/6/23

#ifndef BST_H
#define BST_H

#include "tnode.h"//tree node inclusion, for friend class
#include<iostream>
using namespace std;
//class for binary search tree
class BST{
friend class TNode;//allow access to child/parent/data information
private:
  TNode *root;//pointer to root node
  void Insert(TNode *);//insert a new node into tree (root, new)
  TNode *CreateNode();//create a node
  TNode *Search(int);//search a node (root, data)
  void DelNode(TNode *);//delete a node from the tree
  void Inorder(TNode *);//print inorder walk, recursive
  void Preorder(TNode *);//print preorder walk, recursive
  void Postorder(TNode *);//print postorder walk, recursive
  TNode *Max(TNode *);//finds maximum of inputted tree
  TNode *Min(TNode *);//finds minimum of inputted tree
  TNode *TSuccessor(TNode *);//finds successor of inputted node
  void ClearTree(TNode *);//deletes all nodes from tree (~BST), recursive
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