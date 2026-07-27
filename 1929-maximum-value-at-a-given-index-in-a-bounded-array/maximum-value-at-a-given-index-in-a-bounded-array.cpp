class Solution {
public:
    long long getSum(int a,int b)
    {
        long long sum=0;
        if(a<b)    
        sum+=(1LL)*a*(a+1)/2 + (b-a);
        else
        sum+=(1LL)*b*(2*a-b+1)/2;
        return sum;
    }
    bool isPossible(int mid,int n,int index,int maxSum)
    {
        long long sum=getSum(mid,index+1)+getSum(mid,n-index)-mid;
        if(sum<=maxSum) return true;
        else return false;
    }
    int maxValue(int n, int index, int maxSum) {
        int start=1,end=maxSum,ans=-1;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if (isPossible(mid,n,index,maxSum))
            {
                ans=mid;
                start=mid+1;
            }
            else    end=mid-1;
        }
        return ans;
    }
};