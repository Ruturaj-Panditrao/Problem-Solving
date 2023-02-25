#include <iostream>
using namespace std;

void printMazePaths(int row, int col, int drow, int dcol, string path)
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

    // Horizontal Moves
    printMazePaths(row,col+1,drow,dcol,path + "h");
    // Vertical Moves
    printMazePaths(row+1,col,drow,dcol,path + "v");
    return;
}

int main()
{
    printMazePaths(0,0,2,2,"");
}
