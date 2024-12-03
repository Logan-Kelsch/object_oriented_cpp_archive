// Main function file - bst
// Programmer: Logan Kelsch
// Date: 11/6/23 (- 11/8/23 Finished Program 12:53AM)

#include "bst.h"//binary search tree header
#include "tnode.h"//tree node header
#include <iostream>
using namespace std;

int main() {
  std::cout << "\nWelcome to Logan's Binary Search Tree!\n\n";
  int mp = 0; // menuPick
  BST *tree = new BST;
  while (mp != 5) { // program while loop for program exit
    mp = menu();    // input menu choice
    switch (mp) {   // specific action switch case
    case 1:         // insert element
      tree->InsertNode();
      break;
    case 2: // delete element
      tree->DeleteNode();
      break;
    case 3:            // print tree
      mp = walkMenu(); // input walk print menu choice
      switch (mp) {
      case 1: // inorder walk
        // recur(go left, print, go right)
        tree->Inorder_Walk();
        break;
      case 2: // preorder walk
        // recur(print, go left, go right)
        tree->Postorder_Walk();
        break;
      case 3: // postorder walk
        // recur(go left, go right, print)
        tree->Preorder_Walk();
        break;
      case 4: // search
        // search function
        tree->SearchNode();
        break;
      }
    }
  }
  delete tree; // delete tree
}
