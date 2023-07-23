class Solution {
public:
    bool valid(char s1, char s2){
        if(s1 == '0'){
            return false;
        }
        if(s1 == 'a'){
            s1 = '0';
        }
        int sum = (s1 - '0') * 10 + (s2 - '0');
        return sum >= 1 && sum <= 26;
    }
    int numDecodings(string s) {
        int ans[(int)s.size() + 2];
        memset(ans, 0, sizeof(ans));
        ans[(int)s.size()] = 1;
        if(s[(int)s.size() - 1] != '0'){
            ans[(int)s.size() - 1] = 1;
        }
        for(int i = (int)s.size() - 2; i >= 0; i--){
            if(valid('a', s[i])){
                ans[i] += ans[i + 1];
            }
            if(valid(s[i], s[i + 1])){
                ans[i] += ans[i + 2];
            }
        }
        for(int i = 0; i < (int)s.size() - 1; i++){
            if(s[i] == '0' && s[i + 1] == '0'){
                return 0;
            }
        }
        if(s[0] == '0'){
            return 0;
        }
        return ans[0];
    }
};