class Solution {
public:
    int solve(int i,int j,int rem,vector<vector<vector<int>>> & dp,vector<vector<int>> &grid,int k)
    {
        int n=grid.size();
        int m=grid[0].size();
        if(i<0 || i>=n || j <0 || j>=m) return 0;
        int newRem=(rem+grid[i][j])%k;
        if(i==n-1 && j==m-1 && newRem==0)  return 1;
        if(dp[i][j][rem]!=INT_MAX)  return dp[i][j][rem];
        int mod=1e9+7;
        return dp[i][j][rem]=(solve(i+1,j,newRem,dp,grid,k)+solve(i,j+1,newRem,dp,grid,k))%mod;
    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(k,INT_MAX)));
        return solve(0,0,0,dp,grid,k);
    }
};