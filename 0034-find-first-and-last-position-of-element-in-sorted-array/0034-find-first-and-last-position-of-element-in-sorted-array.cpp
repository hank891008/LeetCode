class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto it_l = lower_bound(nums.begin(), nums.end(), target);
        auto it_r = upper_bound(nums.begin(), nums.end(), target);
        if(it_l == nums.end() || *it_l > target || nums.size() == 0){
            return vector<int>({-1, -1});
        }
        return vector<int>({int(it_l - nums.begin()), int(it_r - nums.begin() - 1)});
    }
};