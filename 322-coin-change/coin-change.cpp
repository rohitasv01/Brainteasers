class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        sort(coins.begin(),coins.end());
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        int ans =solve(n-1,amount,dp,coins);
        if(ans>=1e9)    return -1;
        return ans;
    }
    int solve(int i,int target,vector<vector<int>> &dp, vector<int> &coins)
    {
        if(i==0)    
        {
            if(target % coins[i]==0)  return target/coins[i];
            else return 1e9;
        }
        if(target<0)    return 1e9;
        if(dp[i][target]!=-1)   return dp[i][target];
        int take=1+solve(i,target-coins[i],dp,coins);
        int notTake=solve(i-1,target,dp,coins);
        return dp[i][target]=min(take,notTake);
    }
};