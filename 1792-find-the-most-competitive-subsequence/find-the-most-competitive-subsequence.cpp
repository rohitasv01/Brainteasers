class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        int n=nums.size();
        stack<int> st;
        int removable=n-k;
        for(int i=0;i<n;i++)
        {
            while(st.size() && nums[i]<st.top() && removable>0) 
            {
                st.pop();
                removable--;
            }
            st.push(nums[i]);
        }
        vector<int> ans;
        while(st.size())   
        {
            ans.push_back(st.top());
            st.pop();
        } 
        reverse(ans.begin(), ans.end());
        ans.resize(k);
        return ans;
    }
};