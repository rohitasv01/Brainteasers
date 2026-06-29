class Solution {
public:
    int solve(int i,int j, vector<vector<int>> &dp,vector<vector<int>> & triangle)
    {
        int n=triangle.size();
        if(i==n-1)  return triangle[i][j];
        if(dp[i][j]!=INT_MAX)   return dp[i][j];
        return dp[i][j]=triangle[i][j]+min(solve(i+1,j,dp,triangle),solve(i+1,j+1,dp,triangle));
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>> dp(n,vector<int>(n,INT_MAX));
        return solve(0,0,dp,triangle);
    }
};