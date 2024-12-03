// listFunc.cpp
//.cpp file for functions (for managing list)
// programmer: Logan Kelsch
// Date: 9/30 - 10/1/23

#include "link.h" //brings in node struct and func signatures.
#include <cmath>
#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;

node *createNode() {
  node *newNode = new node; // new node created
  newNode->next = NULL;     // ensures next node pointer is NULL
  ifstream indata;          // bringing in item data from outside file
  indata.open("item.txt");
  bool itemFound = false; // used to ensure the item added exists in item.txt
  int num;
  bool escapeLoop = false; // used to exit search loop under eof condition
  while (itemFound ==
         false) { // used to ensure loop of entering and finding items
    escapeLoop = false;
    indata.clear(); // 23-24 used to reset file search location upon re-entry
    indata.seekg(ios::beg);
    cout << "\n\tPlease input item number:\n\n";
    cin >> num; // entry of search number
    int in;
    // now while loop to search for item
    indata >> in;
    while (num != in &&
           !escapeLoop) { // loop to pull in new data searching for item numbers
      if (indata.eof()) { // if loop has ran to the end of the file
        cout << "\n\tItem not Found. Please try again.";
        break;
      }
      indata >> in;           // main loop function
      while (indata.fail()) { // while data pulled in is not an int (item name
                              // or letter)
        indata.clear(); // 37-38 used to discard non int input
        indata.ignore(256, '\n');
        indata >> in;       // pulling in data until int
        if (indata.eof()) { // if within this next loop, end of file is reached
          cout << "\n\tItem not Found. Please try again.";
          escapeLoop = true; // used to cancel search, as the item is not there.
          break;
        }
      }
    }
    num == in ? itemFound = true : false; // if the item is found in item.txt
  }
  // beginning of assigning item data to node for linked list compilation
  newNode->itemNum = num;      // number assignment
  indata >> newNode->itemName; // name assignment
  char itemSpec; // variable used to pull in chars representing item data
  indata >> itemSpec;
  itemSpec == 't' ? newNode->tax = 1
                  : newNode->tax = 0; // n/t are options, represent if item is taxed
  indata >> itemSpec;
  switch (itemSpec) { // s/p/n are options, represents single item, number of,
                      // pounds of.
  case 's': //-> units represent number of, s=single item
    newNode->units = 1;
    break;
  case 'p': // p=pounds of
    cout << "\nHow many pounds would you like?\n\n";
    cin >> newNode->units;
    break;
  case 'n': // n=number of
    cout << "\nHow many would you like?\n\n";
    cin >> newNode->units;
    break;
  }
  indata >> newNode->unitPrice; // pulls in unit price from item.txt
  newNode->subtotal =
      (newNode->unitPrice * newNode->units); // calculating price*number of.
  newNode->tax = round(newNode->subtotal * 6 * newNode->tax) /
                 100; // calculates tax to 2 decimals
  newNode->itemTotal =
      (newNode->subtotal + newNode->tax); // cost of item after tax
  indata.close();                         // item.txt no longer needed
  return newNode;
}

node *insertNode(node *list, node *tempNode) {
  node *tempList = list; // identical list to access and manipulate original
                         // list
  if (tempList->itemNum == -1 || tempList == NULL) { // if case for empty list
    list = tempNode; // makes new data only node in list
  } else {
    if (tempNode->itemNum < tempList->itemNum) { // if case for smallest in list
      tempNode->next = list;                     // moves one forward in list
      list = tempNode; // replaces original first node in list.
    } else {
      // while loop conditions:
      // 1. Ensure list continues
      // 2. Next itemNumber in list is less than new data.
      while (tempList->next != NULL &&
             tempList->next->itemNum < tempNode->itemNum) {
        tempList = tempList->next; // moves one forward in list to keep looking
      }
      if (tempList->next == NULL) { // if the end of the list has been reached
        tempList->next = tempNode;  // place data at end of list
      } else {                      // if an ordered spot has been found
        if (tempNode->itemNum < tempList->next->itemNum) {
          tempNode->next = tempList->next; // place list after new data
          tempList->next = tempNode;       // place smaller data before new data
        }
      }
    }
  }

  return list;
}

