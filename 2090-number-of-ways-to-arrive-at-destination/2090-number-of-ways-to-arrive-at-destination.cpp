class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int MOD = 1e9 + 7;
        vector<vector<pair<int, int>>> G(n);
        for(auto road: roads){
            G[road[0]].emplace_back(road[1], road[2]);
            G[road[1]].emplace_back(road[0], road[2]);
        }
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
        vector<long long> shortest(n, LLONG_MAX);
        vector<int> cnt(n, 0);
        shortest[0] = 0;
        cnt[0] = 1;
        pq.emplace(0, 0);
        while(!pq.empty()){
            long long time = pq.top().first;
            int u = pq.top().second;
            pq.pop();
            if(time > shortest[u]){
                continue;
            }
            for(auto& [v, next_time]: G[u]){
                if(time + next_time < shortest[v]){
                    shortest[v] = time + next_time;
                    cnt[v] = cnt[u];
                    pq.emplace(shortest[v], v);
                }
                else if(time + next_time == shortest[v]){
                    cnt[v] = (cnt[v] % MOD + cnt[u] % MOD) % MOD;
                }
            }
        }
        return cnt.back();
    }
};