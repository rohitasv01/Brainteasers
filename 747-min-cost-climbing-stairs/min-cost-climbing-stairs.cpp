class Solution {
public:
    int solve(int n,vector<int> &dp, vector<int> &cost)
    {
        if(n==1 || n==0)    return 0;
        if(dp[n]!=-1)   return dp[n];
        int oneStepCost=solve(n-1,dp,cost)+cost[n-1];
        int twoStepCost=solve(n-2,dp,cost)+cost[n-2];
        return dp[n]=min(oneStepCost,twoStepCost);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int>dp(n+1,-1);
        return solve(n,dp,cost);
    }
};