class Solution {
public:
    //check last occurences no of subtrings will be min of last occurence of all 3 +1
    int numberOfSubstrings(string s) {
        vector<int> hash(3,-1);
        int count=0,n=s.size();
        for(int i=0;i<n;i++)
        {
            hash[s[i]-'a']=i;
            count+=1+min(hash[0],min(hash[1],hash[2]));
        }
        return count;
    }
};