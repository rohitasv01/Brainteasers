class MedianFinder {
public:
    priority_queue<int> leftMaxHeap;
    priority_queue<int ,vector<int>, greater<int>> rightMinHeap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(leftMaxHeap.size()==0)   leftMaxHeap.push(num);
        else if(num<leftMaxHeap.top())   leftMaxHeap.push(num);
        else    rightMinHeap.push(num);
        if(rightMinHeap.size()>leftMaxHeap.size())
        {
            leftMaxHeap.push(rightMinHeap.top());
            rightMinHeap.pop();
        }
        else
        {
            if(leftMaxHeap.size()-1>rightMinHeap.size())
            {
                rightMinHeap.push(leftMaxHeap.top());
                leftMaxHeap.pop();
            }
        }
    }
    
    double findMedian() {
        double ans;
        if(leftMaxHeap.size()==rightMinHeap.size())  
        {
          ans=leftMaxHeap.top()+rightMinHeap.top();
          ans/=2;
        }
        else  ans=leftMaxHeap.top();
        return ans;  
        
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */