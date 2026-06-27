class Solution {
public:
    int solve(int r1,int c1,int r2,vector<vector<vector<int>>> &dp,vector<vector<int>> &grid)
    {
        int n=grid.size();
        int c2=r1+c1-r2;
        if(r1<0 || r1>=n ||c1<0 || c1>=n || r2<0 || r2>=n ||c2<0 ||c2>=n)  return INT_MIN;
        if(grid[r1][c1]==-1 || grid[r2][c2]==-1)    return INT_MIN;
        int curr;
        if(r1==r2 && c1==c2)    curr=grid[r1][c1];
        else    curr=grid[r1][c1]+grid[r2][c2];
        if(r1==n-1 && c1==n-1 && r2==n-1 && c2==n-1)    return curr;
        if(dp[r1][c1][r2]!=INT_MAX) return dp[r1][c1][r2];
        return dp[r1][c1][r2]=curr +max({solve(r1+1,c1,r2+1,dp,grid),solve(r1+1,c1,r2,dp,grid),solve(r1,c1+1,r2+1,dp,grid),solve(r1,c1+1,r2,dp,grid)});
        //dd,dr,rd,rr
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(n,vector<int>(n,INT_MAX)));
        //dp[r1][c1][r2]
        return max(0,solve(0,0,0,dp,grid));
    }
};