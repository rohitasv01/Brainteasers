class Solution {
public:
     static bool cmp(pair<char,int> &a,pair<char,int>&b)
        {
            return a.second>b.second;
        }
    string frequencySort(string s) {
        unordered_map<char,int> frequency;
        for(auto it:s)
        {
            frequency[it]++;
        }
        vector<pair<char,int>> v;
        for(auto[ch,freq]:frequency)
        {
            v.push_back({ch,freq});
        }
        string ans="";
        sort(v.begin(),v.end(),cmp);
        for( auto[ch,freq]:v)
        {
            for(int i=0;i<freq;i++)     ans+=ch;
        }
        return ans;
    }
};