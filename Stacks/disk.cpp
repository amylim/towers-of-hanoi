#include "disk.h"


Disk::Disk(int r, int c)
{
    x = r;
    y = c;
}

Disk::~Disk()
{

}

void Disk::setLocation(int r, int c)
{
    x = r;
    y = c;     
}

void Disk::display(bool onOff, int size)
{
    if(onOff)
        display(size); 
    else 
        displayOff(size); 
}

void Disk::displayStack(int r, int c, Stack<int> x)
{
    Disk disks[x.maxSize()];
    for(int i = 0; i < x.maxSize(); i++)
        disks[i].setLocation(r-i, c); 
    if(!x.isEmpty())
    {         
        for(int i = 0; i < x.size(); i++)
            disks[i].display(true, x.seek(i));
        if(!x.isFull())
        {
            for(int i = x.size(); i < x.maxSize(); i++)
                disks[i].display(false, x.maxSize());
        }
    } 
    else
    {
        for(int i = 0; i < x.maxSize(); i++)
            disks[i].display(false, x.maxSize());
    }
}

void Disk::display(int size)
{
    attron(COLOR_PAIR(WHITEONBLUE));
    mvprintw(x, y-size, "<"); 
    for(int i = size - 1; i > 0; i--)
        mvprintw(x, y-i, "-");
    mvprintw(x, y, "%d", size);
    for(int i = size - 1; i > 0; i--)
        mvprintw(x, y+i, "-");
    mvprintw(x, y+size, ">"); 
    refresh();
    attroff(COLOR_PAIR(WHITEONBLUE));
}
void Disk::displayOff(int size)
{
    attron(COLOR_PAIR(WHITEONBLACK));
    int cover = size * 2 + 1;
    int start = y - size;
    for(int i = 0; i < cover; i++)
        mvprintw(x, start+i, " "); 
    refresh();
    attroff(COLOR_PAIR(WHITEONBLACK));
         
}
