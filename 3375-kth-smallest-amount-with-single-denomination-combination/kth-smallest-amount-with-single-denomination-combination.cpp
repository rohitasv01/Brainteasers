class Solution {
public:
    long long count(long long mid,vector<int>& coins, int k)
    {
        int n=coins.size();
        long long ans=0;
        for (int mask=1;mask<(1<<n);mask++)
        {
            int no=0;
            long long currLCM=1;
            for(int i=0;i<n;i++)
            {
                if(mask & (1<<i))
                {
                    no++;
                    currLCM=lcm(currLCM,(long long)coins[i]);
                }
            }
            long long multiples=mid/currLCM;
            if(no & 1) ans+=multiples;
            else ans-=multiples;
        }
        return ans;
    }
    long long findKthSmallest(vector<int>& coins, int k) {
        long long start=*min_element(coins.begin(),coins.end());
        long long end=1LL*k*start,ans=-1;
        while(start<=end)
        {
            long long mid=start+(end-start)/2;
            if(count(mid,coins,k)>=k)
            {
                ans=mid;
                end=mid-1;
            }
            else start=mid+1;
        }
        return ans;
    }
};