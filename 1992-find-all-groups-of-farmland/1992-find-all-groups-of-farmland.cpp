class Solution {
public:
    int n, m;
    int dirs[4][2] = {-1, 0, 1, 0, 0, -1, 0, 1};
    vector<int>ans;
    bool check(int i, int j){
        return i >= 0 && i < n && j >= 0 && j < m;
    }
    void dfs(int i, int j, vector<vector<int>>& land){
        land[i][j] = 0;
        if(i >= ans[2] && j >= ans[3]){
            ans[2] = i;
            ans[3] = j;
        }
        for(auto dir: dirs){
            int _i = i + dir[0], _j = j + dir[1];
            if(check(_i, _j) && land[_i][_j] == 1){
                dfs(_i, _j, land);
            }
        }
    }
    
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>> ret;
        n = land.size();
        m = land[0].size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(land[i][j] == 1){
                    ans = {i, j, -1, -1};
                    dfs(i, j, land);
                    ret.emplace_back(ans);
                }
            }
        }
        return ret;
    }
};