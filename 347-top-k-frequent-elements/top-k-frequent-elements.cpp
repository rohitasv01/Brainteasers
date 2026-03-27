class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int ,int> frequency;
        for(int i:nums) frequency[i]++;
        priority_queue<pair<int ,int> ,vector<pair<int ,int>>,greater<pair<int ,int>>> minHeap;
        for(auto[num,freq]:frequency)
        {
            minHeap.push({freq,num});
            if(minHeap.size()>k)    minHeap.pop();
        }
        vector <int> ans;
        while(minHeap.size()!=0)
        {
            auto it=minHeap.top();
            ans.push_back(it.second);
            minHeap.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};