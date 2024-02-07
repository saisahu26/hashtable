#include <iostream>

#include <cstring>
#ifndef STUDENT_H
#define STUDENT_H
using namespace std;


class Student {
 public:
  Student(); //constructor                                                                                                                                                                            

  //constructors for all the functions                                                                                                                                                                                           
  void add(float gpa, int id, string fname, string lname);
  void print();
  int getID();
  float getGPA();
  //setter                                                                                                                                                                                                      


 protected:
  //variables
  float gpa;
  int id;
  string fname;
  string lname;
};
#endif
