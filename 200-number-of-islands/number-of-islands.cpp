class Solution {
public:
    void bfs(int i,int j,vector<vector<char>>&grid, vector<vector<int>>&visited)
    {
        int dx[4]={1,0,-1,0};
        int dy[4]={0,1,0,-1};
        int n=grid.size();
        int m=grid[0].size();
        visited[i][j]=1;
        queue<pair<int,int>>q;
        q.push({i,j});
        while(q.size())
        {
            auto[x,y]=q.front();
            q.pop();
            for(int k=0;k<4;k++)
            {
                int nx=x+dx[k];
                int ny=y+dy[k];
                if(nx>=0 && ny>=0 && nx<n && ny<m && grid[nx][ny]=='1' &&visited[nx][ny]==-1)
                {
                    visited[nx][ny]=1;
                    q.push({nx,ny});
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>visited(n,vector<int>(m,-1));
        int islands=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1' && visited[i][j]==-1)
                {
                    islands++;
                    bfs(i,j,grid,visited);
                }
            }
        }
        return islands;
    }
};