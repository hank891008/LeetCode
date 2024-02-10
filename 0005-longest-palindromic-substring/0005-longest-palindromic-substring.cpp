class Solution {
public:
    string solve(int l, int r, string s){
        string st;
        while(l >= 0 && r < s.size() && s[l] == s[r]){
            st = s.substr(l, r - l + 1);
            l--;
            r++;
        }
        return st;
    }
    string longestPalindrome(string s) {
        string ans;
        for(int i = 0; i < s.size(); i++){
            string tmp = solve(i, i, s);
            ans = ans.size() > tmp.size()  ? ans : tmp;
            tmp = solve(i, i + 1, s);
            ans = ans.size() > tmp.size()  ? ans : tmp;
        }
        return ans;
    }
};