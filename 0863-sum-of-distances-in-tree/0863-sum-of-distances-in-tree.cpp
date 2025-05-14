class Solution {
public:
    vector<int> ans, depth, sz;
    vector<vector<int>> G;
    void dfs(int u, int fa){
        sz[u] = 1;
        for(auto v: G[u]){
            if(v == fa){
                continue;
            }
            depth[v] = depth[u] + 1;
            dfs(v, u);
            sz[u] += sz[v];
        }
    }
    void dfs2(int u, int fa){
        for(auto v: G[u]){
            if(v == fa){
                continue;
            }
            ans[v] = ans[u] - sz[v] + (sz.size() - sz[v]);
            dfs2(v, u);
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        G.resize(n);
        ans.resize(n, 0);
        depth.resize(n, 0);
        sz.resize(n, 0);
        for(auto e: edges){
            G[e[0]].emplace_back(e[1]);
            G[e[1]].emplace_back(e[0]);
        }
        dfs(0, -1);
        ans[0] = accumulate(depth.begin(), depth.end(), 0);
        dfs2(0, -1);
        return ans;
    }
};