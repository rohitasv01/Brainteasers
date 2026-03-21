class Solution {
public:
    int minScore(vector<int> & arr,int j)
    {   //if(j==0)    return 0;
        int n= arr.size(),minSum=0;
        for(int i=0;i<j;i++)    minSum+=arr[i];
        int l=1,r=j,windowSum=minSum;
        while(r<n)
        {   
            windowSum=windowSum+arr[r]-arr[l-1];
            minSum=min(minSum,windowSum);
            l++;
            r++;
        }
        return minSum;
    }
    int maxScore(vector<int>& cardPoints, int k) {
       int sum=0,n=cardPoints.size();
       for(int i:cardPoints)    sum+=i;
       return sum-minScore(cardPoints,n-k);
    }
};