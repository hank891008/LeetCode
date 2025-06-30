class Solution {
public:
    int findLHS(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        sort(nums.begin(), nums.end());
        for(int l = 0, r = 1; r < n; r++){
            while(l < r && nums[l] < nums[r] - 1){
                l++;
            }
            if(nums[l] == nums[r] - 1){
                ans = max(ans, r - l + 1);
            }
        }
        return ans;
    }
};