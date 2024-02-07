#include <iostream>
#include "student.h"
#include <cstring>

using namespace std;

Student :: Student() { //all the objects within the student class
  gpa = 0;
  id = 0;
  fname = "";
  lname = "";
}

void Student:: add(float newgpa, int newid, string newf, string newl) { //copying the data passed in onto a new set
  gpa = newgpa;
  id = newid;
  fname = newf;
  lname = newl;
 
}

void Student:: print() { //when print is called, print all the objects
  cout  << " gpa  " << gpa << endl;
  cout << " id " << id << endl;
  cout << " first name " << fname << endl;
  cout << " last name " << lname << endl;
}
int Student :: getID() { //when called, return the ID
  return id;
}

float Student :: getGPA() {
  return gpa;
}
