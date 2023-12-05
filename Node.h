#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <cstring>
#include "Student.h"

class Node { //var names from Nikaansh S.
    public:
        Node(Student*); // creating the node from a student
        ~Node(); // destructor for the node
        Node* getNext(); // returns the pointer 
        Student* getStudent(); // returns the pointer to following student
        void setNext(Node*); // sets the pointer to the next node for linked list
    private:

        Node* nextNode; // pointer to the next node 
        Student* student; // pointer to the student 
};

#endif

