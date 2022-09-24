class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curr = 0, maxx = INT_MIN;
        for(int i = 0; i < nums.size(); i++){
            curr += nums[i];
            maxx = max(maxx, curr);
            curr = max(curr, 0);
        }
        return maxx;
    }
};