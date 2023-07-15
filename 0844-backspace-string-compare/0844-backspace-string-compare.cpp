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
        return ss == tt;
    }
};