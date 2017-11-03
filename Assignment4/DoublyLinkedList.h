/**
  Sarah Lasman and Amanda Galemmo
  2278776          2270004
  lasma101@mail.chapman.edu  galem100@mail.chapman.edu
  CS 350 Section 3
  Assignment #2
**/

#include "ListNode.h"

template <class T>
class DoublyLinkedList
{
public:
  ListNode<T>* front;
  ListNode<T>* back;
  DoublyLinkedList();
  ~DoublyLinkedList();
  void insertFront(T data);
  T removeFront();
  void insertBack(T data);
  T removeBack();
  void printList();
  T remove(T key);
  int find(T value);
  T deletePos(int pos);
  bool insertAfter(int pos, T val); //@TODO
  bool isEmpty();
  unsigned int getSize();
  unsigned int size;
};
