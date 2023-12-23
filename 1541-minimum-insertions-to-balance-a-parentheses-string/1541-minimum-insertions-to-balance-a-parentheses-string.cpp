class Solution {
public:
    int minInsertions(string s) {
        int ans = 0;
        stack<char>Stack;
        int idx = 0;
        while(idx < s.size()){
            if(s[idx] == '('){
                Stack.push('(');
                idx++;
            }
            else{
                idx++;
                if(idx < s.size() && s[idx] == ')'){
                    if(!Stack.empty()){
                        Stack.pop();
                    }
                    else{
                        ans++;
                    }
                    idx++;
                }
                else if(idx < s.size() && s[idx] == '('){
                    ans++;
                    if(!Stack.empty()){
                        Stack.pop();
                    }
                    else{
                        ans++;
                    }
                }
                else{
                    if(!Stack.empty()){
                        Stack.pop();
                        ans += 1;
                    }
                    else{
                        ans += 2;
                    }
                }
            }
        }
        while(!Stack.empty()){
            Stack.pop();
            ans += 2;
        }
        return ans;
    }
};