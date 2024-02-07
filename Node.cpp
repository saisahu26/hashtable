#include <iostream>
#include <cstring>
#include "Node.h"
//Implements Media.h

using namespace std;

Node::Node(Student* newS) //creating next node
{
  s = newS;
  next = NULL;
}

Node::~Node()
{
  delete s;
  next = NULL;
}
Student* Node::getStudent() //return student
{
  return s;
}
Node* Node::getNext() //get the node
{
  return next;
}
void Node::setNext(Node* newNext) //change node destanation
{
  
  next = newNext;
}
void Node::add(Student *st) { //add function
  
}
int Node::hash(int id) {
  return (id % studentCount);
}
