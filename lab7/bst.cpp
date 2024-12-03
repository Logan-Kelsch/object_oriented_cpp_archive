//binary search tree function file
//Programmer: Logan Kelsch
//Date: 11/10

#include "bst.h"//binary search tree header
#include "tnode.h"//tree node header
#include <iostream>
using namespace std;
//constructor
BST::BST(){
      root=NULL;
}
//insert node public toward private function
void BST::InsertNode(){
      TNode *newNode = CreateNode();//create node data function
      Insert(newNode);
}
//create node data function
TNode *BST::CreateNode(){
      TNode *newNode = new TNode;//node constructor call
      return newNode;
}
//Delete node function, public toward search() and private
void BST::DeleteNode(){
      cout<<"\nEnter Data to Delete: ";
      int x;
      cin>>x;//data to delete insertion
      TNode *delNode;
      delNode=Search(x);//search node and search for data execution
      if(delNode==NULL)//if data not found
            cout<<"\nData not found.\n";
      else{//if data found
            DelNode(delNode);
      }
}
//Private delete function called by public delete function
//revamped, now recursive and right facing
void BST::DelNode(TNode *temp){//temp is node wanted to be deleted
  if(temp->r!=NULL){//if node has right child
    TNode *y = TSuccessor(temp);//create tmp at successor location
    temp->data = y->data;//copy over data
    DelNode(y);//call again until no right node
  }
  else{//if no right node
    if(temp->l!=NULL){//if node has left child
      TNode *y = temp->l;//create tmp at left child location
      if(temp==root){//if node to delete is the root
        y->p=NULL;//root has NULL parent
        root=y;//left child root
      } else {//if node to delete is not root
        y->p=temp->p;//left child's parents skip to grandparents
	if(temp->p->l==temp)
        	y->p->l=y;//grandparents left grandchild becomes left child
	else
		y->p->r=y;
      }
      delete temp;//deleting isolated node
    } else{//if node to delete is a leaf
      if(temp==root)//if it is only the root in the tree
        root=NULL;//assign root value to NULL
      else {//if leaf is not the root
        if(temp->p->l==temp)//if leaf is left child
          temp->p->l=NULL;//remove tree connection
        else 
          temp->p->r=NULL;//remove tree connection
      }
      delete temp;//delete isolated node
    }
  }
}
//successor function
TNode *BST::TSuccessor(TNode *tmp){
      TNode *y;// temp node to loop forward
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
TNode *BST::Max(TNode *temp){
      while(temp->r!=NULL){//while right child exists
            temp=temp->r;//move forward
      }
      return temp;
}
//Min function
TNode *BST::Min(TNode *temp){
      while(temp->l!=NULL){//while left child exists
            temp=temp->l;//move forward
      }
      return temp;
}
//in order walk function, recursive
void BST::Inorder(TNode *walk){
      if(walk!=NULL){//while exploring existing branches/leaves
            Inorder(walk->l);//check left
            walk->printNode();//print data
            Inorder(walk->r);//check right
      }
}
//in order public call function
void BST::Inorder_Walk(){
      TNode *walk = root;
      if(walk==NULL)//if empty tree
            cout<<"\nThe Tree is Empty.\n";
      else
            Inorder(walk);//call recursive private function
}
//pre order walk function, recursive
void BST::Preorder(TNode *walk){
      if(walk!=NULL){//while exploring existing branches/leaves
            walk->printNode();//print data
            Preorder(walk->l);//check left
            Preorder(walk->r);//check right
      }
}
//pre order public call function
void BST::Preorder_Walk(){
      TNode *walk = root;
      if(walk==NULL)//if tree is empty
            cout<<"\nThe Tree is Empty.\n";
      else
            Preorder(walk);//call recursive private function
}
//post order walk function, recursive
void BST::Postorder(TNode *walk){
      if(walk!=NULL){//while exploring existing branches/leaves
            Postorder(walk->l);//check left
            Postorder(walk->r);//check right
            walk->printNode();//print data
      }
}
//post order walk function, recursive 
void BST::Postorder_Walk(){
      TNode *walk = root;
      if(walk==NULL)//while explorring existing branches/leaves
            cout<<"\nThe Tree is Empty.\n";
      else
            Postorder(walk);//call recusrive private function
}
//public call function to private search function
void BST::SearchNode(){
      cout<<"\nPlease Enter Desired Data: ";
      int search;
      cin>>search;//desired data entry
      if(Search(search)!=NULL)//if data is found
            cout<<"\nData Found.\n";
      else//if data is not found
            cout<<"\nData Not Found.\n";
}
//private search function, called by public search function
TNode *BST::Search(int x){
      TNode *temp = root;
      if(temp==NULL)//if tree is empty
            return temp;
      while(temp->data!=x){//while node data is not correct data
            if(x<temp->data)//if data is less than current node data
                  temp=temp->l;//move left
            else 
                  temp=temp->r;//move right
            if(temp==NULL)//if desired data dne and function pushes out of bounds
                  return temp;
      }
      return temp;
}
//insert node function
void BST::Insert(TNode *newNode){
      TNode *y = NULL;//two seperate temp nodes
      TNode *x = root;
      while(x!=NULL){//while first node exists, initially while tree exists
            y=x;//copy temp nodes
            if(newNode->data<x->data)//if new node data is less than current node data
                  x=x->l;//move forward
            else{
                  if(newNode->data==x->data){//if data is matching (dupe found)
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
      else if(newNode->data<y->data)//otherwise, if data is less than parent
            y->l=newNode;//new data becomes left child
      else
            y->r=newNode;//otherwise, new data becomes right child
}
//clear tree function to delete entire tree data, recursive
void BST::ClearTree(TNode *temp){
      if(temp!=NULL){//if tree exists
            ClearTree(temp->l);//check left
            TNode *temp2;//create second node to backtrack
            temp2=temp->r;//second node preemptively set to right child, check walk functions
            delete temp;//delete explored data
            ClearTree(temp2);//check right
            delete temp2;//delete second temp after full exploration
      }
}
//deletion function, calls recursive cleartree function
BST::~BST(){
      ClearTree(root);//call recursive cleartree function for entire tree
      cout<<"\nThe Tree Has Been Deleted.";//notify users
}
