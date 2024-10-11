class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        int color[n];    // -1 for unknown, 0, 1
        queue<int> q;
        memset(color, -1, sizeof(color));
        for(int i = 0; i < n; i++){
            if(color[i] != -1){
                continue;
            }
            q.emplace(i);
            color[i] = 0;
            while(!q.empty()){
                int u = q.front();    q.pop();
                for(auto v: graph[u]){
                    if(color[v] == color[u]){
                        return false;
                    }
                    else if(color[v] == -1){
                        color[v] = color[u] ^ 1;
                        q.emplace(v);
                    }
                }
            }
        }
        unordered_set<int> s(color, color + n);
        return true;
    }
};