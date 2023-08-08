class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size(), tot = 0;
        tot = accumulate(nums.begin(), nums.end(), 0);
        if(tot & 1){
            return false;
        }
        tot >>= 1;
        bool dp[tot + 5];
        memset(dp, 0, sizeof(dp));
        dp[0] = true;
        for(int i = 0; i < n; i++){
            for(int tar = tot; tar >= nums[i]; tar--){
                dp[tar] |= dp[tar - nums[i]];
            }
        }
        return dp[tot];
    }
};