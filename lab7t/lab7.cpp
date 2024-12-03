// Main function file - bst with template
// Programmer: Logan Kelsch
// Date: 11/11/23

#include "bst.h"   //binary search tree header
#include "tnode.h" //tree node header
#include <iostream>
using namespace std;

int main() {
  std::cout << "\nWelcome to Logan's Binary Search Tree With Template!\n\n";
  int treeType; // int or student tree pick
  cout << "\nPlease Enter Tree Type: \n\t1. Int Tree\n\t2. Student Tree\n\n";
  cin >> treeType;
  int mp = 0; // menuPick
  BST<int> *intTree =
      new BST<int>; // creation of both trees for simplicity of this cpp file
  BST<Students> *studTree = new BST<Students>;
  // treetype 1 = int tree, 2 = student tree
  // this cpp file calls functions accordingly
  while (mp != 5) { // program while loop for program exit
    mp = menu();    // input menu choice
    switch (mp) {   // specific action switch case
    case 1:         // insert element
      treeType == 1 ? intTree->InsertNode() : studTree->InsertNode();
      break;
    case 2: // delete element
      treeType == 1 ? intTree->DeleteNode() : studTree->DeleteNode();
      break;
    case 3:            // print tree
      mp = walkMenu(); // input walk print menu choice
      switch (mp) {
      case 1: // inorder walk
              // recur(go left, print, go right)
        treeType == 1 ? intTree->Inorder_Walk() : studTree->Inorder_Walk();
        break;
      case 2: // preorder walk
              // recur(print, go left, go right)
        treeType == 1 ? intTree->Preorder_Walk() : studTree->Preorder_Walk();
        break;
      case 3: // postorder walk
              // recur(go left, go right, print)
        treeType == 1 ? intTree->Postorder_Walk() : studTree->Postorder_Walk();
        break;
      case 4: // search
              // search function
        treeType == 1 ? intTree->SearchNode() : studTree->SearchNode();
        break;
      }
    }
  }
  delete intTree; // delete int tree
  delete studTree; // delete students tree
}