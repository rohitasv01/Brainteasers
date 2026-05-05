class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>>visited(n,vector<int>(n,-1));
        if(grid[0][0]!=0 || grid[n-1][n-1]!=0)  return -1;
        queue<pair<int,int>>q;
        q.push({0,0});
        visited[0][0]=1;
        int len=0;
        int dx[8]={1,1,0,-1,-1,-1,0,1};
        int dy[8]={0,1,1,1,0,-1,-1,-1};
        while(q.size())
        {
            int size=q.size();
            len++;
            for(int i=0;i<size;i++)
            {
                auto[x,y]=q.front();
                q.pop();
                if(x==n-1 && y==n-1)    return len;
                for(int k=0;k<8;k++)
                {
                    int nx=x+dx[k];
                    int ny=y+dy[k];
                    if(nx>=0 && ny>=0 && nx<n && ny<n && visited[nx][ny]==-1 && grid[nx][ny]==0)
                    {
                        q.push({nx,ny});
                        visited[nx][ny]=1;
                    }
                }
            }
        }
        return -1;
    }
};