/**
  Sarah Lasman and Amanda Galemmo
  2278776          2270004
  lasma101@mail.chapman.edu  galem100@mail.chapman.edu
  CS 350 Section 3
  Assignment #4
**/

/*
A doubly linked list that supports the usual operations.
*/

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
  bool insertAfter(int pos, T val);
  bool isEmpty();
  unsigned int getSize();
  unsigned int size;
};

/**
Constructor
Sets size to 0, and front and back pointers to NULL
*/
template <class T>
DoublyLinkedList<T>::DoublyLinkedList()
{
  size = 0;
  front = NULL;
  back = NULL;
}

/**
Destructor
Deletes pointers to all the nodes
*/
template <class T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
  ListNode<T>* current = front;

  while (current)
  {
      ListNode<T>* next = current->next;
      delete current;
      current = next;
  }
}

/**
insertFront inserts a node at the front of the list
Parameter data: the data to be in the new node
*/
template <class T>
void DoublyLinkedList<T>::insertFront(T data)
{
  ListNode<T>* node = new ListNode<T>(data);
  if (size == 0)
  {
    back = node;
  }
  else
  {
    front->prev = node;
    node->next = front;
  }
  front = node;
  ++size;
}

/**
removeFront removes a node at the front of the list
Returns deleted value
*/
template <class T>
T DoublyLinkedList<T>::removeFront()
{
  T val = front->data;
  if (front->next == NULL)
    back = NULL;
  else
    front->next->prev = NULL;
  front = front->next;

  --size;
  return val;
}

/**
printList prints the list
*/
template <class T>
void DoublyLinkedList<T>::printList()
{
  ListNode<T>* curr = front;
  while(curr)
  {
    cout << curr->data << endl;
    curr = curr->next;
  }
}

/**
find finds a certain value and returns its index
Parameter value - value to be found
Returns index of value (-1 if not found)
*/
template <class T>
int DoublyLinkedList<T>::find(T value)
{
  int idx = -1; //index tracker
  ListNode<T>* curr = front;

  while(curr != NULL)
  {
    ++idx;
    if(curr->data == value)
    {
      break;
    }
    else
    {
      curr = curr->next;
    }
  }

  if (curr == NULL)
     idx = -1;
  return idx;
}

/**
deletePos deletes the node at a certain position in the list
Parameter pos - position in the list
Returns data of the deleted node
*/
template <class T>
T DoublyLinkedList<T>::deletePos(int pos)
{
  if (pos >= size)
    return -1;
  int idx = 0;
  ListNode<T>* curr = front;
  ListNode<T>* prev = front;

  while(idx != pos)
  {
    ++idx;
    prev = curr;
    curr = curr->next;
  }

  prev->next = curr->next;
  curr->next = NULL;
  T d = curr->data;
  size--;
  delete curr;
  return d;
}

/**
isEmpty
Returns true if empty, false otherwise
*/
template <class T>
bool DoublyLinkedList<T>::isEmpty()
{
  return size == 0;
}

/**
getSize
Returns size
*/
template <class T>
unsigned int DoublyLinkedList<T>::getSize()
{
  return size;
}

/**
insertBack inserts new node at back of the list
Parameter data - data to be added
*/
template <class T>
void DoublyLinkedList<T>::insertBack(T data)
{
  ListNode<T>* node = new ListNode<T>(data);

  if (size == 0)
    front = node;
  else
  {
    back->next = node;
    node->prev = back;
  }
  back = node;
  ++size;

}

/**
removeBack removes node at the back of the list
Returns data of removed node
*/
template <class T>
T DoublyLinkedList<T>::removeBack()
{
  T val = back->data;
  if (back->prev == NULL)
    front = NULL;
  else
    back->prev->next = NULL;
  back = back->prev;
  --size;
  return val;

}

/**
remove removes the node with a given key
Parameter key - key of node to be deleted
Returns data of deleted node
*/
template <class T>
T DoublyLinkedList<T>::remove(T key)
{
  ListNode<T>* curr = front;
  while(curr->data != key)
  {
    curr = curr->next;
    if (curr == back)
      return 0;
  }

  if (curr == front)
  {
    front = curr->next;
  }
  else
  {
    curr->prev->next = curr->next;
  }

  if (curr == back)
  {
    back = curr->prev;
  }
  else
  {
    curr->next->prev = curr->prev;
  }

  curr->next = NULL;
  curr->prev = NULL;
  --size;

  int temp = curr->data;
  delete curr;

  return temp;
}

/**
insertAfter inserts a node after a given position
Parameter pos - position after which the node should be inserted
Parameter val - value of the node that will be inserted
Returns true if successful, false otherwise
*/
template <class T>
bool DoublyLinkedList<T>::insertAfter(int pos, T val)
{
  int count = 0;
  ListNode<T>* curr = front;
  while (count != pos)
  {
    curr = curr->next;
    count++;
  }
  ListNode<T>* node = new ListNode<T>(val);
  curr->next->prev = node;
  node->next = curr->next;
  curr->next = node;
  node->prev = curr;
  delete curr;
  return 1;

}
