class Solution {
public:
    int lessThanEqualTo(vector<int>& arr,int k)
    {
        if(k<0)     return 0;
        int l=0,r=0,n=arr.size(),sum=0,count=0;
        while(r<n)
        {
            sum+=arr[r];
            while(sum>k)
            {
                sum-=arr[l];
                l++;
            }
            if(sum<=k)//this is optional-always true after coming out of upper condition
            {
                count+=r-l+1;
                r++;
            }
        }
        return count;

    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return lessThanEqualTo(nums,goal)-lessThanEqualTo(nums,goal-1);
    }
};