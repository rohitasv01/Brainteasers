class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int n1=g.size(),n2=s.size(),ans=0;
        int p1=0,p2=0;
        while(p1<n1 && p2<n2)
        {
            if(g[p1]<=s[p2])
            {
                ans++;
                p1++;
                p2++;
            }
            else    p2++;
        }
        return ans;
    }
};