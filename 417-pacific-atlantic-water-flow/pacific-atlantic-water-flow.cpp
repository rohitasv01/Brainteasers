class Solution {
public:
    void bfs(int i,int j,vector<vector<int>>& heights,vector<vector<int>>&visited)
    {
        int n=heights.size();
        int m=heights[0].size();
        queue<pair<int,int>>q;
        q.push({i,j});
        visited[i][j]=1;
        int dx[4]={1,0,-1,0};
        int dy[4]={0,1,0,-1};
        while(q.size())
        {
            auto[x,y]=q.front();
            q.pop();
            for(int k=0;k<4;k++)
            {
                int nx=x+dx[k];
                int ny=y+dy[k];
                if(nx>=0 && ny>=0 &&  nx<n && ny<m && heights[nx][ny]>=heights[x][y] && visited[nx][ny]==-1)
                {
                    q.push({nx,ny});
                    visited[nx][ny]=1;
                }
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>> visitedP(n,vector<int>(m,-1));
        vector<vector<int>> visitedA(n,vector<int>(m,-1));
        //top and bottom side
        for(int i=0;i<m;i++)
        {
            if(visitedP[0][i]==-1)  bfs(0,i,heights,visitedP);
            if(visitedA[n-1][i]==-1)    bfs(n-1,i,heights,visitedA);
        }
        //left and right
        for(int i=0;i<n;i++)
        {
            if(visitedP[i][0]==-1)   bfs(i,0,heights,visitedP);
            if(visitedA[i][m-1]==-1) bfs(i,m-1,heights,visitedA);
        }
        vector<vector<int>> adj;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(visitedP[i][j]==1 && visitedA[i][j]==1)
                adj.push_back({i,j});
            }
        }
        return adj;
    }
};