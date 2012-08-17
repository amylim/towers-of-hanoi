/**********************************************************
Author: Amy Lim
Program: CS8 Test 1 - Towers of Hanoi (Stacks)
Purpose: Simulation of the game Towers of Hanoi using stacks
Notes: Last edited April 12, 2011
Reference used: http://en.wikipedia.org/wiki/Towers_of_hanoi
**********************************************************/
#include <cstdlib>
#include <iostream>
#include <math.h>
#include "initialize.h"
#include "keyboard.h"
#include "disk.h"
#include "stack.h"

using namespace std;

int const DELAY = 300;
int getDiskCount();
int getStartPos();
int getEndPos(int start);
int findOtherPeg(int start, int end);
void shift(int start, int end, int diskCount, Stack<int> board[], int isRight);
     //0 = left & 1 = right
int downPeg(int peg);
int upPeg(int peg);
void makeValidMove(Stack<int> &a, Stack<int> &b);
void movePiece(Stack<int> &from, Stack<int> &to);

int main(int argc, char *argv[])
{
    int diskCount = getDiskCount();
    int startPos = getStartPos();
    int endPos = getEndPos(startPos);

    Stack<int> peg1(diskCount);
    Stack<int> peg2(diskCount);
    Stack<int> peg3(diskCount);

    Stack<int> board[3];
    board[0] = peg1;
    board[1] = peg2;
    board[2] = peg3;
    
    for(int i = diskCount; i > 0; i--)
        board[startPos-1].push(i);

    initialize();
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    
    Disk test;
    test.displayStack(19, 20, board[0]);
    test.displayStack(19, 40, board[1]);
    test.displayStack(19, 60, board[2]);

    int findGoal = (startPos == 3) ? 1 : startPos + 1;
    cout << "                    1                   2                   3" << endl;

    if(diskCount%2) //case for odd number of disks
    {
        //shift in the same direction of peg
        if(findGoal == endPos) //if end peg is on right
            shift(startPos, endPos, diskCount, board, 1);
        else
            shift(startPos, endPos, diskCount, board, 0);
    }
    else    //case for even number of disks
    {
        //shift in opposite direction of peg
        int otherPeg = findOtherPeg(startPos, endPos);
        if(findGoal == endPos) //if end peg is on right
            shift(startPos, otherPeg, diskCount, board, 0);
        else
            shift(startPos, otherPeg, diskCount, board, 1);
    }
    system("PAUSE");
    return EXIT_SUCCESS;
}

int getDiskCount()
{
    cout << "How many disks would you like to use? (3-9) ";
    int count;
    cin >> count;
    while(count < 3 || count > 9)
    {
        cout << "Invalid number. There must be between 3 to 9 disks. Please try again. " << endl;
        cout << "How many disks would you like to use? ";
        cin >> count;
    }
    return count;
}

int getStartPos()
{
    cout << "Which is the starting peg? (1/2/3) ";
    int start;
    cin >> start;
    while((start < 1) || (start > 3))
    {
        cout << "Invalid peg. Please try again. " << endl;
        cout << "Which is the starting peg? (1/2/3) ";
        cin >> start;
    }
    return start;
}

int getEndPos(int start)
{
    cout << "Which is the ending peg? (1/2/3) ";
    int end;
    cin >> end;
    while((end == start) || (end < 1) || (end > 3))
    {
        cout << "Invalid peg. Please try again. " << endl;
        cout << "Which is the ending peg? (1/2/3) ";
        cin >> end;
    }
    return end;
}

void makeValidMove(Stack<int> &a, Stack<int> &b)
{
    if(a.isEmpty())
        movePiece(b, a);
    else if(b.isEmpty())
        movePiece(a, b);
    else if(a.peek() > b.peek())
        movePiece(b, a);
    else if(a.peek() < b.peek())
        movePiece(a, b);
    else
        cout << "There is no valid move. " << endl;
}

void movePiece(Stack<int> &from, Stack<int> &to)
{
    try
    {
        int move = from.pop();
        to.push(move);
    }
    catch(...)
    {
        cout << "Error in moving pieces. " << endl;
    }

}

void shift(int start, int end, int diskCount, Stack<int> board[], int isRight)
{
    int (*pegDir[2])(int);
    pegDir[0] = &downPeg;
    pegDir[1] = &upPeg; 
    int onePeg = start - 1;
    int otherPeg = end - 1;
    int steps = 0;
    double totalSteps = pow(2.0, (double)diskCount) - 1;
    while(steps < totalSteps)
    {
        makeValidMove(board[onePeg], board[otherPeg]);
        onePeg = pegDir[isRight](onePeg);
        otherPeg = pegDir[isRight](otherPeg);
        steps++;
        Disk test;
        delay_output(DELAY);
        test.displayStack(19, 20, board[0]);
        test.displayStack(19, 40, board[1]);
        test.displayStack(19, 60, board[2]);
    }
}

int downPeg(int peg)
{
    return (peg == 2) ? 0 : peg + 1;   
}
int upPeg(int peg)
{
    return (peg == 0) ? 2 : peg - 1;
}

int findOtherPeg(int start, int end)
{
    if((start == 1 && end == 2) || (start == 2 && end == 1 ))
        return 3;
    else if((start == 1 && end == 3) || (start == 3 && end == 1 ))
        return 2;
    else
        return 1;
}
