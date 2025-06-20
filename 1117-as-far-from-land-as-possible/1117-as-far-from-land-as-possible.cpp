class Solution {
public:
    int dir[4][2] = {
        {-1, 0},
        {1, 0},
        {0, -1},
        {0, 1}
    };
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        queue<pair<int, int>> q;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j]){
                    q.emplace(i, j);
                }
            }
        }
        if(q.size() == 0 || q.size() == n * m){
            return -1;
        }
        int ans = 0;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                auto [_x, _y] = q.front();
                q.pop();
                for(int i = 0; i < 4; i++){
                    int x = _x + dir[i][0], y = _y + dir[i][1];
                    if(x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == 0){
                        grid[x][y] = 1;
                        q.emplace(x, y);
                    }
                }
            }
            if(q.size()){
                ans++;
            }
        }
        return ans;
    }
};