/**
  Sarah Lasman and Amanda Galemmo
  2278776          2270004
  lasma101@mail.chapman.edu  galem100@mail.chapman.edu
  CS 350 Section 3
  Assignment #4
**/

/*
ListNode objects are the building blocks for the DoublyLinkedList.
*/

#include <iostream>

using namespace std;

template <class T>
class ListNode
{
public:
  ListNode<T>* next;
  ListNode<T>* prev;
  T data;
  ListNode();
  ListNode(T d);
  ~ListNode();
};

/*
Constructor
Sets data to 0, and next and prev pointers to null.
*/
template <class T>
ListNode<T>::ListNode()
{
  data = 0;
  next = NULL;
  prev = NULL;
}

/*
Overloaded Constructor
Sets data to param d, and next and prev pointers to null.
*/
template <class T>
ListNode<T>::ListNode(T d)
{
  data = d;
  next = NULL;
  prev = NULL;
}

/*
Destructor
*/
template <class T>
ListNode<T>::~ListNode()
{
  if (next != NULL)
    delete next;
}
