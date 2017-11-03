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
It is a bit big for a main method, but it worked best to keep everything in the same class.
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
  Queue<Student> studentQueue(20);
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
      nextTimeSelected = true;
      if (getline(inFile, input))
      {
        currInput = stoi(input);
      }
      else if (!allWindowsEmpty(windows, numWindows))
      {
        //PLACEHOLDER so that the else can be reached
      }
      else
      {
        stats->printStats();
        return 0;
      }
    }
    if (currTime == currInput) //hits 1
    {
      nextTimeSelected = false;
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
              s.setTimeServed(currTime);
              s.setTimeWaited(0);
              studentQueue.insert(s);
              stats->takeIdle(windows[j].acceptStudent(studentQueue.remove()));
              break;
            }
          }
        }
      }
      else if (!allWindowsEmpty(windows, numWindows))
      {
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
      if (windows[i].isOccupied && windows[i].student.timeNeeded + windows[i].student.timeServed == currTime)
      {
        stats->takeStudent(windows[i].studentLeaves());
      }
      if (!windows[i].isOccupied && !studentQueue.isEmpty())
      {
        s2 = studentQueue.remove();
        s2.setTimeServed(currTime);

        s2.setTimeWaited(currTime - s2.timeEntered);
        s2.setTimeWaited(currTime - s2.timeEntered);
        cout << currTime << " - " << s2.timeEntered << " = " << s2.timeWaited << endl;
        stats->takeIdle(windows[i].acceptStudent(s2));
      }
      if (!windows[i].isOccupied)
      {
        if (currTime > 0)
          windows[i].idleTime++;
      }
    }

    currTime++;
  }
}
