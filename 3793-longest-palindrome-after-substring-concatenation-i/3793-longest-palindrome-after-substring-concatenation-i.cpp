class Solution {
public:
    int check(string st){
        int n = st.size();
        for(int i = 0; i < (n + 1) / 2; i++){
            if(st[i] != st[n - 1 - i]){
                return 1;
            }
        }
        return st.size();
    }
    int longestPalindrome(string s, string t) {
        vector<string> v1, v2;
        v1.emplace_back("");
        v2.emplace_back("");
        for(int i = 0; i < s.size(); i++){
            string sub_s;
            for(int j = i; j < s.size(); j++){
                sub_s += s[j];
                v1.emplace_back(sub_s);
            }
        }
        for(int i = 0; i < t.size(); i++){
            string sub_t;
            for(int j = i; j < t.size(); j++){
                sub_t += t[j];
                v2.emplace_back(sub_t);
            }
        }
        int ans = 0;
        for(auto a: v1){
            for(auto b: v2){
                ans = max(ans, check(a + b));
            }
        }
        return ans;
    }
};