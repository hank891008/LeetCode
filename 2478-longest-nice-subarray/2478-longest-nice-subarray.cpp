class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int ans = 0;
        int l = 0;
        int now = 0;
        for(int r = 0; r < nums.size(); r++){
            while(now & nums[r]){
                now ^= nums[l++];
            }
            now |= nums[r];
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};