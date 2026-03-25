class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
       priority_queue<int> que;
       for(int i:stones)    que.push(i);
       while(que.size()>1)
       {
            int weight=que.top();
            que.pop();
            weight-=que.top();
            que.pop();
            if(weight)  que.push(weight);
       }
       return que.empty()? 0 :que.top();
    }
};