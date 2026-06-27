class Solution {
public:
    int solve(int r,int c1,int c2, vector<vector<vector<int>>> &dp, vector<vector<int>> &grid)
    {
        int n=grid.size();
        int m=grid[0].size();
        if(r>=n || c1< 0 ||c1>=m ||c2<0 ||c2>=m)  return INT_MIN;
        int val;
        if(c1==c2)  val=grid[r][c1];
        else    val=grid[r][c1]+grid[r][c2];
        if(r==n-1)  return val;
        if(dp[r][c1][c2]!=INT_MAX)  return dp[r][c1][c2];
        return dp[r][c1][c2]=val+max({solve(r+1,c1-1,c2-1,dp,grid),solve(r+1,c1-1,c2,dp,grid),solve(r+1,c1-1,c2+1,dp,grid),solve(r+1,c1,c2-1,dp,grid),solve(r+1,c1,c2,dp,grid),solve(r+1,c1,c2+1,dp,grid),solve(r+1,c1+1,c2-1,dp,grid),solve(r+1,c1+1,c2,dp,grid),solve(r+1,c1+1,c2+1,dp,grid)});
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(m,INT_MAX)));
        return solve (0,0,m-1,dp,grid);
    }
};