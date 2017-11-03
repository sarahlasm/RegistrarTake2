#include <iostream>

using namespace std;
/*
  1. The mean student wait time.
  2. The median student wait time.   [maybe a BST??]
  3. The longest student wait time.
  4. The number of students waiting over 10 minutes
  5. The mean window idle time
  6. The longest window idle time
  7. Number of windows idle for over 5 minutes.
*/

//introduce a doubly linked list that keeps track of median/longest

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

Statistics::Statistics()
{
  wait = new DoublyLinkedList<int>();
  studentsServed = 0;
  totalStudentWaitTime = 0;
  totalIdleTime = 0;
  longestIdleTime = 0;
  longestStudentWaitTime = 0;
}

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

Statistics::~Statistics()
{
  delete wait;
}

void Statistics::takeStudent(Student s)
{
  studentsServed++;
  int timeWaited = s.timeWaited;
  cout << "This student had waited: " << timeWaited << endl;
  addToMedianList(timeWaited);
  increaseTotalWait(timeWaited);
  if (timeWaited > 10)
    numOverTen++;
  if (timeWaited > longestStudentWaitTime)
    longestStudentWaitTime = timeWaited;
  //then add this to a list that orders based on value
  cout << "Total wait time " << totalStudentWaitTime << endl;
  //delete &s;
}

void Statistics::takeIdle(int idly)
{
  increaseTotalIdle(idly);
  if (idly > 5)
    numOverFive++;
  if (longestIdleTime < idly)
    longestIdleTime = idly;
}

void Statistics::increaseTotalIdle(int t)
{
  totalIdleTime += t;
}

void Statistics::increaseTotalWait(int t)
{
  totalStudentWaitTime += t;
}

double Statistics::calculateMean(int times, int total)
{
  return (double)total/(double)times;
}

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

void Statistics::addToMedianList(int num)
{
  ListNode<int> *curr = wait->front;
  int pos = 0;
  while (curr-> data > num && curr->next != NULL)
  {
    curr = curr->next;
    pos++;
  }
  cout << "Chocolate\n";
  wait->insertBack(num); cout << wait->back->data << endl;
  cout << "Cake\n";
  curr = NULL;
  curr = wait->front;
  while (curr != NULL)
  {
    curr = curr->next;
  }
}

void Statistics::printStats()
{
  cout << "STATISTICS: " << endl;
  cout << "Median student wait time: " << findMedian(wait) << endl;
  cout << "Longest student wait time: " << longestStudentWaitTime << endl;
  cout << "Mean student wait time: " << calculateMean(studentsServed, totalStudentWaitTime) << endl;
  cout << "Number of students waiting over 10 minutes: " << numOverTen << endl;
  cout << "Longest idle time: " << longestIdleTime << endl;
  cout << "Mean idle time: " << calculateMean(numWindows, totalIdleTime) << endl; //FIND NUM windows
  cout << "Number of windows idle over 5 minutes: " << numOverFive << endl;
}
