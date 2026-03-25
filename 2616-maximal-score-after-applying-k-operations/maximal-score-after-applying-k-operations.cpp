class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long sum=0;
        priority_queue<int> que;
        for(int i:nums)     que.push(i);
        for(int i=0;i<k;i++)
        {
            sum+=que.top();
            int element =(que.top()+3-1)/3;
            que.pop();
            que.push(element);
        }
        return sum;
    }
};