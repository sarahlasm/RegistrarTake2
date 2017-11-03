/**
  Sarah Lasman and Amanda Galemmo
  2278776          2270004
  lasma101@mail.chapman.edu  galem100@mail.chapman.edu
  CS 350 Section 3
  Assignment #4
**/

/*
A class that performs statistics and analyzes the data from the main class.
*/

#include <iostream>

using namespace std;

class Statistics
{
  public:
    int totalIdleTime;
    int longestIdleTime;
    int numOverFive;
    int totalStudentWaitTime;
    int longestStudentWaitTime;
    int numOverTen;
    int studentsServed;
    int numWindows;

    DoublyLinkedList<int> *wait;

    Statistics();
    Statistics(int n);
    ~Statistics();
    void takeStudent(Student s);
    void takeIdle(int idle);
    double calculateMean(int times, int total);
    void increaseTotalWait(int t);
    void increaseTotalIdle(int t);
    int findMedian(DoublyLinkedList<int>* w);
    void addToMedianList(int num);
    void printStats();
};

/**
Constructor
Sets all variables to 0
*/
Statistics::Statistics()
{
  wait = new DoublyLinkedList<int>();
  wait->insertFront(-1);
  studentsServed = 0;
  totalStudentWaitTime = 0;
  totalIdleTime = 0;
  longestIdleTime = 0;
  longestStudentWaitTime = 0;
}

/**
Overloaded Constructor
Sets all variables to 0
Parameter n - number of windows (needed for calculating mean window idle time)
*/
Statistics::Statistics(int n)
{
  wait = new DoublyLinkedList<int>();
  wait->insertFront(-1);
  studentsServed = 0;
  totalStudentWaitTime = 0;
  totalIdleTime = 0;
  longestIdleTime = 0;
  longestStudentWaitTime = 0;
  numWindows = n;
}

/**
Destructor
*/
Statistics::~Statistics()
{
  delete wait;
}

/**
takeStudent is called every time a student is finished at a window.
It records their wait time, and marks it everywhere that's necessary.
Parameter s - student that has finished
*/
void Statistics::takeStudent(Student s)
{
  studentsServed++;
  int timeWaited = s.timeWaited;
  addToMedianList(timeWaited);
  increaseTotalWait(timeWaited);
  if (timeWaited > 10)
    numOverTen++;
  if (timeWaited > longestStudentWaitTime)
    longestStudentWaitTime = timeWaited;
}

/**
takeIdle is called every time a window is idle to record its information
Parameter idly - length of time that window was idle
*/
void Statistics::takeIdle(int idly)
{
  increaseTotalIdle(idly);
  if (idly > 5)
    numOverFive++;
  if (longestIdleTime < idly)
    longestIdleTime = idly;
}

/**
increaseTotalIdle increases the total amount of time spent idle
Parameter t - amount for idleTime to increase by
*/
void Statistics::increaseTotalIdle(int t)
{
  totalIdleTime += t;
}

/**
increaseTotalWait increases the total amount of time spent waiting
Parameter t - amount for waitTime to increase by
*/
void Statistics::increaseTotalWait(int t)
{
  totalStudentWaitTime += t;
}

/**
calculateMean calculates mean
Parameter times - the number of times the total should be divided by
Parameter total - the total number of an occurence
Returns mean
*/
double Statistics::calculateMean(int times, int total)
{
  return (double)total/(double)times;
}

/**
findMedian looks through an ordered list of ints and determines the median
Parameter wait - the list it looks through
Returns median of the list
*/
int Statistics::findMedian(DoublyLinkedList<int>* wait)
{
  wait->front = wait->front->next;
  while (wait->size > 2)
  {
    wait->front = wait->front->next;
    wait->size--;
    wait->back = wait->back->prev;
    wait->size--;
  }
  if (wait->size == 2)
    return ((double)wait->front->data+(double)wait->back->data)/2;
  else
    return wait->front->data;
}

/**
addToMedianList adds a number to the list used to calculate median
Adds it in numerical order
Parameter num - number to be added
*/
void Statistics::addToMedianList(int num)
{
  ListNode<int> *curr = wait->front;
  int pos = 0;
  while (curr-> data > num && curr->next != NULL)
  {
    curr = curr->next;
    pos++;
  }
  wait->insertBack(num);
  curr = NULL;
  curr = wait->front;
  while (curr != NULL)
  {
    curr = curr->next;
  }
}

/**
Prints the stats!
*/
void Statistics::printStats()
{
  cout << "STATISTICS: " << endl;
  cout << "Median student wait time: " << findMedian(wait) << endl;
  cout << "Longest student wait time: " << longestStudentWaitTime << endl;
  cout << "Mean student wait time: " << calculateMean(studentsServed, totalStudentWaitTime) << endl;
  cout << "Number of students waiting over 10 minutes: " << numOverTen << endl;
  cout << "Longest idle time: " << longestIdleTime << endl;
  cout << "Mean idle time: " << calculateMean(numWindows, totalIdleTime) << endl; 
  cout << "Number of windows idle over 5 minutes: " << numOverFive << endl;
}
