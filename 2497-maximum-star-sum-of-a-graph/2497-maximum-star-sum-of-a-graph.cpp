class Solution {
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        vector<int>G[vals.size()];
        for(int i = 0; i < edges.size(); i++){
            G[edges[i][0]].emplace_back(vals[edges[i][1]]);
            G[edges[i][1]].emplace_back(vals[edges[i][0]]);
        }
        int maxx = INT_MIN;
        for(int i = 0; i < vals.size(); i++){
            sort(G[i].begin(), G[i].end(), greater<int>());
            int now = vals[i];
            for(int j = 0; j < min(k, (int)G[i].size()); j++){
                if(G[i][j] <= 0){
                    break;
                }
                now += G[i][j];
            }
            maxx = max(maxx, now);
        }
        return maxx;
    }
};