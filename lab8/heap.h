//heap class header file
//programmer: Logan Kelsch
//Date: 11/16/23 - 11/28/23

#ifndef HEAP_H
#define HEAP_H

//heap class
class Heap{
private:
  int A[100];//array of data, 100 is maximum heap size
  int heapSize;//size of heap
  int p(int i);//index of parent
  int l(int i);//index of left child
  int r(int i);//index of right child
  void heapify(int i);//heapify function organizes data by size/priority
  void buildHeap();//sets data in to place to be heapified
public:
  Heap();//constructor
  void insert(int a);//insert data into heap ("a")
  void heapSort();//sorts heap when unordered
  void extractMax();//prints and removes max from heap
  int maximum();//returns max from heap
  void printHeap();//prints entire heap
};
//function to print out menu options
void menu();

#endif