class Solution {
public:
    int prefix[105];
    double dp[105][105];
    double largestSumOfAverages(vector<int>& nums, int K) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        for (int i = 1; i <= n; i++) {
            dp[i][1] = (1.0 * prefix[i]) / i;
        }
        for (int k = 2; k <= K; k++) {
            for (int i = k; i <= n; i++) {
                for (int j = i - 1; j >= k - 1; j--) {
                    dp[i][k] = max(dp[i][k], dp[j][k - 1] + 1.0 * (prefix[i] - prefix[j]) / (i - j));
                }
            }
        }
        return dp[n][K];
    }
};