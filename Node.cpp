#include <iostream>
#include <cstring>
#include "Node.h"

using namespace std;

Node::Node(Student* studenttmp) : student(studenttmp) {
  nextNode = nullptr; //passing through values from Node.h
}

Node::~Node() {}

//Node setters and getters that pass through the next location
Node* Node::getNext() {
    return nextNode;
}

Student* Node::getStudent() {
    return student;
}

void Node::setNext(Node* newNode) {
  nextNode = newNode; //next node becomes the current
}
