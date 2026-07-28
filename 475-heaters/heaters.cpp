class Solution {
public:
    bool isPossible(int mid,vector<int>& houses, vector<int>& heaters)
    {
        int p1=0,p2=0,n=houses.size(),m=heaters.size();
        while(p1<n && p2<m)
        {
            if(abs(heaters[p2]-houses[p1])<=mid)    p1++;
            else p2++;
        }
        if(p2==m)   return false;
        else return true;
    }
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(),houses.end());
        sort(heaters.begin(),heaters.end());
        int n=houses.size(),m=heaters.size();
        int start=0,end=max(houses[n-1],heaters[m-1]),ans=-1;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(isPossible(mid,houses,heaters))
            {
                ans=mid;
                end=mid-1;
            }
            else start=mid+1;
        }
        return ans;
    }
};