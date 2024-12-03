//queue header file
//Programmer: Logan Kelsch
//Date: 10/26

#ifndef QUEUE_H
#define QUEUE_H
//queue node to point to data and next
template<class DataType>
struct QueueNode{
  DataType data;
  QueueNode<DataType> *next;
};
//queue class to hold queue node in pointers
//and arrange nodes in queue format
template<class DataType>
class Queue{
private:
  QueueNode<DataType> *front;//node to FIFO
  QueueNode<DataType> *back;//node to LILO
  int queueSize;//size of queue
  int queueCnt;//count of data in queue
public:
  Queue();//constructor
  ~Queue();//destructor
  void enQueue(const DataType a); // add item to back of queue
  void deQueue(); // remove item from front of queue
  DataType topQueue() const; // return first item data
  bool isEmpty() const;//test for empty queue
  bool isFull() const;//test for full queue
};

void menu();//prints menu options, cout only

#endif