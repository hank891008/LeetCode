class MinStack {
public:
    stack<int>s, min_s;
    MinStack() {
    }
    
    void push(int val) {
        s.emplace(val);
        if(min_s.empty() || val <= min_s.top()){
            min_s.emplace(val);
        }
    }
    
    void pop() {
        auto val = s.top(); s.pop();
        if(min_s.top() == val){
            min_s.pop();
        }
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return min_s.top();
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