class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> hash1(26,0);
        vector<int> hash2(26,0);
        for(auto it:s) hash1[it-'a']++;
        for(auto it:t)  hash2[it-'a']++;
        for(int i=0;i<26;i++)
        {
            if(hash1[i]!=hash2[i])  return i+'a';
        }
        return ' ';
    }
};