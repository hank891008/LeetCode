class Solution {
public:
    vector<int> topoSort(vector<vector<int>>& G){
        int n = G.size();
        vector<int> indeg(n), ret;
        for(auto &li: G){
            for(int x: li){
                ++indeg[x];
            }
        }
        queue<int> q;
        for(int i = 0; i < n; i++){
            if(!indeg[i]){
                q.emplace(i);
            }
        }
        while(!q.empty()){
            int u = q.front();  q.pop();
            ret.emplace_back(u);
            for(int v: G[u]){
                if(--indeg[v] == 0){
                    q.emplace(v);
                }
            }
        }
        return ret;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
       vector<vector<int>> G;
        G.resize(numCourses);
        for(int i = 0; i < prerequisites.size(); i++){
            int u = prerequisites[i][0], v = prerequisites[i][1];
            G[u].emplace_back(v);
        }
        vector<int> ret = topoSort(G);
        return ret.size() >= numCourses;
    }
};