class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==0)      return 0;
        int p1=0,p2=1;
        while(p2<nums.size())
        {
            if(nums[p1]==nums[p2])  
            {
                p2++;
            }
            else
            {
                nums[p1+1]=nums[p2];
                p1++;
                p2++;
            }
        }
        return p1+1;
    }
};