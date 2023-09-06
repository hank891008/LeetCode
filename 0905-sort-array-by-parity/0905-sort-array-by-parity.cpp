class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int idx = 0;
        for(int i = 1; i < nums.size(); i++){
            if(idx >= nums.size()){
                break;
            }
            if(nums[i] % 2 == 0 && idx < i){
                swap(nums[idx], nums[i]);
            }
            while(idx < nums.size() && nums[idx] % 2 == 0){
                idx++;
            }
        }
        return nums;
    }
};