class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        set<pair<int, int>> s;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j]){
                    s.insert({i, j});
                }
            }
        }
        if(s.size() == 0 || s.size() == n * m){
            return -1;
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!grid[i][j]){
                    int minn = INT_MAX;
                    for(auto [x, y]: s){
                        minn = min(minn, abs(x - i) + abs(y - j));
                    }
                    ans = max(ans, minn);
                }
            }
        }
        return ans;
    }
};