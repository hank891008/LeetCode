class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char>ss, tt;
        for(int i = 0; i < s.size(); i++){
            if(s[i] != '#'){
                ss.push(s[i]);
            }
            else{
                if(!ss.empty()){
                    ss.pop();
                }
            }
        }
        for(int i = 0; i < t.size(); i++){
            if(t[i] != '#'){
                tt.push(t[i]);
            }
            else{
                if(!tt.empty()){
                    tt.pop();
                }
            }
        }
        if((int)ss.size() != (int)tt.size()){
            return false;
        }
        while(!ss.empty()){
            if(ss.top() != tt.top()){
                return false;
            }
            ss.pop();
            tt.pop();
        }
        return true;
    }
};