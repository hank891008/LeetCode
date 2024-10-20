class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1){
            return {0};
        }
        vector<int> degree(n);
        vector<vector<int>> G(n);
        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0], v = edges[i][1];
            G[u].emplace_back(v);
            G[v].emplace_back(u);
            degree[u]++;
            degree[v]++;
        }
        queue<int> q;
        for(int i = 0; i < n; i++){
            if(degree[i] == 1){
                q.emplace(i);
            }
        }
        vector<int> ans;
        while(!q.empty()){
            ans.clear();
            int sz = q.size();
            while(sz--){
                int u = q.front();    q.pop();
                ans.emplace_back(u);
                for(auto v: G[u]){
                    if(--degree[v] == 1){
                        q.emplace(v);
                    }
                }
            }
        }
        return ans;
    }
};