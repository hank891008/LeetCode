class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        bool used[n];
        memset(used, 0, sizeof(used));
        for(int i = 0; i < edges.size(); i++){
            used[edges[i][1]] = true;
        }
        vector<int> ans;
        for(int i = 0; i < n; i++){
            if(!used[i]){
                ans.emplace_back(i);
            }
        }
        return ans;
    }
};