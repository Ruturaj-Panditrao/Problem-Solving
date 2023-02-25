#include <vector>
#include <iostream>
using namespace std;

vector<string>getMazePathJumps(int row, int col, int drow, int dcol)
{
    if(row>drow || col>dcol) 
    // This case is not actually required,
    // Because our for loop while making recursive calls ensures that
    // Only valid recursion calls are being made
    {
        return {};
    }

    if(row == drow && col == dcol)
    {
        return {""};
    }

    vector<string>pathAnswers;
    for(int i=1; i<=dcol; i++)
    {
        // Horizontal Moves
        vector<string>hmoves = getMazePathJumps(row,col+i,drow,dcol);
        for(auto it : hmoves)
        {
            pathAnswers.push_back('h' + to_string(i) + it);
        }
    }
    for(int i=1; i<=drow; i++)
    {
        // Vertical Moves
        vector<string>vmoves = getMazePathJumps(row+i,col,drow,dcol);
        for(auto it : vmoves)
        {
            pathAnswers.push_back('v' + to_string(i) + it);
        }
    }
     for(int i=1; i<=drow && i<=col; i++)
    {
        // Diagonal Moves
        vector<string>dmoves = getMazePathJumps(row+i,col+i,drow,dcol);
        for(auto it : dmoves)
        {
            pathAnswers.push_back('d' + to_string(i) + it);
        }
    }

    return pathAnswers;
}
int main()
{
    vector<string>mazePathJumps = getMazePathJumps(0,0,3,3); // 4x4 Matrix
    for(auto it : mazePathJumps) cout<<it<<" ";
}
