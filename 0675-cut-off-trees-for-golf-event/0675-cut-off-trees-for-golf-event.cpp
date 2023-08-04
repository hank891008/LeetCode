class Solution {
public:
    int n, m;
    int dir[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};
    bool check(int x, int y){
        return x >= 0 && x < n && y >= 0 && y < m;
    }
    int bfs(vector<vector<int>> forest, int s_x, int s_y, int e_x, int e_y){
        bool visited[n][m];
        memset(visited, 0, sizeof(visited));
        
        queue<pair<int, int>>q;
        q.emplace(s_x, s_y);
        visited[s_x][s_y] = true;
        int steps = 0;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                pair<int, int> now = q.front();
                q.pop();
                int c_x = now.first;
                int c_y = now.second;
                if(c_x == e_x && c_y == e_y){
                    return steps;
                }
                for(int i = 0; i < 4; i++){
                    int x = c_x + dir[i][0];
                    int y = c_y + dir[i][1];
                    if(!check(x, y) || visited[x][y] || forest[x][y] == 0){
                        continue;
                    }
                    q.emplace(x, y);
                    visited[x][y] = 1;
                }
            }
            steps++;
        }
        return INT_MAX;
    }
    int cutOffTree(vector<vector<int>>& forest) {
        n = forest.size();
        m = forest[0].size();
        vector<pair<int, pair<int, int>>>v;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(forest[i][j] > 1){
                    v.push_back({forest[i][j], {i, j}});
                }
            }
        }
        sort(v.begin(), v.end());
        int x_prev = 0, y_prev = 0;
        int ans = 0;
        for(int i = 0; i < v.size(); i++){
            int x_now = v[i].second.first;
            int y_now = v[i].second.second;
            int step = bfs(forest, x_prev, y_prev, x_now, y_now);
            if(step == INT_MAX){
                return -1;
            }
            ans += step;
            x_prev = x_now;
            y_prev = y_now;
        }
        return ans;
    }
};