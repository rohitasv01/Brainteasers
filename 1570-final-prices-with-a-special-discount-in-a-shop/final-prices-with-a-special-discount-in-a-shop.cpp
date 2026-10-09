class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack <int> st;
        vector<int> ans=prices;
        for(int i=ans.size()-1;i>=0;i--)
        {
            while(st.size() && prices[i]<st.top())  st.pop();
            if(st.size())   ans[i]=prices[i]-st.top();
            st.push(prices[i]);
        }
        return ans;
    }
};