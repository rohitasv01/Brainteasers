class Solution {
public:
/*start from any and we can go 3 ways base ca*/
    int solve(int i,int j,vector<vector<int>> &dp,vector<vector<int>>&matrix)
    {
        int n=matrix.size();
        int m=matrix[0].size();
        if(j<0 ||j>=m)  return 1e9;
        if(i==n-1)  return matrix[i][j];
        if(dp[i][j]!=INT_MAX)   return dp[i][j];
        return dp[i][j]=matrix[i][j]+min({solve(i+1,j-1,dp,matrix),solve(i+1,j,dp,matrix),solve(i+1,j+1,dp,matrix)});
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>> dp(n,vector<int>(m,INT_MAX));
        int mini=INT_MAX;
        for(int i=0;i<m;i++)
        {
            mini=min(mini,solve(0,i,dp,matrix));
        }
        return mini;
    }
};