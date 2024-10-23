class Solution {
public:
    map<pair<int, int>, int> m;
    int dfs(int i, int j, int score, vector<int>& nums){
        if(m.count({i, j})){
            return m[{i, j}];
        }
        int maxx = 0;
        if(j - i + 1 >= 2){
            if(nums[i] + nums[i + 1] == score){
                maxx = max(maxx, 1 + dfs(i + 2, j, score, nums));
            }
            if(nums[i] + nums[j] == score){
                maxx = max(maxx, 1 + dfs(i + 1, j - 1, score, nums));
            }
            if(nums[j] + nums[j - 1] == score){
                maxx = max(maxx, 1 + dfs(i, j - 2, score, nums));
            }
        }
        return m[{i, j}] = maxx;
    }
    int maxOperations(vector<int>& nums) {
        int n = nums.size();
        return max({
            dfs(0, n - 3, nums[n - 1] + nums[n - 2], nums),
            dfs(1, n - 2, nums[0] + nums[n - 1], nums),
            dfs(2, n - 1, nums[0] + nums[1], nums)
        }) + 1;
    }
};