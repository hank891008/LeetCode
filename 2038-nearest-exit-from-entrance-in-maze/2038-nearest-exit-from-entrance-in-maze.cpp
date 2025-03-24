class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n = maze.size(), m = maze[0].size();
        set<pair<int, int>> used;
        int dir[4][2] = {-1, 0, 1, 0, 0, 1, 0, -1};
        queue<pair<int, int>> q{{make_pair(entrance[0], entrance[1])}};
        int step = 0;
        maze[entrance[0]][entrance[1]] = '+';
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                auto [x, y] = q.front();    q.pop();
                if(maze[x][y] != '+' && (x == 0 || x == n - 1 || y == 0 || y == m - 1)){
                    return step;
                }
                maze[x][y] = '+';
                for(int i = 0; i < 4; i++){
                    int dx = x + dir[i][0], dy = y + dir[i][1];
                    if(dx >= 0 && dx < n && dy >= 0 && dy < m && maze[dx][dy] == '.' && !used.count({dx, dy})){
                        q.emplace(dx, dy);
                        used.insert({dx, dy});
                    }
                }
            }
            step++;
        }
        return -1;
    }
};