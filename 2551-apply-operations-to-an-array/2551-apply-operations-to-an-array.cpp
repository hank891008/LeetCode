class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int cnt = 0;
        for(int i = 0; i < nums.size() - 1; i++){
            if(nums[i] == nums[i + 1] && nums[i] != 0){
                nums[cnt++] = nums[i] * 2;
                nums[i + 1] = 0;
                i++;
            }
            else if(nums[i] != 0){
                nums[cnt++] = nums[i];
            }
        }
        nums[cnt++] = nums[nums.size() - 1];
        for(int i = cnt; i < nums.size(); i++){
            nums[i] = 0;
        }
        return nums;
    }
};