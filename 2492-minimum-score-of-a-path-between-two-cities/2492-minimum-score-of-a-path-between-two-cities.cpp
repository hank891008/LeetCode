class Solution {
public:
    int fa[100005];
    int findr(int x) {
        return x == fa[x] ? fa[x] : fa[x] = findr(fa[x]);
    }
    void unite(int x, int y) {
        x = findr(x);
        y = findr(y);
        fa[y] = x;
    }

    int minScore(int n, vector<vector<int>>& roads) {
        for(int i = 1; i <= n; i++) {
            fa[i] = i;
        }
        for(auto road: roads) {
            unite(road[0], road[1]);
        }
        int ans = INT_MAX;
        for(auto road: roads) {
            if(findr(road[0]) == findr(1)) {
                ans = min(ans, road[2]);
            }
        }
        return ans;
    }
};