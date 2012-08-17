#ifndef DISK_H
#define DISK_H
#include <iostream>
#include "initialize.h"
#include "stack.h"
//#include "queue.h"

using namespace std;

class Disk
{
public:
    Disk(int r = 19, int c = 20);
    ~Disk();

    void setLocation(int r, int c);
    void display(bool onOff, int size);
    void displayStack(int r, int c, Stack<int> x);
    //void displayQueue(int r, int c, Queue<int> x);

private:
    int x, y;
    void display(int size);
    void displayOff(int size);
    
};

#endif // DISK_H
