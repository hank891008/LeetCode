class Solution {
public:
    int row[50 + 5], col[50 + 5];
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                row[i] = max(row[i], grid[i][j]);
                col[j] = max(col[j], grid[i][j]);
            }
        }
        int ans = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                ans += min(row[i], col[j]) - grid[i][j];
            }
        }
        return ans;
    }
};