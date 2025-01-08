class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long total = accumulate(nums.begin(), nums.end(), 0LL);
        long long now = 0;
        int ans = 0;
        nums.pop_back();
        for(auto num: nums){
            now += num;
            ans += (2 * now >= total);
        }
        return ans;
    }
};