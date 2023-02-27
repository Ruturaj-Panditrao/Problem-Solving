#include <iostream>
using namespace std;

bool isSafe(int row, int col, int chessBoard[4][4])
{
    int temprow = row;
    while(temprow--)
    {
        if(chessBoard[temprow][col]==1)
        {
            return false;
        }
    }

    for(int i= row, j = col; i>=0 && j>=0; i-- , j--)
    {
        if(chessBoard[i][j]==1)
        {
            return false;
        }
    }

    for(int i= row, j = col; i>=0 && j<4; i-- , j++)
    {
        if(chessBoard[i][j]==1)
        {
            return false;
        }
    }
    return true;
}
void NQueens(int row, string psf, int n, int chessBoard [4][4] )
{
    if(row==n)
    {
        cout<<psf<<endl;
        return;
    }

    for(int col = 0; col<n; col++)
    {   
        if(isSafe(row,col,chessBoard))
        {
        chessBoard[row][col] = 1;
        NQueens(row+1,psf + to_string(row) + "-" + to_string(col) + " ,",n,chessBoard);
        chessBoard[row][col] = 0;
        }
    }
}
int main()
{
    int chessBoard[4][4];
    for(int i=0;i<4; i++)
    {
        for(int j=0;j<4;j++)
        {
            chessBoard[i][j] = 0;
        }
    }

    NQueens(0,"",4,chessBoard);
}
