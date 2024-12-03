// grocList.cpp
// main .cpp file
// programmer: Logan Kelsch
// Date: 9/30 - 10/1/23

#include "link.h" //header file connection
#include <iostream>
using namespace std;

int main() {
  int menuChoice; //('1'-'4' expected) used for menu choice (4 quits program)
  int lastAdded =
      -1; // integer to keep track of last item added to list for func 3
  cout << "Welcome To Logan's Grocery Receipt System!\n\n";
  node *list = new node; // new blank list of item data
  list->itemNum = -1;    // sets default value to ensure no error
  do {
    intro(); // function to output menu options
    cin >> menuChoice;
    if (menuChoice < 1 || menuChoice > 4) {
      menuChoice = 5; // forces re-entry of command and mentions user error.
      cout << "\nPlease enter a valid input.\n";
    }
    switch ( // switch cases used to split up each menu action
        menuChoice) {
    case 1: // insert item into list
    {
      node *tempNode = new node; // creates blank data
      tempNode = createNode();   // function fills blank data via user input
      lastAdded = tempNode->itemNum;
      list = insertNode(list,
                        tempNode); // function updates list data with new data
      break;
    }
    case 2: // delete node
    {
      cout << "\nEnter the ID number you would like to delete:\n\n";
      int delNum; // requested item number to delete
      cin >> delNum;
      list =
          deleteNode(list, delNum); // function replaces list with removed data
    } break;
    case 3: // print Last Item entered
    {
      printLast(list, lastAdded);
    } break;
    case 4: // print receipt
    {
      printReceipt(list);
    } break;
    }
  } while (menuChoice != 4); // while user has not requested to exit
  cout << "\nThank you for using my program!";
  return 0;
}