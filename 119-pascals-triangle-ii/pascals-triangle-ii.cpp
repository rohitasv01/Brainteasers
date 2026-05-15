class Solution {
public:
    vector<int> getRow(int rowIndex) {
        long long mul=1;
        vector<int> ans;
        ans.push_back(1);
        for(int i=1;i<=rowIndex;i++)
        {
            mul=mul*(rowIndex-i+1)/i;
            ans.push_back(mul);
        }
        return ans;
    }
};