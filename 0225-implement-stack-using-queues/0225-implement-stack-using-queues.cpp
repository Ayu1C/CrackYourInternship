class MyStack {
public:
    queue<int> q1, helper;
    MyStack() {
        
    }
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        while(q1.size()>1)
        {
            helper.push(q1.front());
            q1.pop();
        }
        int ans = q1.front();
        q1.pop();
        while(!helper.empty())
        {
            q1.push(helper.front());
            helper.pop();
        }
        return ans;
        
    }
    
    int top() {
        // while(q1.size()>1)
        // {
        //     helper.push(q1.front());
        //     q1.pop();
        // }
        // int ans = q1.front();
        // helper.push(q1.front());
        // q1.pop();
        // while(!helper.empty())
        // {
        //     q1.push(helper.front());
        //     helper.pop();
        // }
        // return ans;
        return q1.back();
    }
    
    bool empty() {
       if(q1.empty())return true;
        else return false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */