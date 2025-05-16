class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        int MOD = 1e9 + 7;
        int alpha[26] = {0};
        for(int i = 0; i < s.size(); i++){
            alpha[s[i] - 'a']++;
        }
        for(int i = 0; i < t; i++){
            int prev = alpha[0];
            for(int j = 1; j < 25; j++){
                int tmp = alpha[j];
                alpha[j] = prev;
                prev = tmp;
            }
            alpha[0] = alpha[25];
            alpha[1] = (alpha[1] + alpha[25]) % MOD;
            alpha[25] = prev;
        }
        int ans = 0;
        for(int i = 0; i < 26; i++){
            ans = (ans + alpha[i]) % MOD;
        }
        return ans;
    }
};