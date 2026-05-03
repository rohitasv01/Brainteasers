class Solution {
public:
    int bfs(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& visited)
    {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>>q;
        q.push({i,j});
        visited[i][j]=1;
        int dx[4]={1,0,-1,0};
        int dy[4]={0,1,0,-1};
        int sum=0;
        while(q.size())
        {
            auto[x,y]=q.front();
            q.pop();
            sum+=grid[x][y];
            for(int k=0;k<4;k++)
            {
                int nx=x+dx[k];
                int ny=y+dy[k];
                if(nx>=0 && ny>=0 && nx<n && ny<m && grid[nx][ny]!=0 && visited[nx][ny]==-1)
                {
                    q.push({nx,ny});
                    visited[nx][ny]=1;
                }
            }
        }
        return sum;
    }
    int findMaxFish(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>visited(n,vector<int>(m,-1));
        int maxSum=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]!=0 && visited[i][j]==-1) 
                {
                int sum= bfs(i,j,grid,visited);
                maxSum=max(sum,maxSum);
                }
            }
        }
        return maxSum;
    }
};