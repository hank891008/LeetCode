class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> in_deg(numCourses);
        vector<int> ans;
        vector<vector<int>> G(numCourses);
        for(auto p: prerequisites){
            int b = p[0], a = p[1];
            G[a].emplace_back(b);
            in_deg[b]++;
        }
        queue<int> q;
        for(int i = 0; i < numCourses; i++){
            if(in_deg[i] == 0){
                q.emplace(i);
            }
        }
        while(!q.empty()){
            auto u = q.front();   q.pop();
            ans.emplace_back(u);
            for(auto v: G[u]){
                if(--in_deg[v] == 0){
                    q.emplace(v);
                }
            }
        }
        if(ans.size() == numCourses){
            return ans;
        }
        return {};
    }
};