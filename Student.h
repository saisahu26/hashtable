#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <cstring>

using namespace std;

class Student { //student class
 public:
  Student(char* firstname, char* lastname, float gpa, int studentID); //passing all the values
        ~Student();
	//creating all functions
        char* getFirstname(void);
        char* getLastname(void);
        float getGPA(void);
        int getStudentID(void);
	void printStudent(void);
    private:
        char* firstname;
        char* lastname;
        float gpa;
        int studentID;
};

#endif
