class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n=nums.size();
        deque<int> dqMax;
        deque<int> dqMin;
        int maxi=0;
        int l=0;
        for(int r=0;r<n;r++)
        {
            while(dqMax.size() && nums[r]>nums[dqMax.back()])     dqMax.pop_back();
            while(dqMin.size() && nums[r]<nums[dqMin.back()])     dqMin.pop_back();
            dqMax.push_back(r);
            dqMin.push_back(r);
            while(dqMax.size() && dqMin.size() && nums[dqMax.front()]-nums[dqMin.front()] > limit)
            {
                l++;
                if(l>dqMax.front())     dqMax.pop_front();
                if(l>dqMin.front())     dqMin.pop_front();
            }
            maxi=max(maxi, r-l+1);
        }
        return maxi;
    }
};