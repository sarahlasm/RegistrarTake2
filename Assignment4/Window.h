/**
  Sarah Lasman and Amanda Galemmo
  2278776          2270004
  lasma101@mail.chapman.edu  galem100@mail.chapman.edu
  CS 350 Section 3
  Assignment #4
**/

/*
A window class representing the various registrar windows.
Can have one student at a time occupying it.
*/

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
}

/**
Destructor
*/
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
Returns student who left
*/
Student Window::studentLeaves()
{
  isOccupied = false;
  return student;
}
