class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if(nums.size() < 3){
            return false;
        }
        vector<int>L, R;
        L.emplace_back(nums[0]);
        for(int i = 1; i < nums.size(); i++) {
            if(L.back() > nums[i])
                L.emplace_back(nums[i]);
            else
                L.emplace_back(L.back());
        }
        R.emplace_back(nums[(int)nums.size() - 1]);
        for(int i = nums.size() - 2; i >= 0; i--) {
            if(R.back() < nums[i])
                R.emplace_back(nums[i]);
            else
                R.emplace_back(R.back());
        }
        reverse(R.begin(), R.end());
        for(int i = 0; i < nums.size(); i++){
            if(L[i] < nums[i] && nums[i] < R[i]){
                return true;
            }
        }
        return false;
    }
};