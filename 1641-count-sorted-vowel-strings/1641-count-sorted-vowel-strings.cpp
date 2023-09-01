class Solution {
public:
    int countVowelStrings(int n) {
        int dp[] = {1, 1, 1, 1, 1};
        for(int i = 2; i <= n; i++){
            int sum = 0;
            for(int j = 4; j >= 0; j--){
                sum += dp[j];
                dp[j] = sum;
            }
        }
        return accumulate(dp, dp + 5, 0);
    }
};