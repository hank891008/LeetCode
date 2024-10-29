class Solution {
public:
    int dir[3] = {-1, 0, 1};
    int maxMoves(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        set<pair<int, int>> s;
        queue<pair<pair<int, int>, int>> q;
        for(int i = 0; i < n; i++){
            s.insert({i, 0});
            q.push({{i, 0}, 0});
        }
        int max_step = 0;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                auto now = q.front();   q.pop();
                int x = now.first.first, y = now.first.second, step = now.second;
                max_step = max(max_step, step);
                for(int i = 0; i < 3; i++){
                    int new_x = x + dir[i], new_y = y + 1;
                    if(new_x >= 0 && new_x < n && new_y >= 0 && new_y < m && grid[x][y] < grid[new_x][new_y] && !s.count({new_x, new_y})){
                        s.insert({new_x, new_y});
                        q.push({{new_x, new_y}, step + 1});
                    }
                }
            }
        }
        return max_step;
    }
};