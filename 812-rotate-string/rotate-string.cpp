class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size()!=goal.size())   return false;
        int n=s.size(),p1;
        for(int i=0;i<n;i++)
        {
            if(s[0]==goal[i])
            {
                p1=i;
                bool flag=true;
                for(int i=0;i<n;i++)
                {
                    if(s[i]!=goal[(i+p1)%n])    flag =false;
                }
                if(flag==true)  return true;
            }
        }
        return false;
    }
};