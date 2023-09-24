class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        double dp[105][105];
        memset(dp, 0, sizeof(dp));
        dp[0][0] = poured;
        for(int i = 0; i <= query_row; i++){
            for(int j = 0; j <= i; j++){
                if(dp[i][j] > 1.0){
                    double fall = (dp[i][j] - 1) / 2;
                    dp[i][j] = 1.0;
                    dp[i + 1][j] += fall;
                    dp[i + 1][j + 1] += fall;
                }
                cout << dp[i][j] << ' ';
            }
            cout << '\n';
        }
        return dp[query_row][query_glass];
    }
};