class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n=nums.size();
        vector<int> pse(n,-1);
        vector<int> pge(n,-1);
        vector<int> nse(n,n);
        vector<int> nge(n,n);
        stack<int>st;
        for(int i=0;i<n;i++)
        {
            while(st.size() && nums[i]<nums[st.top()])    st.pop();       //monotonic increasing stack
            if(st.size())   pse[i]=st.top();
            st.push(i);
        }
        while(st.size())    st.pop();
        for(int i=n-1;i>=0;i--)
        {
            while(st.size() && nums[i]<=nums[st.top()])     st.pop();       //monotonic increasing stack
            if(st.size())   nse[i]=st.top();
            st.push(i);
        }
        while(st.size())    st.pop();
        for(int i=0;i<n;i++)
        {
            while(st.size() && nums[i]>nums[st.top()])      st.pop();
            if(st.size())   pge[i]=st.top();
            st.push(i);
        }
        while(st.size())    st.pop();
        for(int i=n-1;i>=0;i--)
        {
            while(st.size() && nums[i]>=nums[st.top()]) st.pop();
            if(st.size())   nge[i]=st.top();
            st.push(i);
        }
        long long ans=0;
        for(int i=0;i<n;i++)
        {
            long long maxContri=1LL*nums[i]*((i-pge[i])*(nge[i]-i));
            long long minContri=1LL*nums[i]*((i-pse[i])*(nse[i]-i));
            ans+= (maxContri-minContri);
        }
        return ans;

    }
};