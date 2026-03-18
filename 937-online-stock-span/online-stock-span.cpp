class StockSpanner {
public:
    vector<int> arr;
    stack<int> st;
    StockSpanner() {
        
    }
    
    int next(int price) {
        arr.push_back(price);
        int ans, n=arr.size();
        while(st.size()!=0 && price>=arr[st.top()])     st.pop();
        if(st.size()==0)    ans= n;
        else   ans=n-st.top()-1;
        st.push(n-1);
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */