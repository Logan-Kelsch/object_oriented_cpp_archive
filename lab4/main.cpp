// Main cpp file for lab 3
// programmer: Logan Kelsch
// Date: 12/6
#include "Node.h"
#include "linkedList.h"
#include <iostream>

using namespace std;

int main() {
  cout << "welcome to Logan's Lab 4!\n" << endl;
  int menuChoice; // variable to choose which menu option the user activates.
  LinkedList *Studlist = new LinkedList; // Linked List class formation
  do {
    // program user introduction/welcoming and command input
    cout << "\nWhat would you like to do?\n\n";
    cout << "\t1. Insert a Node\n\t2. Delete a Node\n\t3. Print List";
    cout << "\n\t4. Search for a Node (Prints Student Information)\n\t";
    cout << "5. Quit the Program\n\n";
    cin >> menuChoice; // inputted action
    if (menuChoice < 1 || menuChoice > 5) {
      menuChoice =
          6; // set to 6 if outside of parameter, used to loop and try again
      cout << "\nPlease enter a valid input.\n";
    }
    switch ( // switch cases used to split up each menu action
        menuChoice) {
    case 1: // insert node
    {
      Studlist->insertNode();
    } break;
    case 2: // delete node
    {
      int delID; // ID number to inset into function
      cout << "\nPlease enter the ID you would like to delete:\n\n";
      cin >> delID;
      Studlist->deleteNode(delID);
    } break;
    case 3: // print list
    {
      Studlist->printList();
    } break;
    case 4: // search for a node
    {
      int ID; // ID number to inset into function
      cout << "\nPlease enter the ID you would like to search for:\n\n";
      cin >> ID;
      Studlist->searchNode(ID);
    } break;
    case 5: // quits program and exits switch/case
      break;
    case 6: // used to re-loop upon invalid input
      break;
    }
  } while (menuChoice != 5); // while user has not requested to exit
  cout << "\nThank you for using my program!\nThe List has been destroyed.";
  return 0;
}