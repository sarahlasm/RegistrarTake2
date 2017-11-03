#include "Student.h"

class Window
{
public:
  Window();
  ~Window();
  int acceptStudent(Student s);
  bool isOccupied;
  Student studentLeaves();
  int idleTime;
  //int timeDone;
  Student student;
};

/**
Constructor
Sets idle time to 0, isOccupied to false, and student to NULL
*/
Window::Window()
{
  isOccupied = false;
  idleTime = 0;
  //timeDone = -1;
}

Window::~Window()
{
}

/**
acceptStudent accepts a student in to the window, resetting idle time
Parameter s - student to be accepted
Returns idle time
*/
int Window::acceptStudent(Student s)
{
  student = s;
  isOccupied = true;
  int temp = idleTime;
  idleTime = 0;
  return temp;
}

/**
studentLeaves is called when a student leaves
*/
Student Window::studentLeaves()
{
  //student = NULL;
  isOccupied = false;
  return student;
}
