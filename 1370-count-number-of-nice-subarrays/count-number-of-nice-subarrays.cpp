class Solution {
public:
    int lessThanEqualTo(vector<int> arr, int no)
    {   if (no<0)   return 0;
        int n=arr.size(),l=0,r=0,oddCount=0,num=0;
        while(r<n)
        {
            oddCount+=arr[r]%2;
            while(oddCount>no)
            {
                if(arr[l]%2==1)     oddCount--;
                l++;
            }
            if(oddCount<=no) // redundant condition actually
               num+=r-l+1;
            r++;
        }
        return num;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return lessThanEqualTo(nums,k)-lessThanEqualTo(nums,k-1);
    }
};