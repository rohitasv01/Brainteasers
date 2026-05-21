class Solution {
public:
    void bfs(int i,int j ,vector<vector<int>> &grid,vector<vector<int>>& visited)
    {
        int n=grid.size();
        int m=grid[0].size();
        int dx[4]={1,0,-1,0};
        int dy[4]={0,1,0,-1};
        queue<pair<int,int>>q;
        q.push({i,j});
        visited[i][j]=1;
        while(q.size())
        {
            auto[x,y]=q.front();
            q.pop();
           for(int i=0;i<4;i++)
        {
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx>=0 && ny>=0 && nx<n && ny<m && grid[nx][ny]==0 && visited[nx][ny]==-1)
            {
                visited[nx][ny]=1;
                q.push({nx,ny});
            }
        }
        }
    }
    int closedIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> visited(n,vector<int>(m,-1));
        //first and last row
        for(int i=0;i<m;i++)
        {
            if(grid[0][i]==0 && visited[0][i]==-1)  bfs(0,i,grid,visited);
            if(grid[n-1][i]==0 && visited[n-1][i]==-1)  bfs(n-1,i,grid,visited);
        }
        //first and last col
        for(int i=0;i<n;i++)
        {
            if(grid[i][0]==0 && visited[i][0]==-1)  bfs(i,0,grid,visited);
            if(grid[i][m-1]==0 && visited[i][m-1]==-1)  bfs(i,m-1,grid,visited);
        }
        int count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==0 && visited[i][j]==-1)  
                {
                    count++;
                    bfs(i,j,grid, visited);
                }
            }
        }
        return count;
    }
};