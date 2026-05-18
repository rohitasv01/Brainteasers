class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>> effort(n,vector<int>(m,INT_MAX));
        effort[0][0]=0;
        priority_queue<tuple<int,int,int> ,vector<tuple<int,int,int>>,greater<tuple<int,int ,int>>> pq;
        pq.push({0,0,0});
        int dx[4]={1,0,-1,0};
        int dy[4]={0,1,0,-1};
        while(pq.size())
        {
            auto [eff,x,y]=pq.top();
            pq.pop();
            if(x==n-1 && y==m-1)    return eff;
            for(int i=0;i<4;i++)
            {
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(nx>=0 && ny>=0 && nx<n && ny<m)
                {
                    int newEffort=max(abs(heights[nx][ny]-heights[x][y]),eff);
                    if(newEffort<effort[nx][ny])
                    {
                        effort[nx][ny]=newEffort;
                        pq.push({newEffort,nx,ny});
                    }
                }
            }
        }
        return -1;
    }
};