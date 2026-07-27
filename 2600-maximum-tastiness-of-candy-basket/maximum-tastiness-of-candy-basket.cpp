class Solution {
public: 
    bool isPossible(int mid,vector<int> &price, int k)
    {
        int prev=price[0],number=1;
        for(auto it:price)
        {
            if(it-prev >= mid)
            {
                number++;
                prev=it;
            }
        }
        if(number>=k)   return true;
        else return false;
    }
    int maximumTastiness(vector<int>& price, int k) {
        sort (price.begin(),price.end());
        int start=0,end=*max_element(price.begin(),price.end())-*min_element(price.begin(),price.end()),ans=-1;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(isPossible(mid,price,k)) 
            {
                ans=mid;
                start=mid+1;
            }
            else end=mid-1;
        }
        return ans;
    }
};