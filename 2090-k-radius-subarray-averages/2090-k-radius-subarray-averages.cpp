class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(n, -1);
        if(2 * k + 1 > n){
            return ans;
        }
        long long tot = 0;
        for(int i = 0; i < 2 * k + 1; i++){
            tot += nums[i];
        }
        ans[k] = tot / (2 * k + 1);
        for(int i = k + 1; i < n - k; i++){
            tot = tot + nums[i + k] - nums[i - k - 1];
            ans[i] = tot / (2 * k + 1);
        }
        return ans;
    }
};