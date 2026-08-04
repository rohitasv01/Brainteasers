class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<int> ans;
        int start=0,end=m-1;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            int maxi=INT_MIN,maxP=-1;
            for(int i=0;i<n;i++)
            {
                maxi=max(maxi,mat[i][mid]);
                if(maxi==mat[i][mid])   maxP=i;
            }
            bool leftMax=true,rightMax=true;
            if(mid-1>=0)    
            {
                if(mat[maxP][mid-1]>=mat[maxP][mid]) leftMax=false;
            }
            if(mid+1<m)
            {
                if(mat[maxP][mid+1]>=mat[maxP][mid]) rightMax=false;
            }
            if(leftMax && rightMax)
            {
                ans.push_back(maxP);
                ans.push_back(mid);
                return ans;
            }
            if(leftMax) start=mid+1;
            else end=mid-1;
        }
        return ans;
    }
};