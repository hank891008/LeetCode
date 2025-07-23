class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int> used;
        int ans = 0, curr = 0;
        int l = 0;
        for(int r = 0; r < nums.size(); r++){
            curr += nums[r];
            while(used.count(nums[r])){
                used.erase(nums[l]);
                curr -= nums[l++];
            }
            used.insert(nums[r]);
            ans = max(ans, curr);
        }
        return ans;
    }
};