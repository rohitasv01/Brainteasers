class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.size(),l=0,r=0,count=0;
        vector <int> hash(3,0);
        while(r<n)
        {
            hash[s[r]-'a']++;
            while( hash[0]>0 &&  hash[1]>0 &&  hash[2]>0)
            {
                count+=n-r;
                hash[s[l]-'a']--;
                l++;
            }
            r++;
        }
        return count;
    }
};