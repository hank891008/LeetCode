class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        map<vector<int>, int>Map;
        for(int i = 0; i < n; i++){
            Map[grid[i]]++;
        }
        vector<vector<int>>T(m, vector<int>(n));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                T[j][i] = grid[i][j];
            }
        }
        int ans = 0;
        for(int i = 0; i < m; i++){
            if(Map.count(T[i])){
                ans += Map[T[i]];
            }
        }
        return ans;
    }
};