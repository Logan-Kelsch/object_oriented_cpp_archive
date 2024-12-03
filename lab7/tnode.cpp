//Member functions for TNode class
//Programmer: Logan Kelsch
//Date: 11/6/23

#include "tnode.h"//tree node header
#include<iostream>
using namespace std;

//Constructor
TNode::TNode(){
    p=NULL;//parent
    l=NULL;//left child
    r=NULL;//right child
    cout<<"\nEnter Data: ";
    cin>>data;//input and enter data for each tree node upon constructor call
}
//print tree node function
void TNode::printNode(){
    cout<<"\nData: "<<data<<endl;//output data in one line
}
//menu print and pick function 1 - 3, 5 is quit
int menu(){
    cout<<"\n\n1. Inset Element to the Binary Tree\n2. Delete Element from the Binary Tree\n3. Check Binary tree by printing:";
    cout<<"\n\t- Inorder Walk\n\t- Postorder Walk\n\t- Preorder Walk\n\t- Search Data\n5. Exit\n\n";
    int mp;
    cin>>mp;//menu choice input
    while(mp<1||mp>5){//input validation for menu choice
        cout<<"\nPlease Enter a Valid Input.\n";
        cout<<"\n\n1. Inset Element to the Binary Tree\n2. Delete Element from the Binary Tree\n3. Check Binary tree by printing:";
        cout<<"\n\t- Inorder Walk\n\t- Postorder Walk\n\t- Preorder Walk\n\t- Search Data\n5. Exit\n";
        cin>>mp;
    }
    return mp;
}
//walk print menu print and pick function, 1-4 , 4 is search
int walkMenu(){
    cout<<"\n\n1. Inorder Walk\n2. Postorder Walk\n3. Preorder Walk\n4. Search Data\n\n";
    int mp;//menu choice
    cin>>mp;//menu choice input
    while(mp<1||mp>4){
        cout<<"\nPlease Enter a Valid Input.\n";
        cout<<"\n\n1. Inorder Walk\n2. Postorder Walk\n3. Preorder Walk\n4. Search Data\n\n";
        cin>>mp;
    }
    return mp;
}