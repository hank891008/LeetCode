class Solution {
public:
    int mapping(char c){
        if(c == '7' or c == '9'){
            return 4;
        }
        return 3;
    }
    int countTexts(string pressedKeys) {
        int MOD = 1e9 + 7;
        int n = pressedKeys.size();
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        for(int i = 1; i <= n; i++){
            dp[i] = dp[i - 1];
            bool flag1 = (i >= 2 && pressedKeys[i - 1] == pressedKeys[i - 2]);
            bool flag2 = flag1 && i >= 3 && pressedKeys[i - 1] == pressedKeys[i - 3];
            bool flag3 = flag1 && flag2 && i >= 4 && pressedKeys[i - 1] == pressedKeys[i - 4];
            if(flag1){
                dp[i] = (dp[i] + dp[i - 2]) % MOD;
            }
            if(flag2){
                dp[i] = (dp[i] + dp[i - 3]) % MOD;
            }
            if((pressedKeys[i - 1] == '7' || pressedKeys[i - 1] == '9') && flag3){
                dp[i] = (dp[i] + dp[i - 4]) % MOD;
            }
        }
        return dp.back();
    }
};