class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>> val(n,vector<int>(n,INT_MAX));
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>> pq;
        //val,x,y
        pq.push({grid[0][0],0,0});
        int dx[4]={1,0,-1,0};
        int dy[4]={0,1,0,-1};
        while(pq.size())
        {
            auto[v,x,y]=pq.top();
            pq.pop();
            if(x==n-1 && y==n-1)    return v;
            for(int i=0;i<4;i++)
            {
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(nx>=0 && ny>=0 && nx<n && ny<n)
                {
                    int t=max(v,grid[nx][ny]);
                    if(t<val[nx][ny])
                    {
                        val[nx][ny]=t;
                        pq.push({t,nx,ny});
                    }
                }
            }
        }
        return -1;
    }
};