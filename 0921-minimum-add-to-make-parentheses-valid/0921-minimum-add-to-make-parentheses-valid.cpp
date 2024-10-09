class Solution {
public:
    int minAddToMakeValid(string st) {
        stack<char> s;
        for(int i = 0; i < st.size(); i++){
            if(s.empty()){
                s.emplace(st[i]);
            }
            else if(s.top() == '(' && st[i] == ')'){
                s.pop();
            }
            else{
                s.emplace(st[i]);
            }
        }
        return s.size();
    }
};