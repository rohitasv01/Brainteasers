class Solution {
public:
    bool isPossible(int mid,int m, int n, int k)
    {
        int count=0;
        for(int i=1;i<=m;i++)
        {
            count+=min(n,mid/i);
            if(count>=k)    return true;
        }
        return false;    
    }
    int findKthNumber(int m, int n, int k) {
        int start=1,end=m*n,ans=-1;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if (isPossible(mid,m,n,k)) 
            {
                ans=mid;
                end=mid-1;
            }
            else start=mid+1;
        }
        return ans;
    }
};