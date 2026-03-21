class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.size(),l=0,r=0,count=0;
        vector <int> hash(3,-1);
        for(int i=0;i<n;i++)
        {
            hash[s[i]-'a']=i;
            if(hash[0]>=0 && hash[1]>=0 && hash[2]>=0 )
            {
                count +=1+min(hash[0],min (hash[1],hash[2]));
            }
        }
        return count;
    }
};