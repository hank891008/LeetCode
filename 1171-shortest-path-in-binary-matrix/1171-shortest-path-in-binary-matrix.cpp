class Solution {
public:
    int pos[8][2] = {{1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1}};
    bool check(int x, int y, int n, int m){
        return x >= 0 && x < n && y >= 0 && y < m;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        if(grid[0][0] != 0){
            return -1;
        }
        queue<pair<int, int>> q{{{0, 0}}};
        grid[0][0] = 1;
        int length = 1;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                auto [x, y] = q.front();
                q.pop();
                if(x == n - 1 && y == m - 1){
                    return length;
                }
                for(int i = 0; i < 8; i++){
                    int new_x = x + pos[i][0], new_y = y + pos[i][1];
                    if(check(new_x, new_y, n, m) && grid[new_x][new_y] != 1){
                        grid[new_x][new_y] = 1;
                        q.emplace(new_x, new_y);
                    }
                }
            }
            length++;
        }
        return -1;
    }
};