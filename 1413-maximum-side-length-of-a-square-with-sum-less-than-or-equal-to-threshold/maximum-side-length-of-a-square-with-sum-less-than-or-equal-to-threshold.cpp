class Solution {
public:
    bool isPossible(int mid,vector<vector<int>>& mat, int threshold,vector<vector<int>> &pSum)
    {
        int n=mat.size();
        int m=mat[0].size();
        for(int i=0;i+mid<=n;i++)
        {
            for(int j=0;j+mid<=m;j++)
            {
                int sum=pSum[i+mid-1][j+mid-1];
                if(i>0) sum-=pSum[i-1][j+mid-1];
                if(j>0) sum-=pSum[i+mid-1][j-1];
                if(i>0 && j>0)  sum+=pSum[i-1][j-1];
                if(sum<=threshold)   return true;
            }
        }
        return false;
    }
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>> pSum(n,vector<int>(m,0));
        pSum[0][0]=mat[0][0];
        for(int i=1;i<n;i++)    pSum[i][0]=pSum[i-1][0]+mat[i][0];
        for(int i=1;i<m;i++)    pSum[0][i]=pSum[0][i-1]+mat[0][i];
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                pSum[i][j]=pSum[i-1][j]+pSum[i][j-1]-pSum[i-1][j-1]+mat[i][j];
            }
        }
        int start=1,end=min(n,m),ans=0;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(isPossible(mid,mat,threshold,pSum))
            {
                ans=mid;
                start=mid+1;
            }
            else end=mid-1;
        }
        return ans;
    }
};