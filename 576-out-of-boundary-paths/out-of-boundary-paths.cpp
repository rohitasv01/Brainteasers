class Solution {
public:
    int solve(int i,int j, int moves,int m,int n,vector<vector<vector<int>>>&dp)
    {
        if(i<0 || i>=m || j<0 ||j>=n)   return 1;
        if(moves==0)    return 0;
        if(dp[i][j][moves]!=INT_MAX)    return dp[i][j][moves];
        int dx[4]={0,1,0,-1};
        int dy[4]={1,0,-1,0};
        int sum=0,mod=1e9+7;
        for(int k=0;k<4;k++)
        {
            sum=(sum+solve(i+dx[k],j+dy[k],moves-1,m,n,dp))%mod;
        }
        return dp[i][j][moves]=sum;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>> dp(m,vector<vector<int>>(n,vector<int>(maxMove+1,INT_MAX)));
        int mode=1e9+7;
        return (solve(startRow,startColumn,maxMove,m,n,dp))%mode;
    }
};