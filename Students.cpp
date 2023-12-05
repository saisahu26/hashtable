#include <iostream>
#include <cstring>
#include "Student.h"

using namespace std;

Student::Student(char* firstnametmp, char* lastnametmp, float gpatmp, int studentIDtmp) : firstname(firstnametmp), lastname(lastnametmp), gpa(gpatmp), studentID(studentIDtmp) {} //passing all the values from student

Student::~Student() {} //creating and returning all respective function values 

char* Student::getFirstname(void) {
    return firstname;
}

char* Student::getLastname(void) {
    return lastname;
}

float Student::getGPA(void) {
    return gpa;
}

int Student::getStudentID(void) {
    return studentID;
}
void Student::printStudent(void) {
  cout << firstname << endl;
  cout << lastname << endl;
  cout << gpa << endl;
  cout << studentID << endl;
}
