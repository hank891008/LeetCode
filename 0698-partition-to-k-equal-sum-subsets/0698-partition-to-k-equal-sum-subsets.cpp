class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size(), tot = 0;
        for(int i = 0; i < n; i++){
            tot += nums[i];
        }
        if(tot % k){
            return false;
        }
        int target = tot / k;
        vector<int>dp((1 << 16) + 5, -1);
        dp[0] = 0;
        for(int mask = 0; mask < (1 << n); mask++){
            if(dp[mask] == -1){
                continue;
            }
            for(int j = 0; j < n; j++){
                if(!(mask & (1 << j)) && dp[mask] + nums[j] <= target){
                    dp[mask | (1 << j)] = (dp[mask] + nums[j]) % target;
                }
            }
        }
        return dp[(1 << n) - 1] == 0;
    }
};