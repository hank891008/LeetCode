class Solution {
public:
    int maximumCount(vector<int>& nums) {
        if(nums.back() < 0 || nums[0] > 0){
            return nums.size();
        }
        int l = 0, r = nums.size();
        while(l < r){
            int m = (l + r) / 2;
            if(nums[m] >= 0){
                r = m;
            }
            else{
                l = m + 1;   
            }
        }
        int left = l, right = l;
        while(left >= 0 && nums[left] >= 0){
            left--;
        }
        while(right < nums.size() && nums[right] <= 0){
            right++;
        }
        return max(left + 1, (int)nums.size() - right);
    }
};