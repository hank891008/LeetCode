class MinStack {
public:
    stack<int>s;
    map<int, int>m;
    MinStack() {
    }
    
    void push(int val) {
        s.push(val);
        m[val]++;
    }
    
    void pop() {
        auto top = s.top(); s.pop();
        m[top]--;
        if(m[top] == 0){
            m.erase(top);
        }
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return m.begin()->first;
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