class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        for(int i = 0; i < n; i++){
            sort(grid[i].begin(), grid[i].end(), greater<int>());
        }
        int ans = 0;
        for(int i = 0; i < m; i++){
            int maxx = 0;
            for(int j = 0; j < n; j++){
                maxx = max(maxx, grid[j][i]);
            }
            ans += maxx;
        }
        return ans;
    }
};