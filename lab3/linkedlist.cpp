// LinkedList.cpp
// programmer: Logan Kelsch
// Date: Finished 9/26/23

#include "link.h"
#include <iostream>

using namespace std;

int main() {
  int menuChoice; //('1'-'4' expected) used for menu choice (5 quits program)
  cout << "Welcome To Logan's Sorted Student Database!\n\n";
  node *list = new node;//new blank list of user data
  list->idNumber = -1;//sets default value to ensure no error
  do {
    // program user introduction/welcoming and command input
    cout << "\nWhat would you like to do?\n\n";
    cout << "\t1. Insert a Node\n\t2. Delete a Node\n\t3. Print List";
    cout << "\n\t4. Search for a Node (Prints Student Information)\n\t";
    cout << "5. Quit the Program\n\n";
    cin >> menuChoice;//inputted action
    if (menuChoice < 1 || menuChoice > 5) {
      menuChoice = 6;//set to 6 if outside of parameter, used to loop and try again
      cout << "\nPlease enter a valid input.\n";
    }
    switch (// switch cases used to split up each menu action
        menuChoice) { 
    case 1:           // insert node
    {
      node *tempNode = new node;//creates blank data
      tempNode = createNode();//function fills blank data via user input
      list = insertNode(list, tempNode);//function updates list data with new data
      break;
    }
    case 2: // delete node
    {
      cout << "\nEnter the ID number you would like to delete:\n\n";
      int delNum;//requested ID number to delete
      cin >> delNum;
      list = deleteNode(list, delNum);//function replaces list with removed data
    } break;
    case 3: // print list
    {
      printList(list);//function outputs list of all student IDs to console
    } break;
    case 4: // search for a node
    {
      cout << "\nEnter the ID number you would like to find:\n\n";
      int findNum;//requested ID number to find data for
      cin >> findNum;
      list = searchNode(list, findNum);//function finds data and outputs name+ID
    } break;
    case 5: // quits program and exits switch/case
      break;
    case 6: // used to re-loop upon invalid input
      break;
    }
  } while (menuChoice != 5);//while user has not requested to exit
  cout<<"\nThank you for using my program!";
  return 0;
}