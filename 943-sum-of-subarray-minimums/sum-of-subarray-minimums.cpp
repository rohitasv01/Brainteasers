class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        stack<int> st;
        int n=arr.size();
        vector<int> pse(n,-1);
        for(int i=0;i<n;i++)
        {
            while(st.size() && arr[i]<arr[st.top()])   st.pop();
            if(st.size())   pse[i]=st.top();
            st.push(i);
        }
        while(st.size())    st.pop();
        long long ans=0;
        int mod=1e9+7;
        vector<int> nse(n,n);
        for(int i=n-1;i>=0;i--)
        {
            while(st.size() && arr[i]<=arr[st.top()])   st.pop();
            if(st.size())   nse[i]=st.top();
            st.push(i);
        }
        for(int i=0;i<n;i++)
        {
            ans=(ans+1LL*arr[i]*(i-pse[i])*(nse[i]-i))%mod;
        }
        return ans;
    }
};