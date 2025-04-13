class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        pair<int, int> p[605];
        for(int i = 0; i < strs.size(); i++){
            for(auto s: strs[i]){
                if(s == '0'){
                    p[i].first++;
                }
                else{
                    p[i].second++;
                }
            }
        }
        int dp[605][105][105];
        memset(dp, 0, sizeof(dp));
        for(int i = p[0].first; i <= m; i++){
            for(int j = p[0].second; j <= n; j++){
                dp[0][i][j] = 1;
            }
        }
        for(int i = 1; i < strs.size(); i++){
            for(int j = 0; j <= m; j++){
                for(int k = 0; k <= n; k++){
                    if(j - p[i].first >= 0 && k - p[i].second >= 0){
                        dp[i][j][k] = max(dp[i - 1][j][k], dp[i - 1][j - p[i].first][k - p[i].second] + 1);
                    }
                    else{
                        dp[i][j][k] = dp[i - 1][j][k];
                    }
                }
            }
        }
        return dp[strs.size() - 1][m][n];
    }
};