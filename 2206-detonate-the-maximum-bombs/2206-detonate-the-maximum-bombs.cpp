class Solution {
public:
    vector<vector<int>> G;
    vector<bool> used;
    void dfs(int u){
        used[u] = true;
        for(int v: G[u]){
            if(!used[v]){
                dfs(v);
            }
        }
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        G.resize(n);
        for(int i = 0; i < bombs.size(); i++){
            for(int j = i + 1; j < bombs.size(); j++){
                long long x1 = bombs[i][0], y1 = bombs[i][1], r1 = bombs[i][2];
                long long x2 = bombs[j][0], y2 = bombs[j][1], r2 = bombs[j][2];
                long long dis = abs(x1 - x2) * abs(x1 - x2) + abs(y1 - y2) * abs(y1 - y2);
                if(dis <= r1 * r1){
                    G[i].emplace_back(j);
                }
                if(dis <= r2 * r2){
                    G[j].emplace_back(i);
                }
            }
        }
        int maxx = 0;
        for(int i = 0; i < n; i++){
            used.assign(n, false);
            dfs(i);
            maxx = max(maxx, accumulate(used.begin(), used.end(), 0));
        }
        return maxx;
    }
};