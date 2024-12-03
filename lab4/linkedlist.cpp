// linkedlist cpp function file
// Programmer: Logan Kelsch
// Date: 12/6

#include "linkedList.h"
#include "Node.h"
#include <iostream>
using namespace std;

// constructor
LinkedList::LinkedList() { list = NULL; }
// destructor
LinkedList::~LinkedList() { cout << "\n\nThe list has been destroyed."; }

Node *LinkedList::createNode() {
  Node *newNode = new Node; // new node created
  newNode->next = NULL;     // ensures next node pointer is NULL
  cout << "\nEnter the Student ID Number [4 Digits]:\n\n";
  cin >> newNode->idNumber; // takes in user input ID number
  cout << "\nEnter the Student's First Name:\n\n";
  cin >> newNode->firstName; // takes in user input name
  cout << "\nEnter the Student's Last Name:\n\n";
  cin >> newNode->lastName;
  return newNode;
}

Node *LinkedList::searchLocation(int ID) {
  Node *tempList = new Node;
  tempList = list; // identical list to access and manipulate original list
  if (tempList == NULL) { // if case for empty list
  } else if (tempList->next == NULL || ID == tempList->idNumber) {
  } else {
    // while loop conditions:
    // 1. Ensure list continues
    // 2. Next ID in list is less than new data.
    while (tempList->next != NULL && tempList->next->idNumber <= ID) {
      tempList = tempList->next; // moves one forward in list to keep looking
    }
  }
  return tempList;
}

void LinkedList::insertNode() {
  Node *tempNode = new Node;
  tempNode = createNode();   // temporory new node data
  Node *tempSpot = new Node; // search location do bypass while loop
  tempSpot = searchLocation(tempNode->idNumber);
  if (tempSpot == NULL) { // NULL list
    list = tempNode;
  } else if (tempNode->idNumber < tempSpot->idNumber) {
    tempNode->next = list; // first in list case
    list = tempNode;

  } else if (tempNode->idNumber == tempSpot->idNumber) {
    cout << "\nID Number already exists.\n"; // dupe case

  } else if (tempSpot->next == NULL) {
    tempSpot->next = tempNode; // last in list case
  } else if (tempSpot->next->idNumber > tempNode->idNumber) {
    tempNode->next = tempSpot->next; // middle of list case
    tempSpot->next = tempNode;
  }
}

void LinkedList::printList() {
  if (list == NULL) { // empty list case
    cout << "\nThe list is empty.\n\n";
  } else {
    cout << "\n\tAll Student IDs:\n"; // fancy spacing
    Node *prList = new Node;
    prList = list;                 // duplicate list to access data
    while (prList->next != NULL) { // while loop to repeat until list ends
      prList->printNode();         // output data of each node
      prList = prList->next;       // move 1 forward in list
    }
    prList->printNode(); // output last data in list.
  }
}

// delete node
void LinkedList::deleteNode(int ID) {
  Node *tempList =
      list; // duplicate list created to access and manipulate original
  //if there is no list data, warn and exit
  if(list==NULL){
    cout<<"\nThe List is Empty.\n";
    return;
  }
  // if first in list is matching data
  if (list->idNumber == ID) {
    // repleaces list with list+1 to delete
    list = list->next;
  } else {
    // while loop used to find matching input data
    // refer to delete or insert function while loop for functionality
    while (tempList->next != NULL && tempList->next->idNumber != ID) {
      tempList = tempList->next;
    }
    // if the list has ended with no matching data, report missing
    if (tempList->next == NULL) {
      cout << "\nID not found in list.\n\n";
    } else {
      // otherwise list data is replaces with list+1 to delete.
      tempList->next = tempList->next->next;
    }
  }
}

// searchNode
void LinkedList::searchNode(int ID) {
  Node *tempSpot = new Node;     // location finder
  tempSpot = searchLocation(ID); // used to bypass while loop
  if (tempSpot == NULL) {        // NULL list case
    cout << "\nThere is Nothing in the List.\n";
  } else if (ID < tempSpot->idNumber) { // Before list case
    cout << "ID Not Found.\n";
  } else if (ID == tempSpot->idNumber) { // found case
    tempSpot->printNode();
  } else if (tempSpot->next == NULL) { // last in list case
    cout << "ID Not Found.\n";
  } else if (tempSpot->next->idNumber > ID) { // not found case
    cout << "ID Not Found.\n";
  }
}