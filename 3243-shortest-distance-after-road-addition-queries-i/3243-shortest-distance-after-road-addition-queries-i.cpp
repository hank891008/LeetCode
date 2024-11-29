class Solution {
public:
    int bfs(int n, vector<int> G[]){
        queue<int> q{{0}};
        vector<int> used(n, 0);
        int dis = 0;
        while(!q.empty()){
           int sz = q.size();
            while(sz--){
                int u = q.front();    q.pop();
                if(used[u]){
                    continue;
                }
                used[u] = 1;
                if(u == n - 1){
                    return dis;
                }
                for(auto v: G[u]){
                    q.emplace(v);
                }
            }
            dis++;
        }
        return -1;
        
    }
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int>G[n];
        for(int i = 0; i < n - 1; i++){
            G[i].emplace_back(i + 1);
        }
        vector<int> ans;
        for(auto q: queries){
            G[q[0]].emplace_back(q[1]);
            ans.emplace_back(bfs(n, G));
        }
        return ans;
    }
};