class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int mini=INT_MAX,n=strs.size();
        for(int i=0;i<n;i++)
        {
            mini=min(mini,(int)strs[i].size());
        }
        string ans="";
        for(int i=0;i<mini;i++)
        {
            bool same=true;
            for(int j=0;j<n;j++)   
            {
                if(strs[0][i]!=strs[j][i])    same=false;
            } 
            if(same==true)  ans+=strs[0][i];
            else return ans;
        }
        return ans;
    }
};