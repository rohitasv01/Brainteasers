class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
    bool solve(vector<vector<char>>& board)
    {
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(board[i][j]=='.')
                {
                    for(char ch='1';ch<='9';ch++)
                    {
                        if(isValid(i,j,ch,board)) 
                        {
                            board[i][j]=ch;
                             if(solve(board))   return true;

                            board[i][j]='.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }  
    bool isValid(int row,int col,char ch,vector<vector<char>>& board)
    {
        for(int i=0;i<9;i++)
        {
            if(board[row][i]==ch)   return false;
            if(board[i][col]==ch)   return false;
            int boxR=3*(row/3)+i%3;
            int boxC=3*(col/3)+i/3;
            if(board[boxR][boxC]==ch)   return false;
        }
        return true;
    } 
};