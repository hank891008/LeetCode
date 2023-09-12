class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int dp[n + 5];
        int ans = 0;
        for(int i = 0; i < n; i++){
            dp[i] = nums[i];
            int maxx = 0;
            for(int j = 0; j < i - 1; j++){
                maxx = max(maxx, dp[j]);
            }
            dp[i] += maxx;
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};