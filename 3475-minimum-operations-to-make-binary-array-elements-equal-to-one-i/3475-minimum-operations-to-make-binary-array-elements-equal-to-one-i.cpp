class Solution {
public:
    int minOperations(vector<int>& nums) {
        int cnt = 0;
        for(int i = 2; i < nums.size(); i++){
            if(nums[i - 2] == 0){
                nums[i - 2] ^= 1;
                nums[i - 1] ^= 1;
                nums[i] ^= 1;
                cnt++;
            }
        }
        return accumulate(nums.begin(), nums.end(), 0) == nums.size() ? cnt : -1;
    }
};