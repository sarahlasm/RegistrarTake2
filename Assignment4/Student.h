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

Student::Student()
{
  timeNeeded = 0;
  timeWaited = 0;
}

Student::Student(int timeN, int timeE)
{
  timeNeeded = timeN;
  timeWaited = 0;
  timeEntered = timeE;
  timeServed = 0;
}

Student::~Student()
{
}

void Student::setTimeWaited(int timeW)
{
  timeWaited = timeW;
}

void Student::setTimeServed(int timeS)
{
  timeServed = timeS;
}
