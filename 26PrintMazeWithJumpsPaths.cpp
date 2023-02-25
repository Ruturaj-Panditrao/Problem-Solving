#include <iostream>
using namespace std;

void printMazePathsWithJumps(int row, int col,int drow, int dcol, string path)
{
    if(row > drow || col > dcol)
    {
        return;
    }

    if(row == drow && col == dcol)
    {
        cout<<path<<" ";
        return;
    }

    for(int i=1; i<=drow; i++)
    {
        printMazePathsWithJumps(row+i,col,drow,dcol,path + "v" + to_string(i));
    }

    for(int i=1; i<=dcol; i++)
    {
        printMazePathsWithJumps(row,col+i,drow,dcol,path + "h" + to_string(i));
    }

    for(int i=1; i<=drow && i<=dcol; i++)
    {
        printMazePathsWithJumps(row+i,col+i,drow,dcol,path + "d" + to_string(i));
    }

    return;
}
int main()
{
    printMazePathsWithJumps(0,0,2,2,"");
}
