class FrontMiddleBackQueue {
public:
    deque<int> left;
    deque<int> right;
    FrontMiddleBackQueue() {
        
    }
    void balance()
    {
        if(left.size()<right.size())
        {
            left.push_back(right.front());
            right.pop_front();
        }
        else if(left.size() > right.size()+1)
        {
            right.push_front(left.back());
            left.pop_back();
        }
    }
    void pushFront(int val) {
        left.push_front(val);
        balance();
    }
    
    void pushMiddle(int val) {
        if(left.size()!=right.size())
        {
            right.push_front(left.back());
            left.pop_back();
        }
        left.push_back(val);
    }
    
    void pushBack(int val) {
        right.push_back(val);
        balance();
    }
    
    int popFront() {
        int ans=-1;
        if(left.size()) 
        {
            ans=left.front();
            left.pop_front();
        }
        balance();
        return ans;
    }
    
    int popMiddle() {
        int ans=-1;
        if(left.size())
        {
            ans=left.back();
            left.pop_back();
        }
        balance();
        return ans;
    }
    
    int popBack() {
        int ans=-1;
        if(right.size())
        {
            ans=right.back();
            right.pop_back();
        }
        else if(left.size())
        {
            ans=left.front();
            left.pop_front();
        }
        balance();
        return ans;
    }
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */