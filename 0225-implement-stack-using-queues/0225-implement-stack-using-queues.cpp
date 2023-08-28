class MyStack {
public:
    queue<int>q;
    int _top;
    MyStack() {
        
    }
    
    void push(int x) {
        _top = x;
        q.emplace(x);
        int n = (int)q.size() - 1;
        while(n--){
            q.emplace(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int tmp = q.front();  q.pop();
        _top = q.front();
        return tmp;
    }
    
    int top() {
        return _top;
    }
    
    bool empty() {
        return q.empty();
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