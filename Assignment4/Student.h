/**
  Sarah Lasman and Amanda Galemmo
  2278776          2270004
  lasma101@mail.chapman.edu  galem100@mail.chapman.edu
  CS 350 Section 3
  Assignment #2
**/

#include <iostream>

using namespace std;

class Student
{
public:
  Student();
  Student(int timeN, int timeE);
  ~Student();
  void setTimeWaited(int timeW);
  void setTimeServed(int timeS);
  int timeNeeded;
  int timeWaited;
  int timeEntered;
  int timeServed;
};

//Constructor
Student::Student()
{
  timeNeeded = 0;
  timeWaited = 0;
}

//Constructor with parameters
Student::Student(int timeN, int timeE)
{
  timeNeeded = timeN;
  timeWaited = 0;
  timeEntered = timeE;
  timeServed = 0;
}

//Destructor
Student::~Student()
{
}

//Sets time waited for student object to parameter
void Student::setTimeWaited(int timeW)
{
  timeWaited = timeW;
}

//Sets time served for student object to parameter 
void Student::setTimeServed(int timeS)
{
  timeServed = timeS;
}
