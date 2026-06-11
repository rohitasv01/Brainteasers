class Solution {
public:
    /* make two arrays first ,2 has all elemnts except last , first one will have all exements except first
    ans will be max of the two*/
    int nonCircularRobbing( vector<int> &housesMoney)
    {
        int n=housesMoney.size();
        if(n==1)    return housesMoney[0];
        vector<int> dp(n);
        dp[0]=housesMoney[0];
        dp[1]=max(housesMoney[0],housesMoney[1]);
        for(int i=2;i< n;i++)
        {
            dp[i]=max(dp[i-2]+housesMoney[i],dp[i-1]);
        }
        return dp[n-1];
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)    return nums[0];
        vector<int> temp1,temp2;
        for(int i=0;i<n;i++)
        {
            if(i!=0)    temp1.push_back(nums[i]);
            if(i!=n-1)  temp2.push_back(nums[i]);
        }
        return max(nonCircularRobbing(temp1),nonCircularRobbing(temp2));
    }
};