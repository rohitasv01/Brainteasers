class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n=pushed.size();
        stack<int> st;
        int p1=0;
        for(int no:pushed)
        {
           st.push(no);
           while(p1<n && st.size() && st.top()==popped[p1])
           {
            st.pop();
            p1++;
           }
        }
        return st.empty();
    }
};