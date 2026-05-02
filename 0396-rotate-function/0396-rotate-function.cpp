class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int F = 0, n = nums.size();
        int tot = accumulate(nums.begin(), nums.end(), 0);
        for(int i = 0; i < n; i++) {
            F += i * nums[i];
        }
        int maxx = F;
        for(int i = n - 1; i > 0; i--) {
            F = F + tot - n * nums[i];
            maxx = max(maxx, F);
        }
        return maxx;
    }
};