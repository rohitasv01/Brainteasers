class Solution {
public:
    int solve(int i,int j,int prev,vector<vector<int>>& dp,vector<vector<int>>&grid)
    {
        int n=grid.size();
        int m=grid[0].size();
        if(i<0 ||i>=n || j<0 ||j>=m)    return 0;
        if(grid[i][j]<=prev)    return 0;
        if(dp[i][j]!=INT_MAX)   return dp[i][j];
        return dp[i][j]=1+max({solve(i-1,j+1,grid[i][j],dp,grid),solve(i,j+1,grid[i][j],dp,grid),solve(i+1,j+1,grid[i][j],dp,grid)});
    }
    int maxMoves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,INT_MAX));
        int maxi=0;
        for(int i=0;i<n;i++)
        {
            maxi=max(maxi,solve(i,0,INT_MIN,dp,grid));
        }
        return maxi-1;
    }
};