class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>> visited(n,vector<bool> (m,false));
        queue<pair<int,int>> q;
        //first and last row
        for(int i=0;i<m;i++)
        {
            if(grid[0][i]==1 && !visited[0][i])
            {
                q.push({0,i});
                visited[0][i]=true;
            }
            if(grid[n-1][i]==1 && !visited[n-1][i])
            {
                q.push({n-1,i});
                visited[n-1][i]=true;
            }
        }
        //first and last column
        for(int i=0;i<n;i++ )
        {
            if(grid[i][0]==1 && !visited[i][0])
            {
                q.push({i,0});
                visited[i][0]=true;
            }
            if(grid[i][m-1]==1 && !visited[i][m-1])
            {
                q.push({i,m-1});
                visited[i][m-1]=true;
            }
        }
        int no=0;
        while(q.size())
        {
            auto[x,y]=q.front();
            q.pop();
            no++;
            int dx[4]={0,1,0,-1};
            int dy[4]={1,0,-1,0};
            for(int i=0;i<4;i++)
            {
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(nx>=0 && ny>=0 && nx<n && ny<m && !visited[nx][ny] && grid[nx][ny]==1)
                {
                    visited[nx][ny]=true;
                    q.push({nx,ny});
                }
            }
        }
        int ones=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)   ones++;
            }
        }
        return ones-no;
    }
};