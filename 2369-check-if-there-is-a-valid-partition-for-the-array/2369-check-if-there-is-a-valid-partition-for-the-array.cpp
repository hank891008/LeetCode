class Solution {
public:
    bool flag = 0;
    bool dp(vector<int>& nums, int idx, int check[]){
        if(idx == nums.size() || flag == 1){
            flag = 1;
            return true;
        }
        if(check[idx] != -1){
            return check[idx];
        }
        bool ans = false;
        bool tmp;
        if(idx + 1 < nums.size() && nums[idx] == nums[idx + 1]){
            ans |= check[idx + 2] = dp(nums, idx + 2, check);
        }
        if(idx + 2 < nums.size() && nums[idx] == nums[idx + 1] && nums[idx] == nums[idx + 2]){
            ans |= check[idx + 3] = dp(nums, idx + 3, check);
        }
        if(idx + 2 < nums.size() && nums[idx] + 1 == nums[idx + 1] && nums[idx + 1] + 1 == nums[idx + 2]){
            ans |= check[idx + 3] = dp(nums, idx + 3, check);
        }
        return check[idx] = ans;
    }
    bool validPartition(vector<int>& nums) {
        int check[nums.size() + 5];
        memset(check, -1, sizeof(check));
        return dp(nums, 0, check);
    }
};