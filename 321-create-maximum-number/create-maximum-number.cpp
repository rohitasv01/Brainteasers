class Solution {
public:
    vector<int> maxSubsequence(vector<int> &nums , int size)
    {
        int n=nums.size();
        int removable=n-size;
        stack<int> st;
        for(int i=0;i<n;i++)
        {
            while(st.size() && nums[i]>st.top() && removable>0) 
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
        ans.resize(size);
        return ans;
    }
    vector<int> merge(vector<int> & a, vector<int> &b)
    {
        int p1=0,p2=0;
        vector<int> ans;
        while(p1<a.size() || p2<b.size())
        {
            if(p2==b.size() || (p1<a.size() && lexicographical_compare(b.begin()+p2,b.end(), a.begin()+p1, a.end())))
            ans.push_back(a[p1++]);
            else    ans.push_back(b[p2++]);
        }
        return ans;
    }
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int n1=nums1.size();
        int n2=nums2.size();
        vector<int> max(k,0);
        for(int size1=0;size1<=k;size1++)
        {
            int size2=k-size1;
            if(size1>n1 || size2>n2)    continue;
            vector<int> a=maxSubsequence(nums1, size1);
            vector<int> b=maxSubsequence(nums2, size2);
            vector<int> candidate=merge(a,b);
            if(candidate>max)
            {
                max=candidate;
            }
        }
        return max;
    }
};