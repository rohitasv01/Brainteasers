class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> obstacles(n,vector<int>(m,INT_MAX));
        obstacles[0][0]=(grid[0][0]==0) ? 0 : 1;
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>pq;
        //obstacles,x,y;
        pq.push({obstacles[0][0],0,0});
        int dx[4]={1,0,-1,0};
        int dy[4]={0,1,0,-1};
        while(pq.size())
        {
            auto[obs,x,y]=pq.top();
            pq.pop();
            if(x==n-1 && y==m-1)    return obs;
            for(int i=0;i<4;i++)
            {
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(nx>=0 && ny>=0 && nx<n && ny<m)
                {
                    int o=(grid[nx][ny]==1) ? obs+1 :obs;
                    if(o<obstacles[nx][ny])
                    {
                        obstacles[nx][ny]=o;
                        pq.push({o,nx,ny});
                    }
                }
            }
        }
        return -1;
    }
};