class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        vector<int> occurence;
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            if(s[i]==c) occurence.push_back(i);
        }
        occurence.push_back(INT_MAX);
        int p1=0;
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            ans.push_back(min(abs(i-occurence[p1]),abs(i-occurence[p1+1])));
            if(abs(i-occurence[p1])>=abs(i-occurence[p1+1]))    p1++;
        }
        return ans;
    }
};