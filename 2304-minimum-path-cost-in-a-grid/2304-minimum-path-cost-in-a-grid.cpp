class Solution {
public:
    const int MAXN = 0x3f3f3f3f;
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> ans(n, vector<int>(m, MAXN));
        for(int i = 0; i < m; i++){
            ans[0][i] = grid[0][i];
        }
        int ret = MAXN;
        for(int i = 1; i < n; i++){
            for(int j = 0; j < m; j++){
                for(int k = 0; k < m; k++){
                    int tmp = grid[i][j] + ans[i - 1][k] + moveCost[grid[i - 1][k]][j];
                    ans[i][j] = min(ans[i][j], tmp);
                }
                if(i == n - 1){
                    ret = min(ret, ans[i][j]);
                }
            }
        }
        return ret;
    }
};