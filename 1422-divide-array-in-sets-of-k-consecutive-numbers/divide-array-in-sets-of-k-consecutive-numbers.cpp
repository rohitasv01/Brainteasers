class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        if (nums.size()%k !=0 )     return false;
        map<int ,int> frequency;
        for(int i:nums)     frequency[i]++;
        while(frequency.size()!=0)
        {
            int current=frequency.begin()->first;
            for(int i=0;i<k;i++)
            {
                if(frequency[current+i]==0)     return false;
                frequency[current+i]--;
                if(frequency[current+i]==0)     frequency.erase(current+i);
            }
        }
        return true;
    }
};