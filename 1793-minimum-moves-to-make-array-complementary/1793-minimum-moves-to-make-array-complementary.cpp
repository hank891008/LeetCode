class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        vector<int> diff(2 * limit + 2, 0);
        for(int i = 0; i < nums.size() / 2; i++){
            int oneMoveMin = min(nums[i], nums[nums.size() - 1 - i]) + 1;
            int oneMoveMax = max(nums[i], nums[nums.size() - 1 - i]) + limit;
            int justGood = nums[i] + nums[nums.size() - 1 - i];

            // 1
            diff[2] += 2;
            diff[oneMoveMin] -= 2;

            // 2
            diff[oneMoveMin] += 1;
            diff[justGood] -= 1;

            // 3 0 steps

            // 4
            diff[justGood + 1] += 1;
            diff[oneMoveMax + 1] -= 1;

            // 5
            diff[oneMoveMax + 1] += 2;
        }
        int curr = 0;
        int ans = INT_MAX;
        for(int i = 2; i <= 2 * limit; i++){
            curr += diff[i];
            ans = min(curr, ans);
        }
        return ans;
    }
};