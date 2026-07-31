class Solution {
public:
//smallest distance with pair>=k
    int count(int mid,vector<int> & nums)
    {
        int no=0;
        int left=0;
        for(int right=0;right<nums.size();right++)
        {
            while(nums[right]-nums[left]>mid)   left++;
            no+=right-left;
        }
        return no;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        int start=0,ans=-1,end=*max_element(nums.begin(),nums.end())-*min_element(nums.begin(),nums.end());
        sort(nums.begin(),nums.end());
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(count(mid,nums)>=k)
            {
                ans=mid;
                end=mid-1;
            }
            else start=mid+1;
        }
        return ans;
    }
};