class Solution {
public:
    int MOD = 1e9 + 7;
    int maxProductPath(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        long long dp[20][20][2] = {0};  // 0 max, 1 min
        dp[0][0][0] = dp[0][0][1] = grid[0][0];
        for(int i = 1; i < n; i++) {
            dp[i][0][0] = dp[i][0][1] = dp[i - 1][0][0] * grid[i][0];
        }
        for(int j = 1; j < m; j++) {
            dp[0][j][0] = dp[0][j][1] = dp[0][j - 1][0] * grid[0][j];
        }
        for(int i = 1; i < n; i++) {
            for(int j = 1; j < m; j++) {
                dp[i][j][0] = max({
                    dp[i][j - 1][0] * grid[i][j], 
                    dp[i][j - 1][1] * grid[i][j],
                    dp[i - 1][j][0] * grid[i][j], 
                    dp[i - 1][j][1] * grid[i][j],
                });
                dp[i][j][1] = min({
                    dp[i][j - 1][0] * grid[i][j], 
                    dp[i][j - 1][1] * grid[i][j],
                    dp[i - 1][j][0] * grid[i][j], 
                    dp[i - 1][j][1] * grid[i][j],
                });
            }
        }
        if (dp[n - 1][m - 1][0] < 0) {
            return -1;
        }
        return dp[n - 1][m - 1][0] % MOD;
    }
};