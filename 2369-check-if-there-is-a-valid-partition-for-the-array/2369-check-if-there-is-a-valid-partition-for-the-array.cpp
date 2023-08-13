class Solution {
public:
    bool flag = 0;
    bool dp(vector<int>& nums, int idx, map<int, bool>& m){
        if(idx == nums.size() || flag == 1){
            flag = 1;
            return true;
        }
        if(m.count(idx)){
            return m[idx];
        }
        bool ans = false;
        if(idx + 1 < nums.size() && nums[idx] == nums[idx + 1]){
            ans |= dp(nums, idx + 2, m);
        }
        if(idx + 2 < nums.size() && nums[idx] == nums[idx + 1] && nums[idx] == nums[idx + 2]){
            ans |= dp(nums, idx + 3, m);
        }
        if(idx + 2 < nums.size() && nums[idx] + 1 == nums[idx + 1] && nums[idx + 1] + 1 == nums[idx + 2]){
            ans |= dp(nums, idx + 3, m);
        }
        return m[idx] = ans;
    }
    bool validPartition(vector<int>& nums) {
        map<int, bool> m;
        return dp(nums, 0, m);
    }
};