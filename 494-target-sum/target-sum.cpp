class Solution {
public:
    int solve(int index,int sum,vector<int> & nums,int & target )
    {   
        if(index==nums.size())
        {
            if(sum==target) return 1;
            else return 0;
        }
        sum+=nums[index];
        int l=solve(index+1,sum,nums,target);
        sum-=nums[index];
        sum-=nums[index];
        int r=solve(index+1,sum,nums,target);
        return l+r;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return solve(0,0,nums,target);
    }
};