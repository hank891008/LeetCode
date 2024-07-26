class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        int G[105][105];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                G[i][j] = 0x3f3f3f3f;
            }
            G[i][i] = 0;
        }
        for(auto edge: edges){
            int u = edge[0], v = edge[1], w = edge[2];
            G[u][v] = G[v][u] = w;
        }
        for(int k = 0; k < n; k++){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
                }
            }
        }
        int minn = INT_MAX, ans = 0;
        for(int i = 0; i < n; i++){
            int cnt = 0;
            for(int j = 0; j < n; j++){
                if(i == j){
                    continue;
                }
                if(G[i][j] <= distanceThreshold){
                    cnt++;
                }
            }
            cout << cnt << '\n';
            if(cnt <= minn){
                minn = cnt;
                ans = i;
            }
        }
        return ans;
    }
};