//main cpp file for Heap with array (lab 8)
//programmer: Logan Kelsch
//date: 11/16/23 - 11/28/23

#include "heap.h"//heap header file, also used in heap.cpp
#include <iostream>
using namespace std;

int main() {
  cout << "Welcome to Logan's Heap Lab!\n\n";//lab welcome
  Heap *heap = new Heap;//heap initialization
  int mp=0;//menu pick
  while(mp!=5){//while the menu option is not to quit
    menu();//print menu options
    cin>>mp;//input menu choice
    switch(mp){//switch case for each menu option
      case 1:{// insert
        cout<<"\nPlease Enter Data: ";
        int insDat;//temp insert data variable
        cin>>insDat;//insert data input
        heap->insert(insDat);//insert function
      } break;
      case 2:{// return max value
        if(heap->maximum()!=-1)//if the max function returns that heap is not empty
          cout<<"\nMax Value in Heap is: "<<heap->maximum()<<endl;//print max
        else//if heap is empty
          cout<<"\nHeap is empty.\n\n";
      } break;
      case 3:{ // extract max value
        heap->extractMax();
      } break;
      case 4:{ // print heap
        heap->printHeap();
      } break;
      case 5:{ // sort heap, print heap, exit
        heap->heapSort();
        heap->printHeap();
        return 0;
      } break;
    }
  }
}
