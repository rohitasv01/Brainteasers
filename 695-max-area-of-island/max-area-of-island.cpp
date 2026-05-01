class Solution {
public:
    int bfs(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& visited)
    {
        int dx[4]={1,0,-1,0};
        int dy[4]={0,1,0,-1};
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>>q;
        q.push({i,j});
        visited[i][j]=1;
        int area=1;
        while(q.size())
        {
            auto[x,y]=q.front();
            q.pop();
            for(int k=0;k<4;k++)
            {
                int nx=x+dx[k];
                int ny=y+dy[k];
                if(nx>=0 && ny>=0 && nx<n && ny<m && grid[nx][ny]==1 && visited[nx][ny]==-1)
                {
                    area++;
                    visited[nx][ny]=1;
                    q.push({nx,ny});
                }   
            }
        }
        return area;

    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int maxArea=0;
        vector<vector<int>> visited(n,vector<int>(m,-1));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1 && visited[i][j]==-1)
                {
                    int area=bfs(i,j,grid,visited);
                    maxArea=max(area,maxArea);
                }
            }
        }
        return maxArea;
    }
};