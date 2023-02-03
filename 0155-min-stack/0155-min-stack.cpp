class MinStack {
public:
    stack<int> st, minSt;
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        int mini;
        if(!minSt.empty())
            mini = min(minSt.top(), val);
        else
            mini = val;
        minSt.push(mini);
    }
    
    void pop() {
        st.pop();
        minSt.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minSt.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */