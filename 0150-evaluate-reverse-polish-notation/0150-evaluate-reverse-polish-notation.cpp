class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>s;
        for(auto t: tokens){
            if(t[0] == '+' && t.size() == 1){
                int b = s.top();    s.pop();
                int a = s.top();    s.pop();
                s.emplace(a + b);
            }
            else if(t[0] == '-' && t.size() == 1){
                int b = s.top();    s.pop();
                int a = s.top();    s.pop();
                s.emplace(a - b);
            }
            else if(t[0] == '*' && t.size() == 1){
                int b = s.top();    s.pop();
                int a = s.top();    s.pop();
                s.emplace(a * b);
            }
            else if(t[0] == '/' && t.size() == 1){
                int b = s.top();    s.pop();
                int a = s.top();    s.pop();
                s.emplace(a / b);
            }
            else{
                s.emplace(stoi(t));
            }
        }
        return s.top();
    }
};