class Solution {
public:
    bool isPossible(int mid,int n, int k, int budget, vector<vector<int>>& composition, vector<int>& stock, vector<int>& cost)
    {
        long long mini=INT_MAX;
        for(int i=0;i<k;i++)
        {
            long long totalCost=0;
            for(int j=0;j<n;j++)
            {
                if(stock[j]<(1LL)*mid*composition[i][j])
                {
                    totalCost+=(1LL)*((1LL)*mid*composition[i][j]-stock[j])*cost[j];
                }
            }
            mini=min(mini,totalCost);
        }
        if(mini<=budget)    return true;
        else return false;
    }
    int maxNumberOfAlloys(int n, int k, int budget, vector<vector<int>>& composition, vector<int>& stock, vector<int>& cost) {
        int start=0,end=2e8,ans=-1;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(isPossible(mid,n,k,budget,composition,stock,cost))
            {
                ans=mid;
                start=mid+1;
            }
            else end=mid-1;
        }
        return ans;
    }
};