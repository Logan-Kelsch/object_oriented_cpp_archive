//binary search tree function file
//Programmer: Logan Kelsch
//Date: 11/11

#include "bst.h"//binary search tree header
#include "tnode.h"//tree node header
#include "students.h"//student header
#include <iostream>
using namespace std;
//constructor
template <class DataType>
BST<DataType>::BST(){
      root=NULL;
}
//insert node public toward private function
template <class DataType>
void BST<DataType>::InsertNode(){
      TNode<DataType> *newNode = CreateNode();//create node data function
      Insert(newNode);
}
//2 create node data functions
template <>//int specific function
TNode<int> *BST<int>::CreateNode(){
      TNode<int> *newNode = new TNode<int>;//node constructor call
      return newNode;
}
template <>//student specific function
TNode<Students> *BST<Students>::CreateNode(){
  TNode<Students> *newNode = new TNode<Students>;//node constructor call
  newNode->dataNum=newNode->data.idNumber;
  return newNode;
}
//Delete node function, public toward search() and private
template <class DataType>
void BST<DataType>::DeleteNode(){
      cout<<"\nEnter Data to Delete: ";
      int x;
      cin>>x;//data to delete insertion
      TNode<DataType> *delNode;
      delNode=Search(x);//search node and search for data execution
      if(delNode==NULL)//if data not found
            cout<<"\nData not found.\n";
      else{//if data found
            DelNode(delNode);
      }
}
//Private delete function called by public delete function
//recreated 11/9, made recursive and custom by Logan Kelsch
//right size / successor heavy
//copy data on right, shift pointers on left
template <class DataType>
void BST<DataType>::DelNode(TNode<DataType> *temp){
  if(temp->r!=NULL){//if node has right child data
    TNode<DataType> *y = TSuccessor(temp);//create temp node at successor location
    temp->data = y->data;//copy data from successor
    temp->dataNum = y->dataNum;//cont.
    DelNode(y);//call recursive function, left child impossible, goes until leaf
  }
  else{//if node is without right child data
    if(temp->l!=NULL){//if node has left child data
      TNode<DataType> *y = temp->l;//create temp to hold left child location
      if(temp==root){//if node to delete is the root
        y->p=NULL;//reassign pointers
        root=y;//reasing root location
      } else {//if node is not root
        y->p=temp->p;//reassign parent node to skip temp
	if(temp->p->l==temp)
        	y->p->l=y;//reassign parent's left child data to isolate temp entirely
	else
		y->p->r=y;
      }
      delete temp;//delete temp after isolation
    } else{//no left or right node data (is leaf)
      if(temp==root)//if node is root and is leaf
        root=NULL;//remove root location
      else {//if node is not root, but is leaf
        if(temp->p->l==temp)//if node is leaf and left child
          temp->p->l=NULL;//reassign parents left child location
        else //if node is leaf and right child
          temp->p->r=NULL;//reassign parents right child location
      }
      delete temp;//delete isolated node
    }
  }
}
//successor function
template <class DataType>
TNode<DataType> *BST<DataType>::TSuccessor(TNode<DataType> *tmp){
      TNode<DataType> *y;// temp node to loop forward
      if(tmp->r!=NULL){//if right child exists
            tmp=tmp->r;//move forward
            return Min(tmp);//find smallest value within subtree
      }
      else{//if right child does not exist
            y=tmp->p;//y temp becomes parent of node
            while(y!=NULL&&tmp==y->r){//while temp is not parent and is right child
                  tmp=y;
                  y=y->p;
            }
      }
      return tmp;
}
//Max function
template <class DataType>
TNode<DataType> *BST<DataType>::Max(TNode<DataType> *temp){
      while(temp->r!=NULL){//while right child exists
            temp=temp->r;//move forward
      }
      return temp;
}
//Min function
template <class DataType>
TNode<DataType> *BST<DataType>::Min(TNode<DataType> *temp){
      while(temp->l!=NULL){//while left child exists
            temp=temp->l;//move forward
      }
      return temp;
}
//in order walk function, recursive
template <class DataType>
void BST<DataType>::Inorder(TNode<DataType> *walk){
      if(walk!=NULL){//while exploring existing branches/leaves
            Inorder(walk->l);//check left
            walk->printNode();//print data
            Inorder(walk->r);//check right
      }
}
//in order public call function
template <class DataType>
void BST<DataType>::Inorder_Walk(){
      TNode<DataType> *walk = root;
      if(walk==NULL)//if empty tree
            cout<<"\nThe Tree is Empty.\n";
      else
            Inorder(walk);//call recursive private function
}
//pre order walk function, recursive
template <class DataType>
void BST<DataType>::Preorder(TNode<DataType> *walk){
      if(walk!=NULL){//while exploring existing branches/leaves
            walk->printNode();//print data
            Preorder(walk->l);//check left
            Preorder(walk->r);//check right
      }
}
//pre order public call function
template <class DataType>
void BST<DataType>::Preorder_Walk(){
      TNode<DataType> *walk = root;
      if(walk==NULL)//if tree is empty
            cout<<"\nThe Tree is Empty.\n";
      else
            Preorder(walk);//call recursive private function
}
//post order walk function, recursive
template <class DataType>
void BST<DataType>::Postorder(TNode<DataType> *walk){
      if(walk!=NULL){//while exploring existing branches/leaves
            Postorder(walk->l);//check left
            Postorder(walk->r);//check right
            walk->printNode();//print data
      }
}
//post order walk function, recursive
template <class DataType>
void BST<DataType>::Postorder_Walk(){
      TNode<DataType> *walk = root;
      if(walk==NULL)//while explorring existing branches/leaves
            cout<<"\nThe Tree is Empty.\n";
      else
            Postorder(walk);//call recusrive private function
}
//public call function to private search function
template <class DataType>
void BST<DataType>::SearchNode(){
      cout<<"\nPlease Enter Desired Data: ";
      int search;
      cin>>search;//desired data entry
      if(Search(search)!=NULL)//if data is found
            cout<<"\nData Found.\n";
      else//if data is not found
            cout<<"\nData Not Found.\n";
}
//private search function, called by public search function
template <class DataType>
TNode<DataType> *BST<DataType>::Search(int x){
      TNode<DataType> *temp = root;
      if(temp==NULL)//if tree is empty
            return temp;
      while(temp->dataNum!=x){//while node data is not correct data
            if(x<temp->dataNum)//if data is less than current node data
                  temp=temp->l;//move left
            else 
                  temp=temp->r;//move right
            if(temp==NULL)//if desired data dne and function pushes out of bounds
                  return temp;
      }
      return temp;
}
//insert node function
template <class DataType>
void BST<DataType>::Insert(TNode<DataType> *newNode){
      TNode<DataType> *y = NULL;//two seperate temp nodes
      TNode<DataType> *x = root;
      while(x!=NULL){//while first node exists, initially while tree exists
            y=x;//copy temp nodes
            if(newNode->dataNum<x->dataNum)//if new node data is less than current node data
                  x=x->l;//move forward
            else{
                  if(newNode->dataNum==x->dataNum){//if data is matching (dupe found)
                        cout<<"\nData Already Exists.\n";
                        delete newNode;//delete new data, cannot insert
                        return;
                  }
                  x=x->r;//move one forward right
            }
      }
      newNode->p=y;//setting parents of new data with first temp node
      if(y==NULL)//if new data will be root
            root=newNode;//new data becomes root
      else if(newNode->dataNum<y->dataNum)//otherwise, if data is less than parent
            y->l=newNode;//new data becomes left child
      else
            y->r=newNode;//otherwise, new data becomes right child
}
//clear tree function to delete entire tree data, recursive
template <class DataType>
void BST<DataType>::ClearTree(TNode<DataType> *temp){
      if(temp!=NULL){//if tree exists
            ClearTree(temp->l);//check left
            TNode<DataType> *temp2;//create second node to backtrack
            temp2=temp->r;//second node preemptively set to right child, check walk functions
            delete temp;//delete explored data
            ClearTree(temp2);//check right
            delete temp2;//delete second temp after full exploration
      }
}
//deletion function, calls recursive cleartree function
template <class DataType>
BST<DataType>::~BST(){
      ClearTree(root);//call recursive cleartree function for entire tree
      cout<<"\nThe Tree Has Been Deleted.";//notify users
}

template class BST<int>;
template class BST<Students>;
