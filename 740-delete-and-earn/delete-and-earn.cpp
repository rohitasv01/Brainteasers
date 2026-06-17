class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int maximum=*max_element(nums.begin(),nums.end());
        vector<int> points(maximum+1,0);
        for(int it:nums)
        {
            points[it]+=it;
        }
        int n=maximum+1;
        vector<int> dp(n);
        dp[0]=points[0];
        dp[1]=max(points[0],points[1]);
        for(int i=2;i<n;i++)
        {
            dp[i]=max(dp[i-1],points[i]+dp[i-2]);
        }
        return dp[n-1];
    }
};