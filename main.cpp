/*
  saikapish sahu
  linked list 2
  1/3/24
 */
#include <iomanip>
#include <iostream>
#include <cstring>
#include "student.h"
#include "Node.h"
#include <math.h>

using namespace std;
Node **table = NULL;
Node *root = NULL;
void printNode(Node *temp);
Node *deleteNode(Node *current, int enterId) ;
double findAverage(Node *temp, double sum, int count);
Node *addNode(Node *current, Student *newNode) ;
bool nodeFound = false;
float readGpa();
int readStudentId();
int studentCount = 0;
int main() {
  // recursion();
   char entry;
  int count = 0;
  // Node *root;
  Node *previous;
 
  cin >> studentCount;
  table = new Node * studentCount;
  for (int i = 0; i < studentCount; i++ ) {
    table[i] = NULL;
  }
  while (true) { //while loop to continue to ask for what to do
    cout << " add ('a') or delete ('d') or print ('p') average ('v') " << endl;
    cin >> entry;
    //creating the objects in meain
    int key = 0;
    float gpa;
    int id;
    string input = "";
    string fname;
    string lname;
    if (entry == 'a') {
      cout << " Add student record " << endl;
      Student *st = new Student; //create new pointer to student
      
      gpa = readGpa();
      id = readStudentId();

      cout << " Enter Student First name " << endl; 
      cin >> fname;
      cout << " Enter Student Last name " << endl; 
      cin >> lname;


      float preGPA;
      cout << "GPA is set precision to 3 " << setprecision(3) << endl;
      
      preGPA = gpa; 
      
      cout << " set precision value " << gpa << endl;
      st->add(preGPA, id, fname, lname); //add this into the list
      key = hash(id);
      table[key]  = addNode(table[key], st);//create a root
  }
    else if (entry == 'd') {
      cout << "enter student id delete" << endl;
      Node *temp = root; //create a temp to hold the root
      int enterId; //enter the id to be deleted
      cin >>  enterId ;
      root = deleteNode(temp, enterId); //call the function passing in the temp and the id
      if (nodeFound == false) { //if the node is deleted then make sure to continue, if wrong id is sent then prompt
	cout <<"id not found" << endl;
      }
      else {
	nodeFound = false;
      }
    }
    else if (entry == 'p') {

      Student *sTemp; //pointer to student class
      Node *temp = root; //pointer to node which is root
      printNode(temp); //call print function
      }
    else if (entry == 'v') {

      double avg = 0;
      Node *temp = root; //pointer to node which is root
      avg = findAverage(temp,0,0); //call print function

      if (avg != 0 ) {

          cout << " Average student GPA  = " << avg << endl;
      }
      else {

          cout << " No student list empty " << endl;
      }
    } 
    else {
      cout <<"invalid entry" << endl;
    }
      

 

    }

  return 0;
}

int hash (int id) {
  return (id % studentCount);
}

int readStudentId() { //this is for reading in id
 int i = 0;
 string userInput ;
 size_t pos;

 while (1) { //while running make sure that the id is a number or else an error will be given

    cout << "Enter Student ID " << endl;

    if (!getline(cin,userInput))
    {

        throw runtime_error(" user input not expected \n ");
    }

    try {//try catch for an error statement

      i = stoi(userInput, &pos);  

    }
    catch (invalid_argument&) {

       cout << " Unable to convert the input to int" << endl;
       continue;
    }
    catch (out_of_range&) {
       cout << " out of boundry error, enter the GPA again " << endl; 
       continue;

    }


    bool whiteSpaceFound = false;
    for (;pos < userInput.length(); pos++) {

        if (!isspace(static_cast<char>(userInput[pos]))) {

           cout << " invalid input, try re-entering GPA " << endl;
           whiteSpaceFound = true;
           break;
    
        }

    }


    if (whiteSpaceFound == true) {
       continue;
    }
    return i;
    
 }
}


float readGpa() {//the same will go for GPA as ID 
 float i = 0;
 string userInput, dummy ;
 size_t pos;

 cout << "Enter Student GPA " << endl;
 getline(cin,dummy);
 
 
 while (1) {


    if (!getline(cin,userInput))
    {

        throw runtime_error(" user input not expected \n ");
    }

    try {

      i = stof(userInput, &pos);  

    }
    catch (invalid_argument&) {

       cout << " Unable to convert the input to float " << endl;
       continue;
    }
    catch (out_of_range&) {
       cout << " out of boundry error, enter the GPA again n " << endl; 
       continue;

    }


    bool whiteSpaceFound = false;
    for (;pos < userInput.length(); pos++) {

        if (!isspace(static_cast<char>(userInput[pos]))) {

           cout << " invalid input, try re-entering GPA " << endl; 
           whiteSpaceFound = true;
           break;
    
        }

    }


    if (whiteSpaceFound == true) {
       continue;
    }

    if ((i > 10 ) || ( i < 0)) {
      
       cout << " GPA has to be between greater then 0 and less then 10 " << endl;
       continue;

       
    }
    return i;
    
 }
}


double findAverage(Node *temp, double sum, int count) { 

    Student *sTemp; //create a temp student

    if (temp == NULL) {
     if (count == 0) {
        cout << " end of list " << endl;
        return 0;
     }
     return (sum / count); // call the getGPA function and get GPA 

    }
    else {
      sTemp = temp->getStudent();        //get the student record                                                                                                                                                                    
      return  findAverage(temp->getNext(), sum + sTemp->getGPA(), count + 1);  //keep on printing the nodes
    }
}

Node *addNode(Node *head, Student *st) {

  
  if (head == NULL) { //if there is no head
    Node *current = new Node(st); //return this to become the head
      return current;
   }

   else { 
   
   Student *sTemp;
   sTemp = head->getStudent(); //temp hold of the head
   int tempId;
   tempId = sTemp->getID(); //id of the head

   if (!(tempId < st->getID())) { //if the id is less than the hea dmove it before

       Node *current = new Node(st);
       current->setNext(head);
       return current;
     

   }

 
   head->setNext(addNode(head->getNext(),st)); //else move to the next node and do the same again till you find a value that is greater
    return head;
    }


}

Node *deleteNode(Node *current, int enterId) {


  if (current == NULL) { //if current is null return null because nothing is there

       return NULL;

   }
   else {

       Student *sTemp;
       sTemp = current->getStudent();
       int tempId;
       tempId = sTemp->getID();
       if (enterId == tempId) { //if your id matches one of the classes
    
	 Node *next = current->getNext(); //set the node to current
	 delete current;//delete the current
	 nodeFound = true; //set the node found to true
	 return deleteNode(next, enterId);  


       } else {


	 current->setNext(deleteNode(current->getNext(), enterId)); //else move on to the next node
            return current;


       }
   } 

  
}


  

  void printNode(Node *temp) {
    Student *sTemp; //create a temp student
    if (temp == NULL) {
      return;
    }
    else {
    
      sTemp = temp->getStudent();        //get the student                                                                                                                                                                     
      sTemp->print(); //call the print function and print
	
      return  printNode(temp->getNext());  //keep on printing the nodes
    }

  
}

