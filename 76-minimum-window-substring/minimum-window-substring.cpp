class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> hash(256,0);
        int m=s.size(),n=t.size(),l=0,r=0;
        for(int i=0;i<n;i++)    hash[t[i]]++;
        int count=0,sIndex=-1,minLen=INT_MAX;
        while(r<m)
        {
            if(hash[s[r]] >0)   count++;
            hash[s[r]]--;
            while(count==n)
            {
                if(r-l+1<minLen)
                {
                    minLen=r-l+1;
                    sIndex=l;
                }
                hash[s[l]]++;
                if(hash[s[l]]>0)    count--;
                l++;
            }
            r++;
        }
        return sIndex==-1 ? "" : s.substr(sIndex,minLen);
    }
};