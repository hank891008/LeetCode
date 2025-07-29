class Solution {
public:
    int minSessions(vector<int>& tasks, int sessionTime) {
        int n = tasks.size();
        vector<int> check(1 << n, false);
        for(int i = 1; i < (1 << n); i++){
            int total = 0;
            for(int j = 0; j < n; j++){
                if((i >> j) & 1){
                    total += tasks[j];
                }
            }
            check[i] = total <= sessionTime;
        }

        vector<int> dp(1 << n, 0x3f3f3f3f);
        dp[0] = 0;
        for(int i = 1; i < (1 << n); i++){
            for(int j = i; j; j = (j - 1) & i){
                if(check[j]){
                    dp[i] = min(dp[i], dp[i ^ j] + 1);
                }
            }
        }
        return dp[(1 << n) - 1];
    }
};