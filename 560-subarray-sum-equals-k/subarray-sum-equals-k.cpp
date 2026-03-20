class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        int count=0,prefixSum=0;
        mpp[0]=1;
        for(int i=0;i<nums.size();i++)
        {
            prefixSum+=nums[i];
            int req=prefixSum-k;
            count+=mpp[req];
            mpp[prefixSum]++;
        }
        return count;
    }
};