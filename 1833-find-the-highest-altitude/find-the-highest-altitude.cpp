class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maxi=0,sum=0;
        for(int i:gain)
        {
            sum+=i;
            maxi=max(maxi,sum);
        }
        return maxi;
    }
};