class Solution {
public:
    int findMaxK(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i = 0, j = nums.size() - 1;
        while(i <= j){
            if(nums[i] + nums[j] < 0){
                i++;
            }
            else if(nums[i] + nums[j] == 0){
                return nums[j];
            }
            else{
                j--;
            }
        }
        return -1;
    }
};