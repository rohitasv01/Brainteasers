class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        return solve(n-1,amount,dp,coins);
    }
    int solve(int i,int amount, vector<vector<int>> &dp, vector<int> &coins)
    {
        if(amount==0)   return 1;
        if(i==0)    return (amount%coins[i]==0);
        if(amount<0)    return 0;
        if(dp[i][amount]!=-1)   return dp[i][amount];
        int take=solve(i,amount-coins[i],dp,coins);
        int notTake=solve(i-1,amount,dp,coins);
        return dp[i][amount]=take+notTake;
    }
};