//Member functions for TNode class
//Programmer: Logan Kelsch
//Date: 11/11/23

#include "tnode.h"//tree node header
#include "students.h"//student struct header
#include<iostream>
using namespace std;

//2 constructor functions, specific to each datatype id
template <>//constructor for int tree node
TNode<int>::TNode(){
    p=NULL;//parent
    l=NULL;//left child
    r=NULL;//right child
    int data;//create data variable
    cout<<"\nEnter Data: ";
    cin>>data;//input and enter data for each tree node upon constructor call
    dataNum=data;//variable for ease of search and locating
}
template <>//constructor for Students tree node
TNode<Students>::TNode(){
  p=NULL;//parent
  l=NULL;//left child
  r=NULL;//right child
}
//2 print tree node functions for int and Students
template <>//int constructor
void TNode<int>::printNode(){
  cout<<"\nData: "<<dataNum<<endl;
}
template <>//Students constructor
void TNode<Students>::printNode(){
  data.printStudent();//call student struct function
}
//menu print and pick function 1 - 3, 5 is quit
int menu(){
    cout<<"\n\n1. Inset Element to the Binary Tree\n2. Delete Element from the Binary Tree\n3. Check Binary tree by printing:";
    cout<<"\n\t- Inorder Walk\n\t- Preorder Walk\n\t- postorder Walk\n\t- Search Data\n5. Exit\n\n";
    int mp;
    cin>>mp;//menu choice input
    while(mp<1||mp>5){//input validation for menu choice
        cout<<"\nPlease Enter a Valid Input.\n";
        cout<<"\n\n1. Inset Element to the Binary Tree\n2. Delete Element from the Binary Tree\n3. Check Binary tree by printing:";
        cout<<"\n\t- Inorder Walk\n\t- Preorder Walk\n\t- Postorder Walk\n\t- Search Data\n5. Exit\n";
        cin>>mp;
    }
    return mp;
}
//walk print menu print and pick function, 1-4 , 4 is search
int walkMenu(){
    cout<<"\n\n1. Inorder Walk\n2. Preorder Walk\n3. Postrder Walk\n4. Search Data\n\n";
    int mp;//menu choice
    cin>>mp;//menu choice input
    while(mp<1||mp>4){
        cout<<"\nPlease Enter a Valid Input.\n";
        cout<<"\n\n1. Inorder Walk\n2. Preorder Walk\n3. Postorder Walk\n4. Search Data\n\n";
        cin>>mp;
    }
    return mp;
}
//instantiation
template class TNode<Students>;
template class TNode<int>;