node *deleteNode(node *list, int ID) {
  node *tempList =list; // duplicate list created to access and manipulate original
  // if first in list is matching data
  if (list->itemNum == ID) {
    // repleaces list with list+1 to delete
    list = list->next;
  } else {
    // while loop used to find matching input data
    // refer to delete or insert function while loop for functionality
    while (tempList->next != NULL && tempList->next->itemNum != ID) {
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

void printLast(node *list, int last) { // prints data of last item added to list
  double total = 0; // creating variable for total cost of reciept
  cout << "\nItem Number         Item Name   Unit    Unit Price   Tax    "
             "Subtotal";
  cout << "\n-----------         ---------   ----    ----------   ---    "
             "--------\n";
  node *tempList = list; // duplicate list to access data
  if (tempList->itemNum == -1 || tempList == NULL) { // if list is empty
    cout << "\n\tNo items in your list!\n\n";
  } else {
    while (tempList->next != NULL) { // while loop to repeat until list ends
      cout << tempList->itemNum;  // output item infor of each item data
      cout << right << setw(27) << tempList->itemName << setw(7)
              << tempList->units << setw(14) << tempList->unitPrice << setw(6)
              << fixed << setprecision(2) << (tempList->tax) << setw(12)
              << tempList->itemTotal << endl;
      total += tempList->itemTotal; // adds item price to total
      tempList = tempList->next;    // move 1 forward in list
    }
    total += tempList->itemTotal; // adds final item price to total
    cout << tempList->itemNum; // output last data in list.
    cout << right << setw(27) << tempList->itemName << setw(7)
            << tempList->units << setw(14) << tempList->unitPrice << setw(6)
            << fixed << setprecision(2) << (tempList->tax) << setw(12)
            << tempList->itemTotal << endl;
	cout << "\n\t\tTOTAL: $" << total; // output of total price
  }
}

void printReceipt(node *list) { // prints out entire receipt and total to file
                                // "Kelsch_Logan.txt"
  ofstream outdata; // opening file to save receipt to
  outdata.open("Kelsch_Logan.txt");
  double total = 0; // creating variable for total cost of reciept
  outdata << "\nItem Number         Item Name   Unit    Unit Price   Tax    "
             "Subtotal";
  outdata << "\n-----------         ---------   ----    ----------   ---    "
             "--------\n";
  node *tempList = list; // duplicate list to access data
  if (tempList->itemNum == -1 || tempList == NULL) { // if list is empty
    outdata << "\n\tNo items in your list!\n\n";
  } else {
    while (tempList->next != NULL) { // while loop to repeat until list ends
      outdata << tempList->itemNum;  // output item infor of each item data
      outdata << right << setw(27) << tempList->itemName << setw(7)
              << tempList->units << setw(14) << tempList->unitPrice << setw(6)
              << fixed << setprecision(2) << (tempList->tax) << setw(12)
              << tempList->itemTotal << endl;
      total += tempList->itemTotal; // adds item price to total
      tempList = tempList->next;    // move 1 forward in list
    }
    total += tempList->itemTotal; // adds final item price to total
    outdata << tempList->itemNum; // output last data in list.
    outdata << right << setw(27) << tempList->itemName << setw(7)
            << tempList->units << setw(14) << tempList->unitPrice << setw(6)
            << fixed << setprecision(2) << (tempList->tax) << setw(12)
            << tempList->itemTotal << endl;
    outdata << "\n\t\tTOTAL: $" << total; // output of total price
    outdata.close();                      // file no longer needed
  }
}

void intro() { // function to clear up main, displays menu options.
  cout << "\nWhat would you like to do?\n\n";
  cout << "\t1. Add item to List\n\t2. Delete item from List";
  cout << "\n\t3. Print last item added\n\t4. Print Receipt\n\n";
}
