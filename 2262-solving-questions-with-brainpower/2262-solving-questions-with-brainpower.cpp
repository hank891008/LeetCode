class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n);
        for(int i = n - 1; i >= 0; i--){
            int idx = i + questions[i][1] + 1;
            if(idx >= n){
                dp[i] = questions[i][0];
            }
            else{
                dp[i] = questions[i][0] + dp[idx];
            }
            if(i < n - 1){
                dp[i] = max(dp[i], dp[i + 1]);
            }
        }
        return dp[0];
    }
};