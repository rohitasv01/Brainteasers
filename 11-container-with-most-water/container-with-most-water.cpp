class Solution {
public:
    int maxArea(vector<int>& height) {
        int p1=0,p2=height.size()-1,maxi=INT_MIN,area;
        while(p1<p2)
        {
            area=min(height[p1],height[p2])*(p2-p1);
            maxi=max(maxi,area);
            (height[p1]<height[p2])? p1++ :p2--;
        }
        return maxi;
    }
};