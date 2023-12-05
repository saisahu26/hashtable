/*
  Sai Sahu
  Linked List P1
  12/4/23
 */

#include <iostream>
#include <cstring>
#include "Node.h"

using namespace std;

int main () { //main function takes in values and pushes into node class and prints
  cout << "in main" << endl;
 char* fname = new char[80];
  char* lname = new char[80];
  strcpy(fname, "Sai");
   strcpy(lname, "Sahu");
   Student* st = new Student(fname,lname,4533,4);
   Node* node = new Node(st);//tests contructor
   char* fname2 = new char[80];
   char* lname2 = new char[80];
   strcpy(fname2, "Joe");
   strcpy(lname2, "Rollins");
   Student* st2 = new Student(fname2,lname2,456,2);
  Node* node2 = new Node(st2);//tests contructor
  cout << "before node call" << endl;
 node -> setNext(node2);//tests set next

    ((node) -> getStudent()) -> printStudent();//Tests get studetn and print student
   (((node) -> getNext()) ->getStudent()) -> printStudent();//tests get next
   node -> ~Node();//tests destructor
  return 0;
}

