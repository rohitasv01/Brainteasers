class Solution {
public:
    int solve(int i,int j,vector<vector<int>>&dp, vector<vector<int>>&traingle)
    {
        int n=traingle.size();
        if(i==n-1)  return traingle[i][j];
        if(dp[i][j]!=INT_MAX)    return dp[i][j];
        int down=traingle[i][j]+ solve(i+1,j,dp,traingle);
        int diagonal=traingle[i][j]+solve(i+1,j+1,dp,traingle);
        return dp[i][j] =min(down, diagonal);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>> dp(n,vector<int>(n,INT_MAX));
        return solve(0,0,dp,triangle);
    }
};