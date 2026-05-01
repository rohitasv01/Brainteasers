class Solution {
public:
    void bfs(int i,int j,vector<vector<char>>& board ,vector<vector<int>>&visited)
    {
        int n=board.size();
        int m=board[0].size();
        int dx[4]={1,0,-1,0};
        int dy[4]={0,1,0,-1};
        queue<pair<int,int>>q;
        q.push({i,j});
        visited[i][j]=1;
        while(q.size())
        {
            auto[x,y]=q.front();
            q.pop();
            for(int k=0;k<4;k++)
            {
                int nx=x+dx[k];
                int ny=y+dy[k];
                if(nx>=0 && ny>=0 &&nx<n && ny<m && board[nx][ny]=='X' && visited[nx][ny]==-1)
                {
                    q.push({nx,ny});
                    visited[nx][ny]=1;
                }
            }
        }
    }
    int countBattleships(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>> visited(n,vector<int>(m,-1));
        int count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]=='X'&& visited[i][j]==-1)
                {
                    bfs(i,j,board,visited);
                    count++;
                }
            }
        }
        return count;
    }
};