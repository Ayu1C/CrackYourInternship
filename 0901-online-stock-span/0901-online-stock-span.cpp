class StockSpanner {
public:
    
    stack<pair<int,int>> st;
    StockSpanner() {
        
    }
    
    int next(int price) {
        
       int span=1;
        
        //here if the topmost element is less than or equal to price, we can take its smaller elements and that element as our ans;
        while(!st.empty()&&st.top().first<=price){
            span+=st.top().second;
            st.pop();
        }
        
        //here if our top element of stack is greater than it, we simply push that element pair, because we are storing monotonic decreasing elements in stack;
        st.push({price,span});
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */