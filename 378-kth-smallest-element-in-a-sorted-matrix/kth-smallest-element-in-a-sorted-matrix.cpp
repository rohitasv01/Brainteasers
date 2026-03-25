class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();
        vector<pair<int,pair<int,int>>> temp;
        for(int i=0;i<n;i++)
        {
            temp.push_back({matrix[i][0],{i,0}});
        }
        priority_queue< pair<int,pair<int,int>> ,vector< pair<int,pair<int,int>>>,greater< pair<int,pair<int,int>>>> q(temp.begin(),temp.end());
        int ans,i,j;
        pair<int,pair<int,int>> element;
        while(k--)
        {
            element=q.top();
            q.pop();
            ans=element.first;
            i=element.second.first;
            j=element.second.second;
            if(j+1<n)   q.push({matrix[i][j+1],{i,j+1}});
        }
        return ans;
    }
};