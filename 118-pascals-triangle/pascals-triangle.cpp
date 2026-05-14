class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>arr(numRows);
        for(int i=0;i<numRows;i++)
        {
            for(int j=0;j<=i;j++)
            {
                if(j==0 || j==i)    arr[i].push_back(1);
                else
                {
                    arr[i].push_back(arr[i-1][j-1]+arr[i-1][j]);
                }
            }
        }
        return arr;
    }
};