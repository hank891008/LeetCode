class Solution {
public:
    long long minOperationsToMakeMedianK(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int idx = nums.size() / 2;
        long long ans = abs(k - nums[idx]);
        int l = idx - 1, r = idx + 1;
        while(l >= 0 && nums[l] >= k){
            ans += abs(nums[l--] - k);
        }
        while(r < nums.size() && nums[r] <= k){
            ans += abs(nums[r++] - k);
        }
        return ans;
    }
};