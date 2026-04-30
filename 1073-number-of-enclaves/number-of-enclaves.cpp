class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> visited(n,vector<int>(m,-1));
        queue<pair<int,int>>q;
        //first and last row
        for(int i=0;i<m;i++)
        {
            if(grid[0][i]==1)  
            {
                q.push({0,i});
                visited[0][i]=1;
            } 
            if(grid[n-1][i]==1)
            {
                q.push({n-1,i});
                visited[n-1][i]=1;
            } 
        }
        //first and last column
        for(int i=0;i<n;i++)
        {
            if(grid[i][0]==1)
            {
                q.push({i,0});
                visited[i][0]=1;
            }   
            if(grid[i][m-1]==1) 
            {
                q.push({i,m-1});
                visited[i][m-1]=1;
            }
        }
        int dx[4]={1,0,-1,0};
        int dy[4]={0,1,0,-1};
        while(q.size()!=0)
        {
            auto[x,y]=q.front();
            q.pop();
            for(int i=0;i<4;i++)
            {
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(nx>=0 && ny>=0 && nx<n && ny<m && visited[nx][ny]==-1 && grid[nx][ny]==1)
                {
                    q.push({nx,ny});
                    visited[nx][ny]=1;
                }
            }
        }
        int count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)   count++;
                if(visited[i][j]==1)    count--;
            }
        }
        return count;
    }
};