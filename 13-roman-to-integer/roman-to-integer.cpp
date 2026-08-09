class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> mp{{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
        int n=s.size(),sum=0;
        for(int i=0;i<n;i++)
        {
            int val1=mp[s[i]];
            int val2=0;
            if(i<n-1)   val2=mp[s[i+1]];
            if(val1>=val2)   sum+=val1;
            else sum -=val1;
        }
        return sum;
    }
};