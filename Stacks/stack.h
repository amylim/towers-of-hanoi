#ifndef STACK_H
#define STACK_H
#include <iostream>

using namespace std;

enum STACK_ERRORS {FULL, EMPTY, OUT_OF_BOUND};

template<typename T>
class Stack
{
public:
    Stack(int q = 3);
    ~Stack();

    Stack(Stack<T> &other);
    Stack<T>& operator=(Stack<T> &other);

    void push(T data);
    T pop();
    T peek();    //sees what is on the top of the stack
    void resize(int x);
    void clear();
    bool isEmpty();
    bool isFull();
    int size();
    int maxSize();
    void print();
    T seek(int index);

private:
    T *myStack;
    int mySize, tos;
    void copy(Stack<T> &other);
};

template<typename T>
Stack<T>::Stack(int q)
{
    tos = -1;
    myStack = new T[mySize = q];
}

template<typename T>
Stack<T>::~Stack()
{
    clear();
    delete myStack;
}

template<typename T>
Stack<T>::Stack(Stack<T> &other)
{
    copy(other);
}

template<typename T>
Stack<T>& Stack<T>::operator=(Stack<T> &other)
{
    if(this != &other)
        copy(other);
    return *this;
}

template<typename T>
void Stack<T>::push(T data)
{
    if(isFull())
        throw FULL;
    myStack[++tos] = data;
}

template<typename T>
T Stack<T>::pop()
{
    if(isEmpty())
        throw EMPTY;
    return myStack[tos--];
}

template<typename T>
T Stack<T>::peek()    //sees what is on the top of the stack
{
    if(isEmpty())
       throw EMPTY;
    return myStack[tos];
}

template<typename T>
void Stack<T>::resize(int x)
{
    delete myStack;
    myStack = new T[mySize = x];
    tos = -1;
}

template<typename T>
void Stack<T>::clear()
{
    tos = -1;
}

template<typename T>
bool Stack<T>::isEmpty()
{
    return tos < 0;
}

template<typename T>
bool Stack<T>::isFull()
{
    return tos + 1 == mySize;
}

template<typename T>
int Stack<T>::size()
{
    return tos + 1;
}

template<typename T>
int Stack<T>::maxSize()
{
    return mySize;
}

template<typename T>
void Stack<T>::copy(Stack<T> &other)
{
    delete myStack;
    myStack = new T[mySize = other.mySize];
    tos = other.tos;
    for(int i = 0; i <= tos; i++)
        myStack[i] = other.myStack[i];
}

template<typename T>
void Stack<T>::print()
{
    if(isEmpty())
        cout << "Stack is empty"; //throw EMPTY;
    else
    {
        for(int i = 0; i <= tos; i++)
            cout << myStack[i] << " ";
    }
    cout << endl;
}

template<typename T>
T Stack<T>::seek(int index)
{
    if(index < size())
        return myStack[index];
    else 
        throw OUT_OF_BOUND;
}

#endif // STACK_H
