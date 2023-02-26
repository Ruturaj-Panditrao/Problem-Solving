#include <vector>
#include <iostream>
using namespace std;

void printPaths(int row, int col, int drow, int dcol, vector<vector<int>>&maze,string path)
{   
    if(row > drow || col > dcol || row<0 || col<0)
    {
        return;
    }
    if(row == drow && col == dcol)
    {
        cout<<path<<endl;
        return;
    }

    // Top Move
    if(row-1>=0 && maze[row-1][col]!=1)
    {
        maze[row-1][col] = 1;
        printPaths(row-1,col,drow,dcol,maze,path + "t");
        maze[row-1][col] = 0;
    }

    // Left Move
    if(col-1>=0 && maze[row][col-1]!=1)
    {
        maze[row][col-1] = 1;
        printPaths(row,col-1,drow,dcol,maze, path + "l");
        maze[row][col-1] = 0;
    }

    // Down Move
    if(row+1<=drow && maze[row+1][col]!=1)
    {
        maze[row+1][col] = 1;
        printPaths(row+1,col,drow,dcol,maze, path + "d");
        maze[row+1][col] = 0;
    }

    // Right Move
    if(col+1<=dcol && maze[row][col+1]!=1)
    {
        maze[row][col+1] = 1;
        printPaths(row,col+1,drow,dcol,maze, path + "r");
        maze[row][col+1] = 0;
    }
    return;
}
int main()
{
    vector<vector<int>>maze =  {{0,1,0,0,0,0,0},
                                {0,1,0,1,1,1,0},
                                {0,0,0,0,0,0,0},
                                {1,0,1,1,0,1,1},
                                {1,0,1,1,0,1,1},
                                {1,0,0,0,0,0,0}};

    printPaths(0,0,5,6,maze,"");
}
