class Solution {
public:
    bool used[200005];
    bool dfs(vector<int>G[], int now, int target){
        used[now] = true;
        if(now == target){
            return true;
        }
        bool finded = false;
        for(auto v: G[now]){
            if(!used[v]){
                finded |= dfs(G, v, target);
            }
        }
        return finded;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int>G[200005];
        for(int i = 0; i < edges.size(); i++){
            G[edges[i][0]].emplace_back(edges[i][1]);
            G[edges[i][1]].emplace_back(edges[i][0]);
        }
        return dfs(G, source, destination);
    }
};