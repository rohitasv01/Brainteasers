class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string s1="",s2="";
        for(auto it :s)
        {
            if(it=='#') 
            {
                if(s1.size()!=0)    s1.pop_back();
            }
            else s1+=it;
        }
        for(auto it:t)
        {
            if(it=='#' )
            {
                if(s2.size()!=0)    s2.pop_back();
            }
            else s2+=it;
        }
        if(s1==s2)  return true;
        else return false;
    }
};