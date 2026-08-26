class Solution {
public:
    int numSub(string s) {
        long long count=0,ans=0,mod=1e9+7;
        for(auto it:s)
        {
            if(it=='1') 
            {
                count++;
                ans=(ans+count)%mod;
            }
            else count=0;
        }
        return ans;
    }
};