class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        auto tmp = nums;
        for(int i = 0; i < nums.size(); i++){
            tmp[(i + k) % nums.size()] = nums[i];
        }
        nums = tmp;
    }
};