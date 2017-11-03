/**
  Sarah Lasman and Amanda Galemmo
  2278776          2270004
  lasma101@mail.chapman.edu  galem100@mail.chapman.edu
  CS 350 Section 3
  Assignment #2
**/

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
