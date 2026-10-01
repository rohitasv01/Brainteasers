class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string ans;
        int depth=0;
        for(char ch:s)
        {
            if(ch=='(') 
            {
                depth++;
                ans+=ch;
            }
            else if(ch==')')
            {
                if(depth>0) 
                {
                    ans+=ch;
                    depth--;
                }
            }
            else ans+=ch;
        }
        for(int i=ans.size()-1;i>=0;i--)
        {
            if(ans[i]=='(' && depth>0)
            {
                depth--;
                ans.erase(i,1);
            }
        }
        return ans;
    }
};