class Solution {
public:
    int numMusicPlaylists(int n, int goal, int k) {
        long long MOD = 1e9 + 7;
        long long dp[goal + 5][n + 5];  // # i thength with j diff song
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        for(int i = 1; i <= goal; i++){
            for(int j = 1; j <= n; j++){
                dp[i][j] = (dp[i - 1][j - 1] * (n - (j - 1))) % MOD;
                if(j > k){
                    dp[i][j] = (dp[i][j] + dp[i - 1][j] * (j - k)) % MOD;
                }
            }
        }
        return (int)dp[goal][n];
    }
};