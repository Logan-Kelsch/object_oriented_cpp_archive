// linkFun.cpp
//.cpp file for functions (for managing linked list)
// programmer: Logan Kelsch
// Date: 9/22/23-9/26/23

#include "link.h" //brings in node struct and func signatures.
#include <iostream>

using namespace std;

node *createNode() {
  node *newNode = new node; // new node created
  newNode->next = NULL;     // ensures next node pointer is NULL
  cout << "\nEnter the Student ID Number [4 Digits]:\n\n";
  cin >> newNode->idNumber; // takes in user input ID number
  cout << "\nEnter the Student's First Name:\n\n";
  cin >> newNode->firstName; // takes in user input name
  cout << "\nEnter the Student's Last Name:\n\n";
  cin >> newNode->lastName;
  return newNode;
}

node *insertNode(node *list, node *tempNode) {
  node *tempList = list; // identical list to access and manipulate original
                         // list
  if (tempList->idNumber == -1) { // if case for empty list
    list = tempNode;              // makes new data only node in list
  } else {
    if (tempNode->idNumber <
        tempList->idNumber) { // if case for smallest in list
      tempNode->next = list;  // moves one forward in list
      list = tempNode;        // replaces original first node in list.
    } else {
      // while loop conditions:
      // 1. Ensure list continues
      // 2. Next ID in list is less than new data.
      while (tempList->next != NULL &&
             tempList->next->idNumber < tempNode->idNumber) {
        tempList = tempList->next; // moves one forward in list to keep looking
      }
      if (tempList->next == NULL) { // if the end of the list has been reached
        tempList->next = tempNode;  // place data at end of list
      } else {                      // if an ordered spot has been found
        	if(tempNode->idNumber==tempList->idNumber){
			//output the number already exists in the list
			cout<<"\nDuplicate Input found.\nPlease try again.\n";
		} else {
	      		if (tempNode->idNumber < tempList->next->idNumber) {
          		tempNode->next = tempList->next; // place list after new data
          		tempList->next = tempNode;       // place smaller data before new data
        		}
		}
      }
    }
  }
  return list;
}

node *searchNode(node *list, int ID) {

  node *tempList = list; // duplicate list used to access and manipulate
                         // original
  if (tempList->idNumber == ID) {
    // display first node's data
    cout << "\n\tStudent Data:\n\n\tID #: " << tempList->idNumber;
    cout << "\n\tFirst Name: " << tempList->firstName;
    cout << "\n\tLast Name:  " << tempList->lastName;
    cout << endl << endl;
  } else {
    // while loops to look for matching data under inputted node's idNumber
    // value refer to previous function "insertNode" for functionality
    while (tempList->next != NULL && tempList->idNumber != ID) {
      tempList = tempList->next;
    }
    if (tempList->idNumber == ID) {
      // display found node's data
      cout << "\n\tStudent Data:\n\n\tID #: " << tempList->idNumber;
      cout << "\n\tFirst Name: " << tempList->firstName;
      cout << "\n\tLast Name:  " << tempList->lastName;
      cout << endl << endl;
    } else
      // if matching idNumber is not found
      cout << "\nId not found in list.\n\n";
  }
  return list;
}

node *deleteNode(node *list, int ID) {

  node *tempList =
      list; // duplicate list created to access and manipulate original
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
      cout << "ID not found in list.\n\n";
    } else {
      // otherwise list data is replaces with list+1 to delete.
      tempList->next = tempList->next->next;
    }
  }
  return list;
}

void printList(node *list) {
  cout << "\n\tAll Student IDs:\n\n";   // fancy spacing
  node *tempList = list;                // duplicate list to access data
  while (tempList->next != NULL) {      // while loop to repeat until list ends
    cout << tempList->idNumber << endl; // output idNumber of each node data
    tempList = tempList->next;          // move 1 forward in list
  }
  cout << tempList->idNumber << endl; // output last data in list.
}
