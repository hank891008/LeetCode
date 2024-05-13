class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        for(int i = 0; i < n; i++){
            if(grid[i][0] == 0){
                for(int j = 0; j < m; j++){
                    grid[i][j] ^= 1;
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < m; i++){
            int one = 0;
            for(int j = n - 1; j >= 0; j--){
                one += grid[j][i];
            }
            ans = (ans << 1) + max(n - one, one);
        }
        return ans;
    }
};