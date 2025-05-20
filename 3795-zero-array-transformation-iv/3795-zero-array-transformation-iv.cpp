class Solution {
public:
    const int INF = 0x3f3f3f3f;
    int solve(vector<vector<int>>& q, vector<vector<int>>& dp, int idx, int target, int k){
        if(target == 0){
            return k;
        }
        if(k == q.size() || target < 0){
            return INF;
        }
        if(dp[target][k] != -1){
            return dp[target][k];
        }
        int res = solve(q, dp, idx, target, k + 1);
        if(q[k][0] <= idx && idx <= q[k][1]){
            res = min(res, solve(q, dp, idx, target - q[k][2], k + 1));
        }
        return dp[target][k] = res;
    }

    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int ans = 0;
        for(int i = 0; i < nums.size(); i++){
            vector<vector<int>> dp(nums[i] + 1, vector<int>(queries.size() + 1, -1));
            ans = max(ans, solve(queries, dp, i, nums[i], 0));
            if(ans == INF){
                return -1;
            }
        }
        return ans;
    }
};