class Solution {
public:
    long long bfs(int i,int j,vector<vector<int>>& grid,vector<vector<int>> &visited,int k)
    {
        queue<pair<int,int>>q;
        int n=grid.size();
        int m=grid[0].size();
        q.push({i,j});
        visited[i][j]=1;
        int dx[4]={1,0,-1,0};
        int dy[4]={0,1,0,-1};
        long long sum=grid[i][j];
        while(q.size())
        {
            auto[x,y]=q.front();
            q.pop();

            for(int i=0;i<4;i++)
            {
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(nx>=0 && ny>=0 && nx<n && ny<m && grid[nx][ny]!=0 && visited[nx][ny]==-1)
                {
                    q.push({nx,ny});
                    sum+=grid[nx][ny];
                    visited[nx][ny]=1;
                }
            }
        }
        return sum;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        int count=0;
        vector<vector<int>> visited(n,vector<int>(m,-1));
        for(int i=0 ;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]!=0 && visited[i][j]==-1)
                {
                long long sum=bfs(i,j,grid,visited,k);
                if(sum%k==0)    count++;
                }
            }
        }
        return count;
    }
};