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

template <class T>
Queue<T>::Queue(int maxSize)
{
  max = maxSize;
  numElements = 0;
  myQueue = new DoublyLinkedList<T>();
}

template <class T>
Queue<T>::~Queue()
{
  delete myQueue;
}

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

template <class T>
T Queue<T>::peek()
{
  return myQueue->front->data;
}

template <class T>
bool Queue<T>::isFull()
{
  return numElements == max;
}

template <class T>
bool Queue<T>::isEmpty()
{
  return numElements == 0;
}
