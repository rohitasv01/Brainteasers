class Solution {
public:
    int trap(vector<int>& height) {
        int water=0,leftMax=0,rightMax=0,l=0,r=height.size()-1;
        while(l<r)
        {
            if(height[l]<height[r])
            {
                if(height[l]>leftMax)   leftMax=height[l];
                else    water+=leftMax-height[l];
                l++;
            }
            else
            {
                if(height[r]>rightMax)  rightMax=height[r];
                else    water+=rightMax-height[r];
                r--;
            }
        }
        return water;
    }
};