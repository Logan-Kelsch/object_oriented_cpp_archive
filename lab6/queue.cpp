// queue function file
// Programmer: Logan Kelsch
// Date: 10/26

#include "queue.h"    //queue header
#include "Students.h" //student header
#include <iostream>
using namespace std;

// constructor
template <class DataType> Queue<DataType>::Queue() {
  front = NULL; // both pointers null
  back = NULL;
  queueSize = 5; // queue size 5 default
  queueCnt = 0;  // no data to start
};
// destructor
template <class DataType> Queue<DataType>::~Queue() {
  QueueNode<DataType> *temp = front; // temp data to follow and delete
  if (isEmpty()) {                   // empty queue case
    delete temp;
  } else if (front == back) { // single data in queue case
    delete front;
    delete temp;
  } else {
    while (front->next != NULL) { //>1 data in queue case
      front = front->next;
      delete temp;
      temp = front;
    }
    delete temp; // same as front and back data on this line
  }
};
// enqueue func, adds data to queue
template <class DataType> void Queue<DataType>::enQueue(const DataType a) {
  if (isFull()) // full case, no input
    cout << "\n\nQueue is full.\n";
  else { // new node created
    QueueNode<DataType> *newNode = new QueueNode<DataType>;
    if (typeid(DataType) == typeid(int)) // if int queue
      newNode->data = a;                 // pass inputted data
    if (isEmpty()) {                     // if empty queue
      front = newNode;                   // data is now front and back
      back = newNode;
    } else { // else put on back of queue
      back->next = newNode;
      back = newNode;
    }
    queueCnt++; // successful data add, uptick in data count
  }
};
// dequeue func, prints and deletes data, no confirmation
template <class DataType> void Queue<DataType>::deQueue() {
  if (isEmpty()) { // empty case, do nothing
    cout << "\n\nQueue is empty.\n";
  } else { // single data case, delete only data (front and back)
    if (front == back) {
      delete front;
      front = NULL;
      back = NULL;
    } else { //>1 data case, delete front and advance front
      QueueNode<DataType> *temp = front;
      front = front->next;
      delete temp;
    }
    queueCnt--; // successful data deletion, downtick in count
  }
};
// topqueue func, returns front of queue data
template <class DataType> DataType Queue<DataType>::topQueue() const {
  return front->data; // return front data, not called if empty
};
// isempty function tests for empty queue
template <class DataType> bool Queue<DataType>::isEmpty() const {
  return queueCnt == 0 ? true : false; // if count system = 0 data
};
// isfull func tests for full queue
template <class DataType> bool Queue<DataType>::isFull() const {
  return queueCnt == queueSize ? true : false; // if data count = maximum
};
// shows menu options, no input here, only cout funcs
void menu() {
  cout << "\n\nWhat would you like to do?\n\t";
  cout << "1. enQueue()     :  Add item to back of Queue\n\t";
  cout << "2. deQueue()     : Remove item from front of Queue\n\t";
  cout << "3. TopQueue(): Return value of first item in Queue\n\t";
  cout << "4. Quit Program\n\n";
}
template class Queue<Students>; // prep program for student queue
template class Queue<int>;      // prep program for int queue