class Solution {
public:
    int dir[4][2] = {-1, 0, 1, 0, 0, -1, 0, 1};
    bool check(int x, int y, vector<vector<int>>& grid){
        return x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size() && grid[x][y];
    }
    int dfs(int x, int y, vector<vector<int>>& grid){
        int ans = grid[x][y];
        grid[x][y] = 0;
        for(int i = 0; i < 4; i++){
            int new_x = x + dir[i][0];
            int new_y = y + dir[i][1];
            if(check(new_x, new_y, grid)){
                ans += dfs(new_x, new_y, grid);
            }
        }
        return ans;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxx = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if(grid[i][j]){
                    maxx = max(maxx, dfs(i, j, grid));
                }
            }
        }
        return maxx;
    }
};