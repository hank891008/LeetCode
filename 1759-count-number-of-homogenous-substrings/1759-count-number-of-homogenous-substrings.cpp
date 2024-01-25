class Solution {
public:
    int countHomogenous(string s) {
        int MOD = 1e9 + 7;
        char prev = s[0];
        int tot = 0;
        long long len = 1;
        for(int i = 1; i < s.size(); i++){
            if(prev == s[i]){
                len++;
            }
            else{
                prev = s[i];
                tot = (tot + ((1 + len) * len) / 2) % MOD;
                len = 1;
            }
        }
        return (tot + (1 + len) * len / 2) % MOD;
    }
};