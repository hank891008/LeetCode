class Solution {
public:
    const int MOD = 1e9 + 7;

    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> pow2(n, 1);
        for(int i = 1; i < n; i++){
            pow2[i] = (pow2[i - 1] * 2LL) % MOD;
        }
        int ans = 0;
        int l = 0, r = n - 1;

        while(l <= r){
            if(nums[l] + nums[r] <= target){
                ans = (ans + 0LL + pow2[r - l]) % MOD;
                l++;
                continue;
            }
            r--;
        }
        return ans;
    }
};