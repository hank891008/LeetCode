class Solution {
public:
    int solve(vector<int>& nums, int idx, int sum){
        if(idx == nums.size()){
            return sum;
        }
        return solve(nums, idx + 1, sum) + solve(nums, idx + 1, sum ^ nums[idx]);
    }
    int subsetXORSum(vector<int>& nums) {
        return solve(nums, 0, 0);
    }
};