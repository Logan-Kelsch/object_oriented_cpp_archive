//Stack function file
//Programmer: Logan Kelsch
//Date: 10/23

#include "Stack.h"
#include "Students.h"
#include<iostream>
using namespace std;

//constructor
template <class DataType>
Stack<DataType>::Stack(){
  maxSize=5;//total size of stack
  top=NULL;//pointer to stack info
  numNodes=0;//number of nodes in stack
}
//destructor
template <class DataType>
Stack<DataType>::~Stack(){
  StackNode<DataType> *temp;
  if(top!=NULL){//if there are nodes
    while(temp->next!=NULL){//if there are following nodes
      temp=top;//temp follow
      top=top->next;//move forward 1
      delete temp;//delete node trail
    }
    delete temp;
  }
}
//pushes in new node data into stack
template <class DataType>
void Stack<DataType>::push(const DataType a){
  StackNode<DataType> *newNode = new StackNode<DataType>;//new node
  //no stack
  if(isEmpty()){
    if(typeid(DataType)==typeid(int))//if stack is int
      newNode->data=a;//then pass data
    newNode->next=NULL;
    top=newNode;//put on top of stack
    numNodes++;//+1 nodes
  } else
  //full stack
  if(isFull()){//stack is full
    cout<<"\n\nStack is full.\n";
    delete newNode;//save memory data
  } else {
  //non-full stack with data
    if(typeid(DataType)==typeid(int))//if stack is int
      newNode->data=a;//then pass data
    newNode->next=top;//assigning node location
    top=newNode;//assigning top node
    numNodes++;//+1 nodes in stack
  }
}
//tests for empty stack
template <class DataType>
bool Stack<DataType>::isEmpty() const{
  return top==NULL?true:false;//tests if top points to anything
}
//tests for full stack
template<class DataType>
bool Stack<DataType>::isFull() const{
  return numNodes==maxSize?true:false;//nodes=capacity?
}
//pop function pops node out of list
template<class DataType>
void Stack<DataType>::pop(){
  //empty stack
  if(isEmpty()){
    cout<<"\n\nStack is empty.\n";
  //stack with data
  } else {
    StackNode<DataType> *temp=top;
    top=top->next;//replacing data
    delete temp;//deleting removed data
    numNodes--;//-1 nodes in stack
  }
}
//topStack prints top data out
template<class DataType>
DataType Stack<DataType>::topStack() const{
  	return top->data;//return top stack data
    
}
//shows menu options
void menu(){
  cout<<"\n\nWhat would you like to do?\n\t";
  cout<< "1. Push()    : Push new data to top of stack\n\t";
  cout<< "2. Pop()     : Pop data from top of stack\n\t";
  cout<< "3. TopStack(): Display data in top of stack\n\t";
  cout<< "4. Quit Program\n\n";
}

template class Stack<Students>;//preparation for student stack
template class Stack<int>;//preperation for int stack
