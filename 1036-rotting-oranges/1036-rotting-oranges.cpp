class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        queue<pair<int, int>> q;
        int cnt = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1){
                    cnt++;
                }
                else if(grid[i][j] == 2){
                    q.emplace(i, j);
                }
            }
        }
        if(cnt == 0){
            return 0;
        }
        if(q.empty()){
            return -1;
        }
        int dir[4][2] = {-1, 0, 1, 0, 0, 1, 0, -1};
        int step = 0;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                auto [x, y] = q.front();    q.pop();
                for(int i = 0; i < 4; i++){
                    int dx = x + dir[i][0];
                    int dy = y + dir[i][1];
                    if(dx >= 0 && dx < n && dy >= 0 && dy < m && grid[dx][dy] == 1){
                        grid[dx][dy] = 2;
                        cnt--;
                        q.emplace(dx, dy);
                    }
                }
            }
            step++;
        }
        if(cnt == 0){
            return step - 1;
        }
        return -1;
    }
};