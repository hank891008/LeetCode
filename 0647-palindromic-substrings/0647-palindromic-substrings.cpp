class Solution {
public:
    int solve(int l, int r, string s){
        int cnt = 0;
        while(l >= 0 && r < s.size() && s[l--] == s[r++]){
            cnt++;
        }
        return cnt;
    }
    int countSubstrings(string s) {
        int ans = 0;
        for(int i = 0; i < s.size(); i++){
            ans += solve(i, i, s);
            ans += solve(i, i + 1, s);
        }
        return ans;
    }
};