class Solution {
public:
    int n;
    int solve(vector<int>& arr, int k, vector<int>& dp, int now){
        if(now >= n){
            return 0;
        }
        if(dp[now] != -1){
            return dp[now];
        }
        int maxx = 0;
        int ans = 0;
        for(int i = now; i < min(n, now + k); i++){
            maxx = max(maxx, arr[i]);
            ans = max(ans, maxx * (i - now + 1) + solve(arr, k, dp, i + 1));
        }
        return dp[now] = ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        n = arr.size();
        vector<int> dp(n, -1);
        return solve(arr, k, dp, 0);
    }
};