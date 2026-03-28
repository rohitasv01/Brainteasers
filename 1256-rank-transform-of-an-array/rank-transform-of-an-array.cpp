class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector <int> temp=arr;
        sort(temp.begin(),temp.end());
        unordered_map<int ,int> rankMap;
        int rank=1;
        for(int i:temp)
        {
           if(rankMap.count(i)==0)  rankMap[i]=rank++;
        }
        for(int i=0;i<arr.size();i++)
        {
            arr[i]=rankMap[arr[i]];
        }
        return arr;
    }
};