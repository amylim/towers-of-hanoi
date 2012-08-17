#include <iostream>
#include <math.h>
#include "initialize.h"
#include "disk.h"
#include "queue.h"
using namespace std;

int const DELAY = 250;
int getDiskCount();
int getStartPos();
int getEndPos(int start);
int findOtherPeg(int start, int end);
void shiftRight(int start, int end, int diskCount, Queue<int> board[]);
void shiftLeft(int start, int end, int diskCount, Queue<int> board[]);
void makeValidMove(Queue<int> &a, Queue<int> &b);
void movePiece(Queue<int> &from, Queue<int> &to);

int main(int argc, char *argv[])
{
    int diskCount = getDiskCount();
    int startPos = getStartPos();
    int endPos = getEndPos(startPos);

    Queue<int> peg1(diskCount);
    Queue<int> peg2(diskCount);
    Queue<int> peg3(diskCount);

    switch(startPos)
    {
    case 1:
        for(int i = 1; i <= diskCount; i++)
            peg1.enqueue(i);
        break;
    case 2:
        for(int i = 1; i <= diskCount; i++)
            peg2.enqueue(i);
        break;
    case 3:
        for(int i = 1; i <= diskCount; i++)
            peg3.enqueue(i);
        break;
    default:
        cout << "error in initializing startPeg. " << endl;
        break;
    }

    Queue<int> board[3];
    board[0] = peg1;
    board[1] = peg2;
    board[2] = peg3;

    initialize();
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    
    Disk test;
    test.displayQueue(19, 20, board[0]);
    test.displayQueue(19, 40, board[1]);
    test.displayQueue(19, 60, board[2]);
    delay_output(DELAY);
    
    int findGoal = (startPos == 3) ? 1 : startPos + 1;
    cout << "                    1                   2                   3" << endl;
    
    if(diskCount%2) //case for odd number of disks
    {
        //shift in the same direction of peg
        if(findGoal == endPos) //if end peg is on right
            shiftRight(startPos, endPos, diskCount, board);
        else
            shiftLeft(startPos, endPos, diskCount, board);
    }
    else    //case for even number of disks
    {
        //shift in opposite direction of peg
        int otherPeg = findOtherPeg(startPos, endPos);
        if(findGoal == endPos) //if end peg is on right
            shiftLeft(startPos, otherPeg, diskCount, board);
        else
            shiftRight(startPos, otherPeg, diskCount, board);
    }
    system("PAUSE");
    return EXIT_SUCCESS;
}

int getDiskCount()
{
    cout << "How many disks would you like to use? (3-9) ";
    int count;
    cin >> count;
    while(count < 3)
    {
        cout << "There must be at least 3 disks. Please try again. " << endl;
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

void makeValidMove(Queue<int> &a, Queue<int> &b)
{
     try{
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
        catch(...)
        {
                  cout << "error in makeValidMove()" << endl;
        }
}

void movePiece(Queue<int> &from, Queue<int> &to)
{
    try
    {
        int move = from.peek();
        //cout << "moving disk " << move<< endl;
        from.dequeue(move);
        to.enqueue(move);
    }
    catch(...)
    {
        cout << "Error in moving pieces. " << endl;
    }

}

void shiftRight(int start, int end, int diskCount, Queue<int> board[])
{
    int onePeg = start - 1;
    int otherPeg = end - 1;
    int steps = 0;
    double totalSteps = pow(2.0, (double)diskCount) - 1;
    Disk test;
    while(steps < totalSteps)
    {
        bool cases = (board[onePeg].isEmpty() || board[onePeg].peek() > board[otherPeg].peek()) ? true : false;
        makeValidMove(board[onePeg], board[otherPeg]);
        test.displayQueue(19, 20, board[0]);
        test.displayQueue(19, 40, board[1]);
        test.displayQueue(19, 60, board[2]);
        delay_output(DELAY);
        if(cases)
            board[onePeg].prioritize(board[onePeg].seek(board[onePeg].size()-1));   
        else
            board[otherPeg].prioritize(board[otherPeg].seek(board[otherPeg].size()-1));
        onePeg = (onePeg == 0) ? 2 : onePeg - 1;
        otherPeg = (otherPeg == 0) ? 2 : otherPeg - 1;
        steps++;
        test.displayQueue(19, 20, board[0]);
        test.displayQueue(19, 40, board[1]);
        test.displayQueue(19, 60, board[2]);
        delay_output(DELAY);
    }
}

void shiftLeft(int start, int end, int diskCount, Queue<int> board[])
{
    int onePeg = start - 1;
    int otherPeg = end - 1;
    int steps = 0;
    double totalSteps = pow(2.0, (double)diskCount) - 1;
    Disk test;
    while(steps < totalSteps)
    {
        bool cases = (board[onePeg].isEmpty() || board[onePeg].peek() > board[otherPeg].peek()) ? true : false;
        makeValidMove(board[onePeg], board[otherPeg]);
        test.displayQueue(19, 20, board[0]);
        test.displayQueue(19, 40, board[1]);
        test.displayQueue(19, 60, board[2]);
        delay_output(DELAY);
        if(cases)
            board[onePeg].prioritize(board[onePeg].seek(board[onePeg].size()-1));   
        else
            board[otherPeg].prioritize(board[otherPeg].seek(board[otherPeg].size()-1));
        onePeg = (onePeg == 2) ? 0 : onePeg + 1;
        otherPeg = (otherPeg == 2) ? 0 : otherPeg + 1;
        steps++;
        test.displayQueue(19, 20, board[0]);
        test.displayQueue(19, 40, board[1]);
        test.displayQueue(19, 60, board[2]);
        delay_output(DELAY);
    }
}

int findOtherPeg(int start, int end)
{
    if((start == 1 && end == 2) || (start == 2 && end == 1))
        return 3;
    else if((start == 1 && end == 3) || (start == 3 && end == 1))
        return 2;
    else
        return 1;
}
