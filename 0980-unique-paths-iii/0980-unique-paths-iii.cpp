class Solution {
public:
    int pos[4][2] = {0, -1, 0, 1, 1, 0, -1, 0};
    int n, m;
    int sx, sy, ex, ey;
    int ans = 0;
    int can_walk = 0;
    bool used[25][25];
    
    bool check(int x, int y){
        return x >= 0 && x < n && y >= 0 && y < m;
    }
    
    void dfs(vector<vector<int>>& grid, int x, int y, int step){
        if(x == ex && y == ey){
            ans += (step == can_walk);
            return;
        }
        for(int i = 0; i < 4; i++){
            int _x = x + pos[i][0], _y = y + pos[i][1];
            if(check(_x, _y) && grid[_x][_y] != -1 && !used[_x][_y]){
                used[_x][_y] = true;
                dfs(grid, _x, _y, step + 1);
                used[_x][_y] = false;
            }
        }
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1){
                    sx = i;
                    sy = j;
                }
                if(grid[i][j] == 2){
                    ex = i;
                    ey = j;
                    can_walk++;
                }
                if(grid[i][j] == 0){
                    can_walk++;
                }
            }
        }
        cout <<can_walk << '\n';
        used[sx][sy] = true;
        dfs(grid, sx, sy, 0);
        return ans;
    }
};