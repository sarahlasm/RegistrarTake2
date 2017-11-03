/**
  Sarah Lasman and Amanda Galemmo
  2278776          2270004
  lasma101@mail.chapman.edu  galem100@mail.chapman.edu
  CS 350 Section 3
  Assignment #2
**/

/*
The crux of the work is done in this class.
The file is read, instances of various objects are created, and the simulation is conducted.
It is a bit big for a main class, but it worked best to keep everything in the same class.
*/

#include "Queue.h"
#include "Window.h"
#include "Statistics.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

/**
allWindowsEmpty
Returns true if all windows are empty
*/
bool allWindowsEmpty(Window windows[], int numWindows)
{
  for (int i = 0; i < numWindows; ++i)
  {
    if (windows[i].isOccupied)
      return false;
  }
  return true;
}

int main(int argc, char** argv)
{
  if (argc == 1)
  {
    cout << "You must run this program with a command-line file name.\n";
    return -1;
  }
  string fileName = argv[1];
  string input;
  ifstream inFile(fileName);
  Queue<Student> studentQueue(20);// = new Queue<Student>(20);
  getline(inFile, input);
  int numWindows = stoi(input);
  int currTime = 0;
  Window *windows = new Window[numWindows];
  Student *s;
  Student s2;
  Statistics* stats = new Statistics(numWindows);
  bool nextTimeSelected = false;
  int currInput = -1; //currInput tracks the next clock tick at which more students will arive
  while (true)
  {
    if (currInput != currTime && !nextTimeSelected) //beginning
    {
      cout << "if1\n";
      nextTimeSelected = true;
      if (getline(inFile, input))
      {
        currInput = stoi(input);
      }
      else if (!allWindowsEmpty(windows, numWindows))
      {
    //    currTime++;
      }
      else
      {
        stats->printStats();
        return 0;
      }
    }
    if (currTime == currInput) //hits 1
    {
      cout << "if2\n";
      nextTimeSelected = false;
      //currInput = -1;
      if (getline(inFile, input))
      {
        string studentInput;
        for (int i = 0; i < stoi(input); ++i)
        {
          getline(inFile, studentInput);
          Student s(stoi(studentInput), currTime);

          for (int j = 0; j <= numWindows; ++j)
          {
            if (j == numWindows)
            {
              cout << "The time is " << currTime << " and a new student is waiting in line.\n";
              studentQueue.insert(s);
              break;
            }
            if (!windows[j].isOccupied)
            {
              cout << "The time is " << currTime << " and the student has gone to window " << j << endl;
              s.setTimeServed(currTime);
              cout << "Student has been served at time " << s.timeServed << endl;
              s.setTimeWaited(0);
              cout << "cake\n";
              studentQueue.insert(s);
              //windows[j].acceptStudent(studentQueue.remove());
              cout << "moon\n";
              stats->takeIdle(windows[j].acceptStudent(studentQueue.remove()));
              cout << "brains\n";
              break;
            }
          }
        }
      }
      else if (!allWindowsEmpty(windows, numWindows))
      {
        cout << "if3\n";
        currTime++;
        break;
      }
    }
    else if (allWindowsEmpty(windows, numWindows) && currInput < currTime)
    {
      for (int i = 0; i < numWindows; ++i)
      {
        stats->takeIdle(windows[i].idleTime);
      }
      stats->printStats();
      return 0;
    }
    for (int i = 0; i < numWindows; ++i)
    {
    //  cout << "Is it time for the student to go? " << (windows[i].student.timeNeeded + windows[i].student.timeServed == currTime) << endl;
      //Student's time runs out, this is definitely sloppy
      if (windows[i].isOccupied && windows[i].student.timeNeeded + windows[i].student.timeServed == currTime)
      {
        cout << "Was he right to leave? " << (windows[i].student.timeNeeded) << " " << windows[i].student.timeServed << " " << currTime << endl;
        stats->takeStudent(windows[i].studentLeaves()); //@TODO
        cout << "The time is " << currTime << " and a student has just left window " << i << endl;
      }
      if (!windows[i].isOccupied && !studentQueue.isEmpty())
      {
        cout << "The time is " << currTime << " and a student in line has just gone to window " << i << endl;
        cout << "Current time: " << currTime << endl;
        s2 = studentQueue.remove();
        s2.setTimeServed(currTime);
        cout << "Student has been served at time " << s2.timeServed << endl;

        s2.setTimeWaited(currTime - s2.timeEntered);
        s2.setTimeWaited(currTime - s2.timeEntered);
        cout << currTime << " - " << s2.timeEntered << " = " << s2.timeWaited << endl;
        stats->takeIdle(windows[i].acceptStudent(s2));
      }
      if (!windows[i].isOccupied)
      {
        if (currTime > 0)
          windows[i].idleTime++;
        cout << "Window " << i << " idle time " << windows[i].idleTime << endl;
      }
    }
    cout << "This is the end of time " << currTime << endl;

    currTime++;
  }
}
