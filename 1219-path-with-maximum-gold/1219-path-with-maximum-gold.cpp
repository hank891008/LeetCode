class Solution {
public:
    int n, m;
    int pos[4][2] = {-1, 0, 1, 0, 0, -1, 0, 1};
    int used[20][20];
    
    bool check(int x, int y){
        return x >= 0 && x < n && y >= 0 && y < m;
    }
    int dfs(int x, int y, vector<vector<int>>& grid){
        int maxx = 0;
        int ans = grid[x][y];
        used[x][y] = 1;
        for(int i = 0; i < 4; i++){
            int new_x = x + pos[i][0], new_y = y + pos[i][1];
            if(check(new_x, new_y) && grid[new_x][new_y] != 0 && used[new_x][new_y] == 0){
                maxx = max(maxx, dfs(new_x, new_y, grid));
            }
        }
        used[x][y] = 0;
        return ans + maxx;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] != 0){
                    memset(used, 0, sizeof(used));
                    ans = max(ans, dfs(i, j, grid));
                }
            }
        }
        return ans;
    }
};