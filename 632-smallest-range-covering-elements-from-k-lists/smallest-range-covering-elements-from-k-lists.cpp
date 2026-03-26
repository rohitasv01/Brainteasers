class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue< pair<int,pair<int,int>>, vector< pair<int,pair<int,int>>>, greater< pair<int,pair<int,int>>>> minHeap;
        int maximum=INT_MIN;
        for(int i=0;i<nums.size();i++) 
        {
         minHeap.push({nums[i][0],{i,0}});
         maximum=max(maximum,nums[i][0]);
        }
        vector<int> ans(2);
        int minimum=minHeap.top().first;
        ans[0]=minimum;
        ans[1]=maximum;
        pair<int ,pair<int,int>> element;
        int i,j,value;
        while(true)
        {
            element=minHeap.top();
            minHeap.pop();
            value=element.first;
            i=element.second.first;
            j=element.second.second;
            if(j+1<nums[i].size())
            {
                minHeap.push({nums[i][j+1],{i,j+1}});
                maximum=max(maximum,nums[i][j+1]);
                minimum=minHeap.top().first;
                if(maximum-minimum<ans[1]-ans[0])
                {
                    ans[1]=maximum;
                    ans[0]=minimum;
                }
            }
            else break;
        }
        return ans;
    }
};