class Solution {
public:
    vector<bool> used;
    set<vector<int>> s;
    void dfs(vector<int>& curr, vector<int>& nums, int n, int idx) {
        if(curr.size() >= 2 && !s.count(curr)) {
            s.emplace(curr);
        }
        for(int i = idx; i < n; i++) {
            if(used[i]){
                continue;
            }
            if(curr.empty() || nums[i] >= curr.back()) {
                curr.emplace_back(nums[i]);
                used[i] = true;
                dfs(curr, nums, n, i + 1);
                used[i] = false;
                curr.pop_back();
            }
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        int n = nums.size();
        used.resize(n);
        vector<int> curr;
        dfs(curr, nums, n, 0);
        vector<vector<int>> ans;
        for(auto v: s) {
            ans.emplace_back(v);
        }
        return ans;
    }
};