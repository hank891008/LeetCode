class Solution {
public:
    string RLE(string s){
        string ans;
        int cnt = 1;
        char prev = s[0];
        for(int i = 1; i < s.size(); i++){
            if(s[i] == prev){
                cnt++;
            }
            else{
                ans += to_string(cnt) + prev;
                cnt = 1;
                prev = s[i];
            }
        }
        return ans + to_string(cnt) + prev;
    }
    string countAndSay(int n) {
        string ans = "1";
        for(int i = 2; i <= n; i++){
            ans = RLE(ans);
        }
        return ans;
    }
};