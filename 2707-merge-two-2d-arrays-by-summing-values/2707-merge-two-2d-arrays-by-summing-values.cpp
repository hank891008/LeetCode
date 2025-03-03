class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        map<int, int> mp;
        for(auto nums: nums1){
            mp[nums[0]] += nums[1];
        }
        for(auto nums: nums2){
            mp[nums[0]] += nums[1];
        }
        vector<vector<int>> ans;
        for(auto [x, y]: mp){
            ans.push_back({x, y});
        }
        return ans;
    }
};