    class Solution {
    public:
        string reverseWords(string s) {
            string ans="",word="";
            s=" "+s;
            int n=s.size();
            for(int i=n-1;i>=0;i--)
            {
                if(s[i]==' ') 
                {
                    if(!word.empty())
                    {
                        reverse(word.begin(),word.end());
                        ans+=word + " ";
                        word="";
                    }
                    while(i>0 && s[i-1]==' ') i--;
                } 
                else word+=s[i];
            }
            if(ans.empty()==false)  ans.pop_back();
            return ans;
        }
    };