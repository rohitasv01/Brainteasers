class Solution {
public:
    int myAtoi(string s) {
        long long ans=0;
        int n=s.size() ;
        bool positive=true;
        // "1 -23",-26
        //"   -56"   "    -ab43"
        int index=0;
        while(index<n && s[index]==' ') index++;
        if(s[index]=='-')
        {
            positive=false;
            index++;
        }
        else if(s[index]=='+')  index++;
        for(int i=index;i<n;i++)
        {
            if(s[i]<='9' && s[i]>='0')
            {
                ans=ans*10+s[i]-'0';
                if(ans>=INT_MAX && positive)    return INT_MAX;
                if(ans>=(long long)INT_MAX+1 && !positive) return INT_MIN;
            }
            else break;
        }
        if(positive) return ans;
        else return -ans;
    }
};