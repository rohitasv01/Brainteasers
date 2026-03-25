class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> q;
        long long sum=0;
        for(int i:gifts)    q.push(i);
        for(int i=0;i<k;i++)
        {
            int element =sqrt(q.top());
            q.pop();
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