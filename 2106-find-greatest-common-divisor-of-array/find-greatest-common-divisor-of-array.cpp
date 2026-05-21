class Solution {
public:
    int findGCD(vector<int>& nums) {
        int mini=INT_MAX, maxi=INT_MIN;
        for(auto it:nums)
        {
            mini=min(it,mini);
            maxi=max(maxi,it);
        }
        for(int i=min(mini,maxi);i>=1;i--)
        {
            if(mini%i==0 && maxi%i==0)  return i;
        }
        return -1;
    }
};