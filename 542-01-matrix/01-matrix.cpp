class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>> dist(n,vector<int>(m,-1));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==0)
                {
                    dist[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        int dx[4]={1,0,-1,0};
        int dy[4]={0,1,0,-1};
        while(q.size()!=0)
        {
            auto [x,y]=q.front();
            q.pop();
            for(int i=0;i<4;i++)
            {
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(nx>=0 && nx<n && ny>=0 && ny<m && dist[nx][ny]==-1)
                {
                    dist[nx][ny]=dist[x][y]+1;
                    q.push({nx,ny});
                }
            }
        }
        return dist;
    }
};