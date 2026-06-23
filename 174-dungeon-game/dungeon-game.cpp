class Solution {
public:
/*dp[i][j]=minimum health needed while entering to reach destination*/
    int solve(int i,int j,vector<vector<int>>&dp,vector<vector<int>>&dungeon)
    {
        int n=dungeon.size();
        int m=dungeon[0].size();
        if(i>=n ||j>=m) return INT_MAX;
        if(i==n-1 && j==m-1)    return max(1,1-dungeon[i][j]);
        if(dp[i][j]!=INT_MAX)   return dp[i][j];
        int needed=min(solve(i+1,j,dp,dungeon),solve(i,j+1,dp,dungeon));
        return dp[i][j]=max(1,needed-dungeon[i][j]);
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n=dungeon.size();
        int m=dungeon[0].size();
        vector<vector<int>> dp(n,vector<int>(m,INT_MAX));
        return solve(0,0,dp,dungeon);
    }
};