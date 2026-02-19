class Solution {
public:
    int countBinarySubstrings(string s) {
        int ans = 0, prev = 0, now = 1;
        for(int i = 1; i < s.size(); i++) {
            if(s[i] == s[i - 1]) {
                now++;
            } else {
                prev = now;
                now = 1;
            }
            if(now <= prev) {
                ans++;
            }
        }
        return ans;
    }
};