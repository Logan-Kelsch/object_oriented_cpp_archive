//function file for heap class header file
//programmer: Logan Kelsch
//Date: 11/16/23 - 11/28/23

#include <iostream>
#include "heap.h"
using namespace std;
//menu print out function
void menu(){
  cout<<"\n\t1. Insert element into the heap.";
  cout<<"\n\t2. Maximum Value.";
  cout<<"\n\t3. Extract maximum element from the heap.";
  cout<<"\n\t4. Print heap.";
  cout<<"\n\t5. Heap Sort, print sorted results and exit.\n\n";
}
//constructor
Heap::Heap(){
  A[0]=4;A[1]=12;A[2]=3;A[3]=19;A[4]=23;
  A[5]=5;A[6]=32;A[7]=11;A[8]=2;A[9]=24;
  heapSize=10;
  buildHeap();
}
//heapify function, private, organizes data in heap format
void Heap::heapify(int i){
  int L=l(i);//left child temp
  int R=r(i);//right child temp
  int temp;
  int largest=i;//largest temp
  if(L<heapSize&&A[L]>A[i])//if left exists and is greater than parent
    largest=L;//left is largest
  if(R<heapSize&&A[R]>A[largest])//if right exists and is greater than largest
    largest=R;//right becomes largest
  if(largest!=i){//if largest is one of the children
    temp = A[i];//temp = parent data
    A[i]=A[largest];//swap parent and largest child data
    A[largest]=temp;
    heapify(largest);//heapify from largest data location
  }
}
//build heap funtion, organizes underganized list, private
void Heap::buildHeap(){
  for(int i = ((heapSize/2)-1);i>=0;i--){//goes down each branch of tree
    heapify(i);//heapify at every step
    printHeap();
  }
}
//insert function, public
void Heap::insert(int a){
  int i=heapSize;//size temp
  while(i>0){//while loop to check for duplicate
    i--;//-- first works since size-1 is last data point
    if(A[i]==a){//if data is duplicate, report and exit insert function
      cout<<"\nDuplicate Found. Please Try Again.\n";
      return;
    }
  }
  i=heapSize++;//reset temp value and increase size value
  while(i>0&&A[p(i)]<a){//while loop to "scoot" downward values in the heap
    A[i]=A[p(i)];
    i=p(i);
  }
  A[i]=a;//assign key value as insertion
  heapify(0);//conclude with heapify
}
//heap sort function, public
void Heap::heapSort(){
  //buildHeap();//organizes unorganized
  int temp;//temp value for swapping
  int hS = heapSize;//size temp value
  for(int i = heapSize-1;i>0;i--){//for each item in heap, from last to first (bot->top)
    temp = A[0];//swap function for root and sort varibale location
    A[0]=A[i];
    A[i]=temp;
    heapSize--;//move upward/forward in heap and repeat
    heapify(0);//finalize with heapify
  }
  heapSize = hS;
}
//extract max function, public
void Heap::extractMax(){
  heapify(0);//open with heapify to ensure easy max access
  if(heapSize<1)//if there is no heap
    cout<<"\nERROR: Heap Underflow.\n";
  else{//if there is heap
    cout<<"\nMax Removed: "<<A[0];//print out max
    A[0]=A[heapSize-1];//reassign value
    heapSize--;//decrease heap size
    heapify(0);//finalize with heapify
  }
}
//return max function, public
int Heap::maximum(){
  if(heapSize==0)//if there is no heap
    return -1;
  else//if there is a heap
    return A[0];//return top value
}
//print heap function, public
void Heap::printHeap(){
  //heapify(0);//open with heapify to ensure it is sorted
  if(heapSize>0){//if heap exists
    for(int i =0;i<heapSize;i++)//for earch heap value from greatest to least (top->bot)
      cout<<"\nData: "<<A[i];
  } else//if heap does not exist
    cout<<"\nHeap is empty.\n";
  cout<<endl;
}
//parent return function, private
int Heap::p(int i){
  if(i%2==0)//mod 2 function to find numerical value for parent
    return ((i-1)/2);
  else
    return (i/2);
}
//leftchild return function, private
int Heap::l(int i){
  return 2*i+1;//function to find numerical value for left child
}
//rightchild return function, private
int Heap::r(int i){
  return 2*i+2;//function to find numberical value for right child
}
