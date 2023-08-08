class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size(), tot = 0;
        for(int i = 0; i < n; i++){
            tot += nums[i];
        }
        if(tot % 2){
            return false;
        }
        bool dp[tot + 5];
        memset(dp, false, sizeof(dp));
        dp[0] = true;
        for(int i = 0; i < n; i++){
            for(int tar = tot / 2; tar >= nums[i]; tar--){
                dp[tar] |= dp[tar - nums[i]];
            }
        }
        return dp[tot / 2];
    }
};