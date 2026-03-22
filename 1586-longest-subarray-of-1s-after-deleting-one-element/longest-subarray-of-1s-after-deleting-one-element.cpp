class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int l=0,r=0,n=nums.size(),maxLen=0,zeros=0;
        while(r<n)
        {
            if(nums[r]==0)  zeros++;
            while(zeros>1)
            {
                if(nums[l]==0)  zeros--;
                l++;
            }
            maxLen=max(maxLen,r-l+1);
            r++;
        }
        return maxLen-1;
    }
};