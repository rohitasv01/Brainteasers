class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        int n=words.size();
        vector<vector<int>> hash(n,vector<int>(26,0));
        for(int i=0;i<n;i++)
        {
            for(auto it:words[i])
            {
                hash[i][it-'a']++;
            }
        }
        vector<string> ans;
        for(int i=0;i<26;i++)
        {
            int mini=INT_MAX;
            for(int j=0;j<n;j++)
            {
                mini=min(mini,hash[j][i]);
            }
            for(int k=0;k<mini;k++) ans.push_back(string(1,i+'a'));
        }
        return ans;
    }
};