class CustomStack {
public:
    int maxi;
    stack<int> st;
    CustomStack(int maxSize) {
        maxi=maxSize;
    }
    
    void push(int x) {
        if(st.size()<maxi)  st.push(x);
    }
    
    int pop() {
        if(st.size()==0)    return -1;
        int x=st.top();
        st.pop();
        return x;
    }
    
    void increment(int k, int val) {
        stack<int> temp;
        if(st.size()<k)
        {
            while(st.size())
            {
                temp.push(st.top()+val);
                st.pop();
            }
            while(temp.size())
            {
                st.push(temp.top());
                temp.pop();
            }
        }
        else 
        {
            while(st.size()>k)
            {
                temp.push(st.top());
                st.pop();
            }
            while(st.size())
            {
                temp.push(st.top()+val);
                st.pop();
            }
            while(temp.size())
            {
                st.push(temp.top());
                temp.pop();
            }
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */