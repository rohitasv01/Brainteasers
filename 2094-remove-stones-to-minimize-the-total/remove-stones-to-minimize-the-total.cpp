class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> q;
        int sum=0;
        for(int i:piles)   q.push(i);
        for(int i=0;i<k;i++)
        {
            int element=q.top();
            q.pop();
            element=(element+1)/2;
            q.push(element);
        } 
        while(q.size())
        {
            sum+=q.top();
            q.pop();
        }
        return sum;
    }
};