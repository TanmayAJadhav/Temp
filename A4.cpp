#include<bits/stdc++.h>
using namespace std;
int N;


bool isSafebacktrack(int row, int col, vector<vector<int>>&board)
{
    for(int i = 0; i < col; i++)
    {
        if(board[row][i])
        {
            return false;
        }
    }
    for(int i = row, j = col; i >= 0 &&  j >= 0 ; i--, j--)
    {
        if(board[i][j])
        {
            return false;
        }
    }
    
    for(int i = row, j = col; i < N &&  j >= 0 ; i++, j--)
    {
        if(board[i][j])
        {
            return false;
        }
    }

}

bool solvebacktrack(int col, vector<vector<int>>&board)
{
    if(col >= N)
    {
        return true;
    }
    for(int row = 0; row < N; row++)
    {
        if(isSafebacktrack(row,col,board))
        {
            board[row][col] = 1;
            if(solvebacktrack(col+1,board))
            {
                return true;
            }
            board[row][col] = 0;
        }
    }
    return false;
}

bool isSafebacktrack(int row, int col,vector<bool>rows, vector<bool>left_diagonal, vector<bool>right_diagonal)
{
    if(rows[row] || left_diagonal[row+col] || right_diagonal[col-row+N-1])
    {
        return false;
    }
    return true;
}

bool solvebranch(int col, vector<vector<int>>&board, vector<bool>rows, vector<bool>left_diagonal, vector<bool>right_diagonal)
{
    if(col >= N)
    {
        return true;
    }

    for(int row = 0; row < N; row++)
    {
        if(isSafebacktrack(row,col,rows,left_diagonal,right_diagonal))
        {
            rows[row] = true;
            left_diagonal[row+col] = true;
            right_diagonal[col-row+N-1] = true;
            board[row][col] = 1;

            if(solvebranch(col+1,board,rows,left_diagonal,right_diagonal))
            {
                return true;
            }   

            rows[row] = false;
            left_diagonal[row+col] = false;
            right_diagonal[col-row+N-1] = false;
            board[row][col] = 0;
        }
    }
    return false;
}

int main()
{
    N = 4;
    vector<vector<int>>board(N,vector<int>(N,0));
    bool ans=false;
    // ans= solvebacktrack(0,board);

    vector<bool>rows(N);
    vector<bool>left_diagonal(2*N-1);
    vector<bool>right_diagonal(2*N-1);

    ans = solvebranch(0,board,rows,left_diagonal,right_diagonal);
    if(ans)
    {
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < N; j++)
            {
                cout<<board[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}
