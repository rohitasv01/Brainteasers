class Solution {
public:
    int nextGreaterElement(int n) {
        int pivot =-1;
        string num=to_string(n);
        for(int i=num.size()-2;i>=0;i--)
        {
            if(num[i]-'0'< num[i+1]-'0')   
            {
                pivot=i;
                break;
            } 
        }
        if(pivot==-1)   return -1;
        int mini=INT_MAX;
        int exchange=-1;
        for(int i=num.size()-1;i>=0;i--)
        {
            if(num[i]-'0'>num[pivot]-'0')   
            {
                exchange=i;
                break;
            }
        }
        swap(num[pivot],num[exchange]);
        reverse(num.begin()+pivot+1,num.end());
        long long ans=stoll(num);
        if(ans>INT_MAX) return -1;
        return ans;
    }
};