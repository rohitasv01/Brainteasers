class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size(),n=nums2.size();
        if(m>n) return findMedianSortedArrays(nums2,nums1);
        int left=(m+n+1)/2;
        double ans=-1;
        int start=0,end=m;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            int l1=INT_MIN,l2=INT_MIN,r1=INT_MAX,r2=INT_MAX;
            int cut1=mid;
            int cut2=left-mid;
            if(cut1-1>=0)   l1=nums1[cut1-1];
            if(cut1<m)  r1=nums1[cut1];
            if(cut2-1>=0)   l2=nums2[cut2-1];
            if(cut2<n) r2=nums2[cut2];
            if(l1<=r2 && l2<=r1)  
            {
                if((m+n)%2==1)  ans=max(l1,l2);
                else 
                {
                    ans=(max(l1,l2)+min(r1,r2))/2.0;
                }
                break;
            } 
            else if(l1>r2)   end=mid-1;
            else  if(l2>r1) start=mid+1;
        }
        return ans;
    }
};