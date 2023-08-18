class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int>G[105];
        for(int i = 0; i < roads.size(); i++){
            G[roads[i][0]].emplace_back(roads[i][1]);
            G[roads[i][1]].emplace_back(roads[i][0]);
        }
        int maxx = INT_MIN;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                int now = G[i].size() + G[j].size();
                cout << i << ' ' << j << '\n';
                cout << now << '\n';
                for(auto it_i: G[i]){
                    if(it_i == j){
                        now--;
                        break;
                    }
                }
                maxx = max(maxx, now);
            }
        }
        return maxx;
    }
};