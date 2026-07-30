class Solution {
public:
    long long ab,bc,ac,abc;
    long long count(long long mid,int a,int b,int c)
    {
        return mid/a + mid/b +mid/c -mid/ab-mid/bc-mid/ac+mid/abc;
    }
    int nthUglyNumber(int n, int a, int b, int c) {
        long long start=1,end=2*1e9,ans=-1;
        ab=lcm(1LL*a,1LL*b);
        bc=lcm(1LL*b,1LL*c);
        ac=lcm(1LL*a,1LL*c);
        abc=lcm(1LL*a,lcm(1LL*b,1LL*c));
        while(start<=end)
        {
            long long mid=start+(end-start)/2;
            if(count(mid,a,b,c)>=n) 
            {
                ans=mid;
                end=mid-1;
            }
            else start=mid+1;
        }
        return ans;
    }
};