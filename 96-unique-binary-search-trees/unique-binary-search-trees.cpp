class Solution {
public:
    //DP[i] -no of unique BST that can be constructed using i nodes
    int numTrees(int n) {
        vector<int> dp(n+1,0);
        dp[0]=1;
        dp[1]=1;
        for(int node=2;node<=n;node++)
        {
            for(int root=1;root<=node;root++)
            {
                int left=dp[root-1];
                int right=dp[node-root];
                dp[node]+=left*right;
            }
        }
        return dp[n];
    }
};