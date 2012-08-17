#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
#include <cstdlib>

using namespace std;

enum QUEUE_ERRORS {FULL, EMPTY, OUT_OF_BOUND};

template<typename T>
class Queue
{
public:
    Queue(int x = 1);
    ~Queue();

    Queue(Queue<T> &other);
    Queue<T>& operator=(Queue<T> &other);

    void enqueue(T data);
    void dequeue(T data);
    void prioritize(T newItem);
    T peek();
    bool isEmpty();
    bool isFull();
    void print();
    int size();
    int maxSize();
    T seek(int index);

private:
    T *myQueue;
    int mySize, begin, end;
    void copy(Queue<T> &other);
};

template<typename T>
Queue<T>::Queue(int x)
{
    begin = end = 0;
    myQueue = new T[mySize = x + 1];
}

template<typename T>
Queue<T>::~Queue()
{
    delete myQueue;
}

template<typename T>
Queue<T>::Queue(Queue<T> &other)
{
    copy(other);
}

template<typename T>
Queue<T>& Queue<T>::operator=(Queue<T> &other)
{
    if(this != &other)
        copy(other);
    return *this;
}

template<typename T>
void Queue<T>::enqueue(T data)
{
    if(isFull())
        throw FULL;
    myQueue[end++] = data;
    //prioritize(data);
}

template<typename T>
void Queue<T>::prioritize(T newItem)
{
    int prev = end - 2;
    while(newItem < myQueue[prev] && prev >= 0)
    {
        T temp = myQueue[prev];
        myQueue[prev] = newItem;
        myQueue[prev+1] = temp;
        prev--;
    }
}

template<typename T>
T Queue<T>::peek()
{
    if(isEmpty())
        throw EMPTY;
    return myQueue[begin];
}

template<typename T>
void Queue<T>::dequeue(T data)
{
    if(isEmpty())
        throw EMPTY;
    for(int i = 1; i < mySize; i++)
        myQueue[i-1] = myQueue[i];
    end--;
    //return myQueue[--end];
}

template<typename T>
bool Queue<T>::isEmpty()
{
    return begin == end;
}

template<typename T>
bool Queue<T>::isFull()
{
    return end == mySize;
}

template<typename T>
void Queue<T>::copy(Queue<T> &other)
{
    delete myQueue;
    myQueue = new T[mySize = other.mySize];
    begin = other.begin;
    end = other.end;
    for(int i = 0; i < mySize; i++)
        myQueue[i] = other.myQueue[i];
}

template<typename T>
void Queue<T>::print()
{
    if(isEmpty())
        cout << " " << endl;
    else
    {
        for(int i = end-1; i >= begin; i--)
            cout << myQueue[i] << " ";
        cout << endl;
    }
}

template<typename T>
int Queue<T>::size()
{
    return end;
}

template<typename T>
int Queue<T>::maxSize()
{
    return mySize;
}

template<typename T>
T Queue<T>::seek(int index)
{
    if(index < size())
        return myQueue[index];
    else
        throw OUT_OF_BOUND;
}

#endif // QUEUE_H
