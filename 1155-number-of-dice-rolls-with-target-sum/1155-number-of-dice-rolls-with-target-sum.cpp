class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        int MOD = 1e9 + 7;
        int dp[n + 5][target + 5];
        memset(dp, 0, sizeof(dp));
        for(int i = 1; i <= min(k, target); i++){
            dp[1][i] = 1;
        }
        for(int i = 2; i <= n; i++){
            for(int j = 1; j <= target; j++){
                for(int v = 1; v <= k; v++){
                    if(j - v >= 0){
                        dp[i][j] = (dp[i][j] + dp[i - 1][j - v]) % MOD;
                    }
                }
            }
        }
        return dp[n][target];
    }
};