class Solution {
public:
    int n;
    map<vector<int>, int> dp;
    
    int dfs(vector<int> needs, vector<int>& price, vector<vector<int>> special){
        if(dp[needs]){
            return dp[needs];
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            ans += needs[i] * price[i];
        }
        for(auto s: special){
            int flag = true;
            for(int i = 0; i < n; i++){
                if(s[i] > needs[i]){
                    flag = false;
                    break;
                }
            }
            if(!flag){
                continue;
            }
            auto next = needs;
            for(int i = 0; i < n; i++){
                next[i] -= s[i];
            }
            ans = min(ans, dfs(next, price, special) + s.back());
        }
        return dp[needs] = ans;
    }
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        n = price.size();
        return dfs(needs, price, special);

    }
};