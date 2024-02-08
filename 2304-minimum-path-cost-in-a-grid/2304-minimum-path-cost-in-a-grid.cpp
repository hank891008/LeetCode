class Solution {
public:
    const int MAXN = 0x3f3f3f3f;
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> ans(2, grid[0]);
        int ret = MAXN;
        for(int i = 1; i < n; i++){
            for(int j = 0; j < m; j++){
                ans[i & 1][j] = MAXN;
                for(int k = 0; k < m; k++){
                    ans[i & 1][j] = min(ans[i & 1][j], grid[i][j] + ans[i & 1 ^ 1][k] + moveCost[grid[i - 1][k]][j]);
                }
                if(i == n - 1){
                    ret = min(ret, ans[i & 1][j]);
                }
            }
        }
        return ret;
    }
};