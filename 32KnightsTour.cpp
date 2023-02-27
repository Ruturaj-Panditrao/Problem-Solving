#include <iostream>
using namespace std;

void printBoard(int board[5][5])
{
    for(int i=0; i<5; i++)
    {
        for(int j=0; j<5; j++)
        {
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
void knightsTour(int row, int col, int n, int board[5][5], int move)
{
    if(row < 0 || col < 0 || row >= n || col >=n || board[row][col]>0)
    {
        return;
    }

    else if(move == n*n)
    {
        board[row][col] = move;
        printBoard(board);
        board[row][col] = 0;
        return;
    }

    board[row][col] = move;

    knightsTour(row-2,col+1,n,board,move+1);
    knightsTour(row-1,col+2,n,board,move+1);
    knightsTour(row+1,col+2,n,board,move+1);
    knightsTour(row+2,col+1,n,board,move+1);
    knightsTour(row+2,col-1,n,board,move+1);
    knightsTour(row+1,col-2,n,board,move+1);
    knightsTour(row-1,col-2,n,board,move+1);
    knightsTour(row-2,col-1,n,board,move+1);

    board[row][col] = 0;

}
int main()
{
    int board[5][5];

    for(int i=0; i<5; i++)
    {
        for(int j=0; j<5; j++)
        {
            board[i][j] = 0;
        }
    }
    knightsTour(2,0,5,board,1);
}
