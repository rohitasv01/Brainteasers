class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char,int> mpp;
        for(char ch:s)  mpp[ch]++;
        stack<char> st;
        vector<bool> seen(26,false);
        for(char ch:s)
        {
            mpp[ch]--;
            if(seen[ch-'a'])    continue;
            while(st.size() && ch<st.top() && mpp[st.top()]>0)
            {
                seen[st.top()-'a']=false;
                st.pop();
            }
            st.push(ch);
            seen[ch-'a']=true;
        }
        string ans;
        while(st.size())   
        {
            ans.push_back(st.top());
            st.pop();
        } 
        reverse(ans.begin(), ans.end());
        return ans;
    }
};