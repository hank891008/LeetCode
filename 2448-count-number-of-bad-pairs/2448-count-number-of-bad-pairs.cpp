class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long ans = 0;
        unordered_map<int, int> good;
        for(int i = 0; i < nums.size(); i++){
            int diff = i - nums[i];
            ans += i - good[diff]++;
        }
        return ans;
    }
};