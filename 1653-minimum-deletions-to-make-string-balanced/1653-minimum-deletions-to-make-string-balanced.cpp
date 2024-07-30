class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        vector<int> dp(n, 0);
        int b = (s[0] == 'b');
        for(int i = 1; i < n; i++){
            if(s[i] == 'b'){
                dp[i] = dp[i - 1];
                b++;
            }
            else{
                dp[i] = min(dp[i - 1] + 1, b);
            }
        }
        return dp[n - 1];
    }
};