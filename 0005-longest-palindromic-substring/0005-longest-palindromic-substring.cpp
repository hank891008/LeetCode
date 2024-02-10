class Solution {
public:
    string ans;
    void solve(int l, int r, string &s){
        while(l >= 0 && r < s.size()){
            if(s[l] != s[r]){
                break;
            }
            l--;
            r++;
        }
        ans = ans.size() > (r - 1) - (l + 1) + 1 ? ans : s.substr(l + 1, (r - 1) - (l + 1) + 1);
    }
    string longestPalindrome(string s) {
        for(int i = 0; i < s.size(); i++){
            solve(i, i, s);
            solve(i, i + 1, s);
        }
        return ans;
    }
};