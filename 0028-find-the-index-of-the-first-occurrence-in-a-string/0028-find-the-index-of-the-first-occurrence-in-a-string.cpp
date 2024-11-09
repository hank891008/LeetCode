class Solution {
public:
    vector<int> build_f(string s){
        vector<int> f(s.size(), -1);
        int p = -1;
        for(int i = 1; i < s.size(); i++){
            while(p != -1 && s[p + 1] != s[i]){
                p = f[p];
            }
            if(s[p + 1] == s[i]){
                p++;
            }
            f[i] = p;
        }
        return f;
    }
    int strStr(string t, string s) {
        vector<int> f = build_f(s);
        int p = -1;
        for(int i = 0; i < t.size(); i++){
            while(p != -1 && s[p + 1] != t[i]){
                p = f[p];
            }
            if(s[p + 1] == t[i]){
                p++;
            }
            if(p + 1 == s.size()){
                return i - p;
            }
        }
        return -1;
        
    }
};