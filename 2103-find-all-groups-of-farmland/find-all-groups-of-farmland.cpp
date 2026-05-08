class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int n=land.size();
        int m=land[0].size();
        vector<vector<int>>ans;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(land[i][j]==1 )
                {
                    int r=i,c=j;
                    while(r<n && land[r][j]==1) r++;
                    while(c<m && land[i][c]==1) c++;
                    ans.push_back({i,j,r-1,c-1});
                    for(int x=i;x<r;x++)
                    {
                        for(int y=j;y<c;y++)
                        land[x][y]=0;
                    }
                }
            }
        }
        return ans;
    }
};