class Solution {
public:
    vector<int> perfect;
    int memo[10005];
    int ans = INT_MAX;
    int dfs(int now){
        if(memo[now] != -1){
            return memo[now];
        }
        int minn = INT_MAX;
        for(auto p: perfect){
            if(now >= p){
                minn = min(minn, dfs(now - p));
            }
        }
        return memo[now] = 1 + minn;
    }
    int numSquares(int n) {
        for(int i = sqrt(n); i >= 1; i--){
            perfect.emplace_back(i * i);
        }
        memset(memo, -1, sizeof(memo));
        memo[0] = 0;
        return dfs(n);
    }
};