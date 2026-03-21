class Solution {
public:
    int atMostK(vector<int> &arr ,int k)
    {
        if(k<=0)    return 0;
        int n=arr.size(),l=0,r=0,count=0;
        unordered_map<int ,int> mpp;
        while(r<n)
        {
            mpp[arr[r]]++;
            while(mpp.size()>k)
            {
                mpp[arr[l]]--;
                if(mpp[arr[l]]==0)  mpp.erase(arr[l]);
                l++;
            }
            count+=r-l+1;
            r++;
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMostK(nums,k)-atMostK(nums,k-1);
    }
};