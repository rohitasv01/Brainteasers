class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n=maze.size();
        int m=maze[0].size();
        int u=entrance[0];
        int v=entrance[1];
        maze[u][v]='+';
        queue<tuple<int,int,int>>q;
        q.push({u,v,0});
        int dx[4]={1,0,-1,0};
        int dy[4]={0,1,0,-1};
        while(q.size())
        {
            auto [x,y,dist]=q.front();
            q.pop();
            for(int i=0;i<4;i++)
            {
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(nx>=0 && ny>=0 && nx<n && ny<m && maze[nx][ny]=='.')
                {
                    if(nx==0 || ny==0 ||nx==n-1 || ny==m-1) return dist+1;
                    q.push({nx,ny,dist+1});
                    maze[nx][ny]='+';
                }
            }
        }
        return -1;
    }
};