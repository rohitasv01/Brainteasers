class Solution {
public:
    string makeGood(string s) {
        int n=s.size();
        stack<char> st;
        st.push(s[0]);
        for(int i=1;i<n;i++)
        {
            if(st.size() && (st.top()==(s[i]+32) || st.top()==(s[i]-32)))  st.pop();
            else st.push(s[i]);
        }
        string ans;
        while(st.size())   
        {
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};