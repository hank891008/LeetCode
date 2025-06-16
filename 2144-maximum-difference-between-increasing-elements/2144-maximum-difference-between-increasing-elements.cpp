class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int ans = 0, minn = nums[0];
        for(int i = 1; i < nums.size(); i++){
            ans = max(ans, nums[i] - minn);
            minn = min(minn, nums[i]);
        }
        return ans == 0 ? -1 : ans;
    }
};