class Solution {
public:
    bool isPossible(int mid,int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2)
    {
        long long L=lcm(1LL*divisor1,1LL*divisor2);
        if((mid-mid/divisor1 >=uniqueCnt1) && (mid-mid/divisor2>=uniqueCnt2) && (mid-mid/L>=uniqueCnt1+uniqueCnt2)) return true;
        else return false;
    }
    int minimizeSet(int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2) {
        int start=1,end=2*1e9,ans=-1;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(isPossible(mid,divisor1,divisor2,uniqueCnt1,uniqueCnt2))
            {
                ans=mid;
                end=mid-1;
            }
            else start=mid+1;
        }
        return ans;
    }
};