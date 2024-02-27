class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int l = 0, r = 0;
        int maxx = 0;
        bool has_zero = false;
        while(l < nums.size() && r < nums.size()){
            if(nums[r] == 1){
                maxx = max(maxx, r - l + 1);
                r++;
            }
            else if(has_zero == false && nums[r] == 0){
                has_zero = true;
                maxx = max(maxx, r - l + 1);
                r++;
            }
            else{
                if(nums[l] == 0){
                    has_zero = false;
                }
                l++;
            }
        }
        return maxx - 1;
    }
};