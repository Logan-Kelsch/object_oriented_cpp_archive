// Main cpp file for lab 6
// Programmer: Logan Kelsch
// Date: 10/27

#include "Students.h" //student header
#include "queue.h"    //queue header
#include <iostream>
using namespace std;

int main() {
  cout << "Welcome to Logan's Queue Program!\n"; // intro
  int queueType = 0;                             // binary input for queue type
  while (queueType != 1 && queueType != 2) {     // while input is invalid
    cout << "Would kind of queue would you like to make?\n\t1. Integer\n\t2. "
            "Student Data\n\n";
    cin >> queueType;
    if (queueType != 1 && queueType != 2) { // illegal input
      cout << "\nPlease enter a valid option.\n";
    }
  }
  int menuChoice = 0;  // used for individual menu use
  menu();              // this function is seen printing menu options
  switch (queueType) { // switches operation based on datatype
  case 1:
    // integer queue case
    {
      Queue<int> *intQueue = new Queue<int>; // new queue<int>
      while (menuChoice != 4) {              // while not quitting
        cin >> menuChoice;
        if (menuChoice == 1) { // enqueue function
          cout << "\nPlease enter a new integer.\n";
          int newInt; // new int to be passed into queue
          cin >> newInt;
          intQueue->enQueue(newInt); // enqueue function
        }
        if (menuChoice == 2) {       // deQueue function
          if (intQueue->isEmpty()) { // if queue is empty
            cout << "\nStack is empty.\n";
          } else {
            cout << "\n\tDeleted Data:\n\t"; // print data
            cout << intQueue->topQueue();
            intQueue->deQueue(); // then delete data
          }
        }
        if (menuChoice == 3) {       // front queue print function
          if (intQueue->isEmpty()) { // if queue is empty
            cout << "\nStack is empty.\n";
          } else { // if queue has contents
            cout << "\nThe front of the Queue is: " << intQueue->topQueue()
                 << ".\n";
          }
        }
        menu();
      }
    }
    break;
  case 2:
    // Student Data queue case
    {
      Queue<Students> *studQueue = new Queue<Students>; // new queue<students>
      while (menuChoice != 4) {
        cin >> menuChoice;
        if (menuChoice == 1) { // enqueue selection
          Students *newStud;   // new student data location placeholder
          studQueue->enQueue(*newStud);
        }
        if (menuChoice == 2) {        // deQueue function
          if (studQueue->isEmpty()) { // if queue is empty
            cout << "\nStack is empty.\n";
          } else {
            cout << "\n\tDeleted Student:"; // print first
            studQueue->topQueue().printStudent();
            studQueue->deQueue(); // then delete data
          }
        }
        if (menuChoice == 3) {        // front queue print
          if (studQueue->isEmpty()) { // if queue is empty
            cout << "\nStack is empty.\n";
          } else { // if queue has contents
            cout << "\nStudent data at the front of the queue is:\n";
            studQueue->topQueue().printStudent();
          } // print function^^
        }
        menu();
      }
    }
    break;
  }
  cout << "\n\nThank you for using my program!"; // outro
  return 0;
}
