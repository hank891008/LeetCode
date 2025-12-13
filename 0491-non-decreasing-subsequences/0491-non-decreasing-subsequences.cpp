class Solution {
public:
    set<vector<int>> s;
    void dfs(vector<int>& curr, vector<int>& nums, int n, int idx) {
        if(curr.size() >= 2) {
            s.emplace(curr);
        }
        for(int i = idx; i < n; i++) {
            if(curr.empty() || nums[i] >= curr.back()) {
                curr.emplace_back(nums[i]);
                dfs(curr, nums, n, i + 1);
                curr.pop_back();
            }
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        int n = nums.size(); 
        vector<int> curr;
        dfs(curr, nums, n, 0);
        return vector<vector<int>> (s.begin(), s.end());
    }
};