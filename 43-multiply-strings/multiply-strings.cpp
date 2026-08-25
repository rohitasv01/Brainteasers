class Solution {
public:
    string add(string s1,string s2)
    {
        int p1=s1.size()-1,p2=s2.size()-1;
        string ans="";
        int carry=0;
        while(p1>=0 || p2>=0 || carry>0)
        {
            int sum=carry;
            if(p1>=0)
            {
                sum+=s1[p1]-'0';
                p1--;
            }
            if(p2>=0)
            {
                sum+=s2[p2]-'0';
                p2--;
            }
            ans+=char(sum%10+'0');
            carry=sum/10;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    string helper(string num1 ,char digit)
    {
        string ans="";
        int p1=num1.size()-1;
        int carry=0;
        while(p1>=0 || carry>0)
        {
            int sum=carry;
            if(p1>=0)
            {
                sum+=(num1[p1]-'0')* (digit-'0');
                p1--;
            }
            ans+=char(sum%10+'0');
            carry=sum/10;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    string multiply(string num1, string num2) {
        if (num1=="0" || num2=="0")    return "0";
        int p2=num2.size()-1;
        string ans="";
        int place=0;
        while(p2>=0)
        {
            string unit_mul=helper(num1,num2[p2]);
            for(int i=0;i<place;i++)
            {
                unit_mul+='0';
            }
            ans=add(ans,unit_mul);
            place++;
            p2--;
        }
        return ans;
    }
};