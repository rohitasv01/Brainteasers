class Solution {
public:
    bool bfs(int i,int j,vector<vector<int>>& grid1,vector<vector<int>>&grid2,vector<vector<int>>&visited)
    {
        int n=grid2.size();
        int m=grid2[0].size();
        queue<pair<int,int>>q;
        q.push({i,j});
        visited[i][j]=1;
        int dx[4]={1,0,-1,0};
        int dy[4]={0,1,0,-1};
        bool isSub=(grid1[i][j]==1);
        while(q.size())
        {
            auto[x,y]=q.front();
            q.pop();
            for(int k=0;k<4;k++)
            {
                int nx=x+dx[k];
                int ny=y+dy[k];
                if(nx>=0 && ny>=0 && nx<n && ny<m && visited[nx][ny]==-1 && grid2[nx][ny]==1)
                {
                    if(grid1[nx][ny]!=1)    isSub=false;
                    else if(grid1[nx][ny]==1)
                    {
                        visited[nx][ny]=1;
                        q.push({nx,ny});
                    }
                }
            }
        }
        return isSub;
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n=grid2.size();
        int m=grid2[0].size();
        vector<vector<int>> visited(n,vector<int>(m,-1));
        int count=0;
        bool yes;
        for(int i=0;i<n;i++)
        {
            for (int j=0;j<m;j++)
            {
                if(grid2[i][j]==1 && visited[i][j]==-1)     
                
                {
                    yes=bfs(i,j,grid1,grid2,visited);
                    if(yes) count++;
                }
            }
        }
        return count;
    }
};