class Solution {
public:
    long long count(long long mid,int a,int b)
    {
        return (mid/a)+(mid/b)-(mid/lcm(a,b));
    }
    int nthMagicalNumber(int n, int a, int b) {
        long long start=min(a,b);
        long long end=(1LL)*n*min(a,b),ans=-1;
        while(start<=end)
        {
            long long mid=start+(end-start)/2;
            if(count(mid,a,b)>=n)   
            {
                ans=mid;
                end=mid-1;
            }
            else start=mid+1;
        }
        int mod=1e9+7;
        return ans % mod;
    }
};