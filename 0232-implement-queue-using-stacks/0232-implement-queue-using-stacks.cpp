class MyQueue {
public:
    
    stack<int> s, helper;
    MyQueue() {
        
    }
    
    void push(int x) {
       s.push(x); 
    }
    
    int pop() {
       while(!s.empty())
       {
           helper.push(s.top());
           s.pop();
       }
        int ans = helper.top();
        helper.pop();
        while(!helper.empty())
        {
            s.push(helper.top());
            helper.pop();
        }
        return ans;
    }
    
    int peek() {
        while(!s.empty())
       {
           helper.push(s.top());
           s.pop();
       }
        int ans = helper.top();
        while(!helper.empty())
        {
            s.push(helper.top());
            helper.pop();
        }
        return ans;
    }
    
    bool empty() {
        if(s.empty())return true;
        else return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */