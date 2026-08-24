class Solution {
public:
    string minWindow(string s, string t) {
        int l1=s.size(),l2=t.size();
        string ans="";
        if(l2>l1)   return ans;
        vector<int> hash1(256,0);
        vector<int> hash2(256,0);
        for(int i=0;i<l2;i++)   hash2[t[i]]++;
        int l=0,minSize=INT_MAX,startIndex=-1;
        for(int r=0;r<l1;r++)
        {
            hash1[s[r]]++;
            while(true)
            {
                bool same =true;
                for(int i=0;i<256;i++)
                {
                    if(hash1[i]<hash2[i])   
                    {
                        same =false;
                        break;
                    }
                }
                if(!same) break;
                if(r-l+1<minSize)
                {
                    minSize=r-l+1;
                    startIndex=l;
                }
                hash1[s[l]]--;
                l++;
            }
        }
        if(startIndex==-1) return "";
        return s.substr(startIndex,minSize);
    }
};