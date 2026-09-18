class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int>st;
        for(string s:operations)
        {
            if(s=="D")  st.push(2 * st.top());
            else if(s=="C")  st.pop();
            else if(s=="+")
            {
                int top=st.top();
                st.pop();
                int latest =top+st.top();
                st.push(top);
                st.push(latest);
            }
            else st.push(stoi(s));
        }
        int ans=0;
        while(st.size())
        {
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};