class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int oc=image[sr][sc];
        if(oc==color)   return image;
        int n=image.size();
        int m=image[0].size();
        image[sr][sc]=color;
        queue<pair<int,int>>q;
        q.push({sr,sc});
        int dx[4]={1,0,-1,0};
        int dy[4]={0,1,0,-1};
        while(q.size()!=0)
        {
            auto[x,y]=q.front();
            q.pop();
            for(int i=0;i<4;i++)
            {
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(nx>=0 && ny>=0 && nx<n && ny<m && image[nx][ny]==oc)
                {
                    image[nx][ny]=color;
                    q.push({nx,ny});
                }
            }
        }
        return image;
    }
};