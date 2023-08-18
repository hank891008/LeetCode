class Solution {
public:
    int n, m;
    int dir[4][2] = {-1, 0, 1, 0, 0, -1, 0, 1};
    bool check(int x, int y){
        return x >= 0 && x < n && y >= 0 && y < m;
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int sx = -1, sy = -1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] != 0){
                    sx = i, sy = j;
                    break;
                }
            }
            if(sx != -1){
                break;
            }
        }
        int ans = 0;
        bool used[n][m];
        memset(used, 0, sizeof(used));
        queue<pair<int, int>>q;
        q.emplace(sx, sy);
        while(!q.empty()){
            auto now = q.front();   q.pop();
            if(used[now.first][now.second]){
                continue;
            }
            used[now.first][now.second] = true;
            int cnt = 0;
            for(int i = 0; i < 4; i++){
                int x = now.first + dir[i][0];
                int y = now.second + dir[i][1];
                if(check(x, y) && grid[x][y] == 1){
                    if(!used[x][y]){
                        q.emplace(x, y);
                    }
                    cnt++;
                }
            }
            ans += (4 - cnt);
        }
        return ans;
    }
};