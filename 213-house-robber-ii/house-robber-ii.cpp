class Solution {
public:
    /* make two arrays first ,2 has all elemnts except last , first one will have all exements except first
    ans will be max of the two*/
    int nonCircularRobbing( vector<int> &housesMoney)
    {
        int n=housesMoney.size();
        if(n==1)    return housesMoney[0];
        int prev2=housesMoney[0];
        int prev1=max(housesMoney[0],housesMoney[1]);
        for(int i=2;i< n;i++)
        {
            int curr =max(prev2+housesMoney[i],prev1);
            prev2=prev1;
            prev1=curr;
        }
        return prev1;
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