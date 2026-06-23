class Solution {
public:
    string processStr(string s) {
        string ans;
        for(auto op: s) {
            if(isalpha(op)) {
                ans += op;
            } else if(op == '*') {
                if(ans.size()) {
                    ans.pop_back();
                }
            } else if(op == '#') {
                ans += ans;
            } else {
                reverse(ans.begin(), ans.end());
            }
        }
        return ans;
    }
};