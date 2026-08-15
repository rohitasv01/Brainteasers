class Solution {
public:
    int longestPalindrome(string s) {
        int n=s.size(),ans=0;
        bool odd=false;
        vector<int> hash(256,0);
        for(auto it:s)
        {
            hash[it]++;
        }
        for(int i=0;i<256;i++)
        {
            if(hash[i]%2==0)    ans+=hash[i];
            else
            {
                odd=true;
                ans+=hash[i]-1;
            }
        }
        if(odd) return ans+1;
        else return ans;
    }
};