/**
  Sarah Lasman and Amanda Galemmo
  2278776          2270004
  lasma101@mail.chapman.edu  galem100@mail.chapman.edu
  CS 350 Section 3
  Assignment #4
**/

/*
A student class.
Students can wait in line and acccess windows at the registrar.
*/

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

/*
Constructor
Sets all instnace variables to 0.
*/
Student::Student()
{
  timeNeeded = 0;
  timeWaited = 0;
  timeEntered = 0;
  timeServed = 0;
}

/*
Overloaded Constructor
Sets timeNeeded and timeEntered to params
*/
Student::Student(int timeN, int timeE)
{
  timeNeeded = timeN;
  timeWaited = 0;
  timeEntered = timeE;
  timeServed = 0;
}

/*
Destructor
*/
Student::~Student()
{
}

/*
setTimeWaited sets time a student has waited
Parameter timeW - time the student has waited
*/
void Student::setTimeWaited(int timeW)
{
  timeWaited = timeW;
}

/*
setTimeServed sets the time at which the student was setTimeServed
Parameter timeS - the time the student was served
*/
void Student::setTimeServed(int timeS)
{
  timeServed = timeS;
}
