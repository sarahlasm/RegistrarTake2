/**
  Sarah Lasman and Amanda Galemmo
  2278776          2270004
  lasma101@mail.chapman.edu  galem100@mail.chapman.edu
  CS 350 Section 3
  Assignment #2
**/

#include "DoubleListNode.h"

template <class T>
class Queue
{
  public:
    Queue(int maxSize);
    ~Queue();
    void insert(T data);
    T remove();
    T peek();

    bool isFull();
    bool isEmpty();

    T head;
    T tail;
    int max;

    int numElements;

    unsigned int getSize();

    DoublyLinkedList<T>* myQueue;
};

//Constructor
template <class T>
Queue<T>::Queue(int maxSize)
{
  max = maxSize;
  numElements = 0;
  myQueue = new DoublyLinkedList<T>();
}

//Destructor
template <class T>
Queue<T>::~Queue()
{
  delete myQueue;
}

//Takes a data value and pushes it into queue
template <class T>
void Queue<T>::insert(T data)
{
  if (isEmpty())
  {
    myQueue->insertFront(data);
    head = data;
    tail = data;
    numElements++;
  }
  else if (!isFull())
  {
    myQueue->insertBack(data);
    tail = data;
    numElements++;
  }
  else
    cerr << "Your queue is full. You cannot add more.\n";
}

//Removes the last in value from queue
template <class T>
T Queue<T>::remove()
{
  if (!isEmpty())
  {
    --numElements;
    T temp = myQueue->front->data;
    myQueue->removeFront();
    if (!isEmpty())
    {
      head = myQueue->front->data;
    }
    return temp;
  }
  else
  {
    cerr << "Your queue is empty. You cannot remove more.\n";
    return *(new T);
  }
}

//Looks at last in value of queue
template <class T>
T Queue<T>::peek()
{
  return myQueue->front->data;
}

//Check if full
template <class T>
bool Queue<T>::isFull()
{
  return numElements == max;
}

//Check if empty
template <class T>
bool Queue<T>::isEmpty()
{
  return numElements == 0;
}
