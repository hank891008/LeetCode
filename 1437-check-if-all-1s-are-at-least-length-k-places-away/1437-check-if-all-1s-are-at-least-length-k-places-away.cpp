class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int pre_one = -1e6;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 1){
                if(i - pre_one <= k){
                    return false;
                }
                pre_one = i;
            }
        }
        return true;
    }
};