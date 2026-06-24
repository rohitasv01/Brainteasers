class Solution {
public:
    int solve(int i,int j,vector<vector<int>> &dp,vector<vector<int>>& grid)
    {
        int n=grid.size();
        int m=grid[0].size();
        if(j<0 ||j>=m)  return 1e9;
        if(i==n-1)  return grid[i][j];
        if(dp[i][j]!=INT_MAX)   return dp[i][j];
        int mini=INT_MAX;
        for(int k=0;k<m;k++)
        {
            if(k!=j)    mini=min(mini,solve(i+1,k,dp,grid));
        }
        return dp[i][j]=grid[i][j]+mini;
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,INT_MAX));
        int mini=INT_MAX;
        for(int i=0;i<m;i++)
        {
            mini=min(mini,solve(0,i,dp,grid));
        }
        return mini;
    }
};