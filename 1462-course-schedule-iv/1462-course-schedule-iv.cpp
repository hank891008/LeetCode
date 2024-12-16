class Solution {
public:
    bool dfs(vector<vector<int>> &G, vector<bool> &used, int s, int e){
        if(s == e){
            return true;
        }
        bool ans = 0;
        for(auto v: G[s]){
            if(!used[v]){
                used[v] = 1;
                ans |= dfs(G, used, v, e);
            }
        }
        return ans;
    }
    
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> G;
        vector<bool> used;
        G.resize(numCourses);
        
        for(auto p: prerequisites){
            G[p[0]].emplace_back(p[1]);
        }
        
        vector<bool> ans;
        for(auto q: queries){
            used.assign(numCourses, 0);
            used[q[0]] = true;
            ans.emplace_back(dfs(G, used, q[0], q[1]));
        }
        return ans;
    }
};