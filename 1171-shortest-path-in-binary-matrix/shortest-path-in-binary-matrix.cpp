class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>> dist(n,vector<int>(n,INT_MAX));
        dist[0][0]=1;
        if(grid[0][0]==1 || grid[n-1][n-1]==1)  return -1;
        if(n==1)    return 1;
        queue<tuple<int,int,int>>q;
        q.push({1,0,0});
        int dx[8]={1,1,0,-1,-1,-1,0,1};
        int dy[8]={0,1,1,1,0,-1,-1,-1};
        while(q.size())
        {
            auto[d,x,y]=q.front();
            q.pop();
            for(int i=0;i<8;i++)
            {
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(nx>=0 && ny>=0 && nx<n && ny<n && grid[nx][ny]==0 && d+1<dist[nx][ny])
                {
                    dist[nx][ny]=1+d;
                    if(nx==n-1 && ny==n-1)  return dist[nx][ny];
                    q.push({dist[nx][ny],nx,ny});
                }
            }
        }
        return -1;
    }
};