/*
  saikapish sahu
  hash table
  2/8/24
 */
#include <iomanip>
#include <iostream>
#include <cstring>
#include "student.h"
#include "Node.h"
#include <math.h>
#include <fstream>
//all global variables declared such as tables being used and function prototypes
using namespace std;
Node **table = NULL;
Node **table1 = NULL;
Node *root = NULL;
void printNode(Node *temp);
Node *deleteNode(Node *current, int enterId) ;
double findAverage(Node *temp, double sum, int count);
Node *addNode(Node *current, Student *newNode) ;
int getHashKey(int id);
int getHash1Key(int id); 
void rehasher ();
int actualStudentCounter = 0;
int generateRandomStdId(); 
string generateRandomName(ifstream &name);
float generateRandomGpa();

bool isTable1 = false; //to notify if a rehash has occured

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
  ifstream  firstname ; 
  ifstream  lastname ; 

	  cout << " Enter Hash table  length " << endl; //to see how much indexes the first table will have

	  cin >> studentCount;
	  table = new Node * [studentCount];
	  for (int i = 0; i < studentCount; i++ ) {
	    table[i] = NULL;
	  }
	  while (true) { //while loop to continue to ask for what to do
	    cout << " add ('a') or delete ('d') or print ('p') average ('v') " << endl; //enter the command
	    cin >> entry;
	    //creating the objects in meain
	    int key = 0;
	    float gpa;
	    int id;
	    string input = "";
	    string fname;
	    string lname;
	    if (entry == 'a') {
	      char enter;
	      cout << "Do you want to add manual (m) or random (r)?" << endl; //this is to either enter student by hand or via a txt file
	      cin >> enter;	
	      float preGPA;
	      Student *st = new Student; //create new pointer to student
	      if ( enter == 'm') {
	      
		  cout << " Add student record " << endl;
	      
		  gpa = readGpa();
		  id = readStudentId();

		  cout << " Enter Student First name " << endl; 
		  cin >> fname;
		  cout << " Enter Student Last name " << endl; 
		  cin >> lname;

		  cout << "GPA is set precision to 3 " << setprecision(3) << endl;
	      
		  preGPA = gpa; 
	      
		  cout << " set precision value " << gpa << endl;
	      
	      }
	      else if (enter == 'r') { //calls the student from txt file
                firstname.open("firstname.txt", ios::in);
                lastname.open("lastname.txt", ios::in);
		fname = generateRandomName(firstname);
		lname = generateRandomName(lastname);
		firstname.close();
		lastname.close();
		gpa = generateRandomGpa();
		cout << "GPA is set precision to 3 " << setprecision(3) << endl;
		preGPA = gpa;

		id = generateRandomStdId();
		 
	      }
	      st->add(preGPA, id, fname, lname); //add this into the list
	      key = getHashKey(id);
      Node *temp1 = table[key];
      int listCount = 1;
      int tempKey;
      
      while (temp1 != NULL) {
        	listCount++;
        	temp1 = temp1->getNext();
      }
      
      if (listCount <= 3)  {
              table[key]  = addNode(table[key], st);//assings the student to a certain index in the table
	      actualStudentCounter++;
	
      }
      else {
	      rehasher();
	      tempKey = getHash1Key(id);
	      table[tempKey] = addNode(table[tempKey], st);
	      actualStudentCounter++;
      }
 
    }
    else if (entry == 'd') {
      cout << "enter student id delete" << endl;
      int enterId; //enter the id to be deleted
      cin >>  enterId ;
      key = getHashKey(enterId);
      Node *temp = table[key]; //create a temp to hold the table
      table[key] = deleteNode(temp, enterId); //call the function passing in the temp and the id
      if (nodeFound == false) { //if the node is deleted then make sure to continue, if wrong id is sent then prompt
	cout <<"id not found" << endl;
      }
      else {
	nodeFound = false;
      }
    }
    else if (entry == 'p') {

      Node *temp = NULL; //pointer to node which is table index

      for (int i = 0; i< studentCount; i++) {

            if (table[i] != NULL) {
	   	  temp = table[i];
	 	  printNode(temp); //call print function
	    }
      }
	
    }
    else if (entry == 'v') {
      Node *temp = NULL; //pointer to node which is table index
      double sum = 0;
      for (int i = 0; i< studentCount; i++) {

            if (table[i] != NULL) {
	   	  temp = table[i];
                  sum = sum + findAverage(temp,0,0); //call print function
	    }
      }

      sum = sum / actualStudentCounter;



      if (sum != 0 ) {

          cout << " Average student GPA  = " << sum << endl;
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

int getHashKey(int id) { //calling the key depending on if rehashed or not
  return (id % studentCount);
}
int getHash1Key(int id) {
  return (id % (studentCount));
}

int readStudentId() { //this is for reading in id
 int i = 0;
 string userInput ;
 size_t pos;

 while (1) { //while running make sure that the id is a number or else an error will be given

    cout << "Enter Student ID " << endl;

    if (!getline(cin,userInput))
    {

        throw runtime_error(" user input not expected \n "); //throw catch
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


double findAverage(Node *temp, double sum, int count) { //to find average

    Student *sTemp; //create a temp student

    if (temp == NULL) {
     if (count == 0) {
        cout << " end of list " << endl;
        return 0;
     }
     return (sum ); // call the getGPA function and get GPA 

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


void rehasher () { //rehash will double the length and copy the data onto the new table and seperate the values into new indexes
   
    int tempStore = studentCount;
    studentCount = 2*studentCount;
    table1 = new Node * [studentCount];
    for (int i = 0; i < studentCount; i++ ) {
            table1[i] = NULL;
    }
    Student *tempSt;
    int tempID;
    int tempKey;
    Node* temp1;
    for (int i = 0; i < tempStore; i++) {

           if (table[i] != NULL) {
               temp1 = table[i];
               isTable1 = true;
               while (temp1 != NULL) {
                      tempSt = temp1->getStudent();
                      tempID = tempSt->getID();
                      tempKey = getHash1Key(tempID);
                       table1[tempKey] = addNode(table1[tempKey], tempSt);  
                      temp1 = temp1->getNext();
                }
          }

   }
   table = table1;
}




string generateRandomName(ifstream &name) { //generate random name calls a random name from the txt files
 string line;
int random = 0;
int numOfLines = 0;


    srand(time(0));
    random = rand() % 91;

    while(getline(name, line))
    {
        ++numOfLines;

        if(numOfLines == random)
        {
            return line;
        }

    }
    return NULL;

}


float generateRandomGpa() { //random gpa generates a random number from 1 to 10

  bool found = false;
  float gpa = 0;
  gpa = (float)(rand()%41)/10;
  while (found ==false) {
     if (gpa > 0 ) {

         return (gpa);

     }
  gpa = (float)(rand()%41)/10;
  }
  return 0;


}

int generateRandomStdId() { //random id generates a random 6 digit ID
  bool found = false;
  int id = 0;
  id = rand();
  while (found ==false) {

	   
     if ((id %1000000) <= 999999) {

         return (id  % 1000000);

     }
     id = rand();
  }
  return 0;
}
