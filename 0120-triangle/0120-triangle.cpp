class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        auto dp = triangle;
        for(int i = triangle.size() - 1; i >= 1; i--){
            for(int j = 0; j < triangle[i].size() - 1; j++){
                dp[i - 1][j] += min(dp[i][j], dp[i][j + 1]);
            }
        }
        return dp[0][0];
    }
};