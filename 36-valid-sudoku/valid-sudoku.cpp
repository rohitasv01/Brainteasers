class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int rows[9][9]={0},cols[9][9]={0},box[9][9]={0};
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(board[i][j]=='.')    continue;
                int num=board[i][j]-'1';
                int boxIndex=3*(i/3)+j/3;
                if(rows[i][num]==1 || cols[j][num]==1 || box[boxIndex][num]==1) return false;
                else rows[i][num]=cols[j][num]=box[boxIndex][num]=1;
            }
        }
        return true;
    }
};