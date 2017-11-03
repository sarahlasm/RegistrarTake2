/**
  Sarah Lasman and Amanda Galemmo
  2278776          2270004
  lasma101@mail.chapman.edu  galem100@mail.chapman.edu
  CS 350 Section 3
  Assignment #2
**/

#include "ListNode.h"

//Constructor
template <class T>
ListNode<T>::ListNode()
{
  data = 0;
  next = NULL;
  prev = NULL;
}

//Constructor with data
template <class T>
ListNode<T>::ListNode(T d)
{
  data = d;
  next = NULL;
  prev = NULL;
}

//Destructor
template <class T>
ListNode<T>::~ListNode()
{
  if (next != NULL)
    delete next;
}
