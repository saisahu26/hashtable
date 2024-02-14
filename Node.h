#include <iostream>
#include <cstring>
#ifndef NODE_H
#define NODE_H
#include "student.h"
//Node class

using namespace std;

class Node {
 public:
  Node(Student* newS); //constructor
  ~Node(); //÷d?.≤estructor
   //getters
  Student* getStudent();
  void setStudentCount();
  Node* getNext();
  int hash(int id);
  Node* next;
  //setter
  void setNext(Node* newNext);
  void add(Student *st);
 protected:
  //variables
  Student* s;
  Node** hashTable;
  int studentCount;
};
#endif
