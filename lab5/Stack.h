//Stack header file
//Programmer: Logan Kelsch
//Date: 10/23

#ifndef STACK_H
#define STACK_H

template <class DataType>
struct StackNode{
  DataType data; // data can be any type
  StackNode<DataType> *next; //point to the next node
};

template <class DataType>
class Stack{
private:
  StackNode<DataType> *top; // point to top of node in the stack
  int maxSize; // maximum stack size
  int numNodes; // number of nodes in the stack
public:
  Stack(); // constructor: create a stack with size x; default=10
  ~Stack(); //destructor
  bool isEmpty() const; // check if stack is empty
  bool isFull() const; // check if stack is full
  void push(const DataType a); // push a node onto the top of the stack
  void pop(); // pop a node from the top of stack
  DataType topStack() const; // return data from the top of the stack
};

void menu();

#endif
