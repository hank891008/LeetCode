class Solution {
public:
    int minLength(string s) {
        stack<char> Stack;
        for(int i = 0; i < s.size(); i++){
            if(Stack.empty()){
                Stack.emplace(s[i]);
            }
            else if(s[i] == 'B'){
                if(Stack.top() == 'A'){
                    Stack.pop();
                }
                else{
                    Stack.emplace(s[i]);
                }
            }
            else if(s[i] == 'D'){
                if(Stack.top() == 'C'){
                    Stack.pop();
                }
                else{
                    Stack.emplace(s[i]);
                }
            }
            else{
                Stack.emplace(s[i]);
            }
        }
        return Stack.size();
    }
};