class Solution {
public:
    int beautySum(string s) {
        int n=s.size(),ans=0;
        for(int i=0;i<n;i++)
        {
            int hash[26]={0};
            for(int j=i;j<n;j++)
            {
                hash[s[j]-'a']++;
                int maxi=0,mini=INT_MAX;
                for(int k=0;k<26;k++)
                {
                    if(hash[k]>0)
                    {
                        maxi=max(maxi,hash[k]);
                        mini=min(mini,hash[k]);
                    }
                }
                ans+=maxi-mini;
            }
        }
        return ans;
    }
};