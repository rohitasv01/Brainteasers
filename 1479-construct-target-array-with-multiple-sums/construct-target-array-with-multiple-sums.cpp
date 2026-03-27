class Solution {
public:
    bool isPossible(vector<int>& target) {
        priority_queue<long long> maxHeap(target.begin(),target.end());
        long long sum=0;
        for(int i:target)   sum+=i;
        while(maxHeap.top()!=1)
        {
            long long maxElement=maxHeap.top();
            maxHeap.pop();
            long long remainingSum=sum-maxElement;
            if(remainingSum<=0 || remainingSum>=maxElement) return false;
            long long element=maxElement%remainingSum;
            if(element==0)
            {
                if (remainingSum==1)    return true;
                else    return false;
            }
            maxHeap.push(element);
            sum=remainingSum+element;
        }
        return true;
    }
};