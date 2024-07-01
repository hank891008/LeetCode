class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dp(n, 0x3f3f3f3f);
        dp[src] = 0;
        for(int i = 1; i <= k + 1; i++){
            vector<int> now = dp;
            for(auto flight: flights){
                int from = flight[0], to = flight[1], cost = flight[2];
                now[to] = min(now[to], dp[from] + cost);
            }
            dp = now;
        }
        if(dp[dst] == 0x3f3f3f3f){
            return -1;
        }
        return dp[dst];
    }
};