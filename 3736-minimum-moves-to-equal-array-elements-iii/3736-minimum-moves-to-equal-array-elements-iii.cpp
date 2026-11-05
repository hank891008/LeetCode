class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxx = *max_element(nums.begin(), nums.end());
        int ans = 0;
        for(auto num: nums) {
            ans += maxx - num;
        }
        return ans;
    }
